# 为何主力/资金在流入，价格却在下跌？一文唠明白资金流计算的内涵

量化君 量化君也 2023-12-23 20:35 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485711&idx=1&sn=b9643deda6bfe8c10744e87a5ec8783c&chksm=c37afa393446346f439db63230376f37a31ad9268144fafc1b908e1b2d023e012324572412d9#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485711&idx=1&sn=b9643deda6bfe8c10744e87a5ec8783c&chksm=c37afa393446346f439db63230376f37a31ad9268144fafc1b908e1b2d023e012324572412d9#rd)

  

![](assets/001.png)

  

很多小伙伴的在看盘初期会有这样的疑惑，为什么行情软件明明说资金在净流入，或者主力资金在净流入，最后发现价格却是在下跌的？这跟一般的认知不符啊，真是百撕不得骑姐~

  

比方说在上周五，郴电国际明明净流入了713.6万，为啥最终股价却下跌了1.23%？  

  

![](assets/002.png)

  

这对于了解过资金流具体计算细节的小伙伴来说，理解和接受起来毫不费力，对于萌新来说的确是有违常识，为了让萌新少走些弯路，这里展开来唠唠，**这就涉及到了资金流计算的两大核心：“流入/流出”和“主力/散户”**，虽然下文内容以股票为例，但不只是针对股票，对于期货、外汇、大饼等领域也同样适用。

  

**在我有限的实践经验当中，不同行情软件/金融终端，对“流入/流出”的定义有3种，如下：  
**

  

**（1）上涨即流入，下跌即流出；  
**

  

**（2）买入即流入，卖出即流出；  
**

  

**（3）主动买入即流入，主动卖出即流出。**

  

**（1）上涨即流入，下跌即流出**

这一种方式，是按涨跌结果来确定，你既可以按照每一笔交易的涨跌结果来划分，也可以按照K线来划分。

  

比如股票将每天的交易时间按分钟切分成240根K线，如果某1分钟K线股价是上涨的，则这根K线里的全部成交金额则记为“流入”；如果某1分钟K线股票是下跌的，则这根K线的全部成交金额记为“流出”；如果是不涨不跌，则记“流入为0”。

  

因为这种方式是按照涨跌结果确定的，所以大部分情况都是资金流入情况跟价格趋势是一致的，比较难出现“资金不断的正流入，价格却下跌“的情况。

  

这种情况难出现，但不代表不会出现，假设第N根K线放量成交100w，收盘价仅比开盘价高一分钱，而且有长长的上影线和下影线，则这一分钟记为”流入100w“，第N+1分钟缩量成交10w，收盘价比开盘价低3分钱，则这一分钟记为”流出10w“，如果统计这两分钟的资金情况则是“净流入90w”，但股价却下跌了2分钱，假设其余时间的分钟线的情况与这两分钟的情况类似，则会出现“资金不断的正流入，价格却下跌”的情况。

  

这种资金流入流出的判断方式一般流行于股市早期，也在不能获取逐笔数据的情况下经常使用。

  

**（2）买入即流入，卖出即流出**

在一笔交易当中，有买就有卖，买入金额和卖出金额是相等的，最终累计之和都等于成交额，如果按总体资金计算的话，那资金净流入永远都是0。

  

这就要提前涉及到“主力/散户”的知识了，假设咱可以区分每笔交易当中，哪个委托是主力下的，哪个委托是散户下的，具体怎么区分的后面再说。

  

这样咱就可以统计出主力买了多少，主力卖了多少，买卖一相减，就可以计算出主力资金净流入了多少，同理，咱也可以计算出散户净流入了多少。

  

但这个时候，主力净流入的数值和散户净流入的是相同的，只是正负号不一样，相加起来也还是0。  

  

于是乎，这种情况下，即使告诉你主力净流入是一个大大滴正流入，那股价是涨是跌，也得看老天。  

  

这种“流入/流出”定义方式的典型代表就是东方财富软件，详情可见：  

  

https://finance.eastmoney.com/a/20110101117172217.html

  

![](assets/003.png)

  

**（3）主动买入即流入，主动卖出即流出**

这一种方式跟上一种方式一样，都需要有逐笔数据才能计算，比方说股票需要依赖于Level 2当中的逐笔成交数据。逐笔成交数据当中包含了每一笔成交明细，其中会有买卖标志位，B表示“流入”，S表示“流出”。  

  

![](assets/004.png)

  

