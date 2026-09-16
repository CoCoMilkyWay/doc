# 量化前沿速递：机器学习\[20260518\]

shameless 量化前沿速递 2026-05-18 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489529&idx=4&sn=0f1fa377c2a0f526b92373a9ed86b181&chksm=c3acb724fca8f840d1090d7121f32b1bdeb9d2501924600cd4def12c6267f32b049437b93be5#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489529&idx=4&sn=0f1fa377c2a0f526b92373a9ed86b181&chksm=c3acb724fca8f840d1090d7121f32b1bdeb9d2501924600cd4def12c6267f32b049437b93be5#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Stochastic Policy Gradient Methods in the Uncertain Volatility Model

不确定波动模型中的随机政策梯度方法

来源:ARXIV\_20260511

\[2\] A Market Rule Informed Neural Network for Efficient Imbalance Electricity Price Forecasting

基于市场规则的神经网络用于有效的不平衡电价预测

来源:ARXIV\_20260512

\[3\] The Engineering of Skew

斜交工程

来源:ARXIV\_20260512

\[4\] From Expansion to Consolidation

从扩张到整合

来源:ARXIV\_20260512

\[5\] Quantifying the Risk Return Tradeoff in Forecasting

量化预测中的风险收益权衡

来源:ARXIV\_20260512

\[6\] Nonlinear filtering with stochastic discontinuities

具有随机不连续性的非线性滤波

来源:ARXIV\_20260513

\[7\] Synthetic American Option Pricing via Jump HMM Driven Heston Implied Volatility

基于跳跃HMM驱动的赫斯顿隐含波动率的合成美式期权定价

来源:ARXIV\_20260515

\[8\] Deep Learning for Solving and Estimating Dynamic Models in Economics and Finance

用于求解和估计经济和金融动态模型的深度学习

来源:ARXIV\_20260515

### 

\[1\] Stochastic Policy Gradient Methods in the Uncertain Volatility Model

标题:不确定波动模型中的随机政策梯度方法

作者:Lokman A Abbas-Turki (LPSM), Jean-François Chassagneux (ENSAE Paris), Jean-Philippe Lemor, Grégoire Loeper, Simon Sananes (LPSM)

来源:ARXIV\_20260511

链接:https://arxiv.org/pdf/2605.06670

Abstract : The multidimensional Uncertain Volatility Model leads to robust option pricing problems under joint volatility and correlation uncertainty. Their numerical resolution quickly becomes challenging because the associated stochastic control problem is high dimensional. We propose a backward actor critic stochastic policy gradient scheme tailored to this setting. The method combines a discrete dynamic programming principle with Proximal Policy Optimization and shallow neural network approximations of both the value function and the control policy. A key ingredient is the policy parameterization  continuous controls are represented through a squashed Gaussian policy built on a C vine representation of correlation matrices, which enforces positive semidefiniteness by construction. Numerical experiments on a range of multidimensional derivatives show that the method yields accurate prices, remains computationally efficient, and compares favorably with existing Monte Carlo and machine learning based benchmarks for robust pricing in the Uncertain Volatility Model.

Keywords : 

Abstract :多维不确定波动率模型导致在联合波动率和相关性不确定性下的稳健期权定价问题。由于相关的随机控制问题是高维的，因此它们的数值分辨率很快变得具有挑战性。我们提出了一种针对这种情况量身定制的后向行动者-批评者随机策略梯度方案。该方法将离散动态规划原理与邻近策略优化和值函数和控制策略的浅层神经网络近似相结合。一个关键因素是策略参数化连续控制是通过一个基于相关矩阵的C藤表示的压缩高斯策略来表示的，该策略通过构造来强制实现半正定性。对一系列多维导数的数值实验表明，该方法可以产生准确的价格，保持计算效率，并且与不确定波动率模型中现有的蒙特卡洛和基于机器学习的稳健定价基准相比具有优势。

Keywords :

### 

\[2\] A Market Rule Informed Neural Network for Efficient Imbalance Electricity Price Forecasting

标题:基于市场规则的神经网络用于有效的不平衡电价预测

作者:Runyao Yu, Julia Lin, Derek W. Bunn, Jochen Stiasny, Wentao Wang, Yujie Chen, Tara Esterl, Peter Palensky, Jochen L. Cremer

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.09061

