# 基于特征工程和转换方法的LightGBM资产预测

QuantML QuantML 2025-01-15 21:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488811&idx=1&sn=990a3fb7f2dfaa030e5b99b615112704&chksm=cf28493b67d89cb3a02715a0b95faf30aa296dbad7c14bdbb39dc7cd08b8195e222b503163d7#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488811&idx=1&sn=990a3fb7f2dfaa030e5b99b615112704&chksm=cf28493b67d89cb3a02715a0b95faf30aa296dbad7c14bdbb39dc7cd08b8195e222b503163d7#rd)

![](assets/001.png)

股票市场的波动深刻影响全球经济和个人财富，准确预测其走势对于规避风险至关重要。尽管混合深度学习（DL）和机器学习（ML）模型在预测准确性方面展现出巨大潜力，但其高计算需求往往超出普通个人电脑的能力，限制了广泛的应用。为了应对这一挑战，本文致力于优化LightGBM（一种高效实现梯度提升决策树（GBDT）的模型），在保持低计算需求的同时实现最大性能提升。本文提出了一系列创新的特征工程方法，包括指标价格斜率比率和收盘价与开盘价之差除以相应14期指数移动平均线（EMA）的比率，旨在捕捉市场动态并提高预测准确性。此外，本文测试了七种不同的特征和目标变量转换方法，包括收益率、对数收益率、EMA比率及其标准化版本以及EMA差异比率，以确定在效率和准确性之间权衡的最佳方法。结果表明，对数收益率、收益率和EMA差异比率是最佳的目标变量转换方法，而EMA比率在方向预测准确性上表现较差，标准化版本的目标变量转换方法则需要显著更长的训练时间。此外，引入的特征在所有目标变量转换方法中均表现出较高的特征重要性。本研究展示了一种使用LightGBM进行股票市场预测的可行且计算高效的方法，使得高级预测技术更加普及。

### 1\. 引言

股票市场对个人和社会的金融福祉有着深远的影响。尽管其直接影响主要体现在企业和投资者身上，但其影响范围远远超出了这些直接参与者，渗透到消费者价格、经济政策和通货膨胀等日常生活的各个方面。股票市场的增长通常被视为经济繁荣的标志，但其衰退往往会给参与者和非参与者带来严重后果。因此，个人需要采取预防性措施来减轻这些后果的影响。

时间序列预测是一种应对股票市场复杂性的成熟方法。它利用科学方法，根据历史数据预测时间依赖变量的未来值。在过去的几十年中，时间序列预测被广泛应用于股票市场，因为它能够支持明智的决策、经济规划和潜在的被动收入。

随着技术的指数级增长，时间序列预测领域的创新也在加速。最初，统计方法在该领域占据主导地位，但随着人工智能的快速发展，机器学习（ML）和深度学习（DL）被应用于金融时间序列，如股票市场。ML和DL模型在处理复杂和非线性数据方面的有效性被证明是革命性的，许多当代研究提出了ML和DL的混合模型。尽管这些模型非常准确，但其计算需求通常将其实用性限制在拥有大量技术资源的机构中，从而限制了个人投资者、独立研究人员、小规模从业者和普通人的使用。

为了应对这一挑战，本研究重点关注LightGBM，这是一种使用基于树的算法的ML模型。与更重的深度学习模型相比，LightGBM在计算上更高效且高度可扩展，这使其更易于广泛采用。在M5预测竞赛中，LightGBM在时间序列预测中展示了令人印象深刻的结果。在本研究中，我们旨在通过引入新的特征工程技术和确定最佳的特征和目标变量转换方法，进一步提高其性能。

### 2\. 相关工作

#### 2.1 统计模型

统计模型在金融时间序列预测领域有着广泛的应用。其中，自回归移动平均（ARIMA）模型基于数据中线性相关性的识别来生成预测。因此，它在能源预测和酒店价格预测等领域表现出高准确性。然而，由于其仅建模线性关系的局限性，当面对股票市场等非线性异方差时间序列时，它的表现不佳。因此，广义自回归条件异方差（GARCH）模型被开发出来，通过直接建模波动性成功解决了这一问题。正如Farah Hayati Mustapa等人所展示的，混合GARCH-ARIMA模型在预测标准普尔500指数时实现了有限的准确性（R-squared=0.023910）。

#### 2.2 机器学习模型

