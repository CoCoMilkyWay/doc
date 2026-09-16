# 开源强化学习金融市场元宇宙框架

QuantML QuantML 2024-06-08 00:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484644&idx=1&sn=8fbcac50d77955a0b94e9628d1e5aa6d&chksm=cf77fd32893bd02228f60d0115f045afc76f3ce7f3c003a15403aef182b249c7fe71af236414#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484644&idx=1&sn=8fbcac50d77955a0b94e9628d1e5aa6d&chksm=cf77fd32893bd02228f60d0115f045afc76f3ce7f3c003a15403aef182b249c7fe71af236414#rd)

Content

  

本文介绍了FinRL-Meta，一个由AI4Finance社区维护的开源库，旨在为金融强化学习（FinRL）提供动态数据集和市场环境。FinRL-Meta遵循数据为中心的AI原则和DataOps实践，通过自动化数据管理流程，将来自现实市场的数据转换为标准化的gym-style环境，支持研究人员和从业者设计、训练和测试交易策略。

### **1\. 引言 (Introduction)**

-   论文介绍了金融强化学习（FinRL）作为金融和强化学习交叉领域的前景，强调了其在交易技术方面的优势。
    
-   讨论了深度强化学习（DRL）在金融领域的应用，特别是在处理动态数据集方面的挑战，与静态数据集（如ImageNet）形成对比。
    
-   强调了构建高质量市场环境以训练FinRL代理的难点，包括金融数据的低信噪比、历史数据的生存偏差和模型过拟合等问题。
    
    ![](assets/001.png)
    

### **2\. 相关工作 (Related Works)**

-   回顾了金融大数据、数据为中心的AI、DataOps实践、数据驱动的RL以及FinRL应用的相关技术背景和现有工作。
    
-   讨论了金融大数据的4V特性：体量、多样性、速度和真实性。
    
-   探讨了数据为中心的AI在提高金融数据质量方面的重要性。
    
-   介绍了DataOps实践在数据科学领域的应用，以及它们如何提高数据分析的质量和效率。
    
    ![](assets/002.png)
    

### **3\. FinRL任务和FinRL-Meta框架 (FinRL Tasks and FinRL-Meta Framework)**

本章提供了FinRL任务的理论基础和FinRL-Meta框架的详细描述，包括其设计原则、面临的挑战以及如何通过自动化流程和层次化结构来克服这些挑战。

### **3.1 金融强化学习建模 (Modeling Financial Reinforcement Learning (FinRL))**

-   马尔可夫决策过程 (MDP): 将FinRL任务建模为MDP问题，这是一个数学模型，用于描述序列决策问题。MDP由五元组(S, A, R, P, γ)组成，分别代表状态空间、动作空间、奖励函数、转移概率和折扣因子。
    
-   状态空间 (State Space): 描述所有可能的状态，如账户余额、股票持仓等。
    
-   动作空间 (Action Space): 所有可执行的操作，例如买入、卖出或持有股票。
    
-   奖励函数 (Reward Function): 根据状态转移和执行的动作分配一个实数值奖励。
    
-   转移概率 (Transition Probability): 描述系统动态，即在给定状态下执行动作后转移到新状态的概率。
    
-   折扣因子 (Discount Factor): 用于在决策时考虑未来奖励的现值。
    
    ![](assets/003.png)
    

### **3.2 FinRL的挑战 (FinRL Challenges)**

-   低信噪比 (Low SNR): 金融数据可能包含大量噪声，难以识别有效的信号。
    
-   历史市场数据的生存偏差 (Survivorship Bias): 只关注现存的股票和基金，忽略了那些已经退市的，可能导致对股票和基金性能的高估。
    
-   模型过拟合 (Model Overfitting): 研究主要报告回测结果，可能存在通过调整超参数多次训练以获得更好回测结果的诱惑，这可能导致模型在真实市场表现不佳。
    
-   延迟 (Delay): 金融市场因数据传输、奖励反馈和执行动作而存在延迟。
    
-   部分可观测性 (Partial Observation): 市场的真实状态可能无法直接观察到，需要使用部分可观测马尔可夫决策过程 (POMDP) 模型。
    
-   多目标奖励函数 (Multi-objective Reward Function): 在优化一个指标时，可能需要在其他指标之间进行权衡。
    
-   低可解释性 (Low Interpretability): 使用神经网络来拟合Q值函数和策略，但神经网络是黑盒，导致强化学习的可解释性较低。
    

### **3.3 FinRL-Meta框架概述 (Overview of FinRL-Meta Framework)**

-   数据为中心的AI (Data-Centric AI): 强调数据质量的重要性，并提出了一个自动化的数据管理流程，以确保数据质量。
    
-   DataOps范式 (DataOps Paradigm): 采用DataOps实践、流程和技术，结合自动化数据工程和敏捷开发。![](assets/004.png)
    
-   RLOps流水线 (RLOps Pipeline): 为FinRL设计的流水线，包括任务规划、数据处理、训练-测试-交易流程和性能监控。
    
      
    
    ![](assets/005.png)
    

