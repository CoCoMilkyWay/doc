# 限价订单薄系列（10）：Implementations Of An Order Book

fintechhaibin FinTechHi 2024-12-21 00:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484098&idx=1&sn=9917356586b3b21fd1f0526a70ad5226&chksm=fbadcd8da39913f7ef1dd6a2cfef01d0e9722387d9e5ccd952fe03ddb832457a390a3c1d6087#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484098&idx=1&sn=9917356586b3b21fd1f0526a70ad5226&chksm=fbadcd8da39913f7ef1dd6a2cfef01d0e9722387d9e5ccd952fe03ddb832457a390a3c1d6087#rd)

围绕“订单薄”基本概念及技术构建分享10篇了。内容偏基本概念和理论，并且同一个概念会反复提及。今天路上我正好梳理下围绕“订单薄”这个足够垂直领域做知识分享的整体构思。

1.为什么选择深入研究“订单薄”？

量化投资涉及到：数据、因子、模型、信号、策略、交易执行等多个环节，以下图某百亿私募的体系为例，每个环节门槛都很高，如果没有真正的实盘过，只能为围绕研报、书籍、论文做一些教科书的复现或者泛泛而谈。另外一面，对量化投资来说，特别干货的内容肯定也没法拿出分享，这个行业大家交流时都是非常的慎之又慎，既要保密，还要考虑竞争，所以交流时对方说的未必是他做的，对方和你建议的，未必是真实有效的。明白了就不会道听途说，更不会到时候还去埋怨别人：忽悠你。

因此，我结合自己的知识范围，我选择了一个偏数据层面的：订单薄 为目标。

![](assets/001.png)

  

  

**2\. 订单薄涉及的知识点**

订单薄是从微观角度，特别是围绕量价关系，研究投资品种的一个重要特征。在国际上的投资教育、学术论文及市场分析报告中频繁出现。与之相关的是“订单流”概念。

-   **订单薄**：这是一个展示市场中所有未成交买卖订单的列表，通常按价格水平排序，显示每个价位的买入和卖出订单数量。
    
-   **订单流**：指的是市场中买卖订单的动态变化过程，反映了市场参与者的行为模式和意图。通过分析订单流，交易者可以洞悉市场的活跃度，包括大额订单的变化、订单的撤销和调整等，进而预测市场价格趋势，并识别关键的支持和阻力价位。
    

围绕订单薄和订单流的研究，涉及到以下核心知识点：

-   **行情数据**：这是构建订单薄的基础，分为历史行情和实时行情，常基于Level 2数据（如10档快照、委托队列详情、逐笔委托记录、逐笔成交信息）。
    
-   **订单薄原理和技术**：深入理解订单薄的概念及其工作原理，以及实现订单薄合成的技术挑战，比如多标的物的并发处理、单个标的物的数据处理效率，还有针对不同交易所L2行情数据源的特殊处理需求。
    
-   **订单流分析**：探讨如何利用订单流来解析影响资产价格变动的因素或特征。
    
-   **订单薄因子**：开发基于订单薄信息的量化因子，用于捕捉潜在的市场机会。
    
-   **订单薄策略**：根据订单薄信息设计交易策略，例如做市商策略。
    
-   **高精度回测**：利用订单薄数据进行更精确的策略模拟测试，以减少实际交易时收益表现的不确定性。
    

**3\. 订单薄与订单流在投资中的应用价值**

关于订单薄在国内的应用性问题，确实存在一定的局限性。对于个人投资者而言，由于国内市场上免费提供高质量订单薄数据的服务稀缺，且大多数投资平台尚未集成此类功能，因此直接使用订单薄进行投资决策可能不太现实。此外，构建一个有效的订单薄分析系统需要大量的硬件资源、专业的软件开发能力和深度的量化研究支持，这超出了多数个人投资者的能力范围。

然而，在外汇和数字货币等领域，订单薄和订单流分析已经被广泛接受并实践，这些领域的资料和教程相对丰富。即使是在A股市场，尽管受到监管政策和合规性的限制，使得高频交易难以达到国外或加密货币市场的速度，但订单薄和订单流仍然为那些有能力部署快速交易系统的机构提供了宝贵的信息优势，帮助他们更快地分析短期价格波动的原因，从而优化交易策略。

综上所述，虽然对于普通个人投资者来说，订单薄和订单流的应用可能存在障碍，但对于专业机构和高级交易者，它们依然是不可或缺的工具，能够提供深刻的市场洞察力。希望上述分享能引发同行之间的交流，促进共同进步。

  

* * *

  

  

Order books must be designed efficiently in order for exchanges to work. 

![](assets/002.gif)

