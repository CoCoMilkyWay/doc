#include "stages/tag/tag.hpp"

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <map>

#include "common/util.hpp"
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

// 系列简写 = 券商前 2 字 + "/" + 系列全名 (东方证券/因子选股 -> 东方/因子选股).
// 两级目录由 scan X1 保证; 前 2 字截断实测不引起同名 (国泰君安/国泰海通、华泰证券/华泰期货 的系列名互不相同)
std::string series_abbr(const std::string &folder) {
  size_t p = folder.find('/');
  assert(p != std::string::npos && "标签树目录须为 {券商}/{系列} 两级, 先跑 scan");
  std::vector<char32_t> brok = decode_utf8(folder.substr(0, p));
  std::string out;
  for (size_t i = 0; i < brok.size() && i < 2; ++i)
    append_utf8(out, brok[i]);
  return out + "/" + folder.substr(p + 1);
}

// 显示列宽: 汉字占 2 列, 其余 (ASCII / → 等) 占 1 列. printf 的 %-Ns 按字节算, 带中文的列一律用它补齐
size_t disp_w(const std::string &s) {
  size_t w = 0;
  for (char32_t c : decode_utf8(s))
    w += is_cjk(c) ? 2 : 1;
  return w;
}
void print_pad(const std::string &s, size_t w) {
  size_t cur = disp_w(s);
  printf("%s%*s", s.c_str(), (int)(cur < w ? w - cur : 1), "");
}

// 中文类别名 = 词表 desc 的冒号前一段 (没冒号则整条), 去掉空格: 冒号后是举例, 打印只要类别名
std::string zh_label(const char *desc) {
  std::string s = desc, out;
  s = s.substr(0, s.find(':')); // npos 时取全部
  for (char c : s)
    if (c != ' ')
      out += c;
  return out;
}

// 阶段二: 按流水线阶段 L0..L8 列该阶段每个 approach 的篇数 + 前 3 大系列.
// 分母口径与 X2 一致 (阶段篇数 = 出现该阶段的篇子), 只统计已标注且无违规的篇子 (违规篇的 tag 不可信)
void print_by_stage(const std::vector<TagRec> &recs, const std::vector<size_t> &ok) {
  std::vector<size_t> n_stage((size_t)PipeStage::COUNT, 0), n_appr((size_t)Approach::COUNT, 0);
  std::vector<std::map<std::string, size_t>> by_series((size_t)Approach::COUNT); // approach -> 系列简写 -> 篇数
  for (size_t i : ok)
    for (size_t k = 0; k < (size_t)PipeStage::COUNT; ++k) {
      if (!recs[i].tag.pipe[k])
        continue;
      ++n_stage[k];
      for (Approach a : recs[i].tag.pipe[k]->approach) {
        ++n_appr[(size_t)a];
        ++by_series[(size_t)a][series_abbr(recs[i].folder)];
      }
    }

  printf("\n[按阶段] %zu篇 (已标注且无违规): approach 中文类别 篇数 + 前3大系列(该系列有几篇是这个 approach)\n", ok.size());
  for (size_t k = 0; k < (size_t)PipeStage::COUNT; ++k) {
    printf("%-14s", PipeStage_code[k]);
    print_pad(zh_label(PipeStage_desc[k]), 16);
    printf("(%zu篇)\n", n_stage[k]);
    if (!n_stage[k])
      continue;
    std::vector<size_t> as; // 该阶段的全部 approach, 按篇数降序 (同数保持词表序)
    for (size_t a = 0; a < (size_t)Approach::COUNT; ++a)
      if (Module_stage[(size_t)Approach_module[a]] == (PipeStage)k)
        as.push_back(a);
    std::stable_sort(as.begin(), as.end(), [&](size_t x, size_t y) { return n_appr[x] > n_appr[y]; });
    for (size_t j = 0; j < as.size(); ++j) {
      std::vector<std::pair<std::string, size_t>> top(by_series[as[j]].begin(), by_series[as[j]].end());
      std::stable_sort(top.begin(), top.end(), [](const auto &x, const auto &y) { return x.second > y.second; });
      std::string tail;
      for (size_t t = 0; t < top.size() && t < 3; ++t)
        tail += F(" %s(%zu)", top[t].first.c_str(), top[t].second);
      printf("%s── %-24s", j + 1 == as.size() ? "└" : "├", Approach_code[as[j]]);
      print_pad(zh_label(Approach_desc[as[j]]), 34);
      printf("%5zu%s\n", n_appr[as[j]], tail.c_str());
    }
  }
}

// 阶段三: 全库因子的 data_period (行) × horizon (列) 矩阵, 格子 = 因子数.
// data_period 是列表 => 一个因子有几个原始数据周期就在几行各计一次 (故行合计之和 >= 因子数)
void print_factor_matrix(const std::vector<TagRec> &recs, const std::vector<size_t> &ok) {
  constexpr size_t NP = (size_t)Period::COUNT, LBL = 11, CELL = 10;
  std::vector<size_t> m(NP * NP, 0);
  size_t n_factor = 0;
  for (size_t i : ok) {
    const std::optional<StageTag> &s = recs[i].tag.pipe[(size_t)PipeStage::L1_factor];
    if (!s)
      continue;
    n_factor += s->factors.size();
    for (const FactorTag &f : s->factors)
      for (Period p : f.data_period)
        ++m[(size_t)p * NP + (size_t)f.horizon];
  }

  printf("\n[因子矩阵] %zu个因子: 行 data_period × 列 horizon (多 data_period 的因子每行各计一次)\n", n_factor);
  printf("%-*s", (int)LBL, "period");
  for (size_t c = 0; c < NP; ++c)
    printf("%*s", (int)CELL, Period_code[c]);
  printf("%*s合计\n", (int)CELL - 4, ""); // "合计" 占 4 列宽 (printf 的宽度按字节算, 中文列头手动补齐)
  for (size_t r = 0; r < NP; ++r) {
    printf("%-*s", (int)LBL, Period_code[r]);
    size_t sum = 0;
    for (size_t c = 0; c < NP; ++c) {
      printf("%*zu", (int)CELL, m[r * NP + c]);
      sum += m[r * NP + c];
    }
    printf("%*zu\n", (int)CELL, sum);
  }
  printf("合计%*s", (int)LBL - 4, ""); // "合计" 占 4 列宽
  size_t all = 0;
  for (size_t c = 0; c < NP; ++c) {
    size_t sum = 0;
    for (size_t r = 0; r < NP; ++r)
      sum += m[r * NP + c];
    printf("%*zu", (int)CELL, sum);
    all += sum;
  }
  printf("%*zu\n", (int)CELL, all);
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
  // 库级违规 (X2 分布) 只在表头计数: 十几行 "占237/375" 淹了券商树, 而下面的 [按阶段] 本身就是分布全貌
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

  // 阶段二/三: 分布画像 (与 X2 同口径, 只看已标注且无违规的篇子, 违规篇的 tag 不可信)
  std::vector<size_t> ok;
  for (size_t i = 0; i < recs.size(); ++i)
    if (recs[i].tagged && recs[i].viol.empty())
      ok.push_back(i);
  print_by_stage(recs, ok);
  print_factor_matrix(recs, ok);
  return n_viol + extra.size() + lib_viol.size();
}
