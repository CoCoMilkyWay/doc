# Auto.gov：基于强化学习的去中心化金融（DeFi）治理框架

QuantML QuantML 2025-02-17 21:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489317&idx=1&sn=452e505de9cc3b12be1b561992ba7182&chksm=cf32f63186815a7f2b290890ec7008be94d8332d46492b45e2c7c6f6a0f93d6ddad293e8a2dc#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489317&idx=1&sn=452e505de9cc3b12be1b561992ba7182&chksm=cf32f63186815a7f2b290890ec7008be94d8332d46492b45e2c7c6f6a0f93d6ddad293e8a2dc#rd)

### 

本文介绍了一种名为 **Auto.gov** 的创新性治理框架，该框架旨在解决去中心化金融（DeFi）领域当前面临的治理困境。

### 一、引言：DeFi 治理的现状与挑战

**1\. DeFi 的核心地位与治理的重要性**

-   **DeFi 的定义与作用:** DeFi 作为区块链生态系统的重要组成部分，通过基于智能合约的协议，实现了无需传统金融中介的借贷、交易等金融活动。
    

-   例如，Aave、Uniswap 和 Curve 等协议允许用户直接进行加密资产的借贷和交换。
    

-   **治理的必要性:** 尽管区块链技术本身无需依赖可信第三方，但区块链系统中的某些决策仍需要协调或治理机制。
    

-   以 Aave 为例的 DeFi 借贷协议依赖于各种参数来运行，包括利率模型参数以及抵押因子和清算阈值等风险参数。
    
-   这些资产特定的风险参数决定了每种加密资产的过度抵押程度和清算激励措施，对于保护协议免于因贷款违约或市场不利变动而破产至关重要。
    
-   因此，这些参数需要持续监控和调整，以适应快速变化的加密货币市场。
    

**2\. 传统 DeFi 治理的局限性**

-   **治理过程繁琐且耗时:**
    

-   当前的治理流程包括观察/构思、提案、讨论、投票以及最终的否决/实施，整个过程劳动强度大且耗时。
    
-   例如，Aave 治理论坛上的一个提案建议提高 AAVE 市场的清算阈值，讨论持续了近三周，最终被否决。
    
-   这种固有的缺乏敏捷性在快速发展和波动的加密货币市场中尤其成问题。
    
-   附录 D 表明，即使在价格波动性、交易量和利用率（借款/供应）等关键市场指标发生重大波动的情况下，Aave 的风险参数也经常保持不变。
    

![](assets/001.png)

-   **治理权力集中化问题:**
    

-   协议的核心团队通常持有大量治理代币，并负责投票后的执行工作，这违背了去中心化投票的目的。
    

-   **易受恶意攻击:**
    

-   攻击者通过暂时抬高抵押资产的价格来借入超出其应得数量的资金，并无偿还意图。
    
-   例如，bZx 协议和 Cream Finance 在 2020 年和 2021 年分别因使用“闪电贷”的价格预言机漏洞损失了 800 万美元和 1.3 亿美元。
    
-   当前的治理模式缺乏灵活性，使得协议容易受到价格预言机攻击等恶意利用。
    

**3\.  Auto.gov 的提出：基于深度 Q 网络的强化学习治理框架**

为了应对上述挑战，本文提出了 **Auto.gov**，一种基于深度 Q 网络 (DQN) 强化学习 (RL) 的参数调整框架：

-   **核心思想:**
    

-   Auto.gov 采用半自动化、数据驱动的方式进行参数调整，旨在提高 DeFi 治理的效率、弹性和安全性。
    

-   **RL 的适用性:**
    

-   DeFi 环境可以被建模为马尔可夫决策过程 (MDP)，其中未来状态仅由当前状态和动作决定，这与 RL 原理高度契合。
    
-   与依赖静态数据集并需要重新训练以适应的许多其他机器学习模型不同，RL 擅长快速响应 DeFi 系统中固有的复杂且不可预测的动态变化，提供了一种稳健、有弹性且能够随市场条件变化而发展的治理方法。
    
-   Auto.gov 考虑了决策的长期后果，这对于 DeFi 治理至关重要，因为决策可能会对协议稳定性、用户信任度和风险承受能力产生重大影响。
    
-   Auto.gov 的设计减少了人为错误的可能性，并通过仅允许逐步调整来防止系统行为不稳定，从而降低了“黑天鹅”事件的风险。
    

### 二、相关工作：DeFi 治理与机器学习

**1\.  DeFi 建模与管理:**

-   现有研究主要集中在对 DeFi 协议的不同方面进行建模和分析，例如市场风险、过度和不足抵押风险以及清算事件等。
    
-   相比之下，Auto.gov 直接制定了旨在提高协议整体安全性和盈利能力的治理措施。
    

**2\.  DeFi 领域的机器学习应用:**

-   一些研究将机器学习算法应用于 DeFi，例如预测利率波动性、信用风险评估、基于群学习的信用评分等。
    
-   然而，这些工作都没有直接参与 DeFi 的治理。
    

**3\.  传统金融领域的算法与自动化:**

-   算法交易在金融和计算机科学文献中得到了广泛研究。
    
