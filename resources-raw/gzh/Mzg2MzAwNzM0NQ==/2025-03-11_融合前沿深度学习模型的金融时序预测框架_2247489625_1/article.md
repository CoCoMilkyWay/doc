# 融合前沿深度学习模型的金融时序预测框架

QuantML QuantML 2025-03-11 22:29 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489625&idx=1&sn=571070b27861b9058ffc9ee96a6ea4c6&chksm=cf4744ca13e172044d4fdcefdd3b39bc9b78e9cff94ad0badf0ccb51ccc116490013912ba43f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489625&idx=1&sn=571070b27861b9058ffc9ee96a6ea4c6&chksm=cf4744ca13e172044d4fdcefdd3b39bc9b78e9cff94ad0badf0ccb51ccc116490013912ba43f#rd)

### 

###   

![](assets/001.png)

### 1\. 引言

时间序列预测在资产定价、风险管理和算法交易等关键决策过程中发挥着至关重要的作用。然而，金融市场的非平稳性以及现有研究在数据集和评估指标方面的局限性，阻碍了先进时间序列模型在金融领域的有效应用。具体来说，现有研究多使用具有简化统计特性的数据集，且传统评估指标如MSE和MAE侧重于点对点准确性，忽略了时间相关性，难以全面评估模型在金融场景下的实际表现。为此，本文提出了**FinTSBridge**框架，通过构建新的金融数据集、设计多视角预测任务、开发**新型评估指标（如msIC和msIR）**以及进行策略模拟与评估，旨在弥合先进时间序列模型与现实世界金融应用之间的差距，为金融时间序列预测提供更全面、更可靠的评估体系。

![](assets/002.png)

通过引入新的数据集、评估指标和预测任务，FinTSBridge旨在弥合先进时间序列模型与金融市场遇到的复杂挑战之间的差距。我们的工作强调了金融时间序列预测中相关性感知方法的重要性，最终推进了AI驱动的金融领域的发展。我们的主要贡献可以概括如下：

• 构建了三个经过策划的金融数据集，以反映多样化的现实市场动态：

-   全球股票市场指数（GSMI）：20个指数（2005-2024），捕捉跨市场依赖性和波动性制度。
    
-   高频期权指标（OPTION）：CSI 300 ETF期权的分钟级隐含波动率和希腊字母（2024），模拟日内市场微观结构。
    
-   比特币期货-现货动态（BTCF）：小时级价格-成交量序列（2020-2024），捕捉加密货币市场的领先-滞后效应。
    
-   对来自近期研究工作的十多个领先时间序列预测模型在金融时间序列上的性能进行了验证，以展示它们在该领域的实际可行性。
    
-   开发了两个新的评估指标，msIC（平均序列相关性）和msIR（相关性稳定性比率），作为对传统指标如MSE和MAE的补充，以更好地捕捉时间相关性和非平稳性下的稳健性。
    
-   针对这些数据集设计了特定的金融任务，例如指数投资组合优化、择时交易和BTC期货多空策略，以评估预测模型的实用性能和潜在应用。
    

#### 2\. 相关工作

##### 2.1 时间序列预测模型

最近的时间序列预测进展集中在通过多尺度分解、注意机制优化、轻量级架构和表示学习创新来增强模型能力。基于分解的方法仍然是处理非平稳信号的基础。例如，Autoformer（Wu等人，2021a）开创了自相关驱动的周期性检测，用自适应分解取代了传统的移动平均，而FEDformer（Zhou等人，2022）利用傅里叶-小波混合频谱分析实现了多分辨率频率分解。在此基础上，非平稳Transformer（Liu等人，2022）引入了动态平稳化模块，在应用注意机制之前学习对非平稳输入进行归一化，显著提高了对分布变化的稳健性。这些方法突出了频域分析和时间建模之间的协同作用。

