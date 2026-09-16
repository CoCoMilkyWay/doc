# 研报复现 | 基于筹码分布的选股策略

Hugo QuantML 2024-07-05 19:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=cfb48b70263598bda08ff4077aa88c69b8319b07ce53e0d5007d6ddebdbb0cf35101368b4d06#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=cfb48b70263598bda08ff4077aa88c69b8319b07ce53e0d5007d6ddebdbb0cf35101368b4d06#rd)

  

本文来自星球嘉宾Hugo的研报项目，复现研报：《广发证券\_多因子Alpha系列报告之（二十七）——基于筹码分布的选股策略》，主要内容包括：

    1. 使用前景理论的换手率半衰期加权的筹码构建,这种方式是构建处置效应因子(CGO)的底层算法

    2. 国内看盘软件上显示的筹码分布算法（源于陈浩-筹码分布,国外称之为CYQ）此算法又有两种类型：

       1. 三角分布

       2. 平均分布

本文在Qlib框架的基础上构造了一些列的筹码算子，考虑到效率问题,并未使用scipy.stats.triang和uniform，而是使用numba对其进行了重构，因子复合使用了Qlib的TCN和GBDT模型

# 根据前景理论的筹码因子构建

## 交易行为的非对称性

行为金融学认为，股票的价格并不由股票的内在价值所决定，还很大程度上受投资者主体的行为和心理的影响。换句话说，如果投资者的决策过程存在规律或者特定的话，我们便可以利用这种“人性的弱点”来寻找股票市场的定价错误。

诺贝尔经济学奖得主卡尼曼曾提出前景理论来描述人们的风险决策行为，其理论有三点结论：处于收益状态时，人们往往小心翼翼、厌恶风险、喜欢见好就收；处于亏损状态时，人们往往会极不甘心，宁愿承受更大的风险来赌一把；白捡的100元所带来的快乐，难以抵消丢失100元所带来的痛苦。

当前景理论应用在股票市场时，便成了股票市场的处置效应，即：投资者急于卖出盈利的股票，而不愿意卖出亏损的股票；损失股票的持有时间比收益股票的持有时间长；当股票的价格接近投资者的购买价格的时候，投资者效用会发生剧烈改变。

本文希望通过量化的工具来挖掘处置效应导致的市场定价错误，从而得到不一般基本面分析和资金面分析所不能涉及的Alpha信息，并且我们有理由相信这种基于“人性的弱点”的Alpha是显著而且具有长期有效性的。

## 筹码分布的计算

通过上面的分析我们可以知道，若我们知道各个投资者的购买成本，那么我们就可以分析出来股票市场是否真的存在处置效应，并可以以此指导我们进行投资。但是除了交易所，没有人可以知道其他投资者的购买成本的。因此，此处我们根据市场上已有的价格与成交数据近似的代表股票市场投资者的购买成本以及购买数量，以此计算股票的筹码分布。

**调整换手率**

我们利用成均价与换手率来近似计算股票的筹码分布情况。具体的计算细节为：

1.  1\. 先确定目标交易日；以表1为例，周五为我们的目标交易日；
    
2.  2\. 换手率的路径依赖调整；以表1为例，周四交易的20%的股份在周五还没有被重新交易的股份为20%×（1-20%）=16%；同理周三交易的20%的股份在周五还没有被重新交易的股份为20%×（1-20%）×（1-20%）=13%；
    
3.  3\. 换手率归一化，根据调整换手率的和对每日的调整换手率进行归一化；
    

日期

成交均价

相对收益

换手率

调整换手率

归一化换手率

周一

10

1-10/13=0.23

0.01

0.01\*(1-0.05)(1-0.08)(1-0.02)\*(1-0.03)=0.0083

0.0601

周二

11

1-11/13=0.15

0.005

0.005\*(1-0.08)(1-0.02)(1-0.03)=0.0044

0.0319

周三

12

1-12/13=0.07

0.08

0.08\*(1-0.02)\*(1-0.03)=0.0760

0.5503

周四

10

1-10/13=0.23

0.02

