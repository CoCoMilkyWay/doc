# arxiv量化文献汇总翻译 20210823-20210825

Shame1ess 量化前沿速递 2021-08-25 22:39

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484418&idx=2&sn=c94eec18158c22f37aa6e0db944f7ce0&chksm=c37190b858fca336eb0120fc4fbf23ea671431fabd95ce73650c5e956206870fb7ad136ea7f8#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484418&idx=2&sn=c94eec18158c22f37aa6e0db944f7ce0&chksm=c37190b858fca336eb0120fc4fbf23ea671431fabd95ce73650c5e956206870fb7ad136ea7f8#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] On the Efficiency of 5(4) RK Embedded Pairs with High Order Compact Scheme and Robin Boundary Condition for Options Valuation

高阶紧致格式和Robin边界条件下5（4）RK嵌入对期权定价的有效性

\[2\] Robust Risk Aware Reinforcement Learning

鲁棒风险感知强化学习

\[3\] Deep Signature FBSDE Algorithm

深度签名FBSDE算法

\[4\] The changing dynamics of HIV AIDS during the Covid 19 pandemic in the Rohingya refugee camps in Bangladesh a call for action

孟加拉国罗兴亚难民营在新冠病毒19型大流行期间艾滋病毒/艾滋病不断变化的动态呼吁采取行动

\[5\] Fragmentation, Price Formation, and Cross Impact in Bitcoin Markets

比特币市场的碎片化、价格形成和交叉影响

\[6\] Community Detection in Cryptocurrencies with Potential Applications to Portfolio Diversification

加密货币中的社区检测及其在投资组合多样化中的潜在应用

\[7\] Welfare Effects of the Labor Income Tax Changes on Married Couples

劳动所得税变动对已婚夫妇的福利影响

\[8\] Continuous time Portfolio Optimization for Absolute Return Funds

绝对收益基金的连续时间投资组合优化

\[9\] Previs o dos pre os de abertura, m nima e m xima de ndices de mercados financeiros usando a associa o de redes neurais LSTM

使用LSTM神经网络关联预测金融市场的开盘价、m nima和m xime数量

\[10\] Minimizing ruin probability under dependencies for insurance pricing

相依条件下保险定价的最小破产概率

\[11\] Gender Differences in the Cost of Corrections in Group Work

小组工作中矫正费用的性别差异

\[12\] Effect of Share Capital on Financial Growth of Non Financial Firms Listed at the Nairobi Securities Exchange

股本对内罗毕证券交易所上市非金融公司财务增长的影响

\[13\] Adaptive Gradient Descent Methods for Computing Implied Volatility

计算隐含波动率的自适应梯度下降方法

\[14\] Multivariate self exciting jump processes with applications to financial data

多元自激跳跃过程及其在金融数据中的应用

\[15\] Assessment of waterfront office redevelopment plan on optimal building energy demand and rooftop photovoltaics for urban decarbonization

评估滨水办公室重建计划对最佳建筑能源需求和屋顶光伏城市脱碳的影响

\[16\] Sensitivity of Optimal Retirement Problem to Liquidity Constraints

最优退休问题对流动性约束的敏感性

\[17\] Deep Sequence Modeling

深层序建模

\[18\] Bermudan option pricing by quantum amplitude estimation and Chebyshev interpolation

基于量子振幅估计和切比雪夫插值的百慕大期权定价

## 

\[1\] On the Efficiency of 5(4) RK Embedded Pairs with High Order Compact Scheme and Robin Boundary Condition for Options Valuation

标题 : 高阶紧致格式和Robin边界条件下5（4）RK嵌入对期权定价的有效性

作者 : Chinonso Nwankwo, Weizhong Dai , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2108.10418

说明 : -

Abstract : When solving the American options with or without dividends, numerical methods often obtain lower convergence rates if further treatment is not implemented even using high order schemes. In this article, we present a fast and explicit fourth order compact scheme for solving the free boundary options. In particular, the early exercise features with the asset option and option sensitivity are computed based on a coupled of nonlinear PDEs with fixed boundaries for which a high order analytical approximation is obtained. Furthermore, we implement a new treatment at the left boundary by introducing a third order Robin boundary condition. Rather than computing the optimal exercise boundary from the analytical approximation, we simply obtain it from the asset option based on the linear relationship at the left boundary. As such, a high order convergence rate can be achieved. We validate by examples that the improvement at the left boundary yields a fourth order convergence rate without further implementation of mesh refinement, Rannacher time stepping, and or smoothing of the initial condition. Furthermore, we extensively compare, the performance of our present method with several 5(4) Runge Kutta pairs and observe that Dormand and Prince and Bogacki and Shampine 5(4) pairs are faster and provide more accurate numerical solutions. Based on numerical results and comparison with other existing methods, we can validate that the present method is very fast and provides more accurate solutions with very coarse grids.

