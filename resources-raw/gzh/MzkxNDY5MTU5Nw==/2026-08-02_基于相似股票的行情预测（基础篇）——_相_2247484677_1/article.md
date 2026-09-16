# 基于相似股票的行情预测（基础篇）—— 相似性的10种常用算法

蝴蝶量化 随率而动的因子工厂 2026-08-02 14:30 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484677&idx=1&sn=ac5ca9eef0d9125d273ddc9496f91b62&chksm=c0e2ab21cc9b0166f2ce58022302ea0a90c323369ec09360be7a61d66f794efd2dc10d213b0d#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484677&idx=1&sn=ac5ca9eef0d9125d273ddc9496f91b62&chksm=c0e2ab21cc9b0166f2ce58022302ea0a90c323369ec09360be7a61d66f794efd2dc10d213b0d#rd)

## 技术背景

对于绝大部分人来讲，如果你自己仔细分析过往的一整套历史流程你会发现，最原始的交易逻辑其实就是：**“历史会重演，但不会简单的重演。”** 前一句解释了交易的基本出发点，后一句解释了为什么你判断的重演在实际交易中会失败。

当你看到一只股票最近的K线走势，是否会想："这个形态我好像在历史上见过？那时候后面怎么走的？是不是会大涨或大跌？"

其实，无论你采用量化、技术分析、波浪理论、基本面等方法，其实都是在历史数据中寻找**规律**，然后判断这个“规律”是否能够预测未来的行情，如果能那么就会带来一定的超额收益，那么就可以形成一个交易策略、交易系统。**有一种交易方式除外：** 内幕交易或者价格制造者。

**举个例子：** 很多人认为MACD出现了背离之后，行情会反转见底、见顶。这就是分析历史行情，如果经过分析这种走势出现后未来10天的反转概率之后40%，甚至收益期望为负。也就是大概率会亏钱，你还会依赖于这样的判断去做交易吗？显然不会。当然也有部分人依靠这种判断能够赚到钱。分析下来主要依靠：

1.  幸存者偏差，俗称：运气。
    
2.  长期交易带来的敏锐的盘感与风险管理能力，这也是交易系统中的**止盈止损**.
    
3.  有效的仓位管理能力。
    

到这里你一定会有这样的疑问：如何去落实“历史会重演”的基本想法呢？如何识别相似的股票？识别之后如何形成交易策略呢？那么在接下来2～3篇的文章中，我们将介绍具体的落实方案：**相似K线预测交易系统。**

相似K线预测系统就是把这个思路工程化：

1.  **找到历史上相似的走势**（相似度算法）
    
2.  **统计这些走势之后发生了什么**（预测模型）
    
3.  **给出概率预测**（不是点预测，而是分布）
    

但问题来了：什么叫"相似"？怎么衡量？这就是本文要解决的核心问题。

当然，现在很多的看盘软件中都有：**“相似K线”** 的功能，分析下来大部分的算法就是简单的计算各种K线组合的相关系数，然后排序得到相应的相似度排名。总体来讲能够解决一些基础的K线相似的问题。但，由于从底层的数据仅仅源自于ohlc的行情数据，所以预测效果一般。当然，这是最简单的一种方式。

本期文章为系列文章的第一篇，主要目的：**介绍现有的一系列的计算股票走势相似性的算法。**

## 算法介绍

本节内容我们解决的了怎么做的问题，也就是具体算法介绍，注意，代码仅供参考。

### 算法1：欧氏距离

就像计算两点之间的直线距离，越小越相似。这是最直观最简单的计算方法。

#### 适用场景

-   快速筛选相似股票
    
-   实时计算场景
    
-   标准化后的收益率序列
    

**优点**

-   计算简单，速度快
    
-   直观易理解
    

**缺点**

-   对时间偏移敏感
    
-   受幅度影响大
    

#### python代码

终点在计算欧式距离之前，为了结果不受价格大小的影响，所以需要统一的做标准化以后计算欧式距离。