Abstract : Accurate and efficient imbalance electricity price forecasting is critical for industrial energy trading systems, especially as battery assets and automated bidding pipelines increasingly participate in balancing markets. However, real time forecasting is complicated by nonlinear market rule based price formation, heterogeneous input signals, and incomplete data availability caused by communication delays, publication lags, and measurement outages. This paper proposes a market rule informed neural forecasting framework that embeds imbalance price formation rules into the latent space of an expressive neural network. The proposed framework preserves raw signal information while exploiting transparent market rule priors. We further analyze operational robustness by removing price component information and characterize how forecasting performance scales with input length and forecasting horizon. Experimental results show that the proposed model achieves competitive forecasting performance with substantially fewer trainable parameters and shorter training time than generic deep learning baselines. Experimental results show that the proposed model achieves competitive forecasting performance with substantially fewer trainable parameters and shorter training time than generic deep learning baselines, demonstrating that market rule priors and expressive neural networks should be jointly used for accurate and computationally sustainable forecasting in industrial energy trading applications. The implementation is publicly available at this https URL.

Keywords : 

Abstract :准确有效的不平衡电价预测对于工业能源交易系统至关重要，特别是在电池资产和自动竞价管道越来越多地参与平衡市场的情况下。然而，实时预测因基于非线性市场规则的价格形成、异构输入信号以及通信延迟、发布滞后和测量中断导致的数据不完整而变得复杂。本文提出了一种基于市场规则的神经预测框架，该框架将不平衡价格形成规则嵌入到表达性神经网络的潜在空间中。该框架在利用透明市场规则先验的同时保留了原始信号信息。我们通过去除价格成分信息进一步分析了运营稳健性，并描述了预测绩效如何随输入长度和预测期而变化。实验结果表明，与通用深度学习基线相比，所提出的模型以更少的可训练参数和更短的训练时间实现了有竞争力的预测性能。实验结果表明，与通用深度学习基线相比，所提出的模型以更少的可训练参数和更短的训练时间实现了有竞争力的预测性能，这表明市场规则先验和表达性神经网络应联合用于工业能源交易应用中的准确和计算可持续的预测。该实现可在此https URL上公开获得。

Keywords :

### 

\[3\] The Engineering of Skew

标题:斜交工程

作者:Gregory A. Fanous

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.09123

Abstract : Volatility is the language in which finance often describes risk, but it is not the language in which institutions experience risk. Allocators live through drawdowns, liquidity needs, spending rules, rebalance decisions, board oversight, and the interval between a prior high water mark and full recovery. This paper develops a path dependent framework for asymmetric volatility management. The arithmetic of recovery is nonlinear  after a drawdown of depth  D , the required gain is  R  frac 1  1 D  1 . Lower volatility can improve geometric compounding through the familiar small return approximation  g  approx  mu  frac 1  2  sigma 2 , but symmetric de risking can also impair recovery if it sacrifices too much upside participation. The relevant design problem is therefore not volatility reduction in isolation  it is conditional exposure shaping. Skew engineering is defined here as the portfolio construction discipline of reducing harmful downside participation more than productive upside participation, controlling submergence, and preserving enough recovery participation to sustain compounding under adverse regimes. The resulting Recovery Efficiency Protocol links drawdown depth, time underwater, recovery burden reduction, and rebound participation into an allocator facing reporting discipline. Machine learning and AI methods are framed as tools for conditional estimation, regime mapping, robustness testing, and model risk governance, not as market prediction.

Keywords : 

Abstract :波动性是金融学经常用来描述风险的语言，但它不是机构体验风险的语言。分配者经历了提款、流动性需求、支出规则、再平衡决策、董事会监督以及之前的高水位和完全复苏之间的间隔。本文为非对称波动管理开发了一个路径依赖框架。在深度D下降后，恢复算法是非线性的，所需的增益为R frac 1 D 1。较低的波动性可以通过熟悉的小回报近似g近似μfrac 1 2 sigma 2来改善几何复合，但如果牺牲太多的上行参与，对称的去风险也会损害复苏。因此，相关的设计问题不是孤立地降低波动率，而是有条件的敞口塑造。这里将偏斜工程定义为投资组合构建学科，即减少有害的下行参与，而不是生产性的上行参与，控制淹没，并保持足够的采收参与，以在不利条件下维持复利。由此产生的恢复效率协议将下降深度、水下时间、恢复负担减轻和反弹参与联系到一个面临报告纪律的分配器中。机器学习和人工智能方法被构建为条件估计、制度映射、稳健性测试和模型风险治理的工具，而不是市场预测。

Keywords :

### 

