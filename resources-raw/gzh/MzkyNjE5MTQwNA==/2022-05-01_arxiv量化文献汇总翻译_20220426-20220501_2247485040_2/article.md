# arxiv量化文献汇总翻译 20220426-20220501

Shame1ess 量化前沿速递 2022-05-01 23:25 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247485040&idx=2&sn=d1f95c1ed404d128e1777fa005e29a64&chksm=c3ffe19d70698382035949a064a5231e1b29c57ebd36aff703cc7ac3fcc0fd0fd4ef4e323560#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247485040&idx=2&sn=d1f95c1ed404d128e1777fa005e29a64&chksm=c3ffe19d70698382035949a064a5231e1b29c57ebd36aff703cc7ac3fcc0fd0fd4ef4e323560#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Adaptive Multi Strategy Market Making Agent For Volatile Markets

针对波动市场的自适应多策略做市商代理

\[2\] Portfolio Diversification Revisited

重新审视投资组合多元化

\[3\] Bunching and Taxing Multidimensional Skills

多维度技能的聚集和征税

\[4\] Supervised machine learning classification for short straddles on the  S&P500

S&P500上短跨骑的监督机器学习分类

\[5\] Individual characteristics associated with risk and time preferences

与风险和时间偏好相关的个体特征

\[6\] Policy Gradient Stock GAN for Realistic Discrete Order Data Generation  in Financial Markets

金融市场中真实离散顺序数据生成的策略梯度

\[7\] Fuzzy Expert System for Stock Portfolio Selection

股票投资组合选择的模糊专家系统

\[8\] Modeling dynamic volatility under uncertain environment with fuzziness  and randomness

具有模糊性和随机性的不确定环境下的动态波动率建模

\[9\] Two dimensional forward and backward transition rates

二维正向和反向跃迁率

\[10\] Forecasting Foreign Exchange Rates With Parameter Free Regression  Networks Tuned By Bayesian Optimization

用贝叶斯优化调整的无参数回归网络预测汇率

\[11\] Causal Analysis of Generic Time Series Data Applied for Market  Prediction

用于市场预测的一般时间序列数据的因果分析

\[12\] Sequence Based Target Coin Prediction for Cryptocurrency Pump and Dump

基于序列的加密货币抽取和转储目标硬币预测

\[13\] NFT Appraisal Prediction

NFT评估预测

\[14\] High Frequency Based Volatility Model with Network Structure

基于高频的网络结构波动率模型

\[15\] The Price and Cost of Bitcoin

比特币的价格和成本

\[16\] The universality in urban commuting across and within cities

城市间和城市内部通勤的普遍性

\[17\] Heterogeneous Information Network based Default Analysis on Banking  Micro and Small Enterprise Users

基于异构信息网络的银行业中小企业用户违约分析

\[18\] Martingale Schr dinger Bridges and Optimal Semistatic Portfolios

鞅薛定谔桥与最优半静态投资组合

\[19\] Limits of Semistatic Trading Strategies

半静态交易策略的局限性

\[20\] Changes in Retirement Savings During the COVID Pandemic

新冠疫情期间退休储蓄的变化

\[21\] An empirical equilibrium model of formal and informal credit markets in  developing countries

发展中国家正式和非正式信贷市场的经验均衡模型

\[22\] Kyle s Model with Stochastic Liquidity

具有随机流动性的Kyle s模型

\[23\] Trade Facilitation and Economic Growth Among Middle Income Countries

中等收入国家之间的贸易便利化和经济增长

\[24\] Debt Financed Collateral and Stability Risks in the DeFi Ecosystem

DeFi生态系统中的债务融资抵押品和稳定风险

\[25\] Quantum Bohmian Inspired Potential to Model Non Gaussian Events and the  Application in Financial Markets

量子波希米亚激发的非高斯事件建模潜力及其在金融市场中的应用

\[26\] CVA in fractional and rough volatility models

分数和粗糙波动率模型中的CVA

\[27\] Will claim history become a deprecated rating factor  An optimal design  method for the real time road risk model

索赔历史会成为不推荐的评级因素吗？实时道路风险模型的优化设计方法

\[28\] Forecasting Electricity Prices

预测电价

\[29\] Converting One Way Streets to Two Way Streets to Improve Transportation  Network Efficiency and Reduce Vehicle Distance Traveled

将单向街道改为双向街道，以提高交通网络效率，减少车辆行驶距离

\[30\] An Efficient Approach for Optimizing the Cost effective Individualized  Treatment Rule Using Conditional Random Forest

一种利用条件随机森林优化个体化治疗规则的有效方法

\[31\] Joint mixability and negative orthant dependence

联合可混性与负正态依赖

\[32\] Safe Delivery of Critical Services in Areas with Volatile Security  Situation via a Stackelberg Game Approach

通过Stackelberg博弈方法在安全局势不稳定的地区安全提供关键服务

### 

\[1\] Adaptive Multi Strategy Market Making Agent For Volatile Markets

