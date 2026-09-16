# 上周或是检验择时量选产品质地的试金石

FundTalk Quantis因子工作室 2025-09-09 15:36

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzYzNTMwMzYyMQ==&mid=2247485508&idx=1&sn=2b24b3f7eef768725e6b72560739ba26&chksm=f11695e6e6061e6f8b89e97b7539a7a6cb7000a18f800d13e2fcd5a1a51b31803c4fddf1168f#rd](https://mp.weixin.qq.com/s?__biz=MzYzNTMwMzYyMQ==&mid=2247485508&idx=1&sn=2b24b3f7eef768725e6b72560739ba26&chksm=f11695e6e6061e6f8b89e97b7539a7a6cb7000a18f800d13e2fcd5a1a51b31803c4fddf1168f#rd)

  

  

上周市场剧烈震荡，上证综指一度从3885 的高点触及 3732 的低点，最大跌幅接近 4%，最后一个交易日虽然反弹 1.24%，但全周仍下跌约 1.2%。这样的行情，对任何股票多头策略而言都是一场不小的考验，而对于仓位择时的量化选股策略（简称“择时量选”），更是一次实时、无情且难以回避的“压力测试”。

  

我们搜集了一批主流择时量选产品的周度预估净值，结果颇为惊讶：周涨幅大致落在-4% 到 2% 的区间，表现方差极大。换句话说，同样号称“择时量选”的产品，在同一个市场环境下，有的净值出现大幅回撤，有的却能够相对坚挺，甚至实现正收益。为什么差异会这么大？

  

  

  

▲ 点击观看【Quantis因子工作室】原创短视频

  

  

**0****1****/**

基准仓位与产品定位的差异

  

  

首先要澄清一个前提：不同管理人对“择时量选”的基准仓位设定并不相同。

  

有些管理人将择时量选定义为比普通指增更积极的进攻型产品，基准仓位不仅接近 100%，甚至通过股指期货套保或两融加杠杆，将净敞口提升到 150%、200%。这样的产品追求高贝塔、高弹性，在上涨周期往往能跑赢绝大多数股票策略，但在本轮下跌中出现大回撤也就不奇怪了。

  

然而，高杠杆并不是我们今天讨论的重点。我们更想聚焦在基准仓位0%-100% 之间、杠杆水平相对温和的产品，探讨为何它们的周度表现也会有如此大的分化。

  

  

**0****2****/**

**管理规模与调仓频率的权衡**

  

  

第一个重要原因是管理规模。随着资金管理规模的扩张，策略在执行层面会遇到流动性约束，高换手可能带来显著的冲击成本和滑点损失。

  

为了减轻不必要的“来回折腾”——即频繁增减仓导致的磨损，很多管理人在策略迭代上选择降低调仓频率。

  

这是一种理性的取舍：降低换手能提高组合的容量和执行的稳健性，让策略可以承载更大规模的资金。然而它的代价也很明显——仓位调整的敏感度下降。当遇到像上周这样突然的市场急跌时，降频后的模型很难在第一时间减仓避险，往往需要等到信号确认才行动，结果就是损失更多的回撤空间。

  

![](assets/001.jpg)

  

这种“船大难掉头”的现象，在量化行业里并不少见，也是一种典型的规模效应。小规模策略可以“灵活机动”，几乎每日都能调整仓位甚至做 T，而大规模策略则更倾向于保持仓位稳定，牺牲部分短期敏捷性换取更低的交易成本。

**0****3****/**

**选股特征与风格暴露**

  

  

第二个原因是管理人的选股因子和风格暴露。择时量选并不仅仅是“择时”，它同样包含了“选股”逻辑。前期如果模型更偏好基本面因子、盈利预期、成长因子，那么在 8 月份捕捉到成长股的上涨行情就不足为奇，也正是这些组合在 8 月超额表现并不差。但成长因子的一个天然特征是更高的 Beta，当市场下跌时，它们的回撤幅度往往更大。

  

相反，那些前期配置红利、低波因子或微盘风格较多的产品，在8 月可能表现平平，甚至落后，但到了上周这种剧烈震荡的环境中，反而更抗跌，组合净值回撤相对温和。

  

![](assets/002.jpg)

  

这实际上说明择时量选产品的收益表现，很大程度上是“择时”和“选股”两个维度共同作用的结果。如果择时没有及时降仓，同时选股暴露在高 Beta 风格上，回撤就会更大；如果择时和选股同时偏防御，则有可能在下跌中相对占优。

**0****4****/**

**策略组合的对冲效率**

  

  

![](assets/003.jpg)

  

第三个原因来自策略组合层面。大量择时量选产品并不是纯股票多头，而是“股票多头 + 股指 CTA” 的组合结构，期望通过股指 CTA 在系统性风险来临时提供一定对冲，平滑净值曲线。然而最近股指 CTA 策略本身出现了较为显著的回撤，不仅没起到对冲作用，反而对组合净值形成了负贡献，加剧了整体回撤。  

  

关于近期股指CTA的回撤问题，我们会另外单开文章进行分析，在此不再赘述。

  

这一点其实揭示了一个更深层次的问题：在极端市场下，策略组合的相关性假设可能会失效，本来被设计成“风险缓冲”的部分，反而变成拖累。

  

