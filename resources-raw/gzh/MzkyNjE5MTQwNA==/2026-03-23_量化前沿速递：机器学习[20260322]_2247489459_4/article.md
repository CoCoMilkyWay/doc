# 量化前沿速递：机器学习\[20260322\]

shameless 量化前沿速递 2026-03-23 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489459&idx=4&sn=747d538bddefb25d47718d3da113e087&chksm=c3a1b11d9c3770f8ea5edec71d83690b7d0b83405d4a4308e076a0ae80b1b1dded4154672d8b#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489459&idx=4&sn=747d538bddefb25d47718d3da113e087&chksm=c3a1b11d9c3770f8ea5edec71d83690b7d0b83405d4a4308e076a0ae80b1b1dded4154672d8b#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] AI Agents in Financial Markets

金融市场中的人工智能代理

来源:ARXIV\_20260317

\[2\] E TRENDS

E趋势

来源:ARXIV\_20260317

\[3\] A Controlled Comparison of Deep Learning Architectures for Multi Horizon Financial Forecasting

用于多层次财务预测的深度学习架构的受控比较

来源:ARXIV\_20260319

\[4\] LR Robot

LR机器人

来源:ARXIV\_20260319

### 

\[1\] AI Agents in Financial Markets

标题:金融市场中的人工智能代理

作者:Hui Gong

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.13942

Abstract : Recent advances in large language models, tool using agents, and financial machine learning are shifting financial automation from isolated prediction tasks to integrated decision systems that can perceive information, reason over objectives, and generate or execute actions. This paper develops an integrative framework for analysing agentic finance  financial market environments in which autonomous or semi autonomous AI systems participate in information processing, decision support, monitoring, and execution workflows.The analysis proceeds in three steps. First, the paper proposes a four layer architecture of financial AI agents covering data perception, reasoning engines, strategy generation, and execution with control. Second, it introduces the Agentic Financial Market Model (AFMM), a stylised agent based representation linking agent design parameters such as autonomy depth, heterogeneity, execution coupling, infrastructure concentration, and supervisory observability to market level outcomes including efficiency, liquidity resilience, volatility, and systemic risk. Third, it develops an illustrative empirical application based on event studies of AI agent capability disclosures and heterogeneous market repricing.The central argument is that the systemic implications of AI in finance depend less on model intelligence alone than on how agent architectures are distributed, coupled, and governed across institutions. In the near term, the most plausible equilibrium is bounded autonomy, in which AI agents operate as supervised co pilots, monitoring systems, and constrained execution modules embedded within human decision processes.

Keywords : 

Abstract :大型语言模型、工具使用代理和金融机器学习的最新进展正在将金融自动化从孤立的预测任务转变为可以感知信息、推理目标并生成或执行行动的集成决策系统。本文开发了一个综合框架，用于分析代理金融市场环境，其中自主或半自主的人工智能系统参与信息处理、决策支持、监控和执行工作流程。分析分为三个步骤。首先，本文提出了一种金融人工智能代理的四层架构，涵盖数据感知、推理引擎、策略生成和控制执行。其次，它介绍了代理金融市场模型（AFMM），这是一种基于代理的风格化表示，将代理设计参数（如自治深度、异质性、执行耦合、基础设施集中度和监管可观察性）与市场层面的结果（包括效率、流动性弹性、波动性和系统性风险）联系起来。第三，它基于人工智能代理能力披露和异质市场重新定价的事件研究，开发了一个说明性的实证应用。核心论点是，人工智能在金融领域的系统性影响与其说仅仅取决于模型智能，不如说取决于代理架构如何在机构间分布、耦合和治理。在短期内，最合理的平衡是有限自主，其中人工智能代理作为受监督的副驾驶、监控系统和嵌入人类决策过程中的受限执行模块运行。

Keywords :

### 

\[2\] E TRENDS

标题:E趋势

作者:Harris Buchanan, Eric Benhamou

来源:ARXIV\_20260317

链接:https://arxiv.org/pdf/2603.14453

Abstract : Trend following strategies underpin many systematic trading approaches yet struggle under nonstationary and nonlinear market regimes. We propose an LSTM based framework to forecast next day trend differences (  Delta t ) for the top 30 S &P 500 equities, validated across market cycles (2005  2025). Key contributions include  (i) formal proof of bias variance reduction via differencing, (ii) exhaustive empirical benchmarks against OLS, Ridge, and Lasso, (iii) portfolio simulations confirming economic gains in terms of overall PNL compared to other models like OLS, Ridge, Lasso or LightGBM Regressor

Keywords : 

Abstract :趋势跟踪策略是许多系统交易方法的基础，但在非平稳和非线性的市场制度下却举步维艰。我们提出了一个基于LSTM的框架，用于预测标准普尔500指数前30只股票的次日趋势差异（Δt），并在整个市场周期（2005-2025）中进行了验证。主要贡献包括（i）通过差分减少偏差方差的正式证明，（ii）针对OLS、Ridge和Lasso的详尽经验基准，（iii）投资组合模拟，与OLS、Ridge、Lasso或LightGBM Regressor等其他模型相比，确认了总体PNL的经济收益

Keywords :

### 

\[3\] A Controlled Comparison of Deep Learning Architectures for Multi Horizon Financial Forecasting

