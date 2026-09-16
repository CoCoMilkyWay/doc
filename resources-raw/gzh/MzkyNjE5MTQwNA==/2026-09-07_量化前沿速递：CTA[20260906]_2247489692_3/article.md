# 量化前沿速递：CTA\[20260906\]

shameless 量化前沿速递 2026-09-07 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489692&idx=3&sn=8ee584c04b42cdeebb3626b0658a0fc8&chksm=c3a6658621c18878754a02bae2fceeacd800d6522caf2e050017d782424167c9f88aea43ea4d#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489692&idx=3&sn=8ee584c04b42cdeebb3626b0658a0fc8&chksm=c3a6658621c18878754a02bae2fceeacd800d6522caf2e050017d782424167c9f88aea43ea4d#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Pricing and Calibration of Bitcoin Inverse Options via the Rough Bergomi Model

基于粗糙Bergomi模型的比特币逆期权定价与校准

来源:ARXIV\_20260831

\[2\] Market Informed Valuation of GMMB Riders with Surrender Options under a Heston Stochastic Local Volatility Model

Heston随机局部波动模型下具有投降期权的GMMB骑手的市场知情估值

来源:ARXIV\_20260831

\[3\] RetailAgent

零售 代理

来源:ARXIV\_20260831

\[4\] Deep Hedging Under Realistic Market Frictions

现实市场摩擦下的深度对冲

来源:ARXIV\_20260901

\[5\] Improving Swaption Calibration in Factor HJM Stochastic Volatility Models

改进因子HJM随机波动模型中的互换校准

来源:ARXIV\_20260901

\[6\] The Convergence Rate of Stochastic Tracking with Application to Optimal Execution

随机跟踪的收敛速度及其在最优执行中的应用

来源:ARXIV\_20260901

\[7\] Tariff Threats, Macroeconomic Expectations, and Policy Communication Strategies

关税威胁、宏观经济预期和政策沟通策略

来源:ARXIV\_20260901

\[8\] Importance Sampling Enhanced with the COS Method for the Portfolio Risk Allocation

COS方法增强投资组合风险分配的重要性抽样

来源:ARXIV\_20260901

\[9\] Neural Calibration of a Complete Market Model

完整市场模型的神经校准

来源:ARXIV\_20260901

\[10\] Stochastic Optimal Control of Hawkes Jump Diffusion Systems

霍克斯跳跃扩散系统的随机最优控制

来源:ARXIV\_20260901

\[11\] Harvesting the Variance Risk Premium in Nuclear and Energy Equities

收获核能和能源股票的差异风险溢价

来源:ARXIV\_20260902

\[12\] Price manipulation in nonlinear transient impact models

非线性瞬态冲击模型中的价格操纵

来源:ARXIV\_20260903

\[13\] Modeling Trade Durations under Temporal Granularity Effects in Forex Markets

外汇市场时间粒度效应下的交易持续时间建模

来源:ARXIV\_20260903

\[14\] Viscosity Supersolution Barriers to a Non local Free Boundary Problem

非局部自由边界问题的粘性超解障碍

来源:ARXIV\_20260903

\[15\] Mean field equilibrium of heterogeneous agents under market impact

市场冲击下异质主体的平均场均衡

来源:ARXIV\_20260904

\[16\] Bayesian Confidence Recalibration and Research Equilibrium Criticality

贝叶斯置信度重新校准与研究均衡临界性

来源:ARXIV\_20260904

\[17\] Global Multi Maturity SPX VIX Calibration Beyond Markovian Stitching

超越马尔可夫缝合的全球多成熟度SPX VIX校准

来源:ARXIV\_20260904

### 

\[1\] Pricing and Calibration of Bitcoin Inverse Options via the Rough Bergomi Model

标题:基于粗糙Bergomi模型的比特币逆期权定价与校准

作者:Riccardo Caruso

来源:ARXIV\_20260831

链接:https://arxiv.org/pdf/2608.27575

Abstract : Bitcoin inverse options, traded on the Deribit exchange and settled in the underlying cryptocurrency rather than in fiat currency, combine extreme and genuinely rough volatility dynamics with a non linear, currency dependent payoff structure. This paper develops and empirically validates a pricing and calibration framework for these instruments based on the rough Bergomi (rBergomi) model of Bayer, Friz and Gatheral (2016). We adapt the rBergomi dynamics to the inverse payoff max(S T   K, 0) S T, and implement and compare three computational pipelines that differ in the simulation scheme for the driving fractional Brownian motion (coarse grid Cholesky vs. the Hybrid Scheme of Bennedsen et al., 2017) and in the Monte Carlo pricing estimator (plain log Euler vs. the Mixed Estimator of McCrickerd and Pakkanen, 2018). The model is calibrated to thirty implied volatility surfaces extracted from Deribit trade data between May 2022 and March 2025, spanning seven major market stress events and nine baseline regimes stratified by volatility level. The Hybrid and Mixed pipeline is simultaneously the most accurate (mean unweighted RMSE 22.83 percentage points, versus 41.76 pp for the Cholesky and Euler benchmark) and the fastest (17 seconds per snapshot, a 20 fold speed up). The calibrated Hurst exponent is consistently close to the lower bound of the search space (H approximately equal to 0.01  0.06 in most regimes), confirming that Bitcoin s volatility is genuinely rough, and calibration error scales approximately linearly with the level of at the money implied volatility (Pearson r   0.89).