### **3.3.1 层次结构和可扩展性 (Layer Structure and Extensibility)**

-   数据层 (Data Layer): 遵循DataOps范式进行数据管理，以减少数据工程周期时间并提高数据质量。
    
    ![](assets/006.png)
    
-   环境层 (Environment Layer): 将处理好的数据转换为符合OpenAI Gym标准的市场环境。
    
-   代理层 (Agent Layer): 允许用户插入DRL代理并与之交互。
    

### **3.3.2 动态数据集和训练-测试-交易流水线 (Dynamic Datasets and Training-Testing-Trading Pipeline)**

-   动态数据集 (Dynamic Datasets): 标准化的工作流程，用于定期下载和处理数据，以适应训练-测试-交易流水线的需求。
    
-   训练-测试-交易流水线 (Training-Testing-Trading Pipeline): 描述了DRL代理从训练到测试再到交易的全过程。
    
    ![](assets/007.png)
    

### **3.3.3 DRL算法的即插即用模式 (Plug-and-play Mode for DRL Algorithms)**

-   支持多种DRL库，允许用户直接插入DRL代理到训练-测试-交易流水线中。
    

  

### **4\. 自动数据管理流程 (Automatic Data Curation Pipeline)**

本章详细阐述了FinRL-Meta框架中的数据管理流程，包括数据的访问、清洗、特征工程、情绪分析以及环境层的构建。此外，还介绍了如何创建动态市场环境，以及如何利用这些环境进行金融策略的训练和测试。

### **4.1 数据层处理和工程化高度非结构化金融大数据 (Data Layer for Processing and Engineering Highly Unstructured Financial Big Data)**

-   数据访问 (Data Accessing): 描述了如何通过统一接口连接不同市场平台的数据API，以及如何通过指定参数（如开始日期、结束日期、股票列表、时间间隔等）灵活访问数据。
    
-   数据清洗 (Data Cleaning): 解释了原始数据通常存在格式不一和错误或缺失数据的问题，以及如何通过数据处理器自动化数据清洗过程。
    
-   特征工程 (Feature Engineering): 强调了特征工程在训练数据开发中的重要性，并介绍了FinRL-Meta支持的五种类型的特征：市场特征、基本面特征、分析特征、替代特征和自然语言处理特征。
    

### **4.2 金融情绪分析 (Financial Sentiment Analysis)**

-   情绪分析的重要性: 讨论了除了市场数据之外，对其他数据源进行情绪分析的重要性，以及情绪得分作为另一特征的潜力。
    
    ![](assets/008.png)
    
-   基于词典的情绪分析框架 (Lexicon-based Sentiment Analysis Framework): 介绍了一个为金融领域定制的基于词典的情绪分析框架，包括文本预处理和多级情绪分析两个主要阶段。
    
-   金融情绪词典构建 (Financial Sentiment Dictionary Construction): 描述了构建金融情绪词典的过程，包括词典合并和词典扩展两个阶段。
    
    ![](assets/009.png)
    

### **4.3 动态市场环境的环境层 (Environment Layer for Dynamic Market Environments)**

-   遵循OpenAI gym风格的环境: 解释了如何使用清洗后的数据创建市场环境，并提供了一个通用接口，用户可以构建和分享他们自己的环境。
    
-   市场摩擦和投资组合限制: 讨论了如何通过模拟真实市场条件（如交易成本和风险控制）来提高环境的真实性。
    
-   多进程训练: 描述了如何利用GPU进行多进程训练，以及如何通过向量化环境技术加速训练过程。
    

### **4.4 合成数据生成 (Synthetic Data Generation)**

-   市场模拟器: 介绍了如何使用历史限价单簿数据和订单匹配机制来模拟市场，以及如何创建支持市场订单和限价订单的环境。
    

### **4.5 清算分析和交易执行 (Liquidation Analysis and Trade Execution)**

-   清算分析: 通过复现先前的研究，构建了一个模拟环境，用于分析清算策略和执行交易。
    

### **4.6 更多FinRL演示和教程 (More FinRL Demos and Tutorials)**

-   投资组合分配: 提供了一个关于如何训练DRL代理进行股票投资组合优化的示例。
    
-   加密货币交易: 提供了一个关于10种流行加密货币的交易演示。
    
-   纸面交易演示: 提供了一个纸面交易演示，用户可以结合自己的策略或训练有素的代理进行纸面交易。
    

### **5\. 自定义示例和教程 (Homegrown Examples and Tutorials)**

本章通过提供具体的示例和教程，帮助用户理解如何使用FinRL-Meta库来构建和评估金融强化学习策略。这些示例不仅涵盖了从数据获取到策略评估的整个流程，还包括了如何利用云平台和模拟器来提高策略的性能和泛化能力。

### **5.1 性能指标和基线方法 (Performance Metrics and Baseline Methods)**

-   介绍了用于衡量交易性能的指标，包括累积回报、年化回报、年化波动率、夏普比率和最大回撤。
    
-   提供了几种基线交易策略，如被动交易策略、均值-方差策略和等权重策略，用于与DRL策略进行比较。
    
    ![](assets/010.png)
    
    ![](assets/011.png)
    

