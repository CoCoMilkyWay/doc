# 利用chatGPT选了3支股票，验证未来收益率能否狂飙？

量化君 量化君也 2023-02-12 19:33 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c3619cf0eb11a225d29c2f89f9c835719d736086e9ebcdc5e03554f17739070b9bcedecc9923#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c3619cf0eb11a225d29c2f89f9c835719d736086e9ebcdc5e03554f17739070b9bcedecc9923#rd)

![](assets/001.png)

  

chatGPT在去年11年30日发布，最近火遍全球，短短2个月就坐拥1亿越活用户，这是很多人始料未及的。

  

刚发布不久，闲暇的时候，就爬梯子去调戏一下，有时就会把chatGPT有趣的回答po到群里或发朋友圈，那时的最大感受就是，这种问答类AI终于人工智能，不再是人工智障了。

  

![](assets/002.jpg)

  

最近老听说chatGPT能顶替一大堆职业工作，作为一名宽客（Quant），就也想看看是不是也把量化投资从业者的工作来顶替了，周末闲暇心血来潮胡思乱想，就先测试一下这家伙的选股能力这么样。

  

因为chatGPT的算法模型非常烧钱，训练一次的综合成本就要几百上千万美元，所以训练数据集就不会是每天增量迭代更新的，简单来说，**chatGPT是一个“离线版本”，不是“实时版本”，在模型训练完成后的事情肯定是不知道的，咱就让它预测之后发生的事情，就知道它的预测的能力怎么样了。**

  

经过多次询问，chatGPT的训练集数据截止到2021年，确切是哪个日期就死活不肯说了，那咱就只好“想当然”认为是2021年12月31日了。

  

![](assets/003.png)

  

这家伙不会说谎吧？慎重一点，巧妙试探一下，问一下它“是否知道俄罗斯和乌克兰爆发战争了”，虽然给了肯定的回复，但它知道的最近一场战争是发生在2014年，这说明它肯定不知道2022年的事情，这就放心了。

  

![](assets/004.png)

  

那就让它给咱选股票，开上帝视角来验证一下它的选股能力，WTF，神奇的事情发生了，它死活不肯选股，在它眼前挂萝卜都没用。

  

![](assets/005.png)

  

经过查阅资料得知，chatGPT是美国人工智能研究实验室OpenAI基于GPT-3.5（ Generative Pre-Training，生成式预训练模型）生成的，较上一代版本有一个明显的改进就是，**OpenAI提高了它的“安全性”，特别是禁止恐怖主义、暴力毒品、种族仇恨等言论相关的回应，看来投资这一块儿也被波及了，不让直接回应，开始慢慢吞吞说片汤话了。**

  

那只好往前倒了，看来要找到安全性低、警惕性不高的chatGPT才行了，这时就想到了OpenAI提供的GPT-3的API接口，简单来说，chatGPT=GPT-3改进优化+chat场景属性，如果说chatGPT是pro max版本的话，那GPT-3就是se mini版了，用人话不严谨来说就是，GPT-3是低配丐版chatGPT。

  

![](assets/006.png)

> 来源：国泰君安《ChatGPT 研究框架（2023）》

  

国内的chatGPT镜像站刚好用的就是这个GPT-3接口（OpenAI还没有公开chatGPT的API接口），因为chatGPT在国内还不提供服务，要使用的话需要爬梯子和国外手机号接收注册验证码，非常滴麻烦，为方便国人使用，有些服务商就建立了chatGPT相关公众号/小程序给国人使用，接收用户的提问，然后调用这个接口，再把结果返回给用户，由于这0.5代之差，造成了很多人觉得国内的镜像站比官方chatGPT要笨一些。

  

笨一些就笨一些，总比新版不能用强啊，于是找了一个能用这个接口的chatGPT镜像站（下文统称为“chatGPT(镜像)”），先来确认一下训练数据集的截止日期，是2020年12月31日，连2021年的数据都没用上，没事儿，不妨碍做选股能力验证。

  

![](assets/007.png)

  

顺道儿核实一下有木有撒谎~

  

![](assets/008.png)

  

**于是我就问它：从2020年12月31日到2023年2月10日，中国A股未来涨幅最大的3支股票是什么？**

  

果真还是年轻同志实诚，一点都不来弯弯绕，一点都不扭捏，**直接就给出了回复，这3支股票分别是中国平安、万科A和招商银行。**

  

![](assets/009.png)

  

到底选的股票咋样，把这3支股票和基准沪深300指数的收益曲线画出来对比一下，这里面只有招商银行跑赢了基准，其余两个都跑输了，如果期初等权买入并持有，最终收益率是-26.89%，沪深300指数期间收益率是-21.20%，连同期基准都没有跑赢。

  

![](assets/010.png)

  

