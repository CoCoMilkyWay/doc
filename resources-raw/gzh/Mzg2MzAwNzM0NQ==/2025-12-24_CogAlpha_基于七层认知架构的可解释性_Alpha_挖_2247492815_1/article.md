# CogAlpha: 基于七层认知架构的可解释性 Alpha 挖掘框架

GIM QuantML 2025-12-24 17:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492815&idx=1&sn=b33179d315097cbb1e21bf0c24b055b5&chksm=cf8e860896ec2a74a34aa8e2e781b5222073188e107c7930f5c1200687c023c538d0a07d8c48#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492815&idx=1&sn=b33179d315097cbb1e21bf0c24b055b5&chksm=cf8e860896ec2a74a34aa8e2e781b5222073188e107c7930f5c1200687c023c538d0a07d8c48#rd)

![](assets/001.png)

本文来自**GIM (Grace Investment Machine)** ，中国移动九天人工智能研究院以及香港大学团队。

**GIM**核心团队由来自顶级对冲基金，DeepMind、Meta、Anthropic等国际领先大模型公司及牛津大学、清华北大、香港大学等顶尖学府的成员组成。GIM相信AI技术正在重塑资本市场投资决策，基于此，公司融合最前沿的AI及大模型技术，开发智能分析师与交易系统，致力于在量化方法论之上打造新一代智能投资范式，将金融市场的深度洞察与执行效率提升到全新水平。

## **摘要**

在量化金融领域，从高噪声、非平稳的市场数据中挖掘有效的预测信号（Alpha）始终是一个核心挑战。传统的遗传规划（GP）和深度学习方法面临着解释性差、过拟合以及搜索空间狭窄的瓶颈。本文详细剖析了一种全新的框架——**CogAlpha（Cognitive Alpha Mining）**。该框架将大语言模型（LLM）的认知推理能力与进化算法相结合，通过七层代理层级结构和代码级进化机制，实现了从浅层模式识别到深层逻辑推理的跨越，挖掘出兼具高预测性与金融解释性的 Alpha 因子。

## 1\. 引言与背景

Alpha 挖掘的认知进化Alpha 挖掘旨在从复杂的市场数据中提取能够预测资产收益的信号。这一领域经历了从基于专家经验的手工构建，到机器学习（ML）驱动的自动化挖掘，再到近期利用大语言模型（LLM）进行生成式探索的演变过程。

然而，现有的范式存在显著局限性。深度学习模型往往沦为“黑箱”，难以追踪决策逻辑，且在市场体制转换（Regime Shift）时表现脆弱。基于遗传规划（GP）的符号方法虽然提供了显式公式，但生成的表达式往往过于冗余，缺乏经济学依据，导致泛化能力差。即便是早期的 LLM 方法，也多局限于简单的公式堆叠或模式复制，缺乏真正的逻辑推理和结构创新。

针对这些痛点，**CogAlpha** 框架被提出。它不仅仅是挖掘数据，更是在模拟人类专家的认知过程。通过将 LLM 视为具备适应性的认知代理（Cognitive Agents），CogAlpha 能够在代码层面即时生成、变异和重组 Alpha 因子，利用多阶段提示工程和金融反馈闭环，极大地扩展了搜索空间并提升了因子的逻辑深度。

## 2\. 核心方法论

CogAlpha 框架详解CogAlpha 的核心在于“认知（Cognitive）”与“Alpha”的深度融合。为了克服传统方法搜索空间狭窄的问题，该框架设计了一个精密的多代理协作系统，包含**七层代理层级（Seven-Level Agent Hierarchy）**、**多代理质量检查器（Multi-Agent Quality Checker）以及思维进化模块（Thinking Evolution）**。

### 2.1 七层代理层级结构（Seven-Level Agent Hierarchy）

为了全面覆盖市场数据的潜在特征，CogAlpha 将 Alpha 挖掘任务分解为从宏观结构到微观形态的七个不同抽象层级。这种分层设计确保了因子来源的多样性，避免了单一逻辑的同质化竞争。

