# 因子挖掘点评：遗传规划与 OpenFE

QuantSeek QuantSeek 2025-03-13 15:11 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484967&idx=1&sn=9cd5c6fcd2c7d6eb571c65badad45352&chksm=ce6703c0310473baa4dc83cc4a2b78ffc15b21a4b81457f2149e27c928980cdbe1fa9608ea78#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484967&idx=1&sn=9cd5c6fcd2c7d6eb571c65badad45352&chksm=ce6703c0310473baa4dc83cc4a2b78ffc15b21a4b81457f2149e27c928980cdbe1fa9608ea78#rd)

**算子**

都需要预定义算子以加速

  

**因子生成**

**遗传规划**：先生成简单因子，有效的因子迭代生成更复杂的因子。

  

**OpenFE**：不考虑复杂性，一次性遍历生成因子**公式**，但暂不生成因子。

  

**迭代算法**

**遗传规划**：启发式的算法，即好的父代会产生好的子代。

  

**OpenFE**：因子公式被遍历产生，通过样本区间的二分法筛选，第一轮先用少样本计算排除一半因子，第二轮再用更多的样本排除一半的因子，以此类推。

  

**核心区别**

为了效率，遗传规划在因子产生上进行随机。

  

为了效率，OpenFE在评价因子的样本上进行随机。

  

**缺陷**

两者都可能会遗漏因子，但只要OpenFE的样本选择得当（我在星球会讲），效果要比遗传规划要好很多。

  

![](assets/001.png)