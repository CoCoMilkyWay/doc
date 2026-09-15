// 流水线 stage 抽象。
//
// stage1 = scan (文件名/目录规范校验), stage2 = convert (MinerU 转 markdown), 后续还会有分类等,
// 新增 stage 只需实现本接口并在 src/stages/registry.cpp 中登记。
#pragma once

#include <string>
#include <vector>

// 各 stage 共享的输入参数
struct Ctx {
  std::string root;              // 文档根目录 (run.py 所在目录), 各 stage 据此拼 config.hpp 里的相对路径
  unsigned workers = 1;          // 并行度
  std::string self;              // 本可执行文件绝对路径 (子进程回调 docpipe 用)
  std::vector<std::string> args; // 本 stage 的命令行参数: 命令行里紧跟 stage 名之后的 --xxx 项, 各 stage 自行解释
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
