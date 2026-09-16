# arxiv量化文献汇总翻译 20210902-20210905

partition 量化前沿速递 2021-09-05 20:58

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484455&idx=2&sn=779877c46fceea76b318f597f46f5571&chksm=c391e9dce291499d733ce96bae3976e55a03ece38a3f31840bbd5ed77f7d468f45986ed6fead#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484455&idx=2&sn=779877c46fceea76b318f597f46f5571&chksm=c391e9dce291499d733ce96bae3976e55a03ece38a3f31840bbd5ed77f7d468f45986ed6fead#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Auctions and Prediction Markets for Scientific Peer Review

用于科学同行评审的拍卖和预测市场

\[2\] Bilinear Input Normalization for Neural Networks in Financial Forecasting

金融预测中神经网络的双线性输入归一化

\[3\] Precise option pricing by the COS method How to choose the truncation interval

COS方法下的精确期权定价截尾区间的选择

\[4\] Land use change in agricultural systems

农业系统中的土地利用变化

\[5\] Forecasting High Dimensional Covariance Matrices of Asset Returns with Hybrid GARCH LSTMs

基于混合GARCH-LSTMs的高维资产收益协方差矩阵预测

\[6\] Analysis of taste heterogeneity in commuters travel decisions using joint parking and mode choice model

基于联合停车和模式选择模型的通勤者出行偏好异质性分析

\[7\] Detection of Structural Regimes and Analyzing the Impact of Crude Oil Market on Canadian Stock Market

结构机制检测及原油市场对加拿大股市的影响分析

\[8\] Using Temperature Sensitivity to Estimate Shiftable Electricity Demand

利用温度敏感性估算可移动电力需求

\[9\] Evaluation of the importance of criteria for the selection of cryptocurrencies

评估选择加密货币标准的重要性

\[10\] Multi Anchor Point Shrinkage for the Sample Covariance Matrix (Extended Version)

样本协方差矩阵的多锚定点收缩（扩展版）

\[11\] Nota Sobre Algumas Interpretacoes da Teoria de Tributacao Otima

关于奥蒂玛支流理论若干解释的注记

\[12\] Multiple prior valuation of cash flows subject to capital requirements

根据资本要求对现金流进行多次事先估值

\[13\] Closed form portfolio optimization under GARCH models

GARCH模型下的封闭式投资组合优化

\[14\] Decentralized Payment Clearing using Blockchain and Optimal Bidding

基于区块链和最优竞价的分散支付清算

\[15\] The Potential of Sufficiency Measures to Achieve a Fully Renewable Energy System A case study for Germany

充分性措施实现完全可再生能源系统的潜力——德国案例研究

\[16\] Controlled Measure Valued Martingales

受控测度值鞅

## 

\[1\] Auctions and Prediction Markets for Scientific Peer Review

标题 : 用于科学同行评审的拍卖和预测市场

作者 : Siddarth Srinivasan, Jamie Morgenstern , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.00923

说明 : -

Abstract : Peer reviewed publications are considered the gold standard in certifying and disseminating ideas that a research community considers valuable. However, we identify two major drawbacks of the current system (1) the overwhelming demand for reviewers due to a large volume of submissions, and (2) the lack of incentives for reviewers to participate and expend the necessary effort to provide high quality reviews. In this work, we adopt a mechanism design approach to propose improvements to the peer review process. We present a two stage mechanism which ties together the paper submission and review process, simultaneously incentivizing high quality reviews and high quality submissions. In the first stage, authors participate in a VCG auction for review slots by submitting their papers along with a bid that represents their expected value for having their paper reviewed. For the second stage, we propose a novel prediction market style mechanism (H DIPP) building on recent work in the information elicitation literature, which incentivizes participating reviewers to provide honest and effortful reviews. The revenue raised by the Stage I auction is used in Stage II to pay reviewers based on the quality of their reviews.

