# 你真的懂Barra模型吗？它的核心其实是……

QuantML QuantML 2025-10-22 20:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492084&idx=1&sn=828158ffdd20593b753c154e39812e03&chksm=cfefec69a5222427e79c1565a662ab8334c89d7b68eaeb9edaf05d5fa160784b9985d2eea98b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492084&idx=1&sn=828158ffdd20593b753c154e39812e03&chksm=cfefec69a5222427e79c1565a662ab8334c89d7b68eaeb9edaf05d5fa160784b9985d2eea98b#rd)

![](assets/001.png)

Barra CNE5 Risk Model为量化策略（特别是指数增强以及量化对冲）提供了一个精细化、多维度且经过多步校准的风险预测框架。尽管市面上的相关资料众多，但大部分仅触及皮毛，侧重于风格因子的构建，而忽略了模型的核心——协方差矩阵的估计与调整。本文将深入剖析Barra模型的技术精髓，详细阐述如何构建与调整因子协方差矩阵(F)与特质风险方差矩阵(Δ)。并附上代码，以供研究与实践。

## 一、主要框架

风险模型作为指数增强策略中的重要组成部分，主要用于组合风险预测、因子合成、持仓权重优化及风险归因等环节。常见的风险模型包括GARCH时序预测模型、Ledoit-Wolf压缩估计模型及结构化模型等。本文基于Barra结构化因子模型，将对股票收益率协方差矩阵V的估计，拆解为对因子收益协方差矩阵F与股票特质收益方差矩阵 Δ 的分别估计。

## 二、因子收益与特质收益拆分

Barra结构化因子模型将股票收益拆分为一组共同因子的收益与个股残差收益之和。共同因子即风格因子，截面上的所有股票均受风格因子的影响，影响的程度因不同股票在多个不同风格上的暴露（即因子值）不同而有所区分；个股残差收益为仅与个股本身相关的特异性收益，该收益理论上与共同因子收益相互独立。

股票截面收益率可以为行业因子、风格因子和国家因子三部分共同因子解释，剥离这3部分后的残差部分，即为个股的特质收益率。

上式中，表示某段时间区间内的截面股票收益率，  表示该期期初个股n在行业因子i上面的因子暴露，以哑变量向量表示，股票在所属的中信一级行业上的因子暴露取1，其余取0，  表示该期内行业因子i的收益率；  表示个股n的风格暴露，  表示风格因子s的区间收益率；  表示国家因子，固定取值1，  表示个股的特质收益率。

通过计算个股的风格和行业暴露，进行多期截面WLS回归，回归权重取个股流通市值的平方根，所得的回归系数即各期的因子收益率。注意对于单只个股，其在所有行业因子上的暴露加总之和恒为1，而回归式中截距项国家因子的存在，将会导致其与行业因子之间存在共线性，因此需加入如下约束项 ：

上式中，  表示第j个行业流通市值的全市场占比，  为行业j的因子收益率。根据Ruud(2000)，带约束的WLS回归问题中，约束条件为  时(  、  分别为原回归式和加入约束条件后回归式的拟合系数向量，s为已知常数向量)，回归系数的解析解可以表示为 ：

在本文的因子收益率计算所涉及的WLS回归中，将约束条件和原始方程带入解析解式，即可求得因子收益率及个股特质收益率，后文基于本节内容估计因子收益协方差矩阵F与股票特质收益方差矩阵 。

## 三、协方差矩阵的估计与调整

![](assets/002.png)

### 1\. 偏误统计量

构造偏误统计量，用于评估协方差矩阵的调整效果。

首先，计算资产组合收益率的样本外标准化收益 ：

其中,  表示资产在当前时刻t的预测波动率，  表示从当前时刻t到t+q期间资产的未来收益率，q为预测时间长度，通常取21天。

其次，计算时间窗口T内标准化收益的标准差，即为偏误统计量 ：

从偏误统计量的构造公式来看，其衡量的是实际风险与估计风险之间的比率，若偏误统计量大于1，则说明低估了组合的风险；若偏误统计量小于1，则说明高估了组合的风险。当对风险完美估计时，偏差统计量的值应恰等于1，而实际情况下，由于采样误差的存在，这一条件难以满足，因此在收益率的正态分布假设下，只要偏误统计量的值落在95%置信区间内，就可以认为风险预测比较准确 ：

