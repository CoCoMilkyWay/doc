# FinLLM 2026 论文合集：从任务能力走向系统可靠性

QuantML QuantML 2026-08-12 15:11 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247494368&idx=1&sn=8b0437b398a6318c2ddf03226a02bab2&chksm=cfdab2f8e3a14c80a9bdc75718b3960202a132dd18a2c9e7d59518c7d6c2f5ba853da6934710#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247494368&idx=1&sn=8b0437b398a6318c2ddf03226a02bab2&chksm=cfdab2f8e3a14c80a9bdc75718b3960202a132dd18a2c9e7d59518c7d6c2f5ba853da6934710#rd)

> 对于想了解 AI4Finance 应用场景的读者，今年的 FinLLM 论文是一份很好的观察样本。这里既有 SEC 文件问答、新闻信息抽取和财务舞弊检测，也有因子生成、交易 Agent、市场状态识别、信贷评分与系统验证。论文涉及的已经不是一个抽象的“AI+金融”概念，而是金融任务如何拆解、证据如何进入模型、市场反馈如何回到系统，以及模型结果如何接受审计。

* * *

FinLLM （International Symposium on Large Language Models for Financial Services） 是 IJCAI 2026 的卫星活动，将于 2026 年 8 月 15 日在德国不来梅举行。今年讨论重点已经从往年的金融问答和文本理解进一步延伸到自主 Agent、大小模型协同，以及金融 AI 的部署与治理。

本届会议由易方达基金、清华大学、香港理工大学、曼彻斯特大学、肯特大学和武汉大学共同组织，议题主要分为三组：

-   Agent 架构、多智能体、云端大模型与本地小模型协同，以及多模态和跨语言建模；
    
-   token 成本、轻量化微调、推理和蒸馏；
    
-   自主金融系统的权限控制、幻觉治理、公平性、跨境数据隐私与监管合规。
    

以下是关于论文的一些介绍：

## **最佳论文**

### 1\. FinSAgent：让不同角色分别寻找财报证据

**原文标题**：_FinSAgent: Corpus-Aligned Multi-Agent RAG Framework for Evidence-Grounded SEC Filing Question Answering_  
**作者**：Jijun Chi、Zhenghan Tai、Hanwei Wu、Tung Sum Thomas Kwok、Hailin He、Zixing Liao、Bohuai Xiao、Chaolong Jiang、Jianliang Lei、Jerry Huang、Peng Lu、Muzhi Li、Liheng Ma、Yihong Wu、Sicheng Lyu、Jingrui Tian、Yihan Li、Yanzhang Ma、Sizhe Guan、Dingtao Hu、Yufei Cui、Ling Zhou、Lei Ding、Xinyu Wang

SEC 文件中的问题往往横跨正文、表格、脚注和风险披露，单次向量检索容易漏掉关键材料。FinSAgent 为检索 Agent 划分不同职责，再通过问题分解、并行检索和特征门控重排合并证据。论文在 FinanceBench、FinDER、SECQUE 子集以及两个专有数据集上进行了测试；在控制最终上下文规模后，系统在正确性和事实一致性等指标上仍保持较好表现。

## **最佳论文亚军**

### 2\. 用市场结果调整 RAG 的“信源偏好”

**原文标题**：_Point-in-Time Financial RAG with Frozen LLMs and Market-Feedback Adaptive Retrieval_  
**作者**：Zijie Zhao、Roy E. Welsch

传统 RAG 通常依据文本相关性选择材料，但与某条新闻语义接近的文档，未必对判断后续价格影响有用。这项工作保留冻结的 LLM，把已经实现的残差收益反馈写入外部贝叶斯记忆，用来调整不同事件类型和预测期限下的信源权重。样本覆盖 89 只偏 Nasdaq 的股票；加入来源记忆后，Macro-F1 由 0.438 升至 0.471，Rank IC 由 0.046 升至 0.061。

## Long Oral

### 3\. 开源权重模型的金融文本理解能力

**原文标题**：_Can Open-Weight Models Compete on Financial Text Comprehension?_  
**作者**：Jan Spörer

Financial Touchstone 在本次更新后收录了 495 份国际年报和 2967 组问答。作者用它评测 10 家提供方的 20 个模型。Claude Opus 4.6 的准确率最高，为 88.4%；Gemini 2.5 Pro 的幻觉率最低，为 0.08%；开源权重模型 Kimi K2.6 的准确率排在第三位。错误分析中，48.9% 的失败发生在信息检索环节。