摘要 : 同行评议的出版物被认为是证明和传播研究界认为有价值的观点的黄金标准。然而，我们发现了当前系统的两个主要缺点（1）由于大量提交，对评审员的需求巨大，以及（2）缺乏激励评审员参与并花费必要的精力提供高质量的评审。在这项工作中，我们采用了一种机制设计方法来改进同行评审过程。我们提出了一个两阶段机制，将论文提交和审查过程联系在一起，同时激励高质量的审查和高质量的提交。在第一阶段，作者通过提交论文以及代表其论文评审预期价值的投标，参与VCG评审时段拍卖。对于第二阶段，我们在信息获取文献的最新工作基础上提出了一种新的预测市场风格机制（H DIPP），该机制激励参与评审的评审人员提供诚实、轻松的评审。第一阶段拍卖所得的收入在第二阶段用于根据评审质量向评审人员付款。

## 

\[2\] Bilinear Input Normalization for Neural Networks in Financial Forecasting

标题 : 金融预测中神经网络的双线性输入归一化

作者 : Dat Thanh Tran, Juho Kanniainen, Moncef Gabbouj, Alexandros Iosifidis , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.00983

说明 : Comments: 1 figure, 6 tables

Abstract : Data normalization is one of the most important preprocessing steps when building a machine learning model, especially when the model of interest is a deep neural network. This is because deep neural network optimized with stochastic gradient descent is sensitive to the input variable range and prone to numerical issues. Different than other types of signals, financial time series often exhibit unique characteristics such as high volatility, non stationarity and multi modality that make them challenging to work with, often requiring expert domain knowledge for devising a suitable processing pipeline. In this paper, we propose a novel data driven normalization method for deep neural networks that handle high frequency financial time series. The proposed normalization scheme, which takes into account the bimodal characteristic of financial multivariate time series, requires no expert knowledge to preprocess a financial time series since this step is formulated as part of the end to end optimization process. Our experiments, conducted with state of the arts neural networks and high frequency data from two large scale limit order books coming from the Nordic and US markets, show significant improvements over other normalization techniques in forecasting future stock price dynamics.

摘要 : 在建立机器学习模型时，数据规范化是最重要的预处理步骤之一，特别是当感兴趣的模型是深度神经网络时。这是因为采用随机梯度下降优化的深层神经网络对输入变量范围敏感，并且容易出现数值问题。与其他类型的信号不同，金融时间序列通常表现出独特的特征，如高波动性、非平稳性和多模态，这使得它们很难处理，通常需要专家领域知识来设计合适的处理管道。在本文中，我们提出了一种新的数据驱动的规范化方法，用于处理高频金融时间序列的深层神经网络。所提出的归一化方案考虑了金融多元时间序列的双峰特性，不需要专家知识来预处理金融时间序列，因为该步骤是作为端到端优化过程的一部分制定的。我们的实验使用了最先进的神经网络和来自北欧和美国市场的两个大型限价订单簿的高频数据，结果表明，在预测未来股价动态方面，与其他规范化技术相比，我们有了显著的改进。

## 

\[3\] Precise option pricing by the COS method How to choose the truncation interval

标题 : COS方法下的精确期权定价截尾区间的选择

作者 : Gero Junike, Konstantin Pankrashkin , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2109.01030

说明 : -

Abstract : The Fourier cosine expansion (COS) method is used for pricing European options numerically very fast. To apply the COS method, a truncation interval for the density of the log returns need to be provided. Using Markov s inequality, we derive a new formula to obtain the truncation interval and prove that the interval is large enough to ensure convergence of the COS method within a predefined error tolerance. We also show by several examples that the classical approach to determine the truncation interval by cumulants may lead to serious mispricing. Usually, the computational time of the COS method is of similar magnitude in both cases.

摘要 : Fourier-cosine展开（COS）方法用于欧洲期权的快速定价。要应用COS方法，需要提供日志返回密度的截断间隔。利用Markov不等式，我们推导了一个新的公式来获得截断区间，并证明了该区间足够大，可以保证COS方法在预定的误差容限内收敛。我们还通过几个例子说明，用累积量确定截断区间的经典方法可能导致严重的错误定价。通常，在这两种情况下，COS方法的计算时间是相似的。

## 

\[4\] Land use change in agricultural systems

标题 : 农业系统中的土地利用变化

作者 : Diego Ferraro, Daniela Blanco, Sebastián Pessah, Rodrigo Castro , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.01031

