# PyTorch 与 TensorFlow，谁是一哥？

来自转载 映翡量化 2023-11-24 22:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484103&idx=1&sn=c5ae834cf039dfe795e20b90e56281de&chksm=9e1c65f4b545286546a10662500f64d109721cdb5d26944bd52e5c3cc16d1248a2769d4679d7#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484103&idx=1&sn=c5ae834cf039dfe795e20b90e56281de&chksm=9e1c65f4b545286546a10662500f64d109721cdb5d26944bd52e5c3cc16d1248a2769d4679d7#rd)

![](assets/001.png)

深度学习框架是人工神经网络 (ANN) 开发的重要工具，并且其发展非常迅速。其中，TensorFlow 和 PyTorch 脱颖而出，各自在不同的机器学习领域占有一席之地。

**你用PyTorch还是用TensorFlow？**

对于不同人群可能有不同的答案，科研人员可能更偏爱PyTorch，因其简单易用，能够快速验证idea来抢占先机发论文。

**推荐一本好资料《动手学深度学习》，好多代码复制就可用。https://zh-v2.d2l.ai/d2l-zh-pytorch.pdf**

虽然TensorFlow的差评如海，甚至有用户专门注册一个GitHub账号开个issue来骂TensorFlow，但TensorFlow在工业界大哥的地位PyTorch仍然无法撼动。

![](assets/002.jpg)

  

所以，你决定用PyTorch还是TensorFlow？

# 起源

TensorFlow：诞生于 Google Brain ，TensorFlow 从专有工具转变为开源奇迹。作为一个端到端平台，它提供从基本算术运算到神经网络部署的一切。其适应性体现在与CPU、GPU、TPU、移动设备等平台的兼容性上。值得注意的是，Google 、Uber 和微软等行业巨头已将 TensorFlow 集成到他们的运营中。

PyTorch：PyTorch 于 2016 年推出，通过将用户友好性与高性能相结合而引起了共鸣。其 Pythonic 设计方法和动态计算图使其成为研究社区的首选。它主要用 C++ 开发，效率高，并且在 Tesla Autopilot 和 Uber 's Pyro 等平台证明了其功能。

# 优势

TensorFlow 的优势：

-   丰富的生态系统：其全面的库和工具使 TensorFlow 成为机器学习任务的整体解决方案。
    
-   多功能性：它的兼容性扩展到各种语言，包括 C++、JavaScript 和 Python。
    
-   TensorBoard：一种直观的工具，提供可视化功能，可简化神经网络检查和调试。
    
    ![](assets/003.png)
    

PyTorch 的优势：

-   以用户为中心：它以 Python 为中心的性质确保了与 Python 代码的无缝集成，这使其对数据科学家极具吸引力。
    
-   动态计算图：PyTorch 对动态计算图的支持允许对模型进行实时调整。
    
-   轻松的多 GPU 支持：使用 PyTorch，数据并行性和计算任务的分配并不复杂。
    

# 流行趋势：PyTorch 与 TensorFlow

![](assets/004.png)

Google 趋势：Tensorflow 与 Pytorch — 过去 5 年

一段时间内 PyTorch 和 TensorFlow 之间流行度的动态变化可以与这些框架领域的重大事件和里程碑联系起来：

-   TensorFlow 的初始受欢迎程度：在我们时间线的早期阶段，TensorFlow 在受欢迎程度方面具有明显的优势。这可以归功于谷歌的大力支持及其广泛的工具，可以满足初学者和专业人士的需求。
    
-   PyTorch 的崛起：展望未来，PyTorch 开始获得动力。许多人发现它的方法对于研究和实验来说更加灵活，在吸引注意力方面发挥了作用。此外，随着 PyTorch 获得更多资源和支持，其用户群也在增长。
    
-   最近的情况：PyTorch 和 TensorFlow 都已经在机器学习领域占据了自己的角色。对于那些寻求大规模部署和行业解决方案的人来说，TensorFlow 仍然是一个不错的选择。PyTorch 因其强调灵活性而受到许多人的欢迎，特别是在研究领域。
    

# 考虑局限性

TensorFlow 的挑战：

-   复杂性：虽然多功能性是一种优势，但它可能会带来一些复杂性，这可能会让一些人望而生畏。
    
-   刚性：一旦设置了计算图，进行更改并不简单。
    
-   有限的初始 GPU 语言支持：早期的 TensorFlow 版本有 GPU 和语言限制。
    

PyTorch 的挑战：

-   生产过渡：虽然 PyTorch 在研究方面表现出色，但过渡到全面生产有时需要额外的步骤。
    
-   可视化：PyTorch 开箱即用的可视化能力与 TensorBoard 的可视化能力不太匹配。
    

# 深入探讨：静态与动态计算图

