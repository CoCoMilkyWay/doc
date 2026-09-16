# 量化前沿速递：CTA\[20260816\]

shameless 量化前沿速递 2026-08-17 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489662&idx=3&sn=170918aa557996c588e56b6be2bd032e&chksm=c3cacb6a4c1961c570ccf8c2d2842a6abd61f50291ec8033b3dddf61675ee71ae32b39904f73#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489662&idx=3&sn=170918aa557996c588e56b6be2bd032e&chksm=c3cacb6a4c1961c570ccf8c2d2842a6abd61f50291ec8033b3dddf61675ee71ae32b39904f73#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Tabular Foundation Models and the Unity of Economic Behaviour

表格式基础模型与经济行为的统一性

来源:ARXIV\_20260810

\[2\] A Scalable Bilevel Framework for Renewable Energy Scheduling

可再生能源调度的可扩展双层框架

来源:ARXIV\_20260810

\[3\] Optimizing Bidding Curves for Renewable Energy in Two Settlement Electricity Markets

两个结算电力市场中可再生能源竞价曲线的优化

来源:ARXIV\_20260810

\[4\] High Order Expansions of the Optimizer Map via Bell Polynomials

基于贝尔多项式的优化器映射的高阶展开

来源:ARXIV\_20260811

\[5\] Climate Conditioned Cascade Modeling for Multi Peril Reinsurance

多风险再保险的气候条件级联模型

来源:ARXIV\_20260811

\[6\] Anomaly detection in European cryptocurrency exchange traded products

欧洲加密货币交易所交易产品的异常检测

来源:ARXIV\_20260811

\[7\] Nash Peer to Peer Insurance Bargaining under Price Fairness and Coalitional Stability

价格公平和联盟稳定下的纳什点对点保险交易

来源:ARXIV\_20260811

\[8\] When LLM Agents Negotiate

当LLM代理进行谈判时

来源:ARXIV\_20260811

\[9\] Multi Credit Calibration via Elastically Stopped L vy Processes

通过弹性停止的L vy流程进行多信用校准

来源:ARXIV\_20260812

\[10\] Mastering Stochastic OLG Models in Continuous Time

掌握连续时间中的随机OLG模型

来源:ARXIV\_20260812

\[11\] An Optimal Energy Production Problem with Energy Source Switching and Load Following Nuclear Power Plants

核电站能源切换和负荷跟踪的最优能源生产问题

来源:ARXIV\_20260812

\[12\] Universality and Heterogeneity of Stylized Facts in Cryptocurrency and Equity Markets

加密货币和股票市场中程式化事实的普遍性和异质性

来源:ARXIV\_20260812

\[13\] LOB ID

LOB ID

来源:ARXIV\_20260814

\[14\] Fee Implied Volatility on Uniswap v3

Uniswap v3的费用隐含波动

来源:ARXIV\_20260814

### 

\[1\] Tabular Foundation Models and the Unity of Economic Behaviour

标题:表格式基础模型与经济行为的统一性

作者:Victor H. Aguiar

来源:ARXIV\_20260810

链接:https://arxiv.org/pdf/2608.06842

Abstract : Economics uses different behavioural models for risk, time, losses, valuation, and social choice. I study a unified choice experiment in which the same decision makers face all these domains. I hide a decision maker s choices in one domain and ask a frozen tabular foundation model to recover them from that decision maker s choices elsewhere and labelled choices by other participants. The foundation model improves on the training sample median, and the gain disappears when visible choices are shuffled across decision makers. I then estimate one random utility model over the foundation model s learned representation. This structural model applies the same utility function in every domain, retains most of the foundation model s reduction in prediction error, predicts domains excluded from utility estimation, and reproduces how behavioural measures co move across people. The resulting model separates three objects  a learned common choice domain, one systematic utility function on that domain, and one random component that generates stochastic choice on observed menus.

Keywords : 

Abstract :经济学对风险、时间、损失、估值和社会选择使用不同的行为模型。我研究了一个统一选择实验，在这个实验中，相同的决策者面对所有这些领域。我将决策者的选择隐藏在一个领域中，并要求一个冻结的表格基础模型从该决策者在其他领域的选择中恢复它们，并由其他参与者标记选择。基础模型改进了训练样本中值，当决策者之间的可见选择被打乱时，增益消失了。然后，我在基础模型的学习表示上估计了一个随机效用模型。这种结构模型在每个领域应用相同的效用函数，保留了基础模型在预测误差方面的大部分减少，预测了效用估计中排除的领域，并再现了行为指标在人与人之间的共同作用。由此产生的模型将三个对象分开——一个学习到的共同选择域，一个在该域上的系统效用函数，以及一个在观察到的菜单上生成随机选择的随机组件。

