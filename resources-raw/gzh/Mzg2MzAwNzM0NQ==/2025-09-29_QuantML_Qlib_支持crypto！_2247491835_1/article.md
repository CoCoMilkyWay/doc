# QuantML Qlib | 支持crypto！

QuantML QuantML 2025-09-29 19:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247491835&idx=1&sn=6db7d2d155688ae336cdfcae85de2aee&chksm=cf866437a971d8b2f20d4ef90eb3aa7e5ae31eea97610e676e76cf1107a97a4b8055675e88fe#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247491835&idx=1&sn=6db7d2d155688ae336cdfcae85de2aee&chksm=cf866437a971d8b2f20d4ef90eb3aa7e5ae31eea97610e676e76cf1107a97a4b8055675e88fe#rd)

为打通传统金融与数字资产数据，我们在QuantML Qlib中新增了crypto 模块，可一键导入数据，运行模型。

本次更新在统一数据框架中引入 Binance 加密货币数据源，支持 day/1min/1hour 等多频率与 24/7 日历，提供 K 线、24h 统计、订单簿与最近成交等能力；导入与更新数据全面兼容 Qlib 二进制并增强稳定性（分批抓取、重试、仅数值字段写入），与工厂和配置无缝集成，实现股票与加密资产在同一流程中的采集、导出与回测，提升策略复用与生产可用性。

## 数据

-   **加密货币现货数据**
    

-   **行情字段**：open、high、low、close、volume、total\_turnover、num\_trades
    
-   **扩展能力**：24h 统计（涨跌幅、成交量等）、订单簿（深度）、最近成交、交易所元信息
    

-   **多频率支持**
    

-   **频率**：day / 1min / 1hour（可扩展 3min、5min、15min、30min、2h、4h、6h、8h、12h）
    
-   **日历**：基于频率自动生成，覆盖 24/7 全时段（适配加密货币市场）
    

-   **数据导入（Qlib 兼容）**
    

-   **特征二进制**：与 Qlib `.bin` 格式兼容，自动对齐日历、只写入数值字段
    
-   **增量/全量**：支持全量导出与增量更新两种模式
    

-   **稳定性与性能**
    

-   **分批抓取**：K线接口自动分页
    
-   **频控与重试**：内置重试策略；支持代理与 API Key 提升额度
    
-   **24/7**：无交易日限制，长期运行稳定
    

### 命名与兼容

-   **统一命名**：内部统一使用小写 `usdt` 交易对（如 `btcusdt`、`ethusdt`、`bnbusdt`）
    

### 配置与使用

-   **数据源与工厂**
    

-   通过 `data_interfaces/factory.py` 创建 `binance` 接口；`config/unified_config.py` 支持可选 `BINANCE_API_KEY/SECRET`
    

-   **一键导入示例**
    

`from unified_data_dumper import UnifiedDataDumperAll      config = {       'qlib_dir': 'D:\\qlib_data\\crypto_qlib_data',       'data_source': 'binance',       'data_source_config': {},         # 公共API可为空；如需更高额度可配置 key/secret       'universe': ['BTCUSDT', 'ETHUSDT', 'BNBUSDT'],       'start_date': '2025-09-22',       'end_date': '2025-09-29',       'max_workers': 2,       'freq': 'day'   }      dumper = UnifiedDataDumperAll(**config)   dumper.dump()   `

### 场景与收益

-   **量化研究**：统一框架下同时处理股票与加密资产，策略复用更便捷
    
-   **高频与监控**：分钟/小时级数据稳定导出，可用于盘面监控与短线策略
    

### 最佳实践

-   **频率与区间**：分钟/小时级建议控制时间跨度，避免日历超大
    
-   **速率与代理**：生产环境建议配置 `BINANCE_API_KEY/SECRET` 与代理，提升稳定性
    
-   **容错**：导出链路仅写入数值字段，确保 `.bin` 文件可靠
    

### 快速开始

-   安装依赖：`python-binance`（已在 `requirements.txt`）
    
-   建议环境变量（BINANCE API可选，PROXY必须）：
    

`set BINANCE_API_KEY=your_key   set BINANCE_API_SECRET=your_secret   set http_proxy=http://127.0.0.1:7890   set https_proxy=http://127.0.0.1:7890   `

-   运行示例：`python examples/binance_example.py`
    

## 模型测试

可直接复用QuantML Qlib中所有因子及模型，只需将数据改为crypto数据即可。 示例代码：`examples\workflow_by_code crypto.ipynb`

### 初始化数据地址

`provider_uri = "D:\\qlib_data\\crypto_qlib_data_1min"  # target_dir   qlib.init(provider_uri=provider_uri)   `

### 模型训练

计算crypto的alpha158因子，构建LGBM模型：

`###################################   # train model   ###################################   data_handler_config = {       "start_time": "2025-09-22 00:00:00",       "end_time": "2025-09-28 23:59:00",       "fit_start_time": "2025-09-22 00:00:00",       "fit_end_time": "2025-09-28 23:59:00",       "instruments": market,       "freq": "1min",       "label": ["Ref($close, -60) / Ref($close, -1) - 1"],    }      task = {       "model": {           "class": "LGBModel",           "module_path": "qlib.contrib.model.gbdt",           "kwargs": {               "loss": "mse",               "colsample_bytree": 0.8879,               "learning_rate": 0.0421,               "subsample": 0.8789,               "lambda_l1": 205.6999,               "lambda_l2": 580.9768,               "max_depth": 8,               "num_leaves": 210,               "num_threads": 20,           },       },       "dataset": {           "class": "DatasetH",           "module_path": "qlib.data.dataset",           "kwargs": {               "handler": {                   "class": "Alpha158",                   "module_path": "qlib.contrib.data.handler",                   "kwargs": data_handler_config,               },               "segments": {                   "train": ("2025-09-22 00:00:00", "2025-09-25 23:59:00"),                   "valid": ("2025-09-26 00:00:00", "2025-09-26 23:59:00"),                   "test": ("2025-09-27 00:00:00", "2025-09-28 23:59:00"),               },           },       },   }      # model initialization   model = init_instance_by_config(task["model"])   dataset = init_instance_by_config(task["dataset"])      # start exp to train model   with R.start(experiment_name="train_model"):       R.log_params(**flatten_dict(task))       model.fit(dataset)       R.save_objects(trained_model=model)       rid = R.get_recorder().id   `

### 结果展示

信号的IC及分组收益：

![](assets/001.png)

![](assets/002.png)

## Roadmap

后续我们也将进一步完善对于crypto策略的支持，包括：

-   期货与永续合约数据
    
-   资金费率、资金流向
    
-   更丰富的技术指标与数据质量检查
    
-   与 Dagster 作业更深度融合（失败告警、指标监控）
    

为了方便代码管理，目前QuantML Qlib代码已经托管至我们自建的Gitea服务器，欢迎加入**QuantML知识星球**获取代码，交流测试。

  

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/003.jpg)