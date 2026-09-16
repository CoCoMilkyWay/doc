# 限价订单薄系列（11）Implementations Of An Order Book续

fintechhaibin FinTechHi 2024-12-22 01:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484104&idx=1&sn=fb7abc22980bc59811f38d33992b88f5&chksm=fb464f5c3e6e88a67902c2ed74877439a89fb32a47e782d94c0c754993043993a8d7d2b127a1#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484104&idx=1&sn=fb7abc22980bc59811f38d33992b88f5&chksm=fb464f5c3e6e88a67902c2ed74877439a89fb32a47e782d94c0c754993043993a8d7d2b127a1#rd)

这篇文章对第10篇英文原版文章做下说明。

1.概述

设计一个订单簿程序时，可以使用双向链表来管理订单。选择双向链表。是因为需要频繁地在订单簿中插入和删除订单，而且可能需要按价格排序来处理订单匹配，双向链表在这些操作上效率比较高。

![](assets/001.jpg)

如上图：

-   订单簿（OrderBook）包含两个部分：买单簿和卖单簿。
    
-   买单簿是按价格降序排列的BookSuperNode链表。
    
-   卖单簿是按价格升序排列的BookSuperNode链表。
    
-   每个BookSuperNode包含相同价格的一组订单，通过BookNode链接。
    
-   每个BookNode包含具体的订单信息，以及前后指针。
    

在实现插入订单时，需要根据订单类型和价格，找到对应的位置插入到订单簿中。

在匹配订单时，需要按照价格优先、时间优先的原则进行匹配。

确保所有的指针操作都是正确的，避免内存泄漏和野指针的问题。

另外，可能需要使用智能指针来管理内存，或者手动管理内存，确保释放资源的顺序正确。

在多线程环境下，需要对订单簿的访问进行同步，避免竞态条件。

另外，还需要定义一些辅助函数，比如查找指定价格的BookSuperNode，插入BookNode到BookSuperNode下，删除BookNode等。

在实现的时候，需要用到双向链表的操作，比如在指定位置插入节点，删除节点等。

还需要考虑边界情况，比如订单簿为空，或者订单量为零的情况。

总之，这个系统需要仔细设计，确保各个操作的时间复杂度和正确性，同时还要考虑线程安全和内存管理的问题。

  

2.撮合思路

对于插入订单的逻辑。假设下单一个限价卖单（价格为Ps）：

1.  查找买入订单簿中价格最高的BookSuperNode，记为Pb。
    
2.  如果Ps > Pb，说明没有买家愿意以这么高的价格买入，将这个卖单插入到卖单簿中对应的BookSuperNode下。
    
3.  如果Ps <= Pb，开始匹配：
    

a. 从买入订单簿中价格最高的BookSuperNode开始，检查其价格是否 >= Ps。

b. 如果是，取出这个BookSuperNode下的订单，按照时间顺序匹配，直到卖单委托量全部成交完成或者买入订单薄上没有对应的成交量可以成交。（即这笔卖出限价委托要么全部成交，要么部分成交）

c. 如果匹配后卖单还有剩余，再插入到卖单簿中。

在匹配过程中，需要更新BookSuperNode的volume，以及删除空的BookSuperNode。

对于订单取消，使用内存缓存{order\_id: BookNode}，可以快速找到要取消的订单，然后从链表中删除，并更新相关的BookSuperNode的信息。

注意：处理过程中还需要考虑如何**维护缓存的一致性**，比如在订单插入和删除时更新缓存。

  

3.详细设计思路和实现说明

1.类定义 

BookNode类：

```
表示具体的订单，包含订单信息（如订单ID、价格、数量）
```

BookSuperNode类：

```
表示相同价格的一组订单，包含价格、总量，
```

OrderBook类：

```
管理买单簿和卖单簿，包含两个双向链表，分别按价格降序和升序排列。
```

  

2.订单簿结构

买单薄：按价格降序排列的BookSuperNode链表。

卖单簿：按价格升序排列的BookSuperNode链表。

  

3.订单处理逻辑 

限价卖单：

查找买入订单簿中价格最高的BookSuperNode，记为Pb。

如果Ps > Pb，将卖单插入卖单簿中对应价格的BookSuperNode下。

如果Ps <= Pb，从买入订单簿中价格最高的BookSuperNode开始匹配，直到卖单量耗尽或没有更多匹配的订单。

如果卖单仍有剩余，插入卖单簿中。

处理过程中：

订单匹配逻辑：按照价格优先、时间优先的原则进行匹配。从最高（买入）或最低（卖出）价格开始匹配，直到订单量耗尽。

订单取消逻辑：使用内存缓存{order\_id: BookNode}，快速定位并删除指定订单。

更新相关BookSuperNode的总量和指针，必要时删除空的BookSuperNode。

线程安全 使用互斥锁保护对订单簿和缓存的访问，确保多线程环境下的数据一致性。

  

4.代码参考

```
#include <unordered_map>
```

```
void OrderBook::insertBookNode(BookSuperNode* bsn, BookNode* bn) {
```

```
void OrderBook::insertLimitSellOrder(int order_id, int price, int quantity) {
```

以上代码和说明详细展示了如何设计和实现一个基于双向链表的订单簿系统，支持限价订单和市场订单的插入、匹配和取消操作，并使用内存缓存优化订单取消的性能。通过合理的数据结构和算法设计，确保了系统的高效性和正确性。