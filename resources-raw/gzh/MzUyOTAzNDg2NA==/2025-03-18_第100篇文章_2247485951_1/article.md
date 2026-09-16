# 第100篇文章

fintechhaibin FinTechHi 2025-03-18 20:39 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485951&idx=1&sn=53532bb088d77e896e4fdaa67d72c120&chksm=fb6b66167a84977b0a7e85e32888c3ec83a1bee7e026588af25c9c4a67152d6470e9c19a307b#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485951&idx=1&sn=53532bb088d77e896e4fdaa67d72c120&chksm=fb6b66167a84977b0a7e85e32888c3ec83a1bee7e026588af25c9c4a67152d6470e9c19a307b#rd)

这篇文章是我同各位关注者朋友一起共筑的第100篇文章，真心感谢每一位关注者的鼓励和支持。

同时，也意味着我坚持做这个事100天了。很多事情，粗糙的开始永远胜于完美的想法。

我上一个自己坚持超过100天的事是跑步，那时候我就认识到，坚持做一个事情，会让自己变的更加专注，也会让自己把不轻易间浪费的时间都利用起来。

我之前一直在知乎，目标是做到满级，现在还差一点点，基本上能够得着了，就想着换个平台试试，而且知乎之前主要是以资管科技为主，所以就选择这里记录自己学习量化的过程，当做自己的笔记，还好也有同仁感兴趣。

本公众号的内容定位之前有介绍过，主要是围绕量化投资相关的：数据（行情、订单薄）、因子及模型（含机器学习）、策略思路（T0策略动态）、交易系统（OMS、低时延）等工程类的，也包括量化行业的资讯、监管、职业等行业信息，同时也会记录我认为比较有意义的AI方向标志事件。目前基本上每个点都有涉及了，只有数据相关的，一拖再拖，争取找时间尽快补上，后面就在每个类别下添砖加瓦，让“量化知识树”不断长大。

这么多内容和点，虽然有“一根线”连着，但想把每个点都弄懂，肯定不现实，但我个人一直都主张：“不谋万世者，不足谋一时；不谋全局者，不足谋一域” 。我们了解了全貌后，再选择性的做好做深谋个点，这样不至于陷入管中窥豹，摸着石头过河的局限中。

最近文章基本上都在测试验证指标，自己也在实盘中慢慢验证一些结论，说到指标，肯定有人觉得这都是老掉牙的东西有什么用，有这个想法一点都不奇怪，因为我之前就从来不看这些，但我看国外的文章介绍这类的比较多，我再自己动手去分析这些指标的时候，其实带给我的已经不是这个指标能不能赚钱，而是研究指标的过程，就是一个量化投资的研究过程和逻辑，比如从研究过程来说：处理数据、计算指标、信号处理、回测验证、寻找最佳参数、模拟回测绩效等等，反复的做几次，就熟能生巧，融会贯通了，然后又促使自己的思维上一台阶；从逻辑来说，每个指标在具体标的，具体市场环境下，以及多个指标如何结合，那些指标是判断趋势，那些是为仓位管理提供参考，都需要针对性的分析，这样就是策略实现时需要考虑的方方面面。

今天再把一些出现频率高的指标再整理下（排名不分先后）：

1.移动平均线（Moving Average, MA）

这是最简单也是大家最熟悉的一个指标，计算特定时间段内股票收盘价的平均值，来平滑价格波动，展示股价的趋势方向。

常见的移动平均线有简单移动平均线（SMA）和指数移动平均线（EMA）。SMA对时间段内的所有数据赋予相同权重，而EMA则对近期数据赋予更高权重，能更快地反映价格变化。之前文章有详细讲过，我们再做个回顾：

以SMA为例，假设我们有一个包含股票收盘价的列表close，计算N日SMA的Python代码如下：

`def calculate_sma(close_prices, n):       if len(close_prices) < n:           return None       return sum(close_prices[-n:]) / n   `

对于EMA，计算过程相对复杂，需要考虑权重系数。假设alpha为平滑系数，通常alpha = 2 / (n + 1)，计算N日EMA的Python代码如下：

`def calculate_ema(close_prices, n):       if len(close_prices) < n:           return None       ema = sum(close_prices[:n]) / n       alpha = 2 / (n + 1)       for price in close_prices[n:]:           ema = alpha * price + (1 - alpha) * ema       return ema   `

