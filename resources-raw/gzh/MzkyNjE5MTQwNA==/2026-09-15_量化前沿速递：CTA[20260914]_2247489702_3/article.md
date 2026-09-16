# 量化前沿速递：CTA\[20260914\]

shameless 量化前沿速递 2026-09-15 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489702&idx=3&sn=3abcfe77fee0665c0f68613bbf53f045&chksm=c328a99ed32529003a757e73dc88593953a19cd03c10ee8f145e05a7adb0b3cdc3dbf3d0d687#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489702&idx=3&sn=3abcfe77fee0665c0f68613bbf53f045&chksm=c328a99ed32529003a757e73dc88593953a19cd03c10ee8f145e05a7adb0b3cdc3dbf3d0d687#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Deep Learning for Reflected BSDEs

反射式BSDE的深度学习

来源:ARXIV\_20260909

\[2\] Unbiased Monte Carlo Greeks for Discontinuous Payoffs

无偏见的蒙特卡洛希腊人获得不连续回报

来源:ARXIV\_20260909

\[3\] Pricing and Hedging of Discretely Monitored Asian Options in the Volterra Heston Model

Volterra-Heston模型中离散监控亚式期权的定价与套期保值

来源:ARXIV\_20260909

\[4\] Historical Reflections on Interest Rates and the Emergence of the Yield Curve

利率与收益率曲线产生的历史反思

来源:ARXIV\_20260909

\[5\] AI for AI

AI for AI

来源:ARXIV\_20260909

\[6\] Variance Optimal Hedging in the Rough Hawkes  Heston Model

Rough-Hokes-Heston模型中的方差最优套期保值

来源:ARXIV\_20260909

\[7\] From Discrete Trailing Returns to a Continuous Graphical Profile

从离散追踪回报到连续图形轮廓

来源:ARXIV\_20260909

\[8\] The profit bias identity in sports betting

体育博彩中的利润偏好认同

来源:ARXIV\_20260909

\[9\] AlphaRJM

AlphaRJM

来源:ARXIV\_20260909

\[10\] The Log S fBM model

Log S fBM模型

来源:ARXIV\_20260910

\[11\] Geometric and Arithmetic Likelihood Aggregation for Diffusions with Heterogeneous Volatility

非均匀波动扩散的几何和算术似然聚集

来源:ARXIV\_20260910

### 

\[1\] Deep Learning for Reflected BSDEs

标题:反射式BSDE的深度学习

作者:Ruimeng Hu, Yihan Zou

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.05434

Abstract : Reflected backward stochastic differential equations (RBSDEs) provide a probabilistic formulation for obstacle constrained problems, but existing deep learning methods for their high dimensional solution remain limited. In this paper, we propose two deep learning schemes for RBSDEs, a deep forward scheme (DFS) and a deep backward scheme (DBS), by first reducing the reflected problem to a family of regularized BSDEs. Our main theoretical contribution concerns the DBS  we establish an explicit error bound showing that, for each fixed regularization parameter   varepsilon 0 , the approximation error between the DBS solution and the solution to the regularized BSDE is controlled by the associated training loss. We prove that this training loss can be controlled by the universal approximation capability of neural networks. Together, these results yield a theoretical foundation for the deep learning based solution and complement existing analysis for forward type methods. We illustrate the framework on high dimensional American option pricing, where the reflected formulation allows us to address the continuous time exercise feature directly rather than through a Bermudan approximation. Numerical experiments demonstrate that both DFS and DBS deliver accurate solutions in high dimensions.

Keywords : 

Abstract :反射后向随机微分方程（RBSDE）为障碍约束问题提供了一种概率公式，但现有的高维深度学习方法仍然有限。在本文中，我们提出了两种用于RBSDE的深度学习方案，即深度前向方案（DFS）和深度后向方案（DBS），首先将反射问题简化为一组正则化的BSDE。我们的主要理论贡献涉及DBS，我们建立了一个显式的误差界，表明对于每个固定的正则化参数varepsilon 0，DBS解和正则化BSDE解之间的近似误差由相关的训练损失控制。我们证明了这种训练损失可以通过神经网络的通用逼近能力来控制。这些结果共同为基于深度学习的解决方案提供了理论基础，并补充了现有的正向方法分析。我们说明了高维美式期权定价的框架，其中反映的公式使我们能够直接解决连续时间行使特征，而不是通过百慕大近似值。数值实验表明，DFS和DBS都能在高维度上提供精确的解。

