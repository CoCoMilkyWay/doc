# 综述：深度学习用于加密货币预测

QuantML QuantML 2025-01-11 12:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488783&idx=1&sn=910e83598beac4313d0da2bbb3e138dc&chksm=cf63d6edfc7dc685e49ad962e84fde652fe845c32da617896bff58af08440d0141f3829c7197#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488783&idx=1&sn=910e83598beac4313d0da2bbb3e138dc&chksm=cf63d6edfc7dc685e49ad962e84fde652fe845c32da617896bff58af08440d0141f3829c7197#rd)

![](assets/001.png)

### 1\. 引言

传统金融生态系统通过一系列复杂的政策和结构机制来运作，这些机制由金融机构利用，以在经济中创造货币。该系统的核心是中央银行、国库和商业银行，它们被归类为三种主要的货币框架：基于商品的、基于商品支持的以及法定货币系统。由于这些机构存在通货膨胀倾向和交易效率低下等缺陷，货币的数字化已成为一场革命。加密货币旨在纠正现有系统的缺陷，如通货膨胀、金融稳定性、交易效率和降低运营成本。加密货币是一种点对点的数字交换系统，利用加密技术来创建和分配货币单位。

加密货币市场在其短暂的存在中经历了快速且不可预测的变化。其安全性由一种称为区块链的技术保障，该技术提供了全面的安全保障。截至2024年，加密货币行业已有超过5000种加密货币和580万活跃用户。由于其将密码学与货币单位相结合的固有特性，比特币（BTC）成为最受欢迎的加密货币，并在计算机科学、经济学和密码学等领域引起了关注。Satoshi Nakamoto在2009年1月以开源软件的形式匿名引入了比特币。涵盖比特币和替代币（如Civic和BitDegree）的加密货币生态系统，标志着向去中心化金融体系迈出了重要一步。

然而，由于其去中心化的性质和缺乏政府支持，加密货币市场容易出现价值的大幅波动和定价泡沫的形成。加密货币的固有波动性，包括交易量波动和价格变化，使得预测分析变得复杂。然而，波动性使其成为投机的有利可图的市场，因为它是潜在收益的来源。主要的加密货币，如比特币（BTC）、以太坊（ETH）和莱特币（LTC），在估值、交易速度、用途和波动性方面有所不同。由于该行业的显著波动性，确定这些价格趋势的确切催化剂仍然难以捉摸。尽管如此，加密货币的市场价值预计将在未来增加，预计复合年增长率为11.1%。

与此同时，金融审计部门正在发展，以将加密货币整合为有效的交易媒介。由于价格泡沫导致极端波动，投资者在之前的实例中遇到了挑战。为了克服这些障碍，必须有一个可靠的模型来帮助市场参与者识别趋势并生成准确预测。由于加密货币对多种因素敏感，包括政府政策、技术进步、公众认知和世界事件，因此精确预测加密货币价格是困难的。

一些研究人员正在肯定加密货币与其他领域（如经济学、金融、互联网甚至政治）之间的相关性。机器学习和深度学习模型由于其预测能力和对多模态时空数据和时间序列预测的建模能力，对于加密货币来说是有前景的。

### 2\. 文献综述

### 2.1 金融时间序列预测

金融时间序列预测的重点是预测资产价格。尽管有多种方法，但主要关注点一直是使用深度学习模型预测底层资产的未来走势。这一领域涵盖了许多主题，包括股票价格预测、指数预测、外汇价格预测以及商品（如石油和黄金）、债券价格、波动性和加密货币价格的预测。尽管主题范围广泛，但这些预测中应用的基本原理在所有类别中都是普遍适用的。

金融时间序列预测的研究大致分为两类：精确价格预测和趋势（方向性变动）预测。尽管精确的价格预测符合回归任务，但许多金融预测项目的主要目标并不是准确预测价格，而是正确识别价格变动的方向。这将重点转向趋势预测，或确定价格的方向性变化，使其成为比精确价格预测更为关键的调查领域。因此，趋势预测被视为一个分类问题。一些分析侧重于二元结果，只关注向上/向下的变动，而另一些则包括第三个类别（中性选项），从而构成一个三分类问题。

近年来，研究人员利用机器学习和深度学习来分析金融时间序列数据。深度学习模型在股票市场趋势预测中表现出更高的准确性。研究人员使用LSTM模型结合网格搜索和前向验证来增强NIFTY-50印度股票指数预测，并取得了显著的准确性。深度学习与频率分解方法（如经验模态分解（EMD）和完全集合经验模态分解（CEEMD））相结合，用于预测股票价格，并证明了CEEMD-CNN-LSTM和EMD-CNN-LSTM的有效性。

