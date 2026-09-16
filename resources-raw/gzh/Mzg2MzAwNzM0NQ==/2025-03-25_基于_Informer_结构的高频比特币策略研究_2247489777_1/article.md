# 基于 Informer 结构的高频比特币策略研究

QuantML QuantML 2025-03-25 22:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489777&idx=1&sn=fa21f1ac62aa7e2e2aefc89c4af56128&chksm=cf01ae1554e239e05dba7c5c170f6813dd93dd5d9e8f02f67de1097d97329a2b0031a1398e1e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489777&idx=1&sn=fa21f1ac62aa7e2e2aefc89c4af56128&chksm=cf01ae1554e239e05dba7c5c170f6813dd93dd5d9e8f02f67de1097d97329a2b0031a1398e1e#rd)

### 

本文深入探讨了如何利用 **Informer 架构** 构建自动化交易策略，以应对高频比特币（BTC）数据的挑战。

### 一、引言：自动化交易策略的机遇与挑战

近年来，随着计算机算力的提升和机器学习（ML）技术的飞速发展，**自动化交易算法**在金融市场中得到了广泛应用。据估计，目前市场上 70% 到 80% 的交易都是由自动化交易软件完成的，这一比例在未来几年有望继续上升。

然而，在高频交易（HFT）和先进计算能力的时代，仅处理日度市场数据已远远不够。这一现象在比特币等资产的交易中尤为明显：

-   **比特币**是一种去中心化的数字货币，通过使用区块链技术的比特币网络实现点对点交易。自 2009 年中本聪（Satoshi Nakamoto）发表匿名白皮书以来，比特币迅速普及，涌现出众多促进比特币买卖的加密货币交易所。
    

-   2017 年，比特币价格飙升近 20 倍，达到 19,497 美元，随后暴跌 84%。
    
-   2021 年，比特币创下 63,314 美元的历史新高，但随后价格又跌至 53,477 美元，跌幅接近 55%。
    

-   比特币以高波动性著称，例如：
    
-   尽管自比特币现货 ETF 获批以来，比特币价格走势趋于稳定，但与其他传统投资工具相比，其价格波动依然十分剧烈。
    

鉴于上述背景，本文旨在探索构建比特币自动化交易策略的可能性，并提出以下研究问题：

1.  **能否构建出比“买入并持有”（Buy&Hold）策略更有效的比特币算法交易策略？**
    

-   “买入并持有”策略是指在投资周期内持续持有资产，不进行任何买卖操作。该策略常被用作评估其他策略有效性的基准。
    

3.  **Informer 模型生成的信号能否构建出比基于技术指标的策略更有效的比特币交易策略？**
    

-   **移动平均收敛散度指标（MACD）**: 通过计算不同时间窗口的指数移动平均线（EMA）来识别趋势变化。
    
-   **相对强弱指数（RSI）**:  通过比较一定周期内上涨和下跌的幅度，来评估资产是否处于超买或超卖状态。
    

-   技术指标是指通过分析历史价格数据（如收盘价、成交量等）来预测未来价格走势的指标，例如：
    

6.  **机器学习模型损失函数的选择如何影响策略性能？**
    

-   损失函数是衡量模型预测值与真实值之间差异的函数，其选择对模型的训练方向和最终性能至关重要。
    

8.  **使用更高频率的数据能否构建出更有效的策略？**
    

-   本文研究了 5 分钟、15 分钟和 30 分钟三种不同时间间隔的数据，以评估数据频率对策略性能的影响。
    

为了回答上述问题，本文设计并实现了一种比较各种交易策略的方法，并将其与基准策略（买入并持有和两种基于技术指标的策略）进行比较。此外，本文还分析了不同时间间隔的数据，并进行了多时间段的测试。最后，本文进行了敏感性分析，以展示参数变化对测试策略性能的影响。

### 二、文献综述：金融预测与自动化交易策略的发展历程

#### 2.1 有效市场假说（EMH）

有效市场假说认为股票价格已经反映了所有可获得的信息，因此无法持续获得高于平均市场回报的收益。该假说存在三种形式：

-   **弱式**:  股票价格以随机方式波动，挑战了技术分析的基础。
    
-   **半强式**:  股票价格立即反映所有公开信息，质疑了基本面分析的有效性。
    
-   **强式**:  股票价格包含公共和私人信息。
    

尽管 EMH 在学术界引起了广泛讨论，但许多研究表明，市场并非完全有效。例如：

-   一些研究表明，日度回报之间存在统计上显著的正面相关性，表明可以利用这种模式开发盈利的交易策略。
    
