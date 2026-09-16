# 量化前沿速递：机器学习\[20260524\]

shameless 量化前沿速递 2026-05-25 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489539&idx=4&sn=625222d388a4232fa352caf13c0f97ba&chksm=c3548d9835edfba922793e9b6d5ebe322717ecf3c15db360d49a9a073114f184712e224fd2e8#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489539&idx=4&sn=625222d388a4232fa352caf13c0f97ba&chksm=c3548d9835edfba922793e9b6d5ebe322717ecf3c15db360d49a9a073114f184712e224fd2e8#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Geometric Observables for Financial Regime Detection

金融制度检测的几何可观测值

来源:ARXIV\_20260519

\[2\] Deep Reinforcement Learning Framework for Diversified Portfolio Management Across Global Equity Markets

全球股票市场多元化投资组合管理的深度强化学习框架

来源:ARXIV\_20260519

\[3\] Pegs, Floats, and Forests

飞马、浮舟和森林

来源:ARXIV\_20260519

\[4\] Engagement vs. Commitment

参与与承诺

来源:ARXIV\_20260519

\[5\] Bi Level Chaotic Fusion Based Graph Convolutional Network for Stock Market Prediction Interval

基于双层混沌融合的图卷积网络预测股市区间

来源:ARXIV\_20260519

\[6\] Beyond Sentiment Classification

超越情感分类

来源:ARXIV\_20260519

\[7\] Do Better Volatility Forecasts Lead to Better Portfolios  Evidence from Graph Neural Networks

更好的波动率预测会带来更好的投资组合——来自图神经网络的证据

来源:ARXIV\_20260520

\[8\] External Demand, Domestic Monetary Conditions, and Remittance Dynamics in Nepal

尼泊尔的外部需求、国内货币状况和汇款动态

来源:ARXIV\_20260520

\[9\] Memory Induced Supra Competitive Outcomes Between Deep Reinforcement Learning Agents in Optimal Trade Execution

最优交易执行中深度强化学习代理之间记忆诱导的超竞争结果

来源:ARXIV\_20260521

\[10\] The Statistical Significance of the Inclusion of Graph Neural Networks in the Financial Time Series Forecasting Problem

图神经网络在金融时间序列预测问题中的统计意义

来源:ARXIV\_20260521

\[11\] Position

位置

来源:ARXIV\_20260522

\[12\] A Generative Adversarial Graph Neural Network for Synthetic Time Series Data

用于合成时间序列数据的生成对抗图神经网络

来源:ARXIV\_20260522

### 

\[1\] Geometric Observables for Financial Regime Detection

标题:金融制度检测的几何可观测值

作者:Will Hammond

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.17117

Abstract : We extract four geometric observables    Berry Phase Rate, Spectral Entropy, Reduced State Purity, and Hamiltonian Sensitivity    from a learned spectral embedding of equity index returns and evaluate them as regime shift detectors against 46 classical and machine learning baselines on 17 historical crises spanning 2000 2024. Under walk forward nested hyperparameter selection on nine labelled windows, the Berry Phase Rate achieves an unbiased out of sample median Cohen s  d   0.72  (95  percentile bootstrap CI   0.34, 1.18  , 10,000 resamples) and produces approximately 67  fewer false alarms per year than a label supervised Random Forest (1.2 vs. 3.6 per year). Reduced State Purity attains the highest in sample separability of any method ( d   0.83 ), tied closely by the Absorption Ratio ( d   0.80 )  geometric and classical channels are largely uncorrelated (mean    rho   approx 0.22 ), suggesting they capture distinct risk signals. Score construction is unsupervised  hyperparameter selection is the only supervised step.

Keywords : 

Abstract :我们从股票指数回报的学习谱嵌入中提取了四个几何可观测值——Berry相位率、谱熵、约化态纯度和哈密顿灵敏度，并将其作为政权转移检测器，在2000年至2024年的17次历史危机中，对46个经典和机器学习基线进行评估。在九个标记窗口上的向前走嵌套超参数选择下，Berry相位率实现了无偏的样本外中值Cohen s d 0.72（95%自举CI 0.34、1.18、10000重采样），每年产生的误报比标签监督的随机森林少约67个（每年1.2对3.6）。还原态纯度在任何方法中都达到了最高的样本可分性（d 0.83），与吸收比（d 0.80）密切相关。几何和经典通道在很大程度上是不相关的（平均ρ约为0.22），这表明它们捕获了不同的风险信号。分数构建是无监督的，超参数选择是唯一有监督的步骤。

