# 券商研报因子复现及表现研究

QuantML QuantML 2024-05-15 18:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=cf42914381264f20b72f511ca79bd0b4cce55fe7ceaab8c0e9aa1a624433a2805895c56b355d#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&chksm=cf42914381264f20b72f511ca79bd0b4cce55fe7ceaab8c0e9aa1a624433a2805895c56b355d#rd)

Content  

  

本文数据来自星友的券商研报复现项目：hugo2046/QuantsPlaybook: 量化研究-券商金工研报复现 (github.com)  欢迎加入星球交流。

复现研报因子，对其进行检验。

  

**研报信息：**  

  

项目名

参考

BullBearBattleFactorGenerator

2023-11-20\_方证证券\_-多因子选股系列研究之十二：股票日内多空博弈激烈程度度量与“多空博弈”因子构建——多因子选股

SalienceEffectFactorGenerator

方证证券-多因子选股系列研究之八：显著效应、极端收益扭曲决策权重和“草木 皆兵”因子|广发证券-行为金融研究系列之七：凸显理论之A股价量应用|20221214-招商证券-“青出于蓝”系列研究之四：行为金融新视角，“凸显性收益”因子STR|Salience theory and stock prices Empirical evidence

VolumeSurgeAtExtremesFactorGenerator

2023-12-19\_国盛证券\_金融工程\_“量价淘金”选股因子系列研究（四）：高、低位放量：从事件驱动到选股因子

TractionFactorGenerator

2023-12-19\_开源证券\_金融工程\_开源量化评论（83）：从隔夜价格行为到股票关联网络

IndustryCoMomFactorGenerator

2024-01-09\_国信证券\_金融工程\_联合动量因子：个股与行业的共振

SportBettingFactorGenerator

20220611-方正证券-多因子选股系列研究之四：个股动量效应识别及“球队硬币”因子构建

ModerateRiskFactorGenerator

20220412-方正证券-多因子选股系列研究之一：成交量激增时刻蕴含的alpha信息

TideFactorGenerator

20220508-方正证券-多因子选股系列研究之二：个股成交量的潮汐变化及“潮汐”因子构建

ConvergenceFactorGenerator

20240414-开源证券-开源量化评论（91）：形态识别，均线的收敛与发散

  

**因子信息：  
**

  

序号

项目名

类名

因子名

因子中文名称

说明

1

BullBearBattleFactorGenerator

VolumeBattleReturnFactor

daily\_vol\_battle\_return\_factor

日成交量博弈-收益率因子

frequency:minutes

2

BullBearBattleFactorGenerator

VolumeBattleReturnFactor

avg20\_vol\_battle\_return\_factor

20日均成交量博弈-收益率因子

frequency:minutes

3

BullBearBattleFactorGenerator

VolumeBattleReturnFactor

std20\_vol\_battle\_return\_factor

20日稳成交量博弈-收益率因子

frequency:minutes

4

BullBearBattleFactorGenerator

VolumeBattleReturnFactor

**vol\_battle\_return\_factor**

**成交量博弈-收益率因子**

frequency:minutes

5

BullBearBattleFactorGenerator

VolumeBattleRelativeFactor

daily\_vol\_battle\_relative\_pos\_factor

日成交量博弈-日内相对位置因子

frequency:minutes

6

BullBearBattleFactorGenerator

VolumeBattleRelativeFactor

avg20\_vol\_battle\_relative\_pos\_factor

20日均成交量博弈-日内相对位置因子

frequency:minutes

7

BullBearBattleFactorGenerator

VolumeBattleRelativeFactor

std20\_vol\_battle\_relative\_pos\_factor

20日稳成交量博弈-日内相对位置因子

frequency:minutes

8

BullBearBattleFactorGenerator

VolumeBattleRelativeFactor

vol\_battle\_relative\_pos\_factor

成交量博弈-日内相对位置因子

frequency:minutes

9

BullBearBattleFactorGenerator

VolumeBattleFactor

**vol\_battle\_factor**

**成交量博弈因子**

frequency:minutes

10

BullBearBattleFactorGenerator

AmplitudeBattleFactor

daily\_range\_battle\_factor

日振幅博弈因子

frequency:minutes

11

