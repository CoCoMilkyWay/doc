# 普林斯顿&amp;牛津大学 | 大模型在金融领域的应用、前景和挑战

QuantML QuantML 2024-06-27 17:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=cf8c18b09063bed78f77f2f612029d249ea8a37310cd78fbee5b3b1a2b7d18d4dc2827de7817#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=cf8c18b09063bed78f77f2f612029d249ea8a37310cd78fbee5b3b1a2b7d18d4dc2827de7817#rd)

Content

  

> 论文链接：\[2406.11903\] A Survey of Large Language Models for Financial Applications: Progress, Prospects and Challenges (arxiv.org)
> 
> https://arxiv.org/abs/2406.11903

![](assets/001.png)

本文作者来自普林斯顿和牛津大学。论文全面探讨了大语言模型（LLMs）在金融领域的应用，包括它们的进步、前景和挑战。

  

### **1\. 引言 (Introduction)**

引言介绍了金融领域的复杂性和技术融合的重要性，并强调了大型语言模型（LLMs）在金融领域应用的潜力和优势。同时，它概述了LLMs在金融分析中的多种用途，如情感分析、时间序列预测和金融推理，并指出了在金融领域应用LLMs时面临的挑战，如数据问题、建模问题、基准测试和伦理问题。此外，引言部分还回顾了相关研究，指出了现有文献的不足，并提出了本研究旨在填补的空白，即提供对金融领域LLMs应用的全面审视，并为未来的研究和实践提供指导。

![](assets/002.png)

![](assets/003.png)

  

  

### **2\. 模型 (Models)**

本章深入探讨了大型语言模型（LLMs）在金融领域的应用，包括模型的分类、优势、以及它们如何适应金融任务的特定需求

![](assets/004.png)

  

2.1 模型集合 (Collections of Models)

-   本章介绍了几种主要的通用和金融领域特定的大型语言模型。例如，GPT系列模型以其自注意力机制和位置嵌入捕捉文本中的长距离依赖性而闻名。Ploutos是基于GPT-4的金融LLM框架，它通过整合多模态数据和历史股票数据来提高预测的准确性和可解释性。
    
-   BERT模型通过其深度双向架构，能够学习上下文表示，从而在金融文本上进行了持续预训练，产生了如FinBERT-19、FinBERT-20和FinBERT-21等金融领域特定变体。这些模型通过在金融语料库上的预训练，增强了对金融文本的情感分析能力。
    
-   T5模型，即Text-to-Text Transfer Transformer，是一个统一框架，将所有文本处理任务视为“文本到文本”的问题。BBT-FinT5是为中国市场定制的T5变体，它结合了知识增强的预训练方法。
    
-   ELECTRA模型引入了生成器-鉴别器框架，用于预训练语言模型。FLANG是基于ELECTRA的金融领域变体，它通过选择性标记掩蔽和跨度边界目标来处理金融语言的复杂性。
    
-   BLOOM是一个基础的多语言LLM，支持多种语言。BloombergGPT和XuanYuan 2.0是从BLOOM衍生出来的，专注于金融应用的模型。
    
-   Llama系列模型提供了不同大小的灵活性，并且在大多数基准测试中表现优于更大的模型。Llama的金融变体，如FinMA、Fin-Llama、Cornucopia – Chinese等，为各种金融任务提供了专业能力
    

2.2 零样本学习与微调 (Zero-shot vs Fine-tuning)

-   本章讨论了LLMs在应用中的两种不同适应方法：零样本学习和微调。零样本学习允许模型基于其现有的知识和泛化能力来预测或执行未明确训练的任务。微调则是在特定数据集或特定任务上调整预训练模型以提高其准确性和性能。论文还介绍了一些提高微调效率的技术，如指令调整、低秩适应（LoRA）和量化LLMs。
    

  

2.3 为什么在金融中应用LLMs (Why Applying LLMs in Finance)

