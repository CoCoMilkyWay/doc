# 新拿到一批时序数据可以做哪些分析？

Prabhakaran 量化前沿速递 2023-09-07 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486733&idx=1&sn=396e0c011ead7209d1734ca7ec124e83&chksm=c3a3790b5a9bac1b382326783a510120b30315ae97b9ab386761a0fa48118b4f729ee6d83020#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486733&idx=1&sn=396e0c011ead7209d1734ca7ec124e83&chksm=c3a3790b5a9bac1b382326783a510120b30315ae97b9ab386761a0fa48118b4f729ee6d83020#rd)

    **点击****蓝字**  

关注我们

**#TSer****#**

对时间序列数据进行分析在很多工业场景里都能遇到。依赖于观测值的频率，典型的时间序列可分为每小时、每天、每周、每月、每季度和每年为单位记录。有时，你可能也会用到以秒或者分钟为单位的时间序列，比如，每分钟用户点击量和访问量等等。

  

分析时间序列数据非常重要，因为它是你做序列预测前的必不可少的准备过程。理解序列本质的方方面面可以帮助你更好地了解如何做出有意义并且精确的预测。

  

那么，具体该如何操作呢？本文将为大家简要介绍。点击原文获取英文博客原址。

  

![](assets/001.gif)

**1**

**如何在Python中导入时间序列？**

所以怎样导入时间序列数据呢？典型的时间序列数据以.csv格式或者其他表格形式存储，包括两列：日期和测量值。

  

让我们用pandas包里的read.csv()读取时间序列数据（一个澳大利亚药品销售的csv文件）作为一个pandas数据框。加入parse\_dates=\[‘date’\]参数将会把日期列解析为日期字段。

```
from dateutil.parser import parse
```

![](assets/002.jpg)

此外，你也可以将其导入为date作为索引的pandas序列。你只需要固定pd.read\_csv()里的index\_col参数。

```
ser = pd.read_csv('https://raw.githubusercontent.com/selva86/datasets/master/a10.csv', parse_dates=['date'], index_col='date')
```

![](assets/003.jpg)

  

注意，在此序列当中，‘value’列的位置高于date以表明它是一个序列。

  

  

**2**

**什么是面板数据？**

面板数据也是基于时间的数据集。差异在于，除了时间序列，它也包括同时测量的一个或多个相关变量。通常来看，面板数据当中的列包括了有助于预测Y的解释型变量，假设这些列将在未来预测阶段有用。

  

面板数据的例子如下：

  

```
# dataset source: https://github.com/rouseguy
```

![](assets/004.jpg)

  

  

**3**

**时间序列可视化**

让我们用matplotlib来对序列进行可视化。

```
# Time series data source: fpp pacakge in R.
```

![](assets/005.jpg)

  

因为所有的值都是正值，你可以在Y轴的两侧进行显示此值以强调增长。

```
# Import data
```

  

![](assets/006.jpg)

  

因为这是一个月度时间序列，每年遵循特定的重复模式，你可以把每年作为一个单独的线画在同一张图上。这可以让你同时比较不同年份的模式。

  

**4.1 时间序列的季节图**

```
# Import Data
```

![](assets/007.jpg)

药品销售的季节图  

  

如上图所示，每年二月会迎来药品销售的急速下降，而在三月会再度上升，接下来的4月又开始下降，以此类推。很明显，该模式在特定的某一年中重复，且年年如此。

  

然而，随着年份推移，药品销售整体增加。你可以很好地看到该趋势并且在年份箱线图当中看到它是怎样变化的。同样地，你也可以做一个月份箱线图来可视化月度分布情况。

  

**4.2 月度（季节性）箱线图和年度（趋势）分布**

  

你可以季节间隔将数据分组，并看看在给定的年份或月份当中值是如何分布的，以及随时间推移它们是如何比较的。

```
# Import Data
```

  

![](assets/008.jpg)

  

