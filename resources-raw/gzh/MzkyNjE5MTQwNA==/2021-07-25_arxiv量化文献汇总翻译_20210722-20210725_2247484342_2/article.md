# arxiv量化文献汇总翻译 20210722-20210725

Shame1ess 量化前沿速递 2021-07-25 18:15

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484342&idx=2&sn=dfa92d507779e92997a3623af7fb406a&chksm=c34b8cb4244b7afd37d4e1a7257eece5169f174f63113d591f4f37726b50568744e41cc5e8d3#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484342&idx=2&sn=dfa92d507779e92997a3623af7fb406a&chksm=c34b8cb4244b7afd37d4e1a7257eece5169f174f63113d591f4f37726b50568744e41cc5e8d3#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] A Sparsity Algorithm with Applications to Corporate Credit Rating

稀疏算法及其在企业信用评级中的应用

\[2\] Everything You Always Wanted to Know About XVA Model Risk but Were Afraid to Ask

所有你一直想知道的关于XVA模型风险，但不敢问

\[3\] Time Varying Risk in U.S. Housing Sector and Real Estate Investment Trusts Equity Return

美国房地产行业的时变风险和房地产投资信托基金的股权收益

\[4\] A Stochastic Control Approach to Public Debt Management

公共债务管理的随机控制方法

\[5\] cCorrGAN

科根

\[6\] Capital Requirements and Claims Recovery

资本要求和索赔回收

\[7\] Of Access and Inclusivity Digital Divide in Online Education

数字鸿沟在网络教育中的可及性分析

\[8\] A Time Varying Network for Cryptocurrencies

加密货币的时变网络

\[9\] Financial Network Games

金融网络游戏

\[10\] Hodge theoretic reward allocation for generalized cooperative games on graphs

图上广义合作对策的Hodge理论报酬分配

\[11\] Factors determining maximum energy consumption of Bitcoin miners

比特币矿工最大能耗的决定因素

\[12\] Forecasting performance of workforce reskilling programmes

劳动力再培训计划绩效预测

\[13\] Pricing Exchange Option Based on Copulas by MCMC Algorithm

基于Copulas的MCMC算法的交换期权定价

\[14\] Default Distances Based on the KMV CEV Model

基于KMV-CEV模型的默认距离

## 

\[1\] A Sparsity Algorithm with Applications to Corporate Credit Rating

标题 : 稀疏算法及其在企业信用评级中的应用

作者 : Dan Wang, Zhi Chen, Ionut Florescu , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2107.10306

说明 : Comments: 16 pages, 11 tables, 3 figures

Abstract : In Artificial Intelligence, interpreting the results of a Machine Learning technique often termed as a black box is a difficult task. A counterfactual explanation of a particular black box attempts to find the smallest change to the input values that modifies the prediction to a particular output, other than the original one. In this work we formulate the problem of finding a counterfactual explanation as an optimization problem. We propose a new sparsity algorithm which solves the optimization problem, while also maximizing the sparsity of the counterfactual explanation. We apply the sparsity algorithm to provide a simple suggestion to publicly traded companies in order to improve their credit ratings. We validate the sparsity algorithm with a synthetically generated dataset and we further apply it to quarterly financial statements from companies in financial, healthcare and IT sectors of the US market. We provide evidence that the counterfactual explanation can capture the nature of the real statement features that changed between the current quarter and the following quarter when ratings improved. The empirical results show that the higher the rating of a company the greater the effort required to further improve credit rating.

摘要 : 在人工智能中，解释通常被称为黑盒的机器学习技术的结果是一项困难的任务。对一个特定黑匣子的反事实解释试图找出对输入值的最小变化，从而修改对一个特定输出的预测，而不是原来的预测。在这项工作中，我们制定的问题，寻找一个反事实的解释作为一个优化问题。我们提出了一种新的稀疏算法来解决优化问题，同时最大限度地提高了反事实解释的稀疏性。为了提高上市公司的信用评级，我们应用稀疏性算法为上市公司提供了一个简单的建议。我们用一个综合生成的数据集验证了稀疏性算法，并将其进一步应用于美国金融、医疗和it行业公司的季度财务报表。我们提供的证据表明，当评级提高时，反事实解释可以捕捉到当前季度和下一季度之间发生变化的真实报表特征的性质。实证结果表明，公司评级越高，进一步提高信用评级所需的努力就越大。

