# 综述：深度学习模型在加密货币市场的应用与验证

QuantML QuantML 2024-06-10 18:00 陕西

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484684&idx=1&sn=0c27a963fce8876794f7391841eef3ea&chksm=cf509e5aa710a53965f40da9de9956827b24cb8079eca7ec2f0ac3909b8f8f2f8d276a586579#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484684&idx=1&sn=0c27a963fce8876794f7391841eef3ea&chksm=cf509e5aa710a53965f40da9de9956827b24cb8079eca7ec2f0ac3909b8f8f2f8d276a586579#rd)

Content

本文探讨了深度学习模型在加密货币价格预测中的应用，并提供了实验结果和未来研究方向。

### **1\. 引言 (Introduction)**

-   论文讨论了投资者和研究者对于精确的加密货币价格预测模型的兴趣。
    
-   深度学习模型作为变革性技术，在金融和经济领域显示出潜力。
    
-   尽管已有多种深度学习模型被探索用于加密货币价格预测，但由于市场高波动性，尚不清楚哪些模型适合。
    
-   论文回顾了深度学习在加密货币价格预测方面的文献，并评估了新模型。
    

### **2\. 深度学习模型用于加密货币价格预测的文献回顾 (Review)**

本章主要介绍了深度学习和机器学习在金融时间序列预测，尤其是加密货币价格预测方面的文献综述

#### **2.1 金融时间序列预测 (Financial Time Series Prediction)**

-   重点: 金融时间序列预测主要关注资产价格的预测。
    
-   方法论: 使用深度学习模型来预测资产的未来走势，包括股票价格、指数预测、外汇价格预测以及商品（如石油和黄金）、债券价格、波动性，以及加密货币价格的预测。
    
-   趋势预测: 许多金融预测项目的目标不是准确预测价格，而是正确识别价格运动的方向，这通常被视为分类问题。
    

![](assets/001.png)

#### **2.2 加密货币预测 (Cryptocurrency Prediction)**

-   机器学习模型: 一些研究者使用机器学习模型，如简单神经网络、支持向量机（SVM）、基于遗传算法的神经网络等，来预测加密货币价格。
    
-   性能比较: 一些研究比较了不同机器学习模型的性能，例如使用均方误差（MSE）、平均绝对百分比误差（MAPE）和均方根误差（RMSE）等指标。
    

![](assets/002.png)

#### **2.3 深度学习模型用于加密货币预测 (Deep Learning Models for Cryptocurrency Prediction)**

-   深度学习模型: 近年来，深度学习模型在加密货币预测中表现突出，包括CNN、LSTM及其变体。
    
-   组合模型: 一些研究结合了CNN和LSTM，或者使用强化学习与LSTM结合的方法来优化加密货币价格预测。
    
-   性能提升: 深度学习模型能够提供精确可靠的预测，并且在某些情况下，通过结合卷积层和LSTM记忆单元，能够更好地处理时间序列数据。
    

![](assets/003.png)

#### **2.4 加密货币波动性和预测 (Cryptocurrency Volatility and Prediction)**

-   波动性分析: 一些研究集中于分析和预测加密货币市场的波动性，这是影响商业和金融决策的重要因素。
    
-   模型应用: 使用了不同的模型来分析加密货币市场的波动性，包括异方差模型（GARCH）、时间变化参数模型等。
    

![](assets/004.png)

### **2.5 小结 (Summary)**

-   本章提供了对现有文献的深入概述，解释了机器学习和深度学习如何应用于金融时间序列预测，特别是在加密货币价格预测方面。
    
-   强调了不同模型在预测加密货币价格方面的潜力和挑战，以及它们在捕捉市场趋势和波动性方面的能力。
    

### **3\. 方法论：实现和评估 (Methodology)**

本章详细介绍了用于加密货币价格预测的统计模型和深度学习模型的实现与评估

#### **3.1 传统模型 (Conventional Models)**

-   ARIMA模型: 介绍了自回归积分滑动平均（ARIMA）模型，这是一种用于时间序列预测的常用统计模型。解释了ARIMA模型的三个组成部分：自回归（AR）、积分（I）和移动平均（MA），以及它们在模型中的参数表示（p, d, q）。
    
