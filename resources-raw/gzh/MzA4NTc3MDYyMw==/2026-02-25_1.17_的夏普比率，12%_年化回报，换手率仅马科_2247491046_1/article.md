# 1.17 的夏普比率，12% 年化回报，换手率仅马科维茨模型的一半

InfinityQuant 映翡量化 2026-02-25 09:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491046&idx=1&sn=5408662d7a0b40858907a764c7f44a67&chksm=9e5ba27ec8fc2cbce60484b082a75f65b5db69bbf8059c6af6ba75609b01cad8007850f0d2b1#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491046&idx=1&sn=5408662d7a0b40858907a764c7f44a67&chksm=9e5ba27ec8fc2cbce60484b082a75f65b5db69bbf8059c6af6ba75609b01cad8007850f0d2b1#rd)

**J.P. Morgan AI研究团队最新论文《Deep Reinforcement Learning for Optimal Portfolio Allocation: A Comparative Study with Mean-Variance Optimization》（2026年2月19日）将深度强化学习（Deep RL）与均值-方差优化（Mean-Variance Optimization，简称 MVO）在投资组合配置任务上进行了正面对比——公平条件：相同目标、相同数据。**

一个使用**差分夏普比率（Differential Sharpe Ratio）**训练的 PPO 智能体：

-   夏普比率达到 MVO 的 **1.7 倍**（1.17 vs 0.68），
    
-   年化收益率约为 **12%**，而 MVO 仅为 6.5%，
    
-   波动率更低，换手率接近 MVO 的一半——尤其在 2020 年 3 月期间表现突出。
    

大多数深度强化学习论文都拿买持（buy-and-hold）或其他机器学习模型做基准，而这一篇直接对标从业者实际使用的经典方法。这才是它真正有趣的地方。

![](assets/001.png)

![](assets/002.png)

  

https://arxiv.org/abs/2602.17098

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)