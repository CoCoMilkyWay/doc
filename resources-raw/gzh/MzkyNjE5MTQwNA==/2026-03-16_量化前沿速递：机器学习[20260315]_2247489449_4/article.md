# 量化前沿速递：机器学习\[20260315\]

shameless 量化前沿速递 2026-03-16 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489449&idx=4&sn=b4dc0d24c0807e132450c0538ce1d83b&chksm=c389418a0f7ddb1acf652610e693229a2889aba65f60908009f903483fe1f6eab96e914bd316#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489449&idx=4&sn=b4dc0d24c0807e132450c0538ce1d83b&chksm=c389418a0f7ddb1acf652610e693229a2889aba65f60908009f903483fe1f6eab96e914bd316#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Stock Market Prediction Using Node Transformer Architecture Integrated with BERT Sentiment Analysis

基于节点变换器架构与BERT情绪分析的股市预测

来源:ARXIV\_20260309

\[2\] Calibrated Credit Intelligence

校准信用情报

来源:ARXIV\_20260310

\[3\] Differential Machine Learning for 0DTE Options with Stochastic Volatility and Jumps

具有随机波动和跳跃的0DTE期权的微分机器学习

来源:ARXIV\_20260310

\[4\] Autonomous AI Agents for Option Hedging

用于期权对冲的自主人工智能代理

来源:ARXIV\_20260310

\[5\] A Survey of Reinforcement Learning For Economics

经济学强化学习研究综述

来源:ARXIV\_20260311

\[6\] Uncertainty Aware Deep Hedging

不确定性意识深度对冲

来源:ARXIV\_20260312

\[7\] An operator level ARCH Model

操作员级ARCH模型

来源:ARXIV\_20260312

\[8\] A Bipartite Graph Approach to U.S. China Cross Market Return Forecasting

中美跨市场收益预测的二分图方法

来源:ARXIV\_20260312

\[9\] Beyond Polarity

超越极性

来源:ARXIV\_20260313

\[10\] Managing Cognitive Bias in Human Labeling Operations for Rare Event AI

管理罕见事件人工智能人类标记操作中的认知偏差

来源:ARXIV\_20260313

\[11\] Increasing intelligence in AI agents can worsen collective outcomes

人工智能智能智能的提高可能会恶化集体结果

来源:ARXIV\_20260313

### 

\[1\] Stock Market Prediction Using Node Transformer Architecture Integrated with BERT Sentiment Analysis

标题:基于节点变换器架构与BERT情绪分析的股市预测

作者:Mohammad Al Ridhawi, Mahtab Haj Ali, Hussein Al Osman

来源:ARXIV\_20260309

链接:https://arxiv.org/pdf/2603.05917

Abstract : Stock market prediction presents considerable challenges for investors, financial institutions, and policymakers operating in complex market environments characterized by noise, non stationarity, and behavioral dynamics. Traditional forecasting methods often fail to capture the intricate patterns and cross sectional dependencies inherent in financial markets. This paper presents an integrated framework combining a node transformer architecture with BERT based sentiment analysis for stock price forecasting. The proposed model represents the stock market as a graph structure where individual stocks form nodes and edges capture relationships including sectoral affiliations, correlated price movements, and supply chain connections. A fine tuned BERT model extracts sentiment from social media posts and combines it with quantitative market features through attention based fusion. The node transformer processes historical market data while capturing both temporal evolution and cross sectional dependencies among stocks. Experiments on 20 S&P 500 stocks spanning January 1982 to March 2025 demonstrate that the integrated model achieves a mean absolute percentage error (MAPE) of 0.80  for one day ahead predictions, compared to 1.20  for ARIMA and 1.00  for LSTM. Sentiment analysis reduces prediction error by 10  overall and 25  during earnings announcements, while graph based modeling contributes an additional 15  improvement by capturing inter stock dependencies. Directional accuracy reaches 65  for one day forecasts. Statistical validation through paired t tests confirms these improvements (p   0.05 for all comparisons). The model maintains MAPE below 1.5  during high volatility periods where baseline models exceed 2 .

Keywords : 

