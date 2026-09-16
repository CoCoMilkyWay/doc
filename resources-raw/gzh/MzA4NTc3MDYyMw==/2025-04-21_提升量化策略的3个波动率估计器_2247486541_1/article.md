# 提升量化策略的3个波动率估计器

InfinityQuant 映翡量化 2025-04-21 23:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486541&idx=1&sn=59ab4506107fe48a28129a6eb255ce0d&chksm=9e9495c30b74faf0a7a6e8b2fac62743ce84d9f9d91dc98253cb6463c8b82a6649b140fd6c48#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486541&idx=1&sn=59ab4506107fe48a28129a6eb255ce0d&chksm=9e9495c30b74faf0a7a6e8b2fac62743ce84d9f9d91dc98253cb6463c8b82a6649b140fd6c48#rd)

提升量化策略🚀的 3 个波动率估计器  
  
想要计算资产的波动性？  
  
大多数交易者坚持标准波动率，但有更好的估计器可以提供更多的策略。  
  
1️⃣ 标准波动率  
✅ 易于计算  
✅ 仅使用收盘价  
🚨 问题： 它忽略了柱内价格变动，这意味着您会丢失关键的波动率数据。  

![](assets/001.jpg)

  

2️⃣ 帕金森波动率  
✅ 使用最高价和最低价，而不仅仅是收盘价  
✅ 对柱内波动性更敏感  
🚨 问题： 适合剥头皮交易，但不适合波段交易，因为它忽略了开盘和收盘的变化。  

![](assets/002.jpg)

  
3️⃣ Yang-Zhang 波动率（在大多数情况下是最好的）  
✅ 使用开盘价、最高价、最低价和收盘价  
✅ 捕获柱内和柱间波动  
🚨 例外：在特定情况下，标准或帕金森波动率可能仍然更好。  

![](assets/003.jpg)

也有人说第三个是 Rogers-Satchell 波动率估计器，而不是 Yang-Zhang。待确认。

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=2691435

  

如何更进一步？  
🔹 时间相关波动率的 GARCH 模型  
🔹 期权定价的隐含波动率  
🔹 机器学习动态估计波动性