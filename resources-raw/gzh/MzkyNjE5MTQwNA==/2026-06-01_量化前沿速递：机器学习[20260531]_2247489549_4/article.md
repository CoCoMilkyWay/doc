# 量化前沿速递：机器学习\[20260531\]

shameless 量化前沿速递 2026-06-01 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489549&idx=4&sn=42042cd6f7542dde6082a908c6eab7ae&chksm=c36bf9b33e2b2f834aa2097388a21d55bf6ae7fa1fcceeb981023cedad96d15de5e7cf702ab6#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489549&idx=4&sn=42042cd6f7542dde6082a908c6eab7ae&chksm=c36bf9b33e2b2f834aa2097388a21d55bf6ae7fa1fcceeb981023cedad96d15de5e7cf702ab6#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Is TabPFN the Silver Bullet for Insurance Pricing 

TabPFN是保险定价的灵丹妙药吗

来源:ARXIV\_20260525

\[2\] Leveraging Large Language Models for Sentiment Analysis

利用大型语言模型进行情感分析

来源:ARXIV\_20260525

\[3\] When Alpha Disappears

当阿尔法消失

来源:ARXIV\_20260526

\[4\] From Index to Equity

从指数到股票

来源:ARXIV\_20260526

\[5\] Volatility Surface Reconstruction using Deep Learning under No Arbitrage Constraints

无套利约束下基于深度学习的波动面重建

来源:ARXIV\_20260526

\[6\] From Accuracy to Auditability

从准确性到可审计性

来源:ARXIV\_20260526

\[7\] Predicting Stock Price Direction on Earnings Announcement Days using Multi modal Deep Learning

利用多模态深度学习预测盈利公告日的股价走势

来源:ARXIV\_20260526

\[8\] Multiperiod Groundwater Markets

多期地下水市场

来源:ARXIV\_20260527

\[9\] Nonlinear and Heavy Tailed Predictability in Transition Energy Financial Markets

转型能源金融市场的非线性和重尾可预测性

来源:ARXIV\_20260527

\[10\] Regime Based Portfolio Allocation Using Hidden Markov Models and Reinforcement Learning

基于隐马尔可夫模型和强化学习的制度投资组合分配

来源:ARXIV\_20260528

\[11\] Deep Learning Forecasting of the U.S. Aggregate Bond Index

美国综合债券指数的深度学习预测

来源:ARXIV\_20260528

\[12\] Insurance Pricing Optimization via Off Policy Evaluation

通过保单外评估优化保险定价

来源:ARXIV\_20260528

\[13\] Financially Guided Deep Portfolio Optimization

财务导向的深度投资组合优化

来源:ARXIV\_20260529

### 

\[1\] Is TabPFN the Silver Bullet for Insurance Pricing 

标题:TabPFN是保险定价的灵丹妙药吗

作者:Bruno Deprez, Wouter Verbeke, Tim Verdonck

来源:ARXIV\_20260525

链接:https://arxiv.org/pdf/2605.22892

Abstract : Modelling claim frequency and severity for non life insurance pricing predominantly relies on generalised linear models, with gradient boosted machines as the leading machine learning alternative. Tabular foundation models (TFMs) offer a fundamentally different paradigm. By pre training on large collections of synthetic datasets, TFMs enable inference on new data through in context learning, without any dataset specific fitting or hyperparameter tuning. This paper presents a first empirical evaluation of TabPFN for motor insurance pricing, benchmarking it against GLM and XGBoost on two publicly available MTPL datasets. Our results show that TabPFN does not consistently outperform established baselines, exhibits substantially longer inference times, and is sensitive to the size of the in context training set. While tabular foundation models represent a promising direction, particularly in data scarce settings, their current formulation does not offer a viable replacement for established actuarial methods.

Keywords : 

