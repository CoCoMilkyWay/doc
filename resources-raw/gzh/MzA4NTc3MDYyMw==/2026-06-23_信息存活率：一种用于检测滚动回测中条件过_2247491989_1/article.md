# 信息存活率：一种用于检测滚动回测中条件过拟合的策略内诊断指标

InfinityQuant 映翡量化 2026-06-23 08:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491989&idx=1&sn=36cb0fd337fd0a750704cff51f8ca1a3&chksm=9e1218ee61338bc300fbedb96b3b540cca78ba49cc560677408789335b3e1989477bb3954d78#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491989&idx=1&sn=36cb0fd337fd0a750704cff51f8ca1a3&chksm=9e1218ee61338bc300fbedb96b3b540cca78ba49cc560677408789335b3e1989477bb3954d78#rd)

# 这篇论文《The Information-Survival Ratio: A Within-Strategy Diagnostic of Conditioning Overfit in Walk-Forward Backtests》（2026年6月17日）提出了一个新的回测诊断指标——**信息存活率**（Information-Survival Ratio, ISR），用来衡量策略在样本内使用的“条件信息”有多少能在 walk-forward / 样本外检验中保留下来。

## 核心问题

作者关注的不是“策略在多次试验里是不是碰巧选中了一个好结果”，而是更细的一层：**同一条策略内部，用来做择时或加权的市场状态****信息（如过去收益、波动率、宏观信号），到了样本外还能不能继续起作用**。这解决的是一种“策略内过拟合”问题，而不是传统多重检验意义上的“策略间过拟合”。

## 方法定义

ISR 的定义很简单：先在样本内给策略一个信息预算，用 Kullback–Leibler 散度来表示；再看 walk-forward cross-validation 最终保留下来的预算是多少，二者之比就是 ISR。

![](assets/001.png)

数值范围在 0 到 1 之间，1 表示样本内的条件信息完全能延续到样本外，0 表示它基本退化成无条件基准。

## 理论贡献

论文不仅提出指标，还给出了对应的选择推断理论：包括交叉拟合（cross-fitting）、时间缓冲区（buffer block）、有限网格上的 argmax 推断，以及在混合时间序列下的指数型收敛和 stationary block bootstrap 有效性。  
作者强调，之所以不用直接拿 Sharpe ratio 做选择目标，是因为 Sharpe 在有限样本里不够稳定，而基于 winsorised returns 的均值-方差目标更适合做这种推断。

## 实证结论  
实证部分覆盖了股票组合、行业组合、动量组合、对冲基金指数和单只股票等面板。  
总体上，**对冲基金指数的条件信息存活率最高**，通常接近或高于 0.90；**单只股票最低**，说明特质噪声会严重吞噬条件信号。  
不同信号并不存在全局最优：有的资产更适合用波动率条件化，有的更适合用滞后收益，最优条件集合明显依赖资产类别。

## 论文的实践含义

一个策略即使回测 Sharpe 很强，如果其背后的条件逻辑在 walk-forward 中无法保留，真实可复制性仍然值得怀疑。  
作者建议把 ISR 与 walk-forward Sharpe、deflated Sharpe ratio、PBO 一起报告，因为它们回答的是不同问题，彼此互补。

## 一句话总结

它把“回测里用了多少条件信息，到了未来还能剩多少”这个问题，变成了一个可计算、可比较、可做推断的指标。

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6905139

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)