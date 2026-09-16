# 量化前沿速递：机器学习\[20260823\]

shameless 量化前沿速递 2026-08-24 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489672&idx=4&sn=8d5929b5b17696c739c061966a2bbc2d&chksm=c37c11b2068d1ba80e298149bc173c09fa581902c2738d7deaf141993ff08b195a69a752ec56#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489672&idx=4&sn=8d5929b5b17696c739c061966a2bbc2d&chksm=c37c11b2068d1ba80e298149bc173c09fa581902c2738d7deaf141993ff08b195a69a752ec56#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Photonic Quantum Computing vs. Classical Solvers in Constrained Factor Portfolio Optimization

约束因子组合优化中光子量子计算与经典求解器的比较

来源:ARXIV\_20260817

\[2\] The Yeoman s Portfolio

约曼投资组合

来源:ARXIV\_20260818

\[3\] Biases Informed Job Search Guidance

偏见知情求职指导

来源:ARXIV\_20260818

\[4\] Self Supervised Auxiliary Task Discovery for Stable Reinforcement Learning in Stock Trading

股票交易中稳定强化学习的自我监督辅助任务发现

来源:ARXIV\_20260818

\[5\] Communicating Credit Risk with Large Language Models

用大型语言模型传达信用风险

来源:ARXIV\_20260819

\[6\] Tradable It  Signatures

可交易的It签名

来源:ARXIV\_20260820

\[7\] Multi Level Market Making with Reinforcement Learning

基于强化学习的多层次做市

来源:ARXIV\_20260820

\[8\] Accounting for intra household joint travel in agent based transport simulations

在基于代理的交通模拟中考虑家庭内部联合出行

来源:ARXIV\_20260820

\[9\] Europe s Climate Ambition Under Scrutiny

欧洲的气候雄心受到审查

来源:ARXIV\_20260820

\[10\] Concentrated Liquidity Provision

集中流动性准备金

来源:ARXIV\_20260821

### 

\[1\] Photonic Quantum Computing vs. Classical Solvers in Constrained Factor Portfolio Optimization

标题:约束因子组合优化中光子量子计算与经典求解器的比较

作者:Nirvik Sahoo, Chyng Wen Tee, Paul Robert Griffin

来源:ARXIV\_20260817

链接:https://arxiv.org/pdf/2608.14134

Abstract : The authors present a rigorous empirical evaluation of three distinct optimization paradigms for institutional factor portfolio construction  an entropy based photonic quantum annealer (Dirac 3, Quantum Computing Inc.), a commercial mixed integer programming solver (Gurobi), and a model free deep reinforcement learning agent (SAC). Evaluating these pipelines on the Jensen Kelly Pedersen 13 factor equity library across 164 months test window, we implement a full factorial penalty sweep comprising 48 hyperparameter configurations that govern return, volatility, and skewness trade offs. Our findings demonstrate that while photonic hardware can locate superior risk return topologies within a narrow operating range, classical mixed integer programming remains superior for risk constrained mandates requiring tight tail risk control and cross seed stability. Furthermore, we document structural failure modes in reinforcement learning factor allocators under unanchored higher moment shaping. We translate these empirical results into actionable, mandate specific guidelines for quantitative portfolio managers deploying advanced optimization engines.

Keywords : 

Abstract :作者对机构因子组合构建的三种不同优化范式——基于熵的光子量子退火器（Dirac 3，quantum Computing股份有限公司）、商业混合整数规划求解器（Gurobi）和无模型深度强化学习代理（SAC）——进行了严格的经验评估。在164个月的测试窗口内，我们在Jensen Kelly Pedersen 13因子股票库上评估了这些管道，实现了一个全因子惩罚扫描，包括48个超参数配置，用于控制回报、波动性和偏斜度的权衡。我们的研究结果表明，虽然光子硬件可以在狭窄的操作范围内定位优越的风险回报拓扑，但经典的混合整数规划对于需要严格尾部风险控制和交叉种子稳定性的风险约束任务仍然具有优越性。此外，我们还记录了在未锚定的高弯矩成形下，强化学习因子分配器的结构失效模式。我们将这些实证结果转化为可操作的、针对特定任务的指导方针，供部署高级优化引擎的量化投资组合经理使用。

