# 再过一个月，微盘股可能有危险？

量化君 量化君也 2023-12-04 06:06 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c39f96ef5b738cadc3bc92dc0fce9149111350e68b04315c74c5d9cde13beeb7a73e6118430c#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c39f96ef5b738cadc3bc92dc0fce9149111350e68b04315c74c5d9cde13beeb7a73e6118430c#rd)

  

![](assets/001.png)

  

年初至今，上证指数下跌1.87%，深圳成指下跌11.76%，沪深300下跌10.04%，创业板下跌17.92%，北证50下跌2.08%，中证500下跌5.07%，中证1000下跌2.41%，万得全A下跌3.01%，在各大主流市场指数跌跌不休之际，却有一个指数异军突起，年初至今斩获49.1%的正收益。

  

**这个指数就是“万得微盘股指数(8841431.WI)”，为了方便，下文就简称为“微盘指数”**，它于2021年3月8日由万得公司编制发布（跟金融终端Wind是同一家）。微盘指数的收益不止今年亮眼，往年的也很炸裂，把它跟沪深300和万得全A画在一起，你就能感受到它的威力。

  

![](assets/002.png)

  

2010年12月31日，沪深300(红线)是3128.26点，如今是3482.88点，13年累计涨幅11.34%；万得全A(绿线)是2737.57点，如今是4670.12点，累计涨幅70.59%；微盘指数(蓝线)是10705.2点，现如今是285730.91点，累计涨幅2569.09%，换算成年化涨幅大概是28.74%。

  

正是因为这么炸裂的收益，在近期吸引了不少个人和私募的关注，也同时导致了很多微盘基金产品已经停止申购或是限额。除了收益这一点外，变得炙手可热原因还有一个，就是指数的可复现性，因为有的指数只有理论上的意义，而没有实际的交易意义，比如通达信当中的昨日连板指数，谁能一直买入连板的股票呢，这就属于看上去很美好，交易当中实现不了。

  

![](assets/003.jpg)

  

  

这个微盘指数呢，就属于看上去很美好，有可能实现得了的，咱先来看看指数的编制原理：**在全市场当中选股，首先剔除ST、\*ST、退市整理股、首发连板未打开的股票，然后选择其中市值最小的400只股票，最后等权重配置，每日进行更新。**

  

![](assets/004.png)

  

这个指数的编制原理跟主流的市场指数还真是有点儿不同，主要有3点：

  

**（1）市值排名方式不同。**沪深300、中证500那些指数都是选市值靠前的，微盘指数是选市值靠后的。  

  

**（2）加权方式不同。**一般的指数配置大部分都是按照市值/流通市值加权，微盘指数直接就是等权，相当于更加放大小市值效应了。  

  

**（3）更新频率不同。**像沪深300、中证500这样的指数，都是半年调整一次成分股，微盘指数属于是每个交易日都进行调整。

  

**简单来说，这就是相当于你买了400支市值最小的股票，之后每天进行高抛低吸，把原来持仓当中涨多了市值变大(不再是市值垫底的那400支了)的股票卖出去，然后买入下跌市值变小(跌到市值垫底400以内)的股票，如此往复循环。**  

  

微盘指数的编制原理是公开的，假设你有充足的资金，足够买入这400支股票，就能完整复制出指数亮眼的收益吗？我觉得还是有一定的挑战性。  

  

首先要直接面对的就是交易成本的问题，指数就是直接纳入股票，然后计算收益，而咱实际当中买卖股票是要付出交易成本，况且咱每个交易日都要交易。  

  

国联金工做过这方面的测算，假设买卖佣金是万5，印花税是千1，2016年回测至今，净值曲线差别不大，因此交易成本对微盘指数复现的影响不是很大。  

  

![](assets/005.png)

  

  

平均每天的双边换手率是5.5%，不算特别高，400支股票当中，平均每天要调整22支股票，也就是卖出11支，再买回来11支，一年的双边换手率大概是13.3倍。  

  

![](assets/006.png)

  

从交易成本上看，要复现出微盘指数的大部分收益是可能的，但实际交易当中，与指数的理论差别还有很多，比如说股票突然ST，连续跌停卖不出去，指数是剔除ST股了，但实际持仓当中还持有。微盘股一般流动性没那么好，承载不了太大的资金，资金量一大，滑点和冲击成本就会更高，收益就会下降。

  

