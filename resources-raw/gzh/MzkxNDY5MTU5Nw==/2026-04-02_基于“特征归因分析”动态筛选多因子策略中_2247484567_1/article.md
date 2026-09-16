# 基于“特征归因分析”动态筛选多因子策略中的底层因子——原理、算法、代码

蝴蝶量化 随率而动的因子工厂 2026-04-02 15:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484567&idx=1&sn=4d9be6b98344d650f903af168c63b645&chksm=c0c2ae8901917fb3383d9065353b875a9d91845b2496a140ecb9891045f015711122f0f72877#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484567&idx=1&sn=4d9be6b98344d650f903af168c63b645&chksm=c0c2ae8901917fb3383d9065353b875a9d91845b2496a140ecb9891045f015711122f0f72877#rd)

## 引言（技术背景）

作为一名资深的多因子策略交易员、研究员、使用者，你一定会发现：无论多优秀的因子一定有：**有效期、失效期**。在有效期的因子会增加整个策略的超额收益，同样处在失效期的因子一定会拖累整个组合的收益。至于是不是失效，这不是因子决定的，而是市场决定的，所以如果有人跟你说他的因子有多牛逼，从来不会失效，你就知道其必定大概率是个“半桶水”。

既然如此，一个很现实的问题就摆在眼前：**如何在策略运行过程中动态调整构造多因子策略的基础因子？**

介绍一个比较重要的概念：**“特征归因”**。在做单因子策略的时候，一般挑选因子值（因子暴露）较大的组合作为超配（多头）组，因子值比较小的作为低配（空头）组。那么，，在多因子策略中，多头足中的股票组合由很多因子共同决定，可能跟单个因子的多头组由天差地别。**那么，如何判断单因子是否对组合有贡献呢？** 这里引入**单因子有效分组区域**，具体看下一章：问题分析。通过判断最终的多因子持仓组合是否在该因子的有效分组区域内，来判断该单因子是否对多因子组合起到了积极作用。

本文将从:**问题分析** -> **分步实现** -> **结果验证** -> **代码分析**等方面介绍一个解决这个问题的常用算法。重点是思考逻辑，至于算法可以说条条大路通罗马。具体算法参考了券商的研报。

## 问题分析

对于本文中问题，我们最原始一种思考：**在未来一段时间内，哪些因子可能表现比较好，提供的alpha比较高？哪些因子提供的alpha表现比较差？** 只要解决了上面的问题，我们就知道应该剔除、增加哪些因子。

### 因子检验基础

这里你肯定会有问题：**未来因子好与不好没办法准确预估。** 这是当然，一般来讲我们寻找的因子在稳定性上，都有一定的要求，如果因子的收益很不稳定，那肯定不能作为一个有因子进入模型。所以，我们认为在过去某一段时间内表现不错的因子，在未来一段时间内依然表现较好。也就是**用过去一段时间的因子表现作为未来的一种预估，** 至于这种预估也有评价其有效性的方法。

第一步：了解如何评判因子是否有效？我们回顾一下因子有效性的一些检验方法：

-   **截面上IC、ICIR、IC\_mean**: 定义可以查看往期文章或者deepseek，它们可以让你很明确的看出因子在每一个截面的选股能力，以及IC序列可以看IC是否稳定等等。
    
-   **因子收益**：因子收益通过因子截面回归可以计算得到，它反映了收益中的有多少来源于因子。也是因子提供alpha的一种验证。
    
-   **分组收益：** 多空超额收益，体现了因子分层能力。
    

显然，上面都是线性模型中验证因子有效性的方法。当然在归因分析中，我们可能更加注重于投资组合内部而不是全量的验证。具体看往期文章。

### 特征归因分析

在做单因子策略的时候，我们一般挑选因子值（因子暴露）较大的组合作为我们的超配（多头）组，因子值比较小的作为低配（空头）组。

但多因子组合中，**最终的多头组是由加权后的因子值得到**，至于这个股票组合是否还是在单因子的多头组当中，这就不得而知，大概率是**太差地别**。

当然，如果仅仅是考量是否在某单因子多头组这一个单一组合中肯定是不合理的。范围太窄，由于组合中股票数量基本一致，引入其他因子，必然是想提高一下多头组中的组合收益，必然会改变多头组中的股票。所以**必须要扩大单因子中组别的范围。**

为了解决这个问题，我们定义另一个概念：**因子有效分组区间**。单因子组合通常反映了在该因子上暴露最高的一篮子股票，位于分档中的第1档，那么如果前2档，或者前i档到底还能否产生显著的超额收益呢？

将股票根据因子排序分为N档，计算过去一年第i个分界线之前所有股票组合相对全部股票超额收益信息比 。

则因子的 **有效分档** 的定义为：

且

这里参数0.8为一个经验值，因子多空信息比若大于0.8，通常来说该因子有效性及单调性均较好；而参数0.5则意味着当因子有效性衰竭为一半时，通常应该考虑该因子是否应该继续使用。

