# 多因子合成“剔除法”中比例、顺序的自动识别算法——原理、代码

蝴蝶量化 随率而动的因子工厂 2026-04-18 08:21 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484585&idx=1&sn=5f0ea072c33b1adecf7e98fe67fd2736&chksm=c0f41cb907e5752322b80b28c1385eb4d56279e5f37b25ba4620239604a66e839e97e6ca0997#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484585&idx=1&sn=5f0ea072c33b1adecf7e98fe67fd2736&chksm=c0f41cb907e5752322b80b28c1385eb4d56279e5f37b25ba4620239604a66e839e97e6ca0997#rd)

## 引言（技术背景）

之前的文章中，介绍了采用“特征分析”方法，筛选多因子策略中需要保留有效因子、剔除无效因子？其中一个比较重要的概念：“有效分组”。通过有效分组的定义，就能够清楚的知道：**它给出了因子分组中，哪些分组是有效的？**

回顾一下，我们之前介绍的：因子IC不满意的处理办法中，有一中方法：**空头剔除法**。如果你的因子IC的贡献主要来源于空头组的贡献，那么这种方法给出了一个很好的处理方法。同样，有几个关键的问题：

-   1、哪些因子需要采用空头剔除法？
    
-   2、理论上剔除比例是多少？
    
-   3、多因子策略中，筛选顺序如何？
    

关于第一个问题，我们在之前的文章中，给出了大量的介绍与方法，本文就不过多介绍。第2、3两个问题，将是本文将会讨论的重点

## 剔除比例

### 案例解析

多因子策略中，大部分的因子IC、分组收益表现其实并没有想象中那么好。很多情况IC偏高主要是源于空头组的股票收益率太低，导致了IC整体绝对值偏高。例如：下面的这个因子分组表现与IC

**布林线下轨指标**![](assets/001.png)显然，其IC高达0.04，但是可以明显的看到其分组表现除了最小分组明显小于其他分组外，其他分组的单调性并没有那么明显。**这种因子在构造策略时，一般就采用空头剔除法。** 从分组中我们可以看出来这个因子的剔除后20%即可，那么实时真的如此吗？

### 算法回顾

#### 有效分组概念

将股票根据因子排序分为N档，计算过去一年第i个分界线之前所有股票组合相对全部股票超额收益信息比 。

则因子的 **有效分档** 的定义为：

且

这里参数0.8为一个经验值，因子多空信息比若大于0.8，通常来说该因子有效性及单调行均较好；而参数0.5则意味着当因子有效性衰竭为一半时，通常应该考虑该因子是否应该继续使用。

#### 策略回顾

我们从之前的一个策略入手，先看策略代码：

```
# 筛选peg，挑选出前10%df = df[df['peg'] > 0].copy()df.sort_values(by='peg', ascending=True, ignore_index=True, inplace=True)df = df.head(int(0.10 * len(df.index)))# ebit，挑选出前25%df = df[df['ebit'] > 0]df.sort_values(by='ebit', ascending=True, ignore_index=True, inplace=True)df = df.head(int(0.25 * len(df.index)))# 计算turnover_volatility,计算过去20天的换手率的标准差# 获取过去45天的交易数据，保证其中必须有20个交易日df.sort_values(by='turnover_volatility', ascending=True, inplace=True)df = df.head(int(0.5 * len(df.index)))
```

代码中的算法逻辑：

-   peg >0 ,取前小值10%。
    
-   ebit> 0,取前小值25%
    
-   turnover\_volatility 取小值前50%。
    

#### 改进后代码

我们通过之前算法中滚动计算过于一年中因子的有效分组，根据这个有效分组的比例进行筛选股票。

**在实际的应用中，你会发现：** 因子有正向因子、反向因子，这就导致因子的有效分组就是需要从大到小或者从小到大，我们这里采用了两个版本：全局固定方法、动态变化权重的方式，这里仅仅介绍全局方向固定的方法。这里有几个比较重要的点：

-   **因子的正、反向**
    

**上一期的代码中，我们仅仅给了正向因子的有效分组的计算方法，** 本期程序我对原始策略中ascending参数进行判断，如果正序，说明时反向因子，越小越好。**对因子值取负值后再进行计算有效分组**

```
# 处理因子极性：ascending=True 表示越小越好，取负使其变为越大越好if cfg.get('ascending', True):    panel = -panel
```

-   **是否需要其他筛选,比如:peg>0**
    

这是一个比较关键的坑点，如果没有筛选那么很好不需要处理。一旦需要做一些与处理，那么如果直接计算“有效分组区间”就会导致这个有效分组为“全局有效分组”，但是实际筛选的时候却用在“PEG>0”这个局部的股池中，这就导致:**有效分档"计算空间"与实际"筛选空间"不一致的算法缺陷**,修正代码如下：

