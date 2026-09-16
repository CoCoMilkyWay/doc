# arxiv量化文献汇总翻译 20220310-20220315

Shame1ess 量化前沿速递 2022-03-15 22:35

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484973&idx=2&sn=ae6573449326e6f3d01972713ca2464a&chksm=c39f21bc023a901f8b36ee0def95ffaf9834150446801fbe7d721dec612205f10b223e780d31#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484973&idx=2&sn=ae6573449326e6f3d01972713ca2464a&chksm=c39f21bc023a901f8b36ee0def95ffaf9834150446801fbe7d721dec612205f10b223e780d31#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

## 

文献汇总

\[1\] Fast Simulation Based Bayesian Estimation of Heterogeneous and Representative Agent Models using Normalizing Flow Neural Networks

基于规范化流神经网络的异构和代表性Agent模型的快速仿真贝叶斯估计

\[2\] Regression Monte Carlo for Impulse Control

脉冲控制的回归蒙特卡罗方法

\[3\] Improving Macroeconomic Model Validity and Forecasting Performance with Pooled Country Data using Structural, Reduced Form, and Neural Network Model

使用结构模型、简化模型和神经网络模型，利用汇集的国家数据提高宏观经济模型的有效性和预测性能

\[4\] Calibration of Derivative Pricing Models

衍生品定价模型的校准

\[5\] Bridging the gap between pricing and reserving with an occurrence and development model for non life insurance claims

通过非寿险索赔的发生和发展模型弥合定价和准备金之间的差距

\[6\] Granular Linkages, Supplier Cost Shocks & Export Performance

细粒度联系、供应商成本冲击和出口绩效

\[7\] A Comparative Study on Forecasting of Retail Sales

零售额预测的比较研究

\[8\] Labor Demand on a Tight Leash

紧绷的劳动力需求

\[9\] Social Networks and Spatial Mobility

社交网络与空间流动

\[10\] Some applications of TDA on financial markets

TDA在金融市场上的一些应用

\[11\] Fusion of Sentiment and Asset Price Predictions for Portfolio Optimization

投资组合优化中情绪和资产价格预测的融合

\[12\] Analytical Pricing of 2 Factor Structural PDE model for a Puttable Bond with Credit Risk

具有信用风险的可售债券二因素结构PDE模型的分析定价

\[13\] General properties of the Solutions to Moving Boundary Problems for Black Sholes Equations

Black Sholes方程移动边界问题解的一般性质

\[14\] Structure of international trade hypergraphs

国际贸易超图的结构

\[15\] Optimal times to buy and sell a home

买卖房屋的最佳时机

\[16\] Multi Objective reward generalization

多目标奖励推广

\[17\] The management of scientific and technological infrastructures

科技基础设施的管理

\[18\] Quantum advantage for multi option portfolio pricing and valuation adjustments

多期权组合定价和估值调整的量子优势

\[19\] On the surplus management of funds with assets and liabilities in presence of solvency requirements

论有偿付能力要求的资产负债基金的盈余管理

## 

\[1\] Fast Simulation Based Bayesian Estimation of Heterogeneous and Representative Agent Models using Normalizing Flow Neural Networks

标题 : 基于规范化流神经网络的异构和代表性Agent模型的快速仿真贝叶斯估计

作者 : Cameron Fen , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This paper proposes a simulation based deep learning Bayesian procedure for the estimation of macroeconomic models. This approach is able to derive posteriors even when the likelihood function is not tractable. Because the likelihood is not needed for Bayesian estimation, filtering is also not needed. This allows Bayesian estimation of HANK models with upwards of 800 latent states as well as estimation of representative agent models that are solved with methods that don t yield a likelihood for example, projection and value function iteration approaches. I demonstrate the validity of the approach by estimating a 10 parameter HANK model solved via the Reiter method that generates 812 covariates per time step, where 810 are latent variables, showing this can handle a large latent space without model reduction. I also estimate the algorithm with an 11 parameter model solved via value function iteration, which cannot be estimated with Metropolis Hastings or even conventional maximum likelihood estimators. In addition, I show the posteriors estimated on Smets Wouters 2007 are higher quality and faster using simulation based inference compared to Metropolis Hastings. This approach helps address the computational expense of Metropolis Hastings and allows solution methods which don t yield a tractable likelihood to be estimated.

