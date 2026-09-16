# 限价订单薄系列（22）如何分析股票的流动性和波动性

fintechhaibin FinTechHi 2025-01-31 15:29 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484937&idx=1&sn=ce7d1a82e60a7c58ea119f88dc76c017&chksm=fba442890c5e26299c60ecde0ab6f6a135a47ce60303d9545e5a96dd19386661ecd1d72d195a#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484937&idx=1&sn=ce7d1a82e60a7c58ea119f88dc76c017&chksm=fba442890c5e26299c60ecde0ab6f6a135a47ce60303d9545e5a96dd19386661ecd1d72d195a#rd)

在量化投资中，分析股票的波动性和流动性是评估风险和制定交易策略的重要步骤。

通过分析股票的波动性和流动性，投资者可以更好地评估投资风险和制定交易策略。波动性指标如标准差、历史波动率和ATR可以帮助评估价格变动的幅度，而流动性指标如成交量、VWAP、买卖价差、换手率和安德森流动性比率可以帮助评估股票的交易难易程度和成本。结合这些指标，投资者可以更全面地了解股票的市场行为。

以下是一些常用的方法和指标，用于分析股票的波动性和流动性：

### 1.波动性分析

波动性是衡量股票价格变动幅度的指标，常用于评估投资风险。以下是一些常用的波动性分析方法和指标：

1.  **标准差（Standard Deviation）**：
    

-   计算股票价格或收益率的标准差，衡量价格波动的幅度。
    
-   公式：
    
-   其中， 是每个数据点， 是平均值， 是数据点的数量。
    

3.  **历史波动率（Historical Volatility）**：
    

-   计算一段时间内股票收益率的标准差。
    
-   通常使用对数收益率计算。
    
-   公式：
    
-   其中，是对数收益率的标准差， 是年化因子（如252个交易日）。
    

5.  **平均真实波动范围（Average True Range, ATR）**：
    

-   衡量股票价格的波动幅度，考虑了价格的高低点和开盘价。
    
-   公式：
    
-   其中， 是第 天的真实波动范围，是时间窗口。
    

7.  **波动率指数（Volatility Index, VIX）**：
    

-   反映市场对未来30天波动性的预期，通常用于衡量市场情绪和风险。
    

### 2.流动性分析

流动性是衡量股票在市场中交易的难易程度和成本的指标。以下是一些常用的流动性分析方法和指标：

1.  **成交量（Volume）**：
    

-   衡量股票在一定时间内的交易数量。
    
-   高成交量通常表示高流动性。
    

3.  **成交量加权平均价格（Volume Weighted Average Price, VWAP）**：
    

-   衡量股票在一定时间内的平均交易价格，考虑了成交量的权重。
    
-   公式：
    
-   其中， 是第  笔交易的价格， 是第  笔交易的成交量。
    

5.  **买卖价差（Bid-Ask Spread）**：
    

-   衡量股票买入价和卖出价之间的差距。
    
-   公式：
    
-   较小的价差通常表示较高的流动性。
    

7.  **换手率（Turnover Ratio）**：
    

-   衡量股票在一定时间内的交易量与流通股数量的比率。
    
-   公式：
    
-   高换手率通常表示高流动性。
    

9.  **安德森流动性比率（Amihud Illiquidity Ratio）**：
    

-   衡量股票价格变动与交易量之间的关系。
    
-   公式：
    
-   其中， 是第  天的收益率， 是第  天的成交量， 是时间窗口。
    

#### 实例代码

以下是一个使用Python和Pandas计算股票波动性和流动性指标的示例代码：

