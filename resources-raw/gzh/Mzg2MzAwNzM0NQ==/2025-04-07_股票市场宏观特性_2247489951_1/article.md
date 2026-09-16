# 股票市场宏观特性

QuantML QuantML 2025-04-07 22:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489951&idx=1&sn=62fe7be1d633cd79f8ab1c931f7d8327&chksm=cf8669477524fa8ffed0e8453a5a6800e607ca5eb6d152cc9ae7db38eca39140b6c45d54b607#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489951&idx=1&sn=62fe7be1d633cd79f8ab1c931f7d8327&chksm=cf8669477524fa8ffed0e8453a5a6800e607ca5eb6d152cc9ae7db38eca39140b6c45d54b607#rd)

本文深入探讨了美国股票市场的一些关键宏观特性，这些特性对管理大型股票投资组合至关重要，但在传统金融数学和计量经济学模型中并未得到充分体现。

### 一、引言：量化金融与股票市场分析

量化金融的发展与金融数据分析密不可分。过去几十年间，学术界和从业者积累了大量的实证研究，涵盖了个别资产和多资产价格在低频和高频下的时间行为，以及与宏观经济、基本面和统计因素相关的横截面特性。

**主要发展领域包括：**

-   **市场微观结构与限价订单簿建模：** 深入了解市场运作机制。
    
-   **粗糙波动率：**  捕捉金融市场波动的复杂特性。
    
-   **基于签名的模型：**  利用路径的代数特征进行建模。
    
-   **经济物理学：**  将物理学概念应用于金融市场分析。
    
-   **机器学习在资产定价中的应用：**  利用大数据和复杂算法进行预测。
    
-   **能源市场和加密货币：**  探索新兴市场的特性和规律。
    

尽管市场种类繁多，股票市场因其庞大的规模和融资与风险交易的基本功能，仍然是金融市场的核心。

**本文重点关注股票市场的宏观特性：**

-   **定义：**  依赖于市场中所有或大多数股票的量或属性，例如总市值或整体表现，通常由市值加权市场指数（如标普500指数）代表。
    

-   指数常被用作股票投资组合（无论是被动型还是主动型）的基准，并可通过交易型开放式指数基金（ETF）等可交易资产进行近似。
    
-   术语受统计物理学启发，在统计物理学中，人们会考虑体积、温度和压力等宏观量。
    
-   举例说明：可以将股票市场想象成一个星系，每只股票都是一颗恒星，那么市场指数就是星系总质量的代表，但还有其他有趣的宏观量，例如星系的形状、螺旋和旋转，这些特性会影响恒星，并受恒星影响，且人们对它们的理解还远远不够。
    
-   从主动管理型股票投资组合经理的角度来看，宏观特性显然很重要，因为它们会影响策略的绝对表现和相对于基准的相对表现。例如，研究表明，市场多样性（衡量市值权重的集中度）的变化与主动管理型大盘股投资组合的相对回报显著相关。宏观特性也与市场的整体稳定性有关。
    

**本文研究动机：**

-   本文的研究受到随机投资组合理论（SPT）的启发，该理论由Fernholz率先提出，为理解大型股票市场的某些宏观特性提供了全新视角，特别是那些以市值和/或回报来定义的部分。
    

-   **市场多样性和内在波动率（股票之间的相对波动率）** 在很长一段时间内似乎保持稳定，并且在适当的条件下，可以通过精心挑选的投资组合来利用这些特性超越市值加权基准。
    
-   **规模因子** 在实证金融中一直扮演着重要角色，但SPT更强调（相对）规模如何简化市场建模，描述其稳定性，并使我们能够深入分析一大类系统性再平衡投资组合的相对表现。
    
-   然而，许多受SPT启发的结果由于其技术性以及数学模型可能带来的限制（例如第3.1节讨论的相互作用粒子系统和侧重于功能生成投资组合），对非专业人士来说仍然难以理解。此外，SPT领域的大多数论文都侧重于理论发展。许多重要的实证问题，例如多样性和波动性的联合建模和预测，以及高维市场模型的校准和诊断，在很大程度上仍然悬而未决。
    

### 二、数据：CRSP数据库与美国股票市场

本文的研究重点是美国股票市场，其详细日度数据由美国证券价格研究中心（CRSP）提供。

**CRSP数据库包含：**