-   行为经济学家记录了人类在面对不确定性时的各种行为偏差，例如过度自信、过度反应、损失厌恶、羊群效应和心理账户等，这些偏差是可预测的，并可用于开发超越被动基准的盈利交易策略。
    

#### 2.2 早期的统计方法

早期研究人员开发了多种统计系统和技巧来分析和预测资产价格，例如：

-   **自回归移动平均模型（ARMA）** 和 **自回归综合移动平均模型（ARIMA）**:  将自回归、差分和移动平均相结合来预测股票价格。
    
-   **指数平滑模型（ESM）**:  使用指数窗口函数对数据进行平滑，并估计指数平滑参数。
    

这些方法还经常与其他经典机器学习非线性模型相结合，例如：

-   研究人员将 ARIMA 模型与人工神经网络（ANN）相结合来预测货币对的价格。
    
-   一些研究比较了 ARIMA 模型和支持向量机（SVM）在不同股票价格预测中的表现。
    
-   一些研究开发了结合 ESM、ARIMA 和 ANN 的混合方法来预测道琼斯工业平均指数和深圳指数的日度价格。
    

#### 2.3 早期的机器学习系统

随着计算能力的提升，机器学习模型得到了更广泛的应用，并推动了更复杂的神经网络架构的发展，例如：

-   **卷积神经网络（CNN）** 和 **循环神经网络（RNN）** 及其变体 **长短期记忆网络（LSTM）** 和 **门控循环单元（GRU）**。
    

-   这些模型最初主要用于计算机视觉和自然语言处理领域，但很快被应用于金融预测并取得了成功。
    
-   例如，研究人员使用 LSTM 模型预测中国股市的日度回报，并证明其性能优于之前的经典统计方法。
    
-   一些研究比较了不同 RNN 架构在预测价格走势方面的表现，发现 LSTM 在处理长序列时表现优于其他架构。
    
-   一些研究将 CNN 与 LSTM 架构相结合来预测 S&P 500 指数的日度回报和分钟级别的 FOREX EUR/USD 回报，并报告称 CNN 在建模金融时间序列方面优于其他架构。
    

#### 2.4 现代机器学习系统

尽管 RNN 在处理序列数据方面得到了广泛应用，但该架构在处理更长的序列时遇到了梯度爆炸和梯度消失的问题。为了克服这些局限性，**注意力机制**应运而生。

-   虽然注意力机制最初是与 RNN 结合使用的，但 Vaswani 等人引入了仅基于注意力机制的神经网络架构，称为 **Transformer**。
    

-   该架构在性能上有了显著提升，并迅速在多个领域得到广泛应用。如今，它已成为最先进的大规模多模态模型（如 GPT-4 和 Gemini）的核心。
    

-   时间序列预测领域也采用了这种新架构。
    

-   例如，**Temporal Fusion Transformer (TFT)**  将 Transformer 架构与用于编码静态协变量的新组件、执行“变量选择”和跳过上下文不相关部分的门控组件相结合。
    
-   **MQTransformer**  采用 Transformer 架构，在编码器和解码器中分别使用注意力机制，并考虑从事件指示符中学习位置嵌入。
    
-   **Informer**  是一种计算效率高的 Transformer 架构，专门针对长预测范围的应用程序而设计。
    

一些研究探索了深度学习 Transformer 架构在高频比特币-USDT 对数回报预测中的应用，并将其与 LSTM 模型进行了比较，结果表明，基于 Transformer 的模型在回测期间使用多个信号进行交易时实现了更高的累计盈亏（PnL）。

### 三、数据：数据获取与预处理

#### 3.1 数据来源

本文使用的数据为 2019 年 8 月 21 日至 2024 年 7 月 24 日期间 BTC/USDT 加密货币对的数据。选择该数据的原因包括：

-   **数据质量高**:  许多加密货币交易所提供免费的历史数据访问权限，数据粒度可达到 1 秒级别。
    

-   与股票价格数据相比，加密货币数据更容易获取，即使对于小时级别的数据，访问通常也需要付费。
    
-   BTC/USDT 是最早在交易所上市的货币对之一，因此拥有最长的历史数据。
    

-   **交易连续性**:  加密货币交易所每周 7 天，每天 24 小时不间断运营，因此无需对节假日和股市收盘期间的隔夜价格波动进行特殊处理。
    

-   历史价格数据形成了一个具有等间隔的连续时间序列。
    

