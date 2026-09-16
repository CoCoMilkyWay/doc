# QF-LIB：诞生于CERN的机构级量化框架

QuantML QuantML 2025-11-14 21:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492340&idx=1&sn=d5e960c17f7c705376794e8913b928cc&chksm=cff2e00c55ef800e152972d2241e3cbd7465347c6ea20d339edb9dd58bad326b7606dd38026f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492340&idx=1&sn=d5e960c17f7c705376794e8913b928cc&chksm=cff2e00c55ef800e152972d2241e3cbd7465347c6ea20d339edb9dd58bad326b7606dd38026f#rd)

开源量化生态在过去几年经历了巨变。曾经的行业标杆 **Quantopian / Zipline** 已经关闭，而另一位王者 **Backtrader** 也被其作者宣布“不再积极维护”。

这在“业余”工具（如backtesting.py）和“昂贵/闭源”工具（如QuantConnect的Lean）之间留下了一个**巨大的真空**：市场急需一个纯Python的、严谨的、事件驱动的、机构级的免费框架。

我们已经开源了**pyrust-bt**框架，作为一个rust+python混合框架，它结合了Rust与Python的优势。允许用户在Python中灵活编写策略，同时享受Rust带来的极致回测性能。近期，框架新增了对duckdb数据库和miniQMT行情数据源的支持，其生态正不断丰富。

今天我们介绍另外一个开源项目QF-LIB (QuarkFin Library) ，它是一个由 **quarkfin** 团队创建的模块化Python库。然而，使其与众不同的是其非凡的“血统”：它**诞生于CERN（欧洲核子研究中心）**，最初是为满足CERN养老基金的特定需求而开发的。

**文档**: https://qf-lib.readthedocs.io

**GitHub**: https://github.com/quarkfin/qf-lib

### **核心目标与定位**

QF-LIB的既定目标是为量化金融提供一套**高质量的工具**。其核心是一个**先进的、事件驱动（event-driven）的回测器**。该库明确支持多种资产类别，包括**加密货币、股票和期货**，使其成为一个功能全面的研究平台。

## **核心架构：为什么事件驱动 (Event-Driven) 是QF-LIB的灵魂**

在量化回测领域，框架主要分为两大流派：

1.  **向量化 (Vectorized)：** 速度极快。它利用Pandas和NumPy的数组操作，一次性对整个时间序列进行计算。但这种方法的致命弱点是难以处理复杂的、依赖路径的逻辑（例如，动态止损或组合再平衡），并且极易引入前视偏差 (Look\-ahead Bias)。
    
2.  **事件驱动 (Event-Driven)：** 速度较慢。它通过模拟真实世界的时间流（如“市场开盘”、“新K线到达”），一次一个时间步地推进策略状态。
    

QF-LIB的回测器采用了**事件驱动架构**。该架构的明确设计目标之一，就是提供**“防止回测环境中的前视偏差的工具”**。

事件驱动是实现“无前视”这一目标的系统性机制。QF-LIB的架构（特别是其DataHandler组件）扮演了“数据守门人”的角色。它强制模拟了时间的线性流动，确保在  时刻，策略_绝对_无法访问到  时刻的数据。

对于严肃的量化研究而言，这种架构牺牲了（简单策略的）回测速度，以换取**结果的正确性**。如果你正在测试一个依赖于复杂事件（如盘中重新平衡、动态杠杆或多资产依赖）的策略，事件驱动是唯一可信赖的选择。

![](assets/001.png)

## **框架介绍**

### **关键概念：解耦的框架**

深入研究QF-Lib的AlphaModelStrategy 的实现，可以发现一个强大的、符合机构级实践的设计模式：**信号、风控与执行的彻底解耦**。

1.  AlphaModel：**只负责生成信号**。它继承自基类，并实现calculate\_exposure()方法，返回Exposure.LONG、Exposure.SHORT或Exposure.OUT。它不关心（也不应该关心）将投入多少资金。
    
