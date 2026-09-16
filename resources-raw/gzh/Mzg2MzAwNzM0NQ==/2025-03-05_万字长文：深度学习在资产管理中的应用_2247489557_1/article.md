# 万字长文：深度学习在资产管理中的应用

QuantML QuantML 2025-03-05 19:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489557&idx=1&sn=02a9979585741f71a40c69b3bb4e64ea&chksm=cf1ff2ccd1919b3c54f0506dcd93c682ed3694d7e7a0ebed04c4bc0f2fb6ab9649bb648b38ca#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489557&idx=1&sn=02a9979585741f71a40c69b3bb4e64ea&chksm=cf1ff2ccd1919b3c54f0506dcd93c682ed3694d7e7a0ebed04c4bc0f2fb6ab9649bb648b38ca#rd)

### 

####   

![](assets/001.png)

#### 1\. 引言

金融作为经济学中一个高度多样化的研究领域，涵盖了资产和投资组合管理、风险评估、欺诈活动识别以及金融监管等多个方面。近年来，深度学习（DL）等先进学习方法在投资组合管理和风险评估等领域的应用日益重要。本文系统地回顾了深度学习模型在金融资产管理中的应用，重点关注其在金融市场各种决策中的贡献。

深度学习与金融的交叉领域取得了显著进展，特别是在提高金融预测精度、识别市场数据中的复杂模式以及改进风险管理策略方面。本文通过筛选2018年至2023年间发表的相关文献，识别出15篇探讨这一交叉领域的文章。尽管关于深度学习在金融市场的一般应用综述相对常见，但这些综述主要关注标准深度学习技术，如LSTM和CNN，而对新兴技术（如Transformer模型）及其在多资产组合中的应用探索有限。此外，它们很少涉及可解释的人工智能（XAI）方法，这对于监管合规和从业者采纳至关重要。本文旨在通过纳入这些最新趋势，提供一个更具前瞻性的深度学习应用视角。

![](assets/002.png)

#### 2\. 理论背景

##### 2.1 主题

本文采用与Mirete-Ferrer等人（2022）类似的方法，将投资组合构建任务分为价值/因子投资、算法交易、投资组合管理和价格预测。

###### 2.1.1 价值/因子投资

资产定价是金融学的核心领域，涉及确定金融资产的公平价值。其目标是理解市场如何定价资产，考虑风险、回报以及影响金融资产业绩的各种因素。许多资产管理者使用这些模型来捕捉超额回报，并围绕这些因素构建投资组合。Ross（2013）的套利定价理论（APT）显著推动了此领域的发展。与资本资产定价模型（CAPM）不同，APT考虑了可能影响资产回报的多个因素。Fama和French（1993, 2015, 2018）、Carhart（1997）以及Hou等人（2021）提出了基于非市场风险的多因子模型。

深度学习因子模型优于传统线性模型，表明股票市场超额回报与因子之间的关系是非线性的，而不是线性的（Nakagawa等人，2018）。此外，它们优于非传统非线性模型，因为无需事先指定因子。然而，由于其黑箱性质，深度学习模型需要更多的可解释性才能在资产定价中更有用。这些基线模型应该是基于传统模型构建的投资组合，即Fama和French三因子和五因子模型，因为这些模型在金融文献和从业者中最受认可。

###### 2.1.2 算法交易

算法交易指的是使用计算机算法来自动化买卖金融证券（Ozbayoglu等人，2020）。这些算法旨在根据预定义的准则，包括市场条件和历史数据，决定交易的时机、价格和数量。算法交易的目标是通过以人类交易者无法达到的速度和频率执行交易来最大化效率和盈利能力。这一技术进步对投资组合管理产生了深远影响，使投资组合能够进行动态调整和实时优化。因此，市场上量化分析师的数量显著增加。量化分析师专门从事深度学习策略，这些策略与依赖传统方法和历史趋势的传统方法不同，而是利用尖端技术来适应快速变化的市场条件。

###### 2.1.3 投资组合管理

投资组合选择和投资组合优化在金融学中经常互换使用，但它们指的是不同的过程，具有不同的重点。投资组合选择是选择投资组合中资产组合的更广泛过程。这涉及识别符合投资者风险承受能力、目标和投资期限的潜在投资。相比之下，投资组合优化是指确定选定投资组合内理想资产配置的数量过程，旨在最大化给定风险水平的回报或最小化指定预期回报的风险。尽管存在差异，这两个过程都是投资组合管理的组成部分。投资组合管理包括创建和维护投资组合以实现特定的财务目标，选择和优化是这种整体方法的关键组成部分。

多元化是投资组合管理的关键要素，正如Markowitz（1952）所强调的。与多元化密切相关的是资产相关性的概念。根据Goetzmann和Kumar（2008）的研究，尽管投资者认识到多元化的好处，但他们通常在构建投资组合时没有充分考虑资产相关性。这种疏忽是许多高级投资组合优化技术在样本内表现良好但在样本外表现不佳的主要原因。

关于主动与被动投资组合管理策略的更广泛讨论与此问题密切相关。主动投资组合管理涉及基于基本面和技术分析选择金融资产。这种讨论与深度学习（DL）模型有关，这些模型有助于投资组合选择和优化决策。

###### 2.1.4 价格预测

