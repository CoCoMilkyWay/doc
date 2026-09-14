#include "stages/convert/convert.hpp"

#include <atomic>
#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <thread>

#include "common/fs.hpp"
#include "common/util.hpp"
#include "config.hpp"

namespace {

struct Issue {
  std::string folder; // 相对 PROC_REPORT_DIR 的所在目录, 用于树状分组
  std::string label, name, path;
};

std::string stem_of(const std::string &name) { return name.substr(0, name.size() - 4); }

// 遍历 proc 的 raw 目录层级 (不进入 {stem}/ 内部): 收集多余文件/多余目录, 以及需校验的 {stem}/
void walk_proc(const std::string &proc, const std::string &rel, const std::set<std::string> &raw_dirs,
               const std::map<std::string, size_t> &expected, std::vector<Issue> &issues,
               std::vector<std::pair<std::string, size_t>> &to_verify) {
  std::string abs = rel == "." ? proc : proc + "/" + rel;
  std::vector<std::string> dirs, files;
  list_dir(abs, dirs, files);
  for (const std::string &f : files)
    issues.push_back({rel, "多余文件", f, abs + "/" + f});
  for (const std::string &d : dirs) {
    if (rel == "." && d == PROC_STAGING_DIR)
      continue; // 暂存区由调用方无条件清空
    std::string sub = rel == "." ? d : rel + "/" + d;
    auto it = expected.find(sub);
    if (it != expected.end())
      to_verify.push_back({sub, it->second});
    else if (raw_dirs.count(sub))
      walk_proc(proc, sub, raw_dirs, expected, issues, to_verify);
    else
      issues.push_back({rel, "多余目录:raw无对应PDF", d, abs + "/" + d});
  }
}

} // namespace

bool check_proc(const std::string &proc, const std::vector<Pdf> &pdfs, unsigned workers,
                std::vector<size_t> &pending) {
  double t0 = now_ms();
  std::string staging = proc + "/" + PROC_STAGING_DIR;
  if (path_exists(staging)) {
    fprintf(stderr, "[check] 清空上次残留的暂存区 %s/%s\n", PROC_REPORT_DIR, PROC_STAGING_DIR);
    remove_all(staging);
  }

  // raw 侧: 合法目录 (PDF 所在目录及其全部祖先) 与期望的 {folder}/{stem} -> pdf 下标
  std::set<std::string> raw_dirs = {"."};
  std::map<std::string, size_t> expected;
  for (size_t i = 0; i < pdfs.size(); ++i) {
    const std::string &f = pdfs[i].folder;
    for (size_t p = f.find('/'); p != std::string::npos; p = f.find('/', p + 1))
      raw_dirs.insert(f.substr(0, p));
    raw_dirs.insert(f);
    std::string key = (f == "." ? "" : f + "/") + stem_of(pdfs[i].name);
    assert(!expected.count(key) && "同目录下 stem 重复");
    expected[key] = i;
  }

  std::vector<Issue> issues;
  std::vector<std::pair<std::string, size_t>> to_verify;
  if (is_dir(proc))
    walk_proc(proc, ".", raw_dirs, expected, issues, to_verify);

  // 并行校验每个已存在的 {stem}/: 读 .stat + readdir/stat, 不读内容
  std::vector<std::string> verdict(to_verify.size());
  std::atomic<size_t> cursor{0};
  {
    std::vector<std::jthread> pool;
    for (unsigned w = 0; w < workers; ++w)
      pool.emplace_back([&] {
        for (;;) {
          size_t k = cursor.fetch_add(1);
          if (k >= to_verify.size())
            return;
          verdict[k] = verify_stat(proc + "/" + to_verify[k].first, pdfs[to_verify[k].second].size);
        }
      });
  }
  std::vector<char> complete(pdfs.size(), 0);
  for (size_t k = 0; k < to_verify.size(); ++k) {
    size_t i = to_verify[k].second;
    if (verdict[k].empty())
      complete[i] = 1;
    else
      issues.push_back({pdfs[i].folder, verdict[k], stem_of(pdfs[i].name) + "/",
                        proc + "/" + to_verify[k].first});
  }
  size_t n_complete = 0;
  for (char c : complete)
    n_complete += c;
  fprintf(stderr, "[check] raw %zu个PDF, proc 完整%zu, 问题项%zu, %.0fms\n", pdfs.size(), n_complete,
          issues.size(), now_ms() - t0);

  if (!issues.empty()) {
    std::map<std::string, std::vector<const Issue *>> tree;
    for (const Issue &is : issues)
      tree[is.folder].push_back(&is);
    size_t fi = 0;
    for (const auto &[folder, list] : tree) {
      bool last_folder = ++fi == tree.size();
      printf("%s── %s  (%zu)\n", last_folder ? "└" : "├", folder.c_str(), list.size());
      const char *indent = last_folder ? "    " : "│   ";
      for (size_t i = 0; i < list.size(); ++i)
        printf("%s%s── [%s] %s\n", indent, i + 1 == list.size() ? "└" : "├", list[i]->label.c_str(),
               list[i]->name.c_str());
    }
    fflush(stdout);
    fprintf(stderr, "[check] 以上 %zu 项与 raw 不对应或不完整, 必须删除后才能继续. 删除? [y/N] ",
            issues.size());
    char buf[16] = {};
    bool yes = fgets(buf, sizeof buf, stdin) && (buf[0] == 'y' || buf[0] == 'Y') &&
               (buf[1] == '\n' || buf[1] == '\0');
    if (!yes) {
      fprintf(stderr, "[check] 未删除, 退出\n");
      return false;
    }
    for (const Issue &is : issues)
      remove_all(is.path);
    fprintf(stderr, "[check] 已删除 %zu 项\n", issues.size());
  }

  pending.clear();
  for (size_t i = 0; i < pdfs.size(); ++i)
    if (!complete[i])
      pending.push_back(i);
  return true;
}
