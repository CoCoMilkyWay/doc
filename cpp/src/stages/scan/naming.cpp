#include "stages/scan/scan.hpp"

#include "common/util.hpp"

static bool cls_series(char32_t c) { return is_lower(c) || is_cjk(c); }
static bool cls_title(char32_t c) {
  return is_digit(c) || is_lower(c) || c == '_' || is_cjk(c);
}

// C1 整名结构: '-' 不属于任何字符类, 按 '-' 切分无歧义
bool parse_name(const std::string &fname, Seg &g) {
  if (!fname.ends_with(".pdf"))
    return false;
  std::vector<std::string> parts = split(fname.substr(0, fname.size() - 4), '-');
  if (parts.size() != 5)
    return false;

  std::vector<char32_t> date = decode_utf8(parts[0]);
  std::vector<char32_t> brok = decode_utf8(parts[1]);
  std::vector<char32_t> seri = decode_utf8(parts[2]);
  std::vector<char32_t> num = decode_utf8(parts[3]);
  std::vector<char32_t> titl = decode_utf8(parts[4]);

  if (date.size() != 8 || !all_of_class(date, is_digit))
    return false;
  if (!all_of_class(brok, is_cjk))
    return false;
  if (!all_of_class(seri, cls_series))
    return false;
  if (num.size() != 3 && num.size() != 4)
    return false;
  for (size_t i = 0; i < 3; ++i)
    if (!is_digit(num[i]))
      return false;
  if (num.size() == 4 && !is_lower(num[3]))
    return false;
  if (!all_of_class(titl, cls_title))
    return false;

  g.date = parts[0];
  g.broker = parts[1];
  g.series = parts[2];
  g.num = parts[3];
  g.title = parts[4];
  g.broker_len = brok.size();
  g.series_len = seri.size();
  return true;
}

static bool valid_date(const std::string &s) {
  int y = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
  int m = (s[4] - '0') * 10 + (s[5] - '0');
  int d = (s[6] - '0') * 10 + (s[7] - '0');
  if (y < 1 || m < 1 || m > 12)
    return false;
  static const int dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int md = dim[m - 1];
  if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
    md = 29;
  return d >= 1 && d <= md;
}

static int date_year(const std::string &s) {
  return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
}

void check_naming(const std::string &fname, Rec &r) {
  // C7 长度
  if (fname.size() >= MAX_NAME_BYTES)
    r.viol.push_back(F("违规:文件名超%zu字节", MAX_NAME_BYTES));
  // C1 整名结构
  if (!parse_name(fname, r.g)) {
    r.viol.push_back("违规:整名结构不符");
    return;
  }
  r.parsed = true;
  const Seg &g = r.g;
  // C2 日期
  if (g.date == "00000000")
    r.place.push_back("占位:日期");
  else if (!valid_date(g.date))
    r.viol.push_back(F("违规:非法日期%s", g.date.c_str()));
  else if (date_year(g.date) < YEAR_MIN || date_year(g.date) > YEAR_MAX)
    r.viol.push_back(F("违规:日期年份越界%s", g.date.c_str()));
  // C3 券商
  if (g.broker == WU)
    r.viol.push_back("违规:券商为无");
  else if (g.broker_len < BROKER_MINLEN || g.broker_len > BROKER_MAXLEN)
    r.viol.push_back(F("违规:券商名长度越界(%s)", g.broker.c_str()));
  // C4/C5 系列与序号
  if (g.series == WU) {
    r.viol.push_back("违规:系列为无");
    if (g.num != "000")
      r.viol.push_back(F("违规:系列为无但序号%s", g.num.c_str()));
  } else {
    if (g.num == "000")
      r.viol.push_back("违规:有系列但序号000");
    if (g.series_len > SERIES_MAXLEN)
      r.viol.push_back(F("违规:系列名超%zu字符", SERIES_MAXLEN));
  }
  // C6 标题
  if (g.title == WU)
    r.viol.push_back("违规:标题为无");
  if (g.title.contains("__"))
    r.viol.push_back("违规:标题含连续下划线");
  if (g.title.front() == '_' || g.title.back() == '_')
    r.viol.push_back("违规:标题以下划线开头或结尾");
}
