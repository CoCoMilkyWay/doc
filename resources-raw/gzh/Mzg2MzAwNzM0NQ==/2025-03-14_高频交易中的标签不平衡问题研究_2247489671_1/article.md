# 高频交易中的标签不平衡问题研究

QuantML QuantML 2025-03-14 23:24 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489671&idx=1&sn=03d9d0c8e575cc729ed1cf4fc33286f9&chksm=cf08b757c3d132798e04941876950f954c49952ff82daa265d49c853b992d070fceac80e4503#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489671&idx=1&sn=03d9d0c8e575cc729ed1cf4fc33286f9&chksm=cf08b757c3d132798e04941876950f954c49952ff82daa265d49c853b992d070fceac80e4503#rd)

### 

### 

![](assets/001.png)

在金融交易中，收益预测是构建成功交易系统的基础之一。随着深度学习在多个领域的快速发展，其在处理金融数据方面也展现出显著优势。然而，深度学习的成功依赖于大量标注样本，而在高频交易领域，标注样本（尤其是盈利或亏损）存在严重的标签不平衡问题。例如，在考虑交易成本的情况下，某些事件（如市场崩盘或价格突变）的稀有性使得相关数据分布极度不平衡。这种不平衡会使得标准机器学习算法偏向于多数类，导致模型泛化能力差，增加金融损失风险。本文采用严格的端到端深度学习框架，并结合全面的标签不平衡调整方法，在中国期货市场的高频收益预测中取得了成功。

#### 一、引言

高频交易（HFT）依赖于复杂算法，这些算法能够在毫秒级时间内基于大量金融数据做出快速交易决策。这些决策通常依赖于预测模型，以识别有利的交易机会。然而，开发这些预测模型的一个重大挑战是标签不平衡问题。某些结果或事件（标签）的出现频率远低于其他事件，例如市场崩盘或价格突变等稀有事件。这些事件在历史数据中的稀缺性使得标签分布严重倾斜。这种不平衡会使得模型训练变得复杂，因为标准机器学习算法可能会偏向于频繁出现的标签，从而导致对少数类的频繁误分类。解决标签不平衡问题对于增强高频交易中预测模型的鲁棒性和可靠性至关重要，这最终将推动盈利能力和降低在快速变化的市场环境中的风险暴露。

#### 二、相关工作

稀有事件是指与常见事件相比发生频率较低的事件。在数据挖掘领域，识别稀有事件通常是一个分类问题。由于其稀有性和偶然性，稀有事件难以检测，误分类可能导致重大成本。例如，在高频交易中，错误标记收益可能导致错误的买入或卖出决策，从而导致利润损失。稀有事件的稀少性使得检测任务成为一个不平衡数据分类问题。不平衡数据是指一个或多个类别样本数量远多于其他类别的数据集。最常见的类别称为多数类，而最稀少的类别称为少数类，通常代表感兴趣的概念。由于大多数标准分类算法（如逻辑回归、支持向量机和决策树）是为平衡训练集设计的，因此它们可能产生次优的分类模型，导致对多数类样本的良好覆盖，但对少数类样本的频繁误分类。因此，在不平衡数据集上表现良好的算法不一定能在标准分类框架中表现最佳。

#### （一）预处理技术

预处理技术通常在构建学习模型之前进行，以提高输入数据的质量。两种经典技术常被用作预处理器：

1.  **重采样方法**：重采样技术通过重新平衡不平衡数据集的样本空间来减轻学习过程中类别分布倾斜的影响。根据平衡类别分布的方法，重采样可以分为三类：
    
    在比较不同重采样方法有效性的研究中，对于选择重采样方法获得了重要见解。当数据集中包含数百个少数类样本时，欠采样方法在计算时间上优于过采样方法。然而，在只有几十个少数类样本的情况下，SMOTE方法被证明是更优的选择。当训练样本量过大时，建议采用结合SMOTE和欠采样的混合方法。此外，SMOTE在检测异常值方面表现出稍高的效率。
    

-   **过采样方法**：通过生成新的少数类样本以减轻分布倾斜的不利影响。两种广泛用于创建合成少数样本的方法是随机复制少数类样本和使用“合成少数过采样技术”（SMOTE）。
    
-   **欠采样方法**：通过丢弃多数类样本解决分布倾斜问题。随机欠采样（RUS）是最简单但非常有效的方法，涉及随机删除多数类样本。
    
-   **混合方法**：结合过采样和欠采样方法的技术。
    

