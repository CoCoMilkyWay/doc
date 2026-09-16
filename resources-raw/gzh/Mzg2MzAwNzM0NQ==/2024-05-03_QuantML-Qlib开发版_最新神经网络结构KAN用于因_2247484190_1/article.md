# QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘

QuantML QuantML 2024-05-03 17:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484190&idx=1&sn=836ef4cef6c9183a51de163656cd13c5&chksm=cf5d2573bdaef450ff76b1085bd7cd20f3b1ffdfcace7507899e735f467d27daac104e45f289#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484190&idx=1&sn=836ef4cef6c9183a51de163656cd13c5&chksm=cf5d2573bdaef450ff76b1085bd7cd20f3b1ffdfcace7507899e735f467d27daac104e45f289#rd)

![](assets/001.png)

模型介绍

![](assets/001.png)

昨天的文章介绍了MIT最新的神经网络KAN：[取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)

相较MLP，KAN具有以下特点：

1.  可学习的激活函数：
    

-   KAN的特点是其激活函数是可学习的，并且放置在网络的边缘上，而不是传统MLP中的节点上。这意味着每个权重参数被一个单变量函数（如样条函数）所取代，而不是一个固定的数值。
    

3.  没有线性权重：
    

-   KAN不使用线性权重矩阵，这一点与传统MLP不同。在KAN中，权重被表示为单变量函数，这使得网络能够更灵活地学习复杂的函数映射。
    

5.  基于Kolmogorov-Arnold表示定理：
    

-   KAN的设计灵感来源于Kolmogorov-Arnold表示定理，该定理表明多变量连续函数可以表示为单变量连续函数的有限组合和加法运算。
    

7.  更高的准确性和可解释性：
    

-   KAN在数据拟合和偏微分方程求解方面展现出比MLP更高的准确性。此外，KAN的可解释性也更好，因为它们的结构和激活函数可以直观地可视化。
    

9.  更快的神经缩放法则：
    

-   KAN在理论上拥有比MLP更快的神经缩放法则，这意味着随着模型大小的增加，KAN的性能提升速度更快。
    

11.  稀疏性和剪枝：
     

-   KAN可以通过正则化和剪枝技术来减少模型的复杂性，从而提高其可解释性。这包括使用稀疏化技术来减少激活函数的数量，以及剪除不重要的节点或连接。
    

13.  符号化：
     

-   KAN提供了一种将训练好的网络转换为符号公式的方法，这在科学发现和数学问题求解中特别有用。
    

15.  局部可塑性：
     

-   由于样条基函数的局部性，KAN能够避免灾难性遗忘问题，即在持续学习或学习新任务时不会遗忘旧任务。
    

17.  结构灵活性：
     

-   KAN可以通过改变网络的形状（即层数和宽度）来适应不同的问题，同时保持其核心特性。
    

鉴于其参数量少且可解释性较强的特点，非常适合用于因子挖掘，因此我们将其加入QuantML-Qlib框架当中，并提供运行因子挖掘的样例代码

代码结构如图：

![](assets/002.png)

alphazoo为因子挖掘的目录，后续会加入其他因子挖掘算法，例如遗传规划，强化学习等。

kan\_workflow.ipynb为kan的运行案例，首先需要load数据，  

```
hd = init_instance_by_config(dh_handler['kwargs']['handler'])
```

‍

  

数据结构，因子预测目标为未来一周收益率。：

![](assets/003.png)

  

定义KAN模型：  

```
model = KAN(width=[6,20,1], grid=5, k=3, seed=0, device=device)
```

‍

  

其中\[6,20,1\]代表模型为3层结构，输入层为6维度因子，中间层20维，输出1维结果。grid和k是b-spline参数。目前仅支持cpu, gpu运行会报错，目测是代码里面有些变量没有load进device。

训练模型：  

```
model.train(kan_dataset, opt="LBFGS", steps=5, lamb=0.01, lamb_entropy=10., device=device);
```

  

模型可视化：

![](assets/004.jpg)

相比于MLP动辄几十上百层的结构，KAN的模型结构清晰明了，最终的因子也可以非常容易的构建表达式结构。  

用沪深300一年的数据训练，样本外因子的IC为0.023。考虑到样本较少，且模型结构简单，这个结果看起来非常有前景，后续会继续深入挖掘。

![](assets/005.png)

  

  

QuantML-Qlib项目代码见星球。

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

  

  

**点击蓝字**

![](assets/006.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/007.jpg)

![](assets/008.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**

  

  

  

![](assets/009.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/009.gif)