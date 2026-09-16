# QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测

QuantML QuantML 2024-10-29 17:48 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&chksm=cf24696fbc5819e107dccf1a825440cdf019f34eb7f65a2ff815a3e101639f7f3755592659e1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&chksm=cf24696fbc5819e107dccf1a825440cdf019f34eb7f65a2ff815a3e101639f7f3755592659e1#rd)

  

# LNN介绍

液态神经网络（Liquid Neural Networks，简称LNN）是一种新型的神经网络，它受到生物大脑的启发，特别是秀丽隐杆线虫（Caenorhabditis elegans）的神经系统。这种线虫虽然只有302个神经元，却能展现出复杂的行为，如寻找食物、睡眠和学习。液态神经网络的核心特点是其动态性和连续性，它能够顺序处理数据，保留过去输入的记忆，并根据新输入调整其行为，处理可变长度的输入以增强任务理解能力。

### 液态神经网络的关键特性包括：

1.  **动态架构**：LNN的神经元比传统神经网络的神经元更具表达能力，使得LNN更具可解释性。它们可以有效地处理实时顺序数据。
    
2.  **持续学习和适应能力**：即使在训练后，LNN也能适应不断变化的数据，与传统神经网络在模型训练阶段后停止学习新信息不同，LNN可以更准确地模仿生物体的大脑。
    
3.  **处理时间序列数据**：LNN专门针对时间序列数据处理和预测而构建，能够处理连续或时间序列数据。
    
4.  **小规模和简单架构**：与传统的大型人工智能模型相比，LNN的小规模和简单架构带来了更强的可解释性，并在训练和运行模型时需要更少的计算资源。
    

2020 年的论文《液态时间常数网络Liquid Time Constant Networks》 将LNN带到了 AI/ML 领域的前沿。它旨在提高单个神经元的表征能力，而不是通过规模获得能力。

![](assets/001.jpg)

  

# QuantML-Qlib 实现

LNN已经加入到QuantML-Qlib的模型qlib/contrib/model/pytorch\_lnn\_ts.py当中，通过config配置好参数之后，即可一键运行。

在未经任何优化的情况下，LNN在选股中的表现已经超越目前SOTA模型GRU的结果，显示出了巨大的潜力  

具体运行方式如下：按照教程配置好QuantML-Qlib之后，在examples/benchmarks/LNN/workflow\_config\_lnn\_Alpha360.yaml修改相应的参数，运行目录下的run.py即可进行训练并得到最终的预测结果。

中证500内回测效果如下：

GRU:

![](assets/002.png)

LNN:

![](assets/003.png)

相比于GRU， LNN的累计超额收益从42%提升到了49%，最大回撤从27%下降到23%，具有明显的提升。且LNN模型未经任何优化，优化后结果会有进一步提升。

  

目前QuantML-Qlib Model Zoo中已经集成了40+经典以及前沿的AI模型，未来我们将继续融合新的前沿模型，希望能够使研究员专注模型优化以及策略开发，节省大量的模型开发时间。同时还有Alpha Zoo项目，目前包括GP, RL, KAN, AlphaNET, LLM, 研报因子挖掘等方法。

  

  

QuantML星球内有各类丰富的量化资源，包括上百篇论文代码，QuantML-Qlib框架，研报复现项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

  

![](assets/004.webp)