3.  **特征选择与提取**：特征选择的目标是从整个特征空间中选择一个包含k个特征的子集，以便分类器能够实现最佳性能，其中k是用户指定或自适应选择的参数。另一种解决维度问题的方法是特征提取，它对应于降维，涉及将数据转换到低维空间。然而，需要注意的是，特征选择技术与特征提取不同。特征选择返回原始特征的一个子集，而特征提取通过函数映射从原始特征生成新特征。特征提取方法包括主成分分析（PCA）、奇异值分解（SVD）和非负矩阵分解（NMF）。特征提取方法更常用于处理图像、文本和语音等非结构化数据。在相关论文中观察到，过滤器和包装器特征选择方法被最频繁使用。对于过滤器方法，使用了多种指标对特征进行排名，而启发式搜索是包装器方法的常见选择。此外，还发现特征选择和提取在解决实际问题（如疾病诊断、文本情感分析、欺诈检测和其他稀有事件检测问题）中得到了广泛应用。
    

#### （二）成本敏感学习

成本敏感学习考虑了不同类别误分类的不等成本。成本矩阵通常用于定义这些成本，其中Cij表示将类别i的样本错误分类为类别j的成本。在特定领域，领域专家可以确定成本矩阵，从而得到固定成本矩阵。或者，在数据流场景中，这些矩阵可能根据算法的效率在每个优化循环步骤中变化，这被称为自适应成本矩阵。例如，对于二分类问题{0, 1}，成本矩阵如图1所示。将样本错误分类为类别0的成本为10，而错误分类为类别1的成本为5。少数类的错误分类成本更高，因为我们的主要兴趣在于少数类，我们将其定义为正类（1）。通过假设对少数类样本的错误分类成本高于多数类，成本敏感学习可以在数据层面（如重采样和特征选择）和算法层面进行集成。在算法层面，主要概念是建立直接的成本敏感学习，即将误分类成本纳入学习算法中。在数据层面，成本敏感学习涉及在不改变原始学习算法的情况下，对训练数据进行“预处理”或对输出进行“后处理”。这一类别可以进一步分为两个主要类别：阈值调整和采样。阈值调整基于基本决策理论，即将实例分配到预期成本最低的类别。例如，在二分类问题中，典型的决策树根据到达叶节点的训练样本的多数类分配类别标签。成本敏感算法则将类别标签分配给使分类成本最小化的节点。采样与修改训练数据集有关，最常见的技术是根据成本决策矩阵通过欠采样/过采样或分配实例权重来调整训练数据集的原始类别分布。Guo Haixiang等人对过去十年发表的成本敏感学习方法进行了全面概述，并得出结论，与重采样方法相比，成本敏感学习在处理大数据流方面更具计算效率，但这种方法远不如重采样方法受欢迎。一个可能的解释是，重采样是不熟悉机器学习的研究人员的更常见选择。与成本敏感学习相比，重采样方法更简单，可以直接应用于单模型和集成模型，而成本敏感学习通常需要修改学习算法。

![](assets/002.png)

#### （三）集成方法

基于集成的分类器，也称为多分类器系统，通过组合多个基分类器来提高单个分类器的性能，这些基分类器各自的表现优于单个分类器。集成分类器已成为解决不平衡数据分类问题的潜在解决方案。基于集成的方法涉及将集成学习算法与上述讨论的某种技术相结合，即数据预处理集成或成本敏感学习解决方案。当数据层面的方法添加到集成学习算法中时，新的混合方法通常在训练每个分类器之前对数据进行预处理。相反，成本敏感集成通过集成学习算法引导成本最小化过程，而不是在学习过程中修改基分类器以适应成本。关于集成方法用于不平衡学习的全面分类，可以参考Galar等人提出的分类体系，如图2所示。作者将集成方法分为四个不同的家族，这些家族都嵌入了一种数据预处理技术到集成学习算法中。这些家族基于使用的集成学习算法进行分类，即提升、装袋和混合集成。根据研究，作者得出结论，基于集成的算法是值得的，因为它们的表现超过了仅使用预处理技术训练分类器的效果。

![](assets/003.png)

#### 三、预备知识

给定输入数据X = {x1, x2, ..., xn}，其中每个xi ∈ Rd是表示时间i市场状态的特征向量。特征向量可能包括各种指标，如价格变化（∆P）、交易量（V）、买卖价差（S）、订单簿不平衡（OBI）和波动率（σ）。每个实例xi都有一个对应的标签yi ∈ {1, 2, ..., K}，其中K是可能结果或类别的数量。例如，K = 2可能表示一个二分类任务，如预测价格在下一个时间间隔是上涨还是下跌。特别地，我们考虑一个三分类问题，在1分钟的时间范围内，标签yi定义如下： yi =