## 

\[2\] Regression Monte Carlo for Impulse Control

标题 : 脉冲控制的回归蒙特卡罗方法

作者 : Mike Ludkovski , 类别 ：Computational Finance (q-fin.CP)

说明 : Comments: 18 pages

Abstract : I develop a numerical algorithm for stochastic impulse control in the spirit of Regression Monte Carlo for optimal stopping. The approach consists in generating statistical surrogates (aka functional approximators) for the continuation function. The surrogates are recursively trained by empirical regression over simulated state trajectories. In parallel, the same surrogates are used to learn the intervention function characterizing the optimal impulse amounts. I discuss appropriate surrogate types for this task, as well as the choice of training sets. Case studies from forest rotation and irreversible investment illustrate the numerical scheme and highlight its flexibility and extensibility. Implementation in texttt R is provided as a publicly available package posted on GitHub.

## 

\[3\] Improving Macroeconomic Model Validity and Forecasting Performance with Pooled Country Data using Structural, Reduced Form, and Neural Network Model

标题 : 使用结构模型、简化模型和神经网络模型，利用汇集的国家数据提高宏观经济模型的有效性和预测性能

作者 : Cameron Fen, Samir Undavia , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : We show that pooling countries across a panel dimension to macroeconomic data can improve by a statistically significant margin the generalization ability of structural, reduced form, and machine learning (ML) methods to produce state of the art results. Using GDP forecasts evaluated on an out of sample test set, this procedure reduces root mean squared error by 12 across horizons and models for certain reduced form models and by 24 across horizons for dynamic structural general equilibrium models. Removing US data from the training set and forecasting out of sample country wise, we show that reduced form and structural models are more policy invariant when trained on pooled data, and outperform a baseline that uses US data only. Given the comparative advantage of ML models in a data rich regime, we demonstrate that our recurrent neural network model and automated ML approach outperform all tested baseline economic models. Robustness checks indicate that our outperformance is reproducible, numerically stable, and generalizable across models.

## 

\[4\] Calibration of Derivative Pricing Models

标题 : 衍生品定价模型的校准

作者 : Nelson Vadori , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : One of the most fundamental questions in quantitative finance is the existence of continuous time diffusion models that fit market prices of a given set of options. Traditionally, one employs a mix of intuition, theoretical and empirical analysis to find models that achieve exact or approximate fits. Our contribution is to show how a suitable game theoretical formulation of this problem can help solve this question by leveraging existing developments in modern deep multi agent reinforcement learning to search in the space of stochastic processes. More importantly, we hope that our techniques can be leveraged and extended by the community to solve important problems in that field, such as the joint SPX VIX calibration problem. Our experiments show that we are able to learn local volatility, as well as path dependence required in the volatility process to minimize the price of a Bermudan option. In one sentence, our algorithm can be seen as a particle method a la Guyon et Henry Labordere where particles, instead of being designed to ensure sigma loc (t,S t) 2 mathbb E sigma t 2 S t , are learning RL driven agents cooperating towards more general calibration targets. This is the first work bridging reinforcement learning with the derivative calibration problem.

## 

\[5\] Bridging the gap between pricing and reserving with an occurrence and development model for non life insurance claims

标题 : 通过非寿险索赔的发生和发展模型弥合定价和准备金之间的差距

作者 : Jonas Crevecoeur, Katrien Antonio, Stijn Desmedt, Alexandre Masquelein , 类别 ：Risk Management (q-fin.RM)

说明 : -

