# LLMFactor ：大模型结合SKGP提供可解释的股价预测

QuantML QuantML 2024-07-07 20:53 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485339&idx=1&sn=e4f4f5dceaf6d660628b771ab88f0da5&chksm=cfc0f52252a3661068880822d69d46ad09d8985063f00aa8c7c38b362ae78cef9bba7d44ba6c#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485339&idx=1&sn=e4f4f5dceaf6d660628b771ab88f0da5&chksm=cfc0f52252a3661068880822d69d46ad09d8985063f00aa8c7c38b362ae78cef9bba7d44ba6c#rd)

Content

  

本文介绍了一个名为 LLMFactor 的新框架，该框架使用大型语言模型（LLMs）通过顺序知识引导提示(SKGP)来提取影响股票走势的因素，并提供可解释的股票运动预测。

![](assets/001.png)

  

### **1\. 引言 (Introduction)**

-   介绍了人工智能（AI）在金融领域的应用，特别是预测股票走势的重要性。
    
-   讨论了有效市场假说（EMH）及其局限性，以及如何通过识别市场效率的偏差来寻求超额回报。
    
-   强调了新闻报道、公司间关系和行业间联系在理解市场动态中的重要性。
    
-   提出了使用“因素”来增强股票运动预测的新任务，并介绍了 LLMFactor 框架的概念。
    

### **2\. 相关工作 (Related Work)**

相关工作涵盖了以下三个主要领域：

1.  使用文本数据预测股票走势 (Stock Movement Prediction using Textual Data)
    

-   介绍了自然语言处理（NLP）技术在预测股票市场趋势方面的应用。
    
-   举例说明了如何使用推文和历史价格数据进行时间依赖性预测。
    
-   讨论了多模态数据（如金融文本数据和增强型股票相关性）的建模方法。
    
-   强调了从文本数据中提取更细粒度的洞察力的重要性，比如识别公司事件作为股票运动的驱动力，以及媒体情绪与市场回报之间的显著关联。
    

3.  使用 LLMs 进行时间序列预测 (Time-series Forecasting with LLMs)
    

-   描述了大型预训练变换器（如 GPT 变体）的构建和它们丰富的知识库。
    
-   指出了这些模型在分析时间序列数据方面的局限性，并讨论了如何调整 LLMs 以提高其在时间序列预测方面的能力。
    
-   提到了使用提示方法将数值输入输出转换为文本提示，从而将预测任务框架为句子到句子的转换。
    

5.  提示工程 (Prompt Engineering)
    

-   讨论了通过精心设计的提示使 LLMs 有效处理各种任务的挑战。
    
-   介绍了不同的提示策略，如链式思维（CoT）方法、生成知识提示技术和检索增强生成（RAG）技术。
    
-   这些技术启发了本研究提出的顺序知识引导提示（SKGP）策略，旨在提高金融预测的准确性。
    

### **3\. LLMFactor 框架 (LLMFactor)**

本章详细介绍了 LLMFactor 框架，这是一个创新的系统，旨在通过大型语言模型（LLMs）提取影响股票市场动态的有利因素，并提供可解释的股票走势预测。

### **3.1 任务定义 (Task Definition)**

任务定义部分明确了 LLMFactor 框架的目标：预测特定股票（stocktarget）在目标日期（datetarget）的价格走势。该任务利用与股票相关的新闻（newstarget）和历史股价序列（P），将股票价格序列转换为股票走势的二元表示（ˆP），其中上升用 1 表示，下降用 0 表示。目标是基于给定的日期、新闻和历史走势序列来预测下一个时间点的股票价格是上升还是下降。

### **3.2 顺序知识引导提示 (Sequential Knowledge-Guided Prompting, SKGP)**

SKGP 是 LLMFactor 框架的核心策略，分为三个主要阶段：

![](assets/002.png)

####     **3.2.1 匹配和获取新闻背景知识**

    第一阶段涉及匹配股票与相关新闻，并获取背景知识。通过使用填空提示（fill-in-the-blank）技术，LLMs 被引导生成与股票相关的背景知识，例如公司之间的关系。这一步骤对于理解新闻内容和预测股票走势至关重要。

####     **3.2.2 生成可能影响股票价格的因素**

    第二阶段是从未加工的新闻中提取可能影响股票价格的关键因素。与传统的关键词提取或情感分析不同，这一阶段的目的是提取与股票市场动态更直接相关的因素，这些因素对于预测股票价格走势具有更高的解释性和可读性。

####     **3.2.3 预测股票价格走势**

    第三阶段结合了前两步中提取的背景知识和因素，以及历史股票价格数据，来预测股票的未来走势。通过将时间序列数据转换为文本格式，LLMs 能够根据这些信息预测股票价格的上升或下降，并提供预测的理由。

