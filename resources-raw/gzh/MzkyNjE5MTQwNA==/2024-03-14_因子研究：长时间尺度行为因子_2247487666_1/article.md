# 因子研究：长时间尺度行为因子

白 量化前沿速递 2024-03-14 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487666&idx=1&sn=c71829eb98062dc6961eb1ab156a0f44&chksm=c394b359eb5540cf2a80be57e0169fdb9846e7f801c914b503d0f773b2a902c8ddd257c8d04b#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487666&idx=1&sn=c71829eb98062dc6961eb1ab156a0f44&chksm=c394b359eb5540cf2a80be57e0169fdb9846e7f801c914b503d0f773b2a902c8ddd257c8d04b#rd)

![](assets/001.png)

**0.摘要**

本文讨论了捕捉长尺度异象的FIN因子。根据Barberis and Shleifer (2003)和Daniel, Hirshleifer, and Subrahmanyam (2001)的研究，股票收益率的共同运动可以归因于错误定价和投资者对基本面信息的错误反应。文章使用上市公司的股票发行和回购计算了FIN因子，并与其他多因子模型进行比较。结果表明，FIN因子在解释异象和超额收益方面表现优异。进一步的实证研究还发现，FIN因子在中证1000指数上具有显著且稳定的多空组合收益和超额收益。尽管FIN因子在某些时期可能会有短暂失效，但整体而言，其收益能力呈现显著且稳定的上升趋势，并且具有较好的单调性。  

* * *

![](assets/002.png)

**1\. 引言**

股票收益率之间的共同运动通常有两个原因：

1.Barberis and Shleifer (2003)认为股票存在错误定价上的共性：

不同的股票实际上暴露在一些共同的风格风险上，而情绪冲击（sentiment shocks）会造成同一类风格的股票收益率的共同运动，因此同一类风格上的股票存在相关性很高的定价错误。

2.Daniel, Hirshleifer, and Subrahmanyam (2001)认为投资者对于股票基本面信息的错误反应上存在共性：

由于认知偏差，投资者难以对股票基本面方面的新信息做出及时、正确的反应，因此也会导致错误定价。

市场上的绝大多数异象按照时间尺度可以分为长、短两大类。短时间尺度的异象大多来自投资者的有限注意力（limited attention）、长时间尺度的异象大多来自投资者的过度自信（overconfidence）：例如，对其私人信息信号过度自信的投资者会对这些信号进行过度反应，导致价值效应。为此Daniel, Hirshleifer, and Sun (2018)三位作者提出了捕捉长尺度异象的 FIN 因子和捕捉短尺度异象的 PEAD 因子。

本文主要讨论的是捕捉长尺度异象的 **FIN 因子**。

![](assets/003.png)

**2\. 因子构建方式**

使用上市公司股票发行（issuance）和回购（repurchase）计算。研究表明，由于具备信息优势，公司的管理层善于利用市场上已经形成的定价错误“择时”自己公司的股价：当他们认为公司股价过高时，往往会增发；而当公司股价被低估时，通常采取回购。另一方面，普通（非理性）投资者往往过度自信，导致对上市公司增发、回购行为反应不足，使得股价不会在短期修正。  

Daniel, Hirshleifer, and Sun (2018)使用以下两个指标构建了他们的 FIN 因子：

**过去一年的 net-share-issuance（简称 NSI，出自 Pontiff and Woodgate (2008)）:**

![](assets/004.png)

**过去五年的 composite-share-issuance（简称 CSI，出自 Daniel and Titman (2006)）:**

![](assets/005.png)

综合 NSI 和 CSI（取均值）就得到了 FIN 指标，越小越好。除此之外，DHS 采用了 Fama-French 三因子中的做法，使用 FIN 指标（按从小到大排名）和市值对上市公司进行了 2×3 划分。

最终 FIN 因子定义为：

![](assets/006.png)

在FIN因子定义中，我们能看到他有意将对市值因子的解释度剔除，因此在回测时，对每组也使用了市值中性化处理。

![](assets/007.png)

**3\. 不同模型比较**

完成构建以后，沿用Barillas and Shanken (2018) 的观点：_一个优秀的多因子模型应该既能解释异象（test assets），又能解释其他模型中的因子（traded factors）_。测试中考虑的其他因子，这些因子在实证期间的收益率以及显著性如下

![](assets/008.png)

FIN因子的平均收益率在众因子中最高，且十分显著。

接着看FIN因子被其它模型的解释情况。这里使用已有多因子模型回归新因子。

![](assets/009.png)

可以看到FIN因子对大多数模型拥有显著的α，这说明FIN因子的超额收益绝大多数已有模型无法解释，例外是 NM 和 SY4 模型。

