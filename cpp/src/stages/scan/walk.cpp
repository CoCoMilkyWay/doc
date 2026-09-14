#include "stages/scan/scan.hpp"

#include "common/fs.hpp"
#include "common/util.hpp"

// 递归遍历 (不跟随符号链接), 目录与文件均按字节序, 保证输出稳定
static void walk(const std::string &root, const std::string &rel,
                 std::vector<Rec> &records, size_t &total) {
  std::string dirpath = rel == "." ? root : root + "/" + rel;
  std::vector<std::string> dirs, files;
  list_dir(dirpath, dirs, files);

  for (const std::string &f : files) {
    if (!lower_ascii(f).ends_with(".pdf"))
      continue;
    ++total;
    Rec r;
    r.folder = rel;
    r.name = f;
    r.path = dirpath + "/" + f;
    if (!f.ends_with(".pdf")) // 扩展名必须小写
      r.viol.push_back("违规:扩展名非小写pdf");
    else
      check_naming(f, r);
    records.push_back(std::move(r));
  }
  for (const std::string &d : dirs)
    walk(root, rel == "." ? d : rel + "/" + d, records, total);
}

size_t collect_pdfs(const std::string &root, std::vector<Rec> &records) {
  size_t total = 0;
  walk(root, ".", records, total);
  return total;
}