Keywords :

### 

\[2\] A Scalable Bilevel Framework for Renewable Energy Scheduling

标题:可再生能源调度的可扩展双层框架

作者:Dongwei Zhao, Vladimir Dvorkin, Stefanos Delikaraoglou, Alberto J. Lamadrid L., Audun Botterud

来源:ARXIV\_20260810

链接:https://arxiv.org/pdf/2211.13905

Abstract : Accommodating the uncertain and variable renewable energy sources (VRES) in electricity markets requires sophisticated and scalable tools to achieve market efficiency. To account for the uncertain imbalance costs in the real time market while remaining compatible with the existing sequential market clearing structure, our work adopts an uncertainty informed adjustment toward the VRES contract quantity scheduled in the day ahead market. This mechanism requires solving a bilevel problem, which is computationally challenging for practical large scale systems. To improve the scalability, we propose a technique based on strong duality and McCormick envelopes, which relaxes the original problem to linear programming. We conduct numerical studies on both IEEE 118 bus and 1814 bus NYISO systems. Results show that the proposed relaxation can achieve good performance in accuracy (0.7  gap in the system cost wrt. the least cost stochastic clearing benchmark) and scalability (solving the NYISO system in minutes). Furthermore, the benefit of this bilevel VRES quantity adjustment is more significant under higher penetration levels of VRES (e.g., 70 ), under which the system cost can be reduced substantially compared to a myopic day ahead offer strategy of VRES.

Keywords : 

Abstract :适应电力市场中不确定和可变的可再生能源（VRES）需要复杂和可扩展的工具来实现市场效率。为了考虑实时市场中不确定的不平衡成本，同时保持与现有顺序市场清算结构的兼容性，我们的工作对日前市场中计划的VRES合同数量采用了不确定性知情调整。这种机制需要解决一个双层问题，这对实际的大规模系统来说在计算上具有挑战性。为了提高可扩展性，我们提出了一种基于强对偶性和麦考密克包络的技术，将原始问题放宽为线性规划。我们对IEEE 118总线和1814总线NYISO系统进行了数值研究。结果表明，所提出的松弛方法在精度（系统成本与最小成本随机清算基准相差0.7）和可扩展性（在几分钟内求解NYISO系统）方面具有良好的性能。此外，在VRES的更高渗透率水平（例如70）下，这种双层VRES数量调整的好处更为显著，在这种情况下，与VRES的短视日前报价策略相比，系统成本可以大幅降低。

Keywords :

### 

\[3\] Optimizing Bidding Curves for Renewable Energy in Two Settlement Electricity Markets

标题:两个结算电力市场中可再生能源竞价曲线的优化

作者:Dongwei Zhao, Stefanos Delikaraogloub, Vladimir Dvorkin Alberto J. Lamadrid L., Audun Botterud

来源:ARXIV\_20260810

链接:https://arxiv.org/pdf/2501.18732

Abstract : Coordination of day ahead and real time electricity markets is imperative for cost effective electricity supply and also to provide efficient incentives for the energy transition. Although stochastic market designs feature the least cost coordination, they are incompatible with current deterministic markets. This paper proposes a new approach for compatible coordination in two settlement markets based on benchmark bidding curves for variable renewable energy. These curves are optimized based on a bilevel optimization problem, anticipating per scenario responses of deterministic market clearing problems and ultimately minimizing the expected cost across day ahead and real time markets. Although the general bilevel model is challenging to solve, we theoretically prove that a single segment bidding curve with a zero bidding price is sufficient to achieve system optimality if the marginal cost of variable renewable energy is zero, thus addressing the computational challenge. In practice, variable renewable energy producers can be allowed to bid multi segment curves with non zero prices. We test the bilevel framework for both single  and multiple segment bidding curves under the assumption of fixed bidding prices. We leverage duality theory and McCormick envelopes to derive the linear programming approximation of the bilevel problem, which scales to practical systems such as a 1576 bus NYISO system. We benchmark the proposed coordination and find absolute dominance over the baseline solution, which assumes that renewables agnostically bid their expected forecasts. We also demonstrate that our proposed scheme provides a good approximation of the least cost, yet unattainable in practice, stochastic market outcome.

Keywords : 

