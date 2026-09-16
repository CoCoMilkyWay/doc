# 预测宏观经济指标尾部风险的改进模型

InfinityQuant 映翡量化 2025-11-16 09:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488129&idx=1&sn=2e6bb87b8452aa142b669923d7be3b71&chksm=9e4037c105055fe4affafb24011451bf9b145b4beb37bd2046b23a4f648e4631e421c7fb2170#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488129&idx=1&sn=2e6bb87b8452aa142b669923d7be3b71&chksm=9e4037c105055fe4affafb24011451bf9b145b4beb37bd2046b23a4f648e4631e421c7fb2170#rd)

分位数回归在实证宏观经济学中已获得广泛应用，特别是在估算和预测宏观经济指标的尾部风险方面。Carriero (Queen Mary University of London), Clark (John Hopkins University) and Marcellino (Bocconi University, Baffi Centre) 研究了分位数回归（QR）设定中各种选择对预测宏观经济指标尾部风险的影响，这些指标包括美国的GDP增长、通胀和失业率，以及一些其他发达经济体的GDP增长。

![](assets/001.png)

这篇题为《Specification Choices in Quantile Regression for Empirical Macroeconomics》的论文于2025年2月发表在《应用计量经济学杂志》上，比较了不同模型在不同预测期限下的分位数预测准确性。论文发现，**贝叶斯分位数回归表现最佳**。对于包含多个预测变量的应用场景，贝叶斯收缩带来的收益相对较大且具有一致性（适用于不同应用、预测期限和分位数）。

从绝对预测性能来看，贝叶斯分位数回归也优于频率学派分位数回归——简单的频率学派分位数预测通常无法通过预测最优性检验，而贝叶斯分位数预测则可以通过。

基于该论文关于预测准确性的研究结果，对GDP增长、通胀和失业风险的新分析最好采用贝叶斯分位数回归，而非宏观经济学应用中最常用的经典分位数回归。

  

https://onlinelibrary.wiley.com/doi/abs/10.1002/jae.3099

https://baffi.unibocconi.eu/improved-model-forecast-tail-risk-macro-indicators

  

PDF已更新⬇️

欢迎加入：学术界的Alpha

![](assets/002.jpg)