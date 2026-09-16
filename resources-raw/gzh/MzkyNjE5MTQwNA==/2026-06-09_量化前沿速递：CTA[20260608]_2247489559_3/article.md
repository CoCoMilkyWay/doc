# 量化前沿速递：CTA\[20260608\]

shameless 量化前沿速递 2026-06-09 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489559&idx=3&sn=81c702a350aeb8fbe9a411436237c09c&chksm=c35c753a2b10557bb64ed6b4a3759a5e646c70f18c8dc40eb4a0b2b43b56f03bc2d3aba8831d#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489559&idx=3&sn=81c702a350aeb8fbe9a411436237c09c&chksm=c35c753a2b10557bb64ed6b4a3759a5e646c70f18c8dc40eb4a0b2b43b56f03bc2d3aba8831d#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Distributional Portfolio Optimization (DPO)

分布式投资组合优化（DPO）

来源:ARXIV\_20260601

\[2\] Option Pricing under Stochastic Volatility and Jumps

随机波动和跳跃下的期权定价

来源:ARXIV\_20260601

\[3\] Quality Adjusted Hit Ratio Targeting in Corporate Bond Market Making

公司债券做市中的质量调整命中率目标

来源:ARXIV\_20260601

\[4\] Inspectable Neural Markov Models for Non Stationary Time Series

非平稳时间序列的可检验神经马尔可夫模型

来源:ARXIV\_20260601

\[5\] Machine Learning Based Bitcoin Trading Under Transaction Costs

交易成本下基于机器学习的比特币交易

来源:ARXIV\_20260602

\[6\] Multiplicative Langevin Process for Volatilities Produces Observed Q Variance Regularities

波动的乘法朗之万过程产生观测到的Q方差规律

来源:ARXIV\_20260602

\[7\] A Formally Verified Library of Mathematical Finance in Lean 4

精益4中经过形式验证的数学金融库

来源:ARXIV\_20260602

\[8\] Avellaneda Stoikov and Cartea Jaimungal as One Framework

Avellaneda Stoikov和Cartea Jaimungal作为一个框架

来源:ARXIV\_20260602

\[9\] VIX options in Bergomi models

Bergomi车型中的VIX选项

来源:ARXIV\_20260602

\[10\] Endogenous Fertility Waves and the Dynamics of Utility in an Overlapping Generations Model

内生生育波与代际重叠模型中的效用动力学

来源:ARXIV\_20260602

\[11\] A Per Component Diagnostic Protocol for Neural HJB PIDE Solvers under Control Dependent L vy Jumps

基于控制相关L维跳跃的神经HJB PIDE解算器的每分量诊断协议

来源:ARXIV\_20260602

\[12\] Infinite Horizon Optimal Consumption

无限视界最优消费

来源:ARXIV\_20260603

\[13\] Portfolio Choice with Competing Precautionary and Accumulation Goals

具有竞争性预防和积累目标的投资组合选择

来源:ARXIV\_20260603

\[14\] Hybrid News Sentiment Engine

混合新闻情感引擎

来源:ARXIV\_20260603

\[15\] Trading Frictions in Dynamic Cap and Trade Markets

动态总量管制与交易市场中的交易摩擦

来源:ARXIV\_20260603

\[16\] A new decomposition approach to modeling financial returns

一种新的财务回报建模分解方法

来源:ARXIV\_20260604

\[17\] Polymarket v1 Database

Polymarket v1数据库

来源:ARXIV\_20260604

\[18\] Fairness and Strategy Proofness in Automated Market Makers

自动化做市商的公平性和策略证明

来源:ARXIV\_20260604

### 

\[1\] Distributional Portfolio Optimization (DPO)

标题:分布式投资组合优化（DPO）

作者:Miquel Noguer i Alonso

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30464

Abstract : Classical portfolio optimization treats expected returns, covariances, and allocations as deterministic. Modern practice replaces at least one by a distribution  a posterior over parameters, a law of future returns, a stochastic allocation policy, or a distributional robustness set. We call distributional portfolio optimization (DPO) the unified framework in which weights, returns, and parameters are all modeled as probability measures, organized around the joint coupling Gamma theta(dw,dr) and its marginal triple (W,R,P). The contribution is synthetic and structural  we organize Bayesian, robust, chance constrained, stochastic allocation, and distributional reinforcement learning portfolio methods through this coupling and prove boundary results connecting them, including a portfolio specialization of Wasserstein CVaR duality, a static no randomization theorem, a Bayesian credible radius calibration of Wasserstein DRO, a Gaussian isotropic second order conservatism bound, a conditional two sided rate W 1   Theta(n   (1 alpha) 2 ) governed by the local boundary Holder exponent alpha in  0,1 , and a risk shifted distributional Bellman contraction. A controlled experiment shows that across factor models at K in  10,25,50 , the credible radius rule lands within 3 7 bp of the oracle out of sample tail risk and beats a 24 month validation tuned radius while spending no validation data. On a K 25 DJIA backtest, equal weight, no view Black Litterman, and Ledoit Wolf shrinkage attain higher Sharpe than every distributional method  the operational claim is therefore confined to calibration without validation and turnover, not raw return dominance.

Keywords : 

