# 歪果仁的量化套餐

岛主 量化君也 2026-07-14 07:07 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487370&idx=1&sn=a7cdeb74b332f75d1611742754707ca8&chksm=c34fd441f4e39198c775a06fb3f27fa9af39f30f576397b136f5f3990e12e260690dd0576aa3#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487370&idx=1&sn=a7cdeb74b332f75d1611742754707ca8&chksm=c34fd441f4e39198c775a06fb3f27fa9af39f30f576397b136f5f3990e12e260690dd0576aa3#rd)

前几天，我在墙外瞎逛的时候，在KDnuggets博客上刷到一篇帖子，标题为“10 GitHub Repositories to Master Quant Trading”，内容大概是说推荐了10个GitHub库，帮助大伙儿来入坑量化交易。

  

原贴链接是：  

https://www.kdnuggets.com/10-github-repositories-to-master-quant-trading

  

因此对于这篇文章我也不希望单纯就是翻译原文，或弄成成“10个GitHub量化项目推荐”这类东西。因为如果咱只推个项目的话，对小伙伴帮助不大。量化萌新真正要的不是又多收藏几个链接，而是知道这些项目分别代表着什么能力，自己应该先学什么后学什么，哪些东西适合入门，哪些东西适合进阶，哪些东西看起来很酷但暂时不应该投入过多时间，哪些东西虽然枯燥却决定了一个量化系统能不能从研究走向实盘。

  

如果对10个这样的项目重排序，在我看来他们大概能够分为4个层次。

  

第一层：研究能力，解决的是怎么提出、验证、扩展 一个交易的想法；

  

第二层：投资能力，解决的是如何去把单个策略和单个信号转化为能够配置资金的组合；

  

第三层：工程能力，实现如何将策略从Notebook到System、从Backtesting到Trading；

  

第四层次：成长能力，是如何不断学习，不断的积聚，不断的接近Quant神的水平。

  

这样唠起来比单纯简单按github的顺序更有意义，因为真正的量化交易本来就不是一个指标一段代码还是一个模型，而是研究、投资、工程和成长能力长期加起来的结果。

  

一、研究能力：从想法到Alpha

量化萌新最容易被策略所吸引，这很正常，因为策略是整个量化交易里最直观直白的部分。但是真正的策略研究能力，从来都不在于看到一条策略就相信它是对的，而是把一个交易想法拆解成清晰的规则，用数据去验证她，怀疑她，改造她，并最终判断她是市场结构中的有效信息还是某段历史行情中偶然幻影。

  

1.Python Quant Trading Strategies

https://github.com/je-suis-tm/quant-trading

  

Python Quant Trading Strategies是一个很饱满的量化策略案例库，其中包括CTA，蒙特卡洛模拟，配对交易，模式识别，SAR，MACD等多个策略。这个项目对于萌新而言最大的用处是，不是说随便挑个策略直接可以拿来实盘，而在于将“交易的想法怎么写成代码”给说清楚。

  

很多量化萌新一开始被卡住的不是不能写出复杂的模型，而是搞不清楚什么样子才是一个有逻辑有意义的策略。数据怎样读？指标怎样的算？信号是怎样生成的？仓位怎样变？收益怎样统计？图表怎样画出来？最后怎么样判断这个策略有没有意义？对萌新而言这些项目的最大意义在于锻炼手感，告诉你「策略不单是一句话，而是一组可以复用的规则」。

  

它非常适合萌新入门，但是阅读时不要单纯停留在“这里有这么多的策略代码”，而是将其当做“策略研究基本功的打靶场”。

  

2.Options Trading Strategies in Python

https://github.com/PyPatel/Options-Trading-Strategies-in-Python

  

Options Trading Strategies in Python这个库主要是为期权交易学习者进行设计的，用技术指标和量化方法做期权的交易。

  

期权策略对量化萌新来讲一般是会被忽略掉的，这里只是补充说明一下，需者自取。因为很多人都在一开始学习量化的时候，自然而然地就选择了股票/CTA/择时/多因子选股那些，因为这些对于普通投资者来说，是最容易接触到的，更符合他们对于市场的直觉：涨了买，跌了卖。强者恒强，弱者反转。

  

但期权不一样，核心不只是看方向，还有波动率，时间价值，尾部风险，非线性收益结构。做股票类策略，更多关注的是价格变化，你做期权策略就要理解同样的一个行情，隐含波动率、行权价和期限的不同都可能会带来截然不同的风险收益。

  

