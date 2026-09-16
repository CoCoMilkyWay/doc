# Skfolio：最新机器学习组合优化工具

QuantML QuantML 2024-11-09 19:44 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487574&idx=1&sn=8a881b231f0d74bf155e0def21a5c91b&chksm=cff5a7d14131671f14a7577c0f5cfa9d4366220e5b89aa5ce5c13859b146e1866b98336a1be5#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487574&idx=1&sn=8a881b231f0d74bf155e0def21a5c91b&chksm=cff5a7d14131671f14a7577c0f5cfa9d4366220e5b89aa5ce5c13859b146e1866b98336a1be5#rd)

#### 

skfolio是Python中的最新投资组合优化库， 用来构建和优化投资组合。skfolio是基于scikit-learn构建的库，旨在简化投资组合优化流程，并提供与scikit-learn兼容的接口和功能。![](assets/001.jpg)

### 文章背景

近年来，定量金融方法不断发展，将这些方法整合到一个统一的框架中变得尤为重要，尤其是在与机器学习模型无缝集成的情况下。skfolio应运而生，它专注于投资组合优化，并利用scikit-learn的优势，提供了高效的数据处理、模型选择、验证和超参数调优功能，同时降低了数据泄漏和过拟合的风险。

自2024年初发布以来，skfolio在GitHub上的关注度稳步上升，这表明其在量化金融领域的应用潜力。

![](assets/002.png)

### 1\. 环境配置与数据准备

在开始投资组合优化之前，需要导入必要的库：

-   `requests`：用于下载数据
    
-   `pandas`：用于数据处理
    
-   `numpy`：用于数值计算
    
-   `skfolio`：用于投资组合优化
    
-   `matplotlib`和`plotly`：用于数据可视化
    

```
import requestsimport pandas as pdimport numpy as npfrom skfolio import PerfMeasure, RatioMeasure, RiskMeasure, Populationfrom skfolio.optimization import MeanRisk, ObjectiveFunctionfrom plotly.io import showimport seaborn as snsimport matplotlib.pyplot as plt
```

设置绘图风格和图形大小：

```
plt.style.use("seborm-v0.8-colorblind")plt.rcParams["figure.figsize"] = (16, 8)
```

为了获取历史股票价格数据，使用Financial Modelling Prep的API，并下载FAANG公司（META、AAPL、AMZN、NFLX、GOOGL）的调整后收盘价数据，时间范围为2023年8月1日至今。

```
FAANG_TICKERS = ["META", "AAPL", "AMZN", "NFLX", "GOOGL"]START_DATE = "2023-08-01"def get_adj_close_price(symbol, start_date):    hist_price_url = f"https://financialmodelingprep.com/api/v3/historical-price-full/{symbol}?from={start_date}&apikey={FMP_API_KEY}"    r_json = requests.get(hist_price_url).json()    df = pd.DataFrame(r_json["historical"]).set_index("date").sort_index()    df.index = pd.to_datetime(df.index)    return df[["adjClose"]].rename(columns={"adjClose": symbol})price_df_list = [get_adj_close_price(ticker, START_DATE) for ticker in FAANG_TICKERS]prices_df = pd.concat(price_df_list, axis=1)
```

生成的DataFrame如下：

date

META

AAPL

AMZN

NFLX

GOOGL

2023-08-01

322.05

194.35

191.34

131.69

438.62

2023-08-02

313.67

128.21

429.70

128.23

128.30

...

...

...

...

...

...

2024-08-16

527.42

226.05

170.23

177.59

674.07

绘制下载的时间序列数据：

![](assets/003.png)

为了进行投资组合优化，需要计算股票收益率：

```
returns_df = prices_to_returns(prices_df)
```

计算累计收益率并绘制：

```
cumulative_returns_df = (1 + returns_df).cumprod() - 1cumulative_returns_df.plot(title="Cumulative Returns")
```

![](assets/004.png)

从图中可以看出，在所考虑的时期内，META的累计收益率最高，超过了60%，其次是Netflix。

### 2\. 投资组合优化

#### 2.1 单个投资组合的构建

使用skfolio构建三种类型的投资组合：

-   最小化波动率
    
-   最大化收益率
    
-   最大化夏普比率
    

**最小化波动率的投资组合**

```
model = MeanRisk(    objective_function=ObjectiveFunction.MINIMIZE_RISK,    risk_measure=RiskMeasure.VARIANCE,    portfolio_params=dict(name="Min Variance"))model.fit(returns_df)min_variance_pred = model.predict(returns_df)
```

-   `MeanRisk`类用于均值-方差优化
    
-   `objective_function`参数设置为`MINIMIZE_RISK`，表示最小化风险
    
-   `risk_measure`参数设置为`VARIANCE`，表示使用方差作为风险度量
    
-   `portfolio_params`参数用于设置投资组合的名称
    

使用scikit-learn的API将模型拟合到收益率数据，并进行预测。预测结果是一个`Portfolio`类的对象，包含了许多用于分析投资组合性能的实用工具。

