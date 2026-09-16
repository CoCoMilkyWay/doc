# 用概率空间“拼接”市场：一种新的短期趋势预测方法

InfinityQuant 映翡量化 2026-06-25 08:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247492001&idx=1&sn=043cfe1fd7cfdafc6d8d8fb3a291f65e&chksm=9ef17111a35eff2dc92ffe75ba8dfdd65081753bc9555afc1110fa6da991d9307828947434e8#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247492001&idx=1&sn=043cfe1fd7cfdafc6d8d8fb3a291f65e&chksm=9ef17111a35eff2dc92ffe75ba8dfdd65081753bc9555afc1110fa6da991d9307828947434e8#rd)

9 个美国大型股（mega-caps）全部预测正确，零机器学习。

这篇论文《A novel predictive analytics model for forecasting short-term trends in equity assets prices》（2025年3月）通过将两个概率空间融合为一个，来预测股票的短期走势（关注方向而非价格）：

-   一个 ARIMA 模型 → 在每个预测价格周围生成一个正态分布；
    
-   一个参数化随机游走模型 → 对价格可能落入的位置生成二项分布；
    
-   通过滤过（两个 σ-代数）将二者“拼接”为一个统一的“过滤后”概率分布。
    

其判别规则非常简单：

-   若两个最可能的价格区间相邻，且较高区间的概率更大，则判定为看涨；
    
-   反之则为看跌；
    
-   若二者概率相同，则判定为不可决。
    

结果，在涵盖4个市场的25个资产上：

-   整体方向预测准确率达到 62.5%；
    
-   在美国大型科技股（如 AAPL、AMZN、GOOGL、TSLA 等）上实现了 100% 的准确率。
    

![](assets/001.png)

  

https://www.sciencedirect.com/science/article/pii/S2772662224001383

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)