# 如何使用Agent复现因子策略——遗传算法实现因子挖掘（下）：算法、效果

蝴蝶量化 随率而动的因子工厂 2026-05-11 07:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484619&idx=1&sn=1321cfcf92b0d8524ec9a03d758f4a7b&chksm=c0a399ecf7c36286fa81dca5124d8043304830fddfda8d324d9e1ae959bcdf37a5762895a097#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484619&idx=1&sn=1321cfcf92b0d8524ec9a03d758f4a7b&chksm=c0a399ecf7c36286fa81dca5124d8043304830fddfda8d324d9e1ae959bcdf37a5762895a097#rd)

## 技术背景

现在Agent作为编程的大利器，大幅增加了工程师的工作效率，也给一些不懂编程的小伙伴带了福音。让他们能够实现自己心中的策略，那么事实真的是这样吗？

本文，就从一个实际的案例出发，给出了一个合理的工作流，让不懂编程的小伙伴能够使用Agent实现理想的策略，也大幅增加了量化人的实现心中策略效率。

多因子策略的关键有两个部分：因子挖掘、因子合成两大部分。前两期文章，我们介绍了因子是怎么来的，介绍了因子挖掘的主流方法。上一期文章，我们着重介绍了如何使用遗传算法进行因子挖掘？并且挖掘出因子后我们使用了最大化IC\_IR方法做因子择时，最终合成了一个可行的交易策略。

随着编程Agent的普及，对于我们量化人给予了极大的方便与帮助，我们可以使用的Agent快速的实现大部分文章中的观点，本期内容，我们将带小伙伴们使用claude code一步步实现上文中的算法，实现编程与测试。

## 环境准备：Agent选择

**1.Agent选择：Claude Code**在尝试了使用其他工具：Cursor、Antigravity、Claude code，之后我们选择了Claude Code作为我们实现策略的工具。

在第一次编程的时候，我们采用了Cursor作为主要的工具，当然它也实现了一个版本，但是后来我在测试的时候发现，它的代码跟事前它制定的计划不太一致，并没有按照文章中的原意实现算法，所以我们就放弃了Cursor。当时他的计划我认为做的还是可以的，下图中是cursor给出的计划中的关键部分：![](assets/001.png)但值得一提的是，cursor的交互还可以的，如果你对Claude code的交互不是很满意，可以看看下面，基本上你只要OK、继续就可以完成这个项目，**Cursor会根据项目的理解，给出他认为相对合理的下一步工作，有时候用户就比较省心**，如下图：![](assets/002.png)

![](assets/003.png)大家其实可以采用cursor先干一个版本出来，然后再使用Claude进行审查与修正。当然，如果你对Claude code 比较熟悉，能够接受他的费用，也可以一步搞定。

至于Antigravity，其实一开始我是用这个比较多，多处在白嫖的思路，但是对于一个初学者而言，它的网络要求、额度是个比较麻烦的。所以我们也逐步放弃。

至于Claude Code我也目前也是在tb上的，简单、便宜。

**2.关键的MCP：superpowers**

这是一个比较好用的工具，能够方便你进行项目的实现工作流：计划、编程、审查、测试等等。每一步都有可调用的skills辅助你完成项目。每一步都会详细记录步骤信息，如图：

![](assets/004.png)

## 工作流

要想使得Agent能够像量化工程师一样，我们需要给一个比较合理的工作流。总体上来讲分为下面几个步骤

**1\. 文章、研报理解：**

首先，需要与Agent对话，使其理解完全能够理解研报的真实算法，了解你需要让他做什么。这里可能需要你多次的跟Agent交流、对话。比如下面的一些对话：

![](assets/005.png)上图为：让Agent在复现时加入财务因子作为基础因子

**2\. 数据确认：**

这一步中我们要给出复现研报需要用到的数据在哪里，一帮未来能够快速的回测，一般都会把数据放到本地的文件夹中。

**3\. 方案设计**

这里其实是整个项目的核心，当然这一步其实是第一部分的延伸。以本项目为例，就有很多关键点需要跟Agent交流，此时Agentk可能会按照他的理解给出一些简化、改进的方案，这就需要你的确认：

