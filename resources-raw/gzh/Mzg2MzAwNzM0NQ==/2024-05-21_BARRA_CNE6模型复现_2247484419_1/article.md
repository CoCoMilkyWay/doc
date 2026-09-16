# BARRA CNE6模型复现

QuantML QuantML 2024-05-21 15:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=cff62c3cd0103cc17af85806dec509a02f41c5273babb1044a4e4c74594f28a13ab97ecbb177#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=cff62c3cd0103cc17af85806dec509a02f41c5273babb1044a4e4c74594f28a13ab97ecbb177#rd)

Content  

  

本文来自星球嘉宾的Github项目：ShiliangZhang-nku/Barra\_CNE6: Barra CNE6 因子构建 (github.com)。

项目复现了Barra CNE6的因子计算，欢迎加入星球交流。

BARRA CNE6项目是由MSCI公司开发的中国权益市场风险模型，正式名称为The Barra China Equity Model，简称CNE6。是继CNE5之后的升级版本，旨在更精细地预测和解释中国股票市场的风险，对中国A股的风险评估、组合优化和量化策略产生了积极且广泛的影响。

CNE6模型采用了多层次的因子体系，包括国家因子、行业因子以及多个风格因子。模型考虑了市场中所有股票的因子暴露和个股收益率，通过构建截面回归来获取收益率和特质收益率。CNE6模型能够更高效准确地捕捉横截面上机构头寸在各种因子上的暴露，并且当模型中纳入具有时序记忆的变量时，它可以共享截面回归和时序回归模型的一些优良性质。

与CNE5相比，CNE6模型在因子数量和因子合成方式上都有较大改变，将因子进一步细分和扩充，构建了包括9个一级风格因子，20个二级基础因子，46个三级因子的三层风格因子体系。在合成计算9个一级因子时，对于二级和三级因子均采用等权方式。

CNE6模型还引入了截距项，使得市场因子从行业因子中剥离出来，从而得到纯净的风格因子收益。这种改进有助于投资者更清晰地识别和评估不同因子对投资组合风险和收益的贡献。

![](assets/001.png)

因子具体定义如下：  

  

**一级因子**

**二级因子**

**三级因子**

**说明**

**因子定义**

Size

Size

LNCAP

规模

流通市值的自然对数

Mid cap

MIDCAP

中市值

首先取Size因子暴露的立方，然后以加权回归的方式对Size因子正交，最后进行去极值和标准化处理

Volatility

Beta

BETA

贝塔

股票收益率对沪深300收益率进行时间序列回归，取回归系数，回归时间窗口为252个交易日，半衰期63个交易日

Residual

Volatility

Hist sigma

历史sigma

在计算BETA所进行的时间序列回归中，取回归残差收益率的波动率

Daily std

日标准差

日收益率在过去252个交易日的波动率，半衰期42个交易日

Cumulative range

累积收益范围

为过去T个月累积对数收益率（每个月包含21个交易日），即

其中为股票在月的收益，从而定义累积收益范围如下：

其中,

Liquidity

Liquidity

Monthly share turnover

月换手率

对最近21个交易日的股票换手率求和，然后取对数，即：

其中为股票在t日的成交额，为股票在t日的流通市值

Quarterly share turnover

季换手率

为_τ_月的换手率（每月包含21个交易日）季换手率定义为：

T=3个月

Annual share turnover

年换手率

为τ月的换手率（每月包含21个交易日），年换手率定义为：

T=12个月

Annualized traded value ratio

年化交易量比率

对日交易份额比率（换手率）进行加权求和，时间窗口252个交易日，半衰期63个交易日

Momentum

Short Term reversal

Short Term reversal

短期反转

最近一个月的加权累积对数日收益率

为算数平均股票收益率，为半衰指数权重，时间窗口21个交易日，半衰期5个交易日，T={t-1,.....,t-n}

Seasonality

Seasonality

季节因子

过去五年的已实现次月收益率的平均值

为滞后y年的月收益率

Industry Momentum

Industry Momentum

行业动量

该指标描述个股相对中信一级行业的强度

（1）个股相对强度定义为：

式中，为日股票收益率，为半衰指数权重，时间窗口6个月，半衰期1个月，T(t)={t，...,t-n}

（2）行业的相对强度定义为：

式中，为行业i内个股流通市值的平方根

（3）最终该指标定义为：

Momentum

Relative strength

相对于市场的强度

（1）计算非滞后的相对强度：对股票的对数收益率进行半衰指数加权求和，时间窗口252个交易日，半衰期126个交易日

（2）以11个交易日为窗口，滞后11个交易日，取非滞后相对强度的等权平均值

Historical alpha

历史Alpha

在计算BETA所进行的时间序列回归中，取回归截距项

Quality

Leverage

Market Leverage

市场杠杆

计算公式为：

其中ME为上一交易日的市值，PE和LD分别是上一财政年度的优先股和长期负债

Book Leverage

账面杠杆

计算公式为：

其中BE，PE和LD分别是上一财政年度的普通股账面价值，优先股和长期负债

Debt to asset ratio

资产负债比

计算公式为：

TL、TA分别为上一财政年度总负债和总资产

Earnings Variability

Variation in Sales

营业收入波动率

过去五个财年的年营业收入标准差除以平均年营业收入

Variation in Earnings

盈利波动率

过去五个财年的年净利润标准差除以平均年净利润

Variation in Cash-Flows

现金流波动率

过去五个财年的年现金及现金等价物净增加额标准差除以平均年现金及现金等价物净增加额

Standard deviation of Analyst Forecast  Earnings-to-Price

分析师预测盈市率标准差