说明 : -

Abstract : Agricultural systems experience land use changes that are driven by population growth and intensification of technological inputs. This results in land use and cover change (LUCC) dynamics representing a complex landscape transformation process. In order to study the LUCC process we developed a spatially explicit agent based model in the form of a Cellular Automata implemented with the Cell DEVS formalism. The resulting model called AgroDEVS is used for predicting LUCC dynamics along with their associated economic and environmental changes. AgroDEVS is structured using behavioral rules and functions representing a) crop yields, b) weather conditions, c) economic profit, d) farmer preferences, e) technology level adoption and f) natural resources consumption based on embodied energy accounting. Using data from a typical location of the Pampa region (Argentina) for the 1988 2015 period, simulation exercises showed that the economic goals were achieved, on average, each 6 out of 10 years, but the environmental thresholds were only achieved in 1.9 out of 10 years. In a set of 50 years simulations, LUCC patterns quickly converge towards the most profitable crop sequences, with no noticeable tradeoff between the economic and environmental conditions.

摘要 : 农业系统经历了由人口增长和技术投入强化驱动的土地利用变化。这导致土地利用和覆盖变化（LUCC）动态表现为一个复杂的景观转化过程。为了研究LUCC过程，我们开发了一个基于agent的空间显式模型，该模型采用细胞自动机的形式，并采用Cell-DEVS形式实现。由此产生的名为AgroDEVS的模型用于预测LUCC动态及其相关的经济和环境变化。AgroDEVS的结构使用行为规则和函数表示a）作物产量、b）天气条件、c）经济利润、d）农民偏好、e）技术水平采用和f）基于具体能源核算的自然资源消耗。利用1988-2015年期间潘帕地区（阿根廷）典型地点的数据，模拟演习表明，平均每10年中有6年实现了经济目标，但环境阈值仅在10年中有1.9年实现。在一组50年的模拟中，LUCC模式迅速向最有利可图的作物序列收敛，经济和环境条件之间没有明显的权衡。

## 

\[5\] Forecasting High Dimensional Covariance Matrices of Asset Returns with Hybrid GARCH LSTMs

标题 : 基于混合GARCH-LSTMs的高维资产收益协方差矩阵预测

作者 : Lucien Boulet , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2109.01044

说明 : Comments: 30 pages

Abstract : Several academics have studied the ability of hybrid models mixing univariate Generalized Autoregressive Conditional Heteroskedasticity (GARCH) models and neural networks to deliver better volatility predictions than purely econometric models. Despite presenting very promising results, the generalization of such models to the multivariate case has yet to be studied. Moreover, very few papers have examined the ability of neural networks to predict the covariance matrix of asset returns, and all use a rather small number of assets, thus not addressing what is known as the curse of dimensionality. The goal of this paper is to investigate the ability of hybrid models, mixing GARCH processes and neural networks, to forecast covariance matrices of asset returns. To do so, we propose a new model, based on multivariate GARCHs that decompose volatility and correlation predictions. The volatilities are here forecast using hybrid neural networks while correlations follow a traditional econometric process. After implementing the models in a minimum variance portfolio framework, our results are as follows. First, the addition of GARCH parameters as inputs is beneficial to the model proposed. Second, the use of one hot encoding to help the neural network differentiate between each stock improves the performance. Third, the new model proposed is very promising as it not only outperforms the equally weighted portfolio, but also by a significant margin its econometric counterpart that uses univariate GARCHs to predict the volatilities.

摘要 : 一些学者研究了混合单变量广义自回归条件异方差（GARCH）模型和神经网络的混合模型的能力，以提供比纯计量经济模型更好的波动预测。尽管提出了非常有希望的结果，但将此类模型推广到多变量情况仍有待研究。此外，很少有论文研究了神经网络预测资产回报协方差矩阵的能力，并且都使用了相当少的资产，因此没有解决所谓的维度诅咒问题。本文的目的是研究混合GARCH过程和神经网络的混合模型预测资产收益协方差矩阵的能力。为此，我们提出了一个新模型，该模型基于分解波动率和相关性预测的多元GARCH。这里使用混合神经网络预测波动率，而相关性遵循传统的计量经济学过程。在最小方差投资组合框架中实现模型后，我们的结果如下。首先，添加GARCH参数作为输入有利于所提出的模型。第二，使用一个热编码来帮助神经网络区分每个股票，从而提高了业绩。第三，提出的新模型非常有希望，因为它不仅优于同等加权的投资组合，而且大大优于使用单变量GARCH预测波动性的计量经济学模型。

