# 因子构建中的算子：Qlib中的算子

fintechhaibin FinTechHi 2025-09-05 22:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247487550&idx=1&sn=07a6c3629369e0d50c3518ae9090f0ce&chksm=fb2737cf60a6a088b7b61a95b09ad08808b92795ffdf0fb89efd975400be31f9f857582e03f7#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487550&idx=1&sn=07a6c3629369e0d50c3518ae9090f0ce&chksm=fb2737cf60a6a088b7b61a95b09ad08808b92795ffdf0fb89efd975400be31f9f857582e03f7#rd)

Qlib就不多介绍了。这篇整理了下Qlib中的算子。

  

![](assets/001.jpg)

  

![](assets/002.png)

  

### 一、元素级算子 (Element-Wise Operator)

#### 1. `ElemOperator`

-   **名称**：元素级算子基类
    
-   **功能**：所有元素级算子的抽象基类
    
-   **代码**：
    

`class ElemOperator(ExpressionOps):       """元素级算子的基类"""       def __init__(self, feature):           self.feature = feature              def get_longest_back_rolling(self):           return self.feature.get_longest_back_rolling()              def get_extended_window_size(self):           return self.feature.get_extended_window_size()   `

#### 2. `ChangeInstrument`

-   **名称**：切换标的算子
    
-   **功能**：在计算时切换到另一个标的，例如计算股票相对于大盘指数的beta
    
-   **代码**：
    

`class ChangeInstrument(ElemOperator):       """切换计算的标的"""       def __init__(self, instrument, feature):           self.instrument = instrument           self.feature = feature              def load(self, instrument, start_index, end_index, *args):           # 忽略传入的instrument，使用初始化时指定的instrument           return super().load(self.instrument, start_index, end_index, *args)   `

#### 3. `Abs`

-   **名称**：绝对值算子
    
-   **功能**：计算特征的绝对值
    
-   **代码**：
    

`class Abs(NpElemOperator):       """计算特征的绝对值"""       def __init__(self, feature):           super(Abs, self).__init__(feature, "abs")   `

#### 4. `Sign`

-   **名称**：符号算子
    
-   **功能**：计算特征的符号
    
-   **代码**：
    

`class Sign(NpElemOperator):       """计算特征的符号"""       def __init__(self, feature):           super(Sign, self).__init__(feature, "sign")              def _load_internal(self, instrument, start_index, end_index, *args):           # 将数据转换为float32以避免布尔类型输入引发的错误           series = self.feature.load(instrument, start_index, end_index, *args)           series = series.astype(np.float32)           return getattr(np, self.func)(series)   `

#### 5. `Log`

-   **名称**：对数算子
    
-   **功能**：计算特征的对数
    
-   **代码**：
    

`class Log(NpElemOperator):       """计算特征的对数"""       def __init__(self, feature):           super(Log, self).__init__(feature, "log")   `

#### 6. `Mask`

-   **名称**：掩码算子
    
-   **功能**：使用指定的标的作为掩码
    
-   **代码**：
    

`class Mask(NpElemOperator):       """使用指定的标的作为掩码"""       def __init__(self, feature, instrument):           super(Mask, self).__init__(feature, "mask")           self.instrument = instrument              def _load_internal(self, instrument, start_index, end_index, *args):           return self.feature.load(self.instrument, start_index, end_index, *args)   `

#### 7. `Not`

-   **名称**：非运算算子
    
-   **功能**：对特征进行元素级的逻辑非运算
    
-   **代码**：
    

`class Not(NpElemOperator):       """对特征进行逻辑非运算"""       def __init__(self, feature):           super(Not, self).__init__(feature, "bitwise_not")   `

### 二、二元算子 (Pair-Wise Operator)

#### 8. `PairOperator`

-   **名称**：二元算子基类
    
-   **功能**：所有二元算子的抽象基类
    
-   **代码**：
    

