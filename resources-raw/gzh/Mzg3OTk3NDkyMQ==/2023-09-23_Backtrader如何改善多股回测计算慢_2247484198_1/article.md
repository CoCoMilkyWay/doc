# Backtrader如何改善多股回测计算慢

锤哥 QuantSeek 2023-09-23 09:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484198&idx=1&sn=ac11e55fc2cb755608a1d00a2afd9045&chksm=ceb8dd0bbf59917aa71abc1781d8a95eacb22fd859545c1c91f32e49e4d66813834550e80c85#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484198&idx=1&sn=ac11e55fc2cb755608a1d00a2afd9045&chksm=ceb8dd0bbf59917aa71abc1781d8a95eacb22fd859545c1c91f32e49e4d66813834550e80c85#rd)

我发现这个问题现在还有人问，索性写篇文章说下这个问题：

这基本是无法解决的问题，backtrader本来就很慢，别说多股，单股都快不到哪里去，解决的办法也不只针对backtrader：

1、多进程，向量化。

2、先计算，**存中间结果**，再回测，反正先算嘛，以后想到怎么回测在回测，不要把计算放在用bt回测的时候。

这和金融知识无关，完全是自己编程能力的问题。