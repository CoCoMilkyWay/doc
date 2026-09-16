# 36分钟，6万次报撤单，1手委托亏损400万，量化交易实盘中潜在的那些坑

量化君 量化君也 2023-04-23 22:08 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485126&idx=1&sn=b51077ea159120d4bae79b34fdbb6d81&chksm=c3cb4f14d1856dd75a5241811ba66a5cddae1626de85436457ba872cc4835d5dc2629db202a7#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485126&idx=1&sn=b51077ea159120d4bae79b34fdbb6d81&chksm=c3cb4f14d1856dd75a5241811ba66a5cddae1626de85436457ba872cc4835d5dc2629db202a7#rd)

![](assets/001.png)

  

前几天，一篇知乎文章《量化交易平台的坑有多大？由于行情错误1手委托损失400多万！》在量化圈子内疯传，以自述的形式，表达了在半个多小时内亏损400多万的经历和感受，为了方便表述，根据这篇文章作者的ID名，文中称呼其为“空哥”吧。

  

**空哥这次做的是期货跨期套利**，2023年4月19日上午10点半，量化交易系统监测到沥青2307合约和2308合约的价差处于低位，于是触发开仓信号，**做多价差，预期将来价差会增大，也就是要开多1手沥青2307合约，同时做空1手沥青2308合约。**

  

由于2308合约没有2307合约流动性好（交易活跃成交容易），于是计划先去成交2308合约，成交之后，再去交易2307合约。2308合约成交很顺利，按盘口价3919.0成交。

  

![](assets/002.png)

  

接着要开多2307合约，盘口卖价是3919.0，为了能立马成交，还在这基础上加了4跳（沥青的最小变动单位是1元/吨），发出了限价3923.0的委托单。

  

![](assets/003.png)

  

按照往常一般就成交了，如果不成交，就撤单，然后读取盘口卖价加4跳再发单，通常第二次都会成交，但神奇的是，还是没有成交，高能的地方来了。

  

**在10:30~11:06这36分钟的时间里，由于一直没有成交，在沥青2307合约上，不断地撤单报单，合计总数约6万次，空哥发现异常后，就手动停掉了策略。**

  

![](assets/004.png)

  

本以为就此结束，最多把单腿的空头仓位平掉就好了，亏损一些单边点差和手续费。1手沥青，市值不到4w，每日波动限制是±3%，跌停入手再涨停，1手空头当天最多亏损2k多，那空哥为啥因为这1手委托亏损了400w呢？

  

![](assets/005.png)

  

那是因为当天事后，**期货公司打电话来说，要收400多万的申报费，空哥这个期货账户里面本来有30w，现在不仅全部被划走了，还倒欠了374w。**

  

![](assets/006.png)

  

1手委托要收400w的申报费，是不是很震惊？咱来盘盘其中的道儿~~~

  

这个申报费，沥青这个品种所在的上海期货交易所以前是不收的，是去年8月4日夜盘开始才开始有的，详见上期所公告《关于在期货和期权合约对客户信息量收取申报费的通知》，各大期货公司和金融媒体也都披露宣传过，可能一般交易者都够不着他的起收门槛，很多人都没有留心，打个不恰当的比方，就如同个税起征点调到月薪10w才开始征收，那估计大部分国人都不会去了解10w之后的阶梯征收方式。

  

![](assets/007.png)

  

**那为什么1手委托能收400w的申报费呢？咱来详细看看上期所的这个申报费收取规则。**

  

从收费公式/图表当中看出，要计算出申报费，那就要理解“信息量”和“报单成交比OTR”这两个关键概念。

  

**信息量=报单、撤单、询价等交易指令笔数之和。**也就是1个交易指令对应着1个信息量，在那篇文章当中，空哥说自己使用的是FAK指令，FAK的全称是“Fill And Kill”，立即成交剩余指令自动撤销指令，简单来说就是下一个限价单，能成交就成交，不能成交的那部分就自动撤单。

  

那1个FAK指令对应多少个信息量呢？这得分情况，如果下了FAK，全部成交了，只有报单这1个指令，那算1个信息量，如果不成交或部分成交，那后面还会跟着1个撤单指令，这种情况下算2个信息量。

  

**空哥在沥青2307合约上一共使用了59600次FAK指令，而且都是没有成交，对应的就是59600次报单和59600次撤单，信息量合计是119200笔。**注意，信息量只针对笔数，跟每一笔指令对应的委托数量无关，无论你挂1手还是100手，都是收一样的钱。

  

接下来说“报单成交比OTR”，**报单成交比（OTR）=（信息量/有成交的报单笔数）- 1，因为空哥将近6万次FAK指令都没有成交，所以有成交的报单笔数为0，但分母不能为0啊，上期所对这种特殊情况的处理是将分母设为1，这次的OTR=(119200/1)-1=119199。**

  

OTR这个指标的设置意图就是用来衡量你的报单质量，数值越小，报单质量越高，数值越大，报单质量就越差。如果每一笔报单都全部成交，那OTR就恒定等于0，如果每次报单都没有成交，则OTR一直随着报单笔数增加而增加。

  

在上交所，OTR质量高低的分界点是2.0，OTR>2的各档位申报费都是OTR<=2的2倍，空哥这次很不幸，都落在了收费标准最高的那档。

  

![](assets/008.png)

  

现在，咱对着上期所那张收费表，看看这400多万是怎么算出来的。沥青在上期所是属于A组品种，OTR大于2.0，收费标准看最右边那一列。前面的4000笔不收费，费用为0，费用来自于4000笔之后。

  

