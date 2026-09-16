# arxiv量化文献汇总翻译 20210930-20211003

Shame1ess 量化前沿速递 2021-10-04 10:09

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484511&idx=2&sn=e7982221f1edb846cf644cbc96b3b41d&chksm=c30aff8ab7bea202273cd279c5aa4558d11bfd22823b2de01140be6bc9afa2f076a1116f7635#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484511&idx=2&sn=e7982221f1edb846cf644cbc96b3b41d&chksm=c30aff8ab7bea202273cd279c5aa4558d11bfd22823b2de01140be6bc9afa2f076a1116f7635#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Pricing and Hedging Prepayment Risk in a Mortgage Portfolio

抵押贷款组合中提前还款风险的定价和对冲

\[2\] Stock Index Prediction using Cointegration test and Quantile Loss

基于协整检验和分位数损失的股指预测

\[3\] Bitcoin Volatility and Intrinsic Time Using Double Subordinated Levy Processes

使用双重从属利维过程的比特币波动性和内禀时间

\[4\] Causal effect of regulated Bitcoin futures on volatility and volume

受监管比特币期货对波动性和交易量的因果效应

\[5\] Stock Price Prediction Under Anomalous Circumstances

异常情况下的股价预测

\[6\] Stock index futures trading impact on spot price volatility. The CSI 300 studied with a TGARCH model

股指期货交易对现货价格波动的影响。CSI 300采用TGARCH模型进行研究

\[7\] Pricing American options under negative rates

负利率下的美式期权定价

\[8\] Characterizing and Computing the Set of Nash Equilibria via Vector Optimization

通过向量优化刻画和计算纳什均衡集

\[9\] Deep Hawkes Process for High Frequency Market Making

高频做市的Deep Hawkes流程

\[10\] Lobbying Influence The Role of Money, Strategies and Measurements

游说影响资金、战略和措施的作用

\[11\] Resource sharing on endogenous networks

内生网络上的资源共享

\[12\] Constrained scenarios for twenty first century human population size based on the empirical coupling to economic growth

基于经济增长经验耦合的21世纪人口规模约束情景

\[13\] Systemic risk in interbank networks

银行间网络中的系统性风险

\[14\] Conditional Value at Risk for Quantitative Trading

定量交易的条件风险价值

\[15\] Coulomb Force Model for International Trades

国际贸易的库仑力模型

\[16\] Implicit Generative Copulas

隐生成连接词

\[17\] A Market Mechanism for Truthful Bidding with Energy Storage

储能真实竞价的市场机制

## 

\[1\] Pricing and Hedging Prepayment Risk in a Mortgage Portfolio

标题 : 抵押贷款组合中提前还款风险的定价和对冲

作者 : Emanuele Casamassima, Lech A. Grzelak, Frank A. Mulder, Cornelis W. Oosterlee , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2109.14977

说明 : -

Abstract : Understanding mortgage prepayment is crucial for any financial institution providing mortgages, and it is important for hedging the risk resulting from such unexpected cash flows. Here, in the setting of a Dutch mortgage provider, we propose to include non linear financial instruments in the hedge portfolio when dealing with mortgages with the option to prepay part of the notional early. Based on the assumption that there is a correlation between prepayment and the interest rates in the market, a model is proposed which is based on a specific refinancing incentive. The linear and non linear risks are addressed by a set of tradeable instruments in a static hedge strategy. We will show that a stochastic model for the notional of a mortgage unveils non linear risk embedded in a prepayment option. Based on a calibration of the refinancing incentive on a data set of more than thirty million observations, a functional form of the prepayments is defined, which accurately reflects the borrowers behaviour. We compare this functional form with a fully rational model, where the option to prepay is assumed to be exercised rationally.

摘要 : 了解抵押贷款提前还款对于任何提供抵押贷款的金融机构来说都至关重要，对于对冲此类意外现金流带来的风险也很重要。在这里，在荷兰抵押贷款提供商的背景下，我们建议在处理抵押贷款时，在对冲投资组合中包括非线性金融工具，以选择提前偿还部分名义提前还款。基于提前还款与市场利率之间存在相关性的假设，提出了一个基于特定再融资激励的模型。线性和非线性风险由静态对冲策略中的一组可交易工具解决。我们将证明，抵押贷款概念的随机模型揭示了嵌入在提前还款期权中的非线性风险。基于对超过3000万个观察数据集的再融资激励的校准，定义了预付款的功能形式，准确反映了借款人的行为。我们将这种函数形式与完全理性模型进行比较，其中假设提前还款的选择权是合理行使的。

