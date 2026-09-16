# Rl如人生（3），遥远的偶像不如近距离的榜样

锤哥 QuantSeek 2023-06-20 21:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484001&idx=1&sn=c36a5d4eb8e0001dec4a3c6c683fb97f&chksm=cefc7e2426e05bc070b7120c0cdb8e56d0972531dcb64b56114df7e890303f095e8fac914b0b#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484001&idx=1&sn=c36a5d4eb8e0001dec4a3c6c683fb97f&chksm=cefc7e2426e05bc070b7120c0cdb8e56d0972531dcb64b56114df7e890303f095e8fac914b0b#rd)

这是Rl如人生第三篇，这个系列旨在用轻松的方式讲解一些Rl的知识, 欢迎听我瞎扯淡。

第一篇：[Rl如人生，我们都需要过程正反馈](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483875&idx=1&sn=e5f49519804ceee4bdb2364b711b48fb&chksm=cf7d0e85f80a8793eb268df3cb07d354d6eee8e43b3b77e0bfc301bb8d8c3692052e6b167e91&scene=21#wechat_redirect)

第二篇：[Rl如人生（2），错止于未然](http://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483886&idx=1&sn=ede40447ae294e3ccf2f81d5cc746ff9&chksm=cf7d0e88f80a879e055d8555614c8e198ab63419c99d9df384e92add07990f58372ed2ee7548&scene=21#wechat_redirect)  

  

![](assets/001.png)

  

教育小孩的时候，如果你跟他讲何凯明的故事，让他（她）努力考上清华，孩子大概率会左耳进右耳出，因为太遥远了，以至于完全无法产生共鸣。但如果孩子身边有一个（稍）年长的榜样（比如亲戚的孩子），品学兼优，看得见摸得着，那这位榜样对孩子的影响是深远的。  

  

![](assets/001.png)

强化学习里，也有类似的现象。Proximal Policy Optimization，简称PPO，即近端策略优化，是一个很流行的算法（训练了Dota2的AI），其预测目标可以简化为：  

![](assets/002.png)

  

上面的A是成这一轮训练的得分/相对优势，大家可以理解成你的孩子要学习的榜样的表现。而左边的分数是旧参数和新参数的预测概率的比值（设定为r），其实衡量了新旧参数之间的差距，大家可以理解成你的孩子和榜样之间的距离。

  

真正的优化目标是下面这个：

![](assets/003.png)

这个式子对榜样的表现进行了clip\*截断），当孩子和榜样之间的距离很遥远（即r很小或者很大），那么都会被截断，**不**让它学习太多，因为这时候学习太多是没意义的，孩子（模型）没法产生共鸣。

  

当然了从更专业地角度看，这个系数r是importance sample的产物，为了使得算法变成off-policy，研究者用旧参数去采样，得到的数据去训练参数（可以理解成拿别人去教育孩子），而当新旧参数差距太大时，采样的误差会急剧放大，这样得到的数据拿来训练适得其反，因此要进行截断。

![](assets/001.png)

RL和人生何其相似，以至于我有时候会混淆到底是谁学习谁。

  

关注锤哥，关注AI。还望各位不吝转发，谢谢。

![](assets/004.png)