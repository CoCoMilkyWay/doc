# 量化做市/HFT 史上第一台被监管完整反向工程的&quot;砸收盘&quot;机器

浦城路尽调员 睿见Alpha 2026-05-03 00:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzU2MzcwODg4OA==&mid=2247487907&idx=1&sn=9196f5c85cb253a179db4497d6c2f8ec&chksm=fd649d7667e4e64c737694c9b9b38ead07f34c94152ca123846a707f14a14ecafc262f3edef3#rd](https://mp.weixin.qq.com/s?__biz=MzU2MzcwODg4OA==&mid=2247487907&idx=1&sn=9196f5c85cb253a179db4497d6c2f8ec&chksm=fd649d7667e4e64c737694c9b9b38ead07f34c94152ca123846a707f14a14ecafc262f3edef3#rd)

## 引言：为什么 Athena 与 Gravy 值得被反复拆解

2014 年 10 月 16 日之前，"砸收盘"（marking the close，SEC 处罚令统一使用此措辞，业内口语也称 banging the close）被视为一种经典的人工市场操纵手段。SEC 曾在 2002 年对 Piper Jaffray 处以 10 万美元罚款，原由仅是一名员工帮一个客户在**一只**股票上拉抬过收盘价；2003 年对 SLKC 罚款 45 万美元，案由几乎一模一样——一个员工、一个客户、一只股票。司法逻辑非常清晰：尾盘突然挂大单买入，把收盘价钉在人为高位，以此虚增账面价值、欺骗净值计算、骗取管理费，这就是欺诈。

直到 Athena Capital Research 把这件事用算法规模化运作，SEC 才第一次面对一个真正的工程问题：当"砸收盘"不再是人手敲几十笔单，而是一台机器每天对几千只股票同时执行、每天的最后 2 秒占据 NASDAQ 该股票成交量 70% 以上、且连续运行至少六个月，这套行为还能被原有的市场操纵法理所涵盖吗？

SEC 给出的答案是：能，而且必须能。执法总监 Andrew Ceresney 在新闻发布会上措辞严厉："Traders today can certainly use complex algorithms and take advantage of cutting-edge technology, but what happened here was fraud"。更为关键的是，SEC 把这台机器的内部架构、参数调优逻辑、内部聊天证据链，全部以行政命令形式公开披露。这是历史上首次，一台真实运作的 HFT 收盘竞价策略被监管机构以近乎"反向工程报告"的方式完整呈现给整个市场。

因此，任何认真研究日内 Alpha、ETF 收盘做市、closing auction arbitrage、VWAP/TWAP 对手盘策略的研究员，吃透这个案例，都是一次策略边界的重新校准。

## NASDAQ 收盘竞价

NASDAQ 的 Closing Cross（收盘竞价撮合）并非简单的"挂单等成交"，而是一台精密、按时刻表运行的拍卖机器。

**4:00 PM 收盘竞价的重要性常被低估。** NASDAQ 的 Closing Cross 大约承载每日成交量的 10%。当天所有指数基金、ETF、被动产品、目标到期产品、买方 VWAP 算法的尾段、共同基金的赎回单，绝大多数都汇聚在这一刻。收盘价是全天所有价格中最重要的一个，因为它决定基金净值、ETF 的 iNAV、衍生品结算价、基金经理业绩以及无数与指数挂钩的产品。所以 NASDAQ 必须设计一套机制，让这个价格不至于过度偏离合理区间——这就是 Closing Cross。

**3:50 PM 是一切的起点。** 收盘前 10 分钟，NASDAQ 开始向订阅了 NOII 数据的市场参与者推送 Net Order Imbalance Indicator（失衡指标，简称 NOII）。这条消息实时展示：4 点收盘拍卖中所有 On-Close 单（MOC 市价收盘单、LOC 限价收盘单、IO 失衡单）的买卖差在哪一侧、规模多大、当前的"远价"（Far Price，假设此刻只用 On-Close 单撮合的清算价）和"近价"（Near Price，假设此刻把 On-Close 单与连续盘合并撮合的清算价）是多少。

