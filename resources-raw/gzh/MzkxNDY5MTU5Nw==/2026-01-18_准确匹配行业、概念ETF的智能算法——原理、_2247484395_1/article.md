# 准确匹配行业、概念ETF的智能算法——原理、步骤、代码

蝴蝶量化 随率而动的因子工厂 2026-01-18 22:56 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484395&idx=1&sn=1395566ecfcf1a338a4d4fd94e63bfa4&chksm=c024600a42195609dc1c8cff83f3e8eff36e3a1f27c7ed5504cf55546707b27b2f0075742b78#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484395&idx=1&sn=1395566ecfcf1a338a4d4fd94e63bfa4&chksm=c024600a42195609dc1c8cff83f3e8eff36e3a1f27c7ed5504cf55546707b27b2f0075742b78#rd)

## 技术背景

拥有多年经验的交易员发现，如果你对某个行业、概念、板块比较看好，由于成分股数量较多，选股要求高。并且你也会发现，牛市中指数的涨幅往往个人的账户涨幅要大，所以你只想吃到这个组合的平均收益，也就是整体行业的beta收益。

这时候就有两个选择：

-   **1、资金足够大、能力足够强：** 做整个行业的指数增强组合，调整指数内不用个股的权重。从而吃到整个板块的beta收益，同时吃到个股的alpha收益。这个板块、指数增强算法，我们也会在我们星球里面的重要内容之一。
    
-   **2、普通投资者：** 由于资金不足以覆盖全成分股。理性的投资者这时候就偏向于吃到板块的整体beta收益。那么，对应的板块ETF就成了不二之选。巴菲特认为，作为一名普通投资者的收益，在大部分情况下其实是不如指数的。
    

如果你认可上面的观点，那么通过阅读本文，您将会得到一个很有力的帮手。如果你有类似的经验，你就会发现，市场的ETF有限，某一些板块甚至就没有ETF。这时候如何找出**行业、板块、概念**对应的ETF，就成了一个关键的问题，本期文章的主要内容，就是跟大家一起解决这个问题。

大致的分析角度，可以从下图中看出，具体图片中含义，请阅读后文

![](assets/001.png)

## 使用场景

-   **场景1：** 你对**某个行业**比较青睐，但是你会发现，这个行业的成分股比较多。而且您没有一个**强的逻辑、能力**去做行业内选股。很快你就会发现，往往你选择的个股并没有行业指数走得好。这时候，最好的选择就是买入行业ETF，比如：比如最近表现不错的**申万二级行业：航天装备。** 当你想买入这个二级行业的时候，发现根本没有相应的etf，但是有很多相关的ETF：卫星ETF、军工ETF、航天ETF等，虽然都涨得不错。但是选择哪一个更加的合理就成了一个必须要考究的问题。
    
-   **场景2：** 你对同花顺、通达信、东财的某一个指数（概念、板块）比较看好，同样您又恰好发现，买入个股难度比较大，你只想吃到整体的beta收益。但是对于大部分的概念、板块是没有相应ETF。这时候就需要在整个市场中寻找走势相关的ETF。
    
-   **场景3:**  如果你有一系列的股票组合，这个组合并不跟任何的指数成分股相同。你只想吃到这部分股票的整体的beta收益，同样的由于资金问题难以做到全部的平铺，需要找到一个收益、风险与这个自建组合类似的ETF。那么就可以用本期文章中提到的算法。
    

## 实现算法

首先，第一步是剔除那些成交量小的、交易不活跃的ETF。

### 1、名称匹配（效果一般）

显然，这是一个比较高效的方式，通过python函数扫描全市场的ETF，从而找到与你关注指数名称类似的股票。

步骤：

-   1、筛选某一只看好的指数，获取指数名称。
    
-   2、获取全市场ETF列表
    
-   3、调用python程序，做关键词匹配，输出
    

**注意点：采用名称匹配能够解决很多指数、一级行业的ETF匹配。但是在二级行业、概念板块等指数很多没有对应跟踪的ETF就难以匹配。**

### 2、相似度匹配