标题:用于多层次财务预测的深度学习架构的受控比较

作者:Nabeel Ahmad Saidd

来源:ARXIV\_20260319

链接:https://arxiv.org/pdf/2603.16886

Abstract : Multi horizon price forecasting is central to portfolio allocation, risk management, and algorithmic trading, yet deep learning architectures have proliferated faster than rigorous financial benchmarks can evaluate them. This study provides a controlled comparison of nine architectures (Autoformer, DLinear, iTransformer, LSTM, ModernTCN, N HiTS, PatchTST, TimesNet, and TimeXer) spanning Transformer, MLP, CNN, and RNN families across cryptocurrency, forex, and equity index markets at 4 hour and 24 hour horizons. A total of 918 experiments were conducted under a strict five stage protocol including fixed seed Bayesian hyperparameter optimization, configuration freezing per asset class, multi seed retraining, uncertainty aggregation, and statistical validation. ModernTCN achieves the best mean rank (1.333) with a 75 percent first place rate, followed by PatchTST (2.000). Results reveal a clear three tier ranking structure and show that architecture explains nearly all performance variance, while seed randomness is negligible. Rankings remain stable across horizons despite 2 to 2.5 times error amplification. Directional accuracy remains near 50 percent across all configurations, indicating that MSE trained models lack directional skill at hourly resolution. The findings highlight the importance of architectural inductive bias over raw parameter count and provide reproducible guidance for multi step financial forecasting.

Keywords : 

Abstract :多期价格预测是投资组合分配、风险管理和算法交易的核心，但深度学习架构的激增速度超过了严格的财务基准所能评估的速度。本研究对加密货币、外汇和股票指数市场的Transformer、MLP、CNN和RNN系列的九种架构（Autoformer、DLlinear、iTransformer、LSTM、ModernTCN、N HiTS、PatchTST、TimesNet和TimeXer）进行了4小时和24小时的对照比较。共有918个实验在严格的五阶段协议下进行，包括固定种子贝叶斯超参数优化、按资产类别冻结配置、多种子再训练、不确定性聚合和统计验证。ModernTCN以75%的第一名获得最佳平均排名（1.333），其次是PatchTST（2.000）。结果揭示了一个清晰的三层排名结构，并表明该架构几乎解释了所有的性能差异，而种子随机性可以忽略不计。尽管误差放大了2到2.5倍，但排名在各个范围内保持稳定。在所有配置中，方向精度仍然接近50%，这表明MSE训练的模型缺乏每小时分辨率的方向技能。研究结果强调了架构归纳偏差对原始参数计数的重要性，并为多步财务预测提供了可重复的指导。

Keywords :

### 

\[4\] LR Robot

标题:LR机器人

作者:Wei Wei, Jin Zheng, Zining Wang

来源:ARXIV\_20260319

链接:https://arxiv.org/pdf/2603.17723

Abstract : Recent advances in artificial intelligence (AI) and natural language processing (NLP) have enabled tools to support systematic literature reviews (SLRs), yet existing frameworks often produce outputs that are efficient but contextually limited, requiring substantial expert this http URL framework employs a human in the loop process to define sub SLR tasks, evaluate models, and ensure methodological rigor, while leveraging structured knowledge sources and retrieval augmented generation (RAG) to enhance factual grounding and transparency. LR Robot enables multidimensional categorization of research, maps relationships among papers, identifies high impact works, and supports historical, fine grained analyses of topic evolution. We demonstrate the framework using an option pricing case study, enabling comprehensive literature analysis. Empirical results reveal the current capabilities of AI in understanding and synthesizing literature, uncover emerging trends, reveal topic connections, and highlight core research directions. By accelerating labor intensive review stages while preserving interpretive accuracy, LR Robot provides a practical, customizable, and high quality approach for AI assisted SLRs. Key contributions  (1) a novel framework combining AI and expert supervision for contextually informed SLRs, (2) support for multidimensional categorization, relationship mapping, and fine grained topic evolution analysis, and (3) empirical demonstration of AI driven literature synthesis in the field of option pricing.

Keywords : 

Abstract :人工智能（AI）和自然语言处理（NLP）的最新进展使工具能够支持系统文献综述（SLR），但现有的框架通常会产生高效但上下文有限的输出，需要大量的专家。这种http URL框架采用人工在环过程来定义子SLR任务、评估模型并确保方法的严谨性，同时利用结构化知识源和检索增强生成（RAG）来增强事实基础和透明度。LR Robot能够对研究进行多维分类，绘制论文之间的关系图，识别高影响力的作品，并支持对主题演变的历史、细粒度分析。我们使用期权定价案例研究来演示该框架，从而进行全面的文献分析。实证结果揭示了人工智能在理解和综合文献方面的当前能力，揭示了新兴趋势，揭示了主题联系，并突出了核心研究方向。通过加快劳动密集型审查阶段，同时保持解释准确性，LR Robot为人工智能辅助单反相机提供了一种实用、可定制和高质量的方法。主要贡献：（1）一个结合人工智能和专家监督的新框架，用于情境知情的SLR；（2）支持多维分类、关系映射和细粒度主题演化分析；（3）期权定价领域人工智能驱动的文献综合的实证演示。

Keywords :