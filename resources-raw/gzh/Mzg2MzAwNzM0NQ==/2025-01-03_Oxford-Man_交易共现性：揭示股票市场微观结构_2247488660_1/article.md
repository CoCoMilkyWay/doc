# Oxford-Man | 交易共现性：揭示股票市场微观结构与价格形成的新视角

QuantML QuantML 2025-01-03 18:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488660&idx=1&sn=af147885f3d36f26f5d1cb8414f1e301&chksm=cfe08c8a2bee2bf3f45a0deddedece4a6eefc6e0865dd4a8939565b61b31219601b74c81c764#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488660&idx=1&sn=af147885f3d36f26f5d1cb8414f1e301&chksm=cfe08c8a2bee2bf3f45a0deddedece4a6eefc6e0865dd4a8939565b61b31219601b74c81c764#rd)

![](assets/001.png)

本文提出了一种基于交易时间临近性的交易共现性概念，并将其应用于股票市场微观结构研究。通过将每笔交易根据其与市场其他交易的时间临近性进行分类，深入探讨了不同类型交易对股票价格的影响，并开发了基于条件订单失衡（COI）的交易策略，取得了显著的投资回报。

## 1\. 研究背景与动机

随着主要股票交易所向电子交易转型，市场微观结构发生了巨大变革。低延迟交易技术的应用将交易延迟缩短至纳秒级别，市场参与者得以在交易策略中实现前所未有的盈利水平。每一笔交易都携带独特的信息，并对标的股票的价格变化产生影响，因此被学术界和从业者分类研究。

然而，现有研究大多基于单笔交易的特征进行分类，例如交易方向（买方发起或卖方发起）、交易者类型（机构投资者或个人投资者）等。本文则另辟蹊径，**根据交易时间临近性对交易进行分类**，并提出以下核心问题：

-   某些交易与其他交易以不同方式相互作用，是否包含有用信息？
    
-   这些相互作用如何影响股票价格变动？
    
-   能否借此揭示短期和长期的价格形成机制？
    

**研究动机源于市场参与者可以通过观察市场交易流做出交易决策这一事实。**  知情交易者倾向于将大额订单拆分成多个小额订单以隐藏其真实意图，而其他市场参与者则通过监控订单流来做出交易决策。高频交易（HFT）策略的发展，使得交易速度成为关键因素，因为机会稍纵即逝，可能只在微秒甚至纳秒级别内有效。

## 2\. 相关文献回顾（简要介绍）

本文的研究贡献主要体现在以下四个方面：

**(1)  将共现性分析应用于金融领域**

共现性分析是一种在空间模式分析中已被证明有效的统计方法，广泛应用于生物学、自然语言处理、计算机视觉等领域。在金融领域，共现性分析的应用主要集中在研究新闻文章中共现的股票，例如构建公司共现网络以识别公司间的竞争关系等。

本文开创性地提出**交易共现性**概念，并证明该技术有助于探索和洞察金融市场微观结构。

**(2)  深入研究市场交易活动之间的相互作用**

现有研究大多关注交易者之间的互动，例如高频交易者如何识别知情交易者（如机构投资者）并预测其他交易者的交易流等。

本文则创新性地将**交易共现性**作为分析单笔交易层面互动性的工具，并提供实证证据表明，交易共现并非偶然，交易在微观层面的互动传达了有关价格形成的有用信息。

**(3)  丰富了订单失衡与价格形成的文献**

研究表明，订单失衡的持续性可能源于两种方式：

-   知情交易者为了最小化市场影响，会将大额订单分拆成多个小额订单在较长时间内执行，导致订单失衡呈现自相关性。
    
-   羊群效应也会导致订单失衡。
    

本文则提出了一种**无需额外私有数据集即可分解无条件交易流的新方法**，并证明：

-   未区分交易类型的订单失衡不再对未来回报具有预测能力，这表明市场微观结构在过去几十年中发生了变化。
    
-   使用本文提出的方法分解后的交易流包含不同的信息内容，其条件订单失衡（COI）确实具有预测能力。
    

**(4)  拓展了基于订单流信号的交易策略研究**

许多研究表明，从订单流中提取的细粒度信息对股票回报具有显著的预测能力，可以用于制定盈利交易策略。本文提出了一种基于交易到达时间临近性分析交易流的方法，并从聚合交易流中提取出盈利交易信号。

