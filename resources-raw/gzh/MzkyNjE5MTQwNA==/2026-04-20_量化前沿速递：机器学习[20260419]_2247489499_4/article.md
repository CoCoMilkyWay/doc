# 量化前沿速递：机器学习\[20260419\]

量化前沿速递 2026-04-20 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489499&idx=4&sn=4b9d806862a006e13667e68bd568b18d&chksm=c3273453d68d29227616696477b80f34787c361d2a1f5858a3a359c2c4c91d51fa0fd7ae3302#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489499&idx=4&sn=4b9d806862a006e13667e68bd568b18d&chksm=c3273453d68d29227616696477b80f34787c361d2a1f5858a3a359c2c4c91d51fa0fd7ae3302#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Dynamic Forecasting and Temporal Feature Evolution of Stock Repurchases in Listed Companies Using Attention Based Deep Temporal Networks

基于注意力的深度时间网络对上市公司股票回购的动态预测和时间特征演化

来源:ARXIV\_20260414

\[2\] AI Patents in the United States and China

美国和中国的人工智能专利

来源:ARXIV\_20260414

\[3\] Unveiling contrasting impacts of heat mitigation and adaptation policies on U.S. internal migration

揭示热缓解和适应政策对美国国内移民的对比影响

来源:ARXIV\_20260414

\[4\] Instructing LLMs to Negotiate using Reinforcement Learning with Verifiable Rewards

指导LLM使用具有可验证奖励的强化学习进行谈判

来源:ARXIV\_20260414

\[5\] OOM RL

房间RL

来源:ARXIV\_20260414

\[6\] A Comparative Study of Dynamic Programming and Reinforcement Learning in Finite Horizon Dynamic Pricing

有限时域动态定价中动态规划与强化学习的比较研究

来源:ARXIV\_20260416

### 

\[1\] Dynamic Forecasting and Temporal Feature Evolution of Stock Repurchases in Listed Companies Using Attention Based Deep Temporal Networks

标题:基于注意力的深度时间网络对上市公司股票回购的动态预测和时间特征演化

作者:Xiang Ao, Jingxuan Zhang, Xinyu Zhao

来源:ARXIV\_20260414

链接:https://arxiv.org/pdf/2604.09650

Abstract : Accurately predicting stock repurchases is crucial for quantitative investment and risk management, yet traditional static models fail to capture the complex temporal dependencies of corporate financial conditions. This paper proposes a dynamic early warning system integrating economic theory with deep temporal networks. Using Chinese A share panel data (2014 2024), we employ a hybrid Temporal Convolutional Network (TCN) and Attention based LSTM to capture long  and short term financial evolutionary patterns. Rolling window cross validation demonstrates our model significantly outperforms static baselines like Logistic Regression and XGBoost. Furthermore, utilizing Explainable AI (XAI), we reveal the temporal dynamics of repurchase decisions  prolonged  undervaluation  serves as the long term underlying motive, while a sharp increase in  cash flow  acts as the decisive short term trigger. This study provides a robust deep learning paradigm for financial forecasting and offers dynamic empirical support for classic corporate finance hypotheses.

Keywords : 

Abstract :准确预测股票回购对于定量投资和风险管理至关重要，但传统的静态模型无法捕捉到企业财务状况的复杂时间依赖关系。本文提出了一种将经济理论与深度时间网络相结合的动态预警系统。利用中国A股面板数据（2014-2024），我们采用混合时间卷积网络（TCN）和基于注意力的LSTM来捕捉长期和短期的金融演化模式。滚动窗口交叉验证表明，我们的模型明显优于逻辑回归和XGBoost等静态基线。此外，利用可解释人工智能（XAI），我们揭示了回购决策的时间动态——长期低估是长期潜在动机，而现金流的急剧增加是决定性的短期触发因素。本研究为财务预测提供了一个强大的深度学习范式，并为经典的公司财务假设提供了动态的实证支持。

Keywords :

### 

\[2\] AI Patents in the United States and China

标题:美国和中国的人工智能专利

