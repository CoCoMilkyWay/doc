# 量化前沿速递：机器学习\[20260726\]

shameless 量化前沿速递 2026-07-27 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489632&idx=4&sn=cd72c3ddb304bcc72d06c8d257cda476&chksm=c35a411a85b0833790d2d60354ca6e1186afab17a2c19d8cb38d42a206fa86c5e1a8d8ca42da#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489632&idx=4&sn=cd72c3ddb304bcc72d06c8d257cda476&chksm=c35a411a85b0833790d2d60354ca6e1186afab17a2c19d8cb38d42a206fa86c5e1a8d8ca42da#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] AlphaZeroBeta

AlphaZeroBeta

来源:ARXIV\_20260721

\[2\] Reinforcement Learning Guided NSGA II Enhanced with Gray Relational Coefficient for Multi Objective Optimization

基于灰色关联系数增强的NSGA II多目标优化强化学习

来源:ARXIV\_20260721

\[3\] Prediction of bank transaction fraud using TabNet an adaptive deep learning architecture

基于自适应深度学习架构TabNet的银行交易欺诈预测

来源:ARXIV\_20260722

\[4\] The Price of Quietness

沉默的代价

来源:ARXIV\_20260722

\[5\] Observable Matrix Dynamics of Stocks

股票的可观测矩阵动力学

来源:ARXIV\_20260722

\[6\] Licensing and Innovation Regimes in Pharmaceutical R&D

药品研发的许可与创新机制

来源:ARXIV\_20260723

\[7\] Predictive Extrema, Unprofitable Policies

预测性极端、不盈利的政策

来源:ARXIV\_20260723

\[8\] Group boarding for airplanes

飞机团体登机

来源:ARXIV\_20260724

### 

\[1\] AlphaZeroBeta

标题:AlphaZeroBeta

作者:Boris Belyakov

来源:ARXIV\_20260721

链接:https://arxiv.org/pdf/2607.18001

Abstract : Market neutral portfolios aim to generate consistent returns while offsetting systematic market risk. Traditional approaches based on factor models or convex optimization often underperform during market regime shifts or when structural assumptions break down. We propose AlphaZeroBeta, a deep reinforcement learning framework designed to deliver benchmark relative alpha (excess returns) with near zero beta (market neutrality). AlphaZeroBeta combines a composite reward function that balances risk adjusted excess return, benchmark correlation, and transaction costs with a CNN GRU policy trained end to end via Recurrent PPO and evaluated through a rolling walk forward protocol. Backtests covering 2014 2024 across seven equity indices show that the model achieves higher Sharpe ratios than the baselines while maintaining near zero benchmark correlations and competitive drawdowns.

Keywords : 

Abstract :市场中性投资组合旨在产生一致的回报，同时抵消系统性市场风险。基于因子模型或凸优化的传统方法在市场机制转变或结构假设失效时往往表现不佳。我们提出了AlphaZeroBeta，这是一个深度强化学习框架，旨在提供接近零贝塔（市场中性）的基准相对阿尔法（超额回报）。AlphaZeroBeta结合了一个复合奖励函数，该函数平衡了风险调整后的超额回报、基准相关性和交易成本，以及通过递归PPO端到端训练的CNN GRU策略，并通过滚动向前走协议进行评估。涵盖2014年至2024年七个股票指数的回溯测试表明，该模型实现了比基线更高的夏普比率，同时保持了接近零的基准相关性和竞争性提款。

Keywords :

### 

\[2\] Reinforcement Learning Guided NSGA II Enhanced with Gray Relational Coefficient for Multi Objective Optimization

标题:基于灰色关联系数增强的NSGA II多目标优化强化学习

作者:Zhiyuan Wang, Qinxu Ding, Ding Ding, Siying Zhu, Jing Ren, Yue Wang, Chong Hui Tan

来源:ARXIV\_20260721

链接:https://arxiv.org/pdf/2607.16194

