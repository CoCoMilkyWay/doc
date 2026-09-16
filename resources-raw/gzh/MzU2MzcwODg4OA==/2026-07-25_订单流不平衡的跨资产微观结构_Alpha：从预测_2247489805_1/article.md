# 订单流不平衡的跨资产微观结构 Alpha：从预测能力、市场状态到交易成本的完整拆解

Alpha搬运工 睿见Alpha 2026-07-25 00:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzU2MzcwODg4OA==&mid=2247489805&idx=1&sn=1ecdabc5ac24d3894ddf200ac8875613&chksm=fd97e7207381327a66360f38e5fd4c6ac5c7b02e3e1272263d696c3e4292d63b5e8f1c84206d#rd](https://mp.weixin.qq.com/s?__biz=MzU2MzcwODg4OA==&mid=2247489805&idx=1&sn=1ecdabc5ac24d3894ddf200ac8875613&chksm=fd97e7207381327a66360f38e5fd4c6ac5c7b02e3e1272263d696c3e4292d63b5e8f1c84206d#rd)

在高频和日内量化研究里，最容易被混淆的两个问题是：

1.  某个变量能不能解释价格已经发生的变化？
    
2.  在真实下单、成交和支付成本之后，这个变量能不能预测未来收益并留下利润？
    

订单流不平衡（Order Flow Imbalance，OFI）正好把这两个问题分开。它观察最优买卖价位上的排队量如何变化：买方队列增加、卖方队列减少，通常意味着短时间内的向上压力；反之则意味着向下压力。这个机制在微观结构上很自然，也能在数据里得到很强的同期相关性。但同期相关不等于可交易的 forward alpha：价格在盘口变化的同时可能已经完成调整，留给策略的未来收益只剩很薄的一层。

这项实证研究把 OFI 放进一个相对完整的量化研究框架：从 Level-1 NBBO 行情构造十秒级特征，在十二个美国股票、ETF 和股指期货上做走步（walk-forward）检验，加入两状态 Hidden Markov Model（HMM）识别市场状态，用 Ridge、Lasso 和 LightGBM 做模型比较，最后把 bid-ask spread、market impact 和 commission 都计入回测。

核心结论可以先用一句话概括：

> OFI 的短周期预测内容是真实的，但在十秒级执行频率下，跨 spread 的成本远远超过信号本身；只有把持有期拉长到约 30 分钟，或者显著提高被动成交比例，策略才可能接近经济可行。

下文不把“有显著的 IC”直接当成“有可实现的收益”，而是按研究员真正需要复核的顺序，拆解数据、特征、模型、检验、交易成本和局限。

* * *

## 一、研究背景：盘口压力如何进入价格

### 1\. 从信息交易到盘口事件

市场微观结构理论的出发点是：交易者拥有不同的信息，订单流并不是纯粹的随机噪声。Kyle 模型强调知情交易者会通过持续下单逐步揭示私人信息；Glosten–Milgrom 模型则说明做市商会用买卖方向和成交价格更新对真实价值的判断。无论采用哪种表述，订单流的方向性都可能带来价格的永久或半永久影响。

OFI 的重要性在于，它不只统计“买了多少、卖了多少”，还统计最佳报价队列的增减。一个买单主动成交会减少卖方队列；一个新的买方限价单会增加买方队列；买一价格上移则说明原有买方流动性被消耗或撤走。把这些事件放在一起，可以得到比单纯 trade imbalance 更接近盘口压力的变量。

### 2\. 同期价格影响与未来收益预测不是一回事

同期价格影响可以写成一个简单的回归直觉：

其中， 是当前价格变化， 是价格对订单流的敏感度。过去的研究在股票市场中发现，OFI 对同期价格变动的解释力很高。

但交易策略需要的是 forward return：

真正要检验的是：在只使用  时刻以前信息的前提下，当前 OFI 是否能预测 。如果价格冲击在十秒内已经被套利者吸收，那么同期  可以很高，未来 30 秒的  却可能只有几个千分点。

### 3\. 研究对象与样本

数据覆盖 2024 年 4 月 29 日至 2025 年 4 月 25 日，共 249 个交易日，统一聚合为十秒 bar。十二个品种分成五类：