## 

\[2\] Everything You Always Wanted to Know About XVA Model Risk but Were Afraid to Ask

标题 : 所有你一直想知道的关于XVA模型风险，但不敢问

作者 : Lorenzo Silotto, Marco Scaringi, Marco Bianchetti , 类别 ：Pricing of Securities (q-fin.PR)

链接 : https://arxiv.org/pdf/2107.10377

说明 : Comments: 59 pages, 15 figures, 16 tables, 43 references

Abstract : Valuation adjustments, collectively named XVA, play an important role in modern derivatives pricing. XVA are an exotic pricing component since they require the forward simulation of multiple risk factors in order to compute the portfolio exposure including collateral, leading to a significant model risk and computational effort, even in case of plain vanilla trades. This work analyses the most critical model risk factors, meant as those to which XVA are most sensitive, finding an acceptable compromise between accuracy and performance. This task has been conducted in a complete context including a market standard multi curve G2 model calibrated on real market data, both Variation Margin and ISDA SIMM dynamic Initial Margin, different collateralization schemes, and the most common linear and non linear interest rates derivatives. Moreover, we considered an alternative analytical approach for XVA in case of uncollateralized Swaps. We show that a crucial element is the construction of a parsimonious time grid capable of capturing all periodical spikes arising in collateralized exposure during the Margin Period of Risk. To this end, we propose a workaround to efficiently capture all spikes. Moreover, we show that there exists a parameterization which allows to obtain accurate results in a reasonable time, which is a very important feature for practical applications. In order to address the valuation uncertainty linked to the existence of a range of different parameterizations, we calculate the Model Risk AVA (Additional Valuation Adjustment) for XVA according to the provisions of the EU Prudent Valuation regulation. Finally, this work can serve as an handbook containing step by step instructions for the implementation of a complete, realistic and robust modelling framework of collateralized exposure and XVA.

摘要 : 估值调整，统称XVA，在现代衍生品定价中发挥着重要作用。XVA是一种奇特的定价组件，因为它们需要对多个风险因素进行正向模拟，以便计算包括抵押品在内的投资组合风险敞口，从而导致重大的模型风险和计算工作，即使在普通交易的情况下也是如此。这项工作分析了最关键的模型风险因素，即XVA最敏感的风险因素，在准确性和性能之间找到了一个可接受的折衷方案。这项任务是在一个完整的背景下进行的，包括根据实际市场数据校准的市场标准多曲线G2模型、变动保证金和ISDA SIMM动态初始保证金、不同的抵押方案以及最常见的线性和非线性利率衍生品。此外，我们考虑了在无抵押掉期的情况下XVA的另一种分析方法。我们表明，一个关键的因素是建立一个节俭的时间网格，能够捕捉风险保证金期间担保敞口中出现的所有周期性峰值。为此，我们提出了一种有效捕获所有峰值的解决方法。此外，我们还证明了存在一个参数化，它允许在合理的时间内获得准确的结果，这对于实际应用是非常重要的。为了解决与存在一系列不同参数化有关的估值不确定性，我们根据欧盟审慎估值条例的规定，计算了XVA的模型风险AVA（额外估值调整）。最后，这项工作可以作为一个手册，包含一个完整的，现实的和稳健的担保风险敞口和XVA建模框架的实施步骤说明。

## 

\[3\] Time Varying Risk in U.S. Housing Sector and Real Estate Investment Trusts Equity Return

标题 : 美国房地产行业的时变风险和房地产投资信托基金的股权收益

作者 : Masud Alam , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2107.10455

说明 : Comments: 53 pages

