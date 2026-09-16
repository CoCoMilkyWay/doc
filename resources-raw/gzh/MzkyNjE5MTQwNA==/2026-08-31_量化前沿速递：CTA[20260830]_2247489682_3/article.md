# 量化前沿速递：CTA\[20260830\]

shameless 量化前沿速递 2026-08-31 12:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489682&idx=3&sn=230c3018b8d14d135f4c2636e0f50860&chksm=c3b36c0342084b885026cc2af10d9f805ad81763eadabdcc2e468e9cfd32a5a5a2b05abdebe6#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489682&idx=3&sn=230c3018b8d14d135f4c2636e0f50860&chksm=c3b36c0342084b885026cc2af10d9f805ad81763eadabdcc2e468e9cfd32a5a5a2b05abdebe6#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Calibrating Inelastic Markets to Options

将非弹性市场校准为期权

来源:ARXIV\_20260824

\[2\] Output Only Identification and Spectral Monitoring of Coupled Feedback Networks with Known Time Varying Actuation

已知时变驱动的耦合反馈网络的纯输出识别和频谱监测

来源:ARXIV\_20260827

\[3\] Option Implied Signals and Crash Risk

期权隐含信号与崩盘风险

来源:ARXIV\_20260828

\[4\] A Frequency Controlled Comparison of Tick  and Minute Based Information Bars for Cryptocurrency Markets

加密货币市场基于时间和分钟的信息栏的频率控制比较

来源:ARXIV\_20260828

\[5\] On the approximation of posterior laws in compound loss models by conditional Wasserstein GANs

用条件Wasserstein GANs逼近复合损失模型中的后验法则

来源:ARXIV\_20260828

### 

\[1\] Calibrating Inelastic Markets to Options

标题:将非弹性市场校准为期权

作者:Andrey Itkin

来源:ARXIV\_20260824

链接:https://arxiv.org/pdf/2608.20589

Abstract : The Marketron model of  cite HalperinItkin2025Mark  and its option pricing extension in  cite HalperinItkinMarketron2  suffer from structural non identifiability  an eighteen parameter space traps solvers in suboptimal local minima and renders economic quantities unmeasurable. By removing exact scaling gauges and sign symmetries, freezing non financial parameters by explicit criteria, and adiabatically eliminating the fast hidden signal, we derive a robust nine parameter reduced model. A Gauss Newton Hessian with empty null space and a manifold boundary analysis confirm that the reduced core carries no exact symmetry and admits no further reduction. A diffusive correlation between flow and return innovations captures the short maturity skew. A staged calibration from the physical measure to the risk neutral measure, illustrated on SPX options, fits the whole surface with a single parameter set. The same reduction turns the wedge between the physical and pricing values of the flow block into a well defined market price of flow risk rather than a ridge artifact, identifiable here for the first time, though a single surface constrains its level only weakly. Finally, our analysis reveals that in the Marketron model the log price obeys a generalized Langevin equation with a closed form, state modulated memory kernel, and that the memory variable itself is the exact Markovian lift of this kernel. This mapping also yields a testable condition, the equality of the signal and memory relaxation rates, which on the SPX surface come out well separated, though both weakly identified, placing the fitted market tentatively in the driven, non equilibrium regime and turning the active matter reading from an analogy into a falsifiable constraint.

Keywords : 

Abstract :cite HalperinItkin2025Mark的Marketron模型及其在cite HalperinItkinMarketron2中的期权定价扩展存在结构不可识别性，十八参数空间陷阱求解器处于次优局部最小值，使经济量无法测量。通过去除精确的标度规和符号对称性，通过显式标准冻结非金融参数，并绝热消除快速隐藏信号，我们推导出了一个鲁棒的九参数缩减模型。具有空零空间的高斯-牛顿-黑森方程和流形边界分析证实，约化核不具有精确的对称性，也不允许进一步约化。流动和回报创新之间的扩散相关性捕捉到了短期期限的偏差。从物理测量到风险中性测量的分阶段校准，如SPX选项所示，用单个参数集拟合整个表面。同样的减少将流动块的物理值和定价值之间的楔形变成了流动风险的明确市场价格，而不是脊状伪影，这是第一次在这里被识别出来，尽管单个表面对其水平的限制很弱。最后，我们的分析表明，在Marketron模型中，对数价格服从具有封闭形式、状态调制记忆核的广义朗之万方程，记忆变量本身就是该核的精确马尔可夫提升。这种映射还产生了一个可测试的条件，即信号和记忆弛豫率的相等性，在SPX表面上，这两个条件很好地分开了，尽管两者都很弱，将拟合的市场暂时置于驱动的非均衡状态，并将活性物质读数从类比转变为可证伪的约束。