Abstract :股票市场预测给投资者、金融机构和政策制定者带来了相当大的挑战，他们在以噪音、非平稳性和行为动态为特征的复杂市场环境中运作。传统的预测方法往往无法捕捉到金融市场固有的复杂模式和横截面依赖关系。本文提出了一种将节点变换器架构与基于BERT的情绪分析相结合的股票价格预测集成框架。所提出的模型将股票市场表示为一种图形结构，其中单个股票形成节点，边捕获关系，包括部门隶属关系、相关价格变动和供应链连接。微调的BERT模型从社交媒体帖子中提取情绪，并通过基于注意力的融合将其与定量市场特征相结合。节点转换器处理历史市场数据，同时捕获股票之间的时间演变和横截面依赖关系。1982年1月至2025年3月，对20只标准普尔500指数股票的实验表明，综合模型在一天预测中的平均绝对百分比误差（MAPE）为0.80，而ARIMA为1.20，LSTM为1.00。情绪分析总体上将预测误差降低了10，在收益公告期间降低了25，而基于图的建模通过捕捉股票间的依赖关系，又提高了15。一天预报的方向精度达到65。通过配对t检验的统计验证证实了这些改善（所有比较的p值均为0.05）。在基线模型超过2的高波动期，该模型将MAPE保持在1.5以下。

Keywords :

### 

\[2\] Calibrated Credit Intelligence

标题:校准信用情报

作者:Srikumar Nayak

来源:ARXIV\_20260310

链接:https://arxiv.org/pdf/2603.06733

Abstract : Credit risk scoring must support high stakes lending decisions where data distributions change over time, probability estimates must be reliable, and group level fairness is required. While modern machine learning models improve default prediction accuracy, they often produce poorly calibrated scores under distribution shift and may create unfair outcomes when trained without explicit constraints. This paper proposes Calibrated Credit Intelligence (CCI), a deployment oriented framework that combines (i) a Bayesian neural risk scorer to capture epistemic uncertainty and reduce overconfident errors, (ii) a fairnessconstrained gradient boosting model to control group disparities while preserving strong tabular performance, and (iii) a shiftaware fusion strategy followed by post hoc probability calibration to stabilize decision thresholds in later time periods. We evaluate CCI on the Home Credit Credit Risk Model Stability benchmark using a time consistent split to reflect real world drift. Compared with strong baselines (LightGBM, XGBoost, CatBoost, TabNet, and a standalone Bayesian neural model), CCI achieves the best overall trade off between discrimination, calibration, stability, and fairness. In particular, CCI reaches an AUC ROC of 0.912 and an AUC PR of 0.438, improves operational performance with Recall 1 FPR   0.509, and reduces calibration error (Brier score 0.087, ECE 0.015). Under temporal shift, CCI shows a smaller AUC PR drop from early to late periods (0.017), and it lowers group disparities (demographic parity gap 0.046, equal opportunity gap 0.037) compared to unconstrained boosting. These results indicate that CCI produces risk scores that are accurate, reliable, and more equitable under realistic deployment conditions.

Keywords : 

Abstract :信用风险评分必须支持高风险贷款决策，其中数据分布随时间变化，概率估计必须可靠，并且需要集团层面的公平性。虽然现代机器学习模型提高了默认预测的准确性，但它们在分布偏移下通常会产生校准不佳的分数，并且在没有明确约束的情况下进行训练时可能会产生不公平的结果。本文提出了校准信用情报（CCI），这是一种面向部署的框架，它结合了（i）贝叶斯神经风险评分器来捕捉认知不确定性并减少过度自信错误，（ii）公平约束梯度提升模型来控制组差异，同时保持强大的表格性能，以及（iii）shiftaware融合策略，然后进行事后概率校准，以稳定后期的决策阈值。我们使用时间一致性分割来评估家庭信贷风险模型稳定性基准上的CCI，以反映现实世界的漂移。与强基线（LightGBM、XGBoost、CatBoost、TabNet和独立的贝叶斯神经模型）相比，CCI在区分、校准、稳定性和公平性之间实现了最佳的整体权衡。特别是，CCI达到0.912的AUC ROC和0.438的AUC PR，提高了Recall 1 FPR 0.509的操作性能，并减少了校准误差（Brier评分0.087，ECE 0.015）。在时间变化下，CCI从早期到晚期的AUC PR下降较小（0.017），与无约束增强相比，它降低了群体差异（人口均等差距0.046，机会均等差距0.037）。这些结果表明，CCI产生的风险评分在现实部署条件下是准确、可靠和更公平的。

