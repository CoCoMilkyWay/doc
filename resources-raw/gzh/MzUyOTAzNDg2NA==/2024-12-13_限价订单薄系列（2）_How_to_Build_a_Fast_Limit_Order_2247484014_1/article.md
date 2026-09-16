# 限价订单薄系列（2）:How to Build a Fast Limit Order Book

fintechhaibin FinTechHi 2024-12-13 01:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484014&idx=1&sn=d8141dbc5fea1c7dedabc1595ab6498c&chksm=fbbfc1150e6c63a16c08ae9d3b293427e0165a24a77a60712c3fa255f217ea75742c04288871#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484014&idx=1&sn=d8141dbc5fea1c7dedabc1595ab6498c&chksm=fbbfc1150e6c63a16c08ae9d3b293427e0165a24a77a60712c3fa255f217ea75742c04288871#rd)

## 1.原文

这是国外网站2011年关于限价订单博设计的文章，反复读了好几遍，原汁原味的原文如下：

My first really technical post will be on how to build a limit order book, probably the single most important component of a trading system. Because the data structure chosen to represent the limit order book will be the primary source of market information for trading models, it is important to make it both absolutely correct and extremely fast.

To give some idea of the data volumes, the Nasdaq TotalView ITCH feed, which is every event in every instrument traded on the Nasdaq, can have data rates of 20+ gigabytes/day with spikes of 3 megabytes/second or more. The individual messages average about 20 bytes each so this means handling 100,000-200,000 messages per second during high volume periods.

There are three main operations that a limit order book (LOB) has to implement: add, cancel, and execute. The goal is to implement these operations in O(1) time while making it possible for the trading model to efficiently ask questions like “what are the best bid and offer?”, “how much volume is there between prices A and B?” or “what is order X’s current position in the book?”

The vast majority of the activity in a book is usually made up of add and cancel operations as market makers jockey for position, with executions a distant third (in fact I would argue that the bulk of the useful information on many stocks, particularly in the morning, is in the pattern of adds and cancels, not executions, but that is a topic for another post). An add operation places an order at the end of a list of orders to be executed at a particular limit price, a cancel operation removes an order from anywhere in the book, and an execution removes an order from the inside of the book (the inside of the book is defined as the oldest buy order at the highest buying price and the oldest sell order at the lowest selling price). Each of these operations is keyed off an id number (Order.idNumber in the pseudo-code below), making a hash table a natural structure for tracking them.

Depending on the expected sparsity of the book (sparsity being the average distance in cents between limits that have volume, which is generally positively correlated with the instrument price), there are a number of slightly different implementations I’ve used. First it will help to define a few objects:

```
Order
```

The idea is to have **a binary tree of Limit objects sorted by limitPrice, each of which is itself a doubly linked list of Order objects**.

Each side of the book, the buy Limits and the sell Limits, should be **in separate trees** so that the inside of the book corresponds to the end and beginning of the buy Limit tree and sell Limit tree, respectively. 

Each order is also an entry in a map keyed off idNumber, and each Limit is also an entry in a map keyed off limitPrice.

With this structure you can easily implement these key operations with good performance:

**Add – O(log M) for the first order at a limit, O(1) for all others  
Cancel – O(1)  
Execute – O(1)  
GetVolumeAtLimit – O(1)  
GetBestBid/Offer – O(1)**

where M is the number of price Limits (generally << N the number of orders). Some strategy for keeping the limit tree balanced should be used because the nature of markets is such that orders will be being removed from one side of the tree as they’re being added to the other. Keep in mind, though, that it is important to be able to update Book.lowestSell/highestBuy in O(1) time when a limit is deleted (which is why each Limit has a Limit \*parent) so that GetBestBid/Offer can remain O(1).

A variation on this structure is to store the Limits in a sparse array instead of a tree. This will give O(1) always for add operations, but at the cost of making deletion/execution of the last order at the inside limit O(M) as Book.lowestSell/highestBuy have to be updated (for a non-sparse book you will usually get much better than O(M) though). If you store the Limits in a sparse array and linked together in a list then adds become O(log M) again while deletes/executions stay O(1). These are all good implementations; which one is best depends mainly on the sparsity of the book.

Generally, it’s also wise to use batch allocations, or if using a garbage collecting language like Java, object pools for these entities. Java can be made fast enough for HFT as long as the garbage collector isn’t allowed to run.

Strategies for safely and robustly providing access to the book’s data from multiple threads will be the subject of another post.

To conclude, this is how I’ve learned to build a high performance limit order book. If anyone has questions about how specifically to implement some of the operations I talk about, please post in the comments.

## 二.分析

## 这篇文章详细介绍了如何高效设计和实现限价订单簿，作为高频交易系统的重要基础组件。通过合理选择数据结构和优化策略，可以实现高效的订单管理和查询，以满足高频交易的性能要求。

限价订单簿需实现三项主要操作：添加、取消和执行，目标是这些操作在O(1)时间内完成。具体而言：

\- 添加操作：第一个到达某个限价的订单时间复杂度为O(log M)，后续订单为O(1)。

\- 取消操作：时间复杂度为O(1)。

\- 执行操作：时间复杂度为O(1)（按成交理解，FIX协议中的术语）。

此外，查询操作，如获取某个限价的成交量或最佳买入价和卖出价，时间复杂度也为O(1)。

在订单簿中，每个Limit代表一个价格水平，包含该价格下的所有订单，因此M表示这些Limit对象的数量。订单簿中有许多不同价格水平的订单，例如，买方可能有100元、101元、102元等买入价，卖方可能有99元、100元、101元等卖出价。在高频交易中，M的数量可能很大，但由于价格的稀疏性，可能相对较小。因此，选择合适的数据结构管理这些Limit对象至关重要。

“M是价格Limit的数量（通常远小于订单总数N）”，因为一个价格水平下可能有多个订单，尤其在高频交易中，市场深度较厚，挂单较多。然而，不同的价格水平可能相对较少，特别是在价格波动不大的情况下。例如，如果某股票价格在100元附近波动，可能有许多订单在100元、100.01元、99.99元等附近，但不同的价格水平总数可能只有几十个或几百个，具体取决于市场活跃程度和价格的最小变动单位。

对于添加操作：“第一个到达某个限价的订单时间复杂度为O(log M)，后续订单为O(1)”。第一个订单需要在价格的二叉树中插入新节点，而后续订单可以直接加入已有价格节点的双向链表。

“取消操作和执行操作时间复杂度为O(1)”，这些操作通过ID直接找到订单并进行删除或执行，利用哈希表的快速查找特性。

举个例子，假设有一个股票，订单簿如下：

买方：

\- 100元：100股

\- 101元：200股

\- 102元：150股

卖方：

\- 99元：50股

\- 100元：150股

\- 101元：100股

买方和卖方各有3个不同的限价，总共有6个不同的限价，因此M=6。

1）如果添加一个新订单，比如买方订单限价103元，这是新的价格水平，添加该订单需要在Limit的二叉树中插入新节点，时间复杂度为O(log M)，即O(log 6)，约为3。

2）如果添加已存在的买方订单限价101元，可以直接加入101元的订单链表，时间复杂度为O(1)。

3）取消订单时，通过订单ID直接找到对应订单并从链表中删除，时间复杂度为O(1)，因为哈希表查找是常数时间。

4）执行操作类似，找到最佳买入价或卖出价对应的订单并执行，时间复杂度为O(1)。