# 量化研讨群资料总结 2026-05-13

Alpha搬运工 睿见Alpha 2026-05-14 10:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzU2MzcwODg4OA==&mid=2247488057&idx=1&sn=9fce694948e4025274ccf79e2e960c3b&chksm=fdb9d8eb3f84d4e5a96bb04ae97ec9ca7aead6d6ca42048734eba0f9ea5b0c44b08f60640ba0#rd](https://mp.weixin.qq.com/s?__biz=MzU2MzcwODg4OA==&mid=2247488057&idx=1&sn=9fce694948e4025274ccf79e2e960c3b&chksm=fdb9d8eb3f84d4e5a96bb04ae97ec9ca7aead6d6ca42048734eba0f9ea5b0c44b08f60640ba0#rd)

## 如何捕捉创业板风格切换时点?——基于拥挤度的创业板与红利低波风格轮动研究

**标签：** #创业板 #红利低波 #科创50 #风格轮动 #拥挤度指标 #成长价值轮动 #择时策略 #周频调仓 #A股 #宽基指数

**总结：** 将拥挤度重新定义为风格热度而非风险指标，通过创业板与红利低波拥挤度差进行风格轮动，并用双确认和周频执行机制取得较高历史超额收益。

**评价：** 思路有反直觉亮点且验证范围较广，但2016-2020蓝筹占优期失效、周频胜率接近随机、后续参数优化有过拟合嫌疑，适合作为风格轮动研究参考而非直接实盘方案。

## 基于宏观预期、趋势过滤与泡沫预警的利率择时框架

**标签：** #利率债 #国债 #债券ETF #久期轮动 #择时策略 #宏观因子 #ECFC预期数据 #LPPLS泡沫指标 #趋势过滤 #滚动夏普筛选 #固收+

**总结：** 文章从增长、通胀、信用、流动性四维度构建动态宏观因子池，结合ECFC预期数据、趋势过滤和LPPLS泡沫预警形成利率债久期轮动信号。

**评价：** 框架完整、逻辑链条清晰且解释性较好，但样本期偏短、换手频率较高、部分阈值有调参嫌疑，对固收+和债券择时研究员更有参考价值。

## The Front End of the VIX Term Structure and Forward Realised Volatility

**标签：** #VIX #VIX9D #VIX3M #美国股票市场 #S&P500 #波动率预测 #期限结构 #波动率风险溢价 #期权市场 #HAR\-RV模型

**总结：** 文章发现以VIX9D为基础的前端期限结构指标比传统VIX-VIX3M更能预测未来已实现波动率，且在控制HAR-RV变量和样本外测试后仍具稳健性。

**评价：** 研究质量较高、数据来源和统计检验较规范，但信号强度依赖COVID-19和2025年关税冲击等极端事件，机制解释仍偏推测。

## A Deep Learning Approach for Pricing Convertible Bonds with Path-Dependent Reset and Call Provisions

**标签：** #可转债 #路径依赖期权 #深度学习 #最小二乘蒙特卡洛 #GBM #CEV #Heston模型 #中国可转债市场 #动态规划 #神经网络定价

**总结：** 文章将含下修和赎回条款的可转债定价建模为路径依赖PPDE，并在GBM、CEV和Heston动力学下用神经网络近似条件期望以实现高维路径依赖定价。

**评价：** 方法论上有一定新意且对中国可转债定价研究有参考价值，但神经网络结构基础、实证仅覆盖单一债券且缺乏市场价格对比，更接近方法论论文而非实战工具。

## The Value of Information: A Puzzle

**标签：** #美股 #知情交易 #信息价值 #噪声交易者 #价格冲击 #订单流 #Kyle模型 #市场微观结构 #主动管理费用 #高频数据 #TAQ数据库 #做市商 #市场效率

**总结：** 文章基于Kyle-Back连续时间知情交易模型，用价格变动与订单流的二次协变量度量信息价值，并发现美股平均信息价值远低于主动管理基金收费。

**评价：** 理论推导严谨、实证核验充分且学术规范性强，对市场微观结构、主动管理业绩归因和信息不对称定价研究员有实质参考价值。

## A Validated Volatility-Volume-Gap Classifier for Regime Identification in MNQ Intraday Data

**标签：** #MNQ #微型纳斯达克100期货 #日内交易 #波动率聚类 #成交量异常 #隔夜跳空 #日类型分类器 #制度识别 #OHLCV #滚动扩展窗口 #Walk\-Forward验证 #均值回归策略 #系统化交易 #伪证研究

**总结：** 文章构建由首30分钟绝对涨跌幅、隔夜跳空和首bar成交量偏差共同触发的VVG分类器，用于识别MNQ期货特殊交易日，但8种方向性策略均未通过机构级显著性标准。

**评价：** 研究诚实地区分描述性有效与可交易信号，验证框架值得借鉴，但触发样本仅40天且只覆盖单一品种，对专业机构量化的增量价值有限。

## Bayesian Dynamic Modeling of Realized Volatility in Financial Asset Price Forecasting

**标签：** #贝叶斯动态模型 #已实现波动率 #DLM #随机波动率 #SV模型 #S&P行业ETF #OHLC #Rogers\-Satchell估计量 #高频数据 #杠杆效应 #波动率反馈 #共轭分析 #序贯滤波 #资产价格预测 #风险管理

**总结：** 文章提出耦合价格与已实现波动率的RV-DLM/RVL-DLM贝叶斯动态线性模型，并在9只S&P行业ETF与S&P指数样本外评估中持续优于传统SV-DLM。

**评价：** 该文数学结构干净、实证设计规范且计算成本低，对波动率建模、期权与风险管理、贝叶斯状态空间模型研究员很有启发，但缺少交易级PnL和主流hybrid模型直接对比。

**代码：** GitHub地址：github.com/PSW1998/rv-dlm-paper-figure