```
val_filter = cfg.get('value_filter', None)if val_filter == 'gt_zero':    panel = panel.where(panel > 0)  # ≤0 置为NaNelif val_filter == 'lt_zero':    panel = panel.where(panel < 0)  # ≥0 置为NaN
```

**策略中计算有效分组的代码：**

```
# ======================== v4: 滚动有效分档计算方法 ========================def _calculate_rolling_effective_fractions(self, df_factor: pd.DataFrame):    """    v4新增：滚动计算各选股因子的有效分档比例。    算法说明：    1. 从 df_factor 中提取收益率面板（使用 pct_change 列）和各筛选因子面板。    2. 对每个 filter_date，取过去 lookback_days 天的数据窗口。    3. 调用 EffectiveFractionCalculator 计算各因子的有效分档 F_i。    4. 筛选比例 = F_i / n_bins，并限制在 [min_ratio, max_ratio] 范围内。    5. 如果因子无效（F_i > n_bins），则使用默认比例。    注意：    - 因子极性处理：对于 ascending=True（越小越好）的因子，在计算有效分档时取负值，      使其符合 EffectiveFractionCalculator 的"越大越好"假设。    - 收益率使用 T+1 对齐：factor[T] 对应 return[T+1]，通过 shift(-1) 实现。    :param df_factor: 全量因子数据, multiIndex: (date, stock_code)    """    self.lg.info("============== v4: 开始滚动计算各因子有效分档 ==============")    # 获取需要计算的选股日期列表    filter_dates = sorted(self.df_trade_filter_date['need_filter_date'].dropna().tolist())    # 提取收益率面板: index=date, columns=stock_code    if'pct_change'in df_factor.columns:        returns_panel = df_factor['pct_change'].unstack('stock_code') / 100.0# 转化为小数    elif'close_fq'in df_factor.columns:        close_panel = df_factor['close_fq'].unstack('stock_code')        returns_panel = close_panel.pct_change()    else:        self.lg.warning("v4: 无法获取收益率数据(pct_change/close_fq均不存在)，"                        "所有因子使用默认筛选比例！")        for _filter_date in filter_dates:            self.rolling_eff_fractions[_filter_date] = {                cfg['factor_name']: cfg['default_ratio']                for cfg in self.filter_factor_configs            }        return    # 将收益率向前移一天，使 factor[T] 对应 return[T+1]    returns_shifted = returns_panel.shift(-1)    returns_shifted.dropna(how='all', inplace=True)    # 提取各因子面板    factor_panels = {}    for cfg in self.filter_factor_configs:        f_name = cfg['factor_name']        if f_name notin df_factor.columns:            self.lg.warning(f"v4: 因子 [{f_name}] 不在 df_factor 中，使用默认比例！")            continue        panel = df_factor[f_name].unstack('stock_code')        # v4.0+方案E: value_filter预过滤，使有效分档计算空间=实际筛选空间        # 注意：必须在取负之前做，因为value_filter是对原始因子值的约束        val_filter = cfg.get('value_filter', None)        if val_filter == 'gt_zero':            panel = panel.where(panel > 0)  # ≤0 置为NaN        elif val_filter == 'lt_zero':            panel = panel.where(panel < 0)  # ≥0 置为NaN        # 处理因子极性：ascending=True 表示越小越好，取负使其变为越大越好        if cfg.get('ascending', True):            panel = -panel        factor_panels[f_name] = panel    # 对每个选股日期，滚动计算有效分档    all_dates = sorted(returns_panel.index.tolist())    for _filter_date in filter_dates:        _filter_date_pd = pd.to_datetime(_filter_date)        date_fractions = {}        for cfg in self.filter_factor_configs:            f_name = cfg['factor_name']            default_ratio = cfg['default_ratio']            if f_name notin factor_panels:                date_fractions[f_name] = default_ratio                continue            # 获取回看窗口数据            # 找到 <= filter_date 的所有日期            lookback_dates = [d for d in all_dates if pd.to_datetime(d) <= _filter_date_pd]            if len(lookback_dates) < max(60, self.eff_n_bins * 3):                # 历史数据不足，使用默认比例                date_fractions[f_name] = default_ratio                self.lg.info(f"v4: {_filter_date} 因子[{f_name}] 历史数据不足"                             f"({len(lookback_dates)}天)，使用默认比例 {default_ratio}")                continue            # 截取回看窗口            window_dates = lookback_dates[-self.eff_lookback_days:]            factor_window = factor_panels[f_name].loc[                factor_panels[f_name].index.isin(window_dates)            ]            returns_window = returns_shifted.loc[                returns_shifted.index.isin(window_dates)            ]            if factor_window.empty or returns_window.empty:                date_fractions[f_name] = default_ratio                continue            # 计算有效分档            try:                eff_f = self.eff_calculator.compute_effective_fraction(                    factor_hist=factor_window,                    stock_returns=returns_window                )            except Exception as e:                self.lg.warning(f"v4: {_filter_date} 因子[{f_name}] "                                f"有效分档计算异常: {e}，使用默认比例")                date_fractions[f_name] = default_ratio                continue            # 转换为筛选比例            if eff_f <= self.eff_n_bins:                # 因子有效，比例 = 有效分档数 / 总分档数                ratio = eff_f / self.eff_n_bins                # 限制在合理范围内                ratio = max(self.eff_min_ratio, min(self.eff_max_ratio, ratio))                date_fractions[f_name] = ratio                self.lg.info(f"v4: {_filter_date} 因子[{f_name}] "                             f"有效分档 F_i={eff_f}, 筛选比例={ratio:.2%}")            else:                # 因子无效，使用默认比例                date_fractions[f_name] = default_ratio                self.lg.info(f"v4: {_filter_date} 因子[{f_name}] "                             f"无效(F_i={eff_f}), 使用默认比例 {default_ratio}")        self.rolling_eff_fractions[_filter_date] = date_fractions    self.lg.info("============== v4: 有效分档滚动计算完毕 ==============")    # 保存有效分档结果到文件，方便后续分析    eff_records = []    for dt, fracs in self.rolling_eff_fractions.items():        record = {'date': dt}        record.update(fracs)        eff_records.append(record)    if eff_records:        df_eff = pd.DataFrame(eff_records)        df_eff.sort_values('date', inplace=True, ignore_index=True)        eff_file = self.output_dir + '/effective_fractions_rolling.csv'        df_eff.to_csv(eff_file, index=False)        self.lg.info(f"v4: 有效分档结果已保存至 {eff_file}")# ======================== v4: 滚动有效分档计算方法结束 ========================
```

