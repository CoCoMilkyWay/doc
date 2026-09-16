# 量化前沿速递：CTA\[20260322\]

shameless 量化前沿速递 2026-03-23 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489459&idx=3&sn=12aa7297d66691745b9fac187895ec8f&chksm=c3640a568f81f0a458593848cc7d30c68099250bb43354215e8309b18f25e32b06aff5a53064#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489459&idx=3&sn=12aa7297d66691745b9fac187895ec8f&chksm=c3640a568f81f0a458593848cc7d30c68099250bb43354215e8309b18f25e32b06aff5a53064#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Feynman Kac Derivatives Pricing on the Full Forward Curve

Feynman-Kac衍生品在全正向曲线上的定价

来源:ARXIV\_20260316

\[2\] Macroeconomic Forecasting from Input Output Tables Alone

仅从投入产出表进行宏观经济预测

来源:ARXIV\_20260316

\[3\] Mortgage Burnout and Selection Effects in Heterogeneous Cox Hazard Models

异质Cox风险模型中的抵押贷款倦怠和选择效应

来源:ARXIV\_20260316

\[4\] Pricing Derivatives under Self Exciting Dynamics

自激动力学下的衍生品定价

来源:ARXIV\_20260316

\[5\] A Double Categorical Framework for Multi Stage Portfolio Construction and Alignment

多阶段投资组合构建与对齐的双范畴框架

来源:ARXIV\_20260316

\[6\] Betting Around the Clock

全天候投注

来源:ARXIV\_20260317

\[7\] Conditioning on a Volatility Proxy Compresses the Apparent Timescale of Collective Market Correlation

波动性代理条件压缩了集体市场相关性的表观时间尺度

来源:ARXIV\_20260317

\[8\] Curved Greeks

曲线希腊人

来源:ARXIV\_20260317

\[9\] E TRENDS

E趋势

来源:ARXIV\_20260317

\[10\] Tractable bank capital structure

可追踪的银行资本结构

来源:ARXIV\_20260317

\[11\] When Are Social Ties Associated with Strategic Behavior 

社会关系何时与战略行为相关

来源:ARXIV\_20260318

\[12\] Playing Against the Machine

与机器对抗

来源:ARXIV\_20260318

\[13\] Risk Based Auto Deleveraging

基于风险的自动去杠杆化

来源:ARXIV\_20260318

\[14\] Open vs. Sealed

打开与密封

来源:ARXIV\_20260318

\[15\] A Portfolio Anchored Frequency Severity Risk Index for Trip and Driver Assessment Using Telematics Signals

基于远程信息处理信号的行程和驾驶员评估的组合锚定频率严重性风险指数

来源:ARXIV\_20260318

\[16\] LR Robot

LR机器人

来源:ARXIV\_20260319

### 

\[1\] Feynman Kac Derivatives Pricing on the Full Forward Curve

标题:Feynman-Kac衍生品在全正向曲线上的定价

作者:Kevin Mott

来源:ARXIV\_20260316

链接:https://arxiv.org/pdf/2603.12375

Abstract : This paper introduces a no arbitrage, Monte Carlo free approach to pricing path dependent interest rate derivatives. The Heath Jarrow Morton model gives arbitrage free contingent claims prices but is infinite dimensional, making traditional numerical methods computationally prohibitive. To make the problem computationally tractable, I cast the stochastic pricing problem as a deterministic partial differential equation (PDE). Finance Informed Neural Networks (FINNs) solve this PDE directly by minimizing violations of the differential equation and boundary condition, with automatic differentiation efficiently computing the exact derivatives needed to evaluate PDE terms. FINNs achieve pricing accuracy within 0.04 to 0.07 cents per dollar of contract value compared to Monte Carlo benchmarks. Once trained, FINNs price caplets in a few microseconds regardless of dimension, delivering speedups ranging from 300,000 to 4.5 million times faster than Monte Carlo simulation as the state space discretization of the forward curve grows from 10 to 150 nodes. The major Greeks theta and curve deltas come for free, computed automatically during PDE evaluation at zero marginal cost, whereas Monte Carlo requires complete re simulation for each sensitivity. The framework generalizes naturally beyond caplets to other path dependent derivatives caps, swaptions, callable bonds requiring only boundary condition modifications while retaining the same core PDE structure.

Keywords : 

Abstract :本文介绍了一种无套利、无蒙特卡洛的定价路径相关利率衍生品的方法。Heath-Jarrow-Morton模型给出了无套利的或有索赔价格，但它是无限维的，使得传统的数值方法在计算上难以实现。为了使这个问题在计算上易于处理，我将随机定价问题转化为确定性偏微分方程（PDE）。金融知情神经网络（FINN）通过最小化微分方程和边界条件的违反来直接解决这个偏微分方程，自动微分有效地计算了评估偏微分方程项所需的精确导数。与蒙特卡洛基准相比，FINN的定价精度在每美元合同价值0.04至0.07美分之间。一旦经过训练，FINN在几微秒内对caplet进行定价，无论维度如何，随着正向曲线的状态空间离散化从10个节点增长到150个节点，其速度比蒙特卡洛模拟快30万到450万倍。主要的希腊θ和曲线增量是免费的，在PDE评估期间以零边际成本自动计算，而蒙特卡洛需要对每个灵敏度进行完全的重新模拟。该框架自然地超越了caplets，扩展到其他依赖路径的衍生品caps、swaptions、只需要修改边界条件的可赎回债券，同时保留了相同的核心PDE结构。

