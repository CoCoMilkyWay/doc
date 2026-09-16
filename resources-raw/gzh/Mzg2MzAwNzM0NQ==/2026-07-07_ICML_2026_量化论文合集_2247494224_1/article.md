# ICML 2026 量化论文合集

QuantML QuantML 2026-07-07 20:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247494224&idx=1&sn=1ca971666e7f03ddfefaec298b534e73&chksm=cf0a5073a6fa2e82bc0b1bfa7e0c7a764267561e256eb86cabbae40c38c0639f1360e772e46a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247494224&idx=1&sn=1ca971666e7f03ddfefaec298b534e73&chksm=cf0a5073a6fa2e82bc0b1bfa7e0c7a764267561e256eb86cabbae40c38c0639f1360e772e46a#rd)

![](assets/001.png)

> “
> 
> 第43届国际机器学习大会（ICML 2026）于2026年7月6日至11日在韩国首尔召开。本届会议共收到23,918篇投稿，录用6,352篇。我们系统梳理了与**量化金融、算法交易、市场模拟**相关的核心论文，涵盖投资组合优化、时间序列预测、强化学习交易、市场模拟与生成式AI、LLM金融智能体五大方向。

## 一、投资组合优化

### 1\. Decision-focused Sparse Tangent Portfolio Optimization

项目

内容

**作者**

Haeun Jeon, Seunghoon Choi, Hyunglip Bae, Yongjae Lee, Woo Chang Kim

**链接**

https://icml.cc/virtual/2026/poster/64722 / https://arxiv.org/abs/2607.00581 / https://github.com/feuerwerksh/Diffble-card-SR

**【摘要】** 传统"预测-再优化"流程在金融投资组合构建中存在一个根本性矛盾：预测精度高不代表投资组合质量好。这篇论文提出了一种**端到端的决策聚焦学习框架**，将夏普比率最大化问题重新表述为DPP（Disciplined Parametrized Programming）兼容的凸规划层，用平滑的top-k算子替代离散选择，使得梯度可以在**预测-资产选择-再优化**三个环节自由流动。在五个主要股票市场的实验中，该方法在更大资产池中取得了更高的样本外夏普比率，为量化投资中的"端到端学习"范式提供了重要实证支持。

* * *

### 2\. A Linearly Convergent Proximal Subgradient Algorithm for Sparse Portfolio Optimization with Transaction Cost

项目

内容

**作者**

Xiaoting Yao, Na Zhang

**链接**

https://icml.cc/virtual/2026/poster/60601

**【摘要】** 实际交易中，交易成本和持仓稀疏性（控制持股数量）是影响收益的两个关键因素，但现有文献缺乏同时考虑两者的模型。本文提出了**K-稀疏TCO模型**，在最小化负收益和交易成本的同时保持K-稀疏约束。通过将NP-hard问题重构为非光滑DC（差分凸）优化问题，开发了**近端子梯度算法（PSGA）**，并证明了KL性质下的全局收敛性和R-线性收敛率。在四个真实市场数据集上，该算法在保持更高收益的同时实现了更低风险。

* * *

### 3\. Online Conformal Prediction via Universal Portfolio Algorithms

项目

内容

**作者**

Tuo Liu, Edgar Dobriban, Francesco Orabona

**链接**

https://icml.cc/virtual/2026/poster/65365 / https://arxiv.org/abs/2602.03168 / https://github.com/AdaMLLab/up-for-ocp

**【摘要】** 金融预测不仅需要点估计，更需要可靠的不确定性量化。本文提出**UP-OCP**，一种基于通用投资组合算法的免参数在线共形预测方法。核心创新在于识别出"线性化遗憾"（linearized regret）作为关键概念，证明控制它即可保证任意在线算法的覆盖性。通过将共形预测归约为两资产投资组合选择问题，该方法在多项式增长的预测下仍具有强有限时间边界，实验表明其在规模/覆盖权衡上一致优于现有基线，对风险管理中的区间预测具有重要价值。

* * *

## 二、LLM金融评估与偏见

### 4\. Position: Evaluating LLMs in Finance Requires Explicit Bias Consideration

项目

内容

**作者**