为了解决Transformer的计算瓶颈，研究人员开发了稀疏注意变体：Informer（Zhou等人，2021）通过基于KL散度的概率稀疏注意和token选择将二次复杂度降低，而Crossformer（Zhang & Yan，2023）设计了分层跨分辨率注意，以捕捉跨时间尺度的依赖性。Koopa（Liu等人，2023a）完全避开了注意，提出了时变Koopman动态系统，通过线性算子对潜在状态演化进行建模。同时，轻量级架构挑战了传统智慧-DLinear（Zeng等人，2023）证明，对于趋势和残差分量的解耦线性投影可以胜过复杂模型，而TSMixer（Chen等人，2023）和TimeMixer（Wang等人，2024a）分别采用纯MLP架构和混合频率-时间算子，以在准确性和计算成本之间取得平衡。

表示学习突破进一步扩展了建模能力。TimesNet（Wu等人，2023）通过周期-相位折叠将1D序列转换为2D时间矩阵，使得2D卷积能够同时捕捉周期内和周期间模式。PatchTST（Nie等人，2023）引入了受视觉Transformer启发的通道独立补丁，通过重叠段学习局部时间嵌入。iTransformer（Liu等人，2024）通过将变量视为token，时间点视为特征，颠覆了传统架构，增强了多变量依赖建模。MICN（Wang等人，2023）采用多尺度扩张卷积金字塔来分层提取局部周期性特征。互补技术如RevIN（Kim等人，2021）通过双向实例归一化解决分布变化，而TiDE（Das等人，2023）将时间编码与密集残差连接集成起来，以实现高效的长程预测。这些创新共同推进了三个核心原则：1）频率-时间分析的混合，2）信号处理理论指导下的战略简化，3）通过归一化和分布对齐的系统稳健性增强。

##### 2.2 与金融任务相关的研究

最近在金融时间序列预测方面的进展越来越多地采用多视野预测框架，以捕捉不断变化的市场动态。与传统方法不同，后者侧重于单步预测（例如，预测下一步价格或涨跌趋势，如（Ding等人，2015；Abe & Nakayama，2018；Kraus & Feuerriegel，2017；Sun等人，2023；Li等人，2024）），最近的时间序列方法如（Liu等人，2024；Wu等人，2023；Liu等人，2023a）采用序列到序列架构来预测汇率时间序列的多步轨迹，这有助于理解未来的时间动态，但也给预测带来了挑战。尽管大型模型和强化学习方法在金融时间序列预测中越来越受欢迎（Nie等人，2024；Li等人，2024；Zong等人，2024），但小型模型和有监督学习方法在金融时间序列预测中的潜力尚未得到充分探索。在尖端模型和金融时间序列任务之间建立桥梁非常重要。

尽管端到端预测方法在时间序列领域越来越受欢迎，但在金融数据集中引入协变量作为预测的一部分是必要的。这些协变量提供了时间序列本身所不具备的时间变化信息，这给模型带来了捕捉变量间信息的挑战。此外，不同的时间序列尺度可能导致不同的预测性能和协变量的依赖性。在金融时间序列中，难以预测的现象或不在低频时间序列中出现的现象可能在高频时间序列中表现出可预测性。因此，构建一个涵盖不同频率、金融工具和变量类型的时间序列数据集具有重要价值，因为它有助于全面评估金融时间序列预测能力。

##### 2.3 资产价格的可预测性

股票价格预测确实具有挑战性，但并非完全不可能。这一点从量化对冲基金机构的长期工作中得到了证实，这些机构不断从历史数据集中挖掘预测指标和模式，以应对不断变化的市场环境，实现超额回报。此外，一些基于有效市场假说（EMH）的研究表明，股票市场并不一定是之前认为的半强形式或强形式效率，这将阻止基于可用历史信息预测未来价格变动（Miller等人，1970；Malkiel，2003）。相反，许多市场通常介于半强和弱形式效率之间（Lo & MacKinlay，1988），而（Efficiency，1993）验证了股票市场中的动量效应，即过去表现良好的股票可能在未来继续表现良好，从而挑战了弱形式有效市场假说。（Fama & French，1996）讨论了多因子模型对资产定价异常的解释力，间接表明了市场效率水平。此外，技术的进步显著提高了数据处理能力，从而提高了预测模型的性能。这种发展带来了以前仅基于历史数据的模型所无法获得的数据处理能力和预测性能（Brogaard & Zareei，2023；Leippold等人，2022；Gu等人，2020；Feng等人，2020；Barberis等人，2005）。

