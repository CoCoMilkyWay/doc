# 量化前沿速递：机器学习\[20260608\]

shameless 量化前沿速递 2026-06-09 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489559&idx=4&sn=053eeef0452e3c499e079a6935d6e2e2&chksm=c3ce3bec5d89072916721c12293db4d8a8ace1f66c4c8edd66182ea8726d4cc454470ce44f46#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489559&idx=4&sn=053eeef0452e3c499e079a6935d6e2e2&chksm=c3ce3bec5d89072916721c12293db4d8a8ace1f66c4c8edd66182ea8726d4cc454470ce44f46#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Inspectable Neural Markov Models for Non Stationary Time Series

非平稳时间序列的可检验神经马尔可夫模型

来源:ARXIV\_20260601

\[2\] Kalimati Vegetable Price Index Forecasting with a Momentum Corrected Online Stacking Ensemble

基于动量校正的在线叠加集成的Kalimati蔬菜价格指数预测

来源:ARXIV\_20260601

\[3\] Machine Learning Based Bitcoin Trading Under Transaction Costs

交易成本下基于机器学习的比特币交易

来源:ARXIV\_20260602

\[4\] Macro aware time series forecasting via hierarchical mixed frequency attention models

基于层次混合频率注意力模型的宏观感知时间序列预测

来源:ARXIV\_20260602

\[5\] Differing Roles of Leisure and Productivity in GDP   A Machine Learning based comparative analysis of Germany and USA

休闲和生产力在GDP中的不同作用——基于机器学习的德国和美国比较分析

来源:ARXIV\_20260602

\[6\] Hybrid News Sentiment Engine

混合新闻情感引擎

来源:ARXIV\_20260603

\[7\] Dynamic Multi Pair Trading Strategy in Cryptocurrency Markets with Deep Reinforcement Learning

基于深度强化学习的加密货币市场动态多对交易策略

来源:ARXIV\_20260604

\[8\] ReSGA

ReSGA

来源:ARXIV\_20260604

\[9\] Worker Utility as Hysteresis

工人效用滞后

来源:ARXIV\_20260604

### 

\[1\] Inspectable Neural Markov Models for Non Stationary Time Series

标题:非平稳时间序列的可检验神经马尔可夫模型

作者:Jan Rovirosa, Jesse Schmolze

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30943

Abstract : Modeling non stationary stochastic systems requires balancing the representational capacity of deep learning with the structural transparency of classical probabilistic models. Markov transition matrices provide such a framework, but traditional frequency based estimation collapses at high resolutions due to data sparsity. We propose a hybrid approach that parameterizes the manifold of stochastic matrices through a neural network, enabling estimation of time inhomogeneous Markov chains in sparse data regimes, and use financial markets as a testbed to investigate the Markov state variable as a critical inductive bias. We show that conditioning on realized volatility produces a more internally consistent Markovian structure than return based states, achieving a  5.6    reduction in Chapman Kolmogorov discrepancy and superior held out likelihood in 9 of 10 assets. Unlike black box sequence models, our approach generates explicit matrices amenable to direct geometric analysis, surfacing structural findings such as the universal homogenization of transition probabilities under high volatility regimes.

Keywords : 

Abstract :对非平稳随机系统进行建模需要平衡深度学习的表征能力与经典概率模型的结构透明度。马尔可夫转移矩阵提供了这样一个框架，但由于数据稀疏，传统的基于频率的估计在高分辨率下会崩溃。我们提出了一种混合方法，通过神经网络对随机矩阵的流形进行参数化，从而能够在稀疏数据状态下估计时间不均匀的马尔可夫链，并使用金融市场作为测试平台来研究马尔可夫状态变量作为临界归纳偏差。我们发现，与基于回报的状态相比，基于已实现波动率的条件化产生了更内部一致的马尔可夫结构，查普曼-科尔莫戈罗夫差异降低了5.6，10种资产中有9种具有更高的坚持可能性。与黑盒序列模型不同，我们的方法生成了易于直接几何分析的显式矩阵，揭示了结构发现，如高波动率下转移概率的普遍均匀化。

Keywords :

### 

