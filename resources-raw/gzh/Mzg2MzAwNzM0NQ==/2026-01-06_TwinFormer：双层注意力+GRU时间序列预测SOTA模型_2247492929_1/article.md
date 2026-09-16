# TwinFormer：双层注意力+GRU时间序列预测SOTA模型

QuantML QuantML 2026-01-06 20:57 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492929&idx=1&sn=bfc00e0abde9b6612002422bced5e4d2&chksm=cfad56a9802cc7babf65278a57598dbbd6c0702713cb26973dd5a0d36dde58d3dc1e710818a4#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492929&idx=1&sn=bfc00e0abde9b6612002422bced5e4d2&chksm=cfad56a9802cc7babf65278a57598dbbd6c0702713cb26973dd5a0d36dde58d3dc1e710818a4#rd)

TwinFormer 是一种用于长序列时间序列预测的层级化 Transformer 架构。该模型将输入数据划分为非重叠的时间补丁（Patches），并分两个阶段进行处理：

（1）**局部 Informer（Local Informer）**：利用 top- 稀疏注意力机制对补丁内部的动力学进行建模，随后进行均值池化（mean pooling）；

（2）**全局 Informer（Global Informer）**：使用相同的 top- 注意力机制捕捉补丁之间的长程依赖关系。

随后，通过轻量级的 GRU 对全局上下文信息的补丁 Token 进行聚合，以实现直接的多步预测。这种架构实现了线性的  时间和内存复杂度。在涵盖天气、股价、电力等六个领域的八个真实世界基准数据集上，TwinFormer 在 34 项测试中占据了 27 项的前两名位置，并在多项指标上优于 PatchTST、iTransformer 和 FEDformer 等先进模型。消融实验证实了 top- 稀疏注意力优于 ProbSparse，且 GRU 聚合机制具有显著有效性。

代码见QuantML知识星球

![](assets/001.png)

## 1\. 引言 (Introduction)

长序列时间序列预测（LSTSF）在能源管理、金融建模和气候科学等领域至关重要，输入序列往往超过  到  个时间步。传统的统计方法和早期的循环神经网络（如 LSTM、GRU）在处理梯度消失和顺序计算效率方面存在局限，而标准 Transformer 的  二次计算复杂度使其在极长序列面前变得不可行。

尽管稀疏 Transformer（如 Informer, Autoformer）和基于补丁（Patch-based）的策略（如 PatchTST）通过降低序列长度和注意力复杂度在榜单上占据主导地位，但这些模型大多将时间序列视为扁平序列处理，忽视了现实世界时间数据的层级特性。受计算机视觉中“Transformer in Transformer (TNT)”概念的启发——即内部 Transformer 捕捉细节，外部 Transformer 处理语义补丁——本研究提出了 TwinFormer。该模型引入了双层层级注意力框架：底层通过局部注意力块（Local Attention）捕捉时间补丁内的短程依赖，顶层通过全局注意力块（Global Attention）对补丁间的压缩表示进行建模。理论上，这种架构符合时间抽象原则，即先独立处理局部动力学，再聚合为高层上下文知识。

主要贡献包括：

1.  提出了一种双层层级 Transformer 模型，分别通过 Local Informer 和 Global Informer 独立处理补丁内和补丁间的信息。
    
2.  借鉴视觉 Transformer，采用均值池化蒸馏（mean-pooling distillation）后接自定义稀疏注意力（Top-），创建高保真的补丁级压缩表示，有效降低了内存占用。
    
3.  建立了视觉与时间序列 Transformer 之间的结构类比，证明了计算机视觉机制在时间域的有效转化。
    

## 2\. 相关工作 (Related Work)

### 2.1 经典与早期深度学习方法

ARIMA 和 Prophet 等传统模型擅长捕捉线性模式和季节性，但在处理复杂非线性和高维多变量序列时表现不佳。基于 RNN 的方法（LSTM, GRU）虽然改善了非线性动力学建模，但受限于梯度问题和并行化能力的缺乏，在极长序列任务中效率低下。

### 2.2 基于 Transformer 的 LSTSF

Transformer 的自注意力机制解决了长程依赖问题，但其  复杂度是主要瓶颈。为解决此问题，Informer 提出了 ProbSparse 注意力和蒸馏操作，将复杂度降至 。Autoformer 和 FEDformer 引入了基于分解的架构和频域增强，实现了线性复杂度。Reformer 和 Linformer 等研究则关注于线性复杂度的设计。

### 2.3 基于补丁的时间序列模型

受 Vision Transformers 启发，PatchTST 开创性地将时间序列划分为补丁（Patches）作为 Token，显著降低了序列长度并保留了局部语义信息。后续工作如 iTransformer 和 Pathformer 进一步探索了多变量处理和多尺度补丁。这些模型证明了补丁化和通道独立性是当前高精度 LSTSF 的主流范式。

