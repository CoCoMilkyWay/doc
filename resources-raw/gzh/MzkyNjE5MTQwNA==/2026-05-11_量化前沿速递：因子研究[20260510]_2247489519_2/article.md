# 量化前沿速递：因子研究\[20260510\]

shameless 量化前沿速递 2026-05-11 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489519&idx=2&sn=121de83cf964497d325f0019e639058c&chksm=c3a109140eddea77488379372eed3950ffb0a2f5a4e3b560cd4ae39a25d3b5241219ff989297#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489519&idx=2&sn=121de83cf964497d325f0019e639058c&chksm=c3a109140eddea77488379372eed3950ffb0a2f5a4e3b560cd4ae39a25d3b5241219ff989297#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] PHBench

PHBench

来源:ARXIV\_20260506

\[2\] Market implied time to transition to a low carbon economy

市场意味着向低碳经济过渡的时间

来源:ARXIV\_20260506

\[3\] Fiscal Aggregation and the Limits of IS  LM  BP

财政总量与IS LM BP的局限性

来源:ARXIV\_20260506

\[4\] The Real Interest Rate as a Control Variable in the Open Economy

开放经济中的实际利率作为控制变量

来源:ARXIV\_20260506

\[5\] Do Venture Capitalists Beat Random Allocation 

风险投资家能否战胜随机分配

来源:ARXIV\_20260506

\[6\] Structural Limits of OHLCV Based Intraday Signals in MNQ Futures

MNQ期货中基于OHLCV的日内信号的结构极限

来源:ARXIV\_20260506

\[7\] Single Period Portfolio Selection via Information Projection

基于信息预测的单期投资组合选择

来源:ARXIV\_20260506

\[8\] Human Provenance Verification should be Treated as Labor Infrastructure in AI Saturated Markets

人类来源验证应被视为人工智能饱和市场中的劳动力基础设施

来源:ARXIV\_20260506

\[9\] Coordination as an Architectural Layer for LLM Based Multi Agent Systems

协调作为基于LLM的多智能体系统的架构层

来源:ARXIV\_20260506

\[10\] Scaling Limits of Bivariate Nearly Unstable Hawkes Processes and Applications to Rough Volatility

二元近似不稳定霍克斯过程的标度极限及其在粗糙波动中的应用

来源:ARXIV\_20260506

\[11\] ESG as Priced Crash Insurance

ESG作为定价崩溃保险

来源:ARXIV\_20260507

\[12\] Dynamic Collateral Control for Permissionless Spot Perpetual Basis Trading

无许可现货永续基差交易的动态抵押品控制

来源:ARXIV\_20260507

\[13\] The Demand Externality of Automation

自动化的需求外部性

来源:ARXIV\_20260507

\[14\] What Can Go Wrong During Caplet Stripping  

剥去帽子时会出什么问题

来源:ARXIV\_20260507

\[15\] Optimal Semiparametric Dynamic Pricing with Feature Diversity

具有特征多样性的最优半参数动态定价

来源:ARXIV\_20260507

\[16\] DAO enabled decentralized physical AI

支持DAO的去中心化物理AI

来源:ARXIV\_20260507

\[17\] Learning Time Inhomogeneous Markov Dynamics in Financial Time Series via Neural Parameterization

通过神经参数化学习金融时间序列中的时间非齐次马尔可夫动力学

来源:ARXIV\_20260507

\[18\] Lithium enrichment threatens to curb fusion deployment

锂浓缩威胁到核聚变部署

来源:ARXIV\_20260507

\[19\] A Review of Large Language Models for Stock Price Forecasting from a Hedge Fund Perspective

对冲基金视角下股票价格预测的大型语言模型综述

来源:ARXIV\_20260508

\[20\] Artificial Aesthetics

人工美学

来源:ARXIV\_20260508

\[21\] Numerical methods for lambda quantiles

lambda分位数的数值方法

来源:ARXIV\_20260508

\[22\] Funding Aware Optimal Market Making for Perpetual DEXs

永续DEX的资金意识优化做市

来源:ARXIV\_20260508

\[23\] A Geometry Aware Residual Correction of Hagan s SABR Implied Volatility Formula

Hagan SABR隐含波动率公式的几何感知残差校正

来源:ARXIV\_20260508

\[24\] Frustrated Dynamics of Distance Matrices

距离矩阵的受阻动力学

来源:ARXIV\_20260508

\[25\] Multi Dimensional Behavioral Evaluation of Agentic Stock Prediction Systems Using LLM Judges with Closed Loop Reinforcement Learning Feedback

基于闭环强化学习反馈的LLM判断的代理股票预测系统多维行为评价

来源:ARXIV\_20260508

\[26\] INEUS

INEUS

来源:ARXIV\_20260508

\[27\] Cascading disruptions in natural gas, fertilizers, and crops drive structural food supply vulnerabilities globally

天然气、化肥和作物的连锁中断加剧了全球粮食供应的结构性脆弱性

来源:ARXIV\_20260508

\[28\] Neural Actuarial Longevity Forecasting

神经精算寿命预测

来源:ARXIV\_20260508

\[29\] SNAPO

斯内普

来源:ARXIV\_20260508

### 

\[1\] PHBench

标题:PHBench

作者:Yagiz Ihlamur, Ben Griffin, Rick Chen

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.02974

Abstract : Structured launch signals on Product Hunt contain statistically significant predictive information for Series A funding outcomes. We construct PHBench from 67,292 featured Product Hunt posts spanning 2019 2025, linked to Crunchbase funding records via deterministic domain matching, identifying 528 verified Series A raises within 18 months of launch (positive rate  0.78 ). Our best performing model, a three component ensemble (ENS avg, ENS ISO, XGB) selected by validation F0.5, achieves F0.5   0.097 and AP   0.037 (95  CI  0.024 0.072  4.7x lift over random) on the private held out test set (103 positives). A paired bootstrap confirms a statistically credible advantage over the logistic regression baseline (AP delta   0.013, 95  CI   0.004, 0.039 , p   0.001  F0.5 delta   0.056, 95  CI   0.006, 0.122 , p   0.016). Validation set metrics (F0.5   0.284, AP   0.126) reflect best of 144 selection bias on 53 positives and are reported for benchmark reproducibility only.We further evaluate three zero shot Gemini models (Gemini 2.5 Flash, Gemini 3 Flash, and Gemini 3.1 Pro) in an anonymized numerical setting. The best LLM achieves AP   0.034 (Gemini 3 Flash), below the LR baseline AP of 0.044. Notably, the most capable Gemini variant (Gemini 3.1 Pro, AP   0.023) performs worst    an unexpected pattern that warrants further investigation across providers and prompting strategies. Both ML and LLM models show the same temporal performance decay tracking the 2020 2021 funding boom and subsequent contraction, confirming the dataset captures genuine market structure rather than noise.PHBench provides a reproducible framework comprising public training, validation, and blind test splits  61 engineered features  a five metric evaluation harness  and a public leaderboard at this https URL. All code, baseline models, and anonymized dataset splits are publicly available.

Keywords : 

Abstract :Product Hunt上的结构化启动信号包含对A轮融资结果具有统计意义的预测信息。我们从2019年至2025年的67292篇特色Product Hunt帖子中构建了PHBench，这些帖子通过确定性域匹配与Crunchbase的融资记录相关联，在发布后18个月内识别出528次经过验证的A轮融资（正利率0.78）。我们表现最佳的模型是通过验证F0.5选择的三组分集成（ENS平均值、ENS ISO、XGB），在私人持有测试集（103个阳性）上达到了F0.5 0.097和AP 0.037（95 CI 0.024 0.072 4.7x随机提升）。配对引导法证实了与逻辑回归基线相比具有统计学上可信的优势（APδ0.013，95 CI 0.004，0.039，p 0.001 F0.5δ0.056，95 CI 0.008，0.122，p 0.016）。验证集指标（F0.5 0.284，AP 0.126）反映了53个阳性样本的144个选择偏差中的最佳值，仅用于基准再现性报告。我们在一个匿名的数值设置中进一步评估了三个零射Gemini模型（Gemini 2.5 Flash、Gemini 3 Flash和Gemini 3.1 Pro）。最佳LLM达到AP 0.034（Gemini 3 Flash），低于LR基线AP 0.044。值得注意的是，功能最强大的Gemini变体（Gemini 3.1 Pro，AP 0.023）表现最差——这是一种意想不到的模式，值得在供应商和提示策略之间进行进一步调查。ML和LLM模型都显示了相同的时间性能衰减，跟踪了2020-2021年的融资热潮和随后的收缩，证实了数据集捕捉到了真实的市场结构，而不是噪音。PHPench提供了一个可重复的框架，包括公共培训、验证和盲测拆分61个工程特征、一个五指标评估工具和一个公共排行榜，位于此https URL。所有代码、基线模型和匿名数据集拆分都是公开的。

Keywords :

### 

\[2\] Market implied time to transition to a low carbon economy

标题:市场意味着向低碳经济过渡的时间

作者:Lorenzo Mercuri, Andrea Perchiazzo, Edit Rroji, Ilaria Stefano

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03082

