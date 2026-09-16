# TLOB：基于双重注意力机制的Transformer模型用于限价订单簿数据预测

QuantML QuantML 2025-02-28 21:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489480&idx=1&sn=9b6b2c91f1b6494ba338b882041715aa&chksm=cf6c057dfcc2fad324a19067cf0c94d44ddde3af381cf0456e14b524f2c6e75c0af7918f5e38#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489480&idx=1&sn=9b6b2c91f1b6494ba338b882041715aa&chksm=cf6c057dfcc2fad324a19067cf0c94d44ddde3af381cf0456e14b524f2c6e75c0af7918f5e38#rd)

### 

### 1\. 引言

过去几十年，全球金融市场经历了从人工交易到复杂电子平台的深刻变革。到2020年，美国超过99%的股票交易通过电子平台完成，与2000年的15%形成鲜明对比。这一变革的核心是电子限价订单簿（LOB），它已成为现代金融市场的基石。LOB是一个动态数据结构，记录了按价格水平组织的限价订单的持续流入，反映了供需的实时平衡。

然而，LOB数据的这种多维结构（涵盖价格水平和交易量）使得理解市场行为、预测股票价格趋势以及模拟现实市场条件变得复杂。LOB数据的非平稳性（其随机行为特征）使得对股票价格走势的建模极具挑战性。传统统计方法难以捕捉这些复杂性，尤其是在预测短期价格趋势时。

近年来，深度学习的进步为应对这些挑战提供了新途径，使得能够对LOB数据中固有的非线性关系和时间依赖性进行建模。股票价格趋势预测（SPTP）仍然是金融市场中一个最具挑战性且经济意义重大的问题，尤其在高频交易领域，算法试图利用短期价格波动来获利。

### 2\. 背景

在当今竞争激烈的金融环境中，电子限价订单簿（LOB）是记录和管理市场交易的主要机制。在限价订单簿市场中，交易者可以提交订单，以预定价格买入或卖出指定数量的资产。主要订单类型包括：

-   **市价订单**：以最佳可用价格立即执行预定数量的订单。
    
-   **限价订单**：允许交易者设定他们希望完成交易的最大（买入）或最小（卖出）价格，并始终与指定价格相关联的数量。
    
-   **取消订单**：用于移除活跃的限价订单。
    

LOB是一个数据结构，它根据预定义的规则维护和匹配活跃的限价订单和市价订单。该结构对所有市场参与者透明，并且每个事件（包括订单的放置、修改、取消和执行）都会对其进行持续更新。最广泛采用的订单匹配机制是连续双重拍卖（CDA）。在CDA框架下，当最佳买价（买方愿意提供的最高价格）和最佳卖价（卖方愿意接受的最低价格）重叠时，订单就会被执行。这种机制促进了市场参与者之间的持续和竞争性交易。证券的价格通常定义为中间价，即最佳买价和最佳卖价的平均值，而两者之间的差异代表买卖价差。

鉴于限价订单按不同的价格水平组织成不同的深度级别，每个级别都包含买价、买量、卖价和卖量，因此LOB的时间演变构成了一个复杂的多维时间问题。对LOB数据的研究大致可分为四类：对LOB动态的实证分析、价格和波动性预测、LOB动态的随机建模以及LOB市场模拟。

### 3\. 相关工作

建模LOB相关复杂数据结构和海量数据量的挑战，推动了深度学习算法在相关建模和预测任务中的发展。本节将总结股票价格趋势预测（SPTP）任务中的最新深度学习模型，该任务包括以高频分辨率预测中间价格运动方向。

-   **传统方法**：Tsantekidis等人利用基于长短期记忆（LSTM）层的循环神经网络（RNN）和卷积神经网络（CNN）来预测中间价格运动。
    
-   **混合模型**：Zhang等人提出了DeepLOB模型，该模型利用CNN和LSTM层的组合来预测中间价格运动。
    
-   **注意力机制的应用**：Kiesel等人引入了Axial-LOB，它使用轴向注意力将2D注意力分解为两个1D注意力模块，一个用于特征轴，一个用于时间轴。
    
-   **其他方法**：Prata等人评估了15种用于股票预测的深度学习模型，包括上述所有模型。尽管其中一些模型在FI-2010数据集上表现良好，但大多数模型在应用于更高效股票时缺乏鲁棒性和通用性。
    

### 4\. 任务定义

