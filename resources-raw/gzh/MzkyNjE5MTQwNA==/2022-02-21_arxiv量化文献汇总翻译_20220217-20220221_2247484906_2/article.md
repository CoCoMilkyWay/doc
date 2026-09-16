# arxiv量化文献汇总翻译 20220217-20220221

Shame1ess 量化前沿速递 2022-02-21 22:52

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484906&idx=2&sn=30a5a0b20baa1622f862f04bccf8e826&chksm=c36f17438b3659d6808907918b6c07aa8e020a804f94d5a488afa7e839245d39f022b2324670#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484906&idx=2&sn=30a5a0b20baa1622f862f04bccf8e826&chksm=c36f17438b3659d6808907918b6c07aa8e020a804f94d5a488afa7e839245d39f022b2324670#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

## 

文献汇总

\[1\] Hierarchical Sensitivity Parity

分层灵敏度奇偶校验

\[2\] Volatility forecasting with machine learning and intraday commonality

基于机器学习和日内通用性的波动率预测

\[3\] Constructing a NFT Price Index and Applications

NFT价格指数的构建及应用

\[4\] Ensemble and Multimodal Approach for Forecasting Cryptocurrency Price

密码货币价格预测的集成和多模态方法

\[5\] Stock Embeddings

股票嵌入

\[6\] Caplet pricing in affine models for risk free rates

无风险利率仿射模型中的Caplet定价

\[7\] Introduction of the Market Based Price Autocorrelation

引入基于市场的价格自相关

\[8\] Machine Learning Models in Stock Market Prediction

股市预测中的机器学习模型

\[9\] A 3D index for measuring economic resilience with application to the modern international and global financial crises

衡量经济恢复力的3D指数及其在现代国际和全球金融危机中的应用

\[10\] Emerging trends in soybean industry

大豆产业的新趋势

\[11\] Objectives of platform research

平台研究的目标

\[12\] Transparency principle for carbon emissions drives sustainable finance

碳排放透明度原则推动可持续金融

\[13\] Solving Multi Period Financial Planning Models

求解多期财务规划模型

\[14\] A Short Survey on Business Models of Decentralized Finance (DeFi) Protocols

关于分散金融（DeFi）协议商业模式的简短调查

\[15\] An SMP Based Algorithm for Solving the Constrained Utility Maximization Problem via Deep Learning

基于SMP的深度学习约束效用最大化算法

\[16\] Toward an efficient hybrid method for pricing barrier options on assets with stochastic volatility

随机波动资产上障碍期权定价的有效混合方法

\[17\] Agricultural Windfalls and the Seasonality of Political Violence in Africa

农业意外之财和非洲政治暴力的季节性

\[18\] Optimal market completion through financial derivatives with applications to volatility risk

通过金融衍生品实现市场最优完成，并应用于波动风险

\[19\] A note on hospital financing

关于医院融资的一点注记

## 

\[1\] Hierarchical Sensitivity Parity

标题 : 分层灵敏度奇偶校验

作者 : Alejandro Rodriguez , 类别 ：Portfolio Management (q-fin.PM)

说明 : Comments: 20 Pages, 10 figures

Abstract : In this work we present a new framework for modelling portfolio dynamics and how to incorporate this information in the portfolio selection process. We define drivers for asset and portfolio dynamics, and their optimal selection. We introduce the new Commonality Principle, which gives a solution for the optimal selection of portfolio drivers as being the common drivers. Asset dynamics are modelled by PDEs and approximated with Neural Networks, and sensitivities of portfolio constituents with respect to portfolio common drivers are obtained via Automatic Adjoint Differentiation (AAD). Information of asset dynamics is incorporated via sensitivities into the portfolio selection process. Portfolio constituents are projected into a hypersurface, from a vector space formed by the returns of common drivers of the portfolio. The commonality principle allows for the necessary geometric link between the hyperplane formed by portfolio constituents in a traditional setup with no exogenous information, and the hypersurface formed by the vector space of common portfolio drivers, so that when portfolio constituents are projected into this hypersurface, the representations of idiosyncratic risks from the hyperplane are kept at most in this new subspace, while systematic risks representations are added via exogenous information as part of this common drivers vector space. We build a sensitivity matrix, which is a similarity matrix of the projections in this hypersurface, and can be used to optimize for diversification on both, idiosyncratic and systematic risks, which is not contemplated on the literature. Finally, we solve the convex optimization problem for optimal diversification by applying a hierarchical clustering to the sensitivity matrix, avoiding quadratic optimizers for the matrix properties, and we reach over performance in all experiments with respect to all other out of sample methods.