Abstract : This paper introduces a new market implied object, Time to Transition (TtT), extracted from the difference between two selected nodes of the greenium term structure. TtT is defined as the latent waiting time until this cross maturity greenium difference vanishes, meaning that the greenium becomes equal across the two selected maturities. We develop an inference theory for this object. To model TtT, we introduce two tractable stochastic frameworks  the Regulatory Deadline Constrained Model, in which the transition date is fixed, and a switching extension, in which alternative transition dates capture heterogeneous perceived deadlines across economic agents. The paper combines two layers of analysis. On a fixed daily grid, a deadline constrained diffusion provides a tractable benchmark through an exact Gaussian bridge likelihood, while the switching extension preserves tractability through regime specific bridge densities and filtering recursions. Under a fixed horizon infill scheme, the same framework yields a structural identification result for the regime wise diffusion parameters, with full or partial consistency depending on the observed region. The paper therefore contributes both a new inferential object, market implied transition timing based on cross maturity differences in the greenium term structure, and a two layer inference framework  finite sample filtering provides an operational monitoring tool, while fixed horizon infill asymptotics specify when the regime wise diffusion parameters carrying information about competing transition dates can be consistently estimated.

Keywords : 

Abstract :本文介绍了一个新的市场隐含对象，即过渡时间（TtT），它是从绿色期限结构的两个选定节点之间的差异中提取出来的。TtT被定义为直到这种交叉成熟绿差异消失的潜在等待时间，这意味着绿在两个选定的成熟期之间变得相等。我们为这个对象开发了一个推理理论。为了对TtT进行建模，我们引入了两个易于处理的随机框架——监管截止日期约束模型，其中过渡日期是固定的，以及切换扩展，其中替代过渡日期捕获了经济主体之间异质的感知截止日期。本文结合了两层分析。在固定的日网格上，截止日期约束扩散通过精确的高斯桥似然提供了一个可处理的基准，而切换扩展通过特定制度的桥密度和滤波递归保持了可处理性。在固定层位填充方案下，相同的框架会产生逐体制扩散参数的结构识别结果，其完全或部分一致性取决于观测区域。因此，本文提出了一个新的推理对象，即基于绿色期限结构中交叉成熟度差异的市场隐含转换时间，以及一个两层推理框架——有限样本滤波——提供了一种操作监控工具，而固定期限填充渐近线则规定了何时可以一致地估计携带竞争转换日期信息的制度扩散参数。

Keywords :

### 

\[3\] Fiscal Aggregation and the Limits of IS  LM  BP

标题:财政总量与IS LM BP的局限性

作者:Ricardo Alonzo Fernandez Salguero

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03881

Abstract : This paper develops a formal critique of scalar fiscal aggregation in the IS LM BP Mundell Fleming framework. It shows that when fiscal policy is composed of heterogeneous instruments current purchases, public investment and transfers to different households the aggregate variable G is sufficient for output analysis only under a restrictive gradient condition  all instruments must have identical marginal effects on output. The paper proves this condition, derives composition weighted multipliers, identifies aggregation bias and extends the open economy IS LM BP model to incorporate fiscal composition, public capital, debt dynamics and risk premium effects. A reproducible computational exercise with symbolic checks, derivative tests, accounting identities, adversarial counterexamples, sensitivity sweeps, Monte Carlo simulations and stress tests confirms the internal consistency of the argument. The contribution is methodological  IS LM BP remains useful as a compact equilibrium framework, but fiscal policy analysis requires vector valued instruments and state contingent multipliers rather than a single homogeneous spending variable.

Keywords : 

Abstract :本文在IS-LM BP Mundell-Fleming框架下对标量财政聚合进行了形式化批判。它表明，当财政政策由异质工具组成时——当前购买、公共投资和向不同家庭的转移——聚合变量G仅在限制梯度条件下才足以进行产出分析——所有工具必须对产出具有相同的边际效应。本文证明了这一条件，推导了构成加权乘数，识别了聚合偏差，并扩展了开放经济IS LM BP模型，以纳入财政构成、公共资本、债务动态和风险溢价效应。通过符号检查、衍生品测试、会计恒等式、对抗性反例、敏感性扫描、蒙特卡洛模拟和压力测试等可重复的计算练习，证实了论点的内部一致性。is LM BP作为一个紧凑的均衡框架仍然有用，但财政政策分析需要向量值工具和状态或有乘数，而不是一个单一的同质支出变量。

Keywords :

### 

\[4\] The Real Interest Rate as a Control Variable in the Open Economy

标题:开放经济中的实际利率作为控制变量

作者:Carlos Esteban Posada, Liz Londoño-Sierra

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03966

Abstract : This paper addresses the structure and dynamics of an open market economy and its relations with the real interest rate. In this respect, the paper is situated within a broad conventional literature. However, it departs from the standard approach to the interest rate by treating it as a control variable. Even so, the analysis concludes that the two main determinants of the interest rate are the future utility discount rate and expectations regarding future multifactor productivity (labor efficiency). Furthermore, increases in such expectations lead to increases in both the interest rate and wages. These results are consistent with to those obtained with the Cass, Koopmans, Ramsey model.

Keywords : 

Abstract :本文探讨了开放市场经济的结构和动态及其与实际利率的关系。在这方面，本文处于广泛的传统文献中。然而，它偏离了标准的利率方法，将其视为控制变量。即便如此，分析得出结论，利率的两个主要决定因素是未来效用贴现率和对未来多因素生产率（劳动效率）的预期。此外，这种预期的增加会导致利率和工资的增加。这些结果与Cass、Koopmans、Ramsey模型的结果一致。

Keywords :

### 

\[5\] Do Venture Capitalists Beat Random Allocation 

标题:风险投资家能否战胜随机分配

作者:Max Sina Knicker, Jean-Philippe Bouchaud, Michael Benzaquen

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03980

Abstract : Venture capital outcomes are dominated by a small number of extreme successes, making it difficult to distinguish investor skill from favorable realizations in a highly skewed return distribution. We study this question by comparing empirical VC portfolios to a constrained random benchmark that preserves key portfolio characteristics, including timing, geography, sector composition, and portfolio size, while randomizing individual company selection. Across funding stages, empirical portfolio distributions appear remarkably close to their random benchmarks. We find no evidence that portfolio construction increases the probability of high multiple outcomes  the right tail remains statistically indistinguishable from random allocation. Deviations in the lower part of the distribution are small and sensitive to the interpretation of zero outcomes, suggesting at most weak evidence of downside improvement. We further introduce a rank based benchmark distribution to evaluate outperformance at each position in the cross section. This analysis shows that even the best performing portfolios do not exceed the outcomes expected for their rank under random sampling. Our results suggest that VC portfolio outcomes are largely consistent with constrained random allocation, highlighting the difficulty of identifying aggregate skill in heavy tailed investment environments. A similar conclusion holds for the performance of financial analysts in predicting future earnings.

Keywords : 

Abstract :风险投资的结果主要由少数极端成功所主导，这使得在高度扭曲的回报分布中很难区分投资者的技能和有利的实现。我们通过将经验风险投资组合与约束随机基准进行比较来研究这个问题，该基准保留了关键的投资组合特征，包括时间、地理、行业构成和投资组合规模，同时随机化了单个公司的选择。在各个融资阶段，实证投资组合分布似乎非常接近其随机基准。我们没有发现任何证据表明投资组合构建会增加高倍数结果的概率——右尾在统计上与随机分配没有区别。分布下部的偏差很小，对零结果的解释很敏感，这最多表明下行改善的证据很弱。我们进一步引入了一种基于排名的基准分布来评估横截面中每个位置的表现。这一分析表明，即使是表现最好的投资组合也不会超过随机抽样下其排名的预期结果。我们的研究结果表明，风险投资组合的结果在很大程度上与约束随机分配一致，突显了在重尾投资环境中识别总体技能的困难。同样的结论也适用于金融分析师在预测未来收益方面的表现。

Keywords :

### 

\[6\] Structural Limits of OHLCV Based Intraday Signals in MNQ Futures

标题:MNQ期货中基于OHLCV的日内信号的结构极限

作者:Mathias Mesfin

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.04004

Abstract : This paper tests whether intraday momentum signals derived from open high low close volume (OHLCV) data produce a statistically significant trading edge in Micro E mini Nasdaq 100 futures (MNQ) under realistic execution constraints. Using 947 trading days of five minute data (2021 2025), fourteen signal families are evaluated, including opening range breakouts, gap strategies, volume signals, cross session momentum, liquidity grabs, volatility conditioned classifiers, and news driven strategies. All signals are assessed using strict institutional criteria  out of sample walk forward validation, minimum T statistic of 2.0, at least 30 trades, positive net return after a fixed two point round trip cost, and multi year stability. No signal satisfies all criteria simultaneously. The gross edge available to next bar open execution is constrained to approximately 0.07 1.50 points per trade, insufficient to overcome transaction costs. A gap continuation signal achieves T   3.23 and  14.52 points but fails minimum sample requirements (N   22). Two validated signals from a separate research program are included as positive controls, confirming the methodology detects genuine edge when present. The primary contribution is a reproducible falsification framework and a documented null result, highlighting structural limits of OHLCV based intraday strategies.

Keywords : 