### **5.2 自定义示例 (Homegrown Examples)**

-   提供了Jupyter/Python教程，帮助新用户熟悉整个流程，并复现了先前研究中的实验作为基准。
    

#### **5.2.1 股票交易任务 (Stock Trading Task)**

-   描述了如何使用FinRL-Meta提供的API获取股票的历史OHLCV数据，并进行数据清洗和特征工程。
    
-   介绍了如何构建训练和测试环境，并选择DRL算法来训练交易代理。
    
-   展示了如何对训练好的代理进行回测，并与基线策略进行性能比较。
    

#### **5.2.2 实时交易 (Trading in Real Time)**

-   讨论了实际任务（如股票交易和加密货币交易）中的过拟合问题，并提出了在纸面交易中部署DRL代理的解决方案。
    
-   提供了一个“训练-测试-交易”流水线的示例，展示了如何使用滚动窗口进行训练、测试和纸面交易。
    
    ![](assets/012.png)
    

#### **5.2.3 集成策略 (Ensemble Strategy)**

-   基于股票交易任务，介绍了集成方法，该方法结合了不同的代理以获得一个适应性强的代理，该代理继承了各个代理的最佳特性，并在实践中表现出色。
    
    ![](assets/013.png)
    

#### **5.2.4 Podracer云端解决方案 (Podracer on Cloud)**

-   复现了基于种群的训练解决方案，如代际进化和基于锦标赛的进化，并展示了FinRL-Podracer如何在云平台上扩展到1000个GPU以上。
    

#### **5.2.5 通用代理的课程学习 (Curriculum Learning for Generalizable Agents)**

-   基于FinRL-Meta（一个包含至少100个市场环境的宇宙），讨论了如何通过课程学习方法训练一个能够处理多个金融任务的通用代理。
    
    ![](assets/014.png)
    

#### **5.2.6 市场模拟器 (Market Simulator)**

-   描述了如何构建遵循OpenAI-gym风格的市场环境，并提供了一个市场模拟器，该模拟器使用历史限价单簿数据和订单匹配机制来模拟市场。
    

### **5.3 更多FinRL演示和教程 (More FinRL Demos and Tutorials)**

-   提供了额外的演示和教程，包括投资组合分配、加密货币交易、纸面交易演示、中国A股演示和超参数调整。
    
    ![](assets/015.png)
    

#### **5.3.1 投资组合分配 (Portfolio Allocation)**

-   训练DRL代理在一组股票上执行投资组合优化任务。
    

#### **5.3.2 加密货币交易 (Cryptocurrency Trading)**

-   提供了一个关于10种流行加密货币的交易演示。
    

#### **5.3.3 纸面交易演示 (Paper Trading Demo)**

-   提供了一个纸面交易演示，用户可以结合自己的策略或训练有素的代理进行纸面交易。
    

#### **5.3.4 中国A股演示 (China A-share Demo)**

-   提供了一个基于中国A股市场数据的演示，使用Tushare作为数据源。
    

#### **5.3.5 超参数调整 (Hyperparameter Tuning)**

-   讨论了超参数调整的重要性，并提供了使用Optuna和Ray Tune进行超参数调整的演示。
    

#### **5.3.6 智能投顾 (Robo-advising)**

-   鼓励用户通过结合ChatGPT和GPT-4开发智能投顾应用，并提供了如何使用这些工具的演示。
    
    ![](assets/016.png)
    

### **6\. 结论和未来工作 (Conclusion and Future Works)**

-   总结了FinRL-Meta的主要贡献，包括其数据为中心的方法、DataOps实践和开源社区的支持。
    
-   讨论了未来的研究方向，如构建更多的市场环境、探索使用GPU进行大规模并行模拟，以及将FinRL-Meta与新兴技术（如DAO、DeFi、NFT和Web3）结合的潜力。
    

  

  

论文及代码下载见星球

  

  

目前距离星球下次提价还有最后4个名额，欢迎扫码加入：

![](assets/017.jpg)

  

  

入群请扫我：  

![](assets/018.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序模型Autoformer用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=ce7e631df909ea0b4515cbd2f95cffb0733d872a519942f1d88e6a561a01bcfe68716d31fe0c&scene=21#wechat_redirect)
    
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
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [研报复现 | 开源证券 ：形态识别，均线的收敛与发散](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)  
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | FTS-Diffusion: 用于合成具有不规则和尺度不变模式的金融时间序列的生成框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483907&idx=1&sn=df124c03a74981eba923fee63613ecfd&chksm=ce7e651df909ec0b2f6029db3e29992bb41210c8b9f76f979b7968d0fab1ac913848004ac44d&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)
    
-   [ICAART 2024 | DTX: 基于TBSE Level2多线程市场模型的深度学习交易系统](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483965&idx=1&sn=e2fda25ce1bc8a4b9393158321dc2a14&chksm=ce7e6523f909ec3538bd37e07689308380cad55b02c35a7d4652a3e7d7fd3306a40253341c61&scene=21#wechat_redirect)
    

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

  

**点击蓝字**

![](assets/019.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/020.jpg)