# 做量化交易发愁写代码？一招教你白嫖GPT智能编程神器(重制版)

量化君 量化君也 2023-04-16 20:29 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485109&idx=1&sn=45760b047f9b3510db48104674db4ab8&chksm=c3e6468809e8758eee5fe206a14047d8a3bb9c87ca4221803422f57b451f74774edfcaaae3bb#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485109&idx=1&sn=45760b047f9b3510db48104674db4ab8&chksm=c3e6468809e8758eee5fe206a14047d8a3bb9c87ca4221803422f57b451f74774edfcaaae3bb#rd)

![](assets/001.png)

  

上个月21号，发布了文章[《做量化交易发愁写代码？一招教你白嫖GPT-4智能编程神器》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)，让很多量化萌新体会到了快速高效率生成量化代码的乐趣。

  

但现在是“**AI一天，人间一年**”，距发布时间还不到1个月，AI编程神器Cursor已经日新月异，之前的使用教程也要与时俱进跟上来，下面具体展开唠唠。

  

**一、官网去除了GPT-4字样**

登录官网，虽然总体跟以前的风格大致一样，但是细心的小伙伴会发现slogan口号“Build Software.Fast.”下的那行小字发生了改变，官网地址：https://www.cursor.so/。

  

旧版是“Write, edit and chat about your code **with GPT-4** in a new type of editor”，新版是“Write, edit and chat about your code **with a powerful AI**”，合作方OpenAI公司没有发生改变，但去除了GPT-4的字样，换成了powerful AI。

  

_旧版官网首页_

![](assets/002.png)

  

_新版官网首页_

![](assets/003.png)

  

这也解答了我在之前那篇文章当中的疑惑，因为在之前多次的撩骚当中，发现Cursor也是只使用了GPT-3模型，没有用到GPT-4。其中一种猜想就是，**Cursor的确是调用了OpenAI公司的GPT接口，但并不是每次都是调用GPT-4（感觉大部分时间都是调用GPT-3），可能存在任务的调度。**

  

![](assets/004.png)

  

为了自己标题党的嫌疑少一些，即使这篇文章是旧文的重制版，咱也跟着把标题中的“GPT-4”字样移除，实在是搞不清楚是哪个版本，就只写“GPT”吧。

  

**二、版本升级，需要注册**

之前试验演示时使用的版本是v0.1.3，现在已经升级到v0.2.3，这已经相当于一个船新版本，安装包大小也从83M上升到106M。依然是同时支持Windows、Mac、Linux这3个系统平台，下载安装之后，启动程序，映入眼帘的就是一个登录框。

  

对的，**现在虽然依旧无需爬梯子翻墙，国人直接就可以使用，但是需要注册了**，之前是无需翻墙无需注册，直接就可以全功能使用的，官方给出的原因就是避免算力浪费。

  

![](assets/005.png)

  

有账号的话，点击Sign in登录就可以了（用自己的github账号也可以），**若是没有账号，点击Sign up注册一个，输入邮箱和设置密码就可以了**，同一台PC首次注册的时候，无需邮箱二次验证，注册第二个账号及以后就要验证了。

  

![](assets/006.png)

  

登录后便进入了主界面，整体风格跟VS Code如出一辙。

  

![](assets/007.png)

  

**三、菜单栏汉化更彻底**

Cursor在版本v0.2.1之后，**可以通过下载插件的方式实现菜单栏汉化，更符合国人的使用习惯。**

  

具体操作是，在主界面菜单栏中点击View选项卡，然后在下拉框中点击Extensions。

  

![](assets/008.png)

  

在弹出的商店搜索框当中输入“Chinese”进行搜索，选择简体(简体)语言包插件，点击右下角蓝色Install按钮安装。

  

![](assets/009.png)

  

插件安装完成后，会在主界面右下角出现弹框，点击“Change Language and Restart”蓝色按钮。

  

![](assets/010.png)

  

切换语言和重启后，整个汉化流程就完成了，重新再看菜单栏，全部变成中文了。

  

![](assets/011.png)

  

**四、软件用法和常见问题**

