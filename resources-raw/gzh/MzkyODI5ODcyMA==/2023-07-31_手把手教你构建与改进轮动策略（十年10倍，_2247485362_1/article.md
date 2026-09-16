# 手把手教你构建与改进轮动策略（十年10倍，附源码）

量化君 量化君也 2023-07-31 17:37 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c39f0ea8344561f6c1d3723816a351077d137300889c65bf3573521e870567d38e5ac2daf62e#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c39f0ea8344561f6c1d3723816a351077d137300889c65bf3573521e870567d38e5ac2daf62e#rd)

![](assets/001.png)

  

**一、说在前面的话**  

众所周知，股票、债券、商品等投资市场存在着各种各样明显的轮动效应，最常见的有3种。

  

**第一种是资产轮动**，也就是大类资产间的轮动，在不同的市场/宏观环境下，配置不同的类别的资产，可以获得更显著的投资收益，比如资产配置中最经典的美林时钟，按照经济增长与通胀将经济周期划分为4个阶段，每个阶段都有最适合的投资品种：衰退期买债券，复苏期炒股票，过热期投大宗商品，滞涨期持现金。对了，常见的股债轮动策略也是属于这个类别。

  

![](assets/002.jpg)

  

**第二种是行业轮动**，也可以称之为板块轮动，说的就是各行业/板块在相同时期会表现出差异性，各自支棱的时间不同步，因此可以通过不同时期配置不同行业/板块，从而博取高于市场基准的投资收益。

  

![](assets/003.png)

  

**第三种就是风格轮动**，跟行业轮动和板块轮动原理类似，只不是走强的不是轮动/板块，而是某类投资风格，比方我们常见的大小盘轮动、成长价值轮动就属于这种，晨星的投资风格箱就是按此划分的。

  

![](assets/004.png)

  

第一种是各类资产之间的轮动，后两种更多的是某类资产(如股票)内的轮动，不过抽象出来，它们都是具有价格走势的证券/品种，只要它们有价格走势，就可以非常容易地构建出轮动策略，核心因素有两个。

  

**第一个是候选池，也就是在哪个“池子”里面进行轮动**，是在股票、债券、商品、现金里面进行轮动呢，还是在大小盘风格里面进行轮动，这需要咱一开始就进行框定。

  

**第二个就是强弱排序，也就是采用什么方法规则对池子里面的品种进行排序**，每期买入最强的那个或前几个品种，就跟和联胜社团每两年要选举一次那样，是靠叔父辈发话，还是靠才智拳头，拿到龙头棍，当上坐馆。

  

这些问题，咱都会在本篇文章内解决，就不扯闲篇儿了，赶紧一起出发，let's go~哦，对了，记得戴上头盔~~

  

**二、轮动策略构建**  

**1.候选池确定**  

**第一步咱先要确定轮动策略的候选池，后面的所有步骤都是围绕着这个候选池展开的**，为了讲解方便，最开始先构建A股里面常见的风格轮动，后续要换成别的轮动形式，只要更换里面证券代码列表就可以了。

  

在大小盘风格轮动中，常用沪深300指数代表大盘风格，中证500指数代表小盘风格，为了体现可交易性，这里用的是ETF（Exchange Traded Fund，交易型开放式指数基金），沪深300ETF代码是510300，中证500ETF代码是510500。

  

其实现在代表小盘风格，感觉中证1000指数更为合适，但是中证1000ETF从2016年底才开始，数据不够10年，不方便长期回测，于是还是用中证500，这些细节不用太在意，理解整个轮动策略的框架和回测思路就可以了。

  

在价值成长风格轮动中，个人喜欢用红利ETF（代码：510880）代表价值风格，创业板ETF（代码：159915）代表成长风格，这里没有太死板的规定，根据个人的理解和喜好来决定就可以了。

  

**至此，咱有了风格轮动策略的候选池：沪深300ETF（510300），中证500ETF（510500），红利ETF（510880），创业板ETF（159915）。**再啰唆一句，候选池的确定没有什么条条框框，全凭自己的对交易的理解和喜好，例如你就放余额宝和银华日利都可以，只要能取到序列数据。

  

**2.数据获取**  

有了候选池，把池子里面证券标的数据取出来就可以了，**这里还是用到老朋友股票量化开源库qstock，直接使用“pip install qstock”就可以安装，无需注册就可以直接使用。**在这里，咱取得是这4个ETF的收盘价序列数据。  

  

```
import qstock
```

  

