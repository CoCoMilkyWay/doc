# RD-Agent Windows安装教程

QuantML QuantML 2024-09-23 18:30 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247486408&idx=1&sn=37c166b86060e575614f49bc5bc54de5&chksm=cfbefed28982a273fd0896d7ad735af04f63e8df4c7f05abd2a80f12d68264ecf096776bd721#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486408&idx=1&sn=37c166b86060e575614f49bc5bc54de5&chksm=cfbefed28982a273fd0896d7ad735af04f63e8df4c7f05abd2a80f12d68264ecf096776bd721#rd)

Content

RD-Agent 是微软亚洲研究院推出的一款自动化研究与开发工具，能够通过LLMs自动构建因子和策略，相关介绍见我们之前的文章：[RD-Agent ：自动化Quant工厂](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486294&idx=1&sn=957c38f1319930cf89bbc170baeb6065&chksm=ce7e6c48f909e55e4732ab28d0c11a4cecdff98d5397261b79dc3f527bc445af2c433031de29&scene=21#wechat_redirect)

  

然而，在安装RD-Agent时会遇到各种问题，尤其是目前官方还不支持win和macOS系统，本文介绍如何在win下安装RD-Agent。

  

首先官方github下载代码：

```
git clone https://github.com/microsoft/RD-Agent.git
```

  

创建新环境，安装所需的依赖：

```
conda create -n rdagent python=3.10
```

  

运行需要OPENAI API，可以使用官方API，没有的话也可以使用各种中转API，创建.env 文件：

```
cat << EOF  > .env
```

  

RD-Agent也支持本地的llama模型，可以自行在hf下载权重文件。目前还不支持其他LLMs的API， 等后面有时间我们再增加对于其他大模型的支持。

接下来如果直接运行官方代码的话会遇到各种报错，主要是docker安装时的网络问题以及程序并行的问题。所以在运行之前，首先从星球获取修改后的Dockerfile，替换官方的rdagent\\scenarios\\qlib\\docker\\Dockerfile，接下来就可使用rd-agent自动搭建模型。

使用命令：

```
rdagent fin_model
```

LLMs即可自动思考，生成qlib格式的模型代码，自动运行，且不断改进模型。  

输出结果：  

![](assets/001.png)

这是运行两轮的结果，可以看到，通过LLMs构建的模型能够自动适配qlib并且输出结果，而且随着轮数增加，模型效果也会不断提升。也可以自己修改prompt 构造模型。  

其他功能还在不断探索当中，欢迎加入星球交流。

  

  

**QuantML星球内有各类丰富的量化资源，星球群内有许多大佬，欢迎加入交流，星球人数已经500+，为了感谢支持，近期星球会在保持原价的同时继续赠送优惠券，加星球请扫我：**

![](assets/002.png)

  

  

**入群交流请扫我：**

![](assets/003.webp)

  

  

**点击蓝字**

![](assets/004.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

![](assets/005.webp)