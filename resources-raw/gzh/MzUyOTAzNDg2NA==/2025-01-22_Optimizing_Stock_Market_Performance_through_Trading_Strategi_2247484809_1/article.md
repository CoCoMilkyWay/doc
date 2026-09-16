# Optimizing Stock Market Performance through Trading Strategies

fintechhaibin FinTechHi 2025-01-22 21:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484809&idx=1&sn=ad1bdc9d0d93ae5e740978d3a424aa96&chksm=fb2182dc1328c69485a4e2c1ecedfee4e139fad5b9a3d675e1af307a895047f69666c2049881#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484809&idx=1&sn=ad1bdc9d0d93ae5e740978d3a424aa96&chksm=fb2182dc1328c69485a4e2c1ecedfee4e139fad5b9a3d675e1af307a895047f69666c2049881#rd)

继续以学习的角度了解模型相关的知识点。

1.选择两个指标

Recursive Moving Average (RMA) and Ease of Movement (EMV).

-   Recursive Moving Average (RMA) is a type of moving average that uses a recursive formula to calculate smoothed values for a time series. 
    
-   Exponential Moving Average (EMA) due to its similarity in applying weighting that decreases exponentially for past data points.
    
      
    
      
    

a) Recursive Moving Average (RMA)

## 递归移动平均线 (RMA) 是一种平滑技术，用于时间序列数据的分析。它通过递归计算来平滑数据，常用于金融领域的技术分析。RMA 也被称为指数移动平均线 (EMA) 的一种变体。

```
import pandas as pd
```

`alpha`（平滑系数）在递归移动平均线（RMA）或指数加权移动平均线（EWMA）中是一个非常重要的参数，它决定了当前价格和历史价格对最终结果的权重分配。

取值范围：

。

它决定了当前价格数据在计算 RMA 时的权重，以及历史数据的权重，其中计算公式为：

其中，`period` 是平滑周期。

**权重分配**：

-   当前价格的权重是 `alpha`。
    
-   历史价格的权重是
    

-   这意味着：
    

-   当 `alpha` 较大时（接近 1），当前价格对 RMA 的影响更大，RMA 对价格变化的反应更敏感。
    
-   当 `alpha` 较小时（接近 0），历史价格对 RMA 的影响更大，RMA 对价格变化的反应更平滑。
    

  

递归性质：

-   RMA 的计算是递归的，当前时刻的 RMA 值依赖于上一时刻的 RMA 值。
    
-   公式为：
    

其中：

：当前t时刻的RMA值

：当前t时刻的价格

:上一时刻RMA值

（ps:以下来自deepseek）

  

### **`alpha` 的作用**

1.  **控制平滑程度**：
    

-   `alpha` 越小，RMA 对历史数据的依赖越大，结果越平滑，但对当前价格变化的反应越迟钝。
    
-   `alpha` 越大，RMA 对当前价格变化的反应越敏感，但平滑效果越差。
    

3.  **调整周期**：
    

-   `alpha` 与周期 `period` 成反比。（按上述公式）
    
-   周期越长，`alpha` 越小，RMA 越平滑；
    
-   周期越短，`alpha` 越大，RMA 越敏感。
    

5.  **适应不同场景**：
    

-   在趋势跟踪中，可以使用较小的 `alpha`（较长周期）来过滤噪声，捕捉长期趋势。
    
-   在短期交易中，可以使用较大的 `alpha`（较短周期）来快速反应价格变化。
    

* * *

### **`   `**

### **`alpha` 的直观理解**

-   **`alpha = 0.5`**：
    

-   当前价格的权重是 50%，历史价格的权重也是 50%。
    
-   RMA 对当前价格和历史价格同等重视。
    

-   **`alpha = 0.1`**：
    

-   当前价格的权重是 10%，历史价格的权重是 90%。
    
-   RMA 更注重历史数据，结果更平滑。
    

-   **`alpha = 0.9`**：  
    

-   当前价格的权重是 90%，历史价格的权重是 10%。
    
-   RMA 对当前价格变化非常敏感，但平滑效果较差。
    

`alpha` 是递归移动平均线（RMA）或指数加权移动平均线（EWMA）中的核心参数，它决定了当前价格和历史价格的权重分配。通过调整 `alpha`，可以控制 RMA 的平滑程度和对价格变化的敏感度，从而适应不同的分析需求。

##   

## b) Ease of Movement (EMV)  
  

变动轻松度（EMV）是金融市场中用于衡量价格变动与交易量之间关系的技术指标。它可以帮助交易者评估移动价格需要多少努力（交易量），这可以表明价格趋势的强度：

```
import pandas as pd
```

其中：

-   Distance: Measures how much the midpoint of the high/low priceschanges compared to the previous day.
    
