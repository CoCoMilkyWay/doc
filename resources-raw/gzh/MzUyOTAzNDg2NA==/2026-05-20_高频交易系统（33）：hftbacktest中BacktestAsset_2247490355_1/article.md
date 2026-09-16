# 高频交易系统（33）：hftbacktest中BacktestAsset

fintechhaibin FinTechHi 2026-05-20 06:24 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490355&idx=1&sn=4d8cfcc5656ee5a958226d35d36e7b47&chksm=fba7ab9bcee6aae4440a9db96bb467dd3a411cac5a48e7420ca8feb9806cc2f209547f628dcb#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490355&idx=1&sn=4d8cfcc5656ee5a958226d35d36e7b47&chksm=fba7ab9bcee6aae4440a9db96bb467dd3a411cac5a48e7420ca8feb9806cc2f209547f628dcb#rd)

### 

![](assets/001.jpg)

  
一、BacktestAsset 中 latency\_model 的实现分析

latency\_model（延迟模型）是 `BacktestAsset` 结构体的核心字段之一，结合 Python 层的封装逻辑，其实现可拆解为**底层 Rust 核心逻辑** + **Python 层调用接口**两部分：

#### 1\. 核心定位

`latency_model` 用于模拟订单从提交到交易所响应的延迟（如订单下单、撤单、成交确认的延迟），是高频回测中还原真实交易环境的关键组件，对应 Rust 中 `LatencyModel` 类型。

#### 2\. 实现逻辑

-   **底层 Rust 层**：`BacktestAsset` 结构体直接持有 `latency_model: LatencyModel`，说明延迟模型的核心逻辑由 Rust 实现（高频场景下 Rust 的性能优势）。`LatencyModel` 大概率是一个 trait（类似接口），定义了计算订单延迟的核心方法（如 `compute_order_latency`），不同延迟模型（如插值模型、固定延迟模型）会实现该 trait。
    
-   **Python 层封装（关键接口）**： Python 层通过 `intp_order_latency` 方法为 `latency_model` 赋值，该方法绑定了**插值型延迟模型（IntpOrderLatency）**：
    
    ```
    def intp_order_latency(self, data: str | NDArray | List[str], latency_offset: int = 0):    """使用插值法计算历史订单延迟的模型"""    if isinstance(data, str):        super().intp_order_latency([data], latency_offset)    elif isinstance(data, np.ndarray):        self._intp_order_latency_ndarray(data.ctypes.data, len(data), latency_offset)    elif isinstance(data, list):        super().intp_order_latency(data, latency_offset)    else:        raise ValueError    return self
    ```
    
    该方法的核心行为：
    

-   接收历史延迟数据（npz 文件/NumPy 数组），这些数据是真实交易中记录的订单延迟样本；
    
-   底层 Rust 会基于这些样本，通过**插值法**动态计算不同时间/订单类型的延迟（而非固定值）；
    
-   `latency_offset` 用于调整延迟偏移（跨交易所回测时，补偿不同站点的网络延迟差）。
    

#### 3\. 典型实现方式

`LatencyModel` 常见的具体实现：

-   **IntpOrderLatency（插值延迟模型）**：基于历史延迟数据，按时间/订单属性插值计算实时延迟（代码中明确暴露的类型）；
    
-   **FixedLatencyModel（固定延迟模型）**：所有订单使用固定延迟值（如 500 纳秒）；
    
-   **RandomLatencyModel（随机延迟模型）**：基于正态分布/均匀分布生成随机延迟；
    
-   **PercentileLatencyModel（分位数延迟模型）**：按历史延迟的分位数（如 95 分位）计算延迟。
    

### 二、如何使用 BacktestAsset 中的 queue\_model 进行交易

`queue_model`（队列模型）用于模拟交易所的订单簿队列行为（如订单排队、插队、撮合优先级），是还原订单成交概率的核心，其使用需结合回测流程，步骤如下：

#### 1\. 核心定位

`queue_model: QueueModel` 是 `BacktestAsset` 的字段，对应交易所订单簿的队列规则（如 FIFO 队列、Pro-Rata 撮合、优先级队列），决定了订单在订单簿中的排队位置和成交顺序。

#### 2\. 使用流程（结合高频回测逻辑）

##### 步骤 1：初始化 BacktestAsset 并配置 queue\_model

（代码未直接暴露 Python 层配置接口，但 Rust 层需先初始化队列模型）

```
// 伪代码：Rust 层初始化 QueueModel（如 FIFO 队列模型）let queue_model = FifoQueueModel::new(); // FIFO 是最常见的队列模型let asset = BacktestAsset {    queue_model: queue_model,    tick_size: 0.1, // 最小价格变动单位    lot_size: 1.0,  // 最小交易数量    // 其他字段初始化...};
```