\[4\] From Expansion to Consolidation

标题:从扩张到整合

作者:Roni Blushtein-Livnon, Tal Svoray, Itay Fischhendler, Havatzelet Yahel, Emir Galilee

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.09642

Abstract : In traditional rural societies, where social ties are embedded in physical space, the diffusion of emerging technologies may be amplified through socio spatial contagion (SSC). Such processes may play a key role in accelerating residential PV adoption in off grid regions. Yet empirical evidence on SSC in PV adoption remains largely limited to affluent, grid connected settings, while off grid regions often lack systematic installation records. To address these gaps, we use a deep learning segmentation model to extract PV installations from a decade long series of remote sensing imagery across 507 off grid settlement clusters (hereafter, communities). This enables data driven spatio temporal point pattern inference of SSC in data scarce contexts. SSC is quantified through the range and intensity of clustering of new installations around prior adopters, and the dynamics of these dimensions are linked to adoption outcomes. We found that SSC is nearly ubiquitous, often spanning most of the community s spatial extent, while exhibiting substantial heterogeneity in intensity. Although SSC intensifies over time, its effects remain temporally concentrated, peaking within 1 to 2 years of nearby installations and weakening thereafter. SSC intensity is positively associated with adoption rates in both cross sectional and temporal analyses. However, the relationship between SSC range and adoption changes over time   in early diffusion phases, adoption growth is associated with range expansion, whereas in later phases it is associated with range contraction. This shift reflects a transition from clustering to consolidation of installations. These findings highlight the potential of seeding interventions to accelerate PV diffusion in off grid regions.

Keywords : 

Abstract :在传统的农村社会，社会关系植根于物理空间，新兴技术的传播可能会通过社会空间传染（SSC）而放大。这些过程可能在加速离网地区的住宅光伏采用方面发挥关键作用。然而，关于光伏采用SSC的经验证据在很大程度上仍局限于富裕的并网环境，而离网地区往往缺乏系统的安装记录。为了解决这些差距，我们使用深度学习分割模型从507个离网定居点集群（以下简称社区）长达十年的遥感图像中提取光伏设施。这使得在数据稀缺的情况下，能够对SSC进行数据驱动的时空点模式推理。SSC是通过围绕先前采用者的新安装集群的范围和强度来量化的，这些维度的动态与采用结果有关。我们发现SSC几乎无处不在，通常跨越社区的大部分空间范围，同时表现出强度的显著异质性。尽管SSC会随着时间的推移而加剧，但其影响在时间上仍然集中，在附近设施的1至2年内达到峰值，此后逐渐减弱。在横截面和时间分析中，SSC强度与采用率呈正相关。然而，SSC范围和采用率之间的关系在早期扩散阶段会随着时间的推移而变化，采用率的增长与范围的扩大有关，而在后期则与范围的缩小有关。这一转变反映了从集群到整合安装的过渡。这些发现突显了种子干预在加速离网地区光伏扩散方面的潜力。

Keywords :

### 

\[5\] Quantifying the Risk Return Tradeoff in Forecasting

标题:量化预测中的风险收益权衡

作者:Philippe Goulet Coulombe

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.09712

Abstract : Average forecast accuracy is not the same as forecast reliability. I treat forecast loss differentials relative to a benchmark as a return series. I then evaluate these returns using risk adjusted performance measures from finance, including the Sharpe ratio, Sortino ratio, Omega ratio, and drawdown based metrics. I also introduce the Edge Ratio capturing a model s propensity to deliver uniquely informative predictions relative to the forecasting frontier. I apply this framework to U.S. macroeconomic forecasting, comparing econometric benchmarks, machine learning models, a foundation model (TabPFN), and the Survey of Professional Forecasters. While it is often feasible to beat professional forecasters in terms of average accuracy, it is much harder to beat them on a risk adjusted basis. They rarely exhibit catastrophic failures and often achieve high Edge Ratios, plausibly reflecting the value of contextual judgment. Nonetheless, selected machine learning methods deliver attractive risk profiles for specific targets. The framework naturally extends to meta analyses across targets, horizons, and samples, illustrated with a density forecast evaluation and the M4 competition.

Keywords : 

