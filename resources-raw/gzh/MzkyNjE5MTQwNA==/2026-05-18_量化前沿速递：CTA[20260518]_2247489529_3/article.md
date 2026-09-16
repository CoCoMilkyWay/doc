# 量化前沿速递：CTA\[20260518\]

shameless 量化前沿速递 2026-05-18 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489529&idx=3&sn=08ee22bce4a8c99bd8dad20a55c1c5c5&chksm=c38f86c7bf961c2a1b4abccaf5eb54f475d110801334fb8fcc3b332e7c5b795d63a50e2f7b37#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489529&idx=3&sn=08ee22bce4a8c99bd8dad20a55c1c5c5&chksm=c38f86c7bf961c2a1b4abccaf5eb54f475d110801334fb8fcc3b332e7c5b795d63a50e2f7b37#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Extrema, Barrier Options, and Semi Analytic Leverage Corrections in Stochastic Clock Volatility Models

随机时钟波动率模型中的极值、障碍期权和半解析杠杆修正

来源:ARXIV\_20260511

\[2\] American Options Pricing under Heston Model via Curriculum Learning in Coupled PINNs

Heston模型下基于耦合PINN课程学习的美式期权定价

来源:ARXIV\_20260511

\[3\] Stochastic Calculus and the Black Scholes Merton Model

随机微积分与Black-Scholes-Merton模型

来源:ARXIV\_20260511

\[4\] Modeling Stochastic Multi Agent Interaction in Intraday Battery Energy Storage Dispatch with Market Power

基于市场力量的日内电池储能调度随机多智能体交互建模

来源:ARXIV\_20260511

\[5\] The Phase Structure of Metallic Money

金属货币的相结构

来源:ARXIV\_20260512

\[6\] On the probability distribution of long term changes in the growth rate of the global economy

全球经济增长率长期变化的概率分布

来源:ARXIV\_20260512

\[7\] Optimal Control of the Ethena Yield Bearing Stablecoin

乙醇产量稳定的最优控制

来源:ARXIV\_20260513

\[8\] A deep learning approach for pricing convertible bonds with path dependent reset and call provisions

具有路径依赖重置和赎回条款的可转换债券定价的深度学习方法

来源:ARXIV\_20260513

\[9\] The P behind Q

Q后面的P

来源:ARXIV\_20260513

\[10\] Nonlinear filtering with stochastic discontinuities

具有随机不连续性的非线性滤波

来源:ARXIV\_20260513

\[11\] Yield Curves Dynamics Using Variational Autoencoders Under No arbitrage

无套利条件下使用变分自编码器的收益率曲线动力学

来源:ARXIV\_20260514

\[12\] The fine structure of electricity price volatility

电价波动的精细结构

来源:ARXIV\_20260514

\[13\] Synthetic American Option Pricing via Jump HMM Driven Heston Implied Volatility

基于跳跃HMM驱动的赫斯顿隐含波动率的合成美式期权定价

来源:ARXIV\_20260515

### 

\[1\] Extrema, Barrier Options, and Semi Analytic Leverage Corrections in Stochastic Clock Volatility Models

标题:随机时钟波动率模型中的极值、障碍期权和半解析杠杆修正

作者:Tristan Guillaume (CYU)

来源:ARXIV\_20260511

链接:https://arxiv.org/pdf/2605.06677

Abstract : Barrier derivatives depend on extrema and first passage events and are therefore highly sensitive to volatility dynamics    especially to the instantaneous return volatility correlation   rho , often called   leverage  . This sensitivity makes accurate and fast pricing under realistic stochastic volatility specifications difficult  two dimensional PDE solvers are expensive inside calibration loops, while Monte Carlo methods converge slowly when barrier hits are rare and discretely monitored. In equity markets in particular, the pronounced implied volatility skew motivates factoring in a negative return volatility correlation. We study a class of continuous path stochastic clock volatility models in which the log price is represented as a Brownian motion run on a random increasing clock. In the baseline independent clock case ( rho 0), a broad family of barrier relevant objects maximum distributions, survival probabilities, and killed joint laws reduces to one dimensional quantities determined by the Laplace transform of the terminal clock. This yields transform only pricing formulas for single  and double barrier contracts that are fast and numerically stable once the clock transform is available, notably for affine and quadratic clocks. To incorporate leverage without forfeiting tractability, we develop a systematic small  rho expansion around the  rho 0 backbone. The expansion produces a hierarchy of forced problems whose forcing terms are semi analytic and computable from baseline barrier objects. We provide two implementable leverage correction routes ,  forced PDEs and a Duhamel type Monte Carlo representation, and we show how Pad    acceleration can extend practical accuracy to equity like correlations. Calibration then proceeds by ,  (i) fitting clock parameters from vanillas using only one dimensional transforms, (ii) precomputing the  rho 0 barrier backbone once, and (iii) iterating on  rho (and any remaining parameters) using the fast semi analytic corrections optionally Pad    accelerated inside a standard least squares loop.