`class PairOperator(ExpressionOps):       """二元算子的基类"""       def __init__(self, feature_left, feature_right):           self.feature_left = feature_left           self.feature_right = feature_right   `

#### 9. `Power`

-   **名称**：幂运算算子
    
-   **功能**：计算左特征的右特征次幂
    
-   **代码**：
    

`class Power(NpPairOperator):       """计算左特征的右特征次幂"""       def __init__(self, feature_left, feature_right):           super(Power, self).__init__(feature_left, feature_right, "power")   `

#### 10. `Add`

-   **名称**：加法算子
    
-   **功能**：计算两个特征的和
    
-   **代码**：
    

`class Add(NpPairOperator):       """计算两个特征的和"""       def __init__(self, feature_left, feature_right):           super(Add, self).__init__(feature_left, feature_right, "add")   `

#### 11. `Sub`

-   **名称**：减法算子
    
-   **功能**：计算两个特征的差
    
-   **代码**：
    

`class Sub(NpPairOperator):       """计算两个特征的差"""       def __init__(self, feature_left, feature_right):           super(Sub, self).__init__(feature_left, feature_right, "subtract")   `

#### 12. `Mul`

-   **名称**：乘法算子
    
-   **功能**：计算两个特征的乘积
    
-   **代码**：
    

`class Mul(NpPairOperator):       """计算两个特征的乘积"""       def __init__(self, feature_left, feature_right):           super(Mul, self).__init__(feature_left, feature_right, "multiply")   `

#### 13. `Div`

-   **名称**：除法算子
    
-   **功能**：计算两个特征的商
    
-   **代码**：
    

`class Div(NpPairOperator):       """计算两个特征的商"""       def __init__(self, feature_left, feature_right):           super(Div, self).__init__(feature_left, feature_right, "divide")   `

#### 14. `Greater`

-   **名称**：取大值算子
    
-   **功能**：对两个特征逐元素取较大值
    
-   **代码**：
    

`class Greater(NpPairOperator):       """对两个特征逐元素取较大值"""       def __init__(self, feature_left, feature_right):           super(Greater, self).__init__(feature_left, feature_right, "maximum")   `

#### 15. `Less`

-   **名称**：取小值算子
    
-   **功能**：对两个特征逐元素取较小值
    
-   **代码**：
    

`class Less(NpPairOperator):       """对两个特征逐元素取较小值"""       def __init__(self, feature_left, feature_right):           super(Less, self).__init__(feature_left, feature_right, "minimum")   `

#### 16. `Gt`

-   **名称**：大于比较算子
    
-   **功能**：比较左特征是否大于右特征，返回布尔序列
    
-   **代码**：
    

`class Gt(NpPairOperator):       """比较左特征是否大于右特征"""       def __init__(self, feature_left, feature_right):           super(Gt, self).__init__(feature_left, feature_right, "greater")   `

#### 17. `Ge`

-   **名称**：大于等于比较算子
    
-   **功能**：比较左特征是否大于等于右特征，返回布尔序列
    
-   **代码**：
    

`class Ge(NpPairOperator):       """比较左特征是否大于等于右特征"""       def __init__(self, feature_left, feature_right):           super(Ge, self).__init__(feature_left, feature_right, "greater_equal")   `

#### 18. `Lt`

-   **名称**：小于比较算子
    
-   **功能**：比较左特征是否小于右特征，返回布尔序列
    
-   **代码**：
    

`class Lt(NpPairOperator):       """比较左特征是否小于右特征"""       def __init__(self, feature_left, feature_right):           super(Lt, self).__init__(feature_left, feature_right, "less")   `

#### 19. `Le`

-   **名称**：小于等于比较算子
    
-   **功能**：比较左特征是否小于等于右特征，返回布尔序列
    
-   **代码**：
    

`class Le(NpPairOperator):       """比较左特征是否小于等于右特征"""       def __init__(self, feature_left, feature_right):           super(Le, self).__init__(feature_left, feature_right, "less_equal")   `

