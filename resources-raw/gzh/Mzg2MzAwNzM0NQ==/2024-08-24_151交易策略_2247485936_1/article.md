# 151交易策略

QuantML QuantML 2024-08-24 16:46 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485936&idx=1&sn=da36ea5bf5c038d5ca700144d59055ff&chksm=cff469745a58422cb42eaff8e815fd963f63dba0135efc2486965c33361a281eb2ddd312427a#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485936&idx=1&sn=da36ea5bf5c038d5ca700144d59055ff&chksm=cff469745a58422cb42eaff8e815fd963f63dba0135efc2486965c33361a281eb2ddd312427a#rd)

[J.P.Morgan的python教程](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485441&idx=1&sn=6cbe52b7a69ff2047e296fe5ad8e7240&chksm=ce7e6f1ff909e609dca29aac9f3fa297f65bf1336cbd670fe688e98524c5b95c95733ee3fdbe&scene=21#wechat_redirect)

Content

  

#QuantML-Newbie 项目分享，这个系列是我们面向入门者的免费资源分享项目，提供一系列公开量化学习资料。如果你有推荐的项目，也欢迎推荐给我们，我们会在后续的文章中分享给大家。  
之前几期的分享包括：

-   [高级期权交易全指南](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485813&idx=1&sn=a0f7fb2773029d573c9106b4d8d25e02&chksm=ce7e6e6bf909e77db32b224e8144cb9fe0dd89ef07e5d0c04d54975cc2eb46ee9b2ca154ffdc&scene=21#wechat_redirect)
    
-   [强烈推荐！AI for Trading](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485600&idx=1&sn=80abc69c9a32adee1cda5fcac40148a5&chksm=ce7e6fbef909e6a8d71fcdd48f75c2394894dabe8eb047213a8e41be8f0c82f90c4ad8c22d95&scene=21#wechat_redirect)
    
-   [J.P.Morgan的python教程](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485441&idx=1&sn=6cbe52b7a69ff2047e296fe5ad8e7240&chksm=ce7e6f1ff909e609dca29aac9f3fa297f65bf1336cbd670fe688e98524c5b95c95733ee3fdbe&scene=21#wechat_redirect)  
    
-   [量化交易全攻略：从入门到精通的终极指南](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&chksm=ce7e60e4f909e9f2621971c60567938c886adcc2f0b37d5c61a0263bf7c1ef4fd2d749b54bc5&scene=21#wechat_redirect)  
    
-   [MIT量化课程：Analytics Of Finance](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484744&idx=1&sn=6fd90a99c2d58436cfe40e5001b31f04&chksm=ce7e6256f909eb40052c622c6886505c2a9e8204e833b2280852766fec40b629de792f007a16&scene=21#wechat_redirect)  
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)  
    

  
本期推荐：151 Trading Strategies作者：Z. Kakushadze and J.A. Serur. 地址：https://papers.ssrn.com/sol3/papers.cfm?abstract\_id=3247865  
  

这篇论文由Zura Kakushadze和Juan Andrés Serur撰写，提供了超过150种交易策略的详细描述，涉及多种资产类别和交易风格。这些策略覆盖了股票、期权、固定收益、期货、ETFs、指数、商品、外汇、可转换债券、结构化产品、波动率（作为一种资产类别）、房地产、困境资产、现金、加密货币等。

论文中的每个策略都包括了数学公式，并且总共提供了超过550个数学公式。此外，该论文还包含大约2000个参考文献和超过900个词汇表条目、缩写和数学定义。

![](assets/001.png)

  

  

![](assets/002.png)

![](assets/003.png)

  

  

**QuantML星球内有各类丰富的量化资源。目前人数不断增长，欢迎加入交流，加星球请扫我，某书购买加入有优惠活动：**

![](assets/004.jpg)

  

  

**入群交流请扫我：**

![](assets/005.jpg)

  

  

**点击蓝字**

![](assets/006.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/007.jpg)