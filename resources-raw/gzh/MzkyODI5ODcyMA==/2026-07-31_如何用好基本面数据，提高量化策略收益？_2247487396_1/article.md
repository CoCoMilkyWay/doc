# 如何用好基本面数据，提高量化策略收益？

量化君 量化君也 2026-07-31 11:36 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487396&idx=1&sn=909e26342a0bd778b4fa573daa4a9c59&chksm=c3fe9800ea53928dd3a83bce8898048aa0fef33b7a0aac91f91ce7b1eefd8e69074728d528cc#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487396&idx=1&sn=909e26342a0bd778b4fa573daa4a9c59&chksm=c3fe9800ea53928dd3a83bce8898048aa0fef33b7a0aac91f91ce7b1eefd8e69074728d528cc#rd)

![](assets/001.png)

  

在量化交易当中，财务数据和行情数据有一个很大的区别，你今天去查某支个股的收盘价，和过几年再去查，这两个时间点的价格都是一致的。但是财务数据呢，某家企业去年的净利润是多少，今天查到的数值，却不一定等于三年后的数值。

  

下面举个栗子就明白了~

  

炒股年头儿长的小伙伴都应该听说过一个上市公司，叫獐Z岛，对，就是那个扇贝跑来跑去的公司。

  

这个公司呢，在2014、2015已经连续两年亏损，已经被实施退市风险警示，如果接着2016年再亏损，那就可以喜提毕业大礼包了，所以，2016年的经营结果对公司能否保壳十分关键。

  

2017年3月21日，獐Z岛披露了2016年度报告。按照年报当中显示，2016全年实现归母净利润7959w，终于扭亏为盈，保壳成功，胜天半子。

  

![](assets/002.png)

  

但是，不出意外的话，就要出意外了，2019年7月，证监会经过调查，最终认定獐Z岛存在虚增利润，涉案金额达到1.3个小目标。经过追溯调整以后，公司2016年的净利润和归母净利润都双双转负，倒亏5000w+。

  

![](assets/003.png)

  

更吊诡的是，明明这个公司的净利润数据已经修订过了，但在2026年的今天去查，还有好多行情软件上显示的是那个最初的造假金额。

  

TDX

![](assets/004.png)

  

DFCF

![](assets/005.png)

  

上面的例子想说的是，同一个报告期，同一家公司，同一个净利润科目，在不同的时间点，出现了两个完全相反的答案。

  

平常咱F10看财报数据，很多人都以为财报数据是静态的，发布出来后就不变了，其实不是的，财报数据是动态的，会随着日期发生改变的，除了那种造假被揪出来强制改正之外，日常上市公司也是会对之前的财报主动进行修订。

  

由于财报数据的动态性，稍不注意，你的基本面量化策略可能就在引入未来函数，今天回测2017年的基本面策略，查询到的是那调整后的亏损的5000w。

  

假设策略要求净利润必须为正，或者要求净利润同比保持一定增速，那么獐Z岛自然会被排除在候选股票池之外，策略在2017年就成功识别出了獐Z岛的经营问题，提前避开了后面财务暴雷的风险。

  

这样的回测结果看起来可能非常亮眼，但实际上经历了一次穿越时空的爱恋，2017年的策略不可能知道2019年的证监会的调查结果，更不可能提前使用2年后才出现的净利润调整结果，站在2017年，投资者能够看到的就是盈利7000w，而不是亏损5000w，这个财务造假的雷没有那么顺利避开。

  

要在量化中用好基本面数据，首先就要理解A股上市公司的财务报告是怎样披露的，通常情况下，一季报需要在当年4月底之前披露，半年报需要在当年8月底之前披露，三季报需要在当年10月底之前披露，年报则需要在次年4月底之前披露，所以每年4月你就可能前脚看到去年年报披露，后脚就看到今年一季报。

  

比较低级的错误就是，比如说，在2026年1月就调用2025年的年报数据，以为过完年就可以调数据了，这种就实在太低级了，但凡了解过交易所披露规则的都不会犯，就不在今天的讨论之列了。

  

用好财报数据，至少要了解3个时间概念，第一个是报告期，也就是财务数据描述的是哪个经营阶段。第二个是公告日期，也就是上市公司在什么时候把这份财务报告公开给市场看。第三个是修订日期，也就是公司在首次披露(公告日期)之后，什么时候对原来的数字进行了更正、追溯调整或者重新披露。

  

很多基础数据库只强调报告期，而量化回测真正关心的则是后两个时间，数据什么时候首次可见，以及后来发生的修订在什么时候开始可见。

  

咱以浓眉大眼的中X国际为例，“2024-12-31”是报告期，表示这份财务报告是年报，统计的是2024年1月1日至2024年12月31日的财务状况，“2025-02-12”是公告日期，表示它在这一天公开了自己2024年年报，修订标志为0，表示这是首次发布，“2025-03-28”是修订日期，别是它在这一天对自己的财报进行更正，将自己的净利润和归母净利润分别提高了1.93亿和2.19亿，修订标志为1，表示这是修订版本。

  