![](assets/002.png)

该层级结构包含 21 个特定任务代理，具体划分如下：

-   **Level I：市场结构与周期层 (Market Structure & Cycle Layer)**该层级着眼于宏观视角，利用日频 OHLCV 数据推断长期趋势、市场阶段和周期性状态转换。核心代理包括探索市场节奏的 `AgentMarketCycle` 和检测波动率状态转换的 `AgentVolatilityRegime`。
    
-   **Level II：极端风险与脆弱性层 (Extreme Risk & Fragility Layer)**专注于尾部风险建模。`AgentTailRisk` 量化下行敏感性，而 `AgentCrashPredictor` 通过捕捉流动性枯竭和波动率压缩等前兆信号，识别潜在的市场崩盘风险。
    
-   **Level III：量价动力学层 (Price-Volume Dynamics Layer)**这一层级深入微观结构，分析价格与交易活动的交互。`AgentLiquidity` 衡量市场深度与摩擦，`AgentOrderImbalance` 捕捉单边买卖压力，`AgentPriceVolumeCoherence` 则通过分析量价同步性揭示市场动能的一致性或背离。
    
-   **Level IV：价格-波动行为层 (Price-Volatility Behavior Layer)**这是传统技术分析的核心区域，但 CogAlpha 进行了更深度的量化。除了分析趋势持续性的 `AgentDailyTrend` 和均值回归的 `AgentReversal`，还包括研究非对称价格动态的 `AgentVolAsymmetry` 以及波动率聚类特征的 `AgentRangeVol`。
    
-   **Level V：多尺度复杂性层 (Multi-Scale Complexity Layer)**引入分形市场假说概念，`AgentFractal` 测量时间序列的粗糙度和长记忆性，`AgentDrawdown` 则从回撤-恢复的几何形态中提取风险特征。
    
-   **Level VI：稳定性与体制门控层 (Stability & Regime-Gating Layer)**为了提升因子的鲁棒性，该层级构建适应性机制。`AgentRegimeGating` 根据市场状态调节信号激活，`AgentStability` 则评估信号的时间一致性，优先选择稳健的 Alpha。
    
-   **Level VII：几何与融合层 (Geometric & Fusion Layer)**最微观的层级，关注 K 线形态的几何特征（`AgentBarShape`）以及多因子融合（`AgentComposite`）。该层级还利用 `AgentCreative` 进行非线性变换，并用 `AgentHerding` 探测市场羊群效应。
    

### 2.2 多样化引导策略（Diversified Guidance）

为了防止 LLM 在生成代码时陷入思维定势，CogAlpha 引入了五种转述模式（Paraphrasing Modes）来构建提示词（Prompt），从而激发模型从不同角度进行推理 ：

1.  **Light (轻微)** ：保持原意，仅作最小的语言调整，作为基准。
    
2.  **Moderate (适度)** ：引入自然的措辞变化，丰富表达形式。
    
3.  **Creative (创造性)** ：增加解释深度和研究导向的细微差别，激发替代性推理。
    
4.  **Divergent (发散性)** ：探索相关但不同的分析视角，生成互补性假设。
    
5.  **Concrete (具体化)** ：将抽象描述转化为可实施的数学公式或统计操作，弥合概念与代码的鸿沟。
    

### 2.3 多代理质量检查器（Multi-Agent Quality Checker）

生成的 Alpha 代码必须经过严格的质量控制流程。这是一个闭环的多代理系统，确保存活下来的因子不仅代码无误，且逻辑自洽。

-   **Code Quality Agent**：负责静态代码分析，检测语法错误、格式问题及运行时 Bug。
    
-   **Code Repair Agent**：针对检测到的错误尝试自动修复代码。
    
-   **Judge Agent**：这是核心的“守门人”。它不看回测绩效，而是从逻辑一致性、技术正确性和**经济学意义**三个维度评估因子。它会剔除缺乏金融逻辑的“伪相关”因子。
    
-   **Logic Improvement Agent**：对被 Judge Agent 驳回但有潜力的代码进行逻辑层面的优化和重构。
    

