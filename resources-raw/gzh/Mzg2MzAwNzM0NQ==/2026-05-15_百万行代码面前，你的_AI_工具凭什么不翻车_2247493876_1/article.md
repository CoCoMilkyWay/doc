# 百万行代码面前，你的 AI 工具凭什么不翻车？

QuantML QuantML 2026-05-15 18:44 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493876&idx=1&sn=836009b4c3610ef0eb7e3d6188069b3c&chksm=cfceb4b825e3e8c968d546c49d53e096c58c0f9acad18cc284b89ccfb3f8a6f7181e98158289#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493876&idx=1&sn=836009b4c3610ef0eb7e3d6188069b3c&chksm=cfceb4b825e3e8c968d546c49d53e096c58c0f9acad18cc284b89ccfb3f8a6f7181e98158289#rd)

大伙可能已经看腻了各路 AI coding 工具拿着 benchmark 到处吹。按照自媒体的叙事节奏，这个行业似乎已经被颠覆了无数次。

但是实际上，当你将这类工具投入一个百万行量级的真实工程时，不知道大伙有没有跟我一样的感受：AI 生成的代码往往缺乏可维护性，写出的屎山代码，远非想象中那般美好。

最近Anthropic发布了一篇技术文章，讲述了他们如何将claude code应用于实际的生产项目。核心结论很明确——**决定 AI 编码工具表现的，根本不是模型本身。是它周围的 harness。** 你模型再强，丢进一个导航成本比修改成本还高的代码库里，照样抓瞎。

**所以问题就来了：为什么 AI 工具在真实的、百万行级别的代码库里总是不好使？**

![](assets/001.png)

## RAG 的问题不是精度，是新鲜度

传统 RAG 的思路是 embedding 整个代码库，查询时召回相关 chunk。这个方案在小型 repo 里能跑，但在大型代码库里会撞上一堵墙：**embedding pipeline 跟不上 commit 频率。** 几百个工程师 AI在提交，索引反映的可能是三天前的状态——你查询时它返回一个两周前 rename 掉的函数，或者引用上个 sprint 就删掉的模块，而且没有任何信号告诉你这已经过期了。

Claude Code 的选择是不做预索引。它直接在本地文件系统上遍历、grep、读文件。好处是零维护成本、零延迟，每个开发者都在自己的 live codebase 上工作。代价是：**agent 需要足够好的起点，否则在百万级文件里就是大海捞针。**

这个 tradeoff 对工程团队很具体。如果你的项目里 build 命令在每个子目录都不一样，或者代码散落在没有共同根的文件夹里，agent 的搜索成本会直接吃掉所有效率收益。不是模型不够聪明，是它不知道从哪里开始找。

## Harness 七层：按这个顺序建，不可打乱

Anthropic 把 harness 拆成了七个组件，并且这七个组件**搭建的顺序很重要**。我从工程落地的角度重新梳理了一遍：

### 第一层：CLAUDE.md —— 先建，但别写长

这是 Claude 每次会话自动加载的上下文文件。根目录放全局大图，子目录放局部约定。Claude 会自动沿目录树向上加载，所以根级上下文不会丢。

最常见的错误是把它写成使用说明书，塞进去几十页。结果每次会话都加载一堆噪音，关键信息反而被稀释。所以最佳方法应该是：根文件只放指针和 critical gotchas，其他东西下沉到子目录的 CLAUDE.md。

我的建议是：在你的根目录放一个 CLAUDE.md，说明项目结构（服务边界、数据流、关键模块位置），以及两个绝对不能让 AI 碰的东西（比如生产环境配置、密钥管理逻辑）。每个服务的子目录再补充自己的 build/test/lint 命令。

### 第二层：LSP —— 大型代码库的最高 ROI 投资

Claude Code 默认靠 grep 做代码导航。在大型代码库里，grep 一个常见的函数名可能返回几千个结果，agent 只能逐个打开文件去猜哪个是对的——上下文窗口直接烧光。