标题 : 针对波动市场的自适应多策略做市商代理

作者 : Ali Raheman, Anton Kolonin, Alexey Glushchenko, Arseniy Fokin, Ikram Ansari , 类别 ：Trading and Market Microstructure (q-fin.TR)

说明 : Comments: 10 pages, 1 figure, submitted to conference - Artificial General Intelligence 2022

Abstract : Crypto currency market uncertainty drives the need to find adaptive solutions to maximise gain or at least to avoid loss throughout the periods of trading activity. Given the high dimensionality and complexity of the state action space in this domain, it can be treated as a  Narrow AGI  problem with the scope of goals and environments bound to financial markets. Adaptive Multi Strategy Agent approach for market making introduces a new solution to maximise positive  alpha  in long term handling limit order book (LOB) positions by using multiple sub agents implementing different strategies with a dynamic selection of these agents based on changing market conditions. AMSA provides no specific strategy of its own while being responsible for segmenting the periods of market making activity into smaller execution sub periods, performing internal backtesting on historical data on each of the sub periods, doing sub  agent performance evaluation and re selection of them at the end of each sub  period, and collecting returns and losses incrementally. With this approach, the return becomes a function of hyper parameters such as market data granularity (refresh rate), the execution sub period duration, number of active sub agents, and their individual strategies. Sub agent selection for the next trading sub period is made based on return loss and alpha values obtained during internal backtesting as well as real trading. Experiments with the AMSA have been performed under different market conditions relying on historical data and proved a high probability of positive alpha throughout the periods of trading activity in the case of properly selected hyper parameters.

### 

\[2\] Portfolio Diversification Revisited

标题 : 重新审视投资组合多元化

作者 : Charles Shaw , 类别 ：Portfolio Management (q-fin.PM)

说明 : -

Abstract : We relax a number of assumptions in Alexeev and Tapon (2012) in order to account for non normally distributed, skewed, multi regime, and leptokurtic asset return distributions. We calibrate a Markov modulated Levy process model to equity market data to demonstrate the merits of our approach, and show that the calibrated models do a good job of matching the empirical moments. Finally, we argue that much of the related literature on portfolio diversification relies on assumptions that are in tension with certain observable regularities and which, if ignored, may lead to underestimation of risk.

### 

\[3\] Bunching and Taxing Multidimensional Skills

标题 : 多维度技能的聚集和征税

作者 : Job Boerma, Aleh Tsyvinski, Alexander P. Zimin , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : We characterize optimal policies in a multidimensional nonlinear taxation model with bunching. We develop an empirically relevant model with cognitive and manual skills, firm heterogeneity, and labor market sorting. The analysis of optimal policy is based on two main results. We first derive an optimality condition   a general ABC formula   that states that the entire schedule of benefits of taxes second order stochastically dominates the entire schedule of tax distortions. Second, we use Legendre transforms to represent our problem as a linear program. This linearization allows us to solve the model quantitatively and to precisely characterize the regions and patterns of bunching. At an optimum, 9.8 percent of workers is bunched both locally and nonlocally. We introduce two notions of bunching   blunt bunching and targeted bunching. Blunt bunching constitutes 30 percent of all bunching, occurs at the lowest regions of cognitive and manual skills, and lumps the allocations of these workers resulting in a significant distortion. Targeted bunching constitutes 70 percent of all bunching and recognizes the workers  comparative advantage. The planner separates workers on their dominant skill and bunches them on their weaker skill, thus mitigating distortions along the dominant skill dimension. Tax wedges are particularly high for low skilled workers who are bluntly bunched and are also high along the dimension of comparative disadvantage for somewhat more skilled workers who are targetedly bunched.

### 

\[4\] Supervised machine learning classification for short straddles on the  S&P500

标题 : S&P500上短跨骑的监督机器学习分类

作者 : Alexander Brunhuemer, Lukas Larcher, Philipp Seidl, Sascha Desmettre, Johannes Kofler, Gerhard Larcher , 类别 ：Computational Finance (q-fin.CP)

说明 : Comments: 25 pages

Abstract : In this working paper we present our current progress in the training of machine learning models to execute short option strategies on the S&P500. As a first step, this paper is breaking this problem down to a supervised classification task to decide if a short straddle on the S&P500 should be executed or not on a daily basis. We describe our used framework and present an overview over our evaluation metrics on different classification models. In this preliminary work, using standard machine learning techniques and without hyperparameter search, we find no statistically significant outperformance to a simple  trade always  strategy, but gain additional insights on how we could proceed in further experiments.

### 

\[5\] Individual characteristics associated with risk and time preferences

标题 : 与风险和时间偏好相关的个体特征

