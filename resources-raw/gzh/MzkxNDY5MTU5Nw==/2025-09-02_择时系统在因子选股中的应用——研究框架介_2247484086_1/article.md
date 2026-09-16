# 择时系统在因子选股中的应用——研究框架介绍

灵犀 随率而动的因子工厂 2025-09-02 11:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484086&idx=1&sn=984ab441e33b7aaceeea11fd294d9040&chksm=c0c66ca04c4ebc66ef0398ac1f2d31c54753b032dbc5b834cde95006e138ef91334890e57663#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484086&idx=1&sn=984ab441e33b7aaceeea11fd294d9040&chksm=c0c66ca04c4ebc66ef0398ac1f2d31c54753b032dbc5b834cde95006e138ef91334890e57663#rd)

## 综述

之前我们的大部分内容都是关于因子选股，其大部分收益是来自于股票的截面比较，我们称之为截面收益。其实，交易中的收益还有其他部分，择时收益就是其中很关键的一部分。

什么是择时收益呢？通俗的讲就是寻找时机进入市场、其他时间空仓。这就是择时，比如说2024.01小市值策略在那段时间点上无论什么策略就是下跌，而且是暴跌，如果有择时器作为策略仓位开关，那么就能起到控制回撤的作用。再比如，2024.09月底，如果有择时器，那么就能准确地加仓，从而达到提高利润的作用。

我们目前的系统中，择时是独立于"因子选股"的系统，主要作用于独立的仓位控制系统。主要的逻辑是，我们对大盘、行业做一些择时指标的计算，如果我的择时系统判断最近趋势向上、超卖、突破关键压力位等等，程序会自动增加本期的因子选股仓位。相反，如果判断大盘风格转变、超买、动能减弱等等，我们就会减少仓位。

也就是上周五，择时系统判断最急小盘的风险比较高，我们已经将小盘策略仓位从5成减少到2成。就算出现一些风险，我们觉得完全在承受范围之内。

这就是目前我们的择时指标的用处，作为做了6-7年期货择时量化的资深老玩家，我认为对单个品种的择时空间很小，很多策略都是优化的结果，时间长了你就会发现，这些指标、形态很多都是参数敏感。时序上的优化本质上其实还是用到了未来信息，除非你做了大量的滚动优化与滚动样本外测试。6、7奋斗我没有找到我认为比较满意的择时交易系统。关于这些问题有兴趣可以加地球：“lvdquant”：一起探讨。

  

接下来本文将介绍一个择时指标的研究框架：

* * *

## 一、核心框架与关键观点

报告旨在验证技术指标在指数择时中的有效性，强调行为金融学为技术分析提供理论支撑。核心框架包括：

-   **理论基础**：技术分析基于三大前提——市场行为包容一切、价格以趋势方式演变、历史会重演。行为金融学挑战了有效市场假说（EMH），认为投资者非理性行为（如羊群效应、过度反应）导致技术分析可获取超额收益。报告引用汪天都(2014)的总结，技术分析有效的三个原因：
    

1.  **信息发现**：技术分析帮助预测未公开信息。
    
2.  **趋势追随**：噪声交易者推动价格偏离，技术指标捕捉趋势。
    
3.  **羊群效应**：同质交易行为自我实现价格预期。
    

-   **研究范围**：覆盖沪深300、中证500、中证1000、国证2000和创业板指，时间周期为2010年1月4日至2023年8月31日。
    
-   **关键结论**：
    

-   **整体有效性**：绝大部分技术指标在长期回测中能获取正超额收益（年化超额收益平均2-10%），小盘指数（如国证2000）表现优于大盘（沪深300）。
    
-   **参数敏感性**：参数选择需避免“过拟合”，优先选择“参数高原”（表现稳健的宽参数范围），而非“参数孤岛”（表现跳跃的窄范围）。
    
-   **市场适应性**：不同指标在牛熊市中表现分化——趋势类指标（如AROON）在牛市捕获力强，波动类指标（如UDVD）在震荡市超额收益高，但少有指标能兼顾所有市场状态。
    

* * *

## 二、技术指标分类与信号规则详解

报告将32个指标分为四大类（趋势类、动量类、波动类、成交量类），每类从不同维度刻画价量关系。以下是关键指标的定义及买卖信号规则（基于附录5.2的数学公式）：

#### 1\. 趋势类指标（8个）：捕捉价格方向，适合趋势市。

-   **代表指标**：SMA（简单移动平均）、MACD（指数平滑异同平均线）、AROON（阿隆指标）。
    
-   **信号规则**：
    

-   **金叉死叉**：短期均线上穿长期均线买入，下穿卖出（如SMA）。
    
-   **示例**：MACD当DIFF上穿DEA时买入（金叉），下穿时卖出（死叉）。
    

-   **公式简述**：
    

-   SMA：`SMA = MA(CLOSE, N)`，其中MA为移动平均。
    
