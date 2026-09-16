# 量化前沿速递：CTA\[20260719\]

shameless 量化前沿速递 2026-07-20 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489622&idx=3&sn=e42bad83bd1cf4ac2bd37cc6c39b6e51&chksm=c37bbd870b9ac93e8475704abf2464a1bb2c178d4177535912fabb8da6e05d006377cc46260b#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489622&idx=3&sn=e42bad83bd1cf4ac2bd37cc6c39b6e51&chksm=c37bbd870b9ac93e8475704abf2464a1bb2c178d4177535912fabb8da6e05d006377cc46260b#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] When Does Order Flow Matter  State Dependent L2 Liquidity State Transitions in Crypto Futures

加密期货中订单流何时影响状态依赖的L2流动性状态转换

来源:ARXIV\_20260713

\[2\] The Quarter Hour Effect

四分之一小时效应

来源:ARXIV\_20260713

\[3\] Perturbed utility Markovian traffic equilibrium

扰动效用马尔可夫交通均衡

来源:ARXIV\_20260713

\[4\] Strategic OTC market making with reputation feedback

基于声誉反馈的战略性场外交易做市

来源:ARXIV\_20260714

\[5\] Diachronic Sample Integration

历时性样本整合

来源:ARXIV\_20260714

\[6\] Ito Wentzell Formula and Dupire Stochastic PDE

Ito-Wentzell公式与Dupire随机偏微分方程

来源:ARXIV\_20260715

\[7\] Detecting unusual trading patterns on cryptocurrency exchanges by means of complexity measures

通过复杂性度量检测加密货币交易所的异常交易模式

来源:ARXIV\_20260716

\[8\] Equilibrium stability as a driver of cooperation among Q learners

平衡稳定性是Q学习者合作的驱动力

来源:ARXIV\_20260716

\[9\] NeuralChaos

神经混沌

来源:ARXIV\_20260717

\[10\] Structure Aware Variational State Preparation for Quantum Basket Option Pricing

量子篮子期权定价的结构感知变分态准备

来源:ARXIV\_20260717

### 

\[1\] When Does Order Flow Matter  State Dependent L2 Liquidity State Transitions in Crypto Futures

标题:加密期货中订单流何时影响状态依赖的L2流动性状态转换

作者:Joohyoung Jeon

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09230

Abstract : Building event conditioned market models requires separating macro event labels from persistent microstructure state. We study this distinction in Binance BTCUSDT and ETHUSDT futures from 2023 2026, combining top 20 L2 order book data, trade flow records, and macro event windows. We define a supervised discrete L2 liquidity state transition task, distinct from latent regime detection and price direction prediction, and evaluate models in rolling monthly out of sample folds with event clustered validation and blocked permutation tests, admitting each feature layer only if it improves on the layer below it on the same panel. Within these event windows, the first order predictive signal is the pre event L2 liquidity state  a coarse pre event state baseline strongly predicts post event liquidity regimes, interpretable logit models over continuous L2 features fail to improve on it, and a shallow nonlinear L2 model adds a robust further gain of comparable size to the state baseline s own. The macro event calendar enters only by locating the windows and supplying matched non event controls  we use event timing but not the event s label content, so pre event state competes against an uninformed within window baseline, not against the event type. Order flow adds further value only when layered on top of the L2 state model, not as a replacement. This value is not robustly cross symbol  for ETH it is present across calm, mixed, and stressed regimes and largest under stressed pre event liquidity, whereas BTC shows only isolated five minute passes and no regime that clears at both horizons. These findings motivate a state first design principle for market microstructure models. We provide a liquidity state transition baseline and evaluation protocol that reinforcement learning, execution policy, or LLM based context layers should exceed before their added value is credited.

Keywords : 