## 

\[6\] Analysis of taste heterogeneity in commuters travel decisions using joint parking and mode choice model

标题 : 基于联合停车和模式选择模型的通勤者出行偏好异质性分析

作者 : Janak Parmar, Gulnazbanu Saiyed, Sanjaykumar Dave , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.01045

说明 : Comments: 36 pages, 2 figures

Abstract : The concept of transportation demand management (TDM) upholds the development of sustainable mobility through the triumph of optimally balanced transport modal share in cities. The modal split management directly reflects on TDM of each transport subsystem, including parking. In developing countries, the policy makers have largely focused on supply side measures, yet demand side measures have remained unaddressed in policy implications. Ample literature is available presenting responses of TDM strategies, but most studies account mode choice and parking choice behaviour separately rather than considering trade offs between them. Failing to do so may lead to biased model estimates and impropriety in policy implications. This paper seeks to fill this gap by admitting parking choice as an endogenous decision within the model of mode choice behaviour. This study integrates attitudinal factors and built environment variables in addition to parking and travel attributes for developing comprehensive estimation results. A mixed logit model with random coefficients is estimated using hierarchical Bayes approach based on the Markov Chain Monte Carlo simulation method. The results reveal significant influence of mode parking specific attitudes on commuters choice behaviour in addition to the built environment factors and mode parking related attributes. It is identified that considerable shift is occurring between parking types in preference to switching travel mode with hypothetical changes in parking attributes. Besides, study investigates the heterogeneity in the willingness to pay through a follow up regression model, which provides important insights for identifying possible sources of this heterogeneity among respondents. The study provides remarkable results which may be beneficial to planning authorities for improving TDM strategies especially in developing countries.

摘要 : 交通需求管理（TDM）的概念通过城市最佳平衡交通模式份额的胜利，支持可持续交通的发展。模式分割管理直接反映在每个运输子系统（包括停车）的TDM上。在发展中国家，决策者主要关注供应方措施，而需求方措施在政策影响方面仍然没有得到解决。有大量文献可提供TDM策略的响应，但大多数研究分别考虑模式选择和停车选择行为，而不是考虑两者之间的权衡。如果不这样做，可能会导致有偏见的模型估计和政策含义不当。本文试图通过承认停车选择是模式选择行为模型中的内生决策来填补这一空白。除停车和出行属性外，本研究还整合了态度因素和建筑环境变量，以得出综合评估结果。基于马尔可夫链蒙特卡罗模拟方法，采用层次贝叶斯方法对随机系数的混合logit模型进行了估计。结果显示，除了建筑环境因素和模式停车相关属性外，模式停车特定态度对通勤者选择行为有显著影响。据确定，停车类型之间正在发生相当大的变化，而不是在停车属性发生假设变化的情况下切换行驶模式。此外，本研究通过后续回归模型调查了支付意愿的异质性，这为确定受访者中这种异质性的可能来源提供了重要的见解。这项研究提供了显著的结果，可能有助于规划当局改进TDM战略，特别是在发展中国家。

## 

\[7\] Detection of Structural Regimes and Analyzing the Impact of Crude Oil Market on Canadian Stock Market

标题 : 结构机制检测及原油市场对加拿大股市的影响分析

作者 : Mohammadreza Mahmoudi, Hana Ghaneei , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.01046

说明 : Comments: 14 pages,10 tables, 2 figures

Abstract : This study aims to analyze the impact of the crude oil market on the Toronto Stock Exchange Index (TSX) based on monthly data from 1979 to 2018 using a nonlinear Markov regime switching approach. The results indicate that TSX return contains two regimes, including positive return (regime 1), when growth rate of stock index is positive and negative return (regime 2), when growth rate of stock index is negative. The findings also show the crude oil market has positive effect on the stock market in both regimes, however, the effect of oil price on the stock market in regime 1 is more than regime 2. Moreover, two period lag of oil price increases stock price in regime 1, while it decreases stock price in regime 2

