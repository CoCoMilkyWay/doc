# 过拟合的三层陷阱:量化研究里你能用的防御技术

QuantML QuantML 2026-05-11 20:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247493843&idx=1&sn=6d4b5a3e9231475c1d761c886b1f7fd9&chksm=cf841ba71a3a302001221dc6c270db64bdba0a0f547f4220dd5f0d52b01cd63212af879b294a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247493843&idx=1&sn=6d4b5a3e9231475c1d761c886b1f7fd9&chksm=cf841ba71a3a302001221dc6c270db64bdba0a0f547f4220dd5f0d52b01cd63212af879b294a#rd)

![](assets/001.png)

  

前两天会员发过来一个策略,Sharpe 2.4,问能不能上线。我看了一眼数据切分:`sklearn.train_test_split`, `random_state=42`。

一眼过拟合，时序数据用 random split 等于把未来信息漏给训练集。可怕的地方在于:他的 LASSO 调得很认真,正则化系数也合理,模型层面挑不出毛病——但**信息层**已经被污染了,模型再正则化也救不回来。

经典 ML 教科书讲过拟合的那套(模型复杂度、偏差-方差、正则化),在量化研究里只覆盖了一部分。**量化里的过拟合至少有三张脸**:模型层、信息层、选择层。三层都漏了任何一层,Sharpe 都可能是假的。

下面按这三层展开,把每一层的防御技术过一遍,顺手讲讲哪些工具我自己用过、哪些不靠谱、哪些被高估了。

## 一、过拟合在量化里至少有三层陷阱

**第一层:模型层的过拟合**

参数太多、模型太复杂、把训练样本里的噪音也拟合进去了。这是经典 ML 教科书反复讲的那种。对应的防御技术是正则化(L1/L2/Elastic Net)、Bayesian shrinkage、Dropout、Early Stopping。

**第二层:信息层的过拟合**

模型本身可能正常,但训练集里混入了不该出现的信息——未来标签、提前公布的财报数据、用了同一区间的 label、甚至是简单的前复权。OOS 看起来很美,因为 OOS 其实不是真 OOS。对应的防御是 Walk-Forward、Purged Cross-Validation、Embargo、CPCV。

**第三层:选择层的过拟合**

每个候选模型自己都不过拟合,但你测了 1000 个,挑了最好的一个——选择本身就是过拟合。对应的防御是 multiple testing 校正(Bonferroni / Holm / BH)、Deflated Sharpe、PBO、Covariance-Penalty。

我的经验是:**80% 的"策略上线就拉胯"问题,根源在第二、三层,不在第一层**。但工具链反过来——大家最熟悉的是模型层那一套,信息层和选择层的工具反而最薄。

## 二、信息层的防御:把 leakage 的口子全部堵上

回到开头那个 `train_test_split``random_state=42` 的例子。Random split 在 IID 数据上没事,在时序数据上**直接漏数据**——训练集里包含了"未来"样本,模型偷偷学到了未来信息。

这一层的防御没什么花活,核心是工程纪律。

### 1\. Walk-Forward Analysis (WFA)

最基本的时序切分。按时间顺序滚动:

```
T = [2015 ............ 2024]WFA expanding:  Train: 2015-2019, Test: 2020  Train: 2015-2020, Test: 2021  Train: 2015-2021, Test: 2022  ...WFA rolling:  Train: 2015-2019, Test: 2020  Train: 2016-2020, Test: 2021  Train: 2017-2021, Test: 2022  ...
```

Expanding 还是 rolling 取决于你的市场假设。Expanding 假定 alpha 在历史长河里基本稳定(更多样本利大于弊);rolling 假定 alpha 会衰减,远期数据是噪音。我自己做 A股 cross-sectional alpha 默认用 rolling 5 年窗口——A股 2015 之前的市场结构跟现在差异太大,扩到 10 年以上几乎没有边际信息。

### 2\. Purged K-Fold Cross-Validation

López de Prado 在 _Advances in Financial Machine Learning_ 里强调的方法。

问题在于:**即使你用了时序切分,如果你的 label 是"未来 N 天收益",t 时刻的 label 区间是 \[t, t+N\]** 。如果训练集里有 t 时刻样本、测试集里有 t+1, t+2 ... t+N 时刻样本,**这些测试样本的 label 区间和训练样本的 label 区间重叠**。模型在训练时已经"看过"了测试集 label 涉及的那段未来——这就是 label overlap 引起的隐性 leakage。label 越长，leakage 问题越严重。

Purged K-Fold 的做法:把训练集里所有 label 区间和测试集 label 区间重叠的样本剔除。

