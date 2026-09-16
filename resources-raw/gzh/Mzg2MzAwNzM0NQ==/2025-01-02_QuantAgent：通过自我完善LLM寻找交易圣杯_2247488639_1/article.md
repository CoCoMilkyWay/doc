# QuantAgent：通过自我完善LLM寻找交易圣杯

QuantML QuantML 2025-01-02 17:48 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488639&idx=1&sn=7d6dabd0bf6bee6ad93bce61a3c2f39f&chksm=cfdb7fb3f453ddb17009506ab01ebdebb2a374d4e3ea76d3143d7309a31b02e06033526946e3#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488639&idx=1&sn=7d6dabd0bf6bee6ad93bce61a3c2f39f&chksm=cfdb7fb3f453ddb17009506ab01ebdebb2a374d4e3ea76d3143d7309a31b02e06033526946e3#rd)

### 

![](assets/001.png)

  

摘要

基于大语言模型（LLM）的自主代理在制定计划和解决现实世界挑战方面取得了显著进展。然而，将这些代理应用于特定领域，如量化投资，仍然是一项艰巨的任务。其核心挑战在于如何高效地构建和整合一个领域特定的知识库，以便代理在学习过程中使用。本文提出了一种原则性的框架来解决这一挑战，该框架包含一个双层循环。在内层循环中，代理通过与模拟环境交互来改进其响应，而在外层循环中，这些响应在现实世界中进行测试，以自动增强知识库并获得新的见解。此方法能够使代理逐步逼近最优行为，并且效率可以得到保证。此外，通过一个名为 QuantAgent 的自主代理来实现这一框架，该代理用于挖掘交易信号。实证结果展示了 QuantAgent 在发现可行的金融信号和提高金融预测准确性方面的能力。

### 1\. 引言

大语言模型（LLM）的兴起（如 OpenAI 的 GPT 系列和 Touvron 等人的工作）引发了自主代理领域的显著进步，扩展了它们规划和解决复杂现实任务的能力。然而，将这些强大的语言模型应用于特定领域（如量化投资）带来了独特的挑战。一个关键问题是如何向这些模型提供特定领域的金融知识，使其能够像该领域的专家一样解决复杂问题。

当前的主要问题是领域知识的来源和整合。在那些需要丰富经验和专业技术知识的特定领域，构建一个全面的知识库通常需要大量的人力投入。同时，传统方法依赖于通过微调将知识整合到代理的参数化内存中，或者在推理过程中通过检索增强生成技术引用外部数据库。

然而，这些方法面临重大障碍。构建一个广泛而准确的领域知识库不仅在人力成本上高昂，而且在某些领域（如开发金融阿尔法数据库用于量化投资策略）可能不切实际或无法实现。此外，当前的学术研究领域需要一种更原则性的框架，能够系统地评估知识整合对代理的影响，从而支持知识增强代理的发展。

本文提出了一种原则性的双层框架，旨在以最小的干预自主开发领域特定的知识库，同时保持高质量。该框架的核心是一个嵌套循环系统：在内层循环中，代理通过与模拟环境交互来改进其响应，该模拟环境由内部知识库定义。相反，在外层循环中，代理的响应在现实世界中进行评估，自动生成反馈以进一步丰富内部知识库。这种迭代过程推动代理向更好的性能发展，最终实现自主积累丰富的知识库。

通过理论分析来支持该框架，证明内层和外层循环都能有效地收敛到最优解。这种收敛性是通过应用强化学习中的分析技术来证实的，将自我改进机制置于马尔可夫决策过程（Markov Decision Process）的背景下。由此产生的框架不仅涵盖了各种现有的自我改进方法，而且还在某些假设下被证明是有效的。

### 2\. 相关工作

#### 2.1 基于 LLM 的自主代理

最近的研究尝试正式描述自主代理的结构。尽管在术语上有所不同，基于 LLM 的自主代理基本由一组工具（使用工具的能力可以通过学习获得）、一个记忆（无论是长期记忆如知识库还是短期记忆如上下文）、一个规划算法（指导要做什么）组成。在实践中，已经有许多应用涉及到现实世界的任务。

#### 2.2 将 LLM 代理适应特定领域任务

将基于 LLM 的自主代理适应特定领域任务涉及技术如检索增强生成（RAG）和微调。RAG 通过整合外部知识库，增强了 LLM 生成更准确和上下文相关响应的能力，在需要大量事实信息的特定领域证明特别有益。另一方面，微调在特定领域的数

