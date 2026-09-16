# 视觉胜于文本：LLM在交易中更好的应用方式？

QuantML QuantML 2025-03-18 18:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489712&idx=1&sn=2c37c80069f65fae35fd198105c8b7f8&chksm=cf17b1715d7b9b3bfae237636ef4454b3567e1276d9b89ec38edc31dd5a2e1880981106e137f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489712&idx=1&sn=2c37c80069f65fae35fd198105c8b7f8&chksm=cf17b1715d7b9b3bfae237636ef4454b3567e1276d9b89ec38edc31dd5a2e1880981106e137f#rd)

### 

![](assets/001.png)

#### 1\. 引言

近年来，大型语言模型（LLMs）在自然语言处理（NLP）任务中取得了显著进展，涵盖了翻译、摘要生成和推理等多个领域。然而，LLMs在处理动态的、未见过的任务，特别是在数值推理方面的能力仍然面临挑战。现有的基准测试主要评估LLMs在具有预定义最优解的问题上的表现，这些问题往往与现实世界中缺乏明确答案的情境不符。为了弥合这一差距，我们设计了“代理交易竞技场”（Agent Trading Arena），这是一个模拟复杂经济系统的虚拟数值游戏，通过零和博弈，代理人在其中进行股票投资决策。

我们的实验揭示，LLMs（包括GPT-4o）在处理纯文本股票数据时，往往难以进行代数推理，通常会关注局部细节而非全局趋势。相比之下，当LLMs面对视觉数据（如散点图或K线图）时，几何推理能力显著提升，表明视觉表示增强了数值推理能力。通过引入反思模块（reflection module），进一步提升了模型对复杂数据的分析和解释能力。我们在NASDAQ股票数据集上的验证结果表明，LLMs在处理视觉数据时的推理能力明显强于处理文本数据。

![](assets/002.png)

#### 2\. 相关工作

##### 2.1 数学基准测试

数学文字问题（MWPs）已被广泛研究，并推动了各种基准测试的发展，以评估模型的数学推理和问题解决能力。早期数据集如MAWPS标准化了现有问题以便于一致性评估。Math23K引入了大规模的中文算术问题集，要求结构化方程求解。为了增加多样性，ASDIV和SVAMP等基准测试提供了更丰富的注释和更广泛的问题类型。较新的基准测试如GSM8K和MATH专注于多步骤推理和高级数学概念，拓宽了评估范围。此外，MathQA-Python强调程序化推理，而MGSM将这些基准测试扩展到多语言环境。尽管取得了这些进展，现有模型主要依赖于通过广泛训练获得的基于记忆的回答策略，而不是展示真正的数学推理能力。

##### 2.2 增强数学推理的LLMs

基于这些基准测试，LLMs通过将专门的数据集纳入训练来提升数学问题解决能力。Galactica、PaLM-2、Minerva和LLaMA-2等模型在预训练期间利用了广泛的数据集，提升了它们的数学推理能力和对复杂概念的理解。微调模型如MetaMath、MAmmoTH和WizardMath专门针对数学任务进行了调整。这些模型通过精心策划的数据集进行领域特定的微调，使它们能够应对高级推理挑战，并在专业基准测试上显著提升性能。

然而，现有方法通常依赖于大量训练数据集，引发了对LLMs真正推理能力的担忧。尽管这些方法主要评估模型在已建立问题类型上的表现，但对大量训练数据的严重依赖表明，模型可能通过记忆和模式识别来实现高性能，而不是真正的推理。因此，需要替代的评估范式，以更准确地评估LLMs将数学原理推广到新情境的能力。

#### 3\. 方法

为了减少人类先验知识和记忆的影响，我们设计了一个名为“代理交易竞技场”的闭环经济系统，这是一个模拟复杂定量现实情境的零和博弈。模拟工作流程如图2所示。在代理交易竞技场中，代理可以投资资产，通过持有资产赚取股息，并使用虚拟货币支付日常开支。总回报最高的代理赢得比赛。

##### 3.1 代理交易竞技场

代理交易竞技场的结构。为了消除外部知识偏差，资产价格由买卖系统决定，反映了买卖双方愿意交易的价格。系统仅根据代理的行为和互动演变，没有外部影响。这种设计确保了代理行为的结果不是立即显现的，而是逐渐展开的，受其他代理决策的影响。

![](assets/003.png)

为了鼓励积极参与，引入了一种股息机制。该系统中有两个主要收入来源：资本收益和股息收入。每种资产的股息根据预定的比例分配，作为资产价格的隐性锚点。持有更多低成本资产的代理获得更高的股息。为了防止代理被动持有资产直到游戏结束，代理必须支付与其总财富成比例的日常资本成本。这些费用由资产股息抵消，只有持有足够低成本资产的代理才能覆盖成本。在巨大的日常开支压力下，代理必须迅速而策略性地行动，频繁交易和价格波动以刺激市场活动。这种动态机制确保了零和博弈的公平性，同时防止代理依赖固定策略找到最优解。

