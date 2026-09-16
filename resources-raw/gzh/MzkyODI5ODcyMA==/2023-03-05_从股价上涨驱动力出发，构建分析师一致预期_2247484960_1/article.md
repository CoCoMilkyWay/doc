# 从股价上涨驱动力出发，构建分析师一致预期成长策略

量化君 量化君也 2023-03-05 22:11 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c33db42aaef7bd12a7ce493fc130db0ba643bf1eceeb0f675db4e4322b0a4e385e00dd9f8b46#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c33db42aaef7bd12a7ce493fc130db0ba643bf1eceeb0f675db4e4322b0a4e385e00dd9f8b46#rd)

![](assets/001.png)

  

股票投资的收益，除了获得分红之外，更多的时候来自于买卖的价差，股价上涨，低买高卖，最终收益就是扣除手续费后的价差收益。

  

那股价为什么会变动，为什么会上涨呢？

  

坊间有很多流派，用来解释股价的成因，例如金融书上经常讲的股利贴现模型（Dividend Discount Model，DDM），把股票内在价值表达为未来股利的折现值之和，这个在实际当中很少使用，对普通投资者而言，一般更为常见的股价公式是：

  

**股价(Price) = 市盈率(PE) x 每股收益(EPS)**

  

虽然这个公式只是把市盈率计算公式的分母挪了一下，但用来解释股价变动的驱动力却是非常有用。

  

从这个式子里面看出，想要股价上涨，想要投资获利，那有两个途径，要么让每股收益提高，要么让市盈率增大。

  

**第一条途径，每股收益的提高，对应的就是企业业绩的增长。**假设股本没有大幅变动，企业明年赚取的净利润大幅增加，那每一股平摊到的净利润也就增多了，每股收益就提高了，市盈率不变的情况下，公司的股价就会上涨，这里赚的就是企业业绩增长的钱。这就是巴菲特老爷子常说的，买股票就是买公司，就是这个道理。

  

**第二条途径，市盈率的增大，对应的就是估值的提升。**什么是估值呢？简单来说就是，投资者认为股票值多少钱的看法，市盈率就是股民最为常用的相对估值指标。如果股票对应的每股收益是1块钱的话，给20倍估值，那股价就是20元，给30倍估值的话，那股价就是30元。

  

如果每股收益1元不变，你20倍市盈率买回来的股票，涨到30倍市盈率卖出了，每股就赚了10块钱价差，这里赚的就是估值提高的钱。

  

那为什么每股收益不变，公司业绩不变，一下子给20倍估值，又一下子又给30倍估值呢？

  

**个人觉得主要受宏观预期和个股预期两个因素的影响。**

  

假设前一个交易日风平浪静，今天发生了以下宏观事件：

  

_大毛打二毛了，两个国家爆发战争，全球股市狂泻下跌；_

_漂亮国储官员发表鸽派讲话了，要放水了，全球股市狂喜上涨；_

_漂亮国CPI爆表控制不住了，预期加息停不下来，全球股市低开；_

_国家政策发文，大水漫灌基建，相关产业链个股鸡犬升天。_

  

**宏观层面的因素主要是影响整个大市、影响大部分股票或对应的大类行业，进而影响到投资者对个股的整体预期，时而高估，时而低估。**

  

**个股预期，主要还是对企业业绩的未来预期**，银行股每年都真金白银实打实的分红，只有5倍市盈率，科技企业目前还在盈亏平衡上挣扎，却有50倍市盈率，它们之间的区别就是投资者对未来业绩的预期不同，银行太稳定了，业绩成长性不高，估值低，科技企业预计未来业绩增长快，有想象空间，就会给更高的估值。

  

很多消息面和事件驱动策略，也是作用在企业业绩预期上，导致股价波动，比如说：

  

_果链个股接到苹果加单了，导致未来业绩预期增长，给予更高估值，今天基本面还跟昨天一样呢，但股价也升高了；_

_公司实控人被抓了，配合调查，肯定会对企业运营产生不利影响，投资者看衰，降低估值，股价先跌为敬。_

_企业砸重金开发一款产品，从临床试验来看，效果不乐观，公司业绩稳定性风险加大，导致估值降低，股价下跌。_

  

说完了股价上涨的驱动力和影响因素，明白了要赚钱，要么每股收益提高，要么市盈率(估值)提高。**如果你买的股票两个都一起提高的话，那恭喜你了，你遇到传说中的“戴维斯双击”，享受到了市盈率提升和公司业绩增长的倍乘效益。**戴维斯家族三代人正是利用这个投资想法，在47年时间里，将最初的投资本金放大了1.8万倍。

  

![](assets/002.png)

  

无论是每股收益的提高，还是市盈率估值的提高，其中都涉及到对企业未来业绩的预期（宏观太难太慢，只好放弃了），只要预测对了，那股票投资岂不是so easy~

  

那问题就来了，你可以对这支股票有预期，张三也可以对这支股票有预期，你们谁预测得准？

  

其次，整个A股有将近5000支股票，一个人不可能都全部做一遍预期，然后选前景最好、信心最强的个股。

  

幸好，这些专业且繁重的工作，市场上众多的行业分析师已经为我们做了，他们相比于一般投资者而言，具有更丰富的信息获取渠道，也同时具备更为专业的分析能力。**这些分析师通常会在个股的研究报告当中，给出个股的评级和目标价格，以及未来三年公司营业收入、归母净利润的预测值。**

  

