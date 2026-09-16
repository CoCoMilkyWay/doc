# 量化前沿速递：机器学习\[20240731\]

shameless 量化前沿速递 2024-08-01 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488058&idx=3&sn=709f1da083236b4782747437eea4f9c2&chksm=c35e8341b8ef8f0e26b8f93a2caef9e396b79fe57af85f0afac276515e0f7603203ccd3fd46d#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488058&idx=3&sn=709f1da083236b4782747437eea4f9c2&chksm=c35e8341b8ef8f0e26b8f93a2caef9e396b79fe57af85f0afac276515e0f7603203ccd3fd46d#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

![](assets/001.jpg)

获取文献链接/翻译/pdf请加入知识星球“量化前沿速递”

![](assets/002.png)

### 

文献汇总

\[1\] A Comprehensive Analysis of Machine Learning Models for Algorithmic Trading of Bitcoin

比特币算法交易的机器学习模型综合分析

来源:ARXIV\_20240729

\[2\] CVA Sensitivities, Hedging and Risk

CVA敏感性、对冲和风险

来源:ARXIV\_20240729

\[3\] Enhancing Black Scholes Delta Hedging via Deep Learning

通过深度学习增强Black-Scholes Delta对冲

来源:ARXIV\_20240730

\[4\] Generative model for financial time series trained with MMD using a signature kernel

使用签名核的MMD训练的金融时间序列生成模型

来源:ARXIV\_20240730

\[5\] AI Powered Energy algorithmic Trading

AI驱动的能源算法交易

来源:ARXIV\_20240730

\[6\] Design and Optimization of Big Data and Machine Learning Based Risk Monitoring System in Financial Markets

基于大数据和机器学习的金融市场风险监测系统的设计与优化

来源:ARXIV\_20240730

\[7\] PO QA

波卡

来源:ARXIV\_20240730

### 

\[1\] A Comprehensive Analysis of Machine Learning Models for Algorithmic Trading of Bitcoin

标题:比特币算法交易的机器学习模型综合分析

作者:Abdul Jabbar, Syed Qaisar Jalil

来源:ARXIV\_20240729

链接:https://arxiv.org/pdf/2407.18334

Abstract : This study evaluates the performance of 41 machine learning models, including 21 classifiers and 20 regressors, in predicting Bitcoin prices for algorithmic trading. By examining these models under various market conditions, we highlight their accuracy, robustness, and adaptability to the volatile cryptocurrency market. Our comprehensive analysis reveals the strengths and limitations of each model, providing critical insights for developing effective trading strategies. We employ both machine learning metrics (e.g., Mean Absolute Error, Root Mean Squared Error) and trading metrics (e.g., Profit and Loss percentage, Sharpe Ratio) to assess model performance. Our evaluation includes backtesting on historical data, forward testing on recent unseen data, and real world trading scenarios, ensuring the robustness and practical applicability of our models. Key findings demonstrate that certain models, such as Random Forest and Stochastic Gradient Descent, outperform others in terms of profit and risk management. These insights offer valuable guidance for traders and researchers aiming to leverage machine learning for cryptocurrency trading.

Keywords :

Abstract :本研究评估了41个机器学习模型（包括21个分类器和20个回归器）在预测算法交易比特币价格方面的性能。通过在各种市场条件下检查这些模型，我们强调了它们的准确性、稳健性和对波动的加密货币市场的适应性。我们的全面分析揭示了每种模型的优势和局限性，为制定有效的交易策略提供了关键的见解。我们采用机器学习指标（如平均绝对误差、均方根误差）和交易指标（如损益百分比、夏普比率）来评估模型性能。我们的评估包括对历史数据的回溯测试、对最近看不见的数据的前瞻测试和现实世界的交易场景，以确保我们模型的稳健性和实用性。关键发现表明，某些模型，如随机森林和随机梯度下降，在利润和风险管理方面优于其他模型。这些见解为旨在利用机器学习进行加密货币交易的交易者和研究人员提供了宝贵的指导。

