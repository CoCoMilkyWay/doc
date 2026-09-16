# 分层风险平价（HRP）优化投资组合代码实现

InfinityQuant 映翡量化 2025-07-10 18:59 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487010&idx=1&sn=87332f7104e47af0ee58ff8712fb1581&chksm=9e8096d2a0616cc4425ac940df3dc04945b9cdb8ee4e24bb3415c20b05874cdafb29498f8bd0#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487010&idx=1&sn=87332f7104e47af0ee58ff8712fb1581&chksm=9e8096d2a0616cc4425ac940df3dc04945b9cdb8ee4e24bb3415c20b05874cdafb29498f8bd0#rd)

实现一下这篇文章里的HRP代码。

[投资组合优化的几种方法](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484969&idx=1&sn=3c200ec29519c6a3fd818f5f1202db45&scene=21#wechat_redirect)

在投资组合优化领域，传统的均值-方差优化（MVO）方法由哈里·马科维茨提出，长期以来被视为现代投资组合理论的基石。然而，De Prado（2018）指出，二次优化器在优化问题中常产生不可靠的解决方案，原因在于以下几个方面：

-   不稳定性：优化过程对输入数据的小变化极为敏感，例如预期回报或方差。
    
-   集中化：倾向于生成极端分配的投资组合，即过度集中于少数资产。
    
-   表现不佳：识别出的投资组合往往无法实现预期的风险调整后回报，实际上通常表现不如基于简单启发式方法的分配策略。
    

这些问题的主要原因是需要对协方差矩阵进行求逆运算，当矩阵数值上不稳定（即“病态”矩阵）时，这一过程会产生较大误差。

De Prado 还提到了“马科维茨诅咒”，即当投资之间的相关性增加时，分散投资的需求也随之增加，但这会导致投资组合权重的估计误差进一步放大。

一个潜在的解决方案是引入分层结构，以减少小估计误差对投资组合分配的影响。这种方法解决了二次优化器的一个关键问题，即在输入数据发生微小变化时，优化器可能完全重新调整投资组合权重（除非施加明确约束）。

分层风险平价（Hierarchical Risk Parity, HRP） 是一种结合图论和机器学习技术的投资组合优化方法，基于协方差矩阵构建分散化的投资组合。其算法大致步骤如下：

-   根据协方差矩阵衍生的相关性，计算距离矩阵。
    
-   使用分层聚类和距离矩阵将资产聚类为树状结构。
    
-   在树的每个分支内计算最小方差投资组合。
    
-   逐层遍历树结构，在每个节点处合并投资组合。
    

有关算法的详细描述，请参阅参考文献中的论文。

以下是该方法的优点：

-   充分利用协方差矩阵，且无需对其求逆。
    
-   将聚类的资产视为互补而非替代。
    
-   生成的投资组合权重更稳定和鲁棒。
    
-   提供直观的框架，便于可视化。
    
-   可在优化过程中加入额外约束。
    

-   研究表明，该方法在样本外表现优于经典均值-方差方法。
    

  

`skfolio这个库很牛掰！`

**skfolio**是一个建立在scikit-learn之上的用于组合优化的Python库。它提供了一个与scikit-learn兼容的统一界面和工具，以构建、微调和交叉验证投资组合模型。

![](assets/001.png)

用skfolio实现HRP模型：

```
import requests
```

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

  

De Prado, M. L. 2016. “Building diversified portfolios that outperform out of sample,” The Journal of Portfolio Management, 42(4): 59–69: https://doi.org/10.3905/jpm.2016.42.4.059.

De Prado, M. L. 2018. Advances in Financial Machine Learning. John Wiley & Sons