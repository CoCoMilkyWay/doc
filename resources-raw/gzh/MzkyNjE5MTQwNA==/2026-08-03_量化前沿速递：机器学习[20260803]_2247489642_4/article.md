# 量化前沿速递：机器学习\[20260803\]

shameless 量化前沿速递 2026-08-03 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489642&idx=4&sn=035f885b2ee3da8d216eaedb1c469279&chksm=c35d7a39ad1b4e605016ba01d7ce32169e8473a0298df1b566a74417f0c4b4905018aef3733e#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489642&idx=4&sn=035f885b2ee3da8d216eaedb1c469279&chksm=c35d7a39ad1b4e605016ba01d7ce32169e8473a0298df1b566a74417f0c4b4905018aef3733e#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Quantum Transformer BSDE Solver via Multi Layer Fully Connected Variational Quantum Circuits

基于多层全连接变分量子电路的量子变压器BSDE求解器

来源:ARXIV\_20260729

\[2\] The Human Utility Factor

人类效用因素

来源:ARXIV\_20260730

\[3\] Forcing and duality corrected contracts for volatility control

波动控制的强制和二元修正合约

来源:ARXIV\_20260730

\[4\] Emission Forecasting Based Spatial Temporal Carbon Response

基于碳时空响应的排放预测

来源:ARXIV\_20260731

\[5\] AWARE FX

意识FX

来源:ARXIV\_20260731

\[6\] FinSMART

FinSMART

来源:ARXIV\_20260731

### 

\[1\] Quantum Transformer BSDE Solver via Multi Layer Fully Connected Variational Quantum Circuits

标题:基于多层全连接变分量子电路的量子变压器BSDE求解器

作者:Howard Su, Huan-Hsin Tseng, Chi-Sheng Chen, Lance Bai

来源:ARXIV\_20260729

链接:https://arxiv.org/pdf/2607.25162

Abstract : Solving high dimensional parabolic partial differential equations (PDEs) is important in engineering, physics, and stochastic control. Deep BSDE methods reformulate semilinear PDEs as backward stochastic differential equations and admit a model based reinforcement learning interpretation, where trajectories are generated from known stochastic dynamics while a trainable model learns the gradient related control process. We propose a Quantum Transformer BSDE solver based on Multi Layer Fully Connected Variational Quantum Circuits (FC VQC). The method treats the normalized state trajectory as time  coordinate tokens and applies causal self attention to learn interactions in the adapted BSDE gradient process. All trainable model parameters are contained within the FC VQC embedding, projection, feed forward, and decoder modules, while attention and structural operations remain classical and parameter free. Experiments on three d 36 PDE benchmarks show that QTransformer consistently improves over the non attentive FC VQC baseline and outperforms the classical Transformer at compact hidden widths, while the wider classical Transformer achieves the best overall accuracy. These results demonstrate that combining causal attention with FC VQC provides an effective quantum architecture for high dimensional BSDE trajectory learning.

Keywords : 

Abstract :求解高维抛物型偏微分方程（PDE）在工程、物理和随机控制中具有重要意义。深度BSDE方法将半线性PDE重新表述为向后随机微分方程，并允许基于模型的强化学习解释，其中轨迹由已知的随机动力学生成，而可训练模型学习与梯度相关的控制过程。我们提出了一种基于多层全连接变分量子电路（FC VQC）的量子变压器BSDE求解器。该方法将归一化状态轨迹视为时间坐标标记，并应用因果自注意来学习自适应BSDE梯度过程中的交互。所有可训练的模型参数都包含在FC VQC嵌入、投影、前馈和解码器模块中，而注意力和结构操作仍然是经典的，没有参数。在三个d 36 PDE基准上的实验表明，QTransformer始终优于非关注的FC VQC基线，并在紧凑的隐藏宽度下优于经典Transformer，而较宽的经典Transformer则实现了最佳的整体精度。这些结果表明，将因果注意与FC VQC相结合，为高维BSDE轨迹学习提供了一种有效的量子架构。

Keywords :

### 

\[2\] The Human Utility Factor

标题:人类效用因素

作者:Sivasathivel Kandasamy

来源:ARXIV\_20260730

链接:https://arxiv.org/pdf/2607.26068