-   宽基 ETF：SPY、QQQ、IWM；
    
-   行业 ETF：XLF、XLK、XLE、XLV；
    
-   大盘股：AAPL、JPM、NVDA；
    
-   固收 ETF：TLT；
    
-   股指期货连续合约：ES1!。
    

Level-1 数据保留每个十秒区间内的 best bid、best ask、bid size、ask size 和成交信息。全样本约 699 万个 bar，负 spread、重复时间戳和负成交量均为零，OFI 缺失比例约为 0.04%。

这组质量检查很关键：如果时间戳重复、spread 为负或报价跨越，OFI 的方向和大小都会被人为污染，后续的 IC、HMM 和回测都失去意义。

* * *

## 二、OFI 的构造：从最优报价队列到多周期特征

### 1\. 单个十秒 bar 的事件贡献

设 、 分别为 t 时刻买一和卖一价格，、 为对应队列数量。按照盘口事件的符号约定，买方和卖方的队列变化可以合并写成：

这里的  是示性函数，条件成立时取 1，否则取 0。这个写法把价格变化和数量变化同时编码进来，三个典型情形如下：

-   买一价格上升：原来的买方队列被消耗后，新的买一出现，通常记为正的买方压力；
    
-   买一价格不变： 直接体现买方队列增加或减少；
    
-   买一价格下降：买方流动性减少，贡献为负；卖一方向则用相反的经济含义计入。
    

如果把每个十秒 bar 内的事件贡献相加，得到基础 OFI：

其中  是第  个十秒时间桶内的 quote event 集合。正 OFI 表示买方队列相对更强，负 OFI 表示卖方队列相对更强。

### 2\. 多预测期限

研究同时构造 10 秒、30 秒、1 分钟、5 分钟和 10 分钟版本。用十秒 bar 表示，周期为  的累计特征可以写成：

多周期设计有两个作用。第一，它可以检验订单流压力的半衰期；第二，它能让 Ridge 同时比较“非常短的即时压力”和“已经累积的中短期压力”。实证结果显示，SPY 单品种的 30 秒预测最强，而跨资产池化之后 10 分钟的统计结果更稳定。

### 3\. 一组配套微观结构特征

OFI 并不是唯一输入。最终的 13 个特征包括：

-   `ofi_10s`、`ofi_30s`、`ofi_10m` 和尺度归一化的 `ofi_norm`；
    
-   queue imbalance：
    
-   基于 Lee–Ready 规则识别主动买卖方向后的 trade imbalance；
    
-   spread 与 spread change；
    
-   microprice return；
    
-   VWAP deviation；
    
-   realized volatility；
    
-   Kyle's lambda；
    
-   Amihud illiquidity ratio。
    

这些变量分别代表盘口队列、成交方向、报价宽度、短期价格位置、波动率和流动性。它们既能帮助模型区分“OFI 很大但市场很平静”和“OFI 很大且市场正在剧烈跳动”，也能让后续的 regime model 有可用的状态输入。

### 4\. 共线性与平稳性处理

不同周期的 OFI 天然高度相关。原始特征的 condition number 达到  到  量级，说明直接回归会非常不稳定。研究先用 Spearman 相关系数阈值 0.80 过滤掉 `ofi`、`ofi_1m` 和 `ofi_5m`，再用 VIF 检查剩余特征；最终 condition number 降至 4.67。

这里的逻辑不是“相关就不能用”，而是避免同一个订单流压力被多个近似变量重复计权。与此同时，13 个入选特征的 Augmented Dickey–Fuller 检验都在 1% 水平拒绝 unit root，至少说明它们在样本内没有表现为简单的随机趋势。

* * *

## 三、HMM：把“压力很大”放进市场状态里理解

### 1\. 为什么需要 regime detection

同样大小的 OFI，在不同市场环境下不一定产生相同的未来收益。平静市场里，买方队列的短暂增加可能很快被撤单；压力市场里，spread 变宽、波动率上升，订单流方向可能持续更久。为了区分这两种情况，研究使用两状态 Gaussian HMM：

其中状态 0 重新命名为 calm，状态 1 重新命名为 stressed。输入变量是 realized volatility、spread、queue imbalance、trade imbalance 和 。因为原始变量不服从正态分布（normality test 的 ），先做 rank transform，再拟合高斯发射分布。

