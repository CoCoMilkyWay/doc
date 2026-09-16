# 取代MLP？MIT全新神经网络结构KAN,3天1.4k star

QuantML QuantML 2024-05-02 15:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=cf2b6f0f507e09f1ee805831bab7e55d78e4e587413d9e02543ed10987ba62c37da29e002dc8#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=cf2b6f0f507e09f1ee805831bab7e55d78e4e587413d9e02543ed10987ba62c37da29e002dc8#rd)

Content  

论文地址：arxiv.org/pdf/2404.19756

代码地址：GitHub - KindXiaoming/pykan: Kolmogorov Arnold Networks

  

这篇论文介绍了一种新型的神经网络架构——Kolmogorov-Arnold Networks（KANs），它是由Kolmogorov-Arnold表示定理启发而来，旨在作为多层感知器（MLPs）的有前途的替代品。KANs的核心特点是在网络的边缘（即权重）上拥有可学习的激活函数，而不是像传统的MLPs那样在节点（即神经元）上使用固定的激活函数。这些激活函数由一元函数（univariate functions）组成，每个权重参数被一个作为样条（spline）参数化的一元函数所替代。论文展示了KANs在准确性和可解释性方面相较于MLPs的优势。

![](assets/001.png)

1.  KANs的提出：作者提出了KANs，这是一种新型的神经网络，其灵感来源于Kolmogorov-Arnold表示定理。KANs的特点是在网络的边缘拥有可学习的激活函数，而不是在节点上使用固定的激活函数。
    
    ![](assets/002.png)
    
2.  模型结构：
    

1.  无固定激活函数：与传统MLP在节点上使用固定的激活函数（如ReLU、Sigmoid等）不同，KAN模型的激活函数是可学习的，并且放置在网络的边缘（即权重）上。
    
2.  激活函数的参数化：KAN中的每个激活函数由一个一元函数（univariate function）组成，这些函数被参数化为B样条（B-spline）曲线。这意味着每个权重参数不再是一个单一的数值，而是一个函数。
    
    ![](assets/003.png)
    
3.  网络的宽度和深度：KAN模型可以设计为任意宽度和深度。在论文中，作者展示了如何通过堆叠KAN层来构建更深的网络。每一层都可以被视为一个函数矩阵，其中的函数具有可训练的参数。
    
4.  节点的计算：在KAN模型中，节点（或称为神经元）执行的是简单的加法运算，而不是应用非线性激活函数。这是KAN模型与传统MLP的另一个关键区别。
    
5.  模型的形状表示：KAN模型的形状可以用一个整数数组来表示，例如\[n0, n1, ..., nL\]，其中ni是计算图中第i层的节点数。
    
6.  激活函数的连接：在层l和层l+1之间，存在nl \* nl+1个激活函数。每个激活函数ϕl,i,j连接第l层的第j个节点和第l+1层的第i个节点。
    
7.  前激活和后激活：每个激活函数的前激活（pre-activation）是输入信号xl,i，而后激活（post-activation）是ϕl,i,j(xl,i)。
    
8.  输出的计算：第l+1层的神经元的激活值是所有进入该神经元的后激活值的总和。
    
9.  模型的组合：一个通用的KAN网络是L层的组合，给定输入向量x0，KAN的输出由以下公式给出：  
    
    ![](assets/004.png)
    
    其中◦表示函数的复合，Φl是第l层的函数矩阵  
    
10.  训练和优化：由于KAN模型中的所有操作都是可微分的，因此可以使用反向传播算法进行训练
     

4.  性能对比：论文通过实验表明，KANs在数据拟合和偏微分方程（PDE）求解方面，比MLPs具有更高的准确性，并且参数效率更高。
    
    ![](assets/005.png)
    
    ![](assets/006.png)
    
5.  理论基础：论文提供了KANs的数学理论基础，包括Kolmogorov-Arnold表示定理的概述，以及KANs的表达能力和神经缩放法则（neural scaling laws）。
    
6.  可解释性：KANs的另一个优势是其可解释性。由于网络的可解释性，KANs可以直观地可视化，并且可以与人类用户轻松交互。
    
    ![](assets/007.png)
    
    ![](assets/008.png)
    
7.  科学应用：论文还展示了KANs在数学和物理学中的应用，例如在数学中的结理论（knot theory）和物理学中的Anderson局域化现象。
    
    ![](assets/009.png)
    
    ![](assets/010.png)
    
8.  实现细节：论文讨论了KANs的实现细节，包括残差激活函数、初始化尺度和样条网格的更新。
    
9.  简化和交互：为了提高KANs的可解释性，论文提出了一系列简化技术，包括稀疏化、可视化、剪枝和符号化。
    
10.  持续学习：论文探讨了KANs在持续学习（continual learning）中的应用，展示了KANs如何利用样条的局部性来避免灾难性遗忘（catastrophic forgetting）。
     
     ![](assets/011.png)  
     

  

KANs作为一种新型的神经网络架构，在准确性、可解释性以及科学应用方面展现出了巨大的潜力。论文通过理论分析和广泛的实验验证了KANs的优势，并讨论了其在科学研究中的潜在应用

  

  

  

**论文及代码下载见星球**

  

**点击蓝字**

![](assets/012.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/013.jpg)

![](assets/014.png)

**微信号****｜****QUANTML**

**星球号｜QUANTML**