```
import numpy as npdef euclidean_distance(features1, features2, weights=None):    """    欧氏距离（支持单维和多维）        Args:        features1: 当前特征序列                   单维: shape=(T,) 如收益率序列                   多维: shape=(T, D) 如价格+成交量+RSI        features2: 历史特征序列        weights: 各特征权重，shape=(D,)，单维时可不传        Returns:        distance: 欧氏距离，越小越相似    """    # 统一输入格式    if features1.ndim == 1:        features1 = features1.reshape(-1, 1)    if features2.ndim == 1:        features2 = features2.reshape(-1, 1)        T, D = features1.shape        if weights is None:        weights = np.ones(D) / D        # 逐维度归一化并计算距离    distance = 0    for d in range(D):        feat1 = features1[:, d]        feat2 = features2[:, d]                # 归一化（加入epsilon防止除零）        feat1_norm = (feat1 - np.mean(feat1)) / (np.std(feat1) + 1e-8)        feat2_norm = (feat2 - np.mean(feat2)) / (np.std(feat2) + 1e-8)                # 该维度距离        dim_distance = np.sqrt(np.sum((feat1_norm - feat2_norm) ** 2))                # 加权累加        distance += weights[d] * dim_distance        return distance# 使用示例1：单维（只看收益率）current_kline = np.array([0.01, 0.02, -0.01, 0.03, 0.00])history_kline = np.array([0.015, 0.025, -0.015, 0.028, 0.005])dist = euclidean_distance(current_kline, history_kline)print(f"单维欧氏距离: {dist:.4f}")# 使用示例2：多维（价量配合）current_features = np.array([    # 时刻t-4到t，共5个时间点，4个特征    [0.01, 1.2, 55, 0.015],  # 收益率, 量比, RSI, 波动率    [0.02, 1.5, 58, 0.018],    [-0.01, 0.8, 52, 0.012],    [0.03, 1.3, 60, 0.020],    [0.00, 1.1, 57, 0.016]])history_features = np.array([    [0.015, 1.1, 54, 0.014],    [0.025, 1.4, 57, 0.017],    [-0.015, 0.9, 53, 0.013],    [0.028, 1.2, 59, 0.019],    [0.005, 1.0, 56, 0.015]])# 权重设置（根据重要性）weights = np.array([0.4, 0.3, 0.2, 0.1])  # 收益率最重要dist = euclidean_distance(current_features, history_features, weights)print(f"多维欧氏距离: {dist:.4f}")
```

#### 实战特征组合推荐

```
# 组合1: 价量配合（短线）FEATURES_SHORT = {    'price_returns': 0.4,      # 收益率序列    'volume_ratio': 0.3,       # 量比序列    'volatility': 0.2,         # 波动率    'rsi': 0.1                 # RSI}# 组合2: 技术指标全面（中线）FEATURES_MEDIUM = {    'price_returns': 0.3,    'macd': 0.2,    'rsi': 0.15,    'atr': 0.15,    'volume_ratio': 0.2}# 组合3: 基本面+技术面（长线）FEATURES_LONG = {    'price_returns': 0.25,    'pe_ratio': 0.15,          # PE估值    'roe': 0.15,               # ROE    'revenue_growth': 0.15,    # 营收增长    'macd': 0.15,    'volume_ratio': 0.15}
```

注意：当然这些具体的权重，可以通过滚动优化、机器学习等方法做最优权重配置。

### 算法2：DTW（动态时间规整）

在算法1中，天然存在对时间维度的严格要求，没法处理时间错位的问题，但是DTW算法，给出处理时间错位的有效解决办法。由于篇幅原因，我们会在后期专门做一个关于DTW的文章。

**核心思想：** 允许序列在时间轴上"弹性对齐"。

**举个例子：** 想象两个人走同一条路，一个走得快，一个走得慢，但路线相同。普通距离会认为他们不相似，但DTW能识别出来。

#### 适用场景

-   **K线形态匹配，** 在很多项目中这是首选算法。
    
-   技术指标序列匹配
    
-   多周期形态识别
    
-   **多维时序模式识别**
    

**优点**

-   处理时间扭曲和速度差异
    
-   鲁棒性强
    

**缺点**

-   计算复杂度O(n²)
    
-   需要窗口约束加速
    

#### python代码

```
import numpy as npdef dtw_distance(features1, features2, weights=None, window=None):    """    DTW动态时间规整距离（支持单维和多维）        Args:        features1: 当前特征序列                   单维: shape=(T,) 如收益率序列                   多维: shape=(T, D) 如价格+成交量+RSI        features2: 历史特征序列        weights: 各特征权重，shape=(D,)，单维时可不传        window: 窗口约束，限制对齐路径（加速）        Returns:        distance: DTW距离    """    # 统一输入格式：将一维转为二维    if features1.ndim == 1:        features1 = features1.reshape(-1, 1)    if features2.ndim == 1:        features2 = features2.reshape(-1, 1)        T1, D = features1.shape    T2, _ = features2.shape        if weights is None:        weights = np.ones(D) / D        if window is None:        window = max(T1, T2) // 2        # 初始化DTW矩阵    dtw_matrix = np.full((T1 + 1, T2 + 1), np.inf)    dtw_matrix[0, 0] = 0        # 动态规划    for i in range(1, T1 + 1):        for j in range(max(1, i - window), min(T2 + 1, i + window)):            # 计算多维距离（加权）            cost = 0            for d in range(D):                feat1 = features1[i-1, d]                feat2 = features2[j-1, d]                cost += weights[d] * abs(feat1 - feat2)                        dtw_matrix[i, j] = cost + min(                dtw_matrix[i-1, j],      # 插入                dtw_matrix[i, j-1],      # 删除                dtw_matrix[i-1, j-1]     # 匹配            )        # 归一化距离    distance = dtw_matrix[T1, T2] / max(T1, T2)    return distance# 使用示例2：多维（价量技术面）current_features = np.array([    [0.01, 1.2, 55, 0.015],  # 收益率, 量比, RSI, 波动率    [0.02, 1.5, 58, 0.018],    [0.01, 0.8, 52, 0.012],    [0.03, 1.3, 60, 0.020]])history_features = np.array([    [0.015, 1.1, 54, 0.014],    [0.01,  1.4, 57, 0.017],    [0.025, 0.9, 53, 0.013],    [0.03,  1.2, 59, 0.019],    [0.02,  1.0, 56, 0.015]])weights = np.array([0.4, 0.25, 0.2, 0.15])  # 收益率最重要multi_dist = dtw_distance(current_features, history_features, weights)print(f"多维DTW距离: {multi_dist:.4f}")
```

