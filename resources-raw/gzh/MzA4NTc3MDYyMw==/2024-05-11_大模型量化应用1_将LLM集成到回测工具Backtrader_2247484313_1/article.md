# 大模型量化应用1:将LLM集成到回测工具Backtrader算法交易框架中

小燕子搬砖 映翡量化 2024-05-11 21:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484313&idx=1&sn=8dee0be2a8b24bd6d2fbfb0f676457c6&chksm=9ef36e7136cc34afc45ee1e5f95cae2afdc11e670c55fc7701f431f51ff470a5f502e52ac7aa#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484313&idx=1&sn=8dee0be2a8b24bd6d2fbfb0f676457c6&chksm=9ef36e7136cc34afc45ee1e5f95cae2afdc11e670c55fc7701f431f51ff470a5f502e52ac7aa#rd)

![](assets/001.gif)

**1\. 目的：**算法交易利用数学模型和自动化软件程序执行交易，以减少人为干预。本实验通过Backtrader平台，集成大型语言模型，以期提高交易策略的决策质量。

**2\. 步骤：**

-   **导入库：** 引入必要的Python库和模块。
    
-   **定义策略：** 创建策略的子类，定义参数和指标。
    
-   **实现逻辑：** 编写`next()`方法处理交易信号，决定何时买入或卖出。
    
-   **加载数据：** 准备并加载历史市场数据。
    
-   **设置引擎：** 初始化回测引擎（Cerebro）。
    
-   **添加策略和数据：** 将策略和数据添加到引擎中。
    
-   **运行回测：** 执行回测，查看策略表现。
    
-   **分析结果：** 审查并分析回测结果。
    
-   **可视化：** 绘制结果，可视化性能指标。
    

  

简单的代码实例，参考backtrader网站：

from datetime import datetime

import backtrader as bt

\# Create a subclass of Strategy to define the indicators and logic  
  

classSmaCross(bt.Strategy):  
   # list of parameters which are configurable for the strategy  
   params = dict(  
       pfast=10,  # period for the fast moving average  
       pslow=30   # period for the slow moving average  
   )  
   def\_\_init\_\_(self):  
       sma1 = bt.ind.SMA(period=self.p.pfast)  # fast moving average  
       sma2 = bt.ind.SMA(period=self.p.pslow)  # slow moving average  
       self.crossover = bt.ind.CrossOver(sma1, sma2)  # crossover signal  
  
   defnext(self):  
       ifnot self.position:  # not in the market  
           if self.crossover > 0:  # if fast crosses slow to the upside  
               self.buy()  # enter long  
  
       elif self.crossover < 0:  # in the market & cross to the downside  
           self.close()  # close long position  
  
cerebro = bt.Cerebro()  # create a "Cerebro" engine instance  
  
\# Create a data feed  
data = bt.feeds.YahooFinanceData(dataname='MSFT',  
                                fromdate=datetime(2011, 1, 1),  
                                todate=datetime(2012, 12, 31))  
  
cerebro.adddata(data)  # Add the data feed  
  
cerebro.addstrategy(SmaCross)  # Add the trading strategy  
cerebro.run()  # run it all  
cerebro.plot()  # and plot it with a single command

# 

# **3.交易策略实例**

## **A.止损策略：**

##       (1)基于ATR的止损：利用ATR指标将止损设置在低于目标价格的ATR倍数，根据当前市场波动提供缓冲。

##       (2)技术止损：使用SMA作为基线来设置止损，确保根据市场条件进行动态调整。

##       (3)复合止损：结合ATR和技术止损方法，选择更保守的价值，增强风险管理框架。

## **B.仓位管理：**

    根据目标价格和止损价格之间的差额计算每笔交易的规模，确保每笔交易只有特定比例的投资组合面临风险（通常设置为2%）。

## **C.技术指标：**

(1)简单移动平均线（SMA）和指数移动平均线（EMA）：确定市场趋势。SMA设置为30天，EMA设置为50天，提供对短期和中期趋势。

(2)相对强弱指数（RSI）：设置为14天，RSI测量价格走势的速度和变化，以表明超买或超卖情况。

(3)移动平均收敛发散（MACD）：这包括12天的快速周期、26天的缓慢周期和9天的信号周期。MACD有助于围绕趋势变化确定潜在的买入或卖出机会。