这里要注意一个版本的时点差异：在 2009 年 Athena 涉案时段，NOII 从 3:50:00 起每 5 秒推送一条，直到 3:59:55 的最后一条（SEC 处罚令第 19 段原文）。这一频率在 2018 年之后被 NASDAQ 改为 3:50–3:55 每 5 秒、3:55–4:00 每 1 秒。本文后续讨论的所有时序均以 2009 年版本为准。

**Imbalance-Only Order（IO 单）是关键工具。** 这是一种特殊的限价单，仅在收盘竞价存在失衡时才被执行，且只填补失衡那一侧。它解决了"我愿意提供流动性，但不想反向被吃"的痛点。3:50:00 之后，IO 单就只能增加股数或将限价改得更激进，不能撤销或反向修改——也就是说，3:50 一过，挂出去的 IO 单方向即被锁定。这条规则后来被 Athena 反向利用，成为整套机器最关键的不对称优势之一。

**Closing Cross 的成交价如何确定？** 简单说，NASDAQ 会找到一个能让最大数量的 On-Close 单成交、且与 4:00 之前连续盘最后一笔成交价"不远"的价格。"不远"二字是核心所在。这意味着，如果你能影响连续盘最后那两秒的成交价，你就能影响 Closing Cross 选定的最终收盘价。Athena 看穿的就是这条逻辑链：连续盘尾段价格 → 收盘价的硬约束。

至此，整个舞台搭好。NASDAQ 是导演，NOII 是台词本，IO 单是道具。Athena 要做的，就是写一台机器，在每天最后 10 分钟把这个剧本演到自己想要的结局。

## 四层链路的工程拆解

Athena 的整套收盘策略对外有一个统称叫"Mach"——Manager 2 在 2007 年底入职后引入这一类策略，公司内部统称为 Mach 策略族。Mach 不是单一算法，而是一套四层链路。SEC 在处罚令里将这四层每一层的功能都点了名，这是所有公开 HFT 案件中最完整的策略架构披露，工程价值极高。此外，系统还配有"Protection Orders"防止价格越过 far price 触发反向风险。

### 第一层：Collars——抢占时间优先权

NASDAQ 的 Closing Cross 撮合时，IO 单按时间优先成交。谁先把单挂进订单簿，谁就先拿到失衡那一侧的份额。Athena 用 Collars 这一层算法解决这个问题：在 3:50:00.000（第一条 NOII 发出之前的几毫秒到几十毫秒）就把 IO 单挂进去。也就是说，Collars 不是基于 NOII 信息行动的，而是预判——它对哪些股票今天会有失衡有自己的预测模型，提前布单。

这一层的成果在 SEC 文件里有一个非常过硬的数字：Athena 的 IO 单整体填充率达到 98% 以上——"Athena's imbalance-on-close orders being at least partially filled more than 98 percent of the time"。在一个有 Citadel Securities、Knight、Getco、Susquehanna、Morgan Stanley 等机构参与的高度竞争市场里，98% 的 IO 单填充率不是运气，而是时间优先权、失衡预判、高速接入三件事同时做对的工程结果。Collars 让 Athena 的 Closing Cross 端口成交几乎板上钉钉，这把后面三层的策略风险压缩到了一个量级。

这件事的重要性怎么强调都不过分。因为 Collars 提供了"100% 成交确定性"，后面 Gravy 才能放心地砸单——你不必担心砸完之后没人接，因为接的就是你自己的 IO 单。Manager 1 在邮件里把这个逻辑说得直白到几乎像在写技术文档："We can have some aggressive Gravy if we know we have a 100% chan\[c\]e of getting the fill"。译成做市语言就是："既然我对冲腿确定性是 100%，我那条做单腿可以放心地把价格推到任何我需要的位置。"这就是为什么 Collars 必须在 Gravy 之前讲——它是整套链路的风控前置条件。

### 第二层：Meat——失衡信号的瞬时反应

第一条 NOII 在 3:50:00 发出。绝大多数对手方还在解析消息、跑模型、决定要不要参与的时候，Athena 已经开始第二层动作：Meat。

