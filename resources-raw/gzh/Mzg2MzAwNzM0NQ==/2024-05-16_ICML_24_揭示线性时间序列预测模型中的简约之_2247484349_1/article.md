# ICML 24 | 揭示线性时间序列预测模型中的简约之美

QuantML QuantML 2024-05-16 17:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484349&idx=1&sn=264a5c0eaeca44ef9f2e182edb3d6b6d&chksm=cf11e800caca847f3412ebc45911692af0c40eae88a7cf7b9ecf63719e667df58d08319ffa7e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484349&idx=1&sn=264a5c0eaeca44ef9f2e182edb3d6b6d&chksm=cf11e800caca847f3412ebc45911692af0c40eae88a7cf7b9ecf63719e667df58d08319ffa7e#rd)

Content  

> 论文下载地址：An Analysis of Linear Time Series Forecasting Models (arxiv.org)

  

### **1\. 引言 (Introduction)**

引言部分强调了时间序列预测在多个领域（如金融、气象、医疗保健、云基础设施和交通流量管理）中的重要性。作者提到，尽管深度学习在许多领域取得了成功，但在时间序列预测方面，与简单的线性模型相比，其性能提升往往是边缘性的。引言还概述了线性模型的吸引力，包括它们的简单性、可解释性和效率。

  

### **2\. 相关工作 (Related Work)**

这一部分回顾了与时间序列预测相关的研究，特别是关于线性模型与复杂变换架构（如transformer模型）的比较。作者提到了DLinear和NLinear模型，以及它们在时间序列预测中的使用和性能。

  

### **3\. 线性时间序列预测模型分析 (Analysis of Linear Time Series Forecasting Models)**

分析了多个线性时间序列预测模型，包括DLinear、FITS、RLinear和NLinear。作者详细定义了这些模型，并提供了数学证明来展示这些模型实际上与标准线性回归等价。此外，还探讨了可逆数据归一化技术，如实例归一化（IN）、可逆实例归一化（RevIN）和NowNorm（NN），以及它们如何影响模型类别。

###     **3.1. 符号 (Notation)**

    在这一小节中，作者定义了用于整篇论文的数学符号和术语。这些符号包括上下文长度（L）、通道数（c）、预测范围（T）、上下文向量x）和目标向量y）。这些定义为后续的数学分析和模型比较提供了基础。

###         **3.1.1. DLINEAR (DLinear)**

        DLinear模型通过将上下文向x分解为“趋势”和“季节性”两个组成部分来工作。趋势部分是通过x的移动平均来定义的，而季节性部分则是通过残xseasonal := x - xtrend来给定的。DLinear将这两个部分通过独立的可学习线性层传递。作者提供了DLinear模型类别的数学证明，表明DLinear模型类别等同于仿射线性函数。

![](assets/001.png)

###         **3.1.2. FITS (FITS)**

        FITS模型将实数离散傅里叶变换（RFT）应用于上下文向x，然后应用一个可学习的复数线性映射，最后通过逆RFT将结果映射回时域。作者指出，FITS模型在不使用低通滤波器（LPF）的情况下，其模型类别与仿射线性函数相同，并且提供了相应的数学证明。

###     **3.2. 可逆数据归一化 (Invertible Data Normalisations)**

    这一小节讨论了在时间序列预测中使用的几种可逆数据归一化策略，包括实例归一化（IN）、可逆实例归一化（RevIN）和NowNorm（NN）。每种归一化策略都对模型类别产生了一定的限制。例如，RevIN和IN要求权重矩阵的行和为1，而NowNorm则要求权重矩阵的行和为1，但不对偏差进行限制。

###     **3.3. 实例归一化 (Instance Norm)**

    实例归一化（IN）通过将上下文向x标准化为其均值和标准差，然后应用模型f，最后将预测值逆向转换回原始尺度。作者提供了线性模型结合实例归一化（Linear+IN）的数学描述，并证明了其模型类别与仿射线性函数相同。

![](assets/002.png)

###     **3.4. 可逆实例归一化 (Reversible Instance Normalisation)**

    可逆实例归一化（RevIN）是IN的一个变体，它包括一个额外的仿射变换步骤。RLinear模型使用RevIN，并且作者证明了RLinear模型类别与仿射线性函数相同，但权重矩阵的行和为1。

![](assets/003.png)

###         **3.4.1. RLINEAR (RLinear)**

        RLinear是使用RevIN的线性模型。作者提供了RLinear模型类别的数学描述，并展示了如何将RLinear模型重新解释为无约束的线性回归。

###     **3.5. NowNorm (NowNorm)**

    NowNorm是一种将上下文向x归一化为最新零售值xL为零的归一化技术。NLinear模型使用NowNorm。作者提供了NLinear模型类别的数学描述，并指出其模型类别与仿射线性函数相同，但权重矩阵的行和为1。

###         **3.5.1. NLINEAR (NLinear)**

        NLinear是使用NowNorm的线性模型。作者提供了NLinear模型类别的数学证明，展示了如何将NLinear模型重新解释为无约束的线性回归。

###     **3.6. 模型类别变体和归一化约束 (Model Class Variants Normalisation Constraints)**

    在这一小节中，作者总结了不同模型类别的归一化约束，并指出了它们之间的等价性。例如，DLinear、FITS和Linear模型没有归一化约束，而NLinear模型的权重矩阵行和必须为1。

![](assets/004.png)

  

### **4\. 讨论 (Discussion)**

作者讨论了不同模型类别的归一化约束，并指出所有模型都可以重新表述为无约束线性回归，并由于凸性，它们在给定相同数据的情况下应该收敛到相同的解。

![](assets/005.png)