Abstract :经典投资组合优化将预期回报、协方差和分配视为确定性的。现代实践至少用分布、参数后验、未来回报定律、随机分配策略或分布鲁棒性集取代了一个。我们称分布投资组合优化（DPO）为一个统一的框架，其中权重、回报和参数都被建模为概率度量，围绕联合耦合的Gamma theta（dw，dr）及其边际三元组（W，R，P）进行组织。贡献是综合的和结构化的。我们通过这种耦合组织了贝叶斯、稳健、机会约束、随机分配和分布强化学习投资组合方法，并证明了将它们连接起来的边界结果，包括Wasserstein-CVaR对偶的投资组合特化、静态无随机化定理、Wasserstein-DRO的贝叶斯可信半径校准、高斯各向同性二阶保守界、由0,1中的局部边界Holder指数alpha控制的条件双侧率W 1 Theta（n（1 alpha）2）和风险转移分布Bellman收缩。对照实验表明，在10、25、50的K因子模型中，可信半径规则落在样本外尾部风险的3.7 bp以内，在不花费验证数据的情况下，超过了24个月的验证调整半径。在K 25道琼斯工业平均指数回溯测试中，同等权重、无视野的Black Litterman和Ledoit-Wolf收缩率比每种分配方法都获得了更高的Sharpe，因此操作声明仅限于校准，没有验证和周转，而不是原始回报主导。

Keywords :

### 

\[2\] Option Pricing under Stochastic Volatility and Jumps

标题:随机波动和跳跃下的期权定价

作者:Abigail Anokyewaa Mensah, Ayush Jha, Hongwei Mei, Rui Wang, Svetlozar T. Rachev, Frank J. Fabozzi

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30562

Abstract : We develop a partial integro differential equation (PIDE) framework for option pricing under joint stochastic volatility and jump dynamics, and evaluate its empirical content using the S&P500 index option contracts across three maturities. The framework is derived from the infinitesimal generator of an affine L vy type process and implemented via finite difference discretization with FFT based treatment of the nonlocal jump operator. Calibration via GMM reveals that stochastic volatility accounts for the dominant share of pricing improvement, where relative to Black Scholes, the Heston specification reduces implied volatility RMSE by 39 . Jump augmentation via either Merton or CGMY specifications yields marginal improvements concentrated at short maturities and in the deep out of the money region. The calibrated CGMY activity index supports a compound Poisson structure, consistent with high frequency evidence on S&P500 index returns.

Keywords : 

Abstract :我们开发了一个用于联合随机波动和跳跃动力学下期权定价的偏积分微分方程（PIDE）框架，并使用三种到期日的标普500指数期权合约对其实证内容进行了评估。该框架源自仿射L vy型过程的无穷小生成器，并通过有限差分离散化和基于FFT的非局部跳跃算子处理来实现。通过GMM进行校准表明，随机波动率在定价改进中占主导地位，相对于Black-Scholes，赫斯顿规范将隐含波动率RMSE降低了39。通过默顿或CGMY规范进行跳跃式增长，可以产生边际改善，主要集中在短期和深度货币区。校准后的CGMY活动指数支持复合泊松结构，与标普500指数回报的高频证据一致。

Keywords :

### 

\[3\] Quality Adjusted Hit Ratio Targeting in Corporate Bond Market Making

标题:公司债券做市中的质量调整命中率目标

作者:Bouna Niang

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30643

Abstract : Hit ratio is a common service metric for electronic corporate bond market making, but raw hit ratio targets can be economically misleading when client flow has heterogeneous adverse selection content. This paper extends a stochastic control framework for OTC bond RFQ market making with hit ratio constraints by replacing raw hit ratio with a residual quality adjusted hit ratio. The key modelling distinction is that adverse post trade markouts are first decomposed into observable credit factors, carry rolldown, issuer relative value effects, index or ETF demand effects, and residual adverse selection. Only the residual component is treated as client flow toxicity. The resulting control problem remains tractable  after dualizing the quality hit ratio penalty, the HJB retains separable Hamiltonians, and the dual variable is the solution of an exact one dimensional nonlinear fixed point for each targeted tier. Under a quadratic value function approximation, optimal quotes decompose into a riskless spread, inventory skew, credit alpha skew, residual toxicity charge, and quality hit ratio subsidy. Synthetic multi bond simulations with nonlinear dual solves illustrate that raw hit ratio targeting can subsidize residual toxic flow, while residual quality targeting reallocates service toward low residual toxicity flow and improves the attained service economics frontier. A final reduced form extension studies inventory recycling value through risk aware style aligned client flow warehousing. Sweep or portfolio trade opportunities fill randomly, and participation is sized using the same quadratic value approximation as the RFQ quoting problem. A passive index demand experiment is reported in the appendix as a special case of forecastable client flow. The numerical evidence is synthetic and mechanism oriented  no proprietary RFQ data are used.

Keywords : 

Abstract :命中率是电子公司债券做市的常用服务指标，但当客户流具有异质性逆向选择内容时，原始命中率目标可能会在经济上产生误导。本文通过用剩余质量调整后的命中率代替原始命中率，扩展了具有命中率约束的场外债券询价做市的随机控制框架。关键的建模区别在于，不利的交易后加价首先被分解为可观察的信用因素、结转滚降、发行人相对价值效应、指数或ETF需求效应以及剩余的不利选择。只有残留成分被视为客户端流毒性。在将质量命中率惩罚二元化后，由此产生的控制问题仍然可以处理，HJB保留了可分离的哈密顿量，对偶变量是每个目标层的精确一维非线性不动点的解。在二次值函数近似下，最优报价分解为无风险价差、库存偏差、信用阿尔法偏差、剩余毒性费用和质量命中率补贴。具有非线性对偶求解的合成多键模拟表明，原始命中率目标可以补贴剩余毒性流，而剩余质量目标可以将服务重新分配到低剩余毒性流中，并提高所获得的服务经济前沿。最后一个简化表单扩展通过风险意识风格一致的客户流仓库研究库存回收价值。随机填充扫描或投资组合交易机会，并使用与RFQ报价问题相同的二次值近似来确定参与度。附录中报告了一个被动指数需求实验，作为可预测客户流的特例。数值证据是合成的，面向机制的，没有使用专有的RFQ数据。

