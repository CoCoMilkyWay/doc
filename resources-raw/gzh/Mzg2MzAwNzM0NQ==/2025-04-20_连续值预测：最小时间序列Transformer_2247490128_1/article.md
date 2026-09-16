# 连续值预测：最小时间序列Transformer

QuantML QuantML 2025-04-20 19:49 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490128&idx=1&sn=aa5df5ea7f3568a8a1a52a2ef9271141&chksm=cf00991b186df68c699f6edddd7b5cd29cdf5690a40b8710a2edd554cd2b775b08021c090b18#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490128&idx=1&sn=aa5df5ea7f3568a8a1a52a2ef9271141&chksm=cf00991b186df68c699f6edddd7b5cd29cdf5690a40b8710a2edd554cd2b775b08021c090b18#rd)

  

![](assets/001.png)

## 1\. 引言

Transformer架构最初由Vaswani等人提出，用于机器翻译任务。该模型采用监督学习方式，训练数据包括输入序列X和输出序列Y，这些序列代表两种语言的对应句子。在推理过程中，模型以生成方式执行，逐步生成输出序列。Transformer模型通过自回归方式有效地结合了过去输入和输出样本的信息，使得每个样本都能感知到所有输入和输出。在序列到序列（Seq2Seq）建模中，Transformer处理后的样本在预测下一个输出时表现出色。

时间序列预测是一个典型的序列到序列问题，广泛应用于统计学、信号处理、计量经济学、控制工程以及任何涉及时间测量的应用科学和工程领域。时间序列预测使用时间序列模型，根据先前观察到的值来预测未来值。将Transformer应用于时间序列预测是一个自然的选择，因为Transformer在处理序列数据方面表现出色。

近年来，已经提出了多种针对时间序列预测的Transformer变体，如LogSparse Transformer、MTS Transformer、Informer和ContiFormer。这些工作解决了时间序列预测中的各种挑战，如采样率变化和长期依赖性。然而，这些变体通常对原始Transformer架构进行了复杂的修改，且缺乏与时间序列Transformer基线的比较。此外，Zeng等人的实验表明，一个“简单得令人尴尬”的单层线性回归器在多个基准测试中优于最先进的时间序列Transformer。因此，有必要定义一个简单的时间序列Transformer基线，即最小时间序列Transformer。

本文旨在研究如何对原始Transformer架构进行最小程度的修改，以使其适用于连续值时间序列数据。为了保持简单和易于理解，所有实验都在正弦序列上进行。所有时间序列Transformer模型和实验的代码都已公开。

## 2\. 方法

### 2.1 原始Transformer - Seq2SeqTransformer

本文的参考实现是经过实验验证的Seq2SeqTransformer类。该类使用流行的PyTorch torch.nn.Transformer类作为主要构建块。Seq2SeqTransformer的forward()函数易于理解，主要处理步骤包括：

1.  **源序列和目标序列的嵌入**：使用PyTorch的torch.nn.Embedding类将token ID（整数值）映射到one-hot编码向量，并进一步映射到嵌入向量。
    
2.  **位置编码**：使用遵循原始工作的编码类实现位置编码。
    
3.  **线性“去嵌入”层**：将Transformer的输出转换为类别概率。注意，PyTorch的交叉熵损失实现已经包含了softmax非线性，因此forward函数中未显式包含。
    

PyTorch的Transformer类负责屏蔽未来输出和填充键，掩码的构建在参考代码中可用。一个常见且经常令人困惑的要求是，源和目标变量必须是三维的：序列长度×批次数量×特征向量维度。在类内部，有一些繁琐的步骤来维护正确的形状，这些步骤通常是编程错误的根源。

### 2.2 最小时间序列Transformer - MiTS-Transformer

对离散token Seq2SeqTransformer的最小适应是将“整数到向量”的嵌入层（torch.nn.Embedding）更改为将连续值向量转换为模型维度向量的层，即“向量到向量”。实现这一点的神经网络技巧是用线性层替换嵌入层。这可以通过对原始代码进行小改动来完成。原始嵌入层被以下代码替换：

