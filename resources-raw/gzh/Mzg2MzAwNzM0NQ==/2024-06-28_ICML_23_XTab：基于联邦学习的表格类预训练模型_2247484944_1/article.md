# ICML 23 | XTab：基于联邦学习的表格类预训练模型

QuantML QuantML 2024-06-28 21:18 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484944&idx=1&sn=3301b97ec2256efc831967f00019cdfd&chksm=cfc2ffb052822a39e2e5b943f41961f3e3d52e8e14c0f85400ff9e9731b7090688c4363538b2#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484944&idx=1&sn=3301b97ec2256efc831967f00019cdfd&chksm=cfc2ffb052822a39e2e5b943f41961f3e3d52e8e14c0f85400ff9e9731b7090688c4363538b2#rd)

Content

  

XTab是一种用于tabular transformers的跨表格预训练方法，旨在解决现有表格自监督学习模型在处理多表格数据时的局限性，特别是它们在泛化到新表格上的能力不足的问题。作者提出了一个新颖的框架，通过利用独立的特征提取器和联邦学习技术来预训练共享组件，以处理不同表格间的列类型和数量的不一致性。

XTab框架在OpenML-AutoML Benchmark（AMLB）上的84个表格预测任务中进行了测试，证明了其在提高多种tabular transformers的泛化能力、学习速度和性能方面的有效性。具体来说，通过XTab预训练的FT-Transformer在回归、二元分类和多类分类等任务上，相较于其他最先进的表格深度学习模型，展现出了卓越的性能。

这项工作不仅提出了一种新的预训练方法，而且还展示了跨表格预训练能够显著提升tabular transformers在未见过的表格上的表现，为表格数据的深度学习应用开辟了新的可能性。

  

### **第 1 章：引言 (Introduction)**

### 本章主要介绍了表格数据在机器学习中的重要性和应用基础，以及表格深度学习模型相较于传统基于树的模型在实际使用中的局限性。

### 作者指出，尽管深度学习在计算机视觉和自然语言处理领域取得了巨大成功，但在表格数据上的应用却面临挑战，主要是因为表格数据的多样性和数据特定性给模型的泛化能力带来了困难。

### 此外，引言还讨论了自监督学习在表格数据上的潜力，以及如何借鉴计算机视觉和自然语言处理领域的自监督预训练技术来提升表格深度学习模型的性能。作者强调了跨表格预训练的必要性，以及XTab框架如何通过独立的特征提取器和联邦学习来解决表格数据不一致的挑战，从而提高模型在新表格上的泛化能力和学习效率

###   

### **第 2 章：相关工作 (Related work)**

-   作者回顾了表格自监督学习的相关研究，指出了现有方法的局限性，即大多数方法仅在同一领域内的数据上进行预训练，导致模型缺乏泛化能力。例如，Yoon等人（2020）和Ucar等人（2021）提出了基于自编码器框架的方法，通过重建表格中缺失部分的预文本任务来实现自监督学习。Bahri等人（2021）则采用了对比学习作为预训练目标，扩展了SimCLR框架到表格任务。
    
-   论文探讨了tabular transformers模型的发展，这些模型受到自然语言处理中注意力机制成功的启发，被适配到表格数据上。例如，FT-Transformer通过将表格列视为类似于句子中的单词的标记，展示了在表格分类/回归任务上的优越性能。Saint模型引入了行注意力机制，而Fastformer提出了一种具有线性复杂度的轻量级注意力机制。
    
-   作者讨论了跨表格迁移学习的可能性和挑战。尽管不同表格在列数和语义含义上可能完全不同，但作者认为不同表格之间存在共享的知识，这一点从AutoML中零样本超参数优化（HPO）的成功中得到了证明。与NLP领域的预训练模型不同，XTab不试图学习所有表格的通用分词器，而是旨在学习能够泛化到各种下游任务的权重初始化。
    

### 

### **第 3 章：方法 (Methods)**

-   ### **3.1 模型结构 (Model Structure)**
    
-   XTab的模型结构设计允许它处理来自不同领域的表格数据集。模型由以下几个关键部分组成：
    

![](assets/001.png)

-   Featurizers：这些是数据特定的组件，负责将表格的每一列转换为标记嵌入（token embeddings）。对于数值特征，使用可训练的向量和偏置项进行处理；对于分类特征，则通过查找表来检索嵌入。
    
-   Transformer-based Backbone：作为一个共享组件，跨所有表格数据集处理可变序列长度的标记嵌入。Transformer骨干包含多头自注意力（MHSA）模块和前馈网络。
    
-   Projection Heads：这些头是针对每个数据集特定的，用于进一步处理共享背骨的输出。它们可以用于重建原始表格、识别正/负样本对，或预测每个表格预定义的标签列的值。
    

-   ### 3.1.1 FEATURIZERS
    
