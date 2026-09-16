# 无处不在的「动量」——纵览近十年「动量」研究成果

puppy 跟puppy玩量化 2024-05-27 13:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247486121&idx=1&sn=a19db370ea6ac8d59cbc329a211b1c1d&chksm=c1e5932a6db0bb69d8cf0d365a7cf1a9fda9097085c7c59dc85f66c6eec4bc2632fa1ed8cdae#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247486121&idx=1&sn=a19db370ea6ac8d59cbc329a211b1c1d&chksm=c1e5932a6db0bb69d8cf0d365a7cf1a9fda9097085c7c59dc85f66c6eec4bc2632fa1ed8cdae#rd)

在因子好坏的评价上，我们一般会问5个问题，这个因子是不是持续有效的？在各种市场和资产上，这个因子是不是普遍存在的？因子鲁不鲁棒？因子可不可以用到实际投资中去？以及因子是否具有可解释性。(persistant、pervasive、robust、implementation、intuitive)。

但在因子动物园成百上千个因子中，仅仅只有5个因子同时满足上面的评价标准，**动量就是其中之一。**

(动量可以简单的理解为，好的更好，坏的更坏。一直上涨的股票会继续涨下去，而下跌的股票会继续跌跌不休)

回顾近几年的学术研究，动量吸引了越来越多的目光：

Factor Momentum Everywhere无处不在的动量效应(2019)

Is there Momentum in Factor Premia? Evidence from International Equity Markets因子溢价中是否存在动量？来自国际股票市场的证据(2019)

Factor Momentum and the Momentum Factor因子动量和动量因子(2020)

Factor Momentum因子动量(2021)

Is Factor Momentum More than Stock Momentum?比起股票动量，因子动量更胜一筹？(2021)

Momentum-Managed Equity Factors动量管理的股票因子(2021)

这些研究揭示了时间序列中广泛存在的因子动量，包括：

-   因子动量广泛存在于时间序列(趋势)中，通过买入近期表现最好的因子和卖出表现差的因子，这种策略取得了显著的投资表现，超过了传统的股票动量策略
    
-   因子动量解释了股票动量，股票动量策略实际上是通过因子的时机选择来间接实现的。当因子的自相关性持续时，股票动量策略获利；当自相关性崩溃时，策略就会失败。
    
-   因子动量广泛存在于各种资产和市场中
    
-   行业动量来源于因子动量
    
-   实证表明，通过短期动量进行因子管理带来的增值效果显著，能够抵消交易成本，并且在多因子组合中表现出色
    
      
    

在发表于2024年Trended Momentum趋势动量一文中，作者旗帜鲜明的提出了观点：**清晰的价格趋势是动量效应的关键，过去价格趋势的清晰度是驱动动量现象的必要条件**。

动量效应无处不在。

最早关于动量的研究要追溯到30多年以前，Narasimhan Jegadeesh和Sheridan Titman 发现动量几乎存在于各种市场：全球的股市、企业和国家债券、外汇、商品、行业等等等等。一篇发表于2023年的Option Momentum一文中，更是指出了期权的动量效应比其他资产类别更强。

但是动量策略也存在致命的弱点——“动量崩盘”。在市场趋势发生反转时，策略会出现重大回撤，这个弱点在学界被称为“Achilles heel”，这个英文单词源于古希腊的神话故事，讲述一个几乎无敌的战士，但因为脚后跟没有被保护，最终在战斗中被射中脚后跟而死亡，和动量策略的脆弱性一语双关。

近十年来学界对动量崩盘也有不少研究：

Momentum Has Its Moments动量也需择时(2015)

Momentum Crashes动量崩盘(2016)

A Century of Evidence on Trend-Following Investing趋势跟踪上一个世纪以来的证据(2017)

The Impact of Volatility Targeting波动率锚定的影响(2018)

Portfolio Management of Commodity Trading Advisors with Volatility Targeting结合波动率的商品期货投资组合管理(2019)

Conditional Volatility Targeting条件波动率锚定(2020）

Momentum Turning Points动量的转折点(2023)  

这些论文通过实证找到了一些回避或者减少“动量崩盘”的办法：

-   仅多头动量策略不容易发生深度崩盘
    
-   基于动量的均值和方差进行仓位调整，可以显著减少崩盘风险，并大幅提高动量策略的夏普比率
    
-   根据极端波动性状态调整风险暴露，在高波动性状态下减少风险暴露，在低波动性状态下增加风险暴露
    
-   当慢速和快速动量信号不一致时，市场更有可能处于转折点。
    
-   慢速和快速动量信号一致看多（或看空）更有可能表明市场处于上升趋势（或下降趋势）。
    
-   中速动量策略（如3个月或6个月的动量策略）在风险调整后的回报方面优于慢速动量策略（如12个月的动量策略）和快速动量策略（如1个月的动量策略）的平均夏普比率。
    
      
    

在Momentum Crashes and the 52-Week High动量崩溃与52周价格高点这篇文章中，作者探讨了股票相对高点位置在动量策略中的重要性，文末提出了观点：**离价格高点越远的股票，在动量策略中表现越好；且在市场反弹时，远离高点的股票的投机交易量显著增加，进一步推动了价格的上涨。**

![](assets/001.jpg)

在发表于2024年2月的《Breaking Bad Trends》一文中，作者对11个股票指数、8个债券市场和24种商品进行分析，发现**资产经历的转折点数量与其12个月趋势跟随策略的表现之间存在负相关关系**。

也就是说，资产价格走势发生显著变化的点越多，动量策略在此资产上的成绩越差。在文章中，作者比较短期回报率和长期回报率来识别转折点。

![](assets/002.jpg)

这些对动量效应的研究，对我们个人投资者有什么启示呢？

我觉得第一点是在选品种上，如果你是趋势跟踪的交易者，那么历史上趋势度越清晰，越流畅的品种肯定是上层之选(Breaking Bad Trends的启示)。

第二点是在动量信号的设计上，慢信号和快信号相结合，根据信号的一致性来判断市场是否处于转折点。（Momentum Has Its Moments动量也需择时的启示）。

第三点是根据当前波动率的大小来调整仓位，减少极端行情导致的回撤。（Conditional Volatility Targeting条件波动率锚定的启示）。