# 论文复现 | 基于隔夜与日间收益的d-LE-SC有向网络聚类

QuantML QuantML 2025-12-03 18:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492574&idx=1&sn=f85a50af8c66a90bc76b04fcf22b4f6b&chksm=cf34dc31807e0cea723966f235558ba9853ed24c26062d851041d56b2d690995a341c23f6791#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492574&idx=1&sn=f85a50af8c66a90bc76b04fcf22b4f6b&chksm=cf34dc31807e0cea723966f235558ba9853ed24c26062d851041d56b2d690995a341c23f6791#rd)

上周我们分享了[解码动量溢出：日内-隔夜收益的非对称结构](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492523&idx=1&sn=421d4ab5766e62a516cf7f72f95bf077&scene=21#wechat_redirect)，近期也有多篇关于隔夜与日间分析的券商研报，本文我们进一步实现对《A tug of war across the market: overnight-vs-daytime lead-lag networks and clustering-based portfolio strategies》的复现，代码来自Hugo，基于Python与PyTorch进行复现，并且在大规模矩阵计算下使用GPU加速实现以及许多工程优化细节。完整代码见QuantML知识星球

## 1\. 引言

在量化投资领域，股票间的相关性网络通常被视为无向图（Undirected Graph），即假设股票A对股票B的影响与股票B对股票A的影响是对称的。然而，市场微观结构研究表明，信息的传递往往具有方向性和时滞性。牛津大学数学研究所发表的论文《A tug of war across the market: overnight-vs-daytime lead-lag networks and clustering-based portfolio strategies》提出了一种创新的视角：通过将日收益率分解为**隔夜收益率（Overnight Returns）**和**日间收益率（Daytime Returns）**，构建有向的领先-滞后（Lead-Lag）网络，并利用**d-LE-SC（directed Likelihood Estimation Spectral Clustering）**算法识别市场中的“领导者（Leaders）”和“追随者（Laggards）”，进而构建Alpha策略。

![](assets/001.png)

## 2\. 模型理论框架

### 2.1 收益率分解与网络构建

传统的日收益率（Close-to-Close）掩盖了不同交易时段的信息含量。模型首先将日收益率  分解为两部分：

1.  **隔夜收益率 ()** ：从前一交易日收盘到当日开盘的收益。主要反映非交易时段的全球市场信息及突发新闻。
    
2.  **日间收益率 ()** ：从当日开盘到当日收盘的收益。主要反映市场对隔夜信息的消化及日内交易行为。
    

基于此，我们可以构建不同类型的领先-滞后网络。以“隔夜领先日间（Overnight-Lead-Daytime）”网络为例，其相关性定义为：

该矩阵  描述了股票  的隔夜表现对股票  日间表现的预测能力。为了构建邻接矩阵 ，通常取相关系数的绝对值：。

![](assets/002.png)

  

### 2.2 d-LE-SC 聚类算法

d-LE-SC 算法是本策略的核心，它是基于有向随机块模型（Directed Stochastic Block Model, DSBM）推导出的谱聚类方法。传统的谱聚类处理的是对称矩阵，而 d-LE-SC 处理的是非对称的邻接矩阵，旨在最大化观测数据的似然函数。

算法的核心在于构建一个复值 Hermitian 矩阵 ，该矩阵融合了网络的连通性（对称部分）和方向性（反对称部分）。 的定义如下：

其中：

-    为虚数单位。
    
-    捕捉了网络的方向性不平衡（即领先-滞后关系）。
    
-    捕捉了网络的总体连通强度。
    
-    是 DSBM 的模型参数，表征网络中方向性噪声的水平。
    

通过对矩阵  进行特征分解，取对应最大特征值的特征向量 。 的实部和虚部  构成了节点在二维空间的嵌入表示。随后，对该嵌入进行 K-Means 聚类，将股票划分为“领先簇”和“滞后簇”。

这是一个迭代优化的过程：

1.  初始化 。
    
2.  构建  矩阵并计算特征向量。
    
3.  执行聚类。
    
4.  根据聚类结果产生的簇间流量（Flow）更新 。
    
5.  重复直至收敛。
    

## 3\. 工程化复现与实现细节

本项目基于 PyTorch 框架实现了 d-LE-SC 算法，主要考量在于特征分解（Eigen-decomposition）和大规模矩阵运算在 CPU 上效率较低，利用 GPU 加速可显著提升回测效率。

复现代码主要包含以下核心模块：

-   `lead_lag_network.py`：负责收益率计算及相关性矩阵构建。
    
-   `dlesc_clustering.py`：实现核心的 d-LE-SC 算法及 GPU 加速。
    
-   `factor_computation.py`：基于聚类结果计算因子得分与交易信号。
    
-   `factor_pipeline.py`：整合数据流与计算流的流水线。
    

### 3.1 核心算法实现 (d-LE-SC)

在 `dlesc_clustering.py` 中，我们定义了 `DLESCClustering` 类。为了保证数值稳定性，我们在构建 Hermitian 矩阵时对参数  进行了截断处理。

以下是 Hermitian 矩阵构建的核心代码实现：

`def _compute_hermitian_matrix(self, A: torch.Tensor) -> torch.Tensor:       """       计算算法核心的Hermitian矩阵H       H = i * w_dir * (A - A^T) + w_sym * (A + A^T)       """       if self.eta isNone:           raise ValueError("η参数未初始化")          # 将η限制在合理范围内，防止log(0)       eta_tensor = torch.tensor(self.eta, device=self.device, dtype=torch.float32)       eta_clipped = torch.clamp(eta_tensor, min=1e-10, max=0.5 - 1e-10)          # 计算权重系数       # 反对称部分权重：w_directional = log((1-η)/η)       w_directional = torch.log((1 - eta_clipped) / eta_clipped)       # 对称部分权重：w_symmetric = log(1/(4η(1-η)))       w_symmetric = torch.log(1 / (4 * eta_clipped * (1 - eta_clipped)))          # 计算矩阵的对称和反对称部分       A_diff = A - A.T  # 反对称部分，表征方向       A_sum = A + A.T   # 对称部分，表征连接          # 构建复值Hermitian矩阵       # 实部来自对称部分，虚部来自反对称部分       H_real = w_symmetric * A_sum       H_imag = w_directional * A_diff          # 组合成复值张量       H = torch.complex(H_real, H_imag)          return H   `

### 3.2 数值稳定性与容错机制

在处理实际金融数据时，邻接矩阵可能存在病态（ill-conditioned）情况，导致特征值分解不收敛。项目在 `_compute_top_eigenvector` 方法中实现了多级容错机制：

1.  **正则化扰动**：首先尝试在矩阵对角线上加入微小的扰动项 （例如 ），提高数值稳定性。
    
2.  **动态调整**：如果收敛失败，增大正则化参数重试。
    
3.  **SVD 备选**：如果特征分解（Eigendecomposition）依然失败，退化使用奇异值分解（SVD）提取主成分。对于 Hermitian 矩阵，SVD 的左奇异向量与特征向量在模上等价。
    

代码片段如下：

`@retry(stop=stop_after_attempt(3), wait=wait_fixed(1), retry=retry_if_exception(_is_convergence_error))   def _compute_top_eigenvector(self, H: torch.Tensor) -> torch.Tensor:       try:           # 尝试1: 微小正则化           epsilon = 1e-7           H_reg = H + epsilon * torch.eye(H.shape[0], device=H.device)           eigenvalues, eigenvectors = torch.linalg.eigh(H_reg)           top_idx = torch.argmax(eigenvalues.real)           return eigenvectors[:, top_idx]       except RuntimeError:           # 降级策略...           # 尝试3: SVD分解作为最后的保障           U, S, Vh = torch.linalg.svd(H)           return U[:, 0]   `

### 3.3 因子计算与策略构建

聚类完成后，我们将获得“领先簇” () 和“滞后簇” ()。根据论文逻辑，投资组合的构建分为三步：

1.  **信号生成**：计算领先簇中股票的平均收益作为信号方向 。
    
2.  **股票打分**：在滞后簇内部，根据股票与领先簇的连接强度进行排序。
    

-    （对于滞后簇中的股票 ）
    

4.  **多空构建**：
    

-   如果 （看多）：做多滞后簇中与领先簇正相关性最强的股票（Top Lag），做空负相关性最强的股票（Bottom Lag）。
    
-   如果 （看空）：反向操作。
    

这一逻辑封装在 `factor_computation.py` 的 `LeadLagFactorCalculator` 类中：

`def generate_trading_signal(self, lead_scores, daily_returns, stock_codes):       """       基于领先簇的表现生成全市场信号       S = Mean(Returns of Top Leaders)       """       top_leads = self.sorted_values(lead_scores, self.lead_percentile, True)       lead_indices = [stock_codes.index(s) for s in top_leads if s in stock_codes]              if not lead_indices:           return 0.0                  lead_returns = daily_returns[lead_indices]       signal = np.mean(np.nan_to_num(lead_returns))       return signal   `

### 3.4 并行计算与内存优化

由于需要计算滚动窗口（例如 60 天窗口）下的相关性矩阵，对于 A 股全市场（约 5000 只股票）而言，计算量巨大。`lead_lag_network.py` 中的 `ParallelConfig` 类实现了智能的资源管理。

为了避免生成海量的滚动窗口数据导致内存溢出（OOM），我们使用了 `utils.py` 中的 `sliding_window` 函数，利用 NumPy 的 `as_strided` 创建视图而非物理复制数据。同时，在计算 Spearman 相关性（需要排序操作）时，优先调用 Pandas 底层 C 语言实现的 `algos.rank`，比 `scipy.stats.rankdata` 快一个数量级。

`# utils.py 中的内存优化实现   def sliding_window(arr: np.ndarray, window: int, step: int = 1):       # ... 省略校验逻辑       new_shape = (num_windows, window) + arr.shape[1:]       new_strides = (arr.strides[0] * step, arr.strides[0]) + arr.strides[1:]              # 返回视图，不占用额外内存       sliding_view = np.lib.stride_tricks.as_strided(           arr, shape=new_shape, strides=new_strides, writeable=False       )       yield from sliding_view   `

## 4\. 运行复现流程

本项目提供了完整的流水线 `FactorPipeline`，可以自动化处理从数据获取到因子生成的全过程。

### 4.1 数据准备

复现依赖于 `qlib` 数据源。确保已配置好 Qlib 数据（如 A 股日线数据）。代码通过 `QlibDataProvider` 自动提取日收益、日内收益和隔夜收益。

### 4.2 执行计算

可以通过 `loade_factor.py` 进行批量计算。该脚本会遍历不同的网络定义（如 `overnight_lead_daytime` 和 `daytime_lead_overnight`）以及相关性方法（Pearson 和 Spearman）。

`# 示例调用代码   from factor_pipeline import FactorPipeline      pipeline = FactorPipeline(       codes="ashares",       start_dt="2020-01-01",       end_dt="2025-10-27",       window=60,       network_type="overnight_lead_daytime", # 核心网络类型       correlation_method="spearman",         # 推荐使用Spearman处理非线性关系       n_iterations=20,                       # d-LE-SC迭代次数       lead_percentile=0.5   )      # 运行流水线，获取多空因子收益   factor_df = pipeline.run()   `

### 4.3 结果输出

程序将输出两个 Parquet 文件：

1.  `_long.parquet`：做多部分的因子值（持仓权重或收益）。
    
2.  `_short.parquet`：做空部分的因子值。
    

这些输出可以直接导入到回测引擎（如 Backtrader 或 Qlib 的回测模块）中进行绩效分析。

## 5\. 总结与展望

本文复现了基于 d-LE-SC 算法的隔夜-日间领先滞后网络策略。该模型在理论上突破了传统对称相关性网络的局限，通过引入复数域的 Hermitian 矩阵有效地捕捉了市场的方向性信息流。

在工程实现上，我们解决了以下关键问题：

1.  利用 **PyTorch GPU 加速** 解决了大规模矩阵特征分解的性能瓶颈。
    
2.  实现了 **d-LE-SC 算法的完整迭代逻辑**，包括  参数的动态更新。
    
3.  通过 **NumPy 步长技巧（Strides）** 优化了滚动窗口的内存占用。
    
4.  构建了稳健的**容错机制**，处理矩阵计算中的不收敛问题。
    

初步测试表明，该因子在捕捉短期市场情绪传递方面具有独特的效力，尤其是在隔夜信息对次日日内走势的预测上。未来的优化方向包括引入更复杂的去噪算法处理相关性矩阵，以及探索多层网络结构。

  

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/003.jpg)