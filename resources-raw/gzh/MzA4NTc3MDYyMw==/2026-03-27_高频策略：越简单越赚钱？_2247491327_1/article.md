# 高频策略：越简单越赚钱？

InfinityQuant 映翡量化 2026-03-27 09:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491327&idx=1&sn=60bba99d1d8eecf7890f764fbd9efd53&chksm=9e54958dbd297523dd70ea18374c34352fd5254470d3ec8168d662c28bdcfce010d1c2ecf704#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491327&idx=1&sn=60bba99d1d8eecf7890f764fbd9efd53&chksm=9e54958dbd297523dd70ea18374c34352fd5254470d3ec8168d662c28bdcfce010d1c2ecf704#rd)

高频数据已经彻底改变了我们对金融波动率的建模方式。

但在大型、现实的投资组合环境中，这些复杂的高频模型所增加的复杂度，是否真的值得呢？经过20多年的数据检验，我们的答案是：并不总是如此。

最新发表于《Journal of Applied Econometrics》的一篇论文《Revisiting EWMA in High-Frequency-Based Portfolio Optimization: A Comparative Assessment》（2026年3月）将一系列复杂的高频波动率模型与量化工具箱中最简单的工具之一——EWMA滤波器进行了对比。EWMA可以看作是对过去协方差的加权平均，其中近期观测值权重更高。这是一个参数极少、广泛应用的模型。

作者在一个包含100只美股的投资组合上进行了测试，数据跨度超过二十年，涵盖2008年金融危机和2020年等时期（使用 5 分钟采样间隔计算日内已实现协方差，并加入了隔夜收益率的贡献，以完整捕捉“收盘至收盘”的波动）。提出的简单问题是：在构建最小方差投资组合时，复杂度是否能战胜简单性？

简短答案是：并不明显，而在考虑交易成本后，简单模型大幅胜出。将更复杂的模型切换为EWMA，每年可为投资者节省高达118个基点。原因在于：复杂模型往往导致投资组合换手率更高，但事后投资组合波动率的降低幅度有限，通常不足以弥补额外的交易成本。

下图中，每个点代表一种波动率模型。理想位置在左下方：投资组合风险低且换手率低。EWMA（基准模型）无论在正常时期还是危机时期，都稳定地处于这个“甜点位”（sweet spot）。

这并不意味着复杂模型毫无用处，而是在现实的投资环境中，复杂度要想真正“回本”，门槛比我们通常假设的要高得多。

![](assets/001.png)

图里的包括4个复杂模型和5个简单模型，

4个复杂模型为：

**1️⃣HAR-DRD 模型**(Oh and Patton, 2016)：

-   全称：异构自回归对角线-相关性分解模型（Heterogeneous Autoregressive - Diagonal-Related Decomposition）。
    
-   特点：将协方差矩阵分解为对角矩阵（波动率）和相关系数矩阵，并分别使用 HAR 模型进行建模，以捕捉长记忆性。
    

**2️⃣CCHAR 模型**(Chiriac and Voev, 2011; Hautsch et al., 2015)：

-   全称：柱状 Cholesky 异构自回归模型（Column Cholesky Heterogenous Autoregressive）。
    
-   特点：通过对协方差矩阵进行 Cholesky 分解，并对其元素进行 HAR 建模，从而保证预测出的协方差矩阵始终是正定的。
    

**3️⃣DPC-CAW 模型**(Gribisch and Stollenwerk, 2020)：

-   全称：动态主成分条件自回归 Wishart 模型（Dynamic Principal Component - CAW）。
    
-   特点：这是对 CAW 模型的改进，通过引入动态主成分（DPC）来处理高维矩阵的特征向量和特征值，目的是在解决原始 CAW 模型在大规模组合中数值优化困难的问题。
    

**4️⃣HEAVY GAS 模型**(Opschoor et al., 2018)：

-   全称：基于高频数据的得分驱动波动率模型（High-frequency based volatility Generalized Autoregressive Score）。
    
-   特点：采用“得分驱动”（Score-driven）框架，假设收益率服从肥尾的学生 t 分布（Student's t-distribution），利用预测误差的梯度（得分）来更新协方差矩阵，对异常值具有更强的稳健性。
    

5个简单的模型为：

1️⃣EWMA：直接对已实现协方差矩阵进行指数加权（参数λ=0.96）。其结构极简，参数极少。

2️⃣RM94(RiskMetrics)：经典的低频 EWMA（基于日收益率，非高频）。

**3️⃣EQW**：等权重组合（1/N）。

**4️⃣L252**：基于过去 252 个交易日的历史平均已实现协方差。

**5️⃣Oracle**：先知模型（基于未来真实数据的理论上限）。

  

https://onlinelibrary.wiley.com/doi/10.1002/jae.70053

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)