# 因子挖掘机器学习篇（二）—— 神经网络挖掘集合竞价因子

蝴蝶量化 随率而动的因子工厂 2026-06-06 10:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484642&idx=1&sn=b73a651348f37eb6902038abeffb48da&chksm=c00c2dfa55abd34a0b397aa925b1dd26510b0d92c852d15f84a4a0b52535a1191366d7df9354#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484642&idx=1&sn=b73a651348f37eb6902038abeffb48da&chksm=c00c2dfa55abd34a0b397aa925b1dd26510b0d92c852d15f84a4a0b52535a1191366d7df9354#rd)

## 技术背景

古人云：“一天之计在于晨”。在交易似乎也存在这样的观点。很多集合竞价交易员认为，开盘的集合竞价反映了很多信息：隔夜新闻、公告、主力意图等等。这些信息在盘前的集合竞价阶段充分的博弈，从而产生开盘价。特别是目前这个阶段，很多开盘10分钟，充分反应了全市场投资者的隔夜情绪，能够在很大的程度上预测当天的走势。

特别是对于短线交易者，一般开盘集合竞价期间就能够决定当天的交易计划。

> **本期文章主要内容：从集合竞价的Level1的tick数据，通过因子工程，构建多因子策略。**

![](assets/001.jpg)

其实，整篇文件的技术上不难，但是获得集合竞价数据比较困难，很难找到tick级别的数据，如果你有wind那这些都不是问题，如果你没有万得，那么可以在掘金上获取历史数据。

**为什么要重视集合竞价？**

-   **1.隔夜信息的集中释放：** 每天收盘之后都有很多的新闻、公告数据，这些信息都会在第二天的集合竞价中，直接反映在价格上。
    
-   **2.情绪的集中释放：** 很多涨停、波动大的股票，在集合竞价阶段，买卖之间矛盾集中释放，充分反映了当天的情绪。
    
-   **3.反映主力意图（待考证）：** 也有人认为，集合竞价的强弱、涨停波动大小，直接反映了主力的真实意图。
    
-   **4.无连续成交干扰**：期间没有真实成交，所有订单在结束时统一撮合，数据更“纯净”。
    

很多人就想说，只用开盘那一瞬间的成交数据作为集合竞价因子可以吗？

**答案：** 不完美，简单使用**集合竞价最后一笔成交数据** 作为输入，神经网络预测未来5日收益率的RankIC仅为6.08%，远低于日频或分钟频因子。这说明：单靠最终成交结果信息量不足，必须深入挖掘整个竞价过程的动态变化。

## 因子构造(人工特征工程)

我们将结合竞价分为两个阶段：

-   阶段一：9:15-9:20， 投资者可以申报、测单。
    
-   阶段二：9:20-9:25，投资者只能申报不能撤单。
    
-   9:25 ；撮合成交。
    

### 1\. 因子构造

利用买一/卖一均价作为“拟成交价”，构造出13个特征：

特征类别

具体特征

含义

公式

价格类

振幅、一阶段振幅、二阶段振幅

反映竞价过程波动

(high-low)/low

收益类

隔夜收益率、一阶段涨跌幅、二阶段涨跌幅

衡量价格累积变动

(price - close\_pre)/close\_pre(左收、上一阶段价格)

行为类

上行比例、下行比例

价格上/下行快照占比

上、下行快照数量/总数量

流动性

快照数量、开盘成交量

活跃度与真实成交

快照总数、集合竞价总成交量

委托结构

买量委比、一阶段买量委比、二阶段委比变化

买卖力量对比

sum(买123)/sum（买123卖123）

### 2\. 单因子回测验证

先将每个特征的**过去20日均值**作为简单因子，回测其对未来5日收益率的预测能力。表现最好的三个因子，之前也说过rankIC绝对值大小说明好与差：

-   **快照数量**：RankIC = \*\*-6.59%\*\*（快照越多，未来收益越低，或反映高流动性溢价）
    
-   **二阶段振幅**：RankIC = **\-6.19%**
    
-   **二阶段涨跌幅**：RankIC = **+5.20%**
    

因子

RankIC

ICIR (未年化)

振幅

\-4.46%

\-26.04%

一阶段振幅

\-3.54%

\-23.12%

二阶段振幅

\-6.19%

\-33.92%

隔夜收益率

2.28%

21.94%

一阶段涨跌幅

\-1.76%

\-24.81%

