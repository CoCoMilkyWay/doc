# 支撑线、压力线的智能识别算法——原理、步骤、代码

蝴蝶量化 随率而动的因子工厂 2026-01-02 21:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484373&idx=1&sn=bd8d8e465a39f6088e7eb75891e4f334&chksm=c04c94ae79b0a8eea01f05ef98526eba27bd6ee7c5a0150f546ec18cb3a3ca76c06557874912#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484373&idx=1&sn=bd8d8e465a39f6088e7eb75891e4f334&chksm=c04c94ae79b0a8eea01f05ef98526eba27bd6ee7c5a0150f546ec18cb3a3ca76c06557874912#rd)

## 技术背景

之前我们做了多因子系列的选股因子，对于单个标的的择时方面内容较少。本期文章我们就着眼于单个标的的择时算法，主要方法是基于技术指标中的支撑线、阻力线的突破与震荡，做相应的择时交易。核心在于，使用机器学习方法识别**支撑线、压力线。**

技术指标里面有一个比较重要的部分：形态类技术分析。包括：**对称三角形、上三角、下三角、旗形结构、扩散三角等等**，这些形态的突破往往预示着一段**趋势行情**的开启或者结束。在技术分析领域，准确的识别这些箱体的形态是大部分技术分析交易者终身追求的目标。

既然很多技术交易者通过这些方法取得成功，那么它的存在肯定有一定的道理。而且这些形态类的走势，相同形态往往走势类似，应该是能够用过代码、数据、机器学习识别出来的。

**支撑线、压力线**作为上述形态分析关键，如何准确的识别一段行情的压力线、支撑线就成了技术面量化的关键问题。本期内容我们从经典技术分析理论出发，将其核心规则（如压力线/支撑线的几何特征）转化为具体的数学参数（如斜率），然后进行大规模历史回测，以验证这些传统方法的实战价值，构造一些具体的择时策略，准确的识别支撑线、压力线辅助交易员决策。

## 原理与知识

本章我们介绍一些文章用到一些必备知识点。

### 1\. 形态定义

将经典技术形态的定性描述转化为压力线和支撑线斜率的定量规则。这是将主观经验客观化的关键一步。

-   **持续形态定义示例**：
    

-   **上升三角形**：压力线斜率 ≈ 0 （水平），支撑线斜率 > 0 （微升）。
    
-   **对称三角形**：压力线斜率 < 0 （微降），支撑线斜率 > 0 （微升）。
    
-   **矩形**：压力线和支撑线斜率都 ≈ 0 （水平）。
    

-   **通道形态定义示例**：
    

-   **上升通道发散**：压力线和支撑线斜率都 > 0 （向上），且压力线斜率 > 支撑线斜率（通道扩大）。
    

### 2、分为回归算法简介

直接deepseek更加清晰，本文直接调用sklearn中的`sklearn.linear_model.QuantileRegressor`算法直接搞定。

## 具体步骤

### 1、如何识别压力线与支撑线？

本文没有采用复杂的图像识别，而是借鉴了Lang等（2012）提出的 **“局部高低点 + 分位数回归”** 的方法。

**具体步骤如下：**

-   **步骤一：数据准备**
    

-   **样本**：A股的宽基指数（如沪深300）和申万一级行业指数。
    
-   **回溯期**：固定为**120个交易日**，用于识别一个形态，这是回溯期的大小跟识别出的形态有很大的关系。
    
-   **标准化**：将回溯期首日价格设为100，以消除不同指数价格量纲的影响。
    

-   **步骤二：识别局部高点和低点**
    

-   **方法**：使用**局部极值法**。设定一个时间窗口（w=5个交易日），如果某天的价格是其前后5天内的最高价，则为**局部高点**；是最低价，则为**局部低点**。
    

-   **步骤三：绘制压力线与支撑线**
    

-   **方法**：对识别出的所有**局部高点**进行**分位数回归**，分位值设为**0.9**。这条回归线代表了股价在大部分时间里难以突破的上限，即**压力线**。
    
-   同理，对**局部低点**进行分位数回归，分位值设为**0.1**，得到**支撑线**。
    
-   **优点**：这种方法能自动找到一条能够包含大部分局部高点/低点的直线，其**斜率**即为关键量化参数，用于识别形态的类型。
    

### 2\. 评价标准与结论