Keywords : 

Abstract :障碍衍生品依赖于极值和首次通过事件，因此对波动动态高度敏感，尤其是对瞬时回报波动相关性rho，通常称为杠杆。这种敏感性使得在现实的随机波动率规范下进行准确和快速的定价变得困难——二维PDE求解器在校准循环内很昂贵，而蒙特卡洛方法在很少遇到障碍并受到离散监测时收敛缓慢。特别是在股票市场，明显的隐含波动率偏差促使我们考虑负回报波动率相关性。我们研究了一类连续路径随机时钟波动模型，其中对数价格表示为在随机递增时钟上运行的布朗运动。在基线独立时钟情况下（rho 0），一系列与障碍物相关的物体最大分布、存活概率和死亡关节定律简化为由终端时钟的拉普拉斯变换确定的一维量。这产生了单屏障和双屏障合约的仅变换定价公式，一旦时钟变换可用，这些公式就快速且数值稳定，特别是对于仿射和二次时钟。为了在不丧失可处理性的情况下引入杠杆，我们围绕rho 0骨干开发了一个系统的小rho扩展。这种扩展产生了一个受迫问题的层次结构，其受迫项是半解析的，可以从基线障碍物中计算出来。我们提供了两种可实现的杠杆校正路线，强制PDE和Duhamel型蒙特卡洛表示，我们展示了Pad加速如何将实际精度扩展到类似股权的相关性。然后，校准通过以下方式进行：（i）仅使用一维变换从香草中拟合时钟参数，（ii）预先计算一次rho 0屏障骨干，以及（iii）使用快速半解析校正迭代rho（和任何剩余参数），可选地在标准最小二乘环内加速Pad。

Keywords :

### 

\[2\] American Options Pricing under Heston Model via Curriculum Learning in Coupled PINNs

标题:Heston模型下基于耦合PINN课程学习的美式期权定价

作者:Rohan, Siddanth Shetty, Amit N. Kumar

来源:ARXIV\_20260511

链接:https://arxiv.org/pdf/2605.06688

Abstract : In American options, the early exercise feature allows the option to be exercised at any time prior to expiration. However, this flexibility introduces a challenge  the pricing model must value the option while simultaneously determining an unknown, time varying exercise boundary. The Heston model is one of the most popular ways to model real market behavior because it allows volatility to change over time. However, unlike European options, there is no closed form solution for American options under the Heston model, so we have to use numerical methods. In this paper, we propose a novel approach to solving the stochastic Heston partial differential equation for American options, using coupled physics informed neural networks (PINNs) to predict both the option price and the free boundary, while employing curriculum learning and adaptive resampling to stabilize model training. Our work builds on recent deep learning methods but introduces a more effective training strategy to address the limitations of these approaches. The numerical results demonstrate the effectiveness of the proposed learning framework, providing a robust and efficient alternative to pricing American options, enabling rapid inference and accurate estimation under stochastic volatility.

Keywords : 

