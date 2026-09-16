# 研报复现 | 开源金工-高频追涨杀跌因子复现

张世良 QuantML 2024-06-26 14:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=cf3fa5e0bb84d3b4ab30fd469c47660c728e1e11c47c58adbd471aa1dd539061ed442863641e#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=cf3fa5e0bb84d3b4ab30fd469c47660c728e1e11c47c58adbd471aa1dd539061ed442863641e#rd)

Content

  

本文复现了开源金工《从高频股价形态到追涨杀跌因子》，来自星球嘉宾张世良（微信号：joker19930309）的研报复现项目。  

  

**因子逻辑概述**

股价作为多空双方博弈的最终结果，蕴含多方面信息。而投资者的某些行为特性在股票的价格形态中亦有所体现。这使得通过特定价格形态，匹配特定类别投资者的交易行为成为可能。研报以分钟涨跌幅的自相关衡量股价追涨杀跌的形态特征。通过识别追涨杀跌的价格形态，衡量个股交易中散户投资者交易占比，构建负alpha因子。

对于追涨杀跌价格形态的识别，以分钟涨跌幅的自相关衡量。若股票当前时刻t出现幅度较大的上涨，同时伴随下一时刻t+1的连续上涨，则该股分钟涨跌幅自相关性较高，股价追涨杀跌特性较强，其交易中散户投资者交易占比较高，个股未来风险相应较高。

  

**因子构建**

**1.全时段追涨杀跌因子（chasing\_mom\_allday）：**

**1.1定义：**

选取过去20个交易日的1分钟频数据，通过计算前后一分钟超额收益序列的余弦相似度构建。

  

**1.2计算步骤：**

（1）选取股票过去20个交易日1分钟频率交易数据；

（2）分别计算时点t的当前分钟超额收益和下一分钟t+1的超额收益，分别记作𝑅𝑡和𝑅𝑡+1，超额收益定义为绝对收益-市场中位数，使用超额收益可剔除市场beta对分钟收益的影响；

（3） 计算𝑅𝑡与𝑅𝑡+1之间的余弦相似度，作为追涨杀跌因子值。

![](assets/001.png)

**1.3因子表现（周频）：**

（1）10分组单调性

![](assets/002.png)

（2）10分组年均收益

![](assets/003.png)

（3）与常见风格因子的相关性

![](assets/004.png)

**1.4 小结**

全时段追涨杀跌因子（chasing\_mom\_allday），自2017年2月至今（2024.5），周频RankIC-6.2%，年化ICIR-3.22，可以看出因子表现符合构建的逻辑，空头负向超额较为显著，且总体分组单调性较好，且因子与常见风格中的估值（BP）、波动率（ResidualVolatility）、流动性（Liquidity）具有一定相关性。

  

**2\. 尾盘追涨因子（chasing\_mom\_last\_cos）**

**2.1定义：**

对全时段追涨杀跌因子做进一步拆解，涨跌方向上，以min收益的正负为标签，将追涨杀跌因子拆解为追涨因子与杀跌因子两部分；时间维度上，将日内交易时间段拆解，对比不同时段的信息差异。可以得到结论：涨跌方向上看，追涨因子负alpha显著强于杀跌因子负alpha；时间维度上看，时段越靠近尾盘，因子负alpha越强。

  

**2.2讨论：**

因子有效性呈现以上规律性的原因在于：

（1）涨跌方向：追涨与杀跌均受散户交易程度与散户过度反应两因素影响，有共性也有差异。无论追涨还是杀跌，均意味着散户交易程度较高，这是二者负alpha的来源，但散户交易程度高往往伴随着散户的过度反应，而二者散户过度反应的方向不同，追涨因子中，散户过度反应导致股价上涨，贡献负alpha，杀跌因子中，散户过度反应导致股价下跌，贡献正alpha。因此，追涨因子中两因素相互协调，杀跌因子中两因素相互矛盾，导致追涨因子负alpha更强。

（2）时间维度：首先，从不同投资者交易习惯的角度，机构投资者倾向于早盘交易，散户投资者倾向于尾盘交易，因此尾盘散户行为的负alpha更强；其次，尾盘时段的散户交易中，一定程度交易未来的隔夜信息预期，散户作为非知情交易者，投资决策更多地依赖于当前的价格涨跌，因此尾盘的散户追涨杀跌行为特征更加明显。

  

