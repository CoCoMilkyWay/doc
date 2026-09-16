# Time series forecasting

fintechhaibin FinTechHi 2025-01-17 23:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484688&idx=1&sn=5d554a119652c3a7904674fef67be217&chksm=fb1e146ee11eee667e75ca8ed18287671a83252bca8e673b78b4e375143fb37170dbeceda467#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484688&idx=1&sn=5d554a119652c3a7904674fef67be217&chksm=fb1e146ee11eee667e75ca8ed18287671a83252bca8e673b78b4e375143fb37170dbeceda467#rd)

1.Time series forecasting

时间序列预测是一种通过时间序列预测事件的技术。它通过分析过去数据的趋势来预测未来事件，前提是未来趋势将与历史趋势相似。许多预测问题涉及时间分量，因此需要时间序列数据的外推或时间序列预测。它广泛应用于许多领域，例如商业规划、模式识别、信号处理、天气预报、计量经济学、数理金融等。时间序列数据存在如下4个组成部分：

![](assets/001.png)

  

时间序列预测也是机器学习的一个重要领域，可以说是一个监督式学习问题。可以应用于 `Regression`、`Neural Networks`、`Random Forests` 和 `XGBoost` 等 ML 方法。

在处理时间序列数据时，我们需要了解一些特定的术语：

**①Autocorrelation:** 

describes the relationship among values of the same data series at different time periods. The formula could be written as:

![](assets/002.png)

自相关，描述的是同一个数据序列在不同时间段的值之间的关系。其中 _RK_ 是滞后 _K_ 的自相关。选择的滞后值将取决于单个值与其过去值的相关性。

![](assets/003.jpg)

如上图，第12个数据点和第36个数据点观测值是高度相关的。

**②Partial Autocorrelation:** 

a statistical measure that captures the correlation between two variables after controlling for the effects of other variables. For example, if we’re regressing a signal _St_ with the same signal at lags _t_−1,_t_−2,_t_−3 (_St_−1, _St_−2, _St_−3), the partial correlation between _St_ and _St_−3 is the amount of correlation between _St_ and _St_−3 that isn’t explained by their mutual correlations with _St_−1 and _St_−2.

**偏自相关：**一种统计度量，用于在控制其他变量的影响后统计两个变量之间的相关性。例如，如果我们在滞后 _t-1_、_t-2_、_t-3_（_St-1_、_St-2_、_St-3_）处回归具有相同信号的信号 _St_，则 _St_ 和 _St-3_ 之间的偏相关是 _St_ 和 _St-3_ 之间的相关性量，该相关性不能用它们与 _St-1_ 和 _St-2_ 的互相关性来解释。

**③Seasonality:** 

fluctuations in the pattern due to seasonal determinants over a period such as a day, week, month, or season. Can also be derived from an autocorrelation plot if it has a sinusoidal shape.

**季节性：**由于季节性决定因素在一天、一周、一个月或一个季节等时间段内导致的模式波动。如果自相关图具有正弦形状，也可以从自相关图中导出。

**④Trend:** 

increase or decrease in the series of data over a longer period.

**趋势：**数据序列在较长时间内的增加或减少。

**⑤Random or irregular variations:** 

instability due to random factors that do not repeat in the pattern.

**随机或不规则的变化：**由于模式中不重复的随机因素而导致的不稳定性。

**⑥Stationarity:** 

a time series is said to be stationary if its statistical properties don’t change over time. In other words, it has a constant mean and variance, and its covariance is independent of time. Dickey-Fuller method can be used to test stationarity.

**平稳性：**如果时间序列的统计属性不随时间变化，则称其为平稳。换句话说，它有一个常数均值和方差，并且它的协方差与时间无关。Dickey-Fuller 方法可用于测试平稳性。

2.Types of Time Series Models

有多种方法可以对时间序列进行建模以进行预测。最流行的方法包括：

-   Exponential Smoothing (ES)，指数平滑
    
-   Autoregressive(AR)，自回归
    
-   Moving Average(MA)，移动平均线
    
-   Autoregressive Moving Average (ARMA)，自回归移动平均线
    
-   Autoregressive Integrated Moving Average (ARIMA)，自回归积分移动平均线
    
-   Seasonal Autoregressive Integrated Moving Average (SARIMA)，季节性自回归积分移动平均线
    
-   Vector Autoregressive (VAR)，向量自回归
    
-   Vector Error Correction (VEC)，矢量误差校正
    
-   LSTM,XGBoost,N-Beats,Prophet,DeepAR,Temporal,Fusion,Transformer(Google), etc
    

  

# ①Exponential Smoothing Model

## \- Simple Exponential Smoothing (SES)

这种简单指数平滑方法适用于预测没有明确趋势或季节性的数据。Simple ES 的预测公式为：![](assets/004.png)  
其中 0≤_α_≤1 是平滑参数。ES 的含义是，时间 T+1 的提前一步预测是序列 _y_ _1，y_2,...,_yT_ 中所有观测值的加权平均值。权重降低的速率由参数 _α_ 控制。如果 _α_ 较小，则将更多权重用于更遥远的过去的观测。如果 _α_ 较大，则将为最近的观测值赋予更多权重。

