# 量化前沿速递：机器学习\[20260719\]

shameless 量化前沿速递 2026-07-20 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489622&idx=4&sn=2195c6aaf8840e94daf0ec853fa016fa&chksm=c36e43ed6e56e0994751d1386350c31f96bae486d33eea07ed484e689e95d96bfa5b3b3ac4f1#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489622&idx=4&sn=2195c6aaf8840e94daf0ec853fa016fa&chksm=c36e43ed6e56e0994751d1386350c31f96bae486d33eea07ed484e689e95d96bfa5b3b3ac4f1#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] When Does Order Flow Matter  State Dependent L2 Liquidity State Transitions in Crypto Futures

加密期货中订单流何时影响状态依赖的L2流动性状态转换

来源:ARXIV\_20260713

\[2\] Deep Learning for Dynamic Programming with Recursive Utility Using First order Conditions

基于一阶条件的递归效用动态规划深度学习

来源:ARXIV\_20260713

\[3\] A novel robust mixed integer linear programming model for index tracking problem under no rebalancing

一种新的鲁棒混合整数线性规划模型，用于无再平衡下的指数跟踪问题

来源:ARXIV\_20260713

\[4\] Prices and Competition in Vertically Integrated Launch Markets

垂直整合发射市场的价格与竞争

来源:ARXIV\_20260714

\[5\] Reinforcement Learning for Execution under Dynamic Fees in a Closed Loop DEX Simulator

闭环DEX模拟器中动态费用下的执行强化学习

来源:ARXIV\_20260714

\[6\] Forecasting Inflation with Microdata

用微观数据预测通货膨胀

来源:ARXIV\_20260715

\[7\] Is Deep Hedging Reinforcement Learning 

深度对冲强化学习

来源:ARXIV\_20260716

\[8\] Equilibrium stability as a driver of cooperation among Q learners

平衡稳定性是Q学习者合作的驱动力

来源:ARXIV\_20260716

\[9\] Indirect Variational Inference

间接变分推理

来源:ARXIV\_20260717

\[10\] SciPhy Reinforcement Learning for Portfolio Optimization

SciPhy强化学习在投资组合优化中的应用

来源:ARXIV\_20260717

\[11\] A Noise Robust Elicit to Optimize Framework for Distortion Riskmetrics via Inverse Reinforcement Learning

通过反向强化学习优化失真风险度量框架的噪声鲁棒诱导

来源:ARXIV\_20260717

### 

\[1\] When Does Order Flow Matter  State Dependent L2 Liquidity State Transitions in Crypto Futures

标题:加密期货中订单流何时影响状态依赖的L2流动性状态转换

作者:Joohyoung Jeon

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09230

Abstract : Building event conditioned market models requires separating macro event labels from persistent microstructure state. We study this distinction in Binance BTCUSDT and ETHUSDT futures from 2023 2026, combining top 20 L2 order book data, trade flow records, and macro event windows. We define a supervised discrete L2 liquidity state transition task, distinct from latent regime detection and price direction prediction, and evaluate models in rolling monthly out of sample folds with event clustered validation and blocked permutation tests, admitting each feature layer only if it improves on the layer below it on the same panel. Within these event windows, the first order predictive signal is the pre event L2 liquidity state  a coarse pre event state baseline strongly predicts post event liquidity regimes, interpretable logit models over continuous L2 features fail to improve on it, and a shallow nonlinear L2 model adds a robust further gain of comparable size to the state baseline s own. The macro event calendar enters only by locating the windows and supplying matched non event controls  we use event timing but not the event s label content, so pre event state competes against an uninformed within window baseline, not against the event type. Order flow adds further value only when layered on top of the L2 state model, not as a replacement. This value is not robustly cross symbol  for ETH it is present across calm, mixed, and stressed regimes and largest under stressed pre event liquidity, whereas BTC shows only isolated five minute passes and no regime that clears at both horizons. These findings motivate a state first design principle for market microstructure models. We provide a liquidity state transition baseline and evaluation protocol that reinforcement learning, execution policy, or LLM based context layers should exceed before their added value is credited.

Keywords : 