摘要 : 在求解有红利或无红利的美式期权时，如果不进行进一步处理，即使使用高阶格式，数值方法的收敛速度也往往较低。在这篇文章中，我们提出了一个快速明确的四阶紧致格式来求解自由边界期权。特别是，基于具有固定边界的耦合非线性偏微分方程，计算资产期权和期权敏感性的早期行使特征，获得高阶解析近似。此外，通过引入三阶Robin边界条件，我们在左边界实现了一种新的处理方法。我们不是通过解析近似计算最优行使边界，而是根据左边界的线性关系从资产期权中获得。因此，可以实现高阶收敛速度。我们通过实例验证了左边界的改进在不进一步实施网格细化、Rannacher时间步进和/或初始条件平滑的情况下产生了四阶收敛速度。此外，我们广泛比较了我们目前的方法与几个5（4）Runge-Kutta对的性能，并观察到Dormand和Prince、Bogacki和Shampine 5（4）对更快，提供更精确的数值解。基于数值结果并与现有的其他方法进行比较，我们可以验证该方法是非常快速的，并且在非常粗的网格上提供了更精确的解。

## 

\[2\] Robust Risk Aware Reinforcement Learning

标题 : 鲁棒风险感知强化学习

作者 : Sebastian Jaimungal, Silvana Pesenti, Ye Sheng Wang, Hariom Tatsat , 类别 ：Machine Learning (cs.LG)

链接 : https://arxiv.org/pdf/2108.10403

说明 : Comments: 12 pages, 5 figures

Abstract : We present a reinforcement learning (RL) approach for robust optimisation of risk aware performance criteria. To allow agents to express a wide variety of risk reward profiles, we assess the value of a policy using rank dependent expected utility (RDEU). RDEU allows the agent to seek gains, while simultaneously protecting themselves against downside events. To robustify optimal policies against model uncertainty, we assess a policy not by its distribution, but rather, by the worst possible distribution that lies within a Wasserstein ball around it. Thus, our problem formulation may be viewed as an actor choosing a policy (the outer problem), and the adversary then acting to worsen the performance of that strategy (the inner problem). We develop explicit policy gradient formulae for the inner and outer problems, and show its efficacy on three prototypical financial problems robust portfolio allocation, optimising a benchmark, and statistical arbitrage

摘要 : 我们提出了一种强化学习（RL）方法，用于风险感知性能标准的稳健优化。为了让代理能够表达各种各样的风险-回报曲线，我们使用秩相关期望效用（RDEU）评估策略的价值。RDEU允许代理寻求收益，同时保护自己免受不利事件的影响。为了对模型不确定性的最优策略进行鲁棒性评估，我们不是通过其分布来评估策略，而是通过位于其周围的Wasserstein球中的最差可能分布来评估策略。因此，我们的问题表述可能被视为一个行动者选择了一项政策（外部问题），而对手则采取行动恶化该战略的绩效（内部问题）。我们为内部和外部问题建立了明确的政策梯度公式，并在三个典型金融问题上证明了其有效性：稳健投资组合配置、优化基准和统计套利

## 

\[3\] Deep Signature FBSDE Algorithm

标题 : 深度签名FBSDE算法

作者 : Qi Feng, Man Luo, Zhaoyu Zhang , 类别 ：Machine Learning (cs.LG)

链接 : https://arxiv.org/pdf/2108.10504

说明 : -

Abstract : We propose a deep signature log signature FBSDE algorithm to solve forward backward stochastic differential equations (FBSDEs) with state and path dependent features. By incorporating the deep signature log signature transformation into the recurrent neural network (RNN) model, our algorithm shortens the training time, improves the accuracy, and extends the time horizon comparing to methods in the existing literature. Moreover, our algorithms can be applied to a wide range of applications such as state and path dependent option pricing involving high frequency data, model ambiguity, and stochastic games, which are linked to parabolic partial differential equations (PDEs), and path dependent PDEs (PPDEs). Lastly, we also derive the convergence analysis of the deep signature log signature FBSDE algorithm.

摘要 : 我们提出了一种深度签名日志签名FBSDE算法来求解具有状态和路径依赖特征的正倒向随机微分方程（FBSDE）。与现有文献中的方法相比，通过将深度签名-日志签名转换引入到递归神经网络（RNN）模型中，我们的算法缩短了训练时间，提高了精度，并扩展了时间范围。此外，我们的算法可以应用于广泛的应用，如涉及高频数据的状态和路径相关期权定价、模型模糊性和随机博弈，这些都与抛物偏微分方程（PDE）和路径相关PDE（PPDE）有关。最后，我们还推导了深度签名日志签名FBSDE算法的收敛性分析。

## 

\[4\] The changing dynamics of HIV AIDS during the Covid 19 pandemic in the Rohingya refugee camps in Bangladesh a call for action

标题 : 孟加拉国罗兴亚难民营在新冠病毒19型大流行期间艾滋病毒/艾滋病不断变化的动态呼吁采取行动

作者 : Muhammad Anwar Hossain, Iryna Zablotska-Manos , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2108.09690

说明 : Comments: 10 pages, no figure

