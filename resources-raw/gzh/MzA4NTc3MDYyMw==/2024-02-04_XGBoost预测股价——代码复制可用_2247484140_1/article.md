# XGBoost预测股价——代码复制可用

小燕子搬砖 映翡量化 2024-02-04 22:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484140&idx=1&sn=1ec21d3320091a784c1fc4358676826b&chksm=9ef45cc7f17cb787f7579ea7c625b8c5fddbe225885935f3f3ea3285624f1d238167166f701e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484140&idx=1&sn=1ec21d3320091a784c1fc4358676826b&chksm=9ef45cc7f17cb787f7579ea7c625b8c5fddbe225885935f3f3ea3285624f1d238167166f701e#rd)

![](assets/001.gif)

​

## 1.XGBoost预测介绍

由于金融市场的复杂性和动态性，股票预测是一项具有挑战性的任务。然而，随着机器学习算法的进步，我们可以利用这些技术做出预测。

XGBoost是一种流行的机器学习算法，以其高性能和灵活性而闻名。在处理结构化数据方面特别有效，并已广泛用于包括金融在内的各个领域。

本文中，将纳入技术指标，这些指标是基于历史价格和数量数据的数学计算，以捕捉股市的模式和趋势。此外，将包括VIX指数，也称为“恐惧指数”，它衡量市场波动。

  

![](assets/002.jpg)

## 2.了解XGBoost

XGBoost是一种集成学习算法，它结合了多个弱模型（通常是决策树）的预测，以创建一个强大的预测模型。它使用梯度增强框架，其中对每个后续模型进行训练，以纠正以前模型所犯的错误。

**XGBoost 的优点** 

1）正则化 

XGBoost 在代价函数里加入了正则项，用于控制模型的复杂度。正则项里包含了树的叶子节点个数、每个叶子节点上输出的 score 的 L2 模的平方和。从 Bias-variancetradeoff 角度来讲，正则项降低了模型的 variance，使学习出来的模型更加简单，防止过拟合，这也是XGBoost 优于传统 GBDT 的一个特性。

2）并行处理 

XGBoost 工具支持并行。Boosting 不是一种串行的结构吗?怎么并行的？注意 XGBoost 的并行不是 tree 粒度的并行，XGBoost 也是一次迭代完才能进行下一次迭代的（第 t 次迭代的代价函数里包含了前面 t-1 次迭代的预测值）。XGBoost 的并行是在特征粒度上的。我们知道，决策树的学习最耗时的一个步骤就是对特征的值进行排序（因为要确定最佳分割点），XGBoost 在训练之前，预先对数据进行了排序，然后保存为block结构，后面的迭代中重复地使用这个结构，大大减小计算量。这个 block 结构也使得并行成为了可能，在进行节点的分裂时，需要计算每个特征的增益，最终选增益最大的那个特征去做分裂，那么各个特征的增益计算就可以开多线程进行。

3）灵活性 

XGBoost 支持用户自定义目标函数和评估函数，只要目标函数二阶可导就行。 

4）缺失值的处理 

对于特征的值有缺失的样本，XGBoost 可以自动学习出它的分裂方向。 

5）剪枝 

XGBoost 先从顶到底建立所有可以建立的子树，再从底到顶反向进行剪枝。

6）内置交叉验证 

XGBoost 允许在每一轮 Boosting 迭代中使用交叉验证。因此，可以方便地获得最优Boosting 迭代次数。而 GBM 使用网格搜索，只能检测有限个值。

****XGBoost 的**缺点或不足**

虽然说 XGBoost 在 Kaggle 比赛中获得了不错的成绩，但并不代表 XGBoost 是一个完美的算法，它当然也有自己的缺点和不足之处:

1）算法参数过多 

调参复杂，需要对 XGBoost 原理十分清楚才能很好的使用 XGBoost。 

2）只适合处理结构化数据 

相对于深度学习算法来说，XGBoost 算法只适合处理结构化的特征数据，而对于类似图像中的目标检测等任务重的非结构化数据没有很好的处理能力。

3）不适合处理超高维特征数据 

XGBoost 算法对于中低维数据具有很好的处理速度和精度，但是对于例如大规模图像物体识别，或者是推荐算法的某些场景中会出现的超高维特征的数据就无能为力了，这时候我们就需要借助于深度学习等算法。

**「模型原理还没搞明白，说的就是我自己![](assets/003.png)**

**https://www.showmeai.tech/article-detail/194」**

## 3.收集数据

使用`yfinance`库直接从雅虎财经下载数据。以银行业为例，并下载摩根大通公司（JPM）的数据。

import yfinance as yf

import matplotlib.pyplot as plt

  

\# Downloading the data

ticker = "JPM"

start\_date = "2018-01-01"

end\_date = "2024-02-02"

data = yf.download(ticker, start=start\_date, end=end\_date)

  

\# Plotting the closing price

plt.figure(figsize=(10, 6))

plt.plot(data\["Close"\])

plt.xlabel("Date")

plt.ylabel("Closing Price")

plt.title(f"{ticker} Stock Price")

plt.grid(True)

  

plt.show()

![](assets/004.png)

  

  

## 4.预处理数据

