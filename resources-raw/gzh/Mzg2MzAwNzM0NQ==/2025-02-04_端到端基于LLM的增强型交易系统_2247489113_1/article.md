# 端到端基于LLM的增强型交易系统

QuantML QuantML 2025-02-04 21:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&chksm=cfc35dd21e9698d6c2b60f895535d3293f2ee9a845fcd9f67b745458f9b660076d0e95de2f48#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&chksm=cfc35dd21e9698d6c2b60f895535d3293f2ee9a845fcd9f67b745458f9b660076d0e95de2f48#rd)

金融市场具有高度不可预测性，预测股票价格极具挑战性。理解市场情绪是应对这一挑战的一种方法，这种情绪由市场参与者的情绪和反应所塑造。从金融新闻和社交媒体中实时捕捉这种情绪至关重要，但目前的工具往往无法提供可操作的洞察。

本项目旨在填补这一空白，利用大语言模型（LLM）的优势来综合处理复杂语言和情绪模式。LLM在从多个数据源合成复杂语言和情绪模式方面表现出色。尽管在金融文本中进行情绪预测是一个经过充分研究的问题，但传统模型的成果参差不齐。通过部署基于LLM的系统，我们能够实时捕捉细微的情绪变化，旨在支持具有更高预测准确性的交易策略。

我们的端到端系统利用LLM进行精确的情绪提取，并跟踪对金融市场至关重要的动态情绪变化。该系统将情绪分析整合到交易策略中，通过性能指标进行实际验证。这种综合方法结合了基于LLM的准确性、实时多源数据和现实世界策略测试，为明智的交易决策提供了一个强大且可靠的工具。

#### 项目目标

本项目引入了一种新颖的市场情绪分析方法，将多个实时数据源（包括金融新闻和社交媒体）整合到一个综合框架中。传统的情绪工具通常依赖于单一数据源，且延迟较大。相比之下，该系统利用LLM从不同来源综合洞察，提供更全面和及时的市场情绪视图。LLM使模型能够捕捉复杂的金融语言，识别出简单模型容易忽略的微妙情绪变化。

除了基本的情绪分析外，该系统还利用LLM进行文本摘要，将大量的金融新闻和社交媒体数据提炼成简洁、有意义的洞察。这一功能使投资者和交易员能够快速了解市场动态，而无需筛选过多的信息。此外，该方法创新性地将情绪信号和分数与传统交易信号（如SMA、RSI和随机振荡指标）结合在一起。通过将情绪驱动的洞察与传统技术指标相结合，系统生成了更强大、更具可操作性的交易策略，提供了一个统一的解决方案，弥合了市场情绪和基于价格的分析之间的鸿沟。

#### 文献回顾

机器学习和深度学习的进步使情绪分析成为自然语言处理（NLP）研究的焦点，金融情绪分析通过在金融数据集上实现高准确性的模型而获得了关注。然而，以交易为中心的模型通常依赖于较简单的架构或传统方法，缺乏LLM的细致理解，并且通常在固定的数据间隔上运行。与此同时，基于LLM的模型在情绪分类方面表现出色，但很少应用于直接交易环境中，在这些环境中，连续的多源更新和交易性能验证是至关重要的。这一差距凸显了对实时、可适应解决方案的需求，该解决方案利用LLM的复杂性来支持实际的交易决策。

最近在将LLM应用于情绪分析方面的进展表明，尽管这些模型能够捕捉细微的语言模式，但它们在区分波动、短期的市场环境中的情绪强度和方向时可能会遇到困难。这种挑战源于金融文本中的情绪变化通常带有微妙的线索，这些线索很难转化为即时的交易信号。解决这个问题需要利用已经在高频金融数据上微调的模型，例如FinGPT，它增强了适应性和精确性，而无需额外的训练。我们的方法利用了这些进展，部署了特定于金融领域的LLM，并辅以实时反馈循环，以将情绪分析与交易策略相结合，并在动态市场条件下优化决策。

金融情绪分析模型已经显著发展，从FinBERT开始，这是一个基于BERT的模型，针对金融特定语言进行了微调。尽管FinBERT在金融环境中的情绪分类有所改进，但它受到批处理的限制，这不适合实时交易。后来出现了BloombergGPT，这是一个特定于金融的变压器模型，在命名实体识别和情绪分析等任务中表现出色。然而，其高昂的成本和缺乏在交易应用中的验证限制了其可访问性和在高频交易中的使用。最新的进展FinGPT在金融情绪任务中表现出强大的性能，并且是一个开源替代方案；然而，它尚未在实时交易环境中进行测试。我们的方法利用了这些进展，部署了特定于金融领域的LLM，并辅以实时反馈循环，以将情绪分析与交易策略相结合，并在动态市场条件下优化决策。

