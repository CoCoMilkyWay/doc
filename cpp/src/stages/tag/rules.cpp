#include "stages/tag/tag.hpp"

#include <algorithm>
#include <cstdlib>
#include <unordered_set>

#include "common/util.hpp"

namespace {

template <class T, size_t N>
bool in(const T (&arr)[N], T v) {
  return std::find(arr, arr + N, v) != arr + N;
}

// 去符号的 lexeme 乘 100 (十进制移位, 不经浮点): "0.045" -> "4.5", "0.5" -> "50", "12" -> "1200"
std::string times100(std::string s) {
  if (s.front() == '-')
    s.erase(0, 1);
  size_t dot = s.find('.');
  std::string ip = dot == std::string::npos ? s : s.substr(0, dot);
  std::string fp = dot == std::string::npos ? "" : s.substr(dot + 1);
  while (fp.size() < 2)
    fp += '0';
  ip += fp.substr(0, 2);
  fp = fp.substr(2);
  while (ip.size() > 1 && ip[0] == '0')
    ip.erase(0, 1);
  while (!fp.empty() && fp.back() == '0')
    fp.pop_back();
  return fp.empty() ? ip : ip + "." + fp;
}

std::vector<char32_t> cps(const std::string &s) { return decode_utf8(s); }

} // namespace

std::string norm_text(const std::string &s) {
  std::string out;
  out.reserve(s.size());
  for (char32_t c : decode_utf8(s)) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == 0x3000 || c == 0xA0)
      continue;
    if (c == '*' || c == '|' || c == '#')
      continue;
    if (c >= 0xFF01 && c <= 0xFF5E)
      c -= 0xFEE0;
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';
    append_utf8(out, c);
  }
  return out;
}

namespace {
// 遍历出现的阶段
template <class Fn>
void each_stage(const Tag &t, Fn fn) {
  for (size_t k = 0; k < (size_t)PipeStage::COUNT; ++k)
    if (t.pipe[k])
      fn((PipeStage)k, *t.pipe[k]);
}
} // namespace

void check_consistency(const Tag &t, std::vector<std::string> &viol) {
  auto bad = [&](std::string s) { viol.push_back("违规:" + std::move(s)); };

  // V2 主阶段出现
  if (!t.pipe[(size_t)t.primary])
    bad(F("V2 primary %s 未出现在 pipe", code_of(t.primary)));

  // V3 归属链
  each_stage(t, [&](PipeStage st, const StageTag &s) {
    const char *sc = code_of(st);
    for (Module m : s.module)
      if (Module_stage[(size_t)m] != st)
        bad(F("V3 %s.module %s 不属于该阶段", sc, code_of(m)));
    auto in_module = [&](Approach a) {
      return std::find(s.module.begin(), s.module.end(), Approach_module[(size_t)a]) != s.module.end();
    };
    for (Approach a : s.approach)
      if (!in_module(a))
        bad(F("V3 %s.approach %s 所属模块 %s 不在 module 中", sc, code_of(a), code_of(Approach_module[(size_t)a])));
    for (Approach a : s.baseline) {
      if (Module_stage[(size_t)Approach_module[(size_t)a]] != st)
        bad(F("V3 %s.baseline %s 不属于该阶段", sc, code_of(a)));
      if (std::find(s.approach.begin(), s.approach.end(), a) != s.approach.end())
        bad(F("V3 %s.baseline %s 与 approach 重合", sc, code_of(a)));
    }
  });

  // K1 体裁
  size_t n_stage = 0;
  each_stage(t, [&](PipeStage, const StageTag &) { ++n_stage; });
  if (t.genre == Genre::framework && n_stage < 3)
    bad(F("K1 genre=framework 但只有 %zu 个阶段", n_stage));
  const std::optional<StageTag> &l1 = t.pipe[(size_t)PipeStage::L1_factor];
  if (t.genre == Genre::review && l1 && !l1->factors.empty())
    bad("K1 genre=review 但 L1_factor.factors 非空");
  if (t.genre == Genre::handbook &&
      ((t.primary != PipeStage::L1_factor && t.primary != PipeStage::L2_process) || !l1))
    bad("K1 genre=handbook 须 primary ∈ {L1,L2} 且 L1 出现");
  if (t.genre == Genre::research && t.primary == PipeStage::L1_factor && l1 &&
      !(l1->module.size() == 1 && l1->module[0] == Module::L1_mining) && l1->factors.empty())
    bad("K1 research 且 primary=L1_factor 但 L1_factor.factors 为空");

  // K2 数值域 (stats 非 null 项)
  each_stage(t, [&](PipeStage st, const StageTag &s) {
    for (size_t k = 0; k < s.factors.size(); ++k)
      for (size_t i = 0; i < N_STAT; ++i) {
        const std::string &lex = s.factors[k].stats[i];
        if (lex.empty())
          continue;
        double v = atof(lex.c_str());
        if (v < Stat_lo[i] || v > Stat_hi[i])
          bad(F("K2 %s.factors[%zu].stats[%zu] %s=%s 越界", code_of(st), k, i, code_of((Stat)i), lex.c_str()));
      }
  });

  // K4 高频
  auto hf_source = [](const Data &d) {
    for (DataSource x : d.source)
      if (in(HF_SOURCES, x))
        return true;
    return false;
  };
  each_stage(t, [&](PipeStage st, const StageTag &s) {
    if (STAGE_SPEC[(size_t)st].data && in(HF_FREQS_STRICT, s.data.freq) && !hf_source(s.data))
      bad(F("K4 %s.setup.data freq=%s 但无高频源", code_of(st), code_of(s.data.freq)));
  });
  if (const std::optional<StageTag> &l7 = t.pipe[(size_t)PipeStage::L7_execution];
      l7 && !(in(HF_FREQS, l7->data.freq) && hf_source(l7->data)))
    bad("K4 L7_execution 出现但 setup.data 非高频");

  // K5 资产↔股票池
  bool stock = false;
  for (Asset a : t.asset)
    stock |= in(STOCK_ASSETS, a);
  each_stage(t, [&](PipeStage st, const StageTag &s) {
    if (!STAGE_SPEC[(size_t)st].universe)
      return;
    bool uni_na = s.universe.size() == 1 && s.universe[0] == Universe::na;
    if (stock == uni_na)
      bad(F("K5 %s.setup.universe %s", code_of(st), stock ? "股票资产但为 [na]" : "非股票资产但不是 [na]"));
  });

  // K7 自引
  if (std::find(t.builds_on.begin(), t.builds_on.end(), t.id) != t.builds_on.end())
    bad("K7 builds_on 含自身");
}