Abstract :构建事件条件市场模型需要将宏观事件标签与持久的微观结构状态分开。我们结合前20位L2订单簿数据、交易流记录和宏观事件窗口，研究了2023年至2026年币安BTCUSDT和ETHUSDT期货的这种区别。我们定义了一个有监督的离散L2流动性状态转换任务，有别于潜在的制度检测和价格方向预测，并通过事件聚类验证和阻塞置换测试对月度样本外折叠中的模型进行评估，只有当每个特征层在同一面板上的下一层有所改善时，才承认每个特征层。在这些事件窗口内，一阶预测信号是事件前的L2流动性状态，粗略的事件前状态基线强烈预测了事件后的流动性状况，连续L2特征上的可解释logit模型未能对其进行改进，浅层非线性L2模型增加了与状态基线本身相当大小的鲁棒增益。宏事件日历仅通过定位窗口并提供匹配的非事件控件来进入，我们使用事件计时，但不使用事件的标签内容，因此事件前状态与窗口内的未知基线竞争，而不是与事件类型竞争。订单流只有在L2状态模型之上分层时才能增加更多价值，而不是作为替代品。该值不是ETH的稳健交叉符号，它存在于平静、混合和压力的制度中，以及最大的压力不足的事件前流动性中，而BTC只显示了孤立的五分钟通行证，没有在两个层面都清算的制度。这些发现激发了市场微观结构模型的国家优先设计原则。我们提供了一个流动性状态转换基线和评估协议，强化学习、执行策略或基于LLM的上下文层在计入其附加值之前应超过该基线和协议。

Keywords :

### 

\[2\] Deep Learning for Dynamic Programming with Recursive Utility Using First order Conditions

标题:基于一阶条件的递归效用动态规划深度学习

作者:Xianhua Peng, Wu Guo, Songyan Wang, Jianfei Zhu

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09461

Abstract : This paper proposes the certainty equivalent first order learning (CEFOL) algorithm, a deep learning algorithm for solving discrete time dynamic programming problems with recursive utility. Dynamic programming with recursive utility is challenging because nonlinear certainty equivalent appears in the Bellman equation and the first order optimality conditions but is difficult to evaluate. By introducing a separate neural network to represent the certainty equivalent, CEFOL enables the exploitation of the Bellman and model specific first order optimality conditions. In addition to certainty equivalent, CEFOL also uses neural networks to learn the value functions, policy functions, and Lagrange multipliers by using model specific first order conditions to construct residuals for minimization. By using first order and KKT residuals to learn the policy, CEFOL directly accommodates general equality and inequality constraints on the controls, including occasionally binding constraints, without requiring penalty functions or problem specific reformulations. We apply the algorithm to risk sensitive and Epstein  Zin consumption saving problems, a small noise robust control problem, and a DSGE model with recursive preferences and stochastic volatility. Across these applications, out of sample Bellman diagnostics and model specific optimality residuals, including Euler or first order residuals where applicable, are generally of order 1.0e 4 to 1.0e 3 over the relevant state regions, with larger values mainly near binding constraints, and the learned value and policy functions closely match VFI benchmarks when available. The CEFOL algorithm also works for dynamic programming problems with expected utility, as expected utility is a special case of recursive utility.

Keywords : 

Abstract :本文提出了确定性等价一阶学习（CEFOL）算法，这是一种用于解决具有递归效用的离散时间动态规划问题的深度学习算法。具有递归效用的动态规划具有挑战性，因为非线性确定性等价出现在Bellman方程和一阶最优性条件中，但很难评估。通过引入一个单独的神经网络来表示确定性等价物，CEFOL能够利用Bellman和模型特定的一阶最优性条件。除了确定性等价外，CEFOL还使用神经网络来学习值函数、策略函数和拉格朗日乘数，通过使用特定于模型的一阶条件来构建残差以最小化。通过使用一阶和KKT残差来学习策略，CEFOL直接适应控制上的一般等式和不等式约束，包括偶尔的约束，而不需要惩罚函数或针对特定问题的重新表述。我们将该算法应用于风险敏感和Epstein-Zin消费节约问题、小噪声鲁棒控制问题以及具有递归偏好和随机波动性的DSGE模型。在这些应用中，样本外Bellman诊断和特定于模型的最优性残差，包括欧拉或一阶残差（如适用），在相关状态区域上通常为1.0e 4至1.0e 3阶，较大的值主要在约束附近，学习值和策略函数在可用时与VFI基准非常匹配。CEFOL算法也适用于具有期望效用的动态规划问题，因为期望效用是递归效用的特例。

