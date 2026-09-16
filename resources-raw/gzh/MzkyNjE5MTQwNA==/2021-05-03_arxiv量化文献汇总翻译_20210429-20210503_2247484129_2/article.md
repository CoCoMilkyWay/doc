# arxiv量化文献汇总翻译 20210429-20210503

Shame1ess 量化前沿速递 2021-05-03 22:30

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484129&idx=2&sn=ba21081a7086a3d7fd19d528fe252033&chksm=c33dfe05efc4e83a3ade64c3310b03a83f050401a0eebb2ad6e1708ce0c18b31674a344bf20f#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484129&idx=2&sn=ba21081a7086a3d7fd19d528fe252033&chksm=c33dfe05efc4e83a3ade64c3310b03a83f050401a0eebb2ad6e1708ce0c18b31674a344bf20f#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Optimal Execution with Quadratic Variation Inventories

二次变量库存的最优执行

\[2\] Deep Reinforcement Trading with Predictable Returns

可预测回报的深度强化交易

\[3\] Driver Positioning and Incentive Budgeting with an Escrow Mechanism for Ridesharing Platforms

基于共享平台托管机制的驾驶员定位和激励预算

\[4\] Modelling Net Loan Loss with Bayesian and Frequentist Regression Analysis

基于贝叶斯和频数回归分析的贷款净损失建模

\[5\] Applying Convolutional Neural Networks for Stock Market Trends Identification

卷积神经网络在股市走势识别中的应用

\[6\] Modeling Managerial Search Behavior based on Simon s Concept of Satisficing

基于Simon满意概念的管理者搜索行为建模

\[7\] Where to Refuel

在哪里加油

\[8\] The role of Common Agricultural Policy (CAP) in enhancing and stabilising farm income

共同农业政策在提高和稳定农民收入中的作用

\[9\] FX Market Volatility

外汇市场波动

\[10\] The impact of past pandemics on CO 2 emissions and transition to renewable energy

过去大流行对二氧化碳排放的影响及向可再生能源的过渡

\[11\] Optimal bidding on hourly and quarter hourly day ahead electricity price auctions

小时和季度小时日前电价拍卖的最优竞价

\[12\] Stakeholder dynamics in residential solar energy adoption

住宅太阳能利用中的利益相关者动态

\[13\] Prediction of Food Production Using Machine Learning Algorithms of Multilayer Perceptron and ANFIS

基于多层感知器和ANFIS机器学习算法的粮食产量预测

\[14\] The Effect of Marketing Investment on Firm Value and Systematic Risk

营销投资对企业价值和系统风险的影响

\[15\] Sparse Grid Method for Highly Efficient Computation of Exposures for xVA

xVA曝光量高效计算的稀疏网格法

\[16\] Nonparametric Test for Volatility in Clustered Multiple Time Series

聚类多时间序列波动性的非参数检验

\[17\] Regional poverty in Bulgaria in the period 2008 2019

2008-2019年保加利亚地区贫困状况

\[18\] State capacity and vulnerability to natural disasters

国家承受自然灾害的能力和脆弱性

\[19\] A Review of Disease and Development

疾病与发展综述

\[20\] Social Norms Offer Explanation for Inconsistent Effects of Incentives on Prosocial Behavior

社会规范解释了激励对亲社会行为的不一致影响

\[21\] The Future of Employment Revisited

重新审视就业的未来

\[22\] Optimal Stopping via Randomized Neural Networks

基于随机神经网络的最优停车

## 

\[1\] Optimal Execution with Quadratic Variation Inventories

标题 : 二次变量库存的最优执行

作者 : Rene Carmona, Laura Leal , 类别 ：Trading and Market Microstructure (q-fin.TR)

链接 : https://arxiv.org/pdf/2104.14615

说明 : Comments: 26 pages, 20 figures, 8 tables

Abstract : The first half of the paper is devoted to description and implementation of statistical tests arguing for the presence of a Brownian component in the inventories and wealth processes of individual traders. We use intra day data from the Toronto Stock Exchange to provide empirical evidence of this claim. We work with regularly spaced time intervals, as well as with asynchronously observed data. The tests reveal with high significance the presence of a non zero Brownian motion component. The second half of the paper is concerned with the analysis of trader behaviors throughout the day. We extend the theoretical analysis of an existing optimal execution model to accommodate the presence of It o inventory processes, and we compare empirically the optimal behavior of traders in such fitted models, to their actual behavior as inferred from the data.

摘要 : 本文的前半部分致力于描述和实施统计检验，证明在个体交易者的库存和财富过程中存在布朗成分。我们使用多伦多证券交易所的日内数据来提供这一说法的实证证据。我们处理有规律间隔的时间间隔，以及异步观测的数据。实验结果表明，非零布朗运动分量的存在具有很高的显著性。论文的后半部分是关于全天交易者行为的分析。我们扩展了现有最优执行模型的理论分析，以适应It-o库存过程的存在，并从经验上比较了这种拟合模型中交易者的最优行为与从数据中推断出的实际行为。

## 

\[2\] Deep Reinforcement Trading with Predictable Returns

标题 : 可预测回报的深度强化交易

作者 : Alessio Brini, Daniele Tantari , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2104.14683

说明 : Comments: 10 pages, 5 figures

Abstract : Classical portfolio optimization often requires forecasting asset returns and their corresponding variances in spite of the low signal to noise ratio provided in the financial markets. Deep reinforcement learning (DRL) offers a framework for optimizing sequential trader decisions through an objective which represents its reward function penalized by risk and transaction costs. We investigate the performance of model free DRL traders in a market environment with frictions and different mean reverting factors driving the dynamics of the returns. Since this framework admits an exact dynamic programming solution, we can assess limits and capabilities of different value based algorithms to retrieve meaningful trading signals in a data driven manner and to reach the benchmark performance. Moreover, extensive simulations show that this approach guarantees flexibility, outperforming the benchmark when the price dynamics is misspecified and some original assumptions on the market environment are violated with the presence of extreme events and volatility clustering.