#### 20. `Eq`

-   **名称**：等于比较算子
    
-   **功能**：比较左特征是否等于右特征，返回布尔序列
    
-   **代码**：
    

`class Eq(NpPairOperator):       """比较左特征是否等于右特征"""       def __init__(self, feature_left, feature_right):           super(Eq, self).__init__(feature_left, feature_right, "equal")   `

#### 21. `Ne`

-   **名称**：不等于比较算子
    
-   **功能**：比较左特征是否不等于右特征，返回布尔序列
    
-   **代码**：
    

`class Ne(NpPairOperator):       """比较左特征是否不等于右特征"""       def __init__(self, feature_left, feature_right):           super(Ne, self).__init__(feature_left, feature_right, "not_equal")   `

#### 22. `And`

-   **名称**：逻辑与算子
    
-   **功能**：对两个特征逐元素进行逻辑与运算
    
-   **代码**：
    

`class And(NpPairOperator):       """对两个特征逐元素进行逻辑与运算"""       def __init__(self, feature_left, feature_right):           super(And, self).__init__(feature_left, feature_right, "bitwise_and")   `

#### 23. `Or`

-   **名称**：逻辑或算子
    
-   **功能**：对两个特征逐元素进行逻辑或运算
    
-   **代码**：
    

`class Or(NpPairOperator):       """对两个特征逐元素进行逻辑或运算"""       def __init__(self, feature_left, feature_right):           super(Or, self).__init__(feature_left, feature_right, "bitwise_or")   `

### 三、三元算子 (Triple-wise Operator)

#### 24. `If`

-   **名称**：条件选择算子
    
-   **功能**：根据条件选择两个特征中的值
    
-   **代码**：
    

`class If(ExpressionOps):       """根据条件选择两个特征中的值"""       def __init__(self, condition, feature_left, feature_right):           self.condition = condition           self.feature_left = feature_left           self.feature_right = feature_right              def _load_internal(self, instrument, start_index, end_index, *args):           series_cond = self.condition.load(instrument, start_index, end_index, *args)           # 加载左右特征           if isinstance(self.feature_left, (Expression,)):               series_left = self.feature_left.load(instrument, start_index, end_index, *args)           else:               series_left = self.feature_left           if isinstance(self.feature_right, (Expression,)):               series_right = self.feature_right.load(instrument, start_index, end_index, *args)           else:               series_right = self.feature_right           # 根据条件选择值           series = pd.Series(np.where(series_cond, series_left, series_right), index=series_cond.index)           return series   `

### 四、滚动窗口算子 (Rolling)

#### 25. `Rolling`

-   **名称**：滚动窗口算子基类
    
-   **功能**：所有滚动窗口算子的抽象基类
    
-   **代码**：
    

`class Rolling(ExpressionOps):       """滚动窗口算子的基类"""       def __init__(self, feature, N, func):           self.feature = feature           self.N = N  # 窗口大小           self.func = func  # 应用的函数              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           # N=0时使用expanding窗口           if isinstance(self.N, int) and self.N == 0:               series = getattr(series.expanding(min_periods=1), self.func)()           # 0<N<1时使用指数加权移动平均           elif isinstance(self.N, float) and0 < self.N < 1:               series = series.ewm(alpha=self.N, min_periods=1).mean()           # 否则使用普通滚动窗口           else:               series = getattr(series.rolling(self.N, min_periods=1), self.func)()           return series   `

#### 26. `Ref`

-   **名称**：引用算子
    
-   **功能**：引用特征的历史或未来值
    
-   **代码**：
    

`class Ref(Rolling):       """引用特征的历史或未来值"""       def __init__(self, feature, N):           super(Ref, self).__init__(feature, N, "ref")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           # N=0返回第一天的值           if series.empty:               return series           elif self.N == 0:               series = pd.Series(series.iloc[0], index=series.index)           else:               # 使用shift移动数据               series = series.shift(self.N)           return series   `

