# 无梯度训练的循环神经网络

QuantML QuantML 2024-12-30 19:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488601&idx=1&sn=50500a955109f984bceb565e8d172333&chksm=cfeb913f64b01f93611f540e673004069ccd64fcfe7d8b82f8aff44393c0fbc035139b8d2571#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488601&idx=1&sn=50500a955109f984bceb565e8d172333&chksm=cfeb913f64b01f93611f540e673004069ccd64fcfe7d8b82f8aff44393c0fbc035139b8d2571#rd)

## 

![](assets/001.png)

摘要

循环神经网络（RNN）在处理时间序列分析、预测和动态系统建模等时间依赖性问题方面表现出色。然而，由于其损失梯度在训练过程中容易发生爆炸或消失，使用时间反向传播训练这些网络一直是一个难题。本文提出了一种无需基于梯度的方法来构建RNN的所有权重和偏置。该方法结合了随机特征网络和动态系统的Koopman算子理论。通过随机采样单个循环模块的隐藏参数，并使用扩展动态模式分解（EDMD）构建外部权重，这种方法解决了与RNN相关的所有反向传播问题。与Koopman算子理论的联系还使我们能够利用该领域的现有成果来分析RNN。在时间序列、混沌动态系统预测和控制问题以及天气数据的计算实验中，我们观察到，与常用的基于梯度的方法相比，我们构建的RNN的训练时间和预测精度均有所提高。

## 1\. 引言

循环神经网络（RNN）以其处理时间序列数据的强大能力而闻名，但其训练难度同样出名。RNN的损失梯度在时间反向传播过程中容易饱和或发散，这一问题被称为梯度爆炸和消失问题（EVGP）【Pascanu等人，2013年；Schmidt等人，2019年】。在公式（1）中，我们描述了一个由映射F和g控制的通用非线性系统，该系统受外部输入xt控制。典型的RNN建模方法会直接训练网络F、G以及方程右侧所有矩阵K、B、C、V的所有参数。

我们的方法首先基于Koopman算子理论构建一个线性状态空间模型（SSM）【Korda和Mezic，2018a】。矩阵K将状态从zt-1映射到zt，输入xt通过矩阵B影响这种动态。观测值通过线性映射V与状态相关。

![](assets/002.png)

我们建议使用非线性神经网络将低维状态h映射到更高维度，通过F(h) := o(Wh + b)，同样，将输入x映射到高维输入G(x) = o(Wrx + bx)。这将线性SSM转变为非线性循环神经网络。通常，这种非线性映射也是许多基于Koopman算子模型的核心理念：从非线性系统的状态ht-1开始，使用非线性映射到更高维度的状态Zt-1，然后在这个高维空间中利用线性映射K向前推进时间。然后，该映射是原始非线性系统线性Koopman算子的近似。

![](assets/003.png)

至关重要的是，在本文中，我们从特定的数据相关概率分布中采样权重W和偏置b。然后，可以通过解决一系列线性问题来找到矩阵K、B、C、V中剩余的自由参数（见图1）。这种方法解决了与梯度反向传播相关的所有问题，并将循环架构的思想与底层动态系统的Koopman算子联系起来。后者使我们能够证明关于F中神经元数量近似质量的收敛结果。我们在几个具有挑战性的合成数据和真实数据示例上展示了这种方法的有效性。

## 2\. 相关工作

梯度爆炸和消失：对于所有主要的RNN类型，包括LSTM和GRU，RNN的动态和损失梯度紧密相关。如果RNN动态收敛到一个稳定的固定点或周期，损失梯度将保持有界，但可能会消失【Mikhaeil等人，2022年】。然而，已有的解决方法【Hochreiter和Schmidhuber，1997年；Schmidt等人，2019年】可以有效地防止其梯度消失。然而，在混沌动态中，梯度不可避免地会发生爆炸，这带来了一个挑战，无法通过RNN架构调整、正则化或约束来缓解；相反，它需要在训练过程中解决【Mikhaeil等人，2022年】。分岔也可能导致在RNN训练过程中观察到的损失突然跳跃，可能会严重阻碍训练过程【Doya等人，1992年；Eisenmann等人，2023年】。Eisenmann等人【2023年】已经证明，基于ReLU的RNN中特定的分岔总是与训练期间的EVGP相关联。因此，为了充分利用RNN，训练算法需要精心设计，以应对分岔和可能出现的EVGP带来的挑战。

