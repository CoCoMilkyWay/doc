# 成交量作为择时因子的应用——算法、原理、代码

灵犀 随率而动的因子工厂 2026-01-25 15:53 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484410&idx=1&sn=fd19e4ff97045bfa26d417e3b7d1974f&chksm=c094c54ec8bdb25db5c6fdcf700b2c2e127ec65f6bcc81920eb4f5ad659f29d810e82b82a6ed#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484410&idx=1&sn=fd19e4ff97045bfa26d417e3b7d1974f&chksm=c094c54ec8bdb25db5c6fdcf700b2c2e127ec65f6bcc81920eb4f5ad659f29d810e82b82a6ed#rd)

## 技术背景

之前我们介绍了很多的因子，其实大部分的因子思路源自于量价关系。但是我们之前介绍的因子，大多数偏向于价格之间关系，至于成交量的相关因子介绍甚少。

但是在实际交易中，**成交量**却是整个交易中最真实的部分。它至少可以反应了标的交易活跃程度、交易者互相之间的换手程度、历史筹码分布情况等等。有句俗语说得好，价格可以造假，但是成交量不会，它是货真价实达成的交易。

在很多成熟的交易系统中，一定都存在成交量的因子。

**深入了解成交量，你就会发现下面的一些特点**：

-   1、启动时成交量放大。
    
-   2、见顶的时候成交量放大、价格可能有滞涨。
    
-   3、拉升时，量价齐升。
    
-   4、下跌时，量价齐跌
    
-   5、其他
    

但是作为一名究竟沙场的老交易员，你会发现发现似乎其中规律性也没有那么强。当然这里并没有罗列出全部的规律。

当然，这其中也有很多的问题值得考究：

-   1、放量多少才算放量？
    
-   2、如何区别底部放量？高位放量？
    
-   3、成交量衍生指标有哪些？
    
-   4、有哪些不同的用法？
    
-   等等
    

本期内容，我们从成交量的角度出发，罗列了我们目前能够找到的关于成交量的一些比较热门的用法。

**本期的指标主要是用在单个标的（个股、期货、指数等），上的择时研究。由于篇幅原因，本期将三个基本的用法。后期看情况继续更新。**

至于是否能够作为截面因子，也有相应的研究报告，等以后一起研究。**如果你有一种很好的使用方法，也可以联系我，我们如果认可的话，可以一起做成一个量化指标或者多因子策略。**

**最后，需要跟大家道个歉，由于个人原因，星球迟迟没有推出。我们秉着负责任的态度，必须在准备充分的基础上开放星球，一定让大家物超所值。**

**重中之重：本期文章的阅读重点，应该是整个回测框架的搭建，而不是局限于vol指标本身。由于不涉及多因子的组合，本期文章的没有做因子测试。按说其实应该是按照之前文章的内容做因子测试，位了方便这里没有做，有兴趣的大家可以自行测试。**

## 常见用法与实证

### 成交量均线（MAAMT）

**1、算法：**成交量上破N日均线：买入信号，成交量下创N日均线：卖出信号。

**2、原理解析：** 从交易常识中，放量分为底部、顶部。 底部成交量放大，是一个正向因子。顶部放量其实是一个不太好的因子。缩量总是一个不利因素。

**3、风险点：** 由于顶部放量不一定是一个好的信号，所以MAAMT指标信号，很有可能在顶部回撤的时候，吃到比较大的回撤。特别是个股，指数波动小，可能会好一点，具体看实证结果。

**4、实证结果：**通过python代码，这样一个简单的指标我们就能实现

**中证1000的净值曲线图**![](assets/001.png)

**沪深300的净值曲线图**![](assets/002.png)

**茅台上的策略对比**![](assets/003.png)

**5、总结：** 通过上面的三张图，我们发现，这个策略在大的指数择时上表现说的过去，整体是一个正向收益。但是在个股上表现属实一般。

