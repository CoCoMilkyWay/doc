# DeepScalper：深度强化学习捕捉日内交易的短暂机会

QuantML QuantML 2025-01-26 22:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&chksm=cf70eee013e6652712cdaec6232c44692b38e0cddbccba5a8f118b42e276f23ec31ab2d0f73f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&chksm=cf70eee013e6652712cdaec6232c44692b38e0cddbccba5a8f118b42e276f23ec31ab2d0f73f#rd)

金融市场是一个涉及全球超过90万亿美元市场资本的生态系统，吸引了数百万投资者追求理想的金融资产以实现投资目标。近年来，量化交易因其即时准确的订单执行能力和处理大量时间序列金融数据的能力而得到显著发展。日内交易，即交易者在同一天内多次买卖预先选定的金融资产以抓住日内交易机会，成为最具盈利性和风险性的量化交易任务之一。然而，大多数现有的强化学习（RL）方法关注相对低频的交易场景（例如日级），未能捕捉到日内投资机会，因为存在两大挑战：一是如何有效训练盈利的RL代理以进行日内投资决策，这涉及到高维细粒度的动作空间；二是如何学习有意义的多模态市场表示以理解金融市场的日内行为。

![](assets/001.png)

## 相关工作

传统金融方法主要基于技术分析，通过设计数百万种技术指标来生成交易信号。然而，这些基于规则的方法在捕捉日内模式方面不够敏感，仅在特定市场条件下表现良好。近年来，许多先进的机器学习方法在预测未来价格方面取得了显著进展，但金融市场的高波动性和噪声特性使得准确预测未来价格极为困难，且预测信号与盈利交易行为之间存在明显差距。强化学习方法允许训练代理直接输出盈利的交易行为，并在不同市场条件下具有更好的泛化能力。尽管如此，大多数现有方法仍关注低频交易场景，未能捕捉到日内投资机会。

## 问题定义

日内交易的目标是在同一天内通过买卖金融资产来最大化未来利润。我们定义了几个关键概念，包括OHLCV（开盘价、最高价、最低价、收盘价和成交量）、技术指标、限价单、限价订单簿、匹配系统、仓位和净值。在实际的日内交易中，交易者在每个交易日开始时分配一定数量的现金到账户中，然后在交易时间内分析市场并做出交易决策，将订单提交给匹配系统。交易系统将以最佳可用价格执行订单，并将执行结果返回给交易者。在交易日结束时，交易者以市场价格平仓所有剩余仓位，以避免隔夜风险并再次持有100%现金。日内交易的目标是在多个连续交易日（例如半年）内最大化累积利润。

![](assets/002.png)

## 深度强化学习框架DeepScalper

DeepScalper是一个深度强化学习框架，旨在通过模仿专业日内交易员的工作流程来解决上述挑战。该框架包括四个主要组件：

-   RL优化与动作分支：我们采用分支对抗Q网络（BDQ）来处理日内交易的高维细粒度动作空间。BDQ将状态依赖的动作优势分布在价格和数量两个分支中，并添加一个额外的分支来估计状态值函数。最终，通过聚合层将优势和状态值结合起来，为每个动作维度输出Q值。在推理期间，这些Q值通过argmax查询生成联合动作元组，以确定最终的交易动作。
    
-   带有 hindsight 奖励的奖励函数：为了鼓励RL代理在做出交易决策时考虑整个交易日的长期视野，我们设计了一个带有 hindsight 奖励的奖励函数。该奖励函数通过将持有资产更长时间的预期利润（以权重项 𝜆 加权）添加到原始奖励中，从而在训练日内RL代理时增加长期视野。
    
-   日内市场嵌入：为了学习有意义的多模态日内市场嵌入，我们提出了一个编码器-解码器架构，分别从微观和宏观层面表示市场。微观层面的编码器使用LOB数据和交易者的私有状态来学习微观市场嵌入，而宏观层面的编码器则使用原始OHLCV数据和技术指标来学习宏观市场嵌入。最终，我们将微观和宏观嵌入合并为市场嵌入。
    
-   风险感知辅助任务：为了在最大化利润的同时最小化风险，我们提出了一个风险感知辅助任务，即通过预测波动率来考虑市场风险。波动率是金融中描述收益统计分散度的连贯风险度量。我们通过最小化均方误差来训练网络，预测未来的波动率。
    

![](assets/003.png)![](assets/004.png)

## 实验设置

为了全面评估DeepScalper，我们在两个真实世界的数据集（股票指数和国债）上进行了评估，涵盖了三年内的六种金融资产。我们详细描述了数据集的统计信息，并进一步阐述了它们的特点。我们还介绍了用于描述宏观层面金融市场的11个时间特征，以及从5级LOB中提取的20维特征向量。

  

![](assets/005.png)

## 评估指标

我们使用四个不同的财务指标来评估DeepScalper，包括一个利润标准和三个风险调整后的利润标准：

