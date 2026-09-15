#include "stages/tag/tag.hpp"

#include <atomic>
#include <cassert>
#include <cstdio>
#include <map>
#include <thread>

#include "common/fs.hpp"
#include "common/proc.hpp"
#include "common/util.hpp"
#include "stages/scan/scan.hpp"

namespace {

// 收集 raw 全部 PDF (与 convert 同口径), 文件名五段结构由 scan 保证, 这里直接断言
void walk_raw(const std::string &raw, const std::string &rel, std::vector<TagRec> &recs) {
  std::string dirpath = rel == "." ? raw : raw + "/" + rel;
  std::vector<std::string> dirs, files;
  list_dir(dirpath, dirs, files);
  for (const std::string &f : files) {
    if (!lower_ascii(f).ends_with(".pdf"))
      continue;
    Seg g;
    assert(parse_name(f, g) && "raw 文件名不合规, 先跑 scan");
    TagRec r;
    r.folder = rel;
    r.stem = f.substr(0, f.size() - 4);
    r.date = g.date;
    recs.push_back(std::move(r));
  }
  for (const std::string &d : dirs)
    walk_raw(raw, rel == "." ? d : rel + "/" + d, recs);
}

// 遍历标签树: 对得上 raw 的 .json 记 tagged, 其余一律 [多余]
void walk_tag(const std::string &tagdir, const std::string &rel, const std::map<std::string, size_t> &expected,
              std::vector<TagRec> &recs, std::vector<std::pair<std::string, std::string>> &extra) {
  std::string dirpath = rel == "." ? tagdir : tagdir + "/" + rel;
  std::vector<std::string> dirs, files;
  list_dir(dirpath, dirs, files);
  for (const std::string &f : files) {
    auto it = f.ends_with(".json") ? expected.find((rel == "." ? "" : rel + "/") + f.substr(0, f.size() - 5))
                                   : expected.end();
    if (it == expected.end()) {
      extra.emplace_back(rel, f);
      continue;
    }
    recs[it->second].tagged = true;
    recs[it->second].path = dirpath + "/" + f;
  }
  for (const std::string &d : dirs)
    walk_tag(tagdir, rel == "." ? d : rel + "/" + d, expected, recs, extra);
}

// raw 全集 + 标签树对账. 每次调用重新走一遍目录 (补全之后要刷新 tagged)
void collect(const Ctx &ctx, std::vector<TagRec> &recs, std::vector<std::pair<std::string, std::string>> &extra) {
  std::string raw = ctx.root + "/" + RAW_REPORT_DIR;
  std::string tagdir = ctx.root + "/" + TAG_REPORT_DIR;
  assert(is_dir(raw) && "缺少研报输入目录 RAW_REPORT_DIR");
  recs.clear();
  extra.clear();
  walk_raw(raw, ".", recs);
  std::map<std::string, size_t> expected; // "{folder}/{stem}" -> 下标
  for (size_t i = 0; i < recs.size(); ++i) {
    std::string key = (recs[i].folder == "." ? "" : recs[i].folder + "/") + recs[i].stem;
    assert(!expected.count(key) && "同目录下 stem 重复");
    expected[key] = i;
  }
  if (is_dir(tagdir))
    walk_tag(tagdir, ".", expected, recs, extra);
}

std::string md_path_of(const Ctx &ctx, const TagRec &r) {
  return ctx.root + "/" + PROC_REPORT_DIR + "/" + (r.folder == "." ? "" : r.folder + "/") + r.stem + "/" + PROC_MD_NAME;
}

// 单文件规则: F2-F4 S V K G (r.tagged 且 r.path 有效). F3 不规范则覆盖写回
void check_rec(const Ctx &ctx, TagRec &r) {
  std::string text = read_file(r.path), canon;
  bool ok = parse_tag(text, r.stem, r.tag, r.findings_key, canon, r.viol);
  if (!canon.empty() && canon != text) {
    write_file(r.path, canon);
    r.formatted = true;
  }
  if (!ok)
    return;
  check_consistency(r.tag, r.viol);
  std::string md = md_path_of(ctx, r);
  if (!path_exists(md))
    r.viol.push_back(F("违规:F4 无 %s, 无法接地", PROC_MD_NAME));
  else
    check_grounding(r.tag, read_file(md), r.viol);
}

// --one <json>: 只校验这一个文件 (给 agent loop 回喂用). 文件须在 TAG_REPORT_DIR 或 TAG_STAGING_DIR 下,
// 相对其的路径 = {folder}/{stem}.json. 违规一行一条到 stdout, 退出码 = 有无违规. 不跑 X 规则
int run_one(const Ctx &ctx, const std::string &path) {
  std::string rel;
  for (const char *base : {TAG_REPORT_DIR, TAG_STAGING_DIR}) {
    std::string prefix = ctx.root + "/" + base + "/";
    if (path.starts_with(prefix))
      rel = path.substr(prefix.size());
  }
  assert(!rel.empty() && "--one 路径须在 TAG_REPORT_DIR 或 TAG_STAGING_DIR 下");
  assert(rel.ends_with(".json") && "--one 须为 .json");
  size_t slash = rel.rfind('/');
  std::string file = slash == std::string::npos ? rel : rel.substr(slash + 1);
  TagRec r;
  r.folder = slash == std::string::npos ? "." : rel.substr(0, slash);
  r.stem = file.substr(0, file.size() - 5);
  Seg g;
  assert(parse_name(r.stem + ".pdf", g) && "--one stem 不合规");
  r.date = g.date;
  assert(path_exists(ctx.root + "/" + RAW_REPORT_DIR + "/" + (r.folder == "." ? "" : r.folder + "/") + r.stem + ".pdf") &&
         "--one 对应的 raw PDF 不存在");
  r.tagged = true;
  r.path = path;
  check_rec(ctx, r);
  for (const std::string &v : r.viol)
    printf("%s\n", v.c_str());
  return r.viol.empty() ? 0 : 1;
}

// 阶段一: 缺失的标签交给 agent loop 补全 (cpp/agent/tag_loop.py). 缺失清单写进 staging, 参数全部由 config.hpp 传下去,
// python 侧不另存配置. 无 TAG_AGENT_KEY_FILE 则跳过 (纯校验用法)
void fill_missing(const Ctx &ctx, const std::vector<TagRec> &recs) {
  std::vector<const TagRec *> missing;
  for (const TagRec &r : recs)
    if (!r.tagged)
      missing.push_back(&r);
  if (missing.empty())
    return;
  std::string key_file = ctx.root + "/" + TAG_AGENT_KEY_FILE;
  if (!path_exists(key_file)) {
    fprintf(stderr, "[tag] 缺失 %zu 篇, 无 %s, 跳过补全\n", missing.size(), TAG_AGENT_KEY_FILE);
    return;
  }
  check_tag_env(ctx.root); // T1/T2, 并设好子进程要用的 PYTHONNOUSERSITE/PYTHONPATH
  std::string staging = ctx.root + "/" + TAG_STAGING_DIR;
  remove_all(staging);
  mkdirs(staging);
  std::string list;
  for (const TagRec *r : missing)
    list += r->folder + "\t" + r->stem + "\t" + r->date + "\n";
  std::string list_path = staging + "/missing.tsv";
  write_file(list_path, list);
  fprintf(stderr, "[tag] 缺失 %zu 篇, 交给 agent loop (model=%s, reasoning_effort=%s, workers=%d, max_round=%d)\n",
          missing.size(), TAG_AGENT_MODEL, TAG_AGENT_REASONING_EFFORT, TAG_AGENT_WORKERS, TAG_AGENT_MAX_ROUND);
  std::string py = ctx.root + "/" + PYTHON_BIN;
  int rc = run_cmd({py, ctx.root + "/" + TAG_AGENT_SCRIPT, "--root", ctx.root, "--docpipe", ctx.self, "--key-file", key_file, "--missing", list_path,
                    "--staging", staging, "--out", ctx.root + "/" + TAG_REPORT_DIR, "--proc", ctx.root + "/" + PROC_REPORT_DIR,
                    "--md-name", PROC_MD_NAME, "--quarantine", ctx.root + "/" + TAG_QUARANTINE_DIR, "--log-dir",
                    ctx.root + "/" + TAG_AGENT_LOG_DIR, "--spec", ctx.root + "/cpp/include/stages/tag/tag.md", "--model",
                    TAG_AGENT_MODEL, "--reasoning-effort", TAG_AGENT_REASONING_EFFORT, "--price-in", std::to_string(TAG_AGENT_PRICE.in),
                    "--price-out", std::to_string(TAG_AGENT_PRICE.out), "--price-hit", std::to_string(TAG_AGENT_PRICE.hit), "--workers",
                    std::to_string(TAG_AGENT_WORKERS), "--max-round",
                    std::to_string(TAG_AGENT_MAX_ROUND), "--md-max", std::to_string(TAG_AGENT_MD_MAX_BYTES),
                    "--schema-version", std::to_string(TAG_SCHEMA_VERSION)});
  assert(rc == 0 && "agent loop 异常退出");
}

} // namespace