Abstract : Existing AI governance frameworks, including the EU AI Act and NIST AI RMF, address safety, transparency, and accountability but do not operationalize quantitative constraints on macro socioeconomic stability. As a result, AI systems may satisfy regulatory requirements while contributing to labor displacement, rising inequality, and reduced economic resilience. We introduce the Human Utility Factor (HUF), a differentiable welfare metric that models the interaction between Agency, Wellbeing, and Economic Stability as functions of three actionable policy levers  automation depth, redistribution intensity, and employment coverage. HUF yields a closed form optimal automation level and a minimum redistribution threshold below which no level of automation is welfare positive, transforming high level governance objectives into computable constraints. We evaluate HUF using a three agent multi agent reinforcement learning framework across U.S., Canadian, and Nordic policy regimes. Both analytical and PPO based agents identify welfare optimal operating regions and reveal a critical failure mode  welfare metrics that do not explicitly constrain redistribution can converge to high automation equilibria that satisfy the metric while undermining its intended societal objectives. Our results suggest that AI governance is fundamentally a constrained optimization problem rather than a compliance exercise. HUF provides a quantitative framework for evaluating automation policies, identifying socioeconomic stability boundaries, and supporting governance decisions under accelerating AI deployment.

Keywords : 

Abstract :现有的人工智能治理框架，包括《欧盟人工智能法案》和《美国国家标准与技术研究院人工智能风险管理框架》，解决了安全、透明度和问责制问题，但没有对宏观社会经济稳定实施量化约束。因此，人工智能系统可能会满足监管要求，同时导致劳动力流离失所、不平等加剧和经济弹性降低。我们引入了人类效用因子（HUF），这是一种可区分的福利指标，它将机构、福利和经济稳定之间的相互作用建模为三个可操作的政策杠杆的函数——自动化深度、再分配强度和就业覆盖率。HUF产生了一个封闭形式的最优自动化水平和一个最小再分配阈值，低于这个阈值，任何自动化水平都不会对福利产生积极影响，从而将高层治理目标转化为可计算的约束。我们使用美国、加拿大和北欧政策制度中的三代理多代理强化学习框架来评估HUF。基于分析和PPO的代理都能识别福利最优操作区域，并揭示一个关键的故障模式——没有明确约束再分配的福利指标可以收敛到满足该指标的高度自动化均衡，同时破坏其预期的社会目标。我们的研究结果表明，人工智能治理从根本上说是一个受约束的优化问题，而不是一个合规性练习。HUF提供了一个定量框架，用于评估自动化政策，确定社会经济稳定边界，并在加速人工智能部署的情况下支持治理决策。

Keywords :

### 

\[3\] Forcing and duality corrected contracts for volatility control

标题:波动控制的强制和二元修正合约

作者:Alessandro Chiusolo, Emma Hubert, Dylan Possamaï, Nizar Touzi

来源:ARXIV\_20260730

链接:https://arxiv.org/pdf/2607.27039

Abstract : In this paper, we revisit the construction of optimal incentives in continuous time principal agent problems with drift and volatility control. Originally, a general approach relying on dynamic programming and second order backward stochastic differential equations (2BSDEs) was developed by Cvitani , Possama , and Touzi (2018)  8  to determine the optimal form of contracts in this setting. More recently, Chiusolo and Hubert (2026)  5  proposed a BSDE based approach by introducing an alternative  contractible volatility  problem for the principal. In addition to the proposed new method, this work highlights that the optimality result of  8  actually hinges on an assumption, stated below as Assumption 2.3, which may not hold in general. Motivated by this, we introduce in this paper a more general class of contracts, parametrised by a function   psi  subject to conditions that make the contract revealing for the agent and without loss of generality for the principal. We further provide two natural specifications of   psi   one, inspired by the BSDE approach, yielding a forcing type contract  the other, motivated by the 2BSDE approach, correcting the duality gap when Assumption 2.3 is not satisfied.

Keywords : 

Abstract :本文重新审视了具有漂移和波动控制的连续时间委托代理问题中最优激励的构建。最初，Cvitani、Possama和Touzi（2018）8开发了一种依赖于动态规划和二阶向后随机微分方程（2BSDE）的通用方法，以确定这种情况下合同的最佳形式。最近，Chiusolo和Hubert（2026）5通过引入本金的另一种可收缩波动率问题，提出了一种基于BSDE的方法。除了提出的新方法外，这项工作还强调，8的最优性结果实际上取决于一个假设，如下所述的假设2.3，这可能不适用于一般情况。受此启发，我们在本文中介绍了一类更一般的合同，由函数psi参数化，该函数受制于使合同对代理人具有启示性且对委托人不丧失普遍性的条件。我们还提供了两种自然的psi规范——一种是受BSDE方法的启发，产生了一种强制型契约；另一种是由2BSDE方法驱动，在假设2.3不满足时纠正了二元性差距。

