# 小市值策略除了日历效应外，能用动态择时降低回撤吗？

量化君 量化君也 2026-02-05 23:57 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487189&idx=1&sn=cb9f80a960aa1e4d4739f84fd76fc78c&chksm=c3b20660861217864dd5a843b2ef2e58fbe8388d692d3a7aefb586e867fdb48a3b1c4031be55#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487189&idx=1&sn=cb9f80a960aa1e4d4739f84fd76fc78c&chksm=c3b20660861217864dd5a843b2ef2e58fbe8388d692d3a7aefb586e867fdb48a3b1c4031be55#rd)

![](assets/001.png)

  

有小伙伴说，看了最近的小市值策略，为什么老有一四月份空仓过滤？

  

我说，这个日历效应有其内在的金融逻辑，而且能大幅降低回撤，有人需要这个可选功能。

  

他说，这样会不会太呆板了，有更灵活的吗？

  

我说，可以有，就看你信不信。

  

于是有了今天的内容~

  

众所周知，小市值策略收益高，但回撤大，动不动回撤30~40%+，持有体验不佳，大伙儿孜孜不倦寻找择时降低回撤的方法，一四月空仓算简单粗暴的一个，就是知道的人越来越多，部分人鸡贼抢跑，导致最近这个日历效应开始漂移，那今儿个就来介绍坊间使用比较多的另外一种方法——四大搅屎棍。

  

目前从公开的资料看，这个名字看上去很接地气的小市值择时方法，是由聚宽社区用户ID为『MarioC』的大神最先提出，其核心思想是：当银行、有色金属、钢铁和煤炭这四大“搅屎棍”行业任意中的一个行业市场宽度全场最高时，小市值类策略就应该马上开溜，立即空仓。

  

![](assets/002.png)

  

聚宽社区的神贴就跟新H社的报道一样，历来都是字儿越少，事情就越重大越神奇，该贴全文仅有100余字，并没有给出具体的分析和推理过程，那咱就先大胆接受这个结论，而后小心验证。

  

MarioC大神给出的样例策略可拆解为选股和择时两个部分，还是老规律，咱使用QMT平台，分别对这两个部分进行复现验证。

  

先来说选股部分。

  