### 2.2 加密货币预测

一些研究人员采用了机器学习模型，如简单神经网络（SNN，也称为反向传播）和人工神经网络、支持向量机（SVM）、基于遗传算法的SNN以及通过增强拓扑的神经进化（NEAT），它同时进化架构和神经网络参数。

接下来，我们回顾了一些在预测加密货币价格方面至关重要的机器学习模型。研究表明，神经网络在比特币价格预测方面优于线性回归、逻辑回归和支持向量机（SVM）。研究人员使用自回归分布滞后（ARDL）和S&P50指数研究了市场因素对各种加密货币的影响。通过时间混合模型改进短期比特币波动性预测，优于传统方法。研究人员调查了链状物的预测性格兰杰因果关系，并确定了某些类型的链状物对比特币价格和投资风险具有最高的预测影响。使用ARIMA、自回归和移动平均模型预测比特币加权成本的短期波动性。

### 2.3 深度学习模型在加密货币预测中的应用

近年来，深度学习模型在加密货币预测中占据了重要地位。研究人员结合CNN和强化学习进行投资组合管理，利用历史加密货币定价数据在指定的组合约束下优化资产配置。通过在LSTM网络中利用自回归特性提高比特币预测准确性，优于标准LSTM。研究人员引入了一种新方法，采用逆强化学习结合基于代理的建模来预测比特币价格。LSTM网络被用来预测比特币趋势，展示了模型预测价格变化和分类市场走势的能力。

### 2.4 加密货币波动性和预测

一些研究人员专注于分析和预测加密货币的波动性。加密货币市场的波动性是影响商业和金融领域众多决策的重要因素。最近，已经确定了加密货币市场与其他金融市场之间的波动性溢出。研究人员使用非对称对角BEKK模型检查了加密货币市场的波动性动态，揭示了主要加密货币（如比特币、以太坊、瑞波币、莱特币和恒星币）的波动水平之间的显著相互依赖性和对重大新闻的响应。

### 3\. 方法论：实现与评估

### 3.1 传统模型

### 3.1.1 ARIMA

ARIMA模型，通常被称为Box-Jenkins模型，是一种常用的统计/计量经济模型，用于预测时间序列数据。ARIMA模型由三个组成部分组成：自回归（AR）、积分（I）和移动平均（MA）。积分部分表示将系列数据转换为平稳表示所需的差分次数。自回归部分描述了时间序列的当前值与其先前值之间的关系，捕捉了它们的关联性。移动平均部分表示当前观测值与其先前误差项之间的关联性。这个组成部分帮助模型捕捉时间序列中的随机变化。这三个组成部分构成了模型中的三个参数 、 和 。 代表自回归部分中的滞后观测数量。 是差分阶数，形成积分部分， 是移动平均部分中的滞后预测误差数量。

### 3.1.2 多层感知器

简单的神经网络，也称为多层感知器，是一种机器学习模型，具有输入层、输出层和至少一个隐藏层。MLP需要使用训练算法来更新权重和偏置，以确保网络的输出（预测）类似于实际观测（训练数据）。网络通过计算输入的加权和来得到隐藏层和输出层。

### 3.2 深度学习模型

### 3.2.1 LSTM网络的变体

RNN以其建模时间序列的能力而闻名，其特点是具有上下文层，因为它记忆了先前输入的信息以影响未来结果。有几种简单的RNN架构，例如Elman RNN（也称为简单RNN），这是有效建模时间序列的最早尝试之一。然而，简单的RNN在训练中遇到了问题，这是由于在处理序列数据中的长期依赖性时出现的梯度消失问题。LSTM算法被认为是RNN的增强版本。LSTM通过增强其通过隐藏层中的记忆单元保留长期依赖性的能力，克服了梯度消失的约束。

双向LSTM（BD-LSTM）是一种基于LSTM的高级算法，它使用两个独立的隐藏层双向处理信息。基本的想法是每个输入序列在正向和反向都通过RNN传递一次。这种双向架构为输出层提供了输入序列中每个节点的完整过去和未来上下文信息。与LSTM相比，BD-LSTM在需要从两个时间方向获取上下文的某些应用中表现出更高的效率，这在自然语言处理和语音识别领域尤为明显。

编码器-解码器LSTM（ED-LSTM）可以根据输入序列输出所需的序列（序列的长度可以不同）。ED-LSTM对原始LSTM进行了特定的架构更改，以更好地处理一系列称为序列到序列的问题。ED-LSTM非常适合将某种语言翻译成不同的语言。

### 3.2.2 卷积神经网络

