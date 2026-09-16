# 因子动物园的真相：少数风险的多重伪装

InfinityQuant 映翡量化 2026-06-11 10:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491906&idx=1&sn=f08866ff1e51e1d55599163a7a731171&chksm=9e10c72a96ac18c861ffc86a73fce8fc5ebe6d7ea090ab1666d9acf6008cd9dadba599a01808#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491906&idx=1&sn=f08866ff1e51e1d55599163a7a731171&chksm=9e10c72a96ac18c861ffc86a73fce8fc5ebe6d7ea090ab1666d9acf6008cd9dadba599a01808#rd)

因子动物园可能只是少数几种风险披上了许多外衣。

Dickerson、Julliard 和 Mueller的论文《The Co-Pricing Factor Zoo》（2026年4月7日）在大约18 千万亿种（18 quadrillion）股票与债券因子模型中进行了系统搜索。结果显示，许多看似“不同”的因子，其实只是同一类潜在风险的不同表达方式。

核心发现：

-   不存在一个小规模的因子集合可以同时为股票和公司债定价；
    
-   最强的解释力来自于综合数十个因子的信息，而不是挑选某一个“最佳因子”。
    

### **方法亮点：**

-   扩展Bryzgalova, Huang & Julliard (2023)的贝叶斯框架，处理异质资产（债券+股票）和非交易因子。
    
-   使用**连续尖峰-平板（spike-and-slab）先验**，有效解决弱因子/无用因子识别问题。
    
-   同时报告**因子后验概率**（哪些因子是基础风险）和**市场风险价格后验期望**（如何构建最优组合）。
    
-   理论证明：构建逼近真实SDF的交易组合，应聚焦所有因子的后验风险价格，而非仅因子入选概率。
    

经济含义：

真正的优势可能不在于发现“第301个新因子”，而在于理解现有因子之间所共享的那些共同风险。

-   资产定价里更重要的是风险的共同来源，而不是因子标签本身。
    
-   所谓“新因子”未必真新，很多时候只是旧风险的不同投影。
    
-   对实务研究来说，这意味着与其继续扩充因子 zoo，不如更系统地研究**因子之间的共线结构、跨资产共性，以及它们背后的宏观/行为机制**。
    

![](assets/001.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=4589786

https://github.com/Alexander-M-Dickerson/co-pricing-factor-zoo

PDF和代码已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)