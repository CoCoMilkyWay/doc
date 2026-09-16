# 高级用户日思夜想的新功能

果仁策略 2017-07-13 18:40

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzI5MTEzNzg2Ng==&mid=2650935139&idx=2&sn=b004173e71612516f6421826dc955a42&chksm=f6634ef27c054ae9ff6d5ba3f1f7118ed21a68967c661b19c3b563eba87ec8cfd9fdde5f2c80#rd](https://mp.weixin.qq.com/s?__biz=MzI5MTEzNzg2Ng==&mid=2650935139&idx=2&sn=b004173e71612516f6421826dc955a42&chksm=f6634ef27c054ae9ff6d5ba3f1f7118ed21a68967c661b19c3b563eba87ec8cfd9fdde5f2c80#rd)

![](assets/001.jpg)

* * *

  

**自定义大盘择时**  

  

![](assets/002.jpg)

  

嫌大盘择时模板不够灵活的用户，现在可以**自定义仓位公式**，直接设定策略持仓的总体仓位。仓位公式需在每个调仓日返回一个0到1之间的数值，比如0.5，就设定策略的持股总仓位为50%。表达式一般需要使用一堆的IF嵌套表达式还有横向统计函数，对这不熟悉的用户建议还是使用模板择时。

  

**模型II策略有了持仓变量和持仓函数**

![](assets/003.jpg)

  

在**模型II**策略自定义卖出条件公式中，能够使用持仓股票的指标一直是高级用户的强需求。现在我们提供了如下持仓变量和函数。

持仓股票的变量：

后复权买入价: $beginPrice

持有天数 :$Days

买入后涨幅: $change

买入后最高点跌幅: $withdraw

买入时排名: $beginRank

买入时排名分： $beginScore

最新排名：$rank

最新排名分： $score

持仓股票的统计函数：

$max()

$min()

$sum()

$avg()

**使用例子**：

  

卖出排名下跌10名以上的股票 , 可定义卖出条件$rank- $beginRank >= 10

卖出在持仓股票中排名下降最多的股票，可定义卖出条件 $rank-$beginRank = $max($rank-$beginRank)

另外，新股买入附加限制里也增加了自定义功能。大家可以先去摸索，然后我们线上交流。