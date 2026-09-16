# Stock Embedding 学习股票之间的关系

Quant-ML QuantML 2024-03-21 22:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483764&idx=1&sn=641ba97f6fbb9b771c83dbcecdba6881&chksm=cfd1d4d5e7eefcb17f027abe1f86f5b8456ec9ad25643162401eb387c15db989f6b2b80ab565#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483764&idx=1&sn=641ba97f6fbb9b771c83dbcecdba6881&chksm=cfd1d4d5e7eefcb17f027abe1f86f5b8456ec9ad25643162401eb387c15db989f6b2b80ab565#rd)

  

Stock Embeddings: Learning Distributed Representations for Financial Assets

  

如何识别金融资产价格变动之间的有意义关系，这是一个在众多金融应用中至关重要但极具挑战性的问题。尽管机器学习和深度学习技术在价格预测方面取得了显著成果，但关于资产间相关性的建模研究却相对滞后。  

为了弥补这一差距，作者们受到了自然语言处理领域最新成功的启发，提出了一种神经网络模型来训练股票嵌入。该模型利用历史回报数据来学习金融资产之间复杂的关联。文章详细介绍了这种方法及其在金融领域的潜在应用，并展示了在两个现实金融分析任务中的评估结果，这些结果表明了该方法相对于几个重要基准的实用性。

该模型的架构旨在理解历史回报数据中的动态，这些数据用于训练股票嵌入。这些嵌入在潜在空间中表示资产，使得资产之间的关系更加清晰易懂。文章指出，这些嵌入可以应用于多种金融任务，如投资组合优化、风险管理和市场预测。

总结来说，本文对金融科技领域做出了重要贡献，通过提出了一种新颖的方法来理解和利用金融资产之间的关系。作者们详细阐述了模型并展示了其评估结果，为未来在该领域的研究和应用奠定了坚实的基础。

论文及代码下载见星球

  

![](assets/001.jpg)