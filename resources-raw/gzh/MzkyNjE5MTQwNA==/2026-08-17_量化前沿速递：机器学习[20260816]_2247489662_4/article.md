# 量化前沿速递：机器学习\[20260816\]

shameless 量化前沿速递 2026-08-17 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489662&idx=4&sn=4b2c81952c33b55f1b47424be3e2306f&chksm=c3d863fd32a26fdd15a845f9d6ede36078a718348fe4cede85357d2849210d9292a3376b9bb3#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489662&idx=4&sn=4b2c81952c33b55f1b47424be3e2306f&chksm=c3d863fd32a26fdd15a845f9d6ede36078a718348fe4cede85357d2849210d9292a3376b9bb3#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Yield Curve Prediction with Machine Learning

基于机器学习的产量曲线预测

来源:ARXIV\_20260811

\[2\] Self Explaining Segment Trees

自我解释的分段树

来源:ARXIV\_20260811

\[3\] When the Fed Speaks

当美联储发言时

来源:ARXIV\_20260812

\[4\] Long Horizon Forecasting of Complete Financial Statements with Forma

用Forma对完整财务报表进行长期预测

来源:ARXIV\_20260813

\[5\] EU ETS under attack  The impact of carbon price suppression on the decarbonization of the power sector

欧盟碳排放交易体系受到攻击碳价格抑制对电力行业脱碳的影响

来源:ARXIV\_20260814

\[6\] What Makes a Peer  Valuation Anchored Similarity in Private Markets

是什么让同行估值在私人市场中锚定相似性

来源:ARXIV\_20260814

### 

\[1\] Yield Curve Prediction with Machine Learning

标题:基于机器学习的产量曲线预测

作者:Jeron Tan Kang

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.07536

Abstract : This paper compares direct yield and factor based approaches to U.S. Treasury yield curve forecasting using a common high dimensional macroeconomic information set. Forecasts are evaluated on monthly zero coupon yields over the 2015 2025 out of sample period. Gains over the random walk are concentrated at short maturities and in slope forecasts, and decline with the forecast horizon. Direct yield models perform best for slope forecasts and are relatively stronger at short horizons, while factor based models become more competitive at longer horizons. Macroeconomic predictors provide clear incremental predictive power, strongest for slope related movements. A trading simulation reinforces that macro augmented models perform best in slope trades. The simulation also highlights a gap between statistical and economic performance, as the random walk is a strong benchmark under statistical loss but performs poorly as a trading signal.

Keywords : 

Abstract :本文使用常见的高维宏观经济信息集，对美国国债收益率曲线预测的直接收益率和基于因子的方法进行了比较。预测基于2015年至2025年样本期外的月度零息收益率进行评估。随机游走的收益集中在短期和斜率预测中，并随着预测期的推移而下降。直接产量模型在斜率预测方面表现最佳，在短期内相对较强，而基于因子的模型在长期内更具竞争力。宏观经济预测因子提供了明确的增量预测能力，对斜率相关运动的预测能力最强。交易模拟进一步证实，宏观增强模型在斜坡交易中表现最佳。该模拟还突显了统计和经济表现之间的差距，因为随机游走是统计损失下的一个强有力的基准，但作为交易信号表现不佳。

Keywords :

### 

\[2\] Self Explaining Segment Trees

标题:自我解释的分段树

作者:Girish G N, Dhanashekar Kandaswamy

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.08197

Abstract : Business users confronted with a moving metric need to know which part of their data moved and why. Existing data explanation methods typically return predicates  conjunctions of attribute value conditions that isolate responsible records. Predicates are exact and directly executable as filters, but they describe axis aligned regions and may not compactly capture segments defined by combinations of continuous tendencies. This paper presents Self Explaining Segment Trees (SEST), an architecture in which an explanation is a multivariate cluster in a feature subspace selected for relevance to a designated key performance indicator (KPI). SEST selects the subspace once per KPI using Shapley attributions over a decision tree surrogate, recursively partitions the population while choosing the branching factor independently at each node through mixture model silhouette search, and attaches to every node a dual explanation payload  standardized effect sizes over numeric features and type dependent contribution profiles over user designated dimensions. These explanations are computed from untransformed data so surfaced values retain source units and category labels. A stance layer reduces any depth of the tree to its extremal KPI suppressing and KPI amplifying segments. We establish termination and a node count bound determined by the depth limit and minimum segment size, and characterize per tree construction cost as quadratic in population size in the degenerate case and geometrically decaying across depth in the balanced case. This is an architecture and methodology paper  we report no predictive accuracy or validation results and leave outcome validation to future work.

