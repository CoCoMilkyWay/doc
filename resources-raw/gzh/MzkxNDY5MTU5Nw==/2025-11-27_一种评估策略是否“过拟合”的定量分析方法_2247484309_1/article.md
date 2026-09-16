# 一种评估策略是否“过拟合”的定量分析方法——CSCV框架、步骤、代码

蝴蝶量化 随率而动的因子工厂 2025-11-27 16:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484309&idx=1&sn=33755d6c2d1ef81a6c2d871251bd94cd&chksm=c09b1b5eb563ae49f489e4481aeabe17d9f778ccb9bceacabd06c933b89c6762ea82a261f3ef#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484309&idx=1&sn=33755d6c2d1ef81a6c2d871251bd94cd&chksm=c09b1b5eb563ae49f489e4481aeabe17d9f778ccb9bceacabd06c933b89c6762ea82a261f3ef#rd)

## 技术背景

很多刚接触量化策略的小伙伴，肯定都有这样的困惑：为什么回测时策略回撤小、收益大感觉可以买地球，但是实际交易过程中，却大相径庭？如下图

![](assets/001.png)

究其原因，其实就是 **“参数”** 在作怪，回测时，我们总是希望能够挑选出 **“最优秀”** 的参数，在测试集中表现极为优秀，但是往往收益、夏普最高的并不一定是最好的。这里有很多的关键点需要考究：**参数孤岛（敏感性）、参数稳定（过拟合）等等。**

