# &quot;闪崩&quot;全解析

QuantSeek QuantSeek 2026-02-01 12:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485687&idx=1&sn=f7c2833c127547d62ab4019ae1ac6094&chksm=ce9acd10d556446267e7aa0e43b801cfa680592fdc1761c5eba9a49cfa158d46aa2f67441f0b#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485687&idx=1&sn=f7c2833c127547d62ab4019ae1ac6094&chksm=ce9acd10d556446267e7aa0e43b801cfa680592fdc1761c5eba9a49cfa158d46aa2f67441f0b#rd)

相信上周各位都见识到了金银的闪崩，这里就不放图了。其实学界对闪崩有过很多的研究，方向有2类，分别是闪崩的分类和归因、闪崩的预测。本文总结了2个研究方向的经典论文，以飨读者。

* * *

## 1\. The Microstructure of the 'Flash Crash': Flow Toxicity, Liquidity Crashes and the Probability of Informed Trading

这篇论文分析了2010年5月6日美股闪崩的微观结构成因。作者提出**订单流毒性（flow toxicity）**概念，并提出了**VPIN指标**（成交量同步知情交易概率）来实时监测市场流动性风险。研究发现，闪崩前数小时至数天，VPIN指标已持续攀升至历史极端水平，表明做市商因面临高度毒性订单流而撤离市场，导致流动性突然蒸发。非常的经典论文。

* * *

## 2：The Flash Crash: The Impact of High Frequency Trading on an Electronic Market

**核心内容：** 基于2010年5月6日"闪电崩盘"（Flash Crash）的E-mini S&P 500期货逐秒交易数据，作者将市场参与者分为六类（高频交易者HFTs、做市商、基本面买卖方等）。关键发现：**HFTs并非闪崩的元凶，但加剧了危机**——他们通过"即时性吸收"策略（immediacy absorption），在价格变动前抢先执行最后几笔订单，将成本转嫁给 slower 的交易者；在崩盘期间，HFTs之间产生"烫手山芋"效应（hot potato），交易量激增但净持仓变化极小。研究建议监管应**鼓励HFTs提供流动性而非索取即时性**，可通过短暂交易暂停（如5秒熔断）来协调市场参与者的流动性供给响应。

* * *

## 3\. High-Frequency Financial Market Simulation and Flash Crash Scenarios Analysis: An Agent-Based Modelling Approach

该研究构建了一个**毫秒级高频Agent-Based市场模拟器**，完整复现了2010年闪崩事件。模型包含五类交易者：基本面交易者、长/短期动量交易者、噪声交易者和做市商。通过蒙特卡洛实验，作者发现闪崩幅度与三个因素显著相关：**机构卖单算法的成交量占比（POV）、做市商库存限制、以及基本面交易者交易频率**——其中前两者与闪崩幅度呈非单调关系。研究还创新性地引入"尖峰交易者（Spiking Trader）"来模拟**小型闪崩（mini flash crash）**，发现做市商库存限制是影响小型闪崩频率和幅度的关键因素。

* * *

## 4\. Exogenous and Endogenous Price Jumps Belong to Different Dynamical Classes

**Marcaccioli, Bouchaud & Benzaquen (2021)**

这篇论文利用300只美股5年的高频数据与新闻数据库，将价格跳跃划分为**外生型（EMC）**与**内生型（SEC）**两类动态模式。外生跳跃由突发新闻驱动，表现为**突发式冲击+快速幂律衰减**；内生跳跃则由市场内部反馈机制引发，呈现**渐进式波动累积+缓慢对称衰减**的特征——类似于YouTube观看量和亚马逊图书销量的自激发动态。研究通过拟合双重幂律函数，成功以**73%的AUC准确率**仅基于波动率形态对跳跃类型进行分类，为识别市场脆弱性提供了新工具。

我来为您总结这两篇关于高频交易与市场闪崩的学术论文：

* * *

## 5：Machine Learning-Based Prediction of Mini Flash Crashes

**核心内容：** 该研究首次将机器学习方法应用于预测个股层面的"微型闪崩"（Mini Flash Crashes）。作者利用2017-2018年NYSE的微观结构数据，构建了包含21个预测变量（涵盖交易量、限价订单簿失衡、买卖价差等）的模型，测试了LASSO、SVM、随机森林和XGBoost四种算法。研究发现：**微型闪崩具有可预测性**，尤其是15秒和90秒时间窗口的预测准确率（AUC）可达0.9以上；限价订单簿失衡（LobImbalance）、Kyle's Lambda和有效价差是最重要的预测信号。研究建议监管机构可据此开发**早期预警系统**，在熔断机制触发前识别风险。

* * *

  

![](assets/001.png)

(加入星球获取论文及更多资讯）