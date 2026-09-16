# TSFresh——轻松提取时间序列上的特征功能1

小燕子搬砖 映翡量化 2024-01-05 21:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484116&idx=1&sn=aca785d65978b70f0542a6341f273d29&chksm=9ea3e7e223e0bc9fbce335997e62522f226713cfbc64858f1e5122288242dd10f4d62cf9e8b4#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484116&idx=1&sn=aca785d65978b70f0542a6341f273d29&chksm=9ea3e7e223e0bc9fbce335997e62522f226713cfbc64858f1e5122288242dd10f4d62cf9e8b4#rd)

  

有句俗话：数据和特征工程决定了模型的上限，而改进的算法只接近这个上限。特征工程旨在提高机器学习模型的整体性能，并生成最适合机器学习算法的输入数据集。

  

# **自动化特征工程**

在许多生产项目中，特征工程是手动完成的，它依赖于先前的领域知识、直觉和数据操作。整个过程非常耗时，且需要在场景或数据更改后再次完成。自动化特征工程则希望自动生成大量用于数据集处理的候选功能，以帮助数据科学家和工程师可以选择最有用的功能进行进一步数据和模型处理。

自动化特征工程是一项有意义的技术，允许数据科学家花更多时间在机器学习的其他方面，从而提高工作效率和有效性。

![](assets/001.jpg)

  

# **自动化特征工程实现途径**

# 有许多开源的库和工具可以实现关系数据和时间序列的特征工程自动化。

-   featuretools是一个Python库，用于将时间序列和关系数据转化为机器学习的特征矩阵。
    
-   OneBM可一键式机器将关系数据上的特征转化和特征选择与特征选择技术相结合。帮助数据科学家减少数据探索时间，允许他们在短时间内尝试和错误许多想法。另一方面，它使不熟悉数据科学的非专业人士能够以少量的努力、时间和成本迅速从数据中提取价值。
    
-   getML是一个开源的工具，用于在时间序列和关系数据上进行自动特征工程。它是用C/C++语言实现的，有一个Python接口。已被证明比tsflex、tsfresh、tsfel、featuretools或kats至少快很多倍。
    
-   tsfresh是一个用于时间序列数据特征提取的Python库。它使用假设检验来评估特征的质量。
    
-   tsflex是一个开源的Python库，用于从时间序列数据中提取特征。尽管由Python编写，但它已被证明比tsfresh、seglearn或tsfel更快、更节省内存。
    
-   seglearn是scikitlearnPython库的一个多变量、连续时间序列数据的扩展。
    
-   kats是一个用于分析时间序列数据的Python工具包。
    

  

**TSFresh——轻松提取特征工程‍‍‍**

TSFresh具有强大的时间序列数据特征提取功能，提取的特征可用于描述时间序列，即通常这些特征为时间序列及其动态提供新的解释。它们还可用于集群时间序列和训练在时间序列上执行分类或回归任务的机器学习模型。

![](assets/002.jpg)

TSFresh自动从时间序列中提取100个特征。这些特征描述了时间序列的基本因素，如峰值的数量，平均值或最大值，或更复杂的因素，如时间反向对称统计等。

![](assets/003.jpg)

  

未完待续...

参考资料：

https://vibaike.com/175632/

https://tsfresh.com/  

https://tsfresh.readthedocs.io/en/latest/text/introduction.html  

https://levelup.gitconnected.com/4-python-libraries-for-automated-feature-engineering-that-you-should-use-in-2023-54bccecb1683