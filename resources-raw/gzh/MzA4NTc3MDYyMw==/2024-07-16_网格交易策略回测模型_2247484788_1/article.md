# 网格交易策略回测模型

小燕子 映翡量化 2024-07-16 21:02 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484788&idx=1&sn=22cb9310ec42a7865e43a07bed8c77c5&chksm=9ec4986da80939ad6ca2243c67ee111ab81c0192fff4f889a3dfee5c5aaeb63a0be295e0a14e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484788&idx=1&sn=22cb9310ec42a7865e43a07bed8c77c5&chksm=9ec4986da80939ad6ca2243c67ee111ab81c0192fff4f889a3dfee5c5aaeb63a0be295e0a14e#rd)

![](assets/001.gif)

探索网格交易策略——一种简单而有效的方法，不依赖技术指标来确定趋势。这种策略是算法交易的绝佳候选者，我们使用Python的回测表明，在5分钟的时间范围内，在两个月的数据中，收益稳步增长，结果非常好，夏普比率接近5.7。

参考资料链接：https://youtu.be/YytCoeSq30E

##   

## 什么是网格交易

网格交易涉及在价格图表上创建一个价值网格。每当价格越过网格线时，我们都会同时打开多头头寸和空头头寸。每个开仓头寸的止盈率设置在下一条网格线上。这种策略在价格频繁波动的市场中蓬勃发展，使其特别适合较低的时间框架。

现在，我们将在python中实现网格策略，并在历史数据上进行回测。

  

# 步骤1：设置环境

首先，我们需要通过导入必要的库和下载数据集来设置我们的Python环境。我们将使用`yfinance`获取欧元/美元汇率（国内可以做期货、可转债，T+0的ETF）数据，使用`pandas`获取数据操作，`numpy`获取数值运算，`pandas_ta`获取技术分析指标。

import yfinance as yf

import pandas as pd

import numpy as np

import pandas\_ta as ta

\# Download the EUR/USD data for the last 59 days with a 5-minute interval

dataF = yf.download("EURUSD=X", start=pd.Timestamp.today() - pd.DateOffset(days=59), end=pd.Timestamp.today(), interval='5m')

**导入库**：

-   `yfinance`（yf）：从雅虎财经下载历史市场数据的Python库。
    
-   `pandas`（pd）：数据操作和分析库。
    
-   `numpy`（np）：用于数字运算的库。
    
-   `pandas_ta`（ta）：财务数据集的技术分析库。
    

**下载数据**：

我们使用`yfinance`下载2022年11月19日至2023年1月16日的欧元/美元汇率数据，间隔为5分钟。这为我们提供了适合我们网格交易策略的详细高频数据集。

#   

# 第2步：创建网格

在这一步中，我们创建一个值网格，该网格将决定我们的进入点和退出点。网格是价格图表上定期间隔的一系列水平线。每当价格越过网格线时，我们都会打开一个新的头寸。

grid\_distance = 0.005

midprice = 1.065

def generate\_grid(midprice, grid\_distance, grid\_range):

return np.arange(midprice - grid\_range, midprice + grid\_range, grid\_distance)

  

grid = generate\_grid(midprice=midprice, grid\_distance=grid\_distance, grid\_range=0.1)

**定义参数**：

-   `grid_distance = 0.005`：这定义了每条网格线之间的距离。它代表了我们将开立新头寸的价格增量。
    
-   `midprice = 1.065`：这是创建网格的中心价格。它可以设置为当前市场价格或任何其他参考价格。
    

> **重要信息：这些值必须根据市场、交易资产和考虑当前分析进行更改，因此每次您从Yfinance查询数据时，都会更新数据，本策略中的这些参数必须相应更新。**

**生成网格**：

-   `generate_grid`函数创建一系列从`midprice - grid_range`到`midprice + grid_range`的值，以`grid_distance`间隔。
    
-   `grid_range = 0.1`：这决定了中价以上和下方电网的总范围。
    

**创建网格**：

`grid`阵列包含我们将考虑开仓的所有价格水平。这构成了我们网格交易策略的支柱，使我们能够随着价格的波动系统地进入和退出交易。

#   

# 第3步：生成交易信号

