# Qlib学习分析（五）：绩效分析报表

FinTechHi FinTechHi 2023-07-28 23:43 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483852&idx=1&sn=70968642843e9eb776e3789966df7e07&chksm=fb7e113ea4d43b2f639a987b051ae0802a72c77f10a9f67e3936da6bee070dd46237cf1a24c6#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483852&idx=1&sn=70968642843e9eb776e3789966df7e07&chksm=fb7e113ea4d43b2f639a987b051ae0802a72c77f10a9f67e3936da6bee070dd46237cf1a24c6#rd)

再回顾下Qlib的回测过程：

```
回测开始：qlib.workflow.start
```

Qlib分析模块有两个部分：一是仓位分析，二是模型分析。源代码里路径是：import qlib.contrib.report。  

其中仓位分析包括：

```
report_graph
```

模型分析只有一个：

```
model_performance_graph
```

## 1、数据加载

完成策略回测后，调用qlib.contrib.report模块展示回测和绩效分析结果。执行qlib.workflow.get\_recorder获取回测结果，相关结果均储存为pkl格式。执行recorder.load\_object读取预测结果pred.pkl、回测报告report\_normal.pkl、仓位情况positions\_normal.pkl和持仓分析port\_analysis.pkl。

```
from qlib.contrib.report import analysis_model, analysis_positionfrom qlib.data import Drecorder = R.get_recorder(recorder_id=ba_rid, experiment_name="backtest_analysis")print(recorder)pred_df = recorder.load_object("pred.pkl")report_normal_df = recorder.load_object("portfolio_analysis/report_normal_1day.pkl")positions = recorder.load_object("portfolio_analysis/positions_normal_1day.pkl")analysis_df = recorder.load_object("portfolio_analysis/port_analysis_1day.pkl")
```

## 2、持仓分析

设置label

```
label_df = dataset.prepare("test", col_set="label")label_df.columns = ["label"]
```

持仓分析，主要展示回测净值走势图。其中统计维度主要包括：

-   不扣费、扣费和基准净值；
    
-   不扣费净值最大回撤、扣费净值最大回撤；
    
-   不扣费和扣费超额收益净值；
    
-   不扣费超额收益最大回撤；扣费超额收益最大回撤。
    
-   换手率；
    

```
analysis_position.report_graph(report_normal_df)
```

  

![](assets/001.png)

  

### 3、风险分析

```
analysis_position.risk_analysis_graph(analysis_df, report_normal_df)
```

  

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

![](assets/005.png)

![](assets/006.png)

## 4、score IC

```
pred_label = pd.concat([label_df, pred_df], axis=1, sort=True).reindex(label_df.index)analysis_position.score_ic_graph(pred_label)
```

IC即信息系数（Information Coefficient），表示所选股票的因子值与股票下期收益率的截面相关系数，通过 IC 值可以判断因子值对下期收益率的预测能力。\*\*信息系数的绝对值越大，该因子越有效。IC为负表示因子值越小越好，IC为正表示因子值越大越好。IC的计算方法是：计算全部股票在调仓周期期初排名和调仓周期期末收益排名的线性相关度（Correlation）。IC越大的因子，选股能力就越强。

IC最大值为1，表示该因子选股100%准确，对应的是排名分最高的股票，选出来的股票在下个调仓周期中，涨幅最大；相反，如果IC值为-1，则代表排名分最高的股票，在下个调仓周期中，跌幅最大，是一个完全反向的指标。

实际上，反向的指标也是非常有意义的。最无用的IC值是0或者接近0的值，这代表该因子对于股票没有任何的预测能力。当IC的绝对值大于0.03时（若要求更为严格，则限制在0.05），因子的选股能力较强。

由于IC的值是连续型，为了防止计算过程中由于因子值差距过大，所以发明了RankIC的计算，即某时点某因子在全部股票暴露值排名与其下期回报排名的截面相关系数，它与IC的区别就是将因子的具体值以及收益的具体值，都转换为了所对应的数值在其截面上的排序名次。然后通过计算排序值的相关系数，得到RankIC。

![](assets/007.png)

  

## 5、model performance

```
analysis_model.model_performance_graph(pred_label)
```

  

![](assets/008.png)

![](assets/009.png)

![](assets/010.png)

![](assets/011.png)

![](assets/012.png)

![](assets/013.png)

附：  

![](assets/014.jpg)

![](assets/015.png)