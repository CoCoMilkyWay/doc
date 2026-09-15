#include "stages/tag/tag.hpp"

#include <algorithm>
#include <cstdlib>
#include <initializer_list>
#include <span>

#include "common/json.hpp"
#include "common/util.hpp"

namespace {

// 数字 lexeme 规范形: -?(0|[1-9]\d*)(\.\d*[1-9])?  (无指数, 无尾零, 无 -0); integer 时不允许小数部分
bool canon_number(const std::string &s, bool integer) {
  size_t i = 0;
  if (i < s.size() && s[i] == '-')
    ++i;
  size_t int_beg = i;
  while (i < s.size() && is_digit(s[i]))
    ++i;
  if (i == int_beg || (s[int_beg] == '0' && i - int_beg > 1))
    return false;
  if (i == s.size())
    return !(s == "-0");
  if (integer || s[i] != '.')
    return false;
  ++i;
  size_t frac_beg = i;
  while (i < s.size() && is_digit(s[i]))
    ++i;
  return i == s.size() && i != frac_beg && s[i - 1] != '0'; // 无尾零 => -0.0… 也被排除
}

bool trimmed_nonempty(const std::string &s) {
  if (s.empty())
    return false;
  auto ws = [](unsigned char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; };
  if (ws(s.front()) || ws(s.back()))
    return false;
  const std::string ideo = "\xE3\x80\x80"; // U+3000
  return !s.starts_with(ideo) && !s.ends_with(ideo);
}

size_t cp_len(const std::string &s) { return decode_utf8(s).size(); }

struct Reader {
  std::vector<std::string> &viol;
  bool fatal = false; // 字段拿不到/类型不对/词表外 => 后续 K/G 规则不再跑

  void bad(std::string s, bool is_fatal) {
    viol.push_back("违规:" + std::move(s));
    fatal |= is_fatal;
  }

  // S1 键集合恰好相等
  void keys(const Json &obj, std::span<const char *const> want, const char *path) {
    for (const char *w : want)
      if (!obj.get(w))
        bad(F("S1 %s 缺键 %s", path, w), true);
    for (const std::string &k : obj.keys)
      if (std::find(want.begin(), want.end(), k) == want.end())
        bad(F("S1 %s 多键 %s", path, k.c_str()), false);
  }
  void keys(const Json &obj, std::initializer_list<const char *> want, const char *path) {
    keys(obj, std::span<const char *const>(want.begin(), want.size()), path);
  }

  const Json *typed(const Json &obj, const char *key, Json::Kind kind, const char *path) {
    const Json *v = obj.get(key);
    if (!v)
      return nullptr; // S1 已报
    if (v->kind != kind) {
      bad(F("S2 %s.%s 类型不符", path, key), true);
      return nullptr;
    }
    return v;
  }

  bool str(const Json &obj, const char *key, const char *path, std::string &out, size_t max_cp = 0) {
    const Json *v = typed(obj, key, Json::String, path);
    if (!v)
      return false;
    out = v->str;
    if (!trimmed_nonempty(out)) {
      bad(F("S2 %s.%s 为空或有首尾空白", path, key), true);
      return false;
    }
    if (max_cp && cp_len(out) > max_cp)
      bad(F("S4 %s.%s 超%zu字", path, key, max_cp), false);
    return true;
  }

  bool integer(const Json &obj, const char *key, const char *path, int &out) {
    const Json *v = typed(obj, key, Json::Number, path);
    if (!v)
      return false;
    if (!canon_number(v->num, true)) {
      bad(F("S2 %s.%s 非规范整数 %s", path, key, v->num.c_str()), true);
      return false;
    }
    out = atoi(v->num.c_str());
    return true;
  }

  template <class E>
  bool enum1(const Json &obj, const char *key, const char *path, bool (*parse)(std::string_view, E &), E &out) {
    const Json *v = typed(obj, key, Json::String, path);
    if (!v)
      return false;
    if (!parse(v->str, out)) {
      bad(F("V1 %s.%s 词表外 %s", path, key, v->str.c_str()), true);
      return false;
    }
    return true;
  }

