# 量化交易野路子：菜场大妈选股策略（10年100倍）

量化君 量化君也 2023-07-09 17:59 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c3e35b5dd805297377ad2530cc2be1cd79c485d7ed4d9a3d3d19ffb0d5406bfcbe8fb3288e05#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c3e35b5dd805297377ad2530cc2be1cd79c485d7ed4d9a3d3d19ffb0d5406bfcbe8fb3288e05#rd)

![](assets/001.png)

  

最近在各个量化社区里面瞎转悠，发现有一类策略在个人宽客那里玩得飞起，那就是“大妈类”策略，有菜场大妈，还有皇城大妈、正黄旗大妈、通天纹大妈等，其中以菜场大妈的变种和衍生最多。

  

**虽然这类名字听起来非常“民科”，一股野路子的味道扑面而来，但看过核心的策略思路后，个人感觉还是存在一定的底层逻辑，对于量化萌新来说是一种性价比非常高的入门策略，逻辑简单代码少，思路清晰收益高。**

  

目前从公开的资料看，菜场大妈的核心策略思想是聚宽社区『开心果』大神最先提出，虽然那篇帖子已经被作者删除了，但之前保存下源码的宽客延续了这个策略的生命，出现了各种“魔改”，将策略发扬光大。

  

为啥这些策略名字里面都含有“大妈”呢？我说一个梗大伙儿就明白了。

  

如果你去菜市场买菜时，觉得自己的砍价能力不够出色，或者抹不开面子去砍价，那么有一个土法子非常管用，那就是跟在一个同在市场买菜的大妈后面，等大妈酣畅淋漓砍完价后，你立马凑到摊主跟前，说“这青菜我也来两斤”，划算又实惠，干净又卫生。

  

![](assets/002.png)

  

如果把买股票类比成买菜，那菜场大妈的核心技能就是总能买到“性价比高”的股票，也就是质量好、价格便宜。

  

于是乎，**目前主流菜场大妈策略最核心的选股思路归结起来就七个字：质好价低市值小，下面具体展开唠唠。**

  

**质好，就是筛选质量好、基本面好的股票。**最初的版本只使用了“股息率”这个因子，能真金白银分红的企业应该不会差到哪里去，后来的改进版本当中，为了筛选更优质的股票，逐步加入了“PEG”(市盈率相对盈利增长比率)等因子。

  

**价低，就是筛选质好****股票中价格低的股票，最初的版本中是股价不能超过9元**，“9元”这个设置除了测试效果好之外，还有一个用意就是，方便小资金的个人宽客使用该策略，买入1手股票加上交易费用和滑点，最多才900块出头，选股10支，还不到1w，真的是非常滴亲民接地气。后来改进的版本当中就出现了动态的股价阈值，也就是不使用固定的股价数额了，而使用当时的分位价格，例如股价要比全市场80%的股票都要低。

  

**市值小，顾名思义，也就是筛选出前两步“质好价低”中市值最小的N支股票，作为最终的目标持仓。**

  

你瞧，**虽然策略的名称看起来很俗气，但却利用了两个被金融专家孜孜不倦研究的金融异象——小市值和低价股。**

  

小市值就不用我过多介绍了，那是A股过去十几年来总体收益贡献最大的一类因子，早在Fama-French三因子定价模型中就已经提及，虽然不是一直都有效，但不可忽视它的整体收益贡献。

  

**小市值的“溢价”来源主要有3方面：1)壳价值；2)小票的成长性更好；3)散户主导市场的投机氛围。**当初的壳价值随着注册制的全面推行已经非常弱化，目前主要还是因为A股的投资者结构导致小票更容易被炒作，获得流动性溢价，但针没有两头尖，甘蔗也没有两头甜，小票跌起来也是非常要命的。

  