作者 : Thomas Meissner, Xavier Gassmann, Corinne Faure, Joachim Schleich , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This paper empirically analyzes how individual characteristics are associated with risk aversion, loss aversion, time discounting, and present bias. To this end, we conduct a large scale demographically representative survey across eight European countries. We elicit preferences using incentivized multiple price lists and jointly estimate preference parameters to account for their structural dependencies. Our findings suggest that preferences are linked to a variety of individual characteristics such as age, gender, and income as well as some personal values. We also report evidence on the relationship between cognitive ability and preferences. Incentivization, stake size, and the order of presentation of binary choices matter, underlining the importance of controlling for these factors when eliciting economic preferences.

### 

\[6\] Policy Gradient Stock GAN for Realistic Discrete Order Data Generation  in Financial Markets

标题 : 金融市场中真实离散顺序数据生成的策略梯度

作者 : Masanori Hirano, Hiroki Sakaji, Kiyoshi Izumi , 类别 ：Machine Learning (cs.LG)

说明 : -

Abstract : This study proposes a new generative adversarial network (GAN) for generating realistic orders in financial markets. In some previous works, GANs for financial markets generated fake orders in continuous spaces because of GAN architectures  learning limitations. However, in reality, the orders are discrete, such as order prices, which has minimum order price unit, or order types. Thus, we change the generation method to place the generated fake orders into discrete spaces in this study. Because this change disabled the ordinary GAN learning algorithm, this study employed a policy gradient, frequently used in reinforcement learning, for the learning algorithm. Through our experiments, we show that our proposed model outperforms previous models in generated order distribution. As an additional benefit of introducing the policy gradient, the entropy of the generated policy can be used to check GAN s learning status. In the future, higher performance GANs, better evaluation methods, or the applications of our GANs can be addressed.

### 

\[7\] Fuzzy Expert System for Stock Portfolio Selection

标题 : 股票投资组合选择的模糊专家系统

作者 : Gour Sundar Mitra Thakur, Rupak Bhattacharyyab, Seema Sarkar (Mondal) , 类别 ：Artificial Intelligence (cs.AI)

说明 : -

Abstract : Selection of proper stocks, before allocating investment ratios, is always a crucial task for the investors. Presence of many influencing factors in stock performance have motivated researchers to adopt various Artificial Intelligence (AI) techniques to make this challenging task easier. In this paper a novel fuzzy expert system model is proposed to evaluate and rank the stocks under Bombay Stock Exchange (BSE). Dempster Shafer (DS) evidence theory is used for the first time to automatically generate the consequents of the fuzzy rule base to reduce the effort in knowledge base development of the expert system. Later a portfolio optimization model is constructed where the objective function is considered as the ratio of the difference of fuzzy portfolio return and the risk free return to the weighted mean semi variance of the assets that has been used. The model is solved by applying Ant Colony Optimization (ACO) algorithm by giving preference to the top ranked stocks. The performance of the model proved to be satisfactory for short term investment period when compared with the recent performance of the stocks.

### 

\[8\] Modeling dynamic volatility under uncertain environment with fuzziness  and randomness

标题 : 具有模糊性和随机性的不确定环境下的动态波动率建模

作者 : Xianfei Hui, Baiqing Sun, Yan Zhou , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : Predicting the dynamic volatility in financial market provides a promising method for risk prediction, asset pricing and market supervision. Barndorff Nielsen and Shephard model (BN S) model, used to capture the stochastic behavior of high frequency time series, is an accepted stochastic volatility model with L   evy process. Although this model is attractive and successful in theory, it needs to be improved in application. We build a new generalized BN S model suitable for uncertain environment with fuzziness and randomness. This new model considers the delay phenomenon between price fluctuation and volatility changes, solves the problem of the lack of long range dependence of classic models. Calculation results show that new model outperforms the classic model in volatility forecasting. Experiments on Dow Jones Industrial Average futures price data are conducted to verify feasibility and practicability of our proposed approach. Numerical examples are provided to illustrate the theoretical result. Three machine learning algorithms are applied to estimate new model parameter. Compared with the classical model, our method effectively combines the uncertain environmental characteristics, which makes the prediction of dynamic volatility more flexible and has ideal performance.

### 

\[9\] Two dimensional forward and backward transition rates

标题 : 二维正向和反向跃迁率

作者 : Theis Bathke, Marcus Christiansen , 类别 ：General Finance (q-fin.GN)

说明 : -

Abstract : Forward transition rates were originally introduced with the aim to evaluate life insurance liabilities market consistently. While this idea turned out to have its limitations, recent literature repurposes forward transition rates as a tool for avoiding Markov assumptions in the calculation of life insurance reserves. While life insurance reserves are some form of conditional first order moments, the calculation of conditional second order moments needs an extension of the forward transition rate concept from one dimension to two dimensions. Two dimensional forward transition rates are also needed for the calculation of path dependent life insurance cash flows as they occur upon contract modifications. Forward transition rates are designed for doing prospective calculations, and by a time symmetric definition of so called backward transition rates one can do retrospective calculations.

### 

\[10\] Forecasting Foreign Exchange Rates With Parameter Free Regression  Networks Tuned By Bayesian Optimization

标题 : 用贝叶斯优化调整的无参数回归网络预测汇率

