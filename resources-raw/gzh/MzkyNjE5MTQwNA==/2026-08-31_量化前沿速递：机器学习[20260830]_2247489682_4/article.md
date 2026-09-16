# 量化前沿速递：机器学习\[20260830\]

shameless 量化前沿速递 2026-08-31 12:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489682&idx=4&sn=ac15c6e5bf02e8d5ef98446bba241f8c&chksm=c3b3d5e271216958bec4d5506e75c9bdfdf0016bef135bd782cd3b4d7df1806e660b0465c917#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489682&idx=4&sn=ac15c6e5bf02e8d5ef98446bba241f8c&chksm=c3b3d5e271216958bec4d5506e75c9bdfdf0016bef135bd782cd3b4d7df1806e660b0465c917#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Forecasting Weather Driven Price Dynamics Across Sri Lankan Tea Market Catalogues

预测斯里兰卡茶叶市场目录中天气驱动的价格动态

来源:ARXIV\_20260827

\[2\] A Statistical Finance Benchmark for Same Day Directional Stock Prediction

当日定向股票预测的统计金融基准

来源:ARXIV\_20260828

\[3\] Forecasting Economically Significant Bitcoin Moves

预测具有重大经济意义的比特币走势

来源:ARXIV\_20260828

\[4\] A Temporal Multiplex Graph Neural Network for Systemic Risk Transmission in Global Banking

全球银行业系统性风险传导的时间多重图神经网络

来源:ARXIV\_20260828

\[5\] Tabular Deep Learning for Algorithmic Trading

用于算法交易的表格式深度学习

来源:ARXIV\_20260828

### 

\[1\] Forecasting Weather Driven Price Dynamics Across Sri Lankan Tea Market Catalogues

标题:预测斯里兰卡茶叶市场目录中天气驱动的价格动态

作者:Hesandi Mallawarachchi, Senilka Madurapperumage, Nadil Kulathunge, Thilokya Angeesa, Nethsith Gunaweera, Sandeepa Weerasekara, Patalee Narasinghe, Nisansa de Silva, Sandareka Wickramanayake

来源:ARXIV\_20260827

链接:https://arxiv.org/pdf/2608.24894

Abstract : The Colombo Tea Auction (CTA) plays a vital role in determining global tea prices, yet the relationship between local weather conditions and price behavior across different tea catalogues has not been thoroughly explored. In this study, we develop a novel, structured dataset by extracting information from 105 weekly broker reports spanning late 2023 to 2026, and combined with region specific weather data. Our analysis focuses on four main tea catalogues of Sri Lankan tea  High Grown, Low Grown, Off Grade, and Dust. To better understand the factors influencing tea prices, we apply Granger causality analysis alongside tree based machine learning models  Random Forest, XGBoost, LightGBM, and Gradient Boosting. Our results show that while market dynamics are primary drivers, weather conditions also have significant effects. Notably, Low Grown tea shows strong sensitivity to precipitation and sunshine duration (p 0.05) across 1 3 week lags. Off Grade and Dust catalogues also exhibit significant responses to temperature variations. Catalogue specific modelling outperformed unified approaches, with LightGBM emerging as the superior model for three out of four catalogues. Overall, this study highlights the importance of considering both localized weather patterns and catalogue level differences when forecasting tea prices, offering a more precise and practical framework for the tea industry.

Keywords : 

Abstract :科伦坡茶叶拍卖会（CTA）在决定全球茶叶价格方面发挥着至关重要的作用，但当地天气条件与不同茶叶目录之间的价格行为之间的关系尚未得到深入探讨。在这项研究中，我们通过从2023年底至2026年的105份每周经纪人报告中提取信息，并结合特定地区的天气数据，开发了一个新颖的结构化数据集。我们的分析侧重于斯里兰卡茶叶的四个主要类别——高熟茶、低熟茶、劣质茶和含尘茶。为了更好地了解影响茶叶价格的因素，我们将格兰杰因果关系分析与基于树的机器学习模型随机森林、XGBoost、LightGBM和梯度提升一起应用。我们的研究结果表明，虽然市场动态是主要驱动因素，但天气条件也有显著影响。值得注意的是，低生长茶在13周的滞后期内对降水和日照时间表现出很强的敏感性（p 0.05）。越野和灰尘目录也对温度变化表现出显著的响应。特定目录的建模优于统一方法，LightGBM成为四分之三目录的最佳模型。总体而言，这项研究强调了在预测茶叶价格时考虑局部天气模式和目录水平差异的重要性，为茶叶行业提供了一个更精确和实用的框架。

Keywords :

### 

\[2\] A Statistical Finance Benchmark for Same Day Directional Stock Prediction