Abstract :本文测试了在现实执行约束下，从开盘高低收盘量（OHLCV）数据中得出的日内动量信号是否会在Micro-E mini纳斯达克100期货（MNQ）中产生统计上显著的交易优势。使用947个交易日的5分钟数据（2021-2025），评估了14个信号家族，包括开盘区间突破、缺口策略、成交量信号、跨期动量、流动性抓取、波动性条件分类器和新闻驱动策略。所有信号都是使用严格的制度标准进行评估的，即样本外走前验证、最小T统计量为2.0、至少30笔交易、固定两点往返成本后的正净回报和多年稳定性。没有信号同时满足所有标准。下一次开盘执行的总优势限制在每笔交易约0.071.50点，不足以克服交易成本。间隙连续信号达到T 3.23和14.52点，但未达到最低样本要求（N 22）。来自单独研究项目的两个经过验证的信号作为阳性对照，确认该方法在存在时检测到真正的边缘。主要贡献是一个可重复的伪造框架和一个有记录的零结果，突出了基于OHLCV的日内策略的结构局限性。

Keywords :

### 

\[7\] Single Period Portfolio Selection via Information Projection

标题:基于信息预测的单期投资组合选择

作者:Bo-Yu Yang, Michael Gastpar

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03184

Abstract : We study the single period portfolio selection problem under Constant Relative Risk Aversion (CRRA) utility through the information theoretic lens. Assuming only that the market payoff vector has finite support, we show that the Certainty Equivalent (CE) growth rate under CRRA utility can be exactly decomposed into a portfolio induced R nyi divergence term, a R nyi entropy term of the risk tilted market law, and a log partition term. In this setting, the R nyi order has a clear operational meaning  it exactly coincides with the investor s coefficient of relative risk aversion. We further show that CRRA portfolio selection is equivalent to a R nyi information projection problem. Using a variational representation of R nyi divergence, we obtain a Blahut Arimoto style alternating optimization with a closed form auxiliary update and a KL type portfolio step. In the low risk aversion regime, this method empirically requires fewer iterations than both direct CRRA utility optimization and Cover s method.

Keywords : 

Abstract :我们通过信息论的视角研究了恒定相对风险规避（CRRA）效用下的单期投资组合选择问题。仅假设市场收益向量具有有限支持，我们证明了CRRA效用下的确定性等价（CE）增长率可以精确地分解为投资组合诱导的Rnyi散度项、风险倾斜市场定律的Rnyy熵项和对数分割项。在这种情况下，R nyi顺序具有明确的操作意义，它与投资者的相对风险厌恶系数完全一致。我们进一步证明，CRRA投资组合选择等价于R nyi信息投影问题。利用R-nyi散度的变分表示，我们得到了一个Blahut-Arimoto式的交替优化，该优化具有闭式辅助更新和KL型投资组合步骤。在低风险规避机制下，该方法比直接CRRA效用优化和Covers方法需要更少的迭代。

Keywords :

### 

\[8\] Human Provenance Verification should be Treated as Labor Infrastructure in AI Saturated Markets

标题:人类来源验证应被视为人工智能饱和市场中的劳动力基础设施

作者:Erin McGurk, David Khachaturov

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03210

Abstract : We argue that AI saturated markets are likely to create Veblen good premiums, which we term human provenance premiums, for verified human presence, and hence AI governance should treat human provenance verification as labor infrastructure. Generative and agentic AI systems lower the cost of many standardized cognitive, creative, and coordination tasks, weakening the scarcity premiums that have supported much middle tier knowledge work. We argue that this pressure may produce an asymmetric barbell shaped structure of value capture in advanced economies  high volume synthetic production controlled by owners of AI infrastructure at one pole, and scarce, high status human labor valued for verified human presence at the other.We advance three claims. First, AI compresses the value of standardized middle tier labor by making good enough synthetic substitutes scalable at low marginal cost, hollowing out the middle of the skill distribution currently categorized by knowledge work. Second, this compression reallocates demand for human labor toward work valued for its visible human character. We term this performative humanity and distinguish three forms of labor  relational presence, aesthetic provenance, and accountability. Third, as these premiums depend on credible verification, AI governance should treat human provenance systems as labor infrastructure rather than as luxury authenticity labels.To evaluate hybrid human AI work, we propose constitutive human presence as the relevant standard  human labor retains premium value when human judgment, attention, accountability, authorship, or relational participation is not incidental to the output but constitutive of what is being purchased.

Keywords : 

Abstract :我们认为，人工智能饱和的市场可能会为经过验证的人类存在创造凡勃伦良好的溢价，我们称之为人类来源溢价，因此人工智能治理应该将人类来源验证视为劳动力基础设施。生成性和代理性人工智能系统降低了许多标准化的认知、创造性和协调任务的成本，削弱了支持许多中层知识工作的稀缺溢价。我们认为，这种压力可能会在发达经济体中产生一种不对称的杠铃形价值获取结构——一方面是由人工智能基础设施所有者控制的高产量合成生产，另一方面是稀缺的、高地位的劳动力，其价值在于经过验证的人类存在。我们提出三项索赔。首先，人工智能通过使足够好的合成替代品以低边际成本可扩展，压缩了标准化中层劳动力的价值，掏空了目前按知识工作分类的技能分布的中间部分。其次，这种压缩将对人力的需求重新分配给了以可见的人性为价值的工作。我们称之为这种表演性人性，并区分了三种形式的劳动关系存在、审美来源和责任。第三，由于这些溢价取决于可信的验证，人工智能治理应该将人类来源系统视为劳动力基础设施，而不是奢侈品的真实性标签。为了评估混合的人类人工智能工作，我们提出了构成性的人类存在，因为当人类的判断、注意力、问责制、作者身份或关系参与不是产出的附带因素，而是所购买内容的构成因素时，相关的标准人类劳动仍然具有溢价价值。

Keywords :

### 

\[9\] Coordination as an Architectural Layer for LLM Based Multi Agent Systems

标题:协调作为基于LLM的多智能体系统的架构层

作者:Maksym Nechepurenko, Pavel Shuvalov

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03310

Abstract : Multi agent LLM systems fail in production at rates between 41  and 87 , mostly due to coordination defects rather than base model capability. Existing responses split between cataloguing failure modes empirically and shipping declarative orchestration frameworks as engineering tools  neither delivers a principled mapping from coordination configuration to predictable failure mode signature. We argue that coordination should be treated as a configurable architectural layer, separable from agent logic and from information access, enabling architectural reasoning rather than only engineering productivity.We instantiate this with an information controlled design on prediction markets  a single LLM, fixed tools, fixed per call output cap, and fixed prompt template across five reference coordination configurations, with total compute per question treated as an endogenous architectural output. The Murphy decomposition of the Brier score separates calibration from discriminative power, so configurations leave distinguishable signatures even when aggregate scores coincide.On 100 Polymarket binary markets resolved after the model s training cutoff (claude opus 4 6) we report Murphy signatures, a cost quality Pareto frontier, category conditioned analysis, and a bootstrap power projection. Three of five pre specified predictions are upheld in direction  two configurations dominate the Pareto frontier within this regime  exploratory bootstrap intervals separate consensus alignment from others, though pairwise tests do not survive Bonferroni correction at n 100. We also deploy the same configurations as live agents on Foresight Arena under web search enabled conditions, as an on chain replication channel accumulating in parallel. Harness, trace dataset, and production agents are released. We position this as a methodology validating first instantiation, not a general cross model claim.

Keywords : 

Abstract :多代理LLM系统在生产中的失败率在41到87之间，主要是由于协调缺陷而不是基础模型能力。现有的响应分为经验编目故障模式和作为工程工具发布声明性编排框架，两者都没有提供从协调配置到可预测故障模式特征的原则映射。我们认为，协调应该被视为一个可配置的架构层，与代理逻辑和信息访问分开，实现架构推理，而不仅仅是工程生产力。我们在预测市场上用一个信息控制的设计来实例化这一点——一个单一的LLM、固定的工具、固定的每次调用输出上限和固定的提示模板，横跨五个参考协调配置，每个问题的总计算量被视为内生架构输出。Brier分数的Murphy分解将校准与判别能力分开，因此即使总分数一致，配置也会留下可区分的特征。在模型训练截止后解决的100个Polymarket二元市场（claude opus 4 6）上，我们报告了墨菲特征、成本质量帕累托前沿、类别条件分析和自举幂投影。五个预先指定的预测中有三个在两种配置主导帕累托前沿的方向上得到了支持——探索性引导区间将共识对齐与其他区间分开，尽管成对测试在n 100的Bonferroni校正中无法存活。我们还部署了与Foresight Arena上启用web搜索条件下的实时代理相同的配置，作为并行积累的链上复制通道。发布了线束、跟踪数据集和生产代理。我们将其定位为验证第一个实例化的方法，而不是一般的跨模型声明。

Keywords :

### 

\[10\] Scaling Limits of Bivariate Nearly Unstable Hawkes Processes and Applications to Rough Volatility

标题:二元近似不稳定霍克斯过程的标度极限及其在粗糙波动中的应用

作者:Sohaib El Karmi

来源:ARXIV\_20260506

链接:https://arxiv.org/pdf/2605.03703