Keywords :

### 

\[3\] Differential Machine Learning for 0DTE Options with Stochastic Volatility and Jumps

标题:具有随机波动和跳跃的0DTE期权的微分机器学习

作者:Takayuki Sakuma

来源:ARXIV\_20260310

链接:https://arxiv.org/pdf/2603.07600

Abstract : We present a differential machine learning method for zero days to expiry (0DTE) options under a stochastic volatility jump diffusion model that computes prices and Greeks in a single network evaluation. To handle the ultra short maturity regime, we represent the price in Black  Scholes form with a maturity gated variance correction, and combine supervision on prices and Greeks with a PIDE residual penalty. To make the jump contribution identifiable, we introduce a separate jump operator network and train it with a three stage procedure. In Bates model simulations, the method improves jump term approximation relative to one stage baselines, keeps price errors close to one stage alternatives while improving Greeks accuracy, produces stable one day delta hedges, and is substantially faster than a Fourier based pricing benchmark.

Keywords : 

Abstract :我们提出了一种在随机波动跳跃扩散模型下用于零日到期（0DTE）期权的微分机器学习方法，该模型在单个网络评估中计算价格和希腊。为了处理超短期到期制度，我们用Black-Scholes形式表示价格，并进行到期门控方差校正，并将价格和希腊的监管与PIDE残差惩罚相结合。为了使跳跃贡献可识别，我们引入了一个单独的跳跃算子网络，并用三阶段程序对其进行训练。在Bates模型模拟中，该方法改进了相对于单阶段基线的跳跃项近似，使价格误差接近单阶段备选方案，同时提高了Greeks的准确性，产生了稳定的单日增量套期保值，并且比基于傅里叶的定价基准快得多。

Keywords :

### 

\[4\] Autonomous AI Agents for Option Hedging

标题:用于期权对冲的自主人工智能代理

作者:Minxuan Hu, Ziheng Chen, Jiayu Yi, Wenxi Sun

来源:ARXIV\_20260310

链接:https://arxiv.org/pdf/2603.06587

Abstract : The deployment of autonomous AI agents in derivatives markets has widened a practical gap between static model calibration and realized hedging outcomes. We introduce two reinforcement learning frameworks, a novel Replication Learning of Option Pricing (RLOP) approach and an adaptive extension of Q learner in Black Scholes (QLBS), that prioritize shortfall probability and align learning objectives with downside sensitive hedging. Using listed SPY and XOP options, we evaluate models using realized path delta hedging outcome distributions, shortfall probability, and tail risk measures such as Expected Shortfall. Empirically, RLOP reduces shortfall frequency in most slices and shows the clearest tail risk improvements in stress, while implied volatility fit often favors parametric models yet poorly predicts after cost hedging performance. This friction aware RL framework supports a practical approach to autonomous derivatives risk management as AI augmented trading systems scale.

Keywords : 

Abstract :在衍生品市场部署自主人工智能代理扩大了静态模型校准和实现对冲结果之间的实际差距。我们介绍了两种强化学习框架，一种新的期权定价复制学习（RLOP）方法和Black-Scholes中Q学习器的自适应扩展（QLBS），它们优先考虑短缺概率，并将学习目标与下行敏感对冲相一致。使用列出的SPY和XOP期权，我们使用已实现的路径增量套期保值结果分布、短缺概率和预期短缺等尾部风险度量来评估模型。从经验上讲，RLOP降低了大多数切片中的短缺频率，并在压力下显示出最明显的尾部风险改善，而隐含波动率拟合通常有利于参数模型，但在成本对冲后的预测效果不佳。随着人工智能增强交易系统的扩展，这种摩擦感知RL框架支持一种实用的自主衍生品风险管理方法。

