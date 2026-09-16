# 因子合成另类算法：因子值打分算法详解

蝴蝶量化 随率而动的因子工厂 2025-09-26 14:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484190&idx=1&sn=81d37b8d65ee9fd749ce4f059320132e&chksm=c003c6f9da18301e258e029352e5810564212698429a1643ab2c7360ce22ffd5148a4b9048b4#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484190&idx=1&sn=81d37b8d65ee9fd749ce4f059320132e&chksm=c003c6f9da18301e258e029352e5810564212698429a1643ab2c7360ce22ffd5148a4b9048b4#rd)

之前介绍了很多的因子合成方法：等权、IC加权、半衰期IC加权、IC\_IR加权、最优ICIR方法、机器学习分类等等。

在我们的项目中大部分策略中使用了最优ICIR方法，相比较其他方法最后化ICIR方法能够获得更高的IR，历史表现更加稳定。

在实战中我们发现，有些时候我们只需要关心前10%～20%的多头组标的，后20%～10%的空头组标的，而对于中间的标的得分情况其实我们并不关心。，并且我们认为在用一个分组中的股票不寻在很明显的收益差异，所以在相同分组中的股票因子值应该相同，那么就衍生出今天的算法：在因子合成的中间增加一个函数：

1、如果原始分组在多头组，加权因子值为：1。

2、如果原始分组在空投组，加权因子值为：-1。

3、其他组，加权因子值为：0。

## 具体合成算法详解

### 步骤一：计算因子值

通过python计算相应的因子值：基本面因子、估值因子、成长因子、动量因子等等

### 步骤二：因子预处理

因子预处理包括：去极值化、行业中性化、市值中性化、标准化、正交化等等

### 步骤三：因子加权

采用原始因子的最优ICIR方法，确定各因子的权重。

#### 步骤四：个股打分

1、**打分规则**：

-   如果因子值处于同行业股票的前20%，则得分 为：1。
    
-   如果因子值处于后20%，则得分 -1。
    
-   处于中间60%的，得分为 0。
    

**优点**： 这种方法将连续的因子值离散化，增强了模型的鲁棒性，避免受极端值过度影响。

2、  **计算综合阿尔法得分（核心公式）**： 将个股在所有因子上的得分进行加权求和。

  

-   s： 某一只股票。
    
-   K： 因子大类的总数。
    
-   N(k)： 第k个大类中包含的因子数量。
    
-   w(n, k)： 因子n的权重（来自步骤三）。
    
-   V(s, n, k)： 股票s在因子n上的得分（+1, 0, -1）。
    
-   α(s)： 股票s的最终阿尔法得分。
    

## 代码实现

`# ===== 第一部分：模型训练（定期进行，例如每季度或每半年） =====   # 输入：历史价格数据、历史因子数据   # 输出：有效因子列表、每个因子的权重 w(n, k)      def train_alpha_model(historical_data):       # 1. 计算历史各期的因子收益       all_factors = [‘factor_A', ‘factor_B', ...] # 所有候选因子       factor_returns_ts = [] # 存储每个因子历史各期的收益差（最好组-最差组）              for factor in all_factors:           monthly_returns = []           for month in historical_months:               # 对当月所有股票按该因子值排序               sorted_stocks = sort_stocks_by_factor(month, factor)               # 取前20%和后20%               top_20 = sorted_stocks[:len(sorted_stocks)//5]               bottom_20 = sorted_stocks[-len(sorted_stocks)//5:]               # 计算下个月这两组的平均收益差               return_top = calculate_next_month_return(top_20)               return_bottom = calculate_next_month_return(bottom_20)               factor_return = return_top - return_bottom               monthly_returns.append(factor_return)                      factor_returns_ts[factor] = monthly_returns          # 2. 计算每个因子的信息比率（IR）       # 假设用最近12个月的数据       factor_ir = {}       for factor, returns in factor_returns_ts.items():           recent_returns = returns[-12:] # 最近12个月           ir = np.mean(recent_returns) / np.std(recent_returns)           factor_ir[factor] = ir          # 3. 因子聚类（例如使用层次聚类或K-means，基于因子收益的相关性矩阵）       correlation_matrix = calculate_correlation(factor_returns_ts)       factor_clusters = perform_clustering(correlation_matrix, method='hierarchical') # 返回 {cluster_k: [factor_n1, factor_n2,...]}          # 4. 计算每个因子在各自聚类内的权重 w(n, k)       factor_weights = {}       for cluster_id, factors_in_cluster in factor_clusters.items():           total_ir_in_cluster = sum([factor_ir[f] for f in factors_in_cluster])           for factor in factors_in_cluster:               # 使用步骤三的公式               weight = factor_ir[factor] / total_ir_in_cluster               factor_weights[factor] = weight          return factor_clusters, factor_weights      # ===== 第二部分：模型应用（每月末执行） =====   # 输入：当前时刻的因子数据、训练得到的因子权重   # 输出：所有股票的 Alpha Score      def calculate_alpha_score(current_date, factor_weights, factor_clusters):       all_stocks = get_universe_stocks(current_date) # 获取股票池       alpha_scores = {} # 存储每只股票的最终得分          for stock in all_stocks:           total_alpha = 0.0           # 遍历每一个因子大类 (k)           for cluster_id, factors_in_cluster in factor_clusters.items():               # 遍历大类内的每一个因子 (n)               for factor in factors_in_cluster:                   # a. 获取该因子权重                   weight = factor_weights[factor]                   # b. 计算该股票在这个因子上的原始值                   factor_value = get_current_factor_value(stock, factor, current_date)                   # c. 在同行业内比较，进行打分 (V)                   industry_peers = get_industry_peers(stock)                   peer_values = [get_current_factor_value(peer, factor, current_date) for peer in industry_peers]                   # 确定该股票因子值在同行中的分位数                   percentile = calculate_percentile(factor_value, peer_values)                   # 根据分位数打分                   if percentile >= 0.8: # 前20%                       V = 1                   elif percentile <= 0.2: # 后20%                       V = -1                   else:                       V = 0                   # d. 加权累加                   total_alpha += weight * V              alpha_scores[stock] = total_alpha          # 根据 alpha_scores 对股票进行排序，选择得分高的构建投资组合       return alpha_scores   `

## 写在最后

1、注意，代码为ai生成，使用请谨慎。 

2、本方法是并不一定比原始方法高级或者更好，仅是给我们提供了一个不同的思路：在不改变原始因子基本结构的基础上，我们有时候更加看重因子某一下特征，可以通过一些变换，将原始因子值做一些转化，更加突出某一些性质，从而得到我们想要的结果。