Abstract : We prove a functional limit theorem for a pair of nearly unstable Hawkes processes coupled through a triangular cross excitation mechanism, when the two kernels have distinct heavy tail exponents. This heterogeneous regime produces two different degrees of roughness and, to the best of our knowledge, had not previously been treated in the multivariate nearly unstable setting.As the system approaches criticality, the renormalized intensity processes converge weakly to the unique solution of a coupled stochastic Volterra system driven by two independent Brownian motions. The first component evolves autonomously as a rough fractional diffusion, while the second is driven both by its own noise and by the first component through a convolution cross kernel. This kernel, expressed as the convolution of the two associated Mittag Leffler kernels, encodes both roughness exponents and distinguishes the limit from independent univariate limits or classical bivariate Brownian models.We also derive a short time decorrelation result showing that the functional correlation between the two limiting components vanishes at an explicit polynomial rate governed by the rougher component. Finally, we show that the scale matching assumption is not structural  without it, the limiting cross kernel is replaced by an explicitly time rescaled convolution kernel. The proof combines kernel convergence, tightness, martingale identification via Rebolledo s theorem, and uniqueness for affine stochastic Volterra equations.

Keywords : 

Abstract :当两个核具有不同的重尾指数时，我们证明了通过三角交叉激励机制耦合的一对几乎不稳定的霍克斯过程的函数极限定理。这种异质性机制产生了两种不同程度的粗糙度，据我们所知，在多元几乎不稳定的环境中以前从未被处理过。当系统接近临界状态时，重整化强度过程弱收敛到由两个独立布朗运动驱动的耦合随机Volterra系统的唯一解。第一个分量作为粗略的分数扩散自主演化，而第二个分量则由其自身的噪声和第一个分量通过卷积交叉核驱动。该核表示为两个相关的Mittag-Leffler核的卷积，对粗糙度指数进行编码，并将该极限与独立的单变量极限或经典的双变量布朗模型区分开来。我们还得到了一个短时解相关结果，表明两个极限分量之间的函数相关性在由较粗糙分量控制的显式多项式速率下消失。最后，我们证明，没有它，尺度匹配假设就不是结构化的，限制交叉核被显式时间重新缩放的卷积核所取代。该证明结合了核收敛性、紧密性、通过Rebolledo定理的鞅识别和仿射随机Volterra方程的唯一性。

Keywords :

### 

\[11\] ESG as Priced Crash Insurance

标题:ESG作为定价崩溃保险

作者:Jiayu Yi, Minxuan Hu, Wenxi Sun, Ziheng Chen

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04479

Abstract : This research establishes ESG as a state dependent insurance mechanism against equity crashes by addressing the decoupling of unconditional alpha from tail risk resilience. By validating market stress regimes as distinct economic states through a drawdown based truncation rule, the study demonstrates that high ESG ratings materially reduce the incidence of discrete crash events during systemic drawdowns. To address the selection bias and high dimensional confounding inherent in traditional linear frameworks, we implement Double Machine Learning as a structural deconfounding layer. Unlike simple predictive modeling, the Double Machine Learning framework utilizes machine learning to handle complex nuisance parameters, allowing us to isolate the asymmetric treatment effects of ESG across different market states. Distributional analysis reveals the underlying mechanism as ESG specifically attenuates the severity of realized tail losses at the most adverse quantiles instead of shifting the entire return distribution. Confirmed by structural estimates, this protection functions as priced insurance that incurs performance drags during stable periods while providing critical resilience when tail risks are most acute.

Keywords : 

Abstract :本研究通过解决无条件阿尔法与尾部风险弹性的脱钩问题，将ESG确立为一种针对股票崩盘的国家依赖保险机制。通过基于缩减的截断规则将市场压力制度验证为不同的经济状态，该研究表明，高ESG评级大大降低了系统性缩减期间离散崩溃事件的发生率。为了解决传统线性框架中固有的选择偏差和高维混淆问题，我们将双机器学习作为一个结构解卷积层来实现。与简单的预测建模不同，双机器学习框架利用机器学习来处理复杂的干扰参数，使我们能够隔离ESG在不同市场状态下的不对称处理效应。分布分析揭示了潜在的机制，因为ESG在最不利的分位数上专门减弱了已实现尾部损失的严重程度，而不是改变整个回报分布。经结构性估计证实，这种保护起到了定价保险的作用，在稳定时期会带来业绩拖累，而在尾部风险最严重时则提供关键的弹性。

Keywords :

### 

\[12\] Dynamic Collateral Control for Permissionless Spot Perpetual Basis Trading

标题:无许可现货永续基差交易的动态抵押品控制

作者:Anatoly Krestenko, Mikhail Butov, Rostislav Berezovskiy, Danila Bolotin

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.05089

Abstract : We study permissionless spot  perpetual basis trading in decentralized finance as a collateral control problem. The strategy holds spot inventory, hedges directional exposure with a short perpetual, and allocates capital between spot inventory and derivative margin under on chain liquidity and execution frictions.The paper delivers three results. First, it solves a static control problem for the collateral share and shows that the risk constrained formulation provides a more robust operating benchmark relative to the economic optimum. In comparative calibration, the required collateral rises monotonically under volatility stress. The collateral is the lowest for BTC and increases significantly for long tail assets such as LINK and DOGE. Second, the paper derives an asymmetric dynamic extension in which the lower boundary of intervention is solvency driven, and the upper boundary is determined by a trade off between carry loss and the cost of rebalancing. Monte Carlo simulation shows that the lower boundary remains structurally relevant, whereas meaningful interior upper triggers survive mainly in the regimes with high carry and low costs. Third, the paper validates an execution aware implementation with live routed execution and historical backtests. The execution layer shows that the realized wedges are significant, but become worse in the case of selling the basis. This justifies a minimum effective rebalancing size and a positive execution buffer. The historical validation shows that in the case of a fixed control rule the realized performance is predominantly explained by the funding environment.

Keywords : 

Abstract :我们将去中心化金融中的无许可现货永续基交易作为抵押品控制问题进行研究。该策略持有现货库存，以短期永久性对冲定向风险敞口，并在链上流动性和执行摩擦下在现货库存和衍生品保证金之间分配资本。本文给出了三个结果。首先，它解决了抵押品份额的静态控制问题，并表明风险约束公式相对于经济最优值提供了一个更稳健的操作基准。在比较校准中，所需抵押品在波动压力下单调上升。BTC的抵押品最低，而LINK和DOGE等长尾资产的抵押品则大幅增加。其次，本文推导了一个不对称的动态扩展，其中干预的下限是由偿付能力驱动的，上限是由账面损失和再平衡成本之间的权衡决定的。蒙特卡洛模拟表明，下边界在结构上仍然相关，而有意义的内部上触发主要在高携带和低成本的情况下存在。第三，本文通过实时路由执行和历史回溯测试验证了一个执行感知实现。执行层显示，实现的楔形是显著的，但在卖出基差的情况下会变得更糟。这证明了最小有效再平衡大小和正执行缓冲区是合理的。历史验证表明，在固定控制规则的情况下，实现的绩效主要由资金环境来解释。

Keywords :

### 

\[13\] The Demand Externality of Automation

标题:自动化的需求外部性

作者:Erhan Bayraktar

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.05127

Abstract : Automation raises productivity and reduces paid human labor, but it also reallocates income and ownership claims. This paper studies that tradeoff in a static benchmark and in a stationary heterogeneous agent general equilibrium. Firms choose automation from a profit function. Households differ by skill and wealth, save in a capital equity claim, and face incomplete insurance. Wages and returns are determined by market clearing from a Cobb  Douglas final good firm, while the wealth distribution is pinned down by a Hamilton  Jacobi  Bellman (HJB) equation and a Kolmogorov forward equation (KFE). The paper is deliberately two sided. With strong productivity growth, high skill complementarity, low obsolescence, and broad ownership, automation raises output, capital, and consumption. With strong exposure of low wealth, high marginal propensity to consume (high MPC) households and concentrated ownership, privately chosen automation can be excessive even though it raises high skilled labor income. The central object is the derivative of household consumption demand and collective wage bill with respect to automation. Fiscal policy is modeled as a government problem rather than as an abstract planner  a tax changes the firm s automation first order condition, raises revenue only on the remaining automation base, and must specify rebates and administrative losses.

Keywords : 

Abstract :自动化提高了生产率，减少了有偿人力，但也重新分配了收入和所有权要求。本文研究了静态基准和静态异构代理一般均衡中的权衡。企业从利润函数中选择自动化。家庭因技能和财富而异，除了资本权益索赔，还面临不完整的保险。工资和回报由Cobb-Douglas最终好公司的市场清算决定，而财富分配则由Hamilton-Jacobi-Bellman（HJB）方程和Kolmogorov远期方程（KFE）确定。这篇论文故意两面性。凭借强劲的生产力增长、高技能互补性、低淘汰率和广泛的所有权，自动化提高了产出、资本和消费。由于低财富、高边际消费倾向（高MPC）家庭和集中所有权的强烈暴露，即使提高了高技能劳动力的收入，私人选择的自动化也可能是过度的。中心对象是家庭消费需求和集体工资账单在自动化方面的导数。财政政策被建模为政府问题，而不是抽象的规划者。税收改变了公司的自动化第一秩序条件，仅在剩余的自动化基础上增加收入，并且必须指定退税和行政损失。