我第一次用 Purged K-Fold 是在做 5 日 forward return 预测,N=5,K=5 折,purge 完之后**每折训练集少了大约 8% 样本**——不算多,但拿掉之后 OOS Sharpe 从 1.4 掉到 0.9。原本以为 1.4 是策略实力,实际有近一半是 label overlap 带来的虚高。

### 3\. Embargo

Purging 还不够。即使 label 区间不重叠,t 时刻的特征和 t+ε 时刻的标签可能存在 serial correlation——波动率聚类、动量延续、信息扩散。Embargo 是在 train 和 test 之间额外留出一个 buffer(典型 1-10 天,跟特征自相关长度匹配),把可能 leak 的样本进一步排除。

`mlfinlab` 的实现里 embargo 是一个 percentage of total samples 参数,默认 0.01(也就是 1%)。我自己用的时候会先算一下特征的 autocorrelation length,然后把 embargo 设到 1.5 倍 ACL。一个常见错误是 embargo 设得太小——特征里如果有 20 日移动平均之类的东西,ACL 实际可能是 20+ 天,embargo 设 1 天等于没设。

### 4\. Combinatorial Purged Cross-Validation (CPCV)

把回测期切成 N 段,枚举所有 K-fold 划分(C(N, K) 种),每个划分上跑 purged CV。最后得到很多条独立的 backtest path。CPCV 的好处是给出 Sharpe 的 **distribution**,而不是一个点估计。你能看到这个策略在多少种切分下还能赚钱。

工程上两个坑:

-   **计算量爆炸**。N=10、K=5 就是 252 个 backtest,每个都要重训。我现在跑 CPCV 一般 N=8、K=2,40 多个 path 就够看分布形状了。
    
-   **Label overlap 在高频数据上 purge 完之后训练集可能不够用**。Tick 级数据上,如果你用了 1 分钟 forward return 做 label,purge + embargo 之后训练集可能掉 30%+。这时要么换 label,要么改用其他切分。
    

### 5\. 高频策略的额外 leakage 源

这一层我自己踩过最贵的坑都在高频上。低频(月度调仓)的 leakage 比较好控制——特征工程都是日频以上的聚合,看一眼就知道有没有用未来。

高频不一样。Tick 级特征工程极容易引入 leakage:

-   用了未来 10 秒的成交量做特征(本来想算"接下来 10 秒的流动性",写错了符号)
    
-   标签用 mid price,但特征用 last trade price(成交时点错位 50-200ms)
    
-   Rolling window 用了 `pandas.rolling(window=10, center=True)`——center=True 让窗口包含未来!
    

## 三、选择层的防御:最容易被忽略的一层

模型层和信息层至少能看见。选择层的过拟合最隐蔽——很多人压根没意识到自己在做选择,因此也意识不到选择本身需要 correction。

举个最常见的场景:你的因子库有 100 个 candidate 因子,你想挑出最好的 10 个组成多因子模型。挑选过程本身就是 multiple testing。100 选 10,即使所有因子都是纯噪音,你也能挑出 IS 表现很好的 10 个。

(我在另一篇关于 PBO/DSR 的工业级检测的文章里讲过 multiple testing 的数学细节,这里只讲防御工具,不展开公式。)

### 1\. Multiple Testing 校正

三个常见方法:

-   **Bonferroni**:最保守,threshold = α/N。N=1000、α=0.05 → 0.00005。太严格,真有效的策略也被毙。
    
-   **Holm Step-Down**:Bonferroni 改进版,p-value 排序后逐步放松。控制 FWER,比 Bonferroni 更 powerful。
    
-   **Benjamini-Hochberg (FDR)**:控制 false discovery rate。FDR=5% 意味着 100 个通过检验里预期 5 个 false positive。
    

### 2\. Deflated Sharpe Ratio (DSR)

Bailey & López de Prado (2014) 的方法。校正 observed Sharpe 是否显著高于"测了 N 次能拿到的预期最大 Sharpe"。

公式核心:

其中  是纯随机情况下 N 次 trial 的预期最大 Sharpe。如果 DSR < 0,observed Sharpe 连随机预期都没达到。

我自己跑过的一个因子组合,observed Sharpe 2.1,N=1000、T=1260,SR₀ ≈ 2.38。DSR < 0,p ≈ 0.66,统计上完全不显著。后来 OOS Sharpe 0.3,印证了 DSR 的判断。

A股的负偏 + 肥尾(典型 γ₃ ≈ -0.35,γ₄ ≈ 5.2)会让 DSR 比正态假设更严格——肥尾让分母里  变大,DSR 估计值整体压低。所以 A股策略比同 Sharpe 的标普 500 策略更难通过 DSR 检验。这一条值得反复提醒自己。

### 3\. Probability of Backtest Overfitting (PBO)

