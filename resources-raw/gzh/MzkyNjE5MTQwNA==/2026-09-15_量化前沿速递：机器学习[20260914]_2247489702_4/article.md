# 量化前沿速递：机器学习\[20260914\]

shameless 量化前沿速递 2026-09-15 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489702&idx=4&sn=e16c48c9b055fc7a7863d21c6ff17db9&chksm=c3d5d87eb00de0fe7b9136e1b881c1e21a8f14dd05a318886e984c1b7e0b0c185de0a9113460#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489702&idx=4&sn=e16c48c9b055fc7a7863d21c6ff17db9&chksm=c3d5d87eb00de0fe7b9136e1b881c1e21a8f14dd05a318886e984c1b7e0b0c185de0a9113460#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Explainable Deep Learning for Price Trade Dynamics

价格交易动态的可解释深度学习

来源:ARXIV\_20260909

\[2\] Nystr m Attention Matches Full Attention for Cross Sectional Stock Prediction

Nystr m注意力匹配全注意力进行横截面股票预测

来源:ARXIV\_20260909

\[3\] Adaptive Entangled Game Modules in Artificial General Intelligence

通用人工智能中的自适应纠缠博弈模块

来源:ARXIV\_20260910

\[4\] Adversarial Training for Tabular Credit Scoring

表格信用评分对抗训练

来源:ARXIV\_20260910

### 

\[1\] Explainable Deep Learning for Price Trade Dynamics

标题:价格交易动态的可解释深度学习

作者:Manuel Naviglio, Fabrizio Lillo

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.06085

Abstract : Understanding the joint dynamics of prices and trades is central to market microstructure, where returns and order flow interact through nonlinear and state dependent mechanisms. Linear models are interpretable but may miss these effects, while deep neural networks improve forecasting at the cost of transparency. We use neural networks as tools for structural discovery rather than only for prediction. A deep feed forward network is trained on high frequency returns and signed volumes for large  and small tick stocks and compared with a linear VAR benchmark. The neural network improves predictive performance, especially for returns, revealing nonlinear dependencies beyond the linear specification. Using Shapley based explainability, we show that the dominant contributions are concentrated at the most recent lags. Model implied responses are consistent with conditional averages reconstructed from the data. Unlike empirical averages, however, the neural network decomposition isolates individual regressor contributions to the aggregate dependence. Lagged signed volume generates sign preserving and saturating effects, consistent with nonlinear price impact and order flow persistence. Lagged returns act as state variables  when the previous trade does not move the price, the model predicts continuation in the direction of past order flow, whereas non zero returns generate attenuation or reversal. Building on these findings, we introduce a parsimonious SHAP inspired nonlinear parametric model. It reproduces the main return volume dependencies, outperforms the linear VAR benchmark, and achieves performance comparable to the neural network. A multi lag extension captures residual longer memory effects while preserving interpretability. Overall, explainability offers a route from black box prediction to economically meaningful parametric models of price and trade dynamics.

Keywords : 

Abstract :理解价格和交易的联合动态是市场微观结构的核心，在市场微观结构中，回报和订单流通过非线性和状态依赖机制相互作用。线性模型是可以解释的，但可能会忽略这些影响，而深度神经网络以牺牲透明度为代价来提高预测。我们使用神经网络作为结构发现的工具，而不仅仅是预测。深度前馈网络针对大型和小型蜱虫股票的高频回报和有符号交易量进行训练，并与线性VAR基准进行比较。神经网络提高了预测性能，特别是对于回报，揭示了超出线性规范的非线性依赖关系。使用基于Shapley的可解释性，我们表明主导贡献集中在最近的滞后期。模型隐含响应与从数据中重建的条件平均值一致。然而，与经验平均值不同，神经网络分解将个体回归因素对总体依赖性的贡献隔离开来。滞后的有符号交易量会产生符号保持和饱和效应，这与非线性价格影响和订单流持续性是一致的。当前一笔交易不影响价格时，滞后回报充当状态变量，该模型预测过去订单流方向的延续，而非零回报则产生衰减或反转。基于这些发现，我们引入了一个简约的SHAP启发的非线性参数模型。它再现了主要的回报量依赖关系，优于线性VAR基准，并实现了与神经网络相当的性能。多滞后扩展在保持可解释性的同时捕获了剩余的较长记忆效应。总体而言，可解释性提供了一条从黑匣子预测到价格和贸易动态的具有经济意义的参数模型的途径。

Keywords :

### 

\[2\] Nystr m Attention Matches Full Attention for Cross Sectional Stock Prediction