摘要 : 经典的投资组合优化通常需要预测资产收益率及其相应的方差，尽管金融市场提供了低信噪比。深度强化学习（DRL）提供了一个框架，通过一个目标来优化顺序交易者的决策，这个目标代表了它的报酬函数受到风险和交易成本的惩罚。我们研究了无模型DRL交易者在有摩擦和不同均值回复因子驱动收益动态的市场环境中的表现。由于这个框架允许一个精确的动态规划解决方案，我们可以评估不同基于价值的算法的限制和能力，以数据驱动的方式检索有意义的交易信号，并达到基准性能。此外，大量的模拟表明，这种方法保证了灵活性，当价格动态被错误地指定，并且极端事件和波动性聚集的存在违反了市场环境的一些原始假设时，它的表现优于基准。

## 

\[3\] Driver Positioning and Incentive Budgeting with an Escrow Mechanism for  Ridesharing Platforms

标题 : 基于共享平台托管机制的驾驶员定位和激励预算

作者 : Hao Yi Ong, Daniel Freund, Davide Crapis , 类别 ：Computer Science and Game Theory (cs.GT)

链接 : https://arxiv.org/pdf/2104.14740

说明 : Comments: Forthcoming in INFORMS Journal on Applied Analytics

Abstract : Drivers on the Lyft rideshare platform do not always know where the areas of supply shortage are in real time. This lack of information hurts both riders trying to find a ride and drivers trying to determine how to maximize their earnings opportunity. Lyft s Personal Power Zone (PPZ) product helps the company to maintain high levels of service on the platform by influencing the spatial distribution of drivers in real time via monetary incentives that encourage them to reposition their vehicles. The underlying system that powers the product has two main components (1) a novel escrow mechanism that tracks available incentive budgets tied to locations within a city in real time, and (2) an algorithm that solves the stochastic driver positioning problem to maximize short run revenue from riders fares. The optimization problem is a multiagent dynamic program that is too complicated to solve optimally for our large scale application. Our approach is to decompose it into two subproblems. The first determines the set of drivers to incentivize and where to incentivize them to position themselves. The second determines how to fund each incentive using the escrow budget. By formulating it as two convex programs, we are able to use commercial solvers that find the optimal solution in a matter of seconds. Rolled out to all 320 cities in which Lyft s operates in a little over a year, the system now generates millions of bonuses that incentivize hundreds of thousands of active drivers to optimally position themselves in anticipation of ride requests every week. Together, the PPZ product and its underlying algorithms represent a paradigm shift in how Lyft drivers drive and generate earnings on the platform. Its direct business impact has been a 0.5 increase in incremental bookings, amounting to tens of millions of dollars per year.

摘要 : Lyft rideshare平台上的司机并不总是实时知道供应短缺的地区在哪里。这种信息的缺乏既伤害了试图寻找搭车机会的车手，也伤害了试图确定如何最大化他们的盈利机会的司机。Lyft的Personal Power Zone（PPZ）产品通过鼓励驾驶员重新定位车辆的货币激励措施，实时影响驾驶员的空间分布，从而帮助公司在平台上保持高水平的服务。为产品提供动力的基础系统有两个主要组成部分：（1）一个新的代管机制，实时跟踪与城市内地点相关的可用激励预算；（2）一个算法，解决随机驾驶员定位问题，最大限度地提高乘客票价的短期收入。优化问题是一个多智能体的动态规划问题，对于我们的大规模应用来说，它是一个非常复杂的问题。我们的方法是将其分解为两个子问题。第一种方法确定要激励的驾驶员集以及激励他们在哪里定位自己。第二个决定如何使用托管预算为每个激励提供资金。通过将其表示为两个凸规划，我们可以使用商业求解器在几秒钟内找到最优解。该系统在一年多一点的时间里推广到了所有320个Lyft s运营的城市，现在产生了数百万的奖金，激励数十万活跃的司机在每周的乘车请求前对自己进行最佳定位。PPZ产品及其底层算法共同代表了Lyft驱动程序如何在平台上驱动和产生收益的范式转变。其直接业务影响是增量预订量增加了0.5%，每年达数千万美元。

## 

\[4\] Modelling Net Loan Loss with Bayesian and Frequentist Regression Analysis

标题 : 基于贝叶斯和频数回归分析的贷款净损失建模

作者 : Nathan Thomas Provost , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2104.13947

说明 : -

Abstract : We create two distinct nonlinear regression models relating net loan loss (as an outcome) to several other financial and sociological quantities. We consider these data for the time interval between April 1st 2011 and April 1st 2020. We also include temporal quantities (month and year) in our model to improve accuracy. One model follows the frequentist paradigm for nonlinear regression, while the other follows the Bayesian paradigm. By using the two methods, we obtain a rounded understanding of the relationship between net loan losses and our given financial, sociological, and temporal variables, improving our ability to make financial predictions regarding the profitability of loan allocation.

摘要 : 我们创建了两个不同的非线性回归模型，将净贷款损失（作为结果）与其他几个金融和社会学量联系起来。我们考虑2011年4月1日至2020年4月1日期间的数据。我们还将时间量（月和年）包含在模型中以提高精度。一个模型遵循非线性回归的频率主义范式，而另一个模型遵循贝叶斯范式。通过使用这两种方法，我们全面了解了净贷款损失与我们给定的财务、社会学和时间变量之间的关系，提高了我们对贷款分配盈利能力进行财务预测的能力。

## 

\[5\] Applying Convolutional Neural Networks for Stock Market Trends Identification

标题 : 卷积神经网络在股市走势识别中的应用

作者 : Ekaterina Zolotareva , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2104.13948

说明 : Comments: 22 pages, 8 figures, 6 tables. This paper is the full text of the research, presented at the 20th International Conference on Artificial Intelligence and Soft Computing Web System (ICAISC 2021)

