# 一人量化基金：如何用 Loop Engineering 搭建自进化量化框架？

QuantML QuantML 2026-07-05 12:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247494210&idx=1&sn=66608fb1b4471c7a92777428a09b007c&chksm=cfb5e4667c11424c5dbc3f01fc9eb1a110bbc0992bd1c9b8d2c2c98efafa9e2a8958ebfbea56#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247494210&idx=1&sn=66608fb1b4471c7a92777428a09b007c&chksm=cfb5e4667c11424c5dbc3f01fc9eb1a110bbc0992bd1c9b8d2c2c98efafa9e2a8958ebfbea56#rd)

> “
> 
> **"我不再提示 Claude 了。我有循环在运行，它们自己在提示 Claude，自己决定下一步怎么做。我的工作是写循环。"**
> 
> —— Boris Cherny，Anthropic Claude Code 负责人，2026 年 6 月

这句话在过去一个月里震动了整个 AI 工程圈。Boris 在 2025 年 11 月卸载了自己的 IDE，此后单月合并 259 个 PR，全部出自 Claude Code 之手。到了 2026 年 3 月，Claude Code 这个产品本身已经 **100% 由 Claude Code 编写**。

Google 工程总监 Addy Osmani 将这种范式正式命名为 **Loop Engineering（循环工程）**。

量化交易本质上就是一个循环：拉数据、生成信号、回测验证、执行下单、监控风险、重复。Renaissance 从 1988 年开始跑这个循环，Citadel、Two Sigma、Jane Street 都在跑。**唯一的区别是，他们需要几百个人坐在循环里面，而你不需要。**

在本文中你会看到如何将 Loop Engineering映射到量化交易的五个阶段，以及一套可以直接落地的 MCP 连接器方案，让循环从"给建议"进化到"真下单"。

## Loop Engineering 到底是什么

过去两年，你用 AI 的方式是这样的：打字、等输出、读结果、决定下一步、再打字。**你是循环本身，Agent 只是你手里的工具。**

Loop Engineering 把这个关系倒转过来。你不再坐在循环里面做决策节点，你站在循环外面做架构师。你定义目标，Agent 对着目标迭代，循环自己决定什么时候继续、什么时候停止、什么时候把经验写进记忆。

_自进化量化交易系统的五阶段循环与三大基础设施层_

这里面的关键认知是：**Agent 每次运行都会遗忘，但循环不会。** Agent 是 Stateless 的，它处理完一个任务就清空上下文；循环是 Stateful 的，它通过 STATE.md 文件、SKILL.md 指令和验证器机制，让经验在迭代中持续累积。这正是量化系统最需要的特质——每一次交易的结果，都应该成为下一次决策的输入。

Boris 描述的演进阶梯非常清晰 ：**2023 年你手写代码，2024 年你提示 Claude 写代码，2025 年你写循环让 Claude 自己跑，2026 年你搭建运行循环的 Harness。** 对于量化交易来说，这个 Harness 就是一个自进化的交易系统。

## 基础设施

Loop Engineering 定义包含六个通用组件。这六个组件不是 Claude Code 独有的——它们出现在 Codex、出现在 AutoGPT、出现在每一个能在生产环境跑起来的 Agentic 系统里。

组件

通用定义

量化交易映射

关键配置

**Automation**

循环的心跳：cron、webhook、/loop 命令

数据拉取定时器、信号扫描触发器、风险检查频率

`/loop every 1h`

 或 `/goal sharpe > 1.5`

**Skill**

保存在 SKILL.md 中的程序化手册

Alpha 研究规则、风控约束、品种白名单

每次损失自动写入新规则

**State File**

跨运行持久化的 markdown 状态文件

持仓记录、未成交信号、回测结果、经验教训

STATE.md / PROGRESS.md

**Verifier**

独立的验证 Agent，不同模型、不同指令

回测验证器、风险合规检查、信号质量评估

Maker-Checker 分离，Opus 验证/Sonnet 生成

**Worktrees**

Git 隔离工作区，避免多 Agent 文件冲突

并行回测分支、独立策略研发环境

`isolation: worktree`

**Connectors**

MCP 协议连接外部 API 和数据源

券商交易接口、行情数据、Slack/邮件通知

TraderEvolution MCP  tools

  

这六个组件里，**Verifier（验证器）是最容易被低估、也是 Loop 失败的最主要原因**  。生成信号的 Agent 同时兼任裁判，会系统性地高估自己的工作质量——这跟 Wall Street 的 Maker-Checker 分离原则完全矛盾。Jane Street 的 proposing trader 和 approving trader 必须是两个人；你的量化循环里，生成信号的模型和验证信号的模型也必须是两个独立实例。

