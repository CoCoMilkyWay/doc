# 牛津大学：解锁大规模强化学习交易的GPU加速LOB模拟器

QuantML QuantML 2024-07-01 17:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484978&idx=1&sn=ed321f9103b3d156245934eb49142756&chksm=cff3b37158e47398a28a68b4de0c2c66bcf84e499801097f80da7a7e5117b537e17e509de271#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484978&idx=1&sn=ed321f9103b3d156245934eb49142756&chksm=cff3b37158e47398a28a68b4de0c2c66bcf84e499801097f80da7a7e5117b537e17e509de271#rd)

Content

> 论文地址：\[2308.13289\] JAX-LOB: A GPU-Accelerated limit order book simulator to unlock large scale reinforcement learning for trading (arxiv.org)  
> 
>   
> 
> https://arxiv.org/abs/2308.13289

![](assets/001.png)

这篇论文介绍了基于GPU加速的限价委托簿（Limit Order Book, LOB）模拟器，该模拟器旨在为交易领域中的大规模强化学习（Reinforcement Learning, RL）解锁潜力。

### **1\. 引言 (Introduction)**

-   市场作为现代经济的关键组成部分，依赖于拍卖机制来匹配买卖双方并确定价格。
    
-   限价委托簿（LOB）是现代电子交易所中用于价格发现的工具，允许市场参与者提交指定数量和愿意交易的价格的买卖订单。
    
-   为了研究目的，需要大规模高效的LOB动态模拟器，这些模拟器可以应用于代理模型（Agent-Based Models, ABMs）、强化学习环境和生成模型。
    
-   本文展示了第一个GPU加速的LOB模拟器，能够并行处理数千个委托簿，显著减少了每条消息的处理时间。
    

### 

### **2\. 背景 (Background)**

本章详细介绍了限价委托簿（LOB）作为现代电子交易市场的核心机制，它允许市场参与者提交买卖订单并基于价格和时间优先级进行交易匹配。此外，本章还探讨了LOB模拟器在不同研究领域的应用，包括代理模型、强化学习环境和生成模型，强调了JAX框架在实现高性能机器学习研究中的重要作用，特别是在利用GPU加速和即时编译技术进行大规模并行计算方面。

###   

### **3\. 相关工作 (Related Work)**

本章回顾了现有的限价委托簿（LOB）模拟器实现，这些实现用于代理模型（ABMs）和市场重放，以及如何将强化学习应用于解决交易执行问题。论文讨论了不同实现方式的优缺点，例如基于Python的ABIDES框架和C++实现的MAXE环境，并指出了市场重放模型在复制市场数据分布方面的局限性，以及ABMs在创建足够现实代理行为方面的挑战。此外，还提到了其他研究者如何使用深度Q网络（DQN）和PPO算法来优化交易执行，以及这些方法如何与本文提出的JAX-LOB模拟器相比较。

  

### **4\. JAX-LOB模拟器 (The JAX-LOB Simulator)**

本章详细介绍了JAX-LOB模拟器的基本操作、数据结构设计以及性能测试

### **4.1 基本操作 (Basic Operations)**

JAX-LOB模拟器实现了限价委托簿（LOB）的基本操作，这些操作是模拟市场交易行为的核心。基本操作包括：

-   添加订单：在订单簿的数组中找到一个空位，并插入新的限价订单。这要求识别出数组中的-1值，代表空位，并将订单的详细信息填充到相应的字段。
    
-   取消订单：根据订单ID定位并取消订单，需要从订单簿中减去指定数量的股份。
    
-   匹配订单：当收到一个市价订单时，需要在订单簿的另一侧寻找匹配的限价订单。匹配过程涉及到计算双方订单的剩余数量，并在匹配成功后记录交易。
    

![](assets/002.png)

![](assets/003.png)

### **4.2 消息类型 (Message Types)**

JAX-LOB通过处理不同类型的消息来模拟订单簿的动态变化。消息类型决定了将执行哪种基本操作，包括：

-   限价订单：提交一个新的限价订单到订单簿。
    
-   取消订单：取消订单簿中已有的订单。
    
-   删除订单：从订单簿中删除订单，通常用于错误或超时的订单。
    
-   市价订单：立即执行的订单，以当前市场上的最佳价格成交。
    

每种消息类型都有其特定的数据结构，包括订单类型、买卖方向、价格、数量、订单ID、交易者ID和时间戳。

![](assets/004.png)

### **4.3** **使用vmap进行向量化****(****Vectorising map - vmap****)**

为了充分利用GPU的并行处理能力，JAX-LOB使用JAX库中的vmap函数。vmap允许将可微分的函数应用于输入数组的每个元素，从而实现数据的并行处理。这对于处理大量订单簿尤为重要，因为它可以显著提高处理速度和效率。

-   vmap的优势：通过将控制流语句转换为在运行时执行所有条件分支的选择语句，vmap避免了在每个订单处理步骤中进行条件判断，从而提高了并行处理的效率。
    
-   性能影响：使用vmap进行并行处理时，每个可能的分支都会被计算，但实际的运行时间将由最慢的分支决定。这意味着在处理不同类型或大小的订单簿时，性能可能会有所不同。
    

![](assets/005.png)

![](assets/006.png)

### **5\. GYMNAX环境 (GYMNAX Environments)**

