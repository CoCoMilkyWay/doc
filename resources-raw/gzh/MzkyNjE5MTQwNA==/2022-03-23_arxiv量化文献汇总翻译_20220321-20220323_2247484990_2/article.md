# arxiv量化文献汇总翻译 20220321-20220323

Shame1ess 量化前沿速递 2022-03-23 23:03

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484990&idx=2&sn=2a16e899ee7c81c9286adcb86617aff2&chksm=c32a29461e8d2a333b4314cefdcd5e38f61d361a50e164ab03a1d6f8b07b5bae9f6e6babf587#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484990&idx=2&sn=2a16e899ee7c81c9286adcb86617aff2&chksm=c32a29461e8d2a333b4314cefdcd5e38f61d361a50e164ab03a1d6f8b07b5bae9f6e6babf587#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

## 

文献汇总

\[1\] Deep Reinforcement Learning and Convex Mean Variance Optimisation for Portfolio Management

投资组合管理的深度强化学习和凸均值-方差优化

\[2\] A General Framework for Impermanent Loss in Automated Market Makers

自动做市商短期亏损的一般框架

\[3\] Markov decision processes with Kusuoka type conditional risk mappings

具有Kusuoka型条件风险映射的马尔可夫决策过程

\[4\] Distributionally robust risk evaluation with causality constraint and structural information

具有因果约束和结构信息的分布稳健风险评估

\[5\] The Gerber Shiu discounted penalty function

Gerber-Shiu折扣罚函数

\[6\] Vulnerability CoVaR

脆弱性CoVaR

\[7\] Representation for martingales living after a random time with applications

随机时间后鞅的表示及其应用

\[8\] GCNET

GCNET

\[9\] Inspection L

检查L

\[10\] Maintenance Problem of Insufficiently Financed Pension Funds A Stochastic Approach

资金不足养老基金的维持问题——一种随机方法

## 

\[1\] Deep Reinforcement Learning and Convex Mean Variance Optimisation for Portfolio Management

标题 : 投资组合管理的深度强化学习和凸均值-方差优化

作者 : Ruan Pretorius, Terence van Zyl , 类别 ：Portfolio Management (q-fin.PM)

说明 : -

Abstract : Traditional portfolio management methods can incorporate specific investor preferences but rely on accurate forecasts of asset returns and covariances. Reinforcement learning (RL) methods do not rely on these explicit forecasts and are better suited for multi stage decision processes. To address limitations of the evaluated research, experiments were conducted on three markets in different economies with different overall trends. By incorporating specific investor preferences into our RL models reward functions, a more comprehensive comparison could be made to traditional methods in risk return space. Transaction costs were also modelled more realistically by including nonlinear changes introduced by market volatility and trading volume. The results of this study suggest that there can be an advantage to using RL methods compared to traditional convex mean variance optimisation methods under certain market conditions. Our RL models could significantly outperform traditional single period optimisation (SPO) and multi period optimisation (MPO) models in upward trending markets, but only up to specific risk limits. In sideways trending markets, the performance of SPO and MPO models can be closely matched by our RL models for the majority of the excess risk range tested. The specific market conditions under which these models could outperform each other highlight the importance of a more comprehensive comparison of Pareto optimal frontiers in risk return space. These frontiers give investors a more granular view of which models might provide better performance for their specific risk tolerance or return targets.

## 

\[2\] A General Framework for Impermanent Loss in Automated Market Makers

标题 : 自动做市商短期亏损的一般框架

作者 : Neelesh Tiruviluamala, Alexander Port, Erik Lewis , 类别 ：Trading and Market Microstructure (q-fin.TR)

说明 : Comments: 24 pages, 5 figures

Abstract : We provide a framework for analyzing impermanent loss for general Automated Market Makers (AMMs) and show that Geometric Mean Market Makers (G3Ms) are in a rigorous sense the simplest class of AMMs from an impermanent loss viewpoint. In this context, it becomes clear why automated market makers like Curve ( Ego19 ) require more parameters in order to specify impermanent loss. We suggest the proper parameter space on which impermanent loss should be considered and prove results that help in understanding the impermanent loss characteristics of different AMMs.

