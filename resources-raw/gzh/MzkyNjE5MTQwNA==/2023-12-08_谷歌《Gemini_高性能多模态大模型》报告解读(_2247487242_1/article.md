# 谷歌《Gemini:高性能多模态大模型》报告解读(附pdf)

量化前沿速递 2023-12-08 12:22 北京

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487242&idx=1&sn=88ad1201b09bc9f6ff793c5a75ef8c5f&chksm=c3d7e111870dca19b2057770d8d24d91d80d1b4777a3203c8c80fc80ad2a15b795c3b81c7432#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487242&idx=1&sn=88ad1201b09bc9f6ff793c5a75ef8c5f&chksm=c3d7e111870dca19b2057770d8d24d91d80d1b4777a3203c8c80fc80ad2a15b795c3b81c7432#rd)

12月6日，谷歌官宣Gemini 1.0版本上线。多方面(MMLU、HumanEval、Big-Bench-Hard)超越GPT4。翻了下论文，列一些细节出来，获取原文pdf请在后台回复“**Gemini**"。

Gemini有Ultra、Pro、Nano三个版本，可自动生成文本、代码、总结内容等，并能理解图片、音频和视频内容。Google从12月13日起提供Gemini Pro的API。Ultra版本还在安全、功能优化中，很快会开放使用。

Gemini Pro的API地址：https://cloud.google.com/vertex-ai

![](assets/001.png)

论文里举了一些应用的例子，令人窒息的强大。总结一下就是：**极大利好截图+ctrlCV功能**

首先是一个解物理题的例子。高中物理加速度的问题。需要先识别图片获取语义，然后给出结论。

![](assets/002.png)

一个逆向生成代码的问题，这个我给跪。可能不久的以后，就会有一堆能熟练掌握截图 +ctrl CV 生成代码，再ctrlCV微调的程序员了。

![](assets/003.png)

多模态 语音+图像识别回答的功能也很强大。  

![](assets/004.png)

图像转表的功能，这个相关应用挺多了，就看精度怎么样了，感觉以后还会有一堆熟练掌握截图Ctrl CV的研究员。

![](assets/005.png)

行测功能也很强大，以后会有一堆熟练掌握截图+Ctrl CV的应届生  

![](assets/006.png)

下一个，升级版步步高点读机功能。以后就是哪里不会截哪里了。  

![](assets/007.png)

解方程  

![](assets/008.png)

查位置  

![](assets/009.png)

还有很多不展开了，六十多页，自己看吧。