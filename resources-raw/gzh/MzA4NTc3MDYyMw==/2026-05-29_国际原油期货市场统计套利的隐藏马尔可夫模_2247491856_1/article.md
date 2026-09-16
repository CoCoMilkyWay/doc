# 国际原油期货市场统计套利的隐藏马尔可夫模型

InfinityQuant 映翡量化 2026-05-29 09:02 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491856&idx=1&sn=44e437359482b6f81fc493aa34ff2542&chksm=9ef038b7a938aea0076617a06dd58b194aa3ac8c4687e4835e88fd12dddc19be00b5df745c2f#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491856&idx=1&sn=44e437359482b6f81fc493aa34ff2542&chksm=9ef038b7a938aea0076617a06dd58b194aa3ac8c4687e4835e88fd12dddc19be00b5df745c2f#rd)

通过直觉来看，原油套利似乎已经高度有效。然而，这篇论文《A hidden Markov model for statistical arbitrage in international crude oil futures markets》（2026年4月）表明，新兴市场仍然可能存在可获取的超额收益。

通过将布伦特（Brent）、WTI以及上海原油期货结合到一个状态切换的统计套利框架中，作者发现全球原油基准之间的暂时性错位依然具有出人意料的交易价值。

该模型不再假设价差以恒定速度回归均值，而是通过识别隐藏的市场状态，在不同市场环境下动态调整交易头寸。

表现最优的隐马尔可夫模型（HMM）设定，在扣除交易成本后，样本外年化超额收益约为6%–8%，夏普比率约为1–1.3。相比之下，简单的基于历史的价差策略表现明显较差。

新兴市场通常在套利资本尚未完全压缩价差之前，会带来新的交易机会。

![](assets/001.png)

  

https://www.sciencedirect.com/science/article/pii/S0378426626000889

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)