Meat 的工作是，在收到第一条 NOII 之后立刻在连续盘上累积 IO 单的反向头寸。例如 NOII 显示某只股票收盘买盘失衡 10 万股，Athena 已通过 Collars 挂了一张 IO 卖单接这 10 万股，Meat 现在要做的是在连续盘上买回这 10 万股——目的是 4:00 收盘时净头寸归零，SEC 原文叫 being "flat" by the close。

为什么要急于在第一条 NOII 之后就动手？因为这是 Athena 信息优势最大的一刻：3:50:00 这一帧，你比 99% 的人类交易员更早知道了 NASDAQ 的失衡方向，而且你的延迟比大多数 algo desk 更低——对手盘流动性还没被定价进来。Manager 2 在 2009 年初的一封内部邮件里把这个节奏写成了一个近乎审美的描述："We have a desired accumulation pattern which includes grabbing stock at the beginning, a period of 'average price' accumulation, and a crescendo at the end"。开头抓一把，中段平均价吸筹，结尾一个 crescendo（音乐术语，意为渐强的高潮）——这是 Manager 2 在告诉团队，这是一首三段式的曲子。

### 第三层：Accumulators——3:50 至 3:59:58 的低调吸筹

中段是最考验工程功力的部分。从 3:50 到 3:59:58 这 9 分 58 秒，Athena 要把剩余头寸缓慢吸完。这一层叫 Accumulators——SEC 原文："It called this process 'accumulation,' and the algorithms that accumulated these positions were called 'accumulators'"。

Accumulators 的核心约束是"够，但不能太过"。需要够多——不能在 3:59:58 还有大头寸没吸完，否则 Gravy 来不及做尾段冲刺；需要不太过——不能在中段就把价格推得太明显，否则会引起监管关注、对手方察觉、其他 HFT 跟进。

SEC 文件直接点出了这一两难权衡："Athena, however, did not want to push the price of the stocks it traded too much because it created certain trading risks, but also because Athena was concerned about scrutiny from regulators as result of its last second trading"。这一双向约束是 Athena 把整台机器调试得最精细的一层，本质上是一个控制问题：在被监管察觉的边界曲线与不能完成累积的边界曲线之间，找到那条最优路径。

而且 Accumulators 不仅仅是"匀速吸"，它还有节奏感。SEC 处罚令对涉案期间的统计有两组数字，需要分清：第 9 段在描述 2009 年 4 月一个具体配置时说"Athena traded nearly 60% of its accumulation in the final 2 seconds"；第 32 段给出涉案期间的平均值则是 nearly 56%——也就是说，平均下来，前 9 分 58 秒只完成约 44%，剩下约 56% 全部留给了第四层 Gravy，峰值情形下 Gravy 比例可达 60%。这是有意为之的留白：前段控制风险，尾段集中输出影响。

### 第四层：Gravy——最后 2 秒的"crescendo"

整套机器的核心在最后两秒。Gravy 的工作很直接：用集中的、激进的连续盘下单，把这只股票在 4:00:00.000 之前的最后一笔成交价（Last Best Price，LBP），推到对 Athena 自己的 IO 单最有利的方向。

工程上，Gravy 的下单不是"把单都堆进 4:00:00.000"——那样会被风控和交易所立刻打回。它是在最后 2 秒内分多个精确时点投放，每个时点放一笔不会触发熔断或单一时点异常监控的限价单，但所有这些时点合在一起，在该股票的最后 2 秒成交量里占据压倒性份额。SEC 给出的硬数字是：Athena 在最后 2 秒的成交量平均占其交易股票当时 NASDAQ 全市场该股票成交量的 70% 以上——"Athena's trades made up over 70 percent of the total NASDAQ trading volume of the affected stocks in the seconds before the close of almost every trading day"，涉案期间平均值则为 73%（处罚令第 33 段）。

最具代表性的案例之一是 2009 年 11 月 25 日的 EBAY：Athena 在最后约 1.6 秒（从 3:59:58.355 到 3:59:59.950）以 6 笔限价买单累计买入 11.2 万股（占该 2 秒市场总成交量的约 71%），把 NBO（National Best Offer，全市场最优卖价）从 Gravy 启动前的 23.58 美元一路推至 23.59、23.60，最终 Closing Cross 以 23.61 美元成交——比 Gravy 启动前的 NBO 高出 13 个基点。这 13 个基点就是 Gravy 当天给这只股票"加上去"的价格冲击。

