inInfo][Table_Title]2022.08.04

# 如何选择业绩评价指标

## ——精品文献解读系列（三十二）

## 本报告导读：

投资组合业绩评价的核心莫过于选择合适的评价指标。本报告不仅引入了三类全新的回报风险比率，还依据单调性、拟凹性、数乘不变性和唯分布依赖性的四维视角，对各种指标进行了综合比较，值得战略、战术配置投资者借鉴参考。

## 摘要：

投资学是一门学术界与业界紧密结合的学科，其中大类资产配置是这种紧密结合的代表。从 （ ）开创现代投资组合理论开始，学术界为业界提供了丰富的理论参考和方法模型，推动了大类资产配置实践的繁荣发展。为了帮助读者及时跟踪学术前沿，我们推出了“精品文献解读”系列报告，从大量学术文献中挑选出精品论文进行剖析解读，为读者呈现大类资产配置领域最新的思路和方法。

- 本篇为读者解读的文献是 Cheridito and Kromer（2013）在 Journal ofInvestment Strategies 上发表的论文“Reward-risk ratios”。

本报告引入了三类全新的回报风险比率，并依据单调性、拟凹性、数乘不变性和唯分布依赖性四个维度，将其和既有的业绩评价指标进行了全面对比。由于这三类回报风险比率都满足单调性和拟凹性，因此将其作为业绩评价指标时，能有效兼顾组合收益和持仓多样性。而出于计算便宜性的考虑，本报告引入的第二类指标还满足数乘不变性，第三类指标则只依赖于收益率的概率分布。基于上述分析，我们在本报告的第二部分对各种常见的业绩评价指标分门别类，着重比较了它们的差异，并特别论证了为何 Sharpe 比率虽然是最常见但却并不见得是最合理的组合业绩度量的原因。

投资组合业绩评价的核心莫过于选择合适的评价指标。本报告不仅引入了三类全新的回报风险比率，还依据单调性、拟凹性、数乘不变性和唯分布依赖性的四维视角，对各种指标进行了综合比较，值得战略、战术配置投资者借鉴参考。

大类资产配置研究

## hor] 报告作者

赵索(分析师)

8 0755-23976601

zhaosuo024832@gtjas.com

证书编号 S0880521080002

## cReport] 相关报告

当量化行业配置插上择时的翅膀

2022.08.01

使用基本面因子构建中证500指数增强策略初探

2022.08.01

攻防两端短兵相接，调仓换股做好准备 2022.07.31

欲速则不达，周线级回踩后方为配置良机 2022.07.28

## 1. 文献概述

## 文献来源：

Cheridito, P., and Kromer, E. Reward-risk ratios. Journal of Investment Strategies (2013).

## 文献摘要：

本报告引入了三类全新的回报风险比率，并依据单调性、拟凹性、数乘不变性和唯分布依赖性四个维度，将其和既有的业绩评价指标进行了全面对比。由于这三类回报风险比率都满足单调性和拟凹性，因此将其作为业绩评价指标时，能有效兼顾组合收益和持仓多样性。而出于计算便宜性的考虑，本报告引入的第二类指标还满足数乘不变性，第三类指标则只依赖于收益率的概率分布。基于上述分析，我们在本报告的第二部分对各种常见的业绩评价指标分门别类，着重比较了它们的差异，并特别论证了为何 Sharpe 比率虽然是最常见但却并不见得是最合理的组合业绩度量的原因。

## 文献评述：

投资组合业绩评价的核心莫过于选择合适的评价指标。本报告不仅引入了三类全新的回报风险比率，还依据单调性、拟凹性、数乘不变性和唯分布依赖性的四维视角，对各种指标进行了综合比较，值得战略、战术配置投资者借鉴参考。

## 2. 引言

回报风险比率（reward-risk ratio，RRR）在组合业绩评估中被广泛使用。但并非所有的回报风险比率都拥有良好的结构性质。例如，Sharpe 比率就不具备单调性，因此利用其作为业绩评价指标在一定程度上会导致投资决策反而更加青睐收益率更低的投资策略，相关分析参见 AumannandSerrano（2008）。在本报告中，我们要求每一种业绩评价指标至少满足单调性（monotonicity）和拟凹性（quasi-concavity）。单调性可以理解为收益的方向性，简单来说就是多胜于少，拟凹性可以理解为效用的均衡性，更关注收益率的均值而非极值。和 Sharpe 比率一致，许多既有的业绩评价指标都满足数乘不变性（scale-invariance）和唯分布依赖性（distribution-based）。需要注意的是，数乘不变性有时能简化计算，但并不能从决策理论的基本原则之中直接导出。显然，如果回报的分布函数事前已知，那么只依赖于其的业绩度量将非常有意义。但在实际场景中，意外事件的分布函数并不能被准确估计，故而策略之间的偏好关系并不会只是依是依赖于收益率的分布信息，参见 Klibanoff et al.（2005）、 Maccheroniet al.（2006）或者 Drapeau and Kupper（2013）。

在本报告中，我们将引入三类具备良好性质的回报风险比率并将其和既有的业绩评价指标进行对比。第一类指标可以视为特定概率测度下的期望收益，它们满足单调性和拟凹性，但通常不满足数乘不变性。它们通常需要利用比收益率分布更多的信息。第二类指标拥有和第一类指标类似的性质，由于在风险度量的计算上满足正齐次性，因此它们通常还满足数乘不变性。第三类指标作为第二类指标的一个子类，可以视为畸变期望之间的比值，并且该类指标只与收益的概率分布有关。本报告还列出了一些不满足单调性或者拟凹性的业绩评价指标，尽管它们被广泛接受和使用。特别的我们将会看到，以 Sharpe 比率为代表的均值偏差比率并不满足单调性。

## 3. 定义和基础知识

在符号上，我们有

$$
\left\{\begin{array}{rl}{\left(\Omega,\mathcal{F},\mathbb{P}\right)=\frac{1+\beta\mathcal{Z}}{16\lambda}\frac{\mathcal{Z}}{\mathcal{Z}}\frac{\mathcal{Z}}{\mathcal{Z}}|\mathrm{\ddot{z}}]}&{}\\{\mathcal{X}}&{=\left(\Omega,\mathcal{F},\mathbb{P}\right)\bot\mathbb{E}\mathbb{H}\dot{\mathcal{Z}}\frac{1}{\mathcal{Z}}\frac{\mathcal{S}}{\mathcal{Z}}\frac{\mathcal{Z}}{\mathcal{Z}}\mathbb{H}\dot{\mathcal{Z}}\frac{\dot{\mathcal{Z}}}{\mathcal{Z}}\frac{\mathcal{Z}}{\mathcal{F}}\frac{\dot{\mathcal{Z}}}{\mathcal{Z}}\frac{\dot{\mathcal{Z}}}{\mathcal{F}}}\\{\mathbb{E}}&{=\mathbb{E}_{\mathbb{P}}=\mathbb{P}\mathrm{\ al}/\frac{\dot{\mathcal{Z}}}{\mathcal{Z}}\mathcal{F}\dot{\mathcal{Z}}\frac{\dot{\mathcal{Z}}\dot{\mathcal{Z}}}{\mathcal{F}}\frac{\dot{\mathcal{Z}}\dot{\mathcal{Z}}}{\mathcal{Z}}}\\{\mathbb{E}_{\mathbb{Q}}}&{=\mathbb{Q}\mathrm{\ al}/\frac{\dot{\mathcal{Z}}}{\mathcal{Z}}\mathcal{F}\dot{\mathcal{Z}}\frac{\dot{\mathcal{Z}}\dot{\mathcal{Z}}}{\mathcal{F}}\frac{\dot{\mathcal{Z}}\dot{\mathcal{Z}}}{\mathcal{Z}}}\end{array}\right.
$$

对于不同的随机变量 X 和 Y，其大小关系是指在概率测度ℙ的意义下成立，即：

$$
\mathtt{X}\ge\mathtt{Y}\Leftrightarrow\mathbb{P}[\mathtt{X}\ge\mathtt{Y}]=1
$$

在本报告中，任取

$$
\mathrm{X}\in{\mathcal{X}}
$$

均将其视为期限

$$
\mathrm{T}\in\mathbb{R}_{\geq0}
$$

上的金融资 $\cdot\dot{\bar{r}}$ 回报。例如，X 的具体形式可以是

$$
\mathsf{V}_{\mathrm{T}},\frac{\mathsf{V}_{\mathrm{T}}}{\mathsf{V}_{0}},\mathsf{V}_{\mathrm{T}}-\mathsf{V}_{0},\frac{\mathsf{V}_{\mathrm{T}}}{\mathsf{V}_{0}}-1
$$