摘要 : 本研究旨在基于1979年至2018年的月度数据，采用非线性马尔可夫机制转换方法分析原油市场对多伦多证券交易所指数（TSX）的影响。结果表明，当股票指数增长率为正时，TSX收益率包含两个区域，即正收益（区域1）和负收益（区域2），当股票指数增长率为负时。研究结果还表明，原油市场对两种制度下的股票市场都有正向影响，但油价对制度1下股票市场的影响大于制度2下的影响。此外，油价的两个时期滞后使制度1下的股票价格上升，而制度2下的股票价格下降

## 

\[8\] Using Temperature Sensitivity to Estimate Shiftable Electricity Demand

标题 : 利用温度敏感性估算可移动电力需求

作者 : Michael J. Roberts, Sisi Zhang, Eleanor Yuan, James Jones, Matthias Fripp , 类别 ：Systems and Control (eess.SY)

链接 : https://arxiv.org/pdf/2109.00643

说明 : Comments: 23 pages, plus 17 page supplement, 4 figures, 1 table, plus supplementary tables and figures

Abstract : Growth of intermittent renewable energy and climate change make it increasingly difficult to manage electricity demand variability. Transmission and centralized storage technologies can help, but are costly. An alternative to centralized storage is to make better use of shiftable demand, but it is unclear how much shiftable demand exists. A significant share of electricity demand is used for cooling and heating, and low cost technologies exists to shift these loads. With sufficient insulation, energy used for air conditioning and space heating can be stored in ice or hot water from hours to days. In this study, we combine regional hourly demand with fine grained weather data across the United States to estimate temperature sensitive demand, and how much demand variability can be reduced by shifting temperature sensitive loads within each day, with and without improved transmission. We find that approximately three quarters of within day demand variability can be eliminated by shifting only half of temperature sensitive demand. The variability reducing benefits of employing available shiftable demand complement those gained from improved interregional transmission, and greatly mitigate the challenge of serving higher peaks under climate change.

摘要 : 间歇性可再生能源的增长和气候变化使得管理电力需求变化变得越来越困难。传输和集中存储技术可能有所帮助，但成本高昂。集中式存储的替代方案是更好地利用可移动需求，但尚不清楚存在多少可移动需求。电力需求的很大一部分用于冷却和加热，并且存在低成本技术来转移这些负荷。如果有足够的隔热层，用于空调和空间供暖的能量可以储存在冰或热水中数小时到数天。在这项研究中，我们将区域小时需求与美国各地的细粒度天气数据相结合，以估计对温度敏感的需求，以及通过在每天内转移对温度敏感的负荷（无论是否改善传输）可以减少多少需求变化。我们发现，通过仅转移一半的温度敏感需求，可以消除约四分之三的日内需求变化。利用可转换需求的可变性降低效益补充了改善区域间传输所获得的效益，并大大缓解了在气候变化下为更高峰值服务的挑战。

## 

\[9\] Evaluation of the importance of criteria for the selection of cryptocurrencies

标题 : 评估选择加密货币标准的重要性

作者 : Natalia A. Van Heerden, Juan B. Cabral, Nadia Luczywo , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2109.00130

说明 : -

Abstract : In recent years, cryptocurrencies have gone from an obscure niche to a prominent place, with investment in these assets becoming increasingly popular. However, cryptocurrencies carry a high risk due to their high volatility. In this paper, criteria based on historical cryptocurrency data are defined in order to characterize returns and risks in different ways, in short time windows (7 and 15 days) then, the importance of criteria is analyzed by various methods and their impact is evaluated. Finally, the future plan is projected to use the knowledge obtained for the selection of investment portfolios by applying multi criteria methods.

摘要 : 近年来，加密货币已经从一个不起眼的利基变成了一个突出的位置，对这些资产的投资越来越受欢迎。然而，加密货币由于其高波动性而具有高风险。在本文中，定义了基于历史加密货币数据的标准，以便在短时间窗口（7天和15天）内以不同的方式描述收益和风险，然后用各种方法分析标准的重要性并评估其影响。最后，预计未来计划将使用获得的知识，通过应用多标准方法选择投资组合。

