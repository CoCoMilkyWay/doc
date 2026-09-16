# WWW 24 | 大型语言模型+强化学习生成可解释的股票预测

QuantML QuantML 2024-05-31 22:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484523&idx=1&sn=5591e8a834b65527fcdd3e360e988a39&chksm=cff8eed4f9403722d48547277b381613f865944513171933a47cf5e62c913346fdaa18a9f6c6#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484523&idx=1&sn=5591e8a834b65527fcdd3e360e988a39&chksm=cff8eed4f9403722d48547277b381613f865944513171933a47cf5e62c913346fdaa18a9f6c6#rd)

Content  

  

本文提出了一个名为SEP（Summarize-Explain-Predict）的框架，旨在利用大型语言模型（LLMs）生成可解释的股票预测。

### **引言（Introduction）**

-   背景：传统深度学习模型在股票预测方面存在局限性，主要是它们像“黑箱”一样，无法提供决策过程的解释。
    
-   挑战：股票预测对于LLMs来说是一个挑战，因为需要权衡社会文本对股票价格的不同影响。
    
-   问题：在训练LLMs进行股票预测时，需要大量的专家注释样本，这在实践中成本高昂且难以扩展。
    
-   SEP框架：提出了SEP框架，通过自我反思的代理和近端策略优化（PPO）技术，使LLM能够自主学习如何生成可解释的股票预测。
    
    ![](assets/001.png)
    

### **相关工作（Related Works）**

-   文本分析在股票预测中的应用：从早期的简单文本表示方法发展到利用深度神经网络的结构化信息。
    
-   注意力模型：用于直接从预训练文本嵌入中捕获文本中最重要的信息。
    
-   大型语言模型在金融领域的应用：探索了LLMs在金融任务中的应用，如BloombergGPT和其他针对金融领域微调的LLMs。
    

### **方法论（Methodology）**

本章详细介绍了SEP（Summarize-Explain-Predict）框架的设计和实现，该框架旨在生成可解释的股票预测。该框架通过结合文本摘要、自我反思和强化学习技术，使得LLM能够自主学习如何生成可解释的股票预测。SEP框架的创新之处在于它允许模型自我改进，而无需昂贵且难以扩展的人类注释样本，这对于提高股票预测的透明度和可信度具有重要意义。

![](assets/002.png)

### 3.1 预备知识（Preliminaries）

-   问题定义：明确了任务是给定一只股票及其相关文本资料，目标是生成下一个交易日的股票价格运动预测以及相应的可读解释。
    
-   数据收集和聚类：介绍了如何构建数据集，包括从Twitter API收集推文数据，并使用BERTopic聚类技术来识别每天的代表性推文。
    

### 3.2 摘要生成（Summary Generation）

-   目标：从非结构化文本输入中生成事实信息的摘要。
    
-   方法：利用大型语言模型（LLMs）的摘要能力，将连续几天的原始文本转换为点式摘要。
    

### 3.3 解释生成（Explanation Generation）

-   目标：生成股票预测的清晰解释，并通过自我反思过程改进这些解释。
    
-   解释提示：设计了提示，使得LLM能够根据提取的信息序列生成包含价格运动和解释的响应。
    
-   自我反思过程：通过迭代的自我反思循环，LLM能够根据先前的输入和输出改进其预测。这个过程包括生成反馈、反思失败原因，并提出改进措施。
    
    ![](assets/003.png)
    

### 3.4 预测生成（Prediction Generation）

-   模型微调：使用三步过程微调LLM，包括监督式微调（SFT）、奖励模型训练和PPO强化学习。
    

-   监督式微调：使用正确预测的样本训练一个监督策略。
    
-   奖励模型：使用正确与错误的响应对训练一个奖励模型，该模型学会给正确响应更高的奖励分数。
    
-   PPO强化学习：使用奖励模型优化训练策略，通过最大化整体奖励来训练PPO模型。
    
    ![](assets/004.png)
    

-   基于置信度的采样：在推理过程中，首先使用预训练的LLM对输入文本进行摘要，然后使用训练好的策略生成预测，并通过奖励模型的分数选择最佳响应。
    

### **实验（Experiment）**

### 4.1 实验设置（Experimental Settings）

-   基线比较：SEP模型与传统的深度学习模型和大型语言模型（LLMs）进行比较，包括VAE+Attention、GRU+Attention、Transformer以及GPT-3.5-turbo和Vicuna-7b-v1.5等。
    
-   评估指标：使用预测准确性和Matthews相关系数（MCC）作为评估指标，以衡量模型性能。
    
-   实施细节：介绍了用于生成响应的不同模型，包括OpenAI GPT-3.5-turbo-16k和Vicuna-13b-v1.5-16k，并详细说明了训练和推理过程中的参数设置。
    

### 4.2 性能比较（Performance Comparison）

-   预测性能：通过定量结果展示了SEP模型在股票预测任务上的表现，并与传统深度学习和LLM方法进行比较。
    
-   解释性能：定性比较了预训练的LLMs和SEP模型生成的解释质量，并提出了一套评价指标来衡量解释的质量。
    

### 4.3 消融研究（Ablation Study）

-   摘要模块：评估了摘要模块对性能的影响，比较了使用原始文本和经过摘要的文本作为输入时的性能差异。
    
-   解释模块：展示了解释模块通过自我反思过程生成正确和决定性预测样本的能力。
    
-   预测模块：通过不同变体的模型进行了消融研究，移除了模型的一些组件，以评估每个组件对整体性能的贡献。
    

### 4.4 投资组合优化（Portfolio Optimization）

-   泛化能力：进一步测试了SEP框架在投资组合构建任务中的泛化能力，通过微调LLM来为股票投资组合生成权重。
    
-   投资组合性能：比较了由不同LLMs生成的投资组合的表现，并与几个基准投资组合进行了对比，使用了整体收益、累积收益、标准差和年化夏普比率等指标进行评估。
    

### 4.5 结果分析

-   预测准确性：SEP模型在预测准确性和MCC上都优于基线模型。
    
-   解释质量：SEP模型在生成解释的质量上也显示出优势，特别是在一致性、清晰度和与信息的一致性方面。
    
-   泛化能力：在投资组合优化任务中，SEP模型生成的投资组合在多数评估指标上优于其他方法。
    
    ![](assets/005.png)
    
    ![](assets/006.png)
    

### **结论和未来工作（Conclusion and Future Work）**

-   结论：SEP框架有效地提高了股票预测的准确性和解释质量。
    
-   未来工作：提出了可能的未来研究方向，如减少累积错误、使用额外数据源提高预测质量，以及改进评估生成的股票解释的指标。
    

  

  

  

  

论文及代码下载见星球。

  

加入星球请扫我：

![](assets/007.jpg)

  

  

入群请扫我：  

![](assets/008.jpg)

  

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

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)