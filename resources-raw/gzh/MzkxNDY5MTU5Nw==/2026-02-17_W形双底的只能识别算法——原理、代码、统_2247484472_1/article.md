# W形双底的只能识别算法——原理、代码、统计分析

蝴蝶量化 随率而动的因子工厂 2026-02-17 21:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484472&idx=1&sn=9be3c022e128bf97aaa645302e4a8782&chksm=c0637e4e4e5781c9799157fb05f835f48dc6d6ac7a0672ceda6a05d3df9b194a6692275388ce#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484472&idx=1&sn=9be3c022e128bf97aaa645302e4a8782&chksm=c0637e4e4e5781c9799157fb05f835f48dc6d6ac7a0672ceda6a05d3df9b194a6692275388ce#rd)

## 技术背景

我们在分析个股择时的时候，总是发现，底部走势中双重底、多重底的成功概率往往较大。本期内容是**形态识别系列**第二篇内容。我们通过纯量价的方式来定义、识别双底形态。并且给出了双底形态形成后未来一段时间的上涨概率、平均上涨幅度等等统计结果。

## 双底形态的定义

### 1、传统W底

传统上，一段时间股票长期处在**下跌趋势**当中，短期内在底部宽幅震荡。在经历连续下跌以后出现了一定程度的反弹，之后继续回调在接近前低附近价格得到了支撑，逐步反弹，构成了一个类似于英文字母W形态。这是一个典型的**反转形态**。

下面的图形中就是一个典型的传统W底部走势图。图中一些关键的价格位置都做了标记。

![](assets/001.png)

### 2、本文的W底

#### **定义**

**值得注意：** 本文中的双底形态有别于我们传统意义上的双底形态。

本文中的w底，描述的是在**一段上涨行情中，** 价格出现了短暂的回调之后，价格再一次上涨形成了第一个底部，很多时候价格会攀升到之前的高点附近。之后会出现第二次回撤，形成第二个底部。关键点事第二个底部与第一个底部在价格上基本持平、或者比第一个底部低。

理论上，下图是一个典型的满足要求的双底形态。

![](assets/002.png)

#### **约束条件**

-   **1、上涨趋势：** 形态形成之前是上涨趋势，我们对这个上涨趋势，设定一个阈值：大于N（默认30%）。
    
-   **2、形态深度：** D点距离A点的最大回撤幅度必须在某个阈值M（默认N/2～N）之间
    
-   **3、基线长度：** 从A点开始，到形态的E点形成，至少需要几周的时间。这是一个最小的周期，但是在很多时候，这个周期可能需要更加长时间：几个月、一年以上。如果周期长度不够，也就是说没有足够的时间来巩固之前的走势，也就是洗盘的时间不够。我们这里以一个参数K设定。
    
-   **4、D点与B点关系：** 一般来讲，D点价格要比B点低，这也是充分洗盘的一种表现，绝大部分意志不够坚定的投资者，都会在跌破B点的时候卖出。
    
-   **5、理想买入点：** 在双底形成的确认点：E点，作为最佳买入点位。当然，很多情况下突破E点后，股价也有可能出现短暂的回踩现象。
    
-   **6、成交量放大：** 我们认为有效的突破需要伴随着成交量的放大，为这个放大的比例设定一个最小阈值：20%。
    

## 算法设计

通过观察形似图我们知道：**C点**是一个比较明确的点，而且满足的条件比较简单：除去A点高度外，**C点进需要满足局部的高点**即可。我们确定点的步骤为：C->A->B->E->D。每寻找一个点判断相应的条件是否满足。

#### **第一步：寻找C点**

通过scipy.signal中的函数，或者自己编辑函数寻找历史中所有可能的C点，**作为预选C点**。然后遍历所有的C点，寻找其他的点。

通过下面的代码寻找可能的C点，通过“peak\_order”调节局部区间的长短。当然你也可以对C的幅度做一些要求，这里就给出一个最简单的版本。

`def _find_peaks_and_valleys(self,                                 series: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:         """         识别局部高点和低点         """         order = self.params['peak_order']         peaks = signal.argrelextrema(series, np.greater, order=order)[0]         valleys = signal.argrelextrema(series, np.less, order=order)[0]         return peaks, valleys      `

#### **第二步：确定A点**

首先，规定A点具体C点最大距离，这是在初始条件中，没有规定的。这是为了简化算法，考虑到跨度太大的回调没有太大意义。当然你可以把这个值放到很大。

**我们仅会保留满足所有条件的最近的一个A、B、E、D点，所以肯定是错失一些结构。**

**具体算法：**

-   **1、预选A点** 在C点之前，length\_max根K线之内找出：**最高价大于C点最高价，并且也是局部最高点的点为预选A点**。
    

