// 流水线全部可调参数集中于此. 路径一律相对 ROOT (run.py 所在目录), 不以 / 开头或结尾.
#pragma once

#include <cstddef>

// ---------- 目录布局 ----------
inline constexpr const char *RAW_REPORT_DIR = "resources-raw/report";   // 研报 PDF 输入, 层次 {券商}/{系列}/
inline constexpr const char *PROC_REPORT_DIR = "resources-proc/report"; // 转换产物, 与输入同层次
inline constexpr const char *MINERU_DIR = "cpp/package/MinerU";         // MinerU 源码 (剪裁版)
// 内置便携版 CPython (python-build-standalone, 自带 pip, 不依赖系统 python, 整目录搬迁/换机器直接可用):
//   https://github.com/astral-sh/python-build-standalone/releases
inline constexpr const char *MINERU_PYTHON_DIR = "cpp/package/python";
inline constexpr const char *MINERU_PYTHON_BIN = "cpp/package/python/bin/python3.12";
// MinerU 依赖不用 venv (venv 会把创建时的绝对路径写死进 pyvenv.cfg/activate, 搬迁即失效),
// 改用 pip --target 装到项目内相对目录, 运行时用 PYTHONPATH 指过去 (见 convert.cpp/env.cpp)。
// 注意 pip 会把 MinerU 源码也复制一份进 deps/mineru, PYTHONPATH 必须 MINERU_DIR 在前, deps 在后,
// 否则跑的是 deps 里那份陈旧拷贝, 对 MINERU_DIR 源码的剪裁/修改全部无效
inline constexpr const char *MINERU_DEPS_DIR = "cpp/package/MinerU/deps";

// ---------- stage1 scan: 命名/结构校验 ----------
inline constexpr int SCAN_PAGES = 3; // 扫描件判定只看前几页, 避免整本抽取
inline constexpr int YEAR_MIN = 2000;
inline constexpr int YEAR_MAX = 2030;
inline constexpr size_t BROKER_MINLEN = 4;
inline constexpr size_t BROKER_MAXLEN = 4;
inline constexpr size_t SERIES_MAXLEN = 20;
inline constexpr size_t MAX_NAME_BYTES = 250;
// 该目录下与普通研报同规检查, 仅豁免 X1 的目录==券商/系列比较
inline constexpr const char *TOPIC_DIR = "0主题研报";
inline constexpr const char *WU = "无";

// ---------- stage2 convert: MinerU 转 markdown ----------
inline constexpr const char *MINERU_BACKEND = "pipeline"; // 无 GPU, 只有 pipeline 可用
inline constexpr const char *MINERU_METHOD = "auto";      // auto/txt/ocr; 也决定 MinerU 临时输出子目录名
// 最终产物: PROC_REPORT_DIR/{券商}/{系列}/{stem}/PROC_MD_NAME + images/ (convert.cpp 从 MinerU 固有的
// {stem}/{MINERU_METHOD}/{stem}.md 搬平; 文件名统一, stem 信息已在目录名里)
inline constexpr const char *PROC_MD_NAME = "report.md";
// 每篇完成后写入 {stem}/ 的清单 (源 PDF 大小 + 目录内容清单 + 清单 hash), 是"已完成"的唯一凭据;
// 增量扫描只做 readdir+stat 与清单比对, 不读文件内容, 千篇量级 100ms 内 (见 stat.cpp/check.cpp)
inline constexpr const char *PROC_STAT_NAME = ".stat";
// MinerU 中间产物暂存目录 (PROC_REPORT_DIR 下, 与最终位置同一文件系统, 整篇就绪后 rename 原子换入);
// 启动时无条件清空, 结束时删除, 只有被 kill 才会残留
inline constexpr const char *PROC_STAGING_DIR = ".staging";
inline constexpr const char *MINERU_LANG = "ch";
inline constexpr bool MINERU_FORMULA = true;                      // 关掉可省 1 个模型
inline constexpr bool MINERU_TABLE = true;                        // 关掉可省 4 个模型
inline constexpr const char *MINERU_DEVICE = "cpu";               // 环境变量 MINERU_DEVICE_MODE
inline constexpr const char *MINERU_MODEL_SOURCE = "local";       // 环境变量 MINERU_MODEL_SOURCE, 跑前已校验模型齐备, 不联网
inline constexpr const char *MINERU_FORMULA_CH_SUPPORT = "false"; // 环境变量; true 换用支持中文的 pp_formulanet_plus_m
// 环境变量 MINERU_API_MAX_CONCURRENT_REQUESTS: 本地 mineru-api 同时处理的任务数. MinerU 默认 3, 那是给 GPU
// 的; CPU 上每个任务的 torch 都默认吃满全部核, 3 个并发 = 3 倍线程抢同一批核, 只会更慢, 还把日志交错成一团
inline constexpr const char *MINERU_API_CONCURRENCY = "1";
// 环境变量 MINERU_LOG_LEVEL: loguru + uvicorn (fast_api.py 已改为跟随) 的级别. WARNING = 不刷 INFO 行,
// 终端只剩各模型的 tqdm 进度条 (不受该级别控制) 和 docpipe 自己的进度行
inline constexpr const char *MINERU_LOG_LEVEL = "WARNING";
// 配置文件与模型缓存均改到项目内相对路径 (原版默认在 ~, 通过环境变量
// MINERU_TOOLS_CONFIG_JSON / MODELSCOPE_CACHE 重定向, 见 env.cpp/convert.cpp), 随项目搬迁/换机器可用
inline constexpr const char *MINERU_CONFIG_JSON = "cpp/package/MinerU/mineru.json"; // 由 mineru-models-download 生成
inline constexpr const char *MINERU_MODELS_CACHE_DIR = "cpp/package/MinerU/models"; // 模型缓存 (约 1~2GB)
// models-dir.pipeline 下必须齐备的子路径 (对应 MinerU mineru/utils/enum_class.py ModelPath)
inline constexpr const char *MINERU_PIPELINE_MODELS[] = {
    "models/Layout/PP-DocLayoutV2",
    "models/MFR/unimernet_hf_small_2503",
    "models/MFR/pp_formulanet_plus_m",
    "models/OCR/paddleocr_torch",
    "models/TabRec/SlanetPlus/slanet-plus.onnx",
    "models/TabRec/UnetStructure/unet.onnx",
    "models/TabCls/paddle_table_cls/PP-LCNet_x1_0_table_cls.onnx",
};
