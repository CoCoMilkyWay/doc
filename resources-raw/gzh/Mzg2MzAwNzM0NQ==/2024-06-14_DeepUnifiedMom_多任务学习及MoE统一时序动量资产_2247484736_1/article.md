# DeepUnifiedMom: 多任务学习及MoE统一时序动量资产组合构建

QuantML QuantML 2024-06-14 22:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484736&idx=1&sn=3cde94d9b3c0644d8114bcd5092d0cf8&chksm=cf013b70772fd6dd192e2c1b35e46bb6c00e709e1bc336566b9c63272b7eb25e319cca20e827#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484736&idx=1&sn=3cde94d9b3c0644d8114bcd5092d0cf8&chksm=cf013b70772fd6dd192e2c1b35e46bb6c00e709e1bc336566b9c63272b7eb25e319cca20e827#rd)

Content

论文：\[2406.08742\] DeepUnifiedMom: Unified Time-series Momentum Portfolio Construction via Multi-Task Learning with Multi-Gate Mixture of Experts (arxiv.org)

本文提出了 DeepUnifiedMom，一个创新的深度学习框架，它通过多任务学习和多门控混合专家的方法统一了时间序列动量投资组合的构建。该模型能够捕捉不同时间尺度上的动量机会，并通过综合考虑资产间的相互作用来优化资本分配，从而在广泛的资产类别上实现了持续超越传统动量策略和基准模型的风险调整回报。此外，通过引入soft capping mechanism改进的夏普比率作为训练目标，DeepUnifiedMom 有效地减少了过拟合的风险，提高了模型的泛化能力。

### **1\. 引言 (Introduction)**

-   主题: 时间序列动量（TSMOM）策略是一种利用资产回报随时间持续性的系统方法。这些策略通过在上升趋势中建立多头头寸和在下降趋势中建立空头头寸来利用潜在趋势的延续。
    
-   研究背景: 动量概念在金融文献中受到广泛关注，研究表明通过购买过去12个月回报率为正的资产可以获得令人印象深刻的风险调整回报。
    
-   存在的问题: 传统的TSMOM策略通常没有考虑到投资组合内不同资产之间的相互作用，这可能导致风险暴露过高。
    
-   提出的解决方案: 作者提出了一个基于深度学习的创新方法，利用多任务学习框架和多门控混合专家（Multi-gate Mixture of Experts）架构来开发动量投资组合。
    

### 

### **2\. 相关工作 (Related Work)**

-   深度学习在金融中的应用: 讨论了深度学习技术在提高预测准确性、投资组合优化和风险评估方面的应用。
    
-   时间序列动量策略: 介绍了TSMOM策略的概念及其在不同资产类别中的有效性。
    
-   深度学习在投资组合构建中的应用: 讨论了深度学习方法在投资组合构建中的使用，特别是在处理不同速度的趋势时。
    

###   

### **3\. 方法论 (Methodology)**

本章介绍了作者提出的 DeepUnifiedMom 框架，这是一个结合了多任务学习和多门控混合专家（Multi-gate Mixture of Experts, MoMME）的深度学习模型，用于构建统一的时间序列动量投资组合。

### **3.1 概述 (Overview)**

-   多任务学习架构: 该架构利用长短期记忆网络（LSTM）作为共享层，形成多任务学习框架的主干，以实现不同任务之间的有效参数共享。
    
-   多门控混合专家: 每个特定任务网络都有一个专用的门控网络，这些门控网络是具有 softmax 激活函数的单层前馈神经网络（FNN），用于确定对相应 LSTM 专家的依赖程度。
    

![](assets/001.png)

### **3.2 多任务学习网络 (Multi-Task Learning Network)**

-   动量分类: 动量被分为快速（Fast, 一个月）、中等（Medium, 三个月）和慢速（Slow, 六个月）三类。
    
-   任务特定网络: 每个任务特定网络由一个前馈神经网络（FNN）表示，被训练来预测前瞻性时间序列动量（TSMOM）信号。
    
-   风险调整: TSMOM 信号是资产的前瞻性回报，根据其波动性进行调整，以提供跨不同资产的标准化动量度量。
    
-   训练目标: 最小化预测 TSMOM 信号和实际前瞻性 TSMOM 信号之间的均方根误差（RMSE）。
    

### **3.3 资本分配网络 (Capital Allocation Network, CAN)**

-   目标: 生成分配给由任务特定网络产生的各种动量投资组合的资本权重。
    
-   实现: 作为具有 tanh 和 softmax 激活函数的专门前馈神经网络（FNN）实现。
    
-   夏普比率: 使用夏普比率作为训练目标函数，指导模型学习如何从输入特征生成优化风险调整回报的投资组合。
    

![](assets/002.png)

