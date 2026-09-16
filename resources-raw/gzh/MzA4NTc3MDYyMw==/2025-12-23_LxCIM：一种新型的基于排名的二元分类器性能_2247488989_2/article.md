# LxCIM：一种新型的基于排名的二元分类器性能度量指标

InfinityQuant 映翡量化 2025-12-23 08:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488989&idx=2&sn=6508cedea64365da788532d11d7f93c8&chksm=9e958a8bb8f4a3c5d65dc4ae0f07f8978c846db5bfc058e7e3199e53539549f2f36dd035ab21#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488989&idx=2&sn=6508cedea64365da788532d11d7f93c8&chksm=9e958a8bb8f4a3c5d65dc4ae0f07f8978c846db5bfc058e7e3199e53539549f2f36dd035ab21#rd)

《LxCIM： a new rank-based binary classifier performance metric invariant to local exchange of classes》提出了一种新型的基于排名的二元分类器性能度量指标——LxCIM（Local Exchange of Classes Invariant Metric，本地类交换不变度量）。二元分类是机器学习中最古老、最常见和研究最多的问题之一，而用于评估模型性能的度量指标相对较少受到关注。接收者操作特征曲线下的面积（AUROC）长期以来一直是模型比较的标准选择。

尽管AUROC有诸多优势，但它并非总是理想的，尤其是在对“本地类交换”（LxC）不变的问题中——这是本文引入的一种新型度量不变性。

为了解决这一局限性，作者提出了LxCIM，该指标不仅基于排名且对本地类交换不变，而且直观、逻辑一致、始终可计算，同时通过累积准确率-决策率曲线允许更详细的分析。

LxCIM与AUROC、准确率（accuracy）和准确率-决策率曲线下的面积（AUDRC）有明确的理论联系。这些关系允许多种互补解释：作为AUROC的对称形式、准确率的基于排名模拟，或AUDRC的更具代表性和更易解释的变体。

作者展示了LxCIM在双变量因果发现问题（该问题表现出对本地类交换的不变性）中的直接应用，并说明它如何解决该领域现有度量的已知局限性。

![](assets/001.png)

这种方法可以应用在量化金融里，比如因子挖掘、多空对冲策略等，有兴趣的可以尝试。

  

所有代码和实现细节可在https://github.com/tiagobrogueira/Causal-Discovery-In-Exchangeable-Data获取。

https://www.arxiv.org/abs/2512.10053

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)