Abstract : Due to the presence of reporting and settlement delay, claim data sets collected by non life insurance companies are typically incomplete, facing right censored claim count and claim severity observations. Current practice in non life insurance pricing tackles these right censored data via a two step procedure. First, best estimates are computed for the number of claims that occurred in past exposure periods and the ultimate claim severities, using the incomplete, historical claim data. Second, pricing actuaries build predictive models to estimate technical, pure premiums for new contracts by treating these best estimates as actual observed outcomes, hereby neglecting their inherent uncertainty. We propose an alternative one step approach suitable for both non life pricing and reserving. As such we effectively bridge these two key actuarial tasks that have traditionally been discussed in silos. Hereto we develop a granular occurrence and development model for non life claims that allows to resolve the inconsistency in traditional pricing techniques between actual, complete observations on the one hand and best estimates on the other hand. We illustrate our proposed model on a reinsurance portfolio, where large uncertainties in the best estimates originate from long reporting and settlement delays, low claim frequencies and heavy (even extreme) claim sizes.

## 

\[6\] Granular Linkages, Supplier Cost Shocks & Export Performance

标题 : 细粒度联系、供应商成本冲击和出口绩效

作者 : Santiago Camara , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This paper presents evidence on the granular nature of firms network of foreign suppliers and studies its implications for the impact of supplier shocks on domestic firms performance. To demonstrate this, I use customs level information on transactions between Argentinean firms and foreign firms. I highlight two novel stylized facts (i) the distribution of domestic firms number of foreign suppliers is highly skewed with the median firm reporting linkages with only two, (ii) firms focus imported value on one top supplier, even when controlling for firm size. Motivated by these facts I construct a theoretical framework of heterogeneous firms subject to search frictions in the market for foreign suppliers. Through a calibration exercise I study the framework s predictions and test them in the data using a shift share identification strategy. Results present evidence of significant frictions in the market for foreign suppliers and strong import export complementarities.

## 

\[7\] A Comparative Study on Forecasting of Retail Sales

标题 : 零售额预测的比较研究

作者 : Md Rashidul Hasan, Muntasir A Kabir, Rezoan A Shuvro, Pankaz Das , 类别 ：Machine Learning (cs.LG)

说明 : -

Abstract : Predicting product sales of large retail companies is a challenging task considering volatile nature of trends, seasonalities, events as well as unknown factors such as market competitions, change in customer s preferences, or unforeseen events, e.g., COVID 19 outbreak. In this paper, we benchmark forecasting models on historical sales data from Walmart to predict their future sales. We provide a comprehensive theoretical overview and analysis of the state of the art timeseries forecasting models. Then, we apply these models on the forecasting challenge dataset (M5 forecasting by Kaggle). Specifically, we use a traditional model, namely, ARIMA (Autoregressive Integrated Moving Average), and recently developed advanced models e.g., Prophet model developed by Facebook, light gradient boosting machine (LightGBM) model developed by Microsoft and benchmark their performances. Results suggest that ARIMA model outperforms the Facebook Prophet and LightGBM model while the LightGBM model achieves huge computational gain for the large dataset with negligible compromise in the prediction accuracy.

## 

\[8\] Labor Demand on a Tight Leash

标题 : 紧绷的劳动力需求

作者 : Mario Bossler, Martin Popp , 类别 ：General Economics (econ.GN)

说明 : Comments: 67 pages

Abstract : Although theory highlights search frictions in tight labor markets, standard models of labor demand do not account for labor market tightness. Given the universe of administrative employment data on Germany, we study the effect of labor market tightness on firms labor demand using novel Bartik instruments that rely on predetermined firm shares and national shifts at the occupation level. In line with theory, the IV results suggest that a 10 percent increase in labor market tightness reduces firms employment by 0.5 percent. When accounting for search externalities, we find that the individual firm wage elasticity of labor demand reduces from 0.7 to 0.5 at the aggregate level. For the 2015 minimum wage introduction, the elasticities imply only modest disemployment effects mirroring empirical ex post evaluations. Moreover, the doubling of tightness between 2012 and 2019 led to a significant slowdown in employment growth by 1.1 million jobs.

## 

\[9\] Social Networks and Spatial Mobility

标题 : 社交网络与空间流动

