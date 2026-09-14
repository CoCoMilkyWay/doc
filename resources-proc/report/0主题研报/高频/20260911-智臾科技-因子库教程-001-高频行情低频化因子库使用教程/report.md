知乎

![](images/bc278ebf2c45765e890b8c68e9d2a1f70ebab0dfce118872da14ba0fba0de7df.webp)

BolphinDB

DolphinDB已认证机构号

关注

7 人赞同了该文章

目前，在量化投资研究领域，因子挖掘与应用正不断向更高频、更精细的数据层级深入。经典的因子库，如 国泰君安 191 Alpha 因子库 和 WorldQuant 101 Alpha 因子指标库，为基于日频、分钟频等中低频行情数据的策略开发提供了坚实基础。然而，这类低频因子在捕捉瞬息万变的市场微观结构信息、挖掘更具时效性和差异化的交易信号方面存在天然的局限。

随着行情数据粒度的不断细化，海量的分钟级、快照级乃至逐笔数据蕴含着更丰富的价格形成、订单流动与市场参与者行为信息。直接从这些高频数据中高效、稳定地提炼出可靠的Alpha信号 ，并将其“降维”应用于频率相对较低（如日度、小时级）的策略研究与组合管理中，已成为业界的重要发展方向。高频数据低频化过程的核心业务价值在于：使得策略开发者能够将微观、瞬时的市场状态（如资金流向、订单簿失衡、交易冲击等）转化为具有稳定预测能力的低频特征或因子，从而在更低频的交易周期中，提前洞察机会、优化风险控制，构建具备信息优势的差异化策略。

为满足这一需求，本教程提供了一套基于DolphinDB 高性能时序数据库和分析引擎原生构建的、面向分钟级乃至 tick级金融数据的专业因子计算解决方案。其核心在于，将公开研报和文献中经过验证的100余个中低频日频因子，结合DolphinDB的卓越数据处理能力，高效地适配并应用于分钟K线、Level-2行情 快照、逐笔委托和逐笔成交等高频数据源上。

注意：本教程包含的所有代码兼容 DolphinDB 2.00.12，3.00.2 及以上版本。

## 1. 高频行情低频化因子库简介

高频行情数据通常指时间粒度介于日频与超高频（如毫秒级）之间的数据，主要包括分钟K线、快照行情、逐笔成交与委托等类型。这些数据实时记录了市场最细微的价格变动、订单

流动与交易行为，是捕捉市场微观结

赞同7

## 库，涵高频行情低频化因子库使用教程

于，提供了一套经过完整工程实现、性能优化与初步验证的标准化因子计算流程，用户可直接基于自 己的高频数据运行，快速获得可用于低频策略研究的、具有更高信息密度的因子序列。

本因子库完全基于DolphinDB 高性能时序数据库原生构建。DolphinDB集成了分布式计算、实时流处理与高效存储引擎，其内置的多范式编程语言与丰富的金融分析函数，能够轻松应对高频数据处理的巨大吞吐与计算复杂度挑战，实现从TB级高频数据到日频因子的秒级生成。本文提供了完整的计算脚本与性能基准，帮助用户快速验证、迭代与部署自 己的低频化因子。具体的因子列表与计算脚本请见第7章。

## 2.数据集与入参规范

本文的中高频因子库基于行情数据集：分钟K线数据、快照数据、逐笔成交和逐笔委托数据。本节提供了相关数据集的部分字段和存储方案，具体的建库建表方案及相关代码请参考存储金融数据的分区方案最佳实践

| 数据集 | 简称 | 代码样例中的分区数据库路径 | 代码样例中的表名 | 分区方案 |
| --- | --- | --- | --- | --- |
| 分钟K线 | stockMinKSH | dfs://stockMinKSH | stockMinKSH | 按天分区 |
| 快照行情 | snapshot | dfs://Level2 | snapshot | 按天分区+按股票代码 HASH50分区 |
| 逐笔委托 | entrust | dfs://Level2 | entrust | 按天分区+按股票代码 HASH50分区 |
| 逐笔成交 | trade | dfs://Level2 | trade | 按天分区+按股票代码 HASH50分区 |

## 2.1分钟K线数据

分钟K线数据是指每分钟的市场行情走势，由逐笔成交数据聚合产生，通常用于短线交易者分析日内价格波动。本教程中分钟K线数据采用“时间维度按天”的分区规则，使用 OLAP存储引擎，每个分区内都包含了当天所有股票的分钟K线数据。其中，涉及到因子计算的重要字段有

|  | 字段名称 | 数据类型 | 数据说明 |
| --- | --- | --- | --- |
| 1 | SecuritylD | SYMBOL | 股票代码 |
| 2 | DateTime | TIMESTAMP | 交易时间 |
| 3 | OpenPrice | DOUBLE | 开盘价 |
| 4 | HighPrice | DOUBLE | 最高价 |
| 5 | LowPrice | DOUBLE | 最低价 |
| 6 | LastPrice | DOUBLE | 收盘价 |
| 7 | Volume | LONG | 成交量 |
| 8 | Amount | DOUBLE | 成交额 |

股票Level-2行情数据包含Level-2快照数据、逐笔委托数据、逐笔成交数据。在分布式数据库中，对跨分区数据表进行连接操作往往十分耗时，因为涉及到的分区可能位于不同的节点上，需要在不同节点之间复制数据。为解决这个问题，DolphinDB推出了共存储位置（co-location）的分区机制，使同一分布式数据库中、分区方案一致的多个表，其相同分区的数据能够存放在同一节点上，从而显著提升表连接效率。因此在本教程中，把Level-2快照数据、逐笔委托数据、逐笔成交数据这些分区方案一致的数据表存入同一个数据库中“时间维度按天+股票维度HASH50”的分区规则，使用 TSDB存储引擎 。

## 2.2.1 Level-2 行情快照数据

Level-2行情快照数据是对逐笔行情数据的某一个时刻的，通常以3秒为周期更新，包含多档买卖盘等关键信息。其中，涉及到因子计算的重要字段有：

|  | 字段名称 | 数据类型 | 数据说明 |
| --- | --- | --- | --- |
| 1 | SecurityID | SYMBOL | 证券代码 |
| 2 | TradeTime | TIMESTAMP | 数据生成时间 |
| 3 | PreCloPrice | DOUBLE | 昨日收盘价 |
| 4 | NumTrades | INT | 成交笔数 |
| 5 | TotalVolumeTrade | INT | 成交总量 |
| 6 | TotalValueTrade | DOUBLE | 成交总金额 |
| 7 | LastPrice | DOUBLE | 最近价 |
| 8 | OpenPrice | DOUBLE | 开盘价 |
| 9 | HighPrice | DOUBLE | 最高价 |
| 10 | LowPrice | DOUBLE | 最低价 |
| 11 | ClosePrice | DOUBLE | 今日收盘价 |
| 12 | TotalBidQty | INT | 委托买入总量 |
| 13 | TotalOfferQty | INT | 委托卖出总量 |
| 14 | OfferPrice | DOUBLE VECTOR | 卖价10档 |
| 15 | BidPrice | DOUBLE VECTOR | 买价 10档 |
| 16 | OfferOrderQty | INT VECTOR | 卖量10档 |
| 17 | BidOrderQty | INT VECTOR | 买量 10档 |
| 18 | Market | SYMBOL | 交易所名称 |

## 2.2.2 Level-2 逐笔委托数据

Level-2逐笔委托数据记录了市场中每一笔委托行为，包括新委托的提交、现有委托的撤销以及委托价格或数量的修改。其中，涉及到因子计算的重要字段有：

|  | 字段名称 | 数据类型 | 数据说明 |
| --- | --- | --- | --- |
| 1 | SecuritylD | SYMBOL | 证券代码 |
| 2 | TradeTime | TIMESTAMP | 报价时间 |
| 3 | Price | DOUBLE | 委托价格 |
| 4 | OrderQty | INT | 委托数量 |
| 5 | Side | SYMBOL | 买卖方向 |
| 6 | Market | SYMROI | 交县所名称 |

Level-2逐笔成交数据是交易所公布的买卖双方具体成交的每一笔数据，每3秒发布一次，每次包含这3秒内的所有成交记录。每一笔成交撮合都由买方和卖方的一笔具体委托组成，是交易过程的真实成交情况。其中，涉及到因子计算的重要字段有：

|  | 字段名称 | 数据类型 | 数据说明 |
| --- | --- | --- | --- |
| 1 | SecuritylD | SYMBOL | 证券代码 |
| 2 | TradeTime | TIMESTAMP | 成交时间 |
| 3 | BidApplSeqNum | LONG | 买方委托索引 |
| 4 | OfferApplSeqNum | LONG | 卖方委托索引 |
| 5 | TradPrice | DOUBLE | 委托价格 |
| 6 | TradeQty | DOUBLE | 委托数量 |
| 7 | TradeMoney | DOUBLE | 成交金额 |
| 8 | Market | SYMBOL | 交易所名称 |

## 3. 因子存储

因子挖掘是量化交易的必备环节之一，随着量化交易和AI模型训练规模的发展，量化投资团队在投研环节势必需要处理大量因子数据。因子的存储也是一个关键问题，目前DolphinDB支持宽表和窄表两种存储模式。相较于宽表，窄表存储支持更加高效地添加、更新、删除因子等操作，推荐使用窄表存储因子库。

## 3.1建立因子库

针对日频因子库，经过各项测试后（测试见 中高频多因子库存储最佳实践，推荐采用“时间维度按年+因子名”的组合分区方式存储，使用 TSDB存储引擎，以作为排序列。更多金融数据与因子库分区方案见 存储金融数据的分区方案最佳实践具体脚本如下：

```sql
// 创建日频因子库
create database "dfs://factor_day"
partitioned by RANGE(date(datetimeAdd(1980.01M,0..80*12,'M'))), VALUE(`f1`f
engine='TSDB',
atomic='CHUNK'
// 创建分区表
create table "dfs://factor_day"."factor_day"(
SecurityID SYMBOL,
TradeDate DATE[comment="时间列", compress="delta"],
Value DOUBLE,
FactorName SYMBOL,
UpdateTime TIMESTAMP,
)
partitioned by TradeDate, FactorName
sortColumns=[`SecurityID, `TradeDate],
keepDuplicates=ALL, //保留所有写入的因子值
sortKeyMappingFunction=[hashBucket{, 500}]
```

## 3.2处理计算结果并入库

表方式存储因子，因此可将计算结果直接入库，其代码如下：

//读取数据库并将结果入库

loadTable("dfs://factor_day","factor_day").append!(select * from res)

## 4.因子计算流程

本章将完整地介绍如何调取数据进行因子计算并将计算结果存储入库。考虑到部分因子具有特殊的数据需求或计算方式，其实现方式与其他因子有所区别，相关内容将在4.2 小节单独介绍。

