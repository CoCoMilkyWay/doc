# 强化学习用于量化交易：技术指标与策略优化研究

QuantML QuantML 2025-03-09 21:19 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489609&idx=1&sn=cc17e21a1c55244959277ecc770b249d&chksm=cf449cdd5f5732f919dfd965759e65591be2108f555d996f72f20c2fb09379414861802dfd28#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489609&idx=1&sn=cc17e21a1c55244959277ecc770b249d&chksm=cf449cdd5f5732f919dfd965759e65591be2108f555d996f72f20c2fb09379414861802dfd28#rd)

### 

金融股票市场的固有波动性和动态变化，使得投资者需要采用全面且可靠的方法来整合风险管理策略、市场趋势以及个股走势，通过评估特定数据以做出更明智的决策。然而，当前文献缺乏对强化学习（Reinforcement Learning, RL）代理在实际应用中有效性的有力证据，许多模型仅在使用历史数据的回测中表现出成功，这凸显了需要更先进方法来应对这些挑战的紧迫性。此外，金融指标与市场趋势之间的关联以及其潜在优势常被研究忽视，且成功的交易策略在金融市场中往往被保密，导致利用RL的策略稀缺。本研究旨在通过增强RL代理利用金融指标有效区分正负买卖行为的能力来解决这些复杂性问题，虽未涵盖所有问题，但为深入探讨技术指标及其在强化学习中的益处提供了见解，并为更复杂场景的进一步探索奠定了基础。

## 1 引言

投资者在金融市场的主要目标始终是相同的：最小化交易风险并最大化以回报形式呈现的利润。实现这一目标涉及系统性地预测证券价格及随后的趋势，这是一个复杂且动态的任务，难以确定决策时应包含和排除哪些因素。该领域的研究主要围绕设计接管基础投资者责任并为金融市场提供更大流动性的自动化交易系统展开，过去曾使用监督学习和无监督学习技术，但结果并不理想。强化学习（RL）在这一特定应用中近年来受到关注，可能提供更准确的价格预测解决方案，从而使交易代理能够成功地与其环境互动以做出最优决策。金融数据的动态性与用于解决强化学习挑战的马尔可夫决策过程（Markov Decision Process, MDP）相契合，MDP帮助评估代理在观察状态和所处环境中应采取的行动，其假设未来状态取决于当前状态和行动，但这一假设存在问题，因为时间序列数据并非静态，普通股票市场数据包括每只证券的开盘价、收盘价、最高价、最低价和成交量，通常以各种时间间隔的顺序格式呈现，鉴于时间序列数据的性质及其对细微变化的敏感性，提出了技术指标以帮助创建更稳健的交易策略，进一步识别多头和空头情景的特征和模式。如今，有效利用这些指标可靠预测未来价格走势仍是挑战，虚假信号的存在又增加了复杂性。为解决此问题，通过卷积神经网络（Convolutional Neural Networks, CNN）、递归神经网络（Recurrent Neural Networks, RNN）、长短期记忆网络（Long Short Term Memory, LSTM）等技术进行了降维、特征选择和提取。实验部分使用的模型以20个技术指标作为输入，这些指标的详细解释可在John J. Murphy的《Technical Analysis》一书中找到。

## 2 问题陈述与动机

强化学习可被个人用于开发更稳健的交易策略，但如今个人因有限的计算资源而难以竞争，而量化对冲基金则拥有丰富的资源，便于其开展研究、开发和优化策略。本文的核心动机是由于该领域出版物数量有限，知识匮乏，量化对冲基金和个人投资者通常不愿向公众透露任何交易策略，以免失去竞争优势。我们的工作展示了使用带有指标的强化学习时需要考虑的因素，本文的发现为数据预处理、使用Backtesting.py进行回测、奖励函数、归一化方法等关键组成部分奠定了基础。需要注意的是，本研究并非旨在帮助个人获取经济利益，而是深入探讨局限性，供相关领域专家进一步开发。

## 3 背景概述

### 3.1 背景：强化学习在量化交易中的应用

