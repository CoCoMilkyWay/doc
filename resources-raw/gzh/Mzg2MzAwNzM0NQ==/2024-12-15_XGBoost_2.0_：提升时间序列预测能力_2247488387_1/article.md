# XGBoost 2.0 ：提升时间序列预测能力

QuantML QuantML 2024-12-15 21:44 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&chksm=cf0e29ebb7b91d63518b822efe0fd4913c5c060c0d42c75137e4553ce3160301d898135c611e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&chksm=cf0e29ebb7b91d63518b822efe0fd4913c5c060c0d42c75137e4553ce3160301d898135c611e#rd)

在机器学习不断发展的领域，XGBoost 已经确立了自己作为各种预测任务的强大算法的地位。现在，随着 XGBoost 2.0 的发布，一个针对时间序列预测的新时代已经到来。这个最新版本带来了许多增强功能，专门针对时间依赖数据的复杂性进行了优化。

### XGBoost 简介及其 2.0 版本的新功能

想象一下，你正在尝试解决一个复杂的拼图。每个拼图块都代表解决方案的一小部分。XGBoost 就像有一组专家，每个专家都擅长某种特定类型的拼图块。他们共同努力解决拼图问题。该算法的核心是改进或增强模型的性能。它从一个简单的模型开始，比如决策树，然后逐渐使其变得更好。

XGBoost 非常关注其错误。它会查看拼图中错误的部分，并首先专注于解决这些问题。它不是依靠单一的专家来解决整个拼图，而是利用许多专家（决策树）。每个专家都给出自己对如何解决拼图的意见，他们共同投票做出最终决定。

然后，XGBoost 会经历大量的练习拼图（训练数据）来训练其专家。它从错误中学习，并随着时间的推移变得更好。它还会不断检查自己的表现并进行相应调整。这就像每个专家都在不断学习和完善自己的技能。

最终解决方案是所有专家意见的组合。这种组合通常会比单一专家单独完成的结果要好得多。

在 2.0 版本中，开发团队专注于增强 XGBoost 的多目标回归和分类任务的功能，引入了向量叶树模型。这种新特性允许 XGBoost 为所有目标构建一个单一的树，而不是像以前那样为每个目标构建单独的模型。

与传统的多树方法相比，这种方法具有以下优点和权衡：

-   **减轻过拟合**：通过构建一个更通用的模型来减少过拟合的风险。
    
-   **生成更紧凑的模型**：减少模型大小和复杂性。
    
-   **考虑目标之间的相关性**：通过构建一个同时考虑多个目标的树，可以更好地捕捉目标之间的相互关系。
    

此外，用户可以使用回调机制在训练过程中同时包含向量叶树和标量叶树。

以下是 XGBoost 2.0 中的一些改进：

-   **设备参数简化**：现在，用户只需要指定用于执行的设备及其序号位置即可。
    
-   **默认树方法更改为 hist**：在即将发布的版本中，默认的树方法将更改为 hist。之前，XGBoost 会根据输入数据和训练环境自动选择 approx 或 exact。这种默认设置的变化旨在提高 XGBoost 模型训练的效率和一致性。
    
-   **初步支持在 GPU 上使用 approx 树方法**：虽然这种方法在 GPU 上的性能尚未完全优化，但它功能完备，除了 JVM 包之外的所有功能都可用。
    
-   **新增 max\_cached\_hist\_node 参数**：XGBoost 引入了一个新的参数 max\_cached\_hist\_node，允许用户设置 CPU 缓存中为直方图分配的内存大小。此功能旨在防止 XGBoost 过度积极地缓存直方图。如果禁用缓存，可能会导致性能下降。
    
-   **新增针对排序任务的新功能**：最新版本的 XGBoost 增加了一系列针对排序任务的新功能。
    
-   **自主确定 base\_score 参数**：在早期版本中，base\_score 是一个固定的参数值，可以作为训练参数指定。在更新版本中，XGBoost 可以通过分析输入标签来自主确定这个参数，以提高准确性。
    
-   **支持分位数回归**：XGBoost 算法已经增强，可以支持分位数回归，这需要最小化分位数损失函数。此外，XGBoost 支持同时使用多个目标分位数进行训练，每个分位数使用一棵树。
    

### 重要提示

如果你已经安装了 xgboost 1.7，可以使用以下命令卸载它：

