# 择时荟萃(十五)：基于Transformer的择时策略(附源码)

partition 量化前沿速递 2023-05-28 20:23 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486246&idx=1&sn=ffd501f49a73e7236a71ab98cdd9a3bf&chksm=c35e0cb2ed64c011cd3ed741305cd67584f576098e00b6c0c156f268cf9e487585b756cf3e51#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486246&idx=1&sn=ffd501f49a73e7236a71ab98cdd9a3bf&chksm=c35e0cb2ed64c011cd3ed741305cd67584f576098e00b6c0c156f268cf9e487585b756cf3e51#rd)

择时系列第十五篇，分享一篇使用Transformer构建的择时策略。作者发现，基于注意力机制的深度学习策略，显著优于传统的时序动量策略和均值回归策略。此外作者提供了源码，可以直接测试，后台回复“**择时15**”获取报告及代码。

作者首先对Transfor的深度网络做了一些说明，并与LSTM做对比。Transformer与LSTM不同的地方在于，Transformer是基于注意力机制的深度学习架构，LSTM是顺序式的架构。这种注意力机制使得Transformer可以直接连接到所有先前的时间步骤，从而能够学习更长期的模式。此外，Transformer还引入了多个muliti-head atterntion(MHA)，可以捕捉同时发生在不同时间尺度上的并发模式或时间动态。 

![](assets/001.png)

下图是LSTM和Transformer的一个对比图。  

![](assets/002.png)

数据处理上，首先对收益率做波动率调整，以保证数据在时序上的一致性

![](assets/003.png)

损失函数定义为策略的夏普比率  

![](assets/004.png)

使用的特征包括收益率、波动率、MACD等价量指标。

样本为50个流动性非常好的期货(商品、股指、固定收益等等)。模型使用1990-1995年的数据做训练，1995-2000年作为测试集。

作者共测试了策略在三个区间下的表现：1995-2020、2015-2020、新冠期间期间。结果来看，都是Transformer策略下的策略最优

![](assets/005.png)

这里的Decoder-only TFT设定如下

![](assets/006.png)

净值曲线如下  

![](assets/007.png)

新冠期间  

![](assets/008.png)

论文的主要内容如上，对于代码，作者在文中给出了github链接，可以直接访问。

![](assets/009.jpg)

此外， 还有一些对于参数设定、交易成本方面的说明，可自行查阅论文。  

以上为论文的主要内容，觉得不错可以点赞/在看支持。