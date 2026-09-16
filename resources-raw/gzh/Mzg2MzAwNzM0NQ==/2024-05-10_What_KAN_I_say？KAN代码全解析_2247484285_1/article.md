# What KAN I say？KAN代码全解析

QuantML QuantML 2024-05-10 18:53 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=cf9fe891a124ee3c0720ae838ee2fb0452ee5b6372988ebe98926d4bc515b2aae64b150c97c5#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=cf9fe891a124ee3c0720ae838ee2fb0452ee5b6372988ebe98926d4bc515b2aae64b150c97c5#rd)

Content  

这两天KAN的热度逐渐退去，正好静下心来，研究代码。关于KAN，众人褒贬不一，我认同作者在github上的说法：

  

> I would like to welcome people to be critical of KANs, but also to be critical of critiques as well. Practice is the only criterion for testing understanding (实践是检验真理的唯一标准). We don't know many things beforehand until they are really tried and shown to be succeeding or failing. 
> 
> https://github.com/KindXiaoming/pykan

KAN在某些领域可能无法超越传统的深度MLP结构，但在量化领域，其简洁的架构和可解释性恰好弥补了传统神经网络的不足。

  

  

Talk is cheap, show me the code 

  

KAN的原理参考原论文，本文重点关注KAN代码的实现过程。KAN的代码框架主要由以下几个部分组成：

![](assets/001.png)

1.  Symbolic\_KANLayer: 这个类实现了一个符号激活层，它使用符号函数（如正弦、指数等）来代替传统的数值激活函数。层的每个神经元可以有一个符号函数，这些函数通过仿射变换与输入相联系。
    
2.  KANLayer: 这个类定义了一个基于样条函数的激活层，其中包含了样条函数的网格点、系数、以及激活函数的参数。它负责样条函数的前向传播、网格的更新和参数的共享与锁定。
    
3.  spline: 这个模块提供了一系列函数，用于处理B样条曲线，包括计算B样条基函数、从系数生成样条曲线，以及从样条曲线估计系数。
    
4.  LBFGS: 实现了L-BFGS算法的优化器类，用于在训练过程中对KAN模型的参数进行优化。
    
5.  KAN: 这是整个框架的核心，定义了KAN模型。它由多个`KANLayer`和`Symbolic_KANLayer`组成，支持前向传播、模式设置、符号激活函数的固定和建议、模型训练、剪枝、以及可视化等功能。
    

  

代码主体在KAN.PY中，网络的结构如下：

    `def forward(self, x):`    `'''`    `KAN forward``   `    `Args:`    `-----`        `x : 2D torch.float`            `inputs, shape (batch, input dimension)``   `    `Returns:`    `--------`        `y : 2D torch.float`            `outputs, shape (batch, output dimension)``   `    `Example`    `-------`    `>>> model = KAN(width=[2,5,3], grid=5, k=3)`    `>>> x = torch.normal(0,1,size=(100,2))`    `>>> model(x).shape`    `torch.Size([100, 3])`    `'''``   `    `self.acts = []  # shape ([batch, n0], [batch, n1], ..., [batch, n_L])`    `self.spline_preacts = []`    `self.spline_postsplines = []`    `self.spline_postacts = []`    `self.acts_scale = []`    `self.acts_scale_std = []`    `# self.neurons_scale = []``   `    `self.acts.append(x)  # acts shape: (batch, width[l])``   `    `for l in range(self.depth):``   `        `x_numerical, preacts, postacts_numerical, postspline = self.act_fun[l](x)``   `        `if self.symbolic_enabled == True:`            `x_symbolic, postacts_symbolic = self.symbolic_fun[l](x)`        `else:`            `x_symbolic = 0.`            `postacts_symbolic = 0.``   `        `x = x_numerical + x_symbolic`        `postacts = postacts_numerical + postacts_symbolic``   `        `# self.neurons_scale.append(torch.mean(torch.abs(x), dim=0))`        `grid_reshape = self.act_fun[l].grid.reshape(self.width[l + 1], self.width[l], -1)`        `input_range = grid_reshape[:, :, -1] - grid_reshape[:, :, 0] + 1e-4`        `output_range = torch.mean(torch.abs(postacts), dim=0)`        `self.acts_scale.append(output_range / input_range)`        `self.acts_scale_std.append(torch.std(postacts, dim=0))`        `self.spline_preacts.append(preacts.detach())`        `self.spline_postacts.append(postacts.detach())`        `self.spline_postsplines.append(postspline.detach())``   `        `x = x + self.biases[l].weight`        `self.acts.append(x)``   `    `return x`

  

  

Line 35 中的激活函数self.act\_fun是KAN的核心layer，初始化定义如下：

  

```
for l in range(self.depth):
```

  

  

KANLayer的定义在KANLayer.py当中，具体结构为：

  

```
def forward(self, x):
```

  

前面都是注释和reshape, 我们从Line 36开始解读。

![](assets/002.png)

Line 36：self.base\_fun默认为torch.nn.SiLU()， 对应的是论文中的2.11  

Line 37: coef2curve是spline.py中定义的将B 样条系数转换为 B 样条曲线的函数。这个函数使用最小二乘法来找到最佳拟合曲线， 对应论文中2.12中的spline(x)

Line 40: 对应论文中的2.10，代码与原论文稍有差别，实际在计算时，y通过以下公式计算：

![](assets/003.png)

其中scale\_base初始化为：

![](assets/004.png)

scale\_base和scale\_sp均为可训练参数  

  

至此KANLayer的核心部分已经实现。

  

再回到KAN的网络，L37-L41是KAN symbolic regression实现的过程，symbolic\_fun 的原理是使用预定义的一组符号函数（如正弦、指数、对数等）来近似神经网络中的激活函数，初始化为恒等函数。对应论文的2.5.1章节。在代码中通过suggest\_symbolic对比各结点的r2来确定对应的符号函数。

![](assets/005.png)

在L56中加入了偏置项biases，其中biases是没有bias的nn.Linear权重，biases会被广播到同层所有的x上，相当于对x整体平移，能够提高模型的拟合能力。

  

优化器：KAN支持Adam和LBFGS优化器，默认使用LBFGS， LBFGS 是一种拟牛顿法，它通过近似二阶导数来寻找局部最小值，通常用于对于小规模或中等规模的网络，或者当需要更精确的优化结果时。

  

KAN的作者目前也在积极完善代码当中，之前的一些小问题也逐渐得到修复，在量化中的表现可以参考我们[前期的文章](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484190&idx=1&sn=836ef4cef6c9183a51de163656cd13c5&chksm=ce7e6400f909ed16395bf0f07d9a201ee6c63e79e16130758acf964d81675dacd299e70c6166&scene=21#wechat_redirect)， 后续还会进一步优化，期待有更加优异的表现。  

  

欢迎大家入群交流  

  

![](assets/006.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

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

![](assets/007.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/008.jpg)