Keywords : 

Abstract :面对移动指标的业务用户需要知道他们的数据的哪一部分移动了以及为什么移动。现有的数据解释方法通常返回隔离责任记录的属性值条件的谓词连词。谓词是精确的，可以直接作为过滤器执行，但它们描述轴对齐的区域，可能无法紧凑地捕获由连续趋势组合定义的片段。本文提出了自解释分段树（SEST），这是一种架构，其中解释是一个特征子空间中的多元聚类，该子空间被选择与指定的关键绩效指标（KPI）相关。SEST使用Shapley属性在决策树代理上为每个KPI选择一次子空间，递归划分总体，同时通过混合模型轮廓搜索在每个节点独立选择分支因子，并在每个节点上附加一个双解释有效载荷标准化效果大小，在数字特征上和用户指定维度上的类型相关贡献分布。这些解释是根据未转换的数据计算的，因此表面值保留了源单位和类别标签。立场层将树的任何深度减少到其极值KPI抑制和KPI放大段。我们建立了由深度限制和最小分段大小确定的终止和节点计数界限，并在退化情况下将每棵树的构建成本表征为种群大小的二次方，在平衡情况下则随深度呈几何衰减。这是一篇架构和方法论论文，我们没有报告预测准确性或验证结果，并将结果验证留给未来的工作。

Keywords :

### 

\[3\] When the Fed Speaks

标题:当美联储发言时

作者:Lukasz Adamski, Robert Slepaczuk

来源:ARXIV\_20260812

链接:https://arxiv.org/pdf/2608.10693

Abstract : Our primary goal is to forecast and empirically examine the evolution of the implied volatility (IV) surface, with particular focus on the dates of scheduled meetings of the Federal Open Market Committee (FOMC). Firstly, we check if IV increases before the announcement and if thes effect is stronger for short dated, out the money (OTM) options in high volatility regimes. In the second part, we turn the focus to verifying if the ML framework can beat the benchmark random walk in forecasting this effect. A feature related to dates of scheduled FOMC meetings augments the model, which allows us to discover if it can learn the effect of elevated pre announcement uncertainty. Our contribution relies mainly on the quantitative prediction of the pre announcement effect and the inclusion of exogenous information inside the ML framework used for the IV surface forecasting. It is also on of the first attempts to apply ML models directly on the IV surface without relying on dimensionality reduction. To achieve this, we employ a convolutional two dimensional LSTM model, which is capable of learning spatio temporal signals in the surface. Our analysis reveals that the edge of the ML framework can be limited due to the noisy characteristics of the IV surface. Nevertheless, our study reinforces the perspective that ML models can effectively forecast the IV surface also during abnormal days.

Keywords : 

Abstract :我们的主要目标是预测和实证检验隐含波动率（IV）面的演变，特别关注联邦公开市场委员会（FOMC）预定会议的日期。首先，我们检查IV在宣布之前是否会增加，以及在高波动性制度下，短期资金外（OTM）期权的影响是否更强。在第二部分中，我们将重点放在验证ML框架是否可以在预测这种效应方面击败基准随机游走。与联邦公开市场委员会预定会议日期相关的一个特征增强了该模型，使我们能够发现它是否可以学习到预先公告不确定性增加的影响。我们的贡献主要依赖于对预先公告效应的定量预测，以及在用于IV表面预测的ML框架内纳入外源信息。这也是首次尝试将ML模型直接应用于IV表面，而不依赖于降维。为了实现这一点，我们采用了一种卷积二维LSTM模型，该模型能够学习表面中的时空信号。我们的分析表明，由于IV表面的噪声特性，ML框架的边缘可能会受到限制。然而，我们的研究强化了这样一种观点，即机器学习模型也可以在异常日子里有效地预测IV表面。