记忆的诅咒：长期记忆的存在对RNN的学习过程产生负面影响【Bengio等人，1994年；Hochreiter等人，2001年；Li等人，2021年】。这种负面影响被“记忆的诅咒”概念所捕捉，该概念指出，当数据中存在长期记忆时，近似关系需要指数级数量的神经元，导致学习动态显著放缓。具体来说，当目标关系包括长期记忆时，学习过程的近似和优化都变得非常具有挑战性【Li等人，2021年】。

混沌和多稳态动态重建的损失函数。为了有效地训练RNN并评估重建情况，仔细选择合适的损失函数至关重要。均方误差（MSE）是重建任务中常用的损失函数。MSE是在高斯噪声假设下推导出来的，当处理混沌系统或多稳态动态时，它可能不是最合适的选择，因为这些系统的底层噪声特性可能偏离高斯分布假设。由于混沌动态系统不可预测的行为和突然变化，MSE不适合作为其测试损失【Wood，2010年】。在多稳态系统中，由于存在多个稳定状态，MSE可能难以区分这些状态。损失函数可能无法充分惩罚不同吸引子之间的偏差，导致系统多稳态行为的重建不够准确。尽管提出了替代方案，但挑战依然存在，尚未找到重建混沌或多稳态动态的最佳损失函数【Ciampiconi等人，2023年】。

解释性不足。深度学习模型通常被视为“黑匣子”，而现有的理解RNN决策过程的方法提供的解释有限，或者依赖于局部理论。缺乏分析RNN训练算法以及训练过程本身的理论是领域内尚未解决的问题【Redman等人，2023年】，除了线性系统模型【Datar等人，2024年】。

随机选择内部网络参数。随机选择神经网络内部参数的一般思想在随机特征模型（包括深度架构）中得到了研究。Barron【1993年】和Rahimi和Recht【2008年】发展了基本理论，Gallicchio和Scardapane【2020年】提供了综述。储层计算（也称为回声状态网络，参见Jaeger和Haas【2004年】）可能与本文提出的想法最为接近。在储层计算机中，内部权重也是随机采样的，并且构建了一个循环的、时延模型来近似给定的动态系统。这种架构已成功用于模拟混沌系统（参见Pathak等人【2018年】、Gauthier等人【2021年】、Bollt【2021年】）。尽管与循环架构有相似之处（参见Lukoeviius和Jaeger【2009年】），但储层计算机的概念以及架构通常与使用时间反向传播训练的经典循环神经网络分开处理。在本文中，我们直接计算所有经典循环神经网络的参数，没有储层计算机中存在的时延组件。

Koopman算子理论。Koopman算子是与每个动态系统相关联的对象。它在时间上发展系统的状态的可观测性。这种演化是线性的，这是该算子被广泛用于模拟动态系统的主要原因【Mezi，2005年，2013年；Korda和Mezic，2018b；Gallos等人，2024年】。许多数值近似算法存在【Schmid，2010年；Williams等人，2015a；Li等人，2017年；Mezic，2020年；Schmid，2022年】。Koopman算子的字典已使用梯度下降【Li等人，2017年】和随机特征【Salam等人，2022年】构建的神经网络构建。Bollt【2021年】和Gulina和Mauroy【2020年】也讨论了储层计算与Koopman算子近似的关系。据我们所知，Koopman算子与循环神经网络的权重矩阵的关系之前没有被观察到。这是我们在本文中讨论的内容。我们还提供了一个数据相关概率分布，用于隐藏参数，这是与储层计算中通常使用的与数据无关的分布（例如，正态分布、均匀分布）最大的不同。

## 3\. 数学框架