注意，这里有两个关键s点：**稳定、显著超额。** 为了看到稳定性，那么就需要滚动计算某固定区间的超额收益，如果一个因子找不到这样的区间，那么基本上这个因子也不是有效因子。

现在，只要多因子策略的**多头组**，在该单因子平均因子暴露（因子值）在“有效分组区间”的因子值范围内，我们则认为该单因子对多因子策略做出了积极贡献，可以保留。反之，则应该剔除。

另外，这样的剔除方法，需要做多次，因为做了一次以后，由于**原始因子**发生了变化，就会导致组合的多头组发生变化，这就会导致原来的归因结果发生偏差。需要再一次做**特征归因分析**。直到**组合的多头组在全部的单个因子都满足在其有效组合中**。

**至此，你应该了解了本文的主要算法内容。** 当然，对于我们量化人而言，需要思考一个问题：**如果由10个因子，那么可以通过这些因子各自的有效组合通过交叉取交集，是否能够直接构造一个多因子？** 先说答案：我认为是可以的，之前文章里介绍的空头剔除法，其实就是这方法的一种特殊情况：踢掉一半。掌握这个算法，你可以精确到计算一个因子的剔除比例，使得算法更有说服力。**由于不是本文的主要内容，具体算法设计我们放到下一篇中**

## 算法、策略原理及步骤

本算法里面的时间窗口以**1年**为基准。

### 基础版本V1——循环调整

**1、构建初始因子**

既然我们由因子检验的各种指标，那么第一步就是从一堆因子中，初步挑选出IC表现排名的N个因子。当然，这里可以将一些去除**共线性**的算法加进去。

**2、计算入选因子的有效分组区间**

通过有效分组区间的基本上算法，分别找出这些因子的有效分区间。这里可能会有一个疑问：**这些因子的区间有可能出现跳跃吗？** 比如：1、2、4、7组的因子分组为有效区间。其实，在实际操作过程中，这种情况也是经常出现。

但是，其实这里不需要过多的担心，因为有了第一步的筛选后，IC比较大的因子，一般来讲，这样的因子分组单调性还是不错的。而且我们**以间断的第一组作为有效分组。** 比如，上面我们就以2分组作为有效分组最大区间。

**3、循环做特征归因分析**

根据每一期的多因子截面选股情况，做本步骤中的算法，计算多因子多头组在各个单因子中的平均因子暴露，根据这个平均因子暴露所在的单因子分组范围，计算出其**实际分组**

-   如果“实际分组” < “有效分组”，则为有效因子，继续保留。
    
-   如果 “实际分组” > “有效分组”，则为为无效因子，需要剔除。
    

对得到新因子组合继续上面的特征归因分析，如果依然存在无效因子继续剔除，直到所有因子全部满足条件。

![](assets/001.png)

### 进阶版本V2——动态调整

为了避免了简单粗暴地剔除所有“失效”因子,或者剔除过多的因子，我们增加了因子复活机制，保留了对整体**有效得分**有贡献的因子。

基础版本中通过对组合进行特征归因及有效分档计算可分别得到因子当期的有效分档  和组合的实际分档 ，

**定义：** 为当前组合中因子  的有效得分：

其中，

-   : 因子有效得分
    
-   : 归因后实际分档
    
-   : 因子有效分档
    
-   ：组合在该因子上的暴露（实际分档）**等于或优于**其有效分档阈值，判定为“有效”。
    
-   ：组合暴露不足，判定为“失效”。
    

#### **算法流程如下：**

1.  **初始化**：得到初始的多因子集合。
    
2.  **剔除阶段**：
    

-   对当前组合进行归因，计算所有 。
    
-   剔除所有  的“失效”因子。
    
-   用剩余因子构建新组合。
    
-   **循环**：重复此步骤，直到剩余所有因子都满足 。得到一个“核心有效因子集”。
    

4.  **纳入阶段**：
    

-   从之前被剔除的因子池中，逐个尝试加入一个因子到“核心有效因子集”中。
    
-   对新形成的因子集进行归因，计算**所有因子**的平均有效得分 。
    
-   选择能使 **提升最多**的那个被剔除因子，加入集合。
    
-   加入新因子后，可能导致其他因子再次变为 。因此，需要**再次运行剔除阶段**，移除所有失效因子。
    
-   **循环**：重复此纳入->剔除过程，直到无法通过加入任何已剔除因子来提升  为止。
    

### 总结

![](assets/002.png)

-   **本质**：这是一个**贪心搜索 + 后向剔除**的组合优化启发式算法。它不保证找到全局最优解，但计算效率高，逻辑符合直觉。
    
-   **目标函数**：最大化最终因子集合的 。这间接优化了组合中每个因子的“暴露充足度”。
    
