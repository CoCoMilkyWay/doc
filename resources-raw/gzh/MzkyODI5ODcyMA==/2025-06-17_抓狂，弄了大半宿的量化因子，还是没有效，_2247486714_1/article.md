# 抓狂，弄了大半宿的量化因子，还是没有效，怎么办？

量化君 量化君也 2025-06-17 21:13 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486714&idx=1&sn=e842e731ea1fd7ce911905f07ff3bc84&chksm=c380d93bd4e4d69030292d27d83cab02eb1fa29441e9980f6ec909c397d1846fec5000274baf#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486714&idx=1&sn=e842e731ea1fd7ce911905f07ff3bc84&chksm=c380d93bd4e4d69030292d27d83cab02eb1fa29441e9980f6ec909c397d1846fec5000274baf#rd)

![](assets/001.png)

  

无论是私募研究员，还是个人宽客，开发策略时难免会涉及到因子开发，但经常出现的情况是，自己弄了大半宿，发现量化因子收益不分层，IC也不显著，这就尴尬了，除了抓狂外，还有什么法子呢？

  

从无效到有效，从不行到很行，从耷拉脑袋到勃然昂首，坊间是有一些经验技巧和方法论的，我知道大伙儿都不喜欢听大道理，恰巧最近看到一个很棒的因子改进案例，就当故事讲给大伙儿听吧，姑且言之，姑且听之，一笑了之。

  

在天朝的某家私募里，有一个量化研究员，名字叫做阿Q，为了完成这个月的因子开发KPI，还待在工位上挑灯夜战。

  

话说阿Q前两日看了一篇漂亮国金融工程论文《Overnight returns, daytime reversals, and future stock returns》，get到了一个新因子idea。

  

![](assets/002.png)

  

在证券市场里，有这样一种现象：个股隔夜上涨，但是到了日内，隔夜的涨幅并没能维持下去，还可能转为下跌。这种隔夜与日内时段上的不一致性，是否隐含着某些未被发掘的信息？

  

于是那篇论文的作者就构造了一个『异常负反转频率因子』，因子数值从小到大等分为10组后，因子收益单调性良好，多空收益率显著为正。

  

![](assets/003.png)

  

阿Q就照着论文的步骤，先是计算隔夜收益率和日内收益率。

  

隔夜收益率 = 今日开盘价 / 昨日收盘价 - 1.0

  

日内收益率 = 今日收盘价 / 今日开盘价 - 1.0

  

对于每支个股，如果隔夜收益率为正但日内收益率为负，那么则记为个股发生了一次负反转。然后统计这支个股在一个月里面发生了多少次负反转，将负反转次数除以当月交易日数，那么这个就是负反转频率。

  

负反转频率 = count(隔夜收益率>0 and 日内收益率<0) / count(交易日)

  

进一步地，为了保证因子数值在不同个票间横截面可比，将每支股票当月的负反转频率除以前12个月的负反转频率的均值，便最终得到了『异常负反转频率因子』。 

  

这个因子的底层逻辑是，论文作者认为，隔夜交易主要来自于噪声交易者和信息优势者，而日内交易则套利者更多。如果异常负反因子数值较高，则代表在当月，日内交易的套利者高估了隔夜的噪声或是不认可信息优势者的事件冲击，从而多次且过度修正价格，拉低了股价，产生了较大的偏离，矫枉过正，物极必反，被拉低的股价会向价值靠拢，次月股价上涨的概率较大。 

  

这个因子有计算细节，有逻辑支撑，测试效果良好，正好是下手的优质对象。然而，阿Q把因子复现出来，用A股数据一测，傻眼了，这也没有想象当中好哇。

  

![](assets/004.png)

  

![](assets/005.png)

  

虽说A股里面异常负反转因子总体来说还是与次月收益呈正相关的，但是预测能力并不强，IC值也仅有0.02，并且因子收益最佳组别也不是Top组，多空净值曲线近两年也未呈现上升趋势。

  

阿Q心想，难道这个因子凉凉啦？这个月绩效不能再继续打C了，不然年终奖就泡汤了，就算有，也超不过纯洁心灵逐梦演艺圈的豆瓣评分。鬼叫你穷，顶硬上啊~~~

  

阿Q静下心来，思索这可能是什么原因导致的，对比着A股与美股交易制度的不同，默默在笔记本上写下这3条。

  

（1）美股盘前交易时间是4:00~9:30(连续竞价)，A股的是9:15~9:25(集合竞价)，A股的开盘价可能未充分反映隔夜力量。

  

（2）仅使用反转现象出现的频率构建因子，可能信息量不足，未能完全展示不同投资者间的力量对比。

  

（3）负反转的定义可能较为严格，导致满足的样本占比仅有20%左右，数据量较小可能会影响因子的有效性。

  

对照着这些可能的原因，一条一条进行改进。

  

既然A股开盘价可能无法反映隔夜力量，那就把时间往后推一些，给隔夜力量更多时间，可以使用上午10点钟的价格替代开盘价，那么隔夜收益率和日内收益率就变为：

  

