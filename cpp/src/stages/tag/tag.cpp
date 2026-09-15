#include "stages/tag/tag.hpp"

#include <atomic>
#include <cassert>
#include <cstdio>
#include <map>
#include <thread>

#include "common/fs.hpp"
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

} // namespace

int TagStage::run(const Ctx &ctx) {
  double t0 = now_ms();
  std::string raw = ctx.root + "/" + RAW_REPORT_DIR;
  std::string proc = ctx.root + "/" + PROC_REPORT_DIR;
  std::string tagdir = ctx.root + "/" + TAG_REPORT_DIR;
  assert(is_dir(raw) && "缺少研报输入目录 RAW_REPORT_DIR");

  std::vector<TagRec> recs;
  walk_raw(raw, ".", recs);
  std::map<std::string, size_t> expected; // "{folder}/{stem}" -> 下标
  for (size_t i = 0; i < recs.size(); ++i) {
    std::string key = (recs[i].folder == "." ? "" : recs[i].folder + "/") + recs[i].stem;
    assert(!expected.count(key) && "同目录下 stem 重复");
    expected[key] = i;
  }

  std::vector<std::pair<std::string, std::string>> extra;
  if (is_dir(tagdir))
    walk_tag(tagdir, ".", expected, recs, extra);

  // 单文件规则并行: F2-F4 S V K G
  std::atomic<size_t> cursor{0};
  {
    std::vector<std::jthread> pool;
    for (unsigned w = 0; w < ctx.workers; ++w)
      pool.emplace_back([&] {
        for (;;) {
          size_t i = cursor.fetch_add(1);
          if (i >= recs.size())
            return;
          TagRec &r = recs[i];
          if (!r.tagged)
            continue;
          std::string text = read_file(r.path), canon;
          bool ok = parse_tag(text, r.stem, r.tag, r.findings_key, canon, r.viol);
          if (!canon.empty() && canon != text) { // F3: 覆盖为规范格式
            write_file(r.path, canon);
            r.formatted = true;
          }
          if (!ok)
            continue;
          check_consistency(r.tag, r.date, r.viol);
          std::string md = proc + "/" + (r.folder == "." ? "" : r.folder + "/") + r.stem + "/" + PROC_MD_NAME;
          if (!path_exists(md))
            r.viol.push_back(F("违规:F4 无 %s, 无法接地", PROC_MD_NAME));
          else
            check_grounding(r.tag, read_file(md), r.viol);
        }
      });
  }

  std::vector<std::string> lib_viol, lib_note;
  check_cross(recs, lib_viol, lib_note);

  size_t n_bad = print_tag_report(recs, extra, lib_viol, lib_note);
  fprintf(stderr, "[tag] %zu篇, 校验 %.0fms\n", recs.size(), now_ms() - t0);
  return n_bad ? 1 : 0;
}
