# Qlib学习分析（四）：数据处理与准备因子模型与策略构建

FinTechHi FinTechHi 2023-07-25 20:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483833&idx=1&sn=45b59b5c7bcb370db11c989de177b69b&chksm=fb6ade4caa93343e2d81b0e1d112c83983561a930a2de170adcd5362590e4cb4542322a1294f#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483833&idx=1&sn=45b59b5c7bcb370db11c989de177b69b&chksm=fb6ade4caa93343e2d81b0e1d112c83983561a930a2de170adcd5362590e4cb4542322a1294f#rd)

## 第四章.因子模型与策略构建

因子模型是量化投资中一种重要的研究方法，它通过收集和分析一系列的因子（或特征）来预测资产的未来表现。本节将介绍多因子模型的基本概念和应用，常见的因子计算方法，以及如何构建交易策略规则。

### 4.1数据

1）初始化

在Python中运行Qlib程序前，需要首先初始化运行环境，命令为qlib.init，代码如下：

```
#初始化数据环境import qlibqlib.init(provider_uri='~E:/qlib/qlib_data/cn_data')
```

2）获取交易日期和全部股票代码

```
from qlib.data import D#1.初始化并获取日历data_uri = 'E:/qlib/qlib_data/cn_data'qlib.init(provider_uri=data_uri, region=REG_CN)#GetData().qlib_data(target_dir=data_uri, region=REG_CN)tradedate = D.calendar(start_time='2020-01-01',end_time='2020-11-30',freq='day')print(tradedate[:5])#2.获取所有证券代码instruments = D.instruments(market='all')stock_list = D.list_instruments(instruments=instruments, start_time='2020-07-01', end_time='2020-11-30', as_list=True)#展示后5个股票代码print(stock_list[-5:])
```

终于跑通了，如下图：

![](assets/001.png)

3）获取字段数据

调用qlib.data.features模块可以获取指定股票指定日期指定字段数据，例如下图展示获取惠云钛业（SZ300891）在2020-01-01~2020-11-30日频后复权收盘价和成交量。

```
#3.获取指定股票指定日期指定字段数据features_df = D.features(instruments=['SZ300891'], fields=['$close',' $volume'], start_time='2020-01-01', end_time='2020-11-30', freq='day')print(features_df.head())
```

查询结果如下：

![](assets/002.png)

### 4.2股票池

使用qlib.data.filter.NameDFilter命令进行股票名称静态筛选，参数name\_rule\_re为纳入股票代码的正则表达式，如HK\[0-9!\]表示以HK开头，后续为数字或感叹号的股票代码，感叹号代表目前已退市股票。

其次，使用qlib.data.filter.ExpressionDFilter命令进行股票因子表达式的动态筛选，参数rule\_expression为入选的因子表达式，如$close>=1代表收盘价应大于等于1元。

随后，通过qlib.data.instruments命令的参数filter\_pipe，将两个筛选条件组装到一起，代码如下：

> 不加if \_\_name\_\_=='\_\_main\_\_' ，会报错“RuntimeError: An attempt has been made to start a new process before the current process has finished its bootstrapping phase.”

```
if __name__=='__main__': from qlib.data.filter import NameDFilter, ExpressionDFilter #静态Filter:深交所A股 nameDFilter = NameDFilter(name_rule_re='SZ[0-9!]') # 动态Filter:后复权价格大于等于1元 expressionDFilter = ExpressionDFilter(rule_expression = '$close>=5') #按以上两个过滤条件获取新的股票代码集 instruments = D.instruments(market='all',filter_pipe = [nameDFilter, expressionDFilter]) stock_list = D.list_instruments(instruments = instruments, start_time = '2020-07-01', end_time = '2020-11-30', as_list = True) #展示条件过滤后的5个股票代码 print(stock_list[-5:])
```

执行后过滤的股票代码如下，和上面没过滤的可以对比，发现过滤有效。

![](assets/003.png)

### 4.3因子

Qlib提供Alpha158和Alpha360两类量价因子库，用户也可根据需要自定义因子库。源码位于qlib/contrib/data/handler.py，主要包括两个四个类：