Keywords :

### 

\[14\] What Can Go Wrong During Caplet Stripping  

标题:剥去帽子时会出什么问题

作者:Fabien Le Floc'h

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.05140

Abstract : We study exact and near exact extraction of caplet volatilities from market cap quotes and identify why some common choices produce extreme oscillations or negative vols. Interpolation scheme and node placement are shown to be the primary drivers of instability, which can be amplified by isolated bad quotes. We propose practical, production ready remedies  continuous flat linear and C1 flat smooth kernels that preserve bootstrap equivalence, midpoint node placement with a global solver, positivity enforcement via an exponential reparametrization or Hyman non negative C1 splines. We also introduce simple data quality checks. Numerical experiments demonstrate substantially reduced oscillations, robust positive caplet curves, and negligible repricing error, delivering a fast and stable caplet stripping workflow suitable for real world use.

Keywords : 

Abstract :我们研究了从市值报价中精确和接近精确地提取caplet波动率，并确定了为什么一些常见的选择会产生极端振荡或负波动率。插值方案和节点放置被证明是不稳定性的主要驱动因素，孤立的坏报价会放大这种不稳定性。我们提出了实用的、生产就绪的补救措施——连续平坦线性和C1平坦平滑核，这些核保持了自举等价性，使用全局求解器放置中点节点，通过指数重参数化或Hyman非负C1样条实现正性强制。我们还引入了简单的数据质量检查。数值实验表明，振荡大大减少，稳健的正caplet曲线和可忽略的重新定价误差，提供了一种适用于现实世界的快速稳定的caplet剥离工作流程。

Keywords :

### 

\[15\] Optimal Semiparametric Dynamic Pricing with Feature Diversity

标题:具有特征多样性的最优半参数动态定价

作者:Jinhang Chai, Yaqi Duan, Jianqing Fan, Kaizheng Wang

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04207

Abstract : We study contextual dynamic pricing under a semiparametric demand model in which the purchase probability is  1 F(p m( mathbf x )) , where  m( mathbf x )  captures mean utility as a function of product features and buyer covariates, and  F  is an unknown market noise distribution. Existing methods either incur suboptimal regret or rely on restrictive structural assumptions. We propose a stagewise greedy pricing algorithm that iteratively refines the estimate of  F  via local polynomial regression while pricing greedily with current estimates. By exploiting feature diversity, the algorithm reuses endogenous samples collected during exploitation for nonparametric estimation, avoiding costly global random exploration used in prior work.We establish a general regret bound that applies to any estimator   hat m  of the utility function, and derive explicit rates for linear, nonparametric additive, and sparse linear classes of  m . For the linear class, our regret scales as  T   max  1 2, ,3 (2 beta 1)    , where   beta  is the smoothness of  F  and  T  is the time horizon. This improves the best known rates for semiparametric contextual pricing and achieves the parametric   sqrt T   rate when   beta  ge 5 2 . We further prove a matching lower bound, showing the optimality of our rate, and present numerical experiments that corroborate the theory and demonstrate the practical advantages of iterative refinement.

Keywords : 

Abstract :我们研究了半参数需求模型下的情境动态定价，其中购买概率为1 F（p m（mathbf x）），其中m（mattbf x）捕获了作为产品特征和买方协变量函数的平均效用，F是一个未知的市场噪声分布。现有的方法要么产生次优的遗憾，要么依赖于限制性的结构假设。我们提出了一种分阶段贪婪定价算法，该算法通过局部多项式回归迭代改进F的估计，同时用当前估计贪婪定价。通过利用特征多样性，该算法重用了在利用过程中收集的内生样本进行非参数估计，避免了先前工作中使用的昂贵的全局随机探索。我们建立了一个适用于效用函数的任何估计量hat m的一般遗憾界，并推导出了m的线性、非参数加性和稀疏线性类的显式速率。对于线性类，我们的遗憾尺度为T max 1,2,3（2 beta 1），其中beta是F的平滑度，T是时间范围。这提高了半参数上下文定价的最佳已知费率，并在beta ge 5 2时实现了参数sqrt T费率。我们进一步证明了匹配下限，显示了我们速率的最优性，并给出了数值实验，证实了理论并证明了迭代精化的实际优势。

Keywords :

### 

\[16\] DAO enabled decentralized physical AI

标题:支持DAO的去中心化物理AI

作者:Mark C. Ballandies, Florian Spychiger, Uwe Serdült, Claudio J. Tessone

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04522

Abstract : We propose DAO enabled decentralized physical AI (DePAI), a democratic architecture for coordinating humans and autonomous machines in the operation and governance of physical digital systems. We (1) synthesize foundations in blockchains, decentralized autonomous organizations (DAOs), and cryptoeconomics  (2) connect DAO design with digital democracy research on deliberation and voting, showing how each can advance the other  (3) position DAO governed decentralized physical infrastructure networks (DePIN) within a vertically integrated stack that links energy and sensing to connectivity, storage compute, models, and robots  (4) show how these elements specify workflows that couple machine execution with human oversight, enabling enhanced self organization of techno socio economic systems, which we call DePAI  and (5) analyze risks, including security, centralization, incentive failure, legal exposure, and the crowding out of intrinsic motivation, and argue for value sensitive design and continuously adaptive governance. DePAI offers a path to scalable, resilient self organization that integrates physical infrastructure, AI, and community ownership under transparent rules, on chain incentives, and permissionless participation, aiming to preserve human autonomy.

Keywords : 

Abstract :我们提出了DAO支持的去中心化物理人工智能（DePAI），这是一种在物理数字系统的操作和治理中协调人类和自主机器的民主架构。我们（1）综合区块链、去中心化自治组织（DAO）和加密经济学的基础（2）将DAO设计与关于审议和投票的数字民主研究联系起来，展示了两者如何相互促进（3）将DAO管理的去中心化物理基础设施网络（DePIN）定位在垂直集成的堆栈中，将能源和传感与连接、存储计算、模型和机器人联系起来（4）展示了这些元素如何指定将机器执行与人类监督相结合的工作流程，从而增强技术社会经济系统的自组织性，我们称之为DePAI；（5）分析风险，包括安全性、集中化、激励失败、法律风险和内在动机的挤出，并主张价值敏感的设计和持续自适应的治理。DePAI提供了一条可扩展、有弹性的自组织之路，在透明的规则、链上激励和无需许可的参与下，将物理基础设施、人工智能和社区所有权整合在一起，旨在维护人类的自主权。

Keywords :

### 

\[17\] Learning Time Inhomogeneous Markov Dynamics in Financial Time Series via Neural Parameterization

标题:通过神经参数化学习金融时间序列中的时间非齐次马尔可夫动力学

作者:Jan Rovirosa, Jesse Schmolze

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04690

Abstract : Modeling the dynamics of non stationary stochastic systems requires balancing the representational power of deep learning with the mathematical transparency of classical models. While classical Markov transition operators provide explicit, theoretically grounded rules for system evolution, their empirical estimation collapses due to severe data sparsity when applied to high resolution, high noise environments. We explore this statistical barrier using financial time series as a canonical, real world testbed. To overcome the degeneracy of empirical counting, we introduce a framework that utilizes neural networks strictly as parameterization engines to generate explicit, time varying Markov transition matrices. By constraining the neural network to output its predictions as a formal stochastic operator, we maintain complete structural interpretability. We demonstrate that these learned operators successfully capture complex regime shifts  the state conditioned model achieves mean row heterogeneity   bar  rho    0.0073  while the state free ablation collapses to exactly zero, and operator row entropy correlates with realized variance at  r    0.62  ( p  approx 10   251  ), revealing that high volatility regimes homogenize transition dynamics rather than diversify them. Furthermore, rather than enforcing the Chapman Kolmogorov equations as a rigid structural requirement, we repurpose them as a localized diagnostic tool to pinpoint specific temporal windows where first order memory assumptions break down. Ultimately, this framework demonstrates how neural networks can be constrained to make rigorous, classical operator analysis viable for complex real world time series.

Keywords : 

Abstract :对非平稳随机系统的动力学建模需要平衡深度学习的表征能力和经典模型的数学透明度。虽然经典的马尔可夫转移算子为系统演化提供了明确的、有理论依据的规则，但当应用于高分辨率、高噪声环境时，由于严重的数据稀疏性，它们的经验估计会崩溃。我们使用金融时间序列作为规范的现实世界测试平台来探索这一统计障碍。为了克服经验计数的退化，我们引入了一种框架，该框架严格利用神经网络作为参数化引擎来生成显式的时变马尔可夫转移矩阵。通过约束神经网络将其预测作为形式随机算子输出，我们保持了完全的结构可解释性。我们证明，这些学习到的算子成功地捕捉到了复杂的制度变迁——状态条件模型实现了平均行异质性棒rho 0.0073，而无状态消融则完全崩溃为零，算子行熵与r 0.62的实现方差相关（p约为10251），这表明高波动性制度使过渡动态均匀化，而不是多样化。此外，我们没有将Chapman-Kolmogorov方程强制作为刚性结构要求，而是将其重新用作局部诊断工具，以确定一阶记忆假设失效的特定时间窗口。最终，该框架展示了如何约束神经网络，使严格的经典算子分析适用于复杂的现实世界时间序列。