在之前的文章《[如何防止策略过拟合](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247483788&idx=1&sn=98b16c397f954d580d025064017b576f&scene=21#wechat_redirect)》中，我们给出了一些定性的分析方法，告诉大家如何在一堆参数中选择合适的参数？，如何做样本内、样本外测试？但是这需要一个很大的工作量，作为一量化人，肯定希望能够有一个定量分析的方法，能够很清楚的给出策略是否存在过拟合，后者过拟合的概率是多少？

  

本文从**“CSCV”** （ Combinatorially-Symmetric Cross-Validation：组合对称交叉验证）框架出发，介绍了一种可行的方案、实现步骤、python代码等等。

## CSCV框架介绍

### 过拟合概率（PBO）

采用过拟合概率来度量策略过拟合的程度，采用夏普比率作为评价策略好坏的标准指标，具体定义公式：

其中：

-   \*\*  \*\* :代表第n组参数在样本外的夏普比率。
    
-   \*\*  \*\* : 代表所有N组参数在样本外的**夏普比率中位数**。
    
-   \*\* Prob()\*\* : 为概率计算公式。
    
-   含义：样本内最优的参数n，在样本外的夏普比率小于**所有参数**在样本外夏普比率中位数的概率。
    

也就是这里需要很多的份的样本内、样本外的数据，然后考虑每一个样本内的最优参数的夏普是否在配对样本外所有参数的中位数前。

### CSCV框架

#### 简介：是什么？

**CSCV**的全称是 Combinatorial Symmetric Cross-Validation，即：组合对称交叉验证。是一种先进的、专门为金融策略回测设计的统计方法。其核心目的是更科学地评估一个量化策略的性能，并计算其“过拟合概率”。

**从而回答一个关键问题：“我所看到的优秀回测结果，到底是源于策略的真实预测能力，还是仅仅是运气好（即过拟合）？**

#### 优势：为什么做？

-   **数据窥探/过拟合**：研究者会在一段历史数据上反复测试和修改策略，直到找到表现最好的一个。这个过程会无意中将策略“拟合”到历史数据中的噪音上，导致策略在未来实盘时表现糟糕。
    
-   **性能评估失真**：传统的做法是将数据简单分为“训练集”和“测试集”。但在金融时间序列中，数据有强烈的自相关性和结构性变化（如牛市、熊市），简单的分割可能导致评估结果不稳健。例如，策略可能只是幸运地“躲过”了测试集中的一次大跌。
    
-   **低估了偶然性**：即使一个策略完全随机生成，如果在足够多的策略中进行测试，也总能找到一些在历史数据上表现“惊人”的策略。传统方法很难量化这种“偶然成功”的概率。
    

#### 步骤：怎么做？

CSCV框架，它不直接将数据分为训练集和测试集，而是通过一种组合数学的方法，对所有可能的数据划分情况进行综合评估。 其工作流程可以概括为以下几步：

-   **步骤 1：数据分割**
    
    将长度为 T 的整个价格序列（或收益率序列）均匀地分割成 S 个区间。例如，如果有 1000 个交易日，S=10，那么每个区间包含 100 个交易日。
    
-   **步骤 2：组合生成**
    
    这 S 个区间中，任意一半（S/2）的组合可以构成一个“训练集”，而剩下的一半则自然构成对应的“测试集”。所有可能的组合方式共有 C(S, S/2)种（组合数），这是一个非常大的数字。例如，S=10时，有 252 种组合方式。
    
-   **步骤 3：对称交叉验证**
    
    对于每一种组合方式：
    
    1、 将选中的 S/2 个区间拼接起来，作为“训练集”。
    
    2、用这个训练集的数据来优化策略参数，找到在“训练集”上表现最优的参数组合。
    
    3、然后，立即将找到的最优参数应用到对应的“测试集”（另外 S/2 个区间） 上，计算出策略在测试集上的性能指标（如夏普比率）。
    
-   **步骤 4：性能矩阵构建**
    
    经过以上步骤，我们会得到一个庞大的“性能矩阵”。这个矩阵的行是每一种组合方式，列是策略在不同数据划分下的表现（训练集表现 vs 测试集表现）。
    
-   **步骤 5：计算过拟合概率**
    
    1、**观察最优策略**：从所有在“训练集”上表现最好的策略中，选出那个在“全体历史数据”上表现最好的策略。
    
    2、**排序比较**：我们将策略在“测试集”上的表现（来自步骤3），与所有其他策略在“测试集”上的表现放在一起，进行排序。
    
    3、**计算概率**：过拟合概率（PBO）就定义为策略的测试集表现在这个排序中的分位数。
    
    4、**结果解释**： 具体来说：如策略的测试集表现排名非常靠后，说明它在“未知数据”上表现很差，那么 PBO 就很高（接近1），意味着它极有可能是过拟合的。如果策略的测试集表现排名依然靠前，说明它的性能比较稳健，那么 PBO 就很低（接近0），过拟合的可能性小。
    

**一般来讲，我们以0.3~0.5作为一个关键阈值，**

-   PBO < 0.3：过拟合风险较低
    
-   0.3 ≤ PBO < 0.5：中等风险
    
-   PBO ≥ 0.5：高过拟合风险
    

## Python实现代码

**注意python代码仅供参考**

`import numpy as np   import pandas as pd   from itertools import combinations   import warnings   warnings.filterwarnings('ignore')      class CSCVPBO:       """       基于CSCV框架的回测过拟合概率计算器       """              def __init__(self, returns_matrix, S=16):           """           初始化                      Parameters:           returns_matrix: numpy array, T×N矩阵，T个时间点，N个策略的收益率           S: int, 将时间序列划分的段数，必须为偶数           """           self.returns = returns_matrix           self.T, self.N = returns_matrix.shape           self.S = S                      # 验证参数           if self.T % self.S != 0:               raise ValueError(f"时间长度T={self.T}必须能被S={self.S}整除")                      if self.S % 2 != 0:               raise ValueError(f"S={self.S}必须为偶数")                      self.segment_length = self.T // self.S              def calculate_sharpe_ratio(self, returns, risk_free=0.0):           """           计算夏普比率                      Parameters:           returns: 收益率数据           risk_free: 无风险利率，默认为0                      Returns:           sharpe_ratio: 年化夏普比率           """           excess_returns = returns - risk_free           sharpe = np.mean(excess_returns) / np.std(excess_returns) * np.sqrt(12)  # 年化           return sharpe              def calculate_information_ratio(self, strategy_returns, benchmark_returns):           """           计算信息比率（用于指数增强策略）                      Parameters:           strategy_returns: 策略收益率           benchmark_returns: 基准收益率                      Returns:           information_ratio: 信息比率           """           active_returns = strategy_returns - benchmark_returns           ir = np.mean(active_returns) / np.std(active_returns) * np.sqrt(12)           return ir              def split_time_series(self):           """           将时间序列划分为S个等长子区间           """           segments = []           for i in range(self.S):               start_idx = i * self.segment_length               end_idx = (i + 1) * self.segment_length               segment = self.returns[start_idx:end_idx, :]               segments.append(segment)           return segments              def calculate_pbo(self, metric='sharpe', benchmark_returns=None):           """           计算回测过拟合概率(PBO)                      Parameters:           metric: 评价指标，'sharpe'或'information_ratio'           benchmark_returns: 基准收益率（当metric='information_ratio'时需要）                      Returns:           pbo: 回测过拟合概率           omega_distribution: 相对排名分布           """           # 划分时间序列           segments = self.split_time_series()           segment_indices = list(range(self.S))                      # 生成所有组合           all_combinations = list(combinations(segment_indices, self.S // 2))           total_combinations = len(all_combinations)                      print(f"总组合数: {total_combinations}")                      omega_values = []                      for i, train_indices in enumerate(all_combinations):               if (i + 1) % 1000 == 0:                   print(f"处理进度: {i+1}/{total_combinations}")                              # 构建训练集和测试集               train_segments = [segments[idx] for idx in train_indices]               test_indices = [idx for idx in segment_indices if idx not in train_indices]               test_segments = [segments[idx] for idx in test_indices]                              train_returns = np.vstack(train_segments)               test_returns = np.vstack(test_segments)                              # 计算训练集各策略表现               train_scores = []               for j in range(self.N):                   if metric == 'sharpe':                       score = self.calculate_sharpe_ratio(train_returns[:, j])                   elif metric == 'information_ratio' and benchmark_returns is not None:                       # 需要确保benchmark_returns也相应划分                       train_benchmark = self._get_corresponding_benchmark(benchmark_returns, train_indices)                       score = self.calculate_information_ratio(train_returns[:, j], train_benchmark)                   else:                       raise ValueError("不支持的metric类型")                   train_scores.append(score)                              # 找到训练集最优策略               best_strategy_idx = np.argmax(train_scores)                              # 计算测试集各策略表现               test_scores = []               for j in range(self.N):                   if metric == 'sharpe':                       score = self.calculate_sharpe_ratio(test_returns[:, j])                   elif metric == 'information_ratio' and benchmark_returns is not None:                       test_benchmark = self._get_corresponding_benchmark(benchmark_returns, test_indices)                       score = self.calculate_information_ratio(test_returns[:, j], test_benchmark)                   test_scores.append(score)                              # 计算最优策略在测试集的相对排名               test_rank = self._calculate_relative_rank(test_scores, best_strategy_idx)               omega_values.append(test_rank)                      # 计算PBO           pbo = np.mean([1 if omega > 0.5 else 0 for omega in omega_values])                      return pbo, omega_values              def _get_corresponding_benchmark(self, benchmark_returns, segment_indices):           """获取对应时间段的基准收益率"""           corresponding_returns = []           for idx in segment_indices:               start_idx = idx * self.segment_length               end_idx = (idx + 1) * self.segment_length               corresponding_returns.extend(benchmark_returns[start_idx:end_idx])           return np.array(corresponding_returns)              def _calculate_relative_rank(self, scores, target_idx):           """计算相对排名"""           sorted_indices = np.argsort(scores)[::-1]  # 降序排列           rank = np.where(sorted_indices == target_idx)[0][0] + 1  # 从1开始排名           relative_rank = rank / (len(scores) + 1)           return relative_rank              def analyze_sensitivity(self, S_values, metric='sharpe'):           """           分析不同S值对PBO的影响                      Parameters:           S_values: 不同的S值列表           metric: 评价指标                      Returns:           sensitivity_results: 敏感性分析结果           """           results = {}                      for S in S_values:               if self.T % S != 0 or S % 2 != 0:                   print(f"跳过S={S}（不满足整除或偶数条件）")                   continue                                  print(f"\n分析S={S}...")               self.S = S               pbo, omega_dist = self.calculate_pbo(metric=metric)               results[S] = {                   'pbo': pbo,                   'omega_mean': np.mean(omega_dist),                   'omega_std': np.std(omega_dist),                   'combinations': len(list(combinations(list(range(S)), S//2)))               }                      return results      # 三、实际应用示例      def case_study_1():       """案例1：7种机器学习选股策略的PBO分析"""       print("=== 案例1：机器学习选股策略PBO分析 ===")              # 模拟生成7种策略的96个月度收益率（实际应用中应使用真实回测数据）       np.random.seed(42)       T, N = 96, 7  # 96个月，7种策略              # 生成基准收益率（模拟市场）       market_returns = np.random.normal(0.008, 0.05, T)  # 月均0.8%，波动5%              # 生成7种策略收益率（基于市场收益率加上不同的alpha和噪声）       strategies_returns = []       alphas = [0.002, 0.003, 0.005, 0.008, 0.004, 0.006, 0.007]  # 不同的alpha       noises = [0.02, 0.025, 0.03, 0.035, 0.028, 0.032, 0.029]  # 不同的噪声水平              for i in range(N):           strategy_return = market_returns + np.random.normal(alphas[i], noises[i], T)           strategies_returns.append(strategy_return)              returns_matrix = np.column_stack(strategies_returns)              # 计算PBO       cscv = CSCVPBO(returns_matrix, S=16)              # 多空组合夏普比率PBO       pbo_sharpe, omega_sharpe = cscv.calculate_pbo(metric='sharpe')       print(f"多空组合夏普比率PBO: {pbo_sharpe:.3f}")              # 指数增强组合信息比率PBO       pbo_ir, omega_ir = cscv.calculate_pbo(metric='information_ratio',                                             benchmark_returns=market_returns)       print(f"指数增强组合信息比率PBO: {pbo_ir:.3f}")              return pbo_sharpe, pbo_ir      def case_study_3():       """案例3：择时策略参数优化的PBO分析"""       print("\n=== 案例3：择时策略参数优化PBO分析 ===")              # 模拟择时策略收益率（7组参数）       np.random.seed(123)       T, N = 168, 7  # 168个月，7组参数              # 生成择时策略收益率（假设效果差异较大）       strategies_returns = []       # 模拟不同参数的择时效果       base_returns = np.random.normal(0.006, 0.06, T)  # 基准收益率              for i in range(N):           # 模拟不同参数的择时能力           timing_ability = 0.1 + i * 0.05  # 参数效果递增           noise_level = 0.04 - i * 0.005   # 更好的参数噪声更小                      strategy_return = base_returns + np.random.normal(timing_ability, noise_level, T)           strategies_returns.append(strategy_return)              returns_matrix = np.column_stack(strategies_returns)              # 分析不同S值的影响       cscv = CSCVPBO(returns_matrix, S=12)              S_values = [12, 14, 21, 28, 42]       sensitivity_results = cscv.analyze_sensitivity(S_values)              print("\n敏感性分析结果:")       for S, result in sensitivity_results.items():           print(f"S={S}: PBO={result['pbo']:.3f}, 组合数={result['combinations']}")              return sensitivity_results      def advanced_analysis():       """高级分析：PBO结果的统计显著性检验"""       print("\n=== 高级分析：统计显著性检验 ===")              # 使用案例1的数据       np.random.seed(42)       T, N = 96, 7       market_returns = np.random.normal(0.008, 0.05, T)              strategies_returns = []       alphas = [0.002, 0.003, 0.005, 0.008, 0.004, 0.006, 0.007]              for i in range(N):           strategy_return = market_returns + np.random.normal(alphas[i], 0.03, T)           strategies_returns.append(strategy_return)              returns_matrix = np.column_stack(strategies_returns)              # 多次计算PBO评估稳定性       pbo_values = []       for _ in range(10):  # 重复10次           # 添加微小扰动模拟不同随机种子           perturbed_returns = returns_matrix + np.random.normal(0, 0.001, returns_matrix.shape)           cscv = CSCVPBO(perturbed_returns, S=16)           pbo, _ = cscv.calculate_pbo()           pbo_values.append(pbo)              print(f"PBO均值: {np.mean(pbo_values):.3f}")       print(f"PBO标准差: {np.std(pbo_values):.3f}")       print(f"PBO范围: [{np.min(pbo_values):.3f}, {np.max(pbo_values):.3f}]")              # 统计显著性检验       from scipy import stats       t_stat, p_value = stats.ttest_1samp(pbo_values, 0.5)  # 检验是否显著不等于0.5       print(f"t统计量: {t_stat:.3f}, p值: {p_value:.3f}")              if p_value < 0.05:           print("PBO显著不等于0.5，策略可能有过拟合风险")       else:           print("PBO与0.5无显著差异")      # 四、结果可视化      def visualize_results(pbo_values, omega_distribution, strategy_names=None):       """可视化PBO分析结果"""       import matplotlib.pyplot as plt       import seaborn as sns              plt.figure(figsize=(15, 5))              # 1. PBO值比较       plt.subplot(131)       if strategy_names is None:           strategy_names = [f'策略{i+1}' for i in range(len(pbo_values))]              plt.bar(strategy_names, pbo_values)       plt.axhline(y=0.5, color='r', linestyle='--', label='过拟合阈值(0.5)')       plt.title('各策略PBO比较')       plt.xticks(rotation=45)       plt.legend()              # 2. 相对排名分布       plt.subplot(132)       if isinstance(omega_distribution, list) and len(omega_distribution) > 0:           if isinstance(omega_distribution[0], list):               # 多个策略的分布               for i, omega_dist in enumerate(omega_distribution):                   sns.kdeplot(omega_dist, label=f'策略{i+1}')           else:               # 单个策略的分布               sns.histplot(omega_distribution, bins=20)           plt.axvline(x=0.5, color='r', linestyle='--', label='过拟合阈值')           plt.title('相对排名ω分布')           plt.legend()              # 3. PBO与S值关系       plt.subplot(133)       # 这里可以添加敏感性分析结果的可视化       plt.title('PBO对S值的敏感性')              plt.tight_layout()       plt.show()      # 执行示例   if __name__ == "__main__":       # 运行案例研究       pbo1_sharpe, pbo1_ir = case_study_1()       sensitivity_results = case_study_3()       advanced_analysis()              # 可视化结果       pbo_values = [pbo1_sharpe, pbo1_ir, 0.35, 0.65]  # 示例数据       visualize_results(pbo_values, [])   `

## 总结

本文以CSCV框架为基础，计算了PBO概率作为评价策略是否会过拟合的一种定量的分析方法。

很好的解决了策略**过拟合、幸存者偏差**的问题，当然这不是新技术，却是每一个量化人必须懂得技术。