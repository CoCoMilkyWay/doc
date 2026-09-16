# 一个高级指数：CBOE VIX尾部对冲指数（VXTH）

InfinityQuant 映翡量化 2025-03-21 21:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486231&idx=1&sn=2776ad5fbeff94d00a6aea35864c677c&chksm=9e5d2e931c5d2a998264f866bf550f89edde012ed7530007fde3c4d7645010dbe2a657311cd0#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486231&idx=1&sn=2776ad5fbeff94d00a6aea35864c677c&chksm=9e5d2e931c5d2a998264f866bf550f89edde012ed7530007fde3c4d7645010dbe2a657311cd0#rd)

CBOE VIX尾部对冲指数（VXTH）是通过购买VIX看涨期权来对冲尾部风险（即极端市场下跌风险）的投资策略表现的指数。

![](assets/001.jpg)

指数核心思想，追踪一个投资组合的表现：  

  
✅买入并持有标普500指数（总回报指数，含股息再投资）；  
✅买入CBOE波动率指数（VIX）的一个月30Delta看涨期权。VIX看涨期权每月进行一次购买，这一过程被称为“展期”。

✅投资组合中VIX看涨期权的权重在每次展期时都会变化，具体取决于VIX的远期价值，这是一个衡量“黑天鹅事件”发生概率的指标。  

  

![](assets/002.jpg)

  

VXTH指数的强大力量来自于在股市大幅下跌时期，VIX看涨期权获得的异常高回报。这意味着不需要购买太多VIX看涨期权。为了进一步提高效率，VXTH经过精心校准：投资组合中VIX看涨期权的权重在每次展期时根据“黑天鹅”事件即将发生的可能性而变化。这有助于降低对冲成本，并在极端波动水平达到时实现VIX期权利润的货币化。这种对VIX期权头寸的货币化反过来意味着整体资本可以得到保留。

  

python的demo代码见：[使用期权和Python开发长期、系统的VIX黑天鹅对冲策略](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486227&idx=1&sn=b585f9c54a6dec7cc753c5c936b08358&scene=21#wechat_redirect)

  

指数编制方法：

https://cdn.cboe.com/api/global/us\_indices/governance/Cboe\_VIX\_Tail\_Hedge\_Index\_Methodology.pdf

  

核心内容也可以参考下图：

![](assets/003.jpg)

![](assets/004.jpg)

![](assets/005.jpg)