### 2.4 稀疏与高效注意力机制

除了 ProbSparse，Longformer 结合了局部滑动窗口和全局 Token。Top- 稀疏注意力因其简单性和训练稳定性而受到欢迎。本研究采用了这种简单而有效的 Top- 机制。

### 2.5 本研究的定位

现有的分层处理大多是在补丁化输入上应用单层 Transformer。TwinFormer 提出了双层架构，明确分离了细粒度的补丁内建模和长程的补丁间建模。此外，不同于简单的池化，TwinFormer 引入了轻量级 GRU 聚合器来处理全局上下文补丁 Token，这在 Transformer 主导的文献中较为少见。

## 3\. 方法论 (Methodology)

TwinFormer 旨在实现高效且富有表现力的注意力机制，避免 ProbSparse 的不稳定性。核心构建模块是自定义稀疏注意力（CSA），应用于局部和全局两个阶段。

### 3.1 自定义稀疏注意力 (Custom Sparse Attention, CSA)

模型采用 Top- 稀疏注意力机制。给定查询 、键  和值 ，标准注意力 Logits  计算如下：

其中  是注意力头维度。对于每个查询 ，仅保留  第  行中最大的 top- 个值（本研究中 ），其余值设为 。随后通过 softmax 获得稀疏注意力权重 ，最终输出为 。这种策略比 softmax 后掩码（masking）更稳定且高效。

### 3.2 模型架构

TwinFormer 在两个抽象层级上处理输入时间序列：

1.  **Local Informer**：处理局部补丁内的细粒度 Token 级依赖。
    
2.  **Global Informer**：处理补丁间的长程依赖。
    

#### 3.2.1 数据预处理与补丁化 (Data pre-processing and patching)

设输入时间序列为 ，预测未来  步。首先对特征变量进行 Min-Max 标准化。随后通过线性嵌入层将标准化序列投影到  维空间：

接着，将  划分为  个非重叠的补丁，每个补丁长度为 。生成的张量  维度为 。

#### 3.2.2 局部 Informer：补丁内建模 (Local Informer: intra-patch modeling)

每个补丁独立地由共享的 Local Informer 块处理。该块包含多头 CSA（Multi-Head CSA）、层归一化（LayerNorm）和前馈网络（FFN），并采用残差连接：

在局部处理后，通过在时间维度上进行**均值池化（Mean Pooling）**，将每个补丁聚合为单一表示：

这产生了一个紧凑的补丁嵌入序列 。

#### 3.2.3 全局 Informer：补丁间建模 (Global Informer: inter-patch modeling)

池化后的补丁表示被送入 Global Informer 块（同样使用多头 CSA + FFN），以捕捉补丁间的长程依赖：

输出为 。

#### 3.2.4 序列聚合：门控循环单元 (GRU)

在 Global Informer 生成全局上下文补丁表示后，模型采用 GRU 聚合器来总结跨补丁的长程时间动力学。GRU 按时间顺序处理补丁，并维护一个隐藏状态 ，逐步整合所有先前补丁的信息。具体公式遵循标准 GRU 更新规则（重置门 ，更新门 ，候选隐藏状态 ）。这使得模型能够捕捉不可逆的时间动态。

#### 3.2.5 预测头 (Forecasting head)

为了获得输出，模型仅使用 GRU 的最终隐藏状态  作为整个输入序列的固定维度摘要。该向量通过一个全连接线性层直接生成整个预测视界  的预测结果：

这种设计实现了单次前向传递的直接多步预测，无需自回归滚动，同时利用了 GRU 在建模序列依赖性方面的优势。

### 3.3 计算复杂度分析

TwinFormer 的处理分为三个阶段，整体复杂度实现了线性化：

1.  **补丁化**：。
    
2.  **Local Informer**：由于 Top- 稀疏注意力在每个长度为  的补丁内进行，单补丁复杂度为 。处理  个补丁的总复杂度为 。
    
3.  **Global Informer**：在  个补丁 Token 上应用 Top- 注意力，复杂度为 。这比标准 Transformer 的  有显著降低。
    
4.  **GRU 聚合与预测头**：复杂度为 ，线性投影为 。
    

**总体时间复杂度**为：

其中  且 。该复杂度与 Longformer 等最先进的稀疏 Transformer 相当，且显著优于 Vanilla Transformer 和 Informer。**内存复杂度**：峰值内存发生在局部注意力阶段，为 ，同样关于  呈线性关系。这使得模型能够在单张消费级 GPU（12-24 GB）上处理长达  的序列。

## 4\. 实验 (Experiments)

模型在涵盖天气、股价、温度、功耗、电力和疾病六个领域的八个真实世界基准数据集上进行了验证。

### 4.1 数据集

