# arxiv量化文献汇总翻译 20201224

金融狗 量化前沿速递 2020-12-24 23:02

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247483735&idx=2&sn=adc6b8528d66ddc89684faff42cd2d77&chksm=c3d2ce59cc1a29e30299e4d917cc7187e6a33f05e6160b5ca109e7e216ed941ab9676b1f863a#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247483735&idx=2&sn=adc6b8528d66ddc89684faff42cd2d77&chksm=c3d2ce59cc1a29e30299e4d917cc7187e6a33f05e6160b5ca109e7e216ed941ab9676b1f863a#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Cities in a world of diminishing transport costs

\[2\] Market Impact in Trader Agents

\[3\] Systemic Risk in Financial Networks

\[4\] Estimating The Effect Of Subscription based Streaming Services On The Demand For Game Consoles

\[5\] A machine learning solver for high dimensional integrals

\[6\] Topological data analysis and UNICEF Multiple Indicator Cluster Surveys

\[7\] Credit Freezes, Equilibrium Multiplicity, and Optimal Bailouts in Financial Networks

## 

\[1\] Cities in a world of diminishing transport costs

标题 : 交通成本不断降低的城市

作者 : Tomoya Mori, Minoru Osawa , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2012.12503

说明 : Comments: 4 pages, 2 figures

Abstract : Economic activities favor mutual geographical proximity and concentrate spatially to form cities. In a world of diminishing transport costs, however, the advantage of physical proximity is fading, and the role of cities in the economy may be declining. To provide insights into the long run evolution of cities, we analyzed Japan s census data over the 1970 2015 period. We found that fewer and larger cities thrived at the national scale, suggesting an eventual mono centric economy with a single megacity simultaneously, each larger city flattened out at the local scale, suggesting an eventual extinction of cities. We interpret this multi scale phenomenon as an instance of pattern formation by self organization, which is widely studied in mathematics and biology. However, cities dynamics are distinct from mathematical or biological mechanisms because they are governed by economic interactions mediated by transport costs between locations. Our results call for the synthesis of knowledge in mathematics, biology, and economics to open the door for a general pattern formation theory that is applicable to socioeconomic phenomena.

摘要 : 经济活动有利于地理上的相互接近，并在空间上集中形成城市。然而，在一个运输成本不断下降的世界里，近在咫尺的优势正在消失，城市在经济中的作用可能正在下降。为了深入了解城市的长期演变，我们分析了日本1970-2015年间的人口普查数据。我们发现，越来越少的大城市在全国范围内蓬勃发展，这意味着最终将形成一个单一中心的经济，同时拥有一个特大城市，每一个较大的城市都会在当地规模上趋于平缓，这意味着城市最终会消亡。我们将这种多尺度现象解释为数学和生物学中广泛研究的自组织模式形成的一个实例。然而，城市动态不同于数学或生物机制，因为它们是由不同地点之间的运输成本所介导的经济互动所控制的。我们的结果呼吁综合数学、生物学和经济学的知识，为适用于社会经济现象的一般模式形成理论打开大门。

## 

\[2\] Market Impact in Trader Agents

标题 : 交易者代理的市场影响

作者 : Zhen Zhang, Dave Cliff , 类别 ：Trading and Market Microstructure (q-fin.TR)

链接 : https://arxiv.org/pdf/2012.12555

说明 : Comments: To be presented at the 13th International Conference on Agents and Artificial Intelligence (ICAART2021), Vienna, 4th--6th February 2021. 15 pages; 9 figures

Abstract : Financial markets populated by human traders often exhibit market impact , where the traders quote prices move in the direction of anticipated change, before any transaction has taken place, as an immediate reaction to the arrival of a large (i.e., block ) buy or sell order in the market e.g., traders in the market know that a block buy order will push the price up, and so they immediately adjust their quote prices upwards. Most major financial markets now involve many robot traders , autonomous adaptive software agents, rather than humans. This paper explores how to give such trader agents a reliable anticipatory sensitivity to block orders, such that markets populated entirely by robot traders also show market impact effects. In a 2019 publication Church & Cliff presented initial results from a simple deterministic robot trader, ISHV, which exhibits this market impact effect via monitoring a metric of imbalance between supply and demand in the market. The novel contributions of our paper are (a) we critique the methods used by Church & Cliff, revealing them to be weak, and argue that a more robust measure of imbalance is required (b) we argue for the use of multi level order flow imbalance (MLOFI Xu et al., 2019) as a better basis for imbalance sensitive robot trader agents and (c) we demonstrate the use of the more robust MLOFI measure in extending ISHV, and also the well known AA and ZIP trading agent algorithms (which have both been previously shown to consistently outperform human traders). We demonstrate that the new imbalance sensitive trader agents introduced here do exhibit market impact effects, and hence are better suited to operating in markets where impact is a factor of concern or interest, but do not suffer the weaknesses of the methods used by Church & Cliff. The source code for our work reported here is freely available on GitHub.

