#include "stages/tag/tag.hpp"

#include <cstdio>
#include <map>

#include "config.hpp"

namespace {

struct Broker {
  size_t total = 0, tagged = 0, viol = 0, extra = 0, formatted = 0;
  std::vector<std::pair<std::string, std::string>> items; // (标签串, 相对券商目录的路径)
};

// "{券商}/{系列}" -> 券商 (TOPIC_DIR 整体视为一个券商)
std::string broker_of(const std::string &folder) {
  size_t p = folder.find('/');
  return p == std::string::npos ? folder : folder.substr(0, p);
}
std::string rest_of(const std::string &folder) {
  size_t p = folder.find('/');
  return p == std::string::npos ? "" : folder.substr(p + 1) + "/";
}

} // namespace

size_t print_tag_report(const std::vector<TagRec> &recs, const std::vector<std::pair<std::string, std::string>> &extra,
                        const std::vector<std::string> &lib_viol, const std::vector<std::string> &lib_note) {
  std::map<std::string, Broker> tree; // map 保证券商按字节序
  size_t n_tagged = 0, n_viol = 0, n_fmt = 0;
  for (const TagRec &r : recs) {
    Broker &b = tree[broker_of(r.folder)];
    ++b.total;
    b.tagged += r.tagged;
    n_tagged += r.tagged;
    b.formatted += r.formatted;
    n_fmt += r.formatted;
    if (r.viol.empty())
      continue;
    ++b.viol;
    ++n_viol;
    std::string tags;
    for (const std::string &t : r.viol)
      tags += (tags.empty() ? "" : ",") + t;
    b.items.emplace_back(tags, rest_of(r.folder) + r.stem);
  }
  for (const auto &[folder, name] : extra) {
    Broker &b = tree[broker_of(folder)];
    ++b.extra;
    b.items.emplace_back("多余:raw无对应PDF", rest_of(folder) + name);
  }

  printf("%s  (共%zu篇: 已标注%zu, 缺失%zu, 违规%zu, 多余%zu, 格式化%zu; 库级问题%zu)\n", TAG_REPORT_DIR, recs.size(),
         n_tagged, recs.size() - n_tagged, n_viol, extra.size(), n_fmt, lib_viol.size());
  for (const std::string &l : lib_viol)
    printf("├── [%s]\n", l.c_str());
  for (const std::string &l : lib_note)
    printf("├── [%s]\n", l.c_str());
  size_t bi = 0;
  for (const auto &[broker, b] : tree) {
    bool last_broker = ++bi == tree.size();
    printf("%s── %s  (%zu篇: 标注%zu 缺失%zu 违规%zu 多余%zu 格式化%zu)\n", last_broker ? "└" : "├", broker.c_str(),
           b.total, b.tagged, b.total - b.tagged, b.viol, b.extra, b.formatted);
    const char *indent = last_broker ? "    " : "│   ";
    for (size_t i = 0; i < b.items.size(); ++i)
      printf("%s%s── [%s] %s\n", indent, i + 1 == b.items.size() ? "└" : "├", b.items[i].first.c_str(),
             b.items[i].second.c_str());
  }
  return n_viol + extra.size() + lib_viol.size();
}