如果如果如果

其中：

-   Ri是实例i的1分钟正向收益。
    
-   fee是交易费用。
    

目标是学习一个分类函数f: Rd → {1, 2, ..., K}，将每个输入向量xi映射到其对应的标签yi。该函数f通常由模型θ参数化，如逻辑回归、神经网络或其他机器学习模型。需要注意的是，在1分钟这样的短时间范围内，大多数收益无法覆盖交易费用，导致大多数标签yi取值为0，即标签高度不平衡。

#### 四、方法论

##### （一）概述

如图3所示，我们的方法在训练过程中包括三个主要阶段：数据处理、训练和验证。

![](assets/004.png)

1.  **数据处理**：数据结构和处理方法的细节在第五部分A节中概述。简而言之，我们将数据特征表示为每个秒的13维向量，并利用前60秒的数据来预测当前收益，收益被分为三个类别：-1、0和+1。然而，我们发现数据集中存在显著的标签不平衡问题，大约80%的样本属于类别0，而类别+1和-1各占约10%。为了解决这一问题，我们在训练阶段实施了应对长尾分布挑战的策略。数据集随后按照8:1:1的比例分为训练集、验证集和测试集。为了避免信息泄露，我们按时间顺序而不是随机抽样来分割数据集。最后，我们为每个样本提供了一个可选的归一化操作：
    
    其中x\_i^{(j)}表示样本x中第i个位置的第j维，μ和σ分别表示均值和标准差。尽管这种归一化在多个领域已被证明可以有效减轻协变量偏移并增强模型的泛化能力，但在我们的实验中观察到显著的方差。其影响似乎因神经网络和标签不平衡处理方法而异。目前，我们尚不能明确归类其在我们的任务中的效果是有益还是有害，需要进一步研究。
    
2.  **训练**：在此阶段，我们使用训练集训练神经网络，并纳入缓解标签不平衡的策略。我们将在本节后面详细阐述网络架构和解决标签不平衡的方法。
    
3.  **验证**：为了确定模型收敛，我们采用标准的早停机制。我们在每个训练周期结束时监控模型的准确率，并在准确率在连续几个周期内没有改善时停止训练。
    
    ![](assets/005.png)
    

##### （二）骨干模型

1.  **多层感知机（MLP）**：多层感知机是一种由多个层组成的神经网络，包括输入层、隐藏层和输出层，每一层由感知节点（神经元）组成。隐藏层中的节点称为激活。图4展示了一个具有两个隐藏层的MLP，以及输入层和输出层。第d + 1层中的激活j可以表示为：
    
    其中g(z)是预先指定的非线性激活函数，X是包含p个变量的输入向量，上标表示神经元和权重（系数）所属的层。由于每个激活都是前一层d中激活A\_i^{(d)}的函数，最终它们是输入向量X的函数。通过连续的变换，网络可以创建相当复杂的X的变换，最终作为特征输入到输出层。经过变换后，我们进入输出层。设Z\_m表示第m个可能的输出，其计算方式与激活类似。如果输出Y是连续的，我们直接取(\\hat{Y} = Z\_m)。对于分类响应，我们应用激活函数（如sigmoid函数）来产生输出(\\hat{Y}\_m)。在我们的实现中，隐藏层和输出层的激活函数均使用LeakyReLU函数，定义如下：
    
    如果否则
    
    其中negative slope是一个超参数。
    
    ![](assets/006.png)
    
2.  **长短期记忆网络（LSTM）**：循环神经网络（RNN）专门用于处理和利用序列输入数据，例如金融时间序列数据。设X = {X1, X2, ..., XT}，其中输入序列中的每个向量Xt包含p个分量，隐藏层有K个单元。激活可以表示为：
    
    其中wkj是输入层的权重，uks是隐藏层之间的权重。输出结果为：
    
    其中权重βk是输出层的权重，用于定量预测或与额外的sigmoid函数一起用于二元结果。权重wkj、uks和βk在处理序列的每个元素时始终一致应用，体现了RNN的权重共享特性。传统RNN在学习需要长期依赖的任务时存在困难，因为存在梯度消失和误差流衰减的问题。LSTM通过使用特殊的单元（记忆单元）来保留其内部状态，从而解决了梯度消失问题，这些单元能够“记住”信息较长时间。从图5可以看出记忆单元的结构。三个主要组件控制记忆单元的功能：
    
    其中σ()是sigmoid函数，xt是序列t的输入向量，ht-1是序列t-1的隐藏状态。记忆单元的状态ct与三个门的关系为：
    