  // 枚举列表: V1 词表内, S3 按词表序严格递增 (自然去重), S4 非空 (nonempty 时)
  template <class E>
  bool enum_list(const Json &obj, const char *key, const char *path, bool (*parse)(std::string_view, E &),
                 std::vector<E> &out, bool nonempty) {
    const Json *v = typed(obj, key, Json::Array, path);
    if (!v)
      return false;
    bool ok = true;
    for (const Json &e : v->arr) {
      if (e.kind != Json::String) {
        bad(F("S2 %s.%s 元素非字符串", path, key), true);
        return false;
      }
      E val;
      if (!parse(e.str, val)) {
        bad(F("V1 %s.%s 词表外 %s", path, key, e.str.c_str()), true);
        ok = false;
        continue;
      }
      if (!out.empty() && !(out.back() < val))
        bad(F("S3 %s.%s 未按词表序去重 (%s)", path, key, e.str.c_str()), false);
      out.push_back(val);
    }
    if (nonempty && v->arr.empty()) {
      bad(F("S4 %s.%s 为空", path, key), true);
      return false;
    }
    return ok;
  }

  // 字符串列表: S2 非空项, S3 字节序严格递增
  bool str_list(const Json &obj, const char *key, const char *path, std::vector<std::string> &out) {
    const Json *v = typed(obj, key, Json::Array, path);
    if (!v)
      return false;
    for (const Json &e : v->arr) {
      if (e.kind != Json::String || !trimmed_nonempty(e.str)) {
        bad(F("S2 %s.%s 元素非字符串或为空", path, key), true);
        return false;
      }
      if (!out.empty() && !(out.back() < e.str))
        bad(F("S3 %s.%s 未按字节序去重 (%s)", path, key, e.str.c_str()), false);
      out.push_back(e.str);
    }
    return true;
  }