标题:Nystr m注意力匹配全注意力进行横截面股票预测

作者:Kunhan Guo

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.08106

Abstract : MASTER s inter stock multi head attention    the module responsible for modeling cross sectional stock relationships    accounts for 42.5  of model parameters and 25  of predictive value. We systematically decompose this module and uncover a surprising structure  the learned attention is near uniform (perplexity 278 300), yet forcing exact uniformity eliminates all cross sectional discrimination. Spectral analysis resolves this paradox  the deviation from uniformity is low rank (effective rank  65, top 10 modes capture 96.5  of energy), explaining why sparse approximations consistently fail while Nystrom low rank attention (m 32 landmarks) matches full O(N 2) attention at O(mN) cost    certified equivalent via TOST at both N 300 (5 seeds, Rank IC p 0.003) and N 800 (10 seeds, Rank IC p 0.034). Additional findings include  (i) attention anti correlates with return similarity (Spearman rho    0.614  on the industry labeled subset,  0.645 unconditionally and  0.627 after controlling for industry, beta, and volatility), suggesting complementarity seeking rather than correlation mining  (ii) all graph based alternatives degrade performance, with hard masking worse than complete module removal  and (iii) at N   3,500 with adapted architectures, no cross stock module (GCN, Nystrom, or MASTER style pipeline) significantly outperforms a per stock LSTM baseline (n 4 seeds), indicating that the benefits observed at smaller scales do not trivially transfer. These results establish that the inter stock attention s value resides in a compressible, dynamic, near global redistribution that rewards low rank approximation but resists sparsification.

Keywords : 

Abstract :MASTER的股票间多头关注负责建模横截面股票关系的模块占模型参数的42.5和预测值的25。我们系统地分解了这个模块，发现了一个令人惊讶的结构——学习到的注意力几乎是均匀的（困惑278 300），但强制精确的均匀性消除了所有的横截面歧视。光谱分析解决了这一悖论——与均匀性的偏差是低秩的（有效秩65，前10个模式捕获96.5的能量），这解释了为什么稀疏近似总是失败，而Nystrom低秩注意力（m 32个界标）在N 300（5个种子，秩IC p 0.003）和N 800（10个种子，阶IC p 0.034）下以O（mN）的成本匹配完全的O（N 2）注意力。其他发现包括：（i）注意力与回报相似性呈反相关（在行业标记的子集上为Spearman rho 0.614，在控制行业、贝塔系数和波动性后为0.645，无条件为0.627），表明互补性寻求而非相关性挖掘；（ii）所有基于图的替代方案都会降低性能，硬掩模比完全移除模块更糟糕；（iii）在N 3500的适配架构下，没有跨股票模块（GCN、Nystrom或MASTER风格的管道）显著优于每股LSTM基线（N 4种子），表明在较小尺度上观察到的收益不会轻易转移。这些结果表明，股票间注意力的价值在于一种可压缩的、动态的、接近全局的再分配，这种再分配奖励低秩近似，但抵制稀疏化。

Keywords :

### 

\[3\] Adaptive Entangled Game Modules in Artificial General Intelligence

标题:通用人工智能中的自适应纠缠博弈模块

作者:Haochen Li, Xinshuai Guo, Jingdong Ouyang, Wei Zhang, Leilei Shi

来源:ARXIV\_20260910

链接:https://arxiv.org/pdf/2609.09226

Abstract : We introduce a probability wave framework for modeling the collective behavior of interacting adaptive agents, deriving testable eigenmodes through a generalized behavioral intelligence (GBI) nonlocal probability wave equation. This framework captures a broad range of human intelligence behaviors with analytical mechanisms and offers an indirect method to examine the Liu Chen Ao (LCA) hypothesis of nonlocal entangled nerve fibers in the brain through collective trader behaviors. Our empirical analysis of Chinese intraday stock market data demonstrates that adaptive entangled game modes explain 82 94  (89  overall) of observed decision patterns, a sharp contrast to the predictions of neoclassical finance based on independent rational agents. Moreover, 2 12  of behaviors show adaption to intraday news, events, and environments, characterized by dual equilibrium states and abrupt reference point shifts, while purely independent modes occur in less than 5  of cases. These findings empirically support the LCA hypothesis, as observable trading behaviors reflect underlying brain mechanisms and internal intelligence decision making in behavioral psychology. Our results highlight the necessity of incorporating adaptive entangled game modules into artificial general intelligence (AGI) architectures, addressing the limitations of conventional artificial neural network (ANN) based AI, which relies on trillions of opaque parameters. By integrating ANN based AI with probability wave based entangled brain simulations, machine learning can enrich AGI foundation models (FMs) and facilitate the development of human like processing units (HPUs) that leverage brain inspired mechanisms. Such HPUs may ultimately create more compact, efficient, and robust AGI systems, particularly for embodied intelligence and robotics.

