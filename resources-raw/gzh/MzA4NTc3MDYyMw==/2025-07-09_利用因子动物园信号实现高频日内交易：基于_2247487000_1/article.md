# 利用因子动物园信号实现高频日内交易：基于SPY的简单策略 1.37夏普比率

InfinityQuant 映翡量化 2025-07-09 21:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487000&idx=1&sn=41bde08c63a905275e97b4b846d492a8&chksm=9e6dbfd76cbab75d86e3c799b9b7684c5ea03dcca64b4c8735ee20c7e83651486ec605790e47#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487000&idx=1&sn=41bde08c63a905275e97b4b846d492a8&chksm=9e6dbfd76cbab75d86e3c799b9b7684c5ea03dcca64b4c8735ee20c7e83651486ec605790e47#rd)

这篇论文通过利用“因子动物园”（272个高频投资组合）的信号，可以在日内预测市场总回报。提出了一种忽略跳跃的模型，强调通过机器学习捕捉交易量、尾部风险和流动性因子的可预测信号。

在SPY上基于信号正负的简单交易规则。

扣除交易成本后，夏普比率达1.37，无隔夜持仓，纯日内优势。

![](assets/001.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=4388560