Abstract : This study examines how housing sector volatilities affect real estate investment trust (REIT) equity return in the United States. I argue that unexpected changes in housing variables can be a source of aggregate housing risk, and the first principal component extracted from the volatilities of U.S. housing variables can predict the expected REIT equity returns. I propose and construct a factor based housing risk index as an additional factor in asset price models that uses the time varying conditional volatility of housing variables within the U.S. housing sector. The findings show that the proposed housing risk index is economically and theoretically consistent with the risk return relationship of the conditional Intertemporal Capital Asset Pricing Model (ICAPM) of Merton (1973), which predicts an average maximum of 5.6 percent of risk premium in REIT equity return. In subsample analyses, the positive relationship is not affected by sample periods choice but shows higher housing risk beta values for the 2009 18 sample period. The relationship remains significant after controlling for VIX, Fama French three factors, and a broad set of macroeconomic and financial variables. Moreover, the proposed housing beta also accurately forecasts U.S. macroeconomic and financial conditions.

摘要 : 本研究旨在探讨美国房地产业的波动性如何影响房地产投资信托（REIT）的权益回报。我认为，住房变量的意外变化可能是总住房风险的一个来源，从美国住房变量的波动性中提取的第一个主成分可以预测预期的房地产投资信托基金股票收益。我提出并构建了一个基于因素的住房风险指数，作为资产价格模型中的一个附加因素，该模型利用了美国住房行业住房变量随时间变化的条件波动性。研究结果表明，所提出的住房风险指数与Merton（1973）的条件跨期资本资产定价模型（ICAPM）的风险收益关系在经济上和理论上是一致的，该模型预测REIT股权收益的风险溢价平均最高可达5.6%。在子样本分析中，正相关关系不受样本期选择的影响，但显示2009年18个样本期的住房风险β值较高。在控制了波动率、法玛-法兰西三个因素以及一系列宏观经济和金融变量后，这种关系仍然显著。此外，拟议中的房地产贝塔也准确预测了美国宏观经济和金融状况。

## 

\[4\] A Stochastic Control Approach to Public Debt Management

标题 : 公共债务管理的随机控制方法

作者 : Matteo Brachetta, Claudia Ceci , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2107.10491

说明 : Comments: 26 pages

Abstract : We discuss a class of debt management problems in a stochastic environment model. We propose a model for the debt to GDP (Gross Domestic Product) ratio where the government interventions via fiscal policies affect the public debt and the GDP growth rate at the same time. We allow for stochastic interest rate and possible correlation with the GDP growth rate through the dependence of both the processes (interest rate and GDP growth rate) on a stochastic factor which may represent any relevant macroeconomic variable, such as the state of economy. We tackle the problem of a government whose goal is to determine the fiscal policy in order to minimize a general functional cost. We prove that the value function is a viscosity solution to the Hamilton Jacobi Bellman equation and provide a Verification Theorem based on classical solutions. We investigate the form of the candidate optimal fiscal policy in many cases of interest, providing interesting policy insights. Finally, we discuss two applications to the debt reduction problem and debt smoothing, providing explicit expressions of the value function and the optimal policy in some special cases.

摘要 : 讨论了一类随机环境下的债务管理问题。我们提出了一个债务与GDP（GDP）比率的模型，其中政府通过财政政策的干预同时影响公共债务和GDP增长率。我们考虑了随机利率和可能与GDP增长率的相关性，通过这两个过程（利率和GDP增长率）对一个随机因素的依赖，这个随机因素可能代表任何相关的宏观经济变量，如经济状况。我们要解决的问题是一个政府的目标是确定财政政策，以尽量减少一般功能成本。证明了该值函数是Hamilton-Jacobi-Bellman方程的粘性解，并在经典解的基础上给出了一个验证定理。我们研究了在许多感兴趣的案例中，候选最优财政政策的形式，提供了有趣的政策见解。最后，我们讨论了债务削减问题和债务平滑问题的两个应用，给出了在某些特殊情况下价值函数和最优策略的显式表达式。

## 

\[5\] cCorrGAN