\[2\] Kalimati Vegetable Price Index Forecasting with a Momentum Corrected Online Stacking Ensemble

标题:基于动量校正的在线叠加集成的Kalimati蔬菜价格指数预测

作者:Sahaj Raj Malla

来源:ARXIV\_20260601

链接:https://arxiv.org/pdf/2605.30720

Abstract : Forecasting agricultural commodity prices in emerging economies is difficult due to high volatility, frequent supply disruptions, and strong cultural influences on demand. This study introduces the Kalimati Vegetable Price Index (KVPI), a new inverse volatility weighted composite index that aggregates 135 daily wholesale commodities from Kathmandu over ten years (2013 2023). By creating a stable macro level signal, the KVPI reduces the noise inherent in modelling individual crops. A rich set of 64 causally valid features was developed, including festival lead lag effects, rolling statistics, and calendar variables. Fourteen forecasting models spanning statistical, tree based, deep learning, hybrid, and transformer architectures were rigorously evaluated across short (7 day), medium (14  and 30 day), and long term (90 day) horizons. Tree based ensembles proved notably robust, while classical statistical models and complex transformers struggled with the noisy dataset. The proposed Momentum Corrected Online Stacking Ensemble achieved the strongest performance, yielding a Root Mean Square Error (RMSE) of 1.771, an exceptionally low Mean Absolute Percentage Error (MAPE) of 0.68 , and explaining 84.5  of the variance (R squared   0.845) at the 90 day horizon. This open source pipeline provides policymakers and supply chain actors in Nepal and similar markets with a practical, reliable tool for anticipating price movements and strengthening food security.

Keywords : 

Abstract :由于高波动性、频繁的供应中断以及对需求的强烈文化影响，预测新兴经济体的农产品价格很困难。本研究引入了Kalimati蔬菜价格指数（KVPI），这是一个新的逆波动加权综合指数，汇集了加德满都十年（2013-2023）的135种日常批发商品。通过创建稳定的宏观信号，KVPI降低了建模单个作物时固有的噪声。开发了一组丰富的64个因果有效特征，包括节日超前滞后效应、滚动统计和日历变量。在短期（7天）、中期（14天和30天）和长期（90天）范围内，对跨越统计、基于树、深度学习、混合和变压器架构的14个预测模型进行了严格评估。基于树的集成被证明是非常稳健的，而经典的统计模型和复杂的变换器则难以应对噪声数据集。所提出的动量校正在线叠加集成实现了最强的性能，产生了1.771的均方根误差（RMSE），0.68的极低平均绝对百分比误差（MAPE），并解释了90天内84.5的方差（R平方0.845）。这一开源渠道为尼泊尔和类似市场的政策制定者和供应链参与者提供了一种实用、可靠的工具，用于预测价格走势和加强粮食安全。

Keywords :

### 

\[3\] Machine Learning Based Bitcoin Trading Under Transaction Costs

标题:交易成本下基于机器学习的比特币交易

作者:Andrei Bysik, Robert Ślepaczuk

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.00060

Abstract : This paper investigates whether machine learning forecasts of hourly BTC USDT returns can be converted into economically meaningful trading performance after transaction costs. Using approximately 70,000 hourly observations from 2018 2026, XGBoost, LSTM, and iTransformer are evaluated in a 27 fold walk forward protocol. All three models produce positive gross trading performance in selected configurations, but naive sign based strategies fail once transaction costs of ten basis points are imposed. A cost aware execution filter, which prevents trades only when the forecast magnitude exceeds a transaction cost based threshold, sharply reduces turnover and restores profitability in selected configurations. The strongest long only XGBoost strategy produces annualised returns above 65  with a Sharpe ratio above one. Additional tests show that technical indicators improve performance in selected cases, EGARCH derived features do not provide uniformly robust gains, and XGBoost is descriptively stronger than the neural alternatives, although bootstrap evidence does not support formal statistical dominance. Loss function and model selection effects are secondary and statistically fragile. The results show that the main obstacle in hourly cryptocurrency trading is not only weak predictability, but also the way forecasts are converted into trades.

Keywords : 

