# 一种针对&quot;大小盘轮动择时&quot;的有效方法——原理、代码

蝴蝶量化 随率而动的因子工厂 2025-11-24 13:34 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484303&idx=1&sn=3f3bbf091eca68300ddd4d3878d194e2&chksm=c01b34cb264161009d1f202a3b053d3b525f47c3ec54a02000a4abc6a4ee8d156813490a2a8c#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484303&idx=1&sn=3f3bbf091eca68300ddd4d3878d194e2&chksm=c01b34cb264161009d1f202a3b053d3b525f47c3ec54a02000a4abc6a4ee8d156813490a2a8c#rd)

## 使用场景

最近的行情我们发现大盘股的收益有所转强，相较之下，最近小盘股的收益有所转弱。纵观整个a股在过去30年里，小盘股的超额收益远超过大盘股，但是也存在很明显的大小盘轮动，尤其是近年来大小盘轮动更加明显：2019年、2024年、2025年都有大小盘轮动的现象。

那么，对于量化人来讲：**如何在策略上做到适配大小盘风格轮动？** 就成了一个必须仔细研究的问题。

之前的文章，我们介绍一些**小市值策略**、**ETF轮动策略**等策略逻辑，这些其实就是蕴含着大小盘分格的策略。显而易见，如果小盘风格收益突出，就应该增加小市值策略的仓位配置，反之应该增加ETF策略的仓位配置。

**那么，是否有一套用来判断最近大盘风格的逻辑呢？** 答案是肯定的，本期文章，从基本面因子出发，介绍了一种**大小盘切换的择时逻辑。** 主要方法源自东方证券的一篇研报，需要的可以后台sx。

**本期算法，个人观点可以用在仓位管理部分，说到底这还是一个“因子择时”问题。**

## 理论验证与数据分析

### ： 小市值溢价的显著性与高波动性

-   **长期收益显著**：在A股历史长河中，做多市值最小20%股票、做空市值最大20%股票的多空组合，**平均每月能获得1.1%的超额收益**。从月份看，小盘股跑赢大盘股的概率接近60%。
    
-   **但波动巨大**：这个多空组合的年化波动率高达\*\*21%\*\*，与美国股市整体波动率相当，远高于其他Alpha因子（如价值、质量等）。这意味着：
    

-   **高风险**：如果在小盘股表现糟糕的年份（如2017年，月均溢价为-3.1%）暴露了小盘风险，会遭受巨大损失。2024.1、2月份，月亏损超-15%
    
-   **高机会**：如果能准确预测风格切换，获得的收益可能远超单纯的选股收益。
    

## 如何做：方法简介

1.  **经典“伪回归”问题** ：拿一个股票的价格对另一个股票的价格做回归，我们随机模拟生成了两个相关性为零的股票收益率序列，如果把两个收益率画成散点图，
    

![](assets/001.png)

显然图像上看不到两者任何相关性；但如果把两个收益率序列分别累积计算得到两个股票的净值数据序列再做散点图：

![](assets/002.png)

图形上可以看到这两者之间存在明显的负相关性；如果用 OLS 方法对 两者回归，会发现回归系数十分显著，回归方程的 Rsquared 有 51%，统计分析结果显示了一个不存在的事实。造成这种现象的原因主要是因为股票的净值序列是一个非平稳的随机游走过程，如果检验回归方程的残差，会发现残差序列也是非平稳的随机游走过程，方差趋于无穷大，和标准OLS 模型里残差平稳假设相悖，此时 OLS 方法得到估计量并非一致估计量，即使样本数量再多也 不会收敛于真实模型参数。这个例子并不是说任何两个随机游走过程都会有显著相关性，而是说有显著相关性的两个随机游走过程可能事实上不存在任何逻辑关联。**注意：这样的预测在宏观基本面预测中容易出现。**

2.  方法一：**IVX预测回归模型（解决“伪回归”问题）Kostakis(2015)**
    

-   **问题**：许多宏观数据（如PPI同比）具有强“持续性”（类似于随机游走），用传统OLS回归会导致系数估计偏差和统计检验失真，即“伪回归”——可能得出两个本不相关的变量存在显著关系的错误结论。
    
-   **解决方案**：IVX方法通过构建一个特殊的工具变量，有效处理了持续性和内生性问题，使得回归结果和统计检验更加可靠。
    

4.  方法二：**DLM动态线性模型（捕捉“动态变化”的关系）**
    

