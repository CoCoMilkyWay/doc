# 系统化交易的执行栈：好信号只是开始，基础设施决定生死

Raymond SystematicMacro 2026-07-28 08:56

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzI0MjU4NTcxNw==&mid=2247484342&idx=1&sn=4fd7ab0ad467b82a68dbc69887934f54&chksm=e8ed0ee2baa869ab43d4d900b3338635cf731034d38dc6d999af9712e22ad2de4686de5e71b4#rd](https://mp.weixin.qq.com/s?__biz=MzI0MjU4NTcxNw==&mid=2247484342&idx=1&sn=4fd7ab0ad467b82a68dbc69887934f54&chksm=e8ed0ee2baa869ab43d4d900b3338635cf731034d38dc6d999af9712e22ad2de4686de5e71b4#rd)

2026 年 7 月 28 日

## 🎯 核心观点

做系统化资金的真相是：策略可能只是工作的三分之一。剩下的是基础设施，而正是基础设施决定了一个好的 edge 能否在真实市场中存活下来。

几乎所有的努力都投入到信号生成，几乎没人关注支撑它的东西。直到你上线，才发现市场是最容易的对手。真正的对手是你自己的 setup。

## 💎 一句话总结：三个要点

• 回测再好的策略，如果底层执行层脆弱，也毫无价值。断线、拒单、坏 tick、保证金冲突，这些东西不会出现在任何回测里，却都能让一个盈利系统变成亏损。  
  
• 你的 broker 是系统的一部分，是 edge 必须穿过的 live component。同样的逻辑在一家 venue 可以盈利，在另一家可能就是缓慢失血。  
  
• 每天做 reconciliation。系统期望的 fill 与真实 fill 之间的 gap，是你能得到的最早警报。

## 📝 为什么基础设施决定 edge 能否兑现

edge 是一个统计声明，而基础设施决定你是否真的能 collect on it。

你的回测做出了一系列假设：订单被发出、被接受、以模型看到的价格或接近的价格成交、系统每一刻都知道真实仓位、数据是干净的。这些假设中的每一个在现实世界里都是一项工程，而且每一个都可能失败。

它们失败的时候，往往正是你的策略风险最大的时候——因为波动和成交量才是 broker、feed 和 connection 崩溃的触发条件。市场给了你机会， plumbing 却把它拿走。

## 📝 执行失败的清单

以下是值得坐下来认真想一遍的场景：

• 持仓时 connection 断开，系统恢复后不知道之前发送的 exit order 是否已成交。

• 快市中 broker 拒单，而你的代码从未建模过 rejection，还以为自己在交易里。

• 数据源打嗝，print 一个坏 tick，模型对一个从未真实成交的价格做出反应。

• 两个策略同时需要保证金，其中一个无法开仓。

• 周末 gap 穿过了一个只存在于代码里的 mental stop，而不是 broker 处的 resting order。

每一个都是具体、无聊、可解决的工程问题。但 collectively，它们就是大量盈利回测无法变成盈利账户的原因。

## 🤖 Broker 是系统的一部分

两个 broker，同一策略， materially different results。差距完全来自执行。

Requotes、拒单率、不对称滑点、日内 exact spread schedule、以及在新闻发布前后几秒 venue 的行为，这些在不同 broker 之间差异大到足以让策略在一家活得很好，在另一家缓慢失血。对于持仓周期短、换手高的策略尤其如此，因为成本占 edge 的比重很大。

所以在上规模之前，我会把 broker 当作系统的一个组件来测试。具体做法很直接：用真实的小仓位，在目标 venue 上跑策略（原文作者用 Darwinex Zero account 测试，低成本、无风险），记录每一个 intended order 和每一个 actual fill。

## 📊 数据：比你想的更危险

不同数据商的 bar construction 不同。timestamping 也不同，而这真的很危险。  
  
如果你的数据把 bar 时间戳标在 open，但你的代码用 bar 的 close 做决策，你就是在用那一根 bar 未来的信息交易。回测表现极好，但实盘不可复制——因为实盘信号触发时，那个 close 还没有发生。作者曾审计过一些系统，发现就这单个约定不匹配，就是整个 edge。  
  
