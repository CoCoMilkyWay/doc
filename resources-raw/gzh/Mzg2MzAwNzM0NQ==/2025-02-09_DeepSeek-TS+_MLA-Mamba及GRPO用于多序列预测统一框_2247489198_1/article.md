# DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架

QuantML QuantML 2025-02-09 21:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&chksm=cf36b27ee3ca1a0c511f8b9ba0978071b9ed21a798ff17885decc9fbb0b385e9ad106f779612#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&chksm=cf36b27ee3ca1a0c511f8b9ba0978071b9ed21a798ff17885decc9fbb0b385e9ad106f779612#rd)

我们在之前的文章中介绍过如何使用DeepSeek的核心结构MoE以及MLA用于选股：

[QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现【附代码】](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&scene=21#wechat_redirect)  

[QuantML-Qlib重磅更新：DeepSeek核心模型结构用于选股](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489025&idx=1&sn=35941156783794d719e6ff891ce720c3&scene=21#wechat_redirect)  

除了这两个结构之外，DeepSeek还采用了GRPO的强化学习方法用于更新策略。

本文介绍利用状态空间增强的多头潜在注意力（MLA）和组相对策略优化（GRPO）进行自适应预测

## 引言

DeepSeek的技术给我留下了深刻的印象——其高效的多头潜在注意力（MLA）和组相对策略优化（GRPO）技术启发了我，将它们应用于多产品时间序列预测。在我们的方法中，我们将MLA扩展为MLA-Mamba，允许潜在特征通过具有非线性激活的状态空间模型随时间动态演变。这赋予了我们的模型一种自适应记忆能力，能够像销售团队在市场激增期间调整策略一样适应趋势。与此同时，GRPO引入了一种智能决策过程，通过将预测与基线进行比较，持续优化预测结果，类似于管理者实时调整预测。这种动态调整有助于我们的模型有效应对销售模式的突然变化。

我们将这种方法与经典的ARMA模型和标准的基于GRU的网络进行了比较。虽然ARMA能够处理线性趋势，GRU能够捕捉时间依赖性，但我们的DeepSeek-TS框架旨在建模复杂的产品间关系并适应非线性动态，从而实现更准确、更稳健的预测。

在接下来的部分中，我们将详细剖析扩展的MLA（MLA-Mamba）和GRPO框架的技术细节，并展示它们的协同作用如何增强多产品时间序列预测。

## 多头潜在注意力（MLA）

DeepSeek中MLA的核心思想是将键（Key）和值（Value）压缩到低维潜在空间。这使得模型在推理过程中能够存储更小的KV缓存。该过程可以分解为几个关键的数学步骤：

### 键和值的潜在压缩

考虑一个输入标记，用向量 表示，其维度为 。在标准的Transformer中，该向量通过学习矩阵被投影到查询（Query）、键（Key）和值（Value）空间。然而，在DeepSeek的MLA中，我们首先将 压缩为一个专门用于键和值的低维潜在向量。这一过程可以通过以下公式表示：

其中：

-   是压缩后的潜在向量；
    
-   是降维投影矩阵；
    
-   是压缩维度，且 。
    

这种低秩近似类似于推荐系统中使用的矩阵分解技术，其中大矩阵通过两个较小矩阵的乘积来近似，以捕捉最重要的特征。在我们的案例中， 学习捕捉 中对计算注意力至关重要的方面。

### 从潜在代码重构键和值

一旦我们得到了 ，就需要通过上投影来重构用于注意力机制的键和值向量。这一过程可以通过以下公式实现：

其中：

-   和 分别是重构后的键和值向量；
    
-   和 是上投影矩阵，其维度为 （其中 是每个头的维度， 是头的数量）。
    

关键在于，在推理过程中，我们无需为每个标记缓存完整的键和值向量（这将需要存储每个标记的 个元素），而只需缓存压缩后的潜在向量 ，其中每个标记仅包含 个元素。当 远小于 时，这种减少是显著的。

### 查询压缩（可选，用于提高训练效率）

除了键和值之外，DeepSeek还对查询进行了类似的低秩压缩，以减少训练过程中的激活内存。该过程与上述类似：

其中：

-   是压缩后的查询向量；
    
-   和 是查询的降维和上投影矩阵；
    
-   是查询压缩维度。
    

虽然压缩查询并不会减少KV缓存（因为查询是即时计算的），但它有助于在训练过程中减少整体激活内存。

### 效率提升：一个示例

假设你有一个Transformer层，其中每个标记的原始键值维度为1024（即 ）。使用MLA时，如果你选择压缩维度 ，那么每个标记缓存的数据量将从1024个元素减少到128个元素——减少了8倍。当处理长序列或大规模部署模型时，这一减少是显著的。

此外，在推理过程中，如果上投影矩阵 和 可以吸收进其他权重矩阵（例如 或 ），那么你可能根本无需显式计算或存储键和值。这将带来更大的效率提升。

## 组相对策略优化（GRPO）

虽然MLA专注于高效的注意力机制，但DeepSeek还引入了一种新颖的优化方法，即组相对策略优化（GRPO），用于更新模型的决策策略。这种方法基于强化学习原理，旨在平衡探索与利用，同时确保策略更新的稳定性。

### 策略优化基础

在强化学习中，策略 定义了在状态 下采取行动 的概率，参数为 。目标是最大化预期累积奖励：

其中：

-   是时间 的奖励；
    
-   是折扣因子，用于确定未来奖励的重要性。
    

### 使用组进行相对策略优化

GRPO引入了一种新思想，即通过将新策略的输出与旧策略（固定版本）的输出组进行比较来评估新策略。关键在于，通过将新策略的输出与旧策略的输出进行比较，可以更稳健地衡量某些行动的优势。

设：

-   是用于生成相同查询 的输出组的旧策略；
    
-   是当前可更新的策略。
    

比率：

衡量了新策略相对于旧策略的偏离程度。为了稳定训练，通常会将该比率限制在 和 之间，其中 是一个小的超参数。这种限制确保策略在单次更新中不会发生过大的变化。

### 优势估计

优势函数 衡量了行动 相对于平均表现的好坏程度：

其中 是一个基线价值函数，表示从状态 开始的预期奖励。在GRPO中，优势用于加权更新，确保那些导致高于平均水平奖励的行动得到强化。

策略梯度更新公式为：

该更新规则表明，我们应该调整 的方向，以增加具有正优势的行动的概率，同时减少具有负优势的行动的概率。

### GRPO的新颖贡献

GRPO在先前的方法（如近端策略优化（PPO）和直接策略优化（DPO））的基础上进行了扩展，但引入了一种新机制，通过比较旧策略的输出组与新策略的输出来进行更新。这种“组相对”比较允许更稳定和可靠的更新。策略更新不仅考虑了新策略的输出，还考虑了它们相对于旧策略提供的稳定基线的表现。

关键公式（概念性）：

其中：

clip函数限制了比率 ，目标是最大化 。该公式确保，如果新策略的偏离过大，更新将受到限制，从而防止可能导致训练不稳定的过度变化。

### GRPO的实际应用示例

以我论文中的一个例子为例。假设我们的强化学习代理的任务是从给定的查询中选择最佳模型或模型组合。该查询来自我们的MLA过程生成的潜在表示 。假设旧策略 为某个特定查询分配了一个行动概率分布（例如选择XGBoost、LightGBM、DNN或混合模型），并为“选择DNN”这一行动赋予了0.25的概率。与此同时，新策略 可能为“选择DNN”这一行动赋予了0.35的概率。我们随后计算这些概率的比率。如果 设为0.2，我们将比率 限制在区间 \[0.8, 1.2\] 内，以确保学习过程中的稳定性。

如果 设为0.2，那么我们将 限制在区间 \[0.8, 1.2\] 内。假设计算出的“选择DNN”这一行动的优势 为 +0.5（表明在这种情况下选择DNN是有益的）。

策略梯度更新将使用限制后的比率：

这种受控的更新有助于确保策略仅逐渐向新的行动概率倾斜，基于该行动相对于组的表现有多好。

## 将MLA和GRPO整合到统一框架中

让我们总结一下DeepSeek的突破性成果——MLA和GRPO——并将它们整合到一个自适应模型中。目标是构建一个系统，该系统不仅使用高效的低秩注意力来处理长序列，还利用强化学习智能地选择或混合模型。

1.  **输入编码和潜在压缩**：每个输入标记 首先由编码器处理。编码器使用以下公式将 压缩为潜在表示：
    

将原始维度 降低到较小的潜在空间维度 。

2.  **键和值的重构**：通过以下公式重构用于注意力的键和值：
    

这种重构确保在保持KV缓存较小的同时保留了必要的上下文信息。

3.  **查询压缩（可选）**：
    

4.  **注意力计算**：使用压缩后的查询、键和值计算多头注意力。每个头应用通常的注意力公式，但降低的维度使得该过程更加高效。
    
5.  **通过GRPO进行策略决策**：模型随后使用强化学习模块来选择最佳行动——无论是选择一个模型还是混合多个模型。强化学习策略 接收状态（包括来自MLA模块的潜在特征和额外的统计摘要），并输出一个行动。GRPO通过比较新策略的输出与早期固定策略的输出组来更新策略。计算优势，并对更新进行限制以确保稳定性。
    

其中：

目标是最大化 。该公式确保，如果新策略的偏离过大，更新将受到限制，从而防止可能导致训练不稳定的过度变化。

## 将MLA和GRPO应用于多产品时间序列预测

在前一节中，我们讨论了MLA和GRPO在DeepSeek中的有效协同工作，它们构成了DeepSeek的核心技术。这促使我探索这些技术是否可以应用于LLM之外的其他机器学习领域。经过彻底的理论分析，我确认它们可以扩展到新的领域。因此，我提出了一个统一框架，将MLA和GRPO结合起来用于多产品时间序列预测。具体来说，使用一个包含“日期”、“产品1销售额”、“产品2销售额”……“产品5销售额”等列的DataFrame，我们的目标是预测每种产品在未来10天内的平均销售额。我们的方法将“Mamba风格”的状态空间建模与潜在注意力相结合，并利用基于强化学习的策略优化（GRPO）动态调整预测。

以下是数学基础、算法细节以及一个实际示例。

### 问题设置和数据描述

假设销售数据是一个多变量时间序列 ，其中每个 表示时间 时 种产品（此处 ）的销售额。目标是预测每种产品在未来10天内的平均销售额。挑战在于时间序列可能存在内部相关性和滞后效应。例如，产品1在第 天的销售额可能不仅取决于其自身的过去销售额，还可能受到产品2或产品3过去几天销售额的影响。

### 将MLA扩展到状态空间（Mamba）框架

为了捕捉时间序列预测中固有的时间动态，我建议将潜在压缩步骤与通过非线性激活增强的状态空间更新相结合。在这个框架中，我假设压缩后的潜在向量随时间演变如下：

其中：

-   是一个转移矩阵，用于建模潜在状态动态；
    
-   是一个函数，将当前输入 （例如时间 的销售数据）映射到潜在空间中的一个修正项；
    
-   整个更新应用了ReLU激活，引入非线性并确保更新后的潜在状态是非负的。
    

类似地，可以对查询压缩应用类似的更新：

其中 的定义类似。

解释：这种状态空间更新“记住”了过去的潜在状态 ，并使用新信息 进行调整。通过对整个和 应用ReLU激活，模型捕捉了历史状态和新输入之间复杂的非线性相互作用。非线性有助于建模复杂的时序模式，同时确保潜在表示保持非负。这种方法类似于RNN或LSTM更新其隐藏状态的方式。

### 引入多头注意力

在获得动态潜在状态 和 后，我将它们投影到多头注意力的键、值和查询中。假设将潜在空间划分为 个头。对于头 ：

其中 、、 是权重矩阵， 是每个头的维度。

每个头的注意力计算如下：

所有头的输出随后被拼接并使用输出矩阵 进行投影：

这种多头机制允许模型捕捉销售数据中不同方面的时序关系。例如，一个头可能学习趋势成分，另一个头可能专注于季节性等。

### 扩展GRPO以适应多时间序列预测

在这个框架中，我首先定义了一个给定输入窗口长度 和预测范围 天的预测问题。对于每个产品时间序列 ，目标 被计算为未来 天内原始销售额的平均值，即 。

其中 表示第 天的销售额。

GRPO模型使用两层GRU从归一化的输入序列 （其中 是产品数量）中提取时间特征。设最终时间步的隐藏状态为 。然后 通过两个独立的线性投影进行映射：

-   预测分支使用权重矩阵 计算预测值：
    

其中 是每个产品的预测平均销售额向量。

-   策略分支通过另一个线性映射 计算标量值 （策略值）：
    

其中 。

GRPO启发的损失的核心思想是根据一个“优势”信号调整预测，该信号衡量预测误差相对于一个常数基线 （此处选择 ）。

具体来说，优势定义为：

其中均值是在产品维度上取的。策略值与基线之间的比率 计算为：

为了确保训练过程中的稳定性并避免过大的策略更新，使用了裁剪机制。设：

其中 是一个小值（例如，0.1）。GRPO启发的策略损失随后被公式化为：

如果新策略（即预测）相对于基线没有足够改进，该损失将惩罚模型。总损失函数是预测损失和策略损失的组合：

其中：

是一个控制策略损失权重的超参数。

这种方法嵌入了一个时间外验证方案中：时间序列数据按时间顺序划分，确保仅使用过去的数据进行训练，未来数据用于验证——从而避免数据泄露。在验证过程中，归一化的预测 使用存储的均值和标准差还原回原始规模，并计算平均绝对百分比误差（MAPE）：

其中 是一个小常数，用于避免除以零。

在这里，GRPO方法用于多时间序列预测，使用GRU编码器提取时间依赖特征，并生成预测和策略值。预测使用组合的均方误差（MSE）/平均绝对误差（MAE）进行评估，而策略分支使用裁剪的优势机制提供额外的梯度信号，最终导致对预测范围内平均销售额的更稳健预测。

## 代码实验：结果概述

在这个实验中，我们的目标是预测每种产品在未来5天内的平均销售额。使用AR(1)过程结合产品特定的噪声和偏移生成合成销售数据，生成一个现实的600天数据集。目标被定义为预测范围内的平均销售额。

数据被归一化，然后按时间顺序划分（前80%用于训练，剩余20%用于验证），以确保时间外评估且没有任何泄露。

我比较了四种预测方法。首先，我使用了一个受GRPO启发的模型，该模型结合了扩展的MLA模块、GRU编码器和额外的策略分支。其次，我实现了一个受GRPO启发的预测模型，该模型采用了扩展的MLA（Mamba风格）机制，通过ReLU激活的非线性状态空间方法更新潜在状态。第三，应用了一个简单的基于GRU的预测模型（没有GRPO修改）。最后，使用ARIMA(1,0,1)模型以滚动预测的方式在原始数据上进行经典ARMA方法的预测。

这个代码实验为后续的性能评估奠定了基础，我们将比较这四种方法的平均绝对百分比误差（MAPE）。

代码如下：  

```
import numpy as np import pandas as pdimport torchimport torch.nn as nnimport torch.nn.functional as Ffrom torch.utils.data import Dataset, DataLoaderfrom datetime import datetime, timedeltaimport matplotlib.pyplot as pltfrom sklearn.preprocessing import StandardScalerfrom statsmodels.tsa.arima.model import ARIMA# Load datadf = pd.read_csv("sales_data.csv")# Optional: visualize the generated sales datadf.plot(x="date", y=["product1_sales", "product2_sales", "product3_sales", "product4_sales", "product5_sales"], figsize=(12, 6))plt.title("Simulated Sales Data for 5 Products")plt.show()# -------------------------------# Data Preparation for Time Series Forecasting with Normalization# -------------------------------class SalesDataset(Dataset):    def __init__(self, df, input_window=30, forecast_horizon=5):        """        df: DataFrame with columns: date, product1_sales, ..., product5_sales        input_window: number of days used as input        forecast_horizon: number of days to forecast; target = avg sales over these days per product        """        self.input_window = input_window        self.forecast_horizon = forecast_horizon        df['date'] = pd.to_datetime(df['date'])        df.sort_values('date', inplace=True)        self.df = df.reset_index(drop=True)        # Use only the sales columns (all except 'date')        data = df.drop(columns=['date']).values.astype(np.float32)                # Compute normalization parameters on the entire dataset        self.mean = data.mean(axis=0)        self.std = data.std(axis=0) + 1e-6  # avoid division by zero                # Normalize the data        self.data = (data - self.mean) / self.std        self.n_samples = len(self.data) - input_window - forecast_horizon + 1    def __len__(self):        return self.n_samples    def __getitem__(self, idx):        # Input: sales for input_window days (normalized)        x = self.data[idx: idx + self.input_window]        # Target: average sales over the next forecast_horizon days (normalized)        y = np.mean(self.data[idx + self.input_window: idx + self.input_window + self.forecast_horizon], axis=0)        return x, ydef prepare_dataloaders(df, input_window=30, forecast_horizon=5, batch_size=32, train_ratio=0.8):    dataset = SalesDataset(df, input_window, forecast_horizon)    n_total = len(dataset)    n_train = int(n_total * train_ratio)    # Chronological (out-of-time) split: first n_train samples for training, remaining for validation.    train_dataset = torch.utils.data.Subset(dataset, list(range(n_train)))    val_dataset = torch.utils.data.Subset(dataset, list(range(n_train, n_total)))    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=False)    val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False)    return train_loader, val_loadertrain_loader, val_loader = prepare_dataloaders(df, input_window=30, forecast_horizon=5, batch_size=32, train_ratio=0.8)# -------------------------------# Model Components: Simple GRU-based Forecasting Model with GRPO-inspired Framework# -------------------------------class ForecastingGRPOModel(nn.Module):    def __init__(self, input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.2, lambda_policy=0.1):        """        This model forecasts the average sales of the next 'forecast_horizon' days for each product        using a GRU encoder. It includes a policy branch to compute a GRPO-inspired loss.        """        super(ForecastingGRPOModel, self).__init__()        self.gru = nn.GRU(input_dim, hidden_dim, num_layers=2, batch_first=True, dropout=dropout)        self.fc_forecast = nn.Linear(hidden_dim, num_products)        self.policy_net = nn.Linear(hidden_dim, 1)        self.lambda_policy = lambda_policy    def forward(self, x):        # x: (batch, seq_len, input_dim)        gru_out, _ = self.gru(x)        last_hidden = gru_out[:, -1, :]  # (batch, hidden_dim)        forecast = self.fc_forecast(last_hidden)  # (batch, num_products)        policy_value = self.policy_net(last_hidden)  # (batch, 1)        return forecast, policy_value# -------------------------------# Training and Validation Functions (Using MAPE as Error Metric)# -------------------------------def train_model_full(model, dataloader, optimizer, device, grad_clip=1.0):    model.train()    total_loss = 0.0    for x, y in dataloader:        x = x.to(device)  # (batch, seq_len, input_dim)        y = y.to(device)  # (batch, num_products)        optimizer.zero_grad()        forecast, policy_value = model(x)        # Forecast loss: use a combination of MSE and MAE        loss_mse = F.mse_loss(forecast, y)        loss_mae = F.l1_loss(forecast, y)        loss_forecast = 0.5 * loss_mse + 0.5 * loss_mae                # GRPO-inspired policy loss:        # Compute advantage as the mean error over products for each sample.        advantage = (y - forecast).mean(dim=1, keepdim=True)        baseline = 0.5  # chosen constant baseline        r_t = policy_value / baseline        epsilon = 0.1        r_t_clipped = torch.clamp(r_t, 1 - epsilon, 1 + epsilon)        policy_loss = -torch.min(r_t * advantage, r_t_clipped * advantage).mean()                loss = loss_forecast + model.lambda_policy * policy_loss        loss.backward()        nn.utils.clip_grad_norm_(model.parameters(), grad_clip)        optimizer.step()        total_loss += loss.item() * x.size(0)    return total_loss / len(dataloader.dataset)def validate_model(model, dataloader, device, dataset_obj, debug=False):    model.eval()    all_preds = []    all_targets = []    with torch.no_grad():        for x, y in dataloader:            x = x.to(device)            y = y.to(device)            forecast, _ = model(x)            all_preds.append(forecast.cpu().numpy())            all_targets.append(y.cpu().numpy())    all_preds = np.concatenate(all_preds, axis=0)    all_targets = np.concatenate(all_targets, axis=0)    # Invert normalization: forecast_orig = forecast * std + mean    mean = dataset_obj.mean    std = dataset_obj.std    all_preds_orig = all_preds * std + mean    all_targets_orig = all_targets * std + mean    if debug:        print("Prediction range:", np.min(all_preds_orig), np.max(all_preds_orig))        print("Target range:", np.min(all_targets_orig), np.max(all_targets_orig))    mape = np.mean(np.abs((all_targets_orig - all_preds_orig) / (all_targets_orig + 1e-6))) * 100    return mape# -------------------------------# ARMA Forecasting for Comparison# -------------------------------def arma_forecast(series, forecast_horizon):    """    Fits an ARIMA(1,0,1) model on the provided series and forecasts forecast_horizon steps ahead.    Returns the average forecast.    """    try:        arma_model = ARIMA(series, order=(1, 0, 1))        arma_fit = arma_model.fit(disp=0)        forecast = arma_fit.forecast(steps=forecast_horizon)        return np.mean(forecast)    except Exception as e:        return series[-1]def evaluate_arma(df, input_window=30, forecast_horizon=5, train_ratio=0.8):    """    For each product (column), use a rolling ARMA forecast over the validation period on the raw data.    Returns a dictionary of MAPE values per product and the overall average MAPE.    """    n = len(df)    train_end = int(n * train_ratio)    products = [col for col in df.columns if col != "date"]    mape_dict = {}    all_mapes = []        # Rolling forecast: start from i = (train_end - input_window) to (n - input_window - forecast_horizon + 1)    for prod in products:        preds = []        actuals = []        for i in range(train_end - input_window, n - input_window - forecast_horizon + 1):            series = df[prod].values[:i + input_window]            pred = arma_forecast(series, forecast_horizon)            preds.append(pred)            actual = np.mean(df[prod].values[i + input_window: i + input_window + forecast_horizon])            actuals.append(actual)        preds = np.array(preds)        actuals = np.array(actuals)        prod_mape = np.mean(np.abs((actuals - preds) / (actuals + 1e-6))) * 100        mape_dict[prod] = prod_mape        all_mapes.append(prod_mape)    overall_mape = np.mean(all_mapes)    return mape_dict, overall_mape# -------------------------------# Main Training# -------------------------------def main():      df = pd.read_csv("sales_data.csv")        # Prepare out-of-time (chronological) dataloaders (first 80% for training, remaining for validation)    train_loader, val_loader = prepare_dataloaders(df, input_window=30, forecast_horizon=5, batch_size=32, train_ratio=0.8)        # For validation inversion, we need access to the dataset normalization parameters    dataset_obj = SalesDataset(df, input_window=30, forecast_horizon=5)        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")        # Define model parameters    input_dim = train_loader.dataset[0][0].shape[-1]  # e.g., 5 products    hidden_dim = 256      # Hidden dimension for GRU    num_products = input_dim  # Predict average sales for each product    forecast_horizon = 10  # Note: This parameter is used in the models, even though targets are for next 5 days    lambda_policy = 0.06   # Weight for GRPO-inspired policy loss        # -------------------------------    # GRPO-inspired Forecasting Model (Existing)    # -------------------------------    model = ForecastingGRPOModel(input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.2, lambda_policy=lambda_policy)    model.to(device)        optimizer = torch.optim.Adam(model.parameters(), lr=0.0003)    scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=10, gamma=0.9)    n_epochs = 22    print("Training GRPO-inspired Forecasting Model...")    for epoch in range(n_epochs):        train_loss = train_model_full(model, train_loader, optimizer, device, grad_clip=1.0)        mape = validate_model(model, val_loader, device, dataset_obj, debug=True)        scheduler.step()        print(f"Epoch {epoch+1}/{n_epochs} - GRPO Model Train Loss: {train_loss:.4f}, MAPE: {mape:.2f}%")        # -------------------------------    # ARMA Evaluation for Comparison    # -------------------------------    print("\nEvaluating ARMA Forecasting on raw data...")    arma_mapes, overall_arma_mape = evaluate_arma(df, input_window=30, forecast_horizon=5, train_ratio=0.8)    print("ARMA MAPE per product:", arma_mapes)    print("Overall ARMA MAPE:", overall_arma_mape, "%")        # -------------------------------    # Simple GRU Forecasting Model for Comparison    # -------------------------------    class SimpleGRUForecastingModel(nn.Module):        def __init__(self, input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.2):            super(SimpleGRUForecastingModel, self).__init__()            self.gru = nn.GRU(input_dim, hidden_dim, num_layers=2, batch_first=True, dropout=dropout)            self.fc_forecast = nn.Linear(hidden_dim, num_products)                def forward(self, x):            gru_out, _ = self.gru(x)            last_hidden = gru_out[:, -1, :]            forecast = self.fc_forecast(last_hidden)            return forecast    def train_simple_model(model, dataloader, optimizer, device, grad_clip=1.0):        model.train()        total_loss = 0.0        for x, y in dataloader:            x = x.to(device)            y = y.to(device)            optimizer.zero_grad()            forecast = model(x)            loss_mse = F.mse_loss(forecast, y)            loss_mae = F.l1_loss(forecast, y)            loss = 0.5 * loss_mse + 0.5 * loss_mae            loss.backward()            nn.utils.clip_grad_norm_(model.parameters(), grad_clip)            optimizer.step()            total_loss += loss.item() * x.size(0)        return total_loss / len(dataloader.dataset)    def validate_simple_model(model, dataloader, device, dataset_obj, debug=False):        model.eval()        all_preds = []        all_targets = []        with torch.no_grad():            for x, y in dataloader:                x = x.to(device)                y = y.to(device)                forecast = model(x)                all_preds.append(forecast.cpu().numpy())                all_targets.append(y.cpu().numpy())        all_preds = np.concatenate(all_preds, axis=0)        all_targets = np.concatenate(all_targets, axis=0)        mean = dataset_obj.mean        std = dataset_obj.std        all_preds_orig = all_preds * std + mean        all_targets_orig = all_targets * std + mean        if debug:            print("Simple GRU Prediction range:", np.min(all_preds_orig), np.max(all_preds_orig))            print("Simple GRU Target range:", np.min(all_targets_orig), np.max(all_targets_orig))        mape = np.mean(np.abs((all_targets_orig - all_preds_orig) / (all_targets_orig + 1e-6))) * 100        return mape    print("\nTraining Simple GRU Forecasting Model for Comparison...")    simple_model = SimpleGRUForecastingModel(input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.2)    simple_model.to(device)    optimizer_simple = torch.optim.Adam(simple_model.parameters(), lr=0.0003)    scheduler_simple = torch.optim.lr_scheduler.StepLR(optimizer_simple, step_size=10, gamma=0.9)    n_epochs_simple = 22    for epoch in range(n_epochs_simple):        train_loss_simple = train_simple_model(simple_model, train_loader, optimizer_simple, device, grad_clip=1.0)        simple_mape = validate_simple_model(simple_model, val_loader, device, dataset_obj, debug=True)        scheduler_simple.step()        print(f"Epoch {epoch+1}/{n_epochs_simple} - Simple GRU Train Loss: {train_loss_simple:.4f}, MAPE: {simple_mape:.2f}%")        # -------------------------------    # New Method: GRPO-inspired Forecasting with Extended MLA (Mamba-style) Mechanism    # -------------------------------    class ForecastingGRPOMLAModel(nn.Module):        def __init__(self, input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.3, lambda_policy=0.06):            """            This model extends the GRPO-inspired forecasting approach by incorporating an            extended MLA (Mamba-style) mechanism. The latent state is updated in a state-space            manner with a nonlinear activation applied to the entire update.            """            super(ForecastingGRPOMLAModel, self).__init__()            self.hidden_dim = hidden_dim            self.lambda_policy = lambda_policy            self.dropout = nn.Dropout(dropout)            # Map the input to the latent space.            self.input_transform = nn.Linear(input_dim, hidden_dim)            # State-space transition matrix (M)            self.M = nn.Linear(hidden_dim, hidden_dim, bias=False)            # Nonlinear activation function for the complete state update.            self.activation = nn.ReLU()            self.fc_forecast = nn.Linear(hidden_dim, num_products)            self.policy_net = nn.Linear(hidden_dim, 1)                    def forward(self, x):            # x: (batch, seq_len, input_dim)            batch_size, seq_len, _ = x.size()            # Initialize latent state as zeros.            h = torch.zeros(batch_size, self.hidden_dim, device=x.device)            # Iteratively update latent state with a state-space update.            for t in range(seq_len):                x_t = x[:, t, :]  # (batch, input_dim)                # Compute the correction without activation first.                correction = self.input_transform(x_t)                # Update latent state using the ReLU activation applied to the entire sum.                h = self.activation(self.M(h) + correction)                h = self.dropout(h)            forecast = self.fc_forecast(h)            policy_value = self.policy_net(h)            return forecast, policy_value    print("\nTraining GRPO-inspired Forecasting Model with Extended MLA (Mamba-style) Mechanism...")    model_extended = ForecastingGRPOMLAModel(input_dim, hidden_dim, num_products, forecast_horizon, dropout=0.2, lambda_policy=lambda_policy)    model_extended.to(device)    optimizer_extended = torch.optim.Adam(model_extended.parameters(), lr=0.0003)    scheduler_extended = torch.optim.lr_scheduler.StepLR(optimizer_extended, step_size=10, gamma=0.9)    n_epochs_extended = 22    for epoch in range(n_epochs_extended):        train_loss_extended = train_model_full(model_extended, train_loader, optimizer_extended, device, grad_clip=1.0)        mape_extended = validate_model(model_extended, val_loader, device, dataset_obj, debug=True)        scheduler_extended.step()        print(f"Epoch {epoch+1}/{n_epochs_extended} - Extended MLA Model Train Loss: {train_loss_extended:.4f}, MAPE: {mape_extended:.2f}%")    if __name__ == "__main__":    main()
```

## 评估GRPO启发的预测模型

GRPO启发的模型整合了扩展的MLA模块与GRU，并新增了一个策略分支，在经过22个训练周期后，其平均绝对百分比误差（MAPE）稳步下降并最终稳定在大约21.6%。该模型的预测范围始终与目标范围高度一致，这表明其自适应机制能够有效捕捉底层的销售模式。

### 与简单GRU模型的对比

相比之下，缺乏GRPO特定改进的简单GRU模型，其MAPE平均值略高，约为22.3%。尽管简单GRU的预测范围也与目标范围相似，但在GRPO模型中观察到的微小改进表明，额外的策略损失和扩展的潜在更新为降低预测误差做出了适度但有意义的贡献。

### 扩展的MLA（Mamba风格）模型的见解

进一步采用扩展的MLA（Mamba风格）机制的GRPO启发模型，通过在完整的状态更新中应用ReLU激活的非线性状态空间更新，实现了低至20.8%至21.3%的MAPE。这一改进凸显了利用更丰富的潜在表示来捕捉时间序列动态的优势。

### 经典ARMA方法

最后，ARMA方法显示出显著更高的误差。每个产品的MAPE大致在12.6%到43%之间，整体MAPE约为26.3%。与深度学习方法相比，ARMA在处理复杂的多维销售数据方面效果较差。

## 总结

在本研究中，我们探索了一种创新的多时间序列预测方法，通过结合GRPO和采用Mamba风格状态空间更新的扩展MLA模块来实现。实验结果表明，这种GRPO启发的模型能够实现比简单GRU模型和经典ARMA方法更低的MAPE。由策略分支和状态更新中的非线性激活驱动的增强潜在表示，似乎能够更有效地捕捉销售数据的复杂动态。

展望未来，将GRPO和扩展MLA框架应用于其他领域具有巨大的潜力。例如，这种方法可以适应于金融时间序列预测，其中捕捉市场趋势的微妙变化至关重要。它也可能有助于医疗保健诊断，通过从多个时间依赖信号预测患者结果，从而实现早期干预。

未来的研究可以专注于通过尝试不同的基线值或裁剪阈值来进一步完善GRPO机制，以及探索扩展的MLA模块如何与其他深度学习架构相结合。此外，引入元学习技术可能使模型能够更好地泛化到不同的领域。总体而言，本研究表明，将强化学习与先进的注意力机制相结合是构建更智能、更具适应性的预测系统的一个有希望的方向。

  

作者：Shenggang Li

  

完整代码及数据下载见星球，加入QuantML星球，与700+专业人士一起交流学习：

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