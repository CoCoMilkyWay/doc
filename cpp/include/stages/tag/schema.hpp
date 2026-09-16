// stage3 tag: 研报标签 schema —— 全部词表 (named enum) 与字段结构的唯一出处. 设计与规则原文见同目录 tag.md.
//
// 设计原则: 能被脚本判对错的字段才存在. 除 Factor.name / Factor.formula / Finding.text / external_ref[] / gen.model
// 五处自由文本外, 其余全是封闭词表或数字. LLM 只做 "从词表里选 + 从原文里逐字摘", 不做写作.
// 词表增删必须 bump config.hpp 的 TAG_SCHEMA_VERSION 并全量重标.
//
// 每个词表用 X-宏 (code, 中文说明[, 附加属性]) 列出一次, NAMED_ENUM 展开为
//   enum class Name { code..., COUNT }  +  Name_code[] (json 里写的字符串就是 code)  +  Name_desc[]
//   +  parse_Name(string_view, Name&)  +  code_of(Name)
// 附加属性 (Module 的所属 PipeStage, Approach 的所属 Module, Stat 的取值域) 另用专用 X-宏展开成并行数组.
//
// 分类骨架 = 我们自己总结的因子流水线 (tag.md §0), 三层:
//   PipeStage (L0~L8) > Module (阶段内按功能步骤 partition) > Approach (模块内的几个范式级流派)
// 资产/股票池/数据/频率/周期是正交轴, 不进模块; 检索 = 取交.
//
// json 形态 (tag.md §2): 顶层 {schema_version id genre asset primary pipe findings builds_on external_ref value gen},
// pipe 的键 = 出现的 PipeStage code, 值 = 该阶段子结构 {module approach [baseline] [setup] [factors]},
// setup 的键集与 factors 的有无由 STAGE_SPEC 给出. 数字型结果只有 L1 的 Factor.stats (策略层数字一律进 findings).
#pragma once

#include <climits>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

// ---------- named enum 机制 ----------
#define NE_ENUM_(c, ...) c,
#define NE_CODE_(c, ...) #c,
#define NE_DESC_(c, d, ...) d,

#define NAMED_ENUM(Name, LIST)                                          \
  enum class Name : uint8_t { LIST(NE_ENUM_) COUNT };                   \
  inline constexpr const char *Name##_code[] = {LIST(NE_CODE_)};        \
  inline constexpr const char *Name##_desc[] = {LIST(NE_DESC_)};        \
  inline const char *code_of(Name v) { return Name##_code[(size_t)v]; } \
  inline bool parse_##Name(std::string_view s, Name &out) {             \
    for (size_t k = 0; k < (size_t)Name::COUNT; ++k)                    \
      if (s == Name##_code[k]) {                                        \
        out = (Name)k;                                                  \
        return true;                                                    \
      }                                                                 \
    return false;                                                       \
  }

// ---------- A. 体裁 ----------
#define GENRE_LIST(X)                    \
  X(framework, "体系搭建 (跨 >=3 阶段)") \
  X(research, "原创研究")                \
  X(handbook, "因子全集测试")            \
  X(review, "综述 / 文献解读 / 教程 (无结果)")
NAMED_ENUM(Genre, GENRE_LIST)

// ---------- B. 正交轴 ----------
#define ASSET_LIST(X)             \
  X(stock_cn, "A 股")             \
  X(stock_hk, "港股")             \
  X(stock_us, "美股")             \
  X(future_index, "股指期货")     \
  X(future_commodity, "商品期货") \
  X(future_bond, "国债期货")      \
  X(bond, "债券")                 \
  X(option, "期权")               \
  X(convertible, "可转债")        \
  X(fund, "基金 / ETF")           \
  X(multi, "大类资产")
NAMED_ENUM(Asset, ASSET_LIST)
// K5: 股票类资产 <=> universe 有意义
inline constexpr Asset STOCK_ASSETS[] = {Asset::stock_cn, Asset::stock_hk, Asset::stock_us};