Abstract : In this paper we apply a specific type ANNs convolutional neural networks (CNNs) to the problem of finding start and endpoints of trends, which are the optimal points for entering and leaving the market. We aim to explore long term trends, which last several months, not days. The key distinction of our model is that its labels are fully based on expert opinion data. Despite the various models based solely on stock price data, some market experts still argue that traders are able to see hidden opportunities. The labelling was done via the GUI interface, which means that the experts worked directly with images, not numerical data. This fact makes CNN the natural choice of algorithm. The proposed framework requires the sequential interaction of three CNN submodels, which identify the presence of a changepoint in a window, locate it and finally recognize the type of new tendency upward, downward or flat. These submodels have certain pitfalls, therefore the calibration of their hyperparameters is the main direction of further research. The research addresses such issues as imbalanced datasets and contradicting labels, as well as the need for specific quality metrics to keep up with practical applicability. This paper is the full text of the research, presented at the 20th International Conference on Artificial Intelligence and Soft Computing Web System (ICAISC 2021)

摘要 : 本文将一种特殊类型的神经网络卷积神经网络（CNNs）应用于寻找趋势的起点和终点问题，即进入和离开市场的最佳点。我们的目标是探索长期趋势，持续几个月，而不是几天。我们模型的关键区别在于，它的标签完全基于专家意见数据。尽管各种模型仅基于股价数据，但一些市场专家仍认为，交易员能够看到隐藏的机会。标签是通过GUI界面完成的，这意味着专家直接处理图像，而不是数字数据。这使得CNN成为算法的自然选择。该框架要求CNN的三个子模型依次相互作用，识别窗口中是否存在变化点，并对其进行定位，最后识别出向上、向下或平坦的新趋势类型。这些子模型都存在一定的缺陷，因此其超参数的标定是进一步研究的主要方向。这项研究解决了诸如不平衡的数据集和相互矛盾的标签等问题，以及对具体质量指标的需要，以跟上实际适用性。本文是在第20届国际人工智能与软计算网络系统会议（icaisc2021）上发表的这项研究的全文

## 

\[6\] Modeling Managerial Search Behavior based on Simon s Concept of Satisficing

标题 : 基于Simon满意概念的管理者搜索行为建模

作者 : Friederike Wall , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14002

说明 : Comments: 32 pages, 6 figures

Abstract : Computational models of managerial search often build on backward looking search based on hill climbing algorithms. Regardless of its prevalence, there is some evidence that this family of algorithms does not universally represent managers search behavior. Against this background, the paper proposes an alternative algorithm that captures key elements of Simon s concept of satisficing which received considerable support in behavioral experiments. The paper contrasts the satisficing based algorithm to two variants of hill climbing search in an agent based model of a simple decision making organization. The model builds on the framework of NK fitness landscapes which allows controlling for the complexity of the decision problem to be solved. The results suggest that the model s behavior may remarkably differ depending on whether satisficing or hill climbing serves as an algorithmic representation for decision makers search. Moreover, with the satisficing algorithm, results indicate oscillating aspiration levels, even to the negative, and intense and potentially destabilizing search activities when intra organizational complexity increases. Findings may shed some new light on prior computational models of decision making in organizations and point to avenues for future research.

摘要 : 管理搜索的计算模型通常建立在基于爬山算法的后向搜索的基础上。不管其流行程度如何，有一些证据表明，这一系列算法并不普遍代表管理者的搜索行为。在这样的背景下，本文提出了一种新的算法，该算法抓住了Simon满意概念的关键元素，在行为实验中得到了广泛的支持。在基于agent的简单决策组织模型中，比较了基于满意度的算法和两种不同的爬山搜索算法。该模型建立在nkfitness景观框架的基础上，该框架允许控制待解决决策问题的复杂性。结果表明，模型的行为可能会明显不同，取决于是否满意或爬山作为一个算法表示决策者的搜索。此外，当组织内复杂度增加时，使用满意算法，结果显示出振荡的期望水平，甚至是负的，以及强烈的和潜在的不稳定的搜索活动。这一发现可能会为组织决策的计算模型提供一些新的线索，并为未来的研究指明方向。

## 

\[7\] Where to Refuel

标题 : 在哪里加油

作者 : Ari Pramono, Harmen Oppewal , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14043

说明 : -

Abstract : This paper introduces on the way choice of retail outlet as a form of convenience shopping. It presents a model of on the way choice of retail outlet and applies the model in the context of fuel retailing to explore its implications for segmentation and spatial competition. The model is a latent class random utility choice model. An application to gas station choices observed in a medium sized Asian city show the model to fit substantially better than existing models. The empirical results indicate consumers may adopt one of two decision strategies. When adopting an immediacy oriented strategy they behave in accordance with the traditional gravity based retail models and tend to choose the most spatially convenient outlet. When following a destination oriented strategy they focus more on maintaining their overall trip efficiency and so will tend to visit outlets located closer to their main destination and are more susceptible to retail agglomeration effects. The paper demonstrates how the model can be used to inform segmentation and local competition analyses that account for variations in these strategies as well as variations in consumer type, origin and time of travel. Simulations of a duopoly setting further demonstrate the implications.

摘要 : 本文介绍了零售网点作为一种便利购物形式的方式选择。本文提出了一个零售网点在途选择模型，并将该模型应用于燃料零售领域，探讨其对细分和空间竞争的影响。该模型是一个潜在类随机效用选择模型。在亚洲一个中型城市的加油站选择中的应用表明，该模型比现有模型更适合加油站的选择。实证结果表明，消费者可能会采取两种决策策略中的一种。当采用即时导向策略时，他们的行为与传统的基于重力的零售模式一致，倾向于选择空间上最方便的门店。在遵循以目的地为导向的战略时，他们更注重保持整体出行效率，因此会倾向于访问距离主要目的地较近的门店，并且更容易受到零售集聚效应的影响。本文展示了如何使用该模型进行细分和本地竞争分析，以解释这些策略的变化以及消费者类型、来源和旅行时间的变化。对双寡头垄断格局的模拟进一步证明了这一点。

## 

\[8\] The role of Common Agricultural Policy (CAP) in enhancing and stabilising farm income

标题 : 共同农业政策在提高和稳定农民收入中的作用

作者 : Biagini Luigi, Simone Severini (Tutor) , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14188

说明 : Comments: 127 page

