# 波段识别的全新智能算法（上篇）——传统方法简介、数据预处理

蝴蝶量化 随率而动的因子工厂 2026-02-24 15:59 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484499&idx=1&sn=7fdbce7ec1f0293a351e1a261b613b11&chksm=c062cdcf3cbbc68b5733cdfe7aea07ac036c02ca8a6572d62bb60770c7ac376b7d86dcd0a9b6#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484499&idx=1&sn=7fdbce7ec1f0293a351e1a261b613b11&chksm=c062cdcf3cbbc68b5733cdfe7aea07ac036c02ca8a6572d62bb60770c7ac376b7d86dcd0a9b6#rd)

## 技术背景

之前的文章我们介绍了一些形态的识别算法，但是都因为某些形态的特殊性，识别算法仅仅对特殊形态有效。那么设计一款普适性的算法就成了一个比较重要的事情。

技术指标分析有三大假设：1、市场包容消化一切、2、价格以趋势的方式重演、3、历史会重演。

波段形态的识别正是建立在这些的假设上，分析过去的图形，寻找出最为相似的的走势，总结规律（概率），最后在这些概率的基础上对未来做出预测。

作为自身交易员的你一定听过波浪理论，也一定听说多千人千浪。所以，这套理论本质上来讲，就是为行情找解释。当然，其中也有一些很明确的结论，其中本文用到的结论，以上涨的波浪为例：

-   1、3、5浪的高点依次上升。
    
-   2、4 浪的高点也是依次上升。
    

**既然如此，我们在识别了1浪后，在3浪的开始阶段持有标的，等待3浪上涨过了1浪高点后，回调某个固定比例卖出平仓即可。如下图：**

![](assets/001.png)

**策略目标就是:** 在点**“1”** 时，需要做下面的事：

-   **1、形态识别** 有效的识别出目前的走势形体，并且找出历史中所有标的中与目前类似形态。
    
-   **2、计算概率** 在上一步中的所有形态中，未来涨幅会超过点**a**的概率。
    
-   **3、构建策略买点：** 如果概率超过某个阈值，那么在1处买入标的。
    
-   **4、构建策略卖点：** 如果后期价格超过点a，那么回撤某个阈值\*\*\*\* ，择平仓。当然也存在价格涨不过a点的情况，从高点回撤超过“\*\*\*\*”
    

综上所述：本文的内容，就是给出一种能够识别波段形态的算法，并且在这个识别算法下，我们可以给出目前形态，在历史中上涨、下跌的概率，并且以此为依据给出一些择时策略、选股策略。

**本文的思路源自于券商研报，做了一些改进、代码编写等工作，由于篇幅原因，本内容分为上、中、下两篇：**

-   **上篇：** 传统方法简介与新方法的数据预处理。
    
-   **中篇：** 主要内容为形态识别的新方法，包括：
    

-   常用识别方法简介
    
-   新识别算法原理、测试、部分代码
    

-   **下篇：** 主要内容为策略的构建与测试
    

## 基本知识

### 什么是波段

波浪理论与道氏理论中对于股价走势，最原始的单元就是Z字形波浪走势。所有的波浪走势，都是有Z字形态构成。因此，本文也是以识别Z字形波段为目标。

下面是一些Z字形波，所构成的一些你熟悉的图形：

**1、头肩顶形态：**

![](assets/002.png)显然是由两个Z字形态构成。

**2、M头形态：**

![](assets/003.png)多个Z字形态构成

**3、5浪上涨形态**![](assets/004.png)显然也是Z字形波构成。

**其他形态这里不一一列举**，相信各位小伙伴已经了解了什么是波段了。

## 识别方法

在技术分析中，普遍认同的观点：**价格在空间上变化重要性大于时间变化的重要性。** 所以我们在构建识别算法时，应该更加重视价格变化。

### 传统识别方法

目前最常用的相似性匹配策略大多数采用的固定时间窗口，然后在历史数据中进行相似性匹配。

**算法：**

-   1、将价格数据，正规标准化
    
-   2、在空间中计算欧式距离，或者计算两者的相关性。
    

**局限性：**

-   1、固定大小的窗口使得空间价格变化受制于时间窗口的限制，导致 空间上的欧氏距离的识别效果往往不佳。
    
-   2、两个相似的走势，高低点对应的时间点不同，会使得欧氏距离时间效果不佳。会将两个相似的图形，识别不出来。
    
