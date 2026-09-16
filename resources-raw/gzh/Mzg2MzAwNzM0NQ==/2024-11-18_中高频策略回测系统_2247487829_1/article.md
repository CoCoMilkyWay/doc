# 中高频策略回测系统

Hugo QuantML 2024-11-18 21:57 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487829&idx=1&sn=cec78c5bb5f70c236e1571f1895a000c&chksm=cfe2f998f648f4627e77bebb02d8d5f6b2d6a559620b9906be8aec6c29ff2a41dba17e7b30c5#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487829&idx=1&sn=cec78c5bb5f70c236e1571f1895a000c&chksm=cfe2f998f648f4627e77bebb02d8d5f6b2d6a559620b9906be8aec6c29ff2a41dba17e7b30c5#rd)

  

中高频策略回测相比于低频策略回测，存在两个新的挑战。首先，数据量增加了几个数量级，无论数据查询或者计算都对性能有更加苛刻的要求。其次，在中高频策略回测中，并不能简单的假设每个订单以当前价格或日终价格全部成交，需要一个模拟撮合引擎来模拟实际的交易过程，例如考虑订单能否成交、成交价格、成交量以及市场冲击等因素。DolphinDB 基于其高性能的分布式存储和计算架构，实现了行情回放、模拟撮合引擎和事件型中高频回测引擎三大核心组件，支持通过 DolphinScript、Python 或 C++语言完成中高频策略的研发和测试，提供了一个性能优异且易扩展的中高频量化交易策略回测解决方案。

![](assets/001.png)

**核心组件:**

-   **数据回放模块:**
    

-   支持单表和多表回放，可按时间顺序回放历史行情数据。
    
-   提供多种回放速率控制和数据筛选功能。
    
-   支持 C++ SDK、Python SDK 和 Swordfish 等实现方式，满足不同开发需求。
    

-   **模拟撮合引擎:**
    

-   模拟真实交易环境，提供订单撮合功能，支持多种撮合模式和配置。
    
-   可模拟沪深交易所 Level-2 逐笔和快照行情，以及期货、期权、数字货币等标的。
    

-   **中高频回测引擎:**
    

-   支持多种行情类型和策略触发机制，提供全面的回测结果信息。
    
-   支持用户使用 DolphinScript、Python 或 C++ 编写自定义策略。
    

**优势:**

-   性能优异，可满足中高频策略对低延时和高性能的要求。
    
-   一站式解决方案，简化回测平台搭建流程。
    
-   模块化设计，易于与外部系统集成。
    
-   支持多种编程语言，满足不同用户需求。
    

# 说明

本篇主要是介绍使用DolphinDB的Backtest插件进行回测。

第一部分使用以backtrader为基线，用于对比;

第二部分使用backtest进行回测;

由于大部分量化均在python环境下，所以这里我提供了一个在python下调用DolphinDB回测代码的方法。这里仅回测策略使用原生DolphinDB语法构建。案例中使用的交易信号为[QRS](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)

```
import sysfrom pathlib import Pathsys.path.append(str(Path().cwd().parents[1]))from typing import Dict, List, Tuple, Unionimport pandas as pdimport empyrical as ep
```

# 设置参数

```
START_DT: str = "2005-01-01"END_DT: str = "2023-12-31"# 回归计算窗口REGRESSION_WINDOW: int = 18# 标准化的计算窗口ZSCORE_WINDOW: int = 600# 设置佣金及印花税COMMISSiON: Dict = {    "commission": 0.0003,  # 佣金    "stamp_duty": 0.0001,  # 印花税    "slippage_perc": None,  # 滑点}# 预留的资金比例RESERVECASHRATIO: Dict = {"reserveCashRatio": 0.05}
```

# Backtrader框架回测

**backtrader\_utils**

-   `bt_template`:**run\_template\_strategy**用于运行backtrader策略模板;
    
-   `datafeed`:**DailyOHLCVUSLFeed**用于加载数据所需字段为datetime,open,high,low,close,volume,upperbound(信号上轨),signal(信号),lowerbound(信号下轨);
    
-   `engine`:二次封装的**BackTesting**类用回测.
    

**strategy**

-   `rsrs_strategy`:QRS策略
    

```
from backtrader_utils import run_template_strategyfrom strategy import RSRSStrategyfrom SignalMaker.qrs import QRSCreator
```

```
# 读取数据daily: pd.DataFrame = pd.read_parquet("data/daily.parquet")
```

```
# 查看数据结构daily.head()
```

![](assets/002.png)