机器学习模型在21世纪初崭露头角，利用技术进步有效地应用于股票市场。机器学习模型擅长解码多变量数据集中的复杂关系，这些数据集提供了额外的信息，证明了在处理股票市场的非线性特性方面更为可靠。值得注意的机器学习模型包括支持向量机、随机森林和梯度提升机，后者以更高效的方式在LightGBM、XGBoost、CatBoost和AdaBoost等模型中实现。Ma shangchen等人展示了LightGBM和GBDT模型在2016年至2018年期间预测标准普尔500指数时均实现了比同期指数更高的回报，LightGBM在此期间实现了高达394%的总回报。

#### 2.3 深度学习模型

在机器学习模型成功的基础上，深度学习模型专注于对时间序列中的时间依赖性进行建模，并具有直接从目标变量中提取信息特征的能力。然而，它们的采用速度较慢，部分原因是它们对训练数据有巨大的需求。这些需求包括足够大的数据集；充足的随机存取内存（RAM）；以及高度可并行化的处理器，如最先进的图形处理单元（GPU）和张量处理单元（TPU）。混合机器学习-深度学习模型已被证明在时间序列预测中特别有效，利用了两种技术的优势。Yuankai Guo等人提出了一个LSTM-LightGBM混合模型，使用LSTM预测诸如成交量和收盘价等特征的值，然后由LightGBM进行最终预测。他们提出的模型优于独立的长期短期记忆（LSTM）和递归神经网络（RNN）模型。

### 3\. 我们的贡献

本研究旨在优化LightGBM的性能，减少对通常用于深度学习模型的高性能硬件的依赖。我们系统地评估了七种不同的目标变量转换方法，并在包含使用这些相同转换方法创建的不同特征变体的特征集上进行了训练。此外，我们引入了新的交叉特征，如价格与指标之间的斜率差异和开盘价与前收盘价之间的差异，以在不显著增加训练时间的情况下提高准确性。

### 4\. LightGBM

Light Gradient Boosting Machine（简称LightGBM）是一个先进的开源机器学习框架，建立在GBDT的基础上，显著提高了效率。GBDT通过在数据上迭代训练决策树来纠正之前树的错误，从而进行预测。更具体地说，首先使用目标变量的均值作为基预测来预测数据。随后，决策树被拟合到基预测的残差上，以预测错误。这个过程，称为提升轮次，重复进行，直到在验证集上评估的准确性在指定的提升轮次内不再提高。

LightGBM在几个不同的方面改进了GBDT，其中包括：

### i. 梯度单边采样（GOSS）

梯度是损失函数的导数。它们指示残差相对于模型参数的变化程度。GOSS更关注具有较大梯度的实例，因为它们对模型更具信息性，同时保留了一部分具有较低梯度的实例。通过这个过程，在不显著降低准确性的情况下实现了更高的效率。

### ii. 基于直方图的分箱

分箱将特征值的多个实例组合成一个离散的分箱。一个分箱由其值范围和包含的数据点数组成。梯度是根据分箱而不是单个数据点计算的，从而降低了内存使用并加快了训练速度。此外，这种方法过滤了噪声数据，从而促进了泛化。

### iii. 叶向生长

与使用层级生长的GBDT不同，LightGBM以叶向生长决策树。在层级生长中，决策树最后一层的所有节点同时分裂，节点数量呈指数级增长。相比之下，叶向生长只分裂最具信息性的节点，而不考虑层级，从而创建更深、更复杂的树并减少计算压力。

### 5\. 方法论

#### 5.1 数据收集

苹果公司（AAPL）的股价波动通常被认为与蓝筹股类似，即它们流动性充足、相对稳定且波动性较低。作为标准普尔500等主要指数的组成部分，AAPL也反映了更广泛的市场趋势，使其成为评估股票市场预测方法的合适案例。因此，我们选择AAPL进行测试。我们从TradingView的导出图表数据功能中提取开盘价、最高价、最低价和收盘价（OHLC）以及成交量，总共有8137个数据点，日期跨度从1992年5月到2024年9日，日线时间框架。TradingView使用Cboe One的数据，该数据约占美国股票市场份额的10%。市场休市的日期不是数据集的一部分，因此没有缺失值。

#### 5.2 特征工程

我们将预测给定日期在市场开盘时的收盘价（目标变量），允许对隔夜价格缺口进行建模，并使用当天的开盘价作为特征。我们从OHLC价格和成交量中计算出大量典型和新颖的特征，旨在模拟不同的复杂市场行为和动态，通常借用技术分析（TA）和统计学的概念。

### 6\. 实验