-   **问题**：宏观变量与股市风格的关系不是一成不变的。例如，PPI对风格的影响在2013年前后强度不同。OLS假设这种关系是静态的。
    
-   **解决方案**：DLM模型将回归系数视为一个“隐藏状态”，允许它随时间变化。通过状态空间模型和卡尔曼滤波来估计每一时刻的动态系数，从而更精细地刻画变量间关系的演变。让 β “动”起来的常用方法有两类，一类是从β 的 OLS 估计算式出发：，等式右边的分子和分母基于整个样本区间数据计算，是常数。我们可以借鉴 GARCH 模型的思想， 计算条件期望值cov(Y, X | ℱ𝑡) 和 var(X |ℱ𝑡)。这里可采用随机波动率模型（SV, Stochastic Volatility），也可采用高维 GARCH 模型，常用的形式包括 BEKK、DCC-GARCH、CCC-GARCH 等（详细内容可参考 Mergner(2009)）。
    

6.  **3PRF三阶段回归滤波（“降维”合成指标）**
    

-   **问题**：单个指标噪音大，而同类型指标（如各种通胀分项数据）又存在共线性。直接放入模型会干扰预测。
    
-   **解决方案**：3PRF是一种先进的降维技术，类似于主成分分析（PCA），但它更专注于寻找与预测目标协方差最大的组合。报告用它把多个细分指标合成了**经济增长、资金面、通胀、市场情绪**四大类综合指标，提升了模型的稳健性和样本外预测能力。
    

## 具体算法与python实现

**代码仅供参考！！！**

### 1、 IVX方法的理论基础与实现

`class IVXRegression:       """       IVX（工具变量回归）完整实现       基于Kostakis, Magdalinos & Stamatogiannis (2015)       """              def __init__(self, c=1, delta=0.95):           """           参数:           c: 工具变量构造参数，通常设为1           delta: 介于0.5和1之间，控制工具变量的持续性           """           self.c = c           self.delta = delta                  def _construct_instruments(self, X):           """           构造工具变量Z_t           Z_t = (1 - c/T^δ) * Z_{t-1} + (X_t - X_{t-1})           """           T = len(X)           Z = np.zeros_like(X)                      for t in range(1, T):               rho_T = 1 - self.c / (T ** self.delta)               Z[t] = rho_T * Z[t-1] + (X[t] - X[t-1])                          return Z              def fit(self, Y, X, add_constant=True):           """           IVX回归估计                      参数:           Y: 因变量 (n,)           X: 自变量 (n, k)，如果有多个变量           add_constant: 是否添加常数项           """           Y = np.array(Y)           X = np.array(X)                      if X.ndim == 1:               X = X.reshape(-1, 1)                          n, k = X.shape                      if add_constant:               X = np.column_stack([np.ones(n), X])               k += 1                          # 为每个变量构造工具变量           Z = np.zeros_like(X)           for i in range(k):               if i == 0 and add_constant:  # 常数项的工具变量                   Z[:, 0] = 1               else:                   col_idx = i if not add_constant else i-1                   Z[:, i] = self._construct_instruments(X[:, i])                      # IVX估计量: β_ivx = (Z'X)^(-1)Z'Y           try:               beta = np.linalg.inv(Z.T @ X) @ Z.T @ Y           except np.linalg.LinAlgError:               # 如果矩阵奇异，使用伪逆               beta = np.linalg.pinv(Z.T @ X) @ Z.T @ Y                          # 计算标准误和t统计量           residuals = Y - X @ beta           sigma2 = np.var(residuals)           cov_matrix = sigma2 * np.linalg.inv(Z.T @ X)           se = np.sqrt(np.diag(cov_matrix))           t_stats = beta / se                      results = {               'coefficients': beta,               'standard_errors': se,               't_statistics': t_stats,               'residuals': residuals,               'instrument_matrix': Z           }                      return results              def compare_with_ols(self, Y, X):           """           比较IVX和OLS的结果差异           """           # IVX估计           ivx_results = self.fit(Y, X)                      # OLS估计（有偏）           X_with_const = sm.add_constant(X)           ols_model = sm.OLS(Y, X_with_const).fit()                      comparison = pd.DataFrame({               'IVX_Coeff': ivx_results['coefficients'],               'IVX_tStat': ivx_results['t_statistics'],               'OLS_Coeff': ols_model.params,               'OLS_tStat': ols_model.tvalues,               'Bias': ols_model.params - ivx_results['coefficients']           })                      return comparison      def demonstrate_persistence_problem():       """       展示持续性问题的严重性       """       np.random.seed(42)       T = 500              # 生成具有强持续性的变量       X = np.cumsum(np.random.randn(T))  # 随机游走，ρ≈1              # 生成与X相关的误差项（内生性）       u = 0.3 * np.random.randn(T) + 0.1 * X[:-1]  # 内生性误差              # 真实关系：Y_t = 0.5 * X_{t-1} + u_t       Y = 0.5 * X[:-1] + u[1:]              ivx = IVXRegression()       comparison = ivx.compare_with_ols(Y, X[:-1])              print("持续性问题和内生性导致的估计偏差：")       print(comparison)              # 检验变量的持续性       from statsmodels.tsa.stattools import adfuller       adf_result = adfuller(X)       print(f"ADF检验p值: {adf_result[1]:.4f}")  # p值大说明非平稳   `

