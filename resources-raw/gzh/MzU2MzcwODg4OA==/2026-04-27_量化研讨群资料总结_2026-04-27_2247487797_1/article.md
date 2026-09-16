# 量化研讨群资料总结 2026-04-27

Alpha搬运工 睿见Alpha 2026-04-27 10:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzU2MzcwODg4OA==&mid=2247487797&idx=1&sn=dbeda9975a342bdeea86cf5e2e6374b0&chksm=fde653b2dff066880a00db3c068e7c192c024f06346b11f98b6aa5861d27d3f22649825490b0#rd](https://mp.weixin.qq.com/s?__biz=MzU2MzcwODg4OA==&mid=2247487797&idx=1&sn=dbeda9975a342bdeea86cf5e2e6374b0&chksm=fde653b2dff066880a00db3c068e7c192c024f06346b11f98b6aa5861d27d3f22649825490b0#rd)

## A Complete Taxonomy of Black-Scholes Greeks: Closed-Form Solutions for First, Second, and Third-Order Sensitivities

**标签**：#期权、#Black\-Scholes、#Greeks、#闭式解、#风险管理、#VannaVolga、#Python实现、#衍生品定价

**总结**  ：论文系统整理 21 个 Black-Scholes Greeks，覆盖一阶、二阶、三阶和组合层面敏感度，并给出闭式推导、PDE 关系、sticky-strike/sticky-delta、AAD 和近到期行为。文中称 19 个标准 Greeks 中 12 个 call/put 相同，并提供约 50 张图和 finite-difference 数值校验框架。

**评估**  ：

-   **质量**：作为公式手册较完整，推导覆盖面广；但不是实证论文，也没有市场数据验证。
    
-   **有用程度**：中到高。对期权风险库、Greeks 单元测试和教学很有用，对 alpha 研究间接。
    
-   **适合方向**：衍生品定价、期权风控、做市 Greeks 校验、模型库建设。
    
-   **主要不足或可疑之处**：Black-Scholes 假设本身过强；实际波动率曲面、离散分红、交易成本和跳跃风险仍需另行处理。
    

## Integrating Geopolitical Risk Into Low Volatility Factor Construction

**标签**：#全球股票、#低波动因子、#地缘政治风险、#RavenPack、#因子构建、#组合优化、#日频数据

**总结**  ：论文把 RavenPack 地缘政治事件/情绪信号加入低波动因子构建，在 2019–2025 样本中比较基准、静态优化和两种自适应权重。Adaptive-1 总收益 147.86%、年化 14.45%、波动 16.31%、最大回撤 -32.56%、Sharpe 0.909，显著高于基准 Sharpe 0.704；Wilcoxon 检验显示 Adaptive-1 年化差 3.67%、p=0.007。

**评估**  ：

-   **质量**：有明确基准、风险调整指标和显著性检验；但样本期短且覆盖重大地缘政治事件，容易过拟合。
    
-   **有用程度**：中。可借鉴“低波+地缘政治风险过滤/再加权”，但 RavenPack 数据门槛高。
    
-   **适合方向**：全球股票因子、低波策略、另类数据、风险 overlay。
    
-   **主要不足或可疑之处**：未充分说明交易成本、换手和地区/行业暴露控制；2019–2025 的特殊样本可能夸大地缘政治信号。
    

## Token Dilution and the Cross-Section of Cryptocurrency Returns

**标签**：#加密货币、#截面收益、#Tokenomics、#供应稀释、#Fama\-MacBeth、#CoinGecko、#周频数据

**总结**  ：论文用 CoinGecko API 构建 2020-11 至 2026-03 的 404 个加密货币周频面板，测试 float ratio、FDV premium 和 12周 circulating supply growth 三类稀释指标。FDV premium 在 Fama-MacBeth 回归中 Newey-West t=-3.13，12周稀释率 t=-2.79/-2.54，多空组合年化价差约 25–32%。

**评估**  ：

-   **质量**：主题清晰，因子定义可操作，包含截面回归、组合排序和蓝筹剔除；但供给数据由市值/价格推算，口径风险大。
    
-   **有用程度**：高。Token 解锁、FDV premium 和稀释 beta 是可直接纳入 crypto 多因子库的信号。
    
-   **适合方向**：加密货币截面因子、供给冲击、代币解锁事件、风险溢价研究。
    
-   **主要不足或可疑之处**：幸存者偏差、交易所可交易性、流动性/滑点和做空约束处理不足；周频可能错过解锁日前后的短周期冲击。
    

## Beyond the Greeks: Proactive Neural Hedging in Turbulent Markets

**标签**：#衍生品、#期权对冲、#神经网络、#JumpDiffusion、#HAC、#生成模型、#风险管理

