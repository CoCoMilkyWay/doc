# AI-Kline + MCP : 开源个人AI看线助手

QuantML QuantML 2025-06-03 17:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490599&idx=1&sn=7861349115d7032a7aa48ded5127451e&chksm=cf0a92bfdcd4085d89d25e9cc5afae6d3880eab79beb18e9ddb648a898037e4cebd69748b4f1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490599&idx=1&sn=7861349115d7032a7aa48ded5127451e&chksm=cf0a92bfdcd4085d89d25e9cc5afae6d3880eab79beb18e9ddb648a898037e4cebd69748b4f1#rd)

## 简介

QuantML开源项目AI看线（AI-Kline）是一款集成了K线、技术指标、财务信息和新闻数据的AI分析与预测框架。该框架为用户提供了命令行和Web界面的双重使用选择。

项目地址：https://github.com/QuantML-Github/AI-Kline

近期，我们观察到多个类似项目相继涌现，包括头部机构的研报和个人开发的项目。这表明，AI投研助手正逐步从理论研究走向实际应用。

在专注于前沿深度学习研究的同时，AI+量化也是QuantML社区重点研究和分享的方向之一。此次，我们对AI看线（AI-Kline）进行了重大功能升级，引入了模型上下文协议（MCP）功能。这使得用户能够通过大模型随时调用和管理AI看线内置的各项功能。

模型上下文协议（MCP）是由Anthropic开发的一种开放标准，旨在解决AI助手，特别是大型语言模型（LLM）在数据访问方面的限制问题。通过提供一种通用的协议，MCP帮助AI系统连接到外部数据源和工具，从而提升响应的质量和相关性。我们曾在QuantML的历史文章中介绍过多种实用的MCP SERVER，详情可参考相关教程：

[MCP深入分析：现状、安全与未来](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490139&idx=1&sn=7e8a9563fdb312b04849b57c4055ba61&scene=21#wechat_redirect)

[Quant必备MCP及使用教程](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489892&idx=1&sn=3f0008c7a8ee5244092475cfcd56521c&scene=21#wechat_redirect)

## AI-Kline + MCP

通过AI-Kline + MCP，用户可以随时向大模型提问，大模型会根据用户问题自动选择是否调用AI-Kline中的相关工具，目前AI-Kline提供个股行情数据，财务数据，新闻数据查询，当然还包括AI个股分析结果。

# MCP 服务器功能和特点简介

AI-Kline + MCP基于FastMCP实现，主要用于提供股票分析和数据获取的MCP服务。该函数采用异步处理方式，提高了并发处理能力，缩短了响应时间，提升了用户体验，并增强了系统的可扩展性。数据传输采用streamable-http，这是MCP最新更新的传输方式，相较于sse，传输更加稳定。

**提供的 MCP 工具**

-   `ashare_analysis`: 综合分析股票，提供完整的分析结果
    
-   `get_ashare_quote`: 获取股票行情数据，支持不同时间周期
    
-   `get_ashare_news`: 获取与特定股票相关的新闻
    
-   `get_ashare_financial`: 获取股票的财务数据
    

**配置方式**

-   运行代码 `uv run  mcp_server.py`
    
-   客户端中配置MCP SERVER： http://localhost:8000/mcp
    

**运行结果**

-   AI看线分析结果
    

![](assets/001.png)

![](assets/002.png)

-   股票行情数据查询
    

![](assets/003.png)

-   股票财务数据查询
    

![](assets/004.png)

-   股票新闻数据查询
    

![](assets/005.png)

  

代码见星球，加入QuantML星球，与星主和850+专业人士一起交流学习，618星球优惠活动不容错过：

![图片](assets/006.webp)