Abstract :非人寿保险定价的索赔频率和严重程度建模主要依赖于广义线性模型，梯度增强机器是领先的机器学习替代方案。表格基础模型（TFM）提供了一种根本不同的范式。通过对大量合成数据集进行预训练，TFM能够通过上下文学习对新数据进行推理，而无需任何特定于数据集的拟合或超参数调整。本文首次对TabPFN在汽车保险定价中的应用进行了实证评估，并在两个公开的MTPL数据集上将其与GLM和XGBoost进行了对标。我们的结果表明，TabPFN并不总是优于既定的基线，表现出更长的推理时间，并且对上下文训练集的大小很敏感。虽然表格基础模型代表了一个有前景的方向，特别是在数据稀缺的环境中，但它们目前的表述并不能为既定的精算方法提供可行的替代品。

Keywords :

### 

\[2\] Leveraging Large Language Models for Sentiment Analysis

标题:利用大型语言模型进行情感分析

作者:Xintong Wu, Peiting Tsai, Jing Yuan, Michael Yu, Greg Sun, Luyao Zhang

来源:ARXIV\_20260525

链接:https://arxiv.org/pdf/2605.20192

Abstract : Decentraland, a decentralized virtual reality platform operating within the expanding Metaverse ecosystem, utilizes its native MANA token to facilitate virtual asset transactions and governance. This study investigates the integration of Discord community sentiment with multi modal financial data to enhance cryptocurrency price prediction within virtual world economies. We address  (1) identifying sentiment patterns within Decentraland s Discord community, and (2) evaluating the impact of multi modal features on token return forecasting. Using a BERT based large language model for sentiment analysis, we develop two LSTM architectures  a baseline incorporating historical prices and a multi modal variant integrating sentiment scores, trading volume, and market capitalization. Results indicate predominantly neutral community sentiment with a positive skew. The multi modal model significantly outperforms the price only baseline in prediction accuracy. These findings demonstrate the predictive value of community derived signals for virtual economy forecasting and establish a foundation for future research at the intersection of immersive virtual environments, natural language processing, and cryptocurrency market analysis.

Keywords : 

Abstract :Decentraland是一个在不断扩大的Metaverse生态系统中运营的去中心化虚拟现实平台，它利用其原生MANA代币来促进虚拟资产交易和治理。本研究调查了Discord社区情绪与多模式金融数据的整合，以增强虚拟世界经济中的加密货币价格预测。我们解决了（1）识别Decentraland Discord社区内的情绪模式，以及（2）评估多模式特征对代币回报预测的影响。使用基于BERT的大型语言模型进行情绪分析，我们开发了两个LSTM架构——一个包含历史价格的基线和一个整合情绪评分、交易量和市值的多模态变体。结果表明，社区情绪主要是中性的，有积极的倾向。多模态模型在预测精度方面明显优于仅基于价格的基线。这些发现证明了社区衍生信号对虚拟经济预测的预测价值，并为未来在沉浸式虚拟环境、自然语言处理和加密货币市场分析交叉领域的研究奠定了基础。

Keywords :

### 

\[3\] When Alpha Disappears

标题:当阿尔法消失

作者:Fan Zhang, Zhen Li, Sijia Peng, Yu Chen

来源:ARXIV\_20260526

链接:https://arxiv.org/pdf/2605.23959

Abstract : We introduce When Alpha Disappears, a paired evaluation benchmark for diagnosing decision time leakage in financial machine learning backtests. Rather than treating leakage as a binary property, the benchmark estimates protocol induced inflation by toggling one evaluation convention at a time around a clean  t   1  open reference, while holding the data panel, walk forward split, model family, horizon, portfolio rule, and cost convention fixed. Across two daily OHLCV equity panels, six model families, and yearly tests from 2016  2024, we find that inflation is highly selective  centered temporal features and same day open execution with post open daily bar information cause large and stable increases in both predictive and trading metrics, whereas global normalization, future informed graph structure, and same day close execution are weak in most settings. The benchmark is diagnostic rather than a claim of tradable alpha, and is intended to make evaluation assumptions, failure modes, and protocol fragility directly measurable.

Keywords : 

