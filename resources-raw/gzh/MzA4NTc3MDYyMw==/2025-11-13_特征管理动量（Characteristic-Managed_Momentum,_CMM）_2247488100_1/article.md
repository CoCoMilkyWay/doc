# 特征管理动量（Characteristic-Managed Momentum, CMM）——性能完爆传统动量策略

InfinityQuant 映翡量化 2025-11-13 09:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488100&idx=1&sn=53b28eda3167db44c057353d996c51c6&chksm=9e978b193725af9a22f0ec05bd7fb5ccc0ab41f2b7a780340f7418061a8e489e66a7ed20f64b#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488100&idx=1&sn=53b28eda3167db44c057353d996c51c6&chksm=9e978b193725af9a22f0ec05bd7fb5ccc0ab41f2b7a780340f7418061a8e489e66a7ed20f64b#rd)

论文《All Days Are Not Created Equal: Understanding Momentum by Learning to Weight Past Returns》发表于 _Journal of Banking and Finance_（2025），作者：Heiner Beckmeyer 与 Timo Wiedemann。文章通过机器学习智能挑选真正“有信息含量”的历史回报日，一种简单但强大的新策略——**特征管理动量（Characteristic-Managed Momentum, CMM）**——性能完爆传统动量策略，整整高出三倍。传统动量策略将过去一年（排除最近一个月）的每日收益等权平均不同，而CMM 通过机器学习方法**为不同日期的过去收益赋予差异化权重**，以识别哪些历史收益更能预测未来表现。研究发现，并非所有过去的收益日对未来回报的预测力相同，部分“重要日”（如收益公告日、大盘跳动日、个股大幅波动日）包含更强的趋势延续信息。

CMM 的构建保持了动量信号的可解释性：它仍是过去收益的加权平均，只是权重由神经网络模型根据企业特征与过去收益动态学习而得。研究表明，约有不到 15% 的历史交易日承担了大部分预测信息，其中仅两天的收益权重就占到 30%，30天超50%。这意味着市场中的部分“信息日”极其关键。

在实证结果上，CMM 的表现显著优于传统动量策略：

-   **年化收益率**18.5%（标准动量为13.2%），**夏普比率**1.47（标准动量仅0.49）；
    
-   在2003年后动量普遍失效的时期仍保持有效；
    
-   几乎不经历“动量崩溃”（最大回撤仅−27.6%，而传统动量为−80.3%）；
    
-   在国际市场同样稳健。
    

![](assets/001.png)

机制分析显示，CMM 的超额收益主要源自**投资者对信息的系统性“反应不足”（underreaction）**。模型倾向于为那些在形成期内出现较大绝对收益的日子赋予更高权重，这与市场未能及时反映重大信息相符；相反，过度反应（overreaction）的证据较弱。风险溢价或时间变动的系统性风险因子并不能解释 CMM 的表现。进一步的交叉检验证实，CMM 的盈利与“离散性信息释放”强相关，即当市场对分散发布的消息反应不足时，CMM 的预测力更强。

核心贡献在于：

1.  **方法创新**：利用机器学习学习“过去收益权重”，形成灵活的动量信号；
    
2.  **实证发现**：CMM 解释并超越传统动量，揭示“并非所有过去的日子同等重要”；
    
3.  **理论启示**：动量收益主要源自投资者对关键信息的持续低估，而非风险补偿；
    
4.  **实践价值**：CMM 提供了一种稳健、低风险的趋势投资框架，尤其在传统动量策略频繁失效的近二十年仍具显著超额收益。
    

  

动量因子的玩法很多，最近的一些关于动量因子的文章合集：

[动量因子——150年的证据与演进](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487998&idx=1&sn=67dc85dc85f430a2157031f27732b5f4&scene=21#wechat_redirect)

[夏普比率 3.0+ —— “排序学习”的动量策略](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487976&idx=1&sn=941f58f12c9ac32304f3c8a90a986417&scene=21#wechat_redirect)

[波动率管理因子，动量因子最受益](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487722&idx=1&sn=7d5110829cb15ad10cce3a127c265154&scene=21#wechat_redirect)

[动量策略已死？未必！](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487286&idx=1&sn=3f868f42d3ec2e28c39fd1a5346c64d0&scene=21#wechat_redirect)

[无处不在的因子动量：为何对你的投资组合至关重要](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486786&idx=1&sn=42b229f486617182daf3413da3fd491e&scene=21#wechat_redirect)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5702162

PDF已更新⬇️

欢迎加入：学术界的Alpha

![](assets/002.jpg)