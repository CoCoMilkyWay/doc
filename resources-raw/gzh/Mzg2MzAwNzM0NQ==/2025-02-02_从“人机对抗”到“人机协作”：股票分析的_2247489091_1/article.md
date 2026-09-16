# 从“人机对抗”到“人机协作”：股票分析的技艺与人工智能

QuantML QuantML 2025-02-02 22:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489091&idx=1&sn=fc067e31a14595339523c2a8ebddc903&chksm=cf685a601ee78d2c28aca67239113a5ea3087766ad4aa21ed20321430ede3456b2ed04040f23#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489091&idx=1&sn=fc067e31a14595339523c2a8ebddc903&chksm=cf685a601ee78d2c28aca67239113a5ea3087766ad4aa21ed20321430ede3456b2ed04040f23#rd)

### 

![](assets/001.png)

1\. 引言：人工智能对人类角色的重塑

自人工智能（AI）诞生以来，它不断促使人类重新思考自身在社会中的角色。尽管AI旨在增强人类智能，但人们普遍担心它会取代人类在日益复杂任务中的地位，进而取代目前由高薪高学历人群从事的工作。这种担忧引发了学术界对AI对就业和生产力影响的广泛研究。

现有文献主要关注AI技术对不同类型工作的颠覆性影响，以及AI可能创造的新工作机会。换句话说，现有研究大多围绕“人机对抗”的主题展开，探讨人类如何适应AI带来的变革，并预测由此导致的就业重新分配。然而，这些研究往往将人类置于被动或反应的地位，主要关注如何应对AI带来的颠覆并寻找新机遇，而较少研究如何利用AI技术提升熟练工人的潜力，而这本应是人类设计和开发AI的初衷。

本研究旨在将“人机对抗”的主题与“人机协作”的潜在平衡状态联系起来。我们从国际象棋特级大师加里·卡斯帕罗夫的亲身经历中汲取灵感。1997年，IBM的“深蓝”计算机击败了当时的世界冠军，这一事件广为人知。然而，此后多次类似的人机对弈使得“人机对抗”在国际象棋领域的结果悬念尽失。鲜为人知的是，尽管人们对人机对弈的兴趣逐渐消退，但人类对国际象棋和机器的热情并未减退。事实上，与“深蓝”的遭遇促使卡斯帕罗夫等人率先提出了“人机协作”对弈的概念，即配备AI辅助的棋手（“半人马”棋手）与AI进行对弈。时至今日，“半人马”棋手在对抗机器方面仍保持优势。更令人鼓舞的是，随着价格实惠的基于AI的国际象棋程序的出现，涌现出更多更优秀的人类棋手。

如果AI能够帮助更多人成为更优秀的棋手，那么它也有可能帮助我们在许多需要技能的岗位上表现得更加出色，包括飞行员、医生和投资顾问等。在本研究中，我们将重点放在股票分析这一职业上，其数据可用性使我们能够同时对“人机对抗”和“人机协作”进行校准。股票分析师是市场中最重要的信息中介之一（例如，Brav 和 Lehavy，2003 年；Jegadeesh，Kim，Krische 和 Lee，2004 年；Crane 和 Crotty，2020 年）。他们的工作需要机构知识和数据分析，而AI技术以其强大的预测能力和低成本的核心优势，正在对这一领域产生冲击。越来越多的投资者开始关注AI驱动的股票推荐和投资组合建议。

### 2\.  从“人机对抗”到“人机协作”：研究方法与数据构建

#### 2.1  研究目标与动机

本研究旨在构建一个AI分析师模型，用于预测12个月后的股票回报率（根据12个月目标价格推断），并将其与同期对同一股票的分析预测进行比较。这一过程为我们提供了一个一致且随时间调整的AI性能基准，我们能够理解和解释该基准。收益和目标价格（从中可以推断出股票回报）是分析师预测的两个最重要的主题。我们选择后者作为主要目标变量，因为收益更容易受到管理层自由裁量权的影响，往往是为了达到（或略微超过）共识分析师预测而做出的，这使得AI模型在缺乏这种反馈效应的情况下进行不公平的比较。

#### 2.2  数据收集与处理