Abstract :在美式期权中，提前行使功能允许期权在到期前的任何时间行使。然而，这种灵活性带来了一个挑战——定价模型必须对期权进行估值，同时确定一个未知的、时变的行使边界。赫斯顿模型是模拟真实市场行为最流行的方法之一，因为它允许波动性随时间而变化。然而，与欧式期权不同，在赫斯顿模型下，美式期权没有闭式解，因此我们必须使用数值方法。本文提出了一种求解美式期权随机Heston偏微分方程的新方法，该方法使用耦合的物理知情神经网络（PINN）来预测期权价格和自由边界，同时采用课程学习和自适应重采样来稳定模型训练。我们的工作建立在最近的深度学习方法的基础上，但引入了一种更有效的训练策略来解决这些方法的局限性。数值结果证明了所提出的学习框架的有效性，为美式期权定价提供了一种稳健有效的替代方案，在随机波动下实现了快速推理和准确估计。

Keywords :

### 

\[3\] Stochastic Calculus and the Black Scholes Merton Model

标题:随机微积分与Black-Scholes-Merton模型

作者:Kuo-Ping Chang

来源:ARXIV\_20260511

链接:https://arxiv.org/pdf/2605.07558

Abstract : This paper refutes the claim that the expected rate of return of the underlying asset plays no role in the Black Scholes Merton option pricing model.

Keywords : 

Abstract :本文驳斥了标的资产的预期收益率在Black-Scholes-Merton期权定价模型中不起作用的说法。

Keywords :

### 

\[4\] Modeling Stochastic Multi Agent Interaction in Intraday Battery Energy Storage Dispatch with Market Power

标题:基于市场力量的日内电池储能调度随机多智能体交互建模

作者:Ruimeng Hu, Mike Ludkovski, Hezhong Zhang

来源:ARXIV\_20260511

链接:https://arxiv.org/pdf/2605.01178

Abstract : We develop a stochastic game theoretic model for intraday dispatch of grid scale battery energy storage systems (BESSs). We assume that each BESS operator competitively manages her state of charge to maximize energy arbitrage revenues, driven by the endogenized electricity price that depends on the sum of the charging rates. We characterize the Nash equilibrium of the resulting finite player linear quadratic differential game with a shared stochastic driver, obtaining semi explicit representations of equilibrium feedback controls and equilibrium prices both in the general heterogeneous and the simplified homogeneous BESS setting, via a system of Riccati equations. We then analyze competitive effects, including the marginal externality of additional BESS entering the market, the benefit of coordination and the corresponding market power of large operators, and supply effects from hybrid type BESSs. We further study the asymptotic regime as the number of agents grows large. Our model provides a quantitative testbed to study the impact of decentralized BESS deployment on the grid and the resulting reduction in daily price spreads.

Keywords : 

Abstract :我们开发了一个随机博弈论模型，用于电网规模电池储能系统（BESS）的日内调度。我们假设每个BESS运营商都在竞争性地管理其充电状态，以最大化能源套利收入，这是由取决于充电率总和的内生电价驱动的。我们刻画了具有共享随机驱动的有限参与者线性二次微分博弈的纳什均衡，通过Riccati方程组，在一般异质和简化齐次BESS设置中获得了均衡反馈控制和均衡价格的半显式表示。然后，我们分析了竞争效应，包括额外BESS进入市场的边际外部性、协调效益和大型运营商的相应市场力量，以及混合型BESS的供应效应。随着代理数量的增加，我们进一步研究了渐近机制。我们的模型为研究分散式BESS部署对电网的影响以及由此导致的每日价差的减小提供了一个定量试验平台。

Keywords :

### 

\[5\] The Phase Structure of Metallic Money

标题:金属货币的相结构

作者:Ran Huang

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.08788

Abstract : The Spanish Price Revolution is usually treated as a classic case in which American bullion inflows expanded the money supply and generated inflation. This view captures the first phase of the episode but fails to explain why the same monetary expansion did not continue to produce proportional price growth after 1600. We develop a two phase Money Phase Transition Theory (MPTT) model in which the classical monetary relation is recovered before a transition point, while a second phase correction term modifies the money price transmission coefficient after the transition. Using annual Spanish CPI and reconstructed money supply data, we show that 1500 1600 was a high transmission metallic inflationary phase  CPI increased approximately 3.35 fold while money supply increased approximately 3.73 fold. After 1600, money supply continued to rise, increasing approximately 1.82 fold during 1600 1650, while CPI rose only approximately 1.22 fold. A classical one phase model fitted on 1500 1600, therefore, overpredicts post 1600 prices when extrapolated forward. The MPTT two phase model with transition point tau 1600 estimates beta 1 0.949, gamma  0.812, and beta 2 beta 1 gamma 0.137, indicating a sharp post transition weakening of monetary transmission. An unrestricted break scan identifies a deeper BIC minimizing break around 1636. These results suggest that the Spanish Price Revolution was not a single monotonic bullion inflation process but the rise and exhaustion of high transmission metallic money inflation.