#### 实战应用：价量形态联合匹配

```
def find_similar_patterns_dtw(    target_stock,     target_date,    stock_pool,    lookback_window=20,    top_k=10):    """    基于多维DTW找到相似的价量形态        流程：        1. 提取目标股票的多维特征（价格+成交量+技术指标）        2. 在股票池中搜索历史相似形态        3. 返回Top-K相似案例    """    # 1. 提取目标特征    target_features = extract_multivariate_features(        target_stock,         target_date,         lookback_window    )    # target_features.shape = (20, 5)        similar_cases = []        # 2. 遍历股票池和历史时间    for stock in stock_pool:        for date in get_history_dates(stock, start='2020-01-01', end=target_date):            # 提取历史特征            history_features = extract_multivariate_features(                stock,                 date,                 lookback_window            )                        # 计算多维DTW距离            distance = dtw_distance(                target_features,                history_features,                weights=np.array([0.35, 0.25, 0.2, 0.1, 0.1])            )                        similar_cases.append({                'stock': stock,                'date': date,                'distance': distance            })        # 3. 排序并返回Top-K    similar_cases.sort(key=lambda x: x['distance'])    return similar_cases[:top_k]
```

### 算法3：余弦相似度

#### 核心思想

计算两个向量的夹角，夹角越小（余弦值越大）越相似。

关键特点：**只看趋势方向，不看涨跌幅度**。

#### 适用场景

-   趋势相似性判断
    
-   动量因子构建
    
-   行业轮动分析
    
-   **多维因子相似度**
    

#### python代码

```
def cosine_similarity(features1, features2):    """    余弦相似度（支持单维和多维）        Args:        features1: 当前特征                   单维: shape=(T,) 如时序收益率                   多维因子: shape=(D,) 如[PE, PB, ROE]                   多维时序: shape=(T, D) 会被展平        features2: 历史特征        Returns:        similarity: 范围[-1, 1]，越大越相似        说明：        余弦相似度天然支持任意维度，通过flatten自动适配    """    # 展平为一维向量（支持所有输入格式）    vec1 = features1.flatten()    vec2 = features2.flatten()        # 计算余弦相似度    dot_product = np.dot(vec1, vec2)    norm1 = np.linalg.norm(vec1)    norm2 = np.linalg.norm(vec2)        similarity = dot_product / (norm1 * norm2 + 1e-8)    return similarity# 使用示例2：多维因子（基本面相似度）# 贵州茅台的因子maotai_factors = np.array([    30.5,   # PE    12.8,   # PB    0.35,   # ROE    0.15,   # 营收增长率    0.18,   # 净利润增长率    0.85,   # 毛利率    0.15    # 负债率])# 五粮液的因子wuliangye_factors = np.array([    28.3, 11.5, 0.32, 0.12, 0.15, 0.82, 0.18])sim = cosine_similarity(maotai_factors, wuliangye_factors)print(f"多维因子相似度: {sim:.4f}")  # 高相似度说明基本面接近# 使用示例3：多维时序（自动展平）price_volume = np.array([    [0.01, 1.2],  # 收益率, 量比    [0.02, 1.5],    [0.03, 0.8]])history_pv = np.array([    [0.015, 1.1],    [0.025, 1.4],    [0.028, 0.9]])sim = cosine_similarity(price_volume, history_pv)print(f"多维时序相似度: {sim:.4f}")
```

#### 时序+因子的混合相似度

```
def hybrid_cosine_similarity(price_series1, price_series2,                              factors1, factors2,                             price_weight=0.6, factor_weight=0.4):    """    混合相似度：时序形态 + 因子特征        应用：        找到"走势相似+基本面相似"的股票        避免只看价格形态，忽略基本面    """    # 价格序列相似度    price_sim = cosine_similarity(price_series1, price_series2)        # 因子相似度    factor_sim = cosine_similarity(factors1, factors2)        # 加权融合    hybrid_sim = price_weight * price_sim + factor_weight * factor_sim        return hybrid_sim, {'price_sim': price_sim, 'factor_sim': factor_sim}# 使用示例current_price = np.array([0.01, 0.02, 0.03, 0.02, 0.01])history_price = np.array([0.015, 0.025, 0.028, 0.022, 0.012])current_factors = np.array([30.5, 12.8, 0.35, 0.15])history_factors = np.array([28.3, 11.5, 0.32, 0.12])hybrid_sim, details = hybrid_cosine_similarity(    current_price, history_price,    current_factors, history_factors)print(f"混合相似度: {hybrid_sim:.4f}")print(f"  - 价格相似度: {details['price_sim']:.4f}")print(f"  - 因子相似度: {details['factor_sim']:.4f}")
```