对 NASDAQ 来说，Gravy 投放的最后这几笔成交，就是 Closing Cross 用来锚定"不远的连续盘价格"的那几笔。一只股票在最后 2 秒被推高几个基点，Closing Cross 就大概率会把收盘价定在那个被推高的水平附近。Athena 的 IO 卖单（假设是卖单）在那个被推高的价格上成交——第二层、第三层、第四层吸进来的连续盘头寸，在第四层带动收盘价上升后，通过第一层挂的 IO 单以"被人为推高的价格"卖给 Closing Cross——四层完成闭环。盈亏在单只股票上并不多：SEC 引用的一封邮件里 PM Gravy 一天总收益 5,300 美元、33 只标的、最大单股变动是 NTRS 的 12 美分。但当你每天对成千只股票做这件事，每只股票都稳定贡献几个基点的预期值，累加起来就是 SEC 所暗示的"tens of millions"级别的年化利润。

如果用一句话概括 Mach 这套四层结构：Collars 锁定确定性，Meat 利用首条信号，Accumulators 控制风险，Gravy 输出影响——四层各司其职，缺一不可。这是一台经过工程化打磨的策略产品，不是几个交易员临时拍脑袋做出来的。

## 为什么 4,000 万美金能撬动 70% 的市场份额

这是整个案件里最反直觉、也最值得量化研究员深思的一点。Athena 在被指控期间运营资金只有约 4,000 万美元——SEC 处罚令第 12 段明确："the assets under management of the fund trading these strategies were approximately $40 million"。这个数字非常小，今天任何一家百亿规模的中国量化私募随便一个产品的资金体量都远不止于此。可就是这 4,000 万，在 NASDAQ 数千只股票的最后 2 秒里占据了 70% 以上的成交份额。

这一反差有三个微观结构成因：

**第一，流动性在最后 2 秒断崖式下降。** 白天连续盘里，任何一只大盘股的 BBO（Best Bid and Offer，最优买卖价）上有几万到几十万股的盘口深度。但在 3:59:58 之后，大量做市商已经开始关闭报价、调仓、做风控释放——他们的逻辑很简单：临近收盘几秒钟内吃单，如果对手是做收盘竞价的人，自己很可能成为流动性提供者中那个被反向择时的"傻钱"。结果就是连续盘的有效深度急剧萎缩。当订单簿的有效深度只有平时的十分之一，你只需要十分之一的资金就能吃掉同样比例的份额。

**第二，Athena 的资金是"循环复用"的。** Mach 是日内归零策略，4:00 收盘时净头寸为 0。这意味着 4,000 万的运营资金不是被锁在 4,000 万股头寸里，而是在 10 分钟内被循环投放、撤回、再投放。如果一只股票的累积量是 100 万美金，Gravy 用其中 60 万在最后 2 秒投放出去，与此同时另外几十只股票的资金也在被同样调度。整台机器在这 10 分钟里产生的有效订单流名义量，远远超过 4,000 万。

**第三，Athena 的 Closing Cross 端是确定性的。** Collars 把 IO 单填充率做到了 98%，这让 Athena 知道自己在每只股票上承担的风险敞口最大不会超过 IO 单的预期成交量——有上界的、可建模的、可对冲的。当你的风险敞口有硬上界时，你可以用更激进的杠杆做策略，因为下行已被先验封死。Athena 把这个逻辑工程化到了极致。

三件事合在一起，解释了为什么"小资金 + 高速接入 + 微观结构信息优势"的组合，可以在一个看起来高度饱和的市场里挖出一个别人意识不到、但收益极其稳定的 alpha 池。对今天的中国量化研究员而言，这是一个比任何 ML 模型都更值得思考的现象：在最拥挤的市场里，只要你能找到一个微观结构的褶皱，资金量从来不是壁垒——壁垒是那个褶皱的发现成本和保密成本。

## 一个交易日的全帧回放

