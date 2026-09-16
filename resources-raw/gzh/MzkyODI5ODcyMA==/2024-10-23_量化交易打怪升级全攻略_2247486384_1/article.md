# 量化交易打怪升级全攻略

量化君 量化君也 2024-10-23 19:17 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486384&idx=1&sn=a1d00fcf058755df0f2b51cda5a2ab5a&chksm=c327fcc69c2091560526d24ba293acb5d6eaa6d17575672e6a04bde558f74a10f41894938f43#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486384&idx=1&sn=a1d00fcf058755df0f2b51cda5a2ab5a&chksm=c327fcc69c2091560526d24ba293acb5d6eaa6d17575672e6a04bde558f74a10f41894938f43#rd)

![](assets/001.png)

  

上钟！  

  

继续分享量化干货~

  

**这次要唠的是Stat Arb的新作《Quant Roadmap》(中译名《量化交易路线图》)**，为了方便，下文就称呼作者为“老S”，根据公开资料显示，他可是正儿八经的的量化研究员出身，在漂亮国头部对冲基金担任过量化研究主管，管理过高频交易策略团队，现在主要搞数字货币。

  

![](assets/002.png)

  

老S除了量化交易做得好之外，表达欲还很旺盛，除了在自己博客网站The Quant Stack(https://www.algos.org)写干货文之外，隔三岔五就发推表达自己对量化行业的观点和看法，话题主要集中在高频交易、统计套利、CTA、做市、实盘交易这几块儿，《Quant Roadmap》这本量化攻略也是发布在Twitter上然后传播开来。

  

![](assets/003.png)

  

《Quant Roadmap》跟之前推荐过的[151策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)非常像，都是属于ROR，Resource of Resources，资源中的资源，跟鹿鼎记里面韦小宝刚入会时，陈近南交给他那本武功秘籍一样，是一堆绝世武功秘籍的目录，以至于老S怕大伙儿从入门到放弃，后面还特地还写了一章，教大伙儿如何学习和用好这份材料。

  

![](assets/004.png)

  

‍就不扯闲篇儿了，跟大伙儿唠唠主体的内容架构，先上目录。

  

![](assets/005.png)

  

**Chapter 1:  Machine Learning and Algorithmic Trading** 

**机器学习和算法交易**：这一章节主要给大伙儿提供了机器学习和算法交易的书单，目的是帮助读者从基础概念开始，逐步深入到更高级的主题。当中推荐了很多量化高分书籍，例如《Quantitative Trading: How to Build Your Own Algorithmic Trading Business》和《Advances in Financial Machine Learning》等，除了一些大部头的教材外，也还提供了一些可选的补充书籍，以便大伙儿可以根据自己的难度偏好和学习速度来选择。

  

![](assets/006.png)

  

**Chapter 2:  Derivatives, and Volatility Trading**

**衍生品和波动率交易**：这一章节聚焦于衍生品交易的世界，提供了关于期权、期货和其他衍生品的核心书单，例如做期权都有耳闻的《Options, Futures, and Other Derivatives》，这些书籍不仅涵盖了基础理论，还包括了高级交易策略、风险管理、波动率交易和期权做市等技巧。

  

**Chapter 3:  YouTube Videos**

**YouTube视频**：这一章节推荐了一系列YouTube频道和视频，内容覆盖了量化交易的各个方面，从基础概念到高级策略。这些视频特别适合不喜欢看书、喜欢看视频学习的人，能让大伙儿更直观地理解复杂的量化概念和策略。

  

**Chapter 4:  Courses**

**课程**：这一章节列出了一系列量化相关的课程资源，特别是Coursera上的课程，如Robert Shiller的《Financial Markets》和Andrew Ng的机器学习和深度学习课程，这些课程主打的就是结构化的学习路径，涵盖了从基础金融知识到高级机器学习技术的核心内容。顺道提一嘴，Coursera上很多课程都是免费学习的，除非你想要结课证书攒学分，那时候才要付费。

  

**Chapter 5:  Podcasts**

**播客**：这一章节主要是推荐了一些播客节目，这些节目深入探讨了量化交易和金融市场的各个方面，方便大伙儿获取行业见解、学习市场动态和了解行业专家观点。推荐的播客包括《Tick Talk》、《Flirting with Models》和《Mutiny fund》等，内容还是比较丰富的，从交易策略到市场分析，应有尽有。

  

**Chapter 6:  Trading Platforms & Brokerage Firms**

**交易平台和经纪商**：这章主要讨论了股票和其他资产类别的交易平台，以及数字资产领域的交易所和经纪商。详细介绍和对比了各个经纪商的服务和优势，以及它们在提供数据、交易成本、杠杆和对冲服务方面的特点。

  

**Chapter 7:  Neural Networks / ML / Hype**

**神经网络/机器学习/行业热点**：这一章节探讨了神经网络和机器学习在金融领域的应用，并分析了当前行业的热点。**老S还在文中温馨提醒，尽管这些机器学习和深度学习的技术很受欢迎，但它们可能并不是交易策略的最佳解决方案，对此，老S推荐了一些更为基础和实用的机器学习方法，如回归分析、非参数方法和树模型**，然后又再次倾情推荐了Andrew Ng在Coursera上的机器学习和深度学习课程。

  

**Chapter 8:  Key Mathematics Concepts**

**关键数学概念**：这章强调了理解关键数学概念对于量化交易的重要性，如测度论、随机微积分和概率论，它们对于理解和构建量化模型十分重要。老S推荐了一系列书籍和课程，例如MIT的《Mathematics for Computer Science》和Coursera上的《Mathematics for Machine Learning》，希望大伙儿能建立坚实的数学基础。

  

**Chapter 9:  Optimization (Deterministic & Stochastic)**

**优化（确定性和随机性）**：这一章节主要讨论优化方法在量化交易中的重要性，包括确定性和随机性优化技术。优化算法可以帮助宽客在量化策略中找到最佳参数，以提高策略的性能。老S提供了一些基本的优化算法，如遗传算法、蒙特卡洛优化和凸优化基础，并推荐了一些深入学习优化算法的书籍和资料。

  

**Chapter 10:  High Frequency Trading & Market Making**

**高频交易和做市**：这章提供了高频交易和做市策略相关的书籍、视频和研究文章，介绍了相关的量化策略，例如如何优化交易算法以减少延迟和提高交易效率。怕你专业书籍看不下去，还顺道儿推荐了一些关于高频交易的轻阅读类书籍(故事类)，例如《Flash Boys》和《Dark Pools》。

  

**Chapter 11:  Additional Volatility/Derivatives Resources**

**其他的波动率/衍生品资源**：感觉这一章节是第2章的补充，而且老S在这里套娃了，推荐的网址链接其实是一大堆别的链接的目录。在这里推荐了更多关于波动率和衍生品交易的资源，包括社区讨论、专业论坛和研究文章，特别推荐了Wilmott论坛和Nuclear Phynance网站，对深入理解衍生品定价和交易策略非常有帮助。

  

![](assets/007.png)

  

**Chapter 12:  Coding Languages Review and Resources**

**编程语言回顾和资源**：这章主要讨论了在量化交易当中使用的主要编程语言，如Python、R和C++，并提供了相关的学习资源。文中阐明了Python在目前量化研究和开发中的主导地位，以及C++在高频交易中的应用。此外，还提到了Rust在数字资产交易中的流行趋势，并提供了相关的学习建议。

  

**Chapter 13:  Projects**

**项目**：这一章节提供了丰富的量化交易项目的灵感和案例，包括配对交易、套利、做市策略和动量策略等。通过这些项目的学习，大伙儿可以将理论知识应用于实践，加深对量化交易策略的理解，当中涉及的技术包括机器学习、深度学习和统计模型，对构建自己的交易系统铁定有利，下面是一小部分案例截图。

  

![](assets/008.png)

  

**Chapter 14:  Data**

**数据**：巧妇难为无米之炊，因此这章讨论了数据在量化交易中的重要性，老S贴心地提供了免费数据源的信息，并且详细介绍了如何获取、清洗和预处理数据，以及如何使用数据来测试和优化交易策略。

  

**Chapter 15:  GitHub Repositories**

**GitHub仓库**：众所周知，GitHub是全球最大的在线同(ma)性(nong)交友网站，老S在这一章节当中推荐了一些GitHub项目，里面包含了量化交易策略和工具的示例代码，主打的就是开箱即用，不用重复造轮子，它们可以帮助大伙儿快速学习和开发自己的交易策略，当中涵盖了从基础的信号处理到复杂的市场微结构模型/策略。

  

**Chapter 16:  Light Reading**

**轻松阅读**：如果前面被一大堆专业资料绕晕的话，可以来这章看一些非教科书类的书籍，这些书籍可以让你轻松了解金融行业和量化交易的工作流程，特别适合那些希望在轻松阅读氛围中获得行业见解的小伙伴，例如《Liars Poker》、《The Quants》和《The Man Who Solved the Market》等。

  

**Chapter 17:  Careers**

**职业规划**：这一章节老S介绍了量化交易领域的典型职业路径，包括如何获得实习机会和准备面试。**对于实习生，老S温馨提示，在实习期间，请不要有佩戴劳力士(Rolex)等“炫富”行为，并且，下班不要比老板早。**

> When you receive a summer internship do not wear a Rolex, Gucci sleds, etc. You are there to wear a plain Casio, always leave later than your boss.

  

**Chapter 18:  Arbitrage Guide**

**套利指南**：这章专注于数字资产领域的套利策略，并提供了相关的资源和工具，详细介绍了不同类型的套利策略，如资金费率套利、三角套利、现货套利、永续套利和事件套利等，并推荐了一些扫描套利机会的网站。

  

**Chapter 19:  Market Making Guide**

**市场制造指南**：这一章节主要介绍了做市策略的各个方面，包括如何管理风险、优化报价和处理延迟。

  

**Chapter 20:  Pairs Trading Guide**

**配对交易指南**：这章提供了配对交易策略的一些资源，包括研究文章和GitHub资源等，当中介绍了配对交易的基本原理，以及如何使用统计模型来识别和捕捉交易机会。

  

**Chapter 21:  Seasonality Guide**

**季节性策略指南**：这一章节介绍了季节性策略的原理和资源，包括它在商品市场的应用，例如如何识别和利用市场的季节性模式，以及如何构建基于季节性因素的交易策略。

  

**Chapter 22:  Momentum Guide**

**动量策略指南**：这一章节介绍了动量策略的构建和应用，这是一种基于资产过去表现来预测未来价格变动的策略，当中提供了一些关于动量策略的研究文章和相关资源，帮助大伙儿快速理解动量效应及其在交易当中的应用。

  

**Chapter 23:  Blogs To Read**

**推荐阅读的博客**：博客通常是寻找新信息和新想法的好地方，于是老S在这章里面列出了一系列量化交易相关的博客，涵盖了从基础的交易理念到高级的量化模型，同时里面提供了很多实用交易策略的见解和代码。哈哈，像推荐播客一样，老S也自卖自夸地推荐了自己的博客(https://www.algos.org)，还放在了第一位，咱之前介绍过的Quant Insti和Quantocracy也在此列。

  

![](assets/009.png)

  

**Chapter 24:  Twitter Accounts To Follow**

**Twitter账号推荐关注**：像前一章那样，老S在这章节推荐了132个量化交易相关的Twitter账号，这些账号日常会分享有价值的行业信息和分析，主要的作用是帮助大伙儿保持对市场动态的了解，并获取最新的交易策略idea。

  

**Chapter 25:  How To Learn This Material**

**如何学习这些材料**：也许老S也觉得介绍和推荐的资料太多了，怕大伙儿直接从入门到放弃，于是特地写了这一章节，给大伙儿提供相应的学习建议，**最重要的建议就是“动起来”：不要都看，不要贪大求全，只筛选与自己相关的内容，以开发盈利策略为目标，然后阅读、做笔记和开发策略，实践才是检验学习的最佳途径，同时也要避免陷入过度复杂的模型和工具开发。**

  

**Chapter 26:  Other Roadmaps**

**其他路线图**：老S又在这里套娃了，这本书本身就是路线图(Roadmap)，现在又套了好几个其他路线图进去，变成了Roadmap of Roadmaps，ROR的标签又重现了。老S表示，这些路线图可以作为路线图的补充，旨在帮助大伙儿发现更多的学习资料和工具。

  

看到这里，有没有发现这个《Quant Roadmap》真是包罗万象，啥玩意儿都有，从新手村开始，到打各种副本，主线支线各种攻略都有，真可以称得上是量化交易领域的打怪升级全攻略。

  

还是老规矩，对《Quant Roadmap》感兴趣的小伙伴也无需翻墙出去找，在本公众号后台回复关键字就可以直接保存下载了，**本次接头的暗号是『****量化攻略****』这4个字。同时考虑到有些小伙伴的阅读需求，在资料包里，也一并附上了中英双语对照版，enjoy~**

  

![](assets/010.jpg)

  

* * *

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486235&idx=1&sn=b946c1496b177a4838b14caa98bd713c&chksm=c21ba894f56c218282c2f5e450c594b4133f6a7f8124eb2483eb610e3acad954b6bd0928dc8e&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486239&idx=1&sn=380795dcdf743047427f80d3f2c6b3e3&chksm=c21ba890f56c2186dca7d5839a5c07700a5351245ce1e7b9da0d5c4c3a01b6302fe1469a1aaa&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486368&idx=1&sn=9a8e7b22717192a59072ef40c5b1ea43&chksm=c21ba82ff56c21390408c5974d8fefd112b9f41e70702558dcee5abc018e30c1a61ed42e243f&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[黄金价格预测](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486032&idx=1&sn=7b0a0f10b252eabec76bfef256db9d8e&chksm=c21ba9dff56c20c92e3a08ee170b20dc411112fa12a8f89f55ae70450000e25614174a7a22bf&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect) [五穷六绝](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486105&idx=1&sn=87db4aa95cd30cf1e2b2b4a0205a2234&chksm=c21ba916f56c200088c4aceda6e62511469cff0d18af97fa48b659fc6ac3862d494f02fd38a6&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/011.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/012.png)