## 

\[2\] Volatility forecasting with machine learning and intraday commonality

标题 : 基于机器学习和日内通用性的波动率预测

作者 : Chao Zhang, Yihuang Zhang, Mihai Cucuringu, Zhongmin Qian , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: 36 pages, 12 figures, 9 tables

Abstract : We apply machine learning models to forecast intraday realized volatility (RV), by exploiting commonality in intraday volatility via pooling stock data together, and by incorporating a proxy for the market volatility. Neural networks dominate linear regressions and tree models in terms of performance, due to their ability to uncover and model complex latent interactions among variables. Our findings remain robust when we apply trained models to new stocks that have not been included in the training set, thus providing new empirical evidence for a universal volatility mechanism among stocks. Finally, we propose a new approach to forecasting one day ahead RVs using past intraday RVs as predictors, and highlight interesting diurnal effects that aid the forecasting mechanism. The results demonstrate that the proposed methodology yields superior out of sample forecasts over a strong set of traditional baselines that only rely on past daily RVs.

## 

\[3\] Constructing a NFT Price Index and Applications

标题 : NFT价格指数的构建及应用

作者 : Hugo Schnoering, Hugo Inzirillo , 类别 ：General Finance (q-fin.GN)

说明 : -

Abstract : We are witnessing the emergence of a new digital art market, the art market 3.0. Blockchain technology has taken on a new sector which is still not well known, Non Fungible tokens (NFT). In this paper we propose a new methodology to build a NFT Price Index that represents this new market on the whole. In addition, this index will allow us to have a look on the dynamics and performances of NFT markets, and to diagnose them.

## 

\[4\] Ensemble and Multimodal Approach for Forecasting Cryptocurrency Price

标题 : 密码货币价格预测的集成和多模态方法

作者 : Zeyd Boukhers, Azeddine Bouabdallah, Matthias Lohr, Jan Jürjens , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : Since the birth of Bitcoin in 2009, cryptocurrencies have emerged to become a global phenomenon and an important decentralized financial asset. Due to this decentralization, the value of these digital currencies against fiat currencies is highly volatile over time. Therefore, forecasting the crypto fiat currency exchange rate is an extremely challenging task. For reliable forecasting, this paper proposes a multimodal AdaBoost LSTM ensemble approach that employs all modalities which derive price fluctuation such as social media sentiments, search volumes, blockchain information, and trading data. To better support investment decision making, the approach forecasts also the fluctuation distribution. The conducted extensive experiments demonstrated the effectiveness of relying on multimodalities instead of only trading data. Further experiments demonstrate the outperformance of the proposed approach compared to existing tools and methods with a 19.29 improvement.

## 

\[5\] Stock Embeddings

标题 : 股票嵌入

作者 : Rian Dolphin, Barry Smyth, Ruihai Dong , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: Currently under review. 9 pages, 4 figures

Abstract : Identifying meaningful relationships between the price movements of financial assets is a challenging but important problem in a variety of financial applications. However with recent research, particularly those using machine learning and deep learning techniques, focused mostly on price forecasting, the literature investigating the modelling of asset correlations has lagged somewhat. To address this, inspired by recent successes in natural language processing, we propose a neural model for training stock embeddings, which harnesses the dynamics of historical returns data in order to learn the nuanced relationships that exist between financial assets. We describe our approach in detail and discuss a number of ways that it can be used in the financial domain. Furthermore, we present the evaluation results to demonstrate the utility of this approach, compared to several important benchmarks, in two real world financial analytics tasks.

