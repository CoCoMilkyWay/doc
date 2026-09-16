# Claude Code安装与配置——本土模型

QuantSeek QuantSeek 2026-03-15 22:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485769&idx=1&sn=af05fbd293566d65a6f49fd21616eca1&chksm=ce492d63ca00f1ff8565a2ec576512671bda2b197fc79c2fa00d9f1a826e199e5f2900789546#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485769&idx=1&sn=af05fbd293566d65a6f49fd21616eca1&chksm=ce492d63ca00f1ff8565a2ec576512671bda2b197fc79c2fa00d9f1a826e199e5f2900789546#rd)

最近有星球球友看了[因子挖掘的大一统框架——LLM挖掘 & QuantSeek框架6.0](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485637&idx=1&sn=6b5fe04e57a3a06be6c8dca4acb7b573&scene=21#wechat_redirect)后，跟我探讨现在很火的龙虾、Agent之类的可不可以实现类似的效果。其实事实上，QuantSeek的这套东西就是专门针对挖因子的Agent化写法。

当然更通用的Agent工具我认为还是有必要掌握的，比如Claude Code, Codex, Cursor Composer之类的。

今天这篇文章是一个基础安装配置篇，好像很多人以为Claude Code只能用Claude，国内不能使用等等，其实不是，完全可以搭配本土的任何模型，而且切换是很简单的。

![](assets/001.png)

1、首先安装git工具，claude code依赖git

https://git-scm.com/

  

2、安装node.js依赖

https://nodejs.org/zh-cn/download/

  

3、打开cmd（命令行）下载claude code

设置镜像（下载快一点）

npm config set registry http://mirrors.cloud.tencent.com/npm/

然后安装claude code

npm install -g @anthropic-ai/claude-code

  

4、基础设置

c盘搜索claude.json，打开这个txt

在~/.claude.json文件中添加以下行，

"hasCompletedOnboarding": true

否则会显示地区国家限制

  

5、安装cc switch软件，这是一个切换模型的软件，可以无痛切换，比如想用deepseek，那么打开cc switch设置api即可即可。

![](assets/002.png)

![](assets/001.png)

  

6、大功告成，打开cmd，然后输入 "claude"即可使用。

![](assets/003.png)