Keywords :

### 

\[5\] A Survey of Reinforcement Learning For Economics

标题:经济学强化学习研究综述

作者:Pranjal Rawat

来源:ARXIV\_20260311

链接:https://arxiv.org/pdf/2603.08956

Abstract : This survey (re)introduces reinforcement learning methods to economists. The curse of dimensionality limits how far exact dynamic programming can be effectively applied, forcing us to rely on suitably  small  problems or our ability to convert  big  problems into smaller ones. While this reduction has been sufficient for many classical applications, a growing class of economic models resists such reduction. Reinforcement learning algorithms offer a natural, sample based extension of dynamic programming, extending tractability to problems with high dimensional states, continuous actions, and strategic interactions. I review the theory connecting classical planning to modern learning algorithms and demonstrate their mechanics through simulated examples in pricing, inventory control, strategic games, and preference elicitation. I also examine the practical vulnerabilities of these algorithms, noting their brittleness, sample inefficiency, sensitivity to hyperparameters, and the absence of global convergence guarantees outside of tabular settings. The successes of reinforcement learning remain strictly bounded by these constraints, as well as a reliance on accurate simulators. When guided by economic structure, reinforcement learning provides a remarkably flexible framework. It stands as an imperfect, but promising, addition to the computational economist s toolkit. A companion survey (Rust and Rawat, 2026b) covers the inverse problem of inferring preferences from observed behavior.

Keywords : 

Abstract :这项调查（重新）向经济学家介绍了强化学习方法。维数灾难限制了精确动态规划的有效应用范围，迫使我们依赖于适当的小问题或将大问题转化为小问题的能力。虽然这种减少对于许多经典应用来说已经足够了，但越来越多的经济模型抵制这种减少。强化学习算法提供了一种自然的、基于样本的动态规划扩展，将可处理性扩展到具有高维状态、连续动作和战略交互的问题。我回顾了将经典规划与现代学习算法联系起来的理论，并通过定价、库存控制、战略博弈和偏好启发中的模拟示例演示了它们的机制。我还研究了这些算法的实际漏洞，注意到它们的脆弱性、样本效率低、对超参数的敏感性，以及在表格设置之外缺乏全局收敛保证。强化学习的成功仍然受到这些约束的严格限制，以及对精确模拟器的依赖。在经济结构的指导下，强化学习提供了一个非常灵活的框架。它是计算经济学家工具包中一个不完美但有前景的补充。一项配套调查（Rust和Rawat，2026b）涵盖了从观察到的行为推断偏好的逆问题。

Keywords :

### 

\[6\] Uncertainty Aware Deep Hedging

标题:不确定性意识深度对冲

作者:Manan Poddar (Department of Mathematics, London School of Economics)

来源:ARXIV\_20260312

链接:https://arxiv.org/pdf/2603.10137

Abstract : Deep hedging trains neural networks to manage derivative risk under market frictions, but produces hedge ratios with no measure of model confidence    a significant barrier to deployment. We introduce uncertainty quantification to the deep hedging framework by training a deep ensemble of five independent LSTM networks under Heston stochastic volatility with proportional transaction costs. The ensemble s disagreement at each time step provides a per time step confidence measure that is strongly predictive of hedging performance  the learned strategy outperforms the Black Scholes delta on approximately 80  of paths when model agreement is high, but on fewer than 20  when disagreement is elevated. We propose a CVaR optimised blending strategy that combines the ensemble s hedge with the classical Black Scholes delta, weighted by the level of model uncertainty. The blend improves on the Black Scholes delta by 35 80 basis points in CVaR across several Heston calibrations, and on the theoretically optimal Whalley Wilmott strategy by 100 250 basis points, with all improvements statistically significant under paired bootstrap tests. The analysis reveals that ensemble uncertainty is driven primarily by option moneyness rather than volatility, and that the uncertainty performance relationship inverts under weak leverage    findings with practical implications for the deployment of machine learning in hedging systems.

Keywords : 

