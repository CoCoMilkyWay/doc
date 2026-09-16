# 从零开始用Rust构建股票市场引擎（续）

fintechhaibin FinTechHi 2025-01-15 23:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484587&idx=1&sn=25e43e0dc7082f24283f2f46edf83262&chksm=fb679e7a4dd77572c277f37156532f9193e303b3b660ad106800df490ab8f843a106c5a2741c#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484587&idx=1&sn=25e43e0dc7082f24283f2f46edf83262&chksm=fb679e7a4dd77572c277f37156532f9193e303b3b660ad106800df490ab8f843a106c5a2741c#rd)

1.core\_engine

  

从上篇图中：引擎包括了所有上市公司股票->每个股票有自己的订单薄->订单薄中包括了具体订单。

上市公司一些基本属性代码定义参考如下：

```
                                                               
```

公司的结构及撮合引擎定义参考代码：

```
                
```

查看股票信息及股票对应的订单薄：

```
 
```

股票基本信息查询及订单薄操作：

```

```

通过上述代码，交易引擎实现了股票基本信息查询、股票订单簿构建、买卖订单订单处理。

2.order matching mechanisms

  

第一篇中作者使用 HashMap在Orderbook中存储订单。当进行匹配订单代码编写时，需要每次都对订单簿进行排序，以获取最佳的买卖价格。

在这个实现过程中，把 HashMap 转换为 BTreeMap 更有效率，主要原因：

HashMap stores key-value pairs in an unordered manner, making lookups fast but not maintaining any specific order. 

On the other hand, BTreeMap organizes key-value pairs in a sorted order based on keys, allowing efficient retrieval of elements based on their position in the sorted sequence.

  

使用BTreeMap重新实现订单薄结构代码参考如下：

```
                
```

下面是作者对市价单的解释：

Ideally Market Order is such an order where buyer or seller says that execute my order at the price which is currently demanded in the market. And this price is called Market Price.

The price which you always see at the screen is always the price at which the last transaction was made. Based on that price the sentiments of the market are decided and buyers try to put a price below that price and sellers put above it. This is how market works in entiriety.

实现的市价订单代码参考如下：

```
                
```

关于订单撮合机制：

-   市场订单的买方将与最佳卖价匹配，而市场订单的卖方将与最佳买价匹配。
    
-   每次以精确价格匹配订单可能并不总是有效，因为市场总是在变化。有时，你可能会找到愿意以甚至比你预期的更好的价格买卖股票的人。
    
-   通过查看一系列价格，增加在瞬息万变的股票市场中获得最佳交易的可能。这就是为什么几乎每个交易平台都会显示其订单簿的前 N 个价格。
    
      
    

实现 top\_n\_buying\_prices 和 top\_n\_selling\_prices 方法。在这里说成 Top N ，因为假设一个场景，只有 3 个买入订单，没有卖出订单。获取 top\_5 没有意义。它可能是 top 1 或 2 或 3，但最多是 top\_5。这就是为什么一般行情软件会看到它是 top N 订单。

```

```

当使用 BTreeMap 代替 HashMap 时，情况发生了变化，如果没有使用 BTreeMap，那么每次我们都需要对条目进行排序，然后从中获取 top\_n。有了 BTreeMap，总是可以确保它是 top\_n 或者 bottom\_n。这使得逻辑和复杂性处理变得更加简单。

以上逻辑实现的测试代码如下：

```
                
```

断言语句中价格已经按照最佳顺序到来。作为卖家，690 的买入价格比 685 更好，对我方发出的订单来说，作为买家，700 的卖出价格比 705 更好。

如果我们的订单簿中没有 5 个条目，那么它只会以排序顺序提供两个价格。这完全证明了前 N名的合理性。

  

3.The core matching algorithm

  

匹配的核心步骤如下：

-   Get all the valid best priced orders from the orderbook.
    
-   Match the quantity of the incoming order with the valid orders.
    

编写一个wrapper execute\_match 以匹配 incoming orders 的数量与有效订单。

Matching against quantity has 3 cases：

Partially Matched : Incoming order’s quantity is more than existing order’s quantity.

例如：

-   Incoming Order : BUY 30 units at 1000
    
-   Orderbook Order : SELL 20 units at 1000
    

将20股（假设交易单位）卖出订单和新订单成交后，则新订单还剩余10股未成交，进入排队（比如A股市场，会立即撤销或转限价委托，等待后续撮合。）

Fully Matched : Incoming order’s quantity is less than existing order’s quantity.

例如：

-   Incoming Order : BUY 30 units at 1000
    
-   Orderbook Order : SELL 40 units at 1000
    

incoming order因为买入30股，订单薄上有40股卖出订单，则买入订单完全成交。新订单返回全部成交（程序中退出循环） 。

Perfect Matched : Incoming order’s quantity is equal to existing order’s quantity.

例如：

-   Incoming Order : BUY 30 units at 1000
    
-   Orderbook Order : SELL 30 units at 1000
    

买入订单和卖出订单价量完全匹配，则直接撮合。

```

```

4.Selecting Best Price for Market / Limit Orders

  

We have to take care of Market Orders and the Limit Orders in order to obtain the valid orders from the orderbook.

-   Market Orders : Best possible order at the moment in market.
    