![](assets/003.png)

  

有了这些预测数据，**把同一支个股的不同分析师的预测值汇总起来，就可以形成这个股票的“分析师一致预期值”，把所有股票的一致预期值（若有）汇总起来，就可以形成“分析师一致预期因子”。**

  

其实，这个因子很早就有了，只是早年间数据不完备，没有数据商专门把这些数据从浩如烟海的研究报告中提炼出来，然后结构化存储供宽客使用，比如说在Barra的模型中，其中的Growth风格因子，就可以看成是“分析师一致预期因子”

  

![](assets/004.png)

  

红框当中，**EGRLF就是分析师做出的未来3~5年企业一致预期净利润增长率，这是偏长期的，EGRSF就是未来1年企业一致预期净利润增长率，偏短期。**

  

**另外两个是EGRO和SGRO，EGRO是根据近5年每股收益计算的斜率（除以平均值标准化）**，这属于根据历史财报数据的外推值，潜台词就是未来延续过去的增长趋势，也是一种预测值，只是它不是由分析师预测的。**SGRO也是相同的原理，只不过斜率的计算对象是每股营业收入。**

  

有没有效呢？先挑EGRSF（未来1年企业一致预期净利润增长率）进行一个简易的分组回测试验，也就是获取所有股票的EGRSF因子值，数值从小到大排列，将股票池当中的股票分为5组，数值最小的属于第1组，第2组次之，数值最大的就是第5组，每月(20个交易日)进行换仓，累计收益率(对数)曲线如下所示。

  

![](assets/005.png)

  

如果因子是有效的，那最理想的情况就是这5组收益出现明显分层，也就是说因子值越小的股票组合收益越低，因子值越大的股票组合收益越高，因子具有区分股票“好坏”的能力。

  

次理想的情况就是，收益虽然不严格分层，但高分位组能稳定超越低分组，EGRSF因子就属于这种情况，从近3年的情况来看，第4、5组的收益是稳定超越第1、2组的，属于金融工程研究报告里常说的“多空有效”。

  

特别说明的是，这次分组回测试验的股票池是中证800指数的成分股，因为一致预期因子的数据最初的源头是来自于分析师的个股研究报告，但并不是每个股票都有分析师研究，被研究报告覆盖，覆盖充分的一般都是市值较大成交活跃的股票，因此选了中证800指数。

  

鉴于一致预期因子的多空有效性，可以采用规则筛选的方法进行选股，一致预期成长策略的构建大体流程如下：

  

**Step1：剔除次新股、ST股、停牌股、涨停跌停股。**

  

**Step2：剔除最新一期财报每股收益(EPS)和滚动12个月每股收益(EPS\_TTM)为负的股票。**

因为“股价=市盈率x每股收益”在每股收益为正数的情况下才有金融意义，否则，你见过投资机构给别人的估值是负数吗？

  

**Step3：计算剩余股票池中每支股票的EGRSF因子（未来1年企业一致预期净利润增长率）和EGRLF因子（未来3年企业一致预期净利润增长率），等权加总，选择数值最大的前N支股票。**

  

**Setp4：最后在这N支股票当中选择市值最小的M支股票。**

在这一步当中选用的还是绩优小市值的思路，除了“绩优”之外，能入选的股票说明至少被两份分析师研报覆盖，不是那种让人提心吊胆的纯小市值股票。其实还试过很多其他的因子，绩效还是小市值因子最亮眼，**所以这个策略的诨名又叫“戴维斯的小狮子”。**  

  

每月第一个交易日使用前一天的数据选股，以当天开盘价成交，回测一下近10年的数据（2013~2023年），绩效如下。

  

![](assets/006.png)

  

虽然能跑赢基准，但后期的效果不佳，**于是在策略的Step3中，除了使用EGRSF和EGRLF因子外，还使用Barra当中EGRO和SGRO因子，如果说前2个因子是分析师的主观预测，那后2个因子就是根据财报数据的客观外推**，4因子也是等权组合，绩效如下。

  

![](assets/007.png)

  

**效果好了不少，年化收益从28%提高到了45%，夏普率也从0.92提高到了1.63，最大回撤也降低了一些**，关键是超额收益曲线(黄色)在近年来也比较昂扬，策略收益稳定跑赢基准，看来Barra选的因子果然名不虚传。

  

分析师一致预期成长策略的构建思路大体说完了，策略源码已经分享在『量化藏经阁』和『量化藏经阁Max』社群内，群友请在社群量化兵器库原路径中自取。

  

拿到源码后，可以自行修改4因子之间的权重，**如果是增改因子，注意要先去极值标准化才能把不同量纲的因子加总**，或是根据个人资金量调整选股数目，例如下图是选股数目为5时的回测绩效，股票数目减小，增大了收益，也放大了风险。

  

![](assets/008.png)

  

**参考资料：**

_海通证券，2017.06，《选股因子系列研究（二十一）：分析师一致预期相关因子》_

_东方证券，2017.12，《因子选股系列研究之三十二：分析师研报的数据特征与alpha》_

_天风证券，2018.04，《基于基础数据的分析师一致预期指标构建》_

_东莞证券，2020.09，《量化专题报告：寻找宏观指标中的“戴维斯双击”》_

_东方证券，2023.02，《因子选股系列之八十七：分析师研报类alpha增强》_

_MSCI，2012.06，《The Barra China Equity Model (CNE5) Empirical Notes》_

  

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

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/009.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/010.png)