Keywords :

### 

\[2\] Macroeconomic Forecasting from Input Output Tables Alone

标题:仅从投入产出表进行宏观经济预测

作者:Martin Jaraiz

来源:ARXIV\_20260316

链接:https://arxiv.org/pdf/2603.12412

Abstract : How much macroeconomic information is contained in a single input output table  We feed FIGARO 64 sector symmetric tables into DEPLOYERS, a Darwinian agent based simulator, producing genuine out of sample GDP forecasts. For each year, the model reads one FIGARO table for year N, self organizes an artificial economy through evolutionary selection, then runs 12 months of autonomous free market dynamics whose emergent growth rate predicts year N 1. The I O table is the only input  no time series, no estimated parameters, no expectations formation, no external forecasts.We present five results. First, a 9 year Austrian panel (2010 2018) using 12 seed ensembles produces MAE of 1.22 pp overall  for five non crisis years, MAE falls to 0.42 pp    comparable to the best professional forecaster (WIFO  0.48 pp). Second, cross country portability is demonstrated across multiple FIGARO countries with zero parameter changes. Third, a German 9 year panel reveals systematic  3.7 pp positive bias from export dependency    an informative negative result. Fourth, a COVID 19 simulation demonstrates the I O structure as a shock propagation mechanism  a 19 month timeline produces Year 1 GDP  4.62  vs empirical  6.6 . Fifth, emergent firm size distributions match European Commission data without micro target calibration.These results establish the I O table as serving a dual purpose  structural baseline engine and dynamic shock propagation mechanism. Since FIGARO covers 46 countries, the approach is immediately portable without retuning parameters.

Keywords : 

Abstract :单个投入产出表中包含多少宏观经济信息？我们将FIGARO 64部门对称表输入基于达尔文智能体的模拟器DEPLOYERS，生成真正的样本外GDP预测。对于每一年，该模型读取N年的FIGARO表，通过进化选择自组织人工经济，然后运行12个月的自主自由市场动态，其新兴增长率预测N 1年。I/O表是唯一的输入，没有时间序列，没有估计参数，没有期望形成，没有外部预测。我们呈现五个结果。首先，一个为期9年的奥地利专家组（2010-2018）使用12个种子组合，在五个非危机年份的总体MAE为1.22 pp，MAE降至0.42 pp，与最佳专业预报员（WIFO 0.48 pp）相当。其次，跨国家可移植性在多个FIGARO国家得到了证明，参数变化为零。第三，德国一个为期9年的面板显示，出口依赖带来了3.7个百分点的系统性正偏差，这是一个信息丰富的负结果。第四，COVID 19模拟表明，I O结构是一种冲击传播机制，19个月的时间线产生的第一年GDP为4.62，而经验为6.6。第五，新兴企业规模分布与欧盟委员会数据相匹配，无需进行微观目标校准。这些结果确立了I/O表作为双重用途的结构基线发动机和动态冲击传播机制。由于FIGARO覆盖了46个国家，该方法无需重新调整参数即可立即移植。

Keywords :

### 

\[3\] Mortgage Burnout and Selection Effects in Heterogeneous Cox Hazard Models

标题:异质Cox风险模型中的抵押贷款倦怠和选择效应

作者:Andrew Lesniewski

来源:ARXIV\_20260316

链接:https://arxiv.org/pdf/2603.12422

Abstract : We study the aggregate hazard rate of a heterogeneous population whose individual event intensities are modeled as Cox (doubly stochastic) processes. In the deterministic hazard setting, the observed pool hazard is the survival weighted mean of the individual hazards, and its time derivative equals the mean individual hazard drift minus a variance term. This yields a transparent structural explanation of burnout in mortgage pools. We extend this perspective to stochastic intensity models. The observed pool hazard remains a survival weighted mean, but now evolves as an Ito process whose drift contains the mean drift of the individual hazards and a negative selection term driven by cross sectional dispersion, together with a diffusion term inherited from the common factor. We formulate the general identity and discuss special cases relevant to mortgage prepayment modeling.

Keywords : 

Abstract :我们研究了个体事件强度被建模为Cox（双随机）过程的异质人群的总危险率。在确定性危害设置中，观测到的池危害是单个危害的生存加权平均值，其时间导数等于平均单个危害漂移减去方差项。这为抵押贷款池中的倦怠提供了一个透明的结构性解释。我们将这一观点扩展到随机强度模型。观测到的池危险仍然是生存加权平均值，但现在演变为Ito过程，其漂移包含单个危险的平均漂移和由横截面分散驱动的负选择项，以及从公因子继承的扩散项。我们制定了一般恒等式，并讨论了与抵押贷款提前还款建模相关的特殊情况。

Keywords :

### 

\[4\] Pricing Derivatives under Self Exciting Dynamics

标题:自激动力学下的衍生品定价

作者:Aqib Ahmed, Heiðar Eyjólfsson

来源:ARXIV\_20260316

链接:https://arxiv.org/pdf/2603.12602

