# 使用VADER和Google Gemini 进行投资情绪分析

InfinityQuant 映翡量化 2025-05-24 20:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486760&idx=1&sn=cfe3fc843579969d8b8eb0e4471f3d84&chksm=9e037c069a950fbb44602d372ff5c54aacbf084b5b55acc5f7a642ce9749d556b6fd9c70a589#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486760&idx=1&sn=cfe3fc843579969d8b8eb0e4471f3d84&chksm=9e037c069a950fbb44602d372ff5c54aacbf084b5b55acc5f7a642ce9749d556b6fd9c70a589#rd)

📊 使用VADER和Google Gemini 🧠进行投资情绪分析  

  

🔍 在这个项目中，使用 VADER 情绪分析结合 Gemini Google API 分析了财经新闻头条，可以深入了解公众对金融市场和特定股票的看法。  
  

📌 做了什么：  
通过 Google Gemini 获取实时财经新闻头条。  
应用 VADER 将每个标题分类为：  
✅ 阳性  
⚪ 中性  
❌ 阴性  
汇总和可视化一系列金融主题的情绪分布。  
  

📈 获得的结果：  
积极的头条新闻表明看涨的市场信心。  
中性标题表示平衡或不确定的前景。  
负面头条新闻可能透露看跌压力或风险感知。  
  

📊 示例结果：  
SentimentCount✅ 积极12⚪ 中性18❌ 消极6  
  
💡 这种类型的情绪分析可以帮助投资者发现可能在价格变动之前发生的情绪变化，从而支持更明智的交易和投资决策。

![](assets/001.jpg)

![](assets/002.jpg)

![](assets/003.jpg)

![](assets/004.jpg)

比较了两款强大的情感分析工具，结果可能会让你大吃一惊！

  

🔥 VADER 与 RoBERTa：终极情感分析对决结果出炉！📊

  

🤖 这些工具是什么？  
VADER（Valence Aware Dictionary and sEntiment Reasoner，情感字典与情感推理器）：  
•  极速的基于规则的情感分析工具  
•  非常适合用于社交媒体文本、非正式语言和实时处理  
•  无需训练，可立即部署  
•  在处理表情符号、俚语和标点符号的细微差别方面表现出色  
  

RoBERTa（Robustly Optimized BERT Pretraining Approach，优化的BERT预训练方法）：  
•  基于Transformer的最先进的深度学习模型  
•  在大规模文本数据集上预训练，以获得卓越的上下文理解能力  
•  能够捕捉复杂的语言模式和微妙的情感差异  
•  是情感分类准确性的黄金标准  
  

📈 关键发现：  
 ✅ RoBERTa在准确性方面占据主导地位，尤其是在复杂、依赖上下文的情感分析方面  
 ✅ VADER在速度和简洁性方面表现出色，非常适合高容量、实时应用  
 ✅ 两者在不同情感强度上都显示出强烈的相关性  
 ✅ 根据文本类型和领域，性能差异显著  
  

💼 这对你的业务很重要：  
 🚀 对于初创公司和中小企业：VADER提供了一种成本效益高的即时部署方案，可用于社交媒体监控和客户反馈分析  
 🏢 对于大型企业：RoBERTa提供了进行关键业务决策、品牌声誉管理和复杂市场研究所需的准确性  
 📱 对于科技公司：了解这些权衡对于选择适合特定用例的工具至关重要  
  

🎯 最终结论：  
没有一种放之四海而皆准的解决方案。你的选择取决于：  
•  需要处理的数据量  
•  所需的准确度水平  
•  实时处理需求  
•  可用的计算资源  
•  预算限制  

  

VADER库：

https://github.com/cjhutto/vaderSentiment

  

RoBERTa资料：

https://huggingface.co/docs/transformers/en/model\_doc/roberta