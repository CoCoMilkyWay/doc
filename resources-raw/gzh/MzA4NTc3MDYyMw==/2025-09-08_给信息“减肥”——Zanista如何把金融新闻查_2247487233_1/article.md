# 给信息“减肥”——Zanista如何把金融新闻查询提速60倍

InfinityQuant 映翡量化 2025-09-08 19:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487233&idx=1&sn=2721176ed5e9cf5f782341681e9ecc1f&chksm=9ee73d8e21c685571c989aec9bd33bb449dbb56ef42ed6c4cbc2efded6168cfaa88d1a1b9531#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487233&idx=1&sn=2721176ed5e9cf5f782341681e9ecc1f&chksm=9ee73d8e21c685571c989aec9bd33bb449dbb56ef42ed6c4cbc2efded6168cfaa88d1a1b9531#rd)

每天醒来，投资者都要面对一场信息马拉松：主流通讯社、LinkedIn热帖、Substack深度、小众研报、播客摘要……真正的信号被淹没在重复和噪音里。Zanista.AI给出的解法只有三步：全量抓取、预先降噪、极速搜索。  

1\. 全量抓取：50万+全球信源  
从纽交所公告到日股推特，从中东能源博客到拉美经济播客，系统7×24小时不间断爬取，日新增条目以百万计。  
2\. 预先降噪：PCA-RAG压缩30倍  
传统做法是把所有文本转成3,072维的AI向量（embedding），再建索引；查询时比对海量高维向量，算力开销大。Zanista用“主成分分析”把向量砍到约100维，索引体积缩小近30倍，查询耗时从秒级降至毫秒级，却保留95%+的语义精度。公司称，金融新闻查询速度最高可提60倍。  
3\. 极速搜索：实时+可解释  
压缩后的索引可全驻内存，单节点即可支撑千万级查询；同时系统保留原文映射，用户可一键回溯出处，满足合规审计需求。  
落地进展  
A.一家美国小型对冲基金已采购“罗素3000新闻增强包”，将Zanista流直接接入量化模型。  
B.多家大型资管正在POC（概念验证）阶段，测试把降噪新闻与ESG、期权异动、供应链等多维数据融合，做事件驱动策略。  
一句话总结  
当“信息过载”成为投资业绩的隐形税负，Zanista用AI先把噪音关掉，让投资者把时间花在决策，而不是翻新闻。

  

![](assets/001.jpg)

  

https://www.ai-street.co/p/ai-startup-filters-out-the-noise-in-financial-news  
https://arxiv.org/pdf/2504.08386