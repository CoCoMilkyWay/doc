# 2024年必须知道的网络-直接上分！

无言 量化前沿速递 2024-11-21 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488314&idx=1&sn=71b633c3f0ed6d1bcd16b8d886ed42a6&chksm=c316d26364d06184825620fbc5b38649e75b7b9a03b63844e4db434885f0b382c674de4f9b06#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488314&idx=1&sn=71b633c3f0ed6d1bcd16b8d886ed42a6&chksm=c316d26364d06184825620fbc5b38649e75b7b9a03b63844e4db434885f0b382c674de4f9b06#rd)

# 

  

**KAN: Kolmogorov–Arnold Networks**

## 

简介

![](assets/001.png)

本文介绍一份最新的工作-KAN，在自己测试的数据集中，KAN都得到了非常不错的效果，KAN可以认为是MLP模型的完美替代，MLP和KAN的关系可以直观地通过下面的图展示。

![](assets/002.png)

-   MLP一般是线性转换之后通过固定的激活函数进行处理；
    
-   KAN则是拥有科学系的激活函数，KAN没有线性的权重，每个权重参数都被替换为一个参数化为样条的单变量函数。
    

KAN在实际建模中，亲测非常有效，有兴趣的可以自己尝试一下。

## 

MLP VS KAN

![](assets/001.png)

### 1.MLP

其中 是固定的激活函数。

### 2.KAN

![](assets/003.png)

具体操作可以参考下图：

![](assets/004.png)

  

-   先通过某种操作，例如分grid操作将我们的每个特征都分到某个里面；
    
-   然后对相同grid的值进行函数计算并计算和得到下一层对应位置的值；
    

![](assets/005.png)

## 

代码

![](assets/001.png)

```
from kan import KANimport matplotlib.pyplot as pltfrom sklearn.datasets import make_moonsimport torchimport numpy as np# 1.构建数据集dataset = {}train_input, train_label = make_moons(n_samples=1000, shuffle=True, noise=0.1, random_state=None)test_input, test_label = make_moons(n_samples=1000, shuffle=True, noise=0.1, random_state=None)dataset['train_input'] = torch.from_numpy(train_input).type(dtype).to(device)dataset['test_input'] = torch.from_numpy(test_input).type(dtype).to(device)dataset['train_label'] = torch.from_numpy(train_label).type(torch.long).to(device)dataset['test_label'] = torch.from_numpy(test_label).type(torch.long).to(device)X = dataset['train_input']y = dataset['train_label']# 2.训练KANmodel = KAN(width=[2,2], grid=3, k=3, seed=2024, device=device)def train_acc():    return torch.mean((torch.argmax(model(dataset['train_input']), dim=1) == dataset['train_label']).type(dtype))def test_acc():    return torch.mean((torch.argmax(model(dataset['test_input']), dim=1) == dataset['test_label']).type(dtype))results = model.fit(dataset, opt="LBFGS", steps=20, metrics=(train_acc, test_acc), loss_fn=torch.nn.CrossEntropyLoss());
```

## 

小结

![](assets/001.png)

-   KAN相较于MLP得到了更好的效果：KAN中的可学习激活函数相比于MLP的固定激活，能够捕捉数据中更复杂的关系。这种灵活性可以在特定任务上带来更好的表现，特别是那些涉及复杂模式的任务。
    
-   更高的解释性：与MLP（黑箱）较为不透明的特性不同，KAN提供了一定程度的可解释性。通过分析基函数的学习系数，研究人员可以深入了解网络是如何做出决策的。这对理解模型的内部运作非常有价值，并可能进一步提升其性能。这将消除许多在人工智能过度监管的国家中推广应用的障碍。
    

# 

参考文献

![](assets/001.png)

1.  https://arxiv.org/pdf/2404.19756
    
2.  https://kindxiaoming.github.io/pykan/Example/Example\_4\_classfication.html