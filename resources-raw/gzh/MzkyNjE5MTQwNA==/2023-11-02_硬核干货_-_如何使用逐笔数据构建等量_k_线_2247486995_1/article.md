# 硬核干货 - 如何使用逐笔数据构建等量 k 线

惊雨田 量化前沿速递 2023-11-02 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486995&idx=1&sn=5df01643388bbcd651bd820971242270&chksm=c37999c6b424a461ab6ec38722c7b12eb487fe604868cafbb548824553203cc1649cb06296b3#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486995&idx=1&sn=5df01643388bbcd651bd820971242270&chksm=c37999c6b424a461ab6ec38722c7b12eb487fe604868cafbb548824553203cc1649cb06296b3#rd)

我们通常熟知的 k 线都是基于时间周期，一般最小 1 分钟，最大一根 bar 跨度可到一年甚至更久。等时 k 线的特点就是一根 bar 正好是一段完整的时间周期，记录了该周期从 0 秒到最后 1 秒的价格和量等信息。市面上几乎大部分的非高频类量价策略都是基于这样的 k 线。  

这里我介绍如何构建等量 k 线。另外还有等笔、等价 k 线。这些另类 k 线可能能够开发出不一样的交易策略，然后和通常的等时 k 线策略形成互补。因为它的开平仓时间可能不是在整点。不仅仅分散了开仓时机，还减少了整点时刻交易所交易量大、滑点大的问题。

基于这些另类 k 线，至少能够增加策略的容量，即使与等时 k 线策略的设计逻辑高度类似。资金大的量化交易者可以考虑。

等量和等笔这两种 bar 相比，等量 bar 可能效果更好些，更实用一点，但是有时候具体问题得具体分析。这里限于篇幅，我先只介绍等量 bar，等笔、等价 bar 其实就是相同数量的交易笔数或者价格变动聚合在一根 k 线，很容易引申。

### 等量 bar

首先，等量 bar 就是每根 k 线的交易量（或者交易额）是相等的，而不是时间跨度。比如你规定 100 个大饼一根 k 线，行情来了且波动大的时候，可能几十秒就一根 k 线，没行情的时候可能 1 个多小时才走完一根 k 线。

如果你是构建每根量比较大的等量 bar，那么使用普通的等时分钟 k 线也可以，但是在大行情的时候，可能单根分钟 k 线也会有较大的交易量，那么构建的等量 k 线交易量就会参差不齐，所以这个时候使用更高频的 aggTrades 逐笔数据效果会更好。比如类似 15 分钟周期的等量 k 线，如果基于 1 分钟的等时 bar，交易量很可能就不整齐，影响效果。