Keywords :

### 

\[4\] Inspectable Neural Markov Models for Non Stationary Time Series

标题:非平稳时间序列的可检验神经马尔可夫模型

作者:Jan Rovirosa, Jesse Schmolze

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30943

Abstract : Modeling non stationary stochastic systems requires balancing the representational capacity of deep learning with the structural transparency of classical probabilistic models. Markov transition matrices provide such a framework, but traditional frequency based estimation collapses at high resolutions due to data sparsity. We propose a hybrid approach that parameterizes the manifold of stochastic matrices through a neural network, enabling estimation of time inhomogeneous Markov chains in sparse data regimes, and use financial markets as a testbed to investigate the Markov state variable as a critical inductive bias. We show that conditioning on realized volatility produces a more internally consistent Markovian structure than return based states, achieving a  5.6    reduction in Chapman Kolmogorov discrepancy and superior held out likelihood in 9 of 10 assets. Unlike black box sequence models, our approach generates explicit matrices amenable to direct geometric analysis, surfacing structural findings such as the universal homogenization of transition probabilities under high volatility regimes.

Keywords : 

Abstract :对非平稳随机系统进行建模需要平衡深度学习的表征能力与经典概率模型的结构透明度。马尔可夫转移矩阵提供了这样一个框架，但由于数据稀疏，传统的基于频率的估计在高分辨率下会崩溃。我们提出了一种混合方法，通过神经网络对随机矩阵的流形进行参数化，从而能够在稀疏数据状态下估计时间不均匀的马尔可夫链，并使用金融市场作为测试平台来研究马尔可夫状态变量作为临界归纳偏差。我们发现，与基于回报的状态相比，基于已实现波动率的条件化产生了更内部一致的马尔可夫结构，查普曼-科尔莫戈罗夫差异降低了5.6，10种资产中有9种具有更高的坚持可能性。与黑盒序列模型不同，我们的方法生成了易于直接几何分析的显式矩阵，揭示了结构发现，如高波动率下转移概率的普遍均匀化。

Keywords :

### 

\[5\] Machine Learning Based Bitcoin Trading Under Transaction Costs

标题:交易成本下基于机器学习的比特币交易

作者:Andrei Bysik, Robert Ślepaczuk

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.00060

Abstract : This paper investigates whether machine learning forecasts of hourly BTC USDT returns can be converted into economically meaningful trading performance after transaction costs. Using approximately 70,000 hourly observations from 2018 2026, XGBoost, LSTM, and iTransformer are evaluated in a 27 fold walk forward protocol. All three models produce positive gross trading performance in selected configurations, but naive sign based strategies fail once transaction costs of ten basis points are imposed. A cost aware execution filter, which prevents trades only when the forecast magnitude exceeds a transaction cost based threshold, sharply reduces turnover and restores profitability in selected configurations. The strongest long only XGBoost strategy produces annualised returns above 65  with a Sharpe ratio above one. Additional tests show that technical indicators improve performance in selected cases, EGARCH derived features do not provide uniformly robust gains, and XGBoost is descriptively stronger than the neural alternatives, although bootstrap evidence does not support formal statistical dominance. Loss function and model selection effects are secondary and statistically fragile. The results show that the main obstacle in hourly cryptocurrency trading is not only weak predictability, but also the way forecasts are converted into trades.

Keywords : 

Abstract :本文研究了机器学习对BTC-USDT每小时回报的预测是否可以在扣除交易成本后转化为具有经济意义的交易绩效。使用2018年至2026年的约70000小时观测数据，XGBoost、LSTM和iTransformer在27倍的前向协议中进行了评估。这三种模型在选定的配置中都产生了积极的总交易绩效，但一旦施加了10个基点的交易成本，基于符号的天真策略就会失败。一个具有成本意识的执行过滤器，仅在预测幅度超过基于交易成本的阈值时才阻止交易，在选定的配置中大幅降低营业额并恢复盈利能力。最强的只做多XGBoost策略产生的年化回报率超过65，夏普比率超过1。其他测试表明，技术指标在特定情况下提高了性能，EGARCH衍生的特征不能提供一致的鲁棒增益，XGBoost在描述性上比神经替代方案更强，尽管引导证据不支持正式的统计优势。损失函数和模型选择效应是次要的，在统计上很脆弱。结果表明，每小时加密货币交易的主要障碍不仅是可预测性弱，还有预测转化为交易的方式。

Keywords :

### 

\[6\] Multiplicative Langevin Process for Volatilities Produces Observed Q Variance Regularities

标题:波动的乘法朗之万过程产生观测到的Q方差规律

作者:William H. Press, Alex Dannenberg

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.00800

