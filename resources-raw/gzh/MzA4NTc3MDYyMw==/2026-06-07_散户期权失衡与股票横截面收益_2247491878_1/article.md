# 散户期权失衡与股票横截面收益

InfinityQuant 映翡量化 2026-06-07 08:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491878&idx=1&sn=6ba4731fac58d762b07892a7ec2c599a&chksm=9ed88b8b4a61657d7d02f50e04b87428339fee198865be48dd6e75ac1a9040121fe84288f18a#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491878&idx=1&sn=6ba4731fac58d762b07892a7ec2c599a&chksm=9ed88b8b4a61657d7d02f50e04b87428339fee198865be48dd6e75ac1a9040121fe84288f18a#rd)

Sharpe 比率为 1.76，日收益约 +25 个基点；且六因子 Alpha 高于原始多空价差。《Retail Option Imbalance and the Cross-Section of Stock Returns》（2026年5月22日）这篇新论文，基于 Bryzgalova 等（2023）提出的 SLIM 拍卖标签构建的“散户看涨期权买入压力”，能够稳健地预测美国股票收益的横截面。

基于滞后一期散户看涨期权失衡排序、每日再平衡的多空十分位组合表现为：

-   日收益 +25.75 个基点（t = 2.26），Sharpe 比率 1.76
    
-   Fama-French 六因子 Alpha 为 +26.82 个基点（t = 2.52）
    
-   市场 β 为负（-0.34），动量因子暴露为负（-0.21）
    

该结果在不同子样本划分下依然稳健；即使剔除“迷因股”（meme stocks），t 值也仅下降约 18%。

累计价差在持有期 h\=2 天时达到峰值 +61.77 个基点，随后在 h\=10 天内单调衰减，呈现典型的“过冲—修正”特征。这更符合注意力驱动或“彩票型”误定价的解释，而非做市商的伽马对冲行为或信息型散户交易。

关键点在于：该效应约为 Boehmer 等（2021）基于股票交易侧所发现散户资金流效应的约 4 倍，说明期权市场可能是散户驱动误定价的更强渠道。

![](assets/001.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6781743

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)