Keywords :

### 

\[2\] Unbiased Monte Carlo Greeks for Discontinuous Payoffs

标题:无偏见的蒙特卡洛希腊人获得不连续回报

作者:Evgeny Lakshtanov

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.06137

Abstract : Pathwise differentiation of Monte Carlo estimators fails at payoff discontinuities, producing zero or biased sensitivities for barriers, autocallables, and digital options. The industry workaround     smoothing the indicator functions     introduces bias and requires per product calibration. We derive a correction formula that restores unbiased Greeks without smoothing. For a payoff  F(Z, theta)  that is piecewise smooth with discontinuities on surfaces    g i   0   , we show that the sensitivity decomposes into a pathwise term (computed by standard AAD) plus a sum of boundary corrections, each involving the payoff jump, the Gaussian density at the boundary, and the sensitivity of the boundary to the parameter. The correction is computed by Newton root finding in the normal random space, with the jump evaluated by two forward replays of the pricing kernel. The implementation uses AADC ( texttt pip install aadc ), whose tape replay and automatic discontinuity tracking make the method fully automatic     the quant writes standard pricing code, and the correction driver identifies and handles all discontinuities. We prove the formula for arbitrary compositions of smooth functions and indicator functions (not just outer products), covering real autocallable payoff structures with recursive alive dead logic. Benchmarks on QuantLib models (GBM, Heston, Hull White) show all Greeks within 0.1  4   of analytic or bump and revalue references.

Keywords : 

Abstract :蒙特卡洛估计量的路径微分在收益不连续性时失败，对障碍、自动可调和数字期权产生零或有偏差的灵敏度。平滑指示器功能的行业解决方法引入了偏差，需要对每个产品进行校准。我们推导出了一个校正公式，可以在不平滑的情况下恢复无偏的希腊语。对于在表面g i 0上具有不连续性的分段平滑的收益F（Z，θ），我们证明灵敏度分解为一个路径项（由标准AAD计算）加上一系列边界校正，每个校正都涉及收益跳跃、边界处的高斯密度和边界对参数的灵敏度。修正是通过在正态随机空间中寻找牛顿根来计算的，跳跃是通过定价核的两次前向回放来评估的。该实现使用AADC（texttt-pip-install-AADC），其磁带重放和自动不连续性跟踪使该方法完全自动化——量化师编写标准定价代码，校正驱动程序识别和处理所有不连续性。我们证明了光滑函数和指标函数（不仅仅是外积）的任意组合的公式，该公式用递归活死逻辑覆盖了真实的可自动调整的支付结构。QuantLib模型（GBM、Heston、Hull-White）的基准显示，所有希腊人在分析或碰撞和重估参考值的0.1 4以内。

Keywords :

### 

\[3\] Pricing and Hedging of Discretely Monitored Asian Options in the Volterra Heston Model

标题:Volterra-Heston模型中离散监控亚式期权的定价与套期保值

作者:Gijs Custers, Sven Karbach, Martin Friesen

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.07169

Abstract : We develop semi closed pricing formulas and lifted model hedging methods for discretely monitored geometric and arithmetic Asian options in the Volterra Heston stochastic volatility model. Exploiting the affine Volterra structure, we derive a tractable transform for the joint law of the terminal log price and the discretely monitored geometric average. This transform yields semi closed pricing formulas for geometric Asian options, which in turn provide effective control variates for Monte Carlo valuation of arithmetic Asian options. Under the stated real moment and affine transform hypotheses, we also derive the Galtchouk Kunita Watanabe decomposition for Fourier representable payoffs and obtain a variance optimal hedge in terms of the Riccati Volterra equation and the forward variance curve. Using N factor Markovian approximations, we obtain a finite dimensional numerical implementation for hedging Asian options. Our numerical experiments document factor convergence for a regular non Markovian kernel and the effect of rebalancing frequency on hedging error. In the Heston benchmark, geometric Asian controls substantially reduce the variance of arithmetic Asian price estimates and improve the finite sample stability of regression based hedging relative to direct regression.