-   Box Ratio:: Normalizes price changes by volume and range.
    
-   The rolling average of this ratio provides the EMV, which indicates price movement ease.
    

  

使用示例：

```
# Assuming df is a DataFrame with columns 'High', 'Low', 'Volume'
```

将 RMA 应用到 EMV 指标上，以平滑 EMV 值并更好地观察其趋势：

```
# 假设 df 是包含价格和成交量数据的 DataFrame
```

数据示例结果如下图：

![](assets/001.png)

  

2\. Data Preparation

```
# Define the stock symbol and time period
```

# 3\. Monte Carlo Simulations

#   

```
# 蒙特卡洛模拟：测试不同的 alpha 和 period 参数范围
```

  
  
上面主要是：探索交易策略在各种参数（ `alpha`和`period` ）下的表现并评估其稳健性。

### **为什么需要探索不同参数？交易策略通常依赖于一些关键参数（如** `alpha` 和 `period`），这些参数直接影响策略的表现。例如：

###   

-   **`alpha`**：在递归移动平均线（RMA）中，`alpha` 决定了当前价格和历史价格的权重分配，影响指标的平滑程度和对价格变化的敏感度。
    
-   **`period`**：在 Ease of Movement (EMV) 中，`period` 决定了计算 EMV 的时间窗口大小，影响指标的滞后性和对市场趋势的反应速度。
    

  

不同的参数组合可能会导致策略表现差异巨大。因此，需要通过探索不同的参数组合来：

-   找到最优的参数组合，使策略在历史数据上表现最佳。
    
-   理解参数对策略表现的影响，避免过拟合（即在历史数据上表现很好，但在未来数据上失效）。
    

### 

**需要考虑稳健性，**指的是策略在不同市场环境、不同参数设置下的稳定表现能力。一个稳健的策略应具备以下特点：

-   **对参数不敏感**：策略在参数小幅变化时，表现不会剧烈波动。
    
-   **适应性强**：策略在不同市场（如牛市、熊市、震荡市）中都能保持较好的表现。
    
-   **抗过拟合**：策略不仅在历史数据上表现良好，在未来数据上也能保持稳定的收益。
    

### 

### **上述代码中，使用****蒙特卡洛模拟**来探索不同参数组合下的策略表现。

### 具体步骤如下：

#### **(1) 随机生成参数组合**

-   从给定的 `alpha_range` 和 `period_range` 中随机生成 `alpha` 和 `period`。
    
-   例如：
    

-   `alpha` 在 `[0.01, 0.5]` 之间随机取值。
    
-   `period` 在 `[1, 51]` 之间随机取值。
    

#### **(2) 计算指标并生成交易信号**

-   使用随机生成的 `alpha` 计算 RMA。
    
-   使用随机生成的 `period` 计算 EMV。
    
-   根据 RMA 和 EMV 生成交易信号（买入和卖出）。
    

#### **(3) 回测并记录结果**

-   使用 `vectorbt` 进行回测，计算投资组合的价值和最大回撤。
    
-   将每次模拟的结果（投资组合价值和最大回撤）记录下来。
    

#### **(4) 分析结果**

-   通过分析所有模拟结果，评估策略在不同参数组合下的表现。
    
-   例如：
    

-   计算策略的平均收益率、最大回撤、胜率等指标。
    
-   绘制参数与策略表现的关系图，观察参数对策略的影响。
    

* * *

### 

蒙特卡洛模拟通过随机生成大量参数组合，能够全面覆盖参数空间，从而：

-   **避免过拟合**：通过测试大量随机参数组合，避免策略在特定参数下过拟合历史数据。
    
-   **评估参数敏感性**：通过观察策略在不同参数下的表现，判断策略是否对参数敏感。
    
-   **模拟不确定性**：蒙特卡洛模拟可以模拟市场的不确定性，评估策略在极端情况下的表现。
    

* * *

### 

在实际交易中，市场环境是不断变化的，参数的最优值可能会随时间变化。通过探索不同参数组合并评估策略的稳健性，可以：

-   找到一组相对稳定的参数，使策略在大多数市场环境下都能表现良好。
    
-   避免策略在特定参数下失效，降低交易风险。
    
-   提高策略的适应性和可靠性，增强交易信心。
    

### 

### **示例分析**

假设我们运行 1000 次蒙特卡洛模拟，得到以下结果：

-   **平均收益率**：10%
    
-   **最大回撤**：-15%
    
-   **胜率**：60%
    

  

通过分析不同参数组合的表现，我们发现：

-   当 `alpha` 在 `[0.1, 0.3]` 之间且 `period` 在 `[10, 20]` 之间时，策略表现最佳。
    
