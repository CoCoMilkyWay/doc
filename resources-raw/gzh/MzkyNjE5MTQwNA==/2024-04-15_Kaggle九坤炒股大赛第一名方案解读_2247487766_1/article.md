# Kaggle九坤炒股大赛第一名方案解读

yuuniee 量化前沿速递 2024-04-15 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487766&idx=1&sn=c3b51be2cb55349b4f940783da0165f6&chksm=c3687deb8d169c3e965c15ab3d8c46eb57dd097877af6bf63703f303ebd0e2a99212a1a156d5#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487766&idx=1&sn=c3b51be2cb55349b4f940783da0165f6&chksm=c3687deb8d169c3e965c15ab3d8c46eb57dd097877af6bf63703f303ebd0e2a99212a1a156d5#rd)

  

  

九坤大赛第一名方案解读

简 介

![](assets/001.png)

今天我们一起来看看波动极大的九坤大赛第一名的方案，虽然Public榜单和Private榜单波动极大，但是第一名的成绩在Private榜单中却是十分稳定的，今天我们一起看看第一名的方案究竟有何神奇之处。第一名的方案由下面几个模块组成：

1.  模型：使用了LightGBM和TabNet；
    
2.  做了一定的特征工程；
    
3.  数据采样；
    
4.  对特质工程进行交叉验证，基于时间的划分等；
    
5.  训练采用KFold进行交叉验证；
    

下面我们对上面五个模块进行更细的拆分。

方案解读

![](assets/001.png)

  

01

  

模 型

1.  本次竞赛主要是用了LGM和TABNET；其中LightGBM是最稳定的；
    
2.  TabNET是和LGB融合最好的NN模型；
    
3.  Loss使用的是RMSE，二Pearson Corr用于验证评估；
    
4.  最后使用五折的LGB和五折的TABNET求均值；
    

02

  

特征工程

1.  为了减少或消除不必要特征的影响，我们调查了每个特征的重要性和相关性，但没有发现任何有意义的数值证据，然后相反，我们考虑添加特征；
    
2.  我们增加了100个特征，这些特征可以取得不错的提升；这100个特征是通过下面的形式计算得到：
    

```
features = [f'f_{i}' for i in range(300)]corr           = train_df[features[:] + ['target']].corr()['target'].reset_index()corr['target'] = abs(corr['target'])corr.sort_values('target', ascending = False, inplace = True)best_corr      = corr.iloc[3:103, 0].to_list()time_id_mean_features = []for col in tqdm(best_corr):   mapper = train_df.groupby(['time_id'])[col].mean().to_dict()   train_df[f'time_id_{col}'] = train_df['time_id'].map(mapper)   train_df[f'time_id_{col}'] = train_df[f'time_id_{col}'].astype(np.float16)   time_id_mean_features.append(f'time_id_{col}')features += time_id_mean_features
```

03

  

数据采样

使用(train.csv + supplemental\_train.csv)\[2400000:\]

-   上述的mean是将数据拼接之后计算的；
    
-   使用上面的特征，PurgedGroup and TimeSeriesSplit CV都可以去的不错的提升；
    
-   采样的大小是依据RAM确定的；
    

03

  

FE的特征交叉&调参

-   使用的是PurgedGroupTimeSeries, TimeSerieseSplit
    

04

  

使用KFold&GroupKFold进行训练

1.  对于这个选择还有另一个简单的策略，这是一个自检数据集，如下所示：
    

-   训练集：（time id>=0）和（time id<=1000）测试集：（time  id>=1001）和（time id<=1202）
    

2.  有多种训练方法，但经过上述环境中的测试，选择了\[limited-training-KFold\]，它是最稳定和效果最好的方案；
    
3.  为了减少过度拟合的风险，我们使用了early stop和以及固定训练次数（num\_boost\_round或epoch）限制在某个值或更的值。
    

参考文献

![](assets/001.png)

1.  https://www.kaggle.com/competitions/ubiquant-market-prediction/leaderboard
    
2.  https://www.kaggle.com/competitions/ubiquant-market-prediction/discussion/338220