**计算代码：**

`def compare_bias_beforeafter_adjust(covs_before, covs_after, ret_df, ret_eig=True,                                        fut_window=21, rwindow=None, legends=None):       fut_cumret_eig = cal_fut_ret(ret_df, covs_before, eig=ret_eig, fut_window=fut_window)       cal_bias_stats(covs_before, fut_cumret=fut_cumret_eig, ret_eig=ret_eig, rwindow=rwindow)       cal_bias_stats(covs_after, fut_cumret=fut_cumret_eig, ret_eig=ret_eig, rwindow=rwindow)       plt.legend(legends)      def cal_fut_ret(rets, covs=None, fut_window=21, cov_window=252, eig=True):       if rets.shape[0] > cov_window + fut_window:           ret_df = rets.iloc[cov_window-1:].dropna(how='all', axis=0)       else:           ret_df = rets.copy()       fut_cumret = rolling_apply(ret_df, window=fut_window, myfunc=cum_ret_rapply).\                                  shift(-fut_window)       if eig:           assert covs.shape[0] == fut_cumret.shape[0]           fut_cumret = fut_cumret.values           _, eigmat = np.linalg.eigh(covs)           fut_cumret_eig = (fut_cumret[:, None, :] @ eigmat).squeeze()           return fut_cumret_eig       else:           return fut_cumret   `

### 2\. 风格因子协方差矩阵F估计

#### （1）EWMA调整

使用因子的历史收益率数据估计协方差矩阵时，为及时捕捉最近的市场状态变化，采用EWMA（Exponentially Weighted Moving Average）方法对近期数据赋予更大的权重，从而增加近期数据对最新风险估计的影响。

上式中，  表示因子k第s期收益，  表示因子k样本期内的指数加权平均收益，h为样本窗口长度，  为半衰权重，τ为半衰期。实际计算中，取h=252，τ=90。

（2）Newey-West调整

 的计算是基于因子收益序列时序不相关的假设计算而得的，但因子收益序列一般存在时序上的自相关性，为将此自相关性考虑在内，使用1- 𝐷 阶的时序自协方差矩阵对  进行修正。

上式中，  为截面 𝑡 上所有因子的收益率序列，  为滞后期为 𝑑 时的自协方差矩阵。实际计算中，取D=2。

![](assets/003.png)

_上图为经Newey-West调整前后，各风格因子的偏误统计量走势对比，可以看出经过该步调整后，偏误统计量整体位于0-2之间，估计准确性有了明显提升。_

**计算代码：**

`def ew_cov(s1, s2, window=None, half_life=None):       assert len(s1) == len(s2)       if window is None:           window = len(s1)       if half_life is None:           half_life = np.floor(0.25 * window)                  exp_wt = get_exponential_weights(window=window, half_life=half_life)       ewt_sum1 = wt_sum(s1, exp_wt)       ewt_sum2 = wt_sum(s2, exp_wt)       s1 = s1 - ewt_sum1       s2 = s2 - ewt_sum2       if len(s1) < len(exp_wt):           exp_wt = exp_wt[-len(s1):]       not_na = (~np.isnan(s1)) & (~np.isnan(s2))        return np.nansum(exp_wt * s1 * s2) / np.sum(not_na * exp_wt)   `

#### （3）Eigenfactor调整

特征组合，即把协方差矩阵进行特征根分解后，以特征向量为权重的投资组合，该组合的波动率即为该组合权重（特征向量）对应的特征值，由于协方差矩阵为对称矩阵，其分解对应的特征向量之间相互正交，因此各特征值对应的特征组合之间互不相关。

实证发现，特征组合的偏误统计量与投资组合真实波动率呈现明显的负相关，即简单的历史协方差矩阵预测，倾向于明显低估低波动率特征组合的风险，风险低估程度随特征组合波动率（特征值）的增大而逐渐减小。基于此，文献假设最优投资组合的风险低估很可能与特征组合的风险偏误（即特征值偏误）紧密相关，并且基于这一假设，提出了利用蒙特卡洛模拟估计采样误差带来的特征值偏误，用于修正协方差矩阵的特征值，从而解决风险模型低估最优投资组合风险的问题。