###     **4.1 模型类别变体和归一化约束 (Model Class Variants Normalisation Constraints)**

    在这一小节中，作者总结了不同线性模型类别及其归一化约束。作者指出，当上下文长度 𝐿≥𝑇−2 时，FITS 和 DLinear 与无约束线性回归在功能上等价。此外，作者还讨论了使用归一化处理的时间序列分析模型类别，以及这些归一化处理如何略微改变模型类别。例如，NLinear 等同于权重矩阵的行和必须为1的受限线性回归。

###     **4.2 凸性 (Convexity)**

    作者讨论了所有讨论的模型都使用均方误差（MSE）损失函数进行训练，这意味着训练损失是参数的凸函数。凸优化问题的一个重要性质是存在唯一的全局最优解，这个最优解最小化了训练损失。作者强调，这意味着在相同的训练数据下，这些模型应该通过合适的优化过程收敛到相同的解。

###     **4.3 封闭形式 (Closed Form)**

    作者指出最小二乘线性回归的一个重要性质是它有一个封闭形式的解。这意味着线性回归的最优参数可以在不迭代的情况下直接计算出来。作者提到，对于表1中的每个模型类别，最小二乘最优解都可以以封闭形式找到。

![](assets/006.png)

###     **4.4 FITS偏置项 (The FITS Bias-Term)**

    在这一小节中，作者详细讨论了FITS模型的偏置项参数化的影响。作者分析了通过逆离散傅里叶变换（iDFT）从复数偏差向量 获取偏置向量 的方法。作者指出，FITS模型的这种偏置项参数化方式对学习率的影响，导致偏置项的学习速率远小于权重矩阵的学习速率。

###     **4.5 训练过程中的参数化影响 (Parameterisation Impact During Training)**

    作者探讨了FITS模型在训练过程中参数化的影响，特别是如何影响模型的收敛和泛化。作者指出，由于FITS模型的特定参数化，早期训练阶段几乎不学习偏置项，这可能导致模型在训练初期对某些类型的数据过拟合。

###     **4.6 模型的等价性和差异性 (Equivalence and Differences Between Models)**

    作者总结了线性模型及其变体之间的等价性和差异性。尽管从功能角度看，这些模型几乎没有差异，但在实际训练和预测中，它们的性能可能会有所不同。作者强调，尽管存在这些差异，但每个模型类别都可以重新表述为无约束的线性回归，并因此可以通过封闭形式的解来求解。

### **5\. 实验 (Experiments)**

实验部分展示了不同模型在多个数据集上的性能，并证明了封闭形式的普通最小二乘（OLS）解通常优于使用随机梯度下降训练的模型。

###     **5.1 收敛性 (Convergence)**

    在这一小节中，作者展示了不同线性模型变体（包括RLinear、NLinear、DLinear+IN、FITS+IN和OLS+IN）在ETTh1数据集上训练50个周期后的内部权重矩阵。通过可视化这些权重矩阵，作者发现所有模型的权重矩阵几乎相同，这与他们之前的假设和理论分析一致。此外，作者还讨论了如何从训练好的模型中提取权重矩阵和偏差项。

![](assets/007.png)

###     **5.2 性能 (Performance)**

    作者在8个标准的基准数据集上测试并比较了不同模型的性能。这些数据集包括ETTh1、ETTh2、ETTm1、ETTm2、ECL、Weather、Traffic和Exchange。对于每个模型、数据集和预测范围的组合，作者使用0.0005的学习率和Adam优化器进行了50个周期的训练，并在验证集上跟踪了损失。在测试时，作者加载了在验证集上损失最小的模型进行评估。作者报告了每个模型在不同数据集和预测范围上的平均平方误差（MSE）值，并使用误差线表示标准差。实验结果显示，在72%的设置中，普通最小二乘（OLS）解的性能优于其他模型。

###         **5.2.1 数据集和模型 (Datasets and Models)**

        作者详细描述了用于实验的数据集和模型。数据集包括多个标准时间序列预测数据集，每个数据集都有其特定的训练、验证和测试集划分。作者比较了DLinear、NLinear、RLinear、FITS和Linear模型，以及它们的实例归一化版本。此外，作者还实现了OLS和OLS+IN的封闭形式解决方案，并使用scikit-learn的LinearRegression模型进行实现。

###         **5.2.2 超参数设置 (Hyperparameters)**

        作者描述了实验中使用的超参数设置，包括学习率、优化器、批量大小以及训练周期数。所有实验都至少使用不同的随机种子运行了三次，并计算了均方误差（MSE）的标准差。

###         **5.2.3 权重比较实验 (Weight Comparison Experiments)**

        在这一小节中，作者比较了不同模型的权重矩阵、偏差和预测结果。作者指出，这些比较是在训练50个周期后进行的，而不是使用早停法。此外，作者还展示了在350个训练周期内的余弦相似度，并使用了较小的学习率来清楚地展示这些模型的收敛行为。

![](assets/008.png)

###         **5.2.4 实验细节 (Experiment Details)**

        作者提供了实验的更多细节，包括数据集的预处理、模型的实现细节以及实验的具体设置。

![](assets/009.png)

### **6\. 结论 (Conclusion)**

论文总结了线性模型在时间序列预测中的有效性，并指出了这些模型的简单性和优越性。作者强调了他们的实验结果，即在72%的测试设置中，简单的封闭形式解作为预测器表现更优。

整篇论文通过数学分析和实验验证，为线性时间序列预测模型提供了深入的理解，并对这些模型的性能和等价性提出了有力的证据。

  

目前星球人数已经接近100，人数每增加100星球费用会提升100，星球内有各种有趣的研究，包括因子，模型，框架代码等。欢迎扫码加入交流  

  

  

入群请扫我：  

![](assets/010.jpg)

  

往期回顾

       QuantML-Qlib开发版：

-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)  
    
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
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)  
    
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

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/012.jpg)