在这一步中，我们根据我们创建的网格生成交易信号。每当价格越过网格线时，就会生成交易信号。这是通过遍历我们数据集中的每行来完成的，并检查该间隔的高价还是低价是否跨越任何网格线。

signal = \[0\] \* len(dataF)  
i = 0  
for index, row in dataF.iterrows():  
    for p in grid:  
        if min(row.Low, row.High) < p and max(row.Low, row.High) > p:  
            signal\[i\] = 1  
    i += 1  
dataF\["signal"\] = signal  
dataF\[dataF\["signal"\] == 1\]

**初始化信号**：

`signal = [0] * len(dataF)`：我们创建一个与数据集长度相同的零列表。此列表将存储我们的交易信号。

**对数据进行重述**：

我们使用`dataF.iterrows()`迭代数据集中的每行。

对于每行，我们检查价格是否越过任何网格线。这是通过将该行的高价和低价格的最小值和最高值与每条网格线进行比较来完成的。

**生成信号**：

如果网格线交叉（即最低价格低于网格线，最高价格高于网格线），我们将`signal`列表中的相应条目设置为1。

这表明在该时间间隔内生成了交易信号。

**向DataFrame添加信号**：

-   `dataF["signal"] = signal`：我们将信号列表作为新列添加到我们的DataFrame中。
    
-   `dataF[dataF["signal"] == 1]`：这过滤了DataFrame，以仅显示生成交易信号的行。
    

  

通过生成这些交易信号，我们确定了价格越过网格线的确切时间点，表明了潜在的交易条目。这种系统方法确保我们在定义的网格中捕获所有相关的价格走势。

#   

# 第4步：准备回测

在这一步中，我们通过计算平均真实范围（ATR）和定义信号函数来准备用于回测的数据集。ATR是一种波动性指标，可帮助我们设置动态止损和止盈水平。

dfpl = dataF\[:\].copy()  
  
def SIGNAL():  
    return dfpl.signal  
  
dfpl\['ATR'\] = ta.atr(high=dfpl.High, low=dfpl.Low, close=dfpl.Close, length=16)  
dfpl.dropna(inplace=True)

**  
‍**

**复制数据框架**：

`dfpl = dataF[:].copy()`：我们创建原始数据集的副本，以避免在回测过程中直接修改它。这确保了我们的原始数据保持不变。

**定义信号功能**：

`def SIGNAL()`：此函数从我们的DataFrame返回信号列。它将在回测期间用于访问生成的交易信号。

**计算平均真实范围（ATR）：**

`dfpl['ATR'] = ta.atr(high=dfpl.High, low=dfpl.Low, close=dfpl.Close, length=16)`：我们使用16个间隔的周期来计算ATR。ATR是市场波动的衡量标准，有助于设定适当的止损和止盈水平。

`high=dfpl.High, low=dfpl.Low, close=dfpl.Close`：这些参数指定了用于计算ATR的高价、低价和收盘价。

**清理数据**：

`dfpl.dropna(inplace=True)`：我们删除任何缺少值的行，以确保我们回测过程的完整性。此步骤对于准确可靠的回测结果至关重要。

ATR提供了波动性的动态衡量标准。通过计算ATR和定义信号函数，我们为回测框架配备了必要的工具，以评估网格交易策略的性能。

#   

# 第5步：实施和运行回测

在这一步中，我们使用`backtesting` 库实施我们的交易策略，并运行回测来评估其性能。 我们定义了一个自定义策略类，并配置了回测参数。  

from backtesting import Strategy  
from backtesting import Backtest  
import backtesting  
  
class MyStrat(Strategy):  
    mysize = 50  
      
    def init(self):  
        super().init()  
        self.signal1 = self.I(SIGNAL)  
  
    def next(self):  
        super().next()  
        slatr = 1.5 \* grid\_distance  \# Stop loss distance  
        TPSLRatio = 0.5  \# Take profit to stop loss ratio  
  
        if self.signal1 == 1 and len(self.trades) <= 10000:  
            \# Sell position  
            sl1 = self.data.Close\[-1\] + slatr  
            tp1 = self.data.Close\[-1\] - slatr \* TPSLRatio  
            self.sell(sl=sl1, tp=tp1, size=self.mysize)  
  
            \# Buy position  
            sl1 = self.data.Close\[-1\] - slatr  
            tp1 = self.data.Close\[-1\] + slatr \* TPSLRatio  
            self.buy(sl=sl1, tp=tp1, size=self.mysize)  
  
