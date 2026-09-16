# 当机器学习撞上马科维茨

InfinityQuant 映翡量化 2026-01-04 17:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490359&idx=1&sn=e651214c8e5578771e9b5f71c31bfe2c&chksm=9e101b07c3c595193b73d604ca43b0a86a06418d8cf440fb5a0de43920d5f71c5fb5f52d2a46#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490359&idx=1&sn=e651214c8e5578771e9b5f71c31bfe2c&chksm=9e101b07c3c595193b73d604ca43b0a86a06418d8cf440fb5a0de43920d5f71c5fb5f52d2a46#rd)

一篇最新论文《Machine Learning Meets Markowitz》（2025年12月22日）指出，“预测收益”和“构建组合”本就不该分两步走。作者们发现，传统 ML 模型只优化 MSE（均方误差），而不是投资者真正关心的结果。他们提出的端到端（End-to-End）方法，直接把模型训练目标设为组合绩效、风险与成本。用 2010–2023 年中国 A 股数据测试，该方法在真实约束下实现了更高收益、更低换手率和更优表现。研究来自杜克大学、清华大学与 NBER。

![](assets/001.png)

📌 端到端 ML：直接为组合结果训练，而非仅仅追求预测精度——为效用训练，不为 MSE 训练。

📈 收益：纯多头组合较传统“两步走”模型提升约 12 个百分点。

💸 成本：当交易成本上升时，模型学会降低交易频率，而非失控放大。 

🧠 偏好：不同风险偏好会导出不同的最优预测与组合。

📉 现实性：在禁止做空、只能日频交易等真实约束下结论依然成立。

  

作者与机构：  

Yijie Wang　同济大学  

Hao Gao　清华大学  

Campbell R. Harvey　杜克大学 & NBER  

Yan Liu　清华大学  

Xinyuan Tao　新泽西理工学院

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5947774

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)