二阶段涨跌幅

5.20%

45.20%

上行比例

1.70%

12.57%

下行比例

\-0.75%

\-4.87%

快照数量

\-6.59%

\-57.92%

开盘成交量

\-5.13%

\-43.01%

买量委比

0.18%

3.17%

一阶段买量委比

\-0.24%

\-4.78%

二阶段买量委比变化

0.41%

6.69%

且这些因子之间相关性较低，说明它们从不同维度捕捉信息。

### 3\. 神经网络建模

**具体算法：**将每只股票**过去30日的13个特征**组成矩阵 `(30,13)`，进行时序标准化和去极值后，输入 **TCN（时序卷积网络）**，预测未来5日收益率分位数。

**训练方式**：滚动训练

-   训练集：2010年至T-2年
    
-   验证集：T-1年
    
-   测试集：T年
    
-   样本外起始：2018年1月1日
    

**结果**：

-   样本外RankIC提升至 **8.37%**
    
-   分组超额收益在多空两端显著，但中间组单调性略差（第18组收益高于第19组）
    

## 时序神经网络（TCN）简介

TCN，即时间卷积网络，是一种专门为处理时间序列数据而设计的深度学习模型。它巧妙地将卷积神经网络（CNN）的优势迁移到时间维度，在很多任务上成为了循环神经网络（RNN）及其变体（如LSTM）的强大替代方案。

###  核心技术

TCN的强大源于其三大核心组件，它们共同解决了处理时间序列的关键挑战：

-   **因果卷积**：这是为了确保模型严格遵循时间顺序，只使用当前及过去的信息进行预测，彻底杜绝了“窥探未来”的可能。为了保持输入输出序列长度一致，TCN会使用零填充（zero-padding）。
    
-   **膨胀卷积**：如果说因果卷积是TCN的“规则”，那么膨胀卷积就是它的“魔法”。通过在卷积核元素之间插入“空洞”来间隔采样，它能以很少的层数，指数级地扩大网络的“视野”（感受野），高效捕捉长时间跨度的依赖关系，而不是像普通卷积那样只能线性地扩大视野。例如，一个包含3层、膨胀因子分别为`[1, 2, 4]`的TCN网络，其感受野可以覆盖7个时间步长。
    
-   **残差连接**：为了构建足够深的网络以获得更大视野，TCN引入了残差连接。残差块通常包含两层膨胀因果卷积，并辅以权重归一化和正则化（如Dropout）来稳定训练过程，有效缓解了深层网络中常见的梯度消失问题。
    
-   **一维卷积网络**：与处理图像的二维卷积不同，TCN使用一维卷积核（kernel）在时间轴上滑动，通过点积运算提取局部特征模式。隐藏层通过零填充确保输出长度与输入相同，并利用全卷积结构使每层保持相同的序列长度。
    

### 主要应用场景

凭借其出色的序列建模能力，TCN被广泛应用于众多领域：

-   **时间序列预测**：在金融量化投资中，用于股价、波动率预测；在电力系统中，用于电量消耗预测；在物联网中，用于设备传感器数据的分析和异常检测。
    
-   **音频处理**：如语音识别、音乐生成和音频事件检测。
    
-   **自然语言处理**：可用于机器翻译、文本情感分类等任务，帮助模型理解句子中的上下文依赖。
    
-   **视频分析与动作识别**：能分析视频帧序列，有效识别和理解人体动作或事件。
    
-   **科学工程领域**：在弹道中段目标识别、极化码译码等方面也有应用。
    

## 算法改进

具体方法采用：当日集合竞价构造时序 + 双TCN

### 1\. 当日高频数据识别短线机会

之前的方法使用的是过去30天的日度特征，考虑到开盘集合竞价原始数据本身蕴含的信息对于未来的预测是相对短期的，因此我 们将预测目标缩短至未来 1 日，只用当天开盘集合竞价 Level1 的数据预测当天收盘至第二天收盘股票的涨跌幅。输入端我们考虑将当天开盘集合可能丢失当日竞价的**精细过程**。因此，我们又设计了一个纯当日模型，重新做了特征工程：

-   **数据**：当天9:15–9:25的所有Level1快照
    
-   **重采样**：固定为**10秒一行**，形成60个时间步（若快照不足5个则剔除样本）
    
-   **特征**：6个价格特征（买一/二/三、卖一/二/三）除以开盘成交价；6个委托量特征除以当天最大委托量
    
