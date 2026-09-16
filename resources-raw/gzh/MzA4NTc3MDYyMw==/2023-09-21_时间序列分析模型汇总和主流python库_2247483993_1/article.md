# 时间序列分析模型汇总和主流python库

小燕子搬砖 映翡量化 2023-09-21 20:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247483993&idx=1&sn=f2ab6b035853a76f6a95d2f03ee63690&chksm=9e18d12c652fd55c9ddaa190ea6d52b4bc02f2b25a0db8800d939b09e23bfde72ef0504edbc2#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247483993&idx=1&sn=f2ab6b035853a76f6a95d2f03ee63690&chksm=9e18d12c652fd55c9ddaa190ea6d52b4bc02f2b25a0db8800d939b09e23bfde72ef0504edbc2#rd)

![](assets/001.gif)

​

## **一、时间序列分析模型**‍‍‍‍‍‍

时间序列分析是一种强大的工具，可用于从数据中提取有价值的信息并对未来事件进行预测。它可用于识别趋势、季节性模式和变量之间的其他关系。时间序列分析还可用于预测未来事件，例如销售、需求或价格变动。

时间序列模型，可以归结为四大类：

   🔥基于业务场景理解的因子预测模型；

   🔥传统时间序列模型：比如均值回归、ARIMA、指数平滑预测法（比如 Holt-Winters)等；

    🔥机器学习模型：GBDT（迭代的决策树算法）；两个工具：Lightgbm、Xgboost，是现有kaggle比赛中最常用也是最强有力的工具。两个工具特点可以参考这篇文章https://zhuanlan.zhihu.com/p/99069186。

‍

    🔥深度学习模型：CNN、RNN、LSTM、GRU、VAR、seq2seq、wavenet、N-Beats、DeepAR、TFT（Temporal Fusion Transformer，Google AI ）、Spacetimeformer、AutoML等。前面几个还稍微有点能理解，后面几个这几年才出来的，有点难理解。

‍‍

        **太多了，是不是不知道选哪个合适？目前主流选择基本是 特征工程+GBDT 和 NN族。**

![](assets/002.jpg)

**二、模型发展历史**

-   1950s — Exponential Smoothing
    
-   1970s — ARIMA(X)
    
-   1980 — VAR
    
-   1980s — GARCH
    
-   2000 — Theta model
    
-   2011 — TBATS
    
-   2014 — XGBoost (University of Washington)
    
-   2016 — LightGBM (Microsoft)
    
-   2017 — CatBoost (Yandex)
    
-   2017 — Prophet (Facebook)
    
-   2017 — DeepAR (Amazon)
    
-   2017 — Multi-Horizon Quantile Recurrent Forecaster — MQRNN (Amazon)
    
-   2018 — Deep State Space Model — DSSM (Amazon)
    
-   2018 — Temporal Convolution Network — TCN (CMU)
    
-   2018 — Temporal Graph Convolutional Network — T-GCN (Central South University, Changsha, China)
    
-   2018 — ESRNN (Uber)
    
-   2019 — N-BEATS (ElementAI)
    
-   2019 — AR-Net (Facebook)
    
-   2020 — NeuralProphet (Facebook)
    
-   2020 — Temporal Fusion Transformer — TFT (Google)
    
-   2021 — ThymeBoost
    
-   2021 — Greykite/Silverkite (Linkedin)
    
-   2021 — Orbit (Uber)
    
-   2022 — N-HiTS (CMU/Unity Technologies/Nixtla)
    
-   2023 — PatchTST (Princeton/IBM)
    

## **三、最新几个模型简单介绍**‍‍‍‍

✅✅✅有点复杂。。。  

N-BEATS (ElementAI)

Nbeats的核心思路类似于GBDT，通过多层全连接进行时间序列分解，每层拟合时间序列部分信息。

![](assets/003.jpg)

DeepAR (Amazon)

DeepAR是Amazon提出的一种针对大量相关时间序列统一建模的预测算法，该算法采用了深度学习的技术，通过在大量时间序列上训练自回归递归网络模型，可以从相关的时间序列中有效地学习全局模型，并且能够学习复杂的模式，例如季节性、数据随时间的不确定性增长，从而对各条时间序列进行预测。

![](assets/004.jpg)

Spacetimeformer 

Spacetimeformer的核心理念：使用一个模型来利用这些城市/地点之间的空间关系，从而学习额外的有用依赖，因为模型将同时考虑时间和空间关系。

![](assets/005.jpg)

TFT（Temporal Fusion Transformer ，Google AI) 

Temporal Fusion Transformer（TFT）是一种基于Transformer的模型，专门用于解决时间序列预测问题。该模型结合注意力机制和卷积操作，可以很好地建模所有频率和时空间关系，从而提高时间序列预测的准确性。

![](assets/006.png)

AutoML（这个有点厉害的样子）‍‍‍‍

