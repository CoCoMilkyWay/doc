# 基于新闻相互作用与影响力网络的金融市场预测模型

QuantML QuantML 2025-02-23 22:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489429&idx=1&sn=fee05f3ddc8532e1510cad831ed3ef37&chksm=cf9aa18cbccd5831b69593fcb8c037879e854559189ba470d840d5c7319ec9e37537d8950205#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489429&idx=1&sn=fee05f3ddc8532e1510cad831ed3ef37&chksm=cf9aa18cbccd5831b69593fcb8c037879e854559189ba470d840d5c7319ec9e37537d8950205#rd)

### 

###   
  

![](assets/001.png)

### 金融市场价格的波动受到多方面因素的影响，其中金融新闻的扩散过程尤为复杂，这使得评估新闻事件与市场走势之间的联系变得极具挑战性。本文提出了一种名为FININ（金融互联新闻影响力网络）的新型市场预测模型，该模型不仅捕捉了新闻与价格之间的联系，还分析了新闻项之间的相互作用。FININ有效地整合了来自市场数据和新闻文章的多模态信息。通过对涵盖标普500（S&P 500）和纳斯达克100（NASDAQ 100）指数的15年数据以及超过270万篇新闻文章的广泛实验，FININ展示了其有效性，其在日夏普比率（Sharpe ratio）上分别比先进的市场预测模型高出0.429和0.341。此外，研究结果揭示了金融新闻的若干关键洞察，包括新闻的市场定价延迟、新闻的长期记忆效应，以及金融情绪分析在完全提取新闻数据预测能力方面的局限性。

![](assets/002.png)

####   
1\. 引言  

媒体报导和新闻事件已被证明对市场回报有显著影响。然而，新闻扩散到市场价格的这一过程是复杂的。新闻对市场结果的影响因不同的市场条件而异。现有的研究通常采用简化的方法，将可用的新闻数据作为一个整体来考察其对市场的总体影响，从而忽略了单个新闻项中包含的细微信息。因此，通过考虑每个新闻项的影响来详细解析市场信息扩散过程，成为提高市场预测能力的一个潜在途径。

新闻的重要性在与其他新闻一起考虑时会发生变化。例如，突发新闻可能会削弱另一条新闻的市场影响力。然而，如果考虑到相关的突发新闻，最初新闻的影响力可能会重新显现。评估单个新闻项的影响具有挑战性，因为新闻并非孤立存在，而是与其他信息相互关联。研究表明，市场内的信息扩散是一个渐进的过程。金融新闻表现出“长期记忆效应”，即新闻对市场的影响会持续一段时间。在这一扩散过程中，单个新闻项的影响力可能会受到与其他新闻项相互作用的进一步调节。

本文旨在解决这一研究空白。金融新闻领域为不仅提高市场预测能力，而且增强我们对如何有效利用多模态数据的理解提供了一个极好的测试平台。对新闻互动进行建模需要更全面地使用和探索来自市场和新闻来源的数值和文本形式的多模态数据。它还需要考虑既定的市场理论，例如有效市场假说和信息扩散理论。

我们开发了FININ，即金融互联新闻影响力网络，以构建新闻报道之间的互动，并分析其对市场的不同影响。该模型包括两个关键组成部分：数据融合编码器和市场感知影响力量化器。数据融合编码器通过以不同的方式编码各种输入，同时保持同一领域内数据的一致性来处理多模态数据。它将每个新闻报告相关的信息编码为独立特征，为建模复杂的信息互动提供了基础。市场感知影响力量化器利用金融理论来分析新闻项之间以及新闻与价格之间的关系。它通过考虑整体市场背景来评估每个新闻项的市场影响力。

在标普500和纳斯达克100这两个主要市场上的实验表明，FININ优于现有的最先进方法。使用基于GPT的方法作为基线，我们展示了大型语言模型（LLMs）不能直接用于管理大量新闻以进行市场预测。尽管LLMs在金融情绪分析方面表现良好，但FININ在构建新闻与市场走势之间的关系方面表现出更强的能力。

