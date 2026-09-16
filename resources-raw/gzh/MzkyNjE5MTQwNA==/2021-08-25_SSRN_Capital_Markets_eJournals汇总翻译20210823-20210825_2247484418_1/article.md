# SSRN Capital Markets eJournals汇总翻译20210823-20210825

Shame1ess 量化前沿速递 2021-08-25 22:39

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484418&idx=1&sn=0ad6f8e00859678018b18bac476c8f56&chksm=c3bed43d5462b2366754562d4ee7a7c4331bea81d789d23b9b9176730fb6d3dda839692ce401#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484418&idx=1&sn=0ad6f8e00859678018b18bac476c8f56&chksm=c3bed43d5462b2366754562d4ee7a7c4331bea81d789d23b9b9176730fb6d3dda839692ce401#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Pricing American Options Under Negative Rates

负利率下的美式期权定价

出处:Journal of Computational Finance, Vol. 25, No. 1

\[2\] Fast Pricing of American Options Under Variance Gamma

方差Gamma下美式期权的快速定价

出处:Journal of Computational Finance, Vol. 25, No. 1

\[3\] The Effects of Transaction Costs and Illiquidity on the Prices of Volatility Derivatives

交易成本和流动性不足对波动性衍生品价格的影响

出处:Journal of Computational Finance, Vol. 25, No. 1

\[4\] Effects of Information Overload on Financial Market Returns: How Much Is Too Much?

信息过载对金融市场收益的影响：多少就是太多？

出处:-

\[5\] Oil Price, Gold Price, Exchange Rate and Stock Market in Iraq Pre-During COVID-19 Outbreak: An ARDL Approach

C2019冠状病毒疾病爆发前的油价、黄金价格、汇率和股票市场：ARDL方法

出处:Asaad, Z. A. (2021). Oil Price, Gold Price, Exchange Rate and Stock Market in Iraq Pre-During COVID19 Outbreak: An ARDL Approach. International Journal of Energy Economics and Policy, 11(5), 562-671.

\[6\] Mutual Fund Loyalty and ESG Stock Resilience during the COVID-19 Stock Market Crash

COVID-19股票市场崩溃中的基金忠诚度与ESG股票弹性

出处:-

\[7\] Envisaging Macroeconomics Antecedent Effect on Stock Market Return in India

设想宏观经济对印度股市回报的先行效应

出处:Sivarethinamohan, R., ASAAD, Z. A., MARANE, B. M. R., & Sujatha, S. (2021). Envisaging Macroeconomics Antecedent Effect on Stock Market Return in India. The Journal of Asian Finance, Economics and Business, 8(8), 311–324. https://doi.org/10.13106/JAFEB.2021.VOL8.NO8.0311

\[8\] Disaster Risk, Politicians, and Firm Capital Exuding: A New Role of Stock Market Participation

灾难风险、政客和企业资本外溢：股市参与的新角色

出处:-

## 

\[1\] Pricing American Options Under Negative Rates

标题:负利率下的美式期权定价

作者:Jherek Healy

出处:Journal of Computational Finance, Vol. 25, No. 1

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3909855

Abstract : This paper defines the criteria under which the early exercise of an American option is never optimal, whether under positive or negative rates, and gives a short analysis of the various shapes of the exercise region under negative interest rates. It then presents a new integral equation, which establishes the option price and the two early-exercise boundaries under negative rates, and shows how to solve this new equation through modifications to the modern and efficient algorithm of Andersen and Lake, from changes in the initial estimate of the two boundaries to the more subtle changes required in their fixed-point method for stability. Finally, the performance and accuracy of the resulting algorithm are assessed against a cutting-edge finite-difference method implementation.

Keywords : American options; negative rates; quantitative finance; pricing; integral.