本节主要内容为：如何评价回测的结果？以及给出了本文中方法的一些结论。统计了在股价**突破压力线**后，持有不同天数（5，10，20天）的平均收益率、胜率和盈亏比。

**主要结论：**

-   **部分经典形态确实有效**：在持续形态中，**对称三角形、矩形、旗形**在突破后，相对于全体样本，能取得更高的收益。
    
-   **通道形态表现更稳定**：在所有回溯期测试中（120日、60日、240日），**上升通道发散**形态在突破后表现 consistently 较好。这意味着处于一个温和加速上涨的通道中，向上突破的成功率更高。
    
-   **“平台突破”是高效模式**：报告发现，压力线或支撑线的斜率与后续收益呈**倒U型关系**（见报告图9-12）。即当斜率在**0附近（接近水平）** 时，突破后的收益最高。斜率过大（向上或向下过于陡峭）反而收益会降低。这验证了“横盘整理后选择方向”的经典策略的有效性。
    
-   **喇叭形（扩散形态）风险高**：该形态在宽基指数中表现极差，说明无序扩散后的突破方向难以把握，风险较大。
    

### 可视化结果

**1、中证1000的识别结果**

![](assets/001.png)

**2、沪深300的识别结果**

![](assets/002.png)

**3、多指数指标斜率统计**

![](assets/003.png)

## python代码

直接采用sklearn中的QuantileRegressor方法调用分位数回归方法实现算法 我将详细解读这篇渤海证券关于压力线与支撑线识别算法的研报，并提供Python代码实现。**代码部分由deepseek生成，笔者调试，亲测有效。只需要把data\_file换成自己本地的数据路径即可。**

-   **1\. 局部高低点识别**
    

-   使用`scipy.signal.argrelextrema`函数识别局部极值
    
-   通过`order`参数控制窗口大小（避免噪声干扰）
    

-   **2\. 分位数回归**
    

-   使用`sklearn.linear_model.QuantileRegressor`
    
-   压力线：0.9分位数（拟合高点中的上边界）
    
-   支撑线：0.1分位数（拟合低点中的下边界）
    

### python识别程序