它呢，适合帮萌新打开衍生品研究的大门，并更像是一个期权定价和量化策略的代码入门手册，教会萌新BS模型、VIX恐慌指数等概念怎样跟代码勾搭上的。

  

3.TradeMaster

https://github.com/TradeMaster-NTU/TradeMaster

  

TradeMaster的定位更加前沿，它是一个基于强化学习的量化交易平台，它更多代表的是AI的量化研究能力。

  

以前的量化交易使用机器学习，更多的时候都是在监督学习的范畴里，比方说XGBoost，随机森林，人工神经网络用于预测收益、分类涨跌、股票相对排序等。但是强化学习的想法不同：不只预测下一步的收益，而是在一个市场中不断作出决定、通过奖励函数学会如何交易。

  

强化学习会把交易过程当做是序列决策问题来处理，并且让模型考虑到状态、动作、奖励、路径以及长期的目标。但是需要注意的是，金融市场不是围棋棋盘，数据不稳定，噪音大，有真实的交易成本，是真金白银，不是单纯的理论假设。

  

二、投资能力：从单一策略到投资组合

如果说研究能力解决了“有没有Alpha”，那么投资能力就需要解决“这些Alpha应该如何配置。这两件事儿看起来相似，实质相差颇大。

  

许多人将所有的精力投入在策略收益之上，今天研究一个动量策略，明儿个又搞一个均值回归，后天又增加一个机器学习预测收益模型，每一个单独来看都很不错，一旦拼在一起便开始打架了。这个时候，决定最终战果的就不再是单个策略有多能打抗揍，而是组合管理能力有给力。

  

4.Riskfolio-Lib

https://github.com/dcajasn/Riskfolio-Lib

  

Riskfolio-Lib就是这10个github库里最能代表投资能力的仓库，它是投资组合优化工具，因为它不是教你再找一个信号，也不是教你再测一个策略，而是把注意力放到“资产配置、风险预算、约束优化、组合构建”这些方面。

  

为啥这项能力重要呢？因为真正资金管理从来都不是单个信号的胜利，而是组合层面的胜利，兵熊熊一个，将熊熊一窝。一个信号收益亮眼但回撤太大，未必有价值；一个信号单独来看回报平平，但是与现有组合的相关性很低，反而会非常有价值；一个策略夏普率高但是容量很小，有可能只能作为研究样本；一个策略夏普率中等但容量大、换手少、能跟组合搭伙，反而可以上仓位配置。

  

这些对于一个机构来说是非常重要的，因为他们管理的不是一条收益曲线，而是众多资金、一系列产品、不同风险预算和客户的风险偏好。

  

所以投资能力这层的核心是，不教萌新如何尽快掌握所有的优化模型，而让他尽早建立起一个意识，量化交易不是五花八门策略的堆砌，而是将不同来源和周期、不同风险暴露和容量特征的策略收益，组成一个可承受、可解释、可持续的投资组合。

  

![](assets/001.png)

  

三、工程能力：从Notebook到System

研究代码能写到Notebook里去，可以临时手动改几个参数，可以跑完之后再看生成的图片，但是生产系统不行，它要面对实时行情，交易接口，订单回报，账户状态，异常处理，断线重连，日志监控，风控拦截，任务调度，以及一大堆平时没人想看，出事时却能救命的细节。

  

5.StockSharp

https://github.com/StockSharp/StockSharp

  

StockSharp是一个可以进行交易机器人开发的量化交易和算法交易的开源平台，目前支持股期汇币等市场。

  

它与以上所有策略示例库的区别是，它不是告诉你“这个策略该如何编写”，而是告诉你要看到“一般的量化交易系统应该长成啥样子”。真实交易系统不仅是策略，而且要把策略放入一个稳定的接收到行情，产生信号，发出订单，处理回报，记录状态，控制风险的系统中。

  

你写的on\_bar或者handle\_data函数并不表示你理解了交易系统，你设置的回测参数，也不代表你能明白订单的状态机制，你可以画出净值曲线，并不代表你理解了实盘异常。

  

真正进入工程层以后，很多问题都不再是金融问题，而变成了软件工程问题，服务挂掉了怎么办？行情断了怎么办？重复下单怎么办？订单部分成交怎么办？接口限频怎么办？数据库写入失败怎么办？策略状态怎么样恢复？风控规则如何统一管理？

  

6.Howtrader

https://github.com/51bitquant/howtrader

  