Keywords :

### 

\[2\] The Yeoman s Portfolio

标题:约曼投资组合

作者:Remy Levin, Daniela Vidart

来源:ARXIV\_20260818

链接:https://arxiv.org/pdf/2608.15876

Abstract : We design a method for measuring the risk preferences of agents in the deep past. The method combines a structural model of crop choice as a portfolio allocation with machine learning prediction of expected crop returns, using historic agronomic and climate data. We estimate county level risk preferences for the United States and farmer level preferences in Kansas from 1889 to 1929. More risk averse farmers leveraged less, were less likely to purchase novel WWI Liberty Bonds, and were more likely to participate in local risk sharing institutions. We show that higher risk aversion predicts slower tractor adoption and farm mechanization during the 1920s.

Keywords : 

Abstract :我们设计了一种方法来衡量代理人在过去的风险偏好。该方法将作物选择的结构模型作为投资组合分配，与使用历史农艺和气候数据对预期作物回报的机器学习预测相结合。我们估计了1889年至1929年美国县级风险偏好和堪萨斯州农民级偏好。风险厌恶程度越高的农民杠杆率越低，购买新型一战自由债券的可能性越小，更有可能参与当地的风险分担机构。我们发现，在20世纪20年代，较高的风险规避预示着拖拉机采用和农业机械化的放缓。

Keywords :

### 

\[3\] Biases Informed Job Search Guidance

标题:偏见知情求职指导

作者:Bruno Crépon, Aurélien Frot, Christophe Gaillac

来源:ARXIV\_20260818

链接:https://arxiv.org/pdf/2608.16827

Abstract : Job seekers  expectations about reemployment are increasingly used to study job search, but what their biases reveal about underlying beliefs and preferences is ambiguous. We combine new survey data, structural modeling, and machine learning to uncover the informational content of these expectations and show how they can be used to improve the targeting of employment support. Using a new panel of French job seekers  subjective expectations linked to administrative records, we show that reemployment expectation biases are strongly associated with, and summarize, biases in beliefs about the two fundamentals of search, job offer arrival rates and the wage distribution. These underlying biases are heterogeneous but strongly positively correlated, so their effects on search compound. We then estimate a structural job search model with multiple sources of biased beliefs and show that correcting them helps pessimistic job seekers but can demotivate and hurt optimistic ones, providing a rationale for targeting. Finally, we develop a machine learning stratification that recovers policy relevant groups, with distinct patterns of biased beliefs and behaviors, from easily elicited reemployment expectations alone. This gives employment services a simple tool to target informational interventions.

Keywords : 

Abstract :求职者对再就业的期望越来越多地被用来研究求职，但他们的偏见所揭示的潜在信念和偏好是模糊的。我们结合新的调查数据、结构建模和机器学习来揭示这些期望的信息内容，并展示如何利用它们来提高就业支持的针对性。我们使用与行政记录相关的法国求职者主观期望的新小组，表明再就业期望偏差与对求职的两个基本要素——工作机会到达率和工资分配的信念偏差密切相关，并总结了这些偏见。这些潜在的偏见是异质的，但它们之间存在很强的正相关关系，因此它们对搜索复合物的影响也是如此。然后，我们估计了一个具有多种偏见来源的结构性求职模型，并表明纠正这些偏见有助于悲观的求职者，但会使乐观的求职者失去动力并受到伤害，为目标定位提供了理论基础。最后，我们开发了一个机器学习分层，仅从容易引发的再就业期望中恢复具有不同偏见信念和行为模式的政策相关群体。这为就业服务提供了一种针对信息干预的简单工具。

Keywords :

### 

\[4\] Self Supervised Auxiliary Task Discovery for Stable Reinforcement Learning in Stock Trading

标题:股票交易中稳定强化学习的自我监督辅助任务发现

作者:Arishi Orra, Himanshu Choudhary, Manoj Thakur

