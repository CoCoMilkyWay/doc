# 量化前沿速递：机器学习\[20240825\]

shameless 量化前沿速递 2024-08-26 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488127&idx=4&sn=66019fabe5170be7832355ec4c0c4fe9&chksm=c314a7693eff2ff3d869db41866abd77ec1dd3c400133e3a14c6dfc4149fb54344fc0cbd5e23#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488127&idx=4&sn=66019fabe5170be7832355ec4c0c4fe9&chksm=c314a7693eff2ff3d869db41866abd77ec1dd3c400133e3a14c6dfc4149fb54344fc0cbd5e23#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

![](assets/001.jpg)

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/002.png)

### 

文献汇总

\[1\] A case study on different one factor Cheyette models for short maturity caplet calibration

不同单因素Cheyette模型用于短期资本充足率校准的案例研究

来源:ARXIV\_20240822

\[2\] Less is more

少即是多

来源:ARXIV\_20240822

\[3\] Deviations from the Nash equilibrium and emergence of tacit collusion in a two player optimal execution game with reinforcement learning

强化学习下两人最优执行博弈中纳什均衡的偏离和隐性合谋的出现

来源:ARXIV\_20240822

\[4\] A case study on different one factor Cheyette models for short maturity caplet calibration

不同单因素Cheyette模型用于短期资本充足率校准的案例研究

来源:ARXIV\_20240822

\[5\] Less is more

少即是多

来源:ARXIV\_20240822

\[6\] Deviations from the Nash equilibrium and emergence of tacit collusion in a two player optimal execution game with reinforcement learning

强化学习下两人最优执行博弈中纳什均衡的偏离和隐性合谋的出现

来源:ARXIV\_20240822

\[7\] Gradient Reduction Convolutional Neural Network Policy for Financial Deep Reinforcement Learning

金融深度强化学习的梯度缩减卷积神经网络策略

来源:ARXIV\_20240823

\[8\] Empirical Equilibria in Agent based Economic systems with Learning agents

基于学习代理的经济系统中的经验均衡

来源:ARXIV\_20240823

\[9\] Cross border Commodity Pricing Strategy Optimization via Mixed Neural Network for Time Series Analysis

基于时间序列分析的混合神经网络跨境商品定价策略优化

来源:ARXIV\_20240823

### 

\[1\] A case study on different one factor Cheyette models for short maturity caplet calibration

标题:不同单因素Cheyette模型用于短期资本充足率校准的案例研究

作者:Arun Kumar Polala, Bernhard Hientzsch

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11257

Abstract : In  1 , we calibrated a one factor Cheyette SLV model with a local volatility that is linear in the benchmark forward rate and an uncorrelated CIR stochastic variance to 3M caplets of various maturities. While caplet smiles for many maturities could be reasonably well calibrated across the range of strikes, for instance the 1Y maturity could not be calibrated well across that entire range of strikes. Here, we study whether models with alternative local volatility terms and or alternative stochastic volatility or variance models can calibrate the 1Y caplet smile better across the strike range better than the model studied in  1 . This is made possible and feasible by the generic simulation, pricing, and calibration frameworks introduced in  1  and some new frameworks presented in this paper. We find that some model settings calibrate well to the 1Y smile across the strike range under study. In particular, a model setting with a local volatility that is piece wise linear in the benchmark forward rate together with an uncorrelated CIR stochastic variance and one with a local volatility that is linear in the benchmark rate together with a correlated lognormal stochastic volatility with quadratic drift (QDLNSV) as in  2  calibrate well. We discuss why the later might be a preferable model. 1  Arun Kumar Polala and Bernhard Hientzsch. Parametric differential machine learning for pricing and calibration. arXiv preprint arXiv 2302.06682 , 2023. 2  Artur Sepp and Parviz Rakhmonov. A Robust Stochastic Volatility Model for Interest Rate Dynamics. Risk Magazine, 2023

Keywords :