-   **输入维度**：`(60, 12)`
    

### 2\. 双TCN结构

考虑到价格和委托量分布差异，构建了两个独立的TCN子模型：

-   **子模型A**：学习6个价格特征的变化模式
    
-   **子模型B**：学习6个委托量特征的变化模式
    

最后将两个子模型的隐藏层拼接，通过一层全连接输出预测值。

### 3\. 预测目标与特点

预测目标：**未来1日收益率**（次日收盘涨跌幅）。

结果：

-   预测值与未来1日收益率的RankIC为 **6.68%**
    
-   有趣的是，它与未来5日收益率的RankIC更高（8.37%），说明该因子捕获的效应能持续几天。
    

两个特殊现象：

1.  **超额收益衰减快**：多头组合在首日超额达0.18%（高于日频因子的0.10%），但第3天后斜率明显下降，到第6日被反超。因此该因子更适合**高频调仓**（如2-3天换仓）。
    
2.  **IC > RankIC**：皮尔逊IC（线性相关）高于秩相关，暗示因子值与真实收益的分布更接近，可能含有更多线性信息。
    

## 因子合成

### 1\. 开盘因子合成

将“特征工程+TCN因子”与“重采样+双TCN因子”等权合成，得到最终**开盘集合竞价神经网络因子**。

### 2\. 与其他频率因子合成

-   日频量价因子（TCN）
    
-   1分钟频量价因子（TCN）
    
-   周频量价因子（类似方法） 这三个因子的计算方法，也回在之后的文章中介绍。
    

将这四个因子（周、日、分钟、开盘）等权合成。

**结果**：

-   5日RankIC从基准的11.74%提升至 **12.00%**
    
-   每年RankIC均高于基准，说明开盘因子带来了**稳定的增量信息**
    
-   分组20组中，\*\*Top组年化超额收益高达38.20%\*\*（基准为34.35%）
    

## python代码

**同样，本文的代码大部分由claude code编写，笔者调试测试。**

### 1\. 数据需求

-   **Level1集合竞价快照数据**：9:15–9:25，每几秒一条，包含买/卖三档价量及最终成交价量。
    
-   其实本文最困难的点在这里，这个数据目前看来，wind的质量比较高，但是收费比较贵。
    

### 2\. 特征构造代码示意

![](assets/002.png)

### 3\. TCN实现

