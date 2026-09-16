# 手把手教你用机器学习预测黄金ETF价格（全程源码）

量化君 量化君也 2024-05-18 17:17 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c3850d92767fc293a733106a475f8c00901dd1c100b69fe8747c80c993aa8b688b20c33c97f8#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c3850d92767fc293a733106a475f8c00901dd1c100b69fe8747c80c993aa8b688b20c33c97f8#rd)

![](assets/001.png)

  

之前给大伙儿推荐过许多国外经典优质的量化干货，比如说[《一大波国外高清量化网址正在袭来...》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485841&idx=1&sn=e94800a827ce4f38c833dcd144ea1806&chksm=c21baa1ef56c2308a446ca6fdc4c021bbef760154cc1120943a29323e22407f9f81d419f02d0&scene=21#wechat_redirect)，都是有文章有源码、有图有真相的，但是有不少萌新小伙伴反映说看不懂、跑不通、用不上。  

  

那咋办呢？东西是好东西，但没办法吸收，岂不是白瞎了嘛~

  

帮人帮到底，送佛送到西，扶上了马，还要送一程嘛。所以啊，我打算慢慢地把这些文章国产化本土化，这主要包含3个方面：

  

**（1）将英文变成中文，并且用人话说出来；**

  

**（2）修改原始代码，让它在国内也能跑通；**

  

**（3）将测试标的换成国内的品种，熟悉还用得上。**

  

大的修改主要是这3方面，更细节的就是我会在保证原版功能的情况下，根据个人经验调整代码的实现方式以及部分参数，毕竟“空间”和“时间”都变化了，很多细节也要跟着变化。

  

凡事讲究从易到难，先挑一个简单的开整，就是这篇**《Gold Price Prediction: Step By Step Guide Using Python Machine Learning》，作者是Ishan Shah 和 Rekhit Pachanekar**，原文网址如下：

  

https://blog.quantinsti.com/gold-price-prediction-using-machine-learning-python/

  

其实这篇文章在翻译插件的帮助下，萌新想看明白也不难，其实就是讲了如何使用线性回归模型，根据两根均线的当前数值，预测黄金ETF第二天的价格，有代码有回测，最大的难点就是：代码跑不通！

  

为啥呢？因为里面使用了yfinance这个Python第三方库，它是基于雅虎(Yahoo)公开的API接口访问和获取黄金ETF的历史行情数据，但问题是这个库在2021年11月就停止了对中国的访问服务，要想正常使用，你要么在国外，要么自己搭梯子。

  

所以很多萌新发现自己跑不通文章上的代码，这是很正常的，在这里，咱用同样开源的akshare库替代yfinance，国内正常使用，还免费，一句话“pip install akshare”就可以安装了。

  

解决了数据获取这个最大的难题，接下来的事情就简单多了，按照原文的流程进行讲解，要想基于机器学习预测黄金ETF的价格，总共分为8步走。

  

**Step1：导入Python库和读取黄金ETF数据**

Import the libraries and read the Gold ETF data

  

首先，咱要导入建模和回测中所需要的全部Python库。  

  

```
# 用于数据处理
```

  

接着要获取黄金ETF的数据，原文当中是获取SPDR黄金ETF从2018年1月1日至2020年6月22日的数据，**为了本土化和与时俱进，将黄金ETF的品种改为我国上交所的黄金ETF(代码：518880)**，截止时间设为2024年5月17日，但由于它是在2013年7月才上市，所以起始时间设为2013年8月1日。  

  

```
# 获取黄金ETF的历史行情数据
```

  

上面的代码是用akshare来获取黄金ETF的行情数据，只需要其中的收盘价序列，数据的形式是一个DataFrame，index为datetime格式的日期(与yfinance一致)，columns只有一个收盘价(Close)字段，并画出黄金ETF收盘价序列。

  

上面代码的运行结果：  

  

![](assets/002.png)

  

![](assets/003.png)

  

**Step2：定义解释变量**

Define explanatory variables

  

这一步要做的就是定义解释变量，简单来说，**解释变量就是说你要用什么东西去预测黄金ETF的价格。**其实解释变量在不同的领域还有不同的叫法，在数学领域叫做自变量，在机器学习领域叫特征，在量化领域叫因子，叫法不同，本质都是一个东西，就是y=f(x)当中的x，y就是你想预测的东西，比如说这里黄金ETF第二天的价格。

  

在这里，咱将使用55日移动均线和60日移动均线作为解释变量，你也可以根据自己的喜好加入更多的解释变量，比如说MACD、KDJ、RSI等等，这里咱保持原文当中两个均线因子的设定。

  

**Step3：定义因变量**

Define dependent variable

  

**因变量就是咱要预测的目标，这里指的就是黄金ETF第二天的价格**，更确切一点来说就是第二天的收盘价。

  

```
# 计算均线因子
```

  

运行结果：  

  

![](assets/004.png)

  

按照一般机器学习建模的命名规则，咱将解释变量的矩阵命名为X，格式为DataFrame，所以用大写的X，因变量只有一列数值，所以存储为Series格式，命名为小写的y。  

  

**Step4：将数据划分为训练集和测试集**

Split the data into train and test dataset

  

这一步，咱就要将刚才的数据划分为训练集和测试集，**训练集是用来训练模型的，也就是让机器学习模型自动拟合那两个均线因子与第二天收盘价的关系，测试集就是用来验证模型好坏的**，验证好坏就是要用建模时没有出现过的数据，不然就跟高考全部用模拟考的题目，筛选出来的全都是些死记硬背的“人才”。

  

![](assets/005.png)

  

按照惯例，一般是将大部分数据用于训练模型，少部分数据用于验证模型，这里用80%的数据作为训练集，20%的数据作为测试集。下方代码中，X\_train和y\_train就是训练集数据，X\_test和y\_test就是测试集数据。

  

```
# 将数据划分为训练集和测试集
```

  

运行结果：

  

![](assets/006.png)

  

**Step5：构建线性回归模型**

Create a linear regression model

  

线性回归模型可以说是最常用的一种机器学习模型了，高中就接触过的最小二乘法OLS就属于线性回归。

  

![](assets/007.png)

  

线性回归基于一个或多个自变量预测因变量的值，它之所以被称为“线性”，那是因为它假设因变量和自变量之间的关系是线性的，形式如y=m1\*x1+m2\*x2+c，其中x1和x2是自变量，y是因变量，m1和m2就是回归系数，c又被称为截距或常数项。  

  

```
# 创建线性回归模型并训练
```

  

运行结果：  

  

```
黄金ETF价格(y) = 6.58 * 55日移动平均线(x1)  -5.59 * 60日移动平均线(x2)  +0.02 (constant)
```

  

从运行结果中看出，线性回归模型基于训练集数据，学习到了回归系数和常数项分别是6.58、-5.59和0.02，那么整个模型就可以表示为：

  

**黄金ETF价格 = 6.58 \* 55日移动平均线 - 5.59 \* 60日移动平均线 + 0.02**

  

注意，这里的均线值是今日的，黄金ETF价格是预测第二天的。  

  

**Step6：预测黄金ETF价格**

Predict the Gold ETF prices

  

上一步模型训练好了，那咱就可以预测黄金ETF的价格了，直接调用LinearRegression对象当中的predict函数就可以预测了（sklearn库当中的模型都可以这样操作）。  

  

```
# 预测黄金ETF第二日的价格
```

  

运行结果：

  

![](assets/008.png)

  

上图当中的黄线是黄金ETF实际的价格，蓝线是预测的价格，预测值对实际值还是跟踪得比较紧密的，那有什么指标定量去衡量它们之间的拟合程度呢？

  

那就是决定系数R2了，坊间一般称为“R方”，计算公式如下。

  

![](assets/009.png)

  

其中，y是真实值，y横线是平均值，y三角是预测值。决定系数R2的取值范围一般在0~1之间，数值越大，表示线性拟合的效果就越好，当直线能完美拟合所有数据点时，取值为1。

  

要计算决定系数R2也非常简单，直接调用LinearRegression对象当中的的score函数就可以了。  

  

```
# 决定系数R2
```

  

运行结果：  

  

```
训练集决定系数: 0.9712
```

  

可以看到，训练集和测试集的模型决定系数R2分别是0.9712和0.9301，跟天花板1.0比较接近，属于不错的拟合效果，训练集拟合效果更好的原因也不言而喻，对训练过程中就出现过的样本数据当然拟合效果更好，对从未谋面的测试集数据拟合效果好才是真本事。  

  

**Step7：回测并绘制累积回报图**

Backtesting and plotting cumulative returns

  

模型建好了，并且对已知数据和未知数据的拟合效果都还行，那就基于这个模型构建一个黄金ETF的交易策略，**核心交易逻辑是：如果模型预测的黄金ETF价格比前一个预测值高，则买入黄金ETF，否则，卖出黄金ETF或空仓不操作。**

  

在具体实现当中，今天的predicted\_price\_next\_day对应的是明天黄金ETF价格的预测值，如果这个值比昨天预测的值高，那么交易信号signal记为1，否则signal记为0，那怎么计算策略的收益率和净值呢？  

  

那首先要计算出黄金ETF的日收益率序列，当今日signal为1时，对应的是第二日有持仓，当signal为0时，对应的是第二日没有仓位，假设每次都是满仓交易，那只要将有持仓的黄金ETF日收益率纳入作为策略的日收益就可以了，其他时间策略的日收益率为0，有了策略的日收益率序列后，只要做一个简单的连乘操作就可以算出净值曲线了，具体实现代码如下所示。  

  

```
# 只考虑测试集当中的数据
```

  

运行结果：

  

![](assets/010.png)

  

可以看到，策略净值曲线在基准净值曲线(买入并一直持有黄金ETF)之上，说明择时的效果比Buy & Hold要好一些，并且在大跌前基本都会卖出空仓，持有体验也会好一些。

  

接着咱再来计算一下策略和基准的夏普率，策略的夏普率是2.14，基准的是1.66，定量表明在风险调整后的收益方面，策略也是跑赢基准的。

  

```
# 计算夏普率
```

  

输出结果：  

  

```
策略夏普率: 2.14
```

  

**Step8：每日滚动预测**

Using this model to predict daily moves

  

当你确认这个模型可用之后，以后日常就是每天来看一下明天的预测值是多少，对应的交易操作是什么。

  

有了前面的铺垫，要实现这个功能就很简单了，只要将训练好的模型保存下来，每日获取近期的黄金ETF数据塞进模型里面预测，然后把最新的一行打印出来就可以了，实现代码如下。  

  

```
# 当前日期
```

  

运行结果：  

  

![](assets/011.png)

  

看到这里，你应该对用机器学习算法构建量化交易策略，有了一个框架性的了解，后面要精进的话，最主要的就是选入更多的因子(解释变量)和选用更高级的机器学习算法，基本的框架流程大抵还是这样，建议结合原文和本文对照阅读，这样就会发现一些有趣的细节改动。  

  

终于吭哧吭哧写完了，下期见~

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485753&idx=1&sn=0bff8f88e77269364a7ca2c5c5adcb79&chksm=c21baab6f56c23a0ffffcac74fb9fa7ae5ae87230442be5e3c8e3d131bd321416855cbfaabfb&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485755&idx=1&sn=cbbcc52e7542ed7dcb9ec62ba4ac36cf&chksm=c21baab4f56c23a2d9bf705f47d72fd65f2e82fa3c628978db49c352f0cb125a0eeb2dffc8be&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

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

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect) [量化砸盘](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485487&idx=1&sn=dcf8ca1e44357071363ca63daca0f270&chksm=c21baba0f56c22b6b352b30d7e5bb21f523f4268eb1edaec0ff4b3472199a5432beb920f505f&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/012.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/013.png)