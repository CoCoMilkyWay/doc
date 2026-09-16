# 量化交易四大邪术（完整版）

量化君 量化君也 2024-10-09 21:48 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486330&idx=1&sn=10e5309bc821819950e43bf7df0cac21&chksm=c395a7b7e6ee7a72cd07fc59f04d90bb7358e1598a8343814a3a2bc6871ef05cd773fde28f10#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486330&idx=1&sn=10e5309bc821819950e43bf7df0cac21&chksm=c395a7b7e6ee7a72cd07fc59f04d90bb7358e1598a8343814a3a2bc6871ef05cd773fde28f10#rd)

![](assets/001.png)

  

做量化交易有些年头了，见过的策略也成百上千了，前段时间突发奇想，想揭露一些“照骗”策略，尽自己所能减少一些上当受骗的人数，于是写了一个量化邪术系列，今天来做一个大汇总。

  

为什么叫量化交易邪术呢？因为在古早的简中网络中，流传着亚洲有四大邪术：日本化妆，韩国整容，泰国变性，天朝PS。这些都是让人在颜值上看起来很美的技术，类似地，在量化交易领域，也有一些科技与狠活能让量化策略的收益看起来很美，仅仅是“看起来”，并且普遍目的不正当，因此称之为“量化交易邪术”。

  

![](assets/002.png)

  

**这样的邪术最常见的也是4个，合称为“量化交易四大邪术”，如下：**

**1.般若波罗蜜——未来函数**

**2.霸王硬上弓——强制成交**

**3.春去花还在——过度拟合**

**4.春梦了无痕——交易成本过低**

  

这四大邪术除了会被别有用心之人主动用来美化策略割韭菜之外，有一些量化萌新在自己开发策略时也会不小心踩雷，慎之慎之，下面逐一用实例介绍。  

  

**一.般若波罗蜜(未来函数)**

先来看看这条带未来函数的收益曲线美不美？要是有骗子用这种收益曲线去卖策略割韭菜，可能有不少不懂行的萌新上当受骗吧～

![](assets/003.png)

  

**"未来函数"，顾名思义，就是在量化研究和策略回测当中，使用了当前时间点还没有发生的数据，引入了未来的信息去决定当前的交易信号。**

  

这就相当于至尊宝举起月光宝盒，大喊"**般若波罗蜜**"，时光倒流，带着已知，穿越回去，挽救爱情，而金融的实盘行情当中，没有这种神奇外挂，也无法给你未来的信息。所以啊，有未来函数的策略，回测看起来像《安乐传》当中的迪丽热巴，实盘起来就成了《黑悟空》里面的金池长老。

  

![](assets/004.png)

  

刚才说的都是抽象的概念，接下来我举一个实打实的例子，并且这个带未来函数的策略，还可以"巧妙"地通过量化平台的防未来检验。

  

这是之前群友发的一个圣杯策略，据说是非常牛逼，拿策略源码一回测，哦豁，这TM真的是小母牛坐火箭，牛逼上天了啊！！！

  

![](assets/005.png)

  

![](assets/006.png)

  

**回测从2014年开始，近10年的累计收益率是8359157.97%，年化收益率是198.49%，夏普为6.297**，好嘛，10年8万多倍，每年翻2番，什么西蒙斯、巴菲特、索罗斯，仨人捆一块儿都不是对手，在这个“圣杯”面前都是渣渣。

  

**这么逆天的收益曲线，以我多年踩坑的直觉，肯定是有猫腻啊**，二话不说，先在原来策略基础上打开防未来函数功能，在回测设置部分加入以下代码。

  

```
# 打开防未来函数功能
```

  

**设置avoid\_future\_data为True，表示开启防未来函数功能**，也就是在回测当中，使用包含时间参数的官方API去获取数据时，如果获取了当前日期之后的数据，程序则会抛出异常，无法正常回测。

  

重新回测后，绩效还是纹丝不动，还是10年83591倍，每年翻2番，真正的猫腻还是要耐下心来细细读代码才能发现的。  

  