`import pandas as pd   import numpy as np      # 假设我们有一个包含股票价格数据的数据框   data = {       'Date': pd.date_range(start='2023-01-01', periods=100, freq='D'),       'Close': np.random.normal(100, 10, 100),       'Volume': np.random.randint(1000, 5000, 100)   }   df = pd.DataFrame(data)   df.set_index('Date', inplace=True)      # 计算标准差（波动性）   df['Return'] = df['Close'].pct_change()   volatility = df['Return'].std()      # 计算历史波动率   historical_volatility = df['Return'].std() * np.sqrt(252)      # 计算平均真实波动范围（ATR）   df['High'] = df['Close'] * (1 + np.random.uniform(0, 0.05, 100))   df['Low'] = df['Close'] * (1 - np.random.uniform(0, 0.05, 100))   df['TR'] = df[['High', 'Low', 'Close']].apply(lambda x: max(x['High'] - x['Low'], abs(x['High'] - x['Close']), abs(x['Low'] - x['Close'])), axis=1)   df['ATR'] = df['TR'].rolling(window=14).mean()      # 计算成交量加权平均价格（VWAP）   df['VWAP'] = (df['Close'] * df['Volume']).cumsum() / df['Volume'].cumsum()      # 计算买卖价差（假设买入价和卖出价）   df['Bid'] = df['Close'] * (1 - np.random.uniform(0, 0.01, 100))   df['Ask'] = df['Close'] * (1 + np.random.uniform(0, 0.01, 100))   df['Spread'] = df['Ask'] - df['Bid']      # 计算换手率   shares_outstanding = 1000000# 假设流通股数量   df['Turnover'] = df['Volume'] / shares_outstanding      # 计算安德森流动性比率   df['Amihud'] = (df['Return'].abs() / df['Volume']).rolling(window=14).mean()      # 打印结果   print("Volatility:", volatility)   print("Historical Volatility:", historical_volatility)   print("Average True Range (ATR):", df['ATR'].iloc[-1])   print("VWAP:", df['VWAP'].iloc[-1])   print("Bid-Ask Spread:", df['Spread'].mean())   print("Turnover Ratio:", df['Turnover'].mean())   print("Amihud Illiquidity Ratio:", df['Amihud'].iloc[-1])   `

### 3.基于订单簿数据的分析

订单簿数据（Order Book Data）也是是分析股票流动性和市场深度的重要工具。订单簿记录了市场中所有未成交的买卖订单，包括价格和数量信息。通过分析订单簿数据，投资者可以更好地理解市场动态，评估流动性和价格发现过程。

#### 订单簿数据的关键指标

1.  **买卖价差（Bid-Ask Spread）**：
    

-   买入价（Bid Price）和卖出价（Ask Price）之间的差距。
    
-   公式：
    
-   较小的价差通常表示较高的流动性。
    

3.  **市场深度（Market Depth）**：
    

-   在不同价格水平上的买卖订单数量。
    
-   深度越大，表示市场能够承受较大交易量而不显著影响价格。
    

5.  **订单流（Order Flow）**：
    

-   一段时间内买卖订单的数量和方向。
    
-   订单流可以反映市场参与者的交易意图和情绪。
    

7.  **订单簿不平衡（Order Book Imbalance）**：
    

-   买单和卖单数量的差异。
    
-   公式：
    
-   不平衡值可以帮助识别潜在的价格变动方向。
    

#### 实例代码

以下是一个使用Python和Pandas分析订单簿数据的示例代码：

`import pandas as pd   import numpy as np      # 假设我们有一个包含订单簿数据的数据框   data = {       'Price': [100, 101, 102, 103, 104, 105, 106, 107, 108, 109],       'BidVolume': [500, 450, 400, 350, 300, 0, 0, 0, 0, 0],       'AskVolume': [0, 0, 0, 0, 0, 300, 350, 400, 450, 500]   }   df = pd.DataFrame(data)      # 计算买卖价差（Bid-Ask Spread）   bid_price = df[df['BidVolume'] > 0]['Price'].max()   ask_price = df[df['AskVolume'] > 0]['Price'].min()   spread = ask_price - bid_price      # 计算市场深度（Market Depth）   market_depth = df[['BidVolume', 'AskVolume']].sum()      # 计算订单簿不平衡（Order Book Imbalance）   buy_volume = df['BidVolume'].sum()   sell_volume = df['AskVolume'].sum()   imbalance = (buy_volume - sell_volume) / (buy_volume + sell_volume)      # 打印结果   print("Bid Price:", bid_price)   print("Ask Price:", ask_price)   print("Bid-Ask Spread:", spread)   print("Market Depth:", market_depth)   print("Order Book Imbalance:", imbalance)   `