方方面面的因素我也难以考量周全，拍个脑袋，如果纯粹从复现的角度来讲，个人直觉能复现出5~7成吧，如果你是要从400支股票当中再优选，或是优化权重，构建微盘股增强指数，那又得另当别论了。

  

其实滑点、冲击成本、交易成本什么的，都是“细枝末节”，关键还是得小微盘股的风格延续下去，其他的那些都是赚多赚少的问题。**在风格统计的过程中，发现这个微盘指数上近十几年来，存在着类似“五穷六绝七翻身”的日历效应。**  

  

![](assets/007.png)

  

**统计了自2010年以来，微盘指数每年每个月份的涨跌幅情况，发现1月跟4月就是俩显眼包，这两个月份都是大概率下跌的。**这里要补充说明两点，第一是为什么从2010年开始统计，因为如果将股票按市值规模划分为大、中、小和微盘股的话，数量各自占比25%，那2010年A股才开始有2000支股票上市，微盘指数那市值垫底的400支股票才能占到那垫底的25%当中，才能体现微盘指数的内涵。第二就是，为了统计方便，虽然今年12月份才刚开始有第一个交易日的数据，还没有过完，但也把数值填上去了，数值大小为12月1日涨跌幅乘以20。

  

如果表格不够显眼的话，咱把直方图画出来，下面第一幅图是每个月份的平均涨跌幅，第二幅图是每个月份的上涨概率，可以看出，1月和4月的上涨概率低，而且跌幅显著，**特别是1月份，上涨概率仅有28.57%，平均跌幅为2.58%，如果把**2015年10.02%**和2016年-28.32%这俩最大最小值去除再统计，平均跌幅也有1.48%，现在是2023年12月初，****再过一个月就又是1月份了，从统计数据上看，微盘股好像就有危险了。**

  

![](assets/008.png)

  

![](assets/009.png)

  

最初的时候，我以为微盘股1月份表现差，还有可能是整个市场拖累的，于是又统计了微盘指数相对万得全A的超额收益，发现1月份的超额收益也是负的，看来1月份的平均收益不仅显著为负，而且还跑输市场整体。

  

可惜微盘指数在这种情况下，只有十几年的统计数据，样本不够多，没有严格的统计意义，但可以做个参考，关键咱还是要想明白这统计结果背后的逻辑。  

  

小市值/微盘股的四月之殇，想必不少小伙伴都听说过了，不少人在优化小市值策略时，是会特别过滤掉4月份这个时间段的，道理也很明显，**因为4月是年报密集发布期，很多小市值/微盘股基本面都很“垃圾”，看多了都是雷，以前想象当中的“小甜甜”就成“牛夫人”了。**

  

![](assets/010.png)

  

**小市值/微盘股1月份表现差，目前个人猜测的原因是可能与年报的业绩预告有关**，因为沪深交易所要求，上市公司预计年度经营业绩将出现“净利润为负亏损的”、“实现扭亏为盈的”、“净利润与上年同期相比上升或者下降50%以上”这3种情况之一，应当在会计年度结束后一个月内披露业绩预告，也就是要在1月31日之前披露完毕，作用原理跟“四月之殇”类似。

  

不过这次微盘股1月份是否危险，还要再叠加考虑另外两个因素。

  

第一是外资是否回流。国外加息周期没有结束，美债收益率高企，自今年8月以来，北向资金一直在流出，砸的都是大盘股权重股，人心惶惶不太敢碰这些大票，于是小盘股微盘股成了香饽饽，走出了亮眼的成绩。

  

第二就是私募市值下沉是否结束。现在私募越来越卷，特别是量化私募，中证500不容易做出超额了，就开始卷中证1000，卷完中证1000就开始卷2000，卷完中证2000开始卷微盘，大票信息透明覆盖度高不容易做出超额，就把资金怼向小票，买出了小票微盘的靓丽走势。  

  

**还有一个月，咱拭目以待，如果你自己心里还是没把握的话，那就在二月份再操作吧**，想必细心的小伙伴已经看出来了，还没看出来的小伙伴可以看看我之前的文章[《五穷六绝七翻身？量化分析揭开背后真相》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect)，那可是一个大盘中盘小盘微盘鸡犬升天的月份。

  

**参考资料：**

_德邦证券，2023.4，《微盘股的症结与曙光》_

_华泰证券，2023.8，《小市值与量化的又一次相互成就》_

_国联证券，2023.11，《解析万得微盘股指数：高收益源于市值下沉与交易换手》_

  

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