# 用波动率管理投资组合

InfinityQuant 映翡量化 2025-07-11 18:24 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487015&idx=1&sn=4bc0006129995149467462c525a69ad8&chksm=9ef24a94a5ebaa0bdd096b96f0e271030055a11e9d042057f466e472d0b263367f0a93ca5ffe#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487015&idx=1&sn=4bc0006129995149467462c525a69ad8&chksm=9ef24a94a5ebaa0bdd096b96f0e271030055a11e9d042057f466e472d0b263367f0a93ca5ffe#rd)

波动率管理是一种由Moreira和Muir在2017年提出的风险和投资组合管理技术\[1\]，已被行业从业者广泛采用。该技术基于波动率具有自相关性但与未来回报的相关性较弱的观点。实际上，这意味着在波动率低时增加对基础资产的敞口，在波动率高时减少敞口。这种方法使投资者能够改善风险调整后的回报。

![](assets/001.png)

参考文献\[2\]通过将波动率管理技术应用于行业投资组合继续这一研究方向。它使用了四种波动率衡量指标：一个月实现方差、一个月实现波动率、六个月指数加权移动平均（EWMA）实现波动率，以及GARCH预测的一个月波动率。  

通过分析，波动率管理显著提高了几乎所有行业配置的表现，证明波动率管理是投资者增加特定行业敞口的有用工具。某些行业对波动率管理的反应更好，包括科技和防御性行业。尽管在生成更高的夏普比率方面略有相似，但使用六个月指数加权移动平均波动率的波动率管理在面对杠杆限制和交易成本时表现最为稳定。该策略将科技、电信和公用事业行业的夏普比率分别提高了27.6%、30.5%和25.5%。这表明波动率管理不仅在理论上具有吸引力，对均值-方差投资者来说也具有实用性。然而，在选定子期间和经济衰退期间测试表现时，波动率管理策略的统计显著性有所减弱。证明投资者可以自信地对科技投资组合实施波动率管理策略，因为无论样本期间和交易成本如何，其经济和统计上的显著改进都优于其他行业。

简而言之，文章得出结论：使用六个月EWMA波动率度量的波动率管理最为稳定，该策略提高了科技、电信和公用事业行业的夏普比率，但并非所有行业均等受益。科技行业由于其波动率的持续性表现最佳，在选定子期间和经济衰退期间测试时，波动率管理策略的统计显著性减弱。

\[1\] Moreira, A., & Muir, T. (2017), Volatility-managed portfolios. Journal of Finance, 72(4), 1611–1644.

https://onlinelibrary.wiley.com/doi/abs/10.1111/jofi.12513

  

\[2\] Ryan Enney, Sector-Specific Volatility Management: Evidence from U.S. Equity Industry Portfolios, Claremont McKenna College, 2025  

https://scholarship.claremont.edu/cgi/viewcontent.cgi?article=5061&context=cmc\_theses