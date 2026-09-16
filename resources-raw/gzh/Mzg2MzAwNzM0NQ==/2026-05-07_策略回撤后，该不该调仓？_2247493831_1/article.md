# 策略回撤后，该不该调仓？

QuantML QuantML 2026-05-07 20:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493831&idx=1&sn=217b5ae880a6db22aca247ddcc6a2d70&chksm=cf74acdbf06e8862f98530074b43fce1c201b0108632a71eab23ed1b4c42fb47f567dde3e742#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493831&idx=1&sn=217b5ae880a6db22aca247ddcc6a2d70&chksm=cf74acdbf06e8862f98530074b43fce1c201b0108632a71eab23ed1b4c42fb47f567dde3e742#rd)

策略连亏三周，客户问你："要不要调仓？"

你说"再观察观察"，第四周又亏三个点。客户坐不住了，你被迫砍了仓位，调整了因子权重。然后市场反弹了，你的调整刚好踩在反向节拍上。

2024 年上半年量化圈有个调研数据：极端行情后，**48.32% 的机构选择调整策略，51.68% 选择不动**。基本对半。

极端行情后到底应不应该调整，大部分人答不上来。因为 **"该不该调"的前提都没搞清楚** ——回撤到底是正常波动，还是市场风格切换导致的分布漂移？如果是前者，调了就是反复打脸；如果是后者，不调就是坐着等死。

**怎么判断当前回撤是不是 regime change 引起的，以及判断清楚了该做什么**。

我们不聊宏大叙事，直接上模型和数字。

## 1\. 为什么 VIX Gating 是错的

很多人用 VIX 做 regime proxy：VIX 高就降仓，低就满仓。逻辑简单，但数据不支持。

arXiv:2603.13252（2026-03）用 SPX 跑了 cross-sectional 模型在不同 VIX 分位的表现。核心结论：

-   2024 年 AI 主题轮动期间，VIX mean 在 95.1 百分位，但 cross-sectional 模型表现完全正常
    
-   2023 年上、下半年，VIX 同样超过 94 百分位，IC 反而是全样本最强：+0.104 和 +0.034
    

**VIX 测的是 aggregate volatility，因子失效发生在 dispersion 层面。两者没有稳定相关关系。**

我自己在 A 股上复现了这个结论。用 CSI300 的 realized volatility 做 proxy，测试期 2023-2024：

Method

IC

ICIR

单一模型

0.0107

0.09

VIX-proxy gating（vol > 90 分位降仓）

**0.0052**

**0.04**

VIX gating 的 IC 比什么都不做还低。这个结论我劝你记在脑子里，下次有人跟你聊"波动率高的时候降仓"，你可以把这张表拍他脸上。

## 2\. Regime Detection 的三条工程路线

学术界三条主流路线，我就不逐一介绍了，有兴趣直接询问AI，这里直接给结论：

### 路线一：Soft Markov Switching

Hamilton filter 的软化版本。理论扎实，有 closed-form。问题是 regime 数量要预先设定，转移概率慢慢变——等你检测出来，回撤已经吃完了。

数学上，Hamilton filter 估计的是隐状态序列  的后验概率：

其中前向概率：

后向概率：

EM 迭代直到收敛。问题在于：（regime 数量）是人为设定的，而且对突发性 regime 不敏感——转移概率矩阵  的元素  是全局估计的，不会因为你今天突然暴跌就跳变。

### 路线二：Spectral Clustering + XGBoost

用谱聚类把历史数据划成几个 regime，再用 XGBoost 学习特征到 regime 的映射。优点是非参数，缺点是聚类对距离度量极度敏感，换一个度量结果就跳。

工程上这条路线的优点是**失败模式显式**——聚类结果好不好，肉眼就能看出来。不像 HMM 给你一堆漂亮的概率数字，实际上 false alarm 一堆。

### 路线三：Coefficient-Based Soft Regime

Columbia 那篇 arXiv:2510.03236 推荐的路线。先用 Mood test 检测系数变化点，再用 HAR 系数本身做特征，过 Bayesian GMM 软聚类，最后 XGBoost 预测。

这条路线在 SPX 上的 RMSE 比 baseline HAR 低 15-20%，COVID 期间传统方法 RMSE 暴涨 40%，coefficient-based 只涨了 12%。