> Alpha360(DataHandlerLP)、Alpha360vwap(Alpha360)  
> Alpha158(DataHandlerLP)、Alpha158vwap(Alpha360)

配置文件对应的代码说明如下：

```
def parse_config_to_fields(config): """create factors from config        config = {            'kbar': {}, # whether to use some hard-code kbar features            'price': { # whether to use raw price features                'windows': [0, 1, 2, 3, 4], # use price at n days ago                'feature': ['OPEN', 'HIGH', 'LOW'] # which price field to use            },            'volume': { # whether to use raw volume features                'windows': [0, 1, 2, 3, 4], # use volume at n days ago            },            'rolling': { # whether to use rolling operator based features                'windows': [5, 10, 20, 30, 60], # rolling windows size                'include': ['ROC', 'MA', 'STD'], # rolling operator to use                #if include is None we will use default operators                'exclude': ['RANK'], # rolling operator not to use            }        }
```

其中参数data\_handler\_config相当于配置文件，字典类型，用来定义完整数据起止日期（start\_time和end\_time），拟合数据起止日期（fit\_start\_time和fit\_end\_time），股票池（instruments）等。

拟合数据起止日期区间应为完整数据起止日期数据的子集。

拟合数据日期（训练和验证集）和余下日期（测试集）在数据预处理的方式上有所不同，将在下章展开讨论。

生成Alpha158因子调用qlib.contrib.data.handler模块下的Alpha158类，具体命令为：

```
from qlib.contrib.data.handler import Alpha158h = Alpha158(**data_handler_config)
```

执行上述指令后，程序将计算从start\_time至end\_time的当期因子值和下期收益，分别作为后续AI模型训练的特征和标签。

代码中使用了两个处理器，infer\_processors用于模型预测，learn\_processors用于模型训练。

```
    infer_processors = check_transform_proc(infer_processors, fit_start_time, fit_end_time)    learn_processors = check_transform_proc(learn_processors, fit_start_time, fit_end_time)
```

计算代码如下：

```
import qlibfrom qlib.contrib.data.handler import Alpha158from qlib.data.dataset import TSDatasetHfrom qlib.contrib.model.pytorch_alstm_ts import ALSTMfrom qlib.tests.data import GetDatafrom qlib.constant import REG_CNfrom qlib.data import Dfrom qlib.contrib.data.handler import Alphal58instruments = D.instruments(market='all') stock_list = D.list_instruments(instruments=instruments, start_time='2020-01-01', end_time='2020-11-30', as_list=True) # 设置日期、股票池等参数 data_handler_config = { "start_time":"2020-01-01", "end_time":"2020-11-30", "fit_start_time":"2020-01-01", "fit_end time":"2020-06-30", "instruments":instruments        } h =Alpha158(**data_handler_config) # 获取列名(因子名称) print(h.get_cols0())
```

以上代码运行时间统计如下：

```
Time cost: 0.850s | CSZScoreNorm Done Time cost: 1.507s | fit & process data DoneTime cost: 510.034s | Init data Done
```

大概9分钟左右跑出来158个因子如下：