AutoML 是当前深度学习领域的热门话题。只需要很少的工作，AutoML 就能通过快速有效的方式，为你的 ML 任务构建好网络模型，并实现高准确率。简单有效！数据预处理、特征工程、特征提取和特征选择等任务皆可通过 AutoML 自动构建。

![](assets/007.jpg)

![](assets/008.jpg)

![](assets/009.jpg)

可以看看这个：https://github.com/microsoft/nni

http://www.mysecretrainbow.com/ai/17942.html  

## **四、python库介绍**‍‍

## 最顶尖的三个开源库框架是PyTorch、TensorFlow和Keras。

## Keras是一个用python脚本编写的神经网络库，可以在TensorFlow的顶层执行，它是专门为深度神经网络的鲁棒执行而设计的。

## TensorFlow是一种在数据流编程和机器学习应用中用于执行多个任务的工具。

## PyTorch是一个用于自然语言处理的机器学习库。

## Pytorch

## https://github.com/pytorch/pytorch

## ‍PyTorch是一个开源的Python机器学习库，基于Torch，底层由C++实现，应用于人工智能领域，如计算机视觉和自然语言处理。它主要由Meta Platforms的人工智能研究团队开发。

Tensorflow

https://github.com/tensorflow/tensorflow

TensorFlow 由 Google Brain 团队创建，最初于 2015 年向公众发布，是一个用于数值计算和大规模机器学习的开源库。TensorFlow 将大量机器学习和深度学习模型和算法（也称为神经网络）捆绑在一起，并通过常见的编程隐喻使它们变得有用。它使用 Python 或 JavaScript 为构建应用程序提供方便的前端 API，同时在高性能 C++ 中执行这些应用程序。

TensorFlow与 PyTorch和 Apache MXNet 等框架竞争，可以训练和运行深度神经网络，用于手写数字分类、图像识别、词嵌入、循环神经网络、用于机器翻译的序列到序列模型、自然语言处理和基于 PDE（偏微分方程）的模拟。最重要的是，TensorFlow 支持大规模生产预测，使用相同的模型进行训练。

关于tensorflow和pytorch选哪个，可参考：https://www.51cto.com/article/695886.html‍‍

## Prophet  

https://github.com/facebook/prophet

Facebook 的 Prophet 是一种预测工具，任何人都可以使用 CSV 格式的数据。Prophet 是 Facebook 核心数据科学团队发布的开源软件。它基于一个加性模型，其中非线性趋势与每年、每周和每天的季节性以及假期效应相吻合。它最适用于具有强烈季节性影响和多个季节历史数据的时间序列。Prophet 对缺失数据和趋势变化具有鲁棒性，通常可以很好地处理异常值。  

根据官方文档，fbprophet 可以很好地处理具有显着季节性影响的时间序列数据和几个季节的先前数据。此外，fbprophet 声称它可以抵抗丢失数据，并且能够有效地管理异常值。

## Flow Forecast

https://github.com/AIStream-Peelout/flow-forecast

Flow Forecast是一个开源的时序预测框架，它包含了以下模型:Vanilla LSTM (LSTM)、SimpleTransformer、Multi-Head Attention、Transformer with a linear decoder、DARNN、Transformer XL、Informer、DeepAR、DSANet 、SimpleLinearModel等等

tsfresh

https://github.com/blue-yonder/tsfresh/

tsfresh 是一个 Python 包，可自动执行从时间序列中提取特征的过程。它基于这样一种思想，即时间序列中的信息可以分解为一组有意义的特征，称为特征。tsfresh 负责手动提取这些特征的繁琐工作，并提供自动特征选择和分类的工具。该包旨在与 pandas DataFrames 一起使用，并提供广泛的功能来处理时间序列数据，包括：

-   从时间序列中自动提取特征
    
-   自动特征选择
    
-   时间序列分解
    
-   降维
    
-   异常值检测
    
-   支持多种时间序列格式
    
-   支持缺失值
    
-   支持多种语言
    

  

Python 中有许多可用的时间序列预测库，每个都有自己的长处和短处，可根据您的需要选择合适的一个很重要，以下罗列一些库，供参考：

https://github.com/microsoft/LightGBM  

https://github.com/dmlc/xgboost  

https://github.com/fastai/fastai  

https://github.com/StatMixedML/LightGBMLSS

https://github.com/winedarksea/AutoTS

https://github.com/unit8co/darts

https://github.com/facebookresearch/Kats

https://github.com/alan-turing-institute/sktime

https://www.sktime.org/en/stable/estimator\_overview.html

https://github.com/awslabs/gluon-ts

https://github.com/Alro10/deep-learning-time-series

https://github.com/timeseriesAI/tsai

https://github.com/sktime/sktime

https://github.com/pycaret/pycaret

https://github.com/awslabs/gluonts  

https://github.com/alkaline-ml/pmdarima

  

大模型进化树mark一下（待研究）‍‍‍‍‍‍‍‍‍‍

![](assets/010.png)

##