Keywords :

### 

\[2\] Output Only Identification and Spectral Monitoring of Coupled Feedback Networks with Known Time Varying Actuation

标题:已知时变驱动的耦合反馈网络的纯输出识别和频谱监测

作者:Jihwan Woo

来源:ARXIV\_20260827

链接:https://arxiv.org/pdf/2608.25844

Abstract : Coupled feedback networks are often monitored channel by channel even though cross channel paths alter both stability margins and transmitted disturbances. We study identification of a structured feedback matrix L t   Phi diag(gamma t) in an output only setting  no commanded, probing, or reference input exists    only temporally separated outputs and the scheduling gains gamma t are observed, while the coupling response Phi and the clearing window inputs are not. Identification rests jointly on the persistent excitation of the observed pre window output and on two structural features separating coupling from confounds  the known time variation of the gains, which modulates the closed loop response in a predictable pattern, and a partial reversal moment by which a known fraction of transient displacement is corrected in a subsequent window. We give a hierarchy of results  exact local identification of the coupling under a Jacobian rank condition on the gain regimes  a first order interaction estimator whose identification strength is the minimum eigenvalue of the residualized interaction information matrix (provably unidentified under constant gains)  and a characterization of the estimand as a resolvent sensitivity    the right object for screening transmitted disturbances and a first stage input to spectral margin recovery    with sqrt(T) asymptotics for the first order estimator, a cross identification theorem mapping each varying gain to exactly identified resolvent rows and columns, and bootstrap validity under consistent selection  the implemented heuristic s empirical coverage (90  at nominal 95 ) quantifies the remaining gap. Simulations verify sharpness of the rank condition and quantify benchmark failures under confounding. A case study on leveraged fund rebalancing feedback, where daily fund disclosures play the role of the known gains, illustrates the method on real data.

Keywords : 

Abstract :即使跨信道路径改变了稳定性裕度和传输干扰，耦合反馈网络也经常被逐个信道监测。我们研究了在仅输出设置中识别结构化反馈矩阵L t Phi diag（gamma t），没有命令、探测或参考输入，只存在时间上分离的输出，并且观察到调度增益gamma t，而没有耦合响应Phi和清除窗口输入。识别共同依赖于观测到的窗前输出的持续激励，以及将耦合与混淆分离的两个结构特征——增益的已知时间变化，以可预测的模式调节闭环响应，以及在后续窗口中校正已知瞬态位移部分的部分反转力矩。我们给出了一个结果层次——在增益区域上的雅可比秩条件下耦合的精确局部识别——一个一阶相互作用估计器，其识别强度是残差化相互作用信息矩阵的最小特征值（在恒定增益下可证明未识别），并将估计值表征为预解灵敏度——筛选传输干扰的正确对象，以及一阶估计器的sqrt（T）渐近线对频谱裕度恢复的第一阶段输入，一个将每个不同增益映射到精确识别的预解元行和列的交叉识别定理，以及一致选择下的自举有效性——实现的启发式经验覆盖率（标称95为90）量化了剩余的差距。仿真验证了秩条件的锐度，并量化了混杂条件下的基准失败。杠杆基金再平衡反馈的案例研究，其中每日基金披露起着已知收益的作用，说明了基于真实数据的方法。

Keywords :

### 

\[3\] Option Implied Signals and Crash Risk

标题:期权隐含信号与崩盘风险

作者:Baichuan Li, Mengxiao Wang

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.26115