Abstract : Q variance (so called) posits a statistical relationship   mathbf E ( sigma 2   z)    sigma 0 2    tfrac 1  2 z 2  between an asset s volatility   sigma 2 , as observed in a time interval  T , and its (suitably scaled) return  z  in the same interval. We here show that this relationship is   em exactly equivalent  to to positing an Inverse Gamma probability distribution for   sigma 2  itself. We then show that such a distribution is exactly generated by a multiplicative Langevin process with an arbitrary, settable coherence time   tau c , so that very nearly the same Q variance relationship will hold for all  T  ll  tau c .

Keywords : 

Abstract :Q方差（所谓的）在时间间隔T中观察到的资产波动率σ2与其在相同间隔中的（适当缩放的）回报z之间建立了统计关系mathbf E（σ2 z）σ0 2 tfrac 1 2 z 2。我们在这里证明，这种关系完全等价于为西格玛2本身设定一个逆伽马概率分布。然后，我们证明了这种分布是由具有任意可设置相干时间τc的乘法朗之万过程精确生成的，因此对于所有τc，几乎相同的Q方差关系都成立。

Keywords :

### 

\[7\] A Formally Verified Library of Mathematical Finance in Lean 4

标题:精益4中经过形式验证的数学金融库

作者:Raphael Coelho

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.01356

Abstract : We describe a library of mathematical finance built in the Lean 4 proof assistant, on top of Mathlib and the BrownianMotion package. It is broad  more than two hundred sorry free theorems across eleven areas, from the measure theoretic foundations of continuous time stochastic calculus through derivative pricing to applied risk, portfolio, and fixed income theory, and, to our knowledge, the most comprehensive machine checked development of mathematical finance to date. Breadth is the setting, not the point. Two things make it more than a catalogue. It reaches into the continuous theory far enough to construct the L2 It  integral as a bounded linear isometry and to derive, rather than assume, the risk neutral pricing measure. And it audits its own faithfulness  every result is classified by how its Lean statement relates to the mathematics it claims, and a build enforced gate pins the axioms each proof actually uses, so a reader can see precisely what has been proved and what has only been proved under added hypotheses. We close with a candid finding  a formal base over classical financial mathematics yields certified unification of known results rather than new financial theory. The contribution is therefore methodological and infrastructural, reusable verified foundations for mathematical finance, together with the faithfulness audit.

Keywords : 

Abstract :我们描述了在Mathlib和BrownianMotion软件包之上，在精益4证明助手中构建的数学金融库。它涵盖了11个领域的200多个无条件定理，从连续时间随机微积分的度量理论基础到衍生品定价，再到应用风险、投资组合和固定收益理论，以及据我们所知，迄今为止最全面的数学金融机器检查发展。广度是背景，而不是重点。有两件事使它不仅仅是一个目录。它深入到连续理论中，将L2-It积分构造为有界线性等距，并推导而不是假设风险中性定价度量。它审核自己的可信度——每个结果都是根据其精益陈述与它所声称的数学之间的关系进行分类的，一个强制构建的门钉住了每个证明实际使用的公理，这样读者就可以准确地看到已经证明了什么，以及只有在附加假设下才证明了什么。最后，我们坦率地发现，经典金融数学的形式基础产生了已知结果的公认统一，而不是新的金融理论。因此，贡献在于方法论和基础设施，可重复使用的数学金融验证基础，以及忠诚度审计。

Keywords :

### 

\[8\] Avellaneda Stoikov and Cartea Jaimungal as One Framework

标题:Avellaneda Stoikov和Cartea Jaimungal作为一个框架

作者:Frank M. V. Feys

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.01477

Abstract : In inventory market making, the running penalty coefficient   phi  of the Cartea Jaimungal framework and the risk aversion parameter   gamma  of the Avellaneda Stoikov framework are typically treated as independent free parameters, calibrated separately. We show that they are in fact not independent. A small set of axioms on the market maker s dynamic preference functional, namely cash additivity, normalization, concavity, strong dynamic consistency, and law invariance, forces the preference functional to be the entropic certainty equivalent on liquidation adjusted terminal wealth, parametrized by a single positive scalar   gamma . The Avellaneda Stoikov framework is the unique representative of this axiom class. The Cartea Jaimungal framework is its second order Taylor expansion in inventory magnitude, with the running coefficient forced to   phi    gamma sigma 2 2  and (under a mild regularity condition on the liquidation cost) the terminal coefficient forced to   alpha    frac 1  2 L  (0) . The two frameworks, typically presented as competing alternatives with the choice between them driven by tractability, are different manifestations of a single underlying object. The forced relation is invertible,   gamma   2 phi  sigma 2 , giving a consistency cross check on independently calibrated desk parameters.

Keywords : 

Abstract :在库存做市中，Cartea-Jaimungal框架的运行惩罚系数phi和Avellaneda-Stoikov框架的风险规避参数gamma通常被视为独立的自由参数，分别进行校准。我们证明他们实际上并不独立。做市商动态偏好泛函上的一组小公理，即现金可加性、归一化、凹性、强动态一致性和定律不变性，迫使偏好泛函成为清算调整后的终端财富的熵确定性等价物，由单个正标量γ参数化。Avellaneda-Stoikov框架是这一公理类的独特代表。Cartea-Jaimungal框架是其库存量的二阶泰勒展开，运行系数强制为phi-gamma-sigma 2 2，（在清算成本的温和规律性条件下）终端系数强制为αfrac 1 2 L（0）。这两个框架通常表现为相互竞争的替代方案，由可处理性驱动，是单个底层对象的不同表现形式。强制关系是可逆的，γ2 phi sigma 2，对独立校准的桌面参数进行一致性交叉检查。

