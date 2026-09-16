# 信息量极高！StockFormer： 基于多任务目标（回归/分类）及高低频分离的选股模型

QuantML QuantML 2024-06-19 22:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484801&idx=1&sn=bb6d765cbd18849b1e1f09f650cbe1e1&chksm=cfb0b5cb77213cfd4600c4d5de1225c372ddf95b53bec54de5268a0f42297055b203cb710357#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484801&idx=1&sn=bb6d765cbd18849b1e1f09f650cbe1e1&chksm=cfb0b5cb77213cfd4600c4d5de1225c372ddf95b53bec54de5268a0f42297055b203cb710357#rd)

Content

### **1\. 引言 (Introduction)**

本文讨论了中国股市的发展和市场结构的复杂性，以及传统量化交易方法面临的挑战。文章介绍了“Stockformer”模型，这是一个基于小波变换和多任务自注意力网络的价格-成交量因子选股模型，旨在提高对市场不稳定性的响应能力和预测精度。模型的创新点包括多因素模型输入、高低频分解、时空编码器和注意力机制、图嵌入技术，以及多任务学习策略。

  

### **2\. 相关工作 (Related Work)**

#### **2.1 因子构建 (Factor Construction)**

-   因子定义：因子是可量化的变量，影响股票回报，包括市场、风格、行业、宏观经济、价格-成交量和机器学习派生因素。
    
-   经典工作：Fama和French的研究引入了市场因素，如超额回报和波动性。
    
-   风格因子：Green等人使用横截面回归研究风格因子，探讨了不同股票类别的相对表现。
    
-   时间变化因子：Fan等人探索了时间变化因子载荷，提高了因子模型适应市场变化的能力。
    
-   Beta调整：Jensen等人讨论了Beta调整股票因子的稳定性，确认了因子回报中的季度和动量效应。
    

#### **2.2 股票回报预测模型 (Stock Return Prediction Models)**

-   降维模型：使用主成分分析（PCA）等技术简化数据集，保留关键信息。
    
-   线性模型：使用带有惩罚项的模型，如LASSO，以减少噪声信息，提高预测精度。
    
-   非线性模型：基于历史数据拟合预测变量和回报之间的非线性结构，使用人工智能算法如随机森林、模糊神经网络和长短期记忆（LSTM）网络。
    

#### **2.3 回测交易策略 (Backtesting Trading Strategy)**

-   回测重要性：回测交易策略是投资过程中不可或缺的一部分，可以评估策略性能和风险管理。
    
-   动态交易策略：Fung和Hsieh提供了对冲基金动态交易策略的经验性检验，建立了回测和评估框架。
    
-   自动化编程：Georgakopoulos展示了自动化编程在回测中的效用，详细说明了从数据获取到策略实施和风险评估的过程。
    
-   量化交易基础：Chan提供了量化交易基础的全面概述，重点关注回测、数据处理和策略执行。
    
-   机器学习与金融回测：De Prado强调了机器学习与金融回测的融合，引入了"样本外"测试以增强策略的稳健性。
    
      
    

### **3\. 预备知识 (Preliminaries)**

#### **3.1 问题定义 (Problem Definition)**

-   股票预测问题：根据投资者采用的具体投资策略，定义了股票预测问题的不同范式。本文采用了面板数据分析方法，这是一种广泛接受的研究领域范例。
    
-   数据整合：整合了多个股票在过去一段时间内的回报、趋势运动和360个价格-成交量因素，以预测未来一段时间内多个股票的回报和趋势运动。
    
-   挑战：准确预测基于在历史数据集X中识别的模式和趋势的未来股票指标ˆY。
    

#### **3.2 自注意力机制 (Self-Attention Mechanism)**

-   自注意力机制：介绍了自注意力机制，这是一种常用于提高股票回报预测准确性的技术，它允许模型捕捉整个输入序列的全局依赖性。
    
-   数学表达：提供了自注意力操作的数学公式，包括查询（Q）、键（K）、值（V）的计算过程和softmax函数的应用。
    

#### **3.3 小波变换 (Wavelet Transform)**

-   小波变换定义：小波变换是一种用于信号分层分解的数学工具，涉及缩放函数和小波函数，通过它们的位移和扩展在信号空间中创建稳定的基础。
    
-   离散小波变换（DWT）：探讨了DWT在金融时间序列（如单一股票的回报序列）中的有效性，用于将回报序列分解为低频和高频组成部分。
    
-   数学表达：给出了DWT的数学表达式，包括低通和高通滤波器的应用，以及如何通过上采样操作和全连接层来处理这些组成部分。
    

###   

### **4\. 方法论 (Methodology)**

#### **4.1 整体模型架构 (Overall Model Architecture)**

-   Stockformer架构：介绍了Stockformer的三个主要组成部分：解耦流层（Decoupling Flow Layer）、双频时空编码器（Dual-Frequency Spatiotemporal Encoder）和双频融合解码器（Dual-Frequency Fusion Decoder）。
    
