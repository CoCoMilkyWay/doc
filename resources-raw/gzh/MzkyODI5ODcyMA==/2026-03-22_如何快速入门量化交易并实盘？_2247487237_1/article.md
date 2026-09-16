# 如何快速入门量化交易并实盘？

量化君 量化君也 2026-03-22 19:08 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487237&idx=1&sn=5b1d25efaeb236ef8bca69ca4abbb5bc&chksm=c36bc07da530b1dfafc293c75396d39769ea89620fff6f05789914cc37eb0b5362713cbb1367#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487237&idx=1&sn=5b1d25efaeb236ef8bca69ca4abbb5bc&chksm=c36bc07da530b1dfafc293c75396d39769ea89620fff6f05789914cc37eb0b5362713cbb1367#rd)

![](assets/001.png)

  

量化交易就是一种让电脑按照设定好的数学规则自动买卖股票（或其他金融产品）的投资交易方式。

  

量化交易能实现什么功能呢？打个形象易懂的比方，就好像在你的同花顺软件里面住了一个人，此人全年无休地帮你盯盘看盘复盘下单，他执行的所有动作都是你吩咐布置的，例如“从全市场当中筛选PE在30倍以下且净利润增长率在20%以上的市值最小的100支股票，如果股票连续5天上涨，就买入，如果跌了8%，就立刻卖出”。

  

你让他执行的那个选股交易的动作，在量化交易当中就被称为“交易策略”或者是“量化策略”。如果你不知道这个量化策略能不能赚钱，你可以让他把这个策略放到过去10年的历史数据当中，完全按照设定的规则交易，就可以看到收益率、胜率、夏普率、最大回撤等统计指标，能不能赚钱心里就有数了，这在量化当中就叫做“回测”。

  

从上面的描述当中，可以看出量化交易主要有3大优势。

  

（1）验证/发掘投资交易想法。该作用最为重要，它解决的是投资交易当中根本性的问题：买什么卖多少什么时候买卖。

  

现在网上一搜，一大堆投资交易的书籍和课程，这个专家那个大师，龙头战法，潜伏战法，爆破战法，琳琅满目，包罗万象，公说公有理，婆说婆有理，不知到底该相信谁。

  

有了量化交易之后，把这些专家大师们的理论手法写成代码，转化成交易策略，放在历史数据当中跑一遍，可能就被扒得底裤都不剩了，一声叹息后，大骂竖子误我。

  

用量化方法找到/验证一种有效的投资交易方法，就跟现代医学里面找到治疗某种疾病的药物流程一样，讲究的都是“大样本随机双盲对照测试”，这样发现制作出来的药，敢吃，总好过街边摊贩包治百病的“大力丸”。

  

（2）提高研究和交易的效率。现在A股也有5000多支股票了，人的时间精力是有限的，光靠人眼手工来大范围筛选股票进行研究，非眼瞎手残不可，比方说，要在全部A股当中找出符合“MACD顶底背离”形态的股票，光靠自己手动来做，想死的心都有了，如果量化编程实现，感觉自己还可以抢救一下，这就是提高研究效率。

  

提高交易效率指的是，用程序化的方法实盘交易和盯盘，解放自己大部分时间和精力。举个极端的例子，需要你手动买入100支股票，然后要实时盯盘，下跌幅度超过5%就要止损出场(考虑价格笼子)，想想这对你意味着什么？而这是可以用量化轻松搞定的。

  

（3）保持纪律性。机器是没有情感的，你不敢买时它敢买，你舍不得卖时它敢卖。这应该对做趋势型策略的小伙伴感触会比较深，一般的趋势型策略都是以“低胜率，高赔率”著称，交易几次才能盈利一次，但那一次的利润可以覆盖前几次亏损，并且还有盈余，保证总体预期盈利，“别有心思”的小伙伴就想了，自己过滤一些进场时点会更好，但往往很容易就错过大涨的机会，之前的亏损更加无法弥补。机器没有人的七情六欲，是一个没有感情的执行机器，能帮咱保持高度的统一性和纪律性。

  

那入门量化交易要学习什么知识内容呢？咱再回到刚才那个“同花顺里面住了一个人，他每天帮你选股交易”的例子。

  

首先，他的每日任务是你布置的，所以你要知道量化交易里面可以做什么，不可以做什么，因此，你需要先学习一些量化常识。

  

接着，他是一个机器人，不会说也不会听中文，你需要用他能听懂的语言才能给他布置任务，因此你需要学一门“外语”，对于机器人来说，这门外语就是一门编程语言，在量化交易领域，最广泛被使用的编程语言就是Python。

  

![](assets/002.png)

  

