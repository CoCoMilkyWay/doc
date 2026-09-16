# KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型

QuantML QuantML 2024-06-13 18:19 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=cfd1e6335fd519e9c83d3432892029d0f7b4f582b8619a6d414bb55101f799c87109319c6d3a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=cfd1e6335fd519e9c83d3432892029d0f7b4f582b8619a6d414bb55101f799c87109319c6d3a#rd)

Content

论文：\[2306.09862\] DoubleAdapt: A Meta-learning Approach to Incremental Learning for Stock Trend Forecasting (arxiv.org)

本文提出了一种名为DoubleAdapt的元学习方法，用于股票趋势预测的增量学习。增量学习对于在线服务如股票市场分析是实用的，因为它可以持续更新预测模型以反映最新的数据模式。股票市场动态演变，数据分布可能会发生轻微或显著的变化，这给增量学习带来了分布偏移（concept drifts）的挑战。

DoubleAdapt框架包含两个适配器（adapters），分别针对数据和模型进行适配，以减轻分布偏移的影响。论文的关键洞见是自动学习如何将股票数据适配到局部平稳分布中，以实现有利的更新。通过数据适配，可以自信地在减轻的分布偏移下适配模型参数。将每个增量学习任务视为元学习任务，并自动优化适配器以实现期望的数据适配和参数初始化。

实验表明，DoubleAdapt在真实世界的股票数据集上实现了最先进的预测性能，并且表现出相当的效率。

**(公式编辑不太友好，详细公式建议参考原论文)**

![](assets/001.png)

### **引言 (Introduction)**

-   论文讨论了股票趋势预测的重要性，并指出深度学习在该领域的广泛应用。
    
-   作为在线应用，新的股票数据以流式方式不断到达，需要持续学习新出现的模式以提高预测精度。
    
-   论文介绍了增量学习（Incremental Learning, IL）的概念，以及它在股票趋势预测中的挑战，主要是分布偏移问题。
    
-   作者提出了DoubleAdapt框架，通过数据适配和模型适配来解决这些挑战。
    

### **预备知识 (Preliminaries)**

-   定义了股票价格趋势，并描述了股票市场的特征和标签集合。
    
-   阐述了增量学习问题的定义，包括如何使用增量数据和测试数据来更新预测模型。
    

![](assets/002.png)

### **关键洞见 (Key Insights)**

-   论文提出了两个关键方向：数据适配和模型适配，以应对分布偏移问题。
    
-   数据适配旨在通过细粒度的方式将数据适配到局部平稳分布，以减少分布偏移的影响。![](assets/003.png)
    
-   模型适配关注于为每个增量学习任务学习良好的参数初始化，以适应增量数据并保持对分布偏移的鲁棒性。![](assets/004.png)
    

  

### **方法论 (Methodology)**

在第四章中，作者详细介绍了DoubleAdapt框架的方法论，包括其核心组件及其优化策略。这一框架旨在通过数据适配器和模型适配器的协同作用，增强股票趋势预测中的增量学习能力。

  

#### **4.1 总览**

DoubleAdapt框架包括三个关键组件：预测模型𝐹、模型适配器𝑀𝐴 和数据适配器𝐷𝐴。其中，数据适配器由特征适应层𝐺 和标签适应层𝐻，以及其逆函数𝐻−1组成。预测模型𝐹可以使用任意神经网络实现，例如GRU和ALSTM。

该框架的核心思想是通过数据适配器将原始的训练数据转换为适应的增量数据集，并使用模型适配器初始化和微调预测模型，以提高其在增量数据上的性能。最后，使用经过适配的数据进行在线推断。

  

#### **4.2 数据适配器**

数据适配器的主要功能是将增量数据转换为适应的增量数据集，以减小数据分布变化对模型的影响。其具体步骤如下：

1.  **增量数据适应**：给定增量数据𝐷train𝑘，数据适配器𝐷𝐴 通过特征适应层𝐺 将每个特征向量𝑥 转换为𝑥~\=𝐺(𝑥)，并通过标签适应层𝐻将相应的标签𝑦 转换为𝑦~\=𝐻(𝑦)。这一步骤生成了适应的增量数据集𝐷~train𝑘\={(𝑥~𝑖,𝑦~𝑖)}。
    
2.  **模型适应**：模型适配器𝑀𝐴 使用先前任务的参数𝜙𝑘−1 初始化预测模型𝐹。然后，模型在适应的增量数据集𝐷~train𝑘 上进行微调，优化目标是最小化训练损失𝐿train，从而生成任务特定的参数𝜃𝑘，并在线部署更新后的预测模型𝐹(⋅;𝜃𝑘)。
    
