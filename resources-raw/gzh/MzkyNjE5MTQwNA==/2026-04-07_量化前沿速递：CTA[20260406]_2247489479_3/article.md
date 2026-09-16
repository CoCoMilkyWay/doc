# 量化前沿速递：CTA\[20260406\]

shameless 量化前沿速递 2026-04-07 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489479&idx=3&sn=c5a017b336d14c07267b50c026f9a6c8&chksm=c379b461196012428ebaf98b9e78079b269b97d7173c702344c18d36c76a9198646d92a43f12#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489479&idx=3&sn=c5a017b336d14c07267b50c026f9a6c8&chksm=c379b461196012428ebaf98b9e78079b269b97d7173c702344c18d36c76a9198646d92a43f12#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] STN GPR

STN探地雷达

来源:ARXIV\_20260330

\[2\] Rough volatility dynamics in commodity markets

大宗商品市场波动剧烈

来源:ARXIV\_20260330

\[3\] An Inflation Model for the Colombian Case. 2001 2025

哥伦比亚案例的通货膨胀模型。 2001 2025

来源:ARXIV\_20260331

\[4\] From Volatility to Variance

从波动到差异

来源:ARXIV\_20260331

\[5\] Similarity of Information in Games

游戏中的信息相似性

来源:ARXIV\_20260331

\[6\] Contingent Claim Valuation under Increasing Profit, Strong Arbitrage, and Arbitrage of the First Kind

递增利润、强套利和第一类套利下的或有索赔估价

来源:ARXIV\_20260331

\[7\] Opportunity Sensitive Social Welfare

机会敏感型社会福利

来源:ARXIV\_20260331

\[8\] Biased Mean Quadrangle and Applications

偏均四边形及其应用

来源:ARXIV\_20260331

\[9\] Scaling Limits for Exponential Hedging in Trinomial Models

三项式模型中指数套期保值的标度极限

来源:ARXIV\_20260401

\[10\] Should I State or Should I Show  Aligning AI with Human Preferences

我应该陈述还是应该展示人工智能与人类偏好的一致性

来源:ARXIV\_20260401

\[11\] Ultra short term volatility surfaces

超短期波动面

来源:ARXIV\_20260401

\[12\] Option Pricing on Automated Market Maker Tokens

自动做市商代币的期权定价

来源:ARXIV\_20260401

\[13\] Bridging Stochastic Control and Deep Hedging

桥接随机控制和深度对冲

来源:ARXIV\_20260401

\[14\] Be Water

似水

来源:ARXIV\_20260401

\[15\] Forecasting duration in high frequency financial data using a self exciting flexible residual point process

使用自激灵活残差点过程预测高频金融数据的持续时间

来源:ARXIV\_20260402

\[16\] Pricing Lookback Options on a Quantum Computer

量子计算机上的回溯期权定价

来源:ARXIV\_20260402

\[17\] Valuation of variable annuities under the Volterra mortality and rough Heston models

Volterra死亡率和粗糙Heston模型下可变年金的估值

来源:ARXIV\_20260402

\[18\] Stratified adaptive sampling for derivative free stochastic trust region optimization

无导数随机信赖域优化的分层自适应采样

来源:ARXIV\_20260402

\[19\] Dynamic Weight Optimization for Double Linear Policy

双线性策略的动态权重优化

来源:ARXIV\_20260402

### 

\[1\] STN GPR

标题:STN探地雷达

作者:Dominic Gribben, Carolina Allende, Alba Villarino, Aser Cortines, Mazen Ali, Román Orús, Pascal Oswald, Noureddine Lehdili

来源:ARXIV\_20260330

链接:https://arxiv.org/pdf/2603.26318

Abstract : We develop a tensor network surrogate for option pricing, targeting large scale portfolio revaluation problems arising in market risk management (e.g., VaR and Expected Shortfall computations). The method involves representing high dimensional price surfaces in tensor train (TT) form using TT cross approximation, constructing the surrogate directly from black box price evaluations without materializing the full training tensor. For inference, we use a Laplacian kernel and derive TT representations of the kernel matrix and its closed form inverse in the noise free setting, enabling TT based Gaussian process regression without dense matrix factorization or iterative linear solves. We found that hyperparameter optimization consistently favors a large kernel length scale and show that in this regime the GPR predictor reduces to multilinear interpolation for off grid inputs  we also derive a low rank TT representation for this limit. We evaluate the approach on five asset basket options over an eight dimensional parameter space (asset spot levels, strike, interest rate, and time to maturity). For European geometric basket puts, the tensor surrogate achieves lower test error at shorter training times than standard GPR by scaling to substantially larger effective training sets. For American arithmetic basket puts trained on LSMC data, the surrogate exhibits more favorable scaling with training set size while providing millisecond level evaluation per query, with overall runtime dominated by data generation.

Keywords : 