-   人工智能和数据科学技术 (AIDS) 以及它们在金融业务中的挑战和机遇也得到了研究。
    
-   机器学习被用于快速定价、对冲和拟合金融衍生品。
    
-   与上述研究不同，Auto.gov 的研究重点是 DeFi 治理。
    

### 三、环境与代理建模：构建模拟环境

为了进行 RL 实验，本文构建了一个简化的 DeFi 环境，包括用户和类似 Aave 的借贷协议。RL 代理通过调整每个借贷池的抵押因子来优化协议的净头寸。

![](assets/002.png)

**1\. 动作 (Actions):**

-   **治理代理动作:**
    

-   首先检查代理动作的有效性（例如，调整后的抵押因子不得超过 1）。
    
-   将增量增加或减少幅度限制在 2.5%，以确保即使治理代理做出错误决策，对 DeFi 协议的潜在危害也只会是渐进的和最小的。
    
-   提高/降低/保持抵押因子。
    
-   为了保证代理动作的确定性、可控性和安全性，Auto.gov 对代理动作实施了一层额外的约束：
    

-   **用户动作:**
    

-   存款、取款、借款、还款、清算和抵消。
    
-   用户的行为受到市场条件以及自身财务状况的影响，例如，当借贷池对存款的吸引力降低时，用户会寻求取款。
    

**2\. 状态 (States):**

-   **借贷池状态:**
    

-   总可用资金、供应代币、借款代币、不良债务、净头寸、利用率、抵押因子、供应利率、借款利率以及对供应和借款的吸引力。
    
-   这些状态反映了借贷池的财务状况和风险水平。
    

-   **用户状态:**
    

-   供应价值、借款价值、贷款健康状况、供应信心和借款信心。
    
-   这些状态反映了用户的财务状况和对借贷协议的信心。
    

-   **市场状态:**
    

-   价格、竞争性供应利率和竞争性借款利率。
    
-   这些状态反映了市场环境对用户行为的影响。
    

**3\. 奖励 (Reward):**

-   奖励函数通过计算协议净头寸的变化来近似协议的盈利能力。
    

-   奖励 =  RL 环境中的净头寸变化 - 基线环境中的净头寸变化 - 无效动作的惩罚。
    
-   奖励作为反馈，告知代理其动作在给定状态下的直接后果。
    
-   折扣累积奖励反映了代理的长期优化目标。
    

### 四、治理代理设计：强化学习算法

**1\.  基于 RL 的代理:**

-   Auto.gov 采用深度 RL 代理作为治理代理，该代理根据 DeFi 协议的当前状态动态选择最佳动作。
    
-   深度 Q 学习用于对治理代理进行学习过程，其中 Q 函数可以告诉代理奖励会是什么。
    
-   目标是通过训练策略 π 来最大化折扣累积奖励。
    

**2\.  目标网络:**

-   为了防止训练过程中的过拟合并提高代理对潜在攻击的抵抗力，Auto.gov 实现了目标网络。
    

-   目标网络是一个具有与主网络或在线网络相同架构但权重不同的独立神经网络。
    
-   其主要目的是为 Q 学习更新提供更稳定和一致的目标值。
    
-   训练过程包括定期将权重从在线网络复制到单独的目标网络。
    

**3\.  优先经验回放:**

-   为了使治理代理能够适应不同的 DeFi 环境，加快策略网络的训练，并迅速提高其对潜在攻击的抵抗力，Auto.gov 还采用了优先经验回放作为可选训练功能。
    

-   优先经验回放增强了标准经验回放技术，后者均匀地存储和采样训练过程中的经验。
    
-   优先经验回放根据实际和预测 Q 值之间的差异为每次经验分配重要性，从而增加了采样和学习意外经验或那些更有潜力提高代理性能的经验的可能性。
    

![](assets/003.png)

![](assets/004.png)

### 五、模拟设置：构建训练环境

**1\.  环境抽象:**

-   为了便于实验，本文对 DeFi 借贷协议环境进行了抽象，包括：
    

-   将市场用户行为建模为聚合级别，即一个代表代理代表整个用户群的行为。
    
-   没有清算激励，因为它是用户之间的零和博弈。
    
-   将清算阈值等同于抵押因子。
    

![](assets/005.png)

**2\.  借贷池建立:**

-   为了模拟资产价格波动性对 RL 代理抵押因子确定的影响，本文在借贷协议环境中包含了三个借贷池，涵盖三种类型的加密资产：ETH、USDC 和 TKN。
    

![](assets/006.png)

**3\.  用户反应模拟:**

-   模拟了三种场景下的用户反应：攻击场景、贷款违约场景和普通场景。
    

-   在攻击场景中，模拟了典型的闪电贷资助的价格预言机攻击。
    
-   在贷款违约场景中，用户在抵押不足的情况下违约贷款。
    
-   在普通场景中，用户根据借贷池的吸引力进行存款、取款、借款和还款。
    

**4\.  其他设置:**

-   基准环境与主训练环境完全相同，只是没有治理代理，抵押因子在整个剧集中始终保持其初始值 0.8。
    