-   MACD：`DIFF = EMA(CLOSE, N1) - EMA(CLOSE, N2)`, `DEA = EMA(DIFF, N3)`，买卖信号基于DIFF与DEA交叉。
    

#### 2\. 动量类指标（11个）：衡量趋势变动速率，领先反转信号。

-   **代表指标**：RSI（相对强弱指数）、KDJ（随机指标）、POS（位置指标）。
    
-   **信号规则**：
    

-   **超买超卖**：RSI < 30时买入（超卖），RSI > 70时卖出（超买）。
    

-   **公式简述**：
    

-   RSI：`RS = (N日内涨幅均值) / (N日内跌幅均值)`, `RSI = 100 - 100/(1+RS)`。
    
-   POS：`POS = (当前N日收益率 - 最小N日收益率) / (最大N日收益率 - 最小N日收益率)`，当POS > 80买入，POS < 20卖出。
    

#### 3. **波动类指标（7个）**：衡量价格波动，辅助风险控制。

-   **代表指标**：ATR（平均真实波幅）、BBANDS（布林带）、UDVD（单项波动差）。
    
-   **信号规则**：
    

-   **区间突破**：价格突破上轨买入，下破下轨卖出（如BBANDS）。
    

-   **公式简述**：
    

-   BBANDS：`中轨 = MA(CLOSE, N)`, `上轨 = 中轨 + M × STD(CLOSE, N)`, `下轨 = 中轨 - M × STD(CLOSE, N)`，M默认为2。
    
-   UDVD：`UDVD = SMA(VOLUP - VOLDOWN, N)`，当UDVD > 0买入。
    

#### 4\. 成交量类指标（6个）：引入量能，确认趋势强度。

-   **代表指标**：OBV（能量潮）、MAAMT（成交量均线）、FI（强劲指数）。
    
-   **信号规则**：
    

-   **量价配合**：OBV当量能柱 > 0买入（资金流入），< 0卖出（资金流出）。
    

-   **公式简述**：
    

-   OBV：`VOL = IF(CLOSE > REF(CLOSE,1), VOLUME, -VOLUME)`, `OBV = CUMSUM(VOL)`。
    
-   FI：`FI = EMA((CLOSE - REF(CLOSE,1)) × VOLUME, N)`，当FI > 0买入。
    

* * *

## 三、回测结果与多维评价分析

报告采用纯多头策略（手续费万分之三），评价体系包括参数稳定性、样本外有效性、信号有效性和牛熊市情景分析。

#### 1. **整体回测表现**

-   **超额收益**：大部分指标在五大指数上均获正年化超额收益（见表4-表26）。例如：
    

-   趋势类中AROON在沪深300的年化超额5.94%，动量类POS在国证2000达10.08%。
    
-   小盘指数优势：国证2000上，动量类ROC年化超额10.42%，波动类UDVD达16.65%。
    

-   **典型净值曲线**：趋势类指标在沪深300的回测净值（2010-2023年）。
    

#### 2. **参数稳定性检验**

-   **热力图展示**：以SMA为例，参数组合（短期N1、长期N2）的回测夏普比率热力图显示“高原”区域（N1=4-20, N2=60-100表现稳健）。
    
-   **样本外测试**：最优参数在样本外（2018-2023）表现下滑，如MACD样本内夏普0.70，样本外降至0.45，显示过拟合风险。
    

#### 3. **信号有效性**

-   **评估方法**：统计买卖信号后N日累计收益（N=3,5,10,20,30,60）。以沪深300为例：
    

-   买入信号后10日：SMA平均收益0.01%，胜率50%；RSI在超卖时买入后5日收益0.54%。
    
-   卖出信号表现：动量类WR卖出后30日平均收益1.33%，胜率41.44%（详见表29）。
    

#### 4. **牛熊市情景分析**

-   **评价体系**：基于市场状态（牛市、熊市、震荡市）定义三个指标：
    

-   **牛市捕获比例** = 技术指标年化收益 / 基准年化收益（越高越好）。
    
-   **熊市抗跌比例** = 1 - (技术指标年化收益 / 基准年化收益)（越高越好）。
    
-   **震荡市超额收益** = 技术指标年化收益 - 基准年化收益（正向为佳）。
    

-   **结果**：趋势类ADX在牛市捕获比例达90.04%，但熊市抗跌弱；波动类UDVD在震荡市超额收益显著（见表31-34）。
    

* * *

### 四、Python代码实现示例

提供Python代码实现四个代表指标（SMA、RSI、BBANDS、OBV），使用pandas和numpy库。代码包括指标计算、买卖信号生成及简单回测。

