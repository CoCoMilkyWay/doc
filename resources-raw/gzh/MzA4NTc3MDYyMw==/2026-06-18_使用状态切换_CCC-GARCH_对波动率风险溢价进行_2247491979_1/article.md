# 使用状态切换 CCC-GARCH 对波动率风险溢价进行择时

InfinityQuant 映翡量化 2026-06-18 09:14 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491979&idx=1&sn=79e4a9c42de47eaad82c6a3a20ea99e8&chksm=9e8e8fd443407284d3cd36f26bda2b65bc1bfd1fbfd46b2f231f060cf40026397a0947846afd#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491979&idx=1&sn=79e4a9c42de47eaad82c6a3a20ea99e8&chksm=9e8e8fd443407284d3cd36f26bda2b65bc1bfd1fbfd46b2f231f060cf40026397a0947846afd#rd)

卖出波动率是最经典的套利策略之一，但其收益结构也极为不对称：长时间稳定获取收益，却在市场状态切换时遭遇集中且剧烈的损失。关于波动率风险溢价（VRP）的学术与实务研究，大多集中在其是否存在，而更关键的问题在于何时参与该交易。

QuantInsider的《Regime-Switching CCC-GARCH for Cross-Asset Volatility Risk Premium Forecasting》（2026年6月2日）进行了详细的分析。

用于已实现波动率建模的状态切换 CCC-GARCH 引擎

标准 CCC-GARCH（Bollerslev，1990）将条件协方差分解为对角波动率矩阵与常数相关矩阵。这种设定在计算上方便，但在实证上并不成立。跨资产相关性在平稳与压力状态下表现截然不同，而该假设恰恰在最关键时刻失效。

引入一个潜在的马尔可夫状态，并允许不同状态下具有不同的 GARCH 参数和regime-specific相关矩阵，可以恢复这一经验事实，同时仍保持模型在计算上的可行性（可通过 EM 算法与 Hamilton 滤波进行估计）。

高波动状态的滤波概率可直接作为风险控制信号：当模型对压力状态的概率判断上升时，降低卖出波动率的仓位，从而在大幅回撤发生前退出交易。

用于隐含波动率侧的日历事件调整因子

围绕预定事件（如 FOMC、CPI、ECB、非农就业、财报发布）的短期隐含波动率包含一个确定性成分，纯时间序列模型无法捕捉。

解决方法是对前瞻性已实现方差预测施加一个乘法调整项，其系数通过回归估计得到：以事件窗口内的已实现方差为因变量，事件虚拟变量为自变量，并控制 GARCH 预测值。该调整可防止模型将事件驱动的隐含波动率“高估”误判为可交易的风险溢价。

 VRP 交易信号

最终的 VRP 信号定义为：观察到的隐含方差减去经过事件调整、且考虑体制信息的实现方差预测值（两者对应相同的时间窗口），![](assets/001.png)

在股票、利率、外汇与大宗商品等多资产标的上，该信号可通过风险平价进行聚合；而在策略风险暴露最高的状态下，跨资产分散化带来的收益最为显著。

![](assets/002.png)

https://www.linkedin.com/company/quant-insider/posts/?feedView=all

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)