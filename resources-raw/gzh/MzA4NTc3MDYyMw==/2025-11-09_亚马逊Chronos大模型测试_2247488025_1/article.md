# 亚马逊Chronos大模型测试

InfinityQuant 映翡量化 2025-11-09 09:13 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488025&idx=1&sn=9552233f17ad1889aa26d3420e0ac8d4&chksm=9eaaeb97db20b861f5be675aad5e3d1dca17328568973377e791f40a38719cb0b6608d68a0ce#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488025&idx=1&sn=9552233f17ad1889aa26d3420e0ac8d4&chksm=9eaaeb97db20b861f5be675aad5e3d1dca17328568973377e791f40a38719cb0b6608d68a0ce#rd)

无需金融数据，无需调优，仍能预测股票。

一篇新论文《LLMs for Time Series: an Application for Single Stocks and Statistical Arbitrage》测试了亚马逊的 Chronos 大模型——该模型预训练于非金融数据——用于预测单只股票收益。

仅凭 100 天的残差收益数据，其表现便超越 ARIMA，并可与 CNN-Transformer 媲美。

即使在零样本模式下，夏普比率仍超过 3——无需任何金融微调。 若每日微调，Chronos 的夏普比率可达 4.2，能捕捉均值回归与微观低效。

尽管交易成本仍可能侵蚀利润，但信号真实存在：即便仅用天气数据训练，大语言模型也能从市场噪声中发现阿尔法。

![](assets/001.png)

  

有点神奇吧，看原文哦。

https://arxiv.org/abs/2412.09394v2

PDF已更新⬇️

欢迎加入：学术界的Alpha

![](assets/002.jpg)