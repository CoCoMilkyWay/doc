# 量化前沿速递：机器学习\[20260406\]

shameless 量化前沿速递 2026-04-07 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489479&idx=4&sn=a55e465be231b5f86e9d718e40defed6&chksm=c3f4198a7bca80d4ad7bb89a90ed54f084ed987a4a1fb117c50a85f852cdbb31ffcd7f877b35#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489479&idx=4&sn=a55e465be231b5f86e9d718e40defed6&chksm=c3f4198a7bca80d4ad7bb89a90ed54f084ed987a4a1fb117c50a85f852cdbb31ffcd7f877b35#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Semi structured multi state delinquency model for mortgage default

抵押贷款违约的半结构化多状态拖欠模型

来源:ARXIV\_20260330

\[2\] The Risk Quadrangle in Optimization

优化中的风险四边形

来源:ARXIV\_20260331

\[3\] Decomposable Reward Modeling and Realistic Environment Design for Reinforcement Learning Based Forex Trading

基于强化学习的外汇交易可分解奖励建模与现实环境设计

来源:ARXIV\_20260402

### 

\[1\] Semi structured multi state delinquency model for mortgage default

标题:抵押贷款违约的半结构化多状态拖欠模型

作者:Victor Medina-Olivares, Wangzhen Xia, Stefan Lessmann, Nadja Klein

来源:ARXIV\_20260330

链接:https://arxiv.org/pdf/2603.26309

Abstract : We propose a semi structured discrete time multi state model to analyse mortgage delinquency transitions. This model combines an easy to understand structured additive predictor, which includes linear effects and smooth functions of time and covariates, with a flexible neural network component that captures complex nonlinearities and higher order interactions. To ensure identifiability when covariates are present in both components, we orthogonalise the unstructured part relative to the structured design. For discrete time competing transitions, we derive exact transformations that map binary logistic models to valid competing transition probabilities, avoiding the need for continuous time approximations. In simulations, our framework effectively recovers structured baseline and covariate effects while using the neural component to detect interaction patterns. We demonstrate the method using the Freddie Mac Single Family Loan Level Dataset, employing an out of time test design. Compared with a structured generalised additive benchmark, the semi structured model provides modest but consistent gains in discrimination across the earliest prediction spans, while maintaining similar Brier scores. Adding macroeconomic indicators provides limited incremental benefit in this out of time evaluation and does not materially change the estimated borrower , loan , or duration driven effects. Overall, semi structured multi state modelling offers a practical compromise between transparent effect estimates and flexible pattern learning, with potential applications beyond credit transition forecasting.

Keywords : 

Abstract :我们提出了一个半结构化离散时间多状态模型来分析抵押贷款拖欠的转变。该模型结合了一个易于理解的结构化加性预测器，其中包括线性效应和时间和协变量的平滑函数，以及一个灵活的神经网络组件，可以捕获复杂的非线性和高阶相互作用。为了确保在两个组件中都存在协变量时的可识别性，我们相对于结构化设计对非结构化部分进行正交化。对于离散时间竞争转换，我们推导出了将二元逻辑模型映射到有效竞争转换概率的精确变换，从而避免了对连续时间近似的需要。在模拟中，我们的框架有效地恢复了结构化基线和协变量效应，同时使用神经组件来检测交互模式。我们使用房地美单户贷款水平数据集演示了该方法，采用了超时测试设计。与结构化广义加性基准相比，半结构化模型在最早的预测跨度内提供了适度但一致的区分增益，同时保持了类似的Brier分数。添加宏观经济指标在这种不合时宜的评估中提供了有限的增量收益，并且不会实质性地改变估计的借款人、贷款或期限驱动效应。总体而言，半结构化多状态建模在透明效果估计和灵活模式学习之间提供了一种实用的折衷方案，其潜在应用超出了信用转换预测。

Keywords :

### 

\[2\] The Risk Quadrangle in Optimization

标题:优化中的风险四边形

作者:Bogdan Grechuk, Anton Malandii, Terry Rockafellar, Stan Uryasev

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.27370

Abstract : This paper revisits and extends the 2013 development by Rockafellar and Uryasev of the Risk Quadrangle (RQ) as a unified scheme for integrating risk management, optimization, and statistical estimation. The RQ features four stochastics oriented functionals    risk, deviation, regret, and error, along with an associated statistic, and articulates their revealing and in some ways surprising interrelationships and dualizations. Additions to the RQ framework that have come to light since 2013 are reviewed in a synthesis focused on both theoretical advancements and practical applications. New quadrangles    superquantile, superquantile norm, expectile, biased mean, quantile symmetric average union, and   varphi  divergence based quadrangles    offer novel approaches to risk sensitive decision making across various fields such as machine learning, statistics, finance, and PDE constrained optimization. The theoretical contribution comes in axioms for   subregularity   relaxing   regularity   of the quadrangle functionals, which is too restrictive for some applications. The main RQ theorems and connections are revisited and rigorously extended to this more ample framework. Examples are provided in portfolio optimization, regression, and classification, demonstrating the advantages and the role played by duality, especially in ties to robust optimization and generalized stochastic divergences.

