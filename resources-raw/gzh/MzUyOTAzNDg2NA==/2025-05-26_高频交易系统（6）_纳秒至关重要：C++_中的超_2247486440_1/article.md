# 高频交易系统（6）:纳秒至关重要：C++ 中的超快交易系统

fintechhaibin FinTechHi 2025-05-26 22:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486440&idx=1&sn=0bd58a7fe7c2d166088aa4789a42278d&chksm=fb5b396f91f54d1d828a79ac9ea298245a78391e6db2e67408ff3038ea441cded6cea046b6f8#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486440&idx=1&sn=0bd58a7fe7c2d166088aa4789a42278d&chksm=fb5b396f91f54d1d828a79ac9ea298245a78391e6db2e67408ff3038ea441cded6cea046b6f8#rd)

![](assets/001.png)

注：本文来自：CppCon2024，When Nanoseconds Matter：Ultrafast Trading Systems in C++ 学习记录。

![](assets/002.png)

在交易系统中实现低延迟不能是事后才想到的。

它必须从一开始就成为设计中不可或缺的一部分。

虽然低延迟编程有时被视为 “代码优化” 的范畴，但事实是，实现这种延迟所需的大部分工作都是在设计阶段预先完成的。

-   如何将我们关于 CPU 和硬件的知识转化为 C++？
    
-   如何使用多个 CPU 内核，处理并发问题和成本，并保持快速？  
    

  

在本次演讲分享了一些关于如何从头开始设计低延迟交易系统的行业见解。并介绍了应用程序开发人员可以在其交易系统（或其他一些高性能、高并发应用程序）中直接重用的构建块；且深入研究了交易系统中常用的几种算法和数据结构，并讨论如何使用 C++ 中可用的最新功能来优化它们。以便为高频开发同行提供实用知识和技术，以提高系统的性能，并就您选择使用的工具和技术做出明智的决策。

“There is no silver bullet that will help you beat the market.

Successful trading is a losers’game: it is about being consistentlygood at everything."---Charles D.Ellis

没有什么灵丹妙药能让你战胜市场。成功的交易是一场失败者的游戏：它在于在各方面始终保持出色。（这个引入每个从事过交易的人一定会颇有感悟。）

#### 做市业务 —— 一场失败者的游戏，做市商的初心是活跃市场，提供流动性，交易目的是从投资者为你承担风险所支付的溢价中获取小额利润。并避免重大损失。

  

核心要求是快速交易：你需要对市场事件做出“足够快”的反应；而且需要变得“聪明”：你需要正确的价格，当然这也与速度相关。

![](assets/003.png)

####   

作者分析的图展示了一个低延迟交易系统架构，主题是“快速且准确地进行交易”：

### 整体架构

-   **交易客户端网络（Trading Clients Network）**：左侧浅蓝色区域，包含多个交易工作站（Trading workstation） ，代表交易员或投资者使用的终端设备，用于发起交易指令。
    
-   **托管交易系统（Colocated Trading Systems）**：中间绿色区域，是整个架构的核心处理部分，包含不同交易策略模块（Strategy A、Strategy B ）。这些策略根据接收到的市场价格信息（Prices），依据自身规则（Rules）进行运算，生成交易决策。
    
-   **现场可编程门阵列（FPGA）**：位于托管交易系统右侧，接收策略生成的规则信息，进一步处理价格信息，生成交易订单（Orders） 。
    
-   **软件执行模块（SW Execution）**：同样接收策略规则信息，负责订单的软件层面执行。
    
-   **交易所（Exchange）**：右侧的图标，代表金融交易场所，接收来自FPGA和SW Execution的交易订单并执行交易。
    

### 延迟特性标注：

-   **低延迟策略层（Low - latency strategy layer，1 - 10 μs）**：图中用红色箭头和文字标注，表明从交易工作站到托管交易系统内策略运算这一阶段，延迟控制在1到10微秒之间 。
    
-   **超低延迟执行（Ultra low - latency execution，< 1μs）**：另一处红色标注，强调从策略生成指令到订单实际在交易所执行这一过程，延迟小于1微秒 。
    

整个架构旨在实现快速且准确的交易执行，通过将交易系统部署在靠近交易所的位置（托管交易系统），并利用硬件（FPGA）和软件（SW Execution）优化，减少交易指令从生成到执行过程中的延迟，从而在高频交易场景中获得优势，能够更及时地响应市场价格变化，抓住交易机会。

接下来，很多篇幅作者详细介绍订单薄相关概念

![](assets/004.png)

  

![](assets/005.png)

  

如上订单薄，大家看我之前文章的话，肯定比较熟悉了。

最佳买价（BEST BID）为 92 美元，对应的数量是 50；

最佳卖价（BEST ASK）为 95 美元，对应的数量是 50。

你能买入的 “最佳价格” 是 95 美元，能卖出的 “最佳价格” 是 92 美元。

![](assets/006.png)

  

基于订单薄的构建，面临着一些挑战：

-   算法交易的延迟限制：不仅下单速度要快，而且快速的同时还要保证准确。
    
-   避免网卡丢包的延迟限制：缓冲区数量有限，如果读取速度不够快，应用程序会丢包，导致系统故障。
    
-   每秒高达数十万次的价格更新。
    
      
    

![](assets/007.png)

  

订单薄一般有两个有序序列：

-   买价序列（Bids），从最高价格到最低价格排序；
    