我们用时间序列  表示LOB的演变，其中每个  被称为一个LOB记录，， 是LOB观察的数量， 是级别的数量。具体来说：

其中  和  是1至  级别的价格， 和  是相应的交易量。

![](assets/001.png)

**趋势定义**：我们采用三元分类系统对价格趋势进行分类：

-   **U（上升）**：表示价格上涨趋势。
    
-   **D（下降）**：表示价格下降趋势。
    
-   **S（稳定）**：表示价格波动幅度较小。
    

在股票市场中，中间价通常被认为是实际股票价格的最可靠的单值指标。然而，由于市场固有的波动性和外生冲击，中间价可能会表现出相当大的波动性。因此，对连续中间价  进行标记通常会导致噪声标签。

为了缓解这种情况，许多标记策略采用平滑的中间价函数，通过选择“窗口长度”对价格进行平均，以减少短期噪声并更好地反映持续的方向性变动。例如，Tsantekidis等人提出对过去的价格进行平滑，并定义：

其中  表示窗口长度， 表示预测范围。我们提出的方法 (c) 中， 和  是独立定义的，提供了一种更灵活、更无偏的方法。

百分比变化则定义为：

如果  ，则将趋势分类为上升；如果  ，则将趋势分类为下降；如果  ，则将趋势分类为稳定。阈值  通常选择以平衡三个类别，而不是反映交易成本。然而，我们认为，将  与交易成本联系起来可以更好地将趋势预测与盈利能力保持一致。因此，在第7.4节中，我们探讨了将  设置为平均价差（最佳买价和最佳卖价之间的差异）作为中间价的一个百分比，因为价差代表主要的交易成本。

### 5\. 模型

我们提出了两种用于使用限价订单簿（LOB）数据进行股票价格趋势预测（SPTP）的新型深度学习模型。第一个模型称为MLPLOB，是一个简单的基于MLP的模型。第二个模型TLOB利用了双重注意力Transformer方法。这两种模型都将一系列LOB时间序列作为输入，该时间序列由最后  个LOB快照组成，包含10个LOB级别。

#### 5.1 MLPLOB

基准研究的关键发现表明，尽管用于SPTP的特殊深度学习架构层出不穷，但当在多样化和复杂的数据集上进行测试时，它们的性能往往趋于较低值。受Tolstikhin等人和Zeng等人工作的启发，他们证明了简单的基于MLP的模型在某些领域可以与最先进的方法相媲美，我们开发了一种基于MLP的架构，用于使用LOB数据进行SPTP，称为MLPLOB。

**架构概述**：MLPLOB由多个块组成，每个块包含两种类型的MLP层：

1.  **特征混合MLP**：沿特征轴操作。
    
2.  **时间混合MLP**：沿时间轴操作。
    

这种设计旨在捕捉LOB数据中的空间和时间关系，这是Sirignano和Cont确定的LOB动态和建模的基本特征。

**模型简单性和各向同性设计**：MLPLOB架构仅依赖于矩阵乘法、重塑操作和标量非线性。它还采用各向同性设计，其中每个块（除了初始投影之外）具有恒定的维度。这与在许多CNN中发现的金字塔布局形成对比（它们在增加通道深度的同时降低空间分辨率）。值得注意的是，各向同性设计在Transformer和循环神经网络（RNN）中也很常见。

**最终预测**：经过几轮特征和时间混合后，MLPLOB执行降维，将所有特征合并为一个向量，然后通过几个全连接层，该层逐渐减小向量维度，并最终通过标准分类头。网络输出最终时间步的定向趋势（上升、下降或稳定）。我们在设计MLPLOB时的主要目标是展示一个精心构建的基于MLP的模型可以匹配或超过SPTP任务中的更复杂架构。同样的方法也应用于TLOB。

#### 5.2 TLOB

Transformer架构在深度学习领域取得了重大突破，特别是在自然语言处理和时间序列建模方面。其关键优势在于能够在不遭受严重的梯度消失或遗忘的情况下捕捉长程依赖性，并且性能通常会随着数据量的增加而提高。由于大量金融数据（以TB为单位）可用，Transformer非常适合LOB建模。

**双重注意力块**：我们提出了TLOB，这是一种专门为限价订单簿数据设计的基于Transformer的架构。每个TLOB块包含：

1.  **LOB快照上的自注意力（时间轴）**：计算不同LOB快照之间的注意力值，捕捉连续快照之间的时间依赖性。
    