Abstract :我们引入了When Alpha Disappears，这是一个用于诊断金融机器学习回溯测试中决策时间泄漏的配对评估基准。基准不是将泄漏视为二元属性，而是通过围绕干净的t1开放引用一次切换一个评估约定来估计协议引发的通货膨胀，同时保持数据面板、前进分割、模型族、地平线、投资组合规则和成本约定固定。在两个每日OHLCV股票面板、六个模型系列和2016-2024年的年度测试中，我们发现通货膨胀是高度选择性的时间特征，具有开盘后每日柱状图信息的当日开盘执行导致预测和交易指标的大幅稳定增长，而全球归一化、未来知情图结构和当日收盘执行在大多数情况下都很弱。该基准是诊断性的，而不是可交易阿尔法的声明，旨在使评估假设、故障模式和协议脆弱性直接可衡量。

Keywords :

### 

\[4\] From Index to Equity

标题:从指数到股票

作者:Marie Soehl Coolsaet, Roberto Gallardo, Zhen Gao

来源:ARXIV\_20260526

链接:https://arxiv.org/pdf/2605.23962

Abstract : This research aims to leverage machine learning to improve stock price prediction and support informed investment decisions related to buying, selling, and holding assets. Specifically, this work investigates transformer based models for stock prediction and examines the impact of pre training strategies on forecasting performance. A transformer model was first pre trained on the Toronto Stock Exchange Index (TSX) to predict intra day return direction and subsequently fine tuned on individual TSX stocks. The model was further adapted for return value regression tasks. Performance was benchmarked against Long Short Term Memory (LSTM) and XGBoost models. Pre training on the market index improved the binary cross entropy loss for individual stock prediction from 0.69 to 0.64. The fine tuned transformer regression model achieved lower mean squared error than the benchmark models, although the ensemble and XGBoost models achieved higher average daily returns. In addition, a practical application was developed to deliver real time stock predictions for trading support. Future work will focus on increasing transformer model capacity, incorporating broader global technical indicators, and filtering out stocks with low predictability.

Keywords : 

Abstract :这项研究旨在利用机器学习来改善股票价格预测，并支持与购买、出售和持有资产相关的明智投资决策。具体而言，这项工作研究了基于变压器的股票预测模型，并考察了预训练策略对预测绩效的影响。变压器模型首先在多伦多证券交易所指数（TSX）上进行了预训练，以预测日内回报方向，随后对多伦多证券交易所的单个股票进行了微调。该模型进一步适用于返回值回归任务。性能以长短期存储器（LSTM）和XGBoost型号为基准。市场指数的预训练将个股预测的二元交叉熵损失从0.69提高到0.64。微调后的变压器回归模型实现了比基准模型更低的均方误差，尽管集成和XGBoost模型实现了更高的平均日回报。此外，还开发了一个实用的应用程序来提供实时股票预测以支持交易。未来的工作将侧重于增加变压器模型容量，纳入更广泛的全球技术指标，并过滤出可预测性低的库存。

Keywords :

### 

\[5\] Volatility Surface Reconstruction using Deep Learning under No Arbitrage Constraints

标题:无套利约束下基于深度学习的波动面重建

作者:Pablo Rodriguez Manzi

来源:ARXIV\_20260526

链接:https://arxiv.org/pdf/2605.24031

Abstract : We study the reconstruction of implied volatility surfaces from sparse and noisy option quotes using deep learning models under no arbitrage constraints. We compare multiple neural architectures, including multilayer perceptrons, convolutional networks, U Nets, variational autoencoders, and Transformer based models against classical SVI parameterizations on option market data. Results show that Transformer and U Net architectures achieve strong reconstruction accuracy, particularly under sparse observation regimes, while soft arbitrage penalties significantly reduce arbitrage violations with moderate impact on reconstruction error. We further analyze the trade off between accuracy and arbitrage consistency across architectures and regularization strengths.

Keywords : 

Abstract :我们研究了在无套利约束下，使用深度学习模型从稀疏和有噪声的期权报价中重建隐含波动率曲面。我们将多种神经架构（包括多层感知器、卷积网络、U网、变分自编码器和基于Transformer的模型）与期权市场数据上的经典SVI参数化进行了比较。结果表明，Transformer和U-Net架构实现了很强的重建精度，特别是在稀疏观测条件下，而软套利惩罚显著减少了套利违规，对重建误差的影响适中。我们进一步分析了跨架构和正则化强度的准确性和套利一致性之间的权衡。

Keywords :

### 