#### 27. `Mean`

-   **名称**：移动平均算子
    
-   **功能**：计算特征的滚动平均值
    
-   **代码**：
    

`class Mean(Rolling):       """计算特征的滚动平均值"""       def __init__(self, feature, N):           super(Mean, self).__init__(feature, N, "mean")   `

#### 28. `Sum`

-   **名称**：滚动求和算子
    
-   **功能**：计算特征的滚动总和
    
-   **代码**：
    

`class Sum(Rolling):       """计算特征的滚动总和"""       def __init__(self, feature, N):           super(Sum, self).__init__(feature, N, "sum")   `

#### 29. `Std`

-   **名称**：滚动标准差算子
    
-   **功能**：计算特征的滚动标准差
    
-   **代码**：
    

`class Std(Rolling):       """计算特征的滚动标准差"""       def __init__(self, feature, N):           super(Std, self).__init__(feature, N, "std")   `

#### 30. `Var`

-   **名称**：滚动方差算子
    
-   **功能**：计算特征的滚动方差
    
-   **代码**：
    

`class Var(Rolling):       """计算特征的滚动方差"""       def __init__(self, feature, N):           super(Var, self).__init__(feature, N, "var")   `

#### 31. `Skew`

-   **名称**：滚动偏度算子
    
-   **功能**：计算特征的滚动偏度
    
-   **代码**：
    

`class Skew(Rolling):       """计算特征的滚动偏度"""       def __init__(self, feature, N):           # 偏度计算要求窗口大小至少为3           if N != 0 and N < 3:               raise ValueError("The rolling window size of Skewness operation should >= 3")           super(Skew, self).__init__(feature, N, "skew")   `

#### 32. `Kurt`

-   **名称**：滚动峰度算子
    
-   **功能**：计算特征的滚动峰度
    
-   **代码**：
    

`class Kurt(Rolling):       """计算特征的滚动峰度"""       def __init__(self, feature, N):           # 峰度计算要求窗口大小至少为5           if N != 0 and N < 4:               raise ValueError("The rolling window size of Kurtosis operation should >= 5")           super(Kurt, self).__init__(feature, N, "kurt")   `

#### 33. `Max`

-   **名称**：滚动最大值算子
    
-   **功能**：计算特征的滚动最大值
    
-   **代码**：
    

`class Max(Rolling):       """计算特征的滚动最大值"""       def __init__(self, feature, N):           super(Max, self).__init__(feature, N, "max")   `

#### 34. `IdxMax`

-   **名称**：滚动最大值索引算子
    
-   **功能**：计算滚动窗口内最大值的位置索引
    
-   **代码**：
    

`class IdxMax(Rolling):       """计算滚动窗口内最大值的位置索引"""       def __init__(self, feature, N):           super(IdxMax, self).__init__(feature, N, "idxmax")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = series.expanding(min_periods=1).apply(lambda x: x.argmax() + 1, raw=True)           else:               series = series.rolling(self.N, min_periods=1).apply(lambda x: x.argmax() + 1, raw=True)           return series   `

#### 35. `Min`

-   **名称**：滚动最小值算子
    
-   **功能**：计算特征的滚动最小值
    
-   **代码**：
    

`class Min(Rolling):       """计算特征的滚动最小值"""       def __init__(self, feature, N):           super(Min, self).__init__(feature, N, "min")   `

#### 36. `IdxMin`

-   **名称**：滚动最小值索引算子
    
-   **功能**：计算滚动窗口内最小值的位置索引
    
-   **代码**：
    

`class IdxMin(Rolling):       """计算滚动窗口内最小值的位置索引"""       def __init__(self, feature, N):           super(IdxMin, self).__init__(feature, N, "idxmin")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = series.expanding(min_periods=1).apply(lambda x: x.argmin() + 1, raw=True)           else:               series = series.rolling(self.N, min_periods=1).apply(lambda x: x.argmin() + 1, raw=True)           return series   `

