# 算法化生成趋势线

QuantML QuantML 2025-05-01 21:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490243&idx=1&sn=ffd58aacfc0ee356693a5ed5876d98d8&chksm=cf0acf1b3b3fc9f38db4991b1568094ba209816e2cebb4506c0136753dcddab878fa797e549f#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490243&idx=1&sn=ffd58aacfc0ee356693a5ed5876d98d8&chksm=cf0acf1b3b3fc9f38db4991b1568094ba209816e2cebb4506c0136753dcddab878fa797e549f#rd)

手动绘制趋势线既主观又耗时。本文介绍如何使用多锚点回归来发现方向、强度和汇聚点。

![](assets/001.jpg)

# 概述

大多数趋势通道依赖于任意点，假设对称性，并且在市场发生变化时无法适应。

交易者依赖这些通道来获得清晰度，但往往被虚假的突破和不清的反转所误导。

为了解决这个问题，我们通过算法实现了多锚点线性回归通道，这些通道能够适应真实的价格结构。

这些通道不是静态的，它们对市场的高点、低点和盘整期做出反应。

更妙的是，它们突出了不同趋势信号一致的汇聚区域。

![](assets/002.jpg)

# 我们将涵盖以下要点：

1.  从有意义的锚点生成三个不同的回归通道
    
2.  每个趋势线的统计指标，如斜率、和相关性
    
3.  用于过度延伸走势、趋势耗尽和结构一致性的视觉标记
    

## 1\. 多锚点方法

线性回归只有在有准确的锚点时，才能有效地绘制趋势通道。

锚点定义了回归的起点。没有它们，趋势线只是猜测。

该方法不是选择固定的回溯窗口，而是根据实际价格行为自动选择三个不同的锚点：

### 1.1 最高高点  潜在阻力

我们寻找最近的价格达到最高高点的柱状图。这个点标志着耗尽。从这里开始锚定可以捕捉下降阻力。

例如，如果过去800个柱状图中的最高高点出现在120个柱状图前，我们从那个柱状图开始拟合回归线到今天。

### 1.2 最低低点  潜在支撑

同样的逻辑，但方向相反。我们定位最近过去的最低低点。这个锚点标志着结构性支撑和潜在的反弹区域。

例如，如果最低低点是95个柱状图前，我们从那个柱状图向前回归。

### 1.3 最平斜率  中性阶段

这个锚点找到价格显示最小方向偏差的片段。它用于识别横向盘整。

我们扫描最近的窗口，并选择回归斜率最接近零的窗口：

斜率的窗口成为中性锚点。每个锚点产生一个独立的回归通道。对于每个通道：

-   中线是拟合的回归线：
    
-   残差测量与线的偏差：
    
-   残差的标准差定义了通道宽度：
    

### 通道边界：

上限：y+Do 下限：y-Do

D是一个固定偏差乘数，例如2。

### 为什么使用所有三个锚点？

每个锚点提供了对趋势的不同视角：

-   最高高点显示下降压力（动量）。
    
-   最低低点突出了看涨结构（均值回归）。
    
-   最平斜率找到犹豫区域（区间行为）。
    

当多个通道围绕相同的斜率或价格区域对齐时，那就是汇聚。

汇聚减少了噪音。它突出了不同价格行为之间的一致性。

如果所有通道都指向上方，趋势得到确认。

## 2\. Python实现

以下工作流程是模块化的，易于扩展以适应自定义锚点。

### 2.1 配置和参数

定义股票代码、日期范围和分析设置。这些包括：

MAX\_BARS：搜索锚点的最大回溯窗口。

DEV\_MULT：通道宽度的标准差乘数。

USE\_LOG\_SCALE：启用通过log(price)规范化趋势的选项。

USE\_EXP\_WEIGHT

`import numpy as np   import pandas as pd   import yfinance as yf   import matplotlib.pyplot as plt   from sklearn.linear_model import LinearRegression   from typing import Tuple      TICKER = "NVDA"# 要分析的符号   START_DATE = "2022-01-01"   END_DATE = "2026-01-01"   MAX_BARS = 2000# 锚点搜索的最大回溯窗口   DEV_MULT = 2# 通道宽度 = 标准差 * 这个乘数   USE_LOG_SCALE = False# 启用log(price)转换   USE_EXP_WEIGHT = False# 如果更可取，使用指数样本权重（使用权重）   ANCHORS = ["BarHighest", "BarLowest", "SlopeZero"]   CHANNEL_COLORS = ["lime", "orange", "cyan"]   `

### 2.2 辅助函数

如果启用了对数刻度，则使用以下方法转换价格：

这有助于稳定方差并线性化指数趋势。在绘图之前，我们反转转换。

`def transform_price(p: pd.Series) -> pd.Series:       """如果启用，则使用对数刻度转换价格数据。"""       return np.log10(p) if USE_LOG_SCALE else p      def inverse_transform_price(p: np.ndarray) -> np.ndarray:       """反转转换价格数据。"""       return np.power(10, p) if USE_LOG_SCALE else p      def exponential_weights(n: int, decay: float = 0.9) -> np.ndarray:       """返回给定长度的指数权重。"""       return decay ** np.arange(n)[::-1]   `