-   在纽约证券交易所（NYSE）、NYSE美国（NYSE American）、纳斯达克（NASDAQ）、NYSE Arca和BATS等主要美国交易所上市交易的股票的日度市值和回报数据。
    

-   不包含未在证券交易所上市交易的私营公司数据。
    
-   包含股息、企业行为和摘牌事件数据。
    
-   遵循\[111\]的做法，我们隐含地通过CRSP的ret和dlret字段（分别对应回报和摘牌回报）来处理企业行为对投资组合表现的影响，这些字段考虑了这些影响。我们推荐Ruf的Python笔记本\[110\]作为数据库的入门教程。
    
-   与\[111\]一样，我们仅限于普通股（更准确地说，是CRSP股票代码（shrcd）为10、11和12的证券），并排除了其他证券，如封闭式基金和房地产投资信托基金（REITs）。
    
-   虽然纽约证券交易所的股票数据可以追溯到1925年12月，但NYSE American的股票从1962年7月开始被纳入CRSP（纳斯达克股票从1972年12月开始）。NYSE Arca的股票在2006年3月被添加，但影响不大。
    
-   为了本文的目的，我们的数据集由CRSP数据库中1962年1月2日至2024年12月31日的普通股组成。
    
    ![](assets/001.png)
    

**图1概述了我们的CRSP数据集：**

-   **黑色（粗）系列：**  全市场中股票的数量。
    
-   **灰色（细）系列：**  覆盖至少90%总市值的最小股票数量。
    
-   **绿色（正）条形：**  新上市股票的数量。
    
-   **红色（负）条形：**  从市场中摘牌的股票数量。
    

-   前两个系列是日度的，后两个系列是年度的。
    
-   1962年和1972年的跳跃是由于纳入NYSE American和纳斯达克股票的技术调整。
    

尽管股票数量众多，但大部分市场资本集中在相对较少的大盘股中。例如，在2000-2024年期间，市值最大的1000只股票通常占市场总市值的90%以上。股票之间的资本集中度可以用市场多样性（第3.2节）的概念来量化。

![](assets/002.png)

### 三、资本分布曲线与市场多样性

#### 3.1 资本分布曲线

**资本分布曲线是SPT中最具代表性的对象之一。**

-   **定义：**  将股票按市值从大到小排序后，其对应的市值权重（以对数-对数尺度绘制）的曲线。
    

-   **观察结果：**  资本分布曲线的整体形状相当稳定，通常是凹的，并且在右端迅速衰减。
    
-   **解释：**  资本分布曲线的形状稳定性令人震惊，并需要解释。正如\[39\]第101-103页所指出的，这种稳定性被标准的多变量金融模型所忽视。
    
-   **进一步分析：**  使用凸主成分分析（PCA），可以发现资本分布曲线的变化大约80%可以由前两个凸主成分捕捉。此外，沿着第一个凸主成分的移动与市场多样性的变化密切相关。
    
-   **局限性：**  维度缩减方法通常无法捕捉股票的特异行为，尤其是对市场有重大影响的最大型股票。
    
-   **建模挑战：**  构建能够再现观察到的资本分布曲线特征的市场资本化随机模型是一个具有挑战性的问题。合理的现实模型不仅能提高我们对市场的理解，还能作为优化和回测交易和风险管理策略的场景生成器。
    
-   **可能的解决方案：**  Fernholz提出了一种具有深远意义的观点，即让股票的动力学取决于其当前排名。这种建模假设激发了基于排名的扩散模型，以及相关的过程，如波动率稳定化过程和多项式过程。
    

-   资本分布曲线通常在双对数尺度上可视化，即绘制 log k 对 log μ(k) 的图形。我们称 log k > log μ(k) 的图形为相对于给定宇宙的资本分布曲线（出于绘图目的，我们使用以10为底的对数）。
    
-   当 It = At 是完整宇宙时，我们称其为完整资本分布曲线。
    
-   **图3** 绘制了1962-2024年完整CRSP宇宙的完整资本分布曲线。
    
    ![](assets/003.png)
    

**基于排名的模型：**

-   **优势：**  关注基于排名的行为可以以简约的方式限制参数数量，因为这些特征通常更稳定，并消除了跟踪不断变化的证券集合中的依赖关系的需要。
    

-   例如，系统 (3.3) 由 2n 个参数指定，而基于证券名称的未受限协方差矩阵需要 2n(n+1) 个参数，其中 n 随着新证券的引入而增加。
    
