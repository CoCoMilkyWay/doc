# 最后提交赌了一把，意外喜提kaggle第一。

yuuniee 量化前沿速递 2024-06-13 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487907&idx=1&sn=e5f54789198e7351e06b230a7d89a1c2&chksm=c3e49cc4b7f402d4bf4847ce75b4b9859fd7951f49686148e85c92e1d46bb2a5244b43aa1db9#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487907&idx=1&sn=e5f54789198e7351e06b230a7d89a1c2&chksm=c3e49cc4b7f402d4bf4847ce75b4b9859fd7951f49686148e85c92e1d46bb2a5244b43aa1db9#rd)

# 

  

**Home Credict 信用风险模型稳定性第一名方案分享！**

## 

简介

![](assets/001.png)

第一名的方案可以分为两步，

1.  机器学习模型的开发与优化，主要利用了特征工程和模型集成。
    
2.  Metric Hack，通过调整参数来提高最终得分。
    

## 

01

  

阶段1

第一阶段的框架如下：

![](assets/002.png)

 

-   交叉验证策略: 采用了StratifiedGroupKFold，并分别进行了不打乱和打乱的测试和训练。参数调整对LB得分的影响较小，而特征工程的改进则影响较大。
    
-   特征工程: 利用各个项目的最大值、最小值、平均值、方差等简单统计量作为特征进行了建模。
    
-   模型选择: 利用Catboost、LGBM和DNN模型进行集成，Catboost处理大量分类特征表现最佳。
    
-   DNN使用: 使用了Denselight model和LightAutoML库，最终表现优于其他复杂模型。
    

02

  

指标Hack

指标黑客问题: 由于比赛后的Metric Hack问题，作者通过数据逆向分析发现了一些变量之间的高度相关性，并根据这些信息进行分数调整。

-   date\_decision和min\_refreshdate\_3813885D之间的差值与WEEK\_NUM之间有极高的相关性（约0.9以上）
    

分数调整策略: 基于特定条件调整分数，通过改变REDUCE和DEVIDE值优化得分。

-   测试数据的公共/私有划分涵盖了整个时间段，很难确定特定的分布，私有部分的最佳值可能分布在1/4到3/4之间。
    
-   REDUCE的公共排行榜最佳值是0.03（至少在我的模型中），而私有部分的最佳值可能分布在0.02到0.04之间。
    

决策和结果: 不同选手对调整值的选择导致得分差异较大，最终决定采用median调整值期待能进入前十。

`DEVIDE = 1/2   REDUCE = 0.02   condition = df['WEEK_NUM'] < (df['WEEK_NUM'].max()-df['WEEK_NUM'].min())*DEVIDE+df['WEEK_NUM'].min()   df.loc[condition, 'score'] = (df.loc[condition, 'score'] - REDUCE).clip(0)`

## 

03

  

杀手锏

最终提交了两个模型结果：

1.  第一个选定的提交是第一阶段创建的无Hack模型，具有最佳交叉验证分数；
    
2.  第二个选定的提交则是对其应用了指标Hack。（我认为指标黑客可能会有效，但为了以防万一，我也提交了无黑客的模型）
    

# 

参考文献

![](assets/001.png)

1.  https://www.kaggle.com/competitions/home-credit-credit-risk-model-stability/discussion/508337
    
2.  https://www.kaggle.com/competitions/home-credit-credit-risk-model-stability/leaderboard?tab=public