箱线图将年度和月度分布变得很清晰。并且，在阅读箱线图当中，12月和1月明显有更高的药品销售量，可被归因于假期折扣季。  

  

到目前为止，我们已经看到了识别模式的相似之处。现在怎样才能从通常模式当中找到离群值呢？

  

  

**4**

**时间序列的模式**

任何时间序列都可以被分解为如下的部分：**基线水平+趋势+季节性+误差。**

  

当在时间序列当中观测到增加或降低的斜率时，即可观测到相应的趋势。然而季节性只有在由于季节性因素导致不同的重复模式在规律性的间隔之间被观测到时才能发现。可能是由于当年的特定月份，特定月份的某一天、工作日或者甚至是当天某个时间。

  

然而，并不是所有时间序列必须有一个趋势和/或季节性。时间序列可能没有不同的趋势但是有一个季节性。反之亦然。

  

所以时间序列可以被看做是趋势、季节性和误差项的整合。

```
fig, axes = plt.subplots(1,3, figsize=(20,4), dpi=100)
```

  

![](assets/009.jpg)

  

另一个需要考虑的方面是循环的行为。当序列当中上升和下降模式并不在固定的日历间隔出现时，就会出现循环的行为。需注意不要混淆循环的效应和季节的效应。  

  

**所以，怎样区分循环的和季节性的模式呢？**

  

如果模式不是基于固定的日历频率，那它就是循环的。因为，循环效应不像季节性那样受到商业和其他社会经济因素的影响。

  

  

**5**

**时间序列的加法和乘法**

基于趋势和季节性的本质，时间序列以加法或乘法的形式建模，其中序列里的每个观测值可被表达为成分的和或者积：

  

**加法时间序列**：值=基线水平+趋势+季节性+误差

**乘法时间序列**：值=基线水平\*趋势\*季节性\*误差

  

  

**6**

**怎样分解时间序列的成分？**

你可以通过将序列作基线水平，趋势，季节性指数和残差的加法或乘法组合来实现一个经典的时间序列分解。

  

statsmodels包里的seasonal\_decompose使用起来非常方便。

```
from statsmodels.tsa.seasonal import seasonal_decompose
```

![](assets/010.jpg)

  

在序列开始时，设置extrapolate\_trend='freq' 来注意趋势和残差中缺失的任何值。如果你仔细看加法分解当中的残差，它有一些遗留模式。乘法分解看起来非常随意，这很好。所以理想状况下，乘法分解应该在这种特定的序列当中优先选择。

  

趋势，季节性和残差成分的数值输出被存储在result\_mul 当中。让我们提取它们并导入数据框中。

```
# Extract the Components ----
```

  

如果你检查一下seas, trend 和 resid列的乘积，应该确实等于actual\_values。  

  

  

**7**

**怎样将时间序列去趋势化？**

对时间序列去趋势就是从时间序列当中移除趋势成分。但是如何提取趋势呢？有以下几个方法：  

1.  从时间序列当中减去最优拟合线。最佳拟合线可从以时间步长为预测变量获得的线性回归模型当中获得。对更复杂的模型，你可以使用模型中的二次项（x^2）；
    
2.  从我们之前提过的时间序列分解当中减掉趋势成分；
    
3.  减去均值；
    
4.  应用像Baxter-King过滤器(statsmodels.tsa.filters.bkfilter)或者Hodrick-Prescott 过滤器 (statsmodels.tsa.filters.hpfilter)来去除移动的平均趋势线或者循环成分。
    

  

让我们来用一下前两种方法。

```
# Using scipy: Subtract the line of best fit
```

![](assets/011.jpg)

  

通过减去最小二乘拟合来对时间序列去趋势化

```
# Using statmodels: Subtracting the Trend Component.
```

![](assets/012.jpg)

  

  

**8**

**怎样将时间序列去季节化？**

这里有多种方法对时间序列去季节化。以下就有几个：