Keywords :

### 

\[2\] CVA Sensitivities, Hedging and Risk

标题:CVA敏感性、对冲和风险

作者:Stéphane Crépey (UFR Mathématiques UPCité), Botao Li (LPSM (UMR \_8001)), Hoang Nguyen (IES, LPSM (UMR \_8001)), Bouazza Saadeddine

来源:ARXIV\_20240729

链接:https://arxiv.org/pdf/2407.18583

Abstract : We present a unified framework for computing CVA sensitivities, hedging the CVA, and assessing CVA risk, using probabilistic machine learning meant as refined regression tools on simulated data, validatable by low cost companion Monte Carlo procedures. Various notions of sensitivitiesare introducedand benchmarked numerically.We identify the sensitivities representing the best practical trade offs in downstream tasks including CVA hedging and risk assessment.

Keywords :

Abstract :我们提出了一个统一的框架，用于计算CVA敏感性、对冲CVA和评估CVA风险，使用概率机器学习作为模拟数据的精细回归工具，可通过低成本配套蒙特卡洛程序进行验证。引入了各种敏感性概念，并对其进行了数值基准测试。我们确定了代表下游任务（包括CVA对冲和风险评估）中最佳实际权衡的敏感性。

Keywords :

### 

\[3\] Enhancing Black Scholes Delta Hedging via Deep Learning

标题:通过深度学习增强Black-Scholes Delta对冲

作者:Chunhui Qiao, Xiangwei Wan

来源:ARXIV\_20240730

链接:https://arxiv.org/pdf/2407.19367

Abstract : This paper proposes a deep delta hedging framework for options, utilizing neural networks to learn the residuals between the hedging function and the implied Black Scholes delta. This approach leverages the smoother properties of these residuals, enhancing deep learning performance. Utilizing ten years of daily S&P 500 index option data, our empirical analysis demonstrates that learning the residuals, using the mean squared one step hedging error as the loss function, significantly improves hedging performance over directly learning the hedging function, often by more than 100 . Adding input features when learning the residuals enhances hedging performance more for puts than calls, with market sentiment being less crucial. Furthermore, learning the residuals with three years of data matches the hedging performance of directly learning with ten years of data, proving that our method demands less data.

Keywords :

Abstract :本文提出了一种期权深度delta套期保值框架，利用神经网络学习套期保值函数与隐含Black-Scholes delta之间的残差。这种方法利用了这些残差的平滑特性，提高了深度学习性能。利用十年来的每日标准普尔500指数期权数据，我们的实证分析表明，与直接学习套期保值函数相比，学习残差，使用均方一步套期保值误差作为损失函数，可以显著提高套期保值绩效，通常提高100多倍。在学习残差时添加输入特征，可以比看涨期权更有效地提高看跌期权的套期保值性能，而市场情绪则不那么重要。此外，用三年数据学习残差与用十年数据直接学习的套期保值性能相匹配，证明我们的方法需要更少的数据。

Keywords :

### 

\[4\] Generative model for financial time series trained with MMD using a signature kernel

标题:使用签名核的MMD训练的金融时间序列生成模型

作者:Lu Chung I, Julian Sester

来源:ARXIV\_20240730

链接:https://arxiv.org/pdf/2407.19848

Abstract : Generating synthetic financial time series data that accurately reflects real world market dynamics holds tremendous potential for various applications, including portfolio optimization, risk management, and large scale machine learning. We present an approach for training generative models for financial time series using the maximum mean discrepancy (MMD) with a signature kernel. Our method leverages the expressive power of the signature transform to capture the complex dependencies and temporal structures inherent in financial data. We employ a moving average model to model the variance of the noise input, enhancing the model s ability to reproduce stylized facts such as volatility clustering. Through empirical experiments on S&P 500 index data, we demonstrate that our model effectively captures key characteristics of financial time series and outperforms a comparable GAN based approach. In addition, we explore the application of the synthetic data generated to train a reinforcement learning agent for portfolio management, achieving promising results. Finally, we propose a method to add robustness to the generative model by tweaking the noise input so that the generated sequences can be adjusted to different market environments with minimal data.

