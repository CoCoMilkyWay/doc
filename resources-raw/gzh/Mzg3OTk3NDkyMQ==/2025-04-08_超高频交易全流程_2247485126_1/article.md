# 超高频交易全流程

QuantSeek QuantSeek 2025-04-08 09:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485126&idx=1&sn=7b979f0991b0fcd2406f455b61a3cc7e&chksm=cea39d20e0836ca24fbb767009d2fbee3dea4aeb821e32411413ec011b08acd1a9030a380246#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485126&idx=1&sn=7b979f0991b0fcd2406f455b61a3cc7e&chksm=cea39d20e0836ca24fbb767009d2fbee3dea4aeb821e32411413ec011b08acd1a9030a380246#rd)

## 高频交易的总体流程（The general flow of HFT） 

那些希望在纳秒级别进行买卖操作的交易流程，其核心流程都是一样的：

![img](assets/001.jpg)

img

高频交易（HFT）的独特之处在于，所有这些操作都基于**超低延迟网络（ultra-low-latency networks）**和**高速数据传输与分析（high-speed data transmission and analysis）**。交易平台的算法不断改进和自我学习，以实现更高效的行动，而海量的市场数据池则如同可以在纳秒级跨越的海洋。

![img](assets/002.jpg)

img

_来源（Source）：2024 年 HFT 市场概览（2024 HFT market overview）_

### how does HFT work?

它利用算法在毫秒级别执行数千笔交易，从微小的价格差异中获利。它在速度至关重要的市场中蓬勃发展，例如股票、加密货币和大宗商品市场。

当我们说微小的价格差异时，我们指的是非常微小的差异。利润空间是微不足道的，但这就是重点。HFT 不依赖于大的胜利，而是依赖于在数百万笔交易中持续、逐步地获利。你可以将其想象成挖掘加密货币：单独来看，每个挖出的区块并没有什么价值，但将其扩展到一个矿场的规模，突然间，你就沉浸在利润之中了。

### 高速交易的高级特性（The classy features of high-speed trading）

  

  

  

高速度（High speed）

大数据分析（Big Data analysis）

预测性扩展（Predictive scaling）

韧性（Resilience）

高负载能力（High-load capabilities）

定制硬件和软件（Custom hard & soft）

这里有一个来自区块链的真实世界类比：你有没有注意到在权益证明链（如以太坊）上的验证者每区块获得的奖励是以 ETH 的分数计算的？他们不是在追逐大奖，而是在一个区块一个区块地积累财富。高频交易者也是按照同样的原则运作的。

### 区块链是 HFT 的理想场所（BTW, blockchain is a sweet home for HFT）

-   加密货币永不眠，创造了持续的套利机会，除了区块链之外，没有任何环境能够覆盖如此高强度的信号。
    
-   加密货币臭名昭著的价格“物理特性”使得交易者能够从即使是微小的低效中获利，当然，也可能会失败。
    
-   HFT 公司可以在没有中央中介减慢速度的情况下跨境交易，这正是自由市场的精髓所在。
    

![img](assets/003.jpg)

img

_来源（Source）：全球十大最高收入的 HFT 公司（The ten highest-earning HFT Firms in the World）_

-   区块链的不可变账本在 HFT 中与事件驱动的日志系统相呼应，这些系统能够跟踪每毫秒级别的交易。
    
-   我们用来预测区块链吞吐量的相同人工智能/机器学习算法（AI/ML algorithms）可以优化 HFT 的交易决策。
    

## 为 HFT 提供超快速基础设施（Ultrafast infrastructure for HFT） 

HFT 系统试图征服光速，实现最短的**报价到交易（tick-to-trade）**管道。以下是一个例子。

如果交易所 A 在 10:00:00.001000（10:00 过后 1 毫秒）发布价格更新，一个超快速系统可能在 10:00:00.001500（在 0.5 毫秒内）接收、处理并执行交易。一个慢一点的系统，即使慢了 1 毫秒，也会错过机会。