**总结**  ：论文提出“结构化 jump-diffusion hedge + neural residual learner + generative scenario augmentation”的主动对冲框架，用 Newey-West HAC 和 `|Z_t| > 1.96` 识别结构模型错配。全文主要是理论和架构设计，没有真实市场数据回测或可验证交易表。

**评估**  ：

-   **质量**：概念链条完整，但实证为空；神经残差学习、生成场景和 HAC 识别之间缺少可复现实现。
    
-   **有用程度**：低。可当作对冲系统设计灵感，不可作为已验证模型。
    
-   **适合方向**：衍生品风控、对冲模型研究、压力场景生成。
    
-   **主要不足或可疑之处**：没有样本、baseline、交易成本、再平衡频率和 PnL 归因，落地前需要从零实现并验证。
    

## Machine Learning Forecasts of Asymmetric Betas Using Firm-Specific Information

**标签**：#美股、#Beta预测、#下行风险、#机器学习、#CRSP、#OpenAssetPricing、#月频数据、#组合风险

**总结**  ：论文用 CRSP 1980–2024 美股数据和公司特征，预测 downside/upside beta 与 semibeta，比较 PCA、PLS、Elastic Net、GB、RF、FFNN 和组合模型。1990–2024 样本外中，1个月 downside beta 的 R²约 45–46%，CNL 重构 CAPM beta 的 h=1 R²为 38.73%、h=12 为 12.67%；基于条件 beta 的市场中性组合 ex-post beta 可接近 0。

**评估**  ：

-   **质量**：样本长、模型对照充分、覆盖多期限和组合应用；但模型复杂度高，特征库和再训练流程需要严格防前视。
    
-   **有用程度**：高。对风险模型、beta 中性化、downside 风险控制很有参考价值。
    
-   **适合方向**：股票多因子风险模型、市场中性组合、机器学习预测、组合优化。
    
-   **主要不足或可疑之处**：需要 CRSP/Compustat 与 OpenAssetPricing 数据；交易策略收益并非核心，不能把 beta 预测 R²直接等同 alpha。
    

## Are the Turtles Still Beating the Market? A Cost-Decomposition Pipeline for Trend-Following Strategies

**标签**：#趋势跟踪、#Turtle策略、#执行成本、#匹配引擎、#市场微观结构、#合成数据、#开源代码

**总结**  ：论文开源一个趋势跟踪执行成本分解 pipeline，比较 frictionless、parametric cost 和 matching-engine 三种执行层，并把成本拆为 spread、impact、queue、adverse selection。合成 3 资产 10 年样本中，年化收益从 51.75%/47.53%/44.66% 逐层下降，Sharpe 从 1.41 降至 0.97，matching engine 额外揭示 $7.54M adverse-selection cost，占 engine 总成本 55%。

**评估**  ：

-   **质量**：工程贡献明确，有 117 个测试和多验证门；但实证结果只来自合成价格，不代表真实趋势跟踪收益。
    
-   **有用程度**：中到高。对执行成本建模、回测真实性审计和策略衰减研究很有用。
    
-   **适合方向**：CTA、趋势跟踪、交易成本分析、撮合引擎仿真。
    
-   **主要不足或可疑之处**：没有真实期货/加密订单簿结果；parametric calibration 到真实盘口的稳定性仍未验证。
    

**代码**：https://github.com/boonchuan/turtles（报告称开源 pipeline， permissive license）。

## Cross-Sectional Dispersion and the State Dependence of Cryptocurrency Momentum

**标签**：#加密货币、#截面动量、#横截面离散度、#风险缩放、#CoinGecko、#日频数据、#状态依赖

**总结**  ：论文用 CoinGecko Pro 构建 2015-04-01 至 2026-03-19 的动态、幸存者偏差敏感加密货币面板，最终 tradable panel 为 98 个 ID，研究横截面离散度对动量的状态依赖。基础 crypto momentum 全样本 Sharpe 0.631；dispersion scaling 将 Sharpe 提至 0.798、最大回撤从 -42.5% 降至 -17.1%，BTC 波动率缩放在 2020 后 Sharpe 最高达 1.029。

**评估**  ：

-   **质量**：对幸存者偏差、动态 universe、福利指标和 placebo 做得较细；但作者自己承认 DSR 20–200 trials 下不过 5% 门槛。
    
-   **有用程度**：高。可直接借鉴横截面离散度作为 crypto momentum 降风险 overlay。
    
-   **适合方向**：加密货币截面动量、风险缩放、状态依赖策略、组合风控。
    
-   **主要不足或可疑之处**：CoinGecko Pro 订阅和动态退市处理复现门槛高；full-sample active Sharpe 相对等权基准仍弱，价值主要来自风险形状改善而非绝对 alpha。
    

## Beating the Earnings Game: Why Do Prediction Markets Outperform Professional Analysts?

**标签**：#美股、#预测市场、#Polymarket、#财报事件、#链上数据、#另类数据、#事件驱动