-   在第5节中，我们将报告一些关于排名依赖性的强有力的实证证据。
    
-   **局限性：**  基于排名的模型并非易于分析，因为系数在状态变量中是断开的。此外，排名后的市场权重 u(k)(t) 和差距 log u(k)(t) - log u(k+1)(t) 的动态涉及局部时间、碰撞以及在多面体边界上的反射等微妙概念。
    
-   **未来方向：**  改进这些模型、它们的校准和预测能力，可能使用机器学习工具，如神经随机微分方程。此外，市场模型 (3.3) 是外生的；它们没有解释为什么以及如何出现所述的动力学。
    

#### 3.2 市场多样性

**多样性指数用于量化由多个“物种”组成的系统或种群的多样性或集中度。**

-   **在股票市场中：**  可以使用熵类度量来量化由市值权重或资本分布构成的概率向量的多样性。
    

-   **常用方法：**  香农熵 (3.4) 和参数化多样性度量 Dp (3.5)。
    
-   **关键观察：**  市场多样性往往在长期内“均值回归”。至少，市场权重向量 u(t) 往往会避开单纯形的某些区域，尤其是其顶点。
    
    ![](assets/004.png)
    
-   **图5**  显示了全CRSP宇宙的多样性时间序列。
    

-   **观察结果：**  多样性与股票总数 |At| 在一定程度上相关。这是由于熵（和其他合理的多样性度量）中的规模效应。
    

-   **局限性：**  由于规模效应，很难说 H(uAt(t)) 有一个固定的长期均衡值。
    

-   **进一步分析：**  当选择合适的子宇宙 It 且 |It| < K 时，多样性的行为更容易解释
    
-   **案例 (i)：**  It = At 是当天最大的 K 只股票，每天更新。
    

-   多样性波动在一个比完整宇宙更狭窄的区间内，但即使有这个限制，也很难论证存在一个固定的均衡值。
    

-   多样性似乎表现出短期到中期的趋势或动量。
    

-   市场多样性的几次突然下降与市场崩盘有关，例如2008年的金融危机和2020年的COVID-19。
    
      
    

-   **案例 (ii)：**  将整个时期1962-2024年划分为4个子区间 \[ti, ti+1\]（每个约15.75年）。对于 t 在 \[ti, ti+1\] 中，我们让 It = At ∩ Ati，即在 ti 日是最大的 K 只股票中仍然存在的股票。
    

-   观察到，多样性在所有子区间内普遍下降。换句话说，相对于 It 的资本分布变得越来越集中。
    
-   直观地说，这是由于股票的增长率差异很大，以及许多证券最终被摘牌。
    

-   **案例 (iii)：**  对于 (ii) 中的每个子区间 \[ti, ti+1\]，我们随机选择 K 只股票 Iti  在 At 中，其中 M = 1000，并且，对于 t ∈ \[ti, ti+1\]，让 It = Iti ∩ At。也就是说，我们跟踪随机选择的股票的作为封闭系统的多样性。我们为每个子区间生成25个批次。
    

-   再次观察到，It 的多样性普遍随时间下降。
    
-   随机选择的子宇宙通常不如 At ∩ Ati 多样，而 At ∩ Ati 通常不如 AK 多样。
    

-   **结论：**  由于资本分布是“稳定的”，而多样性是资本分布的函数，我们可以含糊地说“多样性是稳定的”，作为对典型事实1的推论。
    

-   说“多样性是均值回归的”需要存在一个（可能是变化的）均衡值，而我们未能令人信服地建立。
    

-   **典型事实3：**  固定股票集合的多样性往往会随时间下降。
    

-   **解释：**  资本分布的明显稳定性，以及由此产生的多样性，是由股票不断进出市场所支撑的。这种观察在经典的SPT模型（假设固定的股票集合）以及基于排名的扩散模型（如 (3.3)）中是不存在的。我们认为，在基于排名的模型中加入进出因素具有重要的理论和实际意义。
    

**市场多样性与投资组合表现：**

-   由于市场多样性对主动管理型投资组合的相对表现的影响（第3.2节的备注2），一个自然的问题是预测其未来价值。
    

-   在\[6\]中，作者使用宏观经济信息开发了一个广义树结构模型，并报告了相对于标准时间序列方法的预测能力优势。
    
