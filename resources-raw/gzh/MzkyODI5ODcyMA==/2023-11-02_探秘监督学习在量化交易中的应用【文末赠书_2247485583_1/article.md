# 探秘监督学习在量化交易中的应用【文末赠书】

罗勇 量化君也 2023-11-02 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485583&idx=1&sn=c628e2f19a6add3e7d986c7464b36911&chksm=c353e6938f1757ecd0768e66cef3a8942a6fb6e2d3854d90919c6ee3349561ed0ed0ad0b58d6#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485583&idx=1&sn=c628e2f19a6add3e7d986c7464b36911&chksm=c353e6938f1757ecd0768e66cef3a8942a6fb6e2d3854d90919c6ee3349561ed0ed0ad0b58d6#rd)

  

![](assets/001.png)

  

**在机器学习领域，监督学习是一种很重要的学习模式。**它指的是我们在数据有正确标签的情况下建立模型，并通过这一正确标签让模型进行自我修正，使其预测结果不断地朝着正确的方向迈进。

以解决信用卡欺诈问题为例，我们通过历史数据搭建模型以区分违约用户和信用良好的用户。那么在历史数据中，我们不光要知道用户的收入水平、家庭情况等特征信息，还要知道每个用户对应的标签信息，即在当前特征下，用户的标签是违约用户还是信用良好的用户。根据这些特征信息和标签信息所构建的分类模型，就属于监督学习模型。在使用监督学习构建量化交易策略时，我们同样可以采用这种思路，除每只股票的基本信息外，还要对历史数据中过去一段时间内股票的收益从大到小排序。将排名靠前、未来有较大概率表现好的股票记为“上涨股”，将其余的股票记为“非上涨股”，从而进行有监督的机器学习。

上述划分“上涨股”和“非上涨股”的过程就是监督学习中很重要的一步——提取标签**。**如下图所示，在监督学习建模的一般流程中，我们首先需要从所有可获取的数据源中拉取所需原始数据。获取完数据后，根据实际的建模需求确定并提取标签。接下来，将获得的原始数据进行清洗和加工，剔除脏数据，提取有效特征。紧接着，将加工好的数据输入搭建的模型中进行训练，根据模型评估指标表现的好坏不断地调节模型参数。最后，选择表现最好的模型存储，用它来开展后续的预测工作。

  

![](assets/002.png)

  

监督学习的一般流程

  

**Step1 数据获取**

**数据获取是机器学习建模的第一步**，也是至关重要的一步。建模的根本目的是从历史数据中发现有价值的信息，以此来推演未来，帮助我们在解决实际问题时作出更好的决策。因此，越是丰富的优质数据，越能为我们提供更多的有效信息。常规的行情、财务数据可以通过一些标准化的数据库或者数据接口获取，如雅虎财经、新浪财经、万得等。除此之外，还可以尝试借助爬虫技术获取互联网上的舆情信息。数据的获取应根据实际的建模目标展开，即应尽可能地围绕着最终的模拟方向寻找满足我们需求的数据。

**Step2 数据预处理**

收集完数据后，获取的数据往往来自不同的数据源。由于来自标准化数据库或者数据接口的数据可能是已经被清洗、整理好的数据，而现实中来自不同数据源的原始数据通常会出现缺失值、无效值及以不同标准表示同一变量等问题。所以我们需要评估获取到的数据，识别数据质量或结构中出现的任何问题，通过**修改、替换或删除数据等方式来清理、加工数据**，以确保处理后的数据集符合后续的机器学习要求。

**Step3 特征工程**

被清洗干净且结构统一的数据是特征工程能成功进行的前提。在完成对数据的预处理之后，就可以展开特征工程部分的实践。特征工程主要是从原始数据中提取、创造输入机器学习模型的特征值，用来在提高模型精度的同时加速训练过程。

为达到满意的建模效果，**特征工程往往是一个循环往复的过程。**我们可以根据模型的训练效果，不断地修改、添加或删除部分特征。因此，特征工程是机器学习中最耗时和乏味的，但同时也是最具有创造性和“乐趣”的一部分。在这一过程中，具有投资方面专业知识的人士可以大放异彩，充分利用自己的专业知识从繁杂的原始数据中提取有价值的特征。

特征工程是一项具有创造性的工作，因而在多数情况下没有特殊的限制，可以让大家充分发挥自己的才能。但**在量化交易领域，我们通常还是需要保证自己构造的特征不会向后窥探，包含记录创建时刻之后的信息。**如使用整个时间段的平均值或者标准差来标准化数据时，往往会隐晦地将未来的信息泄露到我们创建的特征中。下面，我们将总结一些常用的处理方法，使用示例数据提供代码样例，方便大家根据需要选择合适的代码片段。

