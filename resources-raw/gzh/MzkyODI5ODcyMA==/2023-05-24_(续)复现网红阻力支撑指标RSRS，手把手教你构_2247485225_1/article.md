# (续)复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略

量化君 量化君也 2023-05-24 07:27 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c312586aa606255bd0ca98b736609c56b943b8bcd7ebef5eb0dcd9a985b985af4b6230085764#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c312586aa606255bd0ca98b736609c56b943b8bcd7ebef5eb0dcd9a985b985af4b6230085764#rd)

![](assets/001.png)

  

前文再续，书接上回，之前讲过光大金工的研报《基于阻力支撑相对强度的市场择时》，并对其中的阻力支撑相对强度RSRS指标/策略进行了复现，最终结果跟研报当中的一致，庆幸木有翻车。  

  

![](assets/002.png)

  

**但那篇研报的核心分为3个部分，首先是RSRS概念的提出以及斜率策略和标准分策略的构建，接下来就是对标准分策略进行优化，提出了优化标准分策略和右偏标准分策略，最后就是将前面筛选出来的最优策略，再结合量价数据进行优化。**

  

上一篇文章《复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略》主要复现的就是这篇研报当中的第一部分，我向来是既挖坑又填坑的新时代三好青年，没错，今儿个就来复现第二部分，还是像之前一样，从数据获取、计算细节到策略构建全都有，不藏着掖着，每一步都有对应代码。

  

**一、RSRS策略构建回顾**

由于前后两篇文章的间隔有点儿久了，先帮已经淡忘的小伙伴回顾一下关键概念，具体完整的细节详见前文《复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略》。

  

**1.RSRS斜率指标/策略**

**RSRS当中最底层的变量就是最高价序列和最低价序列的的斜率，这是构建RSRS斜率策略和标准分策略的基础。**

  

RSRS的具体计算步骤是，首先获取N日最高价和最低价的价格序列，然后对最高价和最低价序列进行最小二乘法(OLS)线性回归，每日滚动进行，其中beta值就是斜率，最后这个斜率值beta就会被作为“RSRS斜率值”

  

```
最高价 = alpha + beta×最低价
```

  

![](assets/003.png)

  

当RSRS斜率值很大时，支撑强度大于阻力强度，从图形上看就是，最高价的变动速度比最低价的要快，阻力逐渐减小，上涨空间大。

  

![](assets/004.png)

  

当RSRS斜率值很小时，阻力强度大于支撑强度，从图形上看就是，最高价的变动速度比最低价的要慢，上涨逐渐减缓，势头受阻见顶。

  

![](assets/005.png)

  

于是乎，**最初始的RSRS斜率策略的核心逻辑非常朴素，就是“RSRS斜率值大于1.0的时候，买入持有；RSRS斜率值小于0.8，卖出平仓”，现实当中对应的交易标的可以是300ETF或IF股指期货。**

  

![](assets/006.png)

  

**2.RSRS标准分指标/策略**

但由于市场不同时期，斜率的均值（中枢位置）会有比较大的波动，因此使用固定数值作为买入卖出阈值则不太妥当。

  

因此，研报当中提出了将原来的“RSRS斜率”转换为“RSRS标准分”，也就是在每个交易日，以M个交易日为观察期（默认M=600），将RSRS斜率做一个Z-Score标准化（即“（当前值-均值）/标准差”），便可以得到RSRS标准分，它能更加灵活地适应市场波动带来的斜率均值的变化。

  

**于是RSRS标准分策略构建逻辑便转换为：当RSRS标准分大于0.7时，买入并持有，当RSRS标准分小于-0.7时，则卖出平仓。**

  

![](assets/007.png)

  

**3.以上两个策略的复现结果**

将上述两个策略实现之后，**跑出回测净值曲线放在一起对比观察，RSRS标准分策略看起来要比RSRS斜率策略要好不少，这也就是为什么第二部分选择在标准分策略的基础上进一步进行优化了，**优中选优嘛。

  

![](assets/008.png)

  

**二、线性拟合的决定系数**

要对RSRS标准分策略进行优化，这里需要首先引入和介绍一个重要的数学概念，那就是对线性拟合效果好坏的判断指标——决定系数R2，坊间一般称为“R方”，计算公式如下。

![](assets/009.png)

其中，y是真实值，y横线是平均值，y三角是预测值。对应到RSRS斜率计算中，y就是最高价数值，头上有横线的y就是最高价y的平均值，头上有小三角的y就是线性拟合后根据最低价计算出来的最高价预测值。

  