## 4.1因子通用计算流程

本因子库内所有dos脚本均由三部分构成：因子计算函数，后台任务提交函数以及因子计算样例。用户正确配置参数并直接运行脚本即可实现因子的计算与入库。接下来将分别介绍每一部分的具体内容及使用方法。

## 4.1.1因子计算函数

本小节定义了因子计算函数。这些函数均以因子计算依赖的基础数据表作为唯一入参，并返回一个表。输出表包含五列：SecurityID（证券代码）、TradeDate（数据日期）、Value（因子值）、FactorName（因子名）以及UpdateTime（更新日期），其中每一行对应单只股票在单个交易日的因子值。

以成交量占比偏度因子 为例，其因子计算函数如下：

def skewVolProp(snapshot){ 
snap = 
select 
TradeDate, TradeTime, SecurityID, 
deltas(TotalVolumeTrade)\last(TotalVolumeTrade) as volProp 
from snapshot 
context by TradeDate, SecurityID csort TradeTime 
having TradeTime >= 09:30:00.000 
//日内tick成交量除以总成交量序列的偏度 
res = 
select 
SecurityID, 
TradeDate, 
skew(volProp) as Value, 
"skewVolProp" as FactorName, 
now() as UpdateTime 
from snap 
group by TradeDate, SecurityID 
return res 
}

## 4.1.2 后台任务提交函数

因子计算通常涉及较长时间跨度的数据，处理耗时较长，因此更适合将任务提交至服务器后台执行。本节介绍的函数旨在将因子

旧口エカ文双时六六口四」开基举口芯丁兴，共兵体谷如十。

|  | 配置项 | 配置内容 | 类型 |
| --- | --- | --- | --- |
| 1 | func | 计算因子的函数名 | FUNCTION |
| 2 | funcsec | 调整因子的函数名 | FUNCTION |
| 3 | factorName | 因子名 | SYMBOL |
| 4 | dataDB | 计算所需数据的数据库 | STRING |
| 5 | dataTB | 计算所需数据的数据表 | STRING |
| 6 | factorDB | 存储因子的数据库 | STRING |
| 7 | factorTB | 存储因子的数据表 | STRING |
| 8 | startDay | 计算因子的起始日期 | DATE |
| 9 | endDay | 计算因子的结束日期 | DATE |

该函数首先根据dataDB库中dataTB表的分区信息，生成一个由多条SQL元代码构成的向量ds。每条SQL会查询startDay到endDay期间每日给定时段的数据，这些数据将作为并行计算任务的数据源。随后，函数通过mr函数并行调用因子计算函数func进行处理，并使用 unionAll函数合并所有分区的计算结果。最终，函数将结果按factorDB库中factorTB表所需的格式进行整理后将数据存入目标因子库。

以成交量占比偏度因子为例，其后台任务提交函数如下：