qstock与其他量化库的区别就是，返回的数据列名是证券的名称，而不是证券的代码，注意这一点就好。  

  

![](assets/005.png)

  

**3.数据计算**  

**轮动策略的第二个核心就是强弱排序，这里采用的是动量策略的规则，每天买入前N个交易日涨幅最大的那一个ETF**，因此需要计算出每个ETF在每一天的前N个交易日的涨幅。  

  

为了方便后面的回测，还需要顺带计算出每个ETF的日涨幅，计算代码和运行结果如下。

  

```
# 动量长度
```

  

![](assets/006.png)

  

**4.信号生成与回测**  

经过上一步的计算，**咱就知道了每一天所有ETF的区间涨幅，就可以筛选出涨幅最大的那个ETF，根据这个信号买入这个最强的ETF，作为轮动策略的持仓。**

  

知道了策略每一天的持仓，就知道策略每一天的收益率，采用连乘的方式进而计算出策略的净值曲线，有了这条净值曲线，就可以统计出回测的各项绩效指标。  

  

```
# 取出每日涨幅最大的证券
```

  

![](assets/007.png)

  

这里需要特别说明两点，第一点是交易信号列要前移1格（对应第4行代码当中的shift），因为策略今日的涨跌幅/收益率是由昨日的持仓产生的，这里其实也暗含着一个回测设定，就是当日收盘价计算交易信号当日收盘价成交，如果前移2格就是当日收盘价计算交易信号明日收盘价成交。

  

第二点就是回测第一个交易日收益率为0，这跟第一点暗含的设定有关，当日收盘价才成交产生持仓，故第一个交易日收盘前没有持仓，不纳入信号证券的涨跌幅，收益率为0。

  

**5.结果统计和画图**  

经过上一步，终于回测计算出轮动策略的净值曲线了，咱先把这4个ETF和策略净值都画出来，直观对比一下。  

  

```
import matplotlib.pyplot as plt
```

  

![](assets/008.png)

  

图中那条黄色实线就是轮动策略的净值曲线，它最终跑赢了这4个ETF中的任何一个，实现了通过轮动配置增强了策略收益。  

  

**光看净值曲线还不够，还需要获得收益率、夏普率等回测统计指标信息，在这里，咱可以通过量化工具库quantstats快速实现**，导入该库后，可以通过reports.html函数生成html格式的完整回测报告，也可以通过reports.basic函数输出基本的回测报告信息，也还有很多类似的函数，有空可以逐一去探索。

  

```
import quantstats as qstat
```

  

输出的部分结果截图：  

  

![](assets/009.png)

  

![](assets/010.png)

  

![](assets/011.png)

  

第一幅图显示的是回测当中的各种统计指标，其中关键的是，策略累计收益率(Cumulative Return)是261.7%，年化收益率(CAGR)是9.56%，比基准沪深300ETF的年化收益4.75%要差不多高出了5个百分点，策略的夏普率(Sharpe)为0.65，也高于基准的0.43，不过最大回撤(Max Drawdown)达到了63.15%，超过了基准一大截，不是大心脏真抗不下来。

  

第二幅图是轮动策略和基准的累计收益率曲线，第三幅图是策略相对基准每个月的超额收益，这个就很直观了，就不用过多解释了。

  

**三、轮动策略改进1**  

初版的轮动策略咱已经完成了，虽然能跑赢基准，但是各项回测统计指标看上去还有很大的提升空间，革命尚未成功，同志仍需努力~  

  

还记得轮动策略的两个核心吗？一是候选池，二是强弱排序，要改进，可以先从候选池下手。  

  

侯选池的重要性不言而喻，因为后续所有的动作都是围绕着侯选池展开的，就跟从中国足球队随机挑选球员，还是从巴西足球队随机挑选球员去点球一样，底子好的自然胜率高。

  

比如说，咱除了A股之外，还考虑国外市场，选入代表漂亮国的纳指ETF（代码：513100），还考虑大宗商品市场，于是选入黄金ETF（代码：518880），同时剔除原来候选池当中的沪深300ETF和中证500ETF，**于是整个候选池就变为：红利ETF（510880），创业板ETF（159915），纳指ETF（513100），黄金ETF（518880）。**于是乎，获取数据部分的代码做出对应的调整。

  

```
import qstock
```

  

![](assets/012.png)

  

咱按照原始策略的流程重新回测一遍，注意在回测结果统计的部分要将原来的沪深300ETF修改成纳指ETF。  

  

