# 基于深度强化学习动态优化投资组合

QuantML QuantML 2024-12-29 18:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488572&idx=1&sn=ecf0fd2701188f48cb42e9bfb731b573&chksm=cf7515e1cca92de8098d4357c1f298487bad64f2c5d5c0f456f8f1d6139c61fa867932cfe893#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488572&idx=1&sn=ecf0fd2701188f48cb42e9bfb731b573&chksm=cf7515e1cca92de8098d4357c1f298487bad64f2c5d5c0f456f8f1d6139c61fa867932cfe893#rd)

## 

![](assets/001.png)

1 引言

近年来，人工智能（AI）在技术领域取得了显著进步，特别是在自然语言处理方面。OpenAI开发的ChatGPT凭借其卓越的语言理解和生成能力，引发了关于AI潜力的广泛讨论。该系统的成功主要归功于“基于人类反馈的强化学习”（RLHF），这一创新方法通过将人类反馈整合到强化学习过程中，显著提升了AI系统的性能和一致性。RLHF的技术基础是深度强化学习（DRL），这是一种高级机器学习范式，结合了深度学习和强化学习的方法。尽管DRL在自然语言处理领域展现了显著效果，并在游戏AI和机器人控制等领域展现出巨大潜力，但其在金融领域的应用仍主要处于探索阶段，特别是在复杂的投资组合优化领域。

投资组合优化是金融领域的一个基本挑战，专注于根据投资决策系统地分配资金于多种资产，通过动态调整投资组合资产权重来实现。传统的投资组合优化方法起源于现代投资组合理论，并通过后续改进对领域发展做出了重要贡献。然而，这些方法存在固有局限性，包括对资产回报分布的严格假设、主观效用函数的选择以及在动态市场条件下适应性的不足。

本研究探讨了深度强化学习在投资组合优化中的实施潜力，通过开发新的奖励函数和深度神经网络架构，旨在构建一个智能模型以实现有效的动态资产配置。该研究通过引入创新的投资组合优化方法，在理论和实践上都做出了贡献，同时为人工智能在金融领域的应用开辟了新的方向。

## 2 文献综述

Markowitz建立了现代投资组合理论，开创了定量分析方法在投资组合优化中的应用。Samuelson认为Markowitz的模型适用于单期投资问题，但不足以解决多期资产配置问题，因此提出了一种用于分析财富规划问题的效用函数。随后的研究者，包括Kelly、Merton以及行为金融领域的众多学者，扩展了效用函数在资产配置优化中的应用。然而，基于效用函数的优化方法存在固有局限性，特别是在函数选择的主观性和所选函数普遍适用性的未经验证方面。

Black-Litterman（BL）模型代表了另一种包含主观元素的方法，提出市场具有隐含的均衡回报，其中均衡配置下的资产回报作为先验回报。在该模型中，预期回报是先验回报和投资者主观预期的加权平均值。然而，在建立投资者主观预期的置信水平方面存在显著的主观性，导致没有统一的标准来衡量投资组合资产的均衡回报率。

除了传统的金融计量分析方法，运筹学家Charnes等人引入了数据包络分析（DEA），这是一个非参数分析框架，用于资产配置优化。随后，Kirkpatrick将模拟退火算法整合到投资组合优化中，基于自然科学原理。Arnone等人则使用遗传算法进行投资组合选择，以最小化投资风险。然而，这些模型普遍将投资组合权重调整过程视为静态的，忽略了时间维度，未能纳入资产配置如何随着交易活动的顺序性而演变。

