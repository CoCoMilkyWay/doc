# GPT vs BERT 金融工程该选择哪种结构？

QuantML QuantML 2024-06-02 22:52 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484541&idx=1&sn=437ed0b400142cc9d23ef1ad28ba1843&chksm=cf0c5808c3701ca1ac1124e1b7b4ff23940082aa629f6fffafa7ef900a66fc0b173ba4f884e8#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484541&idx=1&sn=437ed0b400142cc9d23ef1ad28ba1843&chksm=cf0c5808c3701ca1ac1124e1b7b4ff23940082aa629f6fffafa7ef900a66fc0b173ba4f884e8#rd)

Content

  

### **1\. 引言 (Introduction)**

-   论文介绍了BERT（Bidirectional Encoder Representations from Transformers）和GPT（Generative Pre-trained Transformer）这两种模型，并讨论了它们在自然语言处理（NLP）任务中的应用，如机器翻译、文本摘要、问题回答和自然语言生成。
    
-   作者提出了研究动机：帮助公司在动荡的全球市场中做出正确的对冲决策。
    
-   论文还提到了Transformer模型的树状图，展示了大型语言模型是如何分布在编码器、解码器和编码器-解码器架构中的。
    
    ![](assets/001.png)
    

### **2\. Transformer基础 (Transformer Preliminary)**

-   论文介绍了Transformer模型的基本架构，包括自注意力机制，这是管理状态模型的关键技术。
    
-   讨论了大型语言模型在提供替代数据集方面对时间序列模型的潜在益处。
    
    ![](assets/002.png)
    

### **3\. 模型 (Models)**

详细介绍了BERT和GPT这两种基于Transformer的模型，以及它们在特定任务上的应用和性能。

### **3.1 BERT (Bidirectional Encoder Representations from Transformers)**

-   架构: BERT是一种基于Transformer的编码器模型，它通过在所有层中同时考虑左右上下文来预训练深度双向表示。
    
    、![](assets/003.png)
    
-   预训练任务: BERT使用掩码语言模型（Masked Language Model, MLM）和下一句预测（Next Sentence Prediction, NSP）作为预训练任务。
    
-   优势: 由于其双向特性，BERT能够捕获更多的上下文信息，并更好地处理多义词。它还能通过预训练的两个目标来提高模型的泛化能力和鲁棒性。
    
-   应用: BERT可以用于广泛的任务，只需在预训练模型上添加一个额外的输出层即可进行微调。
    

### **3.2 GPT (Generative Pretrained Transformer)**

-   架构: GPT是一个基于Transformer的解码器模型，主要用于生成连贯且与上下文相关的文本。
    
-   预训练任务: GPT使用因果语言模型（Causal Language Modeling, CLM）进行预训练，这使得模型能够按顺序生成文本。
    
-   优势: GPT在语言生成、文本补全和故事创作等任务上表现出色，能够生成类似人类的文本。
    
-   应用: GPT模型通过自回归方式训练，即在生成下一个词时，条件是前面的词。
    

### **3.3 模型比较**

-   双向与单向: BERT是双向的，而GPT是自回归的（解码器仅）。这意味着BERT在处理语言时可以同时考虑前后文，而GPT则是基于前面的词来预测下一个词。
    
-   情感分析: 在情感分析任务中，BERT的双向上下文理解可以帮助更好地把握情感，尤其是在复杂句子中。GPT虽然不像BERT那样考虑未来的上下文，但它仍然能够有效地建模语言并推断情感。
    
    ![](assets/004.png)
    

### **3.4 特定领域模型**

-   FinBERT: 是基于BERT的金融领域语言模型，用于处理金融文本挖掘的NLP任务。FinBERT在两个金融情感分析数据集上的表现超过了现有的最先进方法。
    
-   CopBERT: 本文提出的一个概念，旨在促进对商品新闻源的情感分析NLP任务。
    
      
    

### **3.5 Transformer模型在商品预测中的应用**

-   Transformer架构: 论文讨论了Transformer模型如何通过自注意力机制来处理序列转换任务，以及如何通过编码器和解码器之间的连接来提高性能。
    
-   注意力机制: 论文介绍了缩放点积注意力函数，这是Transformer模型中用于计算注意力分数的关键部分。
    

### **4\. 方法 (Approach)**

这一章节展示了论文中所采用的具体方法，包括数据的收集和处理、模型的训练和评估，以及如何通过可视化和解释性分析来提高模型的透明度和可信度。通过这些方法，作者能够对比BERT和GPT模型在特定金融工程任务中的性能，并探讨了它们在实际应用中的潜力和限制。

### **4.1 数据收集与处理**

-   数据来源: 训练数据来自公开可获取的网站，包括路透社(Reuters)、阿格斯(Argus)、矿业杂志(Mining Journal)和金融时报(FT)等。
    
-   时间索引: 在抓取过程中，文章的标题被时间索引化，以确保数据的时间顺序性。
    
-   人工标注: 训练数据由人类标注者根据他们的感知将文章标题标注为正面、中性或负面情感。
    

### **4.2 模型训练**

-   特定领域模型: CopBERT和CopGPT模型专注于情感建模的NLP任务，它们在开源数据上进行训练。
    
-   训练格式: CopGPT的训练格式被分解为“系统”、“内容”、“用户”和“助手”部分，以适应特定的训练需求。
    

### **4.3 评估指标**

-   F1分数: 使用F1分数作为评估模型性能的主要指标，它代表了召回率和精确率的调和平均值。
    

### **4.4 模型结果**

-   基线模型: 论文中还包括了一个随机基线模型，用于与训练模型的性能进行比较。
    
-   性能比较: 论文列出了一个表格，展示了不同模型在铜特定新闻上的F1分数，包括FinBERT、CopBERT、CopGPT以及GPT的不同版本。
    

### **4.5 混淆矩阵**

-   性能可视化: 论文提供了CopBERT和CopGPT的混淆矩阵，以可视化模型在不同情感类别上的性能。![](assets/005.png)
    

### **4.6 解释性与幻觉**

-   模型解释性: 论文强调了理解模型如何得出结论的重要性，特别是GPT模型在情感分析中可能产生的幻觉问题。
    
-   可视化注意力图: 为了提高解释性，论文创建了一个基于聚合注意力权重的图，其中节点表示句子，边的颜色表示余弦相似性权重，从而可视化模型的注意力模式。
    

### **4.7 结论**

-   性能提升: CopBERT模型在多种商品类型上训练的性能优于随机基线和FinBERT模型。
    
-   GPT模型的挑战: 尽管GPT模型在某些情况下性能优于BERT模型，但它们的工作原理不透明，这在解释性方面提出了挑战，尤其是在与幻觉问题相结合时。
    

### **5\. 结论 (Conclusion)**

-   论文总结了BERT和GPT在不同架构和目标下的应用和挑战。
    
-   作者指出，尽管GPT模型在预测能力上优于BERT模型，但在金融工程任务中，考虑到幻觉风险和解释性挑战，BERT模型可能是一个有趣的替代方案。
    
-   论文最后提出了对BERT模型的进一步研究和探索的建议，特别是在解释性和机制解释性方面。
    

  

  

目前距离星球下次提价还有20多个名额，欢迎扫码加入：

![](assets/006.jpg)

  

  

入群请扫我：  

![](assets/007.jpg)

  

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

![](assets/008.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/009.jpg)