Keywords : 

Abstract :比特币反向期权在Deribit交易所交易，以基础加密货币而非法定货币结算，将极端和真正粗糙的波动动态与非线性、货币依赖的回报结构相结合。本文基于Bayer、Friz和Gatheral（2016）的粗略Bergomi（rBergomi）模型，开发并实证验证了这些仪器的定价和校准框架。我们将rBergomi动力学适应于逆收益最大值（S T K，0）S T，并实现和比较了三种计算管道，它们在驱动分数布朗运动的模拟方案（粗网格Cholesky与Bennedsen等人的混合方案，2017）和蒙特卡洛定价估计量（平对数Euler与McCrickerd和Pakkanen的混合估计量，2018）中有所不同。该模型根据2022年5月至2025年3月期间从Deribit交易数据中提取的30个隐含波动率面进行了校准，涵盖了7个主要市场压力事件和9个按波动率水平分层的基线制度。混合和混合管道同时是最准确的（平均未加权RMSE 22.83个百分点，而Cholesky和Euler基准为41.76个百分点）和最快的（每张快照17秒，速度提高了20倍）。校准后的赫斯特指数始终接近搜索空间的下限（在大多数情况下，H约等于0.01 0.06），这证实了比特币的波动性确实很粗糙，校准误差与货币隐含波动率水平近似呈线性关系（Pearson r 0.89）。

Keywords :

### 

\[2\] Market Informed Valuation of GMMB Riders with Surrender Options under a Heston Stochastic Local Volatility Model

标题:Heston随机局部波动模型下具有投降期权的GMMB骑手的市场知情估值

作者:Ludovic Goudenege, Andrea Molent, Xiao Wei, Antonino Zanette

来源:ARXIV\_20260831

链接:https://arxiv.org/pdf/2608.28397

Abstract : We develop a market informed valuation framework forguaranteed minimum maturity benefit (GMMB) riders withrational surrender under the Heston stochastic localvolatility (SLV) model. The guarantee is written on thefee deducted account value and is considered both in itsterminal only form and in the presence of early surrenderrights. The Heston SLV specification combines stochastic volatility with a leverage function calibrated to a prescribed local volatility surface. The leverage surface is obtained through a forward Markovian projection equation so that, at the model level, the SLV dynamics are constrained to the same one dimensional marginals as the corresponding local volatility (LV) model. The latter is used only as a one factor benchmark, allowing us to isolate the effect of stochastic volatility on continuation values and surrender decisions while preserving the same option calibrated local volatility target. We derive the associated backward pricing equations and propose a hybrid tree finite difference algorithm for the SLV model with a calibrated leverage function. Synthetic experiments and a market informed case study show that SLV and LV valuations are numerically close for terminal only guarantees, as expected from the common marginal target, whereas materially larger differences can arise once surrender is allowed. These differences are reflected in guarantee values, fair insurance fees and volatility dependent surrender regions. The results indicate that matching one date marginals implied by vanilla option prices does not eliminate model risk for insurance liabilities whose value depends on conditional continuation dynamics and endogenous surrender decisions.

Keywords : 

Abstract :我们在赫斯顿随机局部波动率（SLV）模型下，为具有合理退保的保证最低到期收益（GMMB）附加条款开发了一个市场知情的估值框架。该担保以扣除税款的账户价值为基础，在仅以终端形式和存在提前退保权的情况下均被视为担保。Heston SLV规范将随机波动率与校准到规定的局部波动率表面的杠杆函数相结合。杠杆面是通过正向马尔可夫投影方程获得的，因此在模型层面，SLV动态被约束为与相应的局部波动率（LV）模型相同的一维边际。后者仅用作单因素基准，使我们能够隔离随机波动对延续值和放弃决策的影响，同时保持相同的期权校准局部波动目标。我们推导了相关的反向定价方程，并为具有校准杠杆函数的SLV模型提出了一种混合树有限差分算法。综合实验和市场知情案例研究表明，正如共同边际目标所预期的那样，SLV和LV的估值在仅终端担保方面在数值上接近，而一旦允许投降，可能会出现更大的差异。这些差异反映在担保价值、公平的保险费和波动依赖的退保地区。结果表明，匹配香草期权价格隐含的单日边际并不能消除保险负债的模型风险，保险负债的价值取决于条件持续动态和内生退保决策。

Keywords :

### 

\[3\] RetailAgent

标题:零售 代理

作者:Yupeng Zhang, Liuyuan Jiang, Hongyi Huang, Bingheng Li, Lisha Chen

来源:ARXIV\_20260831

链接:https://arxiv.org/pdf/2608.28399

Abstract : In financial markets, a sequential policy that reacts systematically to price movements may become predictable to other market participants. This paper studies whether large language model (LLM) agents exhibit such directional structure through RetailAgent, an experimental framework in which an LLM observes anonymized intraday equity price histories and permitted state, then repeatedly chooses long (hold the stock) or flat (stay out) before the subsequent interval return is revealed. We compare returns during long and flat intervals along the same stock s intraday path after removing the overall fraction of long decisions. This exposure matched measure reveals persistent negative timing across modality, horizon, state, and model family. Shuffling saved action sequences substantially attenuates the effect, showing that alignment between actions and subsequent returns drives the negative score. Feeding self authored memories into decisions further increases policy persistence, while timing becomes more negative among stock days on which the agent uses both actions. These results reveal stable, recoverable directional structure in sequential LLM financial decisions and a behavioral signal for studying how another participant could respond to a predictable policy.

