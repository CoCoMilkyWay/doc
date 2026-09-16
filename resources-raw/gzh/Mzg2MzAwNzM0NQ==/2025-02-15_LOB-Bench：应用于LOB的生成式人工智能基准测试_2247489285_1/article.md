# LOB-Bench：应用于LOB的生成式人工智能基准测试

QuantML QuantML 2025-02-15 22:12 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489285&idx=1&sn=8c9b4ff6c094ced568ec1e1e4953b62a&chksm=cfe86985bedfd20168aa46c5b16919868ce37bc36256dedf29e6fcaadad2eefe353d5ad19a24#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489285&idx=1&sn=8c9b4ff6c094ced568ec1e1e4953b62a&chksm=cfe86985bedfd20168aa46c5b16919868ce37bc36256dedf29e6fcaadad2eefe353d5ad19a24#rd)

### 

### 1\. 引言

金融数据因其高噪声、重尾分布和策略性交互，构成了最具挑战性和趣味性的序列建模任务之一。然而，由于缺乏定量评估范式的共识，这一领域的研究进展受到阻碍。为解决这一问题，本文提出了LOB-Bench，这是一个用Python实现的基准测试框架，旨在评估限价订单簿（LOB）数据的生成式消息流数据的质量和真实性。LOB-Bench框架通过测量生成数据和真实LOB数据之间在条件和无条件统计量上的分布差异，支持灵活的多变量统计评估。基准测试还包括常用的LOB统计量，如价差、订单簿量、订单失衡以及消息间隔时间，并结合了训练有素的判别网络的评分。最后，LOB-Bench包含了“市场影响指标”，即数据中特定事件的交叉相关性和价格响应函数。我们对生成式自回归状态空间模型、（C）GAN以及参数化LOB模型进行了基准测试，发现自回归生成式人工智能方法优于传统模型类别。

生成式人工智能（GenAI）正在彻底改变从自然语言处理到图像生成以及现实世界应用的不同领域。或许令人惊讶的是，这些方法的核心仅仅是在大型数据集上使用自回归序列模型的下一个词预测损失进行自监督预训练（Nie等人，2024；Dubey等人，2024；Liu等人，2024）。

最近，Nagy等人（2023）将这种范式应用于限价订单簿（LOB），即股票市场用来跟踪买卖订单以确定任何时候价格的机制。具体来说，与之前仅建模高级特征的模型（Cont等人，2010；Coletta等人，2022；Byrd等人，2020）不同，这种方法学习了LOBSTER数据集中消息的标记级分布（Huang & Polak，2011）。

从社会和商业角度来看，一个准确、低级别的金融系统生成模型极具价值。例如，它可以通过提供反事实来解锁更好的机制设计、稳定性分析或学习算法（例如订单执行（Frey等人，2023））。

一个关键问题是，如何确定GenAI以及其他生成式金融模型的真实性和可信度。一方面，对于高级方法和“老派”的基于代理的建模（Byrd等人，2020；Chiarella & Iori，2002；Paulin，2019；Llacay & Peffer，2018），评估通常基于定性分析，即模型是否再现了文献中的已知高级模式、“影响”或著名的“平方根定律”（Toth等人，2016；Brokmann等人，2015；Almgren等人，2005b）。然而，这些指标大多是不可量化的，可能与真实数据脱节。

![](assets/001.jpg)  
图1：LOB-Bench条件分布评估方法的示意图

![](assets/002.jpg)  
图2：LOB的示意图

另一方面，对于GenAI，预训练的标准化评估仅仅是交叉熵，即模型在保留数据上预测下一个词的能力。不幸的是，这并不能捕捉到模型在自回归采样下的表现，即逐词生成数据序列时，误差积累会导致分布偏移。在许多GenAI应用中，这不是问题，因为预训练模型仅用作特定任务微调的起点（例如RLHF），而不是以其“原始”形式使用。相比之下，我们希望在采样状态下评估预训练模型，以解锁上述用例。

