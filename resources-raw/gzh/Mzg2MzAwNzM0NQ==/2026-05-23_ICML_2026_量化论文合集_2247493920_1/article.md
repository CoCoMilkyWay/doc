# ICML 2026 量化论文合集

QuantML QuantML 2026-05-23 20:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493920&idx=1&sn=7caf149fcc088dea17d956c8788e9aec&chksm=cf2f98cf330afa6ea494b7a6767d791f0e1025f77e23bc0e355e341cd00a434923112b1343d2#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493920&idx=1&sn=7caf149fcc088dea17d956c8788e9aec&chksm=cf2f98cf330afa6ea494b7a6767d791f0e1025f77e23bc0e355e341cd00a434923112b1343d2#rd)

ICML 2026 量化相关论文合集。

![](assets/001.png)

## 一、量化

### 1\. Joint-Embedding Predictive Learning of Latent Market States in U.S. Equities

作者：Simon Mahns, Randall Balestriero, Mahmoud Assran  
链接：https://icml.cc/virtual/2026/poster/65643  
摘要：论文研究 JEPA 是否能学习美国股票市场的有效状态表征。方法将每日无序的个股特征映射为固定数量的 factor tokens，并通过时间 JEPA 的 masked prediction 学习紧凑的日度市场状态 embedding。实验显示，该 embedding 与实现波动率、相关性集中度、有效因子维度等二阶市场结构关联较强，与市场方向关联较弱；它更擅长刻画渐进式恢复过程，对突发压力启动的识别能力有限。

### 2\. Signature-Informed Transformer for Asset Allocation

作者：Yoontae Hwang, Stefan Zohren  
链接：https://icml.cc/virtual/2026/poster/62694  
摘要：论文提出 Signature Informed Transformer，用于资产配置中的端到端决策学习。模型使用 path signatures 编码路径依赖，并设计面向资产几何关系的注意力机制，直接以 Conditional Value at Risk 为优化目标，使特征提取和组合决策在同一策略中完成。实验覆盖多个股票资产池，并与传统策略和预测型基线比较。

### 3\. Global Merger-Arbitrage Forecasting with Language Models

作者：Hinal Jajal, Michał Mucha, Charles Sweat, Chris Pulman, Charlie Flanagan, Peter Anderson  
链接：https://icml.cc/virtual/2026/poster/60833  
摘要：论文研究大语言模型在全球并购套利预测中的应用。系统使用丰富文本证据，并结合并购套利专家经验进行 context engineering，再利用 outcome-conditioned gold reasoning traces 进行微调。模型输出交易按公告条款完成、出现更高报价、交易终止等概率预测，并在 42 个国家超过 400 笔大型交易的样本外测试中，与前沿模型和市场基线进行比较。

### 4\. Decision-focused Sparse Tangent Portfolio Optimization

作者：Haeun Jeon, Seunghoon Choi, Hyunglip Bae, Yongjae Lee, Woo Chang Kim  
链接：https://icml.cc/virtual/2026/poster/64722  
摘要：论文面向 sparse tangent portfolio optimization，提出端到端 decision-focused learning 框架。方法将 Sharpe ratio 最大化改写为符合 DPP 的凸优化层，并使用 smooth top-k operator 实现精确的 sum-to-k 稀疏预算，使预测、资产选择和再优化可以共同接受梯度训练。实验覆盖五个主要股票市场。

### 5\. Error Propagation in Dynamic Programming: From Stochastic Control to American Option Pricing

作者：Andrea Della Vecchia, Damir Filipovic  
链接：https://icml.cc/virtual/2026/poster/65273  
摘要：论文研究离散时间随机最优控制中的动态规划误差传播问题。作者使用 RKHS 中的 kernel ridge regression 与 Monte Carlo subsampling 估计 value function，并提出误差分解来控制各时间步的近似误差。论文进一步分析误差如何从到期日向初始时刻反向传播，并将该框架应用到美式期权定价问题。

### 6\. Learning The ESG Geometry with Domain Aware Language Models

作者：Kunal Pimparkhede, Chirayu Chaurasia, Jatin Roy, Mahesh Mohan M R  
链接：https://icml.cc/virtual/2026/poster/65502  
摘要：论文提出面向 ESG 投资的 domain-aware representation learning 框架。模型使用 value-aware tokens、block-wise orthogonal embeddings 和 FACET tokens，对 ESG 风险、金融收益、新闻和情绪等异构时间序列进行几何保持表征学习。训练目标同时覆盖未来值预测、轨迹分组、潜在空间检索和资产选择等下游任务。

### 7\. Position: Evaluating LLMs in Finance Requires Explicit Bias Consideration

作者：Yaxuan Kong, Hoyoung Lee, Yoontae Hwang, Alejandro Lopez-Lira, Bradford Levy, Dhagash Mehta, Qingsong Wen, CHANYEOL CHOI, Yongjae Lee, Stefan Zohren  
链接：https://icml.cc/virtual/2026/poster/67204  
摘要：论文讨论金融 LLM 评估中的偏差问题，列出 look-ahead bias、survivorship bias、narrative bias、objective bias 和 cost bias 五类常见偏差。作者回顾 2023 至 2025 年的 164 篇论文，发现单一偏差被讨论的比例均不超过 28%。论文提出 Structural Validity Framework 和评估清单，用于金融 LLM 系统的偏差诊断和部署前验证。

### 8\. Position: Current XAI Methods Cannot Satisfy Financial AI Explainability Requirements

作者：Dongxin Guo, Jikun Wu, Siu Ming Yiu  
链接：https://icml.cc/virtual/2026/poster/67240  
摘要：论文认为当前 XAI 方法难以满足 LLM 金融系统的监管解释要求。作者分析 EU AI Act、US FSOC/CFPB、UK FCA、BIS、MAS、HKMA 六类监管框架，并讨论 SHAP、LIME、Chain-of-thought explanation 等方法在大模型金融场景中的局限。论文覆盖信贷、交易和投顾三个高风险领域，并提出解释性改进与部署约束建议。

### 9\. Adversarially Robust Control of Conditional Value-at-Risk Via Kelly Conformal Inference

作者：Catherine Chen, Jingyan Shen, Xinyu Yang, Lihua Lei  
链接：https://icml.cc/virtual/2026/poster/63594  
摘要：论文提出在线、distribution-free 的 CVaR 控制框架，将 conformal tail risk control 扩展到非平稳和对抗环境。方法结合 conformal tail risk control、parameter-free online learning 和 Rockafellar-Uryasev 的 CVaR 变分表示，给出 adversarial regret 保证。实验场景包括组合风险管理和 LLM 毒性缓释。

### 10\. Online Conformal Prediction Via Universal Portfolio Algorithms

作者：Tuo Liu, Edgar Dobriban, Francesco Orabona  
链接：https://icml.cc/virtual/2026/poster/65365  
摘要：论文研究在线 conformal prediction，目标是在任意数据流上实现长期覆盖率，同时保持预测区间信息量。作者提出基于 pinball loss 的 regret-to-coverage 理论，并将问题约化为双资产组合选择，使用 universal portfolio algorithms 构建无需手动学习率调参的 UP-OCP 方法。

相关论文已整理至星球

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)