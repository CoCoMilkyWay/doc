# 萌新快速入门量化交易的自学路径推荐(新版)

量化君 量化君也 2024-01-09 06:16 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485775&idx=1&sn=c83a27eebf0657496900296dc23064b5&chksm=c32bcd74abeef895c2221df252ee97d317855e7c2f7df85d0f23c89b7f13c6ee532094984987#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485775&idx=1&sn=c83a27eebf0657496900296dc23064b5&chksm=c32bcd74abeef895c2221df252ee97d317855e7c2f7df85d0f23c89b7f13c6ee532094984987#rd)

![](assets/001.png)

  

又是新年伊始，去年立的flag都实现了吗？

  

据我多年来的观察，很多萌新开始学习量化，特别是年初的时候立下“宏图大志”，但有相当一部分最终没能"上岸"，从入门到放弃，从然后到没有然后，并不是因为他们不够聪明或不够努力，原因有很多，我觉得大部分只是方向或方法没对。  

  

特别是对于没有编程基础的萌新，为了入门量化，先买了一本厚厚的Python编程书，看着看着就昏昏欲睡，这个很正常，这的确很无趣，因为这只是为了学习而学习，记住了很多知识，却感觉无法落地。

  

就跟很多国人从小学到大学学了十几年的英语一样，记住语法单词只是为了考试，觉得很无趣，要是说你附近有一群漂亮的外国妹子，你要用英语去勾搭她们，是不是就来劲了。

  

一开始，你只能一个一个单词往外蹦，什么"hello"啊，什么"welcome"啊，什么"beautiful"啊，可能一个主谓宾的整句都说不了，加上肢体语言，不妨碍你们的大体沟通。  

  

跟她们混久了，听着相互之间的沟通，慢慢就会短句了，再过久一些，不仅长句复合句会了，连口语发音味道儿都正了。

  

你瞧瞧，同样是学英语，为什么一个是无趣至极，一个是相当来劲呢，他们之间的差别主要在哪里？

  

我个人觉得主要是两点：**一是目的动机，二是即时反馈。**

  

高效率做事讲究"以终为始"，要紧扣目标，不要走弯路跑偏了，以考试为目的，not cool，因为大部分人感觉自己都是被动应付考试，勾搭妹子，very cool，因为你觉得自己在做一件自己认可且有趣的事情。

  

![](assets/002.png)

  

你以提高考试分数作为学习目标，但是努力学习到分数明显提高之间有非常大的时间间隔，也就是你要在这段长时间里面忍受无趣，而跟外国友人学英语，学了马上就能用，别人提了一个新词儿"pretty"，你转头就能对妹子说"you look so pretty today"，换来莞尔一笑，也就是这种即时反馈，将无趣碎片化了，从忍受变为享受。

  

用高大上的话来说就是"正向飞轮"，在这个学习的过程中，你学了一个知识点，然后学以致用完成了一件小事儿，完成这个行为给你带来了满足感和正反馈，激励你乐乐呵呵学新的知识点，如此反复循环，像滚雪球一样，滚着滚着你就不知不觉入门了。

  

那学量化交易也是如此，首先要想清楚自己为什么要学量化。

  

_是看到媒体宣传量化对冲基金赚钱，自己也想从事该行业？_

  

_看到身边有人学习量化交易，自己也想学习一下？_

  

_自己有投资想法，想形成交易系统，并用量化分析方法验证其准确性？_

  

_自己已经有稳定的盈利系统，想解放双手和坚持纪律性，用程序化自动交易？_

  

学量化的动机和目的是什么都可以，关键是看自己的渴望掌握这项技能的程度，为自己的学习赋予自己认可的意义。

  

比如说，你学量化纯粹是为了赚钱，入门量化需要学100个知识点，你预计将来可以提高交易胜率，多赚或少亏10w，这样一个知识点就相当于多赚或少亏1000块钱，这样一换算，是不是学习动力就足一点了。

  

学习量化，为了交易赚钱可以，为了谈资装X也可以，为了勾搭宽客也可以，只要自己足够认可足够渴求就可以了，这样咱就能保持着未来燎原的星星之火。

  