价格预测是指预测金融资产未来价格的过程。这一实践在金融学中是基础性的，因为它有助于投资者、交易员和金融机构就购买、出售或持有金融资产做出明智的决定。价格预测与Fama的有效市场假说（EMH）有着内在的联系。

根据Fama（1970）的观点，金融市场是有效的，因为资产价格在任何给定时间都完全反映了所有可用信息。EMH分为三种形式：弱式、半强式和强式。弱式认为当前价格反映了所有过去的交易信息，这意味着技术分析无法持续预测未来的价格走势。半强式指出价格迅速调整以适应新的公共信息，使得基本面分析对于获得非微不足道的优势变得无效或代价高昂。强式认为价格反映了所有公共和私人信息，这意味着即使是内幕信息也无法用来获得持续更高的回报。

在EMH框架下，价格预测的有效性受到质疑。如果市场如Fama所主张的那样真正有效，那么价格走势在很大程度上是不可预测的，并且遵循随机游走，这意味着未来的价格变化与过去的价格走势无关（Fama，1965）。这表明，无论是技术分析还是基本面分析都无法可靠地预测未来的价格以获得异常回报，从而否定了主动投资组合管理。因此，关于这一主题的研究的主要基线应该是一个随机游走方法，即假设今天的资产价格是给定资产的第二天最佳预测值。如第4节所述，这是作者使用DL模型解决的主要问题，对Fama（1970）的假设提出了挑战。

##### 2.2 DL模型

在深度学习领域，模型的可能性是巨大的。为了理解它们在金融资产管理中的演变，我们识别出最常见的模型并解释它们的主要优势。

在基本形式中，人工神经网络（ANN）是受生物神经网络启发的模型，ANN中的神经元由一个聚合函数和一个激活函数组成。聚合函数计算输入的总和，激活函数生成输出，可以捕捉金融数据之间的非线性关系。在本综述中，我们将遵循Jiang（2021）的方法。因此，我们将以下模型归类为ANN，因为它们具有相似的结构：反向传播神经网络、多层感知器、极限学习机和无需调整隐藏节点参数的类似模型。

尽管结构相似，但自动编码器（AE）（Hinton和Salakhutdinov，2006）被认为是与ANN分开的。AE是一种用于深度学习的神经网络，它学习输入数据的有效且紧凑的表示（编码），通常用于降维或特征提取。它们通过将输入压缩成低维代码，然后从这种表示中重建输出。自动编码器的架构设计为层的夹心结构：第一部分（编码器）降低输入维度，并以压缩格式捕获关键特征，第二部分（解码器）尝试从这种压缩代码中重建原始输入。由于其特征提取能力，自动编码器在各种应用中非常有用，主要是资产定价。

另一种模型类型是卷积神经网络（CNN）（LeCun等人，1998）。CNN是一种专门用于处理具有网格状拓扑的数据（如图像）的神经网络。CNN通过应用卷积滤波器，通过在输入上滑动权重窗口处理数据，捕捉数据中的空间层次结构，捕捉边缘、纹理和形状等特征。这个过程允许CNN在通过层时构建复杂的图像表示，其中早期层捕捉基本特征，而更深层的解释更复杂的结构。与需要将输入展平为向量的传统神经网络不同，CNN保持了数据的空间结构，使其在图像和视频识别、图像分类和医学图像分析等任务中非常高效。尽管CNN在图像和视频分析中取得了成功，但它在金融资产管理中被广泛用于去噪市场信息。

生成对抗网络（GAN）（Goodfellow等人，2014）是另一种能够去噪市场信息的模型。通过用历史市场数据训练GAN，生成器可以生成新的合成资产价格走势，模仿真实的市场动态。同时，判别器努力区分这些合成数据点和实际历史数据。这种迭代过程增强了模型反映真实市场行为的能力，为投资组合管理者提供了用于风险管理和策略优化的强大工具。此外，GAN生成的数据可以帮助填补历史数据中未充分代表的事件（如极端市场低迷）的空白，从而使管理者能够更好地为潜在的危机做准备。因此，GAN在通过高级、现实的金融时间序列模拟改进投资组合管理决策过程方面具有显著潜力。

另一种模型类型是图神经网络（GNN）（Scarselli等人，2008）。它们能够管理复杂的数据结构，如金融资产管理中的数据结构，特别是在投资组合管理中，资产之间的关系对投资决策有重大影响。在投资组合管理中，GNN可以通过将资产视为节点，其相关性视为边，将投资组合中各种资产的相互连接性分析为一个图。这种方法允许GNN捕捉单个资产的特征及其动态互动，提供对风险评估和优化至关重要的全面视角。使用GNN，投资组合管理者可以通过从投资组合的深度和复杂连接中获得的见解来改进他们的决策过程，这可能带来更稳健和优化的资产配置。这种能力在管理投资组合时尤其有价值，其中资产的时间动态和相关性通常在时间序列数据中捕捉到，在预测未来资产行为和相应调整投资组合中起着关键作用。