BullBearBattleFactorGenerator

AmplitudeBattleFactor

avg20\_range\_battle\_factor

20日均振幅博弈因子

frequency:minutes

12

BullBearBattleFactorGenerator

AmplitudeBattleFactor

std20\_range\_battle\_factor

20日稳振幅博弈因子

frequency:minutes

13

BullBearBattleFactorGenerator

AmplitudeBattleFactor

**range\_battle\_factor**

**振幅博弈因子**

frequency:minutes

14

BullBearBattleFactorGenerator

BullBearBattleFactor

**bull\_bear\_battle\_factor**

**多空博弈因子**

frequency:minutes

15

SalienceEffectFactorGenerator

OriginSalienceFactor

daily\_original\_salience

  

frequency:daily

16

SalienceEffectFactorGenerator

OriginSalienceFactor

**original\_salience**

**凸显度因子**

frequency:daily，(原始论文构造方式)

17

SalienceEffectFactorGenerator

SalienceTrunover

daily\_stv

  

frequency:daily

18

SalienceEffectFactorGenerator

SalienceTrunover

**STV**

**凸显度因子**

frequency:daily，广发证券构造方式

19

SalienceEffectFactorGenerator

AnxietyFactor

anxiety\_score

惊恐分

frequency:daily

20

SalienceEffectFactorGenerator

AnxietyFactor

anxiety\_wscore

加权决策分

frequency:daily

21

SalienceEffectFactorGenerator

AnxietyFactor

anxiety\_ret

惊恐收益

frequency:daily

22

SalienceEffectFactorGenerator

AnxietyFactor

anxiety\_vol

惊恐波动

frequency:daily

23

SalienceEffectFactorGenerator

AnxietyFactor

**origin\_anxiety**

**原始惊恐因子**

frequency:daily,方正证券构造方式

24

SalienceEffectFactorGenerator

AnxietyVolatilityFactor

anxiety\_vol\_wscore

波动率加剧-加权决策分

frequency:mix

25

SalienceEffectFactorGenerator

AnxietyVolatilityFactor

anxiety\_vol\_ret

波动率加剧-惊恐收益

frequency:mix

26

SalienceEffectFactorGenerator

AnxietyVolatilityFactor

anxiety\_vol\_vol

波动率加剧-惊恐波动

frequency:mix

27

SalienceEffectFactorGenerator

AnxietyVolatilityFactor

**anxiety\_volatility**

**波动率加剧-惊恐**

frequency:mix

28

SalienceEffectFactorGenerator

AnxietyIndividualInvestorRatio

anxiety\_individual\_investor\_wscore

个人投资者交易占比-加权决策分

frequency:daily

29

SalienceEffectFactorGenerator

AnxietyIndividualInvestorRatio

anxiety\_individual\_investor\_ret

个人投资者交易占比-收益率

frequency:daily

30

SalienceEffectFactorGenerator

AnxietyIndividualInvestorRatio

**anxiety\_individual\_investor\_vol**

**个人投资者交易占比-波动率**

frequency:daily

31

SalienceEffectFactorGenerator

AnxietyAttentionDecayFactor

anxiety\_attentiondecay\_wscore

注意力衰减-加权平均分数

frequency:daily

32

SalienceEffectFactorGenerator

AnxietyAttentionDecayFactor

anxiety\_attentiondecay\_ret

注意力衰减-收益率

frequency:daily

33

SalienceEffectFactorGenerator

AnxietyAttentionDecayFactor

anxiety\_attentiondecay\_vol

注意力衰减-波动率

frequency:daily

34

SalienceEffectFactorGenerator

AnxietyAttentionDecayFactor

anxiety\_attentiondecay

注意力衰减-惊恐度

frequency:daily

35

SalienceEffectFactorGenerator

AnxietyIndividualInvestorRatio

**anxiety\_individual\_investor\_ratio**

**个人投资者交易占比-惊恐**

frequency:daily

36

SalienceEffectFactorGenerator

HyperVigilanceFactor

hypervigilance\_wscore

草木皆兵因子-加权平均分数

frequency:mix

37

SalienceEffectFactorGenerator

HyperVigilanceFactor

hypervigilance\_ret

草木皆兵因子-收益率

