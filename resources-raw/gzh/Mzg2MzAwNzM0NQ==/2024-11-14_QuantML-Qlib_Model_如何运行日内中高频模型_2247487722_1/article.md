# QuantML-Qlib Model | 如何运行日内中高频模型

QuantML QuantML 2024-11-14 20:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&chksm=cf0e44739337ecdf78e6c1cc02c039a196f4a46420ef1c5f17c819040be0c01727f5d77a4898#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&chksm=cf0e44739337ecdf78e6c1cc02c039a196f4a46420ef1c5f17c819040be0c01727f5d77a4898#rd)

  

在QuantML-Qlib中，星球会员经常问到的一个问题便是如何运行日内模型，本文我们将介绍如何基于分钟频数据训练xgboost，包括如何导入数据，配置参数，运行模型以及在运行时经常会遇到的一些问题，其他频率的数据运行方法相同。

## 准备数据

与日频数据一样，可以采用从csv导入为bin文件，或者直接导入各类数据库，直接从数据库读取数据，本文采用第一种方法，数据库读取的方法参考公众号之前的文章。

分钟频数据的获取需要从第三方获取，为避免广告嫌疑，不做任何推荐。如果没有三方数，可以从星球获取部分测试数据，数据已经处理为csv格式，然后进入到scripts目录下，运行以下命令：

```
python dump_bin.py dump_all --csv_path <your_data_path> --qlib_dir <your_bin_data_path> --include_fields open,close,high,low,vwap,volume,total_turnover,num_trades -freq 1min
```

这里需要注意的是，后续的因子计算需要用到vwap字段，如果数据商没有提供vwap数据（我们测试数据中没有vwap字段），需要进行手动计算。计算方法有两种，一是直接使用成交量和成交额计算，相关的计算代码已经加到了dump\_bin之中，另外还有一种方法，在没有成交额或者成交量时，采用近似算法：(high + 2\*close)/6

会在指定的目录下生成qlib所需的数据格式，生成好的bin文件数据也已上传至星球，可以自行下载获取。

## 配置参数

以XGBOOST模型为例，在example/benchmarks/XGBoost目录下构建workflow\_config\_min\_xgboost\_Alpha158.yaml配置文件，大部分配置与日频的config文件配置相类似，需要修改的内容包括：

-   在 data\_handler\_config 中加入 freq: '1min' 参数
    
-   将所有的日期从日频格式改为分钟频格式
    
-   end time 中的小时部分改为15：00：00
    
-   日频数据正常交易情况下不存在成交量0的情况，所以因子没有极值，但是在分钟频下，有些因此在除以volume时会有异常值出现，需要加入数据清洗的步骤，否则程序报错
    

以上修改均已写入config文件，可自行参考，接下来运行目录下的run.py文件即可。为了便于测试，我们在文件的instruments目录下建一个test文件，只包含100只股票用于训练，因子采用分钟频的alpha158因子，目标为：

"Ref(close, -1) - 1"

模型参数如下：

```
  class: XGBModel  module_path: qlib.contrib.model.xgboost  kwargs:      eval_metric: rmse      colsample_bytree: 0.8879      eta: 0.0421      max_depth: 8      n_estimators: 647      subsample: 0.8789      nthread: 20
```

最终的结果如下：

```
  {'IC': 0.04671055094777292,    'ICIR': 0.28093567513253737,   'Rank IC': 0.0634098272234711,   'Rank ICIR': 0.5279470290513801}
```

样本外时间段较短，且股票数量较少，结果仅作为展示，不具备统计学意义。

本文是分钟频数据和模型介绍的第一篇，如果你在运行时遇到问题，欢迎与我们交流。

后面我们还会介绍如何同时使用分钟频以及日频数据用于模型训练。

  

  

  

  

  

QuantML星球内有各类丰富的量化资源，包括上百篇论文代码，QuantML-Qlib框架，研报复现项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

  

![](assets/001.webp)