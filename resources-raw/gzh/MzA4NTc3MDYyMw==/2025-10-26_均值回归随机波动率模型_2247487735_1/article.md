# 均值回归随机波动率模型

InfinityQuant 映翡量化 2025-10-26 12:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487735&idx=1&sn=8c527fc0a8acf3bedd83f6a98389050f&chksm=9e77b49f50c09e12150728aab80cd40393a254fa5a6bddab3871fd48d9c70c21cf0cb552a085#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487735&idx=1&sn=8c527fc0a8acf3bedd83f6a98389050f&chksm=9e77b49f50c09e12150728aab80cd40393a254fa5a6bddab3871fd48d9c70c21cf0cb552a085#rd)

这篇《Mean-Reverting SABR Models: Closed-form Surfaces and Calibration for Equities》论文提供了真正的闭式解（速度超快、使用简单！！），适用于具有均值回归随机波动率的模型（#MeanRevertingSABR、#ZABR、#Heston）。这些模型仅需 5-6 个参数，就能可靠地拟合整个经验 #波动率曲面。现在，它们可以在 毫秒内完成校准/模拟——非常适合用于 #蒙特卡洛模拟、#风险价值全面重估、#交易 等场景。

  

摘要  
在本文中，我们考虑了三种随机波动率模型，每种模型具有不同的瞬时波动率动态特征：(1) 平方波动率遵循CIR过程（即经典Heston模型）；(2) 波动率遵循均值回归对数正态过程；(3) 波动率遵循CIR过程。此前的研究已为这些模型提供了半解析近似形式，即简单（非均值回归）的SABR模型，并针对特定到期日进行了适当的参数化。  
  
首先，我们使用计算机代数系统推导了这些半解析近似的闭合形式表达式，假设所有参数保持不变（但不要求预期波动率恒定）。尽管所得公式比简单SABR模型的公式长得多，但它们仍然易于处理，即使在Excel中也能轻松实现。  
  
其次，我们利用这些闭合形式表达式，将三种模型校准到EuroStoxx指数期权观察到的经验波动率表面。校准过程表现良好，对观察到的股权波动率表面实现了极佳的拟合，每表面仅需五个参数。因此，这些近似模型提供了一种比经典Heston模型或更高级模型更简单、更快速且（在数值上）更可靠的替代方案，后者缺乏闭合形式解，并且在不太复杂的实现环境中可能存在数值挑战。  
  
第三，我们分析了参数估计的稳定性和相关性。在这一分析中，我们发现了一些模型问题，其中一个问题似乎源于实际股权波动率过程的次对数正态行为。值得注意的是，与CIR方差Heston模型（1）相比，CIR波动率模型（3）似乎能最好地捕捉这一行为，并且参数更稳定。  
  
![3D SABR Surface](assets/001.png)本文的Python代码可在以下仓库获取：

https://github.com/vlad-perederiy/mean-rev\_SABR-based\_models

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5171071

  

PDF已更新⬇️

![](assets/002.jpg)