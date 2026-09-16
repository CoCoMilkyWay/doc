# 从0.06到1.99夏普：用分层注意力让宏观数据真正“懂”市场

InfinityQuant 映翡量化 2026-06-05 09:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491876&idx=1&sn=f2f677e17868e4eb6ac5ec8cb3b008e7&chksm=9ea8419c1abfe990909336273d9f760fe39e9b93db8af9cb6a5e3ce556d9d00508c07f132532#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491876&idx=1&sn=f2f677e17868e4eb6ac5ec8cb3b008e7&chksm=9ea8419c1abfe990909336273d9f760fe39e9b93db8af9cb6a5e3ce556d9d00508c07f132532#rd)

0.06 夏普比率 vs. 1.99 夏普比率：使用完全相同的宏观数据，却得到截然相反的结果。区别仅仅在于**你如何把数据喂给模型**。

一篇新论文《Macro-aware time series forecasting via hierarchical mixed-frequency attention models》（2026年5月30日）提出了 **HANET**（混合 LSTM + Attention 架构），它让每日交易决策能够参考过去几十年的宏观经济背景。论文表明，**最传统的宏观数据使用方式实际上是有害的**。

-   把月度宏观因子**直接硬拼**到每日 LSTM 上（朴素做法）→ 仅得到 **0.06**夏普比率（比完全不使用宏观数据还差）。
    
-   通过**分层交叉注意力**（hierarchical cross-attention）来喂入相同因子 → 夏普比率飙升至 **1.99**，在时序动量策略上实现 **22.5%**的年化回报。
    
-   如果把宏观历史的时间顺序打乱 → 性能直接崩到 **0.81**。**时间结构才是核心**。
    

亮点：模型具有**可解释性**。在 2020 年期间，模型主要参考了 2008 年金融危机时期的记忆；在 2022 年通胀飙升时，它则回溯到了 20 世纪 80 年代初沃尔克时代的经验。

该方法在 **55 个期货品种**（商品、债券、外汇、股票）上进行了测试，同时也是首个针对 **carry（利差）策略** 的深度学习实现，并且在考虑交易成本后依然有效。

![](assets/001.png)

https://arxiv.org/abs/2606.00624

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)