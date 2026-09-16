# arxiv量化文献汇总翻译 20220120-20220123

Shame1ess 量化前沿速递 2022-01-23 23:25

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484835&idx=2&sn=e6ac23f643a7bb07417136862d9e92b6&chksm=c37fbca35c0b9bf63ba7f99780e76a6ad277a5ab61506dadce42495399b618464252213ce7b8#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484835&idx=2&sn=e6ac23f643a7bb07417136862d9e92b6&chksm=c37fbca35c0b9bf63ba7f99780e76a6ad277a5ab61506dadce42495399b618464252213ce7b8#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

## 

文献汇总

\[1\] Deep self consistent learning of local volatility

局部波动的深度自洽学习

\[2\] Long Short Term Memory Neural Network for Financial Time Series

金融时间序列的长短记忆神经网络

\[3\] Applicability of Large Corporate Credit Models to Small Business Risk Assessment

大公司信用模型在小企业风险评估中的适用性

\[4\] Effect Structure and Thermodynamics Formulation of Demand side Economics

需求侧经济学的效应结构与热力学公式

\[5\] Lead lag detection and network clustering for multivariate time series with an application to the US equity market

多元时间序列的超前-滞后检测和网络聚类及其在美国股市的应用

\[6\] Opinion Dynamics in Financial Markets via Random Networks

基于随机网络的金融市场意见动态

\[7\] Forecasting the distribution of long horizon returns with time varying volatility

具有时变波动率的长期收益分布预测

\[8\] COVID 19 impact on the international trade

新冠病毒19对国际贸易的影响

\[9\] Do not rug on me

不要欺负我

\[10\] Consistency of MLE for partially observed diffusions, with application in market microstructure modeling

部分观测扩散的最大似然估计的一致性及其在市场微观结构建模中的应用

\[11\] Equilibria of Time inconsistent Stopping for One dimensional Diffusion Processes

一维扩散过程的时间不一致停止平衡

## 

\[1\] Deep self consistent learning of local volatility

标题 : 局部波动的深度自洽学习

作者 : Zhe Wang, Nicolas Privault, Claude Guet , 类别 ：Computational Finance (q-fin.CP)

说明 : Comments: 22 pages, 9 figures

Abstract : We present an algorithm for the calibration of local volatility from market option prices through deep self consistent learning, by approximating market option prices and local volatility using deep neural networks. Our method uses the initial boundary value problem of the underlying Dupire s partial differential equation solved by the parameterized option prices to bring corrections to the parameterization in a self consistent way. By exploiting the differentiability of the neural networks, we can evaluate Dupire s equation locally at each maturity strike pair while by exploiting their continuity, we sample maturity strike pairs uniformly from a given domain, going beyond the discrete points where the options are quoted. For comparison with existing approaches, the proposed method is tested on both synthetic and market option prices, which shows an improved performance in terms of repricing error, no violation of the no arbitrage constraints, and smoothness of the calibrated local volatility.

## 

\[2\] Long Short Term Memory Neural Network for Financial Time Series

标题 : 金融时间序列的长短记忆神经网络

作者 : Carmina Fjellström , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : Performance forecasting is an age old problem in economics and finance. Recently, developments in machine learning and neural networks have given rise to non linear time series models that provide modern and promising alternatives to traditional methods of analysis. In this paper, we present an ensemble of independent and parallel long short term memory (LSTM) neural networks for the prediction of stock price movement. LSTMs have been shown to be especially suited for time series data due to their ability to incorporate past information, while neural network ensembles have been found to reduce variability in results and improve generalization. A binary classification problem based on the median of returns is used, and the ensemble s forecast depends on a threshold value, which is the minimum number of LSTMs required to agree upon the result. The model is applied to the constituents of the smaller, less efficient Stockholm OMX30 instead of other major market indices such as the DJIA and S&P500 commonly found in literature. With a straightforward trading strategy, comparisons with a randomly chosen portfolio and a portfolio containing all the stocks in the index show that the portfolio resulting from the LSTM ensemble provides better average daily returns and higher cumulative returns over time. Moreover, the LSTM portfolio also exhibits less volatility, leading to higher risk return ratios.

## 

\[3\] Applicability of Large Corporate Credit Models to Small Business Risk Assessment

标题 : 大公司信用模型在小企业风险评估中的适用性

作者 : Khalid El-Awady , 类别 ：General Finance (q-fin.GN)

说明 : Comments: 5 pages

Abstract : There is a massive underserved market for small business lending in the US with the Federal Reserve estimating over 650B in unmet annual financing needs. Assessing the credit risk of a small business is key to making good decisions whether to lend and at what terms. Large corporations have a well established credit assessment ecosystem, but small businesses suffer from limited publicly available data and few (if any) credit analysts who cover them closely. We explore the applicability of (DL based) large corporate credit risk models to small business credit rating.