Keywords :

### 

\[9\] VIX options in Bergomi models

标题:Bergomi车型中的VIX选项

作者:Desen Guo, Dan Pirjol, Lingjiong Zhu

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.02336

Abstract : We present a study of the leading order asymptotics for VIX option prices in Bergomi models in the short maturity and small volatility of volatility regimes. Both out of the money (OTM) and at the money (ATM) asymptotics are considered for one factor, two factor Bergomi and  N  factor models. The leading order asymptotics are obtained in closed form, which are translated into predictions for the small maturity asymptotics of the VIX implied volatility. Numerical illustrations are provided to illustrate the efficiency of the closed form asymptotic formulas.

Keywords : 

Abstract :我们研究了Bergomi模型中VIX期权价格在短期和小波动性波动制度下的领先阶渐近性。对于单因素、双因素Bergomi和N因素模型，考虑了货币外（OTM）和货币内（ATM）渐近性。以封闭形式获得前导阶渐近线，并将其转化为对VIX隐含波动率小到期渐近线的预测。提供了数值说明来说明闭式渐近公式的效率。

Keywords :

### 

\[10\] Endogenous Fertility Waves and the Dynamics of Utility in an Overlapping Generations Model

标题:内生生育波与代际重叠模型中的效用动力学

作者:Wolfgang Kuhle

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.02362

Abstract : This paper investigates the conditions under which the Easterlin hypothesis holds within a neoclassical overlapping generations model with endogenous capital accumulation, wages, interest rates, and fertility. We develop a tractable analytical framework that maps economic transitions into utility space via a continuously differentiable first order difference equation for cohort lifetime utilities. This reformulation allows for a transparent normative evaluation of non steady state paths without requiring explicit solutions to the underlying nonlinear system. Within this framework, we show that when fertility cycles emerge and children are normal goods, the utility of small cohorts strictly exceeds that of large cohorts. Crucially, this cohort welfare asymmetry is driven by fertility preferences and is independent of the economy s position relative to the golden rule.

Keywords : 

Abstract :本文研究了伊斯特林假说在具有内生资本积累、工资、利率和生育率的新古典重叠世代模型中成立的条件。我们开发了一个易于处理的分析框架，通过队列寿命效用的连续可微一阶差分方程将经济转型映射到效用空间。这种重新表述允许对非稳态路径进行透明的规范评估，而不需要对潜在的非线性系统进行显式求解。在这个框架内，我们表明，当生育周期出现并且儿童是正常商品时，小队列的效用严格超过大队列。至关重要的是，这种群体福利不对称是由生育偏好驱动的，与经济相对于黄金法则的地位无关。

Keywords :

### 

\[11\] A Per Component Diagnostic Protocol for Neural HJB PIDE Solvers under Control Dependent L vy Jumps

标题:基于控制相关L维跳跃的神经HJB PIDE解算器的每分量诊断协议

作者:R. Drissi

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.01122

Abstract : We propose a five step diagnostic protocol for residual trained neural HJB PIDE solvers with control dependent L vy jumps, targeting a general failure mode of neural PDE methods  a learned solution can match headline scalar diagnostics while miscomputing an operator inside its training loss. The protocol pairs each neural solve with at least one from scratch independent reference, decomposes the Hamiltonian into drift, diffusion, compensator, and nonlocal integral components across a u grid, and compares the value function and its low order derivatives over a (t,x) grid before any argmax comparison. Applied to a standard CRRA Merton Variance Gamma benchmark, it isolates a missing 1 2 mixture factor in the neural method s importance proposal density that scaled the nonlocal integral by exactly half   a textbook signature of a constant proposal scale error, invisible to longer training, grid refinement, and truncation sweeps. With the bug corrected, four references   two finite difference solvers with disjoint discretizations, the neural solver, and a semi analytic scalar baseline obtained from CRRA homogeneity   agree on the optimal control to within  2 . The constant coefficient CRRA benchmark collapses by homogeneity to a scalar maximization, so the scalar baseline is the efficient method here  the contribution is the protocol, applicable in principle to non homogeneous and higher dimensional settings where neural HJB PIDE solvers are genuinely needed. The episode is a concrete instance of a broader neural PDE verification failure  pointwise agreement of a learned value or control can coexist with a systematically wrong nonlocal operator, so per component and surface level checks are needed before trusting the argmax policy.

Keywords : 

Abstract :我们提出了一种五步诊断协议，用于具有控制相关L vy跳跃的残差训练神经HJB PIDE求解器，针对神经PDE方法的一般故障模式，学习到的解决方案可以匹配标题标量诊断，同时在训练损失内错误计算运算符。该协议将每个神经解与至少一个从头开始的独立参考配对，将哈密顿量分解为u网格上的漂移、扩散、补偿器和非局部积分分量，并在任何argmax比较之前比较（t，x）网格上的值函数及其低阶导数。应用于标准CRRA Merton Variance Gamma基准，它分离出神经方法重要性建议密度中缺失的1-2混合因子，该因子将非局部积分缩放了常数建议缩放误差的教科书签名的一半，这对较长的训练、网格细化和截断扫描是不可见的。在纠正了错误后，四个参考——两个具有不相交离散化的有限差分求解器、神经求解器和从CRRA同质性获得的半解析标量基线——在2以内的最优控制上达成一致。常数系数CRRA基准因同质性而崩溃为标量最大化，因此标量基线是这里的有效方法——贡献是协议，原则上适用于真正需要神经HJB PIDE求解器的非同质性和高维设置。该事件是一个更广泛的神经PDE验证失败的具体实例，学习值或控制的逐点一致性可能与系统错误的非局部算子共存，因此在信任argmax策略之前需要进行每个组件和表面级别的检查。