具体调整步骤如下 ：

首先，将样本协方差矩阵  进行特征根分解，即可得到一个对角矩阵  和一个正交矩阵 。  是对角矩阵，其对角线上的第k个元素表示第k个特征组合的方差，其平方根即为第k个特征组合的风险。  的第k列即为  的第k个特征向量，该向量为特征组合中的持仓权重。

其次，通过蒙特卡罗模拟生成模拟特征组合，计算“真实”协方差矩阵（  ）与模拟组合的协方差矩阵的特征值的比值，衡量采样误差带来的特征值偏误。

a.随机生成大小为  的模拟特征组合收益矩阵 。其中，  为特征组合数目，即因子数目，  为模拟的期数，矩阵的第  行数据服从均值为0、方差为  的正态分布。这样第k行元素的方差即为第k个特征因子的“真实”方差。根据因子与特征组合之间的关系，可以得到因子的模拟收益率矩阵 。

b.计算模拟因子的协方差矩阵 。可以证明，模拟因子协方差矩阵  是“真实”协方差矩阵  的一个无偏估计， 。但是由于采样误差的存在，模拟协方差矩阵相对  存在一定的误差。

c.将模拟协方差矩阵  进行特征值分解，得到模拟特征组合权重矩阵  和模拟特征组合的样本方差，即模拟特征值矩阵 。

d.按照模拟特征组合权重  ，将真实协方差矩阵  分解，得到模拟特征组合的真实方差，即真实特征值矩阵 。

由于  的每一列并不是  对应的特征向量，因此分解得到的特征值矩阵  并不是对角矩阵。但是，依旧可以将  的主对角线元素当作模拟特征组合的真实方差。

e.共进行  次蒙特卡罗模拟，计算第  个特征组合的特征值偏误 ：

最后，进一步调整对特征值偏误的估计，得到修正后的因子收益协方差矩阵  ：

实际计算中，进行M=1000次蒙特卡洛模拟，  是调整系数，取1.5。

![](assets/004.png)

_将所有特征组合的样本内风险（特征值）由小到大进行排列，绘制出各个特征组合的偏差统计量。可以看到，调整前，对于样本内低波动的特征组合，其偏差统计量明显大于1，调整后，特征组合偏差统计量大部分落在95%置信区间内，对于低波动投资组合的风险低估得到了修正。_

#### （4）波动率偏误调整

波动率偏误调整（Volatility Regime）主要考虑利用截面上不同因子的信息，判断模型是否在某些时间段内系统性地高估或者低估了所有因子的波动率，根据此波动率偏误将截面上的因子协方差矩阵进行整体缩放。

 为第  个时间截面上，所有因子的总偏误统计量。由于单个截面数据容易受到随机噪声的影响，因此通过指数移动加权平均，计算出过去一段时间内的平均偏误系数  ，也称作因子波动率调整系数。

 为指数衰减权重，取时间窗口h=252，权重半衰期 。最后得到经过波动率调整过后的最终的因子协方差矩阵 。

为了检验波动率偏误调整效果，定义截面因子波动率  如上式。因子波动率调整系数  与因子横截面波动率  之间的关系如下图所示，可以看到二者之间存在一定的正相关关系。在截面因子波动率突然增大时，因子波动率调整系数及时增大，以修正可能的风险低估；在截面因子波动率突然减小时，因子波动率调整系数及时减小，以修正可能的风险高估。

![](assets/005.png)

### 3\. 股票特质收益方差矩阵 Δ 的估计

Barra模型中假定单只股票的特异风险与各风格因子之间互不相关，且各股票之间的特异风险也是互不相关的，因此股票组合的特异风险∆是一个对角矩阵，其非对角线上元素为0，主对角线上的元素为个股的特质波动率。

#### （1）EWMA调整 & Newey-West调整

该部分调整方法与因子收益协方差矩阵部分一致，其中Newey-West调整过程的滞后期取D=5。

#### （2）结构化调整

基于单只股票的历史收益数据计算得到的特质波动率，容易受到其缺失值和异常值的影响。例如，股票上市时间短、停牌时间长，导致单只股票的特异风险数据存在一定的缺失；公司披露重大事件的时间节点附近，股票的特异收益可能出现异常值。通过对股票时序数据进行结构化模型调整（Structural Model），修正特异收益缺失值和异常值对风险矩阵的影响。