  // 对象列表: 每项非对象 => S2 (致命); 回调返回该项是否完整可用
  template <class T>
  void obj_list(const Json &obj, const char *key, const char *path, std::vector<T> &out,
                bool (*item)(Reader &, const Json &, const char *, T &)) {
    const Json *v = typed(obj, key, Json::Array, path);
    if (!v)
      return;
    for (size_t k = 0; k < v->arr.size(); ++k) {
      std::string p = F("%s.%s[%zu]", path, key, k);
      if (v->arr[k].kind != Json::Object) {
        bad("S2 " + p + " 非对象", true);
        continue;
      }
      T t;
      if (item(*this, v->arr[k], p.c_str(), t))
        out.push_back(std::move(t));
    }
  }
};

bool read_factor(Reader &r, const Json &e, const char *path, FactorTag &f) {
  r.keys(e, {"name", "family", "direction", "evidence"}, path);
  bool ok = r.str(e, "name", path, f.name, TAG_MAX_FACTOR_NAME_CP);
  ok &= r.enum1(e, "family", path, parse_FactorFamily, f.family);
  ok &= r.enum1(e, "direction", path, parse_Direction, f.direction);
  ok &= r.str(e, "evidence", path, f.evidence);
  return ok;
}

bool read_finding(Reader &r, const Json &e, const char *path, Finding &f) {
  r.keys(e, {"text", "evidence"}, path);
  bool ok = r.str(e, "text", path, f.text);
  ok &= r.str(e, "evidence", path, f.evidence);
  return ok;
}

// Metric: pool 阶段多一个 universe 键
template <bool POOL>
bool read_metric(Reader &r, const Json &e, const char *path, Metric &m) {
  if (POOL)
    r.keys(e, {"kind", "value", "universe", "period", "evidence"}, path);
  else
    r.keys(e, {"kind", "value", "period", "evidence"}, path);
  bool ok = r.enum1(e, "kind", path, parse_MetricKind, m.kind);
  if (const Json *v = r.typed(e, "value", Json::Number, path)) {
    if (!canon_number(v->num, false)) {
      r.bad(F("S2 %s.value 非规范数字 %s", path, v->num.c_str()), true);
      ok = false;
    }
    m.value = v->num;
  } else {
    ok = false;
  }
  if (POOL)
    ok &= r.enum1(e, "universe", path, parse_Universe, m.universe);
  if (const Json *p = r.typed(e, "period", Json::Array, path)) {
    bool two = p->arr.size() == 2 && p->arr[0].kind == Json::String && p->arr[1].kind == Json::String;
    if (two) {
      m.period_beg = p->arr[0].str;
      m.period_end = p->arr[1].str;
    } else if (!p->arr.empty()) {
      r.bad(F("S2 %s.period 须为 [] 或两个字符串", path), true);
      ok = false;
    }
  } else {
    ok = false;
  }
  ok &= r.str(e, "evidence", path, m.evidence);
  return ok;
}

// 一个阶段子结构: 键集与字段布局由 STAGE_SPEC 决定
void read_stage(Reader &r, const Json &obj, PipeStage st, StageTag &s) {
  const StageSpec &sp = STAGE_SPEC[(size_t)st];
  const char *path = code_of(st);
  std::vector<const char *> want = {"module", "approach"};
  if (sp.baseline)
    want.push_back("baseline");
  if (sp.has_setup())
    want.push_back("setup");
  if (sp.has_result())
    want.push_back("result");
  r.keys(obj, want, path);

  r.enum_list(obj, "module", path, parse_Module, s.module, true);
  r.enum_list(obj, "approach", path, parse_Approach, s.approach, true);
  if (sp.baseline)
    r.enum_list(obj, "baseline", path, parse_Approach, s.baseline, false);

  if (sp.has_setup())
    if (const Json *su = r.typed(obj, "setup", Json::Object, path)) {
      std::string sp_path = F("%s.setup", path);
      std::vector<const char *> keys;
      if (sp.universe)
        keys.push_back("universe");
      if (sp.data)
        keys.push_back("data");
      if (sp.holding)
        keys.push_back("holding");
      if (sp.risk_factors)
        keys.push_back("risk_factors");
      if (sp.horizon)
        keys.push_back("horizon");
      if (sp.rebalance)
        keys.push_back("rebalance");
      r.keys(*su, keys, sp_path.c_str());
      if (sp.universe)
        r.enum_list(*su, "universe", sp_path.c_str(), parse_Universe, s.universe, true);
      if (sp.data)
        if (const Json *d = r.typed(*su, "data", Json::Object, sp_path.c_str())) {
          std::string dp = sp_path + ".data";
          r.keys(*d, {"source", "freq"}, dp.c_str());
          r.enum_list(*d, "source", dp.c_str(), parse_DataSource, s.data.source, true);
          r.enum1(*d, "freq", dp.c_str(), parse_DataFreq, s.data.freq);
        }
      if (sp.holding)
        if (const Json *h = r.typed(*su, "holding", Json::Object, sp_path.c_str())) {
          std::string hp = sp_path + ".holding";
          r.keys(*h, {"rebalance", "horizon"}, hp.c_str());
          r.enum1(*h, "rebalance", hp.c_str(), parse_Period, s.holding.rebalance);
          r.enum1(*h, "horizon", hp.c_str(), parse_Period, s.holding.horizon);
        }
      if (sp.risk_factors)
        r.enum_list(*su, "risk_factors", sp_path.c_str(), parse_FactorFamily, s.risk_factors, false);
      if (sp.horizon)
        r.enum1(*su, "horizon", sp_path.c_str(), parse_Period, s.horizon);
      if (sp.rebalance)
        r.enum1(*su, "rebalance", sp_path.c_str(), parse_Period, s.rebalance);
    }

  if (sp.has_result())
    if (const Json *re = r.typed(obj, "result", Json::Object, path)) {
      std::string rp = F("%s.result", path);
      std::vector<const char *> keys;
      if (sp.factors)
        keys.push_back("factors");
      if (sp.metrics)
        keys.push_back("metrics");
      r.keys(*re, keys, rp.c_str());
      if (sp.factors)
        r.obj_list(*re, "factors", rp.c_str(), s.factors, read_factor);
      if (sp.metrics)
        r.obj_list(*re, "metrics", rp.c_str(), s.metrics, sp.pool ? &read_metric<true> : &read_metric<false>);
    }
}

} // namespace

