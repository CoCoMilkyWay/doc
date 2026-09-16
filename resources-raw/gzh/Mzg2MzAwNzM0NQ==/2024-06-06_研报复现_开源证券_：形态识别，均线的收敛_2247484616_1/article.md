# 研报复现 | 开源证券 ：形态识别，均线的收敛与发散

QuantML QuantML 2024-06-06 13:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=cf9a51c00d9a3f3348412aee59e47f947c3ae554961f9fdd12d95572d95a96a32d3118404197#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=cf9a51c00d9a3f3348412aee59e47f947c3ae554961f9fdd12d95572d95a96a32d3118404197#rd)

Content

  

本文来自星球嘉宾Hugo的研报复现系列，这期复现的研报为《开源证券-开源量化评论（91）：形态识别，均线的收敛与发散》，全部代码及数据见星球。

  

报告主要探讨了形态识别在金融量化分析中的应用，尤其是均线的收敛与发散形态对个股未来收益的预测能力研报。

  

复现的因子包括：

  

**价格收敛因子（PCF, Price Convergence Factor）：**

-   定义：基于不同周期（如5、10、20、60、120日）的价格均线标准差来衡量价格均线的收敛与发散。
    
-   目的：预测个股未来方向选择的概率，即变盘点的前兆。
    
-   方法：使用个股当日收盘价计算不同周期均线的标准差，并对结果进行取对数处理和取负操作。
    

  

**成交量收敛因子（VCF, Volume Convergence Factor）：**

-   定义：基于不同周期的成交量均线标准差来衡量成交量的收敛与发散。
    
-   目的：衡量市场上投资者交易意愿的变化，预测股价处于阶段底部的概率。
    
-   方法：与PCF类似，计算成交量的均线标准差。
    

  

**价量双收敛因子（PVCF, Price Volume Convergence Factor）：**

-   定义：结合价格收敛因子（PCF）和成交量收敛因子（VCF）来综合判断个股的状态。
    
-   目的：通过价格和成交量的收敛情况，判断个股是否处于变盘点前夕以及当前所处的位置高低。
    
-   方法：将PCF和VCF在截面进行标准化后加总。
    

  

**成交额收敛因子（ACF, Amount Convergence Factor）：**

-   定义：基于不同周期的成交额均线标准差来衡量成交额的收敛与发散。
    
-   目的：预测股票收益，考虑了价格与成交量的融合。
    
-   方法：计算成交额的均线标准差。
    

  

**换手率收敛因子（TRCF, Turnover Rate Convergence Factor）：**

-   定义：基于不同周期的换手率均线标准差来衡量换手率的收敛与发散。
    
-   目的：剔除量纲差异，刻画交易活跃度的相对水平，预测股票收益。
    
-   方法：计算换手率的均线标准差。
    

  

  

因子计算

### 价格的收敛与发散

不同周期价格均线之间的发散是常态, 而收敛通常仅出现在特定的窗口期。当 不同周期价格均线趋于收敛时, 往往代表市场上不同类型的投资者在个股上的持仓 成本逐渐趋同, 筹码分布更趋集中, 未来无论股价往上突破抑或往下下探, 此时个 股面临的阻力都相应下降。由于股价总是沿着阻力最小的方向运行, 我们倾向于认 为个股未来进行方向选择的概率提升, 即变盘点的前兆。

我们选取个股当日收盘价, 并计算不同周期下 (5、10、20、60、120 日) 的均 值, 计算 6 条均线之间在截面上的标准差。为使得因子值分布更接近正态分布, 我 们对结果进行取对数处理, 并通过取负操作使得因子值预测方向为正。为了避免价 格跳空现象, 我们使用后复权价格进行均线计算, 且在因子构建时未剔除截面上不 同个股价格数值的量纲差异。

factor为价格收敛因子 (Price Convergence Factor, PCF), 其中当日收盘价即为   。为便捷表述，下文存在中文名称与英文简写混用。

与研报不同的是我们并未对股票池去除ST及上述不如一年的剔除处理，也未对因子进行行业、市值的中性化处理。

```
import sysfrom pathlib import Pathsys.path.append(str(Path().cwd() / "FactorFactory"))from typing import Dict, Listimport matplotlib.pyplot as pltimport numpy as npimport pandas as pdfrom FactorArithmetic.convergence_factor import calculate_convergence_factorfrom src import standardlizefrom src.analyzer import FactorAnalyzerfrom src.data_provider import LoadH5Data# plt显示中文plt.rcParams["font.sans-serif"] = ["SimHei"]load_data: LoadH5Data = LoadH5Data()
```

