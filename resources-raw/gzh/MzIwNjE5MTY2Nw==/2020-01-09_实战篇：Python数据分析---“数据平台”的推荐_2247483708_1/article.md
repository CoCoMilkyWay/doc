# 实战篇：Python数据分析---“数据平台”的推荐

小莫 摸鱼量化 2020-01-09 13:09

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzIwNjE5MTY2Nw==&mid=2247483708&idx=1&sn=1e3c85ef2675b9118daf1676a6b6df0d&chksm=96fc3352b73a4bb63d944d76fa359e2d614c307b4aaf8e2790754bb048193fb26169b9d0f176#rd](https://mp.weixin.qq.com/s?__biz=MzIwNjE5MTY2Nw==&mid=2247483708&idx=1&sn=1e3c85ef2675b9118daf1676a6b6df0d&chksm=96fc3352b73a4bb63d944d76fa359e2d614c307b4aaf8e2790754bb048193fb26169b9d0f176#rd)

上一篇同伙伴们分享[Python爬虫的特点模式和实战源代码（点击获取）](http://mp.weixin.qq.com/s?__biz=MzIwNjE5MTY2Nw==&mid=2247483697&idx=1&sn=9fdeff116ab7af6d524aef9b50b97e95&chksm=97242c6da053a57b48ca71b6c21511fbf8aaa2b14f9a96dbfc6949d2e197b327fb3fc723955a&scene=21#wechat_redirect)，爬虫是我们获取网络数据的途径之一，在本文结尾，我分享了更多类型的爬虫源代码，请伙伴们惠存，可解决各类网站的数据爬取需要。对于做金融量化交易的伙伴来说，爬虫在舆情领域应用也越来越广泛，结合机器学习、文本分析等近年来越来越热门的方法，作为舆情因子参与选股和降噪，实际开发效果和未来应用潜力十分可观。

![](assets/001.jpg)

今天和伙伴分享Python金融数据挖掘的另一种方式，通过在线数据库，获取我们所需的金融数据，首先介绍一款**免费的、开源的**python财经数据接口包Tushare，Tushare主要实现对股票等金融数据从**数据采集**、**清洗加工** 到 **数据存储**的过程，能够为金融分析人员提供快速、整洁和多样的便于分析的数据，在数据获取方面极大地减轻工作量，从而更加专注于策略和模型的研究与实现上。

考虑到Python pandas包在金融量化分析中体现出的优势，Tushare返回的绝大部分的数据格式都是pandas DataFrame类型（_下一节我们将重点介绍pandas模块的功能讲解，按照数据提取-数据预处理-数据分析的流程逐步展开_），从Tushare下载的数据非常便于用pandas/NumPy/Matplotlib进行数据分析和可视化。

当然，如果有的小伙伴习惯了用Excel或者关系型数据库做分析，您也可以通过Tushare的数据存储功能，将数据全部保存到本地后进行分析。目前，Tushare同时兼容Python 2.x和Python 3.x，对部分代码进行了重构，并优化了一些算法，确保数据获取的高效和稳定。

![](assets/002.jpg)

  

-   **Tushare模块的使用情况：**  
    

使用前提是安装Python IDLE，本人建议安装Anaconda（http://www.continuum.io/downloads），一次安装包括了Python环境和全部依赖包，减少问题出现的几率。

-   **Tushare下载安装的方法：**
    

-   _方式1：_pip install tushare
    
-   _方式2：_
    

      访问https://pypi.python.org/pypi/Tushare/下载安装

-   **Tushare调用方法：**
    

`import tushare``print(tushare.__version__)`

#查看当前Tushare版本，可通过pip install tushare –upgrade升级  

  

以下是使用Tushare进行数据提取和预处理的实战源代码，编程环境是Anaconda：

`import numpy as np``import pandas as pd``%matplotlib inline``import matplotlib.pyplot as plt``import seaborn as sns``import tushare as ts``import warnings;warnings.simplefilter('ignore')`

#忽略可能会出现的警告信息，警告并不是错误，可以忽略；  

`hs300 = ts.get_k_data('hs300',start='2015-01-01', end = '2020-1-8')`

  

#Tushare调取沪深300数据

`hs300.set_index('date', inplace = True)`

 #将data日期设定为index索引值，在原表操作

`hs300.head()`

 #显示表格的前五行  

![](assets/003.jpg)

执行以上代码，就完成了沪深300数据的调取，时间段的选择，将data日期设定为index索引值，可以看到，数据的开盘价、收盘价、最高价、最低价和交易量指标都提取完成，还可以进行分钟级，秒级的数据调取，做到快捷高效。

因为调取的数据是pandas下的DataFrame格式，可以直接通过pandas模块方法进行画图，下图所示：

  

![](assets/004.jpg)

![](assets/005.jpg)

  

增加收益列，展示沪深300的每日收益率表现，可以清晰看到波动率聚集现象，详细的分析欢迎关注我们的后续课程，淘宝店铺--**金融IT教育资料库**。

**小莫良心推荐：**小莫自学最新课程【量化金融分析师培训课程AQF考试量化交易投资视频机器学习数据挖】下方有店铺链接，欢迎随时在公众号和淘宝店铺内交流，我们会提供市场最新的学习资料，不断更新丰富和整理的视频课程和练习资料，并全程答疑，无拼凑篡改，建议大家在找到科学完整的网课的前提下再探索出适合自己的学习方法，感谢各位小伙伴的支持。

小莫系统性学习资料，请扫下方二维码！

![](assets/006.jpg)

![](assets/007.png)

 或 长按复制下面的淘口令，手机打开淘宝 ！

【金融IT教育资料库】：￥9ijB1c9pDOX￥后打开淘宝

**入门到精通全套学习视频+资料：只需116（全程答疑）**

-   **精品课程：**【量化金融分析师培训课程AQF考试量化交易投资视频机器学习数据挖】
    

复制涂黄链接：€DLfs1c9Xws8€后打开淘宝

【数据分析机器学习网络爬虫人工智能新闻舆情挖掘视频课程推荐】：

复制涂黄链接：¢uFec1c9pNw0¢后打开淘宝

**现购买Python或量化全套学习视频，****免费赠送：最新版Python数据分析**

长按图片关注小莫  

![](assets/006.jpg)

![](assets/008.jpg)

**欢迎各位想学习Python和量化的朋友**  

  

**踊跃在文末点赞及留言**

  

**我将不定期选取**

  

**留言最精彩者**

  

**免费赠送一本Python书**

  

  

  

 **重温经典**（点击标题即可观看）：

[Python实战篇：开启“数据挖掘”——有道爬虫](http://mp.weixin.qq.com/s?__biz=MzIwNjE5MTY2Nw==&mid=2247483697&idx=1&sn=9fdeff116ab7af6d524aef9b50b97e95&chksm=97242c6da053a57b48ca71b6c21511fbf8aaa2b14f9a96dbfc6949d2e197b327fb3fc723955a&scene=21#wechat_redirect)  

[Python爬虫起步篇---掌握“铁三角”](http://mp.weixin.qq.com/s?__biz=MzIwNjE5MTY2Nw==&mid=2247483689&idx=1&sn=1a7849b602ac930619b2b88e35918d38&chksm=97242c75a053a563699a79d434039b5e118cf193e2140f6884b32132e75a96ad2573ef9c9b2f&scene=21#wechat_redirect)  

[欢迎大家来小莫的微信公众号作客！](http://mp.weixin.qq.com/s?__biz=MzIwNjE5MTY2Nw==&mid=2247483682&idx=1&sn=6481f22a0f2d7212172bb0de48357351&chksm=97242c7ea053a568aab818c51a07b8eb7b6c9a5033e8c978acc06202ae89a930fbe26a2a3e3f&scene=21#wechat_redirect)