# 量化前沿速递：机器学习\[20260510\]

shameless 量化前沿速递 2026-05-11 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489519&idx=4&sn=6f84008c87fcc4c90f9961d1a62afda7&chksm=c342531cff003477273d13273f03fd21a2ff3e68c86a18fb6d04efaf13c57c94ee4a846eaef6#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489519&idx=4&sn=6f84008c87fcc4c90f9961d1a62afda7&chksm=c342531cff003477273d13273f03fd21a2ff3e68c86a18fb6d04efaf13c57c94ee4a846eaef6#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] ESG as Priced Crash Insurance

ESG作为定价崩溃保险

来源:ARXIV\_20260507

\[2\] Learning Time Inhomogeneous Markov Dynamics in Financial Time Series via Neural Parameterization

通过神经参数化学习金融时间序列中的时间非齐次马尔可夫动力学

来源:ARXIV\_20260507

\[3\] A Geometry Aware Residual Correction of Hagan s SABR Implied Volatility Formula

Hagan SABR隐含波动率公式的几何感知残差校正

来源:ARXIV\_20260508

\[4\] Multi Dimensional Behavioral Evaluation of Agentic Stock Prediction Systems Using LLM Judges with Closed Loop Reinforcement Learning Feedback

基于闭环强化学习反馈的LLM判断的代理股票预测系统多维行为评价

来源:ARXIV\_20260508

\[5\] INEUS

INEUS

来源:ARXIV\_20260508

\[6\] Neural Actuarial Longevity Forecasting

神经精算寿命预测

来源:ARXIV\_20260508

\[7\] SNAPO

斯内普

来源:ARXIV\_20260508

### 

\[1\] ESG as Priced Crash Insurance

标题:ESG作为定价崩溃保险

作者:Jiayu Yi, Minxuan Hu, Wenxi Sun, Ziheng Chen

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04479

Abstract : This research establishes ESG as a state dependent insurance mechanism against equity crashes by addressing the decoupling of unconditional alpha from tail risk resilience. By validating market stress regimes as distinct economic states through a drawdown based truncation rule, the study demonstrates that high ESG ratings materially reduce the incidence of discrete crash events during systemic drawdowns. To address the selection bias and high dimensional confounding inherent in traditional linear frameworks, we implement Double Machine Learning as a structural deconfounding layer. Unlike simple predictive modeling, the Double Machine Learning framework utilizes machine learning to handle complex nuisance parameters, allowing us to isolate the asymmetric treatment effects of ESG across different market states. Distributional analysis reveals the underlying mechanism as ESG specifically attenuates the severity of realized tail losses at the most adverse quantiles instead of shifting the entire return distribution. Confirmed by structural estimates, this protection functions as priced insurance that incurs performance drags during stable periods while providing critical resilience when tail risks are most acute.

Keywords : 

Abstract :本研究通过解决无条件阿尔法与尾部风险弹性的脱钩问题，将ESG确立为一种针对股票崩盘的国家依赖保险机制。通过基于缩减的截断规则将市场压力制度验证为不同的经济状态，该研究表明，高ESG评级大大降低了系统性缩减期间离散崩溃事件的发生率。为了解决传统线性框架中固有的选择偏差和高维混淆问题，我们将双机器学习作为一个结构解卷积层来实现。与简单的预测建模不同，双机器学习框架利用机器学习来处理复杂的干扰参数，使我们能够隔离ESG在不同市场状态下的不对称处理效应。分布分析揭示了潜在的机制，因为ESG在最不利的分位数上专门减弱了已实现尾部损失的严重程度，而不是改变整个回报分布。经结构性估计证实，这种保护起到了定价保险的作用，在稳定时期会带来业绩拖累，而在尾部风险最严重时则提供关键的弹性。

Keywords :

### 

\[2\] Learning Time Inhomogeneous Markov Dynamics in Financial Time Series via Neural Parameterization

标题:通过神经参数化学习金融时间序列中的时间非齐次马尔可夫动力学

作者:Jan Rovirosa, Jesse Schmolze

来源:ARXIV\_20260507

链接:https://arxiv.org/pdf/2605.04690