首先，我们要明确寻找ETF的目的是：寻找收益、回撤、走势跟对应指数最相近的一个ETF。

#### **第一种：相关性角度**

显然，数学上的相近、相似就是找过去一段时间的走势**相关系数**最高的。

那么问题来了，到底运用那个**指标**作为相关系数最高的呢？你可以尝试下面的几种：

-   **收盘价（净值）：** 铆钉开始日期收盘价为1，之后的净值计算为收盘价/第一天的收盘价。得到两个净值曲线。然后，**计算两个时间序列的相关性，按照相关性大小进行排序。选择相关性最高的那个ETF。**
    
-   **收益率：** 计算每天的时间收益率，这是相关性，相当于在**净值**的基础上做了**一阶差分**，这样计算计算下来的相关性排序，准确率更高。
    

**实际用法：**上面的两种方法，从不同的角度，给出了相关性的计算方法，在实际中，为了更加准确，我们采用多因子思路：**去两者之间的平均值，作为最终的相关系数。** 取最高者作为最后的标的。

**注意：如果相关性不足90%时，我需要额外考虑其他的因素：标准差、相对收益的最大回撤等等。**

#### **第二种：回归分析角度**

这里相当于追求两个净值曲线的回归系数，相当于在**相关系数**的基础上，增加了两个净值曲线的标准差。

具体步骤：

-   计算回归系数、残差。
    
-   对残差做t检验，考察显著性。具体代码
    
-   对于上面的计算步骤采用滚动计算的方法。
    

**具体代码见后文**

### 3、成分股匹配

上面的方法就是纯数学方法，我们知道ETF与指数是否联动比较好，**主要取决于成分股是否类似。** 这就给我们提供了另外一种思路：**直接做成分股匹配。**

步骤：

-   1、获取成分股数据
    
-   2、计算指数与ETF成分股之间的相似成度。如果超过80%以上的股票匹配，那么基本上判断相似。
    

**由于篇幅、时间等原因，代码没有呈现，后期星球有完整代码。**

### **综合方法**

通过上面的阅读，你基本上了解了如果做ETF的匹配，我们发现上面的方法从不同的角度给出验证方法，各自有各自的优缺点。那么在实际应用过程中，是否可以综合起来一起做呢？

**答案是显然的，综合应用方法**

-   **1、名称匹配法做初筛：** 通过这种方法可以快速的筛选那些能够直接匹配的ETF（80%以上）。剩下的ETF通过其他两种方法。
    
-   **2、相似度匹配做检验与第二轮筛选：** 这种方法解决两个问题：1、对一步找到的做检验增加可靠性。2、对第一步中没有找到的做匹配。如果放低相关性也能起到兜底作用。
    
-   **3、成分股匹配法兜底：** 通过成分股的匹配方法，通过成分股比例的阈值，基本能上能够找到匹配的ETF，但是建议做完之后，还是需要通过第二种当法，做检验，增加模型的稳定性。
    

**注意点：由于又一些新上的ETF数据上不够第二步，只能通过第一种、第三种方法做匹配。**

## 具体python代码

**由于篇幅、其他等原因，代码仅展示检验（相似度匹配）的代码。部分代码由ai生成，博主调试、亲测正确有效。**

