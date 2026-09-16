# arxiv量化文献汇总翻译 20210107

Shame1ess 量化前沿速递 2021-01-08 00:01

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247483817&idx=2&sn=8393fdc10b602506403e9816c26aa221&chksm=c3937a7de40367f2c2736693db88e02eba04211bd145682fd2c1783c8243dd5989962667fb59#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247483817&idx=2&sn=8393fdc10b602506403e9816c26aa221&chksm=c3937a7de40367f2c2736693db88e02eba04211bd145682fd2c1783c8243dd5989962667fb59#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Deep learning for efficient frontier calculation in finance

\[2\] Liquidity Stress Testing in Asset Management Part 1. Modeling the Liability Liquidity Risk

## 

\[1\] Deep learning for efficient frontier calculation in finance

标题 : 金融领域有效前沿计算的深度学习

作者 : Xavier Warin , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2101.02044

说明 : Comments: 28 pages, 16 figures

Abstract : We propose deep neural network algorithms to calculate efficient frontier in some Mean Variance and Mean CVaR portfolio optimization problems. We show that we are able to deal with such problems when both the dimension of the state and the dimension of the control are high. Adding some additional constraints, we compare different formulations and show that a new projected feedforward network is able to deal with some global constraints on the weights of the portfolio while outperforming classical penalization methods. All developed formulations are compared in between. Depending on the problem and its dimension, some formulations may be preferred.

摘要 : 在均值-方差和均值-CVaR投资组合优化问题中，我们提出了计算有效前沿的深度神经网络算法。我们证明了当状态维数和控制维数都很高时，我们能够处理这类问题。加入一些额外的约束，我们比较了不同的公式，并证明了一个新的投影前馈网络能够处理投资组合权重的一些全局约束，同时优于经典的惩罚方法。所有开发的配方进行了比较。根据问题及其规模，一些配方可能是首选。

## 

\[2\] Liquidity Stress Testing in Asset Management Part 1. Modeling the Liability Liquidity Risk

标题 : 资产管理中的流动性压力测试第1部分。负债流动性风险建模

作者 : Thierry Roncalli, Fatma Karray-Meziou, François Pan, Margaux Regnault , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2101.02110

说明 : -

Abstract : This article is part of a comprehensive research project on liquidity risk in asset management, which can be divided into three dimensions. The first dimension covers liability liquidity risk (or funding liquidity) modeling, the second dimension focuses on asset liquidity risk (or market liquidity) modeling, and the third dimension considers asset liability liquidity risk management (or asset liability matching). The purpose of this research is to propose a methodological and practical framework in order to perform liquidity stress testing programs, which comply with regulatory guidelines (ESMA, 2019) and are useful for fund managers. The review of the academic literature and professional research studies shows that there is a lack of standardized and analytical models. The aim of this research project is then to fill the gap with the goal to develop mathematical and statistical approaches, and provide appropriate answers. In this first part that focuses on liability liquidity risk modeling, we propose several statistical models for estimating redemption shocks. The historical approach must be complemented by an analytical approach based on zero inflated models if we want to understand the true parameters that influence the redemption shocks. Moreover, we must also distinguish aggregate population models and individual based models if we want to develop behavioral approaches. Once these different statistical models are calibrated, the second big issue is the risk measure to assess normal and stressed redemption shocks. Finally, the last issue is to develop a factor model that can translate stress scenarios on market risk factors into stress scenarios on fund liabilities.

摘要 : 本文是资产管理流动性风险综合研究项目的一部分，可分为三个维度。第一个维度是负债流动性风险（或融资流动性）建模，第二个维度是资产流动性风险（或市场流动性）建模，第三个维度是资产负债流动性风险管理（或资产负债匹配）。本研究的目的是提出一个方法和实践框架，以执行流动性压力测试计划，该计划符合监管准则（ESMA，2019年），并对基金经理有用。对学术文献和专业研究的回顾表明，缺乏规范的分析模型。本研究计画的目的是以发展数理统计方法来填补这个空白，并提供适当的答案。在这第一部分，重点是负债流动性风险模型，我们提出了几个统计模型估计赎回冲击。如果我们想了解影响赎回冲击的真实参数，历史方法必须辅以基于零膨胀模型的分析方法。此外，如果我们想发展行为方法，我们还必须区分总体模型和基于个体的模型。一旦这些不同的统计模型被校准，第二个大问题就是评估正常和压力赎回冲击的风险度量。最后，最后一个问题是建立一个因子模型，将市场风险因素的压力情景转化为基金负债的压力情景。