Keywords : 

Abstract :在金融市场中，对价格变动做出系统反应的连续政策可能对其他市场参与者来说是可预测的。本文通过RetailAgent研究了大型语言模型（LLM）代理是否表现出这种方向性结构，RetailAgent是一个实验框架，在这个框架中，LLM观察匿名的日内股票价格历史和允许状态，然后在随后的区间回报显示之前反复选择长期（持有股票）或平稳（不投资）。我们在去除长期决策的整体部分后，比较了同一股票日内路径上长期和平稳区间的回报。这种暴露匹配度量揭示了跨模态、水平、状态和模型家族的持续负时间。对保存的动作序列进行洗牌会大大减弱效果，表明动作和后续返回之间的对齐会导致负分。在决策中加入自主记忆可以进一步提高政策的持久性，而在代理人同时使用这两种行为的股票日，时机变得更加消极。这些结果揭示了连续LLM财务决策中稳定、可恢复的方向性结构，以及研究另一参与者如何对可预测政策做出反应的行为信号。

Keywords :

### 

\[4\] Deep Hedging Under Realistic Market Frictions

标题:现实市场摩擦下的深度对冲

作者:Sheryan Kumar

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.29025

Abstract : Classical option hedging methods like Black Scholes delta assume constant, free rebalancing, which real markets don t allow. Deep hedging trains a neural network to handle these frictions directly, and prior work reports strong results. But those comparisons usually pit deep hedging against a frictionless classical baseline on simulated price data. That s not a fair fight, and it leaves open whether the advantage is real.We test this using five years of actual BTC options data from Deribit (2020 2024), comparing Black Scholes delta, Leland s cost adjusted hedge, and the Whalley Wilmott no trade band against three deep hedging setups  an LSTM and a feedforward network, each trained with a CVaR loss and, in some runs, a penalty for trading too often. All six strategies face the same 5 basis point transaction cost.On 11,546 test episodes from September 2023 to December 2024, Whalley Wilmott cuts transaction costs significantly versus hourly rebalancing, saving  1.79 per episode against plain BS delta (95  CI   2.21,  1.39 , p   0.0001) by trading about eight times less often. Its P&L and tail risk numbers are better too, though not quite significant at this sample size. None of the three deep hedging models beat any classical benchmark on any metric, and all kept trading almost every hour regardless of penalty weight, a twenty fold range barely moved the needle. A calmer validation period shows Whalley Wilmott s P&L edge shrinks or disappears there while its cost edge holds, so the result depends on market regime. We think the likely causes are a small training set and the lack of any built in mechanism for sitting still in the architectures tested. Not a flashy result, but an honest one  a real data check on a claim mostly supported by simulations so far.

Keywords : 

Abstract :经典的期权对冲方法，如Black-Scholes delta，假设持续的、自由的再平衡，这是真实市场所不允许的。深度对冲训练了一个神经网络来直接处理这些摩擦，之前的工作报告了强有力的结果。但这些比较通常将深度对冲与模拟价格数据上无摩擦的经典基线进行比较。这不是一场公平的斗争，优势是否真实存在还有待商榷。我们使用Deribit（2020-2024）的五年实际BTC期权数据对此进行了测试，将Black-Scholes delta、Leland的成本调整对冲和Whalley Wilmott无交易区间与三个深度对冲设置（LSTM和前馈网络）进行了比较，每个设置都用CVaR损失进行了训练，在某些情况下，还对过于频繁的交易进行了惩罚。所有六种策略都面临相同的5个基点的交易成本。在2023年9月至2024年12月的11546次测试中，Whalley Wilmott与每小时的再平衡相比显著降低了交易成本，通过减少约8倍的交易频率，每一次的交易成本比简单的BS delta节省了1.79（95 CI 2.21，1.39，p 0.0001）。它的损益和尾部风险数字也更好，尽管在这个样本量下并不十分显著。三种深度对冲模型在任何指标上都没有击败任何经典基准，并且几乎每小时都在交易，无论惩罚权重如何，20倍的范围几乎没有改变。平静的验证期表明，Whalley Wilmott的损益优势在那里缩小或消失，而其成本优势保持不变，因此结果取决于市场机制。我们认为，可能的原因是训练集较小，并且在测试的架构中缺乏任何内置的静止机制。这不是一个华而不实的结果，而是一个诚实的结果——对迄今为止主要由模拟支持的说法进行了真实的数据检查。

Keywords :

### 

\[5\] Improving Swaption Calibration in Factor HJM Stochastic Volatility Models

标题:改进因子HJM随机波动模型中的互换校准

作者:Bram Brongers

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.29423

Abstract : The factor HJM stochastic volatility model introduced by Sepp and Rakhmonov (2025) obtains tractable swaption pricing by freezing the nonlinear swap rate loading along a deterministic expected state path. This removes the dependence of conditional swap rate variance on the current yield curve state. We introduce a first order Taylor correction to the loading that adds no calibration parameters. Conditional on retaining the frozen annuity measure drift, we show that the first variation of the swap rate transform is affine in the centered rate states and reduces to one dimensional equations in volatility. For quadratic drift lognormal stochastic volatility, these equations yield a finite dimensional ODE representation and a direct log volatility formulation. Calibrations to independently generated nonlinear model prices show substantially lower stochastic volatility parameter bias and held out pricing error, with only modest changes in local calibration identifiability.