预处理数据是任何机器学习项目必不可少的一步。涉及清理数据，处理缺失值，并将数据转换为适合模型的格式。计算简单移动平均线（SMA）、指数移动平均线（EMA）、相对强度指数（RSI）、移动平均线收敛发散（MACD）和VIX指数，并作图。‍‍‍‍‍‍

import pandas as pd

  

\# Calculate technical indicators

data\["SMA"\] = data\["Close"\].rolling(window=20).mean()

data\["EMA"\] = data\["Close"\].ewm(span=20, adjust=False).mean()

data\["RSI"\] = 100 - (100 / (1 + (data\["Close"\].diff() > 0).rolling(window=14).mean()))

data\["MACD"\] = data\["Close"\].ewm(span=12, adjust=False).mean() - data\["Close"\].ewm(span=26, adjust=False).mean()

data\["VIX"\] = yf.download("^VIX", start=start\_date, end=end\_date)\["Close"\]

  

\# Drop missing values

data.dropna(inplace=True)

  

\# Plotting the technical indicators

plt.figure(figsize=(10, 12))

  

plt.subplot(3, 1, 1)

plt.plot(data\["Close"\])

plt.xlabel("Date")

plt.ylabel("Closing Price")

plt.title(f"{ticker} Stock Price")

plt.grid(True)

  

plt.subplot(3, 1, 2)

plt.plot(data\["SMA"\], label="SMA")

plt.plot(data\["EMA"\], label="EMA")

plt.xlabel("Date")

plt.ylabel("Price")

plt.title("Moving Averages")

plt.legend()

plt.grid(True)

  

plt.subplot(3, 1, 3)

plt.plot(data\["RSI"\])

plt.xlabel("Date")

plt.ylabel("RSI")

plt.title("Relative Strength Index (RSI)")

plt.grid(True)

  

plt.tight\_layout()

  

plt.show()

![](assets/005.png)

  

## 5.特征工程

特征工程涉及从数据集中选择和转换相关特征，以提高模型的性能，将使用技术指标和VIX指数作为功能。

创建了一个包含所选特征的特征矩阵`X`和包含收盘价的目标变量向量`y`。然后，我们使用80-20拆分将数据拆分为训练和测试集。

\# Create feature matrix and target variable

features = \["SMA", "EMA", "RSI", "MACD" , "VIX"\]

target = "Close"

  

X = data\[features\]

y = data\[target\]

  

\# Splitting the data into training and testing sets

train\_size = int(len(X) \* 0.8)

X\_train, X\_test = X\[:train\_size\], X\[train\_size:\]

y\_train, y\_test = y\[:train\_size\], y\[train\_size:\]

  

## 6.构建XGBoost模型

要构建XGBoost模型，需要安装`xgboost`库并导入必要的模块。设置了XGBoost模型的参数，包括目标函数、最大深度、学习率、伽马和正则化λ。然后，使用`xgb.train`函数训练模型，并对训练和测试集进行预测。最后，计算均方根误差（RMSE）来评估模型的性能。RMSE越低，模型的预测就越好。

  

import xgboost as xgb

from sklearn.metrics import mean\_squared\_error

  

\# Creating the DMatrix for XGBoost

dtrain = xgb.DMatrix(X\_train, label=y\_train)

dtest = xgb.DMatrix(X\_test, label=y\_test)

  

\# Setting the hyperparameters

params = {

    "objective": "reg:squarederror",

    "max\_depth": 3,

    "learning\_rate": 0.1,

    "gamma": 0,

    "reg\_lambda": 1,

    "eval\_metric": "rmse"

}

  

\# Training the model

model = xgb.train(params, dtrain, num\_boost\_round=100)

  

\# Making predictions

y\_pred\_train = model.predict(dtrain)

y\_pred\_test = model.predict(dtest)

  

\# Calculating the root mean squared error

rmse\_train = mean\_squared\_error(y\_train, y\_pred\_train, squared=False)

rmse\_test = mean\_squared\_error(y\_test, y\_pred\_test, squared=False)

  

print(f"Train RMSE: {rmse\_train:.2f}")

print(f"Test RMSE: {rmse\_test:.2f}")

  

\# create a dataframe with the test and predictions data

df1 = pd.DataFrame({'Test': y\_test, 'Predictions': y\_pred\_test})

  

\# plot the test and predictions data as a line graph

df1.plot(kind='line', figsize=(10, 6))

plt.xlabel('Date')

plt.ylabel('Close Price')

plt.title('Test vs Predictions')

plt.legend()

plt.show()

![](assets/006.png)

此模型的股票JPM输出结果，RMSE还比较小，看起来蛮准的，但是换其他的票结果就不大理想。

  

![](assets/007.png)

  

## 7.后续工作‍

XGBoost为超参数调优提供了各种技术，例如网格搜索和随机搜索。后续可以探索其他技术指标和基本因素，以提高模型的预测能力。

  

资料来源：

https://thepythonlab.medium.com/xgboost-in-stock-returns-prediction-using-technical-indicators-and-vix-index-700fda74b425  

https://bbs.huaweicloud.com/blogs/211421  

https://zhuanlan.zhihu.com/p/40129825  

https://xgboost.readthedocs.io/en/stable/