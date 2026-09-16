# 市场微观结构的奠基石——Roll(1984)

混饭吃不丢人 QuantSeek 2023-06-05 08:11 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247483867&idx=1&sn=2fae750c5308ab6b5a06b0afeb934e53&chksm=cee40c423a347a7e5cb24ac306d0b71d1433ee6fbb368fced9efbfd70ea0a6e7bcc263e7b85d#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483867&idx=1&sn=2fae750c5308ab6b5a06b0afeb934e53&chksm=cee40c423a347a7e5cb24ac306d0b71d1433ee6fbb368fced9efbfd70ea0a6e7bcc263e7b85d#rd)

今天锤哥给各位分享一篇微观结构的经典中的经典文献，简称Roll(1984), ：  

  

_**《A Simple Implicit Measure of the Effective Bid-Ask Spread in an Efficient Market》**_

![](assets/001.png)

  

其引用量高达3764次，可谓必看文章。

  

  

  

  

  

  

这篇文章想要解决的是，Order Book的理论价差（spread）的合理定价问题，即下图所示卖盘1和买盘1的价格差，推导很简单但很有趣。

  

![](assets/002.png)

(数据样例来源：同花顺）

  

**假设：**  

1、有效市场。

2、价格的变化率是平稳的分布（无新信息输入的情况下），至少在短时间内是如此。

3、做市商市场，市场有market maker（做市商，双边报价提供流动性）和market taker（下市价单的交易者），所有的交易的对手都是做市商。

  

当没有新的信息进入市场的时候，股票的内在价值不变：即Mid-price，中间价。但是交易却并不是发生在中间价，而是随机到达，在买1和卖1上进行。

  

![](assets/003.png)

  

注意，只要没有新的信息进入市场，那么交易必然发生在卖1或者买1, 那么我们很容易得到价格变动的概率转换矩阵：

  

![](assets/004.png)

  

左边的图是说，当t-1交易价格是bid（买1）时，由于交易的到达是随机的，Delta\_P\_t只有2种可能，要么是0（即t时刻价格仍然发生在bid，概率为1/2)，要么是+s（即t时刻价格发生在ask，概率也为1/2), 而一旦Delta\_P\_t = 0，那么Delta\_P\_t+1只能是0和+S两种可能，于是能得到上面左右2图转换矩阵。

  

    完整的价格变动概率转移矩阵则为：

  

![](assets/005.png)

那么根据简单的概率论知识，协方差的定义，我们计算Delta\_P\_t和Delta\_P\_t+1的协方差，可以得到：

  

![](assets/006.png)

  

这就是整篇文章的**核心**，理论的spread，可以通过价格变动的协方差得到！

  

  

  

  

让我们跳出数学定义，去理解这个公式：

  

![](assets/006.png)

  

首先价差不可能为负的，这也就意味着，在无信息流入的市场，价格变动的自协方差是负的，也即表现出反转的现象。

  

那为什么需要spread呢，从理论上看，这是对做市商提供流动性服务的风险的补偿，

  

当自相关性为负怎么办？这时候spread无解，在这种情况下，Roll模型是失效的，这可能是因为短期内有很强的价格趋势（新信息的引入）。

  

  

感兴趣的朋友可以看论文原文，公众号(拿着锤子找钉子)发信息 'roll' 即可获取。

![](assets/007.png)