# AI 模型对“风险”的思维方式与人类截然不同

InfinityQuant 映翡量化 2025-11-08 08:12 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488006&idx=1&sn=bc110da970d061d9fe669cce3612bc6c&chksm=9e156769446c15aceb66ff4c6cf872c92cb97ec1714de2b88164eedd624a83cc91e202d1a88b#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488006&idx=1&sn=bc110da970d061d9fe669cce3612bc6c&chksm=9e156769446c15aceb66ff4c6cf872c92cb97ec1714de2b88164eedd624a83cc91e202d1a88b#rd)

《Risk, Ambiguity, and Infinity：Behavioral Signatures of Modern Large Language Models》，揭示了 GPT 模型如何处理风险、模糊性以及无限收益，并指出它们的决策与人类存在显著差异。  

  
核心发现：AI 的风险行为与人类或交易员的风险偏好并不一致。  

这一差距至关重要。当 AI 被用于决策时，它可能采取对模型而言看似合理、但对我们而言却非理性的行动。  
金融从业者与研究者应在将模型用于交易、资产配置或定价前，量化并校准其风险容忍度。若缺乏这种对齐，AI 驱动的策略可能在不知不觉中扭曲风险-收益结构。  

在更广泛的模型对齐议程中，加大对 AI 风险画像对齐的研究。在无法测量并调整模型风险偏好之前，将其用于复杂金融决策本身就意味着风险。  
  
🎯 风险画像：在 107 组 Holt–Laury 彩票任务中，GPT-4 各版本表现出极度风险厌恶；GPT-5 接近风险中性，更频繁选择高期望值（EV）的冒险选项。给 GPT-4 套上“战略思考者”人设后，它会变得风险偏好，而 GPT-5 仍保持平衡。  
🧭 模糊性：在 Ellsberg 模糊任务中，GPT-4.1 与 4o-mini 几乎完全回避模糊；GPT-5 则能容忍模糊。人设提示可把 GPT-5 和 o3-mini 推向中性，GPT-4o 略有缓和，GPT-4.1 纹丝不动。部署前务必校准。  
🧪 无限收益：在圣彼得堡悖论游戏中，GPT-4 的参与门槛与人类在低手续费时的谨慎表现相仿；GPT-5 与 o3-mini 即使手续费升高仍继续参与；人设还会进一步提高它们的参与阈值。需加装折现护栏与手续费上限。  
🛠️ 落地建议：  
•  按行为选模型，而非按品牌。  
•  用人设微调，但警惕“用力过猛”。  
•  加任务级约束与价格阈值。  
•  沿风险、模糊、无限收益三条轴独立测试。  
•  记录参数以供审计，并用线上 A/B 实验持续迭代。

![](assets/001.png)

![](assets/002.png)

  

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5688064

PDF已更新⬇️

欢迎加入：学术界的Alpha

![](assets/003.jpg)