![](assets/006.png)

  

从这里就可以看出来，公告日期和修订日期是让量化回测不要出现未来函数的关键变量，也给提高基本面利用效率打下基础。

  

以往很多人做基本面策略研究，为了避免未来函数，财务数据的使用都非常保守。比如说，2026年4月中旬这个时点，有的上市公司已经发了2025年报和2026一季报，有的则发了2025年报，有的则还停留在2025年的三季报，大部分是业绩不好不敢见公婆，非要压点的，为了避免未来函数，则4月只能取去年三季报的数据，要到5月初才能统一取今年一季度的数据，以此类推，9月初以后才能统一使用半年报，11月初以后才能使用三季报。

  

这种用法虽然避免了未来函数，但从信息利用效率来看，过度保守同样会付出代价。假设一家公司在3月份的时候就发了去年年报，经营现金流、净利润和ROE都出现明显改善，而策略直到5月初才能使用这一part数据，那么财报公布后的2个月里，策略仍然把它当成一家只披露到去年三季报的公司，市场已经开始根据年报重新定价，策略却仍然停留在旧数据上。

  

反过来，一家公司3月份公布的财报如果明显恶化，继续使用旧数据也可能导致策略继续错误持有，原来的ROE、利润增速和现金流或许还符合标准，但新财报已经表明经营质量下降。如果策略必须等到统一时点才更新，基本面风险就无法及时进入选股程序。

  

所以啊，从信息利用率的角度出发，可以不要求所有股票在同一个交易日使用相同报告期，假设策略在4月中旬调仓，有些上市公司可能尚未发布年报，只能继续使用上一年三季报，有些公司已经发布年报，可以使用年度数据，还有极少数公司可能已经披露一季报，可以进一步使用一季报。

  

除非你是要做报告期横截面建模，不然不同上市公司使用不同报告期也不算是口径混乱，反而更加符合当时真实的信息环境，真正需要统一的并不是报告期，而是“所有数据在决策时都已经公开”这一条规则。

  

哦豁，废话太多了，总结一下，在量化入门期，想用好基本面数据，记住三个基础要点就够了。

  

（1）基本面数据不是F10里面看到的那种静态横截面，而是会不定时动态改变的。

  

（2）要记住和区分报告期、公告日期和修订日期这3个概念，不踩未来函数的坑和提高效率就都靠这哥仨。

  

（3）取数规则不用太保守，只要在决策时财报已公开就大胆用，不要求必须是统一报告期。

  

都说到这儿了，那就利用这些规则对上期的绩优红利策略进行改进一下，是骡子是马牵出来溜溜。

  

这个红利策略是作为小市值互补的防空洞策略，主打的是纯基本面选股，逻辑神经大条，中规中矩保持每年正向收益，类似于GARP(Growth at a Reasonable Price)策略，用合理的价格买成长型公司，只不过这些基本面只是用来做股票池筛选，最终还是在候选池子当中买股息率最高的前N支股票，具体构建过程请见上月的文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487368&idx=1&sn=fbb70718b65db76b9c7f6530b2033f3a&scene=21#wechat_redirect)[两个群的人都瞄上了这个策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487368&idx=1&sn=fbb70718b65db76b9c7f6530b2033f3a&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487368&idx=1&sn=fbb70718b65db76b9c7f6530b2033f3a&scene=21#wechat_redirect)。

  

现在来回顾一下策略绩效，作为改进对比的基准。

  

选股5支

![](assets/007.png)

  

![](assets/008.png)

  

选股10支

![](assets/009.png)

  

![](assets/010.png)

  

一般情况下，红利策略跟小市值策略是跷跷板效应，但这俩冤家之前都是被AI拿去当血包，被狂抽流动性，成难兄难弟了，最近AI拉胯，资金回流，红利跟小市值就开始分化了，目前是小市值苦一苦，红利板块开路虎。最近小市值策略也是遇到了2次行业冥灯，算是信号互相印证了。

  

在原始版的红利策略当中，用来过滤选股池的基本面因子用的是最保守的取数规则，也就是统一报告期，5月才能对一季报全部可见。

  

在改进版的策略中，就采用时效性更高的取数规则，不统一报告期，具体来说就是，在1月至4月，改进版会同时查询上一年三季报、上一年年报和当年一季报；在5月至8月，同时查询当年一季报和半年报；在9月至10月，同时查询半年报和三季报；11月至12月则查询三季报。

  

这样的财报候选范围覆盖了当前月份中可能提前披露的新财报，同时又保留了尚未披露新财报公司的上一期数据。然后根据公告日期和修订日期进行判断，如果昨日及之前可见，那么就取可见范围内的最新财报的最新数据，为了避免未来函数，默认所有财报公布后都只能是第二天可见。

  

来看一下改进版的策略绩效。

  

选股5支

![](assets/011.png)

  