Abstract : COVID 19 pandemic has affected each and every country s health service and plunged refugees into the most desperate conditions. The plight of Rohingya refugees is among the harshest. It has severely affected their existing HIV STI prevention and management services and further increased the risk of violence and onward HIV transmission within the camps. In this commentary, we discuss the context and the changing dynamics of HIV AIDS during COVID 19 among the Rohingya refugee community in Bangladesh. What we currently observe is the worst crisis in the Rohingya refugee camps thus far. Firstly, because of being displaced, Rohingya refugees have increased vulnerability to HIV, as well as to STIs and other poor health outcomes. Secondly, for the same reason, they have inadequate access to HIV testing treatment and care. Not only because of their refugee status but also because of the poor capacity of the host country to provide services. Thirdly, a host of complex economic, socio cultural and behavioural factors exacerbate their dire situation with access to HIV testing, treatment and care. And finally, the advent of the COVID 19 pandemic has changed priorities in all societies, including the refugee camps. In the context of the unfolding COVID 19 crisis, more emphasis is placed on COVID 19 rather than other health issues, which exacerbates the dire situation with HIV detection, management, and prevention among Rohingya refugees. Despite the common crisis experienced by most countries around the world, the international community has an obligation to work together to improve the life, livelihood, and health of those who are most vulnerable. Rohingya refugees are among them.

摘要 : 新冠病毒19大流行影响了每个国家的卫生服务，使难民陷入最绝望的境地。罗兴亚难民的困境是最严峻的。这严重影响了他们现有的艾滋病毒性传播感染预防和管理服务，进一步增加了难民营内暴力和艾滋病毒进一步传播的风险。在这篇评论中，我们讨论了孟加拉国罗兴亚难民社区在新冠病毒19型期间艾滋病毒/艾滋病的背景和变化动态。我们目前观察到的是罗兴亚难民营迄今为止最严重的危机。首先，由于流离失所，罗兴亚难民更容易感染艾滋病毒、性传播感染和其他不良健康结果。第二，出于同样的原因，他们无法充分获得艾滋病毒检测治疗和护理。不仅因为他们的难民地位，而且因为东道国提供服务的能力差。第三，一系列复杂的经济、社会文化和行为因素加剧了他们在获得艾滋病毒检测、治疗和护理方面的悲惨处境。最后，新冠疫情的出现改变了包括难民营在内的所有社会的优先事项。在新冠病毒19型危机不断蔓延的背景下，人们更加重视新冠病毒19型而不是其他健康问题，这加剧了罗兴亚难民中艾滋病毒检测、管理和预防的严峻形势。尽管世界上大多数国家都经历了共同的危机，但国际社会有义务共同努力改善最弱势群体的生活、生计和健康。罗兴亚难民就是其中之一。

## 

\[5\] Fragmentation, Price Formation, and Cross Impact in Bitcoin Markets

标题 : 比特币市场的碎片化、价格形成和交叉影响

作者 : Jakob Albers, Mihai Cucuringu, Sam Howison, Alexander Y. Shestopaloff , 类别 ：Trading and Market Microstructure (q-fin.TR)

链接 : https://arxiv.org/pdf/2108.09750

说明 : Comments: 62 pages, 34 figures, 24 tables

Abstract : In light of micro scale inefficiencies induced by the high degree of fragmentation of the Bitcoin trading landscape, we utilize a granular data set comprised of orderbook and trades data from the most liquid Bitcoin markets, in order to understand the price formation process at sub 1 second time scales. To achieve this goal, we construct a set of features that encapsulate relevant microstructural information over short lookback windows. These features are subsequently leveraged first to generate a leader lagger network that quantifies how markets impact one another, and then to train linear models capable of explaining between 10 and 37 of total variation in 500 ms future returns (depending on which market is the prediction target). The results are then compared with those of various PnL calculations that take trading realities, such as transaction costs, into account. The PnL calculations are based on natural textit taker strategies (meaning they employ market orders) that we associate to each model. Our findings emphasize the role of a market s fee regime in determining its propensity to being a leader or a lagger, as well as the profitability of our taker strategy. Taking our analysis further, we also derive a natural textit maker strategy (i.e., one that uses only passive limit orders), which, due to the difficulties associated with backtesting maker strategies, we test in a real world live trading experiment, in which we turned over 1.5 million USD in notional volume. Lending additional confidence to our models, and by extension to the features they are based on, the results indicate a significant improvement over a naive benchmark strategy, which we also deploy in a live trading environment with real capital, for the sake of comparison.

摘要 : 鉴于比特币交易格局的高度碎片化导致的微观层面的低效率，我们利用由订单簿和来自流动性最强的比特币市场的交易数据组成的粒度数据集，以了解亚1秒时间尺度下的价格形成过程。为了实现这一目标，我们构建了一组特性，这些特性封装了短回望窗口上的相关微观结构信息。随后利用这些特征，首先生成一个leader-lagger网络，量化市场如何相互影响，然后训练线性模型，该模型能够解释500毫秒未来回报的10到37之间的总变化（取决于预测目标市场）。然后将结果与考虑交易成本等交易现实的各种PnL计算结果进行比较。PnL计算基于我们与每个模型关联的自然文本接收者策略（意味着他们采用市场订单）。我们的研究结果强调了市场收费制度在决定其成为领先者或落后者的倾向方面的作用，以及我们的接受者策略的盈利能力。进一步分析后，我们还得出了一种天然的textit庄家策略（即仅使用被动限价单的策略），由于与回测庄家策略相关的困难，我们在真实世界的实时交易实验中进行了测试，在该实验中，我们的名义交易额超过150万美元。结果为我们的模型提供了额外的信心，并扩展了它们所基于的功能，结果表明，与简单的基准策略相比，该策略有了显著的改进。为了便于比较，我们还将其部署在具有真实资本的实时交易环境中。