Keywords : 

Abstract :Sepp和Rakhmonov（2025）引入的因子HJM随机波动率模型通过沿确定性预期状态路径冻结非线性掉期利率负载来获得可处理的掉期定价。这消除了条件掉期利率方差对当前收益率曲线状态的依赖。我们对加载引入了一阶泰勒校正，不添加校准参数。在保持冻结年金度量漂移的条件下，我们证明了掉期利率变换的第一变分在中心利率状态下是仿射的，在波动率状态下简化为一维方程。对于二次漂移对数正态随机波动率，这些方程产生了有限维常微分方程表示和直接对数波动率公式。对独立生成的非线性模型价格的校准显示，随机波动性参数偏差和定价误差显著降低，局部校准可识别性仅略有变化。

Keywords :

### 

\[6\] The Convergence Rate of Stochastic Tracking with Application to Optimal Execution

标题:随机跟踪的收敛速度及其在最优执行中的应用

作者:Marcel Nutz, Moritz Voss

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.29468

Abstract : We study the quadratic tracking problem of a general stochastic target process with absolutely continuous controls, with and without terminal constraint. We derive explicit, non asymptotic upper bounds in terms of a Besov type modulus of the target. These bounds yield sharp explicit rates that specialize to the square root order for semimartingale targets. We then apply these results to a generalized Obizhaeva  Wang execution model with random terminal inventory. We first develop a Hilbert space approach to characterize its optimal strategy, which includes jumps. To avoid such trading spikes, one regularizes the problem by a quadratic trading rate penalty with coefficient   varepsilon . We then show that the regularized optimal execution cost   and therefore the excess price impact cost of the regularized optimal strategy   converges at the sharp rate  O( sqrt  varepsilon ) . Since the regularized optimal strategy is not available in closed form, we further construct a nearly optimal strategy which is readily implementable and shares the same approximation rate.

Keywords : 

Abstract :我们研究了具有绝对连续控制的一般随机目标过程的二次跟踪问题，有和没有终端约束。我们根据目标的Besov型模推导出显式的非渐近上界。这些界限产生了专门针对半鞅目标的平方根阶的尖锐显式速率。然后，我们将这些结果应用于具有随机终端库存的广义Obizhaeva-Wang执行模型。我们首先开发了一种Hilbert空间方法来表征其最优策略，其中包括跳跃。为了避免这种交易尖峰，人们通过系数为varepsilon的二次交易率惩罚来规范这个问题。然后，我们证明了正则化最优执行成本以及正则化最优策略的超额价格影响成本在急剧率O（sqrt varepsilon）处收敛。由于正则化最优策略在封闭形式下不可用，我们进一步构建了一个易于实现且具有相同近似率的近似最优策略。

Keywords :

### 

\[7\] Tariff Threats, Macroeconomic Expectations, and Policy Communication Strategies

标题:关税威胁、宏观经济预期和政策沟通策略

作者:Jianhao Lin, Lexuan Sun, Yixin Yan

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.30522

Abstract : Tariff threats can move household beliefs before policy is enacted, yet their rapidly changing language is difficult to study with conventional surveys. We build a multi agent system that turns 300 households from the Michigan Surveys of Consumers into persistent large language model agents exposed to social media information over several simulated months. Calibrated agents reproduce some distributional and demographic patterns in human survey data collected after the announcement of Liberation Day tariffs. Simulated experiments indicate that immediacy, rate salience, semantic progression, message complexity, narrative, and sender identity jointly shape inflation and unemployment expectations and their dispersion. Open ended responses trace these effects to attention, ambiguity, credibility, and causal narratives. A second experiment finds that central bank explanations can coordinate beliefs, although their effects on average expectations depend on message content. The framework supports disciplined exploration of policy communication, subject to human validation rather than as a substitute for it.

Keywords : 

Abstract :关税威胁可能会在政策颁布之前改变家庭观念，但它们迅速变化的语言很难用传统调查来研究。我们构建了一个多代理系统，将密歇根州消费者调查中的300个家庭转化为在几个模拟月内暴露于社交媒体信息的持久性大型语言模型代理。校准后的代理在解放日关税宣布后收集的人类调查数据中再现了一些分布和人口统计模式。模拟实验表明，即时性、率显著性、语义进展、信息复杂性、叙事和发送者身份共同塑造了通货膨胀和失业预期及其分散。开放式回答将这些影响追溯到注意力、模糊性、可信度和因果叙述。第二个实验发现，央行的解释可以协调人们的信念，尽管它们对平均预期的影响取决于信息内容。该框架支持对政策沟通进行有纪律的探索，但须经人类验证，而不是作为其替代品。

Keywords :

### 

\[8\] Importance Sampling Enhanced with the COS Method for the Portfolio Risk Allocation

标题:COS方法增强投资组合风险分配的重要性抽样

作者:Fang Fang, Xiaoyu Shen, Qinling Wang

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.30749

Abstract : We introduce ISCOS, a cross entropy importance sampling calibration method for rare credit portfolio losses. We derive Gaussian and Gaussian  inverse Gamma proposals and analyse the propagation of finite COS approximation errors to the fitted parameters. Numerical experiments for Gaussian and Student t copula credit portfolios show the efficiency of this method.

Keywords : 

Abstract :我们介绍了ISCOS，这是一种用于罕见信贷组合损失的交叉熵重要性抽样校准方法。我们推导了高斯和高斯逆Gamma方案，并分析了有限COS近似误差对拟合参数的传播。对高斯和Student t copula信用组合的数值实验表明了该方法的有效性。