### 锚点检测

每种锚点类型决定了回归的窗口长度：

-   BarHighest：找到自最高高点以来的柱状图数量。
    
-   BarLowest：同上，针对最低低点。
    
-   SlopeZero：搜索斜率最接近零的片段。
    

`def find_bar_highest(high_series: pd.Series, max_bars: int) -> int:       """找到自最高高点以来的柱状图长度。"""       window = high_series[-max_bars:]       idxmax = window.idxmax()       return len(high_series) - high_series.index.get_loc(idxmax)      def find_bar_lowest(low_series: pd.Series, max_bars: int) -> int:       """找到自最低低点以来的柱状图长度。"""       window = low_series[-max_bars:]       idxmin = window.idxmin()       return len(low_series) - low_series.index.get_loc(idxmin)      def find_slope_zero(series: pd.Series, max_bars: int) -> int:       """找到斜率最接近零的片段长度。              返回最佳长度。"""       best_len = 2       best_slope = float("inf")       for L in range(2, min(max_bars, len(series))):           y = series.iloc[-L:]           x = np.arange(L).reshape(-1, 1)           model = LinearRegression()           model.fit(x, y.values)           slope = model.coef_[0]           if abs(slope) < best_slope:               best_slope = abs(slope)               best_len = L       return best_len   `

对于每个锚点窗口，我们拟合一个线性回归模型。我们计算残差和标准差以及通道边界。

我们提取斜率（1）以评估趋势方向，皮尔逊相关系数和用于趋势强度。

`def calc_regression_channel(series: pd.Series, length: int) -> Tuple[np.ndarray, np.ndarray, np.ndarray, float, float, float]:       """计算回归通道线和指标。              返回：回归线、上通道、下通道、斜率、$R^2$和皮尔逊r。"""       y = series.iloc[-length:]       x = np.arange(length).reshape(-1, 1)       model = LinearRegression()       if USE_EXP_WEIGHT:           weights = exponential_weights(length)           weights /= weights.sum()           model.fit(x, y.values, sample_weight=weights)       else:           model.fit(x, y.values)       slope = model.coef_[0]       intercept = model.intercept_       reg_line = intercept + slope * x.squeeze()       residuals = y.values - reg_line       stdev = np.std(residuals)       r_val = np.corrcoef(np.arange(length), y.values)[0, 1]       r2 = r_val ** 2       return reg_line, reg_line + DEV_MULT * stdev, reg_line - DEV_MULT * stdev, slope, r2, r_val   `

### 2.3 数据获取

价格数据是通过yfinance API从Yahoo Finance获取的。我们清理数据，应用转换，并准备进行回归。

`try:       data = yf.download(TICKER, start=START_DATE, end=END_DATE, interval="1d")   except Exception as e:       print(f"Error downloading data: {e}")       return   if data.empty:       print("No data returned.")       return   if isinstance(data.columns, pd.MultiIndex):       data.columns = data.columns.get_level_values(0)   data.dropna(inplace=True)   close = data["Close"]   high = data["High"]   low = data["Low"]   close_t = transform_price(close)   `

### 2.4 绘图和汇聚

对于每个锚点：

-   绘制中线和通道带。
    
-   注释显示锚点名称、长度和相关性。
    
-   带子是彩色编码和半透明的，以便视觉清晰。
    

我们检查三个中线是否收敛

这标志着锚点之间的结构一致性。

然后我们评估当前价格相对于所有通道：

-   高于所有带子  过度延伸的上升趋势
    
-   低于所有带子  超卖的下降趋势
    
-   在任何带子内  在通道内
    

这个汇聚条件可能过于严格。你可以通过例如确定所有回归斜率的趋势是否一致来放宽条件。

