# QuantML-Qlib开发版 | 蚂蚁&amp;清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测

QuantML QuantML 2024-06-30 21:59 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=cf059214a9316de4ca041ae728269caaaca21c3dfb9f3cd0c895f689fc2bed5eaa22301ccf18#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=cf059214a9316de4ca041ae728269caaaca21c3dfb9f3cd0c895f689fc2bed5eaa22301ccf18#rd)

Content

> 论文地址：\[2405.14616\] TimeMixer: Decomposable Multiscale Mixing for Time Series Forecasting (arxiv.org)
> 
> https://arxiv.org/abs/2405.14616

  

  

![](assets/001.png)

  

**摘要 (Abstract)**

-   论文主题：提出了一种名为TimeMixer的新模型，用于时间序列预测。
    
-   背景：时间序列预测在多个领域非常重要，但实际中的时间序列通常具有复杂的时间变化，这使得预测变得非常具有挑战性。
    
-   创新点：TimeMixer采用了一种新颖的多尺度混合视角，通过Past-Decomposable-Mixing (PDM) 和 Future-Multipredictor-Mixing (FMM) 块，充分利用了在不同采样尺度上的时间序列的微观和宏观信息。
    
-   性能：TimeMixer在长期和短期预测任务中均实现了一致的最先进性能，并且具有较好的运行时效率。
    

###   

### **第1章 引言 (Introduction)**

引言介绍了时间序列预测的重要性和广泛应用，例如在经济、能源、交通规划和天气预报等领域。作者指出现实世界中的时间序列数据通常具有复杂和非平稳的特性，展现出混合的多种时间模式，如增长、减少和波动，这些模式对预测任务构成了重大挑战。接着，作者概述了深度学习模型在时间序列预测方面取得的进展，特别是如何通过精心设计的结构捕捉时间变化，包括卷积神经网络(CNN)、递归神经网络(RNN)、Transformer和多层感知器(MLP)等基础架构。此外，还提到了一些特殊设计，如序列分解和多周期性分析，这些设计被用来处理复杂的时间模式，以提高预测性能。

最后，作者提出了TimeMixer模型，这是一种新颖的多尺度混合架构，旨在通过同时利用微观和宏观尺度的信息来解决时间序列预测中的复杂性问题

  

### **第2章 相关工作 (Related Work)**

本章深入探讨了深度时间序列预测中的几个关键问题和现有方法。首先，根据基础架构，将深度模型分为RNN、CNN、Transformer和MLP四类，并概述了它们如何捕获时间序列的不同时间模式。然后，讨论了一些特定的设计方法，如序列分解和多周期性分析，这些方法被集成到深度模型中以更好地捕捉复杂的时间模式。例如，Autoformer使用基于移动平均的序列分解块来分解时间序列，而TimesNet采用傅里叶变换将时间序列映射到具有不同周期长度的多个分量。此外，还探讨了混合网络在计算机视觉和自然语言处理中的应用，并提出了TimeMixer模型，它在时间序列预测中采用了新颖的多尺度混合架构，通过Past-Decomposable-Mixing和Future-Multipredictor-Mixing块来提取和预测时间序列的过去和未来信息。

  

### **第3章 TimeMixer模型 (TimeMixer)**

第三章详细介绍了TimeMixer模型的结构和核心组件，包括多尺度混合架构、过去可分解混合（PDM）和未来多预测器混合（FMM）。

### **3.1 多尺度混合架构 (Multiscale Mixing Architecture)**

TimeMixer模型的核心在于其多尺度混合架构，该架构基于时间序列在不同采样尺度上表现出不同模式的观察。这种多尺度视角能够自然地解开复杂的时间变化，其中细粒度尺度主要描绘详细模式，而粗粒度尺度突出宏观变化。对于预测任务，多尺度时间序列呈现出不同的预测能力，因为它们各自主导的时间模式不同。

为了实现这一点，TimeMixer首先通过对过去的观测数据进行平均池化降采样，生成多尺度时间序列集合。这些序列集合从最细粒度的输入序列到最粗粒度的宏观序列，形成了一个多尺度的表示。接着，模型使用嵌入层将这些多尺度序列投影到深度特征空间中，为后续的过去信息提取和未来预测打下基础。

![](assets/002.png)

### **3.2 过去可分解混合 (Past-Decomposable-Mixing, PDM)**

