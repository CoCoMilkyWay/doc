# 走进gplearn——再谈遗传规划在因子挖掘中的运用

Mr.Bright 跟puppy玩量化 2022-12-22 20:15 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247484408&idx=1&sn=a21373513523cf9dc159c5fad1451d77&chksm=c120cf692f3f5ca751cafbbddbd6fc4091437e0a002dcdd29ac55b7515e1dbbc28f7d4dfdcc0#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484408&idx=1&sn=a21373513523cf9dc159c5fad1451d77&chksm=c120cf692f3f5ca751cafbbddbd6fc4091437e0a002dcdd29ac55b7515e1dbbc28f7d4dfdcc0#rd)

近期随着全国疫情政策的全面放开，全民免疫正在成为现实。面对这种放开，有支持的同时一定有人反对，事物的两面性体现在疫情和病毒演化中，当样本（整个人群）足够大，大数定理一定会被服从。

最终新冠和人类能否和谐共处我们不得而知，对于人体系统来说，免疫能力需要和病毒的进化之间达成一种均衡。我不是生物学/病毒学方面的专业人士，经过查资料得知人的免疫系统和病毒的进化之间存在一种均衡——以人的免疫系统为环境，病毒的各项能力作为指标，相互之间出现“角力”行为。

作为一个quant，我很自然地想起经常在使用的gplearn模块，该模块基于crossover、mutation and reproduction，用于基础因子之上，经过不同的算法组合，在大量运算和进化、变异及繁殖的过程中挖掘更强大的因子。

前期我曾在《更高效的因子挖掘方式——遗传规划及其实战应用》一文中介绍了gplearn模块及其基本原理和基础使用模式。

**一、重要参数及其选择**

![](assets/001.png)

gplearn.genetic中下设SymbolicTransformer，SymbolicRegressor和SymbolicClassifier三个模块，分别用于公式生成、模式回归和模式分类，其中regressor已经被证明优于lasso、ridge和xgboost。

在SymbolicTransformer模块中，如下参数极度重要，需要被严格关照：

1、init\_depth为公式深度，其默认参数为（2,6），也就是默认情况下公式组合最浅为2层，最深为6层。我测试该参数的结果如下所示：

![](assets/002.png)

可以很清晰地看到，当depth超过4时，组合算法过于复杂，可解释性令人质疑。对于笔者来说，认为该参数的最佳范围为（2,4）。

2、population，初始random生成公式的时候生成多少个，这个指标根据各自能够承受的时间和电脑的实际算力进行，一般上我会将这个指标设置为20万，36万或者50万，同时需要注意的是n\_jobs参数，如果选择的population比较大，建议把n\_jobs设置为-1，把电脑的核全部用上。

3、tournament\_size,它的大小与进化论中的选择压力息息相关：tournament\_size越小，选择压力越大，算法收敛的速度可能更快，但也有可能错过一些隐藏的优秀公式，这个公式是最难选择的，为每一个generation中，被选择至下一轮的因子数目。

4、n\_components，输出因子的数量，在这个过程中最终输出多少个因子，我采用的参数是如果population为10万个，最终输出100个因子，在进行分门别类测试。

**二、参数之外的核心基础要素**

1、feature\_names，也就是所选择的fields，一般上大家选择的fields是一些基础因子，比如最常见的是一些使用者把open，high，low，close，volume以及amount几个最为基础的指标输入进去，让gplearn以上述六个基础数据进行深度挖掘。这种模式并非不可以，但是很可能需要浪费大量的时间用于因子挖掘。在这个问题上，我建议还是先对上述数据进行初步处理，再做深度进化，是比较好的选择；

2、function\_set，该模块一般上分为init\_function和user\_function，其中init\_function主要是add，sub，mul，div，sqrt，log，inv，sin，cos，tan，max和min几个基础计算公式，但是user\_function是体现使用者算法功底的部分，也是见仁见智的部分，建议每位quant在这个部分深度发力；

3、metric，该模块为损失函数，也是非常核心的模块，默认函数为spearman或者pearson系数，如果挖掘出来的因子将使用于decision tree model，比较建议使用spearman作为metric损失函数。同时metric模块完全可以按照自己的需求设置损失函数，比如说gross return，sharpe ratio，sortino ratio等，将上述函数def好之后，在metric部分使用make\_function函数进行设置即可。

**三、遗传规划中最容易出错的部位**

1、field方面，绝不能仅仅是open，high，low，close，volume这样简单的基础数据，亲证这样输入的结果是garbage in，那么结果大概率是garbage out；

2、输入的field需进行滚动标准化，以去除其量纲对数据的影响，同时必须以事件驱动模式作为回测基础，否则会包含大量的未来信息，导致回测和实战之间产生缺口；  

3、gplearn为机器学习模型，那么该模型对于样本的要求是比较高的，10k以下样本的数据需要谨慎使用，否则会造成严重的过拟合；

4、在对dataset使用gplearn进行处理之前，仍然需要对齐进行严格的train-test划分，否则在测试数据的过程中会出现严重错误；

5、train部分数据预处理过程中，需要使用nan\_to\_num函数分别对x\_train和y\_train部分进行处理，否则在div或者idv算法中可能出现大量的np.inf或者-np.inf从而产生错误。

最后，道阻且长，无论是因子挖掘这条路，还是疫情的修复，都祝各位顺利，远离伤病，积极上分。