Abstract :构建事件条件市场模型需要将宏观事件标签与持久的微观结构状态分开。我们结合前20位L2订单簿数据、交易流记录和宏观事件窗口，研究了2023年至2026年币安BTCUSDT和ETHUSDT期货的这种区别。我们定义了一个有监督的离散L2流动性状态转换任务，有别于潜在的制度检测和价格方向预测，并通过事件聚类验证和阻塞置换测试对月度样本外折叠中的模型进行评估，只有当每个特征层在同一面板上的下一层有所改善时，才承认每个特征层。在这些事件窗口内，一阶预测信号是事件前的L2流动性状态，粗略的事件前状态基线强烈预测了事件后的流动性状况，连续L2特征上的可解释logit模型未能对其进行改进，浅层非线性L2模型增加了与状态基线本身相当大小的鲁棒增益。宏事件日历仅通过定位窗口并提供匹配的非事件控件来进入，我们使用事件计时，但不使用事件的标签内容，因此事件前状态与窗口内的未知基线竞争，而不是与事件类型竞争。订单流只有在L2状态模型之上分层时才能增加更多价值，而不是作为替代品。该值不是ETH的稳健交叉符号，它存在于平静、混合和压力的制度中，以及最大的压力不足的事件前流动性中，而BTC只显示了孤立的五分钟通行证，没有在两个层面都清算的制度。这些发现激发了市场微观结构模型的国家优先设计原则。我们提供了一个流动性状态转换基线和评估协议，强化学习、执行策略或基于LLM的上下文层在计入其附加值之前应超过该基线和协议。

Keywords :

### 

\[2\] The Quarter Hour Effect

标题:四分之一小时效应

作者:Chan Kim, Peter Reinhard Hansen

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09426

Abstract : Cryptocurrency markets exhibit periodic bursts in volatility and volume at one , five , and quarter hour marks. Using trade data for six Binance perpetual contracts, we associate these bursts with algorithmic trading  trade size roundness declines sharply within them, a behavioral signature of algorithmic participation. The Autocorrelation Map, a clock phase resolved display, reveals serial dependence in order flow and returns at the quarter hour openings that conventional measures conceal. This opening activity is not only predictable out of sample but also informative  its order imbalance forecasts four to twelve hour returns, weaker at finer marks. Our results characterize periodic algorithmic trading and its cross frequency variation.

Keywords : 

Abstract :加密货币市场在一小时、五小时和四分之一小时的波动性和交易量上呈现出周期性的爆发。使用六个币安永久合约的交易数据，我们将这些爆发与算法交易交易规模的圆度急剧下降联系起来，这是算法参与的行为特征。自相关图是一种时钟相位分辨显示，显示了顺序流的串行依赖性，并在传统测量方法所掩盖的四分之一小时开口处返回。这种开盘活动不仅在样本外是可预测的，而且信息量也很大——它的订单不平衡预测了4到12小时的回报，分数越高，回报越弱。我们的结果描述了周期性算法交易及其交叉频率变化。

Keywords :

### 

\[3\] Perturbed utility Markovian traffic equilibrium

标题:扰动效用马尔可夫交通均衡

作者:Rui Yao, Kenan Zhang

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09568

Abstract : Large scale traffic assignment requires equilibrium models that are both behaviorally plausible and computationally tractable. This paper develops a perturbed utility Markovian equilibrium (PUME) framework that preserves the scalability of link based Markovian traffic equilibrium models and extends their applicability to settings with boundary choice probabilities, undiscounted network loading, and general link interactions. As the behavioral basis of PUME, we first develop the perturbed utility Markovian choice model (PUMCM) in which the Bellman optimality operator is defined through a convex surplus function whose gradient directly yields the optimal policy. The model generalizes existing additive random utility (ARUM) Markovian choice models and admits both interior and boundary choice probabilities. Accordingly, unattractive links can receive zero flow without imposing ex ante choice set restrictions as in existing ARUM models. We establish conditions under which the corresponding Markov decision problem is well posed and yields a proper demand mapping. We then formulate the equilibrium as a variational inequality (VI) problem on the dual cost space and establish its existence and uniqueness. Particularly, the VI formulation of PUME accommodates non separable and asymmetric cost structures and thus offers a more flexible modeling framework than existing Markovian traffic equilibrium (MTE) models. For computation, we develop a modified policy iteration method for network loading and a safeguarded accelerated meta algorithm for computing equilibrium. Both algorithms are proven to be globally convergent and have demonstrated satisfactory numerical performances. Experiments on benchmark and synthetic networks further show that the proposed framework is highly scalable and robust towards a wide variety of demand supply settings.