Keywords :

### 

\[3\] A novel robust mixed integer linear programming model for index tracking problem under no rebalancing

标题:一种新的鲁棒混合整数线性规划模型，用于无再平衡下的指数跟踪问题

作者:Danial Ramezani, Mostafa Abouei Ardakan, Mohamadreza Dehghani Ahmadabad

来源:ARXIV\_20260713

链接:https://arxiv.org/pdf/2607.09556

Abstract : Passive management has increasingly won popularity over the past few years because of its advantages, such as lower management fees and transaction costs. Index tracking endeavors to reproduce the performance of an index with smaller sets of assets. In this paper, a novel formulation is proposed that is not only more robust than the existing ones but also performs better on out of sample data and tracks indices over long periods without any considerable deviation or the need for rebalancing. Solving index tracking problems in a polynomial time is a challenging task due to their NP hard nature. To address this issue, a novel heuristic based on metaheuristic algorithms and local branching is also developed to solve the proposed model. The heuristic enjoys not only the exploration capabilities of a genetic algorithm but the characteristics of local search algorithms as well. The data from the OR library is used to verify the capabilities of the proposed heuristic in comparison with commercial solvers. Results indicate that not only is the heuristic able to converge to optimal solutions for not so large problem sizes, but the portfolios it generates also outperform those yielded by commercial solvers in terms of both in sample and out of sample data.

Keywords : 

Abstract :被动管理因其较低的管理费用和交易成本等优势，在过去几年中越来越受欢迎。指数跟踪试图用较小的资产集再现指数的表现。本文提出了一种新的公式，该公式不仅比现有公式更稳健，而且在样本外数据和长期跟踪指数方面表现更好，没有任何明显的偏差或重新平衡的需要。由于索引跟踪问题具有NP难性质，因此在多项式时间内解决索引跟踪问题是一项具有挑战性的任务。为了解决这个问题，还开发了一种基于元启发式算法和局部分支的新启发式方法来解决所提出的模型。启发式算法不仅具有遗传算法的探索能力，还具有局部搜索算法的特点。OR库中的数据用于验证所提出的启发式算法与商业求解器相比的能力。结果表明，启发式算法不仅能够收敛到不那么大的问题规模的最优解，而且它生成的投资组合在样本内和样本外数据方面也优于商业求解器。

Keywords :

### 

\[4\] Prices and Competition in Vertically Integrated Launch Markets

标题:垂直整合发射市场的价格与竞争

作者:Akhil Rao

来源:ARXIV\_20260714

链接:https://arxiv.org/pdf/2607.10385

Abstract : Over the last 15 years the number of U.S. orbital launches has grown by roughly an order of magnitude. About three quarters of those launches were on SpaceX s Falcon 9 vehicle, and roughly three fifths of those Falcon launches deployed SpaceX s own Starlink constellation. A back of envelope Wright s law calculation suggests this increase in experience should have driven the Falcon 9 s real launch cost down by roughly 70   over 2012  2026. Yet over the same period the advertised price fell by less than 6   in real terms. Why  I develop a simple model of competition and vertical integration between launchers and constellations. The launch market is Bertrand  the constellation services market is Cournot  one launcher is integrated with its captive constellation. Three results follow. First, the removal of double marginalization raises the captive constellation s equilibrium size. If the integrated launcher obtains cost reductions from this experience, they are captured as capacity rent rather than passed through to external buyers. Second, the integrated launcher prices launches to be indifferent between serving internal and external demand, leaving more residual demand for a competing launcher to monopolize and pushing the equilibrium launch price up. Third, the same capacity rent that holds the equilibrium launch price up can attract entry to the launch segment, while the expansion of the captive constellation deters entry on the constellation side.

Keywords : 

