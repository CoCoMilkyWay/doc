#include "common/pdftext.hpp"

#include <memory>
#include <mutex>

#include <poppler-document.h>
#include <poppler-global.h>
#include <poppler-page.h>

// poppler 遇到轻微损坏会往 stderr 吐警告, 静音 (等价于原先的 pdftotext -q)
static void silence(const std::string &, void *) {}

// 首个文档常驻不释放: 每个 poppler::document 持有一个引用计数的 GlobalParamsIniter,
// 计数归零就销毁全局字体表, 多线程反复 open/close 会不断重建 fontconfig
static poppler::document *pinned = nullptr;

int pdf_has_text(const std::string &path, int pages) {
  static std::once_flag once;
  std::call_once(once, [&] {
    poppler::set_debug_error_function(silence, nullptr);
    pinned = poppler::document::load_from_file(path);
  });

  std::unique_ptr<poppler::document> doc(poppler::document::load_from_file(path));
  if (!doc || doc->is_locked()) // 损坏, 或空口令打不开
    return -1;
  int n = doc->pages();
  if (n <= 0)
    return -1;
  if (n > pages)
    n = pages;

  for (int i = 0; i < n; ++i) {
    std::unique_ptr<poppler::page> pg(doc->create_page(i));
    if (!pg)
      return -1;
    // ustring 是 utf-16 码元; 去掉换页符与空白后还有内容即算有文字层
    for (unsigned short c : pg->text())
      if (c != 0x0C && c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != 0x0B)
        return 1;
  }
  return 0;
}