![](assets/013.png)

  

![](assets/014.png)

  

![](assets/015.png)

  

从结果图中可以看出，修改候选池后的轮动策略的回测绩效取得了明显的提升，**累计收益率达到了十年10倍，年化收益率从原来的9.56%提升到了18.69%，接近翻了个倍，夏普率也从原来的0.65提高到了1.19，最大回撤也从原来的63.15%降低到了30.30%，打了对折。**

  

**四、轮动策略改进2**

**候选池改过了，咱接下来就是改强弱排序，还是保存动量规则不变，原来采用的是区间涨跌幅，这次改进则打算采用区间走势**，候选池依旧是上一步改进策略的候选池：红利ETF（510880），创业板ETF（159915），纳指ETF（513100），黄金ETF（518880）。  

  

区间走势用什么指标来衡量呢？这里借鉴RSRS指标的构建思路，用收盘价序列的斜率来表征，斜率越大，走势越猛越强。  

  

同时也引入决定系数R2的概念，它是对线性拟合效果好坏的判断指标，取值范围一般在0~1之间，数值越大，表示线性拟合的效果就越好，当直线能完美拟合所有数据点时，取值为1，更详细的说明可以见之前的文章[《(续)复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)。

  

**于是强弱规则就修改为“斜率和决定系数的乘积”，乘积作为ETF动量强弱的得分，得分数值越高，就表示动量越强，每日都选入强弱得分最高的ETF**，数据计算部分的代码也做出相应的调整。  

  

```
from sklearn.linear_model import LinearRegression
```

  

![](assets/016.png)

  

在强弱得分计算当中，有两点要补充说明，**一是在斜率计算时，要每次都对收盘价序列“归一化”**，因为ETF的数值范围不一样，会导致即使相同走势，斜率也不一样，比如说，序列y1=\[1,2,3,4\]和y2=\[2,4,6,8\]分别都对x=\[1,2,3,4\]求斜率，前者的斜率值是1，后者是2，其实它们的走势都是一样的，涨幅也是一样的。

  

二是计算强弱得分求乘积时，乘以了系数10000，那个只是为了让数值“好看”一些，更像是得分的范畴，横截面比较，同时都乘以一个任意正实数，都不影响排序。  

  

之前是按照区间涨幅排序，现在是改为强弱得分排序，重新回测一遍，记得第4步信号生成与回测中的“涨幅”要改为“得分”。  

  

![](assets/017.png)

  

![](assets/018.png)

  

![](assets/019.png)

  

从结果图中看出，改进策略2在改进策略1的基础上又取得了进一步的提升，**累计收益率从十年10倍提升到了十年14倍，年化收益率从18.69%提升到了21.23%，夏普率从1.19提升到了1.34，关键是最大回撤从30.3%下降到了27.64%，比基准的回撤还要低了。**

  

为了更直观地对比改进结果，咱把原始策略、改进策略1和改进策略2都放在一张图里面进行展示，绩效对比一目了然。  

  

![](assets/020.png)

  

**五、总结和补充说明**  

咱戴上头盔撸起袖子终于吭哧吭哧干完了，走通了从零开始构建轮动策略的全流程，并且进行了两番改进，从十年2.6倍提升到了十年14.8倍，虽然效果看起来很不错，但仍然存在一些不足。

  

一是为了方便回测，是按照当日收盘价计算信号并且按收盘价交易的，虽然这在实际当中可以在尾盘近似实现，但依然会存在差距。

  

二是在回测当中并没有考虑滑点和费率，这也是为了方便回测当中的计算。  

  

三是候选池的选取，这也是所有轮动策略中最大玄学部分的存在，像改进策略1一样，候选池选对了，年化收益直接翻倍，你可以将本文当中所有候选池的选取都当做是我的主观臆断，后面存在失效的可能。

  

**本文主要还是让大伙儿快速感受和上手轮动策略的构建过程，有好的idea了，可以快速地进行回测，验证思路，如果有惊艳的结果产生，仍需细细验证，有什么到不到的地方，望大伙儿多多包涵。**

  

**参考资料：**  

_中泰证券，2022.08，《资产配置深度报告：重新认识美林时钟》_

_湘财证券，2022.04，《综合评价模型在 ETF 行业配置上的应用：基于动量策略在行业轮动中的应用研究》_

_湘财证券，2023.03，《基于动量和反转的行业轮动策略》_

  

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

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

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

![](assets/021.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/022.png)