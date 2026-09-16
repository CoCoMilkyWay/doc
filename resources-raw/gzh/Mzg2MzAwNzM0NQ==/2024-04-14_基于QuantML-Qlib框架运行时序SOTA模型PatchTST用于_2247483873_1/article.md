# 基于QuantML-Qlib框架运行时序SOTA模型PatchTST用于金融市场预测

QuantML QuantML 2024-04-14 14:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=cf8b78e18c590815c2a0028b43a0ae9ced3b1e355b3fb43c8963ab3b9e697a8a5f7ee9ad8917#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=cf8b78e18c590815c2a0028b43a0ae9ced3b1e355b3fb43c8963ab3b9e697a8a5f7ee9ad8917#rd)

![](assets/001.png)

1\. 模型介绍

![](assets/001.png)

PatchTST是目前最流行的时序Transformer结构，采用了Patching+Channel Indepedence，在各类时序问题上取得了非常好的结果。

论文的主要贡献和发现如下：

**时间序列的分割设计（Patching）：**通过将时间序列分割成子序列级别的Patching，模型能够保留局部语义信息，同时显著减少了注意力图的计算和内存使用，因为输入标记的数量从原始序列长度减少到大约序列长度除以步长。这种设计还允许模型关注更长的历史记录，从而显著提高了长期预测的准确性。  

![](assets/002.png)

**通道独立性（Channel-independence）：**在多变量时间序列中，每个Transformer输入标记可以由单个通道或多个通道的数据表示。通道独立性意味着每个输入标记只包含来自单个通道的信息。这种设计在卷积神经网络（CNN）和线性模型中已被证明有效，但在基于Transformer的模型中尚未应用。  

![](assets/003.png)

  

![](assets/004.png)

**模型性能：**提出的通道独立Patching时间序列Transformer（PatchTST）在长期预测准确性上显著优于现有的基于Transformer的模型。此外，该模型在自监督预训练任务上也表现出色，通过微调性能超越了大型数据集上的监督训练。  

![](assets/005.png)

**自监督表示学习：**论文还探讨了PatchTST在自监督表示学习方面的应用，通过在没有标签的数据上预训练模型来提取高级抽象表示，这些表示可以有效地转移到预测任务上。实验结果表明，自监督预训练的PatchTST在多个数据集上都取得了最先进的预测性能。

**迁移学习：**研究者们还测试了预训练模型在不同数据集之间的迁移能力，即在一个数据集上预训练模型，然后在另一个数据集上进行微调。结果表明，即使在不同数据集之间，预训练的PatchTST也能够保持优秀的预测性能。

**消融研究：**为了验证Patching设计和通道独立性的有效性，研究者们进行了消融研究，结果表明这两种设计对于提高预测性能都是重要的。

**长期时间序列预测：**论文在多个流行的数据集上评估了PatchTST的性能，包括Weather、Traffic、Electricity、ILI和ETT数据集。这些数据集具有不同的特点，如时间步长、特征数量和时间范围，为模型的评估提供了全面的基准。

**实验设置和结果：**论文详细描述了实验设置，包括数据集、基线模型、模型变体和评估指标。实验结果以表格形式呈现，展示了PatchTST在不同预测长度和不同数据集上的性能。

  

2\. 代码部分

  

我们在中QuantML-Qlib实现PatchTST模型。由于有部分c代码，需要编译后再使用，在QuantML-Qlib根目录下运行以下命令进行编译

```
python  setup.py build_ext --inplace
```

然后将我们的代码拷贝进examples/benchmarks

![](assets/006.png)

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

PatchTST模型部分代码在PatchTST.py中

```
class PatchTSTModel(nn.Module):
```

  

  

QuantML-Qlib项目代码见星球。

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

![](assets/007.png)

  

  

**点击蓝字**

![](assets/008.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/009.jpg)