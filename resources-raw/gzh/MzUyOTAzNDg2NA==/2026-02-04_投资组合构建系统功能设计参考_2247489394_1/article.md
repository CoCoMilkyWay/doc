# 投资组合构建系统功能设计参考

fintechhaibin FinTechHi 2026-02-04 22:53 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489394&idx=1&sn=5452cd7e82504675d2da2ca3c2614c5a&chksm=fb2d83982813c63ff601ac745a08ee65d176c93748c45f2dda492a78ab648272185b09b33ead#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489394&idx=1&sn=5452cd7e82504675d2da2ca3c2614c5a&chksm=fb2d83982813c63ff601ac745a08ee65d176c93748c45f2dda492a78ab648272185b09b33ead#rd)

# 1\. 系统概述

本系统是一个基于在线投资组合选择 (Online Portfolio Selection, OPS) 理论的量化交易系统。

系统集成了多种先进的投资策略、真实市场数据获取、准确的佣金计算、全面的回测分析和直观的可视化功能，为投资决策提供科学依据。

**核心目标**：通过在线学习算法，实现动态资产配置，适应市场变化，提高投资组合的风险调整收益。

**主要特点**：

-   集成多种OPS策略，包括均值回归、动量和 contrarian 策略
    
-   采用混合P&L计算方法，提高回测真实性
    
-   支持真实ETF数据获取与CSV缓存
    
-   实现完整的前向分析和稳健性评估
    
-   提供7子图综合性能仪表板
    

### 2\. 系统架构

系统采用模块化设计，各组件职责明确，相互协作形成完整的量化交易流程。整体架构分为数据层、策略层、回测层、分析层和可视化层五个主要部分。

![](assets/001.png)

系统采用分层架构设计，从数据获取→策略实现→回测验证→结果分析→可视化展示形成完整闭环；

策略层覆盖 7 类经典量化策略，回测层引入真实佣金模型，分析层增加稳健性和跨周期验证，保证策略验证的真实性；

main 函数作为总入口，统一协调各层级核心模块，实现全流程自动化运行。

  

#### a. 数据层

负责所有数据相关的工作。

-   \*\*`AKShareDataEngine`\*\*：这是系统的数据核心，负责从AKShare数据源获取原始的ETF数据和基准数据。
    
-   **数据缓存**：存储获取的真实数据，避免重复请求，提高效率。
    
-   **模拟数据生成**：当真实数据不足或需要测试时，可以生成模拟数据，增强系统的灵活性。
    

#### b. 策略层

这是量化系统的“大脑”，包含了多种投资算法。

-   \*\*`OPSModels`\*\*：这是一个模型库，实现了多种经典的在线投资组合选择算法，例如等权重、指数梯度、追随赢家/输家等。
    
-   \*\*`SingleAssetStrategy`\*\*：这个模块专门支持`Single Asset Momentum`（单一资产动量）策略，这可能是一种专注于挑选特定强势资产进行投资的策略。
    

#### c. 回测层

负责模拟策略在历史数据上的表现，是验证策略有效性的关键环节。

-   \*\*`BacktestEngine`\*\*：回测引擎，它调用策略层中的算法，在历史数据上模拟交易。
    
-   \*\*`IBKRCommissionModel`\*\*：集成盈透券商的佣金模型，使得回测中的交易成本更接近真实情况，提升回测结果的准确性。
    

#### d. 分析层

对回测结果进行深入评估。

-   \*\*`WalkForwardAnalyzer`\*\*：进行“行走验证”，这是一种更稳健的回测方法，将整个历史时期分为多个训练期和测试期滚动进行，防止策略对单一时期过拟合。
    
-   \*\*`PerformanceAnalyzer`\*\*：性能分析器，它结合`RobustnessMetrics`（稳健性指标，如紧缩夏普比率、条件风险价值等）来全面评估策略的盈利能力和风险控制能力。
    

#### e. 可视化层

-   \*\*`Visualizer`\*\*：将分析层产生的数据和结果以图表（如收益曲线、回撤图、指标面板等）形式直观展示出来，便于研究者理解和决策。
    

  

### 3\. 核心模块详细说明

#### 3.1 数据层

**AKShareDataEngine**：负责市场数据的获取、处理和缓存

-   **功能**：
    

-   使用AKShare API获取真实ETF历史数据
    
-   支持CSV缓存机制，提高数据获取效率
    
-   当API调用失败时，自动生成模拟数据作为fallback
    
-   提供开盘价和收盘价数据，支持混合P&L计算
    

-   **关键方法**：
    

-   `fetch_historical_data()`: 获取单个ETF的历史数据
    
-   `fetch_benchmark_data()`: 获取基准指数数据
    
-   `fetch_all_data()`: 获取所有资产和基准的数据
    