1.  取一个以长度为季节窗口的移动平均线。这将在这个过程中使序列变得平滑；
    
2.  序列季节性差分（从当前值当中减去前一季节的值）；
    
3.  将序列值除以从STL分解当中获得的季节性指数。
    

  

如果除以季节性指数后仍没办法得到良好的结果，再试一下序列对数转换然后再做。你之后可以通过去指数恢复到原始尺度。

```
# Subtracting the Trend Component.
```

![](assets/013.jpg)

  

  

**9**

**怎样检验时间序列的季节性？**

常见的方法是绘制序列并在固定的时间间隔内检查可重复的模式。所以，季节性的类型由钟表或日历决定：  

-   一天的每个小时
    
-   一月的每天
    
-   每周
    
-   每月
    
-   每年
    
-   ...
    

  

然而，如果你想要一个更权威的季节性检验，使用自回归函数（ACF）图。更多关于自回归的信息将在下一部分介绍。但是当强季节性模式出现时，ACF图通常揭示了在季节窗的倍数处明显的重复峰值。

  

例如，药品销售时间序列是每年都有重复模式的一个月度序列。所以，你可以看到第12,24和36条线等的峰值。

```
from pandas.plotting import autocorrelation_plot
```

![](assets/014.jpg)

除此之外，如果你想做统计检验，CHT检验可以检验季节性差异是否对序列平稳化有必要。

  

  

**10**

**怎样估计时间序列的预测能力？**

时间序列越有规律性和重复性的模式，越容易被预测。“近似熵”可用于量化时间序列波动的规律性和不可预测性。近似熵越高，预测越难。

  

另一个更好的选项是“样本熵”。样本熵类似与近似熵，但是在估计小时间序列的复杂性上结果更一致。例如，较少样本点的随机时间序列 “近似熵”可能比一个更规律的时间序列更低，然而更长的时间序列可能会有一个更高的“近似熵”。

  

样本熵可以很好地处理这个问题。请看如下演示：

```
# https://en.wikipedia.org/wiki/Approximate_entropy
```

  

  

**11**

**如何得知一个时序有助于预测另一个时序？**

Granger因果检验被用于检验是否一个时间序列可以预测另一个序列。Granger因果检验是如何工作的？  

  

它基于如果X引起Y的变化，Y基于之前的Y值和之前的X值的预测效果要优于仅基于之前的Y值的预测效果。所以需要了解Granger因果检验不能应用于Y的滞后量引起Y自身的变化的情况，而通常仅用于外源变量（不是Y的滞后量）。

  

它在statsmodel包中得到了很好的实现。它采纳2列数据的二维数组作为主要参数，被预测值是第一列，而预测变量（X）在第二列。

  

零假设检验：第二列的序列不能Granger预测第一列数据。如果p值小于显著性水平（0.05），你可以拒绝零假设并得出结论：X的滞后量确实有用。

  

第二个参数maxlag决定有多少Y的滞后量应该纳入检验当中。

  

```
from statsmodels.tsa.stattools import grangercausalitytests
```

  

在上述例子当中，实际上所有检验的p值只能无限接近于0。所以“月份”实际上可以用于预测航空乘客的数量。

  

  

![](assets/015.gif)

**点击下方链接关注时序人**

**欢迎投稿** 

**转载请联系作者**

**往期推荐阅读**

  

# [ICML 2022 | 用于时间序列预测的指数平滑 Transformer](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490491&idx=1&sn=c480bea4fc5bd613790af6a4dc9d9bbc&chksm=ceceee4ef9b9675805ba967ed6b434c94ad7550ca443756948d9cae5965516b3a65da053e3ed&scene=21#wechat_redirect)