`import pandas as pd   import numpy as np   import yfinance as yf  # 用于获取数据      # 示例数据获取（以沪深300 ETF为例）   data = yf.download('510300.SS', start='2010-01-01', end='2023-08-31')   data = data[['Open', 'High', 'Low', 'Close', 'Volume']]      # 1. SMA指标实现（趋势类）   def sma_signal(data, short_window=10, long_window=60):       data['SMA_short'] = data['Close'].rolling(window=short_window).mean()       data['SMA_long'] = data['Close'].rolling(window=long_window).mean()       # 金叉死叉信号：1为买入，-1为卖出       data['Signal'] = 0       data.loc[data['SMA_short'] > data['SMA_long'], 'Signal'] = 1       data.loc[data['SMA_short'] < data['SMA_long'], 'Signal'] = -1       return data      # 2. RSI指标实现（动量类，N=14）   def rsi_signal(data, window=14, overbought=70, oversold=30):       delta = data['Close'].diff()       gain = delta.where(delta > 0, 0)       loss = -delta.where(delta < 0, 0)       avg_gain = gain.rolling(window=window).mean()       avg_loss = loss.rolling(window=window).mean()       rs = avg_gain / avg_loss       data['RSI'] = 100 - (100 / (1 + rs))       # 超买超卖信号       data['Signal'] = 0       data.loc[data['RSI'] < oversold, 'Signal'] = 1  # 超卖买入       data.loc[data['RSI'] > overbought, 'Signal'] = -1  # 超买卖出       return data      # 3. BBANDS指标实现（波动类，N=20, M=2）   def bbands_signal(data, window=20, num_std=2):       data['MA'] = data['Close'].rolling(window=window).mean()       data['STD'] = data['Close'].rolling(window=window).std()       data['Upper'] = data['MA'] + (num_std * data['STD'])       data['Lower'] = data['MA'] - (num_std * data['STD'])       # 区间突破信号       data['Signal'] = 0       data.loc[data['Close'] > data['Upper'], 'Signal'] = 1  # 突破上轨买入       data.loc[data['Close'] < data['Lower'], 'Signal'] = -1  # 突破下轨卖出       return data      # 4. OBV指标实现（成交量类）   def obv_signal(data):       data['OBV'] = (np.where(data['Close'] > data['Close'].shift(1), data['Volume'],                       np.where(data['Close'] < data['Close'].shift(1), -data['Volume'], 0))).cumsum()       data['OBV_MA'] = data['OBV'].rolling(window=30).mean()  # 默认参数N=30       # 量能信号：OBV上穿均线买入       data['Signal'] = 0       data.loc[data['OBV'] > data['OBV_MA'], 'Signal'] = 1       data.loc[data['OBV'] < data['OBV_MA'], 'Signal'] = -1       return data      # 应用示例   data = sma_signal(data)  # 计算SMA信号   print(data[['Close', 'SMA_short', 'SMA_long', 'Signal']].tail())      # 简单回测：假设信号持有N日   def backtest(data, n_days=5):       data['Return'] = data['Close'].pct_change()       data['Strategy_Return'] = data['Signal'].shift(1) * data['Return']  # 信号滞后一日       cumulative_return = (1 + data['Strategy_Return']).cumprod()       return cumulative_return      # 绘制净值曲线（需matplotlib）   import matplotlib.pyplot as plt   cum_ret = backtest(data)   plt.plot(cum_ret, label='SMA Strategy')   plt.plot((1 + data['Return']).cumprod(), label='Buy & Hold')   plt.title('SMA Strategy vs Buy & Hold (沪深300)')   plt.legend()   plt.show()   `

**代码说明**：

-   **数据源**：使用yfinance获取沪深300 ETF数据，覆盖回测周期。
    
-   **指标参数**：默认值（如RSI的N=14、BBANDS的M=2）。
    
-   **信号逻辑**：严格遵循规则：金叉死叉、超买超卖等。
    
-   **回测简化**：信号滞后一日执行，计算策略累计收益。
    
-   **扩展建议**：可添加手续费、参数优化（如网格搜索寻找“参数高原”）以贴合实际情况。
    

* * *

## 五、结论与启示

-   **核心启示**：技术指标在择时中有效，但需结合市场状态动态选择——牛市用趋势类（AROON）、熊市用波动类（ATR）、震荡市用量能类（OBV）。参数优化应避免过拟合，优先“高原”区域。
    
-   **局限与风险**：样本外表现下滑（如MACD样本外夏普下降）、高频交易换手率高（如MAAMT年均换手55次）可能侵蚀收益。
    
-   **实战建议**：构建多指标融合系统（如趋势+动量），辅以牛熊市过滤器。强调“技术分析是艺术”，需结合基本面。
    

本期内容提供量化择时研究系统框架，代码示例可帮助快速验证策略，本文部分参考别人文章，另外，通过本期文章，你知道如何研究一个技术指标好不好用，在技术指标判断出大盘的方向后，就可以结合因子选股情况，做相应仓位筛选即可。

当然，本文给出的仅仅是择时策略冰山一角，至于其他的还需要各位看官深入研究。