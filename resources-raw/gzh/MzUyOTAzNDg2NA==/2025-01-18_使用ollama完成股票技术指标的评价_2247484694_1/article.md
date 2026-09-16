# 使用ollama完成股票技术指标的评价

fintechhaibin FinTechHi 2025-01-18 21:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484694&idx=1&sn=0ee95de61317950f88d20d4f0556abca&chksm=fb7154954b09b3d10f382bb32575d68cdf495f8d824504d586002472741f29b731cec9459a5d#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484694&idx=1&sn=0ee95de61317950f88d20d4f0556abca&chksm=fb7154954b09b3d10f382bb32575d68cdf495f8d824504d586002472741f29b731cec9459a5d#rd)

本篇文章有几个有意思的点：

-   1.使用streamlit可视化。
    
-   2.计算滚动平均值和动量等指标来了解市场趋势。
    
-   3.使用Llama 3对数据做解释。
    

  

提前安装并导入如下包：

```
import yfinance as yf
```

`# Fetching historical data for Apple (AAPL) and Dow Jones (DJI) for yesterday (1-minute intervals)``   `

```
stock = yf.Ticker("AAPL")
```

![](assets/001.png)

`Global variables to store rolling data for analysis`

```

```

这段代码定义了一些全局变量，用于存储滚动数据和跟踪每日的市场情况。  

-   rolling\_window和dow\_rolling\_window用于存储苹果公司和道琼斯指数的滚动数据。然后定义了几个变量来跟踪每日的市场情况。  
    
-   daily\_high和 daily\_low分别初始化为负无穷大和正无穷大，用于记录当天的最高价和最低价。通过将它们初始化为极端值，可以确保在实际数据更新时，这些变量会被正确地设置为当天的实际最高价和最低价。  
    
-   buying\_momentum和selling\_momentum变量初始化为0，用于跟踪当天的买入和卖出动量。这些变量可以帮助分析市场情绪和趋势，判断市场是处于买入还是卖出状态。
    

`   ``get_market_open_duration：Extract current time from the last element of the window`

```
def get_market_open_duration(window):
```

`get_natural_language_insights：generate natural language insights using Ollama（******重点这里，可以换成其他模型。）``   `

```

```

`calculate_insights：moving averages and trends`

```

```

`process_stock_update：process a new stock update every minute`

```

```

`Schedule job to simulate receiving updates every minute：`

```

```

运行日志：

![](assets/002.png)

通过Llama 3给出的数据分析：

Natural Language Insight: Apple's price is consolidating within the Bollinger Bands, with a slight dip to 226.39. The EMA and rolling average are slightly higher, indicating a short-term uptrend. 

The RSI of 37.54 suggests the stock may be oversold, potentially leading to a bounce. The buying momentum is higher than selling momentum, implying investors are still cautiously optimistic. With the Dow Jones index also experiencing a slight decline, it's possible Apple's strength could lead it outperforming the broader market in the short term.

使用Streamlit设计一个界面：

```
# Streamlit UI
```

  

需要完整代码私我即可。