Abstract : In modern financial markets, decision makers increasingly rely on quantitative methods to navigate complex trade offs among multiple, often conflicting objectives. This paper addresses constrained multi objective optimization (MOO) with an application to portfolio optimization for minimizing risk and maximizing return. To address existing gaps, we propose a novel reinforcement learning (RL) guided non dominated sorting genetic algorithm II (NSGA II) enhanced with gray relational coefficients (GRC), termed RL NSGA II GRC, which combines an RL agent controller and GRC based selection to improve convergence and diversity of Pareto fronts. The agent adapts evolutionary parameters online using metrics of hypervolume, feasibility, and diversity, while the GRC tournament operator ranks parents via a unified score considering dominance rank, crowding distance, and proximity to ideal reference. We evaluate the framework on the Kursawe and CONSTR benchmarks and a NASDAQ portfolio application. On the benchmarks, RL NSGA II GRC achieves convergence improvements of about 5.8  and 4.4  over NSGA II, while preserving well distributed non dominated solutions. In the portfolio application, it produces a smooth, densely populated efficient frontier supporting identification of the maximum Sharpe ratio portfolio (annualized Sharpe  1.92) and utility optimal portfolios for different risk aversion levels. The main contributions are three fold  1) we propose an RL NSGA II GRC method integrating an RL agent into the evolutionary framework to adaptively control parameters via generational feedback  2) we design a GRC enhanced binary tournament operator providing a comprehensive indicator to guide the search toward the Pareto front  3) we demonstrate, on benchmark MOO and a NASDAQ case study, that the method delivers improved convergence and well populated frontiers supporting actionable insights.

Keywords : 

Abstract :在现代金融市场中，决策者越来越依赖定量方法来在多个往往相互冲突的目标之间进行复杂的权衡。本文研究了约束多目标优化（MOO），并将其应用于投资组合优化，以最小化风险和最大化回报。为了解决现有的差距，我们提出了一种新的强化学习（RL）引导的非支配排序遗传算法II（NSGA II），该算法结合了RL代理控制器和基于GRC的选择，以提高帕累托前沿的收敛性和多样性。代理使用超容量、可行性和多样性指标在线调整进化参数，而GRC锦标赛运营商则通过统一的分数对父母进行排名，考虑支配地位、拥挤距离和与理想参考的接近程度。我们根据Kursawe和CONSTR基准以及纳斯达克投资组合应用程序评估该框架。在基准测试中，RL NSGA II GRC比NSGA II实现了约5.8和4.4的收敛性改进，同时保留了分布良好的非支配解决方案。在投资组合应用中，它产生了一个平滑、人口稠密的有效边界，支持识别不同风险规避水平的最大夏普比率投资组合（年化夏普1.92）和效用最优投资组合。主要贡献有三方面：1）我们提出了一种RL NSGA II GRC方法，将RL代理集成到进化框架中，通过代际反馈自适应地控制参数；2）我们设计了一个GRC增强的二进制锦标赛算子，提供了一个全面的指标来指导向帕累托前沿的搜索；3）我们在基准MOO和纳斯达克案例研究中证明，该方法提供了改进的收敛性和填充良好的边界，支持可操作的见解。

Keywords :

### 

\[3\] Prediction of bank transaction fraud using TabNet an adaptive deep learning architecture

标题:基于自适应深度学习架构TabNet的银行交易欺诈预测

作者:Prashanth BS, Manoj Kumar, Ariful Hoque, Nasser Al Muraqab, Immanuel Azaad Moonesar, Udo Christian Braendle, Ananth Rao

来源:ARXIV\_20260722

链接:https://arxiv.org/pdf/2607.18616