Howtrader是一个加密货币量化框架，可以用来开发、回测和实盘。支持集成Tradingview和其他第三方信号，支持通过POST请求实现自动交易和下单。

  

对一个萌新而言，Howtrader的价值不在于带你快速冲进B圈，而在让你明白，实盘不是一个单点动作，而是由一条自动化链路构成的。

  

Tradingview发出信号，webhook发送请求，框架接收信号，策略模块负责判断，交易接口实盘下单，订单模块反馈更新，持仓模块记录变化，整个过程要能自动稳定、可追踪运行。

  

7.QuantMuse

https://github.com/0xemmkty/QuantMuse

  

QuantMuse是一个由多个模块组成的量化交易系统，集AI量化分析，实时数据处理以及风险管理功能于一身。

  

不少个人Quant喜欢使用Notebook做研究，在入门初期完全是可以的，甚至说是很有效率。但如果一个团队一直做量化，只用NoteBook的话，很快就乱成一锅粥了，数据版本不统一，特征计算不能相互复现，策略参数到处散落各处，实验结果无法追踪记录，回测参数口径不一，模型训练和生产脱节。真正的正经量化研究，需要一个平台把各个流程串联起来，这当中包括数据/特征/因子/策略/回测/评估/监控/展示/执行。

  

QuantMuse的价值即在于，它使新手看见了「量化系统，而不仅是交易接口，而是一个由数据至研究、研究至执行、再到监控的完整工作流程。对于个人Quant而言，这样的项目也许不一定能够直接“拿来主义”，但还是很适合用来模块拆解和学习的。

  

四、成长能力：从收藏点赞到无限进步

最后一层，便是成长能力，这层不像是那些个量化策略、资产组合、交易系统那么直观，但它却决定了一个人是不是可以长期进步，量化交易不是学完了就结束了，市场结构会变，交易规则会变，数据源会变，模型范式也会变，唯一的不变就是改变。

  

8.EliteQuant

https://github.com/EliteQuant/EliteQuant

  

EliteQuant是一个琳琅满目的知识体系类资源库，这是一个关于量化交易、交易和组合管理的在线资源列表。

  

这个项目的价值不是给你一段直接可以跑的代码，而是帮助你建立起知识索引，把散布于互联网上的量化干货整合起来。

  

但是，这类资源库有个很大的Bug，就是容易给人一种"收藏=学习"的错觉，看到就是会了，许多小伙伴点开资源库链接，然后又看到一连串链接扑面而来，惊呼自己发现了宝藏，点了star/收藏/转发，然后就没有然后了。

  

实际上用EliteQuant的正确方式不是全选，而应该是哪里不会点哪里，例如你刚开始学习，请先看量化交易平台/基础策略/数据源等部分，资源库的价值是帮助你降低搜索成本，而不是帮你看书，以便你可以投入更多的时间精力到内容的吸收上面去。

  

9.Quant Developers Resources

https://github.com/cybergeekgyan/Quant-Developers-Resources

  

Quant Developers Resources体现了另一种成长能力，工程素质和职业预备，它主要是为了量化开发工程师Quant Developer，量化研究员Quant Researcher，量化交易员Quant Trader，量化分析师Quant Analyst等量化机构核心岗位准备的资源合集。

  

在这当中，你会看到，不同量化岗位需要具备的能力是不同的，不是说都需要会挖因子、做回测、搞机器学习那些，其他的也会包括有C++、Linux、网络工程、数据库、分布式系统、系统设计、高性能计算、并行计算等等。

  

![](assets/002.png)

  

10.Sunday Quant Scientist

https://github.com/quant-science/sunday-quant-scientist

  

Sunday Quant Scientist不是那种传统意义上的代码库，而是一个Newsletter风格的资源库，主要面向量化与算法交易、组合分析和投资研究的从业者， Newsletter你就理解为周报就行了，隔三差五不定期提供新一期的量化干货。

  

量化学习不仅是读书、写代码、跑回测，还包包括持续阅读、持续观察、持续获得新idea。很多优秀的量化idea不一定出自于哪本教材，而可能是来自于长期不断的信息获取，信息源可以是博客/论文/开源代码/会议资料/行业报告等等，这些都构成了Quant们的“外脑”。

  

成长能力这一层，表面上不如策略和系统那般刺激，但它决定了长期的差距，一个真正成熟的Quant，不可能只靠某个github库打天下，也不可能只靠某本书治策略，而是需要不断把新的信息、新的工具、新的研究方法吸纳到自己的体系当中。量化不是一次性学习，而是一种长期训练。

  