## 

\[2\] Stock Index Prediction using Cointegration test and Quantile Loss

标题 : 基于协整检验和分位数损失的股指预测

作者 : Jaeyoung Cheong, Heejoon Lee, Minjung Kang , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.15045

说明 : Comments: 8pages, 2 figures

Abstract : Recent researches on stock prediction using deep learning methods has been actively studied. This is the task to predict the movement of stock prices in the future based on historical trends. The approach to predicting the movement based solely on the pattern of the historical movement of it on charts, not on fundamental values, is called the Technical Analysis, which can be divided into univariate and multivariate methods in the regression task. According to the latter approach, it is important to select different factors well as inputs to enhance the performance of the model. Moreover, its performance can depend on which loss is used to train the model. However, most studies tend to focus on building the structures of models, not on how to select informative factors as inputs to train them. In this paper, we propose a method that can get better performance in terms of returns when selecting informative factors using the cointegration test and learning the model using quantile loss. We compare the two RNN variants with quantile loss with only five factors obtained through the cointegration test among the entire 15 stock index factors collected in the experiment. The Cumulative return and Sharpe ratio were used to evaluate the performance of trained models. Our experimental results show that our proposed method outperforms the other conventional approaches.

摘要 : 近年来，利用深度学习方法进行股票预测的研究受到了广泛的关注。这是根据历史趋势预测未来股价走势的任务。仅基于图表上的历史运动模式而非基本值预测运动的方法称为技术分析，在回归任务中可分为单变量和多变量方法。根据后一种方法，重要的是选择不同的因素以及输入，以提高模型的性能。此外，其性能取决于用于训练模型的损耗。然而，大多数研究倾向于建立模型的结构，而不是如何选择信息因素作为输入来训练它们。在本文中，我们提出了一种方法，在使用协整检验选择信息因素和使用分位数损失学习模型时，可以在收益方面获得更好的性能。我们比较了两个分位数损失的RNN变量，在实验中收集的15个股票指数因子中，只有5个因子通过协整检验得到。累积收益率和夏普比率用于评估训练模型的性能。我们的实验结果表明，我们提出的方法优于其他传统的方法。

## 

\[3\] Bitcoin Volatility and Intrinsic Time Using Double Subordinated Levy Processes

标题 : 使用双重从属利维过程的比特币波动性和内禀时间

作者 : Abootaleb Shirvani, Stefan Mittnik, W. Brent Lindquist, Svetlozar T. Rachev , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.15051

说明 : -

Abstract : We propose a doubly subordinated Levy process, NDIG, to model the time series properties of the cryptocurrency bitcoin. NDIG captures the skew and fat tailed properties of bitcoin prices and gives rise to an arbitrage free, option pricing model. In this framework we derive two bitcoin volatility measures. The first combines NDIG option pricing with the Cboe VIX model to compute an implied volatility the second uses the volatility of the unit time increment of the NDIG model. Both are compared to a volatility based upon historical standard deviation. With appropriate linear scaling, the NDIG process perfectly captures observed, in sample, volatility.

摘要 : 我们提出了一种双重从属利维过程（NDIG）来模拟加密货币比特币的时间序列特性。NDIG捕捉了比特币价格的倾斜和厚尾特性，并提出了一种无套利的期权定价模型。在此框架中，我们推导了两个比特币波动性度量。第一种方法将NDIG期权定价与Cboe VIX模型相结合，以计算隐含波动率；第二种方法使用NDIG模型单位时间增量的波动率。两者都与基于历史标准差的波动率进行比较。通过适当的线性缩放，NDIG过程完美地捕获了样本中观察到的挥发性。

## 

\[4\] Causal effect of regulated Bitcoin futures on volatility and volume

标题 : 受监管比特币期货对波动性和交易量的因果效应