相比之下，其他事件驱动的股票预测模型，如ANRES和基于CNN的模型，纳入了情绪数据，但依赖于静态的历史时间窗口和有限的数据源，限制了其对实时市场动态的适应性。ANRES使用带有金融新闻注意力的LSTM，缺乏实时更新，并在固定日期上运行，而Ding等人的模型仅根据情绪类概率执行交易，限制了决策灵活性。同样，FAST模型采用LSTM进行顺序数据处理，但它无法像LLM那样有效地捕捉细微的上下文，并且包含了嘈杂的推文数据，而没有解决潜在的不准确性问题。这些局限性凸显了对一个强大、实时模型的需求，该模型能够适应多源数据，以适应连续、动态的交易环境。

#### 技术考虑

我们的主要模型是FinGPT，并辅以对Llama和Granite模型的微调版本，以在特定于金融的情绪任务上进行比较。FinGPT专门用于金融数据集，并以高精度捕捉细微的市场语言。额外的模型有助于验证我们的发现，表明LLM可以增强情绪分析和交易策略。这种比较方法加强了我们的结果，并为LLM在交易中的作用提供了更广泛的见解。

由于对谷歌云平台的高需求，我们无法获得持续访问GPU资源的权限，而是利用Colab的A100 GPU进行验证和测试。为了解决单个A100 GPU的内存限制，我们选择了Cohere的摘要模型，因为它具有轻量级架构和效率，能够在保持可管理的资源需求的同时进行有效的情绪分析。

#### 方法论与实现

该系统遵循模块化工作流程（见图1）来处理实时金融数据、提取情绪并生成可操作交易信号。用户通过前端提交股票代码，这会触发数据收集。股票价格被聚合成分钟级的VWAP，金融新闻和Reddit帖子被清理、摘要并使用FinGPT进行分析。处理后的数据与技术支持指标（如SMA交叉、RSI和随机振荡指标）相结合，以生成买卖信号。结果，包括VWAP、交易信号和情绪分数，显示在仪表板上以供决策。该系统部署在Kubernetes上，以确保可扩展性、弹性和高效的资源管理。附录中包含了交易信号和性能评估指标（如夏普比率和胜率）的详细公式，以确保清晰和完整性。

![](assets/001.jpg)

系统工作流程图

**系统工作流程与实现**

系统工作流程包括七个关键步骤，从用户交互到部署。每个步骤都经过精心设计，以确保实时数据处理、情绪分析和可操作交易信号的生成。

1.  **用户交互与股票代码提交**
    

系统从用户输入开始，用户通过前端界面提交一组股票代码。这一步允许动态更新正在跟踪的股票代码。

实现：

-   用户通过仪表板输入提交股票代码。
    
-   后端API处理列表，验证股票代码并更新全局配置。
    
-   所有管道（价格、文本和信号）重新启动以反映新的股票代码。
    

2.  **数据收集**
    

系统从多个来源收集选定股票代码的实时金融数据，确保对市场活动的全面了解。

-   **股票价格数据**：实时股票价格和成交量数据通过WebSocket连接流式传输到Finnhub的API。价格和成交量不断被摄取并记录到缓冲区中以供进一步分析。
    
-   **金融文本数据**：
    

-   **新闻文章**：通过新闻API获取与选定股票代码相关的金融文章。
    
-   **Reddit帖子**：使用PRAW API检索WallStreetBets子版块的帖子和评论。时间的对齐确保了Reddit提交和评论之间的上下文一致性。
    

3.  **数据处理**
    

收集到的原始数据经过预处理，以确保其结构化、干净并准备好进行分析。

-   **股票价格数据**：计算分钟级的VWAP（成交量加权平均价格）以平滑短期波动并减少延迟问题。该系统使用deque等高效数据结构为每个股票代码保留滚动VWAP缓冲区。
    
-   **金融文本数据**：原始文本数据被聚合和摘要，以确保简洁和清晰。FinGPT，一个预训练的金融LLM，处理摘要文本以输出情绪分类（正面/负面）和logits（置信度分数），提供细粒度的情绪信息。
    

4.  **情绪分析与信号生成**
    

处理后的价格和情绪数据被结合起来以生成可操作交易信号。

-   **情绪分析**：FinGPT的情绪输出（分类和logits）被整合为情绪信号。
    