bool parse_tag(const std::string &text, const std::string &stem, Tag &tag, std::string &findings_key, std::string &canon,
               std::vector<std::string> &viol) {
  Json j;
  std::string err;
  if (!json_parse(text, j, err)) {
    viol.push_back("违规:F3 json解析失败 " + err);
    return false;
  }
  if (j.kind != Json::Object) {
    viol.push_back("违规:S1 顶层非对象");
    return false;
  }
  Reader r{viol};
  canon = json_canonical(j, tag_key_rank); // F3: 与文件不同时由调用方覆盖写回, 不算违规

  r.keys(j, {"schema_version", "id", "genre", "asset", "primary", "pipe", "findings", "builds_on", "external_ref", "value", "gen"}, "顶层");

  if (r.integer(j, "schema_version", "顶层", tag.schema_version) && tag.schema_version != TAG_SCHEMA_VERSION)
    r.bad(F("S5 schema_version %d != %d", tag.schema_version, TAG_SCHEMA_VERSION), true);
  if (r.str(j, "id", "顶层", tag.id) && tag.id != stem)
    r.bad("F2 id 与文件名不符", true);

  r.enum1(j, "genre", "顶层", parse_Genre, tag.genre);
  r.enum_list(j, "asset", "顶层", parse_Asset, tag.asset, true);
  r.enum1(j, "primary", "顶层", parse_PipeStage, tag.primary);

  // pipe: 键 = 出现的阶段 (F3 已保证键按字节序 = 阶段序), 值 = 阶段子结构
  if (const Json *pipe = r.typed(j, "pipe", Json::Object, "顶层")) {
    if (pipe->keys.empty())
      r.bad("S4 pipe 无阶段", true);
    for (size_t k = 0; k < pipe->keys.size(); ++k) {
      PipeStage st;
      if (!parse_PipeStage(pipe->keys[k], st)) {
        r.bad(F("S1 pipe 多键 %s", pipe->keys[k].c_str()), true);
        continue;
      }
      if (pipe->vals[k].kind != Json::Object) {
        r.bad(F("S2 pipe.%s 非对象", code_of(st)), true);
        continue;
      }
      read_stage(r, pipe->vals[k], st, tag.pipe[(size_t)st].emplace());
    }
  }

  if (const Json *fi = r.typed(j, "findings", Json::Array, "顶层")) {
    findings_key = json_canonical(*fi);
    if (fi->arr.empty())
      r.bad("S4 findings 为空", true);
    r.obj_list(j, "findings", "顶层", tag.findings, read_finding);
  }

  r.str_list(j, "builds_on", "顶层", tag.builds_on);
  r.str_list(j, "external_ref", "顶层", tag.external_ref);
  r.enum1(j, "value", "顶层", parse_Value, tag.value);

  if (const Json *g = r.typed(j, "gen", Json::Object, "顶层")) {
    r.keys(*g, {"model", "prompt_sha256"}, "gen");
    r.str(*g, "model", "gen", tag.gen.model);
    if (r.str(*g, "prompt_sha256", "gen", tag.gen.prompt_sha256)) {
      bool hex = tag.gen.prompt_sha256.size() == 64 &&
                 std::all_of(tag.gen.prompt_sha256.begin(), tag.gen.prompt_sha256.end(),
                             [](char c) { return is_digit(c) || (c >= 'a' && c <= 'f'); });
      if (!hex)
        r.bad("S2 gen.prompt_sha256 非 64 位小写十六进制", false);
    }
  }

  return !r.fatal;
}
