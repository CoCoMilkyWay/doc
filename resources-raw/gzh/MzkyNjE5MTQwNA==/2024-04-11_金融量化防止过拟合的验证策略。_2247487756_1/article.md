# 金融量化防止过拟合的验证策略。

KONRADBANACHEWIC 量化前沿速递 2024-04-11 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487756&idx=1&sn=0fc69806a88c2f22db81541e06e3c84f&chksm=c345db5d3659491511eb2978fb7d627c77512a443f0ca3ffb9d6e2708159cb41fbd077fa1dc4#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487756&idx=1&sn=0fc69806a88c2f22db81541e06e3c84f&chksm=c345db5d3659491511eb2978fb7d627c77512a443f0ca3ffb9d6e2708159cb41fbd077fa1dc4#rd)

  

Purged Group Time Series

简介

![](assets/001.png)

在金融时间序列建模中，最难的问题之一就是过拟合，一旦线下过拟合了最终上线带来的损失会非常巨大，而且难以排查，所以在线下回测的时候我们就需要尽可能避免过拟合的问题，本文我们介绍金融问题中最为常用的线下验证策略 Purged Group Time Series，该验证策略目前仍然是金融建模中用的较多的验证策略之一。  

Purged Group Time Series

![](assets/001.png)

### 1\. 描述

金融时间序列中的标签一般是交易时间和事件时间进行构建的，其中：

-   事件时间=资产的市值在未来达到一定水平时，如止损或获利的价格的时间。
    
-   金融时间序列中的标签是有路径性质的，所以在计算标签时，我们不能看到样本外的重叠。
    

### 2\. 案例

假设我们试图建立一个ML模型，根据各种数据源预测IBM的价格在未来5个工作日内是上涨还是下跌至少50个基点。这些变动的规模是根据IBM股票最近实际的波动水平估计的。一个常见的标签方案是：

-   如果股价波动超过50个基点，则为+1；
    
-   如果股价绝对值波动低于50个基点则为0；
    
-   如果股价下跌超过50个百分点，则为-1。
    

我们假设我们的典型交易期限是1周。你会在今天进入一个头寸，一周后进行清算。然而，在实践中，大多数人都会有一个止损或获利水平，这样，如果达到这两个水平中的任何一个，他们都可以提前退出交易。关键是，要想让你的交易按市值计价，你需要观察未来5天或未来5个周期的价格走势（你可以提前退出）。

![](assets/002.png)

那么在构建标签过程中，我们必须**删除测试折叠中事件时间与交易时间重叠的数据**。这个过程称为Purging。

我们在每个训练和验证划分之间添加了一个gap：group方面保持了一整天的时间，但匿名特征中有某种滞后或窗口计算（尽管有我们KFold部分的结果）。

-   通过引入gap，我们降低了将信息从训练集泄漏到验证集合中的风险；
    
-   我们可以训练集的大小和验证拆分的天数。
    
-   训练、gap和验证集的大小与每天不同数量的样本有关。
    

代码

![](assets/001.png)

-   代码摘自：https://www.kaggle.com/code/konradb/ts-10-validation-methods-for-time-series
    

```
class PurgedGroupTimeSeriesSplit(_BaseKFold):    """Time Series cross-validator variant with non-overlapping groups.    Allows for a gap in groups to avoid potentially leaking info from    train into test if the model has windowed or lag features.    Provides train/test indices to split time series data samples    that are observed at fixed time intervals according to a    third-party provided group.    In each split, test indices must be higher than before, and thus shuffling    in cross validator is inappropriate.    This cross-validation object is a variation of :class:`KFold`.    In the kth split, it returns first k folds as train set and the    (k+1)th fold as test set.    The same group will not appear in two different folds (the number of    distinct groups has to be at least equal to the number of folds).    Note that unlike standard cross-validation methods, successive    training sets are supersets of those that come before them.    Read more in the :ref:`User Guide <cross_validation>`.    Parameters    ----------    n_splits : int, default=5        Number of splits. Must be at least 2.    max_train_group_size : int, default=Inf        Maximum group size for a single training set.    group_gap : int, default=None        Gap between train and test    max_test_group_size : int, default=Inf        We discard this number of groups from the end of each train split    """    @_deprecate_positional_args    def __init__(self,                 n_splits=5,                 *,                 max_train_group_size=np.inf,                 max_test_group_size=np.inf,                 group_gap=None,                 verbose=False                 ):        super().__init__(n_splits, shuffle=False, random_state=None)        self.max_train_group_size = max_train_group_size        self.group_gap = group_gap        self.max_test_group_size = max_test_group_size        self.verbose = verbose    def split(self, X, y=None, groups=None):        """Generate indices to split data into training and test set.        Parameters        ----------        X : array-like of shape (n_samples, n_features)            Training data, where n_samples is the number of samples            and n_features is the number of features.        y : array-like of shape (n_samples,)            Always ignored, exists for compatibility.        groups : array-like of shape (n_samples,)            Group labels for the samples used while splitting the dataset into            train/test set.        Yields        ------        train : ndarray            The training set indices for that split.        test : ndarray            The testing set indices for that split.        """        if groups is None:            raise ValueError(                "The 'groups' parameter should not be None")        X, y, groups = indexable(X, y, groups)        n_samples = _num_samples(X)        n_splits = self.n_splits        group_gap = self.group_gap        max_test_group_size = self.max_test_group_size        max_train_group_size = self.max_train_group_size        n_folds = n_splits + 1        group_dict = {}        u, ind = np.unique(groups, return_index=True)        unique_groups = u[np.argsort(ind)]        n_samples = _num_samples(X)        n_groups = _num_samples(unique_groups)        for idx in np.arange(n_samples):            if (groups[idx] in group_dict):                group_dict[groups[idx]].append(idx)            else:                group_dict[groups[idx]] = [idx]        if n_folds > n_groups:            raise ValueError(                ("Cannot have number of folds={0} greater than"                 " the number of groups={1}").format(n_folds,                                                     n_groups))        group_test_size = min(n_groups // n_folds, max_test_group_size)        group_test_starts = range(n_groups - n_splits * group_test_size,                                  n_groups, group_test_size)        for group_test_start in group_test_starts:            train_array = []            test_array = []            group_st = max(0, group_test_start - group_gap - max_train_group_size)            for train_group_idx in unique_groups[group_st:(group_test_start - group_gap)]:                train_array_tmp = group_dict[train_group_idx]                                train_array = np.sort(np.unique(                                      np.concatenate((train_array,                                                      train_array_tmp)),                                      axis=None), axis=None)            train_end = train_array.size             for test_group_idx in unique_groups[group_test_start:                                                group_test_start +                                                group_test_size]:                test_array_tmp = group_dict[test_group_idx]                test_array = np.sort(np.unique(                                              np.concatenate((test_array,                                                              test_array_tmp)),                                     axis=None), axis=None)            test_array  = test_array[group_gap:]                                    if self.verbose > 0:                    pass                                yield [int(i) for i in train_array], [int(i) for i in test_array]
```

参考文献

![](assets/001.png)

1.  https://www.kaggle.com/code/konradb/ts-10-validation-methods-for-time-series