# 一种有效&quot;均值收敛因子&quot;的单因子策略——原理、实证、代码

蝴蝶量化 随率而动的因子工厂 2026-02-13 22:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484450&idx=1&sn=9e81aa83788bda64fea8523dca0b674c&chksm=c01559661a661874e94c406622e1f4b020413bc7c8fa34113c69d62e26e8d006268b7d582968#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484450&idx=1&sn=9e81aa83788bda64fea8523dca0b674c&chksm=c01559661a661874e94c406622e1f4b020413bc7c8fa34113c69d62e26e8d006268b7d582968#rd)

## 技术背景

很多做过技术分析的小伙伴都知道，均线作为技术指标的根源，扮演着很重要的作用。你也一定听说过大道至简：一根均线走天下的传说。

普通人使用均线无非是下面几种：

-   **1、金叉、死叉：** 金叉做多、死叉做空。
    
-   **2、均线多头排列：** 满足：短期均线 > 中期均线 > 长期均线.
    
-   **3、均线支撑、阻力：** 20日线、半年线、年线都是关键的支撑点位。
    
-   **4、均线粘连：** 很多技术分析者认为均线的粘连是一波行情启动的预兆。
    

那么上面的结论一点正确吗？或者说在多因子策略中是否能够有效呢？

或者说你也很想知道通过什么方法能够将均线粘连的标的全部选出来，并且进行排序，那你一定要看完本期文章

本期文章，我们将以均线作为底层因子，通过数学上的一些算法，将均线这个常用的技术指标转化为一种简单、有效的截面因子。并且给出了新因子的IC、分组收益等检验数据，并且一次构造了一种指数增强的算法。

**同样，本文算法参考了券商的研报，结合了自己的一些方法，使用代码请谨慎。**

**本文的重点是验证：均线粘连对后市的影响，并且构造相应的策略。**

至于均线的金叉、死叉，多头排列，其实我们在之前成交量的择时系统的文章：文章标题中，算法、代码都是现成的，如果当时你找我要了相应的代码，只需要做很少的修改就可以得到相应的验证程序。

## 理论分析

既然本文的重点是：**均线粘连**，绝大部分对这个“粘连”仅仅是个概念，作为量化人，第一反应就是将其转化为**数字**，从而方便做定量分析。我们统称为**收敛因子**

### 1、定义

**收敛定义：**其中：factor 为价格收敛因子（Price Convegence Factor，PCF），其中当日收盘价即为 。为便捷表述，下文存在中文名称与英文简写混用。 \*\*值得注意：\*\* 这里的，可以是各种数据的均值：成交量、收盘价、换手率、成交额等等等。

**公式解释：** 我们将同一股票、不同周期、同一时间点某一个数据的均值的标准差作为基础数据，然后取对数。

**对数变化：** 对数变换（尤其是）能有效压缩右尾，使因子分布更接近正态分布，提升因子与收益之间的线性相关性（IC 稳定性）。至于加1，主要是将数据调整为非负值，并且通过泰勒展开可知：在x比较小的时候，，保留了x比较小时的特性。

**取负值：** 从经验上来讲，一般越收敛得到了std值越小，行业后期的预期收益越大，所以**收敛因子**经验上是一个**负向因子**。所以**取负值**主要是为了将因子的IC调整为正，分组收益：单调增、因子值越大收益越高。

### 2、几个重要的因子

**1、PCF：** 价格收敛因子（PCF）：X = 后复权收盘价

**2、VCF：**成交量收敛因子（VCF）：X = 成交量

**3、ACF：**成交额收敛因子（ACF）：X = 成交额

**4、TRCF：**换手率收敛因子（TRCF）：X = 换手率

**5、PVCF：** 价量双收敛因子（PVCF）：对PCF、VCF分别做**截面标准化**（Z-score）后等权相加。

### 3、检验方法

#### rank\_IC、IR检验法

参见之前的文章

#### 分组收益

参见之前的文章

### 4、指数增强

为了能够获取纯净的Alpha收益，我们将股池锁定在某个指数历史所有成分股的范围之内。这里就有很多种方法做，之前我们的文章：《指数增强的另类方法》，就是其中一种。本文这里介绍两种常见方法：