由于金融数据通常是时间序列的，递归神经网络（RNN）（Elman，1990）是标准方法，因为它们擅长处理顺序数据。RNN与其他神经网络的不同之处在于它们的内部记忆，它捕捉了迄今为止处理的信息，有效地赋予了它们一种短期记忆。这是通过网络架构内的循环实现的，这些循环允许信息在时间步长之间持续。这种基础方法使RNN能够学习序列及其长期依赖性，尽管存在诸如梯度消失问题等限制，这导致了长短期记忆（LSTM）（Hochreiter，1997）的开发。LSTM保持更复杂的内部状态以记住更长时间的信息，使用称为门的结构，特别是输入、遗忘和输出门。这些门控制信息的流动：它们决定在记忆中保留什么，丢弃什么，以及输出什么。这种门控机制使LSTM能够捕捉数据中的长期依赖性，使其在时间序列预测应用中非常有效，在这些应用中，理解时间上的上下文至关重要。然而，RNN和LSTM的一个关键限制是它们在处理比其内部状态长得多的序列时遇到困难，因为内部状态只能总结有限数量的时间步长的信息。

此外，RNN和LSTM是顺序的，这意味着它们必须一次处理序列中的元素（Lipton等人，2015），这导致处理长而复杂的数据序列时计算成本高。门控循环单元（GRU）（Cho，2014）的创建是为了克服这个问题。GRU通过更精简的设计实现了这一点，该设计结合了两个门：更新门和重置门。更新门帮助模型决定需要传递多少过去的信息（从前一个时间步长）到未来，有效地融合了新旧信息。重置门决定了要忘记多少过去的信息，这有助于模型更好地适应数据序列中的变化。GRU和LSTM可以通过引入双向学习来增强，使模型能够通过向前和向后处理序列数据来捕捉序列数据中的过去和未来上下文。

最近，Transformers代表了在深度学习领域，特别是在涉及处理顺序数据的任务中的重大进步。由Vaswani等人（2017）引入的Transformer模型与传统基于循环的方法背道而驰，而是完全基于注意力机制的结构。Transformers的核心思想是注意力机制，它允许模型对输入数据的不同部分的重要性进行不同的权衡。这在理解元素出现的上下文方面特别有用，提高了模型区分数据中关系和依赖性的能力，无论它们与输入序列的距离如何。这增强了处理长程依赖性的能力，使它们非常适合对历史价格或经济指标的整个序列进行建模，从而捕捉影响资产价格的复杂模式。这种能力可以通过提供对市场动态的细致理解，显著提高预测精度、风险评估和识别投资机会。注意力机制是生成式人工智能的基础，主要是大型语言模型，如BERT（Devlin等人，2018）。

深度强化学习（DRL）是算法交易和投资组合管理中的主要深度学习模型。这些模型结合了其他深度学习模型（例如LSTM预测）与强化学习原则，以解决涉及顺序决策的复杂决策任务。DRL包括一个通过与环境互动并根据其采取的行动接收奖励或惩罚的代理。将深度学习融入这一框架使代理能够解释高维输入，并从复杂、非结构化的数据环境中学习最佳策略。

在众多模型中，深度Q网络（DQN）（Mnih等人，2015）在DRL领域脱颖而出。它们通过将Q学习扩展到管理金融市场中典型的复杂、高维状态空间，提供了巨大的好处。DQN的核心创新在于它们使用深度卷积神经网络来近似Q函数。该函数预测基于当前市场条件的特定行动奖励，指导交易和投资策略中的决策。DQN处理原始市场数据以输出行动值，帮助选择最佳行动以最大化潜在回报。这种能力使DQN能够自动化交易策略，优化投资组合再平衡，并通过适应市场的实时变化来有效管理风险。通过根据新数据不断更新其策略，DQN帮助投资组合管理者通过在不同的市场条件下导航，并在目标函数中实施风险回报比率，保持风险和回报之间的平衡，从而提高性能的一致性。

### 3\. 方法论

为了确保本次系统性综述的质量和可复制性，本文采用了**PRISMA（系统评价和荟萃分析的首选报告项目）**标准进行文献筛选和分析。由于本研究仅基于Scopus数据库进行文献检索，因此对PRISMA标准进行了少量调整，具体步骤如下：

#### 3.1 文献识别

首先，本文明确了当前的研究趋势、研究空白以及机器学习领域中最突出的关键词。**Scopus数据库**被选为文献检索的主要来源，因为它提供了全面且相关度高的学术文章集合。为了确保文献的质量和同行评审的可靠性，本文将检索范围限定为Scopus数据库中收录的英文文章。

**检索策略**基于标题和摘要中的关键词进行筛选，具体步骤如下：

-   **关键词组合**：使用“深度学习”或“神经网络”与“资产管理”、“投资组合管理”、“投资组合优化”、“资产定价”、“价格预测”或“算法交易”进行组合检索。
    
-   **时间范围**：仅限于2018年至2023年间发表的实证性文章。
    
-   **语言**：仅限英文。
    
-   **文献类型**：排除没有有效DOI或未在同行评审期刊上发表的文章。
    

通过上述策略，初始检索共获得**934篇**文献。这些文献随后经过两阶段的筛选过程，以确保其与金融资产管理主题的相关性和质量。

#### 3.2 文献筛选

在第二阶段，本文对初始检索获得的934篇文献进行了仔细筛选，以确定其与金融资产管理主题的相关性。这一过程对于保持综述的焦点和质量至关重要。每篇文章都经过摘要和全文的筛查，以评估其是否符合预定的纳入标准。在此阶段，共有**321篇**文章被排除，原因如下：

