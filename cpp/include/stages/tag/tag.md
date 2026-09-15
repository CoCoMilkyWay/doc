## 0. 划分原则

```
骨架   = 我们自己的因子流水线 L0~L8. 标签回答的是 "这篇解决流水线哪一步的什么问题", 不是 "这篇用了什么技术".
Module = 阶段内按功能步骤 partition: 互斥·完备·同一切法 (L2 = 加工→检验→管理, L4 = 因子结构→协方差→尾部, L5 = 权重→摩擦→对冲).
Approach = 模块内的几个流派 (范式级, 3~6 个), 不列实现 (不出现 GRU/Lasso/CNE6/CSCV 这类名字; Barra/Black-Litterman/Brinson 是范式名可用).
正交轴 = 资产/股票池/数据/频率/周期, 一律不进模块: 高频/日内/T0 预测因子 = L1_market ∧ freq∈高频 (L7 只放执行算法与做市), CTA 截面因子 = L1_market ∧ asset=future_commodity,
         期货趋势策略 = L8_timing ∧ asset=future_index, 港股 = asset=stock_hk, 红利 = L1_fundamental ∧ family=dividend. 检索 = 取交.
完备性 = 每篇必有落点: 工具/平台/加速 → L0_warehouse/infrastructure; 合成数据 → L0_derivation/synthesis; 对冲/套利/期权策略 → L5_hedge;
         时序 vs 截面 由 L8_timing / L8_rotation 区分. 词表增删 = fit 某几篇 ⇒ 拒绝; 只在 "某模块缺一个公认流派" 时改.
```

## 1. 词表 (13 个 enum, `Tag` 之外只有它们)

层次链 PipeStage(9) > Module(25) > Approach(87), 归属由并行数组 Module_stage[] / Approach_module[] 给出, 取值见 §2 各阶段注释. 其余 10 个为正交轴:

```
Genre         framework        体系搭建 (跨 ≥3 阶段)
              research         原创研究
              handbook         因子全集测试
              review           综述 / 文献解读 / 教程 (无结果)

Asset         stock_cn         A 股
              stock_hk         港股
              stock_us         美股
              future_index     股指期货
              future_commodity 商品期货
              future_bond      国债期货
              bond             债券
              option           期权
              convertible      可转债
              fund             基金 / ETF
              multi            大类资产

Universe      all              全市场 (所属市场由 Asset 给出)
              sse50            上证50                                       指数
              csi300           沪深300
              csi500           中证500
              csi800           中证800
              csi1000          中证1000
              csi2000          中证2000
              large            大盘 / 龙头 / 核心资产                       风格
              micro            微盘
              dividend         红利 / 高股息
              quality          高质量 / 优质
              growth           成长 / 创业板 / 科创板 / 北证
              sector           单一行业 / 板块 / 主题                       其他
              hk_connect       港股通
              other            其他股票池
              na               不适用 (非股票)

DataSource    market_daily     日频行情 (全部资产, 期货期权也用 market_*)
              market_minute    分钟行情
              market_l1_l2     Level-1 快照 / Level-2 逐笔与十档
              statement        财务报表 / 附注
              analyst          分析师: 一致预期 / 评级 / 目标价 / 研报
              text             新闻 / 公告 / 舆情 / 论坛
              flow             持仓与资金流: 基金持仓 / 北向 / 两融 / 大宗 / 股东 / 席位
              alt              其他另类: 专利 / 供应链 / 地理 / 调研 / ESG
              macro            宏观
              none             无数据 (纯理论 / 综述)

DataFreq      l2               Level-2 (逐笔 / 十档)
              l1               Level-1 (3s 快照)
              minute           分钟
              daily            日
              weekly           周
              monthly          月
              quarterly        季 (财报)
              mixed            混频

Period        second           高频 (秒级)                    通用周期: 调仓周期 / 持有期 / 预测期 / 风险预测期 都用它
              intraday         日内 (分钟级)
              daily            日
              weekly           周
              monthly          月
              event            事件触发 (低频, 不定期)
              na               不适用

FactorFamily  size             规模
              value            估值
              growth           成长
              quality          质量: 盈利 / 杠杆 / 财报质量 / 无形资产
              dividend         红利
              carry            期限结构 / 基差
              analyst          分析师预期 / 修正 / 超预期
              momentum         动量
              reversal         反转
              volatility       波动率 / 高阶矩
              liquidity        流动性 / 换手
              microstructure   订单流 / 订单簿 / 日内结构
              sentiment        文本情绪
              relation         图关联 / 相似度
              institution      机构行为 / 持仓 / 资金流
              event            事件因子化
              composite        机器学习复合因子
              other            其他

Direction     positive         因子值越大未来收益越高
              negative         因子值越大未来收益越低
              nonmonotonic     非单调
              unknown          文中未明确

MetricKind    ic               IC 均值                    [-1, 1]        因子预测力      只留能跨研报标准化比较的核心指标,
              rank_ic          RankIC 均值                [-1, 1]                        其余数字 (t 值/胜率/夏普/滑点/偏差统计量...)
              icir             ICIR                       [-10, 10]                      一律写进 findings, 不强行结构化
              return_ls        多空组合年化收益           [-1, 5]        因子收益
              excess_annual    组合年化超额               [-1, 3]        组合表现
              ir               信息比率                   [-10, 20]
              drawdown         最大回撤 (正数)            [0, 1]
              turnover         换手率                     [0, 100]

Value         high             重要结果: 方法或结论可直接复用            我们对这篇研报的价值判断, 不是标注置信度
              medium           有参考价值: 结论一般或已知
              low              有水分 / 疑似过拟合或前视 / 结论不可信
```

