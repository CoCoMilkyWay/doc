# 能力有限，主打听劝，北交所小市值最高年化83%

量化君 量化君也 2025-12-05 11:29 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487020&idx=1&sn=537b2be9fd7f477ad00c29acc00603e2&chksm=c3e4d160b2f606a7cde22fc490170eb268c587bc258bf097e1fa9c3125582d1a6b8d8721b782#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487020&idx=1&sn=537b2be9fd7f477ad00c29acc00603e2&chksm=c3e4d160b2f606a7cde22fc490170eb268c587bc258bf097e1fa9c3125582d1a6b8d8721b782#rd)

![](assets/001.png)

  

前些天，出于多重验证和可实盘性的考量，在QMT上复现了聚宽蒋老师的小市值策略，虽然未能再现年化收益100%的辉煌，但即使从现在的眼光来看，也是一个非常不错的基础策略，可挖掘可优化的地方还有很多，详情可见之前的文章[《曾经年化100%，为什么如此简单的策略，能在圈子里火5年？》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486987&idx=1&sn=0f579a3f60c04ceef86b2c2565002c9d&scene=21#wechat_redirect)。

  

那篇文章发出去后，陆续有几个小伙伴找我，问能不能把这个策略挪到北交所上，心想，那个策略逻辑是公开的，在代码里面把指数成分股换成北交所股票池不就好了，他们说了目的后，我才想起来，聚宽至今未支持北交所股票，也就是说，即使手握蒋老师的策略源码，在聚宽上也回测/实盘不了北交所的小市值策略。

  

![](assets/002.png)

  

这些小伙伴的出发点和想法都是不错的，不同国家/地区/市场的周期都是有错位的，有的人喜欢在老市场用新策略，有的人喜欢在新市场用老策略，无论是量化交易还是实体生意，之前很多人把非常老旧的CTA策略移植到B圈都取得非常亮眼的战绩，越早期越无效的市场越容易摸到大鱼，北交所30%的涨跌停板着实吸引人，又比如前两天上热搜的“越南炒房”，在天朝已经凉凉的场景，在别处却是方兴未艾。

  

![](assets/003.png)

  

![](assets/004.png)

  

漂亮国尤金·法玛和肯尼斯·弗伦奇在1993年提出的Fama-French三因子模型当中，就已经有小市值因子的身影了，想不到30多年后，小市值策略仍然是中国个人宽客用得最多的策略类型之一。个人看来，小市值因子的超额收益来源主要有3方面。

  

第一就是小微盘股的壳价值，A股不是你说想上市就上市的，要IPO排队，要过五关斩六将，即使运营不善的上市企业也想着保壳，因为这个壳的价值不菲，一旦将来被借壳成功了，身价能翻好几番，这层壳的溢价，就是小市值的超额底色。一旦证监会放开IPO，交份材料，填个报表，阿猫阿狗都可以上市，那小市值的超额收益铁定大打折扣。

  

第二就是风险溢价，小微企业自然没有大企业的业务模式成熟、现金流稳定，那投资小微盘股的风险就比大盘股的风险大，那风险越大，那对应的收益就越高，正所谓风浪越大、鱼越贵，如同企业债的票面利率肯定要比国债高，不然谁买啊。并且，现在股票越来越多，小微票研究的人没那么多，研究覆盖率低，信息差带来强大的超额潜力，小微盘股更容易做出超额。

  

第三个就是流动性溢价，小微盘股基数小，成长性强，容易讲故事拉预期，再加上流通股本少盘子小，拉动的资金不需要太多，大大迎合了游资和机构的炒作，但凡有什么主题概念都容易把股价拉起来，股民再跟风炒作就不要太爽哦，特别是在整个市场没有什么增量资金的情况下。

  

如果有人认为以上逻辑在沪深A股成立，那么，在北交所A股里应该也是大概率成立的，所以就会尝试将沪深A股表现不错的小市值策略迁移到北交所上，但苦于平台和数据无法实现。

  

既然他们找到了我，本人还是很听劝的，听人劝吃饱饭嘛，也不是啥难事儿。QMT平台刚好有北交所行情数据，也支持北交所股票的回测和实盘，再加上Tushare的辅助，把之前的小市值策略改改就可以了，我就帮大伙儿把北交所的小市值策略回测一下，分别测试了选股5支和10支，以及是否做一四月过滤。

  

北交所是2021年11月15日正式开市，首批上市的是81家企业（目前是286家），但考虑到初期流动性不佳等原因，没有选择这天作为回测的起始时间点，而是参考了北证50指数，选择2022年5月1日作为回测的起始日期。由于北交所股票交易时的规费比较高，因此考虑到现实和简单方便，在回测时，把交易佣金和印花税都设置为千1，北交所小市值策略的回测绩效如下所示。

  

北交所小市值选股5支，无一四月过滤

![](assets/005.png)

  

![](assets/006.png)

  

北交所小市值选股10支，无一四月过滤

![](assets/007.png)

  

![](assets/008.png)

  

北交所小市值选股5支，有一四月过滤

![](assets/009.png)

  

![](assets/010.png)

  

北交所小市值选股10支，有一四月过滤

![](assets/011.png)

  

![](assets/012.png)

  

从回测结果当中看出，在不做一四月过滤时，效果最好的是选股10支，年化收益率达到了83.62%，夏普率为1.48，最大回撤为38.19%，选股5支的效果要差一些，年化收益率为71.41%，夏普率为1.17，最大回撤为37.46%。

  

做一四月过滤时的回测结果也是类似的，选股效果最好的也是选股10支，年化收益率为69.23%，夏普率为1.34，最大回撤为43.68%，选股5支的效果也是要差一些，年化收益率为60.21%，夏普率为1.08，最大回撤为42.75%。

  

从中咱可以看出，北交所小市值跟沪深小市值的一些不同之处。

  

（1）沪深小市值一般是选股数目越少，策略收益越高，北交所小市值10股效果要比5股好，说明北交所并非市值最小的效果最好。

  

（2）一四月过滤在北交所小市值策略当中，既不能提高收益，也不能降低回撤，月份过滤至少在沪深小市值当中能降低回撤。

  

（3）北交所小市值收益曲线呈现出阶跃跳升的形态，大部分收益都是来自于那几个月的爆发，看起来没有沪深小市值的持续性好。

  

究其形成的原因，一是相较沪深A股而言，北交所股票现在还属于发展的初期阶段，并且制度与沪深A股存在差异，二是投资者结构，北交所的投资门槛是要求账户里有50w资金，而这就大概过滤了大部分的个人投资者，因为根据中登公司和交易所披露的投资者账户统计数据，个人投资者账户分布情况如下，超过9成账户的资金量在50w以下。

  

![](assets/013.png)

  

北交所小市值策略回测的情况说完了，回测的时间跨度只有3年多，不算长，如果有想要继续深入探究的小伙伴，下面我给你们说一下实盘参数的设置要点。

  

![](assets/014.png)

  

ACCOUNT\_ID：就是你自己的股票账户的资金账号，回测的时候可以不填或乱填，实盘的时候一定要填自己正确的账号。

  

ACCOUNT\_TYPE：因为要使用股票账户进行交易，所以该参数固定为“STOCK”。

  

ACCOUNT\_MODE：就是你打算用多少钱来跑这个策略，可选值为MONEY和RATIO。选MONEY就表示按照ACCOUNT\_MONEY设定的金额，选RATIO就表示使用总账户ACCOUNT\_RATIO那么多比例的资金。

  

ACCOUNT\_MONEY：策略金额，单位是“元”，根据自己的资金情况设置。

  

ACCOUNT\_RATIO：占总账户资金的比例，数值在0~1.0之间，0.3表示占30%比例。

  

STRATEGY\_TRADETIME：策略进行交易的时间，因为该策略是日线策略，一天那么长，所以需要指定一个具体的时间进行下单交易。

  

ORDER\_TIMEOUT：订单超时时间，默认是60秒，下单后超过60秒没有全部成交就是超时，策略程序会自动检查出超时的委托单，然后撤单重下。

  

STRATEGY\_PATH：策略相关文件的存储路径，策略程序会在STRATEGY\_PATH这个路径底下再新建一个名为STRATEGY\_NAME的文件夹，策略相关的持仓文件和交易日志文件都会保存在这个文件夹底下，这些文件是做仓位隔离和信息回溯的关键。

  

STRATEGY\_NAME：策略名称，一旦开启实盘之后，策略名称不要随意修改，不然就无法识别策略持仓文件，如果在盘中修改然后重启策略的话，就识别不了修改之前下的委托单和成交单。特别说明就是，策略名称除了中文和英文之外，不要含有任何特殊字符，不然就无法正确识别券商柜台的委托回报。

  

SELECT\_NUM：每一次选择多少支符合条件的股票作为目标持仓，这里默认是10支。

  

FILTER\_MONTH\_LIST：过滤月份的数值列表，\[1,4\]表示一月份和四月份空仓不交易，空列表则表示不对月份进行过滤。

  
TOKEN：因为这里用到Tushare数据源，所以这里要填入自己Tushare的token，关于如何在QMT当中安装tushare，详见文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[QMT自带的基本面数据这么拉胯，量化大神是怎么用它来实盘的](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)。

  

本次北交所小市值策略的回测/实盘源代码，已经分享在『量化达摩院』社群当中，群友请原路径自取，还不会使用QMT进行策略回测和实盘的小伙伴，请参照社群知识库第二章的第3和第4部分进行操作。

  

![](assets/015.png)

  

根据之前的规则约定，带V1字样的是回测版，仅支持回测，主要是代码少，方便看策略逻辑，带V2字样的是回测实盘一体版，同时兼顾实盘和回测，方便对比回测实盘之间的差异，后缀py的是策略源码文件，rzrk是QMT当中的策略备份文件，在QMT中导入后，除了能看到源码外，还会带有策略回测时的各项参数，因此墙裂建议量化萌新通过rzrk导入的方式使用策略，会非常省心省力。

  
我是量化君，下期见~

* * *

★

往期回顾

  

★

  

\------量化社群------

  

[量化达摩院](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486732&idx=1&sn=982268f4b3e9bbf2dfcebe9221759dc0&scene=21#wechat_redirect)

[量化藏经阁Max](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486489&idx=1&sn=7d7d3bed4d6f78c5e9477a7601a49864&scene=21#wechat_redirect)

[量化藏经阁2025](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486497&idx=1&sn=17a679999c0b3aeaf1c0d421f0533a8b&scene=21#wechat_redirect)

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

![](assets/016.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/017.png)

  

风险提示：市场有风险，投资需谨慎。所有策略思路和策略源码仅供参考和学习，不构成投资建议，策略回测仅代表历史收益，不代表未来收益。