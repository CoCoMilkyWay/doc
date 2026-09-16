# arxiv量化文献汇总翻译 20210113

Shame1ess 量化前沿速递 2021-01-13 22:30

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247483838&idx=2&sn=f9eda27c9cfa7a0e4f07834e23b69639&chksm=c377ff338f84b7a47a4bc9189c07aca61af7504c380727f75db6d89ac008c03f820d980fe6e9#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247483838&idx=2&sn=f9eda27c9cfa7a0e4f07834e23b69639&chksm=c377ff338f84b7a47a4bc9189c07aca61af7504c380727f75db6d89ac008c03f820d980fe6e9#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递  

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Portfolio Construction Using Stratified Models

基于分层模型的投资组合构建

\[2\] Short Rate Dynamics

短速率动力学

\[3\] Learning and Upgrading in Global Value Chains

全球价值链中的学习与提升

\[4\] Text analysis in financial disclosures

财务披露中的文本分析

\[5\] Narrow Bracketing in Work Choices

工作选择中的窄括号

\[6\] Wild Randomness, and the application of Hyperbolic Diffusion in Financial Modelling

狂野随机性与双曲线扩散在金融模型中的应用

\[7\] Social Media, Content Moderation, and Technology

社交媒体、内容节制和技术

\[8\] Quantum option pricing using Wick rotated imaginary time evolution

基于Wick旋转虚时演化的量子期权定价

## 

\[1\] Portfolio Construction Using Stratified Models

标题 : 基于分层模型的投资组合构建

作者 : Jonathan Tuck, Shane Barratt, Stephen Boyd , 类别 ：Portfolio Management (q-fin.PM)

链接 : https://arxiv.org/pdf/2101.04113

说明 : -

Abstract : In this paper we develop models of asset return mean and covariance that depend on some observable market conditions, and use these to construct a trading policy that depends on these conditions, and the current portfolio holdings. After discretizing the market conditions, we fit Laplacian regularized stratified models for the return mean and covariance. These models have a different mean and covariance for each market condition, but are regularized so that nearby market conditions have similar models. This technique allows us to fit models for market conditions that have not occurred in the training data, by borrowing strength from nearby market conditions for which we do have data. These models are combined with a Markowitz inspired optimization method to yield a trading policy that is based on market conditions. We illustrate our method on a small universe of 18 ETFs, using four well known and publicly available market variables to construct 10000 market conditions, and show that it performs well out of sample. The method, however, is general, and scales to much larger problems, that presumably would use proprietary data sources and forecasts along with publicly available data.

摘要 : 在本文中，我们建立了资产回报均值和协方差的模型，这些模型依赖于一些可观察的市场条件，并利用这些条件来构建一个依赖于这些条件和当前投资组合持有量的交易策略。在离散化市场条件后，我们拟合拉普拉斯正则分层模型的回报均值和协方差。这些模型对于每个市场条件具有不同的均值和协方差，但是被正则化，以便附近的市场条件具有相似的模型。这项技术允许我们通过从我们有数据的附近市场条件中借用力量，来拟合训练数据中没有出现的市场条件的模型。这些模型结合马科维茨启发的优化方法，以产生一个基于市场条件的交易政策。我们以一个由18只etf组成的小宇宙为例说明了我们的方法，使用了四个众所周知和公开的市场变量来构建10000个市场条件，并证明了它在样本外表现良好。然而，这种方法是通用的，并且可以扩展到更大的问题，可能会使用专有的数据源和预测以及公开可用的数据。

## 

\[2\] Short Rate Dynamics

标题 : 短速率动力学

作者 : Karol Gellert, Erik Schlögl , 类别 ：Mathematical Finance (q-fin.MF)

链接 : https://arxiv.org/pdf/2101.04308

说明 : -

Abstract : The Secured Overnight Funding Rate (SOFR) is becoming the main Risk Free Rate benchmark in US dollars, thus interest rate term structure models need to be updated to reflect the key features exhibited by the dynamics of SOFR and the forward rates implied by SOFR futures. Historically, interest rate term structure modelling has been based on rates of substantially longer time to maturity than overnight, but with SOFR the overnight rate now is the primary market observable. This means that the empirical idiosyncrasies of the overnight rate cannot be ignored when constructing interest rate models in a SOFR based world. As a rate reflecting transactions in the Treasury overnight repurchase market, the dynamics of SOFR are closely linked to the dynamics of the Effective Federal Funds Rate (EFFR), which is the interest rate most directly impacted by US monetary policy target rate decisions. Therefore, these rates feature jumps at known times (Federal Open Market Committee meeting dates), and market expectations of these jumps are reflected in prices for futures written on these rates. On the other hand, forward rates implied by Fed Funds and SOFR futures continue to evolve diffusively. The model presented in this paper reflects the key empirical features of SOFR dynamics and is calibrated to futures prices. In particular, the model reconciles diffusive forward rate dynamics with piecewise constant paths of the target short rate.