此外，包括Markowitz框架在内的经典资产配置模型，通过将同期资产权重与预期回报相乘来计算投资组合回报，表示为R = ΣCi-1 Wifi，其中R代表投资组合回报，i表示资产数量，Wi表示资产权重，Yi代表相应的预期回报。然而，在现实的动态交易环境中，投资组合的最终回报应通过将前一时期的资产权重与后一时期的资产回报相乘来计算，表示为Rt = ΣWi,t-1 @it-1，其中Yi,t代表资产i在时期t的已实现回报（而非预期回报），Wi,t-1代表投资组合在时期t-1的资产权重配置。这一根本区别可能导致显著差异——交易过程中的建模错误不可避免地会损害这些模型的实际效果。值得注意的是，许多在金融领域广泛实施的优化模型，包括条件风险价值模型、风险平价模型和分层风险平价模型，完全忽视了资产权重的时序演变。因此，传统的金融计量分析方法以及DEA、模拟退火算法和遗传算法等复杂方法，都无法充分捕捉交易过程中投资组合权重调整的动态特性，从而无法实现最优资产配置策略。

深度强化学习（DRL）代表了一种动态建模范式。DRL中的“深度”一词源自其对深度神经网络的整合，这些网络取代了早期强化学习（RL）中使用的传统人工神经网络，包括全连接和递归神经网络。这种架构改进极大地提高了RL的目标函数逼近能力。RL在资产管理中的早期应用主要采用策略梯度（PG）和Q学习算法。Moody引入了一种使用PG算法的单一资产管理模型，随后的衍生模型主要集中在单一风险资产管理或固定投资决策框架上，如Dempster等人的自动化外汇交易模型和Zhang等人的资产管理框架。同时，Ralph Neuneier、Gao等人和Lee等人实施了Q学习算法进行资产管理，尽管这些模型仍局限于单一资产管理。此外，Wu等人、Liu等人、Pourahmadi等人和Kochliaridis等人等学者对DRL在单一资产交易中的应用研究做出了重要贡献。然而，一些学者在应用DRL优化资产配置时忽略了深度神经网络的设计，如Wang等人，而另一些学者则忽略了资产权重的分配，忽略了资产权重之和为1的基本约束条件，如Jiang等人。

近年来，计算能力和动态优化理论的进步推动了DRL在投资组合资产管理研究中的广泛应用。Jiang等人提出了一种用于加密货币市场资产优化的DRL投资组合管理模型。该模型整合了Ormos等人定义的相对价格向量和交易成本。然而，Ormos等人在其论文中对资产的动态变化解释错误，导致交易成本推导错误。由于采用了相同的推导方法，Jiang等人的交易成本率推导也表现出类似的数学不一致性。尽管Jiang等人随后通过近似方法提供了正确的实现公式，但该模型在其他资本市场中的有效性需要进一步验证。

在卖空限制（仅多头头寸）下，当前DRL投资组合权重优化模型的奖励函数主要由投资组合回报组成。然而，使用这种奖励函数的DRL模型在中国股票市场表现不佳，导致Qi Yue等人人为设定固定投资权重以实现满意的回测结果。然而，这种方法与使用DRL模型进行自动资产权重优化的初衷相矛盾。在DRL投资组合应用领域，研究人员已经证明，实施奖励函数以增强DRL的资产优化性能是一种有效的方法。多位学者开发了新的奖励函数以提高DRL的投资组合优化性能：Wu等人研究了使用自定义夏普比率奖励函数（年回报率/年化回报标准差）的台湾股票市场投资组合。然而，他们的研究没有具体说明所实施的底层RL算法。Almahdi等人将Calmar比率作为奖励函数的优化目标，将其与递归强化学习（RRL）整合，这是一种PG算法的衍生算法，用于优化美国股票和新兴市场资产。Aboussalah等人开发了一种与RRL衍生算法兼容的夏普比率奖励函数，尽管这种奖励函数与PG算法的夏普比率奖励函数基本相同。此外，Lim等人采用基于投资组合净资产值的奖励函数，开发了一种基于RL的动态投资组合再平衡策略，以优化不同市场条件下的投资表现。综合现有文献可以发现，目前尚无研究建立专门针对Actor-Critic算法特性的夏普比率奖励函数。

本文基于人工智能原理实施DRL方法，以优化投资组合资产权重，有效消除了模型实施中的主观偏差，同时全面解决了现实交易环境中资产权重变化的动态特性。本研究提出了两种主要创新：

