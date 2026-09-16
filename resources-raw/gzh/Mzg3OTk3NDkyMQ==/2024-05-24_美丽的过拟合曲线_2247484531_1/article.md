# 美丽的过拟合曲线

锤哥 QuantSeek 2024-05-24 11:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484531&idx=1&sn=8e1bd090f58a41810ce94c79045f31a9&chksm=ce6a7b17c5627a94b2077d4cee669d8727a026b93c9163f7170c88b669816971de8a2831b8ba#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484531&idx=1&sn=8e1bd090f58a41810ce94c79045f31a9&chksm=ce6a7b17c5627a94b2077d4cee669d8727a026b93c9163f7170c88b669816971de8a2831b8ba#rd)

量化人面临的两大实盘风险：

1、过拟合

2、衰减  

下面就是一条过拟合曲线，起源于我的一次“方法论的创新”，很遗憾，还是失败了，其实当我看到回测曲线的时候我就知道失败了。不过还好，样本外跟踪就把它pass了，不亏钱只亏时间。

![](assets/001.png)

另外关于衰减，策略大多都会衰减，还是锤哥一直强调的，衰减的幅度取决于逻辑的多少。有时候，赚钱仅需要最朴素的逻辑。