#### 3\. 数据集策划

目前关于长期时间序列预测的研究主要集中在八个主流数据集上（Wu等人，2023；Chen等人，2023；Liu等人，2024；2023a；Zeng等人，2023；Nie等人，2023）。其中，有五个与电力相关，其余三个与天气、交通和汇率相关。尽管汇率数据属于金融领域，但由于汇率数据的非平稳和非周期性特征（Liu等人，2023b），它通常被忽视或被疾病领域的ILI数据集所取代，这使得它比其他表现出显著周期性和平稳性的时间序列数据更难预测。

虽然一些最先进的时间序列模型在主流数据集上展示了强大的长期预测能力，但它们缺乏解决现实世界时间序列问题复杂性的稳健性（Tan等人，2024；Bergmeir，2024a；b；c）。为了更好地研究这些现实世界的挑战，我们提出了三个金融时间序列数据集。

##### 3.1 数据来源

我们构建了三个金融时间序列数据集：GSMI、OPTION和BTCF，每个数据集代表金融学的不同子领域。GSMI数据集包括全球股票市场的20个主要指数，记录了这些指数近20年（2005年至2024年）的每日价格和交易量数据。OPTION数据集包括中国金融市场的CSI 300ETF期权，包含了与看涨和看跌期权的风险相关的变量。BTCF数据集包含比特币现货和永久合约的小时频率数据，有助于了解现货-合约滞后关系，并促进多空交易策略（Bulun，2020；Narayanasamy等人，2023）。在表1中，我们介绍了这三个金融时间序列数据集的统计属性，更多细节见下文。

##### 3.2 数据预处理方法

由于原始数据中许多变量的价值变化幅度存在显著差异，因此需要适当的数据预处理。然而，目前尚无统一且一致的处理资产价格序列的解决方案，预处理方法需要根据特定任务和要求构建。对于GSMI和BTCF数据集，由于它们的频率分别为每日和每小时，我们使用高-开-低-收价格来帮助捕捉数据的信息。为此，我们考虑应用对数变换，同时保留这些变量之间的相对变化模式。

![](assets/003.png)

假设资产收盘价格系列由以下公式给出：

其中  表示第  个时间步的收盘价格，且  。让第  个时间步的收盘价格变化为：

然后 ，这导致：

因此，经过对数变换后，我们构建：

然后，减去初始  导致：

此时，构建的对数价格系列可以被视为价格变化的累积和，转换后的序列仅依赖于前一个状态的价格变化，表现出加法属性。

同样，对于给定的资产最高价格系列：

其中  表示第  个时间步的最高价格。让第  个时间步的最高价格相对于上一个收盘价格的变化为：

![](assets/004.png)

然后 。因此，最终的对数变换对于最高价格系列为：

这不仅使得最高价格系列表现出加法属性，而且还保留了最高价格和收盘价格之间的相对关系，因为它们的差异可以表示为：

其中我们有：

这完全由第  个时间步的价格决定。此外，我们在转换后的序列中添加了一个常数项100，以锚定累积变化的基线，并防止对数价格系列中出现负值。最终的预处理价格变为：

其中  表示转换后的价格系列，而  可以是开、高、低或收盘价格系列中的任何一个。

对于交易量系列：

对数变换方法是：

这有助于避免交易量为零时对数计算中的错误。

##### 3.3 预处理的可视化

在图2中，我们提供了GSMI数据集中20个指数收盘价格和交易量序列在预处理前后的比较。在预处理之前，这些指数价格序列表现出较大的波动和不同的幅度，使得横截面比较具有挑战性。交易量序列的时间变化更加不稳定，跨指数比较交易量尤其困难。预处理后，价格和交易量序列都保持在相同的量级范围内，价格系列锚定到一个统一的初始基线，增强了累积变化的可比性和一致性。

