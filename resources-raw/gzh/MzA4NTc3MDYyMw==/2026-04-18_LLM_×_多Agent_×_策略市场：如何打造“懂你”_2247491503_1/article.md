# LLM × 多Agent × 策略市场：如何打造“懂你”的投资组合策略？

InfinityQuant 映翡量化 2026-04-18 08:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491503&idx=1&sn=215879ed97f6ffea29c55ac31b2b9c6f&chksm=9eaf282d321a4aca89aa4222cbed70adc0ad5d567ac6eecd0b2fd068210386c3972d734c3596#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491503&idx=1&sn=215879ed97f6ffea29c55ac31b2b9c6f&chksm=9eaf282d321a4aca89aa4222cbed70adc0ad5d567ac6eecd0b2fd068210386c3972d734c3596#rd)

Tensor Systems与AlphaNet团队最新论文《Novel Agentic System for User Preference-Driven Strategy Selection——A Comprehensive Design for LLM-Based Multi-Agent Quantitative Portfolio Construction》设计了一个用大模型多智能体来做量化策略选择和组合的系统，核心是通过自然语言对话，实现用户偏好驱动的策略筛选与投资组合构建，同时保持可解释和可监管。

## 核心思路

-   四层架构：对话界面、多智能体编排层、工具与数据层（RAG、回测、相关性、行情等）、执行层（黑盒交易微服务），智能体只负责“给组合建议”。
    
-   六个专用 agent：User Profiler 通过聊天量化风险偏好、收益目标和约束；Strategy Analyst 用向量检索+RAG 找策略并打分；Portfolio Constructor 在工具配合下给出权重；Risk Manager 独立做压力测试和约束检查等；Deployment负责打包信号传输给执行微服务；Monitoring 负责实时监控、再评估触发。
    
-   策略以微服务形式接入，只开放“历史/实时信号”API，不暴露代码和模型，通过统一回测、相关性、信号质量分析等工具，从信号推导出夏普、回撤、相关性和 regime 表现，用于组合构建和风控。
    
-   整个流程：用户一句话 → 画像 → 检索 → 构建 → 验证 → 部署 → 监控，延迟目标<30秒，推理连贯性目标>4.0/5.0。
    

![](assets/001.png)

## 关键机制与结论

-   采用三层记忆（短期对话、中期会话状态、长期策略和用户画像）和 RAG，将用户偏好编码为向量，在策略嵌入空间检索候选，再用硬指标过滤，并要求 LLM 的每个结论都被设计为尽量引用数据以减少幻觉，提升可审计性。
    
-   未给出具体回测数据，而是定义了清晰的复合评估分数（目标>0.75）：
    

-   组合层面：夏普>2.0、回撤<15%、相关性<0.3、各状态下夏普>1.5、3-8只策略。
    
-   系统层面：检索精度>80%、约束满足>95%、推理连贯性>4.0等。
    

-   系统通过波动率、相关性、动量和宏观指标识别市场状态，对每个策略维护分状态绩效，并按当前状态的适配得分对权重做软调整；底层用 Kafka+Flink 区分“慢数据”（建组合）和“快数据”（监控与触发再平衡），避免过度交易。
    
-   给出一个 18 个月的实施路线，从小规模端到端原型开始，逐步补齐各 agent、实时数据、策略上架流水线、扩展到 100+ 策略，并通过组合绩效和系统推理质量综合评分（目标>0.75）来衡量整体成效。还对比了不同LLM提供商（OpenAI、Anthropic、Moonshot等）的适用场景，推荐异构部署以平衡成本和性能。
    

一句话总结

LLM可解释性+确定性工具Agent+微服务架构，是实现“用户中心、可解释、市场状态自适应”量化策略选择的理想路径。它不仅解决了传统方法的痛点，还为第三方策略市场构建了可扩展的生态。

作者之前的两篇大作：

[动态TWAP优化深度解析：强化学习与传统随机控制的比较实证](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488724&idx=1&sn=c1e86575efaf1250518201c90ce16d8b&scene=21#wechat_redirect)

[如何用AI系统化和可解释地挖掘因子](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488711&idx=1&sn=9880b14b9428cfae9a93d21067a30b44&scene=21#wechat_redirect)

  

https://alphanet.global/Novel-Agentic-System-for-Strategy-Selection-V1.pdf

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)