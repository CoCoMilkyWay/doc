# 端到端大规模投资组合优化：通过神经网络协方差清理方法

InfinityQuant 映翡量化 2026-04-23 11:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491534&idx=1&sn=e3398d9f60ef7d8bac4fe69f808218b9&chksm=9e84e5a94b5c1ec4be02f916b697661dfb0f524b8d2daba43d69b1dc78199a8b28992a0d016c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491534&idx=1&sn=e3398d9f60ef7d8bac4fe69f808218b9&chksm=9e84e5a94b5c1ec4be02f916b697661dfb0f524b8d2daba43d69b1dc78199a8b28992a0d016c#rd)

《End-to-End Large Portfolio Optimization for Variance Minimization with Neural Networks through Covariance Cleaning》（2026年4月21日）新论文提出了一种端到端的神经网络，直接取代了经典的协方差矩阵清理方法（QIS、Ledoit-Wolf、DCC）。该网络使用 BiLSTM，直接以已实现的投资组合方差作为训练目标。

![](assets/001.png)

具体设计：

-   旋转不变架构：镜像了全局最小方差（GMV）解的解析形式，并非黑箱模型。
-   三个可解释模块：可学习的滞后权重模块、BiLSTM 特征值清理器、以及逆波动率 MLP。
-   维度无关：同一个训练好的模型可以从几百只股票无缝扩展到 1,000 只+以上。

结果（仅多头，标的为1000 +只美股，2000–2024 年）：

完全真实的回测：包含 IBKR 风格的佣金、SEC 费用、滑点以及融资成本。

-   夏普比率达到 1.058，对比：Average Oracle 为 0.94，DCC 为 0.93，QIS 为 0.85。
-   实现波动率最低，VaR 最低，以及 CVaR也最低。
-   性能优势在 2012 年之后更为明显，并非仅是 AI 时代之前的产物。  
    

模型学到的滞后权重呈现幂律（Power Law）分布，而非经典 RiskMetrics/EWMA 所使用的指数衰减形式。仅这一点“重新思考默认的衰减核函数”就值得一读。

![](assets/002.png)

  

https://arxiv.org/abs/2507.01918

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)