# 【python量化】多种Transformer模型用于股价预测（Autoformer, FEDformer和PatchTST等）

敲代码的quant 量化前沿速递 2024-02-01 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487468&idx=1&sn=4039e623195aa9d741a1142048cc6d4d&chksm=c3cb4cdbf94982ea5e95a8c08b37b7d81b8fb74e718e99cdb2275a5cbfb94d7a140c619c7706#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487468&idx=1&sn=4039e623195aa9d741a1142048cc6d4d&chksm=c3cb4cdbf94982ea5e95a8c08b37b7d81b8fb74e718e99cdb2275a5cbfb94d7a140c619c7706#rd)

  

写在前面

在本文中，我们利用Nixtla的NeuralForecast框架，**实现多种基于Transformer的时序预测模型，包括：Transformer, Informer, Autoformer, FEDformer和PatchTST模型，并且实现将它们应用于股票价格预测的简单例子**。

1

NeuralForecast

  

neuralforecast 是一个旨在为时间序列预测提供一个丰富的、高度可用和鲁棒的神经网络模型集合的工具库。这个库集成了从传统的多层感知器（MLP）和递归神经网络（RNN）到最新的模型如N-BEATS、N-HiTS、TFT，以及其他高级架构，以适应多样化的预测需求。它的关键功能包括对**静态、历史和未来的外生变量**的支持，提高了模型在实际应用中的灵活性。库中的模型提供了良好的预测可解释性，允许用户绘制趋势、季节性以及外生预测组件。neuralforecast 还实现了概率预测，通过简单的适配器支持量化损失和参数分布，增加了预测结果的置信度。此外，它提供了自动模型选择功能，通过并行自动超参数调整来高效确定最优的模型配置。库的简洁接口设计与SKLearn兼容，确保了易用性，并且训练和评估损失的计算能够适应不同的比例，这为不同规模的数据集提供了灵活性。最后，neuralforecast 包含了一个广泛的模型集合，**包括但不限于LSTM、RNN、TCN、N-BEATS、N-HiTS、ESRNN以及各种基于Transformer的预测模型等**，都是以即插即用的方式实现，方便用户直接应用于各种时间序列预测场景。这些特性使得neuralforecast 成为那些寻求高效、精确且可解释时间序列预测模型的研究人员和实践者的有力工具。**本文将利用neuralforecast 实现各种Transformer模型，并展示将它们应用于股票价格预测的简单例子。**

2

环境配置

  

本地环境：

```
Python 3.8
```

库版本：

```
Pandas version: 2.0.3
```

为了使用最新的其他模型，也可以直接fork neuralforecast的源码：

```
git clone https://github.com/Nixtla/neuralforecast.git
```

  

3

代码实现

###   

### **步骤 1: 导入所需的库**

-   **导入库**：首先，导入处理数据所需的 `pandas` 库，绘图所需的 `matplotlib.pyplot` 库，以及 `neuralforecast` 中的多个模块。这些模块包括各种预测模型和评估指标函数。
    

```
import pandas as pd
```

###   

### **步骤 2: 数据准备**

-   **读取数据**：使用 `pandas`从 CSV 文件加载数据。这个数据集包含股票的每日收盘价。
    
-   **数据预处理**：重命名列以符合模型的输入要求（例如，将日期列重命名为 'ds'，将收盘价列重命名为 'y'）。此外，将日期列转换为日期时间格式，并为数据集添加一个唯一标识符，这对于使用neuralforecast进行时间序列预测是必要的。
    

```
df = pd.read_csv('./000001_Daily_Close.csv')
```

  

### **步骤 3: 定义预测模型**

-   **初始化模型**：定义一个模型列表，每个模型都是 `neuralforecast` 库中的一个类的实例。对于每个模型，指定预测范围（horizon）、输入窗口大小（input\_size）以及其他训练参数（如 max\_steps, val\_check\_steps）。
    
-   **模型配置**：这些参数决定了模型的训练方式，包括训练持续时间、评估频率和早停机制等。每个模型都有一些公共的参数以及它们自身的参数可以调整，这里均使用它们默认的参数进行模型初始化。
    

```
models = [VanillaTransformer(h=horizon,
```

  

### **步骤 4: 模型训练与交叉验证**

-   **创建 NeuralForecast 实例**：使用 `NeuralForecast` 类整合所有的模型。这个类提供了一个统一的接口来训练和评估多个模型。
    
-   **执行交叉验证**：使用 `cross_validation` 方法对每个模型进行训练和评估。这个方法自动进行时间序列的交叉验证，分割数据集并评估模型在不同时间窗口上的性能。
    

```
nf = NeuralForecast(
```

  

### **步骤 5: 数据筛选**

-   **筛选数据点**：通过选择特定的“cutoff”点来过滤 `Y_hat_df` 中的预测。这种筛选基于预测范围 `horizon`，确保评估是在均匀间隔的时间点上进行。
    

```
Y_plot = Y_hat_df
```

  

### **步骤 6: 绘图与性能评估**

-   **绘制预测结果**：使用 `matplotlib` 绘制真实数据与每个模型的预测结果。这有助于直观地比较不同模型的预测准确性。
    
-   **计算评估指标**：对每个模型，计算和打印均方根误差（RMSE）、平均绝对误差（MAE）和均方误差（MSE）等性能指标。这些指标提供了量化模型性能的方式。
    

```
plt.figure(figsize=(20, 5))
```

  

### **步骤 7: 结果展示**

-   **展示图表**：最后，显示绘制的图表。图表展示了不同模型在整个时间序列上的预测表现，允许直观地评估和比较模型。
    

![](assets/001.png)

```
VanillaTransformer: rmse 56.5187 mae 38.8573 mse 3194.3650
```

在对比基于 Transformer 的各种模型在股票价格预测任务上的表现时，从可视化以及评估结果中，我们发现 FEDformer 和 PatchTST 在所有评估指标（RMSE、MAE、MSE）上表现最为出色，这可能归因于它们在处理长期依赖关系和捕获时间序列数据中的复杂模式方面的优势。相较之下，虽然 Informer 显示了合理的性能，但其表现略逊于 FEDformer 和 PatchTST。VanillaTransformer 和 Autoformer 的性能相对较差。这些结果强调了根据特定任务的需求选择合适的模型架构的重要性，同时也表明了在实际应用中进行模型选择时需要考虑到模型的特定优势和潜在的局限性。

4

总结  

本文展示了如何使用 neuralforecast 实现多种 Transformer 模型（包括 Informer, Autoformer, FEDformer 和 PatchTST），并将它们应用于股票价格预测的简单示例。通过这个演示，我们可以看到 Transformer 模型在处理时间序列数据方面的潜力和灵活性。虽然我们的实验是初步的，但它为进一步的研究和应用提供了一个基础。读者可以在此基础上进行更深入的模型调优、特征工程和超参数实验，以提升预测性能。此外，这些模型的应用不限于股票价格预测，还可以扩展到其他领域的时间序列分析。

**本文内容仅仅是技术探讨和学习，并不构成任何投资建议。**