**0****5****/**

**怎样的产品才算优秀？**

  

  

什么样的择时量选才算“优秀”？其实没有标准答案，取决于投资人对产品的定位。如果投资人把它当作高弹性的进攻型配置，就必须接受更大的净值波动；如果把它当作绝对收益工具，就应期待它在市场急跌时提供一定的防御。

  

就我个人而言，我更希望择时量选是一款能够长期提供高夏普率、具备一定绝对收益特征的产品。在理想状态下，它应该在维持较高换手、保证灵活性的同时，在上周这样的急跌中尽量少亏，如果能轻微赚钱就更好。

  

毕竟，择时的意义之一，就是在大盘情绪极度悲观时替投资人减轻痛苦，而不是“陪着一起下跌”。

  

  

  

  

  

  

**粉丝·了解更多内容**

  

想了解更多内容，关注后续路演安排。

**请添加知识星球以及小助理微信**。****（路演内容需提供合格投资者材料，近期会逐步提价，欢迎尽早加入知识星球）********

  

![](assets/004.png)

![](assets/005.jpg)

![图片](assets/006.png)

▼

**Selected**

**往期文章**

****[红利增强不是红利ETF的平替，而是稳定中的进攻型主力](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484476&idx=1&sn=6480de76a7c087f2288909b6de697ade&scene=21#wechat_redirect)****

****[同样是消费，不同的主观却有不同的投资理念](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484460&idx=1&sn=850aecb5873960e6500baeecefb08ef8&scene=21#wechat_redirect)****

  

**[转债研究系列之二：因子开发与因子评价](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484459&idx=1&sn=bc96c9d0cfd2f241f7b9b0a7a80e6f3a&scene=21#wechat_redirect)**

**[转债研究系列之一：转债多因子策略开发全景图](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484435&idx=1&sn=b24a85e8c2e98ded2c932b06d6f95c37&scene=21#wechat_redirect)**

**[红利增强策略中，又杀出一匹黑马？这家管理人到底有何“招式”？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484424&idx=1&sn=81130ed82a717bbfb95bd22a060d53d4&scene=21#wechat_redirect)**

**[从过去5年杠铃组合的表现，我们发现了什么特点](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484395&idx=1&sn=e1f9bdc4efa3fcaaaf4babb9899bf803&scene=21#wechat_redirect)**

**[一边风格轮动，一边扫板打板：这家管理人如何玩转两个极端？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484383&idx=1&sn=9029b0a5ec0143880405278a2976f9fd&scene=21#wechat_redirect)**

**[解密年化76%的“利刃”：这家私募的量化秘籍](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484277&idx=1&sn=cc293f06f778eef2d186c65f8fe23f07&scene=21#wechat_redirect)**

**[市场暴涨，而你的股指CTA却在亏钱？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484268&idx=1&sn=8d7649cd4d9f3db18d02bd73a86ca7fb&scene=21#wechat_redirect)**

**[别再迷信景气轮动了！残酷真相：能持续做到的基金经理几乎不存在](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484254&idx=1&sn=5087720c71627a89d051f5c58a49628c&scene=21#wechat_redirect)**

**[3700了，该如何调整FOF组合的多头头寸](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484242&idx=1&sn=976b9c570ba7a3cea404f0f4c607e8fa&scene=21#wechat_redirect)**

**[如何配置主观价值股票管理人](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484222&idx=1&sn=e5189250333fb770e7c5b23f837664a5&scene=21#wechat_redirect)**

**[回撤10%以内，年化27%+：一家“非主流”主观私募的7年生存法则](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484194&idx=1&sn=ba7797d24f7664084664352c3bee8bfa&scene=21#wechat_redirect)**

**[FOF投资中关于“分散风险”的三个真相](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484150&idx=1&sn=b4b20bcb790b676d8dae0d51124a408e&scene=21#wechat_redirect)**

**[【稀缺】这家公奔私的管理人：绝对收益策略，收益100%来自择时](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484080&idx=1&sn=3716d1c3054f4fe33fee9fe1f44bd216&scene=21#wechat_redirect)**

**[【重磅】这家基金量化全天候策略深度解析：两年88%收益的“抗波动神器”是如何炼成的？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484069&idx=1&sn=358f6b430b03273a3ae073ebaf0e2f13&scene=21#wechat_redirect)**

**[不妨考虑用量化转债平替500指增](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484067&idx=1&sn=49772d5a0166195a8e64d95291c7285a&scene=21#wechat_redirect)**

**[择时胜率能代表量选管理人的水平吗？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484022&idx=1&sn=247622468d511435b85013821b5626e5&scene=21#wechat_redirect)**

**[买私募三看：看清你买的是个什么鬼？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247484010&idx=1&sn=2145297087fa94a4cb3bf02ddf2dde22&scene=21#wechat_redirect)**

**[高胜率跟高赔率，可以兼得吗？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247483901&idx=1&sn=ff6af70af6aabd5940c193baabd60788&scene=21#wechat_redirect)**

**[贴水收敛，中性策略这周会赚钱吗？](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247483852&idx=1&sn=ebc96fefdb44dddab8760704f7b404ff&scene=21#wechat_redirect)**

**[股指CTA与商品CTA的本质区别与开发思考](https://mp.weixin.qq.com/s?__biz=MzkzMDk1OTU3MQ==&mid=2247483808&idx=1&sn=bd2579c04f5c9706147d30f435611d75&scene=21#wechat_redirect)**

****THE QR CODE****

**感｜谢｜关｜注**

![](assets/007.jpg)

![图片](assets/008.png)

  

商务合作/转载请留言我们

Business cooperation please leave us a message

  

  

****喜欢就点个** **在看** **吧** ↓↓↓**