作者 : Linwei Li, Paul-Amaury Matt, Christian Heumann , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : The article is concerned with the problem of multi step financial time series forecasting of Foreign Exchange (FX) rates. To address this problem, we introduce a parameter free regression network termed RegPred Net. The exchange rate to forecast is treated as a stochastic process. It is assumed to follow a generalization of Brownian motion and the mean reverting process referred to as the generalized Ornstein Uhlenbeck (OU) process, with time dependent coefficients. Using past observed values of the input time series, these coefficients can be regressed online by the cells of the first half of the network (Reg). The regressed coefficients depend only on   but are very sensitive to   a small number of hyperparameters required to be set by a global optimization procedure for which, Bayesian optimization is an adequate heuristic. Thanks to its multi layered architecture, the second half of the regression network (Pred) can project time dependent values for the OU process coefficients and generate realistic trajectories of the time series. Predictions can be easily derived in the form of expected values estimated by averaging values obtained by Monte Carlo simulation. The forecasting accuracy on a 100 days horizon is evaluated for several of the most important FX rates such as EUR USD, EUR CNY, and EUR GBP. Our experimental results show that the RegPred Net significantly outperforms ARMA, ARIMA, LSTMs, and Autoencoder LSTM models in this task.

### 

\[11\] Causal Analysis of Generic Time Series Data Applied for Market  Prediction

标题 : 用于市场预测的一般时间序列数据的因果分析

作者 : Anton Kolonin, Ali Raheman, Mukul Vishwas, Ikram Ansari, Juan Pinzon, Alice Ho , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: 10 pages, 4 figures, submitted to Artificial General Intelligence 2022 conference

Abstract : We explore the applicability of the causal analysis based on temporally shifted (lagged) Pearson correlation applied to diverse time series of different natures in context of the problem of financial market prediction. Theoretical discussion is followed by description of the practical approach for specific environment of time series data with diverse nature and sparsity, as applied for environments of financial markets. The data involves various financial metrics computable from raw market data such as real time trades and snapshots of the limit order book as well as metrics determined upon social media news streams such as sentiment and different cognitive distortions. The approach is backed up with presentation of algorithmic framework for data acquisition and analysis, concluded with experimental results, and summary pointing out at the possibility to discriminate causal connections between different sorts of real field market data with further discussion on present issues and possible directions of the following work.

### 

\[12\] Sequence Based Target Coin Prediction for Cryptocurrency Pump and Dump

标题 : 基于序列的加密货币抽取和转储目标硬币预测

作者 : Sihao Hu, Zhen Zhang, Shengliang Lu, Bingsheng He, Zhao Li , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: 9 pages

Abstract : As the pump and dump schemes (P&Ds) proliferate in the cryptocurrency market, it becomes imperative to detect such fraudulent activities in advance, to inform potentially susceptible investors before they become victims. In this paper, we focus on the target coin prediction task, i.e., to predict the pump probability of all coins listed in the target exchange before a pump. We conduct a comprehensive study of the latest P&Ds, investigate 709 events organized in Telegram channels from Jan. 2019 to Jan. 2022, and unearth some abnormal yet interesting patterns of P&Ds. Empirical analysis demonstrates that pumped coins exhibit intra channel homogeneity and inter channel heterogeneity, which inspires us to develop a novel sequence based neural network named SNN. Specifically, SNN encodes each channel s pump history as a sequence representation via a positional attention mechanism, which filters useful information and alleviates the noise introduced when the sequence length is long. We also identify and address the coin side cold start problem in a practical setting. Extensive experiments show a lift of 1.6  AUC and 41.0  Hit Ratio 3 brought by our method, making it well suited for real world application. As a side contribution, we release the source code of our entire data science pipeline on GitHub, along with the dataset tailored for studying the latest P&Ds.

### 

\[13\] NFT Appraisal Prediction

标题 : NFT评估预测

作者 : Shrey Jain, Camille Bruckmann, Chase McDougall , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : In this paper we investigate the correlation between NFT valuations and various features from three primary categories  public market data, NFT metadata, and social trends data.

### 

\[14\] High Frequency Based Volatility Model with Network Structure

标题 : 基于高频的网络结构波动率模型

作者 : Huiling Yuan, Guodong Li, Junhui Wang , 类别 ：Statistical Finance (q-fin.ST)

说明 : -

Abstract : This paper introduces one new multivariate volatility model that can accommodate an appropriately defined network structure based on low frequency and high frequency data. The model reduces the number of unknown parameters and the computational complexity substantially. The model parameterization and iterative multistep ahead forecasts are discussed and the targeting reparameterization is also presented. Quasi likelihood functions for parameter estimation are proposed and their asymptotic properties are established. A series of simulation experiments are carried out to assess the performance of the estimation in finite samples. An empirical example is demonstrated that the proposed model outperforms the network GARCH model, with the gains being particularly significant at short forecast horizons.

### 

\[15\] The Price and Cost of Bitcoin

标题 : 比特币的价格和成本