Abstract :深度套期保值训练神经网络来管理市场摩擦下的衍生品风险，但产生的套期保值比率没有模型置信度，这是部署的一个重大障碍。我们通过在Heston随机波动率和比例交易成本下训练五个独立LSTM网络的深度集成，将不确定性量化引入深度套期保值框架。集合在每个时间步长的不一致性提供了一个每时间步长的置信度，该置信度可以很好地预测套期保值性能。当模型一致性高时，学习策略在大约80条路径上优于Black-Scholes delta，但当不一致性升高时，学习策略的表现在不到20条路径上。我们提出了一种CVaR优化的混合策略，该策略将集合的套期保值与经典的Black-Scholes delta相结合，并根据模型的不确定性水平进行加权。在几个赫斯顿校准中，该混合物在CVaR的Black-Scholes delta上提高了35.80个基点，在理论上最优的Whalley-Wilmott策略上提高了100.250个基点，所有改进在配对自举测试下都具有统计学意义。分析表明，集合不确定性主要是由期权的货币性而不是波动性驱动的，在弱杠杆发现下，不确定性与绩效的关系会逆转，这对机器学习在对冲系统中的部署具有实际意义。

Keywords :

### 

\[7\] An operator level ARCH Model

标题:操作员级ARCH模型

作者:Alexander Aue, Sebastian Kühnert, Gregory Rice, Jeremy VanderDoes

来源:ARXIV\_20260312

链接:https://arxiv.org/pdf/2603.10272

Abstract : AutoRegressive Conditional Heteroscedasticity (ARCH) models are standard for modeling time series exhibiting volatility, with a rich literature in univariate and multivariate settings. In recent years, these models have been extended to function spaces. However, functional ARCH and generalized ARCH (GARCH) processes established in the literature have thus far been restricted to model   pointwise   variances. In this paper, we propose a new ARCH framework for data residing in general separable Hilbert spaces that accounts for the full evolution of the conditional covariance operator. We define a general operator level ARCH model. For a simplified Constant Conditional Correlation version of the model, we establish conditions under which such models admit strictly and weakly stationary solutions, finite moments, and weak serial dependence. Additionally, we derive consistent Yule  Walker type estimators of the infinite dimensional model parameters. The practical relevance of the model is illustrated through simulations and a data application to high frequency cumulative intraday returns.

Keywords : 

Abstract :自回归条件异方差（ARCH）模型是模拟波动性时间序列的标准模型，在单变量和多变量环境中有丰富的文献。近年来，这些模型已扩展到功能空间。然而，迄今为止，文献中建立的泛函ARCH和广义ARCH（GARCH）过程仅限于模型逐点方差。在本文中，我们提出了一种新的ARCH框架，用于驻留在一般可分Hilbert空间中的数据，该框架解释了条件协方差算子的完全演化。我们定义了一个通用的算子级ARCH模型。对于模型的简化常条件相关版本，我们建立了此类模型允许严格和弱平稳解、有限矩和弱序列依赖的条件。此外，我们推导了无限维模型参数的一致Yule-Walker型估计。通过模拟和对高频累积日内回报的数据应用，说明了该模型的实际相关性。

Keywords :

### 

\[8\] A Bipartite Graph Approach to U.S. China Cross Market Return Forecasting

标题:中美跨市场收益预测的二分图方法

作者:Jing Liu, Maria Grith, Xiaowen Dong, Mihai Cucuringu

来源:ARXIV\_20260312

链接:https://arxiv.org/pdf/2603.10559

Abstract : This paper studies cross market return predictability through a machine learning framework that preserves economic structure. Exploiting the non overlapping trading hours of the U.S. and Chinese equity markets, we construct a directed bipartite graph that captures time ordered predictive linkages between stocks across markets. Edges are selected via rolling window hypothesis testing, and the resulting graph serves as a sparse, economically interpretable feature selection layer for downstream machine learning models. We apply a range of regularized and ensemble methods to forecast open to close returns using lagged foreign market information. Our results reveal a pronounced directional asymmetry  U.S. previous close to close returns contain substantial predictive information for Chinese intraday returns, whereas the reverse effect is limited. This informational asymmetry translates into economically meaningful performance differences and highlights how structured machine learning frameworks can uncover cross market dependencies while maintaining interpretability.