-   **市场流动性**:  比特币是最成熟的加密货币，BTC/USDT 货币对是交易量最大的货币对之一，这使得它比其他加密货币对更具流动性和稳定性。
    

数据通过币安（Binance）API 获取。币安是全球最大的加密货币交易所之一，提供交易、上市、融资以及加密货币的退市或撤回等综合服务。API 允许下载所谓的 K 线数据，即不同间隔的蜡烛图数据，包括开盘时间、收盘时间、开盘价、最高价、最低价、收盘价和成交量。本文研究使用 5 分钟、15 分钟和 30 分钟的 K 线间隔。

![](assets/001.png)

#### 3.2 数据处理

下载后的数据经过以下处理步骤：

1.  **缺失值处理**:  尽管交易所持续运营，但存在维护窗口，交易所偶尔也会宕机。共检测到 8 个数据缺口，总计缺失超过 101 小时（4.2 天）的数据，这占该时期所有数据点的 0.002，因此对实验影响不大。为了简化操作并保持时间序列的一致性，缺口处的价格和成交量值被替换为上一个可用数据点的值。
    
2.  **回报计算**:  每个间隔的回报
    
    回报收盘价开盘价开盘价
    

#### 3.3 数据特征分析

对 BTC/USDT 回报的描述性统计数据显示：

-   随着间隔长度的增加，回报的标准差也在增加，这符合预期。
    
-   每个间隔的最小值和最大值非常相似，表明重大价格波动是突然且迅速的。
    

-   有趣的是，最大回报出现在 15 分钟间隔，这表明价格必须先迅速上涨，然后下跌（在 30 分钟内）。
    

-   分布呈尖峰态，峰度远高于正态分布，并且随着间隔变小而增加。
    

-   在所有情况下，偏度在 -1 到 1 之间，表明分布相对对称。
    
-   Kolmogorov-Smirnov 正态性检验的检验统计量为 0.49，p 值为 0.0，因此拒绝数据呈正态分布的假设。
    

上述分析凸显了研究并创建在较短时间间隔内运行的交易系统的必要性。这是因为快速且突然的价格波动对于有效的交易策略至关重要，而基于较长间隔的算法将无法捕捉到这些波动。

![](assets/002.png)

![](assets/003.png)

### 四、方法论：策略构建与评估框架

本章详细介绍了本文采用的交易策略以及评估方法。

#### 4.1 评估框架

本文采用滚动窗口的方法对策略进行评估：

-   每个滚动窗口由 24 个月的样本内数据和 6 个月的样本外数据组成。
    

-   每个后续窗口向前移动样本外数据的长度。
    
-   最终，将每个子时期的测试结果结合起来，以提供整个测试期的测试结果。
    
-   这种方法可以更好地评估交易策略的稳健性，因为它可以在不同的市场条件下对它们进行独立评估。
    

对于每个时间步 t，策略可以采取以下三种可能的仓位：

-   **多头仓位**:  买入资产。如果资产价格上涨，组合价值增加。
    
-   **空头仓位**:  做空资产，并在平仓时需要买回。如果资产价格下跌，组合价值增加。
    
-   **无仓位**:  组合中没有资产。无论资产价格如何，组合价值都不会改变。
    

本文还做出了以下假设：

-   当策略仓位发生变化时，资产始终以之前间隔的收盘价买入/卖出。
    
-   每次仓位变化都会产生一定的交易费用。
    
-   可以交易资产的任何部分。
    
-   不分割投资组合配置，资产始终以全部组合价值买入/卖出。
    
-   在评估期结束时，所有仓位必须平仓。
    

#### 4.2 策略描述

本文评估和比较了五种策略：

1.  **买入并持有策略**:  该策略始终持有仓位，不进行任何买卖操作。
    
2.  **移动平均收敛散度策略（MACD）**:  该策略基于 MACD 技术指标，根据 MACD 线和信号线的交叉情况来做出买卖决策。
    
3.  **相对强弱指数策略（RSI）**:  该策略基于 RSI 技术指标，根据 RSI 值与设定的超买/超卖阈值的关系来做出买卖决策。
    
4.  **基于 RMSE 的 Informer 策略**:  该策略使用通过 RMSE 损失函数训练的 Informer 模型进行预测，并根据预测值与设定的阈值关系来做出买卖决策。
    
5.  **基于 Quantile 的 Informer 策略**:  该策略使用通过 Quantile 损失函数训练的 Informer 模型进行预测，并根据预测的特定分位数与设定的阈值关系来做出买卖决策。
    