Abstract :在1中，我们校准了一个单因素Cheyette SLV模型，该模型的局部波动率在基准远期利率中是线性的，CIR随机方差与各种到期日的3M资本不相关。虽然许多到期日的caplet微笑可以在整个罢工范围内进行合理的校准，例如1Y到期日不能在整个罢工期间进行良好的校准。在这里，我们研究了具有替代局部波动率项和/或替代随机波动率或方差模型的模型是否可以在整个执行范围内比1中研究的模型更好地校准1Y caplet微笑。通过1中介绍的通用模拟、定价和校准框架以及本文提出的一些新框架，这是可能和可行的。我们发现，在所研究的打击范围内，一些模型设置与1Y微笑校准良好。特别是，如2所示，具有在基准远期利率中呈分段线性的局部波动率以及不相关的CIR随机方差的模型设置，以及具有在基准利率中呈线性的局部变化率以及具有二次漂移的相关对数正态随机波动率（QDLNSV）的模型设置可以很好地校准。我们讨论了为什么后者可能是更可取的模式。1阿伦·库马尔·波拉拉和伯恩哈德·希恩茨。用于定价和校准的参数微分机器学习。arXiv预印本arXiv 2302.066822023。2阿图尔·塞普和帕尔维兹·拉赫莫诺夫。利率动态的稳健随机波动模型。《风险》杂志，2023年

Keywords :

### 

\[2\] Less is more

标题:少即是多

作者:CJ Finnegan, James F. McCann, Salissou Moutari

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11740

Abstract : In this paper we introduce a multi agent deep learning method which trades in the Futures markets based on the US S&P 500 index. The method (referred to as Model A) is an innovation founded on existing well established machine learning models which sample market prices and associated derivatives in order to decide whether the investment should be long short or closed (zero exposure), on a day to day decision. We compare the predictions with some conventional machine learning methods namely, Long Short Term Memory, Random Forest and Gradient Boosted Trees. Results are benchmarked against a passive model in which the Futures contracts are held (long) continuously with the same exposure (level of investment). Historical tests are based on daily daytime trading carried out over a period of 6 calendar years (2018 23). We find that Model A outperforms the passive investment in key performance metrics, placing it within the top quartile performance of US Large Cap active fund managers. Model A also outperforms the three machine learning classification comparators over this period. We observe that Model A is extremely efficient (doing less and getting more) with an exposure to the market of only 41.95  compared to the 100  market exposure of the passive investment, and thus provides increased profitability with reduced risk.

Keywords :

Abstract :本文介绍了一种基于美国标准普尔500指数在期货市场交易的多智能体深度学习方法。该方法（称为模型A）是一种基于现有成熟机器学习模型的创新，该模型对市场价格和相关衍生品进行采样，以便在日常决策中决定投资是多头还是空头（零敞口）。我们将预测结果与一些传统的机器学习方法进行了比较，即长短期记忆、随机森林和梯度增强树。结果以被动模型为基准，在该模型中，期货合约以相同的敞口（投资水平）连续持有（长期）。历史测试基于6个日历年（2018年23月）的每日日间交易。我们发现，模型A在关键绩效指标上优于被动投资，使其处于美国大盘股主动基金经理的前四分之一绩效范围内。在此期间，模型A的表现也优于三个机器学习分类比较器。我们观察到，与被动投资的100个市场敞口相比，模型A的市场敞口仅为41.95，效率极高（做得更少，做得更多），从而提高了盈利能力，降低了风险。

Keywords :

### 

\[3\] Deviations from the Nash equilibrium and emergence of tacit collusion in a two player optimal execution game with reinforcement learning

标题:强化学习下两人最优执行博弈中纳什均衡的偏离和隐性合谋的出现

作者:Fabrizio Lillo, Andrea Macrì

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11773