Keywords : 

Abstract :本文通过一个保持经济结构的机器学习框架研究了跨市场回报的可预测性。利用美国和中国股市的非重叠交易时间，我们构建了一个有向二分图，捕捉了不同市场股票之间的时间顺序预测联系。通过滚动窗口假设检验选择边缘，得到的图作为下游机器学习模型的稀疏、经济可解释的特征选择层。我们应用一系列正则化和集成方法，利用滞后的国外市场信息预测开盘至收盘的回报。我们的研究结果揭示了一个明显的方向不对称性。美国之前的收盘回报包含了对中国日内回报的大量预测信息，而反向效应是有限的。这种信息不对称转化为具有经济意义的性能差异，并突显了结构化机器学习框架如何在保持可解释性的同时发现跨市场依赖关系。

Keywords :

### 

\[9\] Beyond Polarity

标题:超越极性

作者:Dehao Dai, Ding Ma, Dou Liu, Kerui Geng, Yiqing Wang

来源:ARXIV\_20260313

链接:https://arxiv.org/pdf/2603.11408

Abstract : Forecasting crude oil prices remains challenging because market relevant information is embedded in large volumes of unstructured news and is not fully captured by traditional polarity based sentiment measures. This paper examines whether multi dimensional sentiment signals extracted by large language models improve the prediction of weekly WTI crude oil futures returns. Using energy sector news articles from 2020 to 2025, we construct five sentiment dimensions covering relevance, polarity, intensity, uncertainty, and forwardness based on GPT 4o, Llama 3.2 3b, and two benchmark models, FinBERT and AlphaVantage. We aggregate article level signals to the weekly level and evaluate their predictive performance in a classification framework. The best results are achieved by combining GPT 4o and FinBERT, suggesting that LLM based and conventional financial sentiment models provide complementary predictive information. SHAP analysis further shows that intensity  and uncertainty related features are among the most important predictors, indicating that the predictive value of news sentiment extends beyond simple polarity. Overall, the results suggest that multi dimensional LLM based sentiment measures can improve commodity return forecasting and support energy market risk monitoring.

Keywords : 

Abstract :预测原油价格仍然具有挑战性，因为市场相关信息嵌入了大量非结构化新闻中，而传统的基于极性的情绪指标并没有完全捕捉到这些信息。本文研究了大型语言模型提取的多维情绪信号是否可以提高WTI原油期货周回报率的预测。我们使用2020年至2025年的能源行业新闻文章，基于GPT 4o、Llama 3.2 3b和两个基准模型FinBERT和AlphaVantage构建了五个情绪维度，涵盖相关性、极性、强度、不确定性和前瞻性。我们将文章级别的信号聚合到每周级别，并在分类框架中评估它们的预测性能。通过结合GPT 4o和FinBERT可以获得最佳结果，这表明基于LLM的和传统的金融情绪模型提供了互补的预测信息。SHAP分析进一步表明，强度和不确定性相关特征是最重要的预测因素之一，表明新闻情绪的预测价值超越了简单的极性。总体而言，结果表明，基于多维LLM的情绪指标可以改善商品回报预测，支持能源市场风险监测。

Keywords :

### 

\[10\] Managing Cognitive Bias in Human Labeling Operations for Rare Event AI

标题:管理罕见事件人工智能人类标记操作中的认知偏差

作者:Gunnar P. Epping, Andrew Caplin, Erik Duhaime, William R. Holmes, Daniel Martin, Jennifer S. Trueblood

来源:ARXIV\_20260313

链接:https://arxiv.org/pdf/2603.11511

