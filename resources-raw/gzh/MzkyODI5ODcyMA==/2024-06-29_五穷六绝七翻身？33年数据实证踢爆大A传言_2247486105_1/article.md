# 五穷六绝七翻身？33年数据实证踢爆大A传言

量化君 量化君也 2024-06-29 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c39b10efe5f229f936406ef145fd636da47d6fe9aac31ca12722ae900e234f5acd3b972aa31f#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c39b10efe5f229f936406ef145fd636da47d6fe9aac31ca12722ae900e234f5acd3b972aa31f#rd)

![](assets/001.png)

  

2024年悄然过去一半，回顾行情，大盘五月下跌0.58%，六月跌幅扩大至3.87%，已有五穷六绝之相，七月又当如何？不用想不用猜，各个投资群里，肯定不少人说着同一句朗朗上口的股市谚语，相互取暖，相互打气。

  

**这句谚语就是『五穷六绝七翻身』，不能说大伙儿都耳熟能详吧，肯定都略有耳闻。**从字面上的意思就能看出来，说的是股市每逢每年的五月和六月都会出现下跌，到了七月，下跌趋势终止，开始回升走出低谷，打一个漂亮的翻身仗。

  

![](assets/002.png)

  

真的是这样吗？看回2023年行情，大盘五月下跌3.57%，六月下跌0.08%，七月上涨2.78%，果然应了五穷六绝七翻身之语。再看多一年，2022年，大盘五月大涨4.57%，六月接着大涨6.66%，七月下跌4.28%，恰好跟五穷六绝七翻身是反着来的。

  

那实际到底是什么样子，请容我刨根问底，细细道来~  

  

  

目前主流的观点认为，『五穷六绝七翻身』这种说法最早起源于香港股市，在上世纪80年代至90年代的时候港岛特别流行，据说是当时的经济研究员，在参考过历年香港股市的涨跌情况后，统计总结得出的结论。

  

类似的说法，不单单中国股市有，国外股市也存在，**最著名的莫过于美国华尔街流传已久的“Sell in May”（在五月份卖出），但最早的出处却是在英国。完整的句子应该是“Sell in May and go away, come back at St.Leger's Day”**，St.Leger's Day指的就是英国每年九月份在南约克郡举行的秋季赛马比赛。所以整句话翻译过来就是说，在五月份的时候大伙儿都卖出清仓离开吧，等到秋季赛马比赛后再回来。

  

![](assets/003.png)

  

  

为啥要在五月份离开呢？因为夏天到了太TM热了，要离开伦敦市区去郊外避暑，就跟清朝皇帝一到夏天就跑到承德避暑山庄消夏一样，等到秋天转凉了再屁颠屁颠跑回来。所以嘛，那群英国贵族、银行家和投资家都跑出去避暑了，清仓不玩了，那时候还没现在远程炒股的便利，股市可不就寡淡没有行情嘛，等到他们九月末回来之后，行情才会有起色。后来这句话被投资者们念叨着跨过大西洋，带到了北美大陆，成为了如今华尔街金融人士口口相传的一句谚语。

  

同样都是五月卖出/下跌，一个来自于香港，一个来自于欧美，那跟咱的大A行情规律吻合吗？今年五月已经跌了0.58%，六月份接力跌了3.87%，真的是又穷又绝，接下来的七月咱能翻身不？

  

![](assets/004.png)

  

  

要看咱大A股符不符合“五穷六绝七翻身”这个规律，靠瞎说可不行，要有数据统计结果，邓爷爷教育道“实践是检验真理的唯一标准”，咱就撸起袖子开干。

  

要总结规律，那数据时间范围当然越长越好，挑来挑去，**觉得还是先选择『上证指数』较为合适，它在1991年就发布了（沪深300指数还要14年后才发布），基本跟上交所深交所同龄，数据长度够长，基本全覆盖了A股发展历程**，更何况股民日常说的3000点、3200点什么的，指的就是上证指数的点位。

  

首先咱就来获取上证指数的历史行情数据，这里使用的是股票量化开源库qstock，直接使用“pip install qstock”就可以安装，基本的功能无需注册便可以使用，对萌新来说非常方便，详情请见：https://github.com/tkfy920/qstock

  

```
import numpy as np
```

  

![](assets/005.png)

  

在这里咱就获取了上证指数从1991年6月至2024年6月的全部月度行情数据，结合当月的收盘价和上个月的收盘价(close)就可以计算出当月的涨跌幅(pct)，为了方便后续统计，咱还需要将日期索引(date，对应的是每个月最后的交易日)转换为对应的月份数值(month)。

  

```
# 计算月度涨跌幅
```

  

![](assets/006.png)

  

  

**至此，咱就获取到了1991年7月至2024年6月这33年之间每个月的涨跌幅数据，这样的日期范围设置的原因是，平衡每个月份数的分布，保证每个月都出现的次数相同，都是33次。**

  

数据整理完毕后，就可以开始统计了，在这里咱要统计的是每个月的上涨次数(win\_num)、下跌次数(lose\_num)、胜率(win\_rate)、涨跌幅的均值(pct\_avg)、涨跌幅的中位数(pct\_med)、涨跌幅的最小值(pct\_min)和涨跌幅的最大值(pct\_max)。

  

