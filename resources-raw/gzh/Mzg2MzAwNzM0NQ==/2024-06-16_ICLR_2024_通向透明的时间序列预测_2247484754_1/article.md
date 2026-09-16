# ICLR 2024 | 通向透明的时间序列预测

QuantML QuantML 2024-06-16 22:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=cfee773871bfb873e1fa78af9dcaaa4ad028c6160f7b193917077c403613847624959c6427d3#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=cfee773871bfb873e1fa78af9dcaaa4ad028c6160f7b193917077c403613847624959c6427d3#rd)

Content

**摘要**  

本文强调了在高风险领域（如医疗保健、金融和刑事司法）中，可解释的机器学习（ML）模型对于确保决策系统的信任至关重要。时间序列预测在透明性方面面临独特挑战，传统的自下而上方法（关注特定时间点的值）无法全面理解整个时间序列。作者提出了一种自上而下的双层透明度框架，以理解预测时间序列的高层次趋势和低层次属性。开发了TIMEVIEW，这是一个基于静态特征的时间序列预测的透明ML模型，并配有交互式可视化工具。通过一系列实验，证明了该方法的有效性和可解释性，为ML在各个领域的更透明、更可靠的应用铺平了道路。

![](assets/001.png)

  

### **第1章 引言**

-   解释了为什么需要透明的模型，特别是在高风险决策场景中。
    
-   讨论了现有的透明ML模型，如线性/逻辑回归、广义可加模型和决策树，它们不适用于时间序列预测。
    
-   强调了自下而上方法在理解时间序列预测方面的局限性，并提出了自上而下的方法来理解整个时间序列。
    

![](assets/002.png)

### 

### **第2章 时间序列预测的透明度**

本章主要讨论了时间序列预测中透明度的概念，并提出了一种新的自上而下的方法来增强对整个时间序列轨迹的理解。

### **2.1 设置**

-   时间序列预测定义：作者首先定义了时间序列预测模型，将其视为将输入空间 𝑋X 的样本映射到输出空间 𝑌Y 的函数 𝑓f，其中 𝑌Y 是轨迹的空间。轨迹是定义在时间点集合 𝑇T 上的函数。
    

### **2.2 透明度的定义**

-   透明度的一般定义：ML模型如果能够理解输入对预测的影响，则被认为是透明的。这对于反事实推理（例如，“如果患者是女性，模型会预测什么？”）或检测异常（例如，“为什么患者年龄从64岁变为65岁时，模型会赋予显著更高的风险评分？”）至关重要。
    

### **2.3 自下而上方法的局限性**

-   当前XAI方法：现有的可解释人工智能（XAI）技术通常关注于输入对特定时间点 T 的的影响。这些方法被称为自下而上方法，因为它们通过观察个别时间点的值来理解轨迹。
    
-   与人类理解方式的不一致：人类通常通过趋势而不是个别值来理解轨迹，例如通过线图。自下而上的方法与人类自然理解轨迹的方式不一致。
    
-   增加的认知负担：随着想要更好地理解轨迹，自下而上的方法需要越来越多的值，这增加了人类解释者的认知负担。
    
-   不适合全局特征：自下而上的方法可能在只对特定时间点感兴趣时足够，但通常需要一次性理解整个轨迹。
    

![](assets/003.png)

### **2.4 自上而下的新方法**

-   新方法的动机：作者提出了一种自上而下的方法来理解轨迹，这种方法更符合人类描述轨迹的自然方式，即通过趋势和属性而不是单独的值。
    
-   趋势和属性的理解：自上而下的方法侧重于理解轨迹的趋势（例如，“增加”、“减少”）和属性（例如，“在过去10年中”、“低于100mg/dl”）。
    
-   与科学分析方法的兼容性：自上而下的方法不仅与人类理解轨迹的方式一致，也与科学分析方法兼容，例如在动态系统中理解分叉点。
    

### **2.5 双层透明度**

-   双层透明度的定义：作者提出了双层透明度的概念，即模型能够理解输入对轨迹趋势的影响（第一层），以及输入对给定趋势属性的影响（第二层）。
    
-   透明度的具体化：通过双层透明度，作者细化了透明度的定义，并特别针对时间序列预测进行了调整。
    

  

### **第3章 基于静态特征的时间序列预测**

本章详细介绍了基于静态特征的时间序列预测问题，并提出了TIMEVIEW模型来解决这一问题。静态特征指的是那些在时间序列预测中不随时间变化的属性，如医学中的患者基本信息。作者指出，现有的时间序列预测模型往往无法充分解释输入特征如何影响整个时间序列的预测结果，这限制了模型在高风险领域的应用。为了克服这一挑战，TIMEVIEW模型采用了双层透明度框架，通过理解高层次的时间序列趋势和低层次的属性变化，提供了一种全新的视角来增强模型的可解释性。TIMEVIEW模型基于B-样条基函数构建，能够捕捉时间序列的局部变化，并通过交互式可视化工具，允许用户直观地探索不同输入特征对预测轨迹的影响。此外，作者还讨论了TIMEVIEW模型在金融、医学和药理学等领域的潜在应用，强调了其在提高决策透明度和可信度方面的重要性。

  

### **第4章 模式和组合**

本章深入探讨了如何形式化时间序列预测中的趋势概念，提出了一种基于"模式"和"组合"的新方法来理解和解释时间序列模型的行为。

作者首先定义了"模式"（Motif），这是一种描述时间序列在特定区间内形状的二元关系，例如上升、下降或恒定。接着，作者引入了"组合"（Composition）的概念，它是由一系列模式组成的序列，用于表示时间序列在整个预测区间内的趋势变化。例如，一个先上升后下降再上升的时间序列可以表示为(i, d, i)的组合。

