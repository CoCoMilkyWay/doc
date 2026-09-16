# 5年收益狂飙116倍，没有未来函数，这个量化策略真的是圣杯吗？

量化君 量化君也 2023-03-09 20:58 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c391aac7ae500ca65fe648501aad86bb02b3d57d4f13d347c2eae2fdf14cb5031ddb10f68b52#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c391aac7ae500ca65fe648501aad86bb02b3d57d4f13d347c2eae2fdf14cb5031ddb10f68b52#rd)

![](assets/001.png)

  

最近一个兄dei，发给我一个他最近收集的量化策略，回测下来，**近5年累计收益有116倍（年化158%）**，这狂飙的净值曲线，闪烁着圣杯的耀眼光芒，西蒙斯看了会沉默，索罗斯看了会流泪。

  

![](assets/002.png)

  

![](assets/003.png)

  

看到这么不符合常理的逆天收益，第六感告诉我肯定又是『未来函数』在作妖，打开策略源码一瞅，一目十行的速度看到了第15行，就已经发现，**在回测初始化设置里面已然开了“防未来函数”功能，保证当前时刻取不到未来的数据**，这就奇怪了~

  

![](assets/004.png)

  

突然我回想起了，之前分析过的那个年化577倍的量化策略，里面也是没有未来函数，收益逆天的原因是：在回测设置里面，开启了“强制撮合”功能，能丝滑买入一字涨停板，吃到后续不断涨停的肥美收益。具体的分析过程就不展开了，有兴趣的话，详见这两篇之前的文章[《年化收益577倍的量化策略，没有未来函数，却有这个致命Bug》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&chksm=c21ba03bf56c292df158cfe39451726290f50e990f01301b11e463082d018b14f4761ad9e1db&scene=21#wechat_redirect)和[《年化收益577倍的量化策略，没有未来函数，却有这个致命Bug（续）》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484364&idx=1&sn=251904e9b04aef1c87a908d89ddab8d0&chksm=c21ba043f56c2955f97a6a1a195d4d32076a0e3355c1fe3106d9016d74e862cf96fae0116809&scene=21#wechat_redirect)。

  

**遍览所有设置过程，没有发现开启“强制撮合”功能的函数**，由于系统是默认不开启这个功能的，为了保险起见，我就调用设置函数显式地关闭这项功能，再回测一遍，发现收益还是这么逆天，收益率没有任何改变，没法子了，只好逐行阅读源码，看看是什么情况造成的了。

  

**通读下来，发现这是一个低价股策略，在每周的第一个交易日开盘之后，会先把股票均价在1块5以下的股票统统剔除，然后再剔除停牌股、ST股等乱七八糟的股票，最后选择股价最低的那支股票，作为本周的专属交易股。**

  

**精彩的地方来了，那就是它的交易时点，并不是根据什么技术指标或模型预测信号进行买卖，而是在每天指定的时间范围内，每隔一分钟就会去下一次限价委托单。**

  

买单的委托价格是最近一个50分钟K线的最低价，卖单的委托价格是最近一个50分钟K线的最高价，如果上一分钟的订单没有成交，则撤单后继续根据最新价格下单，如果成交，则此后不再执行同类型交易，也就是买了之后就只卖不买，卖了之后就只买不卖。

  

这样说起来很抽象，咱结合成交明细进行举例说明，策略的回测时间是设置为2018年1月1日至2023年3月7日，初始本金为10w，2018年1月2日是当年的第一周第一个交易日，那一周在盘前筛选出来的股票是“和B生物”，确定了那一周的专属交易股。

  

![](assets/005.png)

  

2018年1月2日开盘后，经过多轮报撤单，终于在10点40分，以2.01元成交价买入了497手，由于A股T+1交易规则，当天不再买入。

  

由于已经有持仓，2018年1月3日开盘后，则开始执行卖出操作，在10点21分，终于委托单全部成交，将昨日旧仓全部卖出，成交价为2.03元。

  

此时，由于又有了可用资金，就又开始了买入操作，仅两轮报单后，就很幸运地又把股票买回来了，当日便停止交易，明天又会按照今天的流程走一遍，如此循环往复。

  

发现没有，这就是每日都在做T，变相实现“T+0”操作，每天一开始就把旧仓卖出去，然后又把股票买回来，一天之内同时实现了买卖两种操作，用日内波段的价差增厚收益。

  

这里面的确没有未来函数，也没有强制撮合，那收益为什么能这么逆天呢？

  

这就要说到我国证券的交易规则了，**因为咱大A股交易的申报价格最小变动单位是0.01元，也就是1分钱**，简单来说，也就是咱每次修改价格下单，要么加减1分钱，要么就是加减1分钱的整数倍。

  

**别小看这1分钱，对低价股来说可就有大用了，因为1分钱相对1块钱股价来说就是1%，相对2块钱股价来说就是0.5%。**

  

就拿2018年1月2日~3日的交易来说，2.01元买入，2.03元卖出，赚了2分钱，价差是大概赚了1%，回测当中设置买入/卖出佣金是万2.5（0.025%），双边合计就是万5（0.05%），卖出时印花税是千1（0.1%），那交易成本大概就是0.15%。

  

_PS：这里的费率设置是合理的，可能会有小伙伴说佣金用设置成【万3】才行，一般你直接在券商官网开户的话，一般费率就是在【万2~万3】之间，找找专属/合作渠道的话可以做到【万1】，目前我认识的好几个券商渠道都是可以做到的。_

  

这一天之间的一进一出的收益就大概赚了0.85%，那5年就算1200个交易日好了，每个交易日赚0.85%的话，1.0085的1200次方是25768，这就是25000多倍啊，116倍相较之下只能算是弟弟了。

  

因为这个策略是不断在等待区间低位买、高位卖，能高胜率地“刮头皮”，这点儿“头皮”对低价股来说，可就是过年吃饺子了，只不过这只是在回测当中，实盘当中且不论交易接口对你不断报撤单有没有限制，就说回测当中能成交的价格，实盘里面能不能成交得了。

  

**回测/模拟盘跟实盘之间的收益不尽相同的原因之一就是“滑点”，滑点就是最终成交价和预期价格之间的偏差**，因为这个世界上最没有意外的事情就是有意外，量化交易里面也是如此。

  

**所以各个量化平台考虑到回测和实盘之间的差距，都会加入滑点模式来帮助大伙儿更好地模拟量化策略在真实市场中的表现，在这里咱就给原始策略加上一个最小的滑点，买卖各偏移1分钱就行了，也就是买入的时候会比原始价格贵1分钱，卖出的时候会比原始价格便宜1分钱，再来回测一遍。**

  

![](assets/006.png)

  

![](assets/007.png)

  

此刻，这个低价股策略就原形毕露了，收益曲线掉头急转直下，最终策略收益-99.88%，基本上是亏完了，其实从2018年1月到2020年10月，都不够3年，策略就已经亏损了99%，只不过后面剩余本金太小了，相对原始本金来说基本上已经忽略不计，后面两年多基本走成了一条直线。

  

出现这种现象，是因为滑点基本上抵消了原来刮的头皮，每次交易基本上都是在妥妥地亏手续费，而且部分交易还会亏价差，上面说了每次一买一卖合计交易成本是0.15%，那就估计每次亏0.30%好了（现实应该比这严重），0.9970的1200次方是0.027，也就是交易到最后，最终剩下的钱只有本金的2.7%。

  

**最后总结一下，这个低价股策略基于日内做T增厚收益的思路，利用交易申报价格最小变动单位对于低股价收益率的“放大效应”，做到了逆天的收益，虽说没有未来函数那些，在实盘当中肯定是无法复现的，加入最小的滑点就可以让它原形毕露，圣杯之旅悄然落幕。**

  

策略排雷就先说到这里了，**如果想了解全部的策略细节，可在公众号后台回复暗号：低价股，获取策略源码和使用说明**，顺便可以试试原策略在高价股里面的表现是什么样子的？

  

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

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/008.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/009.png)