-   模型输入：模型处理历史股票数据，通过解耦流层将股票回报序列进行小波变换，分离出高频和低频成分。
    
-   模型输出：预测股票的未来回报和趋势，包括使用多任务学习策略同时预测股票回报和趋势。
    

![](assets/001.png)

#### **4.2 解耦流层 (Decoupling Flow Layer)**

-   离散小波变换（DWT）：使用DWT从股票回报序列中提取高频和低频成分，分别代表短期市场波动和长期趋势。
    
-   上采样和全连接层：对低频和高频成分进行上采样，并通过全连接层转换，增强模型的表征能力。
    

#### **4.3 双频时空编码器 (Dual-Frequency Spatiotemporal Encoder)**

-   时间注意力和扩张因果卷积：结合时间注意力模块和扩张因果卷积层来处理不同的时间序列模式。
    
-   时间槽和Struc2Vec图注意力网络：使用时间槽表示时间戳，并通过图嵌入方法来捕获股票之间的复杂关系。
    

![](assets/002.png)

#### 4.3.1 解耦时间特征提取 (Decoupling Temporal Feature Extraction)

-   时间卷积层和时间注意力：利用时间卷积层关注局部模式，而时间注意力捕捉长期趋势。
    

#### 4.3.2 时间槽和Struc2Vec图注意力网络 (Time Slots and Struc2Vec Graph Attention Networks)

-   时间槽：将时间戳分割成时间槽，以捕获每日的周期性变化。
    
-   构建时间图：构建有向时间图，以表示时间槽之间的关系。
    
-   图嵌入：使用Struc2Vec算法计算股票之间的相关性，生成高维图嵌入。
    

#### **4.4 双频融合解码器 (Dual-Frequency Fusion Decoder)**

-   预测器：应用在编码器的输出上，生成多步股票回报和趋势的未来表示。
    
-   融合注意力机制：整合高频和低频信息，以更好地捕捉未来股票回报和内部依赖性。
    

#### 4.4.1 解耦特征融合 (Decoupling Feature Fusion)

-   融合注意力：使用融合注意力机制结合低频和高频成分的信息，以提取有用的长期和短期信息。
    

#### 4.4.2 多监督 (Multi-Supervision)

-   多任务输出：模型输出包括股票回报预测和股票趋势预测概率。
    
-   损失函数：定义了结合回归和分类任务损失的函数，以优化模型的多维预测。
    

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

  

### **5\. 价格-成交量因子的构建 (Construction of Price-Volume Factors)**

#### **5.1 数据来源和股票池选择 (Data Sources and Stock Pool Selection)**

-   股票池：选择了沪深300指数的成分股作为研究对象，这些股票在市场流动性和市值方面表现突出，能够代表A股市场的整体趋势。
    

![](assets/006.png)

#### **5.2 因子构建 (Factor Construction)**

-   Alpha360因子库：利用该库构建了360个价格-成交量因子，这些因子涵盖了价格、成交量和波动性等多个维度，确保了市场信息的全面性。
    
-   因子分类：将因子分为六类，每类包含60个因子，提供了各类别前两个因子的构建方法示例。
    

![](assets/007.png)

#### **5.3 因子中性和因子值预处理 (Factor Neutralization and Factor Value Preprocessing)**

-   预处理步骤：
    

-   处理缺失值：使用前一天的股票信息填充。
    
-   极端值处理：排除超出均值三标准差的数据点。
    
-   标准化：对每个因子序列进行Z分数标准化。
    

-   中性和市场价值中立化：通过行业虚拟变量和市值变量的线性回归，使用回归残差作为中性和市场价值中立化的因子序列。
    

#### **5.4 因子有效性测试 (Factor Effectiveness Testing)**

-   信息系数（IC）：使用斯皮尔曼等级相关系数来计算IC值，评估因子与资产回报之间的相关性。
    
-   IC值分析：提供了对特定时间段内360个价格-成交量因子的IC值的分析，展示了12个特定因子的IC值、标准差、IC值大于0的比例以及IC绝对值大于0.02的比例。
    
-   因子有效性：如果因子的平均IC值大于0.02，则认为该因子有效，并在模型中使用。
    

![](assets/008.png)

  

### **6\. 实验 (Experiments)**

#### **6.1 研究问题 (Research Questions)**

-   论文提出了五个研究问题，旨在评估Stockformer模型在预测股票回报和市场趋势方面的表现，分析模型不同组件的影响，研究超参数对性能的影响，确定在回测阶段使用哪种模型输出，以及评估模型在不同市场条件下的投资策略表现。
    

#### **6.2 实验设置 (Experimental Setup)**

-   数据集：使用了沪深300指数的300支股票的数据，包括股票的回报序列和价格-成交量因子。
    
