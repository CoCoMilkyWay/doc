# 如何使用Python构建基于风险调仓的投资组合

fintechhaibin FinTechHi 2025-02-23 21:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485458&idx=1&sn=f7214207d1f1b7d58a4c66ca4a05d6de&chksm=fb7a577e780755b5e4a6cbebb244bd704512b58ba4548f7a1c530afa1f30f8d1cce8abf9a5e1#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485458&idx=1&sn=f7214207d1f1b7d58a4c66ca4a05d6de&chksm=fb7a577e780755b5e4a6cbebb244bd704512b58ba4548f7a1c530afa1f30f8d1cce8abf9a5e1#rd)

管理投资风险最简单的方法之一是分散投资于低相关性的资产（鸡蛋不要放在同一个篮子）。先按照桥水的官网文章学习下基于风险管理投资组合的业务概念。

亿万富翁投资者Ray Dalio使这个概念出名，数十多年来，桥水构建投资组合的过程中始终遵循着三个原则:

1)分配风险，而不是分配资金；

2)区分阿尔法与贝塔；

3)最大化分散投资的好处。

这三个原则是建立长期、可靠、高风险回报比的投资组合的关键。下面通过python代码来构建一个简单的风险组合。

1.数据

使用Yahoo Finance数据源，通过其`yfinance`库来获取每日收盘价的历史数据。导入的库如果没有，自行安装即可。

```
# Libraries & Data
```

上面的代码最终输出了一个随时间变化的股票收盘价的DateFrame。

yfinance库存在请求流控，一直查询不到数据，换成akshare数据源。

```
# Libraries & Data
```

最终数据如下：

![](assets/001.png)

2.把价格转换为回报（Price->Returns）

计算数据集中每个列的百分比变化，并找出这些变化的中位数，然后将结果按降序排序并转换为一个数据集：

-   通过dropna()方法会移除包含 NaN 值的行，
    
-   returns.median()\`计算每列的中位数。
    
-   sort\_values(ascending=False)将这些中位数按降序排序，这样中位数最大的列会排在最前面。
    
-   to\_frame(name="median\_return") 将排序后的中位数转换为一个数据框，并将列命名为 "median\_return"。
    

```
# Returns
```

![](assets/002.png)

3.使用聚类可视化股票相关性

为了更直观的看不同股票的相关性，画一个相关性图：

```
# Clustering Correlations
```

![](assets/003.png)

4.选择相关性低的标的

从不同大类资产中选择具体的标的，上面代码中应该多查询不同资产大类下不同资产，代码中只是给了个示例。

选出了具体的标的后，可以使用Python测试不同的股票组合收益、分析基于风险做投资组合优化（使用riskportfolio - lib），并使用历史数据回测构建的投资组合策略。