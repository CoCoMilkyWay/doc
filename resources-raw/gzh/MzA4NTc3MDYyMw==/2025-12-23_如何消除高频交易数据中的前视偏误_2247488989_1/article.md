# 如何消除高频交易数据中的前视偏误

InfinityQuant 映翡量化 2025-12-23 08:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488989&idx=1&sn=e79eb0eed2a4efa484a8ce36c76a9f1b&chksm=9ee582909ebc305de3aa63e98f99b38d2ad87021654360dc8723ecc312c24ec4365f2444db03#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488989&idx=1&sn=e79eb0eed2a4efa484a8ce36c76a9f1b&chksm=9ee582909ebc305de3aa63e98f99b38d2ad87021654360dc8723ecc312c24ec4365f2444db03#rd)

![](assets/001.png)

**点击蓝字 关注我们**

**论文信息：**

**标题：** Latency and the Look-Ahead Bias in Trade and Quote Data

**作者：** Robert H. Battalio, Craig W. Holden , Matthew Pierson, John J. Shim, Jun Wu，

**发布日期：** 2025年12月15日 

  

论文研究发现，广泛用于金融研究和监管分析的 NYSE TAQ 数据中，基于 SIP生成的 NBBO 存在系统性的**前视偏误（look-ahead bias）**。**NYSE TAQ 数据**是金融学、市场微观结构和证券监管中最常用的高频交易数据来源之一。TAQ 数据由 **Securities Information Processor（SIP）**汇总全美所有交易所的交易和最优报价（BBO），并生成 **NBBO（National Best Bid and Offer）。**

由于不同交易所到 SIP 的传输延迟差异（约 15–550 微秒），以及交易与报价在极短时间内高度聚集，SIP 经常将**交易之后才发生的报价变化错误地记录为交易之前发生**。结果是，研究者在“交易发生前”看到的 SIP NBBO 中点，已经包含了该交易本身引发的价格反应。

![](assets/002.png)

![](assets/001.png)

这一前视偏误直接导致两类关键问题：第一，使用 SIP NBBO 中点进行交易方向判定（如 Lee–Ready 方法）时，约 13%–20% 的交易被错误签名，高延迟交易中错误率更高；第二，有效价差和价格冲击被系统性低估，平均低估幅度约 13%–17%，在高延迟交易中甚至超过 40%。

针对上述问题，作者提出了一种**基于交易所最优报价（EX BBO）的交易签名方法**。该方法不再使用 SIP NBBO，而是利用交易发生所在交易所的最优买卖价，并基于交易所撮合规则判断交易方向，同时**使用交易所时间戳而非 SIP 时间戳**。实证结果表明，对于与可显示限价单成交的交易（占大部分成交量），该方法在直连数据验证下可实现接近 100% 的签名准确率。

此外，作者构建了一个**延迟自由 NBBO（Latency-Free NBBO, LF NBBO）**，通过交易所时间戳在所有交易所间同步聚合最优报价，作为无前视偏误的基准价格，用于更准确地衡量有效价差和价格冲击。

![](assets/003.png)

![](assets/001.png)

总体而言，本文解决了 SIP 数据在高频环境下“时间顺序失真”的根本问题，提供了更简单、透明且准确的交易签名算法，并显著改善了流动性与价格冲击测度，对高频金融研究和监管实践具有重要方法论意义。

  

有需要的研究原文哦！

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5907665

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)

![](assets/001.png)