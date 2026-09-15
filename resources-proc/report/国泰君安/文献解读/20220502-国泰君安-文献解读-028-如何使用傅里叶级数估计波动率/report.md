inInfo][Table_Title]2022.05.02

# 如何使用傅里叶级数估计波动率

## ——精品文献解读系列（二十八）

## 本报告导读：

本文基于傅里叶分析，提供了一种全新的波动率测算方法。由于该方法基于积分而非微分，因此其不仅比来自二次变差的传统方法具有更强的稳健性，而且对高频场景的适用性也会更强，值得战略、战术配置投资者参考借鉴。

## 摘要：

投资学是一门学术界与业界紧密结合的学科，其中大类资产配置是这种紧密结合的代表。从 （ ）开创现代投资组合理论开始，学术界为业界提供了丰富的理论参考和方法模型，推动了大类资产配置实践的繁荣发展。为了帮助读者及时跟踪学术前沿，我们推出了“精品文献解读”系列报告，从大量学术文献中挑选出精品论文进行剖析解读，为读者呈现大类资产配置领域最新的思路和方法。

本篇为读者解读的文献是 Malliavin and Mancino（2002）在 Finance &Stochastics 上发表的论文“Fourier series method for measurement ofmultivariate volatilities”。

本文提出了一种针对半鞅（semi-martingale）数据的波动性测算方法，主要数学工具为傅里叶分析。该方法本质上一种无模型（model-free）的非参数（nonparametric）方法，因此具有很强的数据适应性。

本文基于傅里叶分析，提供了一种全新的波动率测算方法。由于该方法基于积分而非微分，因此其不仅比来自二次变差的传统方法具有更强的稳健性，而且对高频场景的适用性也会更强，值得战略、战术配置投资者参考借鉴。

大类资产配置研究

## hor] 报告作者

玉赵索(分析师)

8 0755-23976601

zhaosuo024832@gtjas.com

证书编号 S0880521080002

## cReport] 相关报告

如何基于PEAD超预期因子构建行业轮动策略

2022.04.26

基金重仓股当前“三重困境”深度解析

2022.04.18

如何基于景气度构建行业轮动策略——行业配置研究系列01

2022.04.12

观象析理：“政策底”后的“市场底”需季度级别的等待

2022.04.01

## 1. 文献概述

## 文献来源：

Malliavin P, Mancino M E. Fourier series method for measurement of multivariate volatilities[J]. Finance & Stochastics, 2002, 6(1):49-61.

## 文献摘要：

本文提出了一种针对半鞅（semi-martingale）数据的波动性测算方法，主要数学工具为傅里叶分析。该方法本质上一种无模型（model-free）的非参数（nonparametric）方法，因此具有很强的数据适应性。

## 文献评述：

本文基于傅里叶分析，提供了一种全新的波动率测算方法。由于该方法基于积分而非微分，因此其不仅比来自二次变差传统方法具有更强的稳健性，而且对高频场景的适用性也会更强，值得战略、战术配置投资者参考借鉴。

## 符号说明：

本文中，方括号在求和指标上视同如下集合：

$$
\left[\mathbf{d}\right]=\{1\mathbf{,}2,\ldots,\mathbf{d}\}
$$

## 2. 二次变差中的Wiener定理

二次变差（quadratic variation）的定义如下。假设函数

$$
\Phi,\Psi\colon[0,1]\to\mathbb{R}
$$

于是对任意的时间 t 可以定义

$$
\langle\phi,\psi\rangle_{\mathrm{t}}:=\operatorname*{lim}_{n\to\infty}\left(\sum_{0\leq\mathrm{k}\leq2^{n}}\left[\phi\left(\frac{\mathrm{k}+1}{2^{n}}\right)-\phi\left(\frac{\mathrm{k}}{2^{n}}\right)\right]\left[\psi\left(\frac{\mathrm{k}+1}{2^{n}}\right)-\psi\left(\frac{\mathrm{k}}{2^{n}}\right)\right]\right),\mathrm{t}\in[0,1]
$$

此时，利用 Ito 引理不难证明所谓 Wiener 定理如下：

定理 1 考虑一个实值 d 维 Brownian 运动，

$$
(\mathbf{x}^{1},\cdots,\mathbf{x}^{\mathbf{d}})
$$

则有：

$$
\left\langle\mathbf{x}^{\mathrm{j}},\mathbf{x}^{\mathrm{k}}\right\rangle_{\mathrm{t}}=\delta_{\mathrm{k}}^{\mathrm{j}}\mathrm{t},\forall\mathrm{t}\in[0,1],\forall\mathrm{j},\mathrm{k}\in[\mathrm{d}]
$$