```
……
```

如下图所示，为监督学习特征工程。

![](assets/003.png)

监督学习特征工程

**①特征变换**

很多时候，成交量、市值、收益等特征会出现数据倾斜，大多数数据都集中在某一范围内，数据尾部拖曳很长，且尾部数据点的数值很大。而一些机器学习模型，如线性回归模型，会假设输入的变量数据是服从正态分布的。因此，我们需要应用一定的变换技巧，使倾斜的数据服从正态分布，以提高模型的表现能力。

参考代码如下所示：

```
# 对成交量进行对数变换
```

**②特征缩放**

特征缩放可以消除特征间量纲的影响，使不同维度的特征被放在一起比较，从而大大提高模型的准确性。除了树模型，多数监督学习模型均需要进行特征缩放。常见的缩放方法有：标准化、归一化、最大最小值归一化、稳健归一化等。以标准化特征缩放为例，我们可以简单地定义一个 lambda 函数，并在任何需要进行特征缩放的地方应用该函数。

参考代码如下所示：

```
……python 
```

在上述标准化的过程中有一点非常值得注意，我们定义了一个可以对每只股票分组应用的 lambda 函数。在 lambda 函数中，我们应用了滑动时间窗口这一技巧，使用当前记录时刻前 100 天的数据来计算该区间内的平均值和标准差，从而可以有效地避免向后窥探数据。

**③技术分析指标**

在挖掘特征的过程中，拥有量化经验的专业人士可能想根据需要添加一些股票、期货交易中的常用技术分析指标因子。实际操作中，可以根据情况自行编写代码计算相关分析因子，也可以借助开源的金融量化库。受大家喜爱的 TA 库(TechnicalAnalysis Library)就可以帮助我们在金融时间序列数据集（开盘、收盘、高、低、交易量）中进行特征工程。

参考代码如下所示：

```
……python 
```

**④其他表述形式**  

根据选择模型的需要，对一些常见的特征表述形式进行处理，如进行数据分箱，将连续数值转换为离散的类别变量，或者用独热编码、序号编码等编码格式对月份、星期等类别变量做处理。

参考代码如下所示：

```
……python 
```

  

**Step4** **模型训练**

完成特征加工后，我们就获得了模型的输入部分，可以据此开始构建量化模型。前面我们描述了通过划分“上涨股”和“非上涨股”来提取标签的过程，如此时待预测的标签为类别变量，就可以搭建一个分类模型来预测股票会上涨还是下跌。如果模型的标签是连续的数值型变量，比如直接预测股票的价格或是股票具体涨了多少，我们就可以**采用回归模型来进行预测。**如下图所示，为监督学习常用模型思维导图。

![](assets/004.png)

监督学习常用模型思维导图

  

根据学习目标的不同，首先确定**要构建分类模型还是回归模型。**而后考虑到具体的学习任务中，样本和特征个数的不同，以及各模型在不同应用场景中表现性能的差异，再进一步确定适合实际应用场景的模型进行建模。一般来说，当数据量较少、开发的特征数量较多时，我们倾向于选择高偏差、低方差的模型，如线性回归模型、朴素贝叶斯模型、逻辑回归模型，以及核函数为线性的支持向量机模型。而当遇到数据量较大、特征较少的数据集时，选择低偏差、高方差的模型通常会表现更好，如决策树模型、支持向量机模型、神经网络模型等。除此之外，挑选可用模型时，往往还需要考虑实际计算资源，涉及业务场景时的模型可解释性，以及模型对异常数据的敏感度等方面。

划定可用的模型范围后，可以从最简单的模型开始尝试。如果经过优化后，模型已经满足实际需求，那么即可采用该模型。或者也可以多选择几个模型，最后在计算效率、测试效果等诸多方面的比较下挑选最合适的模型。在建模过程中，为了确定模型的最优参数组合、查看模型的实际表现效果，通常需要将数据集划分为训练集、验证集和测试集。通过训练集训练模型，用验证集确定合适的模型参数，最后在测试集上查看模型最终的模拟效果。相比于其他的机器学习建模，如果构建的量化模型是回归模型，又由于市场交易具有时序性，那么目前常规的方法就是按照时间来划分数据集，避免数据集向后窥探，泄露未来信息。

