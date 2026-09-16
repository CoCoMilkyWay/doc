# 研报复现 | 行业有效量价因子与行业轮动策略

QuantML QuantML 2025-04-09 18:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489974&idx=1&sn=0dd8a10cb7239fe524f28471d8b46dfa&chksm=cfbdb93ccf10adc116a511fd974fd08db96f0f0ec718ac7f80caaa492a73821c74a2600b5e66#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489974&idx=1&sn=0dd8a10cb7239fe524f28471d8b46dfa&chksm=cfbdb93ccf10adc116a511fd974fd08db96f0f0ec718ac7f80caaa492a73821c74a2600b5e66#rd)

本文旨在复现华西证券-行业有效量价因子与行业轮动策略

## 1. **行业量价因子筛选**：

-   报告从行业层面的量价数据入手，将量价因子分为六大类：动量、交易波动、换手率、多空对比、量价背离、量幅同向。
    
-   通过单因子测试（包括因子分组测试和因子IC值分析），最终筛选出11个有效的月频行业因子。
    

## 2. **量价行业轮动组合回测表现**：

-   基于11个量价因子构建量价行业轮动组合，每月末选取中信一级行业（剔除综合和综合金融）中复合因子值最高的五个行业，行业间等权加权。
    
-   2010年至2022年7月，量价行业轮动组合的累计收益为580.00%，相对于全部行业等权组合的累计超额为484.16%。行业组合的年度胜率为100%，月胜率为64.90%。
    

## 3. **因子分类与构造方法**：

11个量价因子及其构造方法如下：

* * *

### 1. **动量因子**

#### 1.1 简单动量

-   **构造方法**：使用不同期限（如5日、10日、15日、40日、120日、180日）的价格动量，选取动量最高的前5个行业。
    
-   **公式**：
    
    动量当前价格过去价格过去价格
    

#### 1.2 二阶动量

-   **构造方法**：计算最新一期动量与过去动量的差值，并进行指数加权移动平均（EWMA）。
    
-   **公式**：
    
    二阶动量当前价格过去价格均值过去价格均值延迟动量窗口期
    

#### 1.3 动量期限差

-   **构造方法**：长期动量减去短期动量，剔除近期拥挤的行业。
    
-   **公式**：
    
    动量期限差当前价格长期过去价格长期过去价格当前价格短期过去价格短期过去价格
    

* * *

### 2. **交易波动因子**

#### 2.1 成交金额波动

-   **构造方法**：计算过去一段时间成交金额的标准差，取相反数。
    
-   **公式**：
    
    成交金额波动成交金额
    

#### 2.2 成交量波动

-   **构造方法**：计算过去一段时间成交量的标准差，取相反数。
    
-   **公式**：
    
    成交量波动成交量
    

* * *

### 3. **换手率因子**

#### 3.1 换手率变化

-   **构造方法**：长期换手率均值除以短期换手率均值，反映换手率的变化。
    
-   **公式**：
    
    换手率变化长期换手率均值短期换手率均值
    

* * *

### 4. **多空对比因子**

#### 4.1 多空对比总量

-   **构造方法**：计算过去一段时间内每日多头力量与空头力量的比值，并求和，取相反数。
    
-   **公式**：
    
    多空对比总量收盘价最低价最高价收盘价
    

#### 4.2 多空对比变化

-   **构造方法**：计算长期与短期多空力量对比的指数加权平均值之差。
    
-   **公式**：
    
    多空对比变化多空力量对比长期窗口多空力量对比短期窗口
    

* * *

### 5. **量价背离因子**

#### 5.1 量价排序协方差

-   **构造方法**：计算收盘价与成交量排序的协方差的相反数。
    
-   **公式**：
    
    量价排序协方差收盘价成交量窗口期
    

#### 5.2 量价相关系数

-   **构造方法**：计算成交量与收盘价相关系数的相反数。
    
-   **公式**：
    
    量价相关系数收盘价成交量窗口期
    

#### 5.3 一阶量价背离

-   **构造方法**：计算成交量与价格一阶变化的背离程度。
    
-   **公式**：
    
    一阶量价背离成交量成交量收盘价开盘价窗口期
    

* * *

### 6. **量幅同向因子**

#### 6.1 量幅同向

-   **构造方法**：计算成交量变化幅度与价格变化幅度的同向变化。
    
