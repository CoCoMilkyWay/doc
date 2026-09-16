# KANOP：基于Kolmogorov-Arnold网络的数据高效型期权定价模型

QuantML 2024-10-02 22:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247486902&idx=1&sn=e82dc1a2d920766b8111076b2befb965&chksm=cf88165fe9408c5a1d4803f6f12a219dea623776ec28578a21ab79d084d854e7f1bddfafabe0#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486902&idx=1&sn=e82dc1a2d920766b8111076b2befb965&chksm=cf88165fe9408c5a1d4803f6f12a219dea623776ec28578a21ab79d084d854e7f1bddfafabe0#rd)

这篇论文介绍了一种基于Kolmogorov-Arnold Networks（KANs）的新型期权定价模型，称为KANOP。KANOP模型旨在对美式期权进行定价，它建立在传统的最小二乘蒙特卡洛（LSMC）算法之上。KANs基于Kolmogorov-Arnold表示定理，与传统的多层感知器（MLP）相比，它们是一种数据高效型的选择，可以在较少的隐藏层条件下实现更高的性能。  
  
论文的主要贡献包括：  
  
KANOP模型：提出了一种基于KAN的美式期权定价方法，该方法提供了一种可学习的替代方案，用于在LSMC模型中使用的传统的基函数集，允许模型适应定价任务并有效估计预期的继续价值。  
  
性能对比：通过标准美式期权和亚式美式期权的例子，展示了KANOP在单变量情况和涉及多个输入变量的更复杂场景中，都能产生更可靠的期权价值估计。  
  
Delta估计：KANOP模型估算的Delta（期权价格对标的资产价格变动的敏感度）比传统基函数方法更准确，这对有效的期权对冲至关重要。  
  
图形验证：通过图形说明进一步验证了KANOP准确模拟美式期权预期继续价值的能力。  
  
研究问题：论文探讨了KANOP在有限数量的模拟路径下，与传统基于基函数的LSMC算法相比，在提供准确的期权价值和Delta估计方面能达到什么程度。  
  
论文还讨论了相关工作，包括LSMC方法的普及、机器学习技术在期权定价中的应用、以及解决偏微分方程（PDE）的方法。此外，论文详细介绍了KANOP模型的方法论，包括美式期权的执行策略、KAN模型的数学表示、以及基于KAN的期权定价模型的提出。

![图1](assets/001.png)

图1

![图2](assets/002.png)

图2

![图3](assets/003.png)

图3

![图4](assets/004.png)

图4

![图5](assets/005.png)

图5

![图6](assets/006.jpg)

图6