-   即使是简单的模型也可能非常有用。例如，\[117\]的作者实现了一个回归模型（由理论分解 (A.8)  激发），制定了一个规则，当预期多样性下降时，通过切换到市值加权投资组合来减少等权重投资组合的回撤。
    
-   **未来方向：**  将多样性建模为独立的时间序列与构建一个具有现实行为的股票系统模型是不同的。我们再次强调经济模型的重要性，这些模型解释了为什么资本分布曲线（以及由此产生的多样性）会以这种方式表现；它们使我们能够理解观察到的稳定性是否真的是一个长期不变量，或者可能会根据市场变化而改变（例如，大型科技公司和人工智能的兴起）。
    
-   另一个可能具有实际意义的问题是使用股票、指数和ETF的期权价格来推断市场参与者对未来市场多样性价值以及可能的其他量（如内在波动性）的看法。
    
-   最后，我们提到了开发替代多样性度量的问题，这些度量考虑了诸如行业和不同股票之间的统计相似性等附加特征，以及用于比较不同规模市场的多样性的系统方法（包括财务解释）。
    

### 四、内在市场波动性

**股票市场的传统或绝对总波动性通常指的是其市场指数的波动性。**

-   对于美国股票市场，通常使用过去展望的历史波动性（例如标准差）和前瞻性的VIX（CBOE波动率指数），后者使用期权价格计算。
    
-   **内在市场波动性：**  指的是股票之间的相对波动性。
    

-   **重要性：**  相对波动性对于主动管理型投资组合超越市场是必要的，并提供了与交易决策相关的市场行为的补充信息。
    
-   **定义：**  使用超额增长率（EGR）的概念来量化内在市场波动性，在金融文献中也被称为多样化回报。
    

**超额增长率：**

-   **定义：**  考虑一个时间间隔 \[t0, t1\] 和一个集合 It0 ⊂ At0，使得股票 i ∈ It0 在 \[t0, t1\] 内的对数回报为 ri(t0, t1) ∈ R。给定一个概率向量 w = (wi)i∈It0 ∈ P(It0)，我们定义超额增长率 Yw(t0, t1)  在 \[t0, t1\] 期间并由 w 加权，由 (4.1) 给出。
    

-   **财务意义：**  Yw(t0, t1) 是具有权重 (wi) 的投资组合的对数回报与基础资产的加权平均对数回报之间的差额；这就是为什么它被称为超额增长率。
    
-   **特性：**  Yw(t0, t1) ≥ 0，并且（当 wi > 0 对于所有 i 时）当且仅当所有 ri(t0, t1) 相同时，Yw(t0, t1) = 0。因此，我们可以将 Yw(t0, t1) 视为在 \[t0, t1\] 期间实现的相对波动性的度量。
    
-   **其他特性：**  详见第4.1节。
    

**实证结果：**

-   **图7**  显示了不同频率下每期超额增长率 Yw（右）和累积超额增长率 Tw（左），其中 w(t) = μAt(t) 是相对于前 K = 1000 只股票市值权重。
    
    ![](assets/005.png)
    

-   **观察结果：**  累积超额增长率随时间大致呈线性增长（当 Δt = 5 时约为每年 3.5%）。
    
-   **进一步分析：**  如图7（右）和图8（左）所示，超额增长率在所有考虑的频率下都表现出明显的ARCH效应，并且在2000年和2008年的金融危机期间以及其他重大市场事件期间都很大。
    
    ![](assets/006.png)
    
-   **典型事实4：**  市场超额增长率与绝对市场波动性相关，并在时间上聚集。
    
-   **典型事实5：**  当市场多样性波动时，市场超额增长率往往更大，反之亦然。
    

### 五、基于排名的特性

**本节研究股票的行为如何系统地取决于其相对于市值的相对排名。**

#### 5.1 基于排名的波动性

**首先提供一个小定量说明，小盘股平均而言波动性更大。**

-   **图10**  显示了前500只股票的离散二次变化 QVk(t) 随时间变化的序列（左图）和终端值（右图）。
    
    ![](assets/007.png)
    

-   **观察结果：**  小盘股平均而言波动性更大，并且这种效应并非微不足道。
    
-   **典型事实6：**  小盘股平均而言波动性更大。
    

#### 5.2 排名转换概率

**图6  可视化了股票集合的排名随时间的变化。**

![](assets/008.png)