##### 步骤 2：向 BacktestAsset 注入行情/订单数据

通过 Python 层 `data` 方法注入订单簿/成交数据，为队列模型提供运行上下文：

```
import numpy as npfrom hftbacktest import BacktestAssetasset = BacktestAsset()# 注入 npz 格式的行情数据（包含订单簿快照、成交事件）asset.data(["path/to/feed_data1.npz", "path/to/feed_data2.npz"])# 注入初始订单簿快照（可选，还原回测起始时的订单簿状态）asset.initial_snapshot("path/to/initial_snapshot.npz")
```

##### 步骤 3：提交订单并触发 queue\_model 逻辑

队列模型的核心作用是在**订单提交/撮合阶段**生效：

-   当向 `BacktestAsset` 提交限价单时，`queue_model` 会将订单插入到订单簿的对应价位队列中（如买单队列、卖单队列）；
    
-   当市场行情变动（如对手方订单成交），`queue_model` 会按规则调整队列顺序，并判断当前订单是否满足成交条件；
    
-   例如 FIFO 模型下，先提交的订单优先成交；Pro-Rata 模型下，按订单量占比撮合。
    

##### 步骤 4：获取队列模型的运行结果

回测过程中，可通过 BacktestAsset 的接口（未直接暴露，需结合 Rust 层方法）获取：

-   订单在队列中的位置；
    
-   订单的预计成交时间/概率；
    
-   队列长度变化、滑点情况等。
    

#### 3\. 关键注意事项

-   `queue_model` 需与 `tick_size`（最小价格单位）、`lot_size`（最小数量单位）配合使用，确保订单价格/数量符合交易所规则；
    
-   不同队列模型（如 FIFO、Pro-Rata、Priority）会显著影响成交结果，需根据目标交易所的真实规则选择。
    

### 三、BacktestAsset 中 exchange\_model（交易所模型）的常见实现方式

注：代码中字段名为 `exch_kind: ExchangeKind`（交易所类型），对应“交易所模型”的核心逻辑，`exchange_model` 可理解为围绕 `exch_kind` 实现的交易所行为封装，常见实现方式如下：

#### 1\. 按交易所类型区分（基于 ExchangeKind 枚举）

`ExchangeKind` 大概率是一个枚举类型，定义了主流交易所的类型，不同交易所对应不同的模型实现：

```
// 伪代码：ExchangeKind 枚举pub enum ExchangeKind {    BinanceFutures,  // 币安期货    BybitSpot,       // 币安现货    CME,             // 芝加哥商品交易所    Nasdaq,          // 纳斯达克    Okex,            // OKX}
```

不同 `ExchangeKind` 会绑定该交易所的核心规则：

-   撮合规则（如 CME 采用 Pro-Rata，纳斯达克采用 FIFO）；
    
-   手续费模型（如 Binance 的 maker/taker 费率）；
    
-   订单类型支持（如是否支持冰山单、止损单）；
    
-   开盘/收盘时间、熔断规则等。
    

#### 2\. 按核心功能模块拆分实现

交易所模型并非单一组件，而是由多个子模型组合而成，常见实现维度：

子模型

常见实现方式

撮合模型

1\. 连续撮合（Continuous Matching）：实时按价格优先、时间优先撮合  
2\. 集合竞价（Call Auction）：固定时间撮合（如开盘/收盘）  
3\. 做市商优先撮合：做市商订单优先成交

手续费模型

1\. 固定费率模型（FixedFeeModel）：maker/taker 固定费率  
2\. 阶梯费率模型（TieredFeeModel）：交易量越大费率越低  
3\. 返佣模型（RebateFeeModel）：maker 获得返佣

订单簿模型

1\. 全深度订单簿（FullBook）：存储所有价位的订单  
2\. 精简订单簿（L2Book）：仅存储前 N 档价位（如前5档）  
3\. 增量更新订单簿：仅同步订单簿变动（而非全量）

风控模型

1\. 仓位限制模型：限制单品种/总仓位上限  
2\. 挂单限制模型：限制单个价位的挂单量  
3\. 熔断模型：价格波动超限后暂停交易

#### 3\. 按实现方式分类

-   **硬编码实现**：针对特定交易所，直接硬编码其规则（适合单一交易所回测）；
    
-   **配置化实现**：通过配置文件定义交易所规则（如 JSON/YAML），运行时加载（适合多交易所回测）；
    
-   **插件化实现**：将交易所模型设计为可插拔的 trait，新增交易所时只需实现该 trait（扩展性最好）。