预测12月eps的标准差除以当前股价

Earnings Quality

Accruals Balancesheet version

资产负债表应计项目

（1）资产负债表应计项目总额计算公式为：

_\=_ _\-_

其中，NOA为净经营资产，Cash为现金及现金等价物，TA为总资产，TL为总负债，TD为总带息债务（负债合计\-无息流动负债\-无息非流动负债）,DA为折旧与摊销之和

（2）将负的ACCR\_BS除以总资产TA:

Accruals Cashflow version

现金流量表应计项目

（1）现金流量表应计项目总额计算公式为：

Ni为净利润，CFO为经营现金流量净额，CFI为投资活动现金流量净额,  DA为折旧与摊销之和

（2）将负的ACCR\_CF除以总资产TA:

Profitability

Asset turnover

资产周转率

Sales为过去12个月的营业收入，TA为最近报告期的总资产

Gross profitability

资产毛利率

其中Sales、COGS和TA分别是上一个财务年度的营业收入、营业成本和总资产

Gross Profit Margin

销售毛利率

其中Sales和COGS分别为上一会计年度的营业收入和销货成本

Return on assets

总资产收益率

Earnings为过去12个月的净利润，TA为最近报告期的总资产

Investment Quality

Total Assets Growth Rate

总资产增长率

最近5个财政年度的总资产对时间的回归的斜率值，除以平均总资产，最后取相反数

Issuance growth

股票发行量增长率

最近5个财政年度的流通股本对时间的回归的斜率值，除以平均流通股本，最后取相反数

Capital expenditure growth

资本支出增长率

将过去5个财政年度的资本支出对时间的回归的斜率值，除以平均资本支出，最后取相反数

Value

BTOP

Book to price

账面市值比

将最近报告期的普通股账面价值除以当前市值

Earnings Yield

Trailing Earnings-to-price Ratio

EP比

过去12个月的盈利除以当前市值

Analyst-Predicted Earnings-to-Price

分析师预测EP比

预测12个月的盈利除以当前市值

Cash earnings to price

现金盈利价格比

过去12个月的现金盈利除以当前市值

Enterprise multiple (Ebit to Ev)

企业价值倍数的倒数

上一财政年度的息税前利润（EBIT）除以当前企业价值（EV）

Long Term reversal

Long term relative strength

长期相对强度

（1）计算非滞后的长期相对强度：对股票对数收益率进行加权求和，时间窗口1040个交易日，半衰期260个交易日

（2）滞后273个交易日，在11个交易日的时间窗口内取非滞后值等权平均值，最后取相反数

Long term historical alpha

长期历史Alpha

（1）计算非滞后的长期历史Alpha：取CAPM回归（见BETA）的截距项，时间窗口1040个交易日，半衰期260个交易日

（2）滞后273个交易日，在11个交易日的时间窗口内取非滞后值等权平均值，最后取相反数

Growth

Growth

Predicted growth 3 year

分析师预测长期盈利增长率

分析师预测的长期（3-5）年利润增长率

Historical earnings per share growth  rate

每股收益增长率

过去5个财政年度的每股收益对时间回归的斜率除以平均每股年收益

Historical sales per share growth rate

每股营业收入增长率

过去5个财政年度的每股年营业收入对时间回归斜率除以平均每股年营业收入

Sentiment

Sentiment

Revision ratio\*

调整比率

分析师调整比率的每月变动，定义为向上调整次数减去向下调整次数，除以总的调整次数

L={0,1,2}，

Change in analyst-predicted  earnings-to-price\*

分析师预测EP比变化

分析师预测EP比的加权变动

L={0,1,2,3},

Change in analyst-predicted earnings  per share\*

分析师预测的每股收益的变化

分析师预测每股收益的加权变化：

L={0,1,2,3},

Dividend Yield

Dividend Yield

Dividend-to-price ratio

股息率

最近12个月的每股股息除以上个月月末的股价

Analyst predicted dividend to price  ratio\*

分析师预测股息率

预测12个月的每股股息（DPS）除以当前价格

  

注：表中标\*的因子涉及分析师一致预期数据，因构建时数据源缺失，未将计算代码放在项目中，读者可根据本文提供的公式，使用自己的数据源构建descriptor。

  

一级因子纯因子组合净值走势：

![](assets/002.png)

  

参考资料：

1.《渤海证券多因子模型研究系列之八：Barra风险模型（CNE6）之单因子检测》；

2.《渤海证券多因子模型研究系列之九：Barra风险模型（CNE6）之纯因子构建与因子合成》；

3\. MSCI, Barra China A Total Market Equity Model for Long-Term Investors - Empirical Notes, 2018-08。

  

  

  

加星球请扫我：  

![](assets/003.jpg)

  

欢迎入群交流：  

![](assets/004.jpg)

  

往期回顾

       QuantML-Qlib开发版：

-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)  
      
    前沿论文代码：
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)  
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | FTS-Diffusion: 用于合成具有不规则和尺度不变模式的金融时间序列的生成框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483907&idx=1&sn=df124c03a74981eba923fee63613ecfd&chksm=ce7e651df909ec0b2f6029db3e29992bb41210c8b9f76f979b7968d0fab1ac913848004ac44d&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)
    
-   [ICAART 2024 | DTX: 基于TBSE Level2多线程市场模型的深度学习交易系统](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483965&idx=1&sn=e2fda25ce1bc8a4b9393158321dc2a14&chksm=ce7e6523f909ec3538bd37e07689308380cad55b02c35a7d4652a3e7d7fd3306a40253341c61&scene=21#wechat_redirect)
    

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

  

**点击蓝字**

![](assets/005.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/006.jpg)