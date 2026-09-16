# 探索利用价格概率密度函数，构建趋势突破策略

量化君 量化君也 2023-01-11 22:57 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c3a3ee766165cfe0fecbf5fd56f54833ecdf320ce2bb0ebc535180d0df21b1f500de04f9a751#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c3a3ee766165cfe0fecbf5fd56f54833ecdf320ce2bb0ebc535180d0df21b1f500de04f9a751#rd)

![](assets/001.png)

  

之前唠过一期文章，探讨了『导数』在量化策略构建当中的用法，没印象的小伙伴可以回顾一下，点击文章标题可以空降直达。

  

[《『导数』在量化策略中的妙用：日内波动极值vs低阶多项式拟合策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)

  

**与『导数』类似，『概率密度』在发现捕捉证券价格趋势方面也有妙用，构建趋势突破策略方面也有明确的交易意义，下面咱就探索性地唠一唠。**

  

说起『概率密度』，很多小伙伴可能没有反应过来，觉得是啥高大上的玩意儿，其实咱在高中的时候就接触过了，我说个词大家肯定能回想起来，那就是：正态分布（又名“高斯分布”）。是不是立马就能想起一条“中间高、两头低、左右对称”的钟形曲线了呢？

  

![](assets/002.png)

  

这条钟形曲线就是正态分布的概率密度曲线，它的具体形态由连续数值的均值和方差控制，如果一个随机变量X服从正态分布，则记为X~N(μ，σ2)，看到这些描述，是不是感觉一股熟悉的感觉迎面扑来。

  

**那在实际当中，如何计算证券价格的概率密度呢？**

  

**那就要利用到直方图了，也就是说，选定一个时间范围，计算每一个价位出现的概率，X轴是价格，Y轴是出现概率，每个价位的概率对应一个柱子，绘制出来的直方图就近似于概率密度曲线了。**

  

如果觉得得太抽象的话，举一个实际的例子吧，统计某证券最近1000个交易日的收盘价直方图，假设最近1000个交易日内，价格变动范围为50 ~ 100元，间隔1元为一个价位，那直方图总共有51根柱子，例如只要收盘价落在62.0~62.99元区间，都属于62这个价位，落在80.0 ~ 80.99区间，都属于80元这个价位，分别有10和40个交易日的收盘价落在62和80价位，那51和80元价位的概率数值就分别是0.01和0.04，其他价位概率以此类推，所有柱子加起来就是1.0，绘制出来的直方图如下所示。

  

![](assets/003.png)

  

要注意的是，证券价格的直方图画出来，虽然一般都是“中间高、两头低”的形态，都不会那么完美到恰好服从正态分布的，但有时为了方(tou)便(lan)，会用相同均值和方差的正态分布近似代替，方便后续计算。

  

**说完『概率密度』，再说『累积分布』就简单多了。在数学上，累积分布函数F是概率密度函数f的积分，积分嘛，简单来说，那就是在指定范围里曲线跟横轴围成的阴影面积，那在证券价格这种离散数值的直方图里，四则运算里的加法就搞定了。**

  

F(x)=P(X<=x)=P(X=X1)+P(X=X2)+...+P(X=Xn)，其中Xn是小于x的最大数值，P(X)是在X价位上的概率，也就是直方图的柱子长度。

  

举例来说，累积分布F(53)表示小于等于53价位的累积概率是多少，把50、51、52和53这4个价位的柱子数值大小加起来就可以了，F(53)=P(50)+P(51)+P(52)+P(53)，以此类推。

  

特别地，假设上文的直方图像正态分布那样对称，均值左右两边是对称的，那么中间价位的累计分布值F(75)=0.5（确切来说是75价位的中点的累积分布才是0.5，为了方便表述，不要在意这些细节啦），概率密度曲线下的概率之和或是说阴影面积之和为1.0，那么F(100)=1.0。

  

![](assets/004.png)

  

搞清楚了『累积分布』的实际意义，那用它构建趋势突破策略的方法就呼之欲出了，可以用“价格中枢”作为切入点。

  

_有人用均线做趋势突破策略，因为均线是近期价格的(加权)平均，可以看成是近期的价格中枢，价格高于价格中枢时，呈现多头趋势。_

  

_有人用MACD做趋势突破策略，可以看做是短期价格中枢(短EMA)与长期价格中枢(长EMA)的比较，DIF大于0时，短期价格中枢在长期价格中枢之上，呈现多头趋势。_

  

_有人用布林带Boll做趋势突破策略，上轨(MA+N\*Std)可以看做是价格中枢外加N倍标准差偏离值，当价格在价格中枢+偏离值之上时，呈现多头趋势。_

  

**类****似地，概率密度的中心价位天然就是当价格中枢的材料，在这一价位上，累积分布F为0.5，如果当前价位F值在0.5之下，可以看成是空头趋势，在0.5之上时，看成是多头趋势。**

  

**并且概率密度和累计分布，除了能衡量价格中枢之外，还能知道当前价格在近期区间的位置。**

  

**在构建实际趋势突破策略的探索中发现，累积分布F多空阈值不一定要用中间值0.5，震荡的时候会频繁上穿下穿中间值，多空阈值可以分开设置，因为高位开空和低位开多相对来说胜率会更高，其次最好加入大周期的趋势过滤，减少无效开仓次数。**

  

按照惯例，选了两个黑色系品种当做小白鼠，用ATR跟踪止盈止损出场，两品种同参数回测曲线如下。

  

![](assets/005.png)

  

看上去还行，不是很拉胯，应该有正向收益预期吧，多品种、多周期、多空和品种参数单独处理应该效果会好很多，这次主要唠一下利用概率密度构建趋势突破策略的大体思路，写得比较粗线条，策略方面也还不够细致，大伙儿多担待，待下次机缘改进吧~

  

_PS：本文『概率密度趋势突破策略』源码已分享至『量化藏经阁』和『量化藏经阁Max』社群内，群友请在社群量化兵器库原路径中自取。_

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484636&idx=1&sn=7eb5b8b8bf6059cb2aa5a5d4f8f44bc2&scene=21#wechat_redirect)

[量化藏经阁2023](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484645&idx=1&sn=6e134dfd927c2e666875021ea97f7092&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect)  [量化兵器库](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

  

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/006.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/007.png)