首先，我们引入了一种专门为Actor-Critic DRL算法特性设计的夏普比率奖励函数。尽管Moody和Gao在RL资产管理应用方面的开创性研究使用了夏普比率作为奖励函数，但他们的设计仅限于PG算法和Q学习算法的简单结构。同样，Aboussalah等人开发的夏普比率奖励函数也没有充分解决Actor-Critic算法的特定需求。我们提出的奖励函数结合了Actor-Critic系统的架构特性，实施步长归一化以增强模型稳定性，并优化投资组合动态优化过程的指导。

其次，本研究开发了一种专门用于金融时间序列数据分析的深度神经网络架构。该网络架构结合了计算机视觉中VGG网络的基本设计原则，建立了一个针对处理三维结构化时间序列数据的框架。通过将随机采样策略与该网络架构整合，该模型在训练阶段系统地从数据集中选择连续的交易数据。这种方法增强了模型的泛化能力，同时减轻了过拟合风险。这两种技术方法的协同整合显著提高了模型处理金融时间序列数据的能力，为实现有效的动态投资组合优化奠定了坚实的理论基础。

本研究实施多头头寸限制，并将提出的DRL模型应用于优化由CSI300成分股组成的投资组合。优化结果与多种计量经济优化模型进行了系统对比，以评估DRL模型在资产配置优化中的有效性。研究方法严格遵循DRL模型的建模框架，为未来的研究工作建立了全面的指导。本研究的意义跨越了理论和实践领域：它为学术界引入了新的投资组合优化方法，同时为投资组合管理从业者提供了有效的解决方案。该模型系统地整合了现实交易环境中资产权重变化的动态特性，展示了在实践应用中的显著性能提升潜力。

## 3 DRL模型配置

深度强化学习（DRL）是一种符合马尔可夫决策过程（MDP）框架的动态优化方法。投资组合交易过程可以概念化为一个MDP，从账户启动到交易完成的轨迹表示为T =(So, Ao, R1, S1, A1,R2, S2, A2,R3, ... )，构成一个事件。该框架使得DRL理论能够用于模拟交易过程。根据DRL建模框架，本研究定义投资组合交易者为代理，建立状态（环境）、行动和奖励规范，并实施带有深度神经网络的DRL算法以优化投资组合。

### 3.1 状态空间配置

在DRL中，状态空间构成代理交互的环境。根据有效市场假说，所有影响资产价值的信息都嵌入在资产价格中；因此，状态空间仅使用每日资产价格数据构建。本研究采用Jiang等人提出的三维状态空间配置来模拟DRL环境，基于两个基本考虑。首先，DRL在人工智能领域的突破是通过视频游戏应用实现的。视频游戏显示由三维数据结构组成，这些数据结构本质上是适合深度神经网络处理的。深度神经网络之前在图像识别领域取得了卓越的进展，在这一领域达到了与人类相当的性能。其次，传统的金融计量模型通常采用降维技术，如主成分分析（PCA），以减少分析复杂性。然而，这些方法经常导致宝贵信息的显著损失，且损失程度随着数据特征数量的增加而增加。相比之下，深度神经网络具有卓越的非线性函数逼近能力，能够有效分析复杂的特征相互关系，并解决传统金融计量模型的局限性。因此，本研究实施了一个三维时间数据结构用于状态空间，有效利用了深度神经网络的高级数据处理能力。

### 3.2 行动空间配置

该模型仅考虑多头头寸，不进行卖空。投资组合权重（即资产价值与总资产之比）代表模型的行动向量：

![](assets/002.png)

其中，Wo,t代表无风险资产的权重，在本研究中特指现金资产权重。在时间t，投资组合权重满足以下约束：

![](assets/003.png)

在多头头寸限制下，Wit ≥ 0。投资组合初始时仅包含现金资产，其初始权重向量为Wo = (1,0, ... ,0)T。

### 3.3 其他元素推导和奖励函数设置

向量Pt表示投资组合中资产在时期t的收盘价，Yt表示相对价格向量：