这个选股策略是基于蒋老师之前的那个小市值策略进行改进优化的，原版的选股逻辑是“每日在中小综指当中选流通市值最小的5支股票”，详细策略原理和回测请见[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486987&idx=1&sn=0f579a3f60c04ceef86b2c2565002c9d&scene=21#wechat_redirect)[曾经年化100%，为什么如此简单的策略，能在圈子里火5年？](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486987&idx=1&sn=0f579a3f60c04ceef86b2c2565002c9d&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486987&idx=1&sn=0f579a3f60c04ceef86b2c2565002c9d&scene=21#wechat_redirect)，而这版相较于原版主要有5处改动。

  

（1）原版是日频选股，这版是周频。

  

（2）原版是没有新股过滤，这版是需要上市超过1年。

  

（3）原版是按照流通市值最小，这版是总市值最小。

  

（4）原版是选股5支，这版是选股10支。

  

（5）原版没有使用任何基本面指标对股票进行过滤，这版同时使用了净资产收益率ROE和总资产收益率ROA对股票进行过滤。

  

但这版在使用ROE和ROA对股票进行过滤时，感觉是出现了“笔误”，在聚宽当中，ROE和ROA的数值单位都是“百分比(%)”，那它俩分别大于0.15%和0.10%的金融意义就不是很明显。

  

如果你认为作者原来是想设成15%和10%的，修改成对应的设置后，你就会发现会有非常多的时间段入选股数为0，根本就没有能满足条件的股票，所以为了尊重原策略和偷懒，在复现时直接让每股收益EPS大于0就行了。

  

![](assets/003.png)

  

![](assets/004.png)

  

为了验证逻辑和后续魔改，我使用QMT结合Tushare复现了这个新版的小市值优化策略，为了尽力避免未来函数的可能，在回测设定中，今日选股，市值、每股收益等因子数据只用昨日的，并且在历史时点剔除涨跌停股票和ST股票等奇奇怪怪的股票，比方说根据当时股票的名称判断是否是ST股，而不是根据现在的股票名称，这样就能尽力避免幸存者偏差，复现策略的回测绩效如下。

  

![](assets/005.png)

  

![](assets/006.png)

  

该选股策略的年化收益为55.54%，夏普率为1.82，最大回撤为33.64%，收益回撤比为1.65，看上去是一个不错的基础型策略，目前就是回撤还很大。

  

接着就来说今天的重头戏择时部分，看能否有效降低这个选股策略的最大回撤。

  

先来说行业，这里的行业是指申万一级行业分类，目前有31个行业，分别是：农林牧渔、基础化工、钢铁、有色金属、电子、汽车、家用电器、食品饮料、纺织服饰、轻工制造、医药生物、公用事业、交通运输、房地产、美容护理、社会服务、银行、非银金融、综合、建筑材料、建筑装饰、电力设备、机械设备、国防军工、计算机、传媒、通信、煤炭、石油石化、环保、商贸零售。

  

择时的逻辑就是，在调仓日，根据昨天和之前的数据，分别计算这31个行业的市场宽度，如果行业市场宽度最高的行业是银行、有色金属、钢铁和煤炭中的任意一个，那就不开仓，立马空仓。

  

那行业市场宽度如何计算呢？

  

行业市场宽度（以下简称“行业宽度”）的计算逻辑很简单，就是每个行业当中站上20日均线的股票数目在行业股票总数中的占比，就是该行业当中有多少比例的股票站上了MA20，行业宽度数值越大，说明行业的走势越好。

  

在赌场当中，如果有的人手气很差，老是输钱，那么就会有人就反着他的方向下注，他压大你压小，他买庄你买闲，把这个倒霉蛋当作指路明灯，俗称“灯”。所以也有人管这种根据行业进行反向择时的方法，也称之为“行业冥灯”，刚才说的那四个行业就是冥灯行业，见了就要赶紧跑。

  

那出现搅屎棍/冥灯行业时，立马跑路的效果是怎么样的呢，请见以下回测。

  

![](assets/007.png)

  

![](assets/008.png)

  

相较于刚才永远满仓的选股策略而言，最大回撤从33.64%降到了20.78%，但年化收益也从55.54%降到了41.16%，最大回撤的降幅是12.86%，收益的降幅是14.38%，收益的降幅比回撤的要大。

  

好的方面是，夏普率基本持平，收益回撤比从1.65提高到了将近2.0，持有体验会好一些，这种动态择时的方法的确有助于降低小市值策略的最大回撤，但付出的代价是收益也会受到损失，自己需要根据自身的风险偏好情况进行权衡。

  

此时有的小伙伴可能要说了，小孩子才做选择，成年人是都要，如果固定的日历效应择时和动态的行业冥灯择时都用上的话，小市值策略会是什么样子的呢？话不多说，请往下看~

  

![](assets/009.png)

  

![](assets/010.png)

  

相较于之前的两个回测，年化收益和最大回撤都进一步下降了，好的方面是，夏普率提高到了1.92，收益回撤比也提高到了2.08，持有体验舒适度又向前迈了一小步。

  

好了，策略与择时的逻辑都验证完了，下面是给想要进行魔改的小伙伴说一下实盘参数的设置要点。

  

![](assets/011.png)

  

ACCOUNT\_ID：就是你自己的股票账户的资金账号，回测的时候可以不填或乱填，实盘的时候一定要填自己正确的账号。

  

ACCOUNT\_TYPE：因为要使用股票账户进行交易，所以该参数固定为“STOCK”。

  

ACCOUNT\_MODE：就是你打算用多少钱来跑这个策略，可选值为MONEY和RATIO。选MONEY就表示按照ACCOUNT\_MONEY设定的金额，选RATIO就表示使用总账户ACCOUNT\_RATIO那么多比例的资金。

  

ACCOUNT\_MONEY：策略金额，单位是“元”，根据自己的资金情况设置。

  

ACCOUNT\_RATIO：占总账户资金的比例，数值在0~1.0之间，0.3表示占30%比例。

  

STRATEGY\_TRADETIME：策略进行交易的时间，因为该策略是日线策略，一天那么长，所以需要指定一个具体的时间进行下单交易。

  

ORDER\_TIMEOUT：订单超时时间，默认是60秒，下单后超过60秒没有全部成交就是超时，策略程序会自动检查出超时的委托单，然后撤单重下。

  

STRATEGY\_PATH：策略相关文件的存储路径，策略程序会在STRATEGY\_PATH这个路径底下再新建一个名为STRATEGY\_NAME的文件夹，策略相关的持仓文件和交易日志文件都会保存在这个文件夹底下，这些文件是做仓位隔离和信息回溯的关键。

  

STRATEGY\_NAME：策略名称，一旦开启实盘之后，策略名称不要随意修改，不然就无法识别策略持仓文件，如果在盘中修改然后重启策略的话，就识别不了修改之前下的委托单和成交单。特别说明就是，策略名称除了中文和英文之外，不要含有任何特殊字符，不然就无法正确识别券商柜台的委托回报。

  
INDEX\_CODE：指数代码，表示用哪个指数的成分股作为股票池，这里默认用的是中小综指(399101.SZ)。

  

SELECT\_NUM：每一次选择多少支符合条件的股票作为目标持仓，这里默认是10支。

  

WEEK\_DAY：每周第几个交易日进行调仓交易，默认值是1，表示一般是每周一进行交易，遇到节假日则顺延。  

  
JINX\_INDU\_LIST：行业冥灯列表，空列表表示不过滤。默认是：银行，有色金属，钢铁，煤炭。  

  

FILTER\_MONTH\_LIST：过滤月份的数值列表，\[1,4\]表示一月份和四月份空仓不交易，空列表则表示不对月份进行过滤。

  
TOKEN：因为这里用到Tushare数据源，所以这里要填入自己Tushare的token，关于如何在QMT当中安装tushare，详见文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[QMT自带的基本面数据这么拉胯，量化大神是怎么用它来实盘的](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)。

  

本次“小市值优化策略行业冥灯版”的回测/实盘源代码，已经分享在『量化达摩院』社群当中，群友请原路径自取，还不会使用QMT进行策略回测和实盘的小伙伴，请参照社群知识库第二章的第3和第4部分进行操作。

  

![](assets/012.png)

  

根据之前的规则约定，带V1字样的是回测版，仅支持回测，主要是代码少，方便看策略逻辑，带V2字样的是回测实盘一体版，同时兼顾实盘和回测，方便对比回测实盘之间的差异，后缀py的是策略源码文件，rzrk是QMT当中的策略备份文件，在QMT中导入后，除了能看到源码外，还会带有策略回测时的各项参数，因此墙裂建议量化萌新通过rzrk导入的方式使用策略，会非常省心省力。

  
我是量化君，下期见~

* * *

★

往期回顾

  

★

  

\------量化社群------

  

[量化达摩院](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487092&idx=1&sn=25bac190345f2018e6422fe80f60df7f&scene=21#wechat_redirect)

[量化藏经阁Max](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487087&idx=1&sn=b09a75914ffa58c219ec7a2d833652c0&scene=21#wechat_redirect)

[量化藏经阁2026](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487099&idx=1&sn=f459e43d14a1a11a8e0811c7f9315794&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect)[TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect)[北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect)[F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect)[鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect)[波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect)[RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect)[GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零代码策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[黄金价格预测](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c21ba9dff56c20c92e3a08ee170b20dc411112fa12a8f89f55ae70450000e25614174a7a22bf&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

[十年零回撤](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485946&idx=1&sn=0247059aebc4e851e330dcfef8a71e06&scene=21#wechat_redirect) [红利策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486120&idx=1&sn=b3810b54ef12d899cd8cacdf3f7ea594&scene=21#wechat_redirect)  [数字信号](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486368&idx=1&sn=9a8e7b22717192a59072ef40c5b1ea43&scene=21#wechat_redirect)

\------心得杂谈------

[入门路径](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486125&idx=1&sn=7363ab72138ab4c76e167507c6e66fe7&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)

[打开黑箱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化手册](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486076&idx=1&sn=7265e59cd5b9a9716a83b1a4cfb416b4&scene=21#wechat_redirect)  [量化攻略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486384&idx=1&sn=a1d00fcf058755df0f2b51cda5a2ab5a&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[西蒙斯](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)  [雪球爆仓](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485815&idx=1&sn=6378f7c65c16da331af9598b08d53679&scene=21#wechat_redirect)  [量化交易邪术](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486330&idx=1&sn=10e5309bc821819950e43bf7df0cac21&scene=21#wechat_redirect) 

[量化网站1](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485841&idx=1&sn=e94800a827ce4f38c833dcd144ea1806&scene=21#wechat_redirect)  [量化网站2](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485869&idx=1&sn=951f15090c856e7fcda3b660dccc6b8f&scene=21#wechat_redirect)  [量化狠人](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485924&idx=1&sn=9447f05fbba78524455878c999adabd1&scene=21#wechat_redirect)

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485751&idx=1&sn=c97da5635ce842634d1c2f68397f21c1&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486429&idx=1&sn=5f2101cfde264f0370b99b4f8b8e7ada&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect) [五穷六绝](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c21ba916f56c200088c4aceda6e62511469cff0d18af97fa48b659fc6ac3862d494f02fd38a6&scene=21#wechat_redirect) [一月之殇](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485826&idx=1&sn=cfeb2dd29ef21c48ab2e96b568b42559&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/013.png)

![](assets/014.jpg)

风险提示：市场有风险，投资需谨慎。所有策略思路和策略源码仅供参考和学习，不构成投资建议，策略回测仅代表历史收益，不代表未来收益。