TensorFlow 和 PyTorch 之间的根本区别在于它们的计算图方法。TensorFlow 采用静态计算图，而 PyTorch 提倡动态计算图。

# TensorFlow：拥抱急切执行

随着 TensorFlow 2.x 的出现，该框架从静态图范式转变为急切执行，这允许操作在被调用时立即执行。这一转变使 TensorFlow 更加直观和用户友好，使其可用性与 PyTorch 更加紧密地结合在一起。`tf.function`然而，当优化和性能至关重要时，TensorFlow 仍然保留通过装饰器创建静态图的能力。

以下是在 TensorFlow 2.x 中执行简单求和运算的方法：

import tensorflow as tf   
  
\# 输入数据  
a = tf.constant( 1.0 )   
b = tf.constant( 2.0 )   
  
\# 执行操作  
sum\_ab = a + b   
print (sum\_ab.numpy())

PyTorch（动态计算图）：

使用 PyTorch，操作在编写时执行，并且图形是动态构建的。

import torch   
  
\# 立即执行操作  
a = torch.tensor( 1.0 )   
b = torch.tensor( 2.0 )   
sum\_ab = a + b   
  
print (sum\_ab)

虽然 TensorFlow 的静态方法可以在图编译期间进行优化，但它可能不太直观，特别是对于那些刚接触深度学习的人来说。相反，PyTorch 的动态特性更加灵活，特别有利于研究。

# 部署与集成

在考虑部署时，尤其是在生产环境中，框架与各种平台的兼容性和易于集成变得至关重要。

TensorFlow：

-   TensorFlow Serving：专为生产就绪部署而设计。它支持多种模型和版本控制，确保无缝过渡和回滚。
    
-   TensorFlow Lite：专为移动和嵌入式设备量身定制，允许在资源有限的边缘设备上进行机器学习。
    
-   云集成：作为 Google 产品，TensorFlow 与 Google Cloud 高效集成，提供可扩展的训练和部署等优势。
    

PyTorch：

-   TorchServe：TorchServe 是一个相对较新的补充，提供了一种大规模部署 PyTorch 模型的简单方法。它无缝处理版本控制和日志记录等任务。
    
-   ONNX 兼容性：PyTorch 模型可以导出为 ONNX（开放神经网络交换）格式，这确保了深度学习框架之间的互操作性以及在各种平台上更轻松的部署。
    
-   本机移动支持：PyTorch 提供本机库来支持 Android 和 iOS，从而简化了移动设备上的部署过程。
    

# 社区支持和文档

框架的增长、适应性和可持续性通常反映了其社区的活力。

 TensorFlow：：

-   庞大的社区：TensorFlow 存在的时间较长，并且已经建立了一个庞大的社区。在论坛或 Stack Overflow 上找到常见（和不常见）问题的解决方案的可能性更高。
    
-   全面的文档：TensorFlow 的文档内容丰富，为各种任务和级别提供教程、指南和最佳实践。
    

PyTorch：

-   快速增长的社区：虽然较新，PyTorch 的社区正在快速增长，尤其是在学术和研究领域。
    
-   用户友好的文档：PyTorch 的文档清晰简洁，经常因其简单性和易于理解而受到称赞，特别是对于初学者来说。
    

# 未来趋势与发展

密切关注每个框架的发展方向可以深入了解它们的寿命和相关性。

 TensorFlow：

-   对 TF 2.x 的投资：随着 TensorFlow 2.x 的发布，借用了其他框架的一些最佳功能，明显推动了使 TensorFlow 更加用户友好和直观。
    
-   不断发展的生态系统：借助 TensorFlow.js（用于基于浏览器的应用程序）和 TensorFlow Hub（用于可重用模型组件）等工具，TensorFlow 生态系统不断扩展。
    

**PyTorch**：

-   研究到生产：借助 TorchScript 和 TorchServe 等工具，PyTorch 正在弥合研究和生产之间的差距，确保模型可以无缝过渡。
    
-   扩展库：TorchText、TorchVision 和 TorchAudio 等库正在不断开发，为从 NLP 到计算机视觉的一系列应用提供预训练的模型和数据集。
    

# 做出明智的选择

在 TensorFlow 和 PyTorch 之间进行选择并不是要选择“最佳”框架，而是要找到最符合您需求的框架。这两个框架都具有独特的优势，并且在解决其最初的局限性方面取得了重大进展。通过评估您的项目需求、您对 Python 的熟悉程度、可扩展性的需求、部署偏好以及您正在寻求的社区支持类型，您可以做出确保效率和生产力的选择。随着深度学习世界的不断发展，这些框架也会不断发展，保持更新将使您能够一次又一次地做出明智的决策。

  

原文来源：https://medium.com/@kaveh.kamali/pytorch-vs-tensorflow-the-battle-of-machine-learning-frameworks-908cc301f795

参考资料：http://www.yitb.com/article-9249