隔夜收益率 = 今日10点钟价格 / 昨日收盘价 - 1.0

  

日内收益率 = 今日收盘价 / 今日10点钟价格 - 1.0

  

阿Q再重新计算一遍异常负反转频率因子，再测试一遍，这都是什么鬼，因子分组收益和多空净值曲线看上去还不如原来。

  

![](assets/006.png)

  

![](assets/007.png)

  

在上面改进的基础上，继续考虑第2个原因，“隔夜上涨，日内下跌”是由于不同类型交易者对信息观点认可度的差异，除了度量出现的频次和频率外，还可以度量各方力量的认可程度和信心强弱，在这方面，成交量是一个很好的指标。

  

举个栗子，如果隔夜上涨且日内反转下跌，并且伴随着成交量的放大，那么这就表示日内交易者对隔夜信息的强烈不认可。于是乎，阿Q又马上构建了一个因子，如下：

  

改进因子 = corr(隔夜收益率 - 日内收益率，日内成交量占比)

  

日内成交量占比 = 10~15点的成交量 / 当日成交量

  

corr(A，B)表示计算序列A和序列B之间的相关性，“隔夜收益率 - 日内收益率”使用“-”号的原因是，改进因子的计算只考虑隔夜收益率为正且日内收益率为负的交易日，隔夜涨幅越大且日内跌幅越大，对应的值就越大。

  

于是乎，改进因子反映的就是刚才说的那种现象“隔夜上涨，日内下跌，日内放量”，越符合这种现象，那么相关系数的值就越大，越接近1.0。

  

阿Q对改进因子测试一遍，发现因子分组收益单调性有所好转，多空净值曲线也是呈现出整体上升的曲线，仿佛看到胜利的曙光了。

  

![](assets/008.png)

  

![](assets/009.png)

  

对于第3个原因，能满足“隔夜上涨且日内下跌”的负反转现象样本数过少，占比在20%左右。可以考虑放宽对负反转的条件范围，比如说只要求隔夜上涨，但日内不需要一定下跌，只要没能维持相同的涨幅，也可以认为是负反转。于是乎，新的因子就诞生了，阿Q将其命名为“隔夜日内拉锯因子”(TOI，Tug of Overnight-Intraday)。

  

隔夜日内拉锯因子TOI = corr(隔夜收益率 - 日内收益率，日内成交量占比)

  

其实计算式子的形式跟上一个因子是一样的，只是考虑的交易日不一样，改进因子考虑的是“隔夜收益率>0且日内收益率<0”的交易日，而TOI因子考虑的是“隔夜收益率>0且隔夜收益率>日内收益率”的交易日，后者涵盖的样本数明显比前者多。

  

话不多说，再来测试一遍，发现因子分组收益严格单调了，多空净值曲线也昂然向上，TOI因子的IC值也达到了0.035，ICIR值为2.75，算是勉强过关了。

  

![](assets/010.png)

  

![](assets/011.png)

  

根据惯例，阿Q还有两个手续要办，一个是参数敏感性测试，另一个就是跟常见因子的相关性分析。

  

阿Q是选了上午10点钟作为隔夜和日内的时间分割点，万一是运气太好恰巧选中参数孤岛过拟合了呢？

  

于是乎，阿Q将上午的交易时段以5分钟为间隔产生时间分界点，依次计算每个时间分界点上的因子表现。 

  

不同分界点的因子IC值和ICIR值

![](assets/012.png)

  

不同分界点的因子多头超额收益与多空收益

![](assets/013.png)

  

从上面两个图看出，无论是对于因子IC值和ICIR值，还是因子多头超额收益率与多空收益率，10~11点都属于参数平原，没有剧烈的起伏和显眼的参数孤岛，选择这里面的时间分界点都是大差不差。

  

做因子相关性分析，是为了识别并剔除高度相关的因子，解决因子之间多重共线性问题，优化模型性能。阿Q已经入库了一些因子，如果新加进去的因子跟原来的因子相关度过高的话，那么也没有啥信息增量，即使表现优异也可能上不了实盘。

  

于是乎，阿Q还需要计算TOI因子与常见量价因子的相关性，相关性表格(单位：%)如下所示，对角线以上的单元格数值为Pearson相关系数(值vs值)，对角线以下的单元格数值为秩相关系数(排名vs排名)。

  

![](assets/014.png)

  

总体而言，与常见量价因子的相关性都不高(第1行和第1列)，其中与小市值的相关性仅有0.70%，相关性最高的是与反转因子，绝对值也只有13.88%.

  

看来，阿Q这一关是真的能过了。

  

以上情节纯属虚构，如有雷同，不胜荣幸！不过因子构建细节和测试结果都是真实的，皆出自西部证券金融工程团队的“手搓因子”系列的第一期研究报告《隔夜上涨和日内反转中的隐藏alpha》，墙裂推荐感兴趣的小伙伴去看原文。

  

下期见~

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