Abstract :我们为期权定价开发了一个张量网络替代物，针对市场风险管理中出现的大规模投资组合重估问题（例如VaR和预期缺口计算）。该方法涉及使用TT交叉近似以张量训练（TT）形式表示高维价格曲面，直接从黑箱价格评估中构建替代项，而无需实现完整的训练张量。对于推理，我们使用拉普拉斯核，并在无噪声环境中推导核矩阵及其闭式逆的TT表示，从而实现了基于TT的高斯过程回归，而无需密集矩阵分解或迭代线性求解。我们发现，超参数优化始终倾向于大的核长度尺度，并表明在这种情况下，GPR预测器对于离网输入简化为多线性插值，我们还为这个极限推导了一个低秩TT表示。我们在八维参数空间（资产现货水平、执行、利率和到期时间）上评估了五种资产篮子期权的方法。对于欧洲几何篮子看跌期权，张量替代物通过扩展到更大的有效训练集，在更短的训练时间内实现了比标准GPR更低的测试误差。对于在LSMC数据上训练的美国算术篮，代理在训练集大小方面表现出更有利的扩展性，同时为每个查询提供毫秒级的评估，整体运行时间由数据生成主导。

Keywords :

### 

\[2\] Rough volatility dynamics in commodity markets

标题:大宗商品市场波动剧烈

作者:Roberto Daluiso, Héctor Folgar-Cameán, Andrea Pallavicini, Carlos Vázquez

来源:ARXIV\_20260330

链接:https://arxiv.org/pdf/2603.26514

Abstract : In this paper, we develop a general rough volatility model for commodities that provides an automatic calibration of the initial term structure of the futures prices and an appropriate treatment of the Samuelson effect. After the theoretical analysis of this general model, we focus on the rBergomi and rHeston models and their calibration to market data of vanilla futures options on WTI Crude Oil. Finally, numerical results illustrate the performance of the proposed rough volatility models for commodities pricing.

Keywords : 

Abstract :在本文中，我们开发了一个通用的商品粗略波动模型，该模型提供了期货价格初始期限结构的自动校准和萨缪尔森效应的适当处理。在对这一通用模型进行理论分析后，我们重点研究了rBergomi和rHeston模型及其对WTI原油香草期货期权市场数据的校准。最后，数值结果说明了所提出的商品定价粗糙波动模型的性能。

Keywords :

### 

\[3\] An Inflation Model for the Colombian Case. 2001 2025

标题:哥伦比亚案例的通货膨胀模型。 2001 2025

作者:Wilman Arturo Gomez, Carlos Esteban Posada

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.26928

Abstract : Since the beginning of this century the Colombian monetary authority has conducted monetary policy under a strategy based on setting targets for interest rate and inflation, while allowing the exchange rate of the U.S. dollar in domestic currency to float freely. This paper takes that strategy into account in order to explain inflation. Our econometric results were obtained by applying the Generalized Method of Moments to test the hypotheses derived from the structural form of our model. The main findings indicate  a. the validity of a Phillips this http URL is, a positive relationship between the inflation rate and the output gap, conditional on inflation expectations  b. that the monetary authority has reacted to shocks in inflation and in the output gap by adjusting its policy in the appropriate direction but, up to the end of 2025, without being able to claim that its responses have always been timely and consistently forceful. In other words, it can be said that the monetary authority has not been aggressive in ensuring that observed inflation returns rapidly to levels consistent with the inflation target range.

Keywords : 

Abstract :自本世纪初以来，哥伦比亚货币当局一直根据一项基于设定利率和通货膨胀目标的战略实施货币政策，同时允许美元对本国货币的汇率自由浮动。本文考虑了这一策略来解释通货膨胀。我们的计量经济学结果是通过应用广义矩量法来检验从我们模型的结构形式中得出的假设而获得的。主要研究结果表明，a.菲利普斯的有效性，即通货膨胀率与产出缺口之间存在正相关关系，这取决于通货膨胀预期b.货币当局通过在适当的方向上调整其政策来应对通货膨胀和产出缺口的冲击，但到2025年底，还不能声称其反应一直是及时和持续有力的。换句话说，可以说，货币当局在确保观察到的通货膨胀迅速恢复到与通货膨胀目标范围一致的水平方面没有采取积极措施。

Keywords :

### 

\[4\] From Volatility to Variance

标题:从波动到差异

作者:Wenxuan Zhang, Zhouchi Lin, Benzhuo Lu

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.27501

Abstract : Accurately characterizing the implied volatility curves is a central challenge in option pricing and risk management. The classical SABR model by Hagan et al. has been widely adopted in practice due to its well defined stochastic volatility structure and its tractable closed form approximation for Black implied volatility. However, under complex market conditions, its fitting accuracy for implied volatility curves remains limited. To address this issue, this paper proposes an extended model within the SABR framework, referred to as skew SABR. Specifically, the proposed approach introduces an extension to the stochastic dynamics of the underlying asset price and its variance process, under which a corresponding Black implied volatility expression is derived. By further simplifying and reorganizing the resulting formula, the implied volatility can be expressed in a form that explicitly incorporates a skew parameter, thereby enabling a direct characterization of the asymmetry in the implied volatility curve. The resulting expression preserves the structural simplicity of the Hagan SABR formula, while significantly enhancing the model s flexibility in capturing complex volatility smile patterns. From a theoretical perspective, the paper provides a systematic analysis of the model specification and the financial interpretation of its parameters. From an empirical perspective, a comprehensive comparison is conducted using data from the Chinese options market over the period 2018  2025. The skew SABR model is evaluated against the classical Hagan SABR model, the SVI parameterization, polynomial fitting, and spline based methods. Numerical results show that, across different market regimes and a wide range of implied volatility curve shapes, the skew SABR model consistently achieves high and stable fitting accuracy.