## 

\[4\] Effect Structure and Thermodynamics Formulation of Demand side Economics

标题 : 需求侧经济学的效应结构与热力学公式

作者 : Burin Gumjudpai (NAS Mahidol University) , 类别 ：Physics and Society (physics.soc-ph)

说明 : Comments: 10 pages, 3 figures

Abstract : We propose concept of equation of state (EoS) effect structure in form of diagrams and rules. This concept helps justifying EoS status of an empirical relation. We apply the concept to closed system of consumers and we are able to formulate its EoS. According to the new concept, EoS are classified into three classes. Manifold space of thermodynamics formulation of demand side economics is identified. Formal analogies of thermodynamics and economics consumers system are made. New quantities such as total wealth, generalized utility and generalized consumer surplus are defined. Microeconomics concept of consumer surplus is criticized and replaced with generalized consumer surplus. Smith s law of demand is included in our new paradigm as a specific case resembling isothermal process. Absolute zero temperature state resembles the nirvana state in Buddhism philosophy. Econometric modelling of consumers EoS is proposed at last.

## 

\[5\] Lead lag detection and network clustering for multivariate time series with an application to the US equity market

标题 : 多元时间序列的超前-滞后检测和网络聚类及其在美国股市的应用

作者 : Stefanos Bennett, Mihai Cucuringu, Gesine Reinert , 类别 ：Machine Learning (stat.ML)

说明 : Comments: 29 pages, 28 figures; preliminary version appeared at KDD 2021 - 7th SIGKKDD Workshop on Mining and Learning from Time Series (MiLeTS)

Abstract : In multivariate time series systems, it has been observed that certain groups of variables partially lead the evolution of the system, while other variables follow this evolution with a time delay the result is a lead lag structure amongst the time series variables. In this paper, we propose a method for the detection of lead lag clusters of time series in multivariate systems. We demonstrate that the web of pairwise lead lag relationships between time series can be helpfully construed as a directed network, for which there exist suitable algorithms for the detection of pairs of lead lag clusters with high pairwise imbalance. Within our framework, we consider a number of choices for the pairwise lead lag metric and directed network clustering components. Our framework is validated on both a synthetic generative model for multivariate lead lag time series systems and daily real world US equity prices data. We showcase that our method is able to detect statistically significant lead lag clusters in the US equity market. We study the nature of these clusters in the context of the empirical finance literature on lead lag relations and demonstrate how these can be used for the construction of predictive financial signals.

## 

\[6\] Opinion Dynamics in Financial Markets via Random Networks

标题 : 基于随机网络的金融市场意见动态

作者 : Mateus F. B. Granha, André L. M. Vilela, Chao Wang, Kenric P. Nelson, H. Eugene Stanley , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: 23 pages, 12 figures

Abstract : We investigate the financial market dynamics by introducing a heterogeneous agent based opinion formation model. In this work, we organize the individuals in a financial market by their trading strategy, namely noise traders and fundamentalists. The opinion of a local majority compels the market exchanging behavior of noise traders, whereas the global behavior of the market influences the fundamentalist agents decisions. We introduce a noise parameter q to represent a level of anxiety and perceived uncertainty regarding the market behavior, enabling the possibility for an adrift financial action. We place the individuals as nodes in an Erd os R enyi random graph, where the links represent their social interaction. At a given time, they assume one of two possible opinion states pm 1 regarding buying or selling an asset. The model exhibits such fundamental qualitative and quantitative real world market features as the distribution of logarithmic returns with fat tails, clustered volatility, and long term correlation of returns. We use Student s t distributions to fit the histograms of logarithmic returns, showing the gradual shift from a leptokurtic to a mesokurtic regime, depending on the fraction of fundamentalist agents. We also compare our results with the distribution of logarithmic returns of several real world financial indices.

## 

\[7\] Forecasting the distribution of long horizon returns with time varying volatility

标题 : 具有时变波动率的长期收益分布预测

作者 : Hwai-Chung Ho , 类别 ：Risk Management (q-fin.RM)

说明 : -

Abstract : The study of long horizon returns has received a great deal of attention in recent years (see, for example, Boudoukh, Richardson, and Whitelaw (2008), Neuberger (2012) and Lee (2013), Fama and French (2018)). While most of the discussions are concerned with some practical issues in investment, few have touched the important aspect on risk management. The approach adopted in this article is to predict the future distribution of the returns of a fixed long horizon by which the risk measures of interest that come in the form of a distributional functional such as the value at risk (VaR) and the conditional tail expectation (CTE) can be easily derived. The characteristic feature of our approach which requires no specification of the volatility dynamics nor parametric assumptions of the shock distribution extends the work by Ho et al. (2016) and Ho ( 2017) to a more general volatility dynamics that includes both the widely used SV model and the GARCH model (Bollerslev, 1986) as special cases.

