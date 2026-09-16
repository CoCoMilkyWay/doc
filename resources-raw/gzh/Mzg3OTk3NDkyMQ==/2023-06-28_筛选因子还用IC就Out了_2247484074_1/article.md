# 筛选因子还用IC就Out了

锤哥 QuantSeek 2023-06-28 08:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484074&idx=1&sn=07800fa99ff6a0cb921e1e84c752ea80&chksm=ce54b7d2b1d177f69efe35a7d0e3ce563495b899b2af6d11f3fee263e33ede7fc31a34911635#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484074&idx=1&sn=07800fa99ff6a0cb921e1e84c752ea80&chksm=ce54b7d2b1d177f69efe35a7d0e3ce563495b899b2af6d11f3fee263e33ede7fc31a34911635#rd)

01

  

导读

  

做量化评价因子的时候，IC、rankic是很通用的手段。而在多因子筛选的时候，简单利用IC和rankic选择往往效果不好，原因在于：

  

1、因子存在共线性，保留重复因子。

  

2、无法识别有用的非线性因子。

  

因此，IC不是一个好的工具，今天给大家介绍一个好东西。

  

02

  

SHAP  

  

**SHAP的基础定义**

  

SHAP(Shapley Additive Explanations)是一种在机器学习中用于解释预测模型的工具。SHAP值是基于博弈论的Shapley值的一种扩展，可以用于解释任何机器学习模型的输出。

  

SHAP主要关注特征的贡献度。一个特征的SHAP值代表了该特征在预测中的**贡献大小**，也就是，**如果我们移除了这个特征，那么预测的结果将会改变多少**。

  

SHAP方法不仅可以揭示特征的重要性，而且还能揭示特征的影响**方向**。SHAP值为正表示增加该特征将增加预测值，反之则会降低预测值。但一般来说，我们只看绝对值。

  

03

  

实现

  

**SHAP的Python代码实现**

在Python中，我们可以使用SHAP库来计算SHAP值。

  

首先是回归的例子：

```
import shap
```

![](assets/001.png)

  

分类也是可以用的，代码放在星球。  

  

  

  

  

迎加入锤哥的社群，AI + 投资，一个星球，收获2个功能。

![](assets/002.png)

欢迎添加锤哥个人微信：

![](assets/003.jpg)