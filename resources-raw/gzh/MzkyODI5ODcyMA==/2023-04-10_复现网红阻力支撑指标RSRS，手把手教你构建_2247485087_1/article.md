# 复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略

量化君 量化君也 2023-04-10 22:20 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c358f23e1564fbf8fc79b7114a2be4c48c99c8115b8971596e4dd5c033ab9c2acaf1e8279869#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c358f23e1564fbf8fc79b7114a2be4c48c99c8115b8971596e4dd5c033ab9c2acaf1e8279869#rd)

![](assets/001.png)

  

之前写过一篇利用RSRS指标做ETF轮动的文章，可能是因为回测绩效看起来还不错，其后就有不少小伙伴陆陆续续来询问，想不到还有那么多人关注，于是本期文章就想掰开了揉碎了唠唠RSRS，从数据获取、计算细节一直聊到策略构建，不藏着掖着，每一步都有对应代码。

  

![](assets/002.png)

  

我当初关注到RSRS，是因为当时无论是做股票和ETF的，还是做期货CTA或者是大饼的圈子，都有不少人提到它，它被提及的频次仅次于MACD，说是网红指标也毫不为过，好奇心被勾起来了，就去细细研究和向大神们学习呗，于是乎才有了当时那篇ETF轮动的文章。

  

闲白说完，现在开始入活~~~

  

**1.RSRS的来源和思想**

**RSRS指标的全称是“阻力支撑相对强度（Resistance Support Relative Strength）”，它诞生于光大证券在2017年劳动节发布的金工研报《基于阻力支撑相对强度的市场择时》**，这个系列的研报有好几篇，目录放在文末参考资料那里了，想看的小伙伴在本公众号后台回复暗号『**RSRS**』便可以保存下载阅读。

  

![](assets/003.png)

  

具体的渊源和概念可以参照原版研报，如果只想听个大体思路的话，暂且听我之前的闲话唠一唠。

  

刚开始做交易的时候，总会听到一些"专家"预测点位，说大盘的阻力位在哪，说某只股票的支撑位在哪，各有各的理由，众说纷纭，但是预测的点位也是"一千个人眼里有一千个哈姆莱特"，不知道谁说的对。

  

后来慢慢发现，无论是在开发股票策略还是CTA策略，都不知不觉的使用了阻力和支撑的概念，比如说在做趋势策略之时，突破上轨做多，突破下轨做空，这个上下轨其实就类似于阻力线和支撑线，向上突破了阻力线后，广阔天地，大有可为，就开多仓，向下突破支撑线后，失去靠山，一泻千里，则开空仓或平仓。

  

![](assets/004.png)

  

有的时候，阻力线和支撑线并不是分开的两条线，也可以是一条线，这条线既可以是阻力线，也可以是支撑线。

  

就拿很多萌新入门常用的单均线策略来说，价格上穿20日均线做多，价格下穿20日均线做空，在这里，这根20日均线既是阻力线也是支撑线。价格在均线下方之时，均线便是阻力线，向上突破则做多，反之，价格在均线上方，此时均线则化身为支撑线，当价格失去支撑时则做空或平仓。

  

那问题来了，怎么找到阻力位和支撑位呢？听网上那些“专家”的预测吗？当然不是啦~

  

其实我们每天看K线图，“公认”的阻力和支撑就蕴含在里面，那就是K线的最高价和最低价，不要脸地说，这两个价格是经过万千交易者充分交易后的博弈结果，所有的成交价格都包含在了最高价和最低价形成的空间里，在最高价这条阻力线之下，在最低价这条支撑线之上。当然了，光用1天的最高价和最低价当然不行，可以用序列值。

  

![](assets/005.png)

  

假设我们已经有了相对靠谱的阻力位和支撑位，那应该怎么使用呢？像上下轨突破策略那样使用吗？

  

可以换一个思路，**这就是RSRS的创新点所在，不直接使用阻力位和支撑位这种绝对阈值方式，改为使用相对强度的方式。**

  

就好比是，绝对阈值方式就是预测清华北大的学生能否将来年入百万千万，相对强度方式则是预测清华北大的学生收入将来是否超越双非院校的学生，这两者都不是绝对事件，但两者的预测难易程度一目了然，这个比方不是很恰当，是我能想到的最好的了，只是用来说明，让大伙儿更好地体会（惶恐狗头保命状ing）。

  

![](assets/006.png)

  