作者 : Fiammetta Menchetti, Fabrizio Cipollini, Fabrizia Mealli , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.15052

说明 : Comments: 30 pages, 6 figures

Abstract : In December 2017, two leading derivative exchanges, CBOE and CME, introduced the first regulated Bitcoin futures. Our aim is estimating their causal impact on Bitcoin volatility and trading volume. Employing a new causal approach, C ARIMA, we find that the CME future triggered an increase in both outcomes. There is also evidence of a positive volume volatility relationship and that the effect on volatility was partially due to the higher trading volumes induced by the launch of the contract. After controlling for the effect on volumes, we find that the CME instrument caused Bitcoin volatility to increase by more than double.

摘要 : 2017年12月，两家领先的衍生品交易所CBOE和CME推出了首个受监管的比特币期货。我们的目标是估计它们对比特币波动性和交易量的因果影响。采用一种新的因果关系方法C ARIMA，我们发现CME的未来引发了两种结果的增加。也有证据表明，交易量与波动率之间存在正相关关系，对波动率的影响部分是由于合同推出导致交易量增加。在控制了对交易量的影响后，我们发现CME工具导致比特币波动性增加了一倍以上。

## 

\[5\] Stock Price Prediction Under Anomalous Circumstances

标题 : 异常情况下的股价预测

作者 : Jinlong Ruan, Wei Wu, Jiebo Luo , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.15059

说明 : Comments: 8 pages, 5 figures, 3 tables. 2020 IEEE International Conference on Big Data (Big Data)

Abstract : The stock market is volatile and complicated, especially in 2020. Because of a series of global and regional black swans, such as the COVID 19 pandemic, the U.S. stock market triggered the circuit breaker three times within one week of March 9 to 16, which is unprecedented throughout history. Affected by the whole circumstance, the stock prices of individual corporations also plummeted by rates that were never predicted by any pre developed forecasting models. It reveals that there was a lack of satisfactory models that could predict the changes in stocks prices when catastrophic, highly unlikely events occur. To fill the void of such models and to help prevent investors from heavy losses during uncertain times, this paper aims to capture the movement pattern of stock prices under anomalous circumstances. First, we detect outliers in sequential stock prices by fitting a standard ARIMA model and identifying the points where predictions deviate significantly from actual values. With the selected data points, we train ARIMA and LSTM models at the single stock level, industry level, and general market level, respectively. Since the public moods affect the stock market tremendously, a sentiment analysis is also incorporated into the models in the form of sentiment scores, which are converted from comments about specific stocks on Reddit. Based on 100 companies stock prices in the period of 2016 to 2020, the models achieve an average prediction accuracy of 98 which can be used to optimize existing prediction methodologies.

摘要 : 股票市场动荡而复杂，特别是在2020年。由于一系列全球性和区域性的黑天鹅，如新冠病毒19大流行，美国股市在3月9日至16日的一周内三次触发了断路器，这在历史上是前所未有的。受整体情况的影响，个别公司的股价也以任何预先开发的预测模型都无法预测的速度暴跌。这表明，当灾难性的、极不可能发生的事件发生时，缺乏令人满意的模型来预测股票价格的变化。为了填补这类模型的空白，防止投资者在不确定时期遭受重大损失，本文旨在捕捉异常情况下股票价格的运动模式。首先，我们通过拟合标准ARIMA模型并识别预测值与实际值显著偏离的点，来检测序列股票价格中的异常值。利用选定的数据点，我们分别在单一股票水平、行业水平和一般市场水平上训练ARIMA和LSTM模型。由于公众情绪对股市的影响巨大，情绪分析也以情绪分数的形式纳入模型中，情绪分数由Reddit上对特定股票的评论转换而来。基于2016年至2020年期间100家公司的股票价格，该模型的平均预测精度为98，可用于优化现有预测方法。

## 

\[6\] Stock index futures trading impact on spot price volatility. The CSI 300 studied with a TGARCH model

标题 : 股指期货交易对现货价格波动的影响。CSI 300采用TGARCH模型进行研究

作者 : Marcel Ausloos, Yining Zhang, Gurjeet Dhesi , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.15060

