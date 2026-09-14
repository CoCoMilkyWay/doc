// 用 libpoppler-cpp 在进程内解析 PDF, 判断是否有文字层。
#pragma once

#include <string>

// 抽取前 pages 页文字, 一旦发现文字立即停止解析。
// 1=有文字 0=无文字(扫描件) -1=无法解析(损坏或需要口令)
int pdf_has_text(const std::string &path, int pages);