Abstract : The use of reinforcement learning algorithms in financial trading is becoming increasingly prevalent. However, the autonomous nature of these algorithms can lead to unexpected outcomes that deviate from traditional game theoretical predictions and may even destabilize markets. In this study, we examine a scenario in which two autonomous agents, modeled with Double Deep Q Learning, learn to liquidate the same asset optimally in the presence of market impact, using the Almgren Chriss (2000) framework. Our results show that the strategies learned by the agents deviate significantly from the Nash equilibrium of the corresponding market impact game. Notably, the learned strategies exhibit tacit collusion, closely aligning with the Pareto optimal solution. We further explore how different levels of market volatility influence the agents  performance and the equilibria they discover, including scenarios where volatility differs between the training and testing phases.

Keywords :

Abstract :强化学习算法在金融交易中的使用越来越普遍。然而，这些算法的自主性可能会导致偏离传统博弈论预测的意外结果，甚至可能破坏市场稳定。在这项研究中，我们使用Almgren-Chriss（2000）框架研究了一个场景，其中两个自主代理使用双深度Q学习建模，在存在市场影响的情况下学习最优清算同一资产。我们的结果表明，代理学习的策略显著偏离了相应市场影响博弈的纳什均衡。值得注意的是，所学习的策略表现出隐性合谋，与帕累托最优解密切相关。我们进一步探讨了不同水平的市场波动如何影响代理人的表现及其发现的均衡，包括培训和测试阶段波动性不同的情况。

Keywords :

### 

\[4\] A case study on different one factor Cheyette models for short maturity caplet calibration

标题:不同单因素Cheyette模型用于短期资本充足率校准的案例研究

作者:Arun Kumar Polala, Bernhard Hientzsch

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11257

Abstract : In  1 , we calibrated a one factor Cheyette SLV model with a local volatility that is linear in the benchmark forward rate and an uncorrelated CIR stochastic variance to 3M caplets of various maturities. While caplet smiles for many maturities could be reasonably well calibrated across the range of strikes, for instance the 1Y maturity could not be calibrated well across that entire range of strikes. Here, we study whether models with alternative local volatility terms and or alternative stochastic volatility or variance models can calibrate the 1Y caplet smile better across the strike range better than the model studied in  1 . This is made possible and feasible by the generic simulation, pricing, and calibration frameworks introduced in  1  and some new frameworks presented in this paper. We find that some model settings calibrate well to the 1Y smile across the strike range under study. In particular, a model setting with a local volatility that is piece wise linear in the benchmark forward rate together with an uncorrelated CIR stochastic variance and one with a local volatility that is linear in the benchmark rate together with a correlated lognormal stochastic volatility with quadratic drift (QDLNSV) as in  2  calibrate well. We discuss why the later might be a preferable model. 1  Arun Kumar Polala and Bernhard Hientzsch. Parametric differential machine learning for pricing and calibration. arXiv preprint arXiv 2302.06682 , 2023. 2  Artur Sepp and Parviz Rakhmonov. A Robust Stochastic Volatility Model for Interest Rate Dynamics. Risk Magazine, 2023

Keywords :

Abstract :在1中，我们校准了一个单因素Cheyette SLV模型，该模型的局部波动率在基准远期利率中是线性的，CIR随机方差与各种到期日的3M资本不相关。虽然许多到期日的caplet微笑可以在整个罢工范围内进行合理的校准，例如1Y到期日不能在整个罢工期间进行良好的校准。在这里，我们研究了具有替代局部波动率项和/或替代随机波动率或方差模型的模型是否可以在整个执行范围内比1中研究的模型更好地校准1Y caplet微笑。通过1中介绍的通用模拟、定价和校准框架以及本文提出的一些新框架，这是可能和可行的。我们发现，在所研究的打击范围内，一些模型设置与1Y微笑校准良好。特别是，如2所示，具有在基准远期利率中呈分段线性的局部波动率以及不相关的CIR随机方差的模型设置，以及具有在基准利率中呈线性的局部变化率以及具有二次漂移的相关对数正态随机波动率（QDLNSV）的模型设置可以很好地校准。我们讨论了为什么后者可能是更可取的模式。1阿伦·库马尔·波拉拉和伯恩哈德·希恩茨。用于定价和校准的参数微分机器学习。arXiv预印本arXiv 2302.066822023。2阿图尔·塞普和帕尔维兹·拉赫莫诺夫。利率动态的稳健随机波动模型。《风险》杂志，2023年