-   这部分深入探讨了在金融分析中应用LLMs的原因，强调了它们在金融领域的一般和特定优势。LLMs在理解复杂的金融术语、行话和细微表达方面具有先进的上下文理解能力。它们在预训练阶段就对大量互联网文本进行了学习，这为它们提供了广泛的语言理解能力，可以针对特定的金融任务进行微调，减少了对大型领域特定数据集的依赖。
    
-   LLMs还表现出可扩展性，能够快速处理大量文本，为金融决策者提供即时洞见。此外，LLMs的多模态能力使它们能够整合各种数据源，如新闻文章的文本、财务报表的数字数据和市场图表的视觉数据。LLMs的可解释性也为金融应用中的透明度和信任度提供了增强。
    
-   最后，LLMs的定制化能力使它们能够适应特定的金融工具或市场条件，通过整合领域特定数据和参数，LLMs可以被训练以专注于金融市场的特定方面
    
      
    

### **3\. 应用 (Applications)**

本章通过深入分析LLMs在金融领域的各种应用，展示了它们如何转变金融分析的实践，并提供了对未来研究方向的见解。这些应用不仅覆盖了金融分析的传统领域，还探索了新兴的领域，如基于代理的建模和实时金融推理，为金融领域的创新提供了新的机会

3.1 语言任务 (Linguistic Tasks)

LLMs在金融领域的语言任务中扮演着重要角色，特别是在处理大量金融文档和报告时。这些任务包括文本摘要、信息提取、文档结构处理和命名实体识别。

![](assets/005.png)

-   文本摘要与信息提取：LLMs能够将长篇金融文档压缩成简洁的摘要，同时保留关键信息。研究者通过分割文档、使用特定模型或结构化元素来提高处理长文本的效率。
    
-   管理多样化的文档结构：LLMs处理包含图像、图表和表格的PDF文件时面临挑战。解决方案包括将PDF转换为文本或使用布局感知模型来理解文档中的空间布局。
    
-   命名实体识别 (NER)：在金融领域中，NER用于从文本中提取公司名称、股票符号、财务指标等实体。LLMs通过预训练知识增强了在复杂金融文本中识别实体的准确性和效率。
    

  

3.2 情感分析 (Sentiment Analysis)

情感分析是金融领域中的一项关键任务，它涉及对文本数据中表达的意见、情感、主观性和情绪的量化探索。LLMs在此领域的应用包括：

![](assets/006.png)

-   社交媒体和新闻：LLMs能够分析社交媒体和新闻中的公众情绪，这些情绪可能预测市场动向。
    
-   公司披露：通过分析公司财报电话会议和官方声明中的情感，LLMs可以揭示影响投资者决策和管理市场感知的潜在情绪。
    
-   市场研究报告和政策经济指标：LLMs也被用于分析政策文件和经济指标报告中的情感，以指导投资决策。
    

  

3.3 金融时间序列分析 (Financial Time Series Analysis)

LLMs在金融时间序列分析中的应用包括预测市场趋势、检测异常和分类金融数据。

![](assets/007.png)

-   预测：LLMs直接用于股票市场和其他金融指标的预测，通过整合多种数据源提供稳健的预测。
    
-   异常检测：LLMs能够识别金融时间序列中的异常模式或离群值，对于风险管理和欺诈检测至关重要。
    
-   数据增强和插补：LLMs通过生成合成数据来增强现有数据集，或填补缺失的数据点，以提高模型的鲁棒性。
    

  

3.4 金融推理 (Financial Reasoning)

LLMs支持金融推理，包括战略规划、投资建议、决策支持和实时推理。![](assets/008.png)

-   规划：LLMs分析市场趋势和竞争数据，帮助组织制定商业策略和财务规划。
    
-   推荐：LLMs提供基于个人风险偏好和市场条件的个性化投资建议。
    
-   支持决策：LLMs通过监控市场趋势和新闻，提供及时的更新和警报，帮助用户调整策略。
    
