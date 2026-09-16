# 2025Q3最佳AI量化论文

QuantML QuantML 2025-12-08 21:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492615&idx=1&sn=5e21092ea5cf8b372bb2a6d19372c8e3&chksm=cfc89ee1cc71e36e5c3b2f080e4a496d1a2d9928d986ea3eb28f148261d2c8ecaeda8d444589#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492615&idx=1&sn=5e21092ea5cf8b372bb2a6d19372c8e3&chksm=cfc89ee1cc71e36e5c3b2f080e4a496d1a2d9928d986ea3eb28f148261d2c8ecaeda8d444589#rd)

2025年第三季度，金融AI研究呈现出明显的**深化**趋势。如果说前两年的主题是“ChatGPT能做什么”，那么Q3的主题则是“AI如何重塑市场底层的定价逻辑与组织结构”。

根据SSRN最新发布的下载榜单，我们精选了最具代表性的几篇论文，从**资产定价模型**、**市场微观结构**到**宏观劳动力影响**三个维度为您解读。

* * *

### 1\. 资产定价与预测模型的新前沿

本季度最受量化从业者关注的研究集中在如何利用更复杂的模型（Graph, Ensemble, LLMs）来挖掘Alpha。

#### **《理解复杂性的美德》（Understanding The Virtue of Complexity）**

-   **作者**: Bryan T. Kelly (Yale), Semyon Malamud (EPFL)
    
-   **核心看点**: 这篇论文可能是本季度量化圈讨论最激烈的理论文章。Bryan Kelly（知名量化通过学者）等人挑战了传统的“奥卡姆剃刀”原则（即模型越简单越好）。他们通过理论推导论证了在金融机器学习中，**高复杂度的模型（High Complexity）往往能带来更优的样本外表现**。这为使用深度神经网络和庞大参数模型进行资产定价提供了强有力的理论背书。
    
-   公众号文章：[耶鲁 x AQR ｜ 模型越复杂，效果越好？](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492112&idx=1&sn=0755e79d8a46b26e0047db1eb02e49c2&scene=21#wechat_redirect)
    

#### **《GraFiN-Gen：基于图集成的多资产预测生成模型》（GraFiN-Gen: Graph-based Ensemble Generative Modelling for Multi-asset Forecasting）**

-   **作者**: Milena Vuletić (Oxford), Mihai Cucuringu (UCLA)
    
-   **核心看点**: 传统的时序预测往往忽略了资产间的关联网络。该论文提出了一种结合了**图神经网络（GNN）**和**生成式集成模型**的新框架“GraFiN-Gen”。它不仅捕捉单一资产的时间序列特征，还通过图结构捕捉资产间的联动效应（Spillovers），显著提升了多资产组合的预测精度。
    

#### **《市场的镜像：用LLM揭示投资者分歧》（The Market's Mirror: Revealing Investor Disagreement with LLMs）**

-   **作者**: Vineet Bhagwat, J. Anthony Cookson 等
    
-   **核心看点**: 传统的NLP情感分析通常只看“看涨”或“看跌”的平均值。这篇论文利用大语言模型（LLM）的高级语义理解能力，从海量文本中量化了**投资者的意见分歧（Disagreement）**。研究发现，LLM提取的“分歧因子”是一个全新的定价信号，能有效解释市场波动率和交易量的异常。
    

* * *

### 2\. AI对金融机构与市场效率的冲击

除了挖掘Alpha，Q3的论文开始严肃探讨AI对金融机构运营效率的真实影响——结果并非全是正面的。

#### **《人工智能，天然低效？澳大利亚银行业的效率陷阱》（Artificially Intelligent, Naturally Inefficient?）**

-   **作者**: Siddharth Jain, Sagar Lohani, Thomas Denigan
    
-   **核心看点**: 这是一个反直觉的发现。研究通过分析澳大利亚银行业的数据发现，尽管AI投资被认为能提升服务质量，但如果不当使用，可能会陷入“效率陷阱”（Efficiency Trap）。过度依赖自动化可能会导致服务同质化，并在处理复杂长尾问题时产生更高的隐性成本。
    

#### **《董事会中的人工智能》（Artificial Intelligence in the Boardroom）**

-   **作者**: Daniel Ferreira, Jin Li
    
-   **核心看点**: 当AI开始辅助甚至替代董事会决策时会发生什么？论文通过博弈论模型分析了AI进入公司治理顶层的后果。结论表明，AI虽然能提高信息处理能力，但也可能导致人类董事的“搭便车”行为（即过度依赖AI建议而减少尽职调查），从而在某些特定情境下降低整体治理质量。
    

* * *

### 3\. 宏观视角：生成式AI与劳动力市场

#### **《生成式AI的劳动力市场效应》（The Labor Market Effects of Generative AI）**

-   **作者**: Andrew Johnston, Christos Makridis
    
-   **核心看点**: 利用“双重差分法”（Difference-in-Differences），作者量化了AI暴露度（AI Exposure）对不同金融职位的影响。研究证实，高AI暴露度的白领职位确实面临薪资增长放缓或招聘需求结构性改变的压力，但这更多是一种“技能重组”而非单纯的替代。
    

* * *

### 总结：量化人的下一步

纵观2025年Q3的SSRN榜单，我们可以得出三个关键结论：

1.  **模型敢于“复杂”**：在风控得当的前提下，拥抱高参数量的复杂模型（尤其是结合图网络和生成式AI的模型）是获取超额收益的新方向。
    
2.  **LLM不仅是聊天工具**：将LLM用于提取深层语义信号（如“意见分歧度”），是文本挖掘策略的2.0版本。
    
3.  **警惕“AI陷阱”**：无论是在交易策略还是公司治理中，简单的自动化并不等于效率，人机协作的机制设计变得至关重要。
    

  

更多论文已整理至QuantML知识星球, 欢迎加入

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/001.jpg)