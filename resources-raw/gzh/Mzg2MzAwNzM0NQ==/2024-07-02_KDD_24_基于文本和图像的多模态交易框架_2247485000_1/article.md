# KDD 24 | 基于文本和图像的多模态交易框架

QuantML QuantML 2024-07-02 20:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485000&idx=1&sn=1b7a7da8050d6448a3f649014f05ce7f&chksm=cf85f827de84a67e814e8e0376f65e75811070dd0a40a45372a326e0f2bf1c2f77d62e577111#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485000&idx=1&sn=1b7a7da8050d6448a3f649014f05ce7f&chksm=cf85f827de84a67e814e8e0376f65e75811070dd0a40a45372a326e0f2bf1c2f77d62e577111#rd)

Content

这篇论文介绍了多模态基础交易代理FinAgent，它是为了应对金融市场中的复杂性而设计的。![](assets/001.png)

### **第1章：引言 (Introduction)**

-   金融市场对经济稳定至关重要，而金融交易系统通过技术策略增强了市场效率。
    
-   传统基于规则的交易系统缺乏适应市场波动的能力，而基于强化学习的系统虽具适应性，但存在诸如数据需求大、决策过程不透明等障碍。
    
-   论文提出了FinAgent，这是一个多模态基础代理，集成了文本和视觉信息，以全面分析市场动态和历史交易模式。
    

  

### **第2章：相关工作 (Related Work)**

本章回顾了大型语言模型（LLMs）在决策制定任务中的应用，特别是在金融领域的应用情况。本章讨论了LLMs如何超越自然语言处理的限制，扩展到更复杂的特定任务功能，包括集成记忆和规划模块，以模拟人类的认知过程并适应动态环境。

此外，还探讨了多模态LLMs的最新进展，如GPT-4V，它通过处理文本和视觉数据来增强LLMs的能力。

本章还涵盖了AI在金融交易中的应用，包括基于RNN、图深度学习、树模型和强化学习的方法，并指出了现有方法在处理价格数据和泛化能力方面的局限性，强调了需要更先进的技术来整合多模态智能并应对复杂的市场动态。

![](assets/002.png)

### **第3章：问题表述 (Problem Formulation)**

1.  金融交易作为MDP：将金融交易任务建模为MDP，其中代理（投资者）与环境（金融市场）交互以做出投资决策，目标是最大化总利润。MDP由状态集合、行动集合、状态转移函数、奖励函数和折扣因子组成。在这种框架下，每个状态代表了基于价格信息、订单簿、技术指标、趋势预测、金融新闻、专家投资行为和整体市场状况的金融市场感知。
    
2.  问题形式化：进一步将多模态LLMs集成到RL框架中，以灵活定义推理过程。FinAgent的优化问题被扩展，包括了市场情报、记忆、低级和高级反思模块，以及决策模块。这些模块通过特定的提示生成器与多模态LLM交互，生成响应并解析为环境中的兼容行动。
    

  

### **第4章：FinAgent框架 (FinAgent Framework)**

本章详细定义了每个模块的功能，包括市场情报的收集和分析、记忆机制的存储和检索、反思模块的学习和改进决策过程，以及决策模块的最终投资决策制定

![](assets/003.png)

1.  市场情报模块（Market Intelligence Module）：
    

-   该模块负责收集、整合、总结和分析市场信息，包括每日股票新闻、价格和财务报告。
    
-   它通过分析最新的市场情报，评估市场情绪，并提供市场趋势的详细总结，以支持交易决策。
    
-   模块还包括对历史数据的检索和总结，以识别可能影响未来价格的模式和趋势。
    

3.  记忆模块（Memory Module）：
    

-   记忆机制对于LLM代理来说至关重要，它有助于处理大量文本、理解上下文、保持对话连贯性，并提高代理的理解和逻辑能力。
    
-   在金融交易的背景下，记忆模块支持市场情报、低级和高级反思模块，提供存储能力和向量检索功能。
    