PDM模块是TimeMixer中用于处理过去信息的关键组件。它采用序列分解技术，将每个尺度的时间序列分解为季节性部分和趋势部分。季节性和趋势部分具有不同的特性，分别对应短期和长期变化，或静止和非静止动态。

PDM模块通过两个方向的混合操作来聚合跨尺度的信息：

-   自底向上的季节性混合 (Bottom-Up Seasonal Mixing)：采用自底向上的方法，将细粒度时间序列中的详细信息逐步整合到更粗粒度的时间序列中，补充季节性建模所需的细节信息。
    
-   自顶向下的趋势混合 (Top-Down Trend Mixing)：与季节性混合相反，趋势混合采用自顶向下的方法，利用粗粒度时间序列中的宏观信息来指导细粒度时间序列的趋势建模，因为粗粒度序列更容易提供清晰的宏观趋势信息。
    

PDM模块通过这种新颖的设计，能够成功地从最细粒度的季节性信息开始聚合，并随着从更粗粒度尺度获得的知识深入到宏观趋势信息中，最终实现过去信息的多尺度混合。

![](assets/003.png)

### **3.3 未来多预测器混合 (Future-Multipredictor-Mixing, FMM)**

在PDM模块处理完过去信息后，TimeMixer使用FMM模块来进行未来时间序列的预测。FMM模块的关键在于集成多个预测器，利用不同尺度序列的互补预测能力。

具体来说，FMM模块首先从每个尺度的时间序列中提取特征，然后每个尺度的预测器独立地对相应尺度的时间序列进行预测。这些预测器的输出随后被集成起来，形成最终的预测结果。这种集成方法允许模型整合来自不同尺度的预测，从而提高预测的准确性和鲁棒性。

FMM模块的设计允许TimeMixer充分利用每个尺度的独特预测能力，因为不同尺度的序列呈现出不同的主导变化，其预测能力也因此不同。通过这种方式，TimeMixer能够生成综合考虑多尺度信息的未来预测。

  

### **第4章 实验 (Experiments)**

### **4.1 主要结果 (Main Results)**

-   长期预测 (Long-term Forecasting): TimeMixer在多个长期预测基准测试中表现出色，包括ETT、Weather、Solar-Energy、Electricity和Traffic数据集。与现有的最先进模型相比，TimeMixer在这些数据集上实现了更低的平均平方误差（MSE）和平均绝对误差（MAE），显示出其优越的预测性能。
    

![](assets/004.png)

-   短期预测 (Short-term Forecasting): 在短期预测任务中，TimeMixer同样展现了优秀的性能，特别是在PeMS和M4数据集上。这些数据集涵盖了多种不同的时间序列，包括交通网络和不同采样频率的单变量时间序列。
    

![](assets/005.png)

### **4.2 模型分析 (Model Analysis)**

-   消融研究 (Ablation Study): 为了验证TimeMixer中每个组件的有效性，作者进行了详尽的消融实验。这些实验包括移除或替换PDM（Past-Decomposable-Mixing）和FMM（Future-Multipredictor-Mixing）块中的各个组件。消融实验的结果表明，TimeMixer的每个设计选择都对最终性能有显著影响。
    
-   季节性和趋势混合的可视化 (Visualization of Seasonal and Trend Mixing): 作者通过可视化方法展示了PDM块中季节性和趋势混合的权重，以及不同尺度上的季节性和趋势项对预测的贡献。这些可视化结果进一步证实了采用不同的混合策略对于季节性和趋势成分的重要性。
    
-   多预测器的可视化 (Multipredictor Visualization): 通过展示不同尺度上的预测结果，作者说明了FMM块如何利用多尺度时间序列的互补预测能力来提高预测精度。
    
-   效率分析 (Efficiency Analysis): TimeMixer在GPU内存使用和运行时间方面表现出了高效率，与基于Transformer的最新模型相比具有显著优势。这一优势归功于TimeMixer完全基于MLP（多层感知器）的网络架构。
    

![](assets/006.png)

-   尺度数量分析 (Analysis on Number of Scales): 作者探讨了尺度数量（M）对模型性能的影响。实验结果表明，对于长期预测，增加尺度数量可以提高性能；而对于短期预测，尺度数量的增加对性能的提升作用有限。
    