作者 : John E. Marthinsen, Steven R. Gordon , 类别 ：General Economics (econ.GN)

说明 : Comments: 18 pages, 3 tables, 5 figures Accepted by the Quarterly Review of Economics and Finance

Abstract : Explaining changes in bitcoin s price and predicting its future have been the foci of many research studies. In contrast, far less attention has been paid to the relationship between bitcoin s mining costs and its price. One popular notion is the cost of bitcoin creation provides a support level below which this cryptocurrency s price should never fall because if it did, mining would become unprofitable and threaten the maintenance of bitcoin s public ledger. Other research has used mining costs to explain or forecast bitcoin s price movements. Competing econometric analyses have debunked this idea, showing that changes in mining costs follow changes in bitcoin s price rather than preceding them, but the reason for this behavior remains unexplained in these analyses. This research aims to employ economic theory to explain why econometric studies have failed to predict bitcoin prices and why mining costs follow movements in bitcoin prices rather than precede them. We do so by explaining the chain of causality connecting a bitcoin s price to its mining costs.

### 

\[16\] The universality in urban commuting across and within cities

标题 : 城市间和城市内部通勤的普遍性

作者 : Lei Dong, Paolo Santi, Yu Liu, Siqi Zheng, Carlo Ratti , 类别 ：Physics and Society (physics.soc-ph)

说明 : -

Abstract : Commuting is a key mechanism that governs the dynamics of cities. Despite its importance, very little is known of the properties and mechanisms underlying this crucial urban process. Here, we capitalize on   sim  50 million individuals  smartphone data from 234 Chinese cities to show that urban commuting obeys remarkable regularities. These regularities can be generalized as two laws  (i) the scale invariance of the average commuting distance across cities, which is a long awaited validation of Marchetti s constant conjecture, and (ii) a universal inverted U shape of the commuting distance as a function of the distance from the city centre within cities, indicating that the city centre s attraction is bounded. Motivated by such empirical findings, we develop a simple urban growth model that connects individual level mobility choices with macroscopic urban spatial structure and faithfully explains both commuting laws. Our results further show that the scale invariants of human mobility will ultimately lead to the polycentric transition in cities, which could be used to better inform urban development strategies.

### 

\[17\] Heterogeneous Information Network based Default Analysis on Banking  Micro and Small Enterprise Users

标题 : 基于异构信息网络的银行业中小企业用户违约分析

作者 : Zheng Zhang, Yingsheng Ji, Jiachen Shen, Xi Zhang, Guangwen Yang , 类别 ：Risk Management (q-fin.RM)

说明 : -

Abstract : Risk assessment is a substantial problem for financial institutions that has been extensively studied both for its methodological richness and its various practical applications. With the expansion of inclusive finance, recent attentions are paid to micro and small sized enterprises (MSEs). Compared with large companies, MSEs present a higher exposure rate to default owing to their insecure financial stability. Conventional efforts learn classifiers from historical data with elaborate feature engineering. However, the main obstacle for MSEs involves severe deficiency in credit related information, which may degrade the performance of prediction. Besides, financial activities have diverse explicit and implicit relations, which have not been fully exploited for risk judgement in commercial banks. In particular, the observations on real data show that various relationships between company users have additional power in financial risk analysis. In this paper, we consider a graph of banking data, and propose a novel HIDAM model for the purpose. Specifically, we attempt to incorporate heterogeneous information network with rich attributes on multi typed nodes and links for modeling the scenario of business banking service. To enhance feature representation of MSEs, we extract interactive information through meta paths and fully exploit path information. Furthermore, we devise a hierarchical attention mechanism respectively to learn the importance of contents inside each meta path and the importance of different metapahs. Experimental results verify that HIDAM outperforms state of the art competitors on real world banking data.

### 

\[18\] Martingale Schr dinger Bridges and Optimal Semistatic Portfolios

标题 : 鞅薛定谔桥与最优半静态投资组合

作者 : Marcel Nutz, Johannes Wiesel, Long Zhao , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : In a two period financial market where a stock is traded dynamically and European options at maturity are traded statically, we study the so called martingale Schr  odinger bridge Q   that is, the minimal entropy martingale measure among all models calibrated to option prices. This minimization is shown to be in duality with an exponential utility maximization over semistatic portfolios. Under a technical condition on the physical measure P, we show that an optimal portfolio exists and provides an explicit solution for Q . This result overcomes the remarkable issue of non closedness of semistatic strategies discovered by Acciaio, Larsson and Schachermayer. Specifically, we exhibit a dense subset of calibrated martingale measures with particular properties to show that the portfolio in question has a well defined and integrable option position.

### 

\[19\] Limits of Semistatic Trading Strategies

标题 : 半静态交易策略的局限性

作者 : Marcel Nutz, Johannes Wiesel, Long Zhao , 类别 ：Mathematical Finance (q-fin.MF)

说明 : -