\[6\] From Accuracy to Auditability

标题:从准确性到可审计性

作者:Ruizhe Zhou, Xiaoyang Liu, Gaoyuan Du, Yi Zheng, Shouxi Ren, Deepayan Chakrabarti, Dengdu Jiang

来源:ARXIV\_20260526

链接:https://arxiv.org/pdf/2605.23955

Abstract : Deploying machine learning in regulated financial environments    credit risk, fraud detection, and anti money laundering    exposes critical vulnerabilities in algorithmic reproducibility. While early financial ML addressed statistical challenges such as backtest overfitting, deep neural networks and Generative AI have introduced mechanical nondeterminism rooted in hardware and architecture. This survey provides a systems perspective on reproducibility failures across three modalities now dominant in financial AI  tabular models (post hoc explanation variance), graph networks (stochastic sampling and temporal asynchrony), and LLM based agentic workflows (batch dependent divergence and trajectory drift). We supplement the literature analysis with first party experiments on public financial datasets    quantifying explanation rank instability in credit scoring, prediction flip rates in GNN based fraud detection, and tensor parallel induced output divergence in LLM entity extraction. We propose a layered evaluation framework linking modality specific metrics (RBO, D cos, TDI, PSD) to audit readiness, and empirically validate the complementarity of logit level and semantic level determinism measures.

Keywords : 

Abstract :在受监管的金融环境中部署机器学习——信用风险、欺诈检测和反洗钱——暴露了算法可重复性的关键漏洞。虽然早期的金融机器学习解决了回溯测试过拟合等统计挑战，但深度神经网络和生成式人工智能引入了植根于硬件和架构的机械不确定性。这项调查提供了一个系统视角，探讨了目前在金融人工智能表格模型（事后解释方差）、图网络（随机抽样和时间异步）和基于LLM的代理工作流程（批量依赖的方差和轨迹漂移）中占主导地位的三种模式的可重复性失败。我们用公共金融数据集的第一方实验来补充文献分析，这些实验量化了信用评分中的解释排名不稳定性、基于GNN的欺诈检测中的预测翻转率以及LLM实体提取中张量并行诱导的输出发散。我们提出了一个分层评估框架，将特定模态的度量（RBO、DCos、TDI、PSD）与审计准备程度联系起来，并实证验证了逻辑级和语义级决定论度量的互补性。

Keywords :

### 

\[7\] Predicting Stock Price Direction on Earnings Announcement Days using Multi modal Deep Learning

标题:利用多模态深度学习预测盈利公告日的股价走势

作者:Manuel Noseda, Nathan Soldati, Marco Paina

来源:ARXIV\_20260526

链接:https://arxiv.org/pdf/2605.25894

Abstract : Predicting stock price movements during Earnings Announcements (EAs) is a significant challenge due to market noise and high impact price discontinuities. In this study, we evaluate whether pre announcement news sentiment, firm fundamentals, and recent market dynamics jointly predict the directional price movement of equities on EA days. We construct a multi modal feature space combining 15 fundamental metrics, 3 price based technical indicators and sentiment scores derived from financial news articles processed using FinBERT. We compare a Long Short Term Memory (LSTM) network and a Transformer based architecture against a logistic regression baseline, and further assess all models with and without sentiment features to quantify their incremental value. Our results indicate that while the LSTM demonstrates higher precision through a conservative safe bet strategy, the Transformer model exhibits superior sensitivity in identifying volatile movements, achieving a higher macro F1 score, with ablation experiments showing a consistent benefit from incorporating news sentiment.

Keywords : 

Abstract :由于市场噪音和高影响价格的不连续性，在收益公告（EA）期间预测股价走势是一项重大挑战。在这项研究中，我们评估了公告前的新闻情绪、公司基本面和最近的市场动态是否共同预测了EA日股票的价格走势。我们构建了一个多模态特征空间，结合了15个基本指标、3个基于价格的技术指标和使用FinBERT处理的金融新闻文章得出的情绪得分。我们将长短期记忆（LSTM）网络和基于Transformer的架构与逻辑回归基线进行比较，并进一步评估所有具有和不具有情感特征的模型，以量化其增量值。我们的结果表明，虽然LSTM通过保守的安全押注策略表现出更高的精度，但Transformer模型在识别波动性运动方面表现出更优的灵敏度，实现了更高的宏观F1得分，消融实验表明，整合新闻情绪具有一致的好处。