作者 : Harshil Sahai, Mike Bailey , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This paper studies the role of social networks in spatial mobility across India. Using aggregated and de identified data from the world s largest online social network, we (i) document new descriptive findings on the structure of social networks and spatial mobility in India (ii) quantify the effects of social networks on annual migration choice and (iii) embed these estimates in a spatial equilibrium model to study the wage implications of increasing social connectedness. Across millions of individuals, we find that multiple measures of social capital are concentrated among the rich and educated and among migrants. Across destinations, both mobility patterns and social networks are concentrated toward richer areas. A model of migration suggests individuals are indifferent between a 10 increase in destination wages and a 12 16 increase in destination social networks. Accounting for networks reduces the migration distance relationship by 19 . In equilibrium, equalizing social networks across locations improves average wages by 3 (24 for the bottom wage quartile), a larger impact than removing the marginal cost of distance. We find evidence of an economic support mechanism, with destination economic improvements reducing the migration network elasticity. We also find suggestive evidence for an emotional support mechanism from qualitative surveys among Facebook users. Difference in difference estimates suggest college attendance delivers a 20 increase in network size and diversity. Taken together, our data suggest that by reducing effective moving costs increasing social connectedness across space may have considerable economic gains.

## 

\[10\] Some applications of TDA on financial markets

标题 : TDA在金融市场上的一些应用

作者 : Miguel Angel Ruiz-Ortiz, José Carlos Gómez-Larrañaga, Jesús Rodríguez-Viorato , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : The Topological Data Analysis (TDA) has had many applications. However, financial markets has been studied slightly through TDA. Here we present a quick review of some recent applications of TDA on financial markets and propose a new turbulence index based on persistent homology the fundamental tool for TDA that seems to capture critical transitions on financial data, based on our experiment with SP500 data before 2020 stock market crash in February 20, 2020, due to the COVID 19 pandemic. We review applications in the early detection of turbulence periods in financial markets and how TDA can help to get new insights while investing and obtain superior risk adjusted returns compared with investing strategies using classical turbulence indices as VIX and the Chow s index based on the textit Mahalanobis distance. Furthermore, we include an introduction to persistent homology so the reader could be able to understand this paper without knowing TDA.

## 

\[11\] Fusion of Sentiment and Asset Price Predictions for Portfolio Optimization

标题 : 投资组合优化中情绪和资产价格预测的融合

作者 : Mufhumudzi Muthivhi, Terence L. van Zyl , 类别 ：Portfolio Management (q-fin.PM)

说明 : Comments: 9 pages, 4 figures, 6 tables

Abstract : The fusion of public sentiment data in the form of text with stock price prediction is a topic of increasing interest within the financial community. However, the research literature seldom explores the application of investor sentiment in the Portfolio Selection problem. This paper aims to unpack and develop an enhanced understanding of the sentiment aware portfolio selection problem. To this end, the study uses a Semantic Attention Model to predict sentiment towards an asset. We select the optimal portfolio through a sentiment aware Long Short Term Memory (LSTM) recurrent neural network for price prediction and a mean variance strategy. Our sentiment portfolio strategies achieved on average a significant increase in revenue above the non sentiment aware models. However, the results show that our strategy does not outperform traditional portfolio allocation strategies from a stability perspective. We argue that an improved fusion of sentiment prediction with a combination of price prediction and portfolio optimization leads to an enhanced portfolio selection strategy.

## 

\[12\] Analytical Pricing of 2 Factor Structural PDE model for a Puttable Bond with Credit Risk

标题 : 具有信用风险的可售债券二因素结构PDE模型的分析定价

作者 : Hyong Chol O, Dae Song Choe, Gyong-Dok Rim , 类别 ：Pricing of Securities (q-fin.PR)

说明 : Comments: 12 pages

Abstract : In this paper is proposed a 2 factor structural PDE model of pricing puttable bond with credit risk and derived the analytical pricing formula. To this end, first, a 2 factor structural (PDE) model of pricing zero coupon bond with credit risk is provided, the analytical pricing formula is derived under some conditions for default boundary and default recovery, and the strict monotonicity of the bond price function with respect to the firm value variable is proved. Then a (2 factor) pricing model of the option on zero coupon bond with credit risk is provided and under some condition on the exercise price its analytical pricing formula is derived by transforming the 2 factor model into a terminal boundary value problem for Black Scholes equation with time dependent coefficient using zero coupon bond as numeraire. Using it, we provide the pricing formulae of the puttable and callable bonds with credit risk.

## 