把抽象架构落到逐帧的实际运行，以下是基于 SEC 文件描述还原的、典型场景下 Mach 在一只单独股票上的执行过程。

-   3:49:55.xxx：Collars 的预测模型已在前一天收盘后跑完。今天这只股票被识别为高失衡概率标的，买盘失衡概率 75%。Collars 在 3:49:59.x 把一张 IO 卖单的报文发往 NASDAQ，在系统进入 3:50 拍卖前序模式之前抢占订单簿。这笔单不会被任何人看到，因为 IO 单在 NOII 推送之前对市场不可见。
    
-   3:50:00.000：NASDAQ 推出第一条 NOII，买盘失衡 12 万股。Athena 的 IO 单已挂在簿前——Collars 完成它的工作。同时，3:50:00 一过，IO 单进入"只能加码、不能反向修改或撤销"的锁定状态，Athena 的方向被自我锁死，但这恰好是它要的状态。
    
-   3:50:00.0xx：Athena 的低延迟解码器解析 NOII。Meat 算法判断这条信息确认了 Collars 的预测，启动连续盘买入腿，目标在 4:00 之前累积大约 12 万股的连续盘多头头寸。
    
-   3:50:00.5xx → 3:55:00.xxx：Meat 的"开头抓一把"完成，Accumulators 接管。这 5 分钟内，Accumulators 以小单连续买入，每 5 秒接收一次更新的 NOII 来确认失衡仍在，并据此调整剩余累积速度。
    
-   3:55:00 → 3:59:58.xxx：Accumulators 继续以平均价节奏吸筹，完成约 44% 的累积量（以涉案期间平均值反推）。其间监控 NOII 的方向是否有反转；如果反转，启动止损/反向逻辑。同时 Protection Orders 机制也在工作，防止价格因意外越过 far price 而触发反向风险。
    
-   3:59:58.000：Gravy 启动。剩余约 56% 的累积量在接下来 2 秒内集中投放（峰值情形下可达 60%）。Gravy 将这部分拆成多笔限价单，在 2 秒内的若干个精确时点放出。SEC 在 EBAY 案例中披露的实际时点是 3:59:58.355、58.503、59.403、59.705、59.870、59.950 这六个，每笔单的规模经过校准——足以推动连续盘价格上行几个基点，但不会触发交易所的单一时点价格异常监控。
    
-   3:59:59.998：最后一笔 Gravy 单成交。这只股票当前 LBP 被推高几个到十几个基点（EBAY 当天是 13 bps）。
    
-   4:00:00.000：Closing Cross 算法启动。它需要在所有 On-Close 订单簿中找到一个能让最大数量订单成交、且距离 LBP 不远的价格。LBP 已被 Gravy 推到 Athena 想要的位置。Closing Cross 选定收盘价等于或略低于被推高后的 LBP。
    
-   4:00:00.001：Athena 的 IO 卖单以这个被推高后的价格成交。连续盘端的 12 万股多头头寸加 IO 端的 12 万股空头头寸，净头寸归零。
    

P&L = 12 万股 × 几个基点的价差。看起来不多。但乘以每天上千只股票，乘以 6 个月，就是另一番景象了。SEC 在处罚令里特别强调："Athena was acutely aware of the price impact of some its strategies, particularly its last second trading Gravy strategies. Athena used these strategies and its configurations to give its accumulation an extra push, to help generate profits"。这台机器的每一帧都是设计出来的，不是涌现的副作用。

## 压垮辩护的不是策略本身，而是邮件

如果只看策略本身，Athena 尚有辩护余地——"我们提供了 IO 单流动性、我们对冲了 NOII 失衡、我们承担了真实的市场风险、我们的最后 2 秒下单是对失衡信号的真实反应"。这些话术 HFT 行业用了很多年，在很多类似的灰色地带成功保护了从业者。

但 Athena 自己把辩护空间堵死了。SEC 处罚令引用的内部沟通，几乎是一份"自证主观恶意"的清单。它们是这个案子能在很短时间内以和解收尾、SEC 不需要拿到法庭上对抗的核心原因。