#### 37. `Quantile`

-   **名称**：滚动分位数算子
    
-   **功能**：计算特征的滚动分位数
    
-   **代码**：
    

`class Quantile(Rolling):       """计算特征的滚动分位数"""       def __init__(self, feature, N, qscore):           super(Quantile, self).__init__(feature, N, "quantile")           self.qscore = qscore  # 分位数              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = series.expanding(min_periods=1).quantile(self.qscore)           else:               series = series.rolling(self.N, min_periods=1).quantile(self.qscore)           return series   `

#### 38. `Med`

-   **名称**：滚动中位数算子
    
-   **功能**：计算特征的滚动中位数
    
-   **代码**：
    

`class Med(Rolling):       """计算特征的滚动中位数"""       def __init__(self, feature, N):           super(Med, self).__init__(feature, N, "median")   `

#### 39. `Mad`

-   **名称**：滚动平均绝对偏差算子
    
-   **功能**：计算特征的滚动平均绝对偏差
    
-   **代码**：
    

`class Mad(Rolling):       """计算特征的滚动平均绝对偏差"""       def __init__(self, feature, N):           super(Mad, self).__init__(feature, N, "mad")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)                      def mad(x):               x1 = x[~np.isnan(x)]               return np.mean(np.abs(x1 - x1.mean()))                      if self.N == 0:               series = series.expanding(min_periods=1).apply(mad, raw=True)           else:               series = series.rolling(self.N, min_periods=1).apply(mad, raw=True)           return series   `

#### 40. `Rank`

-   **名称**：滚动排名算子
    
-   **功能**：计算特征在滚动窗口内的排名百分比
    
-   **代码**：
    

`class Rank(Rolling):       """计算特征在滚动窗口内的排名百分比"""       def __init__(self, feature, N):           super(Rank, self).__init__(feature, N, "rank")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)                      rolling_or_expending = series.expanding(min_periods=1) if self.N == 0else series.rolling(self.N, min_periods=1)           if hasattr(rolling_or_expending, "rank"):               return rolling_or_expending.rank(pct=True)                      def rank(x):               if np.isnan(x[-1]):                   return np.nan               x1 = x[~np.isnan(x)]               if x1.shape[0] == 0:                   return np.nan               return percentileofscore(x1, x1[-1]) / 100                      return rolling_or_expending.apply(rank, raw=True)   `

#### 41. `Count`

-   **名称**：滚动计数算子
    
-   **功能**：计算滚动窗口内非NaN元素的数量
    
-   **代码**：
    

`class Count(Rolling):       """计算滚动窗口内非NaN元素的数量"""       def __init__(self, feature, N):           super(Count, self).__init__(feature, N, "count")   `

#### 42. `Delta`

-   **名称**：滚动差值算子
    
-   **功能**：计算特征在滚动窗口内的首尾差值
    
-   **代码**：
    

`class Delta(Rolling):       """计算特征在滚动窗口内的首尾差值"""       def __init__(self, feature, N):           super(Delta, self).__init__(feature, N, "delta")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = series - series.iloc[0]           else:               series = series - series.shift(self.N)           return series   `

#### 43. `Slope`

-   **名称**：滚动斜率算子
    
-   **功能**：计算特征在滚动窗口内的线性回归斜率
    
-   **代码**：
    

`class Slope(Rolling):       """计算特征在滚动窗口内的线性回归斜率"""       def __init__(self, feature, N):           super(Slope, self).__init__(feature, N, "slope")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = pd.Series(expanding_slope(series.values), index=series.index)           else:               series = pd.Series(rolling_slope(series.values, self.N), index=series.index)           return series   `

#### 44. `Rsquare`

-   **名称**：滚动R方算子
    
-   **功能**：计算特征在滚动窗口内的线性回归R方值
    
