# 从零开始用Rust构建股票市场引擎

fintechhaibin FinTechHi 2025-01-14 23:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484574&idx=1&sn=1b4ed1289afeccefe2b1e325d4261468&chksm=fb0c03f11020504755e057b06d5d71ba995b830996bc018ce5a1b87e08da85a1bf9194c8d8e2#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484574&idx=1&sn=1b4ed1289afeccefe2b1e325d4261468&chksm=fb0c03f11020504755e057b06d5d71ba995b830996bc018ce5a1b87e08da85a1bf9194c8d8e2#rd)

> 本文来自Medium翻译
> 
> 原文：Building Stock Market Engine from scratch in Rust
> 
> https://github.com/Harshil-Jani/stock\_engine\_rs
> 
> Medium

这篇文章内容虽然比较初级，但对初学者了解一个简单的交易系统原型非常有帮助。

从交易所撮合引擎角度看，主要结构如下图所示：

![](assets/001.png)

上图中四个主体解释如下，直接读原文：

-   Order: Request to Buy or Sell at a particular price and quantity.
    
-   OrderBook:List of all the orders for a particular company.
    
-   Company: A publicly listed company which offers shares to people and has a particular price for it at a single moment.
    
-   Engine:List of companies that are available on the exchange.
    

最终行情以下图的用户终端形式展示出来：

![](assets/002.png)

作者拟定的项目结构如下：

![](assets/003.png)

订单

-   订单由价格和数量组成。
    
-   每个订单可以是两种类型之一：要么是买入订单，要么是卖出订单。
    

订单的结构以及它的类型（买入或卖出）：

```
use rust_decimal::Decimal;
```

订单薄

从架构来看，订单簿有不同的订单。比如有两个相同价格的订单，那么最好的做法可能是将订单按价格累计数量。例如：

第1笔订单：买入，10 数量，100.00 价格

第2笔订单：买入，20 数量，100.00 价格

可以将两者合并为一个价格点，并将该订单包含在订单簿中。

订单簿：\[（买入，30 数量，100.00 价格）\]

如图所示的订单簿中：

![](assets/004.png)

  

在绿色区域，可以看到所有以特定价格排列的买入订单，而在红色区域，可以看到以特定价格排列的卖出订单。

订单簿的结构定义：由于涉及到查找特定价格点并添加该价格的所有订单请求，可以使用 HashMap 或 BTreeMap。

```
use std::collections::HashMap;
```

需要一种方法来将订单添加到订单簿中。 add\_order\_to\_orderbook 方法写入 impl OrderBook：

  

```
use super::order::BuyOrSell;
```

编写测试用例：

  

![](assets/005.png)

```
#[cfg(test)]
```

第一条和第二条断言确保订单簿中总独特价格点对于买入订单和卖出订单都是 2。

下一行断言语句确保价格 690 的买入订单数量为 2，价格 685 的为 1。

同样，对于最后两个断言语句，700 处的卖出订单数量为 2，705 处为 1。

观察到一个重要的事实是，附图中的 Angel-One 应用程序的订单簿中，买单以降序排列，卖单以升序排列。这一点需要考虑，因为市场价格是基于这些最接近的值和最后成交的订单决定的。

如上使用价格和订单的 HashMap，所以不需要对买卖订单进行排序。这些信息对于前端展示可能很有用，但对于引擎来说，需要的最好是买入价和卖出价。如果你观察截图，底部有总买入量和卖出量，这可以给一个关于趋势的线索，以及买家和卖家数量的情况。

  

```
impl OrderBook {
```

在测试模块中添加一个测试用例，用来追踪股票的买入量和卖出量：

```
#[test]
```