最后，同花顺软件不会真的让你住一个人进去，人家也怕有捣乱的。那咱就要找量化界的“同花顺”，能让咱把自己人安排进去的，我这次给大伙儿找到的就是QMT软件，你还需要学习QMT软件的基本操作和功能。

  

虽然要学习的东西不少，但这里需要确定快速入门的学习原则：适度学习，够用即可。最新版《新华字典》中，收录了13000多个汉字，而日常生活中只需要用到其中的3000多个，也就是说，不用啃完大部头才可以开始，按常用按需学习就行。

  

1.补充量化常识

量化知识纷繁复杂，不需要全部学会之后再去实盘交易，只需要掌握一个主体框架，知道量化交易的大体流程和主要模块，以后在实践当中碰到不懂的再去查，边干边学记得牢。

  

这里给大伙儿推荐一本书：《打开量化投资的黑箱(第二版)》（Inside the Black Box: A Simple Guide to Quantitative and High Frequency Trading，Second Edition），虽然它通篇没有具体的策略，也没有复杂繁琐的数学公式，但是个人觉得，它涵盖了量化交易入门所必备的各式各样的常识，在你读完之后，你会对量化交易有一个基本的了解，

  

![](assets/003.png)

  

注意，这里特指的是第二版，原书英文版是在2009年出版，2012年翻译成中文引入国内，第二版是在2013年出版，2016年翻译成中文引入国内，第二版除了对第一版错误进行修正外，关键是加入了『高频交易』这一部分的内容，内容也从原来的13章扩展到了17章。

  

这本书的作者是漂亮国的一个对冲基金经理，诗画乐三绝的文艺老炮，名字叫做里什·纳兰（Rishi K. Narang），咱就亲切称呼他为“老纳”吧，他上个世纪90年代就进入量化领域了，一直深耕量化交易策略至今，妥妥的“黄埔出身正规军”，这本书就相当于是他职业生涯心得体会的阶段脱敏梳理了。

  

![](assets/004.png)

  

这本书通篇可以分为5个部分。第一Part主要是介绍量化交易的背景知识和典型结构，啥是量化交易，啥是宽客；第二Part就开始拆解量化交易这个黑箱了，一个一个零件拆出来，摆在你的面前挨个介绍一番；第三Part主要是唠唠怎么评估宽客和量化策略，还反驳一些外人对量化的误解；第四Part就是说说高频交易和高频策略的类型；最后一Part就是展望一下量化的未来。

  

可以看得出来，这本书的核心内容就是第二Part，横跨第3章到第9章，这里面核心的核心就是阿尔法(Alpha)模型，其他还讲了风险模型、交易成本模型、投资组合模型、订单执行模型和科学研究方法。

  

![](assets/005.jpg)

  

我在这里多说几嘴关于阿尔法模型的吧，因为连阿尔法模型都没有的话，后面的策略步骤基本上就不用去做了。阿尔法模型就是量化策略当中超额收益的来源，也就是如何在交易市场中寻找盈利的机会，让自己获得超越市场基准的丰厚收益，这正是每个宽客魂牵梦萦的所在。

  

虽然量化策略众多，纷繁复杂，老纳给你指明阿尔法模型类型方向，只分为两类，一类是理论驱动型，另一类就是数据驱动型。

  

第一种理论驱动型，也是萌新入门经常选择的一种，宽客通过观察市场行为，寻找可以解释这些行为的普适性理论，然后再用数据检验（回测）是否有效，按照这个普适性理论交易是否能盈利。

  

老纳根据个人经验，把趋势跟随（trend）、均值回复（reversion）、技术情绪（technical sentiment）、价值/收益（value/yield）、成长（growth）和品质（quality）这6种策略都归为理论驱动型交易策略。

  

![](assets/006.png)

  

另一种就是数据驱动型，宽客也是观察市场行为，然后通过技术手段分析这些行为数据中的模式，但只是找到这种潜在的模型就行了，不需要有理论解释和支撑，只需要知道A能到B，不需要知道A为什么能导致B。

  

但老纳在书中说构建数据驱动型策略时，所使用的数学工具较为复杂，门槛比较高，在当时的业界使用还比较少，所以就不展开来讲了，主要还是集中在上面那6种策略类型。

  

到现在就不一样了，硬件设备、算法算力和数据丰富度极大提升，人工智能AI已经深入到投资交易领域，特别擅长发现数据之间的非线性关系，专门干这种数据驱动的活儿，每个时代都有每个时代的局限性。

  

2.入门Python编程

对于Python的快速学习，墙裂推荐廖雪峰老师的Python教程，不仅免费写得非常简单易懂，而且每个小节之后，都有编程互动小题目给你即时反馈，非常有趣，不用再想着自己啃完编程大部头再去编写策略。

  

