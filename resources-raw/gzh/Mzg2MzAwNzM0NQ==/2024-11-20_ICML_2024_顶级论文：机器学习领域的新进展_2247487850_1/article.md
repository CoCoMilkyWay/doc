# ICML 2024 顶级论文：机器学习领域的新进展

QuantML QuantML 2024-11-20 20:49 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487850&idx=1&sn=2a1def2a5e6c95a953df287166d0d5e9&chksm=cf53b7cc938dc00f619e3a88a1565721ab18299ad7e0c18c2de78be9b6473a07b2867d3af86d#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487850&idx=1&sn=2a1def2a5e6c95a953df287166d0d5e9&chksm=cf53b7cc938dc00f619e3a88a1565721ab18299ad7e0c18c2de78be9b6473a07b2867d3af86d#rd)

### 引言

作为人工智能领域最负盛名的会议之一，ICML 每年都会吸引全球顶尖的研究人员提交数千篇论文。今年，ICML 共收到 9653 篇论文投稿，但最终仅接受了 2609 篇，录用率仅为 27.03%。![](assets/001.png)

本文将深入探讨 ICML 2024 上一些备受瞩目的论文，涵盖最佳论文奖、时间序列、大语言模型与迁移学习、计算机视觉与音频等多个领域。

### 最佳论文奖

**论文标题：**  Position: Considerations for Differentially Private Learning with Large-Scale Public Pretraining

**作者：**  Gautam Kamath（滑铁卢大学教授）、Florian Tramr（苏黎世联邦理工学院计算机科学家）、Nicholas Carlini（谷歌 DeepMind 研究员）

**核心内容：**

该论文对迄今为止大型语言模型（LLM）的训练范式提出了挑战。

-   **背景：**  目前，训练 LLM 通常采用以下方法：首先使用公开数据进行预训练，然后在私有数据上进行微调。然而，论文指出，公开数据本身可能包含敏感或私人信息，而即使经过“隐私保护”的微调，模型仍然可能会记住其预训练数据，这直接危害了隐私，并削弱了“隐私学习”的意义。
    
-   **问题根源：**
    

-   对公开预训练价值的过度估计，仅基于公开数据和私有数据分布重叠的参数。
    
-   训练这些大型模型需要大量计算资源，无法在最终用户的机器上执行，导致私有数据的外包。
    

-   **意义：**  该论文对当前私有学习实践的批判性立场恰逢 LLM 领域越来越多小型模型涌现之际。作者呼吁科学界考虑解决这些问题的方法。
    

### 时间序列

**1\. 论文标题：**  A decoder-only foundation model for time-series forecasting

**作者：**  Das 等人![](assets/002.png)

**核心内容：**

-   **研究问题：**  能否利用在海量时间序列数据上训练的大型预训练模型学习时间模式，从而对未见过的数据集进行时间序列预测？
    
-   **方法：**
    

-   **分块处理：**  分块类似于语言模型中的 token。
    
-   **仅解码器模型：**  给定一系列输入分块，模型经过优化，可以根据所有过去分块预测下一个分块。
    
-   **更长的输出分块：**  更长的输出序列可以避免与预测范围长度先验知识相关的限制。
    
-   受 LLM 和基础模型快速发展的启发，研究人员提出了一种名为 TimesFM（时间序列基础模型）的基础模型，用于零样本时间序列预测。
    
-   TimesFM 的架构基于以下原则：
    

-   **结果：**
    

-   该零样本模型能够达到全监督模型的性能。
    
-   在多个数据集上的实验结果表明，TimesFM 在时间序列预测任务中表现出色，甚至优于一些传统模型。
    

**2\. 论文标题：**  Position: What Can Large Language Models Tell Us about Time Series Analysis

**作者：**  Jin, Zhang 等人![](assets/003.png)

**核心内容：**

-   **主要贡献：**
    

-   **路线图：**
    
-   1950-2000 年代：统计时间序列模型（如 ARIMA、Holt-Winters）。
    
-   2010 年代：神经网络时间序列模型（如 RNN、TCN、STGNN）。
    
-   2022 年：预训练时间序列模型（如 TF-C、TimeCLR）。
    
-   2024 年：以 LLM 为中心的时间序列模型（如 Time-LLM、SocioDojo）。
    
-   为 LLM 在时间序列分析中的应用提供了新的视角。
    
-   对现有方法进行了基准测试和回顾，并提出将 LLM 集成到时间序列分析中的路线图。
    
-   确定了未来机会，例如利用 LLM 解决复杂现实世界的时间序列分析任务。
    

**3\. 论文标题：**  TimeMIL: Advancing Multivariate Time Series Classification via a Time-aware Multiple Instance Learning

**作者：**  Chen, Qiu 等人![](assets/004.png)

**核心内容：**

-   **研究问题：**  多变量时间序列分类模型如何更好地捕捉时间序列中的兴趣点和时间依赖性？
    
-   **方法：**
    

-   提出一种新的方法，称为多实例学习（TimeMIL），该方法利用弱监督学习来区分时间序列中的正负实例。
    
-   TimeMIL 将每个时间点视为一个实例，并学习区分包含正实例和负实例的包。
    
-   与传统的监督学习方法相比，TimeMIL 可以更好地捕捉时间序列中的罕见事件和模式。
    

