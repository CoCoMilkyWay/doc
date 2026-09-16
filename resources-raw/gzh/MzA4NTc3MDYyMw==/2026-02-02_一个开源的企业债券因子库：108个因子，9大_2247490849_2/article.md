# 一个开源的企业债券因子库：108个因子，9大主题集群

InfinityQuant 映翡量化 2026-02-02 09:18 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490849&idx=2&sn=487b9562e77215869cbce4749657c674&chksm=9e0a01db5ef1e9fda33c50d0574b0fe0c2411dafe501bb8ece50aa179802cbfc78561a09f645#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490849&idx=2&sn=487b9562e77215869cbce4749657c674&chksm=9e0a01db5ef1e9fda33c50d0574b0fe0c2411dafe501bb8ece50aa179802cbfc78561a09f645#rd)

一个开源的企业债券因子动物园现已正式上线：

🔗 https://openbondassetpricing.com/corporate-bond-factor-zoo   

包含 ：108个企业债券因子；时间跨度1973–2025年；分为 9大主题集群。  
  
相关论文和GitHub：    
https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6088966  
作者：Alexander Dickerson、Cesare Robotti、Giulio Rossetti 等（完整论文草稿即将发布）  

https://github.com/Alexander-M-Dickerson/trace-data-pipeline/tree/main

  

主要特点：  
✅ 开箱即用 — 因子以宽格式 .csv 文件提供；详细的投资组合层面数据（包括多空腿、换手率等）以 .parquet 格式提供    
✅ 经过偏差校正的信号 — 所有信用利差、收益率、债券价值、短期反转以及基于价格的因子，都采用了我们专门的噪声调整程序，避免虚假回测人为放大超额收益（premia）    
✅ 基于干净数据构建 — 因子来自我们经过错误校正的 TRACE 数据处理流程，包括 144A 债券和违约后交易数据    
✅ 无前视偏差 — 因子构建仅使用事前（ex-ante）过滤条件，投资组合形成过程中不嵌入任何未来信息    
✅ 详细数据字典 — 包含完整的变量定义、因子构建方法论以及集群描述：    
🔗 https://openbondassetpricing.com/corporate-bond-factor-zoo （或相关数据说明页面）  
  
这是一个专为企业债券资产定价研究设计的高质量开源因子数据集，特别注重数据清洗、偏差校正和可重复性，非常适合学术研究、因子投资策略开发和基准测试使用。  
  
更多内容可以关注这个网站：

  

https://openbondassetpricing.com/    
这里持续更新各种企业债券相关因子数据、代码和研究成果，是目前公司债因子研究领域非常重要的开源资源之一。

![](assets/001.png)

  

更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)