Keywords :

### 

\[18\] Lithium enrichment threatens to curb fusion deployment

标题:锂浓缩威胁到核聚变部署

作者:Samuel H. Ward, Richard J. Pearson, Thomas B. Scott, Niek J. Lopes Cardozo

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04707

Abstract : The impact of lithium isotopic enrichment on the global deployment of nuclear fusion energy is analysed. Lithium   the 6Li isotope in particular   is essentially one of two elemental fuels required by fusion reactors for tritium breeding. Whilst variable consumption of lithium is low enough to present negligible cost, it is instead the large stored inventory volume (50 100 tonnes) and its required enrichment that compound to significantly drive capital costs. These costs are driven by the inefficiency of the tritium breeding process, making this challenge fundamental to almost all fusion power plant concepts. Financing would further compound these effects, making lithium fusion fuels more akin to an upfront capital expenditure than operational expenditure.Other potential barriers to fusion deployment created by lithium are also discussed  enrichment technologies of today are shown to be too expensive, not scalable, and environmentally risky, and highly enriched 6Li is a controlled substance. Mitigating actions include  developing alternative enrichment technologies that are affordable, scalable, and do not rely on mercury  incorporating lithium enrichment as an explicit cost driver in reactor design processes, producing more compact reactors with smaller lithium inventories  establishing distinct enrichment levels to enable supply chain monitoring for misuse  and the most radical solution  breeding blankets that use natural, unenriched lithium. These actions may impact tritium breeding capabilities, which calls for an urgent re assessment of the tritium breeding paradigm. Whatever solution is sought, lithium supply is a mission critical issue that needs urgently addressing.

Keywords : 

Abstract :分析了锂同位素富集对全球核聚变能源部署的影响。锂，特别是6Li同位素，基本上是聚变反应堆用于氚繁殖所需的两种元素燃料之一。虽然锂的可变消耗量低到可以忽略不计的成本，但正是大量的储存库存量（50100吨）及其所需的富集量大大推动了资本成本。这些成本是由氚增殖过程的低效率驱动的，这使得这一挑战对几乎所有的聚变发电厂概念都至关重要。融资将进一步加剧这些影响，使锂聚变燃料更类似于前期资本支出，而不是运营支出。还讨论了锂对聚变部署造成的其他潜在障碍。目前的浓缩技术被证明过于昂贵、不可扩展且具有环境风险，而高浓缩的6Li是一种受控物质。缓解行动包括开发负担得起、可扩展的替代浓缩技术，并且不依赖于将含汞锂浓缩作为反应堆设计过程中的明确成本驱动因素，生产锂库存较小的更紧凑的反应堆，建立不同的浓缩水平，以使供应链能够监测滥用情况，以及使用天然、未富锂的最激进的解决方案繁殖毯。这些行动可能会影响氚的繁殖能力，这需要紧急重新评估氚的繁殖模式。无论寻求何种解决方案，锂供应都是一个迫切需要解决的关键任务问题。

Keywords :

### 

\[19\] A Review of Large Language Models for Stock Price Forecasting from a Hedge Fund Perspective

标题:对冲基金视角下股票价格预测的大型语言模型综述

作者:Olivia Zhang, Zhilin Zhang

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.05211

Abstract : Large language models (LLMs) are increasingly deployed in quantitative finance for stock price forecasting. This review synthesizes recent applications of LLMs in this domain, including extracting sentiment from financial news and social media, analyzing financial reports and earnings call transcripts, tokenizing or symbolizing stock price series, and constructing multi agent trading systems. Particular attention is paid to practical pitfalls that are often understated in the literature, such as fragility in sentiment analysis, dataset and horizon design, performance evaluation metrics, data leakage, illiquidity premia, and limits of stock price predictability. Organized from a hedge fund perspective, the review is intended to guide both academic researchers and hedge fund managers in integrating LLMs into real world trading pipelines and in stress testing their robustness under realistic market frictions.

Keywords : 

Abstract :大型语言模型（LLM）越来越多地用于股票价格预测的定量金融。本综述综合了LLM在该领域的最新应用，包括从财经新闻和社交媒体中提取情感，分析财务报告和电话财报会议记录，标记或象征股价序列，以及构建多代理交易系统。特别关注文献中经常被低估的实际陷阱，如情绪分析的脆弱性、数据集和视野设计、绩效评估指标、数据泄漏、非流动性溢价和股价可预测性的限制。该评论从对冲基金的角度组织，旨在指导学术研究人员和对冲基金经理将LLM整合到现实世界的交易管道中，并在现实市场摩擦下对其稳健性进行压力测试。

Keywords :

### 

\[20\] Artificial Aesthetics

标题:人工美学

作者:Arbaaz Karim

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.05578

Abstract : Aesthetic qualities command measurable premiums in traditional goods markets. However, it remains unclear whether users are willing to pay for such qualities in AI generated text. This paper estimates the willingness to pay for aesthetic attributes in large language model outputs using an online experiment with N   117 participants. Participants evaluated responses from four anonymized models across academic, professional, and personal contexts, rated outputs along multiple dimensions, and submitted bids for access using a Becker DeGroot Marschak (BDM) mechanism. We find no statistically significant relationship between perceived aesthetic quality and willingness to pay. While participants systematically distinguish between outputs and exhibit consistent preferences over stylistic features, these differences do not translate into higher monetary valuation. Further analysis shows that aesthetic and functional attributes load onto a single latent factor, suggesting that users perceive quality as a unified construct rather than a separable aesthetic dimension. These results imply that, in current large language model (LLM) markets, aesthetic improvements function as baseline expectations rather than sources of price differentiation.

Keywords : 

Abstract :审美品质在传统商品市场上获得了可观的溢价。然而，目前尚不清楚用户是否愿意在人工智能生成的文本中为这些质量付费。本文使用N 117名参与者的在线实验，估计了大型语言模型输出中为美学属性付费的意愿。参与者评估了四个匿名模型在学术、专业和个人背景下的反应，对多个维度的输出进行了评分，并使用Becker-DeGroot-Marschak（BDM）机制提交了访问投标。我们发现，感知的审美质量与支付意愿之间没有统计学上的显著关系。虽然参与者系统地区分了产出，并对风格特征表现出一致的偏好，但这些差异并没有转化为更高的货币估值。进一步的分析表明，美学和功能属性加载到一个潜在因素上，这表明用户将质量视为一个统一的结构，而不是一个可分离的美学维度。这些结果表明，在当前的大型语言模型（LLM）市场中，审美改进起着基线预期的作用，而不是价格差异的来源。

Keywords :

### 

\[21\] Numerical methods for lambda quantiles

标题:lambda分位数的数值方法

作者:Ilaria Peri, Linus Wunderlich

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06220

Abstract : Lambda quantiles, originally introduced as lambda value at risk, generalise the classical value at risk by allowing for a variable confidence level. This work presents efficient algorithms for computing lambda quantiles and demonstrates their application in portfolio optimisation. We first develop a robust algorithm,   Lambda  Newton Bis, that combines Newton s method with a bisection strategy to ensure global convergence. The algorithm handles potential discontinuities and achieves local quadratic convergence under standard regularity assumptions. To address cases with multiple roots, we also propose an interval analysis approach. We then demonstrate the algorithm s computational efficiency and practical relevance within a portfolio optimization framework. To this end, we develop two alternative solution methods that incorporate the   Lambda  Newton Bis procedure. Numerical experiments confirm the algorithm s convergence properties and highlight its computational advantages in optimization tasks based on lambda quantiles.

Keywords : 

Abstract :λ分位数最初被引入为风险λ值，通过允许可变的置信水平来推广经典的风险值。这项工作提出了计算lambda分位数的有效算法，并演示了它们在投资组合优化中的应用。我们首先开发了一种鲁棒算法，Lambda-Newton-Bis，它将牛顿方法与二分法策略相结合，以确保全局收敛。该算法处理潜在的不连续性，并在标准正则性假设下实现局部二次收敛。为了解决具有多个根的情况，我们还提出了一种区间分析方法。然后，我们在投资组合优化框架内展示了该算法的计算效率和实际相关性。为此，我们开发了两种包含Lambda-Newton-Bis过程的替代解决方案。数值实验证实了该算法的收敛性，并突出了其在基于lambda分位数的优化任务中的计算优势。

Keywords :

### 

\[22\] Funding Aware Optimal Market Making for Perpetual DEXs

标题:永续DEX的资金意识优化做市

作者:Nam Anh Le

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06405

Abstract : This paper studies optimal liquidity provision for perpetual contracts when the funding rate is a stochastic state variable. The core extension to classical market making is the coupling between inventory and funding payments  inventory creates both mark to market exposure and a state dependent funding cash flow. A reduced inventory funding control problem is formulated, solved with a monotone finite difference Hamilton Jacobi Bellman scheme, and bid and ask quote offsets are recovered from discrete inventory value differences. Funding is calibrated on Hyperliquid ETH, BTC, and SOL perpetual data. Gaussian OU funding is retained as a tractable diffusion baseline, while OU plus jump diagnostics document the heavy tailed funding innovations that should enter a future extension. In 100 seed holdout simulations under two official fill proxy calibrations, the funding aware HJB improves mean ETH BTC performance while lowering inventory RMS relative to classical Avellaneda Stoikov. SOL gains are positive versus unscaled AS but are not a Pareto improvement once a risk scaled AS diagnostic is included.