Keywords : 

Abstract :我们为Volterra-Heston随机波动率模型中离散监测的几何和算术亚式期权开发了半封闭定价公式和提升模型套期保值方法。利用仿射Volterra结构，我们推导出了终端对数价格和离散监测几何平均值联合定律的可处理变换。这种转换产生了几何亚式期权的半封闭定价公式，这反过来又为算术亚式期权蒙特卡洛估值提供了有效的控制变量。在所述实矩和仿射变换假设下，我们还推导了傅里叶可表示收益的Galtchouk-Kunita Watanabe分解，并根据Riccati-Volterra方程和正向方差曲线得到了方差最优套期。利用N因子马尔可夫近似，我们得到了套期保值亚式期权的有限维数值实现。我们的数值实验记录了正则非马尔可夫核的因子收敛性以及再平衡频率对套期保值误差的影响。在赫斯顿基准中，几何亚洲控制大大降低了算术亚洲价格估计的方差，并提高了基于回归的套期保值相对于直接回归的有限样本稳定性。

Keywords :

### 

\[4\] Historical Reflections on Interest Rates and the Emergence of the Yield Curve

标题:利率与收益率曲线产生的历史反思

作者:Olivier Guéant

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.07958

Abstract : This text grew out of a historical introduction initially written for a study of interest rates in cryptocurrency markets. The difficulty of defining a term structure for a currency without a conventional bond market led naturally to a more fundamental question  under what historical conditions does a yield curve become observable at all  Credit existed long before modern money, and interest bearing loans are documented as early as ancient Mesopotamia. For much of history, the surviving evidence lacks the institutional features that facilitate reliable comparisons of interest rates by maturity  standardised debt instruments, sufficiently homogeneous borrowers, regular issuance over a range of maturities, observable market prices, and liquid secondary markets. We trace the gradual emergence of these conditions from ancient Mesopotamia, Greece, and Rome, through medieval and early modern Europe, to the development of modern sovereign debt markets in the nineteenth and twentieth centuries.

Keywords : 

Abstract :本文源于一篇历史介绍，最初是为研究加密货币市场的利率而写的。在没有传统债券市场的情况下，为货币定义期限结构的困难自然导致了一个更根本的问题，即在什么样的历史条件下，收益率曲线才能被观察到。早在现代货币出现之前，信贷就已经存在，有息贷款早在古代美索不达米亚就有记录。在历史的大部分时间里，幸存的证据缺乏制度特征，这些特征有助于通过到期标准化债务工具、足够同质的借款人、一系列到期日的定期发行、可观察的市场价格和流动性二级市场对利率进行可靠的比较。我们追溯了这些条件的逐渐出现，从古代美索不达米亚、希腊和罗马，到中世纪和近代早期的欧洲，再到19世纪和20世纪现代主权债务市场的发展。

Keywords :

### 

\[5\] AI for AI

标题:AI for AI

作者:Alexander Crosier, Kyle Onghai, Ronnie Sircar

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.08166

Abstract : The twenty first century s transformative technology, artificial intelligence, is increasingly constrained by the twentieth century s transformative technology, the electricity grid. Rapid growth in electricity demand from data centers is leading to higher electricity prices, without a compensating supply side response. We develop a framework linking data center load growth, available generation capacity, and market clearing prices to understand this phenomenon. We first analyze a deterministic model to show how differing estimates of demand and supply growth rates affect prices. We then model the expansion of new data centers and their associated electricity demand, together with build outs of new electricity supply, as stochastic processes,resulting in probabilistic distributions of supply, demand, and prices rather than a single forecast. Finally, we formulate generation expansion as a stochastic control problem in which a revenue maximizing investor dynamically chooses the intensity of supply side investments. The analysis highlights a central challenge of the data center build out  even when rapid demand growth increases the need for new generation, the uncertainties related to load forecasts, development execution risks, and value cannibalization from overbuilding capacity may weaken incentives to invest at the pace required to keep electricity prices stable.