标题 : 科根

作者 : Gautier Marti, Victor Goubet, Frank Nielsen , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2107.10606

说明 : Comments: International Conference on Geometric Science of Information

Abstract : We propose a methodology to approximate conditional distributions in the elliptope of correlation matrices based on conditional generative adversarial networks. We illustrate the methodology with an application from quantitative finance Monte Carlo simulations of correlated returns to compare risk based portfolio construction methods. Finally, we discuss about current limitations and advocate for further exploration of the elliptope geometry to improve results.

摘要 : 本文提出了一种基于条件生成对抗网络的相关矩阵椭圆型中条件分布的近似方法。我们用定量金融蒙特卡罗模拟相关收益来比较基于风险的投资组合构建方法来说明该方法。最后，我们讨论了目前的局限性，并主张进一步探索椭圆几何以改进结果。

## 

\[6\] Capital Requirements and Claims Recovery

标题 : 资本要求和索赔回收

作者 : Cosimo Munari, Lutz Wilhelmy, Stefan Weber , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2107.10635

说明 : -

Abstract : Protection of creditors is a key objective of financial regulation. Where the protection needs are high, i.e., in banking and insurance, regulatory solvency requirements are an instrument to prevent that creditors incur losses on their claims. The current regulatory requirements based on Value at Risk and Average Value at Risk limit the probability of default of financial institutions, but they fail to control the size of recovery on creditors claims in the case of default. We resolve this failure by developing a novel risk measure, Recovery Value at Risk. Our conceptual approach can flexibly be extended and allows the construction of general recovery risk measures for various risk management purposes. By design, these risk measures control recovery on creditors claims and integrate the protection needs of creditors into the incentive structure of the management. We provide detailed case studies and applications We analyze how recovery risk measures react to the joint distributions of assets and liabilities on firms balance sheets and compare the corresponding capital requirements with the current regulatory benchmarks based on Value at Risk and Average Value at Risk. We discuss how to calibrate recovery risk measures to historic regulatory standards. Finally, we show that recovery risk measures can be applied to performance based management of business divisions of firms and that they allow for a tractable characterization of optimal tradeoffs between risk and return in the context of investment management.

摘要 : 保护债权人是金融监管的一个关键目标。在保护需求很高的情况下，即在银行业和保险业，偿付能力监管要求是防止债权人因其债权遭受损失的一种手段。现行基于风险价值和平均风险价值的监管要求限制了金融机构违约的概率，但未能控制违约情况下债权人债权的收回规模。我们通过开发一种新的风险度量方法，即风险恢复值来解决这一问题。我们的概念方法可以灵活扩展，并允许为各种风险管理目的构建一般的恢复风险措施。通过设计，这些风险措施控制了债权人债权的收回，并将债权人的保护需要纳入管理层的激励结构中。我们提供了详细的案例研究和应用我们分析了恢复风险措施对企业资产负债表上资产和负债联合分配的反应，并将相应的资本要求与基于风险价值和平均风险价值的现行监管基准进行了比较。我们将讨论如何根据历史监管标准校准恢复风险度量。最后，我们证明了恢复风险度量可以应用于公司业务部门的绩效管理，并且它们允许在投资管理的背景下对风险和回报之间的最佳权衡进行易于处理的描述。

## 

\[7\] Of Access and Inclusivity Digital Divide in Online Education

标题 : 数字鸿沟在网络教育中的可及性分析

作者 : Bheemeshwar Reddy A, Sunny Jose, Vaidehi R , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2107.10723

说明 : -

Abstract : Can online education enable all students to participate in and benefit from it equally Massive online education without addressing the huge access gap and disparities in digital infrastructure would not only exclude a vast majority of students from learning opportunities but also exacerbate the existing socio economic disparities in educational opportunities.

摘要 : 在线教育能否使所有学生都能参与并受益于同样大规模的在线教育，而不解决数字基础设施方面的巨大差距和差距，不仅会使绝大多数学生失去学习机会，而且还会加剧教育领域现有的社会经济差距机会。