-   **代码**：
    

`class Rsquare(Rolling):       """计算特征在滚动窗口内的线性回归R方值"""       def __init__(self, feature, N):           super(Rsquare, self).__init__(feature, N, "rsquare")              def _load_internal(self, instrument, start_index, end_index, *args):           _series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = pd.Series(expanding_rsquare(_series.values), index=_series.index)           else:               series = pd.Series(rolling_rsquare(_series.values, self.N), index=_series.index)               # 处理标准差接近0的情况               series.loc[np.isclose(_series.rolling(self.N, min_periods=1).std(), 0, atol=2e-05)] = np.nan           return series   `

#### 45. `Resi`

-   **名称**：滚动残差算子
    
-   **功能**：计算特征在滚动窗口内的线性回归残差
    
-   **代码**：
    

`class Resi(Rolling):       """计算特征在滚动窗口内的线性回归残差"""       def __init__(self, feature, N):           super(Resi, self).__init__(feature, N, "resi")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)           if self.N == 0:               series = pd.Series(expanding_resi(series.values), index=series.index)           else:               series = pd.Series(rolling_resi(series.values, self.N), index=series.index)           return series   `

#### 46. `WMA`

-   **名称**：加权移动平均算子
    
-   **功能**：计算特征的加权移动平均
    
-   **代码**：
    

`class WMA(Rolling):       """计算特征的加权移动平均"""       def __init__(self, feature, N):           super(WMA, self).__init__(feature, N, "wma")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)                      def weighted_mean(x):               w = np.arange(len(x)) + 1               w = w / w.sum()               return np.nanmean(w * x)                      if self.N == 0:               series = series.expanding(min_periods=1).apply(weighted_mean, raw=True)           else:               series = series.rolling(self.N, min_periods=1).apply(weighted_mean, raw=True)           return series   `

#### 47. `EMA`

-   **名称**：指数移动平均算子
    
-   **功能**：计算特征的指数移动平均
    
-   **代码**：
    

`class EMA(Rolling):       """计算特征的指数移动平均"""       def __init__(self, feature, N):           super(EMA, self).__init__(feature, N, "ema")              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)                      def exp_weighted_mean(x):               a = 1 - 2 / (1 + len(x))               w = a ** np.arange(len(x))[::-1]               w /= w.sum()               return np.nansum(w * x)                      if self.N == 0:               series = series.expanding(min_periods=1).apply(exp_weighted_mean, raw=True)           elif0 < self.N < 1:               series = series.ewm(alpha=self.N, min_periods=1).mean()           else:               series = series.ewm(span=self.N, min_periods=1).mean()           return series   `

### 五、二元滚动窗口算子 (Pair-Rolling)

#### 48. `PairRolling`

-   **名称**：二元滚动窗口算子基类
    
-   **功能**：所有二元滚动窗口算子的抽象基类
    
-   **代码**：
    

`class PairRolling(ExpressionOps):       """二元滚动窗口算子的基类"""       def __init__(self, feature_left, feature_right, N, func):           self.feature_left = feature_left           self.feature_right = feature_right           self.N = N           self.func = func              def _load_internal(self, instrument, start_index, end_index, *args):           # 加载左右特征           if isinstance(self.feature_left, Expression):               series_left = self.feature_left.load(instrument, start_index, end_index, *args)           else:               series_left = self.feature_left           if isinstance(self.feature_right, Expression):               series_right = self.feature_right.load(instrument, start_index, end_index, *args)           else:               series_right = self.feature_right                      # 应用滚动或扩展窗口操作           if self.N == 0:               series = getattr(series_left.expanding(min_periods=1), self.func)(series_right)           else:               series = getattr(series_left.rolling(self.N, min_periods=1), self.func)(series_right)           return series   `

#### 49. `Corr`

-   **名称**：滚动相关系数算子
    
-   **功能**：计算两个特征在滚动窗口内的相关系数
    