#define UNIVERSE_LIST(X)                     \
  X(all, "全市场 (所属市场由 Asset 给出)")   \
  X(sse50, "上证50")                         \
  X(csi300, "沪深300")                       \
  X(csi500, "中证500")                       \
  X(csi800, "中证800")                       \
  X(csi1000, "中证1000")                     \
  X(csi2000, "中证2000")                     \
  X(large, "大盘 / 龙头 / 核心资产")         \
  X(micro, "微盘")                           \
  X(dividend, "红利 / 高股息")               \
  X(quality, "高质量 / 优质")                \
  X(growth, "成长 / 创业板 / 科创板 / 北证") \
  X(sector, "单一行业 / 板块 / 主题")        \
  X(hk_connect, "港股通")                    \
  X(other, "其他股票池")                     \
  X(na, "不适用 (非股票)")
NAMED_ENUM(Universe, UNIVERSE_LIST)

#define DATA_SOURCE_LIST(X)                                            \
  X(market_daily, "日频行情 (全部资产, 期货期权也用 market_*)")        \
  X(market_minute, "分钟行情")                                         \
  X(market_l1_l2, "Level-1 快照 / Level-2 逐笔与十档")                 \
  X(statement, "财务报表 / 附注")                                      \
  X(analyst, "分析师: 一致预期 / 评级 / 目标价 / 研报")                \
  X(text, "新闻 / 公告 / 舆情 / 论坛")                                 \
  X(flow, "持仓与资金流: 基金持仓 / 北向 / 两融 / 大宗 / 股东 / 席位") \
  X(alt, "其他另类: 专利 / 供应链 / 地理 / 调研 / ESG")                \
  X(macro, "宏观")                                                     \
  X(none, "无数据 (纯理论 / 综述)")
NAMED_ENUM(DataSource, DATA_SOURCE_LIST)

#define DATA_FREQ_LIST(X)        \
  X(l1, "Level-1 (3s 快照)")     \
  X(l2, "Level-2 (逐笔 / 十档)") \
  X(minute, "分钟")              \
  X(daily, "日")                 \
  X(weekly, "周")                \
  X(monthly, "月")               \
  X(quarterly, "季 (财报)")      \
  X(mixed, "混频")
NAMED_ENUM(DataFreq, DATA_FREQ_LIST)
// K4: 高频(Data) := freq ∈ HF_FREQS ∧ source ∩ HF_SOURCES ≠ ∅; 纯高频频率 (不含 mixed) 必须有高频源
inline constexpr DataFreq HF_FREQS[] = {DataFreq::l1, DataFreq::l2, DataFreq::minute, DataFreq::mixed};
inline constexpr DataFreq HF_FREQS_STRICT[] = {DataFreq::l1, DataFreq::l2, DataFreq::minute};
inline constexpr DataSource HF_SOURCES[] = {DataSource::market_minute, DataSource::market_l1_l2};

// 通用周期: 调仓周期 / 持有期 / 预测期 / 风险预测期 / 因子原始数据周期 都用它
#define PERIOD_LIST(X)                \
  X(second, "高频 (秒级)")            \
  X(intraday, "日内 (分钟级)")        \
  X(daily, "日")                      \
  X(weekly, "周")                     \
  X(monthly, "月")                    \
  X(quarterly, "季 (财报)")           \
  X(event, "事件触发 (低频, 不定期)") \
  X(na, "不适用")
NAMED_ENUM(Period, PERIOD_LIST)

#define FACTOR_FAMILY_LIST(X)                           \
  X(size, "规模")                                       \
  X(value, "估值")                                      \
  X(growth, "成长")                                     \
  X(quality, "质量: 盈利 / 杠杆 / 财报质量 / 无形资产") \
  X(dividend, "红利")                                   \
  X(carry, "期限结构 / 基差")                           \
  X(analyst, "分析师预期 / 修正 / 超预期")              \
  X(momentum, "动量")                                   \
  X(reversal, "反转")                                   \
  X(volatility, "波动率 / 高阶矩")                      \
  X(liquidity, "流动性 / 换手")                         \
  X(microstructure, "订单流 / 订单簿 / 日内结构")       \
  X(sentiment, "文本情绪")                              \
  X(relation, "图关联 / 相似度")                        \
  X(institution, "机构行为 / 持仓 / 资金流")            \
  X(event, "事件因子化")                                \
  X(composite, "机器学习复合因子")                      \
  X(other, "其他")