Abstract :在过去的15年里，美国的轨道发射次数大约增长了一个数量级。这些发射中约有四分之三是在SpaceX的猎鹰9号运载火箭上进行的，其中约五分之三的猎鹰发射部署了SpaceX自己的星链星座。根据Wright定律的计算，经验的增加本应使猎鹰9号的实际发射成本比2012年至2026年下降约70。然而，同期广告价格实际下跌不到6。为什么我开发了一个简单的发射器和星座之间的竞争和垂直整合模型。发射市场是贝特朗星座服务市场是古诺一号发射器与其专属星座集成。以下是三个结果。首先，消除双重边缘化提高了圈养星座的均衡规模。如果集成发射器从这一经验中获得了成本降低，它们将被视为容量租金，而不是转嫁给外部买家。其次，集成发射器的发射价格在满足内部和外部需求之间漠不关心，导致更多的剩余需求被竞争发射器垄断，从而推高了均衡发射价格。第三，保持均衡发射价格上涨的相同容量租金可以吸引进入发射领域，而专属星座的扩张则阻碍了星座方面的进入。

Keywords :

### 

\[5\] Reinforcement Learning for Execution under Dynamic Fees in a Closed Loop DEX Simulator

标题:闭环DEX模拟器中动态费用下的执行强化学习

作者:Wen-Ting Wang

来源:ARXIV\_20260714

链接:https://arxiv.org/pdf/2607.10960

Abstract : Trader facing dynamic fees are increasingly proposed for automated market makers (AMMs), but historical data do not identify how order flow would respond  trader facing fees do not vary, trader types are latent, and a replayed tape is not a sequential decision environment. We therefore construct a minimal closed loop simulator in which the missing signal exists by construction  two constant product pools repriced by an equilibrium inspired dynamic fee rule, fee sensitive noise flow, and closed form CEX  AMM arbitrage. Equilibrium is used as a closure principle, not as an object the trader learns. Against a tuned benchmark ladder of schedule, planning, lookahead, and tabular policies, a small DQN is the only evaluated valid policy whose paired improvement over tuned one step routing excludes zero. On a reserved final block of 1 , 000 seeds with completion forced to 1.0 for every policy, it reduces implementation shortfall under every tested intra step ordering, by  13.3 bps  of order notional under the pre specified agent last ordering, and the edge is concentrated in, and learned from, dynamic fee environments  under constant fees the paired difference is indistinguishable from zero. The result is model conditioned counterfactual evidence about execution control in AMMs, not evidence about historical traders, equilibrium play, or deployable profit.

Keywords : 

Abstract :自动做市商（AMM）越来越多地提出面临动态费用的交易者，但历史数据无法确定订单流将如何响应。交易者面临的费用没有变化，交易者类型是潜在的，重放的磁带不是连续的决策环境。因此，我们构建了一个最小闭环模拟器，其中缺失信号的存在是通过构建两个常数产品池来实现的，这两个产品池由均衡激励的动态费用规则、费用敏感的噪声流和闭式CEX AMM套利重新定价。均衡被用作闭合原理，而不是交易者学习的对象。与经过调优的进度、计划、前瞻和表格策略的基准阶梯相比，一个小的DQN是唯一经过评估的有效策略，其成对改进超过了经过调优的一步路由，排除了零。在保留的1000个种子的最后一个块上，每个策略的完成度强制为1.0，它在每个测试的步骤内排序下减少了实施不足，在预先指定的代理最后一个排序下，减少了13.3个基点的订单概念，并且边缘集中在恒定费用下的动态费用环境中并从中学习，配对差异与零无法区分。结果是关于AMM中执行控制的模型条件反事实证据，而不是关于历史交易者、均衡策略或可部署利润的证据。

Keywords :

### 

\[6\] Forecasting Inflation with Microdata

标题:用微观数据预测通货膨胀

作者:Catherine Chen, Chen Gao, Jonathon Hazell, Lihua Lei, Chen Lian

来源:ARXIV\_20260715

链接:https://arxiv.org/pdf/2607.12345

Abstract : Does microeconomic heterogeneity help to forecast aggregate inflation in a non stationary environment  We develop a scan test for whether one forecast outperforms another, over an interval with unknown starting point and duration. To exploit any occasional forecasting power that the scan test detects, we design an adaptive machine learning pipeline. We encode the distribution of price changes into a high dimensional vector, which we combine with a gradient boosted trees algorithm. We then combine this micro forecast with other benchmark forecasts, using an adaptive algorithm that makes use of the micro forecast only when it performs well. We apply the pipeline to UK microdata, with four main results. First, the micro forecast outperforms a univariate benchmark, but only in the volatile period after 2020. Second, the scan test detects periods of micro outperformance, so the micro forecast enters the combined forecast. Third, the combined forecast performs comparably to the univariate benchmark before 2020 and better at every horizon after 2020. Fourth, the value of microdata for the combined forecast materializes after 2020. We conclude that microdata are valuable for forecasting aggregate inflation, but only after large shocks.

