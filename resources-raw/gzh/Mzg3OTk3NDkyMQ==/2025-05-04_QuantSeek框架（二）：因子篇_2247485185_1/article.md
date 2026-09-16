# QuantSeek框架（二）：因子篇

QuantSeek QuantSeek 2025-05-04 09:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485185&idx=1&sn=7ad01f8f07e9d07191e4cd0aac5425ea&chksm=ce6b30c80ff3603ed62e787754e56531f71e66e1a16b8aebdb945a1104b6b0800ccdc830323a#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485185&idx=1&sn=7ad01f8f07e9d07191e4cd0aac5425ea&chksm=ce6b30c80ff3603ed62e787754e56531f71e66e1a16b8aebdb945a1104b6b0800ccdc830323a#rd)

# 

QuantSeek V2版本正式发布了！这个版本更新了可能是最为重要的因子定义和落盘功能。 前文回顾：

[写给苦苦挣扎的Quant（2）——极简QuantSeek投研框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485132&idx=1&sn=fce61f52f8122a9d512469c416341d8c&scene=21#wechat_redirect)

[QuantSeek框架（一）：数据篇](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485149&idx=1&sn=0090555b876cd06e106b0d07e1c42d61&scene=21#wechat_redirect)

  

## unsetunset因子为什么要持久化unsetunset

其实这个问题和数据为什么要落盘是一样的。简而言之，因子的持久化存储是为了后续更快速更方便地进行模型研究。

## unsetunset因子的数据库设计unsetunset

QuantSeek对因子的存储，采取了和原始数据类似的方式，保持了代码的一致性。详细可以看[QuantSeek框架（一）：数据篇](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485149&idx=1&sn=0090555b876cd06e106b0d07e1c42d61&scene=21#wechat_redirect)。

## unsetunset因子的更新流程unsetunset

通常来说，我们每天盘后将底层数据更新完成后，就可以更新因子了。

## unsetunset为何放弃死板的因子模板以及表达式因子为何不够用unsetunset

因子的更新有2个特性，一个是流程性，一个是灵活性，这两个特性是冲突的：

1.  流程性：框架要定义好简洁的更新流程，最大限度方便使用者定义新的因子。
    
2.  灵活性：框架要适应各种类型因子的定义。
    

在目前的一些开源框架中，你会看到流程性做得特别好，因子类写的高度抽象，增加一个新的因子只要改改表达式就好了。这种处理看似方便，实则根本不方便定义特殊的因子。

因子包罗万象，种类繁多，体现在算法上，也体现在其所需要用到的数据上，高度模板化的写法牺牲的是最终的模型绩效！

QuantSeek对这件事的处理是灵活开放的，框架并不排斥类似表达式的因子定义方法，反而是高度兼容的。但是QuantSeek对用户开放的因子定义空间，可以让用户实现高度灵活的因子定义方式。请用户参考定义例子id\_1\_\_Tech\_\_DayFactors.py。

## unsetunsetQuantSeek到底值不值unsetunset

QuantSeek没有开源，只对星球用户开放，是因为我觉得这个东西是有价值的，这是我自己都在使用的框架，商业化才能让QS持续走得更远。

星球有点小贵，单单QuantSeek框架，如果你自己写这个东西，悟性很足，把所有的坑都填完，至少半年。做事情就是省钱和省时间的权衡。

  

![](assets/001.jpg)