Abstract :平均预测精度与预测可靠性不同。我将相对于基准的预测损失差异视为回报序列。然后，我使用财务部门的风险调整绩效指标来评估这些回报，包括夏普比率、索蒂诺比率、欧米茄比率和基于提款的指标。我还介绍了边缘比率，它捕捉了模型相对于预测前沿提供独特信息预测的倾向。我将这个框架应用于美国宏观经济预测，比较计量经济学基准、机器学习模型、基础模型（TabPFN）和专业预测者调查。虽然在平均准确率方面击败专业预测者通常是可行的，但在风险调整的基础上击败他们要困难得多。它们很少表现出灾难性的失败，并且经常达到较高的边缘比率，这合理地反映了情境判断的价值。尽管如此，选定的机器学习方法为特定目标提供了有吸引力的风险预测。该框架自然扩展到跨目标、层位和样本的元分析，以密度预测评估和M4竞争为例。

Keywords :

### 

\[6\] Nonlinear filtering with stochastic discontinuities

标题:具有随机不连续性的非线性滤波

作者:Thorsten Schmidt, Félix B. Tambe-Ndonfack

来源:ARXIV\_20260513

链接:https://arxiv.org/pdf/2605.12142

Abstract : Filtering problems with jumps in both the signal and the observation have been extensively studied, typically under the assumption that jump times are totally inaccessible. In many applications, however, jump times are known in advance (i.e., predictable), such as scheduled clinical visits, dividend payment dates, or inspection times in engineering systems. Taking predictable jump times as a starting point, we investigate a filtering problem in which both the signal and the observations can exhibit jumps at predictable times. We derive the corresponding Kushner Stratonovich and Zakai equations, thereby extending classical nonlinear filtering results to a setting with predictable discontinuities. We illustrate the framework on a Kalman filtering model with predictable jumps and on applications to longitudinal clinical studies, such as spinal muscular atrophy (SMA), as well as to machine learning models (neural jump ODEs) and credit risk.

Keywords : 

Abstract :对信号和观测值中跳跃的滤波问题进行了广泛的研究，通常是在跳跃时间完全不可访问的假设下进行的。然而，在许多应用中，跳跃时间是预先知道的（即可预测的），例如计划的临床就诊、股息支付日期或工程系统中的检查时间。以可预测的跳跃时间为起点，我们研究了一个滤波问题，其中信号和观测值都可以在可预测的时间出现跳跃。我们推导了相应的Kushner Stratonovich和Zakai方程，从而将经典的非线性滤波结果扩展到具有可预测不连续性的环境中。我们说明了具有可预测跳跃的卡尔曼滤波模型的框架，以及在纵向临床研究中的应用，如脊髓性肌萎缩症（SMA），以及机器学习模型（神经跳跃ODE）和信用风险。

Keywords :

### 

\[7\] Synthetic American Option Pricing via Jump HMM Driven Heston Implied Volatility

标题:基于跳跃HMM驱动的赫斯顿隐含波动率的合成美式期权定价

作者:Julia Sun, Zheyu Jin, Jiawei Zhang, Jeffrey D. Varner

来源:ARXIV\_20260515

链接:https://arxiv.org/pdf/2605.13998

Abstract : Generating realistic synthetic option prices requires implied volatility as an input, yet implied volatility is itself derived from observed option prices, creating a circular dependency that limits synthetic data for machine learning and risk analysis applications. We break this circularity with a pipeline in which implied volatility emerges as an output of a structural model of equity returns. A Jump Hidden Markov Model produces multi asset price paths with realistic stylized facts and cross asset tail dependence  a modified Heston variance process, whose mean reversion target depends on regime state, days to expiration, moneyness, and a market mood indicator, converts those paths into implied volatility paths  and a recombining binomial lattice prices American options from the resulting surface. Initializing variance at its mean reversion target for each strike expiration pair lets smile, skew, and term structure emerge without external calibration. We calibrate the shape function through a hierarchy spanning a parametric baseline, a globally shared neural surrogate, and a sector specific neural surrogate fit to a multi ticker, multi sector option ladder. A temporal holdout on a multi day capture isolated scheduled corporate events as the dominant source of test time generalization error, and calendar derived earnings distance and same sector peer coupling features recovered the anticipatory portion of that signal. We then apply the framework as a synthetic data generator on real near the money put and call contracts, forward simulating price paths, and recovering path conditional implied volatility, finite difference American Greeks, and terminal short premium profit and loss from one coherent simulation, and confirm cross ticker robustness by re running on a second underlying from a different sector and volatility regime. The framework is released as an open source Julia package.

Keywords : 

