# 因子魔法：行业市值中性化

QuantSeek QuantSeek 2026-01-06 21:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485485&idx=1&sn=d601a3ade18290c77ed9afac81db0e93&chksm=ce53315528c24a48fc02cc0c71e8e70dd5301006f6f527f0600550dfdded3ecc08065cdca01b#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485485&idx=1&sn=d601a3ade18290c77ed9afac81db0e93&chksm=ce53315528c24a48fc02cc0c71e8e70dd5301006f6f527f0600550dfdded3ecc08065cdca01b#rd)

对因子进行中性化，是一个常规的做法，正好星球有用户问到，我干脆详细讲讲这个东西。

## 常见的中性化：

1、市值中性

2、行业中性

3、行业+市值中性

4、Barra风格+行业中性：

机构通常通过采购或者自己复现来实现Barra风格中性，Barra-CNE5有10个以上的风格因子，如果没有条件进行这么复杂的中性化，可以参Fama-French 五因子进行简单的中性化即可。

## 中性化的作用

1、通常的解释是Pure-alpha那一套，比如剥离掉风格之后，还有没有选股的能力。那么如果一个因子剥离完后没用就真的没用吗？显然不是，星球有说过这个问题。

2、除了pure-alpha，有的时候中性化还能起到起死回生的魔法效果，从无用到有用。

  

我写了一个demo放到QuantSeek-V6框架里，感兴趣的用户星球自取。

![](assets/001.png)