# 应对市场状态切换与肥尾收益的投资组合优化：基于贝叶斯 VAR 和椭圆 Black-Litterman 方法

InfinityQuant 映翡量化 2026-06-10 09:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491899&idx=1&sn=028aa4f98df842e3fc2acd1fe2a35195&chksm=9edaac1197f42cdf7a7531fec35bc450f9aa291f42719ecfac4164099bba3bc4e7b12e0adcc8#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491899&idx=1&sn=028aa4f98df842e3fc2acd1fe2a35195&chksm=9edaac1197f42cdf7a7531fec35bc450f9aa291f42719ecfac4164099bba3bc4e7b12e0adcc8#rd)

剥离其中一个关键组件后，夏普比率从 1.72 断崖式下降至 0.05。

这篇最新论文《Addressing Market Regime Changes and Heavy-Tailed Returns in Portfolio Optimization via Bayesian VAR and Elliptical Black-Litterman》（2026年6月8日）提出了一种新的投资组合模型，严肃地刻画了两个市场现实：**市场存在状态切换（regime shifts），且收益分布具有肥尾特征（fat tails）**。

该框架名为 **BAVAR-BLED**，将两个核心思想嵌入强化学习代理中：

-   一个由 600 个贝叶斯 VAR 模型构成的集成系统，能够随着市场变化动态调整权重，在无需人工标注的情况下自适应识别市场 **regime** ；
    
-   基于 Student's t 分布的 Black-Litterman 模型，从而避免低估极端事件风险。
    

在 29 只道琼斯成分股上进行回测（覆盖 2014–2024 年期间的利率周期及行业轮动等）：

-   夏普比率 1.72，索提诺比率 2.70，总收益率 57.3%；
    
-   最大回撤仅为 8.85%；
    
-   在统计意义上优于 16 个基准模型中的 15 个，包括 TimeXer、PPO 和 A2C。
    

消融实验的关键发现是：**一旦移除自适应先验机制，模型性能将全面崩塌——夏普比率从 1.72 降至 0.05。换言之，对市场 regime 的感知能力才是真正的 alpha（超额收益来源）。**

![](assets/001.png)

![](assets/002.png)

https://arxiv.org/abs/2606.09104

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)