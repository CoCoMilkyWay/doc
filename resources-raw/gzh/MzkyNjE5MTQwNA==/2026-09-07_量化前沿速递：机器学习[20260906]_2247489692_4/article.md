# 量化前沿速递：机器学习\[20260906\]

shameless 量化前沿速递 2026-09-07 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489692&idx=4&sn=9ffaccb4b4be0700cf5375e95b00025c&chksm=c3e7753fe5a74068ea4ae6d94e78d6d8423a5c71c81f3ab494d4158d60359db6ba773e805976#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489692&idx=4&sn=9ffaccb4b4be0700cf5375e95b00025c&chksm=c3e7753fe5a74068ea4ae6d94e78d6d8423a5c71c81f3ab494d4158d60359db6ba773e805976#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Deep Hedging Under Realistic Market Frictions

现实市场摩擦下的深度对冲

来源:ARXIV\_20260901

\[2\] Eliciting ESG Preferences for Reinforcement Learning Based Portfolio Optimization

利用ESG偏好进行基于强化学习的投资组合优化

来源:ARXIV\_20260903

\[3\] Scaling Laws, Tabular Data and Actuarial Ratemaking Models

比例定律、表格数据和精算费率制定模型

来源:ARXIV\_20260904

### 

\[1\] Deep Hedging Under Realistic Market Frictions

标题:现实市场摩擦下的深度对冲

作者:Sheryan Kumar

来源:ARXIV\_20260901

链接:https://arxiv.org/pdf/2608.29025

Abstract : Classical option hedging methods like Black Scholes delta assume constant, free rebalancing, which real markets don t allow. Deep hedging trains a neural network to handle these frictions directly, and prior work reports strong results. But those comparisons usually pit deep hedging against a frictionless classical baseline on simulated price data. That s not a fair fight, and it leaves open whether the advantage is real.We test this using five years of actual BTC options data from Deribit (2020 2024), comparing Black Scholes delta, Leland s cost adjusted hedge, and the Whalley Wilmott no trade band against three deep hedging setups  an LSTM and a feedforward network, each trained with a CVaR loss and, in some runs, a penalty for trading too often. All six strategies face the same 5 basis point transaction cost.On 11,546 test episodes from September 2023 to December 2024, Whalley Wilmott cuts transaction costs significantly versus hourly rebalancing, saving  1.79 per episode against plain BS delta (95  CI   2.21,  1.39 , p   0.0001) by trading about eight times less often. Its P&L and tail risk numbers are better too, though not quite significant at this sample size. None of the three deep hedging models beat any classical benchmark on any metric, and all kept trading almost every hour regardless of penalty weight, a twenty fold range barely moved the needle. A calmer validation period shows Whalley Wilmott s P&L edge shrinks or disappears there while its cost edge holds, so the result depends on market regime. We think the likely causes are a small training set and the lack of any built in mechanism for sitting still in the architectures tested. Not a flashy result, but an honest one  a real data check on a claim mostly supported by simulations so far.

Keywords : 

Abstract :经典的期权对冲方法，如Black-Scholes delta，假设持续的、自由的再平衡，这是真实市场所不允许的。深度对冲训练了一个神经网络来直接处理这些摩擦，之前的工作报告了强有力的结果。但这些比较通常将深度对冲与模拟价格数据上无摩擦的经典基线进行比较。这不是一场公平的斗争，优势是否真实存在还有待商榷。我们使用Deribit（2020-2024）的五年实际BTC期权数据对此进行了测试，将Black-Scholes delta、Leland的成本调整对冲和Whalley Wilmott无交易区间与三个深度对冲设置（LSTM和前馈网络）进行了比较，每个设置都用CVaR损失进行了训练，在某些情况下，还对过于频繁的交易进行了惩罚。所有六种策略都面临相同的5个基点的交易成本。在2023年9月至2024年12月的11546次测试中，Whalley Wilmott与每小时的再平衡相比显著降低了交易成本，通过减少约8倍的交易频率，每一次的交易成本比简单的BS delta节省了1.79（95 CI 2.21，1.39，p 0.0001）。它的损益和尾部风险数字也更好，尽管在这个样本量下并不十分显著。三种深度对冲模型在任何指标上都没有击败任何经典基准，并且几乎每小时都在交易，无论惩罚权重如何，20倍的范围几乎没有改变。平静的验证期表明，Whalley Wilmott的损益优势在那里缩小或消失，而其成本优势保持不变，因此结果取决于市场机制。我们认为，可能的原因是训练集较小，并且在测试的架构中缺乏任何内置的静止机制。这不是一个华而不实的结果，而是一个诚实的结果——对迄今为止主要由模拟支持的说法进行了真实的数据检查。

Keywords :

### 

\[2\] Eliciting ESG Preferences for Reinforcement Learning Based Portfolio Optimization

标题:利用ESG偏好进行基于强化学习的投资组合优化

作者:Giovanni Dispoto, Marcello Restelli, Carmine Ventre