Keywords : 

Abstract :二十一世纪的变革性技术人工智能越来越受到二十世纪变革性技术电网的制约。数据中心电力需求的快速增长导致电价上涨，而供应侧却没有相应的应对措施。我们开发了一个框架，将数据中心负载增长、可用发电容量和市场清算价格联系起来，以了解这一现象。我们首先分析了一个确定性模型，以展示需求和供应增长率的不同估计如何影响价格。然后，我们将新数据中心的扩张及其相关的电力需求以及新电力供应的扩建建模为随机过程，从而得出供应、需求和价格的概率分布，而不是单一的预测。最后，我们将发电扩张表述为一个随机控制问题，其中收益最大化的投资者动态选择供给侧投资的强度。该分析强调了数据中心扩建的一个核心挑战，即使需求快速增长增加了对新一代的需求，与负荷预测、开发执行风险和过度建设能力的价值蚕食相关的不确定性也可能削弱以保持电价稳定所需的速度进行投资的动力。

Keywords :

### 

\[6\] Variance Optimal Hedging in the Rough Hawkes  Heston Model

标题:Rough-Hokes-Heston模型中的方差最优套期保值

作者:Yingli Wang, Xiaoyu Wang

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.08541

Abstract : We study variance optimal stock hedging and the convergence of approximate strategies in the rough Hawkes  Heston model. Starting from the model s affine conditional transform and the affine Volterra jump framework, we obtain semi explicit hedges for European calls and a representation of the minimum quadratic error through the Galtchouk  Kunita  Watanabe projection. Our main approximation result keeps the original stock, variance driver, and information flow fixed while regularizing the kernel used to evaluate the hedge. To handle singular memory and common marked jumps, we construct the approximate holdings from histories available before trading and preserve the conditional transform s random modulus envelope. Riccati  Volterra stability and weighted truncation then yield convergence in the original stock s trading norm on compact Fourier intervals. For calls, a joint choice of kernel regularization and Fourier cutoff gives convergence of the initial capitals and strategies, uniform in time square mean convergence of continuous time gains, and convergence of the terminal mean square error to the variance optimal value. A numerical experiment with shifted fractional kernels illustrates the construction on common original market paths.

Keywords : 

Abstract :我们研究了粗糙霍克斯-赫斯顿模型中的方差最优股票套期保值和近似策略的收敛性。从模型的仿射条件变换和仿射Volterra跳跃框架出发，我们通过Galtchouk-Kunita Watanabe投影得到了欧式调用的半显式模糊限制和最小二次误差的表示。我们的主要近似结果保持了原始股票、方差驱动因素和信息流的固定，同时对用于评估套期保值的核进行了正则化。为了处理奇异记忆和共同标记跳跃，我们根据交易前可用的历史构建近似持有量，并保留条件变换的随机模包络。Riccati-Volterra稳定性和加权截断在紧致傅里叶区间上使原始股票的交易范数收敛。对于调用，核正则化和傅里叶截止的联合选择使初始资本和策略收敛，连续时间增益的时间平方均值收敛均匀，最终均方误差收敛到方差最优值。用移位分数核的数值实验说明了在共同原始市场路径上的构建。

Keywords :

### 

\[7\] From Discrete Trailing Returns to a Continuous Graphical Profile

标题:从离散追踪回报到连续图形轮廓

作者:Lei Liu

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.06267