标题:当日定向股票预测的统计金融基准

作者:Alex Chen

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.26106

Abstract : We study statistical predictability in daily U.S. equity prices using only information available at the market open. Using SPY from February 1, 1993 through March 15, 2024, we benchmark XGBoost against Random Forest, LightGBM, Logistic Regression, and naive baselines under expanding window walk forward validation. After observing the current day s opening price and two lagged target specific prices, the task is to predict whether the same day s close will be above or below the previous day s close.On the last 800 trading days, Logistic Regression attains the highest close direction accuracy (71.09 ), Random Forest reaches 61.20 , and XGBoost reaches 58.45  with a 95  bootstrap confidence interval of  54.94 , 62.08 . For XGBoost, close direction accuracy rises to 72.7  when the predicted move exceeds 1 , but the usable sample falls to 154 observations. We also report Diebold Mariano and McNemar tests, regime specific results, SHAP feature importance, and an auxiliary 541 equity screen.The evidence supports a narrow statistical finance conclusion  simple daily equity features contain detectable same day directional information, but the result should be interpreted with careful sample size accounting and limited economic claims.

Keywords : 

Abstract :我们仅使用开盘时可用的信息来研究美国每日股票价格的统计可预测性。使用1993年2月1日至2024年3月15日的SPY，我们在扩展窗口前走验证下将XGBoost与随机森林、LightGBM、逻辑回归和原始基线进行基准测试。在观察了当天的开盘价和两个滞后的目标特定价格后，任务是预测当天的收盘价是高于还是低于前一天的收盘价。在过去的800个交易日，逻辑回归达到了最高的收盘方向精度（71.09），随机森林达到了61.20，XGBoost达到了58.45，95引导置信区间为54.94，62.08。对于XGBoost，当预测移动超过1时，近距离方向精度上升到72.7，但可用样本下降到154个观测值。我们还报告了Diebold Mariano和McNemar测试、特定制度的结果、SHAP特征重要性以及辅助的541股权筛查。证据支持狭义的统计金融结论——简单的每日权益特征包含可检测的当日方向信息，但应通过仔细的样本量会计和有限的经济索赔来解释结果。

Keywords :

### 

\[3\] Forecasting Economically Significant Bitcoin Moves

标题:预测具有重大经济意义的比特币走势

作者:Parsa Yousefnezhad, Gholamreza Mansourfar, Mohammadreza Feizi Derakhshi

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.26174

Abstract : Bitcoin s future fluctuations are a substantial concern for investments and risk management. Investors and financial institutions require accurate forecasts of these price movements to hedge and optimize portfolios. This study aims to answer the question of whether Bitcoin s price will rise beyond 5  within the next 7 days by utilizing on chain, market, and sentiment data from February 2018 to December 2025. The proposed model consists of a multi scale temporal convolutional network with InceptionTCN blocks, CNN channel attention, adaptive average pooling, and a pairwise ranking loss. Dilated convolutions with bottleneck and fusion layers are employed to efficiently capture features over horizons from 1 to 4 days. Given the class imbalance in the dataset, AUC is used instead of accuracy and other classification metrics to reflect the model s performance better. Subsequently, a profit optimized decision threshold is also applied to align model selection with financial objectives. The proposed model is compared with 5 other baselines  ImprovedTCN GRU, LSTM, TCN, XGBoost, and Random Forest. Results indicate that the proposed model achieved an AUC of 0.6316 and a profit of 1.703, outperforming all baseline models. Using a novel deep learning model would assist investors in making better financial decisions.

Keywords : 

Abstract :比特币的未来波动是投资和风险管理的一个重大问题。投资者和金融机构需要对这些价格变动进行准确预测，以对冲和优化投资组合。本研究旨在利用2018年2月至2025年12月的链上、市场和情绪数据，回答比特币价格是否会在未来7天内上涨超过5的问题。所提出的模型由一个具有InceptionTCN块、CNN信道注意力、自适应平均池和成对排名损失的多尺度时间卷积网络组成。采用具有瓶颈和融合层的扩展卷积来有效地捕获1至4天范围内的特征。鉴于数据集中的类不平衡，使用AUC而不是准确性和其他分类指标来更好地反映模型的性能。随后，还应用了利润优化的决策阈值，以使模型选择与财务目标保持一致。将提出的模型与其他5个基线ImprovedTCN-GRU、LSTM、TCN、XGBoost和随机森林进行了比较。结果表明，所提出的模型实现了0.6316的AUC和1.703的利润，优于所有基线模型。使用新的深度学习模型将帮助投资者做出更好的财务决策。

Keywords :

### 

\[4\] A Temporal Multiplex Graph Neural Network for Systemic Risk Transmission in Global Banking