**总结**  ：论文研究 2025-09 至 2026-02 Polymarket 财报合约，覆盖 469 个 firm-quarter events 和 383 家美国公司，并匹配 I/B/E/S、CRSP-Compustat、Yahoo Finance 与 SEC Form 4。预测市场 Brier score 0.159，分析师 0.360，MSE 降低 56.0%；hit rate 78.5% vs 43.7%，PM surprise 对 \[-1,+1\] CAR 的系数 0.067 且 p<0.001。

**评估**  ：

-   **质量**：数据新、链上交易细节丰富，包含 29,091 名交易者、698 个市场和 374,447 笔 CTF transfers；但样本仅 2025–2026，市场制度仍很年轻。
    
-   **有用程度**：高。对财报事件、预测市场价格、链上 crowd skill 提取很有启发。
    
-   **适合方向**：美股财报事件驱动、另类数据、预测市场、链上行为分析。
    
-   **主要不足或可疑之处**：Polymarket 市场本身可能受监管、流动性和选择性上市影响；交易成本、可下注容量和从概率到股票组合的执行链条未完全解决。
    

## Dealer Gamma Exposure and Overnight Gap Risk: Incremental Information in Low-Volatility Regimes

**标签**：#美股、#SPX期权、#DealerGamma、#隔夜跳空、#HAR模型、#ClarkWest检验、#风险管理

**总结**  ：论文用 SPX options dealer gamma 预测 overnight gap 绝对收益，在 Corsi HAR + BAA10Y 基线下以 2015–2022 训练、2023–2025 测试。低 VIX calm 子样本 N=349 中，基线 OOS R²=-0.068、增强模型 -0.030，Clark-West=+5.82、p=6.0×10^-9；stress 子样本 N=318 中 CW=+0.76、p=0.449。

**评估**  ：

-   **质量**：有样本外、regime split、bootstrap、placebo 和阈值稳健性；比多数 gamma 叙事更严谨。
    
-   **有用程度**：高。适合把 dealer gamma 加入隔夜风险预算、尾部 VaR 或事件前仓位控制。
    
-   **适合方向**：期权风险管理、指数隔夜风险、波动率择时、风险 overlay。
    
-   **主要不足或可疑之处**：依赖 SpotGamma/期权 gamma 数据，商业数据可得性和口径会影响复现；预测的是 gap magnitude，不等于方向性 alpha。
    

## An Anatomy of the Stock Borrow Fee Anomaly

**标签**：#美股、#融券费率、#做空约束、#股票借贷、#FFC4、#期权替代、#月频数据

**总结**  ：论文用 Markit Buy Side Analytics 和 CRSP 2006-07 至 2022-12 的美股普通股数据，样本含 11,139,763 个 stock-day observations，研究借券费率异常。High fee 组合次月 FFC4 alpha 为 -1.42%/月（t=-4.80），扣除借券费后仍为 -0.65%/月（t=-2.39）；高费股票 OTM put bid-ask return 相对低费股票高 9.21%（t=3.01）。

**评估**  ：

-   **质量**：数据扎实，覆盖借券供需、费率、期权替代和价格修正过程；结果经济显著。
    
-   **有用程度**：高。借券费可直接作为空头拥挤/做空约束/负预期收益因子。
    
-   **适合方向**：美股多空、证券借贷、做空约束、期权替代交易。
    
-   **主要不足或可疑之处**：Markit 借券数据难拿，实际做空要受 locate、费率漂移、召回和容量限制；高费组合可能很难按回测规模执行。
    

## An Angle-Based Measure of Price Impact in Cryptocurrency Markets During Crises

**标签**：#加密货币、#流动性、#价格冲击、#KyleLambda、#Kraken、#分钟数据、#危机状态

**总结**  ： 论文提出基于几何角度的价格冲击指标 `θ`，并通过 `λ = tan(θ)` 连接 Kyle price-impact coefficient，用 Kraken 分钟级 OHLCV 比较 Terra/Luna 崩盘和 2023年3月银行危机。Terra/Luna 中均值 θ 从 35.8° 升至 38.2°（Δ=+2.4°, p<0.001），银行危机中从 36.6° 升至 38.8°（Δ=+2.2°, p<0.001），合并 λ 从 0.732 升至 0.795（约 +8.6%）。

**评估**  ：

-   **质量**：指标简单可复现，有危机/稳定窗口对照和稳健性表；但只用 Kraken 单一交易所，且是关联而非因果。
    
-   **有用程度**：中。可作为分钟级流动性压力指标或冲击成本监控变量。
    
-   **适合方向**：加密市场微观结构、危机流动性、交易成本、风控监控。
    
-   **主要不足或可疑之处**：OHLCV 分钟数据无法替代盘口深度；不同交易所、稳定币报价和零成交分钟会影响 θ 的稳定性。
    