`self.embedding = nn.Linear(d_input, d_model)   self.unembedding = nn.Linear(d_model, d_input)   `

在连续情况下，嵌入层将d\_input维度的样本映射到d\_model维度的模型向量。在去嵌入步骤中，转换是反向进行的。

### 2.3 位置编码扩展 - PoTS-Transformer

在时间序列预测中，Transformer面临三个潜在挑战：序列可能很长，从数千到数万个样本；时间上接近的样本可能高度相关；训练数据的数量可能有限。这些挑战的直观解决方案是相互矛盾的。长序列需要高维模型，以便有“空间”容纳位置信息。少量数据使得训练大型模型变得困难，因为容易过拟合并减少泛化能力。相邻样本之间的强相关性使得可以使用小型模型，因为每个新样本只提供微不足道的新信息。为了满足这些相互矛盾的要求，需要特殊的技巧。

在现有文献中，特别是长序列受到了关注。例如，Li等人提出对序列进行对数稀疏采样，以便位置编码变为对数，从而减少对高维模型的需求。Wav2vec 2.0是一种用于音频特征提取的最先进的音频骨干网络。它通过首先应用卷积滤波器，然后使用最近邻乘积量化器，将长音频序列压缩为更紧凑的表示，即“音频token”。

最简单的解决方案是什么？在PoTS-Transformer中，模型尺寸保持较低以避免过拟合并减少计算量。同时，位置编码在更高维空间中完成，以保持其对长序列的有效性。这是通过在两个线性层之间包装位置编码器来实现的，这两个线性层首先执行位置编码扩展，然后在编码步骤之后执行逆位置扩展：

`src = self.pos_expansion(src)   src = self.positional_encoder(src)   src = self.pos_invexpansion(src)   ...   tgt = self.pos_expansion(tgt)   tgt = self.positional_encoder(tgt)   tgt = self.pos_invexpansion(tgt)   `

扩展及其逆定义为：

`# 初始化   self.pos_expansion = nn.Linear(d_model, pos_expansion_dim)   self.pos_invexpansion = nn.Linear(pos_expansion_dim, d_model)   # 位置编码   self.positional_encoder = PositionalEncoding(d_mode <= pos_expansion_dim, dropout_p)   `

使用8维向量执行Transformer模型计算，并使用128维向量执行位置编码，PoTS-Transformer中的可学习参数数量从1,433增加到3,473（增加2.4倍）。相比之下，将MiTS-Transformer的模型尺寸从8维增加到128维空间，可学习参数数量从1,289增加到204,689（增加158倍）。差异接近两个数量级。

### 2.4 训练细节

所有Transformer模型均使用标准的PyTorch Adam优化器（torch.optim.Adam）进行训练，初始学习率为0.023。使用多步调度器来衰减每个参数组的学习率，当epoch数达到某个里程碑时，gamma固定为0.1，里程碑针对每个案例单独手动优化，并记录目标损失以便于所有实验的复制。然而，使用固定的学习率0.023，不进行调度，训练2000个epoch，也可以获得类似的结果。在没有GPU的标准笔记本电脑上，我们实验中最大的模型的训练仅需几分钟。

## 3\. 数据

实验的Seq2Seq数据是通过对正弦函数进行采样生成的：

其中，是信号频率，定义时间点。对于离散信号，将频率定义为每样本的波形数：

其中，是波形数，是样本数。例如，意味着每31个样本有2个波形。图1显示了具有不同频率的正弦波。图1(d)显示了随着频率增加而变得更加显著的采样误差（注意每个波形的顶部看起来不同）。

![](assets/002.jpg)

图1：实验中使用的示例正弦波。

数据类型。生成的数据分为三种类型：

1.  类型1：单个序列（正弦波，）
    
2.  类型2：固定数量的序列（例如，）
    
3.  类型3：任意数量的序列（）
    