作者:Hanming Fang, Xian Gu, Hanyin Yan, Wu Zhu

来源:ARXIV\_20260414

链接:https://arxiv.org/pdf/2604.10529

Abstract : We develop a high precision classifier to measure artificial intelligence (AI) patents by fine tuning PatentSBERTa on manually labeled data from the USPTO s AI Patent Dataset. Our classifier substantially improves the existing USPTO approach, achieving 97.0  precision, 91.3  recall, and a 94.0  F1 score, and it generalizes well to Chinese patents based on citation and lexical validation. Applying it to granted U.S. patents (1976 2023) and Chinese patents (2010 2023), we document rapid growth in AI patenting in both countries and broad convergence in AI patenting intensity and subfield composition, even as China surpasses the United States in recent annual patent counts. The organization of AI innovation nevertheless differs sharply  U.S. AI patenting is concentrated among large private incumbents and established hubs, whereas Chinese AI patenting is more geographically diffuse and institutionally diverse, with larger roles for universities and state owned enterprises. For listed firms, AI patents command a robust market value premium in both countries. Cross border citations show continued technological interdependence rather than decoupling, with Chinese AI inventors relying more heavily on U.S. frontier knowledge than vice versa.

Keywords : 

Abstract :我们开发了一种高精度分类器，通过对美国专利商标局人工智能专利数据集中的手动标记数据进行微调PatentSBERTa来衡量人工智能（AI）专利。我们的分类器大大改进了现有的USPTO方法，达到了97.0的准确率、91.3的召回率和94.0的F1分数，并且基于引用和词汇验证，它很好地推广到了中国专利。将其应用于已授予的美国专利（1976-2023）和中国专利（2010-2023），我们记录了这两个国家人工智能专利的快速增长，以及人工智能专利强度和子领域构成的广泛趋同，尽管中国在最近的年度专利数量上超过了美国。然而，人工智能创新的组织方式却截然不同。美国的人工智能专利集中在大型私营企业和成熟的中心，而中国的人工智能申请在地理上更加分散，制度上更加多样化，大学和国有企业的作用更大。对于上市公司来说，人工智能专利在这两个国家都具有强劲的市场价值溢价。跨境引用显示，中国的人工智能发明者在技术上继续相互依存，而不是脱钩，他们更依赖美国的前沿知识，反之亦然。

Keywords :

### 

\[3\] Unveiling contrasting impacts of heat mitigation and adaptation policies on U.S. internal migration

标题:揭示热缓解和适应政策对美国国内移民的对比影响

作者:Chao Li, Xing Su, Chao Fan, Yang Li, Luping Li, Chunmo Zheng, Wenglong Chao, Leena Jarvi, Han Lin, Juan Tu

来源:ARXIV\_20260414

链接:https://arxiv.org/pdf/2604.10570

Abstract : While climate induced population migration has received rising attention, the role played by human climate endeavors remains underexplored. Here, we combine machine learning with attribution mapping to analyze the impacts of 4,713 heat related policies (HPs) on 11,177 migration flows between U.S. counties. We find that heat adaptation policies (APs) and heat mitigation policies (MPs) have significant and opposing impacts on internal migration  APs reduce out migration, while MPs increase it. These policies have heterogeneous effects on migration among policy types. Behavioral and cultural MPs at origins lead to a 0.24  0.68  (95  confidence interval) increase in annual outflows per policy, whereas behavioral and cultural APs at destinations elevate outflows of origins by 0.11  1.55  (95  confidence interval). Migration patterns are nonlinearly moderated by income, ageing, education, and racial diversity of both origin and destination counties. Ageing rates have the most noticeable U shaped relationship in shaping migration responses to behavioral and cultural MPs at origins, and inverted U shapes for institutional MPs at origins and nature based MPs at destinations. These findings offer critical insights for policymakers on how HPs influence migration as global warming and policy interventions persist.

Keywords : 