-   该模块采用向量存储架构，由市场情报记忆、低级反思记忆和高级反思记忆三个主要部分组成。
    

5.  低级反思模块（Low-level Reflection Module）：
    

-   该模块专注于分析市场情报、K线图和技术指标与价格变动之间的关系，以增强决策能力。
    
-   它生成短期、中期到长期的价格变动分析，识别目标股票价格变动的潜在模式，并从中得出洞察。
    

7.  高级反思模块（High-level Reflection Module）：
    

-   高级反思模块设计用来提供对过去交易决策的分析和反思，包括交易决策的正确性评估和改进建议。
    
-   该模块通过图形化表示买卖点和累积回报图，直观展示历史决策的有效性，并通过迭代学习过程，为交易代理提供动态知识库。
    

9.  工具增强的决策制定模块（Tool-Augmented Decision-making Module）：
    

-   该模块整合了市场情报总结、价格变动分析的低级反思和对过去决策的反思。
    
-   它还包括专业投资指导和传统交易策略，如MACD交叉、KDJ与RSI过滤器和均值回归等增强工具。
    
-   决策制定模块采用链式思考（Chain-of-Thought, COT）方法和上下文学习原则，不仅执行交易，还提供决策的理由，确保每个决策都基于对市场动态和上下文知识的全面理解。
    

![](assets/004.png)

  

### **第5章：实验设置 (Experiment Setup)**

本章旨在全面评估FinAgent的交易效果，特别是其在显著减少历史数据训练窗口的同时，如何高效地处理任务。实验还涉及利用多模态数据输入，结合信息和代理辅助增强工具，以及多视角的多样化检索，以提高对市场动态和情绪的理解，实现更全面和逻辑的决策过程，并提供有根据的解释。

-   ### **数据集 (Datasets)**
    

-   实验使用了六个真实世界的数据集进行评估，包括美国股市的五个数据集和一个加密货币数据集。数据集涵盖了不同来源的多种数据形式，包括日常价格数据、视觉数据（历史K线图和交易图表）、每日更新的资产新闻以及金融专家提供的辅助信息。
    

![](assets/005.png)

-   资产价格：包括开盘、最高、最低、收盘和调整收盘价。
    
-   视觉数据：每日的K线图和交易图表，为资产市场数据和交易过程提供视觉表示。
    
-   资产新闻：来自Bloomberg Technology、Seeking Alpha、CNBC Television等多种来源的日常更新，确保了对金融市场的多元化和全面视角。
    
-   专家指导：由金融专家提供的辅助信息，旨在提供对市场状况的全面理解。
    

-   ### **评估指标 (Evaluation Metrics)**
    

-   FinAgent与基线方法在六个财务指标上进行了比较，包括：
    
-   年化收益率（ARR）：衡量投资的平均年化回报率。
    
-   夏普比率（SR）、卡玛比率（CR）、索提诺比率（SoR）：这些风险调整后的收益指标，用于衡量投资组合的风险调整表现。
    
-   最大回撤（MDD）：衡量投资组合从峰值到谷底的最大损失，显示最坏情况。
    
-   波动率（VOL）：衡量投资回报随时间的变化，以标准差表示。
    

-   ### **基线方法 (Baselines)**
    

-   FinAgent的交易性能与四种传统基于规则的交易策略（买入持有B&H、MACD、KDJ&RSI和ZMR）和八种先进算法进行了比较。这些先进算法包括基于机器学习和深度学习的价格预测模型（LGBM、LSTM和Transformer），以及基于深度强化学习的方法（SAC、PPO和DQN），还有基于LLM的方法（FinGPT和FinMem）
    

-   ### **实验细节 (Implementation Details)**
    

-   虽然FinAgent的训练和推理可以在没有GPU的情况下完成，但为了基准测试，实验中使用了单个NVIDIA RTX A6000 GPU。所有基准测试都在相同的RL环境中进行，以确保公平比较。
    