Abstract : We consider the pricing of derivatives written on accumulated marks, such as weather derivatives or aggregate loss claims, using a self exciting marked point process. The jump intensity mean reverts between events and increases at jump times by an amount proportional to the mark. The resulting state process, where the variable  U t  accumulates jump magnitudes, is a piecewise deterministic Markov process (PDMP). We derive the discounted pricing equation as a backward partial integro differential equation (PIDE) in two spatial dimensions. To overcome the dimensionality, we propose an exponential (Laplace Fourier) transform in the accumulated mark variable, which diagonalizes the translation operator and reduces the pricing problem to a family of one dimensional PIDEs in the intensity variable along a Bromwich contour. For Gamma mixture mark laws (under actuarial or Esscher tilted measures), the nonlocal jump term is efficiently approximated by generalized Gauss  Laguerre quadrature. We solve the reduced PIDEs backward in time using a monotone IMEX finite difference scheme (implicit upwind drift and discounting, explicit jump operator) and recover option prices via numerical inversion. We provide a rigorous, term by term global error bound covering time and space discretization, quadrature, interpolation, and boundary effects, supported by numerical experiments and Monte Carlo benchmarks.

Keywords : 

Abstract :我们考虑使用自激标记点过程对累积标记的衍生品进行定价，如天气衍生品或累计损失索赔。跳跃强度均值在事件之间恢复，并在跳跃时间以与标记成比例的量增加。由此产生的状态过程是分段确定性马尔可夫过程（PDMP），其中变量U t累积跳跃幅度。我们将折扣定价方程推导为二维空间中的向后偏积分微分方程（PIDE）。为了克服维数问题，我们在累积标记变量中提出了一种指数（拉普拉斯-傅里叶）变换，该变换对平移算子进行对角化，并将定价问题简化为沿布罗姆维奇轮廓的强度变量中的一系列一维PIDE。对于Gamma混合标记定律（在精算或Esscher倾斜度量下），非局部跳跃项可以通过广义高斯-拉盖尔求积法有效地近似。我们使用单调IMEX有限差分方案（隐式迎风漂移和贴现，显式跳跃算子）在时间上向后求解缩减的PIDE，并通过数值反演恢复期权价格。我们提供了一个严格的、逐项的全局误差界，涵盖了时间和空间离散化、求积、插值和边界效应，并得到了数值实验和蒙特卡洛基准的支持。

Keywords :

### 

\[5\] A Double Categorical Framework for Multi Stage Portfolio Construction and Alignment

标题:多阶段投资组合构建与对齐的双范畴框架

作者:Wesley Phoa

来源:ARXIV\_20260316

链接:https://arxiv.org/pdf/2603.12301

Abstract : We construct a thin double category HS (Hub and Spoke) whose objects are closed subsets of standard simplices, horizontal morphisms are continuous maps representing portfolio re implementation processes, and vertical morphisms are closed relations representing alignment constraints. This framework models industrial portfolio construction pipelines    hierarchical structures in which a single investment strategy is translated through multiple stages into thousands of client portfolios. We establish four structural theorems  compositionality of alignment (functoriality), a pre trade safety guarantee (adjunction), an order independence result for compliance checking (lax Beck  Chevalley), and a filter commutation law (Frobenius reciprocity). The topological requirement that permissible portfolio spaces be closed and compact    ruling out   phantom portfolios   that arise from open constraint specifications    is shown to be essential for coherence. Extensions to set valued re implementations via the Double Operadic Theory of Systems, stochastic re implementations via Markov kernels on Polish spaces, and transport based safety metrics via Wasserstein distances are developed. An abstract axiomatic treatment identifies the equipment axioms sufficient for the main results. The mathematical content is elementary    no novel category theory is required. The contribution is the modelling claim  that these particular objects and morphisms formalise portfolio re implementation correctly.

Keywords : 

Abstract :我们构造了一个薄双范畴HS（Hub and Spoke），其对象是标准单纯形的闭子集，水平态射是表示投资组合再实现过程的连续映射，垂直态射是代表对齐约束的闭关系。该框架模拟了工业投资组合构建管道的层次结构，其中单个投资策略通过多个阶段转化为数千个客户投资组合。我们建立了四个结构定理——对齐的组合性（功能性）、交易前的安全保证（附加）、合规性检查的顺序独立结果（lax-Beck-Chavalley）和滤波器交换律（Frobenius互惠）。拓扑要求允许的投资组合空间是封闭和紧凑的，排除了由开放约束规范产生的幻影投资组合，这对一致性至关重要。开发了通过双操作系统理论对设定值重新实现的扩展、通过波兰空间上的马尔可夫核对随机重新实现的拓展，以及通过Wasserstein距离对基于传输的安全度量的扩展。抽象的公理化处理确定了足以得到主要结果的设备公理。数学内容是基础的，不需要新的范畴理论。其贡献在于建模声称，这些特定的对象和态射正确地形式化了投资组合的重新实现。

Keywords :

### 

\[6\] Betting Around the Clock

标题:全天候投注

作者:Umberto Cherubini

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.13632

Abstract : We investigate the performance of the Kelly rule in a setting in which the dynamics of the return is represented by a time change process. We find that in this general semi martingale setting the Kelly rule does not maximize the average growth rate, unless the log return is normally distributed. Namely, the investment position proposed by the Kelly rule is too large, and the investor could achieve a higher average growth rate by investing less aggressively. The higher the variance of the stochastic clock, the more material the failure of the Kelly rule. The ruin threshold proposed by Thorp (1969) is closer, even though examples based on stochastic clock variance estimates taken from the literature show that Kelly rule investment remains safely in the ruin free region. Finally, the goal of keeping the investment below the ruin threshold for a family of stochastic clock distributions generates a long term investment problem that parallels the  acceptable investment  theory.