摘要 : 由人类交易者组成的金融市场通常表现出市场影响，在任何交易发生之前，交易者报价朝预期变化的方向移动，作为对市场上一个大型（即，大宗）买入或卖出指令的即时反应，例如，市场中的交易者知道大宗买入指令会推高价格，所以他们会立即调整报价。现在大多数主要的金融市场都涉及到许多机器人交易者、自主的自适应软件代理，而不是人类。本文探讨如何给予这类交易者代理一个可靠的预期敏感度，以使完全由机器人交易者占据的市场也表现出市场冲击效应。在2019年出版的《Church&Cliff》中，展示了一个简单的确定性机器人交易员ISHV的初步结果，通过监测市场供需失衡的指标，展示了这种市场影响效应。本文的创新贡献在于（a）我们批判了Church&Cliff所使用的方法，揭示了它们的弱点，并认为需要更有力的不平衡度量方法（b）我们主张使用多级有序流不平衡（MLOFI Xu et al.）。，2019年）作为对不平衡敏感的机器人交易者代理更好的基础，（c）我们展示了在扩展ISHV时使用更稳健的MLOFI度量，以及众所周知的AA和ZIP交易代理算法（这两种算法之前都被证明始终优于人类交易者）。我们证明，这里介绍的新的不平衡敏感交易者代理确实表现出市场冲击效应，因此更适合于在影响是一个关注因素或利益的市场中操作，但不会受到Church&Cliff所用方法的弱点的影响。我们在这里报告的工作的源代码可以在GitHub上免费获得。

## 

\[3\] Systemic Risk in Financial Networks

标题 : 金融网络中的系统性风险

作者 : Matthew O. Jackson, Agathe Pernoud , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2012.12702

说明 : -

Abstract : We provide an overview of the relationship between financial networks and systemic risk. We present a taxonomy of different types of systemic risk, differentiating between direct externalities between financial organizations (e.g., defaults, correlated portfolios and firesales), and perceptions and feedback effects (e.g., bank runs, credit freezes). We also discuss optimal regulation and bailouts, measurements of systemic risk and financial centrality, choices by banks regarding their portfolios and partnerships, and the changing nature of financial networks.

摘要 : 我们概述了金融网络与系统性风险之间的关系。我们对不同类型的系统性风险进行了分类，区分了金融机构之间的直接外部性（如违约、相关投资组合和贱卖），以及感知和反馈效应（如银行挤兑、信贷冻结）。我们还讨论了最佳监管和救助、系统性风险和金融中心地位的衡量、银行对其投资组合和合作伙伴关系的选择，以及金融网络不断变化的性质。

## 

\[4\] Estimating The Effect Of Subscription based Streaming Services On The Demand For Game Consoles

标题 : 基于订阅的流媒体服务对游戏机需求的影响评估

作者 : Tung Yu Marco Chan, Yue Zhang, Tsun Yi Yeung , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2012.12704

说明 : -

Abstract : In this paper, we attempt to estimate the effect of the implementation of subscription based streaming services on the demand of the associated game consoles. We do this by applying the BLP demand estimation model proposed by Berry (1994). This results in a linear demand specification which can be identified using conventional identification methods such as instrumental variables estimation and fixed effects models. We find that given our dataset, the two stage least squares (2SLS) regression provides us with convincing estimates that subscription based streaming services does have a positive effect on the demand of game consoles as proposed by the general principle of complementary goods.

摘要 : 在这篇文章中，我们试图评估基于订阅的流媒体服务的实现对相关游戏机需求的影响。我们通过应用Berry（1994）提出的BLP需求估计模型来实现这一点。这就产生了一个线性需求规范，可以使用传统的识别方法，如工具变量估计和固定效应模型来识别。我们发现，根据我们的数据集，两阶段最小二乘（2SLS）回归为我们提供了一个令人信服的估计，即基于订阅的流媒体服务确实对游戏机的需求产生了积极的影响，正如补充商品的一般原则所建议的那样。

## 

\[5\] A machine learning solver for high dimensional integrals

标题 : 高维积分的机器学习求解器

作者 : Riu Naito, Toshihiro Yamada , 类别 ：Numerical Analysis (math.NA)

链接 : https://arxiv.org/pdf/2012.12346

说明 : Comments: 11 pages, 2 figures

Abstract : The paper introduces a very simple and fast computation method for high dimensional integrals to solve high dimensional Kolmogorov partial differential equations (PDEs). The new machine learning based method is obtained by solving a stochastic weighted minimization with stochastic gradient descent which is inspired by a high order weak approximation scheme for stochastic differential equations (SDEs) with Malliavin weights. Then solutions to high dimensional Kolmogorov PDEs or expectations of functionals of solutions to high dimensional SDEs are accurately approximated without suffering from the curse of dimensionality. Numerical examples for PDEs and SDEs up to 100 dimensions are shown by using second and third order discretization schemes in order to demonstrate the effectiveness of our method.