-   **技术信号生成**：使用以下方法计算交易信号：
    

-   **SMA交叉**：快速和慢速移动平均线以检测短期趋势逆转。
    
-   **相对强度指数（RSI）**：识别超买或超卖条件。
    
-   **随机振荡指标**：衡量价格相对于近期高点和低点的位置。
    
-   **突破**：将情绪分数和技术指标结合起来，为每个股票代码生成统一的买入/卖出/持有信号。
    

5.  **后端处理与集成**
    

后端管理数据收集、处理和前端显示之间的实时编排。

实现：

-   **并发性**：数据管道（股票价格、文本处理和信号生成）使用多线程并发运行，以确保效率。
    
-   **后端动态提供处理后的数据**，包括情绪分数和基于VWAP的信号，通过FastAPI REST端点。
    

6.  **前端可视化与用户反馈**
    

处理后的洞察通过实时仪表板呈现给用户以供监控和交互。

实现：

-   **仪表板功能**：
    

-   **实时VWAP更新**。
    
-   **由FinGPT生成的情感摘要和logits**。
    
-   **基于情感分析和技术的买卖持有信号**。
    

-   **仪表板每几秒钟动态刷新一次**，确保近乎实时的更新。
    
-   **用户可以记录模拟交易**，这些交易被存储以供性能评估和进一步反馈。
    

7.  **部署**
    

-   **项目的部署过程涉及几个详细步骤**，以确保顺利设置和执行。我们首先使用Docker对应用程序进行容器化，为项目创建了一个标准化的环境，在Dockerfile中指定了依赖项和配置。这确保了应用程序在不同系统上能够一致地运行。接下来，我们构建了Docker镜像并将其推送到容器注册表，如Google容器注册表（GCR），以便在部署期间轻松访问。
    
-   **之后，我们在Google Kubernetes Engine（GKE）上配置了一个Kubernetes集群**，以处理编排和可扩展性。使用YAML配置文件，我们定义了部署规范，包括容器镜像、资源限制、用于GPU分配的节点选择器和环境变量。我们确保与GKE的约束相兼容，例如选择Autopilot模式下支持的适当GPU类型。YAML文件还包括用于服务发现和网络配置，以公开应用程序。
    
-   **我们通过Kubectl命令应用Kubernetes清单来部署应用程序**，这创建了必要的pod和服务。在此过程中，我们遇到了诸如由于资源不足或不支持的GPU类型而导致的挂起pod等问题。这些问题通过修改YAML文件中的资源规范并重新启动部署来解决。我们还利用Kubernetes命令，如kubectl get pods和kubectl logs来监控状态并调试任何问题。
    
-   **此外，我们实现了FastAPI作为后端框架**，以提供应用程序的API端点。API被设计用于处理股票情感分析请求，从新闻和社交媒体来源获取数据，并执行VWAP和交易信号等计算。我们将其与Cohere、Finnhub和NewsAPI等外部API集成，以进行实时数据处理。部署还需要设置日志机制，以监控管道活动并调试错误。
    
-   **最后，部署了一个仪表板**，用于实时数据可视化，允许用户通过HTTP端点与应用程序交互。仪表板定期获取数据并动态更新指标，提供股票情感、交易信号和交易日志等洞察。这种全面的部署过程确保了一个完全功能化和可扩展的系统，为生产做好了准备。
    

#### 结果与评估

**A. 与其他模型在情绪分析方面的基准比较**

我们使用精确度、召回率、F1分数和准确性对FinGPT、IBM Granite 3.0和Meta LLaMA 3.1进行了基准比较。这些指标通过考虑正确预测和假阳性和阴性之间的平衡来评估性能。

在本次基准测试中选择的Kaggle金融情感分析数据集包含金融新闻标题及其相应的情感标签。这个数据集非常适合评估交易相关背景中的模型，因为它捕捉了金融语言的细微差别和推动市场决策的情感。特定领域的术语和多样的情感表达使其具有挑战性，并且非常适合评估语言模型在提取金融情感方面的稳健性和适应性。

在评估的模型中，FinGPT在所有指标上都优于IBM Granite 3.0和Meta LLaMA 3.1。FinGPT的卓越性能可以归因于其专门为金融应用设计的架构。FinGPT采用轻量级的低秩适应（LoRA）微调方法，使其能够以最小的计算开销有效地专门处理金融数据集。LoRA微调仅优化了一部分模型参数，引入低秩矩阵以捕捉任务特定特征，同时保留核心预训练模型的通用知识。这种方法不仅确保了计算效率，还使模型能够更好地适应金融数据集中存在的特定领域词汇和情感模式。

