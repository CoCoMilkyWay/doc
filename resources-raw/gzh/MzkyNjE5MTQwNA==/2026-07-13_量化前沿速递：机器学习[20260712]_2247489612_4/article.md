# 量化前沿速递：机器学习\[20260712\]

shameless 量化前沿速递 2026-07-13 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489612&idx=4&sn=2e7a260da5f37489304940b5d19ee0d9&chksm=c30be1a1b6b430ba6da14126a1e996d1f1cfb66d75995ac0c8aa5e4a3119cc8ed96ba4fdaa99#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489612&idx=4&sn=2e7a260da5f37489304940b5d19ee0d9&chksm=c30be1a1b6b430ba6da14126a1e996d1f1cfb66d75995ac0c8aa5e4a3119cc8ed96ba4fdaa99#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Deep Learning for Dynamic Programming with Recursive Utility

基于递归效用的动态规划深度学习

来源:ARXIV\_20260707

\[2\] A harmonised dataset for Earth system foundation models

地球系统基础模型的协调数据集

来源:ARXIV\_20260707

\[3\] Look Ahead Freedom as Temporal Non Interference

将自由视为时间上的不干涉

来源:ARXIV\_20260707

\[4\] SHARC

SHARC

来源:ARXIV\_20260708

\[5\] Can Reinforcement Learning Efficiently Discover Price Manipulation 

强化学习能否有效发现价格操纵

来源:ARXIV\_20260708

\[6\] Memory Scarcity, Open Models, and the Restructuring of the AI Industry, 2026 2030    A quantitative scenario analysis of inference economics, training cost divergence, and infrastructure solvency

内存短缺、开放模型和人工智能产业的重组，2026-2030推理经济学、培训成本差异和基础设施偿付能力的定量情景分析

来源:ARXIV\_20260709

\[7\] A Comparative Review of Methods to Create a Composite Index for Sustainable and Inclusive Wellbeing

可持续和包容性福祉综合指数创建方法的比较综述

来源:ARXIV\_20260710

### 

\[1\] Deep Learning for Dynamic Programming with Recursive Utility

标题:基于递归效用的动态规划深度学习

作者:Xianhua Peng, Wu Guo

来源:ARXIV\_20260707

链接:https://arxiv.org/pdf/2607.04278

Abstract : We propose the first deep learning algorithm, the Certainty Equivalent Learning (CEL) algorithm, for solving high dimensional discrete time dynamic programming problems with recursive utility. Dynamic programming with recursive utility is numerically challenging because the recursive utility does not have an explicit representation and the Bellman equation contains a certainty equivalent that is difficult to evaluate. The CEL algorithm learns this certainty equivalent value directly with neural networks and jointly approximates value functions, policy functions, and certainty equivalent functions. The CEL algorithm is mesh free and simulation based, allowing high dimensional state and control spaces, and does not rely on Euler equations, first order conditions, or differentiability of the state transition function. The CEL algorithm also works for dynamic programming problems with expected utility as expected utility is a special case of recursive utility. We apply the CEL to discounted linear exponential quadratic Gaussian control, small noise robust control, Epstein Zin DSGE, and multivariate strategic asset allocation problems. Compared with closed form and VFI based benchmarks, the CEL delivers accurate value and policy approximations, remains effective in high dimensional problems, achieves accuracy comparable to VFI in the small noise robust control case, and produces out of sample Bellman errors and Euler or first order residuals that are in the range from 1.0e 4 to 1.0e 3 for most problems.

Keywords : 

Abstract :我们提出了第一种深度学习算法，即确定性等价学习（CEL）算法，用于解决具有递归效用的高维离散时间动态规划问题。具有递归效用的动态规划在数值上具有挑战性，因为递归效用没有显式表示，而贝尔曼方程包含一个难以计算的确定性等价物。CEL算法直接用神经网络学习这个确定性等价值，并联合近似值函数、策略函数和确定性等价函数。CEL算法是无网格的，基于仿真，允许高维状态和控制空间，不依赖于欧拉方程、一阶条件或状态转移函数的可微性。CEL算法也适用于具有期望效用的动态规划问题，因为期望效用是递归效用的特例。我们将CEL应用于贴现线性指数二次高斯控制、小噪声鲁棒控制、Epstein-Zin DSGE和多元战略资产配置问题。与封闭形式和基于VFI的基准相比，CEL提供了精确的值和策略近似值，在高维问题中仍然有效，在小噪声鲁棒控制情况下达到了与VFI相当的精度，并且对于大多数问题，产生了样本外的贝尔曼误差和欧拉或一阶残差，其范围在1.0e 4到1.0e 3之间。