0.02\*(1-0.03)=0.0194

0.1405

周五

13

1-13/13=0.00

0.03

0.03

0.2172

总和

  

  

0.145

0.1381

1

可以看出这种筹码分布的计算方法，有一个很强的假设在于每一日的换手平均化到之前的每一天。即按上表来说，周一的成交量，在周二有0.5%被卖出，周三在周二卖出的基础上再有8%被卖出，周四周五同理。对于周五的3%换手来说，是周四成交的数量的2%加上周三成交的数量但在周四未卖出的3%，一直往前加到周一。

**显然，这离真实的筹码分布还有一定的距离，成交量不可能是简单的平摊到之前的每一天**。但我们得基于此假设继续研究，我们以此为近似筹码分布。

## 筹码分布的四个代理变量

给定任意一只股票，假设该股票在t日的成交均价为$P\_t$，在t-1日的成交均价为$P\_{t−1}$，同理在t-n日的成交均价为$P\_{t−n}$。如果我们以t日为目标日计算筹码分布的话，则任意一日n(1≤n≤60)被交易的股份的相对资产收益（注意：相对资本收益并不是指投资回报）为：

RCt\=PtPt−Pt−n

假设股票在t日得换手率为$TR\_{t}$,在t-n日的换手率为$TR\_{t-n}$。因此，根据我们上述换手率归一化的方法，目标日归一化换手率$TR\_W\_{n}$为: $$ATR\_{t} = TR\_{t} + TR\_{t-1}(1-TR\_{t}) + TR\_{t-2}(1-TR\_{t-1})(1-TR\_{t})+\\dots + TR\_{t-n}(1-TR\_{t-n-1})\\dots(1-TR\_{t})$$ $$TR\_W\_{t}=\\frac{ATR\_{t}}{\\sum^{n}{n=1}ATR{n}}$$

根据相对资本收益以及调整换手率,我们可以构建筹码分布的均值,方差,偏度和峰度四个代理变量:

ARCt\=n\=1∑nTR\_Wt∗RCt

ARC>0表示筹码处于平均盈利状态；ARC<0表示筹码处于平均亏损状态；

VRCt\=n−1∑n\=1nn∗TR\_Wt∗(RCt−ARCt)2

VRC特别大表示筹码特别的分散；VRC特别小表示筹码比较集中；

SRCt\=VRCt1.5∗(n−1)∑n\=1nn∗TR\_Wt∗(RCt−ARCt)3

SRC>0表示筹码分布不对称且右偏，即有一部分投资者的收益特别高；SRC<0表示筹码分布不对称且左偏，即有一部分投资者亏损特别严重；

KRCt\=VRCt2∗(n−1)∑n\=1nn∗TR\_Wt∗(RCt−ARCt)4

KRC特别大表示筹码分布里面盈亏分化很强，要么盈利很多，要么亏损很多，处于小赢小亏状态的筹码非常少；KRC特别小则表现盈亏分化很小，筹码处于小赢小亏的状态；

**n默认为60日**

## 因子构建

`import empyrical as ep   import pandas as pd      from pathlib import Path   import qlib   from qlib.data import D   from qlib.utils import init_instance_by_config   from typing import List, Tuple, Dict   from scr.turnover_coefficient_ops import ARC, VRC, SRC, KRC   from scr.cyq_ops import (       CYQK_C_T,       CYQK_C_U,       CYQK_C_TN,       ASR_T,       ASR_U,       ASR_TN,       CKDW_T,       CKDW_U,       CKDW_TN,       PRP_T,       PRP_U,       PRP_TN,   )   from scr.factor_analyze import clean_factor_data, get_factor_group_returns   from scr.qlib_workflow import run_model, get_dataset_config, get_tsdataset_config   from scr.plotting import plot_dist_chips, model_performance_graph, report_graph      import matplotlib.pyplot as plt      # plt中文显示   plt.rcParams["font.sans-serif"] = ["SimHei"]   # plt显示负号   plt.rcParams["axes.unicode_minus"] = False`

