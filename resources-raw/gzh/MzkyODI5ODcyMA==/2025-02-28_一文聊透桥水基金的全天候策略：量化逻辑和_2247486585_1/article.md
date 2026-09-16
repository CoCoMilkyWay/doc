# 一文聊透桥水基金的全天候策略：量化逻辑和收益复现

量化君 量化君也 2025-02-28 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486585&idx=1&sn=34b59542ba29fbb5ef92a5c18cabfd55&chksm=c3188cbc7b58124fd5376051afa760feb68eef4e472cce73f51618ccbd10b26e0cee638d56fe#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486585&idx=1&sn=34b59542ba29fbb5ef92a5c18cabfd55&chksm=c3188cbc7b58124fd5376051afa760feb68eef4e472cce73f51618ccbd10b26e0cee638d56fe#rd)

![](assets/001.png)

  

年初媒体报道，桥水中国基金(Bridgewater China)以35%的年度收益率，跻身2024年度全球对冲基金Top10，打破多年来外资私募在天朝"水土不服"的魔咒。

  

![](assets/002.png)

  

这亮眼的业绩表现和蹭蹭上升的管理规模，引来了众人的瞩目，不少身边的朋友和群里的伙伴也热烈讨论起桥水基金的顶流策略——全天候策略(All Weather Strategy)，我也写过相关的内容和复现过对应的策略，就把之前的帖子转了过去，有些小伙伴看了之后“大呼上当”，说策略收益根本对不上。

  

好吧，我承认，写这篇文章的小心思就是为了“洗白”自己，我把之前的相关内容梳理整合起来，同步更新策略数据，先来唠唠全天候策略的底层逻辑，然后做策略复现，最后回应误解以及如何做出桥水基金那么亮眼的收益。

  

桥水基金的创立者和主理人是瑞•达利欧(Ray Dalio)，对，他也是《原则》这本书的作者，管理的最出名的两个产品分别是绝对Alpha基金(Pure Alpha，1991 年成立)和全天候基金(All Weather，1996 年成立)。

  

**![](assets/003.jpg)**

**全天候基金采用的投资策略就是全天候策略，核心的投资思想就是，假定自己不知道未来是什么经济周期，也不知道将来什么资产会表现出色，通过分散化买入各种类别的金融资产，希望在各种经济环境下都能带来稳定的收益。**官方测算，在达到与股票相同收益率的情况下，全天候策略的波动率只有股票波动率的三分之一。

  

![](assets/004.png)

  

那全天候策略的构建逻辑是怎么样的呢？请听我下文慢慢道来。

  

上面说到了，全天候策略是假定无法预测经济周期和对应经济周期下哪个资产会表现出色的，没法儿单押，那就全都要！

  

先来看看Dalio如何划分经济周期，**他根据经济增长(Growth)和通胀水平(Inflation)实际值和市场预期值(Market Expectation)之间的相对大小关系将经济周期划分为4种宏观状态：经济上行、经济下行、通胀上行、通胀下行。**要注意的是，经济周期划分方法并不唯一，各有各的经济周期划分方法，这里指的只是Dalio的划分方式。

  

![](assets/005.png)

  

再来看看不同宏观经济状态下哪种资产会带来更好的收益，一般而言，经济上行时股票类资产表现较好，经济下行或通胀下行时债券类资产表现出色，经济上行或通胀上行时大宗商品类资产表现更好。于是乎，Dalio根据各类资产的历史表现和相关金融理论，为这4个经济周期分别安排了不同的适配资产。

  

**经济上行期：**股票(Equities)、商品(Commodities)、公司信用债(Corporate Credit)、新兴市场债(**E**merging **M**arket Credit)。

  

**经济下行期：**名义债券(Nominal Bonds)、通胀挂钩债券(**I**nflation-**L**inked Bonds)。

  

**通胀上行期：**通胀挂钩债券(**I**nflation-**L**inked Bonds)、商品(Commodities)、新兴市场债(**E**merging **M**arket Credit)。

  

**通胀下行期：**股票(Equities)、名义债券(Nominal Bonds)。

  

最后，Dalio给每种可能出现的经济周期配置相同的风险敞口，也就是每个象限的子资产组合都是25%，在每个子资产组合里面又把风险权重等量地分配给组合中的每种资产，进而获得每种资产风险权重和最终配置比例。

  