Order books are the lifeblood of any exchange. Each trade executed on an order book will generate some profits for the exchange in the form of trading fees. Now imagine how much you can earn when billions are transacted each day on the stock market.

In this post, I will cover two different implementations of an order book. 

-   The first uses a linked list implementation which is simple to implement but not optimal for use. 
    

-   The second uses a binary tree implementation which optimises the order book for addition and fulfilment of orders.
    

_The purpose for this exercise is to provide an alternate and clear explanation of how a simple order book may be built from commonly used data structures._

# **Premise,There are two kinds of orders serviced by an exchange.** 

-   Buy orders (or bids) indicate the price and quantity the user wishes to sell the commodity. 
    

-   Sell orders (or asks) indicate the price and quantity the user is willing to sell the commodity.
    

**Limit** orders are orders that are waiting to be fulfilled. These orders will sit in the order book until the prices turn in their favour. In contrast。Market orders will take out the desired quantity regardless of the price. Someone who issues a market order just wants his orders fulfilled to the best possible and does not care how much he pays for them.Order books run by the following,principle.

Where there are no buy / sell orders yet, a new limit order will be registered in the order book. For orders of the same price, we abide by the first come first serve principle.

If a limit buy order arrives at price A and quantity Q, all sell orders with prices ≤ A will be impacted. We will start taking out these sell orders (ordered by the lowest sell price first) until Q has been fulfilled. If there are any remaining buy orders, we store them in the order book.

Same principle applies for a sell order. We will take out all buy orders whose prices ≥ A (ordered by highest buy price first). Any remaining sell orders will be stored in the order book.

Market orders can either be fully or partially fulfilled. If there are any left over quantities, the order is discarded.

In our implementation of the order book, we limit the user to perform the following actions:

-   LIMIT <TYPE> <PRICE> <QTY> <ID> : The user places a new limit order of type buy / sell, price, quantity and order ID.
    
-   MARKET <TYPE> <QTY> <ID> : The user places a new market order of type buy / sell, quantity and order ID. Market orders do not have prices since the user is a taker.
    
-   CANCEL <ID> : The user cancels his prior limit order by ID.
    

# **Solution A involves the use of a sorted link list to track all buy / sell orders. This solution is fairly simple to implement.**

Solution B involves the use of a binary search tree (BST) with two pointers. The _root\_ptr_ will always point to the root of the tree. 

The _front\_ptr_ always points to the highest / lowest of buys / sells respectively.

![](assets/003.png)

  

Contrast the performance differences between using a linked list and BST for N inserted orders into the order book. Performance of a BST is contingent on it being balanced.

Our first implementation of the order book uses a doubly linked list. This data structure was chosen as we would need to traverse to and fro from the list occassionally to service orders.

Lets dive into the implementation. We define two classes; _BookSuperNode_ and _BookNode_. The schema for the classes are represented as such.

  

```
class BookNode:
```

# **Definitions**

![](assets/004.png)

A rough idea of how the order book can be implemented as a linked list. For a sell order book, all prices are arranged in ascending order.

The class _BookNode_ contains Orders placed by the user. All BookNode objects of the same price value are grouped under the same BookSuperNode object. Addition of a new BookNode always happens at the end of the chain using the `last_child` field of the BookSuperNode. This is done to capture the first come, first serve behaviour of orders matching.

The class _BookSuperNode_ contains the pointers to both the front & last BookNode object. During addition of an order, we seek the first BookSuperNode object of equal pricing and insert that order below the last node referenced by the `last_child`pointer. This process is done in linear time since we have to find the correct position at the requested price.

Note that for sell order books, we arrange the prices in ascending order so that the first buy order can easily take out the lowest sell orders found in the first BookSuperNode. The process is reversed for buy order books.

  

# **Caching**

To optimise for fast cancellation of orders, we can employ an in-memory cache of { order\_id : _BookNode_ } reference. This allows us O(1) access and removal of a specific order\_id. Without caching, finding the order\_id has to be done in O(N) linear time, which can be inefficient.

  

# **A working example**

![](assets/005.gif)

# **In this simple example, we assume a buyer places respective buy limit orders at quantity 20. He inserts 9 buy orders of prices \[10 … 2\] and thereafter cancels orders with prices \[9 … 2\] from the book.**

Each node in the linked list is denoted by <class> — <price> — <quantity>. N represents a _BookNode_ class and S represents a _BookSuperNode_.

The example shown above is a simple illustration of how the order book behaves when orders are inserted and cancelled. Because orders must be sorted by their prices, insertion is in O(N) linear time.

Here are the advantages of using a binary tree to implement an order book:

High search efficiency: The average time complexity of search operations in a binary tree is O(log n), whereas in a linked list it is O(n). This means that a binary tree can find specific orders more quickly when handling a large number of orders.