Abstract : Since its inception, the E.U. s Common Agricultural Policy (CAP) aimed at ensuring an adequate and stable farm income. While recognizing that the CAP pursues a larger set of objectives, this thesis focuses on the impact of the CAP on the level and the stability of farm income in Italian farms. It uses microdata from a high standardized dataset, the Farm Accountancy Data Network (FADN), that is available in all E.U. countries. This allows if perceived as useful, to replicate the analyses to other countries. The thesis first assesses the Income Transfer Efficiency (i.e., how much of the support translate to farm income) of several CAP measures. Secondly, it analyses the role of a specific and relatively new CAP measure (i.e., the Income Stabilisation Tool IST) that is specifically aimed at stabilising farm income. The assessment of the potential use of Machine Learning procedures to develop an adequate ratemaking in IST. These are used to predict indemnity levels because this is an essential point for a similar insurance scheme. The assessment of ratemaking is challenging indemnity distribution is zero inflated, not continuous, right skewed, and several factors can potentially explain it. We address these problems by using Tweedie distributions and three Machine Learning procedures. The objective is to assess whether this improves the ratemaking by using the prospective application of the Income Stabilization Tool in Italy as a case study. We look at the econometric performance of the models and the impact of using their predictions in practice. Some of these procedures efficiently predict indemnities, using a limited number of regressors, and ensuring the scheme s financial stability.

摘要 : 自成立以来，欧盟共同农业政策（CAP）旨在确保足够和稳定的农业收入。在认识到上限追求更大的一系列目标的同时，本文重点研究了上限对意大利农场收入水平和稳定性的影响。它使用的微观数据来自一个高度标准化的数据集，即农场会计数据网络（FADN），该网络可在所有欧盟国家使用。这样，如果认为有用，就可以将分析复制到其他国家。本文首先评估了几种CAP措施的收入转移效率（即有多少支持转化为农业收入）。其次，它分析了一个具体的和相对较新的上限措施（即收入稳定工具IST）的作用，这一措施专门旨在稳定农业收入。评估机器学习程序在IST中发展适当评分的潜在用途。这些都是用来预测赔偿水平，因为这是一个类似的保险计划的基本点。评估税率是具有挑战性的赔偿分配是零膨胀，不连续，右偏，有几个因素可以解释它。我们使用Tweedie分布和三个机器学习过程来解决这些问题。本研究的目的是以意大利未来应用收入稳定工具为例，评估这是否改善了税率制定。我们将考察这些模型的计量经济性能以及在实践中使用它们的预测所产生的影响。其中一些程序有效地预测赔偿，使用有限数量的回归，并确保该计划的财政稳定。

## 

\[9\] FX Market Volatility

标题 : 外汇市场波动

作者 : Anton Koshelev , 类别 ：Mathematical Finance (q-fin.MF)

链接 : https://arxiv.org/pdf/2104.14190

说明 : -

Abstract : This paper aims at solving FX market volatility modeling problem and finding the most becoming approach to this task. Validity of two competing approaches, classical econometric generalized conditional heteroscedasticity and mathematical (singular spectrum analysis and dynamical systems stability analysis) are tested on major currency pairs (EUR USD, USD JPY, GBP USD) and unique high frequency USD RUB data. The study shows that both mathematical tools, understudied in econometric discourse, have a great potential in scope of discussed problematic, as for all experiments covered in this research, both of them show promising results.

摘要 : 本文旨在解决外汇市场波动性建模问题，寻找最适合这一任务的方法。在主要货币对（欧元-美元、美元-日元、英镑-美元）和独特的高频美元-卢布数据上，检验了经典计量经济学广义条件异方差和数学方法（奇异谱分析和动力系统稳定性分析）的有效性。研究表明，这两种数学工具在计量经济学话语中都有很大的潜力，在讨论问题的范围内，对于本研究所涉及的所有实验，它们都显示出了很好的结果。

## 

\[10\] The impact of past pandemics on CO 2 emissions and transition to renewable energy

标题 : 过去大流行对二氧化碳排放的影响及向可再生能源的过渡

作者 : Michal Brzezinski , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14199

说明 : -

Abstract : We estimate the short to medium term impact of six major past pandemic crises on the CO2 emissions and energy transition to renewable electricity. The results show that the previous pandemics led on average to a 3.4 3.7 fall in the CO2 emissions in the short run (1 2 years since the start of the pandemic). The effect is present only in the rich countries, as well as in countries with the highest pandemic death toll (where it disappears only after 8 years) and in countries that were hit by the pandemic during economic recessions. We found that the past pandemics increased the share of electricity generated from renewable sources within the fiveyear horizon by 1.9 2.3 percentage points in the OECD countries and by 3.2 3.9 percentage points in countries experiencing economic recessions. We discuss the implications of our findings in the context of CO2 emissions and the transition to renewable energy in the post COVID 19 era.

摘要 : 我们估计了过去六次大流行病危机对二氧化碳排放和能源向可再生电力过渡的中短期影响。结果表明，以往的大流行导致短期内（大流行开始后12年）二氧化碳排放量平均下降3.43.7。这种影响只出现在富裕国家，以及大流行死亡人数最高的国家（8年后才消失），以及在经济衰退期间受到大流行影响的国家。我们发现，过去的大流行使经合组织国家在五年内可再生能源发电的比例增加了1.9-2.3个百分点，而在经历经济衰退的国家增加了3.2-3.9个百分点。我们讨论了我们的研究结果在后科维德19世纪二氧化碳排放和向可再生能源过渡的背景下的意义。

## 

\[11\] Optimal bidding on hourly and quarter hourly day ahead electricity price auctions

标题 : 小时和季度小时日前电价拍卖的最优竞价

作者 : Michał Narajewski, Florian Ziel , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2104.14204

说明 : -

