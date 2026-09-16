# 大模型（LLMs）在处理财务报表时依然会翻车

InfinityQuant 映翡量化 2026-03-19 08:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491277&idx=1&sn=9dd1c3eeffc854fba86f77583fa9ea7b&chksm=9eb664310c67b31fccc6c4b1e827041ded38d309fe1ac601e765c67cb1e6f1eb1de46c9f79e4#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491277&idx=1&sn=9dd1c3eeffc854fba86f77583fa9ea7b&chksm=9eb664310c67b31fccc6c4b1e827041ded38d309fe1ac601e765c67cb1e6f1eb1de46c9f79e4#rd)

终于有人对此进行了严谨的测试。

**论文《FinSheet-Bench: From Simple Lookups to Complex Reasoning, Where LLMs Break on Financial Spreadsheets》（2026年3月7日）**对来自 **OpenAI、Google**和 **Anthropic**的 **10 款大模型**进行了测试，测试素材采用的是真实的私募PE报表。这正是分析师日常处理的那种：布局混乱、设有基金分隔符、多行表头等复杂格式。

结果：

目前没有一个模型能够达到在无人监督下工作的水平。

📊 **最高分：Gemini 3.1 Pro**，准确率为 **82.4%**。这意味着平均每 6 个问题就会答错 1 个。而金融行业的要求是 **97% 以上**。目前的差距还非常大。

🧮 **复杂性**是导致崩溃的主因。简单的数值查找准确率能达到 89%；但一旦要求计算跨基金的中位数，准确率就暴跌至 **19.6%**。即使是表现最好的前三名模型，在处理最难的任务时准确率也仅为 33%。

🔢 推理模式（Reasoning mode）确实有帮助。GPT 5.2 的表现提升了 **22.8 个百分点**，Claude Opus 4.6 提升了 **13.6 个百分点**。进步是明显的，但依然达不到生产环境的标准。

📉 **文件越大，表现越差。**如果扔给它们一个包含 152 家公司、8 支基金的大文件，所有模型的平均准确率仅为 **48.6%**。这基本上和**抛硬币**猜正反面的概率差不多。

结论：

**让大模型做它擅长的事——提取数值；然后让专业的代码去处理计算。**  

试图让一个模型同时完成这两件事，正是目前出错的根源。

该研究来自苏黎世的 **Qubera AG**和**苏黎世大学**。包含 24 个文件，每个模型需回答约 500 个问题，涵盖 7 个任务类别。

![](assets/001.png)

  

https://arxiv.org/abs/2603.07316

PDF已更新到星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)