Abstract :协调日前和实时电力市场对于成本效益高的电力供应以及为能源转型提供有效的激励措施至关重要。尽管随机市场设计具有最低成本协调的特点，但它们与当前的确定性市场不相容。本文提出了一种基于可变可再生能源基准竞价曲线的两个结算市场兼容协调的新方法。这些曲线基于双层优化问题进行优化，预测确定性市场清算问题的每种情况的响应，并最终最小化日前和实时市场的预期成本。尽管一般的双层模型难以求解，但我们从理论上证明，如果可变可再生能源的边际成本为零，则具有零投标价格的单段投标曲线足以实现系统最优性，从而解决了计算挑战。在实践中，可以允许可变可再生能源生产商以非零价格对多段曲线进行投标。我们在固定投标价格的假设下，对单段和多段投标曲线的双层框架进行了测试。我们利用对偶理论和麦考密克包络推导出了双层问题的线性规划近似，该近似可扩展到1576节点NYISO系统等实际系统。我们对拟议的协调进行了基准测试，并发现了对基线解决方案的绝对主导地位，该解决方案假设可再生能源不可知地对其预期预测进行投标。我们还证明，我们提出的方案很好地近似了最小成本，但在实践中无法实现的随机市场结果。

Keywords :

### 

\[4\] High Order Expansions of the Optimizer Map via Bell Polynomials

标题:基于贝尔多项式的优化器映射的高阶展开

作者:Oleksii Mostovyi, Thaleia Zariphopoulou

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.08900

Abstract : Completely monotonic inverse marginal (CMIM) utilities, introduced in  MSZ24 , constitute a tractable class of preferences that includes many of the most important utility functions used in mathematical finance, such as power and exponential utilities. In stochastically dominant markets, their Bernstein representation induces a hidden linear structure in the dual optimization problem that serves as the foundation for the present analysis.In this paper, we investigate the sensitivity of optimal investment with respect to perturbations of investor preferences within the CMIM class. Exploiting Bernstein s representation theorem, we show that, under stochastic dominance, affine perturbations of Bernstein measures induce an affine representation of the dual value function. As a result, the dependence of the optimization problem on preferences can be analyzed through a scalar budget equation, allowing us to prove analyticity of the associated Lagrange multiplier with respect to the perturbation parameter and to derive convergent analytic expansions of arbitrary order for the primal value function and the optimal terminal wealth, with explicit recursive formulas expressed through Bell polynomials.

Keywords : 

Abstract :MSZ24中引入的完全单调逆边际（CMIM）效用构成了一类可处理的偏好，其中包括数学金融中使用的许多最重要的效用函数，如幂和指数效用。在随机主导市场中，它们的Bernstein表示在对偶优化问题中引入了一个隐藏的线性结构，这是本分析的基础。本文研究了CMIM类中最优投资对投资者偏好扰动的敏感性。利用Bernstein的表示定理，我们证明了在随机支配下，Bernstein测度的仿射扰动会导致对偶值函数的仿射表示。因此，优化问题对偏好的依赖性可以通过标量预算方程进行分析，使我们能够证明相关拉格朗日乘数相对于扰动参数的可分析性，并推导出原始值函数和最优终端财富的任意阶收敛解析展开式，显式递归公式通过贝尔多项式表示。

Keywords :

### 

\[5\] Climate Conditioned Cascade Modeling for Multi Peril Reinsurance

标题:多风险再保险的气候条件级联模型

作者:N.Karimi, E.Salavati, F.Shokrollahi

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.09456

Abstract : Climate perils are linked through event ordering and state dependent propagation, features not fully captured by joint loss distributions alone. This paper develops a Cascading Climate Risk Network (CCRN) for multi peril reinsurance that separates calendar scale climate conditioning from within event propagation on a directed acyclic graph (DAG). The model combines complementary log log triggering hazards with bounded severity activation, mapping physical states to insured losses via a capacity bounded demand surge transformation.For fixed shocks, the event scale cascade reaches a unique finite step closure. Monotone comparative statics provide a pathwise upper corner loss bound over rectangular stress sets, yielding a transparent contract level stress testing guarantee under common aleatory inputs.Comprehensive numerical experiments, including copula and Bayesian network benchmarks, sensitivity analyses, and uncertainty propagation, demonstrate that while central layer prices remain robust across matched marginal dependence structures, far tail and high layer behaviors differ materially. Directional propagation, annual event frequency, and dependence strength emerge as the principal risk drivers. The study provides a controlled synthetic verification of the proposed architecture.

Keywords : 

Abstract :气候风险是通过事件排序和状态依赖传播联系在一起的，这些特征并不能完全被联合损失分布所捕捉。本文开发了一个用于多风险再保险的级联气候风险网络（CCRN），该网络在有向无环图（DAG）上将日历尺度气候条件与事件内传播分离。该模型将互补的对数触发危害与有界严重性激活相结合，通过容量有界的需求激增转换将物理状态映射到保险损失。对于固定冲击，事件尺度级联达到独特的有限阶闭合。单调比较静力学提供了矩形应力集上的路径上角损失界，在常见随机输入下产生了透明的合同级应力测试保证。综合数值实验，包括copula和贝叶斯网络基准、敏感性分析和不确定性传播，表明尽管中心层价格在匹配的边际依赖结构中保持稳健，但长尾和高层行为存在实质性差异。定向传播、年度事件频率和依赖强度成为主要风险驱动因素。该研究为所提出的架构提供了受控的综合验证。