![](assets/007.png)

### **第5章 结论 (Conclusion)**

TimeMixer模型的主要贡献和研究成果。TimeMixer通过提出一种新颖的多尺度混合架构，成功地处理了时间序列预测中的复杂时间变化问题。该模型利用Past-Decomposable-Mixing和Future-Multipredictor-Mixing技术，有效地从过去的时间序列中提取关键信息，并准确预测未来趋势。在广泛的实验中，TimeMixer在长期和短期预测任务上均实现了与现有最先进方法相媲美或更优的性能，同时展现出了优越的运行效率。此外，论文还提供了详细的实现细节和源代码，确保了研究的可复现性。最后，作者提出了未来工作的方向，包括探索更高效的参数化方法、将模型扩展到多变量时间序列预测，以及进行更深入的理论分析

  

  

2\. 代码部分

  

我们在QuantML-Qlib实现模型。由于有部分c代码，需要编译后再使用，在QuantML-Qlib根目录下运行以下命令进行编译

  

```
python  setup.py build_ext --inplace
```

然后将我们的代码拷贝进examples/benchmarks

![](assets/008.png)

在yaml文件中设置好数据路径，超参数后，运行run.py即可。

模型代码在TimeMixer.py中, 代码下载地址见星球。

感谢支持，发放一些优惠券，加入星球请扫我：

![](assets/009.png)

  

入群请扫我：

![](assets/010.jpg)

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | 清华大学时序卷积模型TimesNet用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484709&idx=1&sn=f462495e96ee99019f83321a84d2fd0a&chksm=ce7e623bf909eb2d3f24882531e2ac8de4459bab71920a5985d7add81731d82d7ba55934bd07&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序模型Autoformer用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=2&sn=7a1d788cb862ff6f5afd3255c998dab7&chksm=ce7e631df909ea0b4515cbd2f95cffb0733d872a519942f1d88e6a561a01bcfe68716d31fe0c&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [研报复现 | 开源证券 ：形态识别，均线的收敛与发散](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)  
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=ce7e64b7f909eda171118d001451a569509a67bb2d486f5affdaa2824dab5b824ee4bd7b3052&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)[What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [ICLR'24 | FTS-Diffusion: 用于合成具有不规则和尺度不变模式的金融时间序列的生成框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483907&idx=1&sn=df124c03a74981eba923fee63613ecfd&chksm=ce7e651df909ec0b2f6029db3e29992bb41210c8b9f76f979b7968d0fab1ac913848004ac44d&scene=21#wechat_redirect)
    
-   [ICLR'24 | LIFT 领先指标在通道依赖多元时间序列预测中的应用](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483834&idx=1&sn=df3ede32de8806440435b08768e9aadf&chksm=ce7e66a4f909efb2d9c5cc930bea70b32df96aaa66b3f2feba584fb9cf435081e6456c5559ba&scene=21#wechat_redirect)
    
-   [CIKM'23 | Diffusion + VAE用于解决多步股票价格预测随机性问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484152&idx=1&sn=4b83dde88bd433b1ec4447d8122b311e&chksm=ce7e65e6f909ecf00a4272e5d2ae14fe11397937d363316b329f9b61c453fcdc7ec356bbf136&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-23 | PEN: 可解释的结合新闻及社交媒体文本数据的股票预测神经网络模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483925&idx=1&sn=711b4a193f231442ead1a7709fc9b29a&chksm=ce7e650bf909ec1dc65070e866ee1d6c0127291efb093bb982ae5652aa8232155b2a757ca5d7&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)
    
-   [ICAART 2024 | DTX: 基于TBSE Level2多线程市场模型的深度学习交易系统](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483965&idx=1&sn=e2fda25ce1bc8a4b9393158321dc2a14&chksm=ce7e6523f909ec3538bd37e07689308380cad55b02c35a7d4652a3e7d7fd3306a40253341c61&scene=21#wechat_redirect)
    

  

QuantML-Qlib是一个非常强大的AI量化投资框架，基于QLIB底层开发，我们进行了一系列改进，包括数据接口优化，因子挖掘算法，各类深度学习模型，回测优化，大模型接入等等。

QuantML-Qlib项目代码托管在阿里云，加入星球获取代码权限。

  

  

**点击蓝字**

![](assets/011.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

![](assets/012.jpg)