Abstract : The development of online banking has brought about an increase in fraudulent operations, which is a major problem for banks. This study delves into the urgent requirement for interpretable, scalable, and top notch fraud detection systems by using TabNet, an adaptable deep learning framework, on a Kaggle dataset consisting of actual bank transactions in India. Maximizing operational risk management by improving the accuracy of transaction anomaly detection and ensuring regulatory compliance through transparent models is the goal. We utilize a supervised learning pipeline that incorporates the Synthetic Minority Oversampling Technique (SMOTE) to ensure that classes are balanced. Subsequently, we conduct thorough exploratory data analysis (EDA) to identify patterns of fraud, both during specific times and across behaviors. On this dataset, five different deep learning architectures are tested  DNN, GRU, LSTM, CNN1D, and TabNet. Assessment of predictive performance was carried out using a 3 fold cross validation framework. With a ROC AUC of 0.9739 and an accuracy of 97.39  , TabNet considerably outperformed the competition. The method of sparse feature selection used improved interpretability, generalized better on tabular data, and produced fewer false positives and negatives. Critical insights for operational fraud detection systems and a contribution to the broader literature on explainable AI (XAI) in financial decision making are offered by the findings. Goals 8 and 16 of the Sustainable Development Agenda are supported by this study, which promotes inclusive economic growth and institutional transparency. Supporting strong, policy compliant, and interpretable decision support systems, it also offers practical use for real time implementation in banking infrastructure.

Keywords : 

Abstract :网上银行的发展带来了欺诈行为的增加，这是银行面临的一个主要问题。本研究通过在Kaggle数据集上使用TabNet（一种适应性强的深度学习框架），深入研究了对可解释、可扩展和一流的欺诈检测系统的迫切需求，该数据集由印度的实际银行交易组成。目标是通过提高交易异常检测的准确性和通过透明模型确保监管合规性来最大限度地提高运营风险管理。我们利用了一个监督学习管道，该管道结合了合成少数族裔过采样技术（SMOTE），以确保班级的平衡。随后，我们进行了彻底的探索性数据分析（EDA），以识别特定时间和跨行为的欺诈模式。在这个数据集上，测试了五种不同的深度学习架构——DNN、GRU、LSTM、CNN1D和TabNet。使用3倍交叉验证框架对预测性能进行评估。TabNet的ROC AUC为0.9739，准确率为97.39，明显优于竞争对手。稀疏特征选择方法提高了可解释性，在表格数据上得到了更好的推广，产生的误报和漏报更少。研究结果为运营欺诈检测系统提供了关键见解，并为金融决策中可解释人工智能（XAI）的更广泛文献做出了贡献。本研究支持可持续发展议程的目标8和16，促进包容性经济增长和机构透明度。它支持强大、符合政策和可解释的决策支持系统，还为银行基础设施的实时实施提供了实际用途。

Keywords :

### 

\[4\] The Price of Quietness

标题:沉默的代价

作者:Yao-pei Wang, Yong Tu, Yi Fan

来源:ARXIV\_20260722

链接:https://arxiv.org/pdf/2607.18677

Abstract : Using the outbreak of COVID 19 in Singapore as a quasi natural experiment, we investigate tenants  changing responses to road traffic noise in the rental housing market, using 46,980 transaction records between 2006 and 2022. Our difference in differences estimates show that road traffic noise decreases housing rents by 3.8  immediately after the pandemic outbreak and further declines by 12.7  in the subsequent year equivalent to 186.7 US dollars per month. The results are robust to parallel trend analysis, permutation placebo tests, and tests using alternative distance thresholds or distance to the nearest main road. Then, we adopt a machine learning text analysis of 10,425 rental housing advertisements, showing that tenants  preference for quietness increases by approximately 10  from 2019 into 2020. The new work from home business model and rising traffic from delivery services can explain for this pattern. To the best of our knowledge, this is the first paper using a large volume of transaction records to quantify city dwellers  willingness to pay for quietness in the COVID 19 context. Our results have policy implications for other nations and post pandemic era on the interaction among urban planning, transport networks, and human settlements, and shed light on the pathway to achieve sustainable development goals.

Keywords : 