IBM Granite 3.0和Meta LLaMA 3.1虽然在一般的NLP任务中表现强劲，但在金融情感分析中却遇到了困难，因为它们缺乏特定领域的微调和通用的训练目标。缺乏针对金融数据的针对性微调阻碍了它们捕捉复杂金融文本中的微妙情感变化。相比之下，FinGPT通过利用低秩适应（LoRA）微调，表现出色，该方法有效地使模型适应捕捉金融行话中的情感细微差别。这种专门化使FinGPT能够在提取精确和可操作的洞察方面超越其竞争对手，突出了其在情感驱动的交易策略中实时决策的潜力。

![](assets/002.png)

**B. 回测验证**

为了评估交易系统的性能，我们通过2022年和2023年的历史价格和Reddit数据进行回测，使用了两种框架：一种结合了情感信号，另一种仅使用传统技术指标。这两种策略都遵循基于头寸的方法，交易根据买卖信号动态执行。在情感增强策略中，交易决策受到情感信号的影响，信号强度决定了交易规模（初始现金的10%或15%），并且交易根据情感极性（正面/负面）进行分类。相反，基础策略仅根据技术指标执行交易，而不考虑情感。在这两种情况下，头寸翻转（从多头到空头或反之亦然）触发获利了结，头寸在最后一个可用的价格关闭。关键指标、夏普比率和胜率被计算出来，以比较情感整合策略与基线的有效性。这种双重回测方法使我们能够分析将情感信号纳入交易决策的附加值。

**1) 夏普比率**

-   情感整合策略在所有股票和策略中始终优于基线。
    
-   例如，TSLA的SMA交叉策略从0.34提高到3.47，显示出风险调整回报的显著提升。
    
-   同样，AAPL和AMZN显示出显著改善，夏普比率转为正值，表明波动性降低和盈利能力提高。
    

![](assets/003.png)

**2) 胜率**

-   情感整合也提高了胜率，尽管幅度因股票和策略而异。
    
-   对于TSLA，SMA交叉胜率从32.2%跃升至57.0%，而AAPL和AMZN的SMA策略也出现了类似的改善。
    
-   一些指标，如RSI和随机振荡器，显示较小或略有混合的改善，表明对市场条件和信号可靠性的敏感性。
    

![](assets/004.png)

**3) 含义**

-   **增强的预测能力**：整合情感信号有助于捕捉市场动态和投资者情感，这些是传统技术指标可能错过的。这提高了识别盈利机会的能力，特别是在像TSLA这样的波动性股票中。
    
-   **策略的多功能性**：尽管SMA交叉显示出最显著的改善，所有策略都从情感整合中受益。这突出了情感信号补充各种交易方法的通用性。
    
-   **股票特定的敏感性**：结果揭示，情感信号对于某些股票，如TSLA和AMZN，影响特别大，这些股票更受欢迎，讨论更广泛。对情感反应强烈的股票策略将从这种整合中获得最多收益。
    
-   **对投资者的实际用途**：投资者可以利用情感整合信号来改善决策，尤其是在传统指标产生弱或模糊信号时。这种方法减少了策略的波动性，并增加了交易结果的稳健性。
    

#### 潜在挑战与未来方向

遇到的主要挑战围绕实时数据处理的资源和延迟。数据获取、通过FinGPT运行情感分析以及生成可操作信号是计算成本高的任务。在有限的GPU资源下运行会增加延迟，这可能会阻碍实时性能，这是交易系统的关键要求。随着系统扩展到处理更多资产和用户，确保高效的数据流和更快的推理将保持为主要关注点。展望未来，系统将不断发展以应对这些挑战，同时引入增强的功能。

-   **可定制的策略**：为了提供更大的灵活性，将开发一个可编码的接口，使用户能够定义和实施他们的交易策略。用户将能够自由地整合自定义逻辑，根据他们独特的交易偏好调整平台。
    
-   **交互式交易平台**：平台将扩展到包括其他趋势资产，如加密货币，以满足更广泛的参与者。此外，整合经纪商端点将允许用户直接通过系统进行交易。附加功能，如实时风险监控、头寸跟踪和交互式可视化（例如价格图表和蜡烛图），将使平台成为一个全面且动态的交易中心。
    

  

#   

论文及代码见星球，加入QuantML星球，与700+专业人士一起交流学习：

![](assets/005.png)

  

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