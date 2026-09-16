# 来自牛津大学的讲义：高频交易（HFT）和算法执行背后的数学模型与优化方法

InfinityQuant 映翡量化 2026-05-08 09:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491639&idx=2&sn=51e08f16ef11ec9b74410c8a424a9ee1&chksm=9e36796de96e66d0088cfceff08d5c3246a60765ad2db1504a7e358139d7d3365d9ffd95fa7d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491639&idx=2&sn=51e08f16ef11ec9b74410c8a424a9ee1&chksm=9e36796de96e66d0088cfceff08d5c3246a60765ad2db1504a7e358139d7d3365d9ffd95fa7d#rd)

这份讲义是牛津大学 2024 年《Lecture Notes on Market Microstructure and Algorithmic Trading》课程笔记，由 Fayçal Drissi编写，主要讲高频交易（HFT）和算法执行背后的数学模型与优化方法。

核心内容可以概括为三部分：

1.  **市场微观结构（Market Microstructure）**  
    
    介绍电子市场中的限价订单簿（LOB）、做市商、流动性提供者与交易者之间的互动机制，以及买卖价差、市场冲击（Market Impact）等概念。重点解释大额订单为什么会影响价格，以及交易成本如何形成。
    
2.  **最优执行（Optimal Execution）**  
    
    这是全书重点。作者系统讲解了经典的 Almgren–Chriss 模型，包括离散时间和连续时间版本，用随机控制与动态优化的方法求解“如何把大单拆分、以最低冲击成本完成交易”。同时还讨论了带预测信号、非线性冲击、多资产协整等扩展模型。
    
3.  **做市与高频策略（Market Making & HFT）**  
    
    分析做市商如何在持仓风险、价格波动和订单流之间平衡收益，并引入 OTC 市场、统计套利、均值回复、配对交易等策略。后半部分还延伸到 DeFi 与 AMM（自动做市商）机制。
    

整体风格偏“量化研究 + 数学金融”，大量使用随机控制、凸优化、HJB 方程、Riccati 方程等工具。它不是教“写交易策略代码”，而是从理论层面解释：高频市场中的交易成本、流动性和最优策略是如何建模与求解的。

![](assets/001.png)

https://www.faycaldrissi.com/files/HFT\_2024\_\_\_Oxford\_\_\_lecture\_notes\_2024.pdf

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)