### 算法4：皮尔逊相关系数

#### 核心思想

衡量两个序列的线性相关程度，自动去中心化。这是大部分软件中计算相似度的方法

#### 适用场景

-   股票间相关性分析
    
-   因子相关性检验
    
-   配对交易
    
-   **多因子协同分析**
    

#### python代码

```
def pearson_correlation(features1, features2, weights=None):    """    皮尔逊相关系数（支持单维和多维）        Args:        features1: 当前特征序列                   单维: shape=(T,)                   多维: shape=(T, D)        features2: 历史特征序列        weights: 各维度权重，shape=(D,)，单维时忽略        Returns:        correlation: 单维返回标量，多维返回加权平均相关系数    """    # 统一输入格式    if features1.ndim == 1:        features1 = features1.reshape(-1, 1)    if features2.ndim == 1:        features2 = features2.reshape(-1, 1)        T, D = features1.shape        if weights is None:        weights = np.ones(D) / D        # 计算各维度相关系数    weighted_corr = 0    for d in range(D):        # 去中心化        x = features1[:, d] - np.mean(features1[:, d])        y = features2[:, d] - np.mean(features2[:, d])                # 计算相关系数        corr = np.sum(x * y) / (np.sqrt(np.sum(x**2)) * np.sqrt(np.sum(y**2)) + 1e-8)        weighted_corr += weights[d] * corr        return weighted_corr# 使用示例：多维加权相关（重视基本面因子）features1 = np.random.randn(20, 4)  # 20天，4个特征features2 = np.random.randn(20, 4)# 权重：PE、PB、ROE、营收增长率# ROE和营收增长率更重要weights = np.array([0.2, 0.2, 0.3, 0.3])weighted_corr = pearson_correlation(features1, features2, weights)print(f"多维加权相关: {weighted_corr:.4f}")
```

### 算法5：K线形态距离

#### 核心思想

不只看收益率，还看K线的形态特征：实体、影线、方向。主要是用在技术指标，判断相似性

#### python代码

```
# K线特征提取def extract_kline_features(open, high, low, close):    """    提取K线形态特征        Returns:        features: [实体比例, 上影线, 下影线, 方向]    """    full_range = high - low    if full_range == 0:        return np.array([0, 0, 0, 0])        # 实体比例    body = abs(close - open)    body_ratio = body / full_range        # 上影线比例    upper_shadow = (high - max(open, close)) / full_range        # 下影线比例    lower_shadow = (min(open, close) - low) / full_range        # 方向（阴阳线）    direction = 1 if close > open else -1        return np.array([body_ratio, upper_shadow, lower_shadow, direction])# 形态距离计算def shape_distance(kline1_ohlc, kline2_ohlc, weights=None):    """    K线形态距离        Args:        kline1_ohlc: [(open, high, low, close), ...]        kline2_ohlc: [(open, high, low, close), ...]        weights: 特征权重 [实体, 上影线, 下影线, 方向]    """    if weights is None:        weights = np.array([0.4, 0.2, 0.2, 0.2])        # 检查长度是否一致    if len(kline1_ohlc) != len(kline2_ohlc):        raise ValueError(f"K线序列长度不一致: {len(kline1_ohlc)} vs {len(kline2_ohlc)}")        # 提取特征序列    features1 = np.array([extract_kline_features(*k) for k in kline1_ohlc])    features2 = np.array([extract_kline_features(*k) for k in kline2_ohlc])        # 计算差异 shape=(T, 4)    diff = features1 - features2        # 按特征维度加权，按时间维度求和    # (T, 4) * (4,) -> (T, 4) -> sum -> scalar    weighted_diff_sq = np.sum((diff ** 2) * weights, axis=1)  # shape=(T,)    distance = np.sqrt(np.sum(weighted_diff_sq))        return distance
```

### 算法6：曼哈顿距离

#### 核心思想

计算各维度差值的绝对值之和，而不是平方和。

**特点：对异常值不敏感**

#### 适用场景

-   数据有异常值的场景
    
-   稳健性要求高的场合
    
-   **多维特征鲁棒估计**
    

#### python代码

