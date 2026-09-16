# 深度学习模型DeepLOB用于订单簿价格预测

QuantML QuantML 2024-05-14 19:33 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=cfe5d2d1f80b81244eddc13903b514fcee12acdb8d0e83c1e8138ba9201c3ac0c05e8270cc8a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=cfe5d2d1f80b81244eddc13903b514fcee12acdb8d0e83c1e8138ba9201c3ac0c05e8270cc8a#rd)

Content  

> 论文下载地址：1808.03668 (arxiv.org)

  

本文提出了一个大规模深度学习模型，用于从股票的限价单簿（Limit Order Book，简称 LOB）数据中预测价格运动。模型结合了卷积神经网络（CNN）和长短期记忆网络（LSTM）来捕捉限价单簿的空间结构和时间依赖性。

### **摘要**

-   论文开发了一个深度学习模型，用于预测现金股票的限价单簿（LOB）数据中的价格运动。
    
-   模型架构使用卷积滤波器捕捉LOB的空间结构，以及LSTM模块捕捉时间依赖性。
    
-   在基准LOB数据集上的测试显示，该网络的性能超过了所有现有的最先进算法。
    
-   通过使用伦敦证券交易所一年市场报价进行测试，模型在多种工具上展现了非常稳定的样本外预测准确性。
    
-   模型能够很好地泛化到训练集之外的工具，表明模型能够提取通用特征。
    
-   为了更好地理解这些特征并超越“黑箱”模型，作者执行了敏感性分析，以理解模型预测背后的原理，并揭示限价单簿中最相关的组成部分。
    

### **引言**

-   论文讨论了电子限价单簿（LOB）在现代金融市场中的使用，以及它们如何记录交易。
    
-   LOB是一个复杂的多维问题，涉及多个价格和订单量/大小。
    
-   传统的金融数学模型通常难以处理这种高维度问题。
    

### **背景和相关工作**

-   论文回顾了股票市场可预测性的研究历史，并讨论了统计参数模型和数据驱动的机器学习方法。
    
-   作者强调了数据驱动方法在提取代表性特征方面的重要性。
    

### **数据、归一化和标记**

-   ### **Limit Order Books (LOBs) 的定义**
    

-   LOBs 包含两种类型的订单：买单（bid orders）和卖单（ask orders）。
    
-   买单是以低于或等于特定价格购买资产的订单，而卖单则是以高于或等于特定价格出售资产的订单。
    
-   订单根据提交价格不同被排序成不同的级别，每个级别包含价格和成交量的信息。
    
    ![](assets/001.png)
    

-   ### **输入数据**
    

-   论文中使用了两个数据集：FI-2010 数据集和伦敦证券交易所（LSE）的一年期限价单簿数据。
    
-   FI-2010 数据集 是一个公开的高频限价单数据集，包含纳斯达克北欧市场五支股票连续10天的数据。
    
-   LSE 数据集 包含2017年1月3日至12月24日间，LSE上五支流动性最高的股票（Lloyds Bank, Barclays, Tesco, BT 和 Vodafone）的所有限价单簿更新数据。
    

-   ### **数据归一化和标记**
    

-   归一化：由于金融时间序列数据通常经历制度变迁，使用静态归一化方案不适合一年长度的数据集。因此，作者采用了基于前5天数据的动态z-score归一化方法。
    
-   输入定义：使用LOB最近100个状态作为模型的单个输入，每个时间戳有40个特征（每个级别5个价格和成交量）。
    
-   标记：使用中点价格（best bid和best ask价格的平均值）来创建标签，代表价格变动的方向。通过比较前期和后期的中点价格平均值来定义价格运动的方向，如果变动百分比超过设定的阈值（α），则定义为上升（+1）或下降（-1），否则为静止（0）。
    
    ![](assets/002.png)
    

-   ### **数据处理的关键点**
    

-   数据集划分：将数据集划分为训练集、验证集和测试集，以评估模型的泛化能力。
    