2.  PositionSizer：**只负责决定仓位大小**。它获取AlphaModel的信号，并根据自身的规则（例如“固定投资组合的20%” 或默认的“100%仓位”）将其转换为具体的订单。
    
3.  BacktestTradingSession：**只负责模拟环境**。它管理事件循环、数据流和订单执行。
    

这种设计是专业量化工作流的体现。它允许研究（Alpha）和风控（Sizer）完全分离。研究员可以专注于AlphaModel的研发，而风控经理可以使用同一个AlphaModel测试十几种不同的PositionSizer，而无需修改任何信号代码。

### **代码案例：定义AlphaModel**

策略的第一步是定义一个继承自AlphaModel的类，并实现calculate\_exposure()这个核心方法。

`Python      from qf_lib.backtesting.alpha_model.alpha_model import AlphaModel     from qf_lib.backtesting.alpha_model.exposure_enum import Exposure     from qf_lib.common.enums.price_field import PriceField     from qf_lib.common.tickers.tickers import Ticker     from qf_lib.data_providers.data_provider import DataProvider      # 1. 继承自 AlphaModel      class MovingAverageAlphaModel(AlphaModel):         def __init__(self, fast_time_period: int, slow_time_period: int,                       risk_estimation_factor: float, data_provider: DataProvider):             super().__init__(risk_estimation_factor, data_provider)             self.fast_time_period _ fast_time_period             self.slow_time_period = slow_time_period          # 2. 必须实现的核心方法          def calculate_exposure(self, ticker: Ticker, current_exposure: Exposure) \-\> Exposure:             # 3. 获取数据             num_of_bars_needed = self.slow_time_period             close_tms = self.data_provider.historical_price(                 ticker, PriceField.Close, num_of_bars_needed)                          # 4. 计算指标 (使用pandas内建函数)              fast_ma = close_tms.ewm(span=self.fast_time_period, adjust=False).mean()             slow_ma = close_tms.ewm(span=self.slow_time_period, adjust=False).mean()              # 5. 生成信号 (Exposure)              if fast_ma[-1] > slow_ma[-1]:                 return Exposure.LONG             else:                 return Exposure.SHORT   `

### **代码案例：配置回测会话与仓位控制器**

接下来，使用BacktestTradingSessionBuilder来配置和组装回测环境。这体现了“依赖注入”的设计思想，使得配置非常灵活。

`Python      from qf_lib.backtesting.trading_session.backtest_trading_session_builder import BacktestTradingSessionBuilder     from qf_lib.backtesting.strategies.alpha_model_strategy import AlphaModelStrategy     from qf_lib.backtesting.events.time_event import CalculateAndPlaceOrdersRegularEvent     # 引入一个非默认的PositionSizer      from qf_lib.backtesting.position_sizer.fixed_portfolio_percentage_sizer import FixedPortfolioPercentagePositionSizer      from qf_lib.common.enums.frequency import Frequency     from qf_lib.common.utils.dateutils.string_to_date import str_to_date     # 假设 settings, pdf_exporter, excel_exporter, daily_data_provider 已按文档配置好       def run_strategy():         start_date = str_to_date("2010-01-01")         end_date = str_to_date("2015-03-01")          # 1. 初始化构建器          session_builder = BacktestTradingSessionBuilder(             settings, pdf_exporter, excel_exporter)                  # 2. 配置会话 (频率, 数据源)          session_builder.set_frequency(Frequency.DAILY)         session_builder.set_data_provider(daily_data_provider)                  # 3. \[可选\] 配置仓位控制器          # 默认是 SimplePositionSizer (100% 仓位)          # 我们自定义为每次交易20%的仓位          session_builder.set_position_sizer(             FixedPortfolioPercentagePositionSizer, fixed_percentage=0.2)          # 4. 构建交易会话 (Session)          ts = session_builder.build(start_date, end_date)          # 5. 实例化我们的 Alpha Model, 注意传入的是 ts.data_handler          model = MovingAverageAlphaModel(             fast_time_period=5, slow_time_period=20,              risk_estimation_factor=1.25, data_provider=ts.data_handler)                  # 6. 定义要交易的资产         model_tickers = # (使用示例中的DummyTicker)          model_tickers_dict = {model: model_tickers}                  # 7. 实例化策略, 传入会话和模型          strategy = AlphaModelStrategy(ts, model_tickers_dict)                  # 8. 调度事件：何时计算信号和下单          # 设置在每日凌晨1点(默认)计算信号, 并排除周末          CalculateAndPlaceOrdersRegularEvent.set_daily_default_trigger_time()         CalculateAndPlaceOrdersRegularEvent.exclude_weekends()         strategy.subscribe(CalculateAndPlaceOrdersRegularEvent)                  # 9. 启动回测!           ts.start_trading()   `

