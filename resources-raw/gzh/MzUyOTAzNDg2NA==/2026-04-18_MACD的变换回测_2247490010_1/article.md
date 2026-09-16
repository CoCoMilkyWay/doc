# MACD的变换回测

fintechhaibin FinTechHi 2026-04-18 21:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490010&idx=1&sn=94410f191cf6c88950f0e0189b87026b&chksm=fb1a7e90f45df50ea63409e8da12f48a0a45e979ce4cf1c45e79b5b60600dfb549ea60cebe82#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490010&idx=1&sn=94410f191cf6c88950f0e0189b87026b&chksm=fb1a7e90f45df50ea63409e8da12f48a0a45e979ce4cf1c45e79b5b60600dfb549ea60cebe82#rd)

①MACD = EMA12 − EMA26  
②不同价格的标的，MACD值不同，就没法截面比较或设置阈值  
③用ATR做归一化，即通过趋势强度除以波动幅度。  
④MACD\_ = (EMA12 - EMA26) / ATR26 \* 100 (100的作用只是放大数值，图会更清楚点。)  
⑤MACD\_ 的N日EMA。（N：默认9）  
⑥趋势力度除以当前市场波动，表示具体标的相对趋势强度，值为正表示多头趋势，为负则为空头趋势，绝对值越大，趋势相对于当前波动越极端。  
⑦重测中发现重点是指标中的周期确定。  
⑧潜在的问题是暴跌暴涨时ATR很大，MACD‑V反而可能不大，会弱化 “趋势极强” 信号。

![图1](assets/001.jpg)

图1

![图2](assets/002.jpg)

图2

![图3](assets/003.jpg)

图3

![图4](assets/004.jpg)

图4