Abstract :以新加坡爆发的COVID 19为准自然实验，我们使用2006年至2022年间的46980份交易记录，调查了租房市场中租户对道路交通噪音的反应变化。我们的差异估计表明，道路交通噪音在疫情爆发后立即使住房租金降低了3.8美元，并在随后的一年进一步降低了12.7美元，相当于每月186.7美元。结果对平行趋势分析、置换安慰剂测试和使用替代距离阈值或到最近主干道的距离的测试具有鲁棒性。然后，我们对10425个租赁住房广告进行了机器学习文本分析，结果表明，从2019年到2020年，租户对安静的偏好增加了约10个。新的在家工作商业模式和快递服务流量的增加可以解释这种模式。据我们所知，这是第一篇使用大量交易记录来量化城市居民在2019冠状病毒病背景下为安静付费的论文。我们的研究结果对其他国家和疫情后时代的城市规划、交通网络和人类住区之间的相互作用具有政策意义，并为实现可持续发展目标指明了道路。

Keywords :

### 

\[5\] Observable Matrix Dynamics of Stocks

标题:股票的可观测矩阵动力学

作者:Igor Halperin

来源:ARXIV\_20260722

链接:https://arxiv.org/pdf/2607.19005

Abstract : The Observable Matrix Dynamics (OMD) approach monitors the time development of complex non linear systems through the trajectory of a fixed size distance matrix and its spectrum. We apply it to the S &P 500 cross section over three crisis decades, the 2001 dot com bust, the 2007  2008 financial crisis, and the 2020 Covid crash, with three fixed size observables on a fixed universe. The arccos distance matrix of the rolling return correlations reads the correlation geometry  its effective dimension collapses at the 2008 and 2020 crises, while the 2001 bust is a dispersed unwind. Read against machine learning distance matrices, its spectrum stays in the un relaxed, pre learning regime with no low dimensional manifold, so the market never learns its correlation structure or relaxes to a stationary geometry. Subtracting the market factor exposes a coherent sector rotation, whose name level attribution identifies which stocks drive each crisis and in what order. At a short lookback these signals resolve precursors and forecast the endogenous 2008 crisis, though not the exogenous 2020 shock. The other two observables model the daily return and volatility rankings as Markov chains on their ranking spaces. The return chain has persistent, defensive led bellwethers and near reversible dynamics. The volatility chain is far more persistent, led by the financial sector, and is the only one to carry a weak, episodic arrow of time, flaring at market stress and matching volatility clustering and the Zumbach effect. All three matrices show coherent changes during market crashes.

Keywords : 

Abstract :可观测矩阵动力学（OMD）方法通过固定大小的距离矩阵及其谱的轨迹来监测复杂非线性系统的时间发展。我们将其应用于三十年来的标准普尔500指数横截面、2001年互联网泡沫破灭、2007年2008年金融危机和2020年新冠肺炎危机，在一个固定的宇宙中有三个固定大小的可观测值。滚动回报相关性的arccos距离矩阵读取了相关性几何，其有效维度在2008年和2020年的危机中崩溃，而2001年的萧条是分散的放松。与机器学习距离矩阵相比，它的频谱保持在未放松的预学习状态，没有低维流形，因此市场永远不会学习其相关性结构或放松到平稳的几何形状。减去市场因素后，就会出现一个连贯的行业轮换，其名称级别的归因确定了哪些股票推动了每次危机，以及以何种顺序推动。短期回顾，这些信号解决了前兆，并预测了2008年的内生危机，尽管不是2020年的外生冲击。另外两个可观测值将每日回报率和波动率排名建模为其排名空间上的马尔可夫链。回报链具有持续的、防御性主导的领头羊和近乎可逆的动态。由金融部门主导的波动链要持久得多，并且是唯一一个带有微弱、偶发性时间箭头的波动链，在市场压力下燃烧，并与波动集群和Zumbach效应相匹配。这三个矩阵都显示了市场崩盘期间的连贯变化。

Keywords :

### 

\[6\] Licensing and Innovation Regimes in Pharmaceutical R&D

标题:药品研发的许可与创新机制

作者:Michele Liberatore, Massimo Riccaboni

来源:ARXIV\_20260723

链接:https://arxiv.org/pdf/2607.20365

