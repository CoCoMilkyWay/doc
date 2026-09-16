# 菜场大妈遇上马科维茨，擦出小市值更高收益的火花(十年160倍)

量化君 量化君也 2023-10-28 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c33fe88a5cfa573748c373b41318746b77515bb304dba1f89668054c18ea27895a489b8062a2#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c33fe88a5cfa573748c373b41318746b77515bb304dba1f89668054c18ea27895a489b8062a2#rd)

  

![](assets/001.png)

  

我之前介绍分享过不少量化策略了，但是着重点是在标的筛选和进出场时机的把握，仓位一般都是等权重或是等手数，较少涉及到仓位管理，为了填补这方面的空白，先拿菜场大妈策略下手，**唠唠如何在股票清单相同的情况下，通过仓位管理，达到优化策略表现的目的。**  

  

先拿菜场大妈策略开刀的原因，是因为它是目前个人宽客非常喜欢的热门小市值策略，但很多公布出来的小市值类型的策略，里面普遍都是对个股进行等权处理，也就是对于筛选出来的小盘股，每支股票都是买入相同的金额，这种处理的确是很方便，但不够圆润，于是乎，盘他！

  

![](assets/002.png)

  

先给不清楚前情的小伙伴说说菜场大妈选股策略的构建思路，**最核心的选股思路归结起来就七个字：质好价低市值小。**

  

**质好，就是筛选质量好、基本面好的股票。**最初的版本只使用了“股息率”这个因子，能真金白银分红的企业应该不会差到哪里去，后来的改进版本当中，为了筛选更优质的股票，同时使用股息率和PEG因子(市盈率相对盈利增长比率)。

  

**价低，就是筛选质好股票中价格低的股票**，最初的版本中是股价不能超过9元，“9元”这个设置除了测试效果好之外，还有一个用意就是，方便小资金的个人宽客使用该策略，买入1手股票加上交易费用和滑点，最多才900块出头，选股10支，还不到1w，真的是非常滴亲民接地气。由于A股最新的“面值1元退市”规则，于是在改进版当中加入了最低限价2元，也就是股价要在2~9元之间。

  

**市值小，顾名思义，也就是筛选出前两步“质好价低”中市值最小的N支股票，作为最终的目标持仓。**

  

您瞧，虽然策略的名称看起来很俗气，但却利用了两个被金融专家孜孜不倦研究的金融异象——小市值和低价股，有明显的盈利逻辑。

  

对菜场大妈策略进行回测，每个月第一个交易日调仓，剔除ST、停牌、涨跌停等股票之后，最终选择符合上述条件的10支股票，等权分配资金，正常费率滑点，回测绩效如下，对策略更加详细的描述和回测请见之前的文章[《量化交易野路子：菜场大妈选股策略（10年100倍）》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect)。

  

![](assets/003.png)

  

![](assets/004.png)

  

![](assets/005.png)

（对数轴方便看超额收益）

  

从回测图表中看出，**从2013年至今，菜场大妈策略这10年来取得了10932.19%的累计收益，十年100倍，年化收益是56.48%，夏普率是2.03，最大回撤为31.19%**，作为一个简单的入门级策略，这个收益情况算是不错的了，而现在，咱想要它变得更好，改进的方向就是仓位管理。

  

原始版菜场大妈主要解决的是选什么股票的问题，仓位管理解决的是给这些选定的股票如何分配权重的问题。

  

从解决仓位管理普适性问题出发，假设选股策略选出了n支股票S\_1~S\_n，给每支股票分配的权重分别是w\_1~w\_n，假设每支股票未来的预期收益分别为R\_1~R\_n，那么整个组合的收益可以表示为R=w\_1\*R\_1+w\_2\*R\_2+...+w\_n\*R\_n。

  

![](assets/006.png)

  

这个组合收益R就是所有仓位管理问题的起点，你希望组合收益呈现出一种什么样的状态呢？是风险一定的情况下收益最高，还是收益一定的情况下风险最小，还是组合里每个股票冒同样的风险，亦或是收益除以风险的夏普值更高~~

  

要回答这个问题，就要请出现代金融理论和资产组合理论的先驱马科维茨老爷子(Markowitz)，**马老爷子1952年在其经典之作《Portfolio Selection》提出了均值-方差模型，创造性地将数学引入到金融投资领域当中，从数学层面上解决了资产选择和仓位分配的问题。**

  

![](assets/007.png)

  

马老爷子凭借着对现代金融经济学理论的开拓性研究，以及提供了切实可用的金融资产收益与风险的衡量工具，获得了1990年的诺贝尔经济学奖。可惜的是，马老爷子今年6月在圣地亚哥仙逝了，享年95岁，但留下的理论工具依然熠熠生辉。

  

**咱这次要用到的就是其中的最小方差组合理论**，要看懂的话真的不难，只要明白数学期望、方差和协方差的基本定理与性质就可以了。

  

马老爷子用投资回报的期望值表示组合投资收益率，也就是咱之前已经写出的表达式：R=w\_1\*R\_1+w\_2\*R\_2+...+w\_n\*R\_n；用组合收益R的方差(或标准差)表示组合收益的风险，那将R的式子代入到方差(Variance)的计算公式当中，则可以将式子展开成各个股票收益相关的表达式。

  

![](assets/008.png)

其中Var(R\_i)表示第i支股票收益率的方差，Cov(R\_i,R\_j)表示第i支股票和第j支股票收益率的协方差，特别地，Cov(R\_i,R\_i)=Var(R\_i)，如果不明白的话，度娘一下方差和协方差的计算公式就一清二楚了。

  