**数据流程**：

1.  检查缓存文件是否存在
    
2.  如存在，直接加载缓存数据
    
3.  如不存在，尝试使用AKShare API获取数据
    
4.  API调用失败时，生成模拟数据
    
5.  将数据保存到缓存文件
    

#### 3.2 策略层

**OPSModels**：实现多种在线投资组合选择策略

-   **功能**：
    

-   提供等权重、指数梯度、动量、反转等多种策略
    
-   实现单纯形投影，确保权重满足约束
    
-   所有策略均使用T-1数据进行T决策，避免前瞻偏差
    

-   **关键策略**：
    

-   `equal_weight()`: 等权重投资组合
    
-   `exponential_gradient()`: 指数梯度算法
    
-   `follow_the_winner()`: 动量策略
    
-   `follow_the_loser()`: 反转策略
    
-   `pamr()`: 被动攻击均值回归策略
    
-   `olmar()`: 在线移动平均回归策略
    

**SingleAssetStrategy**：单资产选择策略

-   **功能**：
    

-   基于多种窗口的动量和波动率计算
    
-   支持动量、夏普比率和组合排名方法
    
-   实现定期再平衡机制
    

-   **关键方法**：
    

-   `calculate_features()`: 计算资产选择特征
    
-   `rank_assets()`: 对资产进行排名
    
-   `generate_weights()`: 生成投资组合权重
    

#### 3.3 回测层

**BacktestEngine**：核心回测引擎

-   **功能**：
    

-   实现混合P&L计算方法
    
-   支持佣金扣除和滑点计算
    
-   跟踪权重变化和执行情况
    
-   处理各种策略的回测逻辑
    

-   **关键方法**：
    

-   `run_strategy()`: 运行单个策略的回测
    
-   `_compute_weights()`: 计算策略权重
    
-   `run_benchmark()`: 运行基准策略
    

**IBKRCommissionModel**：模拟盈透证券风格的佣金计算

-   **功能**：
    

-   计算最低佣金、每股成本和最大佣金百分比
    
-   支持滑点计算
    
-   提供基于周转值的成本计算
    

-   **关键方法**：
    

-   `calculate()`: 计算总交易成本
    
-   `calculate_turnover_cost()`: 根据周转值计算成本
    

#### 3.4 分析层

**WalkForwardAnalyzer**：前向分析器

-   **功能**：
    

-   实现训练/验证/测试分割
    
-   执行滚动窗口分析
    
-   计算样本内和样本外性能指标
    
-   评估策略的前向效率
    

-   **关键方法**：
    

-   `run_walk_forward()`: 执行前向分析
    
-   `_calculate_sharpe()`: 计算夏普比率
    

**PerformanceAnalyzer**：性能分析器

-   **功能**：
    

-   计算多种性能指标
    
-   评估策略的风险和收益特性
    
-   分析佣金和执行情况
    

-   **关键方法**：
    

-   `calculate_metrics()`: 计算综合性能指标
    

**RobustnessMetrics**：稳健性指标计算

-   **功能**：
    

-   计算折减夏普比率 (DSR)
    
-   计算概率夏普比率 (PSR)
    
-   计算前向效率 (WFE)
    
-   计算风险条件回撤 (CDaR)
    
-   计算参数稳定性指数 (PSI)
    

-   **关键方法**：
    

-   `deflated_sharpe_ratio()`: 计算DSR
    
-   `probabilistic_sharpe_ratio()`: 计算PSR
    
-   `conditional_drawdown_at_risk()`: 计算CDaR
    

#### 3.5 可视化层

**Visualizer**：综合可视化工具

-   **功能**：
    

-   生成7子图综合性能仪表板
    
-   展示累计性能、夏普比率、回撤等指标
    
-   可视化前向分析结果
    
-   生成风险收益散点图和月度收益热力图
    

-   **关键方法**：
    

-   `plot_comprehensive_results()`: 创建综合可视化仪表板
    
-   `_plot_cumulative_performance()`: 绘制累计性能
    
-   `_plot_drawdowns()`: 绘制回撤分析
    
-   `_plot_walk_forward_efficiency()`: 绘制前向效率
    
-   `_plot_risk_return_scatter()`: 绘制风险收益散点图
    
-   `_plot_monthly_returns()`: 绘制月度收益热力图
    
-   `_plot_summary_table()`: 绘制业绩汇总表
    

### 4\. 功能流程

系统的完整运行流程如下：

1.  **初始化配置**：创建OPSConfig对象，设置策略参数、回测周期等
    
2.  **数据获取**：使用AKShareDataEngine获取ETF和基准数据
    
3.  **策略回测**：使用BacktestEngine运行各种策略的回测
    