**就这样，通过多元化的资产配置，并且利用各种资产之间相关性对抗风险，每个时期，都至少有一个象限的资产组合处在上涨周期，便可以在长周期里面获得较为稳定的收益，增强净值曲线的稳定性。**

那具体怎么计算每种资产的风险权重和配置比例呢？这可以参照风险平价(Risk Parity)的计算流程。

  

![](assets/006.png)

  

这里补充说明一下全天候策略和风险平价之间的关系，经常看到“全天候策略是参照风险平价理论构建的”等类似的说法，这样绝B是不严谨的，因为全天候基金在1996年就成立了，而风险平价是磐安基金(Panagora)的钱恩平(Edward Qian)博士在2005年才提出的，属于是先有实践后有理论总结，只不过是这理论总结的是太TM好了，太符合全天候策略的本质内核了。

  

**风险平价的中心思想就是希望在资产组合当中，每个资产的风险敞口都是一样的，也就是每个资产都是面对相同的风险。**也就说，放弃对资产组合收益的预测，把重心转移到资产组合风险预算的规划上，资产权重直接反映风险属性。如果你觉得某些资产的风险太低的话，可以通过放杠杆的方式调节，只不过这时需要考虑资金成本的问题。

  

要实现全天候策略，在计算风险平价确定各个资产配置权重这一步，对量化萌新比较难，不过也不用担心，这里会先给一个简单的版本，稍后再来揭开风险平价的面纱，聊聊具体的计算细节。

  

在托尼•罗宾斯(Tony Robbins)的著作《Money: Master the Game》里面，**Dalio在接受作者采访时，给出了一组全天候策略资产配置比例的经验数值，根据这组数值定期进行再平衡就可以了。**

**30%投资于股票(stocks)**：股价波动大弹性好，在经济上行期收益更支棱。

  

**15%投资于中期债券(intermediate term bonds)**：能提供稳定的利息收益，经济下行或通胀下行时表现更出色。

  

**40%投资于长期债券(longterm bonds)**：配置原理同中期债券，但相较于中期债券而言，对利率的变动更为敏感。

  

**7.5%投资于黄金(gold)**：带有明显的避险属性，在通胀上行和世界动荡时表现出色。

  

**7.5%投资于大宗商品(commodities)**：在经济上行或通胀上行时大宗商品类资产往往表现优异。

  

![](assets/007.png)

  

![](assets/008.png)

  

上面的这个版本可以当做是躺平版的全天候策略，为了让这个策略在我国A股市场也具有投资意义，我打算用对应不同资产类别的ETF完成资产组合的构建，秉承着最适配和尽量分散的原则，组合清单如下。

  

**股票类(30%)：沪深300ETF，中证500ETF，标普500ETF，纳指ETF；**

**中期债券(15%)：5年期国债ETF；**

**长期债券(40%)：10年期国债ETF；**

**黄金(7.5%)：黄金ETF；**

**大宗商品(7.5%)：大宗商品ETF。**

  

每个月月初开盘进行再平衡，开平仓费率各万分之三，因为10年期国债ETF是在2017年8月24日才上市交易，在此之前用5年期国债ETF替代，回测一下近10年的情况，如下。

  

![](assets/009.png)

  

策略累计收益是94.84%，年化收益是7.0%，夏普率为0.461，最大回撤是11.86%，收益不算高，主打的是稳稳的幸福。亮点主要体现在，沪深300指数基准的波动率是0.22，策略的波动率是0.065，前者是后者3.38倍，跟桥水基金他们之前的测算数值还是比较接近的。

  

说完躺平版的风险平价策略，现在就来唠唠原汁原味风险平价版的了。

  

风险平价这个概念是磐安基金(Panagora)的钱恩平(Edward Qian)博士在论文《Risk Parity Portfolios: Efficient Portfolios Through True Diversification》(2005)中有一个生动形象的例子。

  

![](assets/010.png)

**在股债组合中，股票资产的权重是60%，债券资产的权重是40%，看上去资金是分散了，但实际上风险并没有有效分散，90%以上的的风险都集中在股票端。**

具体是怎么得出这个结论的呢？咱来仔细计算一下~

  

股票端(Russell 1000 Index)的年化波动率是15.1%(标准差)，债券端(Lehman Aggregate Bond Index)的年化波动率是4.6%，它俩的相关系数是0.2。

  

那么，整个组合的方差波动率就是：

  