Keywords :

### 

\[2\] Deep Reinforcement Learning Framework for Diversified Portfolio Management Across Global Equity Markets

标题:全球股票市场多元化投资组合管理的深度强化学习框架

作者:Kamil Kashif, Robert Ślepaczuk

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.17307

Abstract : This study develops and evaluates a deep reinforcement learning framework for dynamic portfolio allocation across global equity markets. The Soft Actor Critic algorithm is used to learn continuous portfolio weights within a Markov Decision Process, incorporating transaction costs, turnover penalties, and diversification constraints into the reward function. Five model configurations are compared, varying in reward formulation, policy structure (flat versus hierarchical Dirichlet), portfolio constraints, and temporal encoder (LSTM versus Transformer), and evaluated via walk forward optimization across sixteen out of sample folds spanning 2003 2026 on the Nasdaq 100, Nikkei 225, and Euro Stoxx 50. Results show that RL strategies achieve competitive risk adjusted performance primarily in the Euro Stoxx 50, where statistically significant abnormal returns are observed, but the central hypothesis is only partially confirmed  no strategy achieves statistically significant excess returns relative to Buy and Hold under HAC robust inference across all markets. Regime analysis reveals that RL adds the most value during periods of elevated uncertainty, while ensemble aggregation across markets improves risk adjusted performance and confirms the benefits of geographic diversification.

Keywords : 

Abstract :本研究开发并评估了一个用于全球股票市场动态投资组合分配的深度强化学习框架。软行动者批判算法用于在马尔可夫决策过程中学习连续的投资组合权重，将交易成本、营业额惩罚和多样化约束纳入奖励函数。对五种模型配置进行了比较，这些配置在奖励制定、政策结构（扁平与分层Dirichlet）、投资组合约束和时间编码器（LSTM与Transformer）方面各不相同，并通过在纳斯达克100指数、日经225指数和欧洲斯托克50指数上跨越2003年至2026年的16个样本外折叠的前向优化进行了评估。结果表明，强化学习策略主要在欧洲斯托克50指数中实现了竞争性风险调整后的绩效，在该指数中观察到统计上显著的异常回报，但中心假设仅得到部分证实，在所有市场的HAC稳健推断下，没有一种策略实现了相对于买入并持有的统计学上显著的超额回报。制度分析表明，RL在不确定性增加的时期增加了最大的价值，而跨市场的集合聚合提高了风险调整后的绩效，并证实了地理多样化的好处。

Keywords :

### 

\[3\] Pegs, Floats, and Forests

标题:飞马、浮舟和森林

作者:Marjan Petreski

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.17391

Abstract : This paper combines traditional panel econometrics with random forest machine learning to revisit the relationship between exchange rate regimes and economic growth for 27 transition economies over 1991 2019. Exploiting the Couharde Grekou (2024) probabilistic synthesis classification, the random forest approach non parametrically confirms and sharpens what fixed effects and system GMM estimation establish parametrically intermediate exchange rate regimes consistently underperform fixed arrangements, with growth penalties ranging from  1.0 to  10.4 percentage points, while floating regimes show negative but largely insignificant differentials. Beyond regime effects, the machine learning analysis reveals that the intermediate regime penalty is sharpest precisely where institutions are weakest   non parametric validation that institutional capacity, not regime label alone, determines whether exchange rate anchoring pays off. The regime growth relationship is further concentrated in the pre 2003 stabilization era and is absent among EU member economies, suggesting the growth dividend from exchange rate anchoring eroded as institutional convergence advanced. Together, these findings demonstrate how machine learning variable importance metrics can corroborate and enrich causal inference from panel methods, while supporting the view that exchange rate anchoring carried a meaningful credibility dividend during the formative phase of transition.

Keywords : 

