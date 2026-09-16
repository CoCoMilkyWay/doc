# 量化交易领域10大高效机器学习算法盘点（附实例源码）

量化君 量化君也 2024-05-13 15:37 广东

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyODI5ODcyMA==&mid=2247486013&idx=1&sn=b45a69dc993e6e82100df85d70e15bdb&chksm=c3b0dec3ac3299870e565734730194c20eed102ba963e606b76dd812d26dfe6f232a537f397a#rd](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247486013&idx=1&sn=b45a69dc993e6e82100df85d70e15bdb&chksm=c3b0dec3ac3299870e565734730194c20eed102ba963e606b76dd812d26dfe6f232a537f397a#rd)

![](assets/001.png)

  

在金融投资和量化交易领域，机器学习算法越来越受欢迎，也越来越普遍，因为咱人类一般通过观察能发现因果之间的线性关系，而非线性关系就不得劲儿了，于是乎，就要靠着这些机器学习算法帮助咱做出更明智的投资交易决策。  

  

**在这篇文章里面，咱唠唠在金融投资和量化交易当中，常用的并且效果还不赖的10大机器学习算法，会大概讲述其基本工作原理、用法用途和代码案例**，主要是为量化萌新们起到“算法清单”的作用，文章篇幅有限，难以面面俱到，还望海涵~开整~~

  

**一、线性回归(Linear regression)**

线性回归应该可以说是最常用的一种统计模型了，高中就接触过的最小二乘法OLS就属于线性回归，你瞧，这也算是早期接触机器学习的案例了。

  

**线性回归基于一个或多个自变量预测因变量的值，它之所以被称为“线性”，那是因为它假设因变量和自变量之间的关系是线性的**，形式如y=a0+a1\*x1+a2\*x2+...+an\*xn，其中x是自变量，y是因变量，a就是回归系数，a0又被称为截距。

  

![](assets/002.jpg)

  

在金融投资和量化交易领域，线性回归经常被用来建模和预测金融时间序列/横截面数据，比如证券价格、因子收益、汇率和利率等等。它可以用来识别不同变量/因子之间的关系，并基于这些关系对未来值进行预测。

  

线性回归主打的优点就是其简单性和可解释性，不信你瞧，咱常见的资本资产定价模型（CAPM）、套利定价模型（APT）和Fama-French三因子等等模型都是表达成这种形式。

  

线性回归模型除了应用广泛之外，还非常容易实现，即使在大数据集上，它的训练速度也相对较快，并且还可以通过使用虚拟变量来处理缺失数据和分类变量。

  

现在使用这些机器学习算法已经非常方便了，都是封装好的库（例如scikit-learn），直接调用就可以了，下面来看看线性回归的实例源码。

  

```
import numpy as np
```

  

输出结果：  

  

```
预测：[1. 2. 3. 4.]
```

  

这段代码是对 X 数组中的数据进行线性回归模型拟合， y 数组作为目标变量(因变量)，可以看出X有4个样本点，每个样本有2个特征，会自动学习出2个回归系数和1个截距，最终的训练模型为y=0.25+0.25x1+0.25x2。

  

这里特别说明的是，虽然上面的代码简单，但**现在的机器学习库的使用流程基本都是一样的：先从库(sklearn)中导入需要的模型(LinearRegression)，然后导入数据进行训练(fit)，最后便可以使用训练好的模型对新数据进行预测(predict)，如果觉得有需要，可以查看模型的关键参数(coef\_和intercept\_ )。**下文所有算法模型的建模流程都是遵循这种三板斧流程，不再赘述。

  

不过一般情况下，训练模型用的数据集称为训练集，给训练好的模型进行预测的数据集称为测试集，两个数据集一般数据是不重叠、没有交集的，咱这里是偷懒了，请注意区分。  

  

**二、逻辑回归(Logistic regression)**

不要看到这个算法里面有“回归”(regression)的字样，就以为它是像线性回归那样用来完成回归任务的，**其实它主要是被用来完成分类任务的。通常是基于一个或多个自变量预测二元结果的概率。**

  

它的模型结构是y=1/(1+exp(a0+a1\*x1+a2\*x2+...+an\*xn))，就是在线性回归的基础上，套上了一层Sigmoid函数y=1/(1+exp(x))，无论exp(\*)当中的数值是什么范围，都能将y限制到0~1之间，很好地完成二分类任务。

  

