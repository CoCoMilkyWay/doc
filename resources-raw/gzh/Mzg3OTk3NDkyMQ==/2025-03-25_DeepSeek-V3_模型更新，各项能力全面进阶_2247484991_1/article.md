# DeepSeek-V3 模型更新，各项能力全面进阶

深度求索 QuantSeek 2025-03-25 23:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484991&idx=1&sn=4293a3f6cb6f6e1d5422ca225054b161&chksm=ce20e2c129c457d91813a08376830fc08c2f801f6ae21542c457b36f30c024e17f23d5f03c1c#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484991&idx=1&sn=4293a3f6cb6f6e1d5422ca225054b161&chksm=ce20e2c129c457d91813a08376830fc08c2f801f6ae21542c457b36f30c024e17f23d5f03c1c#rd)

DeepSeek V3 模型已完成小版本升级，目前版本号 DeepSeek-V3-0324，用户登录官方网页、APP、小程序进入对话界面后，**关闭深度思考**即可体验。API 接口和使用方式保持不变。

如非复杂推理任务，建议使用新版本 V3 模型，即刻享受速度更加流畅、效果全面提升的对话体验。

## **模型能力提升一览**

**推理****任务表现提高**

新版 V3 模型借鉴 DeepSeek-R1 模型训练过程中所使用的强化学习技术，大幅提高了在推理类任务上的表现水平，在数学、代码类相关评测集上取得了超过 GPT-4.5 的得分成绩。

![](assets/001.png)

新版 V3 模型的百科知识（MMLU-Pro, GPQA）、数学（MATH-500, AIME 2024）和代码任务（LiveCodeBench）表现均有提升

**前端开发能力****增强**

在 HTML 等代码前端任务上，新版 V3 模型生成的代码可用性更高，视觉效果也更加美观、富有设计感。

![](assets/002.gif)

动图展示了一个由模型生成的演示多个小球在指定空间范围内运动的 p5.js 程序，包含若干可以调整重力、摩擦力等参数的滑动按钮，并以赛博朋克风格的 HTML 呈现

**中文写作升级**

在中文写作任务方面，新版 V3 模型基于 R1 的写作水平进行了进一步优化，同时特别提升了中长篇文本创作的内容质量。

![](assets/003.jpg)

  

![图片](assets/004.png)

  

  

上下滑动查看完整内容

**中文搜索能力优化**

新版 V3 模型可以在联网搜索场景下，对于报告生成类指令输出内容更为详实准确、排版更加清晰美观的结果。

  

![图片](assets/005.jpg)

  

  

上下滑动查看完整内容

此外，新版 V3 模型在**工具调用、角色扮演、****问答****闲聊**等方面也得到了一定幅度的能力提升。

![](assets/006.png)

## **模型开源**

DeepSeek-V3-0324 与之前的 DeepSeek-V3 使用同样的 base 模型，仅改进了后训练方法。私有化部署时只需要更新 checkpoint 和 tokenizer\_config.json（tool calls 相关变动）。模型参数约 660B，开源版本上下文长度为 128K（网页端、App 和 API 提供 64K 上下文）。V3-0324 模型权重下载请参考： 

  

**Model Scope:** 

**https://modelscope.cn/models/deepseek-ai/DeepSeek-V3-0324**

**Huggingface:** 

**https://huggingface.co/deepseek-ai/DeepSeek-V3-0324**

  

与 DeepSeek-R1 保持一致，此次我们的开源仓库（包括模型权重）**统一采用 MIT License**，并允许用户利用模型输出、通过模型蒸馏等方式训练其他模型。

![](assets/007.jpg)