2.  **LOB特征上的自注意力（空间轴）**：计算LOB特征之间的注意力值，捕捉不同价格-交易量特征之间的空间关系。
    
3.  **MLPLOB块**：取代了通常的Transformer前馈网络，以增强模型结合空间和时间信号的能力。
    

**架构图**：如图2所示。![](assets/002.png)

**时间与特征注意力**：虽然标准Transformer沿单一维度处理标记，但LOB数据自然需要学习时间和空间依赖性。例如，时间步  可以揭示更深或更浅的级别如何相互关联，以及趋势如何随过去快照演变。因此，双重注意力明确解决了这两个变化轴。为了调查每种注意力层的的重要性，我们进行了消融研究（第7.5节）。

**双线性归一化层**：为了解决金融时间序列中的非平稳性和幅度差异（价格和规模），我们采用双线性归一化层作为初始层。与传统的  分数归一化不同，后者可能在推理时因分布偏移而失效，双线性归一化适应于批处理特定的统计数据，即使市场条件发生变化，也能保持稳健的性能。MLPLOB中也使用了相同的层。

**位置编码**：由于自注意力是排列不变的，我们结合了正弦位置嵌入，以保持每个LOB窗口内的时序结构。这种编码确保TLOB尊重快照的时序顺序，这对于建模价格演变至关重要。

通过结合两种不同的自注意力操作（首先是时间，然后是空间）以及MLPLOB前馈组件，TLOB旨在捕捉LOB数据中存在的复杂市场微观结构。其Transformer基础使其能够有效地扩展到大型数据集，而双重注意力机制更好地处理金融时间序列特有的细粒度特征交互和序列依赖性。

### 6\. 实验

我们对MLPLOB和TLOB模型在基准FI-2010数据集和由特斯拉和英特尔组成的TSLA-INTC数据集上的训练和测试进行了全面评估。TLOB和MLPLOB在每个数据集和每个范围内都超过了SoTA性能。TLOB在较大范围内表现最佳，而MLPLOB在较短范围内表现最佳。我们的实验超出了仅仅展示TLOB的SoTA性能，旨在解决几个关键的研究问题：(1) 股票价格是否比过去更难预测？(2) 如果我们将  设置为平均价差会怎样？(3) 时间和空间注意力是否必要？通过这些研究，我们不仅旨在验证我们模型的预测能力，而且还要为金融预测中深度学习应用提供更广泛的理解。

![](assets/003.png)

![](assets/004.png)

### 7\. 结果

**FI-2010结果**：表2展示了FI-2010基准数据集上四个预测范围的性能比较。在附录（B）中，我们还报告了范围100的精度和召回曲线。MLPLOB和TLOB表现出非常高的精度，即使在较高的召回值下，也始终在所有召回水平上实现比其它模型更高的精度。基线的结果是从Prata等人的基准中提取的，因为FI-2010数据集的设置是相同的。MLPLOB和TLOB在中分析的所有模型中表现优于其它模型，超过了最先进的性能。有趣的是，MLPLOB在前三个范围内表现出最佳性能。值得注意的是，MLPLOB和TLOB之间的性能差异很小，这表明，正如我们将在第7.2节中展示的，可以归因于FI-2010数据集的较低复杂性，这解释了对于这个特定数据集，更复杂的架构如TLOB的无用性。

![](assets/005.png)

**特斯拉和英特尔结果**：表3和表4分别展示了特斯拉和英特尔的F1得分。对于每只股票，我们训练了不同的模型。在附录（B）中，我们还报告了范围等于100的精度和召回曲线。对于INTC，它们在低召回值下表现出优异的精度，表明它们能够准确识别最自信的积极实例。MLPLOB在前两个范围内（10，20）优于每个模型，而在较长范围内（50，100）TLOB优于每个模型。这在意料之中，因为Transformer擅长长程依赖性。值得注意的是，MLPLOB和TLOB之间在较短范围内的性能差异很小（≈0.5），而在较长范围内则相当显著（≈7）。正如预期的那样，范围越长，预测越困难。总的来说，与FI-2010相比，性能要低得多。我们推测这是因为FI-2010与纳斯达克股票相比，其复杂性较低。这源于它由芬兰股票组成，这些股票流动性较差，效率低于英特尔和特斯拉等纳斯达克股票。此外，数据可以追溯到2010年。实际上，正如后续实验将展示的，随着时间的推移，预测难度会增加。我们实验的结果得到了几项关于该主题的工作的支持。所有模型都训练到收敛。值得注意的是，TLOB和MLPLOB达到收敛所需的周期不到BiNCTABL和DeepLOB的一半。