`fig, ax = plt.subplots(figsize=(12, 6))   plt.style.use("dark_background")   ax.plot(close.index, close, color="white", linewidth=1.2, label="Close")      channel_info = []      for name, color in zip(ANCHORS, CHANNEL_COLORS):       if name == "BarHighest":           length = find_bar_highest(high, MAX_BARS)       elif name == "BarLowest":           length = find_bar_lowest(low, MAX_BARS)       elif name == "slopeZero":           length = find_slope_zero(close_t, MAX_BARS)       length = max(2, min(length, len(close)))          mid, top, bot, slope, r2, r_val = calc_regression_channel(close_t, length)       mid_plot = inverse_transform_price(mid)       top_plot = inverse_transform_price(top)       bot_plot = inverse_transform_price(bot)       xvals = close.index[-length:]          ax.plot(xvals, mid_plot, color=color, linewidth=2, label=f"{name}")       ax.plot(xvals, top_plot, color=color, linestyle="--")       ax.plot(xvals, bot_plot, color=color, linestyle="--")       ax.fill_between(xvals, bot_plot, top_plot, color=color, alpha=0.15)          trend = "Up"if slope > 0.01else"Down"if slope < -0.01else"Flat"       last_mid = mid_plot[-1]          ax.annotate(f"{name}\nl·={length}\nR·={r_val:.2f}", xy=(xvals[-1], last_mid), xytext=(5, 0), textcoords="offset points", color=color, fontsize=9, va="center", fontweight="bold")          channel_info.append({           "anchor": name,           "length": length,           "slope": slope,           "r2": r2,           "r": r_val,           "last_mid": last_mid,           "last_top": top_plot[-1],           "last_bot": bot_plot[-1],           "trend": trend,           "color": color,           "x_pos": xvals[-1]       })      # 汇聚和当前趋势检查   current_condition = ""   confluence_detected = False   if channel_info:       mids = [c["last_mid"] for c in channel_info]       avg_mid = np.mean(mids)       stdev_mids = np.std(mids)       threshold = 0.5 * stdev_mids  # 汇聚阈值       if np.max(mids) - np.min(mids) < threshold:           confluence_detected = True           x_confl = max([c["x_pos"] for c in channel_info])           ax.annotate("Confluence", xy=(x_confl, avg_mid), xytext=(-100, -30), textcoords="offset points", arrowprops=dict(arrowstyle="->", color="yellow"), color="yellow", fontsize=9, fontweight="bold")   current_price = close.iloc[-1]   tops = [c["last_top"] for c in channel_info]   bots = [c["last_bot"] for c in channel_info]   if current_price > max(tops):       current_condition = "Overextended Uptrend"   elif current_price < min(bots):       current_condition = "Oversold Downtrend"   else:       current_condition = "Within Channels"      # 最终绘图调整和标题更新   ax.set_facecolor("#1F1B1B")   ax.grid(True, alpha=0.2)   title_text = f"Multi-Anchored Regression Channels: {TICKER}"   if current_condition:       title_text += f" | {current_condition}"   title_text += f" | Confluence: {'Detected' if confluence_detected else 'None'}"   ax.set_title(title_text, color="orange")   ax.set_xlabel("Date")   ax.set_ylabel("Price")   ax.legend(loc="lower right", fontsize=8)   plt.tight_layout()   plt.show()      # 打印指标摘要      print("\nChannel Report")   print("------------------------------------------------------------")   print("Anchor | Length | Slope | R | R^2 | Trend")   for ch in channel_info:       print(f"{ch['anchor']:<12} | {ch['length']:<6} | {ch['slope']:+.4f} | {ch['r']:+.4f} | {ch['r2']:+.4f} | {ch['trend']:<6}")   `

![](assets/001.jpg)图1. NVDA上的多锚点回归通道。每个通道探索了独特的趋势视角——阻力、支撑和盘整。

## 3\. 关键要点和使用案例

多锚点回归通道是统计基础工具。更好的是，它们适应市场实际行为。

### 3.1 一张图表，三个视角

每个锚点隔离了市场行为的不同阶段：

BarHighest = 动量耗尽

BarLowest = 结构支撑

SlopeZero = 压缩区域

当一起查看时，它们提供了价格行为的分层读数：哪里力量正在消退，哪里买家可能介入，以及哪里突破压力正在积聚。

### 3.2 汇聚是情境，而非确认

当中线聚集时，它标志着多个视角的趋同趋势。

这不能保证后续发展，但它减少了噪音。

例如，如果所有三个通道都显示向上斜率，并且中线汇聚，你正在观察一个协调的上升趋势，理想情况下可以逐步增加力量或跟随动量。

### 3.3 发现过度延伸和均值回归

当价格突破所有上轨时，相对于所有三个通道来说，这个走势在统计上是极端的。

这并不是自动做空，但这是一个警告标志。在由收益驱动的飙升中，如那些在或中看到的，这些区域可以预示短期均值回归。

当与成交量或RSI背离配对时，它们有助于在炒作消退时做空。同样的道理也适用于超卖的下降趋势，对于在恐慌性下跌后把握入场时机非常有用。

### 3.4 压缩区域导致扩张

斜率零锚点在区间震荡市场中特别有用。它识别了价格横向移动且几乎没有偏差的窗口。 当价格突破这个通道的带子时，可能会导致爆炸性走势。 例如，在2023年8月的SAPL，一个平坦斜率锚点捕捉到了多周的盘整。 当价格最终突破回归带时，它在两周内启动了15%的走势。

### 3.5 自适应头寸调整和风险配置

每个通道都带有已知的斜率、和带宽。这对于头寸调整和止损配置非常宝贵。

更高的 = 更清晰的趋势 → 更有信心

更宽的通道 = 更多波动性 → 相应调整止损

斜率指导预期的方向偏差

如果你在上升斜率通道的中线附近做多，并且强，那么一个合理的止损就位于下轨的稍下方。

### 结论性思考

大多数工具基于任意规则绘制趋势线。然而，在这里我们提出了一个更客观的算法化方法。

三个回归通道允许你看到高、低和盘整期。这为你提供了市场结构的视角。

作者 Cristian Velasquez

  

完整代码见星球，加入QuantML星球，与星主和800+专业人士一起交流学习：

![图片](assets/003.webp)