Keywords :

Abstract :生成准确反映现实世界市场动态的合成金融时间序列数据在各种应用中具有巨大的潜力，包括投资组合优化、风险管理和大规模机器学习。我们提出了一种使用具有签名核的最大均值差异（MMD）来训练金融时间序列生成模型的方法。我们的方法利用签名转换的表现力来捕捉金融数据中固有的复杂依赖关系和时间结构。我们采用移动平均模型来模拟噪声输入的方差，增强了模型再现波动率聚类等程式化事实的能力。通过对标准普尔500指数数据的实证实验，我们证明我们的模型有效地捕捉了金融时间序列的关键特征，并优于基于GAN的可比方法。此外，我们还探索了将生成的合成数据应用于训练用于投资组合管理的强化学习代理，取得了有前景的结果。最后，我们提出了一种通过调整噪声输入来增强生成模型鲁棒性的方法，以便生成的序列能够以最少的数据适应不同的市场环境。

Keywords :

### 

\[5\] AI Powered Energy algorithmic Trading

标题:AI驱动的能源算法交易

作者:Tiago Monteiro

来源:ARXIV\_20240730

链接:https://arxiv.org/pdf/2407.19858

Abstract : In the field of quantitative finance, machine learning methods have become essential for alpha generation. This paper presents a pioneering method that uniquely combines Hidden Markov Models (HMM) and neural networks, creating a dual model alpha generation system integrated with Black Litterman portfolio optimization. The methodology, implemented on the QuantConnect platform, aims to predict future price movements and optimize trading strategies. Specifically, it filters for highly liquid, top cap energy stocks to ensure stable and predictable performance while also accounting for broker payments. QuantConnect was selected because of its robust framework and to guarantee experimental reproducibility. The algorithm achieved a 31  return between June 1, 2023, and January 1, 2024, with a Sharpe ratio of 1.669, demonstrating its potential. The findings suggest significant improvements in trading strategy performance through the combined use of the HMM and neural networks. This study explores the architecture of the algorithm, data pre processing techniques, model training procedures, and performance evaluation, highlighting its practical applicability and effectiveness in real world trading environments. The full code and backtesting data are available under the MIT license.

Keywords :

Abstract :在定量金融领域，机器学习方法已成为阿尔法生成的关键。本文提出了一种开创性的方法，该方法独特地结合了隐马尔可夫模型（HMM）和神经网络，创建了一个与Black Litterman投资组合优化集成的双模型阿尔法生成系统。该方法在QuantConnect平台上实施，旨在预测未来的价格走势并优化交易策略。具体来说，它过滤了高流动性、高市值的能源股，以确保稳定和可预测的业绩，同时也考虑了经纪人的付款。选择QuantConnect是因为其强大的框架并保证了实验的可重复性。该算法在2023年6月1日至2024年1月1日期间实现了31的回报，夏普比率为1.669，证明了其潜力。研究结果表明，通过结合使用HMM和神经网络，交易策略绩效得到了显著改善。本研究探讨了算法的架构、数据预处理技术、模型训练程序和性能评估，突出了其在现实世界交易环境中的实际适用性和有效性。完整的代码和回溯测试数据在MIT许可证下可用。

Keywords :

### 

\[6\] Design and Optimization of Big Data and Machine Learning Based Risk Monitoring System in Financial Markets

标题:基于大数据和机器学习的金融市场风险监测系统的设计与优化

作者:Liyang Wang, Yu Cheng, Xingxin Gu, Zhizhong Wu

来源:ARXIV\_20240730

链接:https://arxiv.org/pdf/2407.19352