(60%)^2 × (15.1%)^2 **+** (40%)^2 × (4.6%)^2 **+** 2 × 60% × 40% × 0.2 × 15.1% x 4.6% ≈ (9.6%)^2

  

其中“x^2”表示的是x的平方，股票端贡献的方差波动率就是：

  

(60%)^2 × (15.1%)^2 **+** 60% × 40% × 0.2 × 15.1% x 4.6% ≈ (9.24%)^2

  

那么股票端的风险贡献占比就是(9.24%)^2 / (9.6%)^2 = 92.64%，也就是说，股票端的资金权重虽然是60%，但却贡献了将近93%的风险，资金权重40%的债券只贡献了7%的风险。这还是在论文当中用收益率方差衡量风险的情况下，如果用常用的标准差，股票端的风险占比更高，高达9.24% / 9.6% = 96.25%。

  

**所以，这就是传统的按资金分配资产权重的问题，风险并没有被有效分散，钱博提出的风险平价就是来解决这个问题的，“风险分散才是真的分散”，每个资产带来的风险应当相同。**

![](assets/011.png)

  

知道了风险平价的理念，那咱就来看看怎么根据风险平价，算出每个资产应该配置的权重。

  

咱假设投资组合当中有n个资产，第i个资产的权重为wi，第i个资产的收益率为ri，那么资产的权重向量(列向量)就是w=\[w1, w2, ..., wn\]，那么资产组合的收益就是rp = w1\*r1 + w2\*r2 + ... + wn\*rn，资产组合的波动率(代表风险)就是：

  

![](assets/012.png)

  

其中σij表示资产i和资产j之间的协方差cov(ri, rj)，σij=σji，特别地，当i=j时，σii = cov(ri, ri) = variance(ri) = σi^2，也就是资产i的协方差等于其本身的方差。

  

std(x)表示求x序列的标准差，Σ表示协方差矩阵，其中第i行第j列的元素就是σij，长下面这个样子。

  

![](assets/013.png)

  

接下来就是要计算边际风险贡献MRC(Marginal Risk Contribution)，它的金融意义就是对应资产权重wi变动1单位时，资产组合波动率σp变动多少，对σp求偏导。

  

![](assets/014.png)

  

那么资产i对总风险的贡献TRC(Total Risk Contribution)就是权重wi与边际风险贡献MRCi的乘积。

  

![](assets/015.png)

  

风险平价的目标就是让各个资产对组合总风险的贡献程度就是一样的，也就是TRC1 = TRC2 =…= TRCn，那么求解最优的权重w就可以转化为求解以下最优化问题。

  

![](assets/016.png)

  

因为在现实当中，是很难让每个资产的TRC相互之间完全相等的，只好让它们之间的相互差值的平方之和最小，也就是让它们之间尽量靠近，这种最优化问题用scipy库当中的minimize函数就非常容易求解了。

  

数学推导说完了，风险平价到底有没有用，是骡子是马，咱牵出来溜溜。

  

上面的躺平版全天候策略用的是Dalio给出来的固定权重，咱这次就沿用相同的持仓，但持仓的权重用风险平价理论每一期动态确定，持仓列表如下。

  

**股票类：**沪深300ETF，中证500ETF，标普500ETF，纳指ETF；

  

**中期债券：**5年期国债ETF；

  

**长期债券：**10年期国债ETF；

  

**黄金：**黄金ETF；

  

**大宗商品：**大宗商品ETF。

  

为了方便与上面的躺平版全天候策略进行对比，先将躺平版的回测绩效po上来。

  

![](assets/009.png)

  
设置相同的回测时间范围、调仓周期、费率和滑点等等，再回测风险平价版的全天候策略，回测绩效如下。

  

![](assets/017.png)

  

从两者绩效对比中看出，风险平价版的年化收益是5.83%，躺平版的年化收益是7.0%，年化收益下降1.17%，收益虽然下降了，但夏普率却提高了，之前的夏普率是0.461，现在却上升到了0.507，这主要归功于风险平价对风险的分散/控制能力。

  

从净值曲线上也可以明显看出区别，风险平价版的净值曲线要更加平滑，看向具体的数值，风险平价版的最大回撤是6.59%，跟躺平版的11.86%比起来差不多就是“腰斩”了，风险平价版的策略波动率是0.036，躺平版的策略波动率是0.065，降幅也达到了44%。

  