此外，我们的结果提供了关于市场信息扩散过程的三个关键洞察。首先，FININ突出了新闻市场定价的延迟，表明市场在整合新闻信息方面效率低下。其次，我们证实了新闻的长期记忆效应。第三，我们指出了金融新闻情绪分析的局限性，并描述了FININ如何克服这些局限性。这些发现增强了我们对市场对新闻反应的理解。总结起来，我们的主要贡献是：

1.  我们提出了FININ，这是一个多模态模型，通过考虑新闻之间的互动以及新闻与价格之间的联系，量化了单个新闻项对市场的影响。
    
2.  FININ模型在利用新闻信息进行市场预测方面展示了其有效性，其在标普500和纳斯达克100的日风险调整回报（夏普比率）上分别比最先进的方法高出至少0.429和0.341。
    
3.  FININ的发现揭示了三个关键洞察：新闻的市场定价延迟、新闻的长期记忆效应，以及金融新闻情绪分析在从新闻数据中提取预测能力方面的局限性。
    

####   
2\. 相关工作  

基于新闻的市场预测。金融新闻已被证明对市场走势有显著影响，影响投资者情绪和决策。数据挖掘和自然语言处理（NLP）的进步使得分析新闻数据，包括推文和在线新闻，以进行市场预测成为可能。从新闻文本中提取事件和情绪方面取得了实质性进展。此外，深度学习的进步促进了有效的神经网络结构的发展，例如多模态LSTM模型、集成模型和分层注意力模型，这些模型利用新闻情绪进行股票预测。然而，现有的研究通常侧重于整体新闻的市场影响，忽略了单个新闻项的细微信息和不同影响。尽管一些研究认识到新闻与价格之间多样化的关系，并试图量化新闻的不同市场影响，但较少有研究探索多个新闻项之间的互动。此外，与新闻对市场的影响相关的更复杂方面，例如信息扩散过程，在预测过程中没有得到充分考虑。

市场信息扩散。有效市场假说（EMH）认为，股票价格即时反映所有可用信息，不存在超额回报。然而，现实世界的复杂性挑战了这一理想情况。相比之下，信息扩散假设（IDH）表明，新闻引起的信息逐渐被整合到价格中，导致市场反应延迟。研究强调了新闻对市场价格的持久影响，需要分析新闻与价格变化之间的关系。此外，新闻项对市场的影响并非孤立的，而是相互关联的，其市场影响受到彼此的影响。因此，有效捕捉信息扩散过程的复杂性仍然是一个挑战，需要进一步的研究来开发能够捕捉新闻项全面而详细的市场影响的模型。

####   
3\. 初步工作  

#####   
3.1 符号和问题表述  

在我们的方法中，我们将定义为交易日。我们的数据包括每日市场数据和新闻报告数据。这两种数据源都包含文本信息（由表示）和数值信息（由表示）。市场数据包含文本信息，包括市场描述和相关公司列表，以及数值信息，包括每日市场价格。每日的新闻数据包含多个新闻报告，其中每个代表与第个新闻项相关的信息，代表当天的新闻数量。每个新闻报告包括文本信息，其中包括新闻标题，以及数值信息，代表新闻市场情绪得分。

本文侧重于每日市场预测。目标变量代表每日市场趋势，定义为二元值，其中1表示价格上涨，0表示无变化或价格下降。我们的目标是有效地利用从第天之前的天到第天的信息，包括市场数据和新闻数据，来预测。

#####   
3.2 数据  

我们使用两个主要的股票市场数据集：标准普尔500指数（S&P 500）和纳斯达克100指数（NASDAQ 100）。此外，我们使用汤森路透新闻分析（TRNA）数据集，该数据集包含超过270万个新闻项。我们的新闻数据量显著大于之前研究中使用的数量，至少是之前的10倍。此外，与之前研究中收集的在线新闻数据不同，我们的数

####   
4\. 方法  

我们设计了FININ模型来评估新闻对价格变化的影响。FININ模型包括两个主要组成部分：数据融合编码器和市场感知影响力量化器。通过利用文本和数值数据，FININ可以捕捉这些不同信息之间的相互影响。图2展示了FININ模型的概述。

![](assets/003.png)

#####   
4.1 数据融合编码器  

