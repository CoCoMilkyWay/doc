# QuantML-Qlib Model | 滚动模型训练

QuantML QuantML 2024-07-10 19:58 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=cfbb1bd0e4b250a8446ef6a2064d948fca7e3ffcb92b5f6f5142e7c72568b33403d9ee27cea8#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=cfbb1bd0e4b250a8446ef6a2064d948fca7e3ffcb92b5f6f5142e7c72568b33403d9ee27cea8#rd)

Content

本文主要从应用的角度介绍如何在qlib/quantml-qlib中使用滚动训练。

  

**为什么要滚动训练？**

金融市场的特性是动态且多变的，其特征分布随时都在发生变化。没有单一模型能够永远超越市场表现，因为数据和模型自身都会随时间逐渐失效。为了有效应对市场的这些变化，采用滚动训练方法是一种直接且有效的策略。此外，还可以考虑使用元学习技术，如doubleadapt和DDG-DA，这些方法的详细介绍参考公众号之前的文章。

在qlib中，有两种方式实现滚动训练。

  

**方案一：**

参考examples/rolling\_process\_data，这种方法的流程是先一次性加载完整的数据集，然后通过滚动机制来生成数据集。其优势在于，一旦数据被加载，每次滚动更新时，仅需对数据进行简单的划分和处理。

  

```
for rolling_offset in range(self.rolling_cnt):
```

缺点在于它不支持自定义滚动间隔，通常只能按照年度来重新训练模型。不过，用户可以通过调整start\_time和end\_time的逻辑来自定义数据的切分方式。

在原始代码中，只包含了数据的划分逻辑。要将模型训练集成到这一流程中，操作起来也相对简单。只需在config中定义好模型参数，然后在每次滚动迭代中训练模型，并保存训练结果即可。

**方案二：**

参考examples/benchmarks\_dynamic/baseline，这套方案的集成度很高，所有数据处理，模型定义都封装在了Rolling类里，源代码的详细分析可以参考这里：  

> ‍Qlib 模型滚动训练（一）Task Management - 知乎 (zhihu.com)‍
> 
> https://zhuanlan.zhihu.com/p/596236600

在使用时，首先在examples/benchmarks\_dynamic/baseline/rolling\_benchmark.py中定义config文件，模型使用的linear alpha158的config文件，理论上example里面所有模型的config都可以使用。

需要注意的是，模型使用的训练间隔是20，如果想要修改训练间隔，需要在examples/benchmarks\_dynamic/baseline/rolling\_benchmark.py:22中添加参数step=XX自行修改。

config中label的时间区间会被覆盖，需要根据需要修改examples/benchmarks\_dynamic/baseline/rolling\_benchmark.py:22中的horizon参数。

默认采用的固定开始时间，不断延长结束时间的方式训练，如果要改为固定时间长度的方式，修改qlib/workflow/task/gen.py:148中ROLL\_EX为ROLL\_SD

同时还有一个细节问题，对于最后几天的训练数据实际上会存在信息泄露，因此需要设置一个trunc\_days剔除最后几天的数据避免这个问题，通常设置为horizon+1的值即可。

设置完成后运行examples/benchmarks\_dynamic/baseline/rolling\_benchmark.py即可得到最终结果，有兴趣可以自行对比rolling相比于静态训练的提升效果。  

默认参数运行结果：

{'IC': 0.08611646686177134,

 'ICIR': 0.5959885818997146,

 'Long-Avg Ann Return': 1.787827642634511,

 'Long-Avg Ann Sharpe': 1.864634320864517,

 'Long-Short Ann Return': 2.2364592365920544,

 'Long-Short Ann Sharpe': 6.486889305480004,

 'Rank IC': 0.09404204518955397,

 'Rank ICIR': 0.6107686565935599}

相关代码已经提交到quantml-qlib,欢迎测试。  

  

  

**代码下载见星球**

  

  

加入星球请扫我：

![](assets/001.jpg)

  

  

  

入群请扫我：  

![](assets/002.jpg)

  

  

  

**点击蓝字**

![](assets/003.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/004.jpg)