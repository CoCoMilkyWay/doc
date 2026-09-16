# 机器学习与算法交易：构建市场与另类数据的预测模型

QuantML QuantML 2025-02-11 18:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489219&idx=1&sn=1b6df399f0d77e6aaa2ea42176904b2e&chksm=cfdd0b6b9912a3285caf538d70a75afb1ada36f4e8fbf1a8973fa8d6b906cbec9f0893c07224#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489219&idx=1&sn=1b6df399f0d77e6aaa2ea42176904b2e&chksm=cfdd0b6b9912a3285caf538d70a75afb1ada36f4e8fbf1a8973fa8d6b906cbec9f0893c07224#rd)

《Machine Learning for Trading》这本书由 Stefan Jansen 撰写，是一本全面且实用的指南，旨在帮助读者利用机器学习（ML）技术开发盈利的算法交易策略。本书以**超过800页的篇幅**，系统地讲解了如何将机器学习应用于量化交易，涵盖了从数据获取、特征工程到策略回测和评估的完整工作流程。

#### 1\.  核心内容概览

本书内容分为四个部分，共24章，配套代码库包含超过150份代码：

**(一) 从数据到策略开发：构建量化交易的基础**

1.  **机器学习在交易中的应用：从理念到执行**
    

-   探讨了推动机器学习在投资领域崛起的行业趋势，例如数据爆炸式增长、计算能力的提升以及算法交易的兴起。
    
-   介绍了机器学习在交易中的典型应用场景，例如预测资产价格、识别市场模式、管理风险以及优化投资组合。
    
-   强调机器学习不是孤立的技术，而是量化交易流程中的一个关键环节。
    

3.  **市场与基本面数据：来源与技术**
    

-   **纳斯达克逐笔交易数据**：提供详细的买卖盘信息，用于捕捉市场供需动态。
    
-   **Algoseek 分钟级数据**：包含丰富的属性，可用于开发基于机器学习的日内交易策略。
    
-   深入讲解了如何获取和处理市场数据（如股票价格、交易量、订单簿数据）和基本面数据（如财务报表、宏观经济指标）。
    
-   介绍了不同类型的市场数据，例如：
    
-   展示了如何使用 Python 访问和操作交易数据以及来自美国证券交易委员会（SEC）的财务报告数据，例如使用 XBRL 解析电子文件。
    
-   强调了理解交易基础设施和订单类型对于正确解读数据和设计回测模拟的重要性。
    

5.  **金融另类数据：类别与应用场景**
    

-   **个人数据**：社交媒体、搜索引擎数据等。
    
-   **商业数据**：信用卡交易、电子商务数据等。
    
-   **传感器数据**：卫星图像、天气数据、物联网设备数据等。
    
-   概述了另类数据的类别，例如：
    
-   介绍了评估日益增长的另类数据来源和提供商的评估标准，例如数据质量、覆盖范围、更新频率和成本。
    
-   展示了如何通过网页抓取创建另类数据集，例如收集财报电话记录，用于后续的自然语言处理（NLP）和情感分析。
    

7.  **金融特征工程：如何研究阿尔法因子**
    

-   **NumPy 和 pandas**：用于数据操作和分析。
    
-   **TA-Lib**：用于计算技术指标。
    
-   **小波分析和卡尔曼滤波器**：用于降噪。
    
-   深入探讨了特征工程在交易中的重要性，强调了它对成功预测的关键作用。
    
-   介绍了学术界和业界数十年来对驱动资产市场和价格的因素的研究成果，以及哪些特征有助于解释或预测价格走势。
    
-   提供了计算和测试阿尔法因子的基本工具，例如：
    
-   介绍了如何使用 Zipline 和 Alphalens 对单个和多个阿尔法因子进行离线测试和评估，例如使用信息系数（IC）评估预测性能。
    

9.  **投资组合优化与绩效评估**
    

-   **均值-方差优化**：传统的投资组合优化方法。
    
-   **机器学习方法**：用于学习资产之间的层次关系，并将其视为互补品或替代品，以设计投资组合的风险配置。
    
-   解释了如何将阿尔法因子生成的信号转化为交易，并构建多空头寸。
    
