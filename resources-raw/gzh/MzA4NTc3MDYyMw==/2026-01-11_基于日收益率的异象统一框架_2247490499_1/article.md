# 基于日收益率的异象统一框架

InfinityQuant 映翡量化 2026-01-11 13:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490499&idx=1&sn=80634de40ddf256859a1c2084d11efc3&chksm=9e609d90eab27572b258153d125d8c444a8cdc37701c28ba7b6a00f1621c3e5623b1a6bb40eb#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490499&idx=1&sn=80634de40ddf256859a1c2084d11efc3&chksm=9e609d90eab27572b258153d125d8c444a8cdc37701c28ba7b6a00f1621c3e5623b1a6bb40eb#rd)

这篇新论文《A Unified Framework for Anomalies Based on Daily Returns》（2026年1月2日）从过去一个月的日度股价波动中提取出一个单一信号——日收益信息（Daily Return Information）。作者不再“拍脑袋”定公式，而是让数据自己决定哪些信息重要。最终得到一个能解释众多经典异象、且至今仍然有效的因子。

  
📉 时点比幅度更关键：收益发生在月内的哪一天，比收益的极端程度更重要。  
🤖 模型：采用弹性网络回归（Elastic Net），输入过去21个交易日的日收益，融合LASSO与Ridge，自动挑出最重要的交易日，干净地处理相关性；每年重新样本外估计，让数据而非固定公式决定映射关系。  
🧠 统一性：一个数据驱动的信号即可解释反转效应、MAX效应、波动率效应及“彩票型”效应。  
📊 强度：在常规因子控制后，该因子仍能带来约1.6%的月度收益。  
🧪 稳健性：通过数千种替代研究设计与“因子动物园”全检验，依旧屹立不倒。

![](assets/001.jpg)

作者与机构：  

Nusret Cakici (Fordham University)  
Christian Fieberg (HSB Hochschule Bremen)  
Gabor Neszveda (John von Neumann University)  
Robert Bianchi (Griffith University)  
Adam Zaremba (MBS School of Business, Poznan University of Economics, Monash University)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6005614

PDF已更新，更多策略、资讯⬇️

[欢迎加入：学术界的Alpha](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490493&idx=1&sn=227ec5666254462a59710726c2bbf81c&scene=21#wechat_redirect)

![图片](assets/002.webp)