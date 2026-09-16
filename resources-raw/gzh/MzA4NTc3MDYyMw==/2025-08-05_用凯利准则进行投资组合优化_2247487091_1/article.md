# 用凯利准则进行投资组合优化

InfinityQuant 映翡量化 2025-08-05 21:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487091&idx=1&sn=d2380cac135fcd1fbbdfe89f1b76e932&chksm=9ebdc8d8762e8cadf52a2cbc77652b77ffeb77fed26648da73abc50982e2100863df167fc974#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487091&idx=1&sn=d2380cac135fcd1fbbdfe89f1b76e932&chksm=9ebdc8d8762e8cadf52a2cbc77652b77ffeb77fed26648da73abc50982e2100863df167fc974#rd)

在高利率环境下，对 BIST30 成分股按月再平衡的「半凯利组合」实现了 1.07 的夏普比率，而同期普通 BIST30 指数仅为 –0.19（2023 年 1 月—2025 年 8 月）。

  
如果改用「纯凯利」「半凯利」或「2×杠杆凯利」规则，并把无风险利率设为每日变动的 TLREF（土耳其隔夜回购利率），结果会怎样？该组合相对基准指数又有何差异？

  
Atakan Devrent用完全可复现的 Python 回测给出了答案：  
•  用yfinance 日频价格；  
•  把 TLREF 作为日频无风险利率，计算超额收益；  
•  用 21 日滚动窗口估计日均收益与协方差矩阵；  
•  以 SciPy-SLSQP 求解带约束的二次优化问题；  
•  结果与代码参考GitHub：

https://github.com/adevrent/linkedin\_articles/blob/main/Article\_1/A1.ipynb

![](assets/001.jpg)