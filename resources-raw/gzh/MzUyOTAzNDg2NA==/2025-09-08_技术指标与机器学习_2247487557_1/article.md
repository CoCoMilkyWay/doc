# 技术指标与机器学习

fintechhaibin FinTechHi 2025-09-08 19:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247487557&idx=1&sn=c19340b6ccc1db2b4e83cf87dde85944&chksm=fbbfaaab0b8e0e13b816b785c86034af01f156c3a36c2d76c739ae64ed98c7e17aaa213bb022#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487557&idx=1&sn=c19340b6ccc1db2b4e83cf87dde85944&chksm=fbbfaaab0b8e0e13b816b785c86034af01f156c3a36c2d76c739ae64ed98c7e17aaa213bb022#rd)

手头边正好有一本《期货市场技术分析》，翻了几页。

不同的技术指标可以从不同维度为投资提供决策，从而使我们更容易理解市场行为。每个指标都旨在将市场行为转化为指导我们决策的有用规则，比如：

-   SMA和EMA，有助于显示价格的整体趋势，使交易者更容易判断市场走向。
    
-   RSI或MACD，则关注动量，并可能暗示可能的反转，为交易者提供有用的信号。
    
-   布林带或ATR等工具可以洞察市场的波动性和稳定性，
    
-   OBV等成交量指标则显示价格走势背后的强度。
    

  

技术分析三大假设

-   市场行为包容消化一切
    
-   价格以趋势方式演变
    
-   历史会重演
    

  

技术分析研究市场行为，基本面分析则分析导致价格涨跌的供求关系，二者都为是预测价格变化方向，但着眼点不同。基本面看的是市场的“前因”，而技术派研究的是“后果”。技术派认为“后果”就是所要研究的全部信息，而理由，原因无关紧要，而基础派确需要对其刨根问底。

基本面分析是为了确定一只股票的内在价值，需要考虑影响价格的所有因素，从而类似卖方的结果：看涨、看跌、维持。（通过预测的内在价值（价格）和当前价格比较）。

大多数情况下，在某个行情的初期阶段，基本面分析和技术分析可能会南辕北辙，当趋势发展一段时间后，两者对市场的理解又协调起来，这时候对我们投资者来说：已无法下手了。

市场价格相对经济基础来说，是超前指标。经济基础的新发展在被统计报告等资料揭示之前，在市场上已实际发生作用，并被市场消化。等到利空或利好消息到来时，新的趋势已经滚滚向前了。

如果是做期货交易，业务涉及到杠杆，即使大趋势判断对了，可能也会“结束”（中间的涨跌导致保证金不足后强平），这和股票不一样，即使判断错了，大不了投机做成投资而已。

所以，如果从做交易的择时角度出发，则尽量要依赖技术指标做出判断。

上面是书里面的一些观点，比较基础，但不同阶段，同样的内容，自己的理解是不同。

下面主要是从机器学习的角度，看下用机器学习来对技术指标做分析的思路，有兴趣的自行研究实验。

1.导入包

```
import requests
```

2.get\_stock\_data

```
def get_stock_data(ticker, start_date, end_date):
```

3.add\_52week\_high\_low

```
def add_52week_high_low(df):
```

4.get\_technical\_indicator

```
def get_technical_indicator(ticker, indicator, start_date, end_date, **params):
```

5.all\_stocks\_df 

```
tickers = ["MSFT.US", "AAPL.US", "META.US", "GOOGL.US", 'NVDA.US', 'AVGO.US', 'AMZN.US']
```

![](assets/001.png)

数据列头为：date、open、high、low、close、adjusted\_close、volume、ticker、52w\_high、52w\_low、volatility\_volatility、rsi\_rsi、slope\_slope、dmi\_dmi、adx\_adx、atr\_atr、cci\_cci、bbands\_uband、bbands\_mband、bbands\_lband

6.target

```
# Calculate future returns as percentage changes from the current close price
```

7.all\_stocks\_df

```
all_stocks_df = all_stocks_df.copy().dropna()
```

8.模型预测

```
def return_model_and_results(df, exclude_ind=None):
```

0.6657852987837123 

0.3643574828133263 

0.41459545214172394

从结果看，模型不是很好，只有1周模型达到了约66%的准确率。

9.模型结果分析

```
def parse_classification_report(report_str):
```

![](assets/002.png)

10.plot\_grouped\_feature\_importances

```
def plot_grouped_feature_importances(results_dict, top_n=15):
```

![](assets/003.png)