Keywords :

### 

\[2\] A harmonised dataset for Earth system foundation models

标题:地球系统基础模型的协调数据集

作者:Carlos Rodriguez-Pardo, Massimo Tavoni

来源:ARXIV\_20260707

链接:https://arxiv.org/pdf/2607.03298

Abstract : Foundation models for Earth systems have so far been trained primarily on physical climate and weather data, with limited representation of the human systems that both drive and respond to environmental change. The lack of a unified global training resource that combines climate, land, ocean, cryosphere, infrastructure, hazards, and socioeconomic data on a common grid hinders progress toward truly multimodal Earth system foundation models. We present WorldTensor, a harmonised global dataset that aligns hundreds of environmental and socioeconomic variables to a standardised 0.25   circ  spatial grid and annual temporal framework. WorldTensor integrates reanalysis products, remote sensing, emissions inventories, land use reconstructions, hydrological observations, infrastructure and hazard datasets, and socioeconomic indicators within a single representation designed for machine learning workflows. To build the dataset, we regridded inputs across heterogeneous native resolutions and projections, rasterised point and vector datasets into spatially meaningful gridded fields, and reconciled temporal coverages ranging from daily observations to sparse multiyear socioeconomic snapshots. All outputs are distributed as NetCDF files with standardised coordinates, variable metadata, and a common CF metadata convention. WorldTensor provides a reproducible resource for training and evaluating foundation models that learn coupled dynamics across environmental and human systems at planetary scale.

Keywords : 

Abstract :迄今为止，地球系统的基础模型主要基于物理气候和天气数据进行训练，对驱动和应对环境变化的人类系统的代表性有限。缺乏一个统一的全球培训资源，将气候、土地、海洋、冰冻圈、基础设施、灾害和社会经济数据结合在一个共同的网格上，阻碍了真正多模式地球系统基础模型的进展。我们介绍了WorldTensor，这是一个协调的全球数据集，将数百个环境和社会经济变量与标准化的0.25圈空间网格和年度时间框架对齐。WorldTensor将再分析产品、遥感、排放清单、土地利用重建、水文观测、基础设施和灾害数据集以及社会经济指标集成在一个为机器学习工作流程设计的单一表示中。为了构建数据集，我们对不同原生分辨率和投影的输入进行了重新分级，将栅格化的点和矢量数据集重新划分为具有空间意义的网格字段，并协调了从日常观测到稀疏多年社会经济快照的时间覆盖范围。所有输出都以NetCDF文件的形式分发，具有标准化的坐标、可变元数据和通用的CF元数据约定。WorldTensor为训练和评估基础模型提供了一种可重复的资源，这些模型在行星尺度上学习环境和人类系统的耦合动力学。

Keywords :

### 

\[3\] Look Ahead Freedom as Temporal Non Interference

标题:将自由视为时间上的不干涉

作者:Xavier Fonseca

来源:ARXIV\_20260707

链接:https://arxiv.org/pdf/2607.04958

Abstract : Look ahead bias (using information from after a decision epoch to make the decision at that epoch) is the dominant way a backtest or a machine learning evaluation flatters a system that will disappoint in deployment. The field manages it with construct specific recipes and empirical detectors, which are sound only channel by channel and certify nothing by their silence. We show that look ahead freedom is a formal property in disguise  fixing an epoch, the demand that the future not influence the present is temporal non interference over a time indexed information lattice. From this identification we develop a pipeline calculus separating a datum s availability from its reference time, and settle the problem s boundary. Where availability may depend on data values, look ahead freedom is undecidable (indeed Pi 0 1 hard)  leakage is recursively enumerable but freedom is not. On the value independent fragment (covering windowing, resampling, joins, point in time and vintage reads, and agentic retrieval) we give a type and effect system that is sound and decidable in linear time. An artifact confirms the theory  the check scales linearly, an independent oracle witnesses no leak in any accepted pipeline, and the checker catches every planted leak that differential and tiling detectors miss.

Keywords : 

Abstract :前瞻性偏见（使用决策期后的信息在该时期做出决策）是回溯测试或机器学习评估的主要方式，它会使系统在部署中令人失望。该领域通过构建特定的配方和经验检测器来管理它，这些配方和检测器逐个通道只检测声音，不会通过它们的沉默来证明任何东西。我们证明，前瞻自由是一种伪装成固定纪元的形式属性，未来不影响现在的要求是时间索引信息格上的时间非干扰。根据这种识别，我们开发了一种管道演算，将数据的可用性与其参考时间分开，并解决了问题的边界。在可用性可能取决于数据值的情况下，前瞻自由是不可判定的（实际上Pi 0 1硬）泄漏是递归可枚举的，但自由不是。在与值无关的片段（包括窗口、重采样、连接、时间点和复古读取以及代理检索）上，我们给出了一个在线性时间内健全且可判定的类型和效果系统。人工制品证实了检查线性缩放的理论，独立的预言机见证了任何可接受的管道中都没有泄漏，检查器捕获了差分和平铺探测器遗漏的每一个植入的泄漏。

