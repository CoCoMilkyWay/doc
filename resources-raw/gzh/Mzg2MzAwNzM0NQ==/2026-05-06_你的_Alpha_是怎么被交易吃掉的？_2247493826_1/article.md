# 你的 Alpha 是怎么被交易吃掉的？

QuantML QuantML 2026-05-06 07:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493826&idx=1&sn=52a4c84e92e4f89a712cf8174fe096b2&chksm=cf5e6adb0181c42d8bace5dd0e928831de2c5003a79066e5b665cff002d2a10f36dcd67a1435#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493826&idx=1&sn=52a4c84e92e4f89a712cf8174fe096b2&chksm=cf5e6adb0181c42d8bace5dd0e928831de2c5003a79066e5b665cff002d2a10f36dcd67a1435#rd)

![](assets/001.png)

  

很多量化策略的 Alpha 并不是在模型里死的，是从决策价到成交价这最后一公里里，被盘口、延迟、滑点和错误的下单规则慢慢磨掉的。很多看似美好的回测曲线，一旦加入交易成本就变得惨不忍睹。

很多人聊 execution，最后只剩一句：“注意冲击成本。”

问题是，多少？怎么算？什么时候爆？不知道。

更完整的框架可以看 Perold 的 Implementation Shortfall。它把从决策到成交的损耗拆成几块：

成本类型

含义

常见坑

显性成本

佣金、费率、印花税

最容易算，但不是大头

延迟成本

决策到下单之间价格漂移

信号衰减、排队审批、风控延迟

执行成本

market order 滑点和冲击

walk book、吃 spread

机会成本

没成交的部分后面价格跑了

太保守的 limit order

时间风险

拉长执行降低冲击，但价格方差变大

执行窗口越长，不确定性越大

Almgren-Chriss 框架里，一个常见的临时冲击近似是：

```
temporary impact = η × σ × sqrt(Q / V)
```

假设波动率 σ=2%，你的订单是 10% ADV，η=0.5，那么：

```
0.5 × 0.02 × sqrt(0.1) = 0.316% = 31.6bps
```

31.6bps 的冲击成本。如果你的 Alpha 才 15bps，还没开始就已经亏了。

这也是为什么很多中低频策略在回测里看起来很漂亮，一到实盘就像被人削了一层皮。

## 1\. TWAP 和 VWAP 的问题：静态正义

TWAP 的逻辑很简单：均匀切，按时间下单。每 15 分钟下一次，不管市场在干嘛。

VWAP 稍微聪明一点：按历史成交量分布下。开盘和收盘多下，中间少下。

在流动性不错的股票上，VWAP 通常会比 TWAP 好一点，在A股中证500成分股中：TWAP 平均 implementation shortfall 约 23bps，VWAP 约 19bps。

这 4bps 看起来不多，但在很多指增策略里，可能就是超额收益的 1/4 到 1/3。

但问题在于，TWAP 和 VWAP 都是静态规则。

TWAP 不管开盘 5 分钟 spread 是不是全天最宽，也不管午盘 depth 是不是薄，时间到了就下。

VWAP 假设今天的成交量分布和过去 20 天差不多。但如果有突发消息？如果大户突然砸盘？如果开盘成交量确实高，但 spread 也贵得离谱？

更关键的是：VWAP 的目标不是最小化成本，而是跟踪 VWAP benchmark。如果你的 benchmark 本身就是一个昂贵的目标呢？

## 2\. Market Order 和 Limit Order，不是二选一

Market order 的好处是确定性高，坏处是成本高。你要买，就直接吃 ask；盘口浅一点，就 walk 多个 level。

Limit order 的好处是价格更可控，至少可能省掉 half-spread；坏处是不确定。你挂在那，市场往不利方向跑了，它可能永远不成交。

很多团队的粗规则是：小单用 MO，大单用 LO。

这个规则太糙了。这个问题其实也可以改成一个动态分配的RL问题：每个时间点，不是决定“买不买”，而是决定多少比例用 MO，多少比例挂 LO，多少比例 hold。

参考的状态包括：

状态变量

为什么重要

order book shape

看各档 bid/ask volume

spread

决定直接吃单贵不贵

最近 15 秒 market order flow

判断主动成交压力

最近 15 秒 limit order flow

判断流动性是否在注入

cancellation flow

判断流动性是否在撤退

queue position

你挂的 LO 到底排第几

剩余仓位和剩余时间

决定时间压力

动作空间也不是“MO/LO/hold”三选一，而是一个比例向量：

```
a = (MO比例, LO各档比例, hold比例)
```

这点很重要。真实执行需要在确定性、成本和时间风险之间做动态分配。

## 3\. RL 的核心