Abstract :虽然气候引起的人口迁移越来越受到关注，但人类气候努力所发挥的作用仍未得到充分探索。在这里，我们将机器学习与归因映射相结合，分析了4713项与热相关的政策（HP）对美国各县之间11177次移民流动的影响。我们发现，热适应政策（AP）和热缓解政策（MP）对内部移民有显著且相反的影响。AP减少了向外移民，而MP增加了向外移民。这些政策对不同政策类型的移民有不同的影响。出发地的行为和文化MP导致每份保单的年度流出量增加0.24 0.68（95置信区间），而目的地的行为与文化AP使出发地的流出量增加0.11 1.55（95置信间隔）。移民模式受到收入、老龄化、教育以及原籍国和目的地国种族多样性的非线性调节。老龄化率在塑造移民对原籍地行为和文化议员的反应方面具有最明显的U形关系，在原籍地机构议员和目的地自然议员方面具有倒U形关系。这些发现为政策制定者提供了关键的见解，即随着全球变暖和政策干预的持续，HPs如何影响移民。

Keywords :

### 

\[4\] Instructing LLMs to Negotiate using Reinforcement Learning with Verifiable Rewards

标题:指导LLM使用具有可验证奖励的强化学习进行谈判

作者:Shuze Daniel Liu, Claire Chen, Jiabao Sean Xiao, Lei Lei, Yuheng Zhang, Yisong Yue, David Simchi-Levi

来源:ARXIV\_20260414

链接:https://arxiv.org/pdf/2604.09855

Abstract : The recent advancement of Large Language Models (LLMs) has established their potential as autonomous interactive agents. However, they often struggle in strategic games of incomplete information, such as bilateral price negotiation. In this paper, we investigate if Reinforcement Learning from Verifiable Rewards (RLVR) can effectively teach LLMs to negotiate. Specifically, we explore the strategic behaviors that emerge during the learning process. We introduce a framework that trains a mid sized buyer agent against a regulated LLM seller across a wide distribution of real world products. By grounding reward signals directly in the maximization of economic surplus and strict adherence to private budget constraints, we reveal a novel four phase strategic evolution. The agent progresses from naive bargaining to using aggressive starting prices, moves through a phase of deadlock, and ultimately develops sophisticated persuasive skills. Our results demonstrate that this verifiable training allows a 30B agent to significantly outperform frontier models over ten times its size in extracting surplus. Furthermore, the trained agent generalizes robustly to stronger counterparties unseen during training and remains effective even when facing hostile, adversarial seller personas.

Keywords : 

Abstract :大型语言模型（LLMs）的最新进展已经确立了它们作为自主交互代理的潜力。然而，他们经常在不完全信息的战略博弈中挣扎，如双边价格谈判。本文研究了可验证奖励强化学习（RLVR）是否可以有效地教会LLM进行谈判。具体而言，我们探讨了学习过程中出现的战略行为。我们引入了一个框架，在广泛分布的现实世界产品中，针对受监管的LLM卖家培训中型买家代理。通过将奖励信号直接建立在经济盈余最大化和严格遵守私人预算约束的基础上，我们揭示了一种新的四阶段战略演变。代理人从天真的讨价还价发展到使用激进的起始价格，经历一个僵局阶段，最终发展出复杂的说服技巧。我们的结果表明，这种可验证的训练使30B代理在提取盈余方面明显优于其大小的十倍以上的前沿模型。此外，经过训练的代理能够稳健地泛化到训练中看不到的更强的对手，即使在面对敌对、对抗性的卖家角色时也能保持有效。

Keywords :

### 

\[5\] OOM RL

标题:房间RL

作者:Kun Liu, Liqun Chen

来源:ARXIV\_20260414

链接:https://arxiv.org/pdf/2604.11477