Keywords :

### 

\[4\] SHARC

标题:SHARC

作者:Ujjwala Vadrevu

来源:ARXIV\_20260708

链接:https://arxiv.org/pdf/2607.05484

Abstract : The adoption of non parametric machine learning models for regulatory capital estimation introduces a fundamental governance challenge  the inability to explain model outputs in a manner auditable by supervisory bodies. This  black box  problem remains a major barrier to the adoption of Gaussian Process Regression (GPR) and related ML architectures in ICAAP and CCAR workflows despite their predictive advantages over traditional parametric approaches.This paper addresses this barrier through SHARC (SHAP for Regulatory Capital), an explainability framework for the Hybrid GPR HS architecture and its stress testing extension. SHapley Additive exPlanations (SHAP), derived from cooperative game theory and satisfying the properties of Local Accuracy, Missingness, Consistency, and Efficiency, are applied to Stressed Value at Risk (SVaR) outputs under three macro scenarios  West Asia War, Climate Risk, and AI Bubble Regulatory Burden.SHARC decomposes SVaR into baseline, mean driven, and volatility driven components, enabling transparent linkage between scenario design and capital outcomes. Two findings emerge. First, SHARC consistently links non linear SVaR outputs to underlying scenario inputs, confirming framework fidelity and providing auditable traceability of capital drivers. Second, under stress conditions, the mean return component (directional loss magnitude) dominates the variance component (volatility baseline) in determining capital levels, with implications for capital limit setting, position management, and hedging strategy. The results establish SHARC as a regulator aligned explainability layer that makes the Hybrid GPR HS framework fully auditable and consistent with FRTB, ICAAP Pillar 2, and CCAR transparency requirements.

Keywords : 

Abstract :采用非参数机器学习模型进行监管资本估算带来了一个根本的治理挑战，即无法以监管机构可审计的方式解释模型输出。尽管高斯过程回归（GPR）和相关ML架构在ICAAP和CCAR工作流中比传统参数方法具有预测优势，但这个黑盒问题仍然是采用它们的主要障碍。本文通过SHARC（监管资本SHAP）来解决这一障碍，SHARC是混合GPR-HS架构及其压力测试扩展的可解释框架。SHapley Additive exPlanations（SHAP）基于合作博弈论，满足局部准确性、任务性、一致性和效率的特性，应用于西亚战争、气候风险和人工智能泡沫监管负担三种宏观情景下的应力风险值（SVaR）输出。SHARC将SVaR分解为基线、均值驱动和波动驱动的组成部分，实现了情景设计和资本结果之间的透明联系。出现了两个发现。首先，SHARC始终将非线性SVaR输出与底层场景输入联系起来，确认了框架的保真度，并提供了资本驱动因素的可审计可追溯性。其次，在压力条件下，平均回报成分（定向损失幅度）在确定资本水平方面主导方差成分（波动基线），这对资本限额设定、头寸管理和对冲策略都有影响。结果表明，SHARC是一个与监管机构一致的可解释层，使混合GPR-HS框架完全可审计，并符合FRTB、ICAAP支柱2和CCAR透明度要求。

Keywords :

### 

\[5\] Can Reinforcement Learning Efficiently Discover Price Manipulation 

标题:强化学习能否有效发现价格操纵

作者:Ioanna-Yvonni Tsaknaki, Andrea Macrì, Fabrizio Lillo

来源:ARXIV\_20260708

链接:https://arxiv.org/pdf/2607.06121

Abstract : In this paper, we investigate whether a model free RL agent can identify and exploit price manipulation opportunities more effectively than a traditional model based approach that assumes correct specification of the data generating process but relies on noisy parameter estimates. We consider a single asset market in which prices evolve according to an Almgren Chriss framework with non linear permanent impact and linear temporary impact. We first establish the existence of price manipulative strategies in discrete time and compute the optimal benchmark strategy using Sequential Least Squares Quadratic Programming under full information. We then compare two finite sample learning approaches  a model based procedure that estimates impact parameters from simulated execution data and an agnostic RL approach based on Deep Deterministic Policy Gradient, trained directly on the same amount of data. For intermediate volatility, the RL agent successfully discovers profitable manipulative strategies without explicit knowledge of the underlying model, even when training data are quite limited. More importantly, RL consistently outperforms the model based approach when parameter estimates are affected by sampling error, despite the latter benefiting from the correct model specification. For large volatility, all methods are unable to identify manipulation opportunities, while for small volatility, the model based approach outperforms RL. These findings highlight both the effectiveness of RL in complex control problems and the risks associated with deploying learning algorithms in financial markets without appropriate safeguards.