```
def get_ashare_data(start_dt: str, end_dt: str, feilds: str) -> pd.DataFrame:    """    获取本地文件中获取数据。    参数:        start_dt (str): 开始日期，格式为YYYY-MM-DD。        end_dt (str): 结束日期，格式为YYYY-MM-DD。        feilds (str): 数据字段，用于指定要获取的数据。    返回:        pd.DataFrame: 获取到的A股数据。    示例:        >>> get_ashare_data('2022-01-01', '2022-01-31', 'close')               000001.SZ  000002.SZ  600000.SH  ...        date        2022-01-01     10.50      20.30      15.40        2022-01-02     10.60      20.40      15.50        ...    """    return load_data.get_data(        f"Dataset.{feilds}", start_date=start_dt, end_date=end_dt    ).filter(regex="^[036].*(SH$|SZ$)", axis=1)
```

```
START, END = "2014-01-01", "2023-12-31"  # 设置回测时间PERIODS: List[int] = [5, 10, 20, 60, 120]  # 计算因子所需间隔参数BEGIN: pd.Timestamp = load_data.get_shifted_trading_date(    START, -np.max(PERIODS))  # 前序计算期
```

```
# 获取收盘价数据close_df: pd.DataFrame = get_ashare_data(BEGIN, END, "adjclose")# 因子构建pcf_factor: pd.DataFrame = calculate_convergence_factor(close_df, PERIODS).loc[    START:END]
```

```
# 单因子分析pcf_far: FactorAnalyzer = FactorAnalyzer(    pcf_factor.stack().dropna(),    close_df.loc[START:END],    quantiles=10,    periods=(1,),)
```

测试期内 (下文如无特别说明, 测试区间均为 2014.01.01~2023.12.31), 价格收敛因子 (PCF) RankIC 均值仅为 表现乏善可陈。价格收敛因子虽然对未来个股收益率具有正向的预测能力, 但不可否认的是其表现 随市场环境的变化而有所波动, 如在 2013 年之前和 2017 年到 2020 年之间, 价格均线收敛的预测效果疲弱，2020年以来，超额收益又开始回归正常水平。

```
pcf_far.plot_ic_ts(method="rank")
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/001.png)

png

从收益表现来看, 各分组收益并非严格单调, 价格均线收敛的分组表现处于各分组收益的中游水平, 而价格均线发散的分组则长期稳定跑输。价格均线发散往往对应股价大幅拉涨和砸盘, 从结果来看, 行情趋势中追高和抄底都是不建议的操作。

```
pcf_far.plot_cumulative_returns_by_quantile()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/002.png)

png

```
pcf_far.plot_quantile_returns_bar()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/003.png)

png

回到我们关切的问题, 为什么价格均线收敛的收益预测能力表现疲弱? 我们认 为主要有两点原因:

第一, 价格均线收敛时, 既可以发生在股价低位, 亦可以在股价的阶段高点。若个股在股价低位发生价格均线收敛, 未来上涨的概率往往要高于处于阶段高点价 格均线收敛的个股。在 A 股市场, 反转易得, 动量难寻, 个股价格高低位的变化影 响了均线收敛的变盘胜率。

第二, 在市场整体处于强趋势行情的时候, 价格均线发散反而是一种强势信号,  此时在股价维度追逐动量相比博弈短期反转, 在盈亏比上具有优势, 其亦是不同市 场环境下价格收敛因子表现出现显著差异的直接影响因素。

二者因素叠加后, 价格均线收敛的选股区分度被相应弱化, 其在选股层面, 更 多作为一个变盘点的信号, 是个股选择方向的前兆, 但往上还是往下, 两者的概率 差异还处于较低水平。为此, 我们尝试引入股价当前位置高低的信息。

## 成交量的收敛与发散

前文我们探讨了股票价格均线收敛与发散所蕴含的选股能力, 但单纯的价格可 能存在欺骗性，没有成交量辅助的价格是镜中花、水中月，虚实难辨。仿照前文思 路, 我们尝试通过成交量均线的收敛与发散来刻画当前股价位置高低。

如何理解成交量的收敛与发散形态特征呢? 不同周期成交量均线的收敛发散衡 量了市场上投资者交易意愿的变化。当长短期成交量水平趋于一致时, 往往是因为 个股赚钱效应弱化, 导致投资者交易意愿下滑, 股价处于阶段底部的概率升高。因 为个股股价高涨, 行情过热时, 会吸引到市场上其他投资者的关注, 造成短期成交 量迅速放大从而超过长期的成交水平, 不同周期成交量均线呈现出发散的形态。

我们根据前文价格收敛因子(PCF)的构建方式来计算成交量收敛因子(Volume  Convergence Factor, VCF)。成交量收敛因子(VCF)全区间内RankIC均值为3.8%, 表现较好。

```
# 获取收盘价数据volume_df: pd.DataFrame = get_ashare_data(BEGIN, END, "volume")# 因子构建vcf_factor: pd.DataFrame = calculate_convergence_factor(volume_df, PERIODS).loc[    START:END]
```

```
# 单因子分析vcf_far: FactorAnalyzer = FactorAnalyzer(    vcf_factor.stack().dropna(),    close_df.loc[START:END],    quantiles=10,    periods=(1,),)
```

```
vcf_far.plot_ic_ts(method="rank")
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/004.png)

