# Qlib学习分析（六）：代码示例

FinTechHi FinTechHi 2023-07-29 23:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483857&idx=1&sn=d3859ca22c03c60fa57c649547db2559&chksm=fb06cecf8c857d39813b79eba3e8a90a41e0e3fc7e1551a2ca9e274e4a2b633aba8a9a265361#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483857&idx=1&sn=d3859ca22c03c60fa57c649547db2559&chksm=fb06cecf8c857d39813b79eba3e8a90a41e0e3fc7e1551a2ca9e274e4a2b633aba8a9a265361#rd)

## 一、数据相关

下载数据：

```
# download 1dpython scripts/get_data.py qlib_data --target_dir ~/.qlib/qlib_data/cn_data --region cn# download 1minpython scripts/get_data.py qlib_data --target_dir ~/.qlib/qlib_data/qlib_cn_1min --region cn --interval 1min#download uspython scripts/get_data.py qlib_data --target_dir ~/.qlib/qlib_data/us_data --region us
```

下载演示数据：

```
#1day datapython scripts/get_data.py download_data --file_name csv_data_cn.zip --target_dir ~/.qlib/csv_data/cn_data#1min datapython scripts/data_collector/yahoo/collector.py download_data --source_dir ~/.qlib/stock_data/source/cn_1min --region CN --start 2021-05-20 --end 2021-05-23 --delay 0.1 --interval 1min --limit_nums 10
```

手工更新数据：

```
python scripts/data_collector/yahoo/collector.py update_data_to_bin --qlib_data_1d_dir <user data dir> --trading_date <start date> --end_date <end date>
```

自动每日更新数据：

```
#use crontab： crontab -e#script: https://github.com/microsoft/qlib/tree/main/scripts/data_collector/yahoo#Automatic-update-of-daily-frequency-data* * * * 1-5 python <script path> update_data_to_bin --qlib_data_1d_dir <user data dir>
```

CSV格式转换为Qlib格式

```
#csv to qlibscripts/dump_bin.py Qlib
```

本地个人专属数据，按要求以CSV格式准备后进行转换：

```
#CSV文件以股票代码命名，如：SH600000.csv、AAPL.csv（不区分大小写）#CSV文件包含股票名称列，用户在转储数据时必须指定列名，–include_fields 的参数应与 CSV 文件的列名相对应。提供的数据集列名称应至少包括open、close、high、low、volume、factor。#其中factor为复权因子：factor = adjusted_price / original_price#CSV文件必须包含日期列，转储数据时，用户必须指定日期列名称#假设CSV格式数据目录：~/.qlib/csv_data/my_data，转换后目录： ~/.qlib/qlib_data/my_data python scripts/dump_bin.py dump_all --csv_path  ~/.qlib/csv_data/my_data --qlib_dir ~/.qlib/qlib_data/my_data --include_fields open,close,high,low,volume,factor
```

在调用其他 API 之前初始化 Qlib：在 python 中运行以下代码：

```
import qlib# region in [REG_CN, REG_US]from qlib.constant import REG_CN# target_dirprovider_uri = "~/.qlib/qlib_data/cn_data" #init cn dataqlib.init(provider_uri=provider_uri, region=REG_CN)#init us dataqlib.init(provider_uri='~/.qlib/qlib_data/us_data', region=REG_US)
```

加载给定时间范围和频率的交易日历：

```
from qlib.data import DD.calendar(start_time='2010-01-01', end_time='2017-12-31', freq='day')[:2]
```

将给定的市场名称解析为股票池配置：

```
from qlib.data import DD.instruments(market='all')
```

在给定时间范围内加载特定股票池：

```
from qlib.data import Dinstruments = D.instruments(market='csi300')D.list_instruments(instruments=instruments, start_time='2010-01-01', end_time='2017-12-31', as_list=True)[:6]
```

`Qlib`提供了NameDFilter和ExpressionDFilter两个数据过滤器，其中NameDFilter按照正则表达式编写，ExpressionDFilter则按具体的字段设置动态条件，主要示例如下：