```
"""TCN (Temporal Convolutional Network) 基础模块用途：因果膨胀卷积 + 残差连接，阶段一~三复用修改日期：2026-06-04参考：Bai et al. "An Empirical Evaluation of Generic Convolutional      and Recurrent Networks for Sequence Modeling" (2018)"""import torchimport torch.nn as nnfrom typing import Listclass CausalConv1d(nn.Module):    """    因果卷积：padding 只在左侧，确保 t 时刻看不到 t+1 的信息    用于时间序列建模，避免未来信息泄露    """    def __init__(self, in_channels: int, out_channels: int, kernel_size: int, dilation: int):        super().__init__()        self.padding = (kernel_size - 1) * dilation  # 左侧 padding        self.conv = nn.Conv1d(            in_channels, out_channels, kernel_size,            dilation=dilation, padding=self.padding,        )    def forward(self, x: torch.Tensor) -> torch.Tensor:        """        Args:            x: (batch, channels, seq_len)        Returns:            (batch, channels, seq_len) — 时间维度不变        """        out = self.conv(x)        if self.padding > 0:            out = out[:, :, :-self.padding]  # 去掉右侧多余的 padding        return outclass TCNBlock(nn.Module):    """TCN 残差块：两层膨胀因果卷积 + 残差连接 + BatchNorm + Dropout"""    def __init__(        self, in_channels: int, out_channels: int,        kernel_size: int, dilation: int, dropout: float = 0.2    ):        super().__init__()        self.conv1 = CausalConv1d(in_channels, out_channels, kernel_size, dilation)        self.conv2 = CausalConv1d(out_channels, out_channels, kernel_size, dilation)        self.bn1 = nn.BatchNorm1d(out_channels)        self.bn2 = nn.BatchNorm1d(out_channels)        self.relu = nn.ReLU()        self.dropout = nn.Dropout(dropout)        # 残差连接：维度不匹配时用 1x1 卷积对齐        if in_channels != out_channels:            self.residual = nn.Conv1d(in_channels, out_channels, 1)        else:            self.residual = nn.Identity()        self.residual_bn = nn.BatchNorm1d(out_channels)    def forward(self, x: torch.Tensor) -> torch.Tensor:        # 残差路径：对齐维度 + BatchNorm        residual = self.residual(x)        if isinstance(self.residual, nn.Conv1d):            residual = residual[:, :, :x.shape[2]]  # 对齐时间维度        residual = self.residual_bn(residual)        # 主路径：Conv1 → BN → ReLU → Dropout → Conv2 → BN        out = self.conv1(x)        out = out[:, :, :x.shape[2]]        out = self.bn1(out)        out = self.relu(out)        out = self.dropout(out)        out = self.conv2(out)        out = out[:, :, :x.shape[2]]        out = self.bn2(out)        # 残差相加 + 激活        out = out + residual        out = self.relu(out)        out = self.dropout(out)        return outclass TCN(nn.Module):    """    TCN 网络：多层膨胀 TCNBlock 堆叠 + GlobalAvgPool + 预测头    三个阶段复用，只需调整 input_dim / channels 配置    膨胀率按层递增: 1, 2, 4, ... 保证感受野指数增长    """    def __init__(        self,        input_dim: int,        channels: List[int] = None,        kernel_size: int = 3,        dropout: float = 0.2,    ):        """        Args:            input_dim: 输入特征维度（阶段二=13, 阶段三=6）            channels: 各层输出通道数, 默认 [64, 64, 128]            kernel_size: 卷积核大小            dropout: Dropout 概率        """        super().__init__()        channels = channels or [64, 64, 128]        self.blocks = nn.ModuleList()        prev_ch = input_dim        for i, ch in enumerate(channels):            dilation = 2 ** i  # 膨胀率: 1, 2, 4, ...            self.blocks.append(TCNBlock(prev_ch, ch, kernel_size, dilation, dropout))            prev_ch = ch        self.hidden_dim = channels[-1]        self.fc = nn.Linear(channels[-1], 1)    def forward(self, x: torch.Tensor) -> torch.Tensor:        """        Args:            x: (batch, seq_len, features)        Returns:            (batch, 1) — 预测因子值        """        features = self.extract_features(x)  # (batch, hidden_dim)        return self.fc(features)    def extract_features(self, x: torch.Tensor) -> torch.Tensor:        """        提取 TCN 隐藏层特征（GlobalAvgPool 后、fc 前）        供 DualTCN 拼接两个通道的隐藏层使用        Args:            x: (batch, seq_len, features)        Returns:            (batch, hidden_dim)        """        # (batch, seq_len, features) → (batch, features, seq_len)        x = x.permute(0, 2, 1)        for block in self.blocks:            x = block(x)        # Global Average Pooling over time dimension        return x.mean(dim=2)  # (batch, channels[-1])
```

### 4\. 滚动训练

