# 量化交易笔试逻辑题答案揭晓，最后一题有七成人选错

量化君 量化君也 2023-05-09 07:27 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247485180&idx=1&sn=a6e51b9f94a57f15f8c5c68f5805b72c&chksm=c34c79c73d7b1593e405ea262f42391aeb03a1cc53659cd268d4ee18fdce72f7a4850aa93df5#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485180&idx=1&sn=a6e51b9f94a57f15f8c5c68f5805b72c&chksm=c34c79c73d7b1593e405ea262f42391aeb03a1cc53659cd268d4ee18fdce72f7a4850aa93df5#rd)

![](assets/001.png)

  

上一期的概率统计逻辑题的[文章](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485150&idx=1&sn=79a90ffe0161b7f8f78eb65febc71c83&chksm=c21ba551f56c2c4730c375271d378519801633436b59bb1ac43a26366284ab17a44156b418ae&scene=21#wechat_redirect)看了吧，文章发布后共有130+位小伙伴投票作答，大伙儿都很不错，前面两道题大部分人都答对了，只是最后一道题分歧非常大，答案的确是比较违反人性直觉，接下来详细唠唠每道题的答案和演算。

  

**一、策略选择**

先来回顾一下完整题目，话说，有两个相同交易频率的策略A和B，策略A的胜率是66.67%，盈亏比是1.5，策略B的胜率是33.33%，盈亏比是4.2，请问在经过相同时间长度的充分交易（例如交易10000次）后，哪个策略的预期收益更高？

  

其中，胜率 = 100% \* 盈利次数 / 总交易次数，盈亏比 = 平均单次盈利金额 / 平均单次亏损金额。

  

根据后台投票答案的统计情况，**80%的小伙伴都答对了这道题**，说明大伙儿的交易经验和数理逻辑都不错啊，的确是胜率33.33%、盈亏比4.2的策略B预期收益更高。

  

![](assets/002.png)

  

**这里只涉及到中学阶段里数学期望的知识，以及交易统计指标的解读，对于策略A，它每一次的交易有66.67%的概率赚1块5（也可以假设是其他数值，只要保证盈利和亏损的比例是1.5就行），同时有33.33%的概率亏损1块钱，所以它每次交易收益的数学期望是：0.6667\*1.5+0.3333\*(-1)=0.66675，每次交易的预期收益四舍五入是6毛7。**

  

**同理，对于策略B，它的收益数学期望是：0.3333\*4.2+0.6667\*(-1)=0.73316，大于策略A的0.66675。**

  

很明显，在同等情况下，策略B的预期收益更高，这也是很多趋势策略能盈利的核心基础，虽然趋势不常有，开仓胜率基本都在40%以下，但可以依靠高盈亏比将收益拉正，一次盈利可以将前几次亏损弥补。

  

这里顺道儿说一下用于策略选择时的“盈利系数”，它等于“胜率\*(1+盈亏比)”，大于1表示策略有正收益预期，小于1表示是负收益预期，而且数值越大，预期收益越高。

  

举个例子说明，对抛硬币游戏，如果硬币是没有动过手脚的规则硬币，那双方的胜率是五五开，在没有“抛硬币交易费”的情况下，赢了赚1块钱，输了亏1块钱，盈亏比就是1，那盈利系数就是50%\*(1+1)=1，在临界点上，预期既不赚钱也不亏损，解闷儿可以，玩多了也不赚钱。

  

如果每次抛硬币双方都要给硬币拥有者交1分钱的“交易费”，那赢了就是赚0.99元，输了则是亏1.01元，盈亏比则是0.99/1.01≈0.98，盈利系数则是50%\*(1+0.98)=0.99<1，长期玩下去双方都是亏损的，形成了只有“庄家”赚钱的局面，这就是“负和博弈”或是“负和市场”。

  

扯回正题，策略A的盈利系数为0.6667\*(1+1.5)=1.66675，策略B的盈利系数为0.3333\*(1+4.2)=1.73316，大于策略A的1.66675，因此策略B的预期收益也是越高的。

  

如果上面两种解释还是没有看明白的话，不要怕，我编了一段代码来对这道题进行模拟，如下。

  

```
import random
```

  

这里的关键是使用Python自带的random模块中的choice函数，来模拟随机交易的环境，random.choice(\[True, True, False\])表示从列表\[True, True, False\]中随机选择一个结果，True表示交易盈利，False表示交易亏损，可以看出这里模拟的是策略A的胜率66.67%，每3次交易有2次盈利，1次亏损，\[True, False, False\]对应的则是策略B的胜率33.33%。

  

运行程序，在经过10000次随机交易后，策略A总盈利为6622.5，策略B总盈利为7295.2，策略B的收益更高，这里要注意的是，因为每次的随机选择都不一样，所以每次的运行结果都不一样，但可以肯定的是，最终策略B的盈利曲线(黄色)都在策略A的之上。

  

![](assets/003.png)

  

**二、三门问题**

第二道题是著名的“三门问题”，不同时候的表述可能不一样，但内核都是一致的。

  

![](assets/004.png)

  

话说你参加了一个有奖问答游戏，面前有3扇门（A/B/C门），其中一个门后面有大奖，其他两个门是空的，你猜中哪个门后有大奖，就可以赢得大奖。

  

游戏进行流程如下：

  

（1）你先选择一个觉得后面有大奖的门（例如A门）；

  

（2）主持人知道每个门后面的情况，哪个门有大奖哪个没有，他在你未选择的两个门中（例如B门和C门），打开了一个没藏有大奖的门（例如B门），里面空空如也；

  

（3）主持人问你，是否要将最初选择的门（例如A门）和剩下没有打开的门（例如C门）换一下。

  

如果你是一个理性人，考虑选中的胜率，你会选择换掉最初选择的门吗？

  

**答案是“当然要换，换了可以提高胜率”，这道题的正确率虽然不如第一道题，但大部分小伙伴还是选对了。**

  

![](assets/005.png)

  

这道题的解题思路也很简单，你可以这样想，**假设你一开始就随意选择了A门，那可以把这仨门分为两个部分，一个部分就是你选择的A门，大奖在里面的概率是三分之一，另一个部分就是另外的两个门(B/C门)，大奖在这两个门里面的概率就是三分之二，主持人根据自己的已知情况，打开了其中一个空门，剩下的那个没开的门依然代表着这个部分三分之二的猜中概率，所以当然要换，猜中的概率能翻倍。**

  

如果还不够直观的话，咱把门的数量改成100个，大奖只在其中一个门后面，门的编号从1至100，假设你一开始选了1号门，紧接着主持人打开了2~87号和89~100号这98个空门，就剩下88号大门紧闭着，主持人问你要不要换成88号门，当然要换啦，为啥主持人打开了这么多空门，却唯独刻意避开88号门，用脚后跟想想都觉得有“猫腻”，你一开始选的1号门只有1%的概率猜中，而88号门则有99%的概率。

  

咱用程序来模拟一下，假设将这个三门游戏玩10000次，分别记录下不换门的人和愿意换门的人猜中大奖的次数是多少，源码如下。

  

```
import random
```

  

运行程序，几秒钟模拟完毕，最终的结果是，不换门者和换门者累计猜中次数分别为3326和6674，后者约是前者的两倍，与理论分析的结果一致。大伙儿也可以copy源码到自己电脑上运行，多运行几次，虽然每次的具体数值都和本文的不一样，但愿意换门的人猜中的次数肯定是比不换门的人高的。

  

![](assets/006.png)

  

**三、球队比赛**

**这道题最终的答案统计结果在我意料之外，将近七成的小伙伴没有答对，可能是因为真实答案比较违反人性自觉吧**，正确的答案应该是只投三分球、命中率66.67%的球队B赢面更大。

  

![](assets/007.png)

  

咱再来看一遍题目，好好地捋一捋。

  

话说有A、B两支球队，球队A只投两分球，百发百中，弹无虚发，命中率100%，球队B只投三分球，但准头差点儿，命中率66.67%（平均每投3个球能中2个），请问A、B这两个队伍打一场比赛，谁的赢面更大？

  

补充说明一下篮球规则，每个球队进球之后，都会由对方控球发球。其次就是，球队B会存在投篮不进框的情况，这种投了却弹框而出的情况叫篮板球，两个队的球员是要继续争抢的，控球后继续投篮，这里假设两个队伍的抢篮板能力相同。

  

球队A只投两分球，命中率100%，球队B只投三分球，命中率66.67%，从数学期望上来说，这两支球队每次出手(控球)都能斩获2分，关键是看在一场比赛当中，哪支球队的出手次数更多。

  

根据篮球规则，球队A进球后，就要轮到球队B发球进攻，由于球队A命中率100%，那球队A出手后，肯定是轮到球队B出手，形成类似“…AB…AB…”这样的出手序列。

  

**但是由于球队B的命中率只有66.67%，每3个球就投丢1个，存在抢篮板的情况，如果篮板被球队A抢到了，出手序列依然是“…AB…AB…”，而如果被球队B抢到了，则出手序列会变成“…ABB…ABB…”，也就是说，球队A出手后，肯定是轮到球队B出手，而球队B出手后，有50%的可能继续接着出手，A后面一定是B，B后面不一定是A。**

  

**因此，在一场比赛当中，球队B的出手次数预计要比球队A的多，所以球队B的赢面更大。**

  

也许说得是抽象了一点，咱拿程序来模拟，假设一场球赛当中总共有100次出手机会，先随机决定哪只球队首发。然后判断是哪只球队出手(控球)，如果是球队A，出手次数加1，直接得2分，换球队B出手；如果是球队B，出手次数加1，模拟球队B命中率是否进球，进球则加3分，换球队A出手，不进则抢篮板随机选择出手方，接着重复之前的流程，如此循环往复。

  

```
import random
```

  

在程序的输出结果中可以看到“…ABB…ABB…”出手序列的出现，正是这个导致球队B出手次数更多。

  

![](assets/008.png)

  

最终的运行结果是球队B的出手次数更多，得分更高。

  

![](assets/009.png)

  

如果到这里还没有理解的小伙伴，可以单步调试这个程序，实际感受一下两支球队的出手次数和比分的增加，Devils are in the details~

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485155&idx=1&sn=2c3159534dc114e97eaad77959dfe558&chksm=c21ba56cf56c2c7a6082a275be18cbb41ffdc173bfdd2b3459de6df13161c6ea419a4818056e&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485157&idx=1&sn=6b7f381f57b651b4df8e7b384e43400f&chksm=c21ba56af56c2c7cb15a3c7d66d6df27c41f714ad00a8f681fa8697be51b692dd48df9a69511&scene=21#wechat_redirect)

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

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/010.png)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/011.png)