# 量化前沿速递：机器学习\[20260412\]

shameless 量化前沿速递 2026-04-13 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489489&idx=4&sn=a9ca0a32146751a72855203c52e02ce3&chksm=c3153c86f0d581882b4d4a5247f2d8b5ac8f72c41760a0bf84f8cba870a82cfd0b71e5bbc843#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489489&idx=4&sn=a9ca0a32146751a72855203c52e02ce3&chksm=c3153c86f0d581882b4d4a5247f2d8b5ac8f72c41760a0bf84f8cba870a82cfd0b71e5bbc843#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Anticipatory Reinforcement Learning

预期强化学习

来源:ARXIV\_20260407

\[2\] Effect of Cigarette Price and Tax Increases on Smoking in Europe

欧洲卷烟价格和税收上涨对吸烟的影响

来源:ARXIV\_20260408

\[3\] Quantum Computing for Financial Transformation

金融转型的量子计算

来源:ARXIV\_20260410

### 

\[1\] Anticipatory Reinforcement Learning

标题:预期强化学习

作者:Daniel Bloch

来源:ARXIV\_20260407

链接:https://arxiv.org/pdf/2604.04662

Abstract : This paper introduces Anticipatory Reinforcement Learning (ARL), a novel framework designed to bridge the gap between non Markovian decision processes and classical reinforcement learning architectures, specifically under the constraint of a single observed trajectory. In environments characterised by jump diffusions and structural breaks, traditional state based methods often fail to capture the essential path dependent geometry required for accurate foresight. We resolve this by lifting the state space into a signature augmented manifold, where the history of the process is embedded as a dynamical coordinate. By utilising a self consistent field approach, the agent maintains an anticipated proxy of the future path law, allowing for a deterministic evaluation of expected returns. This transition from stochastic branching to a single pass linear evaluation significantly reduces computational complexity and variance. We prove that this framework preserves fundamental contraction properties and ensures stable generalisation even in the presence of heavy tailed noise. Our results demonstrate that by grounding reinforcement learning in the topological features of path space, agents can achieve proactive risk management and superior policy stability in highly volatile, continuous time environments.

Keywords : 

Abstract :本文介绍了预期强化学习（ARL），这是一种新的框架，旨在弥合非马尔可夫决策过程和经典强化学习架构之间的差距，特别是在单个观察轨迹的约束下。在以跳跃扩散和结构断裂为特征的环境中，传统的基于状态的方法往往无法捕捉到准确预测所需的基本路径相关几何。我们通过将状态空间提升到签名增广流形中来解决这个问题，在该流形中，过程的历史被嵌入为动态坐标。通过使用自洽场方法，代理维护了未来路径定律的预期代理，从而可以对预期回报进行确定性评估。从随机分支到单程线性评估的这种转变显著降低了计算复杂度和方差。我们证明，即使在存在重尾噪声的情况下，该框架也能保持基本的收缩特性，并确保稳定的泛化。我们的结果表明，通过将强化学习建立在路径空间的拓扑特征中，代理可以在高度不稳定、连续时间的环境中实现主动风险管理和卓越的策略稳定性。

Keywords :

### 

\[2\] Effect of Cigarette Price and Tax Increases on Smoking in Europe

标题:欧洲卷烟价格和税收上涨对吸烟的影响

作者:Andreas Stoller, Martin Huber

来源:ARXIV\_20260408

链接:https://arxiv.org/pdf/2604.05841

Abstract : We estimate the effect of cigarette price and tax increases on smoking rates using Eurobarometer survey data from 27 European Union countries between 2012 and 2020. Following a difference in differences approach, we compare individuals exposed to large price and tax increases with those in stable price and tax environments. Estimation is based on a difference in differences estimator with double machine learning, which relaxes the functional form assumptions typically imposed by parametric approaches such as two way fixed effects. Our results indicate that tax increases reduce smoking rates among individuals who smoke at least once per month and among daily smokers. The reduction is primarily driven by individuals aged 15 24. We examine the sensitivity of our findings to functional form assumptions and treatment definitions. While estimates are robust to alternative functional form assumptions, they are sensitive to whether the treatment is defined as binary or continuous.

Keywords : 

Abstract :我们使用2012年至2020年期间来自27个欧盟国家的欧洲晴雨表调查数据，估计了卷烟价格和税收增加对吸烟率的影响。我们采用差异分析法，将面临大幅价格和税收上涨的个人与处于稳定价格和税收环境的个人进行比较。估计基于双机器学习的差分估计器，它放宽了参数方法（如双向固定效应）通常强加的函数形式假设。我们的研究结果表明，增税可以降低每月至少吸烟一次的个人和日常吸烟者的吸烟率。这一减少主要是由15至24岁的个人推动的。我们检查了我们的发现对功能形式假设和治疗定义的敏感性。虽然估计对替代函数形式的假设是稳健的，但它们对治疗是定义为二元还是连续很敏感。

Keywords :

### 

\[3\] Quantum Computing for Financial Transformation

标题:金融转型的量子计算

作者:Hui Gong, Akash Sedai, Thomas Schroeder, Francesca Medda

来源:ARXIV\_20260410

链接:https://arxiv.org/pdf/2604.08180

Abstract : Quantum computing is becoming strategically relevant to finance because several core financial bottlenecks are already defined by combinatorial search, expectation estimation, rare event analysis, representation learning, and long horizon cryptographic resilience. This review examines that landscape across five connected domains  constrained portfolio optimisation, derivative pricing, tail risk and scenario estimation, quantum machine learning, and post quantum security. Rather than treating these topics as isolated demonstrations, the article studies them as linked layers of a financial computation stack. Across all five domains, the review applies a common evaluative logic  identify the financial bottleneck, specify the relevant quantum primitive, compare it with an explicit classical benchmark, and assess the result under realistic implementation and governance constraints. The main conclusion is measured but consequential. The strongest near term case for quantum finance lies in carefully designed hybrid workflows rather than blanket claims of universal advantage. Quantum optimisation is most credible when constrained search dominates  amplitude estimation methods matter most when repeated expectation evaluation is the binding cost  quantum machine learning remains task dependent  and post quantum cryptography is already strategically necessary because financial infrastructures must migrate before fault tolerant attacks arrive. By combining system level synthesis with locally reproducible small scale case studies on simulated qubit registers, the article is intended both as a review of the field and as a handbook style entry point for future work.

Keywords : 

Abstract :量子计算正变得与金融具有战略相关性，因为组合搜索、期望估计、罕见事件分析、表示学习和长期密码弹性已经定义了几个核心金融瓶颈。本综述考察了五个相互关联的领域的情况——约束投资组合优化、衍生品定价、尾部风险和情景估计、量子机器学习和后量子安全。本文没有将这些主题视为孤立的演示，而是将它们作为金融计算堆栈的链接层进行研究。在所有五个领域，该审查应用了一种通用的评估逻辑——确定财务瓶颈，指定相关的量子原语，将其与明确的经典基准进行比较，并在现实的实施和治理约束下评估结果。主要结论是可衡量的，但意义重大。量子金融近期最有力的案例在于精心设计的混合工作流程，而不是笼统地宣称普遍优势。当约束搜索占主导地位时，量子优化是最可信的。当重复期望评估是约束成本时，振幅估计方法最重要。量子机器学习仍然依赖于任务，后量子密码学在战略上已经是必要的，因为金融基础设施必须在容错攻击到来之前迁移。通过将系统级综合与模拟量子比特寄存器的本地可重复小规模案例研究相结合，本文旨在既是对该领域的回顾，也是未来工作的手册式切入点。

Keywords :