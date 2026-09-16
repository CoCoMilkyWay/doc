# 牛津大学｜哪种机器学习模型在量化交易中表现更好？

InfinityQuant 映翡量化 2026-03-11 10:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491193&idx=1&sn=2e70bf58610b74d042ff1d85a0d83ea9&chksm=9ee8a4f2702cb37586f9939ba80fe79a2474ca47f4765f8deb06f25c71f40f9ac303fe4802d1#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491193&idx=1&sn=2e70bf58610b74d042ff1d85a0d83ea9&chksm=9ee8a4f2702cb37586f9939ba80fe79a2474ca47f4765f8deb06f25c71f40f9ac303fe4802d1#rd)

**这篇最新论文《Deep Learning for Financial Time Series: A Large-Scale Benchmark of Risk-Adjusted Performance》（2026年3月2日）来自****牛津大学**（University of Oxford）。研究团队测试了一系列深度学习模型在2010至2025年间于期货、债券、外汇、大宗商品 和 股指 市场的表现。

核心结论很简单：具备更好记忆能力和特征选择能力的模型，在应对充满噪音的市场时表现要出色得多。**VLSTM**在整体表现上夺冠，而 **xLSTM**在应对交易成本的韧性方面展现出最强的实力。

![](assets/001.png)

核心亮点：

📊 **VLSTM 赢得了整体最佳。**其全周期的夏普比率最高达到了 2.40，并且在不同的市场环境下均保持强劲。

🛡️ **下行保护至关重要。**在评估回撤、尾部风险和表现最差的时期时，VSN+xLSTM 和 LSTM+PatchTST 表现得尤为稳健。

💸 **成本改变了整个局面。**xLSTM 具有最大的盈亏平衡交易成本缓冲（breakeven transaction cost buffer），这意味着一旦将真实的交易摩擦考虑在内，它的表现显得最具持久力。

🧠 偏置胜过模型规模（Bias beat scale）。那些专为学习稳定时序结构而构建的模型，击败了许多通用的 Transformer 模型和状态空间模型。这是一个极其重要的发现。

📉 **线性模型（Linear models）显得力不从心。**它们虽然偶尔会有几段不错的表现，但拉长时间来看却缺乏可靠性。

真正的启示是什么？停止对绝对收益的过度痴迷。真正能赢到最后的模型，是那些能够承受成本、控制 回撤 并在市场状态切换中存活下来的模型。这才是深度学习真正体现其价值的地方。

作者：Adir Saly Kaufmann, Kieran Wood, Jan Peter Calliess, Stefan Zohren  
𝐌𝐚𝐜𝐡𝐢𝐧𝐞 𝐋𝐞𝐚𝐫𝐧𝐢𝐧𝐠 𝐑𝐞𝐬𝐞𝐚𝐫𝐜𝐡 𝐆𝐫𝐨𝐮𝐩, University of Oxford  
𝐎𝐱𝐟𝐨𝐫𝐝 𝐌𝐚𝐧 𝐈𝐧𝐬𝐭𝐢𝐭𝐮𝐭𝐞 of Quantitative Finance

![](assets/002.png)

https://arxiv.org/abs/2603.01820

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)