Keywords :

### 

\[5\] Less is more

标题:少即是多

作者:CJ Finnegan, James F. McCann, Salissou Moutari

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11740

Abstract : In this paper we introduce a multi agent deep learning method which trades in the Futures markets based on the US S&P 500 index. The method (referred to as Model A) is an innovation founded on existing well established machine learning models which sample market prices and associated derivatives in order to decide whether the investment should be long short or closed (zero exposure), on a day to day decision. We compare the predictions with some conventional machine learning methods namely, Long Short Term Memory, Random Forest and Gradient Boosted Trees. Results are benchmarked against a passive model in which the Futures contracts are held (long) continuously with the same exposure (level of investment). Historical tests are based on daily daytime trading carried out over a period of 6 calendar years (2018 23). We find that Model A outperforms the passive investment in key performance metrics, placing it within the top quartile performance of US Large Cap active fund managers. Model A also outperforms the three machine learning classification comparators over this period. We observe that Model A is extremely efficient (doing less and getting more) with an exposure to the market of only 41.95  compared to the 100  market exposure of the passive investment, and thus provides increased profitability with reduced risk.

Keywords :

Abstract :本文介绍了一种基于美国标准普尔500指数在期货市场交易的多智能体深度学习方法。该方法（称为模型A）是一种基于现有成熟机器学习模型的创新，该模型对市场价格和相关衍生品进行采样，以便在日常决策中决定投资是多头还是空头（零敞口）。我们将预测结果与一些传统的机器学习方法进行了比较，即长短期记忆、随机森林和梯度增强树。结果以被动模型为基准，在该模型中，期货合约以相同的敞口（投资水平）连续持有（长期）。历史测试基于6个日历年（2018年23月）的每日日间交易。我们发现，模型A在关键绩效指标上优于被动投资，使其处于美国大盘股主动基金经理的前四分之一绩效范围内。在此期间，模型A的表现也优于三个机器学习分类比较器。我们观察到，与被动投资的100个市场敞口相比，模型A的市场敞口仅为41.95，效率极高（做得更少，做得更多），从而提高了盈利能力，降低了风险。

Keywords :

### 

\[6\] Deviations from the Nash equilibrium and emergence of tacit collusion in a two player optimal execution game with reinforcement learning

标题:强化学习下两人最优执行博弈中纳什均衡的偏离和隐性合谋的出现

作者:Fabrizio Lillo, Andrea Macrì

来源:ARXIV\_20240822

链接:https://arxiv.org/pdf/2408.11773

Abstract : The use of reinforcement learning algorithms in financial trading is becoming increasingly prevalent. However, the autonomous nature of these algorithms can lead to unexpected outcomes that deviate from traditional game theoretical predictions and may even destabilize markets. In this study, we examine a scenario in which two autonomous agents, modeled with Double Deep Q Learning, learn to liquidate the same asset optimally in the presence of market impact, using the Almgren Chriss (2000) framework. Our results show that the strategies learned by the agents deviate significantly from the Nash equilibrium of the corresponding market impact game. Notably, the learned strategies exhibit tacit collusion, closely aligning with the Pareto optimal solution. We further explore how different levels of market volatility influence the agents  performance and the equilibria they discover, including scenarios where volatility differs between the training and testing phases.

Keywords :

Abstract :强化学习算法在金融交易中的使用越来越普遍。然而，这些算法的自主性可能会导致偏离传统博弈论预测的意外结果，甚至可能破坏市场稳定。在这项研究中，我们使用Almgren-Chriss（2000）框架研究了一个场景，其中两个自主代理使用双深度Q学习建模，在存在市场影响的情况下学习最优清算同一资产。我们的结果表明，代理学习的策略显著偏离了相应市场影响博弈的纳什均衡。值得注意的是，所学习的策略表现出隐性合谋，与帕累托最优解密切相关。我们进一步探讨了不同水平的市场波动如何影响代理人的表现及其发现的均衡，包括培训和测试阶段波动性不同的情况。