**2.3因子计算步骤：**

（1）选取股票过去20个交易日每日13:31至15:00之间的1分钟频率交易数据；

（2）计算各时点的超额收益，选取超额收益为正的时点t；

（3）分别计算时点t的当前分钟超额收益（>0）和下一分钟超额收益，分别记作𝑅𝑡与𝑅𝑡+1； （4）计算𝑅𝑡与𝑅𝑡+1之间的余弦相似度，作为尾盘追涨因子值。

  

**2.4因子表现（周频）：**

（1）10分组单调性

![](assets/005.png)

（2）10分组年均收益

![](assets/006.png)

（3）与常见风格因子的相关性

![](assets/007.png)

**2.5小结**

尾盘追涨因子（chasing\_mom\_last\_cos），自2017年2月至今（2024.5），周频RankIC-7.3%，年化ICIR-3.77，可以看出因子表现相比全时段追涨杀跌因子有所增强，其余特征则与全时段因子较为类似。

  

**3\. 尾盘追涨自回归系数因子（chasing\_mom\_last\_ar）**

**3.1定义**

将尾盘追涨因子构建步骤中，𝑅𝑡和𝑅𝑡+1之间的余弦相似度指标，变换为自回归的斜率项作为因子值。

**3.2 计算步骤：**

（1）选取股票过去20个交易日每日14:31至15:00之间的1分钟频率交易数据；

（2）计算各时点的超额收益，选取超额收益为正的时点t；

（3）分别计算时点t的当前分钟超额收益和下一分钟超额收益，分别记作𝑅𝑡与𝑅𝑡+1；

（4）计算𝑅𝑡与𝑅𝑡+1之间的回归斜率，作为尾盘追涨因子值。

  

**3.3因子表现（周频）：**

（1）10分组单调性

![](assets/008.png)

（2）10分组年均收益

![](assets/009.png)

（3）与常见风格因子的相关性

![](assets/010.png)

**3.4小结**

尾盘追涨自回归系数因子（chasing\_mom\_last\_ar），自2017年2月至今（2024.5），周频RankIC-6.1%，年化ICIR-3.63，因子单调性一般，空头端收益突出，总体表现介于前两个因子之间。

  

**4\. 尾盘追涨偏离因子（chasing\_mom\_diff）**

**4.1定义**

将尾盘追涨因子与全时段追涨因子作差，构建尾盘追涨偏离因子，衡量个股尾盘时段与全时段追涨特征差异。尾盘追涨偏离因子越大，说明个股相比于自身而言，倾向于尾盘时段追涨特性更强。

chasing\_mom\_diff = standardize(chasing\_mom\_last\_cos) -standardize(chasing\_mom\_allday)

  

**4.2 因子表现（周频）：**

（1）10分组单调性

![](assets/011.png)

（2） 10分组年均收益

![](assets/012.png)

（3）与常见风格因子的相关性

![](assets/013.png)

**4.3小结**

尾盘追涨偏离因子（chasing\_mom\_diff），自2017年2月至今（2024.5），周频RankIC-1.6%，年化ICIR-2.41，因子表现一般，相比于全时段因子和两个尾盘因子，其包含的增量信息较为有限。

  

**总结**

本文参考开源证券金工研报《从高频股价形态到追涨杀跌因子》的构建思路，基于股票日内分钟涨跌幅的自相关衡量股价追涨杀跌的形态特征，进而衡量个股交易中散户投资者交易占比，构建了4个负alpha因子。

  

其中，**尾盘追涨因子（chasing\_mom\_last\_cos），在全历史区间内（2017.2-2024.5）表现最佳，周频RankIC达-7.3%，年化ICIR为-3.77，因子分10组单调性尚可，空头负向alpha显著，与常见风格中的波动率、流动性及估值等因子具有一定相关性**。

  

另外，观察本文构建的4个因子之间的相关性，可知基于类似逻辑在不同时间段内（全时段或尾盘）构建的因子具有较高的相关关联，仅尾盘追涨偏离因子（chasing\_mom\_diff）与另外3因子的关联较低，同时该因子的增量信息也较为有限。

![](assets/014.png)

  

  

  

  

  

**数据及代码下载见星球**

  

加入星球请扫我：

![](assets/015.png)

  

  

  

入群请扫我：  

![](assets/016.jpg)

  

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

![](assets/017.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。