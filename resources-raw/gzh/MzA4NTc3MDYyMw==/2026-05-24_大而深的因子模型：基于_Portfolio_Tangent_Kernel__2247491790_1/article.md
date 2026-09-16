# 大而深的因子模型：基于 Portfolio Tangent Kernel 的特征-定价分离框架

InfinityQuant 映翡量化 2026-05-24 08:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491790&idx=1&sn=a17aeab25af3d12614b1bcf1a2704271&chksm=9edba474c82c4688bcc9131a995cc4968328df601a26d93b5ba245ff1c3e1489a0b8e14345df#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491790&idx=1&sn=a17aeab25af3d12614b1bcf1a2704271&chksm=9edba474c82c4688bcc9131a995cc4968328df601a26d93b5ba245ff1c3e1489a0b8e14345df#rd)

来自Yale、AQR、NBER的论文《Large and Deep Factor Models》（2026年5月4日）提出了一种新的框架，用于理解深度神经网络（DNN）在资产定价中的应用，特别是构建随机折现因子（SDF）。核心思想是将DNN训练过程分解为两个独立但相互关联的任务：特征学习（发现经济相关信息）和定价规则学习（将这些特征聚合成SDF）。作者认为，在传统的DNN训练中，这两个任务通过梯度下降紧密耦合，导致经济解释性受损且可能导致统计效率低下。

核心方法论：Portfolio Tangent Kernel (PTK)

关键贡献是引入了Portfolio Tangent Kernel (PTK)，它能够清晰地将特征学习与定价规则学习分离。

![](assets/001.png)

1\. SDF的参数化与优化问题：

    SDF被定义为 ![](assets/002.png)，其中![](assets/003.png) 是条件有效投资组合。![](assets/003.png)可以被建模为特征![](assets/004.png)的函数![](assets/005.png)。SDF估计的优化目标是最小化平方误差![](assets/006.png)，其中![](assets/007.png)是一个参数化的函数族。本文在此基础上引入了岭（ridge）惩罚项![](assets/008.png)，形成优化问题：

    ![](assets/009.png)

    这个目标函数捕捉了高维SDF估计中的偏差-方差权衡。

2\. 随机特征与Large Factor Models (LFM) SDF：

    作为基准，文章首先考察了基于随机特征的SDF。这种模型中，函数![](assets/010.png)被定义为![](assets/011.png)个非线性随机特征的线性组合：

![](assets/012.png)

    其中![](assets/013.png)是随机抽取的固定权重，![](assets/014.png)是非线性激活函数。这等效于一个隐藏层权重固定的浅层神经网络。在此设定下，SDF可以表示为因子投资组合![](assets/015.png)，其中因子![](assets/016.png)。

优化问题有解析解![](assets/017.png)。

    当![](assets/018.png)时，这种随机特征SDF收敛于一个由核函数![](assets/019.png)决定的形式。本文定义了Portfolio Kernel![](assets/020.png)，它衡量市场状态（收益和特征）之间的相似性。LFM-SDF的渐进形式为：    

![](assets/021.png)

    其中![](assets/022.png)，表示基于Portfolio Kernel的优化权重。

3\. DNN训练与PTK的诞生：

    对于完全训练的DNN，参数![](assets/023.png)通过梯度下降（或梯度流）更新：

![](assets/024.png)

    这个梯度流的动态演化揭示了PTK。投资组合收益的变化率可以表示为：

![](assets/025.png)

    这表明，学习通过梯度特征组合![](assets/026.png)驱动。基于此，本文定义了Portfolio Tangent Kernel (PTK)：

    ![](assets/027.png)

    PTK通过衡量收益对参数扰动的敏感性来量化市场状态之间的相似性，是将Neural Tangent Kernel (NTK) 概念提升到资产定价语境的关键。它捕捉了DNN学习到的“梯度特征”（即因子![](assets/028.png)之间的关系）。

4\.  PTK-SDF的分解与稳定特性：

    文章证明，在梯度流下，DNN的投资组合收益变化与PTK相关：

![](assets/029.png)

    当DNN训练足够长时间（即![](assets/030.png)）且PTK稳定（即![](assets/031.png)收敛到![](assets/032.png)时，DNN-SDF可以分解为两部分：

![](assets/033.png)

    其中第一项是学习到的初始模型，第二项是PTK-SDF，它最优地聚合了通过PTK捕获的已学习特征。![](assets/034.png)表示最优时间权重，其形式与岭回归（ridge regression）中使用的频谱滤波器（spectral filter）相似，表明梯度下降内生地诱导了有效的岭惩罚。这意味着一旦特征学习稳定，后续学习只通过固定梯度特征的聚合进行。由于这种聚合在特征给定下是最优的，原始DNN模型的残余部分可以被丢弃。

统计性质与实证发现：

-   统计极限：PTK表征使得可以使用随机矩阵理论（RMT）工具分析高维定价模型的统计极限。模型的表现受两个因素影响：对齐（alignment），即风险溢价与因子风险的统计强方向的吻合程度；以及频谱复杂度（spectral complexity），即因子风险在主成分上的分散程度。高频谱复杂度意味着经济相关变动分散在许多弱方向上，在有限样本中会放大估计误差。
    
-   PTK-SDF的优势：PTK-SDF通过缓解训练过程中特征发现与定价规则联合学习产生的噪声，系统性地优于原始DNN-SDF，实现了更高的夏普比率（Sharpe ratio）和经济上显著的阿尔法（alpha）。它提出了一种模块化估算方法：DNN仅用于特征发现，然后将这些特征映射到大量因子，最后通过显式、正则化的投资组合规则组合这些因子。
    
-   频谱复杂度的演变：经验发现，自21世纪初以来，PTK的频谱复杂度急剧上升了约六倍，这与因子模型表现普遍下降的时期相吻合。这意味着SDF的统计复杂性显著增加。然而，风险溢价与因子风险之间的对齐程度也有所提高，部分抵消了复杂度上升的不利影响。
    
-   隐式正则化：学习到的特征比随机特征展现出显著更高的频谱复杂度（约一个数量级），这意味着即使没有显式岭惩罚，PTK-SDF也受到强大的隐式正则化。最佳定价规则在很大程度上是“无岭”的，因为学习到的特征本身就通过其频谱特性对弱风险方向进行了收缩。
    
-   经济一致性：PTK-SDF表现出与长期和未来消费风险更强的对齐性，这表明PTK方法不仅提升了统计性能，还增强了模型的经济可解释性。
    

总结：

本文提供了一个统一的框架，解释了深度学习在资产定价中的作用。DNN是强大的经济信息特征发现工具，但有效的定价需要将特征发现与模型估计分离。PTK通过将原始DNN替换为显式的大因子定价表示来实现这一分离。这种表示允许使用高维统计和随机矩阵理论的现代资产定价工具来分析学习特征的经济内容以及有限样本施加的统计限制。

![](assets/035.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6225778

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/036.png)