我们的“AI分析师”基于使用及时、公开可用的数据和信息训练的一组当前机器学习（ML）工具包构建。具体来说，我们收集了公司层面、行业层面和宏观经济变量，以及来自公司披露、新闻和社交媒体的文本信息（在分析师预测之前更新），作为输入或预测因子。我们有意排除了分析师预测（过去和现在）本身的信息，以便AI模型不会从分析师的洞察中获益。在这样的设置中，机器学习模型由于其在处理高维和非结构化数据方面的优势，以及在优化和拟合未指定的函数形式方面的灵活性，已经被证明能够超越传统的经济学模型（如回归）。该领域最近的发展在减轻过拟合并提高样本外性能方面取得了重大进展。

我们选择了一组最先进的机器学习模型，并基于集成模型构建了我们的AI分析师。我们的AI分析师能够击败整体上的人类分析师：在2001年至2018年的样本期间，AI分析师在所有I/B/E/S分析师所做的股票回报预测中，有54.5%的情况下表现更优。机器的优势可能源于其处理信息的卓越能力，或者其对可预测的人类偏见（如激励或心理特征）的免疫（例如，Abarbanell，1991 年；Stickel，1990 年）。为了区分这两者，我们将AI预测与“去偏差”分析师预测进行了比较，其中偏差被预测并使用机器学习去除（此后称为“机器去偏差人类”或“MDM”预测）。这种改进版本的人类分析师仍然落后于机器（MDM仅在46.5%的预测中优于AI），这表明“可纠正”的偏差解释了大约22%的“人机差距”。

### 3\.  AI分析师的构建与性能

#### 3.1  AI分析师的预测模型

对于每只股票 在时间 ，其中 是分析师进行预测的日期， （其中 、 、 分别是股票、分析师和日期的索引，上标 Man 表示人类与 AI 相对），我们将其转换为相应的 12 个月回报率 以实现横截面上的平稳性和可比性。因为分析师对未来的价格做出预测，并且不系统地提供股息预测，因此我们从目标价格推断出的股票回报不包括股息（Brav 和 Lehavy，2003 年）。预测信息集包括截至 的所有公开信息（如第 2 节和附录 A 中所述）。我们总结了预测模型如下：

这里， 是在时间 对所有股票的预测函数。这与具有条件信息的资产定价模型一致；也就是说，我们假设在给定时间点对每只股票都有一个统一的预测模型，同时允许模型随时间变化。

接下来，我们根据事后的实现回报率 来比较 AI 预测 和其人类对应物 的准确性。如果 ，则 AI 击败人类，反之亦然。我们定义 Beat 为一个人类分析师击败 AI 的指标变量。图 1 显示了 AI 与人类分析师预测的相对性能随时间的变化。在 2001 年至 2018 年期间做出的 922,157 个预测中，人类分析师在 45.5% 的情况下击败 AI。百分比来自一个中性概率为一半的分布的 值对于这个样本量来说小于 0.01%。然而，人类分析师的劣势每年都有波动，但随着时间的推移略有改善的趋势。

#### 3.2  变量对 AI 预测的贡献

机器学习的过程通常是模糊不清的。我们通过检查不同组输入变量对 AI 模型预测的贡献来减轻这种模糊性。具体来说，我们将特征分为六组：基于回报的变量、公司特征、收益（公司和行业）、行业信息、宏观经济变量以及从文本信息中提取的变量。我们通过一次取出一组变量的值来计算各组的贡献。具体来说，我们考虑一个“排除一组”的 AI 模型，将给定组变量的值设置为在训练有素的 AI 模型中整个时间内的过去平均值。然后，我们计算预测值的平方误差。接下来，我们计算每年平均平方误差并将其汇总到所有年份。每组变量的贡献由每组平均平方误差相对于所有组增量总和的增加来表示。图 2 显示了构成。

![](assets/002.jpg)

每组特征都对 AI 的优势做出了重大贡献。宏观经济变量和公司回报贡献最大（分别为 27.6% 和 24.4%），其次是公司特征变量（22.0%）。文本信息 9.3% 的贡献凸显了定性信息的重要性。收益信息占据的份额最低（2.0%）或许并不令人惊讶，因为此类信息可能已经包含在过去的回报和其他公司特征变量中。

### 4\.  人机相对优势分析

#### 4.1  相对绩效的决定因素

