#include "stages/tag/tag.hpp"

#include <functional>
#include <unordered_map>

#include "common/util.hpp"

void check_cross(std::vector<TagRec> &recs, std::vector<std::string> &lib_viol, std::vector<std::string> &lib_note) {
  std::unordered_map<std::string, size_t> by_stem; // 全部 raw stem (含未标注)
  for (size_t i = 0; i < recs.size(); ++i)
    by_stem[recs[i].stem] = i;

  // 只对已标注且单文件规则全过的参与跨文件规则
  std::vector<size_t> ok;
  for (size_t i = 0; i < recs.size(); ++i)
    if (recs[i].tagged && recs[i].viol.empty())
      ok.push_back(i);

  // X1 无环 (DFS 三色). 不查引用是否存在于 raw, 也不比日期: 库里的 {日期}-{序号} 是为了排序人为规整过的,
  // 与研报正文自称的日期/期号对不上 (很多系列的原始编号本就是乱的), 拿文件名去卡模型从正文里抄来的前作只会误报.
  // 于是 builds_on 里对不上库内 stem 的项一律跳过, 只在能对上的那些之间查环
  {
    std::vector<int> color(recs.size(), 0);
    std::function<bool(size_t)> dfs = [&](size_t u) -> bool {
      color[u] = 1;
      for (const std::string &ref : recs[u].tag.builds_on) {
        auto it = by_stem.find(ref);
        if (it == by_stem.end() || !recs[it->second].tagged)
          continue;
        size_t v = it->second;
        if (color[v] == 1 || (color[v] == 0 && dfs(v))) {
          recs[u].viol.push_back("违规:X1 builds_on 成环 经 " + ref);
          return true;
        }
      }
      color[u] = 2;
      return false;
    };
    for (size_t i : ok)
      if (color[i] == 0)
        dfs(i);
  }

  // X2 分布: 三个层级各自的 "分母 / 分子" —— primary 在全库; module 在有该阶段的文件里; approach 在有该模块的文件里.
  // 只查取值数 >= 3 的分组 (二分组天然偏斜), 分母 >= TAG_DIST_MIN_N 才查
  {
    std::vector<size_t> n_primary((size_t)PipeStage::COUNT, 0), n_stage((size_t)PipeStage::COUNT, 0),
        n_module((size_t)Module::COUNT, 0), n_approach((size_t)Approach::COUNT, 0);
    for (size_t i : ok) {
      const Tag &t = recs[i].tag;
      ++n_primary[(size_t)t.primary];
      for (size_t k = 0; k < (size_t)PipeStage::COUNT; ++k) {
        if (!t.pipe[k])
          continue;
        ++n_stage[k];
        for (Module m : t.pipe[k]->module)
          ++n_module[(size_t)m];
        for (Approach a : t.pipe[k]->approach)
          ++n_approach[(size_t)a];
      }
    }
    auto over = [&](const char *field, const char *code, size_t n, size_t total) {
      if (total >= TAG_DIST_MIN_N && (double)n > TAG_DIST_MAX_SHARE * (double)total)
        lib_viol.push_back(F("库级:X2 %s=%s 占%zu/%zu 超%.0f%%", field, code, n, total, TAG_DIST_MAX_SHARE * 100));
    };
    for (size_t k = 0; k < (size_t)PipeStage::COUNT; ++k)
      over("primary", PipeStage_code[k], n_primary[k], ok.size());
    // 阶段内 module 数 / 模块内 approach 数
    std::vector<size_t> modules_of_stage((size_t)PipeStage::COUNT, 0), approaches_of_module((size_t)Module::COUNT, 0);
    for (size_t m = 0; m < (size_t)Module::COUNT; ++m)
      ++modules_of_stage[(size_t)Module_stage[m]];
    for (size_t a = 0; a < (size_t)Approach::COUNT; ++a)
      ++approaches_of_module[(size_t)Approach_module[a]];
    for (size_t m = 0; m < (size_t)Module::COUNT; ++m)
      if (modules_of_stage[(size_t)Module_stage[m]] >= 3)
        over("module", Module_code[m], n_module[m], n_stage[(size_t)Module_stage[m]]);
    for (size_t a = 0; a < (size_t)Approach::COUNT; ++a)
      if (approaches_of_module[(size_t)Approach_module[a]] >= 3)
        over("approach", Approach_code[a], n_approach[a], n_module[(size_t)Approach_module[a]]);
  }

  // X3 死词表 (仅全部标注完成时)
  bool complete = true;
  for (const TagRec &r : recs)
    complete &= r.tagged;
  if (complete && !recs.empty()) {
    std::vector<char> used_m((size_t)Module::COUNT, 0), used_a((size_t)Approach::COUNT, 0);
    for (size_t i : ok)
      for (const std::optional<StageTag> &s : recs[i].tag.pipe) {
        if (!s)
          continue;
        for (Module m : s->module)
          used_m[(size_t)m] = 1;
        for (Approach a : s->approach)
          used_a[(size_t)a] = 1;
      }
    for (size_t k = 0; k < used_m.size(); ++k)
      if (!used_m[k])
        lib_note.push_back(F("提示:X3 module %s 从未使用", Module_code[k]));
    for (size_t k = 0; k < used_a.size(); ++k)
      if (!used_a[k])
        lib_note.push_back(F("提示:X3 approach %s 从未使用", Approach_code[k]));
  }

  // X4 findings 串写
  std::unordered_map<std::string, std::vector<size_t>> by_findings;
  for (size_t i : ok)
    by_findings[recs[i].findings_key].push_back(i);
  for (const auto &[key, idxs] : by_findings) {
    if (idxs.size() <= 1)
      continue;
    for (size_t i : idxs) {
      std::string peers;
      for (size_t j : idxs)
        if (j != i)
          peers += (peers.empty() ? "" : " / ") + recs[j].stem;
      recs[i].viol.push_back("违规:X4 findings 与他篇完全相同 (" + peers + ")");
    }
  }
}