强化学习（RL）在量化交易领域展现出巨大潜力，在许多情况下优于其他机器学习方法。在此情境中，RL代理与金融市场环境互动，根据其交易行为获得奖励或惩罚形式的反馈，其主要目标是最大化累积奖励，从而做出更准确和最优的交易决策。RL的一个关键优势在于其能够处理和分析大量金融数据，进而制定更明智的交易策略，但数据过载有时会使RL代理决策效率降低，因此需要开发先进方法来筛选和优先处理相关信息。此外，RL的有效性通常通过其预测未来市场走势和生成盈利交易策略的能力来衡量，引入折扣因子（𝛽）有助于考虑未来奖励的不确定性，平衡即时收益与长期潜力。

![](assets/001.png)

### 3.2 文献中关于指标的内容

在强化学习代理的背景下，金融指标是一种衡量手段，可帮助提供有关证券未来价格预测的见解，从而更好地理解趋势、变化和市场的快速波动。当前研究并未提供关于指标选择的结构化方法或途径，这些指标的选取未经过深入分析优缺点，这限制了代理的性能，也未能为代理提供理想的观察空间以优化决策。指标存在的普遍问题在于短期和长期时间框架之间的对比，短期指标对价格变化反应迅速（易受较大程度波动影响），而长期指标则平滑了波动。随着长期时间周期的平滑，精准识别趋势和转变变得复杂。通过图2和图3展示了不同时间周期的简单移动平均线（SMA）的趋势和对比，强调了根据RL交易者及其期望的交易频率选择合适指标的重要性，因为交易次数越多，佣金费用越高。短期交易者更侧重于利用波动获取利润，而长期交易者则利用较长时间框架持有资产，期待其价值上升。鉴于两种指标难以同时准确识别资产趋势，因此需要结合不同信号以更好地弥补单一指标的不足。

### 3.3 离散和连续动作空间

简要介绍离散和连续动作空间有助于更好地理解问题陈述。在这一特定应用中，可根据期望目标选择离散或连续动作空间。离散动作空间可定义为RL代理的买入或卖出行为，本研究也探索了此类应用。相反，连续动作空间可被应用，使得各种行为由0到1的范围定义，例如，0表示卖出行为，1表示买入行为，范围内的值则表示买入或卖出的置信度。此外，在连续动作空间中，0到1的范围还可用于表示投资组合中应分配给特定证券的资产比例。目前，在基于强化学习的股票交易模型中，动作空间被定义为0到1的连续范围，如使用深度Q网络（Deep Q-Networks）或近端策略优化（Proximal Policy Optimization, PPO）等策略梯度方法的模型，其性能在使用连续动作空间时得到提升。此外，从投资组合管理的角度来看，连续动作空间的应用也具有多样性，既能解决投资组合管理问题，也能适应单一的买入/卖出模型。

## 4 文献综述

2016年的一项研究采用深度强化学习方法，不依赖传统技术指标，通过重构递归深度神经网络（Recurrent Deep Neural Network, RDNN），实现了实时交易中的同时环境感知和递归决策，利用深度学习进行特征提取，并借助其他模糊学习原理处理输入数据，该解决方案在某些市场条件和时期内实现了盈利，超越了传统策略，但其评估仅限于少量合约，且未提供在实时交易中的策略性能证据。另一项研究将深度强化学习与情感分析相结合，以展示其在学习股票交易策略中的有效性，这种双管齐下的方法有助于减少仅使用算法的纯量化交易策略的不确定性，采用DDPG作为强化学习代理，RCNN用于情感分析以增强模型的预测能力，尽管实验表明与市场平均水平相比并无显著利润增长，但分析了代理学习交易策略的能力，然而其奖励函数存在局限性，未考虑风险因素，且为二元奖励函数，即如果采取的行动盈利则奖励为1，否则为0，这种奖励函数虽在短期内可能有效，但缺乏证明其长期交易结果有效的依据。还有研究引入了一种新颖的强化学习框架用于金融投资组合管理，该框架不依赖金融模型，由相同评估器集合（Ensemble of Identical Evaluators, EIIE）拓扑结构、投资组合向量记忆（Portfolio-Vector Memory, PVM）、在线随机批量学习（Online Stochastic Batch Learning, OSBL）方案以及旨在有效最大化回报和管理风险的显式奖励函数组成，该框架在加密货币市场的30分钟交易窗口内进行了三次回测实验，结果显示回报令人印象深刻，但该研究仅关注加密货币市场而非传统金融市场，该方法评估了九个不同的环境变量，包括开盘价、收盘价、最高价、最低价、前一日收盘价、交易量、成交额、股价百分比变化和绝对变化。论文介绍了交易代理的三种主要状态：买入、卖出或持有，强调了双重平均交易策略在帮助代理采取与最高回报/奖励相关的行动方面的有效性，使用短期和长期移动平均线来确定市场中的最佳买卖点。此外，大多数研究表明，长期回报视角下模型表现最佳，而短期则难以连续提供最优结果。