> \['KMID', 'KLEN', 'KMID2', 'KUP', 'KUP2', 'KLOW', 'KLOW2', 'KSFT', 'KSFT2', 'OPEN0', 'HIGH0', 'LOW0', 'VWAP0', 'ROC5', 'ROC10', 'ROC20', 'ROC30', 'ROC60', 'MA5', 'MA10', 'MA20', 'MA30', 'MA60', 'STD5', 'STD10', 'STD20', 'STD30', 'STD60', 'BETA5', 'BETA10', 'BETA20', 'BETA30', 'BETA60', 'RSQR5', 'RSQR10', 'RSQR20', 'RSQR30', 'RSQR60', 'RESI5', 'RESI10', 'RESI20', 'RESI30', 'RESI60', 'MAX5', 'MAX10', 'MAX20', 'MAX30', 'MAX60', 'MIN5', 'MIN10', 'MIN20', 'MIN30', 'MIN60', 'QTLU5', 'QTLU10', 'QTLU20', 'QTLU30', 'QTLU60', 'QTLD5', 'QTLD10', 'QTLD20', 'QTLD30', 'QTLD60', 'RANK5', 'RANK10', 'RANK20', 'RANK30', 'RANK60', 'RSV5', 'RSV10', 'RSV20', 'RSV30', 'RSV60', 'IMAX5', 'IMAX10', 'IMAX20', 'IMAX30', 'IMAX60', 'IMIN5', 'IMIN10', 'IMIN20', 'IMIN30', 'IMIN60', 'IMXD5', 'IMXD10', 'IMXD20', 'IMXD30', 'IMXD60', 'CORR5', 'CORR10', 'CORR20', 'CORR30', 'CORR60', 'CORD5', 'CORD10', 'CORD20', 'CORD30', 'CORD60', 'CNTP5', 'CNTP10', 'CNTP20', 'CNTP30', 'CNTP60', 'CNTN5', 'CNTN10', 'CNTN20', 'CNTN30', 'CNTN60', 'CNTD5', 'CNTD10', 'CNTD20', 'CNTD30', 'CNTD60', 'SUMP5', 'SUMP10', 'SUMP20', 'SUMP30', 'SUMP60', 'SUMN5', 'SUMN10', 'SUMN20', 'SUMN30', 'SUMN60', 'SUMD5', 'SUMD10', 'SUMD20', 'SUMD30', 'SUMD60', 'VMA5', 'VMA10', 'VMA20', 'VMA30', 'VMA60', 'VSTD5', 'VSTD10', 'VSTD20', 'VSTD30', 'VSTD60', 'WVMA5', 'WVMA10', 'WVMA20', 'WVMA30', 'WVMA60', 'VSUMP5', 'VSUMP10', 'VSUMP20', 'VSUMP30', 'VSUMP60', 'VSUMN5', 'VSUMN10', 'VSUMN20', 'VSUMN30', 'VSUMN60', 'VSUMD5', 'VSUMD10', 'VSUMD20', 'VSUMD30', 'VSUMD60', 'LABEL0'\]

其中因子对应的算子计算公式在handler.py中可以看到：