```
class RollingTrainer:    """    分年滚动训练器（单输入模型：阶段一 TCN / 阶段二 TCN）    每年滚动：      - Train: year <= T-2      - Val:   year == T-1      - Test:  year == T    """    def __init__(        self,        model_factory: Callable[[], nn.Module],        lr: float = LEARNING_RATE,        batch_size: int = BATCH_SIZE,        epochs: int = EPOCHS,        device: str = DEVICE,    ):        self.model_factory = model_factory        self.lr = lr        self.batch_size = batch_size        self.epochs = epochs        self.device = device    def train_one_epoch(        self, model: nn.Module, loader: DataLoader, optimizer, criterion    ) -> float:        """训练一个 epoch，返回平均 loss"""        model.train()        total_loss = 0        for batch_x, batch_y in loader:            batch_x, batch_y = batch_x.to(self.device), batch_y.to(self.device)            optimizer.zero_grad()            pred = model(batch_x)            loss = criterion(pred.squeeze(), batch_y)            loss.backward()            optimizer.step()            total_loss += loss.item()        return total_loss / len(loader)    def validate(self, model: nn.Module, loader: DataLoader, criterion) -> float:        """验证集评估，返回平均 loss"""        model.eval()        total_loss = 0        with torch.no_grad():            for batch_x, batch_y in loader:                batch_x, batch_y = batch_x.to(self.device), batch_y.to(self.device)                pred = model(batch_x)                loss = criterion(pred.squeeze(), batch_y)                total_loss += loss.item()        return total_loss / len(loader)    def _split_data(        self, X: np.ndarray, y: np.ndarray, dates: pd.DatetimeIndex, year: int    ) -> Tuple:        """按年份切分训练/验证/测试集的索引"""        train_mask = dates.year <= year - 2        val_mask = dates.year == year - 1        test_mask = dates.year == year        return train_mask, val_mask, test_mask    def _make_loader(self, X: np.ndarray, y: np.ndarray, mask: np.ndarray, shuffle: bool) -> DataLoader:        """创建单输入 DataLoader"""        ds = TensorDataset(torch.FloatTensor(X[mask]), torch.FloatTensor(y[mask]))        return DataLoader(ds, self.batch_size, shuffle=shuffle)    def train_year(        self, year: int, X: np.ndarray, y: np.ndarray, dates: pd.DatetimeIndex    ) -> Tuple[nn.Module, np.ndarray, np.ndarray]:        """        训练一个年份的模型，返回模型和测试集预测值        """        train_mask, val_mask, test_mask = self._split_data(X, y, dates, year)        train_loader = self._make_loader(X, y, train_mask, shuffle=True)        val_loader = self._make_loader(X, y, val_mask, shuffle=False)        test_loader = self._make_loader(X, y, test_mask, shuffle=False)        model = self.model_factory().to(self.device)        optimizer = torch.optim.Adam(model.parameters(), lr=self.lr, weight_decay=WEIGHT_DECAY)        criterion = nn.MSELoss()        best_val_loss = float("inf")        best_state = None        patience = 10        patience_counter = 0        for epoch in range(self.epochs):            train_loss = self.train_one_epoch(model, train_loader, optimizer, criterion)            val_loss = self.validate(model, val_loader, criterion)            if val_loss < best_val_loss:                best_val_loss = val_loss                best_state = {k: v.clone() for k, v in model.state_dict().items()}                patience_counter = 0            else:                patience_counter += 1            if (epoch + 1) % 10 == 0:                print(f"  Year {year} Epoch {epoch+1}/{self.epochs}: "                      f"train_loss={train_loss:.6f}, val_loss={val_loss:.6f}")            if patience_counter >= patience:                print(f"  Year {year}: 早停于 epoch {epoch+1}")                break        model.load_state_dict(best_state)        # 测试集预测        model.eval()        preds, actuals = [], []        with torch.no_grad():            for batch_x, batch_y in test_loader:                batch_x = batch_x.to(self.device)                pred = model(batch_x).squeeze().cpu().numpy()                preds.append(pred)                actuals.append(batch_y.numpy())        return model, np.concatenate(preds), np.concatenate(actuals)    def rolling_train(        self, X: np.ndarray, y: np.ndarray, dates: pd.DatetimeIndex    ) -> pd.DataFrame:        """        分年滚动训练，拼接所有测试集预测值        Args:            X: (N, seq_len, features)            y: (N,) 目标值（未来收益率或分位数）            dates: (N,) 每条样本对应的日期        Returns:            DataFrame columns=["prediction", "actual", "trade_date"]        """        years = sorted(set(dates.year))        if len(years) < 3:            raise ValueError(f"需要至少3年数据才能滚动训练，当前只有 {len(years)} 年")        test_years = years[2:]  # 前两年作为初始训练+验证        all_preds = []        for year in test_years:            print(f"\n===== 训练测试年份 {year} =====")            try:                model, preds, actuals = self.train_year(year, X, y, dates)                test_mask = dates.year == year                test_idx = np.where(test_mask)[0]                year_result = pd.DataFrame({                    "prediction": preds,                    "actual": actuals,                    "trade_date": dates[test_idx],                })                all_preds.append(year_result)            except Exception as e:                print(f"[WARN] 年份 {year} 训练失败: {e}")                continue        if not all_preds:            raise RuntimeError("没有任何年份训练成功")        return pd.concat(all_preds, ignore_index=True)
```

## 六、总结

本文从集合竞价的角度出发，给出了两种构造集合竞价因子的方法，一共产生了25个子因子。但是从绝对收益角度来看，整体策略并没有很大的提高，但是思路跟因子方面的构造方法、神经网络学习方法觉得值得学习。

**最近经常有人问我：你搞了半天的因子，年化20%有什么用？我一天就能转20%？**

我觉的是个很好的问题，大家有什么想法可以留言，后面我们也会出一篇相关的文章，专门讲这个问题。