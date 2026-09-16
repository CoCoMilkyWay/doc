# 基于BOCPD的实时订单流交易模式识别及订单流预测

QuantML QuantML 2024-05-07 13:41 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484250&idx=1&sn=51dff624e70da4f387e3e24ba4008af9&chksm=cf5cf15d14fb3d86a84b4f2884f5a3406845baca1f48933df3b704fa83213afc11ecfe97c33d#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484250&idx=1&sn=51dff624e70da4f387e3e24ba4008af9&chksm=cf5cf15d14fb3d86a84b4f2884f5a3406845baca1f48933df3b704fa83213afc11ecfe97c33d#rd)

Content  

本文主要研究了金融市场中订单流和市场影响的建模问题，并提出了一种基于贝叶斯在线变点检测（Bayesian Online Change-Point Detection, BOCPD）方法的新模型，用于实时识别订单流中的不同交易模式（regimes），并预测订单流和市场影响。

  

### **1\. 引言**

-   论文指出金融订单流表现出显著的持续性，即买入（或卖出）交易往往会在较长时间内被后续的买入（或卖出）交易所跟随。
    
-   这种持续性可以归因于大宗订单的分割和逐步执行。
    
-   作者提出使用贝叶斯在线变点检测方法来实时识别交易模式的转变，并在线预测订单流和市场影响。
    

### **2\. 数据集和动机**

-   论文使用的数据集包括2020年3月微软公司（MSFT）和2021年12月特斯拉公司（TSLA）在NASDAQ交易所的执行订单数据。
    
    ![](assets/001.png)
    
    ![](assets/001.png)
    
-   ![](assets/001.png)
    
-   通过分析订单流的自相关函数，作者发现自相关性具有缓慢衰减的特性，这与长期记忆过程一致。
    

### **3\. 贝叶斯在线变点检测算法**

论文首先回顾了由Adams和MacKay于2007年提出的BOCPD算法，该算法假设每个交易模式内的交易是独立同分布的（i.i.d.）。为了解决金融时间序列中普遍存在的自相关性问题，作者提出了两种算法的扩展：Markovian BOCPD (MBO) 和 Markovian BOCPD for Correlated data (MBOC)

-   ### **3.1 BOCPD算法**
    
-   BOCPD算法由Adams和MacKay于2007年提出，用于处理独立同分布（i.i.d.）数据。该算法的核心思想是将时间序列分割成不同的交易模式（regimes），并在每个模式内假设数据是独立同分布的。具体来说：
    

-   模型假设：时间序列由正态分布的随机变量组成，具有未知均值`θR`和已知方差`σ^2`。
    
-   变点（Change Point, CP）：变点是时间序列中的一个点，从该点开始数据的分布参数发生变化。
    
-   运行长度（Run Length, rt）：从最后一个变点到当前时间点的步数。
    
-   后验概率：计算给定数据的运行长度的后验概率`p(rt|x1:t)`，这反映了自最后一个变点以来的步数的概率分布。
    

-   ### **3.2 MBO算法**
    

-   MBO算法是BOCPD算法的扩展，它考虑了交易模式内的数据可能存在的马尔可夫依赖性。在MBO模型中：
    
-   数据生成过程：假设在每个交易模式内，时间序列是AR(1)过程的实现，具有正态创新。
    
-   条件分布：给定前一个观测值，当前观测值的条件分布是正态的，且具有恒定的相关性`ρ`。
    

-   ### **3.3 MBOC算法**
    

-   MBOC算法进一步扩展了MBO算法，允许交易模式内的参数（如自相关系数`ρ`）随时间变化。MBOC算法采用Score Driven模型来描述时间变化的参数，具体包括：
    
    ![](assets/002.png)
    
-   Score Driven AR(1)过程：时间变化的相关性`ρt`通过Score Driven模型的递归关系进行描述。
    
-   参数估计：使用最大似然估计方法在线估计时间变化参数`ρt`和交易模式特征，如均值`θR`和运行长度`rt`。
    

-   ### **算法实现和结果**
    

-   超参数选择：论文中详细讨论了如何选择超参数，如方差、相关性参数、阈值`η`等，以最小化均方误差（MSE）。
    
-   模型比较：通过在线预测研究，比较了BOCPD、MBO和MBOC模型的性能。使用均方误差（MSE）作为性能指标，结果表明MBOC模型在样本外预测性能上超越了其他模型。
    

-   ### **结果分析**
    

-   交易模式的识别：MBOC算法能够识别出交易日结束时的变点，表明该方法能够实时检测交易模式的变化。
    
-   高斯性检验：在每个检测到的交易模式内，使用Jarque-Bera检验验证了数据的高斯性假设。
    