Abstract : The alignment of Multi Agent Systems (MAS) for autonomous software engineering is constrained by evaluator epistemic uncertainty. Current paradigms, such as Reinforcement Learning from Human Feedback (RLHF) and AI Feedback (RLAIF), frequently induce model sycophancy, while execution based environments suffer from adversarial  Test Evasion  by unconstrained agents. In this paper, we introduce an objective alignment paradigm   textbf Out of Money Reinforcement Learning (OOM RL) . By deploying agents into the non stationary, high friction reality of live financial markets, we utilize critical capital depletion as an un hackable negative gradient. Our longitudinal 20 month empirical study (July 2024    February 2026) chronicles the system s evolution from a high turnover, sycophantic baseline to a robust, liquidity aware architecture. We demonstrate that the undeniable ontological consequences of financial loss forced the MAS to abandon overfitted hallucinations in favor of the  textbf Strict Test Driven Agentic Workflow (STDAW) , which enforces a Byzantine inspired uni directional state lock (RO Lock) anchored to a deterministically verified   geq 95    code coverage constraint matrix. Our results show that while early iterations suffered severe execution decay, the final OOM RL aligned system achieved a stable equilibrium with an annualized Sharpe ratio of 2.06 in its mature phase. We conclude that substituting subjective human preference with rigorous economic penalties provides a robust methodology for aligning autonomous agents in high stakes, real world environments, laying the groundwork for generalized paradigms where computational billing acts as an objective physical constraint

Keywords : 

Abstract :自主软件工程中多智能体系统（MAS）的对齐受到评估者认知不确定性的约束。当前的范式，如基于人类反馈的强化学习（RLHF）和人工智能反馈（RLAIF），经常导致模型阿谀奉承，而基于执行的环境则受到无约束代理的对抗性测试规避的影响。在这篇论文中，我们介绍了一种客观对齐范式textbf，即资金不足强化学习（OOM RL）。通过将代理部署到实时金融市场的非平稳、高摩擦现实中，我们利用临界资本耗尽作为不可破解的负梯度。我们为期20个月的纵向实证研究（2024年7月至2026年2月）记录了该系统从高周转率、阿谀奉承的基线到稳健、流动性感知的架构的演变。我们证明，财务损失的不可否认的本体论后果迫使MAS放弃过度拟合的幻觉，转而支持textbf严格测试驱动代理工作流（STDAW），该工作流强制执行拜占庭式的单向状态锁（RO lock），该状态锁锚定在经过确定性验证的geq 95代码覆盖约束矩阵上。我们的结果表明，虽然早期迭代遭受了严重的执行衰减，但最终的OOM RL对齐系统在成熟阶段实现了稳定的平衡，年化夏普比率为2.06。我们得出结论，用严格的经济惩罚代替主观的人类偏好，为在高风险的现实世界环境中协调自主代理提供了一种稳健的方法，为计算计费作为客观物理约束的广义范式奠定了基础

Keywords :

### 

\[6\] A Comparative Study of Dynamic Programming and Reinforcement Learning in Finite Horizon Dynamic Pricing

标题:有限时域动态定价中动态规划与强化学习的比较研究

作者:Lev Razumovskiy, Nikolay Karenin

来源:ARXIV\_20260416

链接:https://arxiv.org/pdf/2604.14059

Abstract : This paper provides a systematic comparison between Fitted Dynamic Programming (DP), where demand is estimated from data, and Reinforcement Learning (RL) methods in finite horizon dynamic pricing problems. We analyze their performance across environments of increasing structural complexity, ranging from a single typology benchmark to multi typology settings with heterogeneous demand and inter temporal revenue constraints. Unlike simplified comparisons that restrict DP to low dimensional settings, we apply dynamic programming in richer, multi dimensional environments with multiple product types and constraints. We evaluate revenue performance, stability, constraint satisfaction behavior, and computational scaling, highlighting the trade offs between explicit expectation based optimization and trajectory based learning.

Keywords : 

Abstract :本文对有限时域动态定价问题中的拟合动态规划（DP）和强化学习（RL）方法进行了系统比较，其中需求是根据数据估计的。我们分析了它们在结构复杂性不断增加的环境中的表现，从单一类型基准到具有异构需求和跨时间收入限制的多种类型设置。与将DP限制在低维设置的简化比较不同，我们在具有多种产品类型和约束的更丰富的多维环境中应用动态规划。我们评估了收入绩效、稳定性、约束满足行为和计算规模，强调了基于显式期望的优化和基于轨迹的学习之间的权衡。

Keywords :