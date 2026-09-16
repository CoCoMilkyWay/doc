# KDD 2026 量化论文合集

QuantML QuantML 2026-06-27 20:34 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247494142&idx=1&sn=acee4fcccd93d9a4dfea69916ff50547&chksm=cf4c4ccc5120d2668f08f0cfaac28cc1c1656695e1e95709e7b649da1e8779f8d4cb3abb8531#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247494142&idx=1&sn=acee4fcccd93d9a4dfea69916ff50547&chksm=cf4c4ccc5120d2668f08f0cfaac28cc1c1656695e1e95709e7b649da1e8779f8d4cb3abb8531#rd)

![](assets/001.png)

KDD 2026（第32届ACM SIGKDD）将于**8月9-13日**在韩国济州岛召开。作为数据挖掘领域的顶会（CCF-A），今年的KDD在金融量化方向可以说是**含金量拉满**——从LLM驱动的投资策略到宏观高频混合预测，从债券交易自动化到欺诈检测的双层对抗，几乎覆盖了量化投研的全链路。

更值得关注的是，**8月10日被官方设为 Finance Special Day**，足见学术界对金融AI的重视程度。

今天这篇文章，我为大家系统梳理了本届KDD已公布的**全部量化金融相关论文**，按照投研链路分门别类，建议收藏。

## 一、投资策略与组合管理：LLM终于能"实盘"了？

### 🔥 1. FINSABER：LLM投资策略能否跑赢市场？（Oral，D&B Track）

> “
> 
> **原论**：_Can LLM-based Financial Investing Strategies Outperform the Market in Long Run?_
> 
>  **作者**：Li Weixian Waylon, Kim Hyeonjun, Cucuringu Mihai, Ma Tiejun

**核心摘要**：构建了一个面向LLM金融交易策略的综合性回测基准框架FINSABER-2，支持传统技术分析、机器学习和LLM智能体策略的统一评估。框架涵盖2000-2025年标普500的多模态数据（价格、新闻、财报），并纳入滑点、流动性限制、LLM成本核算等真实交易成本。

**点评**： 这是本届KDD最受关注的金融论文之一，从Datasets & Benchmarks Track **92篇Cycle 1投稿中仅7篇被选为Oral**。真正解决了LLM量化策略的\*\*"回测公平性"**问题——把传统技术分析、机器学习、LLM Agent放在同一套回测框架下比拼。对于想验证"ChatGPT炒股"是否靠谱的研究者来说，这是**目前最权威的基准平台\*\*。代码已开源，值得所有做LLM量化的团队跟进。

### 2\. ReCAP：市场状态切换下的持续学习组合管理（Research Track）

> “
> 
> **论文**：_Regime-Adaptive Continual Learning for Portfolio Management_
> 
>  **作者**：Chaofan Pan 等

**核心摘要**：提出ReCAP框架，将持续学习引入动态投资组合管理。通过自适应市场状态检测将历史数据分割为可变长度区间，构建策略库，并在持续交易中根据当前市场状态通过门控机制自适应组合历史策略，仅更新当前状态策略和门控参数，实现快速适应市场状态切换的同时保留有效历史知识。

**点评**： 这本质上是在做"策略的元学习"**——不重新训练整个模型，而是像人类交易员一样"记住不同市况下的经验"。在5个真实数据集上验证，长期回报和状态切换适应性均优于主流基线。对于做**多策略组合、动态择时的团队，这篇的方法论很有启发。

### 3\. 双目标竞争下的最优投资组合（Research Track Oral）

> “
> 
> **论文**：_Portfolio Choice with Competing Precautionary and Accumulation Goals_
> 
>  **作者**：Ananya Parashar

**核心摘要**：研究家庭同时管理随机期限目标（如医疗紧急支出）和固定期限目标（如退休）时的最优组合选择。发现"增长挤出效应"和"截止日期压力效应"两种新颖现象，并揭示了一个反直觉结论：在某些财富区间，略有钱的家庭因被迫支付随机目标而耗尽固定目标资金，最终反而比稍穷的家庭更差。

