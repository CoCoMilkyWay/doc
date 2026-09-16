# 特征工程（Feature Engineering）

FinTechHi FinTechHi 2025-01-29 23:34 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484918&idx=1&sn=9008dd00a657e0eca93212f22c34f6d5&chksm=fbfc34f4a6dd4105e2898ebed8c717e3e1e3225f1b0c95291fd954b2114b1890f66cb2f32ef8#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484918&idx=1&sn=9008dd00a657e0eca93212f22c34f6d5&chksm=fbfc34f4a6dd4105e2898ebed8c717e3e1e3225f1b0c95291fd954b2114b1890f66cb2f32ef8#rd)

特征工程（Feature Engineering）是机器学习流程中最关键的一步，使用领域知识从原始数据中提取有意义特征的过程。它是原始数据和有效机器学习模型之间的桥梁。强大的特征工程可以：

-   显著提高模型性能
    
-   降低计算复杂性
    
-   增强模型可解释性
    
-   创建更强大的模型
    
-   减少训练所需的数据量
    

#   

# ![](assets/001.png)

  

其中特征工程涉及到的技术要点可参考如下脑图：

  

![](assets/002.jpg)

1.Numerical Feature Transformations（数值特征变换）

-   Standardization (z-score normalization
    
-   Min-Max scaling
    
-   Robust scaling
    
-   Log transformation
    
-   Box-Cox transformation
    

#   

# ![](assets/003.png)

以scikit-learn库中StandardScaler类为例做标准化数据特征。目的是将数据的均值调整为0，标准差调整为1，从而使得数据具有相同的尺度。这是因为一些机器学习算法对特征的尺度敏感。

```
from sklearn.preprocessing import StandardScaler
```

执行结果如下：

```

```

2.Encoding Techniques

-   One-hot encoding
    
-   Label encoding
    
-   Target encoding
    
-   Feature hashing
    
-   Entity embeddings
    

  

![](assets/004.png)

继续以scikit-learn库中的OneHotEncoder类为例，可以将分类特征（categorical features）转换为一组二进制（0或1）特征。这个过程称为one-hot encoding。这个处理对于不能直接处理非数值数据的机器学习算法（如线性回归、逻辑回归、SVM等）特别有用。

```
from sklearn.preprocessing import OneHotEncoder
```

# 执行结果如下：

```

```

如果数据集中有多个分类特征，可以一次性对它们进行OneHotEncoder：

```
# 创建一个示例数据集，包含多个分类特征
```

3.Mathematical Transformations

-   Polynomial features
    
-   Interaction terms
    
-   Domain-specific ratios
    
-   Statistical aggregations
    

以scikit-learn库中PolynomialFeatures类为例，通过对原始特征进行多项式扩展生成的，这可以帮助线性模型捕捉非线性关系。

```
from sklearn.preprocessing import PolynomialFeatures
```

执行结果如下：

```
多项式扩展后的数据：
```

4.Temporal Features

-   Lag features
    
-   Rolling statistics
    
-   Time-based features (hour, day, month)
    
-   Fourier features
    
-   Wavelet transforms
    

![](assets/005.png)

5.Text Processing Techniques

-   TF-IDF
    
-   Word embeddings
    
-   N-grams
    
-   Topic modeling
    
-   Named Entity Recognition
    

![](assets/006.png)

文本处理主要针对NLP领域的，主要包括去除空格、去除标点符号等清理、也包括将文本拆分成单词后进行标记等等，不详细展开。

特征选择是机器学习中的一个重要步骤，旨在从原始特征集中选择最有用的特征，以提高模型的性能和可解释性。特征选择方法可以分为三大类：过滤方法（Filter Methods）、包装方法（Wrapper Methods）和嵌入式方法（Embedded Methods）：

![](assets/006.png)

1\. Filter Methods 

过滤方法在特征选择过程中独立于模型，通常基于统计特性来选择特征。这些方法简单且计算效率高，适用于初步特征筛选。

-   Correlation analysis：相关分析用于衡量两个变量之间的线性关系。常用的相关系数包括皮尔逊相关系数和斯皮尔曼相关系数。高相关性的特征可能包含冗余信息，可以去除。
    
-   Chi-square test：卡方检验用于衡量分类特征与目标变量之间的独立性。通过计算卡方统计量，可以选择与目标变量关系密切的特征。
    
-   Information gain：信息增益衡量特征对目标变量的不确定性减少程度。信息增益越大，特征对目标变量的区分能力越强。
    
-   Variance threshold：方差阈值方法通过计算每个特征的方差，去除方差低于某个阈值的特征。方差低的特征通常对模型贡献较小。
    

  

2\. Wrapper Methods

包装方法通过训练模型来评估特征子集的性能，选择最优特征子集。这些方法通常计算成本较高，但可以提供更好的特征选择结果。

-   Forward selection：正向选择从空特征集开始，逐步添加特征，每次添加使模型性能提升最大的特征，直到性能不再显著提升。
    
-   Backward elimination：向后消除从完整特征集开始，逐步移除特征，每次移除对模型性能影响最小的特征，直到性能显著下降。
    
-   Recursive feature elimination：递归特征消除通过训练模型，递归地移除权重最小的特征，直到达到预定的特征数量。RFE 可以与不同的模型结合使用，如线性回归、支持向量机等。
    

  

3\. Embedded Methods

嵌入式方法在模型训练过程中进行特征选择，利用模型的内在特性来选择特征。这些方法通常计算效率高，且能提供良好的特征选择结果。

-   LASSO：（Lasso Regression）在损失函数中加入 L1 正则化项，通过惩罚特征的绝对值，使得一些特征的系数变为零，从而实现特征选择。
    
-   Ridge regression：岭回归（Ridge Regression）在损失函数中加入 L2 正则化项，通过惩罚特征的平方和，减少多重共线性问题，但不会将特征系数变为零，因此不直接用于特征选择。
    
-   Elastic Net：弹性网（Elastic Net）结合了 L1 和 L2 正则化的优点，通过在损失函数中加入 L1 和 L2 正则化项，既能选择特征，又能处理多重共线性问题。
    
-   Tree-based importance：基于树的重要性方法利用决策树或随机森林等树模型的特性，通过计算特征在树结构中的重要性得分来选择特征。特征的重要性得分可以通过特征在树中分裂节点的次数或信息增益来衡量。
    

  

在量化投资过程中，比如我们在基础行情数据基础上挖掘特征时，也会应用到一些“算子”，或“操作符”，“表达式”。

比如我们针对股票的快照基础特征有：收盘价（Close）、成交量加权平均价格（VWAP）、交易量（Volume）等。这些特征可以直接用于分析，也可以作为其他表达式的输入参数，衍生出新的特征。

其中典型的“算子”主要包括：

1\. 一元操作符（Unary Operator）

-   绝对值（Abs）：计算数值的绝对值。
    
-   符号函数（Sign）：返回数值的符号（正、负、零）。
    
-   对数（Log）：计算数值的对数。
    
-   CSRank：一种排序方法，用于对数据进行排序。
    

  

2\. 二元操作符（Binary Operator）

-   加法（Add）：计算两个数值的和。
    
-   减法（Sub）：计算两个数值的差。
    
-   乘法（Mul）：计算两个数值的积。
    
-   除法（Div）：计算两个数值的商。
    
-   幂运算（Pow）：计算一个数值的幂。
    
-   大于（Greater）：比较两个数值，返回布尔值。
    
-   小于（Less）：比较两个数值，返回布尔值。
    

  

3\. 滚动操作符（Rolling Operator）

-   参考值（Ref）：获取过去某个时间点的值。
    
-   均值（Mean）：计算滚动窗口内的平均值。
    
-   总和（Sum）：计算滚动窗口内的总和。
    
-   标准差（Std）：计算滚动窗口内的标准差。
    
-   方差（Var）：计算滚动窗口内的方差。
    
-   偏度（Skew）：计算滚动窗口内的偏度。
    
-   峰度（Kurt）：计算滚动窗口内的峰度。
    
-   最大值（Max）：计算滚动窗口内的最大值。
    
-   最小值（Min）：计算滚动窗口内的最小值。
    
-   中位数（Med）：计算滚动窗口内的中位数。
    
-   平均绝对偏差（Mad）：计算滚动窗口内的平均绝对偏差。
    
-   排名（Rank）：计算滚动窗口内的排名。
    
-   Delta：计算滚动窗口内的变化量。
    
-   加权移动平均（WMA）：计算滚动窗口内的加权移动平均。
    
-   指数移动平均（EMA）：计算滚动窗口内的指数移动平均
    

  

这些操作符可以用于分析价格趋势、波动性和其他统计特性。

4.配对滚动操作符（PairRolling Operator）

用于衡量两个变量之间的关系，常见的配对滚动操作符包括：

-   协方差（Cov）：计算两个变量的协方差。
    
-   相关系数（Corr）：计算两个变量的相关系数。
    

  

以上所表达的具体应用，可以参考一个简单的代码示例：

```
import pandas as pd
```

  

* * *

量化书籍推荐：

说起机器学习的书籍，大家肯定都会推荐周志华老师的《机器学习》，我记的2017年去一个朋友家，他说他正在研究机器学习，买了好多书，然后带我去书房，结果翻了好几本都还没有撕上面的塑料膜，他就随手送了我一本，这几天拿出来粗浅的再翻了一遍，有不懂的地方，也有结合实践的一些更深刻的认识。同时也计划自己再买基本机器学习相关的书籍看看。一眼就看中了：《机器学习实战》这本书（优先想看国外的著作）。

《机器学习实战》由Peter Harrington撰写，是一本面向实践的书籍，旨在帮助读者理解并实现机器学习算法。本书基于Python语言，并利用Scikit-Learn和TensorFlow等流行的机器学习库进行示例代码的编写。书中不仅介绍了机器学习的基础理论，还提供了大量的实例和源码，使读者能够亲手实现这些算法，并应用于实际问题中。

此书的一大亮点是其实用性。它通过一系列具体的例子来讲解如何应用机器学习算法解决实际问题，例如邮件过滤、数据分类等。对于初学者而言，《机器学习实战》采用了简洁明了的语言和循序渐进的方式介绍机器学习概念，避免了复杂的数学推导，使得没有深厚数学背景的人也能轻松上手。书中提供了大量Python代码示例，鼓励读者动手实践，这对于提高读者的实际操作能力和加深对机器学习算法的理解非常有帮助。作者精心挑选了一些贴近生活的案例，让读者能更直观地感受到机器学习的应用场景，从而激发学习兴趣。

虽然本书在实用性方面表现出色，但其理论部分相对较弱。许多重要的数学公式和理论细节并未深入探讨，这对于想要深入了解机器学习原理的读者来说可能不够充分。某些章节使用了已过时的API或技术，如Yahoo位置API，这要求读者自行寻找替代方案或更新代码以适应当前环境。

综上所述，《机器学习实战》非常适合那些希望快速入门机器学习领域并希望通过实践来巩固所学知识的初学者。然而，如果读者追求的是更加深入的理论研究或是高质量的代码实现，则需要结合其他更为专业的资源来进行补充学习。这本书确实为新手提供了一个良好的起点，但对于进一步的学习和发展，建议读者参考更多理论性强的书籍和最新的研究成果。

如果有机器学习方面的大师，烦请能为入门的朋友推荐一些实用的书籍或使用的资源，感谢。