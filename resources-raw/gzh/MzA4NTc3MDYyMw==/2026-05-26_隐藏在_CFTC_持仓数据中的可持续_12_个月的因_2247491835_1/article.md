# 隐藏在 CFTC 持仓数据中的可持续 12 个月的因子

InfinityQuant 映翡量化 2026-05-26 08:48 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491835&idx=1&sn=7eecea2e3c059dcae286b209ca66c68e&chksm=9e59eff83643c8b574e5042daec8fbec6594d4d096b9cd1f2c154a1c45471993bd05725418da#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491835&idx=1&sn=7eecea2e3c059dcae286b209ca66c68e&chksm=9e59eff83643c8b574e5042daec8fbec6594d4d096b9cd1f2c154a1c45471993bd05725418da#rd)

13% 的年化收益率，夏普比率 0.65。一种隐藏在 CFTC 持仓数据中的、可持续 12 个月的信号。

# 《Extrapolative Commodity Returns》（2026年5月11日）这篇论文发现，大宗商品投机者会对过去收益进行外推，而你可以系统性地“抢跑”他们的行为。

作者基于 1986–2024 年间 26 种美国大宗商品的非商业交易者持仓，构建了一个新的“外推程度”（Degree of Extrapolation, DOX）指标：

![](assets/001.png)

-   构建的 DOX 多空组合年化收益达 13.11%，夏普比率 0.65，优于传统动量策略
    
-   收益可持续长达 12 个月（没有快速反转，因此并非泡沫驱动）
    
-   在控制所有已知的大宗商品因子后仍然显著：包括期限结构、基差动量、套期保值压力、价值因子和多期限动量，月度 Alpha 仍保持在 0.71%–0.93%
    
-   将同一逻辑扩展至期货曲线（Basis-DOX）后，夏普比率进一步提升至 0.78，为论文中最高
    

其机制并非“错误定价”，而是“流动性提供”：外推型投机者在价格上涨后不断加仓，随后缓慢平仓，在此过程中向对手方（商业套保者）支付流动性溢价。2021 年 CFTC 持仓限制改革提供了一个干净的外生冲击，从而验证了这一机制。

额外发现：DOX 解释了为什么动量和价值因子在大宗商品中有效——动量主要存在于高 DOX 品种中，而价值主要存在于低 DOX 品种中。

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6745679

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)