## 3\. 交易共现性与交易流分解

### 3.1 交易共现性定义

对于每笔交易  xa  发生在时间  ta  ，我们定义一个预定义的邻域大小  δ  。如果另一笔交易在时间窗口  (ta - δ, ta + δ)  内到达，则认为该交易与  xa  共现。我们将阈值  δ  定义为邻域大小，将与  xa  共现的所有交易集合定义为交易  xa  的  δ  邻域，表示为  Bδ(xa) 。

![](assets/002.png)

### 3.2 交易流分解

基于交易共现性，我们将每只股票的所有交易分解为不同的类别，具体步骤如下：

![](assets/003.png)

**(1)  定义**

-   **参考集 M :** 定义一个固定股票集合作为自定义市场指数 M ，其交易在标记股票 i 的交易时也被考虑在内。
    
-   **市场集 M :** 定义所有股票 j ∈ M 的交易集合 M ，即 M = ∪ j∈M Xj 。
    
-   **参考集 M\_i :** 对于每只股票 i ∈ S ，构建一个参考集 M\_i = M - Xi ，其中包含市场集中除股票 i 以外的所有交易。
    
-   **邻域集合 Bδ(xa) :** 对于每笔交易 xa ∈ Xi ，配备其邻域中的交易集合 Bδ(xa) 。
    

**(2)  分类规则**

-   **孤立交易（iso）:** 如果交易 xa 不与任何其他交易共现，即 Bδ(xa) ∩ (Xi ∪ M\_i) = ∅ ，则将其标记为孤立交易。
    
-   **非孤立交易（nis）:** 如果交易 xa 的邻域中存在与其相同股票的其他交易，或者市场指数 M 中其他股票的交易，则将其标记为非孤立交易，即 |Bδ(xa) ∩ (Xi ∪ M\_i)| ≥ 1 。
    

**(3)  非孤立交易的进一步分解**

-   **非自我孤立交易（nis-s）:** 交易 xa 的 δ 邻域中仅包含与交易 xa 相同股票的交易（至少一个），即 |Bδ(xa) \\ Xi| > 1 且 |Bδ(xa) \\ M\_i| = 0 。
    
-   **非交叉孤立交易（nis-c）:** 交易 xa 的 δ 邻域中仅包含与交易 xa 不同股票的交易，即 |Bδ(xa) ∩ Xi| = 0 且 |Bδ(xa) ∩ M\_i| ≥ 1 。
    
-   **非两者孤立交易（nis-b）:** 交易 xa 的 δ 邻域中同时包含至少一个与其相同股票的交易，以及至少一个其他股票的交易，即 |Bδ(xa) ∩ Xi| ≥ 1 且 |Bδ(xa) ∩ M\_i| ≥ 1 。
    

### 3.3 条件订单失衡（COI）

在交易流分解的基础上，我们计算每种类型交易的每日条件订单失衡：

![](assets/004.png)

其中  N^{type,buy}_{i,t}  和  N^{type,sell}_{i,t}  分别表示股票  i  在交易日  t  的市场买单和卖单总数。如果分母为 0，则定义 COI 为 0。

## 4\. 实证分析

### 4.1 数据来源与预处理

本文使用 2017 年 1 月 3 日至 2020 年 12 月 31 日期间 457 只美国股票的数据，数据来源包括：

-   LOBSTER 数据库：提供纳斯达克交易所所有股票限价订单的详细记录。
    
-   CRSP 数据库：提供股票每日价格数据。
    
-   Kenneth R. French 的在线数据图书馆：提供市场因子、规模因子、价值因子、盈利能力因子、投资因子和动量因子等数据。
    

### 4.2 邻域大小 δ 的选择

为了选择合适的邻域大小  δ  ，我们构建了一个完全随机订单到达的零模型，并选择使经验共现性与零模型下的共现性差异最大的  δ  值。我们发现  δ  = 1 毫秒是一个合适的选择。

### 4.3 交易共现性的存在性

通过比较零模型下的理论共现概率和从数据中得出的经验值，我们证实了股票交易在 1 毫秒级别上的共现性存在，这表明总体交易量具有很强的跨资产互动成分。

### 4.4 交易流分解结果

根据交易共现性，我们将所有交易分为以下五类：

-   孤立交易（iso）
    
-   非孤立交易（nis）
    

-   非自我孤立交易（nis-s）
    