Keywords :

### 

\[8\] Multiperiod Groundwater Markets

标题:多期地下水市场

作者:Igor Cialenco, Michael Ludkovski

来源:ARXIV\_20260527

链接:https://arxiv.org/pdf/2605.26363

Abstract : Motivated by the emergence of local groundwater exchanges, we construct and analyze stochastic models of dynamic groundwater markets. Our primary focus is endogenizing the price formation and groundwater pumping strategies in a closed market with stochastic groundwater allocations and opportunities for intertemporal transfer through rights banking. In our model, several agents, interpreted as farmers or agricultural districts, make competitive decisions on water consumption to produce a basket of goods, as well as on trading allocations among themselves, or banking them for future periods. We define the respective discrete time non zero sum non cooperative game and construct its sub game perfect Nash equilibria characterized by the groundwater price process    p  circ(t)   . We furthermore construct an algorithm to determine equilibrium strategies and prices through a machine learning approach on top of best response iterations. Extensive numerical experiments illustrate dynamic phenomena, including the role of groundwater recharge dynamics, agents  risk aversion and groundwater allocations. Our model provides insights into competitive effects in environmental markets with banking features.

Keywords : 

Abstract :受当地地下水交易出现的启发，我们构建并分析了动态地下水市场的随机模型。我们的主要重点是在一个封闭的市场中内生价格形成和地下水开采策略，该市场具有随机的地下水分配和通过权利银行进行跨期转移的机会。在我们的模型中，几个代理人，被解释为农民或农业区，就生产一篮子商品的用水量以及他们之间的交易分配或为未来时期储存水资源做出竞争性决策。我们定义了各自的离散时间非零和非合作博弈，并构建了其子博弈完美纳什均衡，其特征是地下水价格过程pcirc（t）。我们还构建了一个算法，通过机器学习方法在最佳响应迭代的基础上确定均衡策略和价格。大量的数值实验说明了动态现象，包括地下水补给动力学、代理人风险规避和地下水分配的作用。我们的模型提供了具有银行特征的环境市场竞争效应的见解。

Keywords :

### 

\[9\] Nonlinear and Heavy Tailed Predictability in Transition Energy Financial Markets

标题:转型能源金融市场的非线性和重尾可预测性

作者:Kpante Emmanuel Gnandi (INSA Toulouse), Fredy Pokou (MRE, CRIStAL), Jules Sadefo Kamdem (MRE)

来源:ARXIV\_20260527

链接:https://arxiv.org/pdf/2605.26890

Abstract : Transition related financial markets are increasingly exposed to abrupt repricing episodes, elevated volatility, and heterogeneous macro financial shocks. Under such conditions, conventional Gaussian linear forecasting frameworks may provide an incomplete representation of the dependence structure linking fossil energy, renewable energy, technology, and utility sector assets. This paper investigates whether transition related financial returns exhibit residual non linear predictability after controlling for heavy tailed multivariate linear dynamics. To address this question, we develop a hybrid forecasting framework combining Student t Vector Autoregressions with nonlinear recurrent residual learning architectures. The empirical analysis considers six major exchange traded funds representing broad equity markets and key transition sensitive sectors. The results reveal substantial departures from Gaussian linear behavior, including excess kurtosis, volatility clustering, and remaining nonlinear dependence after econometric filtering. Out of sample forecasting experiments show that the proposed framework consistently improves predictive accuracy relative to conventional VAR models, standalone machine learning methods, and alternative hybrid specifications. The forecasting gains become more pronounced during periods of macro financial stress, particularly during the COVID 19 crisis and the Ukraine related energy shock. Overall, the findings suggest that transition related financial systems exhibit regime sensitive and heavy tailed predictive dynamics that are insufficiently captured by standard Gaussian linear models alone.

Keywords : 

