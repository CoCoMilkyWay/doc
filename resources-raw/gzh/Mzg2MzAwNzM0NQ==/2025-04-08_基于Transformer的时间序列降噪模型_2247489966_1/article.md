# 基于Transformer的时间序列降噪模型

QuantML QuantML 2025-04-08 18:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489966&idx=1&sn=de65c1c695f3e2e1a2248a2dc385f568&chksm=cf60619eceae6f69985228576783de928a76067318ecacc6b4db222fd1115c2af07defc06027#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489966&idx=1&sn=de65c1c695f3e2e1a2248a2dc385f568&chksm=cf60619eceae6f69985228576783de928a76067318ecacc6b4db222fd1115c2af07defc06027#rd)

# 时间序列噪声

时间序列噪声是指序列数据中不需要的波动，这些波动会掩盖潜在的模式和趋势。噪声可能来源于多种因素，包括传感器不准确、环境干扰、随机市场波动或计算错误。  

降噪技术在金融时间序列分析中能够提升数据质量、优化预测模型的关键环节。通过去除噪声干扰，能够更清晰地捕捉市场趋势、波动特征及潜在规律，为投资决策、风险管理和量化交易提供可靠依据。

## 模型概述

去噪Transformer模型包括一个密集输入嵌入层、一个位置编码器、一个Transformer编码器（包含一个全局自注意力层和一个前馈网络），以及一个将Transformer编码器输出映射回原始信号空间的最终密集层，以输出去噪信号。

输入嵌入层将一个长度为1000的噪声输入向量映射到一个32维空间。

位置编码器随后编码每个元素在输入嵌入中的位置信息。

Transformer编码器层通过全局自注意力机制处理噪声输入，生成有意义且去噪的输出。

Transformer模型的最后一层将编码器层的输出从高维空间（1000, 32）映射到长度为1000的向量（去噪模型输出）。

在以下章节中，我们将详细探讨Transformer模型的每个部分。

## 输入嵌入

在我们的Transformer模型中，输入嵌入层用于将输入向量（我们的1D噪声时间序列数据）从形状（1000,）映射到更高维度的表示，形状为（1000, d\_model），其中d\_model=32是我们希望映射到的维度数。我们使用常规的密集神经网络层来实现这一点。现在，每个输入值由一个32维的嵌入表示。

输入嵌入层的输出计算公式为：

 是长度为1000的输入向量， 是形状为（1000, 32）的学习权重矩阵， 是长度为32的偏置向量。输入嵌入的输出形状为（1000, 32）。

## 位置编码器

由于Transformer对输入向量中元素的顺序没有任何固有的概念，我们使用位置编码器注入位置信息。这是通过计算一组正弦函数并将其添加到输入嵌入中来实现的。正弦函数集如下所示：

![](assets/001.jpg)  
32维嵌入的位置编码，序列长度=1000

位置编码器PositionEncoder的代码如下：

Length  是序列长度， 是嵌入中的维度数。

PositionEncoding类PositionEncoding(tf.keras.layers.Layer)：

`def __init__(self, seq_len, d_model, **kwargs):       super(PositionEncoding, self).__init__()       self.pos_encoding = self.get_positional_encoding(seq_len, d_model)      def get_positional_encoding(self, seq_len, d_model, n=10000):       # 创建位置数组（形状：[seq_len, 1]）       position = np.arange(seq_len)[:, np.newaxis]       # 创建维度数组（形状：[d_model/2]）       denominator = np.power(n, 2 * np.arange(0, d_model, 2) / d_model)       # 计算正弦函数并堆叠       P = np.zeros((seq_len, d_model))       P[:, 0::2] = np.sin(position / denominator)  # 对偶数索引应用sin       P[:, 1::2] = np.cos(position / denominator)  # 对奇数索引应用cos       # 转换为TensorFlow张量并重塑为（1, seq_len, d_model）       P_tensor = tf.convert_to_tensor(P, dtype=tf.float32)       P_tensor_reshaped = tf.reshape(P_tensor, (1, seq_len, d_model))       return P_tensor_reshaped      def call(self, inputs):       return inputs + self.pos_encoding[:, :tf.shape(inputs)[1], :]   `

## Transformer编码器

Transformer编码器是去噪Transformer模型的核心，包含两个子层：全局自注意力层和前馈网络。在全局自注意力层和前馈网络之后应用残差连接（将层输入添加到其输出中）和层归一化步骤，以帮助缓解梯度消失问题并稳定训练。