中的任何一种，其中下标分别对应于期初 0 和期末 T。进一步地，对于某个给定的基准组合 B，X 可能形如：

$$
\begin{array}{rl}&{\underbrace{\mathrm{V_{T}}}_{\mathrm{B_{T}}},\underbrace{\mathrm{V_{T}}\mathrm{B_{0}}}_{\mathrm{V_{0}B_{T}}},\mathrm{V_{T}}-\mathrm{B_{T}},\mathrm{V_{T}}-\mathrm{V_{0}}-\mathrm{B_{T}}+\mathrm{B_{0}},\underbrace{\mathrm{V_{T}}-\mathrm{V_{0}}}_{\mathrm{B_{T}}-\mathrm{B_{0}}},}\\&{\qquad\underbrace{\mathrm{V_{T}}}_{\mathrm{B_{T}}}-1,\underbrace{\mathrm{V_{T}}}_{\mathrm{V_{0}}}-\underbrace{\mathrm{B_{T}}}_{\mathrm{B_{0}}},\underbrace{\mathrm{V_{T}}-\mathrm{V_{0}}}_{\mathrm{V_{0}}}\underbrace{\mathrm{B_{0}}}_{\mathrm{B_{T}}-\mathrm{B_{0}}}}\end{array}
$$

本报告的主要研究对象是满足如下形式的回报风险比率：

$$
\alpha(\mathrm{X})=\theta(\mathrm{X})^{+}/\rho(\mathrm{X})^{+}
$$

$$
\theta,\rho;\mathcal{X}\mathbb{R}\cup\{\pm\infty\}
$$

分别称为回报测度和风险测度，分子和分母上的加号

$$
\mathbf{x}^{+}=\mathrm{max}(\mathbf{x},0)=x\lor0
$$

为正向截断函数。相似地，我们可以定义

$$
\mathbf{x}^{-}=-\operatorname*{min}(\mathbf{x},0)=-(x\wedge0)
$$

特别地，为了使得 X 的具体形式都是良定义的，我们约定

$$
{\frac{\infty}{\infty}}=0={\frac{0}{0}}
$$

本报告的回报风险比率必须满足如下公理：

（M）单调性（monotonicity）： $\mathbf{X},\mathbf{Y}\in{\mathcal{X}},\mathbf{X}\geq\mathbf{Y}\Rightarrow\mathbf{\alpha}\mathbf{\alpha}(\mathbf{X})\geq\mathbf{\alpha}\mathbf{\alpha}(\mathbf{Y})$

（Q） 拟 凹 性（ quasi-concavity）： $\mathbf{X},\mathbf{Y}\in{\mathcal{X}},\lambda\in[\mathbf{0},1]\Rightarrow\alpha(\lambda\mathbf{X}+(1-$ ${\mathfrak{A}})\mathbf{Y})\geq\mathbf{\pmb{\alpha}}(\mathbf{X})\wedge\mathbf{\pmb{\alpha}}(\mathbf{Y})$

简单来说，单调性意味着在收益层面多优于少，拟凹性意味着在风险层面鼓励分散。特别地，拟凹性对应的风险厌恶意味着此时的回报风险比率更加关注平均值而非极端值，参考 Schmeidler（1989），Cerreia-Vioglioet al.（2011）或者 Drapeau and Kupper（2013）。否则，对于非拟凹的业绩评价指标，将会导致风险的集中而非分散，参见 Artzneret al.（1999）。

而在既有的文献中，许多回报风险比率还满足

（ S） 数 乘 不 变 性 （ scale-invariance ）： $\mathbf{X}\in{\mathcal{X}},\lambda\in(\mathbf{0},\infty),\lambda\mathbf{X}\in{\mathcal{X}}\Rightarrow$ ${\pmb{\alpha}}(\pmb{\lambda}\mathbf{X})={\pmb{\alpha}}(\mathbf{X})$

（D）唯分布依赖性（distribution-based）:X $\in{\mathcal{X}}\Rightarrow\alpha(\mathbf{X})=\mathbf{\alpha}\mathbf{\alpha}\mathbf{(F_{X})}$ ，其中$\mathbf{F}_{\mathbf{X}}\colon\mathbb{R}\to[\mathbf{0},\mathbf{1}]$ 是随机变量 X的累计分布函数。

需要指出的是，（S）性质虽然能够在一定程度上简化计算，但是回报风险比率与回报的大小无关这一性质，其实既无经济学的解释也无决策论的支撑。Chernyand Madan（2009）对单调的、拟凹、数乘不变度量给出了一个刻画。而性质（D）则是一个比较自然的“信仰”：如果我们将观察数据得到的经验分布视为真实的话，参见 Beutner and Zahle（2010），Pflug and Wozabal（2010）或者 Belomestny and Kratschmer（2012）。但对于很多金融场景，不确定事件的概率分布是未知的，因此模型的参数估计与其追求准确，不如采用更加稳健的方法考虑参数的动态匹配问题。对于上述情况，追求唯分布依赖性是没有道理的。

利用回报风险比率同回报测度以及风险测度的关系，可以得到：

命题 I：设

$$
\mathfrak{\alpha}(-)=\mathfrak{\theta}(-)^{+}/\mathfrak{p}(-)^{+}
$$

$$
\lambda>\mathbf{0},\{\mathbf{X},\mathbf{Y},\lambda\mathbf{X}\}\subset\mathcal{X}
$$

1. 取 $\mathbf{X}{\geq}\mathbf{Y},$ ，如果始终有 ${\mathfrak{\mathbf{\theta}}}(\mathbf{X}){\ge}{\mathfrak{\mathbf{\theta}}}(\mathbf{Y})$ 而且 $\mathbf{\rho}(\mathbf{X}){\leq}\mathbf{\rho}(\mathbf{Y})$ ，那么α满足单调性（M）。

2. 如果 θ 凹 ρ 凸，那么 α满足拟凹性（Q）。

3. 如果 $\scriptstyle\mathbf{p}(\lambda\mathbf{X})=\lambda\mathbf{p}(\mathbf{X}),\mathbf{\theta}(\lambda\mathbf{X})=\lambda\mathbf{\theta}(\mathbf{X})$ ，那么 α满足数乘不变性（S）。

4. 如果 $\mathbf{\rho},\mathbf{\theta}$ 满足（D），那么α 满足唯分布依赖性（D）。

证明：1、3、4 是直接的结论，下面仅证明 2。如果

$$
\alpha(\mathrm{X})\wedge\alpha(\mathrm{Y})=0
$$

那么结论自然成立，否则

$$
\alpha(\mathrm{X})\wedge\alpha(\mathrm{Y})>0\Rightarrow\Theta(\mathrm{X})\wedge\Theta(\mathrm{Y})>0\Rightarrow\Theta(\mathrm{X}),\Theta(\mathrm{Y})>0
$$

而利用θ的凹性可以得到：

$$
\begin{array}{rl}&{\qquad\Theta(\lambda\mathrm{X}+(1-\lambda)\mathrm{Y})^{+}\geq\bigl(\lambda\Theta(\mathrm{X})+(1-\lambda)\Theta(\mathrm{Y})\bigr)^{+}=\lambda\Theta(\mathrm{X})^{+}+(1-\lambda)\Theta(\mathrm{Y})^{+}}\\&{=\lambda\alpha(\mathrm{X})\mathrm{\rho}(\mathrm{X})^{+}+(1-\lambda)\alpha(\mathrm{Y})\mathrm{\rho}(\mathrm{Y})^{+}\geq\bigl(\alpha(\mathrm{X})\wedge\alpha(\mathrm{Y})\bigr)(\lambda\mathrm{\rho}(\mathrm{X})^{+}+(1-\lambda)\mathrm{\rho}(\mathrm{Y})^{+})}\\&{\geq\bigl(\alpha(\mathrm{X})\wedge\alpha(\mathrm{Y})\bigr)\bigl(\lambda\mathrm{\rho}(\mathrm{X})+(1-\lambda)\mathrm{\rho}(\mathrm{Y})\bigr)^{+}\geq\bigl(\alpha(\mathrm{X})\wedge\alpha(\mathrm{Y})\bigr)\bigl(\lambda\mathrm{\rho}(\lambda\mathrm{X}+(1-\lambda)\mathrm{Y})\bigr)^{+}}\end{array}
$$

## 4. 三类回报风险比率

本节将引入三类回报风险比率，它们之间的关系是