Abstract :本文研究了机器学习对BTC-USDT每小时回报的预测是否可以在扣除交易成本后转化为具有经济意义的交易绩效。使用2018年至2026年的约70000小时观测数据，XGBoost、LSTM和iTransformer在27倍的前向协议中进行了评估。这三种模型在选定的配置中都产生了积极的总交易绩效，但一旦施加了10个基点的交易成本，基于符号的天真策略就会失败。一个具有成本意识的执行过滤器，仅在预测幅度超过基于交易成本的阈值时才阻止交易，在选定的配置中大幅降低营业额并恢复盈利能力。最强的只做多XGBoost策略产生的年化回报率超过65，夏普比率超过1。其他测试表明，技术指标在特定情况下提高了性能，EGARCH衍生的特征不能提供一致的鲁棒增益，XGBoost在描述性上比神经替代方案更强，尽管引导证据不支持正式的统计优势。损失函数和模型选择效应是次要的，在统计上很脆弱。结果表明，每小时加密货币交易的主要障碍不仅是可预测性弱，还有预测转化为交易的方式。

Keywords :

### 

\[4\] Macro aware time series forecasting via hierarchical mixed frequency attention models

标题:基于层次混合频率注意力模型的宏观感知时间序列预测

作者:Daniel Cunha Oliveira, Kieran Wood, Stefan Zohren, Mihai Cucuringu, André Fujita

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.00624

Abstract : Deep learning models show promise in financial forecasting, yet their generalization is often undermined by small datasets, noisy signals, and non stationarity. While meta learning and related techniques mitigate some of these issues, they typically do not account for a core limitation in macro financial prediction  the scarcity of distinct macroeconomic regimes that drive asset returns. We introduce HANET (Hierarchical Attention Network), a hybrid LSTM based architecture that integrates macroeconomic domain knowledge through attention over long run macro contexts while preserving high frequency market dynamics. HANET organizes information in a hierarchical mixed frequency structure, with daily asset return signals nested within monthly macroeconomic windows, and introduces a Hierarchical Cross Attention mechanism that reconciles low frequency macro signals with high frequency returns without discarding granular daily information. By framing regime selection as attention over macroeconomic contexts, the model adapts to scarce and shifting regimes. Empirically, across 55 liquid futures spanning multiple asset classes, HANET consistently outperforms neural forecasters that ignore macroeconomic information, particularly during turbulent periods, improving risk adjusted returns and mitigating losses. Ablation studies show that these gains rely on structured macro conditioning rather than naive feature augmentation  an LSTM with the same macro representation performs poorly, and shuffling macro contexts substantially degrades performance. Finally, HANET provides interpretability through attention weights, highlighting which historical regimes are most influential for each forecast and linking macro conditions to portfolio outcomes. These results establish HANET as a systematic approach to integrating macroeconomic information into attention based deep learning for financial forecasting.

Keywords : 

Abstract :深度学习模型在金融预测方面显示出希望，但它们的泛化能力往往受到小数据集、噪声信号和非平稳性的影响。虽然元学习和相关技术缓解了其中一些问题，但它们通常不能解释宏观金融预测的核心局限性——驱动资产回报的不同宏观经济制度的稀缺性。我们介绍HANET（分层注意力网络），这是一种基于LSTM的混合架构，通过在长期宏观环境中的注意力整合宏观经济领域知识，同时保持高频市场动态。HANET以分层混合频率结构组织信息，每日资产回报信号嵌套在月度宏观经济窗口内，并引入了分层交叉注意机制，该机制将低频宏观信号与高频回报相协调，而不会丢弃细粒度的每日信息。通过将制度选择视为对宏观经济背景的关注，该模型适应了稀缺和不断变化的制度。根据经验，在跨越多个资产类别的55个流动性期货中，HANET的表现始终优于忽视宏观经济信息的神经预测者，特别是在动荡时期，提高了风险调整后的回报并减轻了损失。消融研究表明，这些增益依赖于结构化的宏调节，而不是朴素的特征增强——具有相同宏表示的LSTM表现不佳，洗牌宏上下文会大大降低性能。最后，HANET通过注意力权重提供了可解释性，突出了哪些历史制度对每种预测最具影响力，并将宏观条件与投资组合结果联系起来。这些结果确立了HANET是一种将宏观经济信息整合到基于注意力的深度学习中进行金融预测的系统方法。