移动平均线在投资中主要用来判断趋势判断，一般教科书的经验是：当短期移动平均线（如50日线）向上穿过长期移动平均线（如200日线）时，形成“黄金交叉”，通常被视为买入信号，预示着股价可能进入上升趋势；反之，短期均线向下穿过长期均线形成“死亡交叉”，则是卖出信号。

此外，移动平均线还可作为支撑位和阻力位，当股价回调至移动平均线附近时，若获得支撑则可能继续上涨，若跌破则可能下跌。 回到量化视角，具体的窗口多少合适，都需要通过对不同标的，不同市场环境下做回测分析寻找最优值。

  

2.相对强弱指数（Relative Strength Index, RSI）

![](assets/001.jpg)

RSI是一个动量指标，用于衡量股票在一定时期内上涨和下跌的相对强度。它的取值范围在0到100之间，通过比较一段时期内收盘价上涨的平均值与收盘价下跌的平均值来评估股票的买卖力量对比。

一般认为，RSI超过70表明市场处于超买状态，股价可能回调；RSI低于30则表示市场超卖，股价可能反弹。（注意：是一般。）

Python代码如下：

`import numpy as np      def calculate_rsi(close_prices, n):       deltas = np.diff(close_prices)       gains = deltas.copy()       losses = deltas.copy()       gains[gains < 0] = 0       losses[losses > 0] = 0       avg_gain = np.mean(gains[:n])       avg_loss = np.mean(np.abs(losses[:n]))       if avg_loss == 0:           return100       rs = avg_gain / avg_loss       rsi = 100 - (100 / (1 + rs))       for i in range(n, len(close_prices)):           avg_gain = (avg_gain * (n - 1) + gains[i - 1]) / n           avg_loss = (avg_loss * (n - 1) + np.abs(losses[i - 1])) / n           if avg_loss == 0:               rsi = np.append(rsi, 100)           else:               rs = avg_gain / avg_loss               rsi = np.append(rsi, 100 - (100 / (1 + rs)))       return rsi   `

利用RSI指标可以作为判断买卖时机的参考，当RSI进入超买区域，且股价出现滞涨或回调迹象时，可考虑卖出股票；当RSI进入超卖区域，且股价不再创新低时，可寻找买入机会。

此外，RSI指标还可用于识别背离现象，即股价创新高但RSI未能同步创新高，或股价创新低但RSI未能同步创新低，这种背离往往预示着趋势即将反转。

  

3.布林线（Bollinger Bands）

布林线由三条线组成：中轨（通常是20日简单移动平均线）、上轨（中轨加上2倍标准差）和下轨（中轨减去2倍标准差）。

标准差衡量的是价格的波动程度，因此布林线能够直观地展示股价的波动范围和趋势变化。当股价触及上轨时，可能表示市场超买；触及下轨时，可能表示市场超卖。布林线的带宽变窄，通常预示着市场即将出现较大波动。

Python代码如下：

`import numpy as np      def calculate_bollinger_bands(close_prices, n=20):       sma = calculate_sma(close_prices, n)       if sma is None:           return None, None, None       std = np.std(close_prices[-n:])       upper_band = sma + 2 * std       lower_band = sma - 2 * std       return upper_band, sma, lower_band   `

投资中，通过布林线可用于判断股价的波动区间和趋势强度。当股价在布林线中轨上方运行，且布林线开口逐渐扩大时，表明股价处于上升趋势且波动性增强，投资者可考虑持有或买入；当股价在中轨下方运行，且布林线开口扩大时，股价可能处于下跌趋势，应谨慎操作。

此外，当股价触及上轨后回调，或触及下轨后反弹，都可作为交易信号。投资者还可结合布林线与其他指标，如RSI，来提高交易决策的准确性。

  

4.指数平滑异同移动平均线（Moving Average Convergence Divergence, MACD）

MACD是一种趋势跟踪和动量指标，它由两条线组成：MACD线和信号线，以及柱状图（MACD Histogram）。

MACD线是快速移动平均线（通常是12日EMA）与慢速移动平均线（通常是26日EMA）的差值，信号线是MACD线的9日EMA。MACD柱状图则是MACD线与信号线的差值，用于显示两者之间的差距。

MACD指标通过观察两条线的交叉、背离以及柱状图的变化来判断市场的趋势和动量变化。

Python代码如下：