于是乎，展开式的第二行就统一用协方差表示，每支股票两两求协方差后与各自权重相乘，最终全部加总。菜场大妈策略是选10只股票，那对应的Var(R)展开是有10x10=100个子项。

  

为了表达的简洁性，最终表示为向量矩阵的乘积形式，其中W为n维列向量(w\_1,w\_2,...,w\_n)，左上角有个T是表示转置成行向量，Ω为股票之间收益率的协方差矩阵(nxn维)。

  

1xn维的列向量乘以nxn维矩阵，再乘以nx1维行向量，最终的结果是一个标量数值，就是整个组合的风险，咱就是希望找到这个最合适的权重向量W，使得整个组合风险最小化，形成方差/风险最小的投资组合。

  

![](assets/009.png)

  

**怎么找到这个最优权重向量W呢？一般在量化实践当中，咱直接调用数学优化模块进行寻优处理**，例如Python当中的scipy库的optimize模块，以Var(R)作为目标函数，给出对应的约束条件，然后它就会给你找出Var(R)最小值对应的那组权重。就跟使用ChatGPT一样，你给它描述任务、背景和条件，它就能给你提供解决方案。

  

在真正开始实战之前，还要提一嘴最小方差模型的致命缺陷，那就是如果有一个股票之前的股价波动相对较小的话，那它的权重会变得非常大，反之，之前波动大的股票权重会非常小。

  

用一个例子进行解释，假设有三支股票，为了简单起见，假设它们之间两两不相关，也就是相关系数与协方差皆为0，那收益率的协方差矩阵就是对角元素为各自收益率方差的对角矩阵，那可以显式获得最优权重的解析解。

  

![](assets/010.png)

  

其中V\_i就表示第i支股票收益率的方差(风险)，从上面的式子可以看出，股票的权重与其方差成反比，要是股价波动小的话，权重会变得非常高。  

  

如果单纯是根据最小方差组合模型求解权重的话，经常会出现单个股票权重在40%~50%之上，另外一些股票权重在1%之下，如果资金量小的话，低价股也买不进一手，根本成交不了。

  

**所以在量化实战当中，可以人为设定单只个股的权重上下限，指定要在这个权重范围内求解最小方差对应的权重**，于是乎，用带权重上下限约束的最小方差组合模型，确定菜场大妈策略每期选出的那10支股票的权重，其他设置不变，重新回测一遍，绩效如下所示。

  

![](assets/011.png)

  

![](assets/012.png)

  

![](assets/013.png)

（对数轴方便看超额收益）

  

**年化收益率从56.48%提升到了62.81%，累计收益从十年100倍提高到了十年160倍，夏普率从2.03提高到了2.30**，再看看今年年初至今的表现，菜场大妈原版策略目前累计收益是56.61%，马科维茨版的是60.19%，也是高出了一头，说明用马科维茨最小方差组合模型进行仓位分配，还是明显起到了改进策略的作用，没有白折腾。  

  

**菜场大妈策略原版：**

![](assets/014.png)

  

**菜场大妈策略马科维茨版：**

![](assets/015.png)

  

细心的小伙伴可能发现了，原版策略的波动率是0.258，最大回撤是31.19%，马科维茨版的波动率是0.255，最大回撤是31.31%，虽然整体波动率是下降了，起到了“最小方差”的作用，但是降低幅度不明显，而且最大回撤还略微增加了，为啥出现这样的情况呢？  

  

那是马科维茨均值-方差模型最最最致命的“缺陷”，在计算组合收益R时，要输入的是股票的“预期收益”，那是未来的事情，或者是咱也不知道股价的真实概率分布，只好使用历史数据代替，过去的波动未必代表未来的波动，就难以起到方差最小化的作用。

  

但是，如果是同时持仓股票和债券，给这俩分配权重，那很明显，股票与债券的相关性没有股票与股票之间高，并且债券的波动率要明显低于股票，那最小方差模型肯定会将大部分权重给予债券，债券的低波动是持续性的，那就可以起到最小方差的作用，这也从侧面说明了降低整体波动最好是多种低相关资产进行组合。

  

那马科维茨版的菜场大妈策略为什么会比以前明显收益更高了呢？那是因为长期来看，低波动股票的收益整体要比高波动的股票要高，国内外股市普遍如此，又被称为“低波异象”。

  

![](assets/016.png)

  

**最小方差组合模型更倾向于将高权重分配给低波动股票，对于之前的等权组合而言，相当于是提高了低波动股票的权重，降低了高波动股票的权重，把更多的权重分配给了未来预期收益更好的股票，因此通过仓位管理提高了整个组合的收益。**

  

所以啊，在做仓位管理的时候，也不一定要用马科维茨的模型，只要人为地提高低波动股票的权重，降低高波动股票的权重，也能达到类似的效果，只不过马老爷子的模型算得更合理一些，因为他还考虑了组合股票之间的相关关系，比单独根据波动率因子分配的要强上一丢丢。  

  

以上内容纯粹是个人猜想和探究，用以抛砖引玉，下期见~

  

_PS：本文『马科维茨版的菜场大妈策略』试验源码、使用说明和相关资料已分享至『量化藏经阁』和『量化藏经阁Max』社群内，群友请在社群量化兵器库原路径中自取。_

![](assets/017.png)

  

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

![](assets/018.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/019.png)