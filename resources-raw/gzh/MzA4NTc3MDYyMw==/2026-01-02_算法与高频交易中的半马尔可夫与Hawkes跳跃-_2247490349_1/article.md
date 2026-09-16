# 算法与高频交易中的半马尔可夫与Hawkes跳跃-扩散模型研究

InfinityQuant 映翡量化 2026-01-02 15:51 浙江

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490349&idx=1&sn=36eb6e600cf942039307090938bbb077&chksm=9ec8a12e196731a902772279c9cc5b8bb197331feb4596c80b236e6c548929ed7463fd2c6e79#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490349&idx=1&sn=36eb6e600cf942039307090938bbb077&chksm=9ec8a12e196731a902772279c9cc5b8bb197331feb4596c80b236e6c548929ed7463fd2c6e79#rd)

标题：Algorithmic and High-Frequency Trading Problems for Semi-Markov and Hawkes Jump-Diffusion Models

作者：Luca Lalor and Anatoliy Swishchuk

发布日期：2025年3月4日

* * *

这篇论文没有追求阿尔法或提出又一个策略，而是专注于市场不确定性下的决策机制。

核心内容：

使用基于半马尔可夫（Semi-Markov）和霍克斯过程（Hawkes process）的跳跃-扩散模型，来捕捉波动率机制、聚类效应，以及新闻驱动的市场冲击，这些是交易者在实时中实际感受到的现象。

该模型不会告诉你交易什么，而是帮助你决定如何交易以及何时交易。明确捕捉了限价单簿（limit order books）中的非马尔可夫行为，将新闻到达和订单流聚类视为一流要素，而不是噪声。该框架应用于最优收购和清算，直接影响执行质量。

最大启发：

有时优势不是阿尔法，而是压力下的更好执行、对波动率的更快反应，以及理解市场何时即将失常。

论文桥接了理论与实践，适合对市场微观结构感兴趣的量化交易者阅读。

![](assets/001.png)

https://arxiv.org/abs/2409.12776

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)