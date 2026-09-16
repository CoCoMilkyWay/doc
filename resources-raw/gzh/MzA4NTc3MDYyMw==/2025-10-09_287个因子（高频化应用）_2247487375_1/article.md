# 287个因子（高频化应用）

InfinityQuant 映翡量化 2025-10-09 15:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487375&idx=1&sn=55adc938226dc0818aa62f385be3357b&chksm=9e932fff7d3b55cd552019ed74145e08e381e61855aa2648233e87f904cdf08b9a31ff518b01#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487375&idx=1&sn=55adc938226dc0818aa62f385be3357b&chksm=9e932fff7d3b55cd552019ed74145e08e381e61855aa2648233e87f904cdf08b9a31ff518b01#rd)

波动率预测的新视角：市场“叙事”的力量。  

如果股票波动率不仅由盈利和利率驱动，还取决于市场正在追逐的“叙事”呢？

波动率常被视为神秘力量，但新研究表明它可能比想象中更易预测。本文研究了高频因子波动性在单个股票波动性建模中的预测作用。通过分析287个不同市场因子的高频数据（涵盖价值、动量、规模等因子，但规模远超传统框架），本研究构建了一个动态模型，能够实时识别驱动个股波动率的最关键因子。   

该模型显著优于HAR等主流预测方法，因其核心逻辑在于：波动率并非由单一静态源驱动，而是不同因子在市场不同阶段轮流主导。更值得注意的是，预测波动率最有效的因子往往与预测收益的因子截然不同（见图示），这意味着驱动风险与回报的叙事常呈分离状态。对交易员和风险管理者而言，这一发现至关重要：成功预测波动率需超越资产自身价格历史，深入理解“债券真实现金流风险与时变风险溢价之间的交互关系”。  

研究结果强调了将高频横截面信息纳入波动性建模的重要性，为了解股票市场的时变风险提供了一种可扩展和可解释的方法。

![](assets/001.png)

本文里高频化处理方法是改编Aït-Sahalia等（Aït-Sahalia, Y., Kalnina, I., Xiu, D., 2020. High-frequency factor models and regressions. Journal of Econometrics 216, 86–105.）的程序，以1秒网格采样计算日内回报。 【不过这两年的趋势应该是高频因子低频化，还是要看具体怎么应用】

附：287个因子。

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

![](assets/006.png)

![](assets/007.png)

![](assets/008.png)

![](assets/009.png)

![](assets/010.png)

![](assets/011.png)

![](assets/012.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5502438