![](assets/004.png)

Ct表示整个投资组合在时期t的交易成本率。投资组合价格pt表示为：

![](assets/005.png)

投资组合的日对数回报率Yt定义为：

![](assets/006.png)

日对数回报率的平均值R和标准差Std (Yt)计算如下：

![](assets/007.png)

在公式（7）和（8）中，tn表示第n个交易期，Yt是从时期t的收盘价中得出的。在市场进入时，投资者仅持有现金资产。初始交易时间点定义为t=0，Yo =0，考虑到此时没有分配给风险资产，公式（5）和（6）表明Y1 = 0。因此，回报产生期从t=2开始。

奖励函数采用平均年化夏普比率：

![](assets/008.png)

Freq表示年交易天数，本文中设置为252。rf代表无风险利率，本文中设置为0。Steps表示训练事件中的步长，每个步长进行一次交易决策。模型训练目标包括最大化这个奖励函数。

Ct由以下公式确定：

![](assets/009.png)

It代表时期t每资产交易成本率，本研究中设置为ut = 0.0025，构成一个相当高的比率。W't是权重向量W't的一个组成部分，由以下公式给出：

![](assets/010.png)

其中 O 表示Hadamard积，. 表示内积。W'代表t-1期交易后到t期交易前的自主价格变动导致的权重值，如图2所示：

![](assets/011.png)

## 4 DRL算法选择和网络结构

### 4.1 平均夏普比率奖励函数设计用于Actor-Critic架构

在深度强化学习（DRL）中，算法作为战略框架，使代理能够探索环境并通过在行动空间中最佳行动选择和在状态空间中奖励获取来最大化奖励。DRL算法主要分为两类：在线策略和离线策略方法，每种方法在不同任务中表现出不同的性能特点。通过对多种算法结构的全面实验评估，我们确定离线策略算法需要更多的计算资源并且收敛速度更慢。鉴于硬件限制，我们选择了近端策略优化（PPO），一种在线策略算法。

PPO集成了多种性能优化技术，包括广义优势估计（GAE）和价值函数裁剪，本质上扩展了信任区域策略优化（TRPO），而TRPO本身增强了PG算法。PG算法实施基于事件的更新机制，与策略迭代并行，通过完整事件采样进行优化。PPO的Actor-Critic架构独特地结合了事件级更新和事件内的步级更新。原始的PPO论文通过简洁的伪代码利用两个嵌套的for循环优雅地呈现了算法：一个外层循环管理事件更新，一个内层循环执行步级更新。

利用Actor-Critic算法的独特更新机制，我们开发了一种创新的平均夏普比率奖励函数计算方法，优化了Actor-Critic框架，通过PPO实现。该方法初始化一个空的列表R，用于存储每个交易步的回报。在事件执行过程中，Actor网络生成投资组合权重w1，提示环境返回价格变化信息y1（相对价格向量）。这些参数结合交易成本c1，确定每个时间步的投资组合价值变化p1。价值变化转换为对数回报r1并追加到回报列表R中，使得在每个交易步使用累积回报计算夏普比率。详细的实现方法在定义1中概述。

PPO扩展了PG算法的事件更新机制，同时在事件内实施步级更新。为了优化训练期间代理的性能，我们将年化夏普比率归一化到事件更新中的步数（公式9），计算每个事件中每个时间点的代理的平均夏普比率。这种方法确保了不同事件长度和交易序列之间的回报可比性，大幅提高了模型训练稳定性。

![](assets/012.png)

该实现利用Stable-Baselines3（SB3）框架进行PPO部署，将创新的平均夏普比率奖励函数整合到环境状态中以优化投资组合。至关重要的是，环境状态保持与DRL算法独立，奖励函数实施位于环境中，而不修改SB3中核心PPO算法逻辑。实证结果表明，这种平均夏普比率奖励函数有效地利用了PPO（Actor-Critic）算法的特性，显著提高了样本外性能。

### 4.2 神经网络设计