Abstract : Electricity exchanges offer several trading possibilities for market participants starting with futures products through the spot market consisting of the auction and continuous part, and ending with the balancing market. This variety of choice creates a new question for traders when to trade to maximize the gain. This problem is not trivial especially for trading larger volumes as the market participants should also consider their own price impact. The following paper raises this issue considering two markets the hourly EPEX Day Ahead Auction and the quarter hourly EPEX Intraday Auction. We consider a realistic setting which includes a forecasting study and a suitable evaluation. For a meaningful optimization many price scenarios are considered that we obtain using bootstrap with models that are well known and researched in the electricity price forecasting literature. The own market impact is predicted by mimicking the demand or supply shift in the respectful auction curves. A number of trading strategies is considered, e.g. minimization of the trading costs, risk neutral or risk averse agents. Additionally, we provide theoretical results for risk neutral agents. Especially we show when the optimal trading path coincides with the solution that minimizes transaction costs. The application study is conducted using the German market data, but the presented methods can be easily utilized with other two auction based markets. They could be also generalized to other market types, what is discussed in the paper as well. The empirical results show that market participants could increase their gains significantly compared to simple benchmark strategies.

摘要 : 电力交易所为市场参与者提供了多种交易机会，从期货产品开始，通过由拍卖和连续部分组成的现货市场，到平衡市场结束。这种选择的多样性为交易者创造了一个新的问题，即何时交易以获得最大收益。由于市场参与者还应考虑自身的价格影响，因此这个问题并非微不足道，尤其是对于交易量较大的交易而言。以下文章提出了这个问题，考虑到两个市场每小时EPEX日前拍卖和季度每小时EPEX日内拍卖。我们考虑一个现实的设置，其中包括预测研究和适当的评估。对于一个有意义的优化，许多价格方案被认为是我们使用bootstrap模型获得的，这些模型在电价预测文献中是众所周知和研究的。通过模拟相互尊重的拍卖曲线中的需求或供给变化来预测自身的市场影响。考虑了许多交易策略，例如最小化交易成本、风险中性或风险规避代理。此外，我们还为风险中性代理提供了理论结果。特别是当最优交易路径与最小化交易成本的解重合时。应用研究是使用德国市场数据进行的，但本文提出的方法可以很容易地用于其他两个基于拍卖的市场。它们也可以推广到其他市场类型，本文也讨论了这一点。实证结果表明，与简单的基准策略相比，市场参与者能够显著提高收益。

## 

\[12\] Stakeholder dynamics in residential solar energy adoption

标题 : 住宅太阳能利用中的利益相关者动态

作者 : Fabian Scheller, Isabel Doser, Emily Schulte, Simon Johanning, Russell McKenna, Thomas Bruckner , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14240

说明 : -

Abstract : Although there is a clear indication that stages of residential decision making are characterized by their own stakeholders, activities, and outcomes, many studies on residential low carbon technology adoption only implicitly address stage specific dynamics. This paper explores stakeholder influences on residential photovoltaic adoption from a procedural perspective, so called stakeholder dynamics. The major objective is the understanding of underlying mechanisms to better exploit the potential for residential photovoltaic uptake. Four focus groups have been conducted in close collaboration with the independent institute for social science research SINUS Markt und Sozialforschung in East Germany. By applying a qualitative content analysis, major influence dynamics within three decision stages are synthesized with the help of egocentric network maps from the perspective of residential decision makers. Results indicate that actors closest in terms of emotional and spatial proximity such as members of the social network represent the major influence on residential PV decision making throughout the stages. Furthermore, decision makers with a higher level of knowledge are more likely to move on to the subsequent stage. A shift from passive exposure to proactive search takes place through the process, but this shift is less pronounced among risk averse decision makers who continuously request proactive influences. The discussions revealed largely unexploited potential regarding the stakeholders local utilities and local governments who are perceived as independent, trustworthy and credible stakeholders. Public stakeholders must fulfill their responsibility in achieving climate goals by advising, assisting, and financing services for low carbon technology adoption at the local level. Supporting community initiatives through political frameworks appears to be another promising step.

摘要 : 尽管有明确的迹象表明，住宅决策的各个阶段都有其自身的利益相关者、活动和结果，但许多关于住宅低碳技术采用的研究只是隐含地涉及特定阶段的动态。本文从程序的角度探讨了利益相关者对住宅光伏采用的影响，即所谓的利益相关者动力学。主要目标是了解潜在的机制，以更好地开发住宅光伏吸收的潜力。与位于东德的社会科学研究独立研究所SINUS Markt und Sozialforschung密切合作开展了四个专题小组。运用定性内容分析法，从居民决策者的角度，借助以自我为中心的网络地图，综合了三个决策阶段的主要影响动态。结果表明，在情感和空间接近性方面最接近的参与者，如社会网络成员，在整个阶段对住宅PV决策具有主要影响。此外，知识水平较高的决策者更有可能进入下一阶段。从被动接触到主动搜索的转变贯穿于整个过程，但这种转变在不断要求主动影响的风险厌恶决策者中并不明显。讨论表明，当地公用事业和地方政府的利益相关者被视为独立、值得信赖和可信的利益相关者，其潜力在很大程度上尚未开发。公共利益相关者必须履行其在实现气候目标方面的责任，为地方一级采用低碳技术提供建议、协助和融资服务。通过政治框架支持社区倡议似乎是另一个有希望的步骤。

## 

\[13\] Prediction of Food Production Using Machine Learning Algorithms of Multilayer Perceptron and ANFIS

标题 : 基于多层感知器和ANFIS机器学习算法的粮食产量预测

作者 : Saeed Nosratabadi, Sina Ardabili, Zoltan Lakner, Csaba Mako, Amir Mosavi , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14286

说明 : -

Abstract : Advancing models for accurate estimation of food production is essential for policymaking and managing national plans of action for food security. This research proposes two machine learning models for the prediction of food production. The adaptive network based fuzzy inference system (ANFIS) and multilayer perceptron (MLP) methods are used to advance the prediction models. In the present study, two variables of livestock production and agricultural production were considered as the source of food production. Three variables were used to evaluate livestock production, namely livestock yield, live animals, and animal slaughtered, and two variables were used to assess agricultural production, namely agricultural production yields and losses. Iran was selected as the case study of the current study. Therefore, time series data related to livestock and agricultural productions in Iran from 1961 to 2017 have been collected from the FAOSTAT database. First, 70 of this data was used to train ANFIS and MLP, and the remaining 30 of the data was used to test the models. The results disclosed that the ANFIS model with Generalized bell shaped (Gbell) built in membership functions has the lowest error level in predicting food production. The findings of this study provide a suitable tool for policymakers who can use this model and predict the future of food production to provide a proper plan for the future of food security and food supply for the next generations.