代理在竞技场中学习和竞争。零和博弈结构对于消除普遍最优策略的可能性至关重要。在具有静态最优解的固定情境中，代理可以依赖预定义的规则或基于记忆的方法，绕过适应性决策。零和博弈确保没有普遍正确的解决方案，结果根据代理互动和竞争动态演变。这种设计迫使代理不断适应，从反馈中学习，并制定情境依赖的策略，促进更深入的环境探索，防止依赖静态或记忆驱动的解决方案。

在代理交易竞技场中，代理不知道隐含的规则，除了在整个模拟过程中最大化其虚拟财富的目标。为了赢得这场零和博弈，代理必须有效地从经验中学习，破译隐藏的游戏规则，并制定策略来对抗竞争对手。这需要理解数值反馈，制定持久的策略，并做出明智的决策。与其他数学推理问题不同，他们的行为结果逐渐而动态地展开。此外，代理很容易被竞争对手的错误信息误导，阻碍了他们从竞争对手的文本数据中辨别战略线索。重要的是，代理不知道这些隐含的规则，因此应用现实世界的知识不会提高他们的表现。因此，代理必须依靠经验学习来破译隐藏的游戏规则，并最终取得胜利。

##### 3.2 数值数据输入类型

文本数值数据的局限性。在代理交易竞技场中，生成的股票数据以数值格式存储。当直接用作LLM的输入时，模型通常难以准确解释数值数据或做出合理的决策。为了缓解这一问题，我们将数据转换为文本格式，增强语义特征并明确输出要求，以提高模型的理解。在互动过程中，LLMs处理以文本数值数据形式呈现的股票价格、交易量和市场指数。

![](assets/004.png)

然而，这种文本方法揭示了显著的局限性。虽然数据呈现得很清楚，但LLMs往往过于关注特定的值，而不是识别长期趋势或全局模式。它们还难以理解相关关系和百分比变化，限制了其评估差异和识别数据点之间联系的能力。在分析具有复杂模式的时序数据时，LLMs通常会固定在单个数据点上，忽略整体关系。这一问题在图3右上角的分析输出中很明显，LLMs对个别值的关注阻碍了它们进行概括，减少了提取有意义全局见解的能力。

此外，LLMs往往过分强调最近的数据，同时低估历史信息，即使在提示中明确强调其重要性。这阻碍了它们有效地整合过去的数据并识别长期模式，使它们理解数值关系和趋势变得复杂。这些挑战凸显了需要改进的机制来处理数值关系，识别全局趋势，并从文本数值数据中得出更深入的见解。

视觉数值数据的潜力。由于文本数值数据通常导致LLMs关注局部细节而忽略更广泛的关系，我们研究了视觉表示（如散点图、折线图和条形图）是否可以帮助LLMs更好地理解整体趋势，类似于人类推理。因此，我们将文本数值数据输入过渡到可视化格式。如图3右下角所示，视觉表示使LLMs能够更有效地把握整体趋势、模式和关系，这些通常很难仅从文本数值数据中辨别出来。

这些发现凸显了结构化视觉数值数据的优势，表明这种格式使LLMs能够更直观和全面地理解复杂数据，更好地捕捉整体波动，而文本则倾向于关注局部细节。通过结合视觉和文本表示，LLMs不仅克服了时序数据中关系的挑战，而且在识别长期趋势和全局模式方面表现出更好的性能，同时仍然关注局部细节。

##### 3.3 反思模块

我们提出了一种策略提炼方法，如图4所示，通过分析描述性文本和视觉数值数据，向LLMs提供实时反馈。这使得新策略的生成和行动计划的优化成为可能。这种方法允许代理评估其结果，完善策略，并根据反馈不断适应。过程从评估当天的轨迹记忆和相关策略开始，使用评估函数。战略生成过程利用评估阶段峰值和最低表现者的对比分析，创建双向学习信号，为后续迭代提供信息。这个迭代循环确保了策略的持续演变，促进了决策的持续改进。

![](assets/005.png)

反思模块在完善策略中起着至关重要的作用，通过提供实时反馈。它分析描述性文本和视觉数值数据以生成新策略并优化行动计划。在代理交易竞技场中，反思模块定期触发，以整合日常交易记录并评估策略的有效性，完善成功和不成功的经验，以指导未来的决策。无效策略被存储在策略库中，供将来参考，允许代理回顾和学习过去的经验。更多细节可以在附录A中找到。

![](assets/006.png)

#### 4\. 实验结果

##### 4.1 实验设置