来源:ARXIV\_20260903

链接:https://arxiv.org/pdf/2609.02677

Abstract : Modern portfolio management increasingly demands a balance between traditional risk adjusted returns and strict Environmental, Social, and Governance (ESG) mandates. Current Reinforcement Learning (RL) approaches typically optimize for a single ESG provider, neglecting the significant divergence in rating methodologies across the industry and the unintuitive nature of manually weighting conflicting objectives. This paper addresses these limitations by formulating ESG aware portfolio optimization as a Multi Objective Reinforcement Learning (MORL) problem that simultaneously incorporates ratings from three distinct ESG agencies. To bridge the gap between high dimensional algorithmic trade offs and human decision making, we integrate a Preference Elicitation framework using Gaussian Processes. This system enables practitioners to infer their latent utility functions through intuitive pairwise comparisons of candidate portfolios based on their Sharpe ratios and aggregate ESG scores. We systematically evaluate our framework by employing Large Language Model (LLM) personas to simulate Portfolio Managers operating under varied regional contexts. Empirical results using historical market data reveal that regional backgrounds fundamentally shift the derived preference weights. For instance, European based personas tend to prioritize ESG alignment over financial returns, while Texas based personas favor risk adjusted performance. This work offers a highly adaptable framework that successfully aligns multi objective algorithmic trading with diverse, real world human sustainability preferences.

Keywords : 

Abstract :现代投资组合管理越来越需要在传统的风险调整回报和严格的环境、社会和治理（ESG）要求之间取得平衡。当前的强化学习（RL）方法通常针对单个ESG提供商进行优化，忽略了整个行业评级方法的显著差异以及手动加权冲突目标的非直观性。本文通过将ESG感知的投资组合优化制定为多目标强化学习（MORL）问题来解决这些局限性，该问题同时结合了三个不同ESG机构的评级。为了弥合高维算法权衡和人类决策之间的差距，我们使用高斯过程集成了偏好诱导框架。该系统使从业者能够通过基于夏普比率和ESG总分的候选投资组合的直观成对比较来推断其潜在的效用函数。我们通过使用大型语言模型（LLM）人物角色来模拟在不同地区背景下运作的投资组合经理，从而系统地评估我们的框架。使用历史市场数据的实证结果表明，区域背景从根本上改变了导出的偏好权重。例如，欧洲的人物角色倾向于将ESG一致性置于财务回报之上，而德克萨斯州的人物角色则更喜欢风险调整后的绩效。这项工作提供了一个高度适应性的框架，成功地将多目标算法交易与不同的现实世界人类可持续性偏好相结合。

Keywords :

### 

\[3\] Scaling Laws, Tabular Data and Actuarial Ratemaking Models

标题:比例定律、表格数据和精算费率制定模型

作者:Ronald Richman

来源:ARXIV\_20260904

链接:https://arxiv.org/pdf/2609.03106

Abstract : Scaling laws in modern deep learning describe how held out loss improves as model capacity, training data, and compute increase, often following power law trends. We investigate whether analogous scaling regularities arise in actuarial ratemaking, where data are tabular, heterogeneous, and noisy, and where classical models such as GLMs remain strong baselines. Using a real world motor insurance portfolio, we train models from different families across increasing fractions of the training data and multiple random seeds, evaluating out of sample Poisson deviance, a likelihood based loss for Poisson count predictions in which lower values indicate better held out fit. We find that all model families improve with additional data, but scaling exponents differ substantially  TabM exhibits markedly stronger data scaling than purely supervised tabular Transformers and standard MLP baselines. Transformer variants show weak parameter scaling unless augmented with additional inductive biases (TabM style adaptation or self supervision). These results provide quantitative guidance on model selection by data regime and suggest that effective scaling on actuarial tabular tasks depends on architecture and loss function objective design, with simple increases in Transformer size providing limited gains.

Keywords : 

Abstract :现代深度学习中的缩放定律描述了随着模型容量、训练数据和计算量的增加，保持损失如何改善，通常遵循幂律趋势。我们研究了在精算费率制定中是否会出现类似的缩放规律，在这种情况下，数据是表格化的、异构的和有噪声的，而GLM等经典模型仍然是强基线。使用真实世界的汽车保险投资组合，我们在训练数据的增加部分和多个随机种子中训练来自不同家族的模型，评估样本外泊松偏差，这是一种基于概率的泊松计数预测损失，其中较低的值表示更好的拟合。我们发现，所有模型族都会随着额外数据的增加而改善，但缩放指数差异很大。TabM的数据缩放能力明显强于纯监督的表格转换器和标准MLP基线。变压器变体显示出弱的参数缩放，除非增加额外的电感偏置（TabM式自适应或自我监督）。这些结果为数据机制的模型选择提供了定量指导，并表明精算表任务的有效缩放取决于架构和损失函数目标设计，变压器尺寸的简单增加提供了有限的增益。

Keywords :