Keywords :

### 

\[12\] Infinite Horizon Optimal Consumption

标题:无限视界最优消费

作者:Erhan Bayraktar, Emmet Lawless

来源:ARXIV\_20260603

链接:https://arxiv.org/pdf/2606.02945

Abstract : We study an infinite horizon optimal consumption investment problem for an investor with Epstein Zin stochastic differential utility with stochastic investment opportunities in an incomplete market. Risk aversion and intertemporal substitution are separated, and we work in the regime   theta in(0,1) , where there exists a unique generalised utility process for arbitrary non negative progressively measurable consumption streams. Our main contribution is a variational characterisation of the value function. We show that the value function is the unique minimiser of a functional whose Euler Lagrange equation coincides with the Hamilton Jacobi Bellman equation. Although the functional may be non convex, the direct method yields existence, and we prove every minimiser is strictly positive, bounded, and classical. A verification theorem identifies any minimiser with the value function and gives feedback representations for optimal consumption and investment policies. The proof combines a change of measure to the myopic probability with uniqueness results for Epstein Zin BSDEs and a perturbation argument for optimality. Examples with stochastic volatility, Gaussian excess returns, and fat tailed excess returns illustrate the scope of the framework and its implications for intertemporal hedging.

Keywords : 

Abstract :我们研究了不完全市场中具有随机投资机会的Epstein-Zin随机微分效用的投资者的无限期最优消费投资问题。风险规避和跨期替代是分开的，我们在（0,1）中的theta制度下工作，其中对于任意非负的可逐步测量的消费流存在一个独特的广义效用过程。我们的主要贡献是价值函数的变分特征。我们证明了值函数是欧拉-拉格朗日方程与哈密顿-雅可比-贝尔曼方程重合的函数的唯一极小值。尽管泛函可能是非凸的，但直接方法产生了存在性，我们证明了每个最小化器都是严格正的、有界的和经典的。验证定理通过值函数识别任何最小化器，并给出最优消费和投资策略的反馈表示。该证明结合了对近视概率的度量变化、Epstein-Zin BSDE的唯一性结果和最优性的扰动论证。随机波动率、高斯超额收益和肥尾超额收益的例子说明了该框架的范围及其对跨期套期保值的影响。

Keywords :

### 

\[13\] Portfolio Choice with Competing Precautionary and Accumulation Goals

标题:具有竞争性预防和积累目标的投资组合选择

作者:Steven Campbell, Agostino Capponi, Ananya Parashar

来源:ARXIV\_20260603

链接:https://arxiv.org/pdf/2606.03158

Abstract : We study optimal portfolio choice for a household simultaneously managing a random deadline goal, such as a medical emergency or job loss, and a fixed deadline goal such as retirement or college tuition. Under a forced funding rule, in which each goal is paid in full whenever affordable, the household maximizes a weighted sum of the probabilities of fully funding both goals in a Black  Scholes market. We identify two novel effects absent from single goal models  a growth crowding out effect, in which precautionary saving for the random goal distorts investment toward the fixed goal, and a deadline pressure effect, in which a compressed saving horizon forces excess risk taking. A striking implication is that the value function need not be monotone in wealth  a household just above the random goal threshold is forced to pay it when the shock arrives, depleting its wealth for the fixed goal, and ends up worse off than a slightly poorer household that missed the random goal but kept its wealth intact. This non monotonicity is absent from all single goal benchmarks and arises purely from the interaction between the two goal types under forced funding. We further study an optional funding variant in which the household may decline the fixed deadline goal at time  T  rather than being required to fund it. We characterize the ex ante option value, i.e., the full time  0  value of this flexibility and the terminal option value, i.e., its value at the funding decision node. We find that both options are most valuable at intermediate wealth levels where paying the fixed deadline goal would substantially reduce the continuation value of the random deadline problem.

Keywords : 

Abstract :我们研究了一个家庭的最佳投资组合选择，该家庭同时管理一个随机的截止日期目标，如医疗紧急情况或失业，以及一个固定的截止日期的目标，如退休或大学学费。在强制融资规则下，只要负担得起，每个目标都会全额支付，在布莱克-斯科尔斯市场上，家庭会最大化两个目标完全融资的概率的加权和。我们发现了单目标模型中没有的两个新效应——增长挤出效应，其中为随机目标进行的预防性储蓄会扭曲对固定目标的投资，以及截止日期压力效应，其中压缩的储蓄期限会迫使过度冒险。一个引人注目的含义是，价值函数在财富方面不一定是单调的——当冲击到来时，刚好高于随机目标阈值的家庭被迫支付这笔钱，耗尽其用于固定目标的财富，最终比错过随机目标但保持财富完整的稍微贫穷的家庭更糟糕。这种非单调性在所有单一目标基准中都不存在，纯粹源于强制资助下两种目标类型之间的相互作用。我们进一步研究了一种可选的融资变体，在这种变体中，家庭可以在时间T拒绝固定的截止日期目标，而不是被要求为其提供资金。我们描述了事前期权价值，即这种灵活性的全职0值，以及终期期权价值，也就是它在融资决策节点的价值。我们发现，在中等财富水平下，这两种选择都是最有价值的，在这种情况下，支付固定的截止日期目标将大大降低随机截止日期问题的持续价值。