来源:ARXIV\_20260818

链接:https://arxiv.org/pdf/2608.15841

Abstract : Reinforcement learning has gained increasing attention as a data driven approach for stock trading. However, learning a policy that is both profitable and stable remains challenging due to non stationary market behaviour and noisy reward signals. Auxiliary tasks are often used to improve representation learning and stabilize training, yet they are usually designed manually and depend heavily on prior assumptions about targets and prediction horizons. Such fixed designs may not remain suitable across changing market regimes. In this work, we propose a self supervised framework that automatically discovers auxiliary tasks to support reinforcement learning for stock trading. The auxiliary tasks are formulated as General Value Functions so that their predictions enrich the learned state representation and assist policy optimization. The framework consists of two networks. The main network learns the trading policy along with the auxiliary predictions, while the secondary network generates the definitions of auxiliary tasks through learned cumulants and discount factors. These tasks are updated using a meta gradient mechanism that accounts for their long term impact on trading performance and improves training stability. We evaluate the proposed approach across four major equity indices  DJI, FTSE, Sensex, and TAIEX. The empirical results demonstrate that automatically discovered auxiliary tasks lead to more robust learning and improved trading performance compared to existing baselines.

Keywords : 

Abstract :强化学习作为一种数据驱动的股票交易方法越来越受到关注。然而，由于非平稳的市场行为和嘈杂的奖励信号，学习一项既有利可图又稳定的政策仍然具有挑战性。辅助任务通常用于改进表征学习和稳定训练，但它们通常是手动设计的，在很大程度上依赖于对目标和预测范围的预先假设。这种固定的设计可能不适合不断变化的市场制度。在这项工作中，我们提出了一种自我监督框架，可以自动发现辅助任务，以支持股票交易的强化学习。辅助任务被表述为通用值函数，以便它们的预测丰富学习状态表示并辅助策略优化。该框架由两个网络组成。主网络学习交易策略以及辅助预测，而辅助网络通过学习的累积量和折扣因子生成辅助任务的定义。这些任务使用元梯度机制进行更新，该机制考虑了它们对交易绩效的长期影响，并提高了训练稳定性。我们对大疆、富时、Sensex和TAIEX四大股指的拟议方法进行了评估。实证结果表明，与现有基线相比，自动发现的辅助任务可以带来更稳健的学习和更高的交易绩效。

Keywords :

### 

\[5\] Communicating Credit Risk with Large Language Models

标题:用大型语言模型传达信用风险

作者:Sahab Zandi, Noah Kostesku, Christophe Mues, María Óskarsdóttir, Cristián Bravo

来源:ARXIV\_20260819

链接:https://arxiv.org/pdf/2608.17715

Abstract : Credit decisioning is a high stakes task in which model outputs must be accurate and explainable to support compliant decisions. Although modern credit risk models such as eXtreme Gradient Boosting (XGBoost) and Graph Neural Networks (GNNs) improve predictive performance, their explanations are often too technical for stakeholders creating communication gaps that can shape approvals, denials, and fairness judgments. We examine whether Large Language Models (LLMs) can serve as explanation layers that translate post hoc explanation artefacts into stakeholder appropriate risk narratives. Using Freddie Mac single family loan level data, we develop three pipelines  standard tabular (XGBoost   SHAP), and two with alternative data, a pure network based (GNN   GNNExplainer), and a bimodal one (combining tabular and network data). We generate narratives with three LLM configurations  a small fine tuned LLM (Gemma 3 4B), a large fine tuned LLM (DeepSeek R1 70B), and a zero shot commercial LLM (Gemini 2.5). Explanation quality is evaluated through automated checks across all pipelines and a human study of bimodal explanations comparing credit risk professionals and non professionals on eight decision relevant dimensions. We have three main findings. First, the pipeline accounts for higher variance in evidence grounding scores than the language model, meaning that the binding constraint on explanation quality is the evidence representation, not the model used. Second, the explanation narratives reliably name the influential factors but are less reliable when stating the direction of influence, which may be consequential for adverse action communication. Finally, professionals apply stricter evidentiary standards than non professionals. We discuss implications for the governance of risk models, including deployment considerations and the value of domain aligned LLMs in regulated credit settings.