Keywords :

### 

\[4\] Long Horizon Forecasting of Complete Financial Statements with Forma

标题:用Forma对完整财务报表进行长期预测

作者:Travis L. Johnson, Jiannan Jiang, Soumyabrata Chaudhuri, Yihao Chen, Lauren Falvey, Donal O'Cofaigh

来源:ARXIV\_20260813

链接:https://arxiv.org/pdf/2608.11327

Abstract : Specialist training beats generalist scale when forecasting financial statements. To our knowledge, no prior work jointly forecasts complete financial statements beyond one year, yet in a discounted cash flow valuation most firm value sits past that window. We release ProForma 20Q, a reproducible benchmark for forecasting 78 statement line items 1 20 quarters ahead, for anonymized firms, from past statements and an industry code, scored by change space  R 2 . On it, Forma, a transformer that reads statements as sets of (account, quarter, value) tuples and maximizes a masked tuple Gaussian likelihood, beats every competitor we field  classical machine learning, chained gradient boosting, a zero shot time series foundation model, and frontier large language models. Its lead widens with horizon, where valuation needs accuracy most, and its Gaussian predictive intervals never under cover. Forma s forecasts nearly satisfy accounting identities  exact coherence is recoverable at no statistically significant accuracy cost. Its tuple interface supports scenario analysis without retraining, and we show that pinning future revenue paths sharpens the rest of the statement.

Keywords : 

Abstract :在预测财务报表时，专业培训胜过通才规模。据我们所知，之前没有任何研究联合预测一年后的完整财务报表，但在贴现现金流估值中，大多数公司价值都超过了这一窗口。我们发布了ProForma 20Q，这是一个可重复的基准，用于根据过去的报表和行业代码，预测匿名公司未来120个季度的78个报表行项目，按变化空间R2评分。在它上面，Forma，一个将语句读取为（帐户、季度、值）元组集并最大化掩蔽元组高斯似然的转换器，击败了我们领域的每一个竞争对手——经典机器学习、链式梯度提升、零炮时间序列基础模型和前沿大型语言模型。它的领先优势随着估值最需要准确性的领域而扩大，其高斯预测区间永远不会被掩盖。Forma的预测几乎满足会计恒等式的要求，在没有统计上显著的准确性成本的情况下，可以恢复精确的一致性。它的元组接口支持场景分析，无需重新训练，我们表明，锁定未来的收入路径可以使语句的其余部分更加清晰。

Keywords :

### 

\[5\] EU ETS under attack  The impact of carbon price suppression on the decarbonization of the power sector

标题:欧盟碳排放交易体系受到攻击碳价格抑制对电力行业脱碳的影响

作者:Javier Gonzalez-Ruiz, Carlos Rodriguez-Pardo, Alice Di Bella, Paolo Mastropietro, Jose Pablo Chavez-Avila, Massimo Tavoni

来源:ARXIV\_20260814

链接:https://arxiv.org/pdf/2608.12363

Abstract : European countries are debating policies to mitigate the increased energy costs caused by renewed geopolitical tensions, while pursuing decarbonization and electrification. A notable example is Italy s 2026 Decreto Bollette package, which proposes to remove the carbon price equivalent from the bids of certain gas driven power plants to wholesale electricity markets, among other provisions. We use this as a case study to assess the long term implications of suppressing the carbon price signal in the electricity market for investment, emissions, and consumer costs. We employ a stylized Italian power system using MARLEY, a multi agent reinforcement learning framework focused on long term electricity market assessments. In this framework, we test this policy across configurations with varying levels of support for green investment, resource adequacy, and flexibility. Results show that partial suppression of the carbon price signal yields short term cost reductions but only a minor long term effect on total system costs, as the deferred emissions are ultimately repaid by consumers. CO  2  emissions rise across most configurations since suppressing the price signal erodes incentives for renewable and storage investment. Only the most ambitious configurations for supporting green investment avoid this outcome, but they do so by marginalizing the wholesale price signal itself, thereby requiring a commitment to a hybrid market paradigm that is in contradiction with the rationale of the proposed price intervention.