-   Limit Orders : Best possible match beyond a threshold price.
    

  

Let’s write the match\_market\_order method first. But before that make sure you add #\[derive(Clone)\] on top of struct Order and enum BuyOrSell .

```
 
```

主要实现逻辑如下：

Determine if the order is to buy or sell : The method first checks whether the incoming order is a buy order or a sell order.

Find best possible price matches: Depending on whether it’s a buy or sell order, the system looks for potential prices in the order book at which we can execute the incoming order. This comes from top\_n\_buy\_prices and top\_n\_sell\_prices methods which we had wrote earlier.

Attempt to match : For each potential match found at a certain price, the system tries to match the incoming order with existing orders at that price. If there are orders at that price, it executes the matching process.

Execute matching : If there are orders at the same price, it tries to match the incoming order with those orders. This means if someone wants to buy at a price that someone else wants to sell, they can make a deal.

Check quantity and repeat if needed : After trying to match with orders at each price level, it checks if the incoming order has been fully executed (meaning all of the quantity has been matched with existing orders). If not, it repeats the process with other potential matches.

Handle unmatched orders : If the incoming order hasn’t been fully executed after checking all potential best possible prices, it means there weren’t enough matching orders. In that case, the remaining part of the order is added to the order book for future matching.

使用市价单的思路实现限价单参考代码如下：

```
   
```

限价订单与市价订单代码基本相同，区别在于价格阈值，主要检查 incoming order 的价格是否高于订单价格，以便仅在高于一定水平以下执行它。

5.Testing Full Order Execution

  

参考如下订单簿：

![](assets/001.png)

-   Total buying volume is 25+40+125+100+150 = 440
    
-   Total selling volume is 10+50+25+150+120 = 355
    

  

Example 1 : Buy 10 units at limit price of 1005

As a buyer, I would always want that my order gets buyed at price of 1005 or lower since this is a limit order. Now if you check the order book there is already an order for selling at price 1005. We can match the orders here.（非常标准的用户故事描述）

Thus Incoming Order’s quantity now becomes zero. And the selling volume from the orderbook reduces by 10 units from 355 to 345.

![](assets/002.png)

Example 2: Sell 100 units at Market Price

As a seller at market price, I would need my orders to be sold at best available price in the market. Which here is 1004, 1003, 1002 and 1001 in order. The incoming sell order is matched against 65(25+40) units at 1004, 35 units at 1003. Thanks to the market\_price method which we wrote

Thus Incoming Order’s quantity now becomes zero. And the buying volume from the orderbook reduces by 100 units from 440 to 340.

  

![](assets/003.png)

  

Example 3 : Buy 40 units at 1008 Limit price

As a buyer, I would always want that my order gets buyed at price of 1008 or lower since this is a limit order. Now if you check the order book there is already an order for selling at price 1006. We can match the orders here.

Thus Incoming Order’s quantity now becomes zero. And the selling volume from the orderbook reduces by 10 units from 345 to 305.

![](assets/004.png)

  

Example 4: Sell 20 units at 1004 Limit price

As a seller at limit price of 1004, I would need my orders to be sold at price above 1004 in market. But there is nothing above or equal to 1004 to buy. So the order cannot be executed and will be added into the orderbook.

Thus Incoming Order’s quantity remains 20. And the selling volume from the orderbook increases by 20 units from 305 to 325.

![](assets/005.png)

测试用例如下：

```
                
```

6.Testing Partial Order Execution

![](assets/006.png)

-   Total buying volume is 10+25+50+40+120 = 245
    
-   Total selling volume is 20+50+30+100+210 = 410
    

  

Example 1 : Buy 25 units at limit price of 1005

As a buyer, I would always want that my order gets buyed at price of 1005 or lower since this is a limit order. Now if you check the order book there is already an order for selling at price 1005. We can match the orders here. But it is only 20 units. Remaining 5 units needs to be matched with some other order. But there is no order so eventually it is not possible and thus, We are left with no matching choice and add the order to the orderbook as a buy order of 5 units at price 1005.

Thus Incoming Order’s quantity now becomes 5. And the selling volume from the orderbook reduces by 20 units from 410 to 390. But the buying volume increases in the orderbook by 5 units from 245 to 250.

![](assets/007.png)

Example 2 : Sell 100 units at 1002

As a seller at limit price of 1002, I would need my orders to be sold at price above or equal to 1002 in market. We have 5 units at 1005, 10 units at 1004, 25 units at 1003 and 50 units at 1002 which totals 90 units. Still 10 units are remaining that cannot be sold and will go straight into the orderbook.

Thus Incoming Order’s quantity remains 10. And the buying volume from the orderbook reduces by 90 units from 250 to 160. But the selling volume increases in the orderbook by 10 units from 390 to 400.

![](assets/008.png)

  

Example 3: Buy 30 units at market price

As a buyer, I would always want that my order gets buyed at lowest price available. From the orderbook we can easily determine that the best possible buying price is for 10 units at 1002, 20 units at 1006.

Thus Incoming Order’s quantity now becomes 0. And the selling volume from the orderbook reduces by 30 units from 400 to 370.

![](assets/009.png)

测试案例如下：

```
   
```

关于测试案例，作者参考的资料是：https://finlib.in/orders-matched-stock-exchange/。