为了解决这个问题，我们提出了一个通用框架，用于评估生成式LOB模型所诱导的分布与真实数据之间的相似性。在高层次上，我们无条件评估包括三个步骤。我们首先引入一组聚合函数，它们将高维时间序列LOB数据映射到一组一维子空间。其次，我们计算直方图以估计这些子空间中真实数据和生成数据的分布，最后，使用距离度量（例如L1）来比较这些估计值之间的差异。一些选定的聚合函数直接受到文献中使用的指标的启发（Vyetrenko等人，2021；Paulin，2019；Chiarella & Iori，2002；Cont，2001）。它们还直接与生成对抗网络相关，其中判别网络等同于给定生成器的最坏情况聚合函数。

对于条件分布评估，我们首先应用聚合函数，并根据条件变量将这些结果分组到“桶”中。然后，我们使用前面描述的过程对每个结果条件分布进行评分。这种方法使得例如评估在一天中的时间条件下，买卖价差的分布是否与真实数据中的相应条件分布一致成为可能。为了得出单一指标，我们计算跨条件桶的平均损失，并根据每个桶的概率进行加权。此外，我们还可以使用它通过在采样步骤上聚合并与无条件数据进行比较来评估模型漂移，这是开放循环采样中模型偏离的良好代理。有关过程示意图，请参见图1。

我们在五个不同的生成模型上测试了我们的评估框架：四个现代GenAI模型（Coletta等人，2022；Nagy等人，2023；Peng等人，2023；2024）和一个作为基线的广泛使用的经典模型（Cont等人，2010）。所有模型都在Alphabet Inc（GOOG）和英特尔公司（INTC）股票的数据上进行测试。我们没有展示在INTC上训练的Coletta模型的详细结果，因为该架构仅针对小交易量股票开发，因此无法在INTC数据上运行（Coletta等人，2022）。我们发现了“模型偏离”的证据，因为距离评分随着更长的时间步长而增加（图5）。我们还发现，LOBS5模型最能再现经济学和金融文献中众所周知的标准价格影响曲线（Eisler等人，2012）。

我们的贡献总结如下：

-   新型LOB基准测试，用于分布评估：第一个专注于模型性能全面分布量化的LOB基准测试。这解决了之前工作的局限性，这些工作依赖于对风格化事实的定性比较，使得严格的模型比较变得不可行，并阻碍了研究进展。
    
-   可解释的评分函数，用于有针对性的改进：使用直观的评分函数可以促进模型开发和改进。
    
-   判别器评分的困难挑战：判别器评分对未来的生成模型设定了很高的标准，即使大多数其他统计数据紧密一致。
    
-   常见故障模式的识别：作为时间步长的函数计算的分布误差，突出了一种普遍存在的故障模式，可以指导研究。
    
-   易用性和可访问性：开源的、易于应用的基准测试，只需LOBSTER格式的数据。
    
-   可扩展到额外的评分函数。
    
-   可转移到其他领域：适应于LOB数据之外的其他高维生成时间序列任务的理论框架。
    

### 2\. 背景

#### 2.1. 限价订单簿（LOB）

本文的后面部分依赖于读者对电子市场机制的理解，因此我们在这里简要回顾一下。公共交易所如纳斯达克和纽约证券交易所通过接受和满足多个市场参与者的买卖订单来促进资产的买卖。交易所为每个交易的资产维护一个订单簿数据结构。LOB代表了给定时间点资产的供需快照。它是一个电子记录，记录了所有未完成的买卖限价订单，按价格水平组织。Bouchaud等人（2018）提到，匹配引擎，如价格时间优先级，用于配对传入的买卖订单兴趣。订单类型进一步区分为限价订单和市场订单。限价订单（图2）指定了一个价格，在买入订单（出价）的情况下不应超过，或在卖出订单（要价）的情况下不应低于。限价订单在相应的书侧排队等待订单。市场订单表示交易者愿意立即接受最佳可用价格。