void check_grounding(const Tag &t, const std::string &md, std::vector<std::string> &viol) {
  auto bad = [&](std::string s) { viol.push_back("违规:" + std::move(s)); };
  std::string nmd = norm_text(md);

  // G1: 统一收集全部 evidence
  auto g1 = [&](const std::string &ev, const std::string &where) -> std::string {
    std::string ne = norm_text(ev);
    if (cps(ne).size() < TAG_EVIDENCE_MIN_CP)
      bad(F("G1 %s.evidence 归一化后不足%zu字", where.c_str(), TAG_EVIDENCE_MIN_CP));
    else if (nmd.find(ne) == std::string::npos)
      bad(F("G1 %s.evidence 不是 report.md 逐字子串", where.c_str()));
    return ne;
  };

  each_stage(t, [&](PipeStage st, const StageTag &s) {
    for (size_t k = 0; k < s.factors.size(); ++k) {
      const FactorTag &f = s.factors[k];
      std::string where = F("%s.factors[%zu]", code_of(st), k);
      g1(f.evidence, where);
      // G3
      if (nmd.find(norm_text(f.name)) == std::string::npos)
        bad(F("G3 %s.name \"%s\" 未在 report.md 出现", where.c_str(), f.name.c_str()));
      // G2: stats 没有自己的 evidence, 对整篇 report.md 查; 原文 lexeme / 去符号 / ×100 百分数 三选一出现即可
      for (size_t i = 0; i < N_STAT; ++i) {
        const std::string &lex = f.stats[i];
        if (lex.empty())
          continue;
        std::string abs = lex.front() == '-' ? lex.substr(1) : lex;
        if (nmd.find(lex) == std::string::npos && nmd.find(abs) == std::string::npos &&
            nmd.find(times100(lex)) == std::string::npos)
          bad(F("G2 %s.stats[%zu] %s=%s 未在 report.md 出现", where.c_str(), i, code_of((Stat)i), lex.c_str()));
      }
    }
  });
  for (size_t k = 0; k < t.findings.size(); ++k) {
    const Finding &f = t.findings[k];
    std::string ne = g1(f.evidence, F("findings[%zu]", k));
    // G4 字符 bigram 重合率
    std::vector<char32_t> a = cps(norm_text(f.text)), b = cps(ne);
    if (a.size() < 2)
      continue;
    std::unordered_set<uint64_t> bg;
    for (size_t i = 1; i < b.size(); ++i)
      bg.insert(((uint64_t)b[i - 1] << 32) | b[i]);
    size_t hit = 0;
    for (size_t i = 1; i < a.size(); ++i)
      hit += bg.count(((uint64_t)a[i - 1] << 32) | a[i]);
    double ratio = (double)hit / (double)(a.size() - 1);
    if (ratio < TAG_FINDING_OVERLAP_MIN)
      bad(F("G4 findings[%zu].text 与 evidence 重合率 %.2f < %.2f", k, ratio, TAG_FINDING_OVERLAP_MIN));
  }
}
