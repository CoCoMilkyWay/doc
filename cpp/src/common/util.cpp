#include "common/util.hpp"

#include <cassert>
#include <chrono>
#include <cstdarg>
#include <cstdio>

std::string F(const char *fmt, ...) {
  char buf[1024];
  va_list ap;
  va_start(ap, fmt);
  int n = vsnprintf(buf, sizeof buf, fmt, ap);
  va_end(ap);
  assert(n >= 0);
  if ((size_t)n < sizeof buf)
    return std::string(buf, n);
  std::string big((size_t)n, '\0');
  va_start(ap, fmt);
  vsnprintf(big.data(), (size_t)n + 1, fmt, ap);
  va_end(ap);
  return big;
}

double now_ms() {
  using namespace std::chrono;
  return duration<double, std::milli>(steady_clock::now().time_since_epoch()).count();
}

std::vector<std::string> split(const std::string &s, char sep) {
  std::vector<std::string> out;
  size_t beg = 0;
  for (size_t i = 0; i <= s.size(); ++i)
    if (i == s.size() || s[i] == sep) {
      out.push_back(s.substr(beg, i - beg));
      beg = i + 1;
    }
  return out;
}

std::string lower_ascii(std::string s) {
  for (char &c : s)
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';
  return s;
}

std::vector<char32_t> decode_utf8(const std::string &s) {
  std::vector<char32_t> cps;
  size_t i = 0;
  while (i < s.size()) {
    unsigned char c = (unsigned char)s[i];
    char32_t cp;
    size_t n;
    if (c < 0x80) {
      cp = c;
      n = 1;
    } else if ((c & 0xE0) == 0xC0) {
      cp = c & 0x1F;
      n = 2;
    } else if ((c & 0xF0) == 0xE0) {
      cp = c & 0x0F;
      n = 3;
    } else if ((c & 0xF8) == 0xF0) {
      cp = c & 0x07;
      n = 4;
    } else {
      cps.push_back(0xFFFD);
      ++i;
      continue;
    }
    if (i + n > s.size()) {
      cps.push_back(0xFFFD);
      break;
    }
    bool bad = false;
    for (size_t k = 1; k < n; ++k) {
      unsigned char t = (unsigned char)s[i + k];
      if ((t & 0xC0) != 0x80) {
        bad = true;
        break;
      }
      cp = (cp << 6) | (t & 0x3F);
    }
    cps.push_back(bad ? 0xFFFD : cp);
    i += bad ? 1 : n;
  }
  return cps;
}

void append_utf8(std::string &out, char32_t cp) {
  if (cp < 0x80) {
    out += (char)cp;
  } else if (cp < 0x800) {
    out += (char)(0xC0 | (cp >> 6));
    out += (char)(0x80 | (cp & 0x3F));
  } else if (cp < 0x10000) {
    out += (char)(0xE0 | (cp >> 12));
    out += (char)(0x80 | ((cp >> 6) & 0x3F));
    out += (char)(0x80 | (cp & 0x3F));
  } else {
    out += (char)(0xF0 | (cp >> 18));
    out += (char)(0x80 | ((cp >> 12) & 0x3F));
    out += (char)(0x80 | ((cp >> 6) & 0x3F));
    out += (char)(0x80 | (cp & 0x3F));
  }
}

bool is_digit(char32_t c) { return c >= '0' && c <= '9'; }
bool is_lower(char32_t c) { return c >= 'a' && c <= 'z'; }
bool is_cjk(char32_t c) {
  return (c >= 0x4E00 && c <= 0x9FFF) || (c >= 0x3400 && c <= 0x4DBF);
}

bool all_of_class(const std::vector<char32_t> &cps, bool (*pred)(char32_t)) {
  if (cps.empty())
    return false;
  for (char32_t c : cps)
    if (!pred(c))
      return false;
  return true;
}