-   实时推理：LLMs提供即时和动态的交互，通过聊天机器人和虚拟助手提供准确、相关和及时的信息。
    

  

3.5 基于代理的建模 (Agent-based Modeling)

基于代理的建模（ABM）是一种模拟复杂系统的方法，特别是在金融领域中。LLMs与ABM的结合为市场和经济活动的模拟提供了新的视角。

![](assets/009.png)

-   交易和投资：LLMs增强的交易代理能够处理大量数据并执行高精度交易，提供个性化的投资策略和洞察。
    
-   模拟市场和经济活动：LLMs增强的ABM能够模拟复杂的宏观经济活动，提供对不同经济因素相互作用的深入理解。
    
-   自动化金融流程：LLMs集成到金融流程中，自动化工作流程生成和战略规划。
    
-   多代理系统：多代理系统利用LLMs提高金融策略的稳健性和准确性，模拟各种代理之间的互动。
    

  

3.6 其他应用 (Other Applications)

LLMs在金融领域的其他应用包括云计算集成、自动化客户服务、合规性检查等。

###   

### **4\. 数据集、代码和基准 (Datasets, Code and Benchmark)**

4.1 数据集 (Datasets)

-   第四章首先介绍了多种金融领域的数据集，这些数据集对于训练和评估特定金融任务的模型至关重要。包括情感分析、问题回答、关系提取和数值推理等任务。
    
-   特别提到了Financial PhraseBank (FPB)、Financial Question Answering and Opinion Mining (FiQA)、FinQA等数据集，它们分别用于金融情感分析、基于方面的情感分析和金融数据的数值推理。
    

  

4.2 基准和代码 (Benchmarks and Code)

-   基准测试对于评估LLMs在金融领域的表现至关重要，它们提供了标准化的度量，确保了金融文本理解和预测的可靠性和准确性。
    
-   FLUE（Financial Language Understanding Evaluation）是一个全面的基准测试套件，设计用于评估语言模型在各种金融NLP任务上的性能。
    
-   论文还介绍了FLANG-BERT和FLANG-ELECTRA，这两种模型专门针对金融数据进行了训练，并采用了新颖的预训练方法。
    

![](assets/010.png)

### **5\. 挑战和机遇 (Challenges and Opportunities)**

-   数据问题：LLMs在处理高维金融数据时存在挑战，数据污染和信号衰减问题可能影响模型性能。需要研究混合模型和特定领域的预训练策略来提升对金融时间序列的理解。
    
-   建模问题：LLMs的高计算需求导致推理速度慢和成本高。未来前瞻偏差和幻觉问题在金融回测中需被严格控制。此外，LLMs生成内容的不确定性估计对于金融决策至关重要。
    
-   基准测试：现有基准可能不适合评估LLMs生成的交易信号，需要开发新的基准来适应市场变化。
    
-   伦理问题：LLMs的输出需要符合社会价值观和法律规范，避免产生有害建议。随着LLMs在金融决策中的作用日益增强，法律责任和问责问题变得重要。数据安全和隐私保护也是关键挑战。同时，理解LLMs开发和应用背后的动机对于确保其符合伦理标准至关重要。
    

### **6\. 结论 (Conclusion)**

本文了LLMs在金融领域应用的综合概况，强调了它们在提升金融任务效率和准确性方面的潜力。同时，指出了需要解决的挑战，如数据隐私、可解释性和计算成本，以确保LLMs在金融中的负责任和有效部署。最后，论文期望能够激发对LLMs潜力和局限性的进一步探索，推动它们在金融行业的整合，以实现更战略性投资和高效决策。

  

  

  

  

距离下次星球提价名额不到20，星球内有许多业内大佬，以及更多专业内容，欢迎加入，加入后不满意72小时内可全额退款，加入星球请扫我：

![](assets/011.jpg)

入群请扫我：

![](assets/012.jpg)

  

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

![](assets/013.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。