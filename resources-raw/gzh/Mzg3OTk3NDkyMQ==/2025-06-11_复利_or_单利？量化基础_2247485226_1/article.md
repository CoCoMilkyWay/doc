# 复利 or 单利？量化基础

QuantSeek QuantSeek 2025-06-11 22:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485226&idx=1&sn=e607a89dccd63e0e9e580cd5f32e4ab4&chksm=ce138c0cebfc06ebf6730daecb7697de6102560107e68f6823e23470f885a506174af12230cc#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485226&idx=1&sn=e607a89dccd63e0e9e580cd5f32e4ab4&chksm=ce138c0cebfc06ebf6730daecb7697de6102560107e68f6823e23470f885a506174af12230cc#rd)

有一位QuantSeek框架老用户问我为什么在因子回测的时候使用的是cumsum(单利)而不是cumprod(复利)。

下面的例子是一个绩效在不断下降的因子，我们试试看cumsum和cumprod画出来的图的区别。

import numpy as np  
import pandas as pd  
import random  
  
rts = \[\]  
gap = 0.001  
for group in range(10):  
    for n in range(1000):  
        rts.append(random.uniform(-0.01, 0.02 \- gap \* group))  
rts = pd.Series(rts)  
rts.cumsum().plot()  
(rts+1).cumprod().plot()

![](assets/001.png)

![](assets/002.png)

橙色线是cumsum，可以看到，因子的衰减一目了然。而反观cumprod，压根看不出来，这是复利的欺骗性。

所以，cumsum才是最好的方法。但是为什么市面上很多资料、报告都喜欢用cumprod，因为出发点不同，写报告的人想凸显自己的研究结果，把自己的报告卖出去。但是我们做实盘是不能自欺欺人的。

  

![图片](assets/003.webp)