$$
132\div3=\square\overrightarrow{AB}\bot\overrightarrow{AB}\bot\overrightarrow{AB}\bot\overrightarrow{AB}\bot\textnormal{(RRR)C(M)\cap(Q)}
$$

$$
\Zmathring{\ J}\le\ Z\mathring{\|}\ Z\mathring{\pm}\ \dotsc\ Z\in\ Z\mathring{\mp}\ \left(\mathrm{RER}\right)\subset\left(\textbf{ M }\right)\ \cap\ \left(\textbf{ Q }\right)\ \cap\ \left(\textbf{ S }\right)
$$

畸变回报风险比率（DRRR）⊂（M）∩（Q）∩（S）∩（D）

## 4.1. 稳健回报风险比率（robustRRRs）

假设 ${\mathcal{P}},{\mathcal{Q}}.$ 是两个非空的概率测度，且关于ℙ绝对连续。定义

$$
\displaystyle\theta(\mathrm{X})=\operatorname*{inf}_{\mathbb{Q}\in\mathcal{P}}\mathbb{E}_{\mathbb{Q}}[\mathrm{X}],\mathrm{\mathrm{,~}}\mathrm{}\mathrm{}\mathrm{,~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}\mathrm{~}
$$

此时需要适当选择X使得所有的期望存在且有限。此时

$$
\theta{:}\mathcal{X}\{-\infty\}\cup\mathbb{R}
$$

显然是满足（M）+（S）的凹函数；而

$$
{\rho}{:}\mathcal{X}\mathbb{R}_{\geq0}\cup\{\infty\}
$$

为凸函数，并且满足

$$
\mathtt{X}\ge\mathtt{Y}\Rightarrow\rho(\mathrm{X})\le\rho(\mathrm{Y})
$$

根据命题 I，我们知道回报风险比率满足（M）+（Q）

$$
\alpha(\mathrm{X})=\frac{\left(\underset{\mathbb{Q}\in\mathcal{P}}{\operatorname*{inf}}\mathbb{E}_{\mathbb{Q}}[\mathrm{X}]\right)^{+}}{\underset{\mathbb{Q}\in\mathcal{Q}}{\operatorname*{sup}}\big(\mathbb{E}_{\mathbb{Q}}[((\mathrm{m}-\mathrm{X})^{+})^{\mathrm{p}}]\big)^{\beta/\mathrm{p}}}\Rightarrow\alpha\in\left(\mathrm{M}\right)\cap\left(\mathrm{Q}\right)
$$

此类回报风险比率被称为稳健回报风险比率（RRRR）。可以证明

$$
\begin{array}{rl}&{\mathrm{(~a_)}~\mathcal{P}=\mathcal{Q}=\{{\mathbb P}\}\Rightarrow\alpha\in\mathrm{(M)}\cap\mathrm{(Q)}\cap\mathrm{(D)}}\\&{\mathrm{(~b_)}~\mathrm{m}=0,\beta=1\Rightarrow\mathrm{\rho}(\lambda\mathrm{X})=\lambda\mathrm{\rho}(\mathrm{X})\Rightarrow\alpha\in\mathrm{(M)}\cap\mathrm{(Q)}\cap\mathrm{(S)}}\end{array}
$$

Sortino and Satchell（2001）引入的 Sortino-Satchell 比率（Sortino-Satchellratio）就满足（a）+（b），形如

$$
\mathrm{SSR}(\mathrm{X}){:=}(\mathbb{E}[\mathrm{X}])^{+}/\|\mathrm{X}^{-}\|_{\mathrm{p}},\mathrm{p}\geq1
$$

该指标满足 $(\mathbf{M})+(\mathbf{Q})+(\mathbf{S})+(\mathbf{D})\ l_{\circ}\ \mathbf{p}\ l=1$ 时的特例，即是 Bernardoand Ledoit（2000）引入的得失比率（gains-loss ratio，GLR）。需要注意的是，（a）其实定义了广义的 Sortino-Satchell比率，其中 m 代表了收益的平移， $\beta>1$ 则给出了风险测度的一个凸畸变（distortion）。

在（b）中，如果分子和分母取不同的概率测度，可以得到：

$$
\alpha_{\mathcal{P},\mathcal{Q}}(\mathrm{X})=\left(\underset{\mathbb{Q}\in\mathcal{P}}{\operatorname*{inf}}\mathbb{E}_{\mathbb{Q}}[\mathrm{X}]\right)^{+}/\underset{\mathbb{Q}\in\mathcal{Q}}{\operatorname*{sup}}\mathbb{E}_{\mathbb{Q}}[\mathrm{X}^{-}]
$$

在金融学的解释上，分子端的概率测度反映的是不同投资者的信念， $\bar{\hbar}$ 分母端的概率测度了反映了不同的压力场景。

表 1：稳健回报风险比率的性质

|  | $\mathbf{\Omega}(\mathbf{\Omega}\mathbf{M}\mathbf{\Omega})$ | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- |
| RRRR | $\checkmark$ | $\checkmark$ |  |  |
| $\textbf{ ( a ) }$ | $\checkmark$ | $\checkmark$ |  | $\checkmark$ |
| (b) | $\checkmark$ | $\checkmark$ | $\checkmark$ |  |
| SSR | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| GLR | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\checkmark$ |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

## 4.2. 稳健期望比率（robust expectations ratio）

与稳健回报风险比率不同的是，稳健期望比率（RER）形如

$$
\alpha_{\mathcal{P},\mathcal{Q}}(\mathrm{X})=\left(\operatorname*{inf}_{\mathbb{Q}\in\mathcal{P}}\mathbb{E}_{\mathbb{Q}}[\mathrm{X}]\right)^{+}/\left(\operatorname*{sup}_{\mathbb{Q}\in\mathcal{Q}}\mathbb{E}_{\mathbb{Q}}[-\mathrm{X}]\right)^{+}
$$

此时的回报风险比率满足 $(\mathbf{M})+\left(\mathbf{Q}\right)+\left(\mathbf{S}\right)$

表 2：稳健期望比率的性质

|  | (M) | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- |
| RER | $\checkmark$ | $\checkmark$ | $\checkmark$ |  |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

## 4.3. 畸变回报风险比率（distortion RRRs）

对于一个概率分布函数测度，我们定义畸变函数

$$
\varphi\colon[0,1]\to[0,1],\mathbb{P}_{\varphi}[\mathrm{A}]:=\varphi(\mathbb{P}[\mathrm{A}]),\forall\mathrm{A}\in\mathcal{F}
$$

再定义畸变期望（distorted expectation）作为 Choquet 积分如下：

$$
\mathbb{E}_{\varphi}[\mathrm{X}]=\int_{0}^{\infty}\mathbb{P}_{\varphi}[\mathrm{X}>\mathrm{t}]\mathrm{dt}+\int_{-\infty}^{0}(\mathbb{P}_{\varphi}[\mathrm{X}>\mathrm{t}]-1)\mathrm{dt}
$$

可以证明

(i) $\mathrm{X}\geq\mathrm{Y}\Rightarrow\mathbb{E}_{\varphi}\left[\mathrm{X}\right]\geq\mathbb{E}_{\varphi}\left[\mathrm{Y}\right]$

(ii) $\lambda\geq0\Rightarrow\mathbb{E}_{\varphi}\left[\lambda\mathrm{X}\right]=\lambda\mathbb{E}_{\varphi}\left[\mathrm{X}\right]$

(iii) ${\mathrm{m}}\in\mathbb{R}\Rightarrow\mathbb{E}_{\varphi}[\mathrm{X}+{\mathrm{m}}]=\mathbb{E}_{\varphi}[\mathrm{X}]+{\mathrm{m}}$

(iv) $\exists\mathrm{f}(\mathbb{E}_{\varphi}[\mathrm{X}]=\mathrm{f}(\mathrm{F}_{\mathrm{X}}))$ ，即唯分布依赖性。

(v) 若 $\varphi.$ 是凸函数，那么 $\mathbb{E}_{\varphi}$ 是凹函数，并且

$$
\mathbb{E}_{\varphi}\left[\mathrm{X}\right]=\operatorname*{inf}_{\mathbb{Q}\in\mathcal{P}_{\varphi}}\mathbb{E}_{\mathbb{Q}}\left[\mathrm{X}\right],\mathcal{P}_{\varphi}:=\left\{\mathbb{Q}:\mathbb{Q}\left[\boldsymbol{A}\right]\leq\mathbb{P}_{\varphi}\left[\boldsymbol{A}\right],\forall\boldsymbol{A}\in\mathcal{F}\right\}
$$