Abstract :本文将传统的面板计量经济学与随机森林机器学习相结合，重新审视了1991年至2019年间27个转型经济体的汇率制度与经济增长之间的关系。利用Couharde-Grekou（2024）的概率综合分类，随机森林方法非参数地确认并锐化了固定效应和系统GMM估计所建立的参数化中间汇率制度一直不如固定安排，增长惩罚在1.0到10.4个百分点之间，而浮动制度显示出负的但基本上不显著的差异。除了制度效应外，机器学习分析表明，中间制度惩罚最严重的地方恰恰是制度最薄弱的非参数验证，即制度能力，而不仅仅是制度标签，决定了汇率锚定是否有回报。制度增长关系进一步集中在2003年前的稳定时代，在欧盟成员国经济体中并不存在，这表明随着制度趋同的推进，汇率锚定的增长红利受到侵蚀。这些发现共同证明了机器学习变量重要性指标如何证实和丰富面板方法的因果推理，同时支持汇率锚定在转型形成阶段带来有意义的可信度红利的观点。

Keywords :

### 

\[4\] Engagement vs. Commitment

标题:参与与承诺

作者:Shunyao Yan, Klaus M. Miller

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.18357

Abstract : Content that drives engagement need not be the same content that drives willingness to pay. We study how polarizing content affects engagement (time on site) and commitment (subscriptions and retention) on a major news platform. We measure article level polarization with deep learning classifiers and large language models tailored to a multiparty system, and identify causal effects with two complementary instrumental variables  a Bartik instrument exploiting supply side editorial variation, and an election instrument exploiting demand side political salience. We find that supply driven increases in polarizing content raise engagement but not subscriptions. During the high salience election window, the same content reduces subscriptions and accelerates churn, with affective polarization driving the sharpest divergence. On the mechanism, we find evidence inconsistent with confirmation bias  three pre determined ideology proxies do not moderate the engagement or subscription effects. By contrast, on ideological dimensions where the publisher covers both sides, exogenous shifts in the publisher s supply of content opposite readers  baseline ideology raise their consumption of that content, consistent with balanced consumption. These results document an asymmetric engagement commitment trade off for digital publishers  polarizing content reliably captures attention but does not convert to subscriptions, and actively damages commitment when political salience is elevated

Keywords : 

Abstract :推动参与度的内容不一定与推动支付意愿的内容相同。我们研究两极分化的内容如何影响主要新闻平台上的参与度（网站时间）和承诺度（订阅和保留）。我们使用深度学习分类器和为多党制量身定制的大型语言模型来衡量文章层面的两极分化，并使用两个互补的工具变量来识别因果效应——一个利用供给侧编辑差异的Bartik工具，一个利用需求侧政治显著性的选举工具。我们发现，供应驱动的两极分化内容的增加会提高参与度，但不会提高订阅率。在高显著性选举窗口期间，相同的内容减少了订阅并加速了流失，情感两极分化导致了最大的分歧。在机制上，我们发现与确认偏差不一致的证据——三个预先确定的意识形态代理并没有调节参与或订阅效应。相比之下，在出版商涵盖双方的意识形态维度上，出版商内容供应的外生变化与读者的基线意识形态相反，提高了他们对该内容的消费，与均衡消费相一致。这些结果记录了数字出版商不对称的参与承诺权衡——两极分化的内容可靠地吸引了注意力，但不会转化为订阅，并在政治重要性提高时积极损害承诺

Keywords :

### 

\[5\] Bi Level Chaotic Fusion Based Graph Convolutional Network for Stock Market Prediction Interval

标题:基于双层混沌融合的图卷积网络预测股市区间

作者:Eshwar Sai Kandimalla, Sravan Chowdary Kankanala, Sumana Bhimineni, Hem Sundhar Korukunda, Vivek Yelleti

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.16324

