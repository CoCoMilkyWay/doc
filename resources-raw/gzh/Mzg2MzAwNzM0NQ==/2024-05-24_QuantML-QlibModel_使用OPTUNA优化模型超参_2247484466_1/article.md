# QuantML-QlibModel | 使用OPTUNA优化模型超参

QuantML QuantML 2024-05-24 19:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=cf5ac408ea151301861ddc2c122b91a2679c7a37684e68aa64761f5ff2de8f5354d35466d72e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=cf5ac408ea151301861ddc2c122b91a2679c7a37684e68aa64761f5ff2de8f5354d35466d72e#rd)

![](assets/001.png)

框架介绍

![](assets/001.png)

  

![](assets/002.png)

  

> Optuna 是一个特别为机器学习设计的自动超参数优化软件框架。它具有命令式的，define-by-run 风格的 API。由于这种 API 的存在，用 Optuna 编写的代码模块化程度很高，Optuna 的用户因此也可以动态地构造超参数的搜索空间。
> 
> https://zh-cn.optuna.org/index.html

  

Optuna 是一个用于自动化机器学习流程（包括超参数优化）的开源框架。旨在帮助研究人员和数据科学家找到最优的模型超参数，以提高模型性能。Optuna 的特点在于：

1.  自动超参数搜索：Optuna 支持多种搜索算法，包括网格搜索、随机搜索、贝叶斯优化、遗传算法等，以自动寻找最优的超参数组合。
    
2.  易于集成：Optuna 可以轻松集成到现有的机器学习代码中，用户只需少量代码更改即可开始使用。
    
3.  可扩展性：Optuna 支持多进程和分布式计算，可以利用多核处理器和多台机器进行大规模的超参数搜索。
    
4.  多种目标函数：用户可以针对不同的优化目标（如准确率、召回率等）进行搜索，Optuna 会找到最大化或最小化目标函数的超参数。
    
5.  实时监控：Optuna 提供了实时监控功能，用户可以在优化过程中实时查看每个试验的中间结果。
    
6.  中断和恢复：Optuna 允许用户中断优化过程，并在之后恢复，这在长时间运行的优化任务中非常有用。
    
7.  集成多种库：Optuna 可以与多种机器学习库（如 scikit-learn、XGBoost、LightGBM、TensorFlow 和 PyTorch）一起使用。
    
8.  鲁棒性：Optuna 设计了异常处理机制，可以处理优化过程中可能出现的异常，确保优化过程的鲁棒性。
    
9.  可视化：Optuna 提供了多种可视化工具，帮助用户分析优化历史和结果，如并发视图、轮廓图等。
    
10.  社区支持：作为一个开源项目，Optuna 拥有活跃的社区，用户可以从社区获得帮助和支持。
     

  

使用 Optuna 的基本流程如下：

-   定义目标函数：编写一个目标函数，该函数接受超参数作为输入，并返回一个需要优化的目标值（如验证集上的损失）。
    
-   创建试验：使用目标函数创建一个 Optuna 试验。
    
-   选择搜索算法：选择一个超参数搜索算法。
    
-   运行优化：调用 Optuna 的 `optimize` 方法开始优化过程。
    
-   获取最佳结果：优化完成后，获取最优的超参数组合。
    

  

code example：

```
import optunadef objective(trial):    x = trial.suggest_float('x', -10, 10)    return (x - 2) ** 2study = optuna.create_study()study.optimize(objective, n_trials=100)study.best_params  # E.g. {'x': 2.002108042}
```

  

Optuna 的教程参考官方文档：Tutorial — Optuna 3.6.1 documentation（https://optuna.readthedocs.io/en/stable/tutorial/index.html）

  

![](assets/001.png)

使用介绍

![](assets/001.png)

  

本文重点介绍如何在QuantML-Qlib/Qlib中使用optuna对各模型超参进行优化。

