# arxiv量化文献汇总翻译 20210129

partition 量化前沿速递 2021-01-29 23:00

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247483917&idx=2&sn=770f077cd935f07d5077d0106582f611&chksm=c3aebd99ff8309cf198bbd87b54f2ad77575ba5a0709d0e4cc104d04f53339cc9a4ba860a6b0#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247483917&idx=2&sn=770f077cd935f07d5077d0106582f611&chksm=c3aebd99ff8309cf198bbd87b54f2ad77575ba5a0709d0e4cc104d04f53339cc9a4ba860a6b0#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Investors Embrace Gender Diversity, Not Female CEOs

投资者接受性别多样性，而不是女性首席执行官

\[2\] Deep ReLU Network Expression Rates for Option Prices in high dimensional, exponential L vy models

高维指数L-vy模型中期权价格的Deep-ReLU网络表达率

## 

\[1\] Investors Embrace Gender Diversity, Not Female CEOs

标题 : 投资者接受性别多样性，而不是女性首席执行官

作者 : Christopher Cassion, Yuhang Qian, Constant Bossou, Margareta Ackerman , 类别 ：General Economics (econ.GN)

链接 : https://arxiv.org/pdf/2101.12008

说明 : Comments: 20 pages, 9 figures, appeared in EAI Intetain 2020

Abstract : The allocation of venture capital is one of the primary factors determining who takes products to market, which startups succeed or fail, and as such who gets to participate in the shaping of our collective economy. While gender diversity contributes to startup success, most funding is allocated to male only entrepreneurial teams. In the wake of COVID 19, 2020 is seeing a notable decline in funding to female and mixed gender teams, giving raise to an urgent need to study and correct the longstanding gender bias in startup funding allocation. We conduct an in depth data analysis of over 48,000 companies on Crunchbase, comparing funding allocation based on the gender composition of founding teams. Detailed findings across diverse industries and geographies are presented. Further, we construct machine learning models to predict whether startups will reach an equity round, revealing the surprising finding that the CEO s gender is the primary determining factor for attaining funding. Policy implications for this pressing issue are discussed.

摘要 : 风险资本的配置是决定谁将产品推向市场、哪些初创企业成功或失败、以及谁能够参与我们集体经济形成的主要因素之一。虽然性别多样性有助于创业成功，但大多数资金都分配给了男性创业团队。在COVID 19之后，2020年女性和男女混合团队的资金显著减少，这使得迫切需要研究和纠正创业资金分配中长期存在的性别偏见。我们对Crunchbase上的48000多家公司进行了深入的数据分析，根据创始团队的性别构成对资金分配进行了比较。在不同的行业和地区的详细调查结果提出。此外，我们还构建了机器学习模型来预测初创企业是否会进入一轮股权融资，揭示了一个令人惊讶的发现，即首席执行官的性别是获得融资的主要决定因素。讨论了这一紧迫问题的政策含义。

## 

\[2\] Deep ReLU Network Expression Rates for Option Prices in high dimensional, exponential L vy models

标题 : 高维指数L-vy模型中期权价格的Deep-ReLU网络表达率

作者 : Lukas Gonon, Christoph Schwab , 类别 ：Numerical Analysis (math.NA)

链接 : https://arxiv.org/pdf/2101.11897

说明 : -

Abstract : We study the expression rates of deep neural networks (DNNs for short) for option prices written on baskets of d risky assets, whose log returns are modelled by a multivariate L evy process with general correlation structure of jumps. We establish sufficient conditions on the characteristic triplet of the L evy process X that ensure varepsilon error of DNN expressed option prices with DNNs of size that grows polynomially with respect to mathcal O ( varepsilon 1 ) , and with constants implied in mathcal O ( cdot) which grow polynomially with respect d , thereby overcoming the curse of dimensionality and justifying the use of DNNs in financial modelling of large baskets in markets with jumps. In addition, we exploit parabolic smoothing of Kolmogorov partial integrodifferential equations for certain multivariate L evy processes to present alternative architectures of ReLU DNNs that provide varepsilon expression error in DNN size mathcal O ( log( varepsilon) a) with exponent a sim d , however, with constants implied in mathcal O ( cdot) growing exponentially with respect to d . Under stronger, dimension uniform non degeneracy conditions on the L evy symbol, we obtain algebraic expression rates of option prices in exponential L evy models which are free from the curse of dimensionality. In this case the ReLU DNN expression rates of prices depend on certain sparsity conditions on the characteristic L evy triplet. We indicate several consequences and possible extensions of the present results.

摘要 : 本文研究了d类风险资产期权价格的深度神经网络（简称DNN）的表达率，d类风险资产的对数收益率由具有跳跃一般相关结构的多元L evy过程建模。我们建立了关于L evy过程X的特征三元组的充分条件，以保证当DNN的大小相对于数学O（varepsilon 1）多项式增长时，DNN表示的期权价格的varepsilon误差，以及当DNN的大小相对于数学O（varepsilon 1）多项式增长时，mathcal O（cdot）中隐含的常数相对于d多项式增长时，DNN表示的期权价格的varepsilon误差，从而克服了维数的诅咒，证明了DNNs在跳跃市场的大篮子金融建模中的应用是合理的。此外，我们利用某些多元L evy过程的Kolmogorov偏积分微分方程的抛物平滑来给出ReLU DNNs的替代结构，它在DNN-size mathcal O（log（varepsilon）a）中提供了指数为a sim d的变ε表达式错误，然而，数学O（cdot）中隐含的常数相对于d呈指数增长。在levy符号上具有更强的、维数一致的非简并条件下，得到了指数levy模型中无维数灾的期权价格的代数表达式。在这种情况下，价格的ReLU-DNN表达率取决于特征L-evy三元组的某些稀疏性条件。我们指出了目前结果的几个后果和可能的扩展。