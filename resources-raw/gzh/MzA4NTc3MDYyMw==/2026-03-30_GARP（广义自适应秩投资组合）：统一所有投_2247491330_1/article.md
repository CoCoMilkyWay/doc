# GARP（广义自适应秩投资组合）：统一所有投资组合框架的理论

InfinityQuant 映翡量化 2026-03-30 10:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491330&idx=1&sn=0b9ee0d70866623a844e36f4a05cb5ce&chksm=9ed8997bf53bd25da6c273698b31e64573bf4ede931a9b3cfaab9e8c7468350ea847ff86e497#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491330&idx=1&sn=0b9ee0d70866623a844e36f4a05cb5ce&chksm=9ed8997bf53bd25da6c273698b31e64573bf4ede931a9b3cfaab9e8c7468350ea847ff86e497#rd)

最新发布的论文《GARP: Generalized Adaptive Rank Portfolio A Crisis-Adaptive, Assumption-Free Framework for Portfolio Construction》（2026年3月19日），其核心主张非常大胆：HRP、ERC、IVP、1/N、HERC 和 BL-HRP 全部都是同一个递归方程的特例。

可以把它想象成投资组合构建领域的 GARCH：它并不与现有模型竞争……而是包含了它们。

GARP 的核心理念：

-   **无分布假设：完全基于“秩”（ranks）进行运算，因此在数学层面上，高斯先验、重尾分布和偏度都变得不再重要；**
-   **无硬性聚类切割：权重通过完整的树状图（dendrogram）从上到下连续累积；没有任意设定的簇数 k；**
-   **即插即用信号：可以将动量换成 alpha，将 VIX 换成宏观信号；整体架构无需改变；**
-   **专为危机自适应设计：仅通过一个标量 p(t) ∈ \[0,1\]，就能连续地将距离度量从相关性切换到协同崩盘（co-crash，下尾依赖），并将配置权重从传染性强的资产上移开。**

![](assets/001.png)

初步前置结果（尚未是完整 GARP）：样本外 684 周，夏普比率为 1.887，最大回撤 -7.13%，在 2020 年期间相对于等权配置，回撤减少了 75%。

完整的实证评估在另一篇配套论文中。本文是纯理论。

![](assets/002.png)

![](assets/003.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6420058

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)