我们首先定义RNN和底层动态系统的一般框架，然后介绍采样及其与Koopman算子的联系。设X ⊂ Rdx为输入空间，y ⊂ Rdy为输出空间，H ⊂ Ran为状态空间。我们假设这些空间分别与测度μx、μy和μh相关。然后通过演化算子F定义底层动态系统，我们可能在不受控系统ht = F(ht-1)或受控系统ht = F(ht-1, xt)中进行工作。我们还表示输入数据集X = \[x1, x2, ..., xN\]和观测数据集Y = \[y1, y2, ..., yN\]。在本文中，我们对建模可观测状态的动态系统的RNN感兴趣，因此我们通常假设可以访问数据集H = \[h1, ..., hN\]以及其一步后的副本H' = \[h'1, ..., h'N\]，其中ht = F(ht), t ∈ {1, ..., N}。

我们使用激活函数o : R → R，在本文中我们主要使用o = tanh，因为它是一个解析函数，并且与SWIM【Bolager等人，2023年】相关。其他函数，如ReLU也是有效的选择。以下定义概述了我们考虑的模式。

![](assets/004.png)

备注1. 为了完整性，我们添加了作为任意激活函数。我们选择将设置为恒等函数，以允许我们在下面描述的过程中求解最后一个线性层。其他激活函数，如logit也是可能的。

训练这种类型的RNN的传统方法是迭代反向传播，它存在上述问题，如EVGP和高计算复杂度。我们改为从采样隐藏层参数开始，以规避反向传播，如下所述。

## 3.1 采样RNN

采样神经网络是指隐藏层的参数是从某个分布中采样的，而最后一个线性层要么被采样，要么更常见的是通过线性求解器求解。遵循Galaris等人【2022年】和Bolager等人【2023年】的想法，我们通过从域H和X中采样点对来采样Fy和Fx的隐藏层的权重和偏置，并从这些点对中构建权重和偏置。然后，我们在最后解决一个线性（一般）回归问题，用于映射到下一个状态的最后一个线性层。具体来说，让PH和Px分别是H2和X2上的概率分布。对于FH的隐藏层中的每个神经元，采样(h(1), h(2)) ~ PH，并设置所述神经元的权重w和偏置b为

![](assets/005.png)

其中|| . || 和 <., .> 通常是欧几里得范数和内积，S1, S2 ∈ R是常数。对FH和Fx中的所有神经元重复相同的程序。由于本文中我们坚持使用单隐藏层网络，因此我们在这里忽略了多层采样，并建议读者参考Bolager等人【2023年】了解任意数量的隐藏层的完整采样和构建过程。

这种采样技术使权重和偏置适应底层域，并构建出沿数据方向的权重（参见附录C中的示例，说明如何使用此方法解释结果网络）。从经验上看，这比使用与数据无关的分布（如标准高斯分布）有所改进。

人们可以选择任意概率分布作为PH和Px，均匀分布是一个常见的选择。在监督设置中，Bolager等人【2023年】还提出了一个采样分布，其密度捕获目标函数的陡峭梯度。在本文中，我们使用与以下密度成比例的密度py和px进行采样：

![](assets/006.png)

一旦权重和偏置被采样，我们必须解决一个通用回归问题

![](assets/007.png)

总之，我们定义一个采样RNN为一个模型，该模型是通过采样RNN的隐藏层的权重，然后解决公式（5）中的回归问题来构建的。

## 3.2 涉及Koopman算子

我们已经介绍了网络，其中是其单个隐藏层中的神经元数量，同样地，对于也是如此。然后我们分别通过应用和投影到。为了给矩阵和添加更多的结构和可解释性，我们将设置和，其中，，并且。我们最终得到的函数是

![](assets/008.png)

注意，如果输出y与h不同，我们利用高维度优势，而不是先通过C投影下来，而是设置yt = V zt。这完成了公式（1）中的设置。

矩阵Ch和Cz分割的原因是：隐藏层FM和Go将其各自的输入映射到更高维度的空间。在更高维度的空间中，由F描述的可能非线性的演化变得越来越线性【Korda和Mezic，2018b】。然后，这种演化通过K和B的线性变换被捕获，然后我们通过C映射到状态空间。这也允许我们将K和B与应用于动态系统的Koopman理论联系起来。给定一个合适的函数空间F，Koopman算子K: F → R定义为

![](assets/009.png)

Koopman算子捕获了动态系统在函数空间F中的演化，而不是在状态空间本身。在大多数情况下，这使得算子无限维，但作为回报，是一个线性算子。有关Koopman算子的介绍和周围理论，请参见附录A。然后可以将矩阵K和B视为Koopman算子的近似，直觉是选择足够大的M意味着我们可以在映射到状态空间之前捕获线性演化。