Keywords :

### 

\[9\] Neural Calibration of a Complete Market Model

标题:完整市场模型的神经校准

作者:Andrea Molent, Michel Vellekoop

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.30867

Abstract : We propose a neural calibration method to construct a recombining binomial tree directly from a set of given option prices. Rather than estimating a continuous option pricing function or a local volatility surface as an intermediate object, a neural network is used to deform a benchmark lattice. This leads to a discrete pricing model which is guaranteed to be arbitrage free, complete, easy to interpret, and can be used directly for pricing and to find replicating trading strategies. Calibration is formulated as a penalized optimization problem that combines a repricing error with an admissibility penalty, and an optional spatial regularization term based on implied local volatilities. Numerical experiments on synthetic and SPX market data show that the proposed approach yields accurate repricing and is very competitive when compared to recently proposed other neural calibration methods. It preserves the computational advantages of lattice based valuation and hedging. In particular, the calibrated tree can be reused to price contracts that allow early exercise, and could even be calibrated directly with American option prices.

Keywords : 

Abstract :我们提出了一种神经校准方法，直接从一组给定的期权价格构建重组二叉树。神经网络用于使基准晶格变形，而不是将连续期权定价函数或局部波动面作为中间对象进行估计。这导致了一个离散的定价模型，该模型保证无套利、完整、易于解释，可以直接用于定价和寻找复制的交易策略。校准被表述为一个惩罚优化问题，该问题结合了重新定价误差和可接受性惩罚，以及基于隐含局部波动性的可选空间正则化项。对合成和SPX市场数据的数值实验表明，与最近提出的其他神经校准方法相比，所提出的方法可以产生准确的重新定价，并且具有很强的竞争力。它保留了基于格的估值和套期保值的计算优势。特别是，校准后的树可以重新用于为允许早期行使的合约定价，甚至可以直接用美国期权价格进行校准。

Keywords :

### 

\[10\] Stochastic Optimal Control of Hawkes Jump Diffusion Systems

标题:霍克斯跳跃扩散系统的随机最优控制

作者:Daria Sakhanda, Joshué Helí Ricalde-Guerrero

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.29473

Abstract : This paper is devoted to developing a framework for stochastic growth models with environmental risk, in which rare but catastrophic shocks interact with capital accumulation and pollution. Building on the Poisson point process formulation studied in arXiv 2511.13568, we extend the model to disasters driven by a marked Hawkes process, allowing past disasters to temporarily increase the likelihood of subsequent shocks. Our work focuses on a subcritical Markovian Hawkes specification, in which the state space is augmented by the self excitation component of disaster risk. We establish the well posedness and nonexplosion of the resulting controlled Hawkes dynamics. Using the Hamilton Jacobi Bellman characterization of the corresponding Poisson control problem, we obtain quantitative estimates for the Hawkes excitation process and prove, under a small excitation scaling, that the Hawkes value function converges to its Poisson counterpart as the magnitude of self excitation vanishes. This provides a rigorous Poisson approximation of the stochastic control problem and quantifies the effect of self excitation on optimal growth under environmental disaster risk.

Keywords : 

Abstract :本文致力于开发一个具有环境风险的随机增长模型框架，其中罕见但灾难性的冲击与资本积累和污染相互作用。基于arXiv 2511.13568中研究的泊松点过程公式，我们将模型扩展到由标记的霍克斯过程驱动的灾害，允许过去的灾害暂时增加后续冲击的可能性。我们的工作侧重于亚临界马尔可夫-霍克斯规范，其中状态空间由灾害风险的自激分量增强。我们建立了所得受控霍克斯动力学的适定性和非展开性。利用相应泊松控制问题的哈密顿-雅可比-贝尔曼特征，我们得到了霍克斯激励过程的定量估计，并证明了在小激励尺度下，霍克斯值函数在自激幅度消失时收敛到其泊松对应值。这为随机控制问题提供了严格的泊松近似，并量化了环境灾害风险下自激对最优增长的影响。

Keywords :

### 

\[11\] Harvesting the Variance Risk Premium in Nuclear and Energy Equities

标题:收获核能和能源股票的差异风险溢价

作者:Jilang Miao, Nonna Sorokina

来源:ARXIV\_20260902

链接:https://arxiv.org/pdf/2609.01183

Abstract : We study whether nuclear and energy adjacent equity options exhibit a harvestable variance risk premium. Using CRSP and OptionMetrics data for 2000 2024, we construct a systematic cash secured short put strategy on a curated universe of nuclear related firms. The strategy compares at the money put implied volatility with GARCH based realized volatility forecasts, then evaluates unconditional and IV RV filtered put writing portfolios. The results show positive average option premia, high win rates, and substantially lower volatility than an equal weight stock benchmark, though performance is measured before transaction costs and with a fixed universe.

Keywords : 

Abstract :我们研究了核能和能源相邻股权期权是否表现出可收获的方差风险溢价。我们使用2000-2024年的CRSP和OptionMetrics数据，在精心策划的核相关公司范围内构建了一个系统的现金担保看跌策略。该策略将货币看跌期权隐含波动率与基于GARCH的已实现波动率预测进行比较，然后评估无条件和IV RV过滤看跌期权写作投资组合。结果显示，平均期权溢价为正，胜率高，波动性远低于同等权重股票基准，尽管业绩是在交易成本之前和固定范围内衡量的。