-   **非金融资产管理主题**：许多文章涉及物理资产管理，如基础设施、道路或建筑物，而非金融资产。这些研究虽然在其领域内具有价值，但超出了本次综述的范围，本次综述仅关注金融资产管理。
    
-   **非深度学习主题**：一些文章仅在表面上提及深度学习，而没有实际应用这些模型进行实践或方法论研究。这些论文被认为与理解或推进深度学习技术在金融资产管理中的应用无关。
    
-   **其他原因**：包括缺乏DOI、非实证性研究、综述文章、撤回文章以及非英文文章等。
    

经过严格的筛选标准，最终保留了**612篇**文章进行进一步分析。这些选定的文章构成了本次综述的基础，提供了深度学习在金融资产管理中应用的全面概述，并确保了综述在其定义范围内提供有意义且可操作的见解。

为了提供对金融资产管理中使用的模型的全面概述，本文没有按期刊进行过滤。尽管分析中会包含质量较低的论文，但这有助于从研究人员那里总结出最佳实践和改进领域。

#### 3.3 文献纳入

在最终阶段，本文创建了一个数据库，用于进行定性和定量分析。本研究共包含612篇文章，所有文章都经过分析以创建数据库。选定的文章内容根据其金融领域进行了分类，并进行了系统排列（见表8）。每篇文章的标题、作者姓名和数量、发表年份、出版期刊名称、作者指定的关键词、采用的深度学习模型、性能指标、验证方法以及每个金融应用的其他相关信息都进行了详细记录。

### 4\. 调查结果

本节将批判性地分析研究结果。我们首先概述所有文章的结果，然后深入分析每个主题。由于篇幅限制，本文仅提供一般性统计数字，以表明深度学习在金融研究中的当前状态。请注意，除了主要模型外，我们在分析中考虑了文章中使用的所有深度学习模型。混合模型，如CNN+LSTM，既被视为CNN也视为LSTM，因为它们可以用于不同的目的。

#### 4.1 价值/因子投资

自2018年以来，该主题的出版物数量最少。表9提供了关于价值/因子投资的一些文章样本。虽然数据来源主要是历史和基本面数据，但一些文章也考虑了宏观经济因素（见Alaminos等人，2023）。因此，76.5%的文章使用月度时间框架。此外，由于其特征提取能力，自动编码器（AE）仅在29.4%的文章中使用。

表9 - 价值/因子投资文章样本。FF3和FF5分别是Fama和French（1993年和2015年）提出的三因子和五因子模型。

作者

数据来源

模型

基线模型

指标

Gu等人(2021)

历史和基本面数据

AE

FF3和其他模型

R2, SR

Son&Lee(2022)

历史和基本面数据

GNN

FF3, AE和其他模型

R2

Pan等人(2023)

历史和基本面数据

LSTM

FF5

R2, SR, MDD

Lo&Singh(2023)

历史和基本面数据

ANN

其他模型

R2

Gu等人（2021）通过引入AE资产定价模型做出了贡献。他们的研究强调了AE在降低维度和捕捉金融数据中的复杂非线性关系方面的优势，从而提高了资产定价的准确性，与传统线性模型相比。这一创新方法利用了广泛的调节信息，显著推进了资产定价方法。Pan等人（2023）将技术应用于中国股市，重点关注非线性资产定价。他们的发现表明，LSTM在预测股票价格和捕捉市场复杂性方面优于传统线性模型。Lo&Singh（2023）利用ANN提高预测准确性。他们讨论了这些模型的实际应用，并解决了模型可解释性的挑战。Son&Lee（2022）引入了一种基于GNN的多因子资产定价模型，该模型使用图论来整合不同资产和因素之间的关系。他们的方法采用GNN来模拟金融市场中的复杂互动。

这些研究共同强调了深度学习模型相对于传统方法的优越性。然而，它们也强调了需要解决的持续挑战，例如模型的可解释性和计算需求，以实现深度学习在资产定价中的全部潜力。

#### 4.2 算法交易

对于算法交易主题，我们分析了48篇文章。表10显示了一些文章样本。虽然所有文章都提供了其他模型作为基线，但只有22篇考虑了被动投资组合（例如买入并持有，B&H）。

表10 - 算法交易投资文章样本。

作者

金融资产

时间框架

数据来源

模型

基线

性能指标

P.Liu等人(2023)

中国和美国股票

每日

历史和技术

DRL with CNN+BiLSTM

B&H和其他DL模型

回报率, SR, MDD和MDD持续时间

Ye&Schuller(2023)

美国股票

1分钟

历史和技术

DQN

B&H, LSTM和其他参数

回报率

Y.Huang等人(2023)

石油和天然气

每日

历史和技术

DADE-DQN

B&H, S&H和其他参数

回报率, SR和MDD

Chan等人(2022)

EUR/GBP, EUR/JPY, EUR/USD等

每小时

历史和技术

Attention+LSTM

简单的LSTM

回报率

Y.Zhao等人(2022)

美国股票

每日

历史

LSTM

B&H和相对价值模型

回报率, SR和MDD

Theate&Ernst(2021)

美国、英国和中国股票

每日

历史

TDQN

B&H, S&H, 趋势跟随和均值回归

回报率, SR, Sortino R, Std, MDD, MDD持续时间和P&L比率

Li等人(2021)