接下来，最重要的就是打造出能有即时正反馈的学习路径，形成正向飞轮，入门量化就跟滚雪球似的。

  

上面都是虚头巴脑的大道理，都是自己浅薄的想法，以下正式唠唠具体的学习路径：

  

**交易想法 -> 量化基础 -> 量化平台 -> 量化策略**

  

这是抽象的概括，下文会把每个步骤详细讲讲，这里需要确定快速入门的学习原则：**适度学习，够用就行**。

  

最新版《新华字典》中，收录了13000多个汉字，而日常生活中只需要用到其中3000多个，也就是说，不用啃完编程书籍等大部头才可以开始，按常用按需学习就行。

  

**一、交易想法**

很多人做量化，都是因为自己有初始的交易想法，想验证正确性提高交易胜率，或想解放双手追求效率，全自动程序化盯盘交易，量化跟人工智能AI一样，都是手段，用来实现自己想要的目的，不是为了量化或AI本身而学习。

  

**有初始的投资想法，在开始学习的时候有一个好处，就是可以在学习量化时有的放矢，听到相关的知识点的时候，脑子就会在想，我想要的功能可不可以这样实现。**比如，你想实现均线交易策略，那么你在学习pandas模块时，听到rolling和mean函数，就会有“确认过眼神，找到对的人”的赶脚。

  

如果在交易想法这边还是没有感觉，可以多看一些交易书籍和研报论文，这里我可以给大伙儿推荐一些，相信以下这3个交易策略合集类资料能给量化萌新一些交易思路方面的启发，粗粗算下来，这3份资料里面的策略/指标思路合计下来不少于1000个。

  

首先映入眼帘的是前NASA登月科学家、现量化先驱佩里•考夫曼的量化神作《交易系统与方法》，说起这老爷子，国人可能觉得很陌生，但在量化圈子里，或多或少都听说过“考夫曼均线”，学名为“自适应移动均线”（Adaptive Moving Average，简称AMA），这就是他的杰作之一。

  

