# 全A日线数据全自动落盘程序

锤哥 QuantSeek 2023-10-16 22:21 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484218&idx=1&sn=32250218cb1aa71060306cc78ca116c5&chksm=ce7b1185b6ad32740e4c1372c19f0dfd80ee6fea23fda1d3b1cd6263729dc19edb15fa0715bc#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484218&idx=1&sn=32250218cb1aa71060306cc78ca116c5&chksm=ce7b1185b6ad32740e4c1372c19f0dfd80ee6fea23fda1d3b1cd6263729dc19edb15fa0715bc#rd)

今天带来研究基础篇:数据库。做任何长时间的研究，都需要搭建好基础设施，好的基础设施可以令研究事半功倍，有了基础数据，才方便运用类似[告别低速！如何以极高的速度进行多空回测](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484207&idx=1&sn=cf2dcfd9537c7c17701346455dd7fb1f&chksm=cf7d0c49f80a855f0d5dc71427240bd31751779fb56d2d43027d1efc3ef9efe101c4dab17be8&scene=21#wechat_redirect)这些回测函数。  

  

第一步大概就是数据库了，今天的文章提供了一个利用tushare自动落盘a股日线数据的代码，关于数据库的落盘模块，大致有下面一些**基础的**要求:

  

1、按需增长，不要急着什么都塞进去。

2、可靠性，错误处理。

3、不错的读取速度，方便做研究。

4、索引设置完备。

5、更新方便，自动避免重复数据，一键更新。

  

这次给读者带来了一个简易的更新程序，更新的是A股的日线行情，数据来源是tushare网站（https://tushare.pro/document/2?doc\_id=27），这个我在群里也跟群友们说过，这个数据源比较经济实惠，推荐使用。

  

![](assets/001.png)

  

对程序的一些说明：  

  

1、这是不复权，不复权，不复权数据，所以是不能直接用来做量化的，理论上我们需要后复权行情，这个demo只是提供一个落盘数据的流程，具体需要什么数据，可以自己修改。

  

2、需要改动的地方

2.1 private.py，里面的token和Sql数据库的参数都需要改。

2.2 AShareEODPrices.bat 里面的路径，改成 AShareEODPrices.bat 所在的路径。AShareEODPrices\_history.bat同理。

2.3 AShareEODPrices.py 这是主要用到的代码，下面2个参数可改可不改

```
databasename = 'asharestockdata'   # 数据库名
```

  

3、初次运行：  

双击AShareEODPrices\_history.bat ，获取20100101至20230930历史数据。

  

4、日度更新

每晚或者第二天双击AShareEODPrices.bat 即可，自动获取需要更新的交易日，无需指明交易日，不会产生重复插入的现象，建议可以用任务计划程序自动化这个步骤。

  

其它：  

关于sql数据的可视化，可以下载个可视化的软件，方便查看数据。

  

  

**获取方式**

**1、[星球](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484111&idx=1&sn=12b748eeb02b84159342cbf12fd73ba6&chksm=cf7d0da9f80a84bfe2bd90dbf6645f08e81dc71587096002ed9c74bfb18a200042e23a37b025&scene=21#wechat_redirect)用户直接获取。**

**2、转发本文章至朋友圈，保留半小时后截图后台发送给我。**