矩阵Wh和We是通过从Ph和Pz中分别采样每一行i.i.d.找到的。为了估计C、K和B，我们使用扩展动态模式分解（EDMD）-一种经典的寻找Koopman算子有限维近似的方法。这里我们对EDMD进行非常简短的描述，并在附录A.1中给出更深入的介绍。在不受控设置中，该方法选择字典 并估计Koopman算子/使用数据H、H'通过最小化

![](assets/010.png)

其中 。令  并且 ，那么近似可以写成：

其中 表示矩阵的伪逆。类似地，在控制设置中， 的近似被分解为矩阵 和 ，

其中 是从 到 的第二个字典映射。关于控制环境下的Koopman算子以及EDMD的更多信息，请参见附录A.2。无论是否受控，映射 从高维字典空间投影到状态空间，并通过最小化 来近似，因此

我们通过将函数 和 设置为隐藏层，将EDMD算法与我们的循环网络（方程6）联系起来，即  和 。通过这种方式，我们可以看到在方程6中近似 和 可以被视为一个Koopman近似，其中字典是一个分别具有 和 个神经元的隐藏层。这种联系强调了在更高维空间中操作的好处。它还允许我们在下一节中利用Koopman理论，因为已知EDMD近似会收敛到 。最后，重要的是要注意，方程6中得到的函数由两个神经网络组成，分别应用于先前的状态和输入。隐藏层被采样，外部矩阵使用线性求解器构建。因此，方程6是一个采样的循环神经网络。上述方法可以通过以下方式总结：在算法1中采样权重，在算法2中构建RNN，在算法3中对非受控系统进行预测，以及在算法4中进行模型预测控制。

![](assets/011.png)

## 3.3 采样RNN的收敛性

在某些条件下，对于不受控系统的采样RNN的收敛性可以证明任意有限预测范围的收敛。结果表明，通过估计K使用公式（7）来证明收敛。这与通常存在的RNN参数证明不同，并且由于上一节中建立的Koopman连接而成为可能。

## 4\. 计算实验

我们现在讨论一系列实验，旨在说明我们构建方法的优点和挑战。我们将我们的方法与最先进的迭代梯度基方法shPLRNN进行比较，该方法在附录D中解释。对于真实的天气数据集，我们还将我们的方法与长短期记忆（LSTM）模型进行比较。此外，由于我们的方法与储层模型有相似之处，我们还将与一个已建立的储层模型进行比较，即回声状态网络（ESN），在附录E中有进一步的解释。有关数据集的详细信息，请参见附录F，所有模型的超参数见附录H，评估指标在附录G中解释，以及进一步的比较讨论和硬件详细信息在附录H中提供。

在表1中，我们列出了无控制实验的定量结果。每个条目来自五次不同的运行，其中随机种子被改变，以确保证更稳健的结果。我们给出了这五次运行的平均值，以及其中的最小值和最大值。

![](assets/012.png)

## 4.1 简单ODEs：Van der Pol振荡器

我们考虑Van der Pol振荡器系统作为我们方法的简单说明。使用具有tanh激活和80个宽度单隐藏层的采样RNN，并遵循算法3的预测方法。该模型在测试数据上进行评估；报告的平均误差和训练时间在表1中。测试集中的一条轨迹在图2中可视化。值得注意的是，预测从测试数据集中的初始条件开始，用于进行第一次预测，之后继续使用此预测作为输入来预测下一个状态，而没有来自地面真相数据集的信息。在结果中，我们观察到在很长的预测范围内非常稳定的轨迹，并且所有Koopman算子的特征值都在单位圆内（见附录C），因此我们可以确定该模型是稳定的。这个实验也具有重要意义，因为系统的周期性被我们的模型捕获，尽管神经网络架构通常难以捕获周期性【Ziyin等人，2020年】。与梯度下降训练的shPLRNN相比，我们的方法更快，并且实现了更高的预测精度，具有较低的MSE作为预测误差。与ESN相比，我们的模型具有更短的拟合时间和更小的误差。此外，对于我们的方法，超参数搜索要简单得多，耗时也更少，因为要调整的超参数更少。

