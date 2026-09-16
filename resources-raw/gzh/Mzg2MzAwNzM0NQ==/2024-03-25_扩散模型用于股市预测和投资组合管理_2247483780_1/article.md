# 扩散模型用于股市预测和投资组合管理

QuantML QuantML 2024-03-25 19:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483780&idx=1&sn=362ec2ea7bbeef1bef5d034cc1f4db75&chksm=cf690b40f15ac31d7ba0ac4d71ef67e84844d9046b8b28a746bdfcb9fec0918bc5cbbe547052#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483780&idx=1&sn=362ec2ea7bbeef1bef5d034cc1f4db75&chksm=cf690b40f15ac31d7ba0ac4d71ef67e84844d9046b8b28a746bdfcb9fec0918bc5cbbe547052#rd)

  

本文提出了一种结合去噪扩散概率模型（Denoising Diffusion Probabilistic Models, DDPM）和关系学习的方法，用于股市预测和投资组合管理。该研究旨在解决金融市场时间序列预测中的不确定性问题，特别是在金融数据中低信噪比情况下的挑战。

  

引言部分讨论了股票价格预测的重要性和挑战性，特别是在市场波动性和随机性的情况下。作者指出，尽管深度学习技术在股票市场预测中取得了一定的进展，但现有的确定性模型仍难以处理金融数据中的不确定性。因此，作者提出了使用概率模型，特别是DDPM，来更好地处理时间序列预测中的不确定性。

模型部分详细介绍了所提出的模型架构，包括一般市场预测任务的描述、条件扩散模型的构建、金融时间序列扩散的自适应噪声方法以及MaTCHS（Masked Transformer for Hypergraph-based Stock time-series generation）去噪模型的设计与实现。MaTCHS模型结合了掩码变换器（Masked Transformer）和传统网络，利用超图关系来预测股票价格。模型包括两个主要部分：Att-DiCEm，用于从金融指标中提取时间特征；以及MRT网络，用于理解不同股票之间的关系以进行价格预测。

  

![](assets/001.png)

评估部分展示了模型在多个数据集上的评估结果，包括StockNet、NASDAQ和NYSE数据集。作者比较了MaTCHS模型与其他顶尖模型的性能，如STHGCN、GCN、RSR和HATS等。评估指标包括股票走势预测的准确率、F1分数和Matthews相关系数（MCC），以及投资组合管理的累积回报率（IRR）和夏普比率。MaTCHS模型在多个评估指标上取得了最佳性能，特别是在使用扩散模型时。

  

![](assets/002.png)

结果与分析部分讨论了MaTCHS模型的两种变体：基于扩散的MaTCHS和简化版的MaTCHS（不包含扩散）。结果表明，基于扩散的MaTCHS在StockNet数据集上超越了所有其他模型，在NASDAQ和NYSE数据集上也表现出色。此外，作者还对模型进行了消融研究，分析了在注意力头上聚合关系的影响，并发现增加注意力头的数量可以带来边际改进。

局限性与结论部分指出，尽管MaTCHS模型在预测性能上取得了显著进展，但相比于其他方法，它需要更多的计算资源和时间，这限制了其在如日内交易等快速场景中的应用。作者强调，为了在实际中使用，需要更高效的扩散架构。总的来说，该研究提出的基于扩散的股票预测架构超越了当前的模型，为改进股市预测和推动该领域的研究提供了一个有前景的方向。

  

论文下载见星球

  

![](assets/003.jpg)