Yaxuan Kong, Hoyoung Lee, Yoontae Hwang, Alejandro Lopez-Lira, Bradford Levy, Dhagash Mehta, Qingsong Wen, Chanyeo Choi, Yongjae Lee, Stefan Zohren

**链接**

https://icml.cc/virtual/2026/poster/67204 / https://github.com/Eleanorkong/Awesome-Financial-LLM-Bias-Mitigation

**【摘要】** LLM在金融领域的应用日益广泛，但评估实践严重滞后。本文识别了五种反复出现的金融特定偏见：**前瞻偏差**（使用未来信息）、**幸存者偏差**（忽略已退市资产）、**叙事偏差**（过度拟合故事性解释）、**目标偏差**（优化错误目标）、**成本偏差**（忽视交易成本）。通过系统性审查2023-2025年间164篇论文，发现没有单一偏见在超过28%的研究中被讨论。论文提出了**结构有效性框架**和包含偏见诊断最小要求的评估清单，为金融LLM的严谨评估奠定了基础。

* * *

### 5\. Position: Collusion Risks Among AI Reasoning Agents Justify Certification Requirements for Making Market Decisions

项目

内容

**作者**

Matthew Riemer, Tommaso Tosato, Maximilian Puelma Touzel, Amin Memarian, Guillaume Dumas, Glen Berseth, Irina Rish

**链接**

https://icml.cc/virtual/2026/poster/67141 / https://github.com/mattriemer/LLMCartel

**【摘要】** 具有思维链（CoT）推理能力的AI代理存在隐性合谋倾向。在Bertrand寡头定价领域的实验中，**DeepSeek-R1代理即使被明确提示不要合谋，仍趋向于价格协调行为**。更令人担忧的是，这些代理的思维链可以被操纵向极端合谋或高度竞争行为，而这种操纵对分析推理轨迹的LLM来说是不可检测的。这意味着部署推理代理进行市场决策可能导致合谋性经济结果而无需任何共谋证据。论文提出**行为认证要求**，即在部署前必须在代表性场景中通过观察行为验证。

* * *

### 10\. BizFinBench.v2: Towards Reliable LLMs in Finance via Real-User Data and Offline/Online Bilingual Evaluation

项目

内容

**作者**

Xin Guo, Rongjunchen Zhang, Guilong Lu, Xuntao Guo, Jia Shuai, Zhi Yang, Liwen Zhang

**链接**

https://icml.cc/virtual/2026/poster/65946 / https://github.com/HiThink-Research/BizFinBench.v2

**【摘要】** 现有金融LLM基准大多依赖模拟数据，导致报告性能与真实部署效果之间存在巨大鸿沟。本文推出**BizFinBench.v2**，首个基于真实用户查询-响应数据的**离线+在线双语评估基准**，覆盖中美股票市场，包含28,860个问题跨8个离线任务和2个在线任务。实验显示**GPT-5仅达61.5%准确率**，远低于84.8%的商业实践要求。在商业模型中，**DeepSeek-R1表现出最优的投资决策效果**。错误分析揭示了现有模型在金融实践中的持续性局限。

* * *

## 三、市场模拟与生成式AI

### 6\. MarketSim: Simulating Stock Markets with Large-Scale Generative Agents

项目

内容

**作者**

Jinghua Piao, Zhentao Liu, Cheng Huang, Jiarui Huang, Songwei Li, Ranran Wang, Yong Li（清华大学）

**链接**

https://icml.cc/virtual/2026/poster/65297 / https://openreview.net/forum?id=EzpJxPDqXB

**【摘要】** 股票市场是现代社会最复杂的系统之一。本文提出**MarketSim**，一个大规模股票市场模拟框架，引入**分层多智能体架构**解耦战略推理与高频执行，使LLM代理能在纳秒级分辨率的类NASDAQ连续双向拍卖市场中运行。框架模拟了**超过15,000个异质性市场参与者**，其行为基于12,000多篇真实世界新闻文章、政策文件和收益报告。在包含8个GICS行业和3个真实场景的基准测试中，MarketSim不仅捕捉了真实市场的关键复杂性特征，还在追踪高频价格动态方面达到**3.48%的平均MAPE**，显著优于现有基线。