Keywords :

### 

\[5\] Differing Roles of Leisure and Productivity in GDP   A Machine Learning based comparative analysis of Germany and USA

标题:休闲和生产力在GDP中的不同作用——基于机器学习的德国和美国比较分析

作者:Achintya Ranjan, Uma Ranjan

来源:ARXIV\_20260602

链接:https://arxiv.org/pdf/2606.01234

Abstract : The GDP of a country is modelled as the relative interaction between two agents   working hours, reflecting the social choice of a population, and Total Factor Productivity, reflecting the collective investment in productivity enhancers. It is shown that a Random Forest model can accu  rately predict the GDP from these two factors. The differences in the choices made by Germany and USA are analysed though Gini importance, SHAP plots and partial dependency. It is shown that the differences in the social structure of the countries are reflected in the relative contribution of working hours and productivity to the GDP.

Keywords : 

Abstract :一个国家的国内生产总值被建模为两个主体工作时间之间的相对相互作用，反映了人口的社会选择，以及全要素生产率，反映了对生产力增强剂的集体投资。结果表明，随机森林模型可以从这两个因素准确预测GDP。通过基尼系数、SHAP图和部分依赖性分析了德国和美国在选择上的差异。研究表明，各国社会结构的差异反映在工作时间和生产率对GDP的相对贡献上。

Keywords :

### 

\[6\] Hybrid News Sentiment Engine

标题:混合新闻情感引擎

作者:Andreas Aigner

来源:ARXIV\_20260603

链接:https://arxiv.org/pdf/2606.03457

Abstract : We present a hybrid news sentiment engine that continuously learns marketsentiment from paired news headlines and concurrent asset price snapshotswithout requiring any neural network training or GPU compute. The system usesa three way ensemble combining (1) a financial domain lexicon (FinBERT stylekeyword scoring), (2) an adaptive statistical TF IDF cluster learner thatorganizes headlines into semantic neighborhoods and tracks their averagerealized price reactions, and (3) an auto calibrating weighting mechanismthat adjusts ensemble contributions based on each signal s historicalcorrelation with actual price movements. The engine runs on a 3 hour pollingcycle from the Tradeflags NewsFeed API, which provides 22 price snapshotfields per news item spanning equity indices (ES, NQ, SPY, DJIA, NDX, IWM),commodities (CL), and cryptocurrencies (BTC, ETH). All processing occurs atsub second latency on a CPU only server at effectively zero marginal cost peranalytic cycle. We compare our approach against established methods   FinBERT, GPT based scoring, VADER, and commercial sentiment APIs    acrossdimensions of cost, latency, accuracy, and adaptability. Our statisticalcluster learner, which adapts to changing market regimes without retraining,represents a novel contribution not found in existing sentiment systems.

Keywords : 

Abstract :我们提出了一种混合新闻情绪引擎，它可以从成对的新闻标题和并发的资产价格快照中不断学习市场情绪，而不需要任何神经网络训练或GPU计算。该系统使用一种三向集成，结合了（1）金融领域词典（FinBERT风格单词评分），（2）自适应统计TF IDF聚类学习器，将标题组织成语义邻域并跟踪其平均实现的价格反应，以及（3）自动校准加权机制，根据每个信号与实际价格变动的历史相关性调整集成贡献。该引擎在Tradeflags NewsFeed API的3小时轮询周期内运行，该API为每个新闻项目提供22个价格快照字段，涵盖股票指数（ES、NQ、SPY、DJIA、NDX、IWM）、大宗商品（CL）和加密货币（BTC、ETH）。所有处理都在仅使用CPU的服务器上以亚秒的延迟进行，有效地实现了零边际成本的分析周期。我们将我们的方法与FinBERT、基于GPT的评分、VADER和商业情绪API在成本、延迟、准确性和适应性方面进行了比较。我们的统计聚类学习器无需再培训即可适应不断变化的市场制度，这代表了现有情绪系统中没有的新贡献。

