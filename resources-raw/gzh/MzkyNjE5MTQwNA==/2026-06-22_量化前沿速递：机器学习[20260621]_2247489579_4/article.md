# 量化前沿速递：机器学习\[20260621\]

shameless 量化前沿速递 2026-06-22 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489579&idx=4&sn=e703eb82dd5f28695f8fd73e384c9b07&chksm=c344263c837421bc717d26ee76ad5b1ab0fc78d791a9b2d2761cd2d2863032c720d8aaaf25a9#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489579&idx=4&sn=e703eb82dd5f28695f8fd73e384c9b07&chksm=c344263c837421bc717d26ee76ad5b1ab0fc78d791a9b2d2761cd2d2863032c720d8aaaf25a9#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Evaluating the Impact of Rhode Island s Self Sustaining Reemployment Services and Eligibility Assessment (RESEA) Program on Employment Outcomes

评估罗德岛州自我维持再就业服务和资格评估（RESEA）计划对就业结果的影响

来源:ARXIV\_20260615

\[2\] A Longitudinal Attribute Conditioned Neural Network for Modeling Health State Transition Probabilities in Temporally Irregular Data

用于建模时间不规则数据中健康状态转移概率的纵向属性条件神经网络

来源:ARXIV\_20260615

\[3\] Continuous time Optimal Stopping through Deep Reinforcement Learning

通过深度强化学习实现连续时间最优停止

来源:ARXIV\_20260617

### 

\[1\] Evaluating the Impact of Rhode Island s Self Sustaining Reemployment Services and Eligibility Assessment (RESEA) Program on Employment Outcomes

标题:评估罗德岛州自我维持再就业服务和资格评估（RESEA）计划对就业结果的影响

作者:Harrison H Li, Shanna Pearson-Merkowitz, David Yokum

来源:ARXIV\_20260615

链接:https://arxiv.org/pdf/2606.14621

Abstract : Prolonged unemployment carries serious economic, health, and wellbeing costs. With federal support, most U.S. states now operate a Reemployment Services and Eligibility Assessment (RESEA) program to help Unemployment Insurance (UI) claimants return to work faster. We report results from a large (N   23,549) preregistered randomized controlled trial (RCT) evaluating Rhode Island s RESEA program from February 2022 to September 2023. We estimate that selection into the program increased annualized wages by   1,153, increased reemployment by 1.5 percentage points, and reduced UI duration by nearly two weeks. The vast majority of these wage and reemployment effects appeared within two quarters of claimants  first pay dates and persisted through at least the following year, and we estimate that each dollar spent on the program saved the state   2.64. Using causal forests, a machine learning technique for estimating heterogeneous treatment effects (HTE), we also conduct an exploratory analysis to investigate if there are differential effects of selection into the RESEA program. We find that all participants experienced positive wage benefits from RESEA selection, with particularly large effects for older and lower income workers. Finally, we improve upon prior RESEA evaluations by explicitly controlling for the week of treatment assignment    a methodological refinement absent from several existing RCTs of job training programs that is important to eliminate confounding bias. We also discuss ways to harvest precision gains from baseline covariate adjustment without introducing large sample bias.

Keywords : 

Abstract :长期失业会带来严重的经济、健康和福祉成本。在联邦政府的支持下，美国大多数州现在都实施了再就业服务和资格评估（RESEA）计划，以帮助失业保险（UI）申请人更快地重返工作岗位。我们报告了一项大型（N 23549）预注册随机对照试验（RCT）的结果，该试验评估了2022年2月至2023年9月罗德岛州的RESEA计划。我们估计，选择该计划使年工资增加了1153美元，再就业率提高了1.5个百分点，UI持续时间缩短了近两周。这些工资和再就业效应中的绝大多数出现在索赔人首次付款日期的两个季度内，并至少持续到第二年，我们估计，在该计划上花费的每一美元为该州节省了2.64美元。使用因果林，一种用于估计异质处理效应（HTE）的机器学习技术，我们还进行了探索性分析，以调查RESEA程序中是否存在选择的差异效应。我们发现，所有参与者都从RESEA选择中获得了积极的工资福利，对老年和低收入工人的影响尤其大。最后，我们通过明确控制治疗分配周来改进先前的RESEA评估，这是几个现有的职业培训计划随机对照试验中缺乏的方法改进，对于消除混淆偏见非常重要。我们还讨论了在不引入大样本偏差的情况下从基线协变量调整中获得精度增益的方法。

Keywords :

### 

\[2\] A Longitudinal Attribute Conditioned Neural Network for Modeling Health State Transition Probabilities in Temporally Irregular Data

标题:用于建模时间不规则数据中健康状态转移概率的纵向属性条件神经网络

作者:Bright Kwaku Manu, Beckett Sterner, Petar Jevtic

来源:ARXIV\_20260615

链接:https://arxiv.org/pdf/2606.13880