Keywords :

### 

\[12\] Price manipulation in nonlinear transient impact models

标题:非线性瞬态冲击模型中的价格操纵

作者:Minhyeok Lee

来源:ARXIV\_20260903

链接:https://arxiv.org/pdf/2609.02447

Abstract : Transient impact models compose a nonlinearity with a memory kernel, and the order of composition determines the criterion for absence of price manipulation. We classify both orders. If an arbitrary instantaneous law  f  acts on the trading rate before any nonzero integrable Volterra kernel, nonnegative cost on every finite piecewise constant round trip forces  f  to be affine, and linear for every nonzero convolution kernel. In particular, the power law   mathrm sgn (x) x   delta ,   delta 0 , combined with power law decay  t    gamma  ,  0  gamma 1 , admits manipulation if and only if   delta ne1   square root impact is manipulable at every decay exponent, and the region left open by Gatheral s slow rate two block bound   delta  gamma ge1  collapses to the line   delta 1 . Earlier rigidity theorems require a kernel that is bounded at zero  the argument here is a zero volume chattering pump read out by two thin baseline trades, and it applies to singular kernels. If instead a monotone readout acts on the impact state after the kernel, safety for all inputs and all readouts is equivalent to complete positivity of the kernel, with a constructive converse  in particular, square root impact after power law memory is manipulation free. A remote compensating block shows that round trip safety and all input safety coincide for kernels with uniformly vanishing tails and differ, for permanent memory, by an explicit storage quotient. These mechanisms classify every two mode Prony kernel, first order time inhomogeneous memory, and stable fully actuated matrix memory, and they quantify the friction, the two block phase, and the switching complexity behind the power law case. Calibrated exponent pairs all lie in the manipulable set  absent friction, concavity has to enter after the memory, not before it.

Keywords : 

Abstract :瞬态冲击模型由一个记忆核组成非线性，其组成顺序决定了不存在价格操纵的标准。我们对这两个订单进行了分类。如果任意瞬时定律f在任何非零可积Volterra核之前作用于交易率，则每个有限分段常数往返的非负成本迫使f是仿射的，并且对于每个非零卷积核是线性的。特别是，幂律数学sgn（x）x delta，delta 0与幂律衰变t gamma，0 gamma 1相结合，当且仅当delta ne1平方根影响在每个衰变指数下都是可操纵的，并且Gatheral的慢速双块边界delta gamma ge1留下的开放区域坍塌为delta 1线时，才允许操纵。早期的刚性定理要求一个有界于零的核——这里的论点是通过两个薄基线交易读出的零体积抖振泵，它适用于奇异核。相反，如果单调读出作用于核后的冲击状态，则所有输入和所有读出的安全性相当于核的完全正性，特别是幂律记忆无操纵后的平方根冲击。远程补偿块表明，对于尾部均匀消失的核，往返安全性和所有输入安全性是一致的，而对于永久存储器，则存在显式存储商的差异。这些机制对每种双模Prony核、一阶时间非均匀存储器和稳定的全驱动矩阵存储器进行了分类，并量化了幂律情况下的摩擦、两块相位和切换复杂性。校准的指数对都位于可操作集合中，没有摩擦，凹度必须在记忆之后进入，而不是在记忆之前。

Keywords :

### 

\[13\] Modeling Trade Durations under Temporal Granularity Effects in Forex Markets

标题:外汇市场时间粒度效应下的交易持续时间建模

作者:Vladimír Holý

来源:ARXIV\_20260903

链接:https://arxiv.org/pdf/2609.02660

Abstract : Trade durations in high frequency foreign exchange data exhibit increased occurrence near integer values. To address this empirical phenomenon, we propose the granularity adjusted autoregressive conditional duration (GA ACD) model. It is based on a novel two component mixture distribution consisting of a standard generalized gamma component for regular durations and a second component that locally redistributes probability mass around integer values to capture heaping. Conditional dynamics are modeled within a score driven framework, allowing the scale parameter to vary over time in response to past durations, and enabling maximum likelihood estimation of all model parameters. A simulation study shows that ignoring heaping leads to biased parameter estimates and distorted inference regarding both the distribution and the dynamics of durations. An empirical analysis demonstrates that integer duration clustering is pervasive across major currency pairs and that the GA ACD model outperforms the standard generalized gamma ACD model.

Keywords : 

Abstract :高频外汇数据中的交易持续时间在整数值附近出现增加。为了解决这一经验现象，我们提出了粒度调整的自回归条件持续时间（GA-ACD）模型。它基于一种新的双组分混合分布，由一个规则持续时间的标准广义伽马分量和一个在整数值周围局部重新分布概率质量以捕获堆积的第二个分量组成。在分数驱动的框架内对条件动态进行建模，允许尺度参数随时间变化以响应过去的持续时间，并能够对所有模型参数进行最大似然估计。模拟研究表明，忽略堆积会导致参数估计有偏差，并导致对持续时间分布和动态的扭曲推断。实证分析表明，整数持续时间聚类在主要货币对中普遍存在，GA ACD模型优于标准广义gamma ACD模型。

Keywords :

### 

\[14\] Viscosity Supersolution Barriers to a Non local Free Boundary Problem

标题:非局部自由边界问题的粘性超解障碍

作者:Avetik Arakelyan, Lusine Poghosyan

来源:ARXIV\_20260903

