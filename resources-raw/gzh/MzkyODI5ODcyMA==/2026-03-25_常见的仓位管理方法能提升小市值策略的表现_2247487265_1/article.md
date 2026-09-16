# 常见的仓位管理方法能提升小市值策略的表现吗？

量化君 量化君也 2026-03-25 20:49 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247487265&idx=1&sn=13ab4ea876e9cdece9295f0c6ce92c4f&chksm=c32d70a0b1fbd43db3068e97c19c6d3b0bb95c6ce66d7a01dd35f24276e899343fc36f51b5d4#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487265&idx=1&sn=13ab4ea876e9cdece9295f0c6ce92c4f&chksm=c32d70a0b1fbd43db3068e97c19c6d3b0bb95c6ce66d7a01dd35f24276e899343fc36f51b5d4#rd)

![](assets/001.png)

  

有小伙伴问：为啥常见的小市值策略里面，选出股票后都是等权分配资金，有木有有效的仓位管理方法优化个股权重，提升策略表现呢？

  

我说：可以试一试~

  

于是乎有了今天的内容。

  

咱就拿带行业冥灯的菜场大妈策略作为基准吧，她是一个带择时功能的绩优小市值策略，详情请参考2月6日的文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487207&idx=1&sn=a5975e7dc6356200bbc76d606f9a45e6&scene=21#wechat_redirect)[菜场大妈提着行业冥灯，仿佛找到了低回撤途径](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487207&idx=1&sn=a5975e7dc6356200bbc76d606f9a45e6&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247487207&idx=1&sn=a5975e7dc6356200bbc76d606f9a45e6&scene=21#wechat_redirect)，先来回顾一下她的整体表现，这是纯用行业宽度择时的，没有加一月四月空仓过滤。

  

![](assets/002.png)

  

![](assets/003.png)

  

2019年回测至今，累计收益率是982.9%，年化收益是40.98%，夏普率为1.8905，最大回撤是17.14%。该策略从2月24日起就陆续遇到了银行、钢铁、煤炭这3盏冥灯，避险情绪浓重，发出了空仓不交易的信号，所以春节后整整一个月都在空仓，没赶上这两天的反弹，但也躲过了近一月下跌。

  

![](assets/004.png)

  

有了小市值基准策略，咱就在里面加入仓位管理模块试试，那用什么仓位管理方法呢？

  

那就用两个有名的吧，一个马科维茨，另一个风险平价，咱挨个儿说~

  

从解决仓位管理普适性问题出发，假设选股策略选出了n支股票S\_1~S\_n，给每支股票分配的权重分别是w\_1~w\_n，假设每支股票未来的预期收益分别为R\_1~R\_n，那么整个组合的收益可以表示为R=w\_1\*R\_1+w\_2\*R\_2+...+w\_n\*R\_n。

  

![](assets/005.jpg)

  

这个组合收益R就是所有仓位管理问题的起点，你希望组合收益呈现出一种什么样的状态呢？是风险一定的情况下收益最高，还是收益一定的情况下风险最小，还是组合里每个股票冒同样的风险，亦或是收益除以风险的夏普值更高~~

  

要回答这个问题，就要请出现代金融理论和资产组合理论的先驱马科维茨老爷子(Markowitz)，马老爷子1952年在其经典之作《Portfolio Selection》提出了均值-方差模型，创造性地将数学引入到金融投资领域当中，从数学层面上解决了资产选择和仓位分配的问题。

  

![](assets/006.jpg)

  

马老爷子凭借着对现代金融经济学理论的开拓性研究，以及提供了切实可用的金融资产收益与风险的衡量工具，获得了1990年的诺贝尔经济学奖。可惜的是，马老爷子2023年6月在圣地亚哥仙逝了，享年95岁，但留下的理论工具依然熠熠生辉。

  

咱这次要用到的就是其中的最小方差组合理论，要看懂的话真的不难，只要明白数学期望、方差和协方差的基本定理与性质就可以了。

  