png

成交量收敛因子 (VCF) 在全区间内分组收益单调, 但是 2021 年以来, 多空超额收益的波动有所放大。测试结果一定程度上能够说明低位缩量的个股未来上涨的 概率显著高于高位放量的个股。

```
vcf_far.plot_cumulative_returns_by_quantile()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/005.png)

png

```
vcf_far.plot_quantile_returns_bar()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/006.png)

png

## 价与量的同频共振

上文中, 我们从价格均线形态出发讨论了股价面临变盘的可能, 从成交量均线 形态维度锚定了个股当前股价位置的高低水平。若将价量均线形态二者进行结合,  会发生怎样的化学反应呢?

通过将价与量进行融合, 我们希望通过价格均线收敛与否来判断个股当前时刻 是否位于变盘点前夕，通过成交量均线收敛与否来判断个股当前所处位置的高低。如果某只个股价格和成交量均线都处于收敛状态, 则我们倾向于认为该只股票处于 阶段低位且面临变盘的可能, 未来股价向上反转的概率大幅增加。反之, 若价量均 线双发散，表明投资者在赚钱效应的吸引下，短期内大幅涌入该只个股。

我们计算了价格收敛因子 (PCF) 与成交量收敛因子 (VCF) 二者在时序上的相 关性, 根据测试结果可知, PCF 与 VCF 呈现弱相关性, 全区间均值约为10.03%, 表明价格均线收敛与成交量均线收敛蕴含着不同的信息, 可以用来进行融合。

我们将 PCF 与 VCF 在截面进行标准化后进行加总, 构建价量双收敛因子 (Price  Volume Convergence Factor, PVCF)

```
# PCF\VCF截面标准化后合成PVCF因子pvcf_factor:pd.DataFrame = standardlize(pcf_factor) + standardlize(vcf_factor)
```

```
corr_ts:pd.Series = pcf_factor.corrwith(vcf_factor,method="spearman",axis=1)ax = corr_ts.plot(figsize=(18,4),title="时序相关性")ax.axhline(corr_ts.mean(),color="r")print(f"corr均值{corr_ts.mean():.4f}")
```

```
corr均值0.1013
```

![](assets/007.png)

png

```
# 单因子分析pvcf_far: FactorAnalyzer = FactorAnalyzer(    pvcf_factor.stack().dropna(),    close_df.loc[START:END],    quantiles=10,    periods=(1,),)
```

我们将 PCF 与 VCF 在截面进行标准化后进行加总, 构建价量双收敛因子 (Price  Volume Convergence Factor, PVCF)。在测试期内, 价量双收敛因子 (PVCF) 相比单 一价量因子, 表现有所提升, RankIC均值为 4%

```
pvcf_far.plot_ic_ts(method="rank")
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/008.png)

png

价量双收敛因子 (PVCF) 的五分组收益严格单调, 且近期超额收益走势依然稳 健, 价与量的融合有效地弥补了二者单独构建因子的不足。

```
pvcf_far.plot_cumulative_returns_by_quantile()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/009.png)

png