Keywords : 

Abstract :我们研究了凯利规则在回报动态由时间变化过程表示的环境中的性能。我们发现，在这种一般的半鞅设置中，凯利规则不会使平均增长率最大化，除非对数回报呈正态分布。也就是说，凯利规则提出的投资头寸太大，投资者可以通过不那么激进的投资来实现更高的平均增长率。随机时钟的方差越大，凯利规则的失效就越严重。Thorp（1969）提出的破产阈值更接近，尽管基于文献中随机时钟方差估计的例子表明，凯利规则投资在无破产区域仍然是安全的。最后，将投资保持在随机时钟分布家族的破产阈值以下的目标产生了一个与可接受投资理论相似的长期投资问题。

Keywords :

### 

\[7\] Conditioning on a Volatility Proxy Compresses the Apparent Timescale of Collective Market Correlation

标题:波动性代理条件压缩了集体市场相关性的表观时间尺度

作者:Yuda Bi, Vince D Calhoun

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.14072

Abstract : We address the attribution problem for apparent slow collective dynamics  is the observed persistence intrinsic, or inherited from a persistent driver  For the leading eigenvalue fraction   psi 1  lambda   max  N  of S &P 500 60 day rolling correlation matrices ( 237  stocks, 2004  2023), a VIX coupled Ornstein  Uhlenbeck model reduces the effective relaxation time from  298  to  61  trading days and improves the fit over bare mean reversion by   Delta BIC  109 . On the decomposition sample, an informational residual of   log( mathrm VIX )  alone retains most of that gain (  Delta BIC  78.6 ), whereas a mechanical VIX proxy alone does not improve the fit. Autocorrelation matched placebo fields fail (  Delta BIC    max  2.7 ), disjoint weekly reconstructions still favor the field coupled model (  Delta BIC  140    151 ), and six anchored chronological holdouts preserve the out of sample advantage. Quiet regime and field stripped residual autocorrelation controls show the same collapse of persistence. Stronger hidden variable extensions remain only partially supported. Within the tested stochastic class, conditioning on the observed VIX proxy absorbs most of the apparent slow dynamics.

Keywords : 

Abstract :对于标准普尔500指数60天滚动相关矩阵（237只股票，2004-2023）的领先特征值分数psi 1 lambda max N，VIX耦合的Ornstein-Uhlenbeck模型将有效弛豫时间从298个交易日减少到61个交易日，并提高了Delta BIC 109对裸均值回归的拟合度。在分解样本上，单独的对数信息残差（mathm VIX）保留了大部分增益（Delta BIC 78.6），而单独的机械VIX代理并不能改善拟合。自相关匹配的安慰剂场失败（Delta-BIC最大2.7），不相交的每周重建仍然有利于场耦合模型（Delta-BCI 140 151），六个锚定的按时间顺序的坚持保留了样本外的优势。安静状态和场剥离残差自相关控制显示出相同的持久性崩溃。更强的隐藏变量扩展仅得到部分支持。在测试的随机类中，对观察到的VIX代理的条件作用吸收了大部分明显的缓慢动力学。

Keywords :

### 

\[8\] Curved Greeks

标题:曲线希腊人

作者:Pedro Pablo Pérez Velasco, Mengjue Lu, Daniel Arrieta

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.14438

Abstract : Short horizon option book management relies on P&L expansions in a small set of risk factors. In practice, the quadratic term and common desk adjustments (smile corrections, execution cost add ons) depend on the chosen factor coordinates, so predicted second order P&L can change when moving between spot, forward, and log forward parameterizations. We propose a local, model agnostic framework that makes the quadratic term coordinate invariant. The usual Hessian is replaced by a covariant Hessian defined by an affine connection, yielding an invariant quadratic predictor. The connection is calibrated to match a desk target for quadratic P&L (Vanna Volga for smile effects or, in principle, a local fit to realized P&L) while leaving first order hedge Greeks unchanged. Execution frictions enter through a quadratic cost model for hedge trades. Combined with hedge ratios, this induces an equivalent quadratic penalty on factor moves, makes portfolio netting of costs explicit, and provides local liquidity aware second order sensitivities and rebalancing directions. Calibration reduces to small linear systems with clear identifiability conditions. Two FX barrier case studies (EURUSD, USDTRY) illustrate the workflow, and we briefly sketch extensions to other quadratic penalties (risk normalization, scenario gap terms, and xVA capital add ons).

Keywords : 

Abstract :短期期权账簿管理依赖于一小部分风险因素的损益扩张。在实践中，二次项和常见的桌面调整（微笑校正、执行成本附加）取决于所选的因子坐标，因此预测的二阶损益在点、正向和对数正向参数化之间移动时可能会发生变化。我们提出了一个局部的、与模型无关的框架，使二次项坐标不变。通常的Hessian被仿射连接定义的协变Hessian所取代，从而得到一个不变的二次预测器。该连接经过校准，以匹配二次损益的桌面目标（Vanna Volga用于微笑效果，或者原则上用于实现损益的局部拟合），同时保持一阶对冲希腊不变。执行摩擦通过对冲交易的二次成本模型进入。结合对冲比率，这会对要素变动产生等效的二次惩罚，使投资组合的成本净额明确，并提供局部流动性感知的二阶敏感性和再平衡方向。校准简化为具有明确可识别条件的小型线性系统。两个外汇壁垒案例研究（欧元兑美元、美元兑土耳其里拉）说明了工作流程，我们简要概述了其他二次惩罚的扩展（风险归一化、情景缺口条款和xVA资本附加）。

