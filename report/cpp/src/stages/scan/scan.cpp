#include "stages/scan/scan.hpp"

int ScanStage::run(const Ctx &ctx) {
  std::vector<Rec> records;
  std::vector<std::string> dir_viol;

  size_t total = collect_pdfs(ctx.root, records); // 收集 + C1-C7
  check_structure(records, dir_viol);             // X1-X4
  check_content(records, ctx.workers);            // C8 + X5
  size_t n_viol = print_report(ctx.root, total, records, dir_viol);

  return (n_viol || !dir_viol.empty()) ? 1 : 0;
}