链接:https://arxiv.org/pdf/2609.02381

Abstract : We study a parabolic obstacle partial integro differential equation (PIDE) with a dynamically moving bilateral free boundary. This type of problem arises in the mathematical modeling of speculative asset bubbles with L vy jump processes. We consider the existence of viscosity supersolutions within the class of functions exhibiting linear asymptotic growth ( O( g )  at infinity) across three distinct parametric regimes. Our intention is to determine when such a supersolution barrier can be built by analyzing the balance between the stabilizing local drift, defined by the discount rate  r  and mean reversion   rho , and the non local jump dispersion, characterized by the large jump intensity   lambda  and Lipschitz constant  L  gamma . First, when  r  rho    sqrt  lambda L  gamma , we prove the global existence of non negative viscosity supersolutions. Second, in the deficit regime ( r  rho    sqrt  lambda L  gamma ), we prove existence on finite horizons and derive a critical horizon threshold  T   mathrm crit   . Utilizing an asymptotic slope envelope, we prove that no non negative linear growth supersolution can exist beyond  T   mathrm crit   . Finally, at the exact critical boundary ( r  rho    sqrt  lambda L  gamma ), we show global existence by constructing a smooth supersolution, provided an additional spatial no crossing condition holds.

Keywords : 

Abstract :我们研究了一个具有动态移动双边自由边界的抛物型障碍物偏积分微分方程（PIDE）。这类问题出现在具有L vy跳跃过程的投机资产泡沫的数学建模中。我们考虑在三个不同的参数范围内表现出线性渐近增长（O（g）在无穷远处）的函数类中粘度超解的存在性。我们的目的是通过分析由贴现率r和均值回归ρ定义的稳定局部漂移与以大跳跃强度λ和Lipschitz常数Lγ为特征的非局部跳跃色散之间的平衡，来确定何时可以建立这样的超解势垒。首先，当r rho sqrt lambda L gamma时，我们证明了非负粘性超解的全局存在性。其次，在赤字状态（r rho sqrt lambda L gamma）下，我们证明了有限视界上的存在性，并推导出了临界视界阈值T的数学判据。利用渐近斜率包络，我们证明了在T数学判据之外不存在非负线性增长超解。最后，在精确的临界边界（r rho sqrt lambda L gamma）处，我们通过构造一个平滑的超解来证明全局存在性，前提是满足额外的空间无交叉条件。

Keywords :

### 

\[15\] Mean field equilibrium of heterogeneous agents under market impact

标题:市场冲击下异质主体的平均场均衡

作者:Joseph Leclère, Mathieu Rosenbaum

来源:ARXIV\_20260904

链接:https://arxiv.org/pdf/2609.03115

Abstract : Although market participants generally have access to a common information set, they make decisions based on forecasts formed over heterogeneous horizons. Because market impact depends on aggregate positions rather than trader identities, these decisions feed back into prices through their collective effect. We introduce a linear mean field model of this interaction. The observed price is decomposed into a martingale component, a common predictable signal represented by a Volterra process, and the market impact generated by aggregate positions. Agents take positions according to conditional forecasts of future signal increments and a fraction of anticipated aggregate impact over their respective horizons. Within a Gaussian Volterra framework, we characterize equilibrium through a linear fixed point equation for aggregate positions and establish existence and uniqueness under explicit conditions. At equilibrium, we identify a balance condition that cancels the direct transmission of the common signal to the observed price. We then study the limit in which agents fully account for market impact. Along a suitably scaled family of equilibria satisfying explicit conditions, the contributions of the predictable signal and the market impact cancel in the limit, and the observed price converges to its martingale component. For fractional type signals and Gamma distributed horizons, we further derive local H lder bounds and identify the horizon distributions for which the observed price has local regularity compatible with that of Brownian motion.

Keywords : 

Abstract :尽管市场参与者通常可以访问一个共同的信息集，但他们根据在异质视野中形成的预测做出决策。因为市场影响取决于总头寸而不是交易者身份，这些决策通过其集体效应反馈到价格中。我们引入了这种相互作用的线性平均场模型。观察到的价格被分解为鞅分量、由Volterra过程表示的常见可预测信号和由总头寸产生的市场影响。代理人根据对未来信号增量的有条件预测和各自视野内预期总影响的一小部分来确定头寸。在高斯-Volterra框架内，我们通过聚集位置的线性不动点方程来表征平衡，并在显式条件下建立存在性和唯一性。在均衡状态下，我们确定了一个平衡条件，该条件取消了公共信号向观测价格的直接传输。然后，我们研究了代理人充分考虑市场影响的极限。在满足显式条件的适当规模的均衡家族中，可预测信号和市场影响的贡献在极限内相互抵消，观察到的价格收敛到其鞅分量。对于分数型信号和Gamma分布的视界，我们进一步推导了局部霍尔德界，并确定了观测价格具有与布朗运动相容的局部规律性的视界分布。

Keywords :

### 

\[16\] Bayesian Confidence Recalibration and Research Equilibrium Criticality

标题:贝叶斯置信度重新校准与研究均衡临界性

作者:Han Yanç

来源:ARXIV\_20260904

链接:https://arxiv.org/pdf/2609.03741

