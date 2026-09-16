# 择时因子的择时框架——预处理、检验、合成、代码

蝴蝶量化 随率而动的因子工厂 2026-01-09 18:06 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484384&idx=1&sn=4dc172b6ef183e364a2e75494601e647&chksm=c0a2cc6639c270c6aa8a29b807355f20b8f12547c7ac26aa3d77e892bcfb807cda87b234e05b#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484384&idx=1&sn=4dc172b6ef183e364a2e75494601e647&chksm=c0a2cc6639c270c6aa8a29b807355f20b8f12547c7ac26aa3d77e892bcfb807cda87b234e05b#rd)

## 技术背景

之前文章的大部分内容都是关于截面因子的处理方式，由于最近在做择时方面的研究，突然发现，之前对于择时因子的介绍不够全面。本期文章我们将针对**择时因子**的处理方法做一个详细的介绍。

**择时因子**适用情况，顾名思义它的主要用途一般是在单个标的上的择时场景。通过对比时序上的因子相对大小、因子收益等等，判断标的买入时机。

**常见类型：** 截面因子跟择时因子很多情况下是同样一个因子在不同场景下的应用，常见的截面因子都可以是择时因子。比如：pe、pb、eps、技术指标等等，都是既可以作为截面因子也可以作为择时因子。

**有效性检验：** 一般来讲，截面因子的检验方法：IC检验、分组测试、因子收益计算、显著性检验等等。显然，择时因子上述方法不一定适用。

**本文的主要内容：择时因子的有效性检验方法与因子合成方法简介。**

## 知识介绍

### 基本框架

#### **因子数据计算：**

宏观因子、财务指标、估值指标、技术指标、相关性、bate等因子的计算。与直接介绍的大致相同。

对于一些因子需要做一些特殊的处理，大致可以分为下面的几种：

1.  **杜绝未来函数**：
    

-   因子值在时间 t 必须仅使用**t及之前**的信息。
    
-   对于日频数据：使用 `t` 日收盘价计算的因子，只能预测 `t+1` 日及之后的收益。
    
-   **公式**：`Future_Return(t->t+H) = f(Factor(t))`，其中 `H` 为预测期。
    

3.  **处理发布滞后（对宏观、基本面因子）**：
    

-   例如，CPI数据在每月9号公布，反映的是上个月的情况。在检验时，因子值应放置在**实际公布日**（9号），而非其反映的月份。
    
-   **操作**：对所有宏观数据建立**公布日期日历**，确保因子值只在市场可知后才被使用。
    

#### **因子预处理：**

-   **去异常值：** Z-score方法
    
-   **去极致化：** MAD，z-score等方法
    
-   **标准化:** 这里是在时序上某个固定的窗口期的z-score标准化。
    
-   **正交化：** 方法跟之前也是类似，但是不是截面回归而是时序上的**滚动窗口正交化**，以当前时间点的正交化残差作为当前因子值。大致有下面几种方式：
    

> -   时序上的逐步正交化（schmidt\_orthogonalize）。优点：方法简单。缺点：不稳定，回归的顺序影响最终的回归结果。
>     
> -   主成分正交化（PCA）：剔除主成分作为正交化因子，适合因子数量较多的情况
>     
> -   滚动的对称正交化方法（推荐）：可以查看之前的文章，这样就不存在顺序问题。
>     

#### **因子检验：**

这是本文的主要内容，我们将在下一节着重介绍

#### **因子择时、合成：**

这里不是截面比较大小，是时序上的比较。当然这里的择时算法跟之前的检验算法是配套的。也就是检验方法以因子择时合成为基础。在下一节介绍。

### 截面、择时因子的区别

维度

**截面因子**

**择时因子**

**预测目标**

横截面上，哪些股票未来**相对收益**更高/低。

未来一段时间，市场或资产**绝对收益**是涨是跌、波动大小。

**数据结构**

面板数据。每个截面期，因子是N个股票的向量。

时间序列数据。每个时点，因子是1个标量值。

**检验核心**

**截面排序能力**

（Rank IC）和**分组单调性**。

**时序预测能力**

：方向准确性、预测收益分布、信号触发后的市场表现。

**输出**

股票组合（多空组合、多头组合）。

买卖信号或仓位权重）。

## 有效性检验与因子合成

我们知道截面因子的最终追求的目标是截面上的股票因子排名。因子的合成方法一般是：因子择时（加权）、机器学习。

择时因子追求的是单只股票时序上的开、平仓信号。这个信号的确定就有很多不同的方法：技术指标类的突破阈值、预测未来收益、因子的时序相对变化等等。

一般来讲，截面因子的检验方法：IC检验、分组测试、因子收益计算、显著性检验等等。显然，择时因子上述方法不一定适用。大部分检验方法遵循下面的框架：

