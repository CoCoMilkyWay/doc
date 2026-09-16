# 使用机器学习方法研究限价委托簿特征对短期价格预测的影响

QuantML QuantML 2024-06-17 22:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484771&idx=1&sn=52ce2b599bbb5e8a82b3ebf4d909a887&chksm=cf949943651510341cce3cb4a96999cc1bd26aefac44527e035f0513727cf6b00635ffa7f423#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484771&idx=1&sn=52ce2b599bbb5e8a82b3ebf4d909a887&chksm=cf949943651510341cce3cb4a96999cc1bd26aefac44527e035f0513727cf6b00635ffa7f423#rd)

Content

本文主要探讨了利用机器学习方法研究限价委托簿（Limit Order Book, LOB）特征及其对短期价格变动的预测潜力。

### **1\. 引言 (Introduction)**

高频交易已成为金融市场的主要力量，对市场微观结构和高粒度数据的研究兴趣日益增加，特别是限价委托簿（LOB）。本研究旨在特定短期价格预测的背景下，调查LOB的不同特征。研究范围限定在预测价格运动的即时方向，而不涉及价格变化幅度的预测或基于此类预测的交易策略的开发。

### **2\. 数据和系统 (Data and Systems)**

-   数据来源：使用LobsterData提供的NASDAQ股票的高质量限价委托簿数据。
    
-   数据结构：LOB列出了不同价格水平上的买卖订单量。数据包括“消息文件”和“委托簿文件”，分别记录订单事件和重建的10档LOB。
    

![](assets/001.png)

### **3\. 设计基于LOB的价格预测器 (Designing a LOB based Price Predictor)**

本章通过开发和评估不同的预测模型，为后续的研究提供了一个基准，并确定了随机森林作为最佳的预测器。此外，还探讨了类别不平衡问题，并提出了一种平滑方法来改善预测结果。

####     **定义价格预测**

-   价格预测被定义为预测下一个订单事件的中间报价（即最佳卖价和最佳买价的中点）是高于、低于还是等于当前的中间报价。
    
-   引入了一个新的类标签定义，用于表示价格的三种可能变动方向：上涨（+1）、下跌（-1）或不变（0）。
    

####     **评估指标**

-   使用了准确率（Accuracy）、精确率（Precision）、召回率（Recall）、F1加权分数（F1w）和F1微分数（F1mic）作为评估预测结果的主要指标。
    
-   特别关注F1微分数，因为它将每个类别同等对待，对于预测价格变动方向（即少数类）尤为重要。
    

####     **基线预测器 (Baseline Predictor)**

-   开发了一个名为BasePred的基线预测器，它基于测试数据集中每个类的频率进行随机预测。
    
-   BasePred在基础数据集上取得了较高的总体准确率，但在预测个别类别时显示出高方差。
    

![](assets/002.png)

####     **分类器评估**

-   评估了六种不同的分类器：高斯朴素贝叶斯（GNB）、随机梯度下降（SGD）、多层感知器神经网络（NNet）、支持向量机（SVM）、高斯过程分类器（GPC）和随机森林（RF）。
    
-   由于SVM和GPC在小数据样本上也无法在合理时间内收敛，因此这些分类器在早期阶段就被排除了。
    
-   SGD显示出不稳定的结果，而RF的积极结果鼓励了进一步研究集成分类器，如Adaboost（ADA）和梯度提升分类器（GDB）。
    

![](assets/003.png)

####     **类别不平衡问题 (Unbalanced Classes)**

-   初始的价格预测定义导致大约90%的数据点属于“0”类，而“+1”和“-1”类各占大约5%，表现出明显的类别不平衡。
    
-   为了解决这个问题，生成了一个二值化数据集，通过移除所有“0”类数据点来创建一个更平衡的数据集，并在该数据集上运行了分类器。![](assets/004.png)
    

####     **平滑方法 (Smoothing)**

-   为了解决价格在每个时间步的突然和不连续变化问题，采用了类似于Tsantekidis等人（2017年）的平滑方法。
    
-   通过计算过去和未来价格的均值，并使用这些均值来定义一个新的平滑类标签，以表达价格在时间t的运动方向。
    

  