早期的人工神经网络在开发数据驱动的理论模型时遇到了挑战，因为平衡函数逼近准确性和梯度稳定性，同时增加网络深度。深度神经网络的进步使得强化学习（RL）算法得以进步，促进了深度强化学习（DRL）的开发。深度神经网络架构是DRL中的一个关键组成部分，经验证据表明，高效的网络设计可以增强DRL性能。鉴于三维状态空间（即价格张量Xt），本研究实施用于图像处理的VGG架构，如图3所示：

![](assets/013.png)

在图3中，'in'指定输入通道数，而'out'定义输出通道数。网络架构包括5个卷积层，每个卷积层采用33卷积核进行特征提取，并辅以Max Pool层进行特征池化。在最后一个卷积层的最大池化后，Flatten操作将特征数据转换为一位向量，然后是两个全连接（fc）层执行线性处理，每个包含128个神经元。Actor网络以softmax激活函数结束，生成投资组合权重的行动向量，而Critic网络产生价值函数输出，没有激活函数。Actor网络的softmax输出结构适应11个资产（10个风险资产 + 1个无风险资产）。

## 5 实证测试

### 5.1 数据选择、预处理和假设

本研究构建了一个投资组合，使用从CSI300指数中随机选择的成分股进行实证分析。投资组合包括1个无风险资产（现金）和10个风险资产。数据来自Wind数据库的每日交易记录，所有价格均已前向调整。研究限制每只股票每天只进行一次交易。

本研究实施随机投资组合选择，与传统投资理论基于流动性、多样化和其他因素的选择策略不同。该方法基于一个前提：一个有效的DRL模型应该能够在各种投资组合中表现出适应性，而不仅仅是精心挑选的资产组合。随机选择投资组合的优越回测性能提供了DRL模型决策能力和泛化效果的实证验证。这种方法体现了DRL作为数据驱动模型的基本优势：自主适应市场环境，无需人工资产筛选程序。

对于资产选择，研究应用了一个单一的时间标准：资产必须在2012年12月31日之前上市。这一要求反映了DRL模型的数据驱动特性，这些模型需要大量的历史数据用于训练。延长的上市历史提供了全面的交易数据，使得市场特征学习更加完善。研究假设风险资产具有足够的流动性，交易执行即时，且交易活动对市场影响可以忽略不计。

### 5.2 性能指标、回测期和比较优化模型

根据Zhang等人，本研究采用包括年平均回报率E(R)、年波动率Std(R)、年夏普比率（Sharpe）、年Sortino比率（Sortino）、最大回撤（MDD）、Calmar比率（Calmar）、正回报百分比（%of+Ret）和平均收益-损失比率（Ave P/Ave L）的性能指标。

研究实施了一个六个月的回测期以评估模型优化有效性。鉴于每年有252个交易日，六个月包括128个交易日。为了解决过拟合问题，该方法采用了Wassname的开源github实现，从完整数据集中随机抽取128个连续的交易日作为每个训练事件的样本。六个月的回测期选择与该采样框架一致。

图4显示了训练和测试集。价格数据经过标准化，每只资产的收盘价除以最后交易日开盘价，使得具有不同价格水平的投资组合资产的趋势清晰可见。

![](assets/014.png)

回测期仅包括样本外数据，独立于训练数据集。代理（即投资者）在回测期间仅处理这些数据，没有预先暴露于未来的价格变动。表1列出了训练和回测数据的具体时间范围：

![](assets/015.png)

比较分析框架包括多个已建立的优化模型，与DRL模型进行基准比较。这些模型通过Riskfolio-lib资产优化包实施，所有比较模型均保持默认配置，资产回报率来自收盘价。优化框架包括：经典均值方差（MV）、条件风险价值（CVaR）、熵风险价值（EVaR）、风险平价（RP）、分层风险平价（HRP）、分层等风险贡献（HERC）和嵌套聚类优化（NCO）。虽然这些模型支持各种目标函数，包括风险最小化（MinRisk）、夏普比率最大化（Sharpe）、效用函数最大化（Utility）和净资产价值最大化（MaxRet），但比较分析仅关注风险最小化和夏普比率最大化，鉴于效用函数的主观性和效用和净资产价值最大化策略的实证表现不佳。