Abstract : Financial market forecasting is inherently uncertain, yet most deep learning approaches rely on point predictions that provide only single value estimates without quantifying uncertainty. Such predictions are insufficient for risk aware decision making, as they fail to capture the range of possible outcomes and the associated confidence of this http URL problem can be solved using prediction intervals, which allow obtaining an upper and lower bound for the prediction, thus enabling uncertainty representation in the model. Yet, the current methods tend to disregard relationships between assets or cannot simultaneously ensure good calibration and sharpness of the resulting intervals in dynamically changing market regimes. In our work, we propose a spatio temporal graph based approach with a bi level chaotic fusion technique to solve this problem. Our model uses separate nonlinear transformation functions to estimate the interval center and width. Additionally, a volatility aware gating mechanism is used to make predictions dependent on the regime in which the market operates. Temporal dependencies are considered by embedding graph structures and sequentially modeling them. Training is conducted according to a Lower Upper Bound Estimation (LUBE) objective. Our experimental results show significant improvements compared to existing baselines (LSTM, GRU, GCN, HGNN) when applied to data from 2016 to 2026 with 43 leading companies in eight sectors of the NSE. It provides the lowest Winkler score (0.0778), tightest prediction intervals (PIAW   0.1407), and highest coverage (PICP   96.6 ), with all differences statistically significant (p   0.001) according to the Diebold Mariano test.

Keywords : 

Abstract :金融市场预测本质上是不确定的，但大多数深度学习方法都依赖于点预测，这些点预测只提供单一值估计，而不量化不确定性。这种预测不足以进行风险意识决策，因为它们无法捕捉到可能结果的范围，并且可以使用预测区间来解决此http URL问题的相关置信度，这允许获得预测的上限和下限，从而在模型中实现不确定性表示。然而，目前的方法往往忽视资产之间的关系，或者不能同时确保在动态变化的市场制度中得到的区间的良好校准和锐度。在我们的工作中，我们提出了一种基于时空图的方法，该方法采用双层混沌融合技术来解决这个问题。我们的模型使用单独的非线性变换函数来估计区间中心和宽度。此外，使用波动感知门控机制来根据市场运行的制度进行预测。通过嵌入图结构并对其进行顺序建模来考虑时间依赖性。根据下限上限估计（LUBE）目标进行训练。我们的实验结果表明，与现有基线（LSTM、GRU、GCN、HGNN）相比，当应用于2016年至2026年的数据时，NSE八个部门的43家领先公司的数据有了显著改善。它提供了最低的Winkler评分（0.0778）、最严格的预测区间（PIAW 0.1407）和最高的覆盖率（PICP 96.6），根据Diebold-Mariano检验，所有差异都具有统计学意义（p 0.001）。

Keywords :

### 

\[6\] Beyond Sentiment Classification

标题:超越情感分类

作者:Francesco A. Fabozzi, Dasol Kim, William N. Goetzmann

来源:ARXIV\_20260519

链接:https://arxiv.org/pdf/2605.16613

Abstract : We introduce a novel approach to emotion modeling that shifts the focus fromidentification to evaluation, addressing the limitations of discrete classification inapplied domains such as finance. By constructing a dataset of emotional intensityscores and fine tuning open weight generative language models to output continuousvalues from 0 100, we demonstrate a more expressive, generalizable framework forsentiment and emotion analysis. Our findings not only outperform classificationbaselines but also reveal surprising generalization capabilities and transfer effectsto related constructs such as sentiment and arousal. This work contributes to theinterdisciplinary recontextualization of NLP by introducing emotion intensityevaluation as an alternative to classification, arguing that this shift better alignswith the needs of domains  such as finance  where the degree of emotional content iscentral to interpretation and decision making.

Keywords : 

Abstract :我们介绍了一种新的情感建模方法，将重点从识别转移到评估，解决了离散分类在金融等应用领域的局限性。通过构建情感强度核心数据集并微调开放权重生成语言模型以输出从0到100的连续值，我们展示了一个更具表现力、更通用的情感分析框架。我们的研究结果不仅优于分类基线，而且揭示了令人惊讶的泛化能力和对情绪和唤醒等相关结构的转移效应。这项工作通过引入情感强度评估作为分类的替代方法，为NLP的跨学科再语境化做出了贡献，认为这种转变更好地符合金融等领域的需求，在这些领域，情感内容的程度与解释和决策有关。

Keywords :

### 

\[7\] Do Better Volatility Forecasts Lead to Better Portfolios  Evidence from Graph Neural Networks

标题:更好的波动率预测会带来更好的投资组合——来自图神经网络的证据

作者:Rylan Wade

来源:ARXIV\_20260520

链接:https://arxiv.org/pdf/2605.19278

