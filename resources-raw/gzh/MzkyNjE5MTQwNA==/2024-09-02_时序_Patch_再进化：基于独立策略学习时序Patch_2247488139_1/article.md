# 时序 Patch 再进化：基于独立策略学习时序Patch特征表示

TSer 量化前沿速递 2024-09-02 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488139&idx=1&sn=223e9bd12d826177debf2038412ac751&chksm=c3efbbd5665980e421c0e43970e4645c6a559fbadb2065d383b9f004a7291ac07a8f8c9de67c#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488139&idx=1&sn=223e9bd12d826177debf2038412ac751&chksm=c3efbbd5665980e421c0e43970e4645c6a559fbadb2065d383b9f004a7291ac07a8f8c9de67c#rd)

  

  

之前，我们解读过时间序列预测模型中的经典文章[PatchTST](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247494171&idx=1&sn=1af56f2b88cf6b95f3fa610c7b8d6ee2&chksm=cecd1feef9ba96f887c0ac425e5b1a37a539544c328abb58eb39f44d2e3b58ca6e0ac4f90683&scene=21#wechat_redirect)。事实上，Patch方法目前在时间序列领域几乎等同于attention。

  

本文介绍的论文也比较有意思，是继PatchTST之后的新工作，进一步简化了时序预测模型，同时也对比了Patch independent和Patch dependent两种方法。

  

![](assets/001.png)

  

论文地址：https://arxiv.org/abs/2312.16427

论文源码：https://github.com/seunghan96/pits

  

![](assets/002.gif)

  

**Patch依赖和独立**

  

对于大部分的模型在做预测时，为了提高特征表征能力，都增加了自监督表示学习策略，PatchTST也是如此。在PatchTST中，作者也是故意随机移除输入序列的一部分内容，并训练模型恢复缺失的内容。  

  

本文研究者认为，Patch之间的关系，在时间序列领域，对于预测被mask的Patch是冗余的，换言之，只需要用Patch自己本身的信息就能实现预测，文中称之为Patch independent建模。

  

研究者通过一个简单的实验，对比了Patch independent（下文称PI）和patch dependent（下文称PD）的方法，通过下图可以看到，基于PD任务预训练的Transformer在分布偏移下无法预测测试数据，但基于PI任务预训练的Transformer却能稳健应对。其次，研究者还采用了简单的PI架构（例如MLP）与传统的PD架构（例如Transformer）相比，PI具有更高的效率和性能。

  

![](assets/003.png)

  

**建模方法**

  

本文的模型结构简单清晰，如下图所示，完全由MLP组成，核心就是编码然后重构。

  

![](assets/004.png)

  

重构有两种策略：一种所有Patch拼接后，过FC和MLP，然后重构；第二种是每个Patch过FC和MLP，然后逐个重构，作者采用了第二种，即channel /Patch independent建模重构。

  

对于多元时间序列，使用channel independent的建模方法，每个变量单独过MLP，多个变量共享MLP参数，同样的，每个Patch单独过MLP，多个Patch共享MLP参数。

  

为了进一步提高所学习表示的性能，研究者提出了对比学习，以分层方式捕获相邻时间序列信息。

  

对比学习需要两个视图来生成正对，研究者通过遮蔽策略实现这一点。在实验中，随机mask掉50%的Patch，将该序列及与其mask完全相反的序列作为两个视图，使用对比学习的目标进行优化。请注意，遮蔽的目的是为对比学习生成两个视图；它不影响所提出的PI任务，并且在使用所提出的PI架构时不需要额外的正向传递，因此额外的计算成本可以忽略不计。

  

![](assets/005.png)

  

上图说明了对比学习情况，研究者通过在补丁表示上沿时间轴进行最大池化进行层次对比学习。然后，在每个级别上计算和聚合损失。接着，模型通过与另一个视图和其他视图的相似性进行对比，学习找到一个视图中缺失的补丁信息，从而使模型能够分层地捕获相邻时间序列信息，实现从细粒度到粗粒度的对比学习。

  

  

**实验效果**

  

下表显示了多元时间序列预测任务的综合结果，表明研究者提出的PITS在两种设置中均与PatchTST相当，而PITS的效率远高于PatchTST。更多实验数据细节，可自行查阅论文。

  

![](assets/006.png)

  

  

  

**总结**

  

该论文重新审视了时间序列分析中的遮蔽建模，重点关注两个关键方面：预训练任务和模型架构。与之前主要强调时间序列补丁之间依赖性的工作不同，研究者主张在两个方面采取补丁独立的方法：1）通过引入补丁重建任务；（2）采用patch-wise MLP。研究者的结果表明，与PD方法相比，提出的PI方法对分布偏移和补丁大小更具鲁棒性，导致在预测和分类任务中性能更优且效率更高。研究者希望这项工作能够揭示简单预训练任务和模型架构在各种领域中自监督学习的有效性，并为未来的时间序列分析工作提供强有力的基准。