Abstract :本文定义了美式期权的早期行使永远不是最优的标准，无论是在正利率还是负利率下，并简要分析了负利率下行使区域的各种形状。然后提出了一个新的积分方程，该方程建立了负利率下的期权价格和两个早期行使边界，并说明了如何通过修改Andersen和Lake的现代高效算法来求解这个新方程，从两个边界初始估计值的变化到稳定性定点方法所需的更细微变化。最后，通过一个先进的有限差分法实现，对算法的性能和精度进行了评估。

Keywords :美式期权；负利率；定量金融；定价；完整的

## 

\[2\] Fast Pricing of American Options Under Variance Gamma

标题:方差Gamma下美式期权的快速定价

作者:Weilong Fu,Ali Hirsa

出处:Journal of Computational Finance, Vol. 25, No. 1

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3909853

Abstract : We investigate methods for pricing American options under the variance gamma model. The variance gamma process is a pure jump process that is constructed by replacing the calendar time with the gamma time in a Brownian motion with drift, resulting in a time-changed Brownian motion. In the case of the Black–Merton–Scholes model, there exist fast approximation methods for pricing American options. However, these methods cannot be used for the variance gamma model. We develop a new fast and accurate approximation method – inspired by the quadratic approximation – to get rid of the time steps required in finite-difference and simulation methods, while reducing error by making use of a machine learning technique on precalculated quantities. We compare the performance of our method with those of the existing methods and show that our method is efficient and accurate in the context of practical use.

Keywords : American options; variance gamma; quadratic approximation; machine learning; kernel regression.

Abstract :我们研究了方差伽马模型下美式期权的定价方法。方差gamma过程是一个纯跳跃过程，它是通过在带有漂移的布朗运动中用gamma时间替换日历时间而构造的，从而产生随时间变化的布朗运动。在Black-Merton-Scholes模型中，存在美式期权定价的快速近似方法。但是，这些方法不能用于方差伽马模型。我们开发了一种新的快速准确的近似方法——受二次近似的启发——以消除有限差分法和模拟方法中所需的时间步长，同时通过对预先计算的量使用机器学习技术来减少误差。我们将我们的方法与现有方法的性能进行了比较，结果表明我们的方法在实际应用中是有效和准确的。

Keywords :美式期权；方差伽马；二次近似；机器学习；内核回归。

## 

\[3\] The Effects of Transaction Costs and Illiquidity on the Prices of Volatility Derivatives

标题:交易成本和流动性不足对波动性衍生品价格的影响

作者:Mehzabeen Jumanah Dilloo,Désiré Tangman

出处:Journal of Computational Finance, Vol. 25, No. 1

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3909850

Abstract : The prices of assets differ when considering transaction costs and their illiquidity, thus affecting their returns. As volatility derivatives such as variance swaps, gamma swaps, corridor variance swaps and volatility swaps depend on the expected values of these returns, we develop a high-order algorithm so that differences in the fair values of the volatility derivatives under different transaction costs and illiquidity models can be precisely observed. A high-order finite-difference algorithm is used to solve a framework of partial differential equations. A local mesh refinement strategy is applied at the singularities that appear in the pricing problem of some volatility derivatives so that nonuniform five-point stencil finite differences can be implemented in space. The time-stepping is dealt with by an efficient iterative scheme coupled with a Richardson extrapolation and Carathéodory–Fejér approximations. Consequently, the highly convergent solutions are used to analyze the effect of transaction costs and illiquidity on the fair values of volatility derivatives, and the results demonstrate an increase in these values when different transaction costs and liquidity models are implemented.

Keywords : transaction costs models; illiquidity models; volatility derivatives; local mesh refinement; high-order finite-difference schemes.