通过质量检查的代码将进行**单元测试**，重点排查是否存在**未来信息泄露（Look-ahead Bias）**，这是量化回测中最致命的错误。

### 2.4 思维进化（Thinking Evolution）

这是 CogAlpha 区别于传统方法的关键。它在自然语言空间实现了类遗传算法的优化过程。所有经过筛选的合格 Alpha 都会进入进化池，通过 LLM 驱动的变异（Mutation）和交叉（Crossover）操作进行迭代。

-   **Mutation Agent**：对现有 Alpha 代码进行微调，引入变异性，探索局部最优解。
    
-   **Crossover Agent**：结合两个现有 Alpha 的逻辑，生成新的复合因子，融合不同信号源的优势。
    

这一过程通过多轮迭代（Generation）进行，每一代中表现优异的“精英”因子会被保留并传递给下一代，确保种群质量的持续提升。

![](assets/003.png)

## 3\. 实验设置与实证分析

为了验证 CogAlpha 的有效性，研究团队在中国 A 股市场进行了广泛的实证测试。

### 3.1 实验环境

-   **数据集**：CSI300（沪深300）成分股，涵盖 2011 年至 2024 年的数据。训练集为 2011-2019，验证集 2020，测试集 2021-2024。
    
-   **预测目标**：10 日收益率（10-day return）。
    
-   **基准模型**：包括 LightGBM、Random Forest 等传统 ML 模型，LSTM、Transformer 等深度学习模型，Alpha-158/360 因子库，以及 GPT-4、Llama3 等通用 LLM。
    
-   **评估指标**：IC（信息系数）、RankIC、ICIR、RankICIR 以及衡量非线性依赖的互信息（MI）。
    

### 3.2 性能对比实验

结果表明，**CogAlpha 在所有关键指标上均显著优于基准方法**。

在与主流机器学习模型的对比中，CogAlpha 实现了 0.0591 的 IC 和 0.0814 的 RankIC，远超 LightGBM（IC: 0.0269）和 Transformer（IC: -0.0090）等模型。这表明 CogAlpha 生成的因子不仅捕获了线性关系，还通过代码逻辑捕捉了复杂的市场非线性特征。

与通用 LLM（如 GPT-4.1, gpt-oss-120B等）直接生成因子的方法相比，CogAlpha 的优势更为明显。例如，GPT-4.1 的 IC 仅为 0.0118，而 GPT-OSS-120B 为 0.03。这证实了单纯依赖 LLM 的知识库不足以应对高噪金融数据，必须结合进化搜索和严格的质量控制机制。

![](assets/004.png)

### 3.3 因子的可解释性与进化

案例CogAlpha 的一大优势在于生成**可解释的代码**。每个生成的 Alpha 都附带详细的注释，解释其背后的金融逻辑。

**案例：流动性冲击因子的进化**

研究展示了一个流动性相关因子的进化轨迹，生动诠释了 CogAlpha 的“认知”能力。

1.  **初始版本 (Generation 0)** ：
    

模型生成了一个基于经典微观结构理论的因子：

该公式衡量单位成交量带来的价格上行阻力。逻辑简单，但在测试集上表现平平（IC: 0.0090）。

2.  **变异版本 (Mutation)** ：
    

进化过程中，Agent 尝试使用全天价格范围（High-Low）替代收盘价差：

这一改动试图捕捉更广泛的日内流动性行为，但效果并未改善（IC 降至 0.0073），因此在优胜劣汰中被淘汰。

3.  **最终进化版本 (Evolved)** ：
    

经过多轮迭代，CogAlpha 产出了一个更优化的版本。它引入了“成交额（Dollar Volume）”进行标准化，并应用了 `tanh` 函数处理离群值：

`df_copy['abs_move'] = (df_copy['day_close'] - df_copy['day_open']).abs()   df_copy['dollar_vol'] = df_copy['day_volume'] * df_copy['day_close']   df_copy['raw_impact'] = df_copy['abs_move'] / (df_copy['dollar_vol'] + eps)   # Apply tanh to bound the factor within (-1, 1)   df['factor'] = np.tanh(df_copy['raw_impact'])      `