Keywords :

### 

\[6\] Anomaly detection in European cryptocurrency exchange traded products

标题:欧洲加密货币交易所交易产品的异常检测

作者:Julia Kończal, Rafał Połoczański

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.09576

Abstract : Cryptocurrency exchange traded products (ETPs) listed on European exchanges provide a regulated environment for studying intraday market anomalies. We study four Bitcoin and Ethereum ETPs traded on Xetra and Nasdaq Stockholm over the period January 2024   December 2025 using one minute bars. As a benchmark, we adopt an extreme value theory approach in which anomalous bars are defined as returns falling below a threshold estimated by fitting a generalised Pareto distribution to left tail exceedances. We then propose three new binary anomaly indicators. The first, a cross venue divergence anomaly, identifies venue specific price divergence between the two exchanges. The second is a no recovery anomaly that identifies extreme price drops followed by little or no recovery over the next ten active bars. The third is a momentum reversal anomaly that identifies extreme price drops following positive short term momentum. Although each anomaly type represents fewer than 1  of one minute bars, statistical analysis using Mann Whitney U tests shows that anomaly observations exhibit significantly higher effective spreads, higher values of liquidity related ratios, and more pronounced order flow imbalances than non anomalous bars. Furthermore, employing an out of sample prediction methodology with four classifiers   random forest, logistic regression, extreme gradient boosting, and light gradient boosting machine   shows that all four anomaly types are predictable one bar ahead, with AUC ROC values of up to 0.82. Permutation importance indicates that short term volatility and drawdown measures are generally more useful for prediction than microstructure variables.

Keywords : 

Abstract :在欧洲交易所上市的加密货币交易所交易产品（ETP）为研究日内市场异常提供了一个受监管的环境。我们使用一分钟柱状图研究了2024年1月至2025年12月期间在Xetra和纳斯达克斯德哥尔摩交易的四个比特币和以太坊ETP。作为一个基准，我们采用了一种极值理论方法，其中异常柱状图被定义为低于阈值的回报，该阈值是通过将广义帕累托分布拟合到左尾超越值来估计的。然后，我们提出了三个新的二元异常指标。第一种是跨场所差异异常，确定了两家交易所之间特定场所的价格差异。第二种是无复苏异常，即价格出现极端下跌，随后在接下来的十个活跃柱状图中几乎没有复苏。第三种是动量反转异常，它表明在正的短期动量之后出现了极端的价格下跌。尽管每种异常类型代表的一分钟柱状图不到1个，但使用Mann-Whitney U检验的统计分析表明，与非异常柱状图相比，异常观测结果显示出更高的有效点差、更高的流动性相关比率值和更明显的订单流不平衡。此外，采用四个分类器随机森林、逻辑回归、极端梯度增强和光梯度增强机的样本外预测方法表明，所有四种异常类型都可以提前一条预测，AUC ROC值高达0.82。置换重要性表明，短期波动性和下跌指标通常比微观结构变量更有用。

Keywords :

### 

\[7\] Nash Peer to Peer Insurance Bargaining under Price Fairness and Coalitional Stability

标题:价格公平和联盟稳定下的纳什点对点保险交易

作者:Tim J. Boonen, Wing Fung Chong, Kenneth Tsz Hin Ng, Tak Wa Ng

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.09859

Abstract : We study peer to peer (P2P) insurance contracting between a risk averse P2P reinsurer and multiple risk averse peers in an asymmetric Nash bargaining framework, where all agents seek to improve expected utility relative to their disagreement points. Consistent with the expected value premium principle, we impose a price fairness condition requiring each peer s expected contribution to be based on a common loading applied to the peer s expected loss. To justify the bargaining formulation relative to a standard fixed weight weighted sum optimization problem, we provide an axiomatic characterization showing that the Nash bargaining solution satisfies properties well suited to voluntary P2P insurance contracting in small pools. We establish the existence and uniqueness of the optimal contract and derive first order characterizations for the full , partial , and zero reinsurance regimes. To address subgroup formation, we develop computationally tractable sufficient conditions that rule out viable coalitional deviations, both with and without price fairness. Our numerical study investigates the impact of price fairness and pool size on the optimal contract and agents  welfare. Price fairness reduces dispersion in risk allocations and certainty equivalent loadings among peers. Regarding pool size, welfare need not increase monotonically, highlighting that risk pool expansion depends not only on diversification but also on the evolution of bargaining power.