```
def manhattan_distance(features1, features2, weights=None):    """    曼哈顿距离（支持单维和多维）        Args:        features1: 当前特征序列                   单维: shape=(T,)                   多维: shape=(T, D)        features2: 历史特征序列        weights: 各特征权重，shape=(D,)        Returns:        distance: 曼哈顿距离（L1距离）        优势：        - 对异常值更鲁棒        - 适合特征量纲差异大的场景        - 计算效率高    """    # 统一输入格式    if features1.ndim == 1:        features1 = features1.reshape(-1, 1)    if features2.ndim == 1:        features2 = features2.reshape(-1, 1)        T, D = features1.shape        if weights is None:        weights = np.ones(D) / D        distance = 0    for d in range(D):        # 提取第d维特征        feat1 = features1[:, d]        feat2 = features2[:, d]                # 归一化        feat1_norm = (feat1 - np.mean(feat1)) / (np.std(feat1) + 1e-8)        feat2_norm = (feat2 - np.mean(feat2)) / (np.std(feat2) + 1e-8)                # L1距离        dim_distance = np.sum(np.abs(feat1_norm - feat2_norm))                # 加权        distance += weights[d] * dim_distance        return distance# 使用示例1：单维（对比欧氏距离）current = np.array([0.01, 0.02, 0.05])  # 有一个异常值0.05history = np.array([0.01, 0.02, 0.00])euclidean = np.sqrt(np.sum((current - history) ** 2))manhattan = manhattan_distance(current, history)print(f"欧氏距离: {euclidean:.4f}")    # 0.0500，受异常值影响大print(f"曼哈顿距离: {manhattan:.4f}")  # 更稳健# 使用示例2：多维（多特征）current_features = np.array([    [0.01, 1.2, 55],     # 收益率, 量比, RSI    [0.02, 1.5, 58],    [0.05, 0.8, 52]      # 第一维有异常值])history_features = np.array([    [0.01, 1.1, 54],    [0.02, 1.4, 57],    [0.00, 0.9, 53]])weights = np.array([0.4, 0.3, 0.3])dist = manhattan_distance(current_features, history_features, weights)print(f"多维曼哈顿距离: {dist:.4f}")
```

### 算法7：马氏距离

#### 核心思想

**欧氏距离和曼哈顿距离假设各特征独立**，但实际上特征之间往往有相关性（比如PE和PB往往正相关）。

马氏距离考虑了**特征间的协方差**，更适合多维因子分析。

#### 适用场景

-   **多因子相似度**（强烈推荐）
    
-   基本面因子筛选
    
-   异常检测
    
-   风险模型
    

#### python代码

仅为参考代码

```
def mahalanobis_distance(x, y, cov_matrix):    """    马氏距离        Args:        x: 当前样本向量，shape=(D,)        y: 历史样本向量，shape=(D,)        cov_matrix: 协方差矩阵，shape=(D, D)        Returns:        distance: 马氏距离    """    diff = x - y        # 协方差矩阵的逆    try:        inv_cov = np.linalg.inv(cov_matrix)    except np.linalg.LinAlgError:        # 协方差矩阵奇异（不可逆），使用伪逆或正则化        import warnings        warnings.warn("协方差矩阵奇异，使用伪逆计算", RuntimeWarning)        inv_cov = np.linalg.pinv(cov_matrix)        # 马氏距离    distance = np.sqrt(diff.T @ inv_cov @ diff)        return distance# 使用示例# 假设有3个因子：PE, PB, ROEcurrent_factors = np.array([30.5, 12.8, 0.35])history_factors = np.array([28.3, 11.5, 0.32])# 协方差矩阵（从历史数据估计）# PE和PB往往正相关，ROE与估值负相关cov_matrix = np.array([    [10.0,  5.0, -2.0],  # PE的方差和协方差    [ 5.0,  4.0, -1.5],  # PB的方差和协方差    [-2.0, -1.5,  0.01]  # ROE的方差和协方差])mahal_dist = mahalanobis_distance(current_factors, history_factors, cov_matrix)eucl_dist = np.linalg.norm(current_factors - history_factors)print(f"马氏距离: {mahal_dist:.4f}")print(f"欧氏距离: {eucl_dist:.4f}")# 实战应用：多因子股票筛选def find_similar_stocks_by_factors(target_stock_factors,                                    stock_pool_factors,                                    stock_codes,                                   cov_matrix,                                   top_k=10):    """    基于马氏距离找到因子相似的股票        Args:        target_stock_factors: 目标股票的因子，shape=(D,)        stock_pool_factors: 股票池的因子矩阵，shape=(N, D)        stock_codes: 股票代码列表        cov_matrix: 因子协方差矩阵，shape=(D, D)        top_k: 返回Top-K相似股票        Returns:        similar_stocks: [(股票代码, 马氏距离), ...]    """    distances = []        for i, stock_factors in enumerate(stock_pool_factors):        dist = mahalanobis_distance(            target_stock_factors,             stock_factors,             cov_matrix        )        distances.append((stock_codes[i], dist))        # 按距离排序    distances.sort(key=lambda x: x[1])        return distances[:top_k]# 使用示例# 目标：找到和贵州茅台因子相似的股票maotai_factors = np.array([30.5, 12.8, 0.35, 0.15, 0.85])  # PE, PB, ROE, 增长率, 毛利率# 股票池（示例）stock_pool = {    '600519.SH': np.array([30.5, 12.8, 0.35, 0.15, 0.85]),  # 贵州茅台（自己）    '000858.SZ': np.array([28.3, 11.5, 0.32, 0.12, 0.82]),  # 五粮液    '000568.SZ': np.array([35.2, 8.5, 0.28, 0.10, 0.78]),   # 泸州老窖    '603589.SH': np.array([45.8, 15.2, 0.25, 0.08, 0.75]),  # 口子窖}stock_codes = list(stock_pool.keys())stock_factors_matrix = np.array(list(stock_pool.values()))# 估计协方差矩阵（从历史数据）cov_matrix = np.cov(stock_factors_matrix.T)# 查找相似股票similar_stocks = find_similar_stocks_by_factors(    maotai_factors,    stock_factors_matrix,    stock_codes,    cov_matrix,    top_k=3)print("与贵州茅台因子最相似的股票：")for code, dist in similar_stocks:    print(f"  {code}: 马氏距离 = {dist:.4f}")
```