\[13\] General properties of the Solutions to Moving Boundary Problems for Black Sholes Equations

标题 : Black Sholes方程移动边界问题解的一般性质

作者 : Hyong-Chol O, Tae-Song Choe , 类别 ：Pricing of Securities (q-fin.PR)

说明 : Comments: 22 pages

Abstract : We study general properties such as the solution representation of a moving boundary value problem of the Black Scholes equation, its min max estimation, lower and upper gradient estimates, and strict monotonicity with respect to the spatial variables of the solution. These results are used in the study of a structural model of pricing puttable bond with credit risk. We first prove the solution representation of a special fixed boundary value problem of the Black Scholes equation, the min max estimate, the lower and upper gradient estimates, and the strict monotonicity with respect to the spatial variables of the solution. Then, these results are applied to give the solution representation of a moving boundary value problem of the Black Scholes equation with moving boundary in the form of an exponential function, the min max estimate, the lower and upper gradient estimates, and the strict monotonicity results on the spatial variables of the solution. Finally, we illustrate how these results can be used in the derivation of analytical pricing formulae and financial analysis of price functions of puttable bonds with credit risk (corporate bonds with one early redemption date). Our results can be used for the derivation and analysis of the analytical pricing formulae of the one factor structural model of a more general puttable bonds with credit risk (corporate bond with several early redemption dates).

## 

\[14\] Structure of international trade hypergraphs

标题 : 国际贸易超图的结构

作者 : Sudo Yi, Deok-Sun Lee , 类别 ：Physics and Society (physics.soc-ph)

说明 : Comments: 11 pages, 6 figures

Abstract : We study the structure of the international trade hypergraph consisting of triangular hyperedges representing the exporter importer product relationship. Measuring the mean hyperdegree of the adjacent vertices, we first find its behaviors different from those in the pairwise networks and explain the origin by tracing the relation between the hyperdegree and the pairwise degree. To interpret the observed hyperdegree correlation properties in the context of trade strategies, we decompose the correlation into two components by identifying one with the background correlation remnant even in the exponential random hypergraphs preserving the given empirical hyperdegree sequence. The other component characterizes the net correlation and reveals the bias of the exporters of low hyperdegree towards the importers of high hyperdegree and the products of low hyperdegree, which information is not readily accessible in the pairwise networks. Our study demonstrates the power of the hypergraph approach in the study of real world complex systems and offers a theoretical framework.

## 

\[15\] Optimal times to buy and sell a home

标题 : 买卖房屋的最佳时机

作者 : Matthew Lorig, Natchanon Suaysom , 类别 ：Mathematical Finance (q-fin.MF)

说明 : Comments: 21 pages, 5 figures

Abstract : We consider a financial market in which the risk free rate of interest is modeled as a Markov diffusion. We suppose that home prices are set by a representative home buyer, who can afford to pay only a fixed cash flow per unit time for housing. The cash flow is a fraction of the representative home buyer s salary, which grows at a rate that is proportional to the risk free rate of interest. As a result, in the long run, higher interest rates lead to faster growth of home prices. The representative home buyer finances the purchase of a home by taking out a mortgage. The mortgage rate paid by the home buyer is fixed at the time of purchase and equal to the risk free rate of interest plus a positive constant. As the home buyer can only afford to pay a fixed cash flow per unit time, a higher mortgage rate limits the size of the loan the home buyer can take out. As a result, the short term effect of higher interest rates is to lower the value of homes. In this setting, we consider an investor who wishes to buy and then sell a home in order to maximize his discounted expected profit. This leads to a nested optimal stopping problem. We use a nonnegative concave majorant approach to derive the investor s optimal buying and selling strategies. Additionally, we provide a detailed analytic and numerical study of the case in which the risk free rate of interest is modeled by a Cox Ingersoll Ross (CIR) process. We also examine, in the case of CIR interest rates, the expected time that the investor waits before buying and then selling a home when following the optimal strategies.

## 

\[16\] Multi Objective reward generalization

标题 : 多目标奖励推广

作者 : Federico Cornalba, Constantin Disselkamp, Davide Scassola, Christopher Helf , 类别 ：Machine Learning (cs.LG)