Abstract :生成现实的合成期权价格需要隐含波动率作为输入，但隐含波动率本身是从观察到的期权价格中得出的，这产生了一种循环依赖关系，限制了机器学习和风险分析应用程序的合成数据。我们通过一个管道打破了这种循环，在这个管道中，隐含波动率作为股票回报结构模型的输出而出现。跳跃隐马尔可夫模型产生具有现实风格化事实和交叉资产尾部依赖性的多资产价格路径。一个改进的赫斯顿方差过程，其均值回归目标取决于制度状态、到期天数、货币性和市场情绪指标，将这些路径转换为隐含波动率路径，并从结果表面重新组合二项式格对美国期权进行定价。在每个罢工到期对的均值回归目标处初始化方差，可以在没有外部校准的情况下出现微笑、偏斜和期限结构。我们通过一个层次结构来校准形状函数，该层次结构跨越参数基线、全局共享的神经代理和适合多股票、多部门期权阶梯的部门特定神经代理。对多日捕获的孤立计划公司事件的时间坚持是测试时间泛化误差的主要来源，日历衍生的收益距离和同行业同行耦合特征恢复了该信号的预期部分。然后，我们将该框架作为合成数据生成器应用于真实的近货币看跌和看涨合约、远期模拟价格路径、恢复路径条件隐含波动率、有限差分美式希腊和终端短期溢价损益，并通过在不同行业和波动率制度的第二个基础上重新运行来确认交叉股票的稳健性。该框架作为开源Julia包发布。

Keywords :

### 

\[8\] Deep Learning for Solving and Estimating Dynamic Models in Economics and Finance

标题:用于求解和估计经济和金融动态模型的深度学习

作者:Simon Scheidegger

来源:ARXIV\_20260515

链接:https://arxiv.org/pdf/2605.14493

Abstract : This script offers an implementation oriented introduction to deep learning methods for solving and estimating high dimensional dynamic stochastic models in economics and finance. Its starting point is the curse of dimensionality  heterogeneous agent economies, overlapping generations models with aggregate risk, continuous time models with occasionally binding constraints, climate economy models, and macro finance environments with many assets and frictions generate state and parameter spaces that strain classical tensor product grid methods. The exposition is organized around four complementary methodologies. Deep Equilibrium Nets embed discrete time equilibrium conditions into neural network loss functions. Physics Informed Neural Networks approximate continuous time Hamilton  Jacobi  Bellman, Kolmogorov forward, and related partial differential equations. Deep surrogate models provide fast, differentiable approximations to expensive structural models, while Gaussian processes add a probabilistic layer that quantifies approximation uncertainty  together they support estimation, sensitivity analysis, and constrained policy design. Gaussian process based dynamic programming, combined with active learning and dimension reduction, extends value function iteration to very large continuous state spaces. Applications span representative agent and international real business cycle models, overlapping generations and heterogeneous agent economies, continuous time macro finance, structural estimation by simulated method of moments, and climate economics under uncertainty. Companion notebooks in TensorFlow and PyTorch invite hands on experimentation. These notes are a deliberately subjective and inevitably incomplete snapshot of a rapidly evolving field, aimed at equipping PhD students and researchers to engage with this frontier hands on.

Keywords : 

Abstract :本脚本提供了一个面向实现的深度学习方法介绍，用于解决和估计经济和金融中的高维动态随机模型。它的出发点是维度灾难——异构主体经济、具有聚合风险的重叠世代模型、具有偶尔约束的连续时间模型、气候经济模型以及具有许多资产和摩擦的宏观金融环境——产生了状态和参数空间，使经典的张量积网格方法不堪重负。展览围绕四种互补的方法进行组织。深度平衡网将离散时间平衡条件嵌入神经网络损失函数中。基于物理学的神经网络近似连续时间Hamilton-Jacobi-Bellman、Kolmogorov正演和相关偏微分方程。深度代理模型为昂贵的结构模型提供了快速、可微的近似值，而高斯过程添加了一个概率层来量化近似值的不确定性——它们共同支持估计、灵敏度分析和约束策略设计。基于高斯过程的动态规划，结合主动学习和降维，将值函数迭代扩展到非常大的连续状态空间。应用涵盖了代表性主体和国际真实商业周期模型、重叠世代和异质主体经济、连续时间宏观金融、模拟矩量法的结构估计以及不确定性下的气候经济学。TensorFlow和PyTorch中的配套笔记本邀请动手实验。这些笔记是对一个快速发展的领域的故意主观和不可避免的不完整的快照，旨在让博士生和研究人员能够接触到这一前沿领域。

Keywords :