# 高频交易系统（31）：hftbacktest中订单提交与订单管理

fintechhaibin FinTechHi 2026-05-18 06:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490341&idx=1&sn=301f66b3bf09c62fcab2b29919e1ef5d&chksm=fb78ddb7c42d1963250299084d5db4c8f2c65414a7d6caae963798d381faa198c04eaed78a6f#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490341&idx=1&sn=301f66b3bf09c62fcab2b29919e1ef5d&chksm=fb78ddb7c42d1963250299084d5db4c8f2c65414a7d6caae963798d381faa198c04eaed78a6f#rd)

这篇是hftbacktest中的订单相关的一些定义，如果对FIX协议熟悉的，就比较好理解。定义方式上和CTP的大致也差不多，只是国外市场在报单方式上更丰富一些。

hftbacktest订单状态常量：

```
from hftbacktest import LIMIT, GTC, NONE, NEW, FILLED, CANCELED, EXPIRED
```

1.订单状态

状态

含义

常见后续可能状态

**NONE**

订单还未提交到交易所（例如：刚在本地创建，未发送）

NEW 或 直接被丢弃

**NEW**

交易所已接受订单，正在等待成交

FILLED, CANCELED, EXPIRED, 或 部分成交后仍为 NEW

**FILLED**

订单已完全成交

终态，不再变化

**CANCELED**

订单被用户或系统主动取消

终态

**EXPIRED**

订单因超出有效期（如日内有效单未在收盘前成交）而被系统撤销

终态

  

2.订单操作（请求）

请求状态

含义

说明

**NONE**

无待处理请求

当前没有正在进行的提交或取消操作，处于空闲状态

**NEW**

提交订单请求中

已发出“提交订单”的请求，正在等待交易所的确认（是否接受）

**CANCELED**

取消订单请求中

已发出“取消订单”的请求，正在等待交易所确认取消结果

  

3.订单类型

-   LIMIT，限价单
    
-   MARKET，市价单
    

  

4.订单有效期类型：

类型

含义

核心规则

典型场景

**GTC**

Good Till Cancel

一直挂在订单簿上有效，直到被成交、用户主动取消、或触发系统过期（如某些交易所设90天上限）

普通限价单，不急于成交，追求好价格

**GTX**

Post Only / 只做Maker

订单进入订单簿后，如果**立即与已有订单成交**（吃单），则**自动取消**；只允许作为挂单提供流动性

交易手续费有 Maker/Taker 之分时，**只为赚取手续费返还或返佣**

**FOK**

Fill Or Kill

订单必须**立即完全成交**，无法完全成交则整个订单取消

大单要求一次性成交，避免部分成交后剩余滑点风险

**IOC**

Immediate Or Cancel

订单立即成交**尽可能多的数量**，剩余未成交部分立即取消

需要快速建仓/平仓，能接受部分成交，但不希望剩余单子留在盘口

  

5.订单对象

1）数量相关

字段

含义

典型关系

`qty`

下单数量（原始委托量）

`qty = leaves_qty + exec_qty`

`leaves_qty`

剩余未成交量

随部分成交递减，终态时应为 0（除非取消/过期有遗留）

`exec_qty`

已成交量

随成交递增，终态时 ≤ `qty`

注：注意：对于 `FOK` / `IOC` / `GTX` 类型，`leaves_qty` 可能在瞬间变为 0 或直接被拒绝。

2）价格相关

字段

含义

计算关系

`price_tick`

订单价格（以 tick 为单位）

`实际价格 = price_tick × tick_size`

`exec_price_tick`

成交价（以 tick 为单位）

可能存在多笔成交均价的情况

`tick_size`

最小价格变动单位

由交易所/交易对决定（如 0.01 元、0.0001 BTC）

使用 `_tick` 字段可避免浮点数精度问题，适合存储为整数（如 `int64`）。

### 3）时间相关

字段

含义

精度建议

`exch_timestamp`

交易所撮合引擎处理时间

毫秒或微秒级（交易所权威时间）

`local_timestamp`

本地发送或收到时间

用于**延迟监控**和**时序对齐**

常见用途：`local_timestamp` - `exch_timestamp` = 网络 + 撮合延迟

4）标识与状态

字段

含义

说明

`order_id`

订单唯一标识

通常是交易所返回的 ID

`order_type`

订单类型

如 `LIMIT` / `MARKET` / `STOP` 等

`req`

请求状态

你之前定义的 `NONE` / `NEW` / `CANCELED`

`status`

订单状态

`NONE`

 / `NEW` / `FILLED` / `CANCELED` / `EXPIRED`

`maker`

是否以 Maker 成交

仅在成交事件中有意义，用于手续费计算

  

6.订单状态流转示例

```
1. 下单成功
```

  

7.交易中常见处理场景：

场景

处理建议

**部分成交多次**

`exec_price_tick`

 需要记录**每笔成交的明细**，否则只能存储加权平均价

**tick\_size 变化**

交易所偶尔会调整 tick\_size，订单历史中的 `tick_size` 应**随订单固化存储**

**maker 字段**

仅在 `status=FILLED` 且单笔成交时可用；批量成交需要逐笔明细

**leaves\_qty 与 status**

`status=CANCELED`

 时 `leaves_qty` 是剩余的**未成交被取消**的数量

**FOK/IOC 失败**

`status=CANCELED`

, `leaves_qty` = `qty`, `exec_qty` = 0

  

8.不同订单操作示例代码

下面代码实现了一个加密货币订单类型演示的回测功能，使用BTC期货历史数据，在10毫秒订单延迟、Maker 0.02%和Taker 0.07%手续费的环境下，依次演示了限价单（GTC）、Post Only（GTX）订单、订单修改、订单取消、市价单（FOK）以及IOC订单的提交与处理过程，并实时监控订单状态变化、持仓、余额及交易统计信息。

```
from numba import njit
```

运行结果如下：

```
时间:  1778573568908000000 , 迭代:  120
```