# Two Sigma使用深度学习做量化交易分享。​

杰少 量化前沿速递 2024-05-30 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487877&idx=1&sn=55679183e20f92c378c851a137320959&chksm=c3e07fbdbc8e847ec311c06fc57c9b07d088a2cd407fa5b97c6076cac3c4e8efc0d54a5da433#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487877&idx=1&sn=55679183e20f92c378c851a137320959&chksm=c3e07fbdbc8e847ec311c06fc57c9b07d088a2cd407fa5b97c6076cac3c4e8efc0d54a5da433#rd)

  

**Two Sigma深度学习做量化分享**

前言

![](assets/001.png)

本文我们介绍在2021年Two Simga的David Kriegman在一次网络研讨会中关于如何将深度学习应用于量化投资的分享。

在Two Sigma，用深度学习做量化投资会被分解为

-   特征提取；
    
-   预测单个instruments的收益；
    
-   投资组合分配以决定交易数量以及交易执行等步骤。
    

这个过程中的许多步骤很容易被表示为机器学习问题，可以使用深度学习序列建模的方法来解决。

整体框架

![](assets/001.png)

![](assets/002.png)

框架可以分为两个部分

1.  TwoSigma量化投资的工作流程，以及各部分与深度学习的关系；
    
2.  序列预测中常用的深度学习模型。 
    

01

  

TwoSimga量化投资工作流

  

传统投资框架可以分为：

1.  Feature extraction
    
2.  Alpha Modeling
    
3.  Portfolio Optimization
    
4.  Execution
    

![](assets/003.png)

特征的原始输入可以来自一系列不同的来源：

1.  技术特征；
    
2.  基本面数据；
    
3.  情绪语义；
    
4.  另类数据。
    

从大量数据中，构建Alpha型，通过顺序深度学习预测每个资产类别的未来回报。

![](assets/004.png)

在对每项资产进行收益预测后，下一步是构建投资组合。研究人员需要确定投资组合中每项资产的配置。虽然这不是一个序列预测问题，但在投资组合优化中可以实现许多机器学习算法，因为需要考虑很多约束，以及选择合适的目标函数。

![](assets/005.png)

最后，在执行层面，预测未来价格以控制成本也至关重要。与特征提取和alpha建模更关注相对长期回报不同，策略执行倾向于关注短期价格动态，并处理适当数量的买卖。

02

  

使用到的机器学习模型

目前TwoSimga在尝试的深度学习模型：

![](assets/006.png)

强化模型：

![](assets/007.png)

小结

![](assets/001.png)

投资pipeline的许多部分需要对序列进行推理，因此，可以训练深度神经网络以提供帮助；

1.  在传统的投资框架中寻找深度学习模型优势领域很重要；
    
2.  软件基础设施建设（如分布式系统）和大量数据处理等同样重要。
    

参考文献

![](assets/001.png)

1.  Two Sigma: Deep Learning for Sequences in Quant Finance