```
# 读取数据daily: pd.DataFrame = pd.read_parquet("data/daily.parquet")target_code: str = "000300.SH"fields: List[str] = ["code", "open", "high", "low", "close", "volume"]hs300_df: pd.DataFrame = daily.query("code==@target_code")[fields].copy()pivot_table: pd.DataFrame = pd.pivot_table(    daily, index="trade_date", columns="code", values=fields[1:5])high_df: pd.DataFrame = pivot_table["high"]low_df: pd.DataFrame = pivot_table["low"]# 计算QRS信号qrs: QRSCreator = QRSCreator(low_df[target_code], high_df[target_code])single_qrs: pd.DataFrame = qrs.fit(    REGRESSION_WINDOW, ZSCORE_WINDOW, n=2, adjust_regulation=True)# 将QRS信号加入到数据中hs300_df["signal"] = single_qrs["Signal"]# 设置上下界hs300_df["upperbound"] = 0.7hs300_df["lowerbound"] = -0.7
```

## 运行回测

设置回测参数

```
strat = run_template_strategy(    hs300_df,    target_code,    RSRSStrategy,    strategy_kwargs=RESERVECASHRATIO,    commission_kwargs=COMMISSiON)
```

## Backtrader运行时间

可以看到backtrade回测时间大概为997 ms ± 8.87 ms

```
%timeit run_template_strategy(hs300_df,target_code,RSRSStrategy,strategy_kwargs=RESERVECASHRATIO,commission_kwargs=COMMISSiON)
```

```
997 ms ± 8.87 ms per loop (mean ± std. dev. of 7 runs, 1 loop each)
```

```
# 回测净值netValue: pd.Series = ep.cum_returns(    pd.Series(strat.analyzers.getbyname("time_return").get_analysis()).loc[        single_qrs.index.min() :    ],    1,)netValue.plot(figsize=(16, 4), title="Net Value", color="red").axhline(    1, color="black", linestyle="--")
```

```
<matplotlib.lines.Line2D at 0x7f1e3756dab0>
```

![](assets/003.png)

```
# 最后一期净值netValue.iloc[-1]
```

```
4.257836183031623
```

# DolphinDB的Backtest插件回测

**ddb\_backtest**

-   `config.py`:连接dolphindDB的配置,需要用改为自己的对应连接参数;
    
-   `qrs_strategy.dos`:dolphinDB回测策略;
    
-   `__init__`:dolphinDB回测所需函数:
    

1.  **set\_user\_config**:用于设置回测配置;
    
2.  **set\_ddb\_strategy**:用于加载`qrs_strategy`策略到对应节点;
    
3.  **load\_data\_to\_ddb**:用于加载回测数据到对应节点;
    
4.  **run\_backtest**:用于运行回测.
    

## backtest策略回调函数说明

打开ddb\_backtest/qrs\_strategy.dos可以看到回测代码。这里简单介绍一下，回测架构。Backtest与joinquant,zipline类似由

-   回测主体:`initialize`,`beforeTrading`,`afterTrading`,`finalize`;
    
-   与回测频率相关:\[`onTick`,`onBar`\];
    
-   与模拟撮合相关:\[`onSnapshot`,`onOrder`,`onTrade`\]
    

函数构成，其中`initialize`,`beforeTrading`,`afterTrading`用过joinquant回测的应该很熟悉,分别是:初始化函数，开盘前运行策略，收盘后运行策略。`finalize`有点类似于backtrader的`stop`在策略结之前回调一次该函数。第一个方框号中的\[`onTick`,`onBar`\]可以简单理解为不同的周期，其中最细颗粒度便是`onTick`,分钟及日度使用`onBar`。第二个方框号中的\[`onSnapshot`,`onOrder`,`onTrade`\]便是是否使用逐笔+快照的方式进行**模拟撮合回测**.

ddb的backtest支持回测的资产类型有：股票\[1\]、期权\[2\]、期货\[3\]、银行间债券\[4\]、数字货币\[5\]

## 配置说明

本次回测使用QRS\[6\]

这里我将日频股票的引擎配置封装在了`set_user_config`中,这里需要提示的是需要的DolphinDB版本为_V3.00.2.1_.这里这要介绍下面几个较为重要的配置参数:

-   dataType:
    

-   逐笔或逐笔+快照:0
    
-   快照:1
    
-   快照+逐笔成交明细:2
    
-   分钟频率:3
    
-   日频:4
    
-   逐笔（宽表）:5
    
-   逐笔+快照（宽表）:6
    

这里`set_user_config`中的dataType参数固定设置为4,不同的dataType参数对应不同的数据结构。日频数据结构\[7\]参考文档。数据的结构处理在`load_data_to_ddb`函数中进行了处理。

-   context:该参数可以将配置参数传入到`initialize`函数中(仅V3.00.2.1及以以上可以);
    
-   matchingMode:
    

-   1:以收盘价撮合订单
    
-   2:以开盘价撮合订单
    
-   3:以委托价格成交(当前版本日频貌似有点小问题)
    

当前版本设置matchingMode时需要与策略模板中设置的买卖价格对应,在策略模板中设置的参考价格为Open所以这里需要设置撮合模式为2(开盘撮合,否则价格相差较大无法成功下单买入)。

## 回测逻辑说明

使用QRS信号进行买卖，T日信号将会在T+1日以开盘价撮合买入。当前仅支持单股回测。