具体调整方法为 ：

首先，对于一段时间窗（ℎ=252）内的特异性收益序列，定义第  只股票的协调参数 :

上式中，  表示样本期内的有效数据（无明显缺失）的个数，  为衡量特异收益肥尾程度的指标，  为样本期内特异收益的等权标准差，  样本期内特异收益的稳健估计标准差，由样本期内特异收益的3/4分位数  与1/4分位数  相减并乘以调整系数而得。股票在样本期内存在明显数据缺失或异常值导致的肥尾现象时，  ；若无明显数据缺失和异常值，则 。

其次，根据  将全部股票样本划分为数据质量较好和数据质量较差的两个样本池，并对数据质量较差的股票特质风险进行结构化填充。对于所有  的股票，进行如下回归 ：

 为经过Newey-West调整之后的股票特质波动，通过将  对所有股票的因子暴露进行市值加权的回归，得到每个因子对特异波动的贡献值  ，从而可以得到该只股票的结构化特质风险预测值 。

最后，对于所有个股，以协调参数  为权重，综合调整前的股票特异波动  和结构化特异波动  ，得到结构化调整后的特异波动 。

结构化调整主要针对存在明显缺失值或异常值，即  的股票。数据质量良好（  ） 的股票，结构化调整前、后的特异波动不变。

`def structural_adjust(cov_nw, idio_ret, factor_load, olswt, e0=1.05):       q1 = np.percentile(idio_ret, 25, axis=0)       q3 = np.percentile(idio_ret, 75, axis=0)       sigma_u_hat = (1 / 1.35) * (q3 - q1)       sigma_u_eq = np.nanstd(idio_ret, axis=0, ddof=1)       z_u = np.abs(sigma_u_eq / sigma_u_hat - 1)       h = (~np.isnan(idio_ret)).sum(axis=0)              mul1 = np.where((h - 60)/120 > 0, (h - 60)/120, 0)       mul1 = np.where(mul1 <= 1, mul1, 1)       mul2 = np.where(np.exp(1-z_u) >= 0, np.exp(1-z_u), 0)       mul2 = np.where(mul2 <= 1, mul2, 1)       gamma = mul1 * mul2              valid_loc = np.argwhere(gamma == 1).flatten()       y = np.log(np.diag(cov_nw)[valid_loc])       X = factor_load[valid_loc]       cmv_wt = olswt[valid_loc]          params = regress(y, X, cmv_wt)       sigma_n_str = e0 * np.exp(np.dot(factor_load, params))              sigma_n_ts = np.where(np.isnan(np.diag(cov_nw)), 0, np.diag(cov_nw))       sigma_n_str = np.where(np.isnan(sigma_n_str), 0, sigma_n_str)       sigma_u_hat = gamma * sigma_n_ts + (1 - gamma) * sigma_n_str       sigma_u_hat = np.diag(np.where(sigma_u_hat==0, np.nan, sigma_u_hat))       return np.diag(sigma_u_hat)   `

#### （3）贝叶斯压缩调整

实证发现，特异性风险存在明显的回归均值趋势，即样本内波动率较低的股票，很可能在样本外的未来时刻波动率升高，导致风险模型低估其未来风险；同样地，样本内波动率较高的股票，很可能在样本外的未来时刻波动率降低，从而导致风险模型高估其未来风险。

Barra将股票按照其市值从小到大分为10组，进行贝叶斯收缩调整（Bayesian Shrinkage），通过将单只股票的特异风险向其所在的市值分组的市值加权平均风险压缩，从而缓解特异性风险的回归均值趋势。具体调整步骤为 ：

首先，计算贝叶斯先验风险矩阵，即股票  所在市值分组  的市值加权特异风险均值 。

其次，计算压缩密度 。

上式中，q为压缩系数取1，  为股票  所属市值分组  的特异风险标准差。

最后，得到调整后的特异波动 。

如果股票特异波动相对组内均值的偏离越大，即股票特异波动越极端，那么贝叶斯压缩密度越接近1，即贝叶斯压缩后特异波动向组内均值回归的程度越大。