数据集。为了评估LLMs分析和处理数据的能力，我们开发了代理交易竞技场，这是一个隔离外部因素的受控环境。系统的流程如图2所示。在这个环境中，代理讨论股市趋势，分析股票数据，并进行交易活动。每个代理每天可以执行多笔交易，并在每个交易时段结束时反思所有交易。代理交易竞技场允许调整代理和股票的数量；在我们的实验中，我们部署了至少九个代理和三只股票。所有代理都提供了相同的初始资本，以确保相同的起始条件。每个代理的详细信息见表1，股票特定数据可在表2中找到。为了进一步验证我们的发现，我们选择了NASDAQ股票数据集的一个子集进行投资组合投资。

![](assets/007.png)

评估指标。每个代理根据其角色分配了不同的资本，并使用以下指标评估性能：

1.  总回报（TR）：衡量策略的整体表现，计算为：   ，其中  是初始资产价值，  是最终资产价值。
    
2.  胜率（WR）：代表获胜交易的比例，计算为：  ，其中  是获胜交易的数量，  是交易总数。
    
3.  夏普比率（SR）：评估投资回报相对于风险，计算为：   ，其中  是平均每日回报，  是每日回报的标准差，  是无风险回报，设置为0，如SocioDojo（Cheng and Chin, 2024）中所定义。
    
4.  平均每日回报（Mean）：表示交易期间每日的平均回报。
    
5.  每日回报的标准差（Std）：反映了每日回报的波动性，表明与策略相关的风险。
    

##### 4.2 对比实验

我们进行了实验，以评估基于LLM的代理的实时数据分析与推理能力，重点关注文本和视觉表示如何影响决策。首先，我们探讨了文本和视觉表示在动态环境中的影响。接下来，我们引入了反思模块来增强代理的推理和数据解释能力，考察反思性推理如何影响决策。最后，我们通过在NASDAQ股票数据集上的股票投资模拟来验证模型的有效性，评估代理在现实情境中的适应性和决策能力。

使用文本或视觉输入的试验。为了增强LLMs在代理交易竞技场中对复杂数据的理解，我们从文本数值输入过渡到可视化格式，包括散点图、折线图和条形图。使用三种类型的可视化：每日K线图、交易历史和每个代理的交易量。视觉组的实验设置如图3所示，并在附录C中有详细说明。在竞技场中，没有图像输入能力的LLMs只接收文本输入，不进行反思。对于启用图像功能的LLMs，第一个代理只接收视觉输入，第二个接收文本和视觉输入，其余的只接收文本输入。没有一个代理具有反思能力。有关所选LLMs的详细信息，请参见附录E。

我们进行了不同LLMs的实验，结果见表3，结果显示，具有视觉数值输入的代理优于仅使用文本输入的代理。接收文本和视觉输入的代理取得了最佳性能。这种组合使代理能够关注局部细节，同时也能理解整体趋势，从而实现最佳性能。这表明LLMs在几何数据方面的推理能力优于文本数值数据，突出了它们在几何和代数方面的明显优势。

![](assets/008.png)

##### 4.3 消融实验

模态对LLM竞争力的影响。我们在此实验中采用了相对评估方法。第一和第二代理在文本和视觉设置中使用了各种LLMs，而其余代理则基于LLaMa-3（Dubey et al., 2024）作为基线。这种设置旨在探索不同代理和模态对LLM性能的影响。结果见表5。发现表明，DeepSeek（Liu et al., 2024）在不同的LLM环境中表现出更强的竞争性能，表明其独特的优势或优化，使其能够更有效地适应任务的复杂性。

不同LLMs在使用反思的情况下竞争。为了调查反思在LLMs之间使用文本数值数据的竞争动态中的作用，我们在代理交易竞技场中进行了消融研究。使用相对评估方法，第一个代理采用了各种LLMs，而八个基于LLaMa-3的代理作为基线进行比较。这种设置有效地隔离了每种LLM对性能的影响。如表6所示，在使用反思的竞争中，GPT-4o（Hurst et al., 2024）和Qwen-2.5（Yang et al., 2024b）优于其他模型，与表3中的发现一致。

#### 5\. 结论

在这篇论文中，我们介绍了代理交易竞技场，这是一个零和博弈，旨在模拟复杂的经济系统，并评估LLMs在数值推理任务中的表现。我们的结果表明，尽管LLMs在处理纯文本数值数据（代数推理）方面存在困难，但当面对视觉数据（几何推理）时，其表现显著提升。这突出了视觉表示在支持数值推理方面的优势，特别是在复杂情境中。反思模块的引入进一步增强了模型性能，使LLMs能够更好地分析和解释数据。我们在NASDAQ股票数据集上验证了这些发现，表明LLMs在视觉几何推理任务中表现出色，表明LLMs可能在处理视觉数值数据时比处理文本数值数据表现得更好。总体而言，我们的工作提供了关于LLMs在动态数值推理任务中的优势和局限性的见解，特别是在几何与代数的背景下，并为未来研究改进其在现实世界跨学科挑战中的表现奠定了基础。

  

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/009.png)

  

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