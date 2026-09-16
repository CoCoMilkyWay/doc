# 又来唠一唠曾在全球量化策略热榜上排名第6的RUMI策略

量化君 量化君也 2022-03-20 15:07

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&chksm=c3ba76fb8db84cdd3ad083d418f34140aee933420215fbe568e6ba68c69444f97c7a75a12311#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&chksm=c3ba76fb8db84cdd3ad083d418f34140aee933420215fbe568e6ba68c69444f97c7a75a12311#rd)

![](assets/001.png)

  

今天继续给大家唠唠以前见过的一些“怪异”量化策略，本次说的这个策略，它的源码实在是太短了，但TM还赚钱，还曾排过全球第6。

  

上一篇文章给大家介绍了在全球量化策略热榜上排名第9的策略，也同时介绍了美国著名权威的交易系统评选杂志之一的《Futures Truth Magazine》，没有看过的小伙伴，建议先回顾一下上期文章[《](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&chksm=c21ba108f56c281e134fd1e39531314b08426cb2bee56b6fe72cc4889be5ef166b8849a541b0&scene=21#wechat_redirect)[唠一唠曾在全球量化策略热榜上排名第9的TrendModelSys策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&chksm=c21ba108f56c281e134fd1e39531314b08426cb2bee56b6fe72cc4889be5ef166b8849a541b0&scene=21#wechat_redirect)》。

  

本期介绍的是在FT杂志中多市场量化策略排名第6的RUMI策略，RUMI策略的开发者是David Imgraben。

  

![](assets/002.jpg)

  

![](assets/003.jpg)

  

> 这个《Futures Truth Magazine》是美国著名权威的交易系统评选杂志之一，会定期通过不同维度对庞大的策略库进行跟踪评选。这些交易系统一般都被用于大宗商品、股票、外汇、股指期货等多个市场，由于进入排名榜单的交易系统业绩表现并不是一直稳定的，于是榜单会区分“上市以来/最近一年”和“单市场/多市场”进行区分排名，我们平时经常听到的Aberration和R-Breaker等交易系统，就是这个榜单的常客。

  

RUMI策略同TrendModelSys策略一样，最早期也是在TradeStation平台实现的，该TS平台的开发语言为EasyLanguage，在美国已有30多年的历史。

  

后来在2017年底，经某私募大神甲引入，并移植到交易开拓者TB、文华财经和MultiCharts平台上，同时适用于商品期货和中国A股，进行小范围的有偿分享。而后在去年，大神乙又进行了一番改进。

  

![](assets/004.png)

  

打开源码浏览，诶~~~

  

用力揉揉眼睛，发现没有看错。

  

这真的是全部的策略源码！

  

但是为什么这么短？！跟初次看到潘金莲的原配一样.......

  

仔细一琢磨，也有一定的道理，**该策略本质使用的是双均线，但不是我们平时的那种用法——“短线上穿长线做多，短线下穿长线做空”，而是计算双均线的离差值，并进行平滑处理，类似于微积分求X轴上下面积代数之和的简化方法，一定程度上过滤市场噪音，进而发出有效的开平仓信号。**

  

大神甲初始发布之时的回测盈亏曲线：

![](assets/005.png)

  

去年经大神乙改进后的策略回测盈亏曲线：

![](assets/006.png)

  

_PS：本文中大神甲的复现源码已分享至『量化藏经阁』和『量化藏经阁Max』社群内，群友请到社群资料库原路径中自取。_

  

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/007.jpg)

(微信号:iquantman)

添加好友后，私信『666』，领取量化小福利~

![](assets/008.png)