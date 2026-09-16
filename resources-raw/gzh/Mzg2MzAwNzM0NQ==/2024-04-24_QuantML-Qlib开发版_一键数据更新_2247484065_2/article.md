# QuantML-Qlib开发版 | 一键数据更新

QuantML QuantML 2024-04-24 07:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=cf3dddcd303c02a00af63b3d0c2a43e1bde864246670d97504e7cdd412fe87fcf414773a5caa#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=cf3dddcd303c02a00af63b3d0c2a43e1bde864246670d97504e7cdd412fe87fcf414773a5caa#rd)

![](assets/001.png)

1\. QLIB数据结构

![](assets/001.png)

QuantML-Qlib开发版采用Qlib的底层数据结构，因子采用numpy写入binary file，官方提供了csv导入bin的脚本，参考教程：Data Layer: Data Framework & Usage — QLib 0.9.3.99 documentation

官方代码只展示介绍了全量导入因子的方案。但是实际维护时非常麻烦，不仅要维护交易日历，还要维护成分股信息，以及增量更新因子信息。

为了简化数据维护的流程，我们提供了两套方案，一套采用直接读取数据库（mongodb），另一套采用sqlserver->csv->bin一键自动更新的方式。

目前QuantML-Qlib中更新了第二套方案

  

2\. 代码部分

更新代码主要有两个脚本，一是qlib/utils/sqlserver\_v.py，主要实现跟数据库的交互，这里底层数据库是wind 的 sqlserver 数据库，主要实现各类数据的读取：  

![](assets/002.png)

  

  

另外一个是scripts/collect\_data\_sql.py，主要负责将数据按照要求的格式存储为csv,需要注意的是qlib里面的价格需要采用后复权以防止未来函数（看到用前复权不去量纲的量价因子都可以拉黑），同时我们会一并存储指数的行情数据，后续在回测时可以作为基准使用。

指数成分股更新在update\_instrument, 可以根据自己的需求选择相应的指数更新，默认更新全市场成分股。

![](assets/003.png)

  

直接运行代码，便可实现一键从数据库更新本地bin文件过程，所有相应的数据都会更新。  

  

  

QuantML-Qlib项目代码见星球。

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。

  

  

**点击蓝字**

![](assets/004.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/005.jpg)

![](assets/006.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**

  

  

  

![](assets/007.gif)

**分享、在看与点赞  
**

**只要你点，我们就是胖友**

![](assets/007.gif)