## 

\[6\] Community Detection in Cryptocurrencies with Potential Applications to Portfolio Diversification

标题 : 加密货币中的社区检测及其在投资组合多样化中的潜在应用

作者 : J. Gavin, M. Crane , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2108.09763

说明 : Comments: 14 pages, 8 figures

Abstract : In this paper, the cross correlations of cryptocurrency returns are analysed. The paper examines one years worth of data for 146 cryptocurrencies from the period January 1 2019 to December 31 2019. The cross correlations of these returns are firstly analysed by comparing eigenvalues and eigenvector components of the cross correlation matrix C with Random Matrix Theory (RMT) assumptions. Results show that C deviates from these assumptions indicating that C contains genuine information about the correlations between the different cryptocurrencies. From here, Louvain community detection method is applied as a clustering mechanism and 15 community groupings are detected. Finally, PCA is completed on the standardised returns of each of these clusters to create a portfolio of cryptocurrencies for investment. This method selects a portfolio which contains a number of high value coins when compared back against their market ranking in the same year. In the interest of assessing continuity of the initial results, the method is also applied to a smaller dataset of the top 50 cryptocurrencies across three time periods of T 125 days, which produces similar results. The results obtained in this paper show that these methods could be useful for constructing a portfolio of optimally performing cryptocurrencies.

摘要 : 本文分析了加密货币收益率的相互关系。本文对2019年1月1日至2019年12月31日期间146种加密货币的一年期数据进行了检验。首先，通过将互相关矩阵C的特征值和特征向量分量与随机矩阵理论（RMT）假设进行比较，分析了这些收益的互相关。结果表明，C偏离了这些假设，表明C包含关于不同加密货币之间相关性的真实信息。在此基础上，采用Louvain社区检测方法作为聚类机制，检测出15个社区分组。最后，对每个集群的标准化回报进行PCA，以创建用于投资的加密货币组合。该方法选择的投资组合中包含大量高价值硬币，与同年的市场排名进行对比。为了评估初始结果的连续性，该方法还应用于T 125天三个时间段内的前50种加密货币的较小数据集，产生了类似的结果。本文的结果表明，这些方法对于构造性能最优的加密货币组合是有用的。

## 

\[7\] Welfare Effects of the Labor Income Tax Changes on Married Couples

标题 : 劳动所得税变动对已婚夫妇的福利影响

作者 : Egor Malkov , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2108.09981

说明 : Comments: 60 pages

Abstract : This paper develops a framework for assessing the welfare effects of labor income tax changes on married couples. I build a static model of couples labor supply that features both intensive and extensive margins and derive a tractable expression that delivers a transparent understanding of how labor supply responses, policy parameters, and income distribution affect the reform induced welfare gains. Using this formula, I conduct a comparative welfare analysis of four tax reforms implemented in the United States over the last four decades, namely the Tax Reform Act of 1986, the Omnibus Budget Reconciliation Act of 1993, the Economic Growth and Tax Relief Reconciliation Act of 2001, and the Tax Cuts and Jobs Act of 2017. I find that these reforms created welfare gains ranging from 0.16 to 0.62 percent of aggregate labor income. A sizable part of the gains is generated by the labor force participation responses of women. Despite three reforms resulted in aggregate welfare gains, I show that each reform created both winners and losers. Furthermore, I uncover two patterns in the relationship between welfare gains and couples labor income. In particular, the reforms of 1986 and 2017 display a monotonically increasing relationship, while the other two reforms demonstrate a U shaped pattern. Finally, I characterize the bias in welfare gains resulting from the assumption about a linear tax function. I consider a reform that changes tax progressivity and show that the linearization bias is given by the ratio between the tax progressivity parameter and the inverse elasticity of taxable income. Quantitatively, it means that linearization overestimates the welfare effects of the U.S. tax reforms by 3.6 18.1 .

摘要 : 本文开发了一个框架，用于评估劳动所得税变化对已婚夫妇的福利影响。我构建了一个以密集和广泛边际为特征的夫妻劳动供给静态模型，并推导出一个易于理解的表达式，该表达式提供了一个关于劳动供给反应、政策参数和收入分配如何影响改革诱导的福利收益的透明理解。利用这个公式，我对美国过去四十年实施的四项税收改革进行了福利比较分析，即1986年的税收改革法案、1993年的综合预算调节法案、2001年的经济增长和税收减免调节法案，我发现这些改革创造了占总劳动收入0.16%至0.62%的福利收益。很大一部分收益来自妇女的劳动力参与反应。尽管三项改革带来了总体福利收益，但我认为每项改革都会产生赢家和输家。此外，我还揭示了福利收益和夫妻劳动收入之间关系的两种模式。特别是，1986年和2017年的改革呈现出单调增长的关系，而其他两项改革则呈现出U型格局。最后，我描述了由线性税收函数假设产生的福利收益偏差。我认为一个改变税收累进性的改革表明，线性化偏倚是由税收累进性参数与应纳税所得额的逆弹性之比给出的。从数量上讲，这意味着线性化将美国税收改革的福利效应高估了3.6 18.1。

