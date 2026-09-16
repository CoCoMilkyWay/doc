# 宏观因子风险建模：基于 Regime-Time 与 Point-in-Time 的协方差

InfinityQuant 映翡量化 2026-06-21 08:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491982&idx=1&sn=1abbf6c0933b2907d02c339ae6688eab&chksm=9e48d5c4fa958c648f9db20bebb80acf7aa0e969d644cec94de98a65859ed62ffbd38cef8171#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491982&idx=1&sn=1abbf6c0933b2907d02c339ae6688eab&chksm=9e48d5c4fa958c648f9db20bebb80acf7aa0e969d644cec94de98a65859ed62ffbd38cef8171#rd)

大多数风险模型都隐含着一个默认假设：通过对近期历史数据使用滚动窗口估计得到的协方差矩阵，可以合理描述当前所持有的风险。然而，这一假设在两个方面存在缺陷，而且恰恰在最需要精确度的时候，这些缺陷会相互叠加放大。

QuantInsider的《Macro Factor Risk Modelling with Regime-Time and Point-in-Time Covariances》（2026年6月10日）尝试同时修正这两个问题。

## 1.状态时间协方差（Regime-Time Covariance）

跨资产相关性是**状态依赖（state-dependent）**的。在风险厌恶（risk-off）环境中，两类资产之间的相关性，与在平稳（benign）市场环境下的相关性有显著差异。而基于日历时间的滚动估计会将不同状态混合在一起，从而无法准确刻画任何一种状态。

更糟糕的是，当市场状态发生切换时，真实的相关性矩阵可能在几天内迅速变化，而滚动窗口方法却需要数月时间才能逐渐反映这一变化。

解决方案是：**在宏观状态指标条件下估计协方差矩阵**，并通过对各状态的滤波概率（filtered probabilities）加权，构建当前协方差的混合估计。这样，协方差估计可以随着状态变化迅速调整，而不是滞后跟随。

## 2.时点建模（Point-in-Time Evaluation）

策略层面的风险模型通常基于策略历史收益来估计协方差，这隐含假设策略在整个估计窗口期间保持不变。然而，一个从价值风格轮动到动量风格的投资组合，其历史收益反映的是过去的持仓结构，而非当前暴露。

“时点建模”的核心在于：**基于当前持仓，在当前因子模型下评估风险**，从而将投资组合方差清晰分解为因子贡献与特质风险（idiosyncratic risk）。

![](assets/001.png)

## 3.实践收益：Delta复制对冲（Delta Replication Overlay）

一旦我们实现了“时点暴露 + 状态协方差”的结合，对冲不希望暴露的因子就可以转化为一个**约束二次规划问题（constrained quadratic program）**：

在一组流动性良好的工具中，求解对冲权重，使得：

-   不希望的因子暴露被消除；
    
-   希望保留的因子暴露不被“泄漏”（即不被无意削弱）；
    
-   对冲组合的方差最小化。
    

第二个约束往往被实践者忽略，但实际上非常关键。例如，如果构建久期对冲时没有保护信用暴露，那么对冲过程中会不知不觉削弱原本希望保留的信用风险敞口。

![](assets/002.png)

## 4.扩展应用：因子风险预算约束

同一套方法还可以用于投资组合构建中的**因子方差上限控制**，即通过**二次约束二次规划（QCQP）**形式，限制任一因子对总方差的贡献比例。

  

https://www.linkedin.com/company/quant-insider/posts/?feedView=all

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)