Abstract :与转型相关的金融市场越来越容易受到突然重新定价事件、波动加剧和异质性宏观金融冲击的影响。在这种情况下，传统的高斯线性预测框架可能无法完全表示连接化石能源、可再生能源、技术和公用事业部门资产的依赖结构。本文研究了在控制重尾多元线性动力学后，与转型相关的财务回报是否表现出剩余的非线性可预测性。为了解决这个问题，我们开发了一个混合预测框架，将学生向量自回归与非线性循环残差学习架构相结合。实证分析考虑了代表广泛股票市场和关键转型敏感行业的六大交易所交易基金。结果表明，与高斯线性行为存在实质性偏差，包括过度峰度、波动性聚类和计量经济学滤波后的剩余非线性依赖性。样本外预测实验表明，与传统的VAR模型、独立的机器学习方法和替代的混合规范相比，所提出的框架始终如一地提高了预测精度。在宏观金融压力时期，尤其是在2019冠状病毒病危机和乌克兰相关能源冲击期间，预测收益变得更加明显。总体而言，研究结果表明，与转型相关的金融系统表现出对制度敏感和重尾的预测动态，而仅靠标准高斯线性模型无法充分捕捉到这些动态。

Keywords :

### 

\[10\] Regime Based Portfolio Allocation Using Hidden Markov Models and Reinforcement Learning

标题:基于隐马尔可夫模型和强化学习的制度投资组合分配

作者:Ajay Kumar Verma, Nunik Srikandi Putri, Neo Paul Lesupi

来源:ARXIV\_20260528

链接:https://arxiv.org/pdf/2605.27848

Abstract : This study develops a regime aware portfolio allocation framework that integrates Markov switching models with Reinforcement Learning (RL) to dynamically allocate across equities (SPY), long term Treasuries (TLT), and gold (GLD). Using daily ETF data from 2004 2025, we first characterize market behavior through a discrete Markov chain and then estimate a three state Gaussian Hidden Markov Model (HMM) selected by the Bayesian Information Criterion (BIC). The estimated regimes low volatility, transitional, and high volatility exhibit strong persistence and state dependent return dynamics consistent with recent findings on nonlinear market states (Ardia et al., 2024  Gupta & Pierdzioch, 2023). State conditional analysis shows that SPY dominates in stable regimes, while TLT and GLD provide protection during stressed periods, motivating regime conditioned allocation rules.We evaluate rule based rotation and RL driven strategies using a 30  out of sample test window with a one day execution lag to avoid look ahead bias. Both HMM based allocations outperform a passive SPY benchmark, while the RL policy achieves the highest risk adjusted performance, delivering the strongest Sharpe ratio and materially lower drawdowns, yet remains fully interpretable through discrete regime dependent actions. Sensitivity analysis confirms the robustness of the three state specification relative to two state alternatives. Overall, the results demonstrate that RL can systematically enhance HMM based regime detection, providing a transparent, adaptive, and empirically grounded framework for tactical asset allocation. The combined HMM RL system provides a transparent, rules based approach to tactical allocation that improves risk adjusted performance relative to standard benchmark strategies.

Keywords : 

Abstract :本研究开发了一种制度感知的投资组合分配框架，该框架将马尔可夫转换模型与强化学习（RL）相结合，在股票（SPY）、长期国债（TLT）和黄金（GLD）之间动态分配。我们使用2004年至2025年的每日ETF数据，首先通过离散马尔可夫链表征市场行为，然后估计贝叶斯信息准则（BIC）选择的三态高斯隐马尔可夫模型（HMM）。估计的低波动性、过渡性和高波动性制度表现出很强的持续性和状态依赖性回报动态，这与最近关于非线性市场状态的研究结果一致（Ardia等人，2024 Gupta&Pierdzioch，2023）。状态条件分析表明，SPY在稳定制度中占主导地位，而TLT和GLD在压力时期提供保护，激励制度条件分配规则。我们使用30个样本外测试窗口来评估基于规则的轮换和RL驱动策略，该窗口具有一天的执行延迟，以避免前瞻性偏差。这两种基于HMM的分配都优于被动SPY基准，而RL政策实现了最高的风险调整绩效，提供了最强的夏普比率和显著较低的提款率，但仍然可以通过离散的制度依赖行动完全解释。敏感性分析证实了三态规范相对于两态备选方案的稳健性。总体而言，研究结果表明，RL可以系统地增强基于HMM的机制检测，为战术资产配置提供透明、自适应和基于经验的框架。组合的HMM RL系统提供了一种透明的、基于规则的战术分配方法，相对于标准基准策略提高了风险调整后的性能。

