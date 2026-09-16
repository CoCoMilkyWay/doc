# 限价订单薄系列（12）Volume imbalance and Order flow imbalance

fintechhaibin FinTechHi 2024-12-26 23:38 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484248&idx=1&sn=05c0cc462f9232fdc9fdcebf92117946&chksm=fb449771558c99de6f1370dbdbce531f27d6fe5eb2f2923f9e2f401288111a72e39f00e40172#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484248&idx=1&sn=05c0cc462f9232fdc9fdcebf92117946&chksm=fb449771558c99de6f1370dbdbce531f27d6fe5eb2f2923f9e2f401288111a72e39f00e40172#rd)

针对订单薄的基本知识前面做了介绍，这篇文章主要是学习几篇论文中通过订单薄来预测投资标的价格变化的思路，主要包括成交量失衡（Volume imbalance）和订单流失衡（Order flow imbalance）。

**1.成交量失衡**

针对订单簿进行微观角度分析的目的是为了确定某个标的未来的趋势方向（是上涨，还是下跌）。这个思想就是看涨交易量不平衡。成交量在某个时间序列上不平衡：

上面公式中：

-   ：是订单簿上t时刻bid1对应的成交数量。
    
-   ：是订单簿上t时刻ask1对应的成交量。
    

按照将接近1的值解释为强烈的买入压力信号，将接近-1的值解释为强烈的卖出压力信号。上面假设的只是一个1档订单薄的情况。

引用4的论文中将价格不平衡与随后通过价差标准化的价格进行了比较。下图摘自他们的论文：

![](assets/001.png)

上图显示了某个区间的成交量不平衡（x轴）与按价差归一化的平均未来价格变动（y轴）之间的关系。在1档订单薄上，成交量不平衡与未来价格变动之间存在线性关系。普遍来看，未来的价格变动在买卖价差之内。

引用论文1中把划分3个类别（Interval和Label）：

-   ，巨量卖出
    
-   ，中性
    
-   ，巨量买入
    

下图是论文中预测价格走势的结果，图中主要分析了Intel和Oracle两家公司的股票2014年1月至2014年12月期间的订单簿。对于每个到达的市场订单 (MO)，记录成交量不平衡，**并用中间价在接下来的10毫秒内变化的笔数**进行细分。![](assets/002.png)

如图所示，投资标的价格上涨更有可能出现在买单量大的订单簿之前。同样，投资标的价格下跌更有可能出现在卖单量大的订单簿之前。

上段中提到的：“根据中间价格在接下来10毫秒内变化的tick数”我猛然一看，也不是很理解，所以单独展开说下：

##### 中间价格（Mid Price）

中间价格是买入价（Bid Price）和卖出价（Ask Price）的平均值。它通常用来衡量市场的当前价格水平。例如，如果买入价是100元，卖出价是102元，那么中间价格就是101元。

##### tick

tick是行情相关的概念，表示价格的最小变动单位。例如，如果股票的价格从100.00元变动到100.01元，这就是一个tick。在不同的市场和金融工具中，tick的大小可能不同。比如沪深股票最小价格变动单位是0.01元，ETF是0.001元等。

##### 10毫秒内的价格变化

在高频交易和量化投资中，时间精度非常重要。10毫秒（0.01秒）是一个非常短的时间间隔，但在高频交易中，这段时间内的价格变化可能会提供重要的信息。（在国内市场可能未必能基于这个时间完成交易。）

##### 上图的详细思路

1.  **记录市场订单**：每当一个市场订单（Market Order，MO）到达时，记录该订单的相关信息，包括成交量不平衡情况（即买入和卖出订单的数量差异）。
    
2.  **观察价格变化**：在市场订单到达后的10毫秒内，观察中间价格的变化情况。
    
3.  **tick数**：记录中间价格在这10毫秒内变化了多少个tick。例如，如果中间价格从101元变动到101.03元，那么变化了3个tick。
    
4.  **分类**：根据中间价格在这10毫秒内变化的tick数，对成交量不平衡情况进行分类。例如：
    

-   如果中间价格在10毫秒内上升了3个tick，则将这种情况归类为“价格上升3个tick”。
    
-   如果中间价格在10毫秒内下降了2个tick，则将这种情况归类为“价格下降2个tick”。
    

通过这种分类方法，可以分析市场订单对短期价格波动的影响。例如：

-   如果发现市场订单的成交量不平衡通常会导致中间价格在短期内显著变化，可以利用这一信息进行高频交易。
    
-   可以根据这些数据制定更有效的交易策略，例如在预期价格上升时买入，在预期价格下降时卖出。
    

这种分析方法帮助自己理解市场订单对价格变化的短期影响，从而在高频交易和量化投资中做出更明智的决策。

**2.订单流失衡**

先回顾下订单流：订单流（Order Flow）是指市场中买卖订单的流动情况，包括市场订单、限价订单和取消订单等。它反映了市场参与者的交易意图和行为，是市场微观结构研究的重要内容。通过分析订单流，可以了解市场的供需关系、价格发现过程以及市场流动性等信息。订单流分析在高频交易和量化交易中尤为重要，因为它可以帮助交易者预测短期价格走势和市场动态。