结果看上去令人失望啊，**扩大到10支股票看看，它给咱选出了：中国平安、万科A、招商银行、中国石油、中国移动、浦发银行、建设银行、中国银行、中国建筑和中国人寿。**

  

![](assets/011.png)

  

统计一下期间的每支股票的收益率，看上去还行，除了top1和top2拉胯之外，后面的3~10名都跑赢了基准，相当于选股胜率是80%，如果当初等权买入并持有，最终收益率是1.46%，想对基准大概有20%出头的收益。

  

![](assets/012.png)

  

细心的小伙伴可能发现了，在回复当中出现了股票名称和股票代码不对应的情况，中国石油括号中的代码是600028，而600028是中国石化的代码，中国石油的代码是601857，同样地，中国移动括号里的代码是00941，而00941是港股的代码，在A股的代码应该是600941（在提问当中已经强调了是“中国A股”）。

  

中国移动是在2022年1月5日在A股上市的，如果要剔除新股的影响，剩余9支股票的最终收益率是-2.96%，也是大幅跑赢基准。

  

**看到股票名称和股票代码不对应的情况，这让我想到chatGPT是美国公司开发的模型，是一个老外模型，大部分数据应该都是英文语料，虽说是中国通吧，但应该更熟悉美股。**

  

于是，**针对美股进行提问，选3支未来涨幅最大的股票，于是它回复了苹果、微软和谷歌这3支股票。**

  

![](assets/013.png)

  

忽然一想，不对哦，提问美股，应该是要用英文提问，于是将中文转为英文。

  

![](assets/014.png)

  

还好，选出来的还是这3支美股，将它们和基准标普500指数的走势画出来，除了谷歌小幅跑输标普500外，其余2支股票都跑赢了基准，如果期初等权买入并持有，最终收益率是14.80%，标普500指数期间收益率是8.90%，大概跑赢6%。

  

![](assets/015.png)

  

**照例扩展到10支美股，它给咱选出了：苹果、微软、谷歌、亚马逊、特斯拉、英特尔、英伟达、美国银行、IBM和高盛。**

  

![](assets/016.png)

  

统计一下期间的每个美股的收益率，10支股票里有6支股票跑赢了基准，相当于选股胜率是60%，如果当初等权买入并持有，最终收益率是10.23%，只是略微跑赢了基准，都不到2%的超额收益。

  

![](assets/017.png)

  

综合选股胜率和超额收益率，如果选3支股票，chatGPT(镜像)选股能力是美股好于A股，如果选10支股票，则是A股好于美股。

  

**其实无论是A股还是美股，chatGPT(镜像)在这次试验中的选股能力表现，并没有大家想象的那么厉害，其中股票收益率最高能达到60%，但是也有大跌40%的股票，收益率最终都没能狂飙起来，可惜了~**

  

最根本的原因，是因为GPT/chatGPT只是一个自然语言处理模型，一般只处理文本数据，例如文章、新闻、问答等，一般知名度、热度、讨论度越高的公司，模型可能就认为是越好，简单来说，GPT/chatGPT选股只参考了舆情层面，没有考虑到基本面和量价层面，因此会有偏颇，就如同炒股不能只看消息面。

  

而且，一般越大涨的股票，讨论度和热度就越高，模型就可能认为是越好，越容易被选出来，追高挂旗杆的风险往往更大。

  

因此，就目前来看，chatGPT的直接选股能力是缺陷比较大的，chatGPT官方选不了，chatGPT镜像站选不好，估计一时半会儿还替代不了量化从业者的工作，不过用来辅助宽客编程还是挺不错的。

  

等到人工智能AI除了舆情之外，还可以驾驭基本面和量价层面的时候，量化从业者就面临失业的风险了，希望到时候咱能学会如何掌控AI的威力。

  

**重要提示：本文当中出现的具体个股，由chatGPT模型分析产生，仅用来验证模型选股能力，不作为任何投资建议。**

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484693&idx=1&sn=206e989a11eb814a6f29e5a2f0945d7f&chksm=c21ba69af56c2f8c7cc450e1c8213804d5abce293836435e7870251d6b3cffed7a169c86e2d4&scene=21#wechat_redirect)

[量化藏经阁2023](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484708&idx=1&sn=400f8f5a0f5bec22c3b3a82696cebbc5&chksm=c21ba6abf56c2fbdf53c0e2492b6017c0330b6e3affd8eb2c55382897371e054b224a5f5600a&scene=21#wechat_redirect)

\------量化策略------

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484138&idx=1&sn=d254513ad26c1872127bf7287b00d3f3&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

点我，让我们一路同行

吃瓜吐槽写代码

![](assets/018.jpg)

(微信号:iquantman)

添加好友后，私信『666』

送你一些量化小福利

人工回复慢请见谅~

  

![](assets/019.jpg)