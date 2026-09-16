# Kaggle竞赛Top5分享融合绝学。

MATT OP 量化前沿速递 2024-07-25 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488038&idx=1&sn=0c39b3c8fc9c5ade8645b9b38a487d2e&chksm=c351319b80f303388646a75c746c66c91d200cd8ffa817119d5588f81e53b2aba3ad2c654b6f#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488038&idx=1&sn=0c39b3c8fc9c5ade8645b9b38a487d2e&chksm=c351319b80f303388646a75c746c66c91d200cd8ffa817119d5588f81e53b2aba3ad2c654b6f#rd)

# 

  

**Kaggle竞赛Top5分享融合绝学--HillClimb！**

## 

简介

![](assets/001.png)

在最新刚刚结束的Kaggle竞赛“Regression with a Flood Prediction Dataset”中，第四名的选手分享了一种继承策略--HillClimb集成。

Hill Climb集成可以应用到任何问题的集成当中，该策略最早是在多标签问题中被使用，而且在集成中取得了非常大的提升，很多选手赛后也尝试了该策略，纷纷表示效果非常好。

Kaggle GM Chris Deotte也非常推荐该即成策略。

```
"I love hill climbing because it can take lots of models and picks the best small subset of models. (i.e. its like Lasso regression) And it computes ensemble model weights." - Chris Deotte 
```

下面我们就一起来学习一下该策略。

## 

HillClimb Ensemble

![](assets/001.png)

目前HillClimb算法已经被集成到一个Python模块。

爬山算法尝试最大化（或最小化）目标函数 。在每次迭代中，爬山算法会调整中的单个元素，并确定这种改变是否会提高 的值。使用爬山算法，任何能够提升值的改变都会被接受，并且这个过程会一直持续，直到找不到可以提升值的改变为止。这时被称为“局部最优”。爬山算法不一定会找到全局最大值/最小值，而可能会收敛到局部最大值/最小值。

具有最佳交叉验证分数的模型并不总是首选。相反，爬山算法选择不同的模型。

## 

代码

![](assets/001.png)

```
# !pip install hillclimbersfrom hillclimbers import climb_hill, partialdef climb_hill(    train=None,     oof_pred_df=None,     test_pred_df=None,     target=None,     objective=None,     eval_metric=None,    negative_weights=False,     precision=0.01,     plot_hill=True,     plot_hist=False    return_oof_preds=False) -> np.ndarray: # Returns test predictions resulting from hill climbing
```

**实战案例可以参考：**

-   https://www.kaggle.com/code/mattop/ps-s4-e5-4th-place-solution-with-hillclimbers/notebook
    
      
    
-   ![](assets/002.png)
    

## 

适用问题

![](assets/001.png)

适用于所有的问题，尤其是多标签的问题。

# 

参考文献

![](assets/001.png)

1.  https://github.com/Matt-OP/hillclimbers
    
2.  Hillclimb ensembling
    
3.  4th place solution