CNN是最著名的深度学习模型之一，最初设计用于计算机视觉和图像处理任务。CNN通常包括几个层，包括卷积、池化和全连接层。全连接层类似于传统的神经网络，确保连续层节点之间的密集互连。CNN通过迭代卷积和池化来识别数据中的分层模式（特征），最终在完全连接的层中整合这些特征以输出最终任务的结果。这种结构设计对于它们在处理与图像处理相关的任务中的熟练程度至关重要。

### 3.2.3 卷积LSTM网络

卷积LSTM（Conv-LSTM）网络最初是为天气预报问题引入的。该网络扩展了原始的全连接LSTM，并将LSTM单元的矩阵乘法更改为卷积。我们使用 来表示卷积操作。Conv-LSTM单元中的关键方程表示为：

其中 和 分别指遗忘门、输入门、输出门和隐藏状态。 是随着 一起调整学习的权重矩阵， 是偏置。此外，过去的状况 可以在过程中被视为“遗忘”，而 是当前的细胞记忆。

### 3.2.4 Transformer网络

Transformer模型是编码器-解码器LSTM架构的扩展，已广泛应用于机器翻译问题。编码器将输入序列的基本数据压缩成一个固定长度的向量，随后由解码器将其转换为输出。解码器的设计提供了一种处理长序列数据的方法。

我们输入序列数据到向量表示层。给定输入序列 ， 维嵌入层通过一个密集网络生成矩阵 。

我们需要将时间编码与向量化的输入结合起来，以封装时间序列的时间结构。因此，我们使用不同频率的正弦和余弦函数来表示时间信息，我们定义：

其中 。因此，时间编码是 TE 。然后将向量表示与时间编码连接起来，并提供给编码器层。

我们模型的完整框架的简要概述在图7中描述。图7中所示的编码器由 个结构相同的层组成。每个层都配备了两个子层：多头自注意力机制和全连接的前馈网络。这两个子层都包含残差连接和归一化，以增强其功能。解码器，如图7所示，也反映了编码器的结构，但有一个显著的区别：它具有一个额外的多头自注意力层。与\[117\]中描述的原始解码器不同，这个版本省略了掩码注意力机制，因为它只处理观察到的历史数据，不包括未来信息。

注意力机制的出现标志着深度学习中的一个重要创新，它将计算工作集中在捕捉认知中的注意力机制。Vaswani等人\[117\]通过引入基于独家使用自注意力机制的Transformer架构，彻底改变了这种方法。自注意力机制的定义如下：

其中 对应于从同一输入的三个独立线性变换中得到的查询、键和值矩阵。自注意力机制的架构如图7所示。

自注意力机制改变了关注数据中重要局部内容的策略。Vaswani等人\[117\]扩展了这个想法，提出了多头注意力，即并行执行多个自注意力过程，或“头”，每个头评估查询、键和值的不同投影版本。然后将这些头的综合结果线性转换以获得最终输出。

![](assets/002.png)

### 4\. 结果

在本节中，我们提供有关数据集的全面信息，并提出研究设计与计算结果。

### 4.1 数据分析

我们调查了选定四种选定加密货币的趋势，涵盖了COVID-19的所有阶段，包括其开始、传播和衰退。图10显示了选定时期内比特币、以太坊、狗狗币和莱特币的收盘价，粉红色阴影区域表示COVID-19。我们可以观察到，每种加密货币的收盘价在红色区域内都表现出大幅波动。莱特币在COVID-19开始前经历了显著的波动，而其他三种加密货币（比特币、狗狗币和以太坊）在COVID-19前的价格波动并不显著。这表明，COVID-19之后，加密货币的价格比之前更加波动。我们观察到，以太坊的趋势在COVID-19之前和期间与比特币高度相关。从2020年到2022年，价格显著上涨，随后下降，然后在比特币和以太坊的情况下再次上涨。接下来，我们在图11中展示了月度波动图，我们观察到，以太坊和莱特币在COVID-19期间（粉红色突出显示）通常低于10%。我们还展示了同一时间比特币的月度波动低于6%；然而，狗狗币在COVID-19期间呈现不同的趋势。2021年1月和5月，狗狗币的月度波动率达到了20%以上。在其他月份，它始终保持在15%的水平。我们的分析表明，四种加密货币的波动模式表明，在高波动性时期之后的次月，波动性显著下降。COVID-19期间的月度波动性通常与疫情前（2018年至今）的月度波动性相似。尽管月度波动性没有显著变化，但在整个时期内查看每日收盘价时，它会显著波动。**![](assets/003.png)**

