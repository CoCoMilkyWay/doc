# 5个波动性指标的实现

InfinityQuant 映翡量化 2025-01-15 18:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486041&idx=2&sn=ffd73e61401ee451e159fded590d5302&chksm=9ec9189ca88cf5ac50eeb3f80dab6496b119d180430c6ee904d4dcab9555ae766cc7f12c34a7#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486041&idx=2&sn=ffd73e61401ee451e159fded590d5302&chksm=9ec9189ca88cf5ac50eeb3f80dab6496b119d180430c6ee904d4dcab9555ae766cc7f12c34a7#rd)

波动性是金融市场的一类关键因子，反映了金融工具价格随着时间的推移的变化程度。投资者和交易员使用波动性指标因子来衡量市场不确定性并识别交易机会。

  

# 1.Chaikin波动率（CHV）

Chaikin波动指标衡量特定时期高价和低价之间的利差，有助于评估市场波动性。扩大的利差表明波动性增加，而缩小的利差表明波动性降低。

![](assets/001.png)

```
# This code only plots the indicator, not the candlestick chart.
```

关注CHV的急剧上涨或下跌；它们可以表明即将到来的价格变动。峰值和低谷往往在市场重大变化之前。

# 2.Donchian通道

Donchian通道是通过绘制特定时期内最高点和最低低点来创建的。它们帮助交易者识别突破和趋势逆转。

![](assets/002.png)

```
import yfinance as yf
```

价格突破通道上方或下方可能会预示着强劲的趋势。

# 3.凯尔特纳频道

**凯尔特纳通道使用平均真实范围（ATR）来创建波动性包络。它们由三条线组成：一条中央移动平均线和两条外线，由ATR的倍数偏移。**

**![](assets/003.png)**

```
import yfinance as yf
```

****凯尔特纳通道以外的价格走势表明了强劲动量或趋势逆转的可能性。****

# 4.相对波动指数（RVI）

****RVI将资产最近的波动率与给定时期的总波动率进行比较。****

****![](assets/004.png)****

```
# This code only plots the indicator, not the candlestick chart.
```

****RVI上升预示着加强趋势，而RVI下降则表明势头减弱。交叉和分歧可以确定进入或退出的机会。****

# 5.标准偏差

**标准差是衡量价格分散的简单而有效的指标。高标准差表示高波动性，而低标准差表示稳定性。**

**![](assets/005.png)**

```
# This code only plots the indicator, not the candlestick chart.
```

**标准差的飙升预示着波动性增加。调整策略，以应对不断变化的市场条件。**

  

利用Python，可以有效地实现这些指标，并根据特定的交易策略结合其他因子对您的投资组合进行策略回测优化处理。