Abstract :考虑到交易成本和流动性不足，资产价格会有所不同，从而影响其回报。由于波动性衍生品（如方差掉期、伽马掉期、走廊方差掉期和波动性掉期）取决于这些收益的预期值，我们开发了一种高阶算法，以便能够精确观察不同交易成本和非流动性模型下波动性衍生品公允价值的差异。采用高阶有限差分算法求解偏微分方程。对某些波动率导数定价问题中出现的奇异点采用局部网格细化策略，从而在空间中实现非均匀五点模板有限差分。时间步进采用一种高效的迭代格式，并结合Richardson外推和Carathéodory–Fejér近似。因此，使用高度收敛的解决方案来分析交易成本和非流动性对波动性衍生品公允价值的影响，结果表明，当实施不同的交易成本和流动性模型时，这些价值会增加。

Keywords :交易成本模型；非流动性模型；波动性衍生品；局部网格细化；高阶有限差分格式。

## 

\[4\] Effects of Information Overload on Financial Market Returns: How Much Is Too Much?

标题:信息过载对金融市场收益的影响：多少就是太多？

作者:Alejandro Bernales,Marcela Valenzuela,Ilknur Zer

出处:-

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3904916

Abstract : We exploit textual analysis tools and study the effects of information overload—an excess level of information faced by decision-makers—on future stock market returns using daily data from the New York Times over eight decades. Information overload increases information and estimation risk, reduces the decision accuracy amid investors’ limited attention and in- formation processing capabilities. Controlling for well-known predictors of returns, we find that excessive information leads higher future excess returns and lower trading volume. The predictive power of information overload over returns is persistent and reverses in about two years. Finally, information overload affects the cross-section of stock returns via a demand shock or limits to arbitrage. Investors require higher risk premia to hold small, high beta, high volatile, and unprofitable stocks.

Keywords : Sentiment, dispersion, limited attention, predicting returns

Abstract :我们利用文本分析工具，利用《纽约时报》80多年来的每日数据，研究信息过载（决策者面临的过量信息水平）对未来股市回报的影响。在投资者注意力和信息处理能力有限的情况下，信息过载会增加信息和估计风险，降低决策准确性。控制已知的收益预测因素，我们发现过度信息会导致更高的未来超额收益和更低的交易量。信息过载对回报的预测能力是持久的，大约两年后就会逆转。最后，信息过载通过需求冲击或套利限制影响股票回报的横截面。投资者需要更高的风险溢价来持有小型、高贝塔系数、高波动性和无利可图的股票。

Keywords :情绪、分散、有限关注、预测回报

## 

\[5\] Oil Price, Gold Price, Exchange Rate and Stock Market in Iraq Pre-During COVID-19 Outbreak: An ARDL Approach

标题:C2019冠状病毒疾病爆发前的油价、黄金价格、汇率和股票市场：ARDL方法

作者:Zeravan Asaad

出处:Asaad, Z. A. (2021). Oil Price, Gold Price, Exchange Rate and Stock Market in IraqPre-During COVID19 Outbreak: An ARDL Approach. International Journal of Energy Economics and Policy, 11(5), 562-671.

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3909143

Abstract : This study used the econometrics methods to identify the interactions among oil price, gold price, exchange rate, and stock price which represented by the (ISX60) index under the Iraq stock exchange pre-during global pandemic of COVID-19. The analysis employed daily data which categorized into three time periods: full sample pre-during COVID-19 from 24 December 2018 to 3 September 2020, the pre-COVID-19 period from 31 December 2018 to 30 December 2019, as well as during-COVID-19 from 27 December 2019 to 3 September 2020 in order to measure the interactions between the variables for each period. To accomplish that the study used the correlation matrix, unit root test to assure the stationary for the ARDL model and the granger causality test. The correlation output showed different results between the variables based on the period division. Furthermore, the study results accepted the null hypothesis of no cointegration exists between the variables respectively for the (Full sample Pre-during and pre-COVID-19) period, and no decision could be made about the long-run relationship amongst the variables for the (during-COVID-19) period, while the results of the causal short-run model showed that effect of oil price, gold price and exchange rate insignificant with Iraq stock exchange.

Keywords : COVID-19 Outbreak, Oil Price, Gold Price, Exchange Rate, Stock Market