Keywords : 

Abstract :我们研究了在非对称纳什讨价还价框架中，风险厌恶的P2P再保险公司和多个风险厌恶的同行之间的P2P保险合同，其中所有代理人都寻求相对于其分歧点提高预期效用。根据预期价值溢价原则，我们施加了一个价格公平条件，要求每个对等方的预期贡献基于应用于对等方预期损失的共同负载。为了证明讨价还价公式相对于标准固定权重加权和优化问题的合理性，我们提供了一个公理化的特征，表明纳什讨价还价解决方案满足非常适合小池中自愿P2P保险合同的性质。我们建立了最优合同的存在性和唯一性，并推导了完全、部分和零再保险制度的一阶特征。为了解决子群形成问题，我们开发了计算上可处理的充分条件，排除了可行的联盟偏差，无论是否存在价格公平。我们的数值研究调查了价格公平性和池规模对最优合约和代理人福利的影响。价格公平减少了同行之间风险分配的分散和确定性等效负载。关于池规模，福利不必单调增加，这突显了风险池的扩大不仅取决于多样化，还取决于议价能力的演变。

Keywords :

### 

\[8\] When LLM Agents Negotiate

标题:当LLM代理进行谈判时

作者:Chen Liang, Fasheng Xu

来源:ARXIV\_20260811

链接:https://arxiv.org/pdf/2608.07538

Abstract : As LLM agents move from decision support to autonomous procurement, firms need to know whether delegated negotiators create value, divide it predictably, and avoid money losing contracts. We study this in a canonical supply chain bargaining problem  a buyer with private demand information negotiates a quantity payment contract with an uninformed seller. We benchmark nine LLMs from OpenAI, Google, and Alibaba against a validated Perfect Bayesian Equilibrium across 9,840 LLM to LLM negotiations. First, capability governs value creation. Agents agree in 98.9  of negotiations and capture 95.4  of first best surplus undiscounted, but average 2.98 rounds against the benchmark s 1.25, and this delay erodes 21 34  of surplus. Capability also governs reliability  baseline models accept individually irrational contracts in 19.2  of cases, versus 0.0 0.6  at mid tier and flagship, making automated profit verification the binding guardrail below that threshold. Second, surplus capture is relational. Provider identity predicts who captures surplus better than capability rank  self play buyer shares average 40  for OpenAI, 50  for Google, and 70  for Alibaba s Qwen, an ordering that survives restricted communication and no discounting. Reversing which provider sells moves the division by 7 18 percentage points, and the capable Qwen flagship is the weakest cross family seller  vendor choice is a first order distributional decision. Third, the prompt is a strategic lever. Delegation separates the principal s economic patience from the agent s prompted strategic patience, a free deployment choice that is the single strongest driver of surplus division (90  of explained variance). Together these establish an equilibrium referenced audit of AI agents along three dimensions  discounted efficiency, distributional profile, and operational reliability.

Keywords : 

Abstract :随着法学硕士代理人从决策支持转向自主采购，公司需要知道授权谈判者是否创造价值，是否可以预测地分配价值，并避免亏损的合同。我们在一个典型的供应链谈判问题中研究了这一点，即具有私人需求信息的买方与不知情的卖方谈判数量支付合同。我们将来自OpenAI、谷歌和阿里巴巴的9个LLM与9840个LLM到LLM谈判中经过验证的完美贝叶斯均衡进行了基准测试。首先，能力决定价值创造。代理人在98.9次谈判中达成一致，并获得了95.4次未贴现的最佳盈余，但平均为2.98轮，而基准为1.25轮，这一延迟侵蚀了2134次盈余。能力还决定了可靠性基线模型在19.2种情况下接受单独的非理性合约，而在中端和旗舰店为0.0 0.6，这使得自动利润验证成为低于该阈值的约束护栏。其次，盈余捕获是关系性的。提供商身份可以预测谁获得了比能力排名更好的剩余份额——OpenAI的平均买家份额为40，谷歌为50，阿里巴巴的Qwen为70，这种订购在限制沟通和没有折扣的情况下仍然存在。反转哪家供应商的销售将使该部门提高7.18个百分点，而有能力的Qwen旗舰店是最弱的跨家族卖家。供应商的选择是一级分销决策。第三，提示是战略杠杆。委托将委托人的经济耐心与代理人提示的战略耐心分开，这是一种自由部署的选择，是盈余分配的最强驱动力（解释方差的90）。这些因素共同建立了对人工智能代理的均衡参考审计，包括贴现效率、分布概况和操作可靠性三个维度。

