# FinRobot：用于金融领域的大模型AI平台

QuantML QuantML 2024-06-04 22:15 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=cfd1ac5f60d995c38772e5b6fe22113dd95fc57b307299a28350bfb1f277af741ece3856414c#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=cfd1ac5f60d995c38772e5b6fe22113dd95fc57b307299a28350bfb1f277af741ece3856414c#rd)

Content

  

这篇论文介绍了一个名为FinRobot的开源AI代理平台，它利用大型语言模型（LLMs）来支持金融应用。

### **摘要（Abstract）**

-   论文讨论了大型语言模型（LLMs）在金融领域的整合使用，以及金融界与AI社区之间存在的障碍。
    
-   作者提出了FinRobot平台，这是一个开源的AI代理平台，支持多种金融专业AI代理，每个代理都由LLM驱动。
    
-   平台由四层组成：金融AI代理层、金融LLM算法层、LLMOps和DataOps层、多源LLM基础模型层。
    
-   FinRobot旨在为专业分析师和普通用户提供高级金融分析的AI技术。
    
    ![](assets/001.png)
    

### **第1章：引言（Introduction）**

-   讨论了金融分析的重要性，包括市场趋势解释、经济预测和投资策略提供。
    
-   介绍了基于AI的金融分析的革命性变化，以及LLMs如何增强AI的功能。
    

### **第2章：相关工作（Related Work）**

-   讨论了基于LLM的AI代理在多个领域的应用。
    
-   特别强调了金融AI代理，如FinAgent和FinMem，它们利用实时市场数据进行决策。
    
-   探讨了开源AI代理框架的发展，以及AI4Finance Foundation在推动开源文化方面的作用。
    

### **第3章：FinRobot概览（Overview of FinRobot）**

FinRobot被设计为一个分层的系统，每一层都针对金融AI处理和应用的特定方面。

![](assets/002.png)

### **3.1 金融AI代理层（Financial AI Agents Layer）**

这一层由特定领域的AI代理组成，旨在通过先进的数据感知、认知处理和动态行动执行来增强金融分析：

-   感知（Perception）：该模块捕获并解释来自市场信息、新闻和经济指标的多模态金融数据，使用复杂技术将数据结构化以供深入分析。
    
-   大脑（Brain）：作为核心处理单元，该模块使用LLM感知来自感知模块的数据，并利用金融思维链（CoT）过程生成结构化指令。
    
-   行动（Action）：该模块执行来自大脑模块的指令，应用工具将分析洞察转化为可操作的结果，如交易、投资组合调整、生成报告或发送警报。
    

### **3.2 金融LLM算法层（Financial LLMs Algorithms Layer）**

这一层包含针对金融行业特定需求而设计的先进AI算法，增强了平台在一系列金融应用中的能力：

-   金融大型语言模型（FinGPT）：专为金融领域设计的LLM，通过监督式微调，以金融领域的指令响应数据对开源大型语言模型进行优化。
    
-   金融强化学习（FinRL）：使用集成深度强化学习算法优化交易策略，分析历史和实时市场数据。
    
-   金融机器学习（FinML）：利用多种机器学习技术来提高金融预测分析的能力。
    
-   金融多模态LLM：处理并综合来自多种模态（如文本、图表和表格）的信息，提供全面深入的金融文档理解。
    

### **3.3 LLMOps层（LLMOps Layer）**

LLMOps层旨在实现高模块化和可插拔性，以适应技术进步和金融市场需求的演变：

-   智能调度器（Smart Scheduler）：优化任务分配，包括任务管理、代理注册、代理适配器和主管代理等组件，确保任务根据代理的性能指标和特定任务的适用性进行分配。
    
    ![](assets/003.png)
    

### **3.4 数据操作层（DataOps Layer）**

数据操作层管理金融分析所需的广泛和多样化的数据集，确保输入AI处理管道的所有数据都是高质量和代表当前市场状况的：

-   检索增强生成（RAG）：结合了上下文检索机制和LLMs的优势，优化语言生成任务。
    

### **3.5 多源LLM基础模型层（Multi-source LLM Foundation Models Layer）**

这一层为FinRobot提供了管理和整合多种大型语言模型（LLMs）的高级功能，这对于适应全球金融市场的动态需求至关重要：

-   即插即用功能：允许无缝集成和更新通用和专业LLMs。
    
-   模型多样性和评估：整合了参数范围从7亿到72亿的LLMs，针对特定金融任务进行了严格评估。
    
-   全球市场兼容性：支持多语言模型集成，增强了平台分析和处理多样化金融数据的能力。
    

### **第4章：金融思维链（Financial Chain-of-Thought）提示技术**

详细介绍了金融思维链（Financial Chain-of-Thought，简称CoT）提示技术及其在FinRobot平台中的应用。