-   3、技术分析中，价格Z字波浪中各个高点、低点的相对位置也比较重要。高点一次向上，说明多头占上风，反之亦然。但是，在传统的欧式距离识别方法中，这种对于高点的相对位置并没有做出明确的判断。
    

**接下来，我们将介绍一种能够有效解决上述缺点的识别方法。**

### 新方法

下面是新方法的思维导图，参考了券商研报：

![](assets/005.png)

#### 第一步：Boll带归一化处理

有别于传统的识别技术中，直接对原始的收盘价做标准化处理。在新的识别技术中，我们采用boll线的上下轨道对原始的收盘价，做归一化处理。

**归一化优点**

相比于股票价格，%b指标具有以下优点：

-   指标的趋势与价格的变化相同，价格下降时，%b同步下降，没有延迟性。
    
-   相比于价格变化，%b指标的值为标准化，正常情况下位于-1至2之间，这样我们可以指定广为适用的标准化数据加工程序。避免了股价波动的噪声
    
-   %b指标对于股票波动具有放大的作用，能够适时而敏感地检测股票的波动，缩短点位确认的滞后时间。
    

**计算方法**

收盘价下轨线上轨线下轨线

**结果展示**通过归一化后

![](assets/006.png)

#### 第二步：确定高低点（ZIG分割）

显然，通过上面的转化之后，我们并不能清楚的看到哪些是满足条件的顶点，这就需要一个很关键的技术：**ZIG分割**。

很多小伙伴觉得ZIG是带有未来函数的，东西，但是这里完全可以通过时间推移将未来的信息剔除。请大家放心，本文中的所有结论，不存在未来函数情形。

**1、具体计算方法：**

如下图：

![](assets/007.png)

假设当前点位为点3，我们以点3为起始点，若后续点位为上涨，则向后移动，增加窗口大小，点7和点8高度相同，我们以后一点位为高点。点9和点10则均低于先前点位，但当前点为点10时，该点到最高点的距离超过了我们事先设定的阈值 ()，故我们以点10为该窗口的结束点。

同理，点8将成为下一个分割的起始点，然后我们开始下一次划分。由此我们得到Z字形分割。此处，点8至点10为确认一个可能的高点或低点所需的时间,如下图:

![](assets/008.png)

**2、数学公式**

给定当前点 ，则该窗口的高点  满足如下条件：

1.   是当前窗口的最大值。
    

3.   是满足以上两个条件的最后一个点。
    

**3、效果展示**

经过计算后得到下面的效果转化图：

![](assets/009.png)

#### 第三步：指标线的裁剪

虽然，我们通过ZIG转向计算之后，亦然存在较多的噪音，所以我们需要引入第二个阈值。当点4高度高于点2，并且点3相较于点2跌幅小于阈值。那么我们认为趋势没有改变，在高低点钟，删除点2、3，直接链接1-4点。如下图：

![](assets/010.png)

反之，下跌趋势中的波段，亦是如此。经过这一步裁剪后，得到的形态图像为：

![](assets/011.png)

#### 第四步：原始数据裁剪

我们将上一步得到的裁剪数据，通过b%的指标的计算公式，映射会原始价格数据，得到下面的图像：

![](assets/012.png)可以看到，亦然存在一些噪声，为了减少噪声，我们对上面的图像进行进一步的裁剪，得到下面的图像：

![](assets/013.png)

趋势一目了然。

#### 流程总结

![](assets/014.png)

## 代码