-   **进一步量化：**  通过实证估计每日排名转换的转换概率。
    

-   **方法：**  对于每个交易日 t（在整个样本期内）和排名 k ∈ {1, ..., 1000}，找到排名 k 的股票 ik(t)。如果其排名在 t+1 日变为 l，则排名变化为 l - k。根据我们的惯例，排名变化为正意味着股票变得相对较小。例如，对于 k = 2，排名变化的可能值为 -1, 0, 1, 2, ...。在摘牌的情况下，排名变化为 +0。
    
-   **结果：**  如图11所示。
    

-   **观察结果：**  随着排名的增加，排名变化的幅度在统计上更大。在排名1000时，平均每日排名变化（经过截断和平滑后）约为 0.156；排名1的值约为 0.024。
    
    **进一步分析：**  如果我们仅考虑每日排名变化的符号（正、零或负），则可以更清楚地看到模式，从而得到每个排名 k 的经验概率 p+(k), p0(k) 和 p\_(k)。
    

-   **观察结果：**  p+(k) > p\_(k)（有几个例外），并且差异 p+(k) - p\_(k) 随 k 增加大致呈线性增加。在排名1000时，差异（经过平滑后）约为 0.029。
    

  

-   **典型事实7：**  股票市值排名有增加（即变得相对较小）的趋势。
    

-   **解释：**  这种趋势乍一看可能与市场的整体稳定性以及缺乏证据表明股票的增长率系统地依赖于其排名相矛盾。我们再次强调，排名变化包括图2中可视化的进入和退出效应。我们在图11中观察到的转换概率模式反映了“纯粹”的排名转换以及进入和退出之间的微妙平衡。我们的发现强调了进入和退出在维持股票市场稳定性方面的重要性，并表明有可能在基于排名的模型的制定和校准中纳入其影响。
    

#### 5.3 排名转换强度

**小盘股的较大波动性表明，小盘股之间的排名转换更为频繁。**

-   **量化方法：**  引入一个经验量 Ak(t)，它衡量排名 k 处的排名转换的（累积）强度。
    

-   **定义：**  Ak(t) 的定义是由随机微积分中半鞅局部时间的离散化启发的。
    

-   **公式：**  详见第5.3节。
    

-   **观察结果：**  Ak(t) 随时间大致呈线性增加，并且随 k 增加而增加。此外，对于最大型股票（k 小），排名转换的强度非常小。
    

-   **图12**  显示了排名1到499的排名转换强度 Ak(t) 随时间变化的序列。
    

-   **解释：**  如图6所示，最大型股票大多保持在顶部，排名转换只是偶尔发生。
    

-   **典型事实9：**  排名转换对于小盘股来说更为剧烈。
    

### 六、投资组合表现

**本节在明确界定的实证环境中表明，市场多样性和内在波动性是解释某些投资组合（特别是具有各种参数的多样性加权投资组合）相对于市值加权投资组合的相对表现的有用指标。**

#### 6.1 实验设置

**实验目标：**  以最直接和尽可能令人信服的方式说明市场多样性和内在波动性的影响。

**主要步骤：**

1.  **时间划分：**  将整个样本期（1962-2024年）划分为63个时间段，对应于日历年份。
    
2.  **基准投资组合：**  跟踪市场指数的投资组合，更新频率为 f。
    

-   **初始化：**  在时间 te 初始化投资组合，其市值权重 wi(te) = μAK(t e)。
    
-   **再平衡：**  每隔 f 个交易日，这些投资组合重新平衡以持有前 K = 500 只股票的市值权重。
    
-   **处理摘牌：**  如果股票在再平衡时间之间被摘牌，其摘牌回报（如果提供）被视为证券上的最后一个非零回报，并且在此股票中的持有不会被重新分配给投资组合中的其他证券，直到下一个再平衡时间。
    

4.  **多样性加权投资组合：**  回测参数化的多样性加权投资组合 wpf（参见 A.7），参数为 p ∈ \[0, 1\] 和再平衡频率 f ∈ {1, 2, ... } ∪ {∞}。
    

-   **注意：**  根据构造，w1,f  是 (ii) 中的基准。
    

-   **解释：**  当 p = 0 时，投资组合是等权重，当 p = 1 时，投资组合是市值加权，因此我们可以将 p 视为插值参数。
    