### 2 动态线性模型（DLM）的深入应用

**DLM的经济学意义：**

-   捕捉经济变量关系的时变性
    
-   反映市场结构变化和投资者行为演变
    
-   适应政策环境和经济周期的变化
    

`class AdvancedDLM:       """       高级动态线性模型实现       包含多种状态空间模型设定       """              def __init__(self, model_type='local_level'):           """           支持多种DLM模型:           - 'local_level': 局部水平模型           - 'local_trend': 局部趋势模型             - 'time_varying': 时变系数模型           """           self.model_type = model_type                  def fit_time_varying_coefficients(self, Y, X, optimization_method='em'):           """           时变系数模型的完整实现           """           n_obs = len(Y)                      if self.model_type == 'time_varying':               # 时变系数模型设定               # 观测方程: Y_t = β_t * X_t + ε_t               # 状态方程: β_t = β_{t-1} + η_t                              # 使用卡尔曼滤波               from pykalman import KalmanFilter                              # 构建观测矩阵（时变）               def observation_matrix(t):                   return np.array([X[t]])                              kf = KalmanFilter(                   transition_matrices=[1],                   observation_matrices=observation_matrix,                   initial_state_mean=0,                   initial_state_covariance=1,                   observation_covariance=1,                   transition_covariance=0.1  # 需要估计               )                          elif self.model_type == 'local_trend':               # 局部趋势模型               # 状态向量: [水平, 趋势]               pass                          # 参数估计           if optimization_method == 'em':               kf = kf.em(Y, n_iter=20)           elif optimization_method == 'mle':               # 最大似然估计               pass                          # 状态估计           state_means, state_covariances = kf.filter(Y)           smoothed_means, smoothed_covs = kf.smooth(Y)                      results = {               'filtered_states': state_means,               'smoothed_states': smoothed_means,               'model': kf,               'log_likelihood': kf.loglikelihood(Y)           }                      return results              def analyze_structural_breaks(self, dynamic_betas, confidence_level=0.95):           """           检测结构断点 - 基于时变系数           """           from changepoint import rpt  # 需要安装changepoint库                      # 使用多种方法检测结构变化           methods = {               'CUSUM': '累计和检验',               'Bai-Perron': '多重断点检验',               'Chow': '邹检验'           }                      breakpoints = {}                      # 简单的滚动窗口方差检验           window_size = 36  # 3年窗口           volatility_changes = []                      for i in range(window_size, len(dynamic_betas)):               window_var = np.var(dynamic_betas[i-window_size:i])               prev_window_var = np.var(dynamic_betas[i-2*window_size:i-window_size])                              # F检验方差变化               f_stat = window_var / prev_window_var if prev_window_var > 0 else 1               p_value = stats.f.cdf(f_stat, window_size-1, window_size-1)                              if p_value < 1-confidence_level or p_value > confidence_level:                   volatility_changes.append(i)                      breakpoints['volatility_changes'] = volatility_changes           return breakpoints      def dlm_economic_interpretation():       """       DLM结果的经济学解释框架       """       interpretation_framework = {           '系数符号变化': {               '正向转负向': '可能预示风格切换',               '负向转正向': '可能预示趋势反转',               '持续正向': '稳定的预测关系',               '持续负向': '稳定的负向关系'           },           '系数大小变化': {               '绝对值增大': '变量影响力增强',               '绝对值减小': '变量影响力减弱',               '剧烈波动': '市场不确定性高'           },           '结构性断点': {               '政策变化': '货币政策、监管政策调整',               '经济周期转折': '繁荣到衰退或反之',               '市场制度变革': '交易机制、发行制度变化'           }       }       return interpretation_framework   `