查看投资组合权重：

```
model.weights# array([0.02359533, 0.49553118, 0.16225161, 0.14974249, 0.16887939])
```

**最大化收益率的投资组合**

```
model = MeanRisk(    objective_function=ObjectiveFunction.MAXIMIZE_RETURN,    portfolio_params=dict(name="Max Return"))model.fit(returns_df)max_return_pred = model.predict(returns_df)
```

**最大化夏普比率的投资组合**

```
model = MeanRisk(    objective_function=ObjectiveFunction.MAXIMIZE_RATIO,    risk_measure=RiskMeasure.VARIANCE,    portfolio_params=dict(name="Max Sharpe"))model.fit(returns_df)max_sharpe_pred = model.predict(returns_df)
```

**投资组合比较与分析**

使用`Population`类可以方便地比较多个投资组合：

```
population = Population([min_variance_pred, max_return_pred, max_sharpe_pred])population.plot_composition()
```

![](assets/005.png)

从图中可以看出，不同优化目标下的投资组合构成差异显著。例如，在最大化收益率的投资组合中，所有权重都分配给了META，这与累计收益率图中META的表现一致。

绘制投资组合的累计收益率：

```
population.plot_cumulative_returns()
```

![](assets/006.png)

最后，使用`summary`方法查看投资组合的详细性能指标：

```
population.summary()
```

指标

Min Variance

Max Return

Max Sharpe

Mean

0.10%

0.21%

0.19%

Annualized Mean

26.13%

53.88%

46.67%

Variance

0.015%

0.054%

0.022%

...

...

...

...

Sharpe Ratio

0.084

1.341

1.79

...

...

...

...

`Population`类提供了近50个不同的指标来评估投资组合的性能。

#### 2.2 投资组合优化参数调整

`MeanRisk`类提供了许多参数，可以根据需要进行调整：

-   设置交易成本、无风险利率、管理费、预算
    
-   修改风险厌恶系数
    
-   控制最小和最大权重，例如允许做空
    
-   设置预期权重的自定义约束
    
-   在均值-方差优化中添加L2正则化，以减少微不足道的权重为零
    
-   为某些指标设置目标或阈值，例如最低收益率或最高波动率
    

### 3\. 有效前沿的识别

有效前沿代表了在给定风险水平下提供最高预期收益率或给定收益率水平下提供最低风险的投资组合集合。

使用默认参数进行均值-方差优化，并指定要找到的投资组合数量：

```
model = MeanRisk(efficient_frontier_size=50)model.fit(returns_df)efficient_frontier = model.predict(returns_df)
```

绘制有效前沿：

```
fig = efficient_frontier.plot_measures(    x=RiskMeasure.ANNUALIZED_VARIANCE,    y=PerfMeasure.ANNUALIZED_MEAN,    color_scale=RatioMeasure.ANNUALIZED_SHARPE_RATIO,    hover_measures=[        RiskMeasure.MAX_DRAWDOWN,        RatioMeasure.ANNUALIZED_SORTINO_RATIO,        RiskMeasure.WORST_REALIZATION    ])show(fig)
```

![](assets/007.png)

查看有效前沿上投资组合的构成：

```
efficient_frontier.plot_composition()
```

![](assets/008.png)

使用`summary`方法查看有效前沿上投资组合的性能指标：

```
efficient_frontier.summary()
```

为了便于分析，可以提取特定指标，例如年化夏普比率：

```
efficient_frontier(measure=RatioMeasure.ANNUALIZED_SHARPE_RATIO)
```

### 4\. 总结与展望

本文介绍了如何使用skfolio进行投资组合优化：

-   使用均值-方差优化构建了三种类型的投资组合：最小化波动率、最大化收益率和最大化夏普比率。
    
-   使用`Population`类比较了不同投资组合的构成和性能。
    
-   识别了有效前沿，并分析了其构成和性能。
    

### 5\. 结论

skfolio是一个功能强大且易于使用的投资组合优化库，提供了丰富的功能和灵活的接口，可以满足不同投资者的需求。

通过本文的介绍，相信读者已经对如何使用skfolio进行投资组合优化有了更深入的了解。以下是一些建议：

-   **从简单的均值-方差优化开始**，熟悉skfolio的基本用法。
    
-   **尝试不同的估计方法和交叉验证方法**，以提高投资组合模型的稳健性。
    
-   **探索更高级的功能**，例如层次风险平价、投资组合约束和高级优化算法。
    
-   **结合机器学习模型**，构建更智能的投资组合优化策略。
    

skfolio仍在不断发展和完善中，未来将支持更多功能和算法。期待skfolio在量化金融领域发挥更大的作用，帮助投资者构建更有效的投资组合，实现更高的投资回报。

  

  

QuantML星球内有各类丰富的量化资源，包括数百篇论文代码，QuantML-Qlib框架，研报复现，研报分享项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，券商研究员，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

QuantML知识星球双十一优惠活动正式开启，名额有限，欢迎加入

  

![](assets/009.png)