回到实际的模型开发过程中，对于上述数据集划分、模型构建及寻找最优的模型参数组合，我们均可以利用相应的机器学习语言库进行开发。如前面罗列的大部分监督学习模型，相应开发环节都可以通过调用 Scikit-Learn 库相关的 API 接口实现。除此之外，一些被广泛应用、表现良好的集成模型，如 LightGBM、XGBoost 等也可以找到相应的 Python 开源框架。在这里，我们延续前文所述的分类思路，搭建一个分类模型，**根据前 10 天的每只股票的收益情况，预测后 10 天收益排名前 200 的股票。**

这里筛选出了在 2022 年 1 月 1 日前上市的 4639 只股票，将训练数据集的起始日期设为 2018 年 1 月 1 日，测试日期设为 2020 年 1 月 1 日至 2022 年 3 月 1 日。计算\[ (t+2 天的收盘价)−(t+1 天的收盘价)\]/(t+1 天的收盘价)作为每只股票第 t 天的收益，将前 10 天的每日收益作为输入特征，累加上后 10 天的每日收益，随后将后 10 天收益排在前 200 的股票计为“上涨股票”，将其余的股票计为“非上涨股票”。此部分参考代码所用的行情数据 stock\_data 变量同样采用前文所述的 tushare 接口获取，获取代码不再复述。

参考代码如下所示：

```
……python 
```

  

**Step5 模型选择**

模型选择涉及 2 个方面：一方面，在构建模型的过程中会涉及一些模型参数，我们要选择当前模型表现最优时的参数组合；另一方面，如果搭建了多个模型，我们就需要选择模拟效果最好的模型作为最终模型。

这就需要我们客观、真实地评估自己搭建的模型。对量化模型的评估通常可以从 2 个方面展开：一是可以通过模型在测试集上的表现来评估，回归模型可以采用均方误差来衡量，分类模型则可使用分类的正确率、召回率、AUC 等指标来衡量；二是可以通过模型构建的策略组合的实际收益情况来进行评价。下面我们将此次分类模型预测股票的平均收益情况与所有股票收益的均值做了对比，可以看出随着时间的推移，预测结果的收益情况较基线收益还是存在较为显著的提升的。

参考代码如下所示：

```
……python 
```

如下图 所示，为模型预测累计收益与基线收益的对比情况。

![](assets/005.png)

模型预测累计收益与基线收益对比图

  

最后给大家推荐一本新书：

**《GPT时代的量化交易：底层逻辑与技术实践》**

以下是**新书完整目录**，可以去看一看，有没有您感兴趣的章节。

![](assets/006.jpg)

这本书非常适合对量化交易感兴趣的广大投资者，尤其适合希望转型量化交易的程序员参考阅读。这本书可以帮你深入解析量化交易的底层逻辑。掌握多维度剖析量化交易的五种策略。并给出了相应的实战案例及代码，初步探索了运用GPT来实现其逻辑的技术路径，从理论到实践，助你轻松上手量化交易。  

![](assets/007.png)

  

为了感谢大伙儿长久以来的关注和支持，**本公众号『量化君也』将送出5本《GPT时代的量化交易：底层逻辑与技术实践》纸质书给大家**，也不整公众号抽奖关注引流涨粉那些套路，就是直接抽，全凭在座各位的手气~

  

扫描下方二维码直接参与书籍抽奖！

  

![](assets/008.png)

  

**开奖时间**：**2023年11月5日(周日) 18:00**

  

**领奖方式**：中奖者请添加公众号官方微信：**quantman01**，备注【获奖者】，添加好友发送中奖截图信息核实后，便会安排纸质书寄送事宜。

  

Good luck to you~

  

**感谢『**电子工业出版社**』给本公众号打call，以下是书籍出版社官方旗舰店链接，感谢大伙儿对好书的鼓励与支持！Salute！！**

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485155&idx=1&sn=2c3159534dc114e97eaad77959dfe558&chksm=c21ba56cf56c2c7a6082a275be18cbb41ffdc173bfdd2b3459de6df13161c6ea419a4818056e&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485157&idx=1&sn=6b7f381f57b651b4df8e7b384e43400f&chksm=c21ba56af56c2c7cb15a3c7d66d6df27c41f714ad00a8f681fa8697be51b692dd48df9a69511&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect) [量化砸盘](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485487&idx=1&sn=dcf8ca1e44357071363ca63daca0f270&chksm=c21baba0f56c22b6b352b30d7e5bb21f523f4268eb1edaec0ff4b3472199a5432beb920f505f&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/009.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/010.png)