比较模型的历历史数据窗口选择遵循EVaR和HRP原始作者建立的方法框架，分别采用4年和1年时期。鉴于每年有252个交易日，4年时期包括1,008个交易日（252 \* 4）。鉴于这些定量优化模型将资产权重修改视为静态过程，忽略了连续交易中的权重动态，本研究实施滚动窗口方法进行权重预测。具体来说，2021年9月1日的权重预测使用前4年或1年的历史数据到2021年8月31日，这个过程在回测期间继续进行。权重调整产生的交易成本使用公式10计算，与DRL模型中建立交易成本参数保持一致。

### 5.3 训练结果和奖励收敛

深度强化学习（DRL）是一种新的顺序统计决策方法，它利用神经网络来建模和估计状态-行动空间中的条件概率分布和预期回报。在每个时间步，代理根据当前观察执行在线统计推断，同时通过系统探索和经验积累优化其决策策略，实施迭代统计学习过程，旨在最大化预期累积回报。这种方法整合了深度学习的函数逼近能力和强化学习的顺序决策框架，建立了一种端到端的统计建模和优化方法。通过代理-环境交互的奖励函数收敛是评估模型稳定性和鲁棒性的必要条件。

![](assets/016.png)

如图5所示，模型经过了900万步的训练。代理获得的回报与训练步数的进展呈正相关，表明训练过程和代理性能的系统改善。在整个训练期间，回报值显示出收敛，年化夏普比率稳定在-0.3到0.8之间，大部分训练回报值保持在零以上。这些结果表示，代理在已知环境中表现出稳定的回报生成能力，支持了训练模型的稳健性。

### 5.4 回测结果

### 5.4.1 投资组合价值、资产配置和交易成本

![](assets/017.png)

图6的上半部分显示了资产的相对价格（根据公式4计算）。相对价格可以视为一种标准化方法，将投资组合资产的股价调整到同一规模。下半部分分别显示投资组合的资产权重和交易成本。

在整个回测期间，DRL投资组合价值显示出持续上升的趋势，从初始值1.0增长到1.1256，总回报率为12.56%。两次显著上升出现在2023年11月中旬到12月和2024年1月下旬。尽管在2023年9月中旬经历了回撤，投资组合价值暂时下降到约0.98，但回撤幅度不大，随后强劲的恢复势头。

关于权重配置，DRL实施了一个稳健的资产配置策略。投资组合包括现金和10只股票，初始配置大致均匀分布，每只资产约为0.0909。在整个交易期间，DRL保持了稳定的权重调整模式，权重标准差稳定在0.031到0.033之间，表现出有效的多样化特性。现金头寸在0.11到0.12的狭窄范围内波动，确保了充足的投资组合流动性。在股票权重方面，CN002027.SZ和CN002371.SZ表现出相对活跃的权重调整，而CN600029.SH和CN600183.SH则保持了一贯较低的分配比例。

在整个回测期间，该策略表现出高效的交易成本管理。大量交易成本（约0.22%）仅在初始资本配置时发生，随后大多数交易日的交易成本率保持在0.002%到0.01%的最低水平。这种表现表明，在资产配置调整中实施了审慎的交易方法，有效减轻了交易成本对投资组合回报的影响。

基于PPO算法的投资组合表现出有利的风险回报特征，通过保持多样化动态权重调整产生正投资回报，同时有效管理下行风险。这些结果表明深度强化学习在投资组合管理中具有显著的应用潜力。

### 5.4.2 股票优化模型性能比较

表2显示了各种股票优化模型的性能比较。模型根据“模型类型-优化目标-数据窗口”的惯例命名，如下所示：

MV-MinRisk: 均值方差模型，以风险最小化为优化目标，采用1年历史数据滚动窗口。CVaR-Sharpe-4yr: 条件风险价值模型，以夏普比率最大化为优化目标，采用4年历史数据滚动窗口。其他模型也遵循这种命名惯例。

