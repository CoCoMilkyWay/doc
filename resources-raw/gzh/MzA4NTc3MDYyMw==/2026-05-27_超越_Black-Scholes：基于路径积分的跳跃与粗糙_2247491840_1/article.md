# 超越 Black-Scholes：基于路径积分的跳跃与粗糙波动率统一框架

InfinityQuant 映翡量化 2026-05-27 08:52 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491840&idx=1&sn=e5f7d4ff71b73118cf7eb5291e2ace2b&chksm=9e8adc7e74b5b8f231e9503eba64e7b6627f558bca940c9aae0c3b79b6073faa097e6aed0a80#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491840&idx=1&sn=e5f7d4ff71b73118cf7eb5291e2ace2b&chksm=9e8adc7e74b5b8f231e9503eba64e7b6627f558bca940c9aae0c3b79b6073faa097e6aed0a80#rd)

Black-Scholes 模型优雅，但在两个根本问题上是错误的，而几十年的高频数据已经使这些问题无法忽视：价格收益并非高斯分布，且波动率并非常数。《Path Integral Formulation of Option Pricing Beyond Black-Scholes: A Unified Framework for Jump-Diffusion and Rough Volatility》（2026年5月21日）这篇论文，从第一性原理出发，利用一个借鉴自理论物理的框架——费曼路径积分——来同时解决这两个问题。

核心思想：

期权定价本质上是对所有可能价格路径进行求和的问题。Black-Scholes 通过假设路径分布为高斯分布来求解，从而使积分变得可解，但也将“隐含波动率平坦”作为公理写入模型，而非由模型推导得出。期权市场中的每一个波动率微笑、偏斜以及厚尾现象，都是对这一假设的直接违背。

本文构建了一个统一的作用量泛函（action functional），在两个方向上扩展了经典的 Feynman–Kleinert 框架。

-   引入了 Lévy 稳定型跳跃-扩散过程，从而生成短期限期权中观察到的幂律尾部。
    
-   更为关键的一点，构建了一个基于分数布朗运动（fractional Brownian motion）的粗糙随机波动率扩展，其中 Hurst 指数 H 约为 0.1，这一数值已由 Gatheral、Jaisson 和 Rosenbaum 在股票、利率及大宗商品市场中得到经验验证。
    

![](assets/001.png)

结果：

最满意的结果是一个解析性的结论而非数值模拟。对于平值期权（ATM）的隐含波动率偏斜衰减，标准随机波动率模型预测其随期限 T 以 ![](assets/002.png) 衰减，而在本文的 Volterra 作用量框架下，该衰减形式为 ![](assets/003.png) 。当 H = 0.1 时，即为 ![](assets/004.png)，这一结果与真实期权市场观测高度一致，并且无需任何校准参数。仅通过已实现波动率估计得到的 Hurst 指数，就可以预测隐含波动率曲面的形状。

该框架还自然地建立了与微扰量子场论的联系。对 Black-Scholes 的每一个修正项，都对应一个费曼图拓扑结构。在分数作用量下，波动率场的两点函数正是分数布朗运动的协方差，而正是这种非局部协方差驱动了偏斜衰减速度的放缓。

![](assets/005.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6764698

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/006.png)