# QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo

QuantML QuantML 2024-12-17 18:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&chksm=cfa8a6d053d4f131aa2b69695335976ff10e0afc759ae5150b961271358532a89350ef376039#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&chksm=cfa8a6d053d4f131aa2b69695335976ff10e0afc759ae5150b961271358532a89350ef376039#rd)

![](assets/001.png)

在之前的文章中，我们介绍过如何在 qlib 中通过自定义算子来高效优雅地实现筹码因子、切割动量因子、锚定反转因子等的计算。

本文我们将介绍如何将 TA-Lib 中的 100+ 算子融入 QuantML-Qlib 中，从而大幅拓展 qlib 算子库，轻松实现各类指标及形态的计算，为后续模型增添更多类型的因子。

## TA-Lib

`TA-Lib`（Technical Analysis Library）是一个广泛应用于金融数据技术分析的 Python 库。它提供了超过 100 种技术分析指标以及形态，包括 ADX、MACD、RSI、布林带、动量指标、KDJ 指标等。

### 主要功能

-   **技术指标**：包括动量指标、成交量指标、波动率指标、趋势指标、周期指标等。
    
-   **K线形态识别**：识别 K 线图中的各种形态，如双顶、双底、锤子线、吊颈线等。
    
-   **多时间框架分析**：支持不同时间框架的数据分析。
    
-   **高效计算**：底层使用 C 语言实现，计算速度快。
    

接口文档以及算子介绍参考：HuaRongSAO/talib-document: talib学习 talib中文翻译 talib中文文档

## qlib实现

为了在 qlib 中实现 talib 算子，我们在 qlib/data/ops.py 中加入动态 class 生成函数 `create_talib_class`，将 talib 中的算子转换为 qlib 中的算子类型。这里需要注意的是，qlib 本身的算子一般只支持单 feature 或双 features，而 talib 中的算子不仅有单一变量输入（如 RSI），还有多变量输入的算子。例如，在计算两只乌鸦形态时，需要用到高开低收四个 feature。因此在定义算子 class 时，需要支持不定长度的输入。对于多输出（如 MACD），需要根据实际需求进行取舍或分别定义输出列。

将所有算子注册后，我们就可以在 qlib 中轻松实现各类技术指标及形态的计算。在计算因子时，可以采用 D.feature 批量计算，也可以将所有因子写入一个新的 handler 中。qlib 默认构建了 alpha158 和 alpha360 两套因子库，结构都比较简单。我们可以用相同的方法构建 alphazoo，将所有因子表达式加入其中，在之后的 config 文件中便可调用直接用于后续模型训练。

具体构造方式如下，在qlib/contrib/data/handler.py中加入以下代码：

```
class AlphaZoo(DataHandlerLP):    def __init__(        self,        instruments="csi500",        start_time=None,        end_time=None,        freq="day",        infer_processors=[],        learn_processors=_DEFAULT_LEARN_PROCESSORS,        fit_start_time=None,        fit_end_time=None,        process_type=DataHandlerLP.PTYPE_A,        filter_pipe=None,        inst_processors=None,        **kwargs    ):        infer_processors = check_transform_proc(infer_processors, fit_start_time, fit_end_time)        learn_processors = check_transform_proc(learn_processors, fit_start_time, fit_end_time)        data_loader = {            "class": "QlibDataLoader",            "kwargs": {                "config": {                    "feature": self.get_feature_config(),                    "label": kwargs.pop("label", self.get_label_config()),                },                "filter_pipe": filter_pipe,                "freq": freq,                "inst_processors": inst_processors,            },        }        super().__init__(            instruments=instruments,            start_time=start_time,            end_time=end_time,            data_loader=data_loader,            infer_processors=infer_processors,            learn_processors=learn_processors,            process_type=process_type,            **kwargs        )    def get_feature_config(self):        conf = {            "kbar": {},            "price": {                "windows": [0],                "feature": ["OPEN", "HIGH", "LOW", "VWAP"],            },            "rolling": {},        }        return self.parse_config_to_fields(conf)    def get_label_config(self):        return ["Ref($close, -2)/Ref($close, -1) - 1"], ["LABEL0"]    @staticmethod    def parse_config_to_fields(config):        """create factors from config        config = {            'kbar': {}, # whether to use some hard-code kbar features            'price': { # whether to use raw price features                'windows': [0, 1, 2, 3, 4], # use price at n days ago                'feature': ['OPEN', 'HIGH', 'LOW'] # which price field to use            },            'volume': { # whether to use raw volume features                'windows': [0, 1, 2, 3, 4], # use volume at n days ago            },            'rolling': { # whether to use rolling operator based features                'windows': [5, 10, 20, 30, 60], # rolling windows size                'include': ['ROC', 'MA', 'STD'], # rolling operator to use                #if include is None we will use default operators                'exclude': ['RANK'], # rolling operator not to use            }        }        """        fields = []        names = []        field = [ 'RSI($close, 30)', 'SMA($close, 30)/$close', 'T3($close, 30)/$close', 'PPO($close, 30)',]        name = ['RSI', 'SMA', 'T3', 'PPO']        fields += field        names += name        field = [ 'CDL2CROWS($open, $high, $low, $close, 30)', ]        name = ['CDL2CROWS', ]        fields += field        names += name        return fields, names
```

上例中，我们在alphazoo中加入了'RSI', 'SMA', 'T3', 'PPO'技术指标以及‘CDL2CROWS’形态，具体调用方法参考examples/tutorial/talib\_workflow.ipynb：

```
from qlib.contrib.data.handler import Alpha158, AlphaZoohz = AlphaZoo(**handler_kwargs)
```

即可计算得到相关的因子值。

相关代码已更新至QuantML-Qlib中，QuantML-Qlib已经支持40+前沿机器学习模型（DLinear,PatchTST,iTransformer,LNN,Mamba,KAN,xLSTM等）以及各种因子挖掘（GP, RL, GPT）算法，欢迎加入星球获取源代码交流学习。

  

  

![](assets/002.png)