Keywords : 

Abstract :准确表征隐含波动率曲线是期权定价和风险管理的核心挑战。Hagan等人的经典SABR模型因其定义明确的随机波动率结构和易于处理的黑色隐含波动率闭式近似而在实践中被广泛采用。然而，在复杂的市场条件下，其对隐含波动率曲线的拟合精度仍然有限。为了解决这个问题，本文在SABR框架内提出了一个扩展模型，称为斜SABR。具体而言，所提出的方法引入了标的资产价格及其方差过程的随机动力学的扩展，在此基础上推导出了相应的布莱克隐含波动率表达式。通过进一步简化和重组所得公式，隐含波动率可以以明确包含偏斜参数的形式表示，从而能够直接表征隐含波动率曲线中的不对称性。所得表达式保留了Hagan SABR公式的结构简单性，同时显著增强了模型在捕捉复杂波动微笑模式方面的灵活性。从理论角度，本文对模型规范及其参数的财务解释进行了系统分析。从实证角度来看，使用2018年至2025年期间中国期权市场的数据进行了全面比较。斜SABR模型与经典Hagan SABR模型、SVI参数化、多项式拟合和基于样条的方法进行了比较。数值结果表明，在不同的市场制度和广泛的隐含波动率曲线形状下，偏斜SABR模型始终达到高而稳定的拟合精度。

Keywords :

### 

\[5\] Similarity of Information in Games

标题:游戏中的信息相似性

作者:Deepal Basak, Joyee Deb, Aditya Kuvalekar

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.28190

Abstract : Algorithmic content targeting homogenizes information, with implications for strategic interactions. For example, this increased homogenization was arguably responsible for the run on the Silicon Valley Bank. We argue that existing measures of similarity are inappropriate for studying games    especially coordination games    because they do not discipline agents  conditional beliefs. We propose a class of stochastic orders, Concentration Along the Diagonal (CAD), built on agents  conditional beliefs. In canonical binary action coordination games, greater CAD similarity is both necessary and sufficient for strategic similarity    agents adopt the same strategy. We further demonstrate CAD s applicability in congestion games, collective action, and second price auctions.

Keywords : 

Abstract :算法内容定位使信息同质化，对战略互动产生影响。例如，这种同质化的加剧可以说是硅谷银行挤兑的原因。我们认为，现有的相似性度量不适合研究博弈，尤其是协调博弈，因为它们没有约束代理人的条件信念。我们提出了一类基于代理条件信念的随机序，即沿对角线集中（CAD）。在规范的二元动作协调博弈中，对于策略相似性代理采用相同的策略，更大的CAD相似性是必要且充分的。我们进一步证明了CAD在拥堵博弈、集体行动和二次价格拍卖中的适用性。

Keywords :

### 

\[6\] Contingent Claim Valuation under Increasing Profit, Strong Arbitrage, and Arbitrage of the First Kind

标题:递增利润、强套利和第一类套利下的或有索赔估价

作者:Yukihiro Tsuzuki

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.28256

Abstract : We study the upper hedging price for contingent claims in market models with strong types of arbitrage  increasing profit, strong arbitrage, and arbitrage of the first kind. The existence of arbitrage may make the price smaller than if it did not exist. For example, when the asset price process has a reflecting boundary, which introduces increasing profit in the market model, the option prices are reduced to those of the corresponding options that knock out at the boundary. Furthermore, we demonstrate that corporate stock price processes with increasing profit are obtained as a result of corporate stock issuance and repurchase plans.

Keywords : 

Abstract :我们研究了在强套利增加利润、强套利和第一类套利的市场模型中，或有索赔的上限套期保值价格。套利的存在可能会使价格低于不存在套利的情况。例如，当资产价格过程有一个反映边界时，这会在市场模型中引入越来越多的利润，期权价格会降低到在边界处敲除的相应期权的价格。此外，我们证明了公司股票价格过程中利润的增加是由于公司股票发行和回购计划的结果。

Keywords :

### 

\[7\] Opportunity Sensitive Social Welfare

标题:机会敏感型社会福利

作者:T. Wienand, B. Magdalou, R. Nock, P. Hufe

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.26853

