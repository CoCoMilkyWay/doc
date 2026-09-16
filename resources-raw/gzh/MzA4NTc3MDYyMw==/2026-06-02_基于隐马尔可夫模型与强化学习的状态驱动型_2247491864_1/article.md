# 基于隐马尔可夫模型与强化学习的状态驱动型投资组合配置

InfinityQuant 映翡量化 2026-06-02 10:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491864&idx=1&sn=5e4ab6e584a65cee15135ae2d407e959&chksm=9e02cbf220544ec39615d6c0701a62ed8cc39f43ceb9e8b7fabe7e4e92b73832d7ac45100a9d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491864&idx=1&sn=5e4ab6e584a65cee15135ae2d407e959&chksm=9e02cbf220544ec39615d6c0701a62ed8cc39f43ceb9e8b7fabe7e4e92b73832d7ac45100a9d#rd)

年化收益 4.3% 的提升，最大回撤比标普 500 少三分之一，而且模型完全剔除了债券。

这篇论文《Regime-Based Portfolio Allocation Using Hidden Markov Models and Reinforcement Learning》（2026年1月10日）将隐马尔可夫模型（HMM）与强化学习（RL）结合，根据市场所处的“真实”状态，在三种 ETF（股票 SPY、黄金 GLD、长期国债 TLT）之间进行动态轮动。

其方法如下：

-   一个三状态的 HMM 将市场划分为：平稳期、过渡期和危机期
    
-   一个强化学习代理为每种状态学习最优资产配置
    
-   每一次调仓都具有可解释性，并非黑箱决策
    

模型学习到的配置规律：

-   平稳期 + 过渡期 → 100% 配置股票
    
-   危机期 → 100% 配置黄金
    
-   国债 → 在任何状态下都未被配置
    

结果：

在样本外测试中，该策略在收益和风险控制上均优于持有标普 500 指数：

-   年化收益：14.3%（对比 SPY 的 13.2%）
    
-   最大回撤：-23.5%（对比 SPY 的 -35.7%）
    

同时，该策略始终保持高度透明，能够清晰解释每一次交易决策的原因。

  

![](assets/001.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5785443

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)