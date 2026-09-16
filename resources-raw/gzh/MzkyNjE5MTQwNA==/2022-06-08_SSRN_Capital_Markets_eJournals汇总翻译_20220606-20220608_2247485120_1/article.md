# SSRN Capital Markets eJournals汇总翻译 20220606-20220608

Shame1ess 量化前沿速递 2022-06-08 23:06 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247485120&idx=1&sn=ba41996ffda5e2d9f0ec2207a86954f1&chksm=c38d87c5b92b450aba39619f7a305fa21553acac730b9aa2e2e77a1b21ed299435c3fc570adb#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247485120&idx=1&sn=ba41996ffda5e2d9f0ec2207a86954f1&chksm=c38d87c5b92b450aba39619f7a305fa21553acac730b9aa2e2e77a1b21ed299435c3fc570adb#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Electronic Rates Markets & Low Latency Interest Rate Swap Calculations

电子利率市场和低延迟利率掉期计算

出处:-

\[2\] M&A Rumors and Market Efficiency

并购谣言与市场效率

出处:-

\[3\] Stock Market Liberalization and R&D Disclosure: Evidence from China

股票市场自由化与研发信息披露：来自中国的证据

出处:-

\[4\] Benchmarking Equity Premium Forecasts: Using the Full History Makes the Benchmark More Stringent

基准股票溢价预测：使用完整历史记录使基准更加严格

出处:-

\[5\] Presentation Slides for 'What Is the Underlying Coherent Behavior in Market Dynamic Equilibrium?'

“市场动态均衡中的潜在连贯行为是什么？”演示幻灯片

出处:-

\[6\] Unemployment Beta and the Cross-Section of Stock Returns: Evidence From Australia

失业贝塔和股票收益率的横截面：来自澳大利亚的证据

出处:-

\[7\] Twitter-Based Chinese Economic Policy Uncertainty

基于推特的中国经济政策不确定性

出处:-

\[8\] Coreversal: The Booms and Busts of Arbitrage Activities in China

Coreversal：中国套利活动的兴衰

出处:-

\[9\] A Probabilistic Solution to High-Dimensional Continuous-Time Macro-Finance Models

高维连续时间宏观金融模型的概率解

出处:-

\[10\] Money Markets and Bank Lending: Evidence from the Tiering Adoption

货币市场和银行贷款：分层采用的证据

出处:Swedish House of Finance Research Paper, Forthcoming

\[11\] Analytical Closed-form Parameterizations for Bounded Rationality of either of Overconfidence or Underconfidence

过度自信和欠自信的有限理性的解析闭式参数化

出处:-

\[12\] Google Searches and the Performance of Cryptocurrencies during the COVID-19 Pandemic under a Sentiment Analysis View

情绪分析视角下的谷歌搜索和2019冠状病毒疾病大流行期间加密货币的表现

出处:-

\[13\] What Happens after Stock Price Crashes?

股价暴跌后会发生什么？

出处:-

### 

\[1\] Electronic Rates Markets & Low Latency Interest Rate Swap Calculations

标题:电子利率市场和低延迟利率掉期计算

作者:Nicholas Burgess

出处:-

Abstract : In electronic rates markets accuracy and low latency are threshold requirements that can be a barrier to market entry as they are essential to survive and compete. In this paper we outline how to achieve high performance by reducing swap pricing and risk calculations into trivial vector and matrix multiplication operations. This low latency approach has been successfully applied to Quant analytics in a live trading environment to create core trading competencies that can respond dynamically to market opportunities and challenges, as outlined in (Burgess, 2020) and (Burgess, 2022c).We proceed as follows, firstly we discuss how to quote, price and book swaps for live execution purposes. Secondly, it is essential to understand the swap booking, schedule generation and pricing processes in detail in order to optimize swap calculations for low latency pricing, curve construction and risk. It follows that the majority of the calculation process can be reduced to static data that can be stored and reused rather than wastefully recomputed every calculation cycle. Thirdly, we discuss how to reduce calculations into their reduced primitive optimal state. We provide an Excel workbook to demonstrate the key concepts, see https://bit.ly/LowLatencySwaps. Fourthly, we touch upon advanced concepts including curve Jacobian and algorithmic adjoint differentiation (AAD). Finally to complete the picture we note that once calculations are in their primitive state we can further accelerate performance using parallelization, hardware and other technology solutions.

