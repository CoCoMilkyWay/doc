# 使用混合Transformer图神经网络预测股票相关性

InfinityQuant 映翡量化 2026-01-12 09:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490535&idx=1&sn=c7b1b5dca3d817933b41ad8e6f642aae&chksm=9e89535c7db5b1a775b227ec83410640133f680eabd1b10666ca68b932dab84916ae81a8f0f9#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490535&idx=1&sn=c7b1b5dca3d817933b41ad8e6f642aae&chksm=9e89535c7db5b1a775b227ec83410640133f680eabd1b10666ca68b932dab84916ae81a8f0f9#rd)

相关性几天就变，滚动窗口几周才适应，这种滞后真的代价惨重  
这篇论文《Forecasting Equity Correlations with Hybrid Transformer Graph Neural Network》（2026年1月8日）提出了一种Transformer + 图神经网络的混合模型，能提前预测10天后的股票–股票相关性，并直接把预测结果用于统计套利的聚类。  
核心做法：  
•  在Fisher-z残差空间里预测相关性（更稳定、更现实），  
•  通过图注意力学习具备状态感知的市场结构，  
•  保留相关性网络的整体形状（而不只是点预测准确率）。  
回报：  
•  夏普比率1.84 vs 标普500的0.65，  
•  最大回撤-9% vs -34%，  
•  危机时期收益最大，而传统向后看的聚类方法在那时候往往失效。  
一句话总结：  
别再交易昨天的相关性网络了，交易明天的！

![](assets/001.jpg)

![](assets/002.jpg)

https://arxiv.org/abs/2601.04602  

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![图片](assets/003.png)