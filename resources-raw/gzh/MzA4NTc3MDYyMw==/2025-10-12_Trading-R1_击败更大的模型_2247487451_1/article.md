# Trading-R1 击败更大的模型

InfinityQuant 映翡量化 2025-10-12 00:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487451&idx=1&sn=618c0201d7af2d3b0f852f071339cbe8&chksm=9edebfaeb6ee173314c88e83328a8e890500567e107bb5283bd9188709e802df9ae27e80640f#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487451&idx=1&sn=618c0201d7af2d3b0f852f071339cbe8&chksm=9edebfaeb6ee173314c88e83328a8e890500567e107bb5283bd9188709e802df9ae27e80640f#rd)

Trading-R1 击败更大的模型 📈🤖

  
一项来自 #斯坦福 和 #UCLA 的新研究显示，一个名为 #Trading-R1 的小型 4B AI 模型能够击败更大的交易 AI。它通过强化学习学会了如何对市场进行 #推理。在 NVDA、AAPL、MSFT 和 SPY 上的测试中，它实现了更高的夏普比率和高达 70% 的命中率。它像分析师一样推理，做出可解释的交易决策，尽管结果仅限于短期回测和大股票。

![](assets/001.jpg)

  

📊 超额表现

 回测报告显示，在 2024 年 6 月至 8 月期间，与更大的 LLM 和 RL 基线相比，NVDA、AAPL、MSFT、AMZN、META、SPY 的夏普比率更高，命中率达到 70%，回撤更小。

  
🧪 方法

 三阶段训练对齐结构、声明和决策，采用波动性感知的五点行动。使用 Tauric-TR1-DB，在 18 个月内对 14 个股票代码进行 100k 样本训练，通过蒸馏和 GRPO RL 将论点转化为交易。

  
🧭 工作流程

 用引用的论点、情景检查和规模建议来分配任务。将输出与内部限制和成本配对。预期每周进行中短期调用。始终保持人工审查，控制进入、退出和分配。

  
🚫 限制 

 回测窗口短。训练集偏向蓝筹股和牛市。模型可能产生幻觉和漂移。将信号视为研究，而非执行。扩展资产，增加离线 RL，监控稳定性。

  

TRADING-R1 Terminal 将在

https://github.com/TauricResearch/Trading-R1 开源发布。

  

https://arxiv.org/pdf/2509.11420

  

PDF放在了“学术界的Alpha”知识星球里，欢迎加入👏

![](assets/002.jpg)