#include "stages/scan/scan.hpp"

#include <atomic>
#include <thread>
#include <unordered_map>

#include "common/pdftext.hpp"
#include "common/sha256.hpp"
#include "common/util.hpp"

void check_content(std::vector<Rec> &records, unsigned workers) {
  // 并行: 每个文件读一次, 同时算 sha256 与文字层
  std::atomic<size_t> cursor{0};
  {
    std::vector<std::jthread> pool;
    for (unsigned w = 0; w < workers; ++w)
      pool.emplace_back([&] {
        for (;;) {
          size_t i = cursor.fetch_add(1);
          if (i >= records.size())
            return;
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