`custom_ops: List = [ARC, VRC, SRC, KRC, CYQK_C_T, CYQK_C_U, CYQK_C_TN,                       ASR_T, ASR_U, ASR_TN, CKDW_T, CKDW_U, CKDW_TN, PRP_T, PRP_U, PRP_TN]   qlib.init(provider_uri="qlib_data",             region="cn", custom_ops=custom_ops)`

`[6020:MainThread](2023-04-12 09:31:33,351) INFO - qlib.Initialization - [config.py:416] - default_conf: client.   [6020:MainThread](2023-04-12 09:31:33,354) INFO - qlib.Initialization - [__init__.py:74] - qlib successfully initialized based on client settings.   [6020:MainThread](2023-04-12 09:31:33,354) INFO - qlib.Initialization - [__init__.py:76] - data_path={'__DEFAULT_FREQ': WindowsPath('D:/WorkSpace/QuantsPlaybook/B-因子构建类/筹码因子/qlib_data')}`

`###################################   # 参数配置   ###################################   # 数据处理器参数配置：整体数据开始结束时间，训练集开始结束时间，股票池   TARIN_PERIODS: Tuple = ("2014-01-01", "2017-12-31")   VALID_PERIODS: Tuple = ("2018-01-01", "2020-12-31")   TEST_PERIODS: Tuple = ("2021-01-01", "2023-02-17")         dataset_config: Dict = get_dataset_config(       "pool", TARIN_PERIODS, VALID_PERIODS, TEST_PERIODS, "TurnCoeffChips"   )         if Path("factor_data/turnovercoeff_dataset.pkl").exists():       import pickle          with open("factor_data/turnovercoeff_dataset.pkl", "rb") as f:           turncoeff_dataset = pickle.load(f)   else:       # 实例化数据集，从基础行情数据计算出的包含所有特征（因子）和标签值的数据集。       turncoeff_dataset = init_instance_by_config(dataset_config)  # 类型DatasetH          # 保存数据方便后续使用       turncoeff_dataset.config(dump_all=True, recursive=True)       turncoeff_dataset.to_pickle(           path="factor_data/turnovercoeff_dataset.pkl", dump_all=True       )      record_dict: Dict = run_model(       turncoeff_dataset,       "transformer",       start_time=TEST_PERIODS[0],       end_time=TEST_PERIODS[1],       model_kw={"d_feat": 4, "num_layers": 16, "nhead": 8, "method": "normal"},       experiment_name="turncoeffchips",       trained_model="trained_model.pkl",   )`

## 单因子分析

`df_test: pd.DataFrame = turncoeff_dataset.prepare(       segments="test", data_key="raw")   df_test.rename(columns={'LABEL0': "next_ret"}, inplace=True)`

`clean_factor: pd.DataFrame = clean_factor_data(df_test)   # 计算分组收益率   group_returns: pd.DataFrame = get_factor_group_returns(       clean_factor, quantile=5, no_raise=False   )   # 计算累计收益率   group_cum: pd.DataFrame = ep.cum_returns(group_returns)      # 画图   for factor_name, df in group_cum.groupby(level=0, axis=1):       df.plot(title=factor_name, figsize=(12, 6))       plt.axhline(0, ls="--", color="black")`

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

## 因子复合

`try:       recorder = record_dict["recorder"]   except NameError:       # 使用已有模型       from qlib.workflow import R       import pickle          with open("factor_data/turnovercoeff_dataset.pkl", "rb") as f:           turncoeff_dataset = pickle.load(f)       # tfs pool 0accc05c53f74dc6827853d7b310307e       # csi300 34342b9c77c941788eea7b85a27e243e       # gbdt pool 277db25d948e4423b541d3382044c285       with R.start():           recorder = R.get_recorder(               recorder_name="mlflow_recorder",               recorder_id="b6fb35b51626493f835c86c7d8a2b1b3",           )`