High insertion efficiency: The average time complexity of insertion operations in a binary tree is O(log n), whereas in a linked list it is O(n). This makes a binary tree more efficient when frequently adding orders.

High deletion efficiency: The average time complexity of deletion operations in a binary tree is O(log n), whereas in a linked list it is O(n). This makes a binary tree more efficient when fulfilling (deleting) orders.

Orderliness: A binary tree naturally maintains order, especially a Binary Search Tree (BST), which can quickly find the minimum and maximum values. This is very important for an order book, as orders usually need to be sorted by price.

Balance: By using balanced binary trees (such as AVL trees or Red-Black trees), the height of the tree can be kept at O(log n), ensuring operation efficiency even in the worst case.

Overall, a binary tree can provide more efficient search, insertion, and deletion operations when handling a large number of orders, thereby optimizing the performance of the order book.

Adding a new order: The operation of adding a new order will insert a new order into the binary tree. We need to determine the insertion position based on the order's price.

```
class Order:
```

Canceling an order: The operation of canceling an order will delete a specified order from the binary tree. We need to find the order and remove it from the tree.

```
    def cancel_order(self, order_id):
```

Matching order：The operation of fulfilling an order will find a matching order in the binary tree and reduce its quantity. If the order quantity is reduced to zero, it will be removed from the tree.

```
    def fulfill_order(self, order_id, quantity):
```

A primary use case of the order book is to simulate matching. The implementation of a matching logic based on the order book is roughly as follows.  

### Steps

1.  **Initialize the Order Book**: Create an order book to store buy and sell orders.
    
2.  **Load Historical Data**: Load historical price data to simulate market price changes.
    
3.  **Simulate Order Addition**: Add buy and sell orders at different time points based on the strategy.
    
4.  **Order Matching and Fulfillment**: Match and fulfill orders based on market price changes.
    
5.  **Record Results**: Record the results of each trade for later analysis.
    

### Example Code

This example code demonstrates how to use a binary tree-based order book for simple backtesting. You can further expand and optimize this example based on your specific needs and strategies.

`class Order:       def __init__(self, order_id, price, quantity, order_type):           self.order_id = order_id           self.price = price           self.quantity = quantity           self.order_type = order_type  # 'buy' or 'sell'           self.left = None           self.right = None      class OrderBookBinaryTree:       def __init__(self):           self.root = None          def add_order(self, order_id, price, quantity, order_type):           new_order = Order(order_id, price, quantity, order_type)           ifnot self.root:               self.root = new_order           else:               self._add_order_recursive(self.root, new_order)          def _add_order_recursive(self, node, new_order):           if new_order.price < node.price:               if node.left:                   self._add_order_recursive(node.left, new_order)               else:                   node.left = new_order           else:               if node.right:                   self._add_order_recursive(node.right, new_order)               else:                   node.right = new_order          def fulfill_order(self, market_price):           self.root, fulfilled_orders = self._fulfill_order_recursive(self.root, market_price)           return fulfilled_orders          def _fulfill_order_recursive(self, node, market_price):           ifnot node:               return node, []           fulfilled_orders = []           if node.order_type == 'buy'and node.price >= market_price:               fulfilled_orders.append(node)               if node.left:                   node.left, left_fulfilled = self._fulfill_order_recursive(node.left, market_price)                   fulfilled_orders.extend(left_fulfilled)               return node.right, fulfilled_orders           elif node.order_type == 'sell'and node.price <= market_price:               fulfilled_orders.append(node)               if node.right:                   node.right, right_fulfilled = self._fulfill_order_recursive(node.right, market_price)                   fulfilled_orders.extend(right_fulfilled)               return node.left, fulfilled_orders           else:               node.left, left_fulfilled = self._fulfill_order_recursive(node.left, market_price)               node.right, right_fulfilled = self._fulfill_order_recursive(node.right, market_price)               fulfilled_orders.extend(left_fulfilled)               fulfilled_orders.extend(right_fulfilled)               return node, fulfilled_orders      # Backtesting   def backtest(order_book, historical_prices):       for time, price in historical_prices:           # Simulate strategy: add a buy order and a sell order at each time point           order_book.add_order(f'buy_{time}', price - 1, 10, 'buy')           order_book.add_order(f'sell_{time}', price + 1, 10, 'sell')                      # Fulfill orders           fulfilled_orders = order_book.fulfill_order(price)           for order in fulfilled_orders:               print(f"Order {order.order_id} fulfilled at price {price}")      # Example historical price data   historical_prices = [       (1, 100),       (2, 101),       (3, 102),       (4, 103),       (5, 104),   ]      # Initialize order book   order_book = OrderBookBinaryTree()      # Perform backtest   backtest(order_book, historical_prices)   `