### 4.结合波动性和流动性分析

通过结合订单簿数据与波动性和流动性分析，投资者可以获得更全面的市场洞察。例如：

1.  **波动性与订单簿深度**：
    

-   在高波动性时期，订单簿深度可能减少，表示市场流动性降低。
    
-   通过监控订单簿深度变化，可以预测潜在的价格波动。
    

3.  **流动性与订单簿不平衡**：
    

-   订单簿不平衡可以反映市场的买卖压力。
    
-   高流动性市场通常具有较小的订单簿不平衡。
    

5.  **买卖价差与波动性**：
    

-   较小的买卖价差通常表示较高的流动性和较低的波动性。
    
-   在高波动性时期，买卖价差可能扩大，表示市场不确定性增加。
    

#### 综合实例代码

以下是一个综合实例代码，结合波动性、流动性和订单簿数据进行分析：

`import pandas as pd   import numpy as np      # 假设我们有一个包含股票价格和订单簿数据的数据框   price_data = {       'Date': pd.date_range(start='2023-01-01', periods=100, freq='D'),       'Close': np.random.normal(100, 10, 100),       'Volume': np.random.randint(1000, 5000, 100)   }   order_book_data = {       'Price': [100, 101, 102, 103, 104, 105, 106, 107, 108, 109],       'BidVolume': [500, 450, 400, 350, 300, 0, 0, 0, 0, 0],       'AskVolume': [0, 0, 0, 0, 0, 300, 350, 400, 450, 500]   }      price_df = pd.DataFrame(price_data)   price_df.set_index('Date', inplace=True)   order_book_df = pd.DataFrame(order_book_data)      # 计算波动性   price_df['Return'] = price_df['Close'].pct_change()   volatility = price_df['Return'].std()      # 计算历史波动率   historical_volatility = price_df['Return'].std() * np.sqrt(252)      # 计算平均真实波动范围（ATR）   price_df['High'] = price_df['Close'] * (1 + np.random.uniform(0, 0.05, 100))   price_df['Low'] = price_df['Close'] * (1 - np.random.uniform(0, 0.05, 100))   price_df['TR'] = price_df[['High', 'Low', 'Close']].apply(lambda x: max(x['High'] - x['Low'], abs(x['High'] - x['Close']), abs(x['Low'] - x['Close'])), axis=1)   price_df['ATR'] = price_df['TR'].rolling(window=14).mean()      # 计算成交量加权平均价格（VWAP）   price_df['VWAP'] = (price_df['Close'] * price_df['Volume']).cumsum() / price_df['Volume'].cumsum()      # 计算买卖价差（Bid-Ask Spread）   bid_price = order_book_df[order_book_df['BidVolume'] > 0]['Price'].max()   ask_price = order_book_df[order_book_df['AskVolume'] > 0]['Price'].min()   spread = ask_price - bid_price      # 计算市场深度（Market Depth）   market_depth = order_book_df[['BidVolume', 'AskVolume']].sum()      # 计算订单簿不平衡（Order Book Imbalance）   buy_volume = order_book_df['BidVolume'].sum()   sell_volume = order_book_df['AskVolume'].sum()   imbalance = (buy_volume - sell_volume) / (buy_volume + sell_volume)      # 打印结果   print("Volatility:", volatility)   print("Historical Volatility:", historical_volatility)   print("Average True Range (ATR):", price_df['ATR'].iloc[-1])   print("VWAP:", price_df['VWAP'].iloc[-1])   print("Bid Price:", bid_price)   print("Ask Price:", ask_price)   print("Bid-Ask Spread:", spread)   print("Market Depth:", market_depth)   print("Order Book Imbalance:", imbalance)   `

### 5.总结

通过结合波动性、流动性和订单簿数据，投资者可以更全面地分析市场动态，评估风险和制定交易策略。波动性指标如标准差、历史波动率和ATR可以帮助评估价格变动的幅度，而流动性指标如成交量、VWAP、买卖价差、换手率和订单簿不平衡可以帮助评估股票的交易难易程度和成本。订单簿数据提供了市场深度和订单流的信息，进一步增强了对市场行为的理解。