requency:mix

38

SalienceEffectFactorGenerator

HyperVigilanceFactor

hypervigilance\_vol

草木皆兵因子-波动率

requency:mix

39

SalienceEffectFactorGenerator

HyperVigilanceFactor

**hypervigilance**

**草木皆兵因子**

requency:mix

40

VolumeSurgeAtExtremesFactorGenerator

LocalTurnoverProportionFactor

**local\_turnover\_proportion**

**局部换手率占比因子**

frequency:daily

41

VolumeSurgeAtExtremesFactorGenerator

LocalVolatilityProportionFactor

**local\_volatility\_proportion**

**局部波动率占比因子**

frequency:mix

42

VolumeSurgeAtExtremesFactorGenerator

HighVolatilityFactor

**high\_volatility\_proportion**

**分钟\_高位波动占比**

frequency:mix

43

VolumeSurgeAtExtremesFactorGenerator

LowVolatilityFactor

**low\_volatility\_proportion**

**分钟\_低位波动占比**

frequency:mix

44

TractionFactorGenerator

TractionORFactor

**traction\_or**

**隔夜关联网络 牵引因子**

frequency:daily

45

IndustryCoMomFactorGenerator

ICMFactor

**icm**

**行业联合动量因子**

frequency:daily

46

IndustryCoMomFactorGenerator

VICMFactor

**vicm**

**量价齐升行业联合动量因子**

frequency:daily

47

IndustryCoMomFactorGenerator

ICRFactor

**icr**

**行业联合反转因子**

frequency:daily

48

IndustryCoMomFactorGenerator

VICRFactor

**vicr**

**量价齐跌行业联合反转 因子**

frequency:daily

49

IndustryCoMomFactorGenerator

CMCFactor

**cmc**

**行业 联合动量复合因子**

frequency:daily

50

SportBettingFactorGenerator

SportBettingsFactor

interday\_volatility\_reverse

日间波动率反转

frequency:daily

51

SportBettingFactorGenerator

SportBettingsFactor

intraday\_volatility\_reverse

日内波动率反转

frequency:daily

52

SportBettingFactorGenerator

SportBettingsFactor

overnight\_volatility\_reverse

隔夜波动率反转

frequency:daily

53

SportBettingFactorGenerator

SportBettingsFactor

interday\_turnover\_rate\_reverse

日间换手率反转

frequency:daily

54

SportBettingFactorGenerator

SportBettingsFactor

intraday\_turnover\_rate\_reverse

日内波动率反转

frequency:daily

55

SportBettingFactorGenerator

SportBettingsFactor

overnight\_turnover\_rate\_reverse

隔夜波动率反转

frequency:daily

56

SportBettingFactorGenerator

SportBettingsFactor

interday\_turnover\_rate\_f\_reverse

日间自由换手率反转

frequency:daily

57

SportBettingFactorGenerator

SportBettingsFactor

intraday\_turnover\_rate\_f\_reverse

日内自由换手率反转

frequency:daily

58

SportBettingFactorGenerator

SportBettingsFactor

overnight\_turnover\_rate\_f\_reverse

隔夜自由换手率反转

frequency:daily

59

SportBettingFactorGenerator

SportBettingsFactor

revise\_interday\_reverse

修正日间反转

frequency:daily

60

SportBettingFactorGenerator

SportBettingsFactor

revise\_intraday\_reverse

修正日内反转

frequency:daily

61

SportBettingFactorGenerator

SportBettingsFactor

revise\_overnight\_reverse

修正隔夜反转

frequency:daily

62

SportBettingFactorGenerator

SportBettingsFactor

revise\_interday\_f\_reverse

修正日间反转（自由换手率）

frequency:daily

63

SportBettingFactorGenerator

SportBettingsFactor

revise\_intraday\_f\_reverse

修正日内反转（自由换手率）

frequency:daily

64

SportBettingFactorGenerator

SportBettingsFactor

revise\_overnight\_f\_reverse

修正隔夜反转（自由换手率）

frequency:daily

65

SportBettingFactorGenerator

SportBettingsFactor

**coin\_team**

**球队硬币因子**

frequency:daily

66

SportBettingFactorGenerator

SportBettingsFactor

