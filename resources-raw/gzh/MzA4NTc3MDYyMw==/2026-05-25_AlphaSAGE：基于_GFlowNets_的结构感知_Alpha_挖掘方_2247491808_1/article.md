# AlphaSAGE：基于 GFlowNets 的结构感知 Alpha 挖掘方法

InfinityQuant 映翡量化 2026-05-25 09:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491808&idx=1&sn=32caa332bab30b6dd1ea7980f6af8f6e&chksm=9e5a58609a6fee371ce0f55e632bf8f2f61c300e9bfcb39d54ccded5180cd27c8e7b40378a93#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491808&idx=1&sn=32caa332bab30b6dd1ea7980f6af8f6e&chksm=9e5a58609a6fee371ce0f55e632bf8f2f61c300e9bfcb39d54ccded5180cd27c8e7b40378a93#rd)

6.32 的夏普比率，19.47% 的年化收益，4.2% 的最大回撤。

《AlphaSAGE: Structure-Aware Alpha Mining via GFlowNets for Robust Exploration》（最新更新版2026年5月19日）这篇 ICLR 2026 新论文提出了一个很巧妙的思路：不要再试图寻找“唯一最优”的 alpha 公式，而是去采样一个“多样化的 alpha 组合”。

主要方法：

用 GFlowNets 替代传统强化学习。GFlowNets 是一种生成模型，会按奖励成比例地采样多个解，而不是收敛到单一最优解。再结合：

-   基于抽象语法树（AST）的 RGCN 编码器（因为 close + open 和 open + close 本质是同一公式，而 LSTM 无法识别这种等价性）
    
-   一个包含 IC（信息系数）+ 结构对齐 + 新颖性的稠密奖励函数
    
-   加入熵正则化，用于维持探索能力
    

结果：

在 CSI300/500/1000 和 S&P500 上的所有相关性指标和组合指标中均排名第一，并且训练速度比 AlphaGen、AlphaQCM 和 AlphaForge 快 2–3 倍。

消融实验中提升最大的因素并不是复杂的奖励设计，而是图结构编码器。结构的重要性远超大多数人的预期。

![](assets/001.png)

![](assets/002.png)

https://arxiv.org/abs/2509.25055

https://github.com/BerkinChen/AlphaSAGE

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)