-   非交叉孤立交易（nis-c）
    
-   非两者孤立交易（nis-b）
    

统计数据显示：

-   孤立交易占总交易量的 28.55%，而非孤立交易则占 71.45%。
    
-   非自我孤立交易占非孤立交易的 29.75%，而非交叉孤立交易和两者非孤立交易分别占 17.27% 和 24.43%。
    

### 4.5 订单失衡描述性统计

对不同类型订单失衡的描述性统计显示：

-   所有类型的订单失衡都是正自相关的。
    
-   非交叉孤立订单失衡的滞后 1 自相关性相对较高，而非自我孤立订单失衡的滞后 1 自相关性则较低。
    
-   各类订单失衡之间存在正相关性，但强度不同，且可能相当低。
    
-   非孤立订单失衡与其子类型之间的相关性较低。
    

### 5\. 条件订单失衡对同期回报的影响

为了评估每种类型订单失衡对同期回报的影响，我们采用以下面板回归模型：

![](assets/005.png)

其中  r\_{i,t}  是股票  i  在时间  t  的回报； β\_p  是每个自变量的系数； Types  是回归中包含的 COI 类型集合； ε\_{i,t}  是假设均值为零且正态分布的残差项。

![](assets/006.png)

![](assets/007.png)

回归结果显示：

-   与之前的研究一致，未分解的订单失衡与回报呈正相关。
    
-   条件订单失衡（COI）也对同期回报产生显著的正向影响，尤其是孤立 COI。
    
-   分解后的非孤立交易的三种类型订单失衡（nis-s、nis-c 和 nis-b）对回报的影响相对较弱。
    
-   回归中包含多个 COI 类型时，调整后的 R2 显著提高，表明分解交易流有助于解释同期每日价格变化。
    

## 6\. 订单失衡对未来回报的预测能力

本章深入探讨了不同类型条件订单失衡（COI）对未来股票回报的预测能力，并提供了基于回归分析和投资组合排序方法的证据。

### 6.1 预测回归分析

为了检验交易流分解对回报预测的贡献，我们采用了与前一章相同的回归分析程序。具体来说，我们对**未来1天的市场超额回报**进行了面板回归分析，以当前COI为自变量，同时控制当前回报以及其他解释变量。

**回归模型如下：**

![](assets/008.png)

**主要发现：**

-   与同期影响不同，未分解订单失衡对未来回报的影响并不显著，其回归系数接近于零。这表明，在没有未来订单失衡的情况下，**Chordia 和 Subrahmanyam (2004) 提出的理论模型**在本研究期间没有得到支持。
    

![](assets/009.png)

-   然而，**交易流分解后的COI对未来回报具有预测能力**：
    

-   \*孤立（iso）**和**自我非孤立（nis-s）\*\*订单失衡与未来回报呈正相关，表明这些类型的交易流可能包含有关未来价格变动的有用信息。
    
-   **非孤立（nis）**、**非交叉孤立（nis-c）**和**两者非孤立（nis-b）**交易失衡与未来回报呈负相关，表明这些类型的交易流可能预示着价格反转。
    
-   **所有类型的分解COI**在回归中的调整后R²均高于未分解的COI，表明分解交易流可以提高回报预测能力。
    
-   即使仅包含控制变量的回归，其调整后R²也高于包含未分解订单失衡的回归，但低于包含任何类型COI的回归。这进一步强调了**交易流分解**在回报预测中的重要性。
    

**时间序列回归分析**进一步支持了上述结论：

-   对于大多数股票，不同类型COI的回归系数符号与面板回归结果一致。
    
-   调整后R²的分布呈右偏，表明大多数股票的预测模型都具有良好的解释力。
    

**年度回归分析**表明：

-   不同类型COI与未来回报之间的关系符号在大多数子时期内保持一致。
    
-   \*孤立（iso）\*\*COI的预测能力在所有时间段内均具有显著性，除了2020年（由于COVID-19，市场环境异常）。
    
-   与同期价格影响相比，调整后R²从2017年到2018年有所增加，并在2020年达到峰值，表明在动荡时期，市场效率较低，股票吸收价格压力的时间更长。因此，推断出的COI显示出预测能力。
    

![](assets/010.png)

### 6.2 基于失衡的投资组合排序

为了进一步验证不同类型COI与未来回报之间的正负关系，我们采用了投资组合排序方法，将订单失衡转化为投资组合。

