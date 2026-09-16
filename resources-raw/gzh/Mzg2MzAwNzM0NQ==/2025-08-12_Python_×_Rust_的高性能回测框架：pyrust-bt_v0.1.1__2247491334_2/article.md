# Python × Rust 的高性能回测框架：pyrust-bt v0.1.1 更新

QuantML QuantML 2025-08-12 16:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247491334&idx=2&sn=ef675cb94cdd90df24baa61c0cdeb572&chksm=cf1393ed895588a865308a81cb4c72e148e15cbde6c686dff1607835f4833f61186cb9223535#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247491334&idx=2&sn=ef675cb94cdd90df24baa61c0cdeb572&chksm=cf1393ed895588a865308a81cb4c72e148e15cbde6c686dff1607835f4833f61186cb9223535#rd)

在量化研发中，策略表达与回测性能长期处于拉扯：Python 生态极佳但速度受限，C++/Rust 性能强悍却不够“友好”。pyrust-bt 的设计目标，就是把两者的优势融合：策略与数据处理继续用 Python，高吞吐的回测内核交给 Rust，通过 PyO3 实现像本地包一样的调用体验。

Github项目地址：https://github.com/QuantML-C/pyrust-bt

### 框架综述

-   架构分层
    

-   Rust 引擎（PyO3 扩展）：时间推进、订单撮合、成本模型、向量化指标、统计计算
    
-   Python API：策略基类、数据加载、分析器、优化器、引擎包装
    
-   API/前端：FastAPI（任务接口）、Streamlit（可视化）
    

-   策略编程模型
    

-   生命周期：on\_start → next(bar\[, ctx\]) → on\_stop
    
-   事件回调：on\_order（submitted/filled）、on\_trade（含 symbol/price/size）
    
-   动作格式：字符串（“BUY/SELL”）或结构化 dict（action/type/size/price/symbol）
    

### 回测引擎与成本模型

-   订单/撮合：市价、限价（简化：同 bar 撮合），手续费 commission\_rate、滑点 slippage\_bps
    
-   仓位/账本：position、avg\_cost、cash、equity、realized\_pnl
    
-   指标/统计：SMA/RSI（滑动窗口 O(1) 更新）、总收益、年化、波动率、Sharpe、Calmar、最大回撤与持续时间
    

### 分析器与优化

-   分析器
    

-   收益与风险指标、回撤段落（持续/恢复）、回合交易（入/出、周期、盈亏、胜率/Profit Factor）
    
-   因子回测：分位数均值、IC、单调性，并可生成综合报告
    

-   参数优化：朴素网格搜索（可扩展随机/贝叶斯）
    

### 性能工程（单资产循环）

-   关键路径优化：预提取数据（降低 Python↔Rust 往返）、批处理 batch\_size、预分配容器、内联热点函数
    
-   指标计算：Rust 向量化（SMA/RSI），滑动窗口 O(1)
    
-   实测（55 万 bar）：1.3 秒，≈ 419,552 bars/s（较初版 ~1,682 bars/s 提升 ≈ 250×）
    

* * *

## v0.1.1 更新重点

-   多资产/多周期（MVP）
    

-   新增 `BacktestEngine.run_multi(strategy, feeds)`，以“联合时间线”推进
    
-   支持每条指令带 `symbol`；事件回调 on\_order/on\_trade 均携带 symbol
    
-   策略优先实现 `next_multi(update_slice, ctx)`，其中 `update_slice: Dict[feed_id -> bar]`
    
-   上下文 ctx 聚合：positions（逐 symbol 头寸/成本）、cash、equity、bar\_index、last\_prices
    

-   上下文能力
    

-   `EngineContext` 注入到 `on_start(ctx)` 与 `next(bar, ctx)`，获取 position/avg\_cost/cash/equity/bar\_index
    
-   保持 `next(bar)` 向后兼容
    

-   因子回测提速
    

-   新增 Rust 侧 `factor_backtest_fast`，Python 的 `factor_backtest` 在数据量 > 5k bars 时自动走加速路径
    

-   示例与文档
    

-   多资产：`examples/run_multi_assets.py` + `examples/data/multi_assets.csv`
    
-   分析器：`examples/run_analyzers.py`
    
-   网格搜索：`examples/run_grid_search.py`
    
-   性能测试：`examples/run_performance_test.py`
    
-   文档：中英文 README、CHANGELOG
    

* * *

## 快速上手

-   安装与构建
    

`pip install maturin   cd rust/engine_rust   maturin develop --release   `

-   运行示例
    

`cd ../..   python examples/run_mvp.py           # 基础回测   python examples/run_analyzers.py     # 分析器   python examples/run_grid_search.py   # 网格搜索   python examples/run_multi_assets.py  # 多资产/多周期   `

-   在代码中使用（单资产）
    

`from pyrust_bt.api import BacktestEngine, BacktestConfig   from pyrust_bt.data import load_csv_to_bars      cfg = BacktestConfig(start="2020-01-01", end="2020-12-31",                        cash=100000, commission_rate=0.0005,                        slippage_bps=2.0, batch_size=1000)   engine = BacktestEngine(cfg)      bars = load_csv_to_bars("examples/data/sample.csv", symbol="SAMPLE")   res = engine.run(MyStrategy(), bars)   print(res["stats"], res["equity"])   `

-   多资产策略（核心形态）
    

`class MultiAssetStrategy(Strategy):       def next_multi(self, update_slice, ctx):           actions = []           for feed_id, bar in update_slice.items():               sym = bar.get("symbol", feed_id)               # 根据多资产最新 bar 决策               # ...               actions.append({"action": "BUY", "type": "market", "size": 1.0, "symbol": sym})           return actions   `

* * *

## 典型应用场景

-   快速策略迭代：Python 生态下的因子/择时/事件驱动策略，高速回测验证
    
-   研究到生产：统一的数据、回测、分析、优化与可视化链路，利于团队协作与复现
    
-   多资产/多周期：按联合时间线处理多标的异步数据，对接组合维度的研究
    

* * *

## 未来路线（关键里程碑）

-   撮合增强：部分成交、挂单簿、止损/止盈、OCO、条件单；更细的流动性/冲击模型
    
-   多资产完善：交易日历/时区、对齐策略、结果中返回逐 symbol 期末持仓与成本
    
-   并行与分布式：随机/贝叶斯/交叉验证；Ray/Celery/k8s Jobs 的分布式参数搜索
    
-   分析与报告：回撤可视化、分组统计、交易分布、报告导出（PDF/HTML/多 run 对比）
    
-   前端：React + ECharts/Plotly，可视化增强与交互回放、WebSocket 实时流
    

* * *

## 一点实践建议

-   性能优先级：尽量使用结构化动作（dict）、合适的 `batch_size`（1000–5000）、Rust 向量化指标
    
-   数据格式：大样本建议 Parquet/Arrow，并按 symbol/time 分区
    
-   事件回调：订阅 `on_order/on_trade` 便于审计与分析；多资产策略建议在 ctx 中管理组合级状态
    
-   结果一致性：将策略内指标/因子提前写回 `bars`，避免临时变量影响后续分析
    

* * *

pyrust-bt 的出发点很简单：让研究员继续写舒服的 Python 代码，让引擎用 Rust 跑到飞起，并把研发到生产的链路尽量打通。随着多资产/多周期与因子回测加速的落地，这个框架正在成为一个“上手快、跑得快、能长大”的回测基座。

欢迎试用与提议功能，期待你在实际策略上的闭环反馈。

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/001.jpg)