# 大宗商品市场的粗糙波动率动态分析模型

InfinityQuant 映翡量化 2026-04-07 08:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491388&idx=1&sn=786cdc632aec51bd51fe4cb42cb987ff&chksm=9ee5ec94bc82cd6666eccff40df6cfe6f5b084d346b0f6aa9537d113cc20b1252c90f69cc560#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491388&idx=1&sn=786cdc632aec51bd51fe4cb42cb987ff&chksm=9ee5ec94bc82cd6666eccff40df6cfe6f5b084d346b0f6aa9537d113cc20b1252c90f69cc560#rd)

由 R. Daluiso、H. Folgar-Cameán、A. Pallavicini 和 C. Vázquez 撰写的论文《Rough volatility dynamics in commodity markets》（2026年3月30日），主要研究了如何将粗糙波动率模型（Rough Volatility Models）应用于大宗商品市场，并提出了一个通用的建模框架，证明了粗糙波动率模型能比传统模型更准确地捕捉大宗商品市场的动态特征。

文章的核心内容：

**1️⃣目标**：把粗糙波动率模型（Hurst 指数 H<0.5）引入大宗商品市场，给WTI原油期货期权定价，并能自动匹配期货初始期限结构和Samuelson效应（临近交割波动率上升）。

**2️⃣建模框架**：在“虚拟现货价”St框架下，给出一个通用的前向方差模型ξt(u)，推导出期货价格Ft(T)与归一化现货st的解析关系，得到最终模型，其中均值回复速度a(t)既控制Samuelson效应又不破坏期货为鞅。

![](assets/001.png)

**3️⃣具体模型**：在这一通用框架中，重点实现粗糙版Bergomi（rBergomi）与粗糙版Heston（rHeston），并利用已有结果证明相关构造保证无套利；同时给出经典Bergomi/Heston作为对比基准。

**4️⃣实证与校准**：

-   用WTI期货5分钟数据估计得到H≈0.14–0.21，确认原油价格具有“粗糙”特征。
    
-   用2025年3月14日和6月4日NYMEX WTI期货期权数据，采用带权的误差函数和分段线性前向方差曲线进行嵌套校准；粗糙模型拟合略优于经典模型，尤其rBergomi对短期限与笑脸翼端更好，但差距有限。
    

**5️⃣扩展与结论**：

-   将相关系数ρ扩展为与到期相关的分段常数函数，显著提升rBergomi和rHeston的拟合质量，ρ(T)随期限递减，常数ρ大致落在其区间内。
    
-   总体看，粗糙模型在商品市场是可行且略有优势，但经典模型配合“极端参数”也能逼近市场；未来可在更多商品上验证、并更系统地研究H与模型参数的经济含义。
    

![](assets/002.png)

![](assets/003.png)

https://arxiv.org/abs/2603.26514

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/004.png)