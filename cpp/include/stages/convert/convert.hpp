// stage2 convert: 用 MinerU (pipeline 后端, CPU) 把 RAW_REPORT_DIR 下每个 PDF 转成 markdown。
//
// 输出位置与输入同层次, 每篇一个目录, 文件名统一 (给 agent 用: 只留 md + 图, 无调试产物):
//     RAW_REPORT_DIR/{券商}/{系列}/{stem}.pdf
//  -> PROC_REPORT_DIR/{券商}/{系列}/{stem}/report.md  (+ images/, md 内 ![](images/..) 相对引用)
// MinerU 固有输出是 {stem}/{MINERU_METHOD}/{stem}.md, 跑完由 convert.cpp 上移一层并改名;
// middle/model/content_list json 与 origin/layout/span pdf 已在 package/MinerU/mineru/cli/client.py 关掉.
//
// python 环境不用 venv (venv 会把创建时的绝对路径写死进 pyvenv.cfg/activate/符号链接, 项目搬迁即
// 失效), 改用: 内置便携版 CPython (MINERU_PYTHON_BIN, 不依赖系统 python) + pip --target 把依赖装进
// 项目内相对目录 (MINERU_DEPS_DIR) + 运行时 PYTHONPATH 指过去; 配置文件与模型缓存同理改到项目内
// (MINERU_CONFIG_JSON/MINERU_MODELS_CACHE_DIR, 原版默认写 ~, 用 MINERU_TOOLS_CONFIG_JSON/
// MODELSCOPE_CACHE 环境变量重定向)。全部路径基于 ctx.root 现算, 随项目搬迁/换机器直接可用,
// 见 config.hpp 注释。
//
// 跑前环境校验 (env.cpp), 任一不满足即打印解决办法并断言失败:
//   E1  内置python  MINERU_PYTHON_BIN 存在
//   E2  依赖        MINERU_PYTHON_BIN + PYTHONPATH=MINERU_DEPS_DIR 下可 import mineru/torch/onnxruntime/transformers
//   E3  模型        MINERU_CONFIG_JSON 的 models-dir.pipeline 下 MINERU_PIPELINE_MODELS 全部存在
//
// 完成凭据 (stat.cpp): 每篇就绪后在 {stem}/ 下写 PROC_STAT_NAME, 格式:
//     docpipe-stat 1
//     pdf <源PDF字节数>
//     hash <下面清单行的 sha256>
//     D images                    (目录)
//     F <字节数> report.md        (文件, 含 images/ 下每张图)
//   校验 = 源 PDF 大小对得上 + list_tree 现算清单与文件里的逐行相等. 只 readdir/stat, 不读内容.
//
// 增量扫描 (check.cpp), 每次 convert 先跑, 要求 raw PDF 与 proc 目录一一对应:
//   遍历 proc: 位于 raw 目录层级上的文件 => [多余文件]; 在 raw 无对应 PDF 的目录 => [多余目录];
//   对应的 {stem}/ 目录并行校验清单: 无 .stat / 清单不符 / 源 PDF 大小变了 => [不完整:...]/[源PDF已变].
//   有任何问题项: 树状列出, 问 "删除后继续? [y/N]", 非 y 则退出码 1 什么都不动; y 则删掉问题项.
//   待转换 = raw 中没有完整 {stem}/ 的 PDF (含刚被删的).
//
// 转换 (convert.cpp), 随时被 kill 也不留半成品到最终位置:
//   MinerU CLI 每次调用都要拉起本地服务并加载模型, 故按目录分批: 同一目录的待转 PDF 软链到一个
//   临时目录, 一次 mineru -p <临时目录> -o PROC_STAGING_DIR 调用, 模型每目录只加载一次.
//   每篇跑完: 在暂存区内搬平 (MinerU 的 {stem}/auto/{stem}.md -> {stem}/report.md, images 上移)
//   -> 写 .stat -> rename({stem}) 到最终位置 (同一文件系统, 原子). 暂存区启动时无条件清空.
//   mineru 的 INFO 日志 (loguru/uvicorn) 用 MINERU_LOG_LEVEL=WARNING 压掉, 各模型的 tqdm 进度条保留;
//   docpipe 自己的进度: 每目录一行 (PDF 数/页数/累计 s/页/ETA), 每篇落盘一行 ✓, 目录结束一行完成数与耗时.
//   本地 mineru-api 并发固定为 MINERU_API_CONCURRENCY (CPU 上 1 最快, 见 config.hpp).
//   MinerU 没产出 md 的记失败, 树状列出; 有失败退出码 1。
// 参数见 config.hpp。
#pragma once

#include <string>
#include <vector>

#include "stage.hpp"

struct ConvertStage : Stage {
  const char *name() const override { return "convert"; }
  int run(const Ctx &ctx) override;
};

struct Pdf {
  std::string folder; // 相对 RAW_REPORT_DIR 的目录, 根为 "."
  std::string name, path;
  long long size = 0; // 字节数, 写入 .stat 作为源身份
};

// env.cpp: E1-E3
void check_mineru_env(const std::string &root);

// stat.cpp
void write_stat(const std::string &doc_dir, long long pdf_size);
// 返回 "" 表示完整; 否则为问题标签 (如 "不完整:缺 images/x.webp")
std::string verify_stat(const std::string &doc_dir, long long pdf_size);

// check.cpp: 增量扫描. proc 为 PROC_REPORT_DIR 绝对路径. 待转换 PDF 下标写入 pending (按 pdfs 顺序).
// 有问题项时询问用户; 拒绝删除返回 false (调用方应退出)
bool check_proc(const std::string &proc, const std::vector<Pdf> &pdfs, unsigned workers,
                std::vector<size_t> &pending);
