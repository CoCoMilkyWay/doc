# RFS Special Issue: New Methods in the Cross-Section

QuantSeek QuantSeek 2025-03-21 17:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484979&idx=1&sn=5f14489e8db653de4e5aba101425075b&chksm=ceb9a2b8e5c1908cbb1b0bbb07b67e8e25990ce8f3555c7bb5aa513e86b21f0ca9cfc731ca12#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484979&idx=1&sn=5f14489e8db653de4e5aba101425075b&chksm=ceb9a2b8e5c1908cbb1b0bbb07b67e8e25990ce8f3555c7bb5aa513e86b21f0ca9cfc731ca12#rd)

2020年RFS专门发了一个 New Methods in the Cross-Section 的专题特刊，这个专题本身就很有价值，里面还有一些有意思的文章，供大家参考。

  

本期特别版介绍了从横截面和时间序列中提取信息的最新进展，处理复制和虚假发现的问题，以及应用创新的机器学习技术来识别最相关的资产定价因子。  

  
The cross-section and time series of stock returns contains a wealth of information about the stochastic discount factor (SDF), the object that links cash flows to prices. A large empirical literature has uncovered many candidate factors—many more than seem plausible—to summarize the SDF. This special volume of the Review of Financial Studies presents recent advances in extracting information from both the cross-section and the time series, in dealing with issues of replication and false discoveries, and in applying innovative machine-learning techniques to identify the most relevant asset pricing factors.  
  

1\. Comparing Cross-Section and Time-Series Factor Models

摘要:  
中文: 本文使用Fama和MacBeth（1973）的横截面回归方法，构建与Fama和French（2015）时间序列因子相对应的横截面因子。仅使用横截面因子的时间序列模型比使用时间序列因子的模型更能准确描述平均收益。无论是在假设因子载荷恒定的情况下，还是在使用适合时间序列因子和横截面因子的时间变化载荷的情况下，这一结论都成立。  
英文: We use the cross-section regression approach of Fama and MacBeth (1973) to construct cross-section factors corresponding to the time-series factors of Fama and French (2015). Time-series models that use only cross-section factors provide better descriptions of average returns than time-series models that use time-series factors. This is true when we impose constant factor loadings and when we use time-varying loadings that are natural for time-series factors and time-varying loadings that are natural for cross-section factors.  
  

2\. The Cross-Section of Risk and Returns

摘要:  
中文: 金融文献中常见的做法是通过按特征排序来创建特征组合。研究表明，这些组合不仅会捕捉与特征相关的定价风险，还会捕捉未定价风险。我们开发了一种使用过去收益估计的协方差信息来去除这种未定价风险的程序。我们将该方法应用于Fama-French的五个特征组合。经过处理后的特征有效组合的最优组合的夏普比率平方为2.13，而原始特征组合为1.17。  
英文: A common practice in the finance literature is to create characteristic portfolios by sorting on characteristics associated with average returns. We show that the resultant portfolios are likely to capture not only the priced risk associated with the characteristic but also unpriced risk. We develop a procedure to remove this unpriced risk using covariance information estimated from past returns. We apply our methodology to the five Fama-French characteristic portfolios. The squared Sharpe ratio of the optimal combination of the resultant characteristic-efficient portfolios is 2.13, compared with 1.17 for the original characteristic portfolios.  
  

3\. Factor Timing

摘要:  
中文: 最优因子择时组合等同于随机贴现因子。我们提出并实施了一种方法来实证表征这两者。我们的方法对预期收益的动态施加了限制，从而得出一个经济上合理的SDF。市场中性股票因子具有强烈且稳健的可预测性。利用这种可预测性可以显著提高投资组合的表现，与静态因子投资相比有实质性改进。  
英文: The optimal factor timing portfolio is equivalent to the stochastic discount factor. We propose and implement a method to characterize both empirically. Our approach imposes restrictions on the dynamics of expected returns, leading to an economically plausible SDF. Market-neutral equity factors are strongly and robustly predictable. Exploiting this predictability leads to substantial improvement in portfolio performance relative to static factor investing.  
  

4\. Replicating Anomalies

摘要:  
中文: 大多数异常现象无法达到当前实证金融学可接受的标准。在通过NYSE断点和价值加权收益排除微型股后，我们数据库中的452个异常现象中有65%（包括96%的交易摩擦类别）无法通过单个测试的绝对|t|-值1.96的门槛。将5%显著性水平的多重测试门槛提高到2.78，失败率上升到82%。即使是经过复制的异常现象，其经济规模也远小于最初报告的。总体而言，资本市场比之前认为的更有效率。  
英文: Most anomalies fail to hold up to currently acceptable standards for empirical finance. With microcaps mitigated via NYSE breakpoints and value-weighted returns, 65% of the 452 anomalies in our extensive data library, including 96% of the trading frictions category, cannot clear the single test hurdle of the absolute |t|-value of 1.96. Imposing the higher multiple test hurdle of 2.78 at the 5% significance level raises the failure rate to 82%. Even for replicated anomalies, their economic magnitudes are much smaller than originally reported. In all, capital markets are more efficient than previously recognized.  
  

5\. Anomalies and False Rejections