Abstract : This paper tests whether graph neural networks improve realized volatility forecasts and whether those forecasts improve portfolio performance. Using weekly realized volatility for 465 S &P 500 equities from 2015  2025, Heterogeneous Autoregressive and Long Short Term Memory baselines are compared against GraphSAGE models built on rolling correlation, sector, and Granger causal graphs, with and without macro regime features. The empirical finding is that the model with the lowest forecast MSE, the model with the highest cross sectional ranking accuracy, and the model with the highest portfolio Sharpe ratio are three different models. Forecast accuracy, ranking quality, and portfolio performance are related but not interchangeable objectives. Graph volatility models add value only when the portfolio rule can exploit the cross sectional structure they encode.

Keywords : 

Abstract :本文检验了图神经网络是否改善了已实现波动率预测，以及这些预测是否改善了投资组合绩效。使用2015年至2025年465只标普500指数股票的每周实际波动率，将异质自回归和长期短期记忆基线与基于滚动相关性、行业和格兰杰因果图的GraphSAGE模型进行比较，有和没有宏观制度特征。实证发现，具有最低预测MSE的模型、具有最高横截面排名精度的模型和具有最高投资组合夏普比率的模型是三种不同的模型。预测准确性、排名质量和投资组合绩效是相互关联但不可互换的目标。只有当投资组合规则能够利用它们编码的横截面结构时，图波动率模型才有价值。

Keywords :

### 

\[8\] External Demand, Domestic Monetary Conditions, and Remittance Dynamics in Nepal

标题:尼泊尔的外部需求、国内货币状况和汇款动态

作者:Sahaj Raj Malla

来源:ARXIV\_20260520

链接:https://arxiv.org/pdf/2605.19401

Abstract : This study investigates the macroeconomic determinants and dynamic behaviour of personal remittances as a share of Gross Domestic Product (GDP) in Nepal, emphasizing external demand in major destination countries and domestic monetary policy. Using annual data (1993 2024), we construct composite indices via Principal Component Analysis (PCA) for multi country external demand and a domestic Monetary Conditions Index (MCI). Our small sample econometric pipeline includes Autoregressive Distributed Lag (ARDL) bounds testing, Engle Granger cointegration, Dynamic OLS (DOLS), and a two step Error Correction Model (ECM). We also employ Granger causality tests and multi model forecasting using machine learning and ECM scenarios. The analysis reveals a strong positive long run effect of external demand on remittances and a significant negative impact of tighter domestic monetary conditions. The ECM confirms a stable cointegrating relationship, correcting approximately 26  of disequilibria annually. Medium term projections indicate remittances will remain structurally important, reaching around 28.3  of GDP by 2030 under baseline conditions, while exhibiting high sensitivity to external demand shocks. This study advances the literature by integrating PCA derived external demand and monetary conditions indices within a unified ARDL ECM framework for small samples. Focusing on one of the world s most remittance dependent economies, it offers actionable insights for monetary policy calibration, migration diversification, and the productive utilization of remittance inflows.

Keywords : 

Abstract :本研究调查了尼泊尔个人汇款占国内生产总值（GDP）的宏观经济决定因素和动态行为，强调了主要目的地国家的外部需求和国内货币政策。基于1993年至2024年的年度数据，我们通过主成分分析（PCA）构建了多国外部需求的综合指数和国内货币状况指数（MCI）。我们的小样本计量经济学管道包括自回归分布滞后（ARDL）边界检验、恩格尔-格兰杰协整、动态OLS（DOLS）和两步误差校正模型（ECM）。我们还使用格兰杰因果关系检验和使用机器学习和ECM场景的多模型预测。分析显示，外部需求对汇款有强烈的长期积极影响，而国内货币环境收紧则有显著的负面影响。ECM确认了稳定的协整关系，每年纠正约26个不平衡。中期预测表明，汇款在结构上仍然很重要，在基线条件下，到2030年将达到国内生产总值的28.3左右，同时对外部需求冲击表现出高度敏感性。本研究通过在小样本的统一ARDL ECM框架内整合PCA衍生的外部需求和货币状况指数，推进了文献研究。它专注于世界上最依赖汇款的经济体之一，为货币政策校准、移民多样化和汇款流入的生产性利用提供了可操作的见解。

Keywords :

### 