Keywords : 

Abstract :欧洲国家正在就缓解地缘政治紧张局势加剧造成的能源成本增加的政策进行辩论，同时追求脱碳和电气化。一个值得注意的例子是意大利2026年的《博莱特法令》，该法令提议从某些天然气发电厂向批发电力市场的投标中取消碳价格等值，以及其他规定。我们将此作为案例研究，评估抑制电力市场中的碳价格信号对投资、排放和消费者成本的长期影响。我们采用了一种风格化的意大利电力系统，该系统使用MARLEY，这是一个专注于长期电力市场评估的多智能体强化学习框架。在这个框架中，我们在对绿色投资、资源充足性和灵活性支持程度不同的配置中测试了这一政策。结果表明，部分抑制碳价格信号可以在短期内降低成本，但对总系统成本的长期影响很小，因为延迟排放最终由消费者偿还。由于抑制价格信号会削弱对可再生能源和储能投资的激励，因此大多数配置的二氧化碳排放量都会上升。只有支持绿色投资的最雄心勃勃的配置才能避免这一结果，但它们是通过边缘化批发价格信号本身来实现的，因此需要致力于与拟议的价格干预理论相矛盾的混合市场范式。

Keywords :

### 

\[6\] What Makes a Peer  Valuation Anchored Similarity in Private Markets

标题:是什么让同行估值在私人市场中锚定相似性

作者:Sebastian Frank, Jingrao Lyu, Max Jarmey, Preetha Saha, Mingshu Li, Sweet Kaur, Sola Akinola, Dhagash Mehta

来源:ARXIV\_20260814

链接:https://arxiv.org/pdf/2608.12594

Abstract : As more investors contemplate private markets and contend with limited transparency, sparse disclosures, and infrequent transactions, identifying economically meaningful peer companies for comparison is a fundamental challenge for valuation, due diligence, portfolio construction, and risk management. We propose an ensemble tree based supervised similarity learning framework that defines company similarity through the lens of market valuation rather than static feature matching or semantic descriptions. Specifically, we train a CatBoost gradient boosted decision tree model on observed private company valuations and derive a valuation aware similarity metric from importance weighted leaf node co occurrences across the ensemble. The similarity metric captures shared valuation drivers while accommodating nonlinear relationships, mixed data types, and pervasive missing data common in private markets. Using a global private market universe of approximately 270,000 companies, including more than 53,000 firms with observed or derivable post money valuations spanning multiple industries, geographies, and deal stages, we demonstrate that the proposed similarity framework improves upon traditional distance based and text embedding based approaches in downstream k nearest neighbor valuation tasks in the evaluated industry groups, while retaining case based explainability.

Keywords : 

Abstract :随着越来越多的投资者考虑私人市场，并与有限的透明度、稀疏的披露和不频繁的交易作斗争，识别具有经济意义的同行公司进行比较是估值、尽职调查、投资组合构建和风险管理的一个根本挑战。我们提出了一种基于集成树的监督相似性学习框架，该框架通过市场估值而不是静态特征匹配或语义描述来定义公司相似性。具体来说，我们在观察到的私营公司估值上训练了一个CatBoost梯度增强决策树模型，并从整个集合中的重要性加权叶节点共现中推导出了一个估值感知相似性度量。相似性度量捕获了共享的估值驱动因素，同时适应了非线性关系、混合数据类型和私人市场中常见的普遍缺失数据。我们使用了一个由大约27万家公司组成的全球私人市场，其中包括53000多家公司，这些公司在多个行业、地区和交易阶段都有观察到的或可衍生的后货币估值，我们证明了所提出的相似性框架在被评估行业组的下游k近邻估值任务中改进了传统的基于距离和基于文本嵌入的方法，同时保留了基于案例的可解释性。

Keywords :