-   资产价格模拟：使用几何布朗运动对代币价格时间序列进行建模。
    
-   其他 DeFi 环境参数：设置所有三个资产的初始抵押因子为 0.8，外部竞争性供应和借款利率分别为每年 0.05 和 0.15。
    
-   随机事件和随机过程：每个剧集生成新的价格轨迹和攻击时间点，并平等地应用于 RL 和基准环境。
    

![](assets/007.png)

### 六、结果：模型性能评估

**1\.  超参数调整:**

-   使用 PyTorch 实现治理代理，使用 OpenAI Gym 实现 DeFi 环境。
    
-   训练评估过程在配备 M2 Pro CPU 和 24 GB RAM 的 Mac 笔记本电脑上进行。
    
-   对关键超参数进行了详细调整，例如网络层数、神经元数量、学习率、折扣 值等。
    

![](assets/008.png)

**2\.  治理代理训练:**

-   训练速度：对于所有场景（即每个剧集 300、450、600 和 750 个动作），训练时间均保持在每个剧集 3000 毫秒以下。
    

-   使用 600 个动作进行训练可以快速有效地训练治理代理。
    

-   训练过程：
    

-   随着训练剧集的增加，治理代理在两种场景（有无攻击）中都有效收敛。
    
-   在没有对抗性攻击的情况下，借贷协议可以保持偿付能力。
    
-   当受到价格预言机攻击时，破产很可能发生。
    
-   在 RL 环境中，破产在最初的剧集中出现得更频繁，但在大约 5000 剧集之后，频率大幅下降，这证明了训练过程的有效性。
    

![](assets/009.png)

**3\.  治理结果分析:**

-   在训练有素的剧集中，抵押因子的变化变得不频繁，这与训练阶段观察到的结果一致。
    
-   在没有攻击的情况下，代理倾向于采用更激进的策略，即在整个剧集中始终保持抵押因子处于较高水平。
    
-   在存在攻击的情况下，代理会采用更动态的抵押因子策略，以提高借贷协议的弹性。
    
-   训练有素的代理能够有效地增加协议储备，并始终保持 0.6 到 0.8 之间的健康利用率。
    
-   训练有素的 RL 代理在净头寸方面始终优于基线环境，尤其是在存在攻击的情况下，优势更加明显。
    

![](assets/010.png)

**4\.  真实世界数据测试:**

-   使用来自 CryptoCompare.com 的真实世界数据对训练有素的治理代理进行测试。
    
-   与静态基线策略以及两种基准方法（一种统计方法和一种基于 Q 学习的基准方法）进行比较。
    
-   结果表明，训练有素的 RL 策略不仅优于静态基线策略，而且优于两种基准方法。
    

-   基准 2 也基于 RL，但由于 Q 表无法有效处理大型状态空间，导致其性能明显低于 Auto.gov 和基准 1。
    
-   这凸显了使用 DQN 为 Auto.gov 提供动力的必要性，因为它可以通过函数逼近有效地管理大型和连续的状态空间。
    

### 七、讨论：Auto.gov 的局限性及未来方向

**1\.  局限性:**

-   **环境变化:**
    

-   为了便于结果解释和受限于设施条件，本文使用了风格化的 DeFi 环境。
    
-   根据特定 DeFi 协议的实际复杂性和所需的自动化水平，训练时间可能会增加，需要增强计算资源，代理效率也可能会变化。
    

-   **操作员风险:**
    

-   框架可能会受到来自训练操作员的潜在风险。
    
-   操作员可能会采用有偏见的训练策略来指导治理代理，以对自己有利的方式产生利润。
    

-   **对抗性机器学习攻击:**
    

-   可能会暴露于来自对抗性机器学习策略的威胁。
    

**2\.  调整与扩展:**

-   **更多训练维度:**
    

-   除了训练治理代理以找到最佳抵押因子调整策略外，还可以允许其调整其他参数，例如其他风险参数和利率模型参数。
    

-   **更多训练场景:**
    

-   可以在不同的市场条件（例如时变的竞争利率）和不同的用户行为（例如抵押因子下降后不同的借款信心下降水平）下训练治理代理。
    

-   **更复杂的机器学习技术:**
    

-   可以应用更复杂的机器学习模型，例如多智能体强化学习，通过允许用户也成为具有自身目标的强化学习代理（例如最大化其最终财富）。
    

-   **模型适应性和可转移性:**
    

-   通过一些调整和修改，该模型可以轻松扩展到其他借贷协议，例如 Compound 和 dForce。
    
-   经过适当修改后，该模型也可以应用于其他类型的 DeFi 协议，例如自动做市商 (AMM)。
    

### 八、结论

本文构建了一种基于 DQN RL 的 DeFi 治理解决方案，旨在提高 DeFi 治理的安全性和效率。通过模拟环境和真实世界数据的测试，Auto.gov 展现出了强大的适应能力和优越的性能，证明了其在不同场景下的有效性。

未来，Auto.gov 有望取代现有的繁琐且易受人为偏见影响的治理流程，为 DeFi 协议提供一种更安全、更高效的治理方式。

  

CRYPTO加群请见后台。

  

  

论文及代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/011.png)

  

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
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)