Keywords : 

Abstract :本文研究了当融资率为随机状态变量时，永续合约的最优流动性准备金。经典做市的核心延伸是库存和资金支付之间的耦合——库存既产生了按市值计价的风险敞口，也产生了依赖于国家的资金现金流。提出了一个简化的库存资金控制问题，用单调有限差分Hamilton-Jacobi-Bellman方案求解，并从离散的库存价值差异中恢复买卖报价偏移。资金根据Hyperliquit ETH、BTC和SOL永久数据进行校准。高斯OU资金被保留为可处理的扩散基线，而OU加跳跃诊断记录了应该进入未来扩展的重尾资金创新。在两次官方填充代理校准下的100次种子拒绝模拟中，资金意识强的HJB提高了ETH BTC的平均性能，同时相对于经典的Avellaneda Stoikov降低了库存RMS。与非标度AS相比，SOL收益是积极的，但一旦纳入风险标度AS诊断，就不是帕累托改进。

Keywords :

### 

\[23\] A Geometry Aware Residual Correction of Hagan s SABR Implied Volatility Formula

标题:Hagan SABR隐含波动率公式的几何感知残差校正

作者:Adil Reghai, Lama Tarsissi, Gérard Biau, Alex Lipton

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06604

Abstract : This paper proposes a hybrid methodology to improve the approximation of SABR (Stochastic Alpha Beta Rho) implied volatility by combining analytical structure with machine learning. The approach augments the neural network input representation with geometric features derived from the stochastic differential equations of the SABR model. Unlike approaches that fully replace analytical formulas with black box models, the proposed framework preserves the analytical backbone of the model. The hybridization operates along two complementary dimensions. First, geometry aware variables reflecting intrinsic properties of the SABR dynamics are used as structured inputs to the network. Second, the neural network is trained to learn the residual error relative to Hagan s closed form approximation rather than implied volatility directly. The resulting model acts as a structured residual correction to the analytical formula, retaining interpretability while capturing higher order effects that are not included in the asymptotic expansion. Numerical experiments conducted over realistic parameter domains, as well as stressed environments, show that the method improves accuracy and robustness compared with both analytical approximations and standard neural network approaches. Because the correction remains lightweight and structurally consistent with the underlying model, the framework is well suited for real time pricing and calibration in practical trading environments.

Keywords : 

Abstract :本文提出了一种混合方法，通过将分析结构与机器学习相结合来提高SABR（随机阿尔法贝塔Rho）隐含波动率的近似值。该方法利用从SABR模型的随机微分方程中导出的几何特征来增强神经网络输入表示。与用黑盒模型完全取代分析公式的方法不同，所提出的框架保留了模型的分析支柱。杂交沿着两个互补的维度进行。首先，将反映SABR动力学内在特性的几何感知变量用作网络的结构化输入。其次，训练神经网络以学习相对于Hagan闭式近似的残差，而不是直接学习隐含波动率。由此产生的模型充当了对分析公式的结构化残差校正，在保留可解释性的同时捕获了渐近展开中未包含的高阶效应。在真实参数域以及压力环境中进行的数值实验表明，与解析近似和标准神经网络方法相比，该方法提高了准确性和鲁棒性。由于修正仍然很轻，并且在结构上与基础模型一致，因此该框架非常适合在实际交易环境中进行实时定价和校准。

Keywords :

### 

\[24\] Frustrated Dynamics of Distance Matrices

标题:距离矩阵的受阻动力学

作者:Igor Halperin

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.05376

Abstract : We introduce the Frustrated Distance Matrix (FDM) model, a dynamic extension of the static distance matrix ensemble on S 2 analyzed by Bogomolny, Bohigas, and Schmit (BBS). Its entries are pairwise geodesic distances between N Brownian particles on the sphere evolving under quenched random pairwise couplings linear in those distances. Where the static BBS theory recovers geometric information about the underlying manifold from spectra of distance matrices on i.i.d.  samples, the time resolved FDM spectrum carries information about structural changes of the underlying point process. The particle dynamics realize one such change  a fast collapse from a uniform configuration onto a one dimensional ring, followed by slow rotational drift of the ring orientation  the particle level picture provides the ground truth against which spectral diagnostics are calibrated. We find that the static BBS template is preserved at every time, with the dynamics entering as a redistribution of spectral mass within that template, sharp enough to flag ring formation. We propose self averaging of the bulk density as the mechanism behind this preservation, verified by an i.i.d. resample comparison, and extract a small set of spectral diagnostics of the structural change computable from the distance matrix alone. We suggest that our diagnostics can be applied in other similar inverse problem settings  financial correlation matrices, graph and network adjacency spectra, similarity matrices in molecular dynamics, and dynamics on parameter manifolds.

Keywords : 

Abstract :我们介绍了受阻距离矩阵（FDM）模型，这是Bogomolny、Bohigas和Schmit（BBS）分析的S2上静态距离矩阵集成的动态扩展。它的条目是球体上N个布朗粒子之间的成对测地线距离，这些距离在淬火随机成对耦合下呈线性演化。当静态BBS理论从i.i.d.样本上的距离矩阵谱中恢复关于基础流形的几何信息时，时间分辨的FDM谱携带了关于基础点过程结构变化的信息。粒子动力学实现了一个这样的变化——从均匀配置到一维环上的快速坍缩，随后环取向的缓慢旋转漂移——粒子级图像提供了校准光谱诊断所依据的基本事实。我们发现，静态BBS模板每次都被保留下来，动力学作为该模板内光谱质量的重新分布而进入，其剧烈程度足以标记环的形成。我们提出体积密度的自平均作为这种保存背后的机制，并通过i.i.d.重采样比较进行了验证，并提取了一组仅可从距离矩阵计算的结构变化的光谱诊断。我们建议我们的诊断可以应用于其他类似的逆问题设置——金融相关矩阵、图和网络邻接谱、分子动力学中的相似性矩阵和参数流形上的动力学。

Keywords :

### 

\[25\] Multi Dimensional Behavioral Evaluation of Agentic Stock Prediction Systems Using LLM Judges with Closed Loop Reinforcement Learning Feedback

标题:基于闭环强化学习反馈的LLM判断的代理股票预测系统多维行为评价

作者:Mohammad Al Ridhawi, Mahtab Haj Ali, Hussein Al Osman

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.05739

Abstract : Agentic stock prediction systems make sequences of interdependent decisions (regime detection, pathway routing, reinforcement learning control) whose individual quality is hidden by aggregate metrics such as mean absolute percentage error (MAPE) or directional accuracy. We present a behavioral evaluation framework that addresses this gap. Behavioral traces logged at every autonomous decision point are grouped into five day episodes and scored along six domain specific dimensions (regime detection, routing, adaptation, risk calibration, strategy coherence, error recovery) by an ensemble of three large language model (LLM) judges (GPT 5.4, Claude 4.6 Opus, Gemini 3.1 Pro). Perturbation based validation on 420 episodes yields targeted score drops of   1.6  to   2.4  on intended dimensions versus an average of   0.32  on the remaining five, with cross model agreement up to Krippendorff s   alpha   0.85 . The composite behavioral score, used here only for cross episode reporting, correlates at   rho   0.72  with realized 20 day Sharpe ratio from offline backtesting. Closing the loop, the framework converts deficient per dimension scores into a credit assigned penalty term added to the Soft Actor Critic (SAC) reward. Three short fine tuning cycles, all confined to the validation period, produce on the held out 2017 2025 test period a one day MAPE reduction from 0.61  to 0.54  (an 11.5  relative reduction   p 0.001 , Cohen s  d 0.31 ), a directional accuracy increase from 71  to 74 , and an 18  Sharpe ratio improvement (95  bootstrap CI  8.2 , 27.4  ), with gains concentrated in high volatility episodes where the original system was most behaviorally deficient. Results are from offline backtesting and do not address effects specific to live deployment.

Keywords : 

Abstract :代理股票预测系统做出一系列相互依存的决策（状态检测、路径选择、强化学习控制），其个体质量被平均绝对百分比误差（MAPE）或方向精度等聚合指标所掩盖。我们提出了一个行为评估框架来解决这一差距。在每个自主决策点记录的行为痕迹被分为五天的事件，并由三名大型语言模型（LLM）法官（GPT 5.4、Claude 4.6 Opus、Gemini 3.1 Pro）组成的团队沿六个领域特定维度（制度检测、路由、适应、风险校准、策略连贯性、错误恢复）进行评分。对420个事件进行基于扰动的验证，在预期维度上的目标得分下降1.6至2.4，而在其余五个维度上的平均得分下降0.32，跨模型一致性高达Krippendorffα0.85。这里仅用于跨发作报告的复合行为评分与离线回溯测试的20天夏普比率相关，相关系数为0.72。在循环结束时，该框架将每个维度的不足分数转换为添加到软演员评论家（SAC）奖励中的信用分配惩罚项。三个短的微调周期，均限于验证期，在2017-2025年的测试期内，MAPE从0.61降低到0.54（相对降低11.5，p 0.001，Cohen s d 0.31），方向精度从71提高到74，夏普比率提高了18（95自举CI 8.2，27.4），收益集中在原始系统行为缺陷最严重的高波动性事件中。结果来自离线回溯测试，不涉及实时部署的特定影响。

