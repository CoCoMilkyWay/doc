# 做量化交易发愁写代码？一招教你白嫖GPT-4智能编程神器

量化君 量化君也 2023-03-21 23:41 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c324c86882fd12416937347eb73b637ed1b7fcd1728977068d5925a2bbdeb6adcbb3c479c45d#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c324c86882fd12416937347eb73b637ed1b7fcd1728977068d5925a2bbdeb6adcbb3c479c45d#rd)

![](assets/001.png)

  

自chatGPT火遍大江南北之后，感觉AI领域就跟娱乐圈一个样，每天都有重磅大瓜可以吃。这不，最近几天又吃到一个蜜水直流的甜瓜，玩得停不下来，麻麻再也不用担心我的编程。

  

**它就是如今AI界逐渐火出圈的智能编程神器——Cursor**，多人反馈比GitHub Copilot还好用，是咱量化编程新手的福音，很多初级的编程任务都可以挥一挥衣袖轻松搞定，官网地址请撩：www.cursor.so

  

![](assets/002.png)

  

登录官网后就看到一句大大的slogan『Build Software. Fast.』，其下带有一行小字：Write, edit, and chat about your code with GPT-4 in a new type of editor。一目了然，从中就可以看出，**Cursor是基于GPT-4模型的编程工具，可以通过它生成、编辑以及和AI讨论分析代码。**

  

我这几天使用下来，它更多扮演的是一种助手的角色，你给它描述编程任务，它给你生成代码，如果你看不懂，它会给你一句一句翻译，如果代码运行出错，你把错误放在聊天框里面，它会回复是什么原因、怎么解决。

  

**最最关键的是，它目前所用功能的使用都是免费的，其次是不需要爬梯子翻墙，国人直接就可以使用，全程没有任何套路，甚至连注册都不需要！**

  

Cursor不是像chatGPT那样是在网页端直接使用的，而是要在官网上下载客户端，目前是支持Windows、MacOS和Linux三大操作系统，安装软件本体不大，只有80几兆。选择对应版本下载安装完成后，打开软件，来到暗黑色风格的类VS Code开发界面，整体非常简洁，菜单栏和图标也非常少，一股北欧极简风扑面而来。

  

![](assets/003.png)

  

Cursor的使用非常简单，只需要记住两个快捷键就行了，一个是Ctrl+K，另一个是Ctrl+L。

  

**Ctrl+K(生成代码)：负责代码的生成和编辑，也就是在这里给它描述和布置编程任务以及后续的修改。**

**Ctrl+L(聊代码)：负责代码的说明、注释和理解，对于代码不理解和错误的地方，让它给你进行说明和改进。**

  

打开Cursor后，默认情况下是已经打开PY的main.py文件和JS的main.js文件（如果没有，请从左侧文件列表手动打开），PY就是Python，JS是JavaScript，此外还支持C、C#和HTML等多种编程语言。

  

![](assets/004.png)

  

在量化交易领域，使用Python的人比较多，在此就以Python的自动化编程举例，咱先给它安排一个小任务看看效果如何，选中PY的main.py文件（或者自己新建一个py文件，此处我是新建了一个“MACD计算并展示.py”文件），让光标进入，按下快捷键Ctrl+K后，会在界面综上部弹出一个输入框，咱往里面敲入“使用tushare库获取贵州茅台从2018年元旦至2023年3月20日的行情数据，并计算MACD指标，最后要画图展示”。

  

![](assets/005.png)

  

输入完成后就点回车键Enter，然后编辑窗口就不断有代码生成，完整代码如下所示，要注意的是，每次输出的代码都是不同的，即使输入相同的prompt（提示词/关键，坊间俗称“咒语”）。

  

![](assets/006.png)

  

生成后记得点击保存，py文件默认会存储在路径“C:\\Users\\{你的用户名}\\cursor-tutor”对应的文件夹下（也许不同电脑不同操作系统不一样），你可以在终端执行这个py文件，或者直接将代码拷贝到你的IDE里面执行，例如Spyder、PyCharm等。

  