马老爷子用投资回报的期望值表示组合投资收益率，也就是咱之前已经写出的表达式：R=w\_1\*R\_1+w\_2\*R\_2+...+w\_n\*R\_n；用组合收益R的方差(或标准差)表示组合收益的风险，那将R的式子代入到方差(Variance)的计算公式当中，则可以将式子展开成各个股票收益相关的表达式。

  

![](assets/007.png)

  

其中Var(R\_i)表示第i支股票收益率的方差，Cov(R\_i,R\_j)表示第i支股票和第j支股票收益率的协方差，特别地，Cov(R\_i,R\_i)=Var(R\_i)，如果不明白的话，度娘一下方差和协方差的计算公式就一清二楚了。

  

于是乎，展开式的第二行就统一用协方差表示，每支股票两两求协方差后与各自权重相乘，最终全部加总。菜场大妈策略是选10只股票，那对应的Var(R)展开是有10x10=100个子项。

  

为了表达的简洁性，最终表示为向量矩阵的乘积形式，其中W为n维列向量(w\_1,w\_2,...,w\_n)，左上角有个T是表示转置成行向量，Ω为股票之间收益率的协方差矩阵(nxn维)。

  

1xn维的列向量乘以nxn维矩阵，再乘以nx1维行向量，最终的结果是一个标量数值，就是整个组合的风险，咱就是希望找到这个最合适的权重向量W，使得整个组合风险最小化，形成方差/风险最小的投资组合。

  

![](assets/008.jpg)

  

怎么找到这个最优权重向量W呢？一般在量化实践当中，咱直接调用数学优化模块进行寻优处理，例如Python当中的scipy库的optimize模块，以Var(R)作为目标函数，给出对应的约束条件，然后它就会给你找出Var(R)最小值对应的那组权重。就跟你使用小龙虾OpenClaw一样，你给它描述任务、背景和条件，它就能给你提供解决方案并执行。

  

咱把马老爷子的最小方差模型在策略当中实现，用它来决定选股后每个股票的权重，再来跑一遍回测，新版本的回测绩效如下。

  

![](assets/009.png)

  

![](assets/010.png)

  

与基准策略比较，累计收益率从982.9%提高到1037.46%，年化收益从40.98%提高到41.98%，夏普率从1.8905提高到1.9674，最大回撤从17.14%降低到16.96%，有一丢丢的提升作用。

  

弄完最小方差模型，那咱接着弄风险平价模型，之前在全天候策略里面已经涉及到风险平价，详见文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486822&idx=1&sn=b93ba3b8ed5cd0d855d89d74fbbe5070&scene=21#wechat_redirect)[桥水基金全天候策略拆解，构建中国ETF风险平价版策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486822&idx=1&sn=b93ba3b8ed5cd0d855d89d74fbbe5070&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486822&idx=1&sn=b93ba3b8ed5cd0d855d89d74fbbe5070&scene=21#wechat_redirect)，为了方便表(tou)述(lan)，咱用之前的示例来解释大概的原理。

  

风险平价这个概念是磐安基金(Panagora)的钱恩平(Edward Qian)博士在2005年提出的，在论文《Risk Parity Portfolios: Efficient Portfolios Through True Diversification》中有一个生动形象的例子。

  

![](assets/011.jpg)

  

在传统的股债组合中，股票资产的权重是60%，债券资产的权重是40%，看上去资金是分散了，但实际上风险并没有有效分散，90%以上的的风险都集中在股票端。

  

具体是怎么得出这个结论的呢？咱来仔细计算一下~

  

股票端(Russell 1000 Index)的年化波动率是15.1%(标准差)，债券端(Lehman Aggregate Bond Index)的年化波动率是4.6%，它俩的相关系数是0.2。

  

那么，整个组合的方差波动率就是：

  

(60%)^2 × (15.1%)^2 + (40%)^2 × (4.6%)^2 + 2 × 60% × 40% × 0.2 × 15.1% x 4.6% ≈ (9.6%)^2

  