3.  **在线推断**：给定测试样本中的特征𝑥，数据适配器𝐷𝐴 通过特征适应层𝐺将𝑥转换为𝑥~\=𝐺(𝑥)。然后，预测模型𝐹(⋅;𝜃𝑘) 使用𝑥~ 生成中间预测𝑦~，再通过标签适应层的逆函数𝐻−1 将𝑦~转换为最终预测𝑦^\=𝐻−1(𝑦~)。
    

数据适配器的设计考虑了特征和标签的适应性，以便模型能够更好地处理分布变化的增量数据。

  

#### **4.3 模型适配器**

模型适配器的目的是为每个增量学习任务提供一个良好的模型参数初始化，并在此基础上调整这些初始参数以适应增量数据。其具体过程如下：

1.  **参数初始化**：模型适配器首先使用先前任务的参数𝜙𝑘−1 初始化预测模型𝐹，以保证新任务的模型具有良好的初始状态。这种初始化策略能够加速模型的收敛速度，并提高其对新数据的适应能力。
    
2.  **微调过程**：在参数初始化之后，模型在适应的增量数据集𝐷~train𝑘 上进行微调。微调的过程通过优化目标函数最小化训练损失𝐿train 来实现。这一步骤不仅更新了模型参数𝜃𝑘，使其更适应当前任务的数据分布，还保持了模型的泛化能力。
    

模型适配器的核心在于其参数初始化和微调策略，通过这两步操作，模型能够在每个增量学习任务中快速适应新的数据分布，从而保持较高的预测精度。

  

#### **4.4 元学习者优化**

元学习者的优化目标是通过神经网络减少数据层面的分布差异，并在参数层面上增强模型的泛化能力。其具体优化过程如下：

1.  **损失函数定义**：为了优化元学习者，定义了一个综合损失函数𝐿L，该损失函数包括训练损失𝐿train 和正则化项𝑅。训练损失用于衡量模型在适应数据集上的预测误差，而正则化项则用于防止模型过拟合，并增强其泛化能力。
    
2.  **优化目标**：元学习者的优化目标是最小化综合损失函数𝐿\=𝐿train+𝜆𝑅，其中𝜆是一个超参数，用于平衡训练损失和正则化项的重要性。通过最小化这一损失函数，元学习者能够同时优化数据适配和参数初始化的过程。
    
3.  **优化策略**：为了实现上述优化目标，使用了基于梯度下降的优化算法。具体来说，首先通过反向传播算法计算损失函数相对于模型参数的梯度，然后使用这些梯度更新模型参数。这样的优化策略能够确保模型参数逐步收敛到最优值，从而提高模型的预测性能和泛化能力。
    

元学习者的优化通过结合训练损失和正则化项，指导数据适配和参数初始化的过程，使得模型在处理增量数据时能够有效记忆任务特定的信息，同时对分布变化具有鲁棒性和适应性。

  

#### **4.5 方法示例**

为了更好地理解上述方法论，作者在本章中还提供了一个具体的示例，展示了如何在实际应用中实现DoubleAdapt框架。以下是该示例的关键步骤：

1.  **数据预处理**：首先对原始股票数据进行预处理，包括数据清洗、特征提取和标准化处理。这样可以保证输入数据的质量和一致性。
    
2.  **模型初始化**：使用先前任务的模型参数𝜙𝑘−1 初始化预测模型𝐹F，并通过数据适配器将增量数据转换为适应的数据集𝐷~train𝑘。
    
3.  **模型微调**：在适应的数据集上对预测模型进行微调，最小化训练损失𝐿train 并更新模型参数𝜃𝑘。
    
4.  **在线推断**：在预测阶段，通过数据适配器将测试样本的特征转换为适应的特征𝑥~，并使用经过微调的预测模型生成中间预测𝑦~，最后通过标签适应层的逆函数将其转换为最终预测𝑦^。
    

该示例展示了DoubleAdapt框架在处理增量学习任务时的具体操作流程，并验证了其在实际应用中的可行性和有效性。

  

### **训练过程 (Training Procedure)**

本章详细介绍了DoubleAdapt方法的具体训练步骤与优化策略，主要包括数据适配、模型适配、在线推理和优化元学习器四个部分。

![](assets/005.png)

### **5.1 数据适配**

