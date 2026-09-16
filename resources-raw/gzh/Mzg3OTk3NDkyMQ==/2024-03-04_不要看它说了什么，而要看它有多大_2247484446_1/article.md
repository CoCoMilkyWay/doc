# 不要看它说了什么，而要看它有多大

混饭吃不丢人 QuantSeek 2024-03-04 10:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484446&idx=1&sn=6b6beb52cdf3b0584380883ecc326ef4&chksm=ce82faf40e10763e498fd31e8ac4ad7d3e971770eb41081a7b6c9f10e44f96cf18e7de924cdf#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484446&idx=1&sn=6b6beb52cdf3b0584380883ecc326ef4&chksm=ce82faf40e10763e498fd31e8ac4ad7d3e971770eb41081a7b6c9f10e44f96cf18e7de924cdf#rd)

大模型层出不穷，现如今有头有脸的机构都有属于自己的大模型，但不管如何吹嘘自己的能力，评价这些LLM最重要的2个标准就是：（1）参数量；（2）数据量。

以下是著名的chinchilla scaling law，它描述了大模型能力与参数量、数据量之间的关系。  

![](assets/001.png)

所以你会发现，现在几乎天天都有新模型，一些人还浪费时间去测，其实根本不用测，因为很多模型参数量和数据量根本上不去，瓶颈摆在那里。

  

为了更直观地体现这个law，锤哥测试了Meta发布的llama2两个参数量级的模型，2个模型均放到本地运行。一个是7B的参数，一个是70B的参数。同一个问题，问2个落地模型，让他们写一个双均线策略。  

  

7B的模型，完全没法使用。  

```
Here's an explanation of how the code works:
```

  

这是70B的，稍微好点，但是和gpt比差的有点远。

```
 Double Moving Average Strategy
```