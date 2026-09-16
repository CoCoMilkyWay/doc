# 五穷六绝七翻身？量化分析揭开背后真相（附源码）

量化君 量化君也 2023-07-02 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c394ba662097e81f6fb23dcc44dcaef8d8f8a16abb3a7cb1e4d2b05abe70c62eb2de0f9dec30#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c394ba662097e81f6fb23dcc44dcaef8d8f8a16abb3a7cb1e4d2b05abe70c62eb2de0f9dec30#rd)

![](assets/001.png)

  

六月悄悄然过去，留下鲜绿色的回忆，即将迎来七月的第一个交易日，不用想不用猜，各个投资群里，肯定不少人说着同一句朗朗上口的股市谚语，相互取暖，相互打气。

  

**这句谚语就是『五穷六绝七翻身』，不能说大伙儿都耳熟能详吧，肯定都略有耳闻。**从字面上的意思就能看出来，说的是股市每逢每年的五月和六月都会出现下跌，到了七月，下跌趋势终止，开始回升走出低谷，打一个漂亮的翻身仗。

  

![](assets/002.png)

  

目前主流的观点认为，这种说法最早起源于香港股市，在上世纪80年代至90年代的时候港岛特别流行，据说是当时的经济研究员，在参考过历年香港股市的涨跌情况后，统计总结得出的结论。

  

类似的说法，不单单中国股市有，国外股市也存在，**最著名的莫过于美国华尔街流传已久的“Sell in May”（在五月份卖出），但最早的出处却是在英国。完整的句子应该是“Sell in May and go away, come back at St.Leger's Day”**，St.Leger's Day指的就是英国每年九月份在南约克郡举行的秋季赛马比赛。所以整句话翻译过来就是说，在五月份的时候大伙儿都卖出清仓离开吧，等到秋季赛马比赛后再回来。

  

![](assets/003.png)

  

为啥要在五月份离开呢？因为夏天到了太热了，离开伦敦去避暑，就跟清朝皇帝一到夏天就跑到承德避暑山庄消夏一样，等到秋天转凉了再屁颠屁颠跑回来。所以嘛，那群英国贵族、银行家和投资家都跑出去避暑了，清仓不玩了，那时候还没现在远程炒股的便利，股市可不就寡淡没有行情嘛，等到他们九月末回来之后，行情才会有起色。后来这句话被投资者们念叨着跨过大西洋，带到了北美大陆，成为了如今华尔街金融人士口口相传的一句谚语。

  

同样都是五月卖出/下跌，一个来自于香港，一个来自于英美，那跟咱的大A行情规律吻合吗？今年大盘五月份跌了3.57%，六月份跌了0.08%，真的是又穷又绝，接下来的一个月咱能翻身不？

  

![](assets/004.png)

  

要看中国股市符不符合“五穷六绝七翻身”这个规律，靠瞎说可不行，要有数据统计结果，邓爷爷教育道“实践是检验真理的唯一标准”，咱就撸起袖子开干。

  

要总结规律，那数据时间范围当然越长越好，挑来挑去，**觉得还是先选择『上证指数』较为合适，它在1991年就发布了（沪深300指数还要14年后才发布），基本跟上交所深交所同龄，数据长度够长，基本全覆盖了A股发展历程**，更何况股民日常说的3000点、3200点什么的，指的就是上证指数的点位。

  

首先咱就来获取上证指数的历史行情数据，这里使用的是股票量化开源库qstock，直接使用“pip install qstock”就可以安装，基本的功能无需注册便可以使用，对萌新来说非常方便，详情请见：https://github.com/tkfy920/qstock

  

```
import numpy as np
```

  

![](assets/005.png)

  

在这里咱就获取了上证指数从1991年6月至2023年6月的全部月度行情数据，结合当月的收盘价和上个月的收盘价(close)就可以计算出当月的涨跌幅(pct)，为了方便后续统计，咱还需要将日期索引(date，对应的是每个月最后的交易日)转换为对应的月份数值(month)。

  

```
# 计算月度涨跌幅
```

  

![](assets/006.png)

  

**至此，咱就获取到了1991年7月至2023年6月这32年之间每个月的涨跌幅数据，这样的日期范围设置的原因是，平衡每个月份数的分布，保证每个月都出现的次数相同，都是32次。**

  

数据整理完毕后，就可以开始统计了，在这里咱要统计的是每个月的上涨次数(win\_num)、下跌次数(lose\_num)、胜率(win\_rate)、涨跌幅的均值(pct\_avg)、涨跌幅的中位数(pct\_med)、涨跌幅的最小值(pct\_min)和涨跌幅的最大值(pct\_max)。

  

实现的原理是，按月份数值(month)进行循环，分月份进行统计，那每一个月份就有32个涨跌幅(pct)数值，若涨跌幅为正数记为上涨，负数记为下跌，胜率(单位百分比)则为“100\*上涨次数/32”，其余的4个指标就分别对应着这32个涨跌幅数值序列当中的均值、中位数、最小值和最大值，具体细节请看下方代码。

  

