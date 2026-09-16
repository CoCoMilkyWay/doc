# TurboQuant用于量化选股：Qlib复现实测，IC真提升了

QuantML QuantML 2026-03-26 19:29 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493608&idx=1&sn=cd4c79c8e905d641ce48ab97f2f442a4&chksm=cf171d478700649890ce429e23b11798e947aadd2ba984c359f47adb50934f01d0bc6a6eb6b0#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493608&idx=1&sn=cd4c79c8e905d641ce48ab97f2f442a4&chksm=cf171d478700649890ce429e23b11798e947aadd2ba984c359f47adb50934f01d0bc6a6eb6b0#rd)

> “
> 
> **导读：**随着大模型（LLM）进入“长上下文（Long-Context）”时代，如何压缩海量的 KV Cache 成为了学界和工业界的核心难题。近日，Google Research 与 DeepMind 联合推出了一项名为 **TurboQuant** 的极速向量量化技术，不仅实现了趋近理论极限的压缩率，更保证了**无偏的内积估计**。

TurboQuant 是一种兼具理论极值与工程高效的在线（数据无关，Data-oblivious）向量量化算法，其核心特点在于通过巧妙的“随机正交旋转”将任意输入转化为独立的高斯/Beta分布，无需离线校准即可直接应用最优标量量化，实现逼近信息论极限的极低均方误差（MSE）；更为突破的是，针对传统MSE量化在内积计算中存在的系统性偏差，它首创了“MSE量化拟合+QJL残差极化”的两阶段策略，在极低位宽（如2-bit/4-bit）下依然能严格保证无偏的内积估计，从而在实现极致压缩与高度硬件并行友好的同时，完美适配大模型 KV Cache 压缩与海量高维向量近似检索等对精度和实时性要求极高的前沿AI场景。

### 一、 天下苦“显存”久矣：从大模型到量化选股

在自然语言处理领域，长文本推理的算力瓶颈在于注意力机制（Attention）。海量的 Query 和 Key 向量内积运算（）占据了恐怖的显存带宽。

巧合的是，**现代量化选股模型也正在遭遇一模一样的瓶颈：**

1.  **高频/超长序列建模**：如果你在使用分钟级甚至 Tick 级数据，单只股票的时间步长可能高达数万。Transformer 处理这种长序列时，显存消耗呈平方级爆炸。
    
2.  **全市场横截面（Cross-sectional）Attention**：很多前沿的选股模型（如基于图或注意力的多票联动模型），需要在一个 Batch 中把全市场 5000 只股票扔进去做相互 Attention。 的注意力矩阵，让普通显卡望洋兴叹。
    

为了解决这个问题，业界常采用**向量量化（Vector Quantization, VQ）**。但传统方法（如 PQ 或基于 Hessian 的量化）大多需要离线校准（Offline Calibration），一旦数据分布发生变化，性能就会暴跌。对于**分布随时都在漂移（Non-stationary）的金融市场**来说，传统量化显然水土不服。

### 二、 破局者 TurboQuant：为何它对金融数据异常契合？

Google 提出的 **TurboQuant** （论文：_TurboQuant: Online Vector Quantization with Near-optimal Distortion Rate_）完美解决了上述痛点，它有两个极其优雅的特性，简直是为金融时序数据量身定制的：

![](assets/001.png)

#### 1\. Data-oblivious（数据无关性）：专治金融市场“分布漂移”

TurboQuant 不需要拿过去一年的股票数据来离线训练“量化码本”。它采用了一个极其巧妙的数学技巧：**随机旋转（Random Rotation）**。 不管你的股票特征（Alpha 因子）原本是什么分布，只要乘上一个随机生成的正交矩阵，在高维空间中，各个坐标的分布就会被强制“拍扁”成标准的高斯/Beta 分布。随后，模型只需对这个标准分布进行标量量化即可。**这意味着，无论牛熊市怎么切换，TurboQuant 都不用重新校准！**

#### 2\. 无偏内积估计（Unbiased Inner Product）：守护微弱的 Alpha 信号

在计算 Attention 时，我们需要的是  和  的内积。普通的量化方法（如只针对均方误差 MSE 优化的量化）会导致内积计算**有偏（Biased）**，这会严重破坏股票间的排序关系（Rank）。 TurboQuant 采用了一种**“两阶段量化”**策略（`TurboQuant_prod`）：

-   **Stage 1 (MSE Quant)** ：先用  个 bit 拟合原始向量的 MSE，得到一个近似向量。
    
-   **Stage 2 (QJL 极化)** ：再用 1 个 bit，通过 QJL（Quantized Johnson-Lindenstrauss）算法对**残差**进行量化。 这套组合拳不仅将位宽压榨到了极致（2-bit/4-bit），还在数学上严格证明了其内积估计的**期望与真实值绝对一致（无偏）**！
    

### 三、 硬核实战：把 TurboQuant 装进 Qlib 的选股 Transformer

理论再好，也得跑个回测见真章。要在 `Qlib` 的选股模型中验证 TurboQuant 的威力，我们不需要立刻去写底层的 CUDA C++ 算子。

我们首先要做的是**“前向敏感性模拟测试（Forward Simulation）”**——在 PyTorch 中使用 Float32 模拟 2-bit 量化的信息丢失过程。如果模拟量化后，模型依然能选出好股票（IC/IR 不掉），那这项技术就完全可行！

以下是我们基于论文核心算法复现的 PyTorch 代码模块：

#### 1\. 核心模块：TurboQuant\_prod 的 PyTorch 模拟

