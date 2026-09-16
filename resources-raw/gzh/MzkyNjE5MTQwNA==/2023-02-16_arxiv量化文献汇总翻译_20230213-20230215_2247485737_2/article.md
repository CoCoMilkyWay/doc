# arxiv量化文献汇总翻译 20230213-20230215

Shame1ess 量化前沿速递 2023-02-16 08:30 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247485737&idx=2&sn=7da478b58b687885938fb33b613b1fa5&chksm=c38890b5038350af0d46b911c92a3dd2e5fc23704998b3bc45bfeb515b08652e4ffdcd57ab34#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247485737&idx=2&sn=7da478b58b687885938fb33b613b1fa5&chksm=c38890b5038350af0d46b911c92a3dd2e5fc23704998b3bc45bfeb515b08652e4ffdcd57ab34#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Parametric Differential Machine Learning for Pricing and Calibration

用于定价和校准的参数微分机器学习

\[2\] Analysis of optimal portfolios on finite and small time horizons for a  multi dimensional correlated stochastic volatility model

多维相关随机波动模型的有限和小时间范围最优投资组合分析

\[3\] Control of Emerging Market Target, Abnormal Stock Return

控制新兴市场目标，异常股票收益

\[4\] Ruin Probabilities for Risk Processes in Stochastic Networks

随机网络中风险过程的破产概率

\[5\] Set Asides in USDA Food Procurement Auctions

在美国农业部食品采购拍卖中树立榜样

\[6\] Long term option pricing with a lower reflecting barrier

反映障碍较低的长期期权定价

\[7\] A Tale of Two Currencies

两种货币的故事

\[8\] Decentralized Exchanges

去中心化交易所

\[9\] Modelling Illiquid Stocks Using Quantum Stochastic Calculus

用量子随机微积分模拟非流动股票

\[10\] Modelling Illiquid Stocks Using Quantum Stochastic Calculus

用量子随机微积分模拟非流动股票

\[11\] Some asymptotics for short maturity Asian options

短期亚洲期权的一些渐近性

\[12\] An Efficient Algorithm for Optimal Routing Through Constant Function  Market Makers

常函数做市商最优路由的一种有效算法

\[13\] GPU acceleration of the Seven League Scheme for large time step  simulations of stochastic differential equations

随机微分方程大时间步长模拟七联盟方案的GPU加速

### 

\[1\] Parametric Differential Machine Learning for Pricing and Calibration

标题 : 用于定价和校准的参数微分机器学习

作者 : Arun Kumar Polala, Bernhard Hientzsch , 类别 ： Computational Finance (q-fin.CP)

说明 : Comments: 45 pages

Abstract : Differential machine learning (DML) is a recently proposed technique that uses samplewise state derivatives to regularize least square fits to learn conditional expectations of functionals of stochastic processes as functions of state variables. Exploiting the derivative information leads to fewer samples than a vanilla ML approach for the same level of precision. This paper extends the methodology to parametric problems where the processes and functionals also depend on model and contract parameters, respectively. In addition, we propose adaptive parameter sampling to improve relative accuracy when the functionals have different magnitudes for different parameter sets. For calibration, we construct pricing surrogates for calibration instruments and optimize over them globally. We discuss strategies for robust calibration. We demonstrate the usefulness of our methodology on one factor Cheyette models with benchmark rate volatility specification with an extra stochastic volatility factor on (two curve) caplet prices at different strikes and maturities, first for parametric pricing, and then by calibrating to a given caplet volatility surface. To allow convenient and efficient simulation of processes and functionals and in particular the corresponding computation of samplewise derivatives, we propose to specify the processes and functionals in a low code way close to mathematical notation which is then used to generate efficient computation of the functionals and derivatives in TensorFlow.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[2\] Analysis of optimal portfolios on finite and small time horizons for a  multi dimensional correlated stochastic volatility model

标题 : 多维相关随机波动模型的有限和小时间范围最优投资组合分析

作者 : Minglian Lin, Indranil SenGupta , 类别 ： Mathematical Finance (q-fin.MF)

说明 : Comments: arXiv admin note: text overlap with arXiv:2104.06293

Abstract : In this paper, we consider the portfolio optimization problem in a financial market where the underlying stochastic volatility model is driven by n dimensional Brownian motions. At first, we derive a Hamilton Jacobi Bellman equation including the scaled covariances between the standard Brownian motions. We use an approximation method for the optimization of portfolios. With such approximation, the value function is analyzed using the first order terms of expansion of the utility function in the powers of time to the horizon. The error of this approximation is controlled using the second order terms of expansion of the utility function. It is also shown that the one dimensional version of this analysis corresponds to a known result in the literature. We also generate a close to optimal portfolio near the time to horizon using the first order approximation of the utility function. It is shown that the error is controlled by the square of the time to the horizon. Finally, we provide an approximation scheme to the value function for all times and generate a close to optimal portfolio.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[3\] Control of Emerging Market Target, Abnormal Stock Return