那这个交易所是怎么设定这笔交易的流入流出方向的呢？我举个例子来说明。

  

假设现在股票A的现价是10元，买一价格是9.9，卖一价格是10.1，各自都是10000股在排队等待成交，这些等待成交的委托单都是“被动的”，自己只能等在那里，自己是无法成交的。

  

有一个帅小伙觉得这个股票价格估值合理，想马上成交买入，看了目前的挂单情况后，就挂了一个限价单“以10.1的卖一价买入1000股”，这个限价单会马上成交，这就是主动买入，交易所就会记下这笔交易并发送出去，买卖标志位则会设为“B”（流入）。

  

其实这个“流入”体现的是“主动性”，看哪一方更为主动成交，虽然一笔交易有买卖双方，但总有一方是主动方，哪方主动标志位就记为哪一方，就跟谈恋爱一样，总有一方追另一方，极少有双方同时表白的，谈情说爱总有一方说第一句话吧。

  

因此，**买方主动跟卖方成交，那就是“流入(B)”，卖方主动跟买方成交，那就是“流出(S)”。**

  

假设这种情况，目前现价是10元，先是帅小伙主动以10.1价格跟卖一价成交了1000股，此时记为“流入10100元”，现价上升至10.1元，而后另外一个美少女主动以9.9价格跟买一价成交了100股，此时记为“流出990元，现价回落至9.9元”。

  

回顾这个过程，资金净流入了10100-990=9110元，但是股价却从10元下跌到了9.9元，出现了“资金流入，股价下跌”的情况，虽然活跃的股票一天有几十万笔交易，不是这两笔交易就概括了的，大家主要体会一下这个过程。

  

这种“流入/流出”定义方式的典型代表就是新浪财经，详情可见：  

  

https://finance.sina.com.cn/temp/guest4377.shtml

  

![](assets/005.png)

  

看明白了吧，流入和流出其实是没有统一定义的，都是各个行情软件/金融终端的喜好，现在你明白了大概的意思，到时候查看行情软件的说明就可以了。  

  

跟“流入/流出”一样，“主力/散户”也是没有统一定义的，也都是萝卜白菜各有所爱。**股票当中一般的做法是，利用逐笔成交和逐笔委托数据，根据不同的金额阈值，将买卖方的委托划分为超(特)大单、大单、中单和小单，主力就等于超大单和大单之和，散户就等于中单和小单之和**，在有些地方，主力也被称为机构或大宗。

  

![](assets/006.jpg)

  

那这些金额阈值具体是多少呢？不同行情软件/金融终端都不一样，我给大伙儿展示几个常见的。  

  

**（1）通达信主力散户划分金额阈值：**  

![](assets/007.png)

  

******（2）**同花顺主力散户划分金额阈值：****

![](assets/008.png)

  

******（3）东方财富主力散户划分金额阈值：******

![](assets/009.png)

********（4）新浪财经主力散户划分金额阈值：********

![](assets/010.png)

  

知道了这些金额阈值，就可以将买卖双方分别划分为超大单、大单、中单和小单，根据之前的“流入/流出”的定义，就可以分别计算出它们的流入金额和流出金额，前者减后者，那就可以最终得出超大单净流入、大单净流入、中单净流入和小单净流入，进而计算出主力和散户的净流入。

  

上面这些金额阈值是不是数额都不一样，眼花缭乱的，而且有的没有超大单这个划分，有的主力又不包含大单。所以啊，到时候要查阅行情软件/金融终端对资金流的具体定义，根据自己的喜好使用就可以了。  

  

如果你看明白了“流入/流出”和“主力/散户”这两个核心，那在有具体数据的情况下，计算资金流就不成问题了，至少让你能快速看明白各个行情软件/金融终端的资金流。

  

**最后，给大伙儿在资金流使用方面的3个tips：  
**

  

**（1）资金流算法各异，没有真正的资金流，只有适合自己的资金流；  
**

  

**（2）由于拆单算法和划分阈值的存在，主力未必是主力，散户也不一定是散户；  
**

  

**（3）资金流入流出跟证券价格涨跌没有必然联系，但可以参考和借鉴。**  

  

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

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

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

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect) [量化砸盘](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485487&idx=1&sn=dcf8ca1e44357071363ca63daca0f270&chksm=c21baba0f56c22b6b352b30d7e5bb21f523f4268eb1edaec0ff4b3472199a5432beb920f505f&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/011.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/012.png)