Abstract : We study how licensing affects the allocation of innovation in pharmaceutical R&D. We develop a model in which projects differ in both quality and innovation regime, distinguishing between incremental and novel innovations. Information precision is higher for incremental projects and lower for novel ones, generating different equilibrium dynamics in the market for technology. The model predicts that licensing sustains positive selection and competitive return equalization for incremental innovation, while novel projects may exhibit weaker screening consistent with lemons type frictions. Using product level data and Double Machine Learning methods, we test these predictions across success probabilities and monetary returns. We find that licensing increases success probability overall, but return equalization holds primarily for incremental projects. For novel innovation, licensing does not exhibit the same equilibrium adjustment, suggesting residual market imperfections. Instrumenting for licensing using exogenous pipeline shocks confirms this pattern causally  the competitive risk return trade off is preserved for incremental  rushed  licenses, but it breaks down for novel ones. Our results reconcile evidence on both competitive efficiency and information frictions in markets for technologies, showing that market performance depends systematically on the type of innovation being transacted.

Keywords : 

Abstract :我们研究了许可如何影响药品研发中的创新分配。我们开发了一个模型，在该模型中，项目在质量和创新制度上都有所不同，区分了增量创新和新颖创新。增量项目的信息精度较高，而新项目的信息精确度较低，从而在技术市场中产生不同的均衡动态。该模型预测，许可支持增量创新的积极选择和竞争回报均衡，而新项目可能表现出与柠檬型摩擦一致的较弱筛选。使用产品级数据和双机器学习方法，我们在成功概率和货币回报之间测试这些预测。我们发现，许可总体上提高了成功概率，但回报均衡主要适用于增量项目。对于新颖创新，许可并没有表现出同样的均衡调整，这表明市场存在残余缺陷。使用外生管道冲击进行许可的工具证实了这种模式，因为竞争性风险回报权衡对于增量的匆忙许可是保留的，但对于新的许可则会失效。我们的研究结果调和了技术市场中竞争效率和信息摩擦的证据，表明市场绩效系统地取决于所交易的创新类型。

Keywords :

### 

\[7\] Predictive Extrema, Unprofitable Policies

标题:预测性极端、不盈利的政策

作者:Ayoub Jadouli

来源:ARXIV\_20260723

链接:https://arxiv.org/pdf/2607.19453

Abstract : We audit whether candle based machine learning models can turn predictions of cryptocurrency extrema or short horizon outcomes into positive Binance Spot paper policies after assumed costs. Numerical results come from scripted fixed seed model runs and deterministic simulators  human supervised AI agents supported the July 20 evidence integrity revision through literature retrieval, separately tasked critique, artifact reconciliation, documentation, and source packaging, not trading decisions. The strongest later period evidence, conditional on extensive predecessor search, is negative  an unchanged ten pair mandatory daily selector lost 6.72   over 19 July cycles at an assumed 31 bps completed cycle cost, with 3 wins and 16 losses. In short model specific July evaluations, the validation selected local minimum policy returned  1.79  , while the local maximum sell to cash re entry policy underperformed continuous holding by 2.80    their gross mean advantages of 11.11 and 12.21 bps were below even the 21 bps stress. A Gurgul inspired, OHLCV only daily adaptation attained minimum maximum ROC AUC of 0.874 0.896 but average precision of only 0.134 0.116 and lost 44.30   over seven cycles, versus  41.20   for buy and hold. A forensic audit also downgraded an earlier One4All  30 day holdout   its dates had influenced prior architecture work, its four hour outcome horizon was not purged at split boundaries, it used same close entry, and its raw result directories were absent. Across the tested, mostly exploratory protocols, event ranking performance did not establish positive executable policy value. Every operational decision remains NO  TRADE.

Keywords : 