`    import numpy as np   import pandas as pd   import matplotlib.pyplot as plt   import seaborn as sns   from scipy import stats   from sklearn.linear_model import QuantileRegressor   from scipy.signal import argrelextrema   import warnings      warnings.filterwarnings('ignore')      # 设置中文显示      plt.rcParams['font.sans-serif'] = ['PingFang SC', 'STHeiti', 'Arial Unicode MS']   plt.rcParams['axes.unicode_minus'] = False# 解决负号显示问题         class PressureSupportLineAnalyzer:       """       压力线与支撑线识别分析器       基于渤海证券研报方法实现       """          def __init__(self,                    data_file:str,                    start_date:str,                    end_date:str,                    lookback_period=120,                    window=5,                    pressure_quantile=0.9,                    support_quantile=0.1):           """           初始化参数           """           self.data_file = data_file           self.start_date = pd.to_datetime(start_date).date()           self.end_date = pd.to_datetime(end_date).date()           self.lookback = lookback_period  # 回溯期           self.window = window  # 局部高低点窗口           self.pressure_q = pressure_quantile  # 压力线分位数           self.support_q = support_quantile  # 支撑线分位数          def get_stock_data(self, ticker):           """           获取股票/指数数据           """           try:               data = pd.read_csv(self.data_file + f'/{ticker}.csv')               if data.empty:                   print(f"无法获取{ticker}的数据")                   returnNone              except Exception as e:               print(f"获取数据时出错: {e}")               returnNone           else:               data['date'] = pd.to_datetime(data['date']).dt.date               data = data[data['date'].between(self.start_date, self.end_date)]               return data             def find_local_extrema(self, prices, window=5):           """           识别局部高点和低点           参数:               prices: 价格序列               window: 窗口大小           返回:               high_points: 局部高点索引和价格               low_points: 局部低点索引和价格           """           # 使用argrelextrema寻找局部极值           high_indices = argrelextrema(prices.values, np.greater, order=window)[0]           low_indices = argrelextrema(prices.values, np.less, order=window)[0]              # 确保极值点数量合理           high_indices = high_indices[high_indices < len(prices)]           low_indices = low_indices[low_indices < len(prices)]              high_points = pd.DataFrame({               'index': high_indices,               'price': prices.iloc[high_indices].values           })              low_points = pd.DataFrame({               'index': low_indices,               'price': prices.iloc[low_indices].values           })              return high_points, low_points          def quantile_regression_fit(self, x, y, quantile):           """           分位数回归拟合           参数:               x: 自变量（时间索引）               y: 因变量（价格）               quantile: 分位数           返回:               slope: 斜率               intercept: 截距           """           # 使用sklearn的QuantileRegressor           x_reshaped = x.reshape(-1, 1)           model = QuantileRegressor(quantile=quantile, alpha=0)           model.fit(x_reshaped, y)              slope = model.coef_[0]           intercept = model.intercept_              return slope, intercept          def normalize_prices(self, prices):           """           价格标准化：将第一天的价格设为100           """           return prices / prices.iloc[0] * 100          def identify_pressure_support_lines(self,                                           prices,                                           plot=False):           """           识别压力线和支撑线           """           if len(prices) < self.lookback:               print(f"数据长度({len(prices)})小于回溯期({self.lookback})")               returnNone              # 价格标准化           normalized_prices = self.normalize_prices(prices)              # 识别局部高低点           high_points, low_points = self.find_local_extrema(normalized_prices, self.window)              if len(high_points) < 2or len(low_points) < 2:               print("局部高低点数量不足")               returnNone              # 分位数回归拟合           # 压力线：局部高点用0.9分位数           pressure_slope, pressure_intercept = self.quantile_regression_fit(               high_points['index'].values,               high_points['price'].values,               self.pressure_q           )              # 支撑线：局部低点用0.1分位数           support_slope, support_intercept = self.quantile_regression_fit(               low_points['index'].values,               low_points['price'].values,               self.support_q           )              # 计算压力线和支撑线           x_range = np.arange(len(normalized_prices))           pressure_line = pressure_intercept + pressure_slope * x_range           support_line = support_intercept + support_slope * x_range              result = {               'pressure_slope': pressure_slope,               'pressure_intercept': pressure_intercept,               'support_slope': support_slope,               'support_intercept': support_intercept,               'pressure_line': pressure_line,               'support_line': support_line,               'normalized_prices': normalized_prices.values,               'high_points': high_points,               'low_points': low_points           }              if plot:               self.plot_pressure_support(normalized_prices, result)              return result          def plot_pressure_support(self, prices, result):           """           绘制压力线和支撑线           """           fig, ax = plt.subplots(figsize=(15, 8))              # 绘制价格线           ax.plot(prices.index, prices.values, label='价格', linewidth=2, color='black')              # 绘制压力线和支撑线           ax.plot(prices.index, result['pressure_line'],                   label='压力线', linestyle='--', color='red', linewidth=2)           ax.plot(prices.index, result['support_line'],                   label='支撑线', linestyle='--', color='green', linewidth=2)              # 绘制局部高低点           ax.scatter(prices.index[result['high_points']['index']],                      result['high_points']['price'],                      color='red', s=50, label='局部高点', zorder=5)           ax.scatter(prices.index[result['low_points']['index']],                      result['low_points']['price'],                      color='green', s=50, label='局部低点', zorder=5)              # 填充压力线和支撑线之间的区域           ax.fill_between(prices.index,                           result['pressure_line'],                           result['support_line'],                           alpha=0.2, color='gray')              ax.set_title('压力线与支撑线识别', fontsize=16)           ax.set_xlabel('日期', fontsize=12)           ax.set_ylabel('标准化价格', fontsize=12)           ax.legend(fontsize=12)           ax.grid(True, alpha=0.3)              plt.tight_layout()           plt.show()          def identify_pattern(self, pressure_slope, support_slope):           """           根据斜率识别形态           返回形态名称           """           # 形态定义（根据研报表1）           patterns = {               '上升三角形': ((-0.05, 0.05), (0.05, 0.15)),               '对称三角形': ((-0.15, -0.05), (0.05, 0.15)),               '下降三角形': ((-0.05, 0.05), (-0.15, -0.05)),               '矩形': ((-0.05, 0.05), (-0.05, 0.05)),               '旗形': ((-0.15, -0.05), (-0.15, -0.05)),               '喇叭形': ((0.05, np.inf), (-np.inf, -0.05))           }              for pattern_name, (p_range, s_range) in patterns.items():               p_min, p_max = p_range               s_min, s_max = s_range                  if p_min <= pressure_slope <= p_max and s_min <= support_slope <= s_max:                   return pattern_name              return'其他形态'          def identify_channel_pattern(self, pressure_slope, support_slope):           """           识别通道形态           """           # 通道形态定义（根据研报表2）           if pressure_slope > 0and support_slope > 0:               if pressure_slope < support_slope:                   return'上升通道收敛'               else:                   return'上升通道发散'           elif-0.15 < pressure_slope < 0.05and-0.15 < support_slope < 0.05:               return'横盘'           elif pressure_slope < 0and support_slope < 0:               if pressure_slope < support_slope:                   return'下降通道收敛'               else:                   return'下降通道发散'              return'其他通道'          def calculate_breakout_returns(self, prices, pressure_line, hold_days=[5, 10, 20]):           """           计算突破压力线后的收益           """           # 寻找突破点：价格上穿压力线           breakout_indices = []           for i in range(1, len(prices)):               if prices[i - 1] <= pressure_line[i - 1] and prices[i] > pressure_line[i]:                   breakout_indices.append(i)              returns = {}           for days in hold_days:               period_returns = []               for idx in breakout_indices:                   if idx + days < len(prices):                       ret = (prices[idx + days] - prices[idx]) / prices[idx]                       period_returns.append(ret)                  if period_returns:                   returns[f'持有{days}天'] = {                       '平均收益': np.mean(period_returns),                       '胜率': np.mean([1if r > 0else0for r in period_returns]),                       '样本数': len(period_returns)                   }              return returns          def analyze_index(self, ticker='000852.SH'):           """           完整分析流程           """           print(f"开始分析 {ticker}...")              # 1. 获取数据           data = self.get_stock_data(ticker)           if data isNone:               return              # 使用收盘价           prices = data['close']              # 2. 识别压力线和支撑线（使用最近的回溯期）           recent_prices = prices[-self.lookback:]           result = self.identify_pressure_support_lines(recent_prices, plot=True)              if result isNone:               return              # 3. 识别形态           pattern = self.identify_pattern(result['pressure_slope'], result['support_slope'])           channel_pattern = self.identify_channel_pattern(result['pressure_slope'], result['support_slope'])              print(f"\n形态识别结果:")           print(f"持续形态: {pattern}")           print(f"通道形态: {channel_pattern}")           print(f"压力线斜率: {result['pressure_slope']:.6f}")           print(f"支撑线斜率: {result['support_slope']:.6f}")              # 4. 计算突破收益           returns = self.calculate_breakout_returns(               result['normalized_prices'],               result['pressure_line']           )              if returns:               print(f"\n突破压力线后收益统计:")               for period, stats in returns.items():                   print(f"{period}: 平均收益={stats['平均收益']:.2%}, "                         f"胜率={stats['胜率']:.2%}, 样本数={stats['样本数']}")              return result, pattern, channel_pattern         # 使用示例   def main():       # 初始化分析器       analyzer = PressureSupportLineAnalyzer(           data_file='./data/data_folder/index_ohlc',           start_date='2020-01-01',           end_date='2023-01-01',           lookback_period=120,           window=5,           pressure_quantile=0.9,           support_quantile=0.1       )          # 分析恒生指数       result, pattern, channel = analyzer.analyze_index(           ticker='000852.SH',       )          # 批量分析多个指数       indices = ['000852.SH', '000300.SH']            all_results = []       for idx in indices:           print(f"\n{'=' * 50}")           res = analyzer.analyze_index(idx, '2022-01-01', '2024-01-01')           if res:               all_results.append(res)          return analyzer, all_results         if __name__ == "__main__":       analyzer, results = main()         # 参数敏感性分析函数   def parameter_sensitivity_analysis(prices,                                      data_file='./data/data_folder/index_ohlc',                                      start_date='2024-01-01',                                      end_date='2026-01-01',                                      lookback_periods=[60, 120, 240],                                      windows=[3, 5, 10],                                      quantiles=[(0.85, 0.15), (0.9, 0.1), (0.95, 0.05)]):       """       参数敏感性分析       """       sensitivity_results = []          for lookback in lookback_periods:           for window in windows:               for p_q, s_q in quantiles:                   temp_analyzer = PressureSupportLineAnalyzer(                       data_file= data_file,                       start_date=start_date,                       end_date=start_date,                       lookback_period=lookback,                       window=window,                       pressure_quantile=p_q,                       support_quantile=s_q                   )                      result = temp_analyzer.identify_pressure_support_lines(prices, plot=False)                   if result:                       pattern = temp_analyzer.identify_pattern(                           result['pressure_slope'],                           result['support_slope']                       )                          sensitivity_results.append({                           'lookback': lookback,                           'window': window,                           'pressure_q': p_q,                           'support_q': s_q,                           'pressure_slope': result['pressure_slope'],                           'support_slope': result['support_slope'],                           'pattern': pattern                       })          return pd.DataFrame(sensitivity_results)            # 可视化函数   def visualize_slope_distribution(analyzer, tickers):       """       可视化不同指数的斜率分布       """       slopes_data = []          for ticker in tickers:           data = analyzer.get_stock_data(ticker)           if data isnotNone:               prices = data['close']               recent_prices = prices[-analyzer.lookback:]               result = analyzer.identify_pressure_support_lines(recent_prices, plot=False)                  if result:                   slopes_data.append({                       'Ticker': ticker,                       'Pressure_Slope': result['pressure_slope'],                       'Support_Slope': result['support_slope']                   })          if slopes_data:           df = pd.DataFrame(slopes_data)              fig, axes = plt.subplots(1, 2, figsize=(15, 6))              # 压力线斜率分布           axes[0].bar(df['Ticker'], df['Pressure_Slope'], color='red', alpha=0.7)           axes[0].axhline(y=0, color='black', linestyle='-', linewidth=0.5)           axes[0].set_title('压力线斜率分布', fontsize=14)           axes[0].set_ylabel('斜率', fontsize=12)           axes[0].tick_params(axis='x', rotation=45)              # 支撑线斜率分布           axes[1].bar(df['Ticker'], df['Support_Slope'], color='green', alpha=0.7)           axes[1].axhline(y=0, color='black', linestyle='-', linewidth=0.5)           axes[1].set_title('支撑线斜率分布', fontsize=14)           axes[1].set_ylabel('斜率', fontsize=12)           axes[1].tick_params(axis='x', rotation=45)              plt.tight_layout()           plt.show()              return df          returnNone    `