6.  **基于 GMADL 的 Informer 策略**:  该策略使用通过 GMADL 损失函数训练的 Informer 模型进行预测，并根据预测值与设定的阈值关系来做出买卖决策。
    

### 五、实验结果与分析

本章详细介绍了策略训练、超参数选择以及评估结果。

#### 5.1 训练与超参数选择

每个策略都针对每个数据窗口独立实例化：

-   基于机器学习模型的策略使用数据窗口的训练部分进行训练，并使用验证部分选择超参数。
    
-   不需要训练的策略（即基于 MACD 和 RSI 的策略）仅使用数据集的验证部分选择超参数。
    

超参数选择过程如下：

-   对于 MACD 和 RSI 策略，所有可能的超参数组合都被搜索了一遍。
    

-   随机搜索仅在第一个数据窗口进行，选择的训练和模型超参数组合随后用于在给定时间间隔的其他数据窗口上训练模型。
    
-   选择了具有最低验证损失值的超参数组合。
    

-   窗口大小参数采用斐波那契数列的值，因为它们呈指数级增长，可以更有效地搜索可能的窗口空间。
    
-   对于 Informer 模型，超参数空间采用随机采样的方式进行搜索，因为可能的组合数量巨大，训练时间约为每个训练运行 1 小时。
    

#### 5.2 评估结果

评估结果显示：

-   **30 分钟数据**:  基于 RSI 指标的策略表现最佳，所有策略（基于 Quantile Informer 信号除外）都优于买入并持有策略。
    

-   RSI 策略在大多数情况下表现良好，但在第四和第六个窗口期间没有采取任何仓位，这表明这些时期的验证数据分布与测试数据不同，或者在这些时期存在高度不确定性。
    
-   基于 Informer 的策略（GMADL 和 RMSE）取得了非常相似的结果，其中 GMADL Informer 策略在比特币处于上升趋势时表现更好，而 RMSE Informer 策略在处于下降趋势时表现更好。
    
-   Quantile Informer 策略在第四和第六个窗口表现不佳，这极大地影响了整体性能。
    

-   **15 分钟数据**:  GMADL Informer 策略表现最佳，修改后的信息比率是评估的策略中最好的。
    

-   下一个最佳策略是 RMSE Informer，第三个最佳策略是买入并持有基准。
    
-   基于技术指标的策略以及 Quantile Informer 表现不佳，其结果比买入并持有策略更差。
    
-   Quantile Informer 策略的仓位仅占 40% 的时间，这表明所选超参数过于激进地限制了进入/关闭仓位的时机。
    
-   MACD 和 RSI 策略的仓位变化更多，这可能由于高额交易费用而对其性能产生了负面影响。
    

-   **5 分钟数据**:  GMADL Informer 策略显著优于其他策略。
    

-   在整个测试期间，其年化回报率达到 115%，同时将年化标准差保持在与买入并持有基准相似的水平。
    
-   该策略的最大回撤仅为 32.7%，远低于买入并持有的 77.3%。
    
-   该策略的多头和空头仓位保持时间大致相同。
    
-   下一个最佳策略是基于 RSI 的策略，但它在将近 40% 的时间内没有持有仓位。
    
-   这两种策略是唯一击败基准的策略。
    
-   值得注意的是，它们比其他表现较差的策略拥有更少的仓位变化，这表明它们在检测趋势变化和过滤掉不重要的信号方面做得更好。
    
    ![](assets/004.png)
    

### 六、敏感性分析

#### 6.1 验证部分大小

对 GMADL Informer 策略（5 分钟数据）进行评估的结果表明：

-   选择比 6 个月更短或更长的验证期会导致策略性能下降。
    

-   然而，无论验证部分的长度如何，该策略都优于基准，并且修改后的信息比率保持在相对较高的水平。
    
-   可以看出，当验证窗口延长时，交易次数单调减少。这表明，较长的验证期要求策略适应不断变化的市场条件，并更积极地减少改变仓位的信号。
    
-   表现最差的变体是验证窗口长度为三个月的情况。在这种情况下，该策略在测试期的最后两个窗口期间记录重大损失。
    

#### 6.2 数据窗口数量

对 GMADL Informer 策略（5 分钟数据）进行评估的结果表明：

-   当测试期被分割成不同数量的窗口时，策略性能会变差。
    

-   尽管修改后的信息比率仍然高于基准，但它明显低于六窗口评估中的信息比率。
    
-   这可能表明，GMADL Informer 策略的优异性能可能是由于选择了具体的评估窗口数量而导致的孤立事件。
    