Keywords :

### 

\[7\] Dynamic Multi Pair Trading Strategy in Cryptocurrency Markets with Deep Reinforcement Learning

标题:基于深度强化学习的加密货币市场动态多对交易策略

作者:Damian Lebiedź, Robert Ślepaczuk

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04574

Abstract : This study aims to determine whether the application of Deep Reinforcement Learning (DRL) as a specialized execution overlay can enhance pair trading in highly volatile cryptocurrency markets. Although classical implementations of the strategy have proven successful in traditional equities, they frequently exhibit rigidity and suffer from severe divergence risks when applied to high variance environments. To address this need, this research introduces novel concepts. To construct a robust system, we developed a hierarchical  Filter then Rank  pair selection methodology and a proprietary  Fixed Risk, Adaptive Mean  execution model. The system employs a Proximal Policy Optimization (PPO) agent with a Long Short Term Memory (LSTM) layer to govern execution decisions within strict deterministic risk management boundaries. Evaluated on 1 hour interval data from the Binance USD M Futures market, the optimized RL policy achieved an out of sample performance that substantially outperformed the heuristic baseline. A stationary circular block bootstrap robustness check confirms that the agent s risk adjusted outperformance is statistically significant at the 10 percent level. Although falling marginally short of the stricter 5 percent threshold, this result highlights the extreme idiosyncratic variance characteristic of digital assets. Ultimately, this thesis contributes to the quantitative finance literature by introducing a hybrid architecture that combines statistical arbitrage with DRL execution policies. Furthermore, it delivers a novel framework for safe reinforcement learning via deterministic shielding, proving that anchoring a neural policy to statistically robust boundaries successfully mitigates severe divergence risks.

Keywords : 

Abstract :本研究旨在确定深度强化学习（DRL）作为一种专门的执行覆盖层的应用是否可以增强高度波动的加密货币市场中的配对交易。尽管该策略的经典实施已被证明在传统股票中是成功的，但在应用于高方差环境时，它们经常表现出刚性，并面临严重的分歧风险。为了满足这一需求，本研究引入了新的概念。为了构建一个稳健的系统，我们开发了一种分层的过滤器-排名对选择方法和专有的固定风险、自适应均值执行模型。该系统采用具有长短期记忆（LSTM）层的近端策略优化（PPO）代理，在严格的确定性风险管理边界内管理执行决策。根据币安美元期货市场的1小时间隔数据进行评估，优化的RL策略实现了样本外性能，大大优于启发式基线。固定圆形块引导鲁棒性检查证实，代理的风险调整后的表现在10%的水平上具有统计学意义。尽管略低于更严格的5%阈值，但这一结果突显了数字资产的极端特质方差特征。最终，本文通过引入一种将统计套利与DRL执行策略相结合的混合架构，为定量金融文献做出了贡献。此外，它还通过确定性屏蔽提供了一种新的安全强化学习框架，证明将神经策略锚定在统计上稳健的边界上可以成功减轻严重的发散风险。

Keywords :

### 

\[8\] ReSGA

标题:ReSGA

作者:Yichi Zhang, Ke Zhu, Zhoufan Zhu

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04576

Abstract : Learning Value at Risk (VaR) and Expected Shortfall (ES) is important for managing financial risks effectively. Existing approaches with limited parameters are vulnerable to model misspecification in the era of big data. To address this limitation, we propose a large tail risk model, the retrieval enhanced self grouping autoencoder (ReSGA), which is designed with millions of parameters to exploit the rich cross sectional dependence and long term temporal dynamics of assets using their characteristics. Applied to monthly US equity returns from 1926 to 2023 with 153 firm characteristics, ReSGA outperforms twelve econometric and machine learning competitors in terms of out of sample loss and statistical backtesting. In addition, its forecast advantages can translate into significant economic gains from long short decile portfolios that are constructed by a new size enhanced left side momentum strategy. To clarify the role of complexity, we further conduct a systematic scaling analysis and demonstrate that improvements in joint VaR ES forecasting are primarily driven by data complexity rather than model complexity. Finally, our analyses of group importance and transfer learning exhibit the interpretability and cross market generalizability of ReSGA.

