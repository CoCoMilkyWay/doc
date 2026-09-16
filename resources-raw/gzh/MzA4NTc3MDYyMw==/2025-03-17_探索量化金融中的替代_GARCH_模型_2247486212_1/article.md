# 探索量化金融中的替代 GARCH 模型

InfinityQuant 映翡量化 2025-03-17 20:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486212&idx=1&sn=1049acf1512b97a1efffce2243bdb970&chksm=9ebed42189201a3195e2f6afc53a289c4d72c8fc74a8787fb15966c397103219ed7d98db44aa#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486212&idx=1&sn=1049acf1512b97a1efffce2243bdb970&chksm=9ebed42189201a3195e2f6afc53a289c4d72c8fc74a8787fb15966c397103219ed7d98db44aa#rd)

在金融市场中，波动率建模在风险管理、衍生品定价和交易策略中起着至关重要的作用。📚📚  

  

![](assets/001.jpg)

  

虽然 GARCH （广义自回归条件异方差） 模型被广泛使用，但存在几种变体来更好地捕捉市场行为。 🎳🎳  
  
以下是一些关键的 GARCH 扩展及其应用程序：  
  
🔹 GARCH – 标准模型，捕捉过去的冲击 （ε²） 和波动性持久性 （σ²）。  
  
🔹 EGARCH （Exponential GARCH） – 不对称性的原因;较大的负面冲击比正面冲击更能增加波动性。  
  
🔹 GJR-GARCH – 引入指标功能，捕捉坏消息（负面冲击）对波动性的影响大于好消息的杠杆效应。  
  
🔹 IGARCH （Integrated GARCH） – 一种非平稳模型，其中冲击对波动性有长期影响。  
  
🔹 NGARCH （非线性 GARCH） – 通过考虑过去的冲击和波动性之间的相互作用来模拟非线性。  
  
🔹 TGARCH （Threshold GARCH） – 使用阈值来调整波动性，具体取决于过去的回报是正回报还是负回报。  
  
🔹 APARCH （Asymmetric Power ARCH） – 引入幂变换，以便灵活地对波动性动态进行建模。  
  
💡 为什么这很重要？  
  
选择正确的波动率模型可以显著改善风险预测、优化投资组合管理并完善衍生品定价策略。