据集上调整预训练模型，通过使模型更适应领域的独特词汇和细微差别，从而在特定任务中提高性能。这些方法通过显著提高精度和相关性，促进了 LLM 代理在各个领域的应用。

#### 2.3 自我改进的 LLM 代理

在将 LLM 代理适应特定领域任务的基础上，自我改进成为关键的下一步，解决了获取特定领域知识这一昂贵或难以获得的问题。这些自我改进代理通过反馈从环境中迭代学习。最近的研究集中在包括游戏、编程和数学问题解决等环境，这些环境自然提供了持续反馈所需的丰富动态数据。这些环境不仅为代理提供了丰富的动态数据来学习，还使得自我改进技术的实际应用成为可能，减少了对手动策划的特定领域数据集的依赖。这种方法促进了 LLM 代理的发展，使其能够自主增强能力，适应新挑战，并随着时间的推移改进其知识库，使自我改进成为其设计中的一个组成部分。

### 3\. 框架

在这一部分，详细阐述了提出的框架的双层架构。左图描述的外层循环代表与现实世界的交互。在这里，代理生成的输出受到现实世界的评估，得到的反馈被整合到代理的知识库中，进而为后续迭代提供信息。右图描述了内层推理循环，作家和法官组件之间发生迭代对话。这个模拟环境利用内部知识库，是代理的推理和改进过程发生的地方。代理通过这个循环迭代，利用共享上下文缓冲区进行知识检索和推理，直到产生满意的解决方案或达到预设的阈值。

![](assets/002.png)

#### 3.1 内层推理循环

内层循环作为一个模拟推理环境，其中一个 LLM 或基于规则的系统与知识库交互。它使用一个内存缓冲区，最初包含用户的查询，并通过知识库的数据迭代丰富。代理向知识库提出查询，知识库提供相关信息。一个法官（可以是一组规则或一个 LLM）评估这些信息，以确保其满足用户的查询，当形成响应或达到预设条件时结束循环。

![](assets/003.png)

#### 3.1.1 组件

知识库：知识库作为存储代理先前的输出、相关性能得分和反馈的记录库。代理制定查询以提取必要的信息，这些信息随后被处理成嵌入以高效检索相关记录，旨在优化性能准确性和响应多样性之间的权衡。

上下文缓冲区：上下文缓冲区记录了正在进行的交互，保存所有先前的交换和信息。这个累积记录确保了代理推理过程的一致性和连贯性，允许过去的知识为未来的响应提供信息。

作家：作家负责根据从知识库检索到的数据构建响应。它旨在逐步改进其输出，整合法官的反馈以提高后续响应的质量。

法官：法官作为评估者，通过对作家的输出进行评分来提供反馈。其作为评估者的有效性取决于知识库的质量，它在调整代理的输出以提高准确性方面起着关键作用。

#### 3.1.2 程序

单次迭代：在单次迭代中，作家首先从知识库中检索相关知识。利用这些知识，作家制定一个响应。然后，这个响应由法官进行评估，法官提供一个得分和反馈，这些反馈被整合回上下文缓冲区以改进作家下一次响应。

迭代过程：迭代过程基于信息的累积导致逐步改进的响应。循环重复，利用反馈逐步提高响应的质量，直到达到预定的性能阈值或确定最佳响应。

备注：内层循环背后的指导原则是，通过一个强大的响应生成机制，随着迭代次数的增加，作家将从知识库中积累足够的信息，以始终满足法官的标准。这种迭代丰富预计将指导作家产生最佳答案。关于这种收敛过程的正式分析将在第 4.1.2 节中介绍。

![](assets/004.png)

#### 3.2 外层反馈循环

外层循环封装了代理与现实世界环境的迭代交互，其中生成的输出被评估和改进。

环境反馈：环境以性能得分和定性评论的形式提供反馈，这些反馈可能由一个复杂的 LLM 生成。这种反馈旨在将新见解注入代理的决策过程中，有潜力提高未来的性能。

知识更新：在收到反馈后，知识库进行更新过程。这个过程包括健全性检查，以确保新信息的完整性和相关性。更新规则的设计旨在维护一个全面的数据库，包括一系列经验，包括成功和不成功的经验。这种方法确保了代理的多样化学习环境，促进了对现实世界场景的细致理解和适应。