López de Prado & Bailey (2012) 提的 Combinatorially Symmetric Cross-Validation (CSCV)。事后估计你选出来的"最优"策略是过拟合的概率。

具体怎么算这里就不展开了。判读上 PBO > 0.7 是红区,PBO > 0.8 几乎确定过拟合。

一个我还没自己验证的问题:CSCV 推导假设了正态分布,A股是尖峰肥尾的,这个假设违反到底会让 PBO 偏多少。看过几篇 simulation 显示重尾下偏差 < 0.05,但 demo 都是合成数据,真实 A股截面数据上我自己没系统测过。

### 4\. Covariance-Penalty(事前修正)

arXiv 1905.05023 (2019) 的思路。Sharpe 的 IS 估计有系统性偏差,直接修正这个偏差,在模型选择阶段就用 penalized Sharpe 排序。

实证:

-   Naive(直接选 Sharpe 最高):baseline
    
-   AIC 修正:ROS Sharpe 提升 20-30%
    
-   Covariance-Penalty (Imp SR / R²):**ROS Sharpe 提升 80-100%**
    

### 5\. 最有效的选择层防御:缩小搜索空间，寻找因子内在规律

技术工具上面讲了这么多,但**最有效的防御其实是缩小搜索空间以及寻找因子内在规律**——只测真正有 ex-ante 经济学逻辑的因子,不要 grid search 一万个组合。

因子的表现蕴含着可被识别、归纳的结构性规律；研究的真正价值，在于发现并总结这些规律，而非将统计误差带来的短期涨落错当成持久信号。

这一条听起来 trivial,做起来反人性。Grid search 是研究员的 comfort zone:跑机器、看结果、挑最优,流程上很顺。而**事先想清楚"我为什么相信这个因子能赚钱"**,需要建模、需要理论、需要承认自己可能想错——这是研究员的硬功夫,工具替代不了。

## 四、模型层的防御

经典 ML 的防过拟合工具在量化里仍然有用,只是要"狠一点"。

### 1\. L1 / L2 / Elastic Net

低 SNR 是金融数据的常态。股票月度收益的横截面 R² 在 5-10% 已经算高,大部分单因子模型 R² 在 1-3%。这种 SNR 下,正则化系数 λ 要比典型 ML 任务大几个量级。

我跑 LASSO 选因子的时候,`sklearn.LassoCV` 默认的 alpha 路径(1e-4 到 1)在我的因子库上几乎不收敛——必须手动指定到 1e-1 到 10 之间。一个 rule of thumb:**金融数据上 CV 选出的最优 λ,通常比你直觉上"该 regularize 多狠"还要再狠 1-2 倍**。

Elastic Net 在因子高度共线的场景(行业因子 + 风险因子的组合)更稳。L1 alone 在共线特征里会随机挑一个,batch run 之间挑出来的因子不一致——这一点我吃过亏,以为是策略不稳,后来才意识到是 L1 的特性。

### 2\. Bayesian Shrinkage

经典 portfolio optimization 里 Ledoit-Wolf 协方差 shrinkage 是个很好的例子。Markowitz MV 优化用 sample covariance 几乎一定 explosive——它会把估计噪音 amplify 到 weight 上。Shrinkage 把 sample covariance 朝着 structured target(对角阵或者 constant correlation matrix)拉,牺牲一点偏差换大幅 variance reduction。

更激进的 shrinkage 是 Black-Litterman——直接把 prior 写进去,让模型在 prior 和数据之间做 Bayesian update。在因子模型上,我会用 BL 对因子 expected return 做先验校准,避免单期数据扰动整个 portfolio。

### 3\. Early Stopping / Dropout

深度模型在量化里用得不多——因子库少于 100 个的话,深度模型容量明显过剩。但用的时候 early stopping 默认开,patience 设短一点(5-10 epoch)。金融数据的 validation loss 经常出现"局部假平稳",看起来收敛了实际后面会变差。

Dropout 在金融时序数据上效果比 CV image 任务差很多——dropout rate > 0.3 经常让训练完全无法收敛。我个人倾向用 BatchNorm + weight decay 替代 dropout,在因子学习任务上表现更稳。

这一层的工具相对成熟,坑也有人踩过了。**真正的麻烦在前两层。**

## 五、流程层的纪律

技术工具讲完了,流程纪律更重要。

### Pre-registration

学术圈这两年开始流行的做法:**跑回测之前,先写一份 pre-registration 文档**,固定下来:

-   要测试哪些 hypothesis
    
-   用哪些 cutoff
    
-   怎么定义"成功"
    
-   出现什么结果就停止研究
    

跑完之后跟 pre-registration 对照,如果偏离原计划,要明确标注。能极大降低 p-hacking 和 selective reporting。