-   **公式**：
    
    量幅同向成交量成交量最高价最低价窗口期
    

* * *

这11个因子涵盖了动量、交易波动、换手率、多空对比、量价背离和量幅同向六大类，通过单因子测试和因子IC值分析，筛选出逻辑性强且有效的月频行业因子，最终构建了量价行业轮动策略。

## 4\. 代码实现

部分因子计算代码如下：

`class IndustryVolumePriceFactors:       """       实现华西证券报告中的"行业有效量价因子与行业轮动策略"模型              该类包含了六大类量价因子的计算方法：       1. 动量因子       2. 交易波动因子       3. 换手率因子       4. 多空对比因子       5. 量价背离因子       6. 量幅同向因子              并基于这些因子构建行业轮动策略       """              def __init__(self, price_data):           """           初始化行业量价因子计算器                      参数:           price_data (pd.DataFrame): 行业价格数据，包含以下列:               - close: 收盘价               - open: 开盘价               - high: 最高价               - low: 最低价               - volume: 成交量               - amount: 成交金额               - turnover_rate: 换手率(可选)           """           self.price = price_data           # self.price.index = pd.to_datetime(self.price.index)                      # 确保数据为多索引格式，第一层是行业，第二层是时间           if not isinstance(self.price.index, pd.MultiIndex):               raise ValueError("数据必须为MultiIndex格式，第一层为行业代码，第二层为日期")                      # 分解数据           self.close_df = self.price['close']           self.open_df = self.price['open']           self.high_df = self.price['high']           self.low_df = self.price['low']           self.volume_df = self.price['volume']           self.amount_df = self.price['amount']                      # 检查是否有换手率数据           if'turnover_rate'in self.price.columns:               self.turnover_df = self.price['turnover_rate']               self.has_turnover = True           else:               self.has_turnover = False              # ====== 动量因子 ======       def second_order_momentum(self, window1=20, window2=5, window=10):           """           计算二阶动量因子                      Factor = EWMA((Close_t - mean(Close_t-window1:t))/mean(Close_t-window1:t) -                    delay((Close_t - mean(Close_t-window1:t))/mean(Close_t-window1:t), window2), window)                      参数:           window1 (int): 价格均值的窗口期           window2 (int): 延迟窗口期           window (int): EWMA的窗口期                      返回:           pd.DataFrame: 二阶动量因子值           """           # 计算 (Close_t - mean(Close_t-window1:t))/mean(Close_t-window1:t)           step_a = (self.close_df - self.close_df.groupby(level=0).rolling(window1).mean().droplevel(0)).div(               self.close_df.groupby(level=0).rolling(window1).mean().droplevel(0))                      # 计算 delay((Close_t - mean(Close_t-window1:t))/mean(Close_t-window1:t), window2)           step_b = step_a.groupby(level=0).shift(window2)                      # 计算差值           step_c = step_a - step_b                      # 对差值进行EWMA           result = step_c.groupby(level=0).apply(lambda x: pd.Series(EMA(x.values, window), index=x.index))                      return result              def momentum_term_spread(self, window1=60, window2=20):           """           计算动量期限差因子                      Factor = (Close_t - Close_t-window1)/Close_t-window1 - (Close_t - Close_t-window2)/Close_t-window2                      window1 > window2                      参数:           window1 (int): 长期动量窗口期           window2 (int): 短期动量窗口期                      返回:           pd.DataFrame: 动量期限差因子值           """           if window1 <= window2:               raise ValueError(f"动量期限差: window1({window1})必须大于window2({window2})")                      # 计算长期动量           long_term_momentum = (self.close_df - self.close_df.groupby(level=0).shift(window1)).div(               self.close_df.groupby(level=0).shift(window1))                      # 计算短期动量           short_term_momentum = (self.close_df - self.close_df.groupby(level=0).shift(window2)).div(               self.close_df.groupby(level=0).shift(window2))                      # 长期动量减去短期动量           return long_term_momentum - short_term_momentum   `

## 5\. 回测结果

最终的回测结果：

![](assets/001.png)

  

  

  

代码及数据下载见星球

  

QuantML星球内有各类丰富的量化资源，包括上百篇论文代码，QuantML-Qlib框架，研报复现项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，顶会论文作者，github千星项目作者等，星球人数已经800+，欢迎加入交流

  

  

![](assets/002.png)