NAMED_ENUM(FactorFamily, FACTOR_FAMILY_LIST)

#define DIRECTION_LIST(X)               \
  X(positive, "因子值越大未来收益越高") \
  X(negative, "因子值越大未来收益越低") \
  X(nonmonotonic, "非单调")             \
  X(unknown, "文中未明确")
NAMED_ENUM(Direction, DIRECTION_LIST)

// Factor.stats 的位序: 只留能跨研报比较因子的核心指标 (数字只为比较因子, 不为比较策略; alpha 因子只对超额负责),
// 其余数字一律进 findings. 第三/四列: 取值域 [lo, hi] (K2)
#define STAT_LIST(X)                   \
  X(ic, "IC 均值", -1.0, 1.0)          \
  X(rank_ic, "RankIC 均值", -1.0, 1.0) \
  X(icir, "ICIR", -10.0, 10.0)         \
  X(return_ls, "多空组合年化收益", -1.0, 5.0)
#define NE_LO_(c, d, lo, hi) lo,
#define NE_HI_(c, d, lo, hi) hi,
NAMED_ENUM(Stat, STAT_LIST)
inline constexpr double Stat_lo[] = {STAT_LIST(NE_LO_)};
inline constexpr double Stat_hi[] = {STAT_LIST(NE_HI_)};
inline constexpr size_t N_STAT = (size_t)Stat::COUNT; // stats 定长

// 我们对这篇研报的价值判断, 不是标注置信度
#define VALUE_LIST(X)                       \
  X(high, "重要结果: 方法或结论可直接复用") \
  X(medium, "有参考价值: 结论一般或已知")   \
  X(low, "水 / 疑似过拟合或前视 / 结论不可信")
NAMED_ENUM(Value, VALUE_LIST)

// ---------- C. 流水线: PipeStage > Module > Approach ----------
// 阶段 code 即 pipe 对象的键名. 与 stage.hpp 的 Stage 同名冲突, 故叫 PipeStage.
#define STAGE_LIST(X)                                                          \
  X(L0_data, "数据层: 库工程 → 派生加工")                                      \
  X(L1_factor, "因子构造: 按信息源 partition")                                 \
  X(L2_process, "因子处理与检验: 加工→检验→管理")                              \
  X(L3_alpha, "收益预测: 函数形式→训练范式→模型组织")                          \
  X(L4_risk, "风险模型: 因子结构→协方差→尾部")                                 \
  X(L5_portfolio, "组合构建: 权重→摩擦→对冲")                                  \
  X(L6_evaluation, "回测与归因: 阶段对象只有 module/approach")                 \
  X(L7_execution, "交易执行: 代理执行→做市 (只放执行算法, 高频预测信号进 L1)") \
  X(L8_timing, "择时与配置: 截面轮动 vs 时序择时")
NAMED_ENUM(PipeStage, STAGE_LIST)