-   然而，这一结论不应低估 GMADL Informer 策略在不同数量的窗口上进行评估时仍然取得了令人印象深刻的结果这一事实。
    

#### 6.3 排名前 n 位的策略

对排名前 10 位的超参数集进行评估的结果表明：

-   对于 GMADL 策略（5 分钟数据），总体上表现最好的策略确实是第一组超参数，而后续集逐渐降低了策略的结果。
    

-   然而，对于 15 分钟和 30 分钟数据，第二好的策略反而会更好。
    
-   类似的情况也发生在最佳 RSI 策略上，总体上最佳的 RSI 策略（30 分钟窗口）是验证中的第一个，但在 15 分钟数据的情况下，第二好的策略明显更好。
    
-   对于 RMSE Informer（30 分钟数据），前两组超参数似乎过度拟合，其性能在超过第二组后大幅增加。
    
-   对于总体上表现不佳的策略，选择排名前 n 位的超参数集不会产生重大影响。
    

### 七、结论

本文旨在探索创建自动化比特币投资策略的不同方法，并提出五种策略，其中两种使用技术指标信号，三种使用 Informer 机器学习模型的预测。

研究结果表明：

-   可以创建出比买入并持有策略更有效的算法策略。在测试期间，八种策略取得了比基准更好的结果。
    

-   这些策略在六个不同的测试窗口中进行了评估，整个测试期将近三年。
    

-   基于 Informer（使用 RMSE 和 GMADL 损失函数训练）的策略比基于 MACD 指标的策略更有效，但基于 RSI 指标的策略取得了可比较的结果。
    

-   此外，基于 RSI 指标的策略（30 分钟窗口）是总体上排名第二的最佳策略。
    
-   这表明，尽管技术指标由来已久，并且在文献中得到了很好的确立，但它们仍然为昂贵的、基于机器学习的方法提供了有效的替代方案。
    

-   不同损失函数训练的模型的行为有所不同，特别是当结合不同数据频率进行分析时。
    

-   使用 RMSE 损失函数训练的 Informer 的预测对于突然的、大的回报来说更差，这使得构建高频数据策略变得困难。
    
-   相比之下，使用 GMADL 损失函数训练的 Informer 从高频数据中受益。
    
-   采用 Quantile 损失函数的模型的方法相对于基准表现不佳，表明基于使用这种损失的模型预测构建策略存在困难。
    
-   在三种测试的损失函数中，GMADL 损失函数似乎最适合创建用于自动化交易策略的模型。
    
-   更重要的是，损失函数的选择似乎是训练生成算法交易系统信号的模型的决定性因素之一。
    

-   使用更高频率的数据可以创建更有效的策略。
    

-   当在 30 分钟数据上进行评估时，GMADL 和 RMSE 损失函数的策略取得了可比较的结果，但使用高频数据提高了 GMADL Informer 策略的性能，而降低了基于 RMSE 损失函数的 Informer 策略的性能。
    
-   基于技术指标的策略似乎并没有从更高频率中获益太多。
    

本文的主要贡献是分析了将新的损失函数（Quantile 和 GMADL 损失）应用于训练 Informer 模型以预测比特币回报，并将其与使用 RMSE 损失训练机器学习模型的更成熟的方法进行比较。所有三种模型类型的预测都被用来构建自动化交易策略，并与买入并持有基准以及基于 MACD 和 RSI 技术指标的两种基准策略进行比较。详尽的分析包括使用不同的测试期、不同的数据间隔和敏感性分析。研究表明，GMADL 损失函数允许有效地训练机器学习模型，该模型能够为交易策略提供有意义的信号。这种策略可以部署以提供比买入并持有方法更高的收益。

未来研究方向包括：

-   进行更广泛的敏感性分析，以更好地了解各种超参数对策略的影响，特别是对于基于 Informer 的策略和用于训练模型的损失函数。
    
-   测试更高频率的数据，并探索基于 GMADL 损失函数的 Informer 模型是否会进一步提高性能。
    
-   使用其他金融工具的数据，以确定相同的策略是否在其他数据上也能表现良好。
    

####   

  

  

  

  

  

代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/005.jpg)

  

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
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&scene=21#wechat_redirect)  
    
-   [Hummingbot：开源加密货币做市机器人框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489153&idx=1&sn=98198f6cca4aa5bc5646e926c358f01d&scene=21#wechat_redirect)  
    
-   [FinRLlama：基于强化学习和市场反馈的金融情感分析LLM优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489127&idx=1&sn=faad16c8ac3ca02dcb982837d03b21ab&scene=21#wechat_redirect)  
    
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
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)