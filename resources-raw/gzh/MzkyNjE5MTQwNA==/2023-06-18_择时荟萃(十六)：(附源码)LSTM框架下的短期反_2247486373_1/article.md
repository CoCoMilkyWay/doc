# 择时荟萃(十六)：(附源码)LSTM框架下的短期反转+长期动量合成策略

partition 量化前沿速递 2023-06-18 15:12 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486373&idx=1&sn=a5efb7cbd1aba8ea27931460499b6dbb&chksm=c3c4a3f66b6bf1274bac76bee1ad8b87ab0251c00842cc0dc7dc9871cb8101bf5b7eb472c51a#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486373&idx=1&sn=a5efb7cbd1aba8ea27931460499b6dbb&chksm=c3c4a3f66b6bf1274bac76bee1ad8b87ab0251c00842cc0dc7dc9871cb8101bf5b7eb472c51a#rd)

择时系列第十六篇，分享一篇使用LSTM模型对短期反转和长期动量进行组合的择时策略。传统的择时策略在动量崩溃时难以快速响应，本文的策略在这一点上能有效提升，使用动量把握长期趋势，用反转捕捉短期变化。作者在文中一并附上了代码，获取原文请在后台回复“**择时16**”。  

**策略综述**：这里的长期动量用12个月的收益率表示，短期反转为1个月收益。策略构建的思路比较朴素，作者使用了一个变点检测模型CPD(ChangePoint Dection)，正常时候使用长期动量去跟踪趋势，当检测到变点后，切换为短期反转信号，做均值回归。CPD是一个纯统计的模型。LSTM在这里起到的作用在于，CPD的输出是一个0-1的得分，作者将这一得分和其他一些价量信号一起作为LSTM的输入，用LSTM模型的输出作为策略信号。

**CPD部分**：关于CPD的算法略过，附上ChatPDF的说明，详见报告。

![](assets/001.png)

如下图是标普500做CPD的一个例子  

![](assets/002.png)

CPD模型最终输出两个值，变点的位置和变点的得分，作者发现接入这两个值后模型表现和稳定性均有提升。  

![](assets/003.png)

**策略说明**  

传统的时序动量可以表示如下  

![](assets/004.png)

在传统时序动量基础上叠加短期反转  

![](assets/005.png)

策略的设置主要是对w的值进行确定。

**LSTM部分**  

模型输入  

![](assets/006.png)

损失函数：夏普比

![](assets/007.png)

**策略表现**

红色框中为不同窗口期下的策略，相比TSMOM、Long Only策略，收益、夏普比、回撤表现均有显著提升

![](assets/008.png)

作者在多个品种上进行了测试，均有效  

![](assets/009.png)

并且能看出，LSTM+CPD版本优于纯LSTM版本

![](assets/010.png)

以上为全文主要内容，代码有些长，就不附了，感兴趣自己下载了解吧  

![](assets/011.png)

最后附上ChatPDF的说明  

![](assets/012.png)

![](assets/013.png)

![](assets/014.png)

![](assets/015.png)

以上全文

觉得不错可以点在看/赞支持一下