// 流水线全部可调参数集中于此. 路径一律相对 ROOT (run.py 所在目录), 不以 / 开头或结尾.
#pragma once

#include <cstddef>
#include <string_view>

// ---------- 目录布局 ----------
inline constexpr const char *RAW_REPORT_DIR = "resources-raw/report";   // 研报 PDF 输入, 层次 {券商}/{系列}/
inline constexpr const char *PROC_REPORT_DIR = "resources-proc/report"; // 转换产物, 与输入同层次
inline constexpr const char *MINERU_DIR = "cpp/package/MinerU";         // MinerU 源码 (剪裁版)
// stage3 tag 的标签 json, 与 PROC_REPORT_DIR 同层次但独立成树: {券商}/{系列}/{stem}.json
// (不能放进 proc 的 {stem}/ 内: .stat 清单是 list_tree 逐行相等, 多一个文件即判 [不完整])
inline constexpr const char *TAG_REPORT_DIR = "resources-tag/report";
// stage3 补全: 缺失的标签先由智谱 GLM (官方 zai-sdk, 对话补全接口 https://docs.bigmodel.cn/cn/api/introduction) 生成 ——
// 静态前缀 (指令+tag.md+示例) 作 system 消息 (吃隐式上下文缓存), report.md 正文随 user 消息发送, 结果 json 从回复文本里取;
// 本机用 docpipe tag --one 校验, 违规原样作为下一条 user 消息回喂同一段对话重问, 全部补完后再整体校验. 见 cpp/agent/agent loop.md
// 以下三个目录/文件都在 TAG_REPORT_DIR 之外 (放进去会被 F1 判多余)
inline constexpr const char *TAG_STAGING_DIR = "resources-tag/.staging";       // agent 产出先落这里, 校验通过才 rename 进 TAG_REPORT_DIR; 启动清空
inline constexpr const char *TAG_QUARANTINE_DIR = "resources-tag/.quarantine"; // 用完轮数仍违规: json + .viol. 存在即不再重试 (删掉即重试)
inline constexpr const char *TAG_AGENT_LOG_DIR = "resources-tag/agent-log";    // 交互全记录 (迭代 prompt 的依据): agent.jsonl 每篇一行汇总;
                                                                               // prefix-{hash}.md 静态前缀 (指令+tag.md+示例) 只存一份;
                                                                               // {folder}/{stem}/meta.json + round-N.{prompt.md,thinking.md,reply.md,viol.txt}
inline constexpr const char *TAG_AGENT_SCRIPT = "cpp/agent/tag_loop.py";       // 用 PYTHON_BIN 跑, 依赖 zai-sdk (装在共享 PYTHON_DEPS_DIR, 见 tag/env.cpp 的 T1/T2)
inline constexpr const char *TAG_AGENT_KEY_FILE = "cpp/agent/glm_api_key.txt"; // 智谱 API key 一行, 形如 {id}.{secret} (已 gitignore; bigmodel.cn 控制台 → API Keys); 不存在则跳过阶段一
inline constexpr const char *TAG_AGENT_MODEL = "glm-5.3-flash";                // 对话补全接口的模型代码 (无 models.list 可预检, 写错首篇即 400/1211 停). 必须在 TAG_AGENT_PRICES 里
// 单价表 (元/百万 tokens: 未命中缓存的输入 / 输出 / 缓存命中), 抄自 https://docs.bigmodel.cn/cn/guide/start/pricing; 缓存存储限时免费, 不计.
// 每一轮费用 = (prompt_tokens - cached_tokens) * in + cached_tokens * hit + completion_tokens * out, 所有型号同一公式
// (reasoning tokens 计在 completion_tokens 里, 见 usage.completion_tokens_details). 平台不回传金额, 这是本地估算, 对账以账单为准.
// glm-5.1 / glm-5 / glm-5-turbo 按输入长度 <32K / >=32K 分档, 不是单一单价, 要用先补分档规则再进表.
// Batch API (5 折) 只支持 GLM-4 系列 (docs.bigmodel.cn/cn/faq/batch-api-issues), GLM-5.x 用不上.
// concurrency = 本账户对该模型的并发上限 (在途请求数), 抄自控制台 → 速率限制 (2026-09-15, 用户权益 V0); 权益等级变了要跟着改.
// 文档不公布各等级数字, 只能看控制台. 开满即可, 超出只会撞 429/1302 背压等待.
struct ModelPrice {
  const char *model;
  double in, out, hit;
  int concurrency;
};
inline constexpr ModelPrice TAG_AGENT_PRICES[] = {
    {"glm-5.2", 8, 28, 2, 10},
    {"glm-5.3", 8, 28, 2, 5},
    {"glm-5.3-flash", 0.8, 2.8, 0.23, 50},
};
consteval ModelPrice tag_agent_price() {
  for (const ModelPrice &p : TAG_AGENT_PRICES)
    if (std::string_view(p.model) == TAG_AGENT_MODEL)
      return p;
  throw "TAG_AGENT_MODEL 不在 TAG_AGENT_PRICES 里"; // consteval 内 throw => 编译期失败
}
inline constexpr ModelPrice TAG_AGENT_PRICE = tag_agent_price();
inline constexpr const char *TAG_AGENT_REASONING_EFFORT = "high";     // 思考强度 (默认 max: 最贵最慢). 各型号可取档位不同 (docs.bigmodel.cn/cn/guide/start/concept-param):
                                                                      //   glm-5.2: none/minimal 不思考, low/medium 都映射成 high, xhigh 映射成 max => 实际只有 不思考/high/max 三档
                                                                      //   glm-5.3 / glm-5.3-flash: 强制思考, low/high/max 三档
                                                                      // 实测 high 首轮 1~1.3 万 reasoning tokens, 占单篇输出费的大头