其中 $\delta_{k}^{j}$ 仅在j=k 时为 1，其余时候为 0。

## 3. Bachelier 范式下的二次变差

所谓的 Bachelier 假设如下：

【Bachelier 假设】数据u 作为一个半鞅，其Ito微分形如：

$$
\mathbf{d}\mathbf{u}^{\mathrm{j}}=\sum_{\mathrm{i}\in[\mathrm{d}]}\alpha_{\mathrm{i}}^{\mathrm{j}}\mathbf{d}\mathbf{x}^{\mathrm{i}}+\beta^{\mathrm{j}}\mathbf{d}\mathbf{t},\forall\mathrm{j}\in[\mathrm{m}]
$$

$$
\left\{\begin{aligned}x^*=独立的&Brownian运动\\\alpha_*^*&=时变函数\\\beta^*&=时变函数\end{aligned}\right.
$$

在上述假设下可以证明

定理 2 假设函数

$$
\alpha_{\mathrm{i}}^{\mathrm{j}},\beta^{\mathrm{j}}\mathrm{:}\left[0,\mathfrak{t}\right]\rightarrow\mathbb{R}
$$

为一致有界的时变函数，那么我们几乎必然（almostsurely）有如下恒等式成立：

$$
\left\langle\mathbf{u}^{\mathrm{j}},\mathbf{u}^{\mathrm{k}}\right\rangle_{\mathrm{t}}=\int_{0}^{\mathrm{t}}\sum_{\mathrm{i}}\alpha_{\mathrm{i}}^{\mathrm{j}}(s)\alpha_{\mathrm{j}}^{\mathrm{k}}(s)\mathrm{d}s
$$

该定理的原始证明较长（参见文献原文），但利用 Ito 引理（此处我们使用了 Einstein 和号约定）在形式上直接可以“看出”:

$$
\begin{align*}\left\langle\mathsf{u}^{\mathsf{j}},\mathsf{u}^{\mathsf{k}}\right\rangle_{\mathsf{t}}=\left\langle\mathsf{a}_{\mathsf{i}}^{\mathsf{j}}\mathsf{d}x^{\mathsf{i}}+\mathsf{p}^{\mathsf{j}}\mathsf{d}\mathsf{t},\mathsf{a}_{\mathsf{i}}^{\mathsf{k}}\mathsf{d}x^{\mathsf{l}}+\mathsf{p}^{\mathsf{k}}\mathsf{d}\mathsf{t}\right\rangle_{\mathsf{t}}=\left\langle\mathsf{a}_{\mathsf{i}}^{\mathsf{j}}\mathsf{d}x^{\mathsf{j}},\mathsf{a}_{\mathsf{i}}^{\mathsf{k}}\mathsf{d}x^{\mathsf{k}}\right\rangle+\int_{0}^{\mathsf{t}}\mathcal{O}(\mathsf{d}\mathsf{t}^{3/2})\\=\int_{0}^{\mathsf{t}}\mathsf{a}_{\mathsf{i}}^{\mathsf{j}}\mathsf{a}_{\mathsf{i}}^{\mathsf{k}}\delta_{\mathsf{i}}^{\mathsf{l}}\mathsf{d}s=\int_{0}^{\mathsf{t}}\sum_{\mathsf{i}}\mathsf{a}_{\mathsf{i}}^{\mathsf{j}}(s)\mathsf{a}_{\mathsf{i}}^{\mathsf{k}}(s)\mathsf{d}s\end{align*}
$$

因此，我们称下列时变（矩阵）函数

$$
\Sigma=\left(\Sigma^{\mathrm{j},\mathrm{k}}\right)_{\mathrm{j},\mathrm{k}\in[\mathrm{m}]}\quad 其中\quad\Sigma^{\mathrm{j},\mathrm{k}}(\mathrm{t})=\sum_{\mathrm{i}}\alpha_{\mathrm{i}}^{\mathrm{j}}(\mathrm{t})\alpha_{\mathrm{i}}^{\mathrm{k}}(\mathrm{t})
$$

为（瞬时）波动率矩阵。

## 4. 多元波动率的傅里叶级数计算

定理 2 给出的波动率估计虽然在形式上是无懈可击的，但是由于依赖于微分计算，其结果并不稳健。本文采用傅里叶技术规避了这一问题。

本文首先对固定时间窗口的单半鞅情况进行分析。利用坐标变换，可以将时间窗口固定在[0,2π]之间，于是

$$
\mathrm{du}=\sum_{\mathrm{i}}\alpha_{\mathrm{i}}(\mathrm{t})\mathrm{dx}^{\mathrm{i}}+\beta\mathrm{dt},\Sigma(\mathrm{t})=\sum_{\mathrm{i}}(\alpha_{\mathrm{i}}(\mathrm{t}))^{2}
$$

本文的核心思路如下：

1. 首先计算 du 的傅里叶系数。

2. 利用 du 的傅里叶系数构造Σ的傅立叶系数。

3. 利用反演公式从Σ的傅里叶系数重建Σ。

对于 du 而言，其常数项为

$$
\mathrm{a}_{0}(\mathrm{du})=\frac{1}{2\pi}\int_{0}^{2\pi}\mathrm{du}(\mathrm{t})
$$

类似可以得到：

$$
\left\{\begin{aligned}a_{\mathrm{k}}(\mathrm{du})=\frac{1}{\pi}\int_{0}^{2\pi}\cos(\mathrm{kt})\mathrm{du}(\mathrm{t}),\\b_{\mathrm{k}}(\mathrm{du})=\frac{1}{\pi}\int_{0}^{2\pi}\sin(\mathrm{kt})\mathrm{du}(\mathrm{t}).\end{aligned}\right.
$$

由于是单半鞅情况，相应的波动率矩阵的傅里叶系数为

$$
\mathrm{a}_{0}(\Sigma)=\frac{1}{2\pi}\int_{0}^{2\pi}\Sigma(\mathrm{t})\mathrm{du}(\mathrm{t})
$$

其余的傅里叶系数为

$$
\left\{\begin{aligned}a_{k}(\Sigma)=\frac{1}{\pi}\int_{0}^{2\pi}\cos(kt)\Sigma(t)du(t),\\b_{k}(\Sigma)=\frac{1}{\pi}\int_{0}^{2\pi}\sin(kt)\Sigma(t)du(t).\end{aligned}\right.
$$

再利用 Fourier-Fejer 反演公式，有

$$
\Sigma(\mathrm{t})=\operatorname*{lim}_{\mathrm{N}\to\infty}\Sigma_{\mathrm{N}}(\mathrm{t})
$$

$$
\Sigma_{\mathrm{N}}(\mathrm{t})=\sum_{\mathrm{k}=0}^{\mathrm{N}}\left(1-\frac{\mathrm{k}}{\mathrm{N}}\right)\left(a_{\mathrm{k}}(\Sigma)\cos(\mathrm{kt})+b_{\mathrm{k}}(\Sigma)\sin(\mathrm{kt})\right)
$$

不仅如此，利用傅里叶分析中的能量估计和三角函数的和差化积公式，可以得到本文的主要结果如下。

定理 3 给定整数 $\mathbf{n}_{0}>0$ ，波动率水平的傅里叶系数满足：

$$
a_{0}(\Sigma)=\lim_{\mathrm{N}\to\infty}\frac{\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}\left(a_{\mathrm{s}}^{2}(\mathrm{du})+b_{\mathrm{s}}^{2}(\mathrm{du})\right)
$$

以及

$$
\left\{a_{\mathrm{q}}(\Sigma)=\lim_{\mathrm{N}\rightarrow\infty}\frac{2\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}a_{\mathrm{s}}(\mathrm{du})a_{\mathrm{s}+\mathrm{q}}(\mathrm{du}),\mathrm{q}>0\right\}
$$

$$
\mathrm{b}_{\mathrm{q}}(\Sigma)=\lim_{\mathrm{N}\rightarrow\infty}\frac{2\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}\mathrm{a}_{\mathrm{s}}(\mathrm{du})\mathrm{b}_{\mathrm{s}+\mathrm{q}}(\mathrm{du}),\mathrm{q}\geq0
$$

对于高维情况，则可以得到

定理 4 对于多元波动率有

$$
a_{0}\left(\Sigma^{\mathrm{ij}}\right)=\lim_{\mathrm{N}\rightarrow\infty}\frac{2\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}\frac{a_{\mathrm{s}}\left(\mathrm{du}^{\mathrm{i}}\right)a_{\mathrm{s}}\left(\mathrm{du}^{\mathrm{j}}\right)+b_{\mathrm{s}}\left(\mathrm{du}^{\mathrm{i}}\right)b_{\mathrm{s}}\left(\mathrm{du}^{\mathrm{j}}\right)}{2}
$$

以及

$$
a_{\mathrm{q}}(\mathrm{z}^{\mathrm{i},\mathrm{j}})=\lim_{\mathrm{N}\rightarrow\infty}\frac{2\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}\frac{a_{\mathrm{s}}(\mathrm{du}^{\mathrm{i}})a_{\mathrm{s}+\mathrm{q}}(\mathrm{du}^{\mathrm{j}})+a_{\mathrm{s}}(\mathrm{du}^{\mathrm{i}})a_{\mathrm{s}+\mathrm{q}}(\mathrm{du}^{\mathrm{j}})}{2},\mathrm{q}>0
$$

$$
\left[\mathrm{b}_{\mathrm{q}}(\mathrm{z}^{\mathrm{ij}})=\lim_{\mathrm{N}\rightarrow\infty}\frac{2\pi}{\mathrm{N}+1-\mathrm{n}_{0}}\sum_{\mathrm{s}=\mathrm{n}_{0}}^{\mathrm{N}}\frac{a_{\mathrm{s}}(\mathrm{du}^{\mathrm{i}})\mathrm{b}_{\mathrm{s}+\mathrm{q}}(\mathrm{du}^{\mathrm{j}})+a_{\mathrm{s}}(\mathrm{du}^{\mathrm{i}})\mathrm{b}_{\mathrm{s}+\mathrm{q}}(\mathrm{du}^{\mathrm{j}})}{2},\mathrm{q}\geq0\right.
$$

高维情况的证明是一维情况的类推，而定理 3 的证明请参考本文附录。

## 5. 数值实现

本节主要是关于上述公式数值实现的一些注记。

窗口选择

显而易见，时间窗口的选择会对傅里叶分析的结果产生影响。假设时间

窗口为长度为 2Lπ 的区间

$$
[\mathrm{t}_{0}-\mathrm{L}\cdot\pi,\mathrm{t}_{0}+\mathrm{L}\cdot\pi]
$$

对于每一个 L，都可以计算得到一个相应的波动率的傅里叶估计， $而$ 随着 L的减少，相应的估计误差将会提升。准确地说，随着观察样本的数量的增加，估计误差会按照

$$
\frac{1}{\sqrt{\mathrm{N}}}
$$

的速度进行衰减。

正定性

波动率矩阵Σ是一个正定阵，因此其傅里叶重建也应该保障这个性质不变。注意到 Fejer 反演公式的每一个部分和都是正定阵，因此最终得到的极限至少是半正定的，这一点在数值结果上也得到了验证。

连续性处理

给定如下半鞅

$$
\mathrm{du}=\alpha\mathrm{dx}+\beta\mathrm{dt}
$$

分部积分法表明

$$
a_{\mathrm{k}}(\mathrm{du})=\frac{1}{\pi}\int_{0}^{2\pi}\cos(\mathrm{kt})\mathrm{du}(\mathrm{t})=-\frac{k}{\pi}\int_{0}^{2\pi}\sin(\mathrm{kt})\mathrm{u}(\mathrm{t})\mathrm{dt}+\frac{\mathrm{u}(2\pi)-\mathrm{u}(0)}{\pi}
$$

可以看到，由于不涉及到微分计算，上述表达式具有数值稳定性（numerically stable）。但是由于观察时点总是一个有限集合，需要对真实数据进行连续性处理。此处总是设

$$
\mathbf{u}(\mathbf{t})=\mathbf{u}(\mathbf{t}_{\mathbf{i}}),\forall\mathbf{t}\in[\mathbf{t}_{\mathbf{i}},\mathbf{t}_{\mathbf{i}+1})
$$

因此在该区间段上的积分就化为

$$
\frac{k}{\pi}\int_{t_{i}}^{t_{i+1}}\sin(kt)u(t)dt=u(t_{i})\cdot\frac{k}{\pi}\int_{t_{i}}^{t_{i+1}}\sin(kt)dt=\frac{u(t_{i})}{\pi}\cdot\left(\cos(kt_{i+1})-\cos(kt_{i})\right)
$$

上述公式避免了当 k 充分大的时候可能 $产$ 生的抵消错误（即量纲相差非常大的两个数进行计算时，有时会完全忽略小量纲数的影响，例如1e15+0.2 最后得到的数仍然是 1e15）。

最大频率

对于傅里叶分析中使用的最大频率，本文给出了经验公式：

$$
\mathrm{N_{1}}=\left[\mathrm{L}/\delta\right]
$$

其中δ代表了两个观察时点的时间间隔，文中的下方括号代表取整运算。因此各个公式中的求和计算只在

$$
\mathbf{n}_{0}<\mathbf{N}_{1}
$$

时才发生。同时建议刨除 $\mathbf{n}_{0}$ 取值较小时候的项，这主要是因为其对于β较为敏感，容易引入噪声。具体来说，数值实验结果表明只需要刨除首项系数即可。本文推荐的具体数值为：

$$
\mathrm{n}_{0}\leq\mathrm{k}\leq\mathrm{J},\mathrm{n}_{0}+\mathrm{J}\leq\mathrm{N}_{1}
$$

磨光函数

虽然定理 3的计算公式允许对一个时间窗口中的任意时点进行波动率重建，但 Monte Carlo 实验表明窗口中部的准确度要高于窗口两端的准确度。为了解决这个问题，本文使用了一个紧支撑的磨光函数（smoothingfunction），其支撑集的上下端点分别落在 0 和 $2\pi$ 的领域之中:

$$
\varphi\colon[0,2\pi]\to[0,1],\mathrm{supp}(\varphi)\subset(0,2\pi)
$$

这意味着磨光修正后的傅里叶系数形如：

$$
\hat{a}_{\mathrm{k}}(\mathrm{du})=\frac{1}{\pi}\int_{0}^{2\pi}\varphi(\mathrm{t})\cos(\mathrm{kt})\mathrm{du}(\mathrm{t})
$$

计算示例

图 1 中展示的即是从 1896 到 1998 的 Dow Jones Industrial 和 Dow JonesTransportation 之间的波动率估计。相应的数据一共用 28000 条，本文将其划分为 28 段，每段包含 1000 条数据用于波动率的测算。

图 1：Fourier 波动率估计示例
![](images/b91bd7dd0015819f89a1886a411330c0272c668b80a4c20ccdddb370d2682dcd.webp)
数据来源：Malliavin and Mancino（2002）

## 6. 总结

由于传统的波动性测算方法需要数据具有规整性和同步性，因此对于呈现出病态空间分布的逐笔数据或者异步性的交易数据而言，依赖于可微条件的二次变差理论就显得力不从心。本文提供了一种基于傅里叶分析的波动率计算方法，该方法对于高频数据甚至是逐笔数据都具有很好的亲和性，这主要是因为傅里叶分析技术本质是积分而非微分，因此能提供稳健性更好的波动率估计。

## 7. 附录

本文的附录包含两部分，一部分是为不熟悉随机微分的读者阐明半鞅的定义，另一部分则是补全定理 3 的数学证明。

## 7.1. 半鞅的定义

半鞅的定义涉及到诸多概率论中的概念。

滤子（Filtration）

在数学中，一个滤子 $\mathrm{F}=\mathrm{~(F_{i})_{i\in\mathrm{I}}}$ 是一族对象满足：

$$
\mathrm{i<j\Rightarrow F_{i}\subset F_{j}}
$$

鞅（martingale）设

$$
\begin{cases}T=时间域\\\Omega=样本空间\\S=Banach空间\end{cases}
$$

随机过程

$$
\Upsilon\colon{\mathrm{T}}\times{\Omega}\to{\mathsf{S}}
$$

称为滤子F 上的关于概率ℙ的一个鞅（martingale），当且仅当：

1. $\mathrm{F}_{*}$ 是概率空间 (Ω,F,ℙ) 上的滤子。

2. Y 适应于（adapted to）F ，即对于任意的 $\mathbf{t}\in\mathrm{T,}\mathrm{Y_{t}}$ 是 $\Sigma_{\mathrm{t}}$ 可测函数。

3. 对于任意的 $\mathsf{t}\in\mathsf{T},\mathsf{Y}_{\mathsf{t}}\in\mathsf{L}^{1}(\Omega,\Sigma_{\mathsf{t}},\mathbb{P};\mathsf{S})$ ，即 $\mathbb{E}_{\mathbb{P}}(|\mathrm{Y}_{\mathrm{t}}|)<\infty$

4. 对所有的 $s<\mathfrak{t}\in$ T，以及 $\mathrm{F}\in\Sigma_{\mathrm{s}},\mathrm{E}_{\mathbb{P}}\left(\chi_{\mathrm{F}}\left(\mathrm{Y}_{\mathrm{t}}-\mathrm{Y}_{\mathrm{s}}\right)\right)=0$ ，其中 $\chi_{\mathrm{F}}$ 代表事件 F 的示性函数.

局部鞅（local martingale）

设 (Ω,F,ℙ) 为一个概率空间， $\mathbf{F}_{*}=\{\mathbf{F}_{\mathbf{t}}|\mathbf{t}\geq0\}$ 为 F 的一个滤子，

$$
\mathtt{X}\colon\left[0,\infty\right)\times\Omega\to\mathsf{S}
$$

为取值于 S 上的适应于 F 的随机过程。称 X 是F 上的一个局部鞅，如果存在 F∗—停时（stopping time）：

$$
\tau_{\mathrm{k}}{:}\Omega\to[0,\infty)
$$

使得

1. 停时满足单调性 $\mathbb{P}(\tau_{\mathrm{k}}<\tau_{\mathrm{k}+1})=1$

2. 停时满足发散性 $\mathbb{P}\left(\operatorname*{lim}_{\mathbf{k}\to\infty}\tau_{\mathbf{k}}=\infty\right)=1.$

3. 停过程（stopped process） $\mathrm{X}_{\operatorname*{min}(\mathrm{t},\tau_{\mathbf{k}})}$ 对于任意的 k 而言都是F -鞅。

Càdlàg 函数

该类型的函数又称右连左极函数，即 RCLL（right continuous with leftlimits），或者 corlol（continuous on right, limit on left)函数。常见的累积分布函数就是一类典型的 càdlàg 函数。

图 2：累计分布函数是典型的右连左极函数

数据来源：Wikipedia，国泰君安证券研究

有界变差函数（bounded variation）对于连续函数

$$
\mathrm{f}\colon[\mathsf{a},\mathsf{b}]\to\mathbb{R}^{1}
$$

二次变差被定义成为

$$
\mathrm{V}_{\mathrm{a}}^{\mathrm{b}}(\mathrm{f})=\sup_{\mathrm{P}\in\mathcal{P}[\mathrm{a},\mathrm{b}]}\sum_{\mathrm{i}=0}^{\mathrm{n}_{\mathrm{P}}-1}\left|\mathrm{f}(\mathrm{x}_{\mathrm{i}+1})-\mathrm{f}(\mathrm{x}_{\mathrm{i}})\right|
$$

$$
\mathcal{P}[\mathrm{a},\mathrm{b}]:=\left\{\mathrm{P}=\left(\mathrm{a}=\mathrm{x}_{1}<\cdots<\mathrm{x}_{\mathrm{n}_{\mathrm{P}}}=\mathrm{b}\right)\right\}
$$

为[a,b]上的全体拆分的集合。对于可微函数，则有：

$$
\mathrm{V_{a}^{b}(f)=\int_{a}^{b}|f^{\prime}(x)|dx^{\prime}}
$$

所谓有界变差函数即

$$
\mathrm{V_{a}^{b}(f)<\infty}
$$

半鞅（semi-martingale）

设 $(\Omega,\mathrm{F},(\mathrm{F}_{\mathrm{t}})_{\mathrm{t}\geq0},\mathrm{P})是\mathrm{一}$ 个已滤概率空间（filtered probability space），实值随机过程 X 称为其上的一个半鞅过程，当且仅当有如下分解：

$$
\mathrm{X_{t}=M_{t}+A_{t}}
$$

其中 M 是一个局部鞅，A 是一个局部有界变差的右连左极适应过程（adapted process of locally bounded variation）。

## 7.2. 定理 3 的证明

在 Bachelier 的范式中，被观察的历史演进（observed historical evolution）只是概率空间Ω中的一种可能。确切地讲，推动该历史演进的 Brownian运动x∗，以及对应的 $\alpha_{\mathrm{i}},\beta$ 都是在概率空间的一个采样上的实现。由于我们没有对概率空间的结构做任何的假设，因此在分析时需要引入一个对应的辅助概率空间 X。

假设 X 是该采样形成的概率空间，此处即给出了一个保概率映射：

$$
\Phi\colon\Omega\to\mathbb{X};\omega\mapsto\mathbf{x}
$$

通过决定函数（deterministic functions）

$$
\begin{array}{r}{\widetilde{\alpha}_{\mathrm{i}}(\mathsf{t})=\alpha_{\mathrm{i}}(\mathsf{\omega},\mathsf{t})}\\{\widetilde{\beta}(\mathsf{t})=\beta(\mathsf{\omega},\mathsf{t})\;.}\end{array}
$$

我们得以将历史演进表达为 X 上的随机过程

$$
\mathrm{d}\tilde{\mathfrak{u}}_{\mathrm{x}}=\sum_{\mathrm{i}}\tilde{\mathfrak{a}}_{\mathrm{i}}(\mathrm{t})\mathrm{d}\mathrm{x}^{\mathrm{i}}+\tilde{\beta}(\mathrm{t})\mathrm{d}\mathrm{t},
$$

首先注意的到是，由于三角函数构成L2[0,2π]上的正交基，因此

$$
\int_{0}^{2\pi}\tilde{\beta}^{2}(t)\mathrm{d}t=\sum_{\mathrm{k}}\left(a_{\mathrm{k}}^{2}(\tilde{\beta})+b_{\mathrm{k}}^{2}(\tilde{\beta})\right)<\infty
$$

所以对于定理 3 中的每一个等式， $\tilde{\beta}的$ 贡献都是为 0 的。因此只需要考虑 Brownian 运动的部分即可：

$$
\mathrm{d}\mathbf{v}=\mathrm{d}\tilde{\mathbf{u}}-\tilde{\boldsymbol{\beta}}\mathrm{d}\mathbf{t}
$$

若记

$$
\mathrm{C}_{\mathrm{k}}=\mathrm{a}_{\mathrm{k}}(\mathrm{dv}),\mathrm{S}_{\mathrm{k}}=\mathrm{b}_{\mathrm{k}}(\mathrm{dv})
$$

则

$$
\begin{aligned}\mathbb{E}[\mathbb{C}_{\mathrm{k}}\mathbb{C}_{\mathrm{k}+\mathrm{q}}]=&\frac{1}{\pi^{2}}\mathbb{E}\left[\int_{0}^{2\pi}\cos(\mathrm{kt})\mathrm{d}\mathrm{v}(\mathrm{t})\int_{0}^{2\pi}\cos((\mathrm{k}+\mathrm{q})\mathrm{s})\mathrm{d}\mathrm{v}(\mathrm{s})\right]\\=&\frac{1}{\pi^{2}}\int_{0}^{2\pi}\cos(\mathrm{kt})\cos((\mathrm{k}+\mathrm{q})\mathrm{t})\sum_{\mathrm{i},\mathrm{j}}\alpha_{\mathrm{i}}(\mathrm{t})\alpha_{\mathrm{j}}(\mathrm{t})\delta_{\mathrm{i}}^{\mathrm{j}}\mathrm{d}\mathrm{t}\\=&\frac{1}{\pi^{2}}\int_{0}^{2\pi}\cos(\mathrm{kt})\cos((\mathrm{k}+\mathrm{q})\mathrm{t})\sum_{\mathrm{i}}(\mathrm{q}_{\mathrm{i}})^{2}(\mathrm{t})\mathrm{d}\mathrm{t}\\=&\frac{1}{\pi^{2}}\int_{0}^{2\pi}\Sigma(\mathrm{t})\cos(\mathrm{kt})\cos((\mathrm{k}+\mathrm{q}))\mathrm{t}\mathrm{d}\mathrm{t}\\=&\frac{1}{\pi^{2}}\int_{0}^{2\pi}\Sigma(\mathrm{t})\cdot\frac{\cos(\mathrm{qt})+\cos((2\mathrm{k}+\mathrm{q}))\mathrm{t}}{2}\mathrm{d}\mathrm{t}\\=&\frac{1}{2\pi}\Big(\mathrm{a}_{\mathrm{q}}(\Sigma)+\mathrm{a}_{2\mathrm{k}+\mathrm{q}}(\Sigma)\Big)\end{aligned}
$$

注意到

$$
\|\Sigma\|_{2}^{2}=\sum_{\mathbf{k}}(\mathtt{a}_{\mathbf{k}}(\Sigma)^{2}+\mathtt{b}_{\mathbf{k}}(\Sigma)^{2})
$$

现在考虑

$$
\mathbf{U}_{\mathbf{N}}^{\mathbf{q}}=\frac{1}{\mathbf{N}}\sum_{\mathbf{k}\in[\mathbf{N}]}\mathbf{C}_{\mathbf{k}}\mathbf{C}_{\mathbf{k}+\mathbf{q}},
$$

利用三角公式可得

$$
\mathbb{E}\big[\mathrm{U}_{\mathrm{N}}^{\mathrm{q}}\big]=\mathsf{a}_{\mathrm{q}}(\Sigma)+\mathsf{R}_{\mathrm{N}}
$$

$$
|\mathrm{R}_{\mathrm{N}}|=\left|\frac{1}{\mathrm{N}}\sum_{\mathrm{k}=1}^{\mathrm{N}}a_{2\mathrm{k}+\mathrm{q}}(\Sigma)\right|\leq\frac{1}{\mathrm{N}}\|\Sigma\|_{1}\leq\frac{1}{\mathrm{N}}\sqrt{\|\Sigma\|_{2}^{2}\cdot\mathrm{N}}=\frac{1}{\sqrt{\mathrm{N}}}\|\Sigma\|_{2}
$$

注意到

$$
\begin{aligned}&\mathbb{E}\left[\left(\mathsf{U}_{\mathsf{N}}^{\mathsf{q}}\right)^{2}\right]=\frac{1}{\mathsf{N}^{2}}\mathbb{E}\left[\left(\sum_{\mathsf{k}}\mathsf{C}_{\mathsf{k}}\mathsf{C}_{\mathsf{k}+\mathsf{q}}\right)^{2}\right]=\frac{1}{\mathsf{N}^{2}}\mathbb{E}\left[\sum_{\mathsf{i},\mathsf{j}}\mathsf{C}_{\mathsf{i}}\mathsf{C}_{\mathsf{i}+\mathsf{q}}\mathsf{C}_{\mathsf{j}}\mathsf{C}_{\mathsf{j}+\mathsf{q}}\right]\\&\\\leq&\frac{1}{2\mathsf{N}^{2}}\mathbb{E}\left[\sum_{\mathsf{i},\mathsf{j}}\mathsf{C}_{\mathsf{i}}^{2}\mathsf{C}_{\mathsf{j}+\mathsf{q}}^{2}+\mathsf{C}_{\mathsf{j}}^{2}\mathsf{C}_{\mathsf{i}+\mathsf{q}}\right]=\frac{1}{\mathsf{N}^{2}}\mathbb{E}\left[\sum_{\mathsf{i},\mathsf{j}}\mathsf{C}_{\mathsf{i}}^{2}\mathsf{C}_{\mathsf{j}+\mathsf{q}}^{2}\right]=\frac{1}{\mathsf{N}^{2}}\sum_{\mathsf{i},\mathsf{j}}\mathbb{E}[\mathsf{C}_{\mathsf{i}}^{2}\mathsf{C}_{\mathsf{j}+\mathsf{q}}^{2}]\\\end{aligned}
$$

最终可以证明（需要指出的是，此处需要一定的L4边界条件，但在原文中并未提及，当然相关条件在应用场景中其实很容易满足。此处我们略去了细节讨论，具体证明读者可以参考本文的两位作者在 Malliavin andMancino（2009）中的证明）

$$
\mathbb{V}\big[\mathrm{U}_{\mathrm{N}}^{\mathrm{q}}\big]\leq\frac{1}{\mathrm{N}}\|\boldsymbol{\Sigma}\|_{2}^{2}
$$

这意味着

$$
\mathbb{E}\big[\mathbf{U}_{\mathsf{N}}^{\mathsf{q}}\big]\to\mathsf{a}_{\mathsf{q}}(\Sigma)
$$

给出了对应的估计。而对于定理 3 中剩余的等式，只需要注意到有恒等式即可：

$$
\begin{aligned}\mathbb{E}[\mathrm{S}_{\mathrm{k}}]=&\frac{1}{\pi}\Big(\mathrm{a}_{0}(\Sigma)-\mathrm{a}_{2\mathrm{k}}(\Sigma)\Big)\\\mathbb{E}\Big[\mathrm{C}_{\mathrm{k}}\mathrm{S}_{\mathrm{k}+\mathrm{q}}\Big]=&\frac{1}{2\pi}\Big(\mathrm{b}_{\mathrm{q}}(\Sigma)+\mathrm{b}_{2\mathrm{k}+\mathrm{q}}(\Sigma)\Big)\end{aligned}
$$

最后需要特别说明的是，上述方法之所以能成功主要还是因为三角函数有积化和差公式成立。如果选择的正交基不再是三角函数，例如常见的小波基，由于积化和差公式在小波分析中并不存在，因此很难得到相应版本的定理 3。

## 8. 参考文献

Malliavin P, Mancino M E. A Fourier transform method for nonparametric estimation of multivariate volatility[J]. Ann. Statist. 2009.

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
| 股票投资评级 | 增持 | 相对沪深300 指数涨幅15%以上 |
|  | 谨慎增持 | 相对沪深300指数涨幅介于 5%～15%之间 |
|  | 中性 | 相对沪深300指数涨幅介于-5%～5% |
|  | 减持 | 相对沪深300 指数下跌 5%以上 |
| 行业投资评级 | 增持 | 明显强于沪深 300 指数 |
|  | 中性 | 基本与沪深 300 指数持平 |
|  | 减持 | 明显弱于沪深 300 指数 |

## 国泰君安证券研究所

|  | 上海 | 深圳 | 北京 |
| --- | --- | --- | --- |
| 地址 | 上海市静安区新闸路669 号博华广 | 深圳市福田区益田路6009号新世界 商务中心34层 | 北京市西城区金融大街甲9号金融 街中心南楼18层 |
| 邮编 | 场20层 200041 | 518026 | 100032 |
| 电话 | (021)38676666 | (0755)23976888 | （010)83939888 |
|  | E-mail: gtjaresearch@gtjas.com |  |  |