-   **计算复杂度**：每期需要构建多次组合并进行归因。如果初始因子数量为 `K`，复杂度约为 `O(K^2)` 量级，在月频策略中完全可接受。
    

循环进行上述操作直到多因子组合趋于稳定。策略步骤如下所示：

```
初始多因子    │    ▼有效性最低的因子剔除，并根据剩余多因子构建组合并归因    │    ▼循环进行，直到剩余因子均“有效”    │    ▼全部因子是否有效？    ├── 是 ──→ 最终多因子    │    └── 否         │         ▼    逐个检查剔除因子是否带来因子维度或总分的增加，    并纳入其中分数增加最高者，同时再次剔除失效的因子         │         ▼    循环进行，直到没有更好的因子可以纳入         │         ▼    是否得到最优多因子？         ├── 是 ──→ 最终多因子         │         └── 否 ──→ 继续循环
```

## 程序介绍

程序部分由agent生成，笔者调试，主要在于算法介绍，如需要使用，请仔细阅读代码，防止bug。仅仅展示核心算法部分

```
# -------------------- 核心调整算法 --------------------def adjust_factors(self, initial_factors: List[str],                   factor_hist_dict: Dict[str, pd.DataFrame],                   stock_returns: pd.DataFrame,                   current_factor_dict: Dict[str, pd.Series],                   top_pct: float = 0.2) -> Tuple[List[str], Dict[str, float]]:    """返回最终因子列表以及每个因子的有效得分S_i（用于雷达图）"""    # 预计算有效分档    effective_f = {}    for f in initial_factors:        hist = factor_hist_dict.get(f)        if hist is None:            raise ValueError(f"因子 {f} 缺少历史数据")        eff = self.compute_effective_fraction(hist, stock_returns)        effective_f[f] = eff    # 剔除整体无效因子    initial_factors = [f for f in initial_factors if effective_f[f] <= self.n_bins]    if not initial_factors:        return [], {}    # 阶段1：剔除失效    current_set = initial_factors.copy()    while True:        selected_stocks, _ = self.build_combination(current_set, current_factor_dict, top_pct)        actual_g = {}        for f in current_set:            g = self.compute_actual_fraction(current_factor_dict[f], selected_stocks)            actual_g[f] = g        invalid = [f for f in current_set if (effective_f[f] / actual_g[f]) <= 1]        if not invalid:            break        current_set = [f for f in current_set if f not in invalid]        if not current_set:            break    # 阶段2：贪心纳入    excluded = [f for f in initial_factors if f not in current_set]    improved = True    iteration = 0    while improved and iteration < 10:        improved = False        best_factor = None        best_set = None        best_score = 0.0        def mean_score(factor_list):            if not factor_list:                return 0.0            stocks, _ = self.build_combination(factor_list, current_factor_dict, top_pct)            scores = []            for f in factor_list:                g = self.compute_actual_fraction(current_factor_dict[f], stocks)                s = effective_f[f] / g if g != 0 else 0                scores.append(s)            return np.mean(scores)        current_score = mean_score(current_set)        for f in excluded:            trial_set = current_set + [f]            trial_set = self._purge_invalid(trial_set, effective_f, current_factor_dict, top_pct)            if not trial_set:                continue            trial_score = mean_score(trial_set)            if trial_score > current_score + 1e-6:                if trial_score > best_score:                    best_score = trial_score                    best_factor = f                    best_set = trial_set        if best_factor is not None:            current_set = best_set            excluded.remove(best_factor)            improved = True        iteration += 1    # 计算最终每个因子的S_i    final_scores = {}    if current_set:        stocks, _ = self.build_combination(current_set, current_factor_dict, top_pct)        for f in current_set:            g = self.compute_actual_fraction(current_factor_dict[f], stocks)            final_scores[f] = effective_f[f] / g if g != 0 else 0    return current_set, final_scoresdef _purge_invalid(self, factor_list: List[str], effective_f: Dict[str, int],                   current_factor_dict: Dict[str, pd.Series], top_pct: float) -> List[str]:    if not factor_list:        return []    current = factor_list.copy()    while True:        stocks, _ = self.build_combination(current, current_factor_dict, top_pct)        actual_g = {}        for f in current:            g = self.compute_actual_fraction(current_factor_dict[f], stocks)            actual_g[f] = g        invalid = [f for f in current if (effective_f[f] / actual_g[f]) <= 1]        if not invalid:            break        current = [f for f in current if f not in invalid]        if not current:            break    return current
```

## 总结

在多因子策略构造过程中，一会会有这样的疑问：策略的收益有多少是来源有单个因子？或者说，策略中使用到的多个因子到底哪些贡献大？哪些贡献小？如果剔除贡献小的因子？

通过阅读本文，你就可以对这样的问题有清晰明确的回答：特征归因分析。通过此方法，我们就能清晰的了解，哪些因子对最终的组合贡献较大，哪些贡献较小。并且提出了改进算法。