Keywords :

### 

\[4\] Emission Forecasting Based Spatial Temporal Carbon Response

标题:基于碳时空响应的排放预测

作者:Feiyu Cai, Jing Qiu, Yi Yang, Chenxi Zhang, Xinlei Wang, Baichuan Liu, Junhua Zhao

来源:ARXIV\_20260731

链接:https://arxiv.org/pdf/2607.26560

Abstract : As a major contributor to carbon emissions, the decarbonization of power systems has garnered significant societal attention. Nodal carbon intensity (NCI), a critical factor in carbon oriented demand response, has traditionally been determined through ex post calculations. However, this ex post approach introduces latency in low carbon dispatch. To address this, this paper presents a proactive ex ante spatial temporal carbon response framework. At its core, we develop a novel deep learning based hierarchical design, enhanced by a dual stage attention mechanism and a large language model (LLM) based multi agent cooperation system, to accurately forecast day ahead NCI. This design effectively mitigates the impact of renewable energy uncertainty and enhances predictive resilience. On the demand side, the framework proposes a spatial temporal carbon scheduling model that integrates geographically dispatchable loads (GDLs), including mobile energy storage systems (MESSs) and distributed data centers (DDCs). Leveraging high accuracy day ahead NCI predictions, the framework can effectively reduce system emissions by quickly responding to carbon intensity fluctuations. The proposed framework is tested on the modified IEEE 33 bus system. According to the simulation results, the impacts of proposed framework on dispatching latency and emission outcomes are analyzed. The results demonstrate that under a one hour reduction in carbon scheduling latency, the proposed model and methodology can achieve over 30  emission reduction. This research breaks through the limitations of passive carbon accounting, advancing toward proactive carbon management. It offers an intelligent solution that accelerates the transition to cleaner power systems while directly supporting sustainable production goals.

Keywords : 

Abstract :作为碳排放的主要贡献者，电力系统的脱碳引起了社会的广泛关注。节点碳强度（NCI）是碳导向需求响应的关键因素，传统上是通过事后计算来确定的。然而，这种事后方法在低碳调度中引入了延迟。为了解决这个问题，本文提出了一种主动的事前时空碳响应框架。其核心是，我们开发了一种基于深度学习的分层设计，通过双阶段注意力机制和基于大型语言模型（LLM）的多智能体协作系统进行了增强，以准确预测日前NCI。这种设计有效地减轻了可再生能源不确定性的影响，并增强了预测弹性。在需求方面，该框架提出了一种时空碳调度模型，该模型整合了地理上可调度的负载（GDL），包括移动储能系统（MESS）和分布式数据中心（DDC）。利用高精度的日前NCI预测，该框架可以通过快速响应碳强度波动来有效减少系统排放。所提出的框架在改进的IEEE 33总线系统上进行了测试。根据仿真结果，分析了所提出的框架对调度延迟和排放结果的影响。结果表明，在碳调度延迟减少一小时的情况下，所提出的模型和方法可以实现30多个减排目标。本研究突破了被动碳核算的局限性，向主动碳管理迈进。它提供了一种智能解决方案，可以加速向更清洁的电力系统过渡，同时直接支持可持续生产目标。

Keywords :

### 

\[5\] AWARE FX

标题:意识FX

作者:Qi Wang

来源:ARXIV\_20260731

链接:https://arxiv.org/pdf/2607.27611

Abstract : Corporate annual reports contain weakly structured evidence about foreign exchange risk management, derivative use, natural hedging, and explicit non use. This study develops AWARE FX, an auditable AI NLP decision support system that converts report text into traceable firm year hedging disclosure measures. The system combines a professional source lexicon, negation and accounting status logic, channel specific financial encoders, exact evidence gates, conservative aggregation, and an audit ledger. Across 24,909 Hong Kong firm years from 2008 2025, it retrieves and scores 543,527 snippets. Reliability is evaluated through ablations, a stratified 300 snippet human audit, three seed FinBERT ModernBERT comparisons, strict 2023 2025 temporal tests, probability calibration, selective prediction, and fixed prompt generative model benchmarks. FinBERT has the higher mean F1 in seven of eight encoder task split comparisons  its temporal F1 ranges from 0.702 to 0.872. Abstaining on the 20  least confident temporal observations raises retained sample F1 by 0.050 0.077. Deterministic Qwen3 8B performs strongly on commodity and negation evidence but poorly on foreign debt and accounting context labels, showing that a general purpose LLM does not uniformly replace domain constraints. The strict FX score is negatively associated with linked baseline and stress period FX exposure, whereas the generic broad score is not. These associations provide external construct validation, not causal estimates of hedging effectiveness. AWARE FX contributes a tested decision support architecture in which retrieval, status logic, classification, uncertainty handling, aggregation, and external validation remain separately auditable.

