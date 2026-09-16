# 交易参数寻优示例

fintechhaibin FinTechHi 2025-02-07 00:02 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485270&idx=1&sn=20fbc2fa63419787c55dd32706ee2e31&chksm=fbda8a1d7c8764caf39cbfb088a76a3622db5feeb20e801d19eb653138881d2bab576138df4d#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485270&idx=1&sn=20fbc2fa63419787c55dd32706ee2e31&chksm=fbda8a1d7c8764caf39cbfb088a76a3622db5feeb20e801d19eb653138881d2bab576138df4d#rd)

说明4点：

1.此篇文章为【交易参数调优】示例代码，离实际使用还差十万八千里。

2.数据源使用akshare

3.回测框架使用backtrader（注：vectorbt比较坑，依赖numpy版本比较低，还存在各种问题）

4.完整代码若需要，私信我即可，不管多久，我一定会发，留言我没时间一个个回，抱歉。

  

1.安装依赖包

```
pip install akshare backtrader
```

  

2.导入包

```
import numpy as np
```

3.指标

先选择两个指标：williams和**Aroon。跑通后发现一直没有产生交易，为了排查问题，就写了一个单独检查两个指标数据的代码。**

```
import numpy as np
```

williams和**Aroon指标检查结果如下，可以看到基础数据没问题，但指标数据异常。**

![](assets/001.png)

然后换成更好演示的MA：

```
import numpy as np
```

数据果然没问题，所以使用MA(5)和MA(10):

![](assets/002.png)

最终要准备的基础数据代码如下：

```
# 计算简单移动平均线的函数
```

  

4.网格寻优

以最大化总投资组合的回报为目标，找到MA最长最短的最佳周期，具体逻辑参考代码中的注释。

```
# 网格搜索以优化周期
```

5.所有参数组合的总回报

量化研究的常规操作，上图。

```
# 绘制所有参数组合的总回报热图
```

结果如下：

![](assets/003.png)

6.选择最佳参数

`根据最高总回报找到最佳参数组合，并使用最佳参数计算最终投资组合。`

```
# 根据最高总回报找到最佳参数组合
```

7.回测最优参数

`使用backtrader进行回测，使用优化后的参数：`

  

```
class MyStrategy(bt.Strategy):
```

输出结果：拿到圣杯了吗？看着结果都假的离谱，这就是量化，跑通很简单，对不对才是硬实力。（请注意：此文只是演示参数寻优的思路。）

```
Best MA(5) period: 27
```

  

8.绘制权益曲线

```
# 绘制权益曲线
```

图画出来没有数据，懒得排查了：

![](assets/004.png)

以上就是通过网格搜索，进行策略交易参数寻优过程。当然还有更佳做法。本文只是做个思路示例。