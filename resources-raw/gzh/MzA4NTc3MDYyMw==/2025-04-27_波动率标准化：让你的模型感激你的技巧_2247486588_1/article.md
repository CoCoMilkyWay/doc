# 波动率标准化：让你的模型感激你的技巧

InfinityQuant 映翡量化 2025-04-27 20:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486588&idx=1&sn=8f7fb69469cc60bdf8c7acfe69c3e76e&chksm=9e8d83971418230983438e1f9d84756cbc0dd4005048aba4d760d9692186e043837d35ba6d2d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486588&idx=1&sn=8f7fb69469cc60bdf8c7acfe69c3e76e&chksm=9e8d83971418230983438e1f9d84756cbc0dd4005048aba4d760d9692186e043837d35ba6d2d#rd)

📊这不是你通常使用的 Scikit-Learn 中的 StandardScaler 或 MinMaxScaler。我们说的是波动率标准化，这是一种专为金融数据量身定制的方法。  
  

📉 问题所在：  
大多数交易特征是没有界限的——因为它们是根据价格计算出来的，而价格可以无限波动。模型可不喜欢这样。  
  

📌 解决方案？  
将你的特征（因子）除以 N 天的波动率（所有特征使用相同的 N，比如 30 天、60 天……你自己选择）。例如：SMA（简单移动平均）/vol\_30，ATR（平均真实波动范围）/vol\_30……  
  

听起来很简单，但这个技巧能帮你做到：  
✅ 保持特征的有界性  
✅ 保留信息含量  
✅ 让模型更加稳健和稳定  
  

下次构建因子策略的时候不妨试试，你会感受到其中的差异。

  

![](assets/001.jpg)