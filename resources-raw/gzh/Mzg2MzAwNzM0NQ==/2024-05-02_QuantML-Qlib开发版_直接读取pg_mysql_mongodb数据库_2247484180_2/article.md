# QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库

QuantML QuantML 2024-05-02 15:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=cf9155b655c81de98f5e18a92b700539adc41bd55c6f1263ce504d404ea42808d7f8168b03b9#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=cf9155b655c81de98f5e18a92b700539adc41bd55c6f1263ce504d404ea42808d7f8168b03b9#rd)

![](assets/001.png)

数据结构

![](assets/001.png)

QuantML-Qlib开发版采用Qlib的底层数据结构，因子采用numpy写入binary file，官方提供了csv导入bin的脚本，参考教程：Data Layer: Data Framework & Usage — QLib 0.9.3.99 documentation

官方代码只展示介绍了全量导入因子的方案。但是实际维护时非常麻烦，不仅要维护交易日历，还要维护成分股信息，以及增量更新因子信息。

为了简化数据维护的流程，我们提供了两套方案，一套采用直接读取数据库，另一套采用sqlserver->csv->bin一键自动更新的方式。

之前已经介绍过第二种方案，第二种方案的优势在于读取效率快，但是中间过程不够优雅。

本文介绍方案一，即从QuantML-QLib直接接入数据库，方案同样适用于原版的QLib。

要实现直接接入数据库，首先要了解QLIB底层读写数据的逻辑，存储的逻辑参考dump\_bin.py不是本文重点，不再赘述。读取数据的结构为 storage -> provider -> loader -> handler , 大致上是这样的结构。其中又分为calendar,instrument和feature三个子类，分别存储交易日历，成分股信息，以及因子值。数据结构可以参考qlib原有的数据结构。在设计数据库结构时，尽量保持跟原有数据结构一致。

![](assets/002.png)

calendar数据结构

  

![](assets/003.png)

instrument数据结构

  

![](assets/004.png)

feature数据结构

  

所以要改变底层数据接口，重点是修改storage 和 provider，pg和mysql的接口实现都是继承新的storage类。其中pg来自开源项目，mysql来自星友， 实现了wind mysql数据库的直接接入。

mongo实现的时候稍微复杂一些，如果client的建立是在storage中实现，qlib的高并发会导致大量client的实例（pg和mysql代码同样存在这个问题），每个client会建立socket，而client close之后，socket并不会立刻关闭，因此会导致socket数量超过端口上限，最终程序报错

```
pymongo.errors.AutoReconnect: localhost:27017: [WinError 10048] 通常每个套接字地址(协议/网络地址/端口)只允许使用一次
```

  

解决办法有两个，一是每次连接关闭之后sleep小段时间，等socket关闭之后再建立连接，这无疑会降低读取的效率。第二种办法是建立一个公用的client,所有的查询均在这个client中实现。我们将client的register在config中，注意这里register的是client的实例，而非class，这样就能确保在storage中调用时，均为这个建立好的client。

```
if getattr(C, "mongodb_provider", None) is not None:
```

  

storage中调用mongo client的代码：

```
def query(self, query_dict, projection_dict, limit=None, table_name=None):
```

  

目前代码已经打包发布在星球，代码结构如下：

![](assets/005.png)

调用时，只需要修改相应的key值即可实现不同数据库读取的切换。具体调用方法参考QuantML-Qlib项目中的examples/workflow\_by\_code.py

![](assets/006.png)

**效率对比：**  

本地文件：

![](assets/007.png)

  

mongodb数据库：

![](assets/008.png)

  

mongo基本上比本地文件读取慢10倍左右，跟pg的效率相比稍微有所提高。后续会加入arctic/clickhouse的支持，效率应该会有大幅提升。

两套方案均已在QuantML-Qlib中实现，可以根据自己需求进行选择。

  

QuantML-Qlib项目代码见星球。

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

  

  

**点击蓝字**

![](assets/009.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/010.jpg)

![](assets/011.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**

  

  

  

![](assets/012.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/012.gif)