```
def parse_config_to_fields(config): """create factors from config        config = {            'kbar': {}, # whether to use some hard-code kbar features            'price': { # whether to use raw price features                'windows': [0, 1, 2, 3, 4], # use price at n days ago                'feature': ['OPEN', 'HIGH', 'LOW'] # which price field to use            },            'volume': { # whether to use raw volume features                'windows': [0, 1, 2, 3, 4], # use volume at n days ago            },            'rolling': { # whether to use rolling operator based features                'windows': [5, 10, 20, 30, 60], # rolling windows size                'include': ['ROC', 'MA', 'STD'], # rolling operator to use                #if include is None we will use default operators                'exclude': ['RANK'], # rolling operator not to use            }        }        """ fields = [] names = [] if "kbar" in config: fields += [ "($close-$open)/$open", "($high-$low)/$open", "($close-$open)/($high-$low+1e-12)", "($high-Greater($open, $close))/$open", "($high-Greater($open, $close))/($high-$low+1e-12)", "(Less($open, $close)-$low)/$open", "(Less($open, $close)-$low)/($high-$low+1e-12)", "(2*$close-$high-$low)/$open", "(2*$close-$high-$low)/($high-$low+1e-12)",            ] names += [ "KMID", "KLEN", "KMID2", "KUP", "KUP2", "KLOW", "KLOW2", "KSFT", "KSFT2",            ] if "price" in config: windows = config["price"].get("windows", range(5)) feature = config["price"].get("feature", ["OPEN", "HIGH", "LOW", "CLOSE", "VWAP"]) for field in feature: field = field.lower() fields += ["Ref($%s, %d)/$close" % (field, d) if d != 0 else "$%s/$close" % field for d in windows] names += [field.upper() + str(d) for d in windows] if "volume" in config: windows = config["volume"].get("windows", range(5)) fields += ["Ref($volume, %d)/($volume+1e-12)" % d if d != 0 else "$volume/($volume+1e-12)" for d in windows] names += ["VOLUME" + str(d) for d in windows] if "rolling" in config: windows = config["rolling"].get("windows", [5, 10, 20, 30, 60]) include = config["rolling"].get("include", None) exclude = config["rolling"].get("exclude", []) # `exclude` in dataset config unnecessary filed # `include` in dataset config necessary field def use(x): return x not in exclude and (include is None or x in include) # Some factor ref: https://guorn.com/static/upload/file/3/134065454575605.pdf if use("ROC"): # https://www.investopedia.com/terms/r/rateofchange.asp # Rate of change, the price change in the past d days, divided by latest close price to remove unit fields += ["Ref($close, %d)/$close" % d for d in windows] names += ["ROC%d" % d for d in windows] if use("MA"): # https://www.investopedia.com/ask/answers/071414/whats-difference-between-moving-average-and-weighted-moving-average.asp # Simple Moving Average, the simple moving average in the past d days, divided by latest close price to remove unit fields += ["Mean($close, %d)/$close" % d for d in windows] names += ["MA%d" % d for d in windows] if use("STD"): # The standard diviation of close price for the past d days, divided by latest close price to remove unit fields += ["Std($close, %d)/$close" % d for d in windows] names += ["STD%d" % d for d in windows] if use("BETA"): # The rate of close price change in the past d days, divided by latest close price to remove unit # For example, price increase 10 dollar per day in the past d days, then Slope will be 10. fields += ["Slope($close, %d)/$close" % d for d in windows] names += ["BETA%d" % d for d in windows] if use("RSQR"): # The R-sqaure value of linear regression for the past d days, represent the trend linear fields += ["Rsquare($close, %d)" % d for d in windows] names += ["RSQR%d" % d for d in windows] if use("RESI"): # The redisdual for linear regression for the past d days, represent the trend linearity for past d days. fields += ["Resi($close, %d)/$close" % d for d in windows] names += ["RESI%d" % d for d in windows] if use("MAX"): # The max price for past d days, divided by latest close price to remove unit fields += ["Max($high, %d)/$close" % d for d in windows] names += ["MAX%d" % d for d in windows] if use("LOW"): # The low price for past d days, divided by latest close price to remove unit fields += ["Min($low, %d)/$close" % d for d in windows] names += ["MIN%d" % d for d in windows] if use("QTLU"): # The 80% quantile of past d day's close price, divided by latest close price to remove unit # Used with MIN and MAX fields += ["Quantile($close, %d, 0.8)/$close" % d for d in windows] names += ["QTLU%d" % d for d in windows] if use("QTLD"): # The 20% quantile of past d day's close price, divided by latest close price to remove unit fields += ["Quantile($close, %d, 0.2)/$close" % d for d in windows] names += ["QTLD%d" % d for d in windows] if use("RANK"): # Get the percentile of current close price in past d day's close price. # Represent the current price level comparing to past N days, add additional information to moving average. fields += ["Rank($close, %d)" % d for d in windows] names += ["RANK%d" % d for d in windows] if use("RSV"): # Represent the price position between upper and lower resistent price for past d days. fields += ["($close-Min($low, %d))/(Max($high, %d)-Min($low, %d)+1e-12)" % (d, d, d) for d in windows] names += ["RSV%d" % d for d in windows] if use("IMAX"): # The number of days between current date and previous highest price date. # Part of Aroon Indicator https://www.investopedia.com/terms/a/aroon.asp # The indicator measures the time between highs and the time between lows over a time period. # The idea is that strong uptrends will regularly see new highs, and strong downtrends will regularly see new lows. fields += ["IdxMax($high, %d)/%d" % (d, d) for d in windows] names += ["IMAX%d" % d for d in windows] if use("IMIN"): # The number of days between current date and previous lowest price date. # Part of Aroon Indicator https://www.investopedia.com/terms/a/aroon.asp # The indicator measures the time between highs and the time between lows over a time period. # The idea is that strong uptrends will regularly see new highs, and strong downtrends will regularly see new lows. fields += ["IdxMin($low, %d)/%d" % (d, d) for d in windows] names += ["IMIN%d" % d for d in windows] if use("IMXD"): # The time period between previous lowest-price date occur after highest price date. # Large value suggest downward momemtum. fields += ["(IdxMax($high, %d)-IdxMin($low, %d))/%d" % (d, d, d) for d in windows] names += ["IMXD%d" % d for d in windows] if use("CORR"): # The correlation between absolute close price and log scaled trading volume fields += ["Corr($close, Log($volume+1), %d)" % d for d in windows] names += ["CORR%d" % d for d in windows] if use("CORD"): # The correlation between price change ratio and volume change ratio fields += ["Corr($close/Ref($close,1), Log($volume/Ref($volume, 1)+1), %d)" % d for d in windows] names += ["CORD%d" % d for d in windows] if use("CNTP"): # The percentage of days in past d days that price go up. fields += ["Mean($close>Ref($close, 1), %d)" % d for d in windows] names += ["CNTP%d" % d for d in windows] if use("CNTN"): # The percentage of days in past d days that price go down. fields += ["Mean($close<Ref($close, 1), %d)" % d for d in windows] names += ["CNTN%d" % d for d in windows] if use("CNTD"): # The diff between past up day and past down day fields += ["Mean($close>Ref($close, 1), %d)-Mean($close<Ref($close, 1), %d)" % (d, d) for d in windows] names += ["CNTD%d" % d for d in windows] if use("SUMP"): # The total gain / the absolute total price changed # Similar to RSI indicator. https://www.investopedia.com/terms/r/rsi.asp fields += [ "Sum(Greater($close-Ref($close, 1), 0), %d)/(Sum(Abs($close-Ref($close, 1)), %d)+1e-12)" % (d, d) for d in windows                ] names += ["SUMP%d" % d for d in windows] if use("SUMN"): # The total lose / the absolute total price changed # Can be derived from SUMP by SUMN = 1 - SUMP # Similar to RSI indicator. https://www.investopedia.com/terms/r/rsi.asp fields += [ "Sum(Greater(Ref($close, 1)-$close, 0), %d)/(Sum(Abs($close-Ref($close, 1)), %d)+1e-12)" % (d, d) for d in windows                ] names += ["SUMN%d" % d for d in windows] if use("SUMD"): # The diff ratio between total gain and total lose # Similar to RSI indicator. https://www.investopedia.com/terms/r/rsi.asp fields += [ "(Sum(Greater($close-Ref($close, 1), 0), %d)-Sum(Greater(Ref($close, 1)-$close, 0), %d))" "/(Sum(Abs($close-Ref($close, 1)), %d)+1e-12)" % (d, d, d) for d in windows                ] names += ["SUMD%d" % d for d in windows] if use("VMA"): # Simple Volume Moving average: https://www.barchart.com/education/technical-indicators/volume_moving_average fields += ["Mean($volume, %d)/($volume+1e-12)" % d for d in windows] names += ["VMA%d" % d for d in windows] if use("VSTD"): # The standard deviation for volume in past d days. fields += ["Std($volume, %d)/($volume+1e-12)" % d for d in windows] names += ["VSTD%d" % d for d in windows] if use("WVMA"): # The volume weighted price change volatility fields += [ "Std(Abs($close/Ref($close, 1)-1)*$volume, %d)/(Mean(Abs($close/Ref($close, 1)-1)*$volume, %d)+1e-12)"                    % (d, d) for d in windows                ] names += ["WVMA%d" % d for d in windows] if use("VSUMP"): # The total volume increase / the absolute total volume changed fields += [ "Sum(Greater($volume-Ref($volume, 1), 0), %d)/(Sum(Abs($volume-Ref($volume, 1)), %d)+1e-12)"                    % (d, d) for d in windows                ] names += ["VSUMP%d" % d for d in windows] if use("VSUMN"): # The total volume increase / the absolute total volume changed # Can be derived from VSUMP by VSUMN = 1 - VSUMP fields += [ "Sum(Greater(Ref($volume, 1)-$volume, 0), %d)/(Sum(Abs($volume-Ref($volume, 1)), %d)+1e-12)"                    % (d, d) for d in windows                ] names += ["VSUMN%d" % d for d in windows] if use("VSUMD"): # The diff ratio between total volume increase and total volume decrease # RSI indicator for volume fields += [ "(Sum(Greater($volume-Ref($volume, 1), 0), %d)-Sum(Greater(Ref($volume, 1)-$volume, 0), %d))" "/(Sum(Abs($volume-Ref($volume, 1)), %d)+1e-12)" % (d, d, d) for d in windows                ] names += ["VSUMD%d" % d for d in windows] return fields, names
```