在每一个任务中，首先进行的是增量数据适配。具体来说，给定增量数据 𝐷𝑘𝑡𝑟𝑎𝑖𝑛，通过数据适配器 𝐷𝐴 中的特征适配层 𝐺 和标签适配层 𝐻，对每一个特征向量 𝑥 进行转换，生成适配后的增量数据集 𝐷~𝑘𝑡𝑟𝑎𝑖𝑛。此过程的目标是调整训练数据特征分布和标签分布，使其更接近测试数据的分布，从而缓解协变量漂移和条件分布漂移问题 

  

### **5.2 模型适配**

在数据适配完成后，进行模型适配。模型适配器 𝑀𝐴MA 使用前一任务的参数 𝜙𝑘−1 初始化预测模型 𝐹。在典型的增量学习中，我们在适配后的增量数据集 𝐷~𝑘𝑡𝑟𝑎𝑖𝑛 上微调预测模型，生成特定任务的参数 𝜃𝑘。然后，更新后的预测模型 𝐹(⋅;𝜃𝑘) 会在线上部署，用于处理当前任务的测试数据

  

### **5.3 在线推理**

在线推理阶段，给定测试数据 𝐷𝑘𝑡𝑒𝑠𝑡 中的每一个样本特征 𝑥，通过特征适配层 𝐺 转换为适配后的特征 𝑥~。然后，预测模型 𝐹(⋅;𝜃𝑘)使用适配后的特征 𝑥~ 进行预测，生成中间预测值 𝑦~。最后，通过标签适配层的逆函数 𝐻−1 将中间预测值 𝑦~ 转换为最终预测值 𝑦。这一过程保证了模型在适应增量数据的同时，能够准确预测测试数据

  

### **5.4 元学习器的优化**

在每次测试后，一旦测试数据的真实标签已知，我们便可以计算测试误差，以优化我们的元学习器。形式上，通过以下公式计算均方误差（MSE）来优化元学习器：

𝐿𝑀𝑆𝐸\=1/∣𝐷~𝑘𝑡𝑒𝑠𝑡∣∑(𝑥~,𝑦)∈𝐷~𝑘𝑡𝑒𝑠𝑡(𝐻−1∘𝐹(𝑥~;𝜃𝑘,𝜓𝑘−1)−𝑦)2  

此外，为避免增量数据标签的异常适配，加入正则化项 𝐿𝑟𝑒𝑔 ：

𝐿𝑟𝑒𝑔\=1/∣𝐷𝑘𝑡𝑟𝑎𝑖𝑛∣∑(𝑥,𝑦)∈𝐷𝑘𝑡𝑟𝑎𝑖𝑛(𝐻(𝑥,𝑦;𝜓𝑘−1)−𝑦)2  

最终的测试损失 𝐿𝑡𝑒𝑠𝑡Ltest 通过以下公式计算：

𝐿𝑡𝑒𝑠𝑡\=𝐿𝑀𝑆𝐸+𝛼𝐿𝑟𝑒𝑔  

其中， 𝛼 是控制正则化强度的超参数 。

最后，优化模型适配器 𝑀𝐴 的参数 𝜙：

𝜙𝑘\=𝜙𝑘−1−𝜂𝜙∇𝜙𝐿𝑡𝑒𝑠𝑡(𝐷~𝑘𝑡𝑒𝑠𝑡;𝜃𝑘)  

其中， 𝜂𝜙 是模型适配器的学习率。与传统的MAML方法不同，我们每次仅使用一个查询集来更新元学习器，专注于提升当前测试数据的性能 。

  

### **实验 (Experiments)**

本章详细介绍了DoubleAdapt框架的实验，旨在回答以下研究问题：

-   RQ1：DoubleAdapt方法相对于最先进的方法表现如何？
    
-   RQ2：DoubleAdapt中不同组件的效果如何？
    
-   RQ3：DoubleAdapt的实际时间成本是多少？
    

  

#### **6.1 实验设置**

##### **6.1.1 数据集**

    实验在中国A股市场的两个常用的真实数据集上进行：CSI 300和CSI 500。CSI 300包含了市值最大的300只股票，反映了市场的整体表现；CSI 500则包括了剔除CSI 300成分股后的市值排名前500的股票，反映了中小盘股票的表现。

    数据特征使用开源量化投资平台Qlib中的Alpha360，Alpha360包含每日的6个指标：开盘价、收盘价、最高价、最低价、成交量加权平均价（VWAP）和成交量。每只股票在时间点$t$的特征向量由前60天的数据构成一个360维的向量。每只股票的标签由定义1中的股票价格趋势确定。数据集划分为训练集（2008年1月1日至2014年12月31日）、验证集（2015年1月1日至2016年12月31日）和测试集（2017年1月1日至2020年7月31日）。特征按训练集的统计量进行标准化，标签按相同日期的数据进行标准

  