`import numpy as np   import pandas as pd   from scipy import stats   import statsmodels.api as sm   import matplotlib.pyplot as plt         # 方法1：配对样本t检验（检验收益率差值是否显著不为0）   def paired_t_test(ret1, ret2):       """配对样本t检验"""       diff = ret1 - ret2       t_stat, p_value = stats.ttest_1samp(diff, 0)              print("=== 配对样本t检验结果 ===")       print(f"收益率差值均值: {diff.mean():.6f}")       print(f"收益率差值标准差: {diff.std():.6f}")       print(f"t统计量: {t_stat:.4f}")       print(f"p值: {p_value:.4f}")              if p_value < 0.05:           print("结论: 在5%显著性水平下，拒绝原假设，两个标的收益率不一致")       else:           print("结论: 在5%显著性水平下，无法拒绝原假设，两个标的收益率一致")              return t_stat, p_value      # 方法2：线性回归方法   def regression_approach(ret1, ret2):       """回归方法检验收益率一致性"""       # 添加常数项       X = sm.add_constant(ret2)       y = ret1              # 拟合回归模型       model = sm.OLS(y, X).fit()              print("\n=== 线性回归分析结果 ===")       print(model.summary())              # 检验假设 H0: 截距=0 且 斜率=1       hypothesis = 'const = 0, x1 = 1'       f_test = model.f_test(hypothesis)              print(f"\n=== 一致性检验（原假设：截距=0且斜率=1）===")              # 修复这里：直接使用 fvalue 属性，它可能是标量或数组       try:           # 尝试作为标量处理           f_stat = float(f_test.fvalue)       except:           # 如果是数组，取第一个元素           f_stat = f_test.fvalue[0][0] if hasattr(f_test.fvalue, '__getitem__') else f_test.fvalue              print(f"F统计量: {f_stat:.4f}")       print(f"p值: {f_test.pvalue:.4f}")              if f_test.pvalue < 0.05:           print("结论: 拒绝原假设，两个标的收益率不一致")       else:           print("结论: 无法拒绝原假设，两个标的收益率一致")              return model, f_test      # 方法3：相关性检验   def correlation_test(ret1, ret2):       """相关性分析"""       corr, p_value = stats.pearsonr(ret1, ret2)              print("\n=== 相关性分析 ===")       print(f"相关系数: {corr:.4f}")       print(f"相关系数p值: {p_value:.4f}")              # 检验相关系数是否接近1       if corr < 0.95:  # 通常认为高相关性表示一致性           print("提示: 相关系数较低，可能不一致")       else:           print("提示: 相关系数较高，可能一致")              return corr, p_value      # 可视化分析   def visualize_returns(ret1, ret2, label1="标的A", label2="标的B"):       """可视化收益率对比"""       fig, axes = plt.subplots(2, 2, figsize=(12, 10))              # 1. 收益率时间序列       axes[0, 0].plot(ret1, label=label1, alpha=0.7)       axes[0, 0].plot(ret2, label=label2, alpha=0.7)       axes[0, 0].set_title("收益率时间序列对比")       axes[0, 0].set_ylabel("收益率")       axes[0, 0].legend()       axes[0, 0].grid(True, alpha=0.3)              # 2. 散点图与45度线       axes[0, 1].scatter(ret2, ret1, alpha=0.5, s=10)       # 添加45度线（如果一致，点应该在这条线上）       min_val = min(ret1.min(), ret2.min())       max_val = max(ret1.max(), ret2.max())       axes[0, 1].plot([min_val, max_val], [min_val, max_val],                       'r--', label='完全一致线')       axes[0, 1].set_xlabel(f"{label2}收益率")       axes[0, 1].set_ylabel(f"{label1}收益率")       axes[0, 1].set_title("收益率散点图")       axes[0, 1].legend()       axes[0, 1].grid(True, alpha=0.3)              # 3. 收益率差值分布       diff = ret1 - ret2       axes[1, 0].hist(diff, bins=30, edgecolor='black', alpha=0.7)       axes[1, 0].axvline(x=0, color='r', linestyle='--', label='零差值')       axes[1, 0].axvline(x=diff.mean(), color='g', linestyle='-',                          label=f'均值: {diff.mean():.6f}')       axes[1, 0].set_xlabel("收益率差值")       axes[1, 0].set_ylabel("频数")       axes[1, 0].set_title("收益率差值分布")       axes[1, 0].legend()       axes[1, 0].grid(True, alpha=0.3)              # 4. 累积收益率对比       cum_ret1 = np.cumprod(1 + ret1) - 1       cum_ret2 = np.cumprod(1 + ret2) - 1       axes[1, 1].plot(cum_ret1, label=label1)       axes[1, 1].plot(cum_ret2, label=label2)       axes[1, 1].set_title("累积收益率对比")       axes[1, 1].set_xlabel("时间")       axes[1, 1].set_ylabel("累积收益率")       axes[1, 1].legend()       axes[1, 1].grid(True, alpha=0.3)              plt.tight_layout()       plt.show()              # 计算跟踪误差       tracking_error = diff.std() * np.sqrt(252)  # 年化跟踪误差       print(f"\n年化跟踪误差: {tracking_error:.4f}")      # 执行所有检验   def comprehensive_analysis(ret1, ret2, label1="标的A", label2="标的B"):       """综合分析方法"""       print("="*60)       print(f"分析 {label1} 与 {label2} 收益率一致性")       print("="*60)              # 基本统计量       print("\n=== 基本统计量 ===")       print(f"{label1}: 均值={ret1.mean():.6f}, 标准差={ret1.std():.6f}")       print(f"{label2}: 均值={ret2.mean():.6f}, 标准差={ret2.std():.6f}")              # 执行各种检验       paired_t_test(ret1, ret2)       regression_approach(ret1, ret2)       correlation_test(ret1, ret2)              # 可视化       visualize_returns(ret1, ret2, label1, label2)      if __name__ == "__main__":   # 生成示例数据（实际使用时替换为你的数据）     # np.random.seed(42)     # n = 250  # 假设250个交易日     # ret_A = np.random.normal(0.0005, 0.02, n)  # 标的A日收益率     # ret_B = np.random.normal(0.0005, 0.02, n)  # 标的B日收益率        df_a = pd.read_csv('000300.SH.csv')     df_a = df_a[['date','close']].copy()     df_a['date'] = pd.to_datetime(df_a['date']).dt.date     df_a.set_index('date', inplace=True)     df_a.rename(columns = {"close":'000300.SH'},inplace=True)        df_b = pd.read_csv('510300.SH.csv')     df_b = df_b[['date','close']].copy()     df_b['date'] = pd.to_datetime(df_b['date']).dt.date     df_b.set_index('date', inplace=True)     df_b.rename(columns = {"close":'510300.SH'},inplace=True)           df = pd.merge(df_a, df_b, right_index=True, left_index=True, how='inner')     df.sort_index(inplace=True,ascending=True)        # df['000300.SH'] = df['000300.SH']/df.iloc[0]['000300.SH']     # df['510300.SH'] = df['510300.SH']/df.iloc[0]['510300.SH']        df = df.pct_change()     df.dropna(inplace=True)        ret_A = np.array(df['000300.SH'])     ret_B = np.array(df['510300.SH'])        n = len(df.index)     # 运行综合分析         # 运行综合分析     comprehensive_analysis(ret_A, ret_B, "000300.SH", "510300.SH")        # 示例：检验两个高度相关的标的     print("\n" + "=" * 60)     print("示例：检验两个高度相关的标的")     print("=" * 60)        # 创建高度相关的两个标的     ret_C = ret_A + np.random.normal(0, 0.001, n)  # 几乎相同     comprehensive_analysis(ret_A, ret_C, "000300.SH", "510300.SH")         `

## 结果验证与分析

本期代码我们采用部分展示，同样的完整代码会在星球中展示。 1、这是一张统计的图片：![](assets/002.png)显示了沪深300与其ETF的：日收益对比（左上）、拟合曲线（右上）、收益率差值分布（坐下）、走势对比（右下）。**直观上肯定是匹配的。**

2、下面是统计分析表，不同的可以问deepseek：

![](assets/003.png)

![](assets/004.png)

3、滚动截距看误差，通过下图我们可以看到相对收益还是有回归性，是一个平稳序列。

![](assets/005.png)

#### **定期维护更新频率：**

由于经常有ETF建立、或者ETF成分股调仓等等。我们需要定期维护更新数据库，并且运行程序重新匹配ETF，特别是做行业组合的小伙伴。一般来讲：**月频更新即可**

## 总结

通过本文的内容，你一定能够很清楚的了解如果寻找匹配的ETF。我们给出了大部分可能情景的解决办法，并且给出了算法原理、代码、检验过程等等。

当然，条条大路通罗马，如果您还有更好的办法，并且愿意一起讨论、分享可以联系我们。感谢您的阅读。