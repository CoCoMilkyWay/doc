# 本地开源版OpenAI Deep Research

QuantML QuantML 2025-03-17 22:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489700&idx=1&sn=5a1a5ec4a6343be848f8190759480b9a&chksm=cfd30bca8679a7455dbe86173dabb8a1f267db5c864860edc386677b249c67e89a0583926b9f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489700&idx=1&sn=5a1a5ec4a6343be848f8190759480b9a&chksm=cfd30bca8679a7455dbe86173dabb8a1f267db5c864860edc386677b249c67e89a0583926b9f#rd)

### 

在当今信息爆炸的时代，研究人员面临着海量数据与信息筛选的挑战。为了应对这一难题，**LearningCircuit** 团队开发了一款名为 **Local Deep Research** 的强大 AI 研究助手。该工具旨在通过本地化部署和先进的 AI 技术，为用户提供高效、精准且隐私保护的研究体验。

github地址：https://github.com/LearningCircuit/local-deep-research

![](assets/001.png)

### **一、核心功能与特点**

#### 1. **强大的研究能力：深度迭代与全面分析**

Local Deep Research  具备以下先进的研究功能：

-   **自动化深度研究**：该工具能够根据用户输入的初始查询，自动生成一系列智能后续问题，进行多轮迭代分析，从而深入挖掘研究主题的各个方面。
    

-   例如，在进行“人工智能在医疗领域的应用”研究时，工具可能会自动询问“当前有哪些具体的应用案例？”、“这些应用面临哪些挑战？”以及“未来发展趋势如何？”等问题。
    

-   **智能引用追踪与来源验证**：工具会追踪研究过程中引用的所有信息来源，并进行验证，确保研究结果的可靠性和准确性。
    
-   **多轮迭代分析**：通过多轮分析，工具能够对研究主题进行更全面、更深入的探讨，避免遗漏关键信息。
    
-   **全网页内容分析**：区别于仅提取网页片段的传统搜索引擎，Local Deep Research  能够对整个网页内容进行深入分析，从而提供更完整、更准确的信息。
    

#### 2. **灵活的 LLM 支持：本地与云端相结合**

为了满足不同用户的需求，Local Deep Research  提供了灵活的 LLM（大型语言模型）支持：

-   **本地 AI 处理**：内置对 **Ollama** 模型的支持，用户可以在本地运行 AI 模型，确保数据隐私安全。
    

-   用户可以根据自身硬件条件选择合适的模型，例如性能更强的模型可能需要更强大的 GPU 支持。
    

-   **云端 LLM 支持**：支持 **Claude**、**GPT** 等主流云端 LLM，用户可以根据需求选择使用。
    
-   **LangChain 模型支持**：兼容所有 **LangChain** 模型，为用户提供了更广泛的选择空间。
    
-   **模型智能选择**：用户可以根据研究需求和硬件条件，灵活配置使用的模型。
    

#### 3. **丰富的输出选项：满足多样化需求**

Local Deep Research  提供了多种输出格式，以满足不同用户的研究需求：

-   **详细的研究报告**：包含完整的分析过程、引用来源和结论，为用户提供深入洞察。
    
-   **快速摘要**：提供简洁明了的总结，帮助用户快速获取关键信息。
    
-   **引用追踪与验证**：工具会列出所有引用的来源，并提供验证信息，确保研究结果的可靠性。
    
-   **PDF 导出功能**：用户可以将研究结果导出为 PDF 文档，方便分享和存档。
    

#### 4. **隐私保护：本地化部署与数据安全**

-   **本地化部署**：用户可以选择在本地运行工具，所有数据都存储在本地设备上，避免数据泄露风险。
    
-   **隐私保护**：工具不会将用户数据上传至云端，确保用户隐私安全。
    

#### 5. **强大的搜索集成：多源搜索与智能选择**

Local Deep Research  集成了多种搜索功能，并具备智能选择机制：

-   **多源搜索集成**：
    

-   **Wikipedia** 适用于一般知识查询和事实核实。
    
-   **arXiv**  适用于科学和学术研究，访问预印本和论文。
    
-   **PubMed**  适用于生物医学文献、医疗研究和健康信息查询。
    
-   **DuckDuckGo**  提供无需 API 密钥的常规网络搜索。
    
-   **The Guardian**  提供高质量的新闻报道和文章（需要 API 密钥）。
    
-   **SerpAPI**  提供 Google 搜索结果（需要 API 密钥）。
    