## 

\[10\] Multi Anchor Point Shrinkage for the Sample Covariance Matrix (Extended Version)

标题 : 样本协方差矩阵的多锚定点收缩（扩展版）

作者 : Hubeyb Gurdogan, Alec Kercheval , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2109.00148

说明 : Comments: 60 pages, 6 figures

Abstract : Portfolio managers faced with limited sample sizes must use factor models to estimate the covariance matrix of a high dimensional returns vector. For the simplest one factor market model, success rests on the quality of the estimated leading eigenvector beta . When only the returns themselves are observed, the practitioner has available the PCA estimate equal to the leading eigenvector of the sample covariance matrix. This estimator performs poorly in various ways. To address this problem in the high dimension, limited sample size asymptotic regime and in the context of estimating the minimum variance portfolio, Goldberg, Papanicolau, and Shkolnik developed a shrinkage method (the GPS estimator ) that improves the PCA estimator of beta by shrinking it toward a constant target unit vector. In this paper we continue their work to develop a more general framework of shrinkage targets that allows the practitioner to make use of further information to improve the estimator. Examples include sector separation of stock betas, and recent information from prior estimates. We prove some precise statements and illustrate the resulting improvements over the GPS estimator with some numerical experiments.

摘要 : 面对有限样本量的投资组合经理必须使用因子模型来估计高维回报向量的协方差矩阵。对于最简单的单因素市场模型，成功取决于估计的领先特征向量β的质量。当只观察到收益本身时，实践者可获得等于样本协方差矩阵的前导特征向量的PCA估计。该估计器在各种方面表现不佳。为了在高维、有限样本量的渐近状态下以及在估计最小方差投资组合的背景下解决这一问题，Goldberg、Papanicolau和Shkolnik开发了一种收缩方法（GPS估计器），该方法通过将β的PCA估计器收缩到一个恒定的目标单位向量来改进β的PCA估计器。在本文中，我们继续他们的工作，以开发一个更通用的收缩目标框架，使从业者能够利用进一步的信息来改进估计量。例子包括股票beta的部门分离，以及来自先前估计的最新信息。我们证明了一些精确的陈述，并通过一些数值实验说明了与GPS估计器相比所得到的改进。

## 

\[11\] Nota Sobre Algumas Interpretacoes da Teoria de Tributacao Otima

标题 : 关于奥蒂玛支流理论若干解释的注记

作者 : Jose Ricardo Bezerra Nogueira , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.00297

说明 : Comments: in Portuguese

Abstract : This note discusses some aspects of interpretations of the theory of optimal taxation presented in recent works on the Brazilian tax system.

摘要 : 本说明讨论了巴西税收制度最新著作中提出的最优税收理论解释的一些方面。

## 

\[12\] Multiple prior valuation of cash flows subject to capital requirements

标题 : 根据资本要求对现金流进行多次事先估值

作者 : Hampus Engsner, Filip Lindskog, Julie Thoegersen , 类别 ：Pricing of Securities (q-fin.PR)

链接 : https://arxiv.org/pdf/2109.00306

说明 : Comments: 1 figure

Abstract : We study market consistent valuation of liability cash flows motivated by current regulatory frameworks for the insurance industry. Building on the theory on multiple prior optimal stopping we propose a valuation functional with sound economic properties that applies to any liability cash flow. Whereas a replicable cash flow is assigned the market value of the replicating portfolio, a cash flow that is not fully replicable is assigned a value which is the sum of the market value of a replicating portfolio and a positive margin. The margin is a direct consequence of considering a hypothetical transfer of the liability cash flow from an insurance company to an empty corporate entity set up with the sole purpose to manage the liability run off, subject to repeated capital requirements, and considering the valuation of this entity from the owner s perspective taking model uncertainty into account. Aiming for applicability, we consider a detailed insurance application and explain how the optimisation problems over sets of probability measures can be cast as simpler optimisation problems over parameter sets corresponding to parameterised density processes appearing in applications.