以Lightgbm超参优化为例，在QuantML-Qlib的examples/hyperparameter/LightGBM目录之下，提供了两份python文件：hyperparameter\_158\_basic.py和hyperparameter\_158\_comprehensive.py。两份代码都支持并行运行，对原始代码的bug进行了修复，以及增加了代码对于后续版本的兼容性。

其中basic代码仅保存优化参数以及最终结果，适合第一步大批量快速超参寻优。

comprehensive提供了更多的功能，包括自定义config文件，中间变量输出，增加信号ICIR计算，回测，保存运行结果，输出trial的统计结果等等，适合在第一步运行完成basic之后，精细调参。

在运行代码之前，首先创建optuna的数据库：

```
optuna create-study --study LGBM_158 --storage sqlite:///db.sqlite3
```

`   `

注意这里的命令需要在examples/hyperparameter/LightGBM目录下运行，运行完成之后会在目录下创建db.sqlite3文件，超参优化的最终结果均保存在此文件之中，LGBM\_158为study name，根据不同配置选择不同的名称。

创建完成之后，在python代码之中对参数范围进行调节：

task = {  
    "model": {  
        "class": "LGBModel",  
        "module\_path": "qlib.contrib.model.gbdt",  
        "kwargs": {  
            "loss": "mse",  
            "colsample\_bytree": trial.suggest\_float("colsample\_bytree", 0.5, 1),  
            "learning\_rate": trial.suggest\_float("learning\_rate", 0, 1),  
            "subsample": trial.suggest\_float("subsample", 0, 1),  
            "lambda\_l1": trial.suggest\_float("lambda\_l1", 1e-8, 1e4, log\=True),  
            "lambda\_l2": trial.suggest\_float("lambda\_l2", 1e-8, 1e4, log\=True),  
            "max\_depth": 10,  
            "num\_boost\_round": 1000,  
            "num\_leaves": trial.suggest\_int("num\_leaves", 1, 1024),  
            "feature\_fraction": trial.suggest\_float("feature\_fraction", 0.4, 1.0),  
            "bagging\_fraction": trial.suggest\_float("bagging\_fraction", 0.4, 1.0),  
            "bagging\_freq": trial.suggest\_int("bagging\_freq", 1, 7),  
            "min\_data\_in\_leaf": trial.suggest\_int("min\_data\_in\_leaf", 1, 50),  
            "min\_child\_samples": trial.suggest\_int("min\_child\_samples", 5, 100),  
        },  
    },  
}

  

在运行时选择相应的job数量以及trial次数：

study.optimize(objective, n\_jobs\=3, n\_trials\=10)  

  

每次trial均会得到一组超参对应的结果，最终所有结果可以利用optuna\_dashborad在前端网页进行展示，运行命令：

optuna-dashboard --port 5000 --host localhost sqlite:///db.sqlite3

打开网页http://localhost:5000可查看运行结果：

![](assets/003.png)

每个点代表一次trial对应的结果。

![](assets/004.png)

每条线代表参数和结果的对应关系。

  

![](assets/005.png)

这张图比较重要，代表了超参的重要性。

  

![](assets/006.png)

  

超参与结果之间的关系图。

  

![](assets/007.png)

![](assets/008.png)

每次运行结果的保存，点开之后可以展示详细信息。

  

优化其他模型与Lightgbm类似，只要选择相应的config文件，在objective中配置相应的参数搜索空间即可，相关代码已在QuantML-Qlib中更新。

  

目前QuantML-Qlib支持以下模型：

![](assets/009.png)

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

加星球请扫我：

![](assets/010.jpg)

入群请扫我：

![](assets/011.webp)

  

往期回顾

       QuantML-Qlib开发版：

  

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

  

-   [对抗性注意力LSTM模型提高股票价格变动预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484439&idx=1&sn=73843970e730f6ba2a81e9df63124c1a&chksm=ce7e6309f909ea1fac102908400572b02f62d96c901d1517b52d2b2fc85da4a04832720af700&scene=21#wechat_redirect)
    
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

![](assets/012.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/013.jpg)

  

  

  

![](assets/014.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/014.gif)