# 强化学习新突破：集成方法+GPU并行模拟用于交易

QuantML QuantML 2025-03-19 21:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489723&idx=1&sn=80e924f5fea5b68086822fb354215d57&chksm=cfa11a48d90f813f5cd346835adb6a83440006374bdbbadfe52afb5cf8887ac8416f62db116a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489723&idx=1&sn=80e924f5fea5b68086822fb354215d57&chksm=cfa11a48d90f813f5cd346835adb6a83440006374bdbbadfe52afb5cf8887ac8416f62db116a#rd)

### 

### 1\. 引言：强化学习在金融领域的潜力与挑战

近年来，强化学习（RL）在各个领域取得了显著突破，尤其在金融领域，其决策能力的重要性不言而喻。金融强化学习（FinRL）专注于将 RL 应用于各种金融任务，例如算法交易、投资组合管理和期权定价等。然而，金融市场的复杂性和动态性对 RL 模型提出了巨大挑战，主要体现在以下两个方面：

**1.1  政策不稳定性**

-   **根源分析**:  RL 算法的性能在很大程度上依赖于价值函数近似误差，这会导致政策不稳定性。此外，RL 策略对超参数、环境稳定性和随机种子也高度敏感。例如，在股票交易任务中，使用近端策略优化（PPO）、软演员-评论家（SAC）、深度确定性策略梯度（DDPG）以及一个简单的集成模型（对三个智能体动作概率取平均）进行实验。结果表明，不同类型的智能体在累积收益方面均表现出较高的方差，而集成模型的标准差仅为组件智能体的一半左右，这突显了其在缓解政策不稳定性方面的有效性【图 1】。
    
    ![](assets/001.png)
    

-   **图 1 解读**:  不同 RL 算法以及简单集成方法的性能偏差图表明，集成方法在减少收益波动性方面具有显著优势。
    

-   **影响**:  政策不稳定性会严重影响智能体在 RL 中的性能和可靠性。
    
    ![](assets/002.png)
    

**1.2  采样瓶颈**

-   **挑战**:  RL 算法严重依赖于模拟环境进行训练。对于复杂任务，例如机器人训练，需要大量样本，这会导致模拟阶段延长至数天甚至数周。金融市场的固有复杂性和动态性进一步加剧了稳健模型开发的难度，增加了政策不稳定性和采样瓶颈的挑战。
    

-   **具体表现**:  在我们的 FinRL 任务中，轨迹 τ 是指在一定时间内观察到的交易动作和状态序列。金融结果被量化为沿轨迹 τ 的奖励 R(τ) 以计算预期回报 J(θ)。当处理复杂且嘈杂的金融数据集时，实现低方差梯度估计 ∇J(θ) 对于稳定可靠的政策更新至关重要，从而降低次优交易策略的风险。由于金融奖励对动作的小幅变化非常敏感，因此需要广泛的采样来减少梯度估计 ∇J(θ) 的方差。
    
-   **图 2 解读**:  强化学习的生产者-消费者模型图展示了模拟阶段（生产者）和学习阶段（消费者）之间的关系，强调了采样在 RL 中的重要性。
    

![](assets/003.png)

### 2\.  强化学习与集成学习在金融领域的应用

**2.1  金融强化学习 (FinRL)**

-   **应用领域**:  DRL 已被成功应用于各种金融任务，例如算法交易、投资组合管理和期权定价等。
    

-   **新兴算法**:  例如，直接偏好优化 (DPO) 使用不同结果之间的偏好作为学习的主要反馈，也将促进 RL 在金融领域的新应用。
    

-   **优势**:  DRL 适用于高维状态和动作空间，在处理复杂且动态的金融市场时具有优势。
    

**2.2  集成学习**

-   **定义**:  机器学习中的集成方法结合了多个算法的预测，以实现比单个组件更好的性能。
    

-   **常见方法**:  例如，bagging 和 boosting 等不同集成方法已被开发出来，许多变体已应用于各个领域。
    

-   **在 RL 中的应用**:  在 RL 中，集成方法可以通过组合来自组件 RL 算法的选定动作或动作概率来提高整体性能。
    

-   **在金融领域的应用**:  在 FinRL 中，集成方法可以有效提高复杂金融市场中策略的稳定性和智能体的性能。
    

**2.3  模拟环境**

-   **RL 对模拟环境的依赖**:  RL 算法严重依赖于模拟环境进行训练，例如机器人训练依赖于模拟，因为从现实世界中获取样本既昂贵又困难。金融任务在部署到现实世界应用之前，也需要使用历史数据进行训练和验证。
    
-   **现有框架**:
    

-   **OpenAI Gym**:  是最受欢迎的框架和环境的集合之一。
    
-   **ABIDES-gym**:  将 ABIDES 模拟器集成到 Gym 框架中，并已成功应用于金融任务。
    
-   **Isaac Gym**:  为机器人学习而开发，它允许物理模拟和策略更新都在 GPU 上进行，从而将训练速度提高了 100 到 1000 倍。
    