## 2. 结构 (注释 = 这是什么 | 允许取值 | 适用规则; 检查内容一律见 §3)

```cpp
struct Tag {
  // ---- 头: 这篇是什么 ----
  int            schema_version;     // 词表版本, 恒 == TAG_SCHEMA_VERSION  | S2 S5
  string         id;                 // 文件名 stem  | S2 F2
  Genre          genre;              // 体裁: framework research handbook review  | V1 K1
  vector<Asset>  asset;              // 资产, 只在这里 (CTA/期权/港股/基金靠它区分, 不进模块): Asset 词表  | V1 S3 S4 K5
  PipeStage      primary;            // 主阶段: L0_data L1_factor L2_process L3_alpha L4_risk L5_portfolio
                                     //         L6_evaluation L7_execution L8_timing  | V1 V2

  // ---- 流水线: 每阶段一个子结构, 键名 = PipeStage code. 出现 = 本文涉及该阶段; 不出现 = 未涉及 ----
  struct Pipe {
    // 跨阶段共用的小结构
    struct Data {                    // 用了什么数据 (L0 L1 L3 L4 L7)
      vector<DataSource> source;     // DataSource 词表  | V1 S3 S4 K4
      DataFreq           freq;       // DataFreq 词表  | V1 K4
    };
    struct Holding {                 // 调仓周期 + 预测/持有期 (L1 L3)
      Period rebalance;              // Period 词表  | V1
      Period horizon;                // Period 词表  | V1
    };
    struct Metric {                  // 一个数字型结果, 无股票池概念 (L4 L8)
      MetricKind kind;               // MetricKind 词表, 各阶段允许子集见该阶段 result 注释  | V1 K3
      number     value;              // 原文数字  | S2 K2 G2
      [ym, ym]   period;             // 统计区间, [] 或 ["YYYY-MM","YYYY-MM"]  | S2 K6
      string     evidence;           // 原文摘录  | S2 G1
    };
    struct PoolMetric : Metric {     // 带股票池的结果 (L1 L2 L3 L5)
      Universe   universe;           // Universe 词表  | V1 K3
    };

    struct L0 {                                                                       // 数据层: 库工程 → 派生加工
      vector<Module>   module;       // L0_warehouse L0_derivation  | V1 S3 S4 V3
      vector<Approach> approach;     // L0_warehouse:  point_in_time  (时点库/前视/增量更新)
                                     //                taxonomy       (口径与分类: 行业分类/市值口径/指数复刻)
                                     //                infrastructure (平台工具/计算加速/因子库工程/教程)
                                     // L0_derivation: reconstruction (高频还原与降频: 订单簿还原/高频统计量低频化)
                                     //                structuring    (非结构化→结构化: 文本抽取/关系图/持仓资金流整理)
                                     //                synthesis      (合成数据: 生成模型/增广/模拟)  | V1 S3 S4 V3
      struct { Data data; } setup;   // | S1 K4
    } L0_data;

    struct L1 {                                                                       // 因子构造: 按信息源 partition, 机器挖掘单列
      struct Factor {                // 本文新提出/重构的一个因子 (只有 L1 产出因子)
        string       name;           // 因子名  | S2 S4 G3
        FactorFamily family;         // 风格桶: FactorFamily 词表  | V1
        Direction    direction;      // positive negative nonmonotonic unknown  | V1
        string       evidence;       // 原文摘录  | S2 G1
      };
      vector<Module>   module;       // L1_fundamental L1_expectation L1_market L1_alternative L1_mining | V1 S3 S4 V3
      vector<Approach> approach;     // L1_fundamental: style_ratio             (风格比率: 估值/成长/盈利/质量/红利/杠杆, 含学术异象移植)
                                     //                 statement_detail        (报表细项: 附注/税收/研发/现金流拆解)
                                     //                 accounting_quality      (财报信息质量: 盈余管理/应计/透明度)
                                     // L1_expectation: expectation_level       (预期水平/预期估值)
                                     //                 expectation_revision    (预期修正/预期动量)
                                     //                 earnings_surprise       (超预期/PEAD)
                                     //                 analyst_behavior        (分析师行为: 覆盖/评级/目标价/金股/研报文本)
                                     // L1_market:      momentum_reversal       (动量/反转/高频)             频率不进模块, 见 setup.data.
                                     //                 distribution_moment     (收益与成交量的分布: 波动/高阶矩/尾部/筹码)
                                     //                 liquidity_turnover      (流动性/换手/非流动性)
                                     //                 order_flow              (订单流与订单簿: 主动买卖/大小单/资金流/失衡/撤单)
                                     //                 intraday_pattern        (日内结构: 分时/日夜/跳跃/集合竞价)
                                     //                 technical_pattern       (技术形态与指标: K 线形态/海量技术指标)
                                     // L1_alternative: text_sentiment          (文本情绪/语义: 新闻/公告/研报/论坛)
                                     //                 relation_graph          (关系传导: 供应链/地理/共同覆盖/相似度/概念)
                                     //                 participant_behavior    (参与者行为: 机构持仓/北向/调研/股东/高管/两融/大宗)
                                     //                 corporate_event         (公司事件: 公告/回购/定增/预告/送转)
                                     //                 firm_attribute          (非财务属性: ESG/专利/治理/员工)
                                     // L1_mining:      symbolic_search         (符号搜索: 遗传规划/自动特征搜索, 产出公式)
                                     //                 representation_learning (表示学习: 端到端网络 序列/图/生成式, 产出嵌入)
                                     //                 llm_generation          (语言模型生成: LLM/多智能体, 产出假设)  | V1 S3 S4 V3
      struct {
        vector<Universe> universe;   // 检验股票池: Universe 词表  | V1 S3 S4 K5
        Data             data;       // | S1 K4
        Holding          holding;    // | S1
      } setup;
      struct {
        vector<Factor>     factors;  // | S1 K1
        vector<PoolMetric> metrics;  // kind ⊆ {ic rank_ic icir return_ls turnover}  | S1 K3
      } result;
    } L1_factor;

    struct L2 {                                                                       // 因子处理与检验: 加工 → 检验 → 管理
                                     // 出现条件: 处理/检验/管理方法本身是研究对象. 因子研报例行的 IC/分组不进 L2 (否则 L2 被稀释)
      vector<Module>   module;       // L2_preprocess L2_single_test L2_zoo  | V1 S3 S4 V3
      vector<Approach> approach;     // L2_preprocess:   cleaning        (去极值/缺失填充/标准化)
                                     //                  neutralization  (中性化/正交化: 剔除行业·风格·因子间共线)
                                     //                  smoothing       (衰减/平滑/半衰期/频率对齐)
                                     // L2_single_test:  return_test     (收益检验: IC/分组/多空)
                                     //                  regression_test (回归检验: 横截面回归/纯因子组合/时序相关处理)
                                     //                  robustness      (稳健性: 分域/季节/多空不对称/参数敏感/多重比较)
                                     // L2_zoo:          selection       (筛选/去重/降维/人工库 vs 机器库)
                                     //                  decay_monitor   (失效预警/衰减监控/动态纠正)
                                     //                  crowding        (拥挤度度量与预警)  | V1 S3 S4 V3
      struct { vector<Universe> universe; } setup;                                    // | S1 V1 S3 S4 K5
      struct { vector<PoolMetric> metrics; } result;   // kind ⊆ {ic rank_ic icir return_ls turnover}; 前后对比 = 两条同 kind | S1 K3
    } L2_process;

    struct L3 {                                                                       // 收益预测 (Alpha 模型): 函数形式 → 训练范式 → 模型组织
      vector<Module>   module;       // L3_model L3_training L3_composition  | V1 S3 S4 V3
      vector<Approach> approach;     // 主方法.  L3_model:       weighting           (加权合成: 等权/IC/ICIR/IC 优化)
                                     //                          linear              (线性回归: 最小二乘/收缩回归/偏最小二乘)
                                     //                          tree                (树模型: 提升树/随机森林)
                                     //                          neural              (神经网络)
                                     //          L3_training:    label_horizon       (标签设计: 预测期/分类 vs 回归/排序目标)
                                     //                          sample_window       (样本域/滚动窗口/样本加权)
                                     //                          loss_generalization (损失与泛化: 损失函数/正则/多任务/蒸馏/抗噪)
                                     //                          interpretability    (可解释性/特征筛选)
                                     //          L3_composition: regime_domain       (情景/分域: 状态切换/风格域/行业内建模)
                                     //                          ensemble            (多模型集成: 堆叠/模型池/多频率)
                                     //                          fusion              (多源融合: 基本面×量价/先验观点/事件与因子贝叶斯整合)  | V1 S3 S4 V3
      vector<Approach> baseline;     // 对照组: 同上 L3_* 任一流派 (只有 L3 有对照组字段, 其他阶段的对照进 findings)  | V1 S3 V3
      struct { vector<Universe> universe; Data data; Holding holding; } setup;        // | S1 V1 S3 S4 K4 K5
      struct { vector<PoolMetric> metrics; } result;   // kind ⊆ {ic rank_ic icir excess_annual ir drawdown turnover} | S1 K3
    } L3_alpha;

    struct L4 {                                                                       // 风险模型: 因子结构 → 协方差估计 → 尾部
      vector<Module>   module;       // L4_factor_risk L4_covariance L4_tail  | V1 S3 S4 V3
      vector<Approach> approach;     // L4_factor_risk: structural         (结构化: 预设风格因子, Barra 范式)
                                     //                 statistical        (统计/隐含因子)
                                     //                 adaptive           (时变/高频/时点/机器学习风险模型)
                                     // L4_covariance:  shrinkage          (压缩估计)
                                     //                 dynamic_adjust     (时变调整: 自相关/特征值/波动率偏误)
                                     //                 specific_risk      (特异风险估计)
                                     // L4_tail:        distress           (财务困境/退市/负 alpha 剔除)
                                     //                 event_risk         (事件型风险)
                                     //                 extreme_dependence (极端分布: 尾部相关/回撤/Copula)  | V1 S3 S4 V3
      struct {
        vector<FactorFamily> risk_factors;   // 模型含的风格因子集: FactorFamily 词表  | V1 S3
        Data                 data;           // | S1
        Period               horizon;        // 风险预测期: Period 词表  | V1
      } setup;
      struct { vector<Metric> metrics; } result;       // kind ⊆ {excess_annual ir drawdown}  | S1 K3
    } L4_risk;

    struct L5 {                                                                       // 组合构建: 权重 → 摩擦 → 对冲
      vector<Module>   module;       // L5_optimizer L5_cost L5_hedge  | V1 S3 S4 V3
      vector<Approach> approach;     // L5_optimizer: mean_variance     (均值方差/二次规划及约束体系)
                                     //               view_blending     (观点融合: Black-Litterman/熵池)
                                     //               risk_based        (风险驱动: 风险平价/风险预算/最大分散/分层聚类)
                                     //               heuristic_ranking (打分排序/分层等权)
                                     //               learned_solver    (学习式求解: 神经网络/端到端组合)
                                     // L5_cost:      impact            (冲击成本模型)
                                     //               turnover          (换手/调仓频率控制)
                                     //               capacity          (容量/规模效应)
                                     // L5_hedge:     futures_hedge     (期货对冲/基差/套期保值)
                                     //               option_overlay    (期权叠加: 保护/备兑/动态对冲/波动率交易)
                                     //               pairs_arbitrage   (配对/统计套利/跨品种套利)  | V1 S3 S4 V3
      struct {
        vector<Universe> universe;   // 基准: Universe 词表  | V1 S3 S4 K5
        Period           rebalance;  // Period 词表  | V1
      } setup;
      struct { vector<PoolMetric> metrics; } result;   // kind ⊆ {excess_annual ir drawdown turnover} | S1 K3
    } L5_portfolio;

    struct L6 {                                                                       // 回测与归因 (产出是方法, 无 setup/result; 归因里的数字进 findings)
      vector<Module>   module;       // L6_backtest L6_attribution  | V1 S3 S4 V3
      vector<Approach> approach;     // L6_backtest:    bias_control      (框架偏差: 前视/幸存/数据覆盖)
                                     //                 overfit_detection (过拟合: 交叉验证/重采样/多重检验/回测过拟合概率)
                                     //                 evaluation_metric (业绩评价指标与风险度量)
                                     // L6_attribution: holding_based     (持仓归因, Brinson 范式)
                                     //                 factor_based      (因子/风险归因, 多期)
                                     //                 return_based      (净值归因/风格识别/管理人评价)  | V1 S3 S4 V3
    } L6_evaluation;

    struct L7 {                                                                       // 交易执行: 代理执行 → 做市. 只放性质与预测因子不同的算法;
      vector<Module>   module;       // L7_algo L7_making  | V1 S3 S4 V3
      vector<Approach> approach;     // L7_algo:   schedule          (时间表算法: 按量/按时切分)
                                     //            optimal_execution (最优执行/冲击最小化/强化学习执行)
                                     //            cost_prediction   (交易成本与滑点预测)
                                     // L7_making: quoting           (报价/价差: 最优报价模型)
                                     //            inventory         (库存与风险控制)
                                     //            adverse_selection (逆向选择/毒性订单流识别)  | V1 S3 S4 V3
      struct { Data data; } setup;   // | S1 K4
    } L7_execution;

    struct L8 {                                                                       // 择时与配置 (横切): 截面轮动 vs 时序择时, 流派 = 信号来源, 两边对仗
      vector<Module>   module;       // L8_rotation L8_timing  | V1 S3 S4 V3
      vector<Approach> approach;     // L8_rotation (截面: 因子/风格/行业/资产/ETF 的相对配置)
                                     //              relative_value    (估值差/拥挤度)
                                     //              relative_momentum (相对动量/均值回复/ICIR 反转)
                                     //              macro_cycle       (宏观周期/景气/事件)
                                     //              ml_rotation       (机器学习/文本驱动)
                                     // L8_timing   (时序: 单一标的的方向与仓位: 大盘/期指/商品/ETF)
                                     //              technical_trend   (趋势/突破/形态/技术指标)
                                     //              sentiment_flow    (情绪/资金流/微观结构)
                                     //              macro_valuation   (宏观/估值/泡沫)
                                     //              ml_timing         (机器学习/强化学习)  | V1 S3 S4 V3
      struct { Period rebalance; } setup;              // Period 词表  | S1 V1
      struct { vector<Metric> metrics; } result;       // kind ⊆ {excess_annual ir drawdown}  | S1 K3
    } L8_timing;
  } pipe;                            // | S1 S4 V2 K1

  // ---- 结论与引用 ----
  struct Finding {                   // 一条核心结论
    string text;                     // 结论 (自由文本, 不限长)  | S2 G4
    string evidence;                 // 原文摘录  | S2 G1
  };
  vector<Finding> findings;          // | S1 S4 X4
  vector<string>  builds_on;         // 本库内被引研报的 stem  | S2 S3 K7 X1
  vector<string>  external_ref;      // 库外引用短文本  | S2 S3
  Value           value;             // 价值判断: high medium low  | V1
  struct {                           // 生成元数据
    string     model;                // 生成模型名  | S2
    string     prompt_sha256;        // prompt 的 sha256  | S2
  } gen;
};
```

