# 一行代码运行DLinear模型用于股票预测,附代码

QuantGo QuantML 2024-04-03 23:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=cf0b2bebbe01f11d2d2c89f9241913c2ac136de9dc75720aee547647b4af1ca7e9e96951fcb1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=cf0b2bebbe01f11d2d2c89f9241913c2ac136de9dc75720aee547647b4af1ca7e9e96951fcb1#rd)

![](assets/001.png)

1\. 模型介绍

![](assets/001.png)

尽管Transformer模型在自然语言处理、语音识别和计算机视觉等领域取得了巨大成功，但在时间序列建模中，它们可能不是最有效的解决方案。这是因为Transformer的自注意力机制（self-attention）是排列不变的，这可能导致时间信息的丢失。

![](assets/002.png)

  

为了验证这一观点，作者引入了一组简单的一层层线性模型LTSF-Linear，并在九个真实世界数据集上进行了实验。结果显示，LTSF-Linear在所有情况下都意外地超越了现有的复杂Transformer基础的LTSF模型，有时改进幅度达到20%到50%。  

论文还进行了全面的实证研究，探讨了LTSF模型的各种设计元素对其提取时间关系能力的影响。这些发现可能为未来的LTSF任务研究开辟新的方向。

**LTSF-Linear模型：**

基本形式：LTSF-Linear通过一层层线性模型直接回归历史时间序列来进行未来预测。它不共享不同变量之间的权重，也不建模任何空间相关性。

![](assets/003.jpg)

  

变体：为了处理不同领域的时间序列（如金融、交通和能源领域），作者引入了两种预处理方法的变体，分别是DLinear和NLinear。

DLinear：结合了Autoformer和FEDformer中使用的季节性-趋势分解方案和线性层。它首先通过移动平均核将原始数据输入分解为趋势分量和剩余（季节性）分量，然后对每个分量应用一层层线性层，并将两个特征相加以获得最终预测。

NLinear：首先将输入序列减去序列的最后一个值，然后通过线性层进行处理，最后在进行最终预测前将减去的部分加回。这种减法和加法操作是对输入序列的简单归一化。

**实验结果：**

在九个广泛使用的基准数据集上的实验结果显示，LTSF-Linear在大多数情况下都优于现有的复杂Transformer模型。

与Transformer模型相比，LTSF-Linear在处理分布偏移和趋势-季节性特征方面表现出优越性。

论文还发现，与现有Transformer模型声称的相反，大多数模型未能从长序列中提取时间关系，即随着回溯窗口大小的增加，预测误差并没有减少，有时甚至增加。

![](assets/004.jpg)

  

2\. 代码部分

  

我们在QLIB中实现Dlinear模型。为了方便修改源代码，直接使用qlib源码运行，不必采用pip install 安装。

```
git clone https://github.com/microsoft/qlib.git
```

在文件夹中，如果直接运行模型会报错：  

ModuleNotFoundError: No module named 'qlib.data.\_libs.rolling'

是由于qlib中有部分c代码，需要编译后再使用，在qlib根目录下运行以下命令进行编译

```
python  setup.py build_ext --inplace
```

然后将我们的代码拷贝进examples/benchmarks

![](assets/005.jpg)

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

Dlinear模型部分代码在DLinear.py中

```
class DLinearModel(nn.Module):
```

运行结果：

![](assets/006.png)

  

QLIB是一个非常强大的AI量化投资框架，基于QLIB底层结构，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。后续会逐步在公众号更新。  

  

由于本公众号刚开始运行，需要流量支持，如您希望获取源代码，还请将本文转发至三个百人以上量化群至少五分钟，后台截图留言获取代码。

您也可以加入星球，相关模型代码会同步公布在星球。

感谢支持。

  

![](assets/007.jpg)