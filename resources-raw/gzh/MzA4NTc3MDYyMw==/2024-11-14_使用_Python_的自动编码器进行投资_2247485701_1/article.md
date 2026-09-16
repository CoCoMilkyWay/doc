# 使用 Python 的自动编码器进行投资

InfinityQuant 映翡量化 2024-11-14 21:58 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247485701&idx=1&sn=065d4ea53f137b419807af318bf3f636&chksm=9ecd132d7017b85f0d4e5a35858b3fecfabc5948e337149dbfa1925475ae33867d20e444dd73#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247485701&idx=1&sn=065d4ea53f137b419807af318bf3f636&chksm=9ecd132d7017b85f0d4e5a35858b3fecfabc5948e337149dbfa1925475ae33867d20e444dd73#rd)

使用以下代码可以做什么：  

1\. 识别并交易相似的股票形态：配对交易  
2\. 发现集群中表现不佳或表现优异的股票  
3\. 行业和风格轮动：集群动量

4\. 优化投资组合多样化：每个集群代表具有相似行为的股票  
5\. 检测制度变化：定期重新训练自动编码器，并跟踪股票随时间在集群之间的变化  
6\. 因子提取和信号生成

7.基于事件的交易：在重大事件（收益、经济公告）后重新聚集股票，以观察任何变化  
8\. 异常检测：使用自动编码器嵌入来发现异常值或异常

![](assets/001.jpg)

```
import yfinance as yf
```

  

https://github.com/quant-science/sunday-quant-scientist/blob/main/QS025-autoencoders/01\_autoencoders.py