# 夏普比率 3.0+ —— “排序学习”的动量策略

InfinityQuant 映翡量化 2025-11-06 07:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487976&idx=1&sn=941f58f12c9ac32304f3c8a90a986417&chksm=9e54c09e487ac20e984ee823864fc720b6d4e430878cd4af0e585d0f998cead7899454634c43#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487976&idx=1&sn=941f58f12c9ac32304f3c8a90a986417&chksm=9e54c09e487ac20e984ee823864fc720b6d4e430878cd4af0e585d0f998cead7899454634c43#rd)

《Learning to Rank: Enhancing Momentum Strategies Across Asset Classes》一文提出，将信息检索领域的“排序学习”（Learning to Rank, LTR）算法引入金融动量投资，以提升跨资产的策略表现。传统横截面动量策略通常依据过去收益率对资产进行排名并构建多空组合，但忽视了排序问题的本质是“相对比较”而非“单体预测”。

作者采用LambdaMART算法，通过学习资产间的相对强弱关系来优化排序，从而改善组合收益与风险控制。

研究以股票指数、债券指数、大宗商品期货及外汇货币对四大资产类别为样本，比较五种策略：1️⃣传统Jegadeesh–Titman（JT）动量、2️⃣Baz等（2015）的波动率调整MACD动量、3️⃣MLP模型、4️⃣LTR算法，以及5️⃣随机排序基准。LTR模型使用22个收益类特征，包括不同时间窗口的标准化收益（1、3、5、10、21日）和多周期MACD信号，以Normalized Discounted Cumulative Gain（NDCG）评估排名精度。

结果显示，LTR在多数资产中显著提升风险调整后表现，尤其在股票和大宗商品市场。每日调仓下，LTR的夏普比率在股票达到3.40，在大宗商品为0.44，均优于传统动量；债券市场中MLP略胜一筹（1.98 vs. 1.12）；外汇市场中LTR表现稳定但优势有限。周度调仓虽整体收益下降，但LTR在商品与股票中仍保持领先，并显著降低最大回撤。

本文首次在多资产层面验证了Learning to Rank在动量策略中的有效性。其核心创新在于：通过机器学习捕捉资产间的相对排名关系，而非单独预测收益，从而为量化选股与跨资产配置提供了新的系统化思路。

![](assets/001.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5255258

  
PDF已更新⬇️