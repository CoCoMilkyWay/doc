# Qlib库简介与实践步骤介绍

蝴蝶量化 随率而动的因子工厂 2025-11-05 12:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484266&idx=1&sn=3df47acf2157be825963cc712405a0db&chksm=c08c6e076d59e881654ec6368b45ab11c549f8a20529cbf045fc93821cb25744af9d86983b18#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484266&idx=1&sn=3df47acf2157be825963cc712405a0db&chksm=c08c6e076d59e881654ec6368b45ab11c549f8a20529cbf045fc93821cb25744af9d86983b18#rd)

## 技术背景

之前我们介绍了因子各种使用方法，惟独缺少了机器学习方法的讨论与验证。主要是由于，笔者对这部分内容研究不深，没有形成一个完整的研究提体系。

5年前还在机构的时候，研究过一段时间，但是没有找到一个比较满意的策略，总感觉过拟合的风险比较大，所以后来一直专注其他的因子策略的研究。为了与时俱进，近期打算重拾机器学习部分的因子策略研究与开发。

机器学习一个被吹上天的工具QLib自然是需要第一个研究的，个人认为它并没有那些博主吹的那么夸张，但还还是值的学习一下，内部逻辑本文不涉及，大部分内容源子最近看的一篇研报：《华泰人工智能系列40》，并且部分借助了AI总结，需要论文的可以私信，我发你。

下面是本期的主要内容：介绍、优点、使用方法、案例分析等等。

* * *

## 一、Qlib 是什么？

Qlib 是微软亚洲研究院于2020年开源的一个**面向AI的量化投资平台**。其核心目标不是提供一个“黑箱”策略，而是构建一个**基础设施**，将AI量化投资的全流程标准化、模块化和高性能化。

-   **定位**：AI量化投资的**操作系统**或**框架**，而非一个策略库。
    
-   **核心价值**：
    

1.  **全流程覆盖**：从数据管理、Alpha挖掘、模型训练到回测分析，提供端到端的解决方案。
    
2.  **工程创新**：在数据存储、表达式计算等底层架构上做了深度优化，解决大规模数据处理的性能瓶颈。
    
3.  **降低门槛**：通过统一的接口和模块化设计，让研究人员能更专注于模型和策略本身，而非重复的“造轮子”工作。
    

## 二、Qlib 的优点与革新点？

其实，Qlib的底层数据处理方式并没有什么革新的点，绝大部分算法，都是市面上的常见算法，我们自己也可以造出类似的轮子。相反，在数据处理、读取层面的改进，qlib给我们带来了新的方案。

1.  **统一的数据管理层（最大的改进）**：
    

-   **方法**：Qlib设计了独有的**面向金融时序数据的二进制存储格式**。所有数据（价量、基本面等）都被转换成统一的二进制格式（bin），并辅以日历和标的索引文件。
    
-   **优势**：提供了类似数据库的查询接口（如`D.features(D.instruments(market='all'), ['$close', '$volume'])`），但底层是高性能的二进制文件，兼顾了查询便利性和读取速度。
    

3.  **一体化的Python框架**：
    

-   **方法**：整个研究流程都在Qlib的Python框架内完成。通过定义`Task`、`Dataset`、`Model`、`Strategy`等配置对象，以“工作流（Workflow）”的方式串联起来。
    

5.  **高性能底层架构（核心创新）**：
    

-   **方法**：构建了内存+磁盘的二级缓存。对于表达式计算中的中间结果（如`Mean($close, 5)`）进行缓存，避免重复计算。
    
-   **优势**：在复杂的因子计算中能显著提升速度。
    

-   **方法**：因子可以通过字符串表达式直接定义，如 `(Mean($close, 5) - $close) / Mean($close, 5)`。Qlib的引擎会解析并高效执行这些表达式。
    
-   **优势**：极大简化了因子编写难度，代码可读性高，且引擎底层做了优化。
    
-   **代码体现**：在自定义因子时，直接返回表达式字符串列表。
    

-   **方法**：采用“日期索引 + 列式存储”的二进制格式。每个因子的数据按日期组织，存储为紧凑的二进制文件。读取时，可以快速定位到特定日期范围的所有股票数据，或特定股票的所有历史数据。
    
-   **代码体现**：通过`scripts/dump_bin.py`脚本将CSV原始数据转换为Qlib格式。
    
-   **效果**：华泰报告引用微软论文的测试数据表明，Qlib在数据读取和因子计算任务上，性能远超MySQL、MongoDB、InfluxDB和HDF5。
    

-   **a. 数据存储方案**：
    
-   **b. 表达式引擎**：
    
    `fields += ["Mean($close, %d)/$close" % d for d in windows]   `
    
-   **c. 缓存系统**：
    

## 三、代码实战：以港股LightGBM选股策略为例

华泰报告通过一个完整的案例展示了Qlib的使用流程。

### 步骤1：环境安装与数据准备

github网址：https://github.com/microsoft/qlib?tab=readme-ov-file

-   **代码**：
    
    `# 1. 安装C++构建工具（Windows必需）   # 2. 通过源码安装Qlib   git clone https://github.com/microsoft/qlib.git   cd qlib   python setup.py install      # 也可以直接用pip直接安装，具体可以参见github   pip install pyqlib      # 3. 下载官方A股数据（学习用）   python scripts/get_data.py qlib_data --target_dir ~/.qlib/qlib_data/cn_data --region cn      # 4. 导入自定义的港股CSV数据   python scripts/dump_bin.py dump_all --csv_path ~/.qlib/csv_data/hk_data --qlib_dir ~/.qlib/qlib_data/hk_data   `
    