-   卖价序列（Asks），从最低价格到最高价格排序。
    

  

价格水平：

-   价格，指该价格水平的具体数值；
    
-   规模（Size），是该价格水平所有订单数量的总和。
    

  

订单：

-   每个订单都有一个唯一的 ID（uint64\_t 类型），在整个交易日内保持唯一。
    
-   典型的股票订单簿每一侧大约有 1000 个价格水平。
    

  

![](assets/008.png)

  

基于订单薄的基础定义结构如下：

-   Side 表示买卖方向（Bid 表示买，Ask 表示卖）；
    
-    Volume 表示交易量（int64\_t 类型）；
    
-   OrderId 表示订单 ID（uint64\_t 类型）。
    

定义了：

-   添加订单（AddOrder）
    
-   修改订单（ModifyOrder）
    
-   删除订单（DeleteOrder）
    

  

-   执行`AddOrder(OrderId{1}, Side::Buy, Price{92}, Volume{25});`，在订单簿中添加一个买价为 92 美元、数量为 25 的订单。
    

![](assets/009.png)

  

  

-   执行`AddOrder(OrderId{2}, Side::Sell, Price{110}, Volume{200});`，添加一个卖价为 110 美元、数量为 200 的订单。
    

![](assets/010.png)

  

-   执行`ModifyOrder(OrderId{1}, Volume{15});`，将订单 ID 为 1 的订单数量修改为 15。
    

  

![](assets/011.png)

  

  

-   执行`DeleteOrder(OrderId{2});`，删除订单 ID 为 2 的订单。
    

![](assets/012.png)

  

无论为订单簿选择何种数据结构，都需要一个哈希表。

![](assets/013.png)

  

使用`std::map`来存储订单簿的买价和卖价数据。

```
std::map<Price,Volume, std::greater<Price>> mBidLevels;
```

  

定义`mBidLevels`用于存储买价，`表示按价格从高到低排序；`

定义`mAskLevels`用于存储卖价，`表示按价格从低到高排序。`

`   `

```
std::map<Price, Volume, std::greater<Price>> mBidLevels;
```

定义模板函数`AddOrder`用于添加订单，尝试将订单插入到对应的`std::map`中，如果插入失败（价格已存在），则增加该价格水平的交易量。定义模板函数`DeleteOrder`用于删除订单，减少对应价格水平的交易量，若交易量小于等于 0，则从`std::map`中删除该价格水平。

![](assets/014.png)

`   `

`   `

操作复杂度：

-   添加订单（AddOrder）的时间复杂度为 log (N)；
    
-   修改订单（ModifyOrder）的摊还时间复杂度为常数
    

  

`std::map`的迭代器是稳定的，可以与订单数据一起存储在哈希表中；

删除订单（DeleteOrder）的摊还时间复杂度为常数。

  

![](assets/015.png)

  

如上图，实现的订单簿延迟分布，中位数为 33.0 纳秒：

  

![](assets/016.png)

如上图，展示`std::map`（随机分配内存）实现的订单簿延迟分布，中位数为 63.0 纳秒。

![](assets/017.png)

使用`std::vector`，通过两个`std::vector`（分别存储买价和卖价），并使用`std::lower_bound`（二分查找）来操作订单簿数据。定义`mBidLevels`和`mAskLevels`为`std::vector<std::pair<Price, Volume>>`类型。

![](assets/018.png)

使用`std::vector`的操作复杂度：

-   添加订单（AddOrder），如果价格水平已存在，时间复杂度为 log (N)；
    
-   如果插入新的价格水平，时间复杂度为 log (N)+N。
    
-   修改订单（ModifyOrder）的时间复杂度为 log (N)，
    

  

但由于`std::vector::insert`操作会使迭代器和指针失效，所以不能存储它们。

删除订单（DeleteOrder），如果价格水平已存在，时间复杂度为 log (N)；

如果删除导致新的价格水平插入，时间复杂度为 log (N)+N。

  

![](assets/019.png)

定义`AddOrder`函数，根据买卖方向（Side）将订单添加到对应的`std::vector`中。定义模板函数`AddOrder`，使用`std::lower_bound`查找价格位置，如果找到则增加交易量，否则插入新的价格 - 交易量对。

![](assets/020.png)

![](assets/021.png)

`std::map`（随机分配内存）和`std::vector`实现的订单簿延迟分布：`   `

-   `std::map`（随机分配内存）中位数为 63.0 纳秒，`   `
    
-   `std::vector`中位数为 34.0 纳秒
    

![](assets/022.png)

上图展示了NVDA更新价格水平的分布情况。

![](assets/023.png)

使用`std::vector`实现的订单簿相关函数，如`AddOrder`，并定义`GetBestPrices`函数用于获取最佳买价和最佳卖价。

![](assets/024.png)

采用 “反直觉” 的排序方式，将 “最佳价格” 或 “顶部” 数据放在集合末尾，这样可以减少数据复制次数。定义相应的`AddOrder`和`GetBestPrices`函数。

![](assets/025.png)

对比`std::map`（随机分配内存）、`std::vector`和 “反向”`std::vector`实现的订单簿延迟分布，`   `

-   `std::map`（随机分配内存）中位数为 63.0 纳秒，`   `
    
-   `std::vector`中位数为 34.0 纳秒，
    
-   “反向”`std::vector`中位数为 32.0 纳秒）