inline constexpr int TAG_AGENT_WORKERS = TAG_AGENT_PRICE.concurrency; // 同时在飞的请求数 = 账户对该模型的并发上限, 开满. 吞吐 = workers / 单篇耗时
                                                                      // (实测单篇 1.5~4.5 分钟: 4 路约 70 篇/小时, glm-5.2 的 10 路约 170 篇/小时, 1121 篇约 6.5 小时).
                                                                      // GLM-5.x 没有 Batch API 可绕并发; 再快只能换 glm-5.3-flash (并发 50, 单价 1/10)
inline constexpr int TAG_AGENT_MAX_ROUND = 3;                         // 首轮 + 最多 2 次回喂; 用完进 quarantine
inline constexpr size_t TAG_AGENT_MD_MAX_BYTES = 160000;              // report.md 超过则只发前这么多字节 (中位 42KB, p90 73KB)
// ---------- 项目内共享 python (各 stage 共用: convert 跑 MinerU, tag 跑 agent loop) ----------
// 内置便携版 CPython (python-build-standalone, 自带 pip, 不依赖系统 python, 整目录搬迁/换机器直接可用):
//   https://github.com/astral-sh/python-build-standalone/releases
inline constexpr const char *PYTHON_DIR = "cpp/package/python";
inline constexpr const char *PYTHON_BIN = "cpp/package/python/bin/python3.12";
// 依赖不用 venv (venv 会把创建时的绝对路径写死进 pyvenv.cfg/activate, 搬迁即失效), 也不装进 python 自身的
// site-packages (那是 git 跟踪的, 1.6G 依赖不该进版本库), 而是 pip --target 到 python 目录下的 deps/,
// 运行时 PYTHONPATH 指过去 (见 convert/env.cpp, tag/env.cpp)。
// 一个共享 deps, 不按 stage 分: 不同 stage 要的 python 功能不同但 python 是同一个, 分开装只会让公共依赖
// (anyio/httpx/pydantic 这类) 存好几份且各自漂移。代价是各 stage 的包版本互相可见, 所以 —— 增量装一律带
// --upgrade, 不要整目录 rm -rf (会连别的 stage 的包一起删); 装出来的版本能不能用, 由各 stage 跑前自己的
// 环境检查负责 (convert E2 import mineru/torch/..., tag T2 查 zai 接口), 冲突当场失败而不是半路崩。
// 注意 pip 会把 MinerU 源码也复制一份进 deps/mineru, convert 的 PYTHONPATH 必须 MINERU_DIR 在前, deps 在后,
// 否则跑的是 deps 里那份陈旧拷贝, 对 MINERU_DIR 源码的剪裁/修改全部无效
inline constexpr const char *PYTHON_DEPS_DIR = "cpp/package/python/deps";

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
inline constexpr const char *MINERU_BACKEND = "pipeline"; // vlm 后端另需 [vlm] 依赖与 VLM 模型, 未纳入
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
inline constexpr bool MINERU_FORMULA = true; // 关掉可省 1 个模型
inline constexpr bool MINERU_TABLE = true;   // 关掉可省 4 个模型
// 环境变量 MINERU_DEVICE_MODE. "auto" = 由 env.cpp 跑一次 torch.cuda.is_available() 探测, 有卡用 cuda
// 无卡用 cpu (CPU/GPU 通用: 同一份代码换机器不用改); 也可写死 "cpu"/"cuda" 强制指定, 跳过探测
inline constexpr const char *MINERU_DEVICE = "auto";
inline constexpr const char *MINERU_MODEL_SOURCE = "local";       // 环境变量 MINERU_MODEL_SOURCE, 跑前已校验模型齐备, 不联网
// 环境变量; false 用 unimernet_hf_small_2503 (纯英文/LaTeX 训练), 中文研报里"公式+中文变量说明"混排的
// 行会被整行判成公式, 中文全被猜成最接近的 LaTeX 符号 (\dot{\eta}\dot{\pi}... 一类乱码), 故换用
// 支持中文的 pp_formulanet_plus_m
inline constexpr const char *MINERU_FORMULA_CH_SUPPORT = "true";
// 环境变量 MINERU_API_MAX_CONCURRENT_REQUESTS: 本地 mineru-api 同时处理的任务数. MinerU 默认 3, 那是给 GPU
// 的; CPU 上每个任务的 torch 都默认吃满全部核, 3 个并发 = 3 倍线程抢同一批核, 只会更慢, 还把日志交错成一团.
// GPU 下暂时也保持 1: 并发数受显存约束 (每个任务一份模型权重), 调高前先看实测显存占用
inline constexpr const char *MINERU_API_CONCURRENCY = "1";
// 并行 mineru 子进程数 (每个领一个目录). 0 = 自动: cuda 且显存够放两份 (≥6GB) 开 2 个, 否则 1 ——
// 实测单进程 GPU 利用率仅 20%~80% 波动 (流水线里页面渲染/Processing pages/写盘等纯 CPU 阶段 GPU
// 干等), 两个进程错峰互补即接近打满, 再多收益骤减还挤显存; CPU 模式恒 1 (torch 单进程已吃满全部核).
// 也可写死正整数 (显存自己负责). 多进程时各 mineru 的 stderr (tqdm 进度条) 重定向到临时日志防交错,
// 进度看 docpipe 的 ✓ 行. 每进程批量由 MINERU_VIRTUAL_VRAM_SIZE 按显存份额自动定, 见 convert.cpp
inline constexpr int MINERU_WORKERS = 0;
// 环境变量 MINERU_LOG_LEVEL: loguru + uvicorn (fast_api.py 已改为跟随) 的级别. WARNING = 不刷 INFO 行,
// 终端只剩各模型的 tqdm 进度条 (不受该级别控制) 和 docpipe 自己的进度行
inline constexpr const char *MINERU_LOG_LEVEL = "WARNING";
// 环境变量 DOCPIPE_IMG_MAX_WIDTH / DOCPIPE_IMG_QUALITY: 插图落盘参数 (MinerU pdf_image_tools.py::cut_image 读取).
// MinerU 原版是 200dpi 页面截图 + PIL 默认 JPEG(q75), 且对 table/equation 也截图落盘, 而 md 里表格是 <table>
// html、公式是 LaTeX, 那些截图从不被引用 (实测占 images/ 一半以上字节, 由 cli/common.py 在写完 md 后删掉)。
// 被引用的插图改为 WebP + 限宽: 视觉模型输入本就会缩到 ~1000px 量级, 限宽不丢信息; 图表类图 WebP 比 JPEG
// 同质量小一半以上。抽样实测 (120 张) 相对原版: WebP q75 限宽 1000 ≈ 37%, 叠加删孤儿图后整体约 1/10
inline constexpr const char *IMG_MAX_WIDTH = "1000"; // 像素; 宽超过则等比缩到该宽度
inline constexpr const char *IMG_QUALITY = "75";     // WebP 有损质量 0~100
// 环境变量 DOCPIPE_IMG_MIN_SIDE_PT: 图/图表 bbox 短边 (PDF 点, 1pt=1/72in) 小于此值的不落盘也不进 md —— 实测这些全是
// 电话/邮箱/微信 logo 一类图标 (~15pt), 真正的图表短边都在 100pt 以上. 公式与表格截图不受此限
inline constexpr const char *IMG_MIN_SIDE_PT = "36";
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