**决定系数R2的取值范围一般在0~1之间，数值越大，表示线性拟合的效果就越好，当直线能完美拟合所有数据点时，取值为1。**

  

为什么研报要引入决定系数R2这个数学概念呢？

  

因为所有RSRS策略的底层都依赖于斜率计算，用这个斜率来量化支撑阻力的相对强度，这个斜率是用最小二乘法线性拟合出来的，拟合的效果好不好就至关重要了。

  

要计算决定系数R2也非常简单，通过免费的机器学习库sklearn就可以了，使用从sklearn.metrics导入的r2\_score函数。

  

像之前一样，假设有18个二维的数据点，横轴X轴的坐标是1~18的等差数列，纵轴Y轴的坐标依照y=2\*x\_noise+1生成，x\_noise是在横坐标x的基础上加入了随机数噪声，在这里，X轴数值对应的就是RSRS计算中的最低价，Y轴对应的就是最高价。运行程序，决定系数R2是0.9753。

  

```
import numpy as np
```

  

![](assets/010.png)

  

为了生动感受一下决定系数R2的变化，咱将加入的随机数噪声幅度增加为原来的3倍，也就是将“x\_noise = x + np.random.randn(N)”修改为“x\_noise = x + 3 \* np.random.randn(N)”，再运行一遍。

  

![](assets/011.png)

  

可以看到数据点变“凌乱”了，拟合的效果就没有之前那么好了，决定系数R2降低为0.7814。你也可以继续修改随机数噪声的幅度倍数，感受一下决定系数的动态变化过程。

  

**三、RSRS优化标准分策略**

**RSRS优化标准分策略说起来也很简单，就是在原始标准分策略的基础上，将原始的标准分数值与决定系数R2相乘，得到修正标准分，最后再根据修正标准分进行交易。**

  

目的是打算通过这种方法，削弱拟合效果对策略的影响，具体来说，就是以此降低绝对值很大，但实际拟合效果很差的标准分对策略的影响。

  

打个不恰当的比方，就好比针对某只股票，我说它在三个月内有90%的概率会涨，巴菲特老爷子说它只有60%的概率会涨，你们会更相信谁？相信他的底层逻辑，往往就是因为他之前做得不错，对股市的“拟合效果”好。

  

明白了这层道理，咱就撸起袖子开干吧~

  

**第一步，巧妇难为无米之炊，跟研报一样，先来获取沪深300指数从2005年至今的开高低收行情数据，并且为了回测方便，在这里还计算了每日涨跌幅(pct)，这里使用的是股票量化开源库qstock**，“pip install qstock”安装后，基本的功能无需注册便可以使用，萌新使用起来纵享丝滑。

  

```
import qstock as qs
```

  

![](assets/012.png)

  

**第二步，这里的关键是计算每一日的斜率值beta和决定系数R2。**跟之前的复现一样，咱还是直接从Python免费机器学习库Scikit-learn（简称sklearn）中导入LinearRegression求解，这里要注意的是，训练集必须是二维数组（矩阵）的形式，也就是每个样本对应的是一个向量，即使这个向量只有一个数值，这里使用reshape函数快速将n维向量转换为n x 1维矩阵。

  

为了简单方便计算出每一日的斜率值beta和决定系数R2的日序列，这里采用列表推导式的方法计算，在沪深300指数的行情数据上，对每个交易日滑动(rolling)计算18(研报默认)个交易日最高价vs最低价的斜率和R2就可以了。

  

```
def calculate_beta(df, window=18):
```

  

![](assets/013.png)

  

**第三步，根据斜率beta和决定系数R2计算标准分(std\_score)和优化标准分(mdf\_std\_score)，其中优化标准分为标准分和决定系数R2的乘积。**

  

```
M = 600 # 观察周期
```

  

![](assets/014.png)

  

咱来看看标准分和优化标准分的差异在哪里，分布形态是怎么样的？

  

**标准分数据统计代码和分布：**

  

```
print('均值：%.4f' %data3['std_score'].mean())
```

  

![](assets/015.png)

  

**优化标准分数据统计代码和分布：**

  

```
print('均值：%.4f' %data3['mdf_std_score'].mean())
```

  

![](assets/016.png)

  

从两幅数据分布形态，以及偏度和峰度对比中可以看出，优化后的标准分更接近于正太分布。

  

**第四步，有了RSRS优化标准分之后，便可以进行策略构建，与之前的RSRS标准分策略类似，当RSRS优化标准分大于0.7时，买入并持有，当RSRS优化标准分小于-0.7时，则卖出平仓**，策略源码和回测净值曲线如下所示。

  