LSP（Language Server Protocol）给 Claude 提供了 symbol-level 的精度：跳转到定义、查找所有引用、区分不同语言里同名函数。过滤发生在 agent 读文件之前。

没有 LSP，Claude 在做的是 pattern matching；有了 LSP，它做的是 symbol resolution。差距是巨大的。

### 第三层：Skills —— 按需加载，不要常驻

Skills 是打包好的指令集，只在特定任务时触发，不常驻上下文。可以绑定到特定路径，只在相关目录激活。

这个设计的价值在于 progressive disclosure。一个做前端改动的工程师不需要每次启动都加载部署相关的 domain knowledge。Skills 把专业化工作流从每个会话里卸下来，只在需要时加载。

工程场景里可以考虑的 skills：安全审查 skill、文档同步 skill、API 兼容性检查 skill、依赖升级 skill。比如支付服务团队可以把自己的部署 skill 绑定到该目录，确保它不会在 monorepo 其他位置误触发。

### 第四层：Hooks —— 持续改进比拦截错误更有价值

大多数人把 hooks 想成 guardrail——阻止 Claude 做错事。但其实更有价值的用法是**让配置自我改进**。session 结束后的 stop hook 可以回顾刚才发生了什么，在上下文还新鲜的时候提议更新 CLAUDE.md。start hook 可以动态加载团队特定的上下文。

对于 linting、formatting 这类自动化检查，hooks 比依赖 Claude"记住"规则更可靠。规则执行是确定性的，结果是可复现的。

### 第五层：MCP Servers —— 基础打牢前别碰

MCP 是 Claude 连接内部工具、数据源和 API 的接口。文章明确把这一层放在后面，因为"building MCP connections before the basics are working"是最常见的错误。

工程团队常见的 MCP 场景：连接内部文档系统、 ticketing 平台、监控 dashboard、分析平台。但前提是 Claude 已经能可靠地在你的代码库里导航了。否则外部连接越多，出错时的调试面越宽。

### 第六层：Subagents —— 把探索和编辑拆开

用一个只读的子 agent 先 map 子系统，把发现写到文件里，主 agent 再基于完整信息做编辑。这在深入未知代码库时很有用，但日常迭代里不一定每次都值得。

### 第七层：Plugins —— 团队推广时才需要

把 skills、hooks、MCP 配置打包成 installable package，新工程师 day one 就能拿到和资深成员一样的配置。适合已经有成熟 setup、准备规模化推广的阶段。文中提到一家 retail 组织在 Claude Code 广泛推广之前，先通过 plugin 分发了连接内部 analytics platform 的 skill。

## 一个被很多人忽略的点：配置会过期

随着模型升级，以前为了补偿模型缺陷而写的规则和 hooks，可能变成束缚。

具体例子：旧模型做跨文件重构时容易翻车，所以你在 CLAUDE.md 里写了一条"每次只改一个文件"。新模型能处理协调式跨文件编辑了，这条规则反而限制了它能做的事。另一个例子：有人在 Perforce 代码库里写了一个 hook，拦截文件写入来强制执行 p4 edit，Claude Code 原生支持 Perforce 之后这个 hook 直接变成冗余代码。

建议每 3-6 个月 review 一次配置，或者每次大模型更新后检查一遍。这个维护成本需要被计入总拥有成本。

## 总结

Claude Code 在大型代码库里的表现，取决于代码库本身有多"可读"。这不是一个开箱即用的工具，至少在复杂环境里不是。

-   如果你的 repo 有清晰的目录语义、标准化的服务结构、每个子目录有自己的 build/test 命令，从 CLAUDE.md + LSP 开始配置，阻力不大。
    
-   如果你的代码库是自然演进而未经顶层设计的遗留系统，目录结构没有统一约定，先花功夫做代码库全景图和目录整理，再上 AI 工具。否则 agent 的搜索开销会吃掉所有效率。
    
-   不要指望 AI 解决架构问题。它只能在已有结构里更高效地工作。结构本身是人类的责任。
    

  

参考链接：https://claude.com/blog/how-claude-code-works-in-large-codebases-best-practices-and-where-to-start

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)