本章详细介绍了JAX-LOB模拟器在GYMNAX环境中的集成和应用，特别是如何利用这个环境来支持强化学习任务。

### **5.1 基础环境 (Base Environment)**

-   数据加载：为了提高执行效率，环境预先加载了固定大小、不重叠的时间窗口内的消息数据。这意味着每个时间窗口内的处理消息数量是固定的，但每个步骤的时间长度是可变的。此外，为了满足固定大小数组的约束，如果数据不足以填满时间窗口，会用零填充。
    
-   核心状态空间需求：基础环境定义了状态空间所需的核心特征，包括订单簿的买卖两侧、交易记录、初始时间和当前时间等。
    
-   功能：基础环境的核心功能包括将接收到的行动转换为JAX-LOB处理的消息、获取加载数据中的消息、更新当前时间和处理所有消息。
    

![](assets/007.png)

### **5.2 执行环境 (Execution Environment)**

-   扩展状态空间：在基础环境的基础上，执行环境增加了额外的状态信息，如每个处理消息的Level 1数据、初始中间价格、执行任务的大小、迄今为止执行的数量和迄今为止的总收入。
    
-   观察空间：观察空间为RL代理提供了可访问的信息，设计上避免了冗余，并包含了实际生活中可访问的数据。观察空间是一个一维数组，包含了最佳买卖价格、中间价格、价格变动、时间信息等。
    
-   行动空间：为了保持行动空间的丰富性同时简化学习任务，执行环境选择了一个四维的连续行动空间。在每个步骤中，代理必须选择在四个预定义价格上放置订单的大小。
    
-   奖励函数：提出了一个结合了代理执行优势和预测价格趋势能力的奖励函数。奖励函数由两部分组成：优势和漂移。优势代表了在执行过程中相对于平均价格的收益，而漂移代表了平均交易价格相对于初始中间价格的变动效应。
    

### **5.3 Rollout成本比较 (Rollout Cost Comparison)**

-   本节比较了基于JAX-LOB的执行环境与在CPU上运行的类似gym环境的运行时改进。通过在Nvidia 2080 Ti GPU上并行运行不同数量的环境，与在Apple M1 CPU上串行运行的环境进行了比较。结果表明，JAX-LOB在并行环境中的每个环境的步进时间显著减少，显示出显著的性能提升。
    

![](assets/008.png)

### **6\. 使用GYMNAX环境进行强化学习 (Using the GYMNAX Environment for Reinforcement Learning)**

本章聚焦于使用GYMNAX环境进行强化学习的应用，特别是训练一个执行交易任务的代理。

![](assets/009.png)

  

### **6.1 训练循环 (Training Loop)**

-   循环设计：介绍了如何重新实现循环PPO（Recurrent Proximal Policy Optimization, Recurrent-PPO）算法以支持连续动作空间。这是为了适应交易任务的需要，其中代理需要根据市场状态连续地做出交易决策。
    
-   网络结构：展示了演员（Actor）和评论家（Critic）网络的结构，包括观察空间到隐藏状态的转换、循环神经网络（RNN）层以及最终的输出层。
    
-   批量处理：描述了如何收集跨多个环境的步骤来创建用于网络更新的批量数据。每个更新步骤涉及多个时代的训练，每个时代使用不同的小批量数据。
    

### **6.2 JAX加速的训练速度 (JAX-Enabled Training Speedup)**

-   速度比较：比较了使用JAX-LOB的GYMNAX环境与基于CPU的LOB模拟器的训练速度。结果显示，JAX-LOB在训练循环中实现了显著的速度提升。
    
-   效率分析：讨论了由于不需要在处理单元之间传输数据，JAX-LOB能够实现更高的效率。此外，还指出了超参数调整在并行化实现中的优势。
    

![](assets/010.png)

### **6.3 训练执行任务 (Training Execution Task)**

-   任务定义：开始使用所提出的设置训练执行代理，专注于单日数据。训练的目标是最小化交易成本，同时考虑到市场影响和交易时机。
    
-   奖励函数：通过设置奖励函数中的参数，使得训练更加容易。奖励函数包括优势和漂移两部分，其中优势衡量了代理相对于平均执行价格的收益。
    
-   训练曲线：展示了代理在训练过程中的回报曲线，并与时间加权平均价格（TWAP）基准策略进行了比较。
    

![](assets/011.png)

### **7\. 结论和未来工作 (Conclusions and Future Work)**

本文总结了JAX-LOB模拟器的开发成果，强调了其作为第一个GPU加速的限价委托簿模拟器在强化学习训练中的显著性能提升，相较于CPU实现至少提速了5倍，并且在使用PureJaxRL进行RL代理训练时，速度提升达到了7倍。

  

论文还提出了未来的研究方向，包括对执行任务的强化学习训练进行更全面的样本外测试和超参数调整，以及进一步探索行动空间、特征空间、奖励函数和网络架构，以培养出更加健壮和成本效益高的RL执行代理。

  

**论文及代码下载见星球，更多专业研究欢迎加入星球获取**

  

为了感谢支持，发放一些优惠券，加入星球请扫我：

![](assets/012.png)

入群请扫我：![](assets/013.jpg)

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
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

![](assets/014.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

![](assets/015.jpg)