Keywords :

### 

\[9\] Multi Credit Calibration via Elastically Stopped L vy Processes

标题:通过弹性停止的L vy流程进行多信用校准

作者:Graeme Baker, Agostino Capponi

来源:ARXIV\_20260812

链接:https://arxiv.org/pdf/2608.10321

Abstract : We calibrate credit default swaps and index tranches with elastically stopped L vy processes  each firm defaults when the running supremum of a latent, spectrally positive distress process crosses an independent exponential barrier. This yields a Cox construction with totally inaccessible default times, while retaining the interpretability and explicit formulas of a structural approach. Adding a single common compound Poisson jump factor to every firm s latent driver gives a parsimonious multi credit model with simultaneous defaults, which is priced by an exact Wiener  Hopf Monte Carlo scheme. Its tractability rests on a single name result we prove  a finite partial fraction formula for the Laplace transform of the default probability under phase type jumps. On daily CDX North American High Yield and Investment Grade panels, our drivers attain the lowest out of sample errors in a six model field and reproduce the inverted spread curves of names heading into default, which a L vy subordinator provably does not. At the index level, the two parameter dependence structure closes  73    to  89    of the tranche pricing gap left by independent marginals with the dependence parameters frozen, and up to  95    once re marked to tranche quotes  our framework dominates a single factor Gaussian copula and the affine intensity benchmark of Duffie  G rleanu on both indices.

Keywords : 

Abstract :我们使用弹性停止的L-vy过程来校准信用违约掉期和指数部分，当潜在的、频谱正的困境过程的运行极值越过独立的指数障碍时，每家公司都会违约。这产生了一个具有完全不可访问的默认时间的Cox构造，同时保留了结构方法的可解释性和显式公式。在每个公司的潜在驱动因素中添加一个共同的复合泊松跳跃因子，得到了一个同时违约的简约多信用模型，该模型由精确的维纳-霍普夫蒙特卡洛方案定价。它的可处理性取决于一个单一的名称结果——我们证明了相位类型跳跃下违约概率拉普拉斯变换的有限偏分数公式。在每日的CDX北美高收益和投资级面板上，我们的驱动程序在六个模型字段中达到了最低的样本外误差，并再现了即将违约的名称的反向传播曲线，而L vy的从属者则无法证明这一点。在指数层面，双参数依赖结构在依赖参数冻结的情况下，关闭了独立边际留下的73至89个部分定价缺口，一旦重新标记为部分报价，我们的框架在两个指数上都主导着单因素高斯copula和Duffie G rleanu的仿射强度基准。

Keywords :

### 

\[10\] Mastering Stochastic OLG Models in Continuous Time

标题:掌握连续时间中的随机OLG模型

作者:Yves Achdou, Johannes Brumm, Lukas Frank

来源:ARXIV\_20260812

链接:https://arxiv.org/pdf/2608.11134

Abstract : We propose a comprehensive framework for solving overlapping generations (OLG) models in continuous time with both idiosyncratic and aggregate risk. Our general characterization of equilibrium through the master equation operates on the joint distribution over the continuous idiosyncratic states, age and wealth. Our computational strategy is to take a finite dimensional representation of this distribution as an input of a neural net which in turn outputs a finite difference representation of the (conditional) value function. This idea can be applied generally to heterogeneous agent models with aggregate risk, and we call it finite difference neural operator. Our method combines advantages from modern neural nets and traditional finite difference methods  It is grid free in the high dimensional distribution, and retains control on boundary conditions in low dimensional state variables. Moreover, our method is able to enforce shape constraints. We showcase its flexibility by solving a continuous time OLG model with aggregate risk alone where we characterize the distribution by its supporting function  and to an OLG model with both types of risk.

Keywords : 

Abstract :我们提出了一个综合框架，用于解决连续时间内具有特殊和聚合风险的重叠世代（OLG）模型。我们通过主方程对均衡的一般表征作用于连续特质状态、年龄和财富的联合分布。我们的计算策略是将该分布的有限维表示作为神经网络的输入，神经网络进而输出（条件）值函数的有限差分表示。这一思想可以普遍应用于具有聚合风险的异构代理模型，我们称之为有限差分神经算子。我们的方法结合了现代神经网络和传统有限差分方法的优点。它在高维分布中是无网格的，在低维状态变量中保留了对边界条件的控制。此外，我们的方法能够强制执行形状约束。我们通过求解仅具有聚合风险的连续时间OLG模型来展示其灵活性，在该模型中，我们通过其支持函数来表征分布，并求解具有这两种风险的OLG模型。

Keywords :

### 

\[11\] An Optimal Energy Production Problem with Energy Source Switching and Load Following Nuclear Power Plants