Keywords :

### 

\[11\] Deep Learning Forecasting of the U.S. Aggregate Bond Index

标题:美国综合债券指数的深度学习预测

作者:Ajay Kumar Verma, Jul Jon Ramirez General, Yvan Landry Ndzonde Fonkou

来源:ARXIV\_20260528

链接:https://arxiv.org/pdf/2605.27977

Abstract : This study looks at the statistical properties and predictability using deep learning methods of the U.S. aggregate bond index in daily observations spanning 2018 to February 2026. We first establish that index levels are extremely persistent and consistent with unitroot behavior (Dickey and Fuller), while log returns are covariance stationary with weak linear dependence and pronounced volatility clustering characteristic of ARCH type processes (Engle  Bollerslev). Motivated by the trade off between stationarity and information retention, we construct a  stationary but maximally persistent  representation via fractional differencing (Granger and Joyeux  Hosking) following the procedure of L pez de Prado, and evaluate shorthorizon forecast using two neural paradigms  (i) Multilayer Perceptrons (MLPs) trained on lagged vectors with joint lag length and hyperparameter tuning (Hornik et al.  Rumelhart et al.)  and (ii) Convolutional Neural Networks (CNNs) trained on Gramian Angular Field (GAF) image encodings (Wang and Oates). Empirically, MLPs match the strong naive persistence benchmark on levels, collapse toward near zero forecasts on returns, and achieve the strongest incremental performance on the fractionally differenced series, where moderate dependence remains but unit root drift is attenuated. In contrast, CNN GAF models deliver consistently negative out of sample R 2 across all three representations. Overall, the results imply that, for short horizon forecasting of broad bond indices, the primary determinant of predictive performance is the transformation of the series its degree of stationarity and memory rather than architectural complexity. Lag based models remain competitive under persistence, while GAFbased CNNs are better suited to pattern based tasks than to persistence dominated next step prediction.

Keywords : 

Abstract :本研究使用深度学习方法，在2018年至2026年2月的日常观测中研究了美国综合债券指数的统计特性和可预测性。我们首先确定指数水平是极其持久的，与单位根行为一致（Dickey和Fuller），而对数回报是协方差平稳的，具有弱线性依赖性和ARCH型过程的显著波动性聚类特征（Engle-Bollerslev）。受平稳性和信息保留之间权衡的启发，我们按照L pez de Prado的程序，通过分数差分（Granger和Joyeux-Hosking）构建了一个平稳但最大持久的表示，并使用两种神经范式评估短期预测：（i）在具有联合滞后长度和超参数调谐的滞后向量上训练的多层感知器（MLP）（Hornik等人，Rumelhart等人）和（ii）在Gramian角场（GAF）图像编码上训练的卷积神经网络（CNN）（Wang和Oates）。从经验上讲，MLP在水平上与强天真持久性基准相匹配，在回报预测接近零的情况下崩溃，并在分数差分序列上实现最强的增量性能，其中适度的依赖性仍然存在，但单位根漂移减弱。相比之下，CNN-GAF模型在所有三种表示中都提供了一致的负样本外R2。总体而言，结果表明，对于广义债券指数的短期预测，预测性能的主要决定因素是序列的转换——其平稳性和记忆程度，而不是架构复杂性。基于滞后的模型在持久性下仍然具有竞争力，而基于GAF的CNN更适合基于模式的任务，而不是持久性主导的下一步预测。

Keywords :

### 

\[12\] Insurance Pricing Optimization via Off Policy Evaluation

标题:通过保单外评估优化保险定价

作者:Sascha Günther, Dimitri Semenovich, Mario V. Wüthrich

来源:ARXIV\_20260528

链接:https://arxiv.org/pdf/2605.28327