-   总回报（TR）：整个交易期间的总体回报率。
    
-   夏普比率（SR）：考虑每单位增加风险所获得的额外回报。
    
-   卡尔马比率（CR）：预期回报除以整个交易期间的最大回撤（MDD）。
    
-   索提诺比率（SoR）：使用下行偏差（DD）作为风险度量。
    

## 基线

我们将DeepScalper与九种基线方法进行了比较，包括三种传统金融方法、三种基于预测的方法和三种强化学习方法。这些方法包括买入并持有（BAH）、均值回归（MV）、时间序列动量（TSM）、多层感知器（MLP）、门控循环单元（GRU）、梯度提升决策树（LGBM）、深度Q网络（DQN）以及DeepScalper的两个变体（DS-NH和DS-NA）。

## 预处理和实验设置

对于宏观层面的特征，我们直接根据表2中的公式计算了11个技术指标。对于微观层面的特征，我们将每个级别的订单价格和数量分别除以第一级别的价格和数量进行归一化。对于缺失值，我们用前一个价格填充空价格，用零填充空数量以保持时间序列数据的一致性。为了使评估更加现实，我们还考虑了许多实际的真实世界约束。交易费用率 𝜃 设定为股票指数期货和国债期货分别为2.3×10^-5和3×10^-6，这与现实场景一致。由于日内交易广泛使用杠杆，如保证金贷款，我们应用了固定的五倍杠杆来放大利润和波动性。时间被离散化为1分钟间隔，我们假设代理只能在每分钟结束时买卖金融期货。RL代理的账户在开始时有足够的现金购买50股资产。最大持仓位为50。我们在Tesla V100 GPU上进行了所有实验。通过网格搜索找到最优超参数。我们探索了前瞻范围 ℎ 在\[30, 60, 90, 120, 150, 180\]，hindsight奖励的重要性 𝜆 在\[1×10^-3, 5×10^-3, 1×10^-2, 5×10^-2, 1×10^-1\]和辅助任务的重要性 𝜃 在\[0.5, 1.0\]。对于神经网络架构，我们在\[32, 64, 128\]中搜索了MLP层和GRU层的隐藏单元，并使用ReLU作为激活函数。我们使用Adam作为优化器，学习率 𝜃 ∈ (1×10^-5, 1×10^-3)，并在所有金融资产上训练DeepScalper 5个周期。按照\[27\]中的迭代训练方案，我们在训练期间反复增强交易者的私有状态以提高数据效率。我们用5个不同的随机种子运行实验，并报告平均性能。在股票指数和国债数据集的每种金融资产上训练和测试Deepscalper分别需要1.5小时和3.5小时。对于其他基线，我们使用它们公共实现中的默认设置。

![](assets/006.png)

## 结果与分析

### 盈利能力与基线比较

我们在表3中比较了DeepScalper与9个最先进的基线在四个财务指标上的表现。我们观察到DeepScalper在两个数据集的7个指标中一致地产生了显著（𝑝 < 0.01）更高的性能。在股票指数数据集中，DeepScalper在所有四个指标上表现最佳。具体来说，它在总回报（TR）、夏普比率（SR）、卡尔马比率（CR）和索提诺比率（SoR）方面分别比第二名高出30.80%、33.33%、21.42%和7.50%。对于国债数据集，DeepScalper在总回报（TR）、夏普比率（SR）和卡尔马比率（CR）方面分别比第二名高出14.87%、7.47%和30.94%。对于索提诺比率（SoR），DS-NA的表现略优于DS（2%，无统计学意义）。一个可能的原因是波动率预测辅助任务与控制下行回报方差并不直接相关。此外，我们在图5中展示了测试期间每个金融期货的交易日与净值曲线。我们故意排除了BAH、DS-NH和DS-NA，以便于图形的阅读。对于传统方法，我们发现MV在大多数金融期货中表现良好。相比之下，TSM的表现要差得多。TSM失败的一个可能原因是日内交易市场中没有明显的动量效应。对于深度学习模型，GRU的整体性能优于MLP，因为它能够学习指标的时间依赖性。至于LGBM，其表现略优于深度学习模型。RL方法的平均表现最佳。

![](assets/007.png)

### 模型组件消融研究

我们在表4中对DeepScalper的各个组件进行了全面的消融研究，以了解其投资盈利能力的益处。首先，我们观察到编码器-解码器架构能够比仅使用其他宏观或微观市场信息训练的代理更好地学习多模态市场嵌入，从而分别提高了0.15%和0.38%的总回报（TR）和夏普比率（SR）。其次，我们发现将波动率预测辅助任务加入DeepScalper可以进一步提高性能，表明考虑风险可以带来稳健的市场理解。此外，我们观察到hindsight奖励可以显著提高DeepScalper评估交易决策的能力，并进一步增强盈利能力。最后，我们将所有这些组件加入DeepScalper，实现了在总回报（TR）和夏普比率（SR）方面的最佳表现。综合消融研究表明：1）DeepScalper中的每个单独组件都是有效的；2）这些组件大多是正交的，可以有效地整合在一起以进一步提高性能。

