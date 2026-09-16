# 当 Alpha Mining 遇上 Deep Learning：谁才是下一代量化护城河？

InfinityQuant 映翡量化 2026-05-16 08:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491693&idx=1&sn=1978daaf97c12014b4f335659f17a948&chksm=9eab4e53243481885f09d3890a32816ece81a13fb40c53bc3517d0ffbb6f02bdf205eea5a350#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491693&idx=1&sn=1978daaf97c12014b4f335659f17a948&chksm=9eab4e53243481885f09d3890a32816ece81a13fb40c53bc3517d0ffbb6f02bdf205eea5a350#rd)

标题：《Alpha Mining versus Deep Learning Approaches:A Controversial Dilemma in Quantitative Trading》  

作者：Jimmy Hu、Tensor Systems（2026年4月）

论文系统比较了量化Alpha生成的两大范式：Alpha Mining与 Deep Learning (DL)，核心围绕“可持续性、稳定性、护城河、市场环境适配性以及与 Agentic LLM 的协同”五个维度展开，并给出一个范式选择与混合架构设计框架。

## 主要观点

-   量化 alpha 生产已分化为两条主线： Alpha Mining（包括计算搜索、主观研究、微结构与另类数据信号）与Deep Learning (DL)端到端 alpha 系统。
    
-   两者没有绝对优劣，优势取决于市场结构与机构能力：在机构主导、因子丰富、低换手市场（如美股），Alpha Mining 更占优；在行为主导、高换手、非线性环境（如 A 股、商品、加密），Deep Learning 具结构性优势。
    
-   作者认为，从长期技术与算力护城河角度看，“工程良好的Deep Learning系统的护城河增长是二次的，而 Alpha Mining 护城河是线性的”，在持续算力与数据投入的前提下，Deep Learning 在长期风险收益上更有潜力。
    

## Alpha Mining：扩展定义与优劣

-   Alpha Mining 四大支柱：系统化计算挖掘（GP、symbolic regression 等）、主观/研究驱动信号、市场微观结构信号、另类数据与情绪信号；共同特征是“可解释、可独立检验、可加和组合、有审计轨迹和可累积的信号库”。
    
-   可持续性方面：发现阶段算力消耗大，但生产阶段极轻，且对数据需求更小，能在中小型但精心清洗的数据集上产生价值，更易满足监管端对模型可解释性和可审计性的要求。
    
-   稳定性方面：过拟合主要体现为多重检验/回测挖矿，有成熟工具（DSR、CSCV）在“信号层面”筛除过拟合，且库式、多信号组合天然对 regime shift 与信号衰减较为稳健，可按信号粒度做“外科手术”下架或降权。
    
-   护城河来源：深厚且低相关的 alpha 库、成熟的研究流程与组织经验、专有数据管线、持续的新信号生产能力；但对公开或易复制因子极度易受拥挤和套利导致的 alpha 衰减，整体护城河更多是“线性累积”。
    

## Deep Learning：能力与护城河

-   深度学习 alpha 被定义为：大规模神经网络（主要是 Transformer / LSTM）在高维特征矩阵上端到端学习非线性预测或直接给出权重/动作，不预设函数形式，具“高容量、动态特征权重、不可解释”等特性。
    
-   其可持续性依赖 GPU 集群与庞大、多源异质数据（含文本、图像、另类数据）；训练资源消耗巨大且具有重复性（需持续再训练），但在大厂或顶级量化机构环境中，这一成本可被其发现更广、更深信号能力所抵消。
    
-   护城河被重新定义为“系统级护城河”：专有数据与清洗流程、架构配方与训练 recipe、长期累积的训练 compute 历史，以及版本化模型冷存库（cold-storage library）。这些资产外部难以观测和逆向，随时间以“架构创新复利 + 冷存模型复利 + GPU 可扩展性”实现近似二次增长。
    
-   文中提出关键观点：DL 护城河是 time-locked 的，尤其是冷存库——必须经历多个实际市场周期才能形成，无法用一次性投入“买来”；新进入者即便有算力，也难在短期复制一个自 2015 年起积累多轮宏观与风格周期的模型库。
    

## 市场结构与范式选择

-   作者给出一个“组织能力 × 市场结构”的矩阵：算力有限、数据有限、缺乏 ML 工程与受严格可解释监管约束时，应以 Alpha Mining 为主；算力充足、数据广泛、ML 团队完备且市场行为非线性强（A 股、商品、加密）时，适合 DL 主导并配 cold-storage 与自适应模块。
    
-   A 股、商品期货、加密货币被用作结构性案例：高比例散户、政策敏感、异常强的短周期反转与行为效应、线性因子快速拥挤，使端到端 Transformer 这一类模型在 factor half-life、换手与 Sharpe 上有明显优势；同时，高阶矩优化（如 YAND MVSK）在 A 股中也展现出对尾部和回撤的显著改善，提示“DL + 高阶矩优化”的互补潜力。
    

## Agentic LLM 与混合架构结论

-   Agentic LLM 对 Alpha Mining 的加速作用是“全链路”的：可大幅扩展假设空间、自动从文本/经济直觉合成可回测表达式、生成文档和合规材料，并监控文献与披露识别拥挤因子，成为系统化挖掘的放大器。
    
-   在DL系统中，LLM 更偏向外围工具：协助特征工程与架构/超参搜索，解读 SHAP/LRP 归因，并做监控告警，但不直接参与核心梯度学习过程，边际价值小于在 Alpha Mining 中的作用。
    

综合结论：

-   中短期内，两大范式将在不同机构和市场长期并存，并在高端机构中以“混合架构”形式融合——Alpha Mining 提供可解释、可控的基底 alpha 库，DL 提供行为与非线性环境中的增量 alpha 与执行智能。
    

-   从十年以上视角，在算力与数据持续投入的前提下，深度学习系统凭借技术与算力护城河的“复利效应”，更有可能在行为复杂市场上取得更高的长期风险调整收益，但这并不意味着 Alpha Mining 会被淘汰，而是更像从“主角”转为“坚固底座”。
    

![](assets/001.png)

作者之前的三篇大作：

[LLM × 多Agent × 策略市场：如何打造“懂你”的投资组合策略？](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491503&idx=1&sn=215879ed97f6ffea29c55ac31b2b9c6f&scene=21#wechat_redirect)

[动态TWAP优化深度解析：强化学习与传统随机控制的比较实证](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488724&idx=1&sn=c1e86575efaf1250518201c90ce16d8b&scene=21#wechat_redirect)

[如何用AI系统化和可解释地挖掘因子](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488711&idx=1&sn=9880b14b9428cfae9a93d21067a30b44&scene=21#wechat_redirect)

  

以上部分内容是AI整理，想了解更详细内容的看原文：

https://alphanet.global/Alpha%20Mining%20vs%20DL%20V1.pdf

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)