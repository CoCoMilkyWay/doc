# 夏普比率为 3.32 + 14 个因子无法解释的超额 Alpha + 一张展示信息如何在股票之间流动的网络图

InfinityQuant 映翡量化 2026-02-27 09:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491087&idx=1&sn=63c3c3552e5a5184e52a02d3b8eb6b00&chksm=9e9367094de0f71a18714ef970c44d2100fc9093b529ee600c01be0ea995986b43219ee3e92c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491087&idx=1&sn=63c3c3552e5a5184e52a02d3b8eb6b00&chksm=9e9367094de0f71a18714ef970c44d2100fc9093b529ee600c01be0ea995986b43219ee3e92c#rd)

一篇新论文《Stochastic Discount Factors with Cross-Asset Spillovers》（2026年2月24日）构建了一个随机折现因子（stochastic discount factor），它不再仅仅使用某只股票自身的信号，而是建模了**每一只股票的特征如何预测其他每一只股票的回报**。

该框架联合估计：

-   **Λ：哪些信号真正重要（投资、价值和盈利能力占据主导地位），**
-   **Ψ：一个溢出矩阵（spillover matrix），编码了跨资产的预测关系。**

样本外结果（1973–2023）：

-   价差组合（spread portfolios）的夏普比率为 2.21，
    
-   双变量排序（bivariate sorts）的夏普比率为 3.32，
    
-   月度 Alpha 约为 0.25%（t 值 > 11），相对于 Fama-French 5 因子、q-因子、误定价因子以及行为金融模型均显著成立，
    
-   在高/低情绪状态以及不同 VIX 波动率体制下均表现稳健。
    

网络结论：规模大、换手率低的股票是预测信息的**净发送者**（net transmitters）。小盘股则是信息的**吸收者**。动量（momentum）和反转（reversal）在 SDF 中的权重接近于零。

![](assets/001.png)

![](assets/002.png)

https://arxiv.org/abs/2602.20856

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)