Cursor的核心用法并没有发生明显的改变，还是那么简单，只需要记住那两个快捷键就行了，一个是Ctrl+K，另一个是Ctrl+L。

  

**Ctrl+K(生成代码)：负责代码的生成和编辑，也就是在这里给它描述和布置编程任务以及后续的修改。**

  

**Ctrl+L(聊代码)：负责代码的说明、注释和理解，对于代码不理解和错误的地方，让它给你进行说明和改进。**

  

在量化交易当中的具体使用案例，请见之前的那篇文章[《做量化交易发愁写代码？一招教你白嫖GPT-4智能编程神器》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)，在此不再赘述，这里主要讲一讲小伙伴们经常反馈的2个问题。

  

**常遇问题1：在代码输出过程中，代码过长的话会中途截断，如何才能无法完整输出？**

  

在截断之后，继续快捷键Ctrl+K，输入“继续”或“continue”，代码就会继续输出，如果后续输出的代码没有结合上下文和之前代码对应的话，建议先让Cursor把编程任务拆分成多个模块，然后采用少量多次的策略，每次只输出一个模块的代码，降低被截断的概率。

  

**常遇问题2：快捷键Ctrl+L后，向Cursor提问，它总是用英文回复，即使在使用中文提问的情况下，如何才能使Cursor用中文回复？**

  

打个比方，咱让Cursor写一个夏普率的计算程序，它用英文来回复。

  

![](assets/012.png)

  

咱紧跟在它回答之后，输入“请用中文说明”，它就会把之前的回答改用中文回答，达成咱的目的。

  

![](assets/013.png)

  

**更简单的解决方法是，在每次提问时，显式要求Cursor使用中文回答。**

  

![](assets/014.png)

  

还有一个更加简单的偷懒办法，就是在主界面右上角的MORE选项卡中，指定在每次的指令都要默认加上“请使用中文回答”。

  

![](assets/015.png)

  

**五、软件收费，继续白嫖**

**跟ChatGPT一样，Cursor现在也开始收费了，也是20美刀一个月，但用户也是可以免费全功能使用，只不过有次数限制。**

  

Cursor每个账号的免费额度是每个月100次prompts，每次提问和写代码都算一次prompt，使用频繁的话，一天就可能用光了。

  

![](assets/016.png)

  

萌新们先别着急哈~在现有政策不变的情况下，还是可以继续白嫖的！

  

**因为现有政策的免费额度是针对单个账号的，每个账号是每个月100次，而申请一个账号只需要一个邮箱就可以了，即使你只有一个手机号，你在国内就可以申请非常多的免费邮箱（QQ、163、126......），然后再用这些邮箱去注册多个Cursor账号，你就可以使用这些账号的总和额度了。**

  

例如你每天使用非常频繁，你就注册30个免费邮箱，然后注册30个Cursor账号，每个月3000次prompts应该够了吧，不够的话再加，当一个账号免费额度用完之后就切换到另一个账号，如此循环往复下去，一个月一轮回。

  

这是新注册的一个Cursor账号，用了几次之后，查询一下额度使用情况，是用了7次prompts，在主界面右上角，点击齿轮图标，再点击Manage Settings可查看。

  

![](assets/017.png)

  

退出当前账号，换上另外一个新注册的账号，再查询一下，发现prompt使用次数为0，免费额度又是满满的。

  

![](assets/018.png)

  

这种循环使用免费额度的方式，只在当前Cursor收费政策不变情况下适用，土豪可以直接开20美刀的Pro账户省心省力，或者接入自己的OpenAI Key按调用成本使用。

  

**现在的AIGC工具日新月异，一天一个样，估计最终都会走向收费的商业模式，免费使用不易，且行且珍惜~**

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484812&idx=1&sn=1697b0ff17a7e48a56ddab441cb5dd84&chksm=c21ba603f56c2f15c3ded82ee3bf59027a997b25cf22535045743b6860b12fbfa379c54d5f04&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484822&idx=1&sn=39ac52116f314f52f8adb090e6dba782&chksm=c21ba619f56c2f0f6ba71de6526e7fe916088b9a18402ab09f27d01d003a459cc7b59755969b&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/019.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/020.png)