教程链接：

https://liaoxuefeng.com/books/python/introduction/index.html

  

![](assets/007.png)

  

廖老师的教程非常详尽，连Web开发都讲了，但是再次重申咱的快速入门学习原则：适度学习，够用即可。对于量化编程基础而言，学到第13章“IO编程”章节就可以了，后面等有需要或有时间再看。

  

![](assets/008.png)

  

因为写Python就跟写文案一样，都是写作，但也分为散文写作、小说写作、广告写作、短视频脚本等，虽然基础一样，但不同领域用到的方法技巧各有侧重。廖老师的Python教程比较侧重于互联网开发方向，对于量化分析入门而言，后半部分初期的时候还用不上，等需要用到的时候再学习也不迟。

  

遗憾的是，里面没有讲到量化当中常用的numpy和pandas这两个库，不过可以用别的教程去补充，JoinQuant课堂上关于这两个库的入门写得非常好，我把链接放到下面了。可能需要登录才能查看研究环境和源码，用手机号注册就好，免费的，其他课堂内容也不错，有时间的话也可以学习。

  

Numpy：它是Python的一个开源的数值计算库，计算当中常用的数组和矩阵等数据类型，以及它们之间的运算，都可以依靠这个库快速实现。

  

Numpy库教程：

https://www.joinquant.com/view/community/detail/180d0f71a9033338c0a082a3f10123a4

  

Pandas：它是基于Numpy 之上封装的数据分析库，它能让数据分析和量化分析任务变得更加简单，打个不恰当的比方，它就相当于是Python界的“Excel”，是Python量化当中最离不开的一个库。

  

Pandas库之数据查看和选择：

https://www.joinquant.com/view/community/detail/c2e287adec1920efd500b701bced1e70

  

Pandas库之数据处理与规整：

https://www.joinquant.com/view/community/detail/e6471871ddf0098dd042800fe61d428b

  

其实，Python量化当中涉及到的库非常多，初学的话能学好这2个库就算不错了，一般的入门量化分析任务已经难不倒你了，Python量化当中其他可能涉及到的库还包括但不限于：matplotlib、sklearn、scipy、statsmodel、talib、tushare、akshare、backtrader、quantstats、empyrical、pyfolio、tensorflow、pytorch、keras、tsfresh、qlib......不用急着都学，遇到的时候，或有需要的时候再学就可以了。

  

3.掌握QMT软件

QMT是由迅投公司开发的量化交易软件，这是国内宽客实盘最主流的软件之一，支持股票、期货、期权、ETF、可转债等证券的程序化交易，目前已经对接了80+主流券商，对个人宽客来说，它主要是有3项优势：

  

（1）程序化交易实盘的开通门槛低。个人也可以在线开通，无需临柜办理，在各大券商办理开通QMT一般都是免费的，使用也是免费的，但开通的要求条件不同，可自行咨询自己目前所在券商的客户经理。如果没有找到合适的开通方，可通过文末二维码联系『量化君』帮你对接低门槛券商开通满血版QMT。

  

（2）后期的拓展性强。它不限制量化交易策略必须在QMT软件内执行，安装上对应库，可以放在任何Python 3.6 ~ 3.12的环境下运行，可玩性可拓展性非常强。

  

（3）软件生态好，用户基数大。官方有完善的知识库，平常的小窗私信当中，QMT的咨询占比也是最高的，特别是某平台的量化实盘功能停止后，大部分人都是首选转到QMT。   

  

![](assets/009.png)

  

下面3条链接是新手掌握QMT使用和开发策略实盘交易要用到的3个入门级教程，都出自于迅投的知识库。

  

QMT新人上手教程：

https://dict.thinktrader.net/freshman/rookie.html

  

内置Python教程：

https://dict.thinktrader.net/innerApi/start\_now.html

  

XtQuant开发教程：

https://dict.thinktrader.net/nativeApi/start\_now.html

  

【QMT新人上手教程】顾名思义就是教你如何操作QMT软件的，比如说登录、下载数据、新建策略、回测策略和实盘交易等操作。

  

但是【内置Python】就容易让人看懵，Python还分内外吗？XtQuant又是用来干什么的？

  

从底层上来说，【内置Python】和【XtQuant】是量化策略两种不同的实现方式。比方说，你是一个量化萌新，之前学Python的时候在电脑上装了Python3.12，现在刚在券商开通了QMT，拿到示例策略在QMT软件当中跑了起来，你以为用的程序解析器是之前你安装的Python3.12，然而并不是，QMT软件当中其实内置了一个Python环境，你在QMT软件当中跑的策略用的都是QMT自带的Python环境，而并不是你电脑本地安装的那个Python环境，所以QMT软件自带的Python环境叫做【内置Python】。

  

