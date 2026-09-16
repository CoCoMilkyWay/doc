# 又来唠一个另类异质量化策略：20后的Trendflex策略

量化君 量化君也 2022-08-24 23:52 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&chksm=c381ae56f8c551ff74d3ce7edf1b77f0d5887f0001c3938c349e6d54b2ac5b7c2312bb67964c#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&chksm=c381ae56f8c551ff74d3ce7edf1b77f0d5887f0001c3938c349e6d54b2ac5b7c2312bb67964c#rd)

  

![](assets/001.png)

  

今天整个大市表现不好，可能是昨天任总的讲话，将寒气从制造业传导到了资本市场，咱也要居安思危，探索进取，在量化交易领域存活下去。

  

裹着被子爬(f)梯(q)子，看看大洋彼岸的宽客们，都在鼓捣些什么，有啥新奇的玩意儿。

  

你还别说，这次瞎逛还是蛮有收获的，最大的感慨就是，大神们的想法总是那么相通，开发的指标/策略总也是那么相似。

  

之前给大伙儿介绍过一个另类的量化策略：[_K线面积交易法_](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)，是在香港交易大神那里看到的，捶胸顿足恨自己当初没有保留原版。

  

这次我在交易杂志《股票与商品技术分析》（《Technical Analysis of Stocks and Commodities》，业内简称“S&C”）上，又看到了类似的指标用法，**那是约翰•埃勒斯（John F. Ehlers）在2020年2月刊文章《Reflex: A New Zero-Lag Indicator》当中提出的两个指标，分别是Reflex和Trendflex。**

  

![](assets/002.png)

  

别的孩子还是95后、00后，他们哥俩20后的都要出来营业了，咱先来唠唠这个Reflex~

  

先说第一个指标为啥叫这名儿。纯粹因为作者曾经也爱好玩弓耍箭，这个指标构造出来也很像一张弓，reflex在英文里就是“反曲弓”的意思，这是一种弓箭类型，与直拉弓相对，在复仇者联盟里面，鹰眼使用的就是一张反曲弓，于是乎，老约翰拍大腿觉得这名儿酷毙了，让他回想起那青葱的岁月，连文章的配图也是一张拉满弦的弓。

  

> 原文：I named this new indicator “reflex” because I used to be an archer, and the creation of the indicator reminded me of a bow and arrow. Reflex is a kind of bow with a cool name.

  

![](assets/003.jpg)

  

扯过闲篇儿，正儿八经说说Reflex这个指标怎么构造吧，跟把大象塞进冰箱流程一个样，总共分3步走。

  

**Step1：首先对原始价格序列进行平滑处理，采用的是 SuperSmoother过滤器。**

  

老约翰也是漂亮国量化界当中的翘楚了，非常善于用数字信号处理（DSP）技术对证券价格序列去伪存真，咱可以把SuperSmoother当成是一个低通滤波器就可以了，”过滤高频噪声，保留低频趋势“。

  

他在2014年1月刊的文章《Predictive And Successful Indicators》披露过SuperSmoother的计算细节，并通过试验证明SuperSmoother的去噪效果，比传统的指数移动均线EMA要好了不止一丢丢。

  

![](assets/004.png)

![](assets/005.png)

  

**Step2：从当前点位到N个周期的点位画一条直线，计算价格曲线上的点到直线上距离，然后计算出它们的平均值，记为S。**

  

学过微积分的小伙伴都清楚，这个将距离汇总的过程，就类似于积分求面积，所以我开头才说这个指标跟『K线面积交易法』很像。对总面积求均值，就相当于是求每个点到直线的平均距离。

  

![](assets/006.png)

  

**Step3：然后计算平均距离S平方的指数移动平滑值MS，最后将平均距离S除以平滑值的平方根，MS平滑的意图就是保证分母每日变化不要过大。**

  

T日MS = 0.04\*S\*S + 0.96\*T-1日MS

  

Reflex = S / sqrt(MS)

  

文章当中公布的Reflex完整版源码如下，量化平台是TradeStation，配套的编程语言是EasyLanguage，从名字就可以看出来，这款编程语言so easy，TS平台在国外用的人还是很多的，之前介绍过的量化书籍，里面的指标和策略也都是基于这个平台。

  

![](assets/007.png)

  

Reflex指标画出来的效果如下，当价格从低点上升的过程中，Reflex值是逐渐变大的，但是过了临界点之后，即使是价格仍处在上涨趋势当中，Reflex值也会变小，这个临界点的判断，简单来说，就是在step2当中，与N个周期前那个点的连线，是否和K线围成了更大的面积。

  

![](assets/008.png)

  

了解完Reflex之后，弄清楚Trendflex那就是很简单的事情了，因为Trendflex是Reflex的兄弟版本，它们之间计算是相似的，最大的差别就在step2中平均距离的计算上，也就是红框当中的代码。

  

![](assets/009.png)

  

Reflex是在当前点跟N周期之前的点连一条直线，而Trendflex是直接以当前点的价位画一条直线，从step2的计算细节来说，一般情况下，Trendflex的直线会与价格序列之间围出来更大的面积，而且直线的前N个点都是当前价位，随着价格的持续上涨，相对来说面积的变化程度没有Reflex那么大，特别是过了临界点之后，对趋势的保留更为明显。

  

![](assets/010.png)

  

**Trendflex指标画出来的效果如下，通过跟Reflex对比，可以看出，Trendflex在过了Reflex的临界点后，指标数值还是会随着价格上涨而增大，并且在之后会维持一个较为高位的数值。不过针没有两头尖的，有利就有弊，Trendflex相对来说比Reflex滞后。**

  

![](assets/011.png)

  

由于Trendflex对趋势的衡量较优，所以在股票期货和大饼圈等领域，使用Trendflex的人会相对多一点。

  

老约翰在文章中只是详细阐明了这两个指标的来龙去脉，但没有说具体用法，各路宽客也只好八仙过海，各显神通了，没有先天约束，想怎么用就怎么用。

  

**我就举个用法栗子，说个策略大伙儿参考一下，从Trendflex与价格走势图可以看出来，在上涨阶段，Trendflex在上涨初期，数值是随着价格上涨不断增大的，但上涨的中后段数值可能是不升反降。**

  

**下跌阶段也是如此，在下跌初期，Trendflex数值是随着价格下跌不断减小，但下跌的中后段数值可能是不降反升。**

  

**因此，Trendflex非常适合作为趋势初期的捕捉指标，在Trendflex创区间新高时做多，创区间新低时做空，出场咱就使用动态止盈止损就可以了。**

  

新鲜的食材，往往只需要(chun)简(cui)单(shi)的(xiang)做(tou)法(lan)，咱就拿期货市场上，经常被折腾的小(R)白(B)鼠测试一下，净值曲线如下。

  

![](assets/012.png)

  

看上去不是很惊艳，不是那种45度斜向上稳稳的曲线，但作为单品种单周期的朴素粗线条策略，我在上面还是看到了很多待挖掘的可能性。

  

_PS：本文『Trendflex策略』试验源码已分享至『量化藏经阁』和『量化藏经阁Max』社群内，群友请在社群量化兵器库原路径中自取。_

  

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/013.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

![](assets/014.png)