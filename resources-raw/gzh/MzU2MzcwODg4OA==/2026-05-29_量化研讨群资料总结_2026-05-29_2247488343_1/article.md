# 量化研讨群资料总结 2026-05-29

Alpha搬运工 睿见Alpha 2026-05-29 09:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzU2MzcwODg4OA==&mid=2247488343&idx=1&sn=3733d47979ba06cda829187358eab0ab&chksm=fd1051dd12ab4598d5ecce92f11ba0fbae2f4ae9a9818a854aac0b0044472d17f62e41e26d36#rd](https://mp.weixin.qq.com/s?__biz=MzU2MzcwODg4OA==&mid=2247488343&idx=1&sn=3733d47979ba06cda829187358eab0ab&chksm=fd1051dd12ab4598d5ecce92f11ba0fbae2f4ae9a9818a854aac0b0044472d17f62e41e26d36#rd)

## QuantCode-Eval: Benchmarking Quantitative Strategy Code Reproduction from Finance Papers

**标签：** #股票、#期货、#期权、#美股、#动量策略、#均值回归、#因子投资、#波动率管理、#事件驱动策略、#系统化配置、#LLM代码生成、#量化策略复现、#基准测试、#评估框架、#AI量化

**总结：** 本文构建了 QuantCode-Eval 基准，用于评估大语言模型（LLM）将学术金融论文还原为可执行回测代码的能力，涵盖六大策略类别共30篇论文，并设计了约572个属性级别的可执行检验器（pass/fail checker）进行细粒度评估。实验表明，当前最强模型组合（Claude Opus 4.7 + Claude Code）的 pass@5 仅为43%，主要失败模式集中在时序一致性错误、论文特定公式的还原偏差以及多空方向的反转。

## PortBench: A Correlation-Aware, Full-Pipeline Benchmark for LLM-Driven Portfolio Management

**标签：** #大语言模型、#投资组合管理、#基准测试、#多资产、#股票、#债券、#大宗商品、#加密货币、#房地产、#现金等价物、#相关性分析、#压力测试、#投资者风险画像、#量化金融、#风险管理、#均值方差优化

**总结：** 本文提出 PortBench，一个涵盖六类异质资产、跨度十年的 LLM 投资组合管理评估基准，包含 6,269 道基于相关性的静态问答题和一个模拟完整决策流程的五阶段动态沙盒，并引入 CEPS（跨阶段误差传播分数）与双层相关性评分两项新指标。核心发现为：90% 的模型-投资者画像组合无法超越等权重基准，揭示了 LLM 金融知识与实际组合管理能力之间存在显著断层。

## From Knowing to Doing: A Memory-Controlled Benchmark for LLM Trading Agents on Stock Markets

**标签：** #大语言模型(LLM)、#交易智能体、#A股、#沪深300(CSI300)、#量化交易、#日频组合构建、#基准测试(Benchmark)、#数据污染控制、#记忆泄露、#Barra业绩归因、#因子投资、#选股Alpha、#Qlib、#ReAct

**总结：** 提出 KTD-FIN 这一端到端 LLM 股票交易基准,核心做两件事:一是用四级数据掩码协议(在 prompt 和工具返回中一致地匿名化股票代码与日期,并用 10 个攻击者模型做去匿名探针验证掩码有效性)来切断预训练记忆泄露;二是用 Barra 风格的横截面归因把组合收益拆解为市场、风格、选股 alpha 三部分。在 CSI300(2024–2026)上评测 10 个前沿 LLM,发现掩码会把决策理由从"品牌叙事"逼成"因子排名",且各模型表面收益主要来自被动的市场/风格暴露而非真实选股能力(10 个模型中 9 个选股 alpha 为负)。

## 情绪系数加权个股K线评分的选股策略

**标签：** #A股、#中证全指、#K线形态、#技术分析量化、#选股因子、#Kelly准则、#价量共振、#情绪因子、#多因子合成、#金融工程

**总结：** 本报告系统梳理33种传统K线形态，以各形态最优持有期下的Kelly值为依据构建离散化打分体系并叠加合成综合K线因子，再将价量共振因子横截面标准化后取反向作为情绪调整系数与K线因子相乘，最终得到情绪系数加权的复合选股因子；该因子构建的Top50等权组合在2012—2026年的回测中年化收益26.22%、信息比率1.54。

## Capital Market Assumptions and Strategic Asset Allocation Using Multi-Asset Tradable Factors

**标签：** #资产配置、#战略资产配置(SAA)、#资本市场假设(CMA)、#多资产、#可交易因子、#因子模型、#风险溢价、#因子载荷、#HCGL、#均值方差优化、#Black\-Litterman、#期望收益估计、#协方差矩阵、#alpha\-beta一致性、#估计误差、#bootstrap、#股票、#利率债、#信用、#商品、#私募股权、#外汇、#多货币组合、#P\-CAEY、#机构组合管理

**总结：** 提出 MATF-CMA 框架:把每个资产的预期收益拆解为「HCGL 估计的因子载荷 × 九个可交易因子的市场隐含风险溢价」,并让同一个载荷矩阵同时进入协方差模型,从构造上保证预期收益与风险模型的 alpha-beta 一致性,定位为 Black-Litterman 架构的前瞻、估值敏感型替代方案。两个核心成果是:把有效前沿的抽样不确定性相对样本均值法约缩小 2 倍(等价于约 4 倍历史样本),并给出一个与模型无关的 alpha-beta 一致性诊断指标。

## Harvesting Factor Premia Across Regimes: A Hidden Markov Framework for Dynamic Multifactor Allocation

**标签：** #因子溢价、#多因子投资、#美股、#制度切换（Regime Switching）、#动态资产配置、#Smart Beta、#隐马尔可夫模型（HMM）、#高斯混合模型（GMM）、#均值方差优化、#Ledoit\-Wolf协方差收缩、#换手率约束、#因子择时、#VIX、#CAPE

**总结：** 将 Botte & Bao(2021) 的静态 GMM 制度分类扩展为高斯隐马尔可夫模型，估计状态持续性与转移矩阵，再把滤波后的状态概率经转移矩阵向前投影一步，通过带 ℓ1 换手率惩罚、Ledoit-Wolf 收缩的均值方差优化映射成因子权重；VIX/CAPE 不进入状态识别，仅作为优化器的"锚"来稳定参考权重。2013–2023 走步前样本外测试中，长仓（保守）与多空（激进）策略夏普分别为 1.33 / 1.24，最大回撤仅 −3.64% / −5.78%，远低于 SPY/QQQ/TLT。