## \- Weighted Average Form  
时间 _T_+1 的预测等于最近观测值 _yT_ 和前一次预测 _y_^_T_∣_T_−1 之间的加权平均值：![](assets/005.png)

其中 _l_0 是时间 1 处的第一个拟合值。

## \- Component Form  
指数平滑方法的分量形式表示包括方法中包含的每个分量的预测方程和平滑方程：

![](assets/006.png)

  
其中 _lt_ 是时间 _t_ 处的序列水平。预测方程显示，时间 _t_+1 的预测值是时间 _t_ 的估计水平。水平的平滑方程给出了序列在每个周期 _t_ 的估计水平。

## \- Flat Forecasts  
SES 具有 “flat” 预测功能：

![](assets/007.png)

  
也就是说，所有预测都采用相同的值，等于最后一个级别的分量（请记住，仅当时间序列没有趋势或季节性分量时，这些预测才适用）。

## \- Optimization  
任何指数平滑方法的参数 _α_ 和初始值 _l_0 都可以通过最小化 SSE 来估计：

![](assets/008.png)

# ②Autoregressive Model   
在自回归模型中，我们使用变量过去值的线性组合来预测感兴趣的变量。术语 `regression` 表示它是变量对自身的回归：

![](assets/009.png)

  
其中 _εt_ 是白噪声。这类似于多元回归，但使用 _yt_ 的滞后值作为预测因子。我们将其称为 _AR_（_p_） 模型，即 _p_ 阶的自回归模型。

![](assets/010.png)

  
上面的两个图显示了 _AR_ （1） 和 _AR_ （2） 模型的一系列。将参数更改为 1,...,_φp_ _φ_会导致不同的时间序列模式。误差项 _εt_ 的方差只会改变序列的尺度，而不会改变模式。  
对于 _AR_（1） 模型：

-   when _ϕ_1=0, _yt_ is equivalent to white noise;
    
-   when _ϕ_1=1 and _c_\=0, _yt_ is equivalent to random walk;
    
-   when _ϕ_1=1 and _c_\=0, _yt_ is equivalent to a random walk with drift;
    
-   when _ϕ_1<0, _yt_ tends to oscillate around the mean.
    

  
我们通常将自回归模型限制为平稳数据，在这种情况下，需要对参数的值进行一些约束：

-   For an _AR_(1) model: −1<_ϕ_1<1
    
-   For an _AR_(2) model: −1<_ϕ_2<1, _ϕ_1+_ϕ_2<1, _ϕ_2−_ϕ_1<1
    

  
注意：我们可以根据 **PACF** 图中的显着尖峰为 _AR_（_p_） 模型选择阶 _p_。

  

# ③Moving Average Model   
移动平均模型在类似回归的模型中使用过去的预测误差，而不是在回归中使用预测变量的过去值：

![](assets/011.png)

  
其中 _εt_ 是白噪声，呈正态分布，均值为 0，方差为 1。我们将其称为 _MA_（_q_） 模型，即阶数 _q_ 的移动平均模型。

![](assets/012.png)

  
上图显示了来自 _MA_（1） 模型和 _MA_（2） 模型的一些数据。更改参数 _θ_1,...,_θq_ 会导致不同的时间序列模式，误差项的方差只会改变序列的尺度，而不会改变模式。  
可以将任何稳态 _AR_（_p_） 模型编写为 _MA_（∞） 模型。例如，使用重复替换，我们可以为 _AR_（1） 模型演示这一点：

![](assets/013.png)

  
_φ_1_k_ 的值会随着 _k_ 的增大而变小。所以最终我们得到了一个 _MA_（∞） 过程。  
如果我们对 MA 参数施加一些约束，则相反的结果成立。那么 MA 模型称为`可逆`模型。也就是说，我们可以将任何可逆的 _MA_（_q_） 过程重写为 _AR_（∞） 过程。  
例如，_MA_（1） 过程 _yt_\=_εt_+_θ_1\*_εt_−1 可以改写为：

![](assets/014.png)

  
其中，当 ∣_θ_∣<1 时，过程是可逆的。  
其他模型的可逆性约束类似于平稳性约束：

-   For an _MA_(1) model: −1<_θ_1<1
    
-   For an _MA_(2) model: −1<_θ_2<1, _θ_1+_θ_2>−1, _θ_1−_θ_2<1
    

  
注意：我们可以根据 **ACF** 图中的显著尖峰为 _MA_（_q_） 模型选择阶_数 q_。

# ④Autoregressive Moving Average Model (ARMA)  
通过结合我们上面描述的两个模型，我们得到了所谓的自回归移动平均模型。_ARMA_（_p，q_） 模型可以表示为：

![](assets/015.png)

  
如果我们考虑 `Backward Shift 运算符`_L_，那么我们可以将上述内容重写为：

![](assets/016.png)

  
注： 为了确定 _ARMA_ 模型的哪个阶数 _p，q_ 适合于序列，我们需要在 _p，q_ 的值子集中使用 AIC 或 BIC，然后应用 `Ljung-Box` 检验来确定是否为特定的 _p，q_ 对实现了良好的拟合。