### 2\. HMM 的概率结构

HMM 假设隐状态满足一阶 Markov 性质。转移矩阵为：

给定状态 ，观察向量  的发射概率为：

在实际推断中，前向概率递推为：

其中  是状态  的发射密度。模型每天重新估计，但只能使用预测日  之前的数据，并保留 60 个交易日的 burn-in。也就是说，在  时刻不会把  之后的 spread、波动率或 OFI 偷偷带进 HMM，这一点决定了状态过滤是否真的可交易。

### 3\. 状态特征与时间线

SPY 的 calm 状态约占 27.1% 的 bar，stressed 状态约占 72.9%。两状态的 realized volatility 均值分别为 0.069 和 0.147，spread 均值分别为 0.0145 美元和 0.0249 美元；stressed 状态的平均持续时间约 1.92 分钟，状态持续性为 91.4%。

![](assets/001.jpg)

_图：滚动 HMM 如何把十秒 bar 标为 calm 或 stressed，以及 stressed 状态下 bid-ask spread 的同步扩张。_

一个容易误读的点是：stressed 占比更高，并不代表“市场一直在极端波动”。状态标签是相对于样本内分布定义的，stressed 更准确的含义是“相对高波动、相对宽 spread、订单流更容易形成方向性”的状态。

* * *

## 四、从特征到 alpha：walk-forward、Ridge 与 IC

### 1\. 预测目标与信息边界

对每个 horizon ，预测目标是从当前 bar 到未来  的收益：

模型只能读到  时刻结束的信息，因此在模型输入端施加一次 `shift(1)`。这一步和把目标错位并不相同：目标仍然是未来收益，只有特征在训练和预测时向后挪一个 bar，避免使用当前 bar 尚未完全确定的报价。

### 2\. Walk-forward expanding window

SPY 研究被切成 10 个走步 test fold，跨资产研究则得到 12 个品种、84 个 ticker-month fold。每次训练窗口只向前扩展，不把未来 test fold 回填进模型。

五分钟收益存在严重的 target overlap。相邻两个十秒观察点的五分钟目标共享 29 个十秒 bar，lag-1 自相关达到 0.967。若仍把每个相邻 observation 当成独立样本，IC 的标准误会被显著低估。因此研究在 IC 汇总时只使用 non-overlapping windows，并在统计推断里使用 Newey–West 修正。

### 3\. Ridge 的目标函数与闭式解

Ridge 是主模型，因为 OFI 及其衍生变量通常是“许多特征各自贡献一点”，而不是少数变量独占解释力。标准化后的设计矩阵记为 ，目标向量记为 ，Ridge 的优化问题是：

其中  控制拟合误差与系数稳定性的权衡。预测值为：

Ridge 的  惩罚会把高度相关的 OFI 周期系数一起收缩，通常比无正则 OLS 更稳。Lasso 的惩罚是 ，更倾向于得到稀疏系数；LightGBM 则用树模型寻找非线性和交互。

### 4\. IC、ICIR 与 Newey–West

这里的 IC 用预测值与未来收益的 Spearman 相关系数：

ICIR 是 IC 均值除以 IC 的标准差：

由于时间序列有自相关，均值的 Newey–West 方差估计可写成：

其中  是每个 non-overlapping 窗口的 IC， 是 lag  的自协方差， 是截断滞后阶数。这个修正不会改变 IC 的点估计，却会把“看似有很多样本”还原成更接近有效样本量的统计证据。

### 5\. 单品种与跨资产结果

SPY 的 Ridge-Global 在 30 秒 horizon 上取得最清晰的结果：平均 IC 为 ，ICIR 为 0.418，Newey–West ，10 个 fold 中有 7 个为正。1 分钟 horizon 的平均 IC 为 ，。在 HMM 的 calm/all 条件模型中，5 分钟和 10 分钟的 IC 分别达到  和 ，但后者属于 regime-conditioned 的探索性结果，尚未通过 multiple-testing correction。

跨资产合并 12 个品种和 84 个 fold 后，平均 IC 为 ，pooled 、；样本外 IC 为 。但把依赖结构考虑进去后，结论需要收敛：按 ticker 聚合的检验仍显著（，，12 个品种中 10 个均值为正），按月份聚合的检验不再显著（，）。这说明跨资产方向较一致，但可用于跨时间推断的独立月份只有 7 个。