(4)平均真实范围（ATR）：在14天内用于测量市场波动和设置动态止损订单。

(5)斐波那契水平：在30天的窗口内计算，根据历史价格走势确定潜在的支撑和阻力水平。

## **D.更多扩展：**以上指标可以用其他因子替代。

# **4\. LLM集成：**该模型处理这些指标以确定最佳买入或卖出点，或者在条件都不利时选择不作为。此外，该系统具有自动化风险管理功能，例如动态止损设置，提高决策准确性和损失缓解。LLM用于处理这些指标并生成交易信号（买入、卖出或持有），并分配置信度级别。这种方法利用模型分析数据中复杂模式和关系的能力，这些可能是人类交易者难以察觉的。【这段代码还没研究明白呢】

from pydantic import BaseModel, Field, conint, constr, field\_validator  
from langchain.output\_parsers import PydanticOutputParser  
  
classTradingDecision(BaseModel):  
   """  
   A model to encapsulate trading decisions, including confidence level, action, and rationale.  
  
   Attributes:  
       confidence\_level (conint): Represents confidence in the decision (0-10).  
       action (constr): Specifies the trade action ('SELL', 'BUY', or 'CHECK').        reason (str): Explains the basis of the trading decision.  
   """  
  
   confidence\_level: conint(ge=0, le=10) = Field(  
       description="An integer between 0 to 10 indicating how confident the decision is."  
   )  
   action: constr() = Field(  
       description="A string that indicates the trading decision to be taken: 'SELL', 'BUY', or 'CHECK'."  
   )  
   reason: str = Field(  
       description="A textual explanation detailing the reason for the trading decision based on given indicators and information."  
   )  
  
   @field\_validator('action')  
   defcheck\_action(cls, value):  
       if value notin \["SELL", "BUY", "CHECK"\]:  
           raise ValueError("Action must be 'SELL', 'BUY', or 'CHECK'")  
       return value

## 

## **5.执行：**策略的next()方法每天处理传入的价格数据：

        （1）首先检查是否满足足够的数据长度的条件。

        （2）如果条件有利，则执行LLM分析，同时考虑数量、波动性和趋势指标。

        （3）根据LLM的建议和信心水平，交易以动态止损调整和利润目标执行。

  

# **6.结果图形化：**使用Backtrader的分析器单元评估交易表现。分析器是评估交易策略有效性的重要工具，它们提供了对交易系统内发生情况的全面分析，对于完善策略和做出明智的交易决策至关重要。

\# Adding analyzers  
   cerebro.addanalyzer(bt.analyzers.TradeAnalyzer, \_name="trade\_analyzer")  # Analyzer for trade statistics  
   cerebro.addanalyzer(bt.analyzers.AnnualReturn, \_name="annual\_return")  # Yearly returns  
   cerebro.addanalyzer(bt.analyzers.SharpeRatio, \_name="sharpe\_ratio", riskfreerate=0.0)  # Sharpe Ratio  
   cerebro.addanalyzer(bt.analyzers.DrawDown, \_name="drawdown")  # Drawdown statistics

**7.结果分析：**通过在SPY（标普500ETF）的历史数据上进行回测，评估了LLM在特定时期的表现。LLM的任务是审查市场位置并做出交易决策。结果显示，LLM可以显著简化复杂的交易策略，通过同时解释和操作多个指标，提供了人类交易者难以复制的全面市场分析。

**8\. 总结与展望：**结果表明，LLM在有限的交易范围内表现出谨慎但成功的交易表现。专注于盈利的短期交易表明了潜在的成功策略，尽管需要更多数据（更多交易）来广泛评估其有效性。风险指标（夏普比率和最大回撤）表明，交易方法很好地管理了风险，尽管夏普比率为1.0表明回报与承担的风险成正比。本实验仅是将一个非常基本的交易策略应用于一个时间框架，以验证LLM是否能理解并解释指标和价格数据以做出正确决策。对于实际应用，需要进一步的研究和发展，以确保资产的最终年回报为正。

![](assets/002.jpg)

关于模型和实战，持续研究中…

需要先学习一下langchain原理：

![](assets/003.jpg)

![](assets/004.jpg)