1.  **输入门**：决定何时将新输入引入记忆单元，记为i。
    
2.  **遗忘门**：决定何时擦除或重置单元的状态，记为f。
    
3.  **输出门**：控制何时将记忆单元的状态发送到网络的其余部分，记为o。 如果我们将权重wkj和uks分别记为W和U，那么三个门可以表示为：![](assets/007.png)
    

4.  **Mamba**：时间序列处理一直是深度学习中的一个重要课题。继RNN、GRU和LSTM之后，Transformer因其注意力机制而受到时间序列任务的广泛关注，该机制能够有效捕获序列中任意两个位置之间的关系。然而，关于其有效性的争论仍然存在。例如，一些研究人员认为Transformer由于其位置不变性而难以识别顺序。最近，基于结构化状态空间序列模型（SSMs）的Mamba受到广泛关注，并被认为是Transformer的潜在替代品。在传统SSMs中，工作流程可以表示为：
    
    其中A、B、C是模型参数，x(t)和y(t)分别表示模型的输入和输出，h(t)和h'(t)分别表示更新前后的隐藏状态，t表示时间。Mamba通过选择机制增强了这一过程，允许A、B、C依赖于输入，通过使用神经网络而不是固定矩阵。这种方法与Transformer中的注意力机制非常相似：对于不同的标记，Mamba为隐藏状态采用不同的处理模式，这结合了历史信息。与Transformer相比，Mamba在各种序列级任务（如音频处理和自然语言处理）中展现出更快的推理速度和卓越的性能。
    

##### （三）欠采样

直接在完整数据集上训练的模型表现不佳，原因在于数据分布不平衡，导致模型更关注样本数量较多的类别。因此，我们的初步方法是实施欠采样技术以实现标签之间的平衡。在我们的数据集中，类别-1、0和+1的比例约为1:8:1。因此，在每个训练周期中，我们随机丢弃类别0的(\\frac{1}{8})样本。

##### （四）成本敏感学习

1.  **固定成本矩阵**：在解决标签不平衡问题的背景下，算法层面的成本敏感学习旨在将模型的注意力集中在样本较少的类别上，这与重采样方法的直觉类似。最初，我们采用了一种简单的方法，即直接对损失进行加权，以解决标签不平衡问题。样本的损失可以表示为：
    
    其中C是类别数量，lc是类别c样本的损失函数，wc是分配的权重。对于我们的特定任务，我们将类别-1、0和1的权重分别指定为8.0、1.0和8.0。直观上，这种方法与重采样过程类似。此外，我们还根据每个类别的具体大小调整权重。我们在每个类别的均方误差（MSE）中纳入成本，基于Castro和Braga关于不平衡二元标签的研究。每个样本的损失函数可以定义为：
    
    其中N\_c是类别c之外的样本数量，p\_c是样本属于类别c的概率。成本通过C - 1进行归一化，以确保。尽管固定，但成本与标签的真实分布对齐，而不是凭直觉分配。
    
2.  **自适应成本矩阵**：Focal Loss是一种类似于损失加权的方法，但它为每个样本引入了一个动态成本矩阵。它可以表示为：
    
    其中p是模型输出的每个类别的概率向量，y是真实标签，C是类别数量，λ是控制参数，是指示函数。与传统的交叉熵损失相比，Focal Loss为模型对正确类别信心较低的样本分配更大的权重。这种自适应权重是将样本错误分类到其他类别的成本。这种方法特别适用于标签不平衡的场景，因为模型通常对样本较少的类别信心较低。此外，成本在训练过程中的动态性质确保了它们在整个过程中的相关性。
    
    此外，另一种类似的方法也被提出：
    
    其中a\_c是类别c的平均准确率。
    

#### 五、实验

##### （一）数据集描述

我们的数据涵盖了2023年5月4日至2023年5月29日的20个交易日的高频期货数据，数据频率为0.5秒。数据集包括六种品种：螺纹钢（rb2310）、白银（ag2308）、燃料油（fu2309）、镍（ni2306）、锡（sn2306）和黄金（au2308）。需要注意的是，每种品种的交易时间不同，导致样本大小各异。白银和黄金的样本量较大，而螺纹钢和燃料油的样本量较小。原始数据包含关键信息，如交易时间、每日价格（开盘价、收盘价、最高价和最低价）、最新交易价格（lastPrice）、累计交易金额、累计交易量以及买卖订单的前五个交易位置的价格和数量（bidPricei和askPricei，其中i = 1, 2, 3, 4, 5，分别表示5个位置）。基于这些数据，我们构建了13个变量来预测收益。这些变量包括：