[AAAI 2022 | 一种支持任意场景下时序表征学习的模型 TS2Vec](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490464&idx=1&sn=6e511f10fa30e29c969de6be1bf67c14&chksm=ceceee55f9b96743f05dfc5ab410a86234f84192e0e5ed53ad761d8b050eff29a3d99179cf06&scene=21#wechat_redirect)

[KDD 2022 | 推荐系统中的通用序列表征学习](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490148&idx=1&sn=50d9c341e59cc62a49b8a4515410e035&chksm=ceceef91f9b966872ba94a2a5171fe88f668542dfe69e8e8ff022607153e8bcc251defb203f0&scene=21#wechat_redirect)  

[KDD 2022 | 脑电AI助力癫痫疾病诊断](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490037&idx=1&sn=8e07e6b685bdbc357a544a14bfdf296a&chksm=ceceec00f9b96516d111d40e68630ae52a2d41cae64c612744cb7e6b49309081c92cc2483ad3&scene=21#wechat_redirect)

[ICLR 2022 | Pryaformer 工业级长时序预测](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247489786&idx=1&sn=d81a8ecb166663aa6775a2ebdabe2a7a&chksm=ceceed0ff9b96419715f40c0428201551904ce789d29c5f06d57c3cea2c91446f28f408dac14&scene=21#wechat_redirect)

[NeurIPS 2021 | 微观特征混合进行宏观时间序列预测](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247488937&idx=1&sn=95a81055a7f8b99dca783f23edf169d4&chksm=cecee05cf9b9694af885c911f65f5289b5e443fd68193ee3490bcbd8a5026ba3d2d9d25a8a07&scene=21#wechat_redirect)

[WSDM 2021 | 时间序列转化为动态图进行表示](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247486255&idx=1&sn=da35cb175b1dc8cfdc71bb5dfc4b0a8b&chksm=cecefedaf9b977ccbd31c23c940a95fd81d687c62970ce01e73f35f3437fecbcf65211bd8cc4&scene=21#wechat_redirect)

# [AAAI 2021 | 高效长序列预测模型: Informer](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247486246&idx=1&sn=d93cc3a6bb4f056b681144f2c82694b9&chksm=cecefed3f9b977c5d7716f02d5489089f1225f42cf33160455a65b6f24f216d4cf10f92c20b1&scene=21#wechat_redirect)

[ICML 2022 | 时间序列相关论文一览（附原文源码）](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490025&idx=1&sn=3b0c26c52ce1551edfb17fbedc87e55c&chksm=ceceec1cf9b9650ab2c86db5652602a9b5f4818705947f09260a050ddbb061239ce49abc0553&scene=21#wechat_redirect)

[WWW 2022 | 时间序列相关论文一览（附原文源码）](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247489704&idx=1&sn=3538a677eccb277624a9ef17fee1f86c&chksm=ceceed5df9b9644b4eb8ebb7d9b4aa051ba10bbc42a769286e4aec734893f9056609dd0da380&scene=21#wechat_redirect)

[WSDM 2022 | 时间序列相关论文一览（附原文源码）](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247489625&idx=1&sn=c61865f1ee92110bc821277e6903ad74&chksm=ceceedacf9b964baf8c466c7a36d8471cc4296c0dbbebdfb523b2efd25baf4b259b7f646e024&scene=21#wechat_redirect)

[KDD 2022 | 时间序列相关论文一览（附原文源码）](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247490156&idx=1&sn=05c56b595d467f953851b0ffe037f98e&chksm=ceceef99f9b9668f8f316b1a76d84470a68e126107f7a40b5543ce618bd41fed4123b29ec653&scene=21#wechat_redirect)

[AAAI 2022 | 时间序列相关论文一览（附原文源码）](http://mp.weixin.qq.com/s?__biz=Mzg3NDUwNTM3MA==&mid=2247489416&idx=1&sn=7818eed66a2f86f58fb00ddc03218614&chksm=cecee27df9b96b6bbf3753de5cb0ae8b83bef74e342f189ee5c8e1b8c311f591755db2ac9dbb&scene=21#wechat_redirect)

  

**觉得不错，那就点个赞吧**

![](assets/016.gif)