Abstract : Robust portfolio rules that reconstruct confidence sets after learning need not preserve the evaluator obtained by prior by prior Bayesian transport. In the Gaussian model, this discrepancy is summarized by natural coordinate displacement  inherited transport preserves it whereas fresh reconstruction can replace it. We price evaluator replacement and trace the resulting optimized curvature through endogenous research. Optimized robust value represents protocol regret as a functional Bregman divergence, while a within vintage rectangular Gaussian benchmark with constant absolute risk aversion (CARA) yields a stopped recalibration tax. In a versioned model release economy, validated history propagates through a strictly causal network and a same cycle share of current optimized marginal value feeds back into research supply. The capacity constrained equilibrium reduces to a scalar equation with protocol indexed gain  ( mathfrak g I P  lambda beta  R,I (W R P)   ). Purely causal validation cannot create a same cycle unit mode  provenance changes criticality through optimized curvature. For a scalar primitive supplier score shock  (z ) in direction  (h I ) and financial outcome  ( mathcal O ), sensitivity factors as  ( omega   mathcal O,h,I  (1  mathfrak g I P) ). Conditional on a smooth equilibrium state and active cell, completion time information sharply bounds this multiplier when all compatible timing laws are subcritical  no finite uniform bound exists when the timing set reaches the pole.

Keywords : 

Abstract :在学习后重建置信集的稳健投资组合规则不需要保留通过先验贝叶斯传输获得的评估器。在高斯模型中，这种差异可以用自然坐标位移来概括——继承的传输保留了它，而新的重建可以替换它。我们对评估器替换进行定价，并通过内生研究追踪得到的优化曲率。优化的稳健值将协议遗憾表示为函数布雷格曼散度，而具有恒定绝对风险规避（CARA）的老式矩形高斯基准则产生停止重新校准税。在版本化模型发布经济中，验证的历史通过严格的因果网络传播，当前优化边际价值的相同周期份额反馈到研究供应中。容量约束均衡简化为具有协议索引增益的标量方程（mathfrak g I P lambda beta R，I（W R P））。纯粹的因果验证无法通过优化曲率来创建相同的循环单元模式起源变化临界性。对于方向（h I）和财务结果（matcal O）上的标量原始供应商得分冲击（z），敏感性因子为（ωmatcal O，h，I（1 mathfrak g I P））。在平滑平衡状态和活动单元的条件下，当所有兼容的时序律都是亚临界时，完成时间信息会急剧限制这个乘数——当时序集达到极点时，不存在有限的统一界限。

Keywords :

### 

\[17\] Global Multi Maturity SPX VIX Calibration Beyond Markovian Stitching

标题:超越马尔可夫缝合的全球多成熟度SPX VIX校准

作者:Atithi Acharya, Yue Sun, Brandon Augustino, Shouvanik Chakrabarti, Shree Hari Sureshbabu, Charlie Che

来源:ARXIV\_20260904

链接:https://arxiv.org/pdf/2609.04087

Abstract : We develop a global framework for joint S&P 500 (SPX) VIX smile calibration across multiple maturities without the conditional independence restriction induced by Markovian stitching. Exact local and global feasibility are equivalent  every globally feasible law has a block preserving SPX Markovization that leaves each monthly  (S i,V i,S  i 1 )  law unchanged. Nevertheless, stitched laws can form a strict subset of globally feasible path laws because Markovization discards dependence on earlier history beyond the current SPX level. Adjacent smiles therefore cannot identify this dependence, and laws with identical monthly calibrations can price multi period claims differently. Under the standard Markov reference, relative entropy selects the stitched minimum information completion  non Markov dependence requires cross period information, an appropriate objective, or a history dependent prior. For finite discretizations, we introduce an augmented Bregman mirror descent scheme. It preserves the fit to observable quote moments while controlling martingale and dispersion residuals. In a controlled infeasible affine system, this split keeps prescribed marginals about  25  times tighter than cyclic row projection by exposing the discrepancy in the conditional rows. An exact finite state example verifies block preservation and exhibits material cross period price changes after Markovization. On smoothed SPX and VIX surfaces, numerical calculations illustrate a finite budget penalty path  the worst fitted smile error remains below  0.70  volatility points across the reported sweep while the bulk conditional diagnostics improve substantially.

Keywords : 

Abstract :我们开发了一个跨多个到期日的标普500指数（SPX）VIX联合微笑校准的全球框架，没有马尔可夫拼接引起的条件独立性限制。精确的局部和全局可行性是等价的——每个全局可行定律都有一个块保持的SPX马尔可夫化，使每个月（Si，VI，Si1）定律保持不变。然而，缝合定律可以形成全局可行路径定律的严格子集，因为马尔可夫化抛弃了对当前SPX水平之外的早期历史的依赖。因此，相邻的微笑无法识别这种依赖性，具有相同月度校准的法律可能会对多期索赔进行不同的定价。在标准马尔可夫参考下，相对熵选择缝合的最小信息完成——非马尔可夫依赖需要跨周期信息、适当的目标或历史相关的先验。对于有限离散化，我们引入了一种增广Bregman镜像下降方案。它在控制鞅和色散残差的同时保持了对可观测引用矩的拟合。在受控的不可行仿射系统中，这种分割通过暴露条件行中的差异，使规定的边缘比循环行投影严格约25倍。一个精确的有限状态示例验证了块保持性，并展示了马尔可夫化后的材料跨期价格变化。在平滑的SPX和VIX表面上，数值计算表明了有限的预算惩罚路径——在报告的扫描范围内，最差的拟合微笑误差保持在0.70波动点以下，而批量条件诊断显著改善。

Keywords :