实现的原理是，按月份数值(month)进行循环，分月份进行统计，那每一个月份就有33个涨跌幅(pct)数值，若涨跌幅为正数记为上涨，负数记为下跌，胜率(单位百分比)则为“100\*上涨次数/33”，其余的4个指标就分别对应着这33个涨跌幅数值序列当中的均值、中位数、最小值和最大值，具体细节请看下方代码。

  

```
stats = pd.DataFrame(np.nan, index=sorted(data['month'].unique().tolist()),
```

  

![](assets/007.png)

  

  

现在统计结果就一目了然了，五六七月份的胜率都是一样的，基本是五五开(48.48%)，33年时间里都是上涨16次，下跌17次，再看涨跌幅均值，这3个月份的涨跌幅均值分别为5.13%、-0.38%和-0.85%，而且七月份的涨跌幅均值是一年12个月里面最差的，涨跌幅中位数是第二差。

  

**因此结果显而易见，七月份在胜率方面没有优势，并且涨跌幅均值/中位数，七月份都要比五月份和六月份的差，如果还要坚持说五六月份还是“五穷六绝”的话，那整句话就该改为“五穷六绝七地狱”，地狱还可能是十八层的那种。**

  

为了降低选择代表性指数时的片面性，咱把市场上主流的那几个指数都逐个统计一遍，只要把第一段代码中的变量symbol再分别逐次修改为深证成指、上证50、沪深300、中证500、中证1000、创业板指和中证全指，时间范围也做对应的调整，挨个重新run一遍，就可以统计出相应指数的月份涨跌幅数据，每次的统计结果都会保存为以指数名称为文件名后缀的Excel文件，汇总这些统计文件，就可以看到所有指数的全貌，统计结果如下所示，点击图片可放大查看。

  

_主流指数所有月份胜率数据表：_

![](assets/008.png)

  

_主流指数所有月份涨跌幅均值数据表：_

![](assets/009.png)

  

  

从胜率表当中看出，五六七月份的总体胜率均值分别是51.36%、51.93%和51.61%，七月份并没有显著优势；五六七月份的总体涨跌幅均值分别是1.93%、-1.09%和1.19%，虽然七月份翻身了一丢丢，但也没有体现出“五穷”的感觉。

  

**综上所述，至少在主流指数概况当中，“五穷六绝七翻身”这种说法并不成立，根本站不住脚，今年的七月翻身仗，翻不翻得了基本是五五开，但从总体涨跌幅均值来看，还是“优势在我”。**

  

![](assets/010.jpg)

  

  

论证已经完毕了，但是在过程当中还有两个有趣的发现，也可以顺便说一下，眼尖的小伙伴可能已经发现了。

  

**第一个就是存在着“五穷六绝七翻身”的指数，它就是上证50指数**，它五六七月份的胜率分别是42.86%、38.1%和55.0%，涨跌幅均值是-0.88%、-1.65%和1.45%，这样一看，是不是完美契合这句谚语了。

  

其实吧，只要你把各种市场指数、行业指数、风格指数、概念指数和板块指数统统都统计一遍，肯定能找出不少符合这种规律的指数，只不过占比不高，并不是主流，只要林子足够大，什么鸟儿都会有。

  

**第二个发现其实我已经在上面的表格当中标注出来了，那就是在所有月份当中，二月份的胜率和涨跌幅均值出奇的高**，如果还没有感觉的话，咱把它转化为柱状图展示就直观了。

  

![](assets/011.png)

  

![](assets/012.png)

  

  

特别是看二月份的涨跌幅均值，简直就是谷子地里窜高粱——硬生生高出一大截来，并且没有任何一个指数的二月份涨跌幅均值出现负数，二月份的胜率均值为76%，也是没有任何一个指数的二月份胜率低于60%。

  

**如果拿枪指着我的脑袋，让我硬是选一个月份翻身，我会毫不犹豫选择二月份，谁会跟概率过不去嘛。**

  

**其实上面的这些统计研究，在量化交易或金融工程里面有一个确切的术语，叫做『日历效应』，也就是研究那些与日期存在关联的非正常收益和非正常波动的数据特征现象。**

  

如果大伙儿对我国股市的日历效应感兴趣，特别是想了解清楚本次统计中二月份的胜率和收益为什么这么高，背后的金融逻辑是什么，**推荐大家去看国海金工去年出的深度金工研报《日历效应背后的择时策略探究》，在里面作者列举和解释了A股中各种各样与日期节假日相关的Alpha场景，并利用其中的原理构建指数择时和行业轮动策略。**

  

![](assets/013.png)

  

这次就先唠到这儿，噢~对了，差点忘记说，找研报不方便的小伙伴，**可在本公众号『量化君也』后台回复暗号『日历效应』**，就可以直接保存和下载那篇日历效应的研报，如果对你有帮助的话，可以点个充满鼓励的『赞』告诉我，让我动力满满继续肝~

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486038&idx=1&sn=29f610e83c0939e2108348afeecef8af&chksm=c21ba9d9f56c20cffe19a582ae5674b9fa86d8c8659061482a699421e3672376735668763c4c&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486041&idx=1&sn=cf9709ae26edbd8e7fbc52dbb571293b&chksm=c21ba9d6f56c20c0fe3a0b83cd64b6c787ad37ed76d8ee909dc73d9d36f6bce49f215604e25b&scene=21#wechat_redirect)

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

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/014.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/015.png)