说明 : Comments: 9 pages, 12 figures

Abstract : We investigate the potential of Multi Objective, Deep Reinforcement Learning for stock and cryptocurrency trading. More specifically, we build on the generalized setting a la Fontaine and Friedman arXiv 1809.06364 (where the reward weighting mechanism is not specified a priori, but embedded in the learning process) by complementing it with computational speed ups, and adding the cumulative reward s discount factor to the learning process. Firstly, we verify that the resulting Multi Objective algorithm generalizes well, and we provide preliminary statistical evidence showing that its prediction is more stable than the corresponding Single Objective strategy s. Secondly, we show that the Multi Objective algorithm has a clear edge over the corresponding Single Objective strategy when the reward mechanism is sparse (i.e., when non null feedback is infrequent over time). Finally, we discuss the generalization properties of the discount factor. The entirety of our code is provided in open source format.

## 

\[17\] The management of scientific and technological infrastructures

标题 : 科技基础设施的管理

作者 : L. Munguía, J. C. Escalante, E. Robles Belmont , 类别 ：Physics and Society (physics.soc-ph)

说明 : Comments: 24 pages, 3 figures, 5 tables, research article

Abstract : The effectiveness of research units is assessed on the basis of their performance in relation to scientific, technological and innovation production, the quality of their results and their contribution to the solution of scientific and social problems. This paper examines the management practices employed in some Mexican National Laboratories in order to identify those that could explain their effectiveness in meeting their objectives. The results of other works that propose common elements among laboratories with outstanding performance are used and verified directly in the field. Considering the inherent complexity of each field of knowledge and the socio spatial characteristics in which the laboratories operate, we report which management practices are relevant for their effectiveness, how they contribute to their consolidation as fundamental scientific and technological infrastructures, how these can be translated into indicators that support the evaluation of their performance, and still pending.

## 

\[18\] Quantum advantage for multi option portfolio pricing and valuation adjustments

标题 : 多期权组合定价和估值调整的量子优势

作者 : Jeong Yu Han, Patrick Rebentrost , 类别 ：Quantum Physics (quant-ph)

说明 : Comments: 42 pages, 1 figure, based on a BComp Dissertation at National University of Singapore

Abstract : A critical problem in the financial world deals with the management of risk, from regulatory risk to portfolio risk. Many such problems involve the analysis of securities modelled by complex dynamics that cannot be captured analytically, and hence rely on numerical techniques that simulate the stochastic nature of the underlying variables. These techniques may be computationally difficult or demanding. Hence, improving these methods offers a variety of opportunities for quantum algorithms. In this work, we study the problem of Credit Valuation Adjustments (CVAs) which have significant importance in the valuation of derivative portfolios. We propose quantum algorithms that accelerate statistical sampling processes to approximate the CVA under different measures of dispersion, using known techniques in Quantum Monte Carlo (QMC) and analyse the conditions under which we may employ these techniques.

## 

\[19\] On the surplus management of funds with assets and liabilities in presence of solvency requirements

标题 : 论有偿付能力要求的资产负债基金的盈余管理

作者 : Benjamin Avanzi, Ping Chen, Lars Frederik Brandt Henriksen, Bernard Wong , 类别 ：Optimization and Control (math.OC)

说明 : -

Abstract : In this paper we consider a company whose assets and liabilities evolve according to a correlated bivariate geometric Brownian motion, such as in Gerber and Shiu (2003). We determine what dividend strategy maximises the expected present value of dividends until ruin in two cases (i) when shareholders won t cover surplus shortfalls and a solvency constraint (as in Paulsen, 2003) is consequently imposed, and (ii) when shareholders are always to fund any capital deficiency with capital (asset) injections. In the latter case, ruin will never occur and the objective is to maximise the difference between dividends and capital injections. Developing and using appropriate verification lemmas, we show that the optimal dividend strategy is, in both cases, of barrier type. Both value functions are derived in closed form. Furthermore, the barrier is defined on the ratio of assets to liabilities, which mimics some of the dividend strategies that can be observed in practice by insurance companies. Existence and uniqueness of the optimal strategies are shown. Results are illustrated.