**2.RSRS斜率指标和策略**

现在说清楚了阻力位和支撑位的代理变量，和指标构建的核心思想，那再来唠唠RSRS的具体计算步骤和细节。

  

![](assets/007.png)

  

**首先，获取N日最高价和最低价的价格序列，然后，对最高价和最低价序列进行最小二乘法(OLS)线性回归，每日滚动进行，其中beta值就是斜率。**

  

```
最高价 = alpha + beta×最低价
```

  

![](assets/008.png)

  

其中斜率值beta表示最高价相对最低价位置变化的程度，也就是说，当最低价变化为1的时候，最高价变动多少。

  

当斜率值beta很大时，支撑强度大于阻力强度，从图形上看就是，最高价的变动速度比最低价的要快，阻力逐渐减小，上涨空间大。

  

![](assets/009.png)

  

当斜率值beta很小时，阻力强度大于支撑强度，从图形上看就是，最高价的变动速度比最低价的要慢，上涨逐渐减缓，势头受阻见顶。

  

![](assets/010.png)

  

**最后，这个斜率值beta就会被作为当日的RSRS值，确切来说应该是“RSRS斜率指标值”，因为后文会对指标不断改进，RSRS的含义会更加多样丰富。**

  

RSRS的计算步骤和流程说完了，光说不练假把式，咱撸起袖子开干吧，从数据获取、指标计算和策略构建全部用代码实现和展示。

  

**第一步，对照原版研报，获取沪深300指数从2005年至今的开高低收行情数据，这里使用的是股票量化开源库qstock**，“pip install qstock”安装后，基本的功能无需注册便可以使用，萌新使用起来也非常丝滑。

  

```
import qstock as qs
```

  

![](assets/011.png)

  

**第二步，这里的关键是计算每一日的斜率值beta**，这里先给量化萌新说一个简单具体的例子，懂最小二乘法OLS的小伙伴可跳过。

  

假设有18个二维的数据点，横轴X轴的坐标是1~18的等差数列，纵轴Y轴的坐标依照y=2\*x\_noise+1生成，x\_noise是在横坐标x的基础上加入了随机数噪声，在这里，X轴数值对应的就是RSRS计算中的最低价，Y轴对应的就是最高价，具体分布如下。

  

```
import numpy as np
```

  

![](assets/012.png)

  

  

虽然有噪声的干扰，咱都知道它们的底层关系就是一条二维直线y=beta\*x+alpha，其中beta=2是斜率，alpha=1是截距，最小二乘法OLS的作用就是根据已知的坐标数值，计算出斜率和截距。

  

在这里为了方(tou)便(lan)，咱还是直接从Python免费机器学习库Scikit-learn（简称sklearn）中导入LinearRegression求解，这里要注意的是，训练集必须是二维数组（矩阵）的形式，也就是每个样本对应的是一个向量，即使这个向量只有一个数值，这里使用reshape函数快速将n维向量转换为n x 1维矩阵。从最终结果看出，解出来的斜率为1.907，跟实际值还是非常接近的。

  

```
from sklearn.linear_model import LinearRegression
```

  

![](assets/013.png)

  

解单个序列的斜率值咱搞定了，在沪深300指数的行情数据上，**咱只需要每个交易日滑动(rolling)计算18个交易日最高价vs最低价的斜率就可以了，为什么N=18呢，因为这是原版研报中在2017年定的最优参数，本期文章以复现为主，因此尊重历史客观事实按照原始参数。**

  

```
def calculate_beta(df, window=18):
```

  

![](assets/014.png)

  

现在咱们有了历史上每个交易日的beta值，也就是RSRS值，**在这第三步里就可以构建针对大盘沪深300指数的量化择时策略了，这个策略的逻辑非常简单，就是“RSRS值大于1.0的时候，买入持有；RSRS值小于0.8，卖出平仓”，现实当中对应的交易标的可以是300ETF或IF股指期货。**

  

有的小伙伴可能会好奇，为什么买入阈值是1.0、卖出阈值是0.8呢？原文当中的确定方法是，根据RSRS均值加减一个标准差形成的。

  

![](assets/015.png)

  

重新统计一下目前的数据，统计值和斜率分布如下，发现RSRS均值还是在0.9左右，标准差也还是在0.1左右，故买入阈值仍然可以定为1.0，卖出阈值定为0.8。

  

```
print('均值：%.3f' %data['beta'].mean())
```

  

