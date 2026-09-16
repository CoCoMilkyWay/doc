# 隔夜价格跳跃如何揭秘投资者过度反应

InfinityQuant 映翡量化 2025-10-27 13:39 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487778&idx=1&sn=62fe21cd5ecfbec96d5dd779be8205b3&chksm=9eba8b98cd1e238ae6fe4f78516371e35bf491facebcffbabe7ba3d1bec507fdc11aafc1eae8#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487778&idx=1&sn=62fe21cd5ecfbec96d5dd779be8205b3&chksm=9eba8b98cd1e238ae6fe4f78516371e35bf491facebcffbabe7ba3d1bec507fdc11aafc1eae8#rd)

《Dark Side of the Day： Overnight Price Jumps and Short-Term Return Predictability》（2025年10月）探讨了股市闭市后（隔夜）价格跳跃如何揭示投资者过度反应，并导致短期回报可预测性。

讨论聚焦隔夜跳跃这一独特情境：夜间无交易，跳跃纯由信息冲击驱动，避免日内噪音（如噪音交易、流动性失衡、微观结构设计）。基于心理学观点，剧烈信息事件易激发更强反应，作者测试隔夜跳跃是否体现认知偏差导致的过度反应。

  

🔬 一、研究模型

主要采用了两类模型来分析隔夜价格跳跃（overnight price jumps）及其对短期回报的影响。

首先，在跳跃识别（jump identification）方面，作者使用了Lee and Mykland (2008)提出的统计方法。该方法基于局部波动率估计，检测价格序列中的不连续跳跃。具体而言，论文将股票价格建模为半鞅过程（semi-martingale process），包括连续扩散部分和跳跃部分：

![](assets/001.png)

其次，在回报可预测性分析中，使用了横截面回归模型（cross-sectional regression），类似于Fama-MacBeth回归框架。核心回归方程为：

![](assets/002.png)

其中，CDR是累计日内回报，CJR是累计隔夜跳跃回报（正负分开），控制变量包括前日回报（PREV）、特异波动率（IVOL）、公司规模（SIZE）、账面市值比（BM）、杠杆（LEV）、动量回报（RET）和异常非流动性（AI）。回归在月度层面进行，使用Newey-West调整t统计量，确保稳健性。论文还对不同分位数投资组合（quintile portfolios）和子时期进行了回归测试。

  

![](assets/003.png)

## 📊 二、数据与控制因子体系

使用了大规模的美国股票市场数据，样本覆盖9,283只在NYSE、AMEX和NASDAQ上市的普通股（common shares），时间跨度从1993年7月至2021年12月（总计342个月）。数据来源主要包括：CRSP（Center for Research in Security Prices）数据库和COMPUSTAT数据库。

内容

说明

市场

美股主要交易所全样本股票

频率

高频数据（分笔/分钟级）用于跳跃分解

时长

约涵盖二十年完整市场周期

清洗

去除停牌、异常报价、低价股噪声

 研究使用的关键因子

**因子名称**

**定义**

**作用**

**CJR^{-,+} (Cumulative Overnight Jump Returns)**

月度累计正/负隔夜跳跃回报

核心预测因子，衡量信息冲击导致的过度反应

**PREV (Previous Return)**

前一交易日的回报

控制短期连续性

**IVOL\_OJI (Idiosyncratic Volatility excluding Overnight Jump Days)**

排除跳跃日的特异波动率（月度标准差，基于Fama-French三因子模型残差）

控制风险

**SIZE (Firm Size)**

公司规模（市值对数）

控制规模效应

**BM (Book-to-Market Ratio)**

账面市值比

控制价值因子

**LEV (Leverage)**

总负债/总资产

控制财务风险

**RET\_{t-1,t-5} (Short-Term Momentum)**

过去1-5个月回报

控制短期动量

**RET\_{t-6,t-11} (Medium-Term Momentum)**

过去6-11个月回报

控制中期动量

**AI (Abnormal Illiquidity)**

Amihud指标

控制流动性

**CDR (Cumulative Daytime Returns)**

累计日内回报

因变量，衡量后续回报

**IR (Intraday Returns)**

次日日内回报

因变量，衡量短期回报

  

特别强调：

> **跳涨是独立于上述全部控制变量之后仍然显著的预测因子**。

  

✅ 三、核心结论：隔夜跳涨引发次日反转

现象

实证发现

反转效应

累计隔夜跳跃回报（CJR，包括正向和负向）与未来短期回报（尤其是次日日内回报）呈显著负相关。

时段集中

预测效果主要体现在 **开盘半小时至两小时内，并在几天内完全消失。**

市场机制

开盘流动性恢复 → 价格对隔夜过度反应进行修正

稳健性

在加入众多因子后仍显著，Sharpe 明显为正。

小盘股（low SIZE）和高波动股（high IVOL）中过度反应更强。

一句话总结机制：

> **隔夜跳涨反映情绪与噪声增强，开盘后市场定价回归理性 → 出现反转。**

经济含义：

-   夜间市场是**错误定价的集中期**
    
-   开盘交易是**纠偏与风格切换信号的释放期**
    

##   

## 🎯 四、投资启示

方向

应用策略

高频择时

选择对隔夜跳涨显著的标的进行开盘反向操作

执行成本控制

避免开盘追涨跳涨股票

风险监控

隔夜跳涨作为价格失真预警指标

可与其他短期反转因子组合，提升策略稳定性。

  

![](assets/004.png)

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5648748

  

PDF已更新⬇️

![](assets/005.jpg)

直达：https://t.zsxq.com/j0oF6