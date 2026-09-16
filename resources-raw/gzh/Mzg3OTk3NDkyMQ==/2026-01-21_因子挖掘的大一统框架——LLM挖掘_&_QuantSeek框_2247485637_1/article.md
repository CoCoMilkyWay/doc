# 因子挖掘的大一统框架——LLM挖掘 &amp; QuantSeek框架6.0

QuantSeek QuantSeek 2026-01-21 08:13 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485637&idx=1&sn=6b5fe04e57a3a06be6c8dca4acb7b573&chksm=ce682ea56ddae452bedbc7646ff7e0fd570469b8e07eebbcb481242d6d4400491f8cd90d1414#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485637&idx=1&sn=6b5fe04e57a3a06be6c8dca4acb7b573&chksm=ce682ea56ddae452bedbc7646ff7e0fd570469b8e07eebbcb481242d6d4400491f8cd90d1414#rd)

重磅更新的前文概要：

[因子挖掘的大一统框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&scene=21#wechat_redirect)

[QuantSeek框架5.0：因子挖掘](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485282&idx=1&sn=148c23e7390e9136c100c4fad11ac777&scene=21#wechat_redirect)

这次QuantSeek框架的更新终于要把前面的坑给填了：基于大模型的因子挖掘正式嵌入到框架里面

  

一、首先说说我对LLM辅助挖掘的3个核心理解：

1、提示词很重要，否则也会陷入重复挖掘的陷阱。

2、不要尝试融合类似遗传规划那样的算子，算子看似加速或者给了llm很大的选择空间，实际是限制，得不偿失。

3、难点是如何构造prompt进行合理的引导，使得llm可以不断地修正和深入挖掘。

  

二、QuantSeek的大模型因子挖掘的特点：

1、解耦：没有什么深度的项目依赖，随意切换数据源，随意切换任何llm模型（样例以deepseek为例），仔细阅读代码理解逻辑后可以轻松进行进一步的增强（包括增添数据等）。

2、一步到位生成html报告：html记录了每一轮的挖掘结果，包括思考过程、因子评价、因子定义代码、图片和表格等。

3、因子代码直接实盘落盘：若挖掘出有效的因子，其代码可以直接使用在QuantSeek的因子生成中。

  

![](assets/001.png)

（加入星球获取QuantSeek框架代码)

[QuantSeek框架](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=Mzg3OTk3NDkyMQ==&action=getalbum&album_id=3948959972918181903#wechat_redirect)是基于python的极简投研框架，从数据落盘到因子到模型，用新手都能看懂但效率极高的写法构建的一站式投研解决方案，目前已有机构在使用。框架以大A为例。可以轻松拓展到商品、bi等资产。