-   Featurizers负责将输入样本转换为特征嵌入。对于数值列，使用数值乘以可训练向量并加上偏置项；对于分类列，使用嵌入矩阵作为查找表来检索特征嵌入。
    
-   ### 3.1.2 BACKBONES
    
-   作为跨多个预训练数据集共享的组件，Transformer能够处理变长的输入序列，使得预训练一个能够应用于所有表格数据集的表格变换器成为可能。论文中介绍了三种Transformer变体：FT-Transformer、Fastformer和Saint-v。
    
-   ### 3.1.3 PROJECTION HEADS AND OBJECTIVES
    
-   XTab使用不同的预训练目标，包括重建损失、对比损失和监督损失。这些损失函数用于指导模型学习如何从损坏的样本视图中重建原始样本，或者在对比学习设置中识别正负样本对。
    

-   ### **3.2 联邦预训练 (Federated Pretraining)**
    
-   为了处理大量的预训练任务，XTab采用了联邦学习框架。在这种设置下，每个客户端只托管一个数据集，通过客户端本地计算梯度，然后在中央服务器上聚合这些梯度。这个过程涉及到Federated Averaging (FedAvg)算法，允许在多个客户端上分布式地进行预训练。
    
-   FedAvg算法：通过在本地进行多次更新，然后在中央服务器上聚合，减少了与中央服务器的通信成本。
    
-   超参数N：控制每次聚合前在客户端上进行的本地更新次数，是通信效率的关键参数。
    

  

### **第 4 章：实验 (Experiments)**

-   ### **4.1. Transformer骨干架构的灵活性**
    
-   XTab框架能够兼容多种Transformer骨干架构，包括FT-Transformer、Fastformer和Saint-v。该部分说明了XTab如何利用这些架构进行预训练和微调，并展示了其在多种表格任务上的有效性。通过使用重建目标进行预训练，并在下游任务中应用轻量和重量设置的微调，XTab在所有模型上都表现出优于基准的性能。
    
      
    
-   ### **4.2. 不同组件的实验结果**
    
-   附录部分提供了更多实验结果，包括对Transformer不同组件的预训练、仅使用部分训练集进行微调的下游性能、预训练任务数量对性能的影响，以及在联邦预训练设置中本地更新次数对下游性能的影响。
    
      
    

![](assets/002.png)

-   ### **4.3. 与传统基准模型的性能对比**
    
-   为了比较XTab与其他表格模型的性能，作者在完整的AutoML基准数据集上运行了实验。基准数据集被分为两折，每折包含52个表格数据集。XTab在其中一折上进行预训练，并在另一折上评估下游性能，反之亦然。在实验中，XTab与以下几种方法进行了比较：
    
-   树模型：包括随机森林（RF）和梯度提升树变种（XGBoost、LightGBM、CatBoost）。
    
-   神经网络：包括基于PyTorch实现的AutoGluon神经网络和FastAI表格模型。
    
-   Transformer模型：包括没有预训练的FT-Transformer。FTT和XTab的微调设置包括轻量（FTT-l/XTab-l）和重量（FTT-h/XTab-h）微调。此外，还引入了FTT-best/XTab-best，通过早停耐心和模型集成来实现更好的性能。
    
-   实验结果表明，XTab在大多数情况下都优于这些传统基准模型，尤其是在有限的训练时间预算下，其优势更加明显。
    
      
    

![](assets/003.png)

-   ### **4.4. 性能表现**
    
-   通过与FTT的对比，XTab在轻量（FTT-l/XTab-l）和重量（FTT-h/XTab-h）微调下都提升了性能。XTab-best在基准测试中排名第二，并且超过了其他深度学习模型。使用默认配置，XTab的成功确保了预训练的骨干模型在表格任务中广泛适用，而无需针对具体案例进行调整。
    
-   在超参数优化（HPO）中，XTab进一步展示了其在随机搜索超参数时的优势，特别是在训练时间预算紧张的情况下，预训练的基础模型优于随机初始化的权重。
    

![](assets/004.png)

![](assets/005.png)

### **第 5 章：结论 (Conclusion)**

XTab框架的核心贡献，即通过跨表格预训练显著提升了tabular transformers在多种下游任务上的性能。作者强调了XTab在处理表格数据多样性和提高模型泛化能力方面的优势，并指出了与现有树模型之间的性能差距，提出了未来工作的方向，如进一步优化模型结构和探索多模态学习。同时，作者提供了实验代码和预训练模型，以便研究者复现和扩展研究。

论文及代码下载见星球

距离下次星球提价名额不到20，星球内有许多业内大佬，以及更多专业内容，欢迎加入，加入后不满意72小时内可全额退款，加入星球请扫我：

![](assets/006.jpg)

  

入群请扫我：

![](assets/007.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
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

![](assets/008.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。