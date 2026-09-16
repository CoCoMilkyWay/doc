# 做量化交易真的不需要懂金融吗？为啥都对编程大讲特讲？

量化君 量化君也 2023-06-18 21:57 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485258&idx=1&sn=e41ecb4140f678ef69ee1210e2fa2246&chksm=c3e79e4e70c614c9ca3e455b8e96129c62487ba438b7d6db5144504b1e4557c0c2e22bda9743#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485258&idx=1&sn=e41ecb4140f678ef69ee1210e2fa2246&chksm=c3e79e4e70c614c9ca3e455b8e96129c62487ba438b7d6db5144504b1e4557c0c2e22bda9743#rd)

![](assets/001.png)

  

今时今日，市面上与量化交易相关的书籍可谓是琳琅满目，让人眼花缭乱，随便打开一个电商购物网站/APP，以“量化”这个关键字进行搜索，花花绿绿出现一大片。  

  

遨游在这些书籍目录中，惊奇地发现，很多书里面大部分篇幅都在讲编程，其中以Python居多，很少有讲金融的，或是讲金融的篇幅很少，**以至于有的量化萌新都发出了这样的疑惑：为何大部分的Python量化书籍都基本不讲金融知识，反而对编程大讲特讲？做量化交易真的不需要懂金融吗？**

  

咱先来说说为啥有“对编程大讲特讲”的现象。如同下面这个书籍目录，全书三百多页，就有两百多页在讲Python编程，存在即合理，往深处想想，如果让我非写一本书不可，也难逃这样的枷锁。

  

![](assets/002.png)

  

量化交易，官方一点来说，就是通过计算机编程，利用数理统计模型，对金融市场的数据进行分析，然后根据分析结果进行交易的一种方式。简单来说就是，**量化交易=编程+数学+金融**。

  

按理儿来说，要讲量化交易，肯定编程、数学和金融都要涉及的，为啥现在让人感觉好像只讲了“编程”这个部分？

  

这个就涉及到写书的动机了，善意地想，作者肯定都是希望把量化交易给讲通讲透的，但书籍篇幅有限，不可能面面俱到，肯定有所侧重，那么，侧重哪一块儿就有讲究了。

  

写金融吧，光交易的品种就有股票、期货、期权、债券、基金(ETF)等，品种介绍、交易规则和相关金融理论细细写出来，可能红楼梦的篇幅都装不下；写数学吧，就更不用说了，内容比起金融来更boring，概率论、线性代数、微积分、随机过程这些冰冰冷冷地写出来，读者直接从入门到放弃，顺带治愈了多年的间歇性失眠。

  

**相对金融和数学，编程就显得可爱多了，学了就可以上手操作，根据书中的策略示例，编写好了之后，放进量化平台，就能实时产生交易信号、持仓信息和净值曲线，成就感油然而生，学习热情大大滴被激发。**

  

如果着重写金融和数学，读者看过泛泛而谈的理论后，还是茫然无措，不知从何下手，直呼上当，大骂作者灌水割韭菜；侧重写编程就没有这种烦恼了，要是有读者来找茬，作者就可以翻出售卖图书时的宣传语，语重心长地说道：

  

_“你看，我教你搭建Python开发环境了吧”_

  

_“我教你Python语法基础了吧”_

  

_“我教你获取基本面数据和行情数据了吧”_

  

_“我教你如何使用回测框架跑出净值曲线了吧”_

  

_“瞅瞅，我承诺的都做到了！”_

  

![](assets/003.png)

  

明白了吧，**编程、数学和金融这3大模块，如果只能侧重写一个的话，肯定选编程，因为金融和数学都太多太杂，写起来费力不讨好，编程由于它的通用性和实用性，写它的效用反而是最高的。**

  

这就是为啥现在的量化书籍都喜欢大讲特讲编程的主要原因，只要把你教会开发出一个量化策略，那就算成了，有结结实实的成果展示，你这厮就不要再说洒家割韭菜。

  

那做量化交易真的不需要懂金融吗？

  

**金融在量化书籍里面说的少，但不代表不重要，如果说做量化懂编程就可以了，那要做好量化，就一定还需要懂金融和数学，它们才是真正的量化内功，决定着你量化之路的上限。**

  

具体到量化萌新的学习路径，初期以编程为主是可以的，因为这个时期是以实现量化策略为主，把那些量化书籍当成是工具书来看，为什么这样说呢？

  

因为个人感觉，这些书籍目前最大的缺陷就是，从金融理论和数理统计到量化策略的演化过程过于割裂，基本上书里就告诉你有这个策略，它的具体细节是什么，但很少从根本上说这个策略idea是如何产生的。

  

就比方说，股票量化书里面都会提及小市值策略，那小市值策略是怎么被发现出来的？小市值策略生效的金融逻辑是什么？现在A股全面注册制铺开后，对小市值策略有什么影响？

  

再打一个比方就是，如果同时看过国内外量化书籍的小伙伴就会发现，同样都是统计涨跌幅度，漂亮国有效的一般是动量因子，而国内有效的是反转因子，出现这些差异的金融逻辑是什么？

  

所以那些书籍更多是起到工具书的作用，**编程告诉你如何去实现一个量化策略，而金融和数学则是帮助你如何去发现和迭代一个****量化策略，在量化里面，编程少了金融和数学，就是无根之木、无源之水、徒有其表。**

  

说到这里，就会形成一个套娃式的问题：如何学习金融和数学？这就超过本次的话题范围了，而且个人能力有限，觉得这个问题太大太深不好答。

  

因为金融和数学的理论太多太杂了，要想学完了再做量化那是猴年马月的事情了，不过我有一个变通接地气的法子，那就是“多看研报”，那些金融工程研究报告里面往往都包含了金融和数学演化成量化策略的过程，你把自己想做的策略相关研报都找出来，将其中的金融和数学理论搞懂且融会贯通就行了，做到有的放矢，不要胡子眉毛一把抓。

  

**最后想补充说明一下，金融和数学理论并不是越复杂越好**，由于在量化圈子混得久了，能看到的东西稍微比萌新们多一些，真的看过很多量化大神的实盘策略，涉及到的数学都没有超过高中范畴，涉及到的金融就更简单了，就是基本的交易规则和趋势理论，**但策略成功的原因并不纯粹在金融和数学本身，而在于宽客将金融和数学理论与交易实际相结合的能力，也就是要把理论用到刀刃上。**

  

很多人都看过电影《三个白痴》，其中有个名场面，学长让男主角兰彻脱掉裤子（别想歪~原因请看原片），兰彻不从，躲进了宿舍，学长扬言再不出来就在门口嘘嘘，兰彻就把电线接在铁勺上，把铁勺夹在木尺上，接着开电闸，学长后来就直接嘘了上去，那酸爽~~~室友就评价道：**盐水可以作为电的导体，初中生都知道，我们只学了课本，他却学以致用！**

  

![](assets/004.png)

  

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

![](assets/005.jpg)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/006.png)