### 代码使用示例

`from test2 import *   # test2 为上一个程序保存的文件名   # 1. 基本使用   analyzer = PressureSupportLineAnalyzer(data_file='./data/data_folder/index_ohlc',                                          start_date='2024-01-01',                                          end_date='2026-01-01',                                          lookback_period=120,                                          window=5,                                          pressure_quantile=0.9,                                          support_quantile=0.1)      # 获取数据   data = analyzer.get_stock_data('000852.SH')  # 上证指数   prices = data['close']      # 分析最近120天的形态   recent_prices = prices[-120:]   result = analyzer.identify_pressure_support_lines(recent_prices, plot=True)      # 识别形态   if result:       pattern = analyzer.identify_pattern(result['pressure_slope'], result['support_slope'])       print(f"识别到的形态: {pattern}")      # 2. 参数敏感性分析   sensitivity_df = parameter_sensitivity_analysis(prices)   print(sensitivity_df.head())      # 3. 多指数比较   tickers = ['000852.SH', '000300.SH']   slope_df = visualize_slope_distribution(analyzer, tickers)   `

## 总结

本文从技术分析的角度出发，对其中形态突破类的分析做出了量化分析。主要方法是通过回归识别：支撑线、压力线。根据两条线的斜率判断是哪一种形态，然后分别给出了不同形态的突破成功概率等等。

**各形态突破后，不同持仓周期的上涨概率**

![](assets/004.png)

![](assets/005.png)

### 回溯期的思考

选择不同的回溯期（如60日 vs 240日），可能会识别出完全不同的形态（如对称三角形 vs 下降通道），从而导致相反的结论。这是技术分析量化中一个尚未完美解决的主观性难题。个人认为这不是一个很关键的问题，因为在技术分析中，就有类似的周期选择与不确定性

### 产品呈现

通过上面的文章，我们很清楚看到有一些突破获胜概率超6成，并且平均收益超3%。显然这是一个比较优秀的择时策略思路。由于时间原因目前还没有写成完整的交易策略。 在未来我们将会跟大家一起开发支撑线、压力线的识别程序，将会开放给星球用户使用，但是短期内难以实现，我们可能会分出部分星球费用，用于支付小伙伴们参加星球中工具的共建与内容扩展。