![](assets/005.png)

####     **预测器选择和调整 (Predictor Selection and Tuning)**

-   随机森林（RF）在平滑数据集上表现最佳，因此被选为研究的其余部分的预测器。
    
-   使用标准K折交叉验证和Sklearn GridSearchCV函数对RF进行了调参，包括估计器数量、最大特征考虑数和每个树叶的最小样本数。
    
-   还对平滑算法的两个超参数α和S进行了调整，选择了α=1和S=20作为最优参数。
    

![](assets/006.png)

### **4\. 特征调查和工程 (Feature Investigation and Engineering)**

####     **特征集的划分**

-   作者将LOB的原始特征以及其他成功研究所启发的特征进行了工程化处理，生成了不同的特征集，以评估它们对价格预测的有用性。
    

####     **订单特征 (Order Features)**

-   将订单文件中的特征分为不同的订单特征集，例如时间、类型、ID、大小、价格和方向等。
    
-   通过运行随机森林（RF）预测器在这些特征集上，发现订单时间特征集（Order-Time）表现出异常的高准确性和F1分数，这可能是因为使用了单日交易数据，预测器可能过度拟合在时间特征上。
    

####     **LOB特征 (LOB Features)**

-   根据不同的LOB深度，将订单簿文件中的特征分为不同的LOB特征集。
    
-   发现LOB特征集具有很强的预测能力，并且随着特征集中包含的LOB级别数量减少，预测性能迅速下降。
    

![](assets/007.png)

####     **不平衡特征 (Imbalance Features)**

-   近年来的研究表明，LOB的不平衡是一个简单而有效的价格预测特征。
    
-   计算了整个数据集中每个LOB级别的LOB不平衡，并生成了不平衡特征集。
    
-   LOB不平衡特征显示出与LOB本身相当的预测价值，并且随着包含的LOB级别数量减少，预测能力反而增强。
    

![](assets/008.png)

####     **订单到达率特征 (Order Arrival Rates)**

-   作为一个新的工程化特征，订单到达率特征受到Kercheval和Zhang \[2015\]中订单强度概念成功的启发。
    
-   这些特征捕捉了在短历史窗口内创建、取消和执行的买卖订单量，并区分了LOB第一级别与其他订单。
    
-   运行RF预测器在不同时间窗口的订单到达率特征集上，发现这些特征具有一定的预测潜力，尤其是针对LOB第一级别的订单。
    

![](assets/009.png)

![](assets/010.png)

####     **特征组合 (Combining Features)**

-   将每个类别中最佳的特征集（订单、LOB、不平衡、到达率）聚合成一个综合数据集。
    
-   运行RF预测器在综合数据集上，但与在基础数据集上的基准相比，并没有看到显著的改进。
    

####     **结果分析**

-   作者对各种特征集的预测结果进行了详细的分析，发现尽管某些特征集（如LOB不平衡特征集）显示出强大的预测能力，但综合特征集并没有带来预期的改进。
    
-   提出了需要进一步研究以优化特征工程和特征集，以提高预测性能。
    

  

### **5\. 结论 (Conclusion)**

本文通过开发基于限价委托簿（LOB）的价格预测器，评估了多种机器学习分类器，并采用平滑技术有效处理了数据集中的类别不平衡问题。研究结果表明，随机森林（RF）分类器在调整参数后，显著优于基于类频率的基线预测器。此外，通过对订单和LOB特征的系统性研究，发现LOB不平衡特征集在减少包含级别时，其预测能力反而增强，而传统的LOB特征集则随级别减少而性能下降。尽管综合了多种特征集，但并未显著提高预测性能，表明需要进一步研究特征工程和特征集优化。本文的结论强调了未来研究的方向，包括扩大数据集范围、深入研究表现不稳定的分类器、探索LOB变化率等新特征，以及优化现有特征集，以进一步提升短期价格预测的准确性。

  

  

  

  

**论文、数据及代码下载见星球**  

  

  

加入星球请扫我：

![](assets/011.jpg)

  

  

  

入群请扫我：  

![](assets/012.jpg)

  

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

![](assets/013.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/014.jpg)