-   **初始化：**  在 te 时初始化，使其权重为 wpf(te) = (Dp(μAt(te)) / Σi∈AK μi(te)) μi(te)  i ∈ AK。
    
-   **再平衡：**  然后每隔 f 个交易日重新平衡并再投资股息（和摘牌现金收益）到权重 wpf(t) = (Dp(μSt(t)) / Σi∈St μi(t)) μi(t)  i ∈ St  ，同时支付比例交易成本。
    

8.  **交易成本：**  在 (ii) 和 (iii) 中，所有交易活动（除了初始化）都按照\[111，第2.1节\]中描述的程序支付比例交易成本。鉴于\[21, 111\]，我们选择所有股票的购买和销售成本为 0.25%。
    

-   **选择依据：**  \[5\] 的实证研究和纳斯达克的报告\[95\]也支持选择这一数量级的成本。
    

#### 6.2 实证结果

**6.2.1  多样性和内在波动性对相对表现的影响**

-   **分析：**  将等权重投资组合 w0,10 相对于市值加权投资组合 w1,10（两者都每隔10天重新平衡）的年度表现与熵的变化和（累积）每日市场超额增长率（对于这两个量都是）进行回归。
    

-   **回归模型：**  详见 (6.1)。
    
-   **结果：**  拟合的 R2 和调整后的 R2 值分别为 0.78 和 0.77。
    

-   解释：  该模型在解释相对表现方面做得非常好。
    

-   **结论：**  估计的 β1 和 β2 值为正，这意味着再平衡的投资组合受益于市场多样性的积极变化和较大的内在波动性。
    

-   **观察结果：**  从这些系数的值（以及 A log H 和 ΔTu 的典型大小）可以看出，在短期（比如说一年），市场多样性的变化对相对表现的影响大于内在波动性。
    

-   **解释：**  β0 的估计值为负；这可以归因于交易成本（相对于基准）的增加。
    

-   **结论：**  此外，修改估计的系数，这些结论对投资组合 wpf 和基准 w1,f 的参数变化具有稳健性，这凸显了这些解释变量的概念重要性。
    

**6.2.2  对投资组合规格的敏感性**

![](assets/009.png)

-   **分析：**  基于图13的分析，我们可以调查投资组合 wpf 历史上实现的表现范围。
    

-   **图14**  说明了通过同时改变 p 和 f 来实现的投资组合的年度表现，以及 (6.1) 中的解释变量。
    
    ![](assets/010.png)
    

-   **观察结果：**  在大多数年份，投资组合 wpf,20 的超/低表现是单调的，表现为条形从黑色到白色的单调变化。
    

-   **结论：**  当熵增加时，较低的 p 值往往表现更好，反之亦然。
    

-   **图14 顶部右侧：**  显示了等权重投资组合 w0,f 相对于买入并持有（最初等权重）投资组合 w0,∞  的年度表现，对于不同的固定再平衡频率，f。
    

-   **结论：**  与顶部左侧面板不同，这里的关系通常不是单调的。有很多年份，中间的 f 值表现更好。
    

-   **观察结果：**  对于大多数年份，在决定超/低表现程度上，频率的选择不如 p 的选择重要。
    

-   **结论：**  尽管如此，我们观察到，频繁的再平衡（比如说，每1-2天）在大多年份在0.25%的交易成本下表现不佳。
    

-   **观察结果：**  在2000年和2008年的金融危机期间，正确的再平衡决策似乎对投资组合回报有重大影响。
    

-   **图14底部右侧：**  显示了累积每日超额增长率与年度超额增长率之间的差异，用于我们回测中的日历年份。
    

-   **解释：**  这个统计数据捕捉了这两个不同再平衡尺度的内在波动性之间的差异。
    

-   **结论：**  然而，我们看到这与由于 f 的变化而导致的性能差异只有弱正相关关系。这并不意外，因为超额增长率对投资组合回报的贡献在短期时间范围内是二阶效应（参见例如图13），并且关系的强度可能会被许多其他市场因素所混淆，包括交易成本、违约和可变的成分证券集合。
    

**6.2.3  夏普比率和回撤**

-   **分析：**  在随机投资组合理论的框架内，相对较少的工作考察了投资组合风险和风险调整后的回报。在其实证分析中，\[111\] 报告了几个功能生成投资组合的历史夏普比率，并说明了随着交易成本增加而近似线性下降。相关理论研究包括回撤约束下的增长优化（例如 \[38\] 和 \[83，第4.1节\]）。更近期，第一和最后作者在 \[20\] 中提出了一个优化框架，允许灵活的市场多样性敞口。为了解决这一差距，我们在这里简要报告了一些多样性加权投资组合 wpf  的风险特征，这些投资组合一直是我们实证研究的中心。
    