// 模块: 阶段内的功能 partition, 第三列为所属 PipeStage.
#define MODULE_LIST(X)                                                                    \
  X(L0_warehouse, "数据库工程", L0_data)                                                  \
  X(L0_derivation, "派生数据加工", L0_data)                                               \
  X(L1_fundamental, "财报因子", L1_factor)                                                \
  X(L1_expectation, "分析师预期因子", L1_factor)                                          \
  X(L1_market, "量价因子 (各频率含高频/日内/T0 信号, 频率见 setup.data.freq)", L1_factor) \
  X(L1_alternative, "另类因子: 文本/关系/参与者/事件/属性", L1_factor)                    \
  X(L1_mining, "自动因子挖掘", L1_factor)                                                 \
  X(L2_preprocess, "因子预处理", L2_process)                                              \
  X(L2_single_test, "单因子检验 (检验方法本身是研究对象)", L2_process)                    \
  X(L2_zoo, "因子库管理: 筛选/失效/拥挤", L2_process)                                     \
  X(L3_model, "模型函数形式", L3_alpha)                                                   \
  X(L3_training, "训练范式", L3_alpha)                                                    \
  X(L3_composition, "模型组织: 情景/集成/融合", L3_alpha)                                 \
  X(L4_factor_risk, "因子风险模型", L4_risk)                                              \
  X(L4_covariance, "协方差估计", L4_risk)                                                 \
  X(L4_tail, "尾部/事件/财务风险", L4_risk)                                               \
  X(L5_optimizer, "组合优化: 权重", L5_portfolio)                                         \
  X(L5_cost, "交易摩擦: 成本/换手/容量", L5_portfolio)                                    \
  X(L5_hedge, "对冲与套利", L5_portfolio)                                                 \
  X(L6_backtest, "回测框架与过拟合控制", L6_evaluation)                                   \
  X(L6_attribution, "业绩归因", L6_evaluation)                                            \
  X(L7_algo, "代理执行: 母单拆分", L7_execution)                                          \
  X(L7_making, "做市", L7_execution)                                                      \
  X(L8_rotation, "截面轮动: 因子/风格/行业/资产的相对配置", L8_timing)                    \
  X(L8_timing, "时序择时: 单一标的的方向与仓位", L8_timing)
NAMED_ENUM(Module, MODULE_LIST)
#define NE_MODULE_STAGE_(c, d, s) PipeStage::s,
inline constexpr PipeStage Module_stage[] = {MODULE_LIST(NE_MODULE_STAGE_)};