Keywords : 

Abstract :信用决策是一项高风险的任务，其中模型输出必须准确且可解释，以支持合规决策。尽管极限梯度提升（XGBoost）和图神经网络（GNN）等现代信用风险模型提高了预测性能，但它们的解释对于利益相关者来说往往过于技术化，从而造成了可能影响批准、拒绝和公平判断的沟通差距。我们研究了大型语言模型（LLM）是否可以作为解释层，将事后解释工件转化为利益相关者适当的风险叙述。使用房地美单户贷款水平数据，我们开发了三个管道标准表格（XGBoost SHAP），两个具有替代数据的管道，一个基于纯网络的管道（GNN-GNNExplainer）和一个双峰管道（结合表格和网络数据）。我们生成了三种LLM配置的叙述——小型微调LLM（Gemma 3 4B）、大型微调LLM）（DeepSeek R1 70B）和零拍商业LLM（双子星2.5）。解释质量是通过所有管道的自动检查和双峰解释的人体研究来评估的，该研究在八个与决策相关的维度上比较了信用风险专业人士和非专业人士。我们有三个主要发现。首先，与语言模型相比，管道在证据基础得分上的方差更高，这意味着对解释质量的约束是证据表示，而不是使用的模型。其次，解释性叙述可靠地命名了影响因素，但在陈述影响方向时不太可靠，这可能对不良行为沟通产生影响。最后，专业人员比非专业人员适用更严格的证据标准。我们讨论了风险模型治理的影响，包括部署考虑因素和受监管信贷环境中与领域一致的LLM的价值。

Keywords :

### 

\[6\] Tradable It  Signatures

标题:可交易的It签名

作者:Xin Guo, Binnan Wang, Ruixun Zhang

来源:ARXIV\_20260820

链接:https://arxiv.org/pdf/2608.18120

Abstract : We propose an interpretable machine learning framework for dynamic hedging using the It  signature transform, which turns asset price paths into a set of linear features that universally represent nonlinear functions on time series. We show that each discretized It  signature component can be perfectly replicated by a simple self financing strategy using only the underlying assets and cash, which turns It  signature components into tradable and transparent hedging bases. This allows nonlinear derivative payoffs to be approximated by linear combinations of signature terms and hedged through the corresponding combination of trading strategies. We further establish a new approximation result for the It  signature and derive theoretical bounds for both in sample and out of sample hedging errors. Our method is computationally efficient, easy to implement, and avoids the estimation of future conditional expectations, which makes it attractive for real world applications. In simulations, our method delivers strong sample efficiency at substantially lower computational cost than neural network benchmarks. In an empirical study of S &P 500 index options, it performs robustly across vanilla and path dependent contracts, with the signature kernel weighted version providing further gains by localizing estimation to similar historical market paths. Overall, the paper identifies the It  signature as a practical, transparent, and model agnostic implementation framework for dynamic hedging.

Keywords : 

Abstract :我们提出了一种可解释的机器学习框架，用于使用It签名变换进行动态套期保值，该框架将资产价格路径转化为一组线性特征，这些特征普遍表示时间序列上的非线性函数。我们证明，每个离散的It签名组件都可以通过一个简单的自筹资金策略完美地复制，该策略仅使用基础资产和现金，从而将It签名组件转化为可交易和透明的对冲基础。这使得非线性衍生品收益可以通过签名条款的线性组合来近似，并通过相应的交易策略组合进行对冲。我们进一步为It签名建立了一个新的近似结果，并推导出了样本内和样本外套期保值误差的理论界。我们的方法计算效率高，易于实现，避免了对未来条件期望的估计，这使得它对现实世界的应用具有吸引力。在模拟中，我们的方法以比神经网络基准低得多的计算成本提供了强大的样本效率。在标准普尔500指数期权的实证研究中，它在香草和路径依赖合约中表现稳健，签名核加权版本通过将估计本地化到类似的历史市场路径来提供进一步的收益。总体而言，本文将It签名确定为一种实用、透明、与模型无关的动态套期保值实现框架。