-   多层感知器（MLP）: 描述了多层感知器的结构，包括输入层、隐藏层和输出层，以及如何通过训练算法更新权重和偏差来确保网络的预测输出接近实际观测值。
    

#### **3.2 深度学习模型 (Deep Learning Models)**

-   LSTM网络变体: 讨论了长短期记忆（LSTM）网络及其变体，如Elman RNN、双向LSTM（BD-LSTM）和编码器-解码器LSTM（ED-LSTM），并解释了它们如何通过记忆单元来处理时间序列数据中的长期依赖问题。
    

![](assets/005.png)

![](assets/006.png)

-   卷积神经网络（CNN）: 描述了CNN在图像处理任务中的应用，并解释了如何将其调整为适用于单变量时间序列数据的预测。
    
-   卷积LSTM网络（Conv-LSTM）: 介绍了Conv-LSTM网络，这是一种结合了CNN的空间特征提取能力和LSTM的时间序列预测能力的网络。
    
-   Transformer网络: 解释了Transformer模型的架构，包括编码器和解码器，以及它们如何使用自注意力机制来处理序列数据。
    

![](assets/007.png)

#### **3.2.5 Adam优化器 (Adam Optimiser)**

-   优化算法: 讨论了Adam优化器，这是一种自适应梯度优化算法，用于更新模型参数。解释了Adam优化器的工作原理，包括计算梯度的一阶和二阶梯度矩，并使用这些矩来调整学习率。
    

#### **3.3 数据 (Data)**

-   数据选择: 描述了用于评估统计和深度学习模型的四种加密货币：比特币、以太坊、狗狗币和莱特币。提供了数据来源和数据集的基本统计描述。
    

#### **3.4 数据处理 (Data Processing)**

-   时间序列重建: 讨论了使用Taken's嵌入定理来重建时间序列数据，以便进行多步预测。
    

#### **3.5 框架 (Framework)**

-   流程框架: 展示了整个加密货币价格预测流程的框架图，包括数据收集、预处理、超参数选择和实验设计。
    

![](assets/008.png)

![](assets/009.png)

#### **3.6 技术细节 (Technical Details)**

-   评估标准: 使用均方根误差（RMSE）作为预测准确性的评估标准，并讨论了优化过程中使用的超参数设置。
    

![](assets/010.png)

![](assets/011.png)

### **4\. 结果 (Results)**

#### **4.1 数据分析 (Data Analysis)**

-   COVID-19影响: 分析了COVID-19大流行期间四种选定加密货币（比特币、以太坊、狗狗币和莱特币）的收盘价趋势。观察到在COVID-19期间，这些加密货币的价格出现了大幅波动。
    

#### **4.2 实验结果：COVID-19前数据 (Results: Pre-COVID-19)**

-   模型比较: 使用比特币数据，比较了传统模型（MLP和ARIMA）与深度学习模型（LSTM、ED-LSTM、BD-LSTM、CNN、Conv-LSTM、Transformer）在单变量和多变量策略下的表![](assets/012.png)
    

![](assets/013.png)

-   预测性能: 深度学习模型普遍优于传统模型。在多变量策略中，特定的模型（如ED-LSTM）在预测准确性和稳健性方面表现更好。
    

![](assets/014.png)

  

#### **4.3 实验结果：包含COVID-19数据 (Results: Data featuring COVID-19)**

-   策略评估: 仅使用了单变量和多变量\*策略来评估数据集，包括COVID-19期间及之后的数据。
    
-   预测准确性: 发现在COVID-19数据集上，某些模型（如Conv-LSTM）在预测不同加密货币的收盘价时表现更好![](assets/015.png)
    

#### **4.4 模型性能比较 (Model Performance Comparison)**

-   排名: 提供了不同模型在预测不同加密货币时的性能排名，展示了哪些模型在特定策略下表现最佳。
    
    ![](assets/016.png)
    

  

**论文、代码及数据下载见星球**

  

  

感谢对于QuantML的支持，放送10张优惠券，某书也有618活动，欢迎加入：

![](assets/017.png)

  

  

入群请扫我：  

![](assets/018.jpg)

  

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

![](assets/019.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/020.jpg)