-   **Google 可编程搜索引擎**  提供自定义搜索体验（需要 API 密钥和搜索引擎 ID）。
    

-   **自动选择搜索源**：工具会根据用户查询内容，自动选择最合适的搜索引擎，例如：
    
-   **本地 RAG 搜索**：用户可以使用向量嵌入技术搜索本地文档，实现对私有文档的搜索。
    
-   **全网页内容检索**：工具能够检索整个网页内容，而不仅仅是片段。
    
-   **来源过滤与验证**：工具会对搜索结果进行过滤和验证，确保信息的准确性和可靠性。
    
-   **可配置的搜索参数**：用户可以根据需求调整搜索参数，例如搜索范围、时间范围等。
    

-   **智能搜索引擎选择**：
    

-   **“auto”**  选项会根据用户查询内容智能选择最合适的搜索引擎。例如，询问物理学研究论文时，可能会选择 arXiv 或用户的研究论文集合；而询问时事新闻时，则可能会选择 The Guardian 或 DuckDuckGo。
    

#### 6. **本地文档搜索 (RAG)：私有文档的智能检索**

Local Deep Research  集成了强大的本地文档搜索功能，利用检索增强生成 (RAG) 技术，使用户能够搜索和检索本地文档集合中的内容：

-   **基于向量嵌入的搜索**：使用向量嵌入技术对本地文档进行索引和检索，实现更精准的搜索结果。
    
-   **自定义文档集合**：用户可以为不同主题创建自定义文档集合，例如研究论文、个人笔记等。
    
-   **隐私保护**：所有文档都存储在本地设备上，确保数据安全。
    
-   **智能分块与检索**：工具会对文档进行智能分块和检索，提高搜索效率。
    
-   **兼容多种文档格式**：支持 PDF、文本、Markdown 等多种文档格式。
    
-   **与元搜索自动集成**：用户可以使用统一的查询语法进行本地和在线搜索。
    

### **二、使用指南**

#### 1. **安装与配置**

用户需要按照以下步骤进行安装：

1.  克隆仓库并安装依赖项。
    
2.  安装 Ollama 以便在本地运行 AI 模型。
    
3.  配置环境变量，例如 API 密钥（如果使用云端 LLM）。
    
4.  根据需求配置 `config.py` 文件中的参数，例如默认模型、搜索工具等。
    

#### 2. **本地文档集合设置**

用户需要创建 `local_collections.py` 文件，定义本地文档集合，并创建相应的文件夹来存储文档。

#### 3. **使用本地搜索**

用户可以通过以下几种方式使用本地搜索：

-   **自动选择**：将 `search_tool` 设置为 `"auto"`，工具会根据查询内容自动选择合适的搜索源，包括本地文档集合。
    
-   **明确选择**：将 `search_tool` 设置为特定的本地集合名称，例如 `"research_papers"`。
    
-   **搜索所有本地集合**：将 `search_tool` 设置为 `"local_all"`。
    
-   **查询语法**：使用 `collection:collection_name your query` 语法来针对特定集合进行查询。
    

### **三、应用场景与优势**

Local Deep Research  适用于以下场景：

-   **学术研究**：帮助研究人员快速获取相关文献、跟踪最新研究进展，并进行深入分析。
    
-   **商业分析**：为商业分析师提供市场趋势、竞争对手分析等信息，支持决策制定。
    
-   **新闻报道**：为记者提供全面的新闻背景资料和深度分析。
    
-   **知识管理**：帮助知识工作者整理和管理个人笔记、研究资料等。
    

其主要优势在于：

-   **高效性**：自动化深度研究和多源搜索功能，节省研究人员的时间和精力。
    
-   **精准性**：智能引用追踪和来源验证功能，确保研究结果的可靠性。
    
-   **灵活性**：支持本地与云端 LLM 部署，兼容多种文档格式和搜索源。
    
-   **隐私性**：本地化部署和隐私保护功能，满足用户对数据安全的需求。
    

### **四、总结**

Local Deep Research  是一款功能强大且灵活的研究助手，它将先进的 AI 技术与多源搜索功能相结合，为用户提供了一个高效、精准且安全的研究平台。无论是在学术、商业还是新闻领域，该工具都能成为用户不可或缺的得力助手，助力用户更深入地探索知识世界。

  

入群请扫我：

![](assets/002.jpg)

  

  

  

  

更多资源见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/003.png)

  

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