Keywords :

### 

\[7\] Multi Level Market Making with Reinforcement Learning

标题:基于强化学习的多层次做市

作者:Patrick Cheridito, Moritz Weiss

来源:ARXIV\_20260820

链接:https://arxiv.org/pdf/2608.18195

Abstract : We introduce a reinforcement learning framework for market making in a limit order book. Our algorithm aims to maximize trading revenue by dynamically submitting market and limit orders of varying sizes across multiple price levels while controlling inventory size. We use multivariate logistic normal distributions to model order allocations and employ a deep set encoder to aggregate features from variable length order sets into a fixed dimensional latent representation. Additionally, we incorporate potential based reward shaping to accelerate learning without altering the optimal policy. We illustrate the performance of the method in three simulated market environments consisting of noise traders who submit random trades, tactical traders who respond to instantaneous volume imbalance, and strategic traders who trade in the direction of an exponentially weighted volume imbalance signal.

Keywords : 

Abstract :我们在限价订单簿中引入了一个用于做市的强化学习框架。我们的算法旨在通过在多个价格水平上动态提交不同规模的市场和限价订单，同时控制库存规模，从而最大限度地提高交易收入。我们使用多元逻辑正态分布来模拟顺序分配，并使用深度集编码器将可变长度顺序集的特征聚合到固定维的潜在表示中。此外，我们结合了基于潜力的奖励塑造，以在不改变最佳策略的情况下加速学习。我们展示了该方法在三个模拟市场环境中的性能，这三个环境由提交随机交易的噪声交易者、对瞬时交易量不平衡做出反应的战术交易者和在指数加权交易量不均衡信号方向上进行交易的战略交易者组成。

Keywords :

### 

\[8\] Accounting for intra household joint travel in agent based transport simulations

标题:在基于代理的交通模拟中考虑家庭内部联合出行

作者:Javaudin Lucas, Araldo Andrea, Coulombel Nicolas

来源:ARXIV\_20260820

链接:https://arxiv.org/pdf/2608.18657

Abstract : Intra household joint home based tours   trips in which household members depart together, engage in shared activities, and return together   represent a significant share of daily travel, yet are systematically ignored in transport simulations. Conflating joint and solo tours within a single mode choice framework introduces bias in preference parameter estimates. This paper proposes a three step methodology to integrate joint tours in agent based transport models  a Random Forest classifier to identify joint tours, a Multinomial Logit model estimating mode choice specific to joint tours, and a Penalized Logistic Regression for driver passenger assignment. Applied to the Paris region using household travel survey data, the methodology successfully replicates observed joint tour shares and mode distributions in a synthetic population. The proposed framework enables more reliable evaluation of policies whose impacts differ between joint and solo travel, such as HOV lanes or family transit fare discounts.

Keywords : 

Abstract :家庭成员一起出发、参加共同活动和一起返回的家庭内部联合家庭旅行占日常旅行的很大一部分，但在交通模拟中却被系统地忽略了。在单一模式选择框架内合并联合和单独旅行会在偏好参数估计中引入偏差。本文提出了一种三步方法，将联合旅游整合到基于代理的运输模型中——随机森林分类器用于识别联合旅游，多项式逻辑模型用于估计联合旅游特有的模式选择，惩罚逻辑回归用于驾驶员-乘客分配。该方法使用家庭旅行调查数据应用于巴黎地区，成功地复制了合成人群中观察到的联合旅行份额和模式分布。拟议的框架能够更可靠地评估联合旅行和单独旅行之间影响不同的政策，如HOV车道或家庭交通票价折扣。

Keywords :

### 

\[9\] Europe s Climate Ambition Under Scrutiny

标题:欧洲的气候雄心受到审查

作者:Jacopo Ghirri, Carlos Rodriguez-Pardo, Lara Aleluia Reis, Massimo Tavoni

来源:ARXIV\_20260820

链接:https://arxiv.org/pdf/2608.18690

