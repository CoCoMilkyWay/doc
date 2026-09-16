// stage3 tag: 校验 TAG_REPORT_DIR 下的研报标签 json (由 LLM/agent 逐篇填写), 按券商目录统计进度。
//
// 标签树与 raw/proc 同层次但独立:  RAW_REPORT_DIR/{券商}/{系列}/{stem}.pdf
//                                 PROC_REPORT_DIR/{券商}/{系列}/{stem}/report.md   (接地依据)
//                                 TAG_REPORT_DIR/{券商}/{系列}/{stem}.json          (本 stage 校验对象)
// 期望集合 = raw 全部 PDF (与 convert 同口径). 缺标签只计数不违规 (填充中的正常状态); 违规/多余才退出码 1.
// 本 stage 会写标签树: 格式不规范的 json 原地覆盖为规范格式 (F3), 其余只读.
//
// 两个阶段 + 一个子命令:
//   阶段一 补全   缺失的篮子交给 TAG_AGENT_SCRIPT (智谱 GLM 官方 zai-sdk, 设计见 cpp/agent/agent loop.md): 每篇一段多轮对话,
//                回复里的 json 落 TAG_STAGING_DIR, 用 `docpipe ROOT tag --one <json>` 校验, 违规回喂重问; 通过 rename 进
//                TAG_REPORT_DIR, 用完轮数进 TAG_QUARANTINE_DIR. 无 TAG_AGENT_KEY_FILE 则跳过本阶段
//   阶段二 校验   下面的规则全量跑一遍, 按券商统计
//   --one <json>  只跑单文件规则 (F2-F4 S V K G), 违规一行一条到 stdout, 退出码 0/1; 文件须在 TAG_REPORT_DIR 或 TAG_STAGING_DIR 下.
//                agent loop 把这当落库前的关口 (通过才 rename 进 TAG_REPORT_DIR); X 规则要全库视野, 只在阶段二跑
// 字段与词表见 schema.hpp, 设计与规则原文见 tag.md, 阈值见 config.hpp. 规则按 "越早失败越便宜" 分层,
// 单文件任一条失败即记违规 (文件内继续收集其余违规, 一次打全):
//
// F 文件级 (不读内容)
//   F1  1:1        标签树上每个 .json 必须对应 raw 的某个 PDF (目录+stem 均一致); 非 .json 文件 => [多余]
//   F2  id         json 内 id == 文件名 stem
//   F3  规范格式    文件字节 != json_canonical(归一后的解析结果, tag_key_rank) (键按 schema 字段序, 2 空格缩进, 末尾换行;
//                  小 list/小 dict 单行放得下就单行 (见 json.hpp); 数字 lexeme 归一: 展开指数 / 去前导零与尾零 / -0 → 0;
//                  列表按 S3 的序排序去重) —— 三者都只改写法不改语义
//                  => 覆盖写回, 计 [格式化], 不违规 (LLM 生成的第一版也由此过 formatter); 解析失败才违规
//   F4  接地依据    对应 proc 的 report.md 必须存在 (否则 G 规则无法执行)
// S 结构级
//   S1  键集合      顶层 / pipe (键 ⊆ PipeStage code) / 阶段子结构 / setup / Data / Holding / Factor
//                  / Finding / gen 的键集合恰好等于 schema (STAGE_SPEC 决定各阶段 setup 有哪些键、有无 factors)
//   S2  类型        整数字段归一后不得带小数点; 字符串非空且无首尾空白; Factor.stats 恰好 N_STAT 项, 每项数字或 null
//   S3  列表序      枚举列表按词表顺序、builds_on/external_ref 按字节序严格递增 (=> 去重). 由 F3 就地排序保证,
//                  不作为违规: 排序不改变语义, 而模型实测会把同一个列表在两轮里排成两种相反的顺序, 让它猜不值
//   S4  非空        asset module approach Data.source universe findings 非空; pipe >= 1 个阶段; Factor.name <= TAG_MAX_FACTOR_NAME_CP
//   S5  版本        schema_version == TAG_SCHEMA_VERSION
// V 词表级
//   V1  枚举        所有枚举字段的值 ∈ schema.hpp 词表
//   V2  主阶段      primary ∈ pipe 出现的阶段
//   V3  归属链      阶段 K 下每个 module 属于 K; 每个 approach 所属 module ∈ module; L3.baseline 属于 L3 且与 approach 不交
// K 字段间一致性
//   K1  体裁        framework => 阶段数 >= 3; review => L1.factors 为空; handbook => primary ∈ {L1,L2} 且 L1 出现;
//                  research 且 primary=L1 且 L1.module != [L1_mining] => L1.factors 非空
//   K2  数值域      Factor.stats[i] 非 null => ∈ [Stat_lo[i], Stat_hi[i]]
//   K4  高频        每个 Data: freq ∈ HF_FREQS_STRICT => source ∩ HF_SOURCES ≠ ∅; L7 出现 => 高频(L7.setup.data)
//   K5  资产↔股票池 asset ∩ STOCK_ASSETS = ∅ <=> 每个出现的 setup.universe == [na]
//   K7  自引        builds_on ∌ 自身 id                     (K3 / K6 随 metrics / period 一起删除, 编号不复用)
// G 接地 (anti-hallucination, 对 report.md 归一化后比对: 去空白与 markdown 装饰符 * | #, 全角转半角, ASCII 小写)
//   G1  逐字        每个 evidence 归一化后 >= TAG_EVIDENCE_MIN_CP 码点且为 report.md 子串
//   G2  数字        Factor.stats[i] 的 lexeme (或去符号 / ×100 百分数形式) 出现在 report.md 中 (stats 没有自己的 evidence)
//   G3  因子名      Factor.name 归一化后出现在 report.md 中
//   G4  结论贴合    Finding.text 与其 evidence 的字符 bigram 重合率 >= TAG_FINDING_OVERLAP_MIN
// X 跨文件 (全部单文件通过后)
//   X1  引用        已标注文件间 builds_on 无环 (对不上库内 stem 的项跳过). 不查引用是否存在、不比日期: 文件名的
//                  {日期}-{序号} 是为排序人为规整过的, 与正文自称的对不上, 拿它卡模型抄来的前作只会误报
//   X2  分布        分母 >= TAG_DIST_MIN_N 时: primary 取值 / module 数 >= 3 的阶段内各 module 出现率 / approach 数 >= 3 的
//                  模块内各 approach 出现率, 任一 > TAG_DIST_MAX_SHARE => 库级违规 (LLM 在"默认填"). genre 与二分阶段不查
//   X3  死词表      全部标注完成时 (缺失=0), Module/Approach 中从未被使用的值 => [提示], 不违规
//   X4  串写        两篇的 findings 完全相同 => 双方违规 (LLM 串了上下文)
//
// 输出 (stdout) 三段: 一 进度 (按券商目录, TOPIC_DIR 视为一个券商), 二/三 分布画像 (口径同 X2: 只算已标注且无违规的篇子):
//   resources-tag/report  (共N篇: 已标注a, 缺失b, 违规c, 多余d, 格式化f; 库级问题e)   库级违规只计数不逐条打印 (分布看第二段)
//   ├── [提示:X3 ...]
//   ├── {券商}  (n篇: 标注a 缺失b 违规c 多余d 格式化f)
//   │   └── [违规:F3 ...,违规:G1 ...] {系列}/{stem}
//
//   [按阶段] N篇 ...                          阶段篇数 = 出现该阶段的篇子数 (同 X2 的分母)
//   L1_factor  因子构造  (n篇)                中文类别 = 词表 desc 的冒号前一段, 去空格
//   ├── {approach} {中文类别} {篇数} {系列简写}(该系列有几篇是这个 approach) x3   系列简写 = 券商前2字/系列, 按篇数取前 3
//
//   [因子矩阵] N个因子: 行 data_period × 列 horizon                        格子 = 因子数, 多 data_period 的因子每行各计一次
// 退出码: 违规 / 多余 / 库级违规 任一 > 0 => 1.
#pragma once