说明 : Comments: 31 pages, 10 tables, 2 figures, 109 references

Abstract : A TGARCH modeling is argued to be the optimal basis for investigating the impact of index futures trading on spot price variability. We discuss the CSI 300 index (China Shanghai Shenzhen 300 Stock Index) as a test case. The results prove that the introduction of CSI 300 index futures (CSI 300 IF) trading significantly reduces the volatility in the corresponding spot market. It is also found that there is a stationary equilibrium relationship between the CSI 300 spot and CCSI 300 IF markets. A bidirectional Granger causality is also detected. Finally , it is deduced that spot prices are predicted with greater accuracy over a 3 or 4 lag day time span.

摘要 : TGARCH模型被认为是研究指数期货交易对现货价格波动性影响的最佳基础。我们讨论了沪深300指数作为一个测试案例。研究结果表明，沪深300指数期货（csi300if）交易的引入显著降低了相应现货市场的波动性。研究还发现，CSI300现货市场和CCSI300 IF市场之间存在平稳均衡关系。还检测到双向格兰杰因果关系。最后，可以推断，在3或4个滞后日的时间跨度内，现货价格的预测精度更高。

## 

\[7\] Pricing American options under negative rates

标题 : 负利率下的美式期权定价

作者 : Jherek Healy , 类别 ：Pricing of Securities (q-fin.PR)

链接 : https://arxiv.org/pdf/2109.15157

说明 : -

Abstract : This paper starts by defining the criteria where the early exercise of an American option is never optimal, under positive, or negative rates. It follows with a short analysis of the various shapes of the exercise region under negative interest rates. It then presents a new integral equation, which establishes the option price, and the two early exercise boundaries, under negative rates. It shows how to solve this new equation, through modifications of the modern and efficient algorithm of Andersen and Lake, from the initial guess of the two boundaries to more subtle changes required in their fixed point method for stability. Finally, the performance and accuracy of the resulting algorithm is assessed against a cutting edge finite difference method implementation.

摘要 : 本文首先定义了在正利率或负利率下，早期行使美式期权永远不是最优的标准。随后简要分析了负利率下行使区域的各种形状。然后提出了一个新的积分方程，该方程建立了负利率下的期权价格和两个早期行使边界。它展示了如何通过修改Andersen和Lake的现代高效算法来解决这个新方程，从两个边界的初始猜测到稳定性定点方法所需的更细微变化。最后，根据最前沿的有限差分法实现，对所得到的算法的性能和精度进行了评估。

## 

\[8\] Characterizing and Computing the Set of Nash Equilibria via Vector Optimization

标题 : 通过向量优化刻画和计算纳什均衡集

作者 : Zachary Feinstein, Birgit Rudloff , 类别 ：Optimization and Control (math.OC)

链接 : https://arxiv.org/pdf/2109.14932

说明 : -

Abstract : Nash equilibria and Pareto optimality are two distinct concepts when dealing with multiple criteria. It is well known that the two concepts do not coincide. However, in this work we show that it is possible to characterize the set of all Nash equilibria for any non cooperative game as the Pareto optimal solutions of a certain vector optimization problem. To accomplish this task, we enlarge the objective function and formulate a non convex ordering cone under which Nash equilibria are Pareto efficient. We demonstrate these results, first, for shared constraint games in which a joint constraint is applied to all players in a non cooperative game. This result is then extended to generalized Nash games, where we deduce two vector optimization problems providing necessary and sufficient conditions, respectively, for generalized Nash equilibria. Finally, we show that all prior results hold for vector valued games as well. Multiple numerical examples are given and demonstrate the computational advantages of finding the set of Nash equilibria via our proposed vector optimization formulation.

摘要 : 纳什均衡和帕累托最优是两个不同的概念时，处理多个标准。众所周知，这两个概念并不一致。然而，在这项工作中，我们证明了可以将任何非合作博弈的所有纳什均衡集刻画为某个向量优化问题的帕累托最优解。为了完成这项任务，我们扩大了目标函数，并建立了一个非凸序锥，在此锥下纳什均衡是帕累托有效的。我们证明了这些结果，首先，对于共享约束博弈，联合约束应用于非合作博弈中的所有参与者。然后将这一结果推广到广义纳什博弈，在这里我们推导了两个向量优化问题，分别为广义纳什均衡提供了充分必要条件。最后，我们证明了所有先前的结果也适用于向量值对策。给出了多个数值算例，证明了通过我们提出的向量优化公式找到纳什均衡集的计算优势。

