# QuantSeek框架4.0：组合回测

QuantSeek QuantSeek 2025-06-28 17:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485235&idx=1&sn=97ae361c37fc961f4738e03907ee03eb&chksm=cea1cdf027c086cec1c8408951f185cbf97fafdd00d77f0826334a7801cc5bb580b57b6d2fa4#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485235&idx=1&sn=97ae361c37fc961f4738e03907ee03eb&chksm=cea1cdf027c086cec1c8408951f185cbf97fafdd00d77f0826334a7801cc5bb580b57b6d2fa4#rd)

QuantSeek更新啦，这次加入了组合回测的模块。

## 组合回测

日级别的回测本身不是特别困难的事情，有几个注意的点：

1、组合的调仓时间不一定的日级别的，但是当然必须得获得日级别的净值。QuantSeek框架的逻辑是以调仓日tv\_date作为时间的标志，在这一天以某个价格调整到最新的组合权重。

2、成交价格是高度可拓展的，根据实际的要求进行改变。

3、组合的形成和回测是2个分开的逻辑，应当在组合形成时考虑各种情况，比如去掉st股。

这次更新还加入了一个低波100组合的回测样例，星球用户可自行查看。

  

![图片](assets/001.webp)