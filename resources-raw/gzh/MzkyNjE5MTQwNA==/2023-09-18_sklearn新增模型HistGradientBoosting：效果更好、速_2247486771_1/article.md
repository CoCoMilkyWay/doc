# sklearn新增模型HistGradientBoosting：效果更好、速度更快、支持缺失值输入

Coggle 量化前沿速递 2023-09-18 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247486771&idx=1&sn=14d2a8135013452b664960a6ad472e83&chksm=c32371818f12174c927728e9137f5c5f85d5ed040b45422e437df4ec8873bc5f20b3b311e0a1#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247486771&idx=1&sn=14d2a8135013452b664960a6ad472e83&chksm=c32371818f12174c927728e9137f5c5f85d5ed040b45422e437df4ec8873bc5f20b3b311e0a1#rd)

## HistGradientBoosting

> https://scikit-learn.org/stable/modules/ensemble.html#histogram-based-gradient-boosting

Scikit-learn 0.21引入了两种新的梯度提升树实现，分别是`HistGradientBoostingClassifier`和`HistGradientBoostingRegressor`，灵感来自于LightGBM。

-   速度优势
    

这些基于直方图的估计器在样本数量超过数万个样本时可以比`GradientBoostingClassifier`和`GradientBoostingRegressor`快上**数个数量级**。

-   支持缺失值输入
    

它们还内置了对缺失值的支持，避免了需要使用一个填充器（imputer）的必要。

## 使用案例

大多数参数与`GradientBoostingClassifier`和`GradientBoostingRegressor`保持不变。唯一的例外是`max_iter`参数，它代替了`n_estimators`，控制了Boosting过程的迭代次数：

```
>>> from sklearn.ensemble import HistGradientBoostingClassifier>>> from sklearn.datasets import make_hastie_10_2>>> X, y = make_hastie_10_2(random_state=0)>>> X_train, X_test = X[:2000], X[2000:]>>> y_train, y_test = y[:2000], y[2000:]>>> clf = HistGradientBoostingClassifier(max_iter=100).fit(X_train, y_train)>>> clf.score(X_test, y_test)0.8965
```

对于回归问题，可用的损失函数包括"均方误差"（'squared\_error'）、"绝对误差"（'absolute\_error'，对离群值不敏感）、"泊松分布"（'poisson'，适用于模拟计数和频率）。对于分类问题，唯一可用的损失函数是"对数损失"（'log\_loss'）。

对于二元分类，它使用二元对数损失，也称为二项偏差或二元交叉熵。对于`n_classes >= 3`，它使用多类别对数损失函数，具有多项式偏差和分类交叉熵作为替代名称。选择合适的损失函数版本基于传递给fit的y。

通过`max_leaf_nodes`、`max_depth`和`min_samples_leaf`参数可以控制树的大小。

用于对数据进行分箱的箱子数量由`max_bins`参数控制。使用更少的箱子可以作为一种正则化形式。通常建议使用尽可能多的箱子，这是默认设置。

## 缺失值支持

`HistGradientBoostingClassifier`和`HistGradientBoostingRegressor`内置了对缺失值（NaNs）的支持。

在训练过程中，树生长器在每个分裂点学习样本是否具有缺失值，并根据潜在的增益确定缺失值样本是应该分到左子节点还是右子节点。在预测时，具有缺失值的样本被分配到相应的左子节点或右子节点：

```
>>> from sklearn.ensemble import HistGradientBoostingClassifier>>> import numpy as np>>> X = np.array([0, 1, 2, np.nan]).reshape(-1, 1)>>> y = [0, 0, 1, 1]>>> gbdt = HistGradientBoostingClassifier(min_samples_leaf=1).fit(X, y)>>> gbdt.predict(X)array([0, 0, 1, 1])
```

当缺失值的模式具有预测性质时，分裂可以基于特征值是否缺失来进行：

```
>>> X = np.array([0, np.nan, 1, 2, np.nan]).reshape(-1, 1)>>> y = [0, 1, 0, 0, 1]>>> gbdt = HistGradientBoostingClassifier(min_samples_leaf=1,...                                       max_depth=2,...                                       learning_rate=1,...                                       max_iter=1).fit(X, y)>>> gbdt.predict(X)array([0, 1, 0, 0, 1])
```

如果在训练过程中某个特征没有遇到缺失值，那么具有缺失值的样本将被映射到具有最多样本的子节点。

## 设置样本权重

以下的示例演示了模型如何通过设置样本权重为零来忽略具有零权重的样本：

```
>>> X = [[1, 0],...      [1, 0],...      [1, 0],...      [0, 1]]>>> y = [0, 0, 1, 0]>>> # 通过将前两个训练样本的权重设置为0来忽略它们>>> sample_weight = [0, 0, 1, 1]>>> gb = HistGradientBoostingClassifier(min_samples_leaf=1)>>> gb.fit(X, y, sample_weight=sample_weight)HistGradientBoostingClassifier(...)>>> gb.predict([[1, 0]])array([1])>>> gb.predict_proba([[1, 0]])[0, 1]0.99...
```

正如您所看到的，由于前两个样本的样本权重被忽略，\[1, 0\] 被舒适地分类为1。