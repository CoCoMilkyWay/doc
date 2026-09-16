# 基于卡尔曼滤波的时变因子择时：夏普比率大幅提升

InfinityQuant 映翡量化 2026-05-28 10:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491851&idx=1&sn=76122325c0777091f4e4defa7a7e7b73&chksm=9ee431ad4ff8ec15ac5d98b9a14b5cfa8c1a61a3642cc248163b6560ebfa7e418b3a66e54e04#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491851&idx=1&sn=76122325c0777091f4e4defa7a7e7b73&chksm=9ee431ad4ff8ec15ac5d98b9a14b5cfa8c1a61a3642cc248163b6560ebfa7e418b3a66e54e04#rd)

HML 因子曾沉寂了十多年，但被卡尔曼滤波器重新激活。

一篇最新论文《Conditional Equity Factor Risk Premium》（2026年5月26日）估计了 14 个股票因子的条件（时变）风险溢价，并据此进行因子暴露的动态择时。

主要因子夏普比率提升如下：

-   BAB 夏普比率：0.59 → 1.35
    
-   HML 夏普比率：0.12 → 0.56
    
-   LTR 夏普比率：0.08 → 0.57
    
-   ROE 夏普比率：0.51 → 1.10
    

![](assets/001.png)

核心方法：

将随机贴现因子（SDF）分解为“市场成分 + 未来投资机会集合”，然后利用卡尔曼滤波，根据已实现收益作为观测信号，对不可观测的第二部分进行估计。

额外发现：

估计得到的风险溢价与宏观经济状态具有清晰对应关系：

-   当信用风险上升（BAA–AAA 利差扩大）时，mkt-rf、SMB、STR 因子收益更高。
    
-   当期限结构变陡时，HML、RMW、CMA、ROE、EG 因子收益更高。
    

总结：

这篇论文再次表明，许多“已死”的因子并非真正失效，而是缺乏合适的条件信息和动态管理。当使用时变风险溢价进行择时后，这些因子的表现潜力被大幅释放。

![](assets/002.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6813642

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)