### 算法8：KNN + Embedding

#### 核心思想

将K线序列映射到低维向量空间，然后用FAISS等向量库快速检索相似案例。

这是从**特征空间**到**语义空间**的升华。

**架构流程**

```
K线序列(20日) → AutoEncoder编码 → 128维向量 → FAISS检索 → Top-K相似案例
```

#### python代码

```
import torchimport torch.nn as nnclass UnifiedAutoEncoder(nn.Module):    """    统一的AutoEncoder（支持单维和多维）        输入：        单维: shape=(T,) 如20日收益率序列        多维: shape=(T, D) 如(20, 5)的价格+成交量+技术指标        输出：shape=(embedding_dim,) 如128维向量    """    def __init__(self, seq_len=20, feature_dim=1, embedding_dim=128):        super().__init__()                input_size = seq_len * feature_dim  # 展平后的输入维度                # 编码器        self.encoder = nn.Sequential(            nn.Linear(input_size, 512),            nn.ReLU(),            nn.Dropout(0.2),            nn.Linear(512, 256),            nn.ReLU(),            nn.Dropout(0.2),            nn.Linear(256, embedding_dim)        )                # 解码器        self.decoder = nn.Sequential(            nn.Linear(embedding_dim, 256),            nn.ReLU(),            nn.Linear(256, 512),            nn.ReLU(),            nn.Linear(512, input_size)        )                self.seq_len = seq_len        self.feature_dim = feature_dim        def forward(self, x):        # x可以是(batch, T)或(batch, T, D)        batch_size = x.shape[0]                # 展平        x_flat = x.view(batch_size, -1)                # 编码        embedding = self.encoder(x_flat)                # 解码        reconstruction = self.decoder(embedding)        reconstruction = reconstruction.view(batch_size, self.seq_len, self.feature_dim)                return embedding, reconstruction# 使用示例1：单维（只有收益率）def encode_single_feature(kline_sequence):    """编码单维K线序列"""    model = UnifiedAutoEncoder(seq_len=20, feature_dim=1, embedding_dim=128)    model.eval()        with torch.no_grad():        x = torch.FloatTensor(kline_sequence).unsqueeze(0).unsqueeze(-1)  # (1, 20, 1)        embedding, _ = model(x)        return embedding.squeeze().numpy()# 使用示例2：多维（价格+成交量+技术指标）def encode_multi_features(features):    """    编码多维特征        Args:        features: shape=(T, D) 如(20, 5)    """    model = UnifiedAutoEncoder(seq_len=20, feature_dim=5, embedding_dim=128)    model.eval()        with torch.no_grad():        x = torch.FloatTensor(features).unsqueeze(0)  # (1, 20, 5)        embedding, _ = model(x)        return embedding.squeeze().numpy()# FAISS快速检索import faissdef build_faiss_index(embeddings):    """    构建FAISS索引        Args:        embeddings: shape=(N, 128) N个历史K线的向量表示    """    dimension = embeddings.shape[1]    index = faiss.IndexFlatL2(dimension)  # L2距离    index.add(embeddings.astype('float32'))    return indexdef search_similar(query_embedding, index, top_k=10):    """搜索最相似的K个案例"""    distances, indices = index.search(        query_embedding.reshape(1, -1).astype('float32'),         top_k    )    return distances[0], indices[0]# 单维使用示例kline = np.array([0.01, 0.02, -0.01, 0.03, ...])  # 20日收益率emb_single = encode_single_feature(kline)print(f"单维向量: {emb_single.shape}")  # (128,)# 多维使用示例multi_features = np.random.randn(20, 5)  # 20天，5个特征emb_multi = encode_multi_features(multi_features)print(f"多维向量: {emb_multi.shape}")  # (128,)# 实战应用：全市场多维相似度检索def build_market_similarity_system():    """    构建全市场多维相似度检索系统        步骤：        1. 收集全市场历史数据（4000只股票，5年）        2. 提取多维特征（价格+量+技术指标）        3. 训练AutoEncoder        4. 编码所有历史窗口，构建FAISS索引        5. 实时查询相似案例    """        # 1. 收集数据    all_stocks = get_stock_list()  # 4000只    all_features = []    all_metadata = []        for stock in all_stocks:        data = get_stock_data(stock, start='2019-01-01', end='2024-12-31')                # 滑动窗口提取特征        window = 20        for i in range(window, len(data)):            # 提取窗口特征            window_data = data.iloc[i-window:i]            features = extract_multivariate_features_from_data(window_data)            # features.shape = (20, 5)                        all_features.append(features)            all_metadata.append({                'stock': stock,                'date': data.index[i],                'future_return_5d': calculate_future_return(data, i, 5)            })        # 转换为numpy数组    all_features = np.array(all_features)  # shape=(M, 20, 5), M约400万        # 2. 训练AutoEncoder    print("训练AutoEncoder...")    model = train_multi_feature_autoencoder(all_features, epochs=50)        # 3. 编码所有样本    print("编码所有样本...")    embeddings = []    for features in all_features:        emb = encode_multi_features(features, model)        embeddings.append(emb)        embeddings = np.array(embeddings)  # shape=(M, 128)        # 4. 构建FAISS索引    print("构建FAISS索引...")    dimension = 128    index = faiss.IndexFlatL2(dimension)    index.add(embeddings.astype('float32'))        return model, index, all_metadata# 查询相似案例def find_similar_cases_embedding(current_stock, current_date,                                  model, index, metadata, top_k=30):    """    基于Embedding查找相似案例    """    # 1. 提取当前特征    current_data = get_stock_data(current_stock, end_date=current_date, periods=20)    current_features = extract_multivariate_features_from_data(current_data)        # 2. 编码    current_embedding = encode_multi_features(current_features, model)        # 3. FAISS检索    distances, indices = index.search(        current_embedding.reshape(1, -1).astype('float32'),         top_k    )        # 4. 返回相似案例    similar_cases = []    for dist, idx in zip(distances[0], indices[0]):        case = metadata[idx]        case['distance'] = dist        similar_cases.append(case)        return similar_cases# 使用示例# model, index, metadata = build_market_similarity_system()# similar_cases = find_similar_cases_embedding('600519.SH', '2024-08-01', model, index, metadata)
```