![](assets/012.png)

  

选股10支

![](assets/013.png)

  

![](assets/014.png)

  

从中可以看出来，选股5支，改进版红利策略年化收益从25.30%提升到26.34%，夏普率从0.9103提升到0.9497，最大回撤从26.37%下降到26.04%。选股10支，改进版红利策略年化收益从20.45%提升到21.92%，夏普率从0.8019提升到0.8705，最大回撤从23.31%下降到23.18%

  

有一丢丢的提升作用，但效用不是特别明显，主要的原因是，该策略当中最核心的选股因子股息率，原本就是日级别更新的TTM数据，基本面取数规则的改进对它没有影响，影响的是用来进行股票池过滤的基本面因子，因此最大的效用就没有发挥出来，看来下次还是得找个更保守的基本面策略才行。

  

再来进行一个分年收益统计，依旧是中规中矩。

  

![](assets/015.png)

  

![](assets/016.png)

  

好了，这个绩优红利策略的改进说完了，如果之前有用原始版进行魔改/模拟/实盘的小伙伴，建议改用新版的，下面是参数设置的要点。

  

![](assets/017.png)

  

ACCOUNT\_ID：就是你自己的股票账户的资金账号，回测的时候可以不填或乱填，实盘的时候一定要填自己正确的账号。

  

ACCOUNT\_TYPE：因为要使用股票账户进行交易，所以该参数固定为“STOCK”。

  

ACCOUNT\_MODE：就是你打算用多少钱来跑这个策略，可选值为MONEY和RATIO。选MONEY就表示按照ACCOUNT\_MONEY设定的金额，选RATIO就表示使用总账户ACCOUNT\_RATIO那么多比例的资金。

  

ACCOUNT\_MONEY：策略金额，单位是“元”，根据自己的资金情况设置。

  

ACCOUNT\_RATIO：占总账户资金的比例，数值在0~1.0之间，0.3表示占30%比例。

  

STRATEGY\_TRADETIME：策略进行交易的时间，因为该策略是日线策略，一天那么长，所以需要指定一个具体的时间进行下单交易，必须是在交易时间段内。

  

ORDER\_TIMEOUT：订单超时时间，默认是60秒，下单后超过60秒没有全部成交就是超时，策略程序会自动检查出超时的委托单，然后撤单重下。

  

STRATEGY\_PATH：策略相关文件的存储路径，策略程序会在STRATEGY\_PATH这个路径底下再新建一个名为STRATEGY\_NAME的文件夹，策略相关的持仓文件和交易日志文件都会保存在这个文件夹底下，这些文件是做仓位隔离和信息回溯的关键。

  

STRATEGY\_NAME：策略名称，一旦开启实盘之后，策略名称不要随意修改，不然就无法识别策略持仓文件，如果在盘中修改然后重启策略的话，就识别不了修改之前下的委托单和成交单。特别说明就是，策略名称除了中文和英文之外，不要含有任何特殊字符，不然就无法正确识别券商柜台的委托回报。

  
SELECT\_NUM：每一次选择多少支符合条件的股票作为目标持仓，这里默认是5支。

  
PE\_HIGH：基本面估值筛选时，市盈率PE指标的上限。

  
PB\_HIGH：基本面估值筛选时，市净率PB指标的上限。

  
PEG\_HIGH：基本面估值筛选时，市盈增长比率PEG指标的上限。

  
ROE\_LOW：基本面盈利筛选时，净资产收益率‌ROE指标的下限。

  
PROFIT\_YOY\_LOW：基本面成长筛选时，净利润增长率‌的下限。

  
MONTH\_DAY：每个月的第几个交易日进行交易，默认是第1个交易日。

  
TOKEN：因为这里用到Tushare数据源，所以这里要填入自己Tushare的token，关于如何在QMT当中安装tushare，详见文章[《QMT自带的基本面数据这么拉胯，量化大神是怎么用它来实盘的》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)。

  

本次绩优红利策略改进版的回测/实盘源代码，已经分享在『量化达摩院』社群当中，群友请原路径自取，还不会使用QMT进行策略回测和实盘的小伙伴，请参照社群知识库第二章的第3和第4部分进行操作。

  

![](assets/018.jpg)

  

根据之前的规则约定，带V1字样的是回测版，仅支持回测，主要是代码少，方便看策略逻辑，带V2字样的是回测实盘一体版，同时兼顾实盘和回测，方便对比回测实盘之间的差异，后缀py的是策略源码文件，rzrk是QMT当中的策略备份文件，在QMT中导入后，除了能看到源码外，还会带有策略回测时的各项参数，因此墙裂建议量化萌新通过rzrk导入的方式使用策略，会非常省心省力。

  
下期见~

  

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

![](assets/019.png)

![](assets/020.jpg)

风险提示：市场有风险，投资需谨慎。所有策略思路和策略源码仅供参考和学习，不构成投资建议，策略回测仅代表历史收益，不代表未来收益。