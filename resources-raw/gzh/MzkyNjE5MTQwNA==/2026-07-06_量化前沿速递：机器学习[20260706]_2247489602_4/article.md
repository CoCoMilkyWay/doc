# 量化前沿速递：机器学习\[20260706\]

shameless 量化前沿速递 2026-07-06 12:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247489602&idx=4&sn=8a00b0b81d8ea1c59e755ed80bfd6e4a&chksm=c33142b70685a836a0a849b4c888cc1ed93338665123d5eb1b0c3a88084a123f2c1a80731190#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247489602&idx=4&sn=8a00b0b81d8ea1c59e755ed80bfd6e4a&chksm=c33142b70685a836a0a849b4c888cc1ed93338665123d5eb1b0c3a88084a123f2c1a80731190#rd)

机器翻译，仅供参考！可使用微信自带翻译功能自行翻译

更多文献获取请关注公众号：量化前沿速递

获取文献链接/翻译/pdf/文章解析请加入知识星球“量化前沿速递”

![](assets/001.png)

### 

文献汇总

\[1\] Measuring Racial Disparities in Rent Growth Under Algorithmic Landlord Concentration in U.S. Metros

在美国大都市算法地主集中下衡量租金增长的种族差异

来源:ARXIV\_20260629

\[2\] How to deal with machine learning bias in economic history

如何处理经济史上的机器学习偏见

来源:ARXIV\_20260629

\[3\] Bayesian Optimization on the Equilibrium Manifold

平衡流形上的贝叶斯优化

来源:ARXIV\_20260630

\[4\] Swimming in Dark Water

在黑暗的水中游泳

来源:ARXIV\_20260630

\[5\] Translation Readiness Index

翻译准备指数

来源:ARXIV\_20260701

\[6\] Shapley in Context

Shapley在语境中

来源:ARXIV\_20260702

### 

\[1\] Measuring Racial Disparities in Rent Growth Under Algorithmic Landlord Concentration in U.S. Metros

标题:在美国大都市算法地主集中下衡量租金增长的种族差异

作者:Advay Ranade

来源:ARXIV\_20260629

链接:https://arxiv.org/pdf/2606.27525

Abstract : The 2024 Department of Justice antitrust complaint against RealPage, Inc. named five major residential REITs for coordinating algorithmic rent pricing across hundreds of thousands of apartment units in major US metropolitan areas. This paper studies whether census tract level corporate landlord concentration (CLC), measured from SEC EDGAR 10 K property filings geocoded to census tracts, the first such application in the literature, is associated with rent growth 2019 2023, and whether that association is larger in majority minority neighborhoods. Rent outcomes are measured using the Zillow Observed Rent Index (ZORI). To account for the possibility that corporate landlords preferentially locate in neighborhoods already seeing rent appreciation, all regressions control for a fully novel Algorithmic Housing Burden Index (AHBI), a composite of pre existing rent burden and market tightness from ACS data. Across 665 census tracts in ten US metropolitan areas, doubling REIT concentration is associated with 2.8 percentage points higher rent growth (p   0.086, p   0.030, HC1 robust). This association is significantly stronger in majority minority tracts. Within the same metro, high CLC majority minority tracts are associated with 5.9 percentage points higher rent growth than comparable white tracts (p   0.039). An XGBoost model predicts 44 percent of out of sample rent growth variance, with SHAP analysis independently confirming that CLC s contribution is positive in minority tracts and negative in white tracts. Taken all together, these findings provide the first tract level evidence consistent with corporate landlord concentration being associated with disproportionately higher rent growth in communities of color.

Keywords : 

Abstract :2024年司法部针对RealPage，股份有限公司的反垄断投诉列举了五家主要住宅房地产投资信托公司，负责协调美国主要大都市地区数十万套公寓的算法租金定价。本文研究了从SEC EDGAR 10 K房地产文件地理编码到人口普查区（文献中的第一个此类应用）测量的人口普查区级企业房东集中度（CLC）是否与2019-2023年的租金增长有关，以及这种关联在多数族裔社区是否更大。租金结果使用Zillow观察租金指数（ZORI）进行衡量。为了解释企业房东优先选择已经看到租金上涨的社区的可能性，所有回归都控制了一个全新的算法住房负担指数（AHBI），这是ACS数据中现有租金负担和市场紧张程度的综合。在美国十个大都市地区的665个人口普查区中，房地产投资信托基金集中度翻倍与租金增长2.8个百分点相关（p 0.086，p 0.030，HC1强劲）。这种关联在少数民族占多数的地区明显更强。在同一大都市内，CLC占多数的少数族裔地区的租金增长比可比的白人地区高5.9个百分点（p 0.039）。XGBoost模型预测了44%的样本外租金增长方差，SHAP分析独立证实了CLC在少数族裔地区的贡献是正的，在白人地区的贡献则是负的。总的来说，这些发现提供了第一个地块层面的证据，证明企业房东集中与有色人种社区不成比例的租金增长有关。

