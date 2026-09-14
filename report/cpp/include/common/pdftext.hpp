// 调 poppler-utils 的 pdftotext 判断 PDF 是否有文字层。
#pragma once

#include <string>

// 抽取前 pages 页文字。1=有文字 0=无文字(扫描件) -1=pdftotext 无法解析
int pdf_has_text(const std::string &path, int pages);