Abstract : Investment performance is commonly presented either as a conventional cumulative return chart, which fixes a historical starting date and traces performance forward, or as a trailing return table, which fixes the current endpoint but reports only a small set of prespecified horizons. These two displays have complementary limitations  fixed start comparisons are conditional on the selected origin, whereas trailing returns provide only discrete snapshots of the underlying fixed endpoint return function. We present the Return to Present (RTP) curve as a continuous fixed endpoint representation that brings these perspectives together by holding the evaluation date fixed while allowing the hypothetical historical purchase date to vary over the available history. Familiar 1 month, 3 month, 6 month, 1 year, and longer trailing returns therefore become selected points on a continuous curve. When multiple investments are overlaid, RTP directly displays entry date sensitivity, persistent relative advantage, crossings, and the timing and magnitude of separation without requiring selection of a single historical origin. The same endpoint based construction naturally accommodates investments with unequal inception dates, recurring purchases, and retrospective portfolio rotation decisions in which sale and replacement purchase dates may differ. We illustrate these uses with real investment data and discuss its relationship to momentum. RTP does not define a new return measure  its contribution is a simple graphical organization of familiar realized returns for historical comparison and decision support rather than prediction or statistical inference.

Keywords : 

Abstract :投资绩效通常表现为传统的累积回报图，该图确定了历史开始日期并跟踪了未来的表现，或者表现为尾随回报表，该表确定了当前终点，但只报告了一小部分预先指定的范围。这两种显示具有互补的局限性——固定起点比较取决于所选的原点，而尾随返回仅提供底层固定终点返回函数的离散快照。我们将回归现状（RTP）曲线作为一个连续的固定端点表示，通过保持评估日期固定，同时允许假设的历史购买日期在可用历史中变化，将这些观点结合在一起。因此，熟悉的1个月、3个月、6个月、1年和更长时间的跟踪回报成为连续曲线上的选定点。当多个投资重叠时，RTP直接显示进入日期敏感性、持续相对优势、交叉点以及分离的时间和幅度，而不需要选择单个历史来源。同样的基于端点的构建自然可以适应具有不等起始日期、经常性购买和追溯性投资组合轮换决策的投资，在这些决策中，销售和替代购买日期可能不同。我们用真实的投资数据来说明这些用途，并讨论其与动量的关系。RTP没有定义新的回报衡量标准，它的贡献是对熟悉的已实现回报的简单图形组织，用于历史比较和决策支持，而不是预测或统计推断。

Keywords :

### 

\[8\] The profit bias identity in sports betting

标题:体育博彩中的利润偏好认同

作者:Jacek P. Dmochowski

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.06739

Abstract : Sports betting moves money continuously from a large public to a small number of firms. The most influential account of that flow, due to Levitt (2004), holds that books price away from the market clearing point to exploit predictable public biases. It computes profit from two numbers (the probability that a side wins the proposition and the fraction of handle it attracts), treating the share on a side as independent of the outcome. Here we relax that assumption and derive a profit bias identity  profit is affine and increasing in the expected share of handle on the losing side, with Levitt s expression as the special case of independence. The identity resolves the book s margin into exactly three channels  its hold, the product of its price shading and the public s lean, and the covariance between bet share and outcome. A lean is thus worthless without shading, and shading is worthless without a lean. Under a public belief model, the profit driver is the public s Bayes error  the probability of a representative bettor selecting the losing side. We provide necessary and sufficient conditions for a  Goldilocks Zone   prices at which book and bettor both profit. Testing these predictions on 1,139 Major League Baseball games, we find that the apparent dependence between bet share and outcome is a Simpson s paradox  present when games are pooled, but absent once they are separated by which side the book favored. The public leans heavily toward favorites, but we detect no matching shading, and the realized margin is indistinguishable from the hold.

Keywords : 

Abstract :体育博彩不断地将资金从大型公众转移到少数公司。莱维特（2004）对这种流动最有影响力的解释认为，书籍定价偏离了市场清算点，以利用可预测的公众偏见。它根据两个数字（一方赢得命题的概率和它吸引的句柄分数）计算利润，将一方的份额视为与结果无关。在这里，我们放宽了这一假设，并推导出了一个利润偏差恒等式——利润是仿射的，并且在损失方的预期份额中增加，莱维特表达式作为独立性的特例。这个身份将这本书的保证金分为三个渠道——持有、价格阴影和公众偏好的乘积，以及赌注份额和结果之间的协方差。因此，没有遮荫的瘦肉毫无价值，没有瘦肉的遮荫也毫无价值。在公众信念模型下，利润驱动因素是公众的贝叶斯错误，即代表性投注者选择输方的概率。我们为金发姑娘区的价格提供了必要和充分的条件，在这个价格下，图书和博彩商都能获利。在1139场美国职业棒球大联盟比赛中测试这些预测，我们发现投注份额和结果之间的明显依赖性是辛普森悖论，当比赛被合并时存在，但一旦它们被书中支持的一方分开，就不存在了。公众非常倾向于收藏，但我们没有检测到匹配的阴影，并且实现的边距与保留无法区分。