通过下面代码获取标签：

#获取T日每只股票的标签数据（收益，及涨幅）

Alpha158\_df\_label = h.fetch(col\_set="label")

print(Alpha158\_df\_label)

默认参数下，股票t日的标签对应t+2日收盘价相对于t+1日收盘价的涨跌幅，相当于t日收盘后发信号，t+1日收盘时刻开仓，t+2日收盘时刻平仓。

如下图，2020年1月2日沪深300的标签值为-0.003778，对应2020年1月6日该股票涨跌幅为-0.3778%（2020年1月4~5日非交易日）。

![](assets/004.png)

通过下面代码可获取T日的特征（因子）值。

#获取T日每只股票的特征(因子值)值

Alpha158\_df\_feature = h.fetch(col\_set="feature")

print(Alpha158\_df\_feature)

默认参数下，股票t日的特征对应t日收盘后计算出的因子值。

![](assets/005.png)

### 4.4模型

直接以qlib/examples/workflow\_by\_code.py这个例子来看。

1、数据准备

```
import qlibimport pandas as pdfrom qlib.constant import REG_CNfrom qlib.utils import exists_qlib_data, init_instance_by_configfrom qlib.workflow import Rfrom qlib.workflow.record_temp import SignalRecord, PortAnaRecordfrom qlib.utils import flatten_dict#1.初始化并获取日历data_uri = 'E:/qlib/qlib_data/cn_data'qlib.init(provider_uri=data_uri, region=REG_CN)market = "csi300"benchmark = "SH000300"
```

