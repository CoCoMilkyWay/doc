# 三年累积，一次拆分：QuantML-Qlib 重构

QuantML QuantML 2026-06-11 15:41 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247494029&idx=1&sn=a238038a0727fa2a267a7eea62bc2007&chksm=cf59e5a662681cba12bd241c44ff90a9f9295f88531d0b2088943338a5fa4e06123b99449bec#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247494029&idx=1&sn=a238038a0727fa2a267a7eea62bc2007&chksm=cf59e5a662681cba12bd241c44ff90a9f9295f88531d0b2088943338a5fa4e06123b99449bec#rd)

经过三年的开发，QuantML-Qlib 已经积累了不少内容：SOTA预测模型、时间序列算法、因子挖掘算法、自定义算子、数据接口等等，提供了一整套强大的研究工具。

  

  

\_

● [QuantML-Qlib](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=Mzg2MzAwNzM0NQ==&action=getalbum&album_id=3437319663879782404#wechat_redirect)[合集](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=Mzg2MzAwNzM0NQ==&action=getalbum&album_id=3437319663879782404#wechat_redirect)

[► 点击阅读](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=Mzg2MzAwNzM0NQ==&action=getalbum&album_id=3437319663879782404#wechat_redirect)

  

但是许多问题也随之出现：很多新增模型散落在各个文件夹下面。项目继续增长以后，examples 慢慢变成第二个源码目录。模型实现、配置文件、数据格式化代码混在一起，很多读者反馈分不清哪些是 QuantML 增加的模型。

  

更麻烦的是安装。每次新增模型依赖的包太多，之前没有很好的维护导致安装非常麻烦，还有些用户只是想试 LightGBM 或 MLP，结果环境里可能被带入一堆 torch、数据源、数据库、Dashboard、研究 notebook 的依赖。量化研究环境本来就容易被 pandas、numpy、torch、TA-Lib 这些包的冲突拖住，依赖边界不清楚，后面每一次升级都会变得保守。本次重构也优化了安装，核心框架一行命令安装，其他模块按需安装，极大的提高了安装的便利性。

## 核心重构

重构后的核心变化，是把我们自己扩展出来的能力集中放到 `qlib.ext` 下面。

重构后的目录结构是这样的：

```
qlib/ext/  benchmarks/          # 模型、配置、训练流程    models/            # 25+ 预测模型的实现    configs/           # 每个 model 一个子目录，里面有 YAML workflow config    layers/            # 共享的神经网络组件（attention、embedding、encoder/decoder）    data_formatters/   # Informer/DLinear/PatchTST 等模型的数据格式化    handlers/          # LightGBM 多频处理器、高频数据处理、滚动处理    utils/             # KAN、metrics、masking、plotting 等工具    tft/               # Temporal Fusion Transformer（TensorFlow 实现）    research_models/   # 研究阶段模型：iTransformer、PatchTST、MomentFM、ABCM  data_sources/        # 统一数据源适配层    adapters/          # 5 个适配器：AKShare、TuShare、RQDataC、Binance、Smoke    factory.py         # 工厂模式，按名字创建数据源实例    dumper.py          # 统一写入 qlib binary format    config.py          # 分层配置：YAML 文件 → 环境变量覆盖    cli.py             # `qlib-data-source` 命令行入口  data_collector/      # 遗留数据采集脚本的基类迁移  factors/             # 因子挖掘与评估    evaluator.py       # RankIC / ICIR 计算、表达式校验    generation.py      # DeepSeek LLM 因子生成    alphagpt_framework.py  # AlphaGPT 迭代优化编排    gplearn/           # 遗传规划（GP）因子挖掘    alphagen_*.py      # 强化学习因子生成（AlphaGen）    alphakan/          # Kolmogorov-Arnold Network 因子发现    alphanet_*.py      # AlphaNet v3    pool.py            # 因子池：互斥 IC 过滤、权重优化    tensor_evaluator.py # Torch 批量 IC 评估    talib_ops.py       # TA-Lib 算子集成    cli.py             # `qlib-factor` 命令行入口
```

看起来好像只是目录变化，但其实非常关键，意味着：

1.  **代码与 Qlib 原有实现解耦**——所有 QuantML 扩展代码都可以热插拔到读者自己已有的 Qlib 环境中，不需要改 Qlib 源码。
    
2.  **依赖隔离**——torch 相关模型用 lazy import，不会在包加载阶段就把 GPU 依赖拉进来；TFT 模型走独立的 `benchmark-tft` 可选依赖组。
    

## 数据接口

数据接口这块以前最容易编程脚本集合。一个数据源一个写法，一个 dumper 一套路由，最后每个人都能跑自己的版本，别人接手就要重新读一遍。

现在的做法是用适配器模式统一入口。`qlib.ext.data_sources.base` 定义了 `MarketDataAdapter` 抽象类，规定了几个核心方法：

```
class MarketDataAdapter(ABC):    def initialize(self) -> None: ...    def get_trading_dates(self, start, end) -> list: ...    def get_stock_list(self) -> list: ...    def get_stock_data(self, symbol, start, end, fields) -> pd.DataFrame: ...    def get_comprehensive_stock_data(self, symbol, start, end) -> pd.DataFrame: ...    def validate_connection(self) -> bool: ...    def get_available_fields(self) -> list[str]: ...
```

目前我们提供 rqdatac、TuShare、AKShare、Binance、Baostock、Yahoo 等适配器：

数据源

认证方式

免费

安装额外依赖

AKShare

无需认证

是

`pip install -e ".[data-akshare]"`

TuShare

Token

部分免费

`pip install -e ".[data-tushare]"`

RQDataC

用户名+密码

否

`pip install -e ".[data-rqdata]"`

Binance

可选 API Key

是

`pip install -e ".[data-binance]"`

统一入口是 `qlib-data-source`，第一次试用甚至不需要真实账号：

```
# 查看可用数据源qlib-data-source list# 用 smoke 数据源验证安装链路（只生成两天的模拟数据）qlib-data-source dump-all --source smoke --qlib-dir /tmp/qlib-smoke \  --start-date 2024-01-02 --end-date 2024-01-03 --max-workers 1# 从 AKShare 拉取真实数据pip install -e ".[data-akshare]"qlib-data-source dump-all --source akshare --qlib-dir ~/qlib_data/cn_data \  --start-date 2020-01-01 --end-date 2024-12-31
```

配置走分层机制：先读 `~/.quantml-qlib/config.yaml`，环境变量可以覆盖，单次命令可以用 `--config-file` 指定。这样凭证不用写进代码里，也不用在 shell 里到处 export：

```
# ~/.quantml-qlib/config.yamldata_source:default:akshareakshare:{}tushare:    token:"your-tushare-token"rqdatac:    username:"your-username"    password:"your-password"
```

脚本提供了 20+ 个独立的 CLI 入口（`qlib-yahoo`、`qlib-crypto`、`qlib-baostock-5min` 等），覆盖了 A 股、美股、巴西、加密、期货、基金等数据源。

## 因子挖掘

原本的qlib框架只支持alpha158，alpha360两种简单的因子结构，并且不支持任何因子挖掘算法，我们之前陆续加入了 GP、RL、LLM、TAlib、自定义算子等算法，但散落在不同地方。这次统一收进 `qlib.ext.factors`，提供 CLI 和脚本两种运行方式。

### 支持的因子挖掘算法

算法

实现位置

核心思路

CLI 子命令

GP 遗传规划

`gplearn/`

符号回归，搜索最优表达式树

`qlib-factor gp`

AlphaGen（RL）

`alphagen_*.py`

强化学习生成表达式，Transformer 策略网络 + MaskablePPO

脚本调用

AlphaGPT（LLM）

`alphagpt_framework.py`

 + `generation.py`

DeepSeek API 迭代生成/优化因子表达式

`qlib-factor alphagpt`

AlphaKAN

`alphakan/`

Kolmogorov-Arnold 网络做因子发现

脚本调用

AlphaNet v3

`alphanet_model.py`

端到端因子挖掘网络

脚本调用

TA-Lib 算子

`talib_ops.py`

技术分析算子注册到 Qlib 表达式系统

表达式内调用

### 快速上手

安装因子扩展：

```
pip install -e ".[factor]"
```

校验和评估一个因子表达式：

```
# 校验表达式语法（PowerShell 里表达式用单引号）qlib-factor validate --provider-uri D:/qlib_data/qlib_cn --expr 'Mean($close, 5)'# 计算 RankIC / ICIRqlib-factor eval --provider-uri D:/qlib_data/qlib_cn --market csi300 \  --start 2020-01-01 --end 2020-12-31 --expr 'Mean($close, 5)'
```

LLM 因子挖掘：

```
$env:DEEPSEEK_API_KEY="你的key"qlib-factor alphagpt --provider-uri D:/qlib_data/qlib_cn --market csi300 \  --start 2020-01-01 --end 2023-12-31 --mode optimize --expr 'Std($close, %d)/$close'
```

GP 遗传规划：

```
qlib-factor gp --provider-uri D:/qlib_data/qlib_cn --market csi300 \  --start 2020-01-01 --end 2023-12-31 \  --features '$open,$close,$high,$low,$volume' \  --generations 10 --population-size 500 --n-components 10
```

也可以用脚本方式运行（`scripts/factor_mining_example.py`），适合需要更细粒度控制的场景。

cli运行因子命令：

```
# 校验因子表达式，PowerShell 里表达式要用单引号qlib-factor validate --provider-uri D:/qlib_data/qlib_cn --expr 'Mean($close, 5)'# 评估 RankIC / ICIRqlib-factor eval --provider-uri D:/qlib_data/qlib_cn --market csi300 --start 2020-01-01 --end 2020-12-31 --expr 'Mean($close, 5)'# LLM因子挖掘$env:DEEPSEEK_API_KEY="你的key"qlib-factor alphagpt --provider-uri D:/qlib_data/qlib_cn --market csi300 --start 2020-01-01 --end 2023-12-31 --mode optimize --expr 'Std($close, %d)/$close'# GP 遗传规划挖因子qlib-factor gp --provider-uri D:/qlib_data/qlib_cn --market csi300 --start 2020-01-01 --end 2023-12-31 --features '$open,$close,$high,$low,$volume' --generations 10 --population-size 500 --n-components 10
```

### 评估体系

因子评估的核心在 `evaluator.py`，提供的不只是 RankIC 和 ICIR：

-   **表达式校验**：`validate_factor_expression()` 解析 Qlib 表达式语法，在跑数据之前就能发现语法错误
    
-   **RankIC / ICIR**：`evaluate_factor_frame()` 从 DataFrame 计算，`FactorEvaluator.evaluate()` 从 qlib 数据直接计算
    
-   **因子冗余过滤**：`filter_redundant_factors()` 基于互相关矩阵剔除高相关因子
    
-   **因子覆盖度**：`compute_factor_coverage()` 检查因子值的缺失情况
    
-   **因子换手率**：`compute_factor_turnover()` 评估因子稳定性
    
-   **权重优化**：`optimize_factor_pool_weights()` 最小二乘法优化因子池内权重
    

此外还有一套基于 Torch 的批量评估（`tensor_evaluator.py`），支持 GPU 加速计算。

## 模型运行： 25+ SOTA模型

所有模型配置在 `qlib/ext/benchmarks/configs/` 下，每个模型一个子目录：

模型

配置路径

DLinear

`workflow_config_dlinear_Alpha360.yaml`

DeepSeek Transformer（3 变体）

MLA / MoE / FlashMLA

Informer

`workflow_config_informer_Alpha360.yaml`

Autoformer

`workflow_config_autoformer_Alpha360.yaml`

iTransformer

`workflow_config_itransformer_Alpha360.yaml`

PatchTST

`workflow_config_patchtst_Alpha360.yaml`

TimesNet

`workflow_config_timesnet_Alpha360.yaml`

TimeMixer

`workflow_config_timemixer_Alpha360.yaml`

PITS

Alpha158 / Alpha360 两种

FactorVAE

Alpha158 / Alpha360 两种

KANGRU

Alpha158 / Alpha360 两种

Mamba

`workflow_config_mamba_Alpha360.yaml`

Kansformer

`workflow_config_kansformer_Alpha360.yaml`

DyT

`workflow_config_dyt_Alpha360.yaml`

LNN

`workflow_config_lnn_Alpha360.yaml`

minGRU

`workflow_config_mingru_Alpha158.yaml`

xLSTM

`workflow_config_xlstm_Alpha360.yaml`

TransformerMoE

`workflow_config_transformermoe_Alpha360.yaml`

TurboQuant

`workflow_config_turboquant_Alpha158.yaml`

Nonstationary Transformer

Alpha360

TCN / MASTER

包内实现

TFT

TensorFlow 实现

### 运行方式

原始 Qlib 的 examples 仍然保留。熟悉 Qlib 的用户可以继续用官方方式：

```
qrun examples/benchmarks/LightGBM/workflow_config_lightgbm_Alpha158.yaml
```

QuantML 新增的模型建议通过 `qlib-benchmark` 运行：

```
# 列出所有可用模型及其状态（packaged / missing-imports）qlib-benchmark list# 校验模型配置文件中引用的 module_path 是否都能正确导入qlib-benchmark validate# 运行指定模型qlib-benchmark run --model DLinear --config workflow_config_dlinear_Alpha360.yaml
```

`qlib-benchmark list` 会给每个模型标注状态：`packaged` 表示所有依赖就绪，`missing-imports` 表示需要安装额外的可选依赖（比如 torch）。这比之前直接 `qrun` 然后报 `ModuleNotFoundError` 要友好得多。

### 模型注册机制

`registry.py` 里的 `collect_benchmark_registry()` 会扫描配置目录、解析 YAML 里的 `module_path` 和 `class` 字段，然后做 AST 级别的静态分析（`inventory.py`），验证引用的类是否真的在目标模块里导出了。`smoke.py` 提供了一整套轻量级 mock 组件（`QRunSmokeDataset`、`QRunSmokeModel`、`SmokeRecorder`），可以在没有 MLflow、没有真实数据的情况下跑通模型实例化流程。

这意味着新增一个模型的时候，你不需要手动检查 YAML 里的路径对不对——`qlib-benchmark validate` 会替你做这件事。

## 安装：按需安装

这是用户反馈最多的问题。之前安装 QuantML-Qlib 会带入 torch、TA-Lib、数据库驱动、Dashboard 依赖、研究 notebook 依赖等一堆东西，很多用户只是想跑个 LightGBM 回测。pyproject.toml 里现在定义了 24 个可选依赖组，核心框架只需要一行安装：

```
# 创建环境conda create -n quantml-qlib python=3.12conda activate quantml-qlib
```

按需安装：

```
# 开发环境（lint、test 等工具）pip install -e ".[dev]"# 深度学习 + Boosting 模型pip install -e ".[torch,boosting]"# 因子挖掘pip install -e ".[factor]"# 特定数据源pip install -e ".[data-rqdata,data-tushare,data-akshare,data-binance,data-baostock]"# 实验管理pip install -e ".[workflow-mlflow]"
```

装完先验证：

```
make package-smoke
```

这个命令会跑一套轻量级检查，包括 smoke 数据源 dump、模型配置校验、CLI 入口可用性测试。如果全部通过，说明基础安装链路没问题。

## 开发规范：新增模块的标准流程

这次重构不只是整理已有代码，更重要的是，还制定了后续开发的规范。三个 contribution guide（数据/因子/模型） 已经写好了：

文档

适用场景

`docs/refactor/model-contribution-guide.md`

新增预测模型：实现 `qlib.model.base.Model` 接口、放到 `qlib.ext.benchmarks.models`、写 YAML config、注册到 models `__init__.py`

`docs/refactor/factor-contribution-guide.md`

新增因子算子：注册到 `FactorOperatorRegistry`、实现校验和评估、接入 GP/LLM 生成流程

`docs/refactor/data-adapter-guide.md`

新增数据源：实现 `MarketDataAdapter`、注册到 `DataInterfaceFactory`、配置分层读取、编写 CLI 子命令

一个完整的模型贡献流程大致是：

1.  在 `qlib/ext/benchmarks/models/` 下实现模型类
    
2.  在 `qlib/ext/benchmarks/configs/YourModel/` 下写 YAML workflow config
    
3.  在 `models/__init__.py` 添加 lazy alias
    
4.  跑 `qlib-benchmark validate` 确认路径正确
    
5.  跑 `qlib-benchmark run --model YourModel` 验证端到端
    

因子和数据源也有类似的标准化流程。对团队协作来说，这意味着无论是个人开发还是Vibe Coding， 任何新增模块只要按规范走，就能直接复用框架内的 CLI 入口、评估工具、数据适配器和实验管理。

## 建议

个人建议，如果你只是想找一个轻量的研究/回测脚本，QuantML-Qlib 会有点重。它更适合已经在用 Qlib、或者准备把 AI 模型、因子研究、数据融入长期研究流程的人。

**对模型研究员**——`qlib-benchmark` 提供了规范的模型注册和配置管理，新增模型有标准流程，不需要自己拼路径。

**对因子研究员**——表达式校验、RankIC/ICIR 评估、因子冗余过滤、换手率分析从零散脚本变成了统一工具链。挖掘算法（GP、RL、LLM、TA-Lib、自定义算子等）共享同一套评估框架，生成的因子可以直接比较。

**对需要接多数据源的人**——五个适配器共享同一个 dump 流程，切换数据源只需要改一个参数。凭证管理走分层配置，不用往代码里硬编码。

**对团队协作**——三份 contribution guide 定义了数据/因子/模型清晰的开发规范。`qlib-benchmark validate` 会在提交之前帮你检查配置正确性，而不是等到 CI 或者同事跑的时候才发现 YAML 路径写错了。

代码已经同步到Gitea服务器上的dev分支，欢迎使用。

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/001.jpg)