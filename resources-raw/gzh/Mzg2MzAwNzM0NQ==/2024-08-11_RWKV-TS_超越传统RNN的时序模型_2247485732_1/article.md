# RWKV-TS: 超越传统RNN的时序模型

QuantML QuantML 2024-08-11 22:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485732&idx=1&sn=5e362c713b852da5d597e0acb9e8c745&chksm=cf0fb7dfcae1fd513f8e6fc138e1aeb5725c247142c2e849aa5fa0b2c35abebb8314dded7afb#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485732&idx=1&sn=5e362c713b852da5d597e0acb9e8c745&chksm=cf0fb7dfcae1fd513f8e6fc138e1aeb5725c247142c2e849aa5fa0b2c35abebb8314dded7afb#rd)

Content

这篇论文提出了一种新型的基于循环神经网络（RNN）的时间序列预测模型RWKV-TS，它通过三个显著特点克服了传统RNN的局限性：线性时间复杂度和内存使用、增强的长期序列信息捕捉能力以及高效的计算能力。通过广泛的实验，RWKV-TS展现了与最先进的基于Transformer或CNN的模型相媲美的性能，同时在延迟和内存使用上具有优势，为时间序列任务的未来研究提供了一个有前景的方向。

![](assets/001.png)

### **1\. 引言 (Introduction)**

作者首先强调了时间序列分析在机器学习中的重要性，并指出了其在金融预测、环境预测等多个领域的广泛应用。然后，作者讨论了传统循环神经网络（RNN）在处理时间序列数据时由于其捕捉时间依赖性的内在能力而成为建模序列数据的基石。

然而，作者指出了传统RNN，包括其变体如长短期记忆网络（LSTM）和门控循环单元（GRU），在处理长序列时面临的挑战，例如梯度消失或爆炸问题，这限制了它们捕捉长序列信息的能力。此外，由于无法进行并行计算，传统RNN在计算效率上较低，且难以扩展。还有，逐步预测方法导致了错误累积和推理速度慢。

针对这些局限性，作者提出了RWKV-TS模型，这是一个高效的基于RNN的模型，专为时间序列任务设计。RWKV-TS具有三个显著特点：线性时间复杂度和内存使用、比传统RNN更好的长期序列信息捕捉能力、以及高计算效率和有效扩展的能力。作者通过广泛的实验表明，RWKV-TS在与最先进的基于Transformer或CNN的模型相比较时，展现出了有竞争力的性能，并且在减少延迟和内存使用方面表现出优势。

### **2\. 相关工作 (Related Work)**

作者首先回顾了循环神经网络（RNN）及其衍生模型，如长短期记忆网络（LSTM）和门控循环单元（GRU），这些模型曾是时间序列分析的主流选择。尽管RNN在处理序列数据方面具有天然优势，但它们在处理长序列时会遇到梯度消失或爆炸的问题，这限制了它们捕捉长期依赖关系的能力。随后，作者介绍了新型RNN架构，这些架构在大型语言模型领域取得了显著成功，例如RWKV模型及其变体，它们展示了与Transformer模型相媲美的性能和更高的效率。此外，章节还总结了Transformer模型在时间序列预测中的应用，这些模型利用了并行化能力和注意力机制，有效地处理了序列数据，如LogTrans、Informer、Autoformer和FEDformer等。

在讨论了基于RNN和Transformer的模型之后，章节转向了多层感知器（MLP）在时间序列预测中的复兴，特别是DLinear模型，它通过添加线性层和通道不可知策略，超越了现有的Transformer模型。最后，章节还涉及了卷积神经网络（CNN）在时间序列预测中的应用，这些模型通过捕捉局部模式和特征，在某些任务中表现出了优异的性能。

### **3\. 模型架构 (Model Architecture)**

### **3.1 归一化和分块（Normalization and Patching）**

-   实例归一化（Instance Normalization）：首先对每个单变量时间序列实例进行归一化处理，以零均值和单位标准差进行调整。这有助于减少训练和测试数据之间的分布偏移。
    
-   分块（Patching）：将单变量时间序列分割成多个块，这些块可以重叠或不重叠。通过分块，输入令牌的数量从L减少到N，降低了模型的计算量和内存使用。
    

### **3.2 RWKV块（RWKV Blocks）**

-   RWKV主干：模型使用RWKV编码器作为其主要架构，由多个残差块堆叠而成，每个块包含时间混合和通道混合子块。
    
-   时间混合子块（Time Mixing Sub-block）：
    

-   令牌移位（Token Shift）：通过使用可训练变量进行线性组合，实现当前和之前时间步的输入之间的简单时间混合。
    

![](assets/002.png)

-   多头WKV操作符（Multi-head WKV Operator）：与自注意力机制类似，但具有线性时间和空间复杂度，通过时间依赖的更新WKV向量实现循环行为。
    

![](assets/003.png)

-   输出门控（Output Gating）：使用SiLU和接收器实现输出门控，对每个头的输出向量进行计算。
    
-   通道混合子块（Channel Mixing Sub-block）：通过强非线性操作混合通道，增强模型的非线性特性。
    

### **3.3 展平和损失函数（Flatten and Loss Function）**

-   展平（Flatten）：最后一层的输出被展平并通过线性头部用于预测目标。
    
-   损失函数（Loss Function）：模型使用的损失函数是均方误差（MSE），用于衡量预测值与实际值之间的差异。
    

