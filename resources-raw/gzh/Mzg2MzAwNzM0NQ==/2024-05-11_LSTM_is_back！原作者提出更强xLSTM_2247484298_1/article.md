# LSTM is back！原作者提出更强xLSTM

QuantML QuantML 2024-05-11 18:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484298&idx=1&sn=0246750747d8ea7dae412cfb3bde8a52&chksm=cfc1a8ca5a8ff1d18df7f967d91e25b659cb422eda92ef242c428c6ce122d6902c9f4b082f9e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484298&idx=1&sn=0246750747d8ea7dae412cfb3bde8a52&chksm=cfc1a8ca5a8ff1d18df7f967d91e25b659cb422eda92ef242c428c6ce122d6902c9f4b082f9e#rd)

Content  

> 论文下载地址：\[2405.04517\] xLSTM: Extended Long Short-Term Memory (arxiv.org)

  

本文介绍了一种名为xLSTM（Extended Long Short-Term Memory）的新型长短期记忆网络结构，旨在克服传统LSTM（Long Short-Term Memory）网络的一些限制，并探索将LSTM扩展到数十亿参数规模时在语言建模方面的潜力。

![](assets/001.png)

### **1\. 引言和背景**

-   LSTM在1990年代被提出，用以解决循环神经网络（RNN）的梯度消失问题。
    
-   LSTM在多种序列任务中表现出色，但随着Transformer技术的出现，其在大规模语言建模方面的应用受到了挑战。
    

### **2\. xLSTM模型**

#### **2.1 传统LSTM的限制**

-   存储修改能力不足：LSTM难以在发现更相似的向量时修正已存储的值。
    
-   存储容量有限：信息必须被压缩进标量单元状态，限制了其存储能力。
    
-   缺乏可并行性：由于隐藏层之间的混合，LSTM需要按顺序处理，限制了其并行化能力。
    
    ![](assets/002.png)
    

#### **2.2 xLSTM的改进**

-   指数门控（Exponential Gating）：引入指数门控和适当的归一化与稳定化技术，以解决存储修改能力不足的问题。
    
-   记忆结构修改：
    

-   sLSTM：具有标量记忆、标量更新和新的记忆混合技术。
    
    ![](assets/003.png)
    
-   mLSTM：完全可并行化，具有矩阵记忆和协方差更新规则。
    
    ![](assets/004.png)
    

#### **2.3 xLSTM块和架构**

-   将新的LSTM变体集成到残差块模块中，形成xLSTM块，然后将这些块堆叠成xLSTM架构。
    
    ![](assets/005.png)
    

### **3\. xLSTM模型的组成部分**

xLSTM（Extended Long Short-Term Memory）是一种新型的循环神经网络（RNN）结构，旨在解决传统LSTM的一些限制，并提升其在大规模语言建模任务中的性能。以下是xLSTM结构的详细介绍：

###     **3.1. xLSTM的核心思想**

-   指数门控（Exponential Gating）：引入指数激活函数的门控机制，以改进信息的存储和更新能力。
    
-   记忆结构修改：扩展了LSTM的记忆单元，包括标量记忆（sLSTM）和矩阵记忆（mLSTM）。
    

###     **3.2. xLSTM的变体**

####         **3.2.1 sLSTM（Scalar LSTM）**

-   标量记忆和更新：sLSTM保留了LSTM的标量记忆状态，但引入了指数门控来改进记忆的修改能力。
    
-   新的记忆混合技术：允许在多个记忆单元之间进行混合，增强了模型的表达能力。
    

####         **3.2.2 mLSTM（Matrix LSTM）**

-   矩阵记忆：将传统的LSTM标量记忆状态扩展为矩阵，大幅提高了模型的存储容量。
    
-   协方差更新规则：使用协方差矩阵来更新记忆状态，允许更复杂的信息编码和检索。
    

###     **3.3. xLSTM块**

-   残差连接：xLSTM块通过残差连接构建，这有助于训练深层网络。
    
-   上投影和下投影：在sLSTM和mLSTM中使用上投影和下投影来改变信息的维度，以利于处理和学习。
    

###     **3.4. xLSTM架构**

-   堆叠的xLSTM块：通过堆叠多个xLSTM块来构建完整的xLSTM架构，类似于构建深度卷积网络和Transformer。
    
-   预层归一化（pre-LayerNorm）：在每个xLSTM块之前使用，有助于稳定训练过程。
    

###     **3.5. 门控机制**

-   输入门：控制新信息的流入。
    
-   遗忘门：决定哪些信息应该从记忆状态中被遗忘。
    
-   输出门：控制记忆状态到隐藏状态的转换。
    

###     **3.6. 激活函数**

-   指数激活：在门控中使用指数激活函数，以允许更大的动态范围和更精细的控制。
    
-   tanh激活：通常用于隐藏状态的激活，以保持数值的稳定性。
    

###     **3.7. 训练和稳定性**

-   稳定化技术：如引入额外的状态来稳定门控的激活，防止数值溢出。
    
-   归一化：使用层归一化（LayerNorm）或组归一化（GroupNorm）来稳定隐藏状态的分布。
    

###     **3.8. 并行化**

-   mLSTM的并行化：由于没有隐藏层之间的连接，mLSTM可以并行处理输入，提高了计算效率。
    
-   sLSTM的非并行化：由于存在记忆混合，sLSTM的某些操作需要按顺序执行，限制了其并行化能力。
    

### **4\. 实验**

-   论文通过一系列实验评估了xLSTM，并与其他方法（如Transformer和状态空间模型）进行了比较。
    
    ![](assets/006.png)
    
    ![](assets/007.png)
    
-   在15B个token上训练的模型在SlimPajama数据集上的验证集困惑度（perplexity）进行了比较。
    
-   对xLSTM进行了消融研究，以了解不同组件对性能提升的贡献。
    
    ![](assets/008.png)
    

### **5\. 限制**

-   论文讨论了xLSTM的一些限制，包括sLSTM的非并行化操作、mLSTM的高计算复杂性等。
    

### **6\. 结论**

-   xLSTM在语言建模方面与现有的Transformer和状态空间模型相比表现出色，表明其在大规模语言模型构建中有潜力成为有力的竞争者。
    
    ![](assets/009.png)
    

  

欢迎入群交流：  

![](assets/010.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

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

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/012.jpg)