## 

\[8\] Continuous time Portfolio Optimization for Absolute Return Funds

标题 : 绝对收益基金的连续时间投资组合优化

作者 : Masashi Ieda , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2108.09985

说明 : -

Abstract : This paper investigates a continuous time portfolio optimization problem with the following features (i) a no short selling constraint (ii) a leverage constraint, that is, an upper limit for the sum of portfolio weights and (iii) a performance criterion based on the lower mean square error between the investor s wealth and a predetermined target wealth level. Since the target level is defined by a deterministic function independent of market indices, it corresponds to the criterion of absolute return funds. The model is formulated using the stochastic control framework with explicit boundary conditions. The corresponding Hamilton Jacobi Bellman equation is solved numerically using the kernel based collocation method. However, a straightforward implementation does not offer a stable and acceptable investment strategy thus, some techniques to address this shortcoming are proposed. By applying the proposed methodology, two numerical results are obtained one uses artificial data, and the other uses empirical data from Japanese organizations. There are two implications from the first result how to stabilize the numerical solution, and a technique to circumvent the plummeting achievement rate close to the terminal time. The second result implies that leverage is inevitable to achieve the target level in the setting discussed in this paper.

摘要 : 本文研究了具有以下特征的连续时间投资组合优化问题：（i）无卖空约束（ii）杠杆约束，即：，投资组合权重总和的上限和（iii）基于投资者财富和预定目标财富水平之间的较低均方误差的绩效标准。由于目标水平由独立于市场指数的确定函数定义，因此它对应于绝对回报基金的标准。该模型采用具有显式边界条件的随机控制框架。采用基于核的配置方法对相应的Hamilton-Jacobi-Bellman方程进行了数值求解。然而，一个简单的实现并不能提供一个稳定和可接受的投资策略，因此，提出了一些技术来解决这个缺点。通过应用所提出的方法，获得了两个数值结果，一个使用人工数据，另一个使用来自日本组织的经验数据。第一个结果有两个含义：如何稳定数值解，以及如何避免接近终点时间的成就率暴跌。第二个结果表明，在本文讨论的环境中，杠杆是实现目标水平的必然选择。

## 

\[9\] Previs o dos pre os de abertura, m nima e m xima de ndices de mercados financeiros usando a associa o de redes neurais LSTM

标题 : 使用LSTM神经网络关联预测金融市场的开盘价、m nima和m xime数量

作者 : Gabriel de Oliveira Guedes Nogueira, Marcel Otoboni de Lima , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2108.10065

说明 : Comments: in Portuguese

Abstract : In order to make good investment decisions, it is vitally important for an investor to know how to make good analysis of financial time series. Within this context, studies on the forecast of the values and trends of stock prices have become more relevant. Currently, there are different approaches to dealing with the task. The two main ones are the historical analysis of stock prices and technical indicators and the analysis of sentiments in news, blogs and tweets about the market. Some of the most used statistical and artificial intelligence techniques are genetic algorithms, Support Vector Machines (SVM) and different architectures of artificial neural networks. This work proposes the improvement of a model based on the association of three distinct LSTM neural networks, each acting in parallel to predict the opening, minimum and maximum prices of stock exchange indices on the day following the analysis. The dataset is composed of historical data from more than 10 indices from the world s largest stock exchanges. The results demonstrate that the model is able to predict trends and stock prices with reasonable accuracy.

摘要 : 为了做出良好的投资决策，投资者必须知道如何对金融时间序列进行良好的分析。在这一背景下，关于股票价格价值和趋势预测的研究变得更加重要。目前，有不同的方法来处理这项任务。两个主要方面是对股票价格和技术指标的历史分析，以及对新闻、博客和推特中有关市场的情绪分析。一些最常用的统计和人工智能技术是遗传算法、支持向量机（SVM）和不同结构的人工神经网络。这项工作提出了对一个模型的改进，该模型基于三个不同的LSTM神经网络的关联，每个神经网络并行作用，以预测分析后一天的股票交易所指数的开盘价、最低和最高价格。该数据集由世界最大证券交易所10多个指数的历史数据组成。结果表明，该模型能够以合理的精度预测趋势和股票价格。

## 

\[10\] Minimizing ruin probability under dependencies for insurance pricing

标题 : 相依条件下保险定价的最小破产概率

作者 : Ragnar Levy Gudmundarson, Manuel Guerra, Alexandra Bugalho de Moura , 类别 ：Risk Management (q-fin.RM)

链接 : https://arxiv.org/pdf/2108.10075

说明 : -

Abstract : In this work the ruin probability of the Lundberg risk process is used as a criterion for determining the optimal security loading of premia in the presence of price sensitive demand for insurance. Both single and aggregated claim processes are considered and the independent and the dependent cases are analyzed. For the single risk case, we show that the optimal loading does not depend on the initial reserve. In the multiple risk case we account for arbitrary dependency structures between different risks and for dependencies between the probabilities of a client acquiring policies for different risks. In this case, the optimal loadings depend on the initial reserve. In all cases the loadings minimizing the ruin probability do not coincide with the loadings maximizing the expected profit.