### 4.1 考虑因素

对不同环境变量进行归一化和缩放可能会带来挑战，每个变量都需对代理的决策过程做出同等贡献，不一致的缩放可能导致模型长期不准确。改变这些指标中的任何一个也可能会影响代理获得的奖励，需要谨慎考虑并调整奖励函数本身。例如，有研究进行了严格的回测以确保最佳结果，但问题在于确定持有状态的含义。在强化学习和离散动作空间中，需注意RL代理并不完全理解持有状态与无动作状态的区别，除非将此作为输入提供给代理，否则对于代理来说，持有状态可能是一个无动作状态，而非真正意义上的持有状态。无动作状态的问题在于，代理无法明确是处于买入还是卖出行为，或许还需要更多数据才能做出最优决策，当考虑代理在任何给定时间是否持有资产时，情况变得更加复杂，因为当不持有任何资产时，本质上是一个无动作状态，这与代理已经持有资产并决定持有这些资产的情况不同，不清楚持有状态是否具有价值，因为代理必须有效地权衡动态且不断变化的数据集中的收益与风险。

## 5 方法论

本研究探索了使强化学习代理能够随着环境变化继续学习和适应的潜在方法，研究了强化学习代理如何在特定市场条件和趋势下利用金融指标以增强整体交易准确性，通过理解各种指标之间的相关性，可选择性地识别哪些指标为RL代理提供新信息。数据预处理将探索多种方式以归一化强化学习输入，这有助于将强化学习代理的状态空间或输入特征缩放到指定范围内。本研究考虑了包括累加奖励、终端奖励、即时奖励和最终奖励在内的各种奖励函数，通过实验和测试不同奖励类型，研究确定了哪种奖励方案能帮助代理做出最优的交易选择，并通过上一时间步优先考虑近期表现。最终，奖励将影响代理的行为和交易频率。本研究的目标是考察并提供短期和长期交易视角的见解，通过将代理的注意力集中在买入或卖出两种行为上，可能使其更有效。接下来，研究选择了三种与离散动作空间最契合的算法，包括深度Q网络（Deep Q-Network, DQN）、近端策略优化（Proximal Policy Optimization, PPO）和演员-评论家（Actor-Critic, A2C）。

### 5.1 状态空间

交易环境中的状态空间由历史价格数据和技术指标组成，其维度由历史数据窗口的长度和指标数量决定，历史数据窗口通过雅虎财经API获取，以指定感兴趣的时间段。

### 5.2 动作空间

动作空间使用gym-anytrading库定义，该库扩展了OpenAI Gym框架，为模拟和测试算法化RL交易策略提供环境。默认情况下，该库使动作空间离散化，动作包括买入或卖出行为，强化学习代理始终处于市场中，并始终在执行这两种动作之一，代理不处于持有或无动作状态。

## 6 奖励函数

在上述动作空间定义的基础上，奖励函数根据代理采取的行动计算奖励，如果行动导致盈利交易，则奖励为正，如果导致亏损，则奖励为负。研究提出了三种潜在的奖励函数来训练RL代理进行交易，包括即时奖励、终端奖励和最终奖励。第一种奖励函数（即时奖励）通过评估当前时间步与前一时间步之间的对数价格差异来计算，它会检查下一个行动是否基于当前位置，然后计算当前价格与上次交易价格之间的价格差异，如果当前位置是多头仓位，则将价格差异加到步奖励中，公式可表示为：第二种奖励函数将奖励初始化为零，仅在行动发生变化（多头/空头）时计算奖励，如果当前行动与前一行动相同，则奖励保持为零，如果不同，则奖励计算为当前价格与初始价格的比率的自然对数。第三种奖励函数在整个过程中提供零即时奖励，仅根据初始权益价值与最终权益价值提供单一最终奖励。然而，所有这些奖励方案都存在局限性，在本研究中，主要关注即时奖励，因为它使RL代理能够以最大化每次交易财务收益的方式行事。