我们还提供了预处理前后GSMI数据集中Volume-Price系列变化的全面分析，以显示其在数据规模对齐和跨变量保留关键模式方面的有效性。

![](assets/005.png)

  

#### 4\. 新的评估指标

尽管主流时间序列预测工作在顶级会议上通常采用基于误差的方法，例如MSE和MAE作为模型预测的评估指标，但当应用于金融时间序列时，这些指标面临重大挑战。一个简单的例子是表2中的Naive模型，它直接将输入序列的最后一个观察值作为预测值，在Exchange数据集上实现了非常低的预测误差（我们在附录B.5中提供了详细分析）。这引发了对金融时间序列预测评估的关键问题，表明应引入基于相关性的指标以及预测误差，因为它们对于现实世界的金融应用至关重要。尽管传统的资讯系数和资讯比率指标（Treynor & Black，1973；Grinold & Kahn，2000）可以衡量单步单变量预测中的时间相关性，但它们无法评估多变量多步预测。为了解决这一局限性，我们提出了多步IC和多步IR，分别缩写为msIC和msIR。

msIC衡量的是预测时间序列的真值和预测值之间的相关系数。具体来说，对于由B个样本组成的输入数据，表示为 ，其中  是样本数量， 是序列长度， 是变量数量，通过神经网络  映射后，我们得到 ，其中 ， 是预测范围。msIC用于衡量预测时间序列  和真实时间序列  之间的时间相关性。具体来说，我们计算每个样本和每个变量沿时间维度的排名相关系数，然后对B和C维度进行平均，得到最终值。

对于第  个样本和第  个变量，预测时间序列的排名相关系数由以下公式给出：

其中  和  是第  个样本和第  个变量的时间序列。然后， 表示为：

尽管msIC有效地反映了预测和真实时间序列之间的相关性，但它并没有考虑到时间序列的时变分布所导致的时间波动。因此，我们还构建了msIR来捕捉这一方面。具体来说，对于第  个样本，跨通道相关性可以表示为：

并且  保持严格的时序顺序。这些值的标准差由以下公式给出：

其中 。最后， 计算为：

msIR反映了模型实现的有效相关性（由msIC表示）与时间序列动态变化所引起的相关性“噪声”（由msIC序列的标准差反映）之间的比率。较高的值表明模型在不同样本中实现高且稳定的相关性（大的msIC和小的标准差），这意味着在时间预测性能上具有更好的可靠性。较低的值可能表明，尽管模型在某些样本中表现良好（在某些点上有大的msIC），但在不同样本中存在高变异，这反映了模型的可靠性或稳定性较差。

#### 5\. 实验

为了弥合现实世界的金融时间序列数据与尖端时间序列模型之间的差距，我们采用了超过10种先进的时间序列模型，并在三种金融时间序列场景中进行了广泛的实验测试：多变量到多变量预测、多变量到单变量预测和多变量到部分预测。这些时间序列模型包括：TimeMixer(Wang等人，2024a)、Koopa(Liu等人，2023a)、iTransformer(Liu等人，2024)、PSformer(Wang等人，2024d)、TiDE(Das等人，2023)、PatchTST(Nie等人，2023)、DLinear(Zeng等人，2023)、Stationary(Liu等人，2022)、TSMixer(Chen等人，2023)、TimesNet(Wu等人，2023)、FEDformer(Zhou等人，2022)、Autoformer(Wu等人，2021a)、Crossformer(Zhang & Yan，2023)、Transformer(Vaswani，2017)、Informer(Zhou等人，2021)，以及一个Naive模型。

![](assets/006.png)

通过设计与现实世界金融应用一致的预测任务和评估协议，我们的工作为当前SOTA时间序列模型在现实金融环境中的表现提供了全面的基准。此外，我们引入了AI驱动方法的深入见解，以推进金融时间序列预测。详细的实验设置和补充分析记录在附录B.1中。