Keywords : 

Abstract :本文回顾并扩展了Rockafellar和Uryasev 2013年开发的风险四边形（RQ），将其作为整合风险管理、优化和统计估计的统一方案。RQ具有四个面向随机的泛函——风险、偏差、遗憾和错误，以及相关的统计数据，并阐明了它们之间揭示的、在某些方面令人惊讶的相互关系和二元性。自2013年以来，RQ框架的新增内容在一份综合报告中进行了回顾，该报告侧重于理论进步和实际应用。新的四边形——超分位数、超分位数范数、期望值、有偏均值、分位数对称平均并集和基于varphi散度的四边形，为机器学习、统计学、金融和PDE约束优化等各个领域的风险敏感决策提供了新的方法。理论贡献来自四边形泛函的次凸性松弛正则性公理，这对某些应用来说过于严格。重新审视了主要的RQ定理和联系，并将其严格扩展到这个更充分的框架中。在投资组合优化、回归和分类中提供了示例，展示了对偶性的优势和作用，特别是在与鲁棒优化和广义随机发散的关系中。

Keywords :

### 

\[3\] Decomposable Reward Modeling and Realistic Environment Design for Reinforcement Learning Based Forex Trading

标题:基于强化学习的外汇交易可分解奖励建模与现实环境设计

作者:Nabeel Ahmad Saidd

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00031

Abstract : Applying reinforcement learning (RL) to foreign exchange (Forex) trading remains challenging because realistic environments, well defined reward functions, and expressive action spaces must be satisfied simultaneously, yet many prior studies rely on simplified simulators, single scalar rewards, and restricted action representations, limiting both interpretability and practical relevance. This paper presents a modular RL framework designed to address these limitations through three tightly integrated components  a friction aware execution engine that enforces strict anti lookahead semantics, with observations at time t, execution at time t 1, and mark to market at time t 1, while incorporating realistic costs such as spread, commission, slippage, rollover financing, and margin triggered liquidation  a decomposable 11 component reward architecture with fixed weights and per step diagnostic logging to enable systematic ablation and component level attribution  and a 10 action discrete interface with legal action masking that encodes explicit trading primitives while enforcing margin aware feasibility constraints. Empirical evaluation on EURUSD focuses on learning dynamics rather than generalization and reveals strongly non monotonic reward interactions, where additional penalties do not reliably improve outcomes  the full reward configuration achieves the highest training Sharpe (0.765) and cumulative return (57.09 percent). The expanded action space increases return but also turnover and reduces Sharpe relative to a conservative 3 action baseline, indicating a return activity trade off under a fixed training budget, while scaling enabled variants consistently reduce drawdown, with the combined configuration achieving the strongest endpoint performance.

Keywords : 

Abstract :将强化学习（RL）应用于外汇（Forex）交易仍然具有挑战性，因为必须同时满足现实环境、定义良好的奖励函数和表达动作空间，但许多先前的研究依赖于简化的模拟器、单一标量奖励和受限的动作表示，限制了可解释性和实际相关性。本文提出了一个模块化的强化学习框架，旨在通过三个紧密集成的组件来解决这些局限性：一个摩擦感知执行引擎，它强制执行严格的反前瞻语义，在时间t进行观察，在时间t1执行，在时间t2按市值计价，同时结合了价差、佣金、滑点、展期融资和保证金触发清算等现实成本；一个可分解的11个组件奖励架构，具有固定权重和每一步诊断日志，以实现系统消融和组件级归因；一个10个动作离散接口，具有法律行动掩码，在执行保证金感知可行性约束的同时对显式交易原语进行编码。对欧元兑美元的实证评估侧重于学习动态而非泛化，并揭示了强烈的非单调奖励相互作用，在这种情况下，额外的惩罚并不能可靠地改善结果——完整的奖励配置实现了最高的训练夏普（0.765）和累积回报（57.09%）。与保守的3个行动基线相比，扩大的行动空间增加了回报，但也增加了营业额，降低了夏普，表明在固定的培训预算下进行了回报活动权衡，而支持扩展的变体持续减少了缩编，组合配置实现了最强的端点性能。

Keywords :