**1、直接法** 成分股范围内，做普通的多因子选股。选择多头组作为指数的替代，根据需求多头组股票之间可以不相同。这类方法主要应用在行业指数中，不需要做行业中性等等。

**2、组合条件优化法** 这种方法比较繁琐，对冲精准，主要应用在综合指数中，严格控制**风格、行业**等原始权重的变化。这里仅仅给出方法的理论，以后的文章中详细介绍： 为了更好地控制跟踪误差，我们尝试使用约束优化求解的方式对宽基指数进行增强测试。换手率收敛因子是一个正向因子，因此组合预期收益率最大化等价于因子暴露度最大化。前文中，我们在做因子构建的时候，其实是希望暴露于特定的风格以换取长期的超额表现，如低波和低关注度，因此在约束条件中我们放松对 Barra 风格的约束。

其中，

-   表示因子暴露度
    
-    表示待优化权重
    
-    表示基准指数的成分股权重
    
-    表示风格暴露度矩阵
    
-    表示行业变量矩阵
    
-    和  分别表示风格暴露度的偏离上下限
    
-   和  分别表示行业偏离上下限
    
-    和  分别表示权重偏离的上下限
    
-    表示股票池个股是否位于指数成分股的指示性向量
    
-    表示成分股权重的下限。
    

具体而言，约束条件的参数 、 设置为 None，、 分别设置为 -0.01、0.01， 设置为 0.8，、分别设置为 -0.01、0.01。

## 实证

### PCF价格收敛因子

**IC、IR分析图**

![](assets/001.png)

![](assets/002.png)经过计算：PCF的平均IC\_mean:0.0476;IR为2.01。显然PCF还算是一个不错的因子。

**分组收益图**![](assets/003.png)但是从分组表现上来看，并不算非常优秀。在第四组、第五组表现一般。

### VCF成交量收敛因子

**IC、IR分析图**

![](assets/004.png)

![](assets/005.png)ACF的平均IC为0.0836，IR为3.77显然较PCF有了很大的进步

**分组收益图**![](assets/006.png)显然成交量收敛因子的分成效果非常明显，多空收益达到27.8的净值。纯多头也是达到了7.24。

### ACF

**IC、IR分析图**

![](assets/007.png)

![](assets/008.png)相比较之前的成交额因子表现更加劲爆：IC均值达到了8.58，IR更是高达5.12

**分组收益**![](assets/009.png)多空收益年化62.58%，净值达到了恐怖的：91.89。纯多头净值也是到达了12.6.

### TRCF

**IC、IR分析图**![](assets/010.png)

![](assets/011.png)平均IC：0.0836，IR：3.77

**分组收益图**![](assets/012.png)

多头组净值：5.95，多头净值：35.02

### PVCF价格、成交量综合因子

**IC、IR**![](assets/013.png)

![](assets/014.png)IC均值：7.75，IR：4.64

**分组收益图**![](assets/015.png)

多空净值：31.2，多头组净值：7.51

## 代码

代码借助了deepseek的帮助，感谢AI给我们带来便利。由于花费了大量的人力、物力调试、测试，所以这里仅给出部分代码，完整代码后期星球见。

**仅展示了因子计算、程序结构等代码**

