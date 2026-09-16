# 【机器翻译】Meta机器翻译力作NLLB

Ai 量化前沿速递 2024-03-11 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487649&idx=1&sn=f13e9913c88a2a60f3f37d4b9c7402fb&chksm=c35573aceaf757965f3c0177aeadf2dd4c5507817c220bf22b1858aec0e3ed862c9495f934f6#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487649&idx=1&sn=f13e9913c88a2a60f3f37d4b9c7402fb&chksm=c35573aceaf757965f3c0177aeadf2dd4c5507817c220bf22b1858aec0e3ed862c9495f934f6#rd)

  

本文分享我对Meta机器翻译模型NLLB论文解读和实践心得。推荐阅读：4星。不足之处，还望批评指正。

  

  

**论文：**2022 | No Language Left Behind: Scaling Human-Centered Machine Translation

**作者：**NLLB Team

**机构：**Meta AI

**代码：**https://github.com/facebookresearch/fairseq/tree/nllb

**引用量：**190

**应用场景：**Facebook、Instagram、Wikipedia

  

![](assets/001.png)

  

  

本文目录如下：

一、介绍

二、数据

三、模型

四、实践

  

**一、介绍**

Meta AI构建了机器翻译模型NLLB-200，它是第一个能够翻200种不同语言的模型，包括非洲一些低资源语言。如果像搭建一套完整翻译项目，强烈建议阅读这篇190页的论文，很详细了，流程也很规范。

  

![](assets/002.png)

  

整个项目的pipeline：

(1) 从母语者的角度来理解资源不足的翻译问题；

(2) 研究如何自动创建训练数据，使低资源语言向高资源语言迁移；

(3) 利用这些数据来创建SOTA翻译模型；

(4) 评估所要翻译的每一种语言。

  

具体每部分是怎么适配在一起的：

  

![](assets/003.png)

  

**二、数据**

数据有以下几类：  

  

\- NLLB-Seed：39种低资源语言的种子训练数据（数量少但质量高，所以称作种子数据），这是一套在维基百科领域中人类专业翻译的句子 ；

\- Public Bitext：公开网络的双语文本；

\- NLLB-MD：6种语言，来自不同领域的单语数据；

\- Flores-200：204种语言的评估数据集；

\- Toxicity-200：检测200种语言种毒性的单词表，即违规用词；

  

Flores-200的翻译工作流：

  

![](assets/004.png)

  

双语文本开采流程：利用语言识别技术（用的是fasttext）来提取单语句子，然后用LASER模型获取双语文本。

  

![](assets/005.png)

  

**三、模型**

多语言机器翻译为一个序列到序列的任务，使用将源语言输入序列喂入编码器后，并使用解码器以预期的目标语言生成输出序列。

  

为了分词文本序列，为多语言训练了SentencePiece (SPM)。模型则是Transformer encoder-decoder结构，接受输入的源token，编码成token embedding，再自回归解码成目标序列。

  

注意，在实操中，论文有提到几点内容，个人觉得对NLP机器翻译实操任务会有帮助：

  

**1\. 语言标识：**在源序列之前只加入源语言前缀标记，而不是像历史研究那样，也把目标语言标记加上，这是因为实践中发现，如果把目标语言标记加上，会影响零样本表现，即泛化性变差，很难泛化到没有遇到的源语言和目标语言对上；

  

![](assets/006.png)

NLLB tokenizer的分词标识说明

  

**2\. LayerNorm：**在每个子层的开始应用LayerNorm，而不是在每个子层结束的残差连接后应用LayerNorm。在实践中证实在子层用LayerNorm会更稳定；

  

**3\. 多任务学习：**为了让多语言翻译学习之间既能互相迁移知识，又能避免互相过度干扰，就用了多任务模型MoE，这套玩法好像也没有说很新奇… 门控gate决定tokens在experts之间的流转，这里给每个token分别选择进入top2个分数高的experts。

  

![](assets/007.png)

  

在loss上，为了推动tokens平均分布在各experts，作者加入了一个辅助损失：load balancing loss (LB)：

  

![](assets/008.png)

  

fe是在top-k-gating下，第一选择进入到第e个expert的token占比，pe是在mini-batch内第e个expert在T个tokens下的平均流通概率。如果存在tokens们都经常流通经过某个expert e，那fe和pe都会很大，LB也会变大。

  

但MoE受高资源语言影响会训练较长时间，而因此对低资源语言来说，会显著过拟合。为此作者做了以下正则化策略：

  

**（1）MoE Expert Output Masking (EOM)：**对expert输出做mask；

  

![](assets/009.png)

  

**（2）Conditional MoE Routing (CMR)：**多加了个gate控制到共享专家还是其他专家；

  

![](assets/010.png)

  

**4\. 课程学习：**将前K轮就过拟合的低资源语言对，放在第K轮-最后1轮阶段训练，这样可以避免过拟合。即先训练简单的丰富资源语言对，然后后期再加入低资源语言对训练；

  

**5\. 自监督学习：**去噪自编码器（mask文本token去重建）和因果语言建模（因果语言模型采用了对角掩蔽矩阵，使得每个token只能看到在它之前的token信息，而看不到在它之后的token，模型的训练目标是根据在这之前的token来预测下一个位置的token，这里预测模型是来自单语言本身，相当于decoder-only的续写任务）；

  

**6\. 反向翻译：**对单语言数据的数据增强操作。反译学习包括前向翻译和后向翻译两个步骤。前向翻译是将源语言文本翻译成目标语言文本，后向翻译是将目标语言文本再次翻译回源语言。最后，比较后向翻译的结果与原始源语言文本之间的差异，并将差异较小的样本加入训练集进行模型训练。同时会标记反向翻译的数据，帮助模型区分噪声数据和避免过拟合它们；

  

