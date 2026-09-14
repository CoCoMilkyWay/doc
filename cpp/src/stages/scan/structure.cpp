#include "stages/scan/scan.hpp"

#include <array>
#include <map>
#include <set>

#include "common/util.hpp"

static bool is_topic(const std::string &folder) {
  return folder == TOPIC_DIR || folder.starts_with(std::string(TOPIC_DIR) + "/");
}

void check_structure(std::vector<Rec> &records, std::vector<std::string> &dir_viol) {
  // X1 路径两级且与文件名段一致
  for (Rec &r : records) {
    if (!r.parsed)
      continue;
    std::vector<std::string> comps = split(r.folder, '/');
    if (comps.size() != 2) {
      r.viol.push_back(F("违规:路径应为两级(%s)", r.folder.c_str()));
      continue;
    }
    if (is_topic(r.folder))
      continue; // 主题研报: 目录是主题, 豁免与券商/系列段的比较
    if (comps[0] != r.g.broker)
      r.viol.push_back(F("违规:券商目录不符(%s)", comps[0].c_str()));
    if (comps[1] != r.g.series)
      r.viol.push_back(F("违规:系列目录不符(%s)", comps[1].c_str()));
  }

  // X2 同一券商+系列(按文件名段)内序号重复
  std::map<std::array<std::string, 3>, std::vector<size_t>> by_num;
  for (size_t i = 0; i < records.size(); ++i) {
    const Rec &r = records[i];
    if (r.parsed && r.g.series != WU)
      by_num[{r.g.broker, r.g.series, r.g.num}].push_back(i);
  }
  for (const auto &[key, idxs] : by_num) {
    if (idxs.size() <= 1)
      continue;
    for (size_t i : idxs)
      records[i].viol.push_back(
          F("违规:序号%s重复(%s-%s)", key[2].c_str(), key[0].c_str(), key[1].c_str()));
  }

  // X3 券商目录下系列子目录名互为子串
  std::map<std::string, std::set<std::string>> by_broker;
  for (const Rec &r : records) {
    std::vector<std::string> comps = split(r.folder, '/');
    if (comps.size() == 2)
      by_broker[comps[0]].insert(comps[1]);
  }
  for (const auto &[broker, series_set] : by_broker) {
    std::vector<std::string> ns;
    for (const std::string &s : series_set)
      if (s != WU)
        ns.push_back(s);
    for (size_t i = 0; i < ns.size(); ++i)
      for (size_t j = i + 1; j < ns.size(); ++j)
        if (ns[i].contains(ns[j]) || ns[j].contains(ns[i]))
          dir_viol.push_back(F("违规:券商%s下系列目录相近: %s / %s", broker.c_str(),
                               ns[i].c_str(), ns[j].c_str()));
  }

  // X4 顶层券商目录名互为子串
  std::vector<std::string> bs;
  for (const auto &[broker, _] : by_broker)
    if (broker != WU)
      bs.push_back(broker);
  for (size_t i = 0; i < bs.size(); ++i)
    for (size_t j = i + 1; j < bs.size(); ++j)
      if (bs[i].contains(bs[j]) || bs[j].contains(bs[i]))
        dir_viol.push_back(F("违规:券商目录相近: %s / %s", bs[i].c_str(), bs[j].c_str()));
}