4.  **前向分析**：使用WalkForwardAnalyzer执行前向分析，评估策略的样本外性能
    
5.  **性能计算**：使用PerformanceAnalyzer计算各项性能指标
    
6.  **可视化生成**：使用Visualizer生成综合性能仪表板
    
7.  **结果输出**：打印策略性能排名和前向分析结果
    

**核心流程详解**：

`sequenceDiagram       participant Main as 主函数       participant Data as 数据引擎       participant Backtest as 回测引擎       participant WFA as 前向分析器       participant Analyzer as 性能分析器       participant Viz as 可视化工具          Main->>Data: 获取市场数据       Data-->>Main: 返回资产和基准数据          Main->>Backtest: 运行策略回测       Backtest->>Backtest: 计算每日权重和收益       Backtest-->>Main: 返回回测结果          Main->>WFA: 执行前向分析       WFA->>Backtest: 运行滚动窗口回测       Backtest-->>WFA: 返回各窗口结果       WFA-->>Main: 返回前向分析结果          Main->>Analyzer: 计算性能指标       Analyzer-->>Main: 返回性能指标          Main->>Viz: 生成可视化报告       Viz-->>Main: 保存图表文件          Main-->>User: 打印性能汇总和前向分析结果   `

### 5\. 技术特点

#### 5.1 混合P&L计算

系统采用混合P&L计算方法，提高回测的真实性：

-   **执行日**：使用开盘价/开盘价计算收益，捕获隔夜跳空
    
-   **非执行日**：使用收盘价/收盘价计算收益，反映持有期收益
    

这种方法更准确地模拟了实际交易中的收益计算，避免了传统回测方法的偏差。

#### 5.2 时间完整性保障

系统严格遵守T-1到T的时间完整性原则：

-   所有策略决策均基于T-1日及之前的数据
    
-   单资产策略的特征计算使用shift(1)确保数据偏移
    
-   OLMAR策略的移动平均计算只使用历史数据
    

这种设计完全避免了前瞻偏差，确保回测结果的可靠性。

#### 5.3 稳健性评估体系

系统实现了全面的稳健性评估体系：

-   **前向分析**：评估策略的样本外性能
    
-   **多种稳健性指标**：DSR、PSR、WFE、CDaR、PSI
    
-   **风险调整收益**：夏普比率、索提诺比率、卡马比率
    

这些指标从多个维度评估策略的表现，帮助识别真正稳健的投资方法。

#### 5.4 数据获取与缓存

系统实现了高效的数据获取与缓存机制：

-   **真实数据**：使用AKShare API获取A股ETF真实历史数据
    
-   **缓存机制**：将数据保存到CSV文件，避免重复API调用
    
-   **模拟数据**：当API调用失败时，自动生成合理的模拟数据
    

这种设计既保证了数据的真实性，又提高了系统的可靠性和运行效率。

### 6\. 运行说明

#### 6.1 环境要求

-   Python 3.7+
    
-   主要依赖包：
    

-   numpy
    
-   pandas
    
-   matplotlib
    
-   scipy
    
-   akshare
    

#### 6.2 配置参数

系统通过`OPSConfig`类集中管理所有配置参数：

类别

参数

描述

默认值

数据源

data\_source

数据来源

'akshare'

投资组合

tickers

ETF代码列表

\['510300', '510500', '513500', '159941', '159650', '511030', '518800', '159985'\]

投资组合

benchmark

基准指数代码

'000001'

回测期

start\_date

开始日期

'2022-01-01'

回测期

end\_date

结束日期

'2026-01-31'

资本

initial\_capital

初始资本

100000.0

策略参数

eg\_learning\_rate

指数梯度学习率

0.05

策略参数

ftw\_decay

跟随赢家衰减因子

0.97

佣金

min\_commission

最低佣金

1.0

佣金

per\_share\_commission

每股佣金

0.005

前向分析

wf\_train\_months

训练期月数

12

前向分析

wf\_validate\_months

验证期月数

3

#### 6.3 运行步骤

1.  **安装依赖**：
    
    `pip install numpy pandas matplotlib scipy akshare   `
    
2.  **运行系统**：
    
    `python a_stock_ops_v1.py   `
    
3.  **查看结果**：
    

-   控制台输出：策略性能排名和前向分析结果
    
-   图表文件：`strategy_performance_dashboard.png`
    
-   数据缓存：`data_cache/`目录
    

### 7\. 扩展建议

系统设计具有良好的可扩展性，可通过以下方式进一步增强功能：

#### 7.1 策略扩展

-   **添加新策略**：
    

-   实现Hierarchical Risk Parity (HRP)策略
    
-   添加Regime-Aware策略选择
    
-   实现多因子模型
    

-   **策略优化**：
    

