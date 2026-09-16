# NeurIPS 25 | DMMV: 多模态视角可以为时间序列预测带来什么？

ChengAo Shen QuantML 2025-11-13 20:33 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492328&idx=1&sn=f5df3bd7d201a491f357dea57f7e5d99&chksm=cf03a6c948ac8fcad810c69cabba1c7c2fd014a5c93e0ff70f1e7244868abfa59e8f72170ba1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492328&idx=1&sn=f5df3bd7d201a491f357dea57f7e5d99&chksm=cf03a6c948ac8fcad810c69cabba1c7c2fd014a5c93e0ff70f1e7244868abfa59e8f72170ba1#rd)

本文作者来自休斯顿大学（University of Houston）、NEC美国实验室（NEC Laboratories America）与康涅狄格大学（University of Connecticut），由沈骋骜等人提出的论文《Multi-Modal View Enhanced Large Vision Models for Long-Term Time Series Forecasting (DMMV)》已被 NeurIPS 2025 正式接收。这项工作探索了如何在时间序列预测中引入大视觉模型（LVMs）与多模态视角（MMVs），开创了一个新的研究方向。

一作沈骋骜同样是QuantML社群成员，欢迎加入与作者一起交流。

论文链接：https://arxiv.org/abs/2505.24003

论文代码：https://github.com/D2I-Group/dmmv

![DMMV](assets/001.png)

DMMV

* * *

## 引言

长时序预测（LTSF）在能源、气象、医疗、交通等众多领域中具有核心作用。然而，传统基于数值序列的预测方法往往难以捕捉复杂的长期依赖模式。近年来，Transformer 与大语言模型（LLM）在序列建模中取得显著进展，同时，大视觉模型（LVM）如 ViT、MAE、BEiT 等在视觉领域表现卓越。受此启发，研究者开始尝试将时间序列“图像化”，使得视觉模型能够处理时间信号——每一维时间序列被视为类似图像通道的连续像素值。已有工作 VisionTS 证明了这种思路的有效性，但作者发现：LVM 在时间序列预测中存在“周期性归纳偏差”——模型对固定周期的模式表现优异，却难以同时建模全局趋势。这启发了本文提出的核心思想：能否让视觉模型负责周期性，而让数值模型掌控趋势？能否在统一框架下实现不同模态的协同？

## 方法

本文提出的 DMMV（Decomposition-based Multi-Modal View Framework） 是首个将视觉与数值两种模态结合，用于长时序预测的分解式多模态框架。

![DMMVFramework](assets/002.png)

DMMVFramework

### **基本思路**

DMMV 将时间序列视为多模态视角（Multi-Modal Views, MMVs），分别对应：

-   **数值视角**：保持原始序列，用于建模全局趋势；
    
-   **视觉视角**：将序列图像化后输入 MAE 等大视觉模型，用于捕捉周期与局部结构。
    

### **两种结构变体**

1.  **DMMV-S（Simple Decomposition）**
    
    使用移动平均法（Moving-Average）将时间序列分解为“趋势 + 季节”两部分。
    

-   趋势由数值预测器（如线性模型或Transformer）建模；
    
-   季节部分由视觉预测器（MAE）处理；
    
-   结果通过可学习门控（Gate）自适应融合。
    

3.  **DMMV-A（Adaptive Decomposition）**
    
    引入“反向预测-残差（Backcast-Residual）”机制，自动学习分解。
    

-   视觉模型首先重建历史窗口的不同区域（提出了高效的 BCMASK 策略）；
    
-   重建结果（Backcast）代表周期成分；
    
-   残差部分交由数值预测器建模趋势。
    
    这种方式无需显式设定核长，具备更强的自适应性。
    

## 实验

作者在八个经典公开数据集上进行评估，包括 ETTh1/2、ETTm1/2、Weather、Electricity、Traffic、Illness，并与 14 种主流模型对比（涵盖 Transformer、LLM、LVM、多模态模型等）。

### 核心结果

-   DMMV 框架在 MSE 与 MAE 平均排名中均居于前列。
    
-   DMMV-A的自适应分解显著缓解了 LVM 的周期性偏置，在 8 个数据集中 6 个取得最优 MSE 表现；相比 VisionTS（仅视觉视角）与 Time-VLM（视觉+文本），DMMV-A 同时获得更优精度与更低开销
    
-   相较于 LLM 系模型（如 Time-LLM、GPT4TS），DMMV 不仅性能领先，更显著降低计算负担。
    
-   多模态与视觉视角总体优于语言视角模型；数值预测器在非周期数据上仍具竞争力
    

![Main table](assets/003.png)

Main table

### 可视化

-   分解方式对比：对比分解结果可见，DMMV-A生成的季节成分更清晰、周期更平稳，而DMMV-S因固定核宽导致趋势过度平滑、季节部分混入噪声。
    
    ![decompose](assets/004.png)
    
    decompose
    
-   Mask策略对比：BCMASK能在时间维度上形成连续、平滑的周期结构，明显优于随机或无遮掩方式
    

![Mask](assets/005.png)

Mask

-   窗口长度对比：输入窗口长度对性能的影响：当上下文从336扩展到1152时，DMMV随之提升。对比其他模型DMMV在长窗口下依旧保持稳定优势，显示出其更好的趋势捕获与长期建模能力。
    

![Look-back windows](assets/006.png)

Look-back windows

## 总结

本文首次系统性地提出了一个基于多模态视角与大视觉模型（LVMs）的长时序预测框架。通过引入分解—融合机制（decomposition–fusion），DMMV 巧妙地利用了 LVM 在周期建模中的归纳偏置，并以数值分支弥补其在全局趋势建模上的不足，从而实现了周期与趋势的协同预测。

实验结果表明，DMMV 在多项标准数据集上显著优于现有方法，不仅在预测精度上达到了新的水平，更验证了多模态视角在时间序列分析中的潜力与价值。其自适应分解策略与门控融合设计为未来多模态时间序列学习提供了新的研究范式，也为“视觉增强的时间预测”这一方向奠定了方法论基础。未来工作可进一步优化模型效率，在保持高精度的同时降低视觉分支的计算负担，并探索更广泛的多模态任务扩展。

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/007.jpg)