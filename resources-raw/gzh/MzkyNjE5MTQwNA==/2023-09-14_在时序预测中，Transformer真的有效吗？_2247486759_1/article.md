# 在时序预测中，Transformer真的有效吗？

Ai 量化前沿速递 2023-09-14 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486759&idx=1&sn=9f04156657fd2276a7fc47a08306ba6e&chksm=c31cb0f3b6b249b06b436a743b2e2339c6362d572841fa72cd2ee326674b49dd70fa0c348923#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486759&idx=1&sn=9f04156657fd2276a7fc47a08306ba6e&chksm=c31cb0f3b6b249b06b436a743b2e2339c6362d572841fa72cd2ee326674b49dd70fa0c348923#rd)

  

之前我打比赛时，需要预测股市收益率，当时直接上Transformer后，出现严重过拟合问题。看完本篇文章，发现其给出了很好的解释 (股价数据几乎没有点语义关联信息) 和实验论证，确实如论文题目所示，时序预测中，Transformers并未万能油，关键点在于：**Transformer的自注意力机制具有排列不变性(permutation-invariant)**。推荐阅读指数: **5星**。不足之处，还望批评指正。

  

  

**论文：**AAAI2023 | Are transformers effective for time series forecasting \[1\]

**作者：**Zeng, Ailing, Muxi Chen, Lei Zhang, and Qiang Xu

**机构：**港中大、IDEA

**代码：**https://github.com/cure-lab/LTSF-Linear

**引用量：**141

  

![](assets/001.png)

  

**Q: 什么是排列不变性？**

  

A: 在语义丰富的NLP任务中，如果我们把一个句子中部分词位置置换，再喂入Transformer学习，对point-wise自关注机制学习其语义信息并不会有太大的影响。这便是排列不变性。

  

**Q: 排列不变性怎么影响Transformer在时序任务上的表现呢？**

  

A: 排列不变性让模型只关注语义信息，而忽略时序顺序信息。但在时序数值数据中，order信息是非常重要的，并且很多时序数据（如股价、电价）是缺乏语义信息的，因此我们希望模型更关注连续点集，而不是离散点集，但实际上用point-wise的自关注机制，应具有排列不变性，会导致过拟合时序噪声，而非真正时序信息，导致泛化性能差。

  

**Q: 怎么证明Transformer没学到时序信息？**

  

作者设计了相关实验，首先，最直接就是序列打散，看模型前后的表现。然后，看拉长回看窗口，看回看窗口越长，模型会不会学到更多信息，然后表现会不会越好。最后，提出用线性层网络建模，对比Transfomer表现。

  

序列打散实验：

  

![](assets/002.png)

  

Ori正常顺序，Shuf为随机打乱，Half-Ex为前后置换。Average Drop是Shuf/Half-Ex相对Ori MSE表现的下降幅度。结果表明，在Exchange Rate上，使用任何打乱策略，都基本没有影响到Transformer的模型表现。(说明学了啥东西？时序信息都没怎么学到…)

  

回看窗口实验：

  

![](assets/003.png)

  

横坐标是回看窗口大小，纵坐标是Electricity数据上的MSE。结果表明，很多Transformer类模型，回看窗口越大，效果还越差。(给的越多，拟合噪声越多…)

  

模型对比实验:

  

![](assets/004.png)

  

作者提出了3种线性模型，去对比带自注意力机制的Transformer模型：

  

**\- Linear:** 一层线性层；

**\- DLinear:** 先时序分解，分别用两个线性层分别拟合趋势项和季节项，最后合并。在有明显趋势的数据上，表现不错；

**\- NLinear:** 为了解决数据中的分布漂移，先对数据减去序列中最后一个值，做窗口内标准化，然后经过线性层后再加回前面减掉的值。

  

其中，以上各模型可以选择所有变量都共享权重或独立权重。

  

定性看：Dlinear趋势上预测的不错。

  

![](assets/005.png)

  

定量看: 全面秒杀Transformer。

  

![](assets/006.png)

  

另外，把Informer做减法，减到最后反而最好。

  

![](assets/007.png)

  

**Q: Transformer类模型在embedding不是加上position embedding和timestamp embedding了吗？这不是都有顺序和时间信息吗，为什么模型还是不行？**

  

```
class DataEmbedding(nn.Module):
```

  

A: 并不是说这些embedding没用。而是，论文说虽然embedding保留了顺序信息，但在它们之上用了自注意力机制就不可避免地丢失时序信息。

  

另外，作者也做了embedding的消融实验：

  

![](assets/008.png)

  

能看到，由于Informer是用point-wise self attention，即每个token值对应一个时间戳信息，所以w/oTemp对它影响很大。而Autoformer和FEDformer用的是series-wise self attention，即一条时间戳序列去表征时序信息，因此有时w/oPos反而更好。然后w/oTemp对Autoformer影响很好，因为丢弃全局时序信息。而FedFormer因为用了频域增强模块带来时序归纳偏差，所以w/oTemp/Pos影响不会太大。

  

总结下，就是时序慎用point-wise self-attention，可以用series-wise self-attention。而且timestamp embedding一般来说比position embedding更好，因为带来了更多的时序信息。position信息对series-wise self-attention帮助不大（因为series-wise本身就携带位置信息，比如1阶滞后序列一般跟原序列自相关性最高）。

  

论文还分享了些其他实验，比如：

  

用数据集的一部分，反而能取得比用全数据集更好。(感觉以后看论文是否真SOTA，还得检查下数据集使用情况…)

  

![](assets/009.png)

  

Less is More：

  

![](assets/010.png)

  

本篇论文代码是基于Autoformer代码框架上写的，挺简单的，这里就不解析代码了，模型请移步源码GitHub：

  

![](assets/011.png)

  

总结全文，Transformer在时序中最大的弊端就是point wise的self-attention带来的排列不变性，因为时序数值数据本身不具有丰富的语义信息。如果要进一步在Transformer上做研究，除了在embedding上保留时序信息，还要考虑改进self-attention，比如Autoformer用series-wise self-attention在一定程度上能避免模型过拟合单点性的突变噪声，毕竟序列打乱后，series对比下的自相关系数就会低，打破了排列不变性，更关注顺序信息。

  

**参考资料**

\[1\] Zeng, A., Chen, M., Zhang, L., & Xu, Q. (2023, June). Are transformers effective for time series forecasting?. In Proceedings of the AAAI conference on artificial intelligence (Vol. 37, No. 9, pp. 11121-11128)