-   为EG和PAMR策略添加自适应学习率
    
-   实现策略参数的自动优化
    

#### 7.2 数据扩展

-   **数据源扩展**：
    

-   添加更多数据源，如Wind、聚宽等
    
-   支持股票和债券数据
    

-   **数据质量**：
    

-   添加数据质量检查和异常值处理
    
-   实现更复杂的模拟数据生成模型
    

#### 7.3 功能扩展

-   **风险控制**：
    

-   添加止损和止盈功能
    
-   实现VaR和CVaR约束
    

-   **交易执行**：
    

-   添加更复杂的交易成本模型
    
-   实现最优执行算法
    

-   **监控系统**：
    

-   添加策略监控和警报功能
    
-   实现实时性能跟踪
    

#### 7.4 技术优化

-   **性能优化**：
    

-   使用Numba加速计算密集型代码
    
-   实现并行回测
    

-   **部署优化**：
    

-   容器化部署
    
-   实现API服务
    

### 8\. 总结

本系统是一个功能完整、设计合理的在线投资组合选择系统，为A股ETF投资提供了科学的决策支持工具。系统集成了多种先进的投资策略、真实的市场数据、准确的回测分析和直观的可视化功能，能够帮助投资者更好地理解和应用量化投资方法。

通过在线学习算法，系统能够适应市场变化，动态调整资产配置，为投资者提供更稳健的风险调整收益。同时，系统的模块化设计和良好的扩展性，为未来的功能增强和技术升级提供了坚实的基础。

**系统价值**：

-   为投资者提供科学的投资决策工具
    
-   促进量化投资方法在A股市场的应用
    
-   为投资策略的研究和开发提供实验平台
    
-   帮助投资者更好地理解和控制投资风险
    

### 9\. 附录

#### 9.1 策略参数表

策略

参数

描述

默认值

Exponential Gradient

eg\_learning\_rate

学习率

0.05

Follow the Winner

ftw\_decay

衰减因子

0.97

PAMR

epsilon

损失阈值

0.5

PAMR

C

约束参数

5.0

OLMAR

epsilon

预期收益阈值

0.5

Single Asset

sa\_momentum\_windows

动量窗口

\[21, 63, 126, 252\]

Single Asset

sa\_rebalance\_frequency

再平衡频率

21

#### 9.2 性能指标说明

指标

描述

计算方法

Total Return

总收益率

(最终价值/初始价值) - 1

CAGR

年化复合增长率

(最终价值/初始价值)^(1/年数) - 1

Volatility

年化波动率

日收益率标准差 \* sqrt(252)

Sharpe

夏普比率

(年化收益率 - 无风险利率) / 年化波动率

Sortino

索提诺比率

(年化收益率 - 无风险利率) / 下行波动率

Max Drawdown

最大回撤

从峰值到谷值的最大损失百分比

Calmar

卡马比率

CAGR / 最大回撤绝对值

DSR

折减夏普比率

考虑多重测试偏差的夏普比率

PSR

概率夏普比率

真实夏普比率超过基准的概率

CDaR

风险条件回撤

最坏alpha%情况下的预期回撤

WFE

前向效率

样本外夏普比率 / 样本内夏普比率

#### 9.3 代码结构

`a_stock_ops_v1.py   ├── OPSConfig                # 配置类   ├── AKShareDataEngine        # 数据引擎   ├── IBKRCommissionModel      # 佣金模型   ├── OPSModels                # OPS策略实现   ├── SingleAssetStrategy      # 单资产策略   ├── BacktestEngine           # 回测引擎   ├── WalkForwardAnalyzer      # 前向分析器   ├── PerformanceAnalyzer      # 性能分析器   ├── RobustnessMetrics        # 稳健性指标   ├── Visualizer               # 可视化工具   └── main()                   # 主函数   `

### 10\. 参考文献

1.  Li, B., Hoi, S. C. H., & Gopalkrishnan, V. (2012). PAMR: Passive aggressive mean reversion strategy for portfolio selection.
    
2.  Li, B., Zhao, P., Hoi, S. C. H., & Gopalkrishnan, V. (2012). OnLine Portfolio Selection with Moving Average Reversion.
    
3.  Helmbold, D. P., Schapire, R. E., Singer, Y., & Warmuth, M. K. (1998). On-Line Portfolio Selection Using Multiplicative Updates.
    
4.  Bailey, D. H., & Lopez de Prado, M. (2014). The Deflated Sharpe Ratio: A Sharper Sharpe Ratio.
    
5.  DeMiguel, V., Garlappi, L., & Uppal, R. (2009). Optimal Versus Naive Diversification: How Inefficient is the 1/N Portfolio Strategy?
    

  

运行后最终输出结果如下：

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)