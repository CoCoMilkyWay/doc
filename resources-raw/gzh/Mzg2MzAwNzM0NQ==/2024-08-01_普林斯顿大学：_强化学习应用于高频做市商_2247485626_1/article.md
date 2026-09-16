# 普林斯顿大学： 强化学习应用于高频做市商策略分析

QuantML 2024-08-01 23:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485626&idx=1&sn=2eb9cf8553fb6791afedb74c0cd6b34c&chksm=cfdbcaec40691b3f2cfaaf67fb057db7bf0010837f6f0c7c72fa469f161ae1b97616a14a768b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485626&idx=1&sn=2eb9cf8553fb6791afedb74c0cd6b34c&chksm=cfdbcaec40691b3f2cfaaf67fb057db7bf0010837f6f0c7c72fa469f161ae1b97616a14a768b#rd)

这篇论文《Reinforcement Learning in High-frequency Market Making》建立了一个新的理论框架，用于分析和理解强化学习（RL）在高频市场做市商策略中的应用。作者通过将现代RL理论与高频金融中的连续时间统计模型相结合，首次为市场做市商问题提供了理论分析。研究聚焦于采样频率对RL算法性能的影响，发现了一个有趣的误差与复杂性之间的权衡：随着时间增量∆的减小，算法的误差会降低，但同时算法的复杂性会增加。此外，论文还探讨了在一般求和博弈框架下的两玩家模型，证明了当∆趋近于0时，离散时间模型的纳什均衡会收敛到连续时间博弈的均衡。作者应用了纳什Q学习方法来求解均衡，并通过蒙特卡洛模拟提供了理论结果的实证支持。这些理论不仅对选择采样频率具有指导意义，而且对其他高频金融决策问题也具有广泛的适用性。

![图1](assets/001.png)

图1