`def calculate_macd(close_prices):       short_ema = calculate_ema(close_prices, 12)       long_ema = calculate_ema(close_prices, 26)       if short_ema is None or long_ema is None:           return None, None, None       macd = short_ema - long_ema       signal = calculate_ema([macd], 9)       histogram = macd - signal       return macd, signal, histogram   `

MACD在投资中具有重要应用价值。当MACD线向上穿过信号线时，形成“黄金交叉”，是买入信号；当MACD线向下穿过信号线时，形成“死亡交叉”，是卖出信号。

此外，MACD柱状图的变化也能提供有价值的信息，柱状图由负转正，表明市场动量增强，可能是买入时机；柱状图由正转负，则可能是卖出时机。MACD还可用于识别背离现象，与股价走势的背离往往预示着趋势反转。

  

5.平均方向指数（Average Directional Index, ADX）

ADX用于衡量趋势的强度，它不指示趋势的方向，而是显示趋势的强弱程度。

ADX的取值范围从0到100，数值越高表示趋势越强。ADX通常与正方向指标（+DI）和负方向指标（-DI）结合使用，+DI表示上升趋势的强度，-DI表示下降趋势的强度。

当ADX上升且+DI高于-DI时，表明上升趋势强劲；当ADX上升且-DI高于+DI时，表明下降趋势强劲。

Python代码如下：

`import numpy as np      def calculate_directional_movement(high_prices, low_prices, close_prices):       plus_dm = np.diff(high_prices)       minus_dm = np.diff(low_prices)       plus_dm[plus_dm < 0] = 0       minus_dm[minus_dm > 0] = 0       tr = np.maximum(np.maximum(np.diff(high_prices), np.abs(np.diff(low_prices))), np.abs(high_prices[1:] - low_prices[: - 1]))       plus_di = 100 * np.cumsum(plus_dm) / np.cumsum(tr)       minus_di = 100 * np.cumsum(minus_dm) / np.cumsum(tr)       return plus_di, minus_di      def calculate_adx(high_prices, low_prices, close_prices, n=14):       plus_di, minus_di = calculate_directional_movement(high_prices, low_prices, close_prices)       dx = 100 * np.abs(plus_di - minus_di) / (plus_di + minus_di)       adx = calculate_ema(dx, n)       return adx   `

可以利用ADX来判断市场趋势是否足够强劲，以决定是否参与交易。

当ADX值较低时，市场可能处于盘整阶段，趋势不明显，交易风险较大；当ADX值上升且超过一定阈值（如25），同时+DI和-DI的差值也较大时，表明市场趋势强劲，可根据+DI和-DI的关系判断趋势方向，选择顺势交易。在趋势市场中，ADX有助于投资者坚定持有头寸，避免过早离场。

  

6.平均真实波动幅度（Average True Range, ATR）

ATR是衡量市场波动性的指标，它反映了资产在一定时间范围内价格波动的平均幅度。

ATR不考虑价格的涨跌方向，只关注价格波动的程度。ATR值越高，说明市场波动性越大；ATR值越低，说明市场波动性越小。ATR通常用于设置止损和止盈水平，以及评估交易风险。

Python代码如下：

`import numpy as np      def calculate_atr(high_prices, low_prices, close_prices, n=14):       tr1 = np.maximum(np.maximum(np.diff(high_prices), np.abs(np.diff(low_prices))), np.abs(high_prices[1:] - close_prices[: - 1]))       atr = calculate_ema(tr1, n)       return atr   `

策略中可根据ATR值来设置合理的止损位，例如，将止损位设置在距离入场价格一定倍数的ATR处。

当市场波动性较大（ATR值高）时，适当放宽止损距离，以避免被市场噪音触发止损；当市场波动性较小（ATR值低）时，可收紧止损位。ATR还可用于评估投资组合的风险水平，以便合理分配资金，降低整体风险。

  

7.抛物线转向指标（Parabolic SAR）

抛物线转向指标（SAR）是一种趋势跟踪工具，它以一系列点的形式出现在价格图表上，位于价格上方或下方。

当价格在SAR点上方时，表明市场处于上升趋势；当价格在SAR点下方时，表明市场处于下降趋势。SAR点的位置会随着市场价格的变化而动态调整，其目的是帮助投资者在趋势发生反转时及时离场。

Python代码如下：

