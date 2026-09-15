#include "common/json.hpp"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <numeric>

#include "common/util.hpp"

const Json *Json::get(std::string_view key) const {
  assert(kind == Object);
  for (size_t i = 0; i < keys.size(); ++i)
    if (keys[i] == key)
      return &vals[i];
  return nullptr;
}

namespace {

struct Parser {
  const std::string &s;
  size_t i = 0;
  std::string err;

  explicit Parser(const std::string &text) : s(text) {}

  bool fail(const char *why) {
    if (err.empty()) {
      size_t line = 1, col = 1;
      for (size_t k = 0; k < i && k < s.size(); ++k)
        if (s[k] == '\n')
          ++line, col = 1;
        else
          ++col;
      err = F("%zu:%zu %s", line, col, why);
    }
    return false;
  }

  void ws() {
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r'))
      ++i;
  }

  bool lit(const char *w, Json &out, Json::Kind k, bool b) {
    size_t n = strlen(w);
    if (s.compare(i, n, w) != 0)
      return fail("非法字面量");
    i += n;
    out.kind = k;
    out.b = b;
    return true;
  }

  bool hex4(uint32_t &v) {
    if (i + 4 > s.size())
      return fail("\\u 后不足 4 位");
    v = 0;
    for (int k = 0; k < 4; ++k) {
      char c = s[i++];
      v <<= 4;
      if (c >= '0' && c <= '9')
        v |= c - '0';
      else if (c >= 'a' && c <= 'f')
        v |= c - 'a' + 10;
      else if (c >= 'A' && c <= 'F')
        v |= c - 'A' + 10;
      else
        return fail("\\u 后非十六进制");
    }
    return true;
  }

  bool string(std::string &out) {
    assert(s[i] == '"');
    ++i;
    std::string raw; // 未转义原始段, 最后统一校验 UTF-8
    for (;;) {
      if (i >= s.size())
        return fail("字符串未闭合");
      unsigned char c = (unsigned char)s[i];
      if (c == '"') {
        ++i;
        break;
      }
      if (c < 0x20)
        return fail("字符串含未转义控制字符");
      if (c != '\\') {
        out += (char)c;
        raw += (char)c;
        ++i;
        continue;
      }
      ++i;
      if (i >= s.size())
        return fail("转义未完成");
      char e = s[i++];
      switch (e) {
      case '"':
        out += '"';
        break;
      case '\\':
        out += '\\';
        break;
      case '/':
        out += '/';
        break;
      case 'b':
        out += '\b';
        break;
      case 'f':
        out += '\f';
        break;
      case 'n':
        out += '\n';
        break;
      case 'r':
        out += '\r';
        break;
      case 't':
        out += '\t';
        break;
      case 'u': {
        uint32_t cp;
        if (!hex4(cp))
          return false;
        if (cp >= 0xD800 && cp <= 0xDBFF) {
          if (s.compare(i, 2, "\\u") != 0)
            return fail("高代理项后缺低代理项");
          i += 2;
          uint32_t lo;
          if (!hex4(lo))
            return false;
          if (lo < 0xDC00 || lo > 0xDFFF)
            return fail("非法低代理项");
          cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
        } else if (cp >= 0xDC00 && cp <= 0xDFFF) {
          return fail("孤立低代理项");
        }
        append_utf8(out, cp);
        break;
      }
      default:
        return fail("非法转义");
      }
    }
    for (char32_t cp : decode_utf8(raw))
      if (cp == 0xFFFD)
        return fail("字符串非法 UTF-8");
    return true;
  }

  bool number(Json &out) {
    size_t beg = i;
    if (s[i] == '-')
      ++i;
    if (i >= s.size() || !is_digit(s[i]))
      return fail("数字缺整数部分");
    if (s[i] == '0')
      ++i;
    else
      while (i < s.size() && is_digit(s[i]))
        ++i;
    if (i < s.size() && s[i] == '.') {
      ++i;
      if (i >= s.size() || !is_digit(s[i]))
        return fail("小数点后缺数字");
      while (i < s.size() && is_digit(s[i]))
        ++i;
    }
    if (i < s.size() && (s[i] == 'e' || s[i] == 'E')) {
      ++i;
      if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        ++i;
      if (i >= s.size() || !is_digit(s[i]))
        return fail("指数缺数字");
      while (i < s.size() && is_digit(s[i]))
        ++i;
    }
    out.kind = Json::Number;
    out.num = s.substr(beg, i - beg);
    return true;
  }

