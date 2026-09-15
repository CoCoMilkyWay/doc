#include "stages/tag/tag.hpp"

#include <algorithm>
#include <cstdlib>
#include <initializer_list>
#include <span>

#include "common/json.hpp"
#include "common/util.hpp"

namespace {

// F3 的一部分: 数字 lexeme 归一到 -?(0|[1-9]\d*)(\.\d*[1-9])? (展开指数, 去前导零与尾零, -0 → 0).
// 只改写法不改值 —— json.hpp 有意保留原文, 这里按标签的规范形重写一遍, 和键序同属 "格式化" 而不是违规:
// 为 "0.10" 这种事让 agent 多跑一轮不值 (一轮 ~5 分钱 ~40 秒). 真正的类型错误 (int 带小数) 仍由 S2 判.
// 指数过大时原样留着 (只做改写不做兜底, 越界的值交给 K2 的取值域去判, 不在这里展开出一串零)
std::string norm_number(const std::string &s) {
  bool neg = s[0] == '-';
  size_t i = neg ? 1 : 0;
  std::string d; // 全部数字, 小数点在下标 pt 处
  while (i < s.size() && is_digit(s[i]))
    d += s[i++];
  long pt = (long)d.size();
  if (i < s.size() && s[i] == '.')
    for (++i; i < s.size() && is_digit(s[i]); ++i)
      d += s[i];
  if (i < s.size())
    pt += atol(s.c_str() + i + 1); // 余下只可能是 e/E[+-]NN (json.cpp::number 已保证)
  if (pt < -64 || pt > 64 || d.size() > 64)
    return s;
  if (pt <= 0) {
    d.insert(0, (size_t)(1 - pt), '0');
    pt = 1;
  }
  if ((size_t)pt > d.size())
    d.append((size_t)pt - d.size(), '0');
  std::string ip = d.substr(0, (size_t)pt), fp = d.substr((size_t)pt);
  ip.erase(0, std::min(ip.find_first_not_of('0'), ip.size() - 1));
  while (!fp.empty() && fp.back() == '0')
    fp.pop_back();
  std::string out = fp.empty() ? ip : ip + "." + fp;
  return neg && out != "0" ? "-" + out : out;
}

void norm_numbers(Json &j) {
  if (j.kind == Json::Number)
    j.num = norm_number(j.num);
  for (Json &e : j.arr)
    norm_numbers(e);
  for (Json &v : j.vals)
    norm_numbers(v);
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

  Json *typed(Json &obj, const char *key, Json::Kind kind, const char *path) {
    Json *v = obj.get(key);
    if (!v)
      return nullptr; // S1 已报
    if (v->kind != kind) {
      bad(F("S2 %s.%s 类型不符", path, key), true);
      return nullptr;
    }
    return v;
  }

  bool str(Json &obj, const char *key, const char *path, std::string &out, size_t max_cp = 0) {
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

  bool integer(Json &obj, const char *key, const char *path, int &out) {
    const Json *v = typed(obj, key, Json::Number, path);
    if (!v)
      return false;
    if (v->num.find('.') != std::string::npos) { // 归一后还带小数点 = 真的不是整数
      bad(F("S2 %s.%s 非整数 %s", path, key, v->num.c_str()), true);
      return false;
    }
    out = atoi(v->num.c_str());
    return true;
  }

  template <class E>
  bool enum1(Json &obj, const char *key, const char *path, bool (*parse)(std::string_view, E &), E &out) {
    const Json *v = typed(obj, key, Json::String, path);
    if (!v)
      return false;
    if (!parse(v->str, out)) {
      bad(F("V1 %s.%s 词表外 %s", path, key, v->str.c_str()), true);
      return false;
    }
    return true;
  }

  // F3 的一部分: 列表原地排序去重后写回 (元素不动, 只换顺序 —— 和键序、数字写法同属 "格式化".
  // 实测模型两轮能把同一个列表排成两种相反的顺序: 它在猜, 词表序说明写得再细也治不了, 顺手替它排掉)
  template <class T, class Code>
  void sort_back(Json &v, std::vector<T> &out, Code code) {
    std::sort(out.begin(), out.end());
    out.erase(std::unique(out.begin(), out.end()), out.end());
    v.arr.clear();
    for (const T &t : out) {
      Json &j = v.arr.emplace_back();
      j.kind = Json::String;
      j.str = code(t);
    }
  }

  // 枚举列表: V1 词表内, S4 非空 (nonempty 时); 顺序与重复由 F3 按词表序修掉
  template <class E>
  bool enum_list(Json &obj, const char *key, const char *path, bool (*parse)(std::string_view, E &),
                 std::vector<E> &out, bool nonempty) {
    Json *v = typed(obj, key, Json::Array, path);
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
      out.push_back(val);
    }
    if (nonempty && v->arr.empty()) {
      bad(F("S4 %s.%s 为空", path, key), true);
      return false;
    }
    if (ok) // 有词表外的元素就别写回, 否则等于把它悄悄删了 (V1 已致命, 这篇本来就要打回)
      sort_back(*v, out, [](E e) { return code_of(e); });
    return ok;
  }

  // 字符串列表: S2 非空项; 顺序与重复由 F3 按字节序修掉
  bool str_list(Json &obj, const char *key, const char *path, std::vector<std::string> &out) {
    Json *v = typed(obj, key, Json::Array, path);
    if (!v)
      return false;
    for (const Json &e : v->arr) {
      if (e.kind != Json::String || !trimmed_nonempty(e.str)) {
        bad(F("S2 %s.%s 元素非字符串或为空", path, key), true);
        return false;
      }
      out.push_back(e.str);
    }
    sort_back(*v, out, [](const std::string &s) { return s; });
    return true;
  }

  // 对象列表: 每项非对象 => S2 (致命); 回调返回该项是否完整可用
  template <class T>
  void obj_list(Json &obj, const char *key, const char *path, std::vector<T> &out,
                bool (*item)(Reader &, Json &, const char *, T &)) {
    Json *v = typed(obj, key, Json::Array, path);
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

bool read_factor(Reader &r, Json &e, const char *path, FactorTag &f) {
  r.keys(e, {"name", "family", "direction", "data_period", "horizon", "formula", "stats", "evidence"}, path);
  bool ok = r.str(e, "name", path, f.name, TAG_MAX_FACTOR_NAME_CP);
  ok &= r.enum1(e, "family", path, parse_FactorFamily, f.family);
  ok &= r.enum1(e, "direction", path, parse_Direction, f.direction);
  ok &= r.enum_list(e, "data_period", path, parse_Period, f.data_period, true);
  ok &= r.enum1(e, "horizon", path, parse_Period, f.horizon);
  ok &= r.str(e, "formula", path, f.formula);
  // stats: 定长 N_STAT, 每项 Number 或 Null (= 原文未给); 写法已由 norm_numbers 归一, 取值域归 K2
  if (const Json *st = r.typed(e, "stats", Json::Array, path)) {
    if (st->arr.size() != N_STAT) {
      r.bad(F("S2 %s.stats 须恰好 %zu 项 [ic, rank_ic, icir, return_ls]", path, N_STAT), true);
      ok = false;
    } else {
      for (size_t i = 0; i < N_STAT; ++i) {
        const Json &v = st->arr[i];
        if (v.kind == Json::Number) {
          f.stats[i] = v.num;
        } else if (v.kind != Json::Null) {
          r.bad(F("S2 %s.stats[%zu] (%s) 须为数字或 null", path, i, code_of((Stat)i)), true);
          ok = false;
        }
      }
    }
  } else {
    ok = false;
  }
  ok &= r.str(e, "evidence", path, f.evidence);
  return ok;
}

bool read_finding(Reader &r, Json &e, const char *path, Finding &f) {
  r.keys(e, {"text", "evidence"}, path);
  bool ok = r.str(e, "text", path, f.text);
  ok &= r.str(e, "evidence", path, f.evidence);
  return ok;
}

// 一个阶段子结构: 键集与字段布局由 STAGE_SPEC 决定
void read_stage(Reader &r, Json &obj, PipeStage st, StageTag &s) {
  const StageSpec &sp = STAGE_SPEC[(size_t)st];
  const char *path = code_of(st);
  std::vector<const char *> want = {"module", "approach"};
  if (sp.baseline)
    want.push_back("baseline");
  if (sp.has_setup())
    want.push_back("setup");
  if (sp.factors)
    want.push_back("factors");
  r.keys(obj, want, path);

  r.enum_list(obj, "module", path, parse_Module, s.module, true);
  r.enum_list(obj, "approach", path, parse_Approach, s.approach, true);
  if (sp.baseline)
    r.enum_list(obj, "baseline", path, parse_Approach, s.baseline, false);

  if (sp.has_setup())
    if (Json *su = r.typed(obj, "setup", Json::Object, path)) {
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
        if (Json *d = r.typed(*su, "data", Json::Object, sp_path.c_str())) {
          std::string dp = sp_path + ".data";
          r.keys(*d, {"source", "freq"}, dp.c_str());
          r.enum_list(*d, "source", dp.c_str(), parse_DataSource, s.data.source, true);
          r.enum1(*d, "freq", dp.c_str(), parse_DataFreq, s.data.freq);
        }
      if (sp.holding)
        if (Json *h = r.typed(*su, "holding", Json::Object, sp_path.c_str())) {
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

  if (sp.factors)
    r.obj_list(obj, "factors", path, s.factors, read_factor);
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
  norm_numbers(j); // F3 的一部分, 早于各规则做 (它们读到的也是归一后的 lexeme); 列表排序在下面各 Reader 里就地做

  r.keys(j, {"schema_version", "id", "genre", "asset", "primary", "pipe", "findings", "builds_on", "external_ref", "value", "gen"}, "顶层");

  if (r.integer(j, "schema_version", "顶层", tag.schema_version) && tag.schema_version != TAG_SCHEMA_VERSION)
    r.bad(F("S5 schema_version %d != %d", tag.schema_version, TAG_SCHEMA_VERSION), true);
  if (r.str(j, "id", "顶层", tag.id) && tag.id != stem)
    r.bad("F2 id 与文件名不符", true);

  r.enum1(j, "genre", "顶层", parse_Genre, tag.genre);
  r.enum_list(j, "asset", "顶层", parse_Asset, tag.asset, true);
  r.enum1(j, "primary", "顶层", parse_PipeStage, tag.primary);

  // pipe: 键 = 出现的阶段 (F3 已保证键按字节序 = 阶段序), 值 = 阶段子结构
  if (Json *pipe = r.typed(j, "pipe", Json::Object, "顶层")) {
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

  if (Json *fi = r.typed(j, "findings", Json::Array, "顶层")) {
    findings_key = json_canonical(*fi);
    if (fi->arr.empty())
      r.bad("S4 findings 为空", true);
    r.obj_list(j, "findings", "顶层", tag.findings, read_finding);
  }

  r.str_list(j, "builds_on", "顶层", tag.builds_on);
  r.str_list(j, "external_ref", "顶层", tag.external_ref);
  r.enum1(j, "value", "顶层", parse_Value, tag.value);

  if (Json *g = r.typed(j, "gen", Json::Object, "顶层")) {
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

  // F3: 数字与列表都已就地归一, 这里才定稿; 与文件不同时由调用方覆盖写回, 不算违规
  canon = json_canonical(j, tag_key_rank);
  return !r.fatal;
}