-   基本功能过滤器：rule\_expression = '$close/$open>5'
    
-   横截面特征过滤器 ： rule\_expression = '$rank（$close）<10'
    
-   时序特征过滤器：rule\_expression = '$Ref（$close， 3）>100'
    

按股票代码设置过滤条件从指定股票池加载数据：

```
from qlib.data import Dfrom qlib.data.filter import NameDFilternameDFilter = NameDFilter(name_rule_re='SH[0-9]{4}55')instruments = D.instruments(market='csi300', filter_pipe=[nameDFilter])D.list_instruments(instruments=instruments, start_time='2015-01-01', end_time='2016-02-15', as_list=True)
```

按条件表达式方式过滤条件从指定股票池加载数据：

```
from qlib.data import Dfrom qlib.data.filter import ExpressionDFilterexpressionDFilter = ExpressionDFilter(rule_expression='$close>20')instruments = D.instruments(market='csi300', filter_pipe=[expressionDFilter])D.list_instruments(instruments=instruments, start_time='2015-01-01', end_time='2016-02-15', as_list=True)
```

按自定义特征获取符合条件的数据：

```
from qlib.data import Dinstruments = ['SH600000']fields = ['$close', '$volume', 'Ref($close, 1)', 'Mean($close, 3)', '$high-$low']D.features(instruments, fields, start_time='2010-01-01', end_time='2017-12-31', freq='day').head().to_string()
```

按NameDFilter和ExpressionDFilter过滤器且输出自定义特征数据：

```
from qlib.data import Dfrom qlib.data.filter import NameDFilter, ExpressionDFilternameDFilter = NameDFilter(name_rule_re='SH[0-9]{4}55')expressionDFilter = ExpressionDFilter(rule_expression='$close>Ref($close,1)')instruments = D.instruments(market='csi300', filter_pipe=[nameDFilter, expressionDFilter])fields = ['$close', '$volume', 'Ref($close, 1)', 'Mean($close, 3)', '$high-$low']D.features(instruments, fields, start_time='2010-01-01', end_time='2017-12-31', freq='day').head().to_string()
```

如果表达式过滤条件太长，在代码中看起来不方便，可以使用自定义参数的方式编写：

```
from qlib.data import Ddata = D.features(["sh600519"], ["(($high / $close) + ($open / $close)) * (($high / $close) + ($open / $close)) / (($high / $close) + ($open / $close))"], start_time="20200101")
```

拆解后编写方式如下：

```
from qlib.data.ops import *f1 = Feature("high") / Feature("close")f2 = Feature("open") / Feature("close")f3 = f1 + f2f4 = f3 * f3 / f3data = D.features(["sh600519"], [f4], start_time="20200101")data.head()
```

关于数据缓存：

> 启用缓存后，qlib 数据服务器将始终缓存所请求的股票池和字段的数据，第一次处理请求可能需要比没有缓存的时间更长的时间。但是在第一次之后，具有相同库存池和字段的请求将命中缓存并更快地处理，即使请求的时间段发生变化。  
> 在客户端调用D.features()时，使用参数 disk\_cache=0 跳过数据集缓存，使用disk\_cache=1生成和使用数据集缓存。此外，在服务器上调用时，用户可以使用disk\_cache=2更新数据集缓存。

## 二、模型

Qlib支持的模型如下：

  

![](assets/001.png)

  

可以按照以下步骤集成自己的自定义模型。

-   定义一个自定义模型类，它应该是 qlib.model.base.Model 的子类。
    
-   编写描述自定义模型的路径和参数的配置文件。
    
-   测试自定义模型。
    

### 1、自定义模型类

1）重写\_\_init\_\_方法

```
def __init__(self, loss='mse', **kwargs):    if loss not in {'mse', 'binary'}:        raise NotImplementedError    self._scorer = mean_squared_error if loss == 'mse' else roc_auc_score    self._params.update(objective=loss, **kwargs)    self._model = None
```

2）重写fit()

