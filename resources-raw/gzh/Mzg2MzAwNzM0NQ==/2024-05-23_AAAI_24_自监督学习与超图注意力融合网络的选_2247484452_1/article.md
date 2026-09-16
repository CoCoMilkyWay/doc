# AAAI 24 | 自监督学习与超图注意力融合网络的选股模型

QuantML QuantML 2024-05-23 18:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484452&idx=1&sn=b7a6e1041c6a2b43135f894e8fc8fd2b&chksm=cf7ccc48516f5cad9a3b89dec4b3e138b1138e7ad5f4d0d69f199c9a0bdbf7f104d951ed1371#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484452&idx=1&sn=b7a6e1041c6a2b43135f894e8fc8fd2b&chksm=cf7ccc48516f5cad9a3b89dec4b3e138b1138e7ad5f4d0d69f199c9a0bdbf7f104d951ed1371#rd)

Content  

> 论文下载地址：https://ojs.aaai.org/index.php/AAAI/article/view/28770

  

论文提出了一个名为CI-STHPAN（Channel-Independent based Spatio-Temporal Hypergraph Pre-trained Attention Networks）的两阶段股票选择框架，旨在解决量化股票选择中的一些挑战，如非平稳动态和复杂的市场依赖性。

![](assets/001.png)

### **摘要**

-   量化股票选择：作为金融科技（FinTech）中最具有挑战性的任务之一，受到非平稳动态和复杂市场依赖性的影响。
    
-   现有研究局限性：依赖于通道混合方法，加剧了金融时间序列中分布偏移的问题；模型结构复杂，难以处理非常长的序列；基于预定义的股票关系，难以捕捉动态和高度波动的股市。
    
-   CI-STHPAN框架：提出了一个两阶段框架，包括基于Transformer和HGAT（Hypergraph Attention Networks）的股票时间序列自监督预训练，以及基于股票排名的下游任务微调。
    
    ![](assets/002.png)
    
-   动态时间弯曲（DTW）：用于计算不同通道股票时间序列的相似性，并构建基于相似性的通道独立股票动态超图。
    
-   实验结果：在NASDAQ和NYSE市场数据上的五年实验表明，CI-STHPAN框架在投资回报率（IRR）和夏普比率（SR）方面优于现有最先进方法。即使不引入图信息，基于纯Transformer Encoder的自监督学习也超越了现有结果。
    

### **引言**

-   股票市场的重要性：对全球经济的发展起着关键作用。
    
-   传统机器学习技术：需要手动构建大量特征，难以捕捉股票之间的相互作用。
    
-   深度学习技术：在自然语言处理（NLP）、计算机视觉（CV）和自动语音识别（ASR）等领域取得了巨大成功。
    

### **相关工作**

-   基于Transformer的时间序列预测：介绍了基于Transformer的深度学习模型在各个领域的成功应用，并探讨了在时间序列预测中的应用。
    
-   基于时空的股票选择：讨论了股票价格运动受历史趋势和相关股票运动的影响，以及如何通过整合时间和空间特征来进行量化股票选择。
    

### **CI-STHPAN设计**

-   问题表述：将股票价格预测表述为股票排名问题。
    
-   数据预处理：对原始股票价格数据进行标准化处理，包括计算移动平均值。
    
-   股票时间序列分块：通过滑动窗口生成固定长度的补丁，以提高预测准确性。
    
-   股票超图构建：基于DTW算法构建通道独立的超图，以更好地表示股票市场集体的高阶关系。
    

### **模型结构**

CI-STHPAN模型结构包含两个主要部分：基于Transformer的时间序列自监督预训练和基于股票排名的下游任务微调。

![](assets/003.png)

-   ### **1\. 数据预处理和股票时间序列分块（Patching）**
    

-   标准化：原始股票价格数据首先被标准化，计算不同时间窗口的移动平均值，以表示从短期到长期的股票价格趋势。
    
