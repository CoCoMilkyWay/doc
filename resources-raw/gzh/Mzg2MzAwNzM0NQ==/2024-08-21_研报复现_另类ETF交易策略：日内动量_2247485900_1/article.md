# 研报复现 | 另类ETF交易策略：日内动量

Hugo QuantML 2024-08-21 22:01 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&chksm=cf5c7675316b3d1f0a371ef52e2a7600ee6f746f6898e69ce64c0bb3c852b855e4f2d9f24606#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&chksm=cf5c7675316b3d1f0a371ef52e2a7600ee6f746f6898e69ce64c0bb3c852b855e4f2d9f24606#rd)

Content

本文来自星球嘉宾Hugo的研报项目，复现研报：《**西部证券——**另类ETF交易策略：日内动量》

> 报告链接
> 
> 西部量化团队，公众号：西部证券研究发展中心[【西部量化】另类ETF交易策略：日内动量——指数化配置系列研究（1）](https://mp.weixin.qq.com/s/IYINEVMJ3ZBXpra2Qyr8jQ)

  

# 引言

自1993年Jegadeesh和Titman提出动量效应以来，动量策略在学术界和实践中的应用，并指出随着高频数据的可获得性和技术进步，动量策略的研究已经扩展到日内领域。报告提到了价格对新信息反应不足是动量效应存在的原因之一，并概述了本报告将基于粘性供需失衡引起的日内动量效应，设计ETF交易策略，并在A股主要宽基指数上进行测试，以验证其有效性。

# 数据获取

```
etf_price: pd.DataFrame = pd.read_parquet("data/etf/hfq_etf_minute_price.parquet")
```

# 信号构造

## 噪声区域

噪声区域是指在一段时间内，市场价格的正常波动范围，这个范围反映了市场供需平衡状态下的价格波动。报告中的具体计算方法为：

![](assets/001.png)

![](assets/002.png)

当分钟K线的收盘价突破噪声区域上边界时，发出做多信号。当分钟K线的收盘价突破噪声区域下边界时，发出做空信号。  

```
from src.SignalMaker import NoiseArea
```

```
etf_price.head()
```

```
# 使用etf分钟数据生成信号
```

使用指数生成信号，在对应的etf上进行交易

```
etf_codes: List[str] = ["510300.SH", "510050.SH", "510500.SH", "159845.SZ"]
```

```
combo_data.head()
```

# 基础策略

**开仓信号：**当分钟K线的收盘价突破噪声区域的上边界时，视为向上趋势的形成，发出做多信号；当收盘价突破下边界时，视为向下趋势的形成，发出做空信号。

  

**平仓规则：**由于策略是日内的，不持仓过夜，因此设定了明确的平仓规则。如果当前持有多头仓位，价格一旦跌破噪声区域的下边界，或者到达当日收盘，则平仓；反之，如果持有空头仓位，价格一旦突破上边界，或者到达收盘，则平仓。

  

**交易时点：**为了避免频繁交易，策略规定只在每天的10:29、11:29、13:59这三个时点上判断是否开仓。但是，如果收盘前触发了平仓信号，则会立即执行平仓。

```
from src.bt_template import run_template_strategy
```

这里展示的是沪深300指数在2013-10-25的分钟信号情况

```
plot_intraday_signal(combo_data.query('code=="510300.SH"'), "2013-10-25")
```

![](assets/003.png)

**所有回测均收取万一的手续费及万一点五的印花税及万一的滑点。且只能以100的正数倍买入标的**

```
target_code: str = "510300.SH"
```

```
plot_cumulative_return(
```

![](assets/004.png)

# 改进策略1：调整止损规则

改进策略1通过引入更严格的止损规则来优化基础策略，具体做法是将做多（空）时的价格回到上（下）边界作为止损线，并结合成交量加权平均价格（VWAP）作为参考，以提高策略的稳健性。当价格触及这些边界或VWAP时，策略会触发平仓指令，从而及时止损，减少潜在的大幅亏损

![](assets/005.png)

```
from src.strategy import NoiseRangeVWAPStrategy
```

```
noisevwaprange_strat = run_template_strategy(
```

```
plot_cumulative_return(
```

![](assets/006.png)

## 对比基础策略与改进策略

```
noisevwaprange_returns: pd.Series = get_strategy_cumulative_return(
```

![](assets/007.png)

# 有底仓的ETF日内动量策略

假设底仓仓位为50% ,当策略发出做多信号时,用剩余的50%仓位买入 ETF 至平仓信号触发或收盘, 再行卖出; 当策略发出做空信号时, 卖出已有的50%仓位至平仓信号触发或收盘，再买入 ETF，回到 50%仓位。即，日间始终保持仓位不变，试图通过日内交易相对买入持有 ETF 产生增强。由于该模式下无法使用杠杆, 因此我们只测试改进策略 1 。此外, 日内完成一次交易后, 持有的均是当日买入的仓位, 无法再行交易, 故回测时只取每天的第一个信号, 交易成本同样设为单边万一。

```
from src.strategy import BasePositionStrategt
```

```
bp_strat = run_template_strategy(
```

```
plot_cumulative_return(
```

![](assets/008.png)

## 多标的下的底仓策略

这里使用多个标的执行有底仓的ETF动量策略,每个标的等权持仓，独立执行策略。

```
hold_num: int = len(etf_codes)
```

```
plot_cumulative_return(
```

![](assets/009.png)

# 查看不同标的在不同策略下的表现情况

## 有底仓ETF策略下不同标的的表现

```
from src.performance import multi_asset_show_perf_stats,multi_strategy_show_perf_stats
```

```
multi_asset_dict: Dict = {
```

```
for code, strat in multi_asset_dict.items():
```

```
multi_asset_show_perf_stats(multi_asset_dict,combo_data)
```

![](assets/010.png)

![](assets/011.png)

![](assets/012.png)

![](assets/012.png)

## 不同策略下的标的表现

```
strategys: List = [NoiseRangeStrategy, NoiseRangeVWAPStrategy, BasePositionStrategt]
```

### 沪深300ETF

```
code:str = "510300.SH"
```

```
for strategy_name, strat in multi_strategy_dict[code].items():
```

![](assets/013.png)

![](assets/014.png)

![](assets/010.png)

### 中证500ETF

```
code:str = "510500.SH"
```

```
for strategy_name, strat in multi_strategy_dict[code].items():
```

![](assets/015.png)

![](assets/016.png)

![](assets/012.png)

### 上证50ETF

```
code: str = "510050.SH"
```

```

```

![](assets/017.png)

![](assets/018.png)

![](assets/011.png)

### 中证1000ETF

净值突然跳空是复权的原因

```
code:str = "159845.SZ"
```

```

```

![](assets/019.png)

![](assets/020.png)

![](assets/021.png)

  

**代码下载见星球**

**加星球请扫我：**

![](assets/022.png)

  

  

**入群交流请扫我：**

![](assets/023.jpg)

  

  

**点击蓝字**

![](assets/024.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。