通读下来，这个"圣杯"就是一个单因子策略，大致分3步走：  

  

（1）每5个交易日交易一次，以创业板指成分股为基础股票池，剔除停牌无法交易的股票，形成当次的可交易股票池。

  

（2）在可交易股票池中，以Zura Kakushadze大神《101 Formulaic Alphas》论文中的第101号因子当前值作为选股因子，数值从大到小排序，选出其中数值最大的前10支股票。

  

（3）对于这10支股票，等权买入，不在此列的持仓则卖出，在此列的持仓则需要重新恢复到等权。  

  

**这个策略中的"第101号因子当前值"就是带有未来函数的了，但是很“**巧妙**”地绕开了avoid\_future\_data的检查机制，下面细说。**

  

avoid\_future\_data一般用来防止当天使用当天之后的数据，但是如果当天使用当天的数据呢，就不会抛出未来函数异常（至少这个策略没有），就可以正常回测。虽然是当天调用当天数据，但却是开盘时就获得了这一天的涨跌幅信息，具体情况往下看。

  

```
def get_stock_factor_values(date):
```

  

获取因子数据时，使用的是当天的日期，而这个alpha\_101因子的计算式子是：(收盘价 - 开盘价) / ((最高价 - 最低价) + 0.001)。

  

![](assets/007.png)

  

![](assets/008.png)

  

“收盘价 - 开盘价”是日线Bar中实体的长度，“最高价 - 最低价”是整个日线Bar的长度，“0.001”是防止分母为0，简单来说，这个因子就是衡量实体占整个Bar的比例，数值越大，占比越高。

  

那什么时候数值最大呢？如果分母里面没有那个0.001，那光头光脚的阳线数值最大，只要不是一字板，那么这个因子的数值都是1.0。但现在是有了0.001，那就是涨幅越大的光头光脚阳线的因子数值越大，举个极端的例子。  

  

假设close - open = high - low = 0.001，则alpha\_101 = 0.5；

  

假设close - open = high - low = 1.0，则alpha\_101 = 0.999。

  

看到了没，**这个策略相当于在开盘时就选中了今天涨幅最大的股票进行买入，变相地会卖出今天涨幅“不如意”的股票，并且策略当中是使用order\_target和order\_target\_value函数进行交易，默认是按照开盘价成交的，这妥妥明确地吃到一整天肥美的涨幅。**  

  

那咱就把获取因子的数据调整到上一个交易日，重新回测一遍，你瞧，原形毕露了吧，10年累计收益-78.13%，年化收益-13.87%，连基准指数都没有跑过，**怎一个惨字了得！**

  

```
date = str(context.previous_date)[0:10]
```

  

![](assets/009.png)

  

![](assets/010.png)

  