  bool value(Json &out, int depth) {
    if (depth > 64)
      return fail("嵌套过深");
    ws();
    if (i >= s.size())
      return fail("意外结束");
    char c = s[i];
    if (c == '{') {
      ++i;
      out.kind = Json::Object;
      ws();
      if (i < s.size() && s[i] == '}') {
        ++i;
        return true;
      }
      for (;;) {
        ws();
        if (i >= s.size() || s[i] != '"')
          return fail("对象键须为字符串");
        std::string key;
        if (!string(key))
          return false;
        if (std::find(out.keys.begin(), out.keys.end(), key) != out.keys.end())
          return fail("对象键重复");
        ws();
        if (i >= s.size() || s[i] != ':')
          return fail("键后缺冒号");
        ++i;
        out.keys.push_back(std::move(key));
        out.vals.emplace_back();
        if (!value(out.vals.back(), depth + 1))
          return false;
        ws();
        if (i < s.size() && s[i] == ',') {
          ++i;
          continue;
        }
        if (i < s.size() && s[i] == '}') {
          ++i;
          return true;
        }
        return fail("对象内缺逗号或右花括号");
      }
    }
    if (c == '[') {
      ++i;
      out.kind = Json::Array;
      ws();
      if (i < s.size() && s[i] == ']') {
        ++i;
        return true;
      }
      for (;;) {
        out.arr.emplace_back();
        if (!value(out.arr.back(), depth + 1))
          return false;
        ws();
        if (i < s.size() && s[i] == ',') {
          ++i;
          continue;
        }
        if (i < s.size() && s[i] == ']') {
          ++i;
          return true;
        }
        return fail("数组内缺逗号或右方括号");
      }
    }
    if (c == '"') {
      out.kind = Json::String;
      return string(out.str);
    }
    if (c == 't')
      return lit("true", out, Json::Bool, true);
    if (c == 'f')
      return lit("false", out, Json::Bool, false);
    if (c == 'n')
      return lit("null", out, Json::Null, false);
    if (c == '-' || is_digit(c))
      return number(out);
    return fail("非法字符");
  }
};

void dump_string(const std::string &s, std::string &o) {
  o += '"';
  for (unsigned char c : s) {
    switch (c) {
    case '"':
      o += "\\\"";
      break;
    case '\\':
      o += "\\\\";
      break;
    case '\n':
      o += "\\n";
      break;
    case '\r':
      o += "\\r";
      break;
    case '\t':
      o += "\\t";
      break;
    case '\b':
      o += "\\b";
      break;
    case '\f':
      o += "\\f";
      break;
    default:
      if (c < 0x20)
        o += F("\\u%04x", c);
      else
        o += (char)c;
    }
  }
  o += '"';
}

void dump(const Json &j, int indent, KeyRank rank, std::string &o) {
  std::string pad((size_t)indent * 2, ' '), pad_in((size_t)(indent + 1) * 2, ' ');
  switch (j.kind) {
  case Json::Null:
    o += "null";
    break;
  case Json::Bool:
    o += j.b ? "true" : "false";
    break;
  case Json::Number:
    o += j.num;
    break;
  case Json::String:
    dump_string(j.str, o);
    break;
  case Json::Array:
    if (j.arr.empty()) {
      o += "[]";
      break;
    }
    o += "[\n";
    for (size_t k = 0; k < j.arr.size(); ++k) {
      o += pad_in;
      dump(j.arr[k], indent + 1, rank, o);
      o += k + 1 < j.arr.size() ? ",\n" : "\n";
    }
    o += pad + "]";
    break;
  case Json::Object: {
    if (j.keys.empty()) {
      o += "{}";
      break;
    }
    std::vector<size_t> order(j.keys.size());
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](size_t a, size_t b) {
      int ra = rank ? rank(j.keys[a]) : 0, rb = rank ? rank(j.keys[b]) : 0;
      return ra != rb ? ra < rb : j.keys[a] < j.keys[b];
    });
    o += "{\n";
    for (size_t k = 0; k < order.size(); ++k) {
      o += pad_in;
      dump_string(j.keys[order[k]], o);
      o += ": ";
      dump(j.vals[order[k]], indent + 1, rank, o);
      o += k + 1 < order.size() ? ",\n" : "\n";
    }
    o += pad + "}";
    break;
  }
  }
}

} // namespace

bool json_parse(const std::string &text, Json &out, std::string &err) {
  Parser p(text);
  out = Json();
  if (!p.value(out, 0)) {
    err = p.err;
    return false;
  }
  p.ws();
  if (p.i != text.size()) {
    p.fail("顶层值后有多余内容");
    err = p.err;
    return false;
  }
  return true;
}

std::string json_canonical(const Json &j, KeyRank rank) {
  std::string o;
  dump(j, 0, rank, o);
  o += '\n';
  return o;
}
