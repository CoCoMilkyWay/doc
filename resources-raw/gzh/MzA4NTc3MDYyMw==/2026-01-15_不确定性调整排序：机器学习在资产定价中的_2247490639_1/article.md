# 不确定性调整排序：机器学习在资产定价中的新方法

InfinityQuant 映翡量化 2026-01-15 08:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490639&idx=1&sn=d39beda3d1f916ff0d5645f56b9bf428&chksm=9e42c124042bb908c48b8c71b714c84820f62087b8e7a8c4f8a0a165670b929399ce0330ea72#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490639&idx=1&sn=d39beda3d1f916ff0d5645f56b9bf428&chksm=9e42c124042bb908c48b8c71b714c84820f62087b8e7a8c4f8a0a165670b929399ce0330ea72#rd)

这篇新论文《Uncertainty-Adjusted Sorting for Asset Pricing with Machine Learning》（2026年1月2日）证明：在机器学习资产定价中，如果你不用原始预测值，而是用不确定性调整后的预测区间来对股票排序，组合表现会大幅提升。  
传统ML排序把所有预测都当成同样可靠，  
但实际上，不同股票、不同模型的估计误差差异极大，  
那些极端预测往往恰恰是最不可信的。  
解决方案非常优雅：  
做多那些上界（upper bound）最高的股票，  
做空那些下界（lower bound）最低的股票。  
这些区间界限是用个股特有的样本外残差构建的（distribution-free，无需假设分布）。  
结果：  
几乎所有ML模型的夏普比率都大幅跳升，  
波动率显著下降——收益却基本不变，  
增益最大的恰恰是那些最灵活的模型（神经网络、提升树等）。  
零新增预测变量。零重新训练。只是更聪明地利用不确定性而已。  
一句话总结：  
别再迷信点预测的排名了，把不确定性考虑进去，你的ML因子策略瞬间起飞。

![](assets/001.jpg)

https://arxiv.org/abs/2601.00593  

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![图片](assets/002.png)