Keywords :

### 

\[9\] AlphaRJM

标题:AlphaRJM

作者:Sayan Dhan, Selvaraju Natarajan

来源:ARXIV\_20260909

链接:https://arxiv.org/pdf/2609.08581

Abstract : Formulaic alpha discovery is a pool dependent symbolic search problem in which informative feedback is observed primarily when a complete expression is evaluated. This delayed feedback creates two coupled difficulties  the retained alpha pool does not preserve the full history of realized evaluation feedback, and the value of an intermediate construction action is uncertain because its consequence depends on the formula eventually completed. We introduce AlphaRJM, which addresses these difficulties through Reward Jump Memory, an event driven latent state that remains fixed during token construction and updates only at terminal evaluation events using the realized pool reward and evaluation outcome, and an action conditioned SDE return critic that represents future discounted discovery returns with stochastic particles. The particles guide action selection through their mean and uncertainty and are learned using a distributional Bellman objective combining energy distance matching, mean calibration, and jump regularization. Empirically, AlphaRJM delivers strong and stable gains across multiple equity universes, forecasting horizons, and random seeds, while ablations confirm the complementary roles of persistent evaluation history, stochastic return modeling, and distributional supervision.

Keywords : 

Abstract :公式化阿尔法发现是一个依赖于池的符号搜索问题，其中主要在评估完整表达式时观察到信息反馈。这种延迟反馈造成了两个相互关联的困难——保留的阿尔法池不能保留已实现评估反馈的完整历史，中间构建动作的价值是不确定的，因为其后果取决于最终完成的公式。我们引入了AlphaRJM，它通过奖励跳跃记忆来解决这些困难，奖励跳跃记忆是一种事件驱动的潜在状态，在代币构建过程中保持固定，仅在终端评估事件中使用已实现的池奖励和评估结果进行更新，还有一个动作条件的SDE回报评论家，用随机粒子表示未来贴现的发现回报。粒子通过其均值和不确定性来指导动作选择，并使用结合能量距离匹配、均值校准和跳跃正则化的分布式贝尔曼目标进行学习。根据经验，AlphaRJM在多个股票领域、预测期和随机种子中提供了强大而稳定的收益，而消融证实了持续评估历史、随机回报建模和分布监督的互补作用。

Keywords :

### 

\[10\] The Log S fBM model

标题:Log S fBM模型

作者:Othmane Zarhali, Emmanuel Bacry, Jean-François Muzy

来源:ARXIV\_20260910

链接:https://arxiv.org/pdf/2609.09405

Abstract : The Log S fBM model, introduced by Wu et al., is a stochastic volatility model whose log volatility is a stationary fractional Brownian motion (S fBM)  a stationary Gaussian process with power decaying autocovariance driven by the Hurst exponent  H , and variance scaled by an intermittency coefficient. A key property is that it reconciles rough volatility, where  H  is typically near  0.1  (see Gatheral et al.), with multifractal volatility, where  H  is close to  0  as in Bacry, Muzy et al.  the model s volatility measure converges to a multifractal random measure as  H to0 . Numerical findings in Wu et al. show intermittency of order  0.02  across financial assets, motivating a small intermittency approximation of log volatility moments for calibration via the general method of moments (GMM). In this work, we conduct a statistical analysis of the Log S fBM model. We derive scaling properties of the S fBM process and the Log S fBM integrated volatility measure, present deviation inequalities with tail distributions sensitive to  H  and intermittency, and develop a hypothesis test for the null Hurst exponent, i.e.  rough versus multifractal dynamics. Finally, we revisit scale invariance of the log volatility increment process via explicit small intermittency formulas, reproducing analogous properties in both regimes.