### 4\. TriAgent：只有出现分歧时才升级推理

**原文标题**：_TriAgent: Divergence-Aware Multi-Agent Committees for Cost-Efficient Financial Sentiment Analysis_  
**作者**：Isabel Xu、Cynthia Xu、Rachel Ren、Cong Guo、Jiacheng Ding

TriAgent 面向金融情绪分类中的成本与隐私问题。常规请求先由本地小模型处理，当模型之间出现明显分歧时，再交给更强的云端模型。实验还发现，增加 Agent 数量并不会自动改善结果：在一组设置中，单个 critic 的 F1 约为 0.87，同规模的三人格投票反而降至 0.66。论文据此进一步设计了共享词典、缓存和分层路由机制。

### 5\. DCF 估值中的假设治理

**原文标题**：_Document-Grounded DCF Valuation with LLM Assumption Governance_  
**作者**：Anastasiia Fedorova、Fedor Buzaev、Marat Galyavov、Daria Pugacheva

从会议公开信息看，这项工作研究如何让 LLM 辅助 DCF 估值，并要求收入增速、利润率、资本开支等关键假设能够追溯到原始文档。会议页面尚未提供论文全文，数据来源、估值流程和实验结果目前无法核对。

### 6\. 随机切分可能高估财务舞弊检测能力

**原文标题**：_Benchmarking Generalization in Financial Statement Fraud Detection: Robust Evaluation and Novel Tasks_  
**作者**：Guy Stéphane Waffo Dzuyo、Gaël Guibon、Christophe Cerisara、Luis Belmar-Letelier

作者把财务指标、MD&A 文本和 SEC 的 AAER 舞弊标签整理为一个美国公司数据集，并设计了公司隔离的评测方式。使用普通随机切分时，最佳模型的 AUC 达到 0.96；同一家公司的记录不再同时进入训练集和测试集后，各模型成绩明显下降，文本模型的最高 AUC 约为 0.74。两种切分结果之间的差距，显示出公司特征泄漏对舞弊检测评测的影响。

### 7\. 同时读取 FOMC 文本和市场数据寻找制度切换

**原文标题**：_Enhancing Regime Shift Detection Using Unstructured Data: A Study on the Treasury Market_  
**作者**：Mingxuan Yi、Vidal Mehra、Jing Chen、John Cartlidge

样本包括 2010—2024 年 FOMC 会议纪要，以及由 14 个美债和宏观变量组成的数据面板。LLM 先从会议文本中提出可能的变点，再由 VAR 似然比检验确认；反过来，数据模型发现的变点也需要经过文本核查。最终管线取得 F1 0.82、F2 0.86，检测时间的众数偏差为零天。

## Short Oral

### 8\. 用选择题检查交易 Agent 的专业知识

**原文标题**：_Backtrader-Bench: Benchmarking LLM Agents on Algorithmic Trading with Self-Generated MCQs_  
**作者**：Ruoxi Zhao、Maziar Raissi

Backtrader-Bench 试图用自动生成的选择题评估 LLM Agent 对算法交易知识的掌握情况。会议页面和作者主页均已列出这项工作，但截至本文整理时尚无公开全文，因此暂时只能确认其研究范围，题目生成、质量控制和模型对比结果仍待论文披露。

### 9\. PRISM：复杂的多 Agent 检索不一定更好

**原文标题**：_PRISM: Prompt-Refined In-Context System Modeling for Financial Retrieval_  
**作者**：Chun Chet Ng、Jia Yu Lim、Wei Zeng Low

PRISM 不训练新模型，而是分别测试系统提示、上下文学习和轻量多 Agent 对金融检索的作用。实验使用 FinAgentBench、FiQA-2018 和 FinanceBench。最佳设置在 FinAgentBench 上获得 0.71818 的 NDCG@5；消融结果显示，提示优化的收益相对稳定，而 ICL 与多 Agent 的效果更依赖任务难度和模型规模。

### 10\. 当智能体参与信贷评分，申请人如何申诉

**原文标题**：_Substantive Equality in the Age of Generative and Agentic AI: Rethinking Creditworthiness_  
**作者**：Manuela Zaidan、Nicole Inverardi、Ilaria Penco、Silvia Tessaro Trapani、Eylül Erva Akin、Alessio Tartaro

这是一篇侧重制度与治理的论文。作者梳理传统统计模型、生成式模型和智能体系统在信贷评估中的不同作用，讨论公平、可解释性和安全之间的关联，并给出一套供申请人理解、质疑和纠正自动化信贷决定的流程。相关讨论对应欧盟《人工智能法案》、GDPR 和消费者信贷规则。