-   介绍了多种投资组合优化方法，例如：
    
-   展示了如何使用 Zipline 模拟交易并基于阿尔法因子创建投资组合，以及如何使用 pyfolio 评估投资组合的绩效，例如夏普比率、最大回撤等指标。
    

**(二) 机器学习交易基础：掌握核心算法与工作流程**

6.  **机器学习过程**
    

-   **问题构建**：定义预测任务，例如回归或分类。
    
-   **模型训练与评估**：使用训练数据训练模型，并使用验证集评估其性能。
    
-   **超参数调优**：使用交叉验证等技术优化模型超参数。
    
-   **过拟合诊断与处理**：识别过拟合问题并采取措施，例如正则化或增加数据量。
    
-   介绍了监督学习和无监督学习的基本概念，以及它们在交易中的应用。
    
-   详细讲解了如何系统地构建机器学习模型，包括：
    
-   强调了金融数据在样本外测试中需要特别注意的问题，例如市场环境的变化和数据的非平稳性。
    

8.  **线性模型：从风险因子到收益预测**
    

-   介绍了线性回归和逻辑回归的基本原理，以及它们在交易中的应用。
    
-   解释了线性回归的假设条件，以及如何设计和诊断线性回归模型。
    
-   展示了如何使用线性回归预测不同时间跨度的股票收益，以及如何使用岭回归和 Lasso 回归等正则化方法提高预测性能。
    
-   介绍了如何将回归问题转换为分类问题，例如预测股票价格是上涨还是下跌。
    

10.  **ML4T 工作流程：从模型到策略回测**
     

-   提供了对设计、模拟和评估由机器学习算法驱动的交易策略的端到端视角。
    
-   详细演示了如何使用 Python 库 backtrader 和 Zipline 在历史市场环境中对机器学习驱动的策略进行回测。
    
-   讨论了向量化回测引擎和事件驱动回测引擎的优缺点，以及事件驱动回测器的关键组件。
    
-   强调了避免回测中的关键陷阱，例如前视偏差、生存偏差和过度优化。
    
-   介绍了如何设计并执行分钟级和日级频率的 ML4T 工作流程，包括单独训练或作为回测的一部分训练机器学习模型。
    

12.  **时间序列模型：波动率预测与统计套利**
     

-   重点介绍了从时间序列历史中提取信号以预测同一时间序列未来值的模型。
    
-   介绍了诊断时间序列特征（例如平稳性）的工具，以及提取捕捉潜在有用模式的特征。
    
-   介绍了单变量和多变量时间序列模型，用于预测宏观数据和波动率模式。
    
-   解释了协整性如何识别时间序列之间的共同趋势，并展示了如何基于这一关键概念开发配对交易策略。
    

14.  **贝叶斯机器学习：动态夏普比率与配对交易**
     

-   介绍了贝叶斯机器学习方法，以及它们对不确定性的不同视角如何在开发和评估交易策略时增加价值。
    
-   解释了贝叶斯统计如何量化对未来事件的不确定性，并随着新信息的到来以原则性的方式改进估计。
    
-   介绍了贝叶斯机器学习在计算动态夏普比率、动态配对交易对冲比率以及估计随机波动率方面的应用。
    

16.  **随机森林：针对日本股票的长期-短期策略**
     

-   介绍了决策树和随机森林在交易中的应用。
    
-   展示了如何训练决策树进行回归和分类预测，可视化和解释模型学习的规则，以及调整模型的超参数以优化偏差-方差权衡。
    
-   介绍了集成模型如何将多个决策树以随机方式组合起来，以产生具有更低误差的单一预测。
    
-   展示了如何训练、调整和解释随机森林，并使用随机森林设计并评估一个盈利的日本股票交易策略。
    

18.  **提升你的交易策略：从日常到日内数据**
     

-   介绍了梯度提升，这是一种替代的基于树的集成算法，通常比随机森林产生更好的结果。
    
-   解释了提升与装袋的区别，以及梯度提升如何从自适应提升演变而来。
    
