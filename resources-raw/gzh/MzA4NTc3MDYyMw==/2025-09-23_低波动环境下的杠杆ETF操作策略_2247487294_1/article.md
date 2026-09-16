# 低波动环境下的杠杆ETF操作策略

InfinityQuant 映翡量化 2025-09-23 20:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487294&idx=1&sn=b8408b05ab1e9abc9383781706f5fbd7&chksm=9ed2613591730473b22f249a24512ccd072526fa8d97adf591c19fa1159970ceb2bd8d61bf56#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487294&idx=1&sn=b8408b05ab1e9abc9383781706f5fbd7&chksm=9ed2613591730473b22f249a24512ccd072526fa8d97adf591c19fa1159970ceb2bd8d61bf56#rd)

**Quantpedia.com最新一篇文章提出了一种基于波动率过滤器的策略，以优化在低波动率环境中投资杠杆ETF（如SPXL和SPXU）的表现。文章受《The Volatility Edge, A Dual Approach For VIX ETNs Trading》的启发，设计了一种通过比较短期实际波动率（基于SPY近期回报的标准差）和隐含波动率（VIX指数的平均值）来调整杠杆ETF投资暴露的策略。**  

对于SPXL（3倍做多标普500的ETF），当VIX隐含波动率高于SPY的短期实际波动率时，表明市场预期波动大于实际波动，此时适合投资SPXL，以利用稳定的上升趋势并减少波动拖累（volatility drag）的影响。研究通过回测（2013年7月至2025年7月）发现，使用较长的实际波动率窗口（例如20天）和较短的VIX平均窗口（例如10-20天）能显著提高回报，同时降低波动和最大回撤，优于基准SPY的表现。

![](assets/001.png)

对于SPXU（3倍做空标普500的ETF），策略相反，当实际波动率高于隐含波动率时投资SPXU，以捕捉市场下跌的机会。然而，由于2013-2025年为强势牛市，SPXU策略表现较弱，未能超越基准，但相较于直接持有SPXU有所改善，提示其可能作为选择性对冲工具。

![](assets/002.png)

总体而言，通过波动率过滤器可有效管理杠杆ETF的风险和回报，尤其在SPXL上表现更优，而SPXU策略更适合作为未来对冲研究的补充。

https://quantpedia.com/leveraged-etfs-in-low-volatility-environments/

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5316487