## 

\[3\] Markov decision processes with Kusuoka type conditional risk mappings

标题 : 具有Kusuoka型条件风险映射的马尔可夫决策过程

作者 : Ziteng Cheng, Sebastian Jaimungal , 类别 ：Optimization and Control (math.OC)

说明 : -

Abstract : The Kusuoka representation of proper lower semi continuous law invariant coherent risk measures allows one to cast them in terms of average value at risk. Here, we introduce the notion of Kusuoka type conditional risk mappings and use it to define a dynamic risk measure. We use such dynamic risk measures to study infinite horizon Markov decision processes with random costs and random actions. Under mild assumptions, we derive a dynamic programming principle and prove the existence of an optimal policy. We also derive the Q learning version of the dynamic programming principle, which is important for applications. Furthermore, we provide a sufficient condition for when deterministic actions are optimal.

## 

\[4\] Distributionally robust risk evaluation with causality constraint and structural information

标题 : 具有因果约束和结构信息的分布稳健风险评估

作者 : Bingyan Han , 类别 ：Mathematical Finance (q-fin.MF)

说明 : Comments: 8 figures, 7 tables

Abstract : This work studies distributionally robust evaluation of expected function values over temporal data. A set of alternative measures is characterized by the causal optimal transport. We prove the strong duality and recast the causality constraint as minimization over an infinite dimensional test function space. We approximate test functions by neural networks and prove the sample complexity with Rademacher complexity. Moreover, when structural information is available to further restrict the ambiguity set, we prove the dual formulation and provide efficient optimization methods. Simulation on stochastic volatility and empirical analysis on stock indices demonstrate that our framework offers an attractive alternative to the classic optimal transport formulation.

## 

\[5\] The Gerber Shiu discounted penalty function

标题 : Gerber-Shiu折扣罚函数

作者 : Yue He, Reiichiro Kawai, Yasutaka Shimizu, Kazutoshi Yamazaki , 类别 ：Risk Management (q-fin.RM)

说明 : Comments: 30 pages

Abstract : The Gerber Shiu function provides a unified framework for the evaluation of a variety of risk quantities. Ever since its establishment, it has attracted constantly increasing interests in actuarial science, whereas the conventional research has been focused on finding analytical or semi analytical solutions, either of which is rarely available, except for limited classes of penalty functions on rather simple risk models. In contrast to its great generality, the Gerber Shiu function does not seem sufficiently prevalent in practice, largely due to a variety of difficulties in numerical approximation and statistical inference. To enhance research activities on such implementation aspects, we provide a full review of existing formulations and underlying surplus processes, as well as an extensive survey of analytical, semi analytical and asymptotic methods for the Gerber Shiu function, which altogether shed fresh light on its numerical methods and statistical inference for further developments. On the basis of an exhaustive collection of 207 references, the present survey can serve as an insightful guidebook to model and method selection from practical perspectives as well.

## 

\[6\] Vulnerability CoVaR

标题 : 脆弱性CoVaR

作者 : Martin Waltz, Abhay Kumar Singh, Ostap Okhrin , 类别 ：General Finance (q-fin.GN)

说明 : -

Abstract : This paper proposes an important extension to Conditional Value at Risk (CoVaR), the popular systemic risk measure, and investigates its properties on the cryptocurrency market. The proposed Vulnerability CoVaR (VCoVaR) is defined as the Value at Risk (VaR) of a financial system or institution, given that at least one other institution is equal or below its VaR. The VCoVaR relaxes normality assumptions and is estimated via copula. While important theoretical findings of the measure are detailed, the empirical study analyzes how different distressing events of the cryptocurrencies impact the risk level of each other. The results show that Litecoin displays the largest impact on Bitcoin and that each cryptocurrency is significantly affected if an event of joint distress among the remaining market participants occurs. The VCoVaR is shown to capture domino effects better than other CoVaR extensions.

## 

\[7\] Representation for martingales living after a random time with applications

标题 : 随机时间后鞅的表示及其应用

