# AI 能学会因果推断吗？

InfinityQuant 映翡量化 2026-02-08 11:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490935&idx=1&sn=71c3a6f1daddf2e1969e58c9cc38e89c&chksm=9ed21539f41a9950860826df9b48e57abe4a1c1fe2d6532add5b4faaff5e0d2ebfc8fe13f8f6#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490935&idx=1&sn=71c3a6f1daddf2e1969e58c9cc38e89c&chksm=9ed21539f41a9950860826df9b48e57abe4a1c1fe2d6532add5b4faaff5e0d2ebfc8fe13f8f6#rd)

这篇论文《Can AI Learn Causal Structure? Evidence from ADIA Lab's Causal Discovery Challenge》（2026年1月26日）以 ADIA Lab 2024 因果发现挑战赛为背景，系统探讨了一个核心问题：在已知大量“数据–因果图”训练样本的前提下，AI 是否能够有效学习并识别因果结构。研究结论整体偏乐观，但也保持了对现实应用的审慎态度。  

研究目标：不再直接重建完整因果图，而是将问题转化为一个监督分类任务：判断除处理变量 X 和结果变量 Y 外，其余变量在因果图中的八种角色（如混杂因子、中介、碰撞器等）。

文章使用约 4.7 万个合成数据集，每个都由已知因果 DAG 生成；不存在未观测混杂，降低了因果发现难度；评价指标为多分类平衡准确率。

  

**🐮结果：监督学习 + 特征工程 + 集成方法**显示出明显优势。  

🤖 AI学习：在已知图上训练的模型达到约77%准确率，远超传统方法。  
📊 监督学习：监督学习比基于约束的因果工具强得多。  
🧠 集成方法：组合多个模型比任何单一方法更稳定。  
🧩 图结构：某些结构很容易学习。层级结构有效，而优先连接（无标度网络）则不行。  
  

局限性：所有数据都是合成的。真实世界的复杂性仍是未解之谜。

![](assets/001.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6125566

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)