`def calculate_parabolic_sar(high_prices, low_prices, close_prices, acceleration_factor=0.02, maximum_acceleration_factor=0.2):       sar = [close_prices[0]]       is_rising = close_prices[1] > close_prices[0]       extreme_point = high_prices[0] if is_rising else low_prices[0]       af = acceleration_factor       for i in range(1, len(close_prices)):           if is_rising:               new_sar = sar[-1] + af * (extreme_point - sar[-1])               if low_prices[i] < new_sar:                   is_rising = False                   extreme_point = low_prices[i]                   af = acceleration_factor                   new_sar = extreme_point               else:                   if high_prices[i] > extreme_point:                       extreme_point = high_prices[i]                       af = min(af + acceleration_factor, maximum_acceleration_factor)           else:               new_sar = sar[-1] - af * (sar[-1] - extreme_point)               if high_prices[i] > new_sar:                   is_rising = True                   extreme_point = high_prices[i]                   af = acceleration_factor                   new_sar = extreme_point               else:                   if low_prices[i] < extreme_point:                       extreme_point = low_prices[i]                       af = min(af + acceleration_factor, maximum_acceleration_factor)           sar.append(new_sar)       return sar   `

投资中抛物线转向指标主要用于确定退出时机。

当投资者持有多头头寸时，若价格跌破SAR点，表明上升趋势可能结束，应考虑卖出股票；当持有空头头寸时，若价格升破SAR点，表明下降趋势可能反转，应考虑平仓。

抛物线转向指标尤其适用于趋势较为明显的市场环境，它能帮助投资者在趋势持续时紧紧跟随趋势，在趋势反转时及时离场，锁定利润或减少损失。

  

8.一目均衡表（Ichimoku Kinko Hyo）

一目均衡表是一种综合性的技术分析指标，它包含五条线和一个云带，能够同时提供趋势、支撑阻力、动量等多方面的信息。五条线分别为：

-   转折线（Tenkan-sen），计算方法是过去9个周期内最高价和最低价的平均值；
    
-   基准线（Kijun-sen），过去26个周期内最高价和最低价的平均值；先
    
-   行上线（Senkou Span A），转折线和基准线的平均值，向前绘制26个周期；
    
-   先行下线（Senkou Span B），过去52个周期内最高价和最低价的平均值，向前绘制26个周期；
    
-   滞后线（Chikou Span），当前收盘价向后绘制26个周期。云带则由先行上线和先行下线之间的区域构成。
    

Python代码如下：

`import numpy as np      def calculate_ichimoku(high_prices, low_prices, close_prices):       tenkan_sen = np.mean([np.max(high_prices[-9:]), np.min(low_prices[-9:])], axis = 0)       kijun_sen = np.mean([np.max(high_prices[-26:]), np.min(low_prices[-26:])], axis = 0)       senkou_span_a = (tenkan_sen + kijun_sen) / 2       senkou_span_b = np.mean([np.max(high_prices[-52:]), np.min(low_prices[-52:])], axis = 0)       chikou_span = close_prices[-26]       return tenkan_sen, kijun_sen, senkou_span_a, senkou_span_b, chikou_span   `

一目均衡表在投资分析中具有广泛应用。当转折线向上穿过基准线时，是短期买入信号；当转折线向下穿过基准线时，是短期卖出信号。云带可作为支撑和阻力区域，若价格在云带上方，表明市场处于多头趋势；若价格在云带下方，表明市场处于空头趋势。滞后线与价格的交叉也可提供交易信号。此外，通过观察价格与各线以及云带的相对位置和交叉关系，投资者能够全面了解市场的趋势、动量和潜在的反转点，制定更为合理的投资策略。

  

9.随机振荡指标（Stochastic Oscillator）

随机振荡指标是一种动量指标，用于衡量股票当前价格在一定时间段内价格范围中的相对位置。

它由%K线和%D线组成，%K线表示当前收盘价在过去n个周期内最高价和最低价区间内的相对位置，计算公式为：

```
%K = 100 * [(C - Ln) / (Hn - Ln)]
```

其中C为当前收盘价，Ln为过去n个周期内的最低价，Hn为过去n个周期内的最高价。%D线则是%K线的3日移动平均线。随机振荡指标的取值范围在0到100之间，通常当%K线和%D线超过80时，市场处于超买状态；当它们低于20时，市场处于超卖状态。

Python代码如下：

`import numpy as np      def calculate_stochastic_oscillator(high_prices, low_prices, close_prices, n=14):       highest_high = np.max(high_prices[-n:])       lowest_low = np`        