![](assets/018.png)

![](assets/019.png)

采用Ernest P. Chan\[43\]\]的方法，使用夏普比率作为主要指标，表2表明深度强化学习（DRL）模型在投资组合优化中具有显著优势。该模型实现了最高的年平均回报率19.56%，保持了适度的波动性（12.58%），并显著优于其他模型，夏普比率达到1.5550，显示出优越的风险调整回报。该模型获得了最高的Sortino比率（2.9567），验证了其在考虑下行风险时的卓越表现。在风险管理方面，DRL模型表现出仅为5.85%的最大回撤，接近最优水平，同时实现了最高的Calmar比率（3.3395），表明其具有优越的下行风险管理能力。

在传统优化模型中，CVaR-MinRisk-4yr表现最佳，实现了15.08%的年回报率和最低的最大回撤（5.38%）。该模型实现了1.2290的夏普比率，尽管低于DRL模型，但代表了传统模型中最高的。夏普比率的优越性能可能归因于其4年回溯期设计，使得历史数据分析更加稳定。值得注意的是，实施MinRisk策略的模型始终优于其夏普策略的对应物，表明在当前市场环境中，风险最小化策略比风险调整回报最大化策略更为有效。

值得注意的是，风险平价（RP）系列模型和分层等风险贡献（HERC）策略表现出次优性能。RP模型始终产生负回报和负夏普比率，而HERC模型记录最大负回报为-10.07%和最大回撤为11.86%，表明过度依赖历史相关性或简化风险分配方法可能不足以应对市场动态。

从交易效率角度来看，DRL模型实现了优越的性能，投资胜率为47.28%，最佳平均收益-损失比为1.4204，表明其在捕捉市场机会和减少损失方面都很擅长。综合来看，无论是通过主要夏普比率指标还是其他风险调整回报指标，DRL模型有效地整合了回报生成能力和风险管理效率，超越了传统方法，在所有维度上都表现出适应性和稳健性。这些发现验证了深度强化学习在金融领域的应用潜力，特别是在需要动态决策和多目标优化的投资组合管理中的应用。

![](assets/020.png)

为了便于定量比较，本研究考察了排名前11位的传统优化模型，通过年化夏普比率与DRL模型进行比较（如图7所示）。实证结果表明，在整个回测期间，DRL模型相对于传统优化模型表现出优越的性能，以下是主要发现：

i. 回报指标：DRL模型在整个回测期间始终优于传统优化模型，产生了显著的正回报。在传统优化框架中，CVaR-MinRisk-4yr、EVaR-MinRisk-4yr、NCO-MinRisk-4yr和MV-MinRisk-4yr的回报指标最高，但仍然低于DRL模型。

ii. 战略特征：传统优化模型表现出强烈的同质性，投资组合价值轨迹在优化后几乎遵循相同的模式。相比之下，DRL优化后的投资组合价值轨迹显示出与传统的优化方法不同的模式。这表明，数据驱动的DRL框架在捕捉资产价格动态方面表现出更高的能力，从而实现更有效的资产权重分配。

来自广泛实验研究的实证证据表明，DRL模型在CSI300成分股的投资组合优化中表现出显著的效果。这种性能可以归因于两个关键因素：首先，回测期与CSI300成分股的上行轨迹相吻合，为多头策略验证创造了有利条件；其次，CSI300成分股保持稳定的投资者构成，机构投资者占比较高，导致投资模式更加系统化。相对于中小型股，CSI300成分股的股价和交易数据更可靠地反映了市场基本面和投资者情绪，从而为DRL模型建立了更稳健的学习环境。这些结构特性使得DRL模型的学习和市场适应能力得到提升，从而在CSI300成分股投资组合优化中表现出更好的性能。

## 6 结论

