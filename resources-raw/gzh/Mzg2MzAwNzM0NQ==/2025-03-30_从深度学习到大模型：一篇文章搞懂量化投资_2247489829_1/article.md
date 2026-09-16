# 从深度学习到大模型：一篇文章搞懂量化投资中的AI应用

QuantML QuantML 2025-03-30 22:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489829&idx=1&sn=08e80b26c57c48417ec075da2cb9caad&chksm=cf372552fabe71c6e2a84fbc796527bd515df51e00c069a1536e71fd1a3502d26570c250678a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489829&idx=1&sn=08e80b26c57c48417ec075da2cb9caad&chksm=cf372552fabe71c6e2a84fbc796527bd515df51e00c069a1536e71fd1a3502d26570c250678a#rd)

![](assets/001.png)

本文深入探讨了人工智能（AI），特别是深度学习（DL）和大型语言模型（LLMs），在量化投资（Quant）领域的发展历程、应用现状以及未来前景，并以阿尔法策略（Alpha Strategy）作为典型案例进行详细分析。

### 一、  量化投资概述：阿尔法策略的崛起与演变

量化投资作为金融行业的重要组成部分，正日益受到技术进步的推动。量化投资策略利用统计分析、优化技术和人工智能算法来识别并利用市场低效现象，从而获得超越市场基准的回报。其中，阿尔法策略因其强大的捕捉市场低效现象的能力以及与人工智能驱动的预测方法的高度契合性，备受关注。

**1\. 阿尔法策略的定义与目标**

阿尔法策略旨在通过识别能够产生超额回报的投资机会来获取超越市场基准的收益。该策略通常包含两个部分：

-   **阿尔法端:**  专注于通过预测单个资产、板块或整体市场的趋势来生成超额回报。这些预测用于将资金配置到不同的投资工具中，以实现收益最大化。然而，阿尔法端面临着诸多挑战，例如：
    

-   资产价格预测需要处理高维、噪声数据以及复杂的模式。
    
-   投资组合配置需要在风险和回报之间进行权衡优化。
    

-   **对冲端:**  侧重于管理与市场走势相关的风险。其目标是减轻市场风险，确保阿尔法端产生的超额回报不会被侵蚀。对冲端通常采用对冲投资组合，例如股票指数期货或期权，同时尽量降低对冲成本。对冲端也面临着选择合适的对冲投资组合以及控制交易成本等挑战。![](assets/002.png)
    

尽管阿尔法端和对冲端都旨在在控制风险的同时创造回报，但它们面临的挑战不同，需要不同的解决方案。本文主要关注阿尔法策略的阿尔法端，并讨论了最近利用深度学习技术和大型语言模型来解决阿尔法端挑战的研究工作。

![](assets/003.png)

**2\. 阿尔法策略投资的发展历程**

阿尔法策略投资的发展历程可以概括为三个阶段：

**(1)  早期阶段：基于人工标注的交易信号和传统统计模型**

在早期阶段，研究人员主要关注对市场模式的传统统计建模，依靠个人研究人员的专业知识来识别有利可图的投资信号并开发相应的模型。然而，这种方法存在局限性：

-   金融市场具有复杂性，难以在模型中捕捉所有相关因素。
    
-   仍然严重依赖人类研究人员对交易策略进行评估和执行。
    
    ![](assets/004.png)
    

**(2)  深度学习兴起：实现从数据处理到订单执行的端到端可扩展建模**

随着该领域的成熟，深度学习的应用为量化投资开辟了新的可能性，特别是在阿尔法研究方面，深度学习已被证明能够有效识别内在模式。例如：

-   深度学习模型被用于分析空间互联性、长期时间依赖性和新闻情绪等因素，以预测价格走势和管理头寸。
    
-   深度学习擅长处理复杂的数据模式，其应用使得量化投资从数据处理到订单执行的整个流程实现了端到端可扩展建模。
    

然而，深度学习在量化投资中的应用也面临着挑战：

-   **过拟合风险:**  模型在训练数据上表现良好，但在应用于新数据时可能表现不佳。
    
-   **可解释性和准确性:**  需要进一步提高，以更好地理解和推理大量多模态数据。
    

**(3)  大型语言模型时代：人工智能从预测走向自动化**

近年来，大型语言模型（LLMs）作为量化投资领域的一股新兴力量迅速崛起，其发展迅速，应用潜力巨大，引起了广泛关注。LLMs 在理解和处理多模态数据方面表现出色，并具有自主处理大规模数据集的接收、理解、推理等复杂任务的潜力。

在当前的阿尔法策略主流研究中，LLMs 主要扮演两个角色：

-   **预测器:**
    

-   利用其强大的自然语言处理能力，从金融文本中提取情感、因果关系和潜在交易因素等。
    
