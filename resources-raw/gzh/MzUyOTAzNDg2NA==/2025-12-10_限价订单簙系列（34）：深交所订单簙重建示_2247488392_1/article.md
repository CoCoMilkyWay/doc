# 限价订单簙系列（34）：深交所订单簙重建示例

fintechhaibin FinTechHi 2025-12-10 22:34 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247488392&idx=1&sn=7b28cab870a42c83b836c541648e28c1&chksm=fbb92c88b88b19e18c2fb2061f389bd8244340f81a21b9dacc6abbe68160068c5b7065a173d0#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247488392&idx=1&sn=7b28cab870a42c83b836c541648e28c1&chksm=fbb92c88b88b19e18c2fb2061f389bd8244340f81a21b9dacc6abbe68160068c5b7065a173d0#rd)

# 围绕订单簙的内容都是基于公开的官方资料及参考资料，结合腾讯元宝大模型消化理解。就好比策略一样，核心都在细节点上和数据处理上以及性能优化上（保证低时延，否则无法支撑高频交易策略，做这件事情的意义也就没有了。），很难在公开场景下期望能有一个直接运行的。

#   

# 目前实盘提供全量订单簙的软件供应商也有，但这里有一个问题。

#   

# 如果实盘用行情软件供应商A的订单簙，那投研环境研究所需的订单簙为了同实盘保持一致性就有两个方案：

# 1.把实盘实时合成的订单簙数据通过合规渠道保存并能用于研究，核心问题是每日全市场合成的全量订单簙数据量非常大。

# 2.使用行情软件供应商A的订单簿工具以及行情数据商正式购买的level2历史数据合成。

#   

# 这种方案下以为太依赖于外围资源。所以实际中一般都会：自研订单簿工具，以便研究和实盘都能使用同一套系统。

#   

# 基于订单簙的自研工作，主要有两个层面：

# 1.业务上：的了解A股市场交易机制以及level2数据的特点。

# 2.技术上：的有一个能实时处理全市场股票订单簙的低时延高频交易系统底座。

#   

# 最近思考下来，高频交易策略的投入相对来说比较大，硬核实力要求比较高，费事费力费人，如果没有确切的策略目标，贸然开始会是一件性价比非常低的事情。

#   

# 本篇文章主要是以SZ为例，再理解下订单簙的思路（注：仅仅是思路！！！），大家也可以参考一些前辈的精彩分享：

#   

-   # DolphinDB:https://docs.dolphindb.cn/zh/2.00.12/tutorials/orderBookSnapshotEngine.html，重点推荐这篇，里面包括了乱序的逻辑处理，合成订单簿后准确性校验等，干货满满。
    
-   https://zhuanlan.zhihu.com/p/649040063
    
-   https://zhuanlan.zhihu.com/p/685461581
    

#   

# SZ逐笔数据为两个独立的（文件）结构，通过相关字段中可以区分：委托、撤单、成交；区分市价单、限价单、本方最优单，以及买卖。

#   

# 所以基于SZ逐笔数据重建订单薄基本不需要做什么特殊准备。

#   

# 本着由易到难，可以先通过重建深交所订单薄熟悉整个过程，为重建其他市场和证券品种打好基础。

  

1. SZ逐笔数据特征回顾

深交所逐笔文件分成两个独立的结构（文件）。详细说明参考文章：[高频交易系统（14）：高频交易中的行情数据](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247488327&idx=1&sn=eedef288497eb48ec9a216775447b47a&scene=21#wechat_redirect)

其中逐笔委托核心字段是：

![](assets/001.png)

其中逐笔成交核心字段是：

![](assets/002.png)

逐笔数据的时序保证通过ChannelNo 和 ApplSeqNum 作为唯一性排序。通过逐笔成交中的BidApplSeqNum和OfferApplSeqNum 和逐笔委托委托中ApplSeqNum关联查找原始委托。

2.统一内部数据结构

为提升订单簿合成工具对接多源逐笔数据的通用性，需先定义统一内部数据结构，将各来源原始数据标准化并按时序排序，形成唯一的事件流（含委托、撤单、成交），作为订单簿合成的统一输入，用于订单薄的合成或重建。利用deepseek整理了一个表格，仅供参考。  

统一结构字段

sz-order

sz-trade

sh-order&trade

**code**

`SecurityID`

`SecurityID`

`SecurityID`

**time**

`TransactTime`

`TransactTime`

`TickTime`

**event\_type**

0（委托）

`ExecType`

映射：  
`成交`→2  
`撤销`→1

`Type`

映射：  
`A`→0(委托)  
`D`→1(撤单)  
`T`→2(成交)  
`S`→3(状态，过滤)

**price**

`Price`

`LastPx`

`Price`

**qty**

`OrderQty`

`LastQty`

`Qty`

**order\_id**

`ApplSeqNum`

根据方向选择：  
买单→`BidApplSeqNum`  
卖单→`OfferApplSeqNum`

根据`TickBSFlag`选择：  
`B`→`BuyOrderNO`  
`S`→`SellOrderNO`

**counter\_order\_id**

0

根据方向选择：  
买单→`OfferApplSeqNum`  
卖单→`BidApplSeqNum`

根据`TickBSFlag`选择：  
`B`→`SellOrderNO`  
`S`→`BuyOrderNO`

**side**

`Side`

映射：  
`买`→1  
`卖`→2

根据`BidApplSeqNum`/`OfferApplSeqNum`判断

`TickBSFlag`

映射：  
`B`→1  
`S`→2

**order\_type**

`OrdType`

映射：  
`市价`→1  
`限价`→2  
`本方最优`→3

0（成交无订单类型）

0（上交所只有限价）

**seq**

`ApplSeqNum`

`ApplSeqNum`

`BizIndex`

  

处理深交所委托时，BuyNo 和 SellNo 均置为 0，即无实际意义。

深交所的逐笔委托数据中，ApplSeqNum 字段用于标识委托单的唯一编号。

当一个成交发生时，成交单中的 TradeBuyNo 和TradeSellNo 字段分别对应买方和卖方委托单的 ApplSeqNum 。

数据注入引擎之前，一定要按 ApplSeqNum 字段进行排序操作，否则会影响输出结果。

3.流程图

1）系统架构图（太长了，只能缩放截取，凑合看。）

![](assets/003.png)

2）事件流图

![](assets/004.png)

3）委托处理

![](assets/005.png)

4）撤单处理

![](assets/006.png)

5）成交处理

![](assets/007.png)

6）订单簿结构

![](assets/008.png)

  

4.代码示例

基于简化订单簿输入，我来详细说明各种情况的处理逻辑：

1\. 委托处理（event\_type = 0）

````
```python
````

加入订单簿队列

```
    orderbook.add_order(
```

2 ）撤单处理（event\_type = 1）

```
def process_cancel(order):
```

3\. 成交处理（event\_type = 2）

```

```

4）市价单处理（order\_type = 1）

```
def process_market_order(order):
```

5\. 本方最优单处理（order\_type = 3）

```
def process_best_owner_order(order):
```

个人基于公开资料以及结合腾讯元宝的学习笔记，有参考就好，没参考飘过。