Keywords : Electronic Markets, Swap Execution Facility, SEF, Request-for-Quote, RFQ, Bloomberg, Interest Rate Swaps, IRS, Swap Schedules, High Speed, Low Latency, Dynamic Data, Static Data, Curve Jacobian, Algorithmic Adjoint Differentiation, Speed, Performance Acceleration.

### 

\[2\] M&A Rumors and Market Efficiency

标题:并购谣言与市场效率

作者:Jan-Oliver Strych

出处:-

Abstract : I apply a novel approach to identify true rumors by using a United Kingdom regulation called “City Code on Takeovers and Mergers”. This very strict and fully enforced regulation forces firms which are mentioned in a takeover rumor to make a public statement on the truthfulness of the rumor irrespective if they are named targets or acquirers. I document positive abnormal returns of rumored target stocks over the two days preceding a true rumor’s publication in serious financial media such as the Financial Times. This finding indicates that the market is efficient in assessing the truthfulness of M&A rumors. I also show that my results cannot be replicated by using the approach of existing literature encouraging the choice of my novel approach for detecting truthfulness of M&A rumors.

Keywords : mergers and acquisitions, m&a rumors; UK takeover code

### 

\[3\] Stock Market Liberalization and R&D Disclosure: Evidence from China

标题:股票市场自由化与研发信息披露：来自中国的证据

作者:Zhi Jin,Tingting Duan,Bingxuan Lin,Ke Xu

出处:-

Abstract : Using Shanghai-Hong Kong Stock Connect program as a quasi-natural experiment, we examine whether and how stock market liberalization affects companies’ R&D disclosure in China. Contrary to the positive impact of market liberalization on overall firm disclosure, we find that market liberalization reduces companies’ R&D disclosure. This effect is more prominent for companies with higher proprietary costs. We argue that firms adjust their R&D disclosure to protect their proprietary information. We also find that managers disclose R&D information strategically by reducing the quantity of R&D disclosure and increasing the level of optimism in disclosure.

Keywords : Market liberalization, Proprietary costs, R&D disclosure, Strategic reporting

### 

\[4\] Benchmarking Equity Premium Forecasts: Using the Full History Makes the Benchmark More Stringent

标题:基准股票溢价预测：使用完整历史记录使基准更加严格

作者:Gunter Löffler

出处:-

Abstract : Equity premium forecasts are usually benchmarked against a historical mean computed from the start of the sample used in a paper. I show that this benchmark tends to be less stringent than a mean computed over the entire available return history. A replication analysis of a widely cited paper (Rapach, Strauss, and Zhou, 2010) illustrates that reported performance advantages can turn negative or lose their statistical significance when the full-history benchmark is used.

Keywords : equity premium; predictability; benchmark; out-of-sample

### 

\[5\] Presentation Slides for 'What Is the Underlying Coherent Behavior in Market Dynamic Equilibrium?'

标题:“市场动态均衡中的潜在连贯行为是什么？”演示幻灯片

作者:Leilei Shi,Xinshuai Guo,Andrea Fenu,Bing-Hong Wang

出处:-

Abstract : This is the revised presentation slides for the paper entitled “what is the underlying coherent behavior in market dynamic equilibrium?” after we have got feedbacks from anonymous referees, discussants, session chairs, and participants at 2022 Economics of Financial Technology Conference (Edinburgh Business School, United Kingdom) and 2022 China FinTech Research Conference (Tianjin, China). It helps readers, especially for PhD students and junior scholars in economics and finance, understand what problem we address in the paper, why this issue is important in economics and finance, and how we study it in a new paradigm. The study suggests that better behavioral economic and financial theories realizing both descriptively accurate and normatively adequate goals can be extracted from a price-volume probability wave equation in the future, in which the interaction of participants has to be considered in reality, although there is much doubting about the two goals for a decision theory.

