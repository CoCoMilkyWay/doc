# 量化前沿速递：机器学习\[20260329\]

shameless 量化前沿速递 2026-03-30 12:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489469&idx=4&sn=d5d5cba38ddeb70da75a378f11996fe8&chksm=c3e1dc42e4141618a921f4f3fc8eb007e73a195da6b4401f391f0481707a43491dd234cb591b#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489469&idx=4&sn=d5d5cba38ddeb70da75a378f11996fe8&chksm=c3e1dc42e4141618a921f4f3fc8eb007e73a195da6b4401f391f0481707a43491dd234cb591b#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] FinRL X

FinRL X

来源:ARXIV\_20260324

\[2\] AI Driven Multi Agent Simulation of Stratified Polyamory Systems

人工智能驱动的多智能体分层多态系统仿真

来源:ARXIV\_20260324

\[3\] Portfolio Optimization under Recursive Utility via Reinforcement Learning

基于强化学习的递归效用下的投资组合优化

来源:ARXIV\_20260325

\[4\] Adapting Altman s bankruptcy prediction model to the compositional data methodology

将Altman的破产预测模型应用于成分数据方法

来源:ARXIV\_20260326

### 

\[1\] FinRL X

标题:FinRL X

作者:Hongyang Yang, Boyu Zhang, Yang She, Xinyu Liao, Xiaoli Zhang

来源:ARXIV\_20260324

链接:https://arxiv.org/pdf/2603.21330

Abstract : We present FinRL X, a modular and deployment consistent trading architecture that unifies data processing, strategy construction, backtesting, and broker execution under a weight centric interface. While existing open source platforms are often backtesting  or model centric, they rarely provide system level consistency between research evaluation and live deployment. FinRL X addresses this gap through a composable strategy pipeline that integrates stock selection, portfolio allocation, timing, and portfolio level risk overlays within a unified protocol. The framework supports both rule based and AI driven components, including reinforcement learning allocators and LLM based sentiment signals, without altering downstream execution semantics. FinRL X provides an extensible foundation for reproducible, end to end quantitative trading research and deployment. The official FinRL X implementation is available at this https URL.

Keywords : 

Abstract :我们介绍了FinRL X，这是一种模块化和部署一致的交易架构，在以权重为中心的界面下统一了数据处理、策略构建、回溯测试和经纪商执行。虽然现有的开源平台通常是回溯测试或以模型为中心的，但它们很少在研究评估和实际部署之间提供系统级的一致性。FinRL X通过一个可组合的策略管道来解决这一差距，该管道将股票选择、投资组合分配、时机和投资组合级风险叠加集成在一个统一的协议中。该框架支持基于规则和人工智能驱动的组件，包括强化学习分配器和基于LLM的情感信号，而不会改变下游执行语义。FinRL X为可重复的、端到端的定量交易研究和部署提供了可扩展的基础。FinRL X的官方实现可以在这个https URL上找到。

Keywords :

### 

\[2\] AI Driven Multi Agent Simulation of Stratified Polyamory Systems

标题:人工智能驱动的多智能体分层多态系统仿真

作者:Yicai Xing

来源:ARXIV\_20260324

链接:https://arxiv.org/pdf/2603.20678

Abstract : Contemporary societies face a severe crisis of demographic reproduction. Global fertility rates continue to decline precipitously, with East Asian nations exhibiting the most dramatic trends    China s total fertility rate (TFR) fell to approximately 1.0 in 2023, while South Korea s dropped below 0.72. Simultaneously, the institution of marriage is undergoing structural disintegration  educated women rationally reject unions lacking both emotional fulfillment and economic security, while a growing proportion of men at the lower end of the socioeconomic spectrum experience chronic sexual deprivation, anxiety, and learned helplessness. This paper proposes a computational framework for modeling and evaluating a Stratified Polyamory System (SPS) using techniques from agent based modeling (ABM), multi agent reinforcement learning (MARL), and large language model (LLM) empowered social simulation. The SPS permits individuals to maintain a limited number of legally recognized secondary partners in addition to one primary spouse, combined with socialized child rearing and inheritance reform. We formalize the A B C stratification as heterogeneous agent types in a multi agent system and model the matching process as a MARL problem amenable to Proximal Policy Optimization (PPO). The mating network is analyzed using graph neural network (GNN) representations. Drawing on evolutionary psychology, behavioral ecology, social stratification theory, computational social science, algorithmic fairness, and institutional economics, we argue that SPS can improve aggregate social welfare in the Pareto sense. Preliminary computational results demonstrate the framework s viability in addressing the dual crisis of female motherhood penalties and male sexlessness, while offering a non violent mechanism for wealth dispersion analogous to the historical Chinese Grace Decree (Tui en Ling).

Keywords : 

