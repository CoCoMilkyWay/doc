# 量化交易k线预测开源模型：Kronos

InfinityQuant 映翡量化 2025-08-19 18:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487178&idx=1&sn=67bd19a2e172c6e6e34f5ec5fe478a03&chksm=9e44454249fcf5a7a06184081c82c27b2e56dbe20d41879ff890be66cf02dba65b5f68497d5f#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487178&idx=1&sn=67bd19a2e172c6e6e34f5ec5fe478a03&chksm=9e44454249fcf5a7a06184081c82c27b2e56dbe20d41879ff890be66cf02dba65b5f68497d5f#rd)

做量化交易，K 线预测一直是个难题，传统的时序模型不光训练麻烦，还特别容易被噪声数据干扰，导致准确率低。  
  
近日，全球首个专为金融 K 线设计的模型：Kronos，开源了，实现精准的金融预测。  

  

![](assets/001.jpg)

  
基于全球 45 个交易所的海量数据训练，采用自研的离散编码方式，把 OHLCV 数据转成 token，再用大规模 Transformer 模型学会各种走势模式，效果相当惊艳。  

  

![](assets/002.jpg)

主要功能：  
\- 提供多种参数模型，从 4.1M 到 499.2M 参数可选  
\- 专门的金融数据分词器，处理高维 K 线数据  
\- 一键预测接口，轻松生成未来价格走势  
\- 完整的微调pipeline，可适配自己的交易策略    
\- 提供在线 Demo，实时展示 BTC/USDT 预测结果  
\- 支持 A 股市场数据，集成 Qlib 进行回测验证  
  

https://github.com/shiyu-coder/Kronos