其中“x^2”表示的是x的平方，股票端贡献的方差波动率就是：

  

(60%)^2 × (15.1%)^2 + 60% × 40% × 0.2 × 15.1% x 4.6% ≈ (9.24%)^2

  

那么股票端的风险贡献占比就是(9.24%)^2 / (9.6%)^2 = 92.64%，也就是说，股票端的资金权重虽然是60%，但却贡献了将近93%的风险，资金权重40%的债券只贡献了7%的风险。这还是在论文当中用收益率方差衡量风险的情况下，如果用常用的标准差，股票端的风险占比更高，高达9.24% / 9.6% = 96.25%。

  

所以，这就是传统的按资金分配资产权重的问题，风险并没有被有效分散，钱博提出的风险平价就是来解决这个问题的，“风险分散才是真的分散”，每个资产带来的风险应当相同。

  

![](assets/012.png)

  

知道了风险平价的理念，那咱就来看看怎么根据风险平价，算出每个资产应该配置的权重。

  

咱假设投资组合当中有n个资产，第i个资产的权重为wi，第i个资产的收益率为ri，那么资产的权重向量(列向量)就是w=\[w1, w2, ..., wn\]，那么资产组合的收益就是rp = w1\*r1 + w2\*r2 + ... + wn\*rn，资产组合的波动率(代表风险)就是：

  

![](assets/013.jpg)

  

其中σij表示资产i和资产j之间的协方差cov(ri, rj)，σij=σji，特别地，当i=j时，σii = cov(ri, ri) = variance(ri) = σi^2，也就是资产i的协方差等于其本身的方差。

  

std(x)表示求x序列的标准差，Σ表示协方差矩阵，其中第i行第j列的元素就是σij，长下面这个样子。

  

![](assets/014.jpg)

  

接下来就是要计算边际风险贡献MRC(Marginal Risk Contribution)，它的金融意义就是对应资产权重wi变动1单位时，资产组合波动率σp变动多少，对σp求偏导。

  

![](assets/015.jpg)

  

那么资产i对总风险的贡献TRC(Total Risk Contribution)就是权重wi与边际风险贡献MRCi的乘积。

  

![](assets/016.jpg)

  

风险平价的目标就是让各个资产对组合总风险的贡献程度就是一样的，也就是TRC1 = TRC2 =…= TRCn，那么求解最优的权重w就可以转化为求解以下最优化问题。

  

![](assets/017.jpg)

  

因为在现实当中，是很难让每个资产的TRC相互之间完全相等的，只好让它们之间的相互差值的平方之和最小，也就是让它们之间尽量靠近，这种最优化问题还是用scipy库当中的minimize函数就非常容易求解了。

  

数学推导说完了，风险平价到底有没有用呢，咱把它加进原始小市值策略里面，再来跑一遍回测，绩效如下所示。

  

![](assets/018.png)

  

![](assets/019.png)

  

与基准策略比较，累计收益率从982.9%提高到990.62%，年化收益从40.98%提高到41.12%，夏普率从1.8905提高到1.9143，最大回撤从17.14%提高到17.19%，整体看也是有一丢丢丢丢的提升作用，但不及马老爷子的模型显著。

  

整体来看，马老爷子的最小方差模型和钱博士的风险平价模型都对原始的小市值有一定的提升作用，但没有预期中的显著。

  

究其能提升的原因，是因为这两个模型都会偏向于给低波动的股票更高的权重，这就是A股的第三个金融异象——“低波异象”：长期来看，低波动股票的收益整体要比高波动的股票要高，国外股市也是如此。

  

以最小方差模型为例，假设有三支股票，为了简单起见，假设它们之间两两不相关，也就是相关系数与协方差皆为0，那收益率的协方差矩阵就是对角元素为各自收益率方差的对角矩阵，那可以显式获得最优权重的解析解。

  

![](assets/020.jpg)

  

其中V\_i就表示第i支股票收益率的方差(风险)，从上面的式子可以看出，股票的权重与其方差成反比，波动越小，权重越高。

  

