# 重磅开源！pyrust-bt：打造一套兼顾研发效率与极致性能的开源回测框架

QuantML QuantML 2025-08-08 18:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247491294&idx=1&sn=e6d151510b8e56e0caa01a537662cacb&chksm=cfe0b0ccb107793caeb882bf8e3e290053784098667627ef0809035bfe6160601d0cd18fe20e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247491294&idx=1&sn=e6d151510b8e56e0caa01a537662cacb&chksm=cfe0b0ccb107793caeb882bf8e3e290053784098667627ef0809035bfe6160601d0cd18fe20e#rd)

### 从 1600 到 42 万 bars/s，我们是如何通过混合语言架构将回测性能提升 250 倍的

* * *

在量化投资领域，回测框架是策略研发的基石。我们常常陷入一个两难的困境：是选择 Python 的丰富生态和快速迭代能力，还是追求 C++ 的极致性能？如果有一套框架能将二者完美结合，会是怎样的体验？

今天，我们开源了一套专为实战而生的混合语言回测框架——`pyrust-bt`。它巧妙地融合了 Python 的灵活性与 Rust 的高性能，旨在为量化研究者和工程师提供一个“上手快、跑得快、可扩展”的理想工作台。

项目地址：https://github.com/QuantML-C/pyrust-bt

![](assets/001.png)

### 为什么是 Python + Rust？—— 鱼与熊掌，可以兼得

回测框架的选型，本质上是在研发效率与运行效率之间做权衡。

-   **Python**: 量化研究的“瑞士军刀”。`NumPy`、`Pandas`、`Jupyter`、`Matplotlib` 等构成了无与伦比的数据科学生态，让策略表达、数据处理和可视化探索变得极其高效。然而，全局解释器锁（GIL）和动态类型等特性，使其在处理大规模、高频率的回测任务时，性能往往成为瓶颈。
    
-   **Rust**: 现代系统编程语言的翘楚。它以“零成本抽象”、“内存安全”和“并发性能”著称，性能媲美 C++，却无内存管理的后顾之忧。Rust 的强类型系统和高效的编译器优化，使其成为构建性能敏感型底层引擎的绝佳选择。
    

`pyrust-bt` 的核心理念，便是将两者的优势发挥到极致：

-   **Python 端（策略层）**: 负责策略逻辑、数据预处理和结果分析。研究员可以沿用熟悉的工具链，专注于策略创新。
    
-   **Rust 端（引擎层）**: 承担所有计算密集型任务，如事件循环、订单撮合、持仓计算和指标的向量化运算，确保回测过程风驰电掣。
    

通过 `PyO3` 和 `maturin`，我们将 Rust 核心编译成 Python 的本地扩展模块，实现了两者之间的无缝调用。对 Python 用户而言，调用 Rust 函数就像调用一个普通的 Python 包一样简单，几乎感受不到语言边界的存在。

* * *

### 架构解析：一个分层解耦的现代化设计

`pyrust-bt` 采用分层、松耦合的设计，确保各模块职责清晰，易于维护和扩展。

-   **前端 (Streamlit)**: 提供了一个简洁的 Web UI，用于提交回测任务、监控运行状态，并对结果（如净值曲线、核心指标）进行可视化展示。
    
-   **API 层 (FastAPI)**: 作为前后端交互的桥梁，提供了一套标准的 RESTful 接口，用于管理回测任务的生命周期（创建、查询、获取结果）。
    
-   **Python API 层**: 为策略开发者提供了丰富的工具集，包括策略基类、数据加载器、多维度分析器和参数优化器（如网格搜索）。
    
-   **Rust 引擎 (PyO3 扩展)**: 整个框架的“心脏”，负责执行回测的核心逻辑，包括但不限于时间序列推进、订单撮合、成本模型计算、向量化技术指标以及核心统计指标的生成。
    

**数据流示意**:

`[数据源: CSV/Parquet] -> [Python 数据加载器] -> [Rust 回测引擎] -> [回测结果] -> [Python 分析器] -> [前端/API]   `

* * *

### 核心功能一览：从基础到进阶，满足实战所需

`pyrust-bt` 不仅仅是一个简单的回测循环，它内置了大量面向实战的功能模块。

-   **精细的订单与撮合模型**:
    

-   支持市价单和限价单（简化模型：在同一根 bar 内即时撮合）。
    
-   内置成本模型，可配置手续费率 (`commission_rate`) 和滑点 (`slippage_bps`)。
    
-   实时跟踪持仓成本、已实现和未实现盈亏。
    
-   提供 `on_order` 和 `on_trade` 事件回调，供策略订阅和响应。
    

-   **灵活的策略编程模型**:
    

-   清晰的生命周期函数：`on_start`, `next(bar)`, `on_stop`。
    
-   支持多种下单格式，既兼容简单的字符串命令 (`"BUY"`, `"SELL"`)，也支持更精细的结构化字典，以满足复杂订单需求。
    

-   **多维度的分析器 (Analyzers)**:
    

-   **收益与风险**: 计算总收益、年化收益、波动率、夏普比率、Sortino 比率、Calmar 比率、5% VaR 等关键指标。
    
