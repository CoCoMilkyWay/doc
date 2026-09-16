# 使用LSTM构建RNN进行股票预测

FinTechHi FinTechHi 2025-03-11 22:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485861&idx=1&sn=fc4ddb98b08078eca60f633be2ebb4a1&chksm=fb849dd1622d5064a055880c0fadd05da185c304c7ee02edeac6f2a5397a23db494aec358ba4#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485861&idx=1&sn=fc4ddb98b08078eca60f633be2ebb4a1&chksm=fb849dd1622d5064a055880c0fadd05da185c304c7ee02edeac6f2a5397a23db494aec358ba4#rd)

完全是一篇入门文章，大神飘过。

构建具有长短期记忆 (LSTM) 层的循环神经网络 (RNN) ，且使用 Nvidia历史行情数据做股票价格走势预测。

# 步骤 1：准备数据集

从 Nvidia 股票价格数据集 (NVDA.csv) 开始，其中包括股票价格和其他相关数据。该数据集根据日期 2019-01-01 分为训练集和测试集。第一部分数据用于训练，而此日期之后的数据用于测试。

```
# Load the dataset
```

步骤2：构建LSTM模型

使用TensorFlow的Keras API中的 `Sequential` 类构建LSTM模型。

该模型由四个LSTM层组成，分别为50、60、80和120个单元，每个层后面都有一个dropout层，以防止过拟合。

最后一层是一个密集层，输出预测的股票价格。

```
from tensorflow.keras.models import Sequential
```

步骤3：训练模型

使用训练数据训练LSTM模型。该模型训练了10个epoch，批大小为32。

```
# Fit the model
```

步骤4：准备测试数据

在进行预测之前，需要像准备训练数据一样准备测试数据。这包括缩放数据和创建60个时间步长的序列。

```
# 准备测试数据
```

```
# 导入标准化工具
```

第五步：预测

有了训练好的模型和准备好的测试数据，就可以进行预测了。将预测缩小到原来的规模，与实际的股票价格进行比较。

```
# Make predictions
```

第六步：可视化结果

最后，我们将预测的股票价格与实际股票价格进行可视化，以评估模型的性能。

```
import matplotlib.pyplot as plt
```

下图显示了预测的Nvidia股价（灰线）与实际股价（黑线）的对比，证明了模型的准确性。

![](assets/001.png)

构建具有LSTM层的RNN用于股票预测涉及几个步骤，从准备数据和构建模型到训练和预测。LSTM网络对于这种类型的时间序列预测特别有效，因为它们能够捕获数据中的长期依赖关系。通过遵循上面概述的步骤，您可以构建和评估自己的股票价格预测模型。