Keywords : 

Abstract :微观经济异质性是否有助于在非平稳环境中预测总体通胀？我们开发了一种扫描测试，用于在起点和持续时间未知的区间内，判断一种预测是否优于另一种预测。为了利用扫描测试检测到的任何偶然的预测能力，我们设计了一个自适应机器学习管道。我们将价格变化的分布编码为高维向量，并将其与梯度增强树算法相结合。然后，我们将这种微观预测与其他基准预测相结合，使用一种自适应算法，该算法仅在微观预测表现良好时才使用它。我们将该管道应用于英国微观数据，得出了四个主要结果。首先，微观预测的表现优于单变量基准，但仅在2020年后的动荡时期。其次，扫描测试检测到微跑赢时段，因此微预测进入组合预测。第三，综合预测在2020年之前与单变量基准表现相当，在2020年之后的每个时期都更好。第四，综合预测的微观数据价值在2020年后实现。我们得出结论，微观数据对于预测总体通胀是有价值的，但只有在大冲击之后。

Keywords :

### 

\[7\] Is Deep Hedging Reinforcement Learning 

标题:深度对冲强化学习

作者:Frédéric Godin

来源:ARXIV\_20260716

链接:https://arxiv.org/pdf/2607.13353

Abstract : The deep hedging framework of Buehler et al. (2019) trains a neural network policy, via Monte Carlo simulation of price paths and stochastic gradient descent, to minimize a risk measure applied to the terminal hedging error. In a recent stream of papers, my coauthors and I have referred to this technique as reinforcement learning (RL), a characterization that referees on several submissions have challenged on two grounds, among others  first, that because feedback is generated only at the terminal date, with no intermediate reward signal, the method cannot constitute genuine RL  and second, that the absence of a value function, a Bellman equation, temporal difference (TD) learning, and an explicit exploration mechanism disqualifies the method from the RL category altogether, so that it should instead be labeled a neural network method for stochastic optimal control. I argue that both objections rest on an unduly narrow, TD centric reading of what constitutes RL. Once RL is understood, as it is in the standard references of the field, to include Monte Carlo policy gradient methods and direct (actor only) policy search as first class members, the deep hedging algorithm of Buehler et al. (2019) falls squarely within the RL umbrella.

Keywords : 

Abstract :Buehler等人（2019）的深度套期保值框架通过蒙特卡洛模拟价格路径和随机梯度下降来训练神经网络策略，以最小化应用于终端套期保值误差的风险度量。在最近的一系列论文中，我和我的合著者将这种技术称为强化学习（RL），这是几份提交材料的审稿人质疑的一种特征，理由有两个：第一，由于反馈仅在截止日期生成，没有中间奖励信号，该方法不能构成真正的强化学习；第二，由于缺乏值函数、贝尔曼方程、时间差分（TD）学习和显式探索机制，该方法完全不属于强化学习范畴，因此它应该被标记为随机最优控制的神经网络方法。我认为，这两种反对意见都基于对强化学习构成的过于狭隘的、以TD为中心的解读。一旦理解了强化学习，就像该领域的标准参考文献一样，将蒙特卡洛策略梯度方法和直接（仅限参与者）策略搜索作为一级成员，Buehler等人（2019）的深度对冲算法就完全属于强化学习的范畴。

Keywords :

### 

\[8\] Equilibrium stability as a driver of cooperation among Q learners

标题:平衡稳定性是Q学习者合作的驱动力

作者:Janusz M. Meylahn, Maximilian Sch fer

来源:ARXIV\_20260716

链接:https://arxiv.org/pdf/2607.13607

Abstract : Algorithmic collusion among pricing algorithms has raised concerns about sustained supra competitive prices and their implications for social welfare. Existing work has largely focused on the probability that reinforcement learning algorithms converge to cooperative strategies, typically under the assumption that exploration vanishes over time. Motivated by the observation that algorithms deployed in practice are likely to continue exploring in order to remain adaptive to changing environments, we study learning dynamics under constant exploration. In this setting, the relevant question is no longer whether an algorithm converges to a particular strategy profile, but rather what fraction of time the algorithms spend playing cooperative strategies. Even in the benchmark case of the repeated Prisoner s Dilemma with one period memory, this yields high dimensional stochastic learning dynamics, for which a complete analytic treatment is intractable. We show that cooperative strategies can be dominant in this time averaged sense and derive a boundary predicting when such dominance arises, based on the expected dynamics of the Q learning process. Extensive simulations show that this boundary is a strong predictor for non defection dominated behaviour under epsilon greedy Q learning.