摘要 : 有担保隔夜融资利率（SOFR）正成为美元的主要无风险利率基准，因此需要更新利率期限结构模型，以反映SOFR动态和SOFR期货隐含的远期利率的关键特征。从历史上看，利率期限结构模型一直基于比隔夜长得多的到期时间的利率，但有了SOFR，隔夜利率现在是可观察的主要市场。这意味着，在建立基于SOFR的利率模型时，隔夜利率的经验特质不可忽视。作为反映美国国债隔夜回购市场交易的利率，SOFR的动态与有效联邦基金利率（EFFR）的动态密切相关，EFFR是受美国货币政策目标利率决定最直接影响的利率。因此，这些利率以已知时间（联邦公开市场委员会会议日期）的跳跃为特征，市场对这些跳跃的预期反映在基于这些利率的期货价格中。另一方面，美联储基金和SOFR期货隐含的远期利率继续扩散演变。本文提出的模型反映了SOFR动力学的主要经验特征，并对期货价格进行了校正。特别是，该模型协调了扩散远期利率动态与分段常数路径的目标短期利率。

## 

\[3\] Learning and Upgrading in Global Value Chains

标题 : 全球价值链中的学习与提升

作者 : Sourish Dutta , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2101.04447

说明 : Comments: 26 pages, PhD Proposal

Abstract : The topic of my research is Learning and Upgrading in Global Value Chains An Analysis of India s Manufacturing Sector . To analyse India s learning and upgrading through position, functions, specialisation & value addition of manufacturing GVCs, it is required to quantify the extent, drivers, and impacts of India s Manufacturing links in GVCs. I have transformed this overall broad objective into three fundamental questions (1) What is the extent of India s Manufacturing Links in GVCs (2) What are the determinants of India s Manufacturing Links in GVCs (3) What are the impacts of India s Manufacturing Links in GVCs These three objectives represent my three chapters in my PhD thesis.

摘要 : 我的研究主题是全球价值链中的学习与升级——对印度制造业的分析。为了通过制造业全球价值链的地位、功能、专业化和增值来分析印度的学习和升级，需要量化印度制造业在全球价值链中的程度、驱动力和影响。我把这一总体目标转化为三个基本问题：（1）印度制造业在全球价值链中的关联程度如何（2）印度制造业在全球价值链中的关联决定因素是什么（3）印度制造业在全球价值链中的关联影响是什么这三个目标代表了我博士论文中的三个章节。

## 

\[4\] Text analysis in financial disclosures

标题 : 财务披露中的文本分析

作者 : Sridhar Ravula , 类别 ：Trading and Market Microstructure (q-fin.TR)

链接 : https://arxiv.org/pdf/2101.04480

说明 : Comments: 24 pages, 1 figure, Text analysis in financial disclosure analysis survey

Abstract : Financial disclosure analysis and Knowledge extraction is an important financial analysis problem. Prevailing methods depend predominantly on quantitative ratios and techniques, which suffer from limitations like window dressing and past focus. Most of the information in a firm s financial disclosures is in unstructured text and contains valuable information about its health. Humans and machines fail to analyze it satisfactorily due to the enormous volume and unstructured nature, respectively. Researchers have started analyzing text content in disclosures recently. This paper covers the previous work in unstructured data analysis in Finance and Accounting. It also explores the state of art methods in computational linguistics and reviews the current methodologies in Natural Language Processing (NLP). Specifically, it focuses on research related to text source, linguistic attributes, firm attributes, and mathematical models employed in the text analysis approach. This work contributes to disclosure analysis methods by highlighting the limitations of the current focus on sentiment metrics and highlighting broader future research areas

摘要 : 财务信息披露分析与知识提取是财务分析的一个重要问题。流行的方法主要依赖于定量比率和技术，这些方法受到诸如粉饰和过去关注等限制。公司财务披露中的大部分信息都是非结构化的，并且包含了关于公司健康状况的有价值的信息。由于体积巨大和非结构化的特性，人类和机器无法对其进行令人满意的分析。研究人员最近开始分析披露的文本内容。本文介绍了财务会计中非结构化数据分析的前期工作。本文还探讨了计算语言学中的最新方法，并回顾了自然语言处理（NLP）中的最新方法。具体而言，它侧重于与文本来源、语言属性、企业属性以及文本分析方法中使用的数学模型相关的研究。这项工作有助于披露分析方法的局限性，突出目前的重点情绪指标和突出更广泛的未来研究领域

## 

\[5\] Narrow Bracketing in Work Choices

标题 : 工作选择中的窄括号

作者 : Francesco Fallucchi, Marc Kaufmann , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2101.04529

说明 : -

Abstract : Many important economic outcomes result from cumulative effects of smaller choices, so the best outcomes require accounting for other choices at each decision point. We document narrow bracketing the neglect of such accounting in work choices in a pre registered experiment on MTurk bracketing changes average willingness to work by 13 28 . In our experiment, broad bracketing is so simple to implement that narrow bracketing cannot possibly be due to optimal conservation of cognitive resources, so it must be suboptimal. We jointly estimate disutility of work and bracketing, finding gender differences in convexity of disutility, but not in bracketing.