摘要 : 提出准确估计粮食生产的模型对于制定和管理国家粮食安全行动计划至关重要。本研究提出两个机器学习模式来预测食物产量。采用基于自适应网络的模糊推理系统（ANFIS）和多层感知器（MLP）方法建立预测模型。在本研究中，畜牧业生产和农业生产两个变量被认为是粮食生产的来源。用三个变量来评估牲畜产量，即牲畜产量、活牲畜和屠宰牲畜；用两个变量来评估农业生产，即农业生产产量和损失。选择伊朗作为本研究的个案研究。因此，从FAOSTAT数据库收集了1961年至2017年伊朗牲畜和农业生产的时间序列数据。首先，70个数据被用来训练ANFIS和MLP，剩下的30个数据被用来测试模型。结果表明，在隶属函数中加入广义钟形（Gbell）的ANFIS模型对粮食产量的预测误差最小。本研究的结果为政策制定者提供了一个合适的工具，他们可以利用这个模型预测未来的粮食生产，为未来的粮食安全和下一代的粮食供应提供一个合适的计划。

## 

\[14\] The Effect of Marketing Investment on Firm Value and Systematic Risk

标题 : 营销投资对企业价值和系统风险的影响

作者 : Musaab Mousa, Saeed Nosratabadi, Judit Sagi, Amir Mosavi , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14301

说明 : -

Abstract : Analyzing the financial benefit of marketing is still a critical topic for both practitioners and researchers. Companies consider marketing costs as a type of investment and expect this investment to be returned to the company in the form of profit. On the other hand, companies adopt different innovative strategies to increase their value. Therefore, this study aims to test the impact of marketing investment on firm value and systematic risk. To do so, data related to four Arabic emerging markets during the period 2010 2019 are considered, and firm share price and beta share are considered to measure firm value and systematic risk, respectively. Since a firm s ownership concentration is a determinant factor in firm value and systematic risk, this variable is considered a moderated variable in the relationship between marketing investment and firm value and systematic risk. The findings of the study, using panel data regression, indicate that increasing investment in marketing has a positive effect on the firm value valuation model. It is also found that the ownership concentration variable has a reinforcing role in the relationship between marketing investment and firm value. It is also disclosed that it moderates the systematic risk aligned with the monitoring impact of controlling shareholders. This study provides a logical combination of governance marketing dimensions to interpret performance indicators in the capital market.

摘要 : 分析营销的财务效益仍然是从业者和研究者的一个重要课题。公司将营销成本视为一种投资，并期望这种投资以利润的形式返还给公司。另一方面，企业采用不同的创新策略来提升自身价值。因此，本研究旨在探讨行销投资对企业价值与系统风险之影响。为此，考虑了2010年至2019年期间四个阿拉伯新兴市场的相关数据，并考虑了公司股价和贝塔份额，分别衡量公司价值和系统风险。由于企业所有权集中度是企业价值和系统风险的决定因素，因此该变量被认为是营销投资与企业价值和系统风险之间关系的调节变量。研究结果显示，增加行销投入对企业价值评估模式有正向影响。研究还发现，股权集中度变量对营销投资与企业价值的关系具有强化作用。此外，还披露，它缓和了与控股股东的监控影响相一致的系统性风险。本研究提供了治理营销维度的逻辑组合来解释资本市场绩效指标。

## 

\[15\] Sparse Grid Method for Highly Efficient Computation of Exposures for xVA

标题 : xVA曝光量高效计算的稀疏网格法

作者 : Lech A. Grzelak , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2104.14319

说明 : -

Abstract : Every x adjustment in the so called xVA financial risk management framework relies on the computation of exposures. Considering thousands of Monte Carlo paths and tens of simulation steps, a financial portfolio needs to be evaluated numerous times during the lifetime of the underlying assets. This is the bottleneck of every simulation of xVA. In this article, we explore numerical techniques for improving the simulation of exposures. We aim to decimate the number of portfolio evaluations, particularly for large portfolios involving multiple, correlated risk factors. The usage of the Stochastic Collocation (SC) method, together with Smolyaks sparse grid extension, allows for a significant reduction in the number of portfolio evaluations, even when dealing with many risk factors. The proposed model can be easily applied to any portfolio and size. We report that for a realistic portfolio comprising linear derivatives, the expected reduction in the portfolio evaluations may exceed 6000 times, depending on the dimensionality and the required accuracy. We give illustrative examples and examine the method with realistic multi currency portfolios.

摘要 : 所谓xVA金融风险管理框架中的每个x调整都依赖于风险敞口的计算。考虑到数千条蒙特卡罗路径和数十个模拟步骤，一个金融投资组合需要在标的资产的生命周期内进行多次评估。这是每个xVA模拟的瓶颈。在这篇文章中，我们探讨了改善曝光模拟的数值技术。我们的目标是减少投资组合评估的数量，特别是对于涉及多个相关风险因素的大型投资组合。随机配置（SC）方法的使用，加上Smolyaks稀疏网格扩展，允许显著减少投资组合评估的数量，即使在处理许多风险因素时也是如此。该模型可以方便地应用于任何投资组合和规模。我们报告，对于包含线性衍生工具的现实投资组合，投资组合评估的预期减少可能超过6000倍，这取决于维度和所需的准确性。我们给出了实例，并用实际的多货币投资组合检验了该方法。

## 

\[16\] Nonparametric Test for Volatility in Clustered Multiple Time Series

标题 : 聚类多时间序列波动性的非参数检验

作者 : Erniel B. Barrios, Paolo Victor T. Redondo , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2104.14412

说明 : -

