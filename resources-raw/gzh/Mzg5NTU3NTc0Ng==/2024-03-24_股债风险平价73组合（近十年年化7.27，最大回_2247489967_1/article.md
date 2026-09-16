# 股债风险平价73组合（近十年年化7.27，最大回撤4.24%）

云天共远 云天共远投资笔记 2024-03-24 23:48 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5NTU3NTc0Ng==&mid=2247489967&idx=1&sn=fafa14d004cd8a7c6a4115ec55d68d7d&chksm=c16d4064559ad22de41ae7ae7ea5d3473a30d757fd6362bef8a3a758689c4b54d8e7896353aa#rd](https://mp.weixin.qq.com/s?__biz=Mzg5NTU3NTc0Ng==&mid=2247489967&idx=1&sn=fafa14d004cd8a7c6a4115ec55d68d7d&chksm=c16d4064559ad22de41ae7ae7ea5d3473a30d757fd6362bef8a3a758689c4b54d8e7896353aa#rd)

# 1 组合逻辑

这个ETF投资方法建立在桥水全天候投资策略，他有一个核心前提：_我们无法预知未来的经济周期，也无法确定哪些资产将会优异表现。因此，我们采取的策略是多元化投资于不同种类的金融资产，以期在各种经济条件下实现稳健的回报。_

想做这个平价组合的起因是我这周看到的这张图（近十年全球各资产的收益波动率图）：

![](assets/001.png)

参考上图，横轴是年化收益率，纵轴是波动率，因此在同一波动率情况下，收益越高的资产越有配置价值，表格里可以看到沪深300在图里表现较差，因为我前面做过纳指红利黄金442策略的回测，有过境内外配置的经验和思路，所以就在想，是否有一个**更稳健的策略**，能够做到：**年化收益接近近十年沪深300全收益指数（包含分红），波动率又远小于沪深300指数。**

![](assets/002.png)

  

从图里可以看到，近十年沪深300全收益指数年化收益7.58%，年化波动率21.86%，所以我只要做一个组合年化收益7%以上，波动率远小于22%即可。

我的想法是：搭建一个股债境内外平衡组合，**投70%的国债ETF，剩下30%分别投A股红利低波、美股纳斯达克、商品黄金。每月再平衡。**

**资产类别**

**ETF关注**

**场内代码**

**比例**

国债

十年国债ETF

511260

70%

境内高股息

红利低波ETF

512890

10%

美股科技

纳斯达克ETF

159501

10%

大宗商品

黄金ETF

159934

10%

**下面我会用回测数据来支撑我这个想法。**

# 2 各资产相关性分析

我拟选用的资产池包括：红利低波（全）、沪深300、纳斯达克100、标普500、易方达黄金ETF比较基准、国债指数、日经225共7类资产，涵盖全球主要股票市场、国内债券、国内商品等。选取2014年1月至2024年3月22期间上述指数的收盘价数据，并统一以A股市场交易日为准。

`import numpy as np``import pandas as pd``from scipy.optimize import minimize``import datetime as dt``from six import StringIO``from dateutil.parser import parse``import cPickle as pickle``import seaborn as sns``import matplotlib as mpl`

读取全球资产指数行情序列。

`body=read_file('全球资产指数行情序列1.xlsx')``prices=pd.read_excel(StringIO(body))``# print prices.columns``columns =[u'红利低波(全)',u'沪深300',u'纳斯达克100',u'标普500',u'易方达黄金ETF基准',u'国债指数',u'日经225']``prices.set_index(u'时间',inplace=True)``prices = prices[columns]['2014-01-2':]``prices.head().append(prices.tail())`

![](assets/003.png)

绘制全球各类资产指数的净值走势图

`mpl.rcParams['font.family']='serif'``   ``mpl.rcParams['axes.unicode_minus']=False # 处理负号``   ``(prices/prices.iloc[0]).plot(figsize=(15,8),grid='on')``   ``pct_daily = prices.pct_change()`

![](assets/004.png)

计算各类资产的相关矩阵，并以热点图形式展示。可以看出红利低波跟沪深300的相关性较高，纳斯达克100和标普500相关性较高，其他资产相关性不高。

`fig = plt.figure(figsize= (15,10))``ax = fig.add_subplot(111)``ax = sns.heatmap(pct_daily.corr(),annot=True,annot_kws={'size':9,'weight':'bold'})`

  

![](assets/005.png)

# 3 聚宽回测

标的选择：

70%十年国债ETF：511260

10%红利低波ETF：512890

10%纳斯达克ETF：513100

10%黄金ETF：159934

**这次免费提供代码，感兴趣的自己去聚宽测一下，记得回测的时间得选择所有ETF都上市后的时间，不然会出现乱码，我这里时间选的是19年1月28日至今**