-   评估指标：包括预测性能评估指标和投资组合性能评估指标，用于全面评估模型在股票市场预测方面的表现。
    
-   基线模型：与多种现有的先进模型进行比较，如XGBoost、LSTM、GRU、ALSTM、TCN、GATs、Transformer和Localformer等。
    
-   **参数设置：**描述了Stockformer模型的实现细节，包括使用的优化器、批量大小、注意力机制的参数、空间时间编码器的层数、学习率和衰减率等
    
-   **计算环境：**提供了模型训练所使用的硬件和软件环境的详细信息。
    

#### **6.3 预测性能比较分析 (Comparative Analysis of Predictive Performance)**

-   对Stockformer模型在14个子数据集上的预测结果进行了详细分析，并与其他基线模型进行了比较，展示了Stockformer在多个关键性能指标上的优越性。
    

![](assets/009.png)

  

#### **6.4 消融研究 (Ablation Study)**

-   通过比较完整的Stockformer模型与其不同变体（如去除某些组件或改变监督信号）的性能，来评估各个组件对模型性能的贡献。
    

![](assets/010.png)

#### **6.5 超参数敏感性分析 (Hyperparameter Sensitivity Analysis)**

-   分析了隐藏层大小、编码器层数、批量大小和分类损失权重等超参数对模型性能的影响。
    

![](assets/011.png)

#### **6.6 回测输入选择 (Backtesting Input Selection)**

-   比较了在回测阶段使用分类输出和回归输出的性能，提供了在不同情况下选择哪种输出的建议。
    

![](assets/012.png)

#### **6.7 策略回测 (Strategy Backtesting)**

-   使用TopK-Dropout策略进行了投资策略的回测，并在不同的市场条件下（如上升趋势、下降趋势和波动市场）评估了Stockformer模型与其他基线模型的表现。
    

#### 6.7.1 Topk-Dropout策略 (Topk-Dropout Strategy)

-   描述了TopK-Dropout策略的步骤和原理，这是一种基于因子值排名的量化选股策略。
    

![](assets/013.png)

  

#### 6.7.2 投资策略回测 (Investment Strategy Backtesting)

-   展示了在不同市场条件下，使用Stockformer模型的投资策略相对于沪深300指数和其他模型的年度化回报、最大回撤和夏普比率等性能指标。
    

![](assets/014.png)

![](assets/015.png)

![](assets/016.png)

![](assets/017.png)

### **7\. 结论和未来工作 (Conclusion and Future Work)**

#### **7.1 结论 (Conclusion)**

-   模型贡献：Stockformer模型通过整合小波变换和多任务自注意力网络，提高了分析全球证券市场复杂动态的精度和适应性。
    
-   数据挖掘：模型深入挖掘了沪深300指数成分股的数据，并使用了360个经过严格测试的价格-成交量因子，显著提升了对市场波动和突发事件的解释能力。
    
-   技术应用：应用了先进的深度学习技术，包括双频时空编码器、图嵌入技术和多任务学习策略，这些技术不仅提高了股票回报和市场趋势预测的准确性，还增强了模型对市场动态细节的检测能力。
    
-   实验结果：实验结果显示，Stockformer在多个预测性能指标上超越了十种基线模型，特别是在方向准确率达到57.46%，显著高于其他模型。
    
-   回测结果：在不同市场条件下的回测结果表明，基于Stockformer的选股模型在上升、下降和波动市场中都取得了稳定的超额回报，并且在风险控制方面表现出色。
    
-   决策支持：Stockformer为金融市场分析师提供了一个有价值的决策支持工具，帮助他们在动荡的市场环境中做出更明智的投资决策。
    

#### **7.2 未来工作 (Future Work)**

-   参数优化：尽管Stockformer模型在股票市场应用中取得了显著成果，但未来研究仍面临挑战和机遇。首先，模型使用的波浪变换涉及多个复杂参数设置，如周期尺度和变换深度，这些参数的确定既耗时又需要重复实验。未来的工作将探索如何在神经网络架构内自动识别和优化这些周期参数，以减轻初步数据处理的负担。
    
-   动态股票池：当前模型基于静态的沪深300股票池。然而，股票池的动态性是股票市场的基本特征，使用固定股票池可能限制了模型的适用性和预测精度。因此，计划开发动态更新机制，使Stockformer能够适应股票池的变化，从而提高其预测的精度。
    
-   新股票适应性：随着新股票的不断引入，模型需要能够快速适应这些变化。为此，计划采用元学习方法来增强模型的适应性，使其在未知市场条件下保持高效的预测能力。
    
-   改进目标：通过这些改进，Stockformer将更好地服务于金融市场分析师，帮助他们在动荡的市场环境中做出更精确的决策。
    

  

  

**论文、数据及代码下载见星球**  

  

  

加入星球请扫我：

![](assets/018.jpg)

  

  

  

入群请扫我：  

![](assets/019.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
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

![](assets/020.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/021.jpg)