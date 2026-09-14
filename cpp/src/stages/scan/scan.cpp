#include "stages/scan/scan.hpp"

#include <cassert>

#include "common/fs.hpp"

int ScanStage::run(const Ctx &ctx) {
  std::string raw = ctx.root + "/" + RAW_REPORT_DIR;
  assert(is_dir(raw) && "缺少研报输入目录 RAW_REPORT_DIR");

  std::vector<Rec> records;
  std::vector<std::string> dir_viol;

  size_t total = collect_pdfs(raw, records); // 收集 + C1-C7
  check_structure(records, dir_viol);        // X1-X4
  check_content(records, ctx.workers);       // C8 + X5
  size_t n_viol = print_report(raw, total, records, dir_viol);

  return (n_viol || !dir_viol.empty()) ? 1 : 0;
}