-   分块：股票时间序列通过滑动窗口的方式被分割成固定长度P的补丁（patches），每个补丁包含连续的时间序列数据。补丁之间的间隔S可以根据需要设置，以确保捕捉局部时间信息并减少模型复杂性。
    

-   ### **2\. 股票超图构建**
    

-   动态时间弯曲（DTW）：使用DTW算法计算不同股票时间序列之间的相似性，基于这种相似性构建通道独立的超图。
    
-   超图表示：超图由节点集V（代表股票）和超边集E（基于相似性连接的股票组）组成。超图能够更充分地表示股票市场集体的高阶关系。
    

-   ### **3\. Transformer Encoder**
    

-   输入映射：将分块后的时间序列特征通过线性投影和可学习的位置编码映射到Encoder的维度D。
    
-   多头自注意力机制：每个头基于输入特征生成查询（Q）、键（K）和值（V），并通过softmax函数计算注意力权重，实现元素间的关联学习。
    
-   层叠结构：通过多个多头自注意力层和残差连接，生成股票的时间特征表示。
    

-   ### **4\. 超图注意力网络（HGAT）**
    

-   全局时间特征提取：从Transformer Encoder生成的个体股票时间特征中提取全局时间特征。
    
-   节点特征更新：使用超图注意力机制，根据超图的邻接矩阵更新每个节点的特征，考虑了股票之间的关系。
    
-   多头注意力架构：类似于Transformer，HGAT也采用了多头注意力架构，以捕获不同子空间下的关系。
    

-   ### **5\. 通道独立性（Channel Independence）**
    

-   输入张量转换：在分块之后，将输入张量从多通道形式转换为单一通道形式，以实现通道独立性，无需改变模型的其他结构。
    

-   ### **6\. 实例归一化（Instance Normalization）**
    

-   金融时间序列的分布偏移：金融时间序列数据在训练集和测试集之间的分布不一致。通过在分块前后对数据进行归一化处理，可以克服这一问题。
    

-   ### **7\. 自监督预训练**
    

-   掩码自编码器技术：在分块后的数据上随机掩码一定比例的补丁，生成掩码数据，并通过模型重建这些数据。
    
-   损失函数：使用均方误差（MSE）作为损失函数，通过最小化重建误差来训练预训练模型。
    

-   ### **8\. 微调（Finetune）**
    

-   特征表示：将预训练得到的时间-空间特征通过一个展平层和线性头来预测下一个交易日的收盘价，并转换为收益率。
    
-   损失函数：结合点式回归损失和成对排名损失进行微调，使用超参数α来平衡这两个损失项。
    
    ![](assets/004.png)
    

### **实验**

-   数据集：使用与先前研究一致的数据集，包括NASDAQ和NYSE的历史股票交易数据。
    
-   指标：使用每日买卖持有交易策略，计算IRR和SR等指标。
    
    ![](assets/005.png)
    

### **结果**

-   整体性能：CI-STHPAN在风险调整回报方面优于所有基线模型。
    
-   消融研究：分析了CI-STHPAN的不同组件对模型性能的影响。
    
-   深度分析：探讨了不同图信息对模型性能的影响，以及超参数对模型性能的影响。
    
    ![](assets/006.png)
    
-   注意力可视化：展示了模型中时间特征的自注意力权重和股票节点的超边注意力。
    
    ![](assets/007.png)
    

### **迁移学习**

-   预训练和微调：展示了在一个市场上预训练然后在另一个市场上微调的结果。
    
    ![](assets/008.png)
    

### **结论**

-   CI-STHPAN：一个两阶段框架，结合了股票时间序列的自监督预训练和基于股票排名的下游任务微调，以及基于DTW的通道独立股票动态超图的构建。
    
-   定量和定性分析：通过在NASDAQ和NYSE市场的分析，验证了CI-STHPAN在量化股票选择方面的应用性。
    

  

  

论文及代码下载见星球。

  

加入星球请扫我：

![](assets/009.jpg)

  

  

入群请扫我：  

![](assets/010.jpg)

  

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

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/012.jpg)