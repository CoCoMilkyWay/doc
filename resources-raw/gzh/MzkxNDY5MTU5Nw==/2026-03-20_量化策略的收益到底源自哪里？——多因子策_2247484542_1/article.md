# 量化策略的收益到底源自哪里？——多因子策略归因分析原理与实践代码

蝴蝶量化 随率而动的因子工厂 2026-03-20 17:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484542&idx=1&sn=0922489272a89525776cae38ec06ff7a&chksm=c0d477f050e1468b7c87b0fbb724ee80a1b36eaf9dc04160bdb2cfadfca65c20ac069c755e32#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484542&idx=1&sn=0922489272a89525776cae38ec06ff7a&chksm=c0d477f050e1468b7c87b0fbb724ee80a1b36eaf9dc04160bdb2cfadfca65c20ac069c755e32#rd)

## 技术背景

在量化普及的年代，你一定听过各种因子的传说，但是你是不是有这样的疑问：**通过多因子策略选出来的股票收益，到底有多少来源于这些因子？** 特别是在市场好的时候，经常听说别人通过什么因子赚了多少倍，那么他的收益真的源自他所说的因子吗？本文将给出科学、准确的判断方法。

之前我们讲了很多的关于多因子文章，覆盖了：因子基础知识、因子库的搭建、因子合成、因子检验、策略构建等等。也包含了：如何评价一个策略的好与坏、一个好的策略到底长什么样？最近总感觉这里面还是少点了什么，直到昨天，我发现有一个比较关键的问题，一直没有讲，就是：**策略收益到底是否源于因子？**

说白了就是说，一个策略收益利润有多少是来自于因子收益？哪些是源自于市场收益？哪些是运气成分？

本期文章的主要内容：**如何做多因子策略收益的归因分析？**

**当然，多因子策略在因子择时、合成时，分为线性、非线性模型。** 本文主要是对线性模型的**收益归因分析**，至于机器学习、LLM等非线性模型的归因分析我们在以后再介绍。

## 什么是归因分析？

对多因子策略进行收益归因分析，核心目的是拆解策略收益的来源，判断收益是来自于暴露了某些风险因子（如承担了市场风险、规模风险），还是来自于纯粹的阿尔法能力（选股能力），或者是来自于行业、风格的短期运气。

我们都知道，一个投资组合的收益主要由下面的三种收益构成：

1.  市场的整体带来的某种收益：市场收益，源自于资本资产定价模型。
    
2.  组合的超额收益，也就是因子收益：属于广义上的收益，这里的收益属于资本资产定价模型中收益范畴，但是同时又是因子的beta收益。
    
3.  残差收益，也就是运气收益：也就是通过多因子模型回归后，剩下的均值为0的残差部分。
    

这时候你就需要回顾一下**资本资产定价模型、多因子策略模型的公式**。如果忘记了可以阅读结尾关于这部分的进一步介绍。但这不是本文的重点内容。

那么，本文通过**时序回归**模型可以准确的给出最近一段时间那个因子给你的贡献最大，到底我这个收益源自于哪些因子？

## 线性模型——归因分析方法

对于多因子策略收益的归因分析，无非就是分析策略的收益在多大程度上可以解释为对已知因子（如价值、动量、质量等）的暴露。我们以**Barra模型（风险模型）**为例。

### 一、具体原理、步骤

基本思路是：将策略（或投资组合）的收益率序列对一系列因子收益率进行时间序列回归。

#### 1\. 准备数据

-   **策略收益率**：（投资组合每日、每月收益率）
    
