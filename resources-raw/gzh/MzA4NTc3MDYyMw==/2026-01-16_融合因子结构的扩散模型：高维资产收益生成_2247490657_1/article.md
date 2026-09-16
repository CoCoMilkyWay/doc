# 融合因子结构的扩散模型：高维资产收益生成的新框架（含代码）

InfinityQuant 映翡量化 2026-01-16 09:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490657&idx=1&sn=9617d9cc08fc3953fa2c13ab26fb722a&chksm=9eb51e0dc7b26e2526d2f90371c2d84a31b4411f1df0a322f636f15fa19b7e18ccc098074e71#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490657&idx=1&sn=9617d9cc08fc3953fa2c13ab26fb722a&chksm=9eb51e0dc7b26e2526d2f90371c2d84a31b4411f1df0a322f636f15fa19b7e18ccc098074e71#rd)

这篇论文《Diffusion Factor Models：Generating High-Dimensional Returns with Factor Structure》（2026/1/11）围绕高维金融资产收益的情景模拟问题，提出了一种新的生成式建模框架——**扩散因子模型（Diffusion Factor Model）**，来解决金融领域中普遍存在的“高维度、样本量小”难题。文章将因子模型与生成式AI相结合：使用一种**扩散模型**（diffusion model），它能学习资产回报的隐藏因子结构，然后生成无限量、逼真的样本数据。

在金融风险管理和投资组合优化中，能够生成逼真的金融场景至关重要。然而，金融数据通常具有高维性（资产数量d庞大，如数千只股票）和数据稀缺性（有效历史样本n有限）的特点。传统的非参数统计方法在这种环境下失效，而现有的生成对抗网络（GANs）等模型往往面临训练不稳定、缺乏理论保障的问题。  

方法论

提出了一种结合隐因子结构的扩散模型。作者假设资产收益率由少量潜在因子（k个，且k≪d）和特异性噪声构成。基于这一结构，文章做出了以下创新设计：

-   分数函数分解： 从理论上推导出，扩散模型的核心组件——分数函数（Score Function），可以分解为一个低维子空间上的非线性分量（对应因子）和一个高维空间上的线性分量（对应特异性噪声）。
    
-   网络架构设计： 依据上述分解，设计了一种特殊的神经网络架构（基于U-Net的编码器-解码器结构）。该网络只需重点学习低维的因子分布，而通过简单的线性结构处理高维噪声，从而极大地降低了模型的学习难度和参数量。
    

实证表现

基于2001年至2024年的美国股市数据，作者利用该模型生成的数据构建了均值-方差最优投资组合。

-   均值-方差组合（mean-variance portfolios）击败所有传统的收缩估计方法（shrinkage methods）
    
-   基于生成数据的**因子切线组合**（factor tangency portfolios）夏普比率达到3.5+
    
-   生成出的因子与市场因子（Market）、动量因子（Momentum）、反转因子（Reversal）存在相关性
    

当数据稀缺时，就生成更多数据。

![](assets/001.png)

https://arxiv.org/abs/2504.06566

https://github.com/xymmmm00/diffusion\_factor\_model

PDF和代码已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)