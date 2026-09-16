# TrustTrade：修复 AI 交易方式

InfinityQuant 映翡量化 2026-04-14 08:59 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491454&idx=1&sn=0428cabbe45d9d80bf2f4cf83e1228b2&chksm=9efc1494f587f55d4b0215474edde4da4b417128e2ff828350a3f9ee76068df3a79ec45972a3#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491454&idx=1&sn=0428cabbe45d9d80bf2f4cf83e1228b2&chksm=9efc1494f587f55d4b0215474edde4da4b417128e2ff828350a3f9ee76068df3a79ec45972a3#rd)

LLM 的交易agents并不是笨，它们只是太容易相信一切了。哈佛大学 AI 与机器人实验室（Harvard AI and Robotics Lab）最新研究《TrustTrade: Human-Inspired Selective Consensus Reduces Decision Uncertainty in LLM Trading Agents》（2026年3月23日）指出了为什么 AI 驱动的交易总是容易爆仓。核心问题在于统一信任（Uniform Trust）：模型把垃圾信号和金牌信号一视同仁。因此，他们开发了 TrustTrade：一个多代理架构，由多个 AI 代理互相交叉验证，并加入 时间序列信号（基于时间的模式）和过去交易的记忆。结果是，AI 开始表现得更像真正的投资组合经理，而不是带点额外步骤的掷硬币游戏。

🔍偏差问题  
AI 模型会把所有输入数据视为同等有效，无论它是噪音还是真实信号。这正是导致幻觉式交易和持仓不稳定的主因。

🧠人类的优势  
真正的交易员会进行过滤。他们会重视一致的信号，并舍弃噪音。这正是控制最大回撤的关键。

⚖️TrustTrade 的解决方案  
多个 AI 代理独立评估每个信号。如果它们无法达成一致，该信号就会被舍弃。方法简单，却非常有效。

📊实验结果  
更稳定的损益曲线、更低的回撤率，以及决策模式更接近中等风险的人类交易行为。

📌 值得注意的事项：  
该研究仅在有限的美国股票和加密货币交易对上进行测试。真实世界的滑点、流动性问题，以及市场状态转变（regime shifts）仍是开放性挑战。这个框架目前还处于早期阶段。

![](assets/001.png)

![](assets/002.png)

https://arxiv.org/abs/2603.22567

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)