Daniel, Hirshleifer, and Sun (2018)接下来还使用用来捕捉短时间尺度的PEAD因子来与FIN因子构成新三因子模型，并使用他们的三因子模型来解释现有的因子，由于本文意不在讨论他们的新三因子模型，后面的研究过程便直接简要概括。结果是：

DHS 提出的三因子模型能够解释其他模型中绝大部分因子，然而 Fama-French 三因子中的 SMB、Novy-Marx 四因子中的 PMU 以及 HXZ4 四因子中的 IVA 因子可以获得 DHS 三因子无法解释的超额收益。其中，PMU 和 IVA 分别代表两个主流的维度 —— Profitability 和 Investment。DHS 的复合三因子模型对其解释力度较弱。另外一个无法解释的是 SMB 市值因子。

最后三位作者用多因子模型来解释异象，他们从 Hou, Xue, and Zhang (2015) 考察的 73 个异象中找出了 34 个，其中短时间尺度异象 12 个、长时间尺度异象 22 个。使用不同的检验标准，DHS 比较了不同模型在解释这些异象方面的能力。

结果表明复合三因子模型解释了全部短时间尺度异象，其在这方面的表现优于所有其他模型。对于长时间尺度异象，DHS 在 5% 的显著性水平下解释了 22 个中的 19 个，其表现和 NM 以及 SY4 模型相当，优于其他多因子模型。如果把全部 34 个异象放在一起综合考虑，复合三因子模型战胜了其他全部模型。

![](assets/010.png)

**4\. 中证1000的适用性**

我们按照FIN因子值从小到大打分，FIN因子值最小的得分最高。得分最高的为第一组，依此类推。不同于Fama-French做法的是，我们将每月待换仓的股票分为十组，并对每组股票做了行业中性化和市值中性化，我们选择了2016年6月28日- 2023年6月28日中证1000指数的成分股作为实测股票池，在考虑完涨跌停条件，剔除ST股、上市不满250个交易日股等条件后，每个换仓日可供选择的股票大约在700支左右，因此不再进一步用壳效应剔除极端股票。

**图一 分组各组累计收益率和基准**累计**收益率(%)**

![](assets/011.png)

**图二 多空组合**累计**收益率和超额**累计**收益率**(%)****

![](assets/012.png)

可以看到多空组合的收益（蓝线）主要来源于多头，说明FIN因子在获取正向收益的能力比较优秀。超额收益方面，多头组的累计收益（黄线）一直超越基准指数收益，在今年中证1000下行时，FIN因子依然拥有十分优秀的获取收益的能力。

虽然FIN因子在21年有短暂失效过，但是整体来看，多空组合收益和超额收益都呈显著且稳定的上升趋势。  

**图三 单调性检验**

![](assets/013.png)

IC值的计算方式为：t 期末各股票的综合因子打分作为序列 X，t 期到 t+1 期各股票的涨幅(%)序列作为序列 Y，然后计算序列 X 和序列 Y 的相关系数。相关系数计算公式：

![](assets/014.png)

_\*这里没有使用Spearman秩相关系数来计算IC，因此IC值会偏小，但是保留了更多的信息_

由图可以看出，FIN因子的单调性整体很好，12个月的IC均值基本都在x轴上方，仅在21年出现短暂的变向。整体来看，因子是一个比较优秀的反向因子。

**表一 年化多空组合收益率和超额收益显著性检验**

![](assets/015.png)

FIN因子在考虑完交易成本后整体上依然有有年化14.97%的多空组合收益率和13.25%的超额收益率，并且这些整体的年化收益率都至少有95%的置信程度。特别的，今年年初以来，因子的收益能力恢复，这六个月下来多空组合收益率和超额收益率年化以后分别达到46.80%和36.52%，并且这些收益率同样非常显著。

  

**参考文献**

Barberis, N., and Shleifer, A. (2003). Style investing. The Journal of Financial Economics, 68(2), 161-199.

Barillas, F., and Shanken, A., 2017. Which alpha?, Review of Financial Studies, forthcoming.

Daniel, K., Hirshleifer, D., & Subrahmanyam, A. (2001). Overconfidence, arbitrage, and equilibrium asset pricing. The Journal of Finance, 56(3), 921-965.

Daniel, K., Hirshleifer, D., & Sun, L. (2018). Short- and long-horizon behavioral factors. Columbia Business School Research Paper No. 18-5.

Daniel, K., and Titman,S., 2006, Market reactions to tangible and intangible information. Journal of Finance 61, 1605–1643.

Hou, K., Xue, C., and Zhang L., 2015. Digesting anomalies: An investment approach, Review of Financial Studies 28, 650–705.

Pontiff, J., and Woodgate, A., 2008, Share issuance and cross-sectional returns. The Journal of Finance 63, 921–945.