# QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测

QuantML QuantML 2024-05-06 13:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=cf95c6d531b850c104096f276e233a5c0aa4e23fc2dae052ba1a83ddbaf24d27ab60938af4d1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=cf95c6d531b850c104096f276e233a5c0aa4e23fc2dae052ba1a83ddbaf24d27ab60938af4d1#rd)

![](assets/001.png)

模型介绍

![](assets/001.png)

本文提出了一种新的模型，名为iTransformer，它是一种改进的Transformer架构，专门用于时间序列预测任务。

![](assets/002.png)

### **1\. 引言和背景**

-   论文首先讨论了线性预测模型的兴起，这些模型在性能和效率上超过了基于Transformer的预测器。
    
-   Transformer模型在自然语言处理（NLP）和计算机视觉（CV）中取得了巨大成功，但在时间序列预测方面面临挑战，尤其是在处理具有较大回溯窗口的序列时。
    

### **2\. iTransformer模型**

iTransformer模型是对传统Transformer架构的一种改进，专门针对时间序列预测任务。下面是iTransformer模型结构的详细介绍：

![](assets/003.png)

###     **a. 整体架构**

    iTransformer采用了仅编码器（encoder-only）的Transformer架构，包括嵌入层、投影层和多个Transformer块。

![](assets/004.png)

![](assets/005.png)

###     **b. 嵌入层（Embedding）**

-   每个时间序列独立嵌入为变量令牌（variate tokens）。
    
-   使用多层感知机（MLP）将原始序列嵌入到高维空间。
    

###     **c. iTransformer块（iTransformer Blocks）**

    每个iTransformer块包含以下三个主要组件：

####         **c.1 自注意力机制（Self-Attention Mechanism）**

-   应用于嵌入的变量令牌，以捕捉多变量之间的相关性。
    
-   使用线性投影生成查询（Query）、键（Key）和值（Value）。
    
-   通过注意力分数计算，确定不同变量之间的权重。
    

####         **c.2 前馈网络（Feed-Forward Network, FFN）**

-   应用于每个变量令牌的序列表示，以学习非线性表示。
    
-   FFN通过密集的非线性连接对观察到的序列进行编码，并解码表示以预测未来的序列。
    

####         **c.3 层归一化（Layer Normalization）**

-   应用于每个变量令牌的序列表示，以减少变量之间的差异。
    
-   与标准Transformer不同，iTransformer在序列表示上进行归一化，而不是在同一个时间戳的多变量表示上。
    

###    **d. 预测（Projection）**

###     最后一层的输出通过另一个MLP进行投影，以生成预测的时间序列。

###    **e. 架构特点**

-   ### **变量中心表示：**iTransformer通过将整个时间序列作为一个变量令牌嵌入，从而更好地捕捉多变量之间的相关性。
    
-   ### **翻转维度：**与传统Transformer不同，iTransformer在变量维度上应用自注意力机制，在时间维度上应用前馈网络。
    
-   ### **灵活性：**iTransformer允许在训练和推理时输入不同数量的变量，使其能够更灵活地处理不同的数据集。
    

###     **f. 训练策略**

-   论文还提出了一种高效的训练策略，通过在每个批次中随机选择部分变量进行训练，从而显著减少了内存占用和计算成本。
    

### **4\. 实验结果**

-   iTransformer在多个真实世界的数据集上进行了测试，并与现有的先进深度预测器进行了比较。![](assets/006.png)
    
-   实验结果表明，iTransformer在预测高维时间序列方面表现出色，并且在多个数据集上实现了最先进的性能。
    
    ![](assets/007.png)
    
    ![](assets/008.png)
    

### **5\. 相关工作**

-   论文回顾了Transformer在时间序列预测中的应用，并将其改进分为四个类别：组件适应、序列处理、原始架构的修改以及iTransformer所采用的架构翻转。
    

### **6\. 模型分析**

-   通过一系列消融实验，论文验证了iTransformer中不同组件的有效性。
    
-   使用中心核排列（CKA）相似性来分析表示的相似性，结果表明iTransformer通过翻转维度学习了更合适的序列表示。
    
    ![](assets/009.png)
    

  

  

  

2\. 代码部分

  

我们在中QuantML-Qlib实现iTransformer模型。由于有部分c代码，需要编译后再使用，在QuantML-Qlib根目录下运行以下命令进行编译

```
python  setup.py build_ext --inplace
```

然后将我们的代码拷贝进examples/benchmarks

![](assets/010.png)

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

模型代码在iTransformer.py中

```
class iTransformerModel(nn.Module):
```

  

  

QuantML-Qlib项目代码见星球。

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

  

往期回顾

QuantML-Qlib开发版：  
[QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484190&idx=1&sn=836ef4cef6c9183a51de163656cd13c5&chksm=ce7e6400f909ed16395bf0f07d9a201ee6c63e79e16130758acf964d81675dacd299e70c6166&scene=21#wechat_redirect)  

[QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)

[QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)

  

前沿论文代码：

[取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)

[WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)

[WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)

[WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)

[KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)

[ICLR'24 | FTS-Diffusion: 用于合成具有不规则和尺度不变模式的金融时间序列的生成框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483907&idx=1&sn=df124c03a74981eba923fee63613ecfd&chksm=ce7e651df909ec0b2f6029db3e29992bb41210c8b9f76f979b7968d0fab1ac913848004ac44d&scene=21#wechat_redirect)

[ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)

[CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)

[IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)

[AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)

[AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)

[AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)

[COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)

[ICAART 2024 | DTX: 基于TBSE Level2多线程市场模型的深度学习交易系统](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483965&idx=1&sn=e2fda25ce1bc8a4b9393158321dc2a14&chksm=ce7e6523f909ec3538bd37e07689308380cad55b02c35a7d4652a3e7d7fd3306a40253341c61&scene=21#wechat_redirect)

  

  

**点击蓝字**

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/012.jpg)

![](assets/013.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**

  

  

  

![](assets/014.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/014.gif)