在实时交易中，向市场注入订单会引发其他市场参与者的活动，通常会将价格从代理方推开。这种活动被称为市场影响（Almgren & Chriss，1999；Almgren等人，2005a）。实时存在市场影响意味着现实的交易策略模拟应包括偏离历史数据的偏差。因此，真实的市场影响仿真是在限价订单簿建模中的一个重要考虑因素。

#### 2.2. LOB模型

LOB模拟是评估交易策略和测试反事实市场情景的重要技术。模拟结果的可信度取决于它们在多大程度上模仿了现实世界环境。传统上，通常使用历史市场数据来训练和回测交易策略，从而假设市场影响可以忽略不计。这是基于小代理订单和连续交易之间有足够时间的假设（Spooner等人，2018）。然而，“无市场影响”假设对于较大订单规模或高频率订单是不成立的。基于代理的方法自然允许研究这些现象，这些现象是多个参与者交互的结果，否则很难建模。然而，它们在校准方面是出了名的困难（Vyetrenko等人，2021；Paulin，2019）。为了避免校准，使用条件生成对抗网络从历史LOB数据中学习模拟器，这些模拟器既真实又响应（Coletta等人，2023）。最近，一种端到端的自回归生成模型，以生成式人工智能的精神生成标记化的LOB消息，被证明能够实现高度的真实性（Nagy等人，2023）。

#### 2.3. 自回归LOB模型

在机器学习中，自回归建模是像GPT这样的语言模型的关键组成部分。通过学习给定前一个词的概率分布，自回归语言模型可以生成连贯的文本（Radford等人，2019）。交叉熵是深度学习中常用的损失函数，用于训练分类模型。它衡量了预测的类概率与真实类标签之间的不相似性（Goodfellow等人，2016）。交叉熵损失是真实类标签在预测分布下的负对数似然。最小化交叉熵等同于最大化数据的似然（Murphy，2012）。对于二分类，交叉熵损失为：

其中 是真实标签（0或1）， 是预测为正类的概率。交叉熵损失对自信的错误分类施加了严重的惩罚，并激励模型输出与类的经验分布相匹配的校准概率。尽管它与KL散度不同，但交叉熵可以表示为真实分布的熵和真实与预测分布之间的KL散度之和（Cover & Thomas，1999）。

### 3\. 相关文献

LOB在现代金融市场中起着至关重要的作用。Ntakaris等人（2018）发布了第一个公开可用的用于基准测试中点价格预测模型的FI-2010数据集。这个数据集包含在纳斯达克北欧市场交易的五只股票的订单，为期十个连续交易日，并且已经过预处理。尽管对于初步测试和LOB算法的比较有用，但FI-2010不允许对鲁棒性和泛化能力进行全面的评估（Zhang等人，2019）。Huang等人（2021）提供了一个类似的基准，用于预测中国股票市场的平均价格和成交量。与其他目前可用的基准一样，这项工作在用完全分布的视角评估GenAI模型方面也存在不足。Cao等人（2022）提出了一个基准数据集，它对LOB-Bench起到了补充作用。通过DSLOB，他们提供了一个由多代理模拟生成的合成LOB数据集，其中包含冲击，生成标记的分布内和分布外样本。相比之下，LOB-Bench不需要在特定数据集上进行训练，而是专注于通用模型评估和比较。

为了评估生成模型在LOB环境中的性能，一些研究提出了相关指标。Coletta等人（2023）研究了条件生成模型的解释性、挑战和鲁棒性。他们根据某些属性和统计数据对LOB状态进行分组，然后对这些组进行条件生成。Vyetrenko等人（2021）提出了几种统计量来评估LOB模拟器的真实性，例如订单到达率、订单距离分布和价格波动性，而Paulin（2019）进一步考虑了滞后的自相关性和交易流动性。