为了确保这种表示方法的实用性，作者提出了"兼容性"（Compatibility）的概念，确保对于每个可能的预测轨迹，都能唯一地分配一个组合。此外，作者还定义了"组合映射"（Composition map），这是一个将输入特征映射到其对应的时间序列组合的函数，这对于实现模型的双层透明度至关重要。

作者进一步讨论了如何从预测的轨迹中提取组合，这涉及到对每个区间的模式进行识别和连接，以及如何处理连续区间中的相同模式以简化组合。此外，还介绍了如何使用动态模式来实现双层透明度，这些模式基于时间序列的一阶和二阶导数，能够捕捉到局部极值和拐点等关键特征。

最后，通过数学定义和示例，提供了一种新的视角来理解和解释时间序列预测模型的行为，为实现TIMEVIEW模型的透明度和可解释性奠定了理论基础。

![](assets/004.png)

### 

### **第5章 TIMEVIEW**

本章详细介绍了TIMEVIEW模型的架构和实现，这是一个为时间序列预测设计的透明机器学习模型，专注于基于静态特征的预测。TIMEVIEW模型采用B-样条基函数构建预测轨迹，利用一个编码器将静态特征映射到描述时间序列的系数向量。该模型通过一个全连接神经网络实现编码器，包括dropout和批量归一化技术，以提高模型的泛化能力和稳定性。

作者提出了一种基于启发式算法选择结点的方法，以适应不同数据集的需要，并保持模型的解释性。TIMEVIEW模型的训练过程通过最小化均方误差损失和L2正则化项来优化，使用梯度下降法进行。此外，第五章还描述了TIMEVIEW模型如何通过计算组合映射来实现双层透明度，即理解输入特征如何影响时间序列的趋势和属性。

为了增强模型的可解释性，作者开发了一个交互式可视化工具，允许用户通过动态图表探索预测轨迹及其对输入特征变化的响应。这种可视化方法不仅展示了时间序列的整体趋势，还突出显示了关键的转换点，如局部最大值和最小值，使用户能够深入理解模型的预测行为。

最后，通过一系列实验验证了TIMEVIEW模型与现有方法相比在性能和可解释性方面的优势。实验结果表明，TIMEVIEW在保持透明性的同时，仅在性能上有轻微的折损，证明了其在实际应用中的潜力。这一章节为读者提供了TIMEVIEW模型的全面视角，包括其设计理念、技术细节和实际效果。

![](assets/005.png)

  

### 

### **第6章 相关工作**

本章对TIMEVIEW模型与机器学习领域中其他相关工作的关系进行了深入探讨。作者首先回顾了适用于静态预测的传统透明模型，如线性/逻辑回归、评分系统、决策树/规则列表以及广义可加模型（GAMs），这些方法虽然可以扩展到时间序列预测，但通常在性能上有所欠缺。接着，论文讨论了封闭形式表达式，包括符号回归和通过算法发现的常微分方程（ODEs）和偏微分方程（PDEs），这些方法试图从数据中挖掘数学公式，但并不总是能保证双层透明度。

此外，本章还涵盖了时间序列的特征重要性方法，指出现有技术通常采用自下而上的方法，关注于单个预测时间点的特征重要性，而没有全面考虑整个时间序列的输出。作者对比了TIMEVIEW模型与这些方法的不同，强调了TIMEVIEW在提供全面理解时间序列预测方面的优势。

最后，本章还简要介绍了形状发现（shapelets）和模式（motifs）方法，这些方法通常用于时间序列的分类和数据挖掘任务，与TIMEVIEW关注整个时间序列预测的方法有所不同。通过这些讨论，第六章为TIMEVIEW模型在时间序列预测领域的研究和应用提供了更广泛的背景和定位。

  

### **第7章 TIMEVIEW在行动**

本章展示了TIMEVIEW模型的实际应用能力，通过一系列实验验证了其在时间序列预测任务中的有效性和可解释性。本章首先介绍了TIMEVIEW如何回答XAI问题库中的“如果”、“如何成为”和“如何仍然是”等问题，这些问题涉及到模型预测的透明度和可解释性。接着，通过可视化工具，作者展示了TIMEVIEW如何允许用户通过滑动条和2D等高线图来探索和理解单个或多个特征变化对预测轨迹的影响。

在实验部分，TIMEVIEW与其他透明方法（如线性回归、决策树和GAMs）以及封闭形式表达式方法（如符号回归和ODE发现）进行了比较。实验使用了包括真实世界数据集（如Airfoil、flchain、Stress-Strain和Tacrolimus）和合成数据集（如Sine、Beta和Tumor）来评估不同方法的性能。结果显示，TIMEVIEW在大多数数据集上的性能优于透明方法，并且与黑盒模型的性能相当，证明了其在保持模型透明度的同时，也能提供可接受的预测精度。

此外，本章还讨论了TIMEVIEW对不同数量基函数的敏感性，并提供了计算时间的比较，显示TIMEVIEW的训练和预测过程在计算上是高效的。最后，作者讨论了TIMEVIEW的局限性和未来的挑战，包括将模型扩展到包含时间序列本身的输入、改进轨迹表示方法、正则化策略以及如何更好地整合先验知识等。这一章节为TIMEVIEW模型的进一步研究和应用提供了实证基础和发展方向。

![](assets/006.png)

  

### **第8章 讨论和结论**

-   讨论了TIMEVIEW的应用前景，以及如何将双层透明度和数学框架应用于未来的可解释人工智能（XAI）方法。
    
-   指出了TIMEVIEW的局限性和未来的挑战，并强调了在高风险领域部署模型之前的严格审查的重要性。
    

  

  

**论文及代码下载见星球**  

  

  

加入星球请扫我：

![](assets/007.jpg)

  

  

  

入群请扫我：  

![](assets/008.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
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

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)