Keywords :

### 

\[14\] Hybrid News Sentiment Engine

标题:混合新闻情感引擎

作者:Andreas Aigner

来源:ARXIV\_20260603

链接:https://arxiv.org/pdf/2606.03457

Abstract : We present a hybrid news sentiment engine that continuously learns marketsentiment from paired news headlines and concurrent asset price snapshotswithout requiring any neural network training or GPU compute. The system usesa three way ensemble combining (1) a financial domain lexicon (FinBERT stylekeyword scoring), (2) an adaptive statistical TF IDF cluster learner thatorganizes headlines into semantic neighborhoods and tracks their averagerealized price reactions, and (3) an auto calibrating weighting mechanismthat adjusts ensemble contributions based on each signal s historicalcorrelation with actual price movements. The engine runs on a 3 hour pollingcycle from the Tradeflags NewsFeed API, which provides 22 price snapshotfields per news item spanning equity indices (ES, NQ, SPY, DJIA, NDX, IWM),commodities (CL), and cryptocurrencies (BTC, ETH). All processing occurs atsub second latency on a CPU only server at effectively zero marginal cost peranalytic cycle. We compare our approach against established methods   FinBERT, GPT based scoring, VADER, and commercial sentiment APIs    acrossdimensions of cost, latency, accuracy, and adaptability. Our statisticalcluster learner, which adapts to changing market regimes without retraining,represents a novel contribution not found in existing sentiment systems.

Keywords : 

Abstract :我们提出了一种混合新闻情绪引擎，它可以从成对的新闻标题和并发的资产价格快照中不断学习市场情绪，而不需要任何神经网络训练或GPU计算。该系统使用一种三向集成，结合了（1）金融领域词典（FinBERT风格单词评分），（2）自适应统计TF IDF聚类学习器，将标题组织成语义邻域并跟踪其平均实现的价格反应，以及（3）自动校准加权机制，根据每个信号与实际价格变动的历史相关性调整集成贡献。该引擎在Tradeflags NewsFeed API的3小时轮询周期内运行，该API为每个新闻项目提供22个价格快照字段，涵盖股票指数（ES、NQ、SPY、DJIA、NDX、IWM）、大宗商品（CL）和加密货币（BTC、ETH）。所有处理都在仅使用CPU的服务器上以亚秒的延迟进行，有效地实现了零边际成本的分析周期。我们将我们的方法与FinBERT、基于GPT的评分、VADER和商业情绪API在成本、延迟、准确性和适应性方面进行了比较。我们的统计聚类学习器无需再培训即可适应不断变化的市场制度，这代表了现有情绪系统中没有的新贡献。

Keywords :

### 

\[15\] Trading Frictions in Dynamic Cap and Trade Markets

标题:动态总量管制与交易市场中的交易摩擦

作者:Nicola Borri, Yukun Liu, Aleh Tsyvinski, Xi Wu

来源:ARXIV\_20260603

链接:https://arxiv.org/pdf/2606.03767

Abstract : We develop a dynamic stochastic model of markets with an externality and multiple trading frictions, and cap and trade as the leading application. Slow participation, limited intermediation, and heterogeneous information interact in equilibrium  agents choose costly market access, access determines residual compliance demand, intermediary constraints translate residual demand into a surrender month premium, and the premium feeds back into access incentives. These interactions shape how effectively the market corrects the externality. We characterize access choices in closed form, prove that the equilibrium premium is unique, and show that endogenous access dampens the response to each friction in isolation, while the interaction of multiple frictions is non additive and can amplify the price response. We quantify the model using 2.7 million EU ETS registry transactions and compliance records from 2005 2021. About 40  of operators do not trade annually, purchases concentrate in April when returns are systematically high, and operator flow predicts future returns.

Keywords : 

Abstract :我们开发了一个具有外部性和多重交易摩擦的市场动态随机模型，并以限额与交易为主要应用。缓慢的参与、有限的中介和异构的信息在均衡中相互作用——代理人选择昂贵的市场准入，准入决定剩余的合规需求，中介约束将剩余需求转化为投降月溢价，溢价反馈为准入激励。这些相互作用决定了市场如何有效地纠正外部性。我们以封闭形式描述了准入选择，证明了均衡溢价是唯一的，并表明内生准入孤立地抑制了对每种摩擦的反应，而多重摩擦的相互作用是非加性的，可以放大价格反应。我们使用2005年至2021年间270万笔欧盟ETS注册交易和合规记录对模型进行了量化。大约有40家运营商每年不进行交易，购买集中在4月份，此时回报率通常很高，运营商流量预测未来的回报。

Keywords :

### 

\[16\] A new decomposition approach to modeling financial returns

标题:一种新的财务回报建模分解方法

作者:Arsène Brou, Richard Luger

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04153

Abstract : Changes in volatility contain valuable information about the likelihood of positive versus negative returns. We propose a new approach to modeling financial returns that exploits this insight by decomposing returns into sign and magnitude (absolute value) components, with magnitude closely related to volatility. The joint distribution used to compute expected returns combines a model for the marginal distribution of magnitude with a model for the distribution of the sign, conditional on the contemporaneous magnitude. Unlike traditional linear predictive regressions, this decomposition framework captures nonlinear predictability in return dynamics. An out of sample forecasting evaluation using monthly U.S. stock market excess returns demonstrates substantial statistical and economic gains relative to linear regression and complete subset regression, while delivering performance that is competitive with copula based return decomposition methods and other nonlinear benchmarks.