### **3.4 复杂度分析（Complexity Analysis）**

-   对RWKV-TS的复杂度进行了分析，其时间和空间复杂度均为O(L)，这比传统的Transformer模型的O(L^2)复杂度要优越得多。
    

![](assets/004.png)

### **3.5 与传统RNN模型的优势（Advantage over Traditional RNN Models）**

-   并行计算（Parallel Computation）：RWKV-TS利用线性RNN设计，允许并行计算，从而实现高计算效率和可扩展性。
    
-   增强的长期信息捕获能力（Enhanced Long-Range Information Capturing Capability）：与传统RNN相比，RWKV-TS即使在序列长度达到4096时也能保持强大的信息捕获能力。
    
-   编码器仅架构（Encoder-only Architecture）：RWKV-TS采用了编码器仅架构，避免了传统RNN的递归迭代模式，减少了推理步骤，消除了误差累积。
    

![](assets/005.png)

### **4\. 实验 (Experiment)**

### **4.1 效率分析（Efficiency Analysis）**

-   计算成本分析：实验首先对RWKV-TS模型的计算效率进行了评估。通过与其他基线模型（如PatchTST和TimesNet）的比较，RWKV-TS在训练和推理时间上展现出显著的优势。表格中列出了不同模型的参数数量、训练时间和推理时间，显示RWKV-TS在保持相似模型维度的情况下，大幅减少了参数数量和计算时间。
    

![](assets/006.png)

### **4.2 长期预测（Long-term Forecasting）**

-   实验设置：使用八个真实世界的基准数据集（包括气象、交通、电力、流感样疾病（ILI）和四个ETT数据集）来评估长期预测性能。
    
-   结果：RWKV-TS在长期预测任务中表现出与PatchTST相当的性能，并超过了其他基线模型。特别是与最新的方法TimesNet相比，RWKV-TS在平均均方误差（MSE）和平均绝对误差（MAE）上分别实现了12.58%和4.38%的相对降低。
    

![](assets/007.png)

### **4.3 短期预测（Short-term Forecasting）**

-   数据集：使用M4数据集进行短期预测任务的评估，该数据集包含不同频率的市场营销数据。
    
-   结果：RWKV-TS在短期预测任务上超越了多个基于Transformer的模型，并且与基于MLP的模型（如DLinear和LightTS）相比也展现出更好的性能。与当前最先进的模型TimesNet和N-BEATS的差距也很小。
    

![](assets/008.png)

### **4.4 少样本预测（Few-shot Forecasting）**

-   实验设置：在少样本学习范式下进行实验，仅使用训练数据中10%的时间步长。
    
-   结果：RWKV-TS在少样本学习任务中的表现超越了TimesNet、DLinear、PatchTST等方法，显示出优越的性能。与传统的基于CNN和单MLP模型相比，RWKV-TS在平均MSE上分别实现了28.95%和7.92%的相对降低。
    

![](assets/009.png)

### **4.5 时间序列分类（Time Series Classification）**

-   数据集：选择了10个UEA多变量时间序列分类数据集进行评估，涵盖了手势识别、动作识别、音频识别、医疗诊断等实际任务。
    
-   结果：RWKV-TS在分类任务上的平均准确率达到73.10%，超越了大多数基线模型，除了TimesNet（73.60%）。这证明了线性RNN能够产生健壮的时间序列表示。
    

![](assets/010.png)

### **4.6 时间序列异常检测（Time Series Anomaly Detection）**

-   数据集：使用五个常用的数据集进行异常检测任务的评估，包括SMD、MSL、SMAP、SWaT和PSM。
    
-   结果：RWKV-TS在异常检测任务上展现出良好的性能，平均F1分数达到83.89%，与其他最先进模型的性能相近，表明RWKV-TS能够有效地检测时间序列中的罕见异常。
    

![](assets/011.png)

### **4.7 插补（Imputation）**

-   数据集：使用六个真实世界的数据集进行插补任务的评估，这些数据集通常包含缺失数据。
    
-   结果：尽管RWKV-TS在插补任务上的性能不如TimesNet和PatchTST等最先进的模型，但它仍然超越了基于MLP的模型和某些基于Transformer的模型。由于RWKV-TS是单向RNN模型，只能观察到缺失值之前的信息，而基于Transformer的模型是双向的，能够捕获缺失值前后的信息，因此表现更好。
    

![](assets/012.png)

### **5\. 结论 (Conclusion)**

本文通过广泛的实验验证了RWKV-TS模型在多种时间序列任务上的性能，结果表明RWKV-TS不仅与现有的最先进方法具有可比性，而且在效率、延迟和内存使用方面具有显著优势。其线性时间复杂度和内存使用的特性，使得RWKV-TS在资源受限的终端设备上具有很高的竞争力。此外，RWKV-TS的成功实施反驳了传统RNN不适用于时间序列任务的观点，展示了RNN在处理时间序列方面的潜力和适应性，为未来时间序列分析领域的研究提供了新的方向和动力。

  

  

  

**论文及代码下载见星球**

**星球主要面向量化从业以及学术人员，提供了专业的交流社区，内有各类丰富的量化资源。目前人数不断增长，欢迎加入交流，加星球请扫我，某书购买加入有优惠活动：**

![](assets/013.png)

  

  

**入群交流请扫我：**

![](assets/014.jpg)

  

  

**点击蓝字**

![](assets/015.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/016.jpg)