-   **回撤分析**: 详细剖析所有回撤段落，包括最大回撤、回撤持续时间、恢复时间等。
    
-   **交易分析**: 自动配对买卖操作，生成详细的回合交易列表，统计胜率、盈亏比、平均持仓周期等。
    
-   **因子分析**: 内置简单的因子测试工具，支持按因子值进行分位数分组，计算各组的未来收益、IC 值和单调性。
    

-   **参数优化与前端交互**:
    

-   内置简单的网格搜索功能，可自定义优化目标。
    
-   配套的 Streamlit 前端，让回测任务的管理和结果可视化变得简单直观。
    

* * *

### 性能工程揭秘：250 倍性能提升是如何实现的？

从最初的 1,682 bars/s 到惊人的 419,552 bars/s，`pyrust-bt` 的性能飞跃源于一系列精心设计的优化策略。

1.  **预提取数据 (Pre-fetching)**: 在回测开始前，将全部 Python 数据一次性转换为 Rust 的原生数据结构。这极大地减少了回测循环中 Python 与 Rust 之间的频繁调用和数据转换开销，是性能提升的关键。
    
2.  **批处理执行 (Batch Processing)**: Python 的全局解释器锁 (GIL) 是性能的一大掣肘。通过引入可配置的 `batch_size`，我们将策略的 `next` 函数调用分批处理，显著减少了 GIL 争用，提升了 CPU 利用率。
    
3.  **向量化指标计算 (Vectorized Indicators)**: 像移动平均线 (SMA) 和相对强弱指数 (RSI) 这类计算，我们直接在 Rust 端使用向量化的方式实现，并采用滑动窗口算法将更新复杂度降至 O(1)。
    
4.  **内存优化**: 在 Rust 引擎内部，我们对所有需要动态增长的容器（如净值曲线、交易列表）都进行了预分配，有效避免了运行时的内存重分配和复制，确保了性能的稳定。
    

**性能基准 (本地实测)**:

-   **数据集**: 55 万条分钟线数据
    
-   **回测耗时**: ~1.3 秒
    
-   **处理速度**: ≈ 42 万 bars/s
    

* * *

### 上手指南：三步完成你的第一次高性能回测

#### 1\. 构建 Rust 扩展

`# 安装构建工具   pip install maturin   # 进入 Rust 目录并构建   cd rust/engine_rust   maturin develop --release   `

#### 2\. 运行示例

`# 回到项目根目录   cd ../..   # 运行一个基础回测   python examples/run_mvp.py   # 体验增强的分析器   python examples/run_analyzers.py   # 尝试参数网格搜索   python examples/run_grid_search.py   # 查看性能测试结果   python examples/run_performance_test.py   `

#### 3\. 启动 API 和前端

`# 启动 FastAPI 服务   python -m uvicorn python.server_main:app --reload   # 在新终端中启动 Streamlit 前端   set PYRUST_BT_API=http://127.0.0.1:8000   streamlit run frontend/streamlit_app.py   `

现在，你可以在浏览器中打开 Streamlit 页面，提交并监控你的回测任务了。

![](assets/002.png)

  

* * *

### 策略开发体验：依然是你熟悉的 Python

尽管底层由 Rust 驱动，但策略开发体验依然是纯粹的 Python。

`from pyrust_bt import Strategy, BacktestEngine, BacktestConfig, load_csv_to_bars      class MySimpleStrategy(Strategy):       def next(self, bar):           # 伪代码：价格高于 SMA 则买入           if bar["close"] > bar.get("sma", 0):               return {"action": "BUY", "type": "market", "size": 1.0}           returnNone      # 配置回测参数   cfg = BacktestConfig(       start="2020-01-01", end="2020-12-31",       cash=100000, commission_rate=0.0005,       slippage_bps=2.0, batch_size=1000   )      # 加载数据并运行   bars = load_csv_to_bars("examples/data/sample.csv")   engine = BacktestEngine(cfg)   result = engine.run(MySimpleStrategy(), bars)      # 打印结果   print(result["stats"])   `

* * *

### 未来展望 (Roadmap)

`pyrust-bt` 已经为一个高性能、可扩展的回测系统奠定了坚实的基础，但我们的征程才刚刚开始。未来的发展方向包括：

-   **更精细的撮合模型**: 支持部分成交、挂单簿、复杂的订单类型（止损、止盈、OCO）以及流动性冲击模型。
    
-   **分布式计算**: 利用 Ray 或 Celery 实现多进程/多节点的参数优化。
    
-   **实时交易接口**: 打通回测与实盘交易的通道，实现策略的无缝迁移。
    
-   **更专业的因子研究工具**: 支持多资产横截面分析、IC/IR 时间序列分析等。
    
-   **更现代化的前端**: 使用 React + ECharts/Plotly 打造交互性更强的可视化界面，支持交易标注、策略回放等功能。
    

### 结语

`pyrust-bt` 通过将 Python 和 Rust 的优势有机结合，我们得以构建一个既适合快速原型验证，又能承载大规模生产级回测的强大框架。我们欢迎所有对量化交易和系统工程感兴趣的朋友加入社区，共同打磨这把利器。

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/003.jpg)