`class ConvergenceFactorAnalyzer:       """       均线收敛/发散因子选股回测框架       - 支持自定义股票列表       - 支持指定因子计算频率（日频/周频/月频），与回测频率保持一致       - 分组回测 + 指数增强回测       - 现代化 Plotly 绘图       """          def __init__(self,                    start_date: str,                    end_date: str ,                    data_path: str,                    stock_list: Optional[List[str]] = None,                    index_file: Optional[str] = None,                    constituent_file: Optional[str] = None,                    windows: List[int] = None,                    calc_freq: str = 'W-FRI'):           """           初始化回测器           :param data_path: 股票日线CSV文件夹路径，每个股票一个文件 {code}.csv           :param stock_list: 要加载的股票代码列表，None表示加载全部           :param index_file: 基准指数日线CSV文件路径（必须含date, close）           :param constituent_file: 指数成分股列表CSV文件路径（必须含date, code）           :param windows: 均线周期列表，默认[1,5,10,20,60,120]           :param calc_freq: 因子计算频率，'D'=日频，'W'=周频，'M'=月频，默认'D'           """           self.start_date = pd.to_datetime(str(start_date)) if start_date elseNone           self.end_date = pd.to_datetime(str(end_date)) if end_date elseNone           self.data_path = data_path           self.stock_list = stock_list           self.index_file = index_file           self.constituent_file = constituent_file           self.windows = windows if windows else [1, 5, 10, 20, 60, 120]           self.calc_freq = calc_freq              # 数据容器           self.stock_data_resample = None      # 原始日频数据 (MultiIndex)           self.stock_data = None         # 当前使用频率的数据（可能重采样）           self.index_close = None        # 指数收盘价 Series           self.constituents = None       # 成分股字典 {date: [codes]}           self.returns = None           # 个股下期收益率矩阵 (index=date, columns=code)           self.factors = {}            # 因子名 -> DataFrame (index=date, columns=code)              # 回测结果容器           self.group_results = {}       # 分组回测结果 (rank_ic, group_ret)           self.enhance_results = {}     # 指数增强回测结果 (enh_port_df)          # ------------------------------------------------------------------       # 1. 数据加载模块       # ------------------------------------------------------------------       def load_data(self):           """加载股票日线、指数、成分股数据"""           self._load_stock_data()           self._load_index_data()           self._load_constituents()           self._resample_stock_data(freq=self.calc_freq)           self._calc_returns()           print("数据加载完成。")          def _load_stock_data(self):           """           加载个股日线数据:           :return self.stock_data 保存在这个容器中           """           all_dfs = []           if self.stock_list isNone:               files = [f for f in os.listdir(self.data_path) if f.endswith('.csv')]           else:               files = [f"{code}.csv"for code in self.stock_list                        if os.path.exists(os.path.join(self.data_path, f"{code}.csv"))]              ifnot files:               raise FileNotFoundError(f"未找到任何股票数据，请检查路径: {self.data_path}")              for file in files:               df = pd.read_csv(os.path.join(self.data_path, file),converters={'date': str})               df['date'] = pd.to_datetime(df['date'])               df = df[df['date'].between(self.start_date, self.end_date)].copy()               df.sort_values('date',inplace=True,ascending=True,ignore_index=True)                  all_dfs.append(df)              df = pd.concat(all_dfs, ignore_index=True)           df = df.sort_values(['date', 'stock_code']).set_index(['date', 'stock_code'])              # 基础清洗           required_cols = ['close', 'vol', 'amount', 'turnover_rate']           df = df.dropna(subset=required_cols)           self.stock_data = df          def _resample_stock_data(self, freq: str=None):           """           将股票数据重采样至指定频率（取每个周期最后一个交易日）           """           print(f"正在将股票数据重采样至频率: {freq}")           if freq isNone:               freq = self.calc_freq           # 按股票代码分组，对每个股票的日线序列重采样           resampled_list = []           for code, group in self.stock_data.groupby('stock_code'):               # 移除code索引，使date成为索引，以便resample               group = group.reset_index(level='stock_code', drop=True)               group = group.resample(freq).agg({'open':'first',                                                 'low':'min',                                                 'high':'max',                                                 "close":'last',                                                 'vol':'sum',                                                 'amount':'sum',                                                 "turnover_rate":'sum'}).dropna(how='all')               group['stock_code'] = code               group = group.set_index('stock_code', append=True)               resampled_list.append(group)           self.stock_data_resample = pd.concat(resampled_list).sort_index()           self.stock_data_resample.index.names = ['date', 'stock_code']          def _load_index_data(self):           """加载基准指数日线"""           if self.index_file and os.path.exists(self.index_file):               idx_df = pd.read_csv(self.index_file, parse_dates=['date'])               idx_df = idx_df[idx_df['date'].between(self.start_date, self.end_date)].copy()               idx_df = idx_df.set_index('date')['close'].sort_index()               # 指数数据也重采样至 calc_freq（如果非日频）               if self.calc_freq != 'D':                   idx_df = idx_df.resample(self.calc_freq).last()               self.index_close = idx_df           else:               print("警告: 未提供指数文件，指数增强回测将无法进行。")             def _load_constituents(self):           """           加载指数成分股列表（日期->股票列表）           注意：这里指数成分股数据，           """           if self.constituent_file and os.path.exists(self.constituent_file):               cons_df = pd.read_csv(self.constituent_file, parse_dates=['date'])               cons_df = cons_df[cons_df['date'].between(self.start_date, self.end_date)].copy()               self.constituents = cons_df.groupby('date')['stock_code'].apply(list).to_dict()           else:               self.constituents = None               print("警告: 未提供成分股文件，指数增强将使用全股票池（非真实指数增强）。")          def _calc_returns(self, period: int = 1):           """计算个股下期收益率（持有期为1个数据周期）"""           if self.stock_data_resample isNone:               raise ValueError("请先调用 load_data() 加载数据。")           close_pivot = self.stock_data_resample['close'].unstack()  # 将Series多重index转化为index为date，           # 下月收益率（实际应精确对齐调仓日，此处简化为T+21收益）           # 注：正式使用建议改用 resample 方式对齐           self.returns = close_pivot.pct_change(periods=period).shift(-period)          # ------------------------------------------------------------------       # 2. 因子计算模块       # ------------------------------------------------------------------       @staticmethod       def _calc_single_factor(series: pd.Series, windows: List[int]) -> pd.Series:           """计算单只股票的收敛因子"""           df = pd.DataFrame(index=series.index)           for w in windows:               if w == 1:                   df[f'ma{w}'] = series               else:                   df[f'ma{w}'] = series.rolling(w, min_periods=min(w, 20)).mean()           std = df.std(axis=1)           return -np.log1p(std)          def calc_factors(self,                        factor_names: List[str] = None                        ):           """           计算收敛因子，自动适配当前数据频率           :param factor_names: 需计算的因子列表，默认全算 ['PCF','VCF','ACF','TRCF','PVCF']           """           if self.stock_data isNone:               raise ValueError("请先调用 load_data() 加载数据。")              all_factor_def = {               'PCF': 'close',               'VCF': 'vol',               'ACF': 'amount',               'TRCF': 'turnover_rate'           }           if factor_names isNone:               factor_names = list(all_factor_def.keys()) + ['PVCF']              for name in factor_names:               if name == 'PVCF':                   continue               if name notin all_factor_def:                   print(f"跳过未知因子: {name}")                   continue               col = all_factor_def[name]               print(f"正在计算因子: {name} ...")               fac = self.stock_data[col].groupby('stock_code', group_keys=False).apply(                   lambda x: self._calc_single_factor(x, self.windows)               ).rename('factor')               # 生成一个列明为stock_code的dataframe               fac = fac.reset_index().pivot(index='date', columns='stock_code', values='factor')               self.factors[name] = fac  # self.factor为dict              # 计算 PVCF（PCF + VCF 标准化后等权合成）           # 注意：这里的标准化为截面因子           if ('PVCF'in factor_names) and ('PCF'in self.factors) and ('VCF'in self.factors):               print("正在合成因子: PVCF (逐日截面标准化) ...")               pcf = self.factors['PCF'].copy()               vcf = self.factors['VCF'].copy()                  # 对齐日期和股票               common_dates = pcf.index.intersection(vcf.index)               common_codes = pcf.columns.intersection(vcf.columns)               pcf = pcf.loc[common_dates, common_codes]               vcf = vcf.loc[common_dates, common_codes]                  # 逐期截面标准化（Z-score）               pcf_mean = pcf.mean(axis=1)               pcf_std = pcf.std(axis=1).replace(0, np.nan)  # 标准差为0时设为NaN               vcf_mean = vcf.mean(axis=1)               vcf_std = vcf.std(axis=1).replace(0, np.nan)                  pcf_z = pcf.sub(pcf_mean, axis=0).div(pcf_std, axis=0).fillna(0)               vcf_z = vcf.sub(vcf_mean, axis=0).div(vcf_std, axis=0).fillna(0)                  self.factors['PVCF'] = pcf_z + vcf_z              print("因子计算完成。")   `

## 总结

本文从**均值收敛**的角度出发，给出了：收盘价、成交量、成交额、换手率作为底层数据，计算均值收敛因子。通过单因子测试，每一个因子表现都很优异。**特别是成交额的收敛因子尤为突出。**

因子固然重要，但是分析均值不同的角度是否可以用在其他的因子上？整体的分析框架是否熟悉？有没有值得改进的细节？这些问题答案，我想比因子本身更加值得思考，如果你有其他好的方法、疑问欢迎留言讨论。