Abstract :本研究采用计量经济学方法，确定石油价格、黄金价格、汇率、，在2019冠状病毒疾病2019冠状病毒疾病流行期间，在伊拉克证券交易所（ISO 60）指数中，股票价格是由全球指数（CVID-19）的全球数据所组成的，该数据分为三个时间段：2018年12月24日至2020年9月3日COVID-19期间的全样本前期，2018年12月31日至2019年12月30日的前COVID-19期；以及2019年12月27日至2020年9月3日期间的-COVID-19，以测量每个时期变量之间的相互作用。为了实现这一点，本研究使用了相关矩阵、单位根检验来确保ARDL模型和格兰杰因果关系检验的平稳性。根据周期划分，相关输出显示变量之间的结果不同。此外，研究结果接受了零假设，即在（全样本Pre-during和Pre-COVID-19）期间变量之间不存在协整关系，并且无法决定（COVID-19）期间变量之间的长期关系，而因果短期模型的结果表明，石油价格、黄金价格和汇率对伊拉克证券交易所的影响不显著。

Keywords :2019冠状病毒疾病爆发，油价，黄金价格，汇率，股市

## 

\[6\] Mutual Fund Loyalty and ESG Stock Resilience during the COVID-19 Stock Market Crash

标题:COVID-19股票市场崩溃中的基金忠诚度与ESG股票弹性

作者:Rui A. Albuquerque,Yrjo Koskinen,Raffaele Santioni

出处:-

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3908464

Abstract : This paper studies the trading behavior of U.S. actively-managed equity mutual funds during the COVID-19 market crash. We show that Environmental, Social, and Governance (ESG) funds helped to stabilize the market by contributing to the resiliency of ESG stocks, but interestingly non-ESG funds also provided support for ESG stocks. First, ESG funds reduced net sales during the crash, controlling for fund flows. Second, all funds experiencing inflows helped to stabilize the market during the crash by increasing net purchases, but the behaviour was more pronounced for ESG funds. Third, funds experiencing outflows also played a key role contributing to the relative stability of ESG stocks as both ESG and non-ESG funds sold more aggressively their non-ESG stocks. We are able to uncover these results because we use monthly holdings data from Morningstar, instead of the commonly used quarterly data.

Keywords : Environmental and social responsibility, institutional investors, fund flows, trading horizon, COVID-19, stock market crash, investor loyalty

Abstract :本文研究了2019冠状病毒疾病爆发期间美国积极管理的股票型共同基金的交易行为。我们发现，环境、社会和治理（ESG）基金通过促进ESG股票的弹性，帮助稳定了市场，但有趣的是，非ESG基金也为ESG股票提供了支持。首先，ESG基金在崩溃期间减少了净销售额，控制了资金流。其次，所有经历资金流入的基金都通过增加净购买量帮助稳定了崩盘期间的市场，但ESG基金的行为更为明显。第三，由于ESG和非ESG基金更积极地出售其非ESG股票，资金外流也对ESG股票的相对稳定性起到了关键作用。我们之所以能够揭示这些结果，是因为我们使用的是晨星的月度持股数据，而不是常用的季度数据。

Keywords :环境与社会责任2019冠状病毒疾病投资者的投资行为

## 

\[7\] Envisaging Macroeconomics Antecedent Effect on Stock Market Return in India

标题:设想宏观经济对印度股市回报的先行效应

作者:Bayar Marane,sivarethinamohan r,Zeravan Asaad

出处:Sivarethinamohan, R., ASAAD, Z. A., MARANE, B. M. R., & Sujatha, S. (2021). Envisaging Macroeconomics Antecedent Effect on Stock Market Return in India. The Journal of Asian Finance, Economics and Business, 8(8), 311–324. https://doi.org/10.13106/JAFEB.2021.VOL8.NO8.0311

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3909161