int TagStage::run(const Ctx &ctx) {
  if (!ctx.args.empty()) {
    assert(ctx.args.size() == 2 && ctx.args[0] == "--one" && "tag 只认 --one <json>");
    return run_one(ctx, ctx.args[1]);
  }
  double t0 = now_ms();
  std::vector<TagRec> recs;
  std::vector<std::pair<std::string, std::string>> extra;
  collect(ctx, recs, extra);
  fill_missing(ctx, recs);
  collect(ctx, recs, extra); // 补全后刷新 tagged

  // 阶段二: 单文件规则并行
  std::atomic<size_t> cursor{0};
  {
    std::vector<std::jthread> pool;
    for (unsigned w = 0; w < ctx.workers; ++w)
      pool.emplace_back([&] {
        for (;;) {
          size_t i = cursor.fetch_add(1);
          if (i >= recs.size())
            return;
          if (recs[i].tagged)
            check_rec(ctx, recs[i]);
        }
      });
  }

  std::vector<std::string> lib_viol, lib_note;
  check_cross(recs, lib_viol, lib_note);

  size_t n_bad = print_tag_report(recs, extra, lib_viol, lib_note);
  fprintf(stderr, "[tag] %zu篇, 校验 %.0fms\n", recs.size(), now_ms() - t0);
  return n_bad ? 1 : 0;
}