为了评估LightGBM的性能，并比较每种转换方法的性能，我们在方法论中描述的数据集上进行了多次测试。我们使用数据集的80%-20%的训练-测试分割。

### 6.1 转换方法

首先，我们对特定特征集的副本进行异常值处理，以便稍后比较它们的性能。不同的转换方法，如方法论中所述，迭代地应用于每个适用的特征，以创建包含所有特征在每个转换变体中的新数据集。

### 6.2 训练与交叉验证

为了稳健地推广模型，我们选择滚动训练-验证分割，使用scikit-learn的TimeSeriesSplit来避免任何数据泄漏。首先，我们将训练集分成四个部分以创建三个验证折叠。在第一个折叠中，模型在第一部分训练并在下一部分验证。第二个折叠使用前两部分进行训练并在第三部分验证。最后，第三个折叠使用除最后一部分之外的所有部分进行训练，并在第四部分验证。

### 6.3 自定义损失函数

由于在股票市场预测的背景下，较大的错误可能会导致严重的后果，我们选择了一个自定义损失函数，它对较大的错误进行更严厉的惩罚。

### 6.4 超参数调优

网格搜索在以前的研究中常用，但计算成本高且耗时。相反，我们采用Optuna的贝叶斯优化算法，这是一种更快、更可扩展的替代方案。在平衡训练效率与性能的同时，我们将使用500次试验。一些优化的参数如下所示：

![](assets/002.png)

### 6.5 指标

准确评估模型性能对于得出有意义的结果至关重要。对于每种目标变量转换方法，我们相应地反向转换预测，以便与实际市场价值进行比较。我们计算平均绝对误差（MAE）、均方根误差（RMSE）、方向准确性（DA）和训练时间。所有测试均在AMD Ryzen 5 3600处理器上进行，配有32GB的DDR4内存，尽管训练过程并未完全使用。此外，一些计算通过CuPy分配给图形处理单元（GPU）以减轻CPU的负载。

### 6.6 基准

随机游走（RW）模型假设关于下一个时间点的值的所有信息都反映在当前值中。它是股票市场预测的最基本基准，因为任何无法超越它的模型本质上没有有意义的预测能力。RW模型的方程如下所示：

![](assets/003.png)

### 7\. 结果

从九次测试中提取的指标在以下表格中表示：

![](assets/004.png)

![](assets/005.png)

### 8\. 结论

本研究探讨了结合创新转换方法的创新特征工程技术，以优化LightGBM在股票市场预测中的性能，并在AAPL日线价格上进行测试。不同的转换方法在目标变量和特征上进行了评估（如果适用）。为了进行比较，部署了两个基于传统特征的LightGBM模型和一个RW模型。

我们的研究结果表明，对数收益率是目标变量的最佳转换方法，尽管性能差异通常较小。转换方法的标准化版本略微降低了准确性，但大大增加了训练时间，这表明标准化对于LightGBM等基于树的模型是适得其反的。

转换方法极大地影响了不同模型中特征的相对重要性。通过EMA比率、EMA差异比率和收益率转换的特征在所有模型中得分特别高。至关重要的是，新特征，特别是隔夜价格缺口，始终表现出比传统特征更高的重要性。这证明了它们能够为模型提供有关复杂市场动态的额外信息，从而提高预测性能，同时显著减少训练时间。

异常值处理方法对LightGBM没有太多好处，尽管在这方面的测试有限。未来的实验可以更好地评估这种方法及其在时间序列预测更广泛背景下的有效性。此外，残差图表明，在高波动性时期，模型性能会恶化。未来的工作可能涉及训练多个专门的LightGBM模型，每个模型都在特定的波动性制度下训练。这些制度可以使用GARCH模型或LightGBM分类器来识别。最后，EMA比率在多步预测中具有前景，鉴于其基于趋势的性质。

  

论文及更多资源见星球

![](assets/006.png)

  

往期回顾

       QuantML-Qlib开发版：

  

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
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [利用LangGraph 和 OpenAI 打造金融分析师Agent](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [JFQA | 基于深度学习的排序特征因子模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488380&idx=1&sn=15327d544022028afab9efa2a90a0c36&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [NIPS 24 | PGN：RNN 的新继任者](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488128&idx=1&sn=a8287377302d2cdf5d1d6ddc321cdf31&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)  
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [ICLR 2024 | 通向透明的时间序列预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=ce7e624cf909eb5a44ce762087ef23bd8cfeb663aa623f0d729b99d56450abafd525d927bc5e&scene=21#wechat_redirect)
    
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
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)