子结构定义在使用它的层级内: 只被一个阶段用的 (`Factor`) 在该阶段, 跨阶段共用的 (`Data` `Holding` `Metric` `PoolMetric`) 在 `Pipe` 顶部, `Finding`/`gen` 在 `Tag`. `Tag` 之外只有 §1 的 13 个 enum.

json 形态 (国盛-002 Lasso 收益预测, 示意):

```jsonc
{
  "schema_version": 1, "id": "...", "genre": "research", "asset": ["stock_cn"], "primary": "L3_alpha",
  "pipe": {
    "L2_process": { "module": ["L2_zoo"], "approach": ["selection"],
                    "setup": { "universe": ["all"] }, "result": { "metrics": [] } },
    "L3_alpha":   { "module": ["L3_model", "L3_composition"],
                    "approach": ["linear", "regime_domain"], "baseline": ["weighting"],
                    "setup": { "universe": ["all", "csi500"], "data": { "source": ["market_daily", "statement"], "freq": "daily" },
                               "holding": { "rebalance": "monthly", "horizon": "monthly" } },
                    "result": { "metrics": [ { "kind": "ic", "value": 0.097, "universe": "all", "period": [], "evidence": "..." } ] } },
    "L5_portfolio": { "module": ["L5_optimizer"], "approach": ["mean_variance"],
                      "setup": { "universe": ["csi500"], "rebalance": "monthly" },
                      "result": { "metrics": [ { "kind": "excess_annual", "value": 0.165, "universe": "csi500", "period": [], "evidence": "..." } ] } }
  },
  "findings": [ ... ], "builds_on": [ "...-001-..." ], "external_ref": [ "Taming the Factor Zoo" ], "value": "high", "gen": { ... }
}
```

