# 来自BlackRock的AlphaAgents: 基于多Agents的LLM在股票研究和投资组合管理中的应用

InfinityQuant 映翡量化 2025-08-23 01:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487198&idx=1&sn=4dcb638f12188b252fd554373f3c1da8&chksm=9e29f05741d9b3ef0f8d07b9ba87d48ec2f5981c217a5afd744204ba8c56dcbc8a88d0f333a0#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487198&idx=1&sn=4dcb638f12188b252fd554373f3c1da8&chksm=9e29f05741d9b3ef0f8d07b9ba87d48ec2f5981c217a5afd744204ba8c56dcbc8a88d0f333a0#rd)

这篇文章《AlphaAgents: Large Language Model based Multi-Agents for Equity Portfolio Constructions》由BlackRock的研究人员撰写，发表于arXiv（2025年8月15日）。探讨了利用大型语言模型（LLM）构建多Agents系统在股票研究和投资组合管理中的应用。

![](assets/001.png)

**多Agents系统的设计与协作机制**

1.  AlphaAgents框架，使用LLM（如GPT-4o）驱动三个专业智能体：基础Agent（Fundamental Agent，分析10-K/10-Q报告和财务报表）、情绪Agent（Sentiment Agent，分析新闻和分析师评级的情绪影响）、估值Agent（Valuation Agent，基于历史价格和成交量评估股票估值）。
    
2.  Agent通过角色提示（role prompting）和工具（如RAG检索、API调用、数学计算工具）协作生成股票分析报告。系统采用AutoGen框架，支持组聊天（group chat）和圆桌辩论（round-robin debate），以解决Agents间分歧、减少LLM幻觉（hallucination）和人类认知偏差（如损失厌恶）。
    
3.  框架可扩展，可添加更多Agents（如技术分析Agent或宏观经济Agent），并融入风险容忍度（risk tolerance），模拟风险厌恶（risk-averse）和风险中性（risk-neutral）投资者行为。
    

**缓解认知偏差与AI优势**

1.  强调多Agents系统能克服行为金融学中的人类偏差（如过度自信），通过Agents间辩论提供客观、多元视角。同时，减少AI自身问题如幻觉。
    
2.  与现有工作（如FinRobot、FinMem）相比，该系统聚焦于系统化股票选择和投资组合构建，强调代理交互、风险调整和工具集成，而非单一链式思考（chain-of-thought）。
    

**方法论与数据来源**

1.  数据包括Yahoo Finance的价格/成交量、10-K/10-Q财务披露和Bloomberg新闻。
    
2.  工作流程：Agent独立分析后协作/辩论，生成报告和买入/卖出推荐。风险容忍度通过提示工程嵌入，影响决策（如风险厌恶下更保守）。
    
3.  评估使用RAG指标（忠实度和相关性）和下游回测（back-testing），计算夏普比率（Sharpe Ratio）和风险调整回报。
    

**https://arxiv.org/abs/2508.11152v1**

  

![](assets/002.png)

此图片来源：

https://bigquant.com/square/paper/cb3f2934-2a11-4551-a99e-059eef444617