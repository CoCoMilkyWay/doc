# 量化前沿速递：机器学习\[20241020\]

shameless 量化前沿速递 2024-10-21 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488241&idx=3&sn=8b7e3a689ae93a71b0622a75b0350692&chksm=c3ce14eefb519a8e7de9d841707a12c6804979ca8f2723d591a86e8a25b4f02a44ae0ed3fac4#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488241&idx=3&sn=8b7e3a689ae93a71b0622a75b0350692&chksm=c3ce14eefb519a8e7de9d841707a12c6804979ca8f2723d591a86e8a25b4f02a44ae0ed3fac4#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Identifying Money Laundering Subgraphs on the Blockchain

识别区块链上的洗钱子图

来源:ARXIV\_20241014

\[2\] Smart Trading Using Technical Analysis on the Crypto Market: Benchmarking Lstm (Long Short Term Memory), Dqn (Deep Q Network) and Rf (Random Forest) Agents

使用加密货币市场技术分析的智能交易：对Lstm（长期短期记忆）、Dqn（深度Q网络）和Rf（随机森林）代理进行基准测试

来源:SSRN\_20241015

\[3\] Solving The Dynamic Volatility Fitting Problem

求解动态波动率拟合问题

来源:ARXIV\_20241016

\[4\] A Hierarchical conv LSTM and LLM Integrated Model for Holistic Stock Forecasting

用于整体股票预测的分层conv-LSTM和LLM集成模型

来源:ARXIV\_20241018

\[5\] Optimization of Actuarial Neural Networks with Response Surface Methodology

基于响应面法的精算神经网络优化

来源:ARXIV\_20241018

\[6\] IPO Pricing Research Based on Lasso-Fully Connected Neural Networks: Evidence from China

基于Lasso全连接神经网络的IPO定价研究：来自中国的证据

来源:SSRN\_20241018

### 

\[1\] Identifying Money Laundering Subgraphs on the Blockchain

标题:识别区块链上的洗钱子图

作者:Kiwhan Song, Mohamed Ali Dhraief, Muhua Xu, Locke Cai, Xuhao Chen, Arvind, Jie Chen

来源:ARXIV\_20241014

链接:https://arxiv.org/pdf/2410.08394

Abstract : Anti Money Laundering (AML) involves the identification of money laundering crimes in financial activities, such as cryptocurrency transactions. Recent studies advanced AML through the lens of graph based machine learning, modeling the web of financial transactions as a graph and developing graph methods to identify suspicious activities. For instance, a recent effort on opensourcing datasets and benchmarks, Elliptic2, treats a set of Bitcoin addresses, considered to be controlled by the same entity, as a graph node and transactions among entities as graph edges. This modeling reveals the  shape  of a money laundering scheme   a subgraph on the blockchain. Despite the attractive subgraph classification results benchmarked by the paper, competitive methods remain expensive to apply due to the massive size of the graph  moreover, existing methods require candidate subgraphs as inputs which may not be available in practice. In this work, we introduce RevTrack, a graph based framework that enables large scale AML analysis with a lower cost and a higher accuracy. The key idea is to track the initial senders and the final receivers of funds  these entities offer a strong indication of the nature (licit vs. suspicious) of their respective subgraph. Based on this framework, we propose RevClassify, which is a neural network model for subgraph classification. Additionally, we address the practical problem where subgraph candidates are not given, by proposing RevFilter. This method identifies new suspicious subgraphs by iteratively filtering licit transactions, using RevClassify. Benchmarking these methods on Elliptic2, a new standard for AML, we show that RevClassify outperforms state of the art subgraph classification techniques in both cost and accuracy. Furthermore, we demonstrate the effectiveness of RevFilter in discovering new suspicious subgraphs, confirming its utility for practical AML.

Keywords :

Abstract :反洗钱（AML）涉及识别金融活动中的洗钱犯罪，如加密货币交易。最近的研究通过基于图的机器学习的视角推进了反洗钱，将金融交易网络建模为图形，并开发了图形方法来识别可疑活动。例如，最近在开源数据集和基准测试方面的一项努力Elliptic2将一组被认为由同一实体控制的比特币地址视为图节点，将实体之间的交易视为图边。该建模揭示了区块链上洗钱方案的子图形状。尽管本文以有吸引力的子图分类结果为基准，但由于图的巨大规模，竞争性方法的应用仍然很昂贵。此外，现有方法需要候选子图作为输入，这在实践中可能不可用。在这项工作中，我们介绍了RevTrack，这是一个基于图的框架，可以以较低的成本和较高的准确性进行大规模AML分析。关键思想是跟踪资金的初始发送者和最终接收者，这些实体有力地表明了其各自子图的性质（合法与可疑）。基于该框架，我们提出了RevClassify，这是一种用于子图分类的神经网络模型。此外，我们通过提出RevFilter来解决未给出子图候选的实际问题。该方法通过使用RevClassify迭代过滤合法交易来识别新的可疑子图。在AML的新标准Elliptic2上对这些方法进行基准测试，我们发现RevClassify在成本和准确性方面都优于最先进的子图分类技术。此外，我们证明了RevFilter在发现新的可疑子图方面的有效性，证实了它对实际AML的实用性。