#include <string>
#include <vector>

#include "stage.hpp"
#include "stages/tag/schema.hpp"

// ---------- tag: 研报标签 json 校验 ----------
// 词表与字段定义在 stages/tag/schema.hpp (改词表必须 bump 版本并全量重标); 规则见 stages/tag/tag.hpp
// 阈值只留能纠正 LLM 行为的; 列表长度一律不设上限 (S3 严格递增已保证有界, findings 多写无妨)
inline constexpr int TAG_SCHEMA_VERSION = 2;         // 2: 删 result/metrics, Factor 增 data_period/horizon/formula/stats, Period 增 quarterly
inline constexpr size_t TAG_MAX_FACTOR_NAME_CP = 40; // 因子名不是句子 (S4)
// 接地 (G): evidence 归一化后最少码点数; findings.text 与 evidence 的字符 bigram 重合率下限
inline constexpr size_t TAG_EVIDENCE_MIN_CP = 20;
inline constexpr double TAG_FINDING_OVERLAP_MIN = 0.3;
// 跨文件分布检查 (X2): 分母达到该数后才检查; 单一取值占比超过该比例 => 库级违规 (LLM 在"默认填")
inline constexpr size_t TAG_DIST_MIN_N = 50;
inline constexpr double TAG_DIST_MAX_SHARE = 0.6;