Abstract : We develop an axiomatic framework to evaluate income distributions from the perspective of an opportunity egalitarian social planner. Building on a formal link with the literature on decision theory under ambiguity, we characterize a class of opportunity sensitive social welfare functions based on a two stage evaluation  the planner first computes the expected utility of income within each social type, where types consist of individuals sharing the same circumstances beyond their control, and then aggregates these type specific welfare levels through a transformation reflecting aversion to inequality of opportunity. The evaluation is governed by a single parameter. We provide equivalent representations of the social welfare function, including a mean divergence form that separates an efficiency term from an inequality term, and we establish an opportunity stochastic dominance criterion. Finally, we derive inequality measures that decompose overall inequality into within group risk and between group inequality of opportunity, providing a tractable basis for normative welfare analysis.

Keywords : 

Abstract :我们开发了一个公理框架，从机会平等主义社会规划者的角度评估收入分配。基于与模糊决策理论文献的正式联系，我们基于两阶段评估来描述一类机会敏感的社会福利函数。规划者首先计算每种社会类型中收入的预期效用，其中类型由共享超出其控制范围的相同环境的个人组成，然后通过反映对机会不平等的厌恶的转换来聚合这些特定类型的福利水平。评估由单个参数控制。我们提供了社会福利函数的等价表示，包括将效率项与不等式项分开的均值散度形式，并建立了机会随机支配性标准。最后，我们推导了不平等度量，将整体不平等分解为群体内风险和群体间机会不平等，为规范福利分析提供了易于处理的基础。

Keywords :

### 

\[8\] Biased Mean Quadrangle and Applications

标题:偏均四边形及其应用

作者:Anton Malandii, Stan Uryasev

来源:ARXIV\_20260331

链接:https://arxiv.org/pdf/2603.26901

Abstract : This paper introduces  emph biased mean regression , estimating the  emph biased mean , i.e.,   mathbb E  Y    x , where  x  in  mathbb R  . The approach addresses a fundamental statistical problem that covers numerous applications. For instance, it can be used to estimate factors driving portfolio loss exceeding the expected loss by a specified amount (e.g.,   x   10 billion ) or to estimate factors impacting a specific excess release of radiation in the environment, where nuclear safety regulations specify different severity levels.The estimation is performed by minimizing the so called  emph superexpectation error . We establish two equivalence results that connect the method to popular paradigms  (i) biased mean regression is equivalent to quantile regression for an appropriate parameterization and is equivalent to ordinary least squares when  x 0   (ii) in portfolio optimization, minimizing  emph superexpectation risk , associated with the superexpectation error, is equivalent to CVaR optimization. The approach is computationally attractive, as minimizing the superexpectation error reduces to linear programming (LP), thereby offering algorithmic and modeling advantages. It is also a good alternative to ordinary least squares (OLS) regression.The approach is based on the  emph Risk Quadrangle  (RQ) framework, which links four stochastic functionals    error, regret, risk, and deviation    through a statistic. For the biased mean quadrangle, the statistic is the biased mean. We study properties of the new quadrangle, such as  emph subregularity , and establish its relationship to the quantile quadrangle. Numerical experiments confirm the theoretical statements and illustrate the practical implications.

Keywords : 

Abstract :本文介绍了emph偏差均值回归，估计emph偏差的均值，即mathb e Y x，其中x在mathb R中。该方法解决了一个涵盖众多应用的基本统计问题。例如，它可用于估算导致投资组合损失超过预期损失指定金额（例如x 100亿）的因素，或估算影响环境中特定过量辐射释放的因素，其中核安全法规规定了不同的严重程度。通过最小化所谓的emph超期望误差来进行估计。我们建立了两个等价结果，将该方法与流行的范式联系起来：（i）当投资组合优化中的x0（ii）与CVaR优化等价时，有偏均值回归等价于适当参数化的分位数回归，也等价于普通最小二乘。该方法在计算上具有吸引力，因为最小化超期望误差可以简化为线性规划（LP），从而提供算法和建模优势。它也是普通最小二乘（OLS）回归的一个很好的替代方案。该方法基于emph风险四边形（RQ）框架，该框架通过统计将四个随机泛函——误差、遗憾、风险和偏差联系起来。对于有偏均值四边形，统计量是有偏均值。我们研究了新四边形的性质，如emph次对称性，并建立了它与分位数四边形的关系。数值实验证实了理论陈述，并说明了实际意义。

Keywords :

### 

\[9\] Scaling Limits for Exponential Hedging in Trinomial Models

标题:三项式模型中指数套期保值的标度极限

作者:Yan Dolinsky, Xin Zhang

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.28948

Abstract : We study scaled trinomial models converging to the Black  Scholes model, and analyze exponential certainty equivalent prices for path dependent European options. As the number of trading dates  n  tends to infinity and the risk aversion is scaled as  nl  for a fixed constant  l 0 , we derive a nontrivial scaling limit. Our analysis is purely probabilistic. Using a duality argument for the certainty equivalent, together with martingale and weak convergence techniques, we show that the limiting problem takes the form of a volatility control problem with a specific penalty. For European options with Markovian payoffs, we analyze the optimal control problem and show that the corresponding delta hedging strategy is asymptotically optimal for the primal problem.

Keywords : 