// 流派: 模块内的范式级做法, 第三列为所属 Module (V3 用). code 全局唯一, 按模块顺序排列.
#define APPROACH_LIST(X)                                                                                    \
  X(point_in_time, "时点库 / 前视 / 增量更新", L0_warehouse)                                                \
  X(taxonomy, "口径与分类: 行业分类 / 市值口径 / 指数复刻", L0_warehouse)                                   \
  X(infrastructure, "平台工具 / 计算加速 / 因子库工程 / 教程", L0_warehouse)                                \
  X(reconstruction, "高频还原与降频: 订单簿还原 / 高频统计量低频化", L0_derivation)                         \
  X(structuring, "非结构化→结构化: 文本抽取 / 关系图 / 持仓资金流整理", L0_derivation)                      \
  X(synthesis, "合成数据: 生成模型 / 增广 / 模拟", L0_derivation)                                           \
  X(style_ratio, "风格比率: 估值/成长/盈利/质量/红利/杠杆, 含学术异象移植", L1_fundamental)                 \
  X(statement_detail, "报表细项: 附注 / 税收 / 研发 / 现金流拆解", L1_fundamental)                          \
  X(accounting_quality, "财报信息质量: 盈余管理 / 应计 / 透明度", L1_fundamental)                           \
  X(expectation_level, "预期水平 / 预期估值", L1_expectation)                                               \
  X(expectation_revision, "预期修正 / 预期动量", L1_expectation)                                            \
  X(earnings_surprise, "超预期 / PEAD", L1_expectation)                                                     \
  X(analyst_behavior, "分析师行为: 覆盖 / 评级 / 目标价 / 金股 / 研报文本", L1_expectation)                 \
  X(momentum_reversal, "动量 / 反转 / 趋势", L1_market)                                                     \
  X(distribution_moment, "收益与成交量的分布: 波动 / 高阶矩 / 尾部 / 筹码", L1_market)                      \
  X(liquidity_turnover, "流动性 / 换手 / 非流动性", L1_market)                                              \
  X(order_flow, "订单流与订单簿: 主动买卖 / 大小单 / 资金流 / 失衡 / 撤单", L1_market)                      \
  X(intraday_pattern, "日内结构: 分时 / 日夜 / 跳跃 / 集合竞价", L1_market)                                 \
  X(technical_pattern, "技术形态与指标: K 线形态 / 海量技术指标", L1_market)                                \
  X(text_sentiment, "文本情绪 / 语义: 新闻 / 公告 / 研报 / 论坛", L1_alternative)                           \
  X(relation_graph, "关系传导: 供应链 / 地理 / 共同覆盖 / 相似度 / 概念", L1_alternative)                   \
  X(participant_behavior, "参与者行为: 机构持仓 / 北向 / 调研 / 股东 / 高管 / 两融 / 大宗", L1_alternative) \
  X(corporate_event, "公司事件: 公告 / 回购 / 定增 / 预告 / 送转", L1_alternative)                          \
  X(firm_attribute, "非财务属性: ESG / 专利 / 治理 / 员工", L1_alternative)                                 \
  X(symbolic_search, "符号搜索: 遗传规划 / 自动特征搜索, 产出公式", L1_mining)                              \
  X(representation_learning, "表示学习: 端到端网络 序列/图/生成式, 产出嵌入", L1_mining)                    \
  X(llm_generation, "语言模型生成: LLM / 多智能体, 产出假设", L1_mining)                                    \
  X(cleaning, "去极值 / 缺失填充 / 标准化", L2_preprocess)                                                  \
  X(neutralization, "中性化 / 正交化: 剔除行业·风格·因子间共线", L2_preprocess)                             \
  X(smoothing, "衰减 / 平滑 / 半衰期 / 频率对齐", L2_preprocess)                                            \
  X(return_test, "收益检验: IC / 分组 / 多空", L2_single_test)                                              \
  X(regression_test, "回归检验: 横截面回归 / 纯因子组合 / 时序相关处理", L2_single_test)                    \
  X(robustness, "稳健性: 分域 / 季节 / 多空不对称 / 参数敏感 / 多重比较", L2_single_test)                   \
  X(selection, "筛选 / 去重 / 降维 / 人工库 vs 机器库", L2_zoo)                                             \
  X(decay_monitor, "失效预警 / 衰减监控 / 动态纠正", L2_zoo)                                                \
  X(crowding, "拥挤度度量与预警", L2_zoo)                                                                   \
  X(weighting, "加权合成: 等权 / IC / ICIR / IC 优化", L3_model)                                            \
  X(linear, "线性回归: 最小二乘 / 收缩回归 / 偏最小二乘", L3_model)                                         \
  X(tree, "树模型: 提升树 / 随机森林", L3_model)                                                            \
  X(neural, "神经网络", L3_model)                                                                           \
  X(label_horizon, "标签设计: 预测期 / 分类 vs 回归 / 排序目标", L3_training)                               \
  X(sample_window, "样本域 / 滚动窗口 / 样本加权", L3_training)                                             \
  X(loss_generalization, "损失与泛化: 损失函数 / 正则 / 多任务 / 蒸馏 / 抗噪", L3_training)                 \
  X(interpretability, "可解释性 / 特征筛选", L3_training)                                                   \
  X(regime_domain, "情景 / 分域: 状态切换 / 风格域 / 行业内建模", L3_composition)                           \
  X(ensemble, "多模型集成: 堆叠 / 模型池 / 多频率", L3_composition)                                         \
  X(fusion, "多源融合: 基本面×量价 / 先验观点 / 事件与因子贝叶斯整合", L3_composition)                      \
  X(structural, "结构化: 预设风格因子, Barra 范式", L4_factor_risk)                                         \
  X(statistical, "统计 / 隐含因子", L4_factor_risk)                                                         \
  X(adaptive, "时变 / 高频 / 时点 / 机器学习风险模型", L4_factor_risk)                                      \
  X(shrinkage, "压缩估计", L4_covariance)                                                                   \
  X(dynamic_adjust, "时变调整: 自相关 / 特征值 / 波动率偏误", L4_covariance)                                \
  X(specific_risk, "特异风险估计", L4_covariance)                                                           \
  X(distress, "财务困境 / 退市 / 负 alpha 剔除", L4_tail)                                                   \
  X(event_risk, "事件型风险", L4_tail)                                                                      \
  X(extreme_dependence, "极端分布: 尾部相关 / 回撤 / Copula", L4_tail)                                      \
  X(mean_variance, "均值方差 / 二次规划及约束体系", L5_optimizer)                                           \
  X(view_blending, "观点融合: Black-Litterman / 熵池", L5_optimizer)                                        \
  X(risk_based, "风险驱动: 风险平价 / 风险预算 / 最大分散 / 分层聚类", L5_optimizer)                        \
  X(heuristic_ranking, "打分排序 / 分层等权", L5_optimizer)                                                 \
  X(learned_solver, "学习式求解: 神经网络 / 端到端组合", L5_optimizer)                                      \
  X(impact, "冲击成本模型", L5_cost)                                                                        \
  X(turnover, "换手 / 调仓频率控制", L5_cost)                                                               \
  X(capacity, "容量 / 规模效应", L5_cost)                                                                   \
  X(futures_hedge, "期货对冲 / 基差 / 套期保值", L5_hedge)                                                  \
  X(option_overlay, "期权叠加: 保护 / 备兑 / 动态对冲 / 波动率交易", L5_hedge)                              \
  X(pairs_arbitrage, "配对 / 统计套利 / 跨品种套利", L5_hedge)                                              \
  X(bias_control, "框架偏差: 前视 / 幸存 / 数据覆盖", L6_backtest)                                          \
  X(overfit_detection, "过拟合: 交叉验证 / 重采样 / 多重检验 / 回测过拟合概率", L6_backtest)                \
  X(evaluation_metric, "业绩评价指标与风险度量", L6_backtest)                                               \
  X(holding_based, "持仓归因, Brinson 范式", L6_attribution)                                                \
  X(factor_based, "因子 / 风险归因, 多期", L6_attribution)                                                  \
  X(return_based, "净值归因 / 风格识别 / 管理人评价", L6_attribution)                                       \
  X(schedule, "时间表算法: 按量 / 按时切分", L7_algo)                                                       \
  X(optimal_execution, "最优执行 / 冲击最小化 / 强化学习执行", L7_algo)                                     \
  X(cost_prediction, "交易成本与滑点预测", L7_algo)                                                         \
  X(quoting, "报价 / 价差: 最优报价模型", L7_making)                                                        \
  X(inventory, "库存与风险控制", L7_making)                                                                 \
  X(adverse_selection, "逆向选择 / 毒性订单流识别", L7_making)                                              \
  X(relative_value, "估值差 / 拥挤度", L8_rotation)                                                         \
  X(relative_momentum, "相对动量 / 均值回复 / ICIR 反转", L8_rotation)                                      \
  X(macro_cycle, "宏观周期 / 景气 / 事件", L8_rotation)                                                     \
  X(ml_rotation, "机器学习 / 文本驱动", L8_rotation)                                                        \
  X(technical_trend, "趋势 / 突破 / 形态 / 技术指标", L8_timing)                                            \
  X(sentiment_flow, "情绪 / 资金流 / 微观结构", L8_timing)                                                  \
  X(macro_valuation, "宏观 / 估值 / 泡沫", L8_timing)                                                       \
  X(ml_timing, "机器学习 / 强化学习", L8_timing)