Keywords :

### 

\[2\] How to deal with machine learning bias in economic history

标题:如何处理经济史上的机器学习偏见

作者:Torben S. D. Johansen, Julius Koschnick, Christian Vedel

来源:ARXIV\_20260629

链接:https://arxiv.org/pdf/2606.28063

Abstract : Machine learning (ML) has rapidly transformed economic history, lowering costs of digitization, data linkage, and imputation, and making information in historical text usable at scale. This paper offers a practical guide to using these tools well. However, ML tools have also created new problems. Prediction errors are often systematically correlated with covariates of interest, so even highly accurate models can distort and sometimes reverse coefficients, and standard validation cannot detect this. Given that ML tools often perform worse for historical data, this problem is especially severe for the field of economic history. We also identify a solution to this problem. We show that recent debiasing methods can correct such bias for a wide class of applications, using a small, randomly sampled set of expert coded labels while retaining the efficiency of large scale prediction. We organize the field with a taxonomy of three ML tasks, survey the literature along it, and indicate where debiasing applies and where validation against proxies remains the only recourse. We close with best practice guidance on digitization, model choice, and reproducibility.

Keywords : 

Abstract :机器学习（ML）迅速改变了经济史，降低了数字化、数据链接和插补的成本，并使历史文本中的信息可大规模使用。本文为如何正确使用这些工具提供了实用的指导。然而，机器学习工具也带来了新的问题。预测误差通常与感兴趣的协变量系统相关，因此即使是高度精确的模型也会扭曲系数，有时甚至会使系数反转，而标准验证无法检测到这一点。鉴于机器学习工具在历史数据方面的表现往往较差，这个问题在经济史领域尤其严重。我们还确定了这个问题的解决方案。我们表明，最近的去偏方法可以使用一组小的、随机抽样的专家编码标签来纠正广泛应用中的这种偏差，同时保持大规模预测的效率。我们用三个机器学习任务的分类来组织这个领域，调查相关文献，并指出去偏应用的地方以及对代理的验证仍然是唯一的方法。我们以数字化、模型选择和可重复性方面的最佳实践指南结束。

Keywords :

### 

\[3\] Bayesian Optimization on the Equilibrium Manifold

标题:平衡流形上的贝叶斯优化

作者:Felix Kubler

来源:ARXIV\_20260630

链接:https://arxiv.org/pdf/2606.29299

Abstract : Computing optimal policy in heterogeneous agent economies is complicated by the possibility of multiple equilibria. We overcome this difficulty by showing that when the equilibrium manifold has a low dimensional Negishi weight parameterization, Bayesian optimization reliably finds approximate solutions and can be used to certify candidate solutions with high probability. This insight brings recent machine learning advances to bear on a core problem in macroeconomics. We apply Bayesian optimization to a dynamic economy with heterogeneous agents and climate change and compute optimal carbon taxes in this setting. Although in principle the presence of the carbon externality creates scope for multiple equilibria, we show that in an example with realistic calibration of damages competitive equilibra are most likely unique.

Keywords : 

Abstract :在异构主体经济中计算最优策略因存在多个均衡的可能性而变得复杂。我们通过证明当均衡流形具有低维根岸权参数化时，贝叶斯优化可以可靠地找到近似解，并可用于以高概率证明候选解，从而克服了这一困难。这一见解使最近的机器学习进展对宏观经济学的一个核心问题产生了影响。我们将贝叶斯优化应用于具有异质主体和气候变化的动态经济，并在这种情况下计算最优碳税。尽管原则上碳外部性的存在为多重均衡创造了空间，但我们表明，在一个对损害进行现实校准的例子中，竞争均衡很可能是独一无二的。

Keywords :

### 

\[4\] Swimming in Dark Water

标题:在黑暗的水中游泳

作者:David Imhof, Thierry Madiès, Martin Huber

来源:ARXIV\_20260630

链接:https://arxiv.org/pdf/2606.30470

Abstract : This paper analyzes the internal organization and economic effects of a bid rigging cartel in the road construction sector of the Swiss canton of Ticino, active from 1999 to 2005. Using exceptionally rich documentary evidence, we reconstruct how cartel members coordinated bids and allocated contracts under a formal agreement known as the  convention . We show that, despite the absence of side payments, the cartel implemented a cost based allocation mechanism that closely approximated the first best collusive outcome. Regression and machine learning analyses indicate that observable cost proxies systematically predict both winning bids and bid rankings. The evidence further suggests that cartel members strategically mimicked competitive bidding behavior, allowing them to evade standard econometric detection methods. Using double machine learning, we estimate average overcharges of at least 45  , and potentially substantially higher, highlighting the significant financial harm caused by this sophisticated form of collusion.

Keywords : 