![](assets/002.jpg)

_图：同期 OFI 与未来收益的差异：同期 IC 约为 0.24，而 forward IC 很快衰减到几个千分点。_

### 6\. 为什么 Ridge 胜过 Lasso 和 LightGBM

Lasso 在各 horizon 上没有得到显著结果，LightGBM 的 IC 接近零，而 Ridge 在短周期上稳定为正。一个合理解释是：信号不是一个单点阈值或高度非线性的条件分支，而是订单流、微价格、波动率、spread 等变量的近似线性叠加。对研究员而言，这是一条重要经验：高频数据量很大，不代表一定要用深度学习；如果数据生成机制本身接近线性，正则化线性模型可能更稳、更容易做 lookahead 审计。

SHAP 排名也给出了特征层面的检查：`ofi_norm`、`ofi_30s` 和 `ofi_10s` 在 OFI 类变量中最重要；realized volatility 和 microprice return 的平均绝对 SHAP 值也很高，说明模型同时在利用“订单流方向”和“当前价格/波动环境”。

![](assets/003.jpg)

_图： 30 秒 Ridge 模型的特征重要性，OFI 衍生变量与 realized volatility、microprice return 共同构成主要解释来源。_

* * *

## 五、一个案例：为什么同一个 OFI 在不同资产上差异很大

### 1\. 看横截面而不是只看 SPY

把相同的信号和执行逻辑应用到不同资产后，横截面差异十分明显。研究的 gross Sharpe 为 0.981，net Sharpe 为 -1.726，成本拖累（cost drag）为 2.906，整体 fold survival rate 只有 35.7%。

跨资产 IC 热力图显示，10 个品种的平均 IC 为正，但不同月份、不同品种之间仍有明显色块切换。比如 NVDA、XLE 在部分月份有较强正 IC，也在其他月份出现负 IC；ES1! 的平均 IC略为负。这种结果更接近真实的 panel alpha：方向具有一定普遍性，但幅度、稳定性和成本承受力由每个品种的 spread、波动率和成交方式决定。

![](assets/004.jpg)

_图： 12 个品种在 7 个样本外月份的 IC 分布，绿色为正、红色为负，展示横截面共性与时间不稳定性。_

### 2\. 跨资产绩效表怎么读

![](assets/005.jpg)

_表：同一 OFI 预测器在不同品种上的平均 IC、gross/net Sharpe、成本拖累和 fold survival_

表中最值得注意的不是哪个品种的 gross Sharpe 最高，而是 gross 到 net 的落差：

品种

平均 IC

Gross Sharpe

Net Sharpe

成本拖累

Survival

NVDA

+0.005

1.308

+0.140

1.168

57.1%

AAPL

+0.006

1.169

\-0.409

1.578

57.1%

SPY

+0.008

0.356

\-0.786

1.142

42.9%

IWM

+0.009

1.065

\-0.787

1.852

42.9%

QQQ

+0.001

\-0.050

\-0.990

0.940

57.1%

TLT

+0.003

3.182

\-1.463

4.645

14.3%

XLK

+0.005

0.477

\-1.870

2.347

14.3%

ES1!

\-0.001

\-0.303

\-1.950

1.647

42.9%

XLV

\-0.002

1.955

\-2.089

4.044

42.9%

JPM

+0.007

2.310

\-2.924

5.234

14.3%

XLE

+0.010

\-0.031

\-3.671

3.640

14.3%

XLF

+0.003

0.339

\-3.914

4.253

28.6%

组合均值

+0.004

+0.981

\-1.726

2.906

35.7%

NVDA 是全样本中唯一平均 net Sharpe 为正的品种，数值为 。原因不是 OFI 在 NVDA 上突然变成更强的理论信号，而是样本期内 NVDA 年化 realized volatility 约 39.7%，约为 SPY 的 3.6 倍，高波动放大了每笔预测方向正确时的 gross PnL，使固定 spread 成本相对变小。研究也明确提醒，这可能是 2024—2025 年 AI rally 的样本特异性；若 NVDA 回到约 25%—30% 的正常波动区间，net Sharpe 估计会回落到约 -0.20 至 -0.40。