Keywords : 

Abstract :波动性的变化包含了关于正回报与负回报可能性的宝贵信息。我们提出了一种新的财务回报建模方法，通过将回报分解为符号和幅度（绝对值）分量来利用这一见解，其中幅度与波动性密切相关。用于计算预期回报的联合分布结合了幅度边际分布模型和符号分布模型，以同期幅度为条件。与传统的线性预测回归不同，这种分解框架捕捉到了回报动态中的非线性可预测性。使用美国股市月度超额回报进行的样本外预测评估表明，与线性回归和完全子集回归相比，其统计和经济效益显著，同时其表现与基于copula的回报分解方法和其他非线性基准具有竞争力。

Keywords :

### 

\[17\] Polymarket v1 Database

标题:Polymarket v1数据库

作者:Boka Qin, Rui Yang

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04217

Abstract : We introduce the Polymarket v1 Database  the complete on chain trade archive of Polymarket s first generation CTF Exchange on Polygon, spanning 2022 11 21 to 2026 04 28 and covering the full contract lifecycle from first settlement to natural termination. The dataset comprises 1.20 billion trade records across 1.30 million markets with  61 billion in nominal volume. Its defining feature is 100  ground truth aggressor direction derived from the blockchain settlement layer, a property unavailable in existing prediction market archives, which rely on heuristic inference. We use this truth aligned archive to benchmark standard microstructure tools and document three findings. First, the tick rule and bulk volume classification achieve near random aggregate accuracy (49.83  and 50.51 ), but this masks a systematic, correctable price level gradient driven by positive trade direction autocorrelation and concentrated market making    two structural features of prediction markets that violate the mean reversion assumption embedded in classical classifiers. Second, these classification errors propagate into downstream metrics  inferred VPIN diverges substantially from ground truth VPIN, and OFI estimates are directionally biased, with material consequences for Transaction Cost Analysis. Third, ground truth microstructure quality predicts forecasting performance in ways that classification based proxies cannot recover  True VPIN positively predicts Brier scores, while Gibbs spread negatively predicts them    a selection effect reflecting that high spread niche markets attract informed specialists rather than noise traders. Replacing ground truth metrics with classified proxies attenuates both relationships, illustrating that measurement accuracy at the transaction level is a prerequisite for reliable inference about prediction market design and probability calibration.

Keywords : 

Abstract :我们介绍Polymarket v1数据库，这是Polymarket第一代CTF交易所在Polygon上的完整链上交易档案，涵盖2022年11月21日至2026年4月28日，涵盖了从首次结算到自然终止的整个合同生命周期。该数据集包括130万个市场的12亿条交易记录，名义交易量为610亿。它的定义特征是从区块链结算层导出的100个地面真实侵略者方向，这是现有预测市场档案中不可用的属性，依赖于启发式推理。我们使用这个与事实一致的档案来对标准微观结构工具进行基准测试，并记录三个发现。首先，分时规则和批量分类实现了近乎随机的总体准确率（49.83和50.51），但这掩盖了由正交易方向自相关和集中做市驱动的系统性、可纠正的价格水平梯度，这两个预测市场的结构特征违反了经典分类器中嵌入的均值回归假设。其次，这些分类误差传播到下游指标中，推断出的VPIN与地面实况VPIN存在很大差异，OFI估计具有方向性偏差，对交易成本分析产生重大影响。第三，地面真实微观结构质量以基于分类的代理无法恢复的方式预测预测性能。True VPIN正向预测Brier得分，而Gibbs点差负向预测Brier分数——这反映了高点差利基市场吸引的是知情专家而非噪音交易者。用分类代理代替基本事实指标会削弱这两种关系，这表明交易层面的测量准确性是对预测市场设计和概率校准进行可靠推断的先决条件。

Keywords :

### 

\[18\] Fairness and Strategy Proofness in Automated Market Makers

标题:自动化做市商的公平性和策略证明

作者:Frank M. V. Feys

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04959

Abstract : No deployed automated market maker lets its liquidity providers vote on the trading function. We show this is structural, not an oversight. On the weighted product family with  n  geq 3  assets, no aggregation rule is at once fair and strategy proof. Arrovian fairness forces a unique form, the weighted Aitchison centroid, the weighted geometric mean of the providers  preferred pools. But fairness forces mean type aggregation and strategy proofness forces median type, and the only rule that is both is a single provider dictator. The obstruction is sharp  it vanishes at  n   2 , where a fair strategy proof rule exists. Under the Frongillo  Papireddygari  Waggoner equivalence, the centroid is Genest s logarithmic opinion pool, and the impossibility transfers to externally Bayesian pooling.

Keywords : 

Abstract :没有部署的自动化做市商允许其流动性提供商对交易功能进行投票。我们证明这是结构性的，而不是疏忽。在具有n个geq 3资产的加权产品族上，没有聚合规则是公平和策略证明的。阿罗维安公平迫使一种独特的形式，即加权艾奇逊质心，即提供者首选池的加权几何平均值。但公平性力量意味着类型聚合，而策略证明力则意味着中值类型，两者都是唯一的规则，即单一提供者独裁者。障碍是尖锐的，它在n2处消失，在n2处存在公平的策略证明规则。在Frongillo-Papireddygari-Waggoner等价下，质心是Genest的对数意见池，不可能性转移到外部贝叶斯池。

Keywords :