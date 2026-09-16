# 1.59倍隐形波动——“自由”的代价

QuantSeek QuantSeek 2026-01-04 23:12 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485463&idx=1&sn=4d870f06321e73375573f736b546dbba&chksm=ce22e3551c55f96e8a14050de68e74ffc5238bac1326290d22af35c6ff1bc7128e1f1d3d0fe0#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485463&idx=1&sn=4d870f06321e73375573f736b546dbba&chksm=ce22e3551c55f96e8a14050de68e74ffc5238bac1326290d22af35c6ff1bc7128e1f1d3d0fe0#rd)

# 一、研究背景与动机

近年来，机器学习（ML）在资产定价领域的应用迅速普及，大量研究表明非线性模型（如神经网络、树模型）在预测股票收益方面优于传统线性模型。然而，不同研究在模型设计上的选择差异巨大，导致结果难以比较、复现性差，且缺乏统一标准。

本文首次系统评估了7类关键设计选择对机器学习模型预测股票收益的影响，构建了1,056个不同组合的模型，全面衡量其样本外表现，并引入“非标准误差”（nonstandard error）概念，量化设计选择带来的不确定性。

# 二、研究设计与方法

# 1\. 数据

样本：1957年1月至2021年12月，美国NYSE、AMEX、NASDAQ上市普通股（剔除市值最小的20%微型股）

特征：使用Chen & Zimmermann (2022) 提供的开源因子库，共207个特征。

预测目标：未来一个月的股票收益

组合构建：每月按模型预测值排序，构建十分位多空组合（long top decile, short bottom decile），采用NYSE市值加权

# 2\. 设计选择（7类 × 多种选项 = 1,056种组合）

类别

选项

算法（11种）

OLS、ENET、RF、GB、NN1~NN5、ENS NN、ENS ML

目标变量（3种）

超额收益（RET-RF）、市场调整收益（RET-MKT）、CAPM alpha（RET-CAPM）

目标变换（2种）

连续（Raw）、二分类（Dummy）

是否剔除“未发表因子”（Post-Publication）

是 / 否

是否特征预筛选（Feature Selection）

是（LASSO）/ 否（全特征）

训练窗口（Training Window）

扩展窗口（Expanding）/ 滚动窗口（Rolling）

训练样本（Training Sample）

全样本（含微盘股）/ 剔除微盘股（ExMicro）

# 三、核心发现

# 1\. 模型表现差异极大

月频多空组合收益：0.13% ~ 1.98%

年化夏普率：0.08 ~ 1.82

最佳模型：ENS ML + RET-MKT + Raw + NoPost + NoSelect + Expanding + ExMicro

最差模型：RF + RET-CAPM + Raw + YesPost + YesSelect + Rolling + All

# 2\. 非标准误差（NSE）远大于标准误差（SE）

NSE/SE = 1.59（整体）

即使固定某一设计选择，NSE仍普遍大于SE（1.04~1.85）

这意味着模型设计选择带来的不确定性，远大于统计抽样误差

![](assets/001.png)

# 3\. 最关键的设计选择（按影响力排序）

设计选择

影响幅度（月收益）

显著性

是否剔除未发表因子（Post-Publication）

+0.52%

t=6.19\*\*\*

训练窗口（Expanding vs Rolling）

+0.20%

t=1.90\*

目标变换（Raw vs Dummy）

+0.16%

t=1.38

目标变量（RET-MKT vs RET-RF）

+0.12%

t=0.90

算法（ENS ML vs 其他）

+0.08%

t=2.17\*\*

特征筛选（LASSO vs 全特征）

+0.02%

t=1.06

训练样本（All vs ExMicro）

+0.02%

t=0.42

> ✅ **结论：Post-Publication、Training Window、Target Transformation、Target Variable、Algorithm 是最关键的设计选择。**

# 四、非线性模型何时优于线性模型？

![](assets/002.png)

进一步分析ENS ML（非线性集成）vs OLS（线性）的相对表现，发现非线性模型仅在以下条件下显著优于线性模型：

条件

平均超额收益（ENS ML - OLS）

t值

目标变量 = RET-MKT

+0.22%/月

2.06\*\*

目标变换 = Raw（连续）

+0.11%/月

1.82\*

训练窗口 = Expanding

+0.15%/月

4.12\*\*\*

> ✅ **结论：非线性模型并非总是优于线性模型，只有在“市场调整收益+连续目标+扩展窗口”下才显著更强。**

# 五、实用建议（作者给出的“设计选择指南”）

设计选择

建议

算法

使用集成模型（ENS ML），神经网络表现稳健

目标变量

若追求高收益 → 用RET-MKT；若追求风险调整收益 → 用RET-CAPM

目标变换

用连续变量（Raw），避免二分类

是否剔除未发表因子

若用于实盘，建议剔除（YesPost）；若用于研究，可保留（NoPost）但需意识到收益可能被高估

特征筛选

无需预筛选，ML模型可自动处理冗余特征

训练窗口

扩展窗口优于滚动窗口，尤其对非线性模型

训练样本

无需引入微盘股，反而可能引入噪声

![](assets/003.png)

(论文和代码见星球）