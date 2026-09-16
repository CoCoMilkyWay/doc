# ATR

fintechhaibin FinTechHi 2025-02-26 22:13 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485714&idx=1&sn=48fa163da15c31446972fb1d67d23a0f&chksm=fba48b5202c8735f91be0ac7ad7610280b51c3d92041bc2d46b9cb4abe704a08cf250e892c07#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485714&idx=1&sn=48fa163da15c31446972fb1d67d23a0f&chksm=fba48b5202c8735f91be0ac7ad7610280b51c3d92041bc2d46b9cb4abe704a08cf250e892c07#rd)

文章 [动态止损过程的参数优化](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485355&idx=1&sn=1ac94ae08e693d23ba9b05d729014234&scene=21#wechat_redirect) 中提到通过ATR来作为择时交易的出入场信号。

今天再重新学习了下这个指标，记录下，看能不能再实际中应用到。

ATR（Average True Range，平均真实波动范围）是由J. Welles Wilder在其1978年出版的《New Concepts in Technical Trading Systems》一书中提出的一个技术分析指标。ATR用于衡量市场的波动性，通常用于确定止损点和交易策略中的风险管理。

**ATR的计算方法如下：**

1.  **计算真实波动范围（True Range，TR）**： 真实波动范围是以下三者中的最大值：
    
    公式：
    

-   当前最高价与当前最低价的差值
    
-   当前最高价与前一交易日收盘价的绝对差值
    
-   当前最低价与前一交易日收盘价的绝对差值
    

3.  **计算平均真实波动范围（ATR）**： ATR是一定周期内（通常为14天）的真实波动范围的移动平均值。
    
    公式：其中，n是周期长度，通常为14。
    

**ATR的应用场景主要如下：**

-   确定止损点： ATR可以用来设置止损点。例如，可以将止损点设置为买入价格减去一定倍数的ATR值，这样可以根据市场的波动性动态调整止损点。
    
-   衡量市场波动性： ATR值越高，表示市场波动性越大；ATR值越低，表示市场波动性越小。交易者可以根据ATR值调整交易策略。
    
-   过滤交易信号： ATR可以用来过滤交易信号，避免在市场波动性较低时进行交易，从而减少交易噪音。
    

以下是一个计算ATR且如何在交易策略中应用ATR的示例代码：

`import pandas as pd   import numpy as np      def calculate_atr(data, atr_window=14):       data['TR'] = np.maximum((data['High'] - data['Low']),                               np.maximum(abs(data['High'] - data['Close'].shift(1)),                                          abs(data['Low'] - data['Close'].shift(1))))  # 计算真实波动范围（TR）       data['ATR'] = data['TR'].rolling(window=atr_window).mean()  # 计算平均真实波动范围（ATR）       return data      # 示例数据   data = pd.DataFrame({       'High': [10, 11, 12, 13, 14],       'Low': [8, 9, 10, 11, 12],       'Close': [9, 10, 11, 12, 13]   })      # 计算ATR   data = calculate_atr(data)   print(data)   `

假设我们有一个简单的交易策略，当收盘价高于某个移动平均线时买入，当收盘价低于某个移动平均线时卖出。我们可以使用ATR来设置止损点：

`def calculate_stop_loss(data, atr_multiplier=2):       data['Buy_Stop_Loss'] = data['Close'] - (data['ATR'] * atr_multiplier)  # 计算买入止损       data['Sell_Stop_Loss'] = data['Close'] + (data['ATR'] * atr_multiplier)  # 计算卖出止损       return data      # 计算止损点   data = calculate_stop_loss(data)   print(data)   `

通过上述方法，我们可以动态调整止损点，以适应市场的波动性，从而更好地管理交易风险。

**ATR乘数**

ATR（平均真实波动范围）是一个衡量市场波动性的指标。  
为了更好地管理交易风险，交易者通常会给ATR一个乘数，用于动态调整止损点。这个乘数可以帮助交易者根据市场的波动性来设置更合理的止损点，从而避免在市场波动较大时被过早止损。

![](assets/001.png)

例如，如果ATR是1.50元，乘数是2，那么止损点距离收盘价上下各3元。在高波动性事件期间，乘数会更高，以避免快速止损。乘数的选择取决于交易者的风险承受能力。

以下是一个计算ATR并应用乘数来设置止损点的示例代码：

`import warnings   import yfinance as yf   import numpy as np   import pandas as pd   import matplotlib.pyplot as plt   import logging   import json   import os      warnings.filterwarnings('ignore')  # 忽略警告      # 配置日志   logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')      def fetch_data(symbol, start, end):       logging.info(f"获取 {symbol} 从 {start} 到 {end} 的数据")       data = yf.download(symbol, start=start, end=end)       if data.empty:           raise ValueError("未获取到数据")       return data      def calculate_atr(data, atr_window):       logging.info(f"计算ATR，窗口大小为 {atr_window}")       data['TR'] = np.maximum((data['High'] - data['Low']),                               np.maximum(abs(data['High'] - data['Close'].shift(1)),                                          abs(data['Low'] - data['Close'].shift(1))))  # 计算真实波动范围（TR）       data['ATR'] = data['TR'].rolling(window=atr_window).mean()  # 计算平均真实波动范围（ATR）       return data      def calculate_stop_loss(data, atr_multiplier):       logging.info(f"使用ATR倍数 {atr_multiplier} 计算止损")       data['Buy_Stop_Loss'] = data['Close'] - (data['ATR'] * atr_multiplier)  # 计算买入止损       data['Sell_Stop_Loss'] = data['Close'] + (data['ATR'] * atr_multiplier)  # 计算卖出止损       return data      def plot_atr_boundaries(data, symbol, atr_multiplier):       logging.info(f"绘制 {symbol} 的ATR边界")       plt.figure(figsize=(14, 7))       plt.plot(data['Close'], label='收盘价', color='blue')  # 绘制收盘价       plt.plot(data['Buy_Stop_Loss'], label=f'买入止损 (ATR x {atr_multiplier})', linestyle='--', color='red')  # 绘制买入止损       plt.plot(data['Sell_Stop_Loss'], label=f'卖出止损 (ATR x {atr_multiplier})', linestyle='--', color='green')  # 绘制卖出止损          # 添加最后一个值的注释       last_close = data['Close'].iloc[-1]       last_buy_sl = data['Buy_Stop_Loss'].iloc[-1]       last_sell_sl = data['Sell_Stop_Loss'].iloc[-1]       plt.text(data.index[-1], last_close, f'最后收盘价: {last_close:.2f}', color='blue', ha='right')       plt.text(data.index[-1], last_buy_sl, f'买入止损: {last_buy_sl:.2f}', color='red', ha='right')       plt.text(data.index[-1], last_sell_sl, f'卖出止损: {last_sell_sl:.2f}', color='green', ha='right')          plt.title(f'{symbol} 的ATR边界')       plt.xlabel('日期')       plt.ylabel('价格')       plt.legend()       plt.show()      def save_to_csv(data, filename):       logging.info(f"保存数据到 {filename}")       data.to_csv(filename)      def main(config):       symbol = config['symbol']       start_date = config['start_date']       end_date = config['end_date']       atr_multiplier = config['atr_multiplier']       atr_window = config['atr_window']       output_csv = config['output_csv']          data = fetch_data(symbol, start_date, end_date)  # 获取数据          ifnot data.empty:           data = calculate_atr(data, atr_window)  # 计算ATR           data = calculate_stop_loss(data, atr_multiplier)  # 计算止损           save_to_csv(data, output_csv)  # 保存数据到CSV文件           plot_atr_boundaries(data, symbol, atr_multiplier)  # 绘制ATR边界      if __name__ == "__main__":       # 读取配置文件       config_path = 'config.json'       if os.path.exists(config_path):           with open(config_path, 'r') as f:               config = json.load(f)       else:           # 默认配置           config = {               "symbol": "510050",               "start_date": "2022-01-01",               "end_date": "2025-01-01",               "atr_multiplier": 2,               "atr_window": 50,               "output_csv": "output.csv"           }           with open(config_path, 'w') as f:               json.dump(config, f, indent=4)          main(config)   `

在上篇代码代码基础上，使用ATR乘数来动态设置止损点。  
例如，如果ATR计算后是1.50元，乘数是2，那么止损点距离收盘价上下各3元。  
在高波动性事件期间，乘数会更高，以避免快速止损。乘数的选择取决于我们投资时的风险承受能力。

通过这种方式，投资者可以根据市场的波动性动态调整止损点，从而更好地管理交易风险。