# 市场风险模型：当风险模型最该管用时，它们却无效（含代码）

InfinityQuant 映翡量化 2026-01-19 10:11 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490686&idx=1&sn=35ed9d7a4533a4a40518a476e3a035a4&chksm=9e7163317d1dbb898fea8a73f1aafa19701ade60c8f10e88fadbf0e3c4e31c7f1e7f62434521#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490686&idx=1&sn=35ed9d7a4533a4a40518a476e3a035a4&chksm=9e7163317d1dbb898fea8a73f1aafa19701ade60c8f10e88fadbf0e3c4e31c7f1e7f62434521#rd)

标准风险模型往往在最关键的时刻失效。高斯分布假设、线性价格冲击、时间平方根法则。在市场平稳时期，它们似乎运转良好；但在危机中，却全面崩塌。

这篇论文《MARKET RISK MODELING》（2025年12月）构建了一套市场风险建模框架，用来量化那些**真正会对投资组合造成伤害的风险**：**肥尾风险、崩盘风险以及流动性风险**。

作者从零开始搭建了一个 Python 风险建模流水线，用于系统性地压力测试这些传统假设：

-   **非参数风险度量**：实现 Biweight Kernel 核估计方法来计算 VaR 与期望损失（Expected Shortfall），以捕捉损失分布真实且平滑的形态。
    
-   **极值理论（EVT）**：使用 Pickands 估计量与 GEV 分布对尾部崩盘风险进行建模，从而刻画尾部分布的不对称性（Fréchet vs. Weibull）。
    
-   **市场微观结构**：基于逐笔成交数据，通过网格搜索校准 Bouchaud 价格冲击模型。我们验证了文献中广泛记录的“平方根冲击定律”（r≈0.57），并通过传播子函数（propagator）的重构识别出价格黏性动态。
    
-   **分形分析**：利用 Haar 小波与 Hurst 指数（H≈0.65）证明波动率具有持续性，从而有效否定了基于 √T 的传统年化缩放规则。
    

这一实验性项目清晰地表明，传统风险管理方法在很大程度上低估了真实风险。例如，分形分析显示，相较于基于 Hurst 指数的缩放方法，标准年化方法可能会**低估超过 60% 的波动率**。

尽管该框架已具备较强的稳健性，但仍清晰地看到了未来的改进方向：用严格的优化方法替代固定参数、深化 EVT 建模（GPD / POT 方法），以及进一步检验市场微观结构中的内生性问题。

![](assets/001.png)

https://media.licdn.com/dms/document/media/v2/D4E1FAQHv2VwIjuzzww/feedshare-document-pdf-analyzed/B4EZu0MMVZKIAc-/0/1768254655843?e=1769040000&v=beta&t=jolsRc2ekUxR-QQlRGre7X6NSIYC9YtgT6-0vlcEDik  

https://github.com/MartinJondeau/Market-Risk-Modelling

PDF和代码已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![图片](assets/002.png)