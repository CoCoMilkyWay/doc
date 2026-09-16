# 量化前沿速递：机器学习\[20260615\]

shameless 量化前沿速递 2026-06-15 12:02 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489569&idx=4&sn=4bd64b96c5ebc2f61918dffe653e3432&chksm=c39dbaf3adc22db7ecd9ef0077283dabd47ae2dfa6f7ae8f73544242f4d9ac088167da23a3f1#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489569&idx=4&sn=4bd64b96c5ebc2f61918dffe653e3432&chksm=c39dbaf3adc22db7ecd9ef0077283dabd47ae2dfa6f7ae8f73544242f4d9ac088167da23a3f1#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Volatility Forecasting and Return Prediction under Market Regimes

市场机制下的波动性预测和收益预测

来源:ARXIV\_20260609

\[2\] TT DAC PS

TT DAC PS

来源:ARXIV\_20260609

\[3\] Evaluating AI Investment Strategies

评估人工智能投资策略

来源:ARXIV\_20260609

\[4\] Addressing Market Regime Changes and Heavy Tailed Returns in Portfolio Optimization via Bayesian VAR and Elliptical Black Litterman

通过贝叶斯VAR和椭圆Black Litterman解决投资组合优化中的市场机制变化和重尾收益问题

来源:ARXIV\_20260609

\[5\] Weighted universal approximation of differentiable maps on infinite dimensional manifolds

无穷维流形上可微映射的加权普适近似

来源:ARXIV\_20260609

\[6\] Deterministic Policy Gradient for Learning Equilibrium in Time Inconsistent Control Problems

时间不一致控制问题中学习均衡的确定性策略梯度

来源:ARXIV\_20260611

\[7\] Revisiting the ABCs of Working with AI

重温与人工智能合作的ABC

来源:ARXIV\_20260612

\[8\] The Mathematics of Heuristic Portfolio Optimization (HPO)

启发式投资组合优化（HPO）的数学

来源:ARXIV\_20260612

\[9\] Technology Shocks, Relative Performance Measures, and Outcomes

技术冲击、相对绩效指标和结果

来源:ARXIV\_20260612

### 

\[1\] Volatility Forecasting and Return Prediction under Market Regimes

标题:市场机制下的波动性预测和收益预测

作者:Xinyue Fang, Robert Ślepaczuk

来源:ARXIV\_20260609

链接:https://arxiv.org/pdf/2606.09478

Abstract : This study investigates whether regime dependent volatility forecasting and machine learning based return prediction can be jointly integrated to improve both statistical forecasting performance and economic strategy outcomes in equity markets. Using high frequency CSI 300 Index data from 2005 to 2023, a sequential twostage framework is developed. In the first stage, realized volatility is modeled using regime augmented HARQ specifications combined with Markov switching GJR GARCH filtering to capture long memory dynamics, asymmetry, and structural market regimes. In the second stage, volatility forecasts, regime indicators, and return related predictors are incorporated into an XGBoost return prediction model estimated through a strictly walk forward out of sample procedure. The empirical results demonstrate that regime aware volatility forecasting consistently outperforms baseline HARQ models across forecast evaluation metrics and is generally supported by formal forecast comparison tests. In contrast, return predictability remains weak, state dependent, and concentrated primarily in low volatility regimes. Although naive predictive trading strategies generally fail after accounting for realistic transaction costs, carefully designed implementations incorporating volatility scaling, low volatility gating, threshold calibration, and turnover controls can improve defensive economic performance. The findings suggest that the practical value of predictive systems in financial markets may depend less on generating strong unconditional return forecasts and more on transforming weak state dependent signals into economically robust portfolio allocation rules. Overall, the study contributes by integrating econometric volatility modeling, regime classification, machine learning return prediction, and implementation realism within a unified framework.

Keywords : 

