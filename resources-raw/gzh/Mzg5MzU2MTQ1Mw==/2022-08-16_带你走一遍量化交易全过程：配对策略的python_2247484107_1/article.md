# 带你走一遍量化交易全过程：配对策略的python实现

跟puppy玩量化 跟puppy玩量化 2022-08-16 17:53 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247484107&idx=1&sn=e172b7b888d237993bfb4fec46a37fbb&chksm=c1aa4228beb10872613c9ddeaa9adb8bb14f3f2882309a9dcafd90c7c9213413fc99cc5910b3#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484107&idx=1&sn=e172b7b888d237993bfb4fec46a37fbb&chksm=c1aa4228beb10872613c9ddeaa9adb8bb14f3f2882309a9dcafd90c7c9213413fc99cc5910b3#rd)

这篇文章包括了从对**原始数据处理**、**数据检验、代码实现**的一系列详细步骤，如果你没有量化交易的经验，这篇文章是一个很好的开始。

配对策略属于均值回归策略的一种，主要从两只股票的价差来盈利。这个策略在市场上存在已久，但时至今日依然奏效。

### 第一个使用这个策略的人是利弗莫尔，对就是《股票大作手回忆录》的主人公，他用肉眼观察同类资产的表现。

在进入这个策略之前，需要区分两个统计学概念：相关性和协整性。

### 相关性 Correlation：

-   相关系数(ρ)衡量变量之间**线性关系的程度（注意是线性，本文会通篇强调）**：p=-1为完全**线性负相关**，p=0说明两者没有**线性相关**，p=1为完全**线性正相关**
    
-   p=0仅仅说明俩变量间**没有线性关系**，不一定完全**没有关系**。
    
-   用价格还是收益率来度量资产之间的相关性呢？经验表明**短期用收益率度量，长期用价格度量**。
    
-     
    
-   p=1，两组数据完全正相关：  
    

![](assets/001.jpg)

  

p=-0.7，两组数据高度负相关：

![](assets/002.jpg)

  

p=0.7，两组数据高度正相关：

![](assets/003.jpg)

  

### 协整性 Cointegration：

-   书上这么解释：两个金融时间序列之间的比率将围绕一个恒定的均值变化。
    
-   书上的定义说的很绕，打个比方你会很好理解：股票价格和债券价格，他们的比值倾向于收敛一个数值，**这两者就有高度协整性。**
    
-   这个恒定的数值就是配对策略的出发点，我们假设不管市场如何扰动，这个数值都会回到长期均值。
    

## 配对策略：

## 两只股票具有高度协整关系，那么他们的价差长期来看会比较稳定，但稳定性会因为投资者“追涨杀跌”等等的不理性交易而打破，导致**价差扩大**。

配对交易就从这个价差切入，分别在两只股票上建立多头和空头头寸，卖空相对高估的股票，买入相对低估的股票，等待价差收敛。

配对交易同时双向建仓，对冲掉了绝大部分市场风险，因此属于市场中性策略。

## 开搞：

资产选择：澳大利亚ETF（EWA）和加拿大ETF（EWC）。

先来看看他俩价格之间的相关性，一眼看上去高度相关：

![](assets/004.jpg)

用代码测试一下：

`import numpy as npnp.corrcoef(Asset_1, Asset2)`

输出结果是0.85，验证了高度正相关的猜想。

**再来看看这两组数据的比值是否平稳**，如果数据随着时间变化，有趋势性和季节性，那么数据就不平稳，对于不平稳的数据，发现其中规律就无从谈起了。

对**两组数据的比值**进行平稳性检验：

`def stationarity(ratio, cutoff = 0.05):`   `Data[:, 2] = Asset_2 / Asset_1`   `Ratio = Data[:, 2]`   `a = np.ravel(ratio)``if adfuller(a)[1] < cutoff:`     `print(‘The series is stationary’)`     `print(‘p-value = ‘, adfuller(a)[1])`

p-value=0.032，**数据平稳**。

**下一步检查他们的协整性**，高度协整性意味着均值回归，是执行配对策略的基础。

`def cointegration(a, b):if coint(a, b)[1] < 0.05:    print(‘The series are cointegrated’)    print(‘p-value = ‘, coint(a, b)[1])else:    print(‘The series are NOT cointegrated’)    print(‘p-value = ‘, coint(a, b)[1])cointegration(Asset_1, Asset_2)`

![](assets/005.jpg)

协整性的p-value为0.048，说明数据高度协整，存在均值回归性质。

现在对数据的比值进行标准化处理：

`for i in range(len(Data)):``try:`    `Data[i, 3] = (Data[i — lookback:i + 1, 2].mean())`  `except IndexError:`    `pass``# 计算标准差``for i in range(len(Data)):`  `Data[i, 4] = ((Data[i — lookback:i + 1, 2].std()))``# 标准化``for i in range(len(Data)):`  `Data[i, 5] = (Data[i, 2] — Data[i, 3]) / Data[i, 4]`

经标准化处理后的比值。选择-2和2作为界限，当比值达到2，做空；当比值达到-2，做多：![](assets/006.jpg)  

然后开始回测，回测的时间为过去9年的历史行情，策略代码如下：

`for i in range(len(Data)):try:if Data[i, 2] <= lower_barrier and Data[i — 1, 2] > lower_barrier:      Data[i + 1, 4] = -1      Data[i + 1, 5] = 1elif Data[i, 2] >= upper_barrier and Data[i — 1, 2] < upper_barrier:      Data[i + 1, 6] = 1      Data[i + 1, 7] = -1else:continueexcept IndexError:passfor i in range(len(Data)):try:if Data[i, 5] == 1:      Data[i + holding_period, 8] = (Data[i + holding_period, 1] — Data[i, 1])if Data[i, 6] == 1:      Data[i + holding_period, 8] = (Data[i + holding_period, 0] — Data[i, 0])if Data[i, 4] == -1:      Data[i + holding_period, 9] = (Data[i, 0] — Data[i + holding_period, 0])if Data[i, 7] == -1:      Data[i + holding_period, 9] = (Data[i, 1] — Data[i + holding_period, 1])except IndexError:pass`

  

策略触发的信号，红点为卖点，绿点为买点：![](assets/007.jpg)  

回测结果：

-   总交易次数：161次
    
-   年化回报率：21%
    
-   胜率：55.9%
    

### 注意，这个策略没有把手续费和其他交易成本（比如冲击成本）考虑在内，也没有加杠杆。

最后总结一下配对策略的实现过程：

1.  找到两组**逻辑上**相关的资产，观察一下他们的收益率或者价格曲线，对直觉上相关的两组资产进行相关性检验。
    
2.  如果两组资产接近正相关，下一步**进行价格比值**或**收益率比值**的平稳性检验
    
3.  平稳性满足后，进行协整性检验。
    
4.  如果数据高度协整，就可以进行数据回测了。
    

  

这个策略在数据预处理阶段的三个概念：**相关性，协整性，平稳性**，在后面的策略中会是常客：

  

相关性：两个变量线性相关程度

协整性：两个变量的比值，是不是围绕某个定值波动

平稳性：数据不随时间变化