总之，尽管一些研究已经解决了LOB生成模型的评估，但统一的基准测试框架仍然缺乏。现有的研究通常使用定性方法来比较生成数据的统计规律与真实数据，缺乏定量评估指标。因此，建立一个全面的基准测试框架来评估LOB生成模型对于推动该领域的发展至关重要。

### 4\. 评估框架

正如LLM的成功所表明的，生成模型已经可以通过自回归训练或“下一个词预测”单独实现令人印象深刻的性能。然而，并非所有模型类别都是自回归的或允许显式计算条件“下一个词的概率”，这禁止了基于交叉熵的评估或计算模型困惑度（Chen等人，1998）。然而，仍然需要评估这样的模型类别，我们只能对数据进行采样。另一个原因，单词交叉熵损失之所以不足，是因为所谓的“自回归陷阱”（Zhang等人，2024）。即使在下一个词预测任务中小的错误也会在长序列中积累，导致偏离训练分布。然后，分布外的预测变得越来越糟，直到生成分布完全偏离或崩溃。这强调了需要评估整个序列的统计数据，而不是仅仅关注交叉熵。因此，基准测试框架还应通过评估条件分布对预测范围的依赖性来衡量这种错误的积累速度。

在任何领域评估生成模型本质上是一个比较分布的问题。我们的基准测试正是执行这一任务。它通过使用评分函数 ，，将订单簿状态序列 和消息事件 的高维分布简化为标量。然后可以使用各种范数或散度 来比较真实数据和模型生成数据之间的一维评分分布。通过估计无条件真实数据分布 和模型下的数据分布 之间的差异，即 ，可以按其匹配数据特征的能力对不同的生成模型进行排名。

为了评估“自回归陷阱”的大小，基准测试评估了条件分布的误差散度，条件是预测步长 的区间，对于区间限制 ：。这允许量化推理期间的分布偏移。

我们的框架使用L1范数和Wasserstein1距离作为损失指标。为了估计L1范数，我们首先对数据进行了分箱。作为一个健壮的分箱算法，我们使用Freedman-Diaconis规则（Freedman & Diaconis，1981），它计算箱宽为 2 I3√QnR，其中 n 是真实和生成数据的综合样本大小。然后可以估计 缩放的 L1 范数，也称为总变异距离，如下所示：

虽然 L1 度量具有在区间 内有界的优点，但 Wasserstein-1 距离，或称为推土机距离，如 Rubner 等人（2000）提出的，具有对评分之间距离敏感的优点。为了使不同评分函数的损失可以比较，我们在计算 Wasserstein-1 距离之前对数据进行均值-方差归一化。

对于相等的样本大小，我们可以如下计算 Wasserstein-1 距离。设 是从 中抽取的真实数据样本计算的得分的第 i 个顺序统计量， 是使用从 中抽取的生成数据计算的得分的第 i 个顺序统计量。然后我们有：

为了评估生成模型适应不同环境的能力，我们还估计了条件评分分布之间的差异

在这种情况下， 被分箱成 10 个数据十分位数 的池化真实和生成数据。然后根据两个分布的估计密度的均值对这些 10 个条件分布的距离估计进行加权。

设 和 ，可以评估一个条件指标为

这种方法解决了特定类型的分布偏移： 的得分变化跨越另一个得分 的分布。例如，如果条件函数 代表数据序列中消息的平均时间，这个框架允许我们分析分布偏移如何影响任何感兴趣的得分 ，并评估生成模型复制这种动态行为的能力。

### 4.1. 影响响应函数

历史 LOB 数据的一个主要困难是由于静态的、不响应额外注入的订单，因此无法评估反事实情景。因此，生成模型是生成对反事实情景的响应的一个独特机会。

因此，至关重要的是，这些模型应根据其提供对不同事件的真实响应的能力进行评估。作为基础方法，Eisler 等人（2012）的工作被用作比较不同事件类型影响的基础。这种方法仅关注改变最佳买卖订单价格或数量的事件的影响（也称为触摸订单），这是其局限性之一。