在投资组合资产配置领域，传统的金融计量优化模型主要使用静态框架来管理资产权重变化。这种方法虽然便于理论分析和模型实施，但表现出明显的局限性，无法捕捉现实交易环境中观察到的资产权重持续动态演变。实证证据进一步表明，传统优化模型表现出同质性，其优化能力在适应市场波动方面显得不足。

作为新兴的研究方法，深度强化学习（DRL）在投资组合优化中的潜力尚未得到充分探索。DRL是一种数据驱动的动态优化框架，在模型实施过程中最大限度地减少了用户引起的主观偏差。该框架中嵌入的动态优化原则与实际交易过程高度一致，证明了其在投资组合资产配置优化中的特殊有效性。

本研究提出了一种专门为Actor-Critic DRL算法优化的新型平均夏普比率奖励函数。研究开发了一种专门用于处理三维金融数据的深度神经网络架构，并实施了随机采样方法进行模型训练。提出的奖励函数在多头投资策略中表现出优越的优化效果，在训练期间回报值主要分布在正域内，表现出稳健的收敛特性，并在样本外回测中实现了优越的夏普比率指标。与主流金融计量优化模型的实证比较表明，所提出的DRL框架在资产配置优化和风险管理能力方面具有显著优势。

  

论文及代码见星球

![](assets/021.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 还在使用MSE？试试这些更加适合金融预测的损失函数](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487997&idx=1&sn=e05e8e0dafa605615d425ff1f0702c4b&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 如何运行日内中高频模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰SAM：提升AI量化模型的泛化性能 研报复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487238&idx=1&sn=41cbb5b3bb3e5a277c9175ba64642259&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰AlphaNet模型复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学&华泰证券 在高胜率时交易](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485500&idx=1&sn=b29e1d2efe2482165245ab6add4af051&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)[QuantML-Qlib Model | 滚动模型训练](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
    研报复现：
    
      
    
-   [重磅更新！80+量化策略复现（持续更新中）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488528&idx=1&sn=f9c98f60baca2b690956ff6b56a2553f&scene=21#wechat_redirect)
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [研报复现 | QRS择时信号及改进](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-下](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486787&idx=1&sn=bfe98c0b8d331027191761df3b85ea8c&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-上](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486761&idx=1&sn=84a2de96dd3bc7a7fb38386684b3eec4&scene=21#wechat_redirect)
    
-   [研报复现 | 锚定反转因子](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486379&idx=1&sn=d6763bb198d0706c101f2544aa752b4f&scene=21#wechat_redirect)
    
-   [研报复现 | 另类ETF交易策略：日内动量](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&scene=21#wechat_redirect)
    
-   [研报复现 | 国盛金工：如何将隔夜涨跌变为有效的选股因子？——基于对知情交易者信息优势的刻画](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485766&idx=1&sn=89d4060fb135105b969c0ef2f145a7e0&scene=21#wechat_redirect)
    
-   [研报复现 | 招商证券：基于鳄鱼线的指数择时及轮动策略](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485702&idx=1&sn=2b0ed284177a66ee9d0e8623cd9cb1b4&scene=21#wechat_redirect)
    
-   [研报复现 | 华西金工-股票网络与网络中心度因子研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484829&idx=1&sn=3da8197374301bab9610f7ed5d4b715b&chksm=ce7e6283f909eb9509b3ebc9989fe9d140d5ee663ac8749aeb608833ff37544421d0dcd0fa9c&scene=21#wechat_redirect)  
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
-   [研报复现 | 开源证券 ：形态识别，均线的](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)[券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [利用LangGraph 和 OpenAI 打造金融分析师Agent](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [JFQA | 基于深度学习的排序特征因子模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488380&idx=1&sn=15327d544022028afab9efa2a90a0c36&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [NIPS 24 | PGN：RNN 的新继任者](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488128&idx=1&sn=a8287377302d2cdf5d1d6ddc321cdf31&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)  
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [ICLR 2024 | 通向透明的时间序列预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=ce7e624cf909eb5a44ce762087ef23bd8cfeb663aa623f0d729b99d56450abafd525d927bc5e&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)