# HRT | 金融基础模型与 Scaling Laws

QuantML QuantML 2026-01-17 19:49 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493015&idx=1&sn=2d3cc7061cbc6dbd68ad98d7913fbc13&chksm=cff65c2623713cd95da62f4f2f17261df19be1160a6bfc293daa6a9be26057ec185d5adcf373#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493015&idx=1&sn=2d3cc7061cbc6dbd68ad98d7913fbc13&chksm=cff65c2623713cd95da62f4f2f17261df19be1160a6bfc293daa6a9be26057ec185d5adcf373#rd)

Hudson River Trading (HRT) AI实验室（HAIL）的Marc Khoury 在 ICML 2025 Expo Talk Panel 发表了关于在自动化交易中构建基础模型（Foundation Models for Automated Trading）的演讲，本文我们对其进行深入总结与梳理。

  

![](assets/001.png)

  

演讲链接： https://icml.cc/virtual/2025/46791

### 核心背景与市场微观结构

**Hudson River Trading (HRT) 的定位**  

HRT 作为全球顶级的自动化交易公司，占据美国市场约 10% 的交易量。其核心竞争力在于利用机器学习（Machine Learning）处理海量金融数据。AI Labs 团队（HAIL）专注于跨资产类别的深度学习模型研发与部署。

**Limit Order Book (LOB) 与价格本质**

“股价”并非单一数值，而是由 **Limit Order Book (LOB)** 这一数据结构所定义的。LOB 聚合了市场中所有流动性的供需意图：

-   **Bid (买单)** 与 **Ask (卖单)** ：分别代表买方意愿和卖方意愿。
    
-   **Spread (价差)** ：Best Ask 与 Best Bid 之间的差额，代表交易的显性成本。
    
-   **Mid-price (中间价)** ：Best Bid 和 Best Ask 的平均值，常被视为公允价值的代理。 市场微观结构的核心在于：资产流动性越差，进入头寸的风险越高，Spread 通常越宽以补偿风险。
    

**交易策略与盈利机制**  

自动化交易的Alpha来源主要归为两类：

1.  **Market Making (做市)** ：提供流动性（Passive Orders）。通过赚取 Spread 获利，本质是跨时间的供需匹配。其核心风险在于 **Adverse Selection (逆向选择)** ——即交易对手方拥有比做市商更优越的信息（Information Asymmetry），导致做市商在价格即将不利变动前成交。
    
2.  **Removing Liquidity (吃单)** ：消耗流动性（Aggressive Orders）。基于对未来价格方向的预测，主动成交。此类策略要求模型具备比市场更精准的预测能力（Smarter）或更快的执行速度（Faster）。
    

### 建模挑战：智能与速度的权衡

**Smart vs. Fast Trade-off**

交易系统面临严格的 **Pareto Frontier**：

-   **更复杂的模型 (Smarter)** ：能捕捉非线性、非显性的市场特征，提取深层Alpha。
    
-   **更低延迟的系统 (Faster)** ：能抢占显性机会，减少滑点。 增加计算量（Compute）必然带来推理延迟（Inference Latency）。必须在“模型预测能力”与“系统响应速度”之间寻找最优平衡点。
    

**模型架构的选择与归纳偏置**

金融数据处理面临特定的架构挑战：

1.  **Transformers**：
    

-   **优势**：擅长处理长上下文（Long Context），能回顾历史所有事件进行推断。
    
-   **劣势**：推理成本高昂，随序列长度呈线性或二次增长。在极端延迟敏感的场景下（如 tick-to-tick 预测），无法满足实时性要求。
    

3.  **Recurrent Architectures (RNNs/SSMs/LSTMs)** ：
    

-   **优势**：推理时间复杂度为 ，极其适合低延迟环境。
    
-   **劣势**：存在强烈的归纳偏置（Inductive Bias），强迫将历史信息压缩至固定大小的 Hidden State。在金融这种极低信噪比（Low Signal-to-Noise Ratio）的数据环境中，这种压缩往往是有损的，难以有效区分噪音与信号，导致长期依赖信息的丢失。
    

**数据处理：时间 vs. 事件**

金融数据是非均匀的（Non-uniform）。市场活动在某些时刻极度密集（Burst），而在其他时刻稀疏。传统的基于时间（Time-based）的Tokenization（如按分钟切分）会平滑掉微观结构的细节。基于事件（Event-based/Tick-based）的处理更符合市场本质，但对模型架构提出了更高要求。

### 预测目标与 Scaling Laws

**预测视界（Horizon）的困境**  

预测目标的选择直接约束了模型的复杂度：

-   **极短周期（如下一笔成交）**：数据量巨大，信噪比相对较高，但对延迟要求极高，模型必须极度轻量化。
    
-   **长周期（如1小时后）**：允许使用复杂大模型，但数据有效样本量（Effective Sample Size）急剧下降，且信噪比极低，容易过拟合。 在这两者之间，如果选择预测“1分钟后的价格”，虽有丰富的信号，但因延迟限制，不仅需要构建复杂的大模型，还面临无法实时运行推理的工程瓶颈。
    

**Scaling Laws 在金融中的验证**

HRT 的研究证实，**Scaling Laws** 在金融领域依然成立。随着模型参数量和训练数据量的增加，模型性能呈现可预测的提升。HRT 拥有超过 **100TB** 的清洗后市场数据（涵盖全球全资产类别，相当于数万亿 Tokens），并利用顶级规模的 GPU 集群进行训练。在足够大的数据规模下，大模型展现出显著优于小模型的预测能力。

### 金融 AI 的独特性

**与 NLP/CV 的本质差异**

1.  **信噪比极低** ：金融数据绝大部分是噪音。人类无法通过观察 LOB 数据直观判断涨跌，因此基线（Baseline）不是人类水平，而是必须从一开始就达到 **Super-human** 水平。
    
2.  **无完美仿真器 (No Perfect Simulator)** ：与 Atari 或 Go 不同，金融市场没有完美的 Simulator。市场是非平稳的（Non-stationary），且是非零和博弈。回测（Backtest）无法完美复刻市场冲击（Market Impact）和对手方反应，这限制了传统强化学习（RL）在端到端交易中的直接应用。
    
3.  **特征工程的重要性** ：尽管端到端学习是趋势，但在将原始 LOB 数据输入模型前，仍需进行专业的特征提取（Feature Engineering），将非结构化流数据转换为模型可理解的向量空间。
    

### 结论

构建金融基础模型不仅是算法问题，更是工程与数据的系统性工程。核心在于利用海量历史数据训练深度模型以提取微弱的 Alpha，同时通过架构创新（如改进 Transformer 的推理机制或优化 RNN 的记忆能力）来突破延迟瓶颈。在硬件算力和数据规模的双重驱动下，深度学习在量化交易中的应用正从简单的统计套利向通用的金融基础模型演进。

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)