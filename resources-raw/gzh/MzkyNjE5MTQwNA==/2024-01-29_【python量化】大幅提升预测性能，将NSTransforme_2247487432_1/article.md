# 【python量化】大幅提升预测性能，将NSTransformer用于股价预测

敲代码的quant 量化前沿速递 2024-01-29 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487432&idx=1&sn=21447dccd4473614dfda74fcd8eec231&chksm=c314f54451b9fad112f9c124bd9595a0e7ce8067db5367f1caea30c5fae835d35c14e11f8f76#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487432&idx=1&sn=21447dccd4473614dfda74fcd8eec231&chksm=c314f54451b9fad112f9c124bd9595a0e7ce8067db5367f1caea30c5fae835d35c14e11f8f76#rd)

  

写在前面

NSTransformer模型来自NIPS 2022的一篇paper《**Non-stationary Transformers: Exploring the Stationarity in Time Series Forecasting**》。NSTransformer的目的主要是为了解决其他方法出现**过平稳化处理**的问题。其通过提出序列平稳化以及去平稳化注意力机制可以使得模型面向提升预测性能的角度进行平稳化处理，相比于Transformer的变体，NSTransformer在预测性能方面实现了大幅度的提升。**下面的这篇文章主要带大家了解一下NSTransformer的基本原理，并使用作者开源的NSTransformer代码，并将其用于股票价格预测当中。**

1

NSTransformer模型

  

由于Transformer的全局范围的建模能力，使其在时间序列预测中显示出巨大的力量。然而，在联合分布随时间变化的非稳态真实世界数据上，它们的性能可能会退化得很可怕。**以前的研究主要采用平稳化技术来削弱原始序列的非平稳特性**，以提高预测能力。但是，被剥夺了内在非平稳性的平稳序列对于现实世界中的突发事件预测的指导意义不大。这个问题，在本文中被称为**过平稳化（over-stationarization）**，导致Transformer对不同序列产生无差别的时序关注，阻碍了深度模型的预测能力。为了解决序列的可预测性和模型能力之间的困境，作者提出了Non-stationary Transformer （NSTransformer）作为一个通用框架，其中有两个相互依赖的模块。**序列平稳化（Series Stationarization**）和**去平稳化注意力（De-stationary Attention）**。具体来说，序列平稳化模块统一了每个输入的统计特性，并将输出转换为恢复的统计特性，以提高可预测性。为了解决过平稳化问题，去平稳化注意力被设计出来，通过近似于从原始序列中学到的可区分的注意，将内在的非平稳信息恢复为时间依赖。作者提出的NSTransformer框架在很大程度上提升了主流Transformer模型的变体的预测性能，相比于Transformer，MSE降低了49.43%，相比于Informer，降低了47.34%，相比于Reformer，降低了46.89%。

  

**模型框架**  

NSTransformer遵循先前在时间序列预测中使用的Transformer架构，采用标准的编码器-解码器结构，其中编码器从过去的数据中提取信息，而解码器则通过对过去的历史信息进行过汇总来实施预测。典型的NSTransformer是通过对Transformer的输入和输出进行序列平稳化处理，并用提出的非平稳注意机制取代self-attention，这可以提高基础模型的非平稳序列的预测能力。总之，NSTransformer主要包括下面两个模块：序列平稳化模块以及去平稳注意力模块。  

![](assets/001.png)

NSTransformer的基本框架

**序列平稳化**

序列平稳化主要模块两个模块，一个是归一化（Normalization）模块，另一个是反归一化（De-Normalization）模块。首先，归一化模块通过一个滑动窗口的形式对每一维时间序列数据进行归一化处理，这样窗口化的方式可以将每一个相邻窗口内的数据都具有相同的均值跟方差，以**消除序列之间尺度上的差异性**，并增加输入数据在时序上的**分布稳定性**。归一化的过程是：

![](assets/002.png)

在模型预测结束之后，反归一化模块利用归一化时记录的均值跟方差信息，用来将模型的输出映射回原来的尺度，以恢复归一化时损失的信息。反归一化的过程是：

![](assets/003.png)

通过这两个阶段的变换，模型将接收到平稳的输入，这些输入遵循稳定的分布，更容易泛化。这样的设计还使模型对时间序列具有平移不变性和尺度不变性，从而有利于真实序列的预测。

![](assets/004.png)

序列平稳化过程（图片来自：https://zhuanlan.zhihu.com/p/587665491）

****去平稳化注意力****

去平稳化注意力机制去平稳化注意力机制的过程如下图所示：  

![](assets/005.png)

去平稳化注意力机制（图片来自：https://zhuanlan.zhihu.com/p/587665491）

如前面所提到的，过平稳化问题是由内在的非平稳信息的消失引起的，这将使模型无法捕捉到用于预测的事件性时间依赖。因此，作者试图近似从原始的非平稳序列中去学习注意力。下面是Transformer计算注意力的原始公式：

![](assets/006.png)

对于输入时间序列x，计算它的均值跟方差得到：

![](assets/007.png)

除此之外，为了简化分析这里假设了用于嵌入的前馈层在时间维度是线性的，基于线性假设可以推导出  ，  与对平稳化后时间序列计算得到的  跟  的关系是：

![](assets/008.png)