现有的基于新闻的市场预测方法主要侧重于整体新闻与价格变化之间的关系，利用市场情绪分析或新闻文本处理。然而，这些方法有两个主要局限性。首先，仅凭情绪分析可能无法捕捉新闻文本中微妙的语义信息，而文本处理可能缺乏对情绪得分所传达的市场影响的洞察。其次，这些方法将所有新闻作为一个整体进行处理，可能会忽略单个新闻项与市场走势之间的不同关系。

相比之下，我们提出的FININ模型将每个新闻报告视为一个独立的单元，并使用这两种类型的数据，捕捉单个新闻报告所传达的更全面的市场相关信息。数据融合编码器通过将市场条件和新闻项的各种数据类型编码成有意义的特征来处理多模态输入。它首先分别将输入编码成特征，然后整合来自同一输入单元（市场快照或新闻项）的特征。

我们编码器的核心思想是根据每个数据源的性质设计编码函数，确保处理的一致性和差异化。对于市场描述和新闻标题的文本数据，我们使用相同的编码函数来创建不同文本来源的统一语义表示。我们利用一个预训练的语言模型（LM），表示为，以及一个编码层，分别提取市场和新闻文本特征和：

预训练的LM是冻结的，而添加的层适应我们的预测任务的表示。我们探索了各种用于金融文本的LMs，这将在§中详细讨论。

对于数值数据，由于其不同的信息内容和输入大小，市场数据和新闻情绪得分使用不同的函数和进行编码。这确保了处理的同时保持了不同新闻项数值数据编码的一致性。得到的特征分别表示为和，如方程所示：

为了将文本和数值信息整合到统一的编码中，我们使用不同的数据融合函数和分别用于市场和新闻数据。与数值数据的处理类似，这些函数确保了新闻项内的编码一致，同时区分了这两个来源。函数和的实现是将文本和数值输入特征连接起来，然后通过多层感知器（MLP）。它们将文本和数值特征作为输入，并生成市场和新闻项的整合编码和：

通过使用多模态数据作为输入，我们获得了包含更全面信息的特征。此外，与每个新闻报告相关的信息被编码成独立特征，使得对单个新闻项的分析成为可能。

#####   
4.2 市场感知影响力量化器  

与现有工作不同，FININ使用每个新闻项的独立特征来捕捉市场洞察。本节描述了市场感知影响力量化器，它利用金融理论更好地反映现实世界的市场动态。

首先，市场信息扩散理论表明，信息片段相互影响。为了捕捉这些互动，我们使用一个注意力层来完善新闻编码，使其包含来自整个每日新闻语料库的信息，使得每个新闻报告对其他新闻“感知”。

其次，有效市场假说认为，所有相关信息都反映在市场价格中。为了解释这种联系，我们引入了另一个注意力层。与第一个建立所有输入状态之间关系的层不同，这个层仅关注市场状态与新闻项之间的联系。在这一层中，市场信息单元充当查询，所有新闻项作为关键状态。我们计算查询-关键注意力得分来量化每个新闻报告相对于市场的相对重要性：

其中表示关键向量维度。

这些得分随后通过softmax函数进行归一化，以获得注意力权重。值得注意的是，我们排除了市场信息单元的自注意力得分，确保得到的权重仅对应于新闻状态并且总和为1。最后，我们使用这些权重来创建新闻特征的加权和，将它们聚合成整体每日新闻特征。

通过使用这两个注意力层，我们建立了新闻项之间以及新闻与市场信息之间的联系。这使得信息状态能够捕捉到市场的更全面视图，从而产生更具信息性的新闻表示。

#####   
4.3 市场预测  

在数据编码和市场影响力量化阶段之后，FININ的最后一步是市场预测。我们收集了过去天的编码市场和市场新闻表示，分别表示为和。这些表示被输入到预测结构中，表示为，其目的是预测市场趋势：

FININ中的预测器架构是灵活的，允许与各种广泛使用的股票预测结构集成，例如多层感知器（MLP）、卷积神经网络（CNN）和长短期记忆网络（LSTM）。我们的实验表明，FININ生成的富有信息量的特征增强了性能，而不管具体的结构如何。鉴于MLP因其简单性和效率而经常被用作后续层，我们采用MLP来构建最终的FININ模型，以保持简单性和有效性。

####   
5\. 实验设置  