### **4.1 CoT提示技术介绍**

-   概念：CoT提示技术是一种结构化提示方法，旨在通过鼓励AI模型逐步推理来增强其在复杂推理任务上的表现。这种方法通过引导模型明确展示推理的中间步骤，从而提高答案的准确性和可解释性。
    
-   应用：CoT技术已被证明在数学问题解决和常识推理等任务上非常有效。
    

### **4.2 金融CoT提示的概念**

-   定义：金融CoT提示是将CoT技术应用于AI驱动的金融分析，它模仿金融专业人员处理复杂金融问题时的思维过程。
    
-   作用：该技术通过将复杂金融场景分解为更小、更易于管理的部分，然后分析每个部分并综合结果来形成结论或建议。
    

### **4.3 金融CoT提示的实施**

-   财务分析：FinRobot使用CoT提示来超越基本的数据列举和比率计算，通过比较分析和历史表现对比，提供深入的业务洞察。
    
-   业务特定分析：FinRobot利用检索增强生成（RAG）技术来收集有关公司产品与服务的数据，提供全面的业务分析。
    
-   市场分析：FinRobot结合财务比率、市场数据、新闻情绪和网络数据，模拟市场参与者的决策过程，提供公司股价轨迹和估值的综合评估。
    
-   估值分析：FinRobot整合了财务比率、市场数据、新闻情绪和网络数据的分析，使用LLMs评估公司股价轨迹和估值。
    

### **4.4 金融CoT提示的优势**

-   灵活性：与依赖固定模板的数据提供商不同，CoT提示利用LLMs的生成性质，不依赖于死板的模板。
    
-   错误检查：通过多层提示嵌入错误检查，减少误分类的风险。
    
-   简化人工劳动：通过将投资逻辑编码到推理过程中，简化了人工劳动。
    
-   提取信息：能够从复杂且非结构化的数据格式（如收益电话会议记录）中提取相关的历史数字和定性信息。
    
-   解释性：提供对记录和派生值的来源和推导的详细解释。
    
-   适应性和发展性：随着LLMs的持续改进和指令调整，CoT提示可以适应并发展其应用。
    

### **4.5 市场模拟：超越分析师模仿**

-   概念：市场模拟是通过将GPT模仿人类分析过程的能力作为探索更广泛市场动态的门户，它通过结合类似人类的推理过程来超越纯粹的数值分析。
    
-   实现：构建详细的模拟环境，让代表不同市场参与者的生成代理在金融背景下进行互动，每个代理的决策过程由数据驱动的提示引导，模仿人类分析师可能采取的认知步骤。
    

### **第5章：演示应用和实践教程（Demo Applications and Hands-on Tutorial）**

本章展示了FinRobot平台的两个实际应用案例，并提供了互动教程，以展示如何使用这个平台进行金融分析和预测。

### **5.1 应用案例I：市场预测器（Market Forecaster）**

-   功能：市场预测器是一套AI代理，旨在综合最新的市场新闻和金融数据，提供对公司最新成就和潜在问题的全面洞察，并预测股价走势。
    
    ![](assets/004.png)
    
-   应用：作为一个初级的机器人顾问，市场预测器展示了AI在金融咨询领域的应用潜力。
    
-   示例：提供了针对特定公司（如Nvidia和贵州茅台）的市场预测示例，展示了如何根据公司的相关新闻、财务状况和市场趋势来分析积极的发展因素和潜在的担忧，并据此预测未来一周的股价变动。
    
      
    
    ![](assets/005.png)
    

### **5.2 应用案例II：文档分析与报告生成（Document Analysis & Generation）**

-   文档分析：AI代理结合先进的LLMs，用于深入分析财务文件，如年报、SEC文件和收益电话会议记录，提取关键信息，识别主要的财务指标，并突出显示需要进一步审查的趋势和差异。
    
-   报告生成：在分析阶段之后，相同的AI代理被用来生成全面的财务报告，这些报告涵盖了财务分析的各个方面，包括绩效评估、市场比较和前瞻性财务预测。
    
-   效果：展示了由FinRobot生成的股权研究报告样本，证明了平台在实际金融分析中的应用和有效性。
    

### **第6章：结论（Conclusion）**

-   FinRobot通过集成多源LLMs到开源平台中，增强了金融操作的可访问性、效率和透明度。
    
-   论文指出FinRobot不仅加速了金融AI社区的创新，还为AI在金融领域的应用设定了新的标准。
    

  

论文及代码下载见星球

  

  

目前距离星球下次提价还有不到20个名额，欢迎扫码加入：

![](assets/006.png)

  

  

入群请扫我：  

![](assets/007.jpg)

  

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

![](assets/008.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/009.jpg)