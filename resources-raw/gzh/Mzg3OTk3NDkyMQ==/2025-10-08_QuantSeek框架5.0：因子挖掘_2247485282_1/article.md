# QuantSeek框架5.0：因子挖掘

QuantSeek QuantSeek 2025-10-08 23:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485282&idx=1&sn=148c23e7390e9136c100c4fad11ac777&chksm=cee86d2c9aaacd8284019da338adc551e4570aae89df69563c1fc6bb245bb6154417846ed963#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485282&idx=1&sn=148c23e7390e9136c100c4fad11ac777&chksm=cee86d2c9aaacd8284019da338adc551e4570aae89df69563c1fc6bb245bb6154417846ed963#rd)

之前发布了[因子挖掘的大一统框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&scene=21#wechat_redirect)，很多读者私信跟我交流因子挖掘的事情。问的最多的问题就是因子挖掘有没有用，我一般都是这么回答的：因子挖掘是明牌，**绝对有用**，而且各大私募都在用

![](assets/001.png)

当然，如果指望靠这个就能到达什么高度，那我可以泼一盆冷水。但是，这东西**不能没有**。

紧接着就是一些读者催我把[因子挖掘的大一统框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&scene=21#wechat_redirect)提到的文章里面的东西整合到QuantSeek框架里，我原来想直接改改里面的东西，后来我发现不太好弄，和qlib绑定太深，而且写的太不解耦，不符合QuantSeek这套框架的风格，还是把我自己用的那套放上去比较好。

于是QuantSeek 5.0 上线了，目前融入了遗传规划的挖掘。后续会加入[因子挖掘的大一统框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&scene=21#wechat_redirect)提到的别的挖掘方式，。

## 一些特性

1、双目标遗传规划：避免单一目标产生的偏科问题，好因子一般不偏科。

2、基于pytorch和deap，可以用gpu运行，当然没有也没关系会自动用cpu。

3、添加目标和算子非常方便。

4、挖掘成功后，直接利用QuantSeek入库，每天实时更新。

5、完全解耦，可以用于任何市场，各位可以直接把模块拿出去用在别的地方也没关系。这也是QuantSeek的宗旨，这套框架适用于任何市场。

注释已写好，星球用户们赶快用起来吧。

![图片](assets/002.jpg)