`    import numpy as np   import pandas as pd   import plotly.graph_objects as go   from plotly.subplots import make_subplots   from typing import List, Tuple, Dict   import warnings   warnings.filterwarnings('ignore')      # ====================== 参数配置 ======================   BB_WINDOW = 20          # 布林带窗口   BB_STD = 2              # 标准差倍数   ZIG_THRESHOLD = 0.005   # ZIG分割阈值δ₁ (0.5%)   TRIM_THRESHOLD = 0.003  # 裁剪阈值δ₂ (0.3%)   SIMILARITY_GAMMA = 0.1  # 相似距离阈值γ   PREDICT_EPSILON = 0.005 # 趋势判断阈值ε   STOP_LOSS = 0.005       # 止损比例   LOOKBACK_WINDOW = 4     # 匹配波段长度（包含几个端点）      # ====================== 数据加载 ======================   def load_data(file_path: str) -> pd.DataFrame:       """加载本地CSV文件，需包含日期、开盘、最高、最低、收盘"""       df = pd.read_csv(file_path, parse_dates=['date'])       df.sort_values('date', inplace=True)       df.reset_index(drop=True, inplace=True)       return df      # ====================== 技术指标 ======================   def compute_bollinger_bands(close: pd.Series, window: int = BB_WINDOW, std: int = BB_STD) -> pd.DataFrame:       """计算布林带及%b指标"""       ma = close.rolling(window).mean()       std_ = close.rolling(window).std()       upper = ma + std * std_       lower = ma - std * std_       b = (close - lower) / (upper - lower)  # %b指标       return pd.DataFrame({'close': close, 'ma': ma, 'upper': upper, 'lower': lower, 'b': b})      # ====================== ZIG分割与裁剪 ======================   def zig_segment(series: pd.Series, threshold: float) -> List[Tuple[int, float, str]]:       """       ZIG分割：识别转折点       返回列表[(索引, 值, 类型)]，类型为'peak'或'trough'       """       points = []       if len(series) < 2:           return points              # 初始方向：由前两个点决定       idx0, val0 = 0, series.iloc[0]       idx1, val1 = 1, series.iloc[1]       direction = 1 if val1 > val0 else -1  # 1上涨，-1下跌       last_peak_trough_idx = idx0 if direction == 1 else idx1  # 暂存极值点索引              for i in range(2, len(series)):           val = series.iloc[i]           if direction == 1:  # 当前在上涨段，寻找新的高点               if val > series.iloc[last_peak_trough_idx]:                   last_peak_trough_idx = i               elif val <= series.iloc[last_peak_trough_idx] - threshold:                   # 从高点回撤超过阈值，确认高点                   points.append((last_peak_trough_idx, series.iloc[last_peak_trough_idx], 'peak'))                   direction = -1                   last_peak_trough_idx = i           else:  # 当前在下跌段，寻找新的低点               if val < series.iloc[last_peak_trough_idx]:                   last_peak_trough_idx = i               elif val >= series.iloc[last_peak_trough_idx] + threshold:                   # 从低点反弹超过阈值，确认低点                   points.append((last_peak_trough_idx, series.iloc[last_peak_trough_idx], 'trough'))                   direction = 1                   last_peak_trough_idx = i       # 最后一个点作为终点（类型根据方向推断）       if direction == 1:           points.append((len(series)-1, series.iloc[-1], 'peak'))  # 若最后方向向上，终点为peak       else:           points.append((len(series)-1, series.iloc[-1], 'trough'))       return points      def trim_zig(points: List[Tuple[int, float, str]], threshold: float) -> List[Tuple[int, float, str]]:       """       裁剪：合并幅度小于threshold的相邻波动       算法：循环检查相邻点幅度，若小于阈值则删除中间点       """       if len(points) < 3:           return points       trimmed = points[:]       changed = True       while changed:           changed = False           i = 1           while i < len(trimmed)-1:               prev = trimmed[i-1]               curr = trimmed[i]               nxt = trimmed[i+1]               # 计算当前波动幅度               amp = abs(curr[1] - prev[1])               if amp < threshold:                   # 删除当前点，连接前后                   del trimmed[i]                   changed = True                   continue               i += 1       return trimmed      def get_price_waves(close: pd.Series, b: pd.Series, zig_thresh: float, trim_thresh: float) -> pd.DataFrame:       """       完整数据处理流程：       1. 对%b做ZIG分割       2. 裁剪%b的ZIG结果       3. 将裁剪后的转折点索引映射回原始价格       4. 对原始价格再裁剪       返回带转折点标记的价格序列       """       # 对%b分割       b_points = zig_segment(b, zig_thresh)       # 裁剪%b转折点       b_points_trimmed = trim_zig(b_points, trim_thresh)       # 提取索引       idx_b = [p[0] for p in b_points_trimmed]       # 构造原始价格序列的候选转折点（直接取对应索引的价格）       price_points = [(idx, close.iloc[idx], p[2]) for idx, p in zip(idx_b, b_points_trimmed)]       # 对原始价格再裁剪（由于映射后可能仍有小幅波动）       price_points_trimmed = trim_zig(price_points, trim_thresh * close.mean())  # 阈值转换为绝对价格       return pd.DataFrame(price_points_trimmed, columns=['idx', 'price', 'type'])    `

## 总结

本文是波段识别的第一篇内容，主要是对传统方法做了简介。对新方法的原始股价数据给出了预处理方法，剔除了大部分的噪音。