\# Running the backtest  
bt = Backtest(dfpl, MyStrat, cash=50, margin=1/100, hedging=True, exclusive\_orders=False)  
stat = bt.run()  
stat

**导入库**：  

`from backtesting import Strategy, Backtest`：从`backtesting`库导入必要的类，以定义和运行我们的策略。

`import backtesting`：导入`backtesting`库。

**定义策略类**：

`class MyStrat(Strategy)`：我们通过继承`Strategy`类来创建一个自定义策略类。

`mysize = 50`：定义每笔交易的头寸大小。

**初始化**：

`def init(self)`：初始化策略。

`self.signal1 = self.I(SIGNAL)`：使用前面定义的`SIGNAL`函数访问交易信号。

**定义交易逻辑**：

`def next(self)`：定义执行交易的逻辑。

`slatr = 1.5 * grid_distance`：根据网格距离计算止损距离。

`TPSLRatio = 0.5`：设置止盈止损比。

**执行交易**：

如果生成信号（`self.signal1 == 1`），并且交易数量小于或等于10,000：

**出售位置**：

-   `sl1 = self.data.Close[-1] + slatr`：将止损设置为当前收盘价以上。
    
-   `tp1 = self.data.Close[-1] - slatr * TPSLRatio`：将止盈设置为当前收盘价以下。
    
-   `self.sell(sl=sl1, tp=tp1, size=self.mysize)`：执行销售订单。
    

**购买位置**：

-   `sl1 = self.data.Close[-1] - slatr`：将止损设置为当前收盘价以下。
    
-   `tp1 = self.data.Close[-1] + slatr * TPSLRatio`：将止盈设置为当前收盘价以上。
    
-   `self.buy(sl=sl1, tp=tp1, size=self.mysize)`：执行购买订单。
    

**运行回测**：

-   `bt = Backtest(dfpl, MyStrat, cash=50, margin=1/100, hedging=True, exclusive_orders=False)`：配置回测参数。
    
-   `cash=50`：初始现金余额。
    
-   `margin=1/100`。
    
-   `hedging=True`：允许套期保值。
    
-   `exclusive_orders=False`：允许重叠订单。
    
-   `stat = bt.run()`：运行回测并存储统计数据。
    

  

因此，通过这次回测运行，我们可以评估我们网格交易策略的表现。`stat`对象包含详细的指标和见解，有助于我们了解该战略的有效性。

  

# 第6步：分析回测结果

  

![](assets/002.png)

## 总结：

-   **持续时间**：该策略经过57天21小时的测试，提供了一个全面的评估期。
    
-   **曝光时间**：99.14%，表明该策略几乎总是在市场上。
    

##   

## 绩效指标：

-   **最终股权**：136.02美元，从50美元起。
    
-   **股票峰值**：156.59美元，显示有更高的收益潜力。
    
-   **回报率**：172.04%，反映出可观的盈利能力。
    
-   **买入和持有回报**：4.23%，展示了该策略的卓越表现。
    
-   **年化回报率**：37364.62%，由于回测时间短，极高。
    
-   **年化波动性**：46309.60%，表示高风险和频繁交易。
    

##   

## 风险调整指标：

-   **锐利比率**：0.81，表明风险调整后的回报率适中。
    
-   **Sortino比率**：1089.28，表明良好的下行风险管理。
    
-   **Calmar比率**：2194.58，反映相对于最大提款的高回报。
    

##   

## 缩减：

-   **最大亏损**：-17.03%，显著但可控的下降。
    
-   **平均缩减**：-1.16%，相对较低。
    
-   **最大缩减持续时间**：近10天，显示最长的恢复期。
    
-   **平均缩减持续时间**：少于7小时，表示快速恢复。
    

##   

## 交易活动：

-   **交易数量**：1698，由于网格交易策略，频率很高。
    
-   **胜率**：73.03%，成功率非常高。
    
-   **最佳交易**：0.87%，持续小幅收益。
    
-   **最差交易**：-0.85%，控制亏损。
    
-   **平均交易**：0.10%，反映了许多小交易的累积效应。
    
    ‍