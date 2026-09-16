# 成长—防御风格配置的连续择时信号：因子归因、风险匹配与样本外证据

InfinityQuant 映翡量化 2026-06-16 08:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491925&idx=1&sn=365396a69e9a216de6acbbe5b35bfbcd&chksm=9e11adeca6b1dbdd0238d7ca72ee87ac6159db06e9c8ac402219900742b1bb16c927f773cac9#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491925&idx=1&sn=365396a69e9a216de6acbbe5b35bfbcd&chksm=9e11adeca6b1dbdd0238d7ca72ee87ac6159db06e9c8ac402219900742b1bb16c927f773cac9#rd)

实现了与100%成长策略几乎一致的年化复合增长率（CAGR），同时将最大回撤几乎减半。

一篇新论文《Continuous Timing Signals for Growth-Defensive Style Allocation: Factor Attribution, Risk Matching, and Out-of-Sample Evidence》（2026年5月20日）为经典的“成长 vs 防御型 ETF”交易构建了一个连续的择时信号……而且在2022年之后依然有效：

-   CAGR：15.30%（对比 100% 成长的 15.45%）
    
-   最大回撤：-19.89%（对比 -33.92%）
    
-   夏普比率：0.90（对比 0.72）
    

核心方法：

不再使用离散的“恐慌 / 复苏”标签，而是基于以下因素构建一个平滑的连续评分：

-   利率缓解（ΔTNX）
    
-   SPY回撤深度
    
-   VIX压力与缓解
    
-   成长拥挤惩罚（在低利率、低VIX环境下，当成长已经上涨时，惩罚继续加仓的行为）
    

方法上采用 Softplus 交互项、tanh 权重映射以及 EWMA 平滑处理，没有任何 if-then 规则。

这篇论文的态度也相当诚实：作者首先进行了 Fama-French + 动量归因，确认 G − D（成长减防御）并不存在显著α（t = 0.81），并将整个方法明确定位为风格择时（style timing），而非寻找异常收益。同时也承认，在完整样本期内，100%成长策略在绝对CAGR上仍然略胜一筹。

![](assets/001.png)

https://arxiv.org/abs/2605.20636

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)