在金融投资和量化交易领域中，逻辑回归就是经常被用于分类任务，例如证券价格是上涨还是下跌、财务报表当中是否存在欺诈行为或者企业净利润率是否超额上升。

  

![](assets/003.png)

  

逻辑回归的主要优势和线性回归一样，实现和解释起来都相对简单，即使在大型数据集上训练也非常快速。除此之外，逻辑回归具有“概率性”的特性，这意味着它可以输出概率形式的预测结果，而不仅仅是二元预测，这一点在量化交易当中非常有用，能衡量其中不确定性或风险水平。

  

咱来看看逻辑回归的使用实例，如下所示，从整个流程来看，跟线性回归模型是一样的，只不过对于分类任务，y的标签数值要改为0或1，用来表示类别。  

  

```
import numpy as np
```

  

  

**三、决策树(Decision trees)**

**决策树之所以被称为“决策”树，顾名思义，能根据数据集的特征进行预测，它通过数据构建一个类似树状的决策模型来工作，每个分支代表不同的决策或结果。**

  

![](assets/004.png)

  

在金融投资和量化交易领域中，决策树通常被用于分类任务。决策树的主要优势除了相对简单易懂和解释较强外，关键它还能够处理复杂的数据集，并能够识别特征与目标变量之间的非线性关系。不过，如果决策树没有经过适当的修剪，可能会出现过拟合的问题，从而降低其泛化能力。

  

决策树的使用案例如下所示，流程跟上面两种算法是一样的，注意是分类任务就好。

  

```
import numpy as np
```

  

对了，你还可以指定用于拆分树的准则类型，例如“gini”或“entropy”，并设置其他参数，如树的最大深度或叶节点所需的最小样本数，在scikit-learn文档中可以找到完整描述。

https://scikit-learn.org/stable/modules/tree.html  

  

**四、随机森林(Random forests)**

随机森林属于上面刚介绍的决策树的扩展，基于集成学习的原理，用于进行更强大和可靠的预测。**它通过创建一组决策树，并使用每棵树所做预测的平均值来进行最终预测，就类似于现实当中咱一群人投票，然后少数服从多数那样。**

  

![](assets/005.png)

  

随机森林一般也是被用于分类任务，一般具有比较高的准确性，并且往往比单个决策树具有更好的泛化能力。不过，与单个决策树相比，随机森林的解释性相对差一些，因为预测是基于许多树的平均值，而不是单个树。

  

在使用当中，从sklearn里面导入 RandomForestClassifier 模型后，需要设置森林中树的数量(n\_estimators )，树的最大深度(max\_depth)和随机种子(random\_state)，其他的部分，就是跟传统的三板斧流程一样的了。

  

```
import numpy as np
```

  