标题 : 控制新兴市场目标，异常股票收益

作者 : Quyen Van, Vy Tran , 类别 ： General Finance (q-fin.GN)

说明 : -

Abstract : Joining with the upward trend of Global Foreign direct investment and FDI in emerging economies and emerging Asian economies, FDI to Vietnam, especially M&As have increased significantly in both numbers and value of deals from 1995 to 2015...

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[4\] Ruin Probabilities for Risk Processes in Stochastic Networks

标题 : 随机网络中风险过程的破产概率

作者 : Hamed Amini, Zhongyuan Cao, Andreea Minca, Agnès Sulem , 类别 ： Probability (math.PR)

说明 : Comments: 31 pages

Abstract : We study multidimensional Cram  er Lundberg risk processes where agents, located on a large sparse network, receive losses form their neighbors. To reduce the dimensionality of the problem, we introduce classification of agents according to an arbitrary countable set of types. The ruin of any agent triggers losses for all of its neighbours. We consider the case when the loss arrival process induced by the ensemble of ruined agents follows a Poisson process with general intensity function that scales with the network size. When the size of the network goes to infinity, we provide explicit ruin probabilities at the end of the loss propagation process for agents of any type. These limiting probabilities depend, in addition to the agents  types and the network structure, on the loss distribution and the loss arrival process. For a more complex risk processes on open networks, when in addition to the internal networked risk processes the agents receive losses from external users, we provide bounds on ruin probabilities.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[5\] Set Asides in USDA Food Procurement Auctions

标题 : 在美国农业部食品采购拍卖中树立榜样

作者 : Ni Yan, WenTing Tao , 类别 ： General Economics (econ.GN)

说明 : -

Abstract : We study the partial and full set asides and their implication for changes in bidding behavior in first price sealed bid auctions in the context of United States Department of Agriculture (USDA) food procurement auctions. Using five years of bid data on different beef products, we implement weighted least squares regression models to show that partial set aside predicts decreases in both offer prices and winning prices among large and small business bidders. Full set aside predicts a small increase in offer prices and winning prices among small businesses. With these predictions, we infer that net profit of small businesses is unlikely to increase when set asides are present.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[6\] Long term option pricing with a lower reflecting barrier

标题 : 反映障碍较低的长期期权定价

作者 : R. Guy Thomas , 类别 ： Pricing of Securities (q-fin.PR)

说明 : Comments: Accepted for publication in Annals of Actuarial Science

Abstract : This paper considers the pricing of long term options on assets such as housing, where either government intervention or the economic nature of the asset is assumed to limit large falls in prices. The observed asset price is modelled by a geometric Brownian motion (the  notional price ) reflected at a lower barrier. The resulting observed price has standard dynamics but with localised intervention at the barrier, which allows arbitrage with interim losses  this is funded by the government s unlimited powers of intervention, and its exploitation is subject to credit constraints. Despite the lack of an equivalent martingale measure for the observed price, options on this price can be expressed as compound options on the arbitrage free notional price, to which standard risk neutral arguments can be applied. Because option deltas tend to zero when the observed price approaches the barrier, hedging with the observed price gives the same results as hedging with the notional price, and so exactly replicates option payoffs. Hedging schemes are not unique, with the cheapest scheme for any derivative being the one which best exploits the interventions at the barrier. The price of a put is clear  direct replication has a lower initial cost than synthetic replication, and the replication portfolio always has positive value. The price of a call is ambiguous  synthetic replication has a lower initial cost than direct replication, but the replication portfolio may give interim losses, and so the preferred replication strategy (and hence price) of a call may depend on what margin payments need to be made on these losses.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[7\] A Tale of Two Currencies

标题 : 两种货币的故事

作者 : Ravi Kashyap , 类别 ： General Economics (econ.GN)

说明 : -

Abstract : We discuss numerous justifications for why crypto currencies would be highly conducive for the smooth functioning of today s society. We provide several comparisons between cryptocurrencies issued by blockchain projects, crypto, and conventional government issued currencies, cash or fiat. We summarize seven fundamental innovations that would be required for participants to have greater confidence in decentralized finance (DeFi) and to obtain wealth appreciation coupled with better risk management. The conceptual ideas we discuss outline an approach to  1) Strengthened Security Blueprint  2) Rebalancing and Trade Execution Suited for Blockchain Nuances 3) Volatility and Variance Adjusted Weight Calculation 4) Accommodating Investor Preferences and Risk Parity Construction  5) Profit Sharing and Investor Protection  6) Concentration Risk Indicator and Performance Metrics  7) Multi chain expansion and Select Strategic Initiatives including the notion of a Decentralized Autonomous Organization (DAO). Incorporating these concepts into several projects would also facilitate the growth of the overall blockchain eco system so that this technology can, have wider mainstream adoption and, fulfill its potential in transforming all aspects of human interactions.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[8\] Decentralized Exchanges

