# 不是所有波动率都是风险，只有下行波动率才是

InfinityQuant 映翡量化 2026-05-09 09:12 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491640&idx=1&sn=6f5279c342927858d442c0be7fa8bda7&chksm=9e8983b4baaea213c9433fc9d7e270ddc1a3ca4dbb05d11e2152f3593e2ece07a455a77b092e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491640&idx=1&sn=6f5279c342927858d442c0be7fa8bda7&chksm=9e8983b4baaea213c9433fc9d7e270ddc1a3ca4dbb05d11e2152f3593e2ece07a455a77b092e#rd)

不是所有波动率都是风险，只有下行波动率才是。新论文《Variance and Skewness Risk Premium and Expected Equity Returns》（2026年5月4日）提出：著名的“VRP预测股票收益”结果实际上完全由下行方差驱动。将上行方差和下行方差分开后，结果彻底改变：

-   总体VRP作为正向预测因子的统计显著性不成立（p ≈ 0.10）。
-   下行VRP（DVRP）则高度显著（p < 0.01）。
-   仅使用DVRP就能将3个月预测 horizon 的调整后R²从10%提升至14%：依然呈现Bollerslev发现的驼峰形状，但信号更加干净。
-   偏度风险溢价（Skewness Risk Premium, SRP）在更长 horizon（12个月）开始发挥作用，它是一个独立且不相关的信号：投资者正在为尾部风险定价。
-   SRP的期限结构（3M - 1M）为长期收益提供了额外的预测能力。

两条清晰的结论：

-   存在两种不同的风险溢价；
-   它们作用于不同的时间尺度。

核心信息只有一句话：投资者并不害怕波动率，他们害怕的是下行亏损（drawdowns）。

![](assets/001.png)

![](assets/002.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6712647

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)