## 

\[6\] Caplet pricing in affine models for risk free rates

标题 : 无风险利率仿射模型中的Caplet定价

作者 : Claudio Fontana , 类别 ：Pricing of Securities (q-fin.PR)

说明 : Comments: 17 pages

Abstract : Risk free rates (RFRs) play a central role in the reform of interest rate benchmarks. We study a model for RFRs driven by a general affine process. In this context, under minimal assumptions, we derive explicit valuation formulas for forward looking and backward looking caplets floorlets, term basis caplets as well as 1 month and 3 month RFR futures contracts.

## 

\[7\] Introduction of the Market Based Price Autocorrelation

标题 : 引入基于市场的价格自相关

作者 : Victor Olkhov , 类别 ：General Economics (econ.GN)

说明 : Comments: 13 pages

Abstract : This paper considers direct dependence of the market price autocorrelation on statistical moments of the market trades as a must necessary requirement. We regard market time series of the trade value and volume as origin of price time series. That determines dependence of the market based averaging of price on averaging of the trade value and volume time series. We introduce the market based price statistical moments as functions of the statistical moments of trade value and volume. Moving average helps define the market based price statistical moments with time lag and introduce the price time autocorrelation as function of time lag statistical moments of the trade value and volume. Statistical moments of the market trade value and volume are determined by conventional frequency based probability measures. However, the price statistical moments and the price autocorrelation in particular are determined by the market based probability measure that differs from the conventional frequency based price probability. That distinction leads to different treatments of the price autocorrelation via market based and frequency based approach. To assess market dependence of price statistical moments and price autocorrelation one should revise results founded on frequency based approach.

## 

\[8\] Machine Learning Models in Stock Market Prediction

标题 : 股市预测中的机器学习模型

作者 : Gurjeet Singh , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : The paper focuses on predicting the Nifty 50 Index by using 8 Supervised Machine Learning Models. The techniques used for empirical study are Adaptive Boost (AdaBoost), k Nearest Neighbors (kNN), Linear Regression (LR), Artificial Neural Network (ANN), Random Forest (RF), Stochastic Gradient Descent (SGD), Support Vector Machine (SVM) and Decision Trees (DT). Experiments are based on historical data of Nifty 50 Index of Indian Stock Market from 22nd April, 1996 to 16th April, 2021, which is time series data of around 25 years. During the period there were 6220 trading days excluding all the non trading days. The entire trading dataset was divided into 4 subsets of different size 25 of entire data, 50 of entire data, 75 of entire data and entire data. Each subset was further divided into 2 parts training data and testing data. After applying 3 tests Test on Training Data, Test on Testing Data and Cross Validation Test on each subset, the prediction performance of the used models were compared and after comparison, very interesting results were found. The evaluation results indicate that Adaptive Boost, k Nearest Neighbors, Random Forest and Decision Trees under performed with increase in the size of data set. Linear Regression and Artificial Neural Network shown almost similar prediction results among all the models but Artificial Neural Network took more time in training and validating the model. Thereafter Support Vector Machine performed better among rest of the models but with increase in the size of data set, Stochastic Gradient Descent performed better than Support Vector Machine.

## 

\[9\] A 3D index for measuring economic resilience with application to the modern international and global financial crises

标题 : 衡量经济恢复力的3D指数及其在现代国际和全球金融危机中的应用