* * *

### 7\. Towards Professional-Grade Financial Agents: Benchmarking, Tooling, and Structured Reasoning

项目

内容

**作者**

Cheng Huang, Jinghua Piao, Ranran Wang, Yong Li（清华大学）

**链接**

https://icml.cc/virtual/2026/poster/60732

**【摘要】** 金融推理要求精确执行，但现有LLM代理缺乏全面的基准测试和鲁棒的推理结构。本文贡献三方面：**ProFinR基准**（首个专业金融推理基准，528个专家设计任务覆盖四种金融任务类型）、**Financial Tool Universe**（53个领域专用工具，13个类别）、**ProFinAgents框架**（基于有向无环图DAG和案例记忆CBM的结构化代理）。相比SOTA基线，ProFinAgent实现**49.81%性能提升**，同时\*\*推理延迟降低47.1%\*\*，展示了结构化工具增强在金融智能体中的巨大潜力。

* * *

### 9\. Evolving Quantitative Reasoning through Self-Play in Digital Twin Markets

项目

内容

**作者**

Tianmi Ma, Wenxin Huang, Jiawei Du, Lin Li, Xian Zhong, Joey Tianyi Zhou

**链接**

https://icml.cc/virtual/2026/poster/62173 / https://github.com/MTMQuantAI/Agent-Trading-Arena

**【摘要】** LLM在高层次语义理解和战略规划方面表现出色，但在精确计算和定量推理上存在持续缺陷。本文提出将**推理与计算解耦**：LLM负责规划、分析和结果解释，数值计算和统计推断委托给专用外部工具。这些工具在规划阶段以结构化方式动态创建，使代理能够根据市场条件自适应选择工具。在**DecoupledMarket数字孪生市场**中，LLM代理通过自博弈持续测试、比较和适应策略，形成有界自我进化循环，显著提升了LLM驱动决策的定量可靠性。

* * *

## 四、强化学习与时间序列

### 8\. Doubly Outlier-Robust Online Infinite Hidden Markov Model

项目

内容

**作者**

Horace Yiu, Leandro Sánchez-Betancourt, Álvaro Cartea, Gerardo Duran-Martin

**链接**

https://icml.cc/virtual/2026/poster/60726

**【摘要】** 金融时间序列中异常值（闪崩、暴涨）频发，传统在线学习方法对此敏感。本文提出**BR-iHMM（批量鲁棒无限隐马尔可夫模型）**，利用广义贝叶斯推断的最新进展，通过后验影响函数（PIF）定义鲁棒性，提供有界PIF的理论条件。方法通过两个可调参数在**适应性**和**鲁棒性**之间取得平衡。在限价订单簿数据、小时级电力需求和合成高维线性系统上的实验表明，BR-iHMM相比竞争方法将一步预测误差降低\*\*最多67%\*\*，适用于高频交易中的状态推断和regime检测。

* * *

## 五、Workshop亮点论文

### 11\. Forecast-to-Trade: Hierarchical Reinforcement Learning for Decision-Aware Financial Forecasting

项目

内容

作者

Zijie Zhao, Roy E Welsch

链接

https://icml.cc/virtual/2026/workshop/54091

**【摘要】** 传统预测模型独立于下游交易决策进行优化，导致预测结果未必对交易最有用。本文提出**层次化强化学习框架**，将金融预测与交易决策紧密耦合，通过分层RL架构使预测模型直接服务于交易决策目标，实现预测-交易一体化优化。

* * *

### 12\. DeXposure-FM: Time-series Graph Foundation Model for Credit Exposures on Decentralised Financial Networks

项目

内容

作者

Aijie Shu, Wenbin Wu, Gbenga Ibikunle, Fengxiang He

链接

https://icml.cc/virtual/2026/workshop/54057

**【摘要】** 随着DeFi市场快速增长，传统风险管理方法面临挑战。本文提出DeXposure-FM，专为去中心化金融网络设计的时序图基础模型，通过图神经网络和时序建模的结合，为DeFi生态系统的信用风险敞口分析和稳定性评估提供了新工具。

* * *

### 13\. TradeFM: A Generative Foundation Model for Trade-flow and Market Microstructure