下面介绍如何实现。不过建议先看看我之前写的怎么用 aggTrades 重采样为普通等时 k 线，详细的在这篇[使用逐笔交易记录 aggTrades 创建超短 K 线（二）](http://mp.weixin.qq.com/s?__biz=MzAwMjk3ODQ2Mw==&mid=2247483811&idx=1&sn=37bd1a45c91ef47bb17ffaa3f6bfff29&chksm=9ac36653adb4ef45c8f32216c6ec0334e379902f06fa2e3095e0f44933a1b2a41b76d8478653&scene=21#wechat_redirect)。

(中途插入) 分享一个宝藏开源 k 线作图库 (finplot) ，不是那种网页版，而且速度飞快，显示巨量 k 线（10万+）毫无压力，而且缩放自如、不卡顿（非常重要），可能是除了 js 版的 echarts 之外性能最好的作图库了。我下面的图就是用这个库画的。它基于 qt，所以安装的东西可能有点多，100来兆左右吧。朴实无华，量化回测复盘必备。

![](assets/001.png)

![](assets/002.png)

上面两图中，第一幅图片就是普通的等时 bar，第二个就是等量 bar。这是三天时间的小时数据，所以第一张图中有 72 根 bar，但是第二张图中有 94 根 bar，等量 bar 一般来说可能要比等时 bar 多一些，k 线走得快一点，因为交易量大的那些 k 线被分成了更多根小 k 线，不过有时候也有几根小 k 线被合成了一根长 k。

第二张图中的 k 线每根 bar 的交易量是由之前十天的平均每小时交易量决定的。

### 代码和数据

下面是等量 bar 合成的代码：

def bn\_aggTrades\_to\_bvbar(at\_df, bar\_size):    
    at\_df\['bt-bv'\] \= np.where(at\_df\['ibt'\]\>0, at\_df\['bvol'\], 0)  
    at\_df\['bar-num'\] \= (at\_df\['bvol'\].cumsum()//bar\_size).astype(int)  
    bvbar \= pd.DataFrame()  
    bvbar\['open'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['price'\].first()  
    bvbar\['close'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['price'\].last()  
    bvbar\['high'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['price'\].max()  
    bvbar\['low'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['price'\].min()  
    bvbar\['bvol'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['bvol'\].sum()  
    bvbar\['bt-bv'\] \= at\_df.groupby(\['bar-num'\], sort\=False)\['bt-bv'\].sum()  
    ends \= at\_df.groupby(\['bar-num'\], sort\=False)\['lid'\].last()  
    starts \= at\_df.groupby(\['bar-num'\], sort\=False)\['fid'\].first()  
    bvbar\['tcnt'\] \= ends\-starts+1  
    return bvbar  

代码平平无奇，就是普通的 pandas 数据处理，唯一需要稍微解释的就是这句

`at_df['bar-num'] = (at_df['bvol'].cumsum()//bar_size).astype(int)`

它先计算聚合的逐笔交易量的累积和，然后取之前平均交易量的整数倍的值，相当于对每根等量 bar 内的 aggTrades 数据编了一个序号，这样再基于序号 group 分组，然后再在这个分组里计算它们的开关高低价格等的统计值（OHLCV），所以其实不算复杂。难点就是理解 pandas 模块的 group 操作。下面是数据的一个片段

![](assets/003.png)

上面就是普通的等时 k 线的各项值，下面的 dataframe 是等量 bar 的。这里等量 bar 其实还可以记录每根 bar 的起止时间，以后方便事后复查、检验。如果记录到 dataframe 的 index 里可能就会和普通的时序搞混了，这个处理的时候要注意。

### 特点和作用

说了这么多，那么等量 bar 到底有什么特点和实际作用？

我认为它的作用虽然不是颠覆性的，但是有一定的作用。

首先指望光靠一条不一样的 k 线就能成就圣杯是不太可能的。量化交易策略，交易系统的打造是一项复杂的工程，特别是要达到长期正期望的效果。 

那么，虽然它不能做出决定性的作用，但是对主流 k 线策略的互补还是可行的，这样可能提高不了多少收益率，甚至还会拉低，但是大概率可以起到平滑资金曲线，提高夏普的作用，还有提高策略的资金容量等。

下面看一张对比图：

![](assets/004.png)

上图左边是等时 bar，右边是等量 bar。一共十天的小时图。可以看到，右边的图中，行情转折处的小 k 线 + 长引线的 bar 更多一些（例如红圈和绿圈）；还有急跌行情中，等量 bar 更能刻画行情中的反弹，因为会走得缓慢一点，图中橘黄圈可能可以做一个反弹行情中的空单之类的。

这是比较直观和主观的观察，而在量化中，前面已经提到，一般情况下是不会有质的提高，但是可以和其他策略形成互补。一个元策略，形成多个子策略。

补充一下作图的代码，同样是基于那个牛逼画图库 finplot：

if \_\_name\_\_ == "\_\_main\_\_":  
    rpath = '/YOUR\_FILE\_ROOT\_PATH/'  
    fpath = 'xxx.pkl'  
    pkl\_path = rpath + fpath  
    at\_df = pd.read\_pickle(pkl\_path,compression={'method':'gzip'})  
    skdf = bn\_aggTrades\_to\_tbar(at\_df,'1h')  
    
    skdf = skdf\['2022.6.1 08:00:00':'2022.6.11 07:59:59'\]  
    bvol\_h = skdf.bvol.sum()/skdf.shape\[0\]  
  
    at\_df = at\_df\['2022.6.1 12:00:00':'2022.6.10 11:59:55'\]  
    tbar\_df = bn\_aggTrades\_to\_tbar(at\_df,'1h')  
    tbar\_df\['ma20'\] = tbar\_df.close.rolling(20).mean()  
    tbar\_df\['std'\] = tbar\_df.close.rolling(20).std()  
    tbar\_df\['upr'\] = tbar\_df.ma20 + 2\*tbar\_df\['std'\]  
    tbar\_df\['lwr'\] = tbar\_df.ma20 - 2\*tbar\_df\['std'\]  
    bvbar\_df = bn\_aggTrades\_to\_bvbar(at\_df,bvol\_h)  
    bvbar\_df\['ma20'\] = bvbar\_df.close.rolling(20).mean()  
    bvbar\_df\['std'\] = bvbar\_df.close.rolling(20).std()  
    bvbar\_df\['upr'\] = bvbar\_df.ma20 + 2\*bvbar\_df\['std'\]  
    bvbar\_df\['lwr'\] = bvbar\_df.ma20 - 2\*bvbar\_df\['std'\]  
    print(tbar\_df.tail())  
    print(bvbar\_df.tail())  
    print(bvbar\_df.shape, tbar\_df.shape)  
  
    \# ax1,ax2 = fplt.create\_plot('tbar bvbar', rows=2, maximize=False)  
  
    \# fplt.candlestick\_ochl(tbar\_df\[\['open', 'close', 'high', 'low'\]\])  
    \# fplt.plot(tbar\_df.ma20, legend='tma20',color='b')  
    \# fplt.plot(tbar\_df.upr, legend='upr',color='g')  
    \# fplt.plot(tbar\_df.lwr, legend='lwr',color='g')  
  
    fplt.candlestick\_ochl(bvbar\_df\[\['open', 'close', 'high', 'low'\]\])  
    fplt.plot(bvbar\_df.ma20, legend='vma20',color='b')  
    fplt.plot(bvbar\_df.upr, legend='upr',color='g')  
    fplt.plot(bvbar\_df.lwr, legend='lwr',color='g')  
  
    fplt.show()  

### 最后

研究策略，如果原始数据材料总是那些内容，其实不太容易玩出新东西。不过呢，中低频策略如果能够形成策略组合，提高夏普比率还是可能的。夏普高了，你的杠杆就能适当的放大一点点，收益可能就能提高些，回撤可能维持原样，这样卡玛比率也能提高一点。

工具在手，就看你怎么用了。

_喜欢的话，欢迎点赞和关注。后期分享更多代码_编程、_数据分析、量化交易方面的思考和心得。_