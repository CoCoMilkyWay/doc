# 私募奇葩要求，投资经理3周须开发4000个量化因子，手把手教你4行核心代码轻松应对

量化君 量化君也 2023-03-27 07:27 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c316b2b36d2f1df5b7cd65173fa337b8b793b55b5598f503e998bef6a57f4d64c8145dadb4a8#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c316b2b36d2f1df5b7cd65173fa337b8b793b55b5598f503e998bef6a57f4d64c8145dadb4a8#rd)

![](assets/001.png)

  

还记得今年年初，某知名百亿量化私募花式“压榨”员工的事件吗？

  

当时血泪控诉文在业内朋友圈和群聊里面疯传，当事人是该私募的一名投资经理（Portfolio Manager，PM），主要控诉的是这3方面：

  

（1）绩效评定不透明不合理。自己兢兢业业多年，对公司业绩有显著正向贡献，却被评定为“不合格”，绩效远差于自己的另一个PM，考核的指标却是自己的30倍+。

  

**（2）工作量巨大远超正常人范围。被评定为“不合格”后，公司对其的改进计划中，要求在3周的工作时间内提交4000个量化因子，按每周5天8小时工作制，那就是每天要入库266个因子，折合108秒一个。自己觉得无理反对后，被强行降薪降职。**

  

（3）公司不通人情，连育儿假都不准。家人病痛困扰，周岁孩儿无人照顾，向公司请假2天，公司以“专心入库因子”为由拒绝，多次沟通依然无果。

  

![](assets/002.jpg)

  

事情发生到现在已经过去2个月了，有人觉得是真的，有人觉得是纯属捏造，也有大V觉得字面真实但存在误导，总之是雾里看花、难辨真伪。

  

起初，我也是坐在小板凳上抱着吃瓜心态看的，但“3周4000个量化因子”的要求太过震撼，给我不幼小的心灵也埋下了深深的阴影，要是这般“厄运”降临到我身上，我该咋办呢？

  

于是乎，在查阅特征工程相关资料时，会特别留心因子生成工具，能助我一臂之力，短时间内挖掘出成千上万个量化因子。

  

终于，在前段时间，**我遇到了一个非常牛掰的时序数据特征自动化提取神器——tsfresh，别说3周开发4000个因子了，只要你电脑配置足够，20分钟就可以提取出8000个因子！**

  

![](assets/003.png)

  

**tsfresh实际上是一个python库，在电脑终端使用“pip install tsfresh”就可以自动安装，它最主要的功能就是能对证券价格这类型的时间序列数据自动挖掘其中的特征，并且还可以对有效特征进行筛选**，详细说明请见官网：https://tsfresh.com/。

  

特征（feature）一般是在人工智能/机器学习/深度学习领域的叫法，在量化交易/量化投资领域一般叫因子（factor），例如相对强弱指标RSI在机器学习领域就叫RSI特征，在量化选股领域就叫RSI因子，其实都是一样的东西，大伙儿注意分辨语境就好了。

  

使用tsfresh，“20分钟挖掘8000个因子”并不是吹牛，咱可以先来快速体验一下，详细原理下文再细说，在成功安装tsfresh库后，只需要以下4行核心代码（第5~8行），便可以将原有的11个基础因子，扩展到8613个因子，超额完成任务，耗时953秒，约16分钟。

  

```
import datetime
```

输出结果：

```
开始时间： 2023-03-25 20:19:29
```

  

补充说明一下，其中输入数据data是预先生成的数据（下文会说明获取方式），第1列是日期(date)，第2列是证券代码(code)，之后的11列都是因子列；特征提取之后行数少了5行，是因为设置了前面至少要有5行数据才开始提取当日特征；耗时大小跟电脑配置有关，本次试验所用的电脑处理器是第12代i7（主频2.10 GHz），电脑内存大小是16G。

  