Keywords : 

Abstract :定价算法之间的算法合谋引发了人们对持续超竞争价格及其对社会福利影响的担忧。现有的工作主要集中在强化学习算法收敛到合作策略的概率上，通常是在探索随着时间的推移而消失的假设下。观察到在实践中部署的算法可能会继续探索，以保持对不断变化的环境的适应性，我们研究了不断探索下的学习动态。在这种情况下，相关的问题不再是算法是否收敛到特定的策略配置文件，而是算法在玩合作策略上花费了多少时间。即使在具有一个周期记忆的重复囚徒困境的基准情况下，这也会产生高维随机学习动力学，对此难以进行完整的分析处理。我们证明，在这种时间平均意义上，合作策略可以占主导地位，并根据Q学习过程的预期动态，推导出这种主导地位何时出现的边界预测。广泛的模拟表明，该边界是ε贪婪Q学习下非缺陷主导行为的强预测因子。

Keywords :

### 

\[9\] Indirect Variational Inference

标题:间接变分推理

作者:Neele Balke, Stephane Bonhomme, Thibaut Lamadon

来源:ARXIV\_20260717

链接:https://arxiv.org/pdf/2607.15168

Abstract : Latent variable models are central to economics but often entail intractable integration. Variational inference (VI), widely used in machine learning, turns this integration into tractable, differentiable optimization by replacing the likelihood with a variational objective. However, guarantees of recovering the true parameters remain limited when the variational family is insufficiently flexible    a key obstacle to the adoption of VI in economics. We first evaluate VI in models of earnings dynamics and show that the choice of variational posterior is crucial. We then introduce indirect variational inference (IVI), which treats VI as an auxiliary model and corrects the bias induced by the variational approximation. IVI retains much of VI s tractability because it does not require computing the likelihood. We apply these methods to models allowing for nonlinear persistence, non Gaussian and serially correlated transitory shocks, and latent heterogeneity. Across simulated and empirical applications, flexible variational families combined with IVI deliver reliable estimates.

Keywords : 

Abstract :潜在变量模型是经济学的核心，但往往需要棘手的整合。变分推理（VI）广泛应用于机器学习，通过用变分目标替换似然性，将这种集成转化为可处理、可微的优化。然而，当变分族不够灵活时，恢复真实参数的保证仍然有限，这是经济学中采用VI的关键障碍。我们首先评估了盈余动力学模型中的VI，并表明变分后验的选择至关重要。然后，我们引入了间接变分推理（IVI），它将VI视为辅助模型，并校正了变分近似引起的偏差。IVI保留了VI的大部分可处理性，因为它不需要计算可能性。我们将这些方法应用于考虑非线性持续性、非高斯和连续相关瞬态冲击以及潜在异质性的模型。在模拟和实证应用中，灵活的变分族与IVI相结合可以提供可靠的估计。

Keywords :

### 

\[10\] SciPhy Reinforcement Learning for Portfolio Optimization

标题:SciPhy强化学习在投资组合优化中的应用

作者:Igor Halperin, Andrey Itkin

来源:ARXIV\_20260717

链接:https://arxiv.org/pdf/2607.15195

Abstract : This paper introduces a dynamic portfolio optimization framework for large institutional investors using Scientific Physics Informed Reinforcement Learning (SciPhyRL). Formulated in continuous time over an extended state space that includes explicit cumulative costs, the approach leverages offline historical data to learn optimal, distribution aware strategies. A core innovation reduces the optimization challenge to solving an HJB equation by projecting it onto observed trajectories as a pathwise Hamilton Jacobi equation. This is solved directly from data using PINN in a single offline sweep, eliminating the need for traditional value or policy iteration. To make the method effective at practical short horizons, the control variable is recast from a continuous trading rate to a discrete target holding. This ensures signal implied positions are reached immediately, while execution costs are evaluated against a microstructure grounded quadratic price impact model. Evaluated on a  14  asset ETF universe using an engineered oracle signal, the learned Gibbs policy yields substantial out of sample Sharpe ratio improvements over static and myopic baselines. The results demonstrate that the proposed framework successfully translates known signal quality into a robust, multi period, and cost aware allocation mechanism with strictly controlled volatility and turnover.