个人感觉，这两个模型都没有像它们在大类资产配置领域那样出色的表现，主要是因为它俩都是从波动风险角度出发，在同一种风格内做微调，小市值基本都是同涨同跌，无法利用多种风格之间的波动错峰抵消去熨平曲线，降低回撤，提高收益。

  

如果最终选出的股票组合里面除了小市值外，还有大市值，最好再有价值股、成长股、红利股等各种风格的股票，那用这两个仓位管理模型的提升效果就会显著很多，一定能提升收益不敢讲，但降低波动和最大回撤是杠杠滴。

  

量化很多时候就是这样，千辛万苦只能搞出来一点点进步，甚至有时候改出来的模型还不如原版，咱也算在小市值个股权重优化方面做出了探索，尽了绵薄之力，抛砖引玉，那下面是给想要进行测试和魔改的小伙伴说一下实盘参数的设置要点。

  

![](assets/021.png)

  

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

  

PRICE\_DN：股票价格的阈值下限，默认值为2.0，就是股价一定是大于2块钱。

  

PRICE\_UP：股票价格的阈值上限，默认值为9.0，就是股价一定是小于9块钱。  
  

PEG\_DN：股票PEG因子的阈值下限，默认值为-3.0。  

  

PEG\_UP：股票PEG因子的阈值上限，默认值为3.0。

  

WEEK\_DAY：每周第几个交易日进行调仓交易，默认值是1，表示一般是每周一进行交易，遇到节假日则顺延。  

  

MA\_LEN：计算行业市场宽度时所使用的均线长度，默认是20。

  
JINX\_INDU\_LIST：行业冥灯列表，空列表表示不过滤。默认是：银行，有色金属，钢铁，煤炭。

  

FILTER\_MONTH\_LIST：过滤月份的数值列表，\[1,4\]表示一月份和四月份空仓不交易，空列表\[\]则表示不对月份进行过滤。

  

WEIGHT\_METHOD：个股权重的计算方法，“equal”表示个股等权，“min\_variance”表示使用马科维茨的最小方差模型计算个股权重，“risk\_parity” 则是使用风险平价模型。

  
COV\_DAYS：计算最小方差模型或风险平价模型的协方差矩阵时所使用的交易日天数，默认是120。

  
MIN\_WEIGHT：个股权重下限，防止某支个股权重太低，资金量小时买不起1手，设为None时无下限约束，默认为5%。

  
MAX\_WEIGHT：个股权重上限，设为None时无下限约束，默认为20%。

  
TOKEN：因为这里用到Tushare数据源，所以这里要填入自己Tushare的token，关于如何在QMT当中安装tushare，详见文章[《](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[QMT自带的基本面数据这么拉胯，量化大神是怎么用它来实盘的](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)[》](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486971&idx=1&sn=90b6280117edbc7ac0b961d86670c1f4&scene=21#wechat_redirect)。

  

本次“菜场大妈行业冥灯策略权重优化版”的回测/实盘源代码，已经分享在『量化达摩院』社群当中，群友请原路径自取，还不会使用QMT进行策略回测和实盘的小伙伴，请参照社群知识库第二章的第3和第4部分进行操作。

  

![](assets/022.png)

  

根据之前的规则约定，带V1字样的是回测版，仅支持回测，主要是代码少，方便看策略逻辑，带V2字样的是回测实盘一体版，同时兼顾实盘和回测，方便对比回测实盘之间的差异，后缀py的是策略源码文件，rzrk是QMT当中的策略备份文件，在QMT中导入后，除了能看到源码外，还会带有策略回测时的各项参数，因此墙裂建议量化萌新通过rzrk导入的方式使用策略，会非常省心省力。

  
我是量化君，下期见~

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

![](assets/023.png)

![](assets/024.jpg)

风险提示：市场有风险，投资需谨慎。所有策略思路和策略源码仅供参考和学习，不构成投资建议，策略回测仅代表历史收益，不代表未来收益。