## 4.2 时间延迟嵌入示例：Van der Pol振荡器

对于许多现实世界的例子，不可能观察到系统的完整状态。在这里，我们使用与简单Van der Pol实验（第4.1节）相同的数据库，但只考虑第一个坐标h1。我们使用六次时间延迟嵌入数据，然后进行主成分分析（PCA）投影，将维度降低到两个。使用具有tanh激活和80个宽度单隐藏层的采样RNN进行训练。从初始测试数据集状态预测的轨迹显示在图2的右侧列的底部行中。拟合时间和MSE误差在表1中提供，它们与观测到完整状态的示例中的拟合时间和误差相当，表明该模型也捕获了真实动态。

## 4.3 混沌动态示例：Lorenz和Rssler系统

混沌系统提出了一个具有挑战性的预测问题，从动态系统类别中。作为一个例子，我们考虑在混沌区域中的著名的Lorenz系统。训练一个具有tanh激活和200个宽度单隐藏层的采样网络。测试轨迹的预测在图3中可视化。为了评估模型，我们不计算MSE，因为它不适合混沌轨迹，而是计算经验KL散度（EKL），以比较轨道。有关此几何度量的详细信息，请参见附录G。报告了平均EKL和训练时间在表1中。我们的采样RNN实现了与储层模型相当的性能。然而，应该注意的是，在Lorenz数据上训练储层模型是一个经过充分研究的问题，超参数的选择已经经过仔细调整以实现卓越的性能。当选择我们的采样RNN的超参数时，我们发现所需的努力很低，因为与储层相比，自由度不多。另一方面，与使用梯度下降训练的shPLRNN相比，我们观察到在误差和训练时间方面都有更好的性能。

![](assets/013.png)

## 4.4 控制输入示例：强制Van der Pol振荡器

我们再次考虑Van der Pol振荡器，现在第二个坐标h2受外部输入x控制，并使用采样RNN模型执行模型预测控制（MPC）如算法4中所示。我们让Go为恒等函数，并让B从X映射到RM（为x添加非线性并没有为这个系统产生不同的结果，并且在附录H.1.1中描述）。然后，采样循环神经网络是恒等Ga和FM是具有128宽度和tanh激活的隐藏层。该网络随后被传递给线性二次调节器（LQR）。该网络与LQR结合，可以成功地引导状态到目标状态（见图5）。我们考虑了五个不同的运行，其中只有随机种子变化，并获得平均控制器成本为125.92，平均训练时间为1.122秒。状态的L2范数也随时间跟踪，对于五个不同的运行，我们显示了范数以及点平均（在运行上）在图5中。这个实验突出了我们模型的一个关键优势，它允许使用线性控制器如LQR对非线性系统如Van der Pol振荡器进行建模。这意味着我们可以使用线性控制理论中的成熟工具应用于非线性系统。

![](assets/014.png)

![](assets/015.png)

## 4.5 真实世界数据示例

我们将我们的方法应用于TensorFlow【2024】中呈现的气候数据。该数据集包含2009年1月1日至2016年12月31日期间在德国耶拿记录的时间序列14个天气参数。我们使用了实验中最大的连续时间范围，并训练了一个采样RNN来预测温度参数（图6）。我们还训练了一个在TensorFlow【2024】中描述的自回归LSTM模型和一个shPLRNN作为迭代基线。

数据提供了在选择时间延迟和预测范围的大小时有自由。我们决定将时间延迟固定为一周，并设置了两个不同的实验，预测范围为一天和一周。在采样RNN和LSTM实验中，我们对每个模型进行了网格搜索，超参数在附录H.4.1中指定。

表1显示了两个选定范围（天和周）的平均训练时间和误差指标。我们观察到，在较短的范围情况下，采样和迭代模型的表现相似，而采样提供了更快的训练。当考虑一周的范围时，shPLRNN预测性地优于LSTM，但采样RNN仍然快了几个数量级。我们还注意到预测范围并不影响采样模型的训练时间，这与算法2一致。当比较较长范围的预测时（图6），我们注意到LSTM难以预测测量值的高频波动，但采样RNN和shPLRNN成功捕获了它们。图6还突出了MSE指标的不足，因为低平均误差并不总是对应于准确的预测，正如所有三个模型所说明的那样。总之，我们得出结论，采样RNN可以成功地捕获混沌的真实世界动态，并产生与迭代模型相当的结果，同时在训练速度上提供了显著提升。