作者 : Tahir Choulli, Ferdoos Alharbi , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : Our financial setting consists of a market model with two flows of information. The smallest flow F is the public flow of information which is available to all agents, while the larger flow G has additional information about the occurrence of a random time T. This random time can model the default time in credit risk or death time in life insurance. Hence the filtration G is the progressive enlargement of F with T. In this framework, under some mild assumptions on the pair (F, T), we describe explicitly how G local martingales can be represented in terms of F local martingale and parameters of T. This representation complements Choulli, Daveloose and Vanmaele cite ChoulliDavelooseVanmaele to the case when martingales live after T . The application of these results to the explicit parametrization of all deflators under G is fully elaborated. The results are illustrated on the case of jump diffusion model and the discrete time market model.

## 

\[8\] GCNET

标题 : GCNET

作者 : Alireza Jafari, Saman Haratizadeh , 类别 ：Trading and Market Microstructure (q-fin.TR)

说明 : -

Abstract : The prediction of stocks direction of movement using the historical price information has attracted considerable attention as a challenging problem in the field of machine learning. However, modeling and analyzing the hidden relations among stock prices as an important source of information for the prediction of their future behavior has not been explored well yet. The existing methods in this domain suffer from the lack of generality and flexibility and cannot be easily applied on any set of inter related stocks. The main challenges in this domain are to find a way for modeling the existing relations among an arbitrary set of stocks and to exploit such a model for improving the prediction performance for those stocks. In this paper, we introduce a novel framework, called GCNET that models the relations among an arbitrary set of stocks as a graph structure called influence network and uses a set of history based prediction models to infer plausible initial labels for a subset of the stock nodes in the graph. Finally, GCNET uses the Graph Convolutional Network algorithm to analyzes this partially labeled graph and predicts the next price direction of movement for each stock in the graph. GCNET is a general prediction framework that can be applied for the prediction of the price fluctuations for any set of interacting stocks based on their historical data. Our experiments and evaluations on sets of stocks from S &P500 and NASDAQ show that GCNET significantly improves the performance of SOTA in terms of accuracy and MCC measures.

## 

\[9\] Inspection L

标题 : 检查L

作者 : Wai Weng Lo, Siamak Layeghy, Marius Portmann , 类别 ：Cryptography and Security (cs.CR)

说明 : -

Abstract : Criminals have become increasingly experienced in using cryptocurrencies, such as Bitcoin, for money laundering. The use of cryptocurrencies can hide criminal identities and transfer hundreds of millions of dollars of dirty funds through their criminal digital wallets. However, this is considered a paradox because cryptocurrencies are gold mines for open source intelligence, allowing law enforcement agencies to have more power in conducting forensic analyses. This paper proposed Inspection L, a graph neural network (GNN) framework based on self supervised Deep Graph Infomax (DGI), with Random Forest (RF), to detect illicit transactions for Anti Money laundering (AML). To the best of our knowledge, our proposal is the first of applying self supervised GNNs to the problem of AML in Bitcoin. The proposed method has been evaluated on the Elliptic dataset and shows that our approach outperforms the state of the art in terms of key classification metrics, which demonstrates the potential of self supervised GNN in cryptocurrency illicit transaction detection.

## 

\[10\] Maintenance Problem of Insufficiently Financed Pension Funds A Stochastic Approach

标题 : 资金不足养老基金的维持问题——一种随机方法

作者 : Manuel Alberto M. Ferreira , 类别 ：Pricing of Securities (q-fin.PR)

说明 : Comments: 15 pages and no figures

Abstract : The generic case of pensions fund that it is not sufficiently auto financed and it is thoroughly maintained with an external financing effort is considered in this chapter. To represent the unrestricted reserves value process of this kind of funds, a time homogeneous diffusion stochastic process with finite expected time to ruin is proposed. Then it is projected a financial tool that regenerates the diffusion at some level with positive value every time the diffusion hits a barrier placed at the origin. So, the financing effort can be modeled as a renewal reward process if the regeneration level is preserved constant. The perpetual maintenance cost expected values and the finite time maintenance cost evaluations are studied. An application of this approach when the unrestricted reserves value process behaves as a generalized Brownian motion process is presented.