[《261个策略/指标，萌新Quant在这本量化神作中学到的》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&chksm=c21ba2b5f56c2ba37244121483056cb11a064e516a33e5a247938d49ab4f6dbc291f288e70d2&scene=21#wechat_redirect)

  

在此书当中，披露了老爷子数百个交易策略和技术指标，而且全部都有对应的源代码，虽然用的是国外的TradeStation平台，但其编程方式非常口语化的，只要能认识简单的英文，不敢保证你能顺滑地编写策略，但是看懂策略的交易思想是铁定没问题的。

  

第二本也是一位量化大牛的神作，其中涵盖了股票、期货、期权、外汇、加密货币、ETF等投资领域的151个交易策略，那就是Zura Kakushadze的《151 Trading Strategies》，作者另外一本名著就是《101 Formulaic Alphas》（坊间俗称“Alpha101”）。

  

最初是2018年8月发表在SSRN上的同名论文，后来在同年年底整理成书，目前全网传播较多的是361页的论文版本，但个人感觉阅读效果较好的是480页的电子书版本，不仅标签完善，而且参考文献跳转非常顺滑。

  

[《推荐一本量化宝藏书籍，内含151个量化交易策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)

  

书中内容的组织形式是，每一个小节对应一个量化策略，开头会三言两语引入策略，然后概括出核心规则/公式，最后给出策略的构建方法，其间会穿插很多参考文献，告诉你策略idea的来源和为什么这样设置，所以很多人说这本书只是一个目录，那2000个参考文献才是本体。

  

第三个就更厉害了，它是一个被称为量化神集的github项目，在这里面，策略数目直接就是696个，关键是通通都有高清源码，除此之外，还有量化书籍、量化库、视频课程、博客等。

  

![](assets/003.png)

  

这个github项目的贡献者/维护者是Edouard d'Archimbaud、James Munro和GrimyFishTank，所有的量化资源都被分门别类、整整齐齐码放在那里，静静地等待有缘人驻足观看，可惜的是，以前是统统免费，现在部分内容要付费订阅了，如果你依然感兴趣的话，可以去瞅瞅。

  

[《分享一个量化交易神集：696个策略，55本书，97个库...》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

  

**二、量化基础**

这里面主要包含两大部分，**一个是量化通识，另一个是编程基础。**

  

关于量化通识，看量化故事类的书籍都可以有所了解，以前我也列过一个书单，有时间的话可以挑自己感兴趣的慢慢看。

  

[《量化投资书单推荐（20本）》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)

  

如果一开始没有那么多时间，想快速了解量化投资的方方面面，一开始只看**《打开量化投资的黑箱(第二版)》（Inside the Black Box: A Simple Guide to Quantitative and High Frequency Trading，Second Edition）就够了，注意，这里特指的是第二版。**

原书英文版是在2009年出版，2012年翻译成中文引入国内，第二版是在2013年出版，2016年翻译成中文引入国内，第二版除了对第一版错误进行修正外，关键是加入了『高频交易』这一部分的内容，内容也从原来的13章扩展到了17章。

  

[《萌新量化投资入门的第一本书》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)

  

关于编程基础，因为不同量化平台的编程语言都不一样，这里只好拿在量化界广泛使用的Python举例。  

  

**对于Python的快速学习，墙裂推荐廖雪峰老师的Python教程**，不仅免费写得非常简单易懂，而且每个小节之后，都有编程互动小题目给你即时反馈，非常有趣，不用再想着自己啃完编程大部头再去编写策略。

  

教程链接：

https://www.liaoxuefeng.com/wiki/1016959663602400

  

![](assets/004.png)

  

廖老师的教程非常详尽，连Web开发都讲了，但是再次重申咱的快速入门学习原则：不贪多，够用就行。对于量化基础而言，学到“错误、调试和测试”章节就可以了，后面等有时间再看。

  

![](assets/005.png)

  

因为写Python就跟写文案一样，都是写作，但也分为散文写作、小说写作、营销写作等，虽然基础一样，但不同领域用到的方法技巧各有侧重。廖老师的Python教程比较侧重于互联网开发方向，对于量化分析入门而言，后半部分初期的时候还用不上，等需要用到的时候再学习也不迟。

  

遗憾的是，里面没有讲到量化当中常用的numpy、pandas、matplotlib和sklearn等Python库，这个可以在学了廖老师课程之后，再单独度娘学习一下。

  

**Numpy**：它是Python的一个开源的数值计算库，计算当中常用的数组和矩阵等数据类型，以及它们之间的运算，都可以依靠这个库快速实现。  

  

**Pandas**：它是基于Numpy 之上封装的数据分析库，它能让数据分析和量化分析任务变得更加简单，打个不恰当的比方，它就相当于是Python界的“Excel”，是Python量化当中最离不开的一个库。

  

**Matplotlib**：它是Python的一个绘图库，它能帮助你将价格序列、因子数据、净值曲线等数据快速可视化展示出来。

  

**Sklearn**：全称是scikit-learn，是Python当中的机器学习库，它涵盖了大部分机器学习常用的算法，并且还包含了样例数据、预处理、特征选择、模型验证等模块。  

  

其实，Python量化当中涉及到的库非常多，这4个库是其中经常被用到或提及的，萌新可以快速浏览一下我之前这篇文章[《手把手教你，利用机器学习模型，构建量化择时策略（附全流程代码）》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)，感受一下它们之间的关系和作用。

  

初学的话能学好前3个就算不错了，一般的入门量化分析任务已经难不倒你了，Python量化当中其他可能涉及到的库还包括但不限于：scipy、statsmodel、talib、tushare、akshare、backtrader、quantstats、empyrical、pyfolio、tensorflow、pytorch、keras、tsfresh、qlib......不用急着都学，遇到的时候，或有需要的时候再学就可以了。

  

**三、量化平台**

对于量化初学者而言，不建议自己搭建量化框架/平台，应该以实现量化策略为主，把数据获取清洗、回测框架搭建和对接实盘接口等工作交给专业团队打理，**因此强烈建议使用现成的第三方量化平台，这里给大家推荐一些。**

  

如果你打算做股票量化交易，可以选择以下6个量化平台，在他们的官网的“帮助中心”里面，可以找到对应的上手教程和策略模板。

  

**聚宽JoinQuant**：

https://www.joinquant.com

  

**优矿Uqer**：

https://uqer.datayes.com

  

**米筐RiceQuant**：

https://www.ricequant.com

  

**掘金量化**：

https://www.myquant.cn

  

**迅投QMT**：

http://www.thinktrader.net

在支持该量化平台的券商官网下载和开通

  

**PTrade：**  

https://www.hs.net

在支持该量化平台的券商官网下载和开通  

  

 如果你打算做期货/期权/大饼的量化交易，可以选择以下5个量化平台。

  

**交易开拓者TB**：

http://www.tradeblazer.net

  

**vn.py**：

https://www.vnpy.com

  

**文华**：

https://www.wenhua.com.cn

  

**金字塔**：

https://www.weistock.com

  

**MultiCharts**：

https://www.multicharts.cn

  

 TB研究策略和回测什么的都是免费，只有开启实盘时才会在基础手续费上加收一些，以个人观察，现存的很多系列源码，都是以TB居多。

  

vn.py是一款基于Python的开源量化交易系统开发框架，后来更名为VeighNa，不过大伙儿还是习惯地称之为vn.py。由知乎量化大V『用Python的交易员』开发，定位是量化交易平台，提供从交易API对接到策略自动交易的完整解决方案，对接了国内外诸多不同类型的金融市场：证券、期货、期权、外汇、数字货币等。

  

后面三个就都是收费的了，优点就是编程相对简单一些，缺点就是贵，大家也可以去看看。

  

**四、量化策略**

有了编程基础，又选定了量化平台，恭喜你，你终于有能力实现自己最初的投资想法了，量化策略是交易想法的逻辑化和程序化展现。

  

由于每个人的交易想法不尽相同，只好举一个简单的双均线交易策略为例进行描述，因为“双均线”这是一个接触到投资交易，都基本会听过的词儿，“专家”告诉你在金叉的时候买，在死叉的时候卖，那实际效果到底是怎么样的呢？

  

在聚宽JoinQuant量化平台上，拿茅台作为交易标的，咱定义5日均线和20日均线在出现金叉的时候，第二天一开盘就全仓买入，出现死叉时，就把所有持仓全部卖出，策略代码如下。

  

```
# 导入函数库
```

  

如果已经看完廖老师的前几章课程，这代码就大概能看懂七七八八了，剩下的再结合平台的API说明就能全部弄清楚了。

  

大概的实现流程就是，在初始化函数initialize中设置了交易标的、策略参数和交易费率，以及定义了一个每天在开盘运行的函数stock\_trade，并且开启了“防未来函数”功能。在stock\_trade函数里面，计算昨天和前天的5日均线和20日均线，如果金叉就买入，死叉就卖出。

  

运行策略，就会不断输出自定义的交易信息。

  

![](assets/006.png)

  

并且在运行过程中，收益率曲线也在不断地生成。

  

![](assets/007.png)

  

大家觉得这个回测绩效怎么样？双均线策略算有效吗？你可以自己贴代码跑回测试试，同时再调整交易标的和双均线参数试一试，一般情况下回测很快，不需要一个东的时间。

  

虽然我这里以JoinQuant策略为例，**但所有量化平台的实现逻辑都是相通的，你只需要定义自己的函数，告诉系统“你要在什么时间？交易什么标的？交易数量是多少？”，你只要解决这3个“什么”的问题，所有的量化平台你都可以玩得转了。**

  

如果你能完全理解并且复现出这个双均线策略，可以说明量化已经初步入门了，可以着手去实现你最初的交易策略了。如果此时还没有初始的交易想法，但又想量化练手，那就去复现金融工程研报吧，往往一篇研报至少包含一个量化策略，看看自己的复现水平能不能向“正规军”看齐，这一part可以参考一下我之前的手把手系列，全都有参考源码。

  

[《复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect)

  

[《(续)复现网红阻力支撑指标RSRS，手把手教你构建大盘择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)

  

[《手把手教你构建与改进轮动策略（十年10倍）》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect)

  

[《手把手教你，利用机器学习模型，构建量化择时策略（附全流程代码）》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)

  

如果你还想要实现更多的量化策略，可以䁖䁖下面的文章~  

  

**股票&ETF&指数相关策略：**

  

[《Barra太复杂，唠一个适合萌新Quant上手的量化基本面多因子模型F-Score》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect)

  

[《ETF轮动策略在阻力支撑相对强度RSRS指标加持下起飞》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect)

  

[《量化交易野路子：菜场大妈选股策略（10年100倍）》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect)

  

[《菜场大妈遇上马科维茨，擦出小市值更高收益的火花(十年160倍)》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect)

  

[《换了量化平台，重新回测，还是十年10倍》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)  
  

[《轮动策略改进：唉~量化策略越改越差了》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485441&idx=1&sn=6bb933d95c5cbdee9cee0549ec79d77c&chksm=c21bab8ef56c2298dc42a48f0f0cabedd43840f81258b960cf60a1a1f94d7e26d87f945ae34b&scene=21#wechat_redirect)

  

[《唠唠量化策略开发当中的细节优化，十年多赚200%》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

  

[《另类策略探索：利用美债收益率预测A股大盘走势》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)

  

[《两个简单的GARP因子，帮这位量化基金经理，跻身同类Top10（含复现）》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

  

[《从股价上涨驱动力出发，构建分析师一致预期成长策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

  

[《跟踪『聪明钱』，巧用北向资金进行大盘择时》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect)

  

[《量化萌新向ETF择时策略：当北上资金遇上布林带》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect)

  

[《跟着“基金一哥”张坤量化选股的快乐，你想象不到！》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

  

[《小市值因子已然凉凉，绩优小市值依旧狂浪》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)

  

[《中国版“漂亮50”量化策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)

  

[《鱼身策略懒人爱，量化内卷别乱买》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

  

**商品期货相关策略：**

  

[《唠一唠曾在全球量化策略热榜上排名第9的TrendModelSys策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  

  

[《又来唠一唠曾在全球量化策略热榜上排名第6的RUMI策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

  

[《又来唠一个另类异质量化策略：20后的Trendflex策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

  

[《『导数』在量化策略中的妙用：日内波动极值vs低阶多项式拟合策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)

  

[《K线标准化结构图：构建一个趋势策略，就是那么朴实无华》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect)

  

[《探索利用价格概率密度函数，构建趋势突破策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  

  

[《CTA策略中的Alpha：期限结构之展期收益率策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)

  

[《量化本无妙手，背后都是坚实的本手：波动率不对称性RSJ量化策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

  

[《兄弟家量化策略很多，拿一个『波动率收敛突破策略』盘一下》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect)

  

[《兄弟家量化策略很多，又拿一个『操盘手策略』盘一下》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)

  

[《动物庄园：商品期货跨品种套利策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect)

  

[《量化同质越来越严重，如何保持策略的长久优势？（附异质化另类量化策略）》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)

  

[《唠一唠指标之王MACD的另类用法：高低形态短线量化策略》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)

  

[《股指期货除了无脑吃贴水之外，还有更卷的量化操作策略吗？》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect)

  

就这样，转起“正向飞轮”，实现和玩转更多策略，等你测试出心仪的策略效果，接着上模拟盘跟踪，然后就是实盘，接着就是不断迭代优化，慢慢地就变成合格宽客，最后就变成量化大神了。

  

**2024，量化入门，早成大神！！！**

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485753&idx=1&sn=0bff8f88e77269364a7ca2c5c5adcb79&chksm=c21baab6f56c23a0ffffcac74fb9fa7ae5ae87230442be5e3c8e3d131bd321416855cbfaabfb&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485755&idx=1&sn=cbbcc52e7542ed7dcb9ec62ba4ac36cf&chksm=c21baab4f56c23a2d9bf705f47d72fd65f2e82fa3c628978db49c352f0cb125a0eeb2dffc8be&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

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

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect) [量化砸盘](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485487&idx=1&sn=dcf8ca1e44357071363ca63daca0f270&chksm=c21baba0f56c22b6b352b30d7e5bb21f523f4268eb1edaec0ff4b3472199a5432beb920f505f&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/008.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/009.png)