### 3\. 三阶段回归滤波（3PRF）的完整实现

**3PRF方法优势：**

-   优于主成分分析（PCA）：专注于预测能力而非方差解释
    
-   处理变量共线性问题
    
-   提高样本外预测能力
    

`class ThreePassRegressionFilter:       """       三阶段回归滤波完整实现       基于Kelly & Pruitt (2015)       """              def __init__(self, n_factors=1, proxy_method='auto'):           self.n_factors = n_factors           self.proxy_method = proxy_method                  def _select_proxy_variable(self, Y, X):           """           选择代理变量的策略           """           if self.proxy_method == 'auto':               # 自动选择：使用Y的滞后项或主要成分               if len(Y) > 12:                   proxy = np.mean(X, axis=1)  # 变量均值作为代理               else:                   proxy = np.roll(Y, 1)  # 使用Y的滞后项                   proxy[0] = np.mean(Y)           elif self.proxy_method == 'target_lag':               proxy = np.roll(Y, 1)               proxy[0] = np.mean(Y)           elif self.proxy_method == 'pca_first':               from sklearn.decomposition import PCA               pca = PCA(n_components=1)               proxy = pca.fit_transform(X).flatten()                          return proxy              def fit(self, Y, X):           """           三阶段回归滤波           """           T, N = X.shape           proxy = self._select_proxy_variable(Y, X)                      # 第一阶段：每个预测变量对代理变量回归           loadings_stage1 = np.zeros(N)           for i in range(N):               model = sm.OLS(X[:, i], sm.add_constant(proxy)).fit()               loadings_stage1[i] = model.params[1]  # 斜率系数                      # 第二阶段：目标变量对代理变量回归           model_stage2 = sm.OLS(Y, sm.add_constant(proxy)).fit()           gamma = model_stage2.params[1]                      # 第三阶段：构建因子           F_hat = X @ loadings_stage1 * gamma                      # 可选：多因子扩展           if self.n_factors > 1:               # 使用迭代方法提取多个因子               factors = self._extract_multiple_factors(Y, X, F_hat)           else:               factors = F_hat.reshape(-1, 1)                      results = {               'factors': factors,               'loadings_stage1': loadings_stage1,               'gamma_stage2': gamma,               'proxy_variable': proxy,               'r_squared': model_stage2.rsquared           }                      return results              def _extract_multiple_factors(self, Y, X, first_factor):           """           提取多个因子（扩展功能）           """           factors = [first_factor]           residuals = Y - first_factor                      for i in range(1, self.n_factors):               # 在残差上继续提取因子               proxy_residual = self._select_proxy_variable(residuals, X)                              loadings_residual = np.zeros(X.shape[1])               for j in range(X.shape[1]):                   model = sm.OLS(X[:, j], sm.add_constant(proxy_residual)).fit()                   loadings_residual[j] = model.params[1]                              model_factor = sm.OLS(residuals, sm.add_constant(proxy_residual)).fit()               gamma_residual = model_factor.params[1]                              next_factor = X @ loadings_residual * gamma_residual               factors.append(next_factor)                              # 更新残差               residuals = residuals - next_factor                          return np.column_stack(factors)              def economic_interpretation(self, factors, variable_names):           """           对3PRF因子进行经济学解释           """           factor_loadings = self.loadings_stage1                      # 分析因子构成           factor_composition = pd.DataFrame({               'variable': variable_names,               'loading': factor_loadings,               'abs_loading': np.abs(factor_loadings),               'direction': np.sign(factor_loadings)           }).sort_values('abs_loading', ascending=False)                      # 因子标签推断           top_variables = factor_composition.head(5)                      if all('CPI' in var or 'PPI' in var for var in top_variables['variable']):               factor_label = '通胀因子'           elif any('GDP' in var or '工业' in var for var in top_variables['variable']):               factor_label = '增长因子'           elif any('M2' in var or '利率' in var for var in top_variables['variable']):               factor_label = '流动性因子'           else:               factor_label = '综合因子'                          interpretation = {               'factor_label': factor_label,               'main_drivers': top_variables['variable'].tolist(),               'factor_direction': '正向' if np.mean(factors) > 0 else '负向',               'stability': np.std(factors) / np.mean(np.abs(factors))  # 变异系数           }                      return interpretation   `

## 总结

本文主要介绍了一种可以用于分析：大小盘轮动的具体算法，文中提到了三种方法，IVX、DLM、3PRF方法，具体算法源自于证券研报，希望能够给您在**风格轮动**方面有所帮助。