`flowchart TD       A[时序择时因子检验] --> B[第一步：预处理<br>（杜绝未来函数）]       B --> C{第二步：核心检验}          C --> D[信号检验法]       C --> E[相关性检验法]       C --> F[回归模型法]          D --> D1[生成买卖信号]       D1 --> D2[统计胜率、盈亏比]       D2 --> D3[计算多空收益]          E --> E1[计算因子与未来收益<br>的时序相关系数]       E1 --> E2[分析IC序列<br>（均值、IR、稳定性）]          F --> F1[构建时序回归模型<br>R_t+1 = α + β*F_t]       F1 --> F2[检验系数显著性<br>与模型解释力]          D3 & E2 & F2 --> G{第三步：稳健性评估<br>（关键步骤）}          G --> H[样本内外分析]       G --> I[参数敏感性分析]       G --> J[市态区分检验]          H & I & J --> K[第四步：综合决策]       K --> L[因子逻辑坚实]       K --> M[统计显著稳健]       K --> N[样本外有效]          L & M & N --> O[通过检验]   `

### **1、信号检验法**

**思路**：将连续的因子值转化为离散的买卖信号，检验信号发出后市场的实际表现。这里因子必须要经过Z-Score标准化后的数值。![](assets/001.png)**步骤**：

1.  **设定信号规则**：
    

-   **阈值法**：当因子值 > 上阈值时，发出**看多信号**；当因子值 < 下阈值时，发出**看空信号**；中间值不管。
    
-   **均线法**：当因子上穿其N日均线时看多，下穿时看空。
    
-   **极值法**：当因子处于历史分位数（如10%以下）时看多，90%以上时看空，**这里的阈值一定不能有未来信息，只能基于之前的信息，其实做了z-score之后，效果跟阈值法一样**。
    

3.  **计算信号后收益**：
    

-   对每一个信号发出点 ，计算从  日开始未来  个交易日）的标的基准收益率。
    
-   计算累计收益率： 。
    

5.  **关键绩效统计**：
    

-   **胜率**：信号方向正确的次数 / 总信号次数。正确定义为：看多信号后市场上涨，看空信号后市场下跌。
    
-   **平均收益率**：所有看多信号后收益率的均值（应>0），所有看空信号后收益率的均值（应<0）。
    
-   **盈亏比**：正确信号的平均盈利/错误信号的平均亏损。
    
-   **多空收益差**：平均看多收益 - 平均看空收益。该差值应显著为正。**可以通过t检验，多、空收益差是否显著。**利用均值T检验的方法判断某个择时因子上升和下跌情况下的收益是否存在显著的差别：
    

            其中：

-    与  分别为上升和下跌情况下标的未来收益均值；    
    
-    与 分别为上升和下跌情况下**标的未来收益**的标准差；
    
-    与  分别表示择时因子上升和下跌的月份数量。
    

-   **统计检验**：与上面的检验方法类似对看多信号后的收益率序列做T检验，看其均值是否显著>0；对看空信号后的收益率序列做T检验，看其均值是否显著<0。
    

例如下面图片中的效果：  
![](assets/002.png)

**4、多因子策略**

如果需要对多因子策略进行合成，这种检验方法，对应的策略构造方法比较合理的是：**因子打分法**，也就是如果某个因子满足多头的条件，则**总因子加1分**，满足空头条件**减1分**，其他**得0分**。

**总因子得分大于0：持有多单，总得分小于等于0：平仓、空仓**

**Python代码**：

`import pandas as pd   import numpy as np   from scipy import stats      def signal_based_test(factor, market_return, upper_thresh=1.0, lower_thresh=-1.0, hold_period=5):       """       因子信号检验       """       signals = pd.Series(0, index=factor.index)       signals[factor > upper_thresh] = 1    # 1: 看多       signals[factor < lower_thresh] = -1   # -1: 看空              future_ret = market_return.rolling(hold_period).apply(lambda x: (1+x).prod()-1, raw=True).shift(-hold_period)              results = pd.DataFrame({'signal': signals, 'future_ret': future_ret}).dropna()              long_ret = results[results['signal'] == 1]['future_ret']       short_ret = results[results['signal'] == -1]['future_ret']              # 计算指标       metrics = {           'long_win_rate': (long_ret > 0).mean(),           'short_win_rate': (short_ret < 0).mean(),           'long_mean_ret': long_ret.mean(),           'short_mean_ret': short_ret.mean(),           'long_short_spread': long_ret.mean() - short_ret.mean(),           'num_signals': len(results)       }       # T检验       _, long_p = stats.ttest_1samp(long_ret, 0)       _, short_p = stats.ttest_1samp(short_ret, 0)       metrics['long_p_value'] = long_p/2 if long_ret.mean()>0 else 1-long_p/2 # 单边检验       metrics['short_p_value'] = short_p/2 if short_ret.mean()<0 else 1-short_p/2              return pd.Series(metrics), long_ret, short_ret   `

### **2、相关性（IC）分析法**

**思路**：与截面因子一样，直接计算因子值与未来一段时间市场收益率的**时序相关性**。

**步骤**：