NAMED_ENUM(Approach, APPROACH_LIST)
#define NE_APPROACH_MODULE_(c, d, m) Module::m,
inline constexpr Module Approach_module[] = {APPROACH_LIST(NE_APPROACH_MODULE_)};

// ---------- D. 各阶段子结构的字段布局 (S1 键集合的唯一出处) ----------
// 阶段对象键 = {module approach} ∪ {baseline | has_baseline} ∪ {setup | 任一 setup 字段} ∪ {factors | factors}
// setup 键 ⊆ {universe data holding risk_factors horizon rebalance}. 没有 result / metrics: 数字只在 L1 的 Factor.stats
struct StageSpec {
  bool baseline, universe, data, holding, risk_factors, horizon, rebalance; // baseline 在阶段对象里, 其余是 setup 字段
  bool factors;                                                             // 阶段对象里的 factors 列表 (只有 L1)
  bool has_setup() const { return universe || data || holding || risk_factors || horizon || rebalance; }
};
inline constexpr StageSpec STAGE_SPEC[(size_t)PipeStage::COUNT] = {
    // baseline universe data  holding risk  horizon rebal  factors
    /*L0*/ {false, false, true, false, false, false, false, false},
    /*L1*/ {false, true, true, true, false, false, false, true},
    /*L2*/ {false, true, false, false, false, false, false, false},
    /*L3*/ {true, true, true, true, false, false, false, false},
    /*L4*/ {false, false, true, false, true, true, false, false},
    /*L5*/ {false, true, false, false, false, false, true, false},
    /*L6*/ {false, false, false, false, false, false, false, false},
    /*L7*/ {false, false, true, false, false, false, false, false},
    /*L8*/ {false, false, false, false, false, false, true, false},
};