成交量不平衡关注的是限价订单簿中的总成交量。其缺点在于，部分成交量可能来自“旧订单”，包含的信息较少。所以可以关注最新的订单量，这个方法称为订单流不平衡。通过在限价订单簿找出最优买入价和卖出价时成交量的变化来计算订单流不平衡。最优买入价的成交量变化由以下公式得出：

对于以上三种情况：

1.  **情况 1**：如果当前的最佳买入价（或卖出价）高于之前的最佳买入价（或卖出价），则所有交易量都是新交易量，因为价格上涨意味着新的买单（或卖单）进入市场。
    

![](assets/003.png)

1.  **情况 2**：如果当前的最佳买入价（或卖出价）与之前的最佳买入价（或卖出价）相同，则新的交易量是当前总交易量与之前总交易量之间的差值。
    

![](assets/004.png)

1.  **情况 3**：如果当前的最佳买入价（或卖出价）低于之前的最佳买入价（或卖出价），则所有之前的待处理订单都已成交，并且不再存在于订单簿中，因此新的交易量为零。
    

![](assets/005.png)

为了更好的理解逻辑，可参考如下伪代码。

`#include <algorithm> // for std::max      // 定义一个函数来计算最佳买入价的成交量变化   int calculate_bid_volume_change(int current_bid_price, int previous_bid_price, int current_bid_volume, int previous_bid_volume) {       if (current_bid_price > previous_bid_price) {           // 情况 1: 如果最佳出价高于之前的最佳出价，则所有交易量都是新交易量           return current_bid_volume;       } elseif (current_bid_price == previous_bid_price) {           // 情况 2: 如果最佳出价与之前的最佳出价相同，则新的交易量为当前总交易量与之前总交易量之间的差值           return std::max(0, current_bid_volume - previous_bid_volume);       } else {           // 情况 3: 如果最佳出价低于之前的最佳出价，则所有先前的待处理订单均已成交并且不再存在于订单簿中           return 0;       }   }   `

与买入同理，最优卖出价的成交量变化公式如下：

可参考如下伪代码:

`#include <algorithm> // for std::max      // 定义一个函数来计算最佳卖出价的成交量变化   int calculate_ask_volume_change(int current_ask_price, int previous_ask_price, int current_ask_volume, int previous_ask_volume) {       if (current_ask_price < previous_ask_price) {           // 情况 1: 如果最佳卖价低于之前的最佳卖价，则所有交易量都是新交易量           return current_ask_volume;       } elseif (current_ask_price == previous_ask_price) {           // 情况 2: 如果最佳卖价与之前的最佳卖价相同，则新的交易量为当前总交易量与之前总交易量之间的差值           return std::max(0, current_ask_volume - previous_ask_volume);       } else {           // 情况 3: 如果最佳卖价高于之前的最佳卖价，则所有先前的待处理订单均已成交并且不再存在于订单簿中           return 0;       }   }   `

基于“最优买入成交量变化”和“最优卖出成交量”变化，根据净订单流不平衡（OFI）t公式可计算出订单流失衡值：

-   当买单较多时，该值将为正值；
    
-   当卖单较多时，该值将为负值。
    
-   该值既衡量了成交量的大小，也衡量了成交量的方向。 在上面Volume imbalance中，成交量失衡仅衡量了方向，而不是成交量的大小。
    

还有一个算法是将这些值相加以获得一定时间间隔内的 OFI：

在（https://doi.org/10.48550/arXiv.1907.06230）中作者使用回归模型来测试订单流不平衡是否包含有关未来价格变动的信息：

![](assets/006.png)

上图中，订单流不平衡值被用作未来价格变动回归模型的输入。使用了六只股票，分别是亚马逊（AMZN）、特斯拉（TSLA）、奈飞（NFLX）、甲骨文（ORCL）、思科（CSCO）和美光（MU）。  
拟合的截距为 ，订单流不平衡输入的拟合系数为 。在所有六种情况下，显著性水平都低于1%，表明订单流不平衡包含了关于未来价格变动的信息。

通过引用几篇研究限价订单簿中订单量的文章的主要观点，这些文章表明，订单簿中包含的信息可以高度预测未来的价格走势。然而，这些价格走势并没有超出买卖价差。

本文主要参考了：

①Álvaro Cartea, Ryan Francis Donnelly, and Sebastian Jaimungal: “Enhancing Trading Strategies with Order Book Signals” Applied Mathematical Finance 25(1) pp. 1–35 (2018)

②Alexander Lipton, Umberto Pesavento, and Michael G Sotiropoulos: “Trade arrival dynamics and quote imbalance in a limit order book” arXiv (2013)

③Álvaro Cartea, Sebastian Jaimungal, and J. Penalva: “Algorithmic and high-frequency trading.” Cambridge University Press

④Ke Xu, Martin D. Gould, and Sam D. Howison: “Multi-Level Order-Flow Imbalance in a Limit Order Book” arXiv (2019)