那很多人就会想当然地觉得用【内置Python】不就好了，软件自带的，不用自己再安装了，其实不是的，要是那样的话，迅投公司就不用再费心搞个【XtQuant】了。

  

【内置Python】的好处就是开箱即用，方便操作，但是也有两个比较硬核的缺点。

  

第一就是Python版本偏老，目前大部分券商的内置的Python版本是Python3.6，预安装的库也偏老偏少。

  

第二就是资源受限，无论你在QMT里面同时实盘5个策略还是10个策略，它们都是串行运行在一个线程上，只要其中一个策略阻塞，其他策略全部卡死。

  

因此【XtQuant】就是用来解决这两个问题的。QMT软件里有一个轻量化子模块功能叫miniQMT，登录QMT界面时勾选极简模式或独立模式就可以开启该功能，通过在电脑Python环境里安装xtquant库，就可以脱离QMT的内置Python环境编写策略，再连接QMT客户端进行交易。

  

只要你电脑上的Python环境是Python3.6 ~ 3.12，都能安装上xtquant库(可以获取数据和下单)，也就是说你想用什么库就用什么库，不再受QMT内置Python环境的限制，并且，最有用的是，多个实盘策略之间是多线程并行运行的，一个策略单独一个线程，其中一个作死不会影响另外的策略(只要电脑资源够)。

  

因此，基于miniQMT功能通过xtquant库实现策略的方式，在迅投当中也被称为【原生Python】，顾名思义，就是基于电脑本地的Python环境来实现量化策略，与【内置Python】相对，只要你在迅投文档中看到【原生Python】的字眼，就说明这个策略或代码是基于xtquant库实现得。

  

要特别说明的是，xtquant库中只实现了行情数据和交易下单接口，并不包含回测框架，如果需要回测的话需要自建回测框架或着用第三方回测框架。

  

因此，【内置Python】和【原生Python】都无所谓孰优孰劣，只是适用的场景不同，【内置Python】适合你只运行一两个策略或多个简单策略消耗资源都不太多的情况以及策略回测，【原生Python】可以让单个策略独占线程，多策略并行运行，也可以脱离老版本Python和第三方库少的限制，自由度更高，拓展性更强。

  

成年人不做选择，问就是都要。因此在券商那里开通QMT软件的时候，一定要问清楚有没有miniQMT功能，没有miniQMT功能的话，就用不了【原生Python】，你就失去了多策略并行运行和自由拓展等场景。如何判断你的QMT软件是否带miniQMT功能，以及如何安装miniQMT，可以看之前的文章[《你安装的量化交易软件是满血版吗？》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486762&idx=1&sn=0ebf5a95536d463ddb4080d9c5207561&scene=21#wechat_redirect)。

  

再来汇总一下谈及QMT时会涉及到的概念名词。

  

“QMT”是指迅投公司开发的QMT这款量化交易软件。

  

“miniQMT”是QMT软件附带的一个功能，或者说是一种运行模式(极简模式/独立模式)，通过与xtquant库配合，形成自由度更高的开发环境。因为“mini”在英文中是“小”的意思，所以“miniQMT”又俗称为“小QMT”，与之相对，整个QMT软件又被称为“大QMT”。

  

由于部分券商的QMT软件没有miniQMT功能，只有基于“内置Python”的那部分，所以有时候也用“大QMT”表示只有内置Python部分的QMT软件，所以有时候你也能见到“QMT = 大QMT + 小QMT”的表达。

  

“满血版QMT”是指带有miniQMT功能的QMT软件。

  

以上谈论到的QMT都是券商版的QMT，也就是从券商那里开通的QMT，也是绝大部分个人宽客接触到的QMT，其实在迅投官网上还有投研版的QMT，相对券商版的QMT来说数据更丰富和性能更强劲，并且它的原生Python是可以回测的，但它并不像券商版那样免费，软件费要接近1w块一年。由于本文主要是面向于量化萌新，因此QMT特指券商版QMT，继续秉持原生Python的xtquant是不能回测的说法。

  

因此，QMT入门时，建议先学内置Python部分，等到进阶的时候，再学原生Python & xtquant部分，但在券商开通QMT时，一定要开miniQMT功能，给自己将来保留一个可能性。

  

学习虽好，不要贪杯，一步一个脚印，慢慢来比较快~

  

2026，量化入门，早成大神！！！

  

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

![](assets/010.png)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/011.jpg)

![](assets/012.png)