`label_df: pd.DataFrame = turncoeff_dataset.prepare("test", col_set="label")   label_df.columns = ["label"]   pred_df: pd.DataFrame = recorder.load_object("pred.pkl")      # 创建测试集"预测"和“标签”对照表   pred_label_df: pd.DataFrame = pd.concat([pred_df, label_df], axis=1, sort=True).reindex(       label_df.index   )`

## 复合因子表现

`model_performance_graph(pred_label_df, duplicates='drop')`

![](assets/005.png)

## 回测表现

`report_normal_1day_df: pd.DataFrame = recorder.load_object(       "portfolio_analysis/report_normal_1day.pkl")`

`report_graph(report_normal_1day_df)`

![](assets/006.png)

![](assets/006.png)

  

# 陈浩筹码分布(CYQ)

这个版本的筹码就是我们在通达信，同花顺等行情软件上看到的**筹码因子**

筹码分布来源于中科院陈浩老师于1997年，针对中国市场率先提出的一种技术指标，属于资金面指标。

筹码分布有很多衍生指标，可以分为下面三类，下面介绍如何使用：

1.  1\. 形态类，例如："低位密集"个股未来可能会迎来上涨；"高位密集"个股未来会下跌回调；"双峰填谷"代表主力在附近价格吸筹，即将迎来变盘；"低位锁定"代表主力控盘程度高，结合当前上涨力度可以判断是否买入
    
2.  2\. 衍生指标类，例如："活动筹码ASR"刻画当前价位上下区间的筹码比例，该上下区间的筹码往往是短线投资者活动区域，我们可以利用ASR指标来寻找主力控盘强的个股；"成本重心CKDW"同样可以用来判断筹码密集程度，CKDW越大说明高位密集状态越明显，反之说明低位密集状态越明显；"获利盘比例CYQK\_C"刻画在当前收盘价对应的获利盘比例，CYQK\_C越大说明获利筹码越多，未来上涨阻力越小/上方抛售压力越小；"价格相对位置PRP"用于判断股价高估程度，PRP越大说明无量超涨且主力控盘程度高，反之说明无量超跌且大部分筹码处于套牢状态，是一种危险信号。
    
3.  3. 实时指标类，同花顺的DDE等大单/主力指标，这里不做深入研究
    

## 筹码分布计算原理

筹码分布理论就是根据股票交易筹码流动的特点，对大盘或个股的历史成交情况进行分析，得出其筹码分布，然后根据这个筹码分布图来预测以后的走势。筹码分析理论的自然规律基础，是筹码流动的特点。股票交易都是通过买卖双方在某个价位进行买卖成交而实现的。随着股票的上涨或下跌，在不同的价格区域产生着不同的成交量，这些成交量在不同的价位的分布量，形成了股票不同价位的持仓成本。 **筹码分布主要应用于筹码持仓成本分析**。一轮行情发展都是由成本转换开始的，又因成本转换而结束。什么是成本转换呢？形象的说，成本转换就是筹码搬家，是指持仓筹码由一个价位向另一个价位搬运的过程，它不仅仅是股价的转换，更重要的是持仓筹码数量的转换。股票的走势在表象上体现了股价的变化，而其内在的本质却体现了持仓成本的转换。

2008年之前交易所公布topview数据,每天机构/散户/主力的买入量；之后被交易所叫停，我们只能粗略估算各个价位对应的持仓量，具体方法如下：使用日间数据，假设成交量服从某种特定分布，按特定时间衰减，进行换手累加得到估计值。

## 筹码分布估计算法:

已知当天low/high/vol,假设这一天内的各个价位的建仓价格符合三角分布,即可求得当天新建仓位的筹码分布,按换手率衰减比例进行累计最终可求：

![](assets/007.png)

其中Coeff(历史换手衰减系数)默认为1，它是一个常数参数，我们用来赋予今天换手率，也既是当日被移动的成本的权重。如果今天的换手率是A，衰减系数是n，那么我们计算昨日的被移动的筹码的总量是A\*n,如果n取值为1，就是一般意义上理解的今天换手多少，就有多少筹码被从作日的成本分布中被搬移；如果n是2，那么我们就放大了作日被移动的筹码的总量..这样的目的在于突出“离现在越近的筹码分布其含义越明显”。  

