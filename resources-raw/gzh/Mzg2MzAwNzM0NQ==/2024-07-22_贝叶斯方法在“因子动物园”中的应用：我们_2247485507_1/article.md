# 贝叶斯方法在“因子动物园”中的应用：我们运行了两万亿个模型

QuantML 2024-07-22 23:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485507&idx=1&sn=85ebec629ee077060743ac73ea3657ae&chksm=cf911d2224ad7046a7fbdd6cbcce59abd23e3f00a5bbb983a977937c1e7e7cf286f3bd066254#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485507&idx=1&sn=85ebec629ee077060743ac73ea3657ae&chksm=cf911d2224ad7046a7fbdd6cbcce59abd23e3f00a5bbb983a977937c1e7e7cf286f3bd066254#rd)

《Bayesian Solutions for the Factor Zoo: We Just Ran Two Quadrillion Models》  
  
论文地址：https://papers.ssrn.com/abstract=3481736  
  
这篇论文提出了一个创新的贝叶斯框架，用于分析和解决资产定价领域中因风险因素众多而产生的“因子动物园”问题。作者们开发了一个能够处理高达两万亿个模型的贝叶斯方法，不仅适用于可交易和不可交易的风险因素，还能够在模型可能存在误设定的情况下提供稳健的风险价格估计。  
  
通过贝叶斯模型平均（BMA）技术，该框架能够自动选择最佳模型或在没有明确胜出模型的情况下进行模型平均，从而提高了资产定价的准确性和稳健性。  
  
实证分析表明，该方法构建的随机折现因子（SDF）在样本内外的定价性能均优于现有的流行模型。此外，论文还探讨了模型选择、因子选择和模型聚合的相关问题，并提出了一种新的“spike-and-slab”先验，以增强模型选择的稳健性，特别是在处理弱识别因子时。这项研究为高维资产定价问题提供了一种新的视角和解决方案。  
  
论文数据代码下载见星球。

![图1](assets/001.png)

图1