Abstract : We show that pointwise limits of semistatic trading strategies in discrete time are again semistatic strategies. The analysis is carried out in full generality for a two period model, and under a probabilistic condition for multi period, multi stock models. Our result contrasts with a counterexample of Acciaio, Larsson and Schachermayer, and shows that their observation is due to a failure of integrability rather than instability of the semistatic form. Mathematically, our results relate to the decomposability of functions as studied in the context of Schr  odinger bridges.

### 

\[20\] Changes in Retirement Savings During the COVID Pandemic

标题 : 新冠疫情期间退休储蓄的变化

作者 : Elena Derby, Lucas Goodman, Kathleen Mackie, Jacob Mortenson , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This paper documents changes in retirement saving patterns at the onset of the COVID 19 pandemic. We construct a large panel of U.S. tax data, including tens of millions of person year observations, and measure retirement savings contributions and withdrawals. We use these data to document several important changes in retirement savings patterns during the pandemic relative to the years preceding the pandemic or the Great Recession. First, unlike during the Great Recession, contributions to retirement savings vehicles did not meaningfully decline. Second, driven by the suspension of required minimum distribution rules, IRA withdrawals substantially declined in 2020 for those older than age 72. Third, potentially driven by job separation induced leakage and suspension of the early withdrawal penalty, employer plan withdrawals increased for those under age 60.

### 

\[21\] An empirical equilibrium model of formal and informal credit markets in  developing countries

标题 : 发展中国家正式和非正式信贷市场的经验均衡模型

作者 : Fan Wang , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : I develop and estimate a dynamic equilibrium model of risky entrepreneurs  borrowing and savings decisions incorporating both formal and local informal credit markets. Households have access to an exogenous formal credit market and to an informal credit market in which the interest rate is endogenously determined by the local demand and supply of credit. I estimate the model via Simulated Maximum Likelihood using Thai village data during an episode of formal credit market expansion. My estimates suggest that a 49 percent reduction in fixed costs increased the proportion of households borrowing formally by 36 percent, and that a doubling of the collateralized borrowing limits lowered informal interest rates by 24 percent. I find that more productive households benefited from the policies that expanded borrowing access, but less productive households lost in terms of welfare due to diminished savings opportunities. Gains are overall smaller than would be predicted by models that do not consider the informal credit market.

### 

\[22\] Kyle s Model with Stochastic Liquidity

标题 : 具有随机流动性的Kyle s模型

作者 : Ibrahim Ekren, Brad Mostowski, Gordan Žitković , 类别 ：Trading and Market Microstructure (q-fin.TR)

说明 : -

Abstract : We construct an equilibrium for the continuous time Kyle s model with stochastic liquidity, a general distribution of the fundamental price, and correlated stock and volatility dynamics. For distributions with positive support, our equilibrium allows us to study the impact of the stochastic volatility of noise trading on the volatility of the asset. In particular, when the fundamental price is log normally distributed, informed trading forces the log return up to maturity to be Gaussian for any choice of noise trading volatility even though the price process itself comes with stochastic volatility. Surprisingly, we find that in equilibrium both Kyle s Lambda and its inverse (the market depth) are submartingales.

### 

\[23\] Trade Facilitation and Economic Growth Among Middle Income Countries

标题 : 中等收入国家之间的贸易便利化和经济增长

作者 : Victor Ushahemba Ijirshar , 类别 ：General Economics (econ.GN)

说明 : -

Abstract : This study examined the relationship between trade facilitation and economic growth among the middle income countries from 2010 to 2020 using 94 countries made up of 48 lower middle income countries and 46 upper middle income countries. The study utilized both difference and system Generalised Method of Moments (GMM) since the cross sections (N) were greater than the periods (T). The study found that container port traffic, quality of trade and transport related infrastructure have a strong influence on imports and exports of goods and national income while trade tariff hurts the growth of the countries. The study also found that most of the trade facilitation indicators indicated a weak positive influence on trade flows and economic growth. Based on these findings, the study recommends that reforms aimed at significantly lowering the costs of trading across borders among middle income countries should be highly prioritized in policy formulations, with a focus on the export side by reducing at the border documentation, time, and real costs of trading across borders while the international organizations should continue to report the set of Trade Facilitation Indicators (TFIs) that identify areas for action and enable the potential impact of reforms to be assessed.

### 

\[24\] Debt Financed Collateral and Stability Risks in the DeFi Ecosystem

标题 : DeFi生态系统中的债务融资抵押品和稳定风险

作者 : Michael Darlin, Leandros Tassiulas , 类别 ：Trading and Market Microstructure (q-fin.TR)

说明 : -

Abstract : The rise of Decentralized Finance ( DeFi ) on the Ethereum blockchain has enabled the creation of lending platforms, which serve as marketplaces to lend and borrow digital currencies. We first categorize the activity of lending platforms within a standard regulatory framework. We then employ a novel grouping and classification algorithm to calculate the percentage of fund flows into DeFi lending platforms that can be attributed to debt created elsewhere in the system ( debt financed collateral ). Based on our results, we conclude that the wide spread use of stablecoins as debt financed collateral increases financial stability risks in the DeFi ecosystem.