**点评**： 偏理论的一篇，但发现了"流动性需求对长期资产配置的扭曲效应"。做FOF、家族办公室配置或目标日期基金（TDF）的同行可以看看，对理解"多目标约束下的最优风险暴露"有启发。

## 二、预测与信号：从新闻情感到宏观注意力

### 4\. 混合新闻情感引擎：零GPU的实时市场分析（Research Track Oral）

> “
> 
> **论文**：_Hybrid News Sentiment Engine: Real-Time Market Analysis via Adaptive Ensemble Learning on News-Price Pairs_
> 
>  **作者**：Andreas Aigner

**核心摘要**：提出一个无需神经网络训练、零GPU的三向集成新闻情感引擎，结合金融词典评分、自适应TF-IDF聚类学习器和自动校准权重机制，从配对的新闻标题与资产价格快照中持续学习市场情绪。覆盖股指、商品和加密货币，在CPU服务器上实现亚秒级延迟和几乎零边际成本。

**点评**： 这篇的"反深度学习"**思路很有意思。在量化实盘环境中，"轻量、可解释、低延迟"往往比"大模型、高算力"更实用。这个引擎的边际成本几乎为零，对中小量化团队或需要**实时情感信号的策略很有参考价值。

### 5\. HANET：宏观-高频混合注意力预测网络（D&B Track）

> “
> 
> **论文**：_Macro-aware Time Series Forecasting via Hierarchical Mixed-Frequency Attention Models_
> 
>  **作者**：Daniel Cunha Oliveira, Jakob Albers, Mihai Cucuringu, Sam Howison

**核心摘要**：提出层次混合频率注意力网络HANET，将日频资产收益嵌套在月频宏观窗口内，通过层次交叉注意力机制协调低频宏观信号与高频市场动态，使模型能够"选择"当前最相关的历史宏观状态。在55种跨资产类别流动性期货上验证，尤其在市场动荡时期显著优于忽略宏观信息的神经预测器。

**点评**： 宏观因子（如CPI、PMI、利率）对资产定价的影响是**非线性和状态依赖的**。HANET用注意力机制"选择"当前最相关的历史宏观状态，这比简单地把宏观数据拼接到特征尾部要聪明得多。消融实验显示：同样的宏观表示，直接喂给LSTM效果很差，说明**结构化的宏观条件化**是关键。做宏观量化或CTA的团队值得精读。

## 三、风控与反欺诈：图神经网络的新战场

### 6\. 双层对抗学习：标签延迟+概念漂移下的欺诈检测（Research Track）

> “
> 
> **论文**：_Data-Centric Dual-Layer Adversarial Learning for Fraud Detection under Label Delay and Concept Drift_
> 
>  **作者**：武汉大学 沈明轩, 洪亮, 徐青影

**核心摘要**：针对银行欺诈检测中的标签延迟和概念漂移问题，提出数据中心的双层对抗框架。通过因果归因模块解耦两者的单独影响及联合作用，在节点层施加特征扰动缓解标签延迟，在社区层施加结构扰动适应群体行为演化，实现协同纠错。在大型商业银行实际部署中识别出1,449个此前未知的欺诈账户。

**点评**： 从"论文指标"到"真实业务价值"，这篇是本届KDD金融应用中最扎实的之一。在公开数据集上AUC提升2.4，F1提升3.5；更关键的是在某大型商业银行实际部署中**识别出1,449个此前未知的欺诈账户**。工业界和学术界结合的典范。

### 7\. DyGADBench：动态图异常检测基准（D&B Track）

> “
> 
> **论文**：_DyGADBench: A Comprehensive Benchmark for Anomaly Detection in Dynamic Graphs_
> 
>  **作者**：BNP Paribas, LIX, École Polytechnique 等

