# 收益预测中的非平稳性与复杂性权衡

InfinityQuant 映翡量化 2026-01-07 11:32 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247490413&idx=1&sn=5d04d999ae0814fca16e96df7bde6fc1&chksm=9e367a8cd10879f26fab717188c237a1dbd87f85854d1463c0e7215143a176904c80e513dad4#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247490413&idx=1&sn=5d04d999ae0814fca16e96df7bde6fc1&chksm=9e367a8cd10879f26fab717188c237a1dbd87f85854d1463c0e7215143a176904c80e513dad4#rd)

标题：The nonstationarity-complexity tradeoff in return prediction

作者：Agostino Capponi ，Chengpiao Huang， J. Antonio Sidaoui， Kaizheng Wang，Jiacheng Zou

发布日期：2025年12月29日

  

**数据更少 / 模型更简单，反而打败数据更多 / 模型更大**  
**因为市场会变，模型不会** 🔄📉

论文解释了为什么股票预测模型在市场一变就失灵。来自哥伦比亚大学和斯坦福的作者们指出了一个真正的“非平稳”难题：花哨的模型需要海量数据，但旧数据反映的是旧制度。他们打造了一个自适应系统，**同时挑选模型复杂度和数据窗口长度**，在标准方法面前尤其是衰退期全面碾压，还把交易收益也抬高了。

🧩 **三重误差权衡**  
把误差正式拆成三块：

![](assets/001.png)

-   **模型错设误差**（模型太简单）
    
-   **统计不确定性**（模型太复杂、样本不够）
    
-   **非平稳性误差**（窗口太长、环境已变）
    

窗口长度和模型类别必须**一起选**，不能各玩各的。

![](assets/002.png)

🏆 **ATOMS 解决方案**  
他们提出一个“锦标赛”选择器，叫 **ATOMS**：用一条**会根据最新漂移自动伸缩的验证窗口**来比较各路模型，谁稳谁上。

🎯实证数据

17个行业投资组合（1987-2016）。预测变量集：包含宏观经济因子（Chen et al., 2024）、特征排序投资组合（Gu et al., 2020）、Fama-French三因子以及滞后收益。

⚙️模型设定

候选模型：随机森林、Ridge、Lasso、Elastic Net；训练窗口：指数级增长的窗口长度；基准：固定验证窗口（Fixed-val 32/128/512个月）、固定窗口交叉验证（Fixed-CV）。

📊 **R² 结果**  
在 Kenneth French 的 17 个行业组合上，新方法把**样本外 R²**整体抬升约 14%；按不同基准设置，提升幅度 14 %–23 % 不等。

🌪️ **衰退期亮眼**  
市场一乱，优势就放大了：

-   1990 海湾战争衰退期，他们的 R² 仍为正 0.027，而长窗口验证直接负数。
    
-   2001 年互联网泡沫，他们冲到 0.125，固定交叉验证只有 0.071。
    
-   2008年金融危机，也是保持优势。
    

![](assets/003.png)

💸 **交易绩效**  
用他们选出的模型做最简单的交易规则（预测为正就做多，为负就做空），各行业平均累计收益**高出约 31 %**。

![](assets/004.png)

  

https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=5980654

PDF已更新，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/005.png)