# 因子构建中的算子：Transformational

FinTechHi FinTechHi 2025-09-01 06:15 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247487450&idx=1&sn=d4ab9c5efc14c90ccdc48ac3b1c6ba84&chksm=fb29440b29fad5af0ae16c87a2f24d2732e46d70ba1636d9071471a37a7d799e0cd774229180#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487450&idx=1&sn=d4ab9c5efc14c90ccdc48ac3b1c6ba84&chksm=fb29440b29fad5af0ae16c87a2f24d2732e46d70ba1636d9071471a37a7d799e0cd774229180#rd)

> 关于量化投资过程中，使用到算子，根据worldquant官方提供的算子类别及解释，并通过DeepSeek进行深入的学习和小结。
> 
>   
> 
> 这些知识看似基础，深刻理解以及灵活应用却是量化投资过程中的基础中的基础，是进一步构建因子、构建策略、构建风险管理及组合优化的“零件”，通过了解这些“零件”，我们才能保持后续工作的合理性和准确性。

  

其中官方的大类算子类型主要包括7大类：

-   ## Arithmetic
    
-   ## Logical
    
-   ## Time Series
    
-   ## Cross Sectional
    
-   ## Vector
    
-   ## Transformational
    
-   ## Group
    

  

参考本系列文章：

[因子构建中的算数算子：Arithmetic](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487422&idx=1&sn=4665cec001da4f445591c6b53e628972&scene=21#wechat_redirect)

[因子构建中的逻辑算子：Logical Operators](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487434&idx=1&sn=be8245aebab9d82a47576b2dd3d04a8a&scene=21#wechat_redirect)

[因子构建中的时序算子：Time Series](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487433&idx=1&sn=4e7bbb200a82b4d365703d1fca71ef1c&scene=21#wechat_redirect)

[因子构建中的截面算子：Cross Sectional](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487435&idx=1&sn=fd6dab90217d5def3914eb72a47a47a6&scene=21#wechat_redirect)

[因子构建中的算子：Vector](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487438&idx=1&sn=414814e1ad059206c82e096e2b0c2f23&scene=21#wechat_redirect)

本篇介绍：Transformational。

**Transformational（转换类）** 算子，只是对一种算子类型的抽象概况，并不是一个专业术语名词。

其描述的是一类通过对基础数据（价格或基本面）进行**时间序列上的加工与转换**，以提取出具有预测能力的**动态特征**的完整过程。

它的核心不再是简单的“变化”，而是**“从状态中提取趋势”**。

-   **输入**：原始的时间序列数据（如价格、成交量、财报数据）。
    
-   **处理**：应用各种算子，计算其变化、动量、波动、加速度等**衍生特征**。
    
-   **输出**：一个新的、更具预测力的**因子信号**。
    

  

如果用炒菜来类别：

-   **输入：原始数据**是**生鲜食材**（萝卜、青菜、猪肉）。
    
-   **处理：Transformational 处理**就是**烹饪过程**（切丝、翻炒、调味）。
    
-   **输出：****一道美味的菜肴**（鱼香肉丝）。
    
      
    

食材本身很普通，但经过“转换”后，价值倍增。

  

一个典型的 Transformational 因子构建包含以下层次：

  

#### 层次 1：计算原始特征（Raw Transformation）

  

这是最基础的转换，直接从价格序列计算各种指标。

-   **动量 (Momentum)**:
    

-   `returns = close / close[10] - 1`// 计算10期收益率
    
-   **逻辑**：捕捉价格的方向性运动。
    

-   **波动率 (Volatility)**:
    

-   `volatility = vec_std(returns(lookback_window))`// 计算过去N期的收益率标准差
    
-   **逻辑**：衡量价格变化的剧烈程度。
    

-   **加速度 (Acceleration)**:
    

-   `accel = returns(short_window) - returns(long_window)`// 短期动量 - 长期动量
    
-   **逻辑**：捕捉动量的变化速度，看趋势是在加速还是减速。
    

####   

#### 层次 2：标准化与平滑（Normalization & Smoothing）

  

将层次1输出的原始特征处理成可用于横截面比较的稳定信号。

-   **横截面排名**:
    

-   `x_rank = vec_rank(x)`// 计算因子值在股票池中的排名
    
-   **目的**：转化为均匀分布，消除极端值影响。
    

-   **Z分数标准化**:
    

-   `x_zscore = (x - vec_avg(x)) / vec_std(x)`// 去中心化并缩放
    
-   **目的**：使不同因子的尺度一致，便于合成。
    

-   **时间序列平滑**:
    

-   `x_smooth = ts_mean(x, window=5)`// 计算5期移动平均
    
-   **目的**：减少噪声，使信号更稳定，降低换手率。
    

####   

#### 层次 3：信号管理与触发（Signal Management）

将Transformational的思想应用到信号本身的管理上，决定**何时相信**并执行这个信号。

-   **事件触发**:
    

-   `final_signal = trade_when(trigger_condition, raw_signal, exit_condition)`
    
-   **逻辑**：只有当特定的转换条件成立时（如成交量突破、波动率收缩），才采用新的信号；否则**持有现有头寸**。这本身就是一个基于动态变化的决策。
    

-   **状态保持**:
    

-   **`else, Alpha = previousAlpha`** 这一行代码是Transformational思维的升华。它承认“**不变化**”本身也是一种重要的“状态”，持有头寸本身就是一个有意义的决策，而不是盲目地每天调仓。
    

  

worldquant给出了两个算子：bucket(rank(x), range="0, 1, 0.1" or buckets = "2,5,6,7,10")和trade\_when(x, y, z)。

  

1.bucket(rank(x), range="0, 1, 0.1" or buckets = "2,5,6,7,10")  

`   `

`bucket（分组，分箱）`是量化投资中一个**将连续变量（如因子值）转换为离散分组**的核心算子。它的本质是**将数值按区间划分**，并为每个区间分配一个**分组编号**（Bucket Index），从而方便后续的**分组处理**（如分组中性化、分层回测等）。

  

-   **分组中性化（Group Neutralization）**：
    
    在**同一分组内**对因子进行去均值处理，消除行业、市值等变量的影响。
    
    例如：在**每个市值分组内**，对估值因子进行标准化，避免市值偏差。
    
-   **分层回测（Stratified Backtesting）**：
    
    按分组研究因子的单调性（如十分位回测）。
    
-   **风险控制**：
    
    确保组合在不同分组（如行业、风格）上的暴露均衡。
    
      
    

**此算子的核心逻辑是：将一个连续的数值（如 `rank(x)`）映射到预定义的离散区间（即“分桶”或“分段”）。**

**参数解析：**

1.  **`rank(x)`**: 这是要放入桶中的输入值。`rank()` 本身是一个函数，通常用于计算某行数据在分组内的排名（例如，排名第1，第2等）。所以 `rank(x)` 的结果是一个代表排名的数字。
    
      
    

1.  **`range="0, 1, 0.1"`**:
    

-   `本示例中"0, 1, 0.1"` 三个参数值分别表示：
    

-   `range` 关键字表示定义一个**等距的、连续的数值区间**。
    
-     
    

-   **起始值 (Start)**: `0`
    

-   **结束值 (End)**: `1`
    

-   **步长/桶宽 (Step/Size)**: `0.1`
    

`   `

-   **逻辑**：
    
-   函数会创建从 `0` 到 `1`，步长为 `0.1` 的多个桶。
    
-   即 `[0, 0.1)`, `[0.1, 0.2)`, `[0.2, 0.3)` ... `[0.9, 1.0)`。
    
-   函数会判断 `rank(x)` 的值落在哪个区间，并返回该区间的标识（通常是区间的上限或一个代表区间的标签）。
    

  

下面看一个量化投资中的实际示例：

### 量化投资示例：构建十分位投资组合（Decile Portfolio）

**背景**：量化基金经理想要测试一个因子（例如：动量因子）的有效性。他们需要将所有股票按因子值排名，然后分成10个等分的组合（十分位），观察每个组合的未来表现。

#### 第1步：计算因子值和排名

假设我们有N只股票，为每只股票计算其**动量因子**值（例如：过去12个月的收益率，剔除最近1个月）。

`SELECT      stock_code,   date,   -- 计算动量因子：过去12个月至前1个月的收益率     (price / price_12m_ago - 1) AS momentum_factor,   -- 在整个股票池中按动量因子值排名，并转化为0-1之间的分位数排名   RANK() OVER (ORDERBY momentum_factor ASC) / COUNT(*) OVER () AS momentum_rank_percentile   FROM stock_price_table   WHEREdate = '2023-12-31';   `

**结果示例**：

stock\_code

momentum\_factor

momentum\_rank\_percentile

000001.SZ

\-0.25

0.05

000002.SZ

\-0.18

0.12

...

...

...

600019.SH

0.15

0.63

600036.SH

0.28

0.92

#### 第2步：使用Bucket函数进行分桶

`SELECT      stock_code,     momentum_factor,     momentum_rank_percentile,   bucket(momentum_rank_percentile, range='0, 1, 0.1') AS decile_portfolio   FROM (   -- 上面的排名查询   SELECT       stock_code,       momentum_factor,       RANK() OVER (ORDERBY momentum_factor ASC) / COUNT(*) OVER () AS momentum_rank_percentile   FROM stock_price_table   WHEREdate = '2023-12-31'   ) ranked_stocks;   `

#### 第3步：结果分析

**分桶结果示例**：

stock\_code

momentum\_rank\_percentile

decile\_portfolio

组合含义

000001.SZ

0.05

`[0.0, 0.1)`

**第1分位**

 - 动量最差的10%股票

000002.SZ

0.12

`[0.1, 0.2)`

第2分位

...

...

...

...

600019.SH

0.63

`[0.6, 0.7)`

第7分位

600036.SH

0.92

`[0.9, 1.0]`

**第10分位**

 - 动量最好的10%股票

#### 第4步：投资组合回测

**后续操作**：

1.  **构建投资组合**：买入第10分位的所有股票，卖出第1分位的所有股票（做多动量最强，做空动量最弱）
    
2.  **计算收益**：跟踪这两个组合在未来1个月、3个月、12个月的表现
    
3.  **分析结果**：
    

-   如果第10分位组合持续跑赢第1分位组合，说明动量因子有效
    
-   计算**多空收益差**（第10分位收益 - 第1分位收益）
    
-   计算**信息比率**、**夏普比率**等风险调整后收益指标
    

#### 量化意义

1.  **因子测试**：这是测试任何新因子（价值、质量、低波等）有效性的标准方法
    
2.  **组合构建**：用于构建基于因子的Smart Beta产品或量化对冲策略
    
3.  **风险控制**：确保每个分位组合包含相同数量的股票，避免个股权重偏差
    
4.  **业绩归因**：分析投资组合收益来源于哪个因子分位的暴露
    

**关键优势**：`bucket`函数确保了：

-   严格的十分位划分（每个组合包含10%的股票）
    
-   可重复的研究过程
    
-   清晰的组合定义，便于回测和实盘交易
    

  

**`如果是按buckets = "2,5,6,7,10"`**:

-   生成的桶例如：`[2, 5)`, `[5, 6)`, `[6, 7)`, `[7, 10]`。
    
-   函数会判断 `rank(x)` 的值落在哪个自定义区间内。
    

-   `buckets` 关键字表示定义一个**自定义的、不连续的边界点列表**。
    
-   `"2,5,6,7,10"` 定义了一系列边界点。
    
-   **逻辑**：函数会根据这些边界点创建桶。通常，桶的区间是左闭右开 `[a, b)`，最后一个桶是闭区间 `[a, b]`。
    

  

具体示例同上。综上所述：

`bucket`算子通过以下两种方式将连续值（如因子排名）转换为离散分组：

1.  **等间隔划分（range）**
    

-   将数值范围 `[start, end]`按固定步长 `step`切分为多个区间。
    
-   **默认包含两个隐藏区间**：`(-∞, start]`和 `[end, +∞)`。
    

3.  **自定义边界（buckets）**
    

-   直接指定分组的边界点 `a, b, c,...`，生成 `N-1`个区间（`N`为边界点数量）。
    
-   **默认包含两个隐藏区间**：`(-∞, a]`和 `[last, +∞)`。
    
      
    

-   注意：通常，桶的区间是左闭右开 `[a, b)`，最后一个桶是闭区间 `[a, b]`。
    

**输出**：每个输入值对应的分组编号（从 `0`开始）。

  

  

2.trade\_when(x, y, z)

该算子用于仅在满足特定条件时更新Alpha值，并在其他情况下保留原有Alpha值。

它同时还允许在满足特定条件时清空Alpha头寸（将其赋值为NaN）。

Trade\_When (x=触发交易条件, y=新Alpha值表达式, z=触发退出条件)

若触发退出条件 > 0，则将Alpha值设为NaN。

否则若触发交易条件 > 0，则Alpha = 新Alpha值表达式；

否则，Alpha = 上一期Alpha值。

该算子有助于降低策略相关性并减少换手率。

![](assets/001.png)

执行逻辑如下图所示：

![](assets/002.png)

以下面示例来说：

```
Trade_When (volume >= ts_sum(volume,5)/5, rank(-returns), -1)
```

**上述算子表达式：**

```
Trade_When (volume >= ts_sum(volume,5)/5, rank(-returns), -1)
```

`具体逻辑如下：`

1.  **触发交易条件 (x)**：`volume >= ts_sum(volume,5)/5`
    

-   **解释**：如果**当日成交量**大于或等于**过去5日成交量的平均值**，则此条件为真（True）。
    

3.  **新Alpha信号 (y)**：`rank(-returns)`
    

-   **解释**：计算一个新的信号。对所有股票的当日收益率 (`returns`) 进行排名，但取其负值（`-returns`）。这意味着**收益率越低（下跌越多）的股票排名越靠前**，本质上是一个**短期反转因子**（假设近期下跌的股票会反弹）。
    

5.  **触发退出条件 (z)**：`-1`
    

-   **解释**：这是一个永远为负的常数，因此**退出条件永远不可能被触发**（因为 `-1 > 0`为假）。
    

7.  **整体逻辑**：
    

-   **如果** 某只股票的成交量突破其5日均线，
    
-   **那么** 就使用反转因子 `rank(-returns)`作为该股票的新权重信号（进行调仓）。
    
-   **否则**（成交量未突破），就**维持该股票上一期的权重信号不变**（不进行调仓）。
    
-   **永远不**会因为退出条件而清仓。
    

**该示例的目的**：**仅在放量时调仓**，否则持仓不动。这是一种降低换手率、避免在清淡行情中无效交易的经典方法。

```
Trade_When (volume >= ts_sum(volume,5)/5, rank(-returns), abs(returns) > 0.1)
```

**上述算子表达式：**

```
Trade_When (volume >= ts_sum(volume,5)/5, rank(-returns), abs(returns) > 0.1)
```

**具体逻辑如下：**

1.  **触发交易条件 (x)**：`volume >= ts_sum(volume,5)/5`
    

-   **解释**：与示例1相同，成交量突破5日均线。
    

3.  **新Alpha信号 (y)**：`rank(-returns)`
    

-   **解释**：与示例1相同，使用短期反转因子。
    

5.  **触发退出条件 (z)**：`abs(returns) > 0.1`
    

-   **解释**：如果某只股票**当日收益率的绝对值大于10%**（即暴涨或暴跌超过10%），则此条件为真（True）。
    

7.  **整体逻辑（按优先级从高到低执行）**：
    

-   **那么** 使用反转因子 `rank(-returns)`作为该股票的新权重信号（进行调仓）。
    

-   **那么** 将该股票的Alpha值设为 `NaN`（**立即清仓**该股票的头寸）。
    

-   **首先检查**：`如果 abs(returns) > 0.1`
    
-   **否则，再检查**：`如果 volume >= ts_sum(volume,5)/5`
    
-   **否则**（即既没有触发退出，也没有触发交易），就**维持该股票上一期的权重信号不变**（不调仓）。
    

**该示例的目的**：在示例1的基础上，**增加了风险控制机制**。当单只股票出现极端波动时（无论涨跌），强制清仓以规避后续不确定性（如暴跌后的继续下跌或暴涨后的利好兑现回落）。这是一种动态风险管理的手段。

假设某日 3 只股票的 **volume** 和 **returns** 如下：

股票

当日成交量 (volume)

5日均值 (ts\_sum/5)

收益率 (returns)

rank(-returns)

是否调仓 (`x > 0`)

Alpha 信号

A

120

100

0.05

2

True

 (120 ≥ 100)

**2**

B

80

100

\-0.03

1

False 

(80 < 100)

**上一期值**

C

150

100

0.10

3

True 

(150 ≥ 100)

**3**

**结果**：

-   A 和 C 的成交量突破，Alpha 信号更新为 `rank(-returns)`（2 和 3）。
    
-   B 的成交量未突破，**维持上一期的 Alpha 信号**（不调仓）。