HFT 可以被全球的对冲基金、自营交易公司和加密货币交易者应用。他们能够成功地做到这一点，这要归功于他们的基础设施特性，例如：

-   **服务器共址（Co-located servers）**：直接安置在交易所数据中心，以最小化物理距离（因为即使是光也有传播时间！）。
    
-   **定制固件（Custom firmware）**：FPGA 卡加速数据处理到纳秒级别。
    

例如，一个专门的基于 FPGA 的系统通过以太网处理原始 tick 数据，绕过操作系统层，并直接在微秒级别计算出可操作的决策。这确保了在依赖于传统基于软件的系统的竞争对手之前执行交易。

![img](assets/004.jpg)

img

_这些小小的 FPGA 板是超速交易的引擎。这里可不是在打广告哦！_

-   **低延迟网络（Low-latency networks）**：专用光纤和低延迟交换机，从每次跳转中节省毫秒级别的时间。 HFT 基础设施利用定制的网络接口卡（NICs），能够绕过传统的 CPU 处理。像 UDP 卸载这样的技术可以直接将传入的数据包（如订单簿或交易）解码为由嵌入硬件中的交易逻辑处理的可操作数据流。
    
-   **算法交易软件（Algorithmic trading software）**：复杂的算法实时分析市场数据，以识别有利可图的机会。
    

![img](assets/005.jpg)

img

_来源（Source）：一个嵌套的决策执行框架（A nested decision execution framework）。算法交易的核心（A heart of algorithmic trading）。_

-   **风险管理工具（Risk management systems）**：自动化工具管理风险敞口和合规性，减少因市场快速变化而带来的风险。
    
-   **直接市场准入（Direct market access）**：通过 API 提供实时数据流，使交易者能够即时对价格变化做出反应。 高效的市场数据处理涉及将高吞吐量的金融数据流转化为可操作的信号。例如，硬件加速器（如 FPGA）并行解码像 FAST（交易所用于实时数据的协议）这样的协议，避免操作系统引起的延迟峰值。
    

交易者将服务器共址在交易所附近，以最小化延迟，确保更快的订单执行。关键位置包括纽约、伦敦和香港等金融中心。尽管 HFT 因可能增加市场波动性而存在争议，但它提高了流动性并缩小了买卖价差。

让我们揭开这个流程的幕布，看看什么样的高频交易网络架构能够成就最佳的 HFT。

## 在 HFT 中能够产生差异的因素（Things that make a difference in HFT） 

所以你看，我们需要一个快速、高度可靠、始终可用、数据飞速流转的定制引擎。是什么隐藏在高频交易基础设施中，使其如此独特呢？**在 FPGA 架构中的即时风险检查（On-the-go risk checks within FPGA architectures）**至关重要。利用预编程的逻辑块，这些系统能够在不延迟订单执行的情况下实时评估交易规模、投资组合限制和市场风险敞口。这确保了符合监管要求，并防止过度损失。

**超低延迟（Ultra-low-latency）**描述了从市场事件发生到交易者系统对其做出反应的总延迟，通常以微秒为单位进行测量。它包括：

-   **网络延迟（Network latency）**是市场数据从交易所传输到交易者服务器所需的时间。
    
-   **处理延迟（Processing latency）**是算法处理数据并做出决策所需的时间。
    
-   **订单传输延迟（Order transmission latency）**是将订单发送回交易所所需的时间。
    

为了实现纳秒级别的延迟，现代系统利用 FPGA 中的流水线设计优化数据路径，其中每个阶段处理特定的计算任务，而无需等待其他阶段。例如，在一个实现中，流水线操作计算相关矩阵和特征值（特征值用于识别金融数据中的相关性或模式）以进行投资组合分析。

一旦计算确定了机会，**执行策略（execution strategies）**（如套利或动量交易）就会被执行。这些策略直接编程到 FPGA 逻辑中，可以预先针对历史数据进行测试，以最小化执行风险，同时确保超快速的订单放置。

![](assets/006.jpg)