# 深度价外期权套利策略

InfinityQuant 映翡量化 2025-09-30 12:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487335&idx=1&sn=b805f186b7edeb55bfe8defccf154fcd&chksm=9e73dbc830d267c9cac4f243664b0c434a4fc084d478470470173d537c09cdf5444dd1fa6806#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487335&idx=1&sn=b805f186b7edeb55bfe8defccf154fcd&chksm=9e73dbc830d267c9cac4f243664b0c434a4fc084d478470470173d537c09cdf5444dd1fa6806#rd)

《Trading TP2 Option Violations》这篇文章探讨了期权定价中的“完全正性阶2”（Totally Positive of Order 2, TP2）属性及其在实际市场中的应用。基于Black-Scholes模型及其他理论模型中，看涨期权（Call）价格满足TP2属性，即较高行权价（Strike）看涨期权相对于较低行权价的价格比率随到期时间（Time-to-Expiry）增加（经股息和利息调整）。这加强了无日历价差套利（Calendar Spread Arbitrage）的条件，并限制了基础资产的鞅模型类型。类似地，看跌期权（Put）满足“符号反转阶2”（Sign-Reverse Rule of Order 2, RR2）属性。  

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

通过实证分析S&P 500指数（SPX）期权数据（2000-2022年），检验市场价格是否符合TP2/RR2。发现这些“异常”属性的情况比较罕见，通常在一两天内快速逆转，主要发生在深度价外（Deep Out-of-the-Money）行权价。“异常率”随时间波动，受市场条件影响：期权交易量较高时“异常率”上升，VIX（波动率指数）较高时“异常率”下降，SKEW（偏度指数）较高时看跌期权“异常率”上升，但整体市场变量解释力有限。“异常”多发生在短期快到期（看涨期权1-3个月，看跌期权1周内）。

作者认为这些“异常”是“近似套利”机会，并提出长短仓（Long-Short）交易策略：当“异常”发生时，长仓“低估”侧、短仓“高估”侧。通过历史回测，这些策略在单个交易中命中率极高（近完美），累计回报和风险调整回报（如Sharpe比率）大幅优于S&P 500指数（同期指数回报近300%）。

95%+的命中率。 平均夏普比率高于3。 隐藏在SPX选项中的“边缘套利”。

文章还讨论了策略的鲁棒性，包括使用中价（Mid Price）或买卖价差（Bid-Ask Spread）的保守假设，以及仅短仓或两行权价近似等变体。

![](assets/005.png)

![](assets/006.jpg)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5392317