![](assets/011.png)

**主要步骤：**

1.  **单排序投资组合：** 对于每种类型的COI，根据其失衡值将股票从低到高排序，并分成5个五分位投资组合。
    
2.  **双重排序投资组合：** 同时考虑多个特征，对每对COI进行独立排序，将股票分成5x5个双重排序投资组合。
    

**主要发现：**

**(1)  单排序投资组合（详见表9）**

-   **未分解订单失衡：** 投资组合回报为负，且随五分位数波动，表明未分解订单失衡与未来回报之间没有明显的线性关系。
    
-   **分解后的COI：**
    

-   \*孤立（iso）\*\*订单失衡：随着失衡值的增加，投资组合回报几乎呈单调增长（尽管在第二个五分位数略有下降），这加强了其与未来回报的正相关关系。
    
-   \*自我非孤立（nis-s）\*\*订单失衡：回报略有增加，表明存在微弱的正相关关系。
    
-   **非孤立（nis）**、**非交叉孤立（nis-c）**和**两者非孤立（nis-b）**订单失衡：平均回报随失衡值增加而下降，这与时间序列回归结果一致，证实了负相关关系，为交易流分解提供了证据。
    

**(2)  双重排序投资组合（详见表10）**

-   \*孤立（iso）**与**非交叉孤立（nis-c）\*\*双重排序投资组合：
    

-   在每个列中，随着孤立交易COI的增加，平均回报从低到高上升。
    
-   在控制孤立COI的情况下，随着非交叉孤立COI的增加，回报通常从低到高下降。
    
-   同时对最强的信号进行双重排序，产生了最高和最低的回报，分别位于块的右上角和左下角。
    
-   与单一信号排序相比，最强回报的幅度（18.20%和-16.62%）也有所提高。
    

-   \*孤立（iso）**与**其他逆转（nis-c 和 nis-b）\*\*双重排序投资组合也显示出类似的模式和改善。
    
-   **其他组合**的双重排序模式不明显，例如**孤立（iso）**与**自我非孤立（nis-s）**双重排序投资组合。
    

**结论：**

-   \*孤立（iso）\*\*COI和逆转信号包含不同的信息，同时纳入它们可以提高预测性能。
    

![](assets/012.png)

## 7\. 条件订单失衡的经济价值

本章探讨了条件订单失衡的经济价值，通过构建多空投资组合来实现。

### 7.1 多空投资组合构建与评估

我们基于失衡排序的五分位投资组合设计了实用的交易策略：

-   在每个交易日的上午9:30，买入第一个（或最后一个）五分位投资组合，并卖空最后一个（或第一个）五分位投资组合，以实现自平衡。
    
-   每天下午4:00收盘时平仓，以避免隔夜影响。
    
-   每日回报是买入和卖空失衡排序投资组合回报之间的差额。
    

**评估盈利能力的方法：**

-   比较投资组合的年化回报，以及年化夏普比率（Sharpe Ratio）。
    

### 7.2 盈利能力分析

**主要发现：**

-   **多信号纳入提高投资组合利润：** 例如，**孤立（iso）**和**非交叉孤立（nis-c）**双重排序投资组合的回报为23.33%，比单独排序于**孤立（iso）**和**非交叉孤立（nis-c）**COI分别高出16.57%和18.93%。**双重排序于孤立（iso）和非交叉孤立（nis-c）**COI的投资组合实现了34.87%的最高年化回报。
    
-   **夏普比率进一步证实了COI信号的经济价值：** 调整波动性后，我们的交易策略仍然有利可图，并且双重排序的表现优于单独交易信号。**双重排序于孤立（iso）和非交叉孤立（nis-c）**COI的投资组合实现了1.79的最高夏普比率，其次是**孤立（iso）和两者非孤立（nis-b）**排序投资组合的1.74。
    

![](assets/013.png)

**风险调整后的盈利能力：**

-   **异常回报：** 除了**孤立（iso）和自我非孤立（nis-s）**双重排序投资组合外，所有基于**孤立（iso）**COI的投资组合都产生了统计上显著的异常回报，这表明利润不能由常见的风险因素来解释。
    