黄金

每日

历史

VMD-ICSS-BiGRU

B&H和其他策略

回报率

S.-H.Huang等人(2021)

美国股票

1分钟

历史和技术

DRL

B&H, 固定比例和其他DRL模型

回报率和SR

Li等人(2019)

美国股票

1分钟

历史和技术

DQN with AE+LSTM

B&H, basic A3C和DQN

回报率和SR

我们发现，大多数已发表的文章都使用DRL模型（46篇中有27篇），其中7篇专门使用DQN。这些模型经过训练，可以做出决策，即购买、持有或出售金融资产。然而，在其余19篇文章中，模型的主要用途是预测价格。然后，根据这些预测创建交易规则。本文主题中使用的深度学习模型如图3所示。

![](assets/003.jpg)

图3 - 算法交易投资中使用的深度学习模型。

注意力模型最近开始实施（例如，Chan等人，2022年；Lei等人，2020年）。然而，我们没有发现GNN应用于算法交易。此外，58.3%的使用ANN的文章与其他模型相结合（例如，Ceffer等人，2018年；Kalariya等人，2022年）。

关于时间框架，这是使用盘中数据最多的主题。尽管如此，每日时间框架仍然更受欢迎（图4）。例如，Ning等人（2021年）在美国股市中使用最小的时间框架（1秒）。由于这个短时间框架，最常见的数据输入是历史和技术数据，分别占52%和37%。然而，最近，我们看到推文量、谷歌搜索趋势和其他社交媒体作为加密货币价格预测的特征（例如，Belcastro等人，2023年；Kalariya等人，2022年）。

![](assets/004.jpg)

图4 - 算法交易中的时间框架分析。

最后，所有文章都使用回报率作为性能指标。然而，该方法需要改进，以提高风险敏感性。作者至少应在其性能指标中包含夏普比率和MDD，因为它们仅出现在30篇（62.5%）和19篇（39.6%）文章中。

#### 4.3 投资组合管理

投资组合管理是本次调查中第二多的主题。表11提供了关于投资组合管理主题的一些文章样本。

表11 - 投资组合管理文章样本。

作者

金融资产

时间框架

数据来源

模型

基线

性能指标

Jang&Seong(2023)

美国股票

每日

历史和技术

DRL with CNN

DRL with ANN, EW和其他文章

回报率, SR和MDD

Behera等人(2023)

印度股票

每月

历史

ANN

其他ML模型

回报率, Std和VaR

Du(2022)

CSI 300指数, 中国和美国股票

每日

历史, 技术 和 基础

LSTM

其他ML模型

SR, Sortino R., MDD 和周转率

Barua&Sharma(2022)

MSCI亚太行业指数

每日

历史和技术

CNN+BiLSTM

CNN, LSTM, BiLSTM 和 CNN-LSTM

回报率, Std, SR 和赫芬达尔指数

Aboussalah等人(2022)

美国股票

每日

历史

DRL with CNN

B&H (EW) 和其他模型组合

回报率

Betancourt&Chen(2021)

比特币, 以太坊 和 莱特币

30分钟, 6小时 和 每日

历史

DNA-S

CNN, DQN 和 DRL

回报率 和 SR

Wang等人(2020)

英国股票

每日

历史和技术

LSTM+MV

SVM, RAF, ANN, 和 ARIMA

回报率, Std, SR, cVaR, MDD 和 Sortino R

Soleymani&Paquet(2020)

美国股票

每日

历史和技术

DRL with CNN

B&H (MW)

SR 和 MDD

Vo等人(2019)

美国股票

每日

历史和基础

DRL with BiLSTM

B&H (MW)

回报率, Std, SR 和 ESG评分

Y.Zhao等人(2018)

美国股票

每日

历史

Psi Sigma Network

ANN, RNN, B&H (EW 和 MW) 和 ARIMA

回报率, SR, Sortino R., cVaR 和 MDD

在投资组合选择中，深度学习模型的主要目标是帮助资产管理者选择哪些资产将纳入其投资组合。为此，深度学习被用来预测价格（Behera等人，2023年）、方向（Moon&Kim，2023年）或来自替代数据源（例如，社交媒体）的情感分析（Z.Huang&Tanaka，2022年）。Adosoglou等人（2021年）发表了一篇使用创新方法的文章。作者使用段落向量的分布式内存模型（Doc2Vec）模式，根据财务报告对类似公司进行聚类。这种方法有助于投资组合选择过程，击败了B&H（EW和MW）和其他基线模型。

在投资组合优化中，主要任务是在投资组合中决定每项资产将占据的权重（49%）。图5显示了用于预测最优权重的主要模型。

![](assets/005.jpg)

图5 - 在投资组合管理中用于预测最优权重的深度学习模型按年使用情况。

最常用的模型是ANN、LSTM和DRL。在ANN出现的36篇文章中，有26篇的主要模型是ANN（例如，Behera等人，2023年；Chen等人，2020年）。结论与算法交易主题类似。本主题中使用的主要模型不包括计算机科学的最新发展。例如，使用注意力机制和DRL最新发展的文章仍然很少。

大多数研究（84.7%）在其实证分析中使用股票。首选的时间框架是每日和每月，分别为71篇和14篇文章。此外，最常用的数据源是历史价格（图6）。虽然技术分析最近受到了作者们的更多关注，但使用其他输入数据（例如，Z.Huang&Tanaka，2022年）以充分发挥深度学习模型的潜力是有利的。