### 6.1 奖励函数局限性

在前一节中讨论了三种不同的奖励函数，第一种奖励函数简单地计算前一价格与当前价格之间的差异，但为RL模型提供即时奖励的问题在于，它倾向于优化每次交易的最小可能收益，而不是考虑长期利益，每个时间步都提供即时奖励会使模型更容易出现过拟合和/或学习方差更大的问题。同样，仅向模型提供最终奖励意味着模型将难以区分好交易与坏交易，这限制了模型的学习能力，因为它未被优化为在未来表现良好。在开发RL模型时，无论是短期交易还是长期交易，精心设计奖励函数都是至关重要的。

## 7 利用技术指标

本研究检查并评估了20种不同的技术指标（使用TA-Lib）作为RL输入，并采用最小-最大归一化方法对它们进行归一化，所使用的指标包括简单移动平均线（SMA）、成交量加权平均价（OBV）、动量、随机振荡器、MACD、商品通道指数（CCI）、平均方向指数（ADX）、三重指数平均线（TRIX）、变动率（ROC）、抛物线指标（SAR）、三指数移动平均线（TEMA）、三角移动平均线（TRIMA）、加权移动平均线（WMA）、双重指数移动平均线（DEMA）、资金流量指数（MFI）、钱德动量振荡器（CMO）、随机相对强弱指数（STOCHRSI）、终极振荡器（UO）、平衡量指标（BOP）和平均真实范围（ATR）。研究使用DummyVecEnv对自定义环境进行向量化，这种向量化环境有助于RL算法执行多个环境，从而实现更快的收敛和更高的效率，DummyVecEnv是多个环境的向量化包装器，允许按顺序在Python进程中调用每个环境。

## 8 归一化方法

进行了四项独立实验，以衡量使用最小-最大归一化、Z分数、Sigmoid和L2归一化时模式的差异。

### 8.1 最小-最大归一化

最小-最大归一化是一种流行且广泛使用的通用归一化方法，该方法将特征的值缩放到0和1之间，通过从每个值中减去特征的最小值，然后除以范围来实现：

### 8.2 Z分数归一化

其中：

-   ：表示原始值
    
-   ：表示数据的均值
    
-   ：表示数据的标准差
    

### 8.3 Sigmoid归一化

Sigmoid归一化方法涉及使用Sigmoid函数转换微阵列表达值，该函数将值缩放到0和1之间，然后根据样本标准差调整值与均值的距离和数据的变异性：

### 8.4 L2归一化

L2方法将计算向量元素平方值的平方根：

### 8.5 窗口归一化

创建了一个单独的函数，用于检索信号特征的窗口，使用对数变换进行归一化，并按10进行缩放，然后返回观测值：

### 8.6 总结

尽管本研究观察了各种数据预处理方法，但它们对模式识别和指标关系的影响似乎微乎其微，然而，利用PPO、A2C和DQN算法训练三个不同模型的潜力显著，接下来的部分将探讨这些算法如何解释这些关系以及它们对执行交易的影响。

## 9 指标相关矩阵

图4中的相关矩阵提供了关于所分析技术指标之间关系（高度相关或不高度相关）的覆盖和见解，具体模式包括相对强弱指数（RSI）与其他指标（包括动量、随机振荡器、MACD、CCI、ROC、CMO、STOCHRSI和UO）显示出强正相关性，这表明这些指标与RSI同向变动，而其他指标（如ADX、TRIX、SAR、TEMA、TRIMA、WMA、DEMA、MFI、BOP和ATR）与大多数其他指标显示出弱相关性，还对这些指标进行了其他三种归一化方法的测试，以更好地了解相关关系如何变化，结果表明所有这三种归一化方法提供的信息与最小-最大归一化方法相似，图4展示了按相同最小-最大尺度归一化的指标之间的相关性水平，需要注意的是，这可能不是衡量所有技术指标相关关系的有效方法，例如，动量指标的归一化方式可能与成交量指标不同。

![](assets/002.png)

## 10 训练数据