#####   
5.1 语言模型  

金融语言由于其特定领域的词汇和领域知识，与一般文本不同。尽管存在许多预训练的语言模型，但它们在一般任务上的表现可能并不准确反映其对金融任务的有效性。为了调查不同的语言模型如何影响市场信息互动的建模，我们在FININ模型中尝试了四种不同类型的语言模型对文本数据进行编码。这些语言模型包括RoBERTa、FinBERT、BGE、Llama2，分别代表预训练编码器模型、特定领域的模型、表现最好的文本嵌入模型和大型语言模型。这些模型的详细介绍在§中。

#####   
5.2 实现细节  

为了构建图2中展示的架构，函数被实现为一个全连接层，而函数  , 和  使用多层感知器（MLP）结构实现。每个MLP中的层数从中选择，隐藏层大小从中选择。两个注意力机制都包含一个单层，注意力头的数量从中选择。注意力层中查询、关键和值向量的隐藏维度从中选择。在验证集上进行网格搜索以确定超参数的最佳组合。

我们使用2080Ti和A100 GPU进行了实验。在2080Ti GPU上训练一个模型需要32小时，在A100 GPU上需要7.5小时。一旦训练完成，模型可以处理超过一个月的测试案例，单个预测只需要10.16秒。鉴于行业中普遍使用A100和更高级的GPU，我们的计算要求对实际应用是可行的。

#####   
5.3 基线方法  

我们评估了FININ与七种先进的基于新闻的市场预测方法的比较，这些方法代表了利用金融新闻预测市场走势的各种技术：

新闻出现频率（NAF）根据其出现的频率来量化新闻影响力。

基于TRNA的情绪指标：许多工作从新闻情绪中创建市场情绪指标，并使用MLP和LSTM等深度学习结构来预测市场趋势。我们尝试了不同的情绪指标和基于TRNA数据集的情绪预测结构，以涵盖这些方法。我们报告了最佳结果作为这些方法的代表。

基于FinBERT的情绪指标：我们使用FinBERT获得情绪得分，并使用与前一个基线相同的方法来获得结果。

集成深度学习模型将情绪分析与两级聚合集成模型相结合，有效捕捉时间序列事件。

FPT是一种用于时间序列分析的高级预训练方法，在各种任务中取得了最先进的成果。

GPT：最近的一项研究探讨了LLMs在预测市场回报方面的潜力，使用新闻标题。他们发现GPT模型获得了最高的夏普比率。

PEN使用文本和价格数据来进行具有可解释性的市场预测。

#####   
5.4 训练和验证  

我们的实验设置考虑了过去1、3、5、10和20个交易日的输入数据时间跨度，其中5天和20天的设置相当于周和月预测。使用时间序列交叉验证来确定最佳超参数。数据集根据日期划分为10个滑动窗口。每个窗口包含连续500天的数据。我们从第一天开始收集第一个窗口，然后前进391天以获得第二个窗口。在每个窗口中，数据按照时间顺序分配到训练、验证和测试集，比例为8:1:1。报告的结果是10个子集的平均值，提供了对模型在不同时间段和市场条件下性能的稳健和可靠评估。

#####   
5.5 评估指标  

我们模型的评估基于三个指标：准确率（Acc）、损益（PnL）和夏普比率（SR）。这些指标在市场预测文献中常用。PnL衡量模型预测所产生的累计损益，提供了其性能的直接的财务结果。SR衡量风险调整后的回报，量化了每单位风险所获得的回报量。其中，SR被认为是最重要的，因为它结合了回报和风险，这是股票投资的关键因素。因此，在比较不同的方法时，我们优先比较SR。PnL作为次要指标。虽然考虑了准确率，但它被赋予的权重较小，因为高准确率并不保证高盈利能力。

####   
6\. 结果与讨论  

#####   
6.1 语言模型比较  

为了确定生成最适合市场预测的文本嵌入的语言模型，我们使用不同的语言模型作为文本编码器在标普500市场上训练了FININ。表1中的结果显示，RoBERTa在大多数设置中优于其他模型。这表明，模型设计的整体改进，如RoBERTa所展示的，可能比特定领域的适应（FinBERT）对基于新闻的市场预测更有益。这一观察与我们的直觉一致，即新闻中的金融术语通常是可理解的，使得特定领域的适应不那么关键。