4001~8000笔: 4000 x 0.5 = 0.2w

  

8000~40000笔：32000 x 2.5 = 8w

  

40000笔以上：(119200 - 40000) x 50 = 396 w

  

**合****计起来就是404.2w，这跟空哥披露的结算单一致，申报费用大头都来自于第2w次之后使用FAK指令，费用占比达到396/404.2=97.97%，如果空哥能在量化交易系统出现异常12分钟内手动停止策略就好了，至少能降低90%的损失。**

  

![](assets/009.png)

  

有的小伙伴可能就疑惑了，平常那些佣金手续费什么的都是实时收取，最多就把账户的钱给全部扣光，怎么这个申报费是一天一结，还把账户给搞穿仓了？

  

其实是这样的，这个申报费是交易所针对单个品种合约收取的，是交易所要收的钱，收这个钱的目的是“为强化监管效能，保障市场平稳运行......”

  

**但一个交易者可能在多个期货公司开通多个账户交易同一个品种合约，交易所要到每天结算时，才能汇总各个期货公司的交****易数据，才能计算出一个交易者他的合计信息量和OTR是多少，毕竟是阶梯收费，信息量越多、OTR越高收的越贵，这才有了实时交易不收申报费，到结算时才一次性收取，进而造成了穿仓。**

  

申报费看明白了，也计算明白了，但为什么要交这么高的申报费呢？那是因为6w次的报单撤单都成交不了1手沥青2307合约，为什么成交不了呢？

  

**空哥事后找原因发现，空哥所用的JZ量化软件推送的行情数据与其他行情软件显示的数据不一致，可能是JZ量化软件误将沥青2306合约的行情当成是沥青2307的行情推送过来了**，而当时沥青2306合约的实时价格比2307合约的要低10几跳，于是读取2306合约盘口卖价外加4跳都够不着2307合约的盘口价，导致了6w次报撤单都成交不了1手的悲剧发生。

  

也有人质疑空哥为什么不加报单撤单数限制，为什么要用FAK指令“炫技”？

  

这还是有一定历史原因的，这就要说到上期所在2019年1月发布的《上海期货交易所异常交易行为管理办法》，在“第二章 异常交易行为认定”中的“第十条 因套期保值交易、立即全部成交否则自动撤销指令（FOK）和立即成交剩余指令自动撤销指令（FAK）等产生的自成交、频繁报撤单、大额报撤单等行为不构成异常交易行为。”

  

![](assets/010.png)

  

**因为使用FAK指令产生的频繁报撤单行为都不属于异常交易行为，这是当时空哥在开发这个策略时所能看到的最新相关交易规则，于是就没有加上报撤单数目限制，后续又没有经常登交易所网站学习新制度，于是乎错过了后面的申报费收费规则的学习，没有再把报撤单数目限制加上去。**

  

整个事件的始末想必已经了解清楚了，那来总结一下当中量化交易实盘中潜在的那些坑，也给咱一些警示，查缺补漏。

  

**1.行情推送错误。**这是导致这次悲剧的直接原因，除了行情推送错误之外，还会有行情数据延迟，开仓信号错误或者错过交易机会；量化平台/交易终端宕机或掉线，导致委托交易失败或者回报信息慢重复报单；券商系统出错，导致获取持仓/资金错误，导致策略错误执行。别以为这些都是小量化软件平台或小券商才会出现的错误，其实浓眉大眼的交易所也会。

  

![](assets/011.jpg)

  

**2.交易制度变更。**正是由于空哥没有经常登交易所网站学习新的交易制度，没有意识到申报费对原始策略的影响，因此没有加上报撤单数目的限制，导致了高昂费用的产生。在前文当中，详细唠了申报费的收取细节，但那只是上期所的，各个期货交易所的计算细节还是有差异的，各位小伙伴一定要记得去看看自己交易标的最新的交易制度。

  

**3.风控细节不完善。**实盘交易是跟实时行情和反馈对接的，在整个交易链路当中啥幺蛾子都可能会发生，在策略当中重新加上“报撤单数目限制”是事前风控，但总有啥幺蛾子是咱事先想不到的，百密一疏嘛，这个时候至少可以在实盘策略当中加上一个预警提醒机制，事出反常必有妖，提醒一下终归是好的。

  

**愿空哥顺利趟过这次坎坷，福气都在后头~**

  

**参考资料：**

_空不异色，2023.4.19，知乎《量化交易平台的坑有多大？由于行情错误1手委托损失400多万！》_

_https://zhuanlan.zhihu.com/p/623266217_

  

_上海期货交易所，2022.7.29，《关于在期货和期权合约对客户信息量收取申报费的通知》_

_https://www.shfe.com.cn/news/notice/911341847.html_

  

_上海期货交易所，2019.1.21，《上海期货交易所异常交易行为管理办法》_

_https://www.shfe.com.cn/regulation/regulation/gather/911332893.html_

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484812&idx=1&sn=1697b0ff17a7e48a56ddab441cb5dd84&chksm=c21ba603f56c2f15c3ded82ee3bf59027a997b25cf22535045743b6860b12fbfa379c54d5f04&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484822&idx=1&sn=39ac52116f314f52f8adb090e6dba782&chksm=c21ba619f56c2f0f6ba71de6526e7fe916088b9a18402ab09f27d01d003a459cc7b59755969b&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/012.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/013.png)