Abstract : We re estimate canonical option implied predictability evidence using a unified 2015  2026 panel of 12.36 million U.S. equity firm day observations across 10,026 underlyings. We split the sample into three regimes  late post crisis low volatility (2015  2019), high volatility transition (2020  2022), and AI mega cap concentration (2023  2026). The Xing et al. (2010) smirk  return relationship weakens steadily  the next month univariate smirk coefficient falls from   0.023   (t  5.5)  in 2015  2019 to an insignificant   0.006   (t  1.5)  in 2023  2026, and turns positive at the three month horizon  ( 0.016,  t  2.1) . In joint specifications with all six canonical signals, the smirk is insignificant throughout and again changes sign in the latest regime. By contrast, the Cremers  Weinbaum IV spread and a Bakshi et al. (2003) style risk neutral skewness measure remain significant across regimes and specifications. A boosted tree benchmark using IV surface, trading activity, Greeks, and liquidity features outperforms linear models for next month return prediction only in the AI mega cap regime, with  R 2   mathrm OOS    1.29   versus   0.07  . Permutation importance identifies different leading predictors by regime, and no canonical hand engineered signal enters the top five. For firm level five day crash classification, AUC is highest in calm markets  (0.706,   text XGBoost )  and lowest during the high volatility transition  (0.561) . Overall, option implied predictability is real but regime dependent, and the post 2023 AI mega cap period differs sharply from the pre COVID setting in which the canonical results were established.

Keywords : 

Abstract :我们使用2015年至2026年统一的面板，对10026个底层的1236万个美国股票公司日观测值，重新估计了规范期权隐含的可预测性证据。我们将样本分为三个阶段：危机后后期低波动性（2015-2019）、高波动性过渡（2020-2022）和人工智能大盘股集中（2023-2026）。Xing等人（2010）的傻笑回报关系在下个月稳步减弱，单变量傻笑系数从2015年至2019年的0.023（t 5.5）降至2023年至2026年的微不足道的0.006（t 1.5），并在三个月内变为正值（0.016，t 2.1）。在所有六个规范信号的联合规范中，傻笑在整个过程中都是微不足道的，在最新的制度中再次改变了标志。相比之下，Cremers-Weinbaum IV价差和Bakshi等人（2003）风格的风险中性偏度指标在不同制度和规范下仍然具有显著性。使用IV表面、交易活动、希腊和流动性特征的增强树基准仅在人工智能大盘股制度下，在下个月回报预测方面优于线性模型，R 2 mathm OOS为1.29比0.07。置换重要性根据方案确定了不同的主要预测因素，没有规范的人工设计信号进入前五名。对于公司级五天崩盘分类，AUC在平静的市场中最高（0.706，文本XGBoost），在高波动性过渡期间最低（0.561）。总体而言，期权隐含的可预测性是真实的，但取决于制度，2023年后的人工智能超级上限期与新冠肺炎前的情况截然不同，在新冠肺炎疫情前，规范结果是建立的。

Keywords :

### 

\[4\] A Frequency Controlled Comparison of Tick  and Minute Based Information Bars for Cryptocurrency Markets

标题:加密货币市场基于时间和分钟的信息栏的频率控制比较

作者:Muhammad Toheed Fayyaz, Abdul Jabbar, Faheem Ahmad Qureshi, Syed Qaisar Jalil

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.26158

Abstract : This paper provides a controlled comparison of six information bar types (dollar, volume, volatility, range, Renko, and hybrid bars) constructed from both raw Binance aggTrade tick data and one minute OHLCV bars for the BTCUSDT USDT margined perpetual futures market over a six year period spanning January 2020 to December 2025, and evaluated against fixed interval time bar baselines. Both pipelines share a common adaptive EMA calibration framework  the tick pipeline additionally uses strictly tick native activity signals, isolating data resolution as the sole experimental variable. Results across eight statistical quality criteria reveal that the tick advantage is bar type specific and most pronounced in bar types whose activity signals are most sensitive to intra minute price dynamics  tick Renko bars achieve the smallest random walk deviation recorded (   mathrm VR (4)   1    0.020 , lag 1 autocorrelation    0.002 ), and tick volatility bars reduce serial dependence by 69   relative to the minute baseline (   mathrm VR (4)   1   0.028  versus  0.089 ). In the multi regime six year sample, normality improvements are regime dependent and secondary  the extreme market events of 2020  2022 inflate fat tails across all bar types, and Ljung Box independence is rejected for all series at the sample sizes studied. A matched frequency robustness analysis shows that the apparent tick underperformance on distributional criteria is largely a sampling frequency artefact  when tick series are coarsened to the minute pipeline s bar count, frequency matched tick dollar bars lead on all six criteria and matched tick volatility bars attain LB  p   0.51 , recovering serial independence that the raw oversampled series rejects.

