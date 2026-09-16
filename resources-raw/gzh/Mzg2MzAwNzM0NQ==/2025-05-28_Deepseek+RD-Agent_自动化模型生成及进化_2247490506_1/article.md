# Deepseek+RD-Agent 自动化模型生成及进化

QuantML编辑团队 QuantML 2025-05-28 20:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490506&idx=1&sn=6b04e6ec8c77db25b41657a2ee030c49&chksm=cfaf9c1b7d2fd83f3ea1f2457bba4aade5ba809a2a073f23e02adea65e89156f92dac6d43a69#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490506&idx=1&sn=6b04e6ec8c77db25b41657a2ee030c49&chksm=cfaf9c1b7d2fd83f3ea1f2457bba4aade5ba809a2a073f23e02adea65e89156f92dac6d43a69#rd)

RD-Agent 是一个专注于数据驱动场景的自动化研发系统，旨在简化模型和数据处理的开发流程。该系统通过结合传统软件工程与大语言模型，持续探索、实现和评估解决方案，实现科学方法的自动化。

![](assets/001.png)

RD-Agent在量化领域具有显著优势，主要体现在自动化因子发现、模型演化和研究报告处理三个核心方面。

## 自动化因子演化

RD-Agent 提供了完全自动化的因子发现和演化系统。该系统能够：

-   **持续假设生成**：基于历史实验分析和领域专业知识自动提出新的因子假设
    
-   **迭代优化**：通过反馈循环不断改进因子表现
    
-   **量化验证**：使用 Qlib 进行严格的回测验证
    

## 自动化模型演化

在模型开发方面，RD-Agent 实现了端到端的自动化流程：

-   **模型架构自动设计**：基于假设自动生成和优化模型结构
    
-   **代码自动实现**：将模型设计转换为可执行的 PyTorch 代码
    
-   **性能自动评估**：在 CSI300 数据集上进行标准化回测
    

## 研究报告自动处理

RD-Agent 独特的报告处理能力为量化研究提供了重要优势：

-   **因子自动提取**：从金融研究报告中自动识别和提取潜在交易因子
    
-   **快速实现验证**：将报告中的因子描述转换为可测试的代码
    
-   **因子库扩展**：持续丰富和完善因子库
    

## 技术架构优势

### CoSTEER 代码生成框架

RD-Agent 使用专门的 CoSTEER 框架进行代码生成，确保高质量的实现：

系统根据任务类型自动选择相应的编码器，包括特征编码器、模型编码器等专门组件。

### 知识管理和学习

框架具备强大的知识管理能力：

-   查询相似成功案例
    
-   学习历史失败经验
    
-   避免重复错误
    

  

在之前的文章我们介绍过RD-Agent及其安装方法，官方默认采用OpenAI 的API来实现各类任务。最近花了两天将其改为DeepSeek的API接口，实现自动化模型的生成。

[R&D-Agent-Quant](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490469&idx=1&sn=e4748ff2c1902ab9573e7e9a1addef57&scene=21#wechat_redirect)

[RD-Agent Windows安装教程](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486408&idx=1&sn=37c166b86060e575614f49bc5bc54de5&scene=21#wechat_redirect)

[RD-Agent ： 自动化Quant工厂](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486294&idx=1&sn=957c38f1319930cf89bbc170baeb6065&scene=21#wechat_redirect)

首先，RD-Agent团队除了提供OpenAI以及Azure的backend之外，还提供了litellm的backend,通过litellm,能够轻松将接口改为DeepSeek等其他大模型。

具体配置方法为，在环境配置文件.env中，将BACKEND改为litellm，提供模型名称以及API Key:

`BACKEND=rdagent.oai.backend.LiteLLMAPIBackend.   CHAT_MODEL=deepseek/deepseek-chat   DEEPSEEK_API_KEY=sk-***   `

当我天真的以为这就能够使用DeepSeek之后，才发现这是噩梦的开始，接下来在安装以及使用过程中，我遇到了Ubuntu源，Docker源的网络问题，embedding模型适配，json\_model支持，json格式，模型输出效果等一系列问题，所幸大部分问题都得以解决。

不得不说，RD-Agent想法是非常好的，通过集成QLIB框架，利用LLM实现模型和因子的快速猜想和验证。

但是现阶段的问题在于，LLM能力接近一个初级研究员的水平，构造的模型和因子会存在许多问题。

对于模型而言，实际交易中，中低频不太需要去构造复杂深度学习模型，通过RD-Agent构造的模型结果还好。

但是在因子生成任务上，采用代码因子生成模式存在诸多弊端，首先大模型生成的因子代码均为简单因子，加之底层日频的数据类型限制因子种类，以及qlib本身截面算子的限制，很难带来增量alpha信息。

优化方式之一可以改为表达式因子生成的方式，具体可以参考我们之前的文章：

[QuantML-Qlib Factor | DeepSeek自动因子挖掘及优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489803&idx=1&sn=e21dc052c7f55c0af0697ede5245eca4&scene=21#wechat_redirect)

在工程上，代码中频繁使用了try-cache以及retry的方式来确保LLM结果正确，但是这又带来了运行效率较低，在debug时会耗费大量的等待时间。

安装完成后，运行命令：

`rdagent fin_model   `

DeepSeek根据模板自动生成深度学习模型和config配置文件，模型会在qlib的docker中自动运行，结合模型运行的及及结果反馈，DeepSeek尝试优化模型，自动改进模型结果，流程图如下图所示。

![](assets/002.png)

生成的模型代码：

![](assets/003.png)

模型回测结果：

![](assets/004.png)

任务启动之后，接下来就是漫长的等待，模型自动总结已有信息不断迭代生成新的模型结构，期待DeepSeek帮你实现一个效果更好的模型吧！

  

  

欢迎加入星球交流，加入QuantML星球，与星主和850+专业人士一起交流学习：

![图片](assets/005.webp)