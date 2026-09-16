# 以数据为中心的多Agent自动化端到端量化开源工具RD-Agent(Q)

InfinityQuant 映翡量化 2025-06-05 21:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486861&idx=1&sn=d0629c9bfd650c0db16f217f1d8bfe35&chksm=9ee84891f84058a30a3033a8382f6c3945123a39dcf7ddc2486b13bbb5e212fde9b94ffeb20e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486861&idx=1&sn=d0629c9bfd650c0db16f217f1d8bfe35&chksm=9ee84891f84058a30a3033a8382f6c3945123a39dcf7ddc2486b13bbb5e212fde9b94ffeb20e#rd)

RD-Agent（Q），这是第一个以数据为中心的多代理框架，通过协调因子模型共同优化实现定量战略的全栈研究和自动化端到端的量化开源工具。

  

用AI驱动AI

![](assets/001.jpg)

  

通过将量化研发流程分解为研究和开发阶段（规范、综合、实施、验证、分析），RD - Agent(Q) 在 #CSI300 上取得了显著的收益。  

  

![](assets/002.jpg)

  

RD-Agent（Q）将量化过程分解为两个迭代阶段

一个研究阶段，该阶段动态设置目标对齐的提示，根据域先验制定假设，并将其映射到具体任务，一个开发阶段，该阶段使用代码生成代理Co-STEER来实现特定于任务的代码，然后在真实市场回测中执行。这两个阶段通过一个反馈阶段相互连接，该反馈阶段会对实验结果进行彻底评估，并为后续迭代提供依据，同时采用多臂bandit调度器进行自适应的方向选择。

  

![](assets/003.jpg)

  

具体内容：

✅研发流程：研究人员阅读论文和报告，以提取可实施的方法（通常以数学公式或模型架构的形式制定），以寻求潜在的研究方向。然后，他们准确地实施这些方法，以获得进一步分析和开发的结果。

![](assets/004.jpg)

![](assets/005.jpg)

✅自动研发Agent ：Co - STEER 是一种基于思维链的代码生成智能体，可驱动自动化因子和模型的实施，与经典库相比，能实现高达 2 倍的年化收益率，且因子数量减少 70 % 。

![](assets/006.jpg)

  

✅流程分解 ：将工作流程分为规范、综合（想法生成）和实施单元，利用知识森林不断细化假设。

![](assets/007.jpg)

  

✅严格验证 ：在 CSI 300 上进行的真实市场回测证实了其具有更优的信息系数（IC）、信息比率（IR）和年化收益率（ARR），同时也突出了适应波动性市场环境的挑战。

  
✅联合优化影响 ：联合优化因子和模型使 IC 达到 0.0532，ARR 达到 14.21%（GPT - 4o mini），超越了 Alpha158 和 TRA 等顶级基线。

  
✅可扩展且成本效益高 ：所有实验的运行成本均低于 10 美元，证明了智能多智能体研发既能提供强大功能，又十分经济实惠。

  
🔥microsoft/Qlib（24K 星）  
🌟microsoft/RD - Agent（5.5K 星）

  

原文： 

https://arxiv.org/abs/2505.15155

Github 库 ：

https://github.com/microsoft/rd-agent

  

Qlib库：

https://github.com/microsoft/qlib