Keywords : 

Abstract :大规模交通分配需要行为上合理且计算上易于处理的平衡模型。本文开发了一个扰动效用马尔可夫均衡（PUME）框架，该框架保留了基于链路的马尔可夫流量均衡模型的可扩展性，并将其适用性扩展到具有边界选择概率、未折现网络负载和一般链路交互的设置。作为PUME的行为基础，我们首先开发了扰动效用马尔可夫选择模型（PUMCM），其中Bellman最优性算子是通过凸盈余函数定义的，该函数的梯度直接产生最优策略。该模型推广了现有的加性随机效用（ARUM）马尔可夫选择模型，并承认内部和边界选择概率。因此，没有吸引力的链接可以获得零流量，而不会像现有的ARUM模型那样施加事前选择集限制。我们建立了相应的马尔可夫决策问题适定并产生适当需求映射的条件。然后，我们将均衡表述为对偶成本空间上的变分不等式（VI）问题，并证明其存在性和唯一性。特别是，PUME的VI公式适应了不可分离和不对称的成本结构，因此提供了一个比现有的马尔可夫交通均衡（MTE）模型更灵活的建模框架。在计算方面，我们开发了一种改进的网络负载策略迭代方法和一种用于计算均衡的有保障的加速元算法。这两种算法都被证明是全局收敛的，并且具有令人满意的数值性能。在基准和合成网络上的实验进一步表明，所提出的框架具有高度的可扩展性，并且对各种供需环境具有鲁棒性。

Keywords :

### 

\[4\] Strategic OTC market making with reputation feedback

标题:基于声誉反馈的战略性场外交易做市

作者:Alexander Barzykin

来源:ARXIV\_20260714

链接:https://arxiv.org/pdf/2607.11328

Abstract : Electronic over the counter (OTC) liquidity provision is increasingly shaped not only by the price of the next quote, but also by a dealer s accumulated standing with clients and platforms. We develop a stochastic control model in which request for quote (RFQ) win ratios and streaming fill ratios feed back into future flow through performance based flow gates, creating an explicit trade off between immediate spread capture and long term franchise value. The resulting policy naturally alternates between reputation building campaigns and franchise monetization phases, and can generate multiple stable client flow regimes even in a parsimonious single dealer control problem.

Keywords : 

Abstract :电子场外（OTC）流动性供应不仅越来越多地受到下一个报价价格的影响，还受到交易商在客户和平台上积累的地位的影响。我们开发了一个随机控制模型，其中询价（RFQ）获胜率和流填充率通过基于性能的流量门反馈到未来的流量中，在即时点差捕获和长期特许经营价值之间进行了明确的权衡。由此产生的政策自然在声誉建设活动和特许经营货币化阶段之间交替，即使在吝啬的单一经销商控制问题中，也可以产生多个稳定的客户流机制。

Keywords :

### 

\[5\] Diachronic Sample Integration

标题:历时性样本整合

作者:Shuning Zhao, Patrick Wong, Leran Zhang, Xiaolin Hu

来源:ARXIV\_20260714

链接:https://arxiv.org/pdf/2607.10810

Abstract : Deep generative models are increasingly used as simulators for downstream decision making under data scarcity, but in risk sensitive applications their usefulness depends on rare adverse scenarios rather than typical samples. Standard generative objectives prioritize bulk distributional fidelity, leaving low probability tails vulnerable to localized optimization noise and making tail dependent functionals unstable under finite simulation budgets. We introduce Diachronic Sample Integration (DSI), a test time inference framework that ensembles generated samples across checkpoints from a stochastic training trajectory. DSI targets a checkpoint mixture distribution that averages checkpoint specific tail fluctuations rather than relying on a single brittle endpoint. We formalize this mechanism through a finite budget bias variance theory. Empirically, across multivariate synthetic processes and high frequency trading data, DSI substantially reduces tail estimation error compared to single checkpoint baselines under fixed simulation budgets, outperforming standard diffusion and state of the art tail aware baselines without modifying the generative objective.

