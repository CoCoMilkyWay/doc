# 通过波动聚类与因果结构识别实现市场择时

InfinityQuant 映翡量化 2025-10-30 12:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487840&idx=1&sn=c256bbe50b0bf1850dccbe966f225fd8&chksm=9e6c8ab52c736eb061013341da126e1f062994f65e388d452988b57cf2188687b2c891e3fa8d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487840&idx=1&sn=c256bbe50b0bf1850dccbe966f225fd8&chksm=9e6c8ab52c736eb061013341da126e1f062994f65e388d452988b57cf2188687b2c891e3fa8d#rd)

**波动在交易和风险管理中扮演着关键角色。如今，越来越多的投资组合经理意识到并利用波动率指标，即使他们并不交易期权。**

**《_Statistical Arbitrage Volatility-Driven with Statistics and Machine Learning Models for Stock Market Forecasting》_为这一研究领域做出了贡献，该文通过对股票按波动率进行分类并加以交易。具体而言，作者首先采用高斯混合模型（GMM）****对具有相似波动特征的股票进行分组。随后，应用基于**格兰杰因果检验（GCT）**并辅以**有效转移熵（ETE）的因果推断框架，识别领先-滞后关系，最终根据领先股票生成的市场择时信号进行交易。

![](assets/001.png)

主要内容：

> 本文提出了一种新颖的**波动驱动统计套利方法**，用于股票市场预测，该方法整合了复杂统计技术与机器学习模型。通过使用GMM聚类算法根据中程波动率对股票进行分类，我们展示了此类集群作为预测价格运动指标的潜力。该方法结合了包含**格兰杰因果检验、Peter-Clarke瞬时条件独立性检验和有效转移熵**的稳健因果分析框架，识别出股票间显著的预测关系。此外，动态时间规整（DTW）与K近邻（KNN）的整合通过对齐和分类时间序列数据提升了预测精度，从而能够提前捕捉盈利交易机会。

该整合方法的有效性通过回测结果得以验证。基于识别出的**波动聚类与因果关系**的交易策略，在多个绩效指标上持续优于**买入并持有基准**，包括总回报、夏普比率和最大回撤。值得注意的是，**波动驱动策略在控制风险敞口的同时实现了可观回报**，其**索提诺比率和卡玛比率**均显著优于传统策略。

简而言之，作者通过**GMM聚类具有相似波动特征的股票**，并运用因果推断技术确定**领先-滞后对**，开发出一种实现**优异风险调整后收益**的交易策略。

有两个局限性：

1.  该框架涉及多个模型，**参数数量增加，存在过拟合风险**；
    
2.  似乎仅进行了**样本内测试**。
    

  

Ivan Letteri, _Statistical Arbitrage Volatility-Driven with Statistics and Machine Learning Models for Stock Market Forecasting_, SN COMPUT. SCI. **6**, 918 (2025).

https://www.researchgate.net/publication/396622778\_Statistical\_Arbitrage\_Volatility-Driven\_with\_Statistics\_and\_Machine\_Learning\_Models\_for\_Stock\_Market\_Forecasting

PDF已更新⬇️ 

直达：https://t.zsxq.com/gW014

![](assets/002.jpg)