-   一些研究将 LLM 生成的情感信号与传统的资产定价因素相结合进行回测，结果表明，LLM 生成的情感信号具有预测能力。
    
-   例如，ChatGPT 可以根据金融新闻标题将其分类为看涨、看跌或中性，并构建基于情感的交易信号，通过资产定价回归框架和交易模拟来评估其预测强度。
    

-   **智能体:**
    

-   一些研究已经开始探索将 LLM 作为智能体应用于量化投资，例如构建 LLM 驱动的量化智能体，将金融决策的三个阶段（数据预测、投资组合优化和订单执行）整合到一个连贯的过程中。
    
-   该智能体利用 LLM 分析各种数据源以预测股票趋势，然后使用优化算法分配资金，最后执行市场订单以实现交易。
    

然而，LLM 在量化投资中的实际部署仍处于早期阶段，其应用仍面临一些挑战：

-   **与市场动态的错位:**  LLM 主要基于文本语料库进行训练，其对情感的解释主要基于语言线索，而非金融市场反应。
    
-   **数值时间序列数据的表示:**  LLM 处理基于文本的标记，而不是连续的数字序列，因此金融数据必须重新格式化以适应 LLM 的推理框架。
    
-   **实时决策的延迟:**  零样本提示和上下文学习虽然使 LLM 能够跨不同的预测任务进行泛化，但这些方法通常会带来计算开销。
    
    ![](assets/005.png)
    

### 二、  深度学习在阿尔法策略中的应用

深度学习已广泛应用于阿尔法策略的各个阶段，本节将系统分析深度学习如何用于增强传统阿尔法研究在每个子任务中的表现。

**(1)  数据处理**

-   **原始数据:**
    

-   金融市场不断生成具有各种形式的多模态数据，包括数值数据（报价数据、基本面数据）、关系数据（成对边、超边）、替代数据（文本、图像等）和模拟数据。
    
-   例如，报价数据包括蜡烛图和限价订单簿，基本面数据则来自财务报表，如资产负债表、损益表和现金流量表。
    
    ![](assets/006.png)
    

-   **特征工程:**
    

-   为了从原始数据中提取有意义的信息，研究人员使用从原始数据派生的属性，即因子（factors），从不同的金融角度描述资产，例如价值、规模、动量、反转、波动性等。
    
-   因子挖掘过程对应于金融数据的特征工程，包括特征构建、特征提取和特征选择三个步骤。
    
-   特征构建:  通过对原始数据的战略组合和操作，创建更具信息量的表示形式，即因子。
    
-   **特征提取:**  使用特征提取模型（例如编码器-解码器架构）来提取潜在表示或预测输出作为因子。
    
-   **特征选择:**  选择特征子集以减少维度，避免过拟合并提高模型性能，常用的方法有过滤法等。
    

![](assets/007.png)

![](assets/008.png)

**(2)  模型预测**

-   **建模数据之间的相互依赖关系:**
    

-   金融数据本质上具有时间和空间相关性，准确的建模可以提高预测准确性。
    
-   **时间模式:**  研究人员构建时间序列输入，并应用时间建模技术（例如 CNN、RNN、Transformer 等）来聚合连续时间步的信息。
    
-   **空间模式:**  研究人员采用空间建模技术，例如隐式方法（使用自注意力机制）和显式方法（使用图神经网络 GNNs）。
    
-   **时空交互:**  研究人员采用时空建模技术，将空间和时间信息融合在一起，例如解耦方法（分别编码空间和时间特征）和耦合方法（同时整合空间和时间信息）。
    

-   **定义预测目标:**
    

-   **中间目标:**  主要评估股票的未来价格走势，例如：
    

-   **个体趋势分析:**  将资产未来回报作为标签，可以建模为回归或分类任务。
    

-   **相对排名:**  关注资产在横截面框架内的相对位置，例如配对排名方法（评估资产对以确定未来的优越表现）和全局排名（优化预测与实际未来回报之间的相关性）。
    

-   最终目标优化:  直接针对最终投资组合头寸进行优化，例如：
    

-   分析一组资产作为单个样本，使用时空建模方法来解释时间序列趋势和资产间关系
    

-   输出通常包括多期投资组合头寸，并根据回报率、夏普比率等指标进行优化。
    

**(3)  投资组合优化**

-   **传统方法:**
    

-   投资组合优化始于马科维茨的现代投资组合理论，将最优投资组合生成公式化为二次规划问题。
    
-   后续方法，例如基于凯利标准的方法，旨在最大化多个时期的累积回报。
    
-   主要分为单期投资组合选择（关注马科维茨理论）和多期投资组合问题（关注累积回报最大化）。
    

-   **基于学习的方法:**
    

-   将深度学习纳入投资组合优化框架，以增强某些模块，例如：
    