Keywords : 

Abstract :本文对BTCUSDT USDT保证金永久期货市场在2020年1月至2025年12月的六年期间从原始Binance aggTrade分时数据和一分钟OHLCV条构建的六种信息条类型（美元、交易量、波动率、范围、Renko和混合条）进行了受控比较，并根据固定间隔时间条基线进行了评估。这两条管道共享一个通用的自适应EMA校准框架，蜱虫管道还严格使用蜱虫原生活动信号，将数据分辨率作为唯一的实验变量。八个统计质量标准的结果表明，分时优势是特定于条形图类型的，在活动信号对分钟内价格动态最敏感的条形图类型中最为明显。分时Renko条形图实现了记录的最小随机游走偏差（mathm VR（4）1 0.020，滞后1自相关0.002），分时波动条形图相对于分钟基线将序列依赖性降低了69（mathm VR4）1 0.02对0.089）。在多制度六年样本中，正态性改善取决于制度，是次要的。2020年至2022年的极端市场事件在所有酒吧类型中都会膨胀脂肪尾巴，在所研究的样本量下，所有系列的Ljung Box独立性都被拒绝。匹配频率稳健性分析表明，当分时序列粗化为分钟管道的条数，频率匹配分时美元条在所有六个标准上领先，匹配分时波动率条达到LB p 0.51，恢复了原始过采样序列所拒绝的序列独立性时，分布标准上的明显分时表现不佳在很大程度上是一种采样频率伪影。

Keywords :

### 

\[5\] On the approximation of posterior laws in compound loss models by conditional Wasserstein GANs

标题:用条件Wasserstein GANs逼近复合损失模型中的后验法则

作者:Aleksandar Arandjelovic, Pavel V. Shevchenko, George Tzougas

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.27229

Abstract : Bayesian inference in compound loss models must often be repeated across policies, market scenarios, and prior specifications. Outside conjugate cases, this may require repeated numerical integration or Markov chain Monte Carlo (MCMC). We formulate this problem as amortized posterior approximation and construct a conditional Wasserstein generative adversarial network conditioned on sufficient statistics, prior mean and coefficient of variation, and mixture weights of prior families. Notably, a single shared generator is able to approximate the posterior laws of both the Poisson intensity and the Pareto shape parameter under mixtures of Gamma, inverse Gaussian, and lognormal priors. We assess the approximation by simulation based calibration and by comparisons with analytical posteriors, deterministic quadrature, and extensive MCMC simulations. In an application to data on extreme natural catastrophe losses, we produce rolling one year posterior predictive distributions, and examine the effects of heavy tailed severity and prior family uncertainty on aggregate tail risk.

Keywords : 

Abstract :复合损失模型中的贝叶斯推理必须经常在政策、市场情景和先前规范中重复。在共轭情况之外，这可能需要重复的数值积分或马尔可夫链蒙特卡洛（MCMC）。我们将这个问题表述为摊销后验近似，并构建了一个条件Wasserstein生成对抗网络，该网络以充分统计、先验均值和变异系数以及先验家族的混合权重为条件。值得注意的是，在Gamma、逆高斯和对数正态先验的混合下，单个共享生成器能够近似泊松强度和帕累托形状参数的后验法则。我们通过基于模拟的校准以及与分析后验、确定性求积和广泛的MCMC模拟的比较来评估近似值。在极端自然灾害损失数据的应用中，我们生成了滚动的一年后验预测分布，并研究了重尾严重程度和先验家族不确定性对总尾部风险的影响。

Keywords :