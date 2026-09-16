# 牛津大学 Hans Buehler 团队｜ DYSANOS ：生成式动态平滑无套利非参数期权曲面

InfinityQuant 映翡量化 2026-07-30 11:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247492534&idx=1&sn=958067ac7fa81b88491cf667c6fd80f0&chksm=9e6c684115261b862fda3e336d8d2382ef16ceb853410cb502f72641b9b68cb6a8701a0c53d2#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247492534&idx=1&sn=958067ac7fa81b88491cf667c6fd80f0&chksm=9e6c684115261b862fda3e336d8d2382ef16ceb853410cb502f72641b9b68cb6a8701a0c53d2#rd)

在定量金融与衍生品定价领域，“校准”（Calibration）与“动力学”（Dynamics）之间的权衡一直是业界和学术界的核心痛点。传统的本地波动率（Local Volatility）模型虽然能较好地拟合当前市场，但往往需要较多的人工干预，且其动力学演化在实际模拟中难以令人满意。

在第十三届巴舍利耶世界金融数学大会（XIII Bachelier World Congress）上，牛津大学Hans Buehler教授 携手 Blanka Horvath、Anastasis Kratsios等学者，展示了他们最新的研究成果：《DYSANOS - Generative Dynamic Smooth Arbitrage-free Non-parametric Option Surfaces (Presentation)》（2026年7月23日）。该框架通过有机结合线性规划、特征编码与深度对冲（Deep Hedging）技术，为构建严谨无套利、平滑且可用于风险中性模拟的生成式期权市场模型提供了一种端到端的解决方案。

背景：建模期权市场的传统困境

构建期权市场模型历来面临两难：

-   灵活度高的模型往往对现实拟合不佳；
    
-   拟合精度高的模型（如局部波动率模型）则校准困难、计算昂贵，且需要大量人工干预。
    

SANOS：用“Black–Scholes 加权混合”绕过麻烦

核心思想：

-   将每个期权价格表示为在一系列行权价网格上的 简单 Black–Scholes 价格的加权和；
    
-   由于这种结构在数学上被保证不存在静态套利，因此拟合过程不再是“艺术”，而是一个可以直接调用现成优化器的快速线性规划问题。
    

在实证测试中，SANOS 能在远不到一秒的时间内，对真实 SPX 期权中的 91.4% 给出落在买卖价差内的价格。

从五年曲面到“20 数状态”：压缩与动态模拟

进一步将五年历史中每天拟合出的期权曲面压缩为一个 每日 20 维状态向量，然后：

-   使用主成分分析（PCA）发现，实际上只有 五个主要驱动因子 能解释曲面动态；
    
-   基于这五个因子构建生成模型，在风险中性测度下对未来的期权市场进行模拟。
    

正如作者所言，一旦搭建完成，“它很快”（"it is fast"）。

对交易与研究的意义

对量化交易者和研究者而言，SANOS/DYSANOS 提供了一条真正可操作的路径：

-   无需每天手动调参去“捏”出一个波动率曲面；
    
-   即可生成“像真实市场一样行为”的期权市场情景，用于压力测试、策略回测与风险管理。
    

![](assets/001.png)

![](assets/002.png)

  

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=7047878

https://arxiv.org/abs/2601.11209

PDF已更新⬇️，更多策略、资讯⬇️

学术界的Alpha