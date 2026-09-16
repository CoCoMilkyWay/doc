# QuantML-Qlib Model | ICLR 24: 基于独立Patch的时序预测模型

QuantML QuantML 2024-07-12 19:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485428&idx=1&sn=5cab78083a051bf5d458f8981db615b9&chksm=cf2d002ea90b79c6534e5fd4205a919212e405491aa9c250e5e6fc7e94096eb818d093fee701#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485428&idx=1&sn=5cab78083a051bf5d458f8981db615b9&chksm=cf2d002ea90b79c6534e5fd4205a919212e405491aa9c250e5e6fc7e94096eb818d093fee701#rd)

Content

![](assets/001.png)

论文提出了一种新的时间序列嵌入方法，主要观点是独立地嵌入时间序列块（patches），而不是捕捉这些块之间的依赖关系。

### **1\. 引言 (Introduction)**

引言部分介绍了时间序列数据在多种下游任务中的应用，并强调了深度学习在时间序列分析中的优越性能，特别是在表示学习方面。作者指出，自我监督学习，特别是对比学习（CL）和掩码建模（MM），是利用未标记数据的有效策略。论文提出了一种新的时间序列表示学习策略，称为Patch Independence for Time Series (PITS)，它通过独立嵌入时间序列块而不是捕捉块之间的依赖关系，来提高时间序列预测和分类的性能，并且在参数数量和训练/推理时间上更为高效。

![](assets/002.png)

### **2\. 相关工作 (Related Works)**

本章深入探讨了自我监督学习（SSL）在时间序列分析中的进展，特别是对比学习（CL）和掩码建模（MM）作为SSL的两种有效策略。本章回顾了SSL在自然语言处理和计算机视觉中的应用，并详细讨论了时间序列领域的MTM任务，该任务通过部分掩蔽时间序列并预测掩蔽部分来学习表示。此外，本章还对比了不同的时间序列预训练方法，并提出了PITS方法，它通过独立地嵌入时间序列块，而不是依赖于块之间的依赖关系，从而提供了一种新颖的视角来改进时间序列的表示学习。

![](assets/003.png)

### **3\. 方法 (Methods)**

第三章详细介绍了论文提出的Patch Independence for Time Series (PITS) 方法。PITS方法的核心思想是独立地嵌入时间序列块，而不是依赖于块之间的复杂依赖关系。

### **3.1 块独立任务：块重建 (Patch-Independent Task: Patch Reconstruction)**

PITS方法提出了一种新的预训练任务，称为块重建任务。与传统的掩码建模任务不同，块重建任务不是预测被掩蔽的块，而是自编码未掩蔽的块。这种方法不需要考虑其他块的信息，从而实现了块的独立性。

### **3.2 块独立架构：多层感知器 (Patch-Independent Architecture: MLP)**

为了进一步实现块的独立性，PITS采用了简单的多层感知器（MLP）作为编码器架构。MLP架构专注于提取每个块的独立表示，不编码时间序列块之间的交互。这与传统的Transformer架构不同，后者依赖于多头自注意力机制来捕捉序列内部的依赖关系。

### **3.3 补充对比学习 (Complementary Contrastive Learning)**

为了提高学习表示的性能，PITS引入了补充对比学习（CL）。CL通过生成两个视图（通过互补掩码策略）来创建正样本对。这种方法不需要额外的前向传递，因此在计算上非常高效。

![](assets/004.png)

### **3.4 目标函数 (Objective Function)**

PITS的目标函数是重建损失和分层对比损失的总和。重建损失用于确保模型能够准确重建未掩蔽的块，而对比损失则用于确保模型能够区分不同块的表示。

####     **3.4.1 重建损失 (Reconstruction Loss)**

    重建损失是衡量模型重建未掩蔽块的准确性的指标。它通过计算重建块和原始块之间的差异来定义。

####     **3.4.2 对比损失 (Contrastive Loss)**

    对比损失是基于相似性度量的softmax概率来定义的。它鼓励模型将相似的块表示拉近，同时将不相似的块表示推远。

  

### **4\. 实验 (Experiments)**

### **4.1 实验设置 (Experimental Settings)**

实验部分首先介绍了任务和评估指标。作者选择了时间序列预测（TSF）和分类（TSC）两个下游任务来验证PITS方法的有效性。对于评估指标，TSF任务使用了均方误差（MSE）和平均绝对误差（MAE），而TSC任务使用了准确率、精确率、召回率和F1分数。

### **4.2 时间序列预测 (Time Series Forecasting)**

在这一部分，作者详细描述了用于时间序列预测的数据集和基线方法。数据集包括四个ETT数据集（ETTh1, ETTh2, ETTm1, ETTm2）、天气、交通和电力数据集。基线方法涵盖了基于Transformer的模型，如PatchTST、SimMTM、FEDformer和Autoformer，以及线性/MLP模型，如DLinear和TSMixer。

####     **4.2.1 标准设置 (Standard Setting)**

    表2展示了PITS方法与现有最先进方法在多变量时间序列预测任务上的性能比较。结果显示，PITS在效率和性能上都具有竞争力。

