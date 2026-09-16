# 一个真正理解波动率的生成模型，夏普比率2.11（有代码）

InfinityQuant 映翡量化 2026-04-17 08:57 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491495&idx=1&sn=de0813e71e405b2a3e2ce2365688a2d0&chksm=9e3d2b53e0c81e7f8ab7a14da570463b1da0323a4de16b4690ef4c2bf4d20512a1259e6d34b8#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491495&idx=1&sn=de0813e71e405b2a3e2ce2365688a2d0&chksm=9e3d2b53e0c81e7f8ab7a14da570463b1da0323a4de16b4690ef4c2bf4d20512a1259e6d34b8#rd)

《SBBTS: A Unified Schrödinger-Bass Framework for Synthetic Financial Time Series》（2026年4月8日）新论文介绍了 Schrödinger–Bass Bridge for Time Series（SBBTS），把薛定谔桥（Schrödinger Bridge, SB）和 Bass 鞅传输（Bass martingale transport）统一到一个最优传输框架下，用于生成兼具**真实漂移与随机波动率**的合成金融时间序列。

传统生成方法存在结构性短板：

-   经典 SB 类扩散模型能够拟合给定的边际分布并学习漂移，但波动率结构在建模时被固定，无法捕捉真实市场中的随机波动率与噪声相关性。
    
-   Bass 鞅传输及其变体专注于通过“本地波动率”来匹配分布形状，从而精准刻画波动率层面的结构，但在建模时基本忽略漂移，使得时间依赖和预测结构难以体现。
    

SBBTS 的核心思想：不再“二选一”地只拟合漂移或只拟合波动率，而是在同一个生成框架中，通过最优传输的目标函数，把漂移控制项与波动率控制项一并纳入优化，形成一个可调节、可学习、面向时间序列的统一生成模型。

在 433 只标普 500 指数成份股上的测试结果显示：

-   仅在 SBBTS 合成数据上训练的简单方向性策略实现了 **2.11**的夏普比率，而使用真实数据训练的策略为 1.61，零样本（zero-shot）表现则为 -0.25。
    
-   分类准确率跃升至 **53.2%**，在所有配置中拥有最低的对数损失（log loss）和最高的 ROC AUC。
    
-   白噪声增强（White noise augmentation）的效果远不及此：这种性能提升是**结构性**的，而非随机产生的。
    

在 Heston 模型基准测试中，SBBTS 能够还原“波动率的波动率”（vol-of-vol）以及相关性参数，而这些关键参数是标准薛定谔桥方法会完全遗漏的。

![](assets/001.png)

![](assets/002.png)

  

https://arxiv.org/abs/2604.07159

https://github.com/alexouadi/SBBTS

PDF和代码已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)