1.  模型训练
    

模型训练过程主要包括：数据集和模型参数初始化->初始模型和数据集实例->model.fit(dataset)->

1.  参数说明
    

Model（模型）-参数及说明：

```
 "model": { "class": "LGBModel", #模型名称，本代码使用的是LGBmodel "module_path": "qlib.contrib.model.gbdt",#AI模型所在路径 "kwargs": {#LGBmodel的超参 "loss": "mse",#损失函数，此处设置为均方误差 "colsample_bytree": 0.8879,#列采样比列 "learning_rate": 0.0421,#学习率 "subsample": 0.8789,#行采样比例 "lambda_l1": 205.6999,#L1正则化惩罚系数 "lambda_l2": 580.9768,#L2正则化惩罚系数 "max_depth": 8,#最大树深 "num_leaves": 210,#最大叶子节点数 "num_threads": 20,#最大并行线程数        },Dataset（数据集）-参数及说明dataset": { "class": "DatasetH", #数据集名称 "module_path": "qlib.data.dataset", #数据集所在路径 "kwargs": {#DatasetH模型参数 "handler": {#因子库参数 "class": "Alpha158",#因子库名称，此处使用qlib自带的Alpha158 "module_path": "qlib.contrib.data.handler",#因子库路径 "kwargs": data_handler_config, #Alpha158的参数            }, "segments": {#时间区间划分参数 "train": ("2008-01-01", "2014-12-31"),#训练集 "valid": ("2015-01-01", "2016-12-31"),#验证集 "test": ("2017-01-01", "2020-08-01"),#测试集            },        },    },
```

其中data\_handler\_config参数：