其中，  与  是  跟  在时间维度的均值。这样从原始时间序列中计算注意力机制的公式，可以被从平稳化后的时间序列中计算的  跟  替代为下面的公式，具体的推导可以参考原文的附录。

![](assets/009.png)

这样得到的注意力公式不仅包含了原始时间序列的信息，也包含了经过平稳化后的序列信息。之后为了恢复对非平稳序列的原始注意力，这里作者将消失的非平稳信息重新引入到非平稳序列的计算中。为了得到所需要的计算值，作者引入了去平稳因子   跟  ，它们都是通过两个多层感知器从非平稳时间序列中计算得到的。进而，去平稳化注意力的计算方式可以得到如下形式：

![](assets/010.png)

这样，它既能利用平稳序列的可预测性，又能保持原始序列固有的时间依赖性。

2

环境配置

  

本地环境：

```
Python 3.7
```

库版本：

```
numpy 1.18.1
```

NSTransformer源码Github链接：

https://github.com/thuml/Nonstationary\_Transformers

  

3

代码实现

  

NSTransformer的官方代码实现借鉴了Informer的代码，因此，与之前的推文[【python量化】将Informer用于股价预测](http://mp.weixin.qq.com/s?__biz=MzU3NjY2MDUyMw==&mid=2247489720&idx=1&sn=815a3cbea785426cac36a5253bca9874&chksm=fd112dfcca66a4eaf3ef3d8a678f9125254bfb504c4d4e746ea9f8abd3e4f6f83fefd958ac14&scene=21#wechat_redirect)类似，首先将NSTransformer的源码下载到本地，然后将我们的数据集放到某个路径下，这里仍然用到了**上证指数14到17年四年的开高低收成交量**数据。在将NSTransformer的代码用于我们的股票数据预测任务时，同样需要明确的是，我们的任务是基于高低收成交量来预测收盘价，**这是一个多变量输入，单变量输出的预测任务**。所以主要需要修改下面几个参数的设置。当需要进行不同预测任务时，如增加某些特征，预测多个目标变量等则可通过修改**features，target，enc\_in，dec\_in以及c\_out**参数进行实现。NSTransformer的主要参数与Informer类似，主要包括：

```
model: ns_transformer，可以选择其他模型包括Informer，Transformer以及Autoformer。
```

其他参数像模型层数，维度之类的可以根据自己的电脑配置进行修改。下面是进行上证指数预测实验的参数配置：

```
args.is_training = 1
```

按照设置的参数，然后对模型进行训练跟测试：

```
Exp = Exp_Main
```

下面是在CPU上的训练过程。经过训练，可以看出模型的训练集上的loss不断下降，由于加入了early stop机制，所以经过6个epoch模型就停止训练了。经过在测试集上的测试，NSTransformer实现了0.0027的mse跟0.0415的mae（归一化后的结果）。需要注意的是，模型经过训练跟测试之后，会在当前路径的./checkpoints中保存模型参数，在./results/{settings}/下生成pred.npy以及true.npy文件用来分别存放测试集上的预测结果跟ground truth。  

```
Use CPU
```

调用模型的predict()方法可以直接预测所有数据后面的未知数据，因为这里预测长度为5，所以直接调用就相当于预测后5天的收盘价走势了。预测的结果会保存在./results/{settings}/下面的real\_prediction.npy文件中。  

```
exp = Exp(args)
```

![](assets/011.png)

  

最后将完整的测试集上的预测结果进行可视化。  

```
plt.figure()
```

![](assets/012.png)

除此之外，NSTransformer的源码中也提供了Transformer、Informer以及Autoformer的实现。为了直观展示这几种模型之间的预测表现，我们采用相同的超参数对另外几种模型进行实验，并将其可视化的结果进行展示。需要注意是这里为了方便实验，每种模型的超参没有进行寻优而是统一采用了NSTransformer模型的实验配置。

![](assets/013.png)

Transformer

![](assets/014.png)

Informer  

![](assets/015.png)

Autoformer

  

从可视化结果中可以看出相比于其他Transformer模型，NSTransformer实现了最好的拟合效果。最后统计这几种模型的MSE跟MAE（未反归一化），从误差上也可以看出NSTransformer实现了最低的预测误差，其次是Autoformer，Informer以及Transformer。

```
NSTransformer:
```

4

总结

时间序列的非平稳性是现实时间序列数据中存在的重要特性，尤其是对金融时间序列来说。而现有大多数方法都会对数据做平稳化处理来提升预测性能，然而，平稳化处理的过程也会导致一部分信息的丢失。而NSTransformer通过设计的序列平稳化以及去平稳化注意力机制，使得它既能利用平稳序列的可预测性，又能保持原始序列固有的时间依赖性。文中通过将NSTransformer与其他模型包括Transformer，Informer以及Autoformer的实验对比，进一步证实了NSTransformer的预测性能。因此，在面对非平稳，高噪声的股票数据预测中，NSTransformer或许可以取得较好的预测表现。

**本文内容仅仅是技术探讨和学习，并不构成任何投资建议。**

参考文献：

Liu, Y., Wu, H., Wang, J., & Long, M. (2022). Non-stationary Transformers: Exploring the Stationarity in Time Series Forecasting. In _Advances in Neural Information Processing Systems_.

NeurIPS2022 | NSTransformers: 非平稳时间序列的通用预测框架 - 游凯超的文章 - 知乎 https://zhuanlan.zhihu.com/p/587665491