Abstract :本研究调查了是否可以将依赖制度的波动率预测和基于机器学习的回报预测联合起来，以提高股票市场的统计预测性能和经济策略结果。利用2005年至2023年沪深300指数的高频数据，开发了一个连续的两阶段框架。在第一阶段，使用制度增强HARQ规范结合马尔可夫切换GJR-GARCH滤波对实现的波动性进行建模，以捕捉长期记忆动态、不对称性和结构性市场制度。在第二阶段，波动性预测、制度指标和回报相关预测因素被纳入XGBoost回报预测模型，该模型通过严格的样本前走程序进行估计。实证结果表明，在预测评估指标上，制度感知波动率预测始终优于基线HARQ模型，并且通常得到正式预测比较测试的支持。相比之下，回报的可预测性仍然很弱，依赖于国家，主要集中在低波动性地区。尽管幼稚的预测性交易策略在考虑了现实的交易成本后通常会失败，但精心设计的实施，包括波动率缩放、低波动率门控、阈值校准和交易控制，可以提高防御性经济表现。研究结果表明，预测系统在金融市场中的实用价值可能更多地取决于将弱状态依赖信号转化为经济稳健的投资组合分配规则，而不是产生强大的无条件回报预测。总体而言，该研究通过在统一的框架内整合计量经济学波动建模、制度分类、机器学习回报预测和实施现实主义做出了贡献。

Keywords :

### 

\[2\] TT DAC PS

标题:TT DAC PS

作者:Ilia Zaznov, Atta Badii, Julian Kunkel, Alfonso Dufour

来源:ARXIV\_20260609

链接:https://arxiv.org/pdf/2606.08379

Abstract : This study addresses the optimal execution of large stock sell programs by introducing TT DAC PS (Twin Target Deterministic Actor Critic with Policy Smoothing), a deterministic actor critic architecture that combines twin exponential moving average critic targets with pessimistic min backup, TD3 style target policy smoothing noise, delayed actor updates, and conservative Q regularisation to curb overestimation. Exploration uses Ornstein Uhlenbeck (OU) noise with a hybrid schedule  deterministic episode wise decay, variance guided adjustment based on recent reward dispersion, and a Soft Actor Critic (SAC) style temperature that is learned and mapped to the noise scale. The environment integrates Almgren Chriss (AC) trade impact with Limit Order Book (LOB) prices and volumes, normalised state features, per step volume participation caps, and a utility based reward. The trade execution algorithm is applied to LOB data for ten U.S. stocks. Performance is assessed against reinforcement learning baseline algorithms, including Proximal Policy Optimisation (PPO), Soft Actor Critic (SAC), and Advantage Actor Critic (A2C), as well as alternative trade execution algorithms, including Time Weighted Average Price (TWAP), Volume Weighted Average Price (VWAP), and AC. The proposed model consistently reduces mean implementation shortfall percentage with competitive variance, outperforming classical baselines and standard reinforcement learning benchmark models.

Keywords : 

Abstract :本研究通过引入TT DAC PS（双目标确定性行动者评论家与策略平滑）来解决大型股票出售计划的最佳执行问题，这是一种确定性行动者评论家架构，将双指数移动平均评论家目标与悲观最小备份、TD3风格的目标策略平滑噪声、延迟行动者更新和保守Q正则化相结合，以遏制高估。探索使用Ornstein-Uhlenbeck（OU）噪声，该噪声具有混合时间表确定性逐集衰减、基于最近奖励分散的方差引导调整，以及学习并映射到噪声尺度的软演员评论家（SAC）风格温度。该环境将Almgren-Chriss（AC）交易影响与限价订单簿（LOB）价格和数量、标准化状态特征、每步交易量参与上限和基于公用事业的奖励相结合。交易执行算法应用于10只美国股票的LOB数据。根据强化学习基线算法（包括Proximal Policy Optimization（PPO）、Soft Actor Critic（SAC）和Advantage Actor Critics（A2C））以及替代交易执行算法（包括时间加权平均价格（TWAP）、交易量加权平均价格（VWAP）和AC）来评估性能。所提出的模型通过竞争方差持续降低平均实施不足百分比，优于经典基线和标准强化学习基准模型。

Keywords :

### 

\[3\] Evaluating AI Investment Strategies

标题:评估人工智能投资策略

作者:Irene Aldridge

来源:ARXIV\_20260609

链接:https://arxiv.org/pdf/2606.08791