Abstract :我们审核了基于蜡烛的机器学习模型是否可以在假设成本后将加密货币极值或短期结果的预测转化为积极的币安现货政策。数值结果来自脚本化的固定种子模型运行和确定性模拟器——人类监督的人工智能代理通过文献检索、单独任务的评论、工件协调、文档和源代码打包，而不是交易决策，支持了7月20日的证据完整性修订。以广泛的前身搜索为条件，后期最有力的证据是负面的——在7月19日的周期内，10对强制性每日选择器以假设的31个基点的完成周期成本损失了6.72，有3胜16负。在7月份针对特定模型的短期评估中，验证选择的本地最低政策回报率为1.79，而本地最高卖出现金回笼政策的表现比持续持有低2.80，其11.11和12.21个基点的总平均优势甚至低于21个基点的压力。受Gurgul启发，仅OHLCV的每日适应达到了最小最大ROC AUC 0.874 0.896，但平均精度仅为0.134 0.116，在七个周期内损失了44.30，而买入并持有的平均精度为41.20。法医审计还降低了早期One4All 30天的拒绝评级，其日期影响了之前的架构工作，其四小时的结果范围没有在分割边界处清除，它使用了相同的关闭条目，并且没有原始结果目录。在测试的大多数探索性协议中，事件排名性能并没有建立积极的可执行策略价值。每一个运营决策都是禁止交易。

Keywords :

### 

\[8\] Group boarding for airplanes

标题:飞机团体登机

作者:Minyu Shen, Weihua Gu, Junqi Ma, Boqian Song, Li Zhen, Gang Kou

来源:ARXIV\_20260724

链接:https://arxiv.org/pdf/2607.21512

Abstract : Improving boarding efficiency reduces airplane turnaround time and improves passenger experience. Airlines typically assign passengers to a few sequential boarding groups using static seat based rules. Yet arrivals, seat choices, and luggage are sequential and random, and a static rule ignores the seats earlier passengers have already taken. We propose the first dynamic formulation of boarding group assignment. As each passenger checks in, we observe earlier passengers  seats and groups, the current passenger s seat, and optional luggage information, then assign a group while keeping companions together. We formulate dynamic group assignment as a Markov decision process and solve it with reinforcement learning (RL). The policy uses a convolutional neural network to encode the checked in seat assignment state and is trained by proximal policy optimization. The reward balances total boarding time and average individual boarding time.We benchmark the proposed RL policy against three companion compatible static policies (back to front, modified Steffen, and alternating block) in an in house simulator covering six single  and double aisle layouts. Back to front with optimized group sizes achieves the shortest total boarding time and average individual boarding time among the static benchmarks across all layouts. The dynamic RL policy further outperforms it on both metrics in every layout. On a representative case, the RL policy outperforms the optimal back to front by up to 9.8   in total boarding time and 22.8   in average individual time. Sweeping the reward weight yields an approximate Pareto frontier for operator choice. Trained policies remain robust under out of distribution operating conditions, including varying load factors, companion sizes, and luggage loads.

Keywords : 

Abstract :提高登机效率可以缩短飞机周转时间，改善乘客体验。航空公司通常使用基于静态座位的规则将乘客分配到几个连续的登机组。然而，到达、座位选择和行李是连续和随机的，静态规则忽略了较早乘客已经乘坐的座位。我们提出了寄宿小组分配的第一个动态公式。当每位乘客办理登机手续时，我们会观察之前的乘客座位和组别、当前乘客的座位和可选行李信息，然后分配一个组别，同时让同伴在一起。我们将动态组分配表示为马尔可夫决策过程，并用强化学习（RL）求解。该策略使用卷积神经网络对已登记的座位分配状态进行编码，并通过近端策略优化进行训练。奖励平衡了总登机时间和平均个人登机时间。我们在涵盖六种单通道和双通道布局的内部模拟器中，将拟议的RL策略与三种兼容的静态策略（前后、修改后的Steffen和交替块）进行基准测试。在所有布局的静态基准中，通过优化的团队规模，实现了最短的总登机时间和平均个人登机时间。动态RL策略在每个布局中的两个指标上都表现得更为出色。在一个具有代表性的案例中，强化学习策略在总登机时间和平均个人时间上比最佳前后策略高出9.8倍和22.8倍。扫描奖励权重会为操作员选择产生一个近似的帕累托边界。在非配送操作条件下，经过培训的政策仍然稳健，包括不同的负载系数、伴侣尺寸和行李负载。

Keywords :