-   改进动态:  例如，使用神经网络预测特定回报的分布，并计算其预期均值和方差，然后进行马科维茨优化。
    

-   改进估计器:  例如，使用神经网络预测回报和风险，并应用传统的投资组合优化方法生成最终头寸。
    

-   改进求解器:  例如，研究连续时间、连续动作和连续空间的投资组合优化问题，并推导出基于高斯策略的模型。
    

-   **端到端投资组合生成:**
    

-   一些研究使用深度神经网络将参数估计和投资组合构建结合起来，实现“端到端”效果。
    
-   强化学习模型在端到端投资组合优化领域取得了更好的市场表现，因为它消除了对复杂标签构建的需求，并允许更灵活的风险回报平衡。
    

**(4)  订单执行**

-   **传统方法:**
    

-   假设限价订单簿的动态（包括其固有动态和市场订单的影响）可以分析表示为以最低成本执行的问题。
    
-   该最优控制框架分为离散模型和连续模型，两者都旨在找到一种动态交易策略，在固定时期内执行交易，并具有反映成本和波动性组合的最优效用函数。
    

-   **强化学习框架:**
    

-   强化学习（RL）由于其在动态、顺序决策环境中的适应性，在优化订单执行方面非常有效。
    
-   强化学习任务组件与订单执行过程高度契合，例如：
    

-   **状态:**  执行过程中的市场变量，例如剩余时间和当前头寸。
    

-   **动作:**  交易过程的决策集，通常包括提交、修改或取消订单。
    

-   **奖励:**  与市场订单相关的交易成本和影响。
    

-   一些研究将 Almgren-Chriss 模型的解决方案适应于考虑特定当前市场微观结构的动态策略，并使用 Q 学习进行训练。
    
-   一些研究提出了基于深度 Q 网络（DQN）的强化学习算法，用于订单拆分。
    

### 三、  大型语言模型在阿尔法研究中的应用

大型语言模型的发展为量化投资带来了重大突破，推动其从人工智能驱动走向人工智能自动化，其未来发展前景广阔。然而，与其他深度学习方法相比，其应用仍不够成熟，在某些子任务中存在局限性。

![](assets/009.png)

**(1)  基于 LLM 的预测器**

-   **LLM 用于情感提取:**
    

-   LLM 的出现彻底改变了文本数据在量化金融中的角色，改变了投资者提取洞察和生成预测信号的方式。
    
-   早期方法依赖于基本的词频分析和基本的情感评分，但缺乏处理大规模文本信息的计算能力。
    
-   LLM 的出现使得对金融文本进行更细致、更具上下文感知能力的文本分析成为可能。
    

-   **基于嵌入的 LLM 分类器:**  利用预训练模型（例如 BERT、RoBERTa 或 FinBERT）的词或句子嵌入作为金融文本的密集向量表示，并训练监督分类器将其映射到预定义的类别（例如看涨、看跌或中性）。
    

-   **LLM 驱动的情感分类:**  直接提示 LLM 生成情感分类，通过将金融新闻或收益报告纳入结构化查询来生成情感分类。
    

-   LLM 还可以用于构建金融文本中的关系表示，例如构建静态或动态的金融关系图谱，以捕捉市场变量之间的因果关系。
    

-   **LLM 用于直接时间序列预测:**
    

-   LLM 已被证明能够在零样本情况下执行时间序列预测，无需对数值序列进行明确训练。
    
-   一些研究探索了 LLM 如何解决传统深度学习架构在跨序列推理、多源数据融合和可解释性方面的挑战，从而实现更具上下文感知能力、可解释性和适应性的预测框架。
    
-   例如，GPT-4 的推理能力（特别是当使用链式思维（CoT）提示时）显著提高了预测准确性【168†source】。
    
-   一些研究将 LLM 应用到金融时间序列预测中，例如预测纳斯达克 100 指数成分股的走势，并结合零样本和少样本推理、指令微调以及多模态数据集成来提高预测准确性【168†source】。![](assets/010.png)
    

**(2)  基于 LLM 的量化智能体**

-   **LLM 用于直接因子生成:**
    

-   LLM 可以直接生成预测因子，作为因子智能体，为交易模型中的特征工程提供了一种新方法。
    
-   例如，Alpha-GPT 引入了人机交互框架，用于量化投资中的因子挖掘【145†source】。
    

-   Alpha-GPT 利用 LLM 通过迭代对话帮助研究人员和交易员发现新的阿尔法因子，模型提出因子想法，根据人工反馈进行完善，并生成可执行的代码以实现。
    

-   这种交互式工作流程使得因子发现过程更加动态和适应性强，允许领域专家指导 AI 的推理，同时受益于其丰富的知识和模式识别能力。
    