### 算法9：多尺度DTW

#### 💡 核心思想

不同投资者关注不同周期，短线看5日，中线看20日，长线看60日。

多尺度DTW同时匹配多个时间尺度，融合得到综合相似度。

#### python代码

```
def multi_scale_dtw(features1, features2,                     scales=[5, 20, 60],                     scale_weights=None,                    feature_weights=None):    """    多尺度DTW（支持单维和多维）        Args:        features1: 当前特征                   单维: shape=(T,)                   多维: shape=(T, D)        features2: 历史特征        scales: 时间尺度列表        scale_weights: 各尺度权重        feature_weights: 各特征权重（多维时使用）        Returns:        final_distance: 多尺度融合距离    """    # 统一输入格式    if features1.ndim == 1:        features1 = features1.reshape(-1, 1)    if features2.ndim == 1:        features2 = features2.reshape(-1, 1)        if scale_weights is None:        scale_weights = np.array([0.3, 0.5, 0.2])  # 以20日为主        distances = []    valid_weights = []        for scale, weight in zip(scales, scale_weights):        # 检查序列是否足够长        T1, T2 = len(features1), len(features2)        if T1 < scale or T2 < scale:            actual_scale = min(scale, T1, T2)            if actual_scale < 3:  # 至少需要3个点                continue            sub1 = features1[-actual_scale:]            sub2 = features2[-actual_scale:]        else:            sub1 = features1[-scale:]            sub2 = features2[-scale:]                # 计算DTW距离（使用统一的DTW函数，支持多维）        dist = dtw_distance(sub1, sub2, weights=feature_weights)        distances.append(dist)        valid_weights.append(weight)        # 重新归一化权重    valid_weights = np.array(valid_weights)    valid_weights = valid_weights / valid_weights.sum()        # 加权融合    final_distance = np.sum(valid_weights * np.array(distances))    return final_distance# 使用示例1：单维（只看收益率）current = np.random.randn(60)history = np.random.randn(60)multi_dtw = multi_scale_dtw(current, history, scales=[5, 20, 60])print(f"单维多尺度DTW: {multi_dtw:.4f}")# 使用示例2：多维（价格+成交量+技术指标）current_features = np.random.randn(60, 5)  # 60天，5个特征history_features = np.random.randn(60, 5)# 特征权重：收益率>RSI>量>MACD>ATRfeature_weights = np.array([0.35, 0.25, 0.2, 0.1, 0.1])# 尺度权重：中期>长期>短期scale_weights = np.array([0.2, 0.5, 0.3])multi_dtw = multi_scale_dtw(    current_features,     history_features,    scales=[5, 20, 60],    scale_weights=scale_weights,    feature_weights=feature_weights)print(f"多维多尺度DTW: {multi_dtw:.4f}")# 自适应尺度选择def adaptive_scale_dtw(features1, features2, market_condition):    """    根据市场环境自适应选择尺度权重    """    if market_condition == '震荡市':        # 震荡市：短期形态更重要        scales = [5, 10, 20]        scale_weights = np.array([0.4, 0.4, 0.2])        elif market_condition == '牛市':        # 牛市：中长期趋势更重要        scales = [10, 20, 60]        scale_weights = np.array([0.2, 0.3, 0.5])        elif market_condition == '熊市':        # 熊市：关注中期反弹        scales = [5, 20, 40]        scale_weights = np.array([0.3, 0.5, 0.2])        else:        # 默认        scales = [5, 20, 60]        scale_weights = np.array([0.2, 0.5, 0.3])        return multi_scale_dtw(features1, features2, scales, scale_weights)
```

