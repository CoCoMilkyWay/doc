# 设计高性能中频交易系统（一）

fintechhaibin FinTechHi 2025-01-26 23:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484888&idx=1&sn=f4e2eedbd84e58ba903e11939e44a03b&chksm=fbbf237b8ba15aa1845d98453c61df524df0231e35f937fa2d7c1c2312903d47ba0145f05664#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484888&idx=1&sn=f4e2eedbd84e58ba903e11939e44a03b&chksm=fbbf237b8ba15aa1845d98453c61df524df0231e35f937fa2d7c1c2312903d47ba0145f05664#rd)

年底，不管工作还是生活，杂事很多，也不敢多熬夜，所以就以学习为主，同时构思后面关于level2数据和算法交易业务的主题。

今天要学习和借鉴的是github一个开源项目：中频交易系统设计，主要是通过python和数据库构建了一个完整的：策略交易系统，其中模块的划分以及一些业务逻辑点的实现都可以作为学习参考。文章较长，我分两篇。

此系统的整体设计架构如下：

![](assets/001.png)

1.Data Handler Module

先看最基本的实时行情数据（后面会专门定义一个历史数据处理的类）处理模块，通过MarketDataConfig和MarketData两个类，用于处理市场数据的配置和存储，详细逻辑参考注释：

```
import numpy as np
```

下面是处理数据库连接的类DatabaseManager，使用的是TimescaleDB数据库，有兴趣的可以了解下此数据库。

```
import asyncpg
```

然后就是数据处理类：DataProcessor，其中有几个数据校验的业务逻辑，值得借鉴：

```
import logging
```

最后是对接IBKR TWS的一个数据接口，代码也非常的详细：

```
import asyncio
```

  
2.DatabaseManager

处理历史数据的类DatabaseManager，具体逻辑参考代码注释：

```
import asyncpg
```

3.HistoricalDataLoader

此类是数据处理的核心类，比如客户端连接数据控制、向数据平台的流控控制（每10分钟60个请求）

```
import asyncio
```