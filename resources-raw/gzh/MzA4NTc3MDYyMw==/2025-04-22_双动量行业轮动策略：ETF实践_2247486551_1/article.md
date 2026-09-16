# 双动量行业轮动策略：ETF实践

InfinityQuant 映翡量化 2025-04-22 18:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486551&idx=1&sn=f96b3ef60f0d039a79a785bf35ea9d6f&chksm=9e7272990ac88408f41a3b086f3b76d1aef66bcf96a4847ec2462a108ad0566898dba09388de#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486551&idx=1&sn=f96b3ef60f0d039a79a785bf35ea9d6f&chksm=9e7272990ac88408f41a3b086f3b76d1aef66bcf96a4847ec2462a108ad0566898dba09388de#rd)

双动量行业轮动策略（Dual-Momentum Sector Rotation） 是一种基于动量投资的交易策略，结合了相对动量（Relative Momentum）和绝对动量（Absolute Momentum），通过定期轮动投资于表现最好的行业板块来追求超额回报，同时在市场趋势向下时切换到低风险资产以降低风险。该策略源自 Gary Antonacci 的研究，特别是在其著作《Dual Momentum Investing》中详细阐述，广泛应用于股票、ETF 等资产类别。

  

策略介绍——《151 Trading Strategies》的4.1.2

![](assets/001.png)

![](assets/002.png)

核心概念

1.  相对动量（Relative Momentum）：
    

-   比较不同行业板块（或资产）在特定时间段（通常为 6 至 12 个月）的回报率。
    
-   选择表现最好的几个板块（例如排名靠前的板块）进行投资。
    
-   假设近期表现强的资产会继续保持强势（动量效应）。
    

3.  绝对动量（Absolute Momentum）：
    

-   检查所选板块的绝对回报是否为正（即价格高于过去某时间点的价格）。
    
-   仅投资于绝对动能为正的板块（即趋势向上的板块）。
    
-   如果板块的绝对动能为负（趋势向下），则转向低风险资产，如债券 ETF或者黄金ETF（例如 AGG、GLD）或现金。
    

5.  行业轮动（Sector Rotation）：
    

-   定期（通常每月）重新评估各行业板块的动能，调整投资组合。
    
-   投资于表现最好的行业板块，卖出表现较差的板块。
    

7.  市场趋势判断：
    

-   使用市场指数（如标普 500，SPY）的动能作为“金丝雀信号”（canary signal）。
    
-   如果市场整体趋势向上（SPY 的绝对动能为正），投资于高动能行业板块。
    
-   如果市场趋势向下（SPY 的绝对动能为负），则将资金全部配置到低风险资产（如债券 ETF或者黄金ETF）。
    

策略步骤

1.  选择投资标的：通常使用行业 ETF（如 SPDR 系列：XLK、XLF、XLE 等）代表不同行业板块。
    
2.  计算动能：
    

-   相对动能：计算每个板块过去 12 个月的回报率，排名靠前的板块为候选。
    
-   绝对动能：检查候选板块的 12 个月回报是否为正。
    

4.  市场趋势判断：计算 SPY 的 12 个月绝对动能，判断市场是否处于上升趋势。
    
5.  投资决策：
    

-   如果 SPY 趋势向上，投资于排名靠前且绝对动能为正的前 N 个板块（例如 N=4）。
    
-   如果 SPY 趋势向下，或没有板块满足绝对动能要求，投资于黄金ETF（GLD）。
    

7.  定期再平衡：每月末重新计算动能，调整投资组合。
    

* * *

Python 案例

以下是一个基于双动量行业轮动策略的 Python 实现，使用 SPDR 行业 ETF 作为投资标的。代码包括数据获取、动能计算、投资组合再平衡等步骤。

环境准备

-   依赖库：pandas, yfinance, numpy
    
-   数据来源：通过 yfinance 获取行业 ETF 和 SPY 的历史价格
    
-   回测周期：2010-01-01 至 2025-04-22
    
-   投资标的：SPDR 行业 ETF（XLB, XLE, XLF, XLI, XLK, XLP, XLU, XLV, XLY）及黄金ETF（GLD）
    

```
import yfinance as yf
```

结果

![](assets/003.png)

年化收益率 (CAGR): 25.78%夏普比率: 1.60最大回撤: -23.09%，跑赢SPY。

  

改良后在A股市场的全部基金里进行了回测

![](assets/004.png)

![](assets/005.png)

2017年以来，年化收益率: 14.57% 夏普比率: 0.82，最大回撤: -17.45%，跑赢沪深300。

改进点：

1.非行业ETF，而是全部基金包括LOF等。

2.增加了低波动的因子。

3.未根据市场趋势判断。但是实际上会买到黄金ETF或者国债ETF。