摘要:  
中文: 我们使用超过200万种随机生成的真实数据交易策略和通过出版过程存活下来的策略的信息，推断研究人员可能研究的策略集的统计属性。通过这个集合，我们计算了在寻找异常现象时控制多重假设检验的|t|-统计量阈值，分别为时间序列和横截面回归的3.8和3.4。我们估计，如果研究人员未能考虑多重假设检验，他们将产生约45%的错误拒绝。  
英文: We use information from over 2 million trading strategies randomly generated using real data and from strategies that survive the publication process to infer the statistical properties of the set of strategies that could have been studied by researchers. Using this set, we compute |t|-statistic thresholds that control for multiple hypothesis testing, when searching for anomalies, at 3.8 and 3.4 for time-series and cross-sectional regressions, respectively. We estimate the expected proportion of false rejections that researchers would produce if they failed to account for multiple hypothesis testing to be about 45%.  
  

  

6\. A Transaction-Cost Perspective on the Multitude of Firm Characteristics

摘要:  
中文: 我们研究了交易成本如何改变对投资者最优投资组合具有联合显著性的特征数量，以及如何改变股票收益横截面的维度。我们发现，交易成本将显著特征的数量从6个增加到15个。原因在于，我们从理论和实证上证明，结合特征可以降低交易成本，因为重新平衡不同特征所需的底层股票交易通常会相互抵消。因此，交易成本为考虑比主流资产定价模型中更多的特征提供了经济理由。  
英文: We investigate how transaction costs change the number of characteristics that are jointly significant for an investor’s optimal portfolio and, hence, how they change the dimension of the cross-section of stock returns. We find that transaction costs increase the number of significant characteristics from 6 to 15. The explanation is that, as we show theoretically and empirically, combining characteristics reduces transaction costs because the trades in the underlying stocks required to rebalance different characteristics often cancel out. Thus, transaction costs provide an economic rationale for considering a larger number of characteristics than that in prominent asset-pricing models.  
  

  

7\. Empirical Asset Pricing via Machine Learning

摘要:  
中文: 我们对机器学习方法在经典的经验资产定价问题——衡量资产风险溢价——进行了比较分析。我们证明了使用机器学习预测对投资者具有巨大的经济收益，在某些情况下可以将文献中领先的基于回归的策略的性能翻倍。我们确定了表现最佳的方法（树和神经网络），并将它们的预测收益归因于允许其他方法遗漏的非线性预测变量交互。所有方法都同意同一组主导预测信号，包括动量、流动性和波动率的变化。  
英文: We perform a comparative analysis of machine learning methods for the canonical problem of empirical asset pricing: measuring asset risk premiums. We demonstrate large economic gains to investors using machine learning forecasts, in some cases doubling the performance of leading regression-based strategies from the literature. We identify the best-performing methods (trees and neural networks) and trace their predictive gains to allowing nonlinear predictor interactions missed by other methods. All methods agree on the same set of dominant predictive signals, a set that includes variations on momentum, liquidity, and volatility.  
  

8\. Factors That Fit the Time Series and Cross-Section of Stock Returns

摘要:  
中文: 我们提出了一种新的估计潜在资产定价因子的方法，这些因子适合预期收益的时间序列和横截面。我们的估计方法通过在预期收益的定价误差上施加惩罚，扩展了主成分分析（PCA）。我们的方法可以找到具有高夏普比率的弱因子，而PCA无法检测到这些因子。我们发现了五个具有经济意义的因素，这些因素很好地解释了特征排序的投资组合收益的横截面和时间序列。我们因子的样本外最大夏普比率是PCA的两倍，定价误差显著更小。我们的因子表明，大量的特征信息是冗余的。  
英文: We propose a new method for estimating latent asset pricing factors that fit the time series and cross-section of expected returns. Our estimator generalizes principal component analysis (PCA) by including a penalty on the pricing error in expected returns. Our approach finds weak factors with high Sharpe ratios that PCA cannot detect. We discover five factors with economic meaning that explain well the cross-section and time series of characteristic-sorted portfolio returns. The out-of-sample maximum Sharpe ratio of our factors is twice as large as with PCA with substantially smaller pricing errors. Our factors imply that a significant amount of characteristic information is redundant.  
  

  

9\. Dissecting Characteristics Nonparametrically

摘要:  
中文: 我们提出了一种非参数方法来研究哪些特征为预期收益的横截面提供了增量信息。我们使用自适应组LASSO选择特征，并非参数地估计所选特征如何影响预期收益。我们的方法可以处理大量特征，并允许灵活的函数形式。我们的实现对异常值不敏感。许多先前确定的收益预测因子并不为预期收益提供增量信息，非线性很重要。我们在模拟中研究了我们方法的属性，发现与替代选择方法相比，在模型选择和预测方面都有很大的改进。  
英文: We propose a nonparametric method to study which characteristics provide incremental information for the cross-section of expected returns. We use the adaptive group LASSO to select characteristics and to estimate how selected characteristics affect expected returns nonparametrically. Our method can handle a large number of characteristics and allows for a flexible functional form. Our implementation is insensitive to outliers. Many of the previously identified return predictors don’t provide incremental information for expected returns, and nonlinearities are important. We study our method’s properties in simulations and find large improvements in both model selection and prediction compared to alternative selection methods.