Abstract : The European Union has committed to reducing greenhouse gas emissions 55  below 1990 levels by 2030, but whether current trends are compatible with this ambition remains uncertain. We apply deep learning to high resolution socioeconomic and sectoral data across EU27 member states till 2023 to project sectoral CO  2  trajectories under current trends, extrapolating observed sectoral momentum without assuming changes in the pace or effectiveness of the policy environment beyond what is already reflected in historical data. We project that EU27 emissions will exceed the 2030 target by 35  (620 Mt CO  2  shortfall), with only a small minority of countries on trajectories consistent with the bloc s commitments. While the Power sector achieves target consistent reductions driven by the renewable transition, Mobility shows minimal progress and accounts for over a third of total emissions by 2030, reflecting a structural inertia across member states rather than geographically concentrated lag. Our findings indicate that substantial additional intervention is required to close Europe s ambition implementation gap, and call for establishing up to date energy information in Europe.

Keywords : 

Abstract :欧盟已承诺到2030年将温室气体排放量减少到1990年水平以下55倍，但目前的趋势是否与这一雄心壮志相一致仍不确定。我们将深度学习应用于2023年前欧盟27个成员国的高分辨率社会经济和部门数据，以预测当前趋势下的部门二氧化碳轨迹，推断观察到的部门势头，而不假设政策环境的速度或有效性发生了超出历史数据已经反映的变化。我们预计，欧盟27国的排放量将比2030年的目标多出35个国家（二氧化碳短缺6.2亿吨），只有少数国家的排放量符合欧盟的承诺。虽然电力部门在可再生能源转型的推动下实现了目标一致的减排，但移动性方面进展甚微，到2030年占总排放量的三分之一以上，这反映了成员国之间的结构性惯性，而不是地理上集中的滞后。我们的研究结果表明，需要大量的额外干预来缩小欧洲在实现目标方面的差距，并呼吁在欧洲建立最新的能源信息。

Keywords :

### 

\[10\] Concentrated Liquidity Provision

标题:集中流动性准备金

作者:Georgios Chionas, Charalampos Kleitsikas, Stefanos Leonardos, Leandro Sánchez-Betancourt, Carmine Ventre

来源:ARXIV\_20260821

链接:https://arxiv.org/pdf/2608.19389

Abstract : Automated market makers (AMMs) are a cornerstone of decentralised finance (DeFi). Constant product markets with concentrated liquidity, such as UniswapV3, are now a well established design. In these markets, liquidity providers (LPs) face a sequential decision problem  they must decide when to rebalance their positions and which price ranges to allocate capital to as market conditions evolve. We formulate dynamic liquidity provision as a stochastic impulse control problem and use reinforcement learning (RL) to solve it, focusing on providing interpretable solutions. We show that learned policies exhibit rich state dependent behaviour, allocating liquidity according to mispricing, rebalancing costs, uncertainty, inventory exposure, and heterogeneous risk preferences. These behaviours help compress the left tail of the Profit and Loss (PnL) distribution and avoid catastrophic outcomes under high uncertainty. Finally, we benchmark the RL agents against baseline and sophisticated agents from the AMM microstructure literature and analyse their performance.

Keywords : 

Abstract :自动化做市商（AMM）是去中心化金融（DeFi）的基石。具有集中流动性的固定产品市场，如UniswapV3，现在是一个成熟的设计。在这些市场中，流动性提供者（LP）面临着一个连续决策问题，他们必须决定何时重新平衡其头寸，以及随着市场状况的变化将资本分配到哪个价格区间。我们将动态流动性供应表述为随机脉冲控制问题，并使用强化学习（RL）来解决它，重点是提供可解释的解决方案。我们发现，学习政策表现出丰富的状态依赖行为，根据错误定价、再平衡成本、不确定性、库存敞口和异质性风险偏好分配流动性。这些行为有助于压缩损益（PnL）分布的左尾，避免在高度不确定性下出现灾难性结果。最后，我们将RL试剂与AMM微观结构文献中的基线和复杂试剂进行基准测试，并分析它们的性能。

Keywords :