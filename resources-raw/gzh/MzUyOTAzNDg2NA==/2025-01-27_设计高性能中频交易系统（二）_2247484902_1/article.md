# 设计高性能中频交易系统（二）

fintechhaibin FinTechHi 2025-01-27 21:34 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484902&idx=1&sn=ae001e2b2c9c661a73caaa397edf5b7c&chksm=fb69317a7584f36f2d0644bfa327d8453517b49b4d7d61365d17fd5cb607e5563ec246204d45#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484902&idx=1&sn=ae001e2b2c9c661a73caaa397edf5b7c&chksm=fb69317a7584f36f2d0644bfa327d8453517b49b4d7d61365d17fd5cb607e5563ec246204d45#rd)

接[设计高性能中频交易系统（一）](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484888&idx=1&sn=f4e2eedbd84e58ba903e11939e44a03b&scene=21#wechat_redirect)中，主要完成了数据模块的构建，系统启动后的日志如下：

![](assets/001.png)

查询数据库中的数据：

![](assets/002.png)

这里插入一个数据处理时，针对时间戳的时区处理的小点（只是正好补充一个小知识，完全与本文无关）

在处理金融数据时，时间戳通常包含时区信息。例如，数据可能显示为 2023-10-01 09:30:00-05:00，其中 -05:00 表示时区偏移量。Numpy 的 datetime64 类型不支持时区信息，因此我们需要使用 Pandas 来处理这些时间戳，并确保它们被正确转换为 UTC（协调世界时）。看下Copilot给出的一个代码示例：如何在两个模块中使用 Pandas 检查时区并将其转换为 UTC。

在数据处理模块中，我们需要确保时间戳被正确转换为 UTC。以下是一个示例函数，展示如何使用 Pandas 处理时间戳：

```
import pandas as pd
```

在数据存储模块中，我们需要确保在将数据存储到数据库之前，时间戳已经被转换为 UTC。以下是一个示例函数，展示如何在存储数据之前处理时间戳：

```
import pandas as pd
```

好，接下来主要继续按系统模块来梳理代码：

4.data quality checking

该模块有 5 个类，并分为三组：Initializer、Auxiliary 和 Main 类。

**①Initializers**

**主要包括了DataQualityMetrics 和 ProcessingMetrics 两个数据类。**

```
from dataclasses import dataclass
```

**上面代码中有两个指标详细说明下：**

**stale\_data\_pct表示过时数据的百分比，即在整个数据集中，过时数据所占的比例。假设我们有一个实时股票交易系统，如果某些股票价格数据在过去的 5 分钟内没有更新，那么这些数据就可以被认为是过时的。在这种情况下，我们需要监控这些过时数据的比例，以确保系统能够及时处理和更新数据。**

**data\_freshness，"数据的新鲜度"，表示数据的最新程度，即数据与当前时间的接近程度。新鲜度越高，数据越接近实时，反映的市场情况越准确。在股票数据处理过程中，数据的新鲜度是一个关键指标，特别是在高频交易或实时分析的场景中。数据的新鲜度可以用时间差来衡量，即数据生成时间与当前时间之间的差异。这个时间差越小，数据的新鲜度越高。假设我们有一个股票交易系统，该系统每秒钟接收一次股票价格数据。如果某条数据的时间戳是 10 秒前的，那么这条数据的新鲜度就是 10 秒。对于高频交易系统来说，10 秒的数据可能已经过时，需要尽快更新。**

**②**Auxiliaries****

**这个子模块主要包括了CacheManager 和 MonitoringServer 类**

**CacheManager的作用大家肯定都比较熟悉，主要是减少DB的直接访问提升数据库操作延迟并减少数据库的负载。代码中为原始数据和特征数据存储单独的缓存（分别为 1 小时和 30 分钟），并使用 maxsize 限制控制内存使用。**

```
import logging
```

**MonitoringServer 类用作捕获指标和缓存性能的 HTTP 接口:**

```
import logging
```

**③**Main Classes****

****此子模块中主要包括：DataQualityChecker 和 DataMonitor 两个类。****

****DataQualityChecker 验证市场数据的质量，检查市场交易时间内的差距、缺失数据和异常值。****

```
import logging
```

****DataMonitor 类主要是收集、处理和更新指标的核心功能:****

```
import asyncio
```

****程序运行时，如果不考虑非交易时间（或者严格的竞价交易时间）数据质量得分 65%，数据缺口占比是%10 ，如下图：****

****![](assets/003.png)****

****如果考虑了连续交易时间：数据质量达到了97分，且没有数据缺口数据:****

****![](assets/004.png)****

****![](assets/005.png)****

****此文对应的github地址是：****

****https://github.com/egemen-candir/High-Performance-MFT-System****

****但是已经打不开了。****

* * *

今日书籍推荐：