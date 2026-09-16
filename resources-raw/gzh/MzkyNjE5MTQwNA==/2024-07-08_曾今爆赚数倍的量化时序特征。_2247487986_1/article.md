# 曾今爆赚数倍的量化时序特征。

樱落 量化前沿速递 2024-07-08 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487986&idx=1&sn=3440740db167ea4163544c19ce6e70eb&chksm=c3adb3dad809458d4871f2356191d9cca8709187e8282e5ae72c0ca0e9e9603ac2bdf42d6b5d#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487986&idx=1&sn=3440740db167ea4163544c19ce6e70eb&chksm=c3adb3dad809458d4871f2356191d9cca8709187e8282e5ae72c0ca0e9e9603ac2bdf42d6b5d#rd)

# 

  

**量化交易强特征！**

## 

简介

![](assets/001.png)

今天介绍在强势股中最强的一类特征，也是之前我最早接触的一类策略常常听大家说的，就是放量破前高，这类信息一般意味着有人有意愿吃掉所有的套牢盘，说明此类标的是非常强势的，后续上涨空间往往非常大。在市场早期听非常多的分享中，很多牛人交易员会结合底层逻辑+放量破前高进行交易，从而获得数倍收益的情况，尤其在币圈和美股中较为常用。

当然这个特征往往对于商品的价格预测也有着非常大的帮助，价格破前高的商品往往意味着供不应求，后期价格拉升的幅度也会非常大，有相关业务的朋友可以尝试一下。

## 

实现细节

![](assets/001.png)

1.  当日收盘价高于过去N天的最高价；
    
2.  昨日收盘价低于历史过去N天的最高价；
    
3.  放量；
    

`import pandas as pd      def breakout_with_volume_240(df, volume_increase_threshold=1.5, window=240):              df = df.sort_values('Date')              # 计算过去N天的最大值,        df['Prev_High1']  = df['High'].rolling(window=window, min_periods=1).max().shift(1)       df['Prev_High2']  = df['High'].rolling(window=window, min_periods=1).max().shift(2)                      # 今日收盘价>历史最高价 & 昨日收盘价 小于 之前的最高价       df['New_High']             = df['Close'] > df['Prev_High1']       df['YesterdayNotNew_High'] = df['Prev_High2'] > df['Close'].shift()                     # Calculate the increase in volume compared to the previous day's volume       df['Volume_Increase'] = df['Volume'] / df['Volume'].shift(1)              # Identify breakout points where new high is achieved with significant volume increase       df['Breakout'] = (df['New_High']) & (df['YesterdayNotNew_High'] ) & (df['Volume_Increase'] > volume_increase_threshold)              return df   `

##   

参考文献

![](assets/001.png)

1.  https://medium.com/@paullenosky/i-have-created-an-indicator-that-actually-makes-money-unlike-any-other-indicator-i-have-ever-seen-fd7b36aba975