-   一些研究探索了如何将 ChatGPT 和 GPT-4 定位为代理金融分析师来生成新的股票回报因子。
    
    ![](assets/011.png)
    

-   **LLM 驱动的量化智能体架构:**
    

-   LLM 驱动的金融智能体将金融决策的三个阶段整合到一个连贯的过程中：
    

-   **TradingAgents:**  引入了一种新颖的多智能体系统，用于金融交易，模拟交易公司的协作动态【155†source】。
    

-   **FINCON:**  引入了一种新颖的基于 LLM 的多智能体框架，用于金融决策，专注于单股交易和投资组合管理【170†source】。
    

-   **预测智能体:**  利用 LLM 分析各种数据源（例如基本面数据、价格-成交量数据、文本数据和多媒体数据）以预测股票趋势。
    

-   一些研究提出了基于 LLM 的多智能体系统，例如：
    

-   投资组合优化智能体: 使用股票预测来优化资金配置，考虑回报目标、约束和风险控制。
    

-   订单执行智能体:通过执行市场订单来实施这些配置，同时最大限度地减少市场影响带来的损失。
    

**(3)  当前局限性及未来方向**

-   **基于 LLM 的预测器:**
    

-   **情感与市场情绪的错位:**  LLM 主要基于文本语料库进行训练，其对情感的解释主要基于语言线索，而非金融市场反应。
    

-   未来研究方向包括将 LLM 衍生的情感与金融市场动态保持一致，例如通过强化学习、跨模态注意力机制或对金融特定数据集进行微调。
    

-   **数值时间序列数据的表示:**  LLM 处理基于文本的标记，而不是连续的数字序列，因此金融数据必须重新格式化以适应 LLM 的推理框架。
    

-   未来研究方向包括开发更结构化的数值时间序列数据嵌入，例如集成基于 Transformer 的数值编码器或创建专门的金融 LLM 标记化技术。
    

-   **实时决策的延迟:**  零样本提示和上下文学习虽然使 LLM 能够跨不同的预测任务进行泛化，但这些方法通常会带来计算开销。
    

-   未来研究方向包括探索轻量级、经过微调的 LLM 架构或混合模型，将 LLM 推理与低延迟数值模型（例如卡尔曼滤波器或传统时间序列回归）相结合，以提高实时响应能力。
    

-   **跨公司关系的捕捉:**  金融时间序列预测本质上是关系性的，市场走势不仅受单个公司历史价格的影响，还受其竞争对手、行业同行和宏观经济因素的影响。
    

-   未来研究方向包括探索基于图的学习技术，将 LLM 纳入关系嵌入，以编码股票间依赖关系。
    

-   **基于 LLM 的智能体:**
    

-   **预测范式的挑战:**  尽管 LLM 在自然语言处理方面表现出色，但在定量推理任务中存在明显的不足，例如识别精确的价格-成交量模式的能力有限。
    

-   一些研究建议将现有的深度学习模型作为工具集成到专门的 LLM 量化分析师智能体中，使用智能体作为生成和优化预测模型的控制中心。
    
-   一些研究探索了将 LLM 与分位数回归网络相结合的混合架构，为模型输出提供自然语言解释的同时，实现概率预测。
    

-   **投资组合优化框架的偏离:**  当前交易智能体主要关注交易单个资产，而对多资产交易和投资组合优化的研究明显不足。
    

-   一些研究建议将现有的投资组合优化技术作为工具集成到专门的 LLM 优化智能体中，使其能够调用这些方法，分析结果，执行决策，评估并自主迭代。
    
-   神经符号学方法也提供了一种有希望的方向，可以将 LLM 生成的股市论点转化为数学严谨的优化约束，同时保持机器学习模型的灵活性。
    

-   **订单执行阶段的局限性:**  大多数系统假设完美的流动性，忽略了限价订单簿的复杂动态以及大订单带来的巨大市场影响。
    

-   一些研究建议将先进的订单执行工具和市场微观结构模拟器与低延迟 LLM 推理模块集成在一起，使 LLM 交易智能体能够开发出复杂的执行策略，同时考虑市场影响和机会成本。
    

### 四、  结论

量化投资，特别是阿尔法策略，作为金融市场的前沿技术，正受到越来越多的关注。本文对深度学习和大型语言模型在量化投资中的应用进行了深入、全面的回顾，涵盖阿尔法策略研究的数据、模型和整体流程的各个方面。在此基础上，本文探讨了深度学习在各个方面的变革性影响和性能提升。此外，本文还探讨了如何最有效地利用 LLM 作为预测器和智能体。最后，本文比较了量化投资模型不同发展阶段及其应用，总结了当前局限性，分析了主要挑战和复杂性，并讨论了一系列未来研究方向。

  

  

  

  

  

更多资源见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/012.jpg)

  

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