-   **详解**：这一步解决了数据来源问题。Qlib提供了标准化的数据转换工具，将原始的CSV数据转换为其高性能的二进制格式。
    

### 步骤2：初始化环境与数据读取

-   **代码**：
    
    `import qlib   from qlib.config import REG_CN   # 初始化Qlib，指定数据路径   provider_uri = “~/.qlib/qlib_data/hk_data”   qlib.init(provider_uri=provider_uri)      # 获取所有股票池和交易日历   from qlib.data import D   instruments = D.instruments(market=‘all’)   dates = D.calendar(start_time=‘2020-01-01’, end_time=‘2020-11-30’)   `
    
-   **详解**：`qlib.init()`是入口，加载数据配置。`D`对象是数据查询的核心入口。
    

### 步骤3：因子生成与预处理 - 使用内置Alpha158

-   **代码**：
    
    `from qlib.contrib.data.handler import Alpha158   data_handler_config = {       "start_time": "2020-01-01",       "end_time": "2020-11-30",       "fit_start_time": "2020-01-01",       "fit_end_time": "2020-06-30",       "instruments": instruments,   }   h = Alpha158(**data_handler_config)   # 获取特征和标签   df_feature = h.fetch(col_set="feature") # 158个因子值   df_label = h.fetch(col_set="label")     # 下期收益率（标签）   `
    
-   **详解**：
    

-   `Alpha158`是一个`DataHandler`，它封装了158个量价因子的表达式和计算逻辑。
    
-   `fit_start_time`和`fit_end_time`用于指定训练集的时间范围，该范围内的数据会进行**截面标准化**（`CSZScoreNorm`），而测试集则使用训练集的统计量进行标准化（`ZScoreNorm`）。这是避免未来信息泄露的关键步骤。
    

### 步骤4：模型训练与回测 - 配置化工作流

这是Qlib的核心，通过一个`task`字典来定义整个实验。

-   **代码（关键配置部分）**：
    
    `task = {       "model": {           "class": "LGBModel",       # 使用LightGBM模型           "module_path": "qlib.contrib.model.gbdt",           "kwargs": {                # 模型超参数               "loss": "mse",               "colsample_bytree": 0.8879,               "learning_rate": 0.0421,               "subsample": 0.8789,               "lambda_l1": 205.6999,               "lambda_l2": 580.9768,               "max_depth": 8,               "num_leaves": 210,               "num_threads": 20,           },       },       "dataset": {           "class": "DatasetH",           "module_path": "qlib.data.dataset",           "kwargs": {               "handler": {                   "class": "Alpha158",                   "module_path": "qlib.contrib.data.handler",                   "kwargs": data_handler_config,               },               "segments": {          # 划分训练、验证、测试集                   "train": ("2020-01-01", "2020-04-30"),                   "valid": ("2020-05-01", "2020-06-30"),                   "test": ("2020-07-01", "2020-11-30"),               },           },       },   }   `
    
-   **详解**：
    

-   **模块化**：`model`和`dataset`是独立的配置单元，可以轻松替换（例如将`LGBModel`换成`XGBModel`）。
    
-   **工作流引擎**：Qlib的`workflow`模块会根据这个配置，自动执行数据加载、模型训练、预测、回测等一系列操作。用户只需调用`model.fit(dataset)`和后续的回测函数。
    
-   **策略与回测**：回测配置（`port_analysis_config`）定义了交易规则，如TopK选股、换仓逻辑、手续费等。
    

### 步骤5：结果分析

-   **代码**：
    
    `# 生成分析图表   analysis_position.report_graph(report_normal_df)   `
    
-   **输出**：Qlib会自动生成丰富的图表，包括：
    

-   策略净值 vs 基准净值
    

![](assets/001.png)

```
*   超额收益曲线
```

![](assets/002.png)

```
*   信息比率（Information Ratio）*   最大回撤（Max Drawdown）*   换手率（Turnover Rate）*   预测IC值（Information Coefficient）序列图
```

![](assets/003.png)

## 四、效果验证：性能与效率

可以从两个层面验证了Qlib的效果：

1.  **平台性能验证**：
    

-   引用微软论文的测试数据，证明其二进制存储格式在数据读取和因子计算速度上，相比传统方法有**数量级的提升**。这是Qlib最硬核的优势。
    

3.  **策略案例效果验证**：
    

-   报告中的港股LightGBM策略案例在2020年7月至10月产生了稳定的超额收益，但在11月出现回撤。
    

### 五、写在最后

本文大部分内容来自于研究报告，Qlib的核心贡献在于其**开源和工程创新**，为整个行业提供了高标准的基础设施，有望降低重复研发成本，推动AI量化技术的发展。

-   **对于从业者**：Qlib是一个强大的生产工具，尤其适合需要处理大规模数据、构建复杂AI模型的机构投资者。
    
-   **对于学习者**：它是学习AI量化投资全流程的绝佳教材，代码结构清晰，范例丰富。
    

个人认为，这是一个很好的学习工具，通过使用能够清楚的了解因子策略各个步骤，实现方式，大大的减少我们自己造轮子的时间与学习成本。但是个人认为，这只是一个工具，没有必要将其神化。

到底好不好，还是要看使用这的水平与使用方法，笔者始终秉持：基础决定了未来的深度。所以，我认为里面的轮子，我们还是会从0造一遍，让各位小伙伴能够对机器学习、因子策略有更加深刻的理解。如果仅仅是会调用几行代码是远远不够的。

不懂内在算法逻辑，是不能写出很好的策略，我们不光要“术”上的进步，还是“根”上的进步。