Abstract :我们研究了收敛到Black-Scholes模型的缩放三项式模型，并分析了路径依赖欧式期权的指数确定性等价价格。由于交易日期的数量n趋于无穷大，并且风险厌恶度在固定常数l0下被缩放为nl，我们推导出了一个非平凡的缩放极限。我们的分析纯粹是概率性的。利用确定性等价的对偶论证，结合鞅和弱收敛技术，我们证明了极限问题采取具有特定惩罚的波动控制问题的形式。对于具有马尔可夫收益的欧式期权，我们分析了最优控制问题，并证明了相应的delta套期保值策略对于原始问题是渐近最优的。

Keywords :

### 

\[10\] Should I State or Should I Show  Aligning AI with Human Preferences

标题:我应该陈述还是应该展示人工智能与人类偏好的一致性

作者:Keaton Ellis, Wanying Huang

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.29317

Abstract : As AI agents become more autonomous, properly aligning their objectives with human preferences becomes increasingly important. We study how effectively an AI agent learns a human principal s preference in choice under risk via stated versus revealed preferences. We conduct an online experiment in which subjects state their preferences through written instructions ( prompts ) and reveal them through choices in a series of binary lottery questions ( data ). We find that on average, an AI agent given revealed preference data predicts subjects  choices more accurately than an AI agent given stated preference prompts. Further analysis suggests that the gap is driven by subjects  difficulty in translating their own preferences into written instructions. When given a choice between which information source to give to an AI agent, a large portion of subjects fail to select the more informative one. Moreover, when predictions from the two sources conflict, we find that the AI agent aligns more frequently with the prompt, despite its lower accuracy. Overall, these results highlight the revealed preference approach as a powerful mechanism for communicating human preferences to AI agents, but its success depends on careful implementation.

Keywords : 

Abstract :随着人工智能代理变得更加自主，将其目标与人类偏好正确对齐变得越来越重要。我们研究了人工智能代理在风险下通过陈述偏好与揭示偏好来学习人类委托人选择偏好的有效性。我们进行了一项在线实验，受试者通过书面说明（提示）陈述他们的偏好，并通过一系列二元彩票问题（数据）中的选择来揭示他们的偏好。我们发现，平均而言，给定显示偏好数据的AI代理比给定声明偏好提示的AI代理更准确地预测受试者的选择。进一步的分析表明，这种差距是由受试者难以将自己的偏好转化为书面说明造成的。当在向人工智能代理提供哪个信息源之间做出选择时，很大一部分受试者无法选择信息量更大的信息源。此外，当两个来源的预测发生冲突时，我们发现AI代理与提示的对齐频率更高，尽管其准确性较低。总体而言，这些结果突显了揭示偏好方法是将人类偏好传达给人工智能代理的强大机制，但其成功取决于仔细的实施。

Keywords :

### 

\[11\] Ultra short term volatility surfaces

标题:超短期波动面

作者:Federico M. Bandi, Nicola Fusari, Guido Gazzani, Roberto Renò

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.29430

Abstract : Options with maturities below one week, hereafter  ultra short term  options, have seen a sharp increase in trading activity in recent years. Yet, these instruments are difficult to price jointly using classical pricing models due to the pronounced oscillations observed in the at the money implied volatility term structure across ultra short term tenors. We propose Edgeworth  , a parsimonious jump diffusion model featuring a nonparametric stochastic volatility component, which provides flexibility in capturing implied volatility smiles for each tenor, combined with a deterministic shift extension, which allows the model to fit rich at the money implied volatility shapes across tenors. We derive a local (in tenor) expansion of the process characteristic function suited to value ultra short term options. The expansion leads to fast and accurate option pricing in closed form via standard Fourier inversion. We discuss the benefits of the proposed approach relative to benchmarks.

Keywords : 

Abstract :一周以下到期的期权，以下简称超短期期权，近年来交易活动急剧增加。然而，由于在超短期期限内观察到的按货币价值计算的隐含波动率期限结构中存在明显的振荡，因此很难使用经典定价模型对这些工具进行联合定价。我们提出了Edgeworth，这是一个具有非参数随机波动性成分的简约跳跃扩散模型，它为捕捉每个期限的隐含波动率微笑提供了灵活性，并结合了确定性转移扩展，使该模型能够适应不同期限的富货币隐含波动率形状。我们推导出了适用于超短期期权估值的过程特征函数的局部（按期限）扩展。这种扩展通过标准傅里叶逆变换以封闭形式实现了快速准确的期权定价。我们讨论了所提出的方法相对于基准的好处。

Keywords :

### 

\[12\] Option Pricing on Automated Market Maker Tokens

标题:自动做市商代币的期权定价

作者:Philip Z. Maymin

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.29763

Abstract : We derive the stochastic price process for tokens whose sole price discovery mechanism is a constant product automated market maker (AMM). When the net flow into the pool follows a diffusion, the token price follows a constant elasticity of variance (CEV) process, nesting Black Scholes as the limiting case of infinite liquidity. We obtain closed form European option prices and introduce liquidity adjusted Greeks. The CEV structure generates a leverage effect    volatility rises as price falls    whose normalized implied volatility skew depends only on the pool s weighting parameter, not on pool depth  Black Scholes underprices 20  out of the money puts by roughly 6  in implied volatility terms at every pool depth, while the absolute pricing discrepancy vanishes as pools deepen. Empirically, after controlling for pool depth and flow volatility, realized return variance across 90 Bittensor subnets exhibits a strongly negative price elasticity, decisively rejecting geometric Brownian motion and consistent with the CEV prediction. A complementary delta hedged backtest across 82 subnets confirms near identical hedging errors at the money, consistent with the prediction that pricing differences are concentrated in the wings.