```
buy_thre = 0.7 # 买入阈值
```

  

![](assets/017.png)

  

RSRS优化标准分策略年化收益只有15.03%，比不上优化前的标准分策略18.73%（见上一篇复现），优化后收益率反而下降了，在研报的第16页有原因拆解，简单来说，就是优化了的那部分用不上(不做空只做多)，还牺牲了一部分“既得利益”。**手上还没有这篇研报的小伙伴，可在本公众号『量化君也』后台回复暗号『RSRS』便可以保存下载阅读。**

  

**四、RSRS右偏标准分策略**

一计不成，又生一计，继续优化，将上一节的修正标准分与斜率值相乘，得到右偏标准分，主要是通过当前(优化)标准分数值与未来10个交易日的市场涨跌概率和预期收益的统计分析发现的，详见研报第14页开始的统计分析过程，不然篇幅就太长了。

  

![](assets/018.png)

  

**在RSRS右偏标准分策略当中，斜率计算点个数N从18改为了16，观察期M也从600改为300，于是之前的斜率和决定系数R2都需要重新计算。**

  

```
# 去除斜率列和决定系数列，因为要重新计算
```

  

![](assets/019.png)

  

**计算完斜率和决定系数R2后，就可以重新计算标准分(std\_score)和优化标准分(mdf\_std\_score)，进而得到右偏标准分(rsk\_std\_score)。**

  

```
M = 300 # 观察周期，与前面策略不一样
```

  

![](assets/020.png)

  

![](assets/021.png)

  

**RSRS右偏标准分策略与之前的优化标准分策略类似，只是把其中的右偏标准分替换掉优化标准分，当RSRS右偏标准分大于0.7时，买入并持有，当RSRS右偏标准分小于-0.7时，则卖出平仓**，策略源码和回测净值曲线如下所示。

  

```
buy_thre = 0.7 # 买入阈值
```

  

![](assets/022.png)

  

RSRS右偏标准分策略的年化收益率为18.19%，跟优化前的标准分策略差不多，净值曲线的走势也很像，为了方便对比，那咱把RSRS标准分、优化标准分和右偏标准分这3个策略的净值曲线放在一起对比一下，如下所示。

  

![](assets/023.png)

  

可以从图中看出，修正标准分策略的效果是最差的，右偏标准分策略的结果跟标准分策略的结果很想近，但具体看到数值层面，标准分策略要比右偏标准分策略好一丢丢，这跟原始研报当中的结果恰好相反，大家都是修正标准分策略最差，但在研报当中，右偏标准分策略要好于标准分策略。

  

![](assets/024.png)

  

难道是复现有误？但是将回测时间范围设置到与研报一致时，答案就豁然开朗了。

  

![](assets/025.png)

  

复现的策略优劣排序与研报是一致的，的确是最终优化出来的右偏标准分策略最好，只不过这篇研报是在2017年上半年发布的，距今已经6年，这6年都算是样本外数据，右偏标准分策略在2022年初之前这5年时间里(发布后)，基本都是好于标准分策略，只不过最近1年的下跌又让它抽抽回去了，将来再次超越未可知焉？

  

**五、补充和总结**

再重复唠叨补充说明一下，原始研报中可能隐含了两处“未来函数”，第一处是买入卖出阈值的确定，文中是统计了全部数据集的数值（例如斜率值beta）分布再确定阈值的，相当于是用训练集训练模型，然后又让模型预测训练集，幸好这篇研报发布已经有6年时间了，可以当做是样本外数据。

  

第二处就是买卖时点的确定，当天出信号之后当日收盘价成交，虽然只要当日K线不出现“光头”或“光脚”，可以大概率近似实现，但与实盘情况还是有一定差距，只是回测起来非常方便。原版研报当中没有明说，仅为个人猜测和看法，因为这种方式回测结果与研报最接近。

  

总体来说整篇研报还是瑕不掩瑜，RSRS指标带有一定的创新性，不少小伙伴看了都觉得有启发，本次重点是在“复现”，于是也遵从了这两处设定。

  

RSRS研报当中的第二核心部分也复现出来了，幸好总体结果跟原始研报还是一致的，暂时还没有翻车，希望可以给小伙伴们说清楚一些RSRS指标/策略具体的计算细节，也让大伙儿少走一些弯路，节省一些精力。**如果对你有帮助，可以点个充满鼓励的『赞』告诉我，接着把RSRS后续系列肝完。**

  

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

[RSRS](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/026.jpg)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/027.png)