\[9\] Memory Induced Supra Competitive Outcomes Between Deep Reinforcement Learning Agents in Optimal Trade Execution

标题:最优交易执行中深度强化学习代理之间记忆诱导的超竞争结果

作者:Christos Spyridon Koulouris, Carlo Campajola

来源:ARXIV\_20260521

链接:https://arxiv.org/pdf/2605.20348

Abstract : In this paper, we investigate whether deep reinforcement learning agents interacting in a shared optimal execution environment can sustain supra competitive outcomes, in the sense of achieving lower implementation shortfalls than the relevant game theoretical competitive benchmark. We study a two agent Almgren Chriss liquidation game and examine how learned behavior depends on intra episode environment feedback, the ability to interpret the mid price and the agent s knoledge of the past. We first use ex ante schedule learning agents to remove intra episode feedback and isolate what can arise when agents commit to complete liquidation trajectories before execution begins. We then allow agents to condition on the evolving state using a variety of DDQN architectures. We find that, when agents are given access to intra episode history, especially recent prices and own past actions, supra competitive outcomes become substantially more frequent and more persistent. These findings indicate that supra competitive behavior in this execution game is driven not by multi agent learning or by current price observation alone, but by feedback, memory, and state contingent interaction along the realized execution path.

Keywords : 

Abstract :在本文中，我们研究了在共享最优执行环境中交互的深度强化学习代理是否可以维持超竞争结果，即实现比相关博弈论竞争基准更低的实施不足。我们研究了一个双代理Almgren-Chriss清算博弈，并研究了学习行为如何取决于事件内环境反馈、解释中间价格的能力和代理过去的知识。我们首先使用事前调度学习代理来消除事件内的反馈，并隔离代理在执行开始前承诺完成清算轨迹时可能出现的情况。然后，我们允许代理使用各种DDQN架构对不断发展的状态进行调节。我们发现，当代理人可以访问事件内的历史记录，特别是最近的价格和自己过去的行为时，超竞争结果会变得更加频繁和持久。这些发现表明，这种执行游戏中的超竞争行为不是由多智能体学习或仅由当前价格观察驱动的，而是由沿着实现的执行路径的反馈、记忆和状态相关交互驱动的。

Keywords :

### 

\[10\] The Statistical Significance of the Inclusion of Graph Neural Networks in the Financial Time Series Forecasting Problem

标题:图神经网络在金融时间序列预测问题中的统计意义

作者:Marco Gregnanin, Johannes De Smedt, Giorgio Gnecco, Maurizio Parton

来源:ARXIV\_20260521

链接:https://arxiv.org/pdf/2605.21192

Abstract : Forecasting univariate time series in the financial market is a challenging endeavor. While numerous statistical and machine learning models have been introduced to address this challenge, they typically concentrate solely on analyzing temporal patterns within the time series data. In this research, we study the statistical significance of the inclusion of geometric patterns in enhancing forecasting accuracy within the context of time series analysis. We introduce the Time Geometric model, a combination of models designed to exploit both geometric and temporal patterns. The contribution of this research lies in advancing the domain of univariate time series prediction,as demonstrated through extensive empirical evaluations. Our findings underscore that leveraging geometric patterns, captured through Graph Neural Networks, yields statistically significant improvements in forecasting accuracy.

Keywords : 

Abstract :预测金融市场中的单变量时间序列是一项具有挑战性的工作。虽然已经引入了许多统计和机器学习模型来解决这一挑战，但它们通常只专注于分析时间序列数据中的时间模式。在这项研究中，我们研究了在时间序列分析的背景下，纳入几何模式在提高预测准确性方面的统计意义。我们介绍了时间几何模型，这是一种旨在利用几何和时间模式的模型组合。这项研究的贡献在于推进了单变量时间序列预测的领域，正如通过广泛的实证评估所证明的那样。我们的研究结果强调，利用通过图神经网络捕获的几何模式，可以在预测准确性方面取得统计学上的显著提高。

Keywords :

### 

\[11\] Position

标题:位置

作者:Dirk Bergemann, Soheil Ghili, Nitzan Mekel-Bobrov

来源:ARXIV\_20260522

链接:https://arxiv.org/pdf/2605.22632

