# 怎么区分Alpha因子和风险因子？

量化君 量化君也 2023-01-05 21:08 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&chksm=c38de02d450ba3288846d4f800fc0e26d00ad720e9896af32bee8391889a01e7c46f0a8ff398#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&chksm=c38de02d450ba3288846d4f800fc0e26d00ad720e9896af32bee8391889a01e7c46f0a8ff398#rd)

![](assets/001.png)

  

『打开天窗说量化』是一个絮絮叨叨的专题系列，跟大伙儿唠一唠量化相关的小问题，有感而发写到哪算哪，这是第3期，来唠个14块钱的~

  

不知大伙儿有木有这样的疑惑？

  

> 看到Barra里面有Size、Liquid等因子，这些因子同样出现在很多人的Alpha模型里面，这Alpha模型里面到底该不该放风险因子？怎么区分这两者？

  

首先要说的是，无论是Alpha因子，还是风险因子，它们都是『因子』，为什么有『因子』这一说呢？

  

那是经济学家金融学家们研究发现出来的关键因素，这些因素对股票价格涨跌有显著的影响作用，从资本资产定价模型CAPM中的市场收益率，再到Fama-French三因子和五因子模型，这些因子都是用来解释个股收益率的，Barra当中的因子就更多了。

  

![](assets/002.png)

  

也就是说，Alpha因子也好，风险因子也罢，这些因子在横截面上对股价的涨跌都有良好的解释能力，更具体地用数学描述，就是当期因子值与股票下期收益率之间呈现强相关关系（IC值显著不为0）。

  

**横截面上，Alpha因子和风险因子是相同的，它们不同之处就在于时间序列上，Alpha因子方向和收益稳定，能源源不断带来投资收益，风险因子方向和收益不确定，有非常大的不确定性，给投资带来风险。**

  

这里的『因子收益』指的是个股收益对因子值进行线性回归后的回归系数，以下公式当中r是个股收益率，x是因子值，f就是因子收益，表示1单位的因子暴露能给个股带来多少收益，每个月（其他周期也可以）都可以计算一次，就能形成因子收益的时间序列。

![](assets/003.png)

  

最理想的Alpha因子长什么样呢？它的因子收益的时间序列长得跟下图一样，因子的方向和收益率都非常稳定，每一期的因子方向和收益都是可以预测的，根据这个因子正向选股就可以了，就跟有稳定的内幕消息一样，钱哗啦啦地流进口袋。

  

  

![](assets/004.png)

  

但是现实当中哪有这么完美嘛，方向大部分时间稳定就可以了，因子收益不要太小就可以了，因子收益序列如下所示，只要长期坚持根据这个因子正向选股，还是可以获得不菲的投资收益。

  

![](assets/005.png)

  

> BTW，Alpha因子方向稳定就可以了，不一定是要正的，稳定的负向也是可以的，这就是常说的“负Alpha因子”，就好比说你知道一个因子，根据它来选股，这个股票价格一定是下跌的，只要能够融券做空，一样可以哗哗赚钱。

  

风险因子就跟Alpha因子在时间序列上有很大的不同，最主要的差别就是因子方向飘忽不定，令人难以捉摸，无法预测，你都不知道该根据因子值正向选股呢，还是反向选股呢，因子收益序列大概长这样。这样的因子可以用来解释股价，说说这个时间段个股为什么上涨，那个时间段为什么下跌，但很难用来预测，赚取超额收益。

  

![](assets/006.png)

  

Alpha因子和风险因子的区别说完了，那为什么这两类因子出现混用呢？也就是开头说的“看到Barra里面有Size、Liquid等因子，这些因子同样出现在很多人的alpha模型里面，这Alpha模型里面到底该不该放风险因子？”

  

这就涉及到因子的演化了，**因为曾经的Alpha因子会失效，沦落为风险因子；风险因子也可以在某个时间段比较支棱给力，呈现出Alpha打鸡血的状态，被人放进Alpha模型当中。**

  

我给大家贴一个2003年时候的美国股市的Alpha因子列表，上面赫然写有“小市值”，跟我国A股2017之前一样，小市值历来都是Alpha因子，只是后来失效了，成为了风险因子，但是最近又支棱起来了。

  

![](assets/007.png)

  

![](assets/008.png)

  

Alpha模型当中当然可以放风险因子，就如同现在很多选股模型当中依然有小市值因子一样，一个因子是否被放入选股模型当中，并不取决于它是Alpha因子，还是风险因子，只取决于自己是否能“掌控”它？掌控，那又是另一个很长的故事~

  

**参考资料：**

_石川、李腾、flyerye等，知乎问题《怎么区分 alpha 因子和风险因子？》的回答_

_Berry Cox，2003.11，《Equity Factors and Portfolio Management: Alpha Generation Versus Risk Control》_

_冯佳睿，2017.08，《引入风险管理后的多因子选股框架与指数增强策略》_

  

★

往期回顾

  

★

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [量化兵器库](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&scene=21#wechat_redirect)

_Tip：点击关键字可以直接查看对应文章。_

  

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/009.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

![](assets/010.png)