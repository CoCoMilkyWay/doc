# QuantAgent：适用高频交易，Github开源

InfinityQuant 映翡量化 2025-10-28 10:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487803&idx=2&sn=24a01faae2160a49bd78517edde11678&chksm=9e2e8d979e0f5d47cc972f3f829bfb0811efd7cd9e8d160a4ea43053a0887443851bcea27d35#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487803&idx=2&sn=24a01faae2160a49bd78517edde11678&chksm=9e2e8d979e0f5d47cc972f3f829bfb0811efd7cd9e8d160a4ea43053a0887443851bcea27d35#rd)

QuantAgent系统，这是首个专为高频交易（HFT）设计的多Agent大型语言模型（LLM）框架。不同于以往依赖新闻或情绪文本输入的LLM系统，QuantAgent仅基于OHLC（开盘、最高、最低、收盘）价格数据进行分析，强调快速、精确的短期信号处理。

![](assets/001.png)

系统将交易分解为四个专业Agent：

-   IndicatorAgent：计算并解释技术指标，如RSI、MACD、ROC、Williams，用于评估动量、超买/超卖状态。
    

![indicator agent](assets/002.png)

-   PatternAgent：检测图表模式，如双底、三角形等，通过多模态推理分析烛线图的几何特征。
    

  

-   TrendAgent：识别趋势（上升、下降、横盘），通过拟合支撑/阻力线和斜率分析价格方向。
    

![trend agent](assets/003.png)

-   RiskAgent：整合信号，设置止损和止盈水平，计算风险-回报比率。
    

![](assets/004.png)

最终，DecisionAgent汇总输出，决定做多（LONG）或做空（SHORT），并提供自然语言解释，确保决策可追踪。

  

实验覆盖比特币、纳斯达克期货等9种金融工具，在1小时和4小时间隔上，QuantAgent在方向准确率和回报指标上优于随机、线性回归、XGBoost等基线。论文强调该框架在高频市场中的适应性和解释性，代码开源于GitHub。

  

Paper: https://arxiv.org/abs/2509.09995  
GitHub: https://github.com/y-research-sbu/QuantAgent  
  
Similar recent work by the same group on Time Series:  
TimeSeriesScientist: A General-Purpose AI Agent for Time Series Analysis  
Paper: https://arxiv.org/abs/2510.01538  
GitHub: https://github.com/Y-Research-SBU/TimeSeriesScientis

  

PDF已更新⬇️

![](assets/005.jpg)