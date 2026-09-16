# 系统性反转与行业动量

InfinityQuant 映翡量化 2026-03-16 09:58 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491233&idx=1&sn=5f988b9be6cbe46943dcf86993750f36&chksm=9e564a9e2c4f93f5346dd52c70b69217088d14efd46039ecc930c32fad48058533e50080b01c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491233&idx=1&sn=5f988b9be6cbe46943dcf86993750f36&chksm=9e564a9e2c4f93f5346dd52c70b69217088d14efd46039ecc930c32fad48058533e50080b01c#rd)

论文《Systematic Reversal and Industry Momentum》（2024年首次发布、2026年3月更新）针对资产定价领域的经典矛盾展开分析：**个股层面存在显著的一月反转**（Jegadeesh & Lehmann, 1990），而**行业组合、特征组合及因子组合**在相同短期却表现出**动量效应**（Moskowitz & Grinblatt, 1999；Lewellen, 2002；AKL, 2023）。核心疑问在于：多元化是否消除了反转？抑或仅将其掩盖？

### 核心发现

作者突破传统认知，提出**残差-系统性反转（Residual-to-Systematic Reversal, RSR）效应**： 过去**特质性（残差）回报**会**负向预测**未来的**系统性回报**。 这一系统性反转在高度多元化的随机“行业”、特征组合及因子组合中均持续存在，导致观察到的短期动量利润被显著压制。

![](assets/001.png)

### 关键实证证据

-   **对冲RSR后的绩效提升：**

-   行业动量夏普比率提升131%（达1.11），FF5+STREV α升至0.56%（t=7.96）；
    
-   特征动量夏普比率提升109%（为0.71）；因子动量提升82%。 对冲后，**行业动量与因子动量完全独立**（FF5+STREV+FMOM后仍剩0.39%显著α）。
    

![](assets/002.png)

-   **IPCA分解揭示本质： 使用Instrumented Principal Component Analysis（IPCA，Kelly et al., 2019）将行业回报拆分为系统性与残差成分。结果显示：**

-   行业动量利润几乎全部来自**残差成分**（Sharpe比率0.89）；
    
-   系统性成分接近零（Sharpe比率-0.04）。 证明行业动量本质是**行业特异性残差动量**，而非因子动量的“伪装”。
    

![](assets/003.png)

-   **检验方法差异：**
    
     标准**因子跨越回归（spanning regression）**因遗漏RSR产生**遗漏变量偏差（OVB）**，导致因子动量看似完全解释行业动量； 而**Fama-MacBeth横截面回归**不受影响，清晰显示二者来源独立。
    

### 主要贡献

-   首次揭示**系统性反转是所有短期动量策略的共同拖累因子**，解释了“个股反转 vs. 组合动量”的长期谜题。
    
-   为行业动量提供全新经济解释：其核心驱动力是**行业内残差动量**（而非宏观因子趋势）。
    
-   强调资产定价检验中必须控制RSR，否则spanning回归易产生误判；动态对冲RSR可显著提升实际投资绩效。
    

**一句话结论**： 多元化并未消灭反转，而是将其转化为隐形的系统性力量；剥离这一力量后，行业动量展现出独立于因子动量的强劲经济来源。

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6371558

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)