Keywords :

### 

\[2\] Smart Trading Using Technical Analysis on the Crypto Market: Benchmarking Lstm (Long Short Term Memory), Dqn (Deep Q Network) and Rf (Random Forest) Agents

标题:使用加密货币市场技术分析的智能交易：对Lstm（长期短期记忆）、Dqn（深度Q网络）和Rf（随机森林）代理进行基准测试

作者:ALDAN JAY CUERVO,RAFAEL BERLANGA

来源:SSRN\_20241015

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=4987237

Abstract : The volatile and speculative nature of the cryptocurrency market presents unique challenges and opportunities for traders. This study aims to optimize technical analysis (TA) indicators through the application of advanced computational models, specifically Deep Q-Network (DQN), Long Short-Term Memory (LSTM), and Random Forest (RF) agents. Using a systematic backtesting approach, these models were evaluated based on criteria such as Total Return, Annualized Return, Annualized Volatility, Sharpe Ratio, Sortino Ratio, Max Drawdown, and Calmar Ratio.  The DQN model demonstrated superior performance in profitability and risk management, while the LSTM model excelled in generating consistent returns. The RF model was most effective in minimizing Max Drawdown, indicating robust volatility management. A significant finding is the absence of a single optimal TA indicator, underscoring the need for adaptive and diversified trading strategies. This study highlights the potential of integrating advanced computational methods with real-time data analysis to enhance automated trading strategies in the cryptocurrency market. Future work should focus on developing hybrid models, implementing dynamic TA indicator selection, refining risk management strategies, and conducting real-world testing to validate these findings.

Keywords : Algorithmic trading, Deep learning agents benchmarking, Random Forest control for max drawdown, DQN best profit

Abstract :加密货币市场的波动性和投机性为交易者带来了独特的挑战和机遇。本研究旨在通过应用先进的计算模型，特别是深度Q网络（DQN）、长短期记忆（LSTM）和随机森林（RF）代理，优化技术分析（TA）指标。使用系统的回溯测试方法，根据总回报率、年化回报率、年度波动率、夏普比率、索蒂诺比率、最大提款率和卡尔玛比率等标准对这些模型进行了评估。DQN模型在盈利能力和风险管理方面表现出色，而LSTM模型在产生一致回报方面表现出色。RF模型在最小化最大提款方面最为有效，表明波动管理稳健。一个重要的发现是，没有一个最佳的TA指标，这突显了适应性和多样化交易策略的必要性。这项研究强调了将先进的计算方法与实时数据分析相结合的潜力，以增强加密货币市场的自动化交易策略。未来的工作应侧重于开发混合模型，实施动态TA指标选择，完善风险管理策略，并进行实际测试以验证这些发现。

Keywords :算法交易、深度学习代理基准测试、最大提款的随机森林控制、DQN最佳利润

### 

\[3\] Solving The Dynamic Volatility Fitting Problem

标题:求解动态波动率拟合问题

作者:Emmanuel Gnabeyeu, Omar Karkar, Imad Idboufous

来源:ARXIV\_20241016

链接:https://arxiv.org/pdf/2410.11789

Abstract : The volatility fitting is one of the core problems in the equity derivatives business. Through a set of deterministic rules, the degrees of freedom in the implied volatility surface encoding (parametrization, density, diffusion) are defined. Whilst very effective, this approach widespread in the industry is not natively tailored to learn from shifts in market regimes and discover unsuspected optimal behaviors. In this paper, we change the classical paradigm and apply the latest advances in Deep Reinforcement Learning(DRL) to solve the fitting problem. In particular, we show that variants of Deep Deterministic Policy Gradient (DDPG) and Soft Actor Critic (SAC) can achieve at least as good as standard fitting algorithms. Furthermore, we explain why the reinforcement learning framework is appropriate to handle complex objective functions and is natively adapted for online learning.

Keywords :

Abstract :波动率拟合是股票衍生品业务的核心问题之一。通过一组确定性规则，定义了隐含波动率表面编码（参数化、密度、扩散）的自由度。虽然这种方法非常有效，但在行业中广泛使用的这种方法并不是为从市场制度的变化中学习并发现未被怀疑的最佳行为而量身定制的。本文改变了经典范式，应用深度强化学习（DRL）的最新进展来解决拟合问题。特别是，我们证明了深度确定性策略梯度（DDPG）和软行动者批判（SAC）的变体至少可以实现与标准拟合算法一样好的效果。此外，我们解释了为什么强化学习框架适合处理复杂的目标函数，并且天生适用于在线学习。

Keywords :

### 

\[4\] A Hierarchical conv LSTM and LLM Integrated Model for Holistic Stock Forecasting

标题:用于整体股票预测的分层conv-LSTM和LLM集成模型

作者:Arya Chakraborty, Auhona Basu

来源:ARXIV\_20241018

链接:https://arxiv.org/pdf/2410.12807

