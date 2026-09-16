# 因子分析（续）及AI应用

fintechhaibin FinTechHi 2026-01-23 20:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489277&idx=1&sn=221547919f5cedc580d396ea7ca8f529&chksm=fb04174d3085a6756b259d3d450d6c4a01864e95417210c5a1f9c72c0d5849ad103258320d42#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489277&idx=1&sn=221547919f5cedc580d396ea7ca8f529&chksm=fb04174d3085a6756b259d3d450d6c4a01864e95417210c5a1f9c72c0d5849ad103258320d42#rd)

[因子合成](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489263&idx=1&sn=71ee84444f76e09f49e84207c6d08d65&scene=21#wechat_redirect)

[单因子分析补充](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489222&idx=1&sn=125b539ad68976ce394b52cff82f97a1&scene=21#wechat_redirect)

[单因子分析框架](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489188&idx=1&sn=717c012007af184e6f620449493dd783&scene=21#wechat_redirect)

[因子本地化编写框架](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489180&idx=1&sn=c7852934b5a3b25703f17811c9f77f90&scene=21#wechat_redirect)

本篇文章从QD角度出发。

在为量化投研团队提供技术支撑的时候，往往可能需要构建一个本地化的因子系统，以便因子工作能在同一的系统下编写、回测、查看绩效、入库等。

# 1.因子分析指标补充

今天可以再参考一个分析视角：

-   判断因子有效性：IC均值的绝对值
    
-   判断因子稳定性：IC标准差的倒数
    
-   判断因子显著性：因子收益率均值的绝对值
    
-   判断因子区分度：多空收益率均值的绝对值
    
-   判断因子换手率：TOP组换手率均值
    

并通过图形化来展示统计结果：

![](assets/001.png)

![](assets/002.png)

# 2.定期因子绩效跟踪

同样的因子在不同的最新行情下，往往表现不同，

简单说就是当下行情，有的因子好，有的因子不好，

所以实际中一般会在固定的时间周期，结合因子衰减时间及特点跟踪因子在不同指数、行业下的绩效情况。以寻找当前环境下具有alpha能力的因子。

并基于最新的因子情况，进行模型迭代。（请注意：不是任何模型和策略都可以按此方式。）

所以，一般需要开发设计一个因子固定周期的数据跟踪分析报表功能：

我们参考网上公开的因子周报，通过腾讯元宝完成的界面设计如下（如果参考，直接复制图片到腾讯元宝，让他直接转换成html即可。）：

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

# 3.通过大模型给出因子自动化分析和结论

这是最近论证中的一个事。假设我们要通过大模型每周自动分析因子并给根据数据给出分析结论。则可以参考如下提示词：

```

```

同样，我们基于腾讯元宝设计个界面来展示结论，以alpha101因子为例：

![](assets/006.png)

关键特征分析：

![](assets/007.png)

市场环境适配性：

![](assets/008.png)

下周操作建议：

![](assets/009.png)

本周小结：

![](assets/010.png)