**代码**  ：Zenodo replication package: https://doi.org/10.5281/zenodo.19176941（含 metadata、preprocessing code、1-minute aggregation code 和 reproduction instructions）。

## 量化策略演进手记系列之二：引入多维价量信息的风格因子轮动.pdf

**标签**：#A股、#风格轮动、#因子择时、#指数增强、#随机森林、#价量特征、#周频调仓

**总结**：报告在沪深300/中证500/中证1000风格因子池上构造 60 个因子组合维度价量特征，用随机森林筛选重要特征后等权合成，替代简单因子动量。动态合成在沪深300上年化收益从 7.34% 提至 11.03%、夏普从 0.38 提至 0.54；指数增强中沪深300周频新信号年化超额 9.42%、IR 2.33，中证500周频年化超额 10.10%、IR 2.35。

**评估：**

-   **质量**：有多股票池、多指标和指数增强对照，样本到 2026.4；参数自由度较高，随机森林筛选和周频换手可能有数据挖掘风险。
    
-   **有用程度**：高。可直接复现实验的是因子组合级价量特征、动态特征筛选和宏观/风格共振权重替换。
    
-   **适合方向**：A股多因子、风格轮动、指数增强、因子拥挤度监控。
    
-   **主要不足或可疑之处**：未充分披露交易成本、组合容量和特征选择稳定性；中证500月频方案明显退化，说明部分信号半衰期很短。
    

## OpenClaw应用：为Agent重构投研信息底座.pdf

**标签**  ：#投研Agent、#LLM、#知识库、#Obsidian、#问财SkillHub、#MarkItDown、#投研工程

**总结** ：报告讨论 OpenClaw/ClawResearch Agent 的信息底座，提出数据源侧用问财 SkillHub 覆盖查数、选股器、事件宏观、研究评级、信息搜索 5 类 Skill，知识库侧用 Obsidian + LLM Wiki + OpenCLI/Web Clipper/MarkItDown 做采集、格式归一和检索。它不是策略论文，没有回测收益，核心数字来自架构覆盖范围而非交易结果。

**评估** ：

-   **质量**：工程路线清楚，但没有可量化的准确率、召回率、节省时间或投研收益评估。
    
-   **有用程度**：中。对搭建本地研报/论文知识库和 Agent 工作流有参考价值，对 alpha 研究没有直接贡献。
    
-   **适合方向**：投研自动化、知识库工程、LLM 辅助研究流程。
    
-   **主要不足或可疑之处**：依赖商业数据源和人工维护规则，未展示系统性 benchmark；容易把“工具链可用”误读成“投研结论可靠”。
    

## 可转债估值因子的优化思路——赎回规避与非赎回博弈域.pdf

**标签**：#A股可转债、#低估因子、#赎回规避、#正股动量、#事件风险、#转债估值、#日频回测

**总结**  ：报告把“非赎回博弈域”定义为未来 30 天内无法满足赎回条件的转债，认为平价 130 附近的赎回博弈区会压制低估因子。优化后低估策略 2018 年以来年化收益 17.1%、年化超额 6.4%，低估+正股动量策略年化收益 17.4%、年化超额 6.7%。

**评估** ：

-   **质量**：规则直观且和转债条款机制一致，样本覆盖 2018 以来；但赎回意愿不可观测，域划分对发行人行为变化较敏感。
    
-   **有用程度**：高。可直接把“赎回风险过滤器”接入转债低估/动量组合。
    
-   **适合方向**：可转债多因子、条款事件风险、转债组合风控。
    
-   **主要不足或可疑之处**：未充分展开成交冲击、停牌/强赎公告滞后、可交易容量；若市场已拥挤，非赎回域低估因子的超额可能快速衰减。
    

## 投研工具箱系列（三）：利率趋势择时模板.pdf

**标签**：#利率、#国债指数、#趋势择时、#BIAS、#移动平均、#Excel工具、#债券配置

**总结**  ：报告用 BIAS 与均线斜率判断利率趋势，对中债-国债总财富(10年以上)指数 CBA00661.CS 做 90%/110% 债券仓位切换。2005 年至 2026-04-24 回测年化收益 7.18%、夏普 1.24、最大回撤 13.09%，较买入持有收益提高 0.95%、回撤降低 1.43%。

**评估** ：

-   **质量**：规则简单透明，时间跨度长；但只给单一模板和目标指数，缺少参数稳健性、交易成本和实际杠杆融资约束。
    
-   **有用程度**：中。可作为债券趋势 overlay 的基线模型，不宜直接当作完整利率策略。
    
-   **适合方向**：宏观择时、债券配置、FOF 风险预算。
    
-   **主要不足或可疑之处**：90%/110% 仓位隐含融资或久期杠杆，实际可执行性要看产品约束；Excel 工具不等于可审计研究代码。