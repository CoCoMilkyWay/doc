# J.P.Morgan｜TradeFM：交易流和市场微观结构的生成式基础模型

InfinityQuant 映翡量化 2026-03-03 09:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491124&idx=1&sn=20313b046f5a72c239b33349024bf277&chksm=9e92de38dbfb6e922144bb28dda41a80e1d2708dff8e5021433875eee5abdd0967aa104c41a1#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491124&idx=1&sn=20313b046f5a72c239b33349024bf277&chksm=9e92de38dbfb6e922144bb28dda41a80e1d2708dff8e5021433875eee5abdd0967aa104c41a1#rd)

J.P.Morgan AI Research 团队的最新论文《TradeFM: A Generative Foundation Model for Trade-flow and Market Microstructure》（2026年2月27日）开发了 **524M 参数生成式 Transformer 基础模型**，专为金融市场微观结构和订单流设计。

![](assets/001.png)

**核心亮点**：

-   从 >9000 只美股的 **数十亿交易事件**（>10B tokens）中预训练，学习统一、跨资产的交易动态。
    
-   创新使用**规模不变特征**+ **通用标记化**，将异质多模态事件流转为统一离散序列，无需针对每只股票单独校准。
    
-   仅依赖**部分可观察**的事件流（单个参与者视角），而非完整限价订单簿（LOB）。
    
-   与确定性市场模拟器闭环集成，生成的交易序列能很好重现金融回报**风格事实**（重尾、波动聚类、无自相关）。
    
-   量化表现：分布误差比复合 Hawkes 基线低 **2–3 倍**；零样本（Zero-shot）泛化到亚太市场（日本、中国），困惑度仅适度上升。
    

**意义**：证明市场微观结构存在可迁移的通用结构，为合成数据、压力测试、AI 交易代理奠定基础。

一句话概括：TradeFM 把 LLM 式基础模型范式成功带入高频金融微观结构，实现大规模、跨资产、部分观察的生成式建模。

![](assets/002.png)

https://arxiv.org/abs/2602.23784

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)