### **关键组件速查表**

QF-LIB的核心回测组件可以总结如下：

_**表1：QF-LIB核心回测组件**_

组件

关键类

核心职责

**信号 (Alpha)**

AlphaModel

继承并实现 calculate\_exposure()，仅负责生成Exposure (LONG/SHORT/OUT) 信号。

**环境 (Session)**

BacktestTradingSession

模拟交易环境，管理事件队列 (EventManager)、数据 (DataHandler) 和时间。

**构建器 (Builder)**

BacktestTradingSessionBuilder

用于配置和组装交易会话的工厂类，负责注入所有依赖。

**仓位 (Sizing)**

PositionSizer

接收AlphaModel的信号，并决定具体的订单大小 (如 FixedPortfolioPercentagePositionSizer)。

**策略 (Strategy)**

AlphaModelStrategy

将AlphaModel、PositionSizer和TradingSession粘合在一起的“协调器”。

**调度 (Event)**

CalculateAndPlaceOrdersRegularEvent

定义_何时_触发AlphaModel的计算和下单逻辑 (例如，每日开盘前)。

## **QF-LIB生态系统：回测之外的功能矩阵**

QF-LIB的强大之处在于它远不止是一个回测器。它提供了一个从数据获取到投资组合构建，再到最终报告生成的完整生态。

### **数据层 (Data Layer)：灵活的数据供应与容器**

1.  **Data Providers** ：QF-LIB支持灵活的数据源选择。
    

-   **机构级数据**：**Bloomberg**, **Haver Analytics**, **Portara**。
    
-   **通用数据**：**Quandl**。
    
-   **交易平台/API**：通过extras\_require 和安装指南 发现，还支持 **Interactive Brokers**, **Alpaca** 和 **yfinance**。
    

3.  代码案例 ：简单的数据获取 (Quandl)：  
    使用特定提供者（如Quandl）需要额外安装。QF-LIB通过QuandlDataProvider 封装了API调用。
    

   `Python        # 首先，你需要安装Quandl的额外依赖         # pip install qf_lib[quandl]         from qf_lib.data_providers.quandl.quandl_data_provider import QuandlDataProvider        from qf_lib.common.tickers.quandl_ticker import QuandlTicker        # 假设 settings (包含 Quandl API key) 已配置         # 1. 实例化提供者        data_provider = QuandlDataProvider(settings)          # 2. 定义一个 Quandl 股票 (WIKI/PRICES 数据库)         ticker = QuandlTicker('AAPL', 'WIKI')          # 3. 获取历史数据        start_date = '2010-01-01'      end_date = '2015-01-01'      data = data_provider.get_history(ticker, 'Close', start_date, end_date)         print(data.head())`

3.  **扩展的数据容器**：QF-LIB不只是使用原生的Pandas。它提供了**适配的数据容器**，扩展了pandas.Series和pandas.DataFrames的功能。这些容器（如QFSeries和QFDataFrame）为金融时间序列提供了更友好的元数据处理和计算支持。
    

### **组合层 (Portfolio Layer)：专业的组合构建与优化**

