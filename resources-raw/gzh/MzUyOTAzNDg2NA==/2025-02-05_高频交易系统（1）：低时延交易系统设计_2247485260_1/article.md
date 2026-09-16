# 高频交易系统（1）：低时延交易系统设计

fintechhaibin FinTechHi 2025-02-05 06:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485260&idx=1&sn=96b9d3ba3a43854ef6b28dc1e76501bf&chksm=fbbe120a81ef888f198666f813b8f61bae23f5a908fcc214f9aa683da626298d37f1f4da04df#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485260&idx=1&sn=96b9d3ba3a43854ef6b28dc1e76501bf&chksm=fbbe120a81ef888f198666f813b8f61bae23f5a908fcc214f9aa683da626298d37f1f4da04df#rd)

这是“Meeting C++ 2022”Optiver技术负责人David Gross关于latency的一场主题为：Trading at light speed: designing low latency systems in C++的主题演讲。

先看下英文要点：

Making a trading system “fast” cannot be an afterthought. While low latency programming is sometimes seen under the umbrella of “code optimization”, the truth is that most of the work needed to achieve such latency is done upfront, at the design phase. How to translate our knowledge about the CPU and hardware into C++? How to use multiple CPU cores, handle concurrency issues and cost, and stay fast?

一个“光速（极速）交易系统”的构建应该是事先设计出来，而不是“亡羊补牢”的结果。（PS：这里我和作者的认识略有不同，对我们实际工作中来说，我个人更倾向于“快速迭代”，当然指的是高水平开发人员前提下，这样可以时刻都保证有具体要解的问题点。因为实际工作中，设计总是需要不断的开会探讨，很多时候容易陷入“空对空”的无为交流中。）

  

虽然说在实际编码中，对量化开发人员的“编程素养”要求比较高，在代码上需要按照类似“编程规范”一样来编写代码，以便提高系统性能，但对低时延交易系统来说，很多极致的性能点还是需要在设计阶段完成。

  

比如如何把对CPU和硬件的理解应用到代码中？如何有效地利用多核CPU？如何处理并发及减少系统开销、且保证系统的低时延要求？

  

就作者开篇提到的这些点，deepseek给出的建议：从CPU流水线利用率（通过`perf stat`分析IPC指标）、缓存命中率（`perf record -e cache-misses`）、到线程调度延迟（`cyclictest`测量）。这种系统级优化需要将硬件特性深度融入软件设计DNA，而非简单的后期性能调优。基本都说在了点子上：

1.内存层级意识

①通过alignas强制数据结构缓存行对齐，避免伪共享。

②使用std::hardware\_destructive\_interference\_size指导数据结构布局。

③优先选择连续内存容器（如std::vector），利用缓存局部性。

2.并发架构设计

①采用线程绑定（pthread\_setaffinity\_np）减少核心迁移开销。

②使用无锁数据结构避免互斥锁的上下文切换代价。

3.指令级优化

①通过\_\_builtin\_expect指导分支预测。

②使用SIMD指令集（如AVX2）进行数据并行处理。

4.零拷贝架构

①使用DMA技术实现网络包直接写入用户空间（如DPDK）。

②通过mmap实现磁盘内存映射，避免数据二次拷贝。

5.实时性保障

①采用SCHED\_FIFO实时调度策略。

②使用用户态中断处理（如Linux的io\_uring）。

* * *

  

此次演讲的核心观点如下：

1.Importance of Low Latency in Trading Systems: 

Low latency is crucial in automated trading due to the high volume of trades and the need to respond quickly to market changes. For instance, if a significant market event occurs, it’s necessary to cancel buy orders immediately to avoid losses.

高频交易场景下，系统需在百万级订单洪流中瞬时响应市场异动。例如当黑天鹅事件触发时，延迟1微秒的撤单操作可能意味着数百万美元的风险敞口。

  

2.Designing for Performance: 

Performance should be a primary consideration from the beginning of the system design process. While premature optimization can lead to unnecessary complexity, considering performance from the outset is essential in the overall design strategy.

不同于传统软件"先功能后优化"的模式，极速交易系统需将“性能基因”写入“架构DNA”。如同建造F1赛车，空气动力学设计必须在蓝图阶段就深度融入，而非后期加装尾翼。（PS：读到这里，我再反思了会，看来我个人之前的理解可能在高频系统设计上确实不是特别相符。）

  