```
pvcf_far.plot_quantile_returns_bar()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/010.png)

png

# 另类均线的收敛与发散

市场中主流的交易终端软件中, 受限于页面大小, 通常仅展示个股价格和成交 量均线的相关信息, 而对于其他指标的均线覆盖和展示较少。虽然隐秘角落里的其 他指标不直观可见, 但却蕴含着重要的信息, 一如隐匿在海面之下的冰山才是冰山 的重要部分。

上文中, 我们探讨了个股价格均线和成交量均线的形态对未来股价的预测能力。但是实际上价格与成交量的融合, 一定程度上可以用个股成交额来替代。二者的差 异在于价与量的融合, 是通过因子值相加的方式, 而成交额则直接可通过价乘以量 计算得到, 那么成交额均线收敛是否具有股票收益预测能力呢?

## 成交额收敛因子

按照前文的因子构建方式, 我们测试了成交额收敛因子 (Amount Convergence  Factor, ACF) 的表现。全区间内, 成交额收敛因子 (ACF) RankIC 均值为4.9%, 相比与融合后的价量双收敛因子 (PVCF), 效果进一步提升。

```
# 获取成交额数据amount_df:pd.DataFrame = get_ashare_data(BEGIN, END, "amount")
```

```
# 计算因子acf_factor: pd.DataFrame = calculate_convergence_factor(amount_df, PERIODS).loc[    START:END]
```

```
# 单因子分析acf_far: FactorAnalyzer = FactorAnalyzer(    acf_factor.stack().dropna(),    close_df.loc[START:END],    quantiles=10,    periods=(1,),)
```

从收益表现来看, 成交额收敛因子 (ACF) 分组收益严格单调, 多头端收益和 多空收益相比价量双收敛因子（PVCF）均有提升。究其原因, 在于我们在因子构建的过程中, 刻意保留了个股在数据上的量纲差 异, 导致低成交额个股更容易被选中, 而成交额越低的个股对应的市场关注度往往越低。再者, 均线收敛与发散分别对应低波动与高波动的过程。那么当我们选取成 交额均线收敛的个股一定程度上类似于选取低波低关注度个股, 二者长期来看具有 超额收益获取能力。

```
acf_far.plot_ic_ts(method="rank")
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/011.png)

png

```
acf_far.plot_cumulative_returns_by_quantile()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/012.png)

png

```
acf_far.plot_quantile_returns_bar()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/013.png)

png

## 换手率收敛因子

如果将成交额视为个股交易活跃度高低的绝对量值, 那么换手率便是个股交易活跃度高低的相对水平。代表活跃度绝对量级的成交额表现可圈可点, 那么剔除量 纲差异刻画交易活跃度相对水平的换手率表现又如何呢? 为此, 我们尝试从换手率均线的收敛与发散形态入手, 构建换手率收敛因子 (Turnover Rate Convergence Factor,  TRCF)。

不同个股之间的换手率虽然不存在量纲差异, 但在A股市场中大市值个股相比小市值个股天然具有更低的换手率水平, 导致我们在进行换手率收敛因子计算的时候, 等价于给予大市值个股更高的隐含权重。成交额则恰好相反, 成交金额越大, 流通市值越高。

```
turn_df:pd.DataFrame = get_ashare_data(BEGIN, END, "turn")
```

```
trcf_factor: pd.DataFrame = calculate_convergence_factor(turn_df, PERIODS).loc[    START:END]
```

```
# 单因子分析trcf_far: FactorAnalyzer = FactorAnalyzer(    trcf_factor.stack().dropna(),    close_df.loc[START:END],    quantiles=10,    periods=(1,),)
```

```
trcf_far.plot_ic_ts(method="rank")
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/014.png)

png

从分组收益来看, 换手率收敛因子表现优异, 且超额收益率主要集中在多头端。

```
trcf_far.plot_cumulative_returns_by_quantile()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/015.png)

png

```
trcf_far.plot_quantile_returns_bar()
```

```
<Figure size 640x480 with 0 Axes>
```

![](assets/016.png)

png

通过对比上述五个因子的表现可知, 合成的PVCF相比单一因子在因子预测上稍有提升, 与原研报不同的是PVCF并未受PCF的拖累, 在因子稳定性上PVCF相比VCF有小幅增强。单指标构建的ACF和TRCF相比合成的PVCF, 预测能力进一步提升, 其中ACF表现最优。

```
def plot_ic_ir_chart(far_dict: Dict):    """    绘制IC和IR图表。    参数:    far_dict (Dict): 包含多个FactorAnalysisResult对象的字典。    返回:    无返回值，直接显示图表。    """    ic: List = [far.ic["period_1"].mean() for far in far_dict.values()]    ir: List = [        far.ic["period_1"].mean() / far.ic["period_1"].std()        for far in far_dict.values()    ]    df: pd.DataFrame = pd.DataFrame({"IC": ic, "IR": ir}, index=far_dict.keys())    ax = df["IC"].plot(kind="bar", color="blue", label="IC")    ax2 = ax.twinx()    df["IR"].plot(kind="line", color="red", ax=ax2, label="IR")    ax.figure.legend()    plt.show()
```

```
far_dict: Dict = {    "PCF": pcf_far,    "VCF": vcf_far,    "PVCF": pvcf_far,    "ACF": acf_far,    "TRCF": trcf_far,}plot_ic_ir_chart(far_dict)
```

```

```

![](assets/017.png)

png

  

  

  

数据及代码下载见星球

  

  

目前距离星球下次提价还有11个名额，欢迎扫码加入：

![](assets/018.png)

  

  

入群请扫我：  

![](assets/019.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
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

![](assets/020.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/021.jpg)