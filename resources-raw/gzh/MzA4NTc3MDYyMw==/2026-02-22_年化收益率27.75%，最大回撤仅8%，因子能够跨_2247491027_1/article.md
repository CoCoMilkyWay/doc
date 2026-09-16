# 年化收益率27.75%，最大回撤仅8%，因子能够跨洲转移

InfinityQuant 映翡量化 2026-02-22 09:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491027&idx=1&sn=3d311818c19e38d08ef4683f231faac4&chksm=9ebef2e5966cf9a42aecc4b2d37b94725b410ab42c7b531f541a07f602e29eac0c43e5f93c9c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491027&idx=1&sn=3d311818c19e38d08ef4683f231faac4&chksm=9ebef2e5966cf9a42aecc4b2d37b94725b410ab42c7b531f541a07f602e29eac0c43e5f93c9c#rd)

**论文《QuantaAlpha: An Evolutionary Framework for LLM-Driven Alpha Mining》（2026年2月6日）提出了** **QuantaAlpha** —— 一个进化式框架，利用大型语言模型（LLM）通过**轨迹层面的变异（mutation）与交叉（crossover）**来挖掘alpha因子，类似于遗传算法演化最优解的过程。

![](assets/001.png)

核心机制：

-   每一次完整的因子挖掘运行都被视为一条**轨迹**（trajectory）：假设提出 → 因子构造 → 回测表现。
    
-   通过迭代演化不断改进这些轨迹。
    

具体操作方式：

-   **变异（Mutation）：定位轨迹中的失败或薄弱环节，仅针对性地重写出错的那个步骤。**
-   **交叉（Crossover）：从高表现的“父代”轨迹中，重组出已被验证有效的片段。**
-   **约束门控（Constraint gates）：强制保证假设、因子表达式、可执行代码之间的**语义一致性**；同时限制复杂度，并通过**AST子树匹配**过滤冗余因子。**

实证结果（使用GPT-5.2）：

-   在**中证300（CSI 300）**上：信息系数（IC）达到0.15，年化收益率（ARR）**27.75%**，最大回撤（MDD）**7.98%**—— 在所有指标上全面超越RD-Agent和AlphaAgent等基线。
    
-   **零样本迁移到中证500（CSI 500）和标普500（S&P 500）：四年累计超额收益率分别达到**160%**和**137%。****

亮点：

QuantaAlpha挖掘出的因子，在**2023年中国市场剧烈市场风格切换**中完好存活，而几乎所有基线策略都被碾压。 原因在于它发现了**结构性的微观市场信号**，而不是简单依赖容易失效的动量代理变量。

一句话总结：

**QuantaAlpha把“进化”这个生物学概念真正带进了量化因子挖掘，用轨迹级别的遗传操作 + LLM的创造力，实现了在噪声、非平稳市场中更鲁棒、更可迁移的alpha发现。**

![](assets/002.png)

https://arxiv.org/abs/2602.07085

https://github.com/QuantaAlpha/QuantaAlpha

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)