# 𝐃𝐞𝐞𝐏𝐌：不再追逐平均表现，而是专门为最坏时期进行训练

InfinityQuant 映翡量化 2026-02-12 10:19 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490947&idx=1&sn=5563c137dcb11a8179ec1db1455acdfd&chksm=9e5c53f90e468a0e99859399c6e4df9918a5be28106bc92dd65e19557cf2e792778ef78680af#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490947&idx=1&sn=5563c137dcb11a8179ec1db1455acdfd&chksm=9e5c53f90e468a0e99859399c6e4df9918a5be28106bc92dd65e19557cf2e792778ef78680af#rd)

论文《DeePM: Regime-Robust Deep Learning for Systematic Macro Portfolio Management》（2026年1月9日）介绍了 **𝐃𝐞𝐞𝐏𝐌**，一个用于全球宏观交易的深度学习系统。来自**牛津大学**（Oxford）的研究。 

不先预测回报，而是端到端（end-to-end）直接学习投资组合。

尊重市场时机延迟、真实的交易成本，以及资产之间的经济联系。

核心思想是：针对历史上最差的时期进行训练，而非仅仅优化平均表现。正因如此，它在危机中保持稳定。

🧠 **因果延迟（Causal Lag）**：采用严格的一天延迟，让模型学习因果关系而非巧合。 

🕸️ **宏观图（Macro Graph）**：强制资产根据真实的经济学联系进行交互。

🛡️ **鲁棒风险（Robust Risk）**：针对历史上最差的窗口进行优化，而非平均值。 

💸 **真实成本（Real Costs）**：直接在扣除交易成本后的净回报上进行训练。 

📈 **超额表现（Outperformance）**：风险调整后回报大约是经典趋势模型的两倍。

![](assets/001.png)

![](assets/002.png)

  

https://arxiv.org/abs/2601.05975

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)