国内量化几乎没人正式做。但**即使不正式做 pre-registration,在跑回测前先写一段"我预期会看到什么、什么算成功、什么算失败"的内部备忘**,效果也很显著。

这点其实格外重要，尤其是 Agent 架构搭建起来之后，pre-registration能够为 Agent 设立统一的运行规则。

### 三层 pipeline

把过拟合检测分散到研究流程的不同阶段:

**事前(模型选择阶段)**

-   Covariance-Penalty 排序,用 penalized Sharpe 而不是裸 Sharpe
    
-   算 MBL,看回测期是否支撑目标 Sharpe
    
-   Pre-register hypothesis 和 cutoff
    
-   强制缩小 candidate 因子数(我自己设上限 30 个)
    

**事中(回测阶段)**

-   Walk-Forward + Purged K-Fold + Embargo
    
-   CPCV 跑出 Sharpe distribution,看 5th percentile
    
-   CSCV 算 PBO,目标 < 0.5
    
-   DSR 检验,目标 > 0 且 p < 0.05
    
-   Multiple testing 校正(BH-FDR 或 Holm)
    

**事后(实盘监控阶段)**

-   Bayesian win rate decay:P(win\_rate < breakeven) > threshold 报警
    
-   Drawdown exceedance:当前 DD > 1.5 × backtest MDD
    
-   Mahalanobis OOD:市场特征超出训练分布 95% percentile
    
-   2/3 信号同时触发 → 自动 pause 策略
    

这套跑下来,我的策略上线数量从一年 8-10 个降到 2-3 个。但留下来那批,实盘和回测的差距小很多——以前 OOS Sharpe 比 IS 掉 60-70% 是常态,现在大约 20-30%。

### 自检清单

```
■ 模型层  □ 正则化强度选得够狠吗(LASSO α 至少 1e-1)  □ Bayesian shrinkage 用了吗  □ Early stopping patience 设短了吗■ 信息层  □ 时序切分用了 WFA 或 Purged K-Fold  □ Label overlap 区间 purge 了吗  □ Embargo ≥ 1.5 × 特征 ACL  □ 高频策略代码 review 过 forward-looking 特征  □ Center-window 类操作禁用了■ 选择层  □ Candidate 数量 N = ___  □ Multiple testing 校正方法 = ___  □ DSR > 0 且 p < 0.05  □ PBO < 0.5  □ Pre-registration 文档写了吗■ 流程层  □ 事前预期写下来了  □ 实盘三信号监控配好了
```

* * *

## 六、一些开放问题

以下开放问题留给大家思考讨论：

### Regime change vs 真过拟合的混淆

CSCV、Purged CV 都假定了某种数据稳态。A股 2015-2016、2020、2024 都有明显 regime shift,这让事后的过拟合判断变模糊——OOS 表现差,你怎么知道是策略过拟合还是 regime 变了?

### 高频和低频的过拟合 profile 完全不同

低频策略的过拟合源主要在选择层——因子少、参数少、样本也少,搜索空间一搜就完。

高频策略的过拟合源更多在信息层——特征工程极容易引入 leakage,而且高频特征数量大,事后定位非常痛苦。

这两类策略需要的防御技术 priority 完全不同。低频优先校正选择层,高频优先把信息层的纪律抠死。我做过几个 hybrid 策略,日内信号 + 隔夜调仓,发现两层都需要,工程难度比单一频率高一截。

下次看到 Sharpe 漂亮的策略,先问三个问题:

-   **信息层**:数据切分动了吗?Label overlap purge 了吗?
    
-   **选择层**:测了多少个 candidate?DSR 算了吗?PBO 算了吗?
    
-   **模型层**:正则化够狠吗?Bayesian prior 用了吗?
    

三层任何一层没防住,那个 Sharpe 都可能是假的。

星球里给大伙准备了一些防止过拟合的工具，欢迎获取讨论。

## 参考文献

\[1\] López de Prado, M. (2018). _Advances in Financial Machine Learning._ Wiley. 

\[2\] Bailey, D.H. & López de Prado, M. (2014). _The Deflated Sharpe Ratio._ JPM 40(5), 94-107.

\[3\] López de Prado, M. & Bailey, D.H. (2012). _The Probability of Backtest Overfitting._ 

\[4\] Ledoit, O. & Wolf, M. (2004). _A Well-Conditioned Estimator for Large-Dimensional Covariance Matrices._ JMVA 88(2), 365-411.

\[5\] arXiv:1905.05023 (2019). _Avoiding Backtesting Overfitting by Covariance-Penalties._

\[6\] Hansen, P.R. (2005). _A Test for Superior Predictive Ability._ JBES 23(4), 365-380.

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/002.jpg)