看到了吧，即使这个量化策略持仓周期是5天，只有1天的未来信息，但也可以带来巨大的虚假繁荣，一旦未来函数被揪出来，圣杯的光芒就会迅速地黯然褪去，如果不想中"未来函数"的邪，可以看一下之前的避坑贴[《答应我，在量化策略回测里，避开未来函数这4个坑》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&chksm=c21ba13ef56c282892e62144626f5b5c741870628f4ba67e65142dc32ca6ddb044158a4033e3&scene=21#wechat_redirect)。

  

即使现在量化平台越来越完善，有很多功能防止用户出错，但只要是人设计的系统，总会有不完美的地方，**就怕别有用心的人会利用这些漏洞和缺陷，钻未来函数的空子，构建出漂亮的“庞氏曲线”割韭菜。**

  

  

**二.霸王硬上弓(强制成交)**

来来来，再来看一下这个策略的回测绩效，对的，你没有看错，不是累计收益，是年化收益，年化收益11113.14%，也就是111倍。

  

![](assets/011.png)

  

这个量化策略群友兄dei发给我的时候，说这个策略收益吊炸天，胸脯还拍得山响，保证里面没有未来函数。

  

我心里也纳闷，真的假的啊，将信将疑先打开源码䁖一䁖，快速地看一下。

  

在初始化函数前5行代码里面就找到了【set\_option("avoid\_future\_data", True)】，这个是回测的全局设置函数，它开启了【防未来函数】功能，就是系统会自动限定你看不到当前时刻之后的数据，除非你调用的不是系统的数据获取函数。

  

这个功能也不是万无一失的，因为它只是限制了你今天不能取明天的数据，但限制不了今天开盘取收盘的数据(日线级别的话)，也就是取数逻辑不跨出回测的周期级别，就不会报错。

  

于是跳到关键选股函数，取数截止日期用的是【context.previous\_date】，用的是上一个交易日（含）之前的数据，这样的话，有未来函数的嫌疑就极大降低了。

  

先跑个回测看看，分钟级的回测比较慢，先看2020年至今的吧，神奇的事情发生了，我一开始只知道收益率逆天，想不到可以逆天到页面都无法正常显示，这收益率真是高到模糊啊！

  

![](assets/012.png)

  

![](assets/013.png)

  

没有办法了，只好把回测时间缩短，再来跑一遍，终于可以正常显示了。

  

![](assets/011.png)

  

![](assets/014.png)

  

不会吧，年化收益11113.14%，夏普率139.5，什么西蒙斯、巴菲特、索罗斯，仨人捆一块儿都不是对手，在这个“圣杯”面前都是渣渣。

  

![](assets/015.jpg)

  

回测这么逆天，以我多年长期踩坑的经验来看，这种“妖策略”必定有古怪，没有未来函数这种阎王，也可能有难缠的小鬼，到底是什么bug呢？最直观地，先从最近持仓开始看起。

  

不看不知道，一看果然有猫腻，最近2024年8月30日还买进了科\*科技和奋\*科技。

  

![](assets/016.png)

  

![](assets/017.jpg)

  

![](assets/018.jpg)

  

我的天爷啊，这俩股票都是一字板涨停，并且全天没有开板，这样的股票都买得进，那还有什么事情做不出来，还是静下心来仔细看策略源码。

  

**细读之下发现，****这TM是一个打板策略**，策略核心要点如下：

  

（1）在每天开盘前选择上一个交易日涨停，并且上一个交易日创了近3个月的收盘价新高的股票作为选股池，但剔除创业板、科创板和ST股。

  

（2）按分钟回测，在大盘行情向好时，买入股票池中涨幅超过9.5%的股票，最多持有N支股票，买满N支不再买入。

  

（3）在收盘前的固定时间点，卖出不再涨停的可卖出股票（今天之前买入的），如果涨停，则继续持有。

  

**关键是第二条中【买入股票池中涨幅超过9.5%的股票】，这是说股票涨幅超过9.5%就买入，但没有说涨停了就不买了，而且回测时都能成交，这到底是为什么呢？**

  

**最后终于找到了元凶，那就是在全局设置时，将【match\_by\_signal】功能设置成了True，也就是强制撮合，发出委托时将不对委托价格和成交数量进行任何检查而直接成交。**

  

这就解释了为啥能买入一字板涨停的股票，因为你敢挂单，系统就敢给你成交，让你吃到后面连涨的收益，一天一个涨停板，咱们就可买地球（在回测中或梦里）。

  

有交易经验的小伙伴自然清楚，在实盘当中，开盘就涨停的股票不是完全没有机会吃进，但能吃进的基本上都是涨停后封涨停不稳的，后续上涨就乏力了，而那些死死一字板封死涨停的股票，能吃进的概率非常小。

  

**简单来说，实盘中这个打板策略能买进的股票后面上涨乏力，能连续涨停的股票绝大概率买不进。**于是乎，咱把【强制撮合】功能关闭后，这个打板策略就出现亏损了，回测绩效如下。

  

![](assets/019.png)

  

![](assets/020.png)

  

![](assets/021.png)

  

看到了吧，策略源码就差了这么一行，回测绩效真是云泥之别，之前可以丝滑买入涨停股的策略，现在回测时都会被系统提示【 WARNING - 已经涨停，市价买单取消】，年化收益就从原来的狂赚111倍变成现在亏损77%。

  

**这种在实盘中难以成交，但在回测当中却能强制成交的情况，就被称为“****霸王硬上弓****”。**  

  

谁都知道能买入连续涨停的股票可以赚得盆满钵满，但实盘就是买不进啊，那怎么办呢，就有人动了“歪心思”，利用技术手段在回测当中帮你买进去，圆你一个泡沫之梦，顺便割一刀韭菜。

  

上面说的强制撮合是由于流动性问题导致实盘无法成交，还有另一种常见情况——偷价，则是由于不合理的交易价格导致实盘无法成交。总而言之，量化策略设计要合理，回测和实盘成交情况要一致，否则实盘难成交、回测能成交都属于“强制成交”。

  

对了，顺便提一嘴，很多量化平台都有很多“新颖设置”，让用户可以突破传统交易规则的束缚，想怎么交易就怎么交易，比如说股票可以T+0交易，当天买入的股票当天就可以买出，还比如非交易时间段也可以交易。这些都是量化平台为了方便用户的特殊研究需求，就怕被别有用心的人利用，钻空子，割韭菜。

  

  

**三.春去花还在(过度拟合)**

再上一个猫腻策略，让大伙儿感受一下。这当中的回测，是已经开启了防未来函数功能，且取数日期是上一个交易日，并且确认已经关闭强制撮合功能，也就是说，已经排除刚才咱说的那两个未来函数和强制成交的bug。

  

![](assets/022.png)

![](assets/023.png)

  

回测绩效和收益曲线看起来不错吧，策略近五年的累计收益是1922.20%，年化收益是77.35%，最大回撤是22.02%，夏普率是2.956，收益最大回撤比是3.51，看上去就是“别人家孩子”般的策略，年化收益也不是一个很离谱的水平(跟前面两个策略比起来)。

  

**但咱要说这是一个小市值策略，估计会有不少小伙伴快速反应过来，觉得这收益曲线极其不正常**，因为做过的小伙伴都清楚，今年上半年1月份和4月份，小市值跌得连妈都不认识了，这个策略的收益曲线还稳如老狗，并且最大回撤还是出现在2020年底。

  

![](assets/024.jpg)

  

为什么会这个样子呢？遍览策略源码，发现猫腻出现在选股模块中的这一段。

  

```
no_trading_signal = today_is_between('01-10', '02-10') or today_is_between('04-08', '04-30')
```

  

你瞧，如果今天是在1月10日~2月10日之间，或是在4月8日~4月30日之间，就不开仓，这期间一直保持空仓状态，这样就不会出现大跌了，收益曲线上的走平的地方就是这么来的。

  

**即使好日子过去，黑天鹅发生，依然可以保住利润，春去花还在，这就属于『过度拟合』或『过拟合』了。简单来说，过拟合就是在样本内数据上表现良好，但在样本外数据上表现较差的现象。**

  

为了让收益曲线长得漂亮，有些居心叵测卖策略的骗子，就会在策略当中加入大量日期判断的IF语句，类似于today=='2024-07-03'、today=='2024-09-02'，today=='2024-09-09'，blalala~~~用来过滤掉明显亏损的交易或交易日期，只留下盈利的单子和微亏的单子，这样只是让回测好看一些，但实盘上很难复现得了，特别是用来欺骗看不懂策略源码或懒得看的韭菜。

  

说回刚才的那个小市值策略，肯定是因为今年1月和4月小市值大跌才加入这样的日期过滤，曲线昂首向上才有好卖相嘛，但去年底还不知道这种情况，**不加日期过滤跑到现在的话，就是下面这个鬼样子，累计亏损19.25%，最大亏损46.11%。**

  

![](assets/025.png)

![](assets/026.png)

  

就算策略开发者就是单纯地认为，以后的1月和4月就是小市值要下跌不开仓，但市场行情是多人博弈，人的认知也是会进化的。

  

假设大家都发现了这条规律，比方说有人比较鸡贼，或者自己规模太大，就会抢跑提前卖出，那小市值就会提前下跌，基于日期的过滤就会逐渐失效，变成一厢情愿的日期拟合，这也是日历效应会漂移的原因。

  

过拟合的原因有很多，而且还有主观层面的善恶。刚才说的，就属于比较明显的恶意，为了策略卖相好看割韭菜。其他的一些原因就是纯粹的技术原因，没有主观层面的恶意，比如说样本数据少、样本数据噪声太大、样本内外特征分布不一致、参数过多、模型太过复杂等等。

  

![](assets/027.png)

  

长久的实践中悲伤地发现，恶意的过拟合可以避免，但善意的过拟合只能尽量减弱，很难完全避免，就如同黄金纯度也没有百分之一百的。

  

因为归纳和演绎是人类认知活动中常用的方法，拟合其实就是一种归纳，从现象中总结出规律，开发策略无论如何都是要“拟合”的，归纳差一点点就是欠拟合，想得多了一点点就是过拟合，刚好拟合是一种非常完美的状态，很难100%达到，就如同机器学习/深度学习领域，过拟合问题如影随形，想了交叉验证、正则化、Dropout等多种方法，测试集不如训练集是常态，量化实盘不如回测也是如此。

  

  

**四.春梦了无痕(交易成本过低)**

最后，还是按照惯例，先po一个猫腻策略上来，让大伙儿感受一下。

  

![](assets/028.png)

  

![](assets/029.png)

  

这个策略还是去年上半年的时候，群里的一个兄dei发给我观摩的，当时回测下来，**近5年累计收益有131倍（年化157%）**，收益曲线稳健狂飙，闪烁着圣杯的耀眼光芒，**西默索泪**。

  

看到这么漂亮得有点儿逆天的收益曲线，第六感告诉我肯定又是『未来函数』在作妖，打开策略源码一瞅，一目十行的速度看到了第15行，就已经发现，**在回测初始化设置里面已然开了“防未来函数”功能，而且取数用的也是上一根Bar**。

  

![](assets/030.png)

  

**接着往下看，也没有发现开启“强制撮合”功能的函数**，由于系统是默认不开启这个功能的，为了保险起见，就调用设置函数显式地关闭这项功能，再回测一遍，发现收益还是这么逆天，收益率没有任何改变。而且，也没有日期过滤等恶意过拟合的操作，没法子了，只好逐行阅读源码，看看其中到底有什么猫腻。

  

**通读下来，发现这是一个低价股策略，在每周的第一个交易日开盘之后，会先把股票前5个交易日均价在1块5以下的股票统统剔除，然后再剔除停牌股、ST股等乱七八糟的股票，最后选择股价最低的那支股票，作为本周的专属交易股。**

  

**精彩的地方来了，那就是它的交易时点，并不是根据什么技术指标或模型预测信号进行买卖，而是在每天指定的时间范围内，每隔一分钟就会去下一次限价委托单。**

  

买单的委托价格是最近一个50分钟K线的最低价，卖单的委托价格是最近一个50分钟K线的最高价，如果上一分钟的订单没有成交，则撤单后继续根据最新价格下单，如果成交，则此后不再执行同类型交易，也就是买了之后就只卖不买，卖了之后就只买不卖。

  

这样说起来很抽象，咱结合成交明细进行举例说明，策略的回测时间是从2018年1月1日开始的，初始本金为10w，2018年1月2日是当年的第一周第一个交易日，那一周在盘前筛选出来的股票是“和B生物”，确定了那一周的专属交易股。

  

![](assets/031.png)

  

2018年1月2日开盘后，经过多轮报撤单，终于在10点40分，以2.01元成交价买入了497手，由于A股T+1交易规则，当天不再买入。

  

由于已经有持仓，2018年1月3日开盘后，则开始执行卖出操作，在10点21分，终于委托单全部成交，将昨日旧仓全部卖出，成交价为2.03元。

  

此时，由于又有了可用资金，就又开始了买入操作，仅两轮报单后，就很幸运地又把股票买回来了，当日便停止交易，明天又会按照今天的流程走一遍，如此循环往复。

  

发现没有，这就是每日都在做T，变相实现“T+0”操作，每天一开始就把旧仓卖出去，然后又把股票买回来，一天之内同时实现了买卖两种操作，用日内波段的价差增厚收益。

  

这里面的确没有未来函数，也没有强制撮合那些鬼玩意儿，那收益为什么能这么逆天呢？

  

先来说说这逆天收益的来源，那这就要说到我国证券的交易规则了，**因为咱大A股交易的申报价格最小变动单位是0.01元，也就是1分钱**，简单来说，也就是咱每次修改价格下单，要么加减1分钱，要么就是加减1分钱的整数倍。

  

**别小看这1分钱，对低价股来说可就有大用了，因为1分钱相对1块钱股价来说就是1%，相对2块钱股价来说就是0.5%。**

  

就拿2018年1月2日~3日的交易来说，2.01元买入，2.03元卖出，赚了2分钱，价差是大概赚了1%，回测当中设置买入/卖出佣金是万2.5（0.025%），双边合计就是万5（0.05%），卖出时印花税是千1（0.1%），那交易成本大概就是0.15%。

  

这一天之间的一进一出的收益就大概赚了0.85%，那5年就算1200个交易日好了，每个交易日赚0.85%的话，1.0085的1200次方是25768，这就是25000多倍啊，100多倍相较之下只能算是弟中弟了。

  

因为这个策略是不断在等待区间低位买、高位卖，能高胜率地“刮头皮”，这点儿“头皮”对低价股来说，可就是过年吃饺子了。

  

但哪有可能天天过年天天吃饺子的，也许策略初始想法是好的，只是在实盘中难以复现，哪怕是打对折复现。**因为****回测当中能成交的价格，实盘里面成交起来就困难了，要考虑到盘口流动性和交易成本。**

  

在一般的回测当中，只要股价"触碰"到限价单委托价，那就默认全部成交；而对于低价股来说，在实盘当中，买卖价差一分钱，那可能就是千军万马在排队（想想高考差一分就可能刷掉几百人），且不论能不能排到你，就算排到你，也不一定是全部成交，那就不可能有回测中那种收益。

  

![](assets/032.png)

  

对于这种情况，回测系统要模拟出来还是比较难的，因为很难模拟出实际交易中，你的委托单在等待队列中排在哪个位置，能不能成交得了？

  

那咱可以“曲线救国”了，换一个方向去论述。刚才不是说了嘛，盘口“千军万马在排队”，**咱就简化一下，只要股价能打到委托价，就算可以成交，但委托单的实际成交量不能超过当前K线总成交量的千分之一。**

  

在回测系统当中，使用set\_option函数，将order\_volume\_ratio设置为0.001后，再来回测一遍，发现累计收益率下降到了1016.76%，一下子缩水了十几倍，收益曲线也没有之前那么昂首挺胸了。

  

![](assets/033.png)

  

![](assets/034.png)

  

其实这种情况还是好的，因为还是默认了你能成交，还是让你“刮了头皮，吃了饺子”，只不过是少了点儿，不能再“胡吃海塞，想吃就吃”，**至少说明了这个策略对成交率很敏感，成交得少了，开始还好，但后面的复利就上不去了，再也没有上百倍的收益了。**

  

但实际情况肯定还没有这么理想，在实盘当中往往是，能让你能排队买进去的，都是股价开倒车回来接你的，继续跌势的风险非常大。

  

为了让委托单充分成交，提高实盘当中的成交率，让其与回测中的相近，一般会在交易时使用市价单或是扩大价格范围的限价单，**无论使用哪种单，都是考虑到了实际成交价没有回测模拟当中的那么理想，而这种现实和理想之间的差距，被称之为“滑点”。**

  

这个世界上最没有意外的事情就是有意外，量化交易里面也是如此，所以各个量化平台考虑到回测和实盘之间的差距，都会加入滑点模式来帮助大伙儿更好地模拟量化策略在真实市场中的表现，**在这里咱就给原始策略加上一个最小的滑点，买卖各偏移1分钱就行了，也就是买入的时候会比原始价格贵1分钱，卖出的时候会比原始价格便宜1分钱，再来回测一遍。**

  

![](assets/035.png)

  

![](assets/036.png)

  

此刻，这个低价股策略就原形毕露了，收益曲线掉头急转直下，最终策略收益-99.87%，基本上是亏完了，其实从2018年1月到2020年10月，都不够3年，策略就已经亏损了99%，只不过后面剩余本金太小了，相对原始本金来说基本上已经忽略不计，后面两年多基本走成了一条直线。

  

出现这种现象，是因为滑点基本上抵消了原来刮的头皮，每次交易基本上都是在妥妥地亏手续费，而且部分交易还会亏价差，上面说了每次一买一卖合计交易成本是0.15%，那就估计每次亏0.30%好了（现实应该比这严重），0.9970的1200次方是0.027，也就是交易到最后，最终剩下的钱只有本金的2.7%。

  

因为原策略使用的是限价单，所以不会有这种买卖浮动1分钱的滑点，原策略最大的问题还是回测当中能成交的委托单，实盘当中成交不了，也就是成交率低。这里只是想补充说明，如果为了提高成交率，将限价范围扩大的话，原始策略会嘎得非常难看。

  

发现了没有，这个策略盈亏的核心影响因素就是“交易成本”，交易成本主要包括佣金税费和滑点，佣金税费一般是固定的，可变的就是滑点了，按“0滑点”理想价格成交，赚得盆满钵满，但实盘中成交率低，要提高成交率呢，支付的成本就会变高，按“1分滑点”价格成交，策略亏出天际。

  

**所以啊，很多别有用心的人，为了搞个漂亮曲线卖策略割韭菜，就会用这招，设置明显过低的交易成本去做回测，特别是低价股、短线和高频策略，利用高百分比或高频次积累盈利，回测成交是“春梦如烟了无痕”，实盘情况却是“账户沧桑难逢春”。**  

  

聊完正题，再来说说这个策略的后续，眼尖的小伙伴会发现这个策略的回测截止日期是去年的4月28日，那回测到今天会是什么样呢？

  

![](assets/037.png)

  

![](assets/038.png)

  

就是上面这个样子，这是原版策略回测至今，可没加滑点那些。策略收益大幅衰减，去年至今出现了一个幅度达到将近90%的回撤，一开始放出来就是怕有些小伙伴分心。

  

这个巨大的回撤分为两波，造成这两波回撤的原因是一样的，前一波起始时间是去年年4月底，第二波是今年4月底，都是持仓股票(阳G城和富T信息)的上市公司披露年报时，会计师事务所出具了否定意见的内部控制审计报告，触及了深交所相关规定中的“其他风险警示”，带上了ST的帽子，五一之后开市，一连吃了20多个跌停直至1元面值退市，百倍收益，一朝踩雷，终成泡影！

  

![](assets/039.png)

  

![](assets/040.jpg)

  

**这量化交易的四大邪术就盘点完了，希望看到的有缘之人，既不上当受骗，也不中枪踩雷，世道无常，审慎留心，别中了这种邪，上了这种当！**

* * *

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486235&idx=1&sn=b946c1496b177a4838b14caa98bd713c&chksm=c21ba894f56c218282c2f5e450c594b4133f6a7f8124eb2483eb610e3acad954b6bd0928dc8e&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486239&idx=1&sn=380795dcdf743047427f80d3f2c6b3e3&chksm=c21ba890f56c2186dca7d5839a5c07700a5351245ce1e7b9da0d5c4c3a01b6302fe1469a1aaa&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[黄金价格预测](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c21ba9dff56c20c92e3a08ee170b20dc411112fa12a8f89f55ae70450000e25614174a7a22bf&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect) [五穷六绝](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c21ba916f56c200088c4aceda6e62511469cff0d18af97fa48b659fc6ac3862d494f02fd38a6&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/041.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/042.png)