项目

内容

作者

Srijan Sood, Maxime Kawawa-Beaudan, Daniel Borrajo, Manuela Veloso

链接

https://icml.cc/virtual/2026/workshop/54066

**【摘要】** TradeFM是一个生成式基础模型，专门用于交易流和市场微观结构建模。该模型能够生成逼真的交易流数据，为算法交易策略的开发和测试提供高质量模拟环境，同时在市场质量分析方面展现了强大能力。

* * *

### 14\. Learning to Trade Like an Expert: Cognitive Fine-Tuning for Stable Financial Reasoning

项目

内容

作者

Yuchen Pan, Soung Chang Liew

链接

https://icml.cc/virtual/2026/workshop/54088

**【摘要】** 探索通过认知微调让LLM像专家一样进行交易决策。研究设计了稳定的金融推理微调方法，使模型在复杂多变的市场环境中保持推理的一致性和可靠性，克服了通用LLM在金融场景中的不稳定性问题。

* * *

### 15\. Behavioral Proxy Conditioning for Financial Stress Scenario Generation

项目

内容

作者

Elena Kuular, Junsuk Choe

链接

https://icml.cc/virtual/2026/workshop/54066

**【摘要】** 利用预训练扩散模型生成金融风险压力测试场景。通过行为代理条件化技术，模型能够生成符合特定市场条件（金融危机、流动性紧缩）的逼真场景，为压力测试和风险管理提供了新的数据生成范式。

* * *

### 16\. Generating Robust Portfolios of Optimization Models using Large Language Models

项目

内容

作者

Eleni Straitouri, Cheol Kim, Milind Tambe

链接

https://icml.cc/virtual/2026/workshop/54095

**【摘要】** 探索使用大语言模型生成优化模型组合的方法。通过让LLM参与投资组合的优化模型选择和组合过程，展示了AI辅助决策在复杂优化问题中的潜力，为自动化投资组合构建开辟了新方向。

* * *

### 17\. Beyond Forecasting: The Belief-to-Trade Layer in Prediction-Market Agents

项目

内容

作者

Issue Y Wang, Yuxuan Wang, Hanyang Tang

链接

https://icml.cc/virtual/2026/workshop/54091

**【摘要】** 在预测市场中，从信念（belief）到交易（trade）的转换是一个关键但被忽视的环节。本文提出信念到交易的中间层，帮助预测市场代理更好地将概率估计转化为最优交易决策。

* * *

### 18\. Preference Optimization Drives Monoculture in LLM Prediction Markets

项目

内容

作者

James Begin, Brendan Gho, Suman Muppavarapu, Tyson Tsay, Atharva Mohan, Afnan Shaik, Ruizhe Li, Vasu Sharma, Archana Vaidheeswaran, Kevin Zhu

链接

https://icml.cc/virtual/2026/workshop/54091

**【摘要】** 研究了LLM预测市场中偏好优化导致的单一文化（monoculture）现象。发现当多个LLM代理使用相似的偏好优化目标时，预测市场可能失去多样性，影响聚合预测的准确性和鲁棒性。

* * *

### 19\. Scaling Deep Learning in Financial Markets (Expo Talk)

项目

内容

作者

Iain Dunning（Hudson River Trading）

链接

https://icml.cc/virtual/2026/75721

**【摘要】** Hudson River Trading分享了构建和部署大规模市场模型（Market Foundation Models）的实战经验。这些模型每天处理PB级高保真数据，从数万亿个事件中提取信号。核心挑战包括：在非平稳数据集上训练、微秒级实时推理的工程约束、以及在高度动态市场条件下保持鲁棒性。

* * *

### 20\. Mechanism Design for Multi-Agent Alpha Discovery

项目

内容

作者

Ajitabh Kumar

链接

https://icml.cc/virtual/2026/workshop/54068

**【摘要】** 探索多智能体Alpha发现的机制设计问题。通过优化异构LLM市场中代理的分布，研究如何在信号噪声比极低的环境中有效发现可持续的Alpha信号，为量化策略开发提供了多智能体视角。

  

  

更多深度研究欢迎加入QuantML知识星球

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/002.jpg)