所有影响最佳价格的事件都被分类到六种订单类型之一 ：市场订单（MO）、限价订单（LO）和取消（CA），它们进一步细分为影响中点价格的，用下标 1 表示，不影响的，用下标 0 表示：。

使用 LOBSTER 数据中的惯例，我们定义方向 为 1 表示事件在出价侧， 表示在要价侧。事件根据它们将引起的对中点价格的预期影响方向被赋予 值。在这种情况下，执行被视为市场订单。

这允许计算响应函数（(6)）。这是根据给定事件后调整符号的中点价格 的变化的时间平均值 经验计算出来的。事件滞后时间选择在 1 到 200 个刻度之间均匀分布在对数刻度上。价格通过刻度大小进行标准化，以实现不同股票之间的比较。

Eisler 等人（2012）识别了 14 只随机股票在 53 个交易日的平均响应函数。虽然这样的分析为我们提供了一个良好的基线来比较我们的结果，但对于模型评估，我们直接比较了模型生成和真实序列（基于种子的起始点或一天中的时间匹配）的函数。一旦计算出响应函数，我们创建一个比较度量以获得不相似性评分：

这是通过取均值 来跨所有事件类型聚合。

### 4.2. 对抗性测量

对抗性测量的概念是开发一个强大的判别器，能够有效地区分真实和生成轨迹。这个判别器是一个二元分类器，生成一个轨迹为真实的概率估计。我们仅使用订单簿状态作为输入。判别器在两个数据批次上训练，每个维度的尺寸为 。在这种表示中， 表示批次内的序列样本数量， 表示订单簿序列的长度， 是订单簿状态表示的维度。鉴于大多数订单簿状态之间变化的稀疏性，我们设计了一种编码方案来优化判别器的性能。

判别器旨在找到“最坏情况”的函数 ，它通过选择 来最大化真实和生成分布之间的散度，即 。这个 ，可以解释为对订单簿状态序列 到标量 的维度缩减操作 ，可以被认为是敌对评分函数。判别器试图识别真实和生成样本之间最明显的缺陷和差异，并将这些提炼到一个维度上。

订单簿状态包括买卖两侧前 个价格水平的价和量。在本文中，，导致维度 。订单簿状态的变化通常由影响单一价格-数量对的事件触发。为了实现判别器网络的更简洁但信息丰富的表示，我们选择基于这些变化来表示订单簿。因此，书状态 和消息事件 通过 函数 映射到三维向量。这些变化包括中点价格的每一次变化、发生变化的相对价格水平以及相应的数量变化。我们的判别器利用一维卷积神经网络（Conv1D）（LeCun 等人，1995；Kiranyaz 等人，2019）作为特征提取器，后接一个注意力机制（Vaswani 等人，2017）以捕捉跨时间步的长期依赖性。实证结果表明，该模型在 2023 年 GOOG 数据上训练和测试，ROC 评分为 0.83，表明生成的数 据可以被相当准确地辨别。然而，基线模型的性能对于 GOOG 和 INTC 来说很差，判别器 ROC 评分约为 1，表明未来模型改进的空间很大。

### 5\. LOB-Bench 包

基于第 4 节概述的评估框架，我们开发了一个 Python 基准测试包，允许对生成的 LOB 数据进行方便、全面的评估。基准测试具有高度可定制性，因为评分函数 可以轻松添加、删除或修改，并使用提供的默认评分函数提供标准化的模型比较。基准测试通过计算所有条件和无条件评分函数以及自举置信区间来报告聚合模型评分。

基准测试通过对另一个统计量的值进行条件化来执行生成数据的无条件 和条件评估，以评估误差散度或“滚雪球误差”的影响。此外，还根据预测范围对分布进行评估。分布准确性是通过计算真实和生成分布之间的 L1 范数和 Wasserstein-1 距离来衡量的。复杂条件分布的特定支持示例是响应函数，它描述了条件于其他事件在一定滞后时间之前发生的事件的分布。由于这些分布通常具有高方差，并且为了与现有文献保持一致，我们改为衡量一系列滞后时间的平均绝对差异，以评估市场影响曲线。

