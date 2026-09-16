# 更好的微观价格：F-price

锤哥 QuantSeek 2024-10-14 20:19 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484689&idx=1&sn=dd61c66f053d2a7dc154e3fac4481a49&chksm=ce1eae15e8f2321a8f43398727b88ccdda63fdf72fe929e0c11ab8058f3828c3fc692b50c8da#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484689&idx=1&sn=dd61c66f053d2a7dc154e3fac4481a49&chksm=ce1eae15e8f2321a8f43398727b88ccdda63fdf72fe929e0c11ab8058f3828c3fc692b50c8da#rd)

这篇文章提出了 F-price 作为替代中价以及成交量加权价格的更好的微观价格。老生常谈，作者从对Imbalance的解释性等3个方面实证了此定义的有效性。  

锤哥觉得这个定义的特点在于：1、成交量方面取了平方，使得价格能够偏离最佳bid和最佳ask. 2、考虑了交返(rebate).

  

详细的解读和**代码**实现请看星球

![](assets/001.png)

本号唯一的知识星球号定位：量化随笔，文献解读_（文章解读不像别的公众号只机翻，还有专业解读、个人观点）_，实盘经验分享，量化代码分享，公众号所有付费文章免费。