```
#Qlib调用 FIT 方法来训练模型,def fit(self, dataset: DatasetH, num_boost_round = 1000, **kwargs):    # prepare dataset for lgb training and evaluation    df_train, df_valid = dataset.prepare(        ["train", "valid"], col_set=["feature", "label"], data_key=DataHandlerLP.DK_L    )    x_train, y_train = df_train["feature"], df_train["label"]    x_valid, y_valid = df_valid["feature"], df_valid["label"]    # Lightgbm need 1D array as its label    if y_train.values.ndim == 2 and y_train.values.shape[1] == 1:        y_train, y_valid = np.squeeze(y_train.values), np.squeeze(y_valid.values)    else:        raise ValueError("LightGBM doesn't support multi-label training")    dtrain = lgb.Dataset(x_train.values, label=y_train)    dvalid = lgb.Dataset(x_valid.values, label=y_valid)    # fit the model    self.model = lgb.train(        self.params,        dtrain,        num_boost_round=num_boost_round,        valid_sets=[dtrain, dvalid],        valid_names=["train", "valid"],        early_stopping_rounds=early_stopping_rounds,        verbose_eval=verbose_eval,        evals_result=evals_result,        **kwargs    )
```

3)重写预测方法

```
def predict(self, dataset: DatasetH, **kwargs)-> pandas.Series:    if self.model is None:        raise ValueError("model is not fitted yet!")    x_test = dataset.prepare("test", col_set="feature", data_key=DataHandlerLP.DK_I)    return pd.Series(self.model.predict(x_test.values), index=x_test.index)
```

4)覆盖微调方法（可选）

```
def finetune(self, dataset: DatasetH, num_boost_round=10, verbose_eval=20):    # Based on existing model and finetune by train more rounds    dtrain, _ = self._prepare_data(dataset)    self.model = lgb.train(        self.params,        dtrain,        num_boost_round=num_boost_round,        init_model=self.model,        valid_sets=[dtrain],        valid_names=["train"],        verbose_eval=verbose_eval,    )
```

### 2、配置文件

```
model:    class: LGBModel    module_path: qlib.contrib.model.gbdt    args:        loss: mse        colsample_bytree: 0.8879        learning_rate: 0.0421        subsample: 0.8789        lambda_l1: 205.6999        lambda_l2: 580.9768        max_depth: 8        num_leaves: 210        num_threads: 20
```

### 3、模型测试

```
cd examples  # Avoid running program under the directory contains `qlib`qrun benchmarks/LightGBM/workflow_config_lightgbm.yaml
```

从数据集中检索x\_train、y\_train和w\_train：

```
# get features and labelsdf_train, df_valid = dataset.prepare(    ["train", "valid"], col_set=["feature", "label"], data_key=DataHandlerLP.DK_L)x_train, y_train = df_train["feature"], df_train["label"]x_valid, y_valid = df_valid["feature"], df_valid["label"]# get weightstry:    wdf_train, wdf_valid = dataset.prepare(["train", "valid"], col_set=["weight"],                                           data_key=DataHandlerLP.DK_L)    w_train, w_valid = wdf_train["weight"], wdf_valid["weight"]except KeyError as e:    w_train = pd.DataFrame(np.ones_like(y_train.values), index=y_train.index)    w_valid = pd.DataFrame(np.ones_like(y_valid.values), index=y_valid.index)
```

获取预测分数pred\_score：

