# 量化接口：通过QMT的xquant接口获取股票行情数据

fintechhaibin FinTechHi 2026-02-10 22:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489418&idx=1&sn=7a8026c5096f50718a3732e306121efc&chksm=fbd2cb63fd02b92b66ef64eb7b3b85ffb97ca7b8514cb41b7b5d1d32b9ed5a7abaecb7ee9a52#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489418&idx=1&sn=7a8026c5096f50718a3732e306121efc&chksm=fbd2cb63fd02b92b66ef64eb7b3b85ffb97ca7b8514cb41b7b5d1d32b9ed5a7abaecb7ee9a52#rd)

很多时候看起来非常简单的软件安装或者代码，实际动手起来总是会因为各种各样的问题运行不起来。

最近akshare接口获取数据总是报错。就想着通过QMT来拉数据看看。

记录下步骤。

一.基本准备

①联系开户的证券公司开通账户，再申请下开通QMT交易权限，会在电子邮箱收到下载地址。下载并安全qmt软件。

②然后点：我的->下载Python库，弹出系统设置界面，点击python库下载。 

![](assets/001.png)

  

③下载完成后找到 QMT文件安装目录下/bin.x64/lib/site-packags//xtquant 

④复制xtquant文件到本地python环境下的//site-packags文件夹（如果没有安装Python需要先安装）

二.接口学习

参考官方文档：

https://dict.thinktrader.net/nativeApi/start\_now.html

其中最关键的有两个接口。

**Xtdata** 作为行情模块，本模块旨在提供精简直接的数据满足量化交易者的数据需求，主要提供行情数据（历史和实时的K线和分笔）、财务数据、合约基础信息、板块和行业分类信息等通用的行情数据。

**Xttrader** 作为交易模块，封装了策略交易所需要的 Python API 接口，可以和 MiniQMT 客户端交互进行报单、撤单、查询资产、查询委托、查询成交、查询持仓以及接收资金、委托、成交和持仓等变动的主推消息。

三.基础数据接口测试

登录QMT，勾选：独立交易 复选框。同步所有股票的日行情数据并保存为csv文件代码，其中需要注意，需要使用两个函数，先使用download\_history\_data

把数据先下载到本地，格式是QMT自己的格式，然后通过get\_local\_data函数读取数据保存为自己的格式，如csv。

  

```
import os
```

保存到本地的数据结果：

![](assets/002.png)

  

跑通了一个接口后，就可以带着喜悦的心情按接口说明并结合AI，一个个测试其他接口了。比如：

-   获取交易日历
    
-   获取股票基本信息
    
-   获取板块信息及版本成分股
    
-   获取指数及成分股
    
-   获取财务数据
    

  

四.实时行情接口

QMT默认提供的只有level1行情，level2行情需要申请权限。