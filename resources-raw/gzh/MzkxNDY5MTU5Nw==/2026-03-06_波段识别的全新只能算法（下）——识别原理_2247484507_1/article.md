# 波段识别的全新只能算法（下）——识别原理、算法、代码

灵犀 随率而动的因子工厂 2026-03-06 14:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484507&idx=1&sn=896fcd385aaef038ca69addeb5333cec&chksm=c00af37faf52e057539c1658f2610c720e33663b7f06af0bcf1e938dd79a2d6f57291a83196b#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484507&idx=1&sn=896fcd385aaef038ca69addeb5333cec&chksm=c00af37faf52e057539c1658f2610c720e33663b7f06af0bcf1e938dd79a2d6f57291a83196b#rd)

## 技术背景

上一篇：波段形态的智能识别新方法（上）中，我们介绍了一些波动识别的基础。特别是介绍了本文中的方法，相比较传统方法有哪些不同、改进点。此外，详细介绍了本文中识别算法的数据预处理方法。不了解本文内容可以去上一篇查看。

我们知道经过上一期文章中的预处理，我们得到了一个**噪音少、标准化、ZIG分割**的数据图像。本文我们将以此为基础，进一步介绍具体的识别算法。

**个人见解：**最近在研究这个算法时，发现里面的处理方法，在严格控制未来函数的基础上，滞后严重。特别是在做ZIG之后的裁剪、映射到原始数据上的裁剪时，修改了过去的数据，这与本人的量化思路有很大的冲突，本来以为能够想个合适的方法解决这个问题，但是目前为止没有找到很好的在不牺牲时效性的基础上的解决办法，如果你有欢迎一起讨论。我将拉个小组，一起讨论这个解决办法。因此本系列不会出现实证与策略统计分析。

**此外，本文的思路来源于：广发的另类交易策略研报，有兴趣的可以私信发你。**

**阅读目的：** 虽然从zig转折点的角度去判断相似性，个人觉得有一丢丢的滞后，但是我认为本位给出两个相似度判断的角度还是值得学习一下，补充一下知识库。**如果你有其他很好的判断转折点、去除杂波的方法，比如：卡尔曼滤波、小波分析等等，将这里裁剪的方法去掉，在使用本文的识别方法，我觉得也是可以尝试一下的。**

## 算法简介

经前文的数据预处理，我们可以将价格走势标准化为下图中的走势：

![](assets/001.png)

并且我们记录了这些转折点的坐标：（时间、点位、确认时间、类型）。接下来，我们将在这个基础上，详细介绍识别算法的设计。

**具体流程：选择窗口大小-> 排列高低点位 -> 计算度量 -> 筛选相似图形**

**算法优势：** 不受时间长度限制、图形相似度高、符合技术分析理论等等

### 第一步：基于高低点位排列的形态判断

此处我们采用图形**高低点位的排列顺序**作为判断相似性依据的第一条件，具体如下：

取长度为  的一列点位然后将其分为高点和低点两类集合

  

分别对于高点和低点两类集合进行由小到大的重新排序之后，我们得到排列

我们将**排序顺序**相同作为我们相似性匹配的必要条件。

### 第一步：相似距离约束

**我们知道只是相对高点的顺序还不够，转折点之间绝对高度差也是影响相似度的一个要素。** 为了识别更加准确，引入一种新的测度，对于高低点位的距离差加以约束。

定义距离函数：

下面我们证明该函数是一个距离。

**引理1**: 若 ，则。

**引理2**: 若 ， 且 ，则

显然，，，我们仅需证明三角不等式：

令 ，，由引理1和引理2我们易得

因此，成立，**故  是一个距离。**

综合上述，我们得出如下定义：

#### 相似性定义

若两列序列满足：

1.   与  具有相同的高低点排列顺序；
    
2.  ，其中
    

则两列序列可以进行相似性匹配。

我们在实际运用中取 ，。

此处需要权衡阈值  的大小。较小的  能够保证图像高度相似，若 ，则两图形完全相同。但是，过小的阈值 会导致可匹配的图形数量减少，从而减少预测的准确性。

**通过上面关于距离的定义，以及判断两个图形相识的两条定义，我们就能很快的找出历史中相似的图形。**

## 代码

**程序借助于部分ai,** 仅供参考研究。

`# ====================== 模式匹配类 ======================   class PatternMatcher:       """波段模式提取与相似性匹配"""       def __init__(self, config: WPRMConfig):           self.config = config           self.history_patterns: List[Dict] = []          def extract_pattern(self, points: List[Tuple[int, float, str]]) -> Optional[Dict]:           """           从转折点序列中提取最近的lookback_window个点           返回模式字典，包含高低点排序和价格差           """           if len(points) < self.config.lookback_window:               return None           recent = points[-self.config.lookback_window:]           highs = [p for p in recent if p[2] == 'peak']           lows = [p for p in recent if p[2] == 'trough']           # 按价格排序得到模式（升序）           high_order = [p[1] for p in sorted(highs, key=lambda x: x[1])]           low_order = [p[1] for p in sorted(lows, key=lambda x: x[1])]           price_diffs = [abs(recent[j + 1][1] - recent[j][1]) for j in range(len(recent) - 1)]           return {               'high_order': high_order,               'low_order': low_order,               'price_diffs': price_diffs,               'points': recent           }          @staticmethod       def similarity_distance(pattern1: Dict, pattern2: Dict) -> float:           """计算两个波段的距离d (α=1, β=0)"""           diffs1 = pattern1['price_diffs']           diffs2 = pattern2['price_diffs']           if len(diffs1) != len(diffs2):               return np.inf           return np.mean([abs(d1 - d2) for d1, d2 in zip(diffs1, diffs2)])          def match_similar(self, current_pattern: Dict) -> List[Dict]:           """           在历史中寻找相似波段           条件：高低点排序相同 且 距离 <= gamma           """           matches = []           for hp in self.history_patterns:               if (hp['high_order'] == current_pattern['high_order'] and                       hp['low_order'] == current_pattern['low_order']):                   dist = self.similarity_distance(current_pattern, hp)                   if dist <= self.config.similarity_gamma:                       matches.append(hp)           return matches          def add_to_history(self, pattern: Dict):           """将模式加入历史库"""           self.history_patterns.append(pattern)      `

## 总结

本文在前文的基础上，给出了识别算法以及程序。个人在研究时发现：原始算法在严格控制未来函数的基础上，时效性会比较滞后，所以这里没有做成熟的策略分析。特别是回测数据，由于存在未来节点修改过去的点位的数据，所以必须用滚动回测，而不能用全局回测。在运行效率以及可靠性上值得考量。

波段识别的全新智能算法（下）——识别原理、算法、代码