但工程复杂度是三条里最高的。Mood test 的窗口选择、HAR 的拟合稳定性、GMM 的先验设置，每一步都有调参空间，每一步都可能 overfit。我的建议是：**如果只能选一条先上，从路线二做起**。

## 3\. 代码实现：Bayesian GMM + XGBoost

路线二的最朴素实现。先定义市场层面的 regime 特征。

Bayesian GMM 的数学基础是 Dirichlet 过程先验。和普通 GMM 不同，它不需要你预先指定精确的簇数量，而是通过 `weight_concentration_prior` 控制簇的稀疏性：

其中  就是 `weight_concentration_prior`， 是非空簇的数量。 越大，模型越倾向于用更多的簇去解释数据。

代码实现：

```
from sklearn.mixture import BayesianGaussianMixturefrom sklearn.preprocessing import StandardScalerimport xgboost as xgb# Standardize — GMM 对尺度敏感scaler = StandardScaler()X_train = scaler.fit_transform(train_features[regime_cols])X_test = scaler.transform(test_features[regime_cols])# Bayesian GMM with Dirichlet process priorgmm = BayesianGaussianMixture(    n_components=3,              # upper bound, not exact    covariance_type='full',    weight_concentration_prior=1.0,    max_iter=500,    random_state=42)gmm.fit(X_train)# XGBoost learns the mapping from features to GMM labelsxgb_clf = xgb.XGBClassifier(    n_estimators=100,    max_depth=4,    learning_rate=0.1,    subsample=0.8,    colsample_bytree=0.8,    objective='multi:softprob',    num_class=3,    random_state=42)
```

**一个重要的工程细节**：GMM 聚出来的标签是 arbitrary 的（0、1、2 只是簇的编号，不代表任何物理意义）。**必须按波动率重新映射**，否则你的"低波动 regime"可能对应的是高波动簇。

Route A 的输出是一个 regime score：

```
gmm_proba = gmm.predict_proba(X_test)xgb_proba = xgb_clf.predict_proba(X_test)# Ensemble: 0.6 * GMM + 0.4 * XGB for high-vol regime probabilityregime_score = 0.6 * gmm_proba[:, high_vol_cluster] + 0.4 * xgb_proba[:, 2]
```

这个 score 的用途是仓位缩放：`position_size = base_size * (1 - regime_score)`。High-vol 时 score 接近 1，仓位压到 0。

实测结果：测试期 483 个交易日，score > 0.7 的只有 8 天。这个阈值太保守，绝大多数天数 regime score 落在中间区域，对实际仓位的指导意义有限。

**结论：Route A 作为 gating 机制，几乎不触发。**

## 4\. HMM + Specialist：理论上漂亮，工程上有坑

QuantInsti 给过的框架：HMM 检测 regime → 训两个 specialist 模型 → 按预测 regime 切换信号。听上去合理，我跑了一遍，发现两个问题。

### 4.1 HMM 的数学

Gaussian HMM 假设观测  在给定隐状态  下服从高斯分布：

转移概率：

Baum-Welch（EM）算法估计参数 。Viterbi 算法解码最优隐状态序列。

代码很简单：

```
from hmmlearn.hmm import GaussianHMMhmm = GaussianHMM(    n_components=3,    covariance_type='full',    n_iter=500,    random_state=42)hmm.fit(X_train)# Decode hidden stateshmm_labels = hmm.predict(X_test)
```

### 4.2 坑一：In-sample bias

HMM 的 regime 标签是 in-sample 学习出来的。Out-of-sample 时，新数据可能落入训练期没见过的高密度区域，模型会硬把它塞进某个旧 regime，结果就是 false alarm。

我实测的数据：HMM 在训练期把 2020 年 3 月 COVID 崩盘标为高波动 regime，这没问题。但测试期 2023-2024，它把几次普通的技术性回调也标成了高波动 regime，而真正的几次急跌反而标成了中波动。Lag 明显——等它检测出 regime 切换，主要回撤已经发生完了。

### 4.3 坑二：Regime 边界震荡

Specialist 模型在 regime 边界附近会来回切换。今天 regime A，明天 regime B，后天又切回 A。模型信号跟着跳，换手率被不必要地拉高。

我统计了测试期的 regime 切换频率：HMM 在 483 天里产生了 47 次相邻交易日之间的 regime 切换，平均 10 天切一次。而 GMM 的切换更频繁，因为它对当日特征的 noise 更敏感。