### 算法10：CNN图像识别

#### 核心思想

**完全不同的范式**：不使用传统的数值序列比较，而是将K线转换为**图像**，用卷积神经网络（CNN）自动学习和识别形态特征。

这种方法把相似度判断问题转化为**计算机视觉中的图像识别问题**。

#### 适用场景

-   复杂技术形态识别
    
-   大规模历史数据挖掘
    
-   跨市场形态匹配
    
-   追求极致预测性能
    

**优点**

-   自动学习复杂形态特征
    
-   不受时间偏移影响
    
-   融合价格+成交量的视觉信息
    
-   泛化能力强**缺点**
    
-   需要大量训练数据
    
-   计算成本高（需GPU）
    
-   可解释性差（黑盒模型）
    

#### python代码

**Step 1: K线图像生成**

```
import matplotlib.pyplot as pltimport mplfinance as mpfimport numpy as npdef generate_kline_image(ohlc_data, window=20, image_size=(224, 224)):    """    将OHLC数据转换为K线图像        Args:        ohlc_data: DataFrame，包含open/high/low/close/volume        window: 时间窗口（20日）        image_size: 输出图像尺寸        Returns:        image: numpy数组，shape=(H, W, 3)    """    # 提取窗口数据    window_data = ohlc_data.iloc[-window:]        # 生成K线图    fig, axes = plt.subplots(2, 1, figsize=(5, 3),                              gridspec_kw={'height_ratios': [3, 1]})        # 主图：K线    mpf.plot(window_data, type='candle', ax=axes[0],              style='charles', volume=False)        # 副图：成交量    axes[1].bar(range(len(window_data)), window_data['volume'])        # 转换为图像数组    fig.canvas.draw()    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype=np.uint8)    image = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))        # 调整尺寸    from PIL import Image    image = Image.fromarray(image).resize(image_size)    image = np.array(image) / 255.0  # 归一化        plt.close(fig)    return image
```

**Step 2: CNN模型**

```
import torchimport torch.nn as nnclass KLineCNN(nn.Module):    """K线图像识别CNN（国金证券2024）"""    def __init__(self, num_classes=2):        super().__init__()                self.conv1 = nn.Sequential(            nn.Conv2d(3, 64, kernel_size=5, stride=3, padding=2),            nn.LeakyReLU(0.2),            nn.MaxPool2d(kernel_size=2, stride=1)        )                self.conv2 = nn.Sequential(            nn.Conv2d(64, 128, kernel_size=5, stride=3, padding=2),            nn.LeakyReLU(0.2),            nn.MaxPool2d(kernel_size=2, stride=1)        )                self.fc = nn.Sequential(            nn.Flatten(),            nn.Linear(128 * 55 * 56, 256),  # 根据输入224x224计算得出            nn.Dropout(0.4),            nn.Linear(256, num_classes)        )        def forward(self, x):        x = self.conv1(x)        x = self.conv2(x)        return self.fc(x)
```

**Step 3: 预测使用**

```
def predict_with_cnn(model, stock, date, window=20):    """使用CNN预测"""    # 获取数据（防止未来函数）    data = get_stock_data(stock, end_date=date - timedelta(days=1), periods=window)        # 生成图像    image = generate_kline_image(data)    image = torch.FloatTensor(image.transpose(2, 0, 1)).unsqueeze(0)        # 预测    model.eval()    with torch.no_grad():        output = model(image)        probs = torch.softmax(output, dim=1)        prediction = torch.argmax(probs).item()        probability = probs[0, 1].item()        return prediction, probability
```

#### **混合策略**

```
def hybrid_cnn_dtw(stock, date, market_regime):    """CNN + DTW混合策略"""    cnn_pred = predict_with_cnn(model, stock, date)    dtw_pred = predict_with_dtw(stock, date)        # 震荡市偏重DTW，趋势市偏重CNN    if market_regime == '震荡市':        return 0.7 * dtw_pred + 0.3 * cnn_pred    else:        return 0.4 * dtw_pred + 0.6 * cnn_pred
```

## 总结

本位给出了10中单独的计算股票走势、基本面、技术面、视觉上的各种相似的算法，当然找出相似性仅仅是这一系列的第一步，接下来我们还有：相似性的实证效果、评价标准与回测、策略构造等等方面。

其实，这里的寻找相似、预测行情的方法，仔细想想跟我们之前介绍过的时序上多因子择时策略本质上是一样的逻辑。