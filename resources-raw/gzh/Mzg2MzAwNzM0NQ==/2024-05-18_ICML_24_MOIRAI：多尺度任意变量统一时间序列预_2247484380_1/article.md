# ICML 24 | MOIRAI：多尺度任意变量统一时间序列预测预训练模型

QuantML QuantML 2024-05-18 17:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484380&idx=1&sn=fb03570b4d5b7d16dfac59e135df0cdb&chksm=cf08e2a4450f0d00293824a54273bc6db633dc42d9fd060a59fc6e51b25e6d4136aaf6bafc89#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484380&idx=1&sn=fb03570b4d5b7d16dfac59e135df0cdb&chksm=cf08e2a4450f0d00293824a54273bc6db633dc42d9fd060a59fc6e51b25e6d4136aaf6bafc89#rd)

Content  

> 论文地址：https://arxiv.org/abs/2402.02592

  

作者提出了一种新型的深度学习模型MOIRAI，用于时间序列预测。MOIRAI模型的架构设计考虑了时间序列数据的多样性和复杂性，通过创新的多尺度处理、任意变量注意力机制和灵活的混合分布预测，实现了对多种时间序列预测任务的有效建模。

### **摘要**

传统的时间序列预测通常是基于单个数据集构建模型，这限制了大型预训练模型在该领域的应用潜力。为了克服这一限制，作者提出了一种通用预测的概念，即通过在大量时间序列数据集上进行预训练，构建一个能够处理多样化下游预测任务的大型时间序列模型（称为MOIRAI）。这种模型面临几个挑战：跨频率学习、处理任意数量变量的多变量时间序列以及应对大规模数据中固有的分布属性变化。

![](assets/001.png)

### **引言**

作者讨论了当前深度学习在时间序列预测方面的局限性，并提出了一个革命性的概念——通用预测器。这种预测器是一个大型预训练模型，能够处理任何时间序列预测问题。

### **相关工作**

论文回顾了零样本预测、时间序列预测的预训练与微调方法，以及大型语言模型在时间序列预测中的应用。

### **方法**

作者定义了一个时间序列数据集，并提出了预测分布的目标，通过学习模型来预测分布参数。

#### **架构**

MOIRAI模型的架构是这篇论文的核心创新之一，旨在处理时间序列预测任务的复杂性。以下是对MOIRAI模型架构的详细介绍：

### **I. 模型概述**

MOIRAI（Masked EncOder-based UnIveRsAl TIme Series Forecasting Transformer）是一个基于Transformer的时间序列预测模型，它通过预训练和微调来提高对各种时间序列预测任务的泛化能力。

![](assets/002.png)

  

### **II. 核心组件**

####     **2.1 多尺度输入输出投影层（Multi Patch Size Projection Layers）**

-   目的：处理不同频率的时间序列数据，因为不同频率的数据具有不同的模式和特性。
    
-   方法：为不同的频率定义不同的补丁（patch）大小，学习多个输入和输出投影层，每个层对应一个特定的补丁大小。
    
-   实现：使用线性层将不同大小的补丁映射到隐藏状态空间，然后根据需要将隐藏状态映射回分布参数。
    

####     **2.2 任意变量注意力（Any-variate Attention）**

-   目的：使模型能够处理任意数量的变量（即多变量时间序列），并考虑变量之间的交互。
    
-   方法：将多变量时间序列“展平”为单个序列，并引入新的编码方式以区分不同的变量。
    
-   实现：使用二元注意力偏置和旋转位置嵌入（RoPE）来编码时间和变量轴，确保模型能够处理任意数量的变量，并且对变量的排列顺序具有置换等变性。
    

####     **2.3 混合分布（Mixture Distribution）**

-   目的：为了提供灵活的预测分布，以适应不同数据集的分布特性。
    
-   方法：使用参数分布的混合，允许模型预测多种分布的参数，以更好地拟合实际数据。
    
-   实现：预测一个由多个组件组成的混合分布的概率密度函数（pdf），每个组件可以是不同的参数分布，如Student’s t-distribution、负二项分布、对数正态分布和低方差正态分布。
    

### **III. 架构细节**

-   掩码编码器：MOIRAI采用了非重叠的基于补丁的方法来模拟时间序列，使用掩码编码器架构来处理输入序列。
    
-   变换器模块：核心Transformer模块是一个仅编码器（encoder-only）的Transformer架构，利用了最新的大型语言模型（LLM）架构改进。
    
-   预归一化：在Transformer层中使用预归一化，并用RMSNorm代替所有LayerNorms。
    
-   查询-键归一化：应用查询-键归一化来提高模型性能。
    
-   SwiGLU激活函数：在前馈网络（FFN）层中使用SwiGLU激活函数。
    
-   无偏置：在Transformer模块的所有层中省略偏置。
    

### **IV. 预训练和微调**

-   预训练：作者介绍了一个新的大规模开放时间序列数据集（LOTSA），包含超过27亿条观测数据，涵盖九个领域。如能源、交通、气候等。LOTSA旨在支持大型时间序列模型（LTMs）的预训练。
    
-   微调：在特定的下游任务上微调预训练模型，以适应特定数据集的特性。
    

### **V. 训练策略**

-   序列打包：为了提高训练效率，使用序列打包技术来处理不同长度的时间序列。
    
-   优化器：使用AdamW优化器进行模型训练，并采用线性预热和余弦退火的学习率调度策略。
    

MOIRAI模型的架构设计考虑了时间序列数据的多样性和复杂性，通过创新的多尺度处理、任意变量注意力机制和灵活的混合分布预测，实现了对多种时间序列预测任务的有效建模。

### **实验**

作者在Monash基准测试和未见过的目标数据集上对MOIRAI进行了评估，展示了其在零样本设置下与全样本基线相比具有竞争力或更优越的性能。

![](assets/003.png)

![](assets/004.png)

### **贡献**

-   提出了一种新的Transformer架构，支持通用预测的需求。
    
-   引入了LOTSA数据集和统一训练库UNI2TS，并将它们完全开源。
    
-   证明了MOIRAI在LOTSA数据上训练后，作为零样本预测器与全样本模型相比具有竞争力或更优越的性能。
    

### **结论**

MOIRAI作为一个通用的时间序列预测Transformer，解决了传统预测范式中的问题，并在各种设置下展示了其有效性。作者还讨论了未来的工作方向，包括超参数调整技术、更灵活的跨频率学习策略、对高维时间序列的支持、数据集的多样化以及多模态输入的融合。

  

  

  

论文及代码下载见星球，星球人数已超过100人，星球内有各种有趣的研究，包括因子，模型，框架代码等。送十张优惠券，数量有限，欢迎扫码加入交流：  

  

![](assets/005.png)

  

  

入群请扫我：  

![](assets/006.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)  
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)  
    
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
    
      
    
-   [ICML 24 | 揭示线性时间序列预测模型中的简约之美](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484349&idx=1&sn=264a5c0eaeca44ef9f2e182edb3d6b6d&chksm=ce7e64a3f909edb5ed36d1601db36c4a56c644d431e79db556e6a1337d30021a141b4c30edfa&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
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