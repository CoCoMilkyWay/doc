# QuantML-Qlib Model | 华泰AlphaNet模型复现

QuantML QuantML 2024-08-05 20:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&chksm=cf2b7b4e6b50717b6ac5f7a962bd287dcbaba59a11d72f5681335097b512b3da3303c310f555#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&chksm=cf2b7b4e6b50717b6ac5f7a962bd287dcbaba59a11d72f5681335097b512b3da3303c310f555#rd)

Content

> 华泰金工《再探 AlphaNet：结构和特征优化》
> 
> https://crm.htsc.com.cn/doc/2020/10750101/74619658-f648-4001-a255-5b78174b073a.pdf

  

AlphaNet-v3是华泰金工研究团队开发的一个基于深度学习的股票量化投资模型，它是AlphaNet系列的第三个版本。与前一版本相比，AlphaNet-v3在结构和特征提取上进行了显著改进。![](assets/001.png)

1.  结构优化：AlphaNet-v3在特征提取层进行了扩展，引入了两个具有不同回看区间（分别为10和5）的特征提取层，这增强了模型对股票量价数据不同时间尺度信息的捕捉能力。此外，AlphaNet-v3将前版本中的LSTM层替换为了GRU（Gated Recurrent Unit）层，这样做的好处是减少了模型的参数数量，同时保持了模型性能，使得模型更加高效。
    
    ![](assets/002.png)
    
    ![](assets/003.png)
    
2.  特征增强：AlphaNet-v3在特征处理方面，特别强调了比率类特征的有效性，因此在模型中增加了6个比率类特征，这些特征丰富了模型对股票市场行为的理解，有助于更好地揭示价格变动背后的原因。
    
    ![](assets/004.png)
    
3.  性能提升：在全A股和中证800成分股的测试中，AlphaNet-v3展现了优于AlphaNet-v2的表现。特别是在中证500成分股中，AlphaNet-v3的RankIC均值从9.05%提升至9.70%，ICIR从0.89提升至1.00，这表明了模型在预测股票收益率方面的有效性和稳健性有所增强。尽管AlphaNet-v3在模型可解释性方面可能存在局限，但其端到端的学习方式大大简化了从原始数据到alpha因子的整个流程，减少了对单因子测试和相关性分析的依赖。
    
    ![](assets/005.png)
    

  

代码实现  

AlphaNet-v3的模型代码已经加入QuantML-Qlib,目前在alphazoo目录之下。

![](assets/006.png)

  

模型主体部分代码如下：

```
class AlphaNet(nn.Module):
```

  

模型运行代码在jupyter notebook中，数据并非跟alphanet一致，而是直接采用了qlib的alpha360因子，省去了后续自己处理数据，构建dataloader的麻烦，非常方便。简单训练了5轮，损失函数表现如下：

![](assets/007.png)

  

模型的回测效果：

![](assets/008.png)

  

欢迎加入星球一起交流改进模型。

### 

  

**加星球请扫我，某书购买加入有优惠活动：**

![](assets/009.png)

  

  

**入群交流请扫我：**

![](assets/010.jpg)

  

  

**点击蓝字**

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/012.jpg)