标题:核电站能源切换和负荷跟踪的最优能源生产问题

作者:Fabio Baschetti, Alessandro Gnoatto, Athena Picarelli

来源:ARXIV\_20260812

链接:https://arxiv.org/pdf/2608.10197

Abstract : The integration of weather dependent renewable generation increases the volatility of residual demand and raises the value of dispatchable low carbon flexibility. This paper studies the optimal operation of a load following nuclear power plant owned by a producer that must balance stochastic residual demand while accounting for ramping limits and costly changes in operating regimes. Nuclear output can be increased, decreased, or kept constant, and the production decision is formulated as a finite horizon optimal switching problem. We analyze both a closed economy benchmark, where excess production cannot be sold and shortages require costly back up generation, and an open economy setting, where the producer can trade electricity at prices driven by aggregate market residual demand. The value functions are characterized as viscosity solutions of a system of Hamilton Jacobi Bellman quasi variational inequalities, and optimal policies are computed using a monotone semi Lagrangian scheme. The numerical results show how shortage costs, switching costs, ramping capability, and market access shape optimal nuclear load following. The analysis highlights the economic value of controllable low carbon capacity in renewable intensive systems and provides implications for flexibility remuneration, balancing market design, and interconnection policy.

Keywords : 

Abstract :依赖天气的可再生能源发电的整合增加了剩余需求的波动性，提高了可调度低碳灵活性的价值。本文研究了生产商拥有的负载跟踪核电站的最佳运行，该核电站必须平衡随机剩余需求，同时考虑到运行制度的斜坡限制和代价高昂的变化。核输出可以增加、减少或保持恒定，生产决策被表述为有限时域最优切换问题。我们分析了封闭经济基准和开放经济环境，在封闭经济基准中，过剩的生产不能出售，短缺需要昂贵的备用发电，在开放经济环境中，生产商可以以总市场剩余需求驱动的价格交易电力。将值函数表征为哈密顿-雅可比-贝尔曼拟变分不等式系统的粘性解，并使用单调半拉格朗日方案计算最优策略。数值结果表明，短缺成本、转换成本、提升能力和市场准入如何塑造最佳核负荷跟踪。该分析强调了可再生能源密集型系统中可控低碳容量的经济价值，并为灵活性薪酬、平衡市场设计和互联互通政策提供了启示。

Keywords :

### 

\[12\] Universality and Heterogeneity of Stylized Facts in Cryptocurrency and Equity Markets

标题:加密货币和股票市场中程式化事实的普遍性和异质性

作者:Jaesung Kim, Changhee Cho, Jae Woo Lee

来源:ARXIV\_20260812

链接:https://arxiv.org/pdf/2608.10852

Abstract : This study investigates whether the macroscopic statistical maturity of cryptocurrencies implies dynamical equivalence with traditional equity markets. We analyze high frequency data (2020  2025) using the Complexity  Entropy Causality Plane (CECP) and directed horizontal visibility graphs (directed HVG) to uncover complex temporal patterns and time directed structures in the return series. While conventional stylized facts show striking convergence across all assets, structural diagnostics reveal a compelling paradox  cryptocurrencies appear more locally random than the equity benchmark during ordinary periods, yet exhibit significantly stronger directional time irreversibility around high visibility return events. The absolute return results show that large cryptocurrency fluctuations tend to begin abruptly and remain elevated afterward. Separate analyses of positive returns and negative return magnitudes show that this pattern is shared across cryptocurrencies on the upside but varies across assets on the downside. We conclude that statistical maturity is only skin deep  the underlying dynamical processes of mature cryptocurrencies remain fundamentally distinct from traditional benchmarks.

Keywords : 

Abstract :本研究调查了加密货币的宏观统计成熟度是否意味着与传统股票市场的动态等价性。我们使用复杂性熵因果平面（CECP）和有向水平可见性图（有向HVG）分析高频数据（2020-2025），以揭示回报序列中复杂的时间模式和时间导向结构。虽然传统的程式化事实显示所有资产都有惊人的趋同，但结构诊断揭示了一个令人信服的悖论——加密货币在正常时期比股票基准更具局部随机性，但在高可见性回报事件周围表现出明显更强的方向性时间不可逆性。绝对回报结果表明，加密货币的大幅波动往往突然开始，并在之后保持高位。对正回报和负回报幅度的单独分析表明，这种模式在加密货币的上行方面是共享的，但在下行方面因资产而异。我们得出的结论是，统计成熟度只是肤浅的——成熟加密货币的潜在动态过程与传统基准仍然有着根本的区别。

Keywords :

### 

\[13\] LOB ID

标题:LOB ID