![](assets/006.jpg)

图6 - 在投资组合管理中使用的输入数据。

回报率是最常用的性能指标。风险调整后的回报率，如SR和Sortino R.，并不常用，因为它们仅出现在55篇和16篇文章中。最常见的风险度量是MDD，仅出现在33篇文章中。此外，使用基线模型B&H（EW或MW）的文章数量仍然很少（36.7%）。

#### 4.4 价格预测

研究人员对价格预测主题的探索最多。它们占本次调查中研究的所有出版物的73.4%。表12显示了一些关于价格预测的文章样本。然而，一些调查侧重于股票市场（例如，Jiang，2021年；Olorunnimbe&Viktor，2023年），但研究最多的金融资产是商品，其中电力几乎占了一半（图7）。

表12 - 价格预测文章样本。

文章

金融资产

数据研究

时间框架

数据来源

主要模型

基线

范围

性能指标

S.Zhang等人(2023)

WTI原油

2010/02/08至2019/12/31

每日

历史

VMD-SE-GRU

ANN, GRU 和 LSTM

下一步

RMSE, MAE, MAPE 和 R2

Md等人(2023)

三星股票

2016/11/23至2021/11/23

每日

历史

多层顺序LSTM

RNN, ANN, CNN 和 LSTM

下一步

R2, Adj.R2, NMRSE 和 RMSE

Zaheer等人(2023)

上海综合指数

1997/08/03至2022/01/24

每日

历史

CNN-RNN-LSTM

CNN, RNN, LSTM, CNN-RNN 和 CNN-LSTM

下一步

MAE, RMSE 和 R2

Jakubik等人(2023)

比特币

2013/09/12至2019/06/18

每日

历史 和 其他

BiLSTM

LSTM, CNN 和 随机森林

下一步

MSE, RMSE, AUROC, Accuracy, Precision 和 F1

Uddin等人(2023)

Russell 3000股票

1990/01/01至2020/12/30

每日

历史, 技术, 基础 和 其他

DY-GAP (GNN with attention)

SVM, LSTM, ANN 和 其他模型

下一步

RMSE, MAE, MAPE

Staffini(2022)

意大利股票

2005/01/03至2021/04/30

每日

宏观经济, 历史 和 技术

DCGAN (with CNN+BiLSTM 和 CNN)

LSTM, GAN 和 其他模型

多步 (1, 5)

RMSE, MAE 和 MAPE

Zhou等人(2022)

碳

2014/03/14至2021/08/31

每日

历史

CEEMDAN-LSTM

ANN, LSTM, GRU 和 其他模型

多步 (1, 2, 3)

RMSE, MAE, MAPE 和 R2

K.Zhang等人(2022)

煤炭

2011/01/01至2020/12/10

每日

历史

VMD-Attention-LSTM-SVR

其他LSTM变体

多步 (1, 2, 3, 4)

RMSE, MAE, MAPE 和 R2

Lin等人(2021)

S&P500 和 CSI300

2008/11/10至2019/02/20

每日

历史

CEEMDAN-LSTM

LSTM, SVM, ANNs 和 其他模型

下一步

MSE, MAE 和 R2

Memarzadeh&Keynia(2021)

电力

2006 和 2018

每小时

历史

Wavelet-LSTM

ANN 和 Abedinia等人(2017)模型

下一步

MAPE, RMSE, MAE 和 VAR

Y.Huang等人(2021)

碳

2017/11/01至2019/10/31

每日

历史

VMD-GARCH/LSTM-LSTM

LSTM 和 ANN变体

多步 (1, 2, 4, 6)

RMSE, MAE, MAPE 和 DM

Jaquart等人(2021)

比特币

2019/03/04至2019/12/10

1分钟

历史 和 其他

LSTM

GRU, ANN 和 其他模型

多步 (1, 5, 15, 60)

准确率

Livieris等人(2020)

黄金

2014/01/01至2018/04/01

每日

历史

CNN-LSTM

LSTM, ANN 和 支持向量回归

多步 (4, 6, 9)

MAE, RMSE, Accuracy, Area under curve, Sensitivity 和

Qiao&Yang(2020)

电力

1997/01至2020/12

每月

历史

WT-SAE-LSTM

ANN, LSTM, BiLSTM 和 SAE-LSTM

下一步

RMSE, MAPE, MAE, RMSPE, U1 和 U2

Dutta等人(2020)

比特币

2010/01/01至2019/06/30

每日

历史, 技术, 基础 和 其他

GRU-Dropout-GRU

GRU, LSTM 和 ANN

下一步

RMSE

J.Cao等人(2019)

美国, 香港, 德国 和 中国股票指数

2007/12/13至2017/12/12

每日

其他, 历史

CEEMDAN-LSTM

LSTM, SVM 和 ANN

下一步

RMSE, MAE 和 MAPE

Wu等人(2019)

WTI原油

1986/01/06至2016/06/06

每日

历史

EEMD-LSTM

LSTM, ANN 和 其他模型

多步 (1, 2, 3, 4)

RMSE, MAPE, Dstat 和 DM

Ji等人(2019)

比特币

2011/11/29至2018/12/31

每日