然后是数据清洗。用下一个有效价格填补缺口，就是把未来泄露到过去；在拆分前 normalize 整个序列，你的 out-of-sample 就已经见过测试集的均值和方差；用当天不知道的信息调整 roll，你的回测就知道实盘系统永远不可能知道的事。  
  
每一条转换只能使用那个时间戳真正可用的数据。像数据是一根一根 arrival 那样清洗它，因为实盘就是这样。

## 📝 VPS：关于 uptime，而非 latency

对大多数零售系统化策略来说，真正的问题是 uptime。如果你的系统需要在你不在的时候运行，那它就会在你持仓的时候遇到家用机器重启、休眠或宽带掉线。VPS 靠近 broker 服务器可以解决这个问题：它一直在线。

除非你做极短周期交易，否则 latency 远没有你想的那么重要。对于持仓几分钟到几天、跨 FX、指数、金属的系统，执行可靠性和成本建模才是主导。毫秒很少是瓶颈。真正让你付出代价的是 order certainty：你每时每刻都知道自己的真实仓位是否和代码认为的一致。

真正重要的是无聊的冗余：你离开 desk 时能收到 alert；能用手机 flatten book；事后能读懂 log——因为你一定需要它们。

## 📝 每天 Reconcile：最早的警报

每天把 broker 给你的 fill 与系统期望的 fill 匹配。每一个 order、每一个价格、每一个时间戳。两者之间的 gap 是你能得到的最早警报——前提是你把它接上线。

数周内逐渐扩大的 slippage、持续晚到的 fill、快市中毫无预警的拒单让你 flat 而代码还以为你在 long——所有这些都会在 reconciliation 中早于 P&L 暴露。等到 broken execution path 出现在权益曲线上时，它已经让你亏了真金白银。

除了 reconciliation，还要监控策略行为是否在其预期 envelope 内，而不仅是 returns。如果一个系统交易频率是预期的两倍，或持仓时间只有一半，说明数据或逻辑发生了变化，通常在行为上会比在利润上更早可见。

## 📝 每个失败都需要一个确定的归宿

把 resilient system 与 fragile system 区分开的，是失败时它落在哪里。一切都会失败；设计问题是失败目的地。

• connection 在持仓时断开，系统是回来先与 broker 的真实状态对账，还是基于 stale internal state 行动？

• order 被拒，代码是否知道、合理重试、并在 bounded attempts 后停止，还是不断 hammer venue？

• 数据 feed print 出不合理的价格，系统是据此交易，还是拒绝对一个没通过 sanity check 的 tick 行动？

先定义 safe state。通常是 flat，或者在 broker 处有 resting protective order，而不是代码里的 mental stop。然后让每一条失败路径都通向那里。

## 📝 硬性上限：在最上层设硬限制

在一切之上设置硬限制：同时开仓风险的天花板；达到就 flatten book 的每日最大亏损；系统每分钟最多能发送多少订单。这些并不复杂，一天就能搭好。  
  
如果你有组合层面的风险控制需求，还需要 portfolio-level 的监控——因为保证金和同时 exposure 是组合问题。但要记录每个策略的归因，否则你永远找不出是哪个 component 在衰减。

## 📝 最可怕的损失来自哪里

最可怕的损失来自：系统认为自己的仓位与 broker 认为的仓位之间的 gap。  
  
如果你假设订单按代码期望的方式成交，而现实并非如此，你就会持有自己不知道的仓位、空仓、或反向仓位。真正的黑天鹅不是市场价格跳空，而是你以为自己没有风险的时候其实正重仓。

## 📝 结语

有一种系统化交易只存在于回测里：订单以你看到的价格瞬间成交，connection 永不掉线，数据永远干净。那是一个美好的地方，我们谁也不在那里交易。

真正的工作是脚手架：知道 dropped order 和 filled order 区别的 reconnection logic；每天运行的 reconciliation；同时风险的硬限制；在损失发生前就通知你的 monitoring。这些永远不会是你工作中有趣的部分，但正是它们让有趣的部分能够真正产生收益。

edge 让你进入游戏。基础设施让你留在游戏里，久到 edge 能够发挥作用。