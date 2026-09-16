# 时序数据库研究

数据攻城狮 QuantSeek 2023-06-11 20:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247483897&idx=2&sn=7be1e85675a5e5fc997635c44aaf11e8&chksm=ce12dc45d9a3a5568b25c4b136b766b2739fa9b186a51c562347f83ded44893100988fe88bb4#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483897&idx=2&sn=7be1e85675a5e5fc997635c44aaf11e8&chksm=ce12dc45d9a3a5568b25c4b136b766b2739fa9b186a51c562347f83ded44893100988fe88bb4#rd)

这篇文章与其说是研究，不如说是一个简单的综述，其目的是给各个正在调研时序数据库的朋友一些参考，最后给出一个资源禀赋约束下的建议。文章写得比较浅显，欢迎各位数据库大佬后台指导。  

  

# **排名**

首先肯定要参考的是一个权威的时序数据库热度排名：

https://db-engines.com/en/ranking

![](assets/001.png)

  

**数据库列表**

**一、InfluxDB**

ifDB有开源版和商业版，开源性上来说，这个数据库近乎是完全开源，不会有TDengine那样不能商业、必须开源的限制。  

  

但就性能来说，似乎处于一个中等的水平。  

  

支持windows；类似mongodb的schema free.

**二、Clickhouse**

从特性来看，确实很适合金融高频数据的存储（读取要快，方便分析），性能也不错。且开源。  

  

量化公众号1哥也写过它的介绍 及 其它相关的文章：

[https://mp.weixin.qq.com/s/7xxikscq5pUrqP59\_fQUJA](https://mp.weixin.qq.com/s?__biz=MzI5OTM3MjMyNA==&mid=2247491045&idx=1&sn=23f3124063c0951fd19994717e258778&scene=21#wechat_redirect) 大数据东风下，Clickhouse这坨屎是怎么上天的

[https://mp.weixin.qq.com/s/RZak0Sxc6h8lV-AKBmiBhA](https://mp.weixin.qq.com/s?__biz=Mzg3NjIyNjQwMg==&mid=2247507140&idx=2&sn=a7009a815ff745594afcf68833fd001c&scene=21#wechat_redirect) ClickHouse全面解析，看这一篇文章就够了

[https://mp.weixin.qq.com/s/Ru75dN15cqMbFqKrrv0sOg](https://mp.weixin.qq.com/s?__biz=MzAxNTc0Mjg0Mg==&mid=2653313194&idx=1&sn=f7c16e13650dc3ff9517faaf3aad2f35&scene=21#wechat_redirect) 量化投资与机器学习公众号

https://zhuanlan.zhihu.com/p/98135840  ClickHouse深度揭秘

  

缺点：  

1、据反映很难维护（PS：毕竟是开源的东西，也正常）；

2、不支持windows。

  

  

**三、OpenTSDB**

https://zhuanlan.zhihu.com/p/28747552 作者熟悉OpenTSDB，描述相当详细

  

开源，但是查询能力稍弱，写入能力较强，**不太适合**金融场景需求。

  

  

**四、TDengine**

国产数据库，开源（不能用于商业），完全开放源代码。也有商业版本（维护服务等）。开源版本性能上没有阉割，

  

性能也还不错。但可惜没看到它和clickhouse的对比。

  

暂不支持windows（未来会支持）。  

  

如果想支持国产，我认为这可能是个媲美clickhouse的选择。

  

  

**五、DolphinDB**

这是今天分享的唯一一款收费软件。

国产，缺点是收费，而且很贵，听过路演，感觉还不错，对**计算**的优化做得很足。近几年在机构的业务开展的很迅猛。

  

有社区版，但有限制（Up to 2 nodes with 2 cores and 8GB RAM per node）。

  

一些测评显示性能超越kdb。

  

  

**总结**

1、如果你是土豪个人或者机构，建议 DolphinDB 或者 kdb，鉴于一些测评显示DolphinDB性能更强，而且还能支持国产，那就DolphinDB。

2、如果是linux环境，缺钱，那么建议 clickhouse（比较难维护） 或者 TDengine免费版（国产，性能不差）。

3、windows环境，缺钱，那么InfluxDB。

4、其它，其实也不一定非要用时序数据库。  

  

有钱真好。欢迎各位大佬关注转发。

  

  

**附录：**

1、github对DolphinDB InfluxDB KDB TDEngine的测评

https://github.com/micli/timeseriesdb-benchmarks/blob/main/docs/index.md

2、 DolphinDB大佬评价 DolphinDB和TDengine的区别，TDengine和DolphinDB哪家强？  

https://www.zhihu.com/question/335871010/answer/1163702004