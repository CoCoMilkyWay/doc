// 字符串与 UTF-8 小工具。
#pragma once

#include <string>
#include <vector>

// printf 风格格式化
[[gnu::format(printf, 1, 2)]] std::string F(const char *fmt, ...);

std::vector<std::string> split(const std::string &s, char sep);
std::string lower_ascii(std::string s);

// UTF-8 解码; 非法序列产出 U+FFFD (不属于任何字符类, 必然触发结构违规)
std::vector<char32_t> decode_utf8(const std::string &s);

// 文件名字符类
bool is_digit(char32_t c);
bool is_lower(char32_t c);
bool is_cjk(char32_t c);

// 非空且每个码点都满足 pred
bool all_of_class(const std::vector<char32_t> &cps, bool (*pred)(char32_t));
