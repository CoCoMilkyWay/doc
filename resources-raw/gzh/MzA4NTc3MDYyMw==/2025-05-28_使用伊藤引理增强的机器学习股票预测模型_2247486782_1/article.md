# 使用伊藤引理增强的机器学习股票预测模型

InfinityQuant 映翡量化 2025-05-28 23:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486782&idx=1&sn=61d42291a26f6d6cdcb4740300851d6a&chksm=9e0e4fba6cf88c0e410864d32c7316a4c9cd00a3394102aac54f5f595ad5b9127617f51d8dfd#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486782&idx=1&sn=61d42291a26f6d6cdcb4740300851d6a&chksm=9e0e4fba6cf88c0e410864d32c7316a4c9cd00a3394102aac54f5f595ad5b9127617f51d8dfd#rd)

该项目将传统的金融数学与尖端机器学习相结合。  

  

🔬 这个项目有什么特别之处？  
✅ 将伊藤引理（随机微积分）与LSTM神经网络相结合  
✅ 采用多头注意力机制，用于复杂时间模式识别  
✅ 使用机器学习动态预测波动率和漂移参数  
✅ 包含20多个技术指标，如RSI、MACD、布林带  
✅ 使用蒙特卡洛模拟并提供置信区间  
✅ 实现实时6个月预测，并量化不确定性  
  

📊 关键结果：  
•  机器学习模型的盈利概率为68.3%，而传统方法为61.2%  
•  预测不确定性降低了2.15%  
•  动态参数估计能够根据市场条件进行调整  

![](assets/001.jpg)

  

🛠 技术栈：  
•  使用PyTorch构建深度学习架构  
•  使用LSTM + 注意力机制进行序列建模  
•  将几何布朗运动与机器学习预测相结合  
•  使用yfinance获取实时市场数据  
这种混合方法展示了数理金融和人工智能如何协同工作，创建更强大的预测模型。该模型不仅预测价格，还能实时学习市场动态并调整波动率/漂移参数。

  
🔗 GitHub：  
https://github.com/YavuzAkbay/GeometricBrownianMotion