写在最后

这10个Github库实质上是一张Quant能力地图，回头看，如果只拿他们当资源合集就没什么太多的价值。收藏只是一个开始，真正的价值是看你能否把那些仓库背后的能力拆解出来，一个一个补上。

  

这10个库放到一块，正好提醒咱，量化交易不是单点技能，而是能力体系。研究能力能让你产生并验证交易想法，投资能力使你能把信号转化成组合，工程能力能使你将研究转化为真正的交易系统，成长能力能使你不断吸收新知识和适应新市场。

  

如果你是一个刚打算入门量化的萌新，建议你在具有一定的编程基础后，可以先把PQTS这个策略案例库根据自己交易领域选择性通读一遍，来建立一丢丢基础的策略语感，接着再看Riskfolio-Lib，理解为何只考虑单策略的收益并不代表最终的投资结果，然后接触StockSharp、Howtrader或QuantMuse，理解交易系统、实盘链路和工程平台，如果你想学AI在量化当中的应用，再看TradeMaster，你想长期做量化，那就跟着EliteQuant、Quant Developers Resources、Sunday Quant Scientist这些资源，持续补数学、金融工程、研究习惯和行业视野吧。

  

量化这条路，最怕的不是起点低，而是永远停留在起点。

  

最后再唠叨一句，在每个库标题的位置我都放了github链接，复制粘贴进浏览器便可以直达，觉得有用的话，别忘了给开源大神一键三连，但考虑到github可能存在被墙的情况，无法访问时，可以在公众号『量化岛』后台回复关键字【量化套餐】，便可以获取到这10个库打包好的完整资料包，下期见~

  

  

![](assets/003.jpg)

  

  

* * *

★

往期回顾

  

★

  

  

\------量化社群------

[量化达摩院](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487092&idx=1&sn=25bac190345f2018e6422fe80f60df7f&scene=21#wechat_redirect)

[量化藏经阁Max](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487087&idx=1&sn=b09a75914ffa58c219ec7a2d833652c0&scene=21#wechat_redirect)

[量化藏经阁2026](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487099&idx=1&sn=f459e43d14a1a11a8e0811c7f9315794&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect)[TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect)[北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect)[F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect)[鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect)[波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect)[RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect)[GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零代码策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[黄金价格预测](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c21ba9dff56c20c92e3a08ee170b20dc411112fa12a8f89f55ae70450000e25614174a7a22bf&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

[十年零回撤](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485946&idx=1&sn=0247059aebc4e851e330dcfef8a71e06&scene=21#wechat_redirect) [红利策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486120&idx=1&sn=b3810b54ef12d899cd8cacdf3f7ea594&scene=21#wechat_redirect)  [数字信号](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486368&idx=1&sn=9a8e7b22717192a59072ef40c5b1ea43&scene=21#wechat_redirect)

\------心得杂谈------

[入门路径](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486125&idx=1&sn=7363ab72138ab4c76e167507c6e66fe7&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)

[打开黑箱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化手册](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486076&idx=1&sn=7265e59cd5b9a9716a83b1a4cfb416b4&scene=21#wechat_redirect)  [量化攻略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486384&idx=1&sn=a1d00fcf058755df0f2b51cda5a2ab5a&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[西蒙斯](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)  [雪球爆仓](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485815&idx=1&sn=6378f7c65c16da331af9598b08d53679&scene=21#wechat_redirect)  [量化交易邪术](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486330&idx=1&sn=10e5309bc821819950e43bf7df0cac21&scene=21#wechat_redirect) 

[量化网站1](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485841&idx=1&sn=e94800a827ce4f38c833dcd144ea1806&scene=21#wechat_redirect)  [量化网站2](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485869&idx=1&sn=951f15090c856e7fcda3b660dccc6b8f&scene=21#wechat_redirect)  [量化狠人](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485924&idx=1&sn=9447f05fbba78524455878c999adabd1&scene=21#wechat_redirect)

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485751&idx=1&sn=c97da5635ce842634d1c2f68397f21c1&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486429&idx=1&sn=5f2101cfde264f0370b99b4f8b8e7ada&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect) [五穷六绝](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c21ba916f56c200088c4aceda6e62511469cff0d18af97fa48b659fc6ac3862d494f02fd38a6&scene=21#wechat_redirect) [一月之殇](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485826&idx=1&sn=cfeb2dd29ef21c48ab2e96b568b42559&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/004.png)

![](assets/005.jpg)