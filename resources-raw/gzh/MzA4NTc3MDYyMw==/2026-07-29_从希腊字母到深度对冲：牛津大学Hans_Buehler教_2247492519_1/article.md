# 从希腊字母到深度对冲：牛津大学Hans Buehler教授的《Learning to Trade》讲义

InfinityQuant 映翡量化 2026-07-29 13:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247492519&idx=1&sn=3f559c60c93d441e6180b23832b8adbc&chksm=9e4e931e60e8157f5e8a8f6d96d7f67772b8049c198ced8dadb7d7adce4ae8e3e7b64a1697f9#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247492519&idx=1&sn=3f559c60c93d441e6180b23832b8adbc&chksm=9e4e931e60e8157f5e8a8f6d96d7f67772b8049c198ced8dadb7d7adce4ae8e3e7b64a1697f9#rd)

在衍生品交易与风险管理领域，传统方法长期依赖希腊字母（Greeks）和经典模型。但现实中，交易成本、市场冲击、不完整市场、尾部风险以及模型不确定性，往往让“理论完美对冲”在实盘中大打折扣。

牛津大学数学研究所客座教授、前摩根大通（J.P. Morgan）股票量化研究全球主管 Hans Buehler，在 2026 年的最新系列讲义《Learning to Trade I & II》中，系统性地梳理了机器学习如何重塑衍生品定价、对冲与交易的完整框架。

摘要

《Learning to Trade I - Greek, Parameter and Statistical Hedging》（2026年7月9日）

这份讲义介绍了衍生品对冲从传统基于希腊字母（Greeks）的方法到统计对冲的演变。其核心观点是：对冲决策可以从市场数据中学习，同时充分考虑交易成本、真实市场动态以及尾部风险。

《(Deep) Learning to Trade II - Deep Hedging, Model Uncertainty, Deep Bellman Hedging》（2026年7月9日）

基于Trade I ，从每日对冲进一步扩展到学习衍生品投资组合的完整对冲策略。介绍了深度对冲（Deep Hedging）、模型不确定性的处理（包括转换为风险中性测度），以及最终的深度贝尔曼对冲（Deep Bellman Hedging）。

讲义核心内容解析

讲义分为两大部分，逻辑环环相扣，从经典理论的局限性出发，逐步深入到现代深度强化学习和贝尔曼方程的最新应用。

第一部分：从经典量化金融到“统计对冲”

在《Learning to Trade I》中，讲义首先反思了以 Black-Scholes、Dupire 局部波动率（Local Volatility）等为代表的经典量化金融模型。

-   经典模型的局限：传统模型高度依赖于“无套利”和“完全市场”的假设。但在现实中，交易成本、市场冲击、流性限制无处不在。此外，由于真实的市场分布（PP测度）和风险中性分布（QQ测度）均不可知，经典模型在多步骤自动对冲中往往表现出明显的“希腊字母（Greeks）失真”。
    
-   参数对冲与统计对冲：讲义提出通过机器学习引入“第一性原理”，将对冲问题转化为经典组合优化问题。在无法简单假设资产收益呈正态分布的现实场景下，利用优化确定性等值（Optimized Certainty Equivalent, OCE）构建非平凡的目标函数。这种方法允许我们使用已有的计算架构（如 GPU/JAX），直接利用历史场景数据（或通过 GAN、Diffusion 等生成模型产生的市场路径）来进行对冲优化。
    

目前，基于这一思路的“统计对冲”已在工业界（如 J.P. Morgan 的流程衍生品业务中）得到了实际落地和规模化应用。

![](assets/001.png)

  

第二部分：深度对冲与模型不确定性

在《Learning to Trade II》中，将讨论推向了更具挑战性的“非线性风险”和“模型不确定性”领域。

-   Vanilla Deep Hedging（经典深度对冲）：传统的深度对冲通常将问题表述为一个有限期限内的蒙特卡洛周期性策略搜索（Periodic Policy Search）问题，利用循环神经网络（RNN）或 Transformer 压缩市场历史状态（History State），并由神经网络输出每个时间步的最优对冲决策。
    
-   防止统计套利（Statistical Arbitrage）：深度学习在寻找市场规律时，非常容易倾向于“做多指数、卖出看跌期权”等以赚取风险溢价为代价的伪套利策略。讲义详细探讨了如何通过“移除漂移（drift removal）”来重构等价马尔可夫测度（Q≪P），从而约束模型，防止对冲数值解在训练过程中“爆炸”。
    
-   奈特氏不确定性（Knightian Uncertainty）：在真实交易中，由于路径估计的误差，收益均值是极其难以准确预测的。讲义介绍了如何利用凸不确定性度量（Convex Uncertainty Measures）与 CVaR 风险度量来构建“不确定性感知”的深度对冲模型，确保策略在最坏的市场环境下依然具备稳健表现。
    
-   最新探索：深度贝尔曼对冲（Deep Bellman Hedging）：经典深度对冲的一大痛点是“每次资产组合改变或时间流逝，都需要重新训练神经网络”。为了解决这一计算瓶颈，讲义分享了目前正在进行的前沿研究——利用强化学习的 Actor-Critic 架构求解一阶贝尔曼方程。虽然目前该算法在处理复杂多资产组合时仍存在不稳定性，但其有望为高频自动对冲提供全新的实时计算方案。
    

![](assets/002.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=7086398

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=7086438

PDF已更新⬇️，更多策略、资讯⬇️

学术界的Alpha