Keywords :

### 

\[7\] Gradient Reduction Convolutional Neural Network Policy for Financial Deep Reinforcement Learning

标题:金融深度强化学习的梯度缩减卷积神经网络策略

作者:Sina Montazeri, Haseebullah Jumakhan, Sonia Abrasiabian, Amir Mirzaeinia

来源:ARXIV\_20240823

链接:https://arxiv.org/pdf/2408.11859

Abstract : Building on our prior explorations of convolutional neural networks (CNNs) for financial data processing, this paper introduces two significant enhancements to refine our CNN model s predictive performance and robustness for financial tabular data. Firstly, we integrate a normalization layer at the input stage to ensure consistent feature scaling, addressing the issue of disparate feature magnitudes that can skew the learning process. This modification is hypothesized to aid in stabilizing the training dynamics and improving the model s generalization across diverse financial datasets. Secondly, we employ a Gradient Reduction Architecture, where earlier layers are wider and subsequent layers are progressively narrower. This enhancement is designed to enable the model to capture more complex and subtle patterns within the data, a crucial factor in accurately predicting financial outcomes. These advancements directly respond to the limitations identified in previous studies, where simpler models struggled with the complexity and variability inherent in financial applications. Initial tests confirm that these changes improve accuracy and model stability, suggesting that deeper and more nuanced network architectures can significantly benefit financial predictive tasks. This paper details the implementation of these enhancements and evaluates their impact on the model s performance in a controlled experimental setting.

Keywords :

Abstract :基于我们之前对卷积神经网络（CNN）用于金融数据处理的探索，本文介绍了两项重大改进，以提高我们的CNN模型对金融表格数据的预测性能和鲁棒性。首先，我们在输入阶段集成了一个归一化层，以确保一致的特征缩放，解决了可能扭曲学习过程的不同特征量的问题。假设这种修改有助于稳定训练动态，并提高模型在不同金融数据集上的泛化能力。其次，我们采用梯度缩减架构，其中早期层更宽，后续层逐渐变窄。这种增强旨在使模型能够捕获数据中更复杂和微妙的模式，这是准确预测财务结果的关键因素。这些进步直接回应了先前研究中发现的局限性，在这些研究中，更简单的模型难以应对金融应用程序固有的复杂性和可变性。初步测试证实，这些变化提高了准确性和模型稳定性，表明更深入、更细致的网络架构可以显著有利于财务预测任务。本文详细介绍了这些增强功能的实现，并评估了它们在受控实验环境中对模型性能的影响。

Keywords :

### 

\[8\] Empirical Equilibria in Agent based Economic systems with Learning agents

标题:基于学习代理的经济系统中的经验均衡

作者:Kshama Dwarakanath, Svitlana Vyetrenko, Tucker Balch

来源:ARXIV\_20240823

链接:https://arxiv.org/pdf/2408.12038

Abstract : We present an agent based simulator for economic systems with heterogeneous households, firms, central bank, and government agents. These agents interact to define production, consumption, and monetary flow. Each agent type has distinct objectives, such as households seeking utility from consumption and the central bank targeting inflation and production. We define this multi agent economic system using an OpenAI Gym style environment, enabling agents to optimize their objectives through reinforcement learning. Standard multi agent reinforcement learning (MARL) schemes, like independent learning, enable agents to learn concurrently but do not address whether the resulting strategies are at equilibrium. This study integrates the Policy Space Response Oracle (PSRO) algorithm, which has shown superior performance over independent MARL in games with homogeneous agents, with economic agent based modeling. We use PSRO to develop agent policies approximating Nash equilibria of the empirical economic game, thereby linking to economic equilibria. Our results demonstrate that PSRO strategies achieve lower regret values than independent MARL strategies in our economic system with four agent types. This work aims to bridge artificial intelligence, economics, and empirical game theory towards future research.