Abstract : The financial domain presents a complex environment for stock market prediction, characterized by volatile patterns and the influence of multifaceted data sources. Traditional models have leveraged either Convolutional Neural Networks (CNN) for spatial feature extraction or Long Short Term Memory (LSTM) networks for capturing temporal dependencies, with limited integration of external textual data. This paper proposes a novel Two Level Conv LSTM Neural Network integrated with a Large Language Model (LLM) for comprehensive stock advising. The model harnesses the strengths of Conv LSTM for analyzing time series data and LLM for processing and understanding textual information from financial news, social media, and reports. In the first level, convolutional layers are employed to identify local patterns in historical stock prices and technical indicators, followed by LSTM layers to capture the temporal dynamics. The second level integrates the output with an LLM that analyzes sentiment and contextual information from textual data, providing a holistic view of market conditions. The combined approach aims to improve prediction accuracy and provide contextually rich stock advising.

Keywords :

Abstract :金融领域为股市预测提供了一个复杂的环境，其特征是波动的模式和多方面数据源的影响。传统模型利用卷积神经网络（CNN）进行空间特征提取，或利用长短期记忆（LSTM）网络捕获时间依赖性，对外部文本数据的集成有限。本文提出了一种与大型语言模型（LLM）集成的新型两级卷积LSTM神经网络，用于综合股票建议。该模型利用Conv-LSTM分析时间序列数据的优势，以及LLM处理和理解金融新闻、社交媒体和报告中的文本信息的优势。在第一层中，卷积层用于识别历史股价和技术指标中的局部模式，然后是LSTM层来捕捉时间动态。第二级将输出与LLM相结合，LLM从文本数据中分析情绪和上下文信息，提供市场状况的整体视图。这种组合方法旨在提高预测准确性，并提供上下文丰富的股票建议。

Keywords :

### 

\[5\] Optimization of Actuarial Neural Networks with Response Surface Methodology

标题:基于响应面法的精算神经网络优化

作者:Belguutei Ariuntugs, Kehelwala Dewage Gayan Madurang

来源:ARXIV\_20241018

链接:https://arxiv.org/pdf/2410.12824

Abstract : In the data driven world of actuarial science, machine learning (ML) plays a crucial role in predictive modeling, enhancing risk assessment and pricing strategies. Neural networks, specifically combined actuarial neural networks (CANN), are vital for tasks such as mortality forecasting and pricing. However, optimizing hyperparameters (e.g., learning rates, layers) is essential for resource efficiency.This study utilizes a factorial design and response surface methodology (RSM) to optimize CANN performance. RSM effectively explores the hyperparameter space and captures potential curvature, outperforming traditional grid search. Our results show accurate performance predictions, identifying critical hyperparameters. By dropping statistically insignificant hyperparameters, we reduced runs from 288 to 188, with negligible loss in accuracy, achieving near optimal out of sample Poisson deviance loss.

Keywords :

Abstract :在数据驱动的精算科学领域，机器学习（ML）在预测建模、增强风险评估和定价策略方面发挥着至关重要的作用。神经网络，特别是组合精算神经网络（CANN），对于死亡率预测和定价等任务至关重要。然而，优化超参数（例如学习率、层）对于资源效率至关重要。本研究利用析因设计和响应面方法（RSM）优化CANN性能。RSM有效地探索了超参数空间并捕获了潜在的曲率，优于传统的网格搜索。我们的结果显示了准确的性能预测，识别了关键的超参数。通过删除统计上不显著的超参数，我们将运行次数从288次减少到188次，精度损失可以忽略不计，实现了接近最优的样本外泊松偏差损失。

Keywords :

### 

\[6\] IPO Pricing Research Based on Lasso-Fully Connected Neural Networks: Evidence from China

标题:基于Lasso全连接神经网络的IPO定价研究：来自中国的证据

作者:Rui Ge,lu jiang

来源:SSRN\_20241018

链接:https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=4990940

Abstract : This study aims to predict the initial public offering (IPO) pricing of Chinese companies using machine learning techniques, specifically neural networks. We develop a Lasso- fully connected neural network model to forecast the IPO pricing of A-share listed companies from December 1990 to December 2023 and find that it demonstrated the model demonstrates strong generalization capabilities, with an overall goodness-of-fit exceeding 0.80 and an accuracy rate above 70% within the defined thresholds. Furthermore, local interpretation analysis reveals that retained earnings per share (REPS) exerts the most significant influence on IPO pricing for Chinese companies.

Keywords : FNN, IPO pricing, Lasso, Shapley

Abstract :本研究旨在使用机器学习技术，特别是神经网络，预测中国公司的首次公开募股（IPO）定价。我们开发了一个Lasso全连接神经网络模型来预测1990年12月至2023年12月a股上市公司的IPO定价，发现该模型表现出很强的泛化能力，在规定的阈值内，整体拟合优度超过0.80，准确率超过70%。此外，局部解释分析表明，每股留存收益（REPS）对中国公司的IPO定价影响最大。

Keywords :FNN、IPO定价、Lasso、Shapley