备注：法官在内层循环中的角色与外层循环中的环境反馈之间存在明显对比。前者可以描述为提供快速、成本效益高但精度较低的评估，基于有限的知识集。相比之下，后者类似于真理的标准，通常资源密集，但提供了更高的评估保真度。随着外层循环中迭代次数的增加，内层循环的法官积累了丰富的现实世界经验，逐渐提高了其提供高保真评估和反馈的能力。

#### 3.3 与现有方法的比较

许多现有的方法可以看作是此框架的具体实现。一方面，如果丢弃外层循环，那么自我改进方法家族可以看作是，两个 LLM 分别作为行动者和评论家，无论是否有知识库。另一方面，如果简化内层循环为普通的检索增强生成过程，那么许多自我改进方法，如 Voyager 和 FunSearch 都可以实现。

### 4\. 分析

在这一部分，将分析效率（即代理算法可以渐近地收敛到该问题的最优解）和成本（就代币成本和推理时间成本而言）。分析的动机是 1). 了解系统中每个设计组件的效果 2). 分析将其部署到现实世界中是否可行。

#### 4.1 效率

在两个层面上证明了代理算法的效率：内层循环和外层循环。内层循环的效率表明，代理可以在当前知识库的情况下找到问题的最佳可能答案，外层循环的效率表明，随着外层循环迭代的增加，由知识库模拟的环境中的最优策略与现实世界中的最优策略之间的性能差距可以收敛。这两个效率保证共同构成了策略可以收敛到全局最优的保证，表明了代理算法的效率。为了分析效率，首先介绍问题的公式。

#### 4.1.1 公式

将生成问题答案的过程（即内层循环）公式化为马尔可夫决策过程（MDP）。这个 MDP 由元组 (S, A, T, r, γ) 定义，每个组件的特征如下：

状态空间 S：任何时间 t 的状态，表示为 st，是原始问题 p 和共享上下文缓冲区中所有信息的组合。最初 st 是一个空集，表示推理过程的开始。

动作空间 A：动作是相对于作家的，因为只有作家的动作是有意义的。动作就像是对问题的答案，基于当前手头的信息。动作也可以是知识库查询，因为它也改变了信息状态。

