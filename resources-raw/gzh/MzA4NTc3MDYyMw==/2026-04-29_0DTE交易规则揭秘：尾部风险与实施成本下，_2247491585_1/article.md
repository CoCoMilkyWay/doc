# 0DTE交易规则揭秘：尾部风险与实施成本下，如何通过条件择时盈利（有代码）

InfinityQuant 映翡量化 2026-04-29 09:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491585&idx=1&sn=e847ba2443d55a2dcc3dd5005adbe248&chksm=9eefc635e586c1268f17787f6662597c13b85399c497863af98ad515ed1334d578a5f5e0d35d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491585&idx=1&sn=e847ba2443d55a2dcc3dd5005adbe248&chksm=9eefc635e586c1268f17787f6662597c13b85399c497863af98ad515ed1334d578a5f5e0d35d#rd)

《0DTE Trading Rules》（2023年12月初稿，最新版本2026年3月18日）主要研究S&P 500指数（SPX/SPXW）零日到期（0DTE）期权的已实现收益、常见多腿结构策略的表现，重点考察尾部风险（tail risk）、实施成本（transaction costs、slippage）以及战术性择时（tactical timing）的影响。 

核心思想

-   0DTE期权的独特特性：0DTE期权（当日到期）存在显著的方差风险溢价（variance risk premium, VRP）——隐含波动率通常高于实际实现波动率，卖方理论上能从中获利。但由于持有期极短（往往仅几小时），收益分布高度偏斜（skewed）、肥尾（fat-tailed），受单一极端事件（尾部风险）影响极大。
-   策略构建：作者系统考察了七类标准期权结构（包括方向性、波动率类、价差类等），结合不同 moneyness 配置（从0.98到1.02，细粒度步长）。策略在固定时间（如10:00 ET）开仓，持仓至收盘到期（16:00 ET）。此外还测试了不同入场时间（如13:00、15:00 ET）的敏感性。
-   分析维度：

-   无条件表现（unconditional）：全样本及子期间的平均回报。
-   条件表现（conditional）：基于VIX波动率 regime、结构断点（如2022年每日到期扩张）、策略自身历史表现等进行择时。
-   实施现实性：纳入交易成本、滑点（slippage）、流动性特征，评估“可实施PNL”（implementable PNL）。
-   尾部风险诊断：最大回撤、VaR、极端损失概率等。

单纯捕捉VRP并不容易，流行0DTE策略的回报高度不稳定，大多受指数回报的偏度（skewness）驱动。

主要结论与发现

-   无条件策略表现较弱：大多数流行0DTE结构（如ATM straddle/strangle、bull call/bear put spreads、ratio spreads、risk reversals等）在扣除成本和考虑尾部风险后，平均回报统计上不显著或不具吸引力。卖方虽能捕捉正的VRP，但肥尾分布导致偶尔的大额损失抹平收益，夏普比率通常较低。 
-   条件规则有潜力：简单条件过滤（如基于VIX水平、结构断点或策略自身近期表现）能显著改善结果。特别是对选定策略或“top-k basket”（篮子组合）应用出样条件规则（conditional out-of-sample rules）时，可实现夏普比率约1.01–1.27。简单线性模型（如ridge-logit）表现最佳，某些分类器也有潜力。作者指出：“一些SPX 0DTE条件规则确实能盈利，尤其是基于策略自身表现进行条件化时。”   
    ![](assets/001.png)

-   尾部风险与实施挑战：即使有正的期望收益，策略的尾部风险（极端损失）很高；实施中交易成本和滑点会进一步侵蚀利润。2022年每日到期扩张前后存在结构断点，市场微观结构变化影响策略有效性。
-   战术择时的重要性：入场时间、波动率环境等因素对表现影响显著。无纪律的交易容易因宽bid-ask spread和尾部事件而亏损，而纪律性的、基于规则的条件交易能更好地提取溢价。
-   整体建议：0DTE提供提取方差风险溢价的机会，但不是“轻松钱”。成功依赖于严格的风险管理、成本控制和动态择时，而非简单持有流行结构。零售交易者若无系统规则，往往表现不佳。

总结：作者系统拆解了0DTE交易的现实性，结论偏谨慎——无条件0DTE策略吸引力有限，但精心设计的条件规则结合尾部风险控制和战术择时，能在样本外实现较稳健的表现。

论文附带代码，包含数据面板、Python分析脚本，支持无条件/条件分析、尾部风险计算等，便于验证和扩展研究。https://github.com/vilkovgr/0dte-strategies

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=4641356

PDF和代码已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)