Keywords : 

Abstract :我们推导了代币的随机价格过程，其唯一的价格发现机制是恒定产品自动做市商（AMM）。当流入池的净流量遵循扩散时，代币价格遵循恒定的方差弹性（CEV）过程，将Black-Scholes作为无限流动性的极限情况。我们获得封闭式欧洲期权价格，并引入流动性调整后的希腊期权。CEV结构产生了杠杆效应——随着价格下跌，波动率上升，其归一化隐含波动率偏斜仅取决于池的加权参数，而不取决于池深度——布莱克-斯科尔斯在每个池深度将20个货币看跌期权的隐含波动率低估了大约6个，而随着池的加深，绝对定价差异消失了。根据经验，在控制了池深和流量波动后，90个比特张量子网的实际回报方差表现出强烈的负价格弹性，果断地拒绝了几何布朗运动，与CEV预测一致。在82个子网中进行的互补增量对冲回测证实了货币上几乎相同的对冲误差，这与定价差异集中在侧翼的预测一致。

Keywords :

### 

\[13\] Bridging Stochastic Control and Deep Hedging

标题:桥接随机控制和深度对冲

作者:Jules Arzel, Noureddine Lehdili

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.29994

Abstract : This paper studies the problem of hedging and pricing a European call option under proportional transaction costs, from two complementary perspectives. We first derive the optimal hedging strategy under CARA utility, following the stochastic control framework of Davis et al. (1993), characterising the no transaction band via the Hamilton Jacobi Bellman Quasi Variational Inequality (HJBQVI) and the Whalley Wilmott asymptotic approximation. We then adopt a deep hedging approach, proposing two architectures that build on the No Transaction Band Network of Imaki et al. (2023)  NTBN Delta, which makes delta centring explicit, and WW NTBN, which incorporates the Whalley Wilmott formula as a structural prior on the bandwidth and replaces the hard clamp with a differentiable soft clamp. Numerical experiments show that WW NTBN converges faster, matches the stochastic control no transaction bands more closely, and generalises well across transaction cost regimes. We further apply both frameworks to the bull call spread, documenting the breakdown of price linearity under transaction costs.

Keywords : 

Abstract :本文从两个互补的角度研究了比例交易成本下欧式看涨期权的套期保值和定价问题。我们首先根据Davis等人（1993）的随机控制框架，通过Hamilton-Jacobi-Bellman准变分不等式（HJBQVI）和Whalley-Wilmott渐近近似来表征无交易区间，推导出了CARA效用下的最优套期保值策略。然后，我们采用了一种深度对冲方法，提出了两种架构，分别基于Imaki等人（2023）的无事务频带网络NTBN Delta和WW NTBN，前者使增量中心明确，后者将Whalley-Wilmott公式作为带宽的结构先验，并用可微软箝位代替硬箝位。数值实验表明，WW-NTBN收敛速度更快，与随机控制无交易带的匹配更紧密，并且在交易成本制度下具有良好的泛化能力。我们进一步将这两个框架应用于看涨期权价差，记录了交易成本下价格线性的细分。

Keywords :

### 

\[14\] Be Water

标题:似水

作者:Yijia Chen

来源:ARXIV\_20260401

链接:https://arxiv.org/pdf/2603.29593

Abstract : The proliferation of diverse, high leverage trading instruments in modern financial markets presents a complex,  noisy  environment, leading to a critical question  which trading strategies are evolutionarily viable  To investigate this, we construct a large scale agent based model,  MAS Utopia,  comprising 10,000 agents with five distinct archetypes. This society is immersed in five years of high frequency data under a counterfactual baseline  zero transaction friction and a robust Unconditional Basic Income (UBI) safety net. The simulation reveals a powerful evolutionary convergence. Strategies that attempt to fight the market s current   namely Mean Reversion ( buy the dip )   prove structurally fragile. In contrast, the Trend Following archetype, which adapts to the market s flow, emerges as the dominant phenotype. Translating this finding, we architect an LLM driven system that emulates this successful logic. Our findings offer profound implications, echoing the ancient wisdom of  Be Water   for investors, it demonstrates that survival is achieved not by rigid opposition, but by disciplined alignment with the prevailing current  for markets, it critiques tools that encourage contrarian gambling  for society, it underscores the stabilizing power of economic safety nets.

Keywords : 

