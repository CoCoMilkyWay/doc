# 高频交易系统（27）：hftbacktest中使用Tardis数据

fintechhaibin FinTechHi 2026-05-13 22:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490307&idx=1&sn=6c9869db204529374a8099e85b991ae5&chksm=fb191221c67bdb5fe8650d8a0761ac460e6f73929efbf1d519dcf274fb8895e2a6e5ac0d2bab#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490307&idx=1&sn=6c9869db204529374a8099e85b991ae5&chksm=fb191221c67bdb5fe8650d8a0761ac460e6f73929efbf1d519dcf274fb8895e2a6e5ac0d2bab#rd)

hftbacktest的官方文档也提到了通过数据商Tardis.dev获取数据的办法。

**Tardis.dev 是一家专注于新兴全市场级历史数据的专业服务商**，主打 “**比自建采集更完整、质量更高**” 的逐笔（tick）与订单簿（L2）数据，覆盖主流交易所现货、合约，**付费制、提供免费数据样本**。

为**高频交易策略的****量化研究、策略回测提供高质量、开箱即用数据源**，解决自建数据 “缺漏、错乱、丢包” 痛点。

通过下面两个地址可以下载trades和book数据样例：

```
# https://docs.tardis.dev/historical-data-details/binance-futures
```

针对7\*24小时的快照问题：

SOD = Start of Day：每日开盘时的完整订单簿快照（L2 全档）。

Tardis 规则：每个日期文件（.csv.gz）头部强制插入当日 SOD 快照。

示例：

```
2020-02-01.csv.gz：含 02-01 开盘快照 + 全天增量
```

因此若连续多天回测时，正常逻辑只需第一天的SOD初始化订单簿，后续用增量更新即可。Tardis则每天都带独立SOD，回测时需每日重建订单簿，导致回测速度慢、冗余计算、内存开销大。Tardis官方给的方案两个：

```
# 方式1：仅处理第一天 SOD（推荐）
```

下载的BTCUSDT\_book.csv.gz数据定义：

列名

类型

含义

exchange

字符串

交易所：binance-futures

symbol

字符串

交易对：BTCUSDT

timestamp

整数

交易所原始时间戳（纳秒）

local\_timestamp

整数

Tardis 接收时间戳（纳秒）

is\_snapshot

布尔值

**是否为 SOD 开盘快照**

side

字符串

订单方向：ask（卖）/bid（买）

price

浮点数

价格

amount

浮点数

挂单量

数据样例：

```
binance-futures,BTCUSDT,1580515203429000,1580515203896061,true,ask,9366.32,0.01
```

数据特点：

-   数据形状：(27,199,023, 8) ：单日约 2700 万行数据
    
-   开头全是 SOD 快照：is\_snapshot = true
    
-   后面是逐笔增量更新：is\_snapshot = false
    

  

下载的BTCUSDT\_trades.csv.gz数据结构如下：

字段名

数据类型

字段含义

exchange

String

交易所标识：binance-futures 币安合约

symbol

String

交易对：BTCUSDT

timestamp

Int64

交易所撮合时间戳（纳秒级）

local\_timestamp

Int64

Tardis 服务器接收时间戳（纳秒级）

id

Int64

交易所唯一成交 ID

side

String

成交方向：buy /sell

price

Float64

成交价格

amount

Float64

成交数量

数据样例：

```
binance-futures,BTCUSDT,1580515202342000,1580515202497052,35530566,buy,9364.51,1.197
```

数据特点：

-   无 is\_snapshot 字段，纯成交记录，无盘口快照；
    
-   独有 id 成交编号，可唯一标识每一笔撮合；
    
-   side 为 buy/sell 真实成交方向，区别于深度数据 ask/bid；
    
-   时间戳统一纳秒级，和订单簿数据时间维度对齐，可联动回测。
    

  

交易数据（Trades）和深度数据（OrderBook）是高频交易中常用的数据。

Trades记录每一笔实际撮合成交（相当于A股level2中的逐笔委托和逐笔成交），包括成交价、成交量、买卖方向、时间、成交ID等字段，作为回测时的真实成交、量能统计、K 线合成等。OrderBook（订单簙数据，A股基于level2的千档行情），主要看盘口挂单增减变化，包括盘口档位价格、挂单量、买卖方向、时间、是否开盘快照，主要用于完整重建逐笔订单簿、模拟限价挂单、滑点仿真等。

从上面下载的测试数据量看：交易数据229,564行，深度数据27,199,023行，深度数据体量约为交易数据的118.48倍。做高频交易时，之所以要考察历史数据的存储，回测时数据加载及回测效率问题，就是因为ob数据量级非常大的前提。

二者共同字段exchange、symbol、timestamp、local\_timestamp、side、price、amount等。

交易数据特有id（成交唯一 ID），ob数据特有is\_snapshot（是否 SOD 开盘快照标记）；ob数据中side只有两类ask（卖盘）、bid（买盘）,其中卖盘 ask：13,721,298 条，买盘 bid：13,477,725 条，买卖盘数据量基本均衡。