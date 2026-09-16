# QuantML-Qlib开发版 | 清华大学时序模型Autoformer用于股票市场预测

QuantML QuantML 2024-05-21 15:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=cf82c9471de1c8583326fa3e16d72999dec90d9c1bed714ab3f519ccae85f33b1db2b9048637#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=cf82c9471de1c8583326fa3e16d72999dec90d9c1bed714ab3f519ccae85f33b1db2b9048637#rd)

![](assets/001.png)

模型介绍

![](assets/001.png)

  

论文研究了时间序列的长期预测问题，这对于实际应用（如极端天气预报和长期能源消耗规划）至关重要。作者指出，现有的基于Transformer的模型采用各种自注意力机制来发现长期依赖关系，但长期未来的复杂时间模式阻碍了模型发现可靠的依赖关系。此外，Transformer在处理长序列时需要采用稀疏版本的逐点自注意力，这导致了信息利用的瓶颈。为了克服这些限制，作者设计了Autoformer，这是一种新颖的分解架构，具有自相关机制。Autoformer通过逐步分解能力处理复杂时间序列，并基于序列周期性设计自相关机制，在子序列级别进行依赖发现和表示聚合。自相关在效率和准确性方面都优于自注意力。在长期预测方面，Autoformer实现了最先进的准确性，在六个基准测试中相对提高了38%，涵盖了能源、交通、经济、天气和疾病等五个实际应用领域。  

  

引言：时间序列预测在能源消耗、交通和经济规划、天气预报和疾病传播预测等领域有广泛应用。作者强调了将预测时间扩展到更远未来的迫切需求，并指出长期预测任务极具挑战性，因为直接从长期时间序列中发现时间依赖关系不可靠，而且标准Transformer的自注意力机制在计算上对长期预测是不切实际的。

  

相关工作：论文回顾了时间序列预测的相关模型，包括经典的ARIMA模型、循环神经网络（RNNs）、深度AR（DeepAR）、LSTNet、注意力机制的RNNs和基于时间卷积网络（TCN）的模型。此外，还讨论了将自注意力应用于长期时间序列预测的挑战，以及先前基于Transformer的预测模型如何通过改进自注意力机制来解决这些问题。

  

Autoformer架构：

Autoformer是一种新颖的深度学习架构，专门为长期时间序列预测而设计。它通过结合分解方法和自相关机制来提高预测的准确性和效率。以下是Autoformer架构的详细介绍：

![](assets/002.png)

###     1. 问题背景

    在长期时间序列预测中，传统的Transformer模型面临两个主要挑战：一是直接从长期时间序列中发现时间依赖关系不可靠；二是标准Transformer的自注意力机制在计算上对于长期预测是不切实际的，因为它具有二次时间复杂度。

###     2. Autoformer架构组成

    Autoformer架构主要由以下几个部分组成：

####         a. 分解架构（Decomposition Architecture）

-   序列分解块（Series Decomposition Block）：这是Autoformer的核心，用于处理复杂时间序列并提取更可预测的组成部分。它将时间序列分解为趋势-周期部分和季节性部分，分别反映时间序列的长期进展和季节性。
    
-   编码器（Encoder）：专注于季节性部分建模，输出包含过去季节性信息，用于帮助解码器细化预测结果。
    
-   解码器（Decoder）：包含趋势-周期成分的累积结构和堆叠的自相关机制，用于季节性成分的细化。
    

####         b. 自相关机制（Auto-Correlation Mechanism）

-   自相关：基于时间序列的周期性，通过计算序列自相关来发现子序列之间的相似性，并在子序列级别进行依赖发现和表示聚合。
    
-   时间延迟聚合（Time Delay Aggregation）：根据选择的时间延迟τ对子序列进行滚动，将相似的子序列对齐，并通过softmax归一化的置信度进行聚合。
    
    ![](assets/003.png)
    

###     3. 关键概念和技术

####         a. 分解

        Autoformer不是将分解作为预处理步骤，而是将其作为深度模型内部块，这样可以在整个预测过程中，包括过去的时间序列和预测的中间结果，逐步分解隐藏的时间序列。

####         b. 自相关

        与标准的自注意力机制不同，自相关机制基于时间序列的固有周期性，提供系列级的连接，而不是逐点的依赖和聚合。

####         c. 复杂度

        Auto-Correlation机制实现了O(L log L)的时间和空间复杂度，这对于长序列预测是至关重要的。

![](assets/004.png)

实验：作者在六个真实世界的基准数据集上广泛评估了Autoformer，涵盖了能源、交通、经济、天气和疾病等五个主流时间序列预测应用。实验结果表明，Autoformer在所有基准测试中都实现了最先进的性能，并且在不同的预测长度设置下表现一致。

![](assets/005.png)

结论：论文总结了Autoformer如何通过分解架构和自相关机制来解决长期时间序列预测问题，并在多个真实世界数据集上实现了卓越的性能。

  

  

2\. 代码部分

  

  

我们在中QuantML-Qlib实现Autoformer模型。由于有部分c代码，需要编译后再使用，在QuantML-Qlib根目录下运行以下命令进行编译

```
python  setup.py build_ext --inplace
```

  

然后将我们的代码拷贝进examples/benchmarks

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

模型代码在Autoformer.py中

```
class AutoFormerModel(nn.Module):
```

目前QuantML-Qlib支持以下模型：

![](assets/006.png)

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

加星球请扫我：

![](assets/007.jpg)

入群请扫我：

![](assets/008.webp)

  

  

往期回顾

       QuantML-Qlib开发版：

-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)  
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)  
    
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
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)  
    
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
    

  

  

**点击蓝字**

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)

  

  

  

![](assets/011.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/011.gif)