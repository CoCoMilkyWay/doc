# 宏观分析师可以不用学python了——CPI分析一步到位

混饭吃不丢人 QuantSeek 2023-07-10 10:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484159&idx=1&sn=2826cd16900a368da6b6c82f2be8e2bb&chksm=ce856358bcecfbb9110793261409b5b446c42e22d6e929f90650bbdca4d9601c1cd571d2fa96#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484159&idx=1&sn=2826cd16900a368da6b6c82f2be8e2bb&chksm=ce856358bcecfbb9110793261409b5b446c42e22d6e929f90650bbdca4d9601c1cd571d2fa96#rd)

试了一下Gpt4的新特性：Code Interpreter，这个功能实在是过于强大了，可以这么说，现在办公室内一些难度中等偏下的数据分析任务，**完全可以交给机器**。

  

Code Interpreter集成了写代码和分析的功能，但它最大的特点在于：通俗地讲，它本身内置了一个python的运行器，以前我们问Gpt代码问题，它给出的代码不一定能运行，但是现在它会**不断运行直至代码成功**（下面的案例会展示这个特性）,它甚至能帮你选择预测模型最好的参数。

  

周末我找金融行业的朋友要了一份CPI数据，下面我来展示一下是如何使用这个工具来**分析我国的CPI数据**的。  

  

![](assets/001.png)

**一、使用方式**

  

Code Interpreter这个功能需要你开通Plus，以前公众号写过一篇开通Plus的教程：[Plus](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483928&idx=1&sn=1188b007ea60e957b88b4471de0ebe5e&chksm=cf7d0d7ef80a846832d57b624c1e87a89e950e40f82ff883de203bf67397903f0a602eaab840&scene=21#wechat_redirect)。

  

Plus开通后，点击左下角的账户->setting，然后勾选 Code Interpreter即可。  

![](assets/002.png)

  

使用的时候，打开新的聊天窗口，使用Gpt4，然后勾选Code Interpreter即可。  

![](assets/003.png)

  

在对话框就能显示上传数据的+号了，接下来正常聊天就可以了。

![](assets/004.png)

  

![](assets/001.png)

**CPI的分析**

  

我上传了一份2000年1月至2023年5月的CPI数据，包含2列，一列是月份，第二列是CPi。

  

因为锤哥宏观研究并不专业，只问了几个常见的问题：

![](assets/005.png)

  

前文提到，Gpt会**不断运行代码**、**改错**，直至能完全**跑通**代码，这意味着宏观分析师可以**真正意义上不会python**，原来我们去问Gpt代码问题，你还得担心它能不能跑通，自己还要去调，现在完全没有这个问题。

  

![](assets/006.png)

  

经过Gpt自己的多番调试（像极了程序员debug的过程），Gpt给出了完美的答案，看起来这个图还是像模像样的。

  

![](assets/007.png)

  

而且代码都是一键复制的，可以直接在本地运行：  

  

![](assets/008.png)

  

  

再看看它对走势的**分析**，唔，反正这是机器说的，跟锤哥无关。

  

![](assets/009.png)

  

分析完就是**预测**了，这里它使用了经典的**Arima**模型，我觉得还行，毕竟确实是常规预测手段了，这里还有一个办法锤哥还没有尝试：**可否输入更多的数据**来辅助预测，这时候Gpt会给出怎么样的预测方法呢，之后锤哥可能会测一测，欢迎关注公众号后续了解。

  

![](assets/010.png)

  

但是Arima模型熟悉的朋友都知道，需要确定几个参数，主要是AR和MA项，如果Gpt只能给出代码，那将毫无意义，但是我们惊奇地发现，Gpt能**自动判断出合适的参数并且给出理由**！！！并且Gpt根据确定的参数，对cpi进行了预测！

  

  

![](assets/011.png)

  

最后Gpt还给出了贴心的风险提示（还真是一个合格的宏观分析师）

  

![](assets/012.png)

  

![](assets/001.png)

**写在最后：**

  

Gpt这个新特性真的非常强大，很推荐各位使用，上面的这个例子已经达到了一个合格分析师的水准，这里面涉及的所有代码都是复制粘贴即可使用，大大提高了分析师的效率。

  

锤哥在星球还给出了一个股价预测的例子，感兴趣的朋友可以加入星球学习，锤哥会持续在星球输出AI、投资相关的干货。[锤哥的AI、量化投资社区](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484111&idx=1&sn=12b748eeb02b84159342cbf12fd73ba6&chksm=cf7d0da9f80a84bfe2bd90dbf6645f08e81dc71587096002ed9c74bfb18a200042e23a37b025&scene=21#wechat_redirect)