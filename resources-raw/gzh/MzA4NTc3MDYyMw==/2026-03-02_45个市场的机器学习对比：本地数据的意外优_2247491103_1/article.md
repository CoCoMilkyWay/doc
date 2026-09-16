# 45个市场的机器学习对比：本地数据的意外优势

InfinityQuant 映翡量化 2026-03-02 09:44 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491103&idx=1&sn=28d38da3071ac74281225d9f436ba11b&chksm=9ef31d7424a648ca8e91d7d2cac0dc8712459316b3d4286932d17e742f431d8ec42f999cf52c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491103&idx=1&sn=28d38da3071ac74281225d9f436ba11b&chksm=9ef31d7424a648ca8e91d7d2cac0dc8712459316b3d4286932d17e742f431d8ec42f999cf52c#rd)

《The more, the better? Predicting stock returns with local and global data》（2026年2月20日）使用机器学习（主要基于elastic net模型）处理147个股票特征（factor zoo），基于来自**45个市场**近三十年（约1990s–2020s）的个股数据，系统比较了**本地训练**（local training，按国家/区域/行业/产业独立训练）和**全局训练**（global training，池化所有国家数据）在预测个股横截面回报时的表现。所有评估均为**样本外。**

**关键内容：**

-   ⚖️ **平均而言**，全局训练并不能持续优于本地训练。两者预测性能相当。
    
-   🌍 当全局池化确实带来改善时，收益主要集中在**较小市场**（smaller markets）和**特异性风险较高**（higher idiosyncratic risk）的市场。这些市场本地数据较少、噪声较大，全局数据能提供更多信息来稳定估计。
    
-   📈 因子（如动量、价值、规模、反转等）在各国间**总体相似**，且这种一致性随时间推移而**增强，反映全球金融市场一体化程度的提高。**
    

**主要结论：**

-   “更多数据并不是更好”。
    
-   在大多数情况下（尤其是发达市场和大中型市场），**本地数据已足够**；全局池化的增量价值有限，甚至可能因引入噪声或异质性而无益。
    
-   随着市场一体化加深，本地模型的优势可能进一步减弱，但目前实证显示本地模型往往更简单、更稳健、计算成本更低，且性能不相上下。
    

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

  

https://www.sciencedirect.com/science/article/pii/S0378426626000324?dgcid=author

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)