Abstract : We study the problem of auditing a black box algorithmic decision maker from observable inputs and outputs alone. Our main result is an exact decomposition  under precisely characterized conditions, the cumulative  emph regret  of a dynamic policy equals the sum of per period covariances between the cost vector and the policy s decision. This extends the single period identity of Aldridge (2026) to the full multi period setting of stochastic dynamic programming.We prove the identity holds exactly under i.i.d. costs and mean unbiased Markov policies, derive closed form bias corrections for non stationary and time varying cases, and establish the discounted horizon analog. A Bellman recursion for the covariance regret functional connects the result to standard reinforcement learning algorithms  for rolling window policies, the estimation error bias is  O(d w) .The decomposition has direct implications for algorithmic auditing in strategic environments  in platform mechanism design, it provides a welfare based audit metric without access to the agent s private type  in repeated games, covariance reduction is a sufficient condition for policy improvement  in procurement and ad auctions, the bias correction quantifies welfare loss from strategic misreporting. The associated trajectory estimator is consistent, asymptotically normal with HAC variance, and computable in  O(T  cdot nd)  time. This makes the proposed approach a tractable, model free audit tool for platform mechanisms, algorithmic portfolio strategies, and any sequential decision system subject to external performance review.

Keywords : 

Abstract :我们研究了仅从可观察的输入和输出审计黑盒算法决策者的问题。我们的主要结果是在精确表征的条件下进行精确分解，动态策略的累积emph遗憾等于成本向量和策略决策之间的每个周期协方差之和。这将Aldridge（2026）的单周期恒等式扩展到随机动态规划的完整多周期设置。我们证明了在i.i.d.成本和均值无偏马尔可夫策略下，恒等式完全成立，推导了非平稳和时变情况下的闭式偏差校正，并建立了贴现期模拟。协方差后悔函数的Bellman递归将结果与滚动窗口策略的标准强化学习算法联系起来，估计误差偏差为O（dw）。该分解对平台机制设计中的战略环境中的算法审计有直接影响，它提供了一种基于福利的审计度量，在重复博弈中不需要访问代理的私有类型，协方差减少是采购和阅读拍卖中政策改进的充分条件，偏差校正量化了战略误报造成的福利损失。相关轨迹估计器是一致的，与HAC方差渐近正态，并且可在O（T cdot nd）时间内计算。这使得所提出的方法成为一种易于处理的、无模型的审计工具，适用于平台机制、算法组合策略和任何受外部绩效审查的顺序决策系统。

Keywords :

### 

\[4\] Addressing Market Regime Changes and Heavy Tailed Returns in Portfolio Optimization via Bayesian VAR and Elliptical Black Litterman

标题:通过贝叶斯VAR和椭圆Black Litterman解决投资组合优化中的市场机制变化和重尾收益问题