摘要 : 在这项工作中，Lundberg风险过程的破产概率被用作在存在价格敏感保险需求的情况下确定保费的最优安全负荷的准则。考虑了单个索赔过程和聚合索赔过程，分析了独立和相依索赔过程。对于单一风险情况，我们证明了最优负载不依赖于初始储备。在多风险情况下，我们考虑了不同风险之间的任意依赖结构，以及客户获取不同风险策略的概率之间的依赖关系。在这种情况下，最佳载荷取决于初始储备。在所有情况下，最小化破产概率的负荷与最大化期望利润的负荷并不一致。

## 

\[11\] Gender Differences in the Cost of Corrections in Group Work

标题 : 小组工作中矫正费用的性别差异

作者 : Yuki Takahashi , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2108.10109

说明 : Comments: This draft is still preliminary; future versions can differ substantially from this version

Abstract : Corrections among colleagues are an integral part of group work, but people may take corrections as personal criticism, especially corrections by women. I study whether people dislike collaborating with someone who corrects them and more so when that person is a woman. People, including those with high productivity, are less willing to collaborate with a person who has corrected them even if the correction improves group performance. Yet, people respond to corrections by women as negatively as by men. These findings suggest that although women do not face a higher hurdle, correcting colleagues is costly and reduces group efficiency.

摘要 : 同事之间的纠正是小组工作的一个组成部分，但人们可能会将纠正视为个人批评，尤其是女性的纠正。我研究人们是否不喜欢与纠正他们的人合作，尤其是当那个人是女性时。人们，包括生产率高的人，不太愿意与纠正他们的人合作，即使纠正提高了团队绩效。然而，人们对女性矫正的反应和男性一样消极。这些发现表明，尽管女性不会面临更高的障碍，但纠正同事的错误代价高昂，并会降低团队效率。

## 

\[12\] Effect of Share Capital on Financial Growth of Non Financial Firms Listed at the Nairobi Securities Exchange

标题 : 股本对内罗毕证券交易所上市非金融公司财务增长的影响

作者 : David Haritone Shikumo , 类别 ：General Finance (q-fin.GN)

链接 : https://arxiv.org/pdf/2108.10244

说明 : Comments: 20 pages. arXiv admin note: substantial text overlap with arXiv:2011.03339, arXiv:2010.12596

Abstract : Purpose A significant number of the non financial firms listed at the Nairobi Securities Exchange (NSE) have been experiencing declining financial performance which deters investors from investing in such firms. The lenders are also not willing to lend to such firms. As such, the firms struggle to raise funds for their operations. Prudent financing decisions can lead to financial growth of the firm. The purpose of this study is to assess the effect of Share capital on financial growth of Non financial firms listed at the Nairobi Securities Exchange. Financial firms were excluded because of their specific sector characteristics and stringent regulatory framework. The study is guided by Market Timing Theory and Theory of Growth of the Firm. Methodology Explanatory research design was adopted. The target population of the study comprised of 45 non financial firms listed at NSE for a period of ten years from 2008 to 2017. The study conducted both descriptive statistics analysis and panel data analysis. Findings The result indicates that, share capital explains 32.73 and 11.62 of variations in financial growth as measure by growth in earnings per share and growth in market capitalization respectively. Share capital positively and significantly influences financial growth as measured by both growth in earnings per share and growth in market capitalization. Implications The study recommends for the Non financial firms to utilize equity financing as a way of raising capital for major expansions, asset growth or acquisitions which may require heavy funding. In this way, firms will be assured of improved performance as well as high financial growth. The study also recommends for substantial firm financing through equity. Value Equity financing is important to any firm, if the proceeds are used to invest in projects which eventually bring growth to the firm.

摘要 : 目的内罗毕证券交易所（NSE）上市的大量非金融公司的财务业绩一直在下降，这阻碍了投资者对此类公司的投资。贷款人也不愿意向这些公司贷款。因此，这些公司很难为其运营筹集资金。谨慎的融资决策可以导致公司的财务增长。本研究的目的是评估股本对内罗毕证券交易所上市的非金融公司财务增长的影响。金融公司被排除在外，因为它们具有特定的行业特征和严格的监管框架。本研究以市场时机理论和企业成长理论为指导。方法采用解释性研究设计。本研究的目标人群包括45家在NSE上市的非金融公司，从2008年到2017年为期十年。本研究进行了描述性统计分析和面板数据分析。结果表明，以每股收益增长和市值增长衡量，股本分别解释了32.73和11.62的财务增长变化。通过每股收益的增长和市值的增长来衡量，股本对财务增长产生积极而显著的影响。这项研究建议非金融企业利用股权融资作为筹集资本的方式，用于可能需要大量资金的重大扩张、资产增长或收购。通过这种方式，企业将获得更高的绩效和更高的财务增长。该研究还建议企业通过股权进行大量融资。价值股权融资对于任何公司来说都很重要，如果收益被用于投资于最终为公司带来增长的项目。