**coin\_team\_f**

**球队硬币因子(自由换手率)**

frequency:daily

67

SportBettingFactorGenerator

VolatilityMomentum

interday\_lowvolatility\_momentum

  

frequency:daily

68

SportBettingFactorGenerator

VolatilityMomentum

intraday\_lowvolatility\_momentum

  

frequency:daily

69

ModerateRiskFactorGenerator

GlareVolatilityFactor

moderate\_glare\_volatility\_avg

月均耀眼波动率

frequency:minutes

70

ModerateRiskFactorGenerator

GlareVolatilityFactor

moderate\_glare\_volatility\_std

月稳耀眼波动率

frequency:minutes

71

ModerateRiskFactorGenerator

GlareVolatilityFactor

**moderate\_glare\_volatility**

**月 耀眼波动率**

**f**requency:minutes

72

ModerateRiskFactorGenerator

GlareReturnsFactor

moderate\_glare\_returns\_avg

月均耀眼收益率

frequency:minutes

73

ModerateRiskFactorGenerator

GlareReturnsFactor

moderate\_glare\_returns\_std

月稳耀眼收益率

frequency:minutes

74

ModerateRiskFactorGenerator

GlareReturnsFactor

**moderate\_glare\_returns**

**月耀眼收益率**

frequency:minutes

75

ModerateRiskFactorGenerator

ModerateRiskFactor

**moderate\_risk**

**适度冒险**

frequency:minutes

76

TideFactorGenerator

FullTideFactor

full\_tide\_factor

全潮汐因子

frequency:minutes

77

TideFactorGenerator

StrongSemiTideFactor

strongsemi\_tide\_factor

强势半潮因子

frequency:minutes

78

TideFactorGenerator

WeakSemiTideFactor

weaksemi\_tide\_avg

激进弱势 半潮汐因子

frequency:minutes

79

TideFactorGenerator

WeakSemiTideFactor

weaksemi\_tide\_std

稳定弱势半潮汐

frequency:minutes

80

TideFactorGenerator

CompleteTideFactor

**complete\_tide\_factor**

**完整潮汐因子**

frequency:minutes

81

ConvergenceFactorGenerator

CloseConvergenceFactor

**ccf**

**价格收敛因子**

frequency:daily

82

ConvergenceFactorGenerator

VolumeConvergenceFactor

**vcf**

**成交量收敛因子**

frequency:daily

83

ConvergenceFactorGenerator

AmountConvergenceFactor

**acf**

**成交收敛因子**

frequency:daily

84

ConvergenceFactorGenerator

TurnoverConvergenceFactor

tcf

**换手率收敛因子**

frequency:daily

85

ConvergenceFactorGenerator

FreeTurnoverConvergenceFactor

**ftcf**

**自由流通换手率因子**

frequency:daily

**因子表现：**

  

ICIR表现最好的因子为moderate\_glare\_volatility\_avg(月均耀眼波动率)，达到了6.62

  

  

factor

ic

ir

0

ACF

0.0727

4.4241

1

CCF

0.0313

1.6867

2

FTCF

0.0639

2.9775

3

STV

\-0.0307

\-2.961

4

TCF

0.0588

2.5403

5

VCF

0.0534

2.8318

6

anxiety\_attentiondecay

\-0.0469

\-2.9617

7

anxiety\_attentiondecay\_ret

\-0.0628

\-4.0112

8

anxiety\_attentiondecay\_vol

\-0.0622

\-3.1721

9

anxiety\_individual\_investor\_ratio

\-0.0722

\-4.0473

10

anxiety\_individual\_investor\_ret

\-0.0534

\-3.0125

11

anxiety\_individual\_investor\_vol

\-0.0666

\-3.3811

12

anxiety\_ret

\-0.0603

\-3.2744

13

anxiety\_score

\-0.0431

\-3.4845

14

anxiety\_vol\_ret

\-0.0621

\-3.5764

15

anxiety\_vol\_vol

\-0.0651

\-2.9625

16

anxiety\_volatility

\-0.0698

\-3.452

17

avg20\_range\_battle\_factor

\-0.0436

\-2.9453

18

avg20\_vol\_battle\_relative\_pos\_factor

\-0.0533

\-3.2208