-   残差自相关性检验：使用Ljung-Box检验验证了模型残差在交易模式内不存在序列相关性。
    

### **4\. 模型估计和实证分析**

作者在TSLA和MSFT的股票数据上估计了BOCPD、MBO和MBOC模型，并与ARMA(1,1)模型进行了比较。实证分析表明，MBOC模型在样本外预测性能上超越了其他模型，并且通过Ljung-Box测试验证了模型在捕捉订单流序列相关性方面的有效性。

-   ### **4.1 模型比较**
    

-   作者首先对三种模型（BOCPD、MBO和MBOC）进行了比较，并且与ARMA(1,1)模型进行了对比。这一部分的目的是评估不同模型在预测订单流方面的性能。性能通过计算均方误差（MSE）来衡量，MSE越低，表示模型的预测性能越好。
    
    ![](assets/003.png)
    
    ![](assets/004.png)
    

-   ### **4.2 实证分析**
    

-   实证分析部分进一步探讨了通过MBOC模型识别出的交易模式的统计特性：
    
    ![](assets/005.png)
    
-   #### **4.2.1 交易模式的定义和长度分布**
    

-   作者定义了交易模式，并分析了这些模式的长度分布。他们发现，交易模式的长度大致符合指数分布，这与模型中恒定风险函数的假设一致。
    

-   #### **4.2.2 高斯性检验**
    

-   在每个检测到的交易模式内，使用Jarque-Bera (JB) 检验来测试数据的高斯性。结果表明，在大多数情况下，可以在接受置信水平下认为数据在交易模式内是高斯分布的。
    
    ![](assets/006.png)
    

-   #### **4.2.3 残差自相关性检验**
    

-   使用Ljung-Box检验来评估每个交易模式内残差的自相关性。检验结果表明，MBOC模型能够很好地捕捉订单流的序列相关性，并且在交易模式内残差几乎不表现出自相关性。
    

-   ### **4.3 价格影响分析**
    

-   作者研究了交易模式内的价格动态，并分析了价格变化与交易量之间的关系：
    
-   #### **4.3.1 价格与时间的关系**
    

-   通过计算交易模式内的平均价格变化，作者发现价格动态呈现出凹函数的形状，这与大宗订单执行期间的观察结果一致。
    

-   #### **4.3.2 价格与交易量的关系**
    

-   作者还研究了交易模式内的总价格变化与总净交易量之间的关系，并发现这一关系符合次线性幂律，即平方根影响律。
    

-   ### **4.4 在线预测**
    

-   作者探讨了如何利用在线检测到的交易模式信息来预测订单流和价格变化：
    
-   #### **4.4.1 订单流的在线预测**
    

-   利用交易模式信息，作者提出了一种在线预测方法，并发现与无条件使用历史订单流信息的方法相比，利用当前交易模式的信息可以提供更好的订单流预测。
    

-   #### **4.4.2 市场影响的在线预测**
    

-   作者还提出了一种基于交易模式的市场影响在线预测方法，并发现知道一个新的交易模式已经开始可以显著提高对未来价格变化的预测能力。
    

-   ### **结果**
    

-   MBOC模型在预测订单流方面表现最佳，超越了BOCPD、MBO模型和ARMA(1,1)模型。
    
-   通过模型检验，确认了算法输出的交易模式在统计上是合理且没有序列相关性的。
    
-   作者发现交易模式内的订单流和价格动态与大宗订单执行的特征相似，这支持了使用交易模式来解释市场长期记忆的观点。
    

### **5\. 交易模式内的价格影响**

-   论文研究了在检测到的订单流交易模式内的平均价格动态，并测量了相同交易模式内总价格变化与总净交易量之间的关系。
    
    ![](assets/007.png)
    
-   作者发现价格动态是时间的凹函数，并且这种凹性随着交易量的变化而增加，这与大宗订单执行期间观察到的现象一致。
    
    ![](assets/008.png)
    

### **6\. 在线预测订单流和市场影响**

-   论文探讨了如何利用在线检测到的交易模式信息来预测后续的订单流和价格变化。
    
-   作者提出了一种基于交易模式的在线预测方法，并发现利用当前交易模式的订单流信息可以提供对未来价格变化的显著预测能力。
    
    ![](assets/009.png)
    

### **7\. 结论**

-   作者得出结论，提出的基于贝叶斯在线变点检测的方法能够实时识别金融资产订单流中的交易模式，并且可以显著提高订单流和价格动态的预测准确性。
    
-   论文还讨论了这些方法在金融应用中的潜在用途，如最优交易、市场制造和alpha信号检测。
    

  

  

**论文及代码下载见星球**

  

往期回顾

       QuantML-Qlib开发版：

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

![](assets/010.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/011.jpg)

![](assets/012.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**