# 高频交易系统（28）：hftbacktest中回测框架

fintechhaibin FinTechHi 2026-05-14 06:49 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490308&idx=1&sn=9cc865c1b8f2253b41593fff07934b9a&chksm=fb8751f7284c0bba7f41175b320f77ec548ad223cf54383f2c28e67bc4b80c4f22021c0bf1c8#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490308&idx=1&sn=9cc865c1b8f2253b41593fff07934b9a&chksm=fb8751f7284c0bba7f41175b320f77ec548ad223cf54383f2c28e67bc4b80c4f22021c0bf1c8#rd)

HftBacktest的回测框架如下：

```
# 1. 写配置
```

直接看单次回测代码：

```
from numba import njit
```

如上的单次回测代码框架中：

模块

作用

`@njit策略函数`

回测逻辑主体，控制时间推进、读取盘口、下单等

`BacktestAsset`

配置：数据、合约、延迟、手续费、最小变动单位

`HashMapMarketDepthBacktest`

回测引擎，基于哈希表的盘口重建

`hbt.elapse(时间)`

让回测时间向前推进

`hbt.depth(0)`

获取当前最新盘口（买一、卖一、深度）

`hbt.close()`

销毁回测实例，**必须执行**

关键参数：

```
tick_size=0.1：价格最小变动单位（BTC 每跳 0.1 USDT）
```

运行结果：

```
开始回测...
```

可以看到回测框架依赖两个类：

BacktestAsset和HashMapMarketDepthBacktest。

其中BacktestAsset相当于回测开始时的配置参数准备模块，确定一个回测策略的静态基本参数，这个和聚宽回测功能都差不多。

BacktestAsset是量化回测系统的纯参数配置组件，仅负责配置打包，不执行计算、回测与模拟逻辑。它采用Builder建造者模式与链式API设计，支持分步、流畅地设置回测相关参数，大幅提升配置可读性与易用性。

底层基于Rust结构体实现高性能、安全稳定的参数存储，保证数据结构严谨高效；上层通过Python做轻量化封装，提供简洁易用的调用接口，降低使用门槛。该组件核心价值是规范、高效地整合回测参数，并统一交付给回测引擎，实现配置与计算逻辑解耦，让系统架构更清晰、易维护。具体核心参数包括：

属性名

作用说明

`data`

存储标的的行情 / 事件数据源列表（`DataSource<Event>` 类型），是回测的核心数据载体

`asset_type`

标的类型（如现货、期货等，`AssetType` 枚举）

`latency_model`

订单延迟模型（决定订单提交 / 响应的延迟计算逻辑）

`queue_model`

订单队列模型（模拟交易所订单簿的撮合 / 排队规则）

`exch_kind`

交易所类型（`ExchangeKind` 枚举，适配不同交易所的规则）

`tick_size`

最小价格变动单位（如股票的 0.01 元）

`lot_size`

最小交易数量单位（如期货的 1 手）

`last_trades_cap`

最近成交记录的缓存容量（用于回测中快速查询近期成交）

`roi_lb`

/`roi_ub`

ROI（收益）计算的上下边界（用于收益风控 / 统计）

`initial_snapshot`

标的初始快照数据（可选），用于回测启动时初始化订单簿状态（如开盘前的订单簿快照）

`fee_model`

手续费模型（计算交易手续费的规则）

`latency_offset`

延迟偏移量（跨交易所回测时，调整订单延迟的补偿值）

`parallel_load`

是否并行加载数据（优化大数据量下的加载性能）

最重要的是HashMapMarketDepthBacktest，等于是这套系统回测引擎，根据策略的参数配置，模拟整个市场和交易所的运行，主要功能包括：

-   回放历史盘口数据
    
-   推进时间
    
-   模拟下单
    
-   模拟成交
    
-   计算仓位、盈亏
    

  

逻辑顺序如下：

```
BacktestAsset（配置）
```

其中回测引擎有两个：

引擎

存储结构

适用场景

速度

**HashMapMarketDepthBacktest**

哈希表

只用到最优几档

够用

**ROIVectorMarketDepthBacktest**

数组

需要全档深度 / 高频策略

**极快**

推荐先把HashMapMarketDepthBacktest使用熟练。其中回测引擎中设计到高频交易回测几个关键的模块，概要如下：

子模型

常见实现方式

撮合模型

1\. 连续撮合（Continuous Matching）：实时按价格优先、时间优先撮合

2\. 集合竞价（Call Auction）：固定时间撮合（如开盘 / 收盘）

3\. 做市商优先撮合：做市商订单优先成交

手续费模型

1\. 固定费率模型（FixedFeeModel）：maker/taker 固定费率

2\. 阶梯费率模型（TieredFeeModel）：交易量越大费率越低

3\. 返佣模型（RebateFeeModel）：maker 获得返佣

订单簿模型

1\. 全深度订单簿（FullBook）：存储所有价位的订单2. 精简订单簿（L2Book）：仅存储前 N 档价位（如前 5 档）

3\. 增量更新订单簿：仅同步订单簿变动（而非全量）

风控模型

1\. 仓位限制模型：限制单品种 / 总仓位上限

2\. 挂单限制模型：限制单个价位的挂单量

3\. 熔断模型：价格波动超限后暂停交易