摘要 : 本文介绍了一种求解高维Kolmogorov偏微分方程（pde）的高维积分计算方法。新的机器学习方法是通过求解一个随机梯度下降的随机加权极小化问题而得到的，该方法是由具有Malliavin权的随机微分方程（SDEs）的高阶弱近似格式所启发的。然后精确地逼近高维Kolmogorov偏微分方程的解或高维随机微分方程解的泛函期望，而不受维数诅咒的影响。用二阶和三阶离散格式对高达100维的偏微分方程和随机微分方程进行了数值算例，以证明本文方法的有效性。

## 

\[6\] Topological data analysis and UNICEF Multiple Indicator Cluster Surveys

标题 : 拓扑数据分析和儿童基金会多指标类集调查

作者 : Jun Ru Anderson, Fahrudin Memic, Ismar Volic , 类别 ：Physics and Society (physics.soc-ph)

链接 : https://arxiv.org/pdf/2012.12422

说明 : Comments: 24 pages

Abstract : Multiple Indicator Cluster Surveys (MICS), supported by UNICEF, are one of the most important global household survey programs that provide data on health and education of women and children. We analyze the Serbia 2014 15 MICS dataset using topological data analysis which treats the data cloud as a topological space and extracts information about its intrinsic geometric properties. In particular, our analysis uses the Mapper algorithm, a dimension reduction and clustering method which produces a graph from the data cloud. The resulting Mapper graph provides insight into various relationships between household wealth  as expressed by the wealth index, an important indicator extracted from the MICS data and other parameters such as urban rural setting, ownership of items, and prioritization of possessions. Among other uses, these findings can serve to inform policy by providing a hierarchy of essential amenities. They can also potentially be used to refine the wealth index or deepen our understanding of what it captures.

摘要 : 联合国儿童基金会支持的多指标类集调查是提供妇女和儿童健康和教育数据的最重要的全球家庭调查方案之一。我们使用拓扑数据分析（topology data analysis）对塞尔维亚2014年15个MICS数据集进行分析，将数据云视为一个拓扑空间，并提取其内在几何特性的信息。特别地，我们的分析使用了Mapper算法，这是一种降维和聚类方法，它从数据云生成一个图。由此产生的映射图提供了对财富指数（从中等收入国家数据中提取的一个重要指标）所表示的家庭财富与城乡环境、物品所有权和财产优先顺序等其他参数之间各种关系的深入了解。在其他用途中，这些发现可以通过提供基本便利设施的层次结构来为政策提供信息。它们还可能被用来完善财富指数，或者加深我们对财富指数所包含内容的理解。

## 

\[7\] Credit Freezes, Equilibrium Multiplicity, and Optimal Bailouts in Financial Networks

标题 : 信贷冻结、均衡多重性与金融网络中的最优救助

作者 : Matthew O. Jackson, Agathe Pernoud , 类别 ：Computer Science and Game Theory (cs.GT)

链接 : https://arxiv.org/pdf/2012.12861

说明 : -

Abstract : We analyze how interdependencies between organizations in financial networks can lead to multiple possible equilibrium outcomes. A multiplicity arises if and only if there exists a certain type of dependency cycle in the network that allows for self fulfilling chains of defaults. We provide necessary and sufficient conditions for banks solvency in any equilibrium. Building on these conditions, we characterize the minimum bailout payments needed to ensure systemic solvency, as well as how solvency can be ensured by guaranteeing a specific set of debt payments. Bailout injections needed to eliminate self fulfilling cycles of defaults (credit freezes) are fully recoverable, while those needed to prevent cascading defaults outside of cycles are not. We show that the minimum bailout problem is computationally hard, but provide an upper bound on optimal payments and show that the problem has intuitive solutions in specific network structures such as those with disjoint cycles or a core periphery structure.

摘要 : 我们分析了金融网络中组织之间的相互依赖性如何导致多种可能的均衡结果。当且仅当网络中存在某种类型的依赖循环，允许默认的自我实现链时，才会出现多重性。我们给出了银行在任何均衡条件下偿付能力的充要条件。在这些条件的基础上，我们描述了确保系统偿付能力所需的最低救助金，以及如何通过担保一组特定的债务偿付来确保偿付能力。消除自我实现的违约周期（信贷冻结）所需的救助注资是完全可收回的，而防止周期外的连锁违约所需的援助则不可收回。我们证明了最小救助问题在计算上是困难的，但给出了最优支付的上界，并且证明了该问题在特定的网络结构（如不相交环或核心-外围结构）中有直观的解。