## 

\[9\] Deep Hawkes Process for High Frequency Market Making

标题 : 高频做市的Deep Hawkes流程

作者 : Pankaj Kumar , 类别 ：Computational Engineering, Finance, and Science (cs.CE)

链接 : https://arxiv.org/pdf/2109.15110

说明 : Comments: 49 Pages, 10 figures

Abstract : High frequency market making is a liquidity providing trading strategy that simultaneously generates many bids and asks for a security at ultra low latency while maintaining a relatively neutral position. The strategy makes a profit from the bid ask spread for every buy and sell transaction, against the risk of adverse selection, uncertain execution and inventory risk. We design realistic simulations of limit order markets and develop a high frequency market making strategy in which agents process order book information to post the optimal price, order type and execution time. By introducing the Deep Hawkes process to the high frequency market making strategy, we allow a feedback loop to be created between order arrival and the state of the limit order book, together with self and cross excitation effects. Our high frequency market making strategy accounts for the cancellation of orders that influence order queue position, profitability, bid ask spread and the value of the order. The experimental results show that our trading agent outperforms the baseline strategy, which uses a probability density estimate of the fundamental price. We investigate the effect of cancellations on market quality and the agent s profitability. We validate how closely the simulation framework approximates reality by reproducing stylised facts from the empirical analysis of the simulated order book data.

摘要 : 高频做市是一种提供流动性的交易策略，在保持相对中性的情况下，同时产生许多出价并以超低延迟要求证券。针对逆向选择风险、执行不确定风险和库存风险，该策略从每次买卖交易的买卖价差中获利。我们设计了极限订单市场的真实模拟，并开发了一种高频做市策略，其中代理处理订单簿信息以发布最优价格、订单类型和执行时间。通过将Deep-Hawkes过程引入高频做市策略，我们允许在订单到达和极限订单簿状态之间创建反馈回路，以及自激和交叉激励效应。我们的高频做市策略考虑了订单取消对订单队列位置、盈利能力、买卖价差和订单价值的影响。实验结果表明，我们的交易代理优于使用基本价格概率密度估计的基线策略。我们调查取消对市场质量和代理商盈利能力的影响。我们通过从模拟订单数据的实证分析中再现样式化的事实，验证了模拟框架与现实的接近程度。

## 

\[10\] Lobbying Influence The Role of Money, Strategies and Measurements

标题 : 游说影响资金、战略和措施的作用

作者 : Fintan Oeri, Adrian Rinscheid, Aya Kachi , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.13928

说明 : -

Abstract : Comparing the results for preference attainment, self perceived influence and reputational influence, this paper analyzes the relationship between financial resources and lobbying influence. The empirical analysis builds on data from an original survey with 312 Swiss energy policy stakeholders combined with document data from multiple policy consultation submission processes. The results show that the distribution of influence varies substantially depending on the measure. While financial resources for political purposes predict influence across all measures, the relationship is positive only for some. An analysis of indirect effects sheds light on the potential mechanisms that translate financial resources into influence.

摘要 : 比较偏好获得、自我感知影响和声誉影响的结果，本文分析了财政资源与游说影响之间的关系。实证分析基于对312名瑞士能源政策利益相关者的原始调查数据，并结合多个政策咨询提交过程的文件数据。结果表明，影响的分布在很大程度上取决于测量。尽管出于政治目的的财政资源可以预测所有指标的影响力，但这种关系只有在某些方面是积极的。对间接影响的分析揭示了将财政资源转化为影响力的潜在机制。

## 

\[11\] Resource sharing on endogenous networks

标题 : 内生网络上的资源共享

作者 : Philip Solimine, Luke Boosey , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.14204

说明 : -

