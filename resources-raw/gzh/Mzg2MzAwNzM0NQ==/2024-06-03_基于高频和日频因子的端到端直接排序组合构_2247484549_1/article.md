# 基于高频和日频因子的端到端直接排序组合构建模型

QuantML QuantML 2024-06-03 22:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=cf465c98540601a9f8840db341933d7b0be7f5e28ee92699515dc2c00f7587115975ce7261a1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=cf465c98540601a9f8840db341933d7b0be7f5e28ee92699515dc2c00f7587115975ce7261a1#rd)

Content

  

这篇论文提出了一个名为Direct Sorted Portfolio Optimization (DSPO)的端到端框架，用于构建直接排序的投资组合。论文介绍了在量化投资中构建基于特征排序的投资组合的重要性。传统方法存在手动设计复杂、预测与优化目标不一致的问题。作者提出了DSPO，这是一个直接从原始股票数据构建排序投资组合的框架。DSPO使用神经网络架构有效模拟时间步和可交易股票之间的依赖性。引入了新颖的单调逻辑回归损失函数，直接最大化构建最优排序投资组合的可能性。DSPO是首个能够处理来自原始多频数据的数千个可交易股票市场横截面的端到端方法。通过实证结果展示了DSPO的有效性，在纽约证券交易所(NYSE)和中国A股市场(A-Share)取得了显著的投资回报。

![](assets/001.png)

### **第1章：引言 (Introduction)**

-   投资组合构建是量化投资中的关键挑战，目标是在多样化的资产池中分配资本以最大化利润。
    
-   特征排序投资组合是一种基于特定特征对资产进行排序的方法，因其潜在的高回报和在成功投资策略中的关键作用而受到关注。
    
-   现有方法通常包括特征工程、建模和投资组合排序等步骤，但存在局限性，如特征工程需要专业知识，且特征可能因市场动态而迅速过时。
    
-   端到端学习提供了一种解决方案，能够适应数据分布的变化并直接优化特定目标。
    

### **第2章：相关工作与动机 (Related Works and Motivation)**

-   传统方法中的特征工程依赖于从多个来源提取特征，这些数据具有不同的更新频率。
    
-   深度学习在量化金融中的应用，包括CNN、RNN、LSTM和Transformer架构等，提高了预测能力。
    
-   深度学习在排名应用中非常有效，但在股票预测中存在局限性，如成对排名损失不是最大似然估计器，导致内存需求高和训练不稳定。
    
    ![](assets/002.png)
    

### **第3章：方法论 (Methodology)**

本章详细介绍了DSPO模型的构建和工作原理：

### **3.1 问题阐述 (Problem Formulation)**

-   输入数据：由高频市场数据和每日基础数据组成，表示为X = {x1, x2, ..., xn}。每个数据点xi包括高频(xhf\_i)和低频(xlf\_i)两个部分。
    
-   高频数据：例如分钟频率的价格（最高价、最低价、开盘价、收盘价）和买卖价差。
    
-   低频数据：例如市盈率、市净率、PEG比率和周转率等基本面数据。
    
-   目标：设计一个神经网络模型，通过处理这些数据来预测一个得分S ∈ RN，其中N是活跃股票的数量。预测得分的目的是保持未来真实回报的排序。
    

### **3.2 模型架构 (Model Architecture)**

-   股票多频融合模块 (Stock-wise Multi-Frequency Fusion Module)：该模块旨在捕获并整合每只股票的多频时序动态，将高频数据通过卷积操作来描绘时间关系，然后通过线性投影到一个中间的高频嵌入空间。
    
-   股票间变换器模块 (Inter-Stock Transformer Module)：设计用于模拟同一市场横截面内所有可交易资产之间的相互依赖性，使用自注意力机制来建模。
    

### **3.3 单调逻辑回归损失函数 (Monotonic Logistic Regression Loss for Stable Optimization)**

-   问题定义：将预测回报X与实际回报Y相关联，目标是最大化单调函数描述X和Y之间关系的可能性，从而构建最优排序的投资组合。
    