19

avg20\_vol\_battle\_return\_factor

\-0.0518

\-3.1642

20

bull\_bear\_battle\_factor

\-0.0626

\-4.3973

21

cmc

0.009

0.9353

22

coin\_team

\-0.0647

\-4.7032

23

coin\_team\_f

\-0.0656

\-4.8251

24

complete\_tide\_factor

\-0.0321

\-3.0017

25

daily\_range\_battle\_factor

\-0.0524

\-4.1005

26

daily\_stv

\-0.0707

\-3.2503

27

daily\_vol\_battle\_relative\_pos\_factor

0.0285

2.5489

28

full\_tide\_factor

\-0.0536

\-4.0432

29

high\_volatility\_proportion

\-0.0537

\-5.1611

30

hypervigilance

\-0.0468

\-3.0215

31

hypervigilance\_ret

\-0.0613

\-3.9747

32

hypervigilance\_vol

\-0.0577

\-2.8979

33

icm

0.0048

0.4952

34

icr

\-0.0097

\-0.7002

35

interday\_lowvolatility\_momentum

0.0183

0.7941

36

interday\_turnover\_rate\_f\_reverse

\-0.0615

\-4.445

37

interday\_turnover\_rate\_reverse

\-0.0604

\-4.2865

38

interday\_volatility\_reverse

\-0.0349

\-3.0596

39

intraday\_lowvolatility\_momentum

0.0193

0.9189

40

intraday\_turnover\_rate\_f\_reverse

0.0025

0.4048

41

intraday\_turnover\_rate\_reverse

\-0.0495

\-3.9346

42

local\_turnover\_proportion

\-0.0508

\-3.098

43

local\_volatility\_proportion

\-0.0347

\-2.4864

44

low\_volatility\_proportion

\-0.0454

\-4.1328

45

moderate\_glare\_returns

\-0.0668

\-4.5925

46

moderate\_glare\_returns\_avg

\-0.0682

\-4.4955

47

moderate\_glare\_returns\_std

\-0.0633

\-4.6473

48

moderate\_glare\_volatility

\-0.0604

\-6.6249

49

moderate\_glare\_volatility\_avg

\-0.0511

\-5.2509

50

moderate\_glare\_volatility\_std

\-0.0645

\-5.1569

51

moderate\_risk

\-0.0708

\-6.0285

52

origin\_anxiety

\-0.0712

\-3.5785

53

original\_salience

\-0.0778

\-5.5053

54

overnight\_turnover\_rate\_f\_reverse

0.0033

0.52

55

overnight\_turnover\_rate\_reverse

\-0.0424

\-3.9965

56

range\_battle\_factor

\-0.0533

\-3.479

57

revise\_interday\_f\_reverse

\-0.0639

\-4.7824

58

revise\_interday\_reverse

\-0.063

\-4.6589

59

revise\_intraday\_f\_reverse

\-0.0557

\-4.4122

60

revise\_intraday\_reverse

\-0.055

\-4.3024

61

revise\_overnight\_f\_reverse

\-0.0289

\-3.3156

62

revise\_overnight\_reverse

\-0.0287

\-3.2852

63

std20\_range\_battle\_factor

\-0.0594

\-3.8337

64

std20\_vol\_battle\_relative\_pos\_factor

\-0.0551

\-3.4603

65

std20\_vol\_battle\_return\_factor

\-0.0542

\-3.4204

66

strongsemi\_tide\_factor

\-0.0265

\-2.7736

67

traction\_or

0.0139

1.241

68

vicm

0.0003

0.0266

69

vicr

\-0.011

\-0.7975

**部分因子多空收益：**  

**ACF(**成交收敛因子**):**

  

![](assets/001.png)

  

**FTCF(**自由流通换手率因子**):**

![](assets/002.png)

  

**original\_salience(**凸显度因子**):**

![](assets/003.png)

  

**moderate\_risk(**适度冒险**):**

![](assets/004.png)

**moderate\_glare\_volatility\_avg(月均耀眼波动率):**

![](assets/005.png)

因子下载及完整因子表现见星球。  

  

  

欢迎入群交流：  

![](assets/006.jpg)

  

往期回顾

       QuantML-Qlib开发版：

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