在本节中，我们努力了解人类分析师何时表现优于 AI，以及何时相反。这种理解将有助于“揭开”AI 或机器学习相关的黑匣子，并为研究人员和投资者提供关于 AI 适用性的直觉和指导。

我们考虑了分析师、公司和行业层面的许多变量，这些变量可能与人类分析师和 AI 的绩效相关。这些变量在第 2.5 节中定义。我们将这些变量分为几类。首先，我们考虑了一些信息不对称或模糊性的代理变量，包括 Amihud 非流动性、Log 市值和机构持股百分比。其次，我们包括了代表信息量（信息事件数量）、公司文件的可读性（文本复杂性）和信息的实质性（无形资产和流动性）的变量。第三，我们检查了几个影响分析师可获得的信息和资源的变量，例如经纪公司中的分析师数量和明星分析师。最后，我们考虑了违约距离和行业衰退，突出公司对冲击的财务敞口，以及时间趋势，它可以捕捉时间模式。

对于每个目标价格预测，我们定义了两个人类与 AI 相对绩效结果的衡量指标。首先，分析师击败 AI 指标变量等于 1，如果分析师的预测误差绝对值小于 AI 的预测误差绝对值，则为 0。其次，连续指标预测误差差异是 AI 的绝对预测误差（回报率定义如公式 (1)）与分析师的绝对预测误差之间的差异，除以这两个预测误差的最大值。预测误差差异为正且数值较大有利于分析师准确性。

我们估计以下关于公司 、分析师 和日期 的面板数据的回归，以了解人类和 AI 相对优势的驱动因素，

其中，因变量相对绩效是分析师击败 AI 或预测误差差异：分析师与 AI。独立变量向量 包括第 2.5 节中讨论的那些， 和 分别代表公司和分析师以及年份固定效应。结果在表 4 中报告。

![](assets/003.png)

表 4 显示，在控制年份和公司固定效应的情况下，当覆盖流动性差的小型公司以及拥有更高无形资产的公司时，人类更有可能表现更优，这与此类公司受信息不对称程度更高，需要更深入的机构知识才能理解的概念一致。无形资产的一个标准差增加与击败比率增加 3.0% 相关。另一方面，配备了强大处理能力的 AI 在拥有更多披露信息的公司中表现更好，由每年信息事件数量作为代理。一个标准差的信息事件数量增加与击败比率减少 1.8% 相关。在大型经纪公司工作的分析师表现更好，可能是由于这些地方的资源更丰富、研究能力更强，以及分析师技能与经纪公司声望之间的积极匹配。

当目标公司面临更高的财务困境风险时，人类表现更好，由违约距离和行业衰退来衡量，这表明 AI 在处理更不确定的情况时更加困难。当公司拥有更高的机构持股比例时，分析师也表现更好，可能是因为分析师沉浸在由机构投资者（包括经纪公司）产生和处理的信息中。最后，当不包括年份固定效应时，我们能够发现比较绩效的时间趋势，表明人类优势随着时间的推移而增加。这可能是因为人类分析师越来越多地得到 AI 和大数据技术的帮助。或许令人惊讶的是，明星分析师并没有表现出明显优于 AI 的表现，这表明明星分析师相对于同行的卓越能力可以被机器复制。

### 5\.  人机协作：增量贡献与协同效应

#### 5.1  分析师对“人机协作”的增量价值与人机协同效应

承认“人机协作”优于单独的人类或机器，但了解组合中人类和机器各自的增量价值仍然具有指导意义。与前一节类似，我们定义了混合分析师与 AI 的相对绩效指标，以捕捉人类的增量价值。然后我们用这些相对绩效指标作为因变量重新估计方程 (3)。表 6 呈现了结果。

![](assets/004.png)

与之前的发现类似，我们发现当覆盖流动性较差的公司以及拥有更多无形资产和收益波动性的公司时，分析师的输入更有价值。此外，当公司面临更高的困境风险时，分析师输入的增量价值更大。机构持股比例也有助于混合模型击败 AI 分析师。最后，人类的增量价值并没有随着信息量的增加而显著下降，而单独工作的人类是受容量限制的，如表 4 所示。这一发现支持 AI 对熟练专业人员的增强，并凸显了两者之间的协同效应。

