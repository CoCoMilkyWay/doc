# AB-SSM：面向高频动态投资组合管理的强化学习框架

InfinityQuant 映翡量化 2026-05-15 08:58 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491676&idx=1&sn=9f9fad5b55fc773fe4a9c9214520e6b4&chksm=9ec2b44fccf4ef6ab160fbbcb96faa320d10a7d6073be14f9f0468680c4f0f43493afdd6b7b1#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491676&idx=1&sn=9f9fad5b55fc773fe4a9c9214520e6b4&chksm=9ec2b44fccf4ef6ab160fbbcb96faa320d10a7d6073be14f9f0468680c4f0f43493afdd6b7b1#rd)

高频交易（HFT）是指每秒执行数千笔交易，以利用转瞬即逝的价格低效机会。在动态投资组合管理中，HFT至关重要，因为它允许机构投资者实时调整资产配置，在高度波动的市场环境中最大化风险调整后收益——在这种环境中，毫秒级的延迟都可能导致重大损失。

目前许多HFT管理策略依赖于深度强化学习（DRL），并搭配循环神经网络（RNN）或Transformer等架构。然而，这些模型面临两大主要挑战：

1.  非平稳性（Non-Stationarity）：金融市场是“线性时变”系统，模式不断发生漂移（域偏移），导致静态模型迅速过时。
2.  资产相关性：标准模型难以捕捉不同资产之间复杂而全局的相互依赖关系，而这种相关性对于分散化投资至关重要。

为解决上述挑战，《Adaptive Bidirectional State Space Model for High-frequencyPortfolio Management》（2025年）提出了AB-SSM（Adaptive Bidirectional State Space Model，自适应双向状态空间模型）。这是一个增强DRL范式的框架，它集成了专为高频数据设计的状态空间模型。与标准SSMs不同，AB-SSM采用以下设计：

-   自适应线性时变结构：使用输入依赖的状态转移矩阵，能够实时更新，从而捕捉不断变化的时间模式和套利机会。
-   双向状态空间层：通过同时压缩前向和后向时间方向的全局上下文来提取资产相关性，使模型比单向模型能更清晰地“看清”资产之间的关系。

AB-SSM在基准测试中与SOTA（最先进）的高频交易基线进行了对比，包括EIIE（相同独立评估器集成）、DeepScalper以及基于Transformer的标准强化学习代理。测试覆盖美国市场、中国市场和加密货币市场，结果显示AB-SSM在累积收益和\*\*夏普比率（风险调整后收益）\*\*上均显著优于这些基线。

AB-SSM的成功在于，它将SSMs的低时空开销（这对HFT的速度要求至关重要）与更强的市场非平稳性和跨资产依赖建模能力相结合，使其成为适应现代数字市场高速需求、更稳健的通用框架。

![](assets/001.png)

![](assets/002.png)

  

https://dl.acm.org/doi/pdf/10.1145/3746252.3761246

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)