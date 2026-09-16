# 多Agent推理金融分析系统

InfinityQuant 映翡量化 2025-08-08 08:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487107&idx=1&sn=bbc955ad1f491dcc1122aafdf44791ca&chksm=9e18c02118753fe86b1b4edba10ec2e9655aa7b151dc20ff76e52717de2cf101bc66f5dc0d4d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487107&idx=1&sn=bbc955ad1f491dcc1122aafdf44791ca&chksm=9e18c02118753fe86b1b4edba10ec2e9655aa7b151dc20ff76e52717de2cf101bc66f5dc0d4d#rd)

Multi Agent Reasoning - 基于 Claude Sonnet 4 的多智能体推理金融分析系统，通过协作式 AI 智能体提供全面的投资和市场分析  
  
核心组件  
· Web Search Agent: 使用 DuckDuckGo 搜索金融相关新闻和市场动态  
· Finance Agent: 使用\`yfinance\`库获取股票价格、公司基本面、财务比率等金融数据  
· Reasoning Finance Team: Claude Sonnet 4 模型领导，GPT-4.1 作为智能体模型，通过 Agno 框架协调两个智能体，整合数据并生成结构化分析报告  
  
使用场景  
· 投资研究: 分析个股（如 Apple, AAPL）的价格、基本面、新闻和投资建议  
· 行业比较: 比较科技巨头（如 Apple、Google、Microsoft）的财务表现和市场动态  
· 风险评估: 评估个股（如 Tesla, TSLA）的波动性和风险回报  
· 市场情绪分析: 研究 AI 行业股票（如 NVIDIA、AMD）的新闻和市场前景  
· 财报季分析: 分析公司（如 Microsoft, MSFT）的财报预期和交易策略  
  
项目亮点  
· 多智能体协作: 智能体分工明确，协作生成综合分析  
· 数据驱动: 结合实时 Web 搜索和金融数据，提供基于事实的建议  
· 灵活性: 支持多种金融分析场景，可扩展到其他领域  
· 用户友好: 提供 Playground 界面，便于交互和测试

  

![](assets/001.jpg)

  

https://docs.agno.com/introduction

https://github.com/agno-agi/agno/tree/main/cookbook/examples/multi\_agent\_reasoning