历史 和 基础

LSTM 和 ANN

DNN, LSTM, CNN, ResNet, CRNN, Ensemble 和 支持

下一步

MAPE

Y.Liu(2019)

S&P500 和 Apple股票

2000/01/03至2013/11/29

每日

历史

LSTM

VectorModel SVM 和 GARCH

下一步

RMSE

Ugurlu等人(2018)

电力

2013/01/01至2016/12/21

每小时

历史 和 基础

多层GRU

ANN, CNN, RNN, LSTM, GRU 和 天真的

下一天 (24小时)

MAE 和 DM

图7 - 价格预测主题中研究的金融资产。

最常见的预测类型是回归。区间和分类预测仅占6.4%和5.1%。一些研究执行多个选项，要么是回归-区间（Y.Cao等人，2023年）要么是回归-分类（Ji等人，2019年）。一个值得关注的问题是，使用天真的预测器作为基线的情况很少。它们仅出现在4%的文章中，要么是通过实施模型，要么是使用Theil’s U2作为性能指标。

关于所使用的深度学习模型，像其他调查（例如，Mirete-Ferrer等人，2022年；Nazareth&Reddy，2023年），LSTM仍然是使用最多的模型（图8），并且正在获得动力。ANN出现在总文章数的63.6%中。此外，ANN在出现的文章中的主要模型中占54.9%。最近，作者们也开始关注整合注意力机制（K.Zhang等人，2022年）和GNN（G.Zhao等人，2023年），这导致了更好的预测。

![](assets/007.jpg)

图8 - 价格预测主题中的深度学习模型。

Jiang（2021年）和Nazareth&Reddy（2023年）强调了整合替代数据输入的重要性。然而，图9显示，最常见的输入是仅历史数据，占该主题总出版物的65.1%。这是由于在架构中整合了解构技术。例如，CEEDAM3和VMD4最近在Zhou等人（2022年）和S.Zhang等人（2023年）中整合。宏观经济和其他输入数据仍然是最少使用的。

![](assets/008.jpg)

图9 - 价格预测主题中按年使用的输入数据（LHS）。线条代表仅使用历史数据的文章百分比（RHS）。

从公开可访问的数据库中可获得的最短时间框架通常是每日数据。因此，最常见的输入时间框架是每日数据（图10 - 价格预测主题的时间框架分析（图10）。盘中数据文章从2018年的11篇增加到2023年的28篇。

![](assets/009.jpg)

图10 - 价格预测主题的时间框架分析。

大多数研究侧重于预测下一步（66.6%），即下一个交易日或月份，具体取决于时间框架。单一步骤（2.0%）或多步骤（20.3%）的研究较长的时间框架。使用天真的预测方法的文章数量仍然很少（4.0%）。

### 5\. 稳健性分析

#### 5.1 非电力价格预测

电力研究与其他文章不同，因为它们的数据时间框架和预测范围。由于它们占本主题文章的29.0%，我们分析了排除这些文章后的结果。

分析结果与第4.4节中的结果相似。最受研究的金融资产（图11）是商品（52.7%），其次是股票（33.2%）。LSTM和ANN是最常见的模型（图12）。使用最近模型（如注意力机制和GNN）的文章数量也在增加。历史输入是最常用的数据输入（图13）。最后，使用天真的预测基线也很少（2.8%）。

![](assets/010.jpg)

图11 - 价格预测中排除电力的金融资产研究。

![](assets/011.jpg)

图12 - 价格预测主题中排除电力的深度学习模型。

![](assets/012.jpg)

图13 - 价格预测主题中按年使用的输入数据排除电力（LHS）。线条代表仅使用历史数据的文章百分比（RHS）。

然而，当分析时间框架和范围时，结果有所不同。公开可访问的数据库中可获得的最短时间框架通常是股票的每日数据和商品的每日数据。然而，关于电力，这些数据通常是每小时的间隔（图14）。

![](assets/013.jpg)

图14 - 价格预测中使用的时间框架。面板A为不考虑电力的研究。面板B仅为电力文章。

最后，这两个群体的预测范围变化（图15）。大多数非电力研究侧重于预测下一步，即下一个交易日或月份，具体取决于时间框架。然而，电力文章的主要时间框架是每小时的（Memarzadeh&Keynia，2021年），有时是30分钟（Lu等人，2022年）。因此，主要的预测范围是第二天，即24小时或48小时前。

![](assets/014.jpg)

图15 - 价格预测的预测范围。面板A为不考虑电力的研究。面板B仅为电力文章。请注意，面板A中的“第二天”已包含在“下一步”中。

### 5.2 期刊包含标准

我们通过纳入期刊过滤器进一步分析了本次审查的结果。在本节中，我们仅包括在2024年特许协会商学院指南中的学术期刊指南中发表的文章。

表13和表14显示了每本期刊和主题的文章数量。价格预测仍然是最受探索的主题，并且正在获得动力（图16）。然而，价格预测主题的文章百分比明显低于以前。它从73.37%下降到58.18%，而投资组合管理和价值/因子投资增加了它们在作者发表的主题中的存在。

表13 - 按期刊过滤后的出版物数量。

期刊

数量

Expert Systems with Applications

36

Resources Policy

13

Computational Economics

11

Energy Economics

9

Quantitative Finance

7

International Journal of Forecasting