我在终端直接运行这个py文件，很幸运，除了提示我要升级tushare到Pro版之外，并没有其他错误，直接就把最终的行情和MACD图给画出来了。虽然横坐标看起来很“奇怪”，因为里面用了date2num函数将日期转化为天数，也就是距离1900-01-01有多少天。

  

![](assets/007.png)

  

如果萌新看代码不是十分理解，要添加注释，那可以全部选中代码，接着Ctrl+K，在输入框里输入“请给每一行代码添加注释”。

  

![](assets/008.png)

  

然后敲击回车键Enter完成，就会出现修改前后的代码对比。

  

![](assets/009.png)

  

接着点左上角的绿色“Accept”表示接受修改，这样就能给代码都添加上注释了，这样代码的可读性就更高了。

  

![](assets/010.png)

  

如果在看代码的过程中，觉得有哪里不懂的，可以开启“聊代码”功能，只需要使用快捷键Ctrl+L，在弹出的输入框里面输入你想问的问题，例如自己不清楚画图展示中第26行candlestick\_ochl函数，可以这样问。

  

![](assets/011.png)

  

敲击回车后，就会在界面右侧开启一个聊天小框，对你的问题进行回复，如果想继续了解，还可以继续提问，这就跟使用chatGPT是类似的了。

  

![](assets/012.png)

  

我当时发现可以这样聊天的时候，心想这不就可以同时白嫖chatGPT了吗？**谁知道Cursor还是太油腻太鸡贼了，除了编程相关的问题，其他问题都是一律漠视的。**

  

![](assets/013.png)

  

刚才咱不是说行情和MACD指标的画图里面横轴是数字吗，看起来怪怪的，咱来问一下Cursor该怎么修改，先选中画图的那部分代码，然后Ctrl+L，在弹出的输入框当中输入“我想让这段代码展示的图片里面，横轴是日期，请问我该如何修改？”。

  

![](assets/014.png)

  

Enter之后，开启聊天小框回答模式，详细回答了原因，以及如何进行修改，“虽然已经用date2num函数转换为数字，但最后可以用ax.xaxis\_date函数再转回为日期显示”。

  

![](assets/015.png)

  

将原来的代码注释掉，然后把回答当中的代码copy进来，一运行，发现真的可以，数字变回日期了，虽然只把年份显示出来，Cursor你真666~

  

```
import tushare as ts # 导入tushare库
```

  

![](assets/016.png)

  

上面只是一个量化分析小任务，咱还可以让它编写量化策略，例如让它基于backtrader编写一个双均线策略，prompt：基于backtrader，写一个贵州茅台的双均线策略，数据获取要基于tushare，并进行回测，本金是一百万，时间范围是2018-01-01至2023-03-20。

  

代码如下，原始代码结构和形式上都是完整的，但是tushare的数据与导入Backtrader的数据格式不对应，将日期列转为index后和设置格式后便可以正常运行。

  

![](assets/017.png)

  

```
import backtrader as bt
```

  

![](assets/018.png)

  

**相信看到这里，大伙儿应该明白了Cursor的用途和能力，从今往后，就可以把它当做是自己的编程助理，自己可以像领导那样，Ctrl+K给它布置任务，遇到不符合预期的地方，Ctrl+L让它解释和修正。**

  

虽然我已经觉得Cursor的编程能力已经不错了，但是多次的撩骚中发现它只使用了GPT-3模型，那官网首页说好的GPT-4呢？

  

![](assets/019.png)

  

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

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年116倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484971&idx=1&sn=b1406abf16c51e8f44d02182413bce2b&chksm=c21ba5a4f56c2cb2b43b76b539294677b0028c85d60a3543d502bcd5b869a01a6fbcdce39ac4&scene=21#wechat_redirect)  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/020.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/021.png)