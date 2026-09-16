# Kaggle知识点：特征基础编码方法

Coggle数据科学 量化前沿速递 2024-02-22 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487580&idx=1&sn=c47209cd725595f802cdb57affd37ee6&chksm=c31082c0ebe955a355d8956bd28f7cc184d999b8a7a911928a294a9b2c4a2d4eec134c6deee0#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487580&idx=1&sn=c47209cd725595f802cdb57affd37ee6&chksm=c31082c0ebe955a355d8956bd28f7cc184d999b8a7a911928a294a9b2c4a2d4eec134c6deee0#rd)

在之前的文章中我们讲解了[特征工程的实操的范式](http://mp.weixin.qq.com/s?__biz=MzIwNDA5NDYzNA==&mid=2247504463&idx=1&sn=4b892df23e6d756537d14b6db539a998&chksm=96c7ff8aa1b0769c5cfe10c3c43232c5cce834abdf844b8ddee92f4fd9c80d45c33ab709bdc6&scene=21#wechat_redirect)，但有读者留言说文章太过深奥😄。**小编想表达的是特征工程有很多种方式，特征范式是创建特征的方法。**

本文将介绍的更加基础，包括基础的特征编码方法，建议与之前的文章结合一起阅读。

## unsetunset缺失值填充unsetunset

缺失值是数据分析中常见的问题，指的是数据集中某些变量的取值缺失或未知。缺失值可能由于多种原因产生，包括数据收集过程中的错误、设备故障、被调查者拒绝提供信息等。

处理缺失值的主要目标是尽量保留数据的完整性和可用性，同时不引入过多的偏差。常见的填充逻辑包括：

方法

数值变量

分类变量

用均值或中位数替换缺失值

√

×

用指定的任意数值替换缺失值

√

×

用分布的尾部值替换缺失值

√

×

用最频繁的类别值或指定的任意类别值替换缺失值

√

√

从变量中随机抽取值替换缺失值

√

√

添加一个二元变量来指示缺失值

√

√

删除数据集中包含缺失值的观测

√

√

不是所有模型都能处理缺失值，但有些模型能够在训练过程中直接处理缺失值，包括：

-   决策树模型（如随机森林、梯度提升树）：这些模型可以自然地处理缺失值，因为它们在决策过程中只需考虑已知特征的信息。
    
-   K近邻算法：K近邻算法的基本原理是根据数据点的相似性进行预测，对于含有缺失值的数据，K近邻算法能够利用其他特征值相似的样本进行预测。
    
-   神经网络模型：神经网络模型可以通过适当的数据处理和网络架构设计来处理缺失值，例如使用特殊的填充层或者在训练过程中对缺失值进行处理。
    

## unsetunset类别编码unsetunset

类别编码是将分类变量转换为模型可接受的数值形式的过程，以便机器学习算法能够有效地处理它们。在进行类别编码之前，首先需要识别数据中的分类变量类型，然后选择合适的编码方法进行转换。需要注意的是，不同的类别编码方法可能会重复信息，甚至可能导致维度爆炸，因此选择合适的编码方法至关重要。

在识别类别类型时，主要有两种情况：

-   名义型（Nominal）变量：名义型变量是没有顺序或等级关系的分类变量，例如颜色、城市等。对于名义型变量，通常使用独热编码（One-Hot Encoding）等方法进行转换。
    
-   有序型（Ordinal）变量：有序型变量是具有顺序或等级关系的分类变量，例如教育程度（小学、初中、高中等）。对于有序型变量，可以使用序数编码（Ordinal Encoding）等方法进行转换。
    

方法

单调编码

适用回归

适用二元分类

适用多类分类

描述

OneHotEncoder

✅

✅

✅

✅

从每个类别创建虚拟/二元变量

CountFrequencyEncoder

❎

✅

✅

✅

用观测次数或频率替换类别

OrdinalEncoder

若按目标排序，则为✅；否则为❎

✅

✅

若数字被任意分配，则为✅；否则为❎

将类别按顺序替换为整数，可以是任意的顺序或按目标平均值排序

MeanEncoder

✅

✅

✅

数字将被返回，但不同类别的平均值没有数学意义

按类别的目标平均值替换类别

WoEEncoder

✅

❎

✅

❎

将类别替换为权重值

PRatioEncoder

✅

❎

✅

❎

用概率比率替换类别

DecisionTreeEncoder

✅

✅

✅

✅

用决策树的预测替换类别

RareLabelEncoder

  

✅

✅

✅

将不常见的类别分组到一个新类别中

在进行类别编码时，需要注意以下几点：

-   选择适当的编码方法根据变量的类型和业务需求。
    
-   处理编码可能导致的维度爆炸问题，特别是在独热编码等方法中。
    
-   考虑类别的数量和稀疏性，选择合适的编码方法以平衡信息损失和计算效率。
    

## unsetunset离散化unsetunset

离散化是数据预处理中常用的一种技术，可以将连续变量转换为离散的分箱，以便更好地与一些模型进行配合，或者使得数据更符合实际问题的特性。

方法

介绍

EqualFrequencyDiscretiser()

将值分为具有相似观测数的区间。

EqualWidthDiscretiser()

将值分为相等大小的区间。

ArbitraryDiscretiser()

将值分为用户预定义的区间。

DecisionTreeDiscretiser()

用决策树的预测值替换值，这些值是离散的。

GeometricWidthDiscretiser()

将变量分为几何区间。

KBinsDiscretizer

使用K均值对变量进行离散化。

## unsetunset异常值处理unsetunset

异常值处理能够提高模型的稳定性和预测能力，提高模型的鲁棒性。

方法

描述

Winsorizer()

将变量的值限制在自动确定的极值上

ArbitraryOutlierCapper()

将变量的值限制在用户确定的值上

OutlierTrimmer()

从数据框中删除异常值

## unsetunset缩放unsetunset

缩放方法可以帮助调整数据的分布，使其更符合模型的假设，从而提高模型的性能和鲁棒性。缩放方法比较适合用于线性模型、KNN和神经网络中。

转换器

描述

LogTransformer

对数转换器

LogCpTransformer

对数截断转换器

ReciprocalTransformer

倒数转换器

ArcsinTransformer

反正弦转换器

PowerTransformer

幂次转换器

BoxCoxTransformer

Box-Cox转换器

YeoJohnsonTransformer

Yeo-Johnson转换器

FunctionTransformer

允许自定义的函数应用于数据的转换器

PowerTransformer

将数据进行幂次转换，可选择是Yeo-Johnson转换还是Box-Cox转换

## unsetunset新的特征unsetunset

创造新的特征需要一定的想象力，但通常遵循一些基本模式。在创造新的特征时，需要根据数据的特点和问题的需求灵活运用不同的特征创建方法。

转换器

描述

MathFeatures

数学特征

RelativeFeatures

相对特征

CyclicalFeatures

周期特征

GroupedFeatures

分组特征

PolynomialFeatures

多项式特征

SplineTransformer

样条特征

## unsetunset特征筛选unsetunset

特征选择是指从原始特征集中选择出最具预测能力的特征子集的过程。有很多类型的方法，如下是一些基础方法：

方法

描述

DropFeatures()

根据用户确定的特征名删除任意特征

DropConstantFeatures()

删除常量和准常量特征

DropDuplicateFeatures()

删除重复的特征

DropCorrelatedFeatures()

删除相关的特征

SmartCorrelatedSelection()

从相关特征组中删除不太有用的特征

SelectBySingleFeaturePerformance()

根据单个特征模型性能选择特征

RecursiveFeatureElimination()

通过评估模型性能递归地移除特征

RecursiveFeatureAddition()

通过评估模型性能递归地添加特征

DropHighPSIFeatures()

删除具有高Population Stability Index的特征

SelectByInformationValue()

删除信息值较低的特征

SelectByShuffling()

如果对特征值进行洗牌会导致模型性能下降，则选择该特征

SelectByTargetMeanPerformance()

使用目标均值作为性能代理，选择性能良好的特征

ProbeFeatureSelection()

选择重要性大于随机变量的特征