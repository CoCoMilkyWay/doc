# 重新定义回报目标：排序预测让机器学习准确率提升近3倍

InfinityQuant 映翡量化 2026-05-02 08:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491592&idx=1&sn=7d29ba29b53c50e1deb5ca5bcfdc8ac3&chksm=9e439fcb51836b2cb90dd08d4258cd24c682195134af8ecfbc0de955e58b0ab519f2688f7dd5#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491592&idx=1&sn=7d29ba29b53c50e1deb5ca5bcfdc8ac3&chksm=9e439fcb51836b2cb90dd08d4258cd24c682195134af8ecfbc0de955e58b0ab519f2688f7dd5#rd)

《Getting the Target Right in Return Prediction》（2026年4月20日）提出：一个被长期忽视的关键——如何定义预测目标（Target Return），才是提升模型性能的核心。

关键发现

作者基于1994-2024年35个国际市场的海量股票数据发现：目标变量的转换对预测准确性和投资组合收益的影响，远大于特征工程。

将原始回报（Raw Returns）转换为标准化回报（Standardized Returns）或基于排序的回报（Rank-based Returns）后，预测准确性可提升近三倍，构建的投资组合回报几乎翻倍。而特征工程的边际贡献则相对有限。

为什么目标转换如此有效？

重新定义回报  
将目标回报定义为相对排序（relative ranks）而非原始数值，能让机器学习模型的预测准确性提升近三倍。

大多数量化研究员把主要精力放在清洗和缩放股票特征上，但这项研究明确揭示：如何定义预测目标才是模型表现的首要驱动因素。

从原始回报切换到排序或标准化目标后，模型能够有效过滤常见的市场噪声，将注意力集中在真正重要的事情上——在特定月份内，哪些股票的表现超越同伴。这种转变对于非线性模型（如随机森林）尤其强大：当面对原始的、重尾分布数据时，这些模型可能完全失效；但一旦目标被稳定化，它们就能充分发挥优势。

注意事项

然而，排序法并非万能。它会丢弃价格变动的实际幅度信息。这种损失在高波动板块中代价较高，例如微盘股（micro-cap stocks）或新兴市场。在这些市场中，极端回报往往蕴含着真实的经济信号，而不仅仅是噪声。

最终，最优的目标转换方式取决于特定市场的回报分布特征。忽略数据形状的投资者，很有可能是在为错误的目标进行优化。

![](assets/001.png)

![](assets/002.png)

之前有几篇研究排序的：

[夏普比率1.18，停止预测回报，开始预测排名](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491314&idx=1&sn=9d37fa805c8591e678ec9a63d99341d3&scene=21#wechat_redirect)

[夏普比率 3.0+ —— “排序学习”的动量策略](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487976&idx=1&sn=941f58f12c9ac32304f3c8a90a986417&scene=21#wechat_redirect)

[不确定性调整排序：机器学习在资产定价中的新方法](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490639&idx=1&sn=d39beda3d1f916ff0d5645f56b9bf428&scene=21#wechat_redirect)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6615698

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)