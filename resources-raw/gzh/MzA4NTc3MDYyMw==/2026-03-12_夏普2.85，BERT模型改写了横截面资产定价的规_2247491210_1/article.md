# 夏普2.85，BERT模型改写了横截面资产定价的规则

InfinityQuant 映翡量化 2026-03-12 09:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491210&idx=1&sn=bf8c333a3820227737a578664f058fea&chksm=9e5fd8df8995d3e14039a5ad578428b104f4c66a88bc73c751e66864bb938d58857648f50c05#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491210&idx=1&sn=bf8c333a3820227737a578664f058fea&chksm=9e5fd8df8995d3e14039a5ad578428b104f4c66a88bc73c751e66864bb938d58857648f50c05#rd)

**论文《Generative AI for Finance: A New Framework》（2026年3月4日）把股票市场当作语言来处理——而且它真的奏效了。**

核心思路：  

正如一个词的含义来自句子中它的邻居一样，一家公司的风险溢价来自于它在同行中的排名，用特征（规模、价值、动量……）对公司进行排序，形成“句子”，然后用BERT编码器来“阅读”这些句子。

![](assets/001.png)

这个模型叫**RPBERT，核心机制**：

-   通过同类股票间的自注意力机制，学习上下文感知的公司嵌入（embeddings）。
    
-   与条件因子定价模块进行端到端（end-to-end）的联合微调。
    
-   碾压所有基准模型：LASSO、随机森林、XGBoost、IPCA、自编码器。
    

实测数据：  

-   在多空十分位投资组合上，市值加权夏普比率为 2.85，等权重夏普比率为 3.50。
    

-   切点投资组合（tangency portfolio）的夏普比率高达 4.91。
    
-   每月约 2.5% 的 Alpha 收益，在经过 CAPM、FF3（Fama-French三因子）、FF5（五因子）以及 Carhart 因子模型调整后依然稳健存在。
    
-   将三大异象（因子）库中具有统计显著性的 Alpha 比例大幅压降至低至 3%（注：即解释了绝大部分异象）。
    

如果你把公司序列打乱？模型表现直接崩溃。排名结构就是信号本身。

模型的注意力头（attention heads）具备很强的可解释性——不同的注意力头会专门负责捕捉盈利预测、流动性摩擦、资本投资和研发强度等信息。**模型能明明白白地告诉你，它究竟是基于什么逻辑在为这些公司定价。**

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6276278

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)