* * *

## 六、回测真正的分水岭：交易成本与持有期

### 1\. 成本模型

对 SPY，单笔交易的成本拆为三部分：

-   实际盘口 spread crossing：平均约 0.35 bps；
    
-   Almgren–Chriss square-root market impact：约 0.06 bps；
    
-   commission：约 0.10 bps。
    

因此总成本约为：

策略按信号方向买 ask、卖 bid，等价于在每次调仓时主动跨越 spread。净收益可以用最简单的账本表达：

其中  是交易次数， 是每次交易名义金额。高频策略的关键不是单笔成本看起来只有半个基点，而是每天会把这个半基点重复很多次。

### 2\. 持有期扫描

SPY、100 万美元组合的 holding-period sweep 如下：

持有期

Gross Sharpe

Net Sharpe

成本 / Gross

最大回撤

是否存活

10 秒

2.002

\-45.5

2400%

\-44.6%

否

30 秒

1.100

\-22.8

2180%

\-31.7%

否

1 分钟

0.677

\-17.2

2653%

\-25.3%

否

5 分钟

1.824

\-2.3

224%

\-4.7%

否

10 分钟

0.989

\-1.3

227%

\-2.5%

否

30 分钟

0.878

+0.114

87%

\-2.33%

是

十秒执行频率下，spread-crossing 成本每天约 819 bps，而 gross signal edge 约 5 bps，成本约是 gross edge 的 164 倍。这个数量级解释了为什么一个 IC 显著的模型会得到极差的 net Sharpe：IC 衡量的是排序方向，不能自动扣除成交价格和调仓次数。

![](assets/006.jpg)

_图： gross Sharpe 和 net Sharpe 随持有期的断层，30 分钟是该成本假设下第一个净 Sharpe 略为正的点。_

### 3\. 一个可复用的盈亏平衡推导

设每次交易产生的平均 gross edge 为  bps，持有期为 ，每天交易次数近似为 ，单笔成本为 。每天的成本拖累为：

盈亏平衡的必要条件是：

如果简单假设信号的 gross edge 随持有期增加而缓慢衰减，但交易次数近似与  成反比，那么延长持有期会显著减少成本次数；这正是 10 分钟仍然亏损、30 分钟刚刚转正的直觉来源。这里不能把 30 分钟当成普适答案，它只是该数据、该执行模型和该成本假设下的 break-even frontier。

### 4\. 三个改变 break-even 的杠杆

第一，延长持有期。从 10 分钟延长到 30 分钟不需要更换交易基础设施，却能把成本拖累从 gross PnL 的 227% 降到 87%。

第二，做 regime filtering。stressed 状态占 72.9% 的 bar，且在特定条件下 5 分钟 IC 可达 0.0148，约为全局短周期 IC 的数倍。但 HMM 过滤会减少可交易时段，也会引入在线状态识别复杂度，不能只看条件 IC 的点估计。

第三，使用 passive limit-order execution。spread 是总成本中约 69% 的部分。如果假设 50% 的限价单被动成交，spread 成本可从 0.35 bps 降至约 0.18 bps，10 分钟 net Sharpe 的估计值可从 -1.30 改善到约 +0.30；100% 被动成交的估计值约 +1.58，但对一个试图利用短暂订单流压力的策略来说，这个成交率并不现实。

* * *

## 七、Level-1 与 Level-2：信息损失的方向性证据

### 1\. 为什么 best bid/ask 可能低估 OFI

Level-1 只看最优买卖价位，无法观察第二档、第三档乃至更深队列。若大量撤单、补单和成交发生在深度档位，best-level OFI 可能把不同的真实订单流压缩成相同的十秒变化，形成 attenuation bias，即信号被测量误差向零拉回。

为检查这一点，研究用 Databento XNAS ITCH Market-By-Order 数据重建 NVDA 的完整订单簿，覆盖 2025 年 2 月 3 日至 3 月 28 日的 40 个交易日、约 91,221 个十秒 bar。订单簿引擎按 order ID 追踪 add、cancel 和 fill 事件，并使用 Numba JIT 加速。

### 2\. 结果如何解释

