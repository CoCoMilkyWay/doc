#include "stage.hpp"

#include "stages/scan/scan.hpp"

// 新增 stage: 在此实例化并追加到列表末尾
const std::vector<Stage *> &all_stages() {
  static ScanStage scan;
  static std::vector<Stage *> stages = {&scan};
  return stages;
}

Stage *find_stage(const std::string &name) {
  for (Stage *s : all_stages())
    if (name == s->name())
      return s;
  return nullptr;
}