#### (4)波动率偏误调整

波动率偏误调整考虑同一时间截面上所有股票的特异波动，判断模型是否在某些时间段内系统性地高估或者低估了所有股票的特异性风险，并根据此波动率偏误对截面上的特异性方差矩阵进行整体缩放。

首先，计算特异风险的横截面偏误统计量 。其中，  为股票n在t时刻的市值权重。

其次，计算波动调整系数 。其中，  为指数衰减权重，时间窗口h=252，半衰期 。

最后，得到波动率偏误调整后的股票特质波动率。 

与风格因子协方差矩阵的调整类似，由下图可以看出，在时间序列上，特异波动率调整系数  会及时跟进截面特异波动率  的变化。

![](assets/006.png)

将股票按照其预测特质波动率从小到大分为10组，并计算每组的平均偏误统计量，其结果如下图所示。可以看到在贝叶斯压缩调整(bs)前，股票的特质波动率存在明显的低估低波动、高估高波动的现象，经过贝叶斯压缩调整后，偏误统计量整体分布更为均衡，在波动率偏误调整(vra)后，整体的取值更加接近95%置信区间，从而调整后的特质波动预测更为合理。

![](assets/007.png)

## 三、风险模型的应用示例

利用组合权重w，可以计算组合风险= 。对于指数而言，其组合权重即为成分股权重。 以沪深300指数（000300.SH）为例，根据风险模型计算的未来21日预测值（日标准差）与实际值走势对比如下图，二者在全区间内(2014.1-2023.12)的相关系数达0.735，二者的走势相对较为接近，可以将风险模型作为风险预测的有效工具。

`def get_index_risk_forecast(api, floads，fcovs, sidio_vol，index_code='000300.SH',                                sdate='2014-1-1', edate='2023-12-31'):       #index_stock_weight       index_weight_all = api.query_qdata(qname='index_weight', raw=True)       index_wt = index_weight_all.loc[index_code]       index_wt = index_wt.squeeze().unstack(level=1).loc[sdate:edate] / 100              #cal predicted index volatality       indcols = floads.columns.difference(stylefac_names)       res = {}       for dt in index_wt.index:           fload = floads.loc[dt]           fload = fload.drop(indcols[fload[indcols].sum(axis=0) == 0], axis=1)           fcov = fcovs[dt]           if len(fload.columns.difference(fcov.index)) > 0:               fload = fload[fcov.index]           mut_stock_vol = fload @ fcov @ fload.T            idio_stock_vol = sidio_vol.loc[dt].reindex(mut_stock_vol.index).squeeze()           idio_stock_vol = np.diag(idio_stock_vol.fillna(0).values)           stock_vol = mut_stock_vol + idio_stock_vol           iwt = index_wt.loc[dt].reindex(stock_vol.index).fillna(0).values           idx_vol = iwt.T @ stock_vol.fillna(0) @ iwt           res[dt] = idx_vol       idx_vol_fore = pd.Series(res)              idx_p = api.query_qdata(qname='index_quote', raw=True)              pc = idx_p.loc[index_code]['changepct'] / 100       idx_vol = pc.rolling(21).std()       idx_vol = idx_vol.shift(-21).loc[sdate:edate]               ivol = (idx_vol_fore**(1/2)/np.sqrt(21)).to_frame('forecast').assign(true=idx_vol)           ivol.plot()   `

![](assets/008.png)

_本文涉及资料及完整代码均已上传至知识星球，完整版代码请关注本文作者的github：ShiliangZhang-nku，后续将上传完整项目代码。_

### 参考文献

1.  “An Introduction To Classical Econometric Theory”.Pual A. Ruud, Oxford University Press, 2000.
    
2.  Shepard Peter, 2009. Second Order Risk.Working Paper.
    
3.  MencheroJose, Jun Wang, D.J.Orr, 2011. Eigen-Adjusted Covariance Matrices.MSCI Research Insight.
    
4.  Grinold R, R. Kahn, 2000, Active Portfolio Management, New York:McGraw-Hill.
    
5.  Menchero Jose, D.J.Orr, Jun Wang, 2011, The Barra USE Equity Model (USE4).
    

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/009.jpg)