五分钟 horizon 上，depth-aware Level-2 OFI 的绝对 IC 约为 0.0046，Level-1 的绝对 IC 约为 0.0026；但两者的统计检验都不显著， 值分别约为 0.43 和 0.16，regime difference 的 Fisher z-test 为 。

![](assets/007.jpg)

_图： Level-2 深度信息在 10 秒和 5 分钟处往往给出更大的绝对 IC，但当前 40 天样本不足以证明差异显著。_

正确的结论是“方向性支持 Level-1 attenuation bias”，而不是“Level-2 已被证实更赚钱”。如果要把这个观察变成可部署的 alpha，需要至少延长样本、控制数据供应商差异、统一事件重建规则，并重新做 execution-aware backtest。

* * *

## 八、统计稳健性：哪些结果可以相信，哪些结果只能当线索

### 1\. 样本外与多重检验

最终两个月的 out-of-sample 结果为：IC ，gross Sharpe 2.491，net Sharpe 。样本内和样本外 IC 的 Welch t-test 没有发现显著差异。这支持“信号没有完全依赖训练集”的判断，但两个月仍然很短，不能等同于长期稳定。

PBO-style CSCV 在 25 个 model-horizon 配置、12 个品种和 35 个组合切分上得到 robustness score 0.1429，明显低于 0.50 的随机基线。但用于 CSCV 的独立月数只有 7，低于通常建议的至少 16 个时期，因此这个数更适合作为透明披露的警示，而非过拟合的最终定论。

Deflated Sharpe Ratio 也只能作为一致性检查：gross DSR 约 1.00，net DSR 约 0.00；因为最终部署规格只算一个 trial，deflation 项本身很小。

### 2\. 因子归因没有发现显著 alpha

把组合日收益放进 Fama–French 三因子回归：

样本内  只有 0.040，alpha 的 ，唯一显著的是 SMB beta ，，表现为大盘股倾向。这个结果提醒我们：短周期 OFI 的 IC 显著，并不意味着日收益组合会产生独立于传统风险因子的长期 alpha。

### 3\. 研究限制清单

-   Level-1 数据存在深度信息丢失；Level-2 比较只覆盖 NVDA 的 40 天；
    
-   全样本虽然有 13 个月，但真正的样本外月份只有 7 个；
    
-   十秒 bar 的预测能力不能直接外推到更细的逐笔成交或更长持有期；
    
-   回测使用简化的成交和 market impact 假设，没有 live execution simulator；
    
-   单一归一化尺度可能造成不同资产之间的 signal-cost mismatch；
    
-   NVDA 的正 net Sharpe 可能被 AI rally 和异常高波动放大。
    

这些限制不是附录里的形式主义，而是决定研究结论能否迁移到下一段样本的边界条件。

* * *

## 九、给量化研究员的可复现路线

如果要在自己的数据上复现或扩展这个想法，可以按以下顺序搭建 pipeline：

### 第一步：先做事件级数据审计

检查 timestamp 唯一性、bid/ask 非负、spread 非负、size 非负，以及交易时段切分。不要在清洗之前聚合 OFI，否则错误报价会被累积进一个看似正常的 bar。

### 第二步：明确 OFI 的符号和边界

固定“正值代表买方压力”的约定，分别单测买一上移、买一数量变化、卖一上移、卖一数量变化和撤单事件。每个测试都要能解释为什么符号为正或负。

### 第三步：特征只使用过去信息

所有 rolling mean、rolling volatility、标准化和 HMM fit 都必须在预测时点之前完成。一个实用的检查是：随机选一个 test date，删除该日期之后的所有记录，确认模型输出完全不变。

### 第四步：处理 target overlap

对  分钟 forward return，至少按照不重叠的  个 bar 采样一次 IC；或者在严格的 HAC 协方差框架下明确建模重叠结构。不能把大量高度相似的目标当成独立证据。

### 第五步：先线性、后非线性

先用标准化 Ridge 建立基线，再比较 Lasso、Elastic Net、LightGBM 或深度模型。每增加一个模型和 horizon，就增加一次 multiple-testing 负担，不能只报告最好的配置。

### 第六步：把执行假设放进同一张结果表

