# 手把手带你扒明白波动率—怎样建立波动率预测模型？比较不同波动率模型预测能力

puppy 跟puppy玩量化 2023-11-30 14:52 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247485636&idx=1&sn=5218a4cc796534832cedac4b0f321931&chksm=c152411351f415c60f670930478cc75b5f1b3208f34101857f5b46d6abf43fd8787b0900c761#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247485636&idx=1&sn=5218a4cc796534832cedac4b0f321931&chksm=c152411351f415c60f670930478cc75b5f1b3208f34101857f5b46d6abf43fd8787b0900c761#rd)

价格的波动大小由波动率反映，因为波动率在时间轴上有聚集性，也就是大的波动跟随大的波动，小的波动跟随小的波动，这一特点决定了未来波动可以被历史的波动预测。

  

之前写过的[新手做量化交易，什么策略最可行？](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247485588&idx=1&sn=2c8dc369bf98995ca3f3edd0d032f3e5&chksm=c02db796f75a3e80be91ff934cdec8b110c92522c4883dac238bbbb3cf8758888bfc9a29c5be&scene=21#wechat_redirect)，我们可以用波动率过滤震荡，瞄准趋势，找到规则类趋势策略的入场点。  

  

不论是单个资产，还是投资组合，波动率的预测都非常重要❗️，趋势交易者做波动率预测，能够抓住行情的特点，适时地切换震荡和趋势策略；做市商预测波动率，能决定什么时候单边挂单，什么时候双边挂单；期权交易者预测波动率，能抓住买卖权的入场时机。对多个资产波动率的准确估计能够让我们构建一套风险恒定的投资组合。

  

有些时候，波动率甚至比收益率更重要。

  

历史波动率是未来波动率的重要参考，这篇要写的两种波动率预测模型也不例外，它们都是计算了历史的波动，然后给出对未来波动的预测。这两种模型分别是**移动平均波动率预测模型(SMA)**，和**加权移动平均波动率预测模型(EWMA)**。文章的最后我们一起来看看这两种模型在美股指数上的使用效果。

  

欢迎关注puppy，未来我会写更多波动率在实战中的运用。

  

  

本着新手友好的原则，要追根溯源的讲清楚波动率，我们从最早的对波动率的定义开始讲起。

  

1\. 波动率的前生今世

定义波动率的模型多种多样，无论哪个模型都离不开一个关键变量——收益率。一个资产在一段时间内的收益率可以写成：

![](assets/001.jpg)

  

一个资产在一段时间内的方差，可以写成（省略数学推导过程）：

![](assets/002.jpg)

波动率就等于方差开根号，在这个公式的基础上，不同的假设衍生了不同的波动率定价模型。比如假设一段时间内，收益率的均值μt为0，资产的方差就可以写成下面这个样子：

![](assets/003.jpg)

用学术点的话描述这个表达式—一段时间内收益率的平方可以看作是资产方差的近似估计，或者代理变量。  

  

其实在期权定价的早期，Fischer Black就把收益率的均值μt假设为0了：  

  

_在我计算股票期权的一个月的波动率时，我直接加总每只股票日收益率的平方，求出平均值，再开根号。我没有减去每天回报率的平均值(μt)，这是因为一个月的平均回报率并不能很好的估计长期平均回报率。_

![](assets/004.png)

  

**但是return仅仅刻画了收盘价一个维度上的信息，并且由收盘价计算的return严重依赖于对时间切片的采样，所以在衡量波动率上是明显不足的**。这些年更精确的估计模型不断出现，其中之一是Parkinson的波动率估计模型，它在理论上和实践上都被证明比收益率更好用。  

  

![](assets/005.jpg)

  

这个公式用到了一段时间内的**High最高价**和**Low最低价**作为修正项，不再局限于close对close的收益率维度衡量波动。

  

另外还想提一嘴的是，kaggle波动率预测比赛中用到的计算方式也比较公允——这**种方式把时间颗粒度细化到tick级别，具体做法是加总一段时间段内每一个tick的收益率**。比方说计算10分钟内每个tick的收益率：

  

```
# 计算10分钟内tick的收益
```

  

简单移动平均波动率模型（SMA vol model）

  

一个资产的未来波动率，和它的历史波动率息息相关，我们在计算未来的波动率时，就是对资产的历史波动率做建模。

  

这里的简单移动平均顾名思义，就是给每一个窗口的波动率都分配了同等的权重，所以一个资产下一时刻(T时刻)的波动率等于前面一段时间内方差和的平均值。

  

![](assets/006.jpg)

  

SMA model的窗口选择

  

应该选择过去多少个时间窗口，来预测未来的波动率呢？

  

一种方法是用经验值来估计，比如你想预测接下来一个月股票每天的波动率，那你可以用过去一个月每天的波动率作为参考。

  

不同的预测时段（比如预测未来一天和预测未来一个月）可能需要不同的窗口大小，所以另一种方法是**最小化预测误差**来确定这个窗口大小，预测误差可以用**实际波动率和预测的波动率之间的均方根误差（RMSE）**来衡量。

  

举个例子，如果你想预测明天的波动率，你会试验过去5天、10天、20天的窗口大小，然后看哪个窗口大小预测的最准确。

  

![](assets/007.png)

  

加权移动平均波动率模型(EMA vol model)

  

波动率是有聚集性的，在时间轴上来看，大的变动倾向于跟随大的变动，小的变动跟随小的变动。EWMA模型赋予最近的市场波动率较大的权重，更好地反映出波动率的这种时间聚集性。

  

EWMA模型这么定义波动率：下一个时刻(T+1)的波动率等于T时刻的波动率乘上一个衰减系数λ，T时刻的波动率又由T-1时刻的波动率乘上λ.....依次递归求得。

![](assets/008.jpg)

  

这个λ衰减系数怎么选呢？你可以用文献里推荐的参数：

  

λ=0.9415或者λ=0.8920，用于预测未来1天的波动率；λ=0.9220用于预测未来一周的波动率；λ=0.9520 用于预测未来2周的波动率；λ=0.9715或λ=0.9820用于预测未来1个月的波动率。

  

也可以用前面也可以用前面SMA模型中提到的最小预测误差的方法，来确定这个衰减系数λ。

  

虽然模型的表现都离不开资产的类别和预测的时间窗口，但是实证结果告诉我们他俩依然是很好用的模型！  

  

实验部分

  

第一个实验是预测10个ETF未来一个月的波动率，这10个ETF是：  

![](assets/009.jpg)

  

实验一共采用了传统的收盘价收益率、parkinson range、调整后的 parkinson range三种模型，对每种模型都进行了SMA

或EWMA处理，然后用Mincer-Zarnowitz回归来评估每个模型的预测能力，得到不同模型在SMA和EWMA下的表现：

![](assets/010.jpg)

![](assets/011.jpg)

![](assets/012.jpg)

  

总结下来，无论是经过SMA还是EWMA的处理，**Parkinson波动率模型(前文提到的考虑了最高价和最低价的波动率模型)**，最准确的预测了未来的波动率。  

  

接下来进入第二个实验，我们先回顾一篇论文：Risk Before Return: Targeting Volatility with Higher Frequency Data，这篇论文提到了15分钟的日内数据能够明显增强日级别“以波动率为目标”的策略表现。

  

什么是「以波动率为目标」的策略？

  

在以波动率为目标的策略中，我们动态调整各个资产的权重，来实现波动率的恒定(其实就是平衡风险资产和无风险资产的比重)。

  

先计算目标波动率和和预测的波动性的比值Wt，这个Wt也就是我们投入到风险资产的权重，剩下的1-Wt投入到无风险资产中。这个策略的目的是维持投资组合总体波动性的稳定。

  

分别用30天移动平均、包含日内15分钟数据的2天移动平均、和每天的VIX值，对标普指数2020年到2023年的日波动率做预测（三种模型都是用收盘价对收盘价的return来算波动率），得到的结果是：

  

![](assets/013.jpg)

  

从第二个实验可以看出，添加日内的高频数据能明显提高预测的准确率。

  

本篇文章参考了十几篇论文：

  

‍

‍Andrew J. Patton, Volatility forecast comparison using imperfect volatility proxies, Journal of Econometrics, Volume 160, Issue 1, 2011, Pages 246-256. 

  

Boudoukh, J., Richardson, M., & Whitelaw, R.F. (1997). Investigation of a class of volatility estimators, Journal of Derivatives, 4 Spring, 63-71.

  

Figlewski, S. (1997), Forecasting Volatility. Financial Markets, Institutions & Instruments, 6: 1-88. 

  

Fischer Black, One Way to Estimate Volatility, Black on Options

  

Alizadeh, S., Brandt, M.W. and Diebold, F.X. (2002), Range-Based Estimation of Stochastic Volatility Models. The Journal of Finance, 57: 1047-1091.

  

Richard D.F. Harris, Fatih Yilmaz, Estimation of the conditional variance-covariance matrix of returns using the intraday range, International Journal of Forecasting, Volume 26, Issue 1, 2010, Pages 180-194. 

  

Lazard Asset Management, Predicting Volatility, December 2015. 

  

RiskMetrics. Technical Document, J.P.Morgan/Reuters, New York, 1996. Fourth Edition.

  

Fulvio Corsi, A Simple Approximate Long-Memory Model of Realized Volatility, Journal of Financial Econometrics, Volume 7, Issue 2, Spring 2009, Pages 174-196.

  

Brooks, Chris and Persand, Gitanjali (2003) Volatility forecasting for risk management. Journal of Forecasting, 22(1). pp. 1-22.

  

Axel A. Araneda, Asset volatility forecasting:The optimal decay parameter in the EWMA model, arXiv. 

  

Mincer, J. and V. Zarnowitz (1969). The evaluation of economic forecasts. In J. Mincer (Ed.), Economic Forecasts and Expectations. 

  

Salt Financial, Risk Before Return: Targeting Volatility with Higher Frequency Data, Research Note. 

  

Salt Financial people scale their proposed intraday high frequency realized volatility measure in order to account for overnight returns. 

  

Andersen, T. G. and Bollerslev, T.: 1998, Answering the skeptics: Yes, standard volatility models do provide accurate forecasts, International Economic Review 39, 885-905. 

  

Harvey, Campbell R. and Hoyle, Edward and Korgaonkar, Russell and Rattray, Sandy and Sargaison, Matthew and van Hemert, Otto, The Impact of Volatility Targeting.

  

Hansen, P.R. and Lunde, A. (2005), A forecast comparison of volatility models: does anything beat a GARCH(1,1)?. J. Appl. Econ., 20: 873-889. 

  

Brunetti, Celso and Lildholdt, Peter M., Return-Based and Range-Based (Co)Variance Estimation - with an Application to Foreign Exchange Markets (March 2002). 

  

R. Cont (2001) Empirical properties of asset returns: stylized facts and statistical issues, Quantitative Finance, 1:2, 223-236. 

  

Butler, Adam and Philbrick, Mike and Gordillo, Rodrigo and Varadi, David, Adaptive Asset Allocation: A Primer.