Keywords : 

Abstract :学习风险价值（VaR）和预期缺口（ES）对于有效管理金融风险非常重要。在大数据时代，参数有限的现有方法很容易出现模型错误。为了解决这一局限性，我们提出了一种大尾部风险模型，即检索增强型自分组自动编码器（ReSGA），该模型设计有数百万个参数，利用资产的特征利用其丰富的横截面依赖性和长期时间动态性。应用于1926年至2023年的美国月度股票回报，有153个公司特征，ReSGA在样本外损失和统计回溯测试方面优于12个计量经济学和机器学习竞争对手。此外，其预测优势可以转化为由新的规模增强的左侧动量策略构建的长短十分之一投资组合带来的显著经济收益。为了阐明复杂性的作用，我们进一步进行了系统的缩放分析，并证明联合VaR ES预测的改进主要是由数据复杂性而不是模型复杂性驱动的。最后，我们对群体重要性和迁移学习的分析表明了ReSGA的可解释性和跨市场推广性。

Keywords :

### 

\[9\] Worker Utility as Hysteresis

标题:工人效用滞后

作者:Piotr Frydrych

来源:ARXIV\_20260604

链接:https://arxiv.org/pdf/2606.04916

Abstract : Worker utility is not observed    only its consequence is. Each gig transaction produces a single bit  accepted or rejected. We argue this structure points directly to the Preisach hysteresis model as the natural representation of latent worker preferences. The Preisach operator models aggregate output as an integral over a population of binary threshold elements    precisely the structure that emerges when heterogeneous workers each carry a private acceptance wage. We estimate two latent utility surfaces  acceptance utility U 1(X) and rejection utility U 0(X), via a dual output neural network (shared layers 256  128, margin loss enforcing U 1    U 0). Classification reduces to the Preisach gap U 1(X)   U 0(X), passed into an XGBoost classifier alongside clip stabilised price to threshold encodings. On 36,891 gig transactions, this pipeline achieves Jaccard   0.827 and ROC AUC   0.799. The price to threshold encoding accounts for  11.0 pp AUC over raw utility features. The model confirms the directional asymmetry hysteresis predicts  price decreases depress completion rates more than equivalent increases raise them. Applied to the full dataset, the model s recommendations simultaneously reduce the total wage bill by 21.3  and increase expected fill rate by 9.7 pp. For 74.2  of transactions, P(accept) already exceeds 0.80  reducing the wage keeps it above threshold (mean post cut P   0.972), releasing cost savings (median 31 ). For the remaining 25.4 , a median 7  wage increase recovers  43 pp acceptance. A model without an explicit indifference zone cannot execute both moves simultaneously.

Keywords : 

Abstract :Worker实用程序没有被观察到，只是它的结果是。每个gig事务都会产生一个接受或拒绝的比特。我们认为，这种结构直接指向Preisach滞后模型，作为潜在工人偏好的自然表现。Preisach算子将总产出建模为二元阈值元素群体上的一个积分，这正是异质工人各自持有私人接受工资时出现的结构。我们通过双输出神经网络（共享层256 128，边际损失强制U 1 U 0）估计两个潜在的效用面——接受效用U 1（X）和拒绝效用U 0（X）。分类减少到Preisach间隙U 1（X）U 0（X），与削波稳定的价格阈值编码一起传递到XGBoost分类器。在36891次gig交易中，该管道实现了Jaccard 0.827和ROC AUC 0.799。价格阈值编码占原始效用特征的11.0 pp AUC。该模型证实了方向不对称滞后预测价格下降对完成率的抑制作用大于同等增长对完成率提高的抑制作用。应用于整个数据集，该模型的建议同时将总工资账单减少了21.3，并将预期填充率提高了9.7页。对于74.2笔交易，P（接受）已经超过0.80，降低工资使其保持在阈值以上（平均削减后P 0.972），从而节省了成本（中位数31）。对于剩下的25.4，工资中位数7的增长恢复了43个百分点的接受率。没有明确无差异区的模型不能同时执行这两个动作。

Keywords :