-   损失函数推导：通过使用双曲正切函数作为平滑替代符号函数，来增强优化和数值稳定性。
    
-   损失函数公式：定义了期望损失函数，反映了不同市场横截面的预期表现。
    

### **3.4 横截面子采样策略 (Cross-Sectional Sub-Sampling)**

-   策略目的：解决由于市场横截面数据量有限而导致的训练不稳定和过拟合问题。
    
-   策略方法：通过从数据集中随机选择m个不同的交易日来形成m个横截面，然后从这些横截面中随机选择k只股票来创建一个训练小批量样本。
    

### **3.5 实验设置 (Experimental Settings)**

-   实验框架：围绕日内交易，从超过4000只股票中选择顶部和底部10%构建排序投资组合。
    
-   模型训练策略：使用历史数据进行模型训练，并采用滚动重训练方法。
    
-   数据收集与预处理：通过专业渠道收集数据，包括高频交易信号和从财务报告中提取的低频数据，并进行了标准化处理。
    

### **3.6 评估指标 (Evaluation Metrics)**

-   评估方法：使用基于排名的指标（RankIC和RankICIR）和基于投资组合的指标（累积回报和信息比率IR）来评估模型。
    

### **第4章：实验 (Experiments)**

本章详细描述了DSPO模型的实验设置、数据收集、基线比较、评估指标以及实验结果：

### **4.1 实验设置 (Experimental Settings)**

-   数据来源：介绍了数据来源，包括从polygon.io收集的NYSE数据和通过专业渠道获取的A-Share数据。
    
-   数据预处理：对高频数据进行标准化，对低频数据进行MinMax标准化，范围从0到1，并排除了10天内无交易量的股票。
    
-   模型训练策略：为NYSE使用2020至2022年的数据进行模型训练，并在2023年进行评估；A-Share市场使用2018至2020年的数据进行训练，并在2021年直接部署。
    

### **4.2 主要结果 (Main Results)**

-   性能比较：使用不同的基线模型与DSPO进行比较，包括基于特征工程的方法、时间序列预测模型、回归模型和分类模型等。
    
-   评估指标：使用RankIC、RankICIR、累积回报和信息比率(IR)等指标评估模型性能。
    
    ![](assets/003.png)
    
    ![](assets/004.png)
    
-   结果展示：表格展示了不同模型在A-Share和NYSE市场的表现，DSPO在所有指标上均优于其他模型。
    

### **4.3 案例研究 (Case Studies)**

-   适应性测试：测试了DSPO对市场变化的适应性，尤其是在传统工程特征可能随时间退化的情况下。
    
-   稳定性测试：通过多次实验来评估DSPO在不同运行中的稳定性，与DIN和CNN模型进行了比较。
    

### **4.4 消融研究 (Ablation Studies)**

-   模块有效性：通过移除DSPO模型中的某些模块，来评估每个组件对整体性能的贡献。
    
-   子采样策略影响：研究了子采样策略对模型性能的影响，特别是对子采样股票数量的敏感性分析。
    
-   初始资本对性能的影响：分析了不同初始资本规模对模型性能的影响，包括累积回报、信息比率和最大回撤等指标。
    

### **第5章：局限性与未来工作 (Limitations and Future Work)**

-   讨论了DSPO在处理不同投资规模和市场动态（如流动性和风险敞口）方面的局限性。
    
-   建议未来的研究应专注于将风险管理策略整合到DSPO框架中，以提高模型在不同市场条件下的适应性和适用性。
    

### **第6章：结论 (Conclusion)**

-   论文总结了DSPO框架的主要贡献，强调了其在整合高频市场数据和每日基础数据方面的创新性，以及在现代金融市场复杂性管理方面的鲁棒性。
    

  

  

  

目前距离星球下次提价还有20个名额，欢迎扫码加入：

![](assets/005.jpg)

  

  

入群请扫我：  

![](assets/006.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
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

![](assets/007.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/008.jpg)