-   动态归一化：使用动态归一化方法来适应金融时间序列数据的非平稳特性。
    
-   输入特征：选择限价单簿的最近100个状态作为输入，捕捉最近的价格和成交量变化。
    
-   标签生成：利用中点价格的百分比变化来生成价格运动的标签，以此来训练模型预测价格的上升、下降或静止。
    

### **模型架构**

DeepLOB模型由三个主要部分组成：标准的卷积层、Inception模块和LSTM层。这个结构旨在自动化特征提取过程，并捕捉时间依赖性，从而提高对股票价格运动的预测准确性。

![](assets/003.png)

-   ### **卷积层 (Convolutional Layer)**
    

-   目的：从LOB的历史数据中提取特征，尤其是价格和成交量之间的局部关系。
    
-   操作：使用不同大小的卷积核来扫描输入数据，提取特征。
    
-   设计：第一层使用(1×2)大小的卷积核和(1×2)的步长来处理每个订单簿级别中的价格和成交量信息。后续层使用更大尺寸的卷积核来整合来自不同级别信息，形成微价格（micro-price）特征。
    

-   ### **Inception模块 (Inception Module)**
    

-   目的：捕获多时间尺度的动态行为，类似于在技术分析中使用不同衰减权重的移动平均线。
    
-   操作：通过使用1×1卷积来降低维度，然后应用不同大小（如3×1和5×1）的卷积核，最后将结果合并，以此来提取不同时间尺度上的特征。
    
-   设计：Inception模块内部使用最大池化层（Maxpooling）来进一步提取特征，同时保持网络的参数数量可控。
    
    ![](assets/004.png)
    

-   ### **LSTM层 (LSTM Layer)**
    

-   目的：捕获提取特征之间的时间依赖性，因为限价单簿数据具有强烈的时间序列特性。
    
-   操作：LSTM层通过其内部状态和门控机制来记忆长期的时间信息，从而捕捉序列数据中的时间动态。
    
-   设计：使用64个LSTM单元，显著减少需要估计的参数数量，相比于全连接层更加高效。
    

-   ### **输出层 (Output Layer)**
    

-   目的：生成最终的价格运动预测。
    
-   操作：最后一个输出层使用softmax激活函数，输出每个时间步的价格上升、静止或下降的概率。
    

-   ### **模型训练和优化**
    

-   损失函数：使用分类交叉熵（categorical crossentropy）作为损失函数。
    
-   优化算法：使用ADAM算法进行参数优化，设置学习率和epsilon参数。
    
-   训练终止条件：当验证集的准确度在20个epoch内没有提升时停止训练。
    

-   ### **模型特性**
    

-   参数共享：卷积层通过参数共享减少了模型的复杂度。
    
-   平移等变性：卷积层对输入数据的平移具有等变性，有助于提取在时间序列中位置不变的特征。
    
-   动态归一化：输入数据采用基于前几天数据的动态z-score归一化，以适应金融时间序列的非平稳性。
    

DeepLOB模型通过这种混合结构有效地结合了卷积网络的空间特征提取能力和LSTM网络的时间序列处理能力，使其能够从复杂的限价单簿数据中提取出对预测股票价格运动有用的特征。

### **实验结果**

-   作者在FI-2010数据集和LSE数据集上进行了实验，并与其他方法进行了比较。
    
-   实验结果表明，DeepLOB模型在预测短期价格运动方面优于其他技术。
    
    ![](assets/005.png)
    
-   作者还进行了简单的交易模拟，以测试模型的实用性，并获得了统计上显著的利润。
    
    ![](assets/006.png)
    

### **敏感性分析**

-   为了提高模型的可解释性，作者使用了LIME方法来识别对预测最重要的限价单簿组件。
    
    ![](assets/007.png)
    

  

代码下载见星球。

  

  

欢迎入群交流：  

![](assets/008.jpg)

  

往期回顾

       QuantML-Qlib开发版：

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