Keywords :

### 

\[9\] E TRENDS

标题:E趋势

作者:Harris Buchanan, Eric Benhamou

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.14453

Abstract : Trend following strategies underpin many systematic trading approaches yet struggle under nonstationary and nonlinear market regimes. We propose an LSTM based framework to forecast next day trend differences (  Delta t ) for the top 30 S &P 500 equities, validated across market cycles (2005  2025). Key contributions include  (i) formal proof of bias variance reduction via differencing, (ii) exhaustive empirical benchmarks against OLS, Ridge, and Lasso, (iii) portfolio simulations confirming economic gains in terms of overall PNL compared to other models like OLS, Ridge, Lasso or LightGBM Regressor

Keywords : 

Abstract :趋势跟踪策略是许多系统交易方法的基础，但在非平稳和非线性的市场制度下却举步维艰。我们提出了一个基于LSTM的框架，用于预测标准普尔500指数前30只股票的次日趋势差异（Δt），并在整个市场周期（2005-2025）中进行了验证。主要贡献包括（i）通过差分减少偏差方差的正式证明，（ii）针对OLS、Ridge和Lasso的详尽经验基准，（iii）投资组合模拟，与OLS、Ridge、Lasso或LightGBM Regressor等其他模型相比，确认了总体PNL的经济收益

Keywords :

### 

\[10\] Tractable bank capital structure

标题:可追踪的银行资本结构

作者:Erhan Bayraktar, Etienne Chevalier, Vathana Ly Vath, Yuqiong Wang

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.14557

Abstract : Banks must optimize risky investments, dividend payouts, and capital structure under tight Basel III solvency and liquidity constraints, while costly equity issuance serves as a distress recovery tool. We formulate this as a stochastic control problem that reduces the high dimensional balance sheet dynamics to a tractable one dimensional process in the leverage ratio, with state dependent investment limits. The resulting policy is simple and interpretable  pay dividends at an upper reflection barrier and, when needed, recapitalize only at the distress boundary, jumping to a unique target level. We characterize these thresholds analytically and show their sensitivity to regulatory parameters. From a regulatory viewpoint, we solve an outer optimization problem that maps the efficient frontier between shareholder value and survival probability (via Monte Carlo), with and without leverage caps. Results highlight that tightening solvency requirements often yields the best safety profitability trade off.

Keywords : 

Abstract :银行必须在严格的巴塞尔协议III偿付能力和流动性约束下优化风险投资、股息支付和资本结构，而昂贵的股票发行则是一种困境恢复工具。我们将其表述为一个随机控制问题，该问题将高维资产负债表动态简化为杠杆率中可处理的一维过程，并具有状态依赖的投资限制。由此产生的政策很简单，可以解释，在较高的反射障碍下支付股息，并在需要时仅在困境边界进行资本重组，跳到一个独特的目标水平。我们对这些阈值进行了分析表征，并展示了它们对监管参数的敏感性。从监管的角度来看，我们解决了一个外部优化问题，该问题映射了股东价值和生存概率之间的有效边界（通过蒙特卡洛），有和没有杠杆上限。结果表明，收紧偿付能力要求通常会产生最佳的安全盈利权衡。

Keywords :

### 

\[11\] When Are Social Ties Associated with Strategic Behavior 

标题:社会关系何时与战略行为相关

作者:Nandini Maroo, Kavita Vemuri

来源:ARXIV\_20260318

链接:https://arxiv.org/pdf/2603.15700

Abstract : Social relationships are known to shape human behavior, yet when and how social ties influence strategic cognition remains unclear. We adopt a dual measure approach that combines observed gameplay behavior with elicitation of partner specific beliefs at each decision point, allowing us to examine how social ties shape both decisions and predictions across interaction structures. Dyads classified as having no ties, weak ties, or strong ties played three canonical economic games  the Dictator Game, Ultimatum Game, and Centipede Game, while also making predictions about their partner s actions. Using a mixed design that held partners constant across games while varying social distance between dyads, we examined how relational proximity affected the alignment between behavior and partner specific beliefs. Across two norm saturated games (Dictator and Ultimatum), neither offers nor belief calibration differed reliably by social distance. In contrast, in the sequential Centipede Game, where outcomes depend on anticipating a specific partner s future actions, strong tie dyads both cooperated longer and expected later termination than no tie dyads, with beliefs and behavior shifting in parallel. These results indicate that social ties become strategically relevant when the interaction structure makes partner specific accountability cognitively necessary, but not when behavior is governed primarily by shared norms or institutional constraints. The findings provide a structural account of when relational knowledge enters strategic cognition and help reconcile mixed results in prior work on social distance in economic games.

Keywords : 

