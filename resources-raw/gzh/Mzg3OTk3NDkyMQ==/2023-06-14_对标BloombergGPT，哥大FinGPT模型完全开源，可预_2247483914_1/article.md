# 对标BloombergGPT，哥大FinGPT模型完全开源，可预测股价

混饭吃不丢人 QuantSeek 2023-06-14 08:02 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247483914&idx=1&sn=d18c364f155a85a675ebfef2cdf481a6&chksm=cef1b5625b3225c8275861c7d3f60cd28f8ae4f85070f857d102e3c614ae07a6755e011e4970#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483914&idx=1&sn=d18c364f155a85a675ebfef2cdf481a6&chksm=cef1b5625b3225c8275861c7d3f60cd28f8ae4f85070f857d102e3c614ae07a6755e011e4970#rd)

**开局就是极其讽刺的一句话：**  

——不要指望资本家们开源LLM（大语言模型）的API  

  

![](assets/001.png)

  

这是哥伦比亚大学开源LLM——FinGPT项目的第一句话，也表明了FinGPT的核心特点：开源。  

![](assets/002.png)

**一、背景**  

继Bloomberg提出了500亿参数的BloombergGPT，GPT在金融领域的应用受到了广泛关注，但BloombergGPT是一个非开源的模型，而且用到了Bloomberg自身独有的数据储备，并不利于金融大模型的广泛普及。

  

哥大团队最近在他们的论文《FinGPT: Open-Source Financial Large Language Models》里提出了开源的金融大预言模型：FinGPT，叫板BloombergGPT。

  

![](assets/003.png)

  

**二、FinGPT的特点**

  

1、完全开源：开源的训练数据、开源的模型。

  

2、数据中心化：尽管没有Bloomberg用到的独有数据，但FinGPT所用的所有数据都被集中、严格地清洗，保证了数据的质量，并向大众开放。

  

3、端到端的设计：包括输入层、数据加工层、大语言模型微调层和应用层。

  

4、BloombergGPT中**缺少**人类反馈强化学习，但这是GPT模型成功的关键，而FinGPT**应用**了这项技术。

  

5、**轻量级**的部署和微调，为了普及金融大模型，降低应用成本，应用了the Low-Rank Adaptation (LoRA) of LLMs技术，将可训练参数**从61.7亿减少为367万**。

  

![](assets/004.png)

  

**三、FinGPT的训练数据**

  

FinGPT运用了各种各样的金融训练数据，包括金融新闻、公司公告、社交媒体、金融专业网站、学术资料等，多种多样的数据保证了FinGPT可以理解金融市场和做出金融决策。

  

值得注意的是，FInGPT提供了一套完善的机制应对**实时数据**，做出实时决策；使用者也可以很轻松地对下游任务进行微调、

  

**四、微调以预测股价**

  

我们还可以微调FinGPT来预测股价，由于股价预测任务微调时可以简单利用股价变动作为反馈，因此微调成本相对其它需要人类反馈的任务低得多。

  

**五、可能的下游应用**

  

1、金融建议。

2、量化交易、组合优化。

3、金融情感分析。

4、风险管理。

5、金融欺诈发现。

6、信用评级。

7、破产预测。

8、ESG。

9、低代码开发。

10、金融教育等。

  

**六、应用例子**  

```
# 数据下载
```

  

下面的链接展示了用ChatGPT进行进行交易的结果：

```
https://github.com/AI4Finance-Foundation/FinGPT/tree/master/fingpt/chat
```

![](assets/005.png)

![](assets/006.png)

  

  

锤哥的感受：尽管从复杂度而言，FinGPT可能还有所欠缺，但考虑到金融场景特殊的隐私性要求，FinGPT还是值得微调部署应用的。

  

  

**Github链接：**

https://github.com/AI4Finance-Foundation/FinGPT

https://github.com/AI4Finance-Foundation/FinNLP

论文获取，可在公众号后台回复：FinGPT

  

  

  

关注我，了解最新的、深刻的金融、工业AI前沿