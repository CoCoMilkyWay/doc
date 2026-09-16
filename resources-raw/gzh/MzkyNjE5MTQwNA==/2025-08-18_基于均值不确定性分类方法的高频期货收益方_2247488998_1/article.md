# 基于均值不确定性分类方法的高频期货收益方向预测

shameless 量化前沿速递 2025-08-18 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488998&idx=1&sn=552c9becb7ffa26dbfbe45aa083791e8&chksm=c3af435e8f61fb2805e8cc804d0c99ade2a6d971fe252c8d0715c9665383b213bc8aeeac0b50#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488998&idx=1&sn=552c9becb7ffa26dbfbe45aa083791e8&chksm=c3af435e8f61fb2805e8cc804d0c99ade2a6d971fe252c8d0715c9665383b213bc8aeeac0b50#rd)

Prediction of high frequency futures return directions based on the mean uncertainty classification methods

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文章概述

### 

背景与目的

    本文主要研究了中国期货市场高频交易数据中短期平均收益率方向的预测问题。由于微小波动通常被视为随机噪声，只有显著的价格变动才被认为是统计上重要的信号，因此数据不平衡成为预测建模中的关键问题。作者采用均值不确定性分类方法（mean-uncertainty LR 和 mean-uncertainty SVM），在次线性期望框架下进行预测，并提出了相应的投资策略。

### 

方法

    文中提出并扩展了两种基于次线性期望（SLE）框架的方法：均值不确定性逻辑回归（mean-uncertainty LR）和支持向量机（mean-uncertainty SVM）。这些方法旨在解决数据不平衡问题，并通过实证分析验证其有效性。具体来说，作者选择了中国期货市场中最活跃合约的前15个流动性产品，利用交易数据和限价订单簿数据进行实证研究。

### 

实证结果

    实验结果表明，相较于传统的逻辑回归（LR）和SVM相关方法，这两种均值不确定性方法在分类指标和每笔交易的平均收益方面具有显著优势。具体而言：

-       在“向上/非向上”预测任务中，均值不确定性LR和SVM方法在大多数期货产品上的每笔交易平均收益优于其他传统方法。
    
-       对于“向下/非向下”预测任务，均值不确定性LR方法在80%的LR相关期货产品上表现出更高的收益，而均值不确定性SVM方法在67%的SVM相关产品上表现更优。
    

### 

结论

    总体而言，均值不确定性方法在处理高频期货数据的方向预测中展示了更强的优势和更准确的预测能力，有助于提高投资决策的效果。这些方法不仅提高了分类准确性，还在实际应用中带来了更高的投资回报。