至少同时报告 mean IC、ICIR、Newey–West t-stat、gross Sharpe、net Sharpe、turnover、spread cost、impact cost、最大回撤和 OOS 结果。只给 IC 或 gross Sharpe，会把最重要的经济约束藏起来。

### 第七步：用 break-even frontier 代替单点 Sharpe

对持有期、执行方式、被动成交率、参与率和手续费做网格扫描。研究最终关心的不是“回测最优参数是多少”，而是策略在多大成本范围和多少成交延迟下仍然不亏。

* * *

## 十、结论：微观结构 alpha 的价值也可以体现在“知道它不够交易”

这项实证给出的价值，不只是一个正的 OFI 系数。它把几个经常被分开报告的事实放在同一条证据链上：

1.  最优报价队列的净变化确实包含短期方向信息；
    
2.  同期价格影响很强，forward IC 却快速衰减；
    
3.  Ridge 能稳定提取这类分布在多个特征上的近似线性关系；
    
4.  HMM 显示市场状态会改变信号的强弱，但条件结果仍需更长样本验证；
    
5.  跨资产的平均 IC 为正，不代表每个品种都能在成本后赚钱；
    
6.  在十秒级主动执行下，spread crossing 足以把 gross Sharpe 2.002 变成 net Sharpe -45.5；
    
7.  30 分钟是当前成本假设下的第一个可行持有期，NVDA 的正净 Sharpe 暂不能视为普遍规律；
    
8.  Level-2 深度信息可能减轻 Level-1 的测量衰减，但现有比较只能算探索性证据。
    

对实际研究工作而言，最重要的判断标准不是“统计显著是否足够漂亮”，而是信号半衰期、换手率、成交方式和市场状态能否共同落在可实现的成本边界内。一个经过样本外检验、但在真实执行下明确亏损的信号，仍然可以成为有价值的研究基线；它告诉我们下一步应该延长持有期、改进被动执行、补充 Level-2 数据，还是干脆停止在错误的频率上优化模型。

* * *

## 参考文献

1.  Kethan S. E. (2026). _Predictive Order Flow Imbalance: Cross-Asset Microstructure Alpha_. Working Paper, July 2026.
    
2.  Cont, R., Kukanov, A., & Stoikov, S. (2014). The price impact of order book events. _Journal of Financial Econometrics_, 12(1), 47–88.
    
3.  Kyle, A. S. (1985). Continuous auctions and insider trading. _Econometrica_, 53(6), 1315–1335.
    
4.  Glosten, L. R., & Milgrom, P. R. (1985). Bid, ask and transaction prices in a specialist market. _Journal of Financial Economics_, 14(1), 71–100.
    
5.  Easley, D., López de Prado, M., & O'Hara, M. (2012). Flow toxicity and liquidity in a high-frequency world. _Review of Financial Studies_, 25(5), 1457–1493.
    
6.  Lee, C. M. C., & Ready, M. J. (1991). Inferring trade direction from intraday data. _Journal of Finance_, 46(2), 733–746.
    
7.  Almgren, R., & Chriss, N. (2001). Optimal execution of portfolio transactions. _Journal of Risk_, 3(2), 5–39.
    
8.  Newey, W. K., & West, K. D. (1987). A simple, positive semi-definite, heteroskedasticity and autocorrelation consistent covariance matrix. _Econometrica_, 55(3), 703–708.
    
9.  Rabiner, L. R. (1989). A tutorial on hidden Markov models. _Proceedings of the IEEE_, 77(2), 257–286.
    
10.  Petersen, M. A. (2009). Estimating standard errors in finance panel data sets: Comparing approaches. _Review of Financial Studies_, 22(1), 435–480.
     
11.  Bailey, D. H., & López de Prado, M. (2014). The deflated Sharpe ratio. _Journal of Portfolio Management_, 40(5), 94–107.
     
12.  Kolm, P. N., Turiel, J., & Westray, N. (2023). Deep order flow imbalance: Extracting alpha at multiple horizons from the limit order book. _Mathematical Finance_, 33(4), 1044–1081.
     
13.  Zhang, Z., Xiong, X., & Li, S. (2021). Multi-level order-flow imbalance and price prediction in limit order book markets. _Quantitative Finance_, 21(11), 1853–1871.