Keywords : 

Abstract :本文介绍了一种使用科学物理知情强化学习（SciPhyRL）为大型机构投资者提供的动态投资组合优化框架。该方法在包括显式累积成本的扩展状态空间内连续制定，利用离线历史数据来学习最优的分布感知策略。一项核心创新通过将HJB方程投影到观测到的轨迹上作为路径哈密顿-雅可比方程，减少了求解HJB方程的优化挑战。这可以在一次离线扫描中使用PINN直接从数据中解决，消除了对传统值或策略迭代的需要。为了使该方法在实际短期内有效，将控制变量从连续交易率重新设定为离散目标持有量。这确保了立即达到信号隐含头寸，同时根据基于微观结构的二次价格影响模型评估执行成本。通过使用工程预言信号对14种资产的ETF进行评估，学习到的Gibbs策略在静态和短视基线下产生了显著的样本外夏普比率改善。结果表明，所提出的框架成功地将已知的信号质量转化为具有严格控制波动性和周转率的鲁棒、多周期和成本意识的分配机制。

Keywords :

### 

\[11\] A Noise Robust Elicit to Optimize Framework for Distortion Riskmetrics via Inverse Reinforcement Learning

标题:通过反向强化学习优化失真风险度量框架的噪声鲁棒诱导

作者:Yang Liu, Yuhao Liu, Yunran Wei

来源:ARXIV\_20260717

链接:https://arxiv.org/pdf/2607.14373

Abstract : We propose a noise robust elicit to optimize framework that integrates inverse reinforcement learning (IRL) and reinforcement learning (RL) for eliciting agents  risk preferences and optimizing policies under a broad class of risk objectives characterized by distortion riskmetrics. On the elicitation side, we propose an adaptive Bayesian IRL method that infers agents  latent risk objectives from their noisy observed decisions, explicitly allowing agents to take stochastic and suboptimal actions. We establish the existence of a finite set of distinguishing questions that identifies the preferred distortion riskmetric within the candidate class and prove that the convergence rate of the algorithm is of order  O( exp( cm O( sqrt m log m )))  under general settings, where  c 0  is a constant and  m  denotes the number of algorithm iterations. On the optimization side, we develop a model free RL algorithm for optimizing policies under conditional distortion riskmetrics. By representing the objective as an integral of the conditional cost quantile function with respect to the distortion function, the method unifies distortion riskmetric objectives. We optimize diverse risk objectives by extending the Proximal Policy Optimization (PPO) algorithm with policy, value, and quantile neural networks, where the quantile network estimates the full conditional cost quantile function and enables numerical evaluation of general risk objectives. A comprehensive empirical study demonstrates the framework s elicitation accuracy and effectiveness in complex financial environments.

Keywords : 

Abstract :我们提出了一种噪声鲁棒的诱导优化框架，该框架集成了反向强化学习（IRL）和强化学习（RL），用于在以失真风险度量为特征的广泛风险目标下诱导代理风险偏好和优化策略。在启发方面，我们提出了一种自适应贝叶斯IRL方法，该方法从代理人的噪声观察决策中推断出潜在的风险目标，明确允许代理人采取随机和次优的行动。我们建立了一组有限的区分问题的存在性，这些问题识别了候选类中的首选失真风险度量，并证明了在一般设置下，算法的收敛速度为O阶（exp（cm O（sqrt m log m）），其中c 0是常数，m表示算法迭代次数。在优化方面，我们开发了一种无模型的RL算法，用于在条件失真风险度量下优化策略。通过将目标表示为条件成本分位数函数相对于失真函数的积分，该方法统一了失真风险度量目标。我们通过使用策略、值和分位数神经网络扩展Proximal Policy Optimization（PPO）算法来优化各种风险目标，其中分位数网络估计了完整的条件成本分位数函数，并能够对一般风险目标进行数值评估。一项全面的实证研究证明了该框架在复杂金融环境中的启发准确性和有效性。

Keywords :