```
data_handler_config = { "start_time": "2008-01-01", "end_time": "2020-08-01", "fit_start_time": "2008-01-01", "fit_end_time": "2014-12-31", "instruments": market,}
```

1）代码

```
#################################### train model###################################data_handler_config = { "start_time": "2008-01-01", "end_time": "2020-08-01", "fit_start_time": "2008-01-01", "fit_end_time": "2014-12-31", "instruments": market,}task = { "model": { "class": "LGBModel", "module_path": "qlib.contrib.model.gbdt", "kwargs": { "loss": "mse", "colsample_bytree": 0.8879, "learning_rate": 0.0421, "subsample": 0.8789, "lambda_l1": 205.6999, "lambda_l2": 580.9768, "max_depth": 8, "num_leaves": 210, "num_threads": 20,        },    }, "dataset": { "class": "DatasetH", "module_path": "qlib.data.dataset", "kwargs": { "handler": { "class": "Alpha158", "module_path": "qlib.contrib.data.handler", "kwargs": data_handler_config,            }, "segments": { "train": ("2008-01-01", "2014-12-31"), "valid": ("2015-01-01", "2016-12-31"), "test": ("2017-01-01", "2020-08-01"),            },        },    },}# model initiaitonmodel = init_instance_by_config(task["model"]) #dataset = init_instance_by_config(task["dataset"])# start exp to train modelwith R.start(experiment_name="train_model"): R.log_params(**flatten_dict(task)) model.fit(dataset)  #拟合模型 R.save_objects(trained_model=model) rid = R.get_recorder().id
```

2）结果

![](assets/006.png)

模型按设置的参数进行训练直到验证分数50轮内没有提高，在所有训练结果中，最好的训练参数值是：0.978519，最好的验证参数值是：0.993238

### 4.6策略

策略思路：TopkDropout策略：

每日等权持有topk=50只股票，同时每日卖出持仓股票中最新预测收益最低的n\_drop=5只股票，买入未持仓股票中最新预测收益最高的n\_drop=5只股票。

策略参数如下：

```
 "strategy": { "class": "TopkDropoutStrategy", #策略名称 "module_path": "qlib.contrib.strategy.signal_strategy", #策略所在路径 "kwargs": { #TopkDropout 策略参数 "model": model,#模型 "dataset": dataset,#数据集 "topk": 50,#每日持仓股票 "n_drop": 5,#每日换仓股票        },
```

### 4.6回测

回测参数设置如下：

```
 "backtest": {#回测参数 "start_time": "2017-01-01",#回测开始时间 "end_time": "2020-08-01",#回测结束时间 "account": 100000000,#起始资金 "benchmark": benchmark,#业绩比较基准 "exchange_kwargs": {#交易参数 "freq": "day",#日频 "limit_threshold": 0.095,#涨跌停限制 "deal_price": "close",#成交价格，按收盘价 "open_cost": 0.0005,#开仓交易费率，万5佣金 "close_cost": 0.0015,#平仓交易费率，千1印花税+万5佣金 "min_cost": 5,#最低交易费用5元        },    },
```

调用qlib.workflow模块正式进行回测，依次执行如下命令：

获取上步模型训练值记录，并通过load\_object读取：

```
 recorder = R.get_recorder(recorder_id=rid, experiment_name="train_model") model = recorder.load_object("trained_model")
```

使用SignalRecord，针对测试集数据，使用训练完的模型生成预测值；

```
 # prediction recorder = R.get_recorder() ba_rid = recorder.id sr = SignalRecord(model, dataset, recorder) sr.generate()
```

使用PortAnaRecord，对预测结果进行策略回测，如下图中使用了Qlib内置的TopKDropout策略，计算策略回测的绩效指标。

```
# backtest & analysis par = PortAnaRecord(recorder, port_analysis_config, "day") par.generate()
```

模型预测值结果：

![](assets/007.png)

回测结果及绩效指标如下，分扣不扣税费。

![](assets/008.png)

### 4.7分析

前面的回测结果都以pkl文件格式存储的，所以先加载相关回测结果文件