### 

\[25\] Quantum Bohmian Inspired Potential to Model Non Gaussian Events and the  Application in Financial Markets

标题 : 量子波希米亚激发的非高斯事件建模潜力及其在金融市场中的应用

作者 : Reza Hosseini, Samin Tajik, Zahra Koohi Lai, Tayeb Jamali, Emmanuel Haven, G. Reza Jafari , 类别 ：Mathematical Finance (q-fin.MF)

说明 : Comments: 7 pages, 2 figures

Abstract : We have implemented quantum modeling mainly based on Bohmian Mechanics to study time series that contain strong coupling between their events. We firstly propose how compared to normal densities, our target time series seem to be associated with a higher number of rare events, and Gaussian statistics tend to underestimate these events  frequency drastically. To this end, we suggest that by imposing Gaussian densities to the natural processes, one will seriously neglect the existence of extreme events in many circumstances. The central question of our study concerns the consideration of the effects of these rare events in the corresponding probability densities and studying their role from the point of view of quantum measurements. To model the non Gaussian behavior of these time series, we utilize the multifractal random walk (MRW) approach and control the non Gaussianity parameter   lambda  accordingly. Using the framework of quantum mechanics, we then examine the role of   lambda  in quantum potentials derived for these time series. Our Bohmian quantum analysis shows that the derived potential takes some negative values in high frequencies (its mean values), then substantially increases, and the value drops again for the rare events. We thus conclude that these events could generate a potential barrier that the system, lingering in a non Gaussian high frequency region, encounters, and their role becomes more prominent when it comes to transversing this barrier. In this study, as an example of the application of quantum potential outside of the micro world, we compute the quantum potentials for the S &P financial market time series to verify the presence of rare events in the non Gaussian densities for this real data and remark the deviation from the Gaussian case.

### 

\[26\] CVA in fractional and rough volatility models

标题 : 分数和粗糙波动率模型中的CVA

作者 : Elisa Alòs, Fabio Antonelli, Alessandro Ramponi, Sergio Scarlatti , 类别 ：Computational Finance (q-fin.CP)

说明 : Comments: 29 pages, 7 figures

Abstract : In this work we present a general representation formula for the price of a vulnerable European option, and the related CVA in stochastic (either rough or not) volatility models for the underlying s price, when admitting correlation with the default event. We specialize it for some volatility models and we provide price approximations, based on the representation formula. We study numerically their accuracy, comparing the results with Monte Carlo simulations, and we run a theoretical study of the error. We also introduce a seminal study of roughness influence on the claim s price.

### 

\[27\] Will claim history become a deprecated rating factor  An optimal design  method for the real time road risk model

标题 : 索赔历史会成为不推荐的评级因素吗？实时道路风险模型的优化设计方法

作者 : Jiamin Yu , 类别 ：Risk Management (q-fin.RM)

说明 : Comments: 8 pages, 7 figures

Abstract : With the popularity of Telematics and Self driving, more and more rating factors, such as mileage, route, driving behavior, etc., are introduced into actuarial models. There are quite a few doubts and disputes on the rationality and accuracy of the selection of rating variables, but it does not involve the widely accepted historical claim records. Recently, Tesla Insurance released a new generation of Safety Score based insurance, irrespective of accident history. Forward looking experts and scholars began to discuss whether claim history will disappear in the future auto insurance rate making system. Therefore, this paper proposes a new risk variable elimination method as well as a real time road risk model design framework and concludes that claim history will be regarded as a  noise  factor and deprecated in the Pay How You Drive model.

### 

\[28\] Forecasting Electricity Prices

标题 : 预测电价

作者 : Katarzyna Maciejowska, Bartosz Uniejewski, Rafał Weron , 类别 ：Statistical Finance (q-fin.ST)

说明 : Comments: Forthcoming in the Oxford Research Encyclopedia of Economics and Finance (this https URL)

Abstract : Forecasting electricity prices is a challenging task and an active area of research since the 1990s and the deregulation of the traditionally monopolistic and government controlled power sectors. Although it aims at predicting both spot and forward prices, the vast majority of research is focused on short term horizons which exhibit dynamics unlike in any other market. The reason is that power system stability calls for a constant balance between production and consumption, while being weather (both demand and supply) and business activity (demand only) dependent. The recent market innovations do not help in this respect. The rapid expansion of intermittent renewable energy sources is not offset by the costly increase of electricity storage capacities and modernization of the grid infrastructure. On the methodological side, this leads to three visible trends in electricity price forecasting research as of 2022. Firstly, there is a slow, but more noticeable with every year, tendency to consider not only point but also probabilistic (interval, density) or even path (also called ensemble) forecasts. Secondly, there is a clear shift from the relatively parsimonious econometric (or statistical) models towards more complex and harder to comprehend, but more versatile and eventually more accurate statistical machine learning approaches. Thirdly, statistical error measures are nowadays regarded as only the first evaluation step. Since they may not necessarily reflect the economic value of reducing prediction errors, more and more often, they are complemented by case studies comparing profits from scheduling or trading strategies based on price forecasts obtained from different models.

