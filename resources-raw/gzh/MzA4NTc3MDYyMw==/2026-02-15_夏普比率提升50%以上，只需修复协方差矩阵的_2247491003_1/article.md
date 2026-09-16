# 夏普比率提升50%以上，只需修复协方差矩阵的对角线

InfinityQuant 映翡量化 2026-02-15 09:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491003&idx=1&sn=a3ddf7a3fcf0594eed683d4fa3ce7df7&chksm=9e03aafc868fe3544e8269d9d971a894d3d1545c9764e2d67ea25a05fb1972e9db0587f6b6b3#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491003&idx=1&sn=a3ddf7a3fcf0594eed683d4fa3ce7df7&chksm=9e03aafc868fe3544e8269d9d971a894d3d1545c9764e2d67ea25a05fb1972e9db0587f6b6b3#rd)

**论文《Covariance Implied Risk Factors》（2026年2月11日）指出：标准的PCA（主成分分析）——作为潜在因子估计的基石——其实在暗中受到了****异方差特质方差的严重扭曲。**

解决方案：**heteroPCA**（异方差PCA），通过迭代的方式，用**非对角线协方差结构所隐含的值**来替换对角线元素。

实证结果：

-   在AP-Tree投资组合上，样本外夏普比率提升约**2倍**（0.55 vs 0.26）
    
-   在大多数股票排序维度上，Hansen-Jagannathan距离降低**15–30%**
    
-   得到具有清晰经济含义的因子——例如，标准PCA完全遗漏的**干净的应计项目因子（accrual factor）**
    
-   构建的随机贴现因子（SDF）显示出“**优质 vs 垃圾**”的交易策略，而不是PCA得到的缺乏直观性的“**规模哑铃策略**”
    

核心观点：**系统性风险存在于协方差（非对角线元素）中**，而**异方差噪声会人为放大方差（对角线元素）**。 把噪声剥离后，真实的因子结构就会浮现。

实现方式简单：

-   只需**5次迭代**
    
-   不需要任何额外数据
    
-   可以作为标准PCA的**直接替换**（drop-in replacement）
    

一句话总结：**“对角线去噪”可能是过去二十年因子研究中最被低估、最容易实现的改进之一。**

![](assets/001.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=6136149

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)