Keywords :

Abstract :我们提出了一种基于代理的模拟器，用于具有异构家庭、企业、中央银行和政府代理的经济系统。这些因素相互作用，定义了生产、消费和货币流动。每种代理类型都有不同的目标，例如家庭从消费中寻求效用，央行以通货膨胀和生产为目标。我们使用OpenAI Gym风格的环境定义了这个多智能体经济系统，使智能体能够通过强化学习优化其目标。标准的多智能体强化学习（MARL）方案，如独立学习，使智能体能够同时学习，但不解决由此产生的策略是否处于平衡状态。本研究将策略空间响应Oracle（PSRO）算法与基于经济代理的建模相结合，该算法在具有同构代理的游戏中表现出优于独立MARL的性能。我们使用PSRO来制定近似经验经济博弈纳什均衡的代理策略，从而与经济均衡联系起来。我们的结果表明，在我们的四种代理类型的经济系统中，PSRO策略的遗憾值低于独立的MARL策略。这项工作旨在将人工智能、经济学和经验博弈论与未来的研究联系起来。

Keywords :

### 

\[9\] Cross border Commodity Pricing Strategy Optimization via Mixed Neural Network for Time Series Analysis

标题:基于时间序列分析的混合神经网络跨境商品定价策略优化

作者:Lijuan Wang, Yijia Hu, Yan Zhou

来源:ARXIV\_20240823

链接:https://arxiv.org/pdf/2408.12115

Abstract : In the context of global trade, cross border commodity pricing largely determines the competitiveness and market share of businesses. However, existing methodologies often prove inadequate, as they lack the agility and precision required to effectively respond to the dynamic international markets. Time series data is of great significance in commodity pricing and can reveal market dynamics and trends. Therefore, we propose a new method based on the hybrid neural network model CNN BiGRU SSA. The goal is to achieve accurate prediction and optimization of cross border commodity pricing strategies through in depth analysis and optimization of time series data. Our model undergoes experimental validation across multiple datasets. The results show that our method achieves significant performance advantages on datasets such as UNCTAD, IMF, WITS and China Customs. For example, on the UNCTAD dataset, our model reduces MAE to 4.357, RMSE to 5.406, and R2 to 0.961, significantly better than other models. On the IMF and WITS datasets, our method also achieves similar excellent performance. These experimental results verify the effectiveness and reliability of our model in the field of cross border commodity pricing. Overall, this study provides an important reference for enterprises to formulate more reasonable and effective cross border commodity pricing strategies, thereby enhancing market competitiveness and profitability. At the same time, our method also lays a foundation for the application of deep learning in the fields of international trade and economic strategy optimization, which has important theoretical and practical significance.

Keywords :

Abstract :在全球贸易背景下，跨境商品定价在很大程度上决定了企业的竞争力和市场份额。然而，现有的方法往往被证明是不够的，因为它们缺乏有效应对动态国际市场所需的灵活性和准确性。时间序列数据在商品定价中具有重要意义，可以揭示市场动态和趋势。因此，我们提出了一种基于混合神经网络模型CNN-BiGRU-SSA的新方法。目标是通过对时间序列数据的深入分析和优化，实现跨境商品定价策略的准确预测和优化。我们的模型在多个数据集上进行了实验验证。结果表明，我们的方法在UNCTAD、IMF、WITS和中国海关等数据集上取得了显著的性能优势。例如，在UNCTAD数据集上，我们的模型将MAE降至4.357，RMSE降至5.406，R2降至0.961，明显优于其他模型。在IMF和WITS数据集上，我们的方法也取得了类似的优异性能。这些实验结果验证了我们的模型在跨境商品定价领域的有效性和可靠性。总体而言，本研究为企业制定更合理有效的跨境商品定价策略，从而提高市场竞争力和盈利能力提供了重要参考。同时，我们的方法也为深度学习在国际贸易和经济战略优化领域的应用奠定了基础，具有重要的理论意义和现实意义。

Keywords :