### **3.3 股票市场中的因素分析 (Factor Analysis in the Stock Market)**

因素分析部分展示了如何将 SKGP 技术应用于股票市场，以及如何利用提取的因素来提供对股票市场趋势的深入见解。例如，通过分析 Nvidia 股票价格的趋势，LLMFactor 能够识别出影响股价的关键因素，如“Nvidia 股票在一月份的收益”、“新产品公告”和“EV制造商选择 Nvidia Drive Thor”。

### **4\. 实验 (Experiments)**

本章是关于LLMFactor框架的实验评估，旨在验证其在股票市场预测方面的有效性和准确性。

### **4.1 数据集 (Datasets)**

实验使用了四个基准数据集来评估LLMFactor框架的性能，包括：

-   StockNet：包含87个美国股市股票，以及相关的推文和2014年至2016年间的历史价格数据。
    
-   CMIN-US：涵盖美国股市前110支股票，以及2018年至2021年间的推文和历史价格数据。
    
-   CMIN-CN：包含中国股市CSI300指数中的300支股票，以及同期的推文和历史价格数据。
    
-   EDT：包含从2020年至2021年间的54,080篇新闻文章，以及相关的美国股市股票和价格信息。
    

![](assets/003.png)

### **4.2 评估指标 (Evaluation Metrics)**

使用了以下两个主要评估指标来衡量预测模型的性能：

-   准确率（Accuracy, ACC）：预测正确的样本数占总样本数的比例。
    
-   马修斯相关系数（Matthews Correlation Coefficient, MCC）：衡量分类模型的平衡性和准确性的指标。
    

### **4.3 基线模型 (Baselines)**

实验中对比了多种基线模型，包括：

-   基于关键词的模型：如PromptRank、KeyBERT、YAKE、TextRank等，这些模型通过提取文本中的关键词来预测股票走势。
    
-   基于情感的模型：如EDT、FinGPT、GPT系列模型等，这些模型通过分析文本的情感倾向来预测股票市场。
    
-   基于时间序列的模型：如CMIN和StockNet，这些模型结合了文本和时间序列数据来预测股票走势。
    

### **4.4 实施细节 (Implementation Details)**

详细介绍了实验的实施过程，包括：

-   数据集的划分方法。
    
-   关键词提取和情感分析的具体实现。
    
-   使用的预训练模型，如gpt-3.5-turbo、gpt-4等，以及它们的参数设置。
    

### **4.5 结果 (Results)**

展示了LLMFactor和其他基线模型在四个数据集上的性能对比结果。LLMFactor在所有评估方法上均优于其他方法，特别是在MCC指标上，显示出其在预测准确性和解释性方面的优势。

![](assets/004.png)

![](assets/005.png)

![](assets/006.png)

  

### **4.6 数据分析 (Data Analysis)**

####     **4.6.1 消融研究 (Ablation Study)**

    通过消融研究来评估LLMFactor中每个组成部分的贡献。研究发现，提取的因素层对整体性能的提升最为显著。

####     **4.6.2 案例研究 (Case Study)**

    通过具体案例展示了LLMFactor在实际股票市场分析中的应用效果。例如，分析了苹果公司和特斯拉公司的股价变动，展示了LLMFactor如何结合公司背景知识、历史新闻和价格数据来提供股价变动的解释。

### **5\. 结论 (Conclusion)**

LLMFactor利用顺序知识引导提示（Sequential Knowledge-Guided Prompting, SKGP）策略，成功地集成了背景知识、股票相关因素和时间数据，以预测股票走势。通过在四个基准数据集上的严格测试，LLMFactor证明了其在准确性和解释性方面优于依赖关键词、情感分析和多模态数据输入的最新技术（state-of-the-art, SOTAs）。此外，本研究还指出了三个主要局限性，并对未来的研究方向提出了展望，包括改进时间数据到文本格式的转换方法、提高实验结果的可复制性，以及评估不同长度和类型文本中提取因素的质量。

  

  

  

  

**论文下载见星球，更多专业研究欢迎加入星球获取**

**欢迎专业人士投稿，分享知识同时获取收益。**  

  

加入星球请扫我：

![](assets/007.jpg)

入群请扫我：![](assets/008.jpg)

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)  
    
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
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [如何使用强化学习筛选因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485027&idx=1&sn=fd7db21edfc2eabd5554d08b7fbd9df1&chksm=ce7e617df909e86be3837e0a5236e6e58ff7e195cd6fc15c48edc26a438f6c710044e9e37bc3&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
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