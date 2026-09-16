# 投资组合优化器——Python简单实践

InfinityQuant 映翡量化 2024-11-08 20:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247485658&idx=1&sn=5992150ed7f23f73956da9c8befe05b1&chksm=9e496273ba02782120b61077a6261ec8ffd6bde09989451ddbcae225f28d54417e8756335f6d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247485658&idx=1&sn=5992150ed7f23f73956da9c8befe05b1&chksm=9e496273ba02782120b61077a6261ec8ffd6bde09989451ddbcae225f28d54417e8756335f6d#rd)

# 目标

投资组合优化器的目标是在可变时间段内找到指数基金、ETF、股票和债券的最佳组合，并具有最佳夏普比率，以最大限度地提高您的回报。

## 夏普比是多少？

夏普比率是一种用于评估投资组合风险调整回报的衡量标准。它将投资组合的超额回报（高于无风险利率的回报）与其标准差（波动性或风险的衡量标准）进行比较。夏普比率的公式是：

  

![](assets/001.png)

更高的夏普比率表明风险调整后的回报更具吸引力，这意味着投资每单位风险的回报率更高。

> **注意：**在我将要使用的公式中，不会有无风险的费率，因为它是一个任意值，不提供更多有价值的信息，而只提供在这种情况下不需要的噪音。

# 启动项目

需要一些库来获取项目所需的数据、可视化和预处理。

```
import yfinance as yf  # For downloading financial data from Yahoo Finance
```

然后，我们需要一个票证对象，该票证将存储模拟将考虑的所有票证：

```
# All the tickets that are going to be analyzed
```

为了允许这一点，我们将首先从_time\_periods_列表中下载最长的时间段，然后通过裁剪最长的时间段来获取其他时间段的其余时间段。

```
# Function to calculate the start date based on the time period
```

```
# Determine the highest time period
```

## 模拟代码

```
# Box of splits where the percentage for every asset will be drawn
```

‍我们首先为模拟创建变量，可能最棘手的变量是_std\_exponent\_sharpe\_ratio。_

添加了这个变量，以防止软件选择具有高波动性和高回报的组合，它们在未来不太可能稳定盈利。

然后，我们迭代所有模拟，并从票证对象中随机选择票证。

如果票证已经在模拟中，不要尊重_max\_stocks\_percent_或_max\_sector\_percent_，那么将抽取另一张票。

我们运行模拟，并将结果存储在_模拟_列表中。

# 结果

在屏幕上绘制最佳模拟结果的时间：

`simulations_to_analyze = 50 # Don't show every simulation but only the best ones``   ``# Sort simulations by Sharpe ratio in descending order``simulations.sort(key=lambda x: x["sharpe_ratio"], reverse=True)``   ``# Define a colormap from green to red``cmap = plt.cm.get_cmap('RdYlGn')``norm = mcolors.Normalize(vmin=min(sim["sharpe_ratio"] for sim in simulations[:simulations_to_analyze]),`                         `vmax=max(sim["sharpe_ratio"] for sim in simulations[:simulations_to_analyze]))``   ``# Plot each simulation in a subplot``fig, axes = plt.subplots(nrows=math.ceil(simulations_to_analyze / 2), ncols=2, figsize=(25, int(simulations_to_analyze * 1.7)))``axes = axes.flatten()``   ``for idx, sim in enumerate(simulations[:simulations_to_analyze]):`    `ax = axes[idx]`    `sim["series_cum_returns"].plot(ax=ax)`    `tickets_splits = ", ".join([f"{ticket}: {split}%" for ticket, split in sim["tickets"].items()])`    `title = f"Tickets: {tickets_splits} | Time Period: {sim['time_period']} | Sharpe Ratio: {sim['sharpe_ratio']}"`    `color = cmap(norm(sim["sharpe_ratio"]))`    `ax.set_title(title, color=color, bbox={'facecolor': 'black', 'pad': 5})`    `ax.set_xlabel("Date")`    `ax.set_ylabel("Cumulative Returns")``   ``plt.tight_layout()``plt.show()`

这是我找到的最好的门票组合：  
**_{'OTIS'：10，'MDHQX'：10，'SMCI'：20，'VDE'：40，'VOO'：10，'QQQ'：10}_**

夏普比为：**_1.3_**

以下是最有可能收到的图表示例：

  

![](assets/002.png)

> **注意：**结果可能因模拟参数而异，即使模拟参数相同，由于软件的随机性，它们仍然可能有所不同。

## 让我们更好地了解结果

接下来，您将看到一些代码来更好地了解结果，如总收入、年收入、最佳证券、最佳行业等......

```
# What are the tickets of the best simulation?simulations[0]["tickets"]
```

{'OTIS': 10, 'BLDR': 30, 'IXJ': 30, 'QQQ': 10, 'SMH': 10, 'SOXX': 10}

```
# How much did the simulation earned?
```

3.833603973508689

不错，这意味着通过这种投资组合分配，我们几乎可以赚到6年投资的4倍，当然，这个指标会过度拟合，但这是获得未来投资内容的一般指南的好方法。

```
def calculate_annual_rate(years, final_earnings):
```

> ‍在6年内达到410.28367071043795%的投资所需的年利率为26.53%

以SP500为基准，我们肯定以这些结果击败了市场。

`# Tickets that are more present in the top simulations``best_simulations = simulations[:simulations_to_analyze]``tickets_showup = {}``   ``for ticket in list(tickets.keys()):`  `tickets_showup[ticket] = 0``   ``for best_simulation in best_simulations:`  `for ticket in best_simulation["tickets"].keys():`    `tickets_showup[ticket] += 1``   ``dict(sorted(tickets_showup.items(), key=lambda item: item[1], reverse=True))`

按外观数量排名前七的资产：

**'OTIS'：30，'SMH'：24，'CELH'：23，'GC=F'：13，'VDE'：13，'VGT'：13，'QQQ'：11**

```
# Sectors that are more present in the top simulations
```

> ‍按外观数量排名前七的部门：
> 
> **“技术、媒体和电信”：109，“工业品和机械”：51，“金融服务”：43，“采矿”：32，“消费者”：30，“石油和天然气”：21，“一般”：19**

## 可能的改进

我的软件正试图强制组合最佳投资组合分配。

这不是很有效率，你可以实施一种算法来“学习”最好的票证，并尝试将它们组合在一起，如果在模拟过程中票证取得了好的结果，你可以增加它被抽签的概率。

由于我们没有使用机器学习算法，因此代码不那么受过度拟合的影响，出于解释目的，我决定不将数据库拆分为训练、验证和测试集。

如果您想将此代码应用于您自己的个人投资组合，我建议您不要使用同一组数据来训练/理解和验证最佳门票。

# 结论

在本文中，我们演示了如何使用Python构建投资组合优化器，利用数学原理和夏普比率来最大化风险调整后的回报。

通过模拟各种投资组合分配和约束，我们确定了资产的最佳组合，以实现最佳性能。

这种方法提供了一种系统的投资方法，专注于平衡风险和回报，而不是试图在每次交易中超越市场。

使用`yfinance`、`numpy`和`pandas`等工具，我们可以根据历史数据有效地分析和优化投资组合。

  

完整代码参考：https://github.com/MoscatelliMarco/articles-code/tree/main/portfolio-builder-in-python