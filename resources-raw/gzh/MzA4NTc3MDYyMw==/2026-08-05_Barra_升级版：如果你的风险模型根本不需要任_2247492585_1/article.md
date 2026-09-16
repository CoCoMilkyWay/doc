# Barra 升级版：如果你的风险模型根本不需要任何历史价格数据，会怎样？

InfinityQuant 映翡量化 2026-08-05 10:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247492585&idx=1&sn=5c19a892faffd2faf51d8a85c32f87f5&chksm=9e7f971d48fec3a14abfc9cd950ff9fb8855b411daefb62c41632e0c6402db44519422d56f34#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247492585&idx=1&sn=5c19a892faffd2faf51d8a85c32f87f5&chksm=9e7f971d48fec3a14abfc9cd950ff9fb8855b411daefb62c41632e0c6402db44519422d56f34#rd)

大多数协方差矩阵都完全依赖历史收益率构建，因此对于上市时间不长、历史数据有限的股票，建模往往很棘手。

Alexandre Alouadi 与 Charles-Albert Lehalle 的新论文《The Fundamental Structure of Risk: From Characteristics to Covariance》（2026年7月27日）提出：只用基本面信息来构建风险结构。输入变量包括规模、价值、杠杆率、行业等，这些指标几乎逐日不变，且与收益率高度独立（平均相关性绝对值仅为 0.009）。

可以把它理解为 Barra 特征因子思想的升级版，但特征到协方差的映射是通过非线性方式端到端学习的，直接瞄准的是未来风险。

这个模型叫作 CD-DFM（Characteristic-Driven Dynamic Factor Model，特征驱动动态因子模型）。

![](assets/001.jpg)  

### 技术骨架（极简版）

-   特征编码器：连续特征做仿射 token，分类特征做 embedding，再经浅层 MLP 得到潜在表示![](assets/002.png)
    
-   两个线性头：一个输出软隶属度 Zt（simplex 上），一个输出有符号载荷 βt
    
-   因子构造：第一个是等权市场因子，其余是现金中性的多空因子
    
-   协方差：低秩 + 对角形式![](assets/003.png)
    
-   端到端训练：Stein 前向协方差损失 + 重构损失
    

整个过程返回只参与因子实现和损失计算，不进入编码器。这就是“零历史”的根本原因。

![](assets/004.png)

![CD-DFM architecture](assets/005.png)

主要发现：

-   ✅ 在整个基准模型组合中，该模型的协方差校准效果最佳，优于基于收益率的收缩估计和主成分分析（PCA）方法。
    
-   ✅ 提取出的因子与真实的经济主题高度一致，行业板块能够“自然涌现”，无需人为设定行业分类。  
    
-   ✅ 对新上市股票可实现“零样本”（zero-shot）接入：无需历史、无需重新训练即可直接纳入风险模型。
    

一个 quieter 但深刻的启示是：我们通常从收益率中“恢复”出来的大量风险结构，其实早已隐藏在资产负债表里。💡

![](assets/006.png)

  

论文代码已开源：https://github.com/alexouadi/CD-DFM

https://arxiv.org/abs/2607.24410

PDF和代码已更新⬇️，更多策略、资讯⬇️

学术界的Alpha