####     **4.2.2 迁移学习 (Transfer Learning)**

    作者还探讨了PITS在迁移学习场景下的表现，包括领域内和跨领域迁移学习。表4展示了PITS在不同迁移学习设置下的平均MSE结果，证明了其在大多数情况下都优于现有方法。

### **4.3 时间序列分类 (Time Series Classification)**

在这一部分，作者使用了五个不同的数据集进行时间序列分类任务的实验，包括SleepEEG、Epilepsy、FD-B、Gesture和EMG数据集。基线方法包括TS-SD、TS2Vec、CoST、LaST、Mixing-Up、TS-TCC、TF-C、TST、TimeMAE和SimMTM。

![](assets/005.png)

####     **4.3.1 标准设置 (Standard Setting)**

    表5展示了PITS方法在SleepEEG数据集上的性能，与所有现有最先进方法相比，PITS在所有评估指标上都取得了最佳性能。

####     **4.3.2 迁移学习 (Transfer Learning)**

    表6展示了PITS在迁移学习设置下的性能，包括领域内和跨领域迁移学习。结果表明，PITS在所有场景中都优于现有方法，尤其是在具有挑战性的跨领域迁移学习设置中。

![](assets/006.jpg)

### **4.4 消融研究 (Ablation Study)**

作者进行了一系列消融研究来评估PITS中不同组件的影响。

####     **4.4.1 PI/PD任务/架构的影响 (Effect of PI/PD Tasks/Architectures)**

    表7展示了使用不同预训练任务和架构对时间序列预测性能的影响。结果表明，无论架构选择如何，使用PI任务进行预训练始终优于PD任务。

![](assets/007.png)

####     **4.4.2 隐藏维度和dropout (Hidden Dimension and Dropout)**

    图4展示了不同隐藏维度和dropout率对模型性能的影响。结果表明，使用dropout对于学习高维表示是必要的。

![](assets/008.png)

####     **4.4.3 不同预训练任务的性能 (Performance of Various Pretrain Tasks)**

    表8比较了使用不同预训练任务对模型性能的影响，强调了所提出的PI任务的有效性。![](assets/009.png)

####     **4.4.4 下游任务的表示选择 (Which Representation to Use for Downstream Tasks)**

    表9和表10探讨了在下游任务中使用不同层级的表示对性能的影响。

![](assets/010.png)

####     **4.4.5 对比学习的层次设计 (Hierarchical Design of Complementary CL)**

    表11评估了对比学习的层次设计对性能的影响。

![](assets/011.png)

####     **4.4.6 与PatchTST的比较 (Comparison with PatchTST)**

    表12展示了PITS与PatchTST相比，通过改变预训练任务和编码器架构对性能的改进。

![](assets/012.png)

### **5\. 分析 (Analysis)**

本章深入探讨了PITS方法的鲁棒性、效率和解释性。通过一系列实验，作者评估了块独立（PI）任务与块依赖（PD）任务在面对分布偏移时的表现，证明了PI任务在所有情况下都更为稳健。同时，比较了多层感知器（MLP）和Transformer架构对不同补丁大小的鲁棒性，发现MLP在各种补丁尺寸下均表现更佳。此外，论文还讨论了MLP在解释性方面的优势，展示了其在捕捉时间序列季节性方面的能力。最后，通过可视化和效率分析，论文进一步证实了PITS方法在时间序列表示学习中的有效性和实用性。

![](assets/013.png)

### **6\. 结论 (Conclusion)**

本文强调了PITS方法在时间序列表示学习中的有效性。作者提出，与以往侧重于时间序列块之间依赖性的工作不同，PITS通过引入块重建任务和采用块级独立多层感知器（MLP），展示了在预测和分类任务上的卓越性能。此外，PITS在面对分布偏移和不同补丁大小时的鲁棒性，以及在参数数量和训练效率方面的优势，使其在实际应用中具有重要价值。论文还讨论了PITS在不同领域应用的潜力，并强调了简单预训练任务和模型架构在未来研究中的重要性。

  

  

  

2\. 代码部分

  

我们在QuantML-Qlib实现Supervised PITS模型。由于有部分c代码，需要编译后再使用，在QuantML-Qlib根目录下运行以下命令进行编译

  

```
python  setup.py build_ext --inplace
```

然后将我们的代码拷贝进examples/benchmarks，目前quantml-qlib在qlib的基础上已经支持40多个模型，包括线性模型，树模型，MLP类，CNN类，RNN类，GNN类，Transformer类以及KAN等，各类SOTA模型会不断更新。

![](assets/014.png)

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

模型代码在PITS.py中, 代码下载地址见星球。

模型回测结果：

策略alpha：18.25%，超额最大回撤6.80%，超额信息比1.98![](assets/015.png)  

  

**代码已更新在星球，****加入星球请扫我：**

![](assets/016.jpg)

  

  

  

入群请扫我：  

![](assets/017.jpg)

  

  

**点击蓝字**

![](assets/018.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/019.jpg)