摘要 : 我们研究保险业现行监管框架激励下的负债现金流市场一致性估值。基于多重先验最优停止理论，我们提出了一个具有良好经济性质的估值函数，适用于任何负债现金流。可复制现金流被指定为可复制投资组合的市场价值，而不完全可复制的现金流被指定为可复制投资组合的市场价值和正利润的总和。保证金是考虑将负债现金流从保险公司转移至空置公司实体的直接结果，该空置公司实体的唯一目的是管理负债流失，但须符合重复资本要求，并从所有者的角度考虑该实体的估值，同时考虑模型的不确定性。针对适用性，我们考虑一个详细的保险申请，并解释如何优化问题的概率测度集可以投简单的优化问题的参数集对应于参数化的密度过程中出现的应用程序。

## 

\[13\] Closed form portfolio optimization under GARCH models

标题 : GARCH模型下的封闭式投资组合优化

作者 : Marcos Escobar-Anel, Maximilian Gollart, Rudi Zagst , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2109.00433

说明 : -

Abstract : This paper develops the first closed form optimal portfolio allocation formula for a spot asset whose variance follows a GARCH(1,1) process. We consider an investor with constant relative risk aversion (CRRA) utility who wants to maximize the expected utility from terminal wealth under a Heston and Nandi (2000) GARCH (HN GARCH) model. We obtain closed formulas for the optimal investment strategy, the value function and the optimal terminal wealth. We find the optimal strategy is independent of the development of the risky asset, and the solution converges to that of a continuous time Heston stochastic volatility model, albeit under additional conditions. For a daily trading scenario, the optimal solutions are quite robust to variations in the parameters, while the numerical wealth equivalent loss (WEL) analysis shows good performance of the Heston solution, with a quite inferior performance of the Merton solution.

摘要 : 本文针对方差服从GARCH（1,1）过程的现货资产，给出了第一个封闭形式的最优投资组合配置公式。我们考虑一个投资者具有恒定相对风险厌恶（CRRA）效用谁想要最大化预期效用的终端财富下的赫斯顿和楠迪（2000）GARCH（HN GARCH）模型。我们得到了最优投资策略、价值函数和最优终端财富的封闭公式。我们发现，最优策略独立于风险资产的发展，并且解收敛于连续时间Heston随机波动率模型的解，尽管是在附加条件下。对于日常交易场景，最优解对参数变化非常稳健，而数值财富等价损失（WEL）分析显示赫斯顿解的性能良好，而默顿解的性能较差。

## 

\[14\] Decentralized Payment Clearing using Blockchain and Optimal Bidding

标题 : 基于区块链和最优竞价的分散支付清算

作者 : Hamed Amini, Maxim Bichuch, Zachary Feinstein , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2109.00446

说明 : Comments: 30 pages

Abstract : In this paper, we construct a decentralized clearing mechanism which endogenously and automatically provides a claims resolution procedure. This mechanism can be used to clear a network of obligations through blockchain. In particular, we investigate default contagion in a network of smart contracts cleared through blockchain. In so doing, we provide an algorithm which constructs the blockchain so as to guarantee the payments can be verified and the miners earn a fee. We, additionally, consider the special case in which the blocks have unbounded capacity to provide a simple equilibrium clearing condition for the terminal net worths existence and uniqueness are proven for this system. Finally, we consider the optimal bidding strategies for each firm in the network so that all firms are utility maximizers with respect to their terminal wealths. We first look for a mixed Nash equilibrium bidding strategies, and then also consider Pareto optimal bidding strategies. The implications of these strategies, and more broadly blockchain, on systemic risk are considered.

摘要 : 在本文中，我们构建了一个分散的清算机制，该机制内生地自动提供索赔解决程序。该机制可用于通过区块链清除义务网络。特别是，我们调查通过区块链清算的智能合约网络中的违约传染。在这样做的过程中，我们提供了一个构建区块链的算法，以确保支付可以被验证，矿工可以赚取费用。此外，我们还考虑了特殊的情况，其中块具有无限的容量，为终端网络提供一个简单的平衡清除条件，证明了该系统的存在性和唯一性。最后，我们考虑网络中每个公司的最优竞价策略，使得所有公司相对于其终端财富都是效用最大化者。首先寻找混合纳什均衡竞价策略，然后再考虑帕累托最优竞价策略。考虑了这些策略以及更广泛的区块链对系统性风险的影响。