这一版本的 IC 跃升至 0.0141，RankIC 达到 0.0087。

这个过程清晰地展示了 CogAlpha 如何像人类研究员一样，从一个粗糙的“想法”出发，通过尝试不同的变量组合、归一化方法和非线性变换，最终打磨出一个稳健的 Alpha 因子。

### 3.4 消融研究

为了验证各组件的贡献，研究进行了消融实验。结果显示：

-   仅使用基础 Agent（Agent）：RankICIR 为 0.2595。
    
-   加入进化模块（+E）：RankICIR 提升至 0.3322。
    
-   加入自适应生成（+A）：RankICIR 提升至 0.3583。
    
-   加入多样化引导（+G）：RankICIR 提升至 0.3599。
    
-   **完整 CogAlpha（+H 七层结构）**：RankICIR 最终达到 **0.4350**。
    

这一递增的性能证明了每一层设计——从进化算法到提示工程再到层级结构——都在为最终的 Alpha 质量贡献独特的价值。

![](assets/005.png)

![](assets/006.png)

## 4\. 结论与展望

CogAlpha 框架代表了量化金融领域的一个重要里程碑：从“暴力挖掘”迈向“认知创造”。它不仅解决了传统深度学习模型不可解释的难题，也突破了传统遗传算法产生冗余公式的限制。

通过**七层代理结构**确保因子的多样性，利用**多代理质量检查**保证逻辑的严密性，并借助**思维进化机制**实现代码级的自我优化，CogAlpha 成功挖掘出了具有高预测精度、强鲁棒性和清晰经济学解释的 Alpha 因子。

这一研究表明，将 LLM 的推理能力与进化计算相结合，是解决高维、低信噪比金融预测问题的有效路径。未来，随着 LLM 推理能力的进一步增强，类似的认知型挖掘框架有望在更广泛的另类数据（Alternative Data）和跨资产类别策略中发挥关键作用。

* * *

GIM团队近期也开放招聘：

**AI量化研究员**

**北京/深圳、全职/实习**

我们希望你是：

-   硕士及以上学历,计算机、数学、金融工程、物理等理工相关专业业；
    
-   优秀编程能力，计算机竞赛奖牌者优先；
    
-   深入理解金融市场,掌握多因子、动量、套利等核心量化方法论；
    
-   有 AI、深度学习/机器学习（如Transformer、LightGBM、LSTM）金融应用经验者优先；
    
-   精通 Python，熟悉 Pandas/Numpy/Numba；
    
-   具备探索精神、独立思考与主动学习能力。
    

**AI量化系统开发**

**北京/深圳、全职**

我们希望你是：

-   本科及以上学历，计算机科学、信息工程、自动化等相关专业背景；
    
-   精通 Python 语言，具备规范的代码组织与模块化开发能力，了解 C++/Rust 者优先加分；
    
-   熟练驾驭 Linux 环境，能熟练使用 Docker、Kubernetes、Git 等 DevOps 工具；
    
-   熟悉机器学习部署流程，拥有 MLOps 或 AI 模型工程实践经验者将被优先考虑；
    
-   搭建并持续优化量化研究平台，涵盖历史数据加载、回测系统、实时模拟系统等核心模块；
    
-   开发与维护交易执行模块，设计并完善策略风控相关功能；
    
-   支撑 AI 策略工程侧部署，包括模型版本控制、自动训练、推理服务化（支持 ONNX/MLflow 等）；
    
-   管理交易基础设施，涉及数据库、数据接入 API、消息队列、容器环境等运维与优化；
    
-   与量化研究员紧密协作，推动策略从研究阶段到实盘落地的高效迭代。
    

如果你对以上职位感兴趣，请将你的简历投递至： **talents@graceim.ai**

  

![](assets/007.gif)

  

  

  

  

![Merry christmas typography with santa hat for holiday celebration | Premium  Vector](assets/008.jpg)