## 5\. 结论

我们通过结合随机特征网络和Koopman算子理论，提出了一种高效且可解释的训练循环神经网络的方法。

**优势：**在许多例子中，我们证明了我们可以训练出比通过迭代方法训练的网络更精确的循环网络，并且训练速度提高了几个数量级。我们还观察到，这种训练方法适用于非常少量的训练数据。与Koopman算子理论的直接联系使我们能够借鉴现有动态系统的理论成果，我们利用这些成果证明了在无限宽度极限下的收敛性。此外，同样的联系使我们能够将线性控制理论应用于非线性系统。

**局限性：**我们使用的训练方法涉及解决一个大型线性系统。解决这个系统的复杂性取决于最小神经元数量和数据点数（分别对应时间步数）的立方。这意味着如果网络和数据点数一起增长，训练的计算时间和内存需求增长得太快。对于时间反向传播，内存需求主要是因为在一次更新过程中必须存储许多梯度。

  

  

  

论文及代码见星球

![](assets/016.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 还在使用MSE？试试这些更加适合金融预测的损失函数](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487997&idx=1&sn=e05e8e0dafa605615d425ff1f0702c4b&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 如何运行日内中高频模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰SAM：提升AI量化模型的泛化性能 研报复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487238&idx=1&sn=41cbb5b3bb3e5a277c9175ba64642259&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰AlphaNet模型复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学&华泰证券 在高胜率时交易](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485500&idx=1&sn=b29e1d2efe2482165245ab6add4af051&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)[QuantML-Qlib Model | 滚动模型训练](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
    研报复现：
    
      
    
-   [重磅更新！80+量化策略复现（持续更新中）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488528&idx=1&sn=f9c98f60baca2b690956ff6b56a2553f&scene=21#wechat_redirect)
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [研报复现 | QRS择时信号及改进](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-下](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486787&idx=1&sn=bfe98c0b8d331027191761df3b85ea8c&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-上](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486761&idx=1&sn=84a2de96dd3bc7a7fb38386684b3eec4&scene=21#wechat_redirect)
    
-   [研报复现 | 锚定反转因子](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486379&idx=1&sn=d6763bb198d0706c101f2544aa752b4f&scene=21#wechat_redirect)
    
-   [研报复现 | 另类ETF交易策略：日内动量](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&scene=21#wechat_redirect)
    
-   [研报复现 | 国盛金工：如何将隔夜涨跌变为有效的选股因子？——基于对知情交易者信息优势的刻画](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485766&idx=1&sn=89d4060fb135105b969c0ef2f145a7e0&scene=21#wechat_redirect)
    
-   [研报复现 | 招商证券：基于鳄鱼线的指数择时及轮动策略](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485702&idx=1&sn=2b0ed284177a66ee9d0e8623cd9cb1b4&scene=21#wechat_redirect)
    
-   [研报复现 | 华西金工-股票网络与网络中心度因子研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484829&idx=1&sn=3da8197374301bab9610f7ed5d4b715b&chksm=ce7e6283f909eb9509b3ebc9989fe9d140d5ee663ac8749aeb608833ff37544421d0dcd0fa9c&scene=21#wechat_redirect)  
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
-   [研报复现 | 开源证券 ：形态识别，均线的](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)[券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [利用LangGraph 和 OpenAI 打造金融分析师Agent](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [JFQA | 基于深度学习的排序特征因子模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488380&idx=1&sn=15327d544022028afab9efa2a90a0c36&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [NIPS 24 | PGN：RNN 的新继任者](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488128&idx=1&sn=a8287377302d2cdf5d1d6ddc321cdf31&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)  
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [ICLR 2024 | 通向透明的时间序列预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484754&idx=1&sn=44bcf54c0caa1001ac343648d89a9407&chksm=ce7e624cf909eb5a44ce762087ef23bd8cfeb663aa623f0d729b99d56450abafd525d927bc5e&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)