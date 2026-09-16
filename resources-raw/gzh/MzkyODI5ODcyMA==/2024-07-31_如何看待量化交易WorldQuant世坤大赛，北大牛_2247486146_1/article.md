# 如何看待量化交易WorldQuant世坤大赛，北大牛人提交了6万+因子？

量化君 量化君也 2024-07-31 21:58 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486146&idx=1&sn=42d02994bfcacce0d98cacb9cfe90e27&chksm=c307a8e8787c997e7c7185fe8af1da088eca2abf71bf1dd02fb81f8c0fff957013be5f9b499b#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486146&idx=1&sn=42d02994bfcacce0d98cacb9cfe90e27&chksm=c307a8e8787c997e7c7185fe8af1da088eca2abf71bf1dd02fb81f8c0fff957013be5f9b499b#rd)

![](assets/001.png)

  

最近逛知乎，碰到了这个问题：**如何看待量化交易WorldQuant世坤大赛北大牛人提交了6万+因子？**

  

![](assets/002.jpg)

  

我的第一直觉，这肯定不是纯手工挖出来的，6w个因子，一天挖一个，节假日都不休息的话，需要164年，一个小时挖一个的话，也需要7年，一分钟一个，需要42天。

  

这明显不是一个纯人工手工的速度，麒麟臂也不行，肯定是有机器参与了，除非这个北大学子也是个少爷，雇了100来人，每个人搞来几百个因子就行了。

  

**如果可以用机器，只注重因子数量的话，短时间内挖6w+因子也不是什么难事，量化小白也可以做到，本来这方法是我之前给PM支招对付恶毒私募那种3周要挖4000因子的要求，核心代码只有4行，虽然因子质量不一定能保证，但因子数量绝对是足斤足两的，我刚才试了一下，挖6w+因子，一共花了不到3个小时。**

  

不藏着掖着，**这个牛掰的量化因子自动挖掘神器就是**tsfresh**，只要你基础因子和电脑配置足够，真的是想挖多少就挖多少。**

  

![](assets/003.png)

  

tsfresh实际上是一个python库，在电脑终端使用“pip install tsfresh”就可以自动安装，它最主要的功能就是能对证券价格这类型的时间序列数据自动挖掘其中的特征，并且还可以对有效特征进行筛选，详细说明请见官网：https://tsfresh.com/。

  

特征（feature）一般是在人工智能/机器学习/深度学习领域的叫法，在量化交易/量化投资领域一般叫因子（factor），例如相对强弱指标RSI在机器学习领域就叫RSI特征，在量化选股领域就叫RSI因子，其实都是一样的东西，大伙儿注意分辨语境就好了。

  

废话不多说，咱可以先来快速体验一下挖6w+因子，详细原理下文再细说，在成功安装tsfresh库后，只需要以下4行核心代码（第5~8行），**便可以将原有的84个基础因子，扩展到65772个因子，耗时9730秒，约2.7小时。**

  

```
import datetime
```

输出结果：

```
开始时间： 2024-07-30 23:10:01
```

  

补充说明一下，其中输入数据data是预先生成的数据（下文会说明获取方式），第1列是日期(date)，第2列是证券代码(code)，之后的84列都是因子列；特征提取之后行数少了5行，是因为设置了前面至少要有5行数据才开始提取当日特征；耗时大小跟电脑配置有关，本次试验所用的电脑处理器是第12代i7(主频2.10 GHz)，电脑内存大小是32G。  

  