Keywords : 

Abstract :西班牙价格革命通常被视为美国黄金流入扩大货币供应并引发通货膨胀的经典案例。这一观点捕捉到了事件的第一阶段，但未能解释为什么1600年后同样的货币扩张没有继续产生成比例的价格增长。我们开发了一个两阶段货币阶段过渡理论（MPTT）模型，其中经典货币关系在过渡点之前恢复，而第二阶段修正项在过渡后修改货币价格传导系数。使用西班牙年度CPI和重建的货币供应量数据，我们发现1500 1600是高传导金属通胀阶段，CPI增长了约3.35倍，而货币供应量增长了约3.73倍。1600年后，货币供应量继续上升，在1600年至1650年间增长了约1.82倍，而CPI仅增长了约1.22倍。因此，在1500 1600上拟合的经典单相模型在向前推断时高估了1600年后的价格。具有转变点tau 1600的MPTT两相模型估计β1 0.949、γ0.812和β2β1γ0.137，表明货币传导在转变后急剧减弱。无限制的中断扫描可以识别出1636年左右更深的BIC，从而最大限度地减少中断。这些结果表明，西班牙价格革命不是一个单一的单调的金价通胀过程，而是高传导金属货币通胀的上升和耗尽。

Keywords :

### 

\[6\] On the probability distribution of long term changes in the growth rate of the global economy

标题:全球经济增长率长期变化的概率分布

作者:David Roodman

来源:ARXIV\_20260512

链接:https://arxiv.org/pdf/2605.09182

Abstract : Daniel Kahneman and Amos Tversky argued for challenging inside views (informed by contextual specifics) with outside views (based on historical  base rates  for certain event types). A reasonable inside view of the prospects for the global economy in this century is that growth will converge to 2.5  year or less  population growth is expected to slow or halt by 2100  and as more countries approach the technological frontier, economic growth should slow as well. To test that view, this paper models gross world product (GWP) observed since 10,000 BCE or earlier, in order to estimate a base distribution for changes in the growth rate as a function of the GWP level. For econometric rigor, it casts a GWP series as a sample path in a stochastic diffusion whose specification is novel yet rooted in neoclassical growth theory. After estimation, most observations fall between the 40th and 60th percentiles of predicted distributions. The fit implies that GWP explosion is all but inevitable, in a median year of 2047. The friction between inside and outside views highlights two insights. First, accelerating growth is more easily explained by theory than is constant growth. Second, the world system may be less stable than traditional growth theory and the growth record of the last two centuries suggest.

Keywords : 

Abstract :Daniel Kahneman和Amos Tversky主张用外部观点（基于某些事件类型的历史基准率）挑战内部观点（基于上下文细节）。对本世纪全球经济前景的合理内部看法是，增长将收敛到2.5年或更短时间。到2100年，人口增长预计将放缓或停止，随着越来越多的国家接近技术前沿，经济增长也应放缓。为了验证这一观点，本文对自公元前10000年或更早以来观察到的世界生产总值（GWP）进行了建模，以估算增长率变化随GWP水平变化的基本分布。为了计量经济学的严谨性，它将GWP序列作为随机扩散中的样本路径，其规范新颖，但植根于新古典增长理论。经过估计，大多数观测值落在预测分布的40到60百分位数之间。这一拟合意味着，全球变暖潜势的爆炸几乎是不可避免的，在2047年的中位数。内部和外部观点之间的摩擦突显了两个见解。首先，加速增长比持续增长更容易用理论来解释。其次，世界体系可能不如传统增长理论和过去两个世纪的增长记录所表明的那样稳定。

Keywords :

### 

\[7\] Optimal Control of the Ethena Yield Bearing Stablecoin

标题:乙醇产量稳定的最优控制

作者:Matthew Lorig

来源:ARXIV\_20260513