![](assets/011.png)

  

**7\. NLLB-Seed：**该数据能显著提高反向翻译的有效性。

  

**四、实践**

NLLB有几个参数版本：

  

![](assets/012.png)

  

我建议用3.3B，因为蒸馏效果还是差强人意。其中，NLLB-200（MoE，54.5B）模型有128名专家，在256个GPU上进行训练…

  

有人会问：在做机器翻译任务时，为啥不直接考虑使用LLM来做？是因为我发现有以下问题：

  

**（1）LLM内存占用高：**就拿ChatGLM2/3-6B来说，1B可以约等于4G显存占用需求，6B的参数量就与等于24G显存占用，如果知识考虑做机器翻译单个任务，使用LLM对GPU成本要求过高。当然，如果已有其他业务部署LLM，那么调用LLM就不需要考虑额外单独部署的成本了；

  

**（2）LLM效果不佳（仅讨论非百亿开源的LLM）**：LLM的效果，我个人粗浅认为主要来自2方面：数据语料质量 和 模型参数量，如果在翻译任务上，在语料上，你可以理解为：国外LLM因为训练使用的外文语料比中文语料丰富，所以在中文翻译成外文上，会比国内LLM好，反之，国内LLM在外文转中文上效果更好。

  

我展示几个示例效果：

在线对比LLM效果，可访问：https://chat.lmsys.org/

  

![](assets/013.png)

Meta的llama-2-13b VS 阿里的qwen-14b：英转中，qwen14b好

  

![](assets/014.png)

Meta的llama-2-13b VS 阿里的qwen-14b：中转英，llama好

  

英转中，llama对中文口语化翻译结果一言难尽…，而中转英，qwen居然出现中文，而且并不是由于断句原因或者提示词的问题，比如我改善输入句子和提示词后，仍然有这个问题。

  

![](assets/015.png)

Meta的llama-2-13b VS 阿里的qwen-14b：中转英，llama好

  

以上的展示语料给LLM带来的影响（没有严格论证，只是个人YY的，轻喷，欢迎私聊讨论~）。另外，发现，参数量越大的模型，对提示词的理解能力会更强，同时，生成回复也相对可控。比如，在要求中译葡一句非完整的句子时，Chatglm3-6b和qwen-14b-chat的表现如下：

  

![](assets/016.png)

智谱&清华的Chatglm3-6b VS 阿里的qwen-14b：中转葡，qwen14b好

  

虽然生成LLM训练模型是预测下一个字的出现概率，但低参数量的模型在面临非完整句子的翻译时，有时会出现续写问题。

  

但机器翻译模型，比如Meta的NLLB，在应用中也有些需要优化的工程点：

  

（1）需要声明用何种语种的分词器去加，因此对OCR识别出的文本做翻译时，要做语种识别（Language identification，LID），可实际过程中，还可能会出现一句话中出现多种语言混杂的情况；

  

（2）面临非完整句子的翻译时，虽然不会出现续写，但可能模型会选择不解码不完整部分的句子。

  

在工程上，其实可以尝试以下工程方法：

  

（1）正常情况，用langid或fasttext识别文本语种即可，个人偏好langid，速度快，虽然业界说fastext好，但有次翻译居然把中文识别为日本，真让人感官不适。但这种语言识别的弊端在于，很难完全判断文本是否存在多语言混杂情况（拿识别分数去判断也很难），没法性根本解决依赖语言的分词器对语种混杂的句子分词不好的缺点。当然，你用大模型去做语种识别也行，但实践下来，也不是说很理想（GPT除外，有1说1，用以翻译服务为主去设计Prompt+语言生成模型，如果去专门训练/微调，就能解决源文本多语言混杂的问题（即分词器不依赖源语言的给定），但效果好不好，我也没尝试，暂时不清楚）;

  

顺便聊一句，像百度翻译，如果你不指定待翻译文本的语言，他会先自动检测。所以我想应该他可能是做了语种识别后，用目标语种的分词器去分词后再翻译，但我试过百度，对一些语言混杂翻译场景，也表现不错，这点还是很好的。而且口语化中文翻译效果不错。

  

![](assets/017.png)

百度翻译：口语化中英文混杂场景

  

![](assets/018.png)

Meta NLLB：口语化中英文混杂场景

  

SentencePiece的相关资料：

\[1\] 大模型基础｜分词｜LLaMA中文词表训练｜词表合并 - 养生的控制人，知乎：https://zhuanlan.zhihu.com/p/650224698

\[2\] ChatGLM2 源码解析：\`ChatGLMTokenizer\` - ApacheCN，博客：https://www.cnblogs.com/apachecn/p/17818543.html

  

语种识别的相关资料：

\[1\] langid, Github: https://github.com/saffsd/langid.py

\[2\] fasttext, Github: https://github.com/facebookresearch/fastText/#text-classification

  

（2）如果模型会选择不解码不完整部分的句子，可以通过修改解码方式解决。如果用的模型在Hugging Face上，直接简单修改下解码配置参数即可。我是用了对比搜索（Contrastive Search），旨在产生不重复但连贯的长输出，在model.generate()中加入penalty\_alpha和top\_k解决了非完整句子不翻译的问题。关于生成文本的解码方式，以后有机会学习后，再专门分享下。

  

生成文本的解码方式的相关资料： 

\[1\] 如何生成文本: 通过 Transformers 用不同的解码方法生成文本 - patrickvonplaten，博客：https://huggingface.co/blog/zh/how-to-generate 

\[2\] Text generation strategies - Hugging Face, 文档：https://huggingface.co/docs/transformers/generation\_strategies