**核心摘要**：构建动态图异常检测的综合基准测试框架，系统评估多种方法在真实世界数据集上的性能，涵盖离散时间和连续时间动态图模型，支持边级和节点级异常检测任务。为金融交易网络、反洗钱等场景中的动态图异常检测研究提供了统一的评估标准。

**点评**： BNP Paribas（法国巴黎银行）直接参与学术基准建设，**金融机构深度参与学术基础设施**的信号很明显。对于做**反欺诈、反洗钱、关联交易监测**的团队，这是必跟的基础设施。

### 8\. TransactionGPT

> “
> 
> **论文**：_TransactionGPT_
> 
>  **作者**：Visa Research Yingtong Dou 等

**核心摘要**：提出面向支付网络交易数据的基础模型TransactionGPT，采用3D-Transformer架构（特征、元数据、时间维度三个耦合Transformer）和虚拟token机制，在十亿级真实交易数据上训练。参数量仅约10M，但在异常检测任务上比生产模型提升22%，训练推理速度比Llama2-7B微调快300倍。

**点评**： Visa Research出品，**十亿级真实交易数据**训练的交易基础模型。核心洞察：**交易数据有自己的结构规律，不需要套用NLP大模型的范式**。做支付风控、交易反欺诈、用户行为预测的团队，这篇是"工业级基础模型"的标杆。

### 9\. TREASURE

> “
> 
> **论文**：_TREASURE: A Transformer-Based Foundation Model for High-Volume Transaction Understanding_
> 
>  **作者**：Visa Research Chin-Chia Michael Yeh 等

**核心摘要**：提出多用途交易理解基础模型TREASURE，同时捕获消费者行为和支付网络信号（如响应码、系统标志），支持异常检测和推荐系统等多个下游任务。作为独立模型使异常检测提升111%，作为embedding提供者使推荐模型提升104%。

**点评**： 与TransactionGPT形成互补，TREASURE更强调**多用途性**——一个基础模型服务多个下游任务。对于金融机构来说，这比为每个任务单独建模要高效得多，展示了"基础模型+金融"的落地路径。

## 四、交易自动化：从债券询价到在线分解

### 10\. Chat2Trade：中信证券的债券RFQ智能解析（Applied Data Science）

> “
> 
> **论文**：_Chat2Trade: Automating Financial RFQ Parsing with Fine-Tuned LLMs_
> 
>  **作者**：中信证券（CITIC Securities）

**核心摘要**：基于微调大语言模型构建智能债券询价报价（RFQ）解析系统，集成于中信证券"八爪鱼"固收智能平台。针对固收市场RFQ文本非结构化、口语化的特点，利用大模型进行意图识别和参数抽取，实现债券询价的自动化解析。

**点评**：**国内券商大模型应用首次在CCF-A类会议发表**，具有标志性意义。固收市场的RFQ（Request for Quote）是交易员之间的即时通讯文本，充满口语、缩写、省略——"10y国开 3.15% 出500"这种表达，传统NLP几乎无法解析。用大模型做意图识别和参数抽取，是"金融大模型落地"的典型案例。

### 11\. FOCAL：频率正则化的在线耦合张量分解（Research Track）

> “
> 
> **论文**：_Fast and Accurate Online Coupled Matrix-Tensor Factorization via Frequency Regularization_
> 
>  **作者**：Yong-chan Park, SeungJoo Lee, U Kang

**核心摘要**：提出频率正则化的在线耦合矩阵-张量分解方法FOCAL，通过区分新旧数据避免流式场景下的全量重训练，同时用频率正则化缓解过拟合。在美股、日股、中国股票数据集上验证，为多源异构金融数据（行情、订单簿、基本面）的实时联合建模提供了高效的可扩展方案。

**点评**： 多源异构数据的联合建模一直是量化难点，张量分解提供了高阶交互的数学框架，在线版本则适配了流式数据场景。对于做**多因子合成、高频数据降维、实时信号融合**的团队，这篇的方法值得借鉴。

_免责声明：本文仅供学术交流，不构成任何投资建议_

_相关论文代码均已整理至QuantML知识星球_

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/002.jpg)