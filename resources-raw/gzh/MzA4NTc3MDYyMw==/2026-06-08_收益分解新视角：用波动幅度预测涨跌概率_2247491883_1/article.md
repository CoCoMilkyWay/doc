# 收益分解新视角：用波动幅度预测涨跌概率

InfinityQuant 映翡量化 2026-06-08 09:13 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491883&idx=1&sn=3fead2dac52ea84ad5fc505a4aaeacd1&chksm=9e3529901c7ce16e07f20a6e3d50946d96ba3a64248e5ca5c4f9fbd7f48edac990e42b2a562e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491883&idx=1&sn=3fead2dac52ea84ad5fc505a4aaeacd1&chksm=9e3529901c7ce16e07f20a6e3d50946d96ba3a64248e5ca5c4f9fbd7f48edac990e42b2a562e#rd)

《Journal of Banking & Finance》的一篇新论文《A new decomposition approach to modeling financial returns: Conditioning sign on magnitude》（2026年6月2日）将股票收益分解为“方向 × 幅度”，并在给定波动幅度的条件下，建模上涨月份的概率。

原理：

-   波动具有聚集性。今天的大幅波动意味着明天波动率更高，从而改变上涨的概率。
    
-   即使平均收益看起来不可预测，这种机制也会引入方向上的可预测性。
    
-   无需使用 copula 或机器学习，只需用一个以波动幅度为自变量的 Probit 模型。
    

研究结果（基于1981–2021年的标普500月度数据，扣除交易成本后）：

-   终值财富为 181.68 美元，而买入并持有为 104.63 美元，
    
-   夏普比率提升在 5% 显著性水平下成立，
    
-   确定性等价收益（CER）每年提高约 2%，相当于理性投资者愿意为该预测支付的费用。
    

线性回归和状态转换模型？都被稳定地击败了。

![](assets/001.png)

  

https://arxiv.org/abs/2606.04153

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/002.png)