Abstract : Modeling the dynamics of non stationary stochastic systems requires balancing the representational power of deep learning with the mathematical transparency of classical models. While classical Markov transition operators provide explicit, theoretically grounded rules for system evolution, their empirical estimation collapses due to severe data sparsity when applied to high resolution, high noise environments. We explore this statistical barrier using financial time series as a canonical, real world testbed. To overcome the degeneracy of empirical counting, we introduce a framework that utilizes neural networks strictly as parameterization engines to generate explicit, time varying Markov transition matrices. By constraining the neural network to output its predictions as a formal stochastic operator, we maintain complete structural interpretability. We demonstrate that these learned operators successfully capture complex regime shifts  the state conditioned model achieves mean row heterogeneity   bar  rho    0.0073  while the state free ablation collapses to exactly zero, and operator row entropy correlates with realized variance at  r    0.62  ( p  approx 10   251  ), revealing that high volatility regimes homogenize transition dynamics rather than diversify them. Furthermore, rather than enforcing the Chapman Kolmogorov equations as a rigid structural requirement, we repurpose them as a localized diagnostic tool to pinpoint specific temporal windows where first order memory assumptions break down. Ultimately, this framework demonstrates how neural networks can be constrained to make rigorous, classical operator analysis viable for complex real world time series.

Keywords : 

Abstract :对非平稳随机系统的动力学建模需要平衡深度学习的表征能力和经典模型的数学透明度。虽然经典的马尔可夫转移算子为系统演化提供了明确的、有理论依据的规则，但当应用于高分辨率、高噪声环境时，由于严重的数据稀疏性，它们的经验估计会崩溃。我们使用金融时间序列作为规范的现实世界测试平台来探索这一统计障碍。为了克服经验计数的退化，我们引入了一种框架，该框架严格利用神经网络作为参数化引擎来生成显式的时变马尔可夫转移矩阵。通过约束神经网络将其预测作为形式随机算子输出，我们保持了完全的结构可解释性。我们证明，这些学习到的算子成功地捕捉到了复杂的制度变迁——状态条件模型实现了平均行异质性棒rho 0.0073，而无状态消融则完全崩溃为零，算子行熵与r 0.62的实现方差相关（p约为10251），这表明高波动性制度使过渡动态均匀化，而不是多样化。此外，我们没有将Chapman-Kolmogorov方程强制作为刚性结构要求，而是将其重新用作局部诊断工具，以确定一阶记忆假设失效的特定时间窗口。最终，该框架展示了如何约束神经网络，使严格的经典算子分析适用于复杂的现实世界时间序列。

Keywords :

### 

\[3\] A Geometry Aware Residual Correction of Hagan s SABR Implied Volatility Formula

标题:Hagan SABR隐含波动率公式的几何感知残差校正

作者:Adil Reghai, Lama Tarsissi, Gérard Biau, Alex Lipton

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06604

Abstract : This paper proposes a hybrid methodology to improve the approximation of SABR (Stochastic Alpha Beta Rho) implied volatility by combining analytical structure with machine learning. The approach augments the neural network input representation with geometric features derived from the stochastic differential equations of the SABR model. Unlike approaches that fully replace analytical formulas with black box models, the proposed framework preserves the analytical backbone of the model. The hybridization operates along two complementary dimensions. First, geometry aware variables reflecting intrinsic properties of the SABR dynamics are used as structured inputs to the network. Second, the neural network is trained to learn the residual error relative to Hagan s closed form approximation rather than implied volatility directly. The resulting model acts as a structured residual correction to the analytical formula, retaining interpretability while capturing higher order effects that are not included in the asymptotic expansion. Numerical experiments conducted over realistic parameter domains, as well as stressed environments, show that the method improves accuracy and robustness compared with both analytical approximations and standard neural network approaches. Because the correction remains lightweight and structurally consistent with the underlying model, the framework is well suited for real time pricing and calibration in practical trading environments.

Keywords : 

Abstract :本文提出了一种混合方法，通过将分析结构与机器学习相结合来提高SABR（随机阿尔法贝塔Rho）隐含波动率的近似值。该方法利用从SABR模型的随机微分方程中导出的几何特征来增强神经网络输入表示。与用黑盒模型完全取代分析公式的方法不同，所提出的框架保留了模型的分析支柱。杂交沿着两个互补的维度进行。首先，将反映SABR动力学内在特性的几何感知变量用作网络的结构化输入。其次，训练神经网络以学习相对于Hagan闭式近似的残差，而不是直接学习隐含波动率。由此产生的模型充当了对分析公式的结构化残差校正，在保留可解释性的同时捕获了渐近展开中未包含的高阶效应。在真实参数域以及压力环境中进行的数值实验表明，与解析近似和标准神经网络方法相比，该方法提高了准确性和鲁棒性。由于修正仍然很轻，并且在结构上与基础模型一致，因此该框架非常适合在实际交易环境中进行实时定价和校准。

Keywords :

### 

\[4\] Multi Dimensional Behavioral Evaluation of Agentic Stock Prediction Systems Using LLM Judges with Closed Loop Reinforcement Learning Feedback

标题:基于闭环强化学习反馈的LLM判断的代理股票预测系统多维行为评价

作者:Mohammad Al Ridhawi, Mahtab Haj Ali, Hussein Al Osman

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.05739

