# 为AI而生的编程语言——Mojo

小燕子 映翡量化 2024-07-06 22:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484734&idx=1&sn=864ba914791df56f453886c8c769c553&chksm=9e7744a2c2569ad6e3403940d78ecccb8aff6385911e3e8898f84aee6643daea0632e875d8ef#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484734&idx=1&sn=864ba914791df56f453886c8c769c553&chksm=9e7744a2c2569ad6e3403940d78ecccb8aff6385911e3e8898f84aee6643daea0632e875d8ef#rd)

近日，一匹黑马突然进入开发者的视野，目前已正式开放下载。

它的名字叫**Mojo**，相信最近不少朋友也见过它。

![](assets/001.jpg)

Mojo 是一种专为人工智能开发人员设计的编程语言，其语法与 Python 有些相似。

![](assets/002.jpg)

据Mojo官网介绍，它结合了Python的易用性和C的高性能，解锁了AI硬件的可编程性和AI模型的可扩展性。

Mojo 看起来很有前途；哪家公司推出了它？

经过进一步调查发现，Mojo 是人工智能公司 Modular 推出的一种全新编程语言。

Modular 本身是一家非常年轻且新成立的 AI 初创公司，由 Chris Lattner 和 Tim Davis 于 2022 年创立。

![](assets/003.jpg)

提到这两位创始人，大家可能已经知道，他们都是业界的顶尖专家，Chris Lattner 也被称为“LLVM 之父”、“Swift 之父”，曾在苹果、谷歌、特斯拉等知名科技巨头领导 AI 和核心系统的研发。

Modular 的愿景非常宏伟，旨在从头开始重塑 AI 基础设施。

去年，Modular AI 获得了 3000 万美元融资。就在几天前，Modular 宣布又成功完成一轮融资，获得 1 亿美元。对于一家刚刚成立的初创公司来说，这是一个了不起的成就。

![](assets/004.jpg)

此外，在公司官网上可以看到，已有多家AI领域知名的投资机构参与其中。

![](assets/005.png)

编程语言 Mojo 有几个独特的特点。

## **1.性能：**

Mojo 充分利用硬件的特性和能力，包括多核系统、矢量单元和加速器单元，以及先进的编译器和异构运行时机制，在不增加复杂性的情况下实现了与 C++ 和 CUDA 相当的性能。

对于并行化，Mojo 使用 MLIR，使开发人员能够充分利用向量、线程和 AI 硬件单元。

![](assets/006.png)

## **2.互操作性：**

众所周知，Python的生态系统如今极其繁荣，拥有无数的函数、库、框架、模型、工具等等。

Mojo 可以访问整个 Python 生态系统。例如，使用 Mojo，您可以将 Numpy 和 Matplotlib 等库无缝集成并混合到您的代码中。

![](assets/007.png)

## **3.可扩展性：**

可扩展性也是 Mojo 的一大优势。Mojo 可以升级用户模型中现有的操作，让开发人员能够使用预处理、后处理和自定义替换等操作轻松扩展其模型。

Mojo 最初于今年 5 月初发布，上线几个月后便已建立起基本的规模和生态系统。

![](assets/008.png)

近日，Modular 官网宣布**Mojo 正式开放下载**，首发 Linux 系统，后续迭代中会加入对 Mac 和 Windows 的支持。

这意味着开发人员可以使用 Mojo SDK 试验并编写自己的 Mojo 代码。

![](assets/009.png)

在 Mojo 正式宣布开放下载后不久，一位名为 Aydyn Tairov 的开源开发者利用 Mojo 进行了一次开创性的尝试。

该开发人员之前曾将用纯 C 实现的流行 GitHub 项目 llama2.c 移植到基于 Python 的 llama2.py。

此次，Aydyn Tairov将llama2.py移植到了llama2.mojo，效果出奇的好，移植后性能提升了近250倍。

![](assets/010.gif)

尽管取得这样的成就，开发商仍然认为还有进步的空间。

看到Mojo的不俗表现，不少网友纷纷评论道：Python现在好像遇到了劲敌，未来Mojo甚至有可能取代Python？

对此，首席执行官 Chris Lattner 直接表示：

Mojo 不会对 Python 构成威胁，相反，它会让 Python 开发者变得更加强大。真正需要担心的不是 Python，而是 C++。

![](assets/011.png)

对于有兴趣尝试的人，文章还提供了相关页面的链接。

-   Mojo 地址：www.modular.com/mojo
-   Mojo 文档：docs.modular.com/mojo

至于这门编程语言在即将到来的AI时代将会如何演进，我们不妨拭目以待。

  

参考资料：

https://mp.weixin.qq.com/s/STlszhtsCp5BIGi35NBXoA

https://medium.com/stackademic/a-new-programming-language-is-born-51a91046d647