**6、python代码：**这里仅仅展示信号产生代码，比较简单。回测的backtest函数，在后文。**如果需要完整代码，可以私我。**

  `def get_signals_ma(self,                        df_vol,                        n_days: int = 30, ):         """生成买卖信号 - 使用向量化操作"""         if df_vol is None:             raise ValueError("输入数据为空！")            data = df_vol.copy()            # 计算成交量N日均线         data['vol_ma'] = data['vol'].rolling(window=n_days, min_periods=1).mean()         # 创建前一日的成交量均线列         data['vol_ma_prev'] = data['vol_ma'].shift(1)         data['vol_prev'] = data['vol'].shift(1)            # 使用向量化操作生成信号         # 买入信号：前一日成交量在均线下方，当日成交量在均线上方         buy_condition = (data['vol_prev'] <= data['vol_ma_prev']) & (data['vol'] > data['vol_ma'])            # 卖出信号：前一日成交量在均线上方，当日成交量在均线下方         sell_condition = (data['vol_prev'] >= data['vol_ma_prev']) & (data['vol'] < data['vol_ma'])            # 初始化信号列         data['signal'] = 0            # 设置买入信号         data.loc[buy_condition, 'signal'] = 1            # 设置卖出信号         data.loc[sell_condition, 'signal'] = -1            # 删除临时列         data = data.drop(['vol_ma_prev', 'vol_prev'], axis=1)            print(f"信号生成完成，共 {len(data[data['signal'] != 0])} 个交易信号")         print(f"买入信号: {len(data[data['signal'] == 1])} 个")         print(f"卖出信号: {len(data[data['signal'] == -1])} 个")            return data.copy()`

### EOM指标（指标类）

**1、算法：** EOM (Ease of Movement) 简易波动指标策略

-     
    

1.  距离移动 = ((High + Low)/2 - (Prev\_High + Prev\_Low)/2)
    

-     
    

2.  箱子比率 = (Volume / 100000000) / (High - Low)
    

-     
    

3.  EOM = 距离移动 / 箱子比率
    

-     
    

-   EOM上穿0轴: 买入信号
    
-   EOM下穿0轴: 卖出信号
    

4.  交易信号:
    

**2、原理：** EOM指标的基本思想是：在成交量较小的情况下，价格的大幅移动表明市场趋势较强；而在成交量较大的情况下，价格的微小移动表明市场趋势较弱。

**3、实证结果分析**

**hs300的测试结果**![](assets/004.png)

**中证1000测试结果**

![](assets/005.png)

**4、总结**对于下面表格中的指标，大家可以自行测试。![](assets/006.png)

**5、python代码**

  `@staticmethod     def calculate_eom(df_vol,                       eom_period=14,                       ma_period=9,                       scale = 100000000):         """计算EOM指标"""         if df_vol is None:             print("请先下载数据")             return None            data = df_vol.copy()            # 1. 计算中点         data['Midpoint'] = (data['high'] + data['low']) / 2            # 2. 计算距离移动 (Distance Moved)         # DM = 当日中点 - 前一日中点         data['Midpoint_Prev'] = data['Midpoint'].shift(1)         data['Distance_Moved'] = data['Midpoint'] - data['Midpoint_Prev']            # 3. 计算箱子比率 (Box Ratio)         # BR = (vol / Scale) / (high - low)         # Scale通常为100000000，用于调整量纲            data['Box_Ratio'] = (data['vol'] / scale) / (data['high'] - data['low'])            # 避免除数为0的情况         data['Box_Ratio'] = data['Box_Ratio'].replace([np.inf, -np.inf], 0)            # 4. 计算原始EOM         # EOM = Distance_Moved / Box_Ratio         data['EOM_Raw'] = data['Distance_Moved'] / data['Box_Ratio']         data['EOM_Raw'] = data['EOM_Raw'].replace([np.inf, -np.inf], 0)            # 5. 计算EOM的N日简单移动平均         data['EOM'] = data['EOM_Raw'].rolling(window=eom_period).mean()            # 6. 计算EOM移动平均信号线         data['EOM_MA'] = data['EOM'].rolling(window=ma_period).mean()            # 清理临时列         data = data.drop(['Midpoint_Prev'], axis=1)            return data        def calculate_eom_signals(self, df_vol: pd.DataFrame):         """生成EOM交易信号"""         if (df_vol is None) or df_vol.empty:             raise ValueError('基础数据为空！')         data = self.calculate_eom(df_vol)         if data is None:             raise ValueError('emo数据为空！')         # 计算前一日的EOM值         data['EOM_Prev'] = data['EOM'].shift(1)         data['EOM_MA_Prev'] = data['EOM_MA'].shift(1)            # 初始化信号列         data['signal'] = 0            # 信号1: EOM上穿0轴 (金叉)         # 前一日EOM < 0 且 当日EOM > 0         golden_cross = (data['EOM_Prev'] < 0) & (data['EOM'] > 0)         data.loc[golden_cross, 'signal'] = 1            # 信号2: EOM下穿0轴 (死叉)         # 前一日EOM > 0 且 当日EOM < 0         death_cross = (data['EOM_Prev'] > 0) & (data['EOM'] < 0)         data.loc[death_cross, 'signal'] = -1            # # 信号3: EOM上穿其移动平均线 (可选，更强烈的买入信号)         # # 前一日EOM < EOM_MA 且 当日EOM > EOM_MA         # eom_above_ma = (data['EOM_Prev'] < data['EOM_MA_Prev']) & (data['EOM'] > data['EOM_MA'])         # data.loc[eom_above_ma, 'signal'] = 2  # 强烈买入信号         #         # # 信号4: EOM下穿其移动平均线 (可选，更强烈的卖出信号)         # # 前一日EOM > EOM_MA 且 当日EOM < EOM_MA         # eom_below_ma = (data['EOM_Prev'] > data['EOM_MA_Prev']) & (data['EOM'] < data['EOM_MA'])         # data.loc[eom_below_ma, 'signal'] = -2  # 强烈卖出信号            # 清理临时列         data = data.drop(['EOM_Prev', 'EOM_MA_Prev'], axis=1)            # 统计信号数量         signals_summary = {             '买入信号(上穿0轴)': len(data[data['signal'] == 1]),             '卖出信号(下穿0轴)': len(data[data['signal'] == -1]),             # '强烈买入信号(上穿MA)': len(data[data['signal'] == 2]),             # '强烈卖出信号(下穿MA)': len(data[data['signal'] == -2]),             '总信号数': len(data[data['signal'] != 0])         }            print("\nEOM信号统计:")         for key, value in signals_summary.items():             print(f"{key}: {value}个")            return data`