##### **6.1.2 评价指标**

使用四个常用的评价指标：IC、ICIR、Rank IC和Rank ICIR。在每个时间点$t$，IC($t$)计算如下：

  

𝐼𝐶(𝑡)\=1/𝑁(𝑌^(𝑡)−𝑚𝑒𝑎𝑛(𝑌^(𝑡)))𝑇(𝑌(𝑡)−𝑚𝑒𝑎𝑛(𝑌(𝑡)))𝑠𝑡𝑑(𝑌^(𝑡))⋅𝑠𝑡𝑑(𝑌(𝑡))  

  

其中，$Y(t)$为实际股票价格趋势，$Ŷ(t)$为模型预测结果。在所有测试日期上报告平均IC。ICIR通过将平均IC除以IC的标准差来计算。Rank IC和Rank ICIR通过标签和预测的排名来计算。此外，还使用两个投资组合指标：超额年化收益（Return）及其信息比率（IR）。IR通过将超额年化收益除以其标准差来计算。我们的回测设置遵循Qlib的默认策略。

每个实验运行10次，并报告平均结果。对于所有六个指标，值越高表示性能越好

  

**6.2 实验结果**

##### **6.2.1 整体表现**

在CSI 300和CSI 500数据集上，DoubleAdapt框架在所有评价指标上均优于其他最先进的方法，证明了其在股票价格预测任务中的有效性。实验结果显示，DoubleAdapt不仅在IC和Rank IC等统计指标上表现突出，还在实际投资组合收益（Return）和信息比率（IR）等实际应用指标上显著提升

![](assets/006.png)

  

**6.2.2 组件分析** 

为了分析DoubleAdapt中不同组件的效果，进行了消融实验。实验结果表明，数据适配器和模型适配器的结合显著提升了模型性能。单独移除任何一个组件都会导致性能下降，这验证了两者在应对非平稳金融时间序列中的重要性

![](assets/007.png)

  

  

**6.2.3 时间成本分析** 

DoubleAdapt的时间成本分析表明，尽管其包含多个适配步骤，但其计算效率较高，适用于实际的在线学习场景。相比于传统的重复训练方法，DoubleAdapt在时间消耗上具有明显优势

![](assets/008.png)

**6.3 超参数研究** 

附录B对超参数进行了详细研究，包括任务间隔（$r$）、Softmax温度（$τ$）、变换头数（$N$）、正则化强度（$α$）和在线学习率（$η\_φ$ 和 $η\_ψ$）。实验结果表明，合理选择这些超参数可以进一步提升DoubleAdapt的性能。其中，任务间隔较短（例如5个交易日）可以更好地捕捉最新的市场模式，而适当的Softmax温度和变换头数有助于防止模型的欠拟合或过拟合

![](assets/009.png)

  

### **结论 (Conclusion)**

在这项研究中，作者提出了DoubleAdapt，这是一种用于股票趋势预测的元学习方法，旨在应对增量学习中的分布转移问题。该方法提供了两个关键见解：首先，通过细粒度的方式学习将数据适应为局部平稳分布；其次，学习为预测模型分配初始参数，使其能够快速适应增量数据，并且在面对分布转移时仍能很好地泛化。实验结果表明，DoubleAdapt在实际数据集上的预测性能达到了最先进的水平。

未来的工作将尝试将增量学习算法与滚动重训练结合起来，以避免长时间在线增量学习后出现灾难性遗忘问题。作者还相信，这种双重适应的理念可以启发其他遇到复杂分布转移挑战的应用 。

  

**代码具体使用案例参考星球教程**  

  

  

加入星球请扫我：

![](assets/010.jpg)

  

  

  

入群请扫我：  

![](assets/011.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学时序卷积模型TimesNet用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484709&idx=1&sn=f462495e96ee99019f83321a84d2fd0a&chksm=ce7e623bf909eb2d3f24882531e2ac8de4459bab71920a5985d7add81731d82d7ba55934bd07&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序模型Autoformer用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=ce7e631df909ea0b4515cbd2f95cffb0733d872a519942f1d88e6a561a01bcfe68716d31fe0c&scene=21#wechat_redirect)
    
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
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [研报复现 | 开源证券 ：形态识别，均线的收敛与发散](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)  
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
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
    

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

  

**点击蓝字**

![](assets/012.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/013.jpg)