`# 导入函数库``from jqdata import *``   ``# 初始化函数，设定基准等等``def initialize(context):`    `# -----------------------参数设置-----------------------`    `# 资产配置清单`    `g.asset_dict = {`        `'ixic':{'weight':0.1, 'security_list':['513100.XSHG']}, #纳指ETF`        `'红利':{'weight':0.1, 'security_list':['512890.XSHG']}, #红利低波ETF`        `'long_bond':{'weight':0.7, 'security_list':['511260.XSHG']},   #10年期国债ETF`        `'gold':{'weight':0.1, 'security_list':['159934.XSHG']},       #黄金ETF`        `}``   `    `# 获取每个ETF上市信息`    `all_security_list = []`    `for asset,d in g.asset_dict.items():`        `all_security_list.extend(d['security_list'])`    `df = get_all_securities(types=['etf'], date=None)`    `g.info_df = df.loc[all_security_list]`    `log.info(g.asset_dict)`    `log.info(g.info_df)`    `# -----------------------回测设置-----------------------`    `# 设定基准`    `set_benchmark('511260.XSHG')`    `# 开启动态复权模式(真实价格)`    `set_option('use_real_price', True)`    `# 打开防未来函数`    `set_option('avoid_future_data', True)`    `# ETF每笔交易时的手续费是：买入时佣金万分之三，卖出时佣金万分之三，无印花税, 每笔交易佣金最低扣5块钱`    `set_order_cost(OrderCost(open_tax=0, close_tax=0, open_commission=0.0003, close_commission=0.0003, close_today_commission=0, min_commission=5), type='fund')`    `# ***设置固定滑点，降低/去掉滑点回测收益会高一些***`    `set_slippage(FixedSlippage(0.002))`    `# set_slippage(FixedSlippage(0))`    `# 过滤掉order系列API产生的比error级别低的log`    `log.set_level('order', 'error')``   `    `# 定期月初开盘运行`    `run_monthly(ETF_rebalance, monthday=1, time='09:30', reference_security='000300.XSHG')``   ``   ``# 开盘时运行函数``def ETF_rebalance(context):`    `today = context.current_dt.date()`    `total_value = context.portfolio.total_value # 获取总资产`    `for asset in g.asset_dict.keys():`        `asset_weight = g.asset_dict[asset]['weight']`        `security_list = g.asset_dict[asset]['security_list']`        `weight_per_security = asset_weight / len(security_list)`        `cash_per_security = weight_per_security * total_value`        `for s in security_list:`            `start_date = g.info_df.loc[s, 'start_date']``   `            `# 调整标的至目标权重`            `order_target_value(s, cash_per_security)``   `

![](assets/006.png)

2019年1月28日至今（因为红利低波2019年1月底才上市），策略收益42.75%，年化收益7.41%，年化波动率仅3.7%，最大回撤4.24%

通过聚宽的回测，我们发现近五年的年化收益率跟近十年沪深300全收益的年化收益率接近（近5年沪深300没赚钱，所以没拿来比），但波动率3.7%远小于沪深300的波动率。

# 4 万得回测（从2014年回测起）

如果要了解到近十年该策略的年化收益率，可以用万得，万得的PMS功能支持持仓导入，也能快捷的回测某一投资组合的历史收益情况。

在512890红利低波ETF上市之前，我拿东证红利低波全收益 (921446.CSI)来替代，在511260十年国债ETF上市之前，我拿国债ETF511010来替代。

历史走势图如下：

![](assets/007.png)

![](assets/008.png)

  

2014年1月1日至今总回报105.38%，年化收益7.27%，年化波动率3.77%，最大回撤4.24%。2014年至今所有年份没有负收益，表现最差的是2022年，仅有0.47%的收益。

# 5 结论（从2014年回测起）

我用了聚宽和万得分别回测了这个73策略近五年和近十年的收益情况，可以看到聚宽和万得得出来的年化收益都超过了7%，波动率都是3.7%左右，最大回撤一样。

因此可以得出一个结论，这个股债73风险评价组合，年化收益与沪深300全收益指数接近，但年化波动率远低于沪深300指数，他的收益性价比比沪深300高很多。**我验证和复现了一开始提出的组合构建的设想。**

**如果你是风险厌恶者，或者资金较大，想要有比投资A股股票更稳健、更有持有体验的持仓的人，不妨试试这个股债平衡组合策略，月度、季度再平衡都可。**

**资产类别**

**ETF关注**

**场内代码**

**比例**

国债

十年国债ETF

511260

70%

境内高股息

红利低波ETF

512890

10%

美股科技

纳斯达克ETF

159501

10%

大宗商品

黄金ETF

159934

10%

**最后鸣谢聚宽股友“小羊肖恩”，提供了思路和代码**

https://www.joinquant.com/view/community/detail/32c1dfe4e9d62b6a59934f59a6d18c82?type=1&page=1