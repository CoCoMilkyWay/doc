# 量化交易中的数据预处理：对金融时序数据重采样，新打标法和分数差分法

puppy 跟puppy玩量化 2022-12-29 20:15 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247484424&idx=1&sn=52b8750d77a5dcf2861d2ce339253425&chksm=c1128b3156dfb9df6d0bd726b08116fea86be929b1f785ad2d938d697dacf65ef4ebba58bdd1#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484424&idx=1&sn=52b8750d77a5dcf2861d2ce339253425&chksm=c1128b3156dfb9df6d0bd726b08116fea86be929b1f785ad2d938d697dacf65ef4ebba58bdd1#rd)

‍‍

这篇文章是在medium上看到的，原文地址是：  

https://towardsdatascience.com/ai-for-algorithmic-trading-rethinking-bars-labeling-and-stationarity-90a7b626f3e1

这篇文章讲的是机器学习模型建模前的金融时间序列预处理环节，文章由3个部分构成，第一部分是对bars按照新的规则重采样，第二部分提出了新的打标法——triple barrier labeling和two-step labeling，这两种打标法在lopez的书中都有介绍，第三部分介绍了fractional differentiation法，对时间序列平稳化处理的同时保留其中的记忆。

本文中的大部分灵感来自lopez de prado的书《advances in financial machine learning》，需要本书pdf版本的公众号后台回复领取。

![](assets/001.jpg)

我的翻译在保证准确严谨的前提下，尽量做到通俗易懂。现在我们进入正文部分。

**第一部分：金融事件序列数据采样新法**

我之前预测金融时间序列的方式很粗暴简单：取整个数据集，使用滑动窗口方法生成X和Y，然后把这些数据划分为历史数据和样本外数据，接下来训练机器学习模型，将X映射到Y，最后回测简单的多空策略。

但后来我逐渐发现对简单静态数据集（图像、文本、扁平数据集等等）的预测方法并不能用到金融时间序列的分析上。

一个个包含开盘价、收盘价、最高价和最低价的OHLC数据组成了金融时间序列，我们通常用时间来划分这些数据，也就形成了5min的k线、10min的K线等等。

**按时间划分的数据，作为机器学习模型的输入，有什么问题呢？**

其中最大的问题是：交易信息并不是均匀分布在每一个固定时间间隔的bar上。比如说股票市场在开盘后几小时交易量很活跃，但是中午交易量就下来了。再比如期货市场半夜交易很活跃。交易在各个时段的分布是“不均匀的”，我们就会undersample交易活跃时段的样本，oversample交易稀少时段的样本。

另外从统计学上看，按固定时间划分的bar有着非常差的统计学特征，它们呈现出较低的序列相关性，且不符合分布正态性检验。

那怎么办呢？我们用另一套规则来处理数据，不再是简单粗暴地用“时间”划分。下面是我制定的4种采样规则（参考了lopez的书）：

**tick bar：**每隔n个ticks采样一次(比如每1000次交易发生，采集一次bar)。tick bar的缺点在于订单的碎片化会引入随意性，比如我挂一个单买入10手，这个就会被记录为1个tick，但是如果我挂10个单，每单买入1手，这种情况就会被记录为10个tick。

**volume bar：**每x份资产被交易采样一次（比如每发生1000份股票交易，采集一次bar）。这种采样法比用tick采样好，除了避免上面所说的碎片化订单带来的随意性外，基于volume bar计算出来的收益率体现了更好的统计学特征（接近于独立数据高斯分布）。

**dollar bars：**每发生了Y美元交易采样一次（比如每发生100万美金的交易，采集一次bar），用成交金额采样胜过用volume和tick的采样，文中给出了两点理由。理由一：比如说我们想分析一段时间涨幅100%的股票，这只票期末卖出1000块钱的必定对应着期初1000块钱的买入，换句话说，股票交易数量符合实际价值交换的函数。

理由二：公司的行为干预（股票合并，拆股，发行新股，回购等等）会影响流通股的数量，而这种流通股数量的变动会对用tick和volume采样的方式产生干扰。而用交易金额采样就会避免这类问题。

下图是基于dollar、tick和volume采样的日均频率曲线图：

![](assets/002.jpg)

**imbalance bar：基于价格高低比例偏离预期采样**

这四种采样方式，让信息更均匀的分布在了bar上。相比于按时间机械划分的bar数据，按照新规则采样后的bar呈现出了更好的统计学性质。

我们按照上面的规则对bars重新采样，下面四副图分别是按10min时间采样的bar、按每100个tick采样的bar、按每10000次交易量采样的bar、按每100万美金交易额采样的bar。

![](assets/003.jpg)

我们来看看重采样后，这些新的bars的统计学特征：可以看到，重采样后的bars的参数表现，都比按时间划分的K线好(除了方差，无论如何方差都非常低)

![](assets/004.jpg)

## 

**第二部分：怎么正确的给数据集打标？**

  

label的方式和信息量很大程度决定了预测的效果。以前我预测的目标是：在n个bar过后，价格会怎么变化。比如说我会预测30分钟过后是上涨还是下跌，然后根据涨跌来决定开多还是空。

但是交易员们真的是这样做的吗？

在交易员们根据某个信号开了头寸后，他们在意的是在这30分钟内的情况，价格会不会触及止盈止损位？价格的波动率是怎样的情况？在一段价格的运动走势中，如果价格先打到了止损位，那很难说你能赚到后面的钱。