### 

\[29\] Converting One Way Streets to Two Way Streets to Improve Transportation  Network Efficiency and Reduce Vehicle Distance Traveled

标题 : 将单向街道改为双向街道，以提高交通网络效率，减少车辆行驶距离

作者 : Geoff Boeing, William Riggs , 类别 ：Physics and Society (physics.soc-ph)

说明 : -

Abstract : Planning scholars have identified economic, safety, and social benefits of converting one way streets to two way. Less is known about how conversions could impact vehicular distances traveled   of growing relevance in an era of fleet automation, electrification, and ride hailing. We simulate such a conversion in San Francisco, California. We find that its current street network s average intra city trip is about 1.7  longer than it would be with all two way streets, corresponding to 27 million kilometers of annual surplus travel. As transportation technologies evolve, planners must consider different facets of network efficiency to align local policy and street design with sustainability and other societal goals.

### 

\[30\] An Efficient Approach for Optimizing the Cost effective Individualized  Treatment Rule Using Conditional Random Forest

标题 : 一种利用条件随机森林优化个体化治疗规则的有效方法

作者 : Yizhe Xu, Tom H. Greene, Adam P. Bress, Brandon K. Bellows, Yue Zhang, Zugui Zhang, Paul Kolm, William S.Weintraub, Andrew S. Moran, Jincheng Shen , 类别 ：Methodology (stat.ME)

说明 : Comments: Submitted to Statistical Methods in Medical Research

Abstract : Evidence from observational studies has become increasingly important for supporting healthcare policy making via cost effectiveness (CE) analyses. Similar as in comparative effectiveness studies, health economic evaluations that consider subject level heterogeneity produce individualized treatment rules (ITRs) that are often more cost effective than one size fits all treatment. Thus, it is of great interest to develop statistical tools for learning such a cost effective ITR (CE ITR) under the causal inference framework that allows proper handling of potential confounding and can be applied to both trials and observational studies. In this paper, we use the concept of net monetary benefit (NMB) to assess the trade off between health benefits and related costs. We estimate CE ITR as a function of patients  characteristics that, when implemented, optimizes the allocation of limited healthcare resources by maximizing health gains while minimizing treatment related costs. We employ the conditional random forest approach and identify the optimal CE ITR using NMB based classification algorithms, where two partitioned estimators are proposed for the subject specific weights to effectively incorporate information from censored individuals. We conduct simulation studies to evaluate the performance of our proposals. We apply our top performing algorithm to the NIH funded Systolic Blood Pressure Intervention Trial (SPRINT) to illustrate the CE gains of assigning customized intensive blood pressure therapy.

### 

\[31\] Joint mixability and negative orthant dependence

标题 : 联合可混性与负正态依赖

作者 : Takaaki Koike, Liyuan Lin, Ruodu Wang , 类别 ：Statistics Theory (math.ST)

说明 : -

Abstract : A joint mix is a random vector with a constant component wise sum. It is known to represent the minimizing dependence structure of some common objectives, and it is usually regarded as a concept of extremal negative dependence. In this paper, we explore the connection between the joint mix structure and one of the most popular notions of negative dependence in statistics, called negative orthant dependence. We show that a joint mix does not always have negative dependence, but some natural classes of joint mixes have. In particular, the Gaussian class is characterized as the only elliptical class which supports negatively dependent joint mixes of arbitrary dimension. For Gaussian margins, we also derive a necessary and sufficient condition for the existence of a negatively dependent joint mix. Finally, we show that, for identical marginal distributions, a negatively dependent Gaussian joint mix solves a multi marginal optimal transport problem under uncertainty on the number of components. Analysis of this problem with heterogeneous marginals reveals a trade off between negative dependence and the joint mix structure.

### 

\[32\] Safe Delivery of Critical Services in Areas with Volatile Security  Situation via a Stackelberg Game Approach

标题 : 通过Stackelberg博弈方法在安全局势不稳定的地区安全提供关键服务

作者 : Tien Mai, Arunesh Sinha , 类别 ：Computer Science and Game Theory (cs.GT)

说明 : -

Abstract : Vaccine delivery in under resourced locations with security risks is not just challenging but also life threatening. The current COVID pandemic and the need to vaccinate have added even more urgency to this issue. Motivated by this problem, we propose a general framework to set up limited temporary (vaccination) centers that balance physical security and desired (vaccine) service coverage with limited resources. We set up the problem as a Stackelberg game between the centers operator (defender) and an adversary, where the set of centers is not fixed a priori but is part of the decision output. This results in a mixed combinatorial and continuous optimization problem. As part of our scalable approximation of this problem, we provide a fundamental contribution by identifying general duality conditions of switching max and min when both discrete and continuous variables are involved. We perform detailed experiments to show that the solution proposed is scalable in practice.