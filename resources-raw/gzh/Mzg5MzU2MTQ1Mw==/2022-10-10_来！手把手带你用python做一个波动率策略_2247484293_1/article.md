# 来！手把手带你用python做一个波动率策略

puppy 跟puppy玩量化 2022-10-10 17:02 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247484293&idx=1&sn=1745f1474f9bbaeca26d20c3e5ba998e&chksm=c16f05de6bd2b009438af42987073c2e20f50284c3b74cc9bf8391b386e39916ccd6bf64c0c2#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484293&idx=1&sn=1745f1474f9bbaeca26d20c3e5ba998e&chksm=c16f05de6bd2b009438af42987073c2e20f50284c3b74cc9bf8391b386e39916ccd6bf64c0c2#rd)

**0****1**

原文选取于medium上的基础热门策略，我在原文的基础上加上了更直观的解读，方便不同水平的期权交易者阅读。原文链接在下面。

  

https://link.medium.com/7O12Qd8nVtb  

  

隐含波动率:

  

![](assets/001.jpg)

  

期权交易界有句话说，_期权交易是波动率的交易_。

隐含波动率（下文简称iv）是期权交易的核心。iv是对未来股价波动的预期，一份iv为95%的期权表明，在期权到期日之前，未来股价可能会上涨或者下跌95%。

随便选个期权点进去，都能看到iv，不同券商iv读数不同，是因为计算iv的模型不一样。

有个例子讲的iv讲的很形象，Tom不确定会不会下雨，他打开窗户，看到街上行人都带了伞，于是判断今晚很可能会下雨。这个对未来下雨的预期，就是隐含波动率。

IV越高，期权价格越贵。和任何市场一样，供需关系直接影响IV，IV越高，说明买的人越多，期权价格当然也就越贵。

### Delta:

![](assets/002.jpg)

期权兄弟随身带几把尺子，随时测量和亲兄弟股票的关系。其中一把尺子叫delta，用来衡量期权价格随股票价格的变动幅度。

当delta等于0.65时，股价上涨1块钱，期权价格会上涨0.65元。

### delta-hedging（delta对冲）：

知识已经储备好，现在进入这个策略的核心部分。

这个策略的套利空间来自iv和已实现波动率（realized volitility，RV）的差异。比方说，一张期权的iv是95%，但是到期日时，他的iv变成了90%，那么这5%的差异就是利润的来源。

网上对已实现波动率（下文简称RV）的解释花里胡哨，在本文中RV就是对未来隐含波动率的预测。

比如说上面，我们预测iv等于90%（价格低），现在iv等于95%（价格高），我们先卖一张，收到钱，等它波动率降低到90%，再回来，高卖低买赚差价哈哈。

只赚波动率的钱，就必须剥离股价方向波动（涨跌）对组合的影响，整个组合要保持delta中性。straddle策略就是一种delta中性策略，同时买入同一个行权价的put和call，股价涨也能赚，跌也能赚。

### 预测RV：

前面说利润来自IV和RV的差异，IV一开始就知道，所以关键在于计RV。

目前计算RV的最好方法是GARCH模型，GARCH模型是基于金融时间系列波动率聚集的特征建模的。

公式太复杂，没关系反正python有现成的包。

![](assets/003.jpg)

garch模型用人话说，就是股价大波动接着大波动，小波动接着小波动。在高波动的时候，人们情绪高涨，市场的势能不断积累，于是会转化成更大的波动；在低波动的时候，人们对市场的兴趣越来越低，市场逐渐会成为一摊死水。GARCH就是在这样的市场特征基础上建立的。

下面开始用Python自带的arch库来试试RV预测。

**02**

第一步，导库，准备数据。

`import pandas_datareader.data as web``from datetime import datetime, timedelta``import pandas as pd``import matplotlib.pyplot as plt``from arch import arch_model``from statsmodels.graphics.tsaplots import plot_acf, plot_pacf``import numpy as np``from arch.__future__ import reindexing``   ``start = datetime(2015, 1, 1)``end = datetime(2021, 4, 16)``dis = web.DataReader('SPY', 'yahoo', start=start, end=end)``returns = 100 * dis.Close.pct_change().dropna()``plt.figure(figsize=(10,4))``plt.plot(returns)``plt.ylabel('Pct Return', fontsize=16)``plt.title('SPY Returns', fontsize=20)`

  

第二步，训练数据。  

`plot_pacf(returns**2)``plt.show()``model = arch_model(returns, p=2, q=2)``model_fit = model.fit()``model_fit.summary()``rolling_predictions = []``test_size = 365*5``   ``for i in range(test_size):`        `train = returns[:-(test_size-i)]`        `model = arch_model(train, p=2, q=2)`        `model_fit = model.fit(disp='off')`       `pred = model_fit.forecast(horizon=1)`    `rolling_predictions.append(np.sqrt(pred.variance.values[-1,:][0]))`   `rolling_predictions = pd.Series(rolling_predictions, index=returns.index[-365*5:])``plt.figure(figsize=(10,4))``true, = plt.plot(returns[-365*5:])``preds, = plt.plot(rolling_predictions)``plt.title('Volatility Prediction - Rolling Forecast', fontsize=20)``plt.legend(['True Returns', 'Predicted Volatility'], fontsize=16)`

  

![](assets/004.jpg)

  

第三步，预测RV。

```
train = returns
```

  

![](assets/005.jpg)

预测出2020年6月11日的RV是122%，那么你可以在之前卖出IV高于122%的ITM call，并时刻保证delta中性，赚波动率回归的钱。

为什么要卖ITM的期权？因为在波动率曲面（volitility surface）中，越是价内的期权，波动率回归的越快，最终收敛至RV。

**03**

### 进阶：

期权大兄弟还有一把尺子，叫做gamma，它是和delta一起用的。

delta为0.5，gamma为0.05，那么股价每涨1块钱，delta会增加：gamma\*1=0.05，从0.5增加到0.55。

gamma用来衡量股价和delta之间的关系。股价涨1块钱，delta涨几块钱。

因为有gamma的存在，delta会一直变化，这就需要你一直调整delta，让它一直等于0。这就是动态对冲！