Keywords : 

Abstract :深度生成模型越来越多地被用作数据稀缺下下游决策的模拟器，但在风险敏感的应用中，它们的有用性取决于罕见的不利情景，而不是典型的样本。标准生成目标优先考虑批量分布保真度，使低概率尾部容易受到局部优化噪声的影响，并使尾部相关泛函在有限的模拟预算下不稳定。我们介绍了Diachronic Sample Integration（DSI），这是一个测试时间推理框架，它将随机训练轨迹中的检查点生成的样本集成在一起。DSI的目标是检查点混合分布，该分布平均检查点特定的尾部波动，而不是依赖于单个脆弱的端点。我们通过有限预算偏差方差理论将这一机制形式化。根据经验，在多变量合成过程和高频交易数据中，与固定模拟预算下的单检查点基线相比，DSI大大降低了尾部估计误差，在不修改生成目标的情况下，优于标准扩散和最先进的尾部感知基线。

Keywords :

### 

\[6\] Ito Wentzell Formula and Dupire Stochastic PDE

标题:Ito-Wentzell公式与Dupire随机偏微分方程

作者:Vladimir Lucic

来源:ARXIV\_20260715

链接:https://arxiv.org/pdf/2607.12479

Abstract : Starting from the classic result of Wentzell, we derive a conditional forward equation and an associated stochastic Dupire PDE for a local stochastic volatility model (LSV). As an application, we obtain a density weighted Rao  Blackwell estimator for the leverage function in LSV. We also derive an SPDE for a rolling expiry vanilla option, in the spirit of the Musiela parametrization in interest rate modeling.

Keywords : 

Abstract :从Wentzell的经典结果出发，我们推导出了局部随机波动率模型（LSV）的条件正演方程和相关的随机Dupire PDE。作为应用，我们得到了LSV中杠杆函数的密度加权Rao-Blackwell估计量。我们还根据利率建模中Musiela参数化的精神，推导了滚动到期香草期权的SPDE。

Keywords :

### 

\[7\] Detecting unusual trading patterns on cryptocurrency exchanges by means of complexity measures

标题:通过复杂性度量检测加密货币交易所的异常交易模式

作者:Jakub Zwydak, Marcin Wątorek, Jarosław Kwapień, Stanisław Drożdż

来源:ARXIV\_20260716

链接:https://arxiv.org/pdf/2607.13916

Abstract : Artificial transaction generation remains an important source of potential market manipulation on cryptocurrency exchanges, as it may distort reported liquidity and reduce market transparency. This study proposes a diagnostic framework for detecting unusual trading patterns based on complexity and statistical structure measures derived from high frequency trade level data. The analysis considers log returns, trading volume, and transaction counts, using tail distributions, autocorrelation functions, multifractal characteristics, approximate entropy, and detrended cross correlations. The methodology is applied to BTC, ETH, and XRP traded on Binance, Bitget, KuCoin, and Kraken over the period from April 1 to June 30, 2025. The results reveal a pronounced anomaly on Bitget for BTC and ETH after mid May 2025. The number of transactions increases sharply, but there is no proportional increase in traded volume or return fluctuations. This regime is characterised by numerous low volume trades, weaker autocorrelations, reduced multifractal organisation, higher short pattern irregularity, and weaker cross correlations involving the transaction count series. These features are consistent with a noise like component in trading activity and may indicate artificially increased transaction counts, although they do not provide direct proof of wash trading. The findings show that complexity based indicators can be useful for detecting exchange specific trading anomalies that remain hidden in price based measures.

Keywords : 