```rust
def factorJob(conf){
dataTB = loadTable(conf[`dataDB], conf[`dataTB])
days = conf[`startDay]..conf[`endDay]
startTime = 09:27:00.000
endTime = 14:57:00.000
//提取计算所需数据，sqlDS生成元代码
ds = sqlDS(<select SecurityID, TradeDate, TradeTime, TotalVolumeTrade
from dataTB
where TradeDate in days and (TradeTime between startTime and endTim
//计算因子，mr函数将因子在不同节点并行计算，unionAll函数将不同节点的计算结果汇总
res = mr(ds, conf[`func]).unionAll()
//写入因子库，存储到磁盘做持久化
loadTable(conf[`factorDB], conf[`factorTB]).append!(select * from res)
}
```

## 4.1.3 计算样例

本小节将提供参数配置和提交后台任务的一个样例。首先，基于4.1.2 小节中的入参字典配置参数 conf，其次使用 submitJob函数将任务函数提交到服务器后台执行。

以成交量占比偏度因子为例，其计算样例如下：

```javascript
// 配置计算因子的参数
// conf = {
//func : 计算因子的函数名
//funcsec : 计算再调整因子
```

## //ataDB : 计算所需数据的数据库高频行情低频化因子库使用教程

```javascript
//factorDB : 存储因子的数据库
//factorTB : 存储因子的数据表
//startDay : 计算因子的起始 日 期
//endDay : 计算因子的结束 日 期
// }
conf = {
func : skewVolProp,
funcsec : NULL,
factorName : `skewVolProp,
dataDB : "dfs://Level2",
dataTB : "snapshot",
factorDB : "dfs://factor_day",
factorTB : `factor_day,
startDay : 2023.02.01,
endDay : 2023.02.28
}
//提交计算和存储因子的任务到服务器并返回任务 id
id = submitJob("factor_job", conf[`factorName], factorjob, conf)
```

在该例子中，计算的因子名为skewVolProp，计算因子的函数为 skewVolProp 计算所需的2023 年 2 月 的通联 Level-2 行情快照数据存储于数据库 dfs://Level2 下的 snapshot 表中计算的时间区间为2023年2 月 1 日到2023年2 月 28 日计算得到的因子将存储在数据库dfs://factor_day 下的表 factor_day 中。因为该因子不涉及调整因子的函数，因此配置项为 NULL 。

配置完成后， submitJob 函数将任务提交到后台服务器，提交的任务名为factor_jo，任务描述为因子名 skewVolProp，执行的函数为 4.1.2 小节中的 factorJob 函数，入参为。执行 submitJob 函数后等待后台完成计算任务即可完成因子计算到入库的全流程。

## 4.2特殊因子实现方式

部分因子实现方式与其他因子有所区别，因此这一小节将单独介绍这些因子的计算和使用方式。

## 4.2.1需要额外数据集的因子

部分因子的计算涉及基础数据表与其它数据库表（如历史数据或市场指数数据）。在分布式计算框架下，由于数据按时间和标的分区并行处理，某些因子（如依赖历史窗口的因子或其他市场指数）无法仅从当前传入的数据块中获取全部所需信息。

为解决此问题，本因子库允许在计算函数内部直接读取数据库。对于需要额外数据的因子，其计算函数内已预设了读取逻辑。因此，用户在使用这些因子前，需根据实际环境，在相应的因子计算函数中修改所依赖数据的数据库路径参数。

本因子库中包含的该类因子如下：

|  | 因子名 | 涉及的额外数据集 |
| --- | --- | --- |
| 1 | 日度惊恐因子 | Level-2 行情快照数据 |
| 2 | 日内主买占比因子 | Level-2 行情快照数据开 |
| 3 |  |  |

| 6 | 开盘后买入意愿强度 | Level-2 逐笔成交数据 |
| --- | --- | --- |
| 7 | 开盘后买入意愿占比 | Level-2 逐笔成交数据 |

以开盘后买入意愿强度因子 为例，其计算函数如下：

def netBuyIntenOpen(entrustTB){ 
//净委买增额：1分钟委托买单增加量减去委托卖单变化量（逐笔委托） 
tmp1 = 
select 
sum(OrderMoney*iif(Side==`B or Side==`1, 1.0, 0.0)) - sum(Order 
from entrustTB 
group by TradeDate, SecurityID, interval(X=TradeTime, duration=60s, 
//净主买成交额：1分钟主动买入成交额减去主动卖出成交额（逐笔成交） 
//根据逐笔委托当天的标的去逐笔成交表查询计算依赖的行情数据 
calDate = first(entrustTB[`TradeDate]) 
codes = exec distinct SecurityID from entrustTB 
tradeTB = 
select SecurityID, TradeDate, TradeTime, TradePrice*TradeQty as Tra 
from loadTable("dfs://Level2", "trade") 
where TradeDate=calDate, SecurityID in codes and TradeTime between 
tmp2 = 
select 
sum(TradeMoney*iif(BSFlag==`B, 1.0, 0.0))- sum(TradeMoney*iif(B 
sum(TradeMoney) as tradeTotal 
from tradeTB 
group by TradeDate, SecurityID, interval(X=TradeTime, duration=60s, 
//开盘后买入意愿强度：开盘后时间段（09:30-10:00）内1分钟买入意愿序列的均值除以标准 
tmp3 = 
select 
mean(tradeNetBuy+enrustNetBuy)\stdp(tradeNetBuy+enrustNetBuy) a 
from lj(tmp1, tmp2, `TradeDate`SecurityID`TradeTime) 
where tradeNetBuy!=NULL 
group by TradeDate, SecurityID 
//因子 
res = 
select 
SecurityID, 
TradeDate, 
Value, 
"netBuyIntenOpen" as FactorName, 
now() as UpdateTime 
from tmp3 
return res 
} 
A

注：该类因子的后台任务提交函数与计算样例部分与通用模板一致，遵循通用模板的流程即可计算因子并入库。

## 4.2.2基于日频因子的再调整因子

部分因子需在已生成的日频因子上进行二次修正，无法一次性计算得出。对此，本小节采用两步计算策略：先运行日频因子计算函数，再将其结果传入修正函数进行二次处理。因此这类因子的实现方式与其他因子不同

## 修正。高频行情低频化因子库使用教程

算，而非分布式计算。

本因子库中包含的该类因子主要：

| 因子名 | 测试数据集 |
| --- | --- |
| 修正日模糊价差因子 | 分钟K线数据 |

以修正日模糊价差因子为例，其计算因子的函数如下：

77首定文因子计算函数//自定义因子计算函数

def fuzzinessDiff(minKTB){ 
/**@test 少量数据临时调试 
minKTB = 
select SecurityID, date(DateTime) as TradeDate, time(DateTime) as T 
from loadTable("dfs://stockMinKSH", "stockMinKSH") 
where date(DateTime) between 2021.01.04 and 2021.01.31, SecurityID 
*/ 
//计算模糊性 
fuzziness = 
select 
SecurityID, 
TradeDate, 
TradeTime, 
Volume, 
Amount, 
mstd(mstd(percentChange(LastPx), 5, 5), 5, 5) as fuzziness 
from minKTB 
context by SecurityID, TradeDate 
//计算每日起雾时刻模糊性阈值及成交量均值、成交金额均值 
threshold = 
select 
SecurityID, 
TradeDate, 
avg(Volume) as avgVolume, 
avg(Amount) as avgAmount, 
avg(fuzziness) as thresholdFuzzy 
from fuzziness 
group by SecurityID, TradeDate 
//日模糊价差=日模糊金额比-日模糊数量比 
res = 
select 
SecurityID, 
TradeDate, 
avg(Volume)\first(avgVolume)-avg(Amount)\first(avgAmount) as Va 
"fuzzinessDiff" as factorName, 
now() as updateTime 
from lj(fuzziness, threshold, `SecurityID`TradeDate) 
where fuzziness > thresholdFuzzy 
group by SecurityID, TradeDate 
return res 
} 
def adjFuzzinessDiff(diffTB){ 
/**@test 
diffTB = select * from r 
/zhuanlan.zhihu.com/p/2012221540524111249

## 知乎正日模糊价差：将横截面上值为负高频行情低频化因子库使用教程

select 
TradeDate, 
sum(Value) as s1 
from diffTB 
where Value<0 
group by TradeDate 
adjDiff = 
select 
SecurityID, 
TradeDate, 
iif(Value<0, Value\mstd(Value, 10), Value) as adjFuzzDiff 
from diffTB 
context by SecurityID 
//调整数量级：将横截面上值为负的修正日模糊价差求和，记为 s2；将值为负的修正日模糊 
s2 = 
select 
TradeDate, 
sum(adjFuzzDiff) as s2 
from adjDiff 
where adjFuzzDiff<0 
group by TradeDate 
s = 
select 
TradeDate, 
s1\s2 as s 
from ej(s1, s2, `TradeDate) 
res = 
select 
SecurityID, 
TradeDate, 
iif(adjFuzzDiff<0, adjFuzzDiff*s, adjFuzzDiff) as Value, 
"adjFuzzinessDiff" as FactorName, 
now() as UpdateTime 
from lj(adjDiff, s, `TradeDate) 
context by SecurityID, TradeDate 
return res

由于该类因子在计算时需要调用两个函数，其任务函数也有所区别。修正模糊价差因子的任务函数如下：

//后台任务计算函数模版 
def factorjob(conf){ 
dataTB = loadTable(conf[`dataDB], conf[`dataTB]) 
days = conf[`startDay]..conf[`endDay] 
startTime = 09:30:00.000 
endTime = 14:57:00.000 
//提取计算所需数据，sqlDS生成元代码 
ds = sqlDS(<select SecurityID, date(DateTime) as TradeDate, time(DateTi 
from dataTB 
where date(DateTime) in days and (time(DateTime) between startTime 
//计算因子，mr函数将因子在不同节点并行计算，unionAll函数将不同节点的计算结果汇总 
diffTB = mr(ds, conf[`fu 
res = conf[`funcsec](dif

与通用流程的区别在于，此类计算需配置funcsec参数以实现两步计算：先分布式执行 func函数生成日频因子，再通过funcsec函数进行修正。配置时，需将修正函数赋值给conf的funcsec。其计算样例如下：

```javascript
//计算模版配置参数
conf = {
func : fuzzinessDiff,
funcsec : adjFuzzinessDiff,
factorName : "fuzzinessDiff",
dataDB : "dfs://stockMinKSH",
dataTB : "stockMinKSH",
factorDB : "dfs://factor_day",
factorTB : "factor_day",
startDay : 2021.01.01,
endDay : 2021.01.31
}
//提交计算和存储因子的任务到服务器
id = submitJob("factorjob", conf[`factorname], factorjob, conf)
```

## 4.3批量计算因子

本因子库支持批量计算因子。所有脚本开箱即用，只需将参数配置完成的脚本上传至DolphinDB服务器，并通过循环执行即可实现批量计算与入库。

以基于逐笔成交的 日 频因子为例，将所需脚本上传至 /ssd/ssd0/singleDDB/server/高频因子库/基于逐笔成交的日频因子 文件目录下，执行以下代码即可批量计算：

//登录服务器.
login("xxxxxx","xxxxxxxx");
go
//脚本所在目录
scriptdir = "/ssd/ssd0/singleDDB/server/高频因子库/基于逐笔成交的 日 频因子"
//获取脚本所在目录下的脚本名称
scriptFiles = files(scriptdir)
//批量运行脚本
for(script in scriptFiles){
run(scriptdir+"/"+script[`filename], newSession = true, clean = true)
print("已运行脚本："+script[`filename])
}

用户实际使用时可自行设置脚本所在目录和是否打印运行信息。

## 4.4 因子更新

本因子库的因子在入库时默认追加至尾部，如用户需要更新已计算的因子值，可以通过在建立存储因子的数据库的时候调整配置码复用性，在建库之前将删除已存在https://zhuanlan.zhihu.com/p/2012221540524111249

//删高频行情低频化因子库使用教程

```sql
// 创建日频因子库
create database "dfs://factor_day"
partitioned by RANGE(date(datetimeAdd(1980.01M,0..80*12,'M'))), VALUE(`f1`f
engine='TSDB',
atomic='CHUNK'
// 创建分区表
create table "dfs://factor_day"."factor_day"(
SecurityID SYMBOL,
TradeDate DATE[comment="时间列", compress="delta"],
Value DOUBLE,
FactorName SYMBOL,
UpdateTime TIMESTAMP,
)
partitioned by TradeDate, FactorName
sortColumns=[`SecurityID, `TradeDate],
keepDuplicates=LAST, //支持重复写入，保留最新写入的因子值
sortKeyMappingFunction=[hashBucket{, 500}]
```

创建数据表时 keepDuplicates参数设置为 LAST 时，将依据 sortColumns中的数据列保留最新入库的数据。此外，因子表中的 UpdateTime列可用于记录当前数据入库时间。

## 5.计算性能

## 5.1测试环境与数据集

## 5.1.1 测试环境

测试使用的 DolphinDB server 版本为 2.00.16 ，硬件配置如下：

| OS（操作系统） | CentOS Linux 7 (Core) |
| --- | --- |
| 内核 | 3.10.0-1160.el7.x86_64 |
| CPU | Intel(R) Xeon(R) Gold 5220R CPU @2.20GHz 16 逻辑 CPU 核心 |
| 内存 | 8*32GB RDUNN, 3200MT/s 总共 256 GB |
| 磁盘 | 固态硬盘(SSD)6*3.84TB 固态硬盘 SATA 读取密集型 6Gbps 512 2.5 英寸 Flex Bay AG 硬盘，1DWPD单盘测试随机写平均写入IO：430MB/s单盘测试混合随机读写平均写入IO：73MB/s平均读取IO：443MB/s |
| 网络 | 9.41Gbps（万兆以太网） |

## 5.1.2 测试数据集

计算各因子依赖的的数据集及其数据量展示：

| 因子类型 | 测试数坦售 | 粉据量(冬) |
| --- | --- | --- |

## 基于行照的因子高频行情低频化因子库使用教程

| 基干逐笔委托数据的因子 | 2023年2月沪深逐笔委托数据 | 2,712,071,019 |
| --- | --- | --- |
| 基于逐笔成交数据的因子 | 2023年2月沪深逐笔成交数据 | 2,067,012,875 |
| 基于分钟K线的因子 | 2021年1月K线数据 | 38,594,699 |

## 5.2 测试结果

所有因子测试数据及耗时情况如下：

|  | 因子名 | 测试数据 | 计算耗时 (s) |
| --- | --- | --- | --- |
| 1 | 最短路径非流动性因子 | 2021年1月K线数据 | 0.29 |
| 2 | 一致买入交易因子 | 2021年1月K线数据 | 0.25 |
| 3 | 绝对收益与调整后滞后成交量相关性因子 | 2021年1月K线数据 | 78.75 |
| 4 | 成交量“潮汐”的价格变动速率因子 | 2021年1月K线数据 | 0.48 |
| 5 | 跌幅时间重心偏离因子 | 2021年1月K线数据 | 77.94 |
| 6 | 一致交易因子 | 2021年1月K线数据 | 0.33 |
| 7 | 成交额占比熵因子 | 2021年1月K线数据 | 0.23 |
| 8 | 日内持续异常交易量因子 | 2021年1月K线数据 | 0.56 |
| 9 | 日耀眼波动率因子 | 2021年1月K线数据 | 0.35 |
| 10 | 日午蔽古木因子 | 2021年1月K线数据 | 1.52 |
| 11 | 单一成交额占比熵因子 | 2021年1月K线数据 | 0.27 |
| 12 | 日度灾后重建因子 | 2021年1月K线数据 | 1.01 |
| 13 | 滞后绝对收益与调整后成交量相关性因子 | 2021年1月K线数据 | 78.53 |
| 14 | 日耀眼收益率因子 | 2021年1月K线数据 | 0.27 |
| 15 | 日度勇攀高峰因子 | 2021年1月K线数据 | 1.04 |
| 16 | 绝对收益与成交量相关性因子 | 2021年1月K线数据 | 0.41 |
| 17 | 绝对收益与滞后成交量相关性因子 | 2021年1月K线数据 | 0.18 |
| 18 | 滞后绝对收益与成六 2021年1日K线数量相关性因 |  |  |

19日朝没晨雾因子高频行情低频化因子库使用教程

| 20 | T分布主动占比因子 | 2021年1月K线数据 | 0.61 |
| --- | --- | --- | --- |
| 21 | 置信正态分布主动占比因子 | 2021年1月K线数据 | 0.30 |
| 22 | 朴素主动占比因子 | 2021年1月K线数据 | 0.63 |
| 23 | T分布主动占比因子 | 2021年1月K线数据 | 0.21 |
| 24 | 成交量波峰计数因子 | 2021年1月K线数据 | 0.22 |
| 25 | 日模糊金额比因子 | 2021年1月K线数据 | 0.36 |
| 26 | 日模糊数量比因子 | 2021年1月K线数据 | 0.38 |
| 27 | P型成交量分布因子 | 2021年1月K线数据 | 0.42 |
| 28 | B 型成交量分布因子 | 2021年1月K线数据 | 0.44 |
| 29 | 修正日模糊价差因子 | 2021年1月K线数据 | 日模糊价差因子：0.38；修正版：0.41 |
| 30 | 成交量支撑区域下限与收盘价差异因子 | 2021年1月K线数据 | 0.43 |
| 31 | 模糊关联度因子 | 2021年1月K线数据 | 0.32 |
| 32 | 时间加权平均的股票相对价格位置因子 | 2023年2月通联Level-2 快照数据 | 7.96 |
| 33 | 高频上行波动占比因子 | 2023年2月通联Level-2 快照数据 | 5.94 |
| 34 | 高频下行波动占比因子 | 2023年2月通联Level-2 快照数据 | 5.94 |
| 35 | 已实现波动率因子 | 2023年2月通联Level-2 快照数据 | 5.78 |
| 36 | 上行已实现波动率因子 | 2023年2月通联Level-2 快照数据 | 5.20 |
| 37 | 下行已实现波动率因子 | 2023年2月通联Level-2 快照数据 | 5.05 |
| 38 | 高频已实现偏度因子 | 2023年2月通联Level-2 快照数据 | 5.27 |
| 39 | 高频已实现峰度因子 | 2023年2月通联Level-2 快照数据 | 4.93 |
| 40 | 上下行波动率不对称性因子 | 2023年2月通联Level-2 快照数据 | 6.98 |
| 41 | 中间价变化率偏度因子 | 2023年2月通联Level-2 快照数据 | 30.27 |
| 42 | 中间价变化率最大值因子 | 2023年2月通联Level-2 快照数据 | 31.44 |

高频行情低频化因子库使用教程

| 44 | 大成交量价量相关性因子 | 2023年2月通联Level-2 快照数据 | 7.35 |
| --- | --- | --- | --- |
| 45 | 已实现双幂次变差因子 | 2023年2月通联Level-2 快照数据 | 5.85 |
| 46 | 已实现三幂次变差因子 | 2023年2月通联Level-2 快照数据 | 6.16 |
| 47 | 日度惊恐因子 | 2023年2月通联Level-2 快照数据 | 4.01 |
| 48 | 成交量分桶熵因子 | 2023年2月通联Level-2 快照数据 | 5.68 |
| 49 | 已实现跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 6.72 |
| 50 | 交易量变异系数因子 | 2023年2月通联Level-2 快照数据 | 5.76 |
| 51 | 上行已实现跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 6.34 |
| 52 | 下行已实现跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 6.69 |
| 53 | 聪明钱因子 | 2023年2月通联Level-2 快照数据 | 7.51 |
| 54 | 成交量占比偏度因子 | 2023年2月通联Level-2 快照数据 | 5.24 |
| 55 | 成交量占比峰度因子 | 2023年2月通联Level-2 快照数据 | 5.26 |
| 56 | 日度主力交易情绪因子 | 2023年2月通联Level-2 快照数据 | 8.34 |
| 57 | 趋势占比因子 | 2023年2月通联Level-2 快照数据 | 6.69 |
| 58 | 上下行跳跃波动的不对称性因子 | 2023年2月通联Level-2 快照数据 | 6.80 |
| 59 | 最大涨幅因子 | 2023年2月通联Level-2 快照数据 | 5.44 |
| 60 | 大单资金净流入率因子 | 2023年2月通联Level-2 快照数据 | 8.35 |
| 61 | 大单驱动涨幅因子 | 2023年2月通联Level-2 快照数据 | 7.84 |
| 62 | 每单成交量筛选的局部反转因子 | 2023年2月通联Level-2 快照数据 | 8.63 |
| 63 | 平均单笔流出金额占比因子 | 2023年2月通联Level-2 快照数据 | 8.03 |
| 64 | 大的上行跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 8.03 |
| 65 | 大的下行跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 8.22 |
| 66 | 小的上行跳跃波动率因子 | 2023年2月通联Level-2 快照数据 | 8.13 |

高频行情低频化因子库使用教程

| 68 | 日内条件在险价值因子 | 2023年2月通联Level-2 快照数据 | 8.73 |
| --- | --- | --- | --- |
| 69 | 隔夜收益率因子 | 2023年2月通联Level-2 快照数据 | 5.18 |
| 70 | 日内最大回撤因子 | 2023年2月通联Level-2 快照数据 | 5.09 |
| 71 | 日内成交量占比标准差因子 | 2023年2月通联Level-2 快照数据 | 5.26 |
| 72 | 每笔成交量收益率相关性因子 | 2023年2月通联Level-2 快照数据 | 8.33 |
| 73 | 日内收益率因子 | 2023年2月通联Level-2 快照数据 | 5.04 |
| 74 | 分钟成交额方差因子 | 2023年2月通联Level-2 快照数据 | 5.39 |
| 75 | 尾盘半小时收益率因子 | 2023年2月通联Level-2 快照数据 | 2.03 |
| 76 | 日度盘口价差因子 | 2023年2月通联Level-2 快照数据 | 30.64 |
| 77 | 尾盘半小时成交额占比因子 | 2023年2月通联Level-2 快照数据 | 2.04 |
| 78 | 大的上下行跳跃波动不对称性因子 | 2023年2月通联Level-2 快照数据 | 9.44 |
| 79 | 小的上下行跳跃波动不对称性因子 | 2023年2月通联Level-2 快照数据 | 10.33 |
| 80 | 日度价格弹性因子 | 2023年2月通联Level-2 快照数据 | 7.31 |
| 81 | 日度盘口平均深度因子 | 2023年2月通联Level-2 快照数据 | 29.77 |
| 82 | 加权收盘价比因子 | 2023年2月通联Level-2 快照数据 | 6.32 |
| 83 | 结构化反转因子 | 2023年2月通联Level-2 快照数据 | 6.98 |
| 84 | 日度有效深度因子 | 2023年2月通联Level-2 快照数据 | 28.92 |
| 85 | 分钟成交额自相关性因子 | 2023年2月通联Level-2 快照数据 | 5.60 |
| 86 | 尾盘半小时成交量占比因子 | 2023年2月通联Level-2 快照数据 | 2.01 |
| 87 | 加权偏度因子 | 2023年2月通联Level-2 快照数据 | 8.94 |
| 88 | 交易量同步的知情交易概率因子 | 2023年2月通联Level-2 快照数据 | 8.52 |
| 89 | 开盘后买入意愿强度因子 | 2023年2月通联Level-2 逐笔委托 | 11.80 |
| 90 | 开盘后净委买增额占比因子 | 2023年2月通联Level-2 逐笔委托 | 3.56 |

91高频行情低频化因子库使用教程

| 92 | 卖出反弹偏离因子 | 2023年2月通联Level-2 逐笔成交 | 87.86 |
| --- | --- | --- | --- |
| 93 | 大单买入占比因子 | 2023年2月通联Level-2 逐笔成交 | 38.15 |
| 94 | 买单集中度因子 | 2023年2月通联Level-2 逐笔成交 | 32.47 |
| 95 | 卖单集中度因子 | 2023年2月通联Level-2 逐笔成交 | 31.79 |
| 96 | 开盘后大单净买入占比因子 | 2023年2月通联Level-2 逐笔成交 | 14.73 |
| 97 | 日内主买占比因子 | 2023年2月通联Level-2 逐笔成交 | 49.80 |
| 98 | 大单买入强度因子 | 2023年2月通联Level-2 逐笔成交 | 38.02 |
| 99 | 开盘后净主买占比因子 | 2023年2月通联Level-2 逐笔成交 | 17.61 |
| 100 | 日内主买强度因子 | 2023年2月通联Level-2 逐笔成交 | 38.02 |
| 101 | 开盘后净主买强度因子 | 2023年2月通联Level-2 逐笔成交 | 16.81 |
| 102 | 卖单非流动性因子 | 2023年2月通联Level-2 逐笔成交 | 29.79 |
| 103 | 买单非流动性因子 | 2023年2月通联Level-2 逐笔成交 | 29.64 |
| 104 | 卖出反弹占比因子 | 2023年2月通联Level-2 逐笔成交 | 34.94 |
| 105 | 剔除超大单后的普通大单买入占比因子 | 2023年2月通联Level-2 逐笔成交 | 35.77 |
| 106 | 超大单买入占比因子 | 2023年2月通联Level-2 逐笔成交 | 29.00 |
| 107 | 小买单主动成交度因子 | 2023年2月通联Level-2 逐笔成交 | 1,035.52 |
| 108 | 剔除超大单影响后的大单涨跌幅因子 | 2023年2月通联Level-2 逐笔成交 | 25.44 |
| 109 | 基于物理时间交易量加权的知情交易概率 | 2023年2月通联Level-2 逐笔成交 | 28.24 |
| 110 | 超大单涨跌幅因子 | 2023年2月通联Level-2 逐笔成交 | 19.43 |
| 111 | 买入浮亏占比因子 | 2023年2月通联Level-2 逐笔成交 | 33.64 |
| 112 | 买入浮亏偏离因子 | 2023年2月通联Level-2 逐笔成交 | 20.28 |
| 113 | 开盘后大单净买入强度因子 | 2023年2月通联Level-2 逐笔成交 | 14.06 |
| 114 | 大成交量委托单成交量占比因子 | 2023年2月通联Level-2 逐笔成交 | 34.27 |

## 6. 常见问题解答（FAQ）

## 6.1窄表存储的因子如何按照因子名转变为宽表形式？

本因子库推荐以窄表的形式存储因子。若实际业务场景需要宽表计算，用户可以使用 pivotby语句将因子窄表按照因子名转变为宽表形式，示例代码如下：

```python
dailyFactor = loadTable("dfs://factor_day","factor_day")
factorTB1 = select
Value
from dailyFactor
where FactorName in `skewVolProp`netBuyIntenOpen
pivot by SecurityID, TradeDate, FactorName
```

## 6.2如何把一个按照因子名展开的宽表处理成一个窄表？

若需要将宽表转化为窄表，可以使用 unpivot函数：

factorTB2 = 
select 
SecurityID, TradeDate, value as Value, valueType as FactorName 
from factorTB1.unpivot(`SecurityID`TradeDate, `skewVolProp`netBuyIntenOpe 
2

## 6.3如何将每个因子单独存储在独立的数据表中？

若用户需要将每个因子单独存储于同一个数据库下的不同表中，以成交量占比偏度因子为例，可将建库建表代码和任务函数调整为：

//删除已有数据库
if(existsDatabase("dfs://factor_day")) dropDatabase("dfs://factor_day")

//建立日频因子数据库 
create database "dfs://factor_day" 
partitioned by RANGE(date(datetimeAdd(1980.01M,0..80*12,'M'))), 
engine='TSDB', 
atomic='CHUNK'

//任务函数

def factorjob(conf){ 
dataTB = loadTable(conf[`dataDB], conf[`dataTB]) 
days = conf[`startDay]..conf[`endDay] 
startTime = 09:27:00.000 
endTime = 14:57:00.000 
//提取计算所需数据，sqlDS生成元代码 
ds = sqlDS(<select SecurityID, TradeDate, TradeTime, TotalVolumeTrade 
from dataTB 
where TradeDate in days and (TradeTime between startTime and endTim 
//计算因子，mr函数将因子在不 
res = mr(ds, conf[`func]

## 知乎database(conf[`factorDB]高频行情低频化因子库使用教程

if(existsTable(conf[`factorDB], tbName)){dropTable(db, tbName)} 
colNames = `SecurityID`TradeDate`Value`FactorName`UpdateTime 
colTypes = [SYMBOL, DATE, DOUBLE, SYMBOL, TIMESTAMP] 
t = table(1000:0, colNames, colTypes) 
pt = createPartitionedTable(dbHandle=db, 
table=t, 
tableName=tbName, 
partitionColumns=`TradeDate, 
sortColumns=`SecurityID`TradeDate,keepDupli 
sortKeyMappingFunction=[hashBucket{, 500}]) 
//写入因子库，存储到磁盘做持久化 
loadTable(conf[`factorDB], conf[`factorName]).append!(select * from res

请注意，这种存储因子的方式会导致一个数据库下有大量数据表，而每个表内仅有少量数据，不利于因子的查询与管理。因此，不建议采用此种存储方式。

## 6.4如何处理用户数据字段名与因子计算字段名不一致的问题？

如果用户在计算因子时使用的数据集字段名与本教程中所列字段名不同，则需要调整任务函数中构造分布式数据源的SQL代码以成交量占比偏度因子为例，示例如下：

```rust
def factorjob(conf){
dataTB = loadTable(conf[`dataDB], conf[`dataTB])
days = conf[`startDay]..conf[`endDay]
startTime = 09:27:00.000
endTime = 14:57:00.000
//提取计算所需数据，sqlDS生成元代码
//此处修改字段名
ds = sqlDS(<select ticker as SecurityID,
date(tradeTime) as TradeDate,
time(tradeTime) as TradeTime,
cumVolume as TotalVolumeTrade
from dataTB
where date(tradeTime) in days and (time(tradeTime) between startTim
//计算因子，mr函数将因子在不同节点并行计算，unionAll函数将不同节点的计算结果汇总
res = mr(ds, conf[`func]).unionAll()
//写入因子库，存储到磁盘做持久化
loadTable(conf[`factorDB], conf[`factorTB]).append!(select * from res)
}
```

注：如果计算的因子属于4.2.1 小节中列出的需要额外数据集的因子，请在计算函数中修改额外数据集中的字段。

## 6.5如何对计算得到的因子进行相关性分析？

DolphinDB 内置了多种相关性分析函数，如 corr 计算 Pearson 相关系数、spearmanr 计算Spearman相关系数等。本小节提供了

## // 计def f

con = ej(factor1, factor2, `SecurityID`TradeDate) 
if(method == `pearson){ 
return corr(con[`Value], con[`factor2_Value]) 
} 
if(method == `spearman){ 
return spearmanr(con[`Value], con[`factor2_Value]) 
} 
if(method == `kendall){ 
return kendall(con[`Value], con[`factor2_Value]) 
} 
} 
//相关性分析 
factorTB = loadTable("dfs://factor_day", `factor_day) 
factor1 = select * from factorTB where FactorName = `skewVolProp 
factor2 = select * from factorTB where FactorName = `netBuyIntenOpen 
result = factorCorr(factor1, factor2, `pearson)

该相关性计算函数可以计算两个因子之间的Pearson相关系数、Spearman相关系数和Kendall相关系数传入参数为两张因子表和需要计算的相关系数类型，输出为DOUBLE类型的相关系数。

## 7.因子与计算代码汇总

## 7.1 因子库代码

本因子库中所有因子脚本均整理在以下压缩包中，用户可根据自有数据库表进行修改使用。

中高频因子库因子脚本.zip

## 7.2 因子库因子列表

## 7.2.1基于分钟线的因子

|  | 因子名 | 因子计算逻辑和含义 | 参考文献 |
| --- | --- | --- | --- |
| 1 | 最短路径非流动性因子 | 股价变动最短路径：2*(high-low)-abs(close-open)最短路径非流动性因子：股价变动最短路径与成交额的比值之和 | 基于K线路径构造的非流动性因子，光大证券 |
| 2 | 一致买入交易因子 | 集体一致交易：分钟数据满足 abs(close-open)≤α*abs(high-low) 的 K线，其中 α为给定常数一致买入交易因子：在满足集 | 一致交易因子：挖掘集体行为背后的收益，光大证券 |

知乎高频行情低频化因子库使用教程

| 3 | 绝对收益与调整后滞后成交量相关性因子 | 调整后成交额：(amount-μ)/σ，其中μ，σ分别为前20个交易日相同时刻成交额的均值和标准差绝对收益：对数收益率的绝对值绝对收益与调整后滞后成交量相关性：绝对收益与前一时刻调整后成交额的相关系数 | 量价关系的高频乐章，方正证券 |
| --- | --- | --- | --- |
| 4 | 成交量“潮汐”的价格变动速率因子 | 领域成交量：日内第n 分钟及其前后 4 分钟的总成交量顶峰时刻：领域成交量最大值所在时刻涨潮时刻：顶峰时刻前领域成交量最低点所在时刻 m 退潮时刻：顶峰时刻后领域成交量最低点所在时刻n潮汐价格变动速率：涨潮时刻较退潮时刻的收盘价变动速率除以n-m | 个股成交量的潮汐变化及“潮汐”因子构建，方正证券 |
| 5 | 跌幅时间重心偏离因子 | 涨（跌）幅时间重心：上涨（下跌）时间依价格变动幅度的加权平均数跌幅时间重心偏离：在截面跌时间重心对涨时间重心进行回归，得到的残差均值 | 日内分钟收益率的时序特征：逻辑讨论与因子增强，开源证券 |
| 6 | 一致交易因子 | 集体一致交易：满足abs(close-open)≤α*abs(high-low)的 K线，其中 α为给定常数一致交易：一致交易K线的总成交量与当日总成交量的比值 | 一致交易因子：挖掘集体行为背后的收益，光大证券 |
| 7 | 成交额占比熵因子 | 每分钟成交额占当日总成交额的比值的熵 | 高位成交因子一从量价匹配说起，长江证券 |
| 8 | 日内持续异常交易量因子 | 异常交易量：当前分钟交易量与过去一段时间分钟交易量均值的比值（本因子库中为过去10个交易时刻）日内持续异常交易量： | “持续异常交易量”选股因子PATV，招商证券 |

知乎高频行情低频化因子库使用教程

|  |  | 易量的排名百分位 |  |
| --- | --- | --- | --- |
| 9 | 日耀眼波动率因子 | 成交量激增时刻：成交量增长量大于当日差值序列均值 +1 倍标准差的时刻耀眼波动率：成交量激增时刻及其随后四分钟区间内的1 分钟收益率标准差日耀眼波动率：交易日内所有耀眼波动率的均值 | 成交量激增时刻蕴含的alpha值息，方正证券 |
| 10 | 日午蔽古木因子 | 对每天第6分钟到第240 分钟的增量成交量数据进行带截距项的最小二乘回归：其中，volDiff为1分钟增量成交量。若回归方程的F值小于其横截面均值，午蔽古木因子为截距项t值的绝对值的负值，反之为截距项t值的绝对值。 | 推动个股价格变化的因素分解与“花隐林间”因子，方正证券 |
| 11 | 单一成交额占比熵因子 | 单一成交额占比熵计算公式为：其中，voli 和 closei 分别为每分钟成交量和每分钟收盘价，VOL 和CLOSE 分别为整个时间段总成交量和收盘价之和。 | 高位成交因子一从量价匹配说起，长江证券 |
| 12 | 日度灾后重建因子 | 更优波动率：对当前时刻及其前四分钟的高开低收的标准差与均值之比的平方收益波动比：收益率与更优波动率之比日度灾后重建因子：收益波动比与更优波动率的协方差 | 个股波动率的变动及“勇攀高峰”因子构建，方正证券 |
| 13 | 滞后绝对收益与调整后成交量相关性因子 | 调整后成交额：(amount-μ)/σ，其中μ，σ分别为前20个交易日相同时刻成交额的均值和标准差绝对收益：对数收益率的绝对值滞后绝对收益与调整后成交量相关性：前一时刻绝对收益与调整后成交 | 量价关系的高频乐章，方正证券 |

知乎高频行情低频化因子库使用教程

| 14 | 日耀眼收益率因子 | 差值序列均值+1倍标准差的时刻耀眼收益率：成交量激增时刻的分钟收益率日耀眼收益率：交易日内所有耀眼收益率的均值 | 成交量激增时刻蕴含的 alpha值息，方正证券 |
| --- | --- | --- | --- |
| 15 | 日度勇攀高峰因子 | 更优波动比：对当前时刻及其前四分钟的高开低收的标准差与均值之比的平方收益波动比：收益率与更优波动率之比波动率异常高时刻：更优波动率大于其日内均值+1 倍标准差的时刻日度勇攀高峰因子：当日波动率异常高时刻的收益波动比序列和更优波动率序列的协方差 | 个股波动率的变动及“勇攀高峰”因子构建，方正证券 |
| 16 | 绝对收益与成交量相关性因子 | 对数收益率：当前价格与前一时刻价格之比的对数绝对收益与成交量相关性：对数收益率的绝对值与成交额的相关系数 | 量价关系的高频乐章，方正证券 |
| 17 | 绝对收益与滞后成交量相关性因子 | 绝对收益与滞后成交量相关性：对数收益率的绝对值与前一时刻成交额的相关系数 | 量价关系的高频乐章，方正证券 |
| 18 | 滞后绝对收益与成交量相关性因子 | 前一时刻对数收益率的绝对值与成交额的相关系数 | 量价关系的高频乐章，方正证券 |
| 19 | 日朝没晨雾因子 | 对每天第6分钟到第240 分钟的增量成交量数据进行带截距项的最小二乘回归：其中，volDiff为1分钟增量成交量。日朝没晨雾因子：五阶增量成交量回归系数的t值的标准差 | 推动个股价格变化的因素分解与“花隐林间”因子，方正证券 |
| 20 | T分布主动占比因子 | T分布主动买入金额：amount*t(ret/σ,df)，其中σ为收益率标准差，df 为自由度T分布主动占比因子：T分布主动买入金额除以当日总成交额 | 分布估计下的主动成交占比，长江证券 |

知乎高频行情低频化因子库使用教程

| 21 | 置信正态分布主动占比因子 | amount"N(ret/0.11.96)，即每分钟成交额与对应分钟的标准正态分布累积函数的乘积置信正态分布主动占比因子：置信正态分布主动买入金额除以当日总成交额 | 分布估计下的主动成交占比，长江证券 |
| --- | --- | --- | --- |
| 22 | 朴素主动占比因子 | 朴素主动买入金额：amount*t(∆close/σ,df)，其中σ为收盘价增长量标准差，df 为自由度朴素主动占比因子：主动买入金额除以当日总成交额 | 分布估计下的主动成交占比，长江证券 |
| 23 | 均匀分布主动占比因子 | 均匀分布主动买入金额：amount*(ret-0.1)/0.2，其中amount 为每分钟成交额，ret 为对应分钟收益率均匀分布主动占比因子：均匀分布主动买入金额除以当日总成交额 | 分布估计下的主动成交占比，长江证券 |
| 24 | 成交量波峰计数因子 | 成交量波峰：成交量大于当日成交量均值+1 倍标准差的时刻成交量波峰计数因子：统计每条记录与上一条记录时间差超过1分钟的记录条数 | 高频波动中的时间序列信息，长江证券 |
| 25 | 日模糊金额比因子 | 波动率：当前时刻及之前4分钟内收益率的标准差模糊性：当前时刻及之前4分钟内波动率的标准差起雾时刻：模糊性大于当日模糊性均值的时刻雾中金额：起雾时刻的成交金额均值日模糊金额比：雾中金额除以当日成交金额均值 | 波动率的波动率与投资者模糊性厌恶，方正证券 |
| 26 | 日模糊数量比因子 | 波动率：当前时刻及之前4分钟内收益率的标准差模糊性：当前时刻及之前4分钟内波动率的标准差起雾时刻：模糊性大于当日模糊性均值的时 | 波动率的波动率与投资者模糊性厌恶，方正证券 |

知乎高频行情低频化因子库使用教程

| 27 | P型成交量分布 | 同价成交量：将日内分钟收盘价相同的成交量累加在一起，得到成交量随价格的分布成交量支撑点和成交量支撑区域：成交量累计最大的价格及其附近区域（区域累积成交量达全天成交量 50% 的最小区域）P型成交量分布：成交量支撑区域下限价格与当日最高价之差 | 成交量分布中的Alpha，兴业证券 |
| --- | --- | --- | --- |
| 28 | B 型成交量分布 | 同价成交量：将日内分钟收盘价相同的成交量累加在一起，得到成交量随价格的分布成交量支撑点和成交量支撑区域：成交量累计最大的价格及其附近区域（区域累积成交量达全天成交量 50% 的最小区域）B 型成交量分布：成交量支撑区域上限价格与当日最低价之差 | 成交量分布中的Alpha，兴业证券 |
| 29 | 修正日模糊价差因子 | 日模糊价差：日模糊金额比-日模糊数量比修正日模糊价差：将横截面上值为负的日模糊价差求和，记为 s1；将负的日模糊价差除以其过去10 日日模糊价差的标准差，值为正的日模糊价差不变调整数量级：将横截面上值为负的修正日模糊价差求和，记为 s2；将值为负的修正日模糊价差除以 s2 后乘以s1 | 波动率的波动率与投资者模糊性厌恶，方正证券 Ambiguityabout velatlity andinvestor behaviot,Journal of FinancialEconomics |
| 30 | 成交量支撑区域下限与收盘价差异因子 | 同价成交量：将日内分钟收盘价相同的成交量累加在一起，得到成交量随价格的分布成交量支撑点和成交量支撑区域：成交量累计最大的价格及其附近区域（区域累积成交量达全天成交是r00/的目小反ば) | 成交量分布中的Alpha，兴业证券 |

知乎高频行情低频化因子库使用教程

|  |  | コ口顺皿在 |  |
| --- | --- | --- | --- |
| 31 | 模糊关联度因子 | 波动率：当前时刻及 之前4分钟内收益率 的标准差模糊性：当 前时刻及之前4分钟 内波动率的标准差模 糊关联度：模糊性序 列和时刻成交额序列 的相关系数 | 波动率的波动率与投 资者模糊性厌恶，方 正证券 |

## 7.2.2基于Level-2行情快照的因子

|  | 因子名 | 因子计算逻辑和含义 | 参考文献 |
| --- | --- | --- | --- |
| 1 | 时间加权平均的股票相对价格位置因子 | 股票当期价格相对区间最高最低价的分位数：时间加权平均的股票相对价格位置： | 基于时间尺度度量的日内买卖压力，东方证券 |
| 2 | 高频上行波动占比因子 | 收益率：price /上一时刻 price - 1 上行收益率：收益率大于0高频上行波动占比：上行收益率的平方和与收益率平方和之比 | 高频因子之已实现波动分解，海通证券 |
| 3 | 高频下行波动占比因子 | 收益率：price /上一时刻 price - 1 下行收益率：收益率小于0高频下行波动占比：下行收益率的平方和与收益率平方和之比 | 高频因子之已实现波动分解，海通证券 |
| 4 | 已实现波动率因子 | 对数收益率序列：收益率的对数已实现波动率：对数收益率序列平方和的平方根 | The distribution ofexchange ratevolatlity. Jounal ofthe AmencanStatisticalAssociation 96,42-55 |
| 5 | 上行已实现波动率因子 | 对数收益率序列：收益率的对数上行已实现波动率：大于0的收益率的平方和的平方根 | Measutingdownside riskrealisedsemivariance, InVolatlity and TimeSeriesEconometncsEssays in Honor ofRobert F EngleEdited by TBoliersiev.J Russelland M. Watson),Oxford UniversityPress,117-136. |
|  | 下行司实现法六一 | …ー… | - - |

下行已实现

知乎高频行情低频化因子库使用教程

|  |  | JI | SeriesEconometncsEssays in Honor ofRobert F EngleEdited by TBoliersiev.J Russelland M. Watson),Oxford UniversityPress,117-136. |
| --- | --- | --- | --- |
| 7 | 高频已实现偏度因子 | 收益率：price /上一时刻 price - 1 高频已实现偏度：收益率的偏度 | 高频因子之股票收益分布特征，海通证券 |
| 8 | 高频已实现峰度因子 | 收益率：price / 上一时刻 price - 1 高频已实现峰度：收益率的峰度 | 高频因子之股票收益分布特征，海通证券 |
| 9 | 上下行波动率不对称性因子 | 已实现波动率：对数收益率序列平方和上行已实现波动率：大于0的收益率的平方和下行已实现波动率：小于0的收益率的平方和上下行波动率不对称性：上行已实现波动率与下行已实现波动率之差除以已实现波动率 | Measutingdownside riskrealisedsemivariance, InVolatlity and TimeSeriesEconometncsEssays in Honor ofRobert F EngleEdited by TBoliersiev.J Russelland M. Watson),Oxford UniversityPress,117-136. |
| 10 | 中间价变化率偏度因子 | 市场中间价：买一价与卖一价的均值中间价变化率：（当前时刻中间价/前一时刻中间价）-1中间价变化率偏度：中间价变化率的偏度 | 高频订单失衡及价差因子，中信建投证券 |
| 11 | 中间价变化率最大值因子 | 市场中间价：买一价与卖一价的均值中间价变化率：（当前时刻中间价/前一时刻中间价）-1中间价变化率最大值：中间价变化率的最大值 | 高频订单失衡及价差因子，中信建投证券 |
| 12 | 大成交量已实现偏度因子 | 大成交量：分钟成交量在当日排名前1/3的成交量大成交量已实现偏度：大成交量订单收益率的偏度 | 高频价量数据的因子化方法，广发证券 |

知乎高频行情低频化因子库使用教程

| 13 | 大成父重价重相大性因子 | 的成父重大成父重价量相关性：大成交量订单成交量和价格的相关系数 | 高列价重数据的囚于化方法，广发证券 |
| --- | --- | --- | --- |
| 14 | 已实现双幂次变差因子 | 已实现双幂次变差：日内对数收益率的绝对值与前一时刻对数收益率的绝对值的乘积之和 | Power and bipowervariation withstochastic volatilityand jumps. Journalof FinancialEconometrics.2.1-48 |
| 15 | 已实现三幂次变差因子 | 已实现三幂次变差：首先计算每一时刻与t-1 时刻、t-2 时刻对数收益率绝对值的乘积的2/3 次方，其次计算日内所有该值之和 | Power and bipowervariation withstochastic volatilityand jumps. Journalof FinancialEconometrics.2.1-48 |
| 16 | 日度惊恐度因子 | 偏离度：个股收益率与市场收益率的差的绝对值（选取中证全指 000985 代表市场水平）基准项：个股收益率的绝对值+市场收益率的绝对值+0.1日度惊恐度：偏离度与基准项之比 | 显著效应、极端收益扭曲决策权重和“草木皆兵”因子，2022.方正证券Cosemans M,Frehen R.2021,Salience theoryand stock prices:Empirical evidence,Journal of FinancialEconomics.140(2),480-483 |
| 17 | 成交量分桶熵因子 | 将日内分钟成交量基于最大值、最小值区间进行等距分桶，并统计各个区间的概率；分桶信息熵：每个区间计算pk*ln(pk) 的值并求和，然后乘以-1 | 成交量分布中的Alpha，兴业证券 |
| 18 | 已实现跳跃波动率因子 | 已实现三幂次变差：首先计算每一时刻与t-1 时刻、t-2 时刻对数收益率绝对值的乘积的2/3 次方，其次计算日内所有该值之和积分波动估计量：已实现三幂次变差乘以常数1.935792405(正态分布的 2/3 阶绝对矩）已实现跳跃波动率：max(对数收益率的平方和与积 | Power and bipowervariation withstochastic volatilityand jumps. Journalof FinancialEconometrics.2.1-48.New Evidence ofthe MarginalPredictve Contentof Small and LargeJumps in the Cross-Section,Eoonamatrinn |

19交易量变异系数因高频行情低频化因子库使用教程

| 20 | 上行已实现跳跃波动 率因子 | 已实现三幂次变差： 首先计算每一时刻与 t-1 时刻、t-2 时刻对 数收益率绝对值的乘 积的2/3 次方，其次 计算日内所有该值之 和积分波动估计量： 已实现三幂次变差乘 以常数1.935792405 (正态分布的 2/3 阶 绝对矩）上行已实现 跳跃波动率： max(收益率大于0 的对数收益率的平方 和与积分波动估计量 的一半之差，0) | New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross- Section, Econometrics, MDPI, 8(2), 1-52. |
| --- | --- | --- | --- |
| 21 | 下行已实现跳跃波动 率因子 | 已实现三幂次变差： 首先计算每一时刻与 t-1 时刻、t-2 时刻对 数收益率绝对值的乘 积的2/3次方，其次 计算日内所有该值之 和积分波动估计量： 已实现三幂次变差乘 以常数1.935792405 (正态分布的 2/3 阶 绝对矩）下行已实现 跳跃波动率： max(收益率小于0 的对数收益率的平方 和与积分波动估计量 的一半之差，0) 原始聪明钱因子：每 | New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross- Section, Econometrics, MDPI, 8(2), 1-52. |
| 22 | 聪明钱因子 | 分钟涨跌幅绝对值与 成交量的四次方根之 比聪明钱交易：将原 始聪明钱因子按从大 到小排序后，成交量 累计占比 20% 的分 钟交易成交量加权平 均价：将价格按照成 交量大小进行加权平 均聪明钱因子：聪明 钱交易的成交量加权 平均价除以所有交易 的成交量加权平均价 | 聪明钱因子模型的 2.0版本，开源证券 |
| 23 | 成交量占比偏度因子 | 日内成交量占比序列 的偏度 | 高频因子（四）.高 阶矩高频因子，长 江证券 |
| 24 | 成交量占比峰度因子 | 日内成交量占比序列 的收麻 | 高频因子（四）.高 阶矩高频因子，长 |

知乎日度主力交易情绪高频行情低频化因子库使用教程

|  |  | 相关性 | 为刻画，开源证券 |
| --- | --- | --- | --- |
| 26 | 趋势占比因子 | 当日收盘价减开盘价，除以每一时刻价格变化量绝对值之和 | 高频价量数据的因子化方法，广发证券 |
| 27 | 上下行跳跃波动的不对称性因子 | 已实现三幂次变差：首先计算每一时刻与t-1 时刻、t-2 时刻对数收益率绝对值的乘积的2/3 次方，其次计算日内所有该值之和积分波动估计量：已实现三幂次变差乘以常数1.935792405(正态分布的 2/3 阶绝对矩）上行（下行）已实现跳跃波动率：max(收益率大于（小于）0的对数收益率的平方和与积分波动估计量的一半之差，0)上下行跳跃波动的不对称性：上行已实现跳跃波动率与下行已实现跳跃波动率之差 | New Evidence ofthe MarginalPredictve Contentof Small and LargeJumps in the Cross-Section,Econometrics,MDPI, 8(2), 1-52. |
| 28 | 最大涨幅因子 | 日内涨跌幅最大的前10% 时刻的涨跌幅加1后连乘 | 高频选股因子分类体系，中信建投证券 |
| 29 | 大单资金净流入率因子 | 平均单笔成交金额：每分钟成交金额总额除以成交笔数大单筛选：平均单笔成交金额最大的 30% 的时刻大单资金净流入金额：收益率为正的成交总额与收益率为负的成交总额之差大单资金净流入率：大单资金净流入金额除以当日成交总额 | 日内分时成交中的玄机，海通证券 |
| 30 | 大单驱动涨幅因子 | 平均单笔成交金额：每分钟成交金额总额除以成交笔数大单筛选：平均单笔成交金额最大的 30% 的时刻大单驱动涨幅：大单收益率加1后连乘 | 日内分时成交中的玄机，海通证券 |
| 31 | 每笔成交量（成交量/成交笔数）位于每笔成交量筛选的局 量价关系中的反转微80%~100% 区间对部反转因子 观结果，长江证券应时间段的收益率之 |  |  |

知乎平均单笔流出金额高频行情低频化因子库使用教程

|  | 上行已实现跳跃波动 | 1体平均早毛成父金额 | Empincal evidence |
| --- | --- | --- | --- |
| 33 | 大的上行跳跃波动率 因子 | 率：max(收益率大 于0的对数收益率的 平方和与积分波动估 计量的一半之差，0) 判别阈值：其中，α 经验参数为4，Δ为 日内股票收益率的采 样间隔，IV为积分波 动估计量大的上行跳 跃波动率：min(上 行已实现跳跃波动 率，高于判别阈值的 对数收益率的平方 和) 下行已实现跳跃波动 | on the importance of aggregaton, asymmetry and jumps for volatlty ored cnon jourral af Econometrics.187 606-621New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross-Section, Econometrics, MDPI, 8(2), 1-52. Empincal evidence |
| 34 | 大的下行跳跃波动率 因子 | 率：max(收益率小 于0的对数收益率的 平方和与积分波动估 计量的一半之差，0) 判别阈值：其中，α 经验参数为4，Δ为 日内股票收益率的采 样间隔，IV为积分波 动估计量大的下行跳 跃波动率：min(下 行已实现跳跃波动 率，小于判别阈值相 反数的对数收益率的 平方和) 上行已实现跳跃波动 | on the importance of aggregaton, asymmetry and jumps for volatlty ored cnon jourral af Econometrics.187 606-621New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross-Section, Econometrics, MDPI, 8(2), 1-52. |
| 35 | 小的上行跳跃波动率 因子 | 率：max(收益率大 于0的对数收益率的 平方和与积分波动估 计量的一半之差，0) 判别阈值：其中，α 经验参数为4，Δ为 日内股票收益率的采 样间隔，IV为积分波 动估计量大的上行跳 跃波动率：min(上 行已实现跳跃波动 率，高于判别阈值的 对数收益率的平方 和)小的上行跳跃波 动率：上行已实现 跳跃波动率与大的上 | Empincal evidence on the importance of aggregaton, asymmetry and jumps for volatlty ored cnon jourral af Econometrics.187 606-621New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross-Section, Econometrics, MDPI, 8(2), 1-52. |
| 36 | 小的下行跳跃波动率 因子 | 行已实现跳跃波动率 之差 下行已实现跳跃波动 | Empincal evidence |

知乎高频行情低频化因子库使用教程

|  |  | 经验参数为4，Δ为 | Econometrics.187606-621NewEvidence of theMarginal PredictveContent of Smalland Large Jumps inthe Cross-Section,Econometrics,MDPI, 8(2), 1-52. |
| --- | --- | --- | --- |
|  |  | 日内股票收益率的采 |  |
|  |  | 样间隔，IV为积分波 |  |
|  |  | 动估计量大的下行跳跃波动率：min(下行已实现跳跃波动率，小于判别阈值相反数的对数收益率的平方和)小的下行跳跃波动率：下行已实现跳跃波动率与大的下行已实现跳跃波动率之差 |  |
| 37 | 日内条件在险价值因子 | 分钟 VWAR：分钟收益率序列依交易量的加权平均数VaR (在险价值):CVaR:VCVaR:交易日分钟 VWAR 的置信度为α的 CVaR | 分钟线的尾部特征，方正证券 |
| 38 | 隔夜收益率因子 | 当日开盘价与前一日收盘价之比减1 | Overnight Return:the invisible HandBehind intradayReturns, Journal ofFinancialEconometrics. 2.90-100 |
| 39 | 日内最大回撤因子 | 交易日内价格峰值到随后谷值的最大跌幅 | 高频价量数据的因子化方法，广发证券 |
| 40 | 日内成交量占比标准差因子 | 日内时刻成交量占比的标准差 | 高阶矩高频因子，长江证券 |
| 41 | 每笔成交量收益率相关性因子 | 分钟平均每笔成交量与收益率的相关系数 | 量价关系中的反转微观结果，长江证券 |
| 42 | 日内收益率因子 | 当日收盘价与当日开盘价之比减1 | Overnight Return:the invisible HandBehind intradayReturns, Journal ofFinancialEconometrics. 2.90-100 |
| 43 | 分钟成交额方差因子 | 日内分钟成交额的方差 | 高频视角下成交额蕴藏的Alpha,华安证券 |
| 44 | 尾盘半小时收益率因子 | 14：30~15：00的收盘价收益率 | 高频价量数据的因子化方法，广发证券 |
| 45 | 日度盘口价差因子 | 盘口价差：2*(a1-b1)/(a1+b1)，其中高频视角下的微观流a1 和 b1 分别为盘口动性与波动性，中金卖一价和买一价日度公司盘口价差：盘口价差 |  |

知乎尾盘半小时成交额高频行情低频化因子库使用教程

|  |  | 额比值 上行（下行）已实现 | 芬 |
| --- | --- | --- | --- |
| 47 | 大的上下行跳跃波动 不对称性因子 | 跳跃波动率： max(收益率大于 (小于)0的对数收 益率的平方和与积分 波动估计量的一半之 差，0)判别阈值：其 中，α经验参数为 4，Δ为日内股票收 益率的采样间隔，IV 为积分波动估计量大 的上行跳跃波动率： min(上行已实现跳跃 波动率，高于判别阈 值的对数收益率的平 方和)大的下行跳跃 波动率：min(下行 已实现跳跃波动率， 小于判别阈值相反数 的对数收益率的平方 和)大的上下行跳跃 波动不对称性：大的 上行跳跃波动率与大 的下行跳跃波动率之 差 | Empincal evidence on the importance of aggregaton, asymmetry and jumps for volatlty prediction, journal of Econometrics.187 606-621New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross-Section, Econometrics, MDPI, 8(2), 1-52. |
| 48 | 小的上下行跳跃波动 不对称性因子 | 上行（下行）已实现 跳跃波动率： max(收益率大于 (小于)0的对数收 益率的平方和与积分 波动估计量的一半之 差，0)判别阈值：其 中，α经验参数为 4，Δ为日内股票收 益率的采样间隔，IV 为积分波动估计量大 的上行跳跃波动率： min(上行已实现跳跃 波动率，高于判别阈 值的对数收益率的平 方和)大的下行跳跃 波动率：min(下行 已实现跳跃波动率， 小于判别阈值相反数 的对数收益率的平方 和)小的上行（下行） 跳跃波动率：上行 (下行)已实现跳跃 波动率与大的上行 (下行)已实现跳跃 波动率之差小的上下 | Empincal evidence on the importance of aggregaton, asymmetry and jumps for volatlty prediction, journal of Econometrics.187 606-621New Evidence of the Marginal Predictve Content of Small and Large Jumps in the Cross-Section, Econometrics, MDPI, 8(2), 1-52. |

知乎高频行情低频化因子库使用教程

| 49 | 日度价格弹性因子 | 价格弹性：最高价与最低价之差与成交额的比值日度价格弹性：价格弹性序列的均值 | 高频视角下的微观流动性与波动性，中金公司 |
| --- | --- | --- | --- |
| 50 | 日度盘口平均深度因子 | 盘口平均深度：买卖一量均值日度盘口平均深度：盘口平均深度序列的均值 | 高频视角下的微观流动性与波动性，中金公司 |
| 51 | 加权收盘价比因子 | 其中，VOL 为整个时间段总成交量 | 高位成交因子一从量价匹配说起，长江证券 |
| 52 | 结构化反转因子 | 动量时间段和反转时间段：将成交量从小到大进行排序，将小于等于10%的时间段记为动量时间段，大于10%的时间段记为反转时间段动量时间段反转因子：反转时间段反转因子：结构化反转因子：反转时间段反转因子与动量时间段动量因子之差 | 结构化反转因子，长江证券 |
| 53 | 日度有效深度因子 | 有效深度：买卖一量的最小值日度有效深度：有效深度序列的均值 | 高频视角下的微观流动性与波动性，中金公司 |
| 54 | 分钟成交额自相关性因子 | 分钟成交额与其前1分钟的分钟成交额的相关系数 | 高频视角下成交额蕴藏的Alpha，华安证券 |
| 55 | 尾盘半小时成交量占比因子 | 14：30~15：00的成交量占当日总成交量比值 | 高频因子的现实与幻想，海通证券 |
| 56 | 加权偏度因子 | 其中，权重 ω 为成交量占当日总成交量的比值，分母为收盘价的标准差的三次方 | 高位成交因子一从量价匹配说起，长江证券 |
| 57 | 交易量同步的知情交易概率因子 | 交易量桶：将交易量等量划分为交易量桶(此处设置单桶交易量为100,000）桶内买方交易量：桶内逐笔交易的加权和，权重为标准正态分布累计密度函数，其参数为环比增量与其标准差之比向量桶内卖方交易量：桶量与买方 | Flow toxicity andliquidity in a highfrequency world,Review of FinancialStudies, 25(5),457-1493. |

大家都在搜换一换景德镇学院通报宿舍调整… 热384 万开屏广告导致错过最佳抢… 热383万日本暴发梅毒疫情 382万热刘翔被体育局买断获49.4万 381万热知乎CLI创作者能力上新 358万热微信被曝出史诗级漏洞 335万热

| 心文勿里 |
| --- |

## 7.2.3基于逐笔委托的因子

|  | 因子名 | 因子计算逻辑和含义 | 参考文献 |
| --- | --- | --- | --- |
| 1 | 开盘后买入意愿强度因子 | 净委买变化额：委托买单增加量减去委托卖单增加量（逐笔委托）净主买成交额：主动买入成交额减去主动卖出成交额买入意愿：净主买成交额与净委买变化额之和开盘后买入意愿强度：开盘后时间段(9:30~10:00) 内买入意愿序列的均值除以标准差 | 基于直观逻辑和机器学习的高频数据低频化应用，海通证券 |
| 2 | 开盘后净委买增额占比因子 | 净委买变化额：委托买单增加量减去委托卖单增加量开盘后净委买增额占比：开盘后时间段(9:30~10:00) 内净委买变化额的总量除以同时间段内总成交额 | 捕捉投资者的交易意愿，海通证券高频因子的现实与幻想，海通证券 |
| 3 | 开盘后买入意愿占比因子 | 净委买变化额：委托买单增加量减去委托卖单增加量（逐笔委托）净主买成交额：主动买入成交额减去主动卖出成交额买入意愿：净主买成交额与净委买变化额之和开盘后买入意愿强度：开盘后时间段(9:30~10:00) 内买入意愿的总和除以同时间段内总成交额 | 基于直观逻辑和机器学习的高频数据低频化应用，海通证券 |

![](images/60cf92ee193931c6d20de7f3e9f7131b996fba8fedd2445b9c61e12e45739490.webp)

## 7.2.4基于逐笔成交的因子

|  | 因子名 | 因子计算逻辑和含义 | 参考文献 |
| --- | --- | --- | --- |
| 1 | 卖出反弹偏离因子 | (低于当日收盘价的卖单平均成交价之和/当日收盘价)-1 | 基于逐笔成交数据的遗憾规避因子，国金证券 |
| 2 | 大单买入占比因子 | 大单筛选：成交量对数调整后，成交量大于均值+1 倍标准差的成交单大单买入占 | 大单的精细化处理与大单因子重构，海通证券买卖单数据中的Alnha.海通证券 |

知乎高频行情低频化因子库使用教程

| 3 | 买单集中度因子 | 买单成交额的平方和 与总成交额的平方之 比 | 买卖单数据中的 Alpha，海通证券 |
| --- | --- | --- | --- |
|  |  | 卖单成交额的平方和 与总成交额的平方之 | 买卖单数据中的 Alpha，海通证券 |
| 4 5 | 卖单集中度因子 开盘后大单净买入占 比因子 | 比 大单筛选：成交量对 数调整后，成交量大 于均值+1 倍标准差 的成交单开盘后大单 净买入占比：开盘后 (9:30~10:00) 大买 | 买卖单数据中的 Alpha，海通证券大 单的精细化处理与大 单因子重构，海通证 券 |
| 6 | 日内主买占比因子 | 交额之差/总成交额 主动买入成交额：剔 除处于涨跌停分钟上 的主动买入卖出金额 数据，逐笔成交数据 中的标识为“Buy” 的成交额日内主买占 比：主动买入成交额 | 基于主动买入行为的 选股因子，海通证券 |
| 7 | 大单买入强度因子 | 占当日总成交额之比 大单筛选：成交量对 数调整后，成交量大 于均值+1 倍标准差 的成交单大单买入强 度：大买单成交额的 日内均值/大买单成 交额的日内标准差 | 大单的精细化处理与 大单因子重构，海通 证券 |
| 8 | 开盘后净主买占比因 子 | 净主买成交额：剔除 处于涨跌停分钟上的 主动买入金额数据， 主动买入成交额与主 动卖出成交额之差开 盘后净买入占比：开 盘后(9:30~10:00) 净主买成交额占总成 | 基于主动买入行为的 选股因子，海通证券 高频因子的现实与幻 想，海通证券 |
| 9 | 日内主买强度因子 | 主动买入成交额：剔 除处于涨跌停分钟上 的主动买入卖出金额 数据，逐笔成交数据 中的标识为“Buy” 的成交额日内主买强 度：主动买入成交额 的均值与标准差之比 | 基于主动买入行为的 选股因子，海通证券 |
| 10 子 | 开盘后净主买强度因 | 净主买成交额：剔除 处于涨跌停分钟上的 主动买入金额数据， 主动买入成交额与主 | 基于主动买入行为的 选股因子，海通证券 高频因子的现实与幻 想，海通证券 |

知乎高频行情低频化因子库使用教程

|  |  | J小エ左之比 |  |
| --- | --- | --- | --- |
| 11 | 卖单非流动性因子 | 以收益率为因变量，主动卖出成交额和主动买入成交额为自变量进行线性回归，其中主动卖出成交额的回归系数 | Sell-order liquidityand the crosssection of expectedstock retutns,Journat ofFinancialEconomeics 105(3)523-541 技术类新Alpha 因子的批量测试，东方证券 |
| 12 | 买单非流动性因子 | 以收益率为因变量，主动卖出成交额和主动买入成交额为自变量进行线性回归，其中主动买入成交额的回归系数 | Sell-order liquidityand the crosssection of expectedstock retutns,Journat ofFinancialEconomeics 105(3)523-541 技术类新Alpha 因子的批量测试，东方证券 |
| 13 | 卖出反弹占比因子 | 卖价小于收盘价的所有卖单的成交量之和与总成交量的比值 | 基于逐笔成交数据的遗憾规避因子，国金证券 |
| 14 | 剔除超大单后的普通大单买入占比因子 | 大单筛选：成交金额的分位数大于70%的订单超大单筛选：订单成交金额占当日成交总额比例超过1% 的订单剔除超大单后的普通大单买入占比：剔除超大单后的大买单成交金额占全部大单成交金额的比例 | 超大单冲击对大单因子的影响，东方证券 |
| 15 | 超大单买入占比因子 | 超大单筛选：订单成交金额占当日成交总额比例超过 1% 的订单超大单买入占比：超大单买入成交金额占全部超大单成交金额的比例 | 超大单冲击对大单因子的影响，东方证券 |
| 16 | 小买单主动成交度因子 | 小单筛选：成交量对数调整后，成交量小于均值的成交单小买单主动成交度：小买单主动成交金额占小买单成交金额的比例 | 买卖单主动成交中的隐藏信息，海通证券 |
| 17 | 剔除超大单影响后的大单涨跌幅因子 | 大单筛选：成交金额的分位数大于 70%的订单超大单筛选· | 超大单冲击对大单因子的影响，东方证券 |

知乎高频行情低频化因子库使用教程

|  |  | 又动：コ刚文川的对数与上一笔成交价格的对数之差剔除超大单影响后的大单涨跌幅：剔除超大单后，大单主动成交订单的累计对数价格变动 |  |
| --- | --- | --- | --- |
| 18 | 基于物理时间交易量加权的知情交易概率因子 | 其中，Si 和 Bi 分别第i个交易时段内的卖单数和买单数 | 知情交易概率与风险定价——基于不同PIN 测度方法的比较研究，管理科学学报.23(1).33-46 |
| 19 | 超大单涨跌幅因子 | 超大单筛选：订单成交金额占当日成交总额比例超过 1% 的订单对数价格变动：当前成交价格的对数与上一笔成交价格的对数之差超大单涨跌幅：超大单主动成交订单的累计对数价格变动 | 超大单冲击对大单因子的影响，东方证券 |
| 20 | 买入浮亏占比因子 | 买单成交价大于当日收盘价的的买单成交量之和，除以当日总成交量 | 基于逐笔成交数据的遗憾规避因子，国金证券 |
| 21 | 买入浮亏偏离因子 | 买单成交价大于当日收盘价的的买单平均成交价之和，除以收盘价，减去1 | 基于逐笔成交数据的遗憾规避因子，国金证券 |
| 22 | 开盘后大单净买入强度因子 | 大单筛选：成交量对数调整后，成交量大于均值+1 倍标准差的成交单开盘后大单净买入强度：开盘后(9: 30~10: 00)大买单成交额与大卖单成交额之差的日内均值除以其标准差 | 大单的精细化处理与大单因子重构，海通证券 |
| 23 | 大成交量委托单成交量占比因子 | 大成交量委托单筛选：按照委托单号统计成交量，成交量排前 5% 的委托单大成交量委托单成交量占比：大成交量委托单成交总量占全天成交总量的比例 |  |
| 24 | 大成交量成交单成交量占比因子 | 大成交量成交单筛选：逐笔成交数据中成交量排前 50%的订 |  |

## 知乎

## 7.3建库建表、计算因子及因子入库全流程代码

因子计算通用模板.dos

编辑于 2026-03-04 17:39 ・ 浙江

![](images/cf82887bc8976f43845b77de4691d36846d7eacf9556188ed2e679d68478f8a1.webp)

## 12项 Harness权益全包，超量尊享 8.8折

多模态覆盖18+旗舰模型、Harness权益每月赠送、多Agent适配生产力全面扩容 查看详情

阿里云 的广告

理性发言，友善互动

1 条评论

林一二我艹，牛逼06-19 · 江苏

默认最新

## 推荐阅读

## 中金研报发布《高频因子手册》全解析（1）

一 概述市场对日频及以上频率的量价因子研究由来已久，也比较成熟。相对而言，高频因子研究较为新颖，拥挤度较低，有效性也较高。中金公司的研报《量化多因子系列12：高频因子手册》比较系…PandaAI量枢院

## 中金公司《高频因子手册》分享2：动量反转因子，从数据构…

上一篇文章中我们对高频因子的优势和类型做了简要介绍，从这篇文章开始，我们将对每一大类因子做介绍，并从中选取具体一例因子，实现从数据构建到测试评估的整个过程。研究环境利用聚宽因…

PandaAI量枢院

## 从因子数量与质量说起

在前几天分享的文章《部分主流及新晋量化管理人的选股模型比较》中，会发现不同管理人的因子数量会有非常大的差异，少的几百、多则上万，这与管理人的新因子入库标准有很大的关系；其中因…

熊敛四爪

![](images/0fbc406b85162e4f497fae2f7fd5b5e30a1741bc931cfabe3a9fa52c04abb602.webp)
为什么多因子模型不是在做预测

Charl...

发表于掘金之心公...