### 11\. 用两级重排控制金融 RAG 的上下文成本

**原文标题**：_Hierarchical Reranking for Scalable Financial RAG System_  
**作者**：Joohyun Lee、Sungwoo Hong

面对篇幅很长的金融材料，系统先用较轻的模型筛选候选，再将少量高相关文档交给更强的重排器；如果证据超过 token 限额，还会按语义结构压缩上下文。论文报告的 NDCG@20 为 0.7918，并同时记录检索质量、推理准确性和处理成本。

### 12\. 金融新闻不能只压缩成一个情绪标签

**原文标题**：_Beyond Sentiment: Structured Information Extraction from Financial News_  
**作者**：Daohan Zhu、Sitong Ge、Ruofei Wang、Honggu Chen、Yubo Hou、Tao Wan、Zengchang Qin

作者用 LLaMA-3.1-70B 从新闻中提取六类信息，包括事件类型、影响对象、时间跨度和置信度，并在 41618 个新闻—股票样本上检验其预测价值。结构化语义与 FinBERT 情绪结果的分歧率为 53.5%。将两类特征合并后，股票方向预测的 F1 从 0.576 提高到 0.600。

### 13\. 让 Agent 自主挖掘并检验因子

**原文标题**：_Beyond Prompting: Autonomous Factor Investing via Agentic AI_  
**作者**：Allen Yikuan Huang、Zheqi Fan

这套闭环流程让 Agent 扮演量化研究员：构建经济解释，编写因子，样本外检验，然后再组合通过筛选的因子。在美股多空组合的年化 Sharpe 为 2.75，收益率为 54.81%。

### 14\. 在 4-bit 模型中连续更新金融知识

**原文标题**：_CACHE-UK: A Stability-Aware Memory Editor for Sequentially Updated Quantized LLMs in Finance_  
**作者**：Anubhav Lakra、Yue Feng

CACHE-UK 处理的是量化模型连续编辑后的知识遗忘。实验语料包含 88021 篇英国金融文档。系统监测每次编辑造成的退化，并据此调整后续更新强度。在 4-bit 条件下，其测试成功率约为 28%，比最强对照高 6 个百分点；连续编辑结束后的知识退化也低于其他方法。

### 15\. 跑分不能代替金融系统验证

**原文标题**：_Benchmarks Are Not Validation: A System-Level View of Financial LLM Applications_  
**作者**：Bünyamin Burak Payzun、İrem Demirtaş、Simona Scala、Elena Ferretti、Seçil Arslan

模型在公开基准上得分较高，并不能说明整套应用已经具备上线条件。文中提出的验证范围包括数据质量、模型设计、检索与生成、工具调用、Agent 轨迹、IT 实现和治理机制。自动指标、人工审阅和 LLM Judge 可以共同使用，但需要保留评分规则、一致性检查、失败案例及整改记录。

### 16\. 跨境经济危机检测需要可解释的比较基准

**原文标题**：_Evaluating Frontier LLMs Against an Interpretable Reference for Cross-Border Economic-Crisis Detection_  
**作者**：Viacheslav Shalamov、Valeria Efimova、Ilya Novitskiy、Kirill Mironov、Sergey Muravyov、Georgii Petrov、Andrey Silivonchik

从题目和会议议程可知，这项工作使用可解释参照评估前沿 LLM 的跨境经济危机识别能力。目前没有可公开下载的全文，危机样本如何定义、参照模型如何构造以及各模型的成绩尚无法从公开材料确认。

### 17\. ContestTrade：让交易 Agent 通过历史表现竞争资源

**原文标题**：_ContestTrade: A Multi-Agent Trading System Based on Internal Contest Mechanism_  
**作者**：Rui Sun、Li Zhao、Zuoyou Jiang、Bo Yang、Yuxiao Bai、Mengting Chen、Jing Li、Zuo Bai

ContestTrade 分为数据团队和研究团队。每个 Agent 的输出都要等市场结果出现后再评分，系统随后预测其未来效用，并把计算资源分配给得分较好的成员。2025 年 1—6 月的 A 股回测考虑了 T+1、涨跌停和 0.1% 交易成本，报告累计收益 52.80%、Sharpe 3.12、最大回撤 12.41%。论文将这组结果界定为单一时期的初步回测。

  

  

相关论文详细解读已加入 AxiomQ.Paper

  

  

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![](assets/001.jpg)