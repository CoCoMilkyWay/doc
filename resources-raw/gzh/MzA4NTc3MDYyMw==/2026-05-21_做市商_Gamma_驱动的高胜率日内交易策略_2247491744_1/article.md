# 做市商 Gamma 驱动的高胜率日内交易策略

InfinityQuant 映翡量化 2026-05-21 09:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491744&idx=1&sn=caca17bdb70f814deb0946034143fc3b&chksm=9e5ba1eab347af1b4a032ccda4aa1a8f8984d3795a88b56a6fe387eed9c24ad4ebe8c96ee3d2#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491744&idx=1&sn=caca17bdb70f814deb0946034143fc3b&chksm=9e5ba1eab347af1b4a032ccda4aa1a8f8984d3795a88b56a6fe387eed9c24ad4ebe8c96ee3d2#rd)

321 笔交易，胜率 77%，每个季度均实现盈利。

这篇文章《Regime-Conditioned Directional Prediction of the S&P 500 Index: A Walk-Forward Validation Study Using Dealer Greek Exposure》（2026年5月10日）将标普500的方向预测建立在做市商 Gamma 状态之上，结果看起来并非噪声。

核心框架：

-   使用三状态隐马尔可夫模型（HMM）将每个交易日划分为三类：
    

-   Pin（钉住/稳定性，做市商多 Gamma → 均值回归）
    
-   Vacuum（真空/中性，Gamma 中性）
    
-   Accelerant（加速/不稳定性，做市商空 Gamma → 动量放大）
    

-   在不同状态下分别训练自适应的 XGBoost 模型（按方向划分），用于预测日内走势
    
-   通过两阶段“信号强度”筛选入场；利用做市商资金流信号触发提前离场
    
-   采用 15 个月滚动向前（walk-forward）的样本外测试，构建六个近似不相关的策略子组合（sleeves）
    

结果表现：

-   累计收益 +3,063 个 SPX 点（共 321 笔交易）
    
-   盈利因子 4.40，最大回撤仅为累计收益的 2.2%
    
-   Vacuum 多头策略：胜率 92%，风险收益比 2.86
    
-   将状态标签随机化后，策略表现退化为接近随机（抛硬币） → 说明状态划分具有真实信息含量
    

关键结论：  
最简单的模型（Pin 多头，13 个特征，深度为 3 的树）反而取得最高胜率（81%）。压缩型市场状态（compression regimes）往往蕴含高度集中的交易信号。

![](assets/001.png)

![](assets/002.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6741978

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)