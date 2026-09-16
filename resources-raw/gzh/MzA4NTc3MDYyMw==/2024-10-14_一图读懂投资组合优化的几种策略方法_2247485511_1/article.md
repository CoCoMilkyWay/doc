# 一图读懂投资组合优化的几种策略方法

InfinityQuant 映翡量化 2024-10-14 20:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247485511&idx=1&sn=91bda64bf8248dbe99978400189b60c5&chksm=9e842a8bb0b273771e38f517361efad24b126dc6375531b7eab1c1087570a4131ebe74bc1dc1#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247485511&idx=1&sn=91bda64bf8248dbe99978400189b60c5&chksm=9e842a8bb0b273771e38f517361efad24b126dc6375531b7eab1c1087570a4131ebe74bc1dc1#rd)

![](assets/001.gif)

下图展示了一个完整的投资组合优化框架，它将资产配置过程分解为几个关键要素，并展示了各种优化策略之间的关系。

![](assets/002.png)

### **核心要素**

-   **资产 (Asset Universe)：** 指的是可以纳入投资组合的所有潜在资产，例如股票、债券、商品等。
    
-   **风险 (Risk)：** 衡量投资组合可能产生的损失，通常用标准差、方差等指标来表示。
    
-   **协同风险 (Co-risk)：** 指不同资产之间的相关性，即一种资产的波动对另一种资产的影响。
    
-   **收益 (Returns)：** 指投资组合的预期收益率。
    

###   

### **优化策略分类**

图中展示了多种投资组合优化策略，可以分为以下几类：

#### **1.风险平价策略 (Risk Parity)，两个大类**

-   **朴素风险平价 (Naive Risk Parity)：** 将风险平等地分配给投资组合中的每项资产。
    
-   **稳健风险平价 (Robust Risk Parity)：** 考虑了风险估计中的不确定性，更加稳健。
    

#### 

#### **2.最小方差策略 (Minimum Variance)**

-   **逆波动率 (Inverse Volatility)：** 将资金分配给波动性较低的资产。
    
-   **逆方差 (Inverse Variance)：** 与逆波动率类似，但强调的是方差。
    
-   **等风险贡献 (Equal Risk Contribution)：** 确保每项资产对组合总风险的贡献相等。
    
-   **最大分散化 (Maximum Diversification)：** 旨在最大化投资组合中不同资产之间的差异性。
    
-   **最小方差 (Minimum Variance)：** 构建风险最小的投资组合。
    
-   **分散化风险平价 ( Diversified Risk Parity）：**结合风险平价和多样化的概念。  
    

#### 

#### **3.均值方差策略 (Mean Variance)**

-   **战略资产配置 (Strategic Asset Allocation)：** 根据长期投资目标，对不同资产类别的配置。
    
-   **等夏普比率贡献 (Equal Sharpe Contribution)：** 确保每项资产对夏普比率的贡献相等。
    
-   **全球战术资产配置 (Global Tactical Asset Allocation)：** 在全球范围内进行资产配置。
    
-   **自适应资产配置 (Adaptive Asset Allocation)：** 根据市场环境动态调整资产配置。
    

#### 

#### **4.其他策略**

-   **逆条件风险价值 (Inverse CVaR)：** 关注极端损失的风险。
    
-   **逆条件下行风险 (Inverse CDaR)：** 与CVaR类似，但考虑了资产间的相关性。
    
-   **逆最大日度损失 (Inverse Max Daily Loss)：** 关注最大可能单日损失。
    

###   

**其他整体风险因素**  
**假设风险 (Assumption Risk)：** 指由于对未来市场状况的假设不准确而产生的风险。  
**估计风险 (Estimation Risk)：** 指由于对历史数据的估计误差而产生的风险。

### **总结**  

此图投资组合优化框架，涵盖了从资产选择到风险管理的各个方面。通过选择不同的优化策略，投资者可以根据自己的风险偏好和投资目标构建个性化的投资组合。然而，需要注意的是，任何投资组合优化模型都依赖于对未来市场的假设，因此也存在一定的局限性。

资料来源：https://investresolve.com/lp/portfolio-optimization-general-framework/

之前有一篇文章也介绍过部分投资组合优化方法，并且有部分python代码，可参考：[投资组合优化的几种方法](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484969&idx=1&sn=3c200ec29519c6a3fd818f5f1202db45&chksm=9fd3ae39a8a4272f6105fd352d7922ec7349baa2d72dcd5b6c8fe4287107395fdeb94814244b&scene=21#wechat_redirect)