## 

\[13\] Adaptive Gradient Descent Methods for Computing Implied Volatility

标题 : 计算隐含波动率的自适应梯度下降方法

作者 : Yixiao Lu, Yihong Wang, Tinggan Yang , 类别 ：Computational Finance (q-fin.CP)

链接 : https://arxiv.org/pdf/2108.07035

说明 : Comments: 6 pages, 1 table, 4 figures

Abstract : In this paper, a new numerical method based on adaptive gradient descent optimizers is provided for computing the implied volatility from the Black Scholes (B S) option pricing model. It is shown that the new method is more accurate than the close form approximation. Compared with the Newton Raphson method, the new method obtains a reliable rate of convergence and tends to be less sensitive to the beginning point.

摘要 : 本文提出了一种新的基于自适应梯度下降优化器的数值方法来计算Black-Scholes（bs）期权定价模型的隐含波动率。结果表明，新方法比闭式近似更精确。与Newton-Raphson方法相比，新方法具有可靠的收敛速度，且对起始点不太敏感。

## 

\[14\] Multivariate self exciting jump processes with applications to financial data

标题 : 多元自激跳跃过程及其在金融数据中的应用

作者 : Heidar Eyjolfsson, Dag Tjøstheim , 类别 ：Probability (math.PR)

链接 : https://arxiv.org/pdf/2108.10176

说明 : -

Abstract : The paper discusses multivariate self and cross exciting processes. We define a class of multivariate point processes via their corresponding stochastic intensity processes that are driven by stochastic jumps. Essentially, there is a jump in an intensity process whenever the corresponding point process records an event. An attribute of our modelling class is that not only a jump is recorded at each instance, but also its magnitude. This allows large jumps to influence the intensity to a larger degree than smaller jumps. We give conditions which guarantee that the process is stable, in the sense that it does not explode, and provide a detailed discussion on when the subclass of linear models is stable. Finally, we fit our model to financial time series data from the S &P 500 and Nikkei 225 indices respectively. We conclude that a nonlinear variant from our modelling class fits the data best. This supports the observation that in times of crises (high intensity) jumps tend to arrive in clusters, whereas there are typically longer times between jumps when the markets are calmer. We moreover observe more variability in jump sizes when the intensity is high, than when it is low.

摘要 : 本文讨论了多元自激励和交叉激励过程。我们定义了一类由随机跳跃驱动的多元点过程，通过它们相应的随机强度过程。本质上，每当相应的点过程记录一个事件时，强度过程就会发生跳跃。我们的建模类的一个属性是，不仅在每个实例中记录跳跃，而且还记录其大小。这使得大跳跃比小跳跃对强度的影响更大。我们给出了保证过程在不爆炸的意义上是稳定的条件，并详细讨论了线性模型的子类何时是稳定的。最后，我们将我们的模型分别与标准普尔500指数和日经225指数的金融时间序列数据进行拟合。我们得出结论，我们的建模类中的非线性变量最适合数据。这支持了这样的观察：在危机时期（高强度），跳跃往往以集群的形式出现，而当市场较为平静时，跳跃之间的时间通常较长。此外，我们还观察到，当强度较高时，跳跃大小的变化比强度较低时更大。

## 

\[15\] Assessment of waterfront office redevelopment plan on optimal building energy demand and rooftop photovoltaics for urban decarbonization

标题 : 评估滨水办公室重建计划对最佳建筑能源需求和屋顶光伏城市脱碳的影响

作者 : Younghun Choi, Takuro Kobashi, Yoshiki Yamagata, Akito Murayama , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2108.09029

说明 : Comments: 29 pages

Abstract : Designing waterfront redevelopment generally focuses on attractiveness, leisure, and beauty, resulting in various types of building and block shapes with limited considerations on environmental aspects. However, increasing climate change impacts necessitate these buildings to be sustainable, resilient, and zero CO2 emissions. By producing five scenarios (plus existing buildings) with constant floor areas, we investigated how building and district form with building integrated photovoltaics (BIPV) affect energy consumption and production, self sufficiency, CO2 emission, and energy costs in the context of waterfront redevelopment in Tokyo. From estimated hourly electricity demands of the buildings, techno economic analyses are conducted for rooftop PV systems for 2018 and 2030 with declining costs of rooftop PV systems. We found that environmental building designs with rooftop PV system are increasingly economical in Tokyo with CO2 emission reduction of 2 9 that depends on rooftop sizes. Payback periods drop from 14 years in 2018 to 6 years in 2030. Toward net zero CO2 emissions by 2050, immediate actions are necessary to install rooftop PVs on existing and new buildings with energy efficiency improvements by construction industry and building owners. To facilitate such actions, national and local governments need to adopt appropriate policies.