3.Strategy vs Tactics in System Design: 

Strategy refers to the overall approach to meet a goal, such as handling a million events per second or reacting to a certain event within a specific latency distribution. 

Tactics, on the other hand, refer to individual actions or implementation details. While premature optimization (tactics) can be detrimental, considering performance from the beginning (strategy) is essential.

①战略层规划：确立系统能力基线，例如构建支撑10万QPS的行情解析引擎，要求99.9%的订单处理延迟低于50微秒。（PS：注意这是演讲者给出的数据，并非A股市场高频玩家的数据，A股股票市场，不管是吹牛的，还是真做到的，一个关键的问题是证券公司柜台的延时，和证券公司和交易所链路的延时，是不可绕过去的。工作中曾经遇到一个“行家”，在会上说：人家国外都拉光纤到交易所了，就是为了那几纳秒延时。）

②战术层执行：在实现过程中选择性采用无锁队列、SIMD指令优化等具体技术手段，避免陷入"为优化而优化"的陷阱。（PS：实际工作中，PM对量化开发人员总会反复提及。）

  

4.Building Blocks of Low Latency Systems: 

Four main topics are crucial in building low latency systems: data model access, system tuning, eventuality, and performance measurement. These topics provide a roadmap for designing and implementing a low latency trading system.

低时延系统设计的4个核心要点

①数据模型的范式：通过内存对齐、缓存亲和的数据结构设计，将L1/L2缓存命中率提升至98%+

②系统调优：采用CPU绑核、NUMA感知的内存分配策略，将线程切换开销压缩至纳秒级

③事件处理机制：实现基于环形缓冲区的零拷贝传输，将网络报文到业务处理的延迟降低到5微秒以内

④性能监控：通过eBPF实时采集LLC（末级缓存）未命中率，结合PMU（性能监控单元）数据进行热点分析

  

5.Evolution of Exchange Speeds: 

Exchange speeds in financial markets have evolved, with the current focus on achieving microsecond-level latencies. This highlights the increasing demand for speed in financial markets and the need for trading systems to keep up with this trend.

金融市场的交易速度持续进化，如今的重点在于实现微秒级的低延迟。这体现了金融市场对速度需求的不断增长，以及对交易系统能够跟上这一趋势的需求。

  

6.Trigger to Target Latency: 

“Trigger to target latency” is a concept used to measure the speed of trading systems. It refers to the time from when the exchange sends an event to market participants (the trigger) to when any market participant sends an order back (the target). This is a key performance indicator in the world of automated trading.

从交易所行情触达（Trigger）到策略引擎发出目标订单（Target）的全链路时延，包含：网络传输延迟（光速物理限制）、协议解析时耗（优化空间最大）、策略计算耗时（算法效率核心）、风控校验耗时（合规性刚需）。

  

关于低时延，需要细分为4个概念：

①tick-to-trade latency：这是一个大家比较通用的延时指标。

![](assets/001.png)

②socket-to-socket latency:

![](assets/002.png)

③port-to-port latency:

![](assets/003.png)

④wire to wire latency:

![](assets/004.png)

  

关于高频交易中，系统的延时到底多少合适？这个问题如果不谈前提条件就没有标准答案。

首先，谈延时必须谈场景。比如是多少只股票参与计算、因子的数量、模型计算的复杂度、策略计算的复杂度，以及是否要过风控系统等等。不能说行业有人喊出了纳秒级，就以为别人都可以，为什么自己不行。

同时，如果策略不行，哪怕在光速上开发系统也赚不钱；如果策略效果非常好，收益的损失都是因为交易延时带来的滑点影响的，那是应该交易执行系统的时延。

但在国内的股票市场，一些客观的基础设施摆在那里，比如每天9.30的行情吞吐高峰，全市场行情源给出的行情都是延时的，我们又去要求谁或者自己有能力来改变吗？比如证券公司证券柜台的现状，比如高频交易者在合规条件下的系统最佳部署方案等等，都是谈低时延的前提。证券行业现在还有信创任务，在交易核心链路满足低时延要求，需在计算层，网络层，存储层，应用层都要做好相关信创技术引入，比如低时延网络、低时延网卡、全闪存储等等。