7

Journal of Cleaner Production

6

Annals of Operations Research

6

Others

70

表14 - 按期刊过滤后的主题文章数量。

主题

数量

Price Forecast

96

Portfolio Management

44

Algorithmic Trading

14

Value/factor investing

11

Total

165

![](assets/015.jpg)

应用过滤器后，结果显示类似的结论。股票和商品仍然是研究最多的资产（图17）。历史数据是最常见的数据输入（图18）。最后，最常用的深度学习模型是LSTM，而GNN和注意力机制最近引起了作者们的关注（图19）。

图16 - 按期刊过滤的主题出版物按年。

![](assets/016.jpg)

图17 - 按期刊过滤的金融资产出版物按年。

![](assets/017.jpg)

图18 - 按期刊过滤的数据输入按年使用（LHS）。线条代表仅使用历史数据的文章百分比（RHS）。

![](assets/018.jpg)

图19 - 按期刊过滤的深度学习模型。

应用过滤器时结论的主要区别在于使用天真的模型作为基准。在价格预测中使用天真的预测方法的文章数量为15.6%（高于4.0%）。在投资组合管理中，使用B&H（MW或EW）的使用率从36.7%增加到47.7%。在算法交易中，包含夏普比率和MDD的文章数量从62.5%减少到50.0%和39.6%减少到35.7%。此外，42.9%的文章使用B&H（MW或EW）作为基准，低于45.8%。

总的来说，当应用期刊过滤器时，我们看到最佳实践略有改善。然而，这些值仍然很小。

### 6\. 结论

总之，将深度学习应用于金融资产管理已经展示了显著的变革潜力。通过多项研究确定的增强的预测精度、替代数据源的整合以及投资组合的动态优化是主要的好处。我们的广泛调查得出结论，金融资产管理领域的文章数量在过去几年中显著增加，对价格预测的关注很大。LSTM、ANN和CNN仍然是研究人员偏好的模型，而注意力机制、GAN和GNN最近获得了关注。

从我们的研究中，我们建议四个未来研究的方向。

首先，未来的研究需要在所有主题中实施计算机科学的最新进展。在价格预测中，Torres等人（2021）、Benidis等人（2022）和X. Liu & Wang（2024）的文章提供了一个良好的起点。作者调查了时间序列预测的最新进展，包括在大语言模型领域，这些模型尚未在金融资产管理中实施，可能会有更好的预测。

在价值/因子投资中，作者应专注于实施可解释的深度学习模型。诸如DeepLIFT（Shrikumar等人，2017）和SHAP（Lundberg & Lee，2017）等模型尚未应用于这一主题。DeepLIFT通过分解预测相对于基线来提供对每个输入特征对模型预测的贡献的洞察，使投资者能够确定关键因素。另一方面，SHAP使用合作博弈理论中的Shapley值来公平一致地量化每个特征的边际影响，提供细粒度的、特征级的解释。这些方法共同使投资者能够解释金融预测或股票评分中的黑箱模型，确保与价值投资的基本原则保持一致。这种提高的可解释性使投资者能够理解预测背后的原因，最终导致更明智的决策。

此外，在算法交易和投资组合管理中，还应考虑深度强化学习的进展（例如，X. Chen等人，2023；Zhu等人，2023）。例如，分层深度强化学习将任务（如资产选择和风险管理）分解为更小的步骤，使策略更加灵活。多代理深度强化学习模型模拟不同市场参与者或策略之间的互动，帮助模拟真实的市场动态。自监督深度强化学习通过在没有详细奖励定义的情况下找到模式来改进学习，这在定义成功时在金融中很棘手。

其次，大多数研究主要集中在单一类型的资产上，这限制了它们在不同金融情况下的有用性。包含多资产类型和市场投资组合对于使模型更加可靠和全球适用非常重要。这支持了Jiang（2021）和Cremers等人（2019）的发现，并表明尽管全球市场的复杂性日益增加，但研究在过去五年中保持不变。

第三，整合替代数据输入，如社交媒体的情绪分析和宏观经济指标，可以显著提高模型的效力，特别是在处理多资产和多市场投资组合时。这些数据源提供了对市场情绪和全球经济趋势的宝贵见解，对于理解各种资产类别和区域市场的相互关联行为至关重要。例如，宏观经济指标有助于预测更广泛的经济变化如何影响不同的资产。通过结合这些数据输入，模型可以捕捉到市场动态的更全面的图景，使其在管理复杂、支持多资产和多市场投资组合方面更加适应和有效。

最后，适当的基线和性能指标应作为所有研究的标配，以实现一致的比较和有意义的评估。虽然在我们的分析中应用期刊标准时，基线有所增加，但这些数字仍然有限。建立标准化的基线和指标不仅提高了研究的可重复性，而且促进了元分析。通过在GitHub等平台上提供源代码，作者可以创造机会进行系统的元分析，使研究人员能够比较方法、汇总发现，并就模型在不同背景下的有效性和普遍性得出更广泛的见解。这种合作努力可以显著推进该领域。

总之，随着计算机科学的快速发展，金融资产管理仍然需要赶上最新的发展。通过这种整合，我们可以提供证据，可能挑战EMH，并为积极与消极投资组合管理策略提供更坚实的证据。

  

  

  

  

论文见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/019.png)

  

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