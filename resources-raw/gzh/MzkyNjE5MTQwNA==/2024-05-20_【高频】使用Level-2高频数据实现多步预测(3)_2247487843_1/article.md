# 【高频】使用Level-2高频数据实现多步预测(3)

Yud. 量化前沿速递 2024-05-20 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487843&idx=1&sn=12d703320eedad85b945867b37cd20f3&chksm=c3f69647bed3f2563ee5758bba1ac43ba8130f8529461a4f841e5b97a52d1056d61e8186df76#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487843&idx=1&sn=12d703320eedad85b945867b37cd20f3&chksm=c3f69647bed3f2563ee5758bba1ac43ba8130f8529461a4f841e5b97a52d1056d61e8186df76#rd)

## 上一篇使用GBDT预测未来一步涨跌情况，本文试图实现多步预测以满足更贴切实际的需求。  

要实现多步预测需要用到时序模型。经查找文献有一篇经典文章《Deep Order Flow Imbalance: Extracting Alpha At Multiple Horizons From The Limit Order Book》符合需求，里面也涉及order imbalance的概念。该文的结论是CNN-LSTM的预测结果相对较优。

下文将基于该文结论对模型结构微调。

（另外关于多步预测kaggle上也有不少效果很好的方案（例如用自动编码器提取特征后预测），但大多不是针对orderbook上提取的特征。）

![](assets/001.png)

_论文中的模型a;（其中100是lookback window；）_

简化结构如下

![](assets/002.png)

_模型结构_

block1-3和5是正常的CNN/LSTM，比较显眼的是其中的inception模块。可以改进的部分可以是增加（时序）特征、增减核数、改动Inception模块…但大概还是增加多维订单簿特征对预测效果的改进会更显著。

“The most straightforward way of improving the performance of deep neural networks is by increasing their size. This includes both increasing the depth – the number of levels – of the network and its width: the number of units at each level.”

模型中的inception的原型出自GoogLeNet：

![](assets/003.png)

_From 《Going deeper with convolutions》_

Inception在CV领域能捕捉到不同尺寸的图像模式，并且GoogLeNet使用Inception相比之前的AlexNet可以更加有效地使用参数。

  

在模型a中的Inception里，其中的1x1一方面可作为Bottleneck瓶颈层降低维度，在时序卷积3x1和5x1之前使用1x1的conv可以有效缓解计算代价；其次，（1x1,3x1）和（1x1,5x1）是两个单独的卷积结构，是能够扫描图像中的两层神经网络，非单纯线性逻辑，所以能捕捉更加复杂的模式。

在了解了inception的起源和作用后，鉴于论文中的3和5是时序卷积，因此考虑在Inception里增加类似（1x1，Tx1）的子结构以捕捉时序上的更多特征信息。

使用keras来实现，基于下述代码修改。    

![](assets/004.png)

对变量进行winsorize、zscore数据预处理，Epochs=100；分别使用R2和mse作为metric和loss；

R2定义为：

![](assets/005.png)

_From《Deep Order Flow Imbalance: Extracting Alpha At Multiple Horizons From The Limit Order Book》_

实验过程结果展示如下：

Test0 loss

Test0 R2

Test1 loss

Test1 R2

R1

0.002103

0.037809

0.001698

0.052382

R2

0.003808

0.039471

0.00306

0.051671

R3

0.005581

0.028974

0.004461

0.039459

R5 

0.009061

0.036409

0.007341

0.003145

R10

0.01933

\-0.00169

0.014486

\-0.01504

          Test1为改动了inception结构的测试之一。

经测试改动后的inception层对预测效果有些许改良。实验使用R1、R2、R3、R5、R10作为预测目标，结果发现模型对R1、R2、R3均有预测效果。而对R5以后的收益率预测效果欠佳；可能是1）原始输入特征有限；2）Block1/2中的(ii)中时序上卷积核长度仅为4.（temporal convolutions(4x1)）..