**第一份证据是 2008 年 8 月的电子表格。** Manager 2 当时不在办公室，一名分析师把当天 Gravy 的成绩发给他："PM Gravy made 5.3k, trading on 33 symbols, biggest dollar move NTRS .06 (.41%)"。注意这条邮件的报告口径——不是"我们今天接了多少 IO 单"，不是"我们的对冲腿成本是多少"，而是"我们在每只股票上推动了几美分"。报告口径决定了主观目的。Manager 2 的回复同样带着讽刺性的轻松："Looks like we have some Mach chips….going to Vegas tonight…"。同一时期，公司内部还存在一份名为"gravy \[average\] move by symbol"的电子表格——文件名本身就是对策略目的的自我披露。

**第二份证据是 2009 年 4 月的"够大"邮件。** Manager 1 在分析当天的 Gravy 之后发现累积只完成了 25%，价格没动。他把分析发给 Manager 2 和 CTO，指示："make sure we always do our gravy with enough size"。这句话的法律破坏力在于，它直接把"够大"和"价格影响"画了等号。如果 Gravy 真的只是"对冲 IO 单的连续盘下单"，accumulation 完成 25% 不是好消息或坏消息，只是头寸没吸完；但 Manager 1 把它当作问题，说明在内部决策语言里，price impact 才是绩效指标。

**第三份证据是"金鹅"邮件。** NASDAQ 在某次到期/再平衡日发出了一份名为"Scrutiny on Expiration and Rebalance Days"的自动监管警示，提到"Suspicious orders or quotes that are potentially intended to manipulate the opening or closing price will be reported immediately to FINRA"。CTO 看到后，把这条警示转发给 Manager 1 和 Manager 2，加了一句话："Let's make sure we don't kill the golden goose"。"金鹅"——这是 CTO 在监管警示发到面前的当下，以一种 to be feared 而非 to be debated 的口吻，把 Gravy 命名为应当被保护起来的收入来源。这一句话在 SEC 笔下足以将"我们不知道这是操纵"的辩护彻底抹去。

**第四份证据是私人邮箱的转移。** 2009 年初，Athena 招聘了一名负责对外推广的 Officer。这位 Officer 在了解到 Gravy 的运行方式之后，警告 CTO 公司在"punching the stock"（砸股票）。SEC 在文件中接着披露了一个更致命的细节——CTO 转告 Manager 2 时提到，Officer 还建议他用某些关键词去研究 Athena 的交易策略时"at home, not here"（在家里搜，不要在公司搜）。自这次警告之后，CTO 与 Manager 2 转用私人邮箱继续讨论 Gravy 相关问题。在任何一桩美国证券执法案件里，"用私人邮箱"加上"at home, not here"是分量极重的两条事实组合——它意味着行为人主观上完全意识到自己讨论的内容不应该留在公司服务器上，且这种意识被文字记录了下来。这一动作把"是否知道在违规"这个问题从灰色地带推到了清晰一侧。

**第五份证据是 Athena 从未就 Gravy 寻求法律意见。** SEC 文件第 42 段明确指出这一点。在一家 HFT 公司里，任何一个新的、在监管灰区操作的策略，合规成本最低的动作就是请外部律师出一份 No-Action 备忘录或合规意见。Athena 没有做。这一行为缺失在监管视角下，被解读为"故意不询问，因为知道会得到不利答复"。

把这五条放在一起，任何辩护方律师都会建议直接和解而不是上庭——因为上庭的话陪审团会在 30 秒内做出判决。这也是为什么这个案子最终以 100 万美元罚款加终止令（cease-and-desist）加公开谴责（censure）的相对快速形态收尾，Athena 既不承认也不否认指控（neither admitted nor denied the charges），由 Holland & Knight 的合伙人 Mitchell Herr 与 Aaron Goldberg 代理。