-   **因子收益率**： 没具体可以常看我们往期的文章：[<因子值、因子收益、因子暴露的相互关系>](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484162&idx=1&sn=ad669836aa856361f2dda0424d7816e4&scene=21#wechat_redirect)
    
-   **无风险利率**：
    

#### 2\. 时间序列回归法

构建如下回归模型：

-   ：阿尔法收益。代表不能被已知因子解释的超额收益（即真正的选股能力）。
    
-   ：因子暴露。表示策略对因子的敏感度（即策略在多大程度上像一只“小盘股”或“价值股”）。
    
-   ：残差收益（特异性收益）。
    

**分析：**

1.  **判断显著性**：看是否显著大于0。如果显著为正且很大，说明策略有独立于**已知风险因子**的选股能力。
    
2.  **分解收益**：计算每个因子对总收益的贡献。
    

-   因子贡献 =  该因子的平均收益率。
    
-   通过对比各因子的贡献，可以知道策略收益主要是由“小盘股效应”带来的，还是由“低波效应”带来的。
    

#### 3\. 截面回归法

如果策略换手率较高，或者想了解**特定调仓时点**的归因，可以使用截面回归。

-   **方法**：在每个调仓日，将持仓个股的收益率对当期的因子暴露进行回归，得到该截面上的因子收益率，**然后加权得到组合的整体因子收益。**
    
-   这就是一般计算因子收益的回归模型,区别在于对于截面股票池为你的当期持仓.
    

### 二、常见结论与解读

-   **真正的阿尔法**：阿尔法显著 > 0，且残差平稳。这说明你的因子挖掘或组合权重优化确实有效。
    
-   **Smart Beta**：阿尔法不显著，但收益主要来自规模因子或价值因子的稳定暴露。这说明你做的不是对冲基金，而是低成本的因子ETF，需要考虑收取管理费是否合理。
    
-   **风险错配/伪阿尔法**：阿尔法显著，但进一步分析发现阿尔法主要来自对某个行业（如白酒）或某个风格（如壳价值）的集中押注。一旦风格反转，策略可能会遭遇较大回撤。
    

### 可视化分析

数据为构造数据，收益不供参考。

**因子收益分解图**

![](assets/001.png)本图主要是用于观察策略收益、因子解释收益、残差alpha收益的分解情况。

**因子的平均收益**

![](assets/002.png)用于观察多因子的不同收益情况。

**因子暴露热力图**

![](assets/003.png)用于观察因子收益长期以来的趋势于分布情况。

**行业、综合分析图**

![](assets/004.png)仅作为展示，具体看代码

### python代码

本代码由deepseek辅助变成，笔者修改与适配，请谨慎使用。数据可以接你自己的因子数据，或者仅参考算法

`import numpy as np   import pandas as pd   import statsmodels.api as sm   import matplotlib.pyplot as plt   import seaborn as sns   import warnings      warnings.filterwarnings('ignore')      # 设置中文显示   plt.rcParams['font.sans-serif'] = ['SimHei']   plt.rcParams['axes.unicode_minus'] = False         # ==============================   # 1. 因子时间序列归因类   # ==============================   class FactorAttribution:       """       因子时间序列归因类       功能：对策略收益率进行因子模型回归，计算 alpha、因子暴露、因子贡献，            并绘制累计收益分解图、因子贡献柱状图、滚动因子暴露热力图。       """          def __init__(self, portfolio_return, factor_returns, rf=None):           """           参数           ----------           portfolio_return : pd.Series               策略收益率序列，index 为日期           factor_returns : pd.DataFrame               因子收益率序列，index 为日期，columns 为因子名称           rf : pd.Series, optional               无风险利率序列，index 同 portfolio_return，默认为 0           """           self.portfolio_return = portfolio_return.copy()           self.factor_returns = factor_returns.copy()           self.rf = rf if rf is not None else pd.Series(0, index=portfolio_return.index)              # 统一索引，去除缺失值           self.data = pd.concat([self.portfolio_return - self.rf, self.factor_returns], axis=1).dropna()           self.y = self.data.iloc[:, 0]           self.X = self.data.iloc[:, 1:]              self.results = {}  # 存储回归结果          def fit(self, cov_type='HAC', maxlags=5):           """           执行时间序列回归，计算 alpha、beta、因子贡献等。              参数           ----------           cov_type : str               statsmodels 中协方差矩阵类型，'HAC' 为 Newey-West 调整           maxlags : int               HAC 调整的最大滞后阶数           """           X_with_const = sm.add_constant(self.X)           model = sm.OLS(self.y, X_with_const).fit(cov_type=cov_type, cov_kwds={'maxlags': maxlags})              self.results['model'] = model           self.results['alpha'] = model.params['const']           self.results['beta'] = model.params.drop('const')           self.results['t_values'] = model.tvalues.drop('const')           self.results['p_values'] = model.pvalues.drop('const')           self.results['r_squared'] = model.rsquared              # 因子贡献 = beta * 因子平均收益率           self.results['factor_contribution'] = self.results['beta'] * self.factor_returns.mean()              # 累计收益分解           factor_cum = (self.factor_returns * self.results['beta']).cumsum()           total_cum = self.y.cumsum()           residual_cum = total_cum - factor_cum.sum(axis=1)           self.results['cumulative_decomp'] = {               'factor_cum': factor_cum,               'residual_cum': residual_cum,               'total_cum': total_cum           }              return self          def summary(self, annualize=True, periods_per_year=252):           """打印回归结果摘要"""           alpha_annual = self.results['alpha'] * periods_per_year if annualize else self.results['alpha']           print("=== 因子时间序列归因结果 ===")           print(f"Alpha (年化): {alpha_annual:.4f}")           print(f"R-squared: {self.results['r_squared']:.4f}")           print("\n因子暴露 (Beta):")           print(self.results['beta'].round(4))           print("\n因子贡献 (平均每日收益):")           print(self.results['factor_contribution'].round(6))           print("\nT统计量:")           print(self.results['t_values'].round(2))          def plot_cumulative_decomposition(self, figsize=(12, 6)):           """绘制累计收益分解图"""           cum = self.results['cumulative_decomp']           plt.figure(figsize=figsize)           plt.plot(cum['total_cum'], label='策略累计超额收益', linewidth=2)           plt.plot(cum['factor_cum'].sum(axis=1), label='因子解释累计收益', linestyle='--')           plt.plot(cum['residual_cum'], label='残差累计收益（alpha）', linestyle=':')           plt.title('累计收益分解')           plt.xlabel('日期')           plt.ylabel('累计收益')           plt.legend()           plt.grid(True)           plt.show()          def plot_factor_contribution(self, figsize=(8, 5)):           """绘制因子贡献柱状图"""           contrib = self.results['factor_contribution']           plt.figure(figsize=figsize)           contrib.plot(kind='bar', color='steelblue')           plt.title('各因子平均每日贡献')           plt.ylabel('贡献')           plt.axhline(0, color='black', linewidth=0.8)           plt.grid(axis='y')           plt.show()          def rolling_exposure_heatmap(self, window=60, figsize=(12, 6)):           """           计算滚动窗口的因子暴露并绘制热力图              参数           ----------           window : int               滚动窗口大小（交易日）           figsize : tuple               图形尺寸           """           # 创建空的DataFrame，指定数据类型为float           rolling_betas = pd.DataFrame(index=self.X.index[window - 1:],                                        columns=self.X.columns,                                        dtype=float)              for i in range(window - 1, len(self.y)):               y_window = self.y.iloc[i - window + 1:i + 1]               X_window = self.X.iloc[i - window + 1:i + 1]               X_window = sm.add_constant(X_window)               try:                   model = sm.OLS(y_window, X_window).fit()                   beta_vals = model.params.drop('const')                   # 确保赋值的是浮点数                   rolling_betas.iloc[i - window + 1] = beta_vals.astype(float)               except Exception as e:                   # 回归失败时填充NaN                   rolling_betas.iloc[i - window + 1] = np.nan              # 强制转换为float类型，防止object类型导致绘图错误           rolling_betas = rolling_betas.astype(float)              # 检查是否有有效数据           if rolling_betas.isnull().all().all():               print("警告：滚动暴露计算结果全为NaN，无法绘制热力图")               return rolling_betas              # 绘制热力图           plt.figure(figsize=figsize)           sns.heatmap(rolling_betas.T, cmap='RdBu_r', center=0, annot=False,                       cbar_kws={'label': 'Beta暴露'}, linewidths=0.5)           plt.title(f'因子暴露热力图（滚动{window}日窗口）')           plt.xlabel('日期')           plt.ylabel('因子')           plt.tight_layout()           plt.show()              return rolling_betas         # ==============================   # 2. Brinson 归因类   # ==============================   class BrinsonAttribution:       """       Brinson 行业归因类       将组合相对于基准的超额收益分解为配置效应、选股效应和交互效应。       """          def __init__(self, benchmark_weights, portfolio_weights,                    benchmark_stocks, portfolio_stocks):           """           参数           ----------           benchmark_weights : pd.Series               基准行业权重，index 为行业名称           portfolio_weights : pd.Series               组合行业权重，index 为行业名称           benchmark_stocks : pd.DataFrame               基准个股数据，必须包含列：industry, stock, return, weight_in_bench           portfolio_stocks : pd.DataFrame               组合个股数据，必须包含列：industry, stock, return, weight_in_port           """           self.benchmark_weights = benchmark_weights.copy()           self.portfolio_weights = portfolio_weights.copy()           self.benchmark_stocks = benchmark_stocks.copy()           self.portfolio_stocks = portfolio_stocks.copy()              # 确保行业列表一致           self.industries = benchmark_weights.index.tolist()          def _calc_industry_return(self, stocks_df, weight_col, return_col='return'):           """计算每个行业的收益率（行业内加权平均）"""           industry_return = {}           for ind in self.industries:               sub = stocks_df[stocks_df['industry'] == ind]               if len(sub) == 0:                   industry_return[ind] = 0               else:                   # 行业内权重归一化（如果 weight_col 不是行业内的权重，需要先归一化）                   total_w = sub[weight_col].sum()                   if total_w > 0:                       ind_return = (sub[return_col] * sub[weight_col]).sum() / total_w                   else:                       ind_return = 0                   industry_return[ind] = ind_return           return pd.Series(industry_return)          def run(self):           """执行 Brinson 分解"""           # 计算基准行业收益率和组合行业收益率           bench_ind_return = self._calc_industry_return(self.benchmark_stocks, 'weight_in_bench')           port_ind_return = self._calc_industry_return(self.portfolio_stocks, 'weight_in_port')              # 基准总收益           benchmark_total_return = (bench_ind_return * self.benchmark_weights).sum()           # 组合总收益           portfolio_total_return = (port_ind_return * self.portfolio_weights).sum()           # 超额收益           excess_return = portfolio_total_return - benchmark_total_return              # 逐行业分解           results = []           for ind in self.industries:               w_b = self.benchmark_weights[ind]               w_p = self.portfolio_weights[ind]               r_b = bench_ind_return[ind]               r_p = port_ind_return[ind]                  allocation = (w_p - w_b) * (r_b - benchmark_total_return)               selection = w_b * (r_p - r_b)               interaction = (w_p - w_b) * (r_p - r_b)                  results.append({                   '行业': ind,                   '基准权重': w_b,                   '组合权重': w_p,                   '基准行业收益': r_b,                   '组合行业收益': r_p,                   '配置效应': allocation,                   '选股效应': selection,                   '交互效应': interaction,                   '总贡献': allocation + selection + interaction               })              self.results_df = pd.DataFrame(results)              # 汇总           total_allocation = self.results_df['配置效应'].sum()           total_selection = self.results_df['选股效应'].sum()           total_interaction = self.results_df['交互效应'].sum()           total_attributed = total_allocation + total_selection + total_interaction              self.summary_stats = {               'benchmark_total_return': benchmark_total_return,               'portfolio_total_return': portfolio_total_return,               'excess_return': excess_return,               'total_allocation': total_allocation,               'total_selection': total_selection,               'total_interaction': total_interaction,               'total_attributed': total_attributed           }              return self          def print_summary(self):           """打印归因结果摘要"""           stats = self.summary_stats           print("=== Brinson 归因结果 ===")           print(f"基准总收益: {stats['benchmark_total_return']:.4%}")           print(f"组合总收益: {stats['portfolio_total_return']:.4%}")           print(f"超额收益: {stats['excess_return']:.4%}")           print(f"配置效应合计: {stats['total_allocation']:.4%}")           print(f"选股效应合计: {stats['total_selection']:.4%}")           print(f"交互效应合计: {stats['total_interaction']:.4%}")           print(f"归因总和: {stats['total_attributed']:.4%} (应等于超额收益: {stats['excess_return']:.4%})")          def plot_decomposition(self, figsize=(15, 4)):           """绘制 Brinson 归因图表（改进版，避免饼图负值问题）"""           fig, axes = plt.subplots(1, 3, figsize=figsize)              # 1. 各行业效应分解柱状图           self.results_df.set_index('行业')[['配置效应', '选股效应', '交互效应']].plot(               kind='bar', ax=axes[0], title='各行业效应分解')           axes[0].axhline(0, color='black', linewidth=0.8)           axes[0].set_ylabel('贡献')              # 2. 超额收益来源水平条形图（可展示正负）           labels = ['配置效应', '选股效应', '交互效应']           sizes = [self.summary_stats['total_allocation'],                    self.summary_stats['total_selection'],                    self.summary_stats['total_interaction']]           colors = ['#ff9999' if x < 0 else '#66b3ff' for x in sizes]  # 负值用红色           axes[1].barh(labels, sizes, color=colors)           axes[1].axvline(0, color='black', linewidth=0.8)           axes[1].set_xlabel('贡献')           axes[1].set_title('超额收益来源分解')           # 在条形末端添加数值标签           for i, (label, val) in enumerate(zip(labels, sizes)):               axes[1].text(val + (0.001 if val >= 0 else -0.003), i, f'{val:.2%}',                            va='center', ha='left' if val >= 0 else 'right')              # 3. 行业权重对比           x = np.arange(len(self.industries))           width = 0.35           axes[2].bar(x - width / 2, self.benchmark_weights, width, label='基准权重', alpha=0.7)           axes[2].bar(x + width / 2, self.portfolio_weights, width, label='组合权重', alpha=0.7)           axes[2].set_xticks(x)           axes[2].set_xticklabels(self.industries)           axes[2].set_ylabel('权重')           axes[2].set_title('行业权重对比')           axes[2].legend()              plt.tight_layout()           plt.show()      # ==============================   # 3. 模拟数据生成函数（用于演示）   # ==============================   def generate_factor_data(n_periods=252, n_factors=5, seed=42):       """       生成模拟的策略收益率和因子收益率数据       """       np.random.seed(seed)       dates = pd.date_range(start='2020-01-01', periods=n_periods, freq='B')       factor_names = ['MKT', 'SMB', 'HML', 'MOM', 'QMJ']       factor_returns = pd.DataFrame(           np.random.randn(n_periods, n_factors) * 0.01,           index=dates,           columns=factor_names       )       true_beta = np.array([0.8, 0.3, -0.2, 0.5, 0.1])       alpha = 0.0005       specific_return = alpha + np.random.randn(n_periods) * 0.005       portfolio_return = pd.Series(           factor_returns.dot(true_beta) + specific_return,           index=dates,           name='Portfolio'       )       rf = pd.Series(0, index=dates, name='RF')       return portfolio_return, factor_returns, rf         def generate_brinson_data():       """生成模拟的 Brinson 归因数据"""       industries = ['金融', '科技', '医药']       benchmark_weights = pd.Series([0.4, 0.35, 0.25], index=industries)       portfolio_weights = pd.Series([0.3, 0.45, 0.25], index=industries)          # 基准个股数据       benchmark_stocks = pd.DataFrame({           'industry': ['金融'] * 2 + ['科技'] * 3 + ['医药'] * 2,           'stock': ['银行A', '保险B', '硬件C', '软件D', '半导体E', '制药F', '器械G'],           'return': [0.01, 0.02, 0.03, 0.05, 0.02, 0.02, 0.01],           'weight_in_bench': [0.6, 0.4, 0.3, 0.5, 0.2, 0.7, 0.3]       })          # 组合个股数据       portfolio_stocks = pd.DataFrame({           'industry': ['金融', '科技', '科技', '医药', '医药'],           'stock': ['银行A', '硬件C', '半导体E', '制药F', '器械G'],           'return': [0.01, 0.03, 0.02, 0.02, 0.01],           'weight_in_port': [0.3, 0.2, 0.25, 0.15, 0.1]       })       # 确保权重和为一       portfolio_stocks['weight_in_port'] /= portfolio_stocks['weight_in_port'].sum()          return (benchmark_weights, portfolio_weights,               benchmark_stocks, portfolio_stocks)         # ==============================   # 4. 示例调用   # ==============================   if __name__ == "__main__":       # 因子时间序列归因       print("=" * 50)       print("因子时间序列归因")       print("=" * 50)          port_ret, factor_ret, rf = generate_factor_data(n_periods=252 * 2)       fa = FactorAttribution(port_ret, factor_ret, rf)       fa.fit()       fa.summary()       fa.plot_cumulative_decomposition()       fa.plot_factor_contribution()       # 计算滚动暴露热力图（需要足够长的数据）       rolling_beta = fa.rolling_exposure_heatmap(window=60)          # Brinson 归因       print("\n" + "=" * 50)       print("Brinson 归因")       print("=" * 50)          (bench_w, port_w, bench_stocks, port_stocks) = generate_brinson_data()       br = BrinsonAttribution(bench_w, port_w, bench_stocks, port_stocks)       br.run()       br.print_summary()       br.plot_decomposition()   `

## 资本资产定价模型、多因子模型中Alpha的不同理解

总的来讲，资本资产定价模型中的Alpha是在“只剔除市场风险”后剩下的残差；而多因子模型中的Alpha是在“剔除了市场、规模、价值、动量等数十种已知风险”后剩下的残差。

#### **具体来讲：**

### 一、 表达式的形式区别

#### 1\. 资本资产定价模型：单因子结构

-   **其中：**
    

1.   为市场整体预期收益（市场平均收益）
    
2.   为无风险收益
    
3.   资产实际收益
    

-   **风险维度**：仅包含一个风险因子——市场风险溢价。
    
-   **Alpha定义**：在剥离了市场涨跌（）之后，剩余的超额收益。如果模型是“正确”的，Alpha的长期期望值应为0。任何显著非零的Alpha都被视为市场异象或定价错误。
    

#### 2\. 多因子模型

以**法玛-弗伦奇五因子模型**为例：

-   **代码含义：** 同上，自查
    
-   **风险维度**：包含多个风险因子（如市值规模SMB、账面市值比HML、盈利能力RMW、投资模式CMA等）。
    
-   **Alpha定义**：在剥离了市场、规模、价值、盈利、投资等 **所有已知的系统性风险来源**之后，剩余的超额收益。
    

**所以两个相比较来看，因子收益部分属于广义上的资本资产定价模型中的aplha收益。** 但是你也可以将，你的投资组合收益吃的是因子的beta收益，这两者是不矛盾的。

**总结**：资本资产定价模型告诉你“这个人跑赢了大盘”；多因子模型告诉你“这个人跑赢大盘是因为他赌对了小盘风格，还是真的会选股”。**大家通常所说的“寻找Alpha”，指的是在多因子模型剥离了所有已知风险之后，依然存在的那个微小但珍贵的残差项。**

## 本文总结

在做归因分析时，重要的是**理解你的策略到底赚的是什么,源自于哪里？**。本文分析、理论、代码等等角度给出一个适用于**线性模型**的多因子归因分析框架。当然，由于时间仓促代码可能不够完善，后期这部分也会融合到我们自己的项目里，让你一键就能知道自己的策略收益，到底源自于哪里？