Keywords : 

Abstract :在这篇论文中，我们研究了无模型的RL代理是否可以比传统的基于模型的方法更有效地识别和利用价格操纵机会，这种方法假设数据生成过程的规范是正确的，但依赖于噪声参数估计。我们考虑一个单一资产市场，其中价格根据Almgren-Chriss框架演变，具有非线性永久影响和线性暂时影响。我们首先建立了离散时间内价格操纵策略的存在性，并在完全信息下使用序列最小二乘二次规划计算了最优基准策略。然后，我们比较了两种有限样本学习方法——一种基于模型的程序，从模拟执行数据中估计影响参数，另一种基于深度确定性策略梯度的不可知RL方法，直接在相同数量的数据上训练。对于中等波动性，即使训练数据非常有限，RL代理也能在不明确底层模型的情况下成功发现有利可图的操纵策略。更重要的是，当参数估计受到采样误差的影响时，RL始终优于基于模型的方法，尽管后者受益于正确的模型规范。对于大波动性，所有方法都无法识别操纵机会，而对于小波动性，基于模型的方法优于RL。这些发现突显了RL在复杂控制问题中的有效性，以及在没有适当保障的情况下在金融市场部署学习算法的风险。

Keywords :

### 

\[6\] Memory Scarcity, Open Models, and the Restructuring of the AI Industry, 2026 2030    A quantitative scenario analysis of inference economics, training cost divergence, and infrastructure solvency

标题:内存短缺、开放模型和人工智能产业的重组，2026-2030推理经济学、培训成本差异和基础设施偿付能力的定量情景分析

作者:Satoshi Matsuoka

来源:ARXIV\_20260709

链接:https://arxiv.org/pdf/2607.07207

Abstract : We analyze how four forces restructure the AI industry over 2026 2030  the DRAM HBM price surge, frontier capable open weight models (GLM 5.2), rapid inference efficiency gains (near Shannon limit KV cache compression, lightweight local runtimes), and the entry of Meta and xAI into compute resale on fleets bought before the memory repricing. Formulating inference economics in dollars per petabyte of bandwidth delivered (   PB)    model agnostic for bandwidth bound decode    we show the entrant incumbent cost gap never closes  a depreciation conveyor delivers newly amortized fleets to incumbents faster than hardware prices normalize (3.2x in 2026, 1.9x in 2027, re widening to 3 4x by 2029 30). Training bifurcates into a luxury tier (  18 38B per frontier run by 2030) and a mass tier (previous frontier parity via RL distillation falling toward   5M). Solvency of the announced buildout is confined to a corridor requiring roughly 2x annual token demand growth for four years with sticky premium pricing  a measurement critique shows public token trackers overstate monetizable demand, and all pre Q2 2026 projections predate the industry s shift from token maximization to token minimization. A vintage breakeven analysis finds 2026 and 2028 29 capacity each fatally exposed to one pricing regime, with only the 2027 vintage robust. A greenfield custom silicon entrant removes the merchant margin but not the memory premium (central outcome  25  success 34  mediocre 41  loss, improvable via staged go no go gates). China s LineShine LX2    domestic HBM on a standard ISA    decouples its cost curve from the memory crisis. Scenario probabilities  Rotating Landlord Oligopoly 25 , Commoditization Crash 25 , Jevons Absorption 20 , System Layer Re differentiation 18 , Geopolitical Bifurcation 12 . Solvency now depends on monetized bandwidth demand, premium stickiness, and vintage ownership.

Keywords : 

