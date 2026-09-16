# arxiv量化文献汇总翻译 20210319-20210321

partition 量化前沿速递 2021-03-22 00:10

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247484047&idx=2&sn=5122e8c3a828e5e46a86d3c093dc6178&chksm=c355d83a1b73d39ee2e3f0b317935b08cdaf2773b9861ccd302fe155d9eebc0b98a5e9b65521#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247484047&idx=2&sn=5122e8c3a828e5e46a86d3c093dc6178&chksm=c355d83a1b73d39ee2e3f0b317935b08cdaf2773b9861ccd302fe155d9eebc0b98a5e9b65521#rd)

机器翻译，仅供参考！更多文献获取请关注公众号：量化前沿速递

获取原文请加入知识星球“量化前沿速递”

## 

文献汇总

\[1\] Statistical Arbitrage Risk Premium by Machine Learning

基于机器学习的统计套利风险溢价

\[2\] Leveraged ETF Investing

杠杆ETF投资

## 

\[1\] Statistical Arbitrage Risk Premium by Machine Learning

标题 : 基于机器学习的统计套利风险溢价

作者 : Raymond C. W. Leung, Yu-Man Tam , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2103.09987

说明 : -

Abstract : How to hedge factor risks without knowing the identities of the factors We first prove a general theoretical result even if the exact set of factors cannot be identified, any risky asset can use some portfolio of similar peer assets to hedge against its own factor exposures. A long position of a risky asset and a short position of a replicate portfolio of its peers represent that asset s factor residual risk. We coin the expected return of an asset s factor residual risk as its Statistical Arbitrage Risk Premium (SARP). The challenge in empirically estimating SARP is finding the peers for each asset and constructing the replicate portfolios. We use the elastic net, a machine learning method, to project each stock s past returns onto that of every other stock. The resulting high dimensional but sparse projection vector serves as investment weights in constructing the stocks replicate portfolios. We say a stock has high (low) Statistical Arbitrage Risk (SAR) if it has low (high) R squared with its peers. The key finding is that unique stocks have both a higher SARP and higher excess returns than ubiquitous stocks in the cross section, high SAR stocks have a monthly SARP (monthly excess returns) that is 1.101 (0.710 ) greater than low SAR stocks. The average SAR across all stocks is countercyclical. Our results are robust to controlling for various known priced factors and characteristics.

摘要 : 如何在不知道因子身份的情况下对冲因子风险我们首先证明了一个一般的理论结果，即使无法确定因子的确切集合，任何风险资产都可以使用一些同类资产的组合来对冲其自身的因子风险。风险资产的多头头寸和同行的复制投资组合的空头头寸代表该资产的因子剩余风险。我们将资产s因子剩余风险的预期收益作为其统计套利风险溢价（SARP）。从经验上估计SARP的挑战在于为每种资产找到对等方并构建重复的投资组合。我们使用弹性网（一种机器学习方法）将每个股票过去的收益率投影到其他股票的收益率上。由此得到的高维稀疏投影向量作为构建股票投资组合的投资权重。我们说，如果一只股票与它的同类股票具有低（高）R平方，它就具有高（低）统计套利风险（SAR）。关键的发现是，在横截面上，独特股票比普遍股票具有更高的SARP和更高的超额收益，高SAR股票的月SARP（月超额收益）比低SAR股票大1.101（0.710）。所有股票的平均SAR都是反周期的。我们的结果是稳健的控制各种已知的价格因素和特点。

## 

\[2\] Leveraged ETF Investing

标题 : 杠杆ETF投资

作者 : Tal Miller , 类别 ：Statistical Finance (q-fin.ST)

链接 : https://arxiv.org/pdf/2103.10157

说明 : -

Abstract : It is common knowledge that leverage can increase the potential returns of an investment, at the expense of increased risk. For a passive investor in the stock market, leverage can be achieved using margin debt or leveraged ETFs. We perform bootstrapped Monte Carlo simulations of leveraged (and unleveraged) mixed portfolios of stocks and bonds, based on past stock market data, and show that leverage can amplify the potential returns, without significantly increasing the risk for long term investors.

摘要 : 众所周知，杠杆可以增加投资的潜在回报，但代价是增加风险。对于股票市场的被动投资者来说，杠杆可以通过融资融券或杠杆etf来实现。基于过去的股市数据，我们对杠杆化（和非杠杆化）的股票和债券混合投资组合进行了自举蒙特卡罗模拟，结果表明，杠杆化可以放大潜在收益，而不会显著增加长期投资者的风险。