Keywords : 

Abstract :Wu等人提出的Log-S-fBM模型是一个随机波动模型，其对数波动是一个平稳的分数布朗运动（S-fBM），一个由赫斯特指数H驱动的具有幂衰减自协方差的平稳高斯过程，方差由间歇系数缩放。一个关键特性是，它调和了粗糙波动率和多重分形波动率，其中H通常接近0.1（见Gatheral等人），其中H接近0，如Bacry、Muzy等人所述。当H到0时，模型的波动率度量收敛到多重分形随机度量。Wu等人的数值研究结果表明，金融资产之间存在0.02级的间歇性，通过一般矩量法（GMM）激发了对数波动矩的小间歇性近似进行校准。在这项工作中，我们对Log-S-fBM模型进行了统计分析。我们推导了S-fBM过程和Log-S-fBM综合波动度量的标度性质，给出了对H和间歇性敏感的尾部分布的偏差不等式，并对零赫斯特指数进行了假设检验，即粗糙与多重分形动力学。最后，我们通过显式的小间歇公式重新审视了对数波动增量过程的尺度不变性，在两种情况下都再现了类似的性质。

Keywords :

### 

\[11\] Geometric and Arithmetic Likelihood Aggregation for Diffusions with Heterogeneous Volatility

标题:非均匀波动扩散的几何和算术似然聚集

作者:Jan Vecer

来源:ARXIV\_20260910

链接:https://arxiv.org/pdf/2609.09470

Abstract : We study how to combine diffusion models that disagree about drift and covariance. Candidate first relative entropy minimization gives geometric pooling, whereas expert first minimization gives the arithmetic mixture associated with weighted logarithmic wealth. Different quadratic variations can make path space entropy infinite, and the arithmetic mixture need not be a Markov diffusion. We therefore specify a local criterion combining drift information, normalized by the second argument s covariance, with quadratic transport between Gaussian shocks in a fixed state metric. A Gaussian identity and an Euler convergence estimate justify this chosen criterion. The expert first projection has posterior mean drift and an inverse covariance penalty for drift dispersion  in one dimension this penalty increases volatility. For Ornstein  Uhlenbeck experts with a common mean reversion rate, coefficient regularity holds on the full horizon for common volatility and away from the initial time for heterogeneous volatilities. The candidate first problem has a Hamilton  Jacobi  Bellman characterization. Its matrix covariance selector reduces by congruence to a Bures  Wasserstein barycenter. The condition  H  lambda M succ0 , with value Hessian  H  and state metric  M , is sharp for finiteness of the unrestricted local covariance problem  compact constraints keep that problem finite. A covariance disagreement budget interprets the penalty parameter. Linear  quadratic, exact transition, and financial examples distinguish dynamic volatility reduction, drift dispersion inflation, and martingale restrictions.

Keywords : 

Abstract :我们研究如何将漂移和协方差不一致的扩散模型结合起来。候选优先相对熵最小化给出了几何池，而专家优先最小化给出了与加权对数财富相关的算术混合。不同的二次变化可以使路径空间熵无限大，算术混合不需要是马尔可夫扩散。因此，我们指定了一个局部标准，该标准将由第二个自变量协方差归一化的漂移信息与固定状态度量中高斯冲击之间的二次传输相结合。高斯恒等式和欧拉收敛估计证明了所选标准的合理性。专家优先投影具有后验均值漂移和一维漂移分散的逆协方差惩罚，这种惩罚增加了波动性。对于具有共同均值回归率的Ornstein-Uhlenbeck专家来说，系数规律性适用于共同波动率的整个范围，而不适用于异质波动率的初始时间。候选第一个问题具有哈密顿-雅可比-贝尔曼特征。它的矩阵协方差选择器通过与Bures-Wasserstein重心的同余来减少。对于无限制局部协方差问题的有限性，具有Hessian H值和状态度量M的H lambda M succ0条件是尖锐的——紧约束使该问题保持有限。协方差差异预算解释了惩罚参数。线性二次型、精确转移和金融例子区分了动态波动率降低、漂移分散膨胀和鞅限制。

Keywords :