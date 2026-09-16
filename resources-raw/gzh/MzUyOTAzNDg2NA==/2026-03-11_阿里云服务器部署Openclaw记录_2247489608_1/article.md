# 阿里云服务器部署Openclaw记录

fintechhaibin FinTechHi 2026-03-11 22:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489608&idx=1&sn=fc83e96d3d3400774339b6f5b682d610&chksm=fbf4bc5c58b5050606f5b69a6fd08233752d5a4b1f526cc1270957b4331b745449d0776587c6#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489608&idx=1&sn=fc83e96d3d3400774339b6f5b682d610&chksm=fbf4bc5c58b5050606f5b69a6fd08233752d5a4b1f526cc1270957b4331b745449d0776587c6#rd)

在Mac上本地搭建openclaw后，外网访问、远程登录都不方便。

还是控制不住好奇心，购买了云服务器，再配置下。

1.openclaw安装方案

目前有几种方案：

-   本地电脑+openclaw + codeing plan
    
-   本地电脑+openclaw + 某个在线大模型
    
-   本地电脑+openclaw +LM Studio + Qwen3-4b(本地大模型，一来硬件配置)
    
-   本地电脑+clawx(通过可视化界面安装openclaw) +codeing plan
    
-   本地电脑+
    

  

-   云服务器+操作系统（自选）+openclaw（自主安装） +codeing plan
    
-   云服务器 +操作系统（默认）+ openclaw（已默认安装）
    

  

还有一些类似的更简易的同类产品可以选择：

  

-   ArkClaw（字节）
    
-   WorkBuddy（腾讯）
    
-   KimiClaw
    
-   QClaw（腾讯，UP主秋芝，开发了同名的）
    
-   CoPaw（阿里）
    

  

每个大厂现在都是使出浑身解数来教大家怎么安装openclaw或使用技巧。

听来听去确实容易眼花缭乱，

  

对自己来说，核心点就4个：

-   在什么机器上部署
    
-   选择什么大模型token
    
-   自己动手安装openclaw，还是找一些可视化安装工具。
    
-   安装后用来跑通一个什么案例
    

  

每家提供服务的活动内容，工具其实都大差不差，选择一个自己喜欢的大厂，本着一个工具尽快跑起来，跑通实际案例体会就行。

  

2.阿里云

我选择的了阿里云服务器。

官网直接就能看到轻量应用服务器2核2G：

![](assets/001.png)

购买后看到服务器列表，点击：远程连接可以登录服务器。

![](assets/002.png)

点击：更多操作弹出菜单中选择：查看详情。

![](assets/003.png)

进入服务器详情页：

![](assets/004.png)

右上角OpenClaw 最佳实践链接有一系列文档，重点看：快速部署并使用OpenClaw，简化自动化流程以提升运维效率。-轻量应用服务器(SAS)-阿里云帮助中心

![](assets/005.png)

点击应用详情，在**OpenClaw使用步骤**区域中，单击**端口放通**下的**执行命令**，可开放获取OpenClaw服务运行端口的防火墙。

![](assets/006.png)

点击配置 2openclaw下的初始化时。

![](assets/007.png)

弹出如下阿里云百炼API key配置界面：

![](assets/008.png)

点击：订阅百炼coding plan并创建API key 的：前往。开通后默认送了额度。

![](assets/009.png)

点击密钥管理菜单，点击：创建API key按钮。

![](assets/010.png)

回到下面界面：

![](assets/008.png)

会看到刚刚创建的API key.

![](assets/011.png)

点下一步，配置成功：

![](assets/012.png)

点获取地址：

![](assets/013.png)

在弹出的对话框中会给访问openclaw主页的链接地址，粘贴到浏览器中：

果然比本地安装简单多了。

![](assets/014.png)

hello world！

![](assets/015.png)

明天配置飞书。