数据集包括 Weather, Electricity, ILINet, Temperature, Power consumption, Stock price (IDEA.NS) 以及四个 ETT 数据集。其中 Weather, Traffic 和 Electricity 数据集具有较大的时间序列规模，结果更具稳定性。

![](assets/002.png)

### 4.2 基线与指标

对比基线包括 PatchTST, Transformer, Informer, iTransformer, FEDformer。所有模型统一输入长度（B=48，注：此处原文可能指Batch size或Lookback window，结合上下文通常Lookback为输入长度，但在4.3节中提及Input length，需注意原文表述，此处保留原文  的表述，通常 LSTSF 中输入长度  更长，此处可能指 Batch Size 或特定实验设置）和预测长度（）。评估指标为 MAE 和 RMSE。

### 4.3 实施细节

数据归一化到 \[0, 1\]。使用 Adam 优化器，学习率 ，损失函数为  损失，早停机制设为 20 个 Epoch。

### 4.4 训练动态

在训练损失收敛性调查中，TwinFormer 在所有数据集上均表现出最快的收敛速度，并在训练结束时达到最低的训练损失。尽管在前几个 Epoch 损失略高，但迅速超越了 Informer, FEDformer, iTransformer, PatchTST 和 Vanilla Transformer，表现出清晰的下降轨迹。

### 4.5 消融研究

1.  **Top- vs. ProbSparse**：Top- 稀疏注意力在多数数据集和预测视界上一致优于或匹配 ProbSparse 的性能。特别是在 Power consumption（MAE 从 1528.64 降至 1505.65）、IDEA.NS 和 Electricity 数据集上取得了大幅改进。这表明直接选择信息量最大的查询（Query）比依赖概率假设更有效。
    
2.  **GRU 聚合器的有效性**：将 GRU 与 LSTM、Conv1D 和标准 Attention-decoder 进行对比。
    

-   在单变量 **Temperature** 数据集上，GRU 模型在 MAE (0.6188)、RMSE (0.8094) 和  (0.9349) 上均取得最佳结果，相对 LSTM 提升 3-4%。
    
-   在多变量 **Weather** 数据集（21 个高度相关变量）上，GRU 表现极具竞争力（MAE 20.3328），仅略微落后于 Conv1D 和 Attention-Decoder，但在无需显式注意力机制的情况下保持了稳健性。 这证实了 GRU 作为轻量级但强大的基线，能够有效捕捉序列动态。
    

## 5\. 结果与讨论 (Results and discussion)

实验结果显示 TwinFormer 在多个数据集和预测视界上优于其他模型：

-   **Temperature**：在四个预测视界中的三个取得了最低误差，尤其是在较短视界（96步）上优于 PatchTST 和 iTransformer。
    
-   **单变量数据集**（Power consumption, IDEA.NS）：在 MAE 上持续排名第一。
    
-   **大型多变量数据集**（Electricity, Weather, ETT）：TwinFormer 表现稳健，在 ETTm1 上排名第一，在其他数据集上通常排名第二，紧随 PatchTST 之后。
    

这表明“局部到全局”的层级处理有效地处理了细粒度的局部模式和高维设置下的长程依赖。TwinFormer 的高效性能归功于其关键架构设计：Top- 稀疏注意力提供了比 ProbSparse 更稳定有效的结果；基于 GRU 的序列聚合器有效地捕捉了全局上下文补丁的不可逆时间动态，优于 LSTM 和 Conv1D 等替代方案。更快的收敛速度和更低的最终训练损失进一步表明层级架构比扁平的 Transformer 基线更易于优化。总体而言，TwinFormer 在 34 项对比中获得了 27 次前两名的成绩（其中 17 次第一，10 次第二），展现了其鲁棒性。

![](assets/003.png)

![](assets/004.png)

## 6\. 结论 (Conclusion)

本研究介绍了 TwinFormer，这是一种层级 Transformer 架构，通过 **Local Informer** 显式分离细粒度的补丁内建模，并通过 **Global Informer** 捕捉长程补丁间依赖，最后辅以轻量级 **GRU** 聚合器进行直接多步预测。这种受视觉层级启发的双阶段处理管道结合固定的 Top- 稀疏注意力，在八个真实世界数据集上实现了最先进（SOTA）的性能，持续优于 PatchTST、iTransformer、FEDformer 等强力基线。

消融研究验证了设计选择的合理性：Top- 注意力提供了一致的改进；GRU 聚合器在单变量和中等多变量序列上优于其他解码器。该架构在输入长度  上保持了线性的时间和内存复杂度 ，使得在单张消费级 GPU 上高效训练和推理由  时间步组成的序列成为可能。尽管 Top- 可能会忽略某些长程依赖，且 GRU 解码器无法显式建模预测未来步骤间的时间依赖，但 TwinFormer 仍为长序列预测提供了一个高效且强大的解决方案。

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/005.jpg)