Abstract :现代金融市场中多样化、高杠杆交易工具的激增带来了一个复杂、嘈杂的环境，导致了一个关键问题，即哪些交易策略在进化上是可行的。为了研究这一点，我们构建了一个大规模的基于代理的模型MAS Utopia，由10000个具有五个不同原型的代理组成。这个社会沉浸在五年的高频数据中，在反事实的基线零交易摩擦和强大的无条件基本收入（UBI）安全网下。模拟揭示了强大的进化收敛性。试图对抗市场当前趋势的策略，即均值反转（买入下跌），在结构上被证明是脆弱的。相比之下，适应市场流动的趋势跟踪原型成为主导表型。根据这一发现，我们构建了一个模拟这种成功逻辑的LLM驱动系统。我们的发现提供了深刻的启示，与Be Water对投资者的古老智慧相呼应，它表明生存不是通过僵化的反对来实现的，而是通过与市场主流的有纪律的一致来实现的。它批评了鼓励社会逆向赌博的工具，强调了经济安全网的稳定力量。

Keywords :

### 

\[15\] Forecasting duration in high frequency financial data using a self exciting flexible residual point process

标题:使用自激灵活残差点过程预测高频金融数据的持续时间

作者:Kyungsub Lee

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00346

Abstract : This paper presents a method for forecasting limit order book durations using a self exciting flexible residual point process. High frequency events in modern exchanges exhibit heavy tailed interarrival times, posing a significant challenge for accurate prediction. The proposed approach incorporates the empirical distributional features of interarrival times while preserving the self exciting and decay structure. This work also examines the stochastic stability of the process, which can be interpreted as a general state space Markov chain. Under suitable conditions, the process is irreducible, aperiodic, positive Harris recurrent, and has a stationary distribution. An empirical study demonstrates that the model achieves strong predictive performance compared with several alternative approaches when forecasting durations in ultra high frequency trading data.

Keywords : 

Abstract :本文提出了一种使用自激柔性残差点过程预测限价订单持续时间的方法。现代交易所中的高频事件表现出严重的到达间隔时间，对准确预测构成了重大挑战。所提出的方法结合了到达时间间隔的经验分布特征，同时保留了自激和衰变结构。这项工作还研究了过程的随机稳定性，可以将其解释为一般的状态空间马尔可夫链。在适当的条件下，该过程是不可约的、非周期的、正哈里斯循环的，并且具有平稳分布。实证研究表明，与几种替代方法相比，该模型在预测超高频交易数据的持续时间时具有很强的预测性能。

Keywords :

### 

\[16\] Pricing Lookback Options on a Quantum Computer

标题:量子计算机上的回溯期权定价

作者:Florence Paquette, Tania Belabbas, Emmanuel Hamel, Anne MacKay

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00389

Abstract : We develop a quantum algorithm to price discretely monitored lookback options in the Black Scholes framework using imaginary time evolution. By rewriting the pricing PDE as a Schrodinger type equation, the problem becomes the imaginary time evolution of a quantum state under a non Hermitian Hamiltonian. This evolution is approximated with the Variational Quantum imaginary time evolution (VarQITE) method, which replaces the exact non unitary dynamics with a parameterized, hardware efficient quantum circuit. A central challenge arises from jump conditions caused by the discrete updating of the running maximum. This feature is not present in standard quantum treatments of European or Asian options. To address this, we propose two quantum compatible formulations  (i) a sequential approach that models jumps via dedicated jump Hamiltonians applied at monitoring dates, and (ii) a simultaneous multi function evolution that removes explicit jumps at the expense of an increased number of dimensions. We compare both approaches in terms of qubit resources, circuit complexity and numerical accuracy, and benchmark them against Monte Carlo simulations. Our results show that discretely monitored, path dependent options with jump conditions can be handled within a variational quantum framework, paving the way toward the quantum pricing of more complex derivatives with non smooth dynamics.

Keywords : 

Abstract :我们开发了一种量子算法，在Black-Scholes框架中使用虚时间进化对离散监控的回溯期权进行定价。通过将定价偏微分方程重写为薛定谔型方程，该问题变成了非厄米哈密顿量下量子态的虚时间演化。这种演化用变分量子虚时间演化（VarQITE）方法近似，该方法用参数化、硬件高效的量子电路代替了精确的非酉动力学。一个核心挑战来自运行最大值离散更新引起的跳跃条件。欧洲或亚洲选项的标准量子治疗中不存在此功能。为了解决这个问题，我们提出了两个量子兼容的公式：（i）一种顺序方法，通过在监测日期应用的专用跳跃哈密顿量来模拟跳跃；（ii）一种同时进行的多函数进化，以增加维度为代价消除显式跳跃。我们从量子位资源、电路复杂性和数值精度方面比较了这两种方法，并将其与蒙特卡洛模拟进行了比较。我们的结果表明，具有跳跃条件的离散监控、路径依赖期权可以在变分量子框架内处理，为具有非光滑动力学的更复杂衍生品的量子定价铺平了道路。

Keywords :

### 

\[17\] Valuation of variable annuities under the Volterra mortality and rough Heston models

标题:Volterra死亡率和粗糙Heston模型下可变年金的估值

作者:Wenyuan Li, Haoqi Lyu

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00472

