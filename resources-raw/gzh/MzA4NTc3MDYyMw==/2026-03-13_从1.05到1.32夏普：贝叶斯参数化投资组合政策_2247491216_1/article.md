# 从1.05到1.32夏普：贝叶斯参数化投资组合政策（BPPP）的实证突破

InfinityQuant 映翡量化 2026-03-13 09:07 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491216&idx=1&sn=cc1d47201c40c08de3eca949b79233e6&chksm=9e35cb23ab394895a942c9cd4c8a4bd7e29b4fd879771dd5a4ddb3076372f4452ffd57b6bffb#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491216&idx=1&sn=cc1d47201c40c08de3eca949b79233e6&chksm=9e35cb23ab394895a942c9cd4c8a4bd7e29b4fd879771dd5a4ddb3076372f4452ffd57b6bffb#rd)

**参数化投资组合政策（Parametric Portfolio Policies，简称 PPP）** 让你可以跳过回报建模，直接从信号映射到权重。但它有一个隐藏的代价：**PPP 把估计出来的参数当作真实值，完全忽略了估计风险（estimation risk）。**

这篇论文《Bayesian Parametric Portfolio Policies》（2026年2月24日）证明，其后果绝非小事：

-   **PPP 总是高估预期效用；**
-   这种过度自信在**信号最强的时候最为严重**；
    
-   福利损失随着**风险厌恶程度增加**而扩大——对保守型投资者伤害最大。
    

**如何修正：**

**贝叶斯参数化投资组合政策（Bayesian Parametric Portfolio Policies，简称 BPPP）**：对策略系数（policy coefficients）施加先验分布，然后在后验分布上进行积分。没有人为设定的惩罚项——只是**Jensen 不等式**在发挥作用。

#### **数据与实证设置：**

-   **数据：6个Fama-French因子（市场、规模、价值、盈利、投资 + 动量）；242个预测信号（212个基于Chen & Zimmermann (2022)的异常信号 + 30个基于Haddad et al. (2020)的因子择时信号）。**
-   **样本：扩展窗口，外样本期1973M8–2023M12（605个月）；初始训练期120个月。**
-   **效用函数：CRRA（常相对风险厌恶），基线γ=5；月度再平衡。**

结果：

-   **夏普比率：1.32（BPPP） vs. 1.05（PPP） vs. 0.74（市场基准）**
-   **交易成本 50 个基点时：0.99 vs. 0.60**
-   **最大回撤：\-24.5% vs. -37.2%**
-   **额外发现：因子择时（factor-timing）的可预测性是**密集的（dense）**，而不是稀疏的——**绝大多数信号都有贡献**。**

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

https://arxiv.org/abs/2602.21173

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)