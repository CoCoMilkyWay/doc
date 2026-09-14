#include "stages/scan/scan.hpp"

#include <atomic>
#include <cassert>
#include <thread>
#include <unordered_map>

#include <sys/stat.h>

#include "common/pdftext.hpp"
#include "common/sha256.hpp"
#include "common/util.hpp"

void check_content(std::vector<Rec> &records, unsigned workers) {
  // X5 按文件字节判重, 字节相同必然大小相同, 故只对大小有碰撞的文件算 sha256;
  // 其余文件 digest 保持为空, 不参与后面的分组
  std::unordered_map<size_t, std::vector<size_t>> by_size;
  for (size_t i = 0; i < records.size(); ++i) {
    struct stat st;
    assert(stat(records[i].path.c_str(), &st) == 0);
    by_size[(size_t)st.st_size].push_back(i);
  }
  std::vector<char> need_hash(records.size(), 0);
  for (const auto &[sz, idxs] : by_size)
    if (idxs.size() > 1)
      for (size_t i : idxs)
        need_hash[i] = 1;

  // 并行: 逐文件跑文字层, 需要时再算 sha256
  std::atomic<size_t> cursor{0};
  {
    std::vector<std::jthread> pool;
    for (unsigned w = 0; w < workers; ++w)
      pool.emplace_back([&] {
        for (;;) {
          size_t i = cursor.fetch_add(1);
          if (i >= records.size())
            return;
          if (need_hash[i])
            records[i].digest = file_sha256(records[i].path);
          records[i].text = pdf_has_text(records[i].path, SCAN_PAGES);
        }
      });
  }

  // C8 扫描件
  for (Rec &r : records) {
    if (r.text < 0)
      r.viol.push_back("违规:PDF无法解析");
    else if (r.text == 0)
      r.scan.push_back("扫描:无文字层");
  }

  // X5 内容重复 (按 sha256 判定, 即使文件名不同)
  std::unordered_map<std::string, std::vector<size_t>> by_hash;
  for (size_t i = 0; i < records.size(); ++i)
    if (!records[i].digest.empty())
      by_hash[records[i].digest].push_back(i);
  for (const auto &[digest, idxs] : by_hash) {
    if (idxs.size() <= 1)
      continue;
    for (size_t i : idxs) {
      std::string peers;
      for (size_t j : idxs)
        if (j != i) {
          if (!peers.empty())
            peers += " / ";
          peers += records[j].name;
        }
      records[i].viol.push_back(F("违规:内容重复(%s)", peers.c_str()));
    }
  }
}