**基本的一些概念**

-   • 平均分布：将当日的换手筹码在当日的最高价和最低价之间平均分布。
    
-   • 三角形分布：将当日的换手筹码在当日的最高价、最低价和平均价之间三角形分布。
    

## 筹码分布可视化

`# 数据获取   pool: List = D.list_instruments(D.instruments("csi300"), as_list=True)   print(pool[0])   frame: pd.DataFrame = D.features(       [pool[0]],       fields=["$close", "$high", "$low", "$vol", "$turnover_rate"],   )   frame.reset_index(level=0, inplace=True, drop=True)   frame.columns = frame.columns.str.replace("$", "", regex=True)      slice_frame: pd.DataFrame = frame.iloc[-80:].copy()`

`002202.SZ`

## 三角分布

`plot_dist_chips(slice_frame, "triang", "002202.SZ-三角分布")`

`<AxesSubplot: title={'center': '002202.SZ-三角分布'}, xlabel='price', ylabel='volume'>`

![](assets/008.png)

## 平均分布

`plot_dist_chips(slice_frame, "uniform", "002202.SZ-平均分布")`

`<AxesSubplot: title={'center': '002202.SZ-平均分布'}, xlabel='price', ylabel='volume'>`

![](assets/009.png)

## 换手率半衰期

`plot_dist_chips(slice_frame, "turn_coeff", "002202.SZ-换手率衰减")`

`<AxesSubplot: title={'center': '002202.SZ-换手率衰减'}, xlabel='price', ylabel='volume'>`

![](assets/010.png)

  

## 因子构建

`###################################   # 参数配置   ###################################   # 数据处理器参数配置：整体数据开始结束时间，训练集开始结束时间，股票池   TARIN_PERIODS: Tuple = ("2014-01-01", "2017-12-31")   VALID_PERIODS: Tuple = ("2018-01-01", "2019-12-31")   TEST_PERIODS: Tuple = ("2020-01-01", "2023-02-17")         dataset_config: Dict = get_tsdataset_config(       "csi300",       TARIN_PERIODS,       VALID_PERIODS,       TEST_PERIODS,       20,       "Chips",   )         if Path("factor_data/chip_ts_dataset.pkl").exists():       import pickle          with open("factor_data/chip_ts_dataset.pkl", "rb") as f:           cyq_ts_dataset = pickle.load(f)   else:       cyq_ts_dataset = init_instance_by_config(dataset_config)  # 类型DatasetH          # 保存数据方便后续使用       cyq_ts_dataset.config(dump_all=True, recursive=True)       cyq_ts_dataset.to_pickle(path="cyq_ts_dataset.pkl", dump_all=True)      cyq_record: Dict = run_model(       cyq_ts_dataset,       "transformer_ts",       start_time=TEST_PERIODS[0],       end_time=TEST_PERIODS[1],       model_kw={"d_feat": 12,"num_layers":8, "seed": 42,'n_jobs':20},       experiment_name="cyq",       trained_model="trained_model.pkl",   )`

## 单因子分布

`# TSDatasetH生成数据并非pd.DataFrame   # 可以使用DatasetH或者QlibData来生成因子数据 因子生成差不多需要200~300min   try:       cyq_dataset.prepare(segments="test", data_key="raw")   except NameError:       import pickle          if Path("factor_data/chip_dataset.pkl").exists():           with open("factor_data/chip_dataset.pkl", "rb") as f:               cyq_dataset = pickle.load(f)          else:           dataset_config: Dict = get_dataset_config(               "csi300",               TARIN_PERIODS,               VALID_PERIODS,               TEST_PERIODS,               "Chips",           )           cyq_dataset = init_instance_by_config(dataset_config)  # 类型DatasetH              # 保存数据方便后续使用           cyq_dataset.config(dump_all=True, recursive=True)           cyq_dataset.to_pickle(path="cyq_dataset.pkl", dump_all=True)      df_test: pd.DataFrame = cyq_dataset.prepare(segments="test", data_key="raw")   df_test.rename(columns={"LABEL0": "next_ret"}, inplace=True)`

