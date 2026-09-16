# 一种“状态感知”（regime-aware）的多因子组合策略框架

InfinityQuant 映翡量化 2026-06-04 09:33 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491875&idx=1&sn=58d5752dff0fb8cf7f8deb66bbec72df&chksm=9e3413389903c28db029e952c4570daab993e8924561ef38cc405f9de1dca5ace01fdf285ae2#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491875&idx=1&sn=58d5752dff0fb8cf7f8deb66bbec72df&chksm=9e3413389903c28db029e952c4570daab993e8924561ef38cc405f9de1dca5ace01fdf285ae2#rd)

这篇来自哥伦比亚大学的论文《Harvesting Factor Premia Across Regimes: An Anchor-Stabilized Hidden Markov Framework for Multifactor Portfolios》（2026年5月29日）构建了一种“状态感知”（regime-aware）的多因子组合策略。它并不试图预测收益，而是识别市场的隐含“状态”（regime），并据此进行动态再配置。

核心方法：

利用隐马尔可夫模型（HMM）从因子收益中推断潜在市场状态，并将其向前一步映射到组合权重上。VIX和CAPE并不用于预测，而只是用于稳定优化过程。

样本外结果（2013–2023）：

-   多头策略：夏普比率1.33，最大回撤-3.64%
    
-   多空策略：夏普比率1.24，超额收益6.86%
    
-   同期标普500：夏普比率0.90，最大回撤-24%
    

-   与静态高斯混合模型（GMM）相比，HMM在样本外表现显著更优（1.24 vs 0.30）。
    
-   2022年：股票下跌18%，长期债券下跌31%，而这一因子策略实现了7%至12%的收益。
    

该策略在牛市中未必跑赢股票，这是诚实的结论。但在追求平滑复利和应对市场状态切换方面，它提供了一种简洁、透明且具有“智能贝塔”（smart beta）特征的框架。

![](assets/001.png)

![](assets/002.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6823998

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)