Abstract : Contagion arising from clustering of multiple time series like those in the stock market indicators can further complicate the nature of volatility, rendering a parametric test (relying on asymptotic distribution) to suffer from issues on size and power. We propose a test on volatility based on the bootstrap method for multiple time series, intended to account for possible presence of contagion effect. While the test is fairly robust to distributional assumptions, it depends on the nature of volatility. The test is correctly sized even in cases where the time series are almost nonstationary. The test is also powerful specially when the time series are stationary in mean and that volatility are contained only in fewer clusters. We illustrate the method in global stock prices data.

摘要 : 由多个时间序列（如股票市场指标中的时间序列）聚集而产生的传染会使波动性的性质进一步复杂化，从而使参数测试（依赖于渐近分布）受到大小和功率问题的影响。我们提出了一个基于bootstrap方法的多时间序列波动性检验，旨在解释可能存在的传染效应。虽然该测试对分布假设相当稳健，但它取决于波动性的性质。即使在时间序列几乎是非平稳的情况下，测试的大小也是正确的。特别是当时间序列的平均值是平稳的，并且波动性只包含在较少的簇中时，该检验也非常有效。我们在全球股票价格数据中说明了该方法。

## 

\[17\] Regional poverty in Bulgaria in the period 2008 2019

标题 : 2008-2019年保加利亚地区贫困状况

作者 : Iva Raycheva , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.14414

说明 : -

Abstract : Background Poverty among the population of a country is one of the most disputable topics in social studies. Many researchers devote their work to identifying the factors that influence it most. Bulgaria is one of the EU member states with the highest poverty levels. Regional facets of social exclusion and risks of poverty among the population are a key priority of the National Development Strategy for the third decade of 21st century. In order to mitigate the regional poverty levels it is necessary for the social policy makers to pay more attention to the various factors expected to influence these levels. Results Poverty reduction is observed in most areas of the country. The regions with obviously favorable developments are Sofia district, Pernik, Pleven, Lovech, Gabrovo, Veliko Tarnovo, Silistra, Shumen, Stara Zagora, Smolyan, Kyustendil and others. Increased levels of poverty are found for Razgrad and Montana districts. It was fond that the reduction in the risk of poverty is associated to the increase in employment, investment, and housing. Conclusion The social policy making needs to be aware of the fact that the degree of exposition to risk of poverty and social exclusion significantly relates to the levels of regional employment, investment and housing.

摘要 : 背景一个国家的人口贫困是社会研究中最有争议的话题之一。许多研究人员致力于找出对其影响最大的因素。保加利亚是贫困程度最高的欧盟成员国之一。社会排斥和人口贫困风险的区域层面是21世纪第三个十年国家发展战略的一个关键优先事项。为了减轻区域贫困水平，社会政策制定者有必要更多地关注影响贫困水平的各种因素。结果全国大部分地区贫困人口减少。开发明显有利的地区有索非亚区、佩尼克、普列文、洛夫奇、加布罗沃、维利科·塔诺沃、西利斯特拉、舒门、斯塔拉·扎戈拉、斯莫林、Kyustendil等。拉兹格勒和蒙大拿地区的贫困程度有所增加。人们认为，贫困风险的降低与就业、投资和住房的增加有关。结论社会政策制定者需要认识到，贫困和社会排斥风险的暴露程度与地区就业、投资和住房水平显著相关。

## 

\[18\] State capacity and vulnerability to natural disasters

标题 : 国家承受自然灾害的能力和脆弱性

作者 : Richard S.J. Tol , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.13425

说明 : -

Abstract : Many empirical studies have shown that government quality is a key determinant of vulnerability to natural disasters. Protection against natural disasters can be a public good flood protection, for example or a natural monopoly early warning systems, for instance. Recovery from natural disasters is easier when the financial system is well developed, particularly insurance services. This requires a strong legal and regulatory environment. This paper reviews the empirical literature to find that government quality and democracy reduce vulnerability to natural disasters while corruption of public officials increases vulnerability. The paper complements the literature by including tax revenue as an explanatory variable for vulnerability to natural disasters, and by modelling both the probability of natural disaster and the damage done. Countries with a larger public sector are better at preventing extreme events from doing harm. Countries that take more of their revenue in income taxes are better that reducing harm from natural disasters.

摘要 : 许多实证研究表明，政府质量是自然灾害脆弱性的关键决定因素。针对自然灾害的保护可以是一种公益性的防洪保护，例如自然垄断的预警系统。当金融体系，特别是保险服务发展良好时，从自然灾害中恢复会更容易。这需要一个强有力的法律和监管环境。本文回顾了实证文献发现，政府质量和民主降低了自然灾害的脆弱性，而公职人员腐败增加了自然灾害的脆弱性。本文补充了文献，将税收收入作为易受自然灾害影响的解释变量，并对自然灾害发生的概率和造成的损失进行了建模。公共部门规模较大的国家更善于防止极端事件造成伤害。从所得税中获得更多收入的国家比减少自然灾害的危害更好。

## 

\[19\] A Review of Disease and Development

标题 : 疾病与发展综述

作者 : Ruiwu Liu , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.13475

说明 : Comments: This paper was from my advanced case study report (2019) in the Australian National University

Abstract : Acemoglu and Johnson (2007) put forward the unprecedented view that health improvement has no significant effect on income growth. To arrive at this conclusion, they constructed predicted mortality as an instrumental variable based on the WHO international disease interventions to analyse this problem. I replicate the process of their research and eliminate some biases in their estimate. In addition, and more importantly, we argue that the construction of their instrumental variable contains a violation of the exclusion restriction of their instrumental variable. This negative correlation between health improvement and income growth still lacks an accurate causal explanation, according to which the instrumental variable they constructed increases reverse causality bias instead of eliminating it.

摘要 : Acemoglu和Johnson（2007）提出了前所未有的观点，认为健康改善对收入增长没有显著影响。为了得出这一结论，他们根据世卫组织国际疾病干预措施将预测死亡率作为工具变量来分析这一问题。我复制了他们的研究过程，消除了他们估计中的一些偏差。此外，更重要的是，我们认为他们的工具变量的结构包含了对他们的工具变量排除限制的违反。健康改善与收入增长之间的这种负相关仍然缺乏准确的因果解释，根据这一解释，他们构建的工具变量增加了反向因果关系偏差，而不是消除它。