Abstract :众所周知，社会关系会塑造人类行为，但社会关系何时以及如何影响战略认知尚不清楚。我们采用了一种双重衡量方法，将观察到的游戏行为与在每个决策点激发合作伙伴特定的信念相结合，使我们能够研究社会关系如何在互动结构中塑造决策和预测。被归类为无关系、弱关系或强关系的Dyads玩了三种典型的经济游戏——独裁者游戏、最后通牒游戏和蜈蚣游戏，同时也对伴侣的行为做出了预测。我们使用一种混合设计，在游戏中保持伴侣不变，同时改变二人组之间的社交距离，研究了关系接近度如何影响行为与伴侣特定信念之间的一致性。在两个规范饱和的游戏（独裁者和最后通牒）中，无论是报价还是信念校准，都不会因社会距离而产生可靠的差异。相比之下，在连续的蜈蚣游戏中，结果取决于对特定伴侣未来行为的预测，强关系二元比无关系二元合作的时间更长，预期更晚终止，信念和行为同时发生变化。这些结果表明，当互动结构使合作伙伴特定的问责制在认知上成为必要时，社会关系就变得具有战略相关性，但当行为主要受共同规范或制度约束时则不然。这些发现为关系知识何时进入战略认知提供了结构性解释，并有助于调和先前在经济博弈中关于社会距离的研究中的混合结果。

Keywords :

### 

\[12\] Playing Against the Machine

标题:与机器对抗

作者:Chowdhury Mohammad Sakib Anwar, Konstantinos Georgalos

来源:ARXIV\_20260318

链接:https://arxiv.org/pdf/2603.15852

Abstract : This paper investigates how natural language communication with an AI agent affects human cooperative behaviour in indefinitely repeated Prisoner s Dilemma games. We conduct a laboratory experiment (n   126) with two between subjects treatments varying whether human participants chat with an AI chatbot (GPT 5.2) before every round or only before the first round of each supergame, and benchmark against human human data from Dvorak and Fehrler (2024) (n   108). We find four main results. First, cooperation against the AI is high and initially comparable to human human levels, but unlike in the human human setting, where cooperation converges to near complete levels, cooperation against the AI plateaus and never reaches full cooperation. Second, repeated communication, which substantially increases cooperation in human human interactions, has no detectable effect in the human AI setting. Third, strategy estimation reveals that human AI subjects favour Grim Trigger under pre play communication and remain dispersed under repeated communication, whereas human human subjects converge to Tit for Tat and unconditional cooperation respectively. Fourth, human AI conversations contain more explicit strategy commitments but fewer emotional and social messages. These results suggest that humans cooperate with AI at high rates but do not develop the trust observed in human human interactions. Cooperation in the human AI setting is sustained through conditional rules rather than through the social bonds and mutual understanding that characterise human human cooperation.

Keywords : 

Abstract :本文研究了在无限重复的囚徒困境博弈中，与人工智能代理的自然语言交流如何影响人类的合作行为。我们进行了一项实验室实验（n 126），两种受试者之间的治疗方式各不相同，人类参与者是在每一轮之前与人工智能聊天机器人（GPT 5.2）聊天，还是仅在每个超级游戏的第一轮之前聊天，并与Dvorak和Fehrler（2024）的人类数据进行了基准比较（n 108）。我们发现了四个主要结果。首先，针对人工智能的合作程度很高，最初与人类水平相当，但与人类环境不同，在人类环境中，合作会收敛到接近完全的水平，针对AI的合作会停滞不前，永远不会达到完全合作。其次，重复的沟通大大增加了人与人之间的互动合作，但在人类人工智能环境中没有可检测到的影响。第三，策略估计表明，人类人工智能受试者在游戏前交流中更喜欢Grim Trigger，在重复交流中保持分散，而人类受试者分别为了Tat和无条件合作而收敛到Tit。第四，人类与人工智能的对话包含更明确的战略承诺，但情感和社会信息较少。这些结果表明，人类与人工智能的合作率很高，但并没有发展出在人机交互中观察到的信任。人类人工智能环境中的合作是通过有条件的规则来维持的，而不是通过人类合作所特有的社会纽带和相互理解来维持的。

Keywords :

### 

\[13\] Risk Based Auto Deleveraging

标题:基于风险的自动去杠杆化

作者:Steven Campbell, Natascha Hey, Ciamac C. Moallemi, Marcel Nutz

来源:ARXIV\_20260318

链接:https://arxiv.org/pdf/2603.15963

Abstract : Auto deleveraging (ADL) mechanisms are a critical yet understudied component of risk management on cryptocurrency futures exchanges. When available margin and other loss absorbing resources are insufficient to cover losses following large price moves, exchanges reduce positions and socialize losses among solvent participants via rule based ADL protocols.We formulate ADL as an optimization problem that minimizes the exchange s risk of loss arising from future equity shortfalls. In a single asset, isolated margin setting, we show that under a risk neutral expected loss objective the unique optimal policy minimizes the maximum leverage among participants. The resulting design has a transparent structure  positions are reduced first for the most highly levered accounts, and leverage is progressively equalized via a water filling (or   leverage draining  ) rule. This policy is distribution free, wash trade resistant, Sybil resistant, and path independent. It provides a canonical and implementable benchmark for ADL design and clarifies the economic logic underlying queue based mechanisms used in practice.We further study the multi asset, cross margin setting, where the ADL problem becomes genuinely multi dimensional  the exchange must allocate a vector of required reductions across accounts with portfolios exposed to correlated price moves. We show that under an expected loss objective the problem remains separable across accounts after introducing asset level shadow prices, yielding a scalable numerical method. We observe that naive gross leverage can be misleading in this context as it ignores hedging within portfolios. When asset prices are driven by a single dominant risk factor, the optimal policy again takes a water filling form, but now in a factor adjusted notion of leverage, so that more effectively hedged portfolios are deleveraged less aggressively.