AlphaModel 提供了单个资产的“买入”或“卖出”信号。但在机构实践中，当一个模型同时为50个资产生成（可能有冲突的）信号时，研究员就面临一个**投资组合优化问题**：如何分配资本以在控制风险的同时最大化预期收益？

portfolio\_construction (投资组合构建) 模块 正是AlphaModel逻辑的**必然延伸**。

-   该模块包含促进投资组合构建流程的组件。
    
-   核心功能涉及**协方差矩阵优化**。
    
-   RobustCovariance (稳健协方差)：该库专注于解决标准协方差矩阵（对异常值和非正态分布极其敏感）在现实世界中的应用问题。
    

### **分析层 (Analysis Layer)：风险、绩效与可视化**

QF-LIB提供多种分析工具。

1.  自动化的分析与报告：
    
    analysis模块 用于分析策略的整个生命周期，并能自动生成包含结果的摘要文件。这极大地简化了研究和报告流程。支持将结果导出为 PDF 和 Excel。  
    analysis模块的子模块（如ratios、returns和volatility）提供了计算关键绩效指标 (KPI) 的工具，包括：
    

-   夏普比率 (Sharpe Ratio)
    
-   欧米茄比率 (Omega Ratio)
    
-   回撤 (Drawdowns)
    
-   条件在险价值 (CVaR)
    

![](assets/002.png)

2.  可视化 (Plotting)：
    
    plotting模块 提供了一套丰富的图表模板。它采用了一种灵活的装饰器 (Decorators) 模式。用户首先创建一个基础图表（例如create\_line\_chart），然后通过添加DataElementDecorator或LegendDecorator 来丰富图表内容。
    

![](assets/003.png)

![](assets/004.png)

3.  代码案例：简单的绘图：  
    以下代码演示了plotting模块的装饰器模式。
    

   `import matplotlib.pyplot as plt        from qf_lib.plotting.charts.line_chart import LineChart        from qf_lib.plotting.decorators.series_line_decorator import SeriesLineDecorator        from qf_lib.plotting.decorators.legend_decorator import LegendDecorator        from qf_lib.common.utils.dateutils import DateFrequency        import pandas as pd        import numpy as np         # 假设这是你的策略收益率 (应为 QFSeries)        dates = pd.date_range(start='2010-01-01', periods=100, freq=DateFrequency.DAILY)        pnl_series = pd.Series(np.random.randn(100).cumsum(), index=dates)         # 1. 创建基础图表         chart = LineChart()         # 2. 使用装饰器添加数据 (SeriesLineDecorator)         data_decorator = SeriesLineDecorator(pnl_series, title="Strategy PnL")        chart.add_decorator(data_decorator)         # 3. 添加图例 (LegendDecorator)         chart.add_decorator(LegendDecorator())         # 4. 绘图 (plot() 方法只是绘制, 并不显示)         chart.plot()         # 5. 必须调用 plt.show() 来显示         plt.show(block=True)`

## **对比**

### **框架对比：选择你的武器**

_**表3：主流Python量化框架定位**_

框架

核心范式

维护状态

核心优势

最佳适用场景

**QF-LIB**

**事件驱动**

**积极**

**机构级**

；集成分析；投组构建；防前视

严肃的、多资产的、以风险管理为中心的量化研究。

**Backtrader**

事件驱动

**不再积极维护**

功能全面；文档详尽；曾是社区标准

维护遗留项目；学习事件驱动概念。

**Zipline**

事件驱动

**不再积极维护**

曾与PyFolio深度集成；Quantopian的遗产。

几乎没有新项目会选择。

**vectorbt**

**向量化**

积极

**极快的速度**

；擅长大规模参数扫描。

快速迭代和测试基于指标的、非路径依赖的策略。

**pyrust-bt**

事件驱动

积极

跨平台 (Rust/Python)；高效，上手简单。

团队快速实现回测框架

**Lean**

事件驱动

积极

跨平台 (C#/Python)；功能极其全面；支持多资产、多交易所。

接近真实交易的全面系统；但可能过于复杂。

###   

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/005.jpg)