`import torch   import torch.nn as nn   import math      class TurboQuantProdSim(nn.Module):       """       模拟 TurboQuant_prod (优化无偏内积)       采用 2-bit 模拟: 1-bit MSE量化 + 1-bit QJL 残差量化       """       def __init__(self, d):           super().__init__()           self.d = d           # 1. 生成随机正交旋转矩阵 Pi (应对非平稳数据)           H = torch.randn(d, d)           Q, _ = torch.linalg.qr(H)           self.register_buffer('Pi', Q)                      # 2. 生成随机投影矩阵 S (用于 QJL 1-bit 残差量化)           self.register_buffer('S', torch.randn(d, d))                      # 1-bit 标量量化的最优 k-means 质心缩放系数           self.c = math.sqrt(2 / (math.pi * self.d))          def forward(self, x):           # 提取范数信息 (量价特征的 norm 包含重要信息，必须保留)           norm = torch.norm(x, p=2, dim=-1, keepdim=True) + 1e-8           x_unit = x / norm                      # --- Stage 1: Quant_mse (1-bit) ---           # 随机旋转打散分布           y = torch.matmul(x_unit, self.Pi.T)           # 1-bit 量化 (看正负号)           y_tilde = torch.where(y > 0, torch.full_like(y, self.c), torch.full_like(y, -self.c))           x_mse = torch.matmul(y_tilde, self.Pi)                      # --- Stage 2: Quant_prod (QJL on residual) ---           r = x_unit - x_mse           gamma = torch.norm(r, p=2, dim=-1, keepdim=True)           # 极低位宽的符号投影           qjl_z = torch.sign(torch.matmul(r, self.S.T))           qjl_z = torch.where(qjl_z == 0, torch.ones_like(qjl_z), qjl_z)                      scale = math.sqrt(math.pi / (2 * self.d))           r_tilde = scale * gamma * torch.matmul(qjl_z, self.S)                      # --- 重建近似向量并恢复范数 ---           x_tilde = x_mse + r_tilde           return x_tilde * norm   `

#### 2\. 魔改 Transformer 的 Attention 机制

现在，我们把这把“手术刀”插进 Multi-Head Attention 中，拦截 `Query` 和 `Key`，让它们在做点积前经历一波“极限压缩”。

`class QuantizedMultiHeadAttention(nn.Module):       def __init__(self, d_model, num_heads, dropout=0.1):           super().__init__()           self.head_dim = d_model // num_heads           # ... (常规的 Q/K/V Linear 定义略) ...                      # 为 Q 和 K 实例化 TurboQuant_prod           self.quantizer_q = TurboQuantProdSim(self.head_dim)           self.quantizer_k = TurboQuantProdSim(self.head_dim)          def forward(self, x):           # ... (reshape 过程略) ...                      # 核心：拦截 Q 和 K，强行注入 TurboQuant 的量化噪声           Q_quant = self.quantizer_q(Q)           K_quant = self.quantizer_k(K)                      # 计算无偏内积 (Attention Score)           Q_quant = Q_quant.transpose(1, 2)           K_quant = K_quant.transpose(1, 2)                      scores = torch.matmul(Q_quant, K_quant.transpose(-2, -1)) / math.sqrt(self.head_dim)           attn_weights = torch.softmax(scores, dim=-1)                      # ... (后续乘 V 的操作略) ...   `

代码已开源，地址：https://github.com/QuantML-Community/turboquant-qlib

### 四、 结果对比

实验条件保持一致：

数据集都是 Alpha158 筛出来的 25 个特征。 市场都是 CSI300。 训练区间是 2016 年到 2019 年，验证区间是 2020 年，测试区间是 2021 年到 2025 年。 序列长度都是 60。 模型主干也保持一致，d\_model=8，n\_epochs=100，seed=0。

基线模型是 Qlib 原始的时序 Transformer。 对照模型则是在 attention 里，把 Q 和 K 投影后的向量送入 TurboQuant 的量化模拟模块，再继续做自注意力计算。

也就是说，这次复现并没有改整个框架，而是在 Transformer 的 attention 内部插入了 TurboQuant 的两阶段量化逻辑。这样做的好处是，比较直接，变量也少，最后看到的差异基本可以归因到量化模块本身。

相比于传统Transformer， TurboQuant的结构带来了3点改进：

1.  IC提升： Transformer 样本外的IC为0.03829， TurboQuant 样本外IC为0.04061， 提升幅度大约在6%左右
    
2.  训练效率提升： Transformer 10个epoch 训练耗时 2分23秒， TurboQuant 耗时为 1分28秒， 单轮效率提升～40%
    
3.  loss更加平滑： Transformer 训练到13轮达到loss最优，TurboQuant 训练到99轮（设置的最大epoch数，理论上继续训练loss更低），两者最终loss相差不大。
    

凭借“随机旋转与无偏内积估计”的核心技术，它不仅天然免疫金融市场的分布漂移难题（无需离线校准），其极致的量化截断更充当了强效的空间正则化器，有效过滤了低信噪比数据的微小噪声，打破了模型极易过拟合的“早停”魔咒，使样本外IC逆势提升约6%、Loss收敛更加深邃平滑；同时，极高的压缩率大幅降低了显存占用与数据搬运开销，不仅令单轮训练效率暴涨40%，更一举打破了算力天花板，让普通硬件也能轻松驾驭极度耗费资源的“全市场横截面多票交互”与“超长高频时序建模”。

### 结语

从 LLM 的 KV Cache 压缩，到量化交易的横截面加速，技术的底层逻辑往往是相通的。**TurboQuant** 用极致的数学之美（随机旋转 + QJL 极化）提供了一种优雅的技术手段。

QuantML-Qlib已同步更新，欢迎加入星球获取。

> “
> 
> **互动时间：**你在训练横截面 / 高频选股模型时，遇到过什么瓶颈吗？欢迎在评论区分享你的看法与实测经验！

  

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)