Abstract : This paper investigates the valuation of variable annuity contracts with an early surrender option under non Markovian models. Moreover, policyholders are provided with guaranteed minimum maturity and death benefits to protect against the downside risk. Unlike the existing literature, our variable annuity account value is linked to two non Markovian processes  an equity index modeled by a rough Heston model and a force of mortality following a Volterra type stochastic model. In this case, the early surrender feature introduces an optimal stopping problem where continuation values depend on the entire path history, rendering traditional numerical methods infeasible. We develop a deep signature Least Squares Monte Carlo approach to learn optimal surrender strategies on a discretized time grid. To mitigate the curse of dimensionality arising from the path dependent model, we use truncated rough path signatures to encode the historical paths and approximate the continuation values using a neural network. Numerically, we find that the fair fee increases with the Hurst parameters of both the stock volatility and the force of mortality. Finally, a convergence proof is provided to further support the stability of our method.

Keywords : 

Abstract :本文研究了非马尔可夫模型下具有提前退保期权的可变年金合约的估值。此外，为保单持有人提供有保证的最低到期日和死亡保险金，以防范下行风险。与现有文献不同，我们的可变年金账户价值与两个非马尔可夫过程有关，一个是由粗糙赫斯顿模型建模的股票指数，另一个是遵循沃尔泰拉型随机模型的死亡率。在这种情况下，早期投降特征引入了一个最优停止问题，其中连续值取决于整个路径历史，使得传统的数值方法不可行。我们开发了一种深度签名最小二乘蒙特卡洛方法，用于在离散时间网格上学习最优投降策略。为了减轻路径依赖模型引起的维数灾难，我们使用截断的粗糙路径签名对历史路径进行编码，并使用神经网络近似连续值。从数值上讲，我们发现公平费用随着股票波动率和死亡率的赫斯特参数而增加。最后，提供了一个收敛性证明，以进一步支持我们方法的稳定性。

Keywords :

### 

\[18\] Stratified adaptive sampling for derivative free stochastic trust region optimization

标题:无导数随机信赖域优化的分层自适应采样

作者:Giovanni Amici, Sara Shashaani, Pranav Jain

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00178

Abstract : There is emerging evidence that trust region (TR) algorithms are very effective at solving derivative free nonconvex stochastic optimization problems in which the objective function is a Monte Carlo (MC) estimate. A recent strand of methodologies adaptively adjusts the sample size of the MC estimates by keeping the estimation error below a measure of stationarity induced from the TR radius. In this work we explore stratified adaptive sampling strategies to equip the TR framework with accurate estimates of the objective function, thus optimizing the required number of MC samples to reach a given   epsilon  accuracy of the solution. We prove a reduced sample complexity, confirm a superior efficiency via numerical tests and applications, and explore inexpensive implementations in high dimension.

Keywords : 

Abstract :有新的证据表明，信赖域（TR）算法在解决目标函数为蒙特卡洛（MC）估计的无导数非凸随机优化问题方面非常有效。最近的一系列方法通过将估计误差保持在TR半径引起的平稳性度量以下，自适应地调整MC估计的样本大小。在这项工作中，我们探索了分层自适应采样策略，为TR框架提供目标函数的准确估计，从而优化所需数量的MC样本，以达到给定的解的ε精度。我们证明了样本复杂度的降低，通过数值测试和应用证实了卓越的效率，并探索了高维中的廉价实现。

Keywords :

### 

\[19\] Dynamic Weight Optimization for Double Linear Policy

标题:双线性策略的动态权重优化

作者:Tan Chin Hong, Chung-Han Hsieh

来源:ARXIV\_20260402

链接:https://arxiv.org/pdf/2604.00415

Abstract : The Double Linear Policy (DLP) framework guarantees a Robust Positive Expectation (RPE) under optimized constant weight designs or admissible prespecified time varying policies. However, the sequential optimization of these time varying weights remains an open challenge. To address this gap, we propose a Stochastic Model Predictive Control (SMPC) framework. We formulate weight selection as a receding horizon optimal control problem that explicitly maximizes risk adjusted returns while enforcing survivability and predicted positive expectation constraints. Notably, an analytical gradient is derived for the non convex objective function, enabling efficient optimization via the L BFGS B algorithm. Empirical results demonstrate that this dynamic, closed loop approach improves risk adjusted performance and drawdown control relative to constant weight and prescribed time varying DLP baselines.

Keywords : 

Abstract :双线性策略（DLP）框架在优化的恒重设计或可接受的预先指定的时变策略下保证了稳健的正期望（RPE）。然而，这些时变权重的顺序优化仍然是一个悬而未决的挑战。为了解决这一差距，我们提出了一个随机模型预测控制（SMPC）框架。我们将权重选择制定为一个滚动时域最优控制问题，该问题明确地最大化风险调整后的回报，同时强制实施生存能力和预测的正期望约束。值得注意的是，为非凸目标函数推导了一个分析梯度，通过L BFGS B算法实现了高效优化。实证结果表明，相对于恒定权重和规定的时变DLP基线，这种动态闭环方法提高了风险调整后的性能和缩减控制。

Keywords :