# QuantML-Qlib开发版

QuantML QuantML 2024-04-11 09:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483845&idx=1&sn=6f3819847ab0987b200fc17506bfb3e0&chksm=cf9d92ed18888c90518666954dd3f2c249d227d3bcb45a7d19901f2936416114eeb12337b7e5#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483845&idx=1&sn=6f3819847ab0987b200fc17506bfb3e0&chksm=cf9d92ed18888c90518666954dd3f2c249d227d3bcb45a7d19901f2936416114eeb12337b7e5#rd)

1\. 进展

  

为了便于策略和因子代码发布，打算建一个QuantML-Qlib项目，基于QLIB进行开发，QLIB是一个非常强大的AI量化投资框架，基于QLIB底层结构，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

  

目前进展：

本来打算在Gitee上建一个私有项目，但是Gitee个人版有人数上限（还有少量名额，欢迎加入），所以目前代码维护在Gitee上，发布依然在星球内部发布。

  

  

![](assets/001.png)

  

  

项目内已经更新了Dlinear和MASTER策略模型代码，以及回测模块。模型运行的教程参考之前的文章，运行结束之后，可以利用信号进行回测，回测代码examples/scripts/backtest.py如下：

  

  

```
def run():
```

  

  

最终会计算得到各类指标：

  

  

 mean               0.000695

 std                0.007908

 annualized\_return  0.165394

 information\_ratio  1.355780

 max\_drawdown      -0.103054

  

  

同时回生成一个html页面用于展示：

  

  

![](assets/002.png)

  

  

  

  

  

**点击蓝字**

![](assets/003.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

星球内会同步QLIB开发版项目，欢迎加入交流。

  

![](assets/004.jpg)