-   **风险因素暴露：** **孤立（iso）和非交叉孤立（nis-c）**双重排序投资组合对SMB和UMD因素有显著暴露，而**孤立（iso）和非交叉孤立（nis-c）**双重排序投资组合对MKT、HML和CMA因素有显著加载。然而，**基于COI的投资组合**有相当大一部分回报无法用这些因素来解释。
    

**与其他基准投资组合的比较：**

-   与基于COI的投资组合相比，**基准投资组合**在调整因素后均没有表现出显著且正的异常回报。
    
-   **基于COI的投资组合**的R²值从3.16%到6.24%，与基准投资组合相比要低得多。
    
-   **未分解订单失衡**排序投资组合对Fama French 5因素有显著暴露，其R²为13.35%。此外，其他基准投资组合都可以通过风险因素显著解释，R²值从55.64%到99.52%不等。
    

![](assets/014.png)

## 8\. 稳健性分析

本章对交易共现性的识别和条件订单失衡的构建进行了稳健性分析。

**(1)  邻域大小效应：**

-   对不同邻域大小 δ 的分析表明，较小邻域大小的同时影响和预测能力模式是稳健的。
    
-   当 δ 达到50毫秒时，交易共现性作为过滤器的性能下降。
    
-   此外，我们在不同的 δ 值下实现了不同类型COI的最佳结果，这表明结合从多个 δ 值中提取的信号的方法具有潜在的好处。
    

**(2)  市场代表效应：**

-   使用不同的市场指数 M （例如S&P 100和Dow 30）进行交易流分解，结果表明，COI之间的相关性很高，多空投资组合的盈利能力仍然存在。
    
-   当使用S&P 500指数作为市场指数时，**双重排序于孤立（iso）和非交叉孤立（nis-c）**COI的投资组合实现了最高的夏普比率。
    
-   然而，当使用Dow 30（一个较小的市场指数）时，预测能力下降，一些投资组合变得无利可图。
    

**(3)  不同时段效应：**

-   我们分别研究了9:30-10:00、10:00-15:30和15:30-16:00的COI，并发现分解后的交易流的预测能力源于不同时期。
    
-   \*孤立（iso）和自我非孤立（nis-s）\*\*COI的最后一个小时的COI有助于预测未来回报。
    
-   相反，**非交叉孤立（nis-c）**COI的预测能力源于非最后一个半小时的时期。
    
-   对于**两者非孤立（nis-b）**交易，只有与10:00-15:30相关的COI有助于预测下一个交易日开盘到收盘的市场超额回报。
    

**(4)  体积订单失衡：**

-   除了交易数量外，我们还分析了基于交易量的订单失衡，并研究了相应的交易策略。
    
-   我们的发现在体积指标下仍然稳健。我们观察到与计数COI相同的模式，但注意到，与计数失衡相比，对体积失衡的同期回归的R²和相应多空投资组合的夏普比率普遍较低。
    
-   这一发现与之前的研究一致，该研究提供了证据表明，交易数量更好地捕捉了机构投资者为了最佳执行而拆分订单所产生的价格压力。
    

**(5)  投资组合盈利能力进一步分析：**

-   为了验证所提出的COI排序投资组合的盈利能力，我们对回测应用了交易成本。
    
-   假设所有股票都有相同的往返交易成本，我们测试了包括1、2、3、4和5个基点的成本率。
    
-   结果表明，**双重排序于孤立（iso）和非交叉孤立（nis-c）**COI的投资组合在各种成本情景下仍然有利可图，并且表现优于基准。
    
-   特别是，在最严格的场景下，**双重排序于孤立（iso）和非交叉孤立（nis-c）**COI的投资组合实现了22.27%的年化回报和1.11的夏普比率。
    

## 9\. 结论与未来方向

本文提出了一种基于交易共现性的交易流分解方法，并研究了其对股票回报的同期影响和预测能力，以及其经济价值。

**主要结论如下：**

-   分解后的交易流具有不同的价格影响。
    
-   孤立交易流的 COI 单独可以解释与使用所有交易的 COI 相同的同期回报变化量，而纳入其他交易流的 COI 可以进一步提高解释力。
    
-   对于预测能力，我们观察到未来回报与孤立和自我非孤立 COI 呈正相关，而与非孤立、非交叉孤立和两者非孤立 COI 呈负相关。
    
-   交易流分解具有显著的经济价值，基于前几日 COI 方向的交易策略可以显著提高交易策略的盈利能力。
    

  

  

![](assets/015.jpg)

  

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