初始训练数据集由苹果公司（APPL）2020年1月1日至2022年1月1日的两年日数据组成，这些数据用于训练每种模型，每种模型分别使用不同的算法，研究重点关注演员-评论家（Actor-Critic）、近端策略优化（PPO）和深度Q网络（DQN），因为这些算法在以往的研究中被证明是有效的，并且与离散动作空间配合良好，每种模型都在一百万时间步上进行训练，代理与环境通过一系列时间步进行交互，然后在每个时间步 ，代理将接收到环境的状态以及与前一行动相关的奖励，代理随后将采取行动。

## 11 实验与结果

### 11.1 演员-评论家（Actor-Critic）

如图5所示，在两年期间，采用MlpPolicy的A2C方法表现不佳，与其他使用DQN和PPO的模型相比，A2C的一个固有问题在于其需要大量数据才能有效学习，A2C还容易受到收敛问题的影响，尤其是因为它基于梯度下降，这意味着参数将按照性能提升最快的方向进行更新，对于时间序列数据，A2C存在诸多问题，其表现也证实了这一点。

### 11.2 近端策略优化（PPO）

近端策略优化（PPO）算法在识别何时发起买入或卖出行动方面存在困难，尽管在某些情况下确实做出了合理的交易，但最终未能明确区分盈利的买入或卖出行动，如图6所示，在两年期间，PPO模型进行了最多的交易，与其他算法相比，PPO模型在两年期间内总共进行了101次交易，PPO算法并不有效，因为所有交易的胜率为27%，且总体回报为负，年化波动率接近10%，由回测产生的利润因子也并非正值。

### 11.3 深度Q网络（DQN）

深度Q网络（DQN）模型在数周内提供了有力证据，一系列盈利的买入行动增加了回报，然而，其在某些周的表现较为不稳定，此外，它频繁地在很接近的时间内执行买入和卖出行动，这表明该策略可能缺乏稳定性，鉴于该模型迄今为止表现最佳，因此对其进行了进一步的超参数调整评估，DQN模型在一开始进行了一些盈利交易，它在理解什么是好的交易方面表现良好，但在某些特定时间段内确实存在困难，图7展示了DQN在两年期间的表现，以及在未调整超参数和使用MlpPolicy的情况下，学习率控制梯度下降过程中的步长，降低学习率是为了尝试稳定模型。

### 11.4 超参数

表1：超参数

超参数

值

学习率

(1 \\times 10^{-4})

缓冲区大小

100000

批量大小

128

折扣因子（Gamma）

0.99

目标更新间隔

1000

表1展示了正在考察的五个不同的超参数，为了更好地评估模型探索和学习的能力，研究对不同学习率进行了测试，以识别训练集性能方面是否存在任何模式或变化。

### 11.5 学习率

接下来，研究对DQN模型进行了不同学习率的测试，以确定其对模型性能的影响。初步测试结果表明，较大的学习率有助于提升模型的整体性能。较大的学习率有助于探索，但学习率可以在模型表现出更大的稳定性后进行调整以减小。

### 11.6 超参数调整结果

图8展示了使用DQN模型进行的多次调整，包括学习率、缓冲区大小、批量大小、折扣因子（Gamma）和目标更新间隔等参数调整后的表现。例如，批量大小是从缓冲区中采样的经验数量，然后在迭代过程中用于更新权重。在将学习率调整为 (1 \\times 10^{-4}) 后，模型开始更好地识别盈利交易。

表2：结果

结果

值

回报率（%）

13.558111

年化回报率（%）

7.149259

年化波动率（%）

29.531209

夏普比率

0.242092

索提诺比率

0.392577

卡玛比率

0.170546

胜率（%）

45.901639

在接下来的实验中，学习率从 (1 \\times 10^{-4}) 调整为 (1 \\times 10^{-2})，而其他参数保持不变，如表3所示。较大的学习率有助于更快地收敛，因为学习率较高，网络会更快地调整权重。相反，较小的学习率（如 (1 \\times 10^{-4})）会提供更稳定的权重更新，但由于更新较小，整体训练时间会增加。研究探索了探索与利用之间的权衡。

表3：超参数

超参数

值

学习率

(1 \\times 10^{-2})

缓冲区大小

100000

批量大小

128

折扣因子（Gamma）

0.99

目标更新间隔

1000

图9展示了使用 (1 \\times 10^{-2}) 学习率的DQN模型的表现。表4展示了调整超参数后的DQN模型性能。关键指标包括胜率、夏普比率、回报率和波动率。特别是学习率从 (1 \\times 10^{-4}) 调整为 (1 \\times 10^{-2})，这一简单的变化在回报率、夏普比率和胜率方面带来了显著的差异。