Abstract : Agentic stock prediction systems make sequences of interdependent decisions (regime detection, pathway routing, reinforcement learning control) whose individual quality is hidden by aggregate metrics such as mean absolute percentage error (MAPE) or directional accuracy. We present a behavioral evaluation framework that addresses this gap. Behavioral traces logged at every autonomous decision point are grouped into five day episodes and scored along six domain specific dimensions (regime detection, routing, adaptation, risk calibration, strategy coherence, error recovery) by an ensemble of three large language model (LLM) judges (GPT 5.4, Claude 4.6 Opus, Gemini 3.1 Pro). Perturbation based validation on 420 episodes yields targeted score drops of   1.6  to   2.4  on intended dimensions versus an average of   0.32  on the remaining five, with cross model agreement up to Krippendorff s   alpha   0.85 . The composite behavioral score, used here only for cross episode reporting, correlates at   rho   0.72  with realized 20 day Sharpe ratio from offline backtesting. Closing the loop, the framework converts deficient per dimension scores into a credit assigned penalty term added to the Soft Actor Critic (SAC) reward. Three short fine tuning cycles, all confined to the validation period, produce on the held out 2017 2025 test period a one day MAPE reduction from 0.61  to 0.54  (an 11.5  relative reduction   p 0.001 , Cohen s  d 0.31 ), a directional accuracy increase from 71  to 74 , and an 18  Sharpe ratio improvement (95  bootstrap CI  8.2 , 27.4  ), with gains concentrated in high volatility episodes where the original system was most behaviorally deficient. Results are from offline backtesting and do not address effects specific to live deployment.

Keywords : 

Abstract :代理股票预测系统做出一系列相互依存的决策（状态检测、路径选择、强化学习控制），其个体质量被平均绝对百分比误差（MAPE）或方向精度等聚合指标所掩盖。我们提出了一个行为评估框架来解决这一差距。在每个自主决策点记录的行为痕迹被分为五天的事件，并由三名大型语言模型（LLM）法官（GPT 5.4、Claude 4.6 Opus、Gemini 3.1 Pro）组成的团队沿六个领域特定维度（制度检测、路由、适应、风险校准、策略连贯性、错误恢复）进行评分。对420个事件进行基于扰动的验证，在预期维度上的目标得分下降1.6至2.4，而在其余五个维度上的平均得分下降0.32，跨模型一致性高达Krippendorffα0.85。这里仅用于跨发作报告的复合行为评分与离线回溯测试的20天夏普比率相关，相关系数为0.72。在循环结束时，该框架将每个维度的不足分数转换为添加到软演员评论家（SAC）奖励中的信用分配惩罚项。三个短的微调周期，均限于验证期，在2017-2025年的测试期内，MAPE从0.61降低到0.54（相对降低11.5，p 0.001，Cohen s d 0.31），方向精度从71提高到74，夏普比率提高了18（95自举CI 8.2，27.4），收益集中在原始系统行为缺陷最严重的高波动性事件中。结果来自离线回溯测试，不涉及实时部署的特定影响。

Keywords :

### 

\[5\] INEUS

标题:INEUS

作者:Jean-Loup Dupret, Davide Gallon, Patrick Cheridito

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06281

Abstract : In this paper, we introduce INEUS, a meshfree iterative neural solver for partial integro differential equations (PIDEs). The method replaces the explicit evaluation of nonlocal jump integrals with single jump sampling and reformulates PIDE solving as a sequence of recursive regression problems. Like Physics Informed Neural Networks (PINNs), INEUS learns global solutions over the entire space time domain, yet it offers a more efficient treatment of nonlocal terms and avoids the computationally expensive differentiation of full PIDE residuals. These features make INEUS particularly well suited for high dimensional PDEs and PIDEs. Supported by a contraction based convergence proof for linear PIDEs, our numerical experiments show that INEUS delivers accurate and scalable solutions for various high dimensional linear and nonlinear examples.

Keywords : 

Abstract :本文介绍了求解偏积分微分方程（PIDE）的无网格迭代神经求解器INEUS。该方法用单跳采样代替了非局部跳跃积分的显式计算，并将PIDE求解重新表述为一系列递归回归问题。与物理知情神经网络（PINN）一样，INEUS在整个时空域上学习全局解，但它提供了一种更有效的非局部项处理方法，并避免了计算成本高昂的全PIDE残差微分。这些特性使INEUS特别适合高维PDE和PIDE。在基于收缩的线性PIDE收敛证明的支持下，我们的数值实验表明，INEUS为各种高维线性和非线性示例提供了准确和可扩展的解决方案。

Keywords :

### 

\[6\] Neural Actuarial Longevity Forecasting