![](assets/016.png)

  

买入卖出阈值确定后，RSRS值若大于1.0，买入并持有，RSRS值跌破0.8后，则卖出平仓，为了方(tou)便(lan)尊重原版研报不考虑费率影响，策略源码和回测曲线如下，总体下来比买入并一直持有基准指数要好。

  

```
buy_thre = 1.0  # 买入阈值
```

  

![](assets/017.png)

  

**3.RSRS标准分指标和策略**

但由于市场不同时期，斜率的均值（中枢位置）会有比较大的波动，季度均值(蓝线)和年度均值(红线)如下所示，因此使用固定数值作为买入卖出阈值则不太妥当。

  

![](assets/018.png)

  

于是乎，**研报当中提出了将原来的“RSRS斜率”转换为“RSRS标准分”，也就是在每个交易日，以M个交易日为观察期（默认M=600），将RSRS斜率做一个Z-Score标准化（即“（当前值-均值）/标准差”），便可以得到RSRS标准分**，它能更加灵活地适应市场波动带来的斜率均值的变化。

  

![](assets/019.png)

  

有了RSRS标准分之后，便可以构建新策略，与之前的RSRS斜率策略类似，**当RSRS标准分大于0.7时，买入并持有，当RSRS标准分小于-0.7时，则卖出平仓**，策略源码和回测净值曲线如下所示。

  

```
M = 600 # 观察周期
```

  

![](assets/020.png)

  

RSRS标准分策略看起来要比RSRS斜率策略要好，咱把它们和基准画在一张图上进行对比，这种优秀就更明显了。

  

```
data_merge = pd.merge(data1[['date','strategy']].rename(columns={'strategy':'RSRS斜率策略'}),
```

  

![](assets/021.png)

  

咱把研报中的RSRS策略对比图也找出来看看，研报中的数据是截止到2017年4月，当时RSRS斜率策略的累计净值是在10.57，RSRS标准分策略的累计净值是在13.37，无论是走势还是数值，总体上还是比较接近的，算是能复现出个大概了。

  

![](assets/022.png)

  

**4.补充和总结**

需要补充的是，原始研报中可能隐含了两处“未来函数”，第一处是买入卖出阈值的确定，文中是统计了全部数据集的数值（例如斜率值beta）分布再确定阈值的，相当于是用训练集训练模型，然后又让模型预测训练集。

  

第二处就是买卖时点的确定，当天出信号之后当日收盘价成交，虽然只要当日K线不出现“光头”或“光脚”，可以大概率近似实现，但与实盘情况还是有一定差距，只是回测起来非常方便。原版研报当中没有明说，仅为个人猜测和看法，因为这种方式回测结果与研报最接近。

  

总体来说整篇研报还是瑕不掩瑜，RSRS指标带有一定的创新性，不少小伙伴看了都觉得有启发，本次重点是在“复现”，于是也遵从了这两处设定。

  

到这里，基本的RSRS策略就已经复现完毕了，幸好总体结果跟原始研报还是一致的，暂时还没有翻车，希望可以给小伙伴们说清楚一些RSRS指标策略具体的计算细节，也让大伙儿少走一些弯路，节省一些精力。**如果对你有帮助，可以点个充满鼓励的『赞』告诉我，接着把RSRS后续系列肝完。**

  

**参考资料**

_光大金工，2017.5，《技术择时系列报告之一：基于阻力支撑相对强度（RSRS）的市场择时》_

  

_光大金工，2017.6，《技术择时系列报告之二：阻力支撑相对强度（RSRS）择时及行业轮动》_

  

_光大金工，2017.7，《技术择时系列报告之三：阻力支撑相对强度（RSRS）选股》_

  

_光大金工，2018.3，《技术择时系列报告之五：基于RSRS策略改进的资产配置研究》_

  

_光大金工，2019.11，《技术择时系列报告之六：RSRS择时：回顾与改进》_

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484812&idx=1&sn=1697b0ff17a7e48a56ddab441cb5dd84&chksm=c21ba603f56c2f15c3ded82ee3bf59027a997b25cf22535045743b6860b12fbfa379c54d5f04&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484822&idx=1&sn=39ac52116f314f52f8adb090e6dba782&chksm=c21ba619f56c2f0f6ba71de6526e7fe916088b9a18402ab09f27d01d003a459cc7b59755969b&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

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

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/023.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/024.png)