## 

\[8\] A Time Varying Network for Cryptocurrencies

标题 : 加密货币的时变网络

作者 : Li Guo, Wolfgang Karl H rdle, Yubo Tao , 类别 ：Methodology (stat.ME)

链接 : https://arxiv.org/pdf/1802.03708

说明 : Comments: 43 pages, 6 figures, 7 tables

Abstract : Cryptocurrencies return cross predictability and technological similarity yield information on risk propagation and market segmentation. To investigate these effects, we build a time varying network for cryptocurrencies, based on the evolution of return cross predictability and technological similarities. We develop a dynamic covariate assisted spectral clustering method to consistently estimate the latent community structure of cryptocurrencies network that accounts for both sets of information. We demonstrate that investors can achieve better risk diversification by investing in cryptocurrencies from different communities. A cross sectional portfolio that implements an inter crypto momentum trading strategy earns a 1.08 daily return. By dissecting the portfolio returns on behavioral factors, we confirm that our results are not driven by behavioral mechanisms.

摘要 : 加密货币返回交叉可预测性和技术相似性，产生关于风险传播和市场细分的信息。为了研究这些影响，我们建立了一个基于收益交叉可预测性和技术相似性演化的加密货币时变网络。我们发展了一种动态协变量辅助的谱聚类方法来一致地估计加密货币网络的潜在社区结构，该网络同时考虑了这两组信息。我们证明投资者可以通过投资不同社区的加密货币来实现更好的风险分散。实施跨加密动量交易策略的横截面投资组合的日回报率为1.08。通过剖析行为因素的投资组合收益，我们证实了我们的结果不是由行为机制驱动的。

## 

\[9\] Financial Network Games

标题 : 金融网络游戏

作者 : Panagiotis Kanellopoulos, Maria Kyropoulou, Hao Zhou , 类别 ：Computer Science and Game Theory (cs.GT)

链接 : https://arxiv.org/pdf/2107.06623

说明 : -

Abstract : We study financial systems from a game theoretic standpoint. A financial system is represented by a network, where nodes correspond to firms, and directed labeled edges correspond to debt contracts between them. The existence of cycles in the network indicates that a payment of a firm to one of its lenders might result to some incoming payment. So, if a firm cannot fully repay its debt, then the exact (partial) payments it makes to each of its creditors can affect the cash inflow back to itself. We naturally assume that the firms are interested in their financial well being (utility) which is aligned with the amount of incoming payments they receive from the network. This defines a game among the firms, that can be seen as utility maximizing agents who can strategize over their payments. We are the first to study financial network games that arise under a natural set of payment strategies called priority proportional payments. We investigate the existence and (in)efficiency of equilibrium strategies, under different assumptions on how the firms utility is defined, on the types of debt contracts allowed between the firms, and on the presence of other financial features that commonly arise in practice. Surprisingly, even if all firms strategies are fixed, the existence of a unique payment profile is not guaranteed. So, we also investigate the existence and computation of valid payment profiles for fixed payment strategies.

摘要 : 我们从博弈论的角度研究金融系统。一个金融系统由一个网络来表示，其中节点对应于企业，而有向标记边对应于企业之间的债务契约。网络中周期的存在表明，企业向其贷方之一付款可能会产生一些收入。因此，如果一家公司不能完全偿还债务，那么它向每个债权人支付的确切（部分）款项可能会影响现金流入。我们自然而然地假设，公司对他们的财务状况（效用）感兴趣，这与他们从网络收到的收入相一致。这定义了企业之间的博弈，可以看作是效用最大化的代理人，他们可以制定支付策略。我们是第一个研究金融网络游戏下出现的一套自然的支付策略称为优先比例支付。我们研究了均衡策略的存在性和效率，在不同的假设条件下，企业效用是如何定义的，企业之间允许的债务契约类型，以及实践中常见的其他金融特征。令人惊讶的是，即使所有公司的策略都是固定的，也不能保证存在唯一的支付模式。因此，我们也研究了固定支付策略有效支付模式的存在性和计算。