表4：结果

结果

值

回报率（%）

92.316259

年化回报率（%）

42.642871

年化波动率（%）

39.851569

夏普比率

1.070042

索提诺比率

2.395635

卡玛比率

2.094297

胜率（%）

100.0

有趣的是，模型仅交易了一次，而使用较大学习率时进行了61次交易。然而，这也引发了对模型可能过拟合的担忧，因为模型在胜率和夏普比率方面都表现出显著的变化。研究结果表明，DQN在与其他两种算法相比时表现更优。鉴于模型处理了大量数据，研究了超参数及其对模型稳定性和性能的影响。特别是，缓冲区大小决定了在对整个集合执行梯度下降之前需要收集的经验数量，学习率也影响了模型的学习效率。尽管本研究仅进行了少量超参数调整实验，但可以围绕超参数进行更多实验。

### 11.7 时间间隔与策略退化

当前工作为改进和深入探索提供了多个方向。特别关注的一个领域是数据时间间隔。将测试范围扩大到更细粒度的数据时间间隔，如小时、分钟或秒，有助于捕捉更多细节，并为每个训练的RL代理的表现提供更深入的见解。此外，重要的是在不同市场条件下对不同模型进行比较分析。例如，研究DQN是否在市场下跌期间优于PPO，以及这种表现背后的原因，可能会带来更好的见解。此外，纳入Stable-Baselines3中的多样化策略，并结合超参数调整和探索/利用策略，是完善这些模型的关键步骤。金融市场在交易时间内提供了大量的新数据，模型需要不断优化。另一个普遍问题是策略退化。虽然可以使用历史数据对单一策略进行回测，但策略的未来表现总是不确定的。使用更全面的方法，如集成方法，有助于最小化在单一算法上训练RL代理的风险，但并不能充分解决策略退化问题。

## 12 策略开发

在开发RL交易策略时，需要考虑许多因素。本研究为开发RL交易策略提供了一些关键考虑因素。个人可以立即复制这项工作，并开始探索不同的股票代码。可以使用Backtesting.py开发和测试许多策略，并设置止损、订单大小和其他特定交易功能，以模拟现实世界的交易环境并利用RL。可以进一步扩展到使用所有200多个技术指标作为输入，并确定这些指标的最佳归一化方案。例如，归一化方法对于移动平均收敛发散指标（MACD）这种滞后指标会有所不同，因为其范围在-1.0到1之间，而最大-最小归一化方法将所有数据缩放到0到1之间，这可能会导致问题。应谨慎选择指标并适当归一化，以避免结果失真。

## 13 结论

金融市场以其固有的波动性和动态变化为特征，投资者需要采用全面的策略，整合风险管理、市场趋势和个股走势。当前文献旨在追求稳健性，并强调需要先进的方法来弥合强化学习（RL）在量化交易中的差距。本研究的关键贡献在于为强化学习在金融交易中的应用提供了一个基础框架，

  

  

  

  

  

论文见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/003.png)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib重磅更新：DeepSeek核心模型结构用于选股](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489025&idx=1&sn=35941156783794d719e6ff891ce720c3&scene=21#wechat_redirect)  
    
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
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&scene=21#wechat_redirect)  
    
-   [Hummingbot：开源加密货币做市机器人框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489153&idx=1&sn=98198f6cca4aa5bc5646e926c358f01d&scene=21#wechat_redirect)  
    
-   [FinRLlama：基于强化学习和市场反馈的金融情感分析LLM优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489127&idx=1&sn=faad16c8ac3ca02dcb982837d03b21ab&scene=21#wechat_redirect)  
    
-   [端到端基于LLM的增强型交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&scene=21#wechat_redirect)
    
-   [基于分层强化学习的日内风险因子挖掘](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489104&idx=1&sn=c0b6938ebcf0cbd8244f87abe609798e&scene=21#wechat_redirect)
    
-   [DeepScalper：深度强化学习捕捉日内交易的短暂机会](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&scene=21#wechat_redirect)
    
-   [TradingAgents：基于多智能体LLM的金融交易框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488712&idx=1&sn=daa7fb4a9d49a621f9f54579dda4a184&scene=21#wechat_redirect)  
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)