```
from qlib.contrib.report import analysis_model, analysis_positionfrom qlib.data import Drecorder = R.get_recorder(recorder_id=ba_rid, experiment_name="backtest_analysis")print(recorder)pred_df = recorder.load_object("pred.pkl")report_normal_df = recorder.load_object("portfolio_analysis/report_normal_1day.pkl")positions = recorder.load_object("portfolio_analysis/positions_normal_1day.pkl")analysis_df = recorder.load_object("portfolio_analysis/port_analysis_1day.pkl")
```

AnalysisPosition持仓分析，分report和 risk analysis两部分。

```
analysis_position.report_graph(report_normal_df)analysis_position.risk_analysis_graph(analysis_df, report_normal_df)Analysismodelabel_df = dataset.prepare("test", col_set="label")label_df.columns = ["label"]
```

IC值：

```
pred_label = pd.concat([label_df, pred_df], axis=1, sort=True).reindex(label_df.index)analysis_position.score_ic_graph(pred_label)Model performanceanalysis_model.model_performance_graph(pred_label)
```

附：示例workflow\_by\_code.py完整的代码：(注：我使用的是workflow\_by\_code.ipynb)

```
#  Copyright (c) Microsoft Corporation.#  Licensed under the MIT License."""Qlib provides two kinds of interfaces. Users could define the Quant research workflow by a simple configuration.Qlib is designed in a modularized way and supports creating research workflow by code just like building blocks.The interface of (1) is `qrun XXX.yaml`.  The interface of (2) is script like this, which nearly does the same thing as `qrun XXX.yaml`"""import qlibfrom qlib.constant import REG_CNfrom qlib.utils import init_instance_by_config, flatten_dictfrom qlib.workflow import Rfrom qlib.workflow.record_temp import SignalRecord, PortAnaRecord, SigAnaRecordfrom qlib.tests.data import GetDatafrom qlib.tests.config import CSI300_BENCH, CSI300_GBDT_TASKif __name__ == "__main__": # use default data # provider_uri = "~/.qlib/qlib_data/cn_data"  # target_dir # GetData().qlib_data(target_dir=provider_uri, region=REG_CN, exists_skip=True) # qlib.init(provider_uri=provider_uri, region=REG_CN) #1.初始化并获取日历 data_uri = 'E:/qlib/qlib_data/cn_data' qlib.init(provider_uri=data_uri, region=REG_CN) model = init_instance_by_config(CSI300_GBDT_TASK["model"]) dataset = init_instance_by_config(CSI300_GBDT_TASK["dataset"]) port_analysis_config = { "executor": { "class": "SimulatorExecutor", "module_path": "qlib.backtest.executor", "kwargs": { "time_per_step": "day", "generate_portfolio_metrics": True,            },        }, "strategy": { "class": "TopkDropoutStrategy", "module_path": "qlib.contrib.strategy.signal_strategy", "kwargs": { "signal": (model, dataset), "topk": 50, "n_drop": 5,            },        }, "backtest": { "start_time": "2017-01-01", "end_time": "2020-08-01", "account": 100000000, "benchmark": CSI300_BENCH, "exchange_kwargs": { "freq": "day", "limit_threshold": 0.095, "deal_price": "close", "open_cost": 0.0005, "close_cost": 0.0015, "min_cost": 5,            },        },    } # NOTE: This line is optional # It demonstrates that the dataset can be used standalone. example_df = dataset.prepare("train") print(example_df.head()) # start exp with R.start(experiment_name="workflow"): R.log_params(**flatten_dict(CSI300_GBDT_TASK)) model.fit(dataset) R.save_objects(**{"params.pkl": model}) # prediction recorder = R.get_recorder() sr = SignalRecord(model, dataset, recorder) sr.generate() # Signal Analysis sar = SigAnaRecord(recorder) sar.generate() # backtest. If users want to use backtest based on their own prediction, # please refer to https://qlib.readthedocs.io/en/latest/component/recorder.html#record-template. par = PortAnaRecord(recorder, port_analysis_config, "day") par.generate()
```