Abstract :人工交易生成仍然是加密货币交易所潜在市场操纵的重要来源，因为它可能会扭曲报告的流动性并降低市场透明度。本研究提出了一种诊断框架，用于根据高频交易水平数据的复杂性和统计结构指标来检测异常交易模式。该分析考虑了对数回报、交易量和交易计数，使用了尾部分布、自相关函数、多重分形特征、近似熵和去趋势互相关。该方法适用于2025年4月1日至6月30日期间在币安、Bitget、KuCoin和Kraken上交易的BTC、ETH和XRP。结果显示，2025年5月中旬之后，比特币和以太坊在Bitget上出现了明显的异常。交易数量急剧增加，但交易量或回报波动没有成比例的增加。这种制度的特点是大量的低交易量交易、较弱的自相关性、减少的多重分形组织、较高的短期模式不规则性以及涉及交易计数序列的较弱的互相关性。这些特征与交易活动中的噪声成分是一致的，可能表明人为增加了交易数量，尽管它们不能提供直接的洗钱交易证据。研究结果表明，基于复杂性的指标可用于检测隐藏在基于价格的指标中的交易所特定交易异常。

Keywords :

### 

\[8\] Equilibrium stability as a driver of cooperation among Q learners

标题:平衡稳定性是Q学习者合作的驱动力

作者:Janusz M. Meylahn, Maximilian Sch fer

来源:ARXIV\_20260716

链接:https://arxiv.org/pdf/2607.13607

Abstract : Algorithmic collusion among pricing algorithms has raised concerns about sustained supra competitive prices and their implications for social welfare. Existing work has largely focused on the probability that reinforcement learning algorithms converge to cooperative strategies, typically under the assumption that exploration vanishes over time. Motivated by the observation that algorithms deployed in practice are likely to continue exploring in order to remain adaptive to changing environments, we study learning dynamics under constant exploration. In this setting, the relevant question is no longer whether an algorithm converges to a particular strategy profile, but rather what fraction of time the algorithms spend playing cooperative strategies. Even in the benchmark case of the repeated Prisoner s Dilemma with one period memory, this yields high dimensional stochastic learning dynamics, for which a complete analytic treatment is intractable. We show that cooperative strategies can be dominant in this time averaged sense and derive a boundary predicting when such dominance arises, based on the expected dynamics of the Q learning process. Extensive simulations show that this boundary is a strong predictor for non defection dominated behaviour under epsilon greedy Q learning.

Keywords : 

Abstract :定价算法之间的算法合谋引发了人们对持续超竞争价格及其对社会福利影响的担忧。现有的工作主要集中在强化学习算法收敛到合作策略的概率上，通常是在探索随着时间的推移而消失的假设下。观察到在实践中部署的算法可能会继续探索，以保持对不断变化的环境的适应性，我们研究了不断探索下的学习动态。在这种情况下，相关的问题不再是算法是否收敛到特定的策略配置文件，而是算法在玩合作策略上花费了多少时间。即使在具有一个周期记忆的重复囚徒困境的基准情况下，这也会产生高维随机学习动力学，对此难以进行完整的分析处理。我们证明，在这种时间平均意义上，合作策略可以占主导地位，并根据Q学习过程的预期动态，推导出这种主导地位何时出现的边界预测。广泛的模拟表明，该边界是ε贪婪Q学习下非缺陷主导行为的强预测因子。

Keywords :

### 

\[9\] NeuralChaos

标题:神经混沌

作者:Anastasis Kratsios, Giulia Livieri, Philipp Schmocker

来源:ARXIV\_20260717

链接:https://arxiv.org/pdf/2607.14361

Abstract : We address fundamental challenges in representing and computing   mathbb R   d   valued predictable square integrable processes over   0,T  , collected in the space   mathcal H  2 T( mathbb R   d ) . These processes are central to continuous time stochastic control, reinforcement learning, and mathematical finance. Although Wiener chaos expansions offer strong theoretical tools, traditional computational methods are hindered by the need for large chaos dictionaries and high order iterated integrals. To overcome these obstacles, we introduce NeuralChaos    a neural operator architecture that produces elements of   mathcal H  2 T( mathbb R   d )  using only finitely many evaluations of the driving Brownian motion, while preserving predictability and square integrability. We prove that NeuralChaos is dense in   mathcal H  2 T( mathbb R   d )  and achieves the best  N  term chaoslet approximation rates for compressible and Malliavin  Sobolev regular processes. Moreover, compressibility is shown to be typical for processes from   mathcal H  2 T( mathbb R   d )  under non degenerate sub Gaussian sampling. In contrast, we show that finite dimensional Markovian neural SDE models constitute a meagre and Gaussian null subset in   mathcal H  2 T( mathbb R   d ) , regardless of discretization, whereas compressible processes are generic. Numerical experiments on a stochastic optimal control problem and dynamic hedging highlight the practical effectiveness of our approach. Our results enable more efficient and expressive modelling in stochastic analysis and mathematical finance.