-   策略对 `alpha` 的敏感性较高，但对 `period` 的敏感性较低。
    

  

这些结论可以帮助我们：

-   选择一组稳健的参数（如 `alpha=0.2`, `period=14`）。
    
-   避免使用过于极端的参数（如 `alpha=0.01` 或 `period=50`），因为这些参数可能导致策略失效。
    

  

**4\. Metrics**:  

-   Calculate portfolio value as a percentage of the initial value.  
      
    
-   Track drawdowns (the percentage drop from the highest portfolio value).  
      
    

#   

# 5\. Buy-and-Hold Strategy 

```
# 计算买入持有策略（Buy and Hold）
```

buy\_and\_hold：是一个 Series，表示买入持有策略的收益率随时间的变化。示例如下：

  

![](assets/002.png)

6\. Visualization  

## a) Monte Carlo Simulations  
我首先通过蒙特卡罗模拟来检验系统的潜力，看看它是否能够盈利并跑赢市场。蒙特卡罗模拟的目的是模拟极端市场条件下的交易，看看我们的交易系统是否能够生存。

```
# 绘制所有模拟的投资组合价值（百分比变化）
```

![](assets/003.png)

## b) Histograms 

```
# 绘制最终投资组合价值的直方图（百分比变化）
```

## Histogram of Final Portfolio Values:

##   

![](assets/004.png)

Drawdown：

![](assets/005.png)

  
  
查看 2015 年至 2020 年所有模拟与买入并持有相比的图表，对于该系统，无论参数如何，它在所有情况下都表现不佳。然而，让该系统跑赢市场的是 COVID-19 危机，在此期间，该系统能够将所有参数的损失降至最低。这使得我们的交易系统的平均表现从长远来看超过了市场。

# 7\. Statistics 

```
# 计算并显示最终投资组合价值的统计信息（百分比变化）
```

-   Mean Final Portfolio Value (%): 144.90  
      
    
-   Standard Deviation (%): 53.39  
      
    

```
# 计算并显示最大回撤的统计信息
```

  

-   Mean and standard deviation describe the average and variability of the strategy’s worst-case losses.  
    
-   Mean Drawdown (%): -60.88  
    
-   Drawdown Standard Deviation (%): 7.30  
      
    

  
此外，如果我们将交易系统与买入并持有进行比较，我们可以看到平均最终投资组合价值（%）为144.90，而买入并持有的利润仅为46%。因此，该系统值得进一步研究。

# 8.Backtesting Function 

  

```
# 定义函数：使用优化参数进行回测
```

**返回投资组合的总收益率（Total Return \[%\]**），用于优化最大收益。

  

# 9.Grid Search

The grid search evaluates multiple combinations of `alpha` and `period`:  

```
# 定义要测试的参数网格
```

###   

1.  **定义参数网格**：
    

-   **`alpha`**：使用 `np.linspace(0.01, 0.5)` 生成从 0.01 到 0.5 的等间隔值。
    
-   **`period`**：使用 `np.arange(1, 51)` 生成从 1 到 50 的整数。
    

3.  **创建参数组合**：
    

-   使用 `ParameterGrid` 将 `param_grid` 转换为所有可能的参数组合。
    

* * *

### **参数网格的作用：**

-   **`alpha`**：递归移动平均线（RMA）的平滑系数，范围从 0.01 到 0.5。
    
-   **`period`**：Ease of Movement (EMV) 的计算周期，范围从 1 到 50。
    

* * *

### **应用场景：**

此代码用于生成所有可能的参数组合，以便进行网格搜索（Grid Search），从而找到最优的参数组合。

### **示例输出：**

假设 `param_grid` 如下：

```
param_grid = {
```

则 `ParameterGrid(param_grid)` 将生成以下参数组合：

```
[
```

对于每个参数组合：

```
# 存储优化结果
```

### 

1.  **初始化结果列表**：
    

-   使用 `results = []` 初始化一个空列表，用于存储每组参数的回测结果。
    

3.  **遍历参数网格**：
    

-   使用 `for params in grid` 遍历所有参数组合。
    
-   每组参数组合是一个字典，包含 `alpha` 和 `period`。
    

5.  **获取参数值**：
    

-   从 `params` 中提取 `alpha` 和 `period`。
    

7.  **回测**：
    

-   调用 `backtest_with_parameters(alpha, period)` 进行回测，返回总收益率 `total_return`。
    

9.  **存储结果**：
    

-   将 `alpha`、`period` 和 `total_return` 作为一个元组存储到 `results` 列表中。
    

### **输出示例：**

假设 `grid` 包含以下参数组合：

```
[
```

则 `results` 可能如下：

```
[
```