## 剔除顺序

这是另一个比较重要的问题，无论顺序如何都会导致一个问题，就是在前面的因子通过“有效分组”筛选后，都会对后面的因子的筛选空间产生极大的影响，同样会导致：**有效分档"计算空间"与实际"筛选空间"不一致的算法缺陷。**

为了解决上面的问题，我们给出了下面的方案：**选股筛选从"级联筛选"改为"独立并行筛选 + 取交集"，消除因子筛选的顺序依赖。** 也就是说，我们对所有的因子筛选时都在原始空间上进行，对剩下的股票做交集，得到预选股票。

## 最终代码：

**筛选的最终逻辑**

```
# 获取当前日期的有效分档比例（如果没有计算结果则使用默认值）date_fractions = self.rolling_eff_fractions.get(filter_date, {})# 每个因子独立筛选，收集各因子选出的股票代码集合factor_selected_sets = []for cfg in self.filter_factor_configs:    f_name = cfg['factor_name']    default_ratio = cfg['default_ratio']    ascending = cfg.get('ascending', True)    val_filter = cfg.get('value_filter', None)    # 获取动态比例，没有则使用默认值    ratio = date_fractions.get(f_name, default_ratio)    # 每个因子独立在全量df上操作（不修改df本身）    df_subset = df.copy()    # value_filter 过滤（与有效分档计算的空间一致）    if val_filter == 'gt_zero':        df_subset = df_subset[df_subset[f_name] > 0]    elif val_filter == 'lt_zero':        df_subset = df_subset[df_subset[f_name] < 0]    if df_subset.empty:        self.lg.warning(f'{filter_date} 因子[{f_name}] value_filter({val_filter})过滤后数据为空！')        factor_selected_sets.append(set())        continue    # 按因子排序并截取前 ratio 比例    df_subset = df_subset.sort_values(by=f_name, ascending=ascending, ignore_index=True)    n_total = len(df_subset)    n_keep = max(1, int(ratio * n_total))    selected_codes = set(df_subset.head(n_keep)['stock_code'].tolist())    factor_selected_sets.append(selected_codes)    self.lg.info(f"v4: {filter_date} 因子[{f_name}] "                 f"比例={ratio:.2%}, 空间={n_total}只, 选出={n_keep}只")
```

从本文开始，我们将不展示完全代码，所有代码我们将会在之后星球中发布。

## 结果对比

**程序运行明细**

![](assets/002.png)

**改进前后**

![](assets/003.png)

## 总结

对于这样的需要筛选的因子，当你读懂了本文之后，再也不需要根据自己的经验取判断到底需要筛选多少比例，应该怎么筛选。

本文给出了一种自动识别、自动调整比例、自动识别因子方向的方法，可以大大提高因子的自适应性。