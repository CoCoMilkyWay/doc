# NautilusTrader：开源、高性能、生产级算法交易系统

InfinityQuant 映翡量化 2025-04-05 14:57 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486448&idx=1&sn=a8a8c773e66d9ef214d1d3d9cca44fbc&chksm=9ef77cef1d26e7dd7ae1cc654f2c656295f4ffbab04665c04376bed5899fc14d1ae6f23731ae#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486448&idx=1&sn=a8a8c773e66d9ef214d1d3d9cca44fbc&chksm=9ef77cef1d26e7dd7ae1cc654f2c656295f4ffbab04665c04376bed5899fc14d1ae6f23731ae#rd)

Nautilus Trader 是一个开源 Python 库，可用于生产级算法交易。

在 Github 上是100%免费：https://github.com/nautechsystems/nautilus\_trader

![](assets/001.jpg)

\- 快速：使用Rust，速度极快  
\- 使用 Python 原生运行  
\- 风险管理  
\- 回测  
\- 高度可扩展  
Nautilus Trader 包括一个完整的交易平台，其中包含以下核心组件：  
  
\- 投资组合  
\- 交易者：账户 + 交易策略  
\- 缓存  
\- 数据引擎：数据提供商  
\- 风险引擎  
\- 执行引擎  
  

![](assets/002.jpg)

![](assets/003.jpg)

  

Nautilus Trader 附带了大量示例：  
  
A、Crypto EMA Cross ETHUSD Trailing Stop：  

https://github.com/nautechsystems/nautilus\_trader/blob/develop/examples/backtest/crypto\_ema\_cross\_ethusdt\_trailing\_stop.py  
B、Databento EMA Cross Long Only TSLA 交易策略：  

https://github.com/nautechsystems/nautilus\_trader/blob/develop/examples/backtest/databento\_ema\_cross\_long\_only\_tsla\_trades.py  
C、FX TaLib GDPUSD Bars Internal Strategy：

https://github.com/nautechsystems/nautilus\_trader/blob/develop/examples/backtest/fx\_talib\_gbpusd\_bars\_internal.py

1.NautilusTrader介绍  

NautilusTrader是一个开源、高性能、生产级算法交易平台，为定量交易者提供使用事件驱动引擎在历史数据上回测自动交易策略组合的能力，还可以实时部署这些相同的策略，无需更改代码。  
  
该平台是人工智能优先的，在高性能和强大的Python原生环境中开发和部署算法交易策略。有助于解决保持Python研究/回测环境与生产实时交易环境一致的挑战。  
  
NautilusTrader的设计、架构和实施理念优先考虑软件的正确性和安全性，以支持Python原生、关键任务、交易系统回测和实时部署工作负载。  
  
任何REST API或WebSocket等都可以通过模块化适配器集成。它支持各种资产类别和工具类型的高频交易，包括外汇、股票、期货、期权、加密和博彩，同时实现跨多个场所的无缝运营。

![](assets/004.jpg)

  

2.功能核心内容

-   **快速**：Core是用Rust编写的，使用tokio的非同步网络。
-   **可靠**：通过Rust的类型安全和Nautilus安全。Redis支持的高性能状态持久性。
-   **便携式**：独立于操作系统，在Linux、macOS和Windows上运行。使用Docker进行部署。
-   **灵活**：模块化适配器意味着任何REST API或WebSocket等都可以集成。
-   **高级**：`IOC`、`FOK`、`GTC`、`GTD`、`DAY`、`AT_THE_OPEN`、`AT_THE_CLOSE`、高级订单类型和条件触发器生效时间。执行指令`post-only`、`reduce-only`和冰山。应急命令包括`OCO`、`OUO`、`OTO`。
-   **可定制**：添加用户定义的自定义组件，或利用缓存和消息总线从头开始组装整个系统。
-   **回测**：使用历史报价刻度、交易刻度、条形、订单簿和纳秒分辨率的自定义数据同时运行多个策略等。
-   **实时**：在回测和实时部署之间使用相同的策略实施。
-   **多场地**：多场地能力促进了市场制造和统计套利策略。
-   **人工智能培训**：回测引擎速度足够快，可用于培训人工智能交易代理（RL/ES）。

  

3.为什么用NautilusTrader

-   **高性能事件驱动的Python**：原生二进制核心组件。
-   **回测和实时交易之间的平价**：相同的策略代码。
-   **降低运营风险**：增强风险管理功能、逻辑准确性和类型安全性。
-   **高度可扩展**：消息总线、自定义组件和行为者、自定义数据、自定义适配器。

  

传统上，交易策略研究和回测可能会在Python中使用矢量化方法进行，然后需要使用C++、C#、Java或其他静态类型语言以更事件驱动的方式重新实施该策略。这里的理由是，矢量化回测代码无法表达实时交易的精细时间和事件依赖复杂性，事实证明，编译语言更适合，因为它们固有的性能和类型安全性更高。

  

NautilusTrader在这里的关键优势之一是，这个重新实现步骤现在被规避了——因为平台的关键核心组件都是完全用Rust或Cython编写的。这意味着我们正在为这项工作使用正确的工具，其中系统编程语言编译高性能二进制文件，然后使用CPython C扩展模块能够提供Python原生环境，适合专业定量交易员和量化公司。

  

4.为什么是Python？

Python最初是几十年前创建的，是一种简单的脚本语言，语法简洁明了。从那时起，它已经发展成为一种成熟的通用面向对象编程语言。根据TIOBE索引，Python是目前世界上最流行的编程语言。不仅如此，Python已经成为数据科学、机器学习和人工智能_事实上_的_通用语言_。

然而，开箱即用的语言并非没有缺点，特别是在实施大型性能关键系统的背景下。Cython解决了很多这些问题，提供了静态类型语言的所有优势，嵌入到Python丰富的软件库和开发人员/用户社区生态系统中。

##   

## 5.Rust是什么？

## Rust是一种多范式编程语言，专为性能和安全而设计，特别是安全并发。Rust“速度极快”且内存高效（可与C和C++相媲美），没有垃圾收集器。它可以为关键任务系统提供动力，在嵌入式设备上运行，并轻松与其他语言集成。

Rust丰富的类型系统和所有权模型在确定性上保证了内存安全性和线程安全性——在编译时消除了许多类别的错误。

该项目越来越多地将Rust用于核心性能关键组件。Python语言绑定通过Cython和PyO3处理，在打包轮毂二进制文件之前，静态库在编译时链接，因此用户无需安装Rust即可运行NautilusTrader。

  

6.目前支持的一些集成

NautilusTrader采用模块化设计，可与_适配器_配合使用，通过将原始API转换为统一的接口和规范化域模型，实现与交易场所和数据提供商的连接。

目前支持以下集成：

![](assets/005.jpg)

  

NautilusTrader由Nautech Systems开发和维护，Nautech Systems是一家专门开发高性能交易系统的技术公司。

有关更多信息，请访问https://nautilustrader.io。