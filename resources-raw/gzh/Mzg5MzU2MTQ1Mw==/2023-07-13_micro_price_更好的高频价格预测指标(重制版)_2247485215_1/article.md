# micro price:更好的高频价格预测指标(重制版)

puppy 跟puppy玩量化 2023-07-13 21:27 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247485215&idx=1&sn=6d4f6146e67cb028041f7ff795af42d9&chksm=c188540ff209dbbe6f17429a2feb7c807dabbb5b10badeac243ee5f94187e90d97ec1ccf6dab#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247485215&idx=1&sn=6d4f6146e67cb028041f7ff795af42d9&chksm=c188540ff209dbbe6f17429a2feb7c807dabbb5b10badeac243ee5f94187e90d97ec1ccf6dab#rd)

‍‍

前两天发表的关于micro price的文章出现了基本概念(wmid写成vwap了)错误，所以删掉了。今天重写了一遍micro price，**增加了我用3个商品期货品种tick数据验证micro price的部分**。

先回顾一下micro price的出现背景。  

如果当前的盘口信息长下面这样，要找到一个能预测未来盘口变动的公允价格，怎么去确定这个公允价格？

![](assets/001.jpg)

**mid price**是最常用的公允价格，它的计算方式非常简单，用（买1价格+卖1价格）/ 2得到mid price：  

![](assets/002.jpg)

但mid price的缺点很多，一是mid存在负的自相关性，中间价格的上涨往往会接着下跌，如果只考虑中间价格的变化，会低估价格的实际变化幅度，二是mid没有考虑到订单量的信息，三是mid相对于订单薄的变动太迟钝了，不能及时反应订单薄的信息。

为了弥补mid的种种缺陷，业界提出了在mid上改进的**weighted mid price(wmid)**，加权中间价。

![](assets/003.jpg)

其中的I衡量了订单量：

![](assets/004.jpg)

即便wmid考虑到了订单量，它也有缺陷，比如用下面这个一档盘口的数据来计算wmid：

![](assets/005.jpg)

  

此时的wmid = (9 \* 10.02 + 10 \* 27) / (27 + 9) = $10.005  

如果一笔新的sell order进来，以1手$10.01打到了卖一档，此时的wmid = (9 \* 10.01 + 10 \* 1) / 10 = $10.009，常理来说此时的价格应该是下降的，但算出来的wmid不降反增。

  

为了解决mid和wmid的问题，Sasha Stoikov提出了micro price。

  

在他2018年发表的这篇论文里，作者通过严谨的数学推导证明了Micro Price在高频价格的预测上优于mid和wmid。论文很短，只有14页，是我喜欢的行文简洁逻辑清晰的风格。

![](assets/006.jpg)

下面是详细的micro price推导过程。作者先定义了第i个mid price的表达式，Ft是在t时刻订单簿中所包含的信息，τ1，..., τn表示中间价格M变化的时间：

![](assets/007.png)

  
接下来定义了Micro Price，它等于当时间i趋近于无穷大时的mid price：  
  

![](assets/008.jpg)

  
为什么要把时间设定为无穷大，作者解释了这样做的2个原因：一是方便对不同交易频率的资产做比较，把时间的因素剥离出去。二是比较远期的价格，过滤掉高频微观中的噪声。  
  
在下一步的推导展开之前，作者做了2个假设。

  
假设一是订单簿数据由三维的马尔可夫过程产生，三个静态变量分别是Mid中间价，订单不平衡程度和报价价差，这些都是由一档数据（买1卖1数据）构建的。表达式为_Ft_ = _σ_(_Mt, It, St_)。

  
Mt中间价：

![](assets/009.jpg)

  
It订单不平衡：

![](assets/010.jpg)

  
St报价价差：

![](assets/011.jpg)

  
假设二是预期的中间价格增量与中间价格本身无关，也就是每一tick变动时，价格的动态都是相同的：

![](assets/012.jpg)

  
在以上2个假设的基础上，作者用递归的方法推导出了micro price的表达式，它是一个mid price加上关于I订单不平衡和S报价价差的函数。

![](assets/013.jpg)

  
但这里有一个问题，就是即使预测出来的价格会收敛，也不能保证收敛到bid和ask之间。随后作者进一步证明了推论2，解决了这个问题，随着i的增大，micro price会收敛至特定值，也就是落在bid和ask之间：

![](assets/014.jpg)

  
  
在实证部分，作者分别选取了BAC和CVX两只代表性股票做分析，BAC和CVX有非常不同的微观结构，大部分时间BAC的报价价差是1 tick，而CVX的报价价差更大。另外，BAC中间价的变化频率远远低于CVX。

![](assets/015.jpg)

  
上面这幅图表示了不同spread和imbalance的分箱下，micro price偏离mid price的程度。mid price在两幅图中都是平行横轴的一条直线，因为mid price没有考虑订单薄不平衡，它与imbalance无关。

上图中，不管是BAC还是CVX，micro price都落在了mid price和weighted mid price之间。并且，随着不平衡度imbalance的增加，spread越大，斜率越小(比如左图中的代表2tick的红线和代表1tick的绿线，随着imbalance增加，红线的斜率走低。)，也就是说，**随着价差的扩大，订单薄失衡带来的信息量越来越少。**

BAC的价格低于CVX，因此1美分的跳价对于BAC的价格而言是一个更大的百分比，作者把类似于BAC的股票称为large tick股票，而像CVX这一类的称为small tick股票，这两只股票的特征可以代表市场上绝大部分股票。

  

## **总结下来，micro price有下面几个特点**：

###   
1.micro price是mid price「远期」预测

###   
2.可以用未来第6个中间价格的时间来近似「远期」

###   
3.micro price能适应微观结构非常不同的各类资产

###   
4.micro price与时间尺度无关

###   
5.micro price存在bid和ask之间

  

我用沥青、燃油和PTA计算了micro price，参数选择n\_imbalance = 10, n\_spread=2，绘制出来不同spread下，micro price随imbalance的变化图：  

![](assets/016.png)

![](assets/017.jpg)

![](assets/018.jpg)

_**计算过程直接用的原文作者在Github上给出的代码，地址：  
**_

_**github.com/sstoikov/microprice**_

进一步，用上面提到的三种公允价格来测试对未来价格的预测效果。以未来n个tick的mid作为真实值，以mid、wmid和micro作为预测值，分别计算真实值和预测值的RMSE。

n的取值范围：

```
n = [1,2,3,4,5,6,7,8,9,10,20,30,50,100,200,300]
```

  

代码:

```
def cal_rmse(df):
```

‍

  

**对样本外数据测试的结论：**

1、在包含所有imbalance的样本上，在预测区间小于4个tick时，wmid比micro好，在n其他的取值下，即n大于4个tick时，micro优于mid和wmid。micro引入的spread 和 imbalance的确带来了增量信息。

2、在极度不平衡的样本中(imbalance=0或imbalance=9)，wmid表现最差，其RMSE是mid和micro的几倍到十几倍。

![](assets/019.jpg)

![](assets/020.jpg)

  

**一点点思考：**

1、虽然 mid 没有考虑订单量的信息，但同时也过滤了订单量变动带来的噪音。

2、有些品种的流动性很差，很多时刻的mid price保持不变，此时的订单量变动会是噪声，这种噪声会导致micro的表现比mid差。

3、原文计算micro只用了一档数据，可以加入多档数据，对其他档的spread和imbalance进行权重衰减处理来计算micro。

4、从图像来看，micro和spread、imbalance大致呈线性关系，用线性模型来算micro应该也是可行的。

  

‍