##### 5.1 多变量到多变量预测

设置。多变量任务的多元预测在时间序列预测实验中广泛使用，例如天气预报或电力预测。我们对三个数据集上的16个时间序列模型在这些任务上的表现进行了广泛评估，考虑到金融时间序列的非平稳性和低信噪比，以及交易日的特点。对于每个数据集，我们选择了四个不同的预测长度 ，每个任务运行5次，以确保实验的稳健性。我们使用MSE和MAE作为指标来衡量预测值和实际值之间的误差，并使用msIC和msIR作为指标来衡量时间序列相关性。

结果。表3显示了这些模型在每个数据集上的平均表现，完整的实验结果详见表9。从模型比较中可以看出，没有一个模型在每个数据集的每个指标上表现出绝对优势；然而，比较优势确实存在。其中，PSformer、TimeMixer、TiDE和PatchTST在大多数任务中表现出竞争力，PSformer在12个实例中实现了最佳表现。值得注意的是，尽管早期的模型，如Transformer和FEDformer，在误差指标上不具竞争力，但在某些数据集上，它们在相关性指标上表现出竞争力，提供了模型评估的另一个维度。Naive模型，它只是重复输入时间序列的最后一个值，几乎缺乏预测相关性，但其误差指标保持在较低水平，甚至超过了一些尖端的时间序列模型。这种现象在非平稳和非周期性时间序列预测中广泛观察到。

![](assets/007.png)

##### 5.2 多变量到单变量预测

设置。多变量预测单变量时间序列是时间序列预测中的一个重要实验设置，具有广泛的实际应用。我们不仅从时间序列预测的角度评估模型性能，还根据不同金融数据集的应用场景构建了各种投资策略，例如择时交易和多空交易，并评估这些模型在投资策略中的表现。

结果。在表10和表11中呈现的性能评估中，Naive模型在大多数情况下保持了较低的MSE和MAE损失。此外，PSformer、PatchTST和DLinear表现出相对较小的损失。Naive模型在GSMI和BTCF数据集上实现了最低的误差指标，这与预测价格序列的难度较高有关。在相关性指标方面，PSformer、Stationary和DLinear表现出更强的竞争力。总体而言，PSformer在12个指标中表现最佳或第二佳。虽然评估指标有效地展示了模型的预测性能，但图8直观地展示了模型在GSMI上的市场择时表现，表4量化了不同模型之间策略统计指标的对比。更多单变量实验和相关讨论，请参见附录B.3。这些结果提供了模型性能对比和金融领域潜在应用的更广泛视角。

##### 5.3 多变量到部分预测

设置。部分变量的多变量预测目前不是时间序列预测的主流实验设置。然而，（Wang等人，2024c）讨论了这一实际场景的重要性。在这项工作中，我们将GSMI数据集中的20个指数的收盘价格设定为目标变量进行预测。我们评估了模型在GSMI数据集上的表现。此外，我们构建了一个投资组合选择策略，并在同时持有不同数量的指数时回测回报表现。

结果。表12和表13显示了预测部分变量的表现。在误差指标方面，Naive和PatchTST模型表现更好，而PSformer和Informer表现出更好的相关性指标。从图10中的投资组合选择回测图来看，没有一个模型在不同数量的指数持有情况下始终实现最高的累计回报。然而，在大多数情况下，这些模型的累计回报高于20个指数的平均回报曲线，并且随着持有指数数量的减少，这种趋势变得更加明显。

#### 6\. 结论

本研究弥合了先进时间序列预测模型与实际金融应用之间的差距。我们构建了专门的金融数据集，捕捉了全球指数、衍生品和加密货币市场的不同市场动态，通过msIC和msIR指标量化了多步预测任务中的时间相关性。此外，广泛的策略评估和可视化验证了先进模型在实际金融部署中的有效性和潜力。未来的工作将探索将大型基础模型和基于代理的系统与更广泛的金融时间序列分析任务相结合。

  

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/008.png)

  

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