链接:https://arxiv.org/pdf/2605.11263

Abstract : We formulate and solve stochastic control problems that model the core yield generating strategy of the Ethena protocol, a decentralized finance (DeFi) stablecoin that earns yield by combining a long position in staked Ethereum (stETH) with an equal sized short position in ETH perpetual futures. The combined position is delta neutral with respect to the ETH spot price, yet earns carry from two sources  staking rewards on the stETH leg, and funding rate payments received from long perpetual holders when the perpetual trades at a premium to spot. A key feature of our model is that the control    the rate of simultaneously buying stETH and shorting the perpetual    exerts two distinct types of price impact.  textit Permanent  impact shifts the mid market prices of both legs, compressing the basis and permanently eroding future funding income.  textit Temporary  impact reflects execution slippage on each leg. We study both an infinite horizon discounted problem and a finite horizon problem in which the protocol maximizes total wealth up to a fixed date  T , subject to a terminal cost for liquidating any remaining position. In both cases the optimal control is obtained explicitly.

Keywords : 

Abstract :我们制定并解决了随机控制问题，该问题模拟了Ethena协议的核心收益生成策略，Ethena协议是一种去中心化金融（DeFi）稳定币，通过将以太坊（stETH）的多头头寸与以太坊永久期货中同等规模的空头头寸相结合来获得收益。合并后的头寸相对于ETH现货价格是增量中性的，但从两个来源获得套利，即在stETH腿上下注奖励，以及在永续交易溢价现货时从长期永续持有人那里获得的资金利率支付。我们模型的一个关键特征是，控制同时购买stETH和做空永续的比率会产生两种不同类型的价格影响。textit永久性影响改变了两条腿的中端市场价格，压缩了基础，永久性地侵蚀了未来的融资收入。textit临时影响反映了每条腿上的执行失误。我们研究了无限期贴现问题和有限期问题，其中协议在固定日期T之前最大化总财富，但要考虑清算任何剩余头寸的终端成本。在这两种情况下，都明确地获得了最优控制。

Keywords :

### 

\[8\] A deep learning approach for pricing convertible bonds with path dependent reset and call provisions

标题:具有路径依赖重置和赎回条款的可转换债券定价的深度学习方法

作者:Qinwen Zhu, Wen Chen, Nicolas Langrené

来源:ARXIV\_20260513

链接:https://arxiv.org/pdf/2605.12189

Abstract : This paper develops a deep learning based framework for pricing convertible bonds with path dependent contractual features, namely downward conversion price reset and issuer call clauses under rolling window trigger rules, which are widespread in the convertible bond market. We formulate the valuation problem as a path dependent partial differential equation (PPDE), which explicitly captures the dependence of the convertible bond value on the historical path of the underlying asset and the dynamic evolution of the conversion price. We derive consistent PPDE formulations for three canonical underlying dynamics  geometric Brownian motion (GBM), constant elasticity of variance (CEV) and Heston stochastic volatility. We then construct a discrete time dynamic programming scheme in which conditional expectations are approximated by neural networks, which remains tractable in such high dimensional path dependent setting. Empirical tests on China CITIC Bank Convertible Bond show that our framework produces stable and accurate prices and sensitivity patterns across all model specifications. Three key economic insights emerge  1. Contractual features dominate underlying dynamics in determining convertible bond values. 2. The call provision decreases convertible bonds prices by truncating upside gains. 3. Counterintuitively, despite improving conversion terms, the downward reset provision further decreases the price of convertible bonds by lowering the effective call threshold and making early redemption more likely. The proposed PPDE deep learning approach provides an efficient, flexible tool for pricing convertible bonds with complex path dependent structures.

Keywords : 

