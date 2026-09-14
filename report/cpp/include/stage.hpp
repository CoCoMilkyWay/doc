// 流水线 stage 抽象。
//
// stage1 = scan (文件名/目录规范校验), 后续还会有 mineru 转 markdown、分类等,
// 新增 stage 只需实现本接口并在 src/stages/registry.cpp 中登记。
#pragma once

#include <string>
#include <vector>

// 各 stage 共享的输入参数
struct Ctx {
  std::string root;     // 文档根目录 (report/)
  unsigned workers = 1; // 并行度
};

struct Stage {
  virtual ~Stage() = default;
  virtual const char *name() const = 0;
  // 返回退出码; 非 0 表示该阶段判定不通过, 流水线就此中止 (后续阶段不应在不合规的库上跑)
  virtual int run(const Ctx &ctx) = 0;
};

// 全部已登记的 stage, 顺序即默认执行顺序
const std::vector<Stage *> &all_stages();
// 按名字查找, 未登记返回 nullptr
Stage *find_stage(const std::string &name);