Abstract : Traditional insurance pricing relies on risk based principles that ensure actuarial fairness and solvency but do not explicitly account for policyholders  price sensitivity. We formulate insurance pricing as a decision making problem and study it using tools from off policy evaluation and stochastic control. We propose a kernelized inverse propensity score estimator that exploits local structure in the action space and yields variance reduction compared to the classical inverse propensity score estimator. Building on these value estimates, we investigate policy optimization and present two practical approaches for computing optimal pricing rules  an interpretable data shared Lasso formulation and a flexible policy parameterization based on neural networks. Using a controlled synthetic travel insurance environment, we empirically confirm the theoretical results and show that neural networks outperform existing techniques for policy optimization.

Keywords : 

Abstract :传统的保险定价依赖于基于风险的原则，这些原则确保了精算的公平性和偿付能力，但没有明确考虑投保人的价格敏感性。我们将保险定价视为一个决策问题，并使用保单外评估和随机控制的工具对其进行研究。我们提出了一种核化的逆倾向得分估计器，该估计器利用动作空间中的局部结构，与经典的逆倾向评分估计器相比，可以降低方差。基于这些价值估计，我们研究了政策优化，并提出了两种计算最优定价规则的实用方法——可解释的数据共享Lasso公式和基于神经网络的灵活政策参数化。使用受控的综合旅行保险环境，我们实证证实了理论结果，并表明神经网络在政策优化方面优于现有技术。

Keywords :

### 

\[13\] Financially Guided Deep Portfolio Optimization

标题:财务导向的深度投资组合优化

作者:Rahul Fernandes, Travis Desell

来源:ARXIV\_20260529

链接:https://arxiv.org/pdf/2605.28853

Abstract : Portfolio optimization in real world financial markets is notoriously difficult due to non stationarity, noisy data, and high transaction costs. Standard predict then optimize methods first forecast returns and then solve for weights, compounding prediction errors and often failing under regime shifts. We propose an end to end framework that directly optimizes differentiable surrogates of key financial metrics   Sharpe ratio, Omega ratio, Conditional Value at Risk (CVaR), and Risk Parity   allowing neural networks to learn portfolio weights via backpropagation. Our expanding window walk forward procedure, applied to 50 S&P 500 stocks from 2007 to 2023, incorporates realistic bid ask spread costs and rebalances quarterly. On the challenging out of sample test period (2022 2023), the best model   an AttentionLSTM with the Omega CVaR RiskParity loss   achieves an annualized Sharpe of 0.29 and a total compounded return of  7.86 , while the S&P 500 delivers  4.52  total return and an annualized Sharpe of  0.02. This outperforms the S&P 500 by 12.38 percentage points (a relative improvement of over 270 ), while keeping tail risk (CVaR) nearly unchanged. The framework consistently outperforms the equal weight portfolio, S&P 500, and traditional methods (MVP, HRP, NCO), demonstrating that embedding financial objectives directly into model training yields robust, economically meaningful outperformance even in adverse market conditions.

Keywords : 

Abstract :由于非平稳性、噪声数据和高交易成本，现实世界金融市场中的投资组合优化非常困难。标准预测然后优化方法——首先预测回报，然后求解权重，复合预测误差，在政权更迭下经常失败。我们提出了一个端到端的框架，直接优化关键财务指标的可微分替代品——夏普比率、欧米茄比率、条件风险值（CVaR）和风险平价——允许神经网络通过反向传播学习投资组合权重。我们的扩展窗口向前走程序适用于2007年至2023年的50只标普500指数股票，包括现实的买卖价差成本和季度重新平衡。在具有挑战性的样本外测试期（2022-2023），最佳模型AttentionLSTM的Omega CVaR RiskParity损失实现了0.29的年化夏普和7.86的总复合回报，而标准普尔500指数实现了4.52的总回报和0.02的年化Sharpe。这比标准普尔500指数高出12.38个百分点（相对提高了270多个百分点），同时尾部风险（CVaR）几乎保持不变。该框架的表现始终优于等权重投资组合、标准普尔500指数和传统方法（MVP、HRP、NCO），表明即使在不利的市场条件下，将财务目标直接嵌入模型训练也能产生稳健、具有经济意义的表现。

Keywords :