# Transformer预测的并非收益，而是它的“困惑”

InfinityQuant 映翡量化 2026-04-04 08:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491384&idx=1&sn=c3f0ef6586a5cca6ae082075fc898cf6&chksm=9e78ee9d859dbf901e26534fd5916e4fc536789383ae9ccd644c03a2cc56c1794d7e9e065723#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491384&idx=1&sn=c3f0ef6586a5cca6ae082075fc898cf6&chksm=9e78ee9d859dbf901e26534fd5916e4fc536789383ae9ccd644c03a2cc56c1794d7e9e065723#rd)

Transformer并没有预测股票的收益；它预测的是**自己的困惑程度。**

**罗格斯大学（Rutgers）的最新论文《Transformer Uncertainty and the Cross-Section of Stock Returns》（2026年4月2日）提出了一个名为** **WTrans** 的信号：它不是基于模型认为一只股票**会**获得怎样的收益，而是基于模型对这一预测**有多不确定性**。

单独来看，这种不确定性度量本身几乎没有预测力（t ≈ 0.5）。但当它与“异常共识方向”（µ）相互作用时，它成为近年来横截面资产定价研究中最强的信号之一：

-   在各种异常指标一致认为“该买”的股票中，**模型不确定性高 → 未来回报更高**；
    
-   在一致认为“该卖”的股票中，**模型不确定性高 → 未来回报更低**。
    

两者的交互项（µ × WTrans）的 Fama-MacBeth t 统计量达到 **8.68**，在 FF6 调整后的双重差分（DiD）回归中，月度 α 收益为 **+1.30%**。

该条件多空因子的 **R² 仅为 1.5%**（对 FF6 因子而言几乎完全正交），这意味着它真正提供了与现有“因子动物园”不同的新信息。

其背后的机制是投资者注意力不足导致的套利限制：这种溢价几乎只出现在媒体关注度少和分析师覆盖度较低的股票中，而在知情套利者活跃的股票中则基本消失。

在与“跨主题分歧”（σ）的直接竞争（horse race）中，该信号也表现更优——当 WTrans 进入同一回归方程时，σ的t统计量降至−0.19（变得不再显著）。

![](assets/001.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6412360

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)