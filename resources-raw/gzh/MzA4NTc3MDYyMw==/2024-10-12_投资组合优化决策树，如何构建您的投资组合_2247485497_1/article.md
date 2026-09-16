# 投资组合优化决策树，如何构建您的投资组合？

InfinityQuant 映翡量化 2024-10-12 23:49 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247485497&idx=1&sn=990bd4388571f2499ec1699f9a2016a2&chksm=9ecb08ff7dbe428f76e2dfd52d48dd646a09759cc5c2d743565a0e0d060d0612d818aadf801a#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247485497&idx=1&sn=990bd4388571f2499ec1699f9a2016a2&chksm=9ecb08ff7dbe428f76e2dfd52d48dd646a09759cc5c2d743565a0e0d060d0612d818aadf801a#rd)

如何构建您的投资组合？ 🤔  
  
您对波动性有何看法？  
对回报有积极的看法？  
相关性——你能解释它们吗？  
市场是否具有风险效率？  
市场会奖励哪种类型的风险？ 💡

  

投资组合优化决策树，可以帮助投资者为工作选择合适的优化工具。如何让股票回报与风险（β和波动性）无关，以下示例映射了最佳投资组合方法的决策路径。

  

![](assets/001.jpg)

红色箭头为确信回报与风险无关的股票投资者寻找最佳方法，并且认为他可以估计协方差-->最小方差投资组合是MV最佳。

  

绿色箭头为确信回报与风险无关的股票投资者寻找最佳方法，并且认为他只能估计波动性-->逆方差加权投资组合是MV最佳。

  

黄色箭头为确信回报与风险无关的股票投资者寻找最佳方法，他觉得自己可以估计相关性但不能估计波动性-->最大不相关性投资组合是MV最佳。  

  

蓝色箭头为确信回报与风险无关的股票投资者寻找最佳方法，他们觉得自己无法估计相关性或波动性-->同等权重的投资组合是MV最佳。

  

当然，鉴于投资者对他们可以估计什么以及风险与回报的关系的假设，优化机器可用于为任何投资领域找到最优化的分配方法，而不需要任何积极的回报视图。  

  

例如，假设区域股票和债券市场指数以及商品期货等广泛资产类别具有相等的夏普比率可能是合理的，在这种情况下，最大多样化优化是MV最佳。

  

要怎么实现还需要相当多的金融理论知识、数理模型能力、技术创新能力等。

![](assets/002.jpg)

  

  

参考资料：  

https://investresolve.com/lp/portfolio-optimization-general-framework/

https://investresolve.com/portfolio-optimization-simple-optimal-methods/

https://investresolve.com/portfolio-optimization-case-study-managed-futures/