```
from qlib.contrib.model.gbdt import LGBModelfrom qlib.contrib.data.handler import Alpha158from qlib.utils import init_instance_by_config, flatten_dictfrom qlib.workflow import Rfrom qlib.workflow.record_temp import SignalRecord, PortAnaRecordmarket = "csi300"benchmark = "SH000300"data_handler_config = {    "start_time": "2008-01-01",    "end_time": "2020-08-01",    "fit_start_time": "2008-01-01",    "fit_end_time": "2014-12-31",    "instruments": market,}task = {    "model": {        "class": "LGBModel",        "module_path": "qlib.contrib.model.gbdt",        "kwargs": {            "loss": "mse",            "colsample_bytree": 0.8879,            "learning_rate": 0.0421,            "subsample": 0.8789,            "lambda_l1": 205.6999,            "lambda_l2": 580.9768,            "max_depth": 8,            "num_leaves": 210,            "num_threads": 20,        },    },    "dataset": {        "class": "DatasetH",        "module_path": "qlib.data.dataset",        "kwargs": {            "handler": {                "class": "Alpha158",                "module_path": "qlib.contrib.data.handler",                "kwargs": data_handler_config,            },            "segments": {                "train": ("2008-01-01", "2014-12-31"),                "valid": ("2015-01-01", "2016-12-31"),                "test": ("2017-01-01", "2020-08-01"),            },        },    },}# model initiaitonmodel = init_instance_by_config(task["model"])dataset = init_instance_by_config(task["dataset"])# start expwith R.start(experiment_name="workflow"):    # train    R.log_params(**flatten_dict(task))    model.fit(dataset)    # prediction    recorder = R.get_recorder()    sr = SignalRecord(model, dataset, recorder)    sr.generate()
```

典型的量化研究中的工作流程：

```
qlib_init:    provider_uri: "~/.qlib/qlib_data/cn_data"    region: cnmarket: &market csi300benchmark: &benchmark SH000300data_handler_config: &data_handler_config    start_time: 2008-01-01    end_time: 2020-08-01    fit_start_time: 2008-01-01    fit_end_time: 2014-12-31    instruments: *marketport_analysis_config: &port_analysis_config    strategy:        class: TopkDropoutStrategy        module_path: qlib.contrib.strategy.strategy        kwargs:            topk: 50            n_drop: 5            signal: <PRED>    backtest:        limit_threshold: 0.095        account: 100000000        benchmark: *benchmark        deal_price: close        open_cost: 0.0005        close_cost: 0.0015        min_cost: 5task:    model:        class: LGBModel        module_path: qlib.contrib.model.gbdt        kwargs:            loss: mse            colsample_bytree: 0.8879            learning_rate: 0.0421            subsample: 0.8789            lambda_l1: 205.6999            lambda_l2: 580.9768            max_depth: 8            num_leaves: 210            num_threads: 20    dataset:        class: DatasetH        module_path: qlib.data.dataset        kwargs:            handler:                class: Alpha158                module_path: qlib.contrib.data.handler                kwargs: *data_handler_config            segments:                train: [2008-01-01, 2014-12-31]                valid: [2015-01-01, 2016-12-31]                test: [2017-01-01, 2020-08-01]    record:        - class: SignalRecord          module_path: qlib.workflow.record_temp          kwargs: {}        - class: PortAnaRecord          module_path: qlib.workflow.record_temp          kwargs:              config: *port_analysis_config
```

将上述配置保存到configuration.yaml后，使用如下命令启动工作流：

```
qrun configuration.yaml
```

策略回测：

```
from pprint import pprintimport qlibimport pandas as pdfrom qlib.utils.time import Freqfrom qlib.utils import flatten_dictfrom qlib.contrib.evaluate import backtest_dailyfrom qlib.contrib.evaluate import risk_analysisfrom qlib.contrib.strategy import TopkDropoutStrategy# init qlibqlib.init(provider_uri=<qlib data dir>)CSI300_BENCH = "SH000300"STRATEGY_CONFIG = {    "topk": 50,    "n_drop": 5,    # pred_score, pd.Series    "signal": pred_score,}strategy_obj = TopkDropoutStrategy(**STRATEGY_CONFIG)report_normal, positions_normal = backtest_daily(    start_time="2017-01-01", end_time="2020-08-01", strategy=strategy_obj)analysis = dict()# default frequency will be daily (i.e. "day")analysis["excess_return_without_cost"] = risk_analysis(report_normal["return"] - report_normal["bench"])analysis["excess_return_with_cost"] = risk_analysis(report_normal["return"] - report_normal["bench"] - report_normal["cost"])analysis_df = pd.concat(analysis)  # type: pd.DataFramepprint(analysis_df)
```