对量化研究员而言，这一段最值得记下的不是任何一句具体的引语，而是一个工程教训：你的 IM、邮件、文件命名，会成为你策略法律性质的最强证据。如果你内部把一个变量命名为 `pump_size`，你这个策略今后被监管 review 时基本上没有任何辩护空间——哪怕这个 `pump_size` 在数学意义上完全是合规的对冲量。Athena 之所以输得这么彻底，有一半原因是工程师文化——他们以日常工程师的随意命名习惯，给一个监管敏感的策略起了 Gravy、Meat、Collars、pump\_size 这一系列在内部沟通里足够"形象"的名字。当一个策略的命名让外行一眼就读懂它在做什么，而它做的事情又恰好处于灰区，你的法律暴露面被自己放大了一个数量级。这是任何一家有志于做 closing auction 策略的中国量化机构都应当从 Athena 案中学到的第一条教训——比策略本身的教训更直接、更便宜、也更经常被忽视。公司内部还使用过"owning the game"、"dominating the auction"等表述，这些全数成为 SEC 的证据。

## Gravy 落幕之后：收盘竞价生态被怎样重写

2014 年 10 月之后，一系列变化直接定义了今天 closing auction 策略的可行边界。

**SEC 的执法基调。** Andrew Ceresney 在 Athena 案的发布会上明确表示 SEC 还有"a number of other investigations into computer-driven trading firms for manipulative activity"。这是一个明显的威慑信号。时任主席 Mary Jo White 在 2014 年 6 月的演讲中已经预告了"反扰乱性交易规则"的立法方向，Athena 案是这一方向的执行落点。该案被 SEC 官方定性为"首例针对高频交易公司的市场操纵执法行动"（Press Release 2014-229）。

**法律覆盖的扩展。** 2015 年 11 月，Coscia 案在芝加哥联邦法院定罪，是 2010 年 Dodd-Frank 反 spoofing 条款下首例刑事定罪；2016 年 11 月 Sarao 在与 Flash Crash 相关的指控下达成认罪并与 CFTC 民事和解（2020 年 1 月最终判处居家监禁）；2016 年 12 月 Igor Oystacher 与 3Red Trading 被 CFTC 罚款 250 万美元并签署同意令。这一系列案件，加上 CFTC 在期货市场的多起 spoofing 处罚，持续将"算法策略等于操纵"这条线在判例上做实。Athena 案确立了一个原则：策略的复杂性、自动化程度、合理性叙事，均不能成为减免市场操纵指控的理由。

**NASDAQ 自身的进化。** Closing Cross 的某些参数和监控规则在 2014 年之后逐步收紧。NASDAQ 增加了对最后 2 秒成交量集中度的实时监测，改进了对 IO 单异常分布的预警；FINRA 也在经纪商监管层面加入了对 closing auction 行为的常规扫描。NOII 的推送频率也在 2018 年之后从全程每 5 秒升级为 3:55 后每 1 秒，使市场对失衡的反应窗口被压缩。今天再沿用 Gravy 那套原始打法，被识别的概率可能在数小时内，而非数年内。

**Athena 自身的存活。** SEC 罚款支付完毕，Athena 未受 SEC IB 类禁业令，公司继续运营至今。它在当时的公开声明中声称"Athena believes that its trading activity helped satisfy market demand for liquidity ... Athena stopped running the trading strategies in question several years ago, primarily due to declining market demand for liquidity"。这种将操纵行为重塑为"提供流动性"的话术，是 HFT 公司在监管面前的标准姿态。2014 年之后，Athena 的策略很可能向更安全的微观结构方向调整——可能是高频做市、跨市场套利、ETF/ETP 报价等更"白"的领域。但官方层面没有任何披露，其当前策略组合在公开信息中不可见。

**对买方的影响。** Athena 案直接让买方的 target-the-close、VWAP-tail、MOC algo 重新审视了他们在最后 2 秒的执行成本。很多大型买方此前认为 Closing Cross 是"公平价格"，在 Athena 案后开始用交易成本分析（TCA）反向估算自己被"砸收盘"剥削的成本。这是 Themis Trading 的 Sal Arnuk 在评论 Athena 案时反复强调的一个点。Arnuk 当时对 CNBC 直言"This is very disgusting. \[I'm\] very shocked that this was a $1 million fine"——100 万美元罚款相对于策略全期利润几乎是九牛一毛，行业舆论普遍认为处罚偏轻。

