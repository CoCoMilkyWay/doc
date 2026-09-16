# 金融深度强化学习中的梯度缩减卷积神经网络策略

QuantML 2024-08-23 17:27 中国香港

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485925&idx=1&sn=716bded9ae30ab81722ff1e1acba1496&chksm=cf7bfb63a0c264a4013e6f1d2e1fb441a3399eb3fecc6c6bdaf8a55d5968266ebff20c917992#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485925&idx=1&sn=716bded9ae30ab81722ff1e1acba1496&chksm=cf7bfb63a0c264a4013e6f1d2e1fb441a3399eb3fecc6c6bdaf8a55d5968266ebff20c917992#rd)

论文提出了两种改进措施：在输入阶段集成归一化层以确保特征缩放一致性，以及采用梯度缩减架构，其中前层更宽，后层逐渐变窄，以提高模型对金融数据复杂模式的捕捉能力。  
  
通过使用Proximal Policy Optimization (PPO)算法，将改进的CNN架构应用于DRL环境中，以优化交易策略。实验结果表明，改进的CNN模型在模拟交易环境中实现了更高的累积回报和更大的稳定性，与基线模型相比表现出色。  
  
论文的结论强调了这些改进措施使得CNN模型在金融数据的处理和预测建模方面具有更强的性能和鲁棒性。

![图1](assets/001.jpg)

图1

![图2](assets/002.png)

图2

![图3](assets/003.png)

图3