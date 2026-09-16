# 微架构为何比算法更重要——高频交易的隐藏战场

InfinityQuant 映翡量化 2025-10-13 08:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487475&idx=1&sn=5a2271b29b7012a4adf289de02686f1a&chksm=9e4e15982820a8b8d2ffcdb070fa38f327b6f505d4ac91f7be920faca2260dec38f404058d84#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487475&idx=1&sn=5a2271b29b7012a4adf289de02686f1a&chksm=9e4e15982820a8b8d2ffcdb070fa38f327b6f505d4ac91f7be920faca2260dec38f404058d84#rd)

当胜负以纳秒计时，高频交易的护城河不仅来自更聪明的模型，更取决于代码与硬件如何“对话”。  

  
这份白皮书拆解了常被忽视、却能把平庸系统托举到世界级水准的性能工程层：从 CPU 流水线、分支预测、缓存局部性，到 NUMA 感知、内核旁路网络、无锁数据结构，展示如何将延迟砍掉“倍数”而非“百分比”。

  
核心观点：  
1\.  优化 Lkernel + Luser 的收益，远高于给算法再省几微秒。  
2\.  分支感知设计与 SoA（结构体数组）数据布局，可显著提升可预测性与吞吐。  
3\.  内核旁路 + NUMA 绑核，解锁确定性、超低延迟表现。  
  

实战清单：  
附上一份可落地的检查表与真实重构案例：通过纯微架构级改动，把 tick-to-trade 延迟从 35 µs 压到 7 µs。

  

![](assets/001.png)

  

PDF版本在这里：

![](assets/002.jpg)

3天免费体验领取

![](assets/003.jpg)