咱不能是为了提取因子而提取因子，必定是用来做些什么的吧，那咱就可以沿着之前机器学习指数量化择时的策略思路，构建一个因子增强版的策略，整体策略思路详见之前的文章[《手把手教你，利用机器学习模型，构建量化择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&chksm=c21ba71af56c2e0c95390b450ac86bd1e3ff7af387e0d8d98d8f2a7c2bcefe8d69d2e7262035&scene=21#wechat_redirect)。

  

![](assets/004.png)

  

整个建模流程分为收集数据、准备数据、选择/建立模型、训练模型、测试模型和调节参数这6大步骤，这次咱主要是利用tsfresh库生成更多的有效因子进行建模，因此只需改变收集数据和准备数据这2个步骤，后面4个步骤与之前的文章基本一致，无须大变。

  

**Step1：收集数据**

现在开始第1个步骤，咱就来获取沪深300指数从2005年4月8日上市以来至今的全部行情数据，这里使用的是股票量化开源库qstock，“pip install qstock”安装后，基本的功能无需注册便可以使用，对萌新来说非常方便，详情请见：https://github.com/tkfy920/qstock

  

```
import qstock as qs
```

![](assets/005.png)

  

这里使用qstock获取数据只是举例，大家使用相同功能的库或API都可以，要注意的是不要带名称列，而且日期列是str格式，不是datetime格式。

  

**Step2：准备数据（本期重点）**

第2个步骤就是准备数据，生成/选取哪些特征/因子作为将来SVM模型的输入，在这里咱额外计算的因子是价格斜率（slope）、相对强弱指标（rsi）、威廉指标值（wr）、MACD快线（dif）、MACD慢线（dea）、MACD柱（macd）和抛物线指标（sar）这7个因子，再加上之前的收盘价、成交量、成交金额和换手率，一共是11个因子。

  

```
import talib
```

![](assets/006.png)

  

注意这里的行数比之前的少了33（4367->4334），那是因为在计算MACD指标时，底层需要计算EMA26并且在这基础上还要计算EMA9，期初的数据由于长度不足，指标是空值被剔除了，(26-1)+(9-1)=33，下面出现行数减少的原因也是同样的原理，不再赘述。

  

重点来了，在这里咱要基于这11个基础因子，生成8000+个因子，这里就要先说明一下tsfresh的提取特征原理了。

  

**tsfresh是对序列数据提取特征，输入一个时间序列数据就会转换为一个数值，例如输入一段时间的股价序列，那么可以转化成最大值、最小值、平均值、中位数、波峰数这样的标量数值。**

  

![](assets/007.png)

  

**如果不做特殊处理，直接把沪深300因子数据输入进去，那么它只会把每个因子序列数据转化为单个值，这样一个4334x13的因子矩阵，最终就会变为1x13的因子向量，相当于只是一个样本，这样是无法建模的。**

  

咱需要的是每个交易日都要有一个样本，这就需要用到tsfresh的滚动(roll)技术了，请看下面的变换。

  

![](assets/008.png)

```
from tsfresh.utilities.dataframe_functions import roll_time_series
```

![](assets/009.png)

  

在这个变换中，新生成了一个id列，数值是一个元组，元素1是证券代码，元素2是日期，红框中id日期表明，2005-06-08的因子计算需要用到2005-06-01、2005-06-02、2005-06-03、2005-06-06、2005-06-07和2005-06-08这6个数值组成的时间序列数据，用多长的序列数据，由参数max\_timeshift和min\_timeshift决定。

  

max\_timeshift=n表示每个交易日**最多**使用包含当日在内的n+1个数据点序列，min\_timeshift=m表示每个交易日**至少**使用包含当日在内的m+1个数据点序列，这也就说明了数据id为什么从2005-06-08开始，因为之前至少需要5个数据点，再给大伙儿换一种方式展示就清楚更多了，如下。

  

```
gg = data_roll.groupby('id').agg({'date':['count', min, max]})
```

![](assets/010.png)

  

看到这里应该就明白了，数据长度在min\_timeshift+1 ~ max\_timeshift+1之间时，有多少数据用多少数据，当超出这个范围后，就每个交易日滚动(roll)使用max\_timeshift+1个数据点的序列数据，因此原始因子数量不变，但行数被扩展为9万多行，因为部分数据被重复滚动使用。

  

**在data\_roll之上，就可以使用tsfresh的extract\_features函数在基础因子之上衍生出众多因子，这一步较为耗时，不同电脑配置执行时间不一样，须耐心等待。**

  

```
from tsfresh import extract_features
```

输出结果：

```
Feature Extraction: 100%|██████████████████████████████████████████████████████████████| 50/50 [13:11<00:00, 15.83s/it]
```

  

从结果中看出，最终得到了4329x8613的因子矩阵，4329对应着交易日数，8613对应着在11个基础因子之上衍生出来的因子数。

  

**因子生成的原理是，tsfresh预置了783个算子(calculator)，会逐个用在每一个交易日的基础因子数值序列上，这就相当于孙悟空拔一根猴毛下来，能变出783个形态各异的化身，相同计算公式不同单参数也算1个，11乘以783就是8613**，具体的算子计算公式请见官方文档：

https://tsfresh.readthedocs.io/en/latest/text/list\_of\_features.html

  

![](assets/011.png)

  

**这8613维里面都是衍生出来的因子，是不包含原始的基础因子的，记得也把基础因子添加回去。**跟以前的做法一样，也要给每个交易日的数据打上标签，每个样本标签对应的是第二个交易日的涨跌情况，计算出每个样本第二天的涨幅（pct），如果第二天上涨，则设置标签（rise）为1，反之为0。

  

```
import pandas as pd
```

  

**Step3：****选择/建立模型**

还是跟之前一样，使用SVM模型，原因和原理不再赘述，详见之前的文章[《手把手教你，利用机器学习模型，构建量化择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&chksm=c21ba71af56c2e0c95390b450ac86bd1e3ff7af387e0d8d98d8f2a7c2bcefe8d69d2e7262035&scene=21#wechat_redirect)，为了方(tou)便(lan)实现和建立模型，咱还是直接从Scikit-learn（简称sklearn）中导入，它是非常流行的Python免费机器学习库，具有各种分类、回归和聚类算法，一般配合numpy数据格式使用。

  

**Step4：****训练模型**

在这里，咱需要把整个数据集分拆为训练集和测试集，因为除了训练模型之外，咱还要留出一部分数据来验证训练出来模型的优劣。

  

一般来说，将完整数据集80%的样本作为训练集，剩余20%的样本作为测试集，要注意的是，**在这里使用tsfresh的select\_features函数对之前的8000+因子进行有效因子筛选，最终有效入选因子有200多个，这个只能在训练集上操作，不能在全部数据集上操作，否则就会变相引入“未来函数”。**

  

```
from tsfresh import select_features
```

输出结果：  

```
(3462, 247)
```

  

接下来，按照老方法将因子数据标准化后，用于模型训练，从sklearn的svm模块当中导入SVM分类器SVC，创建实例对象后，将训练集因子数据和对应标签塞进fit函数就行了，SVM模型的惩罚系数使用默认值1.0，核函数也用默认的RBF核函数。

  

```
from sklearn.svm import SVC
```

  

**Step5：测试模型**

至此，SVM分类器已经训练好了，把因子数据塞进predict函数，就能输出每个样本的预测值，咱分别把训练集和测试集的预测标签插回到原来的数据集当中，用来计算预测的准确率。

  

```
y_train_pred = classifier.predict(X_train)
```

输出结果：

```
训练集预测准确率：65.51%
```

  

光看准确率还是不够直观，咱还要看一下如果纯粹按照这个择时模型的预测结果进行投资，能获得多少收益。**假设指数可以多空交易，如果模型预测为1（上涨），第二天策略的收益率就是指数的涨幅，如果模型预测为0（下跌），第二天策略的收益率就是指数的涨幅的相反数，有了每天的日收益率之后，通过dataframe自带的累乘函数cumprod，就可以得到择时策略和沪深300指数的净值曲线**，为了方(tou)便(lan)起见，不考虑交易费率，以及按照收盘价成交。

  

```
import matplotlib.pyplot as plt
```

![](assets/012.png)

  

**Step6：调节参数**

如果你觉得预测准确率和策略收益还达不到预期，可以对每一个步骤的参数进行调整改进。

  

**就好比这次建模，跟上一次比起来，最大的不同点就是使用了不同的基础因子，还在基础因子上提取了众多的衍生因子，并且进行了有效因子筛选，训练集预测准确率从之前的57.52%提升到了65.51%，测试集预测准确率从52.35%提升到了54.62%，策略年化收益也从15.40%提高到了27.70%。**

  

这就是改进了“因子参数”的结果，你还可以调整SVM模型参数、因子标准化方法、因子中性化/正交化方法等等。

  

根据惯例，最后总结一下，本文主要目的是为了介绍时序数据特征自动化提取神器tsfresh，并结合实例说明它的使用方式，加入到之前的SVM量化择时模型后取得了明显的提升作用。

  

**tsfresh可以在短时间内，高效率帮助咱挖掘出成千上万的量化因子，虽然并不是每个因子都能有效，但足以应付“3周4000个量化因子”这种奇葩要求，先解决数量，再解决质量，如果奇葩公司继续脸都不要了，那这么低质量的脸面，也配不上高质量的因子~**

  

![](assets/013.png)

  

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484812&idx=1&sn=1697b0ff17a7e48a56ddab441cb5dd84&chksm=c21ba603f56c2f15c3ded82ee3bf59027a997b25cf22535045743b6860b12fbfa379c54d5f04&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484822&idx=1&sn=39ac52116f314f52f8adb090e6dba782&chksm=c21ba619f56c2f0f6ba71de6526e7fe916088b9a18402ab09f27d01d003a459cc7b59755969b&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/014.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/015.png)