### vmacd\_MTM算法

1.  **算法：**
    

-   计算 VMACD 指标（基于成交量的 MACD）
    
-   对 VMACD 进行 Z-score 标准化
    
-   计算 VMACD\_MTM（标准化后 VMACD 的动量）
    
-   生成交易信号
    

3.  **交易规则**：
    

-   当日 VMACD\_MTM > T: 信号为 1（持仓）
    
-   当日 VMACD\_MTM < -T: 信号为 -1（空仓）
    
-   当日 VMACD\_MTM 在 \[-T, T\] 之间: 保持上一状态
    

5.  **结果分析：**
    

**沪深300择时回测结果**

![](assets/007.png)

**中证1000择时回测结果**

![](assets/008.png)

4.  **总结：**
    

整体来看，也是一个比较不错的指标，但是似乎收益率并不算高。当然这里没有做任何的优化，个人也比较讨厌去做拟合类的优化。大家尝试滚动优化。

5.  **python代码：**
    

`    class VolMacdMtm:       def __init__(self, n1: int = 12, n2: int = 26, n3: int = 9, n_window: int = 60, threshold: float = 1.0):           """           初始化 VMACD_MTM 参数              Parameters:           -----------           n1: int               VMACD 快速移动平均窗口，默认 12           n2: int               VMACD 慢速移动平均窗口，默认 26           n3: int               VMACD DEA 计算窗口，默认 9           n_window: int               VMACD_MTM 计算窗口，默认 60           threshold: float               交易信号阈值 T，默认 1.0           """           self.n1 = n1           self.n2 = n2           self.n3 = n3           self.n_window = n_window           self.threshold = threshold          @staticmethod       def calculate_ema(data: pd.Series, window: int) -> pd.Series:           """计算指数移动平均"""           return data.ewm(span=window, adjust=False).mean()          # 计算vmacd       def calculate_vmacd(self, volume: pd.Series) -> pd.DataFrame:           """           计算 VMACD 指标              Parameters:           -----------           volume: pd.Series               成交量序列              Returns:           --------           pd.DataFrame: 包含 V_DIF, V_DEA, VMACD 的数据框           """           # 计算 V_DIF           ema_fast = self.calculate_ema(volume, self.n1)           ema_slow = self.calculate_ema(volume, self.n2)           v_dif = ema_fast - ema_slow              # 计算 V_DEA           v_dea = self.calculate_ema(v_dif, self.n3)              # 计算 VMACD           vmacd = (v_dif - v_dea) * 2              return pd.DataFrame({               'V_DIF': v_dif,               'V_DEA': v_dea,               'VMACD': vmacd           })          # 标准化vmacd       def standardize_vmacd(self, vmacd: pd.Series) -> pd.Series:           """           对 VMACD 进行 Z-score 标准化              Parameters:           -----------           vmacd: pd.Series               VMACD 序列              Returns:           --------           pd.Series: 标准化后的 VMACD           """           # 滚动计算均值和标准差           rolling_mean = vmacd.rolling(window=self.n_window, min_periods=1).mean()           rolling_std = vmacd.rolling(window=self.n_window, min_periods=1).std()              # Z-score 标准化           vmacd_std = (vmacd - rolling_mean) / rolling_std              return vmacd_std          def calculate_vmacd_mtm(self, vmacd_std: pd.Series) -> pd.Series:           """           计算 VMACD_MTM 指标              Parameters:           -----------           vmacd_std: pd.Series               标准化后的 VMACD 序列              Returns:           --------           pd.Series: VMACD_MTM 序列           """           # 计算 VMACD_diff (标准化后)           vmacd_diff = vmacd_std.diff()              # 计算 VMACD_MTM (近N个交易日的VMACD_diff累计和)           vmacd_mtm = vmacd_diff.rolling(window=self.n_window).sum()              return vmacd_mtm          def calculate_vmacd_mtm_signals(self, vmacd_mtm: pd.Series) -> pd.Series:           """           生成交易信号              规则:           - 当日 VMACD_MTM > T: 信号为 1 (持仓)           - 当日 VMACD_MTM < -T: 信号为 -1 (空仓)           - 当日 VMACD_MTM 在 [-T, T] 之间: 保持上一状态              Parameters:           -----------           vmacd_mtm: pd.Series               VMACD_MTM 序列              Returns:           --------           pd.Series: 交易信号序列 (1: 做多, -1: 空仓, 0: 初始状态)           """           signals = pd.Series(0, index=vmacd_mtm.index)           prev_signal = 0  # 初始状态为空仓              for i in range(len(vmacd_mtm)):               if pd.isna(vmacd_mtm.iloc[i]):                   signals.iloc[i] = 0                   continue                  if vmacd_mtm.iloc[i] > self.threshold:                   signals.iloc[i] = 1                   prev_signal = 1               elif vmacd_mtm.iloc[i] < -self.threshold:                   signals.iloc[i] = -1                   prev_signal = -1               else:                   # 保持上一状态                   signals.iloc[i] = prev_signal              # 为了跟回测框架保持一致，这里需要仅仅保持第一次的交易信号其他为0              signals = pd.Series(np.where(signals!=signals.shift(1), signals, 0), index=signals.index)                 return signals          def calculate_all(self, df: pd.DataFrame, volume_col: str = 'vol') -> pd.DataFrame:           """           计算完整的 VMACD_MTM 指标和信号              Parameters:           -----------           df: pd.DataFrame               包含成交量等数据的数据框，需要有日期索引           volume_col: str               成交量列名              Returns:           --------           pd.DataFrame: 包含所有指标和信号的数据框           """           # 计算 VMACD           vmacd_df = self.calculate_vmacd(df[volume_col])              # 标准化 VMACD           vmacd_std = self.standardize_vmacd(vmacd_df['VMACD'])              # 计算 VMACD_MTM           vmacd_mtm = self.calculate_vmacd_mtm(vmacd_std)              # 生成信号           signals = self.calculate_vmacd_mtm_signals(vmacd_mtm)              # 合并结果           result_df = pd.DataFrame({               'vol': df[volume_col],               'V_DIF': vmacd_df['V_DIF'],               'V_DEA': vmacd_df['V_DEA'],               'VMACD': vmacd_df['VMACD'],               'VMACD_std': vmacd_std,               'VMACD_MTM': vmacd_mtm,               'threshold_buy': [self.threshold] * len(df[volume_col]),               'threshold_sell': [-self.threshold] * len(df[volume_col]),               'signal': signals           })              result_df = pd.merge(result_df, df, how='inner',left_index=True, right_index=True)           return result_df       `

## 总结

由于篇幅原因，本期文章我们给出了常见的三种不同类型、与成交量相关的择时指标的算法、实证、python代码，当然代码较长，仅给出了部分代码。从本文的结果来看，成交量确实是一个值得考虑的正向因子。

另外，这里因子、指标有很多其他的用法，也是一种原始因子的思路。小伙伴们可以根据自己的需求魔改，也可以结合其他的因子做成一个多因子的择时策略。