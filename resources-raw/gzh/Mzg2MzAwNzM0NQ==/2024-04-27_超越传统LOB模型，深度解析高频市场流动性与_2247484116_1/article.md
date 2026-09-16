# 超越传统LOB模型，深度解析高频市场流动性与价格波动

QuantML QuantML 2024-04-27 10:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484116&idx=1&sn=f50834b5ba442b5a2e7582d3638e3112&chksm=cf32ee9d084bd93cee5fb390d6b63d10e20811a14f63bb11663f0da52c029a31410865109e53#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484116&idx=1&sn=f50834b5ba442b5a2e7582d3638e3112&chksm=cf32ee9d084bd93cee5fb390d6b63d10e20811a14f63bb11663f0da52c029a31410865109e53#rd)

Content  

本文的核心在于通过高频数据深入分析限价单簿（Limit Order Book, LOB）来预测买卖价差（Bid-Ask Spread）并理解全球中点价格（Global Mid-Price, GMP）现象。

### **1\. 引言 (Introduction)**

引言部分讨论了金融市场的复杂性，特别是价格形成机制和价差动态。作者指出限价单簿（LOB）是记录特定资产在不同价格水平上的买卖订单的关键结构。随着高频交易（High-Frequency Trading, HFT）的出现和金融市场复杂性的增加，需要更细致地检查这些动态，并识别出管理价差预测和全球中点价格现象的策略。

### **2\. 初步讨论 (Preliminaries)**

在这一部分，作者介绍了限价单簿（LOB）的基本概念，并定义了两个新的概念：总市场订单簿买卖价差（Total Market Order Book Bid-Ask Spread, TMOBBAS）和全球中点价格（Global Mid-Price, GMP）。TMOBBAS 是通过考虑 LOB 的整个深度来扩展传统的买卖价差和中点价格度量，提供了对市场动态更全面的视角。

![](assets/001.png)

### **3\. 数据 (The Data)**

作者讨论了获取用于计算 TMOBBAS 和 GMP 的高频 LOB 数据的挑战，并感谢 LOBSTER 提供的免费高频数据样本。论文使用了亚马逊（AMZN）、苹果（AAPL）和谷歌（GOOG）在 2012 年 6 月 21 日的交易数据，并描述了如何清洗和截断数据集以进行分析。

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

### **4\. 尾部行为分析 (Tail Behavior Analysis)**

这一章节探讨了 TMOBBAS 和 GMP 的对数收益率的分布，并指出这些收益率的分布明显是非高斯的。作者使用超额峰度（excess kurtosis）和鲁棒超额峰度（robust excess kurtosis）来量化对数收益率的非高斯性，并使用广义帕累托分布（Generalized Pareto Distribution, GPD）拟合尾部数据，以及 Hill 方法来估计尾部指数。

![](assets/005.png)

![](assets/006.png)

![](assets/007.png)

### **5\. 对数收益率的动态 (Dynamics of Log-Returns)**

作者在这一部分采用了时间序列方法来识别最适合 TMOBBAS 和 GMP 时间序列数据的模型。通过 ARMA(1,1)–GARCH(1,1) 模型结合正态逆高斯分布（Normal Inverse Gaussian, NIG）来模拟数据，并使用蒙特卡洛模拟生成预测的收益率样本。

![](assets/008.png)

![](assets/009.png)

### **6\. 期权定价和隐含波动率 (Option Pricing and Implied Volatility)**

这一章节介绍了如何为 TMOBBAS 和 GMP 指数定价期权并推导其隐含波动率。作者采用了双次服从过程（double-subordinated process）来模拟这两个指数，并使用快速傅里叶变换（Fast Fourier Transform, FFT）来计算期权价格。

![](assets/010.png)

### **7\. 风险-收益性能评估 (Evaluation of Risk–Return Performance)**

在这一部分，作者使用 Rachev 比率来衡量 TMOBBAS 和 GMP 的风险-收益性能。Rachev 比率是一种在非高斯设置中评估极端正收益相对于极端损失风险的比率。

![](assets/011.png)

### **8\. 总结 (Summary)**

最后，作者总结了研究发现，强调了 TMOBBAS 和 GMP 在提供市场流动性、波动性和效率方面的战略洞察力的重要性。论文不仅对学术讨论做出了贡献，还为交易员、风险管理师和政策制定者提供了实际意义。

  

  

  

  

**论文下载见星球**

  

**点击蓝字**

![](assets/012.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/013.jpg)

![](assets/014.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**