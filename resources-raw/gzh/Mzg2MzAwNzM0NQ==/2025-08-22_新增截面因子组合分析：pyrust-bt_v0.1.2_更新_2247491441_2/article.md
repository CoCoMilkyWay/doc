# 新增截面因子组合分析：pyrust-bt v0.1.2 更新

QuantML QuantML 2025-08-22 17:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247491441&idx=2&sn=da1aa2f04c662b2c920a0347a333045e&chksm=cf9250e93d4996235bef42020206c4a38e22bd7c134ccb871f0900db2c8043c3fa823d55871a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247491441&idx=2&sn=da1aa2f04c662b2c920a0347a333045e&chksm=cf9250e93d4996235bef42020206c4a38e22bd7c134ccb871f0900db2c8043c3fa823d55871a#rd)

### 本次更新概览

-   新增了一套“截面因子 → 分位组合/IC → 多资产回测/报告”的完整链路，包含核心回测类、分析器可运行示例，覆盖研究与实盘回测两侧的典型工作流。
    

### 1) 截面因子分层回测器 `python/pyrust_bt/cs_factor_backtester.py`

-   **用途**：不依赖撮合引擎，直接用当期因子与下一期收益做分位组合与多空组合评价（更快、更轻）。
    
-   **核心能力**：
    

-   逐日分桶（`quantiles`）、可选截面去极值（`winsorize`）与标准化（`standardize`）。
    
-   产出各分位与多空的日收益、净值与统计：年化、波动、Sharpe、Calmar、最大回撤、回撤时长、胜率等。
    
-   逐分位换手率（集合交并法，真实刻画成分变动）。
    

-   **输出**：按分位导出 `ret_q*.csv`、`equity_q*.csv`、多空 `ret_long_short.csv` / `equity_long_short.csv`、统计 `stats.json`、`stats_long_short.json`、换手 `turnover_q*.csv`。
    
-   **示例**：文件内置随机数据 demo，一键导出到 `examples/results/cs_backtester_demo/`。
    

### 2) 多因子分析器 `python/pyrust_bt/multi_factor_analyzer.py`

-   **数据结构**：新增 `FactorResult`、`MultiFactorReport`；支持 TS/CS 两种口径（`AnalysisMethod`）。
    
-   **CS 分析（横截面）**：
    

-   逐日分桶、截面 Spearman IC/IC\_IR/IC 胜率、分位平均前瞻收益、单调性评分。
    
-   最高分位逐日成分换手率、因子衰减（多前瞻期 IC）。
    

-   **TS 分析（时间序列）**：
    

-   滚动皮尔逊相关得到 IC 序列与 IR；可选 Numba 加速（大样本自动启用）。
    
-   因子稳定性评分（基于 IC 均值/标准差归一化）。
    

-   **可扩展性**：
    

-   `register_analyzer` 注册机制 + `FactorConfig` 一键调度（`analyze_all_factors_with_config`）。
    
-   自动发现因子列（剔除价格字段），支持列名配置与缺失值策略（`nan_policy`）。
    

-   **报告导出**：详细结果 JSON、因子排名 CSV、相关性矩阵 CSV、汇总统计 JSON。
    

### 3) 示例脚本

-   `examples/run_cs_momentum_sample.py`
    

-   生成多股票日频动量因子（20/126/252 日），运行 CS 因子评价，打印排名与摘要，导出报告到 `examples/results/cs_momentum_reports/`。
    

-   `examples/run_cs_quantile_portfolios.py`
    

-   生成样例 + 逐日分桶，构建分位成分集合；以 `BacktestEngine` 运行“按分位再平衡”的多资产策略（`QuantileRebalanceStrategy`），导出每分位的交易与净值。
    

### 设计特点

-   **截面预处理完备**：winsorize + z-score（逐日）+ 可控缺失值策略，保证稳健性。
    
-   **指标体系完整**：收益/净值、Sharpe、Calmar、最大回撤、胜率；IC/IC\_IR/RankIC、单调性、换手、衰减。
    
-   **工程化与易用性**：统一列名约定（`datetime`、`symbol`、`close`、因子列；CS 回测需 `ret_next`）、数值强制为 float、防除零、`Int64` 分桶避免空值问题。
    
-   **结果可落地**：CSV/JSON 全量导出，便于外部看板与复现实验。
    

本次更新来自社区贡献者@

代码地址：https://github.com/QuantML-C/pyrust-bt

欢迎试用与提议功能，期待更多开发者加入我们！

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/001.jpg)