## 

\[8\] COVID 19 impact on the international trade

标题 : 新冠病毒19对国际贸易的影响

作者 : Célestin Coquidé, José Lages, Leonardo Ermann, Dima L. Shepelyansky , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: 22 pages, 2 tables, 13 figures, 2 appendices

Abstract : Using the United Nations Comtrade database, we perform the Google matrix analysis of the multiproduct World Trade Network (WTN) for the years 2018 2020 comprising the emergence of the COVID 19 as a global pandemic. The applied algorithms the PageRank, the CheiRank and the reduced Google matrix take into account the multiplicity of the WTN links providing new insights on the international trade comparing to the usual import export analysis. These algorithms establish new rankings and trade balances of countries and products considering every countries on equal grounds, independently of their wealth, and every products on the basis of their relative exchanged volumes. In comparison with the pre COVID 19 period, significant changes in these metrics occur for the year 2020 highlighting a major rewiring of the international trade flows induced by the COVID 19 pandemic crisis. We define a new PageRank CheiRank product trade balance, either export or import oriented, which is significantly perturbed by the pandemic.

## 

\[9\] Do not rug on me

标题 : 不要欺负我

作者 : Bruno Mazorra, Victor Adan, Vanesa Daza , 类别 ：Cryptography and Security (cs.CR)

说明 : -

Abstract : Uniswap, like other DEXs, has gained much attention this year because it is a non custodial and publicly verifiable exchange that allows users to trade digital assets without trusted third parties. However, its simplicity and lack of regulation also makes it easy to execute initial coin offering scams by listing non valuable tokens. This method of performing scams is known as rug pull, a phenomenon that already existed in traditional finance but has become more relevant in DeFi. Various projects such as 34,37 have contributed to detecting rug pulls in EVM compatible chains. However, the first longitudinal and academic step to detecting and characterizing scam tokens on Uniswap was made in 44 . The authors collected all the transactions related to the Uniswap V2 exchange and proposed a machine learning algorithm to label tokens as scams. However, the algorithm is only valuable for detecting scams accurately after they have been executed. This paper increases their data set by 20K tokens and proposes a new methodology to label tokens as scams. After manually analyzing the data, we devised a theoretical classification of different malicious maneuvers in Uniswap protocol. We propose various machine learning based algorithms with new relevant features related to the token propagation and smart contract heuristics to detect potential rug pulls before they occur. In general, the models proposed achieved similar results. The best model obtained an accuracy of 0.9936, recall of 0.9540, and precision of 0.9838 in distinguishing non malicious tokens from scams prior to the malicious maneuver.

## 

\[10\] Consistency of MLE for partially observed diffusions, with application in market microstructure modeling

标题 : 部分观测扩散的最大似然估计的一致性及其在市场微观结构建模中的应用

作者 : Sergey Nadtochiy, Yuan Yin , 类别 ：Statistics Theory (math.ST)

说明 : -

Abstract : This paper presents a tractable sufficient condition for the consistency of maximum likelihood estimators (MLEs) in partially observed diffusion models, stated in terms of stationary distributions of the associated test processes, under the assumption that the set of unknown parameter values is finite. We illustrate the tractability of this sufficient condition by verifying it in the context of a latent price model of market microstructure. Finally, we describe an algorithm for computing MLEs in partially observed diffusion models and test it on historical data to estimate the parameters of the latent price model.

## 

\[11\] Equilibria of Time inconsistent Stopping for One dimensional Diffusion Processes

标题 : 一维扩散过程的时间不一致停止平衡

作者 : Erhan Bayraktar, Zhenhua Wang, Zhou Zhou , 类别 ：Probability (math.PR)

说明 : -

Abstract : We consider three equilibrium concepts proposed in the literature for time inconsistent stopping problems, including mild equilibria, weak equilibria and strong equilibria. The discount function is assumed to be log sub additive and the underlying process is one dimensional diffusion. We first provide necessary and sufficient conditions for the characterization of weak equilibria. The smooth fit condition is obtained as a by product. Next, based on the characterization of weak equilibria, we show that an optimal mild equilibrium is also weak. Then we provide conditions under which a weak equilibrium is strong. We further show that an optimal mild equilibrium is also strong under a certain condition. Finally, we provide several examples including one shows a weak equilibrium may not be strong, and another one shows a strong equilibrium may not be optimal mild.