## 3. 规则总表 (cpp 按此实现; 越早失败越便宜, 单文件任一条失败即违规, 文件内继续收集其余违规一次打全)

阈值常量 (config.hpp, 只留能纠正 LLM 行为的; 列表长度一律不设上限, S3 严格递增已保证有界): `TAG_SCHEMA_VERSION` `TAG_MAX_FACTOR_NAME_CP=40` (因子名不是句子) `TAG_EVIDENCE_MIN_CP=20` `TAG_FINDING_OVERLAP_MIN=0.3` `TAG_DIST_MIN_N=50` `TAG_DIST_MAX_SHARE=0.6`

```
F 文件级 (不读内容)
  F1 对应    标签树每个 .json 的 {目录}/{stem} 必须 == raw 某 PDF 的 {目录}/{stem}; 对不上或非 .json ⇒ [多余]
  F2 id      id == 文件名 stem
  F3 规范    canonical(解析结果) := 键按 schema 字段序 (schema.hpp TAG_KEY_ORDER, 不是字母序), 2 空格缩进, 数字保留原文, 非 ASCII 原样, 末尾换行
            文件字节 != canonical ⇒ 原地覆盖写回, 计 [格式化], 不违规 (LLM 第一版也由此过 formatter); json 解析失败 (含重复键) 才违规
  F4 依据    对应 proc 的 report.md 必须存在 (否则 G 无法执行)

S 结构级
  S1 键集合  每个对象的键集合恰好 == 其 struct 的字段集合, 多键少键皆违规. 适用于: 顶层 / pipe (键 ⊆ 9 个 PipeStage code)
            / 每个出现的阶段子结构 / setup / result / Data / Holding / Metric / PoolMetric / Factor / Finding / gen
  S2 类型    int: -?(0|[1-9]\d*), 无小数点/指数        number: 上式 + 可选 (\.\d*[1-9]), 无尾零, 无 -0
            string: 非空, 首尾无 ASCII 空白与 U+3000     period: [] 或 [s,s], s 形如 YYYY-MM 且 MM ∈ 01..12
            prompt_sha256: 64 位 [0-9a-f]
  S3 列表序  枚举列表 (asset module approach baseline source universe risk_factors): 按词表序严格递增 (⇒ 去重)
            字符串列表 (builds_on external_ref): 字节序严格递增
  S4 非空    asset  module  approach  Data.source  universe  findings  pipe(>=1 个阶段键)      码点: Factor.name <= TAG_MAX_FACTOR_NAME_CP
            其余列表与字符串不设上限 (findings 多写无妨, 标签的目的就是不读原文)
  S5 版本    schema_version == TAG_SCHEMA_VERSION

V 词表级
  V1 枚举    所有枚举字段的值 ∈ schema.hpp 对应词表
  V2 主阶段  primary ∈ pipe 出现的阶段键
  V3 归属链  阶段键 K 下: 每个 module[i] 满足 Module_stage[module[i]] == K
                        每个 approach[i] 满足 Approach_module[approach[i]] ∈ module
            L3.baseline: 每个 baseline[i] 满足 Module_stage[Approach_module[baseline[i]]] == L3_alpha, 且 baseline ∩ approach = ∅

K 字段间一致性
  K1 体裁    genre=framework ⇒ pipe 阶段键数 >= 3
            genre=review    ⇒ 每个出现阶段的 result 内所有列表为空
            genre=handbook  ⇒ primary ∈ {L1_factor, L2_process}, 且 L1_factor 出现
            genre=research ∧ primary=L1_factor ∧ L1.module != [L1_mining] ⇒ |L1.result.factors| >= 1
  K2 数值域  Metric.value ∈ [MetricKind_lo, MetricKind_hi] (kind 的取值域, §1)
  K3 结果归属 Metric.kind ∈ 所在阶段允许子集 (§2 各 result 注释)      PoolMetric.universe ∈ 同阶段 setup.universe
  K4 高频    高频(Data) := freq ∈ {l1 l2 minute mixed} ∧ source ∩ {market_minute market_l1_l2} ≠ ∅
            每个 Data: freq ∈ {l1 l2 minute} ⇒ source ∩ {market_minute market_l1_l2} ≠ ∅ (频率与数据源自洽)     L7 出现 ⇒ 高频(L7.setup.data)
  K5 资产↔池 asset ∩ {stock_cn stock_hk stock_us} = ∅  ⇔  每个出现的 setup.universe == [na]
  K6 日期    period 非空 ⇒ beg < end, 且 end <= 文件名日期所在月 (日期占位 00000000 时跳过后半)
  K7 自引    builds_on ∌ id

G 接地 (norm(s) := 去 ASCII 空白/U+3000/U+00A0 与 * | #, 全角 FF01..FF5E → 半角, ASCII 大写 → 小写; 下面均在 norm 后比较)
  G1 逐字    每个 evidence (Metric / Factor / Finding): 码点数 >= TAG_EVIDENCE_MIN_CP 且是 report.md 的子串
  G2 数字    Metric.value 的 lexeme / 去负号 / ×100 (十进制移位) 三者之一出现在自己的 evidence 中
  G3 因子名  Factor.name 出现在 report.md 中
  G4 贴合    Finding.text 与其 evidence 的字符 bigram 重合率 >= TAG_FINDING_OVERLAP_MIN

X 跨文件 (仅单文件规则全过者参与)
  X1 引用    builds_on 每项 ∈ raw 全部 stem; 被引日期 <= 本文日期 (任一为 00000000 跳过); 已标注文件间 builds_on 无环
  X2 分布    primary 在全库 / 每个 module 数 >= 3 的阶段各自的 module 在有该阶段的篇子 / 每个 approach 数 >= 3 的模块各自的 approach 在有该模块的篇子,
            分母 >= TAG_DIST_MIN_N 时查, 任一单值占比 > TAG_DIST_MAX_SHARE ⇒ 库级违规. genre 与只有 2 个 module 的阶段不查 (研报库本就偏 research/L1, 二分必有一侧过半, 查了只报结构)
  X3 死词表  缺失=0 时: Module / Approach 中从未使用的值 ⇒ [提示], 不违规
  X4 串写    两篇 findings 的 canonical 完全相同 ⇒ 双方违规
```