`clean_factor: pd.DataFrame = clean_factor_data(df_test)   # 计算分组收益率   group_returns: pd.DataFrame = get_factor_group_returns(       clean_factor, quantile=5, no_raise=True   )   # 计算累计收益率   group_cum: pd.DataFrame = ep.cum_returns(group_returns)      # 画图   for factor_name, df in group_cum.groupby(level=0, axis=1):       df.plot(title=factor_name, figsize=(12, 6))       plt.axhline(0, ls="--", color="black")`

![](assets/011.png)

![](assets/012.png)

![](assets/013.png)

![](assets/014.png)

![](assets/015.png)

![](assets/016.png)

![](assets/017.png)

![](assets/018.png)

## 复合因子

`try:       recorder = record_dict["recorder"]   except NameError:       # 使用已有模型       from qlib.workflow import R       import pickle          with open("factor_data/chip_dataset.pkl", "rb") as f:           cyq_dataset = pickle.load(f)       # tcn layer 8:5a8fbb3d07ca4bcf8883589dcebad44d       # transform layer 2:e7539ce11aad4c8c92c3e2be518b9106       # transform layer 8 :e8e62a5185394314b5a7d79a17160059       with R.start():           recorder = R.get_recorder(               recorder_name="mlflow_recorder",               recorder_id="5a8fbb3d07ca4bcf8883589dcebad44d",           )`

``[77228:MainThread](2023-04-09 22:11:26,486) INFO - qlib.workflow - [exp.py:258] - Experiment 2 starts running ...   [77228:MainThread](2023-04-09 22:11:26,511) INFO - qlib.workflow - [recorder.py:341] - Recorder 18e1bb1381904a5e9d1bc350d8f6e5c4 starts running under Experiment 2 ...   [77228:MainThread](2023-04-09 22:11:27,000) INFO - qlib.timer - [log.py:128] - Time cost: 0.001s | waiting `async_log` Done``

`label_df = recorder.load_object("label.pkl")   label_df.columns = ["label"]   pred_df: pd.DataFrame = recorder.load_object("pred.pkl")      # 创建测试集"预测"和“标签”对照表   pred_label_df: pd.DataFrame = pd.concat([pred_df, label_df], axis=1, sort=True).reindex(       label_df.index   )`

`model_performance_graph(pred_label_df, duplicates='drop')`

## 回测表现

`report_normal_1day_df: pd.DataFrame = recorder.load_object(       "portfolio_analysis/report_normal_1day.pkl")`

`report_graph(report_normal_1day_df)`

  

  

**数据及代码下载见星球**

加入星球请扫我：

![](assets/019.png)

入群请扫我：![](assets/020.jpg)

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | 清华大学时序卷积模型TimesNet用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484709&idx=1&sn=f462495e96ee99019f83321a84d2fd0a&chksm=ce7e623bf909eb2d3f24882531e2ac8de4459bab71920a5985d7add81731d82d7ba55934bd07&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序模型Autoformer用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=ce7e631df909ea0b4515cbd2f95cffb0733d872a519942f1d88e6a561a01bcfe68716d31fe0c&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [研报复现 | 开源证券 ：形态识别，均线的收敛与发散](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)  
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | FTS-Diffusion: 用于合成具有不规则和尺度不变模式的金融时间序列的生成框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483907&idx=1&sn=df124c03a74981eba923fee63613ecfd&chksm=ce7e651df909ec0b2f6029db3e29992bb41210c8b9f76f979b7968d0fab1ac913848004ac44d&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)
    
-   [ICAART 2024 | DTX: 基于TBSE Level2多线程市场模型的深度学习交易系统](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483965&idx=1&sn=e2fda25ce1bc8a4b9393158321dc2a14&chksm=ce7e6523f909ec3538bd37e07689308380cad55b02c35a7d4652a3e7d7fd3306a40253341c61&scene=21#wechat_redirect)
    

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

  

**点击蓝字**

![](assets/021.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

![](assets/022.jpg)