摘要 : 滨水区重新开发的设计通常侧重于吸引力、休闲和美观，从而形成各种类型的建筑和街区形状，对环境方面的考虑有限。然而，日益加剧的气候变化影响要求这些建筑具有可持续性、弹性和零二氧化碳排放。通过制作五个具有固定楼层面积的场景（加上现有建筑），我们调查了在东京滨水区重建背景下，建筑和区域形式与建筑集成光伏（BIPV）如何影响能源消耗和生产、自给自足、二氧化碳排放和能源成本。根据建筑物每小时的预计电力需求，对2018年和2030年屋顶光伏系统进行了技术经济分析，屋顶光伏系统的成本不断下降。我们发现，在东京，屋顶光伏系统的环保建筑设计越来越经济，二氧化碳排放量减少了29%，这取决于屋顶的大小。投资回收期从2018年的14年下降到2030年的6年。为了在2050年实现二氧化碳净零排放，有必要立即采取行动，在现有和新建筑上安装屋顶PVs，提高建筑业和建筑业主的能效。为了促进这些行动，国家和地方政府需要采取适当的政策。

## 

\[16\] Sensitivity of Optimal Retirement Problem to Liquidity Constraints

标题 : 最优退休问题对流动性约束的敏感性

作者 : Guodong Ding, Daniele Marazzina , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2108.09035

说明 : -

Abstract : In this work we analytically solve an optimal retirement problem, in which the agent optimally allocates the risky investment, consumption and leisure rate to maximise a gain function characterised by a power utility function of consumption and leisure, through the duality method. We impose different liquidity constraints over different time spans and conduct a sensitivity analysis to discover the effect of this kind of constraint.

摘要 : 在这项工作中，我们解析地解决了一个最优退休问题，在该问题中，代理通过对偶方法优化配置风险投资、消费和休闲率，以最大化以消费和休闲的幂效用函数为特征的收益函数。我们在不同的时间跨度上施加不同的流动性约束，并进行敏感性分析，以发现这种约束的影响。

## 

\[17\] Deep Sequence Modeling

标题 : 深层序建模

作者 : Lin William Cong, Ke Tang, Jingyuan Wang, Yang Zhang , 类别 ：Machine Learning (cs.LG)

链接 : https://arxiv.org/pdf/2108.08999

说明 : -

Abstract : We predict asset returns and measure risk premia using a prominent technique from artificial intelligence deep sequence modeling. Because asset returns often exhibit sequential dependence that may not be effectively captured by conventional time series models, sequence modeling offers a promising path with its data driven approach and superior performance. In this paper, we first overview the development of deep sequence models, introduce their applications in asset pricing, and discuss their advantages and limitations. We then perform a comparative analysis of these methods using data on U.S. equities. We demonstrate how sequence modeling benefits investors in general through incorporating complex historical path dependence, and that Long and Short term Memory (LSTM) based models tend to have the best out of sample performance.

摘要 : 我们使用人工智能深层序列建模中的一项重要技术来预测资产收益和衡量风险溢价。由于资产收益往往表现出传统时间序列模型无法有效捕获的序列依赖性，序列建模以其数据驱动的方法和优异的性能提供了一条有前途的道路。在本文中，我们首先概述了深序列模型的发展，介绍了它们在资产定价中的应用，并讨论了它们的优点和局限性。然后，我们使用美国股票数据对这些方法进行比较分析。我们展示了序列建模如何通过合并复杂的历史路径依赖而使投资者总体受益，并且基于长期和短期记忆（LSTM）的模型往往具有最佳的样本外性能。

## 

\[18\] Bermudan option pricing by quantum amplitude estimation and Chebyshev interpolation

标题 : 基于量子振幅估计和切比雪夫插值的百慕大期权定价

作者 : Koichi Miyamoto , 类别 ：Quantum Physics (quant-ph)

链接 : https://arxiv.org/pdf/2108.09014

说明 : Comments: 14 pages, no figure

Abstract : Pricing of financial derivatives, in particular early exercisable options such as Bermudan options, is an important but heavy numerical task in financial institutions, and its speed up will provide a large business impact. Recently, applications of quantum computing to financial problems have been started to be investigated. In this paper, we first propose a quantum algorithm for Bermudan option pricing. This method performs the approximation of the continuation value, which is a crucial part of Bermudan option pricing, by Chebyshev interpolation, using the values at interpolation nodes estimated by quantum amplitude estimation. In this method, the number of calls to the oracle to generate underlying asset price paths scales as widetilde O ( epsilon 1 ) , where epsilon is the error tolerance of the option price. This means the quadratic speed up compared with classical Monte Carlo based methods such as least squares Monte Carlo, in which the oracle call number is widetilde O ( epsilon 2 ) .

摘要 : 金融衍生品的定价，特别是早期可行权期权，如百慕大期权，是金融机构一项重要但繁重的数字任务，其加速将对业务产生重大影响。最近，人们开始研究量子计算在金融问题上的应用。在本文中，我们首先提出了百慕大期权定价的量子算法。该方法通过切比雪夫插值，使用量子振幅估计估计的插值节点处的值，对连续值进行近似，连续值是百慕大期权定价的关键部分。在这种方法中，调用oracle生成基础资产价格路径的次数按widetilde O（ε1）的比例递增，其中ε是期权价格的误差容限。这意味着与经典的基于蒙特卡罗的方法（如最小二乘蒙特卡罗）相比，二次加速，其中oracle调用号为widetilde O（ε2）。