-   展示了如何使用 scikit-learn 设计并调整自适应提升和梯度提升模型，以及如何使用 XGBoost、LightGBM 和 CatBoost 等最先进的实现来构建、优化和评估大型数据集上的梯度提升模型。
    
-   介绍了如何使用 SHAP 值解释梯度提升模型，并使用提升与高频数据设计一个日内交易策略。
    

20.  **数据驱动的风险因子与资产配置：使用无监督学习**
     

-   介绍了无监督学习的主要任务：降维和聚类。
    
-   详细介绍了主成分分析（PCA）和独立成分分析（ICA）如何执行线性降维，以及如何使用 PCA 从资产收益中识别数据驱动的风险因子和特征投资组合。
    
-   介绍了如何使用流形学习有效地可视化非线性、高维数据，以及如何使用 t-SNE 和 UMAP 探索高维图像数据。
    
-   介绍了 k-means、层次聚类和基于密度的聚类算法的工作原理，以及如何使用层次聚类构建具有层次风险平价的稳健投资组合。
    

**(三) 自然语言处理交易：挖掘文本数据的价值**

14.  **文本数据交易：情感分析**
     

-   介绍了如何将文本数据转换为机器学习算法可用的数值格式，同时保留其语义或含义。
    
-   展示了如何构建多语言特征提取管道，以及执行词性标注或命名实体识别等 NLP 任务。
    
-   介绍了如何将标记转换为数字，以及使用文档-词矩阵进行文本分类和情感分析。
    
-   介绍了朴素贝叶斯模型，并将其性能与线性和基于树的模型进行比较。
    

16.  **主题建模：总结金融新闻**
     

-   介绍了如何使用无监督学习对潜在主题进行建模，并从文档中提取隐藏的主题。
    
-   介绍了主题建模的演变历程、其成就以及重要性。
    
-   介绍了如何使用潜在语义索引（LSA）降低文档-词矩阵（DTM）的维度，以及如何使用概率潜在语义分析（pLSA）提取主题。
    
-   解释了潜在狄利克雷分配（LDA）如何改进 pLSA，成为最流行的主题模型。
    
-   介绍了如何使用 scikit-learn 和 gensim 运行 LDA，以及如何将主题建模应用于财报电话金融新闻文章集合。
    

18.  **词嵌入：用于财报电话和 SEC 文件**
     

-   介绍了如何使用神经网络学习单个语义单元（例如单词或段落）的向量表示。
    
-   解释了词嵌入如何捕捉语义信息，以及如何获取和使用预训练的词向量。
    
-   介绍了哪些网络架构最有效地训练 word2vec 模型，以及如何使用 TensorFlow 和 gensim 训练 word2vec 模型。
    
-   介绍了如何可视化并评估词向量的质量，以及如何在 SEC 文件上训练 word2vec 模型以预测股票价格走势。
    
-   介绍了 doc2vec 如何扩展 word2vec 并帮助进行情感分析，以及为什么 Transformer 的注意力机制对 NLP 产生了如此大的影响。
    
-   介绍了如何在金融数据上微调预训练的 BERT 模型。
    

**(四) 深度学习与强化学习：构建智能交易系统**

17.  **深度学习交易**
     

-   介绍了前馈神经网络（NN），并展示了如何使用反向传播高效地训练大型模型，同时管理过拟合的风险。
    
-   展示了如何使用 TensorFlow 2.0 和 PyTorch，以及如何优化 NN 架构以生成交易信号。
    
-   介绍了深度学习如何解决复杂领域中的 AI 挑战，以及推动深度学习当前流行的关键创新。
    
-   展示了前馈网络如何从数据中学习表示，以及如何使用 Python 设计并训练深度神经网络（NN）。
    
-   介绍了如何使用 Keras、TensorFlow 和 PyTorch 实现深度 NN，以及如何构建并调整深度 NN 以预测资产收益。
    

19.  **CNN：用于金融时间序列和卫星图像**
     

-   介绍了 CNN 架构的构建模块，以及如何使用迁移学习加速学习，以及如何使用 CNN 进行目标检测。
    
-   展示了 CNN 如何生成来自图像或时间序列数据的交易信号，例如使用卫星图像预测商品趋势。
    