虽然BGE在许多NLP任务中表现出强大的性能，但在我们的金融背景下，其结果却不那么令人印象深刻，这加强了一个观点，即没有单一的编码器在所有任务中占主导地位。Llama2代表先进的LLMs，也显示出较低的性能。由于LLMs主要针对文本生成进行优化，我们的发现反映了对其在文本编码方面的局限性的担忧。此外，Llama2的嵌入尺寸（4096）相比于典型的尺寸（大约1000）大得多，这给了一般尺寸的模型带来了挑战。

![](assets/004.png)

#####   
6.2 市场预测比较  

表2展示了FININ模型与基线方法的市场预测结果。尽管三个指标的排名并没有强烈的相关性，但SR被认为是最实用和最重要的。尽管并不总是能达到最佳的Acc或PnL，FININ在不同的设置中始终在SR方面优于所有基线。

![](assets/005.png)

此外，对于这两个数据集，FININ生成的最好的PnL和SR结果（带下划线的）都是最高的。FININ在标普500和纳斯达克100上的最高SR结果分别为1.772和1.449，分别比其它方法所达到的最佳SR高出至少0.429和0.341。

讨论新闻使用情况：比较突出了FININ在利用广泛的新闻数据进行市场预测方面的优势。虽然基线方法也包含新闻信息，但FININ提供了两个不同的优势。首先，FININ使用新闻情绪和文本标题。这与主要依赖情绪分析或文本处理的基线方法形成对比。通过整合多模态输入，FININ可以捕捉新闻项之间的互动，这是其他方法所忽略的。其次，FININ对单个新闻项的分析使得能够有效地管理大量的新闻。基线方法将所有新闻项视为同等重要，导致在面对大量数据时，有影响力的新闻被一般新闻所淹没。FININ对每个新闻项进行单独编码，使得它们能够根据其不同的影响力对预测做出不同的贡献。当处理大量新闻时，这一能力至关重要，因为缺乏适当的新闻聚合甚至会损害预测（与“总是买入”策略相比）。FININ在建模新闻互动方面的能力在§中的案例研究中进行了详细分析。总之，FININ的先进输入处理和有效的新闻管理技术使其成为在市场预测任务中使用金融新闻数据的优越工具。

![](assets/006.png)

讨论长期记忆效应和LLM：我们的发现揭示了金融新闻的长期记忆效应。随着所考虑的新闻数据的时间框架的扩展，夏普比率呈现上升趋势。由于其稳定和有效的新闻数据使用，FININ的结果中这一趋势尤为明显。基线方法也表明，随着时间框架的扩展，预测会有所改善，表明包含更广泛的交易日的数据可以增强预测。然而，基于GPT的方法是一个例外。GPT-3.5和GPT-4在标普500数据集的3天和1天预测设置中达到了最佳结果，当考虑更多天数时，性能下降。检查GPT的输出揭示了其分析复杂指数如标普500的局限性。在基于GPT的方法中，GPT被询问新闻项对公司股票的影响是正面、负面还是未知。然而，当应用于我们的数据集时，GPT在分析标普500市场的复杂性方面显得过于谨慎，有相当一部分新闻项（对于GPT-3.5为55.38%，对于GPT-4为66.78%）被分类为“未知”。因此，当我们考虑更多天的新闻时，越来越多的新闻项对预测毫无贡献。此外，新闻情绪的显著偏差损害了预测，导致结果不佳。

#####   
6.3 消融研究  

为了分离FININ中不同数据源和处理方法的影响，我们将FININ分解为五个关键组成部分：数据融合编码器的四个子部分，市场文本数据处理器（MTP）、市场数值数据处理器（MNP）、新闻文本数据处理器（NTP）和新闻数值数据处理器（NNP），以及市场感知影响力量化器（MIQ）。我们考察了三个消融变体：（1）移除新闻数据（FININ-NTP-NNP），（2）移除文本输入（FININ-MTP-NTP），（3）移除影响力量化器（FININ-MIQ）。在移除MIQ时，我们通过简单的平均而不是使用MIQ的得分来聚合新闻特征。