作者 : Dimitrios Tsiotas , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : The study and measurement of economic resilience is ruled by high level of complexity related to the diverse structure, functionality, spatiality, and dynamics describing economic systems. Towards serving the demand of integration, this paper develops a three dimensional index, capturing engineering, ecological, and evolutionary aspects of economic resilience that are considered separately in the current literature. The proposed index is computed on GDP data of worldwide countries, for the period 1960 2020, concerning 14 crises considered as shocks, and was found well defined in a conceptual context of its components. Its application on real world data allows introducing a novel classification of countries in terms of economic resilience, and reveals geographical patterns and structural determinants of this attribute. Impressively enough, economic resilience appears positively related to major productivity coefficients, gravitationally driven, and depended on agricultural specialization, with high structural heterogeneity in the low class. Also, the analysis fills the literature gap by shaping the worldwide map of economic resilience, revealing geographical duality and centrifugal patterns in its geographical distribution, a relationship between diachronically good performance in economic resilience and geographical distance from the shocks origin, and a continent differentiation expressed by the specialization of America in engineering resilience, Africa and Asia in ecological and evolutionary resilience, and a relative lag of Europe and Oceania. Finally, the analysis provides insights into the effect of the 2008 on the globe and supports a further research hypothesis that political instability is a main determinant of low economic resilience, addressing avenues of further research.

## 

\[10\] Emerging trends in soybean industry

标题 : 大豆产业的新趋势

作者 : Siddhartha Paul Tiwari , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : Soybean is the most globalized, traded and processed crop commodity. USA, Argentina and Brazil continue to be the top three producers and exporters of soybean and soymeal. Indian soyindustry has also made a mark in the national and global arena. While soymeal, soyoil, lecithin and other soy derivatives stand to be driven up by commerce, the soyfoods for human health and nutrition need to be further promoted. The changing habitat of commerce in soyderivatives necessitates a shift in strategy, technological tools and policy environment to make Indian soybean industry continue to thrive in the new industrial era. Terms of trade for soyfarming and soy industry could be further improved. Present trends, volatilities, slowdowns, challenges faced and associated desiderata are accordingly spelt out in the present article.

## 

\[11\] Objectives of platform research

标题 : 平台研究的目标

作者 : Fabian Schueler, Dimitri Petrik , 类别 ：General Economics (econ.GN)

说明 : Comments: ZfbF Sonderheft 75/20 (Schmalenbach Business Review)

Abstract : Business economics research on digital platforms often overlooks existing knowledge from other fields of research leading to conceptual ambiguity and inconsistent findings. To reduce these restrictions and foster the utilization of the extensive body of literature, we apply a mixed methods design to summarize the key findings of scientific platform research. Our bibliometric analysis identifies 14 platform related research fields. Conducting a systematic qualitative content analysis, we identify three primary research objectives related to platform ecosystems (1) general literature defining and unifying research on platforms (2) exploitation of platform and ecosystem strategies (3) improvement of platforms and ecosystems. Finally, we discuss the identified insights from a business economics perspective and present promising future research directions that could enhance business economics and management research on digital platforms and platform ecosystems.

## 

\[12\] Transparency principle for carbon emissions drives sustainable finance

标题 : 碳排放透明度原则推动可持续金融

作者 : Chris Kenyon, Mourad Berrahoui, Andrea Macrina , 类别 ：Risk Management (q-fin.RM)

说明 : Comments: 33 pages, 2 figures, 5 tables

Abstract : Alignment of financial market incentives and carbon emissions disincentives is key to limiting global warming. Regulators and standards bodies have made a start by requiring some carbon related disclosures and proposing others. Here we go further and propose a Carbon Equivalence Principle all financial products shall contain a description of the equivalent carbon flows from greenhouse gases that the products enable, as well as their existing description in terms of cash flows. This description of the carbon flows enabled by the project shall be compatible with existing bank systems that track cashflows so that carbon flows have equal standing to cash flows. We demonstrate that this transparency alone can align incentives by applying it to project finance examples for power generation and by following through the financial analysis. The financial requirements to offset costs of carbon flows enabled in the future radically change project costs, and risk that assets become stranded, thus further increasing costs. This observation holds whichever partner in the project bears the enabled carbon costs. Mitigating these risks requires project re structuring to include negative emissions technologies. We also consider that sequestered carbon needs to remain sequestered permanently, e.g., for at least one hundred years. We introduce mixed financial physical solutions to minimise this permanence cost, and price to them. This complements previous insurance based proposals with lesser scope. For financial viability we introduce project designs that are financially net zero, and as a consequence are carbon negative. Thus we see that adoption of the Carbon Equivalence Principle for financial products aligns incentives, requires product redesign, and is simply good financial management driving sustainability.