Abstract : In this paper, we examine behavior in a voluntary resource sharing game that incorporates endogenous network formation an incentive problem that is increasingly common in contemporary digital economies. Using a laboratory experimental implementation of repeated play in this information rich decision setting, we examine the effects of a simple reputation feedback system on patterns of linking and contribution decisions. Reduced form estimates find significant effects of the information treatment on a number of key outcomes such as efficiency, complementarity, and decentralization. To further understand the driving causes of these observed changes in behavior, we develop and estimate a discrete choice framework, using computationally efficient panel methods to identify the structure of social preferences in this setting. We find that the information treatment focuses reciprocity, and helps players coordinate to reach more efficient outcomes.

摘要 : 在本文中，我们研究了自愿资源共享博弈中的行为，该博弈包含了内生网络形成，这是一个激励问题，在当代数字经济中日益普遍。在这个信息丰富的决策环境中，我们使用重复游戏的实验室实验实现，检验了一个简单的声誉反馈系统对链接和贡献决策模式的影响。简化形式的估计发现，信息处理对效率、互补性和权力下放等一系列关键成果产生了重大影响。为了进一步了解这些观察到的行为变化的驱动因素，我们开发并评估了一个离散选择框架，使用计算效率高的面板方法来确定这种环境下的社会偏好结构。我们发现，信息处理注重互惠，并帮助参与者进行协调，以达到更有效的结果。

## 

\[12\] Constrained scenarios for twenty first century human population size based on the empirical coupling to economic growth

标题 : 基于经济增长经验耦合的21世纪人口规模约束情景

作者 : Barry W. Brook, Jessie C. Buettel, Sanghyun Hong , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.14209

说明 : Comments: 11 pages, 4 figures, 2 tables

Abstract : Growth in the global human population this century will have momentous consequences for societies and the environment. Population growth has come with higher aggregate human welfare, but also climate change and biodiversity loss. Based on the well established empirical association and plausible causal relationship between economic and population growth, we devised a novel method for forecasting population based on Gross Domestic Product (GDP) per capita. Although not mechanistically causal, our model is intuitive, transparent, replicable, and grounded on historical data. Our central finding is that a richer world is likely to be associated with a lower population, an effect especially pronounced in rapidly developing countries. In our baseline scenario, where GDP per capita follows a business as usual trajectory, global population is projected to reach 9.2 billion in 2050 and peak in 2062. With 50 higher annual economic growth, population peaks even earlier, in 2056, and declines to below 8 billion by the end of the century. Without any economic growth after 2020, however, the global population will grow to 9.9 billion in 2050 continue rising thereafter. Economic growth has the largest effect on low income countries. The gap between the highest and lowest GDP scenarios reaches almost 4 billion by 2100. Education and family planning are important determinants of population growth, but economic growth is also likely to be a driver of slowing population growth by changing incentives for childbearing. Since economic growth could slow population growth, it will offset environmental impacts stemming from higher per capita consumption of food, water, and energy, and work in tandem with technological innovation.

摘要 : 本世纪全球人口的增长将对社会和环境产生重大影响。人口增长带来了更高的总体人类福利，但也带来了气候变化和生物多样性丧失。基于经济增长和人口增长之间已建立的经验关联和合理的因果关系，我们设计了一种基于人均国内生产总值（GDP）的人口预测新方法。虽然不是机械因果关系，但我们的模型是直观、透明、可复制的，并且基于历史数据。我们的主要发现是，世界越富裕，人口越少，这一影响在快速发展的国家尤其明显。在我们的基准情景中，人均GDP遵循正常的轨迹，预计全球人口将在2050年达到92亿，在2062年达到峰值。随着50年以上的年经济增长，人口高峰甚至更早出现在2056年，到本世纪末下降到80亿以下。然而，如果2020年后没有任何经济增长，全球人口将在2050年增长到99亿，此后将继续增长。经济增长对低收入国家的影响最大。到2100年，最高和最低GDP情景之间的差距达到近40亿。教育和计划生育是人口增长的重要决定因素，但经济增长也可能通过改变生育动机而成为人口增长放缓的驱动力。由于经济增长可能减缓人口增长，它将抵消人均食品、水和能源消费增加所带来的环境影响，并与技术创新协同工作。

## 

\[13\] Systemic risk in interbank networks

标题 : 银行间网络中的系统性风险

