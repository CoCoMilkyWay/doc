# 如何避开那些“怪异”的公司

InfinityQuant 映翡量化 2026-01-17 11:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490665&idx=1&sn=63467352f3ff22faa82d61b17b636466&chksm=9ed28927f6256eeae5bb87d4b245efa6a43e6275dd0fe7bbe472906afe198a78edc5ae838a30#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490665&idx=1&sn=63467352f3ff22faa82d61b17b636466&chksm=9ed28927f6256eeae5bb87d4b245efa6a43e6275dd0fe7bbe472906afe198a78edc5ae838a30#rd)

每月 **1.47%**的收益——仅仅通过避开那些“怪异”的公司。

一篇新论文《Hard to Process: Atypical Firms and the Cross-Section of Expected Stock Returns》（2025年12月）提出了 **ATYP**：一种用机器学习衡量公司“有多难被理解”的指标。  
作者用 **100 多个公司特征**训练了一个 **自编码器（autoencoder）**，然后用每只股票的重构误差（RMSE）来打分。误差越大，说明这些特征的组合越“非典型”，也就越难被投资者消化和理解。

![](assets/001.png)

**主要结果（1981–2023）：**

-   做多 **低 ATYP**、做空 **高 ATYP**：等权组合：+1.47% / 月；市值加权组合：+0.82% / 月；
    
-   **风险调整后**：FF6 Alpha约 **+0.84% / 月（对应高减低组合的 Alpha 为** **–0.84% / 月**，t = –4.52）；
    
-   **横截面回归**：即使控制了一大堆变量，ATYP 仍然显著（系数约 **–3.21**）。
    

**作用机制：**

-   在 **高 ATYP**公司中，**盈余公告后漂移（PEAD）**强度是低 ATYP 公司的 **3 倍**  
    （下个月收益 **0.89% vs 0.27%**）；
    
-   信息扩散更慢、投资者反应更迟钝。
    

**结论：**  
这种效应在**最容易出现错误定价的地方最强**——低关注度、难以套利的股票。

**有限注意力不是一种“感觉”或叙事，而是一种定价状态变量。**

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6048715

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)