![](assets/006.png)

### 8\. 结论

我们提出了两种新的深度学习模型：MLPLOB：一个简化的但有效的基于MLP的架构；TLOB：一个基于Transformer的方法，用于限价订单簿（LOB）数据的股票价格趋势预测任务。这两种模型都表现出优于现有最先进方法的性能，TLOB在处理高频市场数据方面显示出特别的希望。纳斯达克股票（特斯拉，英特尔）证明比芬兰股票（FI-2010）更难预测。我们的研究还表明，随着预测范围的增加，预测准确性下降，这突出了金融市场中长期预测的内在挑战。

####   

  

  

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/007.png)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib重磅更新：DeepSeek核心模型结构用于选股](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489025&idx=1&sn=35941156783794d719e6ff891ce720c3&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 还在使用MSE？试试这些更加适合金融预测的损失函数](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487997&idx=1&sn=e05e8e0dafa605615d425ff1f0702c4b&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 如何运行日内中高频模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰SAM：提升AI量化模型的泛化性能 研报复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487238&idx=1&sn=41cbb5b3bb3e5a277c9175ba64642259&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰AlphaNet模型复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学&华泰证券 在高胜率时交易](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485500&idx=1&sn=b29e1d2efe2482165245ab6add4af051&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)[QuantML-Qlib Model | 滚动模型训练](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)
    
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
    
      
    研报复现：
    
      
    
-   [重磅更新！80+量化策略复现（持续更新中）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488528&idx=1&sn=f9c98f60baca2b690956ff6b56a2553f&scene=21#wechat_redirect)
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [研报复现 | QRS择时信号及改进](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-下](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486787&idx=1&sn=bfe98c0b8d331027191761df3b85ea8c&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-上](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486761&idx=1&sn=84a2de96dd3bc7a7fb38386684b3eec4&scene=21#wechat_redirect)
    
-   [研报复现 | 锚定反转因子](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486379&idx=1&sn=d6763bb198d0706c101f2544aa752b4f&scene=21#wechat_redirect)
    
-   [研报复现 | 另类ETF交易策略：日内动量](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&scene=21#wechat_redirect)
    
-   [研报复现 | 国盛金工：如何将隔夜涨跌变为有效的选股因子？——基于对知情交易者信息优势的刻画](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485766&idx=1&sn=89d4060fb135105b969c0ef2f145a7e0&scene=21#wechat_redirect)
    
-   [研报复现 | 招商证券：基于鳄鱼线的指数择时及轮动策略](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485702&idx=1&sn=2b0ed284177a66ee9d0e8623cd9cb1b4&scene=21#wechat_redirect)
    
-   [研报复现 | 华西金工-股票网络与网络中心度因子研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484829&idx=1&sn=3da8197374301bab9610f7ed5d4b715b&chksm=ce7e6283f909eb9509b3ebc9989fe9d140d5ee663ac8749aeb608833ff37544421d0dcd0fa9c&scene=21#wechat_redirect)  
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
-   [研报复现 | 开源证券 ：形态识别，均线的](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&scene=21#wechat_redirect)  
    
-   [Hummingbot：开源加密货币做市机器人框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489153&idx=1&sn=98198f6cca4aa5bc5646e926c358f01d&scene=21#wechat_redirect)  
    
-   [FinRLlama：基于强化学习和市场反馈的金融情感分析LLM优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489127&idx=1&sn=faad16c8ac3ca02dcb982837d03b21ab&scene=21#wechat_redirect)  
    
-   [端到端基于LLM的增强型交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&scene=21#wechat_redirect)
    
-   [基于分层强化学习的日内风险因子挖掘](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489104&idx=1&sn=c0b6938ebcf0cbd8244f87abe609798e&scene=21#wechat_redirect)
    
-   [DeepScalper：深度强化学习捕捉日内交易的短暂机会](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&scene=21#wechat_redirect)
    
-   [TradingAgents：基于多智能体LLM的金融交易框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488712&idx=1&sn=daa7fb4a9d49a621f9f54579dda4a184&scene=21#wechat_redirect)  
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)