作者 : Alessandro Ferracci, Giulio Cimini , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2109.14360

说明 : -

Abstract : We study the difference between the level of systemic risk that is empirically measured on an interbank network and the risk that can be deduced from the balance sheets composition of the participating banks. Using generalised DebtRank dynamics, we measure observed systemic risk on e MID network data (augmented by BankFocus information) and compare it with the expected systemic of a null model network, obtained through an appropriate maximum entropy approach constraining relevant balance sheet variables. We show that the aggregate levels of observed and expected systemic risks are usually compatible but differ significantly during turbulent times (in our case, after the default of Lehman Brothers and the VLTRO implementation by the ECB). At the individual level instead, banks are typically more or less risky than what their balance sheet prescribes due to their position in the network. Our results confirm on one hand that balance sheet information used within a proper maximum entropy network models provides good systemic risk estimates, and on the other hand the importance of knowing the empirical details of the network for conducting precise stress tests of individual banks, especially after systemic events.

摘要 : 我们研究在银行间网络上经验性测量的系统性风险水平与从参与银行的资产负债表构成中推断的风险之间的差异。利用广义DebtRank动力学，我们测量了e MID网络数据（由BankFocus信息增强）上观察到的系统性风险，并将其与通过适当的最大熵方法约束相关资产负债表变量获得的空模型网络的预期系统性风险进行比较。我们表明，观察到的和预期的系统性风险的总体水平通常是相容的，但在动荡时期（在我们的案例中，在雷曼兄弟违约和欧洲央行实施VLTRO之后）存在显著差异。相反，在个人层面，由于银行在网络中的地位，银行的风险通常高于或低于其资产负债表规定的风险。我们的结果一方面证实了在适当的最大熵网络模型中使用的资产负债表信息提供了良好的系统风险估计，另一方面也证实了了解网络的经验细节对于对单个银行进行精确压力测试的重要性，尤其是在系统性事件之后。

## 

\[14\] Conditional Value at Risk for Quantitative Trading

标题 : 定量交易的条件风险价值

作者 : Ali Al-Ameer, Khaled Alshehri , 类别 ：Trading and Market Microstructure (q-fin.TR)

链接 : https://arxiv.org/pdf/2109.14438

说明 : -

Abstract : We propose a convex formulation for a trading system with the Conditional Value at Risk as a risk adjusted performance measure under the notion of Direct Reinforcement Learning. Due to convexity, the proposed approach can uncover a lucrative trading policy in a pure online manner where it can interactively learn and update the policy without multi epoch training and validation. We assess our proposed algorithm on a real financial market where it trades one of the largest US trust funds, SPDR, for three years. Numerical experiments demonstrate the algorithm s robustness in detecting central market regime switching. Moreover, the results show the algorithm s effectiveness in extracting profitable policy while meeting an investor s risk preference under a conservative frictional market with a transaction cost of 0.15 per trade.

摘要 : 在直接强化学习的概念下，我们提出了一个以条件风险值作为风险调整绩效度量的交易系统的凸公式。由于凸性，所提出的方法可以以纯在线方式发现利润丰厚的交易政策，在这种方式下，它可以交互地学习和更新政策，而无需多时代的培训和验证。我们在一个真实的金融市场上评估了我们提出的算法，该市场交易了美国最大的信托基金之一SPDR，为期三年。数值实验证明了该算法在检测中央市场制度转换方面的鲁棒性。此外，结果表明，在每次交易成本为0.15的保守摩擦市场下，该算法在满足投资者风险偏好的同时提取盈利策略是有效的。

## 

\[15\] Coulomb Force Model for International Trades

标题 : 国际贸易的库仑力模型

作者 : Mikrajuddin Abdullah , 类别 ：General Finance (q-fin.GN)

链接 : https://arxiv.org/pdf/2109.14554

说明 : Comments: 18 pages, 8 figures

Abstract : I propose the coulomb force model to explain international trade volume as an alternative to the gravitational force model. The empirical equations to accurately describe international trade between countries deviated far from the original gravity equations. This deviation can be avoided by using the Coulomb force model in which all factors other than GDP and the distance between countries are aggregated into a dielectric constant.