Abstract : Investors have increasingly become interested in macroeconomic antecedents in order to better understand the investment environment and estimate the scope of profitable investment in equity markets. This study endeavors to examine the interdependency between the macroeconomic antecedents (international oil price (COP), Domestic gold price (GP), Rupee-dollar exchange rates (ER), Real interest rates (RIR), consumer price indices (CPI)), and the BSE Sensex and Nifty 50 index return. The data is converted into a natural logarithm for keeping it normal as well as for reducing the problem of heteroscedasticity. Monthly time series data from January 1992 to July 2019 is extracted from the Reserve Bank of India database with the application of financial Econometrics. Breusch-Godfrey serial correlation LM test for removal of autocorrelation, Breusch-Pagan-Godfrey test for removal of heteroscedasticity, Cointegration test and VECM test for testing cointegration between macroeconomic factors and market returns,\] are employed to fit regression model. The Indian market returns are stable and positive but show intense volatility. When the series is stationary after the first difference, heteroskedasticity and serial correlation are not present. Different forecast accuracy measures point out macroeconomics can forecast future market returns of the Indian stock market. The step-by-step econometric tests show the long-run affiliation among macroeconomic antecedents.

Keywords : Forecast Accuracy; Error Correction; Autocorrelation; Stationarity; Long Term Equilibrium; Indian Stock Market

Abstract :为了更好地了解投资环境和估计股票市场有利可图的投资范围，投资者对宏观经济的前因越来越感兴趣。本研究试图检验宏观经济先行因素（国际石油价格（COP）、国内黄金价格（GP）、卢比-美元汇率（ER）、实际利率（RIR）、消费者价格指数（CPI））与BSE Sensex和Nifty 50指数回报之间的相互依赖性。将数据转换为自然对数，以保持其正常，并减少异方差问题。1992年1月至2019年7月的月度时间序列数据从印度储备银行数据库中提取，并应用金融计量经济学。回归模型采用Breusch-Godfrey序列相关LM检验去除自相关，Breusch-Pagan-Godfrey检验去除异方差，协整检验和VECM检验检验宏观经济因素与市场收益之间的协整关系。印度市场回报率稳定且为正，但波动剧烈。当序列在第一次差分后保持平稳时，不存在异方差性和序列相关性。不同的预测精度指标指出，宏观经济学可以预测印度股市的未来市场收益。逐步的计量经济学检验显示了宏观经济前因之间的长期联系。

Keywords :预测精度；误差修正；自相关；平稳性；长期均衡；印度股市

## 

\[8\] Disaster Risk, Politicians, and Firm Capital Exuding: A New Role of Stock Market Participation

标题:灾难风险、政客和企业资本外溢：股市参与的新角色

作者:Art Durnev,Jiawei (Brooke) Wang

出处:-

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3908762

Abstract : We propose a new function of stock market – to align voters’ preferences to politicians’ policies. We build a model with politicians’ ability to abate negative disaster shocks. Pro-business politicians are more likely to get re-elected when voters hold firm equity, and because of less severe disaster shocks, firms exude less capital and allocate investment more efficiently. We construct a novel stock market participation data for U.S. states using IRS statistics. We find that companies in states with higher stock market participation invest more efficiently and elect pro-business politicians. We use a novel neighboring states methodology and financial literacy instrument to eliminate endogeneity concerns.

Keywords : disaster risk, politics, firm investment

Abstract :我们提出了股票市场的一个新功能——使选民的偏好与政治家的政策相一致。我们建立了一个政治家有能力减轻负面灾难冲击的模型。当选民持有公司股权时，支持商业的政客更有可能再次当选，而且由于灾难冲击不那么严重，公司的资本流出更少，投资配置更有效。我们使用IRS统计数据为美国各州构建了一个新的股票市场参与数据。我们发现，在股票市场参与度较高的州，公司的投资效率更高，并选举支持商业的政客。我们使用一种新的邻国方法和金融知识工具来消除内生性问题。

Keywords :灾难风险、政治、企业投资