标题 : 去中心化交易所

作者 : Tobias Bitterli, Fabian Sch r , 类别 ： General Finance (q-fin.GN)

说明 : -

Abstract : In this paper we analyze constant product market makers (CPMMs). We formalize the liquidity providers  profitability conditions and introduce a concept we call the profitability frontier in the xyk space. We study the effect of mint and burn fees on the profitability frontier, consider various pool types, and compile a large data set from all Uniswap V2 transactions. We use this data to further study our theoretical framework and the profitability conditions. We show how the profitability of liquidity provision is severely affected by the costs of mint and burn events relative to the portfolio size and the characteristics of the trading pair.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[9\] Modelling Illiquid Stocks Using Quantum Stochastic Calculus

标题 : 用量子随机微积分模拟非流动股票

作者 : Will Hicks , 类别 ： Mathematical Finance (q-fin.MF)

说明 : -

Abstract : Quantum Stochastic Calculus can be used as a means by which randomness can be introduced to observables acting on a Hilbert space. In this article we show how the mechanisms of Quantum Stochastic Calculus can be used to extend the classical Black Scholes framework by incorporating a breakdown in the liquidity of a traded asset. This is captured via the widening of the bid offer spread, and the impact on the nature of the resulting probability distribution is modelled in this work.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[10\] Modelling Illiquid Stocks Using Quantum Stochastic Calculus

标题 : 用量子随机微积分模拟非流动股票

作者 : Will Hicks , 类别 ： Mathematical Finance (q-fin.MF)

说明 : -

Abstract : This article investigates the Fokker Planck equations that arise from the application of quantum stochastic calculus to the modelling of illiquid financial markets, using asymptotic methods. We present a power series solution for quantum stochastic processes with a non zero conservation process. Whilst the series in question are in general divergent, we show they can be used to approximate solutions for longer time frames, and provide estimates for the relative error on the higher order terms.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[11\] Some asymptotics for short maturity Asian options

标题 : 短期亚洲期权的一些渐近性

作者 : Humayra Shoshi, Indranil SenGupta , 类别 ： Pricing of Securities (q-fin.PR)

说明 : Comments: arXiv admin note: text overlap with arXiv:1609.07559 by other authors

Abstract : Most of the existing methods for pricing Asian options are less efficient in the limit of small maturities and small volatilities. In this paper, we use the large deviations theory for the analysis of short maturity Asian options. We present a local volatility model for the underlying market that incorporates a jump term in addition to the drift and diffusion terms. We estimate the asymptotics for the out of the money, in the money, and at the money short maturity Asian call and put options. Under appropriate assumptions, we show that the asymptotics for out of the money Asian call and put options are governed by rare events. For the at the money Asian options, the result is more involved and in that case, we find the upper and lower bounds of the asymptotics of the Asian option price.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[12\] An Efficient Algorithm for Optimal Routing Through Constant Function  Market Makers

标题 : 常函数做市商最优路由的一种有效算法

作者 : Theo Diamandis, Max Resnick, Tarun Chitra, Guillermo Angeris , 类别 ： Optimization and Control (math.OC)

说明 : Comments: To be presented at Financial Cryptography 2023

Abstract : Constant function market makers (CFMMs) such as Uniswap have facilitated trillions of dollars of digital asset trades and have billions of dollars of liquidity. One natural question is how to optimally route trades across a network of CFMMs in order to ensure the largest possible utility (as specified by a user). We present an efficient algorithm, based on a decomposition method, to solve the problem of optimally executing an order across a network of decentralized exchanges. The decomposition method, as a side effect, makes it simple to incorporate more complicated CFMMs, or even include  aggregate CFMMs  (such as Uniswap v3), into the routing problem. Numerical results show significant performance improvements of this method, tested on realistic networks of CFMMs, when compared against an off the shelf commercial solver.

摘要翻译 : 加入知识星球“量化前沿速递”可获取

### 

\[13\] GPU acceleration of the Seven League Scheme for large time step  simulations of stochastic differential equations

标题 : 随机微分方程大时间步长模拟七联盟方案的GPU加速

作者 : Shuaiqiang Liu, Graziana Colonna, Lech A. Grzelak, Cornelis W. Oosterlee , 类别 ： Numerical Analysis (math.NA)

说明 : -

Abstract : Monte Carlo simulation is widely used to numerically solve stochastic differential equations. Although the method is flexible and easy to implement, it may be slow to converge. Moreover, an inaccurate solution will result when using large time steps. The Seven League scheme, a deep learning based numerical method, has been proposed to address these issues. This paper generalizes the scheme regarding parallel computing, particularly on Graphics Processing Units (GPUs), improving the computational speed.

摘要翻译 : 加入知识星球“量化前沿速递”可获取