-   介绍了 CNN 如何利用其与图像的结构相似性提供高质量的时间序列分类结果，并设计基于时间序列数据格式化的图像的策略。
    
-   详细介绍了 CNN 如何使用多个构建模块来有效地建模网格状数据，以及如何使用 TensorFlow 训练、调整和正则化 CNN 以处理图像和时间序列数据。
    

21.  **RNN：用于多变量时间序列和情感分析**
     

-   介绍了递归神经网络（RNN），其计算每个输出作为前一个输出和新数据的函数，从而有效地创建具有记忆的模型，并在更深的计算图中共享受参数。
    
-   介绍了 RNN 的主要架构，例如 LSTM 和 GRU，它们解决了学习远程依赖关系的挑战。
    
-   展示了 RNN 如何将一个或多个输入序列映射到一个或多个输出序列，以及它们如何特别适合自然语言处理。
    
-   介绍了 RNN 如何应用于单变量和多变量时间序列，以预测市场或基本面数据。
    
-   展示了如何使用 RNN 对替代文本数据进行建模，例如使用词嵌入对文档中表达的情感进行分类。
    

23.  **自动编码器：用于条件风险因子和资产定价**
     

-   介绍了如何利用无监督深度学习进行交易。
    
-   详细介绍了自动编码器，即训练神经网络在再现输入的同时，学习由隐藏层参数编码的新表示。
    
-   展示了自动编码器如何用于非线性降维，并利用我们在过去三章中介绍的 NN 架构。
    
-   介绍了如何使用 Python 构建和训练自动编码器，以及如何使用自动编码器提取考虑到资产特征的数据驱动的风险因子以预测收益。
    

25.  **生成对抗网络：用于合成时间序列数据**
     

-   介绍了生成对抗网络（GAN）。
    
-   解释了 GAN 如何在竞争环境中训练生成器和判别器网络，使生成器学习生成判别器无法区分的样本。
    
-   介绍了 GAN 在图像数据中的应用，以及它们如何用于生成医学领域的合成时间序列数据。
    
-   展示了如何使用 TensorFlow 2 设计和训练 GAN，以及如何生成合成金融数据以扩展可用于训练 ML 模型和回测的输入。
    

27.  **深度强化学习：构建交易代理**
     

-   介绍了强化学习（RL），其模型化目标导向的学习，由代理与随机环境交互。
    
-   介绍了 RL 如何通过从奖励信号中学习状态和动作的价值来优化代理的决策，以实现长期目标。
    
-   介绍了 RL 的最终目标是推导出一个编码行为规则的策略，并映射状态到动作。
    
-   展示了如何制定并解决 RL 问题，介绍了基于模型和无模型的方法，介绍了 OpenAI Gym 环境，并结合深度学习与 RL 训练一个在复杂环境中导航的代理。
    
-   展示了如何将 RL 适应于算法交易，通过模拟一个与金融市场交互的代理，同时尝试优化目标函数。
    

29.  **结论与下一步**
     

-   持续监控模型性能，并根据市场变化进行更新。
    
-   将机器学习模型集成到现有的交易系统中。
    
-   组建一个跨学科的团队，将机器学习专家与量化分析师结合起来。
    
-   探索更多先进的机器学习算法，例如深度强化学习。
    
-   将机器学习应用于更多类型的另类数据，例如高频数据、新闻流数据等。
    
-   将机器学习与其他量化交易技术（例如统计套利、风险对冲等）相结合。
    
-   简要总结了本书中介绍的关键工具、应用和经验教训。
    
-   确定尚未涉及但值得关注的领域
    
-   建议将机器学习融入投资流程的方法
    

31.  **附录 - 阿尔法因子库**
     

-   强调了智能设计特征的重要性，包括适当的预处理和降噪。
    
-   提供了 TA-Lib 和 WorldQuant 的 101 公式化阿尔法因子论文中实现的各种指标的计算方法。
    
-   介绍了公式化阿尔法的创建方法。
    

  

  

代码及相关资料见星球，加入QuantML星球，与700+专业人士一起交流学习：

![](assets/001.png)

  

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