## 

\[10\] Hodge theoretic reward allocation for generalized cooperative games on graphs

标题 : 图上广义合作对策的Hodge理论报酬分配

作者 : Tongseok Lim , 类别 ：Probability (math.PR)

链接 : https://arxiv.org/pdf/2107.10510

说明 : -

Abstract : We define cooperative games on general graphs and generalize Lloyd S. Shapley s celebrated allocation formula for those games in terms of stochastic path integral driven by the associated Markov chain on each graph. We then show that the value allocation operator, one for each player defined by the stochastic path integral, coincides with the player s component game which is the solution to the least squares (or Poisson s) equation, in light of the combinatorial Hodge decomposition on general weighted graphs. Several motivational examples and applications are also presented.

摘要 : 定义了一般图上的合作对策，推广了lloyds。Shapley关于这些博弈的著名分配公式是由每个图上相关的Markov链驱动的随机路径积分。根据一般加权图上的组合Hodge分解，我们证明了由随机路径积分定义的每个参与方一个值分配算子与参与方的分量对策（即最小二乘（Poisson）方程的解）是一致的。文中还介绍了一些激励性的例子和应用。

## 

\[11\] Factors determining maximum energy consumption of Bitcoin miners

标题 : 比特币矿工最大能耗的决定因素

作者 : Jesus M. Gonzalez-Barahona , 类别 ：Cryptography and Security (cs.CR)

链接 : https://arxiv.org/pdf/2107.10634

说明 : Comments: 24 pages, request for comments

Abstract : Background During the last years, there has been a lot of discussion and estimations on the energy consumption of Bitcoin miners. However, most of the studies are focused on estimating energy consumption, not in exploring the factors that determine it. Goal To explore the factors that determine maximum energy consumption of Bitcoin miners. In particular, analyze the limits of energy consumption, and to which extent variations of the factors could produce its reduction. Method Estimate the overall profit of all Bitcoin miners during a certain period of time, and the costs (including energy) that they face during that time, because of the mining activity. The underlying assumptions is that miners will only consume energy to mine Bitcoin if they have the expectation of profit, and at the same time they are competitive with respect of each other. Therefore, they will operate as a group in the point where profits balance expenditures. Results We show a basic equation that determines energy consumption based on some specific factors minting, transaction fees, exchange rate, energy price, and amortization cost. We also define the Amortization Factor, which can be computed for mining devices based on their cost and energy consumption, helps to understand how the cost of equipment influences total energy consumption. Conclusions The factors driving energy consumption are identified, and from them, some ways in which Bitcoin energy consumption could be reduced are discussed. Some of these ways do not reduce the most important properties of Bitcoin, such as the chances of control of the aggregated hashpower, or the fundamentals of the proof of work mechanism. In general, the methods presented can help to predict energy consumption in different scenarios, based on factors that can be calculated from available data, or assumed in scenarios.

摘要 : 背景在过去的几年里，人们对比特币矿工的能源消耗进行了大量的讨论和估算。然而，大多数研究都集中在估计能源消耗上，而不是探讨决定能源消耗的因素。目的探讨影响比特币矿工最大能量消耗的因素。特别是，分析能源消耗的限制，以及在多大程度上变化的因素可以产生其减少。该方法估计了在一定时期内所有比特币矿工的总体利润，以及他们在这段时间内由于采矿活动而面临的成本（包括能源）。其基本假设是，只有当矿商对利润有预期，同时在相互尊重方面具有竞争力时，他们才会消耗能源开采比特币。因此，他们将作为一个群体在利润平衡支出的点上运作。结果我们给出了一个基本方程，确定能源消耗的一些具体因素的基础上铸造，交易费用，汇率，能源价格和摊销成本。我们还定义了可根据采矿设备的成本和能耗计算的摊销系数，有助于了解设备成本如何影响总能耗。结论找出了影响比特币能耗的因素，并从中探讨了降低比特币能耗的途径。其中一些方法并没有减少比特币最重要的特性，比如控制聚合hashpower的机会，或者工作证明机制的基本原理。一般来说，所提出的方法有助于根据可用数据计算或假设的因素预测不同情景下的能源消耗。