注：这个length\_ma定义为A-E之间的最大K线数量。

-   **2、约束条件** 在上面满足条件的A点中，筛选出前期涨幅超过30%的股票。实际算法中采用剔除法，剔除不满足条件的A点。采用continue。
    
-   3、满足条件的A点，继续接下来B点判断。
    

**代码见后文**

#### **第三步：确定B点**

-   B点：A->C 点之间的最低点。
    
-   **新增约束条件：** B点的最低点，距离A点最高点的下跌幅度要超过：10%
    

#### **第四步：确定E点**

-   **预选E点：** 在C点之后length\_max的范围内，寻找第一个满足突破条件的E点。
    
-   **约束条件：**
    

-   1、 E点最高价必须大于C点最高价、并且突破比例不能超过某个阈值。
    
-   2、E点开盘价不等于最高价，也就是不是光头阴线。
    
-   3、E点成交量必须大于C-E之间成交量均值1.2倍（参数）。
    
-   4、A-E点的距离不能超过legth\_max.
    

#### **第五步：确定D点**

-   **D点：** D点为C->E点之间的最低点。
    
-   **约束条件：**
    

-   D点的最低点必须小于B点
    
-   形态深度（D点距离A点的跌幅）必须在15%～30%之内。
    

#### **第六步：其他约束条件**

-   A点是A->C之间的最高点
    
-   C点是A->C之间的第二高点
    
-   E点是C->E 之间的最高点
    

**满足上面所有条件的，确定了C -> A -> B -> E ->D**，一个C点确定了一个组合，找到了之后其他可能的A点不在寻找。

## 代码

这里给出了确定这个点的代码：