### 4.4 Specialist 模型的实测结果

修复之后，specialist 模型的IC有明显改善 ：

Regime

天数

Specialist IC

Single IC

结论

低波动

431

**0.0234**

0.0054

Specialist 碾压

中波动

19

0.0386

**0.0609**

样本太少，不稳定

高波动

33

**0.0606**

0.0511

Specialist 略好

整体 IC：Specialist 0.0265 vs Single 0.0107，ICIR 从 0.09 提升到 0.21。

所有代码均已上传知识星球，代码架构：

```
regime_shift/├── src/                          # 核心模块│   ├── config.py                 # 集中配置（数据路径、超参数、回测参数）│   ├── data_loader.py            # qlib 数据加载与缓存│   ├── features.py               # 市场层面 + 个股层面特征工程│   ├── regime_detector.py        # GMM+XGB / HMM 两种 regime 检测器│   ├── alpha_model.py            # LightGBM baseline + specialist 子模型│   ├── backtest.py               # 等权多空组合回测│   └── evaluation.py             # IC / ICIR / regime 分层统计├── scripts/│   ├── run_reproduction.py       # 代码入口│   └── run_validation.py         # 数据与模型校验├── data/│   ├── raw/                      # 原始 qlib 数据│   ├── processed/                # 特征矩阵│   └── results/                  # 测试结果└── README.md                     
```

## 5\. 不追 prediction，追 response

### 5.1 核心观点

Regime prediction 本质是择时，是一个低胜率游戏。我的建议是把精力从"预测下一个 regime"转移到"识别当前 regime 已经不利"，再转移到"已经预设的应对动作"。

### 5.2 三层防御体系

**第一层：IC 监控**

每个因子算 rolling 20 日 Spearman IC：

其中  是预测收益， 是实际收益， 是 Spearman 秩相关。

-   IC 掉 2 个标准差 → yellow alert
    
-   IC 掉 3 个标准差 → red alert，暂停因子或大幅降权
    

关键点：**监控对象是模型 efficacy（IC），不是市场环境 proxy（VIX）。** VIX 高了不一定降仓，但 IC 掉了 3σ 一定要做点什么。

**第二层：Factor exposure 漂移监控**

每天检查组合在 size、value、momentum、quality、low vol 等风格上的暴露。某个因子的 exposure 在 5 天内漂移超过 1 个标准差 → 检查 factor correlation structure 是否变了。

2024 年 2 月那次事后看就很清楚——市值因子的非线性暴露在两三天内突然成主导，整个因子相关性结构都变了。如果当时有这个监控，至少能在踩踏的第二天看到信号。

**第三层：策略切换预案**

至少准备三套策略：

-   Strategy A：主策略（适合 Steady State）
    
-   Strategy B：防御策略（适合 Crisis，低波 + 质量 + 现金）
    
-   Strategy C：灵活策略（适合 Walking on Ice，价值 + 动量混合）
    

切换 trigger 用 IC 监控来定，不用 regime 预测模型。让 regime 预测模型来定切换，等于把切换决定建立在另一个未必稳定的预测上——前者基于事实，后者基于猜测。

切换成本要提前算清楚：仓位调整 + 交易成本，1 到 3 天的 transition cost。遇到事再算就晚了。

## 6\. 结论：一些有用的建议

1.  **Specialist 模型在低波动 regime 里有增量 IC**（0.0234 vs 0.0054），但前提是因子本身要有正预期收益。如果 alpha 为负，IC 提升救不了你。
    
2.  **VIX-proxy gating 在 A 股上再次验证了我的怀疑**——IC（0.0052）不仅低于 specialist，还低于什么都不做的单一模型。Aggregate volatility 和 cross-sectional dispersion 是两回事。
    
3.  **HMM 的 regime 数量预设为 3，中波动 regime 样本太少**（测试期仅 19 天），specialist 在这个区间不稳定。工程上只切两个 regime（低波动 / 非低波动）可能更务实。
    
4.  **Regime switching 策略的 alpha 主要来自"避开极端坏的 regime"** 。"在好 regime 里赚更多"那部分大概率被高估了。
    

最后留一个问题：你的 regime 分类是靠市场环境指标（VIX、波动率），还是靠模型自己的 efficacy 指标（IC、Sharpe）？

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/001.jpg)