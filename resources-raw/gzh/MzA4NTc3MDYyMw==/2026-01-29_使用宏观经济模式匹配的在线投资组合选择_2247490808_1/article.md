# 使用宏观经济模式匹配的在线投资组合选择

InfinityQuant 映翡量化 2026-01-29 10:06 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490808&idx=1&sn=55022627a5914155aa1b0f5a7282ebca&chksm=9e94d8c26f016c18821b7a0e473dc48b3e2c7368b4604acaee2cf624d1eb4440172bd9985fd6#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490808&idx=1&sn=55022627a5914155aa1b0f5a7282ebca&chksm=9e94d8c26f016c18821b7a0e473dc48b3e2c7368b4604acaee2cf624d1eb4440172bd9985fd6#rd)

**宏观“模式匹配” + 在线投资组合 = 主要股指 Sharpe 比率约 1.3。**

大多数模式匹配策略只关注价格。这个预印本《Online Portfolio Selection Using Macroeconomic Pattern Matching》（2026年1月22日）完全颠倒了思路：

-   **步骤 1：使用Δβ（不对称宏观敏感性）挑选真正“随宏观波动”的股票**

-   **步骤 2：对它们进行聚类（层次聚类 + 对称不确定性），避免冗余押注**
-   **步骤 3：两阶段类比搜索：先在历史上找到相似的宏观 regime（状态/时期），然后在那些 regime 内寻找相似的股票模式**
-   **步骤 4：按溢出重要性（spillover importance）加权宏观信号，从每个簇中挑选最强的个股，并进行分配**

**结果**（1995–2023，日频）：宏观感知的聚类模型表现最佳，在标普 500 上等权（EW）累计收益约 **110%**，在道琼斯和日经指数上也展现出显著超额表现。

这是一个将宏观 regime 识别与股票层面模式匹配深度结合的在线（online）投资组合构建框架，显著提升了风险调整后收益（Sharpe ~1.3）。

![](assets/001.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6115073

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)

[2026年1月23日量化投资峰会 部分资料](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490784&idx=2&sn=b224c879bd9a80e26cc1542c29eef3f8&scene=21#wechat_redirect)

《2025-2026中国量化投资红皮书》pdf可以去星球获取

![](assets/003.png)