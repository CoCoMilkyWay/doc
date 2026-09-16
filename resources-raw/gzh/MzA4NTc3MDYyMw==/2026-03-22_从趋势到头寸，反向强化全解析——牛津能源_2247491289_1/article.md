# 从趋势到头寸，反向强化全解析——牛津能源研究所最新CTA预测框架

InfinityQuant 映翡量化 2026-03-22 07:41 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491289&idx=1&sn=f0756275337af7ee697847c1fa441f15&chksm=9ecdf4cec9e204b7b0b1ffe469495d46295cc6f7d009a7f6a6ba6eb6d78d0a635a5a50f799af#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491289&idx=1&sn=f0756275337af7ee697847c1fa441f15&chksm=9ecdf4cec9e204b7b0b1ffe469495d46295cc6f7d009a7f6a6ba6eb6d78d0a635a5a50f799af#rd)

牛津能源研究所（Oxford Institute for Energy Studies）最新研究《Momentum Trading and Managed Money Positioning in Energy ：Relationships and Practical Applications》（2026年3月）提出了一种新的CTA模型，该模型能够捕捉管理资金头寸动态变化，显示出强劲的样本外预测性能，可用于预测管理资金头寸变化，并支持多项实际应用。

**核心观点：**

🔹 **CTA 的联动效应：**CTA 根据当前价格趋势建立头寸，而其建仓行为反过来又会强化价格动态。这解释了期货价格与每周管理基金（Managed Money）持仓数据之间观察到的强联动性。

🔹 **统一决策框架：开发了一个 CTA 模型，能够模拟趋势追踪基金的决策过程，并在一个统一的框架下捕捉跨多个市场的趋势追踪行为。**

🔹 **分离系统性与主观持仓：**该模型将“通用趋势信号的生成”与“特定市场的资本配置决策”分离开来。通过引入一个时变偏置项（time-varying bias term），模型能够捕捉到系统性趋势追踪策略之外的主观持仓（discretionary positioning），从而有助于更精准地识别趋势追踪行为。

🔹 **前瞻性预测与分解：**该框架可以预测截至周二收盘的管理基金头寸（领先于周五的官方发布），并能分解出系统性趋势追踪和主观持仓的具体构成。

🔹 **跨市场扩展：**该方法可以扩展到金属等其他市场，为持仓动态提供跨市场的深度洞察。

![](assets/001.png)

累计全市场：本模型44.59%，基准仅21.08%。分市场、分年度，本模型在几乎所有子样本中均显著优于基准（2025年WTI例外，但方向准确率仍高）。

![](assets/002.png)

  

https://www.oxfordenergy.org/wpcms/wp-content/uploads/2026/03/Insight-177-Money-Positioning-in-Energy.pdf

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)