// ---------- 输出键序 (F3 格式化用) ----------
// 一个全局序, 使 json 里每个对象的键按它排出来 == 该对象在 tag.md §2 struct 里的字段序 (而不是字母序).
// 同名键 (universe/rebalance/horizon/evidence) 在不同对象里的相对位置互不冲突, 所以一个序够用:
//   顶层   schema_version id genre asset primary pipe findings builds_on external_ref value gen
//   阶段   module approach baseline setup factors        pipe 的阶段键不在表内 => 字节序 = L0..L8
//   setup  universe risk_factors data holding rebalance horizon      Data: source freq      Holding: rebalance horizon
//   Factor name family direction data_period horizon formula stats evidence
//   Finding: text evidence       gen: model prompt_sha256
inline constexpr const char *TAG_KEY_ORDER[] = {
    "schema_version",
    "id",
    "genre",
    "asset",
    "primary",
    "pipe",
    "findings",
    "builds_on",
    "external_ref",
    "value",
    "gen",
    "module",
    "approach",
    "baseline",
    "setup",
    "factors",
    "universe",
    "risk_factors",
    "data",
    "holding",
    "rebalance",
    "name",
    "family",
    "direction",
    "data_period",
    "horizon",
    "formula",
    "stats",
    "source",
    "freq",
    "text",
    "evidence",
    "model",
    "prompt_sha256",
};
inline int tag_key_rank(std::string_view k) {
  for (size_t i = 0; i < sizeof(TAG_KEY_ORDER) / sizeof(*TAG_KEY_ORDER); ++i)
    if (k == TAG_KEY_ORDER[i])
      return (int)i;
  return INT_MAX;
}

// ---------- 解析后的标签 ----------
struct Data {
  std::vector<DataSource> source;
  DataFreq freq;
};
struct Holding {
  Period rebalance, horizon;
};
struct FactorTag {
  std::string name;
  FactorFamily family;
  Direction direction;
  std::vector<Period> data_period;
  Period horizon;
  std::string formula;
  std::string stats[N_STAT]; // 按 Stat 位序的原文 lexeme (K2 转 double 比较, G2 用字面匹配); 空 = null
  std::string evidence;
};
struct StageTag { // 一个阶段子结构; 哪些字段有效由 STAGE_SPEC 决定, 其余保持默认
  std::vector<Module> module;
  std::vector<Approach> approach, baseline;
  std::vector<Universe> universe;
  Data data;
  Holding holding;
  std::vector<FactorFamily> risk_factors;
  Period horizon, rebalance;
  std::vector<FactorTag> factors;
};
struct Finding {
  std::string text, evidence;
};
struct Tag {
  int schema_version = 0;
  std::string id;
  Genre genre;
  std::vector<Asset> asset;
  PipeStage primary;
  std::optional<StageTag> pipe[(size_t)PipeStage::COUNT]; // 有值 = 该阶段出现
  std::vector<Finding> findings;
  std::vector<std::string> builds_on, external_ref;
  Value value;
  struct {
    std::string model, prompt_sha256;
  } gen;
};