![](assets/008.png)

### Hindsight奖励的有效性

我们从两个角度分析了hindsight奖励的有效性。首先，我们探索了hindsight奖励范围和权重的影响。如图6a所示，随着𝜆的增加，代理倾向于以长期视野进行交易，并实现了更高的利润。带有𝜆 = 0.1的DeepScalper实现了最高的利润。图6b显示了hindsight范围ℎ对DeepScalper性能的影响。我们观察到，随着ℎ从30增加到180，DeepScalper的总回报逐渐增加，当ℎ > 180时，总回报开始减少。此外，我们在图7中比较了带有和不带有hindsight奖励的代理在下降趋势交易日的详细交易行为。那天的一般良好的日内交易策略是在一天开始时做空，在一天结束时做多。我们发现，没有hindsight奖励（图7a）训练的代理在捕捉局部交易机会方面表现良好，但忽略了整个交易日的长期趋势。相比之下，带有hindsight奖励（图7b）训练的代理在交易日开始时进行了大量做空操作，表明它提前意识到了下降趋势。这种交易行为是明智的，因为它捕捉到了整体趋势的大价格差距，而忽略了局部的盈亏。

![](assets/009.png)

### 风险感知辅助任务的有效性

由于金融市场存在噪声，且RL训练过程不稳定，不同随机种子之间的性能方差是基于RL的交易算法的一个主要关注点。直观上，考虑市场风险可以帮助RL代理表现得更加稳定，具有更低的性能方差。我们用5个不同的随机种子运行实验，并在图8中报告了带有/不带有风险感知辅助任务训练的RL代理之间的相对方差关系。我们发现，带有风险感知辅助任务训练的RL代理在所有六种金融资产中都实现了更低的总回报（TR）方差，在67%的金融资产中实现了更低的夏普比率（SR）方差。此外，我们测试了辅助任务重要性𝜃对DeepScalper性能的影响。自然地，波动率值的规模小于回报，这使得𝜃 = 1成为一个不错的选择。实际上，我们测试了𝜃 ∈ \[0, 0.5, 1\]，并发现辅助任务的改进对不同的重要性权重是稳健的，如图9所示。

![](assets/010.png)

### 泛化能力

我们进一步测试了我们的框架在不同金融期货（TF02和T02）之间的泛化能力。在图10中，很明显TF02和T02的价格趋势是相似的。我们假设相似的价格曲线共享相似的交易模式。然后，我们使用TF02训练集训练DeepScalper，并在TF02和T02的测试集上进行测试。我们在图11中比较了MV、GRU、LGBM和DeepScalper的性能。红色和蓝色线条分别代表TF02和T02的性能。我们观察到，MV、GRU和LGBM在这些资产之间的性能相当不同，表明它们在我们的任务上具有较差的泛化能力。一个可能的原因是MV、GRU和LGBM的交易信号涉及启发式规则或阈值。有一些潜在的交易机会接近满足交易规则或阈值，但MV、GRU和LGBM会错过这些机会。与此同时，我们的DeepScalper在TF02和T02上都实现了稳健的性能，如图11（d）所示，尽管它以前从未见过T02数据。所有这些实验都表明，DeepScalper可以学习市场的稳健表示，并实现良好的泛化能力。

## 结论

在本文中，我们专注于日内交易，并提出了DeepScalper来模仿专业日内交易员的工作流程。首先，我们应用带有动作分支的对抗Q网络来高效地训练日内RL代理。然后，我们设计了一个带有hindsight奖励的新型奖励函数，以鼓励长期视野来捕捉整体价格趋势。此外，我们设计了一个编码器-解码器架构，通过结合宏观和微观市场信息来学习稳健的市场嵌入。最后，我们提出了波动率预测作为辅助任务，以帮助代理在最大化利润的同时意识到市场风险。在两个股票指数期货和四个国债期货上的广泛实验表明，DeepScalper显著优于许多先进的方法。

  

  

论文及代码见星球，加入QuantML星球，与700+专业人士一起交流学习：

![](assets/011.png)

  

往期回顾

       QuantML-Qlib开发版：

  

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
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)[券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [利用LangGraph 和 OpenAI 打造金融分析师Agent](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [JFQA | 基于深度学习的排序特征因子模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488380&idx=1&sn=15327d544022028afab9efa2a90a0c36&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [NIPS 24 | PGN：RNN 的新继任者](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488128&idx=1&sn=a8287377302d2cdf5d1d6ddc321cdf31&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)  
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [ICLR 2024 | 通向透明的时间序列预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=ce7e624cf909eb5a44ce762087ef23bd8cfeb663aa623f0d729b99d56450abafd525d927bc5e&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)