Abstract : Accurate estimation of long term care transition probabilities is central to disability insurance pricing, reserving, and solvency assessment. Classical actuarial multi state models commonly rely on Markov, semi Markov, or proportional hazard specifications, which provide a direct connection to cohort projection but may be restrictive for irregular longitudinal health data with nonlinear aging patterns and heterogeneous covariate histories. This paper develops a well calibrated estimator of multi state transition probabilities for irregular longitudinal health data. The model learns from individual health history, incorporates the time elapsed between observations, and conditions transition probabilities on demographic and socioeconomic attributes. It produces a valid probability distribution over the next observed health state, with four possible states  healthy, mild disability, severe disability, and death. Individual probabilities are aggregated by age group and origin state to form transition matrices compatible with actuarial cohort projection. Using longitudinal data from the Health and Retirement Study, we compare the proposed estimator with logistic regression, gradient boosted trees, a recurrent neural network, and a last state persistence benchmark. The evaluation considers probabilistic accuracy, endpoint discrimination and calibration for severe disability and death, risk concentration, and transition matrix error after aggregation. The proposed estimator improves severe disability discrimination relative to logistic regression and gradient boosted tree benchmarks, maintains strong calibration, and yields the lowest transition matrix error among the evaluated models in the held out test analysis. Results show that a structured machine learning estimator can support long term care transition modeling when judged by calibration and projection fidelity, beyond discrimination.

Keywords : 

Abstract :准确估计长期护理过渡概率是残疾保险定价、准备金和偿付能力评估的核心。经典精算多态模型通常依赖于马尔可夫、半马尔可夫或比例风险规范，这些规范与队列预测直接相关，但对于具有非线性衰老模式和异质协变量历史的不规则纵向健康数据可能具有限制性。本文为不规则纵向健康数据开发了一个经过良好校准的多态转移概率估计器。该模型从个人健康史中学习，结合观察之间经过的时间，以及人口和社会经济属性的条件转换概率。它在下一个观察到的健康状态上产生了一个有效的概率分布，有四种可能的状态——健康、轻度残疾、重度残疾和死亡。个体概率按年龄组和起源状态汇总，形成与精算队列预测兼容的转移矩阵。使用健康与退休研究的纵向数据，我们将提出的估计量与逻辑回归、梯度增强树、递归神经网络和最后状态持久性基准进行了比较。评估考虑了概率准确性、终点判别和严重残疾和死亡的校准、风险集中度以及聚合后的转移矩阵误差。所提出的估计器相对于逻辑回归和梯度增强树基准提高了严重残疾的判别能力，保持了很强的校准，并在保持测试分析的评估模型中产生了最低的转移矩阵误差。结果表明，当通过校准和投影保真度进行判断时，结构化机器学习估计器可以支持长期护理过渡建模，而不是歧视。

Keywords :

### 

\[3\] Continuous time Optimal Stopping through Deep Reinforcement Learning

标题:通过深度强化学习实现连续时间最优停止

作者:Cosmin Borsa, Michael Ludkovski

来源:ARXIV\_20260617

链接:https://arxiv.org/pdf/2606.17545

Abstract : Simulation based solvers for optimal stopping problems must discretize the stopping decision. Under classical dynamic programming, a coarse exercise grid with only a few stopping opportunities can materially undervalue the optimal expected reward, whereas on a very fine grid, approximation errors accumulate through the backward recursion. To remove this limitation, we develop a new reinforcement learning inspired algorithm that enables us to learn the exercise rule at arbitrarily fine time resolution. Our CARLOS (Continuous time Adaptive Reinforcement Learning for Optimal Stopping) algorithm utilizes an aggregate deep neural network (ADNN) to learn a joint space time decision boundary. Starting from a coarse time grid, we progressively increase the frequency of stopping opportunities, while in parallel training the ADNN to refine its timing value estimates. We moreover design an adaptive sampling strategy that gradually concentrates training effort near the stopping boundary. Benchmarked results show that CARLOS delivers higher prices than existing Bermudan solvers, approaching the American upper bound, and achieves high computational efficiency relative to non RL comparators.

Keywords : 

Abstract :基于仿真的最优停车问题求解器必须对停车决策进行离散化。在经典动态规划下，只有少数停止机会的粗略练习网格可能会大大低估最佳预期奖励，而在非常精细的网格上，近似误差会通过向后递归累积。为了消除这一限制，我们开发了一种新的强化学习启发算法，使我们能够以任意精细的时间分辨率学习练习规则。我们的CARLOS（用于最优停止的连续时间自适应强化学习）算法利用聚合深度神经网络（ADNN）来学习联合时空决策边界。从粗略的时间网格开始，我们逐步增加停止机会的频率，同时并行训练ADNN以改进其定时值估计。此外，我们还设计了一种自适应采样策略，该策略逐渐将训练工作集中在停止边界附近。基准测试结果表明，CARLOS的价格高于现有的百慕大求解器，接近美国上限，并且相对于非RL比较器实现了较高的计算效率。

Keywords :