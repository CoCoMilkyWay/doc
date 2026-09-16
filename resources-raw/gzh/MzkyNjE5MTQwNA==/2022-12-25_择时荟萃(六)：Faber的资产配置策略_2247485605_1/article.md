# 择时荟萃(六)：Faber的资产配置策略

partition 量化前沿速递 2022-12-25 17:31

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247485605&idx=1&sn=9e2f097ede6d0ba1f3419df91ac3e983&chksm=c31c832857ccc634d60a5a9b10a5c3928a06d886902ca006649136c63de79c4136ab90ddcfd2#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247485605&idx=1&sn=9e2f097ede6d0ba1f3419df91ac3e983&chksm=c31c832857ccc634d60a5a9b10a5c3928a06d886902ca006649136c63de79c4136ab90ddcfd2#rd)

Faber(2006,2010)利用时序和截面动量，构建了一套全球的资产配置方案，全球知名。如下图，1x,2x分别表示取不同杠杆率下的净值，对比标普500的表现。  

获取报告请在后台回复“**择时6**”。

![](assets/001.png)

**1**

**Faber的时序策略**

 Faber的时序策略规则如下

![](assets/002.png)

策略规则非常简单，在美股上的效果也很好  

![](assets/003.png)

![](assets/004.png)

统计收益的分布情况，可以明显看出，择时策略的负向收益更少，呈现右偏特征。  

![](assets/005.png)

以上是在单品种上测试的结果，将这一策略用于多资产类别做资产配置，发现也是有效的，如下图，GTAA为分别对每个单资产使用这一策略，Buy and Hold为等权持有的表现。

![](assets/006.png)

对于SMA的周期长度测试发现，不同周期下均有效，9最好

![](assets/007.png)

  

对于策略有效性的逻辑，作者解释为**波动率的聚集效应(Volatility Clustering)**。

  

统计发现，在10个月SMA上下，各类资产的风险收益比都呈现出相似的特征，以上收益更高，以下波动率更高。  

  

![](assets/008.png)

**2**

**Faber的截面策略**

Faber的截面策略逻辑如下  

![](assets/009.png)

在多个资产上仅使用截面策略效果如下，均可战胜基准。

![](assets/010.png)

在之前时序策略的基础上，叠加截面策略，可以进一步提升策略的表现  

![](assets/011.png)