摘要 : 许多重要的经济结果来自于较小选择的累积效应，因此最佳结果需要在每个决策点考虑其他选择。我们在MTurk的一个预先注册的实验中记录了在工作选择中忽略这种会计的窄括号，括号内的变化平均工作意愿为13 28。在我们的实验中，宽括号很容易实现，窄括号不可能是由于认知资源的最优保护，所以它一定是次优的。我们共同估计工作的不效用和括号，发现性别差异凸的不效用，但没有括号。

## 

\[6\] Wild Randomness, and the application of Hyperbolic Diffusion in Financial Modelling

标题 : 狂野随机性与双曲线扩散在金融模型中的应用

作者 : Will Hicks , 类别 ：Mathematical Finance (q-fin.MF)

链接 : https://arxiv.org/pdf/2101.04604

说明 : -

Abstract : The application of the Cauchy distribution has often been discussed as a potential model of the financial markets. In particular the way in which single extreme, or Black Swan , events can impact long term historical moments, is often cited. In this article we show how one can construct Martingale processes, which have marginal distributions that tend to the Cauchy distribution in the large volatility limit. This provides financial justification to the approach investigated in cite Romero , and highlights an example of how quantum probability can be used to construct non Gaussian Martingales. We go on to illustrate links with hyperbolic diffusion, and discuss the insight this provides.

摘要 : 柯西分布作为一种潜在的金融市场模型，其应用经常被讨论。特别是单个极端事件或黑天鹅事件影响长期历史时刻的方式，经常被引用。在这篇文章中，我们展示了如何构造鞅过程，它在大波动率极限下具有趋向于柯西分布的边缘分布。这为cite Romero中研究的方法提供了财务上的证明，并突出说明了如何使用量子概率构造非高斯鞅的一个例子。我们继续说明双曲扩散的联系，并讨论它提供的见解。

## 

\[7\] Social Media, Content Moderation, and Technology

标题 : 社交媒体、内容节制和技术

作者 : Yi Liu, T. Pinar Yildirim, Z. John Zhang , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2101.04618

说明 : -

Abstract : This paper develops a theoretical model to study the economic incentives for a social media platform to moderate user generated content. We show that a self interested platform can use content moderation as an effective marketing tool to expand its installed user base, to increase the utility of its users, and to achieve its positioning as a moderate or extreme content platform. The optimal content moderation strategy differs for platforms with different revenue models, advertising or subscription. We also show that a platform s content moderation strategy depends on its technical sophistication. Because of imperfect technology, a platform may optimally throw away the moderate content more than the extreme content. Therefore, one cannot judge how extreme a platform is by just looking at its content moderation strategy. Furthermore, we show that a platform under advertising does not necessarily benefit from a better technology for content moderation, but one under subscription does. This means that platforms under different revenue models can have different incentives to improve their content moderation technology. Finally, we draw managerial and policy implications from our insights.

摘要 : 本文发展了一个理论模型来研究社会媒体平台调节用户生成内容的经济激励。我们表明，一个自利的平台可以使用内容适度作为一个有效的营销工具，以扩大其安装的用户群，增加其用户的效用，并实现其定位为一个中等或极端的内容平台。对于不同收入模式、广告或订阅的平台，最佳的内容调节策略是不同的。我们还表明，平台的内容调节策略取决于其技术成熟度。由于技术的不完善，一个平台可能会以最佳方式抛弃适度的内容，而不是极端的内容。因此，人们不能仅仅通过观察一个平台的内容节制策略来判断它有多极端。此外，我们还表明，广告下的平台不一定能从更好的内容调节技术中受益，但订阅下的平台却能受益。这意味着，不同收入模式下的平台可以有不同的动机来改进其内容调节技术。最后，我们从我们的见解中得出管理和政策的启示。

## 

\[8\] Quantum option pricing using Wick rotated imaginary time evolution

标题 : 基于Wick旋转虚时演化的量子期权定价

作者 : Santosh Kumar Radha , 类别 ：Quantum Physics (quant-ph)

链接 : https://arxiv.org/pdf/2101.04280

说明 : -

Abstract : In this paper we reformulate the problem of pricing options in a quantum setting. Our proposed algorithm involves preparing an initial state, representing the option price, and then evolving it using existing imaginary time simulation algorithms. This way of pricing options boils down to mapping an initial option price to a quantum state and then simulating the time dependence in Wick s imaginary time space. We numerically verify our algorithm for European options using a particular imaginary time evolution algorithm as proof of concept and show how it can be extended to path dependent options like Asian options. As the proposed method uses a hybrid variational algorithm, it is bound to be relevant for near term quantum computers.

摘要 : 本文重新构造了量子环境下的期权定价问题。我们提出的算法包括准备一个初始状态，表示期权价格，然后使用现有的虚拟时间模拟算法对其进行演化。这种期权定价方法可以归结为将初始期权价格映射到量子态，然后在Wick的虚拟时间空间中模拟时间依赖性。我们用一个特殊的虚时演化算法作为概念证明，对欧式期权的算法进行了数值验证，并说明了如何将其推广到路径相关期权，如亚式期权。由于所提出的方法采用了混合变分算法，因此它必然适用于近期量子计算机。