RL 交易的核心在于以下三点：

第一，动作应该是比例，不是开关。

action 可以用 logistic-normal 分布建模，保证所有动作比例加起来等于 1，每个比例都大于等于 0。对实盘规则引擎也有启发：不要写成“spread > 3bps 就 LO，否则 MO”。更合理的是输出：

```
MO 40%，LO 45%，hold 15%
```

第二，执行质量要相对决策价评估。

不要只看最后赚没赚钱。市场本身涨跌会污染判断。更好的评价方式是看实际成交相对决策价偏了多少，也就是 implementation shortfall。

第三，市场环境不是中性的。

你的下单行为本身会改变市场。尤其是大单，你不是在一个静态盘口里成交，而是在和其他交易者互相暴露、试探、反应。

## 4\. 不用 RL 也可以用规则模型

小团队不一定要上 RL。训练一次几小时到十几个小时，还要 tick data replay、仿真环境、paper trading，成本不低。

但你至少可以把“时间表优先”改成“盘口状态优先”。

一个简化版三层框架如下：

层级

判断规则

动作倾向

盘口状态

spread < 2bps 且 depth > 5倍订单量

可以提高 MO

盘口状态

spread > 5bps 或 depth < 2倍订单量

改 LO 或拆小

盘口状态

imbalance > 0.7

尝试 bid+1 tick LO

盘口状态

imbalance < -0.7

谨慎挂 LO，考虑 hold 或 MO

时间压力

剩余时间 > 50%，剩余仓位 < 50%

可以耐心

时间压力

剩余时间 < 20%，剩余仓位 > 30%

提高 MO

微观结构

开盘 30 分钟

spread 宽，LO 为主

微观结构

午盘

depth 薄，order size 要更小

微观结构

收盘前 30 分钟

volume 高，但 tactical trader 活跃

可以写成一个很粗的规则函数（完整框架代码见知识星球）：

```
def execution_decision(    spread_bps,    depth_ratio,    imbalance,    time_remaining_pct,    position_remaining_pct,    is_open_30min,    is_close_30min,    is_lunch,):    mo, lo, hold = 0.3, 0.5, 0.2    if spread_bps < 2and depth_ratio > 5:        mo += 0.3        lo -= 0.2        hold -= 0.1    if spread_bps > 5or depth_ratio < 2:        mo -= 0.2        lo += 0.1        hold += 0.1    if imbalance > 0.7:        lo += 0.2        mo -= 0.1        hold -= 0.1    if imbalance < -0.7:        lo -= 0.2        hold += 0.2    if time_remaining_pct < 0.2and position_remaining_pct > 0.3:        mo += 0.4        lo -= 0.2        hold -= 0.2    if is_lunch:        mo -= 0.1        hold += 0.1    total = mo + lo + hold    return mo / total, lo / total, hold / total
```

这段代码不能直接上生产。它的价值是提醒你：执行决策至少应该看 spread、depth、imbalance、剩余时间和剩余仓位，而不是只看钟表。

更深的坑在于，如果所有人都按 imbalance 下单，imbalance 本身就会失效。这就是 market microstructure 里很烦的自指问题：信号一旦被广泛使用，就会改变它自己的含义。

## 5\. 个人观点：先别迷信 RL，先把执行账算清楚

大部分团队现在的问题是连基本的 execution attribution 都没做好。

如果你不想上复杂模型，个人建议至少做到以下三件事。

最低配置：

1.  不要用纯 TWAP。至少用 VWAP + spread filter，spread > 5bps 时暂停 MO，改 LO 或 hold。
    
2.  记录 queue position。如果挂了 10 秒还在第 10 位之后，cancel 重挂或改策略。
    
3.  每次大额交易后计算 implementation shortfall，不要只在月报里看平均交易成本。
    

进阶配置：

1.  做实时 order book 面板：spread、depth、imbalance、最近 15 秒 ΔM/ΔL/ΔC。
    
2.  用历史 tick data 回测执行规则，不要继续用固定 10bps 成本糊弄自己。
    
3.  记录 cancel、modify、submit 的延迟。如果 cancel-to-modify 平均超过 150ms，基础设施要查。
    

高阶配置：

1.  训练简化版 RL agent，state space 先压到 6-8 个变量。
    
2.  action space 不要太花，先做 MO/LO/HOLD 三维比例。
    
3.  用真实 tick data replay，而不是 random walk。
    
4.  上线前至少做 3 个月 paper trading，对比基准是 TWAP 和 VWAP。
    

最后一句话：亏损不一定来自模型，很多时候，它是在下单那一刻开始的。

本文只讨论交易执行与研究框架，不构成任何投资建议。

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)