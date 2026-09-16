# Bootstrap情景模拟在投资组合构建中的应用

InfinityQuant 映翡量化 2026-06-19 08:50 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491980&idx=1&sn=1e960bd8bb5f01461e5cd5d6a49893bb&chksm=9ea95c19a850ac558a6fab1872c2bdd082a76a4c5e06bdf247f3e57eb5879dad4b9d29925263#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491980&idx=1&sn=1e960bd8bb5f01461e5cd5d6a49893bb&chksm=9ea95c19a850ac558a6fab1872c2bdd082a76a4c5e06bdf247f3e57eb5879dad4b9d29925263#rd)

您的花哨均值-方差优化器本质上只是一个加了额外步骤的随机数生成器。下面是证明方法。

每一个投资组合决策都建立在一段单一的历史样本之上。优化器只看到一条已实现的路径，并将其估计结果视为真实，从而把权重集中分配给在该样本中表现最好的资产。由此得到的投资组合对未发生的情景极为脆弱，并且对已观察路径存在过拟合。

Bootstrap是解决这一问题的标准方法。

QuantInsider的《Bootstrap Scenario Simulationfor Portfolio Construction》（2026年6月6日）涵盖三个层面。

1.区块重采样

标准Bootstrap假设数据是独立同分布（iid），而金融收益显然并非如此。区块Bootstrap（Künsch）和稳定Bootstrap（Politis-Romano）通过重采样连续区间，保留了真实收益中关键的波动聚集特征。其输出不再是单一回测统计量，而是该统计量的分布，从而揭示原本被误认为精确的结果实际上只是一个样本实现。

![](assets/001.png)

2.条件情景重采样

标准Bootstrap只能对历史进行再加权，无法生成比历史最差情形更极端的场景。通过按照宏观经济状态对日期分桶，并在选定的状态内进行重采样，可以将经验分布向历史中样本不足的压力情景倾斜。其输出是一组在指定情景组合下的路径集合（fan of paths）。

![](assets/002.png)

3.Bagging（装袋法）

对 B 个重采样数据分别应用投资组合构建方法，并对权重进行平均。Bagging后的权重更加分散，对输入噪声不敏感，并且在高维资产空间中通常具有显著更好的样本外表现。不同重采样之间权重的离散程度还可以作为评估策略稳健性的诊断指标。

两个注意事项：

-   Bootstrap降低的是方差，而不是偏差：它无法修复模型设定错误或数据泄露问题。
    
-   条件情景方法的效果依赖于状态划分的质量；如果状态标签是非因果的，那么无论重采样过程多么谨慎，回测结果仍然会受到污染。
    

https://www.linkedin.com/company/quant-insider/posts/?feedView=all

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)