(vi) 若 $\varphi$ 是凹函数，那么 $\mathbb{E}_{\varphi}$ 是凸函数，并且

$$
\mathbb{E}_{\varphi}\left[\mathrm{X}\right]=\operatorname*{inf}_{\mathbb{Q}\in\mathcal{Q}_{\varphi}}\mathbb{E}_{\mathbb{Q}}\left[\mathrm{X}\right],\mathcal{Q}_{\varphi}:=\left\{\mathbb{Q}:\mathbb{Q}\left[\boldsymbol{A}\right]\geq\mathbb{P}_{\varphi}\left[\boldsymbol{A}\right],\forall\boldsymbol{A}\in\mathcal{F}\right\}
$$

证明参见 Schmeidler（1985）、Denneberg（1997）或者 Delbaen（2002）。因此一旦选择凸的畸变函数 $.\varphi$ 和凹的畸变函数ψ，那么对应的畸变回报风险比率（DRRR）

$$
\begin{array}{r}{\alpha_{\varphi,\psi}(\mathrm{X})=\big(\mathbb{E}_{\varphi}\left[\mathrm{X}\right]\big)^{+}/\big(\mathbb{E}_{\Psi}[-\mathrm{X}]\big)^{+},\mathrm{X}\in\mathcal{X}}\end{array}
$$

就满足（M）+（Q）+（S）+（D）。而从(v)和(vi)可以得到，畸变回报风险比率都是稳健期望比率。

特别地，对于φ = id的情况，有一些比较有名的例子：

- Wang（1995）的比例风险变换（proportional hazard transform，PHT）：

$$
\Psi^{\mathrm{(x)}}=\mathbf{x}^{1/\gamma},\gamma\geq1
$$

该方法将增加较高损失的比重。

- Wang（2000）的 Wang 变换：

$$
\Psi^{\mathrm{(x)}}=\Phi(\Phi^{-1}({\mathrm{x}})+\gamma),\gamma\geq0
$$

- 其中Φ是标准的正态分布的累计分布函数。该方法同样将增加较高损失的比重。例如

$$
\mathrm{X}\sim\mathrm{N}(\mu,\sigma)\Rightarrow\mathbb{E}_{\psi}[-\mathrm{X}]\sim\mathrm{N}(\mu-\sigma\gamma,\sigma)
$$

- Cherny and Madan（2009）的 MINVAR 畸变函数：

$$
\Psi^{\mathrm{(x)}}=1-(1-\mathrm{x})^{1+\gamma},\gamma\geq0
$$

可以证明当γ ∈ ℕ时：

$$
\mathbb{E}_{\Psi}[-\mathrm{X}]=\mathbb{E}\big[-\operatorname*{min}\big\{\mathrm{X}_{1},\mathrm{X}_{2},\dots,\mathrm{X}_{\gamma+1}\big\}\big],\mathrm{X}_{\mathrm{i}}\sim_{\mathrm{iid}}\mathrm{~X~}
$$

- Cherny and Madan（2009）的 MINMAXVAR 畸变函数：

$$
\Psi(\mathbf{x})=1-\left(1-\mathbf{x}^{\frac{1}{1+\gamma}}\right)^{1+\gamma},\gamma\geq0
$$

可以证明当γ ∈ ℕ时

$$
\mathbb{E}_{\Psi}[-\mathrm{X}]=\mathbb{E}\big[-\operatorname*{min}\big\{\mathrm{Z}_{1},\mathrm{Z}_{2},\dots,\mathrm{Z}_{\gamma+1}\big\}\big]
$$

并且此时满足

$$
\mathrm{max}\{\mathrm{Z}_{1},\mathrm{Z}_{2},\dots,\mathrm{Z}_{\gamma+1}\}\sim\mathrm{X}
$$

表 3：畸变回报风险比率的性质

|  | (M) | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- |
| DRRR | √ | √ | √ | √ |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

更进一步，下一节的许多例子都可以写成畸变回报风险比率的形式，特

别是 VaR 和平均 VaR（average VaR）。关于畸变回报风险比率的更多信息，可以参考 Sereda et al.（2010）。

## 5. 更多的例子

## 5.1. 均值偏差比率（mean-deviation ratios）

最典型的均值偏差（MDR）比率莫过于 Sharpe 比率（SR）

$$
\mathrm{SR}(\mathrm{X})=(\mathbb{E}[\mathrm{X}])^{+}/\sigma(\mathrm{X})
$$

$$
\boldsymbol{\sigma}(\mathrm{X})=\|\mathrm{X}-\mathbb{E}[\mathrm{X}]\|_{2}
$$

Rockafellar et al.（2006）引入了一族偏差测度：

$$
\mathcal{D}{:}\mathrm{L}^{2}\mathbb{R}_{\ge0}\cup\{+\infty\}
$$

满足如下公理

（D1） $\mathbf{X}\in\mathbf{L}^{2},\mathbf{m}\in\mathbb{R}\Rightarrow\pmb{\mathcal{D}}(\mathbf{X}+\mathbf{m})=\pmb{\mathcal{D}}(\mathbf{X})$

（D2） $\mathbf{X}\in\mathbf{L}^{2},\lambda\in\mathbb{R}_{>0}\Rightarrow\pmb{\mathcal{D}}(\mathbf{0})=\mathbf{0},\pmb{\mathcal{D}}(\lambda\mathbf{X})=\lambda\pmb{\mathcal{D}}(\mathbf{X})$

（D3） $\mathbf{X},\mathbf{Y}\in\mathbf{L}^{2}\Rightarrow{\mathcal{D}}(\mathbf{X}+\mathbf{Y})\leq{\mathcal{D}}(\mathbf{X})+{\mathcal{D}}(\mathbf{Y})$

（D4） $\mathbf{X}\equiv\mathbf{c}\in\mathbb{R}\Rightarrow\pmb{\mathcal{D}}(\mathbf{X})=\mathbf{0},\mathbf{X}\not\equiv\mathbf{c}\in\mathbb{R}\Rightarrow\pmb{\mathcal{D}}(\mathbf{X})>\mathbf{0}$

显然，任意给定一个偏差测度，就会得到一个相应的均值偏差比率

$$
\alpha_{\mathcal{D}}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/\mathcal{D}(\mathrm{X})
$$

此时的均值偏差测度满足（Q）+（S）。更进一步地，我们有

定理 设 $\mathbf{\Delta}\cdot\mathbf{p}\in[1,\infty]$ ，函数θ: $\mathbf{L}^{\mathbf{p}}\mathbb{R}\cup\{\pm\infty\}$ 满足

$$
\mathbf{X}\in\mathbf{L}^{\mathbf{p}},\mathbf{m}\in\mathbb{R},\lambda\in\mathbb{R}_{>0}\Rightarrow\mathbf{\theta}(\mathbf{X}+\mathbf{m})=\mathbf{\theta}(\mathbf{X}),\mathbf{\theta}(\lambda\mathbf{X})=\lambda\mathbf{\theta}(\mathbf{X})
$$

如果偏差测度 $\pmb{\mathcal{D}}\colon\mathbf{L}^{\mathbf{p}}\mathbb{R}_{\geq\mathbf{0}}\cup\{+\infty\}$ 满足（D1）+（D2），那么一定存在 ${\bf Z}\geq$ $\mathbf{0},\mathbf{\boldsymbol{\Theta}}(\mathbf{Z})\in\mathbb{R}_{\geq0},\mathbf{\mathcal{D}}(\mathbf{Z})>\mathbf{0}$ 使得回报风险比率 ${\bf{\sigma}}\bullet({\bf{X}})={\bf{\sigma}}{\bf{\otimes}}({\bf{X}})^{+}/{\pmb{\mathcal{D}}}(\bf{X})$ 违背单调性（M）。

证明：假设 $\mathrm{Z}\in\mathrm{L}^{\mathrm{p}},\mathrm{Z}\geq0,\theta(\mathrm{Z})\in\mathbb{R}_{\geq0},\mathcal{D}(\mathrm{Z})\in\mathbb{R}_{>0}$ 。选择常数 $^{\mathrm{a,b,c>0}}$ ，满足 $\mathrm{a{>}c,b{>}l,bc{>}a}$ ，定义 $\scriptstyle\mathrm{X=a+bZ,Y=c+Z}.$ ，于是有 $\mathrm{X}{>}\mathrm{Y},$ ，但是