# ⑤Autoregressive Integrated Moving Average Model (Non-seasonal ARIMA)  
ARIMA 模型是 _ARMA_ 和差分的组合：

![](assets/017.png)

  
其中 _yt_′ 是差值序列。我们称之为 _ARIMA_（_p，d，q_） 模型，其中

-   p — order of the autoregressive part
    
-   q — order of the moving average part
    
-   d — degree of differencing involved
    

# ⑥Seasonal Autoregressive Integrated Moving Average (SARIMA)  
季节性 ARIMA 考虑了季节性因素。它写成如下：

![](assets/018.png)

  
其中，第一部分是非季节性部分，第二部分是季节性部分。_m_ 是每年的观测值数。  
例如，没有常量的 _ARIMA_（1,1,1）（1,1,1）\_4 模型可以写成：

![](assets/019.png)

  
其中，附加季节性项只是乘以非季节性项。

# ⑦Vector Autoregressive Model (VAR)  
VAR 用于`多变量`时间序列。结构是每个变量都是自身过去滞后和其他变量过去滞后的线性函数。例如，假设我们测量三个不同的时间序列变量，用 xt，1，xt，2，xt，3 表示。1 阶的 VAR 模型如下：

![](assets/020.png)

  
每个变量都是集合中所有变量的滞后 1 值的线性函数。VAR 的一般形式可以写成：

![](assets/021.png)

  
其中 _Ai_ 是 i =1,2 的 （K x K） 系数矩阵,...p 和 _ut_ 是具有时间不变的正定协方差矩阵的 K 维白噪声过程。矩阵 C 是具有维度 （K x M） 的潜在确定性回归变量的系数矩阵，_Dt_ 是一个 （M x 1） 列向量，其中包含适当的确定性回归变量，例如常数、趋势和虚拟变量，和/或季节性虚拟变量。

# 3.Some Assumptions for Time Series Models

#   

![](assets/022.png)

![](assets/023.png)

4.滞后特征

假设需要预测一家公司的股价。那么，昨收价对于预测很重要，对吧？换句话说，时间_t_的值受到时间_t-1 的_值的很大影响。过去的值称为滞后，因此_t-1_是滞后1，_t-2_是滞后2，依此类推。

```
import pandas as pd
```

![](assets/024.png)

为什么要滞后一呢？选择的滞后值将取决于单个值与其过去值的相关性。如果该系列数据具有每周趋势，这意味着可以使用上周一的值来预测本周一的值，则应创建七天的滞后特征。 

也可以创建多个滞后特征，假设我们想要滞后1到滞后7，我们可以让模型决定哪一个是最有价值的。因此，如果我们训练一个线性回归模型，它将为滞后特征分配适当的权重（或系数）：

  

```
import pandas as pd
```

![](assets/025.png)

可以使用上文中ACF（自相关函数）和 PACF（偏自相关函数）进行分析：

```
from statsmodels.graphics.tsaplots import plot_acf
```

![](assets/026.png)

如图，偏自相关函数与第一滞后值具有较高的相关性，与第二滞后值和第三滞后值具有较低的相关性。自相关函数衰减缓慢，这意味着未来值与过去值具有非常高的相关性。需要注意的一点是，移动的次数越多，数据中值的数量就越少。在开始时看到一些带有 NaN 的行。这是因为第一次观察没有滞后。您需要从训练数据中丢弃这些行。

5.滑动窗口

比如最简单的：选择一个窗口大小，取窗口中值的平均值：

```
import pandas as pd
```

![](assets/027.png)

类似地，可以将总和、最小值、最大值等（针对选定的窗口）视为一个特征。此方法可以平滑数据并降低噪音。

新近度是时间序列中的一个重要因素。越接近当前日期的值包含的信息越多。因此，我们可以使用加权平均值，这样最近的观测值就会被赋予更高的权重。

在滚动窗口的情况下，窗口的大小是恒定的，而窗口会随着时间的流逝而滑动。因此，我们只考虑最近的值，而忽略过去的值。扩展窗口每一步，窗口的大小都会增加一，因为它会考虑系列中的每个新值。

```
import pandas as pd
```

![](assets/028.png)

对于传统的机器学习问题，我们随机选择数据子集作为验证集和测试集。但在时序数据下下，每个数据点都依赖于其过去的值。如果我们随机打乱数据，我们可能会对未来数据进行训练并预测过去的值。在处理时间序列问题时，重要的是我们要小心地构建验证集，而不要破坏数据内的顺序。

6.数据示例

假设有如下数据：

![](assets/029.png)

```
# print the metadata of the dataset
```

![](assets/030.png)

![](assets/031.png)

可视化下数据：

```
df['Open'].plot(figsize=(12,6),c='g')
```

![](assets/032.png)

Pandas 提供了丰富的工具来处理日期、时间和时间索引数据。

```
df.shift(1)
```

在时间序列分析中也称为滞后或移位，是指将时间序列的值向前或向后移动的过程。它涉及将整个序列移动特定数量的周期。1前移，-1后移。

比如如下图原始数据：

![](assets/033.png)

前移：

![](assets/034.png)

后移：

![](assets/035.png)