咱不能是为了提取因子而提取因子，必定是用来做些什么的吧，那咱就可以沿着之前机器学习指数量化择时的策略思路，构建一个因子增强版的策略，整体策略思路详见之前的文章[《手把手教你，利用机器学习模型，构建量化择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&chksm=c21ba71af56c2e0c95390b450ac86bd1e3ff7af387e0d8d98d8f2a7c2bcefe8d69d2e7262035&scene=21#wechat_redirect)。

  

![](assets/004.png)

  

整个建模流程分为收集数据、准备数据、选择/建立模型、训练模型、测试模型和调节参数这6大步骤，这次咱主要是利用tsfresh库生成更多的有效因子进行建模，因此只需改变收集数据和准备数据这2个步骤，后面4个步骤与之前的文章基本一致，无须大变。

  

由于一次性同时挖掘6w+因子耗时就不说了，还非常吃内存，我自己这台32G内存的老机子都差点儿扛不下来，因此为了照顾到更多的小伙伴能跑通程序，建模的时候使用的是8k+因子，但同时也会说明如何升级到6w+因子。

  

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

  

注意这里的行数比之前的少了33（4694->4661），那是因为在计算MACD指标时，底层需要计算EMA26并且在这基础上还要计算EMA9，期初的数据由于长度不足，指标是空值被剔除了，(26-1)+(9-1)=33，下面出现行数减少的原因也是同样的原理，不再赘述。  

  

重点来了，在这里咱要基于这11个基础因子，生成8k+个因子，这里就要先说明一下tsfresh的提取特征原理了。

  

**tsfresh是对序列数据提取特征，输入一个时间序列数据就会转换为一个数值，例如输入一段时间的股价序列，那么可以转化成最大值、最小值、平均值、中位数、波峰数这样的标量数值。**

  

![](assets/007.png)

  

**如果不做特殊处理，直接把沪深300因子数据输入进去，那么它只会把每个因子序列数据转化为单个值，这样一个4661x13的因子矩阵，最终就会变为1x13的因子向量，相当于只是一个样本，这样是无法建模的。**

  

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

  

看到这里就应该明白了，数据长度在min\_timeshift+1 ~ max\_timeshift+1之间时，有多少数据用多少数据，当超出这个范围后，就每个交易日滚动(roll)使用max\_timeshift+1个数据点的序列数据，因此原始因子数量不变，但行数被扩展为9万多行，因为部分数据被重复滚动使用。  

  

**在data\_roll之上，就可以使用tsfresh的extract\_features函数在基础因子之上衍生出众多因子，这一步较为耗时，不同电脑配置执行时间不一样，须耐心等待。**

  

```
from tsfresh import extract_features
```

输出结果：

```
Feature Extraction: 100%|██████████████████████████████████████████████████████████████| 50/50 [14:50<00:00, 17.81s/it]
```

  

从结果中看出，最终得到了4656x8613的因子矩阵，4656对应着交易日数，8613对应着在11个基础因子之上衍生出来的因子数。

  

**因子生成的原理是，tsfresh预置了783个算子(calculator)，会逐个用在每一个交易日的基础因子数值序列上，这就相当于孙悟空拔一根猴毛下来，能变出783个形态各异的化身，相同计算公式不同单参数也算1个，11乘以783就是8613**，具体的算子计算公式请见官方文档：

https://tsfresh.readthedocs.io/en/latest/text/list\_of\_features.html

  

![](assets/011.png)

  

**看到这里，挖出6w+因子的原理就很明显了，60000 / 783 ≈ 77，只需要有77个基础因子，就能衍生出6w个因子，只需要将之前生成11个基础因子的部分，替换为以下代码，就可以生成84个基础因子，能衍生出65772个因子，开头2.7小时挖6w+因子的试验就是用这个方法。**

  

```
import talib
```

  

大致的原理是，使用价格斜率（slope）、相对强弱指标（rsi）、威廉指标值（wr）、均幅指标（atr）、平均趋向指标（adx）、MACD快线（dif）、MACD慢线（dea）和MACD柱（macd）这8个指标，每个指标都分别使用10个不同的参数，那就是80个不同的因子，再加上之前的收盘价、成交量、成交金额和换手率，一共是84个因子。这是一种偷懒的写法，大伙儿别学我，根据自己的实际需要加入基础因子哈

  

说回正题，这8613维里面都是衍生出来的因子，是不包含原始的基础因子的，记得也把基础因子添加回去。跟以前的做法一样，也要给每个交易日的数据打上标签，每个样本标签对应的是第二个交易日的涨跌情况，计算出每个样本第二天的涨幅（pct），如果第二天上涨，则设置标签（rise）为1，反之为0。

  

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
(3724, 242)
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
训练集预测准确率：65.01%
```

  

光看准确率还是不够直观，咱还要看一下如果纯粹按照这个择时模型的预测结果进行投资，能获得多少收益。**假设指数可以多空交易，如果模型预测为1（上涨），第二天策略的收益率就是指数的涨幅，如果模型预测为0（下跌），第二天策略的收益率就是指数的涨幅的相反数，有了每天的日收益率之后，通过dataframe自带的累乘函数cumprod，就可以得到择时策略和沪深300指数的净值曲线**，为了方(tou)便(lan)起见，不考虑交易费率，以及按照收盘价成交。

  

```
import matplotlib.pyplot as plt
```

![](assets/012.png)

  

**Step6：调节参数**

如果你觉得预测准确率和策略收益还达不到预期，可以对每一个步骤的参数进行调整改进。

  

**就好比这次建模，跟原始版SVM择时模型比起来，最大的不同点就是使用了不同的基础因子，还在基础因子上提取了众多的衍生因子，并且进行了有效因子筛选，训练集预测准确率从之前的57.23%提升到了65.01%，测试集预测准确率从48.34%提升到了52.42%，策略年化收益也从-5.98%提高到了18.34%。**

  

_原始版SVM择时模型测试集的策略净值_

![](assets/013.png)

  

这就是改进了“因子参数”的结果，你还可以调整SVM模型参数、因子标准化方法、因子中性化/正交化方法等等。

  

\~~~~~~建模结束分割线~~~~~~

  

**荀子的《劝学》中有云：君子性非异也，善假于物也。有些事情看上去很牛掰，也许只是善于利用工具的缘故罢了，你会用了，你也可以很牛掰，10w+因子都不在话下。**

  

★

往期回顾

  

★

  

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486038&idx=1&sn=29f610e83c0939e2108348afeecef8af&chksm=c21ba9d9f56c20cffe19a582ae5674b9fa86d8c8659061482a699421e3672376735668763c4c&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486041&idx=1&sn=cf9709ae26edbd8e7fbc52dbb571293b&chksm=c21ba9d6f56c20c0fe3a0b83cd64b6c787ad37ed76d8ee909dc73d9d36f6bce49f215604e25b&scene=21#wechat_redirect)

  

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[黄金价格预测](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c21ba9dff56c20c92e3a08ee170b20dc411112fa12a8f89f55ae70450000e25614174a7a22bf&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

  

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

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect) [五穷六绝](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c21ba916f56c200088c4aceda6e62511469cff0d18af97fa48b659fc6ac3862d494f02fd38a6&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/014.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/015.png)