Keywords : PhD students, junior scholars, new paradigm, presentation slides

### 

\[6\] Unemployment Beta and the Cross-Section of Stock Returns: Evidence From Australia

标题:失业贝塔和股票收益率的横截面：来自澳大利亚的证据

作者:Nhan  Huynh

出处:-

Abstract : This study provides evidence of the significant impacts of unemployment indicators, including the projected unemployment rate and actual unemployment gap, on the cross-sectional stock returns in the Australian market. Utilising the extensive dataset of all listed stocks and unemployment data from 1992 to 2020, we construct an unemployment beta to measure the monthly-varying sensitivity of returns to the actual and forecasted unemployment levels. The findings confirm that stocks in the lowest unemployment beta decile can generate higher excess and risk-adjusted returns compared to the higher unemployment beta decile. The predictive powers of unemployment remain significant within the horizon of 36 months. Further, the unemployment premiums are positively correlated with economic, financial, and political uncertainties. After considering a battery of sensitivity analyses accounting for alternative approaches, risk, and macroeconomics indicators, our results remain robust.

Keywords : unemployment, unemployment beta, cross-sectional returns, Australia evidence

### 

\[7\] Twitter-Based Chinese Economic Policy Uncertainty

标题:基于推特的中国经济政策不确定性

作者:Kiryoung Lee,Eunseon Choi,Minki Kim

出处:-

Abstract : Given the strict censorship in China, would tweets about Chinese economic policy uncertainty by global Twitter users contain valuable information above and beyond existing indices? We construct novel daily and monthly frequency "censorship-free" indices of Twitter-based Chinese economic policy uncertainty from 2010 onward. Our uncertainty index significantly spikes during major economic policy events. Shocks to our index are significantly associated with future Chinese stock market returns as well as investment, consumption, unemployment, and production while existing Chinese economic policy uncertainty indices are not significantly related to economic outputs.

Keywords : Twitter, Economic Policy Uncertainty, China, Chinese uncertainty

### 

\[8\] Coreversal: The Booms and Busts of Arbitrage Activities in China

标题:Coreversal：中国套利活动的兴衰

作者:Xin Liu,Zhigang Qiu,Luyao Shen,Weinan Zheng

出处:-

Abstract : This paper investigates arbitrage activities in China’s stock market to examine whether arbitrageurs destabilize stock prices. We focus on reversal anomaly and construct a measure of arbitrage intensity, coreversal, which captures the abnormal return correlation among stocks on which a reversal strategy would speculate. In times of low reversal arbitrage, the reversal strategy exhibits delayed correction, taking up to three years for abnormal returns to be realized. However, when reversal arbitrage is high, prices overshoot and then revert in the long run, reflecting prior overreaction from crowded reversal trading which pushes prices away from fundamentals.

Keywords : Coreversal; Arbitrage activities; Price overshoot; Market destabilization; Reversal

### 

\[9\] A Probabilistic Solution to High-Dimensional Continuous-Time Macro-Finance Models

标题:高维连续时间宏观金融模型的概率解

作者:Ji Huang

出处:-