struct TagStage : Stage {
  const char *name() const override { return "tag"; }
  int run(const Ctx &ctx) override;
};

// 一篇研报 (以 raw PDF 为准) 的标签状态
struct TagRec {
  std::string folder; // 相对 RAW_REPORT_DIR 的目录 "{券商}/{系列}"
  std::string stem;   // 文件名 stem (五段结构, 由 scan 保证)
  std::string date;   // stem 第一段
  std::string path;   // 标签 json 绝对路径 (tagged 时有效)
  bool tagged = false;
  bool formatted = false;        // F3: 本次被覆盖写回
  std::vector<std::string> viol; // 违规标签, 空 = 通过
  Tag tag;                       // tagged 且结构/词表规则通过后有效
  std::string findings_key;      // X4 用: findings 的规范 json
};

// parse.cpp: F2 F3 S1-S5 V1. text 为 json 文件内容; canon 为规范格式 (解析失败时为空); 违规写入 viol, 返回 tag 是否可用于后续规则
bool parse_tag(const std::string &text, const std::string &stem, Tag &tag, std::string &findings_key, std::string &canon,
               std::vector<std::string> &viol);
// rules.cpp: V2 V3 K1 K2 K4 K5 K7 (不读 report.md) 与 G1-G4 (md 为 report.md 原文)
void check_consistency(const Tag &tag, std::vector<std::string> &viol);
void check_grounding(const Tag &tag, const std::string &md, std::vector<std::string> &viol);
// 接地用文本归一化 (G 规则口径), 暴露出来便于单测/复用
std::string norm_text(const std::string &s);
// env.cpp: 阶段一的环境检查 T1 内置便携 python / T2 zai-sdk; 缺则打印安装指令后断言。
// 顺带把 PYTHONNOUSERSITE / PYTHONPATH 设成 TAG_AGENT_SCRIPT 子进程要用的值
void check_tag_env(const std::string &root);
// cross.cpp: X1 无环 + X2-X4. 库级违规写入 lib_viol, 提示写入 lib_note
void check_cross(std::vector<TagRec> &recs, std::vector<std::string> &lib_viol, std::vector<std::string> &lib_note);
// report.cpp: 按券商统计打印. extra 为 [多余] 项 (folder, name). 返回 违规数+多余数+库级违规数
size_t print_tag_report(const std::vector<TagRec> &recs, const std::vector<std::pair<std::string, std::string>> &extra,
                        const std::vector<std::string> &lib_viol, const std::vector<std::string> &lib_note);