Keywords : 

Abstract :自动去杠杆（ADL）机制是加密货币期货交易所风险管理中一个关键但研究不足的组成部分。当可用的保证金和其他损失吸收资源不足以弥补价格大幅波动后的损失时，交易所会减少头寸，并通过基于规则的ADL协议在有偿债能力的参与者之间将损失社会化。我们将ADL表述为一个优化问题，以最小化交易所因未来股权短缺而产生的损失风险。在单一资产、孤立的保证金设置中，我们表明，在风险中性的预期损失目标下，唯一的最优策略使参与者之间的最大杠杆最小化。由此产生的设计具有透明的结构，对于杠杆率最高的账户，首先减少头寸，并通过注水（或杠杆排水）规则逐步均衡杠杆率。这项政策是免分销、耐清洗贸易、耐Sybil和路径独立的。它为ADL设计提供了一个规范和可实现的基准，并阐明了实践中使用的基于队列的机制的经济逻辑。我们进一步研究了多资产、交叉保证金设置，在这种设置下，ADL问题变成了真正的多维问题——交易所必须在投资组合受到相关价格变动影响的账户之间分配一个所需的减持向量。我们证明，在预期损失目标下，在引入资产水平影子价格后，该问题在不同账户之间仍然是可分离的，从而产生了一种可扩展的数值方法。我们观察到，在这种情况下，天真的总杠杆率可能会产生误导，因为它忽略了投资组合中的对冲。当资产价格由单一主要风险因素驱动时，最优政策再次采取注水形式，但现在是一种经因素调整的杠杆概念，因此更有效的对冲投资组合的去杠杆化程度较低。

Keywords :

### 

\[14\] Open vs. Sealed

标题:打开与密封

作者:Aleksei Adadurov, Sergey Barseghyan, Anton Chtepine, Antero Eloranta, Andrei Sebyakin, Arsenii Valitov

来源:ARXIV\_20260318

链接:https://arxiv.org/pdf/2603.16333

Abstract : We study optimal auction design for Maximum Extractable Value (MEV) auction markets on Ethereum. Using a dataset of 2.2 million transactions across three major orderflow providers, we establish three empirical regularities  extracted values follow a log normal distribution with extreme right tail concentration, competition intensity varies substantially across MEV types, and the standard Revenue Equivalence Theorem breaks down due to affiliation among searchers  valuations. We model this affiliation through a Gaussian common factor, deriving equilibrium bidding strategies and expected revenues for five auction formats, first price sealed bid, second price sealed bid, English, Dutch, and all pay, across a fine grid of bidder counts  n  and affiliation parameters   rho . Our simulations confirm the Milgrom Weber linkage principle  English and second price sealed bid auctions strictly dominate Dutch and first price sealed bid formats for any   rho   0 , with a linkage gap of 14 28   at moderate affiliation (  rho 0.5 ) and up to 30   for small bidder counts. Applied to observed bribe totals, this gap corresponds to   10 18 million in foregone revenue over the sample period. We also document a novel non monotonicity  at large  n  and high   rho , revenue peaks in the interior of the affiliation parameter space and declines thereafter, as near perfect correlation collapses the order statistic spread that drives competitive payments.

Keywords : 

Abstract :我们研究了以太坊上最大可提取价值（MEV）拍卖市场的最优拍卖设计。使用三个主要订单流提供商的220万笔交易的数据集，我们建立了三个经验规律——提取的值遵循对数正态分布，具有极右尾集中，不同MEV类型的竞争强度差异很大，标准收入等价定理因搜索者估值之间的关联而失效。我们通过高斯公因子对这种关联进行建模，在投标人计数n和关联参数rho的精细网格中，推导出五种拍卖格式的均衡出价策略和预期收入，即第一价格密封出价、第二价格密封出价，英语、荷兰语和全付。我们的模拟证实了米尔格罗姆-韦伯联系原理——对于任何ρ0，英语和第二价格密封投标拍卖严格主导荷兰和第一价格密封投标格式，在中等关联度（ρ0.5）下，联系差距为1428，对于小投标人数量，联系差距高达30。应用于观察到的贿赂总额，这一差距相当于样本期内放弃的1018万美元收入。我们还记录了一个新的非单调性，在大n和高ρ下，收入在关联参数空间的内部达到峰值，此后下降，因为近乎完美的相关性会破坏驱动竞争性支付的顺序统计分布。

Keywords :

### 

\[15\] A Portfolio Anchored Frequency Severity Risk Index for Trip and Driver Assessment Using Telematics Signals

标题:基于远程信息处理信号的行程和驾驶员评估的组合锚定频率严重性风险指数

作者:Jongtaek Lee, Andrei Badescu, X. Sheldon Lin

来源:ARXIV\_20260318

链接:https://arxiv.org/pdf/2603.15839