标题:全球银行业系统性风险传导的时间多重图神经网络

作者:Nneka Umeorah, Tolulope Fadina

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.27295

Abstract : This paper develops a unified framework for assessing systemic risk and identifying contagion channels in the global banking system using a Temporal Heterogeneous Multiplex Graph Neural Network. We construct a harmonised quarterly panel combining bank fundamentals, CDS spreads, and macroeconomic indicators, and represent these data as dynamic multiplex networks linking banks through financial similarity and liquidity co movement, augmented with country level macroeconomic relationships. The model integrates graph convolutional layers with recurrent GRU dynamics and incorporates a learnable fusion gate to capture time varying reliance on alternative contagion channels. Empirical results show that the framework outperforms conventional econometric, machine learning, and graph based benchmarks for short term changes in CDS spreads. Beyond forecasting, we provide an interpretable framework to quantify bank level systemic importance via stress testing, assess country level spillovers under macroeconomic shocks, and uncover transmission pathways through edge perturbation analysis. Robustness tests confirm the stability of both predictive accuracy and systemic risk rankings.

Keywords : 

Abstract :本文使用时间异构多重图神经网络开发了一个统一的框架，用于评估系统性风险和识别全球银行系统中的传染渠道。我们构建了一个结合银行基本面、CDS利差和宏观经济指标的协调季度面板，并将这些数据表示为通过金融相似性和流动性联动将银行联系起来的动态多重网络，并辅以国家层面的宏观经济关系。该模型将图卷积层与循环GRU动态相结合，并引入了一个可学习的融合门，以捕捉对替代传染通道的时变依赖。实证结果表明，该框架在CDS利差的短期变化方面优于传统的计量经济学、机器学习和基于图的基准。除了预测，我们还提供了一个可解释的框架，通过压力测试量化银行层面的系统重要性，评估宏观经济冲击下的国家层面溢出效应，并通过边缘扰动分析揭示传播途径。稳健性检验证实了预测准确性和系统性风险排名的稳定性。

Keywords :

### 

\[5\] Tabular Deep Learning for Algorithmic Trading

标题:用于算法交易的表格式深度学习

作者:Joshua Le Grice

来源:ARXIV\_20260828

链接:https://arxiv.org/pdf/2608.27076

Abstract : Algorithmic trading now represents a market exceeding  20 billion, where even marginal gains in signal robustness can translate into economically significant returns. Existing evaluations of equity prediction models do not explicitly target regime robustness during hyperparameter selection. Five model classes are trained on daily observations from approximately 300 large cap US equities over eleven years, with Bayesian optimisation configured to target trading performance across three statistically different market regimes. Regime robust hyperparameter selection is associated with out of sample generalisation, as signal precision remains above the random baseline across all four quarters of the test period, and portfolio performance slowly degrades under simulated input noise before collapsing beyond a defined threshold. No individual tabular deep learning architecture outperforms gradient boosted trees, but combining XGBoost and TabNet using rank aggregation produces a Hybrid ensemble with an annualised return of 51.26 , a Sharpe ratio of 2.44, and a statistically significant CAPM alpha of 0.423 (p   0.011). A near zero beta indicates this outperformance is driven by stock selection, not market exposure. Alternative data plays a secondary role once technical and fundamental features are accounted for, as well as contributing more strongly on the short side than the long, and varies by model class. An interactive application makes these results explorable in real time, with live data integration the remaining step toward practical deployment.

Keywords : 

Abstract :算法交易现在代表了一个超过200亿的市场，在这个市场中，即使信号鲁棒性的微小收益也可以转化为具有经济意义的回报。现有的股权预测模型评估在超参数选择过程中没有明确针对制度稳健性。五个模型类基于11年来约300只美国大盘股的日常观察进行训练，贝叶斯优化配置为针对三种统计上不同的市场制度的交易表现。制度鲁棒超参数选择与样本外泛化有关，因为信号精度在测试期的所有四个季度都保持在随机基线之上，投资组合性能在模拟输入噪声下缓慢下降，然后崩溃到定义的阈值之外。没有任何单一的表格式深度学习架构能超越梯度增强树，但使用秩聚合将XGBoost和TabNet结合起来，可以产生一个混合集成，年化回报率为51.26，夏普比率为2.44，统计上显著的CAPMα为0.423（p 0.011）。接近零的贝塔系数表明，这种表现是由股票选择驱动的，而不是市场风险。一旦考虑到技术和基本特征，替代数据就起着次要作用，并且在短期内比长期内贡献更大，并且因模型类别而异。交互式应用程序使这些结果可以实时探索，实时数据集成是实现实际部署的剩余步骤。

Keywords :