**相关数据也反映了 Gravy 策略的扩张速度。** Athena 交易的股票数量从 2008 年末的每月 1,000 至 3,000 个，到 2009 年 11 月单月已达 12,844 个——相当于将覆盖面在一年内拉高了 4 至 12 倍。这一扩张速度在小资金 HFT 策略里非常罕见，也佐证了"Closing Cross 微观结构褶皱"在当时的容量被严重低估。

## Athena Capital Research 真实画像：低调的 20 人精品店

跳出 SEC 案件的光环，Athena Capital Research 的真实体量与一线 HFT 巨头相去甚远。下面分四个维度看。

**规模与可见度。** LinkedIn 公司页自报员工区间 11 至 50 人，第三方数据如 Tracxn（2024 年 7 月）显示为 19 人，RocketReach 与 LeadIQ 的测算在 13 至 16 人之间。LinkedIn 关注者仅 1,328（对比 Hudson River Trading、Jane Street 的数十万），这一数据本身就是该公司低调到何种程度的最直观佐证。两位创始人（"two former colleagues from a large high-frequency trading firm"，SEC 处罚令第 13 段）的姓名从未在 SEC 文件中披露，也未在任何官方渠道公开。

**硬件与工程文化。** GitHub 组织账号公开 4 个仓库，以 C++ 与 JavaScript 为主；技术栈抓取结果包括 C、C++、Python、MATLAB、MySQL、Linux——这是一套相当传统的 HFT 工程语言组合，未发现任何 FPGA、ASIC、自建微波链路或激光链路的公开证据。鉴于其规模与可推测的资金体量（SEC 案件期间管理规模约 4,000 万美元，业内合理推测当前在 1 亿至 5 亿美元区间），它几乎不可能负担得起顶级 HFT 的硬件军备投入，更可能是租用 NJ Carteret（NASDAQ 数据中心）、Mahwah（NYSE 数据中心）、香港将军澳（HKEX 数据中心）等地的 colocation，微波网络则可能采购 McKay Brothers、Anova 等第三方服务。

**办公室与亚太业务。** 纽约总部位于 14 Penn Plaza Suite 1300（亦记录为 225 W 34th St Ste 1300，两个地址实际为同一座楼）；亚太据点位于香港中环皇后大道中 100 号。香港办公室成立于 2010 年（早于 SEC 处罚令半年），是 Athena 在 2010 年代向亚洲扩张的明确信号。公司没有新加坡办公室。香港 SFC 牌照状况需在持牌人公开名册逐项核查，本次调研未能直接确认。亚洲业务方面，员工 Jasmine Qi 的 LinkedIn 自述提及增长中国境内 AUM 50%，这是该公司在中国境内有过实际交易业务的唯一公开线索，但具体的 QFII/RQFII 资格、合作通道、法律实体均未在公开信息中披露。

**团队与招聘。** 唯一通过 LinkedIn 可被公开锁定的非高管员工是 Beck Kong（香港中文大学背景，任 Senior Trading Support，香港办公室）。Glassdoor 11 份匿名薪酬数据显示 NYC 软件工程师平均 base 约 13 万美元，显著低于 HRT、Citadel、Jane Street 软件工程师 17.5 至 22.5 万美元的 base 水平，综合评分 2.8/5（行业均值 3.7）。Glassdoor 一条典型负评直白写道"low base, no raise, no bonus, all senior people left, all current employee are planning to leave, poor management"，而正评则集中在"good work life balance, can get involved in projects with quants and researchers, free snacks/drinks/fresh fruit"。这是一个典型的"小而清的工程师友好型 boutique"，而非 PM Pod 制的高强度赌场。招聘上有几个独特特征：面试题强烈偏向 C++ 系统底层（继承、指针、内存、vtable、多线程），而非 LeetCode 算法竞赛风格；未发现公司在 LeetCode、HackerRank、Kaggle、CodeForces 任何平台开设官方 channel 或赞助记录；Glassdoor 多条反馈来自"Fall Career Fair"校招，显示其依赖传统校招而非高调宣传；未发现任何赞助 NeurIPS、ICML、SIAM、AFA、QuantCon 等会议的记录；未发现任何以 Athena Capital Research 署名的 arXiv 或 SSRN 学术论文；公司也没有形成可识别的"Athena 系" alumni 网络。