Abstract : This paper demonstrates that the equilibrium dynamics of a continuous-time macro-finance model can be characterized by the probabilistic solution of a coupled forward-backward stochastic differential equation. The probabilistic approach can, to some extent, overcome the \`\`curse of dimensionality'' with the help of the parametric approximation of deep neural networks and Machine Learning libraries (e.g., TensorFlow in Python and Flux in Julia). I propose a simple algorithm and assess its performance by considering a multiple-country macro-finance model, which allows for an analytic solution under symmetric states.

Keywords : probabilistic solution, macro-finance, FBSDE, deep learning

### 

\[10\] Money Markets and Bank Lending: Evidence from the Tiering Adoption

标题:货币市场和银行贷款：分层采用的证据

作者:Carlo Altavilla,Miguel Boucinha,Lorenzo Burlon,Mariassunta Giannetti,Julian Schumacher

出处:Swedish House of Finance Research Paper, Forthcoming

Abstract : Exploiting the introduction of the ECB’s tiering system for remunerating excess reserve holdings, we document the importance of the access to the money market for bank lending. We show that the two-tier system produced positive wealth effects for banks with excess reserves and encouraged a reallocation of liquidity toward banks with unused exemptions. This ultimately decreased the fragmentation in the money market and enhanced the transmission of monetary policy. Improved money market access incentivizes banks with unused allowances to extend more credit than other banks, including banks with excess liquidity whose valuations increased the most.

Keywords : money market; bank lending; negative interest rate policy

### 

\[11\] Analytical Closed-form Parameterizations for Bounded Rationality of either of Overconfidence or Underconfidence

标题:过度自信和欠自信的有限理性的解析闭式参数化

作者:Oghenovo A. Obrimah

出处:-

Abstract : This study establishes analytical closed-form mathematical parameterizations for each of overconfidence or underconfidence that boundedly are rational. Given that, feasibly \`boundedly rational overconfident (BRoverconfident)' agents revert, over time, to \`boundedly rational underconfidence (BRunderconfidence)', but not vice versa, there exist specifications of BRoverconfidence that rationalize \`patterns' of stock return momentum and reversals. For concreteness, whereas, emergence of \`boundedly irrational overconfidence', which, necessarily reverts to \`boundedly irrational underconfidence', and vice versa induces {positive,negative;...positive,negative} return sequences; with all agents boundedly rational, feasibly emergence of BRoverconfidence induces {positive,negative,positive;...positive,negative,positive} return sequences in markets. Corroborating the formal theory, but yet with the boundedly irrational pattern parameterized by better goodness-of-it, the same underlying stock portfolio return data supports the two dichotomous - boundedly rational vis-a-vis boundedly irrational - patterns for return momentum and reversals. Boundedly irrational investing swamps, as such boundedly rational investing.

Keywords : Behavior, Bias, Bounded Rationality, Irrationality, Decision Making, Momentum

### 

\[12\] Google Searches and the Performance of Cryptocurrencies during the COVID-19 Pandemic under a Sentiment Analysis View

标题:情绪分析视角下的谷歌搜索和2019冠状病毒疾病大流行期间加密货币的表现

作者:Evangelos Vasileiou,Aristeidis Samitas,Petros Koutrakos

出处:-

Abstract : This paper examines the performance of the large-cap cryptocurrencies, Bitcoin (BTC) and Ethereum (ETH), during the COVID-19 period (1/2/2020-30/12/2021) using sentiment analysis. Using the Google Trends tool, we try to quantify users’ intention to buy and sell BTC and ETH, and their sentiments against COVID fear. The empirical results show strong statistical evidence that COVID fear has a negative impact on BTC/ETH performance. Additionally, our findings indicate that Google searches which imply a buy intention have a positive influence on the performance of these cryptos, but the selling intention searches do not provide any statistically significant information. Moreover, the Granger causality tests show that: (i) COVID-19 fear Granger causes the BTC/ETH returns, (ii) there is a bi-directional Granger causality between the performance of BTC/ETH and the buy intention searches, and (iii) that the performance of the cryptocurrencies causes the sell intention searches.  Further research on sentiment analysis should be conducted using data from several internet sources, e.g. Twitter, and tools such as textual analysis, in order to improve the accuracy of the sentiment indices and the asset pricing models.

Keywords : Behavioral finance, Sentiment Analysis, Internet Searches, Cryptocurrency performance

### 

\[13\] What Happens after Stock Price Crashes?

标题:股价暴跌后会发生什么？

作者:Suvra Roy,Ben R. Marshall,Harvey Nguyen,Nuttawat Visaltanachoti

出处:-

Abstract : Numerous researchers study stock price crashes, but most of this work focuses on the causes of crashes rather than their consequences. We consider the impact of crashes on a broad range of stakeholders, including analysts, investors, management, and employees. Analysts and investors pay more attention to firms that have crashed. Management becomes more focused on regaining the trust of shareholders by investing in social capital and employee welfare, improving transparency, and reducing agency conflicts. These management actions alleviate the likelihood of future crashes among high crash-exposed firms.

Keywords : Crash risk, Investor trust, Information asymmetry, Agency conflict