Abstract : Many operational AI systems depend on large scale human annotation to detect rare but consequential events (e.g., fraud, defects, and medical abnormalities). When positives are rare, the prevalence effect induces systematic cognitive biases that inflate misses and can propagate through the AI lifecycle via biased training labels. We analyze prior experimental evidence and run a field experiment on DiagnosUs, a medical crowdsourcing platform, in which we hold the true prevalence in the unlabeled stream fixed (20  blasts) while varying (i) the prevalence of positives in the gold standard feedback stream (20  vs. 50 ) and (ii) the response interface (binary labels vs. elicited probabilities). We then post process probabilistic labels using a linear in log odds recalibration approach at the worker and crowd levels, and train convolutional neural networks on the resulting labels. Balanced feedback and probabilistic elicitation reduce rare event misses, and pipeline level recalibration substantially improves both classification performance and probabilistic calibration  these gains carry through to downstream CNN reliability out of sample.

Keywords : 

Abstract :许多可操作的人工智能系统依赖于大规模的人工注释来检测罕见但重要的事件（例如欺诈、缺陷和医疗异常）。当积极因素很少时，患病率效应会引发系统性的认知偏差，从而增加失误，并可能通过有偏见的训练标签在人工智能生命周期中传播。我们分析了先前的实验证据，并在医疗众包平台DiagnosUs上进行了一项现场实验，在该实验中，我们固定了未标记流中的真实患病率（20次爆炸），同时改变了（i）金标准反馈流中阳性的患病率（20vs.50）和（ii）响应界面（二进制标签vs.诱发概率）。然后，我们在工人和人群级别使用线性对数赔率重新校准方法对概率标签进行后处理，并在得到的标签上训练卷积神经网络。平衡的反馈和概率启发减少了罕见事件的遗漏，管道级重新校准大大提高了分类性能和概率校准——这些增益将影响下游CNN的样本外可靠性。

Keywords :

### 

\[11\] Increasing intelligence in AI agents can worsen collective outcomes

标题:人工智能智能智能的提高可能会恶化集体结果

作者:Neil F. Johnson

来源:ARXIV\_20260313

链接:https://arxiv.org/pdf/2603.12129

Abstract : When resources are scarce, will a population of AI agents coordinate in harmony, or descend into tribal chaos  Diverse decision making AI from different developers is entering everyday devices    from phones and medical devices to battlefield drones and cars    and these AI agents typically compete for finite shared resources such as charging slots, relay bandwidth, and traffic priority. Yet their collective dynamics and hence risks to users and society are poorly understood. Here we study AI agent populations as the first system of real agents in which four key variables governing collective behaviour can be independently toggled  nature (innate LLM diversity), nurture (individual reinforcement learning), culture (emergent tribe formation), and resource scarcity. We show empirically and mathematically that when resources are scarce, AI model diversity and reinforcement learning increase dangerous system overload, though tribe formation lessens this risk. Meanwhile, some individuals profit handsomely. When resources are abundant, the same ingredients drive overload to near zero, though tribe formation makes the overload slightly worse. The crossover is arithmetical  it is where opposing tribes that form spontaneously first fit inside the available capacity. More sophisticated AI agent populations are not better  whether their sophistication helps or harms depends entirely on a single number    the capacity to population ratio    that is knowable before any AI agent ships.

Keywords : 

Abstract :当资源稀缺时，一群人工智能代理会协调一致，还是陷入部落混乱？来自不同开发人员的不同决策人工智能正在进入日常设备，从手机和医疗设备到战场无人机和汽车，这些人工智能代理通常会竞争有限的共享资源，如充电槽、中继带宽和流量优先级。然而，人们对它们的集体动态以及由此给用户和社会带来的风险知之甚少。在这里，我们将人工智能代理群体作为第一个真实代理系统进行研究，其中控制集体行为的四个关键变量可以独立切换——自然（先天LLM多样性）、培养（个体强化学习）、文化（新兴部落形成）和资源稀缺。我们从经验和数学上证明，当资源稀缺时，人工智能模型的多样性和强化学习会增加危险的系统过载，尽管部落的形成会降低这种风险。与此同时，一些人获得了丰厚的利润。当资源丰富时，同样的成分会使超载接近于零，尽管部落的形成会使超载稍微恶化。交叉是算术上的——它是自发形成的对立部落首先适应可用容量的地方。更复杂的人工智能代理群体并不是更好——它们的复杂程度是有益还是有害——完全取决于一个数字——在任何人工智能代理发布之前都可以知道的容量与人口之比。

Keywords :