# GNN算法在多因子策略中应用以及结合QIL库的实现步骤（一）—— 原理与算法结构

蝴蝶量化 随率而动的因子工厂 2025-11-09 13:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484281&idx=1&sn=58d270b62099fab73ccc90d410c0975c&chksm=c0634ac960ebf2871ad2f800bb7482e1e5cc148192ec91d0981eeec99682fbfb6c82030d2323#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484281&idx=1&sn=58d270b62099fab73ccc90d410c0975c&chksm=c0634ac960ebf2871ad2f800bb7482e1e5cc148192ec91d0981eeec99682fbfb6c82030d2323#rd)

## 应用背景

之前的文章，我们介绍了很多从**因子->构造策略**的方法，比如：《[因子合成的另类算法](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484190&idx=1&sn=81d37b8d65ee9fd749ce4f059320132e&scene=21#wechat_redirect)》、《[因子合成系列：最优ICIR方法](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484135&idx=1&sn=58b45f62b6fe4467f0feee4e380f2fb3&scene=21#wechat_redirect)》等等。这些方法的原理都是：对N个基础因子进行合成得到一个总因子，然后对总因子排序，从而得到最终的选股策略。

在《[如何做多因子合成？常见的7种方法](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484017&idx=1&sn=7090a205e3d26b81bfe9210f909449c9&scene=21#wechat_redirect)》、《[对比SVM、XGBoost、transframer在量价模型中的应用](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247483992&idx=1&sn=65b10763febf4e027c221c9131cc36cb&scene=21#wechat_redirect)》等文章中，我们都提到了**神经网络**算法，在这些算法中，并没有给出明确的最终合成因子，而是将未来收益作为直接的预测目标，从而形成完整的选股策略。

但是，传统多因子模型将每只股票视为一个独立的样本，模型学习从该股票的因子特征（X）到未来收益（y）的映射函数 `f(X) -> y`。这种方法忽略了金融市场的一个关键特性：**股票之间并非孤立，而是存在复杂、动态的关联网络**。特别是，在合成因子之前，我们都需要做行业中性化、市值中性化但是实际交易过程中，我们发现很多的策略收益很大程度源自于**风格因子**，由此诞生了：小市值策略、行业轮动、风格轮动策略等等。

**其中，这些关联包括：**

1.  行业/板块关联： 同一行业的股票受相同的宏观经济和产业政策影响。
    
2.  产业链关联： 上下游企业（如锂电池与锂矿、整车厂与零部件）的景气度会传导。
    
3.  主题概念关联： 属于同一概念的股票会形成联动。
    
4.  **动量/波动率溢出：** 一只股票的剧烈波动可能会影响相关股票的波动性。
    

**GNN的应用价值就在于能够显式地建模并利用这些股票间的复杂关系，将其作为增量信息（Alpha）注入预测模型，从而超越传统模型的性能天花板。**

在Qlib的框架下，GNN（如GATs\_ts模型）的作用可以理解为一种**高级的因子合成器**或**特征增强器**。它接收传统的量价/基本面因子，并通过聚合邻居股票的因子信息，输出一个蕴含了关系信息的、更强大的“图嵌入”因子。

* * *

## GNN的核心原理（以GAT为例）

GNN的种类很多，但在量化领域，**图注意力网络（GAT）** 因其灵活性和强大的表现力成为主流选择。其核心思想是：不同邻居对中心节点的影响程度是不同的，模型应能自适应地学习这些权重。

### 1\. 输入与定义

-   **图结构：**`G = (V, E)`，其中节点集合 `V` 表示股票，边集合 `E` 表示股票间的关系。在Qlib的GATs\_ts中，图是**全连接**的，让模型自己学习权重，避免了手动定义关系的麻烦。
    
-   **节点特征：** 每个节点（股票）`i` 在时间 `t` 都有一个特征向量 `h_i^t`，这就是该股票的多因子值（例如来自Alpha158的158个因子）。
    

### 2\. GAT层的计算步骤（核心）

**第一步：线性变换**对每个节点的特征应用一个共享的权重矩阵 ，将特征映射到更高维的空间，为后续计算做准备。

**第二步：计算注意力系数（Attention Coefficients）**使用一个共享的注意力机制 （通常是一个单层前馈神经网络）来计算节点  和其邻居  之间的未标准化注意力系数 。这衡量了邻居 对中心节点  的重要性。其中  表示拼接操作， 是可学习参数。

**第三步：标准化注意力权重**使用 softmax 函数对所有邻居 `j` 的注意力系数进行标准化，得到最终的、可解释的注意力权重 `α_ij`。所有权重之和为1。α

**第四步：加权聚合（消息传递）**将邻居节点的变换后的特征  用注意力权重 α 进行加权求和，得到聚合后的邻居信息。通常会与中心节点自身的特征进行组合（例如相加或拼接），再通过一个非线性激活函数（如ELU），最终得到节点  更新后的特征表示 。σα

**多头注意力（Multi-head Attention）**为了稳定学习过程并增强模型表达能力，通常会并行运行多个独立的GAT层（头），然后将它们的输出特征拼接起来或取平均。σα（拼接）

σα （平均）

**整个过程可以通过以下流程图来直观理解：**

`flowchart TD   A[输入: 所有节点特征 h_i]   A --> B[对每个节点进行<br>线性变换 z_i = W * h_i]   B --> C[计算节点i与邻居j的<br>注意力系数 e_ij]   C --> D[使用Softmax标准化<br>得到注意力权重 α_ij]   D --> E[加权聚合邻居信息<br>h_i' = σ Σ α_ij * z_j]   E --> F[输出: 更新后的节点特征 h_i’]   `

* * *

## 代码实现详解（PyTorch）

以下是一个简化版的GAT层实现，用于阐明其核心代码逻辑。

`import torch   import torch.nn as nn   import torch.nn.functional as F      class GATLayer(nn.Module):       def __init__(self, in_features, out_features, n_heads=1, concat=True, dropout=0.6):           super(GATLayer, self).__init__()           self.n_heads = n_heads           self.concat = concat           self.out_features = out_features              # 线性变换矩阵 W           self.W = nn.Linear(in_features, out_features * n_heads, bias=False)           # 注意力机制参数向量 a           self.a = nn.Linear(2 * out_features, 1, bias=False) # 计算e_ij的MLP           self.dropout = nn.Dropout(dropout)              self.leakyrelu = nn.LeakyReLU(0.2)          def forward(self, h):           # h 输入: [n_nodes, in_features]           n_nodes = h.size(0)                      # 1. 线性变换: z_i = W * h_i           Wh = self.W(h) # -> [n_nodes, out_features * n_heads]           Wh = Wh.view(n_nodes, self.n_heads, self.out_features) # -> [n_nodes, n_heads, out_features]              # 2. 计算注意力系数 e_ij           # 生成所有节点对 (i, j)           Wh_repeated = Wh.repeat(n_nodes, 1, 1, 1) # 产生所有可能的(i,j)对           # 计算e_ij = a([Wh_i || Wh_j])           Wh_repeated_ij = Wh_repeated.permute(1, 0, 2, 3) # 调整维度           concat_feat = torch.cat([Wh_repeated, Wh_repeated_ij], dim=-1) # 拼接                      # 通过MLP计算e_ij           e = self.a(concat_feat).squeeze(-1) # -> [n_nodes, n_nodes, n_heads]           e = self.leakyrelu(e)              # 3. 构建掩码和标准化（使用softmax）           # 创建注意力掩码（这里假设是完全图，没有掩码。也可以加入先验知识，如只计算行业内的注意力）           attention_mask = torch.ones(n_nodes, n_nodes) # 全1矩阵           negative_inf = -1e9           e = e.masked_fill(attention_mask == 0, negative_inf) # 将不需要的边置为负无穷              # 沿列方向（邻居j维度）计算softmax           attention = F.softmax(e, dim=1) # -> [n_nodes, n_nodes, n_heads]           attention = self.dropout(attention)              # 4. 加权聚合           h_prime = torch.einsum('ijh,jhf->ihf', attention, Wh) # 高效的多头矩阵运算              # 如果是单头或者选择用concat方式，直接返回           if self.concat:               h_prime = h_prime.view(n_nodes, self.n_heads * self.out_features)           else:               h_prime = h_prime.mean(dim=1) # 多头取平均              return h_prime      # 假设我们有300只股票，每只股票有158个因子   n_stocks = 300   d_feat = 158   x = torch.randn(n_stocks, d_feat) # 模拟因子数据      # 初始化一个单头GAT层，输出维度为64   gat_layer = GATLayer(in_features=d_feat, out_features=64, n_heads=1, concat=True)   output = gat_layer(x) # output shape: [300, 64]   print(f"输入形状: {x.shape}")   print(f"经过GAT层后的输出形状: {output.shape}")   `

**代码输出:**

`输入形状: torch.Size([300, 158])   经过GAT层后的输出形状: torch.Size([300, 64])   `

* * *

## 基于Qlib的完整实践步骤

以下是使用Qlib平台实现GNN（GATs\_ts）选股策略的完整流程。

### 步骤一：环境准备与数据部署

1.  **安装Qlib：**
    
    `pip install pyqlib   `
    
2.  **下载数据（A股示例）：**
    
    `# 下载并处理A股数据，创建回测数据集   qlib update --source_url <A股数据源URL> --target_dir ~/.qlib/qlib_data/cn_data --region cn   `
    
3.  **初始化Qlib：**
    
    `from qlib.contrib.ops import init_instance   init_instance(provider_uri='~/.qlib/qlib_data/cn_data')   `
    

### 步骤二：配置文件设置（YAML）

Qlib的运行由YAML配置文件驱动。这是最关键的一步。

**`gats_ts_config.yaml`:**

`# 数据配置   data_handler_config:       start_time: 2010-01-01       end_time: 2021-12-31       fit_start_time: 2010-01-01       fit_end_time: 2016-12-31       instruments: csi300 # 股票池：沪深300       feature_pool: Alpha158 # 因子库      # 模型配置   model:       class: GATs_ts       module_path: qlib.contrib.model.pytorch_gats_ts       kwargs:           d_feat: 158 # 输入因子维度           hidden_size: 64 # LSTM隐藏层大小           num_layers: 2 # LSTM层数           n_epochs: 200 # 训练轮数           lr: 0.0001 # 学习率           dropout: 0.7 # Dropout率           n_heads: 2 # GAT多头注意力数           base_model: LSTM # 基础时序模型      # 策略配置   task:       model: model       dataset:           class: DatasetH           module_path: qlib.data.dataset           kwargs:               handler:                   class: Alpha158                   module_path: qlib.contrib.data.handler                   kwargs: $data_handler_config               segments:                   train: [2010-01-01, 2016-12-31]                   valid: [2017-01-01, 2017-12-31]                   test: [2018-01-01, 2021-12-31]      # 回测配置   backtest:       start_time: 2018-01-01       end_time: 2021-12-31       account: 100000000 # 初始资金       benchmark: SH000300 # 基准指数（沪深300）       exchange_kwargs:           limit_threshold: 0.095           deal_price: close           open_cost: 0.0005           close_cost: 0.0015           min_cost: 5   `

### 步骤三：模型训练与预测

使用Qlib的命令行工具 `qrun` 一键完成训练、预测和回测。

`# 运行整个流程：数据->模型->预测->回测   qrun gats_ts_config.yaml      # 如果只想训练和预测，后续再回测   qrun gats_ts_config.yaml --task_mode train   qrun gats_ts_config.yaml --task_mode test   `

### 步骤四：结果分析

`qrun` 完成后，会生成预测结果和回测报告。

1.  **分析预测结果（IC、Rank IC）：**
    
    `from qlib.contrib.evaluate import risk_analysis   from qlib.data import D      # 加载预测结果   pred_df = D.features(D.instruments('csi300'), ['$pred'], start_time='2018-01-01', end_time=GNN算法在多因子策略中应用以及结合Qlib库的实现步骤（一）—— 原理与算法结构)   # 加载真实收益率   label_df = D.features(D.instruments('csi300'), ['$close/Ref($close, 1)-1'], ...)      # 计算IC序列   ic_df = risk_analysis.calc_ic(pred_df, label_df)   print(ic_df.mean())   `
    
2.  **分析回测绩效：**
    
    `from qlib.contrib.evaluate import backtest_analysis   # 读取回测结果   report_normal_df, positions = backtest_analysis.get_backtest_result('backtest')   # 打印绩效指标：年化收益、夏普比率、最大回撤、信息比率等   print(backtest_analysis.report_graph(report_normal_df))   `
    

### 步骤五：策略优化与迭代

-   **调整GNN结构：** 在配置文件中修改 `n_heads`, `hidden_size`, `num_layers_gat`（需修改源码支持多层）等超参数。
    
-   **尝试不同的因子库：** 将 `Alpha158` 替换为 `Alpha360` 或自定义因子。
    
-   **引入显式关系：** 修改GATs\_ts源码，将全连接图改为基于行业或概念的稀疏图，注入先验知识。
    
-   **集成学习：** 将GATs\_ts的预测结果与其他模型（如LightGBM）的结果进行融合。
    

* * *

## 总结

将GNN应用于多因子策略是一个强大但复杂的过程。其核心优势在于**关系建模**。Qlib平台极大地简化了数据处理、回测和比较的工程复杂度，让研究者能更专注于模型和思想的迭代。

**重要提示：**

-   GNN是强大的工具，但不是“圣杯”。它的表现依然严重依赖于底层因子质量和市场环境。持续进行因子挖掘和模型迭代同样重要。
    
-   本文的主要内容依然源自于券商研报，具体细节呈现借助了AI。
    
-   至于本地化实现文中的代码、算法效果展示我们将会在接下来的文章中，逐步呈现，并且给出其中的要点与需要规避的雷区。