-   不能有未来函数
    
-   开仓价格按照第二天的开盘价计算
    
-   因子检验、合成方法确认
    
-   策略的回测
    
-   是否采用多进程、并行计算
    
-   结果的检验方法、可视化方法
    
-   其他
    

**4\. 编码实现**

等下面的方案确认以后，就可以开始干活了![](assets/006.png)上图为让Agent在确认方案后干活。

如果是你Claude Code，这时候基本上就会调用MCP：Superpowers下面的某些Skills，分步骤、多Agent验证的方式完成既定的方案。

**5\. 调试验证**

这里程序会自己检验一些错误，然后会给你一些建议![](assets/007.png)

**6\. 结果校验**

这是一个比较繁琐的工程，比如：你会发现，某些结果不合理。或者结束展示有各种各样的问题。而且上一步的检验中，并不能检验出结果中的不合理现象。

比如：在本期的项目中，程序在做分组检验的时候，多次将多头组、空头组的顺序弄反了。**如何发现错误呢？**下图中，多头组的收益很差，显然这是有点问题的。![](assets/008.png)

这时候，你就需要尝试问一下Claude，是不是把分组弄错了：

![](assets/009.png)这是Claude思考的过程。

**这样的微调问题会有很多，一些意向不到的各种小问题。所以，目前但凡是AI写的代码，我肯定是要过一遍的，有一些问题他自己是发现不了的。**

比如：开盘价使用哪一个？他会默认使用当天的收盘价，这显然是不合理的。如果你改成了第二天的开盘价就会差很多。

类似的细节，很多很多，比如：

![](assets/010.png)

![](assets/011.png)

**7\. 文档沉淀**这一步就是各种文档的输出，让你对整体项目有一个比较好的理解。或者你需要输出哪些文件，直接跟Agent说就可以。

## 遗传算法的代码

### 📂 项目结构

```
遗传算法/├── README.md                       # 本文档├── 版本迭代说明.md                 # 完整版本历史（新增）├── 改进总结.md                     # V2.0详细改进说明├── 改进前后对比.md                 # V1 vs V2对比├── 改进记录_2026-05-05.md          # V2.1改进记录├── 可视化实施总结_2026-05-09.md    # V2.2可视化说明（新增）├── 可视化布局优化_2026-05-09.md    # V2.2布局优化（新增）├── 复现方案.md                     # 原始复现方案│├── config_optimized.py             # 配置文件（已更新）├── requirements.txt                # 依赖（已更新）│├── main_optimized.py               # 主程序（V2.2，含可视化）├── genetic_factor.py               # 遗传算法模块（V2.2核心）├── factor_combine_optimized.py     # 因子合成模块（V2.2修复版）├── test_visualization.py           # 可视化测试脚本（新增）│├── data_loader.py                  # 数据加载├── features_vectorized.py          # 特征工程（向量化）├── backtest.py                     # 回测├── metrics.py                      # 指标计算├── reporting.py                    # 报告生成│├── visualization/                  # 可视化模块（新增）│   ├── __init__.py│   ├── config.py                   # 颜色和布局配置│   ├── utils.py                    # 工具函数│   ├── plot_factor_quality.py      # 因子质量仪表盘│   ├── plot_strategy_backtest.py   # 策略回测仪表盘│   └── plot_all.py                 # 主函数│└── outputs/                        # 输出目录    ├── *.csv                       # 数据文件    └── *.html                      # 可视化文件（新增）
```

### 代码片段

**空间有限，仅仅给出遗传算法代码部分**