通过上述代码，找到总收益率最高的参数组合，绘制参数与收益的关系图，根据最优参数组合调整策略，进一步测试策略的稳健性。

  

# 10.Analyzing Results

The results are converted to a DataFrame and analyzed:  

```
# 将结果转换为 DataFrame，便于分析
```

### 

1.  **将结果转换为 DataFrame**：
    

-   使用 `pd.DataFrame` 将 `results` 列表转换为 DataFrame。
    
-   列名分别为 `Alpha`、`Period` 和 `Total Return [%]`。
    

3.  **找到最优参数**：
    

-   使用 `results_df['Total Return [%]'].idxmax()` 找到总收益率最高的行的索引。
    
-   使用 `results_df.loc[]` 提取该行的数据，即最优参数组合。
    

假设 `results_df` 如下

![](assets/006.png)

则 `best_params` 的输出为：

```
Alpha                0.02
```

### **应用场景：**

1.  **数据分析**：
    

-   将结果转换为 DataFrame 后，可以方便地进行排序、过滤和可视化分析。
    

3.  **参数优化**：
    

-   找到总收益率最高的参数组合，用于优化策略。
    

* * *

### **后续步骤：**

1.  **分析结果**：
    

-   使用 `results_df` 绘制参数与收益的关系图。
    
-   分析参数对策略表现的影响。
    

3.  **优化策略**：
    

-   根据 `best_params` 调整策略参数。
    
-   进一步测试策略的稳健性。
    

  

# 11.Outputs

```
# 打印最优参数和总收益率
```

**Best Parameters**:  

```
Best Alpha: 0.31
```

12.Backtesting with the Best Parameters  

## 1）Calculate RMA and EMV

##   

```
# 计算递归移动平均线 (RMA) 和 Ease of Movement (EMV)
```

##   

**RMA**:  

-   Recursive Moving Average of the stock’s `Close` price is calculated using an `alpha` value of `0.31`.  
      
    
-   Gives more weight to recent prices, creating a smooth trend line  
      
    

**EMV**:  

-   Ease of Movement is calculated over a `31-day` rolling window.  
      
    
-   Measures how easily the price moves up or down relative to volume and price range.  
      
    

## 2）Define Entry and Exit Signals  
  
我们需要再次定义进入和退出信号，因为它们位于`backtest_with_parameters`函数之外。

```
# 定义基于 RMA 和 EMV 的交易信号
```

**Entry Signal**:  

-   The stock’s closing price (`Close`) is greater than the RMA.  
      
    
-   EMV is positive (indicating upward price momentum with ease).  
      
    

**Exit Signal**:  

-   The stock’s closing price falls below the RMA.  
    
-   EMV is negative (indicating downward price momentum with ease).
    

  

## 3）Filter Data for the Testing Period

```
# 过滤数据，仅保留测试时间段（2015 年至 2025 年）
```

##   

## 4）Convert Signals to Boolean Arrays

##   

```
# 将交易信号转换为布尔数组
```

![](assets/007.png)

##   

## 5）Backtest Using vectorbt

##   

```
# 使用 vectorbt 进行回测
```

## Creates a **portfolio simulation** based on the entry and exit signals:  
  

-   `close: Stock's closing prices.   `
-   `entries: Buy signals.   `
-   `exits: Sell signals.   `
-   `init_cash: Starting capital of $100,000.   `
-   `fees: A transaction fee of 0.1% is applied to each trade.   `

##   

## 6）Display Performance Metrics  
  

```
# Display performance metricsprint(portfolio.stats())
```

##   

## 7）Key performance metrics of the backtest:  
  

-   **Total Return**
    
    : Overall return percentage.  
    
-   **Max Drawdown**
    
    : Maximum loss from the peak value.  
    

![](assets/008.png)

##   

## 8\. Plot the Equity Curve  
  

```
# Plot equity curveportfolio.plot().show()
```

**Equity Curve**: A visual representation of the portfolio’s value over time.  

-   The x-axis represents time.  
    
-   The y-axis represents portfolio value.  
    

It helps visualize performance trends, drawdowns, and gains during the backtest period.  

![](assets/009.png)

The results from backtesting with the best parameters lead to a similar conclusion: Before the COVID-19 crisis, the trading system (green area line) significantly underperformed the market (gray line).  
  

However, after the crisis, the trading system was able to outperform the market, with a return of 300.74% and a maximum drawdown of 52.6%, compared to the buy and hold strategy which yielded a return of 46.36% over the 10-year period. This makes it another viable option for diversifying investment risk this year.  
  

However, this is just a backtest using historical data, and as we know, the market is constantly changing. The best parameters for the past may not necessarily work the same way in the future. Therefore, we must continuously adjust the parameters.