![](assets/006.png)

### **第6章：实验结果 (Experimental Results)**

本章深入探讨了FinAgent与现有基线方法的比较结果，突出了其在多个财务指标上的显著优势，尤其是在盈利能力方面。实验结果显示，FinAgent在所有数据集上均实现了至少36%的平均利润提升，其中在一个数据集上实现了92.27%的回报率，相对提高了84.39%。

此外，FinAgent是首个为金融交易任务设计的高级多模态基础代理，其性能的卓越表现在累计回报上尤为明显，尤其是在TSLA数据集上，有效地对冲了潜在的交易损失并实现了高收益。这一章节还强调了FinAgent在风险控制上的轻微妥协，以实现更高的回报，符合积极投资者的偏好。

  

### **第7章：消融研究 (Ablation Studies)**

通过消融研究深入分析了FinAgent中各个关键组件对整体交易性能的贡献，以及增强工具对交易决策的影响。

### **1\. 各组件有效性 (RQ2)**

本节研究了FinAgent中市场情报（M）、低级反思（L）、高级反思（H）和增强工具（T）四个主要组件对交易性能的影响。研究发现，低级反思模块的加入显著提升了特定资产的年化回报率（ARR%），并降低了风险。例如，在TSLA数据集上，ARR%提升了45.56%，而在ETHUSD数据集上，ARR%提升了101.48%。高级反思模块的引入进一步提高了ARR%和夏普比率（SR），但对TSLA数据集的最大回撤（MDD%）有轻微的负面影响。

![](assets/007.png)

### **2\. 增强工具的有效性 (RQ3)**

在本节中，研究了仅使用增强工具（如作为辅助代理的基于规则的方法）进行决策时的性能。实验结果显示，增强工具在股票投资中可以提升利润，但在加密货币投资中可能导致性能显著下降。例如，在ETHUSD数据集上，仅使用增强工具的ARR%为16%，而买入并持有（B&H）策略的ARR%为29%，这突出了股票特定规则方法在加密货币中的局限性。

### **3\. 多样化检索的有效性 (RQ4)**

本节探讨了FinAgent中多样化检索功能对交易性能的影响。实验比较了开启和不开启多样化检索功能的FinAgent在AAPL数据集上的表现，发现使用多样化检索可以显著提高ARR和SR。此外，通过t-SNE可视化验证了不同检索类型市场情报的明显区分，证明了FinAgent多样化检索方法的有效性。

![](assets/008.png)

  

  

### **第8章：结论和未来工作 (Conclusion and Future Work)**

FinAgent是一个由大型语言模型驱动的金融交易代理，具有高推理能力和良好的泛化性。作为一个多模态代理，FinAgent能够整合文本和视觉数据，全面理解市场动态和历史交易行为。它独立地利用辅助工具对不同时间尺度的市场数据进行详细分析，并通过多视角和多样化的检索方法，有效地识别当前市场状况与过去市场模式和趋势之间的关联，并整合市场信息以做出最终有效的决策。未来的研究将探索将FinAgent应用于其他金融任务，例如投资组合管理，其中LLM用于根据观察到的市场情报对每只股票进行排名，并进行股票选择。

  

**相关代码：**

**main entry：  
**

![](assets/009.png)

**run step：  
**

![](assets/010.png)

  

**论文下载见星球，更多专业研究欢迎加入星球获取**

  

为了感谢支持，发放一些优惠券，加入星球请扫我：

![](assets/011.png)

入群请扫我：![](assets/012.jpg)

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | 清华大学时序卷积模型TimesNet用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484709&idx=1&sn=f462495e96ee99019f83321a84d2fd0a&chksm=ce7e623bf909eb2d3f24882531e2ac8de4459bab71920a5985d7add81731d82d7ba55934bd07&scene=21#wechat_redirect)  
    
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

![](assets/013.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

![](assets/014.jpg)