$$
\alpha(\mathrm{X})=\frac{\mathbb{E}[\mathrm{X}]}{\mathcal{D}(\mathrm{X})}=\frac{\mathrm{a}+\mathrm{b}\mathbb{E}[\mathrm{Z}]}{\mathrm{b}\mathcal{D}(\mathrm{Z})}<\frac{\mathrm{c}+\mathbb{E}[\mathrm{Z}]}{\mathcal{D}(\mathrm{Z})}=\frac{\mathbb{E}\left[\mathrm{Y}\right]}{\mathcal{D}(\mathrm{Y})}=\alpha(\mathrm{Y})
$$

这表明回报风险比率会违反（M）。

显然，我们可以更换 Sharpe 比率分母中的标准差为

$$
\begin{array}{r}{\sigma_{\mathrm{p}}(\mathrm{X})=\Vert\mathbb{E}[\mathrm{X}]-\mathrm{X}\Vert_{\mathrm{p}}\enspace\stackrel{\mathrm{35}}{}\enspace\enspace\sigma_{\mathrm{p}}^{-}\enspace(\mathrm{X})=\Vert(\mathbb{E}[\mathrm{X}]-\mathrm{X})^{+}\Vert_{\mathrm{p}}}\end{array}
$$

可以证明均值 p-偏差比率（mean-p-deviation ratio，MPDR）和均值 p-半偏差比率（mean-p-semi-deviation ratio，MPSDR），即

$$
(\mathbb{E}[\mathrm{X}])^{+}/\sigma_{\mathrm{p}}(\mathrm{X})\xrightarrow{\pm}\mathbb{X}\xrightarrow{\pm}\mathbf{\Gamma}(\mathbb{E}[\mathrm{X}])^{+}/\sigma_{\mathrm{p}}^{-}(\mathrm{X})
$$

都满足（Q）+（S）+（D），但 Sharpe 比率一样，它们不满足单调性（M）。该类型回报风险比率的例子包括：

Martin and McCann（1998）引入的均值标准半偏差比率（mean-standard-semi-deviation ratio，MSSDR）：(E[X])+/‖(X − E[X]) $^+\|_{2}$

Konno and Yamazaki（1991） 引入 的均值 绝对 偏差比 率（ mean-absolute-deviation ratio，MADR）：(E[X])+/E[|X − E[X]|] 和均值绝对半偏差比率（mean-absolute-semi-deviation ratio，MASDR）:(E[X])+/E $[(\mathrm{X}-\mathbb{E}[\mathrm{X}])^{+}]$

- Zakamouline and Koekebakker（2008）引入的斜调整 Sharpe 比率（skewness adjusted Sharpe ratio，SASR）：

$$
\mathrm{SASR}_{\mathrm{b}}(\mathrm{X}):=\mathrm{SR}(\mathrm{X})\sqrt{1+\frac{\mathrm{b}}{3}\cdot\mathbb{E}\left[\left(\frac{\mathrm{X}-\mathbb{E}[\mathrm{X}]}{\sigma(\mathrm{X})}\right)^{3}\right]}
$$

和调整后斜 Sharpe 比率（adjusted for skewness Sharpe ratio，ASSR）:

$$
\operatorname{ASSR}_{\mathrm{b}}(\mathrm{X}):=\operatorname{SR}(\mathrm{X}){\sqrt{1+{\frac{\mathrm{b}}{3}}\cdot\operatorname{\mathbb{E}}\left[\left({\frac{\mathrm{X}-\operatorname{\mathbb{E}}[\mathrm{X}]}{\mathrm{~o}(\mathrm{X})}}\right)^{3}\right]\cdot\operatorname{SR}(\mathrm{X})}}
$$

- Treynor and Black（1973）基于基准组合 B 引入的 Black-Treynor 比率：

$$
\mathrm{BTR}(\mathrm{X})=\frac{(\mathbb{E}[\mathrm{X}])^{+}\cdot\mathrm{Var}(\mathrm{B})}{\bigl(\mathrm{Cov}(\mathrm{X},\mathrm{B})\bigr)^{+}}
$$

表 4：均值偏差比率的性质

|  | (M) | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- |
| MDR |  | $\checkmark$ | $\checkmark$ |  |
| SR |  | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| MPDR |  | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| MPSDR |  | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| MSSDR |  | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| MADR |  | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| SASR |  |  | $\checkmark$ | $\checkmark$ |
| ASSR |  |  | $\checkmark$ | $\checkmark$ |
| BTR |  | $\boldsymbol{\mathscr{v}}$ | $\checkmark$ |  |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

其中 ASSR 虽然不满足前述定理的条件，但同样也不满足单调性。而SASR 和 ASSR 的（Q）性质反例为