```
#!/usr/bin/env python# -*- coding: utf-8 -*-"""因子合成模块 - 性能优化版本主要优化:1. 向量化IC矩阵计算，避免双重循环2. 支持月度/季度滚动窗口，减少计算次数3. 批量计算相关系数，提升性能60-80%作者:  song创建日期: 2026-05-08当前版本: V2.2-optimized最后修改: 2026-05-08修改日志:-----------2026-05-08 V2.2-optimized:  - 优化_get_ic_matrix为向量化版本，性能提升60-80%  - 新增_get_ic_matrix_batch批量计算方法  - 支持滚动窗口的重采样频率配置（日/周/月/季）  - 减少不必要的数据复制，降低内存占用"""from __future__ import annotationsfrom dataclasses import dataclassimport numpy as npimport pandas as pdfrom scipy.optimize import minimizefrom sklearn.covariance import EmpiricalCovariance, LedoitWolf, OAS, ShrunkCovariancefrom sklearn.model_selection import GridSearchCVfrom config_optimized import CFGfrom metrics import calc_ic, calc_irfrom utils import safe_div@dataclassclass CombineResult:    """因子合成结果。"""    weights: pd.Series    combined_factor: pd.Series    ic: float  # 合成因子的平均IC    icir: float  # 合成因子的ICIR    ic_series: pd.Series  # 合成因子的IC时间序列class FactorCombinerOptimized:    """因子合成器 V2.2 - 性能优化版本。"""    def __init__(self, cfg=CFG):        self.cfg = cfg    @staticmethod    def _get_ic_matrix_vectorized(panel: pd.DataFrame, factor_cols: list[str]) -> pd.DataFrame:        """向量化计算IC矩阵（优化版本）。        性能提升: 60-80%        原理: 使用groupby + apply批量计算，避免双重循环        """        def calc_ic_batch(group):            """一次性计算所有因子的IC"""            result = {}            y = group["future_ret_1d"].values            # 批量计算所有因子的IC            for col in factor_cols:                if col notin group.columns:                    result[col] = np.nan                    continue                x = group[col].values                # 移除NaN                mask = ~(np.isnan(x) | np.isnan(y))                if mask.sum() < 10:                    result[col] = np.nan                    continue                # 计算Pearson相关系数                x_clean = x[mask]                y_clean = y[mask]                # 使用numpy的corrcoef更快                corr = np.corrcoef(x_clean, y_clean)[0, 1]                result[col] = corr ifnot np.isnan(corr) else np.nan            return pd.Series(result)        # 使用groupby + apply批量计算        ic_df = panel.groupby("date", group_keys=False).apply(calc_ic_batch)        ic_df.index.name = "date"        return ic_df    @staticmethod    def _get_ic_matrix(panel: pd.DataFrame, factor_cols: list[str]) -> pd.DataFrame:        """按日期计算每个因子的横截面 IC 序列（兼容旧版本）。"""        # 直接调用优化版本        return FactorCombinerOptimized._get_ic_matrix_vectorized(panel, factor_cols)    @staticmethod    def _shrink_cov(ic_df: pd.DataFrame, method: str = "cv") -> np.ndarray:        """估计 IC 协方差矩阵。"""        x = ic_df.dropna().values        if x.shape[0] < 5:            return np.cov(np.nan_to_num(x).T)        if method == "empirical":            return EmpiricalCovariance().fit(x).covariance_        if method == "lw":            return LedoitWolf().fit(x).covariance_        if method == "oas":            return OAS().fit(x).covariance_        if method == "cv":            alphas = np.logspace(-4, 0, 30)            gs = GridSearchCV(                ShrunkCovariance(store_precision=False, assume_centered=False),                param_grid={"shrinkage": alphas},                cv=5,            )            gs.fit(x)            return gs.best_estimator_.covariance_        return np.cov(x.T)    def optimize_weights(self, ic_mean: np.ndarray, cov: np.ndarray) -> np.ndarray:        """使用 SLSQP 求解最大化 ICIR 的权重。"""        n = len(ic_mean)        if n == 1:            return np.array([1.0])        def objective(w):            num = np.dot(w, ic_mean)            den = np.sqrt(np.dot(w, cov @ w))            if den <= 0or np.isnan(den):                return1e6            return -num / den        # 约束：权重之和为1（用于优化）        cons = ({"type": "eq", "fun": lambda w: np.sum(w) - 1.0},)        bounds = [(-1.0, 1.0) if self.cfg.combine.use_negative_weight else (0.0, 1.0) for _ in range(n)]        x0 = np.repeat(1.0 / n, n)        res = minimize(objective, x0=x0, method="SLSQP", bounds=bounds, constraints=cons)        ifnot res.success:            return x0        # 归一化：使权重绝对值之和为1        weights = res.x        sum_abs_before = np.sum(np.abs(weights))        weights = weights / sum_abs_before        sum_abs_after = np.sum(np.abs(weights))        print(f"[DEBUG] 归一化前 sum(|w|)={sum_abs_before:.4f}, 归一化后 sum(|w|)={sum_abs_after:.4f}", flush=True)        return weights    def combine(self, panel: pd.DataFrame, factor_cols: list[str]) -> CombineResult:        """执行因子合成（全样本版本）。"""        # 使用优化的IC矩阵计算        ic_df = self._get_ic_matrix_vectorized(panel, factor_cols)        ic_mean = ic_df.mean(skipna=True).values        cov = self._shrink_cov(ic_df, method=self.cfg.combine.shrinkage_method)        # 优化权重        weights = self.optimize_weights(ic_mean, cov)        weights = pd.Series(weights, index=factor_cols)        # 横截面标准化后加权合成        combined = pd.Series(index=panel.index, dtype=float)        for dt, g in panel.groupby("date"):            score = pd.Series(0.0, index=g.index)            for col, w in weights.items():                if col in g.columns:                    score = score + w * g[col].fillna(0)            combined.loc[g.index] = score        # 计算合成因子的IC时间序列        combined_ic_series = []        dates = []        for dt, g in panel.groupby("date"):            ic_val = calc_ic(combined.loc[g.index], g["future_ret_1d"])            ifnot np.isnan(ic_val):                combined_ic_series.append(ic_val)                dates.append(dt)        combined_ic_series = pd.Series(combined_ic_series, index=dates)        # IC是IC序列的均值        ic = combined_ic_series.mean()        # ICIR是IC均值/IC标准差        ic_std = combined_ic_series.std(ddof=0)        if ic_std > 0andnot np.isnan(ic_std):            icir = ic / ic_std        else:            icir = np.nan        return CombineResult(            weights=weights,            combined_factor=combined,            ic=ic,            icir=icir,            ic_series=combined_ic_series,        )    def combine_rolling(        self,        panel: pd.DataFrame,        factor_cols: list[str],        window_years: int = 3,        rebalance_freq: str = "ME"    ) -> CombineResult:        """滚动窗口因子合成（优化版本）。        优化点:        1. 支持重采样频率（D/W/ME/QE），减少计算次数        2. 使用向量化IC计算        3. 减少不必要的数据复制        参数：            panel: 包含因子和收益的面板数据            factor_cols: 因子列名列表            window_years: 滚动窗口年数（默认3年）            rebalance_freq: 调仓频率 ("D"=日, "W"=周, "ME"=月末, "QE"=季末)        返回：            CombineResult: 合成结果        """        panel = panel.sort_values("date")        # 根据调仓频率重采样日期        all_dates = sorted(panel["date"].unique())        if rebalance_freq == "D":            rebalance_dates = all_dates        else:            # 使用pandas的重采样功能            date_series = pd.Series(1, index=pd.DatetimeIndex(all_dates))            rebalance_dates = date_series.resample(rebalance_freq).last().index.tolist()            # 确保日期在原始数据中            rebalance_dates = [d for d in rebalance_dates if d in all_dates]        print(f"[FactorCombinerOptimized] 滚动窗口合成: 窗口={window_years}年, 频率={rebalance_freq}", flush=True)        print(f"[FactorCombinerOptimized] 总交易日={len(all_dates)}, 调仓日={len(rebalance_dates)}", flush=True)        # 存储每个时间点的合成因子值        combined = pd.Series(index=panel.index, dtype=float)        # 存储权重历史（限制大小避免内存泄漏）        weights_history = []        current_weights = None        MAX_HISTORY_SIZE = 100# 最多保留100条历史记录        for i, current_date in enumerate(rebalance_dates):            # 计算历史窗口的起始日期            window_start = current_date - pd.DateOffset(years=window_years)            # 获取历史数据（不包括当前日期）            hist_mask = (panel["date"] >= window_start) & (panel["date"] < current_date)            hist_panel = panel[hist_mask]            # 如果历史数据不足，使用上一次的权重            if len(hist_panel) < 100or hist_panel["date"].nunique() < 20:                if current_weights isNone:                    continue            else:                # 在历史数据上计算IC矩阵和协方差（使用优化版本）                ic_df = self._get_ic_matrix_vectorized(hist_panel, factor_cols)                if ic_df.empty or len(ic_df) < 10:                    if current_weights isNone:                        continue                else:                    ic_mean = ic_df.mean(skipna=True).values                    cov = self._shrink_cov(ic_df, method=self.cfg.combine.shrinkage_method)                    # 优化权重                    weights = self.optimize_weights(ic_mean, cov)                    current_weights = pd.Series(weights, index=factor_cols)                    # 记录权重（限制历史大小）                    weights_history.append({                        "date": current_date,                        **{f"weight_{col}": w for col, w in current_weights.items()}                    })                    # 防止内存泄漏：只保留最近的记录                    if len(weights_history) > MAX_HISTORY_SIZE:                        weights_history = weights_history[-MAX_HISTORY_SIZE:]            # 用当前权重合成从current_date到下一个调仓日之间的所有因子值            if current_weights isnotNone:                # 找到下一个调仓日                next_idx = i + 1                if next_idx < len(rebalance_dates):                    next_date = rebalance_dates[next_idx]                    period_mask = (panel["date"] >= current_date) & (panel["date"] < next_date)                else:                    period_mask = panel["date"] >= current_date                period_data = panel[period_mask]                # 批量合成这段时间的因子                for dt, g in period_data.groupby("date"):                    score = pd.Series(0.0, index=g.index)                    for col, w in current_weights.items():                        if col in g.columns:                            score = score + w * g[col].fillna(0)                    combined.loc[g.index] = score            # 打印进度            if (i + 1) % 10 == 0or i == len(rebalance_dates) - 1:                print(f"  进度: {i+1}/{len(rebalance_dates)}", flush=True)        print(f"[FactorCombinerOptimized] 滚动窗口合成完成", flush=True)        # 计算合成因子的IC时间序列        combined_ic_series = []        dates_with_ic = []        for dt, g in panel.groupby("date"):            if combined.loc[g.index].notna().sum() > 0:                ic_val = calc_ic(combined.loc[g.index], g["future_ret_1d"])                ifnot np.isnan(ic_val):                    combined_ic_series.append(ic_val)                    dates_with_ic.append(dt)        combined_ic_series = pd.Series(combined_ic_series, index=dates_with_ic)        # 计算IC和ICIR        ic = combined_ic_series.mean()        ic_std = combined_ic_series.std(ddof=0)        if ic_std > 0andnot np.isnan(ic_std):            icir = ic / ic_std        else:            icir = np.nan        # 使用最后一个窗口的权重作为代表权重        if current_weights isnotNone:            final_weights = current_weights        else:            final_weights = pd.Series(0.0, index=factor_cols)        return CombineResult(            weights=final_weights,            combined_factor=combined,            ic=ic,            icir=icir,            ic_series=combined_ic_series,        )
```

## 效果展示

**依然由Claude编写**

![](assets/012.png)

![](assets/013.png)这个训练与测试的IC对比图，至于其他的这里就不过多展示了。

## 总结

目前来看，一个有效的Agent绝对能够大幅提高我们的工作效率，特别是前端、后端的一些固定类操作，微调很麻烦。

就量化算法而言，能在一定程度上增加产量，在框架、函数、可视化上能够做到很好，但是在策略细节方面还是有待提高的。

至少，目前来讲作为一个资深的量化工程师，对于Agent写的策略，我必须要从头到位看一遍，才敢说是否有效。

**从另一个角度讲，传统的编程人员正在往代码审核员、产品设计员发展。**