由于我们将开发一个多变量模型，我们还需要提供对加密货币的不同特征（低、高、开放和收盘价）与黄金价格的关联性的分析。图12显示了使用Pearson相关性在每种加密货币的多变量模型的特征之间的相关性。我们观察到，关闭价与低价、高价和开盘价高度相关。我们观察到，黄金与其他特征之间的相关性较低；然而，我们将黄金用于我们的多变量模型，因为它是加密生态系统之外但与之相关的外部数据。我们还发现，黄金价格与比特币的相关性最高，其次是以太坊和莱特币，与狗狗币的相关性最低。图13显示了包括给定加密货币的收盘、高、低和开盘价与黄金价格以及最相关的其他加密货币（使用图12）的Pearson相关性，在比特币的情况下，即图13 -面板（a）。我们将使用这个进行多变量预测策略，使用图8所示的数据处理。

![](assets/004.png)

![](assets/005.png)

  

### 4.2 结果：COVID-19之前

接下来，我们实施了在框架（图9）中概述的步骤4（实验1）的调查，我们比较了选定的深度学习模型以及使用COVID-19之前的训练数据集的单变量和多变量策略。请注意，我们的测试数据集包括COVID-19的第一阶段（表7）。

我们展示了每种预测范围（步骤）从30次独立实验运行中获得的平均RMSE和95%置信区间的结果，这些运行使用不同的初始权重和偏置进行模型训练。我们注意到，稳健性是指对预测的信心程度，它通过较低的置信区间表示。此外，可扩展性是指随着预测范围的扩大，保持恒定的性能的能力。我们的主要关注点是测试数据集上的性能（RMSE），无论是5个预测范围的平均值，还是各个预测范围。因此，在其余的讨论中，我们关注的是测试数据集。

我们首先使用比特币数据来评估传统模型（MLP和ARIMA）与深度学习模型（LSTM、ED-LSTM、BD-LSTM、CNN、Conv-LSTM、Transformer），用于单变量（图14）和多变量策略（图15）。结果表明，MLP和ARIMA的表现不如深度学习模型。MLP表现出缺乏稳健性，而ARIMA模型在与深度学习模型相比时，在测试预测准确性方面遇到困难。我们注意到，ARIMA在训练数据集上表现最好，这是由于过度训练，并且在泛化能力方面遇到困难。深度学习模型的结果与Chandra等人\[40\]的发现一致，即深度学习模型的预测准确性优于传统机器学习模型，用于多步前向时间序列预测。每个模型的预测性能显示出一个趋势，即最佳多变量策略（ED-LSTM）在预测范围变化时提供了与单变量策略（BD-LSTM）一致的准确性。在图15中，多变量策略显示Conv-LSTM提供了最低的预测准确性，而ED-LSTM和BD-LSTM模型提供了最准确的预测。在图14中，与多变量策略的结果相反，最稳健的单变量模型预测比特币是Conv-LSTM。

![](assets/006.png)

### 5\. 讨论

我们首先回顾了第一个实验的结果，该实验调查了没有COVID-19数据的模型性能。我们的结果表明，Conv-LSTM与多变量策略在四种不同的加密货币中提供了出色的预测性能。我们还注意到，在所有加密货币中，单变量模型的表现不如多变量策略。单变量策略在准确性上通常优于多变量策略（表10和11）。我们发现，具有高预测准确性（较低RMSE）的模型通常伴随着较窄的置信区间（例如，图22）。相反，较高的RMSE值通常导致模型的稳健性较低，即较高的置信区间。随着预测范围的增加，预测准确性通常会下降，这是多步前向问题的自然现象（图14b）。预测是从当前值派生的，随着预测步骤的增加，信息差距扩大。这是因为我们的任务被定义为直接预测多步，而不是迭代预测策略。我们发现，使用卷积操作的CNN相关模型在预测加密货币价格方面比其他模型提供了更好的准确性。

![](assets/007.png)

![](assets/008.png)

### 6\. 结论

在这项研究中，我们对加密货币价格预测的创新深度学习模型进行了严格的评估。我们比较了使用单变量和多变量策略的著名深度学习模型。结果表明，具有多变量策略的卷积LSTM在预测两种主要实验设置中加密货币价格方面提供了最高准确性，这些设置涉及数据、COVID-19疫情前和期间的数据。此外，我们的发现表明，包含高度相关的加密货币数据的多变量策略显著提高了预测准确性，与单变量策略相比。在COVID-19的影响方面，我们发现加密货币的收盘价波动性相当明显，这给各自的模型带来了进一步的挑战。我们的实验结果表明，使用具有高波动性的训练数据集会削弱我们预测的精度。

  

论文及代码见星球

![](assets/009.png)

  

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