全局自注意力层允许Transformer关注输入序列中的不同时间步，以确定在生成输出序列时需要注意哪些时间步。

与循环神经网络或卷积神经网络不同，全局自注意力同时处理整个输入序列，从而可以学习全局依赖关系。

我们的Transformer使用TensorFlow MultiHeadAttention层来计算自注意力输出。计算过程如下：

首先，全局自注意力层将位置编码器输出，形状为（1000, 32），作为查询、键和值矩阵的输入：

W\_Q、W\_K 和 W\_V 是可学习的权重矩阵，形状为（1000, d\_k）。由于我们的Transformer只有一个注意力头，d\_k = d\_model/H。其中 H=1 是注意力头的数量，因此，d\_k=32 对我们的模型来说。

接下来，我们计算注意力分数作为 Q 和 K^T 之间的点积：

注意力分数是一个形状为（1000, 1000）的矩阵，其中每个条目告诉你一个时间步对另一个时间步的关注程度。

接下来，我们缩放并对注意力分数应用 softmax 函数。这有助于稳定训练并提供概率注意力分布，其中注意力权重矩阵的每一行加起来为1：

最后，我们通过计算形状为（1000, 1000）的注意力权重矩阵和形状为（1000, 32）的值矩阵 V 之间的点积来计算全局自注意力层的输出。输出是一个形状为（1000, 32）的矩阵：

前馈网络【8】在Transformer编码器中有两个大小分别为128和32的密集层【7】，以及一个 dropout 层【10】以帮助防止模型过拟合并增强模型的表达能力。前馈网络通过在全局自注意力层混合跨时间步的信息后，独立地对每个时间步进行操作。

我们可以将前馈网络用方程表示为：

其中 W\_1 和 W\_2 分别是大小为（32, d\_ff）和（d\_ff, 32）的可学习权重矩阵（前馈网络的维度，d\_ff=128），b\_1 和 b\_2 分别是长度为 d\_ff 和 32 的偏置向量。前馈网络的输出形状为（1000, 32）。

残差连接和层归一化步骤在全局自注意力层和前馈网络之后应用，表示为：

EncoderLayer的实现如下：

`class EncoderLayer(tf.keras.layers.Layer):       def __init__(self, *, d_model, num_heads, dff, dropout_rate=0.1):           super().__init__()           self.self_attention = GlobalSelfAttention(               num_heads=num_heads, key_dim=d_model, dropout=dropout_rate)           self.ffn = FeedForward(d_model, dff)              def call(self, x):           x, attn_scores = self.self_attention(x)           x = self.ffn(x)           return x, attn_scores   `

# 最终层

Transformer编码器的输出形状为（1000, 32）。最终层在我们的Transformer模型中的作用是将编码器的输出映射回原始信号空间（1000,）。这是通过单个密集层【7】实现的。

完整的NoiseRemovalTransformer实现如下：

`class NoiseRemovalTransformer(tf.keras.Model):       def __init__(self, d_model, seq_len, num_heads, dff, num_layers, dropout_rate=0.1):           super(NoiseRemovalTransformer, self).__init__()           # 嵌入层           self.embedding_layer = tf.keras.layers.Dense(d_model, activation=None)           # 编码器层           self.enc_layers = [EncoderLayer(d_model=d_model, num_heads=num_heads, dff=dff, dropout_rate=dropout_rate) for _ in range(num_layers)]           # 最终层           self.final_layer = tf.keras.layers.Dense(1, activation=None)  # 输出一个值              def call(self, x, return_attn_scores=False):           x = self.embedding_layer(x)           x = self.pos_encoding_layer(x)           for i in range(len(self.enc_layers)):               x, attn_scores = self.enc_layers[i](x)           x = self.final_layer(x)           if return_attn_scores:               return x, attn_scores           return x   `

# 训练模型

## 生成合成时间序列数据

为了训练模型，生成合成时间序列数据。这分为三个步骤：

首先，使用随机游走算法生成一个干净的信号。随机游走的输出经过平滑处理，然后缩放到-1到1的范围内。

接下来，我们为每个干净信号添加噪声轮廓。首先，为基础噪声（0.1到0.5）分配一个随机值。通过将基础噪声乘以一个可变的噪声因子（0.5到2）来计算最大和最小噪声水平。最后，通过插值一组均匀间隔的点，这些点的变化在最大和最小噪声水平之间，生成噪声轮廓。

噪声信号是干净信号和生成的噪声轮廓之和：