Keywords :

### 

\[26\] INEUS

标题:INEUS

作者:Jean-Loup Dupret, Davide Gallon, Patrick Cheridito

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06281

Abstract : In this paper, we introduce INEUS, a meshfree iterative neural solver for partial integro differential equations (PIDEs). The method replaces the explicit evaluation of nonlocal jump integrals with single jump sampling and reformulates PIDE solving as a sequence of recursive regression problems. Like Physics Informed Neural Networks (PINNs), INEUS learns global solutions over the entire space time domain, yet it offers a more efficient treatment of nonlocal terms and avoids the computationally expensive differentiation of full PIDE residuals. These features make INEUS particularly well suited for high dimensional PDEs and PIDEs. Supported by a contraction based convergence proof for linear PIDEs, our numerical experiments show that INEUS delivers accurate and scalable solutions for various high dimensional linear and nonlinear examples.

Keywords : 

Abstract :本文介绍了求解偏积分微分方程（PIDE）的无网格迭代神经求解器INEUS。该方法用单跳采样代替了非局部跳跃积分的显式计算，并将PIDE求解重新表述为一系列递归回归问题。与物理知情神经网络（PINN）一样，INEUS在整个时空域上学习全局解，但它提供了一种更有效的非局部项处理方法，并避免了计算成本高昂的全PIDE残差微分。这些特性使INEUS特别适合高维PDE和PIDE。在基于收缩的线性PIDE收敛证明的支持下，我们的数值实验表明，INEUS为各种高维线性和非线性示例提供了准确和可扩展的解决方案。

Keywords :

### 

\[27\] Cascading disruptions in natural gas, fertilizers, and crops drive structural food supply vulnerabilities globally

标题:天然气、化肥和作物的连锁中断加剧了全球粮食供应的结构性脆弱性

作者:Pavel Kiparisov, Christian Folberth

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06411

Abstract : Global food security depends on tightly coupled international supply chains including natural gas, mineral fertilizers, and staple crops. Earlier research has examined potential consequences of disruptions in each of these domains separately but not from a systemic perspective. Here we integrate bilateral trade in natural gas, nitrogen, phosphorus and potassium fertilizers, and eleven staple crops accounting for approximately 70  of plant based calories into a cascading impact model spanning 208 countries, 20 geopolitical blocs, and the period 1992 2023. Under complete trade isolation, up to 22  of global caloric consumption would be lost, with a peak in the most recent evaluated years. Structural vulnerabilities vary greatly. Regions largely lacking some parts of the supply chain face near total crop supply collapse, while few countries can cover the whole nexus through domestic resource endowments and production capacities. Temporal trends highlight a substantial increase in vulnerability globally, most prominently in the EU with a near two fold increase since the 1990s. Market power is most concentrated and most volatile in the upstream gas and mineral fertilizer layers, from which shocks propagate downstream. Food stocks provide only limited resilience with half of humanity living in countries disposing of stock lasting less than three months. Our results identify the upstream supply chains as the structural bottlenecks of the global agrifood system and propose leverage points to enhance resilience.

Keywords : 

Abstract :全球粮食安全取决于紧密耦合的国际供应链，包括天然气、矿物肥料和主粮作物。早期的研究分别考察了这些领域中断的潜在后果，但不是从系统的角度。在这里，我们将天然气、氮肥、磷肥和钾肥以及11种主要作物（约占植物热量的70）的双边贸易整合到一个跨越208个国家、20个地缘政治集团和1992年至2023年期间的级联影响模型中。在完全贸易隔离的情况下，全球多达22种热量消耗将减少，在最近评估的年份达到峰值。结构脆弱性差异很大。主要缺乏供应链某些部分的地区面临着近乎全面的作物供应崩溃，而很少有国家能够通过国内资源禀赋和生产能力覆盖整个关系。时间趋势凸显了全球脆弱性的大幅增加，尤其是在欧盟，自20世纪90年代以来，脆弱性增加了近两倍。市场力量在上游天然气和矿物肥料层最集中、最不稳定，冲击从这些层向下游传播。粮食库存只能提供有限的恢复力，一半的人类生活在处置库存的国家，持续时间不到三个月。我们的研究结果将上游供应链确定为全球农业食品系统的结构性瓶颈，并提出了提高弹性的杠杆点。

Keywords :

### 

\[28\] Neural Actuarial Longevity Forecasting

标题:神经精算寿命预测

作者:Davide Rindori

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06438

Abstract : Traditional multi population models, such as the Li Lee framework, rely on the assumption of mean reverting country specific deviations. However, recent data from high longevity clusters suggest a systemic break in this paradigm. We identify a stationarity paradox where mortality residuals in countries like Sweden and West Germany exhibit persistent unit roots, leading to a systematic mispricing of longevity risk in linear models. To address these non linearities, we propose Hybrid Lift, a neural actuarial framework that combines Hierarchical LSTM networks with a Mean Bias Correction (MBC) anchoring mechanism. Positioned as a governance friendly model challenger rather than a replacement of classical approaches, the framework exhibits selective superiority on out of sample validation (2012 2020)  it outperforms Li Lee by 17.40  in Sweden and 12.57  in West Germany, while remaining comparable for near linear regimes such as Switzerland and Japan. We complement the predictive model with an integrated governance suite comprising SHAP based cross country influence mapping, a dual uncertainty framework for regulatory capital calibration (Swiss ES 99.0  of  1.153 years), and a reverse stress test identifying the critical shock threshold for solvency buffer exhaustion. This research provides evidence that neural networks, when properly anchored by actuarial principles, can serve as effective model challengers for longevity risk management under the SST and Solvency II standards.

Keywords : 

Abstract :传统的多人口模型，如李-李框架，依赖于均值回归国家特定偏差的假设。然而，高寿命集群的最新数据表明，这一范式发生了系统性突破。我们发现了一个平稳性悖论，即瑞典和西德等国家的死亡率残差表现出持续的单位根，导致线性模型中寿命风险的系统性错误定价。为了解决这些非线性问题，我们提出了混合提升，这是一种神经精算框架，将分层LSTM网络与平均偏差校正（MBC）锚定机制相结合。该框架被定位为治理友好型模型挑战者，而不是传统方法的替代品，在样本外验证方面表现出选择性优势（2012-2020）——在瑞典和西德分别比李高出17.40和12.57，同时在瑞士和日本等近线性制度下保持可比性。我们用一个综合治理套件来补充预测模型，该套件包括基于SHAP的跨国影响映射、监管资本校准的双重不确定性框架（1.153年的瑞士ES 99.0）和识别偿付能力缓冲耗尽的关键冲击阈值的反向压力测试。这项研究提供了证据，表明神经网络在精算原理的正确锚定下，可以作为SST和偿付能力II标准下长寿风险管理的有效模型挑战者。

Keywords :

### 

\[29\] SNAPO

标题:斯内普

作者:Dmitri Goloubentsev, Natalija Karpichina

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06570

Abstract : Many real world problems require sequential decisions under uncertainty  when to inject or withdraw gas from storage, how to rebalance a pension portfolio each month, what temperature profile to run through a pharmaceutical reactor chain. Dynamic programming solves small instances exactly but scales exponentially in state dimensions. Black box reinforcement learning handles high dimensional states but trains slowly and produces no sensitivities.We introduce SNAPO (Smooth Neural Adjoint Policy Optimization), a framework that embeds a neural policy inside a known, differentiable simulator, replaces hard constraints with smooth approximations, and computes exact gradients of the objective with respect to all policy parameters and all inputs in a single adjoint pass.We demonstrate SNAPO on three domains  natural gas storage (training in under a minute, 365 forward curve sensitivities at no additional cost per sensitivity), pension fund asset liability management (6.5x 200x sensitivity speedup over bump and revalue, scaling with the number of risk factors), and pharmaceutical manufacturing (cross unit sensitivities through a 4 unit process chain, with 20 ICH Q8 regulatory sensitivities from 5 adjoint passes in 74.5 milliseconds).All sensitivities are produced by the same backward pass that trains the policy, at a cost proportional to one reverse pass regardless of how many sensitivities are computed.

Keywords : 

Abstract :许多现实世界的问题需要在不确定的情况下做出连续的决定——何时注入或从储存中提取天然气，如何每月重新平衡养老金组合，在制药反应器链中运行什么温度曲线。动态规划精确地解决了小实例，但在状态维度上呈指数级扩展。黑盒强化学习处理高维状态，但训练缓慢，不产生灵敏度。我们介绍了SNAPO（平滑神经伴随策略优化），这是一个将神经策略嵌入已知可微模拟器中的框架，用平滑近似代替硬约束，并在单个伴随过程中计算目标相对于所有策略参数和所有输入的精确梯度。所有敏感度都是由训练策略的同一反向传递产生的，其成本与一次反向传递成正比，而不管计算了多少敏感度。

Keywords :