1.  **计算时序IC序列**：
    

-   对于每一个时点 ，计算因子值与未来N期市场收益率的相关系数。
    
-   使用 **Spearman秩相关**（Rank IC），因为它对异常值不敏感，更关注单调关系。
    
-   公式： 
    

3.  **分析IC统计量**：
    

-   **IC均值**：反映因子的平均预测方向。对于择时因子，绝对值通常大于0.05被认为有较强预测力。
    
-   **IC标准差**：衡量预测能力的稳定性。
    
-   **信息比率**：均值标准差。择时因子ICIR > 0.5 表现良好，>1 表现优秀。
    
-   **IC胜率**：IC > 0 的月份占比。> 60% 通常认为有稳定的正向预测能力。
    
-   **累计IC收益曲线**：计算每一期IC的累计收益曲线。
    
-   **IC衰减分析**：计算不同预测周期（H=1， 5， 10， 20日）的IC均值，观察预测能力的持续时间。
    

3、**合成方法：**这种检验方法一般对应的因子择时（加权合成）、机器学习等等。

**Python代码**：

`def calculate_ts_ic(factor, market_return, horizons=[1, 5, 22]):       """       计算不同预测周期的时序IC序列       """       ic_results = {}       for h in horizons:           # 计算未来h日累计收益           future_ret = market_return.rolling(h).apply(lambda x: (1+x).prod()-1, raw=True).shift(-h)           # 对齐数据           aligned_data = pd.concat([factor, future_ret], axis=1).dropna()           # 计算Spearman相关系数           ic = aligned_data.iloc[:, 0].corr(aligned_data.iloc[:, 1], method='spearman')           ic_series = aligned_data.iloc[:, 0].rolling(60).corr(aligned_data.iloc[:, 1]) # 滚动IC           ic_results[f'IC_{h}D'] = {'IC均值': ic, 'IC序列': ic_series}              ic_summary = pd.DataFrame({           k: [v['IC均值']] for k, v in ic_results.items()       }).T       ic_summary.columns = ['IC均值']       ic_summary['ICIR'] = [ic_results[k]['IC序列'].mean()/ic_results[k]['IC序列'].std() for k in ic_results.keys()]              return ic_summary, ic_results   `

### **3、回归模型法**

**思路**：通过回归模型量化因子对未来收益的解释能力，并检验其统计显著性。类似于计算因子收益。

**模型**：αβε

**步骤**：

1.  用OLS（普通最小二乘法）或WLS（加权最小二乘法）估计模型。
    
2.  **核心检验**：
    

-   系数 β 的 **t统计量** 和 **p值**：β 应显著不为零（p值通常<0.05）。
    
-   模型的 \*\*调整²\*\*：表示因子能解释的未来收益波动的比例。对于日频数据，即使0.5%也很可贵。
    

4.  **注意点**：
    

-   金融时间序列常有异方差和自相关，建议使用 **Newey-West调整** 的标准误来计算稳健的t统计量。
    

6.  **代码解析**：     库的  可实现。
    
7.  **合成方法：** 这种检验方法用的比较少，对应的合成方案你有什么好的想法，可以留言。
    

**Python代码**：

`import statsmodels.api as sm      def regression_test(factor, market_return, horizon=5):       """       时序回归检验       """       # 准备因变量：未来horizon日累计收益       Y = market_return.rolling(horizon).apply(lambda x: (1+x).prod()-1, raw=True).shift(-horizon)       # 准备自变量：当期因子值       X = factor       # 对齐数据       data = pd.concat([Y, X], axis=1).dropna()       Y = data.iloc[:, 0]       X = sm.add_constant(data.iloc[:, 1])  # 添加常数项              # 使用Newey-West调整标准误的OLS回归       model = sm.OLS(Y, X).fit(cov_type='HAC', cov_kwds={'maxlags': int(horizon*1.5)})              # 输出关键结果       results = {           'beta': model.params[1],           'beta_t': model.tvalues[1],           'beta_p': model.pvalues[1],           'alpha': model.params[0],           'alpha_p': model.pvalues[0],           'rsquared_adj': model.rsquared_adj,           'f_pvalue': model.f_pvalue       }       return pd.Series(results), model   `

### **收益率分布（分组分层）**

-   **思路**：观察在不同因子值区间（分位数）内，未来市场收益的分布特征，可以计算相应未来收益曲线等等。
    
-   **步骤**：
    

1.  将所有历史时期的因子值分成若干组（如5组）。
    
2.  统计每组对应的**未来市场收益率的分布**（均值、标准差、偏度、峰度、正收益比例）。
    
3.  **有效性标志**：单调性。
    

## 总结

本文文章我们介绍了择时因子的一整套框架，包括了：择时因子定义、择时因子的预处理、重点是因子的有效性检验、略带合成方法等等，

本期文章补全了，我们之前在择时因子上的空白，暂时没有做实证案例，我们打算在以后做实证，同样代码在星球中分享。