```
pip uninstall xgboost
```

然后使用以下命令安装最新版本：

```
pip install xgboost
```

### 使用 XGBoost 2.0 进行时间序列预测

与旧版本类似，我们可以使用 XGBoost 高效地预测时间序列。以下是本实验将遵循的步骤：

1.  **下载并导入 COT JPY 数据**：
    

-   COT 报告，或交易者持仓报告，是由美国商品期货交易委员会（CFTC）每周发布的报告，提供有关各种市场参与者（包括商业对冲者、大型投机者和小型交易者）在期货和期权市场中的持仓信息。
    
-   该报告提供了有关这些群体的情绪和持仓情况的宝贵见解，帮助交易者和投资者判断潜在的市场趋势和逆转。
    

3.  **对数据进行差分处理，以使其平稳**：
    

-   为什么使数据平稳？在进行预测之前，使数据平稳很重要，因为许多时间序列预测技术都假设潜在的数据生成过程是平稳的。平稳性是指时间序列的统计属性随时间保持不变。
    

5.  **将数据拆分为训练集和测试集**（同时使用滞后值作为特征或预测变量）。
    
6.  **使用 XGBoost 算法进行拟合和预测**。
    
7.  **评估模型**。
    

以下是执行该研究的代码：

```
from xgboost import XGBRegressorimport numpy as npimport matplotlib.pyplot as pltimport pandas as pd# 读取数据data = np.reshape(pd.read_excel('COT_JPY.xlsx').values, (-1))data = np.diff(data)# 数据预处理函数def data_preprocessing(data, num_lags, train_test_split):    # 准备训练数据    x = []    y = []    for i in range(len(data) - num_lags):        x.append(data[i:i + num_lags])        y.append(data[i + num_lags])    # 将数据转换为 numpy 数组    x = np.array(x)    y = np.array(y)    # 将数据拆分为训练集和测试集    split_index = int(train_test_split * len(x))    x_train = x[:split_index]    y_train = y[:split_index]    x_test = x[split_index:]    y_test = y[split_index:]    return x_train, y_train, x_test, y_test# 预处理数据x_train, y_train, x_test, y_test = data_preprocessing(data, 80, 0.80)# 创建模型model = XGBRegressor(random_state = 0, n_estimators = 64, max_depth = 64)# 拟合模型model.fit(x_train, y_train) y_pred_xgb = model.predict(x_test)# 绘图plt.plot(y_pred_xgb[-100:], label='预测数据 | XGBoost', linestyle='--', marker='o', color='orange')plt.plot(y_test[-100:], label='真实数据', marker='.', alpha=0.7, color='blue')plt.legend()plt.grid()plt.axhline(y=0, color='black', linestyle='--')# 计算方向预测准确率same_sign_count = np.sum(np.sign(y_pred_xgb) == np.sign(y_test)) / len(y_test) * 100print('XGBoost 方向预测准确率 = ', same_sign_count, '%')
```

**重要提示**

为什么在预测之前需要使数据平稳？

在预测之前使数据平稳很重要，因为许多时间序列预测技术都假设潜在的数据生成过程是平稳的。平稳性是指时间序列的统计属性随时间保持不变。

模型的预测结果如下：

XGBoost 方向预测准确率 =  60.81 %

该模型似乎能够正确预测 COT JPY 时间序列变化方向约 61% 的时间。这是一个良好的开端，但仍有改进空间。

### 结论

XGBoost 2.0 在多个方面进行了重大改进，使其在时间序列预测和其他机器学习任务中更加强大和高效。

-   **向量叶树模型**和**分位数回归**等新特性为用户提供了更强大的工具来处理复杂的数据和任务。
    
-   **默认树方法更改为 hist** 和 **GPU 支持** 提高了模型的训练速度和效率。
    
-   **max\_cached\_hist\_node 参数** 和 **自主确定 base\_score 参数** 提供了更大的灵活性，使用户能够更精细地控制模型训练过程。
    

总的来说，XGBoost 2.0 延续了其一贯的高性能和高可扩展性，并在功能和性能上都有了显著的提升。对于数据科学家和机器学习从业者来说，XGBoost 2.0 是一个非常有价值的工具，可以帮助他们构建更准确、更高效的预测模型。

  

新建一个量化从业交流群，进群请在微信私信名片加入

![](assets/001.png)