作者:Andreea Bacalum, Zhuohan Wang, Ollie Olby, Martin Garaj, Namid Stillman

来源:ARXIV\_20260814

链接:https://arxiv.org/pdf/2608.13082

Abstract : Generative models of limit orderbook (LOB) data have advanced rapidly, but their evaluation often focuses on stylised facts and selected market statistics. These measures provide useful diagnostics but may not capture the joint temporal and cross level structure of order book trajectories. We introduce LOB ID, an embedding based framework that adapts the Fr chet Inception Distance (FID) and Monge Inception Distance (MIND) to LOB data. To obtain domain specific embeddings, we train the DeepLOB architecture on four months of Level 2 order book data for five equities. We show that LOB ID is stable across time, instruments, and embedding checkpoints, and rises monotonically under controlled distortions. We then construct a moment matching attack against FID and a deep book perturbation that evades statistic based evaluation. MIND remains substantially more sensitive to both distortions. Finally, we score five generative LOB models, spanning stochastic baselines and deep learning approaches, and find that LOB ID ranks them in line with the joint temporal and cross level structure each captures by construction.

Keywords : 

Abstract :限额订单（LOB）数据的生成模型发展迅速，但它们的评估通常侧重于风格化的事实和选定的市场统计数据。这些措施提供了有用的诊断，但可能无法捕捉到订单簿轨迹的联合时间和跨级别结构。我们引入了LOB ID，这是一个基于嵌入的框架，它将Frchet Inception Distance（FID）和Monge Inception Distance（MIND）适应LOB数据。为了获得特定领域的嵌入，我们在五个股票的四个月2级订单数据上训练DeepLOB架构。我们证明了LOB ID在时间、仪器和嵌入检查点之间是稳定的，并且在受控失真下单调上升。然后，我们构建了一个针对FID的矩匹配攻击和一个逃避基于统计的评估的深书扰动。MIND对这两种扭曲仍然更加敏感。最后，我们对五个生成性LOB模型进行了评分，这些模型跨越了随机基线和深度学习方法，并发现LOB ID根据每个模型通过构造捕获的联合时间和跨级别结构对它们进行了排名。

Keywords :

### 

\[14\] Fee Implied Volatility on Uniswap v3

标题:Uniswap v3的费用隐含波动

作者:Amy Oumayma Khaldoun

来源:ARXIV\_20260814

链接:https://arxiv.org/pdf/2608.13340

Abstract : Narrow Uniswap v3 liquidity ranges resemble short dated options, and Panoptic s streaming premium echoes the short maturity concentration of Black Scholes theta near the strike. This motivates a natural question  can implied volatility be extracted from Uniswap v3 and Panoptic using only on chain observables  A direct identification of theta with realized fee income is too strong, since fee income captures only the compensation leg of a narrow range LP position. The remaining leg, the cost of dynamically hedging the LP s negative convexity through arbitrage aligned trades, is formalized elsewhere as predictable loss or loss versus rebalancing and is not observable from fees alone. We therefore reformulate the object of interest. We derive   sigma  fee    2  cdot feeRate  cdot  sqrt Volume L  tick   , and interpret it as a DEX native fee implied volatility proxy  an observable, oracle free measure of fee flow relative to active liquidity. We show that recovering a structural latent volatility from pool observables alone is not identified in general, since aggregate volume mixes informed and uninformed flow while the missing hedging cost term depends on external price dynamics and arbitrage timing. What the pool data support directly is a fee implied activity index, not a Black Scholes consistent implied volatility.

Keywords : 

Abstract :窄的Uniswap v3流动性范围类似于短期期权，Panoptic的流式溢价与Black-Scholes theta在行权附近的短期集中度相呼应。这引发了一个自然的问题，即是否可以仅使用链上可观测值从Uniswap v3和Panoptic中提取隐含波动率。θ与已实现费用收入的直接识别太强了，因为费用收入仅捕获了窄范围LP头寸的补偿部分。剩下的部分，即通过套利对齐交易动态对冲LP负凸性的成本，在其他地方被形式化为可预测的损失或损失与再平衡，仅从费用中无法观察到。因此，我们重新表述了关注的对象。我们推导出西格玛费用2 cdot feeRate cdot sqrt Volume L tick，并将其解释为DEX原生费用隐含波动率代理，这是相对于主动流动性的可观察、无预言的费用流度量。我们表明，一般来说，仅从池可观测值中恢复结构性潜在波动性是不确定的，因为总量混合了知情和不知情的流量，而缺失的套期保值成本项取决于外部价格动态和套利时机。池数据直接支持的是费用隐含活动指数，而不是布莱克-斯科尔斯一致隐含波动率。

Keywords :