-   midPrice，即每个数据点的最佳买价（buy one）和卖价（sell one）的平均值。
    
-   diffBidPricei和diffAskPricei，i = 1, 2, 3, 4, 5，即每个层级与平均midPrice的价格差。
    
-   diffLastPrice，即最新交易价格lastPrice与平均midPrice的价格差。
    
-   logVolume，即过去0.5秒内的交易量的对数（如果没有交易，则记录为0）。计算公式如下：
    
    如果如果
    

对于收益的计算，我们计算时间t相对于t-29.5秒（59个数据点，每个数据点间隔0.5秒）的平均midPrice的变化率。此外，我们对缺失值进行向前填充，并将每个交易日的前59个收益（前一天23:00、当天9:00、10:30和13:30）记录为缺失值。如表II所示，我们还构建了几个因子来预测收益，以测试数据的质量。图7展示了8个不同因子的收益累积和。因子效果的显著且不稳定的差异表明，模型需要进一步分析和估计数据，以实现更好的预测性能。

##### （二）实验设置

表III展示了我们提出方法的实现细节。在实验中，我们使用了Intel(R) Xeon(R) Silver 4210R CPU @ 2.40GHz和两块NVIDIA RTX 4090 GPU作为硬件设备。每种神经网络的详细配置如表IV所示。

##### （三）实验结果与分析

实验结果如图6所示。我们观察到，当训练集仅包含一个品种时，模型容易过拟合。这可能是由于数据量有限且包含大量噪声。因此，我们使用所有六个品种的数据来训练模型，并在不同品种上评估其性能。

![](assets/008.png)

在骨干模型方面，难以确定哪一种模型最佳。LSTM和Mamba在大多数情况下表现优于MLP，这可能是因为它们的结构更适合捕捉时间序列数据中的时间关系。然而，我们注意到Mamba的训练时间显著长于其他模型，因为它无法并行计算。尽管这种比较可能由于其参数数量较多而不公平，但进一步减少其规模仍具挑战性。

在解决标签不平衡问题方面，敏感损失和损失加权方法的表现优于其他方法。在我们的任务中，重采样和Focal Loss（公式11）方法有时表现不如基准方法（未采用任何解决标签不平衡问题的特定方法）。这些现象的原因需要进一步研究。

![](assets/009.png)

#### 六、讨论与未来方向

在本项目中，我们主要展示了在高频交易中使用机器学习方法解决标签不平衡问题的效率。除了本文报告的发现外，我们还希望强调在项目中遇到的一些问题和挑战，以为未来的研究提供见解和经验。

##### （一）数据噪声

在实验中，我们观察到金融数据包含显著的噪声，这使得训练过程复杂化。尽管我们尝试通过归一化（公式1）来缓解这一问题，但性能提升有限。为解决这一挑战，我们考虑两种方法。一种是改进模型结构。例如，有研究建议在回归任务中使用高斯分布而不是预测单一值，这在高噪声或动态数据场景中已被证明是有效的。另一种方法是采用特征工程方法。例如，我们识别出一些有效的特征（如图7所示），这些特征可能有助于增强模型的鲁棒性和性能。

![](assets/010.png)

##### （二）域偏移

在项目中，我们错误地使用了整个数据集的均值和标准差进行归一化，而不是使用滚动一分钟窗口。这一错误导致模型性能显著优于当前结果。这表明测试数据可能与训练数据存在显著的域差距，即数据域会随着时间逐渐变化。为解决这一问题，我们可能需要探索跨域方法。

##### （三）局限性

本研究也存在一些局限性，这些局限性可以在未来的研究中进一步探索。首先，在骨干模型选择方面，当前选择的模型可以分为MLP和解码器结构（LSTM和Mamba）。然而，编码器结构在时间序列分析中也非常重要。我们已经开发了一种用于金融数据的BERT模型，但由于时间限制，尚未充分测试其性能。其次，我们当前解决标签不平衡问题的方法主要集中在损失函数上。其他方法，如数据增强和少样本学习，也可以进一步探索。第三，如果数据和资源允许，我们可以尝试构建一个用于金融数据的大型基础模型。如最后一节所述，我们在单一品种上训练模型时发现模型性能显著较差，但这一问题在使用多个品种时得到解决。我们相信，规模定律也可以在金融领域发挥作用。

#### 七、结论

在本项目中，我们尝试学习中国期货市场1分钟正向收益的预测。我们通过适当的骨干模型和标签不平衡调整方法，成功解决了高频交易的固有挑战，并构建了一个具有稳定预测能力的模型。

  

  

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/011.png)

  

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