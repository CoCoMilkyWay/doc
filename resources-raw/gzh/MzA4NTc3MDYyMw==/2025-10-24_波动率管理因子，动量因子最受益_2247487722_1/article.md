# 波动率管理因子，动量因子最受益

InfinityQuant 映翡量化 2025-10-24 07:29 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487722&idx=1&sn=7d5110829cb15ad10cce3a127c265154&chksm=9e494964fc57e044dbb57b3b851dd01e33269985b98f5b4520cd4ba0c1109c9ce567390dd16d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487722&idx=1&sn=7d5110829cb15ad10cce3a127c265154&chksm=9e494964fc57e044dbb57b3b851dd01e33269985b98f5b4520cd4ba0c1109c9ce567390dd16d#rd)

波动率管理（Volatility Management）是近年来资产定价与量化投资的重要研究主题。

其核心思想是：**在高波动时期降低风险暴露，在低波动时期增加敞口**，以期改善风险调整后的收益表现。

Patrick Schwarz在《Journal of Empirical Finance》（2025）发表的论文《On the performance of volatility-managed equity factors — International and further evidence》及其附录，基于45个国际权益市场（1982-2021年）数据，系统评估了几种（下行）波动率管理因子的表现，包括考虑交易成本和跨国文化差异。该研究提供全球视角，强调交易成本作为套利限制的关键作用。

## 一、数据筛选与因子构建

-   市场数据：研究采用Refinitiv Datastream和Worldscope数据，覆盖65,300只股票（约980万股票月观测）。附录详细描述了数据质量控制：静态筛选剔除非普通股（如使用关键词列表，源自Ince and Porter, 2006等），动态筛选确保回报、市场资本化和账面市值比的有效性。样本起始日期基于Landis and Skouras（2021）的无偏方法，避免前瞻偏差。最终保留45国数据，确保每月至少30只股票构建因子。
    
-   因子构建（使用Worldscope项目）：市场因子（MKT）为价值加权超额回报；其他因子基于2x3排序（规模与因子标准），使用国家特定断点。因子包括SMB（规模）、HML/HMLm（价值）、CMA（投资）、RMW/RMWc/ROE（盈利能力）、MOM（动量）等。
    
-   **波动率管理策略：构建波动率管理因子，通过最近波动率倒数缩放原始因子。测试组合策略（管理+非管理）、直接夏普比率比较，以及考虑交易成本的净表现。**
    

![](assets/001.png)

![](assets/002.png)

类型

因子

核心逻辑

① 总波动率管理

Realized Variance (RV²)

用上个月总体波动率调整头寸：高波动降杠杆，低波动提杠杆

② 下行波动率管理

Downside Variance (dRV²)

只关注“坏波动”，更贴合投资者风险厌恶心理

③ 六个月波动率管理

6M RV² / 6M dRV²

滚动六个月均值，减少频繁调仓

④ 预期波动率管理

Expected (Downside) Vol

用历史回归预测未来波动

⑤ 限制杠杆版本

Leverage Capped at 1.5×

限制最大杠杆，防止低波动期过度放大风险

⑥ 剔除小盘股

Exclude Small Stocks

减少高换手带来的交易摩擦

-   **交易成本估计：灵感来源于Chen和Velikov（2022），计算股票级有效价差，评估动态再平衡的周转率影响。**
    

## 二、主要发现：波动率管理的潜力

（1）总体表现：动量（MOM）与市场（MKT）是波动率管理的最大受益者。

因子

原始组合夏普比率

波动率管理夏普比率

MKT 市场

↑ 显著提升（尤其下行波动率）

✓ 稳健

HML 价值

↑ 明显改善

✓ 稳健

MOM 动量

↑↑ 大幅改善（效果最佳）

★ 显著

RMW 盈利

小幅改善

\-

CMA 投资

无显著差异

\-

SMB 规模

不显著

✗

其他因子

轻微改善或无效

\-

### （2）下行波动率优于总波动率：以**下行波动率（dRV²）**为调整因子的组合优于传统的总波动率（RV²）版本，尤其在价值（HML）和市场（MKT）因子上。投资者主要关注“坏波动”而非整体波动，符合行为金融中的**损失厌恶效应**。

（3）引入交易成本后，超额收益显著下降：

-   高换手率因子（MOM、SMB）受影响最大；
    
-   低换手率因子（HML、RMW）相对稳健；
    
-   只有**动量策略**在考虑6个月下行波动率后，依然保持显著正收益。
    

## 三、跨国差异

价值和动量因子的超额表现更强于不确定性规避（Uncertainty Avoidance）低、长期导向（Long-Term Orientation）高的国家（如Hofstede文化维度）。

文化维度

代表特征

与策略表现关系

不确定性规避（Uncertainty Avoidance）

投资者厌恶不确定性

**负相关：高规避国家（如美国、英国）效果较弱**

长期导向（Long-Term Orientation）

强调未来收益

**正相关：如德国、日本、韩国等长期导向市场表现更好**

  

这为“慢交易假说（Slow Trading Hypothesis）”提供了支持：

> 投资者反应越慢，市场波动中可利用的错误定价越多。

换言之，波动率管理策略的国际差异反映的不仅是市场结构，更是文化与行为的差异。

## 四、结论与启示

-   波动率管理并非普适策略，仅在部分因子（尤其动量）上显著有效。
    
-   **下行波动率是更具行为经济学意义的风险度量**，能更好反映投资者的真实风险偏好。
    
-   交易成本与文化差异是决定策略能否落地的关键约束。
    

> “波动率管理不是追求平滑收益的技巧，而是对风险暴露的自觉调节。”

![](assets/003.png)

Schwarz, P. (2023). _On the Performance of Volatility-Managed Equity Factors: International and Further Evidence._

_https://www.sciencedirect.com/science/article/pii/S092753982400094X_

_两个PDF已更新⬇️干货满满_

![](assets/004.png)