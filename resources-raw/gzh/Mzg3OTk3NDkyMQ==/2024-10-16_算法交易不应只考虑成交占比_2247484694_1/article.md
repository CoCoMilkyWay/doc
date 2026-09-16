# 算法交易不应只考虑成交占比

锤哥 QuantSeek 2024-10-16 16:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484694&idx=1&sn=186951b544fda89490b3870bd1e918fb&chksm=ce7effa3582c289af9fd5e9bba4c574d4a9293ffdaf30b4b0439403dee59c9a278b1596fab28#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484694&idx=1&sn=186951b544fda89490b3870bd1e918fb&chksm=ce7effa3582c289af9fd5e9bba4c574d4a9293ffdaf30b4b0439403dee59c9a278b1596fab28#rd)

在几乎所有下单算法的设计中，都非常强调参与率或者说成交占比这个指标，更不用说vwap就是纯粹的控制成交比例的简单算法。

今天这篇文章通过理论和实证发现了，参与率在另外3个因素下显得微不足道，锤哥感觉这篇文章对做算法设计的同学来说还是挺有意义的。

至于是哪3个因素，锤哥这里卖个关子，其中一个是区间的order imbalance，对整体订单流动态信息的建模比强调每一笔拆单的影响更为重要。

  

详细的解读请看星球。

![](assets/001.png)

本号唯一的知识星球号定位：量化随笔，文献解读_（文章解读不像别的公众号只机翻，还有专业解读、个人观点）_，实盘经验分享，量化代码分享，公众号所有付费文章免费。