## 

\[13\] Solving Multi Period Financial Planning Models

标题 : 求解多期财务规划模型

作者 : Afşar Onat Aydınhan, Xiaoyue Li, John M. Mulvey , 类别 ：Computational Finance (q-fin.CP)

说明 : -

Abstract : This paper introduces the MCTS algorithm to the financial word and focuses on solving significant multi period financial planning models by combining a Monte Carlo Tree Search algorithm with a deep neural network. The MCTS provides an advanced start for the neural network so that the combined method outperforms either approach alone, yielding competitive results. Several innovations improve the computations, including a variant of the upper confidence bound applied to trees (UTC) and a special lookup search. We compare the two step algorithm with employing dynamic programs neural networks. Both approaches solve regime switching models with 50 time steps and transaction costs with twelve asset categories. Heretofore, these problems have been outside the range of solvable optimization models via traditional algorithms.

## 

\[14\] A Short Survey on Business Models of Decentralized Finance (DeFi) Protocols

标题 : 关于分散金融（DeFi）协议商业模式的简短调查

作者 : Teng Andrea Xu, Jiahua Xu , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : Decentralized Finance (DeFi) services are moving traditional financial operations to the Internet of Value (IOV) by exploiting smart contracts, distributed ledgers, and clever heterogeneous transactions among different protocols. The exponential increase of the Total Value Locked (TVL) in DeFi foreshadows a bright future for automated money transfers in a plethora of services. In this short survey paper, we describe the business model for different DeFi domains namely, Protocols for Loanable Funds (PLFs), Decentralized Exchanges (DEXs), and Yield Aggregators. We claim that the current state of the literature is still unclear how to value thousands of different competitors (tokens) in DeFi. With this work, we abstract the general business model for different DeFi domains and compare them. Finally, we provide open research challenges that will involve heterogeneous domains such as economics, finance, and computer science.

## 

\[15\] An SMP Based Algorithm for Solving the Constrained Utility Maximization Problem via Deep Learning

标题 : 基于SMP的深度学习约束效用最大化算法

作者 : Kristof Wiedermann , 类别 ：Computational Finance (q-fin.CP)

说明 : -

Abstract : We consider the utility maximization problem under convex constraints with regard to theoretical results which allow the formulation of algorithmic solvers which make use of deep learning techniques. In particular for the case of random coefficients, we prove a stochastic maximum principle (SMP), which also holds for utility functions U with mathrm id mathbb R cdot U being not necessarily nonincreasing, like the power utility functions, thereby generalizing the SMP proved by Li and Zheng (2018). We use this SMP together with the strong duality property for defining a new algorithm, which we call deep primal SMP algorithm. Numerical examples illustrate the effectiveness of the proposed algorithm in particular for higher dimensional problems and problems with random coefficients, which are either path dependent or satisfy their own SDEs. Moreover, our numerical experiments for constrained problems show that the novel deep primal SMP algorithm overcomes the deep SMP algorithm s (see Davey and Zheng (2021)) weakness of erroneously producing the value of the corresponding unconstrained problem. Furthermore, in contrast to the deep controlled 2BSDE algorithm from Davey and Zheng (2021), this algorithm is also applicable to problems with path dependent coefficients. As the deep primal SMP algorithm even yields the most accurate results in many of our studied problems, we can highly recommend its usage. Moreover, we propose a learning procedure based on epochs which improved the results of our algorithm even further. Implementing a semi recurrent network architecture for the control process turned out to be also a valuable advancement.

## 