Abstract :当代社会面临着严重的人口再生产危机。全球生育率继续急剧下降，东亚国家呈现出最显著的趋势——中国的总生育率在2023年降至约1.0，而韩国则降至0.72以下。与此同时，婚姻制度正在经历结构性解体——受过教育的女性理性地拒绝缺乏情感满足和经济保障的婚姻，而越来越多的社会经济地位较低的男性经历了长期的性剥夺、焦虑和习得性无助。本文提出了一种计算框架，用于使用基于代理的建模（ABM）、多代理强化学习（MARL）和支持大语言模型（LLM）的社会模拟技术对分层多态系统（SPS）进行建模和评估。SPS允许个人除了一个主要配偶外，还可以维持有限数量的法律认可的次要伴侣，并结合社会化的育儿和继承改革。我们将A、B、C分层形式化为多智能体系统中的异构智能体类型，并将匹配过程建模为可接受邻近策略优化（PPO）的MARL问题。使用图神经网络（GNN）表示对交配网络进行分析。基于进化心理学、行为生态学、社会分层理论、计算社会科学、算法公平和制度经济学，我们认为SPS可以改善帕累托意义上的总体社会福利。初步计算结果表明，该框架在解决女性母性惩罚和男性无性恋的双重危机方面是可行的，同时为财富分散提供了一种类似于历史上的《中国恩典法令》的非暴力机制。

Keywords :

### 

\[3\] Portfolio Optimization under Recursive Utility via Reinforcement Learning

标题:基于强化学习的递归效用下的投资组合优化

作者:Minkey Chang

来源:ARXIV\_20260325

链接:https://arxiv.org/pdf/2603.22880

Abstract : We study whether a risk sensitive objective from asset pricing theory    recursive utility    improves reinforcement learning for portfolio allocation. The Bellman equation under recursive utility involves a certainty equivalent (CE) of future value that has no closed form under observed returns  we approximate it by  K  sample Monte Carlo and train actor critic (PPO, A2C) on the resulting value target and an approximate advantage estimate (AAE) that generalizes the Bellman residual to multi step with state dependent weights. This formulation applies only to critic based algorithms. On 10 chronological train test splits of South Korean ETF data, the recursive utility agent improves on the discounted (naive) baseline in Sharpe ratio, max drawdown, and cumulative return. Derivations, world model and metrics, and full result tables are in the appendices.

Keywords : 

Abstract :我们研究了资产定价理论中的风险敏感目标递归效用是否改善了投资组合配置的强化学习。递归效用下的贝尔曼方程涉及未来值的确定性等价物（CE），在观测到的回报下没有封闭形式，我们通过K个样本蒙特卡洛和训练行动者评论家（PPO，A2C）对结果值目标进行近似，并通过近似优势估计（AAE）将贝尔曼残差推广到具有状态相关权重的多步。此公式仅适用于基于评论家的算法。在韩国ETF数据的10个时间序列测试分割中，递归效用代理在夏普比率、最大提款和累积回报方面改善了贴现（天真）基线。推导、世界模型和指标以及完整的结果表见附录。

Keywords :

### 

\[4\] Adapting Altman s bankruptcy prediction model to the compositional data methodology

标题:将Altman的破产预测模型应用于成分数据方法

作者:Fatemeh Keivani (1), Germà Coenders (1), Geòrgia Escaramís (1) ((1) Universitat de Girona)

来源:ARXIV\_20260326

链接:https://arxiv.org/pdf/2603.24215

Abstract : Using standard financial ratios as variables in statistical analyses has been related to several serious problems, such as extreme outliers, asymmetry, non normality, and non linearity. The compositional data methodology has been successfully applied to solve these problems and has always yielded substantially different results when compared to standard financial ratios. An under researched area is the use of financial log ratios computed with the compositional data methodology to predict bankruptcy or the related terms of business default, insolvency or failure. Another under researched area is the use of machine learning methods in combination with compositional log ratios. The present article adapts the classical Altman bankruptcy prediction model and some of its extensions to the compositional methodology with pairwise log ratios and three common statistical and machine learning tools  logistic regression models, k nearest neighbours, and random forests, and compares the results with standard financial ratios. Data from the sector in the Spanish economy with the largest number of bankrupt firms according to the first two digits of the NACE code (46XX  wholesale trade, except of motor vehicles and motorcycles ) were obtained from the Iberian Balance sheet Analysis System. The sample size (31,131 firms, of which 97 were bankrupt) was divided into a training and a validation dataset. The training data set was downsampled to one healthy firm to each bankrupt firm. No outliers were removed. Focusing on predictive performance, the results show that compositional methods are better than standard ratios in terms of sensitivity, with mixed results regarding specificity, compositional random forests and compositional logistic regression behaving the best.

Keywords : 

Abstract :在统计分析中使用标准财务比率作为变量与几个严重问题有关，如极端异常值、不对称性、非正态性和非线性。组合数据方法已成功应用于解决这些问题，与标准财务比率相比，其结果总是大不相同。一个研究不足的领域是使用组合数据方法计算的财务对数比率来预测破产或相关的商业违约、资不抵债或失败条款。另一个研究不足的领域是结合组合对数比率使用机器学习方法。本文将经典的Altman破产预测模型及其一些扩展应用于具有成对对数比率和三种常见统计和机器学习工具逻辑回归模型、k近邻和随机森林的组合方法，并将结果与标准财务比率进行比较。根据NACE代码的前两位数字，西班牙经济中破产公司数量最多的部门（46XX批发贸易，机动车和摩托车除外）的数据来自伊比利亚资产负债表分析系统。样本量（31131家公司，其中97家破产）分为训练数据集和验证数据集。训练数据集被下采样到每一家破产公司对应一家健康公司。没有删除异常值。关注预测性能，结果表明，组合方法在灵敏度方面优于标准比率，在特异性、组合随机森林和组合逻辑回归方面的结果喜忧参半。

Keywords :