其中  是干净信号， 是噪声信号， 是噪声轮廓。

应用最终的缩放步骤以准备数据用于训练，其中  被缩放到-1到1之间。相同的缩放应用于干净信号，以生成正确缩放的信号对：

用于生成合成时间序列数据的代码可以在这里查看。

## 训练

模型在1000个生成的信号对（800个训练样本，200个验证样本）上进行训练，使用Adam优化器【12】，学习率为0.001。使用均方误差（MSE）损失函数，并在训练过程中监控平均绝对误差（MAE）。训练样本被分割成16个样本一批，模型训练100个周期。

# 结果

## 信噪比与MSE

由于每个样本的噪声轮廓不同，我们可以查询我们的模型，以了解它在不同的噪声条件下表现如何。我们可以通过绘制模型的MSE与原始干净和噪声信号的信号与噪声比（SNR）的散点图来确定模型在不同噪声条件下的表现。SNR，以dB为单位，计算公式为：

![](assets/002.jpg)  
训练历史（LHS：MSE损失函数，RHS：MAE）

SNR：

SNR衡量了干净信号的强度相对于噪声。SNR值高表示信号质量高，值低表示信号质量低。SNR小于0表示噪声强于信号。

![](assets/003.jpg)  
MSE与SNR

上述500个训练样本的散点图显示，大多数样本聚集在  0.002 和  dB 左右。

在min(SNR)附近存在异常值，对应于低MSE，以及max(MSE)对应于高SNR。在这两个异常值区域，我们观察到与我们直觉相反的情况（低SNR与低MSE，高SNR与高MSE）。

这两个异常值的样本如下所示，以及从样本的主要集群中选取的样本。

在下面的每个图中，去噪信号（模型输出）以实线蓝色表示，原始干净信号以虚线蓝色表示，噪声信号（模型输入）以实线红色表示。

![](assets/004.jpg)  
最小SNR（对应于低MSE）样本（SNR  -7.047, MSE  0.002）

![](assets/005.jpg)  
最大MSE（对应于高SNR）样本（SNR  8.727, MSE 0.011）

![](assets/006.jpg)  
集群样本  MSE  0.002)

# 深入了解注意力机制

通过绘制注意力权重，我们可以建立对全局自注意力机制在我们去噪Transformer中如何工作的直觉。

在这个图中，行对应于查询（序列中收集信息的那些位置），列对应于键（序列中那些被关注的位置）。

集群样本的注意力权重如下所示：

![](assets/007.jpg)  
集群样本的注意力权重（SNR  5.709, MSE  0.002）

# 讨论

去噪Transformer模型在广泛的噪声条件下展示了从输入信号中去除噪声的强大能力。在结果部分绘制的三个样本显示了模型在极端情况和平均值下的表现。

min(SNR)（对应于低MSE）样本以噪声为主。由于信号没有大幅波动，模型能够在这些噪声条件下重建原始信号。

max(MSE)（对应于高SNR）样本表现出相反的行为——低噪声但强烈波动的干净信号。模型难以重建原始干净信号的波动，导致高MSE。

集群样本（大约  和  dB）具有不太强烈波动的原始干净信号和相对较高的噪声水平。模型能够在这些条件下重建干净信号。

绘制的集群样本的注意力权重显示出强烈的对角线优势，这意味着每个时间步主要关注自身及其邻居。

注意力权重中存在多个对角线带。这表明模型已经学习到训练中使用的噪声输入信号中的某些周期性结构。其原因是合成的训练数据中由于生成干净和噪声信号的方法而可能存在的一些周期性模式。

该模型特意在具有不同噪声水平和低整体SNR的样本上进行训练。对于未来的发展，应该可以针对具有特定噪声特征的信号去噪对模型进行微调。使用相同的Transformer架构，我们可以训练特定于特定去噪任务的专用模型，我们能够生成合成训练数据，其噪声轮廓具有需要去噪的系统的特征。

# 总结

在本文中，我们介绍了基于Transformer的机器学习模型用于时间序列去噪。我们介绍了时间序列去噪问题，并逐步构建了一个能够接受噪声输入信号作为输入并输出去噪信号的微型Transformer。合成的干净信号/噪声信号对被生成以训练模型。

总的来说，去噪Transformer模型展示了从输入信号中去除噪声并返回去噪输出的强大能力。本文介绍的基本Transformer架构可用于对模型进行微调或构建用于特定任务的专用去噪模型。

  

  

  

  

代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/008.png)