Abstract :本文分析了1999年至2005年瑞士提契诺州道路建设行业操纵投标卡特尔的内部组织和经济影响。利用异常丰富的文件证据，我们重建了卡特尔成员如何根据被称为公约的正式协议协调投标和分配合同。我们发现，尽管没有附带付款，但卡特尔实施了一种基于成本的分配机制，该机制与第一个最佳合谋结果非常接近。回归和机器学习分析表明，可观察的成本代理系统地预测了中标和投标排名。证据进一步表明，卡特尔成员战略性地模仿竞标行为，使他们能够逃避标准的计量经济学检测方法。使用双机器学习，我们估计平均超额收费至少为45，甚至可能更高，突显了这种复杂形式的勾结造成的重大经济损失。

Keywords :

### 

\[5\] Translation Readiness Index

标题:翻译准备指数

作者:Paul X. McCarthy, Rasika Amarasiri, Xian Gong

来源:ARXIV\_20260701

链接:https://arxiv.org/pdf/2606.31102

Abstract : Universities, funders, investors, and policy agencies often need to identify research with translational relevance before patents, licenses, startups, or industry collaborations are visible. This study introduces the Translation Readiness Index (TRI), a text based measure evaluating a publication s semantic similarity to papers that appear in high confidence patent paper pairs. Using 20,610 publications from OpenAlex, including 9,431 publications from the Reliance on Science patent paper pairs data and 11,179 matched comparison publications, we created paper level 768 dimensional semantic embeddings from titles and abstracts with SPECTER2. After evaluating four machine learning classifiers, XGBoost achieved the highest ROC AUC (0.77). We define TRI as the model estimated probability that a publication belongs to the patent paper paired class. Linguistic analysis revealed that patent paired publications more often use an invention oriented framing, distinct from the observational language of the comparison group. External validation across University of Western Australia (UWA) publications and leading global universities demonstrated positive associations between high TRI scores and independent translational indicators. TRI provides a text based method for identifying translation ready research, though it should be interpreted as a measure of semantic proximity to patented science rather than a direct measure of realized commercialization.

Keywords : 

Abstract :大学、资助者、投资者和政策机构通常需要在专利、许可证、初创公司或行业合作可见之前，确定具有转化相关性的研究。本研究引入了翻译准备指数（TRI），这是一种基于文本的指标，用于评估出版物与高置信度专利论文对中出现的论文的语义相似性。使用OpenAlex的20610篇出版物，包括Reliance on Science专利论文对数据的9431篇出版物和11179篇匹配的比较出版物，我们使用SPECTER2从标题和摘要中创建了768维语义嵌入。在评估了四个机器学习分类器后，XGBoost获得了最高的ROC AUC（0.77）。我们将TRI定义为模型估计的出版物属于专利论文配对类别的概率。语言分析显示，专利配对出版物更经常使用以发明为导向的框架，这与对照组的观察语言不同。西澳大学（UWA）出版物和全球领先大学的外部验证表明，高TRI分数与独立翻译指标之间存在正相关关系。TRI提供了一种基于文本的方法来识别翻译就绪的研究，尽管它应该被解释为与专利科学语义接近程度的衡量标准，而不是实现商业化的直接衡量标准。

Keywords :

### 

\[6\] Shapley in Context

标题:Shapley在语境中

作者:Dangxing Chen, Pengzhan Guo

来源:ARXIV\_20260702

链接:https://arxiv.org/pdf/2607.00856

Abstract : In recent years, large language models have achieved remarkable success and have seen growing adoption in financial applications. At the same time, explainability remains critical in finance, a domain characterized by high stakes and strict regulatory requirements. Although numerous methods have been proposed to explain black box machine learning models, the majority of these approaches are designed for general purpose tasks and do not incorporate domain specific knowledge. In this work, we study the explainability of financial textual data modeled by large language models through the lens of the Shapley value. Specifically, we investigate whether Shapley based attributions align with established financial domain knowledge. Through rigorous theoretical analysis and extensive empirical evaluations, we demonstrate that Shapley values can yield explanations that are consistent with financial reasoning and can offer meaningful insights into the model s behavior in text based financial applications.

Keywords : 

Abstract :近年来，大型语言模型取得了显著的成功，并在金融应用程序中得到了越来越多的采用。与此同时，可解释性在金融领域仍然至关重要，金融领域的特点是高风险和严格的监管要求。尽管已经提出了许多方法来解释黑盒机器学习模型，但这些方法中的大多数都是为通用任务设计的，并不包含特定领域的知识。在这项工作中，我们通过Shapley值的视角研究了由大型语言模型建模的金融文本数据的可解释性。具体而言，我们研究了基于Shapley的归因是否与既定的金融领域知识相一致。通过严格的理论分析和广泛的实证评估，我们证明Shapley值可以产生与金融推理一致的解释，并可以为基于文本的金融应用中的模型行为提供有意义的见解。

Keywords :