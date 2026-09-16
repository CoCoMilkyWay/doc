# Kaggle建模技巧，稳稳的提升。

无言 量化前沿速递 2024-08-19 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488103&idx=1&sn=f0bcf8681572c1b2590acac694e8bf0a&chksm=c318efe9bdb4888adabc1949c91e09506c8b1ccdc528b286045a991f67bb8f52f79cac20c449#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488103&idx=1&sn=f0bcf8681572c1b2590acac694e8bf0a&chksm=c318efe9bdb4888adabc1949c91e09506c8b1ccdc528b286045a991f67bb8f52f79cac20c449#rd)

# 

  

**Kaggle Stacking模型竞赛技巧**

  

## 

简介

![](assets/001.png)

在非常多的建模问题中，例如预测不同产品的销量；预测参保人员是否会续保等；有一种非常值得尝试的提分方案，分类别建模。该方案在历史的诸多竞赛中屡试不爽，而且基本都能带来一定的提升，也是stacking中非常好的选择。

## 

案例

![](assets/001.png)

### kaggle  Binary Classification of Insurance Cross Selling竞赛冠军方案为例

-   链接：https://www.kaggle.com/competitions/playground-series-s4e7/code
    

冠军方案中就采用了该类的建模策略。

  

![](assets/002.png)

在模型进行stacking前，分别对

-   previously insured (2 models),
    
-   vehicle damage (2 models)
    
-   previously insured + vehicle damage (4 models)
    

构建了8个模型用于最后的模型stacking，并且带来了提升。

![](assets/003.png)

#   

参考文献

![](assets/001.png)

1.  https://medium.com/towards-data-science/are-outliers-harder-to-predict-ae84dd4be465
    
2.  https://www.kaggle.com/competitions/playground-series-s4e7/discussion/523404