Keywords : 

Abstract :我们引入了一个概率波框架，用于对相互作用的自适应主体的集体行为进行建模，通过广义行为智能（GBI）非局部概率波方程推导出可测试的特征模。该框架通过分析机制捕捉了广泛的人类智能行为，并提供了一种间接方法来检验刘振敖（LCA）关于大脑中非局部纠缠神经纤维通过集体交易者行为的假设。我们对中国股市日内数据的实证分析表明，自适应纠缠博弈模式解释了8294（总共89）个观察到的决策模式，这与基于独立理性主体的新古典金融预测形成了鲜明对比。此外，212种行为表现出对日内新闻、事件和环境的适应，其特征是双重平衡状态和突然的参考点偏移，而纯粹独立的模式出现在不到5种情况下。这些发现从实证上支持了LCA假说，因为可观察到的交易行为反映了行为心理学中潜在的大脑机制和内部智力决策。我们的研究结果强调了将自适应纠缠游戏模块纳入通用人工智能（AGI）架构的必要性，解决了传统基于人工神经网络（ANN）的人工智能的局限性，该人工智能依赖于数万亿不透明参数。通过将基于ANN的人工智能与基于概率波的纠缠大脑模拟相结合，机器学习可以丰富AGI基础模型（FM），并促进利用大脑启发机制的类人处理单元（HPU）的开发。这样的HPU最终可能会创建更紧凑、高效和鲁棒的AGI系统，特别是用于嵌入式智能和机器人。

Keywords :

### 

\[4\] Adversarial Training for Tabular Credit Scoring

标题:表格信用评分对抗训练

作者:Gijs A. F. Niewzwaag, Marijn G. S. Veth, Manuele Massei, Marcos R. Machado

来源:ARXIV\_20260910

链接:https://arxiv.org/pdf/2609.09945

Abstract : Machine learning based credit scoring is increasingly central to Peer to Peer (P2P) lending, yet its resilience to adversarial manipulation, where applicants strategically alter self reported inputs to secure favourable decisions, remains poorly understood. Most adversarial robustness evidence comes from image and text domains and evaluates a single attack against a matching defence, offering little guidance on how defences generalise across attack types in tabular credit data. We address this with a systematic train test robustness benchmark on a large Lending Club subset, spanning three model families (logistic regression, a feed forward neural network, and a transformer for tabular data) and four attacks confined to applicant mutable features  Fast Gradient Sign Method (FGSM), Projected Gradient Descent (PGD), Salt and Pepper (S&P) noise, and DeepFool, plus a mixed attack regime. Across a full grid evaluated with stratified cross validation, adversarial training sharply improves robustness against the attack it is trained on and transfers well within the gradient based family, but transfers weakly to non gradient corruption, so single attack defences overstate real world resilience. Mixed training delivers the most balanced robustness across heterogeneous attacks while preserving clean test performance, supporting multi attack stress testing in credit model governance.

Keywords : 

Abstract :基于机器学习的信用评分在点对点（P2P）贷款中越来越重要，但它对对抗性操纵的弹性仍然知之甚少，在对抗性操纵中，申请人战略性地改变自我报告的投入以确保有利的决策。大多数对抗性稳健性证据来自图像和文本域，并评估针对匹配防御的单一攻击，对于防御如何在表格信用数据中跨攻击类型推广，几乎没有提供任何指导。我们通过在大型Lending Club子集上进行系统的训练测试鲁棒性基准来解决这个问题，该子集跨越了三个模型家族（逻辑回归、前馈神经网络和表格数据转换器）和四种攻击，这些攻击仅限于申请人可变特征——快速梯度符号法（FGSM）、投影梯度下降（PGD）、盐和胡椒（S&P）噪声和DeepFool，以及混合攻击机制。在通过分层交叉验证评估的整个网格中，对抗性训练显著提高了对所训练攻击的鲁棒性，并在基于梯度的家族中很好地传递，但向非梯度腐败的传递较弱，因此单次攻击防御夸大了现实世界的弹性。混合训练在异构攻击中提供了最平衡的鲁棒性，同时保持了干净的测试性能，支持信用模型治理中的多攻击压力测试。

Keywords :