另一个金融异象就是低价股，这也跟小市值一样，不单单是A股，国内外都存在这个现象，最著名的例子之一就是：七十多年以前，美国投资大师约翰·坦伯顿用借来的一万美元买入一百多支1美元以下的低价股，在这四年之后，他将这些股票全部卖出，赚回了3倍的收益，那也是他投资生涯的第一桶金。

  

**低价股的“溢价”来源就没有小市值的那么明确了，可能的来源也是有3个，分别是低估值、低质量和个人投资者的价格幻觉**，进一步详细的说明大伙儿可以看招商证券金工团队的研究《A股低价股溢价效应及其成因解析》，对了，小市值的可以看东方证券团队的《A股小市值溢价的来源》。

  

菜场大妈选股策略的思路和原理唠完了，是骡子是马时候牵出来遛遛了，策略回测绩效如下，第一个收益曲线图是普通轴，也就是平常一般看的收益率，第二个是对数轴，方便对比策略和基准的收益趋势。

  

![](assets/003.png)

  

![](assets/004.png)

  

![](assets/005.png)

  

回测时间范围是近10年，也就是从2013年至今，取得了10年将近140倍的收益，年化收益是62.34%，夏普率是2.25，最大回撤为30.88%，作为一个简单的入门级策略，这个收益情况算是不错的了。

  

**这里补充说明的是，在质好方面，同时使用了股息率和PEG因子；在价低方面，除了最高限价9元之外，由于A股最新的“面值1元退市”规则，加入了最低限价2元，也就是股价要在2~9元之间；每个月第一个交易日调仓，剔除ST、停牌、涨跌停等股票之后，最终选择符合质好价低条件市值最小的10支股票，等权分配资金，正常费率含最低5元。**

  

不过先不要高兴太早，上面的回测当中我还没有加入滑点，只是模拟一种最理想的交易情况，特别是对于低价股而言，滑点有时候是一个非常致命的因素，这方面的详细说明可以看之前的文章[《5年收益曾狂飙131倍，没有未来函数，"圣杯"背后却有这样的bug》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)。

  

在这里，可以放开一些，加入1%的滑点，再重新回测一遍，回测绩效如下所示。

  

![](assets/006.png)

  

![](assets/007.png)

  

![](assets/008.png)

  

**策略总收益就从140倍下降到了97倍，看上去下降得非常多，但实际策略年化收益只从62.34%下降到了56.70%，因为月频调仓，交易频率不高，滑点造成的收益下降有限，可以从侧面看出复利效应是多么的厉害和诱人。**夏普率也下降到了2.03，最大回撤也扩大到了31.19%，虽然出现了明显的下降，但对于入门级策略来说，依旧是一个非常亮眼的数据。

  

那咱再来看看今年的表现如何，回测时也是加入了滑点。

  

![](assets/009.png)

  

![](assets/010.png)

  

![](assets/011.png)

  

**菜场大妈选股策略年初至今的表现非常亮眼，虽然说5月份之前总体跑输了，但两个月的时间一下子就追回来了，跑赢了基准37%。其实这也是大妈类策略关注度提高的原因，都是被目前亮眼的数据吸引过来的。**

  

本文只是说了菜场大妈选股策略的主流基础玩法，留有很多改进方向待大侠们魔改，例如：

  

（1）更多更有效的基本面筛选因子组合。

  

（2）对持仓中涨跌停等特殊股票的特殊处理和之后的空闲资金再利用。

  

（3）大妈类策略不是机构的主流策略，因为承载不了那么多资金，更适合个人宽客使用，并且鉴于小市值和低价股的溢价来源，可以在基础池中进一步剔除机构持股比例和分析师跟踪比例比较高的个股。

  

纯粹只是个人猜想，抛砖引玉，下期见~

  

_PS：本文『菜场大妈量化选股策略』试验源码、使用说明和异象研报已分享至『量化藏经阁』和『量化藏经阁Max』社群内，群友请在社群量化兵器库原路径中自取。_

  

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

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/012.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/013.png)