```
stats = pd.DataFrame(np.nan, index=sorted(data['month'].unique().tolist()),
```

  

![](assets/007.png)

  

现在统计结果就一目了然了，五月份和六月份的胜率都是五五开，32年里面涨跌都是各有16次，而七月份上涨次数只有15次，再看涨跌幅均值，这3个月份的涨跌幅均值分别为5.31%、-0.27%和-0.96%，而且七月份的涨跌幅均值是一年12个月里面最差的，涨跌幅中位数也是。

  

**因此结果显而易见，无论从胜率，还是涨跌幅均值/中位数，七月份都要比五月份和六月份的差，如果还要坚持说五六月份还是“五穷六绝”的话，那整句话就该改为“五穷六绝七地狱”，地狱还可能是十八层的那种。**

  

为了降低选择代表性指数时的片面性，咱把市场上主流的那几个指数都逐个统计一遍，只要把第一段代码中的变量symbol再分别逐次修改为深证成指、上证50、沪深300、中证500、中证1000、创业板指和中证全指，时间范围也做对应的调整，挨个重新run一遍，就可以统计出相应指数的月份涨跌幅数据，每次的统计结果都会保存为以指数名称为文件名后缀的Excel文件，汇总这些统计文件，就可以看到所有指数的全貌，统计结果如下所示，点击图片可放大查看。

  

_主流指数所有月份胜率数据表：_

![](assets/008.png)

  

_主流指数所有月份涨跌幅均值数据表：_

![](assets/009.png)

  

从胜率表当中看出，五六七月份的总体胜率均值分别是54.2%、54.81%和49.55%，七月份并没有好于五六月份；五六七月份的总体涨跌幅均值分别是2.12%、-0.81%和1.13%，虽然七月份翻身了一丢丢，但也没有体现出“五穷”的赶脚。

  

**综上所述，至少在主流指数概况当中，“五穷六绝七翻身”这种说法并不成立，根本站不住脚，今年的七月翻身仗，翻不翻得了基本是五五开，但从总体涨跌幅均值来看，还是“优势在我”。**

  

![](assets/010.jpg)

  

论证已经完毕了，但是在过程当中还有两个有趣的发现，也可以顺便说一下，眼尖的小伙伴可能已经发现了。

  

**第一个就是存在着“五穷六绝七翻身”的指数，它就是上证50指数**，它五六七月份的胜率分别是45%、40%和52.63%，涨跌幅均值是-0.92%、-1.60和1.19%，这样一看，是不是完美契合这句谚语了。

  

其实吧，只要你把各种市场指数、行业指数、风格指数、概念指数和板块指数统统都统计一遍，肯定能找出不少符合这种规律的指数，只不过占比不高，并不是主流，只要林子足够大，什么鸟儿都会有。

  

**第二个发现其实我已经在上面的表格当中标注出来了，那就是在所有月份当中，二月份的胜率和涨跌幅均值出奇的高**，如果还没有感觉的话，咱把它转化为柱状图展示就直观了。

  

![](assets/011.png)

  

![](assets/012.png)

  

特别是看二月份的涨跌幅均值，简直就是谷子地里窜高粱——硬生生高出一大截来，并且没有一个指数的二月份涨跌幅均值出现负数，二月份的胜率均值接近75%，也是没有一个指数的二月份胜率是低于60%的。

  

**如果拿枪指着我的脑袋，让我硬是选一个月份翻身，我会毫不犹豫选择二月份，谁会跟概率过不去嘛。**

  

**其实上面的这些统计研究，在量化交易或金融工程里面有一个确切的术语，叫做『日历效应』，也就是研究那些与日期存在关联的非正常收益和非正常波动的数据特征现象。**

  

如果大伙儿对我国股市的日历效应感兴趣，特别是想了解清楚本次统计中二月份的胜率和收益为什么这么高，背后的金融逻辑是什么，**推荐大家去看国海金工今年新出的深度金工研报《日历效应背后的择时策略探究》，在里面作者列举和解释了A股中各种各样与日期节假日相关的Alpha场景，并利用其中的原理构建指数择时和行业轮动策略。**

  

![](assets/013.png)

  

![](assets/014.png)

  

这次就先唠到这儿，噢~对了，差点忘记说，找研报不方便的小伙伴，**可在本公众号『量化君也』后台回复暗号『日历效应』**，就可以直接保存和下载上面那篇研报，如果对你有帮助的话，可以点个充满鼓励的『赞』告诉我，让我动力满满继续肝~

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485155&idx=1&sn=2c3159534dc114e97eaad77959dfe558&chksm=c21ba56cf56c2c7a6082a275be18cbb41ffdc173bfdd2b3459de6df13161c6ea419a4818056e&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485157&idx=1&sn=6b7f381f57b651b4df8e7b384e43400f&chksm=c21ba56af56c2c7cb15a3c7d66d6df27c41f714ad00a8f681fa8697be51b692dd48df9a69511&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/015.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/016.png)