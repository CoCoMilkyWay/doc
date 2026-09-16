# 最新Kaggle量化赛Trading at the Close高分方案解析

量化前沿速递 2024-02-02 12:25 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487544&idx=1&sn=e52943ef73df85763d8fccf314cc40bd&chksm=c302ac331e70b35cae37ca242e59d202fd74d2b18c2b63ced82854764b19ec1327fc0fb5243a#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487544&idx=1&sn=e52943ef73df85763d8fccf314cc40bd&chksm=c302ac331e70b35cae37ca242e59d202fd74d2b18c2b63ced82854764b19ec1327fc0fb5243a#rd)

Kaggle上最新的量化比赛，Optiver组织的Trading at the Close近期结束了，对其中的高分方案做汇总，供参考。 点赞超50就开一个系列写了  

  

赛题要求根据给定的特征，预测纳斯达克交易所股票的收盘价，细节见赛题说明。  

https://www.kaggle.com/competitions/optiver-trading-at-the-close/overview

  

排名来看，不少国内的大兄弟遥遥领先(如有侵权，私戳沟通)。  

![](assets/001.png)

  

  

**单模型5.34高分的方案**

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/456438

1.   numba + 多进程，构建特征非常快
    
2.  predict.mean() 好于zeromean
    

  

**无特征工程的NN模型 5.34分**

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/462639

分享两个神经网络模型。第一个是LSTM模型，第二个是ConvNet。即使不进行任何特征工程，也可以达到5.3505的LB得分。如果再加入一些反映不平衡的特征，就可以获得5.3439的得分。提供两个Notebook供参考。

  

ConvNet结构的一个重要特征是使用残差连接，这显著提升了性能。以下是LSTM和ConvNet模型的链接：

  

Convnet: optiver-conv-just-imb-inference-cleanup

LSTM: optiver-no-fe-lstm-inference-cleanup

  

**最稳健的单模型方案（超高赞)**

https://www.kaggle.com/code/lblhandsome/optiver-robust-best-single-model

1\. 设计了一些反映订单不平衡、周期性的特征，相见notebook  

![](assets/002.png)

2\. LGM模型，时序模型，KFold会有数据泄露，因此严格设定部分test set数据不用于训练，时序上将trainset拆为train valid test。  

  

**Public LB 18名的方案  很细致的说明**

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/462650

  

基于公开notebook的特征工程

-   Catboost feature elimination，一些特征在Catboost中表现很好但在LGB中很差
    
-   LGB和Catboost的集中，分别使用202、141个特征构建  
    
-   Online learning在public LB表现很好但到最新的数据崩了  
    
-   尝试了不同的预处理
    
-   所有代码：https://www.kaggle.com/code/wuhongrui/public-5-3227-lgbm-catboost-with-online-learning/notebook
    

  

LGB  

-   train.csv中删除所有含NAN的特征如wap，bid-price等
    
-   使用了前文最强单模型中的所有特征，并用stock\_id，date\_id生成组合特征  
    
-   使用前一天同一秒的特征预测今天的特征，将前一天的目标作为一个特征
    
      
    

Catboost

-   catboost使用了所有特征，包括一些在lgb中不好用的特征。使用Catboost去剔除不重要的特征，数量从380降到141
    
-   一些技术指标报告RSI,MACD，布林带在catboost中很好用，但lgbm中没用，但算起来太花时间
    
-   catboost训练比lgb快非常多，7分钟vs1小时这种量级。  
    

  

**WAP特征的构建，一个被很多队伍采用的特征**  

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/462022

  

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

  

**Public LB 5th LGB,Catboost融合，首次参加kaggle比赛就拿了高分**  

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/462743

  

-   5个lgb+5个catboost，预处理使得指数加权和为0
    
-   lgb表现非常好，同时发现与少量的深层模型相比，大量的浅层模型（在不同数据集上验证）产生了更稳定的输出。特别是参数extra\_trees=True增加了一个更强的正则项。
    
-   catboost在调参后表现很好。
    
-   MLP FC>GELU，就NN解决方案来说，这是最好的。因为stock\_id和seconds\_in\_bucket都有超过200层维度的嵌套。最好的MLP叠加LGB获得5.391分，但由于不稳定，最终未使用。
    
-   Temporal CNN。尝试了一个时间卷积神经网络。如果把问题分解开来，需要考虑几个不同的维度，date\_id,second\_in\_bucket和整体市场的运动，TCN应该能很好捕获second in bucket之间的依赖关系，但由于太不稳定，未使用。
    

  

特征集：使用了216个特征。特征集可以分为以下几类

-   股票特定总额的合计值  
    
-   日度rolling rolling获取日间的变动  
    
-   市场走势：我们研究股票相对于市场的进展情况，因此最好包含整体的情绪特征，包含加权指数（归一化和不归一化两个版本）
    
-   imbalance 特征：价量上的不平衡特征。我们发现market\_urgency表现非常好，所以构造了一些相似的特征。
    

  

Continuous Adapting  我们使用两种方法更新LGB，lgb.train和booster.refit，第一种支持更多参数更多树的训练，根据给定迭代次数，refit根据最新给定数据进行迭代，new\_output = k\*old\_output + (1-k)\*new\_output

  

**Public 23th  Feature is all you need** 

https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/462664

  

做了一堆日内特征

![](assets/006.png)

  

日线上的特征

![](assets/007.png)

  

阶段性统计特征

![](assets/008.png)

  

模型：lgb、catboost的融合

1.   高性能计算：使用高性能的libraries重构了一堆算特征的函数，最终算一个因子只需要20ms，lgb，catboost预测只需要500ms，其他的pandas操作只需要100ms
    
2.  非增量的训练：观察到纳斯达克6-12月波动很大，担心11月回撤对模型有影响
    
3.  rolling feature：用numba/polar结果可能不精确，和pandas计算结果不一致，用excel对比。使用np.allclose函数保证pandas和numba结果一致。