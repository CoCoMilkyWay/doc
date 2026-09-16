# 五类最为强悍的时序特征

无言 量化前沿速递 2024-08-05 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488066&idx=1&sn=9d68cae661823f4396c0586337ec9b29&chksm=c3c37d08d06dc08839a1a5d959f04a25502a4320dc55ba4ddeac610c7c9869414887da4cfff0#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488066&idx=1&sn=9d68cae661823f4396c0586337ec9b29&chksm=c3c37d08d06dc08839a1a5d959f04a25502a4320dc55ba4ddeac610c7c9869414887da4cfff0#rd)

#   

**五类最为强悍的时序特征**

## 

简介

![](assets/001.png)

时间序列数据对各行业至关重要，而特征工程在时间问题建模时发挥着关键作用。本文我们介绍构建特征时非常强悍的五大特征，这些特征基本是时序建模竞赛中的必备项。

## 

五类强悍时序特征

![](assets/001.png)

### 1.Date and Time Features and Domain-Specific Features

这类特征一般可以用于捕捉周期性的信息，以及一些突发的情况，例如节假日等信息。典型的特征如下：

```
def extract_date_features(data):        data['Year']             = data.index.year    data['Month']            = data.index.month    data['Day']              = data.index.day    data['Weekday']          = data.index.weekday    data['Day_of_year']      = data.index.dayofyear    data['Week_of_year']     = data.index.isocalendar().week    data['Quarter']          = data.index.quarter    data['Is_month_start']   = data.index.is_month_start    data['Is_month_end']     = data.index.is_month_end    data['Is_quarter_start'] = data.index.is_quarter_start    data['Is_quarter_end']   = data.index.is_quarter_end    data['Is_year_start']    = data.index.is_year_start    data['Is_year_end']      = data.index.is_year_end    data['Days_in_month']    = data.index.days_in_month    data['Is_leap_year']     = data.index.is_leap_year    data['Elapsed_days']     = (data.index - data.index.min()).days    data['Weekday_name']     = data.index.day_name()    data['Month_name']       = data.index.month_name()    data['Is_weekend']       = data['Weekday'].apply(lambda x: x >= 5)    data['Is_weekday']       = ~data['Is_weekend']    data['Days_till_month_end']    = data['Days_in_month'] - data['Day']    data['Days_since_month_start'] = data['Day'] - 1    data['Week_of_month']          = (data['Day'] - 1) // 7 + 1    data['Weekday_of_month']       = (data['Day'] - 1) % 7 + 1    data['Days_to_next_holiday']   = data.index.to_series().apply(lambda x: (x + pd.DateOffset(days=1)).to_period('D').start_time)    data['Days_since_last_holiday']= data.index.to_series().apply(lambda x: (x - pd.DateOffset(days=1)).to_period('D').end_time)    data['Business_days_in_month'] = data.index.to_series().apply(lambda x: np.busday_count(x.replace(day=1), x.replace(day=x.days_in_month) + pd.DateOffset(days=1)))    data['Business_day_of_month']  = data.index.to_series().apply(lambda x: np.busday_count(x.replace(day=1), x))    data['Days_since_first_day_of_year'] = data['Day_of_year'] - 1    data['Days_remaining_in_year'] = (data.index + pd.offsets.YearEnd(0)).dayofyear - data['Day_of_year']        return data
```

### 2.滚动聚合特征

滚动窗口和扩展窗口统计涉及在移动或逐渐变大的固定大小窗口上计算摘要统计数据，如平均值、中位数、标准偏差以及最大或最小值。

这些特征有助于捕捉时间序列数据中的局部趋势、波动以及整体行为，使模型能够从时间动态中学习。在处理嘈杂数据或时间序列呈现非平稳性时，滚动窗口统计尤其有用。

```
# Apply a rolling windowwindow_size = 3time_series['Rolling_Mean']   = time_series['Data'].rolling(window=window_size).mean()time_series['Rolling_Std']    = time_series['Data'].rolling(window=window_size).std()# Apply an expanding windowtime_series['Expanding_Mean'] = time_series['Data'].expanding().mean()time_series['Expanding_Std']  = time_series['Data'].expanding().std()
```

### 3.指数平滑

指数平滑给过去的观察分配指数递减的权重，更加强调最近的观察。这种方法对于减少噪音并捕捉时间序列数据中的趋势是有用的。

指数平滑有各种形式，例如：

-   简单指数平滑；
    
-   双重指数平滑（霍尔特方法）；
    
-   三重指数平滑（霍尔特-温特斯方法） 。
    

```
def exponential_smoothing(data, alpha):    es = [data[0]]    for t in range(1, len(data)):        es.append(alpha * data[t] + (1 - alpha) * es[t - 1])        return es
```

### 4.Lag特征

Lag特征是指时间序列中先前时间步的值。它们可以帮助捕捉数据中存在的自相关性，即当前值与其过去值之间的关系。

```
import pandas as pddef create_lag_features(data, n_lags):    data_frame = pd.DataFrame(data, columns=['value'])    for i in range(1, n_lags+1):        data_frame[f'lag_{i}'] = data_frame['value'].shift(i)    return data_frame 
```

### 5.季节性分解特征

季节性分解将时间序列分离为

-   趋势；
    
-   季节；
    
-   残差
    

最常见的季节分解方法是使用STL方法。

```
import statsmodels.api as smimport matplotlib.pyplot as pltdata     = np.array([...])# Input time series dataseasonal_period = 12result   = sm.tsa.seasonal_decompose(data, period=seasonal_period)trend    = result.trendseasonal = result.seasonalresidual = result.resid 
```

#   

参考文献

![](assets/001.png)

1.  https://hackernoon.com/must-know-base-tips-for-feature-engineering-with-time-series-data