其中交易速度的演进路径大概包括如下历程：

-   2000年代：百毫秒级延迟 → 采用普通TCP协议栈；
    
-   2010年代：微秒级突破 → FPGA加速+内核旁路技术；
    
-   2020年代：向纳秒级逼近 → 光子传输+ASIC芯片定制化。
    

目前国外顶级做市商系统可实现1.2微秒的端到端延迟，相当于光在光纤中传播240米的耗时。

从交易所角度来说：

我找到了自己收藏的一个2019年统计数据，国外交易所的速度确实比较优秀，

![](assets/005.jpg)

这是nyse2019年将纽约证券交易所股票平台迁移到纽约证券交易所Pillar技术后的延时提升统计图：

![](assets/006.png)

  

按官方介绍通过 Pillar 匹配引擎进行的 NYSE Pillar 订单输入会话的往返延迟已从 FIX 的约 592μs 减少到约 32μs，Binary 的往返延迟从约 96μs 减少到约 26μs，从而可以更快地将客户订单送入市场。由于 99 百分位延迟结果改善了 92%。订单输入会话中能够处理的消息数量从每秒 1,000 条消息增加到每秒 5,000 条消息（具体来说，每 100 毫秒 500 条消息）。这一增长使客户能够在单个会话中提交 5 倍的订单量。会话费用保持不变，从而为行业带来降低成本的机会。

  

国内沪深交易所近几年都相应的进行了交易系统的升级，上海期货交易系统更是升级到了NGES3.0，下面是上期发布的介绍：

上期所上一代交易系统NGES2.0于2015年上线，已平稳运行9年。随着期货市场的蓬勃发展，面对业务创新需求和交易规模不断增长的挑战，在上期所党委的引领下，聚全所之力，按照“技术服务业务，业务服从技术，更要服从安全”的要求，在2020年启动了新一代交易系统NGES3.0的建设。

在吸纳NGES2.0系统优点的基础上，NGES3.0结合国内外期货市场特点及上期所发展的长远目标，针对实际业务需求，采用当前的主流前沿技术，开展技术攻坚，保证新系统具备高可靠、大容量、高性能、易运维的四大特点。

NGES3.0是完全自主研发，采用“主从备三节点”的确认架构，防双点故障，报单容量提升3倍，业务处理性能提升40%，支持灵活扩展，精细化监控，降低运维风险，保障安全生产。

  

综上，在国内股票市场从事高频交易，我们不但要构建自身低时延的高频交易全流程系统，同时也要关注市场基础设施的建设情况，确保我们在高频交易上的投入是有切切实实的回报，否则，可能只是为了实现一个并不能带给我们投资收益的：软件目标。

* * *

  

以下是本次路演的PPT文档，这两天我会对核心要点做好翻译和整理，后续文章中发出。

![](assets/007.png)

  

![](assets/008.png)

  

![](assets/009.png)

![](assets/010.png)

  

![](assets/011.png)

  

![](assets/012.png)

![](assets/013.png)

![](assets/014.png)

  

![](assets/015.png)

![](assets/016.png)

![](assets/017.png)

![](assets/018.png)

![](assets/019.png)

  

![](assets/020.png)

![](assets/021.png)

![](assets/022.png)

![](assets/023.png)

![](assets/024.png)

  

![](assets/025.png)

  

![](assets/026.png)

![](assets/027.png)

![](assets/028.png)

![](assets/029.png)

![](assets/030.png)

![](assets/031.png)

  

![](assets/032.png)

  

![](assets/033.png)

![](assets/034.png)

![](assets/035.png)

![](assets/036.png)

![](assets/037.png)

![](assets/038.png)

![](assets/039.png)

![](assets/040.png)

![](assets/041.png)

![](assets/042.png)

![](assets/043.png)

  

![](assets/044.png)

![](assets/045.png)

![](assets/046.png)

![](assets/047.png)

![](assets/048.png)

![](assets/049.png)

  

![](assets/050.png)

  

![](assets/051.png)

![](assets/052.png)

![](assets/053.png)

![](assets/054.png)

![](assets/055.png)

![](assets/056.png)

![](assets/057.png)