-   **代码**：
    

`class Corr(PairRolling):       """计算两个特征在滚动窗口内的相关系数"""       def __init__(self, feature_left, feature_right, N):           super(Corr, self).__init__(feature_left, feature_right, N, "corr")              def _load_internal(self, instrument, start_index, end_index, *args):           res = super(Corr, self)._load_internal(instrument, start_index, end_index, *args)                      # 处理标准差接近0的情况           series_left = self.feature_left.load(instrument, start_index, end_index, *args)           series_right = self.feature_right.load(instrument, start_index, end_index, *args)           res.loc[               np.isclose(series_left.rolling(self.N, min_periods=1).std(), 0, atol=2e-05)               | np.isclose(series_right.rolling(self.N, min_periods=1).std(), 0, atol=2e-05)           ] = np.nan           return res   `

#### 50. `Cov`

-   **名称**：滚动协方差算子
    
-   **功能**：计算两个特征在滚动窗口内的协方差
    
-   **代码**：
    

`class Cov(PairRolling):       """计算两个特征在滚动窗口内的协方差"""       def __init__(self, feature_left, feature_right, N):           super(Cov, self).__init__(feature_left, feature_right, N, "cov")   `

### 六、时间索引相关算子 (Time Index Related)

#### 51. `TResample`

-   **名称**：时间重采样算子
    
-   **功能**：将数据按指定频率重采样
    
-   **代码**：
    

`class TResample(ElemOperator):       """将数据按指定频率重采样"""       def __init__(self, feature, freq, func):           self.feature = feature           self.freq = freq  # 重采样频率           self.func = func  # 重采样方法              def _load_internal(self, instrument, start_index, end_index, *args):           series = self.feature.load(instrument, start_index, end_index, *args)                      if series.empty:               return series           else:               if self.func == "sum":                   return getattr(series.resample(self.freq), self.func)(min_count=1)               else:                   return getattr(series.resample(self.freq), self.func)()   `

### 七、算子包装器和注册机制

#### 52. `OpsWrapper`

-   **名称**：算子包装器
    
-   **功能**：提供算子的注册和访问功能
    
-   **代码**：
    

`class OpsWrapper:       """算子包装器"""       def __init__(self):           self._ops = {}              def reset(self):           self._ops = {}              def register(self, ops_list):           # 注册算子列表           for _operator in ops_list:               # 处理不同类型的算子定义               if isinstance(_operator, dict):                   _ops_class, _ = get_callable_kwargs(_operator)               else:                   _ops_class = _operator                              # 检查是否为ExpressionOps的子类               ifnot issubclass(_ops_class, (Expression,)):                   raise TypeError("operator must be subclass of ExpressionOps")                              # 注册算子               if _ops_class.__name__ in self._ops:                   get_module_logger(self.__class__.__name__).warning(                       "The custom operator [%s] will override the qlib default definition", _ops_class.__name__                   )               self._ops[_ops_class.__name__] = _ops_class              def __getattr__(self, key):           # 通过属性访问获取算子           if key notin self._ops:               raise AttributeError("The operator [{0}] is not registered".format(key))           return self._ops[key]   `

#### 53. `register_all_ops`

-   **名称**：注册所有算子
    
-   **功能**：注册所有内置算子和自定义算子
    
-   **代码**：
    

`def register_all_ops(C):       """注册所有算子"""       logger = get_module_logger("ops")              from qlib.data.pit import P, PRef  # 导入额外的算子              # 重置并注册内置算子       Operators.reset()       Operators.register(OpsList + [P, PRef])              # 注册自定义算子       if getattr(C, "custom_ops", None) isnotNone:           Operators.register(C.custom_ops)           logger.debug("register custom operator %s", C.custom_ops)   `

  

  

* * *

1.什么问题？怎么解决问题？

2.不陷入事和人

3.没有能力突围就淡定下来

4.按自己内心的长期主义