摘要 : 我提出库仑力模型来解释国际贸易量，作为引力模型的替代。准确描述国家间国际贸易的经验方程与原始引力方程相差甚远。这种偏差可以通过使用库仑力模型来避免，在库仑力模型中，除了GDP和国与国之间的距离之外的所有因素都被聚合为一个介电常数。

## 

\[16\] Implicit Generative Copulas

标题 : 隐生成连接词

作者 : Tim Janke, Mohamed Ghanmi, Florian Steinke , 类别 ：Machine Learning (stat.ML)

链接 : https://arxiv.org/pdf/2109.14567

说明 : Comments: Accepted at NeurIPS 2021

Abstract : Copulas are a powerful tool for modeling multivariate distributions as they allow to separately estimate the univariate marginal distributions and the joint dependency structure. However, known parametric copulas offer limited flexibility especially in high dimensions, while commonly used non parametric methods suffer from the curse of dimensionality. A popular remedy is to construct a tree based hierarchy of conditional bivariate copulas. In this paper, we propose a flexible, yet conceptually simple alternative based on implicit generative neural networks. The key challenge is to ensure marginal uniformity of the estimated copula distribution. We achieve this by learning a multivariate latent distribution with unspecified marginals but the desired dependency structure. By applying the probability integral transform, we can then obtain samples from the high dimensional copula distribution without relying on parametric assumptions or the need to find a suitable tree structure. Experiments on synthetic and real data from finance, physics, and image generation demonstrate the performance of this approach.

摘要 : Copulas是建模多元分布的强大工具，因为它允许单独估计单变量边际分布和联合依赖结构。然而，已知的参数连接函数提供了有限的灵活性，特别是在高维情况下，而常用的非参数方法受到维数灾难的影响。一种常用的补救方法是构造一个基于树的条件二元copula层次结构。在本文中，我们提出了一个灵活的，但概念上简单的替代基于隐式生成神经网络。关键的挑战是确保估计的copula分布的边际均匀性。我们通过学习多变量潜在分布来实现这一点，该分布具有未指定的边缘，但具有所需的依赖结构。通过应用概率积分变换，我们可以从高维copula分布中获得样本，而无需依赖参数假设或寻找合适的树结构。对来自金融、物理和图像生成的合成和真实数据的实验证明了该方法的性能。

## 

\[17\] A Market Mechanism for Truthful Bidding with Energy Storage

标题 : 储能真实竞价的市场机制

作者 : Rajni Kant Bansal, Pengcheng You, Dennice F. Gayme, Enrique Mallada , 类别 ：Optimization and Control (math.OC)

链接 : https://arxiv.org/pdf/2109.14596

说明 : -

Abstract : This paper proposes a storage cycle aware market mechanism for a multi interval electricity market with generators and storage. Drawing ideas from linear supply function bidding, we propose for storage a cycle based cumulative supply function bidding form storage half cycle depths as a function of cycle based prices. It allows storage to reflect their preference for cycling operations, which are directly associated with storage degradation, instead of power at each interval. The market clearing for associated economic dispatch based on bids (linear supply function for generators) yields traditional clearing prices for energy and specific clearing prices for storage cycling cycling prices on identified half cycles. We show that price taking participants in such a market are all incentivized to reveal their truthful costs, thus leading to an efficient competitive equilibrium. Simulations for New York Independent System Operator (NYISO) data illustrate that linear supply function bid is insufficient to guarantee storage profitability.

摘要 : 针对具有发电机和储能的多时段电力市场，提出了一种储能周期感知的市场机制。借鉴线性供应函数竞价的思想，我们提出了一种基于周期的累积供应函数竞价形式，将存储半周期深度作为基于周期的价格的函数。它允许存储反映其对循环操作的偏好，循环操作与存储降级直接相关，而不是每个间隔的电源。基于投标的相关经济调度的市场清算（发电机的线性供应函数）产生能源的传统清算价格和确定的半周期上存储循环价格的特定清算价格。我们发现，在这样一个市场中，价格接受的参与者都被激励去揭示他们真实的成本，从而导致一个有效的竞争均衡。对纽约独立系统运营商（NYISO）数据的模拟表明，线性供应函数投标不足以保证存储盈利能力。