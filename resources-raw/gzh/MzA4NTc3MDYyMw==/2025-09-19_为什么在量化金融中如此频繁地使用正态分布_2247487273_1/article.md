# 为什么在量化金融中如此频繁地使用正态分布？

InfinityQuant 映翡量化 2025-09-19 23:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487273&idx=1&sn=fedd2c6247af329905ae5780e7b8287a&chksm=9ea72751aed04ae531c33e92cba0f14e1ffba22198013b82b094f0afa53073244f3568a5ba1d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487273&idx=1&sn=fedd2c6247af329905ae5780e7b8287a&chksm=9ea72751aed04ae531c33e92cba0f14e1ffba22198013b82b094f0afa53073244f3568a5ba1d#rd)

👉 简洁与直观  
钟形曲线提供了一种“干净”的方式来刻画随机性——对称、易懂、数学上优雅。  
  

👉 中心极限定理（CLT）  
当大量独立的随机冲击不断累积（例如收益随时间叠加），它们的分布会趋向正态。这使得正态分布成为天然的起点。  
  

👉 解析模型  
Black-Scholes 等核心模型都假设收益率正态，从而能得到封闭解、计算更快。  
  

👉 风险管理  
VaR、Expected Shortfall 等风险指标通常先假设正态，再去估算尾部风险，即便真实世界更复杂。  
  

👉 基准作用  
即使市场存在“肥尾”和偏度，正态分布仍是一个基准线，可与 Student-t、Heston、GARCH 等更复杂的模型进行对比。  
  

一句话：正态并不完美，却是强大的“第一近似”。  
量化金融往往先拿钟形曲线开刀，再逐步逼近市场现实。

![](assets/001.jpg)