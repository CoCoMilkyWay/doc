# 面板回归与驱动因子选择：跨资产因子研究

InfinityQuant 映翡量化 2026-06-20 08:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491981&idx=1&sn=d6e9ac6b4331c46edf06e944d69b1fd1&chksm=9e87632464ff4a7db41e9f13ac0c8339eea0ba52d255dcebb9eeae11de20b81a8afe51205448#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491981&idx=1&sn=d6e9ac6b4331c46edf06e944d69b1fd1&chksm=9e87632464ff4a7db41e9f13ac0c8339eea0ba52d255dcebb9eeae11de20b81a8afe51205448#rd)

**跨资产因子研究的成败取决于两个关键选择：如何将数据跨资产进行合并（pooling），以及在模型中保留哪些驱动因子。第一点选错，你要么浪费信息，要么掩盖异质性；第二点选错，你的归因就会被样本内偶然胜出的共线性变量所主导。**

QuantInsider的《Panel Regressions and Driver Selection for Cross-Asset Factor Research》（2026年6月9日）分为三个层面：

**1\. 面板回归设定**  

固定效应（Fixed Effects）能够吸收资产特定的截距项，在驱动因子具有持续性时，几乎总是默认的正确选择。随机效应（Random Effects）更有效率，但前提是正交性假设成立，而这一假设通常不成立。对于相对收益研究，Fama-MacBeth 横截面回归方法是另一种可行的替代方案。

**2\. 变量选择**  

宏观面板中的候选驱动因子天然存在相关性：收益率曲线形态变量共享期限结构信息，动量与趋势存在重叠，增长与信用共同反映经济周期。

-   对于较小的候选变量集，逐步选择（Stepwise Selection）能给出清晰的离散结果。
    
-   对于更大的变量集和相关性较强的组别，LASSO 和弹性网（Elastic Net）处理得更为优雅，其中弹性网特别适合将共线性变量组一起保留，而不是任意挑选其中一个。
    

![](assets/001.png)

![](assets/002.png)

**3\. 归因堆叠（Attribution Stacking）**  

最终的“菜谱式”输出是将各驱动因子的贡献份额按资产类别并排展示。横向阅读可了解单一因子在不同市场中的表现；纵向阅读则能刻画每个资产类别的特征。

**三个比方法选择更重要的注意事项**

-   逐步选择会使经典标准误失效，最终模型上的任何 t 统计量都会向上偏差。
    
-   标准的 k 折交叉验证会打乱观测值并导致未来信息泄漏，因此应使用前向链（forward-chaining）或分块交叉验证（blocked CV）。
    
-   在滚动窗口中重新进行变量选择，每次都会产生不同的模型，因此应报告每个变量在历史窗口中存活的频率，而不仅仅是最新一次的变量集合。
    

  

https://www.linkedin.com/company/quant-insider/posts/?feedView=all

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)