## 

\[12\] Forecasting performance of workforce reskilling programmes

标题 : 劳动力再培训计划绩效预测

作者 : Evan Hurwitz, George Cevora , 类别 ：General Finance (q-fin.GN)

链接 : https://arxiv.org/pdf/2107.10001

说明 : -

Abstract : Estimating success rates for programmes aiming to reintegrate theunemployed into the workforce is essential for good stewardship of publicfinances. At the current moment, the methods used for this task arebased on the historical performance of comparable programmes. In lightof Brexit and Covid 19 simultaneously causing a shock to the labourmarket in the UK we developed an estimation method that is basedon fundamental factors involved workforce demand and supply asopposed to the historical values which are quickly becoming irrelevant.With an average error of 3.9 of the re integration success rate, ourmodel outperforms the best benchmark known to us by 53

摘要 : 估计旨在使失业者重新融入劳动力队伍的方案的成功率对于良好管理公共财政至关重要。目前，用于这项任务的方法是基于可比方案的历史表现。鉴于英国脱欧和Covid 19同时对英国劳动力市场造成冲击，我们开发了一种估算方法，该方法基于劳动力需求和供给等基本因素，与迅速变得不相关的历史值相对应。重新整合成功率的平均误差为3.9，我们的模型比我们已知的最好的基准高出53%

## 

\[13\] Pricing Exchange Option Based on Copulas by MCMC Algorithm

标题 : 基于Copulas的MCMC算法的交换期权定价

作者 : Wen Su , 类别 ：Mathematical Finance (q-fin.MF)

链接 : https://arxiv.org/pdf/2107.10225

说明 : -

Abstract : This paper focus on pricing exchange option based on copulas by MCMC algorithm. Initially, we introduce the methodologies concerned about risk netural pricing, copulas and MCMC algorithm. After the basic knowledge, we compare the option prices given by different models, the results show except Gumbel copula, the other model provide similar estimation.

摘要 : 本文采用MCMC算法对基于copulas的交换期权进行定价。本文首先介绍了风险网络定价方法、copulas方法和MCMC算法。在基本知识的基础上，对不同模型给出的期权价格进行了比较，结果表明，除了Gumbel copula模型外，其他模型给出了相似的估计。

## 

\[14\] Default Distances Based on the KMV CEV Model

标题 : 基于KMV-CEV模型的默认距离

作者 : Wen Su , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2107.10226

说明 : -

Abstract : This paper presents a new method to assess default risk based on applying non constant volatility to the KMV model, taking the CEV model as an instance. We find the evidence that the classical KMV model could not distinguish ST companies in China stock market. Aiming at improve the accuracy of the KMV model, we assume the firm s asset value dynamics are given by the CEV process frac dV A V A mu A dt delta V A beta 1 dB and use fixed effects model and equivalent volatility method to estimate parameters. The estimation results show the beta 1 for non ST companies while beta 1 for ST companies and the equivalent volatility method estimate the parameters much more precisely. Compared with the classical KMV model, our CEV KMV model fits the market better in forecasting the default probability. We also provide an insight that other volatility model can be applied, too.

摘要 : 本文以CEV模型为例，将非常数波动率应用于KMV模型，提出了一种新的违约风险评估方法。我们发现经典KMV模型不能区分中国股市中的ST公司。为了提高KMV模型的精度，我们假设企业的资产价值动态由CEV过程frac dV A V A mu A dt delta V A beta 1 dB给出，并使用固定效应模型和等效波动率方法估计参数。估计结果表明，非ST公司的beta-1估计值比ST公司的beta-1估计值和等效波动率法的估计值要精确得多。与经典的KMV模型相比，CEV-KMV模型在预测违约概率方面更符合市场。我们还提供了一个洞察，其他波动率模型也可以应用。