-   **JAX-LOB**:  提出了一个 GPU 加速的限价订单簿 (LOB) 模拟器，旨在实现数千个订单簿在 GPU 上的并行处理。
    

### 3\.  问题描述：FinRL 任务中的问题制定

**3.1  FinRL 任务的问题制定**

-   **股票交易任务**:  涉及买卖道琼斯指数的 30 只股票，以在指定的时间范围内最大化财务回报。交易者需要利用每日 OHLCV 数据来预测价格走势并做出交易决策。
    
-   **加密货币交易任务**:  涉及买卖比特币 (BTC) 以在时间范围内最大化财务回报。交易者需要利用秒级的 LOB 数据来预测价格走势并做出交易决策。
    
-   **MDP 公式化**:
    

-   **状态**:  包含账户余额、每种资产的价格、持有头寸以及每种资产的特征向量（技术指标）。
    
-   **动作**:  表示每个股票或加密货币的交易动作，即头寸的变化。
    
-   **奖励函数**:  奖励是总资产价值的变化，激励交易智能体在状态 s\_t 执行动作 a\_t。
    
-   **策略**:  是状态 s 上动作的概率分布，评估当前市场状况并确定每种可能交易动作的可能性。
    

**3.2  训练过程**

-   **模拟阶段**:  作为“生产者”，通过在环境中执行动作来实现数据采样，从而产生新的状态和奖励。
    
-   **重放缓冲区**:  作为存储模拟阶段样本的存储库，允许学习阶段访问这些样本。
    
-   **学习阶段**:  作为“消费者”，从重放缓冲区检索样本以更新策略。
    

**3.3  集成方法的有效性和负担**

-   **3.3.1  有效性及成本**:
    

-   **理论依据**:  Condorcet 投票定理为在决策中使用集成方法提供了理论基础。在金融决策中，集成方法的优势在于，随着具有正确决策概率 p > 0.5 的交易者数量的增加，集成做出正确交易决策的概率接近 1。
    
-   **挑战**:  集成方法在 FinRL 中仍需解决智能体多样性和广泛的采样要求。组件智能体的多样性对于利用各种交易策略来降低风险至关重要，而实现高度多样性需要跨模拟不同市场场景的环境训练多个智能体。
    

-   **3.3.2  广泛采样的挑战**:
    

-   **目标**:  学习一个策略 π\_θ，其参数 θ 最大化预期回报 J(θ)。
    
-   **梯度估计**:  为了获得稳定的梯度估计，需要广泛的采样来减少梯度估计的方差。
    

### 4\.  大规模并行模拟

**4.1  模拟阶段的梯度估计**

-   使用蒙特卡罗方法估计梯度 ∇J(θ)，并利用大数定律和中心极限定理来保证估计的收敛性和减少估计的方差。
    

**4.2  大规模并行市场环境**

-   **4.2.1  模拟阶段的并行性**:
    

-   模拟阶段采样的大量轨迹 N 对于减少 ∇J(θ) 的方差是必要的。每个轨迹 τ^(i) 都可以并行模拟，从而实现高度的并行性。
    
-   并行性随着计算资源的处理能力而扩展，这对于实现大规模并行模拟至关重要。
    

-   **4.2.2  向量化市场环境**:
    

-   **并行子环境 (SubEnv)**:  每个 SubEnv 使用不同的 OHLCV 或 LOB 数据集模拟不同的市场场景，并维护自己的余额、价格、持有头寸、技术因素和市场限制。
    
-   **构建环境**:  对所有 SubEnv 执行一致的操作进行数据采样，包括重置 (reset)、步骤 (step) 和奖励 (reward)。
    

-   开发向量化的市场环境 (VecEnv) 进行大规模并行模拟。
    

**4.3  映射到 GPU**

-   **4.3.1  在 GPU 上进行并行模拟**:
    

-   现代 GPU 具有强大的并行处理能力，非常适合在许多 GPU 核心上进行大规模并行模拟。
    
-   PyTorch 的 vmap 函数向量化了步骤和奖励函数，使它们能够在数千个并行 SubEnv 中同时运行。
    

-   **4.3.2  在 GPU 张量中存储数据样本**:
    

-   将数据样本组织成张量并存储在 GPU 内存中，避免了昂贵的 CPU-GPU 通信。
    
-   通过在 GPU 上存储和处理数据样本，可以解决传统训练过程中由于 PCIe 带宽限制导致的 GPU-CPU 通信瓶颈问题。
    
    ![](assets/004.png)
    

### 5\.  集成学习

**5.1  智能体多样性**

-   **使用 KL 散度**:  为了在组件智能体之间强制执行多样性，我们在智能体的训练损失函数中引入 Kullback-Leibler (KL) 散度项。KL 散度衡量一个概率分布与另一个概率分布的差异。在集成中，KL 散度项会惩罚不同智能体之间策略的相似性，鼓励它们采用各种交易策略。
    
-   **使用不同的数据集**:  用于训练组件智能体的金融数据集是多样化的。对每只股票或加密货币，生成一个从 -1% 到 1% 的随机百分比变化，并应用于其价格，从而在保留原始价格趋势的同时改变价格尺度。智能体还在测试集中对不同的股票进行训练。
    

