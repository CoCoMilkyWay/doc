# TimeGPT预测上证指数

小燕子搬砖 映翡量化 2024-05-23 19:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484443&idx=1&sn=0df145c66208e249fe60362e1124f289&chksm=9eea74bda3fb936afa2327997dbdc1ec4c303b4d4670224a297e6b6cd06d532a9b7177e8e56d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484443&idx=1&sn=0df145c66208e249fe60362e1124f289&chksm=9eea74bda3fb936afa2327997dbdc1ec4c303b4d4670224a297e6b6cd06d532a9b7177e8e56d#rd)

![](assets/001.gif)

TimeGPT是由Nixtla开发的一款专门用于预测任务的生成式预训练Transformer模型。TimeGPT是在有史以来最大的数据集上进行训练的——超过1000亿行的金融、天气、能源和网络数据。这个工具能够在几秒钟内识别出模式并预测未来的数据点。在本文中，利用Nixtla的nixtlats框架，实现一个将TimeGPT应用于上证指数价格预测的简单例子。

**TimeGPT**

TimeGPT是创建时间序列预测基础模型的首次尝试。

![](assets/002.jpg)

从上图中，可以看到TimeGPT背后的想法是对来自不同域的大量数据进行训练模型，然后对看不见的数据进行零射推理。这种方法依赖于转移学习，即模型利用其在培训期间获得的知识解决新任务的能力。只有当模型足够大，并且在大量数据上进行训练时，这才有效。

![](assets/003.jpg)

  

从上图中，可以看到TimeGPT使用完整的编码-解码架构。

输入可以包括一个历史数据窗口，以及外部数据，如时间序列数据或其他系列。数据输入到模型的编码器部分。然后，编码器内部的注意力机制从输入中学习不同的属性。然后将其输入解码器，解码器使用学到的信息来生成预测。当然，当预测序列达到用户设定的预测视界长度时，它就结束了。

值得注意的是，在TimeGPT中实现了共形预测，允许模型根据历史误差估计预测间隔。

  

## **TimeGPT的功能**

TimeGPT具有广泛的功能。

首先，TimeGPT是一个预训练的模型，这意味着我们可以生成预测，而无需专门针对我们的数据进行训练。尽管如此，仍然可以根据我们的数据微调模型。

其次，该模型支持外源变量来预测我们的目标，并且可以处理多变量预测任务。

最后，通过使用共形预测，TimeGPT可以估计预测间隔。这反过来又允许模型执行异常检测。基本上，如果一个数据点超出99%的置信区间，则模型将其标记为异常。

所有这些任务都可以通过零点推理或一些微调，这是时间序列预测领域范式的根本转变。

现在我们对TimeGPT、它的工作原理和训练方式有了更扎实的了解，让我们看看模型的实际应用。

  

**TimeGPT获取密钥**

免费获取密钥地址：https://docs.nixtla.io/

![](assets/004.png)

  

**TimeGPT用于上证指数预测的代码——复制可用**

import yfinance as yf

import pandas as pd

\# Define the ticker symbol for the S&P 500 index

ticker\_symbol = "000001.ss"

\# Fetch daily data for the S&P 500 index

data = yf.download(ticker\_symbol, start='2010-01-01', end='2024-05-22')

\# Create a DataFrame

df = pd.DataFrame(data)

from nixtla import NixtlaClient

nixtla\_client = NixtlaClient(api\_key = 'your key')

nixtla\_client.validate\_api\_key()

#Create a timestamp column and change the index

df\['timestamp'\] = df.index

df = df.reset\_index(drop=True)

level = \[50,80,90\] # confidence levels 

fcst = nixtla\_client.forecast(df, h=10, level=level,freq='D', time\_col='timestamp', target\_col='Close')

nixtla\_client.plot(df, fcst, max\_insample\_length=250,time\_col='timestamp', target\_col='Close')  

  

预测了2024年5月22日后10日的数据：‍‍‍‍‍‍‍‍‍

![](assets/005.jpg)

**放大一些****看：****准确预测了今天5月23日跌，十天内还有一次大跌，拭目以待。**  

![](assets/006.jpg)

![](assets/007.jpg)