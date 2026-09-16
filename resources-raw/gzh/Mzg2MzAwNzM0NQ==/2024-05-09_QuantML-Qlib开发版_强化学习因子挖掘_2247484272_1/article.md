# QuantML-Qlib开发版 | 强化学习因子挖掘

QuantML QuantML 2024-05-09 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=cf38b1d823c9b7fbb0b17799dbcb07b984d5beab9f6ad291821b70d8d46e5942506db54ca883#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=cf38b1d823c9b7fbb0b17799dbcb07b984d5beab9f6ad291821b70d8d46e5942506db54ca883#rd)

![](assets/001.png)

模型介绍

![](assets/001.png)

本文提出了一个新颖的框架，用于生成协同的公式化Alpha集合，以提高量化交易中市场趋势预测的精度。Alpha因素是量化交易中用于预测股票市场趋势的信号指标，而公式化Alpha由于其可解释性，更受业界青睐。论文的核心贡献在于提出了一个利用强化学习（Reinforcement Learning, RL）来优化Alpha生成器的框架，以直接针对下游组合模型的性能进行优化。

### **1\. 引言和背景**

-   在量化交易领域，将原始历史股票数据转换为市场趋势的指标信号（Alpha因素）是一种常见做法。
    
-   传统上，Alpha因素的发现方法主要分为基于机器学习和公式化Alpha两种。
    
-   论文指出，尽管现有的方法取得了显著的成功，但它们在不同方面仍有缺点，如机器学习Alpha因素的复杂性和低可解释性。
    
    ![](assets/002.png)
    

### **2\. 问题定义**

-   Alpha因素被定义为一个函数，它将交易日的所有股票的特征向量映射为Alpha值。
    
-   Alpha因素挖掘的任务是优化一组Alpha因素，以最大化组合模型的性能。
    
    ![](assets/003.png)
    

### **3\. 方法论**

-   Alpha组合模型：使用线性模型结合多个公式化Alpha，以实现预测中的最优性能。
    
-   Alpha生成器：基于策略梯度算法的RL框架，用于生成公式化Alpha的令牌序列。
    
    ![](assets/004.png)
    

#### **3.1 Alpha组合模型**

使用线性组合模型，通过最小化均方误差（MSE）来优化Alpha集合的权重。Alpha组合模型的结构相对简单，它主要由以下部分组成：

1.  输入特征：模型接收一组股票的特征向量，这些特征可能包括股票的开盘价、收盘价、最高价、最低价、成交量等。
    
2.  Alpha集合：模型结合一组公式化Alpha因素 F，每个Alpha因素都是一个从输入特征到Alpha值的函数。
    
3.  权重向量：每个Alpha因素都有一个对应的权重 𝑤\=(𝑤1,𝑤2,...,𝑤𝑛)w，权重向量决定了各个Alpha因素在组合中的重要性。
    
4.  线性组合：模型通过线性组合的方式将各个Alpha因素结合起来，形成最终的预测信号。
    

Alpha组合模型的原理基于以下几个关键步骤：

1.  标准化处理：为了使不同规模的Alpha值能够在同一框架下比较，首先对Alpha值进行中心化和标准化处理，使其均值为0，标准差为1。
    
2.  线性组合：将标准化后的Alpha值通过权重向量进行线性组合，得到最终的预测信号，即“mega-alpha”
    
3.  损失函数：模型使用均方误差（MSE）作为损失函数，以评估预测信号与实际股票趋势之间的差异：其中 𝑁N 是股票的数量，  
    y是第 𝑖i 支股票的实际趋势值。
    
4.  权重优化：通过梯度下降或其他优化算法来调整权重向量 𝑤w，以最小化损失函数 𝐿(𝑤)。
    
5.  模型评估：使用信息系数（IC）来评估组合模型的性能。IC是Alpha值与股票实际趋势之间的相关性度量。
    

#### **3.2 Alpha生成器**

      Alpha生成器的结构基于Markov Decision Process (MDP)，它包括以下几个关键组件：

-   状态空间（State Space）：每个状态对应于一个令牌序列，表示当前生成表达式的一部分。状态空间的初始状态始终是BEG（开始），有效的状态总是以BEG开始，并跟随之前选择的令牌。
    
-   动作空间（Action Space）：动作是在当前状态下可以采取的令牌。为了确保生成的RPN序列的正确性，只有子集中的动作在特定状态下是允许的。
    
-   令牌（Tokens）：令牌是操作符、特征或常数值的抽象表示。例如，操作符可以是加法（Add）、减法（Subtract），特征可以是开盘价（open）、成交量（volume）等。
    
-   动态（Dynamics）：给定状态和动作，可以确定性地获得下一个状态。下一个状态是通过将动作令牌添加到当前状态的序列末尾来生成的。
    
-   奖励和回报（Rewards and Returns）：MDP不为部分形成的序列立即提供奖励。在每个episode结束时，如果最终状态有效，则将其解析为公式函数，并在组合模型中评估。然后使用模型的性能作为该episode的回报。
    
    Alpha生成器的原理基于以下步骤：
    
-   初始化：使用BEG令牌初始化状态空间。
    
-   策略选择：RL代理根据当前状态选择一个动作（令牌），这个选择是基于策略网络输出的概率分布。
    
-   动作执行：执行选定的动作，将新的令牌添加到当前的表达式序列中。
    
-   状态更新：根据执行的动作更新状态空间。
    
-   评估和奖励：如果生成的表达式是合法的，它将被评估并用于组合模型。组合模型的性能提升作为奖励信号反馈给RL代理。
    
-   策略优化：使用PPO（Proximal Policy Optimization）算法来优化RL代理的策略，以提高未来生成有效Alpha因素的概率。
    

### **4\. 实验**

-   设计实验以评估提出的框架与先前的Alpha挖掘方法的比较，并测试模型在更现实的交易设置下的表现。
    
      
    
    ![](assets/005.png)
    

  

  

2\. 代码部分

  

强化学习因子挖掘现已加入QuantML-Qlib框架，位于alphazoo目录下：  

![](assets/006.png)

  

PPO算法运行代码在train\_maskable\_ppo.py中，可以使用CPU/GPU进行训练，支持日频和分钟频因子挖掘。在conf中设置相应的股票池，起始日期，频率等信息。

```
dataset_conf = {
```

PPO算法主体，policy可以选择MlpPolicy,CnnPolicy或者 MultiInputPolicy，特征提取网络支持LSTM和Transformer（Encoder or Decoder):

```
model = MaskablePPO(
```

设置好相应的参数之后，运行函数，其中csi300表示股票池，pool\_capacity表示个体的数量，值越大因子结构复杂，target为挖掘的目标频率，5为周频因子，step代表训练轮数。

```
  main(42, 'csi300', pool_capacity = 10, target = 5, steps = 10000)
```

  

运行结果：  

pool\_capacity=10 ： 

![](assets/007.png)

‍

  

pool\_capacity=100 ：

![](assets/008.png)

仅用基础量价数据训练10万轮之后，周频因子IC大致在0.08左右，月频因子IC在0.14左右。  

  

  

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

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)

![](assets/011.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**

  

  

  

![](assets/012.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/012.gif)