## 

\[15\] The Potential of Sufficiency Measures to Achieve a Fully Renewable Energy System A case study for Germany

标题 : 充分性措施实现完全可再生能源系统的潜力——德国案例研究

作者 : Elmar Zozmann, Mirjam Helena Eerma, Dylan Manning, Gro Lill Økland, Citlali Rodriguez del Angel, Paul E. Seifert, Johanna Winkler, Alfredo Zamora Blaumann, Leonard Göke, Mario Kendziorski, Christian von Hirschhausen , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2109.00453

说明 : -

Abstract : The paper provides energy system wide estimates of the effects sufficiency measures in different sectors can have on energy supply and system costs. In distinction to energy efficiency, we define sufficiency as behavioral changes to reduce useful energy without significantly reducing utility, for example by adjusting thermostats. By reducing demand, sufficiency measures are a potentially decisive but seldomly considered factor to support the transformation towards a decarbonized energy system. Therefore, this paper addresses the following question What is the potential of sufficiency measures and what is their impacts on the supply side of a 100 renewable energy system For this purpose, an extensive literature review is conducted to obtain estimates for the effects of different sufficiency measures on final energy demand in Germany. Afterwards, the impact of these measures on the supply side and system costs is quantified using a bottom up planning model of a renewable energy system. Results indicate that final energy could be reduced by up to 20.5 and as a result cost reduction between 11.3 to 25.6 are conceivable. The greatest potential for sufficiency measures was identified in the heating sector.

摘要 : 该文件提供了能源系统范围内不同部门充足措施对能源供应和系统成本的影响估计。与能源效率不同，我们将充分性定义为在不显著降低效用的情况下减少有用能源的行为变化，例如通过调节恒温器。通过减少需求，充足性措施是支持向脱碳能源系统转型的潜在决定性因素，但考虑较少。因此，本文讨论了以下问题：充分性措施的潜力是什么？它们对100可再生能源系统的供应侧有何影响？为此，进行了广泛的文献综述，以获得不同充分性措施对德国最终能源需求影响的估计。然后，使用自下而上的可再生能源系统规划模型量化这些措施对供应侧和系统成本的影响。结果表明，最终能源可减少20.5，因此成本可降低11.3至25.6。取暖部门确定了采取充分措施的最大潜力。

## 

\[16\] Controlled Measure Valued Martingales

标题 : 受控测度值鞅

作者 : Alexander M.G. Cox, Sigrid K llblad, Martin Larsson, Sara Svaluto-Ferro , 类别 ：Probability (math.PR)

链接 : https://arxiv.org/pdf/2109.00064

说明 : Comments: 49 pages

Abstract : We consider a class of stochastic control problems where the state process is a probability measure valued process satisfying an additional martingale condition on its dynamics, called measure valued martingales (MVMs). We establish the classical results of stochastic control for these problems specifically, we prove that the value function for the problem can be characterised as the unique solution to the Hamilton Jacobi Bellman equation in the sense of viscosity solutions. In order to prove this result, we exploit structural properties of the MVM processes. Our results also include an appropriate version of It o s lemma for controlled MVMs. We also show how problems of this type arise in a number of applications, including model independent derivatives pricing, the optimal Skorokhod embedding problem, and two player games with asymmetric information.

摘要 : 我们考虑一类随机控制问题，其中状态过程是一个概率测度值过程，满足其动态上的附加鞅条件，称为测度值鞅（MVM）。我们建立了这些问题的随机控制的经典结果，证明了该问题的值函数在粘性解意义下可以刻画为Hamilton-Jacobi-Bellman方程的唯一解。为了证明这个结果，我们利用了MVM过程的结构特性。我们的结果还包括一个适用于受控MVM的It o s引理的适当版本。我们还展示了这类问题是如何在许多应用中出现的，包括独立于模型的衍生品定价、最优Skorokhod嵌入问题以及信息不对称的两人博弈。