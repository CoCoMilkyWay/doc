#include "stages/scan/scan.hpp"

#include <cstdio>
#include <map>
#include <utility>

size_t print_report(const std::string &root, size_t total,
                    const std::vector<Rec> &records,
                    const std::vector<std::string> &dir_viol) {
  // folder -> [(文件名, 标签串)]; map 保证目录按字节序, 组内保持遍历顺序
  std::map<std::string, std::vector<std::pair<std::string, std::string>>> tree;
  size_t n_viol = 0, n_place = 0, n_scan = 0;
  for (const Rec &r : records) {
    if (r.viol.empty() && r.place.empty() && r.scan.empty())
      continue;
    std::string tags;
    for (const std::vector<std::string> *grp : {&r.viol, &r.place, &r.scan})
      for (const std::string &t : *grp) {
        if (!tags.empty())
          tags += ",";
        tags += t;
      }
    tree[r.folder].emplace_back(r.name, tags);
    n_viol += !r.viol.empty();
    n_place += !r.place.empty();
    n_scan += !r.scan.empty();
  }

  std::string base = root.substr(root.find_last_of('/') + 1);
  printf("%s  (共%zu个PDF: %zu个违规, %zu个含占位, %zu个扫描件, %zu个目录级违规)\n",
         base.c_str(), total, n_viol, n_place, n_scan, dir_viol.size());
  for (const std::string &line : dir_viol)
    printf("├── [%s]\n", line.c_str());
  size_t fi = 0;
  for (const auto &[folder, items] : tree) {
    bool last_folder = ++fi == tree.size();
    printf("%s── %s  (%zu)\n", last_folder ? "└" : "├", folder.c_str(), items.size());
    const char *indent = last_folder ? "    " : "│   ";
    for (size_t i = 0; i < items.size(); ++i)
      printf("%s%s── [%s] %s\n", indent, i + 1 == items.size() ? "└" : "├",
             items[i].second.c_str(), items[i].first.c_str());
  }
  return n_viol;
}