Abstract :本文开发了一个基于深度学习的可转换债券定价框架，该框架具有路径依赖的契约特征，即滚动窗口触发规则下的向下转换价格重置和发行人赎回条款，这些特征在可转换债券市场中很普遍。我们将估值问题表述为路径相关偏微分方程（PPDE），该方程明确地捕捉了可转换债券价值对标的资产历史路径和转换价格动态演变的依赖性。我们推导了三个典型潜在动力学几何布朗运动（GBM）、恒定方差弹性（CEV）和赫斯顿随机波动率的一致PPDE公式。然后，我们构建了一个离散时间动态规划方案，其中条件期望由神经网络近似，在这种高维路径相关设置中仍然可以处理。对中信银行可转换债券的实证检验表明，我们的框架在所有模型规范中都产生了稳定准确的价格和敏感性模式。出现了三个关键的经济见解1。在决定可转换债券价值时，契约特征主导着潜在的动态。2.赎回条款通过截断上行收益来降低可转换债券的价格。3.与直觉相反，尽管转换条款有所改善，但向下重置条款通过降低有效赎回门槛和增加提前赎回的可能性，进一步降低了可转换债券的价格。所提出的PPDE深度学习方法为具有复杂路径依赖结构的可转换债券定价提供了一种高效、灵活的工具。

Keywords :

### 

\[9\] The P behind Q

标题:Q后面的P

作者:Useong Shin

来源:ARXIV\_20260513

链接:https://arxiv.org/pdf/2605.12250

Abstract : Put call parity is exact as a terminal payoff identity, yet its market enforcement is path dependent and capital using. This paper examines whether physical measure drift is reflected in the carry gap, defined as the annualized wedge between option implied and OIS implied discounting, using SPX and RUT European index options. I derive a drift preserving extension of the GBM implementation risk term that adds an (r mu tau) component to the standard (r sigma sqrt  tau ) path risk component. The drift input ( mu) is measured by a lagged rolling OLS trend proxy and should not be interpreted as an observed expected return. Empirically, the drift term improves both in sample and leave one year out fit, especially for SPX, consistent with drift sensitive margin burden in parity enforcement rather than a failure of no arbitrage.

Keywords : 

Abstract :看跌期权平价作为终端支付身份是精确的，但其市场执行是路径依赖和资本使用的。本文使用SPX和RUT欧洲指数期权，研究了实物计量漂移是否反映在利差中，利差定义为隐含期权和OIS隐含贴现之间的年化楔形。我推导出了GBM实施风险项的漂移保持扩展，该扩展将（r mu-tau）分量添加到标准（r sigma-sqrt-tau）路径风险分量中。漂移输入（μ）由滞后滚动OLS趋势代理测量，不应被解释为观察到的预期回报。从经验上讲，漂移项在样本和一年内都有所改善，特别是对于SPX，这与平价执行中漂移敏感的保证金负担相一致，而不是没有套利的失败。

Keywords :

### 

\[10\] Nonlinear filtering with stochastic discontinuities

标题:具有随机不连续性的非线性滤波

作者:Thorsten Schmidt, Félix B. Tambe-Ndonfack

来源:ARXIV\_20260513

链接:https://arxiv.org/pdf/2605.12142

Abstract : Filtering problems with jumps in both the signal and the observation have been extensively studied, typically under the assumption that jump times are totally inaccessible. In many applications, however, jump times are known in advance (i.e., predictable), such as scheduled clinical visits, dividend payment dates, or inspection times in engineering systems. Taking predictable jump times as a starting point, we investigate a filtering problem in which both the signal and the observations can exhibit jumps at predictable times. We derive the corresponding Kushner Stratonovich and Zakai equations, thereby extending classical nonlinear filtering results to a setting with predictable discontinuities. We illustrate the framework on a Kalman filtering model with predictable jumps and on applications to longitudinal clinical studies, such as spinal muscular atrophy (SMA), as well as to machine learning models (neural jump ODEs) and credit risk.

Keywords : 

Abstract :对信号和观测值中跳跃的滤波问题进行了广泛的研究，通常是在跳跃时间完全不可访问的假设下进行的。然而，在许多应用中，跳跃时间是预先知道的（即可预测的），例如计划的临床就诊、股息支付日期或工程系统中的检查时间。以可预测的跳跃时间为起点，我们研究了一个滤波问题，其中信号和观测值都可以在可预测的时间出现跳跃。我们推导了相应的Kushner Stratonovich和Zakai方程，从而将经典的非线性滤波结果扩展到具有可预测不连续性的环境中。我们说明了具有可预测跳跃的卡尔曼滤波模型的框架，以及在纵向临床研究中的应用，如脊髓性肌萎缩症（SMA），以及机器学习模型（神经跳跃ODE）和信用风险。