Keywords : 

Abstract :公司年度报告包含有关外汇风险管理、衍生品使用、自然对冲和明确不使用的弱结构化证据。本研究开发了AWARE FX，这是一个可审计的AI NLP决策支持系统，可以将报告文本转换为可追溯的公司年度套期保值披露指标。该系统结合了专业的源词典、否定和会计状态逻辑、特定渠道的财务编码器、精确的证据门、保守的汇总和审计分类账。从2008年到2025年，在香港24909家公司的年份中，它检索并得分543527个片段。通过消融、300片段分层人工审计、三种子FinBERT ModernBERT比较、严格的2023-2025时间测试、概率校准、选择性预测和固定的即时生成模型基准来评估可靠性。FinBERT在八个编码器任务分割比较中的七个中具有较高的平均F1，其时间F1范围为0.702至0.872。对20个最不可信的时间观测结果进行弃权，保留样本F1增加了0.050 0.077。确定性Qwen3 8B在商品和否定证据方面表现强劲，但在外债和会计背景标签方面表现不佳，表明通用LLM并不能统一取代领域约束。严格的外汇评分与相关的基线和压力期外汇敞口呈负相关，而通用的广义评分则不然。这些关联提供了外部结构验证，而不是对冲有效性的因果估计。AWARE FX提供了一个经过测试的决策支持架构，其中检索、状态逻辑、分类、不确定性处理、聚合和外部验证仍然可以单独审计。

Keywords :

### 

\[6\] FinSMART

标题:FinSMART

作者:Giorgos Iacovides, Wuyang Zhou, Danilo Mandic

来源:ARXIV\_20260731

链接:https://arxiv.org/pdf/2607.28127

Abstract : Recent advances in Generative AI have substantially improved financial sentiment analysis through post trained financial large language models (LLMs). However, existing approaches remain confined to a market agnostic, supervised learning paradigm that relies on limited, static and human annotated datasets, and thus are incapable of adapting to evolving market conditions. To address this limitation, we introduce FinSMART, the first market aligned reinforcement learning framework for financial sentiment analysis, which directly optimizes sentiment signals using realized market outcomes. To deal with the noisy, non stationary, and multifactorial nature of financial markets, FinSMART incorporates a signal extraction pipeline that combines market aware data filtering with a discrete asymmetric trading reward, enabling stable reinforcement learning from economically meaningful market feedback. Experimental results demonstrate that FinSMART significantly outperforms existing state of the art methods in profitability, risk adjusted performance, and sentiment signal quality, improving cumulative trading returns by 220  over the strongest baseline. Uniquely, the FinSMART framework naturally supports market aware retraining, at any point in time, by replacing costly manual annotation with newly observed financial articles and their realized market outcomes. Such a retraining strategy enables the model to continuously adapt to changing market dynamics, resulting in consistent performance gains over its static counterpart. These findings demonstrate the practical applicability of market aligned reinforcement learning and highlight its potential as a next generation paradigm for developing adaptive financial LLMs.

Keywords : 

Abstract :生成式人工智能的最新进展通过后训练的金融大型语言模型（LLM）大大改善了金融情绪分析。然而，现有的方法仍然局限于一种与市场无关的监督学习范式，这种范式依赖于有限的、静态的和人工注释的数据集，因此无法适应不断变化的市场条件。为了解决这一局限性，我们引入了FinSMART，这是第一个用于金融情绪分析的市场对齐强化学习框架，它使用实现的市场结果直接优化情绪信号。为了应对金融市场的嘈杂、非平稳和多因素性质，FinSMART整合了一个信号提取管道，该管道将市场感知数据过滤与离散的不对称交易奖励相结合，从而能够从具有经济意义的市场反馈中稳定地强化学习。实验结果表明，FinSMART在盈利能力、风险调整绩效和情绪信号质量方面明显优于现有的最先进方法，在最强的基线上将累计交易回报提高了220。独特的是，FinSMART框架通过用新观察到的金融文章及其实现的市场结果替换昂贵的手动注释，在任何时间点自然支持市场意识再培训。这种再培训策略使模型能够不断适应不断变化的市场动态，从而比静态模型获得一致的性能提升。这些发现证明了市场导向强化学习的实用性，并强调了其作为开发适应性金融LLM的下一代范式的潜力。

Keywords :