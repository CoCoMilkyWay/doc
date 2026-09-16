# LOBERT：如何把高频交易变成一种“可学习的语言”

InfinityQuant 映翡量化 2025-11-22 10:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488269&idx=1&sn=5d8e4b7569496fee9f88cf1f9c6d43e3&chksm=9e55b11197b3e67c69a453aad76ae31d0eddb24471e7cf769b9675b3996865cbd7acf1b69a10#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488269&idx=1&sn=5d8e4b7569496fee9f88cf1f9c6d43e3&chksm=9e55b11197b3e67c69a453aad76ae31d0eddb24471e7cf769b9675b3996865cbd7acf1b69a10#rd)

LOBERT 是第一个真正实用的**限价委托簿（LOB）生成式基础模型**，把 BERT 成功搬到高频金融市场。每条完整 LOB 消息只用 1 个 token（传统模型拆成 22~24 个），上下文长度直接缩短 ~20 倍。

![](assets/001.png)

关键技术：

1️⃣离散 token（293 个）表示 方向+类型+粗价格/数量桶；

2️⃣连续回归头精确预测 价格、数量、时间差（用 PLGS 压缩）；

3️⃣Combined 推理：token 定大类 + 回归精细修正 → 分布最准；

4️⃣连续时间 RoPE + MMM 预训练（类似 BERT 的 MLM）。

实验结果（Nasdaq AAPL 等股票）：

1️⃣下一条消息预测：完整消息准确率 27.8%（vs S5 的 6.1%，提升 4.5 倍）；

2️⃣中价方向预测：全面超越 DeepLOB，尤其高置信时 F1 可达 0.88。

结论： LOBERT 是金融市场的“BERT”，首次实现一消息一token + 预训练微调范式，效率和效果双碾压现有模型，堪称高频市场生成式 AI 的里程碑。

![](assets/002.png)

  

https://arxiv.org/abs/2511.12563

  

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)