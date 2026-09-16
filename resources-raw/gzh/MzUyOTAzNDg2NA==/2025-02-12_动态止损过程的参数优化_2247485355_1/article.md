# 动态止损过程的参数优化

fintechhaibin FinTechHi 2025-02-12 00:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485355&idx=1&sn=1ac94ae08e693d23ba9b05d729014234&chksm=fb69461f292345bc6fa7026cf332afa9026ba861a3925c2ae4f15ce8b6ebb3be16d55ced1f64#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485355&idx=1&sn=1ac94ae08e693d23ba9b05d729014234&chksm=fb69461f292345bc6fa7026cf332afa9026ba861a3925c2ae4f15ce8b6ebb3be16d55ced1f64#rd)

关于止损，之前 [止损和止盈](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484880&idx=1&sn=6f375be299b05c3b8d3d0d059b9afa17&scene=21#wechat_redirect) 文章中已经介绍，本文是基于动态波动率的止损，并使用贝叶斯优化（Bayesian）和前向优化（walk-forward optimization.）来优化输入参数。

1.安装依赖

```
pip install bayesian-optimization
```

注：贝叶斯优化库提供了使用贝叶斯优化技术来优化复杂函数的工具。它特别适用于机器学习模型中的超参数调优、黑箱函数的优化，以及高效地寻找目标函数的最大值。该库使用概率模型来决定下一步从哪里采样，平衡了对搜索空间的探索与对已知优良区域的利用。其他依赖的库若没有，自行安装即可。

2.导入包

```
import warnings
```

3.数据

从Yahoo Finance API获取特定股票或指数的金融数据（之前有人问yfinance），如果想换成国内akshare，tushare，或者自己手头的数据源的话，则就不需要这个包了。

```
def fetch_data(symbol, start, end):
```

4.计算指标

本实例选择了4个技术指标：ATR、EMA、MACD、RSI，用于生成买卖信号。通过这些信号确定交易入场和出场的最佳时点。并通过这些信号基于累积收益来确定最佳止损阈值。

①RSI

RSI是一个相对强弱指数指标，其计算逻辑为：计算价格变化->计算平均涨幅->计算平均跌幅->计算相对强度->计算RSI。

其中两个参数，series 是一个Pandas Series对象，包含时间序列数据（本示例中是一只股票每日的收盘价）。period 参数代表窗口周期，默认是14，可以根据自己的分析结果做调整，RSI的值范围是0到100，日常理解下，其中70以上通常被视为超买，30以下通常被视为超卖。

```
def compute_RSI(series, period=14):
```

②计算所有指标

```
def calculate_indicators(data):
```

其中：

-   TR：是当前最高价与最低价之间的差值，或者是当前最高价与前一收盘价之间的差值，或者是当前最低价与前一收盘价之间的差值，取这三个值中的最大值。本例是后者。
    
-   ATR：对TR计算14个时间窗口的简单移动平均值。
    
-   EMA12和EMA26：分别计算窗口为12和26的指数移动平均线（ewm）。
    
-   MACD：EMA12和EMA26之间的差值。
    
-   Signal：计算9个窗口的MACD的指数移动平均值。
    
-   RSI：体现股票波动性。
    
      
    

指数加权移动平均线（EMA）给予近期数据更高的权重，因此比简单移动平均线（SMA）更能反映价格的变化趋势。这是因为它采用了指数衰减的方式来计算平均值。

这种衰减方式使得最近的数据点对最终结果的贡献更大，而较远的数据点对最终结果的贡献则逐渐减小。我们通过公式做进一步理解：

```
EMA(t) = (α * P(t)) + [(1 - α) * EMA(t-1)]
```

其中EMA(t) 是时间 t 的指数加权移动平均线值。P(t) 是时间 t 的价格或数据点。EMA(t-1) 是时间 t-1 的指数加权移动平均线值。α 是衰减因子，取值范围是0到1，其公式为：

```
α = 2 / (n + 1)
```

其中 n 是窗口大小。例如，对于12期指数移动平均线，n 为12，所以 α 的值为 2 / (12 + 1) = 0.1538。

由于 α 的值小于1，所以随着时间 t 的增加，EMA(t) 对 P(t) 的贡献会逐渐减小，而对 EMA(t-1) 的贡献会逐渐增大。打破砂锅问到底看：

-   初始阶段：当 t 较小，即数据点较少时，EMA(t) 主要依赖于 P(t)。因为 EMA(t-1) 还没有值，或者它的值对 EMA(t) 的贡献较小。
    
-   随着 t 的增加：EMA(t) 的计算公式中，P(t) 的权重由 α 决定，而 EMA(t-1) 的权重由 1 - α 决定。由于 α 的值小于1，所以 EMA(t) 对 P(t) 的贡献会逐渐减小，而对 EMA(t-1) 的贡献会逐渐增大。
    
-   最终阶段：当 t 很大，即数据点很多时，EMA(t) 主要依赖于 EMA(t-1)。因为 P(t) 的值对 EMA(t) 的贡献已经非常小。
    

  

5.计算动态止损水平

用于计算买入和卖出止损水平。函数接受两个参数：data和atr\_multiplier。data是上面指标计算后的结果数据DataFrame。atr\_multiplier是要确定的止损优化参数。

```
def calculate_stop_loss(data, atr_multiplier):
```

6.优化止损参数

① 回测逻辑

-   ATR乘数调整：取atr\_multiplier和指定的min\_atr\_multiplier二者最大。
    
-   ATR计算：使用指定的窗口大小计算平均真实范围（ATR），以此来衡量波动性。
    
-   止损位计算：利用ATR和调整后的乘数计算动态买入和卖出止损水平。
    
-   信号生成：基于止损水平、MACD和RSI生成买卖信号。
    
-   执行最低持有期：确保买卖信号遵守最低持有期，以防止过于频繁的交易。
    
-   收益计算：根据信号计算每日收益和策略收益，并计算累积收益。
    
-   最终收益：返回策略的最终累积收益，这将作为优化的目标。
    

```
def backtest_strategy(atr_multiplier, atr_window, data, min_atr_multiplier, min_holding_period):
```

②优化参数

-   确定目标函数：上面回测函数返回的策略的最终累积收益。
    
-   参数边界设置：为ATR乘数和窗口设置边界（例如，ATR乘数：最小值到3，ATR窗口：5到60周期）。
    
-   贝叶斯优化设置：使用目标函数和参数边界初始化贝叶斯优化器。
    
-   优化执行：运行优化过程，用不同的参数值评估目标函数。
    
-   最优参数：返回在回测期间产生最高累积收益的ATR乘数和窗口。
    

```
def optimize_parameters(data, min_atr_multiplier, min_holding_period):
```

7.在训练集上优化参数

将历史数据划分为多个段，每一段都包含一个训练集和一个测试集。

```
optimized_params = optimize_parameters(
```

在训练集上优化策略以找到最佳参数，然后将这些参数应用于随后的测试集以评估性能。

-   参数优化：在每个训练期中，使用贝叶斯优化来找到最佳的ATR乘数和窗口。优化过程最大化策略的最终累积收益。
    
-   应用于测试期：将优化后的参数应用于随后的测试期以评估策略的表现。
    
-   评估与记录：记录每个测试期的策略表现，包括累积收益。
    
-   结果汇总：处理完所有段后，将结果汇总到一个DataFrame中。这个DataFrame包括每个测试期的最终收益和其他绩效指标。
    

  

为了比较，计算“买入并持有直到平仓”的收益：在收到买入信号后持有仓位直到产生卖出信号来计算收益。

```
# 确保交易信号符合最小持有期，以防止频繁交易。
```

8.结果统计函数

```
def plot_results(data, symbol):
```

9.准备数据及执行

①数据准备

```
symbol = 'ASML'  
```

②运行并输出结果`   `

```
if not data.empty:
```

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

10.简单示例

下面是一个不通过参数调优的例子，可以对着看效果。

```
import warnings
```

![](assets/004.png)