Keywords :

### 

\[11\] Yield Curves Dynamics Using Variational Autoencoders Under No arbitrage

标题:无套利条件下使用变分自编码器的收益率曲线动力学

作者:Fusheng Luo, H'elyette Geman

来源:ARXIV\_20260514

链接:https://arxiv.org/pdf/2605.12764

Abstract : This paper introduces a physics informed generative framework that resolves the fundamental conflict between the statistical flexibility of deep learning and the rigorous theoretical constraints of fixed income modeling. We demonstrate that standard generative models and unconstrained statistical extrapolations suffer from  manifold collapse  and severe arbitrage violations when forecasting term structures across diverse macroeconomic regimes. To overcome this, we propose a two stage architecture. First, a Student t Conditional Variational Autoencoder with Dynamic Level Injection (CVAEsT LS) extracts a robust, heavy tailed term structure manifold, effectively decoupling macroeconomic shape dynamics from absolute base rates. Second, the latent dynamic evolution is governed by a continuous time Neural Stochastic Differential Equation (SDE) strictly penalized by a No Arbitrage Partial Differential Equation (PDE). Empirical results across multiple sovereign currencies (USD, GBP, JPY) confirm that our synergistic approach drastically reduces out of sample forecasting errors    achieving an exceptional 6.58 bps Mean Tenor RMSE    and successfully overcomes the massive parallel drift and zero lower bound violations exhibited by the classical HJM model in extreme environments. Furthermore, through phase space vector field analysis, we demonstrate the model s superior capability in unsupervised macroeconomic regime detection and high quality continuous time scenario generation. Ultimately, this research provides a highly scalable, mathematically sound evolutionary engine for term structure modeling.

Keywords : 

Abstract :本文介绍了一种基于物理的生成框架，该框架解决了深度学习的统计灵活性与固定收益建模的严格理论约束之间的根本冲突。我们证明，在预测不同宏观经济制度的期限结构时，标准生成模型和无约束统计外推会遭受多重崩溃和严重的套利违规。为了克服这一点，我们提出了一种两阶段架构。首先，具有动态水平注入的Student t条件变分自编码器（CVAEsT-LS）提取了一个鲁棒的重尾项结构流形，有效地将宏观经济形态动态与绝对基准利率解耦。其次，潜在的动态演化由连续时间神经随机微分方程（SDE）控制，该方程受到无套利偏微分方程（PDE）的严格惩罚。跨多种主权货币（美元、英镑、日元）的实证结果证实，我们的协同方法大大减少了样本外预测误差，实现了6.58个基点的平均期限RMSE，并成功克服了经典HJM模型在极端环境中表现出的大规模平行漂移和零下限违规。此外，通过相空间矢量场分析，我们证明了该模型在无监督宏观经济状态检测和高质量连续时间场景生成方面的优越能力。最终，这项研究为期限结构建模提供了一个高度可扩展、数学上合理的进化引擎。

Keywords :

### 

\[12\] The fine structure of electricity price volatility

标题:电价波动的精细结构

作者:Thomas K. Kloster, Fred Espen Benth

来源:ARXIV\_20260514

链接:https://arxiv.org/pdf/2605.13320

Abstract : We conduct the first rigorous study of electricity price volatility for the full panel of electricity prices across three European generation zones. By interpreting the observed day ahead prices as local averages of a latent price process governed by a stochastic partial differential equation, we develop estimators of the weekly integrated variance. The inherently infinite dimensional setting introduce several complications that are not relevant in the conventional finite dimensional semimartingale setting, and we spend considerable effort in dealing with these. In particular, we must account for both mean reversion in prices and semigroup smoothing in the estimated variance. We provide a detailed decomposition and interpretation of the empirical estimates across three vastly different European generation zones, namely Germany, Norway, and Spain. Our findings indicate that each zone has very different drivers of volatility, and that the impact of generation variables differs considerably. We document that leverage effects appear to be present at first sight, but disappear once we condition on suitable state variables, thereby showing that electricity price volatility does not generally exhibit asymmetric responses to price shocks.

Keywords : 