人机协同效应与分析师预测对 AI 预测的增量信息价值相关，但超越了这种价值。可以通过将“人机协作”模型的平方（或绝对）预测误差回归到单独的人类和机器误差上来揭示协同效应的另一种衡量指标。然后将残差项作为“人机协作”超出单独人类和机器的增量价值。我们然后取残差并将其回归到各种公司和分析师特征上，以了解是什么推动了这种协同效应。在这次回归中，我们否定了残差的符号，以便正系数传达积极的结果，即与更高的人机协同效应相关。

### 5.2  “人机协作”能否避免极端错误？

正如许多其他熟练职业一样，极端预测错误可能对预测者的声誉和投资建议接受者的福利造成灾难性的后果。然而，正如俗话所说，“犯错是人之常情，宽恕是神圣的”，机器错误远不如人类错误容易被容忍（Prahl 和 Swol，2017）。因此，我们对“人机协作”抵抗极端错误的韧性感兴趣，除了平均预测准确性之外，这种质量对于组合的未来至关重要。

为了奠定基础，我们将每个预测的预测误差与同年同一公司所有分析师的平方预测误差的第 90 个（或第 75 个，作为敏感性检查）百分位数进行基准比较。这样的设置导致四种结果，关于谁犯了极端错误：(1) 分析师和 AI 模型（“两者”）；(2) 分析师；(3) AI；(4) 两者都没有犯极端错误（“都没有”）。我们检查这四种情况并计算它们的经验频率。我们然后计算无条件概率和条件概率，即“人机协作”模型可以避免在前三种情况下犯下的极端错误，同样重要的是，“人机协作”在第四种情况下创造极端错误的可能性。所有概率在表 8 中报告。

![](assets/005.png)

我们发现分析师和 AI 犯极端错误的可能性大致相同（使用第 90 个百分位数阈值，分别为 9.3% 和 7.8%）。还有 3.5% 的可能性两者都做出糟糕的预测。事实证明，“人机协作”模型可以帮助避免 90.7% 的人类极端错误和 43.6% 的 AI 极端错误。即使分析师和 AI 似乎都偏离了轨道，他们的组合仍然设法将 4.6% 的此类案例带回合理的范围。此外，“人机协作”仅在“都没有”情景的 0.1% 中创造自己的极端错误。总体结果呈现了结合人类和 AI 能力的显著互补优势。

这种协作模式强调人机协同的一个重要方面，特别是在高风险场景中，包括金融市场以及医疗诊断、气候建模和紧急响应系统的潜在应用。鉴于人类和机器错误通常源于不同的因素，他们的共同努力有可能减少严重失误的可能性。据我们所知，这种人机协同效应在现有文献中尚未得到实证记录。

### 6\.  结论

在这篇论文中，我们构建了一个 AI 分析师来消化公司披露和其他信息（定性和定量）并执行与股票分析师类似的预测任务。我们的 AI 分析师能够击败大多数人类分析师在股票回报预测中。在“人机对抗”的竞赛中，我们发现这种 AI 分析师的相对优势在信息更透明和丰富时更为强大。当关键信息需要机构知识（例如，无形资产的性质和与财务困境相关的条件）时，人类分析师仍然具有竞争力。结合 AI 和人类专家的技艺在两种技能互补的环境中产生了最高的潜力生成准确预测，其好处在明确避免单独人类或机器可能犯下的极端错误方面特别吸引人。本研究中记录的人机协同效应为人类如何利用自身优势更好地适应 AI 实力日益增长的时代提供了指导。

尽管我们构建 AI 分析师时使用了相当全面的数据输入集，并采用了最先进的机器学习技术，但一个模型本质上不可能包含所有公开可用的数据和所有先进的算法。我们认为未来研究在机器能力以及更重要的方面有充分的改进空间，人机智能的整合。以下方向可能特别有前途。首先，进一步研究如何最好地利用“人机协作”的潜力来减少负面尾部对于 AI 采用中的风险管理至关重要。其次，对机器学习模型进行更好的训练以了解商业周期和处理不断变化的环境将至关重要地扩大模型能力和适用性。最后，随着 AI 模型变得越来越复杂，模型的解释性对于模型稳健性和人机协作都至关重要。

#   

加入QuantML星球，与700+专业人士一起交流学习：

![](assets/006.png)

  

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