**4\. 论文标题：**  Time Weaver: A Conditional Time Series Generation Model

**作者：**  Narasimhan 等人

**核心内容：**

-   **研究问题：**  如何将元数据（如天气、位置等）整合到时间序列生成模型中？
    
-   **方法：**
    

-   提出一种基于扩散模型的方法，该方法利用元数据（以分类、连续或时间特征的形式）来生成更逼真的时间序列。
    
-   引入了一种新的评估指标，可以更准确地捕捉生成时间序列的真实感。
    
-   该模型在能源领域等需要整合元数据的时间序列生成任务中表现出色。
    

### 大语言模型与迁移学习

**趋势：**  小型化模型成为主流，研究方向主要集中在模型蒸馏和更高效的微调技术。

**1\. 论文标题：**  Transferring Knowledge from Large Foundation Models to Small Downstream Models

**作者：**  Qiu 等人

![](assets/005.png)

**核心内容：**

-   **方法：**
    

-   基于权重的迁移信息传递有限。
    
-   预训练模型通常较大。
    
-   无法结合多个学习互补信息的模型。
    
-   提出一种新的知识迁移方法，称为自适应特征迁移（AFT）。
    
-   与传统的基于权重的迁移学习不同，AFT 直接在特征上操作，自适应地迁移那些最有用的特征。
    
-   该方法旨在解决以下与迁移学习相关的问题：
    

**2\. 论文标题：**  LLaGA: Large Language and Graph Assistant

**作者：**  Chen 等人![](assets/006.png)

**核心内容：**

-   **方法：**
    

-   提出一种名为 LLaGA（大型语言与图助手）的新模型，该模型利用 LLM 处理图数据。
    
-   该方法基于将图数据映射到与 LLM 兼容的空间。
    
-   LLaGA 在多个数据集上表现出良好的泛化能力和可解释性。
    

**3\. 论文标题：**  FrameQuant: Flexible Low-Bit Quantization for Transformers

**作者：**  Adepu 等人

**核心内容：**

-   **研究问题：**  如何在不显著降低性能的情况下，对 Transformer 模型进行更高效的量化？
    
-   **方法：**
    

-   提出了一种 2 位量化方法，该方法基于一种称为“融合帧”的谐波分析。
    
-   研究表明，量化的关键不在于原始权重空间，而在于融合帧的表示。
    
-   该方法可以在保持性能的同时，将模型大小和计算成本降低到更低水平。
    

**4\. 论文标题：**  DISTILLM: Towards Streamlined Distillation for Large Language Models

**作者：**  Ko 等人

**核心内容：**

-   **方法：**
    

-   提出了新的目标函数 Skew KLD（Kullback-Leibler 散度），该函数针对稳定的梯度和最小的近似误差进行了优化。
    
-   采用自适应非策略方法减少训练时间。
    
-   性能优异，效率高，与最先进的技术不相上下。
    
-   针对 LLM 引入了一种新的模型蒸馏方法，称为 DistiLLM。
    
-   主要贡献：
    

### 计算机视觉与音频

**1\. 论文标题：**  Vision Mamba: Efficient Visual Representation Learning with Bidirectional State Space Model

**作者：**  Zhu, Liao 等人![](assets/007.png)

**核心内容：**

-   **方法：**
    

-   利用 Mamba 架构（一种新型的状态空间模型架构）进行视觉数据处理。
    
-   Vision Mamba（Vim）采用双向状态空间模型，并结合投影层、MLP 和预测层。
    
-   与 Vision Transformers 相比，Vim 在 ImageNet 分类任务、COCO 对象检测和分割任务中表现出更优的性能，同时速度提高了 2.8 倍，GPU 内存节省了 86.8%。
    

**2\. 论文标题：**  ConvNet vs Transformer, Supervised vs CLIP: Beyond ImageNet Accuracy

**作者：**  Vishniakov 等人

**核心内容：**

-   **研究问题：**  如何超越准确率来衡量视觉模型的性能？
    
-   **方法：**
    

-   探讨了 ConvNet、Transformer 和 CLIP 等不同视觉模型在误差类型、输出校准、可迁移性、特征不变性等方面的差异。
    
-   强调了在评估视觉模型时，除了准确率之外，还需要考虑其他因素，以捕捉所有可能的细节。
    

**3\. 论文标题：**  UniAudio: Towards Universal Audio Generation with Large Language Models

**作者：**  Yang, Tian 等人

**核心内容：**

-   **方法：**
    

-   对所有类型的目标音频以及其他条件模态进行标记化。
    
-   将源-目标对连接成单个序列。
    
-   使用 LLM 进行下一个标记预测。
    
-   提出了一种名为 UniAudio 的模型，该模型利用 LLM 技术生成各种类型的音频，包括声音、语音、音乐和歌唱。
    
-   训练数据包含 165,000 小时的音频，模型参数为 10 亿。
    
-   UniAudio 的工作原理：
    

-   对所有类型的目标音频以及其他条件模态进行标记化。
    
-   将源-目标对连接成单个序列。
    
-   使用 LLM 进行下一个标记预测。
    

  

  

所有资料均已整理至星球，QuantML星球内有各类丰富的量化资源，包括上百篇论文代码，QuantML-Qlib框架，研报复现项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

  

![](assets/008.webp)