**需要特别说明的是，load\_data()是抽象出来的函数，需要自己根据自身应用情况实现，主要目的是用来加载训练集数据(X\_train)和标签(y\_train)、测试集数据(X\_test)和标签(y\_test)**，组织形式跟上面介绍过的3个算法是一样的，如果当前自己还没有确切建模任务的话，可以根据我之前的两篇文章[《手把手教你，利用机器学习模型，构建量化择时策略》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&chksm=c21ba71af56c2e0c95390b450ac86bd1e3ff7af387e0d8d98d8f2a7c2bcefe8d69d2e7262035&scene=21#wechat_redirect)和[《投资经理3周须开发4000个量化因子，手把手教你4行核心代码轻松应对》](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)中的数据准备部分构建因子数据和打上对应的标签。

  

如果也不想自己组织数据，想马上就开箱使用，那可以直接使用sklearn机器学习库datasets模块，里面自带了各种机器学习任务需要用到的数据集，首先你可以使用make\_regression或make\_classification函数自定义生成自己需要的回归/分类数据集，其次你也可以使用现成的数据集，例如回归任务常用的糖尿病数据集(load\_diabetes)，分类任务的鸢尾花数据集(load\_iris)。

  

就以随机森林这次的分类任务为例，使用鸢尾花数据集(load\_iris)，咱先看一下具体的数据形式。

  

```
import numpy as np
```

  

![](assets/006.png)

  

iris包含了 150 个鸢尾花的数据，其中每个样本有 4 个特征，分别为萼片长度、萼片宽度、花瓣长度和花瓣宽度，以及对应的类别标签，label的0、1、2分别对应花的品种Iris Setosa、Iris Versicolour、Iris Virginica）。

  

于是乎，要在随机森林当中使用这个数据集来训练和测试模型，只需要将应用实例当中的这句代码

  

```
# 加载训练集和测试集数据
```

  

修改为  

  

```
from sklearn import datasets
```

  

为了方便阐述和展示，下文依旧使用抽象函数load\_data()表示训练集和测试集数据的加载，不再赘述。  

  

**五、K最近邻（KNN）**

K最近邻（K-Nearest Neighbors，KNN）是一种常用于分类和回归任务的机器学习算法，**它大概的原理是通过找到离给定数据点最近的K个数据点，并利用这些数据点的类别或数值来进行预测。**相信大多数人都听过这种说法，“你的收入就是身边 5 位好友收入的平均值”，KNN贯彻的就是这种“人以群分，物以类聚”的理念。

  

![](assets/007.png)

  

在金融投资和量化交易领域中，KNN通常用于分类任务居多，也可以用于回归。KNN的主要优势之一是相对简单易懂，并且容易实现，对缺失值不太敏感，**最大的缺点就是，它对于K值的选择比较敏感。**除此之外，在特征/因子数量相对于样本数量过大的情况下可能表现比较拉胯，在大型数据集上进行KNN预测也可能需要比较大的计算量。  

  

```
import numpy as np
```

  

**六、K均值聚类算法(K-Means)**

说完KNN，就顺道儿来说一下它的亲戚K-Means，从称呼上看起来很像，底层原理也很像，但干的却是不一样的活儿。

  

**K-Means一般用于聚类(clustering)任务，而KNN一般用于分类(classification)任务，虽然是一字之差，但用途却不一样。**咱可以先把实例代码贴出来，你就会发现它跟别的算法代码有个显著的区别。

  

```
import numpy as np
```

  

看见木有，**别的算法一般训练模型时都需要同时输入特征/因子数据X和标签数据y，而K-Means只需要输入特征/因子数据X，前者这种训练方式被称为监督学习(Supervised learning)，后者则被称为无监督学习(Unsupervised learning)**，前者就相当于让你自学的时候，既发给你试题，也发给你参考答案，后者是只发试题，木有答案。

  

那有什么用呢？也是起到“人以群分，物以类聚”的划分作用，因此K-Means叫聚类算法，比如说现在A股有5000多支股票，申万把它们划分为31个行业，你觉得这样划分不合适，可以给它们设定不同的属性/因子和想分成多少个行业/概念/风格/板块(例如上面实例的聚类数是2)，K-Means算法就可以把这5000多支股票按自己的要求划分出来，在每个簇当中，里面的股票在你设定属性/因子方面肯定都是极其相似的，属于你自己的行业/概念/风格/板块。**很多时候，你会惊叹，八竿子打不着的股票怎么会在这些方面这么相似。**

  

![](assets/008.png)

  

  

**七、支持向量机（SVM）**

**支持向量机（Support Vector Machines，SVM）最初的设计是用来解决二分类问题，后来扩展到多分类问题**，比如说之前开发的大盘择时策略“预测沪深300指数涨跌”就属于典型的二分类问题，“涨”是一个类别，“跌”就是另一个类别。

  

它通过寻找一个最大间隔超平面将两类样本线性区分开来，并且保证两侧样本的最近边缘点到这个平面的距离是最大的，由于最大间隔超平面仅取决于两个类别的边缘点，这些点就被称为支持向量，这就是“支持向量机”名称的由来。

  

![](assets/009.png)

  

如果数据点在原始空间不可分的话，就将低维不可分的数据映射到高维线性可分，于是乎，SVM的主要优势之一就是能够处理高维数据，并且能识别特征与目标变量之间的复杂关系。

  

不过，与其他一些机器学习算法相比，SVM的训练计算量可能更大，并且由于基于复杂的优化问题，解释性就相对差一些。对了，为了将数据从低维映射到高维，SVM中核函数的选取就非常关键，常用的核函数有线性核、多项式核、高斯核（RBF核）和Sigmoid核。

  

```
import numpy as np
```

  

**八、朴素贝叶斯(Naive Bayes)**

朴素贝叶斯是一种基于贝叶斯定理进行预测的机器学习算法，**它之所以被称为“朴素”是因为它假设数据集当中的所有特征都是相互独立的**，而在现实世界的数据中当然肯定不是这样的。

  

![](assets/010.png)

  

尽管有这个假设，朴素贝叶斯算法通常用起来效果也不错，并且在金融投资和量化交易当中经常使用。朴素贝叶斯算法常被用于分类任务，比如预测指数第二日涨跌、财经新闻的正负面情或者财务报表是否掺假。

  

朴素贝叶斯算法的主要优势之一就是其简单性和易于理解了，就连很多成功学文章和书籍中，都经常倡导要“贝叶斯式”思考。这个模型训练起来也非常快，即使是在大型数据集上。并且，当底层数据受到某些类型的噪声干扰影响，或者特征数量相对于样本数量过大时，朴素贝叶斯算法往往也都有良好表现。

  

```
import numpy as np
```

  

**九、神经网络(Neural networks)**

**神经网络是一种受到人脑结构和功能启发而研发出来的机器学习算法，模型结构由大量相互连接的节点(神经元)组成，模拟人脑的机制用于处理和传输信息。**神经网络特别适用于涉及模式识别和预测的任务，并且已被广泛应用于各种领域和场景，取得了非常显著的成果。

  

![](assets/011.png)

  

神经网络模型在回归和分类任务上都非常支棱，只需要人为地确定模型结构，然后就能够在没有显式编程的情况下学习、迭代和适应新数据，它还可以处理大型和复杂的数据集，并能够识别特征与目标变量之间的非线性关系。

  

与其他一些机器学习算法相比，神经网络的训练可能需要消耗更多的计算资源，并且由于其中复杂的网络结构，因此可解释性就差很多，如果设计和训练不当的话，神经网络非常容易过拟合。

  

```
import numpy as np
```

  

  

**十、集成学习(Ensemble learning)**

集成学习(Ensemble learning)并不是特指某一个算法，而是一个算法大类，或者说是训练和组合模型的思路或方法。**在机器学习当中，单个模型运行时可能表现没那么好，但同时将多个模型组合起来，“三个臭皮匠顶个诸葛亮”，就会变得非常强大，这种多个基础模型/算法的组合，就被称为集成学习。**

  

集成学习一般分为两大类：Bagging(装袋法)和Boosting(提升法)。这两种方法都是将多个弱模型组合在一起，形成一个强模型，但它们之间最明显的区别是，**Bagging中的多个弱模型都是并行单独训练，然后再组合在一起，而Boosting是串行训练，下一级弱模型是根据前一级弱模型的“残差”针对性训练，用来提升上一级的“短板”，最终再组合在一起。**其实集成学习还有更为复杂的Stacking(堆叠法)和Cascading(级联法)，有兴趣的话，可以自己去探究一下。

  

**Bagging模型结构：**

![](assets/012.png)

  

**Boosting模型结构：**

![](assets/013.png)

  

Bagging集成学习其实咱之前已经见过了，那就是随机森林，在金融投资和量化交易领域，Bagging用得最多的就是它。  

  

Boosting集成学习就比较多了，常见的有：梯度提升树GBDT、自适应提升算法Adaboost、极限梯度提升算法XGBoost和轻量级梯度提升算法LightGBM。以前常用XGBoost组合多因子模型，现在多流行用LightGBM，那就以LightGBM作为实例展示吧。

  

```
import numpy as np
```

  

量化交易领域的10大常用机器学习算法就盘点完了，不知道你有没有发现，再复杂的机器学习算法，利用现成的机器学习算法库(如sklearn)，按照“三板斧”流程，十几二十行代码就可以建模完毕，麻麻再也不用担心咱的算法实现。

  

这就是本文想要达到的目的，以后大伙儿大部分时间只需要专注于量化任务拆解和数据整理，是分类任务(如预测**涨跌**)，还是回归任务(如预测**涨跌幅**)，接着把特征/因子数据整理好，按照这篇“机器学习算法清单”的索引，按需按代码实例使用相应算法就搞掂了，顺藤摸瓜，按图索骥。

  

**内容来源/参考：**

_Christophe Atten，2022.12，《Top 10 machine learning algorithms in Finance》_

_Chainika Thakar，2023.01，《Top 10 Machine Learning Algorithms For Beginners》_

_机器之心，2019.03，《机器学习必学10大算法》_

_楷哥，2020.10，《集成学习》_

_周志华，2016.01，《机器学习》_

  

★

往期回顾

  

★

  

\------量化社群------

[量化藏经阁Max](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485753&idx=1&sn=0bff8f88e77269364a7ca2c5c5adcb79&chksm=c21baab6f56c23a0ffffcac74fb9fa7ae5ae87230442be5e3c8e3d131bd321416855cbfaabfb&scene=21#wechat_redirect)

[量化藏经阁2024](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485755&idx=1&sn=cbbcc52e7542ed7dcb9ec62ba4ac36cf&chksm=c21baab4f56c23a2d9bf705f47d72fd65f2e82fa3c628978db49c352f0cb125a0eeb2dffc8be&scene=21#wechat_redirect)

\------量化策略------

[桥水全天候策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485885&idx=1&sn=d687f4296450cae754bd1b801ce7bd34&chksm=c21baa32f56c2324b137bf77796ce740cf9ca6b2c66f4ea4f9c60f1658b170cae66ae45ec5e3&scene=21#wechat_redirect)  [风险平价策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485904&idx=1&sn=7f9a873f81ea6dcbc6e5b9af2d659fa5&chksm=c21baa5ff56c23495174192875c6ea4a6cdfa52d9db3646fa52765acc68bdfdd7334859b1377&scene=21#wechat_redirect)

[聪明钱](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483685&idx=1&sn=e1c02c587859ffce1e0497fe6c7b2651&scene=21#wechat_redirect) [TrendModelSys](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484039&idx=1&sn=defcd9c0c03653ed1078ba98392af315&scene=21#wechat_redirect)  [张坤策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483753&idx=1&sn=ecbe89280d78f897b394a97e06ffd6b5&scene=21#wechat_redirect)

[RSRS](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483898&idx=1&sn=d792431094001b4e64360a901b92e6bf&scene=21#wechat_redirect) [北向资金](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483921&idx=1&sn=242f6a721077eaf46b7340c4ddedb76a&scene=21#wechat_redirect) [F-Score](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483724&idx=1&sn=16645331a226874c8110ecfee3875e96&scene=21#wechat_redirect) [鱼身策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484311&idx=1&sn=8a064c83e9412d0cc5a05698f4c7aa54&scene=21#wechat_redirect)

[TrendPattern](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484545&idx=1&sn=20905b287eee64d65843ba4687ad8621&scene=21#wechat_redirect) [波动率收敛](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483852&idx=1&sn=00e3211e3ad821606e6d10b9bdc09b5a&scene=21#wechat_redirect) [RSJ策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484191&idx=1&sn=191cbea3fc1bcdfb0f90c2956e49c65c&scene=21#wechat_redirect)

[期货Alpha](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484095&idx=1&sn=56d3df957c23f8043667b9fa190d1a36&scene=21#wechat_redirect)  [跨品种套利](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484021&idx=1&sn=de75d6fb7b8e30c4e6a6b465ed608791&scene=21#wechat_redirect) [GARP策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484628&idx=1&sn=91adbe6e039e86324b2136f733fb4e72&scene=21#wechat_redirect)

[MACD形态](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483870&idx=1&sn=8936877f7f597a2bbb9ef8e2ec9887cb&scene=21#wechat_redirect)  [导数策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484119&idx=1&sn=40636937af309698dd56a24a129dad8e&scene=21#wechat_redirect)  [Trendflex](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484458&idx=1&sn=c8f01ddeadd954f432b91bcfe00afc3b&scene=21#wechat_redirect)

[绩优小市值](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484219&idx=1&sn=b4b6b583d379ec5920807d580559578a&scene=21#wechat_redirect)  [漂亮50](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483810&idx=1&sn=cbf7c998e8b95f029bd98d16b75a89ce&scene=21#wechat_redirect)  [操盘手](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484010&idx=1&sn=8f425ffec08b044aff03cf8a1f51b16b&scene=21#wechat_redirect)  [Rumi](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484064&idx=1&sn=cfd99a47728f889692845ccb7b0a099d&scene=21#wechat_redirect)

[AI择时](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484565&idx=1&sn=9fedbb0b8904fac5e4cb6df582e94bf8&scene=21#wechat_redirect)  [K线面积法](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484161&idx=1&sn=85b980eb19f4d016b7f1a42ffa9bf7a5&scene=21#wechat_redirect)  [零编程策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484518&idx=1&sn=24270a92ae7e4aada59981a479adf38e&scene=21#wechat_redirect) 

[贴水策略](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484405&idx=1&sn=664567f274c737278867402e0b2277c2&scene=21#wechat_redirect) [概率密度策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484675&idx=1&sn=e8a5e701e58ddb2e34db793f0ec59d9c&chksm=c21ba68cf56c2f9ab4d37d956e70250dfd59af25b636681f8fae8d9557e4c639e45c1633429d&scene=21#wechat_redirect)  [一致预期](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484960&idx=1&sn=bacb21875c2a4b377a7d35c47d03b21b&chksm=c21ba5aff56c2cb97a55bab6a7630d20e5cf19fb9f6743d9e8c49f186f19d6a5e3ff666c43d7&scene=21#wechat_redirect)

[RSRS复现1](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485087&idx=1&sn=f42bcb657ce82654a537194992787157&chksm=c21ba510f56c2c06459d13f193613df9d633679b2fc5089054de9953d652f94b46a836690790&scene=21#wechat_redirect) [RSRS复现2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485225&idx=1&sn=dba12368183359f98f7b0f60ea6a38a4&chksm=c21ba4a6f56c2db0684151422eb24311f06902d656ce3654bfd4954aceeb4571cdbdd26712dd&scene=21#wechat_redirect)  [ICU均线](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485797&idx=1&sn=cb4c3026e855879e1fa57e4f7d1e8ee3&chksm=c21baaeaf56c23fcb81d4a01669c3c743ba1dc101053a8b0f0a0339effac391938fce0a4fea2&scene=21#wechat_redirect)

[野路子策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485305&idx=1&sn=eb63adecb80b44b8ee57d050495da51c&chksm=c21ba4f6f56c2de037a52ab7b5c74ae31ace34863ed6d9bad20486e583e09d2643e2150d7a3d&scene=21#wechat_redirect) [ETF轮动](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485362&idx=1&sn=28d5dc92d07758cdc922cf81e5cc5e26&chksm=c21ba43df56c2d2b2a2185c28297745c1108163ab6ae2274676f3605eed9bf10f80ad681db31&scene=21#wechat_redirect) [ETF轮动2](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485425&idx=1&sn=d25d93f195a38d64976f6cd0f78bd21d&chksm=c21ba47ef56c2d68436195945c4d1a85887736a36366cf207f19aa9f5cea36ceb936f107a491&scene=21#wechat_redirect)   

[菜场大妈&马科维茨](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485558&idx=1&sn=a376f48a64e624ca543f4ad6d947f8f2&chksm=c21babf9f56c22effd22cff1aefd7c02835f96a840b08d65772af4d584320066e89571dbf5b7&scene=21#wechat_redirect) [多赚200%](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485503&idx=1&sn=436532c5379f99d18307c2841b150020&chksm=c21babb0f56c22a6eb876387adf688580acd97e2e4a49b1f2352833f45e22fcbde11509293ad&scene=21#wechat_redirect)

[美债&A股择时](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485683&idx=1&sn=470100d1c72e65d5f9ae4116e480617c&chksm=c21bab7cf56c226a9b8d699c6504d982240a1b65da0b832df2e6723cd266c31d302a3eb5b6a8&scene=21#wechat_redirect)  [价比斜率套利](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485960&idx=1&sn=3ac032c71b7aafeb15d9bbb0b84f9faf&chksm=c21ba987f56c20914d85503f959c7b0912b1189b30af329e408375c6b7ed203c706a55e30d54&scene=21#wechat_redirect)  

[量化兵器库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483659&idx=1&sn=4c44a69d92bf5fdcb57ae64f3f7bab01&chksm=c21ba284f56c2b92aadecee7a9b50d507198c87b64c7355d23c178756b1ef4348105d58a2ac8&scene=21#wechat_redirect)

\------心得杂谈------

[年化577倍](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484340&idx=1&sn=b415703a642e2b3c1a04481af017108f&scene=21#wechat_redirect)  [抄底&摸顶](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484287&idx=1&sn=5de0c792a1d7a56bf8867656d919c07e&scene=21#wechat_redirect)  [策略开发](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483999&idx=1&sn=1c77888217e83b4dab4961bc2b3b8ce5&scene=21#wechat_redirect)

[量化入门](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484482&idx=1&sn=7b98097f0a0a48728aeec452a834f1fc&scene=21#wechat_redirect)  [量化神作](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483706&idx=1&sn=7c45148b63cd2afd102da9da08609073&scene=21#wechat_redirect)  [量化书单](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483782&idx=1&sn=b80c2ee25c6f9f8fd88b7c1dee9513ef&scene=21#wechat_redirect)  [他](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483840&idx=1&sn=8cce9b5875f11d57945a1666f0e03591&scene=21#wechat_redirect)

[个人量化](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484469&idx=1&sn=ecfdb2b3f3e723fd417c0bddbd957b6b&scene=21#wechat_redirect)  [量化误解](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485473&idx=1&sn=4c71320bde8a62db39ee807dc4a206a8&chksm=c21babaef56c22b8846e2a4b1c499cd1ffae011276bd06c8cad172453b9d4d905578da0c71cf&scene=21#wechat_redirect)  [高收入背后](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484426&idx=1&sn=e0d282978280a65b4d3270c050fe71bf&scene=21#wechat_redirect)

[未来函数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484081&idx=1&sn=6076ced2c2418de2d8e5d77f2162ea07&scene=21#wechat_redirect) [回测&过拟合](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484577&idx=1&sn=6492bc8164649e3d85d015410c9db8a6&scene=21#wechat_redirect) [回测&实盘](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484586&idx=1&sn=545202b3c6a10f87e5f03be0f00a2cb2&scene=21#wechat_redirect)

[Alpha&风险因子](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484663&idx=1&sn=b92ae7684ce15f839cdcdbe7ae8c0a37&scene=21#wechat_redirect)  [MACD参数](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484259&idx=1&sn=fdcb626ce9c07fca5c9362978d81a2a3&scene=21#wechat_redirect)

[资金流](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484049&idx=1&sn=78b94c8055e6822e949180d942b00058&scene=21#wechat_redirect) [吃贴水](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484388&idx=1&sn=f165f6ca0ab5c0e36fc320e4dbf0e8e0&scene=21#wechat_redirect) [回测提速](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483736&idx=1&sn=334f2395a881328014c2f2bc1568e89b&scene=21#wechat_redirect) [量价背离](https://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247483796&idx=1&sn=0f783208f9dd1994a21964b715bdf63e&scene=21#wechat_redirect)

[自学路径](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484712&idx=1&sn=9fdf003c783b4bc053b90736ebbb8435&chksm=c21ba6a7f56c2fb1e87cf876cba0c2620244840c339666072447a0c14516dbeb686ca2e65702&scene=21#wechat_redirect)  [文章合辑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484689&idx=1&sn=1e1c6ad82946f9abd0cada5e0092b517&chksm=c21ba69ef56c2f883068c5dbb559d0b61b206b16f32afd908ea12a3cb93d2fbaddea5e1ac3d8&scene=21#wechat_redirect)  [151个策略](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484775&idx=1&sn=90a7e0d3786f9dd2d97a7ba95ec69318&chksm=c21ba6e8f56c2ffe64eb9fe0d2f30ba8460d53997401f00b79a91e5981a9ba2ab21a000e4d2b&scene=21#wechat_redirect)  

[chatGPT选股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484803&idx=1&sn=a96365d1b1f719a0e83a60ef1c4b0165&chksm=c21ba60cf56c2f1a467ba8d5728fcbbc1319ab4817812c6dde43346dc1ea892a19539d558592&scene=21#wechat_redirect)  [量化注册制](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247484876&idx=1&sn=cf7d6c875d2163bcce200946e09e4e82&chksm=c21ba643f56c2f5514f04bec3fcc62b4028b3aa67fbc81487106336cf4dec8543f1c58d30a1f&scene=21#wechat_redirect)  

[5年131倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485243&idx=1&sn=2c2903bce6d0de4f7480ab30c4139124&chksm=c21ba4b4f56c2da23deaa897576c6617653a7dd1d9186fdec53ba42d813a628eaf7132eddaf3&scene=21#wechat_redirect)  [量化编程神器](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485006&idx=1&sn=ec989b1a9f2d74f669509dc7ce561710&chksm=c21ba5c1f56c2cd7e02fba70dab2e8236ddbc6aa05d6cf7ad7fc9205c6fe1f4f7f29461d6f6b&scene=21#wechat_redirect)

[4000因子](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485037&idx=1&sn=dad40d6cdb8482fdf1e6f94690f2494e&chksm=c21ba5e2f56c2cf48767632408133f74e3e23dbd0aac285e1f169d2d7f912516d178b04da22d&scene=21#wechat_redirect)  [因子库](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485053&idx=1&sn=c5e2113de913cfa7c6834e7ca8c169fe&chksm=c21ba5f2f56c2ce48db75fe65827ce53ab986d2cd342d025979dd46180f14c8cdaa1d6b40184&scene=21#wechat_redirect)  [量化神集](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485464&idx=1&sn=782255a6c21ac469dc7fb85bde8699a4&chksm=c21bab97f56c2281ce0d25b95fbc689322fecd47952f24ce8e29e35da0f24891bce15dda51fb&scene=21#wechat_redirect)

[五穷六绝七翻身](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485290&idx=1&sn=0a2ffe4e238b861befdac4dce35f380e&chksm=c21ba4e5f56c2df3fc3d90a8aa58c35eea49489aa11becd2d4be46ae96c4e4b5b917f0604785&scene=21#wechat_redirect) [量化砸盘](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485487&idx=1&sn=dcf8ca1e44357071363ca63daca0f270&chksm=c21baba0f56c22b6b352b30d7e5bb21f523f4268eb1edaec0ff4b3472199a5432beb920f505f&scene=21#wechat_redirect)

[量化深坑](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485449&idx=1&sn=e228c79ce83db37b1c4360347439ddf8&chksm=c21bab86f56c22909465f838d3eb66009058cdfbe63f8a64f272d6517328d6ff4f4f4e216b93&scene=21#wechat_redirect)  [老胡炒股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485272&idx=1&sn=11e9d986e865585aa6b82ebdf28ffde0&chksm=c21ba4d7f56c2dc10545527e2fa965adde6559c1ffca60f5c1acff0413cf5616b72e1d56f661&scene=21#wechat_redirect)  [私募上班](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485250&idx=1&sn=294038b08fe03a700052aa6e94aea1f2&chksm=c21ba4cdf56c2ddb2831a4da44609bc7c323d03c0897a57022fa937501bf2c18f83ac417490c&scene=21#wechat_redirect) 

[机器学习算法Top10](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485534&idx=1&sn=e24e01705f49ae8e145b748705170931&chksm=c21babd1f56c22c7b99f7c78c5d0fda3f3788028f02be161a7c036c5cecc78f62a88ef92dca4&scene=21#wechat_redirect)  [微盘股](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485638&idx=1&sn=855a89c9abdb037020c750b5d50bc550&chksm=c21bab49f56c225f2288b263efa6ce51046f70819165febeefb85ec3970ae0130ce54e81dfed&scene=21#wechat_redirect)

[量化的一天](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485598&idx=1&sn=0beb5d40d9ccde36e688a1c273de74ca&chksm=c21bab11f56c2207dcd2fbe6a2fc593e40bc559f1d38665eec3747fea0c04ffc6932797ef8aa&scene=21#wechat_redirect)  [失败的Quant](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485604&idx=1&sn=411b3d6d6dc89743b8585739c52ccbaa&chksm=c21bab2bf56c223d1dcd11327a3b53d2e1c3b5007e5c758a7be792f2407d864608a8ce7ac15d&scene=21#wechat_redirect)  

[十年8万倍](http://mp.weixin.qq.com/s?__biz=MzkyODI5ODcyMA==&mid=2247485624&idx=1&sn=893ca25217be05fca79e7f43ae3410cd&chksm=c21bab37f56c2221c2cc186175080622c2421cc7c1704862e482a60f282900e4c1ff02708855&scene=21#wechat_redirect)

  

  

_Tip：点击关键字可以直接查看对应文章。_

END

如果对本文有疑惑，或是想聊聊

亦或是围观朋友圈当点赞之交

戳我，让我们一路同行

吃瓜吐槽写代码

![](assets/014.png)

添加好友后，私信『**666**』

送你一些量化小福利

人工回复慢请见谅~

![](assets/015.png)