Abstract :我们分析了2026年至2030年四种力量如何重组人工智能行业——DRAM HBM价格飙升、前沿开放权重模型（GLM 5.2）、快速推理效率提高（接近香农极限KV缓存压缩、轻量级本地运行时间），以及Meta和xAI进入内存重新定价前购买的机队的计算转售。以每PB带宽交付（PB）的美元为单位制定推理经济学模型，该模型与带宽受限解码无关，我们表明，进入者与现有者的成本差距永远不会缩小，折旧输送机向现有者交付新摊销的车队的速度比硬件价格正常化的速度快（2026年为3.2倍，2027年为1.9倍，到2029年重新扩大到3倍30）。培训分为豪华级别（到2030年，每个前沿运行1838亿英镑）和大众级别（之前通过强化学习蒸馏实现的前沿平价降至500万英镑）。所宣布的扩建的偿付能力仅限于一个走廊，该走廊需要在四年内每年大约2倍的代币需求增长，并采用粘性溢价定价。一项衡量批评显示，公共代币追踪者夸大了可货币化的需求，而2026年第二季度之前的所有预测都早于该行业从代币最大化向代币最小化的转变。一项复古盈亏平衡分析发现，2026年和2028年的29个产能都受到一种定价制度的致命影响，只有2027年的产能表现强劲。绿地定制硅进入者消除了商家的利润，但没有消除内存溢价（中心结果25成功34平庸41失败，可通过分阶段的不通过门加以改善）。中国基于标准ISA的LineShine LX2国产HBM将其成本曲线与内存危机脱钩。情景概率旋转地主寡头垄断25，商品化崩溃25，杰文斯吸收20，系统层再分化18，地缘政治分叉12。偿付能力现在取决于货币化的带宽需求、溢价粘性和老式所有权。

Keywords :

### 

\[7\] A Comparative Review of Methods to Create a Composite Index for Sustainable and Inclusive Wellbeing

标题:可持续和包容性福祉综合指数创建方法的比较综述

作者:Ricardo da Silva Vieira, Mario Biggeri, Peter Benczur, Robert Costanza, Joseph Eastoe, Tuuli Hirvilammi, Ida Kubiszewski, Matteo Mazziotta, Kenneth Mulder, Taketo Muroya, Kelsey J. OConnor, Francesco Sarracino, Nikos Rigas, Enrico Giovannini, Rutger Hoekstra, Daniel Hopp, Edwin Horlings, Petra Krylova, Michele Melchiorri, Heriberto Tapia, Oscar Smallenbroek

来源:ARXIV\_20260710

链接:https://arxiv.org/pdf/2607.08153

Abstract : Societal goals need to shift from over reliance on gross domestic product (GDP) to broader aspects of sustainable and inclusive wellbeing (SIW). However, defining SIW and eventually measuring it with a single number is problematic because it involves many subjective and objective contributors that combine in complex, non linear ways. Conventional approaches either use linear weighted averages or reduce SIW to subjective wellbeing alone. Neither is sufficient. This paper reviews aggregation methods for SIW against nine conditions derived from needs theory and strong sustainability  limited substitutability, penalisation of imbalances, non linear transformations, respect for environmental ceilings, respect for lower limits, a formative measurement model, no correlation requirement, distributional sensitivity, cross border spillovers, and intertemporal aggregation. We compare 13 methods, from simple arithmetic means to penalty based indices, outranking multicriteria, data envelopment analysis, and insights from ecology, neuroscience, and machine learning. Our illustrative example shows that aggregation choices change significantly country rankings. Compensatory methods create similar rankings. No single method satisfies all nine conditions. We conclude that a future SIW composite indicator will require combining methods across levels  non linear normalisation, non compensatory aggregation, and measurement level choices for inclusiveness and spillovers. This paper provides a step towards the headline aggregated indicator advocated by the UN High Level Expert Group on Beyond GDP.

Keywords : 

Abstract :社会目标需要从过度依赖国内生产总值（GDP）转向可持续和包容性福祉（SIW）的更广泛方面。然而，定义SIW并最终用一个数字来衡量它是有问题的，因为它涉及许多主观和客观因素，这些因素以复杂的非线性方式结合在一起。传统方法要么使用线性加权平均值，要么仅将SIW降低到主观幸福感。两者都不够。本文回顾了基于需求理论和强可持续性有限替代性、不平衡惩罚、非线性转换、尊重环境上限、尊重下限、形成性测量模型、无相关性要求、分配敏感性、跨境溢出和跨期聚合的九种条件下的SIW聚合方法。我们比较了13种方法，从简单的算术平均值到基于惩罚的指数、超越多标准、数据包络分析，以及生态学、神经科学和机器学习的见解。我们的示例表明，汇总选择会显著改变国家排名。补偿方法也会产生类似的排名。没有一种方法能满足所有九个条件。我们得出结论，未来的SIW综合指标将需要结合非线性归一化、非补偿汇总和包容性和溢出效应的衡量水平选择等不同层次的方法。本文为联合国超越GDP高级别专家组倡导的标题汇总指标迈出了一步。

Keywords :