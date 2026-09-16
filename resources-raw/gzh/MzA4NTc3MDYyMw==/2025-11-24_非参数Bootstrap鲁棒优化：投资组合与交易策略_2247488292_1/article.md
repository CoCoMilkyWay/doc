# 非参数Bootstrap鲁棒优化：投资组合与交易策略的稳健决策框架

InfinityQuant 映翡量化 2025-11-24 09:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488292&idx=1&sn=9cdbc3debc3026c9c14b058dce0d9f97&chksm=9e7aa2bd87363dbd8d5ad3b1cc8a9b3271a5da4caf808cebe8deed7788e6410a29134c40a9cd#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488292&idx=1&sn=9cdbc3debc3026c9c14b058dce0d9f97&chksm=9e7aa2bd87363dbd8d5ad3b1cc8a9b3271a5da4caf808cebe8deed7788e6410a29134c40a9cd#rd)

在金融决策中，参数估计误差与模型不确定性常导致投资组合权重剧烈波动，甚至引发样本外失效。传统均值-方差优化（MVO）对预期收益μ与协方差Σ的微小扰动极为敏感（Chopra, 1993; Michaud, 1998），而经验风险最小化（ERM）在交易策略调参中易陷入过拟合陷阱（Harvey & Liu, 2014）。为此，本文《(Non-Parametric) Bootstrap Robust Optimization for Portfolios and Trading Strategies》（2025/10/14）提出一种**非参数Bootstrap鲁棒优化框架**，通过重采样构建效用分布的经验置信区间，而不依赖特定分布假设，实现对下尾风险的显式控制。

### 一、鲁棒优化的三类范式

1.  **经典鲁棒优化：基于椭圆不确定集构造最小最大化问题（Goldfarb & Iyengar, 2003; Tütüncü & Koenig, 2004），依赖χ²分布假设。**
2.  **参数Bootstrap方法：利用渐进置信区间重构不确定集（Supandi et al., 2017）。**
3.  **贝叶斯鲁棒优化：整合先验与后验，优化预测分布下的期望效用（Anderson & Cheng, 2016）。**

上述方法或依赖强分布假设，或仅关注参数不确定性，难以全面刻画金融时序数据的复杂依赖结构。

### 二、核心思想：效用分布百分位优化

本文将**效用视为随机变量**，采用**块Bootstrap**（Lahiri, 2003）生成S个重采样路径，保留序列自相关性。优化效用分布的**α百分位**（α=0.25）：

![](assets/001.png)

此目标等价于在最差α比例路径下的最优解，显式控制下尾风险。

三、实证

实验部分使用股票、期货等数据集，在长仓/长短仓设置下比较框架与基准（如标准MVO、椭圆不确定集和经验风险最小化）。结果显示，该方法在样本外性能更稳定，提供更高的风险调整回报、更浅的回撤和更小的泛化差距，尤其在中位百分位（40th-70th）选择下表现优异。

结论强调该框架作为分布无关的实用替代方案，能有效提升金融机器学习中的鲁棒性和泛化，并建议未来扩展到多资产策略、动态环境和与贝叶斯结合。

![](assets/002.png)

https://arxiv.org/abs/2510.12725v1

PDF已更新，更多策略⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)