标题:神经精算寿命预测

作者:Davide Rindori

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06438

Abstract : Traditional multi population models, such as the Li Lee framework, rely on the assumption of mean reverting country specific deviations. However, recent data from high longevity clusters suggest a systemic break in this paradigm. We identify a stationarity paradox where mortality residuals in countries like Sweden and West Germany exhibit persistent unit roots, leading to a systematic mispricing of longevity risk in linear models. To address these non linearities, we propose Hybrid Lift, a neural actuarial framework that combines Hierarchical LSTM networks with a Mean Bias Correction (MBC) anchoring mechanism. Positioned as a governance friendly model challenger rather than a replacement of classical approaches, the framework exhibits selective superiority on out of sample validation (2012 2020)  it outperforms Li Lee by 17.40  in Sweden and 12.57  in West Germany, while remaining comparable for near linear regimes such as Switzerland and Japan. We complement the predictive model with an integrated governance suite comprising SHAP based cross country influence mapping, a dual uncertainty framework for regulatory capital calibration (Swiss ES 99.0  of  1.153 years), and a reverse stress test identifying the critical shock threshold for solvency buffer exhaustion. This research provides evidence that neural networks, when properly anchored by actuarial principles, can serve as effective model challengers for longevity risk management under the SST and Solvency II standards.

Keywords : 

Abstract :传统的多人口模型，如李-李框架，依赖于均值回归国家特定偏差的假设。然而，高寿命集群的最新数据表明，这一范式发生了系统性突破。我们发现了一个平稳性悖论，即瑞典和西德等国家的死亡率残差表现出持续的单位根，导致线性模型中寿命风险的系统性错误定价。为了解决这些非线性问题，我们提出了混合提升，这是一种神经精算框架，将分层LSTM网络与平均偏差校正（MBC）锚定机制相结合。该框架被定位为治理友好型模型挑战者，而不是传统方法的替代品，在样本外验证方面表现出选择性优势（2012-2020）——在瑞典和西德分别比李高出17.40和12.57，同时在瑞士和日本等近线性制度下保持可比性。我们用一个综合治理套件来补充预测模型，该套件包括基于SHAP的跨国影响映射、监管资本校准的双重不确定性框架（1.153年的瑞士ES 99.0）和识别偿付能力缓冲耗尽的关键冲击阈值的反向压力测试。这项研究提供了证据，表明神经网络在精算原理的正确锚定下，可以作为SST和偿付能力II标准下长寿风险管理的有效模型挑战者。

Keywords :

### 

\[7\] SNAPO

标题:斯内普

作者:Dmitri Goloubentsev, Natalija Karpichina

来源:ARXIV\_20260508

链接:https://arxiv.org/pdf/2605.06570

Abstract : Many real world problems require sequential decisions under uncertainty  when to inject or withdraw gas from storage, how to rebalance a pension portfolio each month, what temperature profile to run through a pharmaceutical reactor chain. Dynamic programming solves small instances exactly but scales exponentially in state dimensions. Black box reinforcement learning handles high dimensional states but trains slowly and produces no sensitivities.We introduce SNAPO (Smooth Neural Adjoint Policy Optimization), a framework that embeds a neural policy inside a known, differentiable simulator, replaces hard constraints with smooth approximations, and computes exact gradients of the objective with respect to all policy parameters and all inputs in a single adjoint pass.We demonstrate SNAPO on three domains  natural gas storage (training in under a minute, 365 forward curve sensitivities at no additional cost per sensitivity), pension fund asset liability management (6.5x 200x sensitivity speedup over bump and revalue, scaling with the number of risk factors), and pharmaceutical manufacturing (cross unit sensitivities through a 4 unit process chain, with 20 ICH Q8 regulatory sensitivities from 5 adjoint passes in 74.5 milliseconds).All sensitivities are produced by the same backward pass that trains the policy, at a cost proportional to one reverse pass regardless of how many sensitivities are computed.

Keywords : 

Abstract :许多现实世界的问题需要在不确定的情况下做出连续的决定——何时注入或从储存中提取天然气，如何每月重新平衡养老金组合，在制药反应器链中运行什么温度曲线。动态规划精确地解决了小实例，但在状态维度上呈指数级扩展。黑盒强化学习处理高维状态，但训练缓慢，不产生灵敏度。我们介绍了SNAPO（平滑神经伴随策略优化），这是一个将神经策略嵌入已知可微模拟器中的框架，用平滑近似代替硬约束，并在单个伴随过程中计算目标相对于所有策略参数和所有输入的精确梯度。所有敏感度都是由训练策略的同一反向传递产生的，其成本与一次反向传递成正比，而不管计算了多少敏感度。

Keywords :