Abstract : With the increasing complexity of financial markets and rapid growth in data volume, traditional risk monitoring methods no longer suffice for modern financial institutions. This paper designs and optimizes a risk monitoring system based on big data and machine learning. By constructing a four layer architecture, it effectively integrates large scale financial data and advanced machine learning algorithms. Key technologies employed in the system include Long Short Term Memory (LSTM) networks, Random Forest, Gradient Boosting Trees, and real time data processing platform Apache Flink, ensuring the real time and accurate nature of risk monitoring. Research findings demonstrate that the system significantly enhances efficiency and accuracy in risk management, particularly excelling in identifying and warning against market crash risks.

Keywords :

Abstract :随着金融市场日益复杂和数据量的快速增长，传统的风险监测方法已不再适用于现代金融机构。本文设计并优化了一个基于大数据和机器学习的风险监控系统。通过构建四层架构，它有效地集成了大规模金融数据和先进的机器学习算法。该系统采用的关键技术包括长短期记忆（LSTM）网络、随机森林、梯度提升树和实时数据处理平台Apache Flink，确保了风险监测的实时性和准确性。研究结果表明，该系统显著提高了风险管理的效率和准确性，特别是在识别和预警市场崩盘风险方面表现出色。

Keywords :

### 

\[7\] PO QA

标题:波卡

作者:Kamila Zaman, Alberto Marchisio, Muhammad Kashif, Muhammad Shafique

来源:ARXIV\_20240730

链接:https://arxiv.org/pdf/2407.19857

Abstract : Portfolio Optimization (PO) is a financial problem aiming to maximize the net gains while minimizing the risks in a given investment portfolio. The novelty of Quantum algorithms lies in their acclaimed potential and capability to solve complex problems given the underlying Quantum Computing (QC) infrastructure. Utilizing QC s applicable strengths to the finance industry s problems, such as PO, allows us to solve these problems using quantum based algorithms such as Variational Quantum Eigensolver (VQE) and Quantum Approximate Optimization Algorithm (QAOA). While the Quantum potential for finance is highly impactful, the architecture and composition of the quantum circuits have not yet been properly defined as robust financial frameworks algorithms as state of the art in present literature for research and design development purposes. In this work, we propose a novel scalable framework, denoted PO QA, to systematically investigate the variation of quantum parameters (such as rotation blocks, repetitions, and entanglement types) to observe their subtle effect on the overall performance. In our paper, the performance is measured and dictated by convergence to similar ground state energy values for resultant optimal solutions by each algorithm variation set for QAOA and VQE to the exact eigensolver (classical solution). Our results provide effective insights into comprehending PO from the lens of Quantum Machine Learning in terms of convergence to the classical solution, which is used as a benchmark. This study paves the way for identifying efficient configurations of quantum circuits for solving PO and unveiling their inherent inter relationships.

Keywords :

Abstract :投资组合优化（PO）是一个财务问题，旨在最大化给定投资组合的净收益，同时最小化风险。量子算法的新颖之处在于，在给定底层量子计算（QC）基础设施的情况下，它们具有解决复杂问题的广受好评的潜力和能力。利用QC在金融行业问题（如PO）中的适用优势，我们可以使用基于量子的算法（如变分量子本征求解器（VQE）和量子近似优化算法（QAOA））来解决这些问题。虽然量子在金融领域的潜力具有很大的影响力，但量子电路的架构和组成尚未被正确定义为稳健的金融框架算法，这是当前文献中用于研究和设计开发目的的最新技术。在这项工作中，我们提出了一种新的可扩展框架，称为PO QA，用于系统地研究量子参数（如旋转块、重复和纠缠类型）的变化，以观察它们对整体性能的微妙影响。在我们的论文中，性能是通过QAOA和VQE的每个算法变体集向精确特征求解器（经典解）收敛到类似的基态能量值来衡量和指示的。我们的研究结果为从量子机器学习的角度理解PO提供了有效的见解，即收敛到经典解，经典解被用作基准。这项研究为识别解决PO的量子电路的有效配置和揭示其内在的相互关系铺平了道路。

Keywords :