我们从金融文献中包含多个条件评分函数，例如，价差条件于买卖量，价差条件于一天中的时间，以及价差条件于 回报的波动性。

基准测试还评估了模型响应函数（6）

![](assets/003.jpg)  
图 3：模型比较蜘蛛图：LOBS5 模型在几乎所有评分上都击败了基线和 coletta 模型。注意：径向轴通过绘制负损失（越大越好）进行反转。

在聚合上。计算每个滞后时间的各个 L1 距离 并取平均以产生累积影响评分。

### 6\. 结果

作为我们基准测试的第一个测试案例，我们改编了使用 S5 层（Gu 等人，2021）的自回归状态空间模型（Nagy 等人，2023）（LOBS5）。特别是，我们将模型大小扩大到 3500 万个参数，并将训练时间延长到整个 2022 年。

![](assets/004.png)

我们还评估了由 Cont 等人（2010）（基线）、Coletta 等人（2022）（Coletta）以及基于 Peng 等人（2023；2024）（RWKV 4 和 6）的模型生成的数据。基线模型采用参数化到达过程，通过直接使用估计的经验到达率而不是拟合幂律，进行了调整，以概括小和大交易量限价订单簿（LOB）动态。此外，我们推断出在 LOBSTER 中存在的数据特征，例如单个消息 ID，这些 ID 并没有由 Cont 等人（2010）生成。这种推断对于捕获订单取消尤为重要，因为我们统一地从指定价格水平可用的订单中采样目标限价订单。对于 Coletta 模型，我们实现了一个 LOBSTER 数据接口，以促进数据格式的转换。对于 RWKV 模型，我们应用自回归下一个词预测，但在一个更大的模型（1.7 亿个参数）上，不进行任何数据预处理，并使用现成的字节对标记器，如 LLM 中使用的。这些模型仅在消息数据上训练，没有任何订单簿，不需要像 Nagy 等人（2023）中那样传播计算出的订单簿状态。这里呈现的 S5、RWKV 和基线结果是在 2023 年 1 月测试数据的子样本上计算的，用于 Alphabet（GOOG）和英特尔（INTC）股票。Coletta 模型在 2019 年 1 月的三天数据上训练，并在随后三天进行测试，按照 Coletta 等人（2022）中的程序，这是由于训练和推理的计算成本高。比较所有模型，我们注意到 LOBS5 模型在基准任务上提供了最先进的性能。

![](assets/005.png)

### 7\. 结论

我们介绍了 LOB-Bench，这是一个用于订单簿建模的生成式人工智能模型的评估框架。至关重要的是，我们的框架包含分析工具，使得机器学习和金融领域的用户能够轻松地对他们的消息级订单流模型进行基准测试。

我们相信 LOB-Bench 将极大地促进核心机器学习研究在序列建模方面的创新应用于这一具有挑战性和相关性的现实问题，同时也使金融从业者更容易使用最佳实践工具。

生成式人工智能模型用于微观结构数据的一个有趣方面是能够对反事实进行建模，这与金融建模中的价格影响概念密切相关。使用传统方法考虑其他市场参与者对自己行为的反应是非常具有挑战性的，但我们的基准测试套件为生成式 LOB 模型提供了广泛的测试，以评估生成的数 据是否在更大规模上再现了预期的响应函数。将来，我们计划衡量生成模型在多大程度上符合文献中的市场影响法则，例如“平方根法则”（SRL）（Toth 等人，2016）。我们希望这将开启许多新的研究，包括训练强化学习算法和多代理模型，用于具有模拟不同市场参与者真实反应能力的交易执行。

  

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/006.png)

  

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
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)[券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
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
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)