## 

\[20\] Social Norms Offer Explanation for Inconsistent Effects of Incentives on Prosocial Behavior

标题 : 社会规范解释了激励对亲社会行为的不一致影响

作者 : Caroline Graf, Eva-Maria Merz, Bianca Suanet, Pamala Wiepking , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.13652

说明 : Comments: 34 pages, 11 figures

Abstract : Incentives have surprisingly inconsistent effects when it comes to encouraging people to behave prosocially. Classical economic theory, according to which a specific behavior becomes more prevalent when it is rewarded, struggles to explain why incentives sometimes backfire. More recent theories therefore posit a reputational cost offsetting the benefits of receiving an incentive yet unexplained effects of incentives remain, for instance across incentive types and countries. We propose that social norms can offer an explanation for these inconsistencies. Ultimately, social norms determine the reputational costs or benefits resulting from a given behavior, and thus variation in the effect of incentives may reflect variation in norms. We implemented a formal model of prosocial behavior integrating social norms, which we empirically tested on the real world prosocial behavior of blood donation. Blood donation is essential for many life saving medical procedures, but also presents an ideal testing ground for our theory Various incentive policies for blood donors exist across countries, enabling a comparative approach. Our preregistered analyses reveal that social norms can indeed account for the varying effects of financial and time incentives on individual level blood donation behavior across 28 European countries. Incentives are associated with higher levels of prosociality when norms regarding the incentive are more positive. The results indicate that social norms play an important role in explaining the relationship between incentives and prosocial behavior. More generally, our approach highlights the potential of integrating theory from across the economic and behavioral sciences to generate novel insights, with tangible consequences for policy making.

摘要 : 当涉及到鼓励人们亲社会行为时，激励措施的效果出人意料地不一致。古典经济学理论认为，当一种特定的行为得到奖励时，它会变得更加普遍，这一理论很难解释为什么激励有时会适得其反。因此，最近的理论认为，声誉成本抵消了获得激励的好处，但激励的影响仍然无法解释，例如，在不同的激励类型和国家。我们认为社会规范可以为这些不一致性提供解释。最终，社会规范决定了一个特定行为产生的声誉成本或收益，因此激励效果的变化可能反映了规范的变化。我们实施了一个整合社会规范的亲社会行为的正式模型，并对现实世界中的献血亲社会行为进行了实证检验。献血对于许多挽救生命的医疗程序来说是必不可少的，但同时也为我们的理论提供了一个理想的试验场各国对献血者的各种激励政策都存在，使得比较方法成为可能。我们预先登记的分析显示，社会规范确实可以解释28个欧洲国家的财政和时间激励对个人献血行为的不同影响。当有关激励的规范更积极时，激励与更高水平的亲社会性相关。结果表明，社会规范在解释激励与亲社会行为的关系中起着重要作用。更普遍地说，我们的方法强调了整合经济和行为科学理论的潜力，以产生新的见解，并对政策制定产生切实的影响。

## 

\[21\] The Future of Employment Revisited

标题 : 重新审视就业的未来

作者 : Fabian Stephany, Hanno Lorenz , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2104.13747

说明 : -

Abstract : The uniqueness of human labour is at question in times of smart technologies. The 250 years old discussion on technological unemployment reawakens. Prominently, Frey and Osborne (2017) estimated that half of US employment will be automated by algorithms within the next 20 years. Other follow up studies conclude that only a small fraction of workers will be replaced by digital technologies. The main contribution of our work is to show that the diversity of previous findings regarding the degree of job automation is, to a large extent, driven by model selection and not by controlling for personal characteristics or tasks. For our case study, we consult experts in machine learning and industry professionals on the susceptibility to digital technologies in the Austrian labour market. Our results indicate that, while clerical computer based routine jobs are likely to change in the next decade, professional activities, such as the processing of complex information, are less prone to digital change.

摘要 : 在智能技术时代，人类劳动的独特性受到质疑。250年前关于技术失业的讨论再次被唤醒。值得注意的是，弗雷和奥斯本（2017）估计，在未来20年内，美国一半的就业将通过算法实现自动化。其他后续研究得出结论，只有一小部分工人将被数字技术取代。我们工作的主要贡献在于表明，以往关于工作自动化程度的研究结果的多样性在很大程度上是由模型选择驱动的，而不是由对个人特征或任务的控制驱动的。在我们的案例研究中，我们就奥地利劳动力市场对数字技术的敏感性咨询了机器学习专家和行业专业人士。我们的研究结果表明，尽管在未来十年，基于计算机的文书日常工作可能会发生变化，但专业活动（如处理复杂信息）不太容易发生数字化变化。

## 

\[22\] Optimal Stopping via Randomized Neural Networks

标题 : 基于随机神经网络的最优停车

作者 : Calypso Herrera, Florian Krack, Pierre Ruyssen, Josef Teichmann , 类别 ：Machine Learning (stat.ML)

链接 : https://arxiv.org/pdf/2104.13669

说明 : -

Abstract : This paper presents new machine learning approaches to approximate the solution of optimal stopping problems. The key idea of these methods is to use neural networks, where the hidden layers are generated randomly and only the last layer is trained, in order to approximate the continuation value. Our approaches are applicable for high dimensional problems where the existing approaches become increasingly impractical. In addition, since our approaches can be optimized using a simple linear regression, they are very easy to implement and theoretical guarantees can be provided. In Markovian examples our randomized reinforcement learning approach and in non Markovian examples our randomized recurrent neural network approach outperform the state of the art and other relevant machine learning approaches.

摘要 : 本文提出了一种新的机器学习方法来逼近最优停止问题的解。这些方法的核心思想是使用神经网络，其中隐藏层是随机产生的，只有最后一层是训练，以近似的连续值。我们的方法适用于现有方法越来越不实用的高维问题。此外，由于我们的方法可以使用简单的线性回归进行优化，因此它们非常容易实现，并且可以提供理论保证。在马尔可夫例子中，我们的随机强化学习方法和在非马尔可夫例子中，我们的随机递归神经网络方法优于最新的和其他相关的机器学习方法。