**看出来了吧，风险平价还是有用的，但它不是用来提高收益的，反而会降低收益，它的最大用处就是分散/控制资产组合的风险，有效降低资产组合的波动率和最大回撤，提高策略的收益风险比，有更好的持仓体验。  
**

  

那么，这问题就来了，躺平版和风险平价版的全天候策略年化收益才是7.0%和5.83%，远远赶不上人家35%的年收益，这不是潘长江躺地上跟姚明比身高嘛~~~咱先别急啊，桥水基金的是2024年度的收益，咱也把上面的两个策略2014年初至今的策略收益po出来。

  

躺平版全天候策略2024年初至今回测收益：

![](assets/018.png)

  

风险平价版全天候策略2024年初至今回测收益：

![](assets/019.png)

  

由于去年股债金商表现都不错，所以这两个全天候策略年化收益达到了14.1%和10.71%，比历年平均收益有明显的提高，好吧，还是没有达到35%。先别急，井被大风吹到墙外头，郭德纲扒马褂圆谎也得慢慢来~~~

  

试想一下，年化14%，100w一年就是赚14w，那如果赚14w固定不变，但本金是40w，那收益率不就是35%了嘛。那怎么做到呢，保证金交易啊！！！就是俗话说的“上杠杆”。

  

全天候策略做的是大类资产配置，因为普通人把这些大类资产都集齐最容易的途径之一就是ETF，所以为了策略的普适性和可交易性，上面的两个策略中的大类资产用对应的ETF实现。

  

但是对于大机构来说，那能玩得起的大类资产证券标的可就多了。比如说，买市值100块10年期国债ETF，真的就要自己口袋掏出100块，而10年期国债除了有ETF外，还有10年期国债期货，保证金只要5%，5块钱就能配置市值100的国债期货，但是1手国债期货市值上百万。

  

同理，还有5年期国债期货，沪深300股指期货，中证500股指期货，这些一手的市值都是上百万起，一手黄金期货也要将近70w，所以这些都不太适合小资金的个人。

  

![](assets/020.png)

  

![](assets/021.png)

  

![](assets/022.png)

  

但对于大资金的机构来说却有大用，可以上杠杆，提高收益。假设上面这些大类资产对应的期货品种平均保证金率是15%，一个小目标1y的资管产品，可以拆为4500w+5500w，4500w的保证金可以撬动3y的市值，剩下的5500w现金可以留在账户里补充证券亏损时的保证金（得亏全天候策略波动不大），假如3y的市值盈利了14%，那就是4200w，本金是1y，那收益率就是42%。这里举的例子就是“上3倍杠杆”的理想情况，不考虑市值增加带来交易税费和冲击成本。

  

咱来假设ETF也同样可以保证金交易，利用量化平台的融资融券功能（把融资利息降到0），变相实现“上3倍杠杆”的情况，交易费率和滑点保持不变，再跑一遍策略。

  

躺平版全天候策略(可保证金交易)2024年初至今回测收益：

![](assets/023.png)

  

风险平价版全天候策略(可保证金交易)2024年初至今回测收益：

![](assets/024.png)

  

你瞧，之前那两个策略的年化收益不就提升到了42.08%和32.77%了嘛，保证金交易立大功啊，只要再继续提高杠杆，收益还可以提高(但是要确保最大回撤不要打爆保证金)，是不是就跟桥水基金35%的年度收益对上了。

  

终于把之前的坑填了，也希望这篇文章对你理解桥水基金的全天候策略有帮助，下期见~

  

PS：还是老规矩，躺平版和风险平价版全天候策略源码等相关资料，『量化藏经阁』和『量化藏经阁Max』群友请原路径自取，enjoy

  

参考资料：

_Edward Qian，2005，《Risk Parity Portfolios:Efficient Portfolios Through True Diversification》_

_Bridgewater，2011，《Risk Parity is about Balance》_

__中信期货，2020.12，《基于风险平价的资产配置模型》__

_华泰证券，2022.5，《风险平价策略的前世今生》  
_

_国泰君安，2023.5，《桥水全天候策略和风险平价模型全解析》_

兴业证券，2025.2，《桥水全天候策略ETF的创新与桥水中国的逆势崛起》

  

![](assets/025.png)

* * *

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486489&idx=1&sn=7d7d3bed4d6f78c5e9477a7601a49864&scene=21#wechat_redirect)

[量化藏经阁2025](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486497&idx=1&sn=17a679999c0b3aeaf1c0d421f0533a8b&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

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