$$
\begin{array}{r}{(\mathrm{X},\mathrm{Y})=\left\{\begin{array}{ll}{(4,2),\quad\mathbb{P}=0.5}\\{(-1,4),\ \mathbb{P}=0.4}\\{(-2,-4),\mathbb{P}=0.1}\end{array}\right.}\end{array}
$$

而 BTR 由于使用到了(X,B)的联合分布，当然不满足唯收益依赖性。

## 5.2. 货币风险度量型均值风险比率（meanrisk ratio）

考虑映射

$$
\rho\colon\mathrm{L}^{\mathrm{p}}\mathbb{R}\cup\{\infty\}
$$

首先列举风险度量公理如下：

（R1） $\mathbf{X}\leq\mathbf{Y}\Rightarrow\mathbf{\rho}(\mathbf{X})\geq\mathbf{\rho}(\mathbf{Y})$

（R2） $\mathbf{X}\in{\mathcal{X}},\mathbf{m}\in\mathbb{R}\Rightarrow\mathbf{\pmb{\rho}}(\mathbf{X}+\mathbf{m})=\mathbf{\rho}\mathbf{\vec{\rho}}(\mathbf{X})-\mathbf{m}$

（R3） $\mathbf{X},\mathbf{Y}\in{\mathcal{X}},\lambda\in(\mathbf{0},1)\Rightarrow\mathbf{\rho}(\lambda\mathbf{X}+(\mathbf{1}-\lambda)\mathbf{Y})\leq\lambda\mathbf{\rho}(\mathbf{X})+(\mathbf{1}-\lambda)\mathbf{\rho}(\mathbf{Y})$

（R4） $\mathbf{X}\in{\mathcal{X}},\lambda\in\mathbb{R}_{\geq0}\Rightarrow\mathbf{\boldsymbol{\mathsf{p}}}(\lambda\mathbf{X})=\lambda\mathbf{\boldsymbol{\mathsf{p}}}(\mathbf{\boldsymbol{X}})$

其中，如果满足（R1）+（R2）则称ρ为货币（monetary）风险度量，如果满足 $(\mathbf{R}\mathbf{1})+\left(\mathbf{R}2\right)+\left(\mathbf{R}3\right)$ 则称ρ为凸性（convex）风险度量，如果满足 $(\mathbf{\thinspace R1})+\left(\mathbf{\thinspace R2}\right)+\left(\mathbf{\thinspace R3}\right)+\left(\mathbf{\thinspace R4}\right)$ 则称ρ为一致（coherent）风险度量。

## 5.2.1. VaR 比率

Favre and Galeano（2002）引入了所谓 VaR 比率（VaR ratio，VaRR）

$$
\mathrm{VaRR}_{\gamma}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/\Bigl(\mathrm{VaR}_{\gamma}(\mathrm{X})\Bigr)^{+}
$$

其中 VaR 的计算公式为

$$
\operatorname{VaR}_{\gamma}(\mathrm{X})=\operatorname*{inf}\{\mathrm{m}\in\mathbb{R}\colon\mathbb{P}[\mathrm{X}+\mathrm{m}<0]\leq\gamma\},\gamma\in(0,1)
$$

众所周知的是，VaR 满足 $(\mathrm{~D~})+(\mathrm{~R1~})+(\mathrm{~R2~})+(\mathrm{~R4~})$ ，但是不满足（R3）；因此 VaRR 满足 $\left(\mathbf{M}\right)+\left(\mathbf{S}\right)+\left(\mathbf{D}\right)$ ，但是不满足（Q）。（Q）的反例如下，考虑 iid 的分布 X 和 Y

$$
\mathrm{X=Y=}\left\{\begin{array}{ll}{-30,\mathbb{P}=0.03}\\{-10,\mathbb{P}=0.03}\\{5,\mathbb{P}=0.94}\end{array}\right.
$$

令γ=0.05，可以得到

$$
\begin{array}{c}{\mathbb{E}[\mathrm{X}]=\mathbb{E}[\mathrm{Y}]=3.5}\\{\mathrm{VaR}_{\gamma}(\mathrm{X})=\mathrm{VaR}_{\gamma}(\mathrm{Y})=10,\mathrm{VaR}_{\gamma}(\mathrm{X}+\mathrm{Y})=25}\end{array}
$$

而

$$
\operatorname{VaRR}_{\gamma}\left({\frac{\mathrm{X+Y}}{2}}\right)=\operatorname{VaRR}_{\gamma}(\mathrm{X+Y})={\frac{7}{25}}<{\frac{7}{20}}=\operatorname{VaRR}_{\gamma}(\mathrm{X})\wedge\operatorname{VaRR}_{\gamma}(\mathrm{Y})
$$

## 5.2.2. 凸性风险度量型均值风险比率

凸性风险度量型的均值风险比率只满足（M）+（Q）但并不满足（S）。例如，均值熵比率（mean-entropic ratio）

$$
\mathrm{MER}_{\gamma}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/(\gamma^{-1}\ln\mathbb{E}[\exp(-\gamma\mathrm{X})])^{+}
$$

或者 Tsanakas（2009）引入的均值畸变熵比率（mean-distortion-entropicratio）

$$
\mathrm{MDER}_{\gamma,\Psi}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/\big(\gamma^{-1}\ln{\mathbb{E}_{\Psi}[\exp(-\gamma\mathrm{X})]}\big)^{+}
$$

## 5.2.3. 一致风险度量型均值风险比率

对于一致风险度量ρ而言，均值风险比率

$$
\left(\mathbb{E}[\mathrm{X}]\right)^{+}/{\bigl(}\rho(\mathrm{X}){\bigr)}^{+}
$$

满足（M）+（Q）+（S）。特别地，下面列出的例子也都满足（D）。

Martin et al.（2003）引入的稳定尾部调整收益比率（stable tail adjusted return ratio）形如

$$
\mathrm{STARR}_{\gamma}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/\left(\mathrm{AVaR}_{\gamma}(\mathrm{X})\right)^{+}
$$

$$
{\mathrm{AVaR}}_{\gamma}{\mathrm{(X)}}{\mathrm{:}}=\gamma^{-1}\int_{0}^{\gamma}{\mathrm{VaR}}_{\mathrm{u}}{\mathrm{(X)}}{\mathrm{du}},\gamma\in(0,1]
$$

为平均 VaR。

Young（1998）引入了 MiniMax 比率

$$
\mathsf{MMR}_{\gamma}(\mathrm{X})=(\mathbb{E}[\mathrm{X}])^{+}/\|\mathrm{X}^{-}\|_{\infty}
$$

Shalit and Yitzhaki（1994）引入了 Gini 比率：

$$
\mathrm{GR}_{\gamma}(\mathrm{X}):=(\mathbb{E}[\mathrm{X}])^{+}/(\Gamma_{\mathrm{X}}(\gamma)-\mathbb{E}[\mathrm{X}])^{+}
$$

$$
\Gamma_{\mathrm{X}}(\gamma):=\mathbb{E}[\mathrm{X}]-\gamma\int_{0}^{1}(1-\mathbf{u})^{\gamma-1}\mathrm{F}_{\mathrm{X}}^{-1}(\mathbf{u})\mathrm{d}\mathbf{u}\mathrm{~},\gamma>1
$$

而

$$
\Gamma_{\mathrm{X}}(\gamma)-\mathbb{E}[\mathrm{X}]
$$

为一致风险度量的证明参见 Ortobelli et al.（2006）。

表 5：货币风险度量型均值风险比率的性质

|  | $\mathbf{\Omega}(\mathbf{\Omega}\mathbf{M}\mathbf{\Omega})$ | $\mathbf{\Omega}^{(\mathrm{~Q~})}$ | $\mathbf{\Xi}(\mathbf{\Lambda}\mathbf{S\Lambda})$ | $\left(\textrm{ D }\right)$ |
| --- | --- | --- | --- | --- |
| VaRR | $\checkmark$ |  | $\checkmark$ | $\checkmark$ |
| MER | $\checkmark$ | $\checkmark$ |  | $\checkmark$ |
| MDER | $\checkmark$ | $\checkmark$ |  | $\checkmark$ |
| STARR | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| MMR | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\checkmark$ |
| GR | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\checkmark$ |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

## 5.3. 更多的非拟凹回报风险比率

Farinelli and Tibiletti（2008）引入了 Farinelli-Tibiletti 比率：

$$
\operatorname{FTR}(\mathrm{X}):=\Vert(\mathrm{X}-\mathrm{m})^{+}\Vert_{\mathrm{p}}/\Vert(\mathrm{n}-\mathrm{X})^{+}\Vert_{\mathrm{q}},\mathrm{m},\mathrm{n}\in\mathbb{R},\mathrm{p},\mathrm{q}>0
$$

该类型的指标只满足（M）+（D）。如果 m=n=0，那么此时指标还会满足（S），但始终不会满足（Q）。反例为：

$$
\left(X,Y\right)=\left\{{\overset{\left(-10,1\right),\mathbb{P}}{\left(1,3\right)}}=0.2\right.
$$

此时令 m=n=p=q=1 有

$$
\mathrm{FTR(X)}={\frac{3}{55}},\mathrm{FTR(Y)}={\frac{4}{21}}
$$

取 λ=0.75 即有

$$
\mathrm{FTR}(\lambda\mathrm{X}+(1-\lambda)\mathrm{Y})=\frac{4}{177}<\frac{3}{55}=\mathrm{FTR}(\mathrm{X})\wedge\mathrm{FTR}(\mathrm{Y})
$$

Watanabe（2006）引入了偏度峰度比率（skewness-kurtosis ratio）

$$
\operatorname{SKR}(\mathrm{X})=(\mathbb{E}[\Phi(\mathrm{X})^{3}])^{+}/\mathbb{E}[\Phi(\mathrm{X})^{4}]
$$

$$
\Phi^{\mathbf{(}\mathrm{X})}=\frac{\mathbf{\operatorname{X}}-\mathbb{E}[\mathbf{\operatorname{X}}]}{\mathbf{\operatorname{\sigma}}\sigma\mathbf{(}\mathbf{\operatorname{X}})}
$$

该指标满足（S）+（D），但是不满足 $\left(\mathbf{M}\right)+\left(\mathbf{0}\right)$ 。（M）的反例为

$$
\begin{array}{r}{\left(\mathrm{X},\mathrm{Y}\right)=\left\{\begin{array}{ll}{(3,1),\mathbb{P}=0.25}\\{(2,0),\mathbb{P}=0.5}\\{(1,0),\mathbb{P}=0.25}\end{array}\right.}\end{array}
$$

其中 $\mathrm{X}{>}\mathrm{Y}.$ ，但是

$$
\mathrm{SKR}(\mathrm{X})=0<{\frac{2\sqrt{3}}{7}}=\mathrm{SKR}(\mathrm{Y})
$$

而（Q）的反例为

$$
\begin{array}{r}{(\mathrm{X},\mathrm{Y})=\left\{\begin{array}{ll}{(-10,1),\mathbb{P}=0.5}\\{(1,3),\ \mathbb{P}=0.2}\\{(2,-1),\mathbb{P}=0.3}\end{array}\right.}\end{array}
$$

取 $\lambda{=}0.7$ 有

$$
\mathrm{SKR}(\lambda\mathrm{X}+(1-\lambda)\mathrm{Y})\approx0.0056<0.0104\approx\mathrm{SKR}(\mathrm{X})\wedge\mathrm{SKR}(\mathrm{Y})
$$

Biglova et al.（2004）引 $\lambda\vec{\textbf{ J }}$ Rachev 比率和广义 Rachev 比率（generalizedRachev ratio）：

$$
\begin{array}{rl}{\mathrm{RR}_{\mathsf{\beta},\mathsf{\gamma}}(\mathrm{X}):=\mathrm{AVaR}_{\mathsf{\beta}}(-\mathrm{X})/\mathrm{AVaR}_{\mathsf{\gamma}}(\mathrm{X})}&{}\\{\mathrm{GRR}_{\mathsf{\beta},\mathsf{\gamma},\mathsf{\delta},\mathsf{\epsilon}}(\mathrm{X}):=\mathrm{AVaR}_{\mathsf{\beta},\mathsf{\gamma}}(-\mathrm{X})/\mathrm{AVaR}_{\mathsf{\gamma},\mathsf{\epsilon}}(\mathrm{X})}&{}\end{array}
$$

$$
\mathrm{AVaR}_{\mathsf{\beta},\gamma}(\mathrm{X}):=\beta^{-1}\int_{0}^{\beta}(\mathrm{max}(-\mathrm{F}_{\mathrm{X}}^{-1}(\mathrm{u}),0))^{\gamma}\mathrm{d}\mathrm{u}
$$

Stoyanov et al. （2007） 则 $31\wedge$ 了修正广义 Rachew 比率（modifiedgeneralized Rachev ratio）：

$$
\begin{array}{r}{\operatorname{MGRR}_{\beta,\gamma,\delta,\epsilon}(\mathrm{X}):=\operatorname{AVaR}_{\beta,\gamma}(-\mathrm{X})^{\frac{1}{\gamma}}/\operatorname{AVaR}_{\gamma,\epsilon}(\mathrm{X})^{\frac{1}{\epsilon}}}\end{array}
$$

## （Q）性质的反例为

$$
\begin{array}{r}{\left(\mathrm{X},\mathrm{Y}\right)=\left\{\begin{array}{ll}{\left(-500,-1000\right),\mathbb{P}=0.02}\\{\left(4,5\right),\quad\quad\mathbb{P}=0.03}\\{\left(1,6\right),\quad\quad\mathbb{P}=0.95}\end{array}\right.}\end{array}
$$

此时有

$$
\mathrm{RR}_{0.05,0.05}\left(\frac{\mathrm{X}+\mathrm{Y}}{2}\right)=\frac{5}{429}<\frac{14}{997}=\mathrm{RR}_{0.05,0.05}\left(\mathrm{X}\right)\wedge\mathrm{RR}_{0.05,0.05}\left(\mathrm{Y}\right)
$$

表 6：非拟凹回报风险比率的性质

|  | $\mathbf{\Omega}(\mathbf{\Omega}\mathbf{M}\mathbf{\Omega})$ | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- |
| FTR | $\checkmark$ |  | $\checkmark$ | $\checkmark$ |
| SKR |  |  | $\checkmark$ | $\checkmark$ |
| RR | $\checkmark$ |  | $\checkmark$ | $\checkmark$ |
| GRR | $\checkmark$ |  |  | $\checkmark$ |
| MGRR | $\checkmark$ |  | $\checkmark$ | $\checkmark$ |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

## 5.4. 畸变表达

本节中的很多例子都可以表达为畸变回报风险比率。例如：

$$
\Psi_{\gamma}^{\mathrm{VaR}}(\mathbf{x})=\left\{{0,0\leq\mathbf{x}<\gamma\atop1,\gamma\leq\mathbf{x}\leq1}\Rightarrow\mathrm{VaR}_{\gamma}(\mathbf{X})=\mathbb{E}_{\Psi_{\gamma}^{\mathrm{VaR}}}[-\mathbf{X}]\right.
$$

$$
\Psi_{\gamma}^{\mathrm{AVaR}}(\mathbf{x})=\left\{\begin{array}{l}{\displaystyle\mathrm{x}/\gamma,0\leq\mathbf{x}<\gamma}\\{\displaystyle1,\gamma\leq\mathbf{x}\leq1}\end{array}\right.\Rightarrow\mathrm{AVaR}_{\gamma}(\mathbf{X})=\mathbb{E}_{\Psi_{\gamma}^{\mathrm{AVaR}}}[-\mathbf{X}]
$$

$$
\Psi_{\gamma}^{\mathrm{Gini}}(\mathbf{x})=(1-\mathbf{x})^{\gamma},\gamma>1\Rightarrow\Gamma_{\mathrm{X}}(\gamma)-\mathbb{E}[\mathrm{X}]=\mathbb{E}_{\Psi_{\gamma}^{\mathrm{Gini}}}[-\mathrm{X}]
$$

而修正广义 Rachev 比率则等于

$$
\begin{array}{r}{\mathrm{MGRR}_{\beta,\gamma,\delta,\epsilon}(\mathrm{X}):=\left(\mathbb{E}_{\Psi_{\mathfrak{g}}^{\mathrm{AVaR}}}[(\mathrm{X}^{+})^{\gamma}]\right)^{\frac{1}{\gamma}}/\left(\mathbb{E}_{\Psi_{\delta}^{\mathrm{AVaR}}}[((-\mathrm{X})^{+})^{\epsilon}]\right)^{1/\epsilon}}\end{array}
$$

## 5.5. 性质总结

在本报告的最后，我们将回报风险比率按照章节和性质罗列如下：

表 7：回报风险比率的性质

|  | 章节 | (M) | (Q) | (S) | (D) |
| --- | --- | --- | --- | --- | --- |
| Robust RRR | 4.1 | √ | √ |  |  |
| Sortino-Satchel ratio | 4.1 | √ | √ | √ | √ |
| Gain-loss ratio | 4.1 | √ | √ | √ | √ |
| Robust expectations ratio | 4.2 | V | √ | V |  |
| Distortion RRR | 4.3 | √ | √ | √ | √ |
| Proportional hazard transform DRRR | 4.3 | √ | √ | √ | √ |
| Wang transform DRRR | 4.3 | √ | √ | √ | √ |
| MINVAR DRRR | 4.3 | √ | V | V | √ |
| MINMAXVAR DRRR | 4.3 | √ | √ | √ | √ |
| Mean-deviation ratio | 5.1 |  | √ | √ |  |
| Sharpe ratio | 5.1 |  | √ | √ | √ |
| Mean-p-deviation ratio | 5.1 |  | √ | √ | √ |
| Mean-p-semi-deviation ratio | 5.1 |  | √ | √ | √ |
| Skewness adjusted Sharpe ratio | 5.1 |  |  | √ | √ |
| Adjusted for skewness Sharpe ratio | 5.1 |  |  | √ | √ |
| Black-Treynor ratio | 5.1 |  | √ | V |  |
| Mean-risk ratio with a monetary risk measure | 5.2 | √ |  |  |  |
| VaR ratio | 5.2.1 | √ |  | √ | √ |
| Mean-risk ratio with a convex risk measure | 5.2.2 | √ | √ |  |  |
| Mean-entropic ratio | 5.2.2 | √ | √ |  | √ |
| Mean-distortion-entropic ratio | 5.2.2 | √ | √ |  | √ |
| Mean-risk ratio with a coherent risk measure | 5.2.3 | √ | √ | √ |  |
| STAR ratio | 5.2.3 | √ | √ | √ | √ |
| MiniMax ratio | 5.2.3 | √ | √ | √ | √ |
| Gini ratio | 5.2.3 | √ | √ | √ | √ |
| Farinelli-Tibiletti ratio | 5.3 | √ |  | √ | √ |
| Skewness-kurtosis ratio | 5.3 |  |  | V | √ |
| Rachev ratio | 5.3 | V |  | √ | √ |
| Generalized Rachev ratio | 5.3 | V |  |  | V |
| Modified generalized Rachew ratio | 5.3 | √ |  | √ | √ |

数据来源：Cheridito and Kromer（2013），国泰君安证券研究

## 6. 参考文献

[1] P. Artzner, F. Delbaen, J.M. Eber and D. Heath (1999). Coherent measures of risk. Mathematical Finance 9(3), 203-228.

[2] R.J. Aumann and R. Serrano (2008). An economic index of riskiness. Journal of Political Economy 116(5), 810-836.

[3] D. Belomestny and V. Kr¨atschmer (2012). Central limit theorems for law -

invariant coherent risk measures. Journal of Applied Probability 49, 1-21.

[4] A.E. Bernardo and O. Ledoit (2000). Gain, loss, and asset pricing. Journal of Political Economy 108(1), 144-172.

[5] E. Beutner and H. Z¨ahle (2010). A modified functional delta method and its application to the estimation of risk functionals. Journal of Multivariate Analysis 101, 2452-2463.

[6] A. Biglova, S. Ortobelli, S. Rachev and S. Stoyanov (2004). Different approaches to risk estimation in portfolio theory. The Journal of Portfolio Management 31, 103-112.

[7] S. Cerreia-Vioglio, F. Maccheroni, M. Marinacci and L. Montrucchio (2011). Risk measures: rationality and diversification. Mathematical Finance, 21(4), 743-774.

[8] A. Cherny and D. Madan (2009). New measures for performance evaluation. Review ofFinancial Studies 22(7), 2571-2606.

[9] F. Delbaen (2002). Coherent risk measures on general probability spaces. in: Advances in Finance and Stochastics, Essays in Honour of Dieter Sondermann, 1-37.

[10] D. Denneberg (1997). Non Additive Measure and Integral. Dordrecht-Boston-London: Kluwer Academic Publishers.

[11] S. Drapeau and M. Kupper (2013). Risk preferences and their robust representation. Mathematics of Operations Research 38(1), 28-62.

[12] S. Farinelli and L. Tibiletti (2008). Sharpe thinking in asset ranking with one-sided measures. European Journal of Operational Research 185, 1542- 1547.

[13] L. Favre and J.A. Galeano (2002). Mean-modified Value-at-Risk optimization with hedge funds. The Journal of Alternative Investments 5, 21- 25.

[14] H. Follmer and A. Schied (2004). Stochastic Finance. An Introduction in Discrete Time. 2nd Edition. de Gruyter Studies in Mathematics 27.

[15] P. Klibanoff, M. Marinacci and S. Mukerji (2005). A smooth model of decision making under ambiguity. Econometrica 73(6), 1849-1892.

[16] H. Konno and H. Yamazaki (1991). Mean-absolute deviation portfolio optimization model and its applications to Tokyo stock market. Management Science 37, 519-531.

[17] F. Maccheroni, M. Marinacci and A. Rustichini (2006). Ambiguity aversion, robustness, and the variational representation of preferences. Econometrica 74(6), 1447-1498.

[18] P. Martin and B. McCann (1989). The Investors Guide To Fidelity Funds: Winning Strategies For Mutual Fund Investors. John Wiley & Sons.

[19] R.D. Martin, S. Rachev and F. Siboulet (2003). Phi-alpha optimal portfolios and extreme risk management. Wilmott, 70-83.

[20] S. Ortobelli, S. Rachev, H. Shalit and F. Fabozzi. (2008). Orderings and risk probability functionals in portfolio theory. Probability and Mathematical Statistics 28(2), 203-234.

[21] G. Pflug and N. Wozabal (2010). Asymptotic distribution of law -invariant risk functionals. Finance and Stochastics 14, 397-418.

[22] R.T. Rockafellar, S. Uryasev and M. Zabarankin (2006). Generalized

deviations in risk analysis. Finance and Stochastics 10, 51-74.

[23] D. Schmeidler (1985). Integral representation without additivity. Proceedings of the American Mathematical Society 97 (2), 255-261.

[24] D. Schmeidler (1989). Subjective probability and expected utility without additivity. Econometrica 57, 571-587.

[25] E.N. Sereda, E.M. Bronshtein, S.T. Rachev, F.J. Fabozzi, W. Sun and S.V. Stoyanov (2010). Distortion risk measures in portfolio optimization. Handbook of Portfolio Construction, Springer US, 649-673.

[26] H. Shalit and S. Yitzhaki (1994). Mean-Gini, portfolio theory, and the pricing of risky assets. The Journal of Finance 39(5), 1449-1468.

[27] W.F. Sharpe (1966). Mutual fund performance. The Journal of Business 39, 119-138.

[28] F.A. Sortino and S. Satchell (2001). Managing Downside Risk in Financial Markets. Butterworth-Heinemann.

[29] S. Stoyanov, S. Rachev, F. Fabozzi (2007). Optimal financial portfolios. Applied Mathematical Finance 14(5), 401-436.

[30] J.L. Treynor and F. Black (1973). How to use security analysis to improve portfolio selection. Journal of Business 46(1), 131-136.

[31] A. Tsanakas (2009). To split or not to split: capital allocation with convex risk measures. Insurance: Mathematics and Economics 44, 268-277.

[32] S.S. Wang (1995). Insurance pricing and increased limits ratemaking by proportional hazards transforms. Insurance: Mathematics and Economics 17, 43-54.

[33] S.S. Wang (2000). A class of distortion operators for pricing financial and insurance risks. The Journal of Risk and Insurance 67, 15-36.

[34] Y. Watanabe (2006). Is Sharpe ratio still effective? Journal of Performance Measurement, 11(1), 55-66.

[35] M.R. Young (1998). A minimax portfolio selection rule with linear programming solution. Management Science 44, 673-683.

[36] V. Zakamouline and S. Koekebakker (2008). Portfolio performance evaluation with generalized Sharpe ratios: beyond the mean and variance. Journal of Banking and Finance 33(7), 1242-1254.

## 本公司具有中国证监会核准的证券投资咨询业务资格

## 分析师声明

作者具有中国证券业协会授予的证券投资咨询执业资格或相当的专业胜任能力，保证报告所采用的数据均来自合规渠道，分析逻辑基于作者的职业理解，本报告清晰准确地反映了作者的研究观点，力求独立、客观和公正，结论不受任何第三方的授意或影响，特此声明。

## 免责声明

本报告仅供国泰君安证券股份有限公司（以下简称“本公司”）的客户使用。本公司不会因接收人收到本报告而视其为本公司的当然客户。本报告仅在相关法律许可的情况下发放，并仅为提供信息而发放，概不构成任何广告。

本报告的信息来源于已公开的资料，本公司对该等信息的准确性、完整性或可靠性不作任何保证。本报告所载的资料、意见及推测仅反映本公司于发布本报告当日的判断，本报告所指的证券或投资标的的价格、价值及投资收入可升可跌。过往表现不应作为日后的表现依据。在不同时期，本公司可发出与本报告所载资料、意见及推测不一致的报告。本公司不保证本报告所含信息保持在最新状态。同时，本公司对本报告所含信息可在不发出通知的情形下做出修改，投资者应当自行关注相应的更新或修改。

本报告中所指的投资及服务可能不适合个别客户，不构成客户私人咨询建议。在任何情况下，本报告中的信息或所表述的意见均不构成对任何人的投资建议。在任何情况下，本公司、本公司员工或者关联机构不承诺投资者一定获利，不与投资者分享投资收益，也不对任何人因使用本报告中的任何内容所引致的任何损失负任何责任。投资者务必注意，其据此做出的任何投资决策与本公司、本公司员工或者关联机构无关。

本公司利用信息隔离墙控制内部一个或多个领域、部门或关联机构之间的信息流动。因此，投资者应注意，在法律许可的情况下，本公司及其所属关联机构可能会持有报告中提到的公司所发行的证券或期权并进行证券或期权交易，也可能为这些公司提供或者争取提供投资银行、财务顾问或者金融产品等相关服务。在法律许可的情况下，本公司的员工可能担任本报告所提到的公司的董事。

市场有风险，投资需谨慎。投资者不应将本报告作为作出投资决策的唯一参考因素，亦不应认为本报告可以取代自己的判断。
在决定投资前，如有需要，投资者务必向专业人士咨询并谨慎决策。

本报告版权仅为本公司所有，未经书面许可，任何机构和个人不得以任何形式翻版、复制、发表或引用。如征得本公司同意进行引用、刊发的，需在允许的范围内使用，并注明出处为“国泰君安证券研究”，且不得对本报告进行任何有悖原意的引用、删节和修改。

若本公司以外的其他机构（以下简称“该机构”）发送本报告，则由该机构独自为此发送行为负责。通过此途径获得本报告的投资者应自行联系该机构以要求获悉更详细信息或进而交易本报告中提及的证券。本报告不构成本公司向该机构之客户提供的投资建议，本公司、本公司员工或者关联机构亦不为该机构之客户因使用本报告或报告所载内容引起的任何损失承担任何责任。

## 评级说明

## 1.投资建议的比较标准

投资评级分为股票评级和行业评级。

以报告发布后的 12 个月内的市场表现为比较标准，报告发布日后的 12 个月内的公司股价（或行业指数）的涨跌幅相对同期的沪深 300 指数涨跌幅为基准。

## 2.投资建议的评级标准

报告发布日后的 12 个月内的公司股价（或行业指数）的涨跌幅相对同期的沪深300 指数的涨跌幅。

|  | 评级 | 说明 |
| --- | --- | --- |
| 股票投资评级 | 增持 | 相对沪深300指数涨幅15%以上 |
|  | 谨慎增持 | 相对沪深300指数涨幅介于 5%～15%之间 |
|  | 中性 | 相对沪深300指数涨幅介于-5%～5% |
|  | 减持 | 相对沪深300指数下跌5%以上 |
| 行业投资评级 | 增持 | 明显强于沪深 300 指数 |
|  | 中性 | 基本与沪深 300指数持平 |
|  | 减持 | 明显弱于沪深 300 指数 |

## 国泰君安证券研究所

|  | 上海 | 深圳 | 北京 |
| --- | --- | --- | --- |
| 地址 | 上海市静安区新闸路 669 号博华广 | 深圳市福田区益田路6009号新世界 商务中心34层 | 北京市西城区金融大街甲9号金融 街中心南楼18层 |
| 邮编 | 场20层 200041 | 518026 | 100032 |
| 电话 | (021)38676666 | (0755)23976888 | （010)83939888 |
|  | E-mail: gtjaresearch@gtjas.com |  |  |