\[16\] Toward an efficient hybrid method for pricing barrier options on assets with stochastic volatility

标题 : 随机波动资产上障碍期权定价的有效混合方法

作者 : Alexander Lipton, Artur Sepp , 类别 ：Computational Finance (q-fin.CP)

说明 : Comments: 33 pages, 11 figures

Abstract : We combine the one dimensional Monte Carlo simulation and the semi analytical one dimensional heat potential method to design an efficient technique for pricing barrier options on assets with correlated stochastic volatility. Our approach to barrier options valuation utilizes two loops. First we run the outer loop by generating volatility paths via the Monte Carlo method. Second, we condition the price dynamics on a given volatility path and apply the method of heat potentials to solve the conditional problem in closed form in the inner loop. We illustrate the accuracy and efficacy of our semi analytical approach by comparing it with the two dimensional Monte Carlo simulation and a hybrid method, which combines the finite difference technique for the inner loop and the Monte Carlo simulation for the outer loop. We apply our method for computation of state probabilities (Green function), survival probabilities, and values of call options with barriers. Our approach provides better accuracy and is orders of magnitude faster than the existing methods. s a by product of our analysis, we generalize Willard s (1997) conditioning formula for valuation of path independent options to path dependent options and derive a novel expression for the joint probability density for the value of drifted Brownian motion and its running minimum.

## 

\[17\] Agricultural Windfalls and the Seasonality of Political Violence in Africa

标题 : 农业意外之财和非洲政治暴力的季节性

作者 : David Ubilava, Justin V. Hastings, Kadir Atalay , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : We study the seasonality of violence against civilians in the cropland of Africa. We combine monthly international cereal prices with grid cell level cropland area fraction and harvest seasons to investigate the relationship between agricultural income shocks and violent attacks by different violent actors. We find that violence in the cropland is associated with the price increase, and the effect is apparent during the early post harvest season when the value of spoils to be appropriated is highest. Among considered perpetrators, we find political militias as the most likely force behind the seasonal political violence in Africa.

## 

\[18\] Optimal market completion through financial derivatives with applications to volatility risk

标题 : 通过金融衍生品实现市场最优完成，并应用于波动风险

作者 : Matt Davison, Marcos Escobar-Anel, Yichen Zhu , 类别 ：Portfolio Management (q-fin.PM)

说明 : Comments: 16 pages, 5 figures

Abstract : This paper investigates the optimal choices of financial derivatives to complete a financial market in the framework of stochastic volatility (SV) models. We introduce an efficient and accurate simulation based method, applicable to generalized diffusion models, to approximate the optimal derivatives based portfolio strategy. We build upon the double optimization approach (i.e. expected utility maximization and risk exposure minimization) proposed in Escobar Anel et al. (2022) demonstrating that strangle options are the best choices for market completion within equity options. Furthermore, we explore the benefit of using volatility index derivatives and conclude that they could be more convenient substitutes when only long term maturity equity options are available.

## 

\[19\] A note on hospital financing

标题 : 关于医院融资的一点注记

作者 : Raffaele Mosca , 类别 ：Computer Science and Game Theory (cs.GT)

说明 : -

Abstract : This note tries to study how hospital behaviors, with reference to interhospital collaboration or competition, could be affected by hospital financing systems. For that this note simulates two scenarios which start with the following baseline scenario a State, with a set of hospitals, each with all types of wards at a basic level. The evolution of this baseline scenario consists in the evolution of hospitals, that is, in the possibility of hospitals to make some of their wards excel. The State has a budget, for the evolution of this baseline scenario, which can be used by two financing systems either by a local financing , i.e., by splitting the budget among the hospitals so that each hospital is managing its own portion of the budget by pursuing the individual benefit, or by a central financing , i.e., by not splitting the budget among the hospitals so that the State is the sole manager of the budget, by pursuing the benefit of the whole community. The conclusions seem to be that in the local financing system hospitals tend to diversify their excellences, while in the central financing system the State tends to create poles of excellence.