Abstract :我们首次对三个欧洲发电区的全面板电价波动进行了严格的研究。通过将观测到的日前价格解释为由随机偏微分方程控制的潜在价格过程的局部平均值，我们开发了周积分方差的估计量。固有的无限维设置引入了一些与传统有限维半鞅设置无关的复杂情况，我们在处理这些问题上付出了相当大的努力。特别是，我们必须考虑价格的均值回归和估计方差的半群平滑。我们对三个截然不同的欧洲发电区（即德国、挪威和西班牙）的经验估计进行了详细的分解和解释。我们的研究结果表明，每个区域都有非常不同的波动驱动因素，发电变量的影响也大不相同。我们记录了杠杆效应乍一看似乎是存在的，但一旦我们设定了合适的状态变量，杠杆效应就会消失，从而表明电价波动通常不会对价格冲击表现出不对称的反应。

Keywords :

### 

\[13\] Synthetic American Option Pricing via Jump HMM Driven Heston Implied Volatility

标题:基于跳跃HMM驱动的赫斯顿隐含波动率的合成美式期权定价

作者:Julia Sun, Zheyu Jin, Jiawei Zhang, Jeffrey D. Varner

来源:ARXIV\_20260515

链接:https://arxiv.org/pdf/2605.13998

Abstract : Generating realistic synthetic option prices requires implied volatility as an input, yet implied volatility is itself derived from observed option prices, creating a circular dependency that limits synthetic data for machine learning and risk analysis applications. We break this circularity with a pipeline in which implied volatility emerges as an output of a structural model of equity returns. A Jump Hidden Markov Model produces multi asset price paths with realistic stylized facts and cross asset tail dependence  a modified Heston variance process, whose mean reversion target depends on regime state, days to expiration, moneyness, and a market mood indicator, converts those paths into implied volatility paths  and a recombining binomial lattice prices American options from the resulting surface. Initializing variance at its mean reversion target for each strike expiration pair lets smile, skew, and term structure emerge without external calibration. We calibrate the shape function through a hierarchy spanning a parametric baseline, a globally shared neural surrogate, and a sector specific neural surrogate fit to a multi ticker, multi sector option ladder. A temporal holdout on a multi day capture isolated scheduled corporate events as the dominant source of test time generalization error, and calendar derived earnings distance and same sector peer coupling features recovered the anticipatory portion of that signal. We then apply the framework as a synthetic data generator on real near the money put and call contracts, forward simulating price paths, and recovering path conditional implied volatility, finite difference American Greeks, and terminal short premium profit and loss from one coherent simulation, and confirm cross ticker robustness by re running on a second underlying from a different sector and volatility regime. The framework is released as an open source Julia package.

Keywords : 

Abstract :生成现实的合成期权价格需要隐含波动率作为输入，但隐含波动率本身是从观察到的期权价格中得出的，这产生了一种循环依赖关系，限制了机器学习和风险分析应用程序的合成数据。我们通过一个管道打破了这种循环，在这个管道中，隐含波动率作为股票回报结构模型的输出而出现。跳跃隐马尔可夫模型产生具有现实风格化事实和交叉资产尾部依赖性的多资产价格路径。一个改进的赫斯顿方差过程，其均值回归目标取决于制度状态、到期天数、货币性和市场情绪指标，将这些路径转换为隐含波动率路径，并从结果表面重新组合二项式格对美国期权进行定价。在每个罢工到期对的均值回归目标处初始化方差，可以在没有外部校准的情况下出现微笑、偏斜和期限结构。我们通过一个层次结构来校准形状函数，该层次结构跨越参数基线、全局共享的神经代理和适合多股票、多部门期权阶梯的部门特定神经代理。对多日捕获的孤立计划公司事件的时间坚持是测试时间泛化误差的主要来源，日历衍生的收益距离和同行业同行耦合特征恢复了该信号的预期部分。然后，我们将该框架作为合成数据生成器应用于真实的近货币看跌和看涨合约、远期模拟价格路径、恢复路径条件隐含波动率、有限差分美式希腊和终端短期溢价损益，并通过在不同行业和波动率制度的第二个基础上重新运行来确认交叉股票的稳健性。该框架作为开源Julia包发布。

Keywords :