是均匀随机分布。类型1用于对模型进行健全性检查。类型2是一个简单的案例，其中只有少量不同的序列。类型3是最难的案例，因为两个几乎相同频率的正弦波之间的差异可能很微妙。在实验中，信号长度设置为31，分为19个输入（源）样本和12个输出（目标）样本（图2）。

## 4\. 实验

### 4.1 使用单个固定序列（类型1序列）进行代码健全性检查

健全性检查是使用长度为和频率的单个正弦波进行的。训练集和测试集中的信号重复100次，以模拟标准训练。

MiTS-Transformer。该模型在固定学习率为0.023的情况下，经过200个epoch后收敛，最终MSE误差为0.23。图3显示了示例。

![](assets/003.jpg)

图2：31个样本的正弦波（类型2序列）分为源X（蓝色样本0-18）和目标部分（绿色样本19-30）。

![](assets/004.jpg)

图3：MiTS-Transformer实现的单个序列健全性检查（参见Jupyter笔记本）。

### 4.2 多个序列（类型2）

MiTS-Transformer。图4中的结果和插图展示了良好的学习性能。单序列和多序列（4个序列）的准确性几乎没有差异。

![](assets/005.jpg)

图4：MiTS-Transformer的四个序列（类型2）结果（模型参数：d\_model ，dim\_feedforward ，总共1,289个可学习参数）。信号频率分别为0/31、1/31、2/31和。

### 4.3 任意序列（类型3）

MiTS-Transformer。图5中的结果和来自三个不同运行的样本插图显示了相同训练和测试数据的结果。结果验证了最小时间序列Transformer适用于序列中任意微小变化的数据。结果验证了模型的某些插值能力，因为许多测试序列不出现在训练数据中。对于任意序列的结果几乎比固定类型1和2序列的结果差一个数量级。

![](assets/006.jpg)

图5：MiTS-Transformer的任意序列（类型3）结果（d\_model ，dim\_feedforward ，1289个参数）。数据由频率在(0/31, 3/31)内的任意正弦波序列组成。

通过增加模型维度（d\_model），可以提高MiTS-Transformer的学习能力。图6和图7显示了模型维度设置为16和32的结果。尺寸16的模型系统地优于尺寸8的模型，但尺寸32的模型开始偶尔对训练数据过拟合并降低泛化能力。8、16和32模型中的可学习参数总数分别为1289、4097和14321。

![](assets/007.jpg)

图6：MiTS-Transformer的任意序列（类型3）结果（d\_model ，dim\_feedforward ，4097个参数）。

![](assets/008.jpg)

图7：MiTS-Transformer的任意序列（类型3）结果（d\_model ，dim\_feedforward = ，14321个参数）。

PoTS-Transformer。使用位置扩展维度64和2,385个可学习参数进行实验。图8中的结果显示了系统地优于MiTS-Transformer的性能。

![](assets/009.jpg)

图8：PoTS-Transformer的任意序列（类型3）结果（d\_model ，dim\_feedforward ，pos\_expansion\_dim ，2,385个参数）。

## 5\. 结论

本文旨在研究如何将“Attention is All You Need”（原始）Transformer架构适配到时间序列（连续）数据中。最小程度的适配是将token嵌入层更改为线性层。这在本文的最小时间序列Transformer（MiTS-Transformer）中实现，该模型能够很好地学习正弦波。通过改变模型维度，可以调整MiTS-Transformer的学习能力。然而，这很快导致模型尺寸在可学习模型参数方面的爆炸式增长，并且模型容易过拟合并降低泛化能力。为了解决这个问题，本文提出了一种简单的模型，称为位置编码扩展时间序列Transformer（PoTS-Transformer）。它结合了在扩展空间中长序列的位置编码和避免过拟合并减少计算量的低维模型。我们实验中的结果令人信服，为基于Transformer的时间序列预测提供了类似的最小和简单技巧。

  

  

  

代码见星球，加入QuantML星球，与星主与800+专业人士一起交流学习：

![](assets/010.jpg)