```
import dolphindb as ddbfrom ddb_backtest import run_backtest, set_ddb_strategy, set_user_configfrom ddb_backtest.config import Config  # dolphindb连接配置
```

## 创建ddb连接

```
session: ddb.session = ddb.session()# 加载连接配置session.connect(**Config)
```

```
True
```

## 运行回测

设置回测参数

```
# step1 设置回测策略set_ddb_strategy(session)# step2 设置回测参数## 1.设置QRS计算参数## 2.设置回测区间set_user_config(    session,    codes=target_code, # 回测标的    start_dt=START_DT,  # 回测开始时间    end_dt=END_DT, # 回测结束时间    data=daily, # 数据    cash=1e6,  # 初始资金    regressionPeriod=REGRESSION_WINDOW, # 回归窗口    zscorePeriod=ZSCORE_WINDOW, # 标准化窗口    commission=COMMISSiON["commission"], # 佣金    tax=COMMISSiON["stamp_duty"], # 印花税    reserveCashRatio=RESERVECASHRATIO["reserveCashRatio"], # 预留资金比例    orderBookMatchingRatio=1.0, # 撮合模式)# step3 运行回测## 设置数据区间与回测区间保持一致## 上传数据run_backtest(session)
```

策略上传成功!  

回测配置设置成功!  

回测配置信息如下:  

{  
    'matchingMode': 2,  
    'msgAsTable': False,  
    'tax': 0.0001,  
    'context': {  
        'reserveCashRatio': 0.05,  
        'show\_log': True,  
        'holdNum': 1,  
        'zscorePeriod': 600,  
        'regressionPeriod': 18  
    },  
    'commission': 0.0003,  
    'cash': 1000000.0,  
    'strategyGroup': 'stock',  
    'orderBookMatchingRatio': 1.0,  
    'dataType': 4,  
    'endDate': numpy.datetime64('2023-12-31'),  
    'frequency': 0,  
    'startDate': numpy.datetime64('2005-01-01')  
}  

加载数据到DolphinDB中...  

DolphinDB的Backtest回测时间大概在273 ms ± 6.4 ms

```
# 设置show_log不输出日志set_user_config(    session,    codes=target_code,    start_dt=START_DT,    end_dt=END_DT,    data=daily,    cash=1e6,    show_log=False,    regressionPeriod=REGRESSION_WINDOW,    zscorePeriod=ZSCORE_WINDOW,    commission=COMMISSiON["commission"],    tax=COMMISSiON["stamp_duty"],    reserveCashRatio=RESERVECASHRATIO["reserveCashRatio"],    orderBookMatchingRatio=1.0,)
```

回测配置设置成功!  

回测配置信息如下:  

加载数据到DolphinDB中...  

数据上传成功  

数据加载成功!  

```
# 测试运行时间%timeit run_backtest(session)
```

```
Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 264.272 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 264.874 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 267.029 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 264.911 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 268.705 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 272.218 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 284.558 msDone!Begin backtest!QRS参数设置:regressionPeriod:18;zscorePeriod:600Time elapsed: 267.399 msDone!273 ms ± 6.4 ms per loop (mean ± std. dev. of 7 runs, 1 loop each)
```

```
# 获取每日持仓数据daily_pnl: pd.DataFrame = session.run("Backtest::getDailyTotalPortfolios(engine)")daily_pnl.set_index("tradeDate")["netValue"].loc[single_qrs.index.min() :].plot(    figsize=(18, 4), color="r").axhline(1, color="black", alpha=0.4)
```

```
<matplotlib.lines.Line2D at 0x7f1e3756e0b0>
```

![](assets/004.png)

```
daily_pnl.iloc[-1]['netValue']
```

```
3.5840676209500133
```

```
# 获取交易明细表session.run("Backtest::getTradeDetails(engine)")
```

![](assets/005.png)

`# 获取策略的收益概述   session.run("Backtest::getReturnSummary(engine)")   `

![](assets/006.png)

  

参考资料

\[1\]

股票: _https://docs.dolphindb.cn/zh/plugins/backtest/stock.html_

\[2\]

期权: _https://docs.dolphindb.cn/zh/plugins/backtest/option.html_

\[3\]

期货: _https://docs.dolphindb.cn/zh/plugins/backtest/futures.html_

\[4\]

银行间债券: _https://docs.dolphindb.cn/zh/plugins/backtest/interbank\_bonds.html_

\[5\]

数字货币: _https://docs.dolphindb.cn/zh/plugins/backtest/digital\_currency.html_

\[6\]

QRS: _https://mp.weixin.qq.com/s/QgoKD2Zykb05s9vCFzVIVQ_

\[7\]

日频数据结构: _https://docs.dolphindb.cn/zh/plugins/backtest/stock.html#id-%E8%82%A1%E7%A5%A8-%E8%A1%8C%E6%83%85%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E8%AF%B4%E6%98%8E.4_

  

  

完整代码见星球，QuantML星球内有各类丰富的量化资源，包括上百篇论文代码，QuantML-Qlib框架，研报复现项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

  

![](assets/007.jpg)