作者:Daniil Mikriukov (1 and 2), Ruoyu Sun (2), Angelos Stefanidis (2), Jionglong Su (2), Zhengyong Jiang (2) ((1) University of Liverpool, (2) Xi'an Jiaotong-Liverpool University)

来源:ARXIV\_20260609

链接:https://arxiv.org/pdf/2606.09104

Abstract : Deep reinforcement learning (DRL) frameworks for portfolio optimization have shown promise for their ability to learn allocation rules dynamically from market data. However, these models fail to account for fat tailed returns, which characterize actual market behavior with more frequent extreme events. Furthermore, historical data is treated homogeneously, without accounting for temporal importance, leading models to fail during regime changes. We propose a new BAVAR BLED algorithm that combines methods derived from Bayesian Averaging Vector Autoregressive (BAVAR) and the Black Litterman model using Elliptical Distributions (BLED) within a TD3 architecture. BAVAR captures a set of vector autoregressive representations that consider multi scale temporal features, enabling adaptive allocation decisions based on regime aware estimates of return expectations and dispersion matrices. These estimates serve as prior inputs to BLED, a model that uses Student s t distributions, allowing for more realistic fat tail return estimates. The BAVAR BLED algorithm uses transformer networks for view construction and CNNs for risk aversion estimates, which modify dynamic allocation decisions based on market conditions. An evaluation of 29 Dow Jones Industrial Average constituents over a decade long market period shows that BAVAR BLED significantly outperforms state of the art methods, achieving Sharpe and Sortino ratios of 1.72 and 2.70, respectively, and total returns of 57.26 .

Keywords : 

Abstract :用于投资组合优化的深度强化学习（DRL）框架已经显示出从市场数据中动态学习分配规则的能力。然而，这些模型未能考虑肥尾回报，肥尾回报是实际市场行为的特征，极端事件更为频繁。此外，历史数据被统一处理，没有考虑时间重要性，导致模型在政权更迭期间失败。我们提出了一种新的BAVAR BLED算法，该算法结合了贝叶斯平均向量自回归（BAVAR）和Black-Litterman模型在TD3架构中使用椭圆分布（BLED）的方法。BAVAR捕获了一组考虑多尺度时间特征的向量自回归表示，从而能够基于对回报预期和分散矩阵的制度感知估计做出自适应分配决策。这些估计值可作为BLED的先验输入，BLED是一种使用Student s t分布的模型，允许更真实的肥尾回报估计。BAVAR BLED算法使用变压器网络进行视图构建，使用CNN进行风险规避估计，根据市场条件修改动态分配决策。对道琼斯工业平均指数29个成分股在长达十年的市场期内的评估表明，BAVAR BLED的表现明显优于最先进的方法，夏普和索蒂诺比率分别为1.72和2.70，总回报率为57.26。

Keywords :

### 

\[5\] Weighted universal approximation of differentiable maps on infinite dimensional manifolds

标题:无穷维流形上可微映射的加权普适近似

作者:Philipp Schmocker, Josef Teichmann

来源:ARXIV\_20260609

链接:https://arxiv.org/pdf/2606.09820

Abstract : We generalize the universal approximation theorem for functional input neural networks (FNN) to differentiable maps by including the approximation of the derivatives. A FNN maps the input from a possibly infinite dimensional weighted manifold to the real valued hidden layer, on which a non linear scalar activation function is applied, and then returns the output into a Banach space via some linear readouts. By proving a weighted Nachbin theorem, we establish a universal approximation theorem (UAT) for differentiable maps, which goes beyond the usual formulation on compact sets and also includes the approximation of the derivatives. This leads us to approximation results for non anticipative functionals including the horizontal and vertical derivatives. As a further application, we show that linear functions of the signature are able to approximate path space functionals including their directional derivatives.

Keywords : 

Abstract :我们通过包含导数的近似，将函数输入神经网络（FNN）的普遍近似定理推广到可微映射。FNN将来自可能无限维加权流形的输入映射到实值隐层，在该隐层上应用非线性标量激活函数，然后通过一些线性读数将输出返回到Banach空间。通过证明加权Nachbin定理，我们建立了可微映射的普遍逼近定理（UAT），该定理超越了紧致集上的通常公式，还包括导数的近似。这使我们得到了包括水平和垂直导数在内的非预期泛函的近似结果。作为进一步的应用，我们证明了签名的线性函数能够近似路径空间泛函，包括它们的方向导数。

Keywords :

### 

\[6\] Deterministic Policy Gradient for Learning Equilibrium in Time Inconsistent Control Problems

标题:时间不一致控制问题中学习均衡的确定性策略梯度

作者:Xin Guo, Yijie Huang, Xiang Yu

来源:ARXIV\_20260611

链接:https://arxiv.org/pdf/2606.11798

Abstract : In this paper, we develop a continuous time model free reinforcement learning algorithm to learn deterministic equilibrium policies in general time inconsistent control problems. Utilizing the extended Hamilton Jacobi Bellman system, we recast the original time inconsistent problem into an equivalent two stage problem. In the first stage, for given auxiliary functions, we employ the deterministic policy gradient approach to learn an optimal policy in an auxiliary time consistent control problem. In the second stage, given the updated policy, we exploit the inner fixed point iterations and some martingale characterizations to learn the auxiliary functions. As a theoretical contribution, we provide some mild model assumptions and establish the convergence of inner fixed point iterations. By repeating this actor critic style of iterations across two stages, our algorithm aims to learn the equilibrium under different sources of time inconsistency in a unified manner. The superior effectiveness of the proposed algorithm are illustrated in two classical financial applications with time inconsistency  mean variance portfolio management and optimal tracking portfolio under non exponential discounting.

Keywords : 

Abstract :本文开发了一种连续时间无模型强化学习算法，用于学习一般时间不一致控制问题中的确定性均衡策略。利用扩展的Hamilton-Jacobi-Bellman系统，我们将原始的时间不一致问题转化为等效的两阶段问题。在第一阶段，对于给定的辅助函数，我们采用确定性策略梯度方法来学习辅助时间一致控制问题中的最优策略。在第二阶段，给定更新的策略，我们利用内不动点迭代和一些鞅特征来学习辅助函数。作为理论贡献，我们提供了一些温和的模型假设，并建立了内不动点迭代的收敛性。通过在两个阶段重复这种行动者-评论家式的迭代，我们的算法旨在以统一的方式学习不同时间不一致源下的均衡。所提出的算法在两个经典的金融应用中表现出了卓越的有效性，这两个应用分别是时间不一致均值方差投资组合管理和非指数贴现下的最优跟踪投资组合。

Keywords :

### 

\[7\] Revisiting the ABCs of Working with AI

标题:重温与人工智能合作的ABC

作者:Daniel Martin

来源:ARXIV\_20260612

链接:https://arxiv.org/pdf/2606.12585

Abstract : Artificial intelligence (AI) systems increasingly assist human experts, but the consequences of AI assistance on productivity can be heterogeneous. Caplin, Deming, S. Li, Martin, Marx, Weidmann, and Ye (2025b) provide evidence that two characteristics, ability and belief calibration, help to determine the returns to AI assistance. This note shows that their results replicate to a setting where professional radiologists analyze chest X rays with access to state of the art machine learning predictions. I leverage the public Collab CXR data repository described by Moehring, Kutwal, Huang, Banerjee, Jacobi, Eber, Mendoza, Chung, Dayan, Gupta, Bui, Truong, Pareek, Langlotz, Lungren, Agarwal, Rajpurkar, and Salz (2025) and first analyzed for human AI collaboration by Agarwal, Moehring, Rajpurkar, and Salz (2023). To faithfully reproduce the analysis in Caplin, Deming, S. Li, Martin, Marx, Weidmann, and Ye (2025b), I use the radiologist assessments from the repeated case designs, which include 68 radiologists and 11,420 paired radiologist patient pathology observations. The results of this replication support the external validity of their core findings  lower baseline ability and higher calibration predict larger incremental value from AI.

Keywords : 

Abstract :人工智能（AI）系统越来越多地协助人类专家，但AI协助对生产力的影响可能是多种多样的。Caplin、Deming、S.Li、Martin、Marx、Weidmann和Ye（2025b）提供的证据表明，能力和信念校准这两个特征有助于确定人工智能辅助的回报。本说明表明，他们的结果可以复制到专业放射科医生分析胸部X射线并获得最先进的机器学习预测的环境中。我利用了Moehring、Kutwal、Huang、Banerjee、Jacobi、Eber、Mendoza、Chung、Dayan、Gupta、Bui、Truong、Pareek、Langlotz、Lungren、Agarwal、Rajpurkar和Salz（2025）描述的公共Collab CXR数据存储库，Agarwal，Moehring，Rajpurkar，和Salz首先分析了人工智能协作（2023）。为了忠实地再现Caplin、Deming、S.Li、Martin、Marx、Weidmann和Ye（2025b）的分析，我使用了重复病例设计中的放射科医生评估，其中包括68名放射科医师和11420对放射科医氏患者病理观察。这种复制的结果支持了他们核心发现的外部有效性——较低的基线能力和较高的校准预测了AI的更大增量值。

Keywords :

### 

\[8\] The Mathematics of Heuristic Portfolio Optimization (HPO)

标题:启发式投资组合优化（HPO）的数学

作者:Miquel Noguer i Alonso

来源:ARXIV\_20260612

链接:https://arxiv.org/pdf/2606.12612

Abstract : Practitioners allocate capital with forecast light rules such as equal weight, inverse volatility, risk parity, HRP, and return adjusted HRP (RA HRP). This paper develops  emph Heuristic Portfolio Optimization  (HPO)  an information restricted projection of the Markowitz tangency solution onto a stable rule class. The implied return principle,   w  is maximum Sharpe iff   bmu e propto bSigma w , gives closed form optimality sets for leading heuristics and exposes the Schur complement substitutions behind HRP. For RA HRP, we introduce fixed tree cluster Sharpe recursion, unit free HRP  RA HRP interpolation, tangency conditions, conditional risk splits, and pathwise KL decompositions of weight distortion. First order Sharpe calculus expresses the marginal value of return information as nodewise alphas against HRP and yields a linear KL trust budget. We formalize generic HPO maps, define the implied return defect, prove that it equals squared Sharpe inefficiency, characterize tree HPO coincidence by nodewise mass ratios, and give a bias  variance decomposition for estimated rules. Finally, HPO is embedded into Reinforcement Learning Portfolio Optimization (RLPO)  every HPO map induces a deterministic stationary policy  static HPO is the   gamma 0  no friction face of the Bellman problem  RA HRP supplies a hierarchical policy prior  and dynamic improvement is warranted when continuation value exceeds myopic HPO defect plus frictions. A performance difference identity prices the myopic value gap, gives an   varepsilon (1  gamma)  myopia bound, and identifies nodewise alphas as policy gradient coordinates of the hierarchical actor. Thus HPO is the static optimality layer and RLPO the dynamic control layer. The conditions are GRS testable, extend to mean  CVaR and expected utility under ellipticity, and become Kelly growth conditions in diffusion limits.

Keywords : 

Abstract :从业者使用预测轻规则分配资本，如等权重、逆波动率、风险平价、HRP和回报调整HRP（RA-HRP）。本文重点发展了启发式投资组合优化（HPO），这是Markowitz切线解在稳定规则类上的信息受限投影。隐含返回原理w是最大Sharpe-iff bmu e propto bSigma w，它为领先的启发式算法提供了闭式最优性集，并揭示了HRP背后的Schur补码替换。对于RA HRP，我们引入了固定树簇Sharpe递归、无单位HRP RA HRP插值、相切条件、条件风险分割和权重失真的路径KL分解。一阶夏普演算将返回信息的边际值表示为相对于HRP的逐节点α，并产生线性KL信任预算。我们形式化了通用的HPO映射，定义了隐含的返回缺陷，证明了它等于夏普效率的平方，通过节点质量比表征了树HPO一致性，并对估计规则进行了偏差方差分解。最后，HPO被嵌入到强化学习组合优化（RLPO）中。每个HPO映射都会诱导一个确定性的静态策略。静态HPO是贝尔曼问题的gamma 0无摩擦面。RA HRP提供了一个分层策略先验，当连续值超过近视HPO缺陷加摩擦时，需要进行动态改进。性能差异标识对近视值差距进行定价，给出varepsilon（1-gamma）近视界限，并将节点α标识为分层参与者的策略梯度坐标。因此，HPO是静态最优性层，RLPO是动态控制层。这些条件是GRS可测试的，在椭圆度下扩展到平均CVaR和预期效用，并在扩散极限下成为Kelly生长条件。

Keywords :

### 

\[9\] Technology Shocks, Relative Performance Measures, and Outcomes

标题:技术冲击、相对绩效指标和结果

作者:Dan Ben-Moshe, David Genesove

来源:ARXIV\_20260612

链接:https://arxiv.org/pdf/2606.12893

Abstract : In the fall of 2020, neural network methods produced a large improvement in chess engines that became freely and widely available. By the end of 2021, the monthly draw rate in classical chess had risen by about four percentage points, but the distribution of player ratings, which are commonly read as measures of playing strength, had changed little. Ratings, however, are a relative measure, built from results against other rated players rather than from an absolute scale of play quality, so an improvement shared broadly across players need not change their ratings. Using 3.9 million rated classical games from March 2015 to November 2023, we document that the increased draw rate remains after conditioning on both players  ratings, holds within repeated same color matchups, is not a continuation of a pre existing trend, and persists through the end of the sample. A linear transformation that maps post Covid ratings to higher pre Covid equivalents, with a larger gap at lower ratings, accounts for more than 90 percent of the post minus pre shift in the fitted draw, White win, and Black win probabilities. Players  ratings and ranks, by contrast, show no additional rank reshuffling and no general widening of within group dispersion relative to the pre Covid benchmark. We interpret these findings as consistent with adoption across rating levels, with larger rating equivalent gains for lower rated players.

Keywords : 

Abstract :2020年秋季，神经网络方法对国际象棋引擎进行了大幅改进，使其变得免费且广泛可用。到2021年底，古典国际象棋的月度平局率上升了约4个百分点，但通常被视为衡量下棋实力的玩家评分分布变化不大。然而，评级是一种相对的衡量标准，是根据与其他评级玩家的结果建立的，而不是根据游戏质量的绝对规模建立的，因此玩家之间广泛分享的改进不需要改变他们的评级。从2015年3月到2023年11月，我们使用了390万款评分的经典游戏，记录了在对两名玩家的评分进行条件化处理后，抽签率的提高仍然存在，在重复的同色比赛中保持不变，这不是现有趋势的延续，并持续到样本结束。将新冠肺炎疫情后的评分映射到新冠肺炎疫情前的较高评分，在较低评分时差距较大，这一线性变换在拟合平局、白人获胜和黑人获胜概率中占了减去前的90%以上。相比之下，与新冠肺炎前的基准相比，球员评级和排名没有显示出额外的排名调整，也没有普遍扩大团队内部的分散。我们将这些发现解释为与各评级级别的采用一致，评级较低的球员的评级等效收益较大。

Keywords :