表3展示了在标普500市场的消融研究结果。与完整的FININ模型相比，每个消融设置的性能下降，突出了新闻输入、文本数据处理和新闻影响力量化器在增强市场预测方面的关键作用。

“FININ-NTP-NNP”列显示，仅基于历史价格数据的预测提供了有限的长期预测能力，因为随着输入时间框架的增加，性能略有改善。这表明每日价格波动的信息主要被整合到后续价格中。整合新闻信息，如在完整的FININ模型中，可以提高预测，特别是对于长期预测。这一发现突出了新闻在捕捉长期股票价格动态方面的增强的相关性。

“FININ-MTP-NTP”在大多数设置中优于“FININ-NTP-NNP”，表明新闻情绪分析捕捉到了尚未反映在价格中的额外信息。然而，与“完整FININ”的比较显示，仅依赖情绪分析会错过新闻文本中的关键信息，突出了我们文本处理组件的必要性。

“FININ-MIQ”的结果强调了新闻影响力量化器的重大贡献。直接聚合新闻特征甚至比没有新闻数据的模型（FININ-NTP-NNP）表现更差。这表明，在没有适当使用的情况下，简单地包含大量新闻数据可能是有害的。市场感知影响力量化器的得分对于提取新闻对市场预测的预测能力是必不可少的。

总之，虽然市场数据提供了基线结果，但通过FININ的处理组件整合新闻情绪和文本信息可以显著提高性能。此外，FININ的市场感知影响力量化器对于利用新闻数据至关重要，因为它有效地整合了复杂输入，并提取了它们的预测能力以增强市场预测。

#####   
6.4 对金融新闻的洞察  

我们全面的实验结果提供了三个关键洞察，揭示了金融新闻与市场走势之间的相互作用，强调了改进使用新闻数据的方法的必要性：

新闻信息的市场定价延迟：尽管标普500和纳斯达克100是高度高效的市场，我们的研究揭示了将新闻完全整合到资产价格中的明显延迟。§和§中的结果和讨论通过使用前一天的数据时性能的提高证明了这一点。这为投资者提供了一个机会，通过将新闻数据纳入其决策中来利用市场的不效率。

金融新闻的长期记忆效应：我们的结果在不同的时间范围内都表明了新闻的持续影响，这与信息扩散假设一致。虽然新闻的即时效应在1天预测中是显而易见的，但在所有测试的时间设置中都有所改善，表明延迟的影响是持久的，而不是在特定的时间框架内释放。

市场情绪分析的局限性：仅依赖情绪分析这一常用方法，可能无法捕捉市场对新闻反应的完整复杂性。我们的发现主张采用更全面的方法，考虑情绪和文本，以对新闻对资产价格的影响进行细致入微的理解。

####   
7\. 结论  

本文介绍了FININ，这是一种旨在利用金融新闻进行市场预测的新型模型。FININ有效地使用来自新闻数据的市场相关信息，优于各种先进的市场预测方法。我们的实验揭示了新闻与市场之间的关系，强调了新闻的市场定价延迟、金融新闻的长期记忆效应，以及市场情绪分析在提取新闻预测能力方面的局限性。

虽然理想情况下能够捕捉所有可用新闻报告之间的详细互动，但目前FININ主要关注的是将新闻链接在同一天内。不同天之间的信息关系由预测模型建立。这种局限性主要是由于每日的新闻量大（平均702篇，最多1953篇），这对注意力机制构成了挑战。尽管存在可能扩大注意力窗口大小的技术，但本文优先提供了一种建立新闻互动的方法。未来的工作可以探索捕捉超越单日的长程新闻依赖性的方法，这可能会提高模型的性能。

其次，我们提出的FININ模型主要关注新闻数据，因为既定的金融理论证明了新闻与市场走势之间的联系。然而，市场走势受到新闻之外的多种因素的影响。社交媒体信息和公司报告只是可能与新闻和价格数据相互作用的两个例子，但处理这些数据集超出了本文的范围。FININ有潜力扩展到整合这些相关数据源，可能导致对市场信息扩散、价格发现和预测的更全面的理解。

  

  

  

  

  

加入QuantML星球，与750+专业人士一起交流学习：

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