Abstract : Industry academia ML collaborations routinely fail to launch    not for scientific reasons, but because academics must publish while companies must protect models trained on proprietary data, and no standard contract framework resolves this tension. Because contracts are negotiated by legal departments alone, many apparent legal disputes are incentive misalignment problems that only scientists at the table can correctly diagnose. We propose PBOS (Protect the Business   Open Source the Science), a community adoptable contract template anchored to a single technically grounded boundary  pre training artifacts (architectures, training code, benchmarks, untrained weights) are open science  post training artifacts (weights trained on proprietary data) are business IP. This boundary is technically meaningful, legally clean, and auditable    and could not have been drawn correctly without scientists at the negotiating table. We argue the ML community should adopt PBOS as its default contract for such collaborations.

Keywords : 

Abstract :产学界机器学习合作经常失败，不是因为科学原因，而是因为学术界必须发表论文，而公司必须保护基于专有数据训练的模型，没有标准的合同框架可以解决这种紧张关系。由于合同是由法律部门单独谈判的，许多明显的法律纠纷都是激励错位问题，只有在座的科学家才能正确诊断。我们提出PBOS（保护商业开源科学），这是一个社区可采用的合同模板，锚定在一个单一的技术基础边界上，预训练工件（架构、训练代码、基准、未训练的权重）是开放科学，后训练工件（在专有数据上训练的重量）是商业IP。这一边界在技术上是有意义的、法律上是干净的、可审计的，如果没有科学家坐在谈判桌上，就不可能正确地划定。我们认为机器学习社区应该采用PBOS作为此类合作的默认合同。

Keywords :

### 

\[12\] A Generative Adversarial Graph Neural Network for Synthetic Time Series Data

标题:用于合成时间序列数据的生成对抗图神经网络

作者:Marco Gregnanin, Johannes De Smedt, Giorgio Gnecco, Maurizio Parton

来源:ARXIV\_20260522

链接:https://arxiv.org/pdf/2605.22215

Abstract : Generating synthetic data for financial time series poses challenges, especially considering their non stationary nature. Traditional statistical time series models normally assume weak stationarity. However, this assumption can constrain their effectiveness. Deep learning models, particularly Generative Adversarial Networks (GANs), have exhibited considerable potential in emulating complex probability distributions. GANs employ a generator discriminator framework, where the generator creates data samples, while the discriminator distinguishes real from generated data. In this research, we introduce the Sig Graph GAN model, which integrates the time series signature, offering a structured summary of its temporal evolution  the Long Short Term Memory network, capturing its inherent autoregressive structure  and Graph Neural Networks (GNNs), leveraging geometric patterns within the time series data. To employ GNNs optimally, we use the visibility graph algorithm to derive a graph based representation of the underlying time series. Numerical evaluations demonstrate that the Sig Graph GAN model outperforms baseline methods in replicating the distribution of logarithmic returns across different stock exchanges. The integration of the graph structure with the autoregressive component effectively captures both geometric and temporal patterns embedded in time series data. This research advances the field of GAN models for time series by introducing a model capable of leveraging both autoregressive properties and geometric structures for synthetic data generation.

Keywords : 

Abstract :为金融时间序列生成合成数据带来了挑战，特别是考虑到它们的非平稳性。传统的统计时间序列模型通常假设弱平稳性。然而，这种假设可能会限制其有效性。深度学习模型，特别是生成对抗网络（GAN），在模拟复杂的概率分布方面表现出了相当大的潜力。GAN采用生成器鉴别器框架，生成器创建数据样本，鉴别器区分真实数据和生成的数据。在这项研究中，我们引入了Sig-Graph GAN模型，该模型整合了时间序列特征，对其时间演化提供了结构化的总结——长短期记忆网络，捕捉了其固有的自回归结构和图神经网络（GNN），利用了时间序列数据中的几何模式。为了最佳地使用GNN，我们使用可见性图算法来推导底层时间序列的基于图的表示。数值评估表明，Sig-Graph-GAN模型在复制不同证券交易所的对数回报分布方面优于基线方法。图结构与自回归分量的集成有效地捕获了时间序列数据中嵌入的几何和时间模式。本研究通过引入一种能够利用自回归特性和几何结构生成合成数据的模型，推进了时间序列GAN模型领域的发展。

Keywords :