![https://github.com/cobusgreyling/loop-engineering/blob/main/assets/visuals/LE5.jpeg](assets/001.jpg)

## 五阶段量化循环：从数据到 risk-off 的完整链路

把六大组件组装起来，就得到一个完整的自进化量化交易系统。这个系统由 **五个子循环** 构成，每个子循环有自己的 Skill、自己的 State File、自己的 Verifier。

### Stage 1：数据摄取（Data Ingestion）

这是整个系统的心跳。根据资产品类设置不同频率：加密可以每分钟拉一次，股票日线策略可以每小时或每日触发。

```
# .claude/commands/ingest.md@loop(interval="1h")def ingest_data():    data = fetch_market_data(        symbols=universe,      # 交易品种清单，从 SKILL.md 读取        lookback="30d",        # 回看窗口        sources=["alpaca", "polygon"]  # 多源聚合    )    state.write("latest_data.parquet", data)    state.append("STATE.md", f"\n[{datetime.now()}] Data ingested: "                            f"{len(data)} rows, {len(universe)} symbols")
```

关键设计要点：**数据源必须多源交叉验证**。单一数据源的故障会导致整个循环产生垃圾输入。

### Stage 2：信号生成（Signal Generation）

这是 Alpha 研究的核心战场。Signal Generation Agent 从 alpha\_research\_skill.md 读取规则，这个文件会随着每次交易结果自动进化。

```
<!-- alpha_research_skill.md -->## Goal基于过去 30 天的价量数据生成交易信号，采用线性回归 + 动量复合模型## Rules- Sharpe 比率在最近 5 次回测中至少 3 次 > 1.5- 单信号仓位上限 2%- FOMC  announcement 当日跳过所有信号- 财报发布前 48 小时跳过相关标的## Lessons Learned- 2026-02-14: 财报周亏损 4.2%。新增规则：财报前 48h 跳过- 2026-03-08: 行业集中度突破导致 6% 回撤。新增规则：单一行业暴露上限 30%- 2026-04-22: 动量信号在 FOMC 日爆炸。新增规则：FOMC 日 kill 所有动量信号
```

**Skill 文件的自进化机制是整个系统的灵魂。** 每次 Risk Monitoring 阶段检测到异常，都会自动追加一条 Lessons Learned。下一次 Signal Generation Agent 读取 Skill 时，这些规则已经成为它的行为约束。这不是简单的日志记录，而是**用结构化经验持续压缩策略的失效空间**。

### Stage 3：验证（Verification）

信号必须通过完全独立的验证层才能进入执行阶段。这是 Maker-Checker 分离原则的技术实现。

```
# .claude/commands/verify.md —— 独立验证 Agent 的指令@checker(model="claude-opus-4")  # 用更强模型做验证def verify_signal(signal):    result = claude.invoke(        skill="backtest_verification_skill.md",        signal=signal,        rules=[            "Sharpe ratio > 1.5 (Newey-West adjusted)",            "Max drawdown < 10%",            "Out-of-sample period >= 2 years",            "Newey-West t-stat > 2.0",            "Position size <= 2% of NAV",            "Not in earnings blackout window"        ]    )    return result.verdict  # PASS / FAIL / NEEDS_REVIEW
```

验证器的设计有几个硬性要求：**必须用不同的模型**、**必须看不到生成器的推理过程**（防止 confirmation bias）、**停止条件必须可被独立检查**（"Sharpe > 1.5" 可以验证，"我觉得这个信号不错" 无法验证）。

### Stage 4：执行（Execution）

只有验证通过的信号才能到达这里。执行层通过 MCP 连接器直连券商 API，实现真正的无人值守。

```
# execution 层通过 MCP 连接券商@auto_mode  # 免人工确认，直接下单@loop(trigger="signal_verified")def execute(signal):    if verify_signal(signal) == "PASS":        broker.place_order(            symbol=signal.symbol,            side=signal.side,            qty=signal.position_size * nav,            order_type="TWAP",           # 拆单执行，降低冲击成本            max_slippage_bps=10          # 滑点上限        )        state.write("active_trades.json", signal)        state.append("STATE.md",            f"\n[{datetime.now()}] EXECUTED: {signal.symbol} "            f"{signal.side} @ {signal.expected_price}")
```

执行层的关键是 **MCP（Model Context Protocol）连接器**。MCP 是 Anthropic 推出的开放标准，让 LLM 通过结构化 JSON 调用外部工具  。目前已经有多个券商的 MCP Server 实现：Interactive Brokers  、TastyTrade 、Angel One 、SnapTrade  ，以及 TraderEvolution 的 31-tool 生产级实现  。

### Stage 5：风险监控（Risk Monitoring）

这个子循环在独立的 Git worktree 中并行运行，是整个系统的 kill switch。

```
# 独立 worktree 中的风险监控循环@loop(interval="1m")  # 每分钟检查def monitor_risk():    positions = broker.get_positions()    nav = calculate_nav(positions)    dd = current_drawdown(nav)    # 硬止损：单日回撤 5% 清仓    if dd > 0.05:        broker.close_all_positions()        state.append("STATE.md",            f"\n[{datetime.now()}] RISK EVENT: Drawdown {dd:.2%}. "            f"All positions closed.")        # 触发 Skill 进化        skill.append_lesson(            date=datetime.now(),            event=f"Drawdown trigger {dd:.2%}",            new_rule="Review position sizing model after >4% drawdown"        )    # 行业集中度检查    sector_exposure = calculate_sector_exposure(positions)    if any(exp > 0.30for exp in sector_exposure.values()):        # 发送警报，不自动清仓（给人工判断空间）        alert.send(f"Sector exposure breach: {sector_exposure}")
```

## MCP 连接器：从"给建议"到"真下单"的关键一跃

很多量化开发者的 AI 系统卡在最后一公里：Agent 能分析、能给信号，但无法直连交易账户。MCP 解决了这个问题。

MCP 的本质是一个**标准化的工具调用协议**。Agent 不需要知道 Alpaca API 或 Interactive Brokers API 的具体细节，它只需要调用 `place_order(symbol="AAPL", side="buy", qty=100)`，MCP Server 负责把结构化调用翻译成券商能理解的请求  。

```
# MCP Server 配置示例（claude_desktop_config.json）{"mcpServers": {    "alpaca_trading": {      "command": "python",      "args": ["-m", "alpaca_mcp_server"],      "env": {        "ALPACA_API_KEY": "...",        "ALPACA_SECRET_KEY": "...",        "PAPER_TRADING": "true"# 先用模拟盘      }    },    "market_data": {      "command": "python",      "args": ["-m", "polygon_mcp_server"],      "env": {        "POLYGON_API_KEY": "..."      }    }  }}
```

当前可用的交易 MCP Server 生态已经相当丰富：TraderEvolution 提供 31 个工具的完整多资产交易能力 ；Interactive Brokers 的 MCP 实现支持自然语言下单 ；TastyTrade 的 MCP Server 甚至内置了期权 Greeks 计算和 DXLink 实时行情。建议先用模拟盘测试。

## 生产部署

Loop Engineering 的一个常见陷阱是**循环失控**。Boris 本人也强调：没有真实停止条件的循环会安静地失败——Agent 发出完成信号，认为半成品的任务已经做完，循环退出，坏交易却留在场上 。

部署前的强制性检查清单：

检查项

具体要求

失败后果

**停止条件可验证**

"Sharpe > 1.5" ✓ / "Agent 说做完了" ✗

循环提前退出，半成品信号流入市场

**预算上限**

设置 `--max-turns` 和月度 API 预算

一个失控的 200 轮循环可能消耗 $80+ 

**Maker-Checker 分离**

生成模型 ≠ 验证模型

信号质量系统性高估，假 Alpha 流入实盘

**Worktree 隔离**

并行子循环使用独立 Git 分支

文件冲突导致状态损坏

**只读启动**

前 3 天仅做 summary，不下单

验证循环逻辑正确性

**日志完整**

所有决策写入 STATE.md + 外部日志

出问题时无法复盘

成本方面需要心中有数。Loop 的 token 消耗是单轮对话的几十到几百倍——每轮工具调用的上下文会在后续轮次中累积重发，第 20 轮迭代时单次输入可能超过 50K tokens。以 Opus 4.8 的 $5/百万 input tokens 计算，一轮成本约 \\$0.25，**200 轮的开环任务可能花费 $80 以上**。

**建议的成本控制策略**：信号生成阶段用 Sonnet（$3/ 百万 tokens），验证阶段才用 Opus（\\$15/百万 tokens）；日常监控循环用 Haiku（$0.25/百万 tokens）；设置 `--max-turns 30` 作为硬性上限。

## 结语：你写循环，循环替你交易

Loop Engineering 在量化交易领域的意义，远不止"自动化"三个字。它代表了一种范式转移：**你的核心竞争力从"写一个更好的策略"变成"设计一个能持续产生更好策略的系统"** 。

Renaissance 和 Citadel 的优势不是某个具体的因子，而是他们跑了三十年的进化循环——每一次交易结果都被结构性地反馈到下一次信号生成中。现在，一个 solo quant 用 Claude Code + MCP + 六个核心组件，就能搭建出同构的进化架构。

Boris Cherny 每天从手机上发出几十个 PR。你完全可以设计一个循环，让它在你睡觉时拉数据、在你开会时跑回测、在你度假时监控风险。**你的工作是写循环。循环的工作是交易。**

  

完整的自进化SKILL.md欢迎加入QuantML知识星球 获取

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/002.jpg)