**5.2  FinRL 任务的集成方法**

-   **5.2.1  股票交易任务**:
    

-   **训练**:  智能体在 30 天的训练滚动窗口上使用 VecEnv 进行独立训练，并使用第 4 节的大规模并行模拟和第 5.1 节中的智能体多样性方法。
    
-   **验证**:  训练后，智能体在 5 天的滚动窗口上进行验证，计算夏普比率以评估其平衡回报与相关风险的能力。
    
-   **权重计算**:  丢弃夏普比率非常低的智能体。使用 softmax 函数对剩余智能体的夏普比率应用以计算权重。
    
-   **交易**:  在 5 天的交易窗口期间，集成根据智能体动作概率的加权平均采取行动。这种滚动窗口方法确保了集成方法能够适应不断变化的市场。
    

-   **集成组成**:  集成包括 PPO、SAC 和 DDPG 智能体。
    
-   **最终交易动作确定**:  通过对智能体动作概率的加权平均来确定集成的最终交易动作。
    

-   **5.2.2  加密货币交易任务**:
    

-   **训练**:  每个组件智能体都使用 VecEnv 进行独立训练，并使用第 4 节的大规模并行模拟和第 5.1 节中的智能体多样性方法。
    
-   **动作集成和交易**:  在交易阶段，每个智能体处理相同的市场状态，并根据其策略确定一个动作。选择多数动作作为最终集成动作。
    

-   **集成组成**:  使用 DQN、Double DQN 和 Dueling DQN 智能体来处理离散动作空间。
    

### 6\.  性能评估

**6.1  实验设置**

-   所有实验均使用一台 NVIDIA A100 GPU 进行。
    

**6.2  采样速度**

-   在股票交易任务中，使用 2048 个并行环境的模拟平均采样速度为每秒 8813.81 个样本，与单个环境的 184.63 个样本相比，采样速度提高了 47.73 倍。
    
-   在加密货币交易任务中，使用 2048 个并行环境的模拟每秒可实现约 114885.98 个样本，而单个环境为 65.79 个样本，采样速度提高了 1746 倍【图 4】。
    

-   ![](assets/005.png)
    

**6.3  股票交易任务**

-   **模型**:  使用三种集成模型，以及单个 PPO、SAC 和 DDPG 智能体。
    
-   **结果**:
    

-   PPO 智能体实现了最高的累积回报 63.37%、夏普比率 1.55 和 Sortino 比率 2.44，表明其能够在控制波动性和下行风险的同时保持高回报。
    
-   DDPG 的累积回报接近 PPO，但其最大回撤较高，为 -13.15%，表明存在重大价值下跌的潜在风险。
    
-   SAC 的最大回撤低于 DDPG，但在其他指标方面表现不佳。
    
-   所有单个智能体在所有指标上都大大优于两个传统基线。
    
-   集成模型也保持了盈利能力，并在风险管理方面具有优势。集成 1 的累积回报为 62.60%，并且在 2022 年 9 月至 2023 年 10 月期间表现出色【表 2】。
    
    ![](assets/006.png)
    

**6.4  加密货币交易任务**

-   **模型**:  使用三种集成模型，以及单个 DQN、Double DQN 和 Dueling DQN 智能体。
    
-   **结果**:
    

-   Double DQN 和 Dueling DQN 智能体的性能相似，累积回报为 0.48%，低于 BTC 价格基线。
    
-   尽管如此，它们实现了比固定时间退出策略和 BTC 价格基线更高的夏普比率 0.21 和更低的最大回撤 -0.98%，表明有效的风险管理。
    
-   三种不同的集成模型性能相似，这可能是由于每个时间步的有限动作空间导致智能体输出相同的动作。
    
-   集成模型的累积回报接近 BTC 价格基线。此外，集成模型在所有指标上都优于所有单个智能体，实现了最高的夏普比率 0.28 和最低的最大回撤 -0.73%，以及最高的胜/负比率 1.62【表 3】。
    

### 7\.  结论

本文重新探讨了集成方法，并将其与大规模并行模拟相结合，以执行股票和加密货币交易任务。它增强了训练模型在动荡的金融市场中的效率和稳健性。在 GPU 上进行的大规模并行模拟将采样速度提高了 1746 倍（与单个环境相比，使用 2048 个并行环境）。集成方法结合了不同智能体的优势，以缓解政策不稳定性并提高模型性能。股票和加密货币交易任务的结果表明，集成模型具有高累积回报，并且优于某些单个智能体，最大回撤降低了 4.17%，夏普比率提高了 0.21。

总之，将集成方法与 GPU 上大规模并行模拟相结合，是解决 FinRL 中政策不稳定性和采样瓶颈的强有力的方法。凭借高稳定性，集成模型可以实现高泛化能力。未来的研究可以侧重于优化这些技术，并探索更广泛的金融工具和市场条件。大规模的集成集合可以利用加速采样，结合各种智能体，从而在 FinRL 中实现更具普遍能力的模型。

  

  

  

更多资源见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/007.png)

  

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
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
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
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)