`       class DoubleBottomScanner:       """       双底形态（W底）识别与分析工具       支持从本地CSV文件加载数据，或直接传入DataFrame。       """          def __init__(self,                    params: Optional[Dict[str, Any]] = None,                    file_path: Optional[str] = None,                    code_col: Optional[str] = None,                    code: Optional[str] = None,                    date_col: str = 'date'                    ):           """           初始化参数，并可选择从本地文件加载数据。              Parameters           ----------           params : dict, optional               包含以下键值：               - pre_rise_threshold: 前期涨幅下限，默认0.3               - length_min: 形态最小周数，默认7               - length_max: 最大周数，默认65               - depth_min: 最小深度，默认0.15               - depth_max: 最大深度，默认0.30               - vol_ratio: 成交量突破倍数，默认1.2               - break_max_ratio: 突破最高价比例，默认1.05               - peak_order: 寻找极值点的邻域宽度，默认3           file_path : str, optional               本地CSV文件路径。若提供，则自动加载数据。           code_col : str, optional               CSV文件中代表股票代码的列名。当提供file_path时必须提供。           code : str, optional               要筛选的具体股票代码。当提供file_path时必须提供。           date_col : str, default 'date'               CSV文件中日期列的列名。              """           default_params = {               'pre_rise_threshold': 0.3,  # A点前期最小涨幅               'length_min': 7,  # A点到E点最小距离               'length_max': 100,  # A点到E点的最大距离               'depth_min_b':0.10,  # B点距离A点最小的回调幅度               'depth_min': 0.15,  # A点到B点最小回撤               'depth_max': 0.30,  # A点到B点的最大回撤               'vol_ratio': 1.2,  # 成交量放量的比例啊               'break_max_ratio': 1.03,  # E点的突破比例               'peak_order': 3  # C点是极值点的K线数量           }           if params:               default_params.update(params)           self.params = default_params           self.data = None          # 当前处理的股票数据           self.signals = []          # 识别出的信号列表，每个元素为 (a_idx, c_idx, e_idx)           self.returns_df = None     # 收益统计DataFrame           self.file_path = file_path           self.code_col = code_col           self.code = code           self.date_col = date_col              # 如果提供了文件路径，则自动加载              self.load_from_file()          def load_from_file(self):           """           从本地CSV文件加载指定股票的数据。              """           # 读取CSV文件           print(self.file_path)           df = pd.read_csv(self.file_path+f'/{self.code}.csv')              # 筛选指定股票           if self.code_col not in df.columns:               raise ValueError(f"文件中不存在列: {self.code_col}")           df = df[df[self.code_col] == self.code].copy()           if len(df) == 0:               raise ValueError(f"文件中未找到代码为 {self.code} 的数据")              # 转换日期列           if self.date_col not in df.columns:               raise ValueError(f"文件中不存在日期列: {self.date_col}")           df[self.date_col] = pd.to_datetime(df[self.date_col])              # 排序并重置索引           df.sort_values(self.date_col,inplace=False, ascending=True,ignore_index=True)              # 检查必要的OHLCV列是否存在           required = ['open', 'high', 'low', 'close', 'vol']           if not all(col in df.columns for col in required):               raise ValueError(f"文件中必须包含OHLCV列: {required}")              # 统一日期列名为 'date'           df.rename(columns={self.date_col: 'date'}, inplace=True)              self.data = df           self.signals = []           self.returns_df = None          def _find_peaks_and_valleys(self,                                   series: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:           """           识别局部高点和低点           """           order = self.params['peak_order']           peaks = signal.argrelextrema(series, np.greater, order=order)[0]           valleys = signal.argrelextrema(series, np.less, order=order)[0]           return peaks, valleys          def identify(self) -> List[Tuple[int, int, int]]:           """           执行双底形态识别              Returns           -------           List[Tuple[int, int, int]]               每个元素为 (A点索引, C点索引, E点索引)           """           if self.data is None:               raise ValueError("请先调用 load_from_file() 加载数据")              df = self.data           highs = df['high'].values           lows = df['low'].values           closes = df['close'].values           vols = df['vol'].values           dates = df['date'].values              params = self.params           result = []              # 寻找所有可能的C点（局部高点）           peaks, _ = self._find_peaks_and_valleys(highs)           pre_window = 40           for c_idx in peaks:               # 向前寻找第一个高于C的A点               a_idx = None               is_find = False               for i in range(c_idx - 1, max(0, c_idx - params['length_max']), -1):                   if (highs[i] > highs[c_idx]) & (i in peaks):                       a_idx = i                   else:                       continue                   # 检查A点前期涨幅是否达到阈值（简单取前40周期最低点）                   pre_min = min(lows[max(0, a_idx - pre_window):a_idx + 1])                   if (highs[a_idx] - pre_min) / pre_min < params['pre_rise_threshold']:                       continue                   # 在A→C之间找最低点B                   b_idx = np.argmin(lows[a_idx:c_idx + 1]) + a_idx                      if (1-lows[b_idx]/highs[a_idx]) < params['depth_min_b']:                       continue                         # 在C之后寻找E点                   for e_idx in range(c_idx + 1, min(len(df), c_idx + params['length_max'])):                       # E必须高于C且不超过C*break_max_ratio                       if not (highs[e_idx] > highs[c_idx] and highs[e_idx] <= highs[c_idx] * params['break_max_ratio']):                           continue                       # E点开盘价不能是最高价                       if df.iloc[e_idx]['open'] >= highs[e_idx]:                           continue                          # 计算C→E之间的成交量均值（不含E）                       vol_mean = vols[c_idx + 1:e_idx].mean()                       if vols[e_idx] < vol_mean * params['vol_ratio']:                           continue                          # 形态长度                       length = e_idx - a_idx                       if length < params['length_min'] or length > params['length_max']:                           continue                          # 在C→E之间找最低点D                       d_idx = np.argmin(lows[c_idx:e_idx + 1]) + c_idx                       # D必须低于B                       if lows[d_idx] >= lows[b_idx]:                           continue                          # 计算形态深度                       depth = (highs[a_idx] - lows[d_idx]) / highs[a_idx]                       if depth < params['depth_min'] or depth > params['depth_max']:                           continue                          # 检查A是A→C区间最高点（排除比C高的中间点）                       if max(highs[a_idx + 1:c_idx]) >= highs[a_idx]:                           continue                       # C是A→C区间第二高点（除A外最高）                       if max(highs[a_idx + 1:c_idx]) > highs[c_idx]:                           continue                       # E是C→E区间最高点                       if max(highs[c_idx + 1:e_idx]) >= highs[e_idx]:                           continue                          # 所有条件通过，记录信号                       result.append((a_idx, c_idx, e_idx))                       is_find = True                       break   # 一个C只取第一个符合条件的E                   if is_find:                       break                    self.signals = result           return result       `

## 结果分析

### 识别形态

首先，我们看看识别的效果，下面是来过那种识别的效果图。仅供参考。![](assets/003.png)

![](assets/004.png)

#### 信号统计分析

接下来是不同参数、不同年份相应的统计结果

**不同年份的收益情况**

![](assets/005.png)

**不同形态深度，不同持仓周期的收益分布**![](assets/006.png)

**W形双底的智能识别算法——原理、代码、统计分析**![](assets/007.png)

## 总结

本文通过python代码实现一种W双底形态的智能识别，整体代码的框架比较清晰。

当然这里有很多的约束条件，不同的约束条件下，识别的W底有一定的区别。小伙伴可以根据自己的喜好、习惯调整自己的参数，从而识别不同的W底部形态。

**思考：** 接下里我们打算打这些代码做成一个网页版的使用小工具，小伙伴可以在网页上选择自己比较习惯的一些算法，实现特定的形态识别。