### **3.4 损失函数 (Loss Function)**

-   总损失函数: 训练过程中最小化的最终损失函数结合了资本分配网络的soft capping mechanism修改后的夏普比率损失和每个任务特定网络的 RMSE 损失。
    
-   **soft capping mechanism:** 目的是为了减少金融数据中高噪声对信号比例的影响，降低过拟合的风险。通过通过设置阈值来限制夏普比率的极端值，并对超出阈值的部分应用对数变换，以减缓其增长速度。
    
-   **模型训练和验证细节：**
    

-   训练过程: 描述了使用 SGD 与 Adam 优化器来最小化损失函数的过程。
    
-   超参数搜索: 进行了网格搜索以确定最佳超参数。
    
-   早停法: 如果验证损失在连续5个周期内没有改善，则停止训练。
    

### **4\. 实验设置 (Experimental Setup)**

本章描述了用于评估 DeepUnifiedMom 模型的实验环境、数据集、特征工程、基准模型选择以及回测细节。

### **4.1 数据集 (Dataset)**

-   数据源: 使用 Pinnacle Data Corp CLC 数据库，提供了从1990年1月到2023年12月的49种不同资产类别的期货合约的每日连续价格历史数据。
    
-   处理方法: 通过端到端连接和使用向后比率方法的价格调整，构建了每个资产的连续合约历史，以确保对长期趋势的稳健分析。
    

### **4.2 特征集 (Feature Set)**

-   动量特征: 从连续期货的日结算价格中提取时间序列动量特征，包括过去3天、5天、10天、21天、63天、126天和252天的对数收益率。
    
-   标准化: 通过资产的波动性对计算出的对数收益率进行标准化，以确保跨不同资产和时期的公平比较。
    

### **4.3 基准模型 (Benchmark Models)**

-   TSMOM 投资组合: 基于 Moskowitz 等人 (2012) 提出的时间序列动量 (TSMOM) 投资组合概念，构建了多个 TSMOM 投资组合，以评估模型的有效性。
    
-   时间框架: 包括基于过去1个月、3个月、6个月、12个月回报的 TSMOM 投资组合，以及它们的等权重组合。
    

### **4.4 回测细节 (Backtest Specifications)**

-   训练与验证: 使用扩大窗口交叉验证方法，第一个训练数据集涵盖10年期，20%的数据用于验证。
    
-   测试集: 训练好的模型用于构建测试集的投资组合，每个投资组合对应一年的实际样本外数据。
    
-   超参数: 进行了网格搜索以确定最佳的网络结构和参数。
    
-   优化器: 使用随机梯度下降（SGD）与 Adam 优化器来最小化损失函数。
    
-   早停机制: 如果在连续5个周期内验证损失没有改善，则停止训练。
    

![](assets/003.png)

### **5\. 性能评估 (Performance Evaluation)**

本章深入分析了 DeepUnifiedMom 模型在实际金融市场数据上的表现，并与其他动量策略和投资组合构建技术进行了全面比较。通过从2000年1月到2023年12月的广泛回测，结果显示 DeepUnifiedMom(CAN) 在风险调整回报方面显著超越了所有传统的时间序列动量(TSMOM)基准模型，包括基于不同时间框架的动量策略。

![](assets/004.png)

  

具体来说，DeepUnifiedMom(CAN) 实现了2.33的夏普比率和3.88的Sortino比率，同时将最大回撤控制在-1.02%，这比大多数基准策略的风险调整性能都要好。此外，DeepUnifiedMom(CAN) 还展示了在不同市场条件下对动量机会的捕捉能力，以及在资本分配上的一致性和有效性。与等权重分配方法(DeepUnifiedMom-EQWT)和均值方差优化方法(DeepUnifiedMom-MVO)相比，DeepUnifiedMom(CAN) 也表现出了更高的风险调整回报和更低的最大回撤。此外，当使用带软帽子机制的夏普比率作为训练目标函数时，DeepUnifiedMom(CAN) 的性能得到了进一步提升，这表明了改进目标函数在提高深度学习模型泛化能力方面的潜力。

![](assets/005.png)

![](assets/006.png)

  

### **6\. 结论 (Conclusion)**

-   贡献: DeepUnifiedMom框架在应用深度学习于投资组合管理方面取得了显著进展，有效解决了传统动量策略的局限性。
    
-   未来工作: 计划通过将稀疏性纳入门控机制和使用更复杂的深度学习架构（如Transformer模型）来增强DeepUnifiedMom框架，并整合可解释的AI技术以提高透明度和可解释性。
    

  

  

  

  

**论文下载见星球**  

  

  

加入星球请扫我：

![](assets/007.jpg)

  

  

  

入群请扫我：  

![](assets/008.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
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

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)