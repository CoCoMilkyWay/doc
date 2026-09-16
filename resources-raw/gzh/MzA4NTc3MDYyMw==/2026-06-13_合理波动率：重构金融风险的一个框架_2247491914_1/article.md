# 合理波动率：重构金融风险的一个框架

InfinityQuant 映翡量化 2026-06-13 08:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491914&idx=1&sn=4c47b232cb011a5f6af6b750fc670657&chksm=9e07c329d86d76c73b58333388d818111e4caa1239b6c3e04714c024e274f59a63c6b503b99b#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491914&idx=1&sn=4c47b232cb011a5f6af6b750fc670657&chksm=9e07c329d86d76c73b58333388d818111e4caa1239b6c3e04714c024e274f59a63c6b503b99b#rd)

波动率（volatility）是金融风险的经典度量，这一地位主要源自现代投资组合理论。然而，其普适性建立在一系列严格的市场有效性假设之上，因此在很大程度上只能被视为对真实风险的不完全刻画。  

《Fair Volatility: A Framework for Reconceptualizing Financial Risk》（2026年4月29日）这篇论文指出了三点根本性的不一致之处：

（i）波动率是路径无关的，无法反映时间依赖性与非平稳性；

（ii）在衍生品主导的策略中，其相关性显著下降，因为波动率往往代表机会而非风险；

（iii）波动率缺乏绝对基准，无法说明在有效市场中何种波动水平在经济意义上是“合理”（Fair）的。

方法：

为克服这些局限，作者提出一种新的范式，将风险重新定义为“可预测性”而非“波动性”。基于一类广义随机过程，在多重分形随机指数过程（Multifractional Process with Random Exponent, MPRE）框架下，推导出波动率与 Hurst–Hölder 指数之间的解析关系。

该关系进一步给出了“合理波动率”（Fair Volatility）的形式化定义，即在市场有效条件下（价格服从半鞅过程）所隐含的波动率。

![](assets/001.png)

结果：

对全球股票指数的广泛实证分析支持了这一框架，结果表明，偏离“合理波动率”（Fair Volatility）的程度可以作为市场无效率的可操作度量，并能够区分动量驱动与均值回复的市场状态。

本文的研究不仅推进了金融风险的理论基础，也为其实证测度提供了新的工具，从而赋予波动率一个与市场效率一致且具有经济解释力的定义。

![](assets/002.png)

https://arxiv.org/abs/2509.18837

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)