**图15  显示了（大约）每月重新平衡的多样性投资组合 wpf  的风险统计数据的散点图。**

![](assets/011.png)

-   **左侧面板：**  显示每个日历年的夏普比率（基于每日回报）与最大回撤。
    

-   **观察结果：**  总体而言，夏普比率与回撤之间存在逆关系，夏普比率较高的年份往往经历较小的回撤。
    
-   **结论：**  投资组合和多样性回撤呈正相关，尽管投资组合回撤在绝对值上更大（参见图13中的相对回报）。
    
-   **观察结果：**  值得注意的是，夏普比率和回撤都表现出对 p 的非线性依赖性，有些年份对 p 几乎没有敏感性，而其他年份则表现出重大变化。
    
-   **结论：**  平均而言，增加 p 略微降低了回撤的幅度，并削弱了对多样性回撤的敏感性。这与较低 p 值超重小盘股，导致更高的换手率和更大的投资组合攻击性这一事实相一致。对功能生成投资组合的风险属性的更深入理解仍然是未来研究的重要方向。
    

### 七、结论

本文对美国股票市场的几个宏观特性进行了系统的实证研究，使用了CRSP数据库。在此过程中，我们阐述了和强调了若干新老典型事实。特别令人感兴趣的是，进入和退出在产生稳定的生态系统方面的重要性。在整个分析中，我们努力提出了一些受随机投资组合理论和我们研究结果启发的新的研究方向，并指出了我们了解的相关工作。我们所有的分析都可以通过我们仓库中的代码进行复制，我们鼓励感兴趣的读者与研究进行互动。特别是，其中提供的回测引擎可能会引起研究人员和从业者的独立兴趣。除了本文讨论的问题外，我们还强调了以下进一步调查的方向：

**(i)  其他市场：**  大多数随机投资组合理论的实证研究主要考虑美国股票市场，这主要得益于方便的CRSP数据库。 \*  **研究方向：**  我们的典型事实在多大程度上可以推广到过去和现在的其他股票市场，这一点很有趣。此外，可以考虑将几个市场（例如所有亚洲市场）作为一个整体。虽然我们预计许多特性（例如资本分布曲线的稳定性以及排名转换的强度）是跨市场的，但也有一些重要的差异。例如，考虑MSCI韩国指数\[1\]，它涵盖了约85%的韩国股票市场。截至2024年7月，最大的公司三星电子就占据了指数的30%以上。在这个意义上，韩国市场比美国市场集中得多。 \*  **其他应用：**  随机投资组合理论提供的视角也可以应用于非股票市场。最近的论文\[65\]已经证明了其在商品期货市场的成功应用。由于这些替代市场的特性各不相同，因此从宏观角度研究它们会很有趣。例如，这些商品市场没有传统意义上的“进入”和“退出”。

**(ii)  其他量和高频数据：**  在本文中，我们侧重于以市场市值和回报来定义的宏观特性。其他量，例如交易量、签名（以粗糙路径理论的意义上）\[34\]、行业、期权价格33和交易所交易基金，可能会提供额外的见解。此外，CRSP数据库提供的是日度数据，而不是日内数据。SPT启发的对高频数据分析是一个有前途的方向，但基本上是开放的；我们唯一了解的工作是\[60\]，它研究了与做市商赚取的利润有关的超额增长率的日内特性。一个可能的方向是研究日内回报分布（参见例如\[127\]）并将其与市场市值和其他量联系起来。

**(iii)  在现实条件下进行适应性投资组合选择：**  我们的实证研究和第6节中进行的回测自然地提出了在大量但不断变化的资产数量和交易成本下进行系统化的投资组合选择方法的研究。空头头寸、衍生品和适应性再平衡频率也可以考虑。不用说，这些以及其他问题都涉及所有实际投资组合，但不容易纳入金融数学中的理论模型。我们希望我们的工作能够成为理论和实践之间的桥梁。

  

  

  

论文及代码见星球，加入QuantML星球，与星主与800+专业人士一起交流学习：

![](assets/012.jpg)

  

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