所以我要预测的目标变成了；我的盈亏目标位变化，这个目标位随市场波动而变化；另外我不仅要知道价格的涨跌方向，我还要知道我应该下注多少。

围绕下面三个预测目标进行label：

1.收益率的波动性

2.止盈止损目标价

3.下注的仓位大小

传统的label法是binary classification二分类，收益率＞0打上label 1, 收益率<0 打上label 0。这种打分法的缺点在于它只截取了2个点（收益率大于0和小于0的情况）而忽略了价格的运动轨迹，价格运动轨迹中包含了很多重要的信息，例如波动率，止盈和止损的点。

于是我采用了另一种打标法：triple barrier labeling三重障碍打标法。triple barrier labeling是Lopez大神在Advances in Financial Machine Learning书中对于金融预测的一种新的Labeling的方法，这种方法是设置3个障碍barrier，样本先触发哪个barrier就打上对应的标签，所以叫做triple barrier labeling。

我们想知道在接下来的N个bar上会发生什么：会不会触发止盈目标价？会不会触发止损目标价？或者价格根本不会怎么变化，所以一开始就别赌了？或者三种情况兼有之？三重障碍达标法就是对这三种情况进行标记。

![](assets/005.jpg)

三重障碍达标法具体是这样操作的：

-   如果价格先达到止盈（profit-taking）条件，那么label 1；
    
-   如果先达到止损（stop-limmit）条件，那么label -1。
    
-   什么都没有触发，label 0。
    

  

原著中的代码如下：

```
def applyPtSlOnT1(close,events,ptSl,molecule):
```

这种label法的优点是考虑了价格的变化轨迹，这和我们的交易决策紧密关联。

**那么如何确定下注多少呢？每次开多少仓位呢？**

Lopez大神给出了一种two-step labeling两步打标法。具体做法是我们先训练一个预测涨跌的模型，同时我们训练了一个预测“确定性”的模型。在第一个模型预测方向后，第二个模型会输出从 0 到 1 的值来衡量确定性——我们以第二个模型输出值作为参考下注。

例如，如果第一个模型告诉我价格会上涨，但是第二个模型告诉我上涨的确定性是 0.05，这意味着即使价格会上涨，我们很可能也不会达到止盈目标。所以这笔单子宁可不做。

**第三部分：数据的记忆和平稳性**

在我们把数据喂进机器学习模型之前，要对数据进行平稳化处理。通常的做法是对数据lag 1，也就是向后移动1个单位，我们就得到了收益率（return）。这种做法能让序列平稳，但是它有个缺陷：它消除了数据内部的记忆。

我们怎么既能得到平稳的时间序列数据，又能保留数据中的记忆呢？

一个方法是fractional differentiation分数差分法，之前我们是用lag 1处理数据，现在我们用lag 0.1，0.3和0.75来处理数据。

我们通过ADF检验来衡量多少信息得到了保留。

![](assets/006.jpg)

左图：按tick采样的bars

右图：按时间采样的bars

在这些时间序列中，fractional differentiation分数差分法并不能给我们更好的平稳性，但确实能保留数据中更多的记忆。

现在把数据喂进模型里。我用了非常简单的softmax回归作为分类算法(使用dropout进行正则化)，并使用标准化的收盘价、成交量和收益率数据作为特征，Keras中的模型是这样的:

```
main_input = Input(shape=shape, name='main_input')
```

长窗长度为100，短窗长度为50。阈值T = 0.01。数据集由ticks组成：

![](assets/007.jpg)

蓝色是训练集，黄色是验证集，绿色是测试集，线段之间的断档被称之为“embargo”，目的是让附近的数据之间不产生记忆。

**下面我们比较Fixed threshold vs volatility threshold vs triple barrier（比较固定阈值、波动率阈值和triple barrier label三重障碍打标法）。**

Fixed threshhold：我们的目标是对价格上涨/或下跌/或不超过阈值t的预测。分类报告如下(0级代表向下移动，1级代表不显著移动，2级代表向上移动):

```
                  precision    recall  f1-score   support
```

‍

精度和召回率上不平衡性很显著，分类成绩并不好。我们看看volatility threshold波动率阈值的分类评估情况。  

```
                  precision    recall  f1-score   support
```

  

分类评估指标越来越好，volatility threshold波动率阈值在精度/召回率方面没有不平衡（这说明分类器是公平的，并且随着算法本身和特征的改进，我们在准确性方面获得了提高）。

现在让我们尝试三重障碍，基于波动性在滚动 T 值处对称止盈和止损：

```
                   precision    recall  f1-score   support
```

数据进一步提升。  

下面我们比较fractional differentiation和intege differentiation，也就是前面的用lag 1处理数据还是用lag 0.2/0.3/0.75这些小于1的值处理数据。  

现在，我们用d=0.5的fractional differentiation来进行实验：

```
                   precision    recall  f1-score   support
```

volitility horizon有显著提高：

```
                   precision    recall  f1-score   support
```

最后，triple barrier打标法：

```
                 precision    recall  f1-score   support
```

至此，我们可以得出一个结论：

**fractional differentiation分数差分法是一种非常有用的方式，它可以保存原始时间序列中的更多信息**！

**结论：**

在这篇文章里，我们重构了bars，发现基于“成交量/成交金额”采样的bars比基于“时间间隔”统计特征更佳。我们还尝试了几种打标法，对止盈止损目标价和波动性打标。最后，我们尝试对时间序列平稳化处理的同时，保留其中的记忆。

放上作者的github链接：

https://github.com/Rachnog/Advanced-Deep-Trading/tree/master/bars-labels-diff