转换函数 T：定义为 T(s'|s, a)，表明基于当前手头的信息，给定一个动作，信息状态将如何改变。这有几个实现：1). KB 对查询动作的响应 2). 法官对答案动作的审查。因此，KB 和法官共同构成了转换函数。

奖励函数 r：此函数，r (st)，为信息状态 st 分配一个值。r 可以是连续值，表示答案的绝对得分，也可以是 0/1 值，表示答案是否足以回答这个问题。

折扣因子 γ：它定义了代理在考虑未来奖励时的权重，通过强调长期结果的重要性来塑造推理过程的战略深度。在实践中，使用 γ ∈ (0, 1) 来确保值函数 Vπ(s) 是有界的，这对分析很重要。

![](assets/005.png)

给定一个策略 π : S → A 和一个由 θ 参数化的环境，定义其值函数和 Q 函数如下：

![](assets/006.png)

其中期望值是对 at ∼ π(St) 和 st+1 ∼ Pθ(.|st, at) 对于所有 t > 0。这里 θ 可以被认为是知识库内容。具体来说，θ 通过确定给定查询动作的查询结果来影响转换函数 Pθ(.|st, at)，奖励函数 rθ(s) 也受到知识库的影响，因为法官依赖于它。因此，内层循环的目标是学习一个策略，该策略对所有 s ∈ S 最大化 Vπθ(s)，以便找到任意用户问题的足够信息。

目标是证明的代理在内层和外层循环中都是可证明有效的。即，代理的贝叶斯遗憾

![](assets/007.png)

在 KT 中是次线性的。

#### 4.1.2 内层循环

根据 (Liu et al., 2023)，对内层循环提出以下假设：

假设 4.1。在上下文中推理步骤中，LLM 作家隐含地执行模拟环境参数的贝叶斯推断。

假设 4.1 本质上指出 LLM 在给定信息状态 s 和其通过预训练获得的先验知识 p(θ) 的情况下，执行隐含的贝叶斯推断 p(θ|s) 环境参数 θ。这种机制也在以前的工作中得到验证 (Xie et al., 2021)。基于估计的环境参数，采用了一种规划机制来确保在 θ 上的最优性：

定义 4.2。（ε-最优性 (Liu et al., 2023)）在一个由 θ 参数化的环境中，如果以下条件以高概率成立，则策略 π 满足 ε-最优性

![](assets/008.png)

这样，内层循环的可证明效率表明，通过在不断增长的信息和法官的反馈下迭代改进其答案，

引理 4.3。内层循环中规划代理的贝叶斯遗憾在内部循环迭代次数 T 中是次线性的

这个证明背后的直觉是，由于 LLM 推理是隐含的贝叶斯推断，其对模拟世界参数的后验估计越来越准确，信息差距最终会收敛。鉴于规划算法的最优性，次优性仅取决于模型估计误差。因此，随着信息收敛，模型估计也收敛，最终导致最优策略。

同时，值得一提的是，一站式方法对应于闭环解决方案，没有理论上的效率保证，这意味着它们在理论上不是收敛的。这是因为在 LLM 推理中的信息不会随着迭代增长而累积。然而，在其他工作中，这种方法也工作得很好，表明实际信息差距在 1 次射击后可能并不那么大。此外，其他工作也没有明确地包含规划机制，但也取得了良好的结果，这可能是因为在现实世界的实践中，次优性可能也不是那么严重。

#### 4.1.3 外层循环

外层循环的效率本质上是悲观的结果。首先假设知识库上的最优策略可以通过悲观主义训练得到。这样，知识库可以被视为一个离线数据集，获得这样的最优策略可以视为在这个数据集上执行离线 RL。（Jin et al., 2021）指出，如果离线策略是通过悲观主义学习的，那么离线学习到的最佳策略与在线学习到的最佳策略之间的性能差距可以由信息差距来界定。分析将假设这一点，并基于这一点来获得我们的效率证明。

假设 4.4。给定一个由离线知识库参数化的模拟环境 θ，最优策略 π 可以通过悲观价值迭代（PEVI）（Jin et al., 2021）获得。

引理 4.5。（悲观主义的效率）根据假设 4.4，在真实环境中的 π 和 π\* 之间的性能差距是由知识库引起的内在不确定性所界定的。

引理 4.5 保证，在悲观主义下，次优性只与模型参数在真实环境和由知识库参数化的模拟环境之间的估计不准确有关。而且，随着知识库积累了越来越多的关于真实环境的信息，使得模拟环境更接近真实环境，使用悲观主义在这个模拟环境上训练的最优策略也应该有一个收敛的性能差距。这个理论结果桥接了真实环境和模拟环境中的最优策略，结合内层循环效率，桥接了代理学习到的策略与真实环境中的最优策略之间的差距。

#### 4.1.4 总体结果

结合内层和外层循环的可证明效率，可以桥接整体性能差距

定理 4.6。LLM 代理在真实环境中的贝叶斯遗憾，公式 3 中的 R(TK)，在 KT 中是次线性的。

证明。在这里给出证明的概要。每个术语的详细证明可以在 (Liu et al., 2023; Jin et al., 2021) 中找到。性能差距可以基本上分解如下：

![](assets/009.png)

当对 T 和 K 取和时，术语 A, B, 在悲观主义假设（假设 4.4）下，可以由离线数据集的内在不确定性（引理 4.5）来界定，在基础 MDP 的适度假设（例如线性 MDP）下是次线性的。同样，对于术语 D，它也由信息差距所界定，在相同情况下是次线性的。对于术语 C，根据引理 4.3，它在 T 中是次线性的。因此，左边的部分，当在公式 3 中取和时，是次线性的。

#### 4.2 成本分析

代币成本：在自我改进阶段，内层循环会产生一个随着规划视野 H 和闭环交互循环 T 的平方增长的代币成本。这样，单个外层循环迭代的计算复杂度为 O(T2 H)。当考虑多轮外层循环迭代时，对于代理的自我改进，K 次这样的迭代的累计代币成本扩展到 O(KT2 H)。在推理阶段，不执行外层循环时，代币成本保持在 O(T2 H)，假设从训练到推理的响应生成复杂度没有显著变化。

时间成本：外层循环中每次迭代的时间成本受规划视野和代表基线计算开销的常数因子的影响。假设关键操作的时间是常数，并且每次值计算产生一个单位时间，单个外层循环迭代需要 T(H + Const) 单位时间。因此，整个训练阶段，包括 K 次外层循环迭代，需要 O(KTH) 时间。在推理阶段，没有外层循环，时间复杂度降低到 O(HT)。

### 5 实验

在这一部分，介绍论文中的实验设置。实验是在一个特定领域的场景中进行的，所以将介绍任务背景，然后是实验中最重要的设置。详细信息见附录。

#### 5.1 背景

任务是金融信号挖掘。金融信号是从金融市场价格数据中计算出来的预测信号，可以用于金融预测。设计金融信号需要良好的市场理解、代码实现技能和如数值分析等数学技能。这项任务的主要目标是获得好的金融信号，具有高预测能力。给定一个交易想法，还希望代理改进其。还希望获得一组多样化的信号，在此基础上可以构建机器学习模型，将它们结合起来以获得更好的预测。

#### 5.2 问题设置

总目标是生成好的金融信号，通过测量来评估。为了实现这一目标，在每次外层循环迭代中，代理被赋予一个交易想法，然后被要求生成既反映这个交易想法又实现良好性能的金融信号（通过考虑其他考虑）。交易想法是从一个分布中采样的，在们的实验中由另一个 LLM 生成。金融信号的实现本质上是一段代码（或等效地是一个函数）具有预定义的模式。类似于 FunSearch，定义了一个模板，如附录所示，让 LLM 代理实现该阿尔法的函数代码。

数据集：选择了中国 A 股市场的 500 只股票。这些数据的时间范围是 2023 年。用于计算金融信号的基本市场数据包含每天收盘时收集的成交量和价格。

基础 LLM：选择了 gpt-4-0125-preview 作为我们基础模型的版本。

#### 5.3 评估协议

预测性能：为了评估金融信号的预测能力，计算信息系数（IC）相对于未来回报。IC 是每个横截面（所有股票在单个时间点）的皮尔逊相关系数，然后对所有时间点进行平均。为了确定知识库（KB）作为信号生成的基础数据集的有效性，检查机器学习模型（即 XGBoost 回归树）使用 KB 作为特征输入的信号的 IC。这评估了 KB 作为创建金融预测模型的可靠来源的潜力。此外，分析信号的夏普比率，以评估其产生满意投资回报的能力。

信号质量：对于数值质量，查看信号所涉及的有效和唯一实体的数量，确保它们能够区分股票。在交易想法相似性方面，衡量信号与其基础交易想法的对应程度。这种相关性对于 LLM 作为投资研究助理的潜在用途至关重要。为了量化这一点，进行成对比较，其中一个 LLM 对不同代理生成的同一交易想法的两个信号进行评估。LLM 选择更准确的信号，从这些成对比较中，构建了一个胜率矩阵。这个矩阵的汇总结果形成了一个排行榜，对代理产生忠于原始交易概念的信号的能力进行排名。这个排名提供了不同代理在捕捉交易想法在其信号实现中的本质方面的能力的见解。

### 6 结果

这一部分展示了实验结果，支持理论发现。重点介绍代理自我改进能力的主要成果，并通过不同的实验分析了内层和外层循环的效果。

#### 6.1 自我改进的证据

图 5 显示了训练在累积信号和训练在单个阿尔法片段上的持续性能改进。不断提高的预测准确性表明，随着代理自我改进，它能够产生更强的信号以获得更好的预测能力。

![](assets/010.png)

![](assets/011.png)

#### 6.2 提高阿尔法相关性

为了衡量信号质量，根据生成的迭代对整个过程中生成的信号进行排序，并将其分割成等数量组，以比较它们在准确传达基础交易想法方面的表现，由 GPT-4 判断。图 4 显示了胜率的分布。累积胜率到右上角表明，随着模型的发展，代理在编写高质量信号方面获得了更好的技能，验证了自我改进的有效性。值得注意的是，最右边的矩阵中的递减模式表明了内层和外层循环的有效性。

#### 6.3 内层和外层循环的效果

图 3 展示了整个过程中单个阿尔法属性的演变。虽然看起来没有显著的绩效差异，但蓝色曲线的趋势表明了自我改进在所有指标上的有效性。

### 7 讨论

研究展示了自主代理的效率，特别是在量化投资领域，展示了它们通过模拟环境进行自我改进和适应的能力。这一进步不仅突出了它们作为金融分析和风险管理工具的潜力，还为它们在包括医疗保健和物流在内的各个复杂领域的应用打开了大门，通过定制知识库和反馈机制。尽管有这些有希望的发展，挑战如对知识库质量的依赖和对计算优化的需求仍然存在。未来的努力将旨在提高代理的学习效率，扩展其应用场景，并探索实时适应动态环境。最终，这些努力强调了基于 LLM 的代理在工业革命决策过程中的巨大潜力，标志着迈向智能自动化时代的重要一步。

  

![](assets/012.jpg)

  

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