Keywords : 

Abstract :我们解决了在表示和计算空间数学H 2 T（mathbb R d）中收集的0，T上的mathb R d值可预测平方可积过程方面的基本挑战。这些过程是连续时间随机控制、强化学习和数学金融的核心。尽管维纳混沌展开提供了强大的理论工具，但传统的计算方法因需要大型混沌字典和高阶迭代积分而受到阻碍。为了克服这些障碍，我们引入了NeuralChaos，这是一种神经算子架构，它只使用驱动布朗运动的有限次评估来产生数学H 2 T（mathbb R d）的元素，同时保持可预测性和平方可积性。我们证明了NeuralChaos在数学H 2 T（mathbb R d）中是稠密的，并且对于可压缩和Malliavin-Sobolev正则过程实现了最佳的N项chaoslet近似率。此外，在非简并亚高斯采样下，压缩性被证明是数学H 2 T（mathb R d）过程的典型特征。相比之下，我们表明，无论离散化如何，有限维马尔可夫神经SDE模型在数学H 2 T（mathbb R d）中都构成了一个稀疏的高斯零子集，而可压缩过程是通用的。对随机最优控制问题和动态套期保值的数值实验突出了我们方法的实际有效性。我们的结果使随机分析和数学金融中的建模更加高效和富有表现力。

Keywords :

### 

\[10\] Structure Aware Variational State Preparation for Quantum Basket Option Pricing

标题:量子篮子期权定价的结构感知变分态准备

作者:Dongwoo Kim, Zhenyu Cui, Daniel K. Park, Chihoon Lee

来源:ARXIV\_20260717

链接:https://arxiv.org/pdf/2607.14518

Abstract : Basket option pricing often relies on Monte Carlo estimation, for which quantum amplitude estimation (QAE) provides a quadratic speed up. However, the practical benefit of QAE can be limited by the depth of the state preparation circuit. We propose a structure aware quantum state preparation framework for QAE based basket option pricing. The framework uses tensor train (TT) rank information to design shallow variational state preparation circuits. In the independent regime, TT ranks remove unnecessary entangling links from a hardware efficient ansatz. In correlated basket settings, we instead prepare asset wise marginals locally and train a compact latent block to match the basket cumulative distribution function. The Basket CDF objective targets the basket pushforward distribution rather than the full joint state, directly aligning state preparation with basket dependent payoffs. Numerical experiments show that the proposed circuits replace the exponential state preparation depth scaling of exact amplitude loading with linear scaling, while maintaining low percent basket pricing errors. Additional sampling based training experiments and an end to end QAE integration study support compatibility with sample estimated training and standard QAE based pricing workflows.

Keywords : 

Abstract :篮子期权定价通常依赖于蒙特卡洛估计，量子振幅估计（QAE）为其提供了二次加速。然而，QAE的实际效益可能受到状态准备电路深度的限制。我们提出了一种基于QAE的篮子期权定价的结构感知量子态准备框架。该框架使用张量训练（TT）秩信息来设计浅变分状态准备电路。在独立机制中，TT等级从硬件高效的传输中删除了不必要的纠缠链路。在相关篮子设置中，我们转而在本地准备资产边际，并训练一个紧凑的潜在块来匹配篮子累积分布函数。篮子CDF的目标是篮子向前推的分布，而不是整个联合状态，直接将状态准备与篮子相关的收益相匹配。数值实验表明，所提出的电路用线性缩放代替了精确振幅加载的指数状态准备深度缩放，同时保持了较低的篮子定价误差百分比。额外的基于抽样的训练实验和端到端的QAE集成研究支持与样本估计训练和标准的基于QAE的定价工作流程的兼容性。

Keywords :