Abstract : In this paper, we propose a novel frequency severity joint trip level risk index that combines the frequency of abnormal driving patterns with a severity component reflecting how extreme such behavior is relative to a portfolio level baseline. Severity is quantified through an inverse probability penalty that increases with the rarity of observed tail extremes, rather than being interpreted as a claim size. Based on high frequency telematics data, we construct a multi scale representation of longitudinal acceleration using the maximal overlap discrete wavelet transform (MODWT), which preserves localized driving patterns across multiple time scales. To capture severity as tail rarity, we model the portfolio distribution using a Gaussian Uniform mixture with a layered tail structure, where Gaussian components describe typical driving behavior and the tail is partitioned into ordered severity layers that reflect increasing extremeness. We develop a likelihood based estimation procedure that makes inference feasible for this mixture model. The resulting severity layers are then used to construct multi layer tail counts (MLTC) at the trip level, which are modeled within a Poisson Gamma framework to yield a closed form posterior risk index that jointly reflects frequency and severity. This conjugate structure naturally supports sequential updating, enabling the construction of dynamically evolving driver level risk profiles. Using the UAH DriveSet controlled dataset, we demonstrate that the proposed index enables reliable discrimination across behavioral driving states, identification of high risk trips, and coherent ranking of drivers, yielding a purely behavior driven risk measure suitable for actuarial ratemaking and potentially mitigating fairness concerns associated with traditional covariates.

Keywords : 

Abstract :在这篇论文中，我们提出了一种新的频率-严重程度联合出行水平风险指数，该指数将异常驾驶模式的频率与严重程度分量相结合，反映了这种行为相对于投资组合水平基线的极端程度。严重性是通过逆概率惩罚来量化的，该惩罚随着观察到的尾部极值的罕见程度而增加，而不是被解释为索赔规模。基于高频远程信息处理数据，我们使用最大重叠离散小波变换（MODWT）构建了纵向加速度的多尺度表示，该变换在多个时间尺度上保留了局部驾驶模式。为了将严重性视为尾部稀有性，我们使用具有分层尾部结构的高斯均匀混合来对投资组合分布进行建模，其中高斯分量描述了典型的驾驶行为，尾部被划分为反映极值增加的有序严重性层。我们开发了一种基于似然的估计方法，使这种混合模型的推理可行。然后，将得到的严重程度层用于在行程级别构建多层尾部计数（MLTC），在泊松-伽玛框架内对其进行建模，以产生一个联合反映频率和严重程度的封闭形式后验风险指数。这种共轭结构自然支持顺序更新，从而能够构建动态演变的驾驶员级风险档案。使用UAH DriveSet控制的数据集，我们证明了所提出的指数能够可靠地区分行为驾驶状态，识别高风险出行，并对驾驶员进行连贯的排名，从而产生了一种纯粹的行为驱动风险度量，适用于精算评价，并可能减轻与传统协变量相关的公平性问题。

Keywords :

### 

\[16\] LR Robot

标题:LR机器人

作者:Wei Wei, Jin Zheng, Zining Wang

来源:ARXIV\_20260319

链接:https://arxiv.org/pdf/2603.17723

Abstract : Recent advances in artificial intelligence (AI) and natural language processing (NLP) have enabled tools to support systematic literature reviews (SLRs), yet existing frameworks often produce outputs that are efficient but contextually limited, requiring substantial expert this http URL framework employs a human in the loop process to define sub SLR tasks, evaluate models, and ensure methodological rigor, while leveraging structured knowledge sources and retrieval augmented generation (RAG) to enhance factual grounding and transparency. LR Robot enables multidimensional categorization of research, maps relationships among papers, identifies high impact works, and supports historical, fine grained analyses of topic evolution. We demonstrate the framework using an option pricing case study, enabling comprehensive literature analysis. Empirical results reveal the current capabilities of AI in understanding and synthesizing literature, uncover emerging trends, reveal topic connections, and highlight core research directions. By accelerating labor intensive review stages while preserving interpretive accuracy, LR Robot provides a practical, customizable, and high quality approach for AI assisted SLRs. Key contributions  (1) a novel framework combining AI and expert supervision for contextually informed SLRs, (2) support for multidimensional categorization, relationship mapping, and fine grained topic evolution analysis, and (3) empirical demonstration of AI driven literature synthesis in the field of option pricing.

Keywords : 

Abstract :人工智能（AI）和自然语言处理（NLP）的最新进展使工具能够支持系统文献综述（SLR），但现有的框架通常会产生高效但上下文有限的输出，需要大量的专家。这种http URL框架采用人工在环过程来定义子SLR任务、评估模型并确保方法的严谨性，同时利用结构化知识源和检索增强生成（RAG）来增强事实基础和透明度。LR Robot能够对研究进行多维分类，绘制论文之间的关系图，识别高影响力的作品，并支持对主题演变的历史、细粒度分析。我们使用期权定价案例研究来演示该框架，从而进行全面的文献分析。实证结果揭示了人工智能在理解和综合文献方面的当前能力，揭示了新兴趋势，揭示了主题联系，并突出了核心研究方向。通过加快劳动密集型审查阶段，同时保持解释准确性，LR Robot为人工智能辅助单反相机提供了一种实用、可定制和高质量的方法。主要贡献：（1）一个结合人工智能和专家监督的新框架，用于情境知情的SLR；（2）支持多维分类、关系映射和细粒度主题演化分析；（3）期权定价领域人工智能驱动的文献综合的实证演示。

Keywords :