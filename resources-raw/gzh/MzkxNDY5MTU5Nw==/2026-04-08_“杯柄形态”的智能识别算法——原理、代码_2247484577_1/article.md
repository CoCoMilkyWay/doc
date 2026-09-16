# “杯柄形态”的智能识别算法——原理、代码、验证

蝴蝶量化 随率而动的因子工厂 2026-04-08 17:05 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484577&idx=1&sn=0b7f90b7a94e15b0f252b36b7870d35a&chksm=c00ff1820108807ca56facf0871d21d8813591681529bba08d35e863515a3a749c966ae30b2b#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484577&idx=1&sn=0b7f90b7a94e15b0f252b36b7870d35a&chksm=c00ff1820108807ca56facf0871d21d8813591681529bba08d35e863515a3a749c966ae30b2b#rd)

## 引言

如果你热衷于技术分析，那你一定知道一种关于突破的技术结构——**杯柄突破**。本期文章我们就着眼于杯柄结构的识别算法研究，主要内容：杯柄简介、算法设计、历史信号统计等等。

**杯柄形态**是由威廉·欧奈尔（William O'Neil）提出的经典看涨持续形态。其核心逻辑是：股价在经历一轮显著上涨后，通过“杯”部回调整理，清洗不坚定筹码，再通过“柄”部二次回踩，最终放量突破前高，开启新一轮上涨。

之前看到一些文章说：杯柄形态形成后上涨的概率高达**95%**，对于一个量化人来说，看到这么高的胜率，第一反应就是**不可能！！！**。本期内容，我们将通过python代码给你一个完整的验证程序与统计分析。具体内容,见下图：

![](assets/001.jpg)

## 杯柄形态的定义

基于目前能找到的关于杯柄的定义，我们将识别过程分解为**三个关键点（A、B、C）** 的检测，其中：

-   **A点**：杯左侧高点，代表上涨趋势的顶点。
    
-   **B点**：杯右侧次高点（柄的起点），通常略低于A点。
    
-   **C点**：突破点（买点），股价放量超过B点，确认形态完成。
    

## 具体算法步骤

由于A点的确定需要B、C点，B点的确认也需要C点，所以这里我们采用从C点->B点->A点的顺序寻找**杯柄结构**。

### 1.寻找C点

C点是形态的最终确认信号，必须同时满足：

-   **价格突破**： 且 （即突破幅度不超过5%）。
    
-   **放量确认**：区间，其中BC区间指从B点到C点（不含）的成交量均值。
    
-   **K线特征**：,即当日不是光头阳线。
    

### 2\. 寻找B点（柄起点）

B点位于杯的右侧，是柄部回调的起点，需满足：

-   **局部高点**：B点是B→C区间内（不含C）的最高价最高点。
    
-   **与C的关系**：C点最高价必须高于B→C区间内所有价格（即C点突破整个柄部区域）。
    
-   **柄深限制**：柄部回调深度 柄部最低价
    
-   **成交量萎缩**：在B→C区间内，底部附近的成交量明显低于B点附近成交量，可定义为 柄底部
    

### 3\. 寻找A点

A点是杯的左沿顶点，需满足：

-   **前期上涨**：从A点向前推一段时间（如120日），股价涨幅 ≥ 30%。简化可用A点价格与之前一个中期低点的比例判断。
    
-   **杯深限制**：杯底最低价 应在12%~15%之间。
    
-   **价格顺序**：（杯左高高于右高）。
    
-   **结构对称性**：A→B区间（杯的宽度）与B→C区间长度比大致合理。
    

### 4\. 整体形态过滤

-   **总长度**：从A点第一根下跌K线到C点，至少35个交易日。
    
-   **杯体长度**：A点右侧下跌开始到B点，至少25个交易日。
    
-   **柄部长度**：B点到C点，通常15~100日，但建议3~8周最佳。
    

### 5\. 算法实现步骤（滑动窗口扫描）

1.  遍历每个交易日作为**候选C点**。
    
2.  从C点向左回溯，寻找满足条件的**B点**（柄起点）。
    
3.  从B点继续向左，寻找满足条件的**A点**（杯左高点）。
    
4.  验证A→B区间的杯体参数（深度、上涨幅度）和B→C区间的柄部参数（深度、缩量）。
    
5.  若全部条件满足，记录形态的A/B/C点、突破日、突破价格，输出买入信号。
    

## Python代码实现

代码框架有笔者设计，借助antigravity作为辅助工具，大大加快了编程效率，由笔者亲测有效。所有的参数支持自定义调整。

**值得注意的是：** 这里坚决避免使用胃寒函数，这是重点中的重点。

```
"""杯柄形态（Cup-with-Handle）识别算法 — 向量化优化版严格无未来函数：每个交易日仅使用当日及之前的数据进行判断。使用 numpy 向量化计算大幅提升性能。A点：杯左侧高点（前期上涨顶点）B点：杯右侧次高点（柄的起点）C点：突破点（买入信号，收盘价突破确认）"""import pandas as pdimport numpy as npfrom typing import List, Dict, Optional, Tupleimport osimport warningswarnings.filterwarnings('ignore')class CupHandleDetector:    """杯柄形态识别器（向量化优化版）"""    DEFAULT_DATA_DIR = r'C:\Users\Administrator\PyCharmMiscProject\Factor_strategy\data\data_folder\stock_ohlc_data\csv'    def __init__(self,                 lookback_max: int = 250,                 cup_depth_min: float = 0.12,                 cup_depth_max: float = 0.40,                 handle_depth_max: float = 0.12,                 vol_ratio: float = 1.4,                 handle_vol_shrink: float = 0.7,                 min_cup_len: int = 25,                 min_handle_len: int = 10,                 max_handle_len: int = 100,                 min_total_len: int = 35,                 pre_rise_threshold: float = 0.30,                 pre_rise_window: int = 120,                 break_max_ratio: float = 1.05):        """        参数说明:            lookback_max: 最大回溯天数            cup_depth_min: 杯深下限 (12%)            cup_depth_max: 杯深上限 (40%, 考虑熊市)            handle_depth_max: 柄深上限 (12%)            vol_ratio: C点突破放量倍数 (相对于柄区间均量)            handle_vol_shrink: 柄部缩量系数 (柄底量 < 0.7 * B点附近量)            min_cup_len: 最小杯体长度(交易日)            min_handle_len: 最小柄部长度            max_handle_len: 最大柄部长度            min_total_len: A→C最小总长度            pre_rise_threshold: A点前期最小涨幅 (30%)            pre_rise_window: 检查前期涨幅的窗口长度            break_max_ratio: C点最高价不超过B点高价的比例 (1.05)        """        self.lookback_max = lookback_max        self.cup_depth_min = cup_depth_min        self.cup_depth_max = cup_depth_max        self.handle_depth_max = handle_depth_max        self.vol_ratio = vol_ratio        self.handle_vol_shrink = handle_vol_shrink        self.min_cup_len = min_cup_len        self.min_handle_len = min_handle_len        self.max_handle_len = max_handle_len        self.min_total_len = min_total_len        self.pre_rise_threshold = pre_rise_threshold        self.pre_rise_window = pre_rise_window        self.break_max_ratio = break_max_ratio    @staticmethod    def list_stocks(data_dir: str) -> List[str]:        """列出数据目录中所有股票代码"""        if not os.path.isdir(data_dir):            return []        files = [f for f in os.listdir(data_dir) if f.endswith('.csv')]        codes = [f.replace('.csv', '') for f in sorted(files)]        return codes    @staticmethod    def load_stock(data_dir: str, stock_code: str) -> pd.DataFrame:        """        加载单只股票数据        返回包含 date,open,high,low,close,volume,stock_name 的 DataFrame        """        filename = stock_code if stock_code.endswith('.csv') else f'{stock_code}.csv'        filepath = os.path.join(data_dir, filename)        if not os.path.exists(filepath):            raise FileNotFoundError(f'找不到文件: {filepath}')        df = pd.read_csv(filepath)        # 列名统一        rename_map = {}        if 'vol' in df.columns and 'volume' not in df.columns:            rename_map['vol'] = 'volume'        if rename_map:            df.rename(columns=rename_map, inplace=True)        # 必要列检查        required = ['date', 'open', 'high', 'low', 'close', 'volume']        missing = [c for c in required if c not in df.columns]        if missing:            raise ValueError(f'缺少必要列: {missing}')        df['date'] = pd.to_datetime(df['date'])        df.sort_values('date', ascending=True, inplace=True)        df.reset_index(drop=True, inplace=True)        return df    def identify(self, df: pd.DataFrame) -> List[Dict]:        """        识别杯柄形态，严格无未来函数，向量化优化。                优化说明：        1. 采用多峰值搜索，防止单一极值偏差导致的漏报。        2. 严格校准前置涨幅窗口（A点之前）。        3. 引入形态去重，确保信号唯一性。        """        n = len(df)        if n < self.min_total_len + self.pre_rise_window:            return []        highs = df['high'].values.astype(np.float64)        lows = df['low'].values.astype(np.float64)        closes = df['close'].values.astype(np.float64)        opens = df['open'].values.astype(np.float64)        volumes = df['volume'].values.astype(np.float64)        dates = df['date'].values        # 1. 前置涨幅需要的滚动最低价 (严格不包含当前点，寻找 a_idx 之前的低点)        rolling_min_low_pre = pd.Series(lows).shift(1).rolling(self.pre_rise_window, min_periods=20).min().values        # 2. 成交量累加        cum_vol = np.concatenate([[0], np.cumsum(volumes)])                # C点候选：必须不是一字涨停且收盘价突破近期高位        c_mask = (opens != highs)        start_idx = max(self.lookback_max, self.pre_rise_window + self.min_cup_len + self.min_handle_len)        c_mask[:start_idx] = False        c_candidates = np.where(c_mask)[0]        signals = []        used_ab_pairs = set()        for c_idx in c_candidates:            c_high, c_close, c_vol = highs[c_idx], closes[c_idx], volumes[c_idx]            # 确定 B 点搜寻范围            b_range_end = c_idx - self.min_handle_len            b_range_start = max(0, c_idx - self.max_handle_len)            if b_range_start >= b_range_end: continue            # 寻找范围内最大的三个局部高点作为候选 B 点            search_slice = highs[b_range_start : b_range_end + 1]            if len(search_slice) < 5: continue                        potential_b_indices = []            sorted_indices = np.argsort(search_slice)[::-1]            for idx_in_slice in sorted_indices[:3]: # 尝试前三个高点                potential_b_indices.append(b_range_start + idx_in_slice)            found_signal_for_c = False            for b_idx in potential_b_indices:                b_high = highs[b_idx]                                # 条件过滤                if c_close <= b_high: continue                handle_max_after_b = highs[b_idx+1 : c_idx].max() if c_idx > b_idx+1 else 0                if b_high < handle_max_after_b: continue                if b_high > 0 and c_high / b_high > self.break_max_ratio: continue                handle_slice_lows = lows[b_idx : c_idx]                handle_low = handle_slice_lows.min()                handle_depth = (b_high - handle_low) / b_high if b_high > 0 else 0                if handle_depth > self.handle_depth_max: continue                vol_sum_bc = cum_vol[c_idx] - cum_vol[b_idx]                handle_days = c_idx - b_idx                handle_vol_mean = vol_sum_bc / handle_days if handle_days > 0 else 0                if handle_vol_mean > 0 and c_vol < self.vol_ratio * handle_vol_mean: continue                                handle_slice_vols = volumes[b_idx : c_idx]                handle_low_pos = np.argmin(handle_slice_lows)                bottom_vol_avg = handle_slice_vols[max(0, handle_low_pos - 2):min(len(handle_slice_vols), handle_low_pos + 3)].mean()                b_area_vol_avg = handle_slice_vols[:min(len(handle_slice_vols), 3)].mean()                if b_area_vol_avg > 0 and bottom_vol_avg >= self.handle_vol_shrink * b_area_vol_avg: continue                # 寻找 A 点                a_far = max(0, b_idx - self.lookback_max)                a_near = max(0, b_idx - self.min_cup_len)                if a_near <= a_far: continue                                cup_range_highs = highs[a_far : a_near + 1]                if len(cup_range_highs) < 5: continue                a_idx = a_far + np.argmax(cup_range_highs)                a_high = highs[a_idx]                # 去重逻辑                if (a_idx, b_idx) in used_ab_pairs:                     found_signal_for_c = True                     break                cup_slice_lows = lows[a_idx : b_idx]                cup_low_idx = a_idx + np.argmin(cup_slice_lows)                cup_low = lows[cup_low_idx]                cup_depth = (a_high - cup_low) / a_high if a_high > 0 else 0                if not (self.cup_depth_min <= cup_depth <= self.cup_depth_max):                    continue                pre_min_low = rolling_min_low_pre[a_idx]                if pd.isna(pre_min_low) or pre_min_low <= 0: continue                pre_rise = (a_high - pre_min_low) / pre_min_low                if pre_rise < self.pre_rise_threshold:                    continue                used_ab_pairs.add((a_idx, b_idx))                                signals.append({                    'C_idx': int(c_idx),                    'C_date': dates[c_idx],                    'C_close': float(c_close),                    'A_idx': int(a_idx),                    'A_date': dates[a_idx],                    'A_high': float(a_high),                    'B_idx': int(b_idx),                    'B_date': dates[b_idx],                    'B_high': float(b_high),                    'cup_low_idx': int(cup_low_idx),                    'cup_depth': round(cup_depth, 4),                    'handle_depth': round(handle_depth, 4),                    'cup_len': int(b_idx - a_idx),                    'handle_len': int(c_idx - b_idx),                    'total_len': int(c_idx - a_idx),                    'volume_ratio': round(float(c_vol / handle_vol_mean), 2) if handle_vol_mean > 0 else 0,                })                found_signal_for_c = True                break                         if found_signal_for_c: continue        return signals    @staticmethod    def compute_statistics(df: pd.DataFrame,                           signals: List[Dict],                           hold_days: List[int] = None) -> Tuple[pd.DataFrame, pd.DataFrame]:        """        向量化计算信号后 T+N 天的收益统计。        """        if hold_days is None:            hold_days = [1, 3, 5, 10, 20]        if not signals:            empty_detail = pd.DataFrame(columns=['C_date', 'hold_days', 'return_pct'])            empty_summary = pd.DataFrame(columns=[                'hold_days', 'signal_count', 'up_count', 'up_probability',                'avg_return', 'median_return', 'max_return', 'max_loss',                'win_rate', 'profit_loss_ratio'            ])            return empty_detail, empty_summary        closes = df['close'].values        max_idx = len(closes) - 1        # 向量化构造明细        sig_df = pd.DataFrame(signals)        hold_arr = np.array(hold_days)        # 构造 (n_signals × n_hold_days) 的交叉表        c_indices = sig_df['C_idx'].values       # shape (n,)        c_closes = closes[c_indices]              # shape (n,)        # future_indices[i, j] = c_indices[i] + hold_days[j]        future_indices = c_indices[:, None] + hold_arr[None, :]  # (n, m)        valid_mask = future_indices <= max_idx        # clip 防止越界        clipped = np.clip(future_indices, 0, max_idx)        future_closes = closes[clipped]        returns = (future_closes - c_closes[:, None]) / c_closes[:, None]        returns[~valid_mask] = np.nan        # 展开为明细表        n_sig = len(signals)        n_hold = len(hold_days)        records = {            'C_date': np.repeat(sig_df['C_date'].values, n_hold),            'A_date': np.repeat(sig_df['A_date'].values, n_hold),            'B_date': np.repeat(sig_df['B_date'].values, n_hold),            'hold_days': np.tile(hold_arr, n_sig),            'return_pct': returns.ravel(),            'cup_depth': np.repeat(sig_df['cup_depth'].values, n_hold),            'handle_depth': np.repeat(sig_df['handle_depth'].values, n_hold),            'cup_len': np.repeat(sig_df['cup_len'].values, n_hold),            'handle_len': np.repeat(sig_df['handle_len'].values, n_hold),        }        detail_df = pd.DataFrame(records)        detail_df.dropna(subset=['return_pct'], inplace=True)        if detail_df.empty:            empty_summary = pd.DataFrame(columns=[                'hold_days', 'signal_count', 'up_count', 'up_probability',                'avg_return', 'median_return', 'max_return', 'max_loss',                'win_rate', 'profit_loss_ratio'            ])            return detail_df, empty_summary        # 向量化汇总统计        grouped = detail_df.groupby('hold_days')['return_pct']        summary = grouped.agg(            signal_count='count',            avg_return='mean',            median_return='median',            max_return='max',            max_loss='min',        ).reset_index()        summary['up_count'] = grouped.apply(lambda x: (x > 0).sum()).values        summary['up_probability'] = (summary['up_count'] / summary['signal_count']).round(4)        summary['win_rate'] = summary['up_probability']        # 盈亏比        def calc_pl_ratio(x):            wins = x[x > 0]            losses = x[x < 0]            avg_w = wins.mean() if len(wins) > 0 else 0            avg_l = losses.mean() if len(losses) > 0 else 0            return round(abs(avg_w / avg_l), 2) if avg_l != 0 else float('inf')        summary['profit_loss_ratio'] = grouped.apply(calc_pl_ratio).values        # 格式化        for c in ['avg_return', 'median_return', 'max_return', 'max_loss']:            summary[c] = summary[c].round(4)        summary['up_count'] = summary['up_count'].astype(int)        # 列顺序        summary = summary[['hold_days', 'signal_count', 'up_count', 'up_probability',                           'avg_return', 'median_return', 'max_return', 'max_loss',                           'win_rate', 'profit_loss_ratio']]        return detail_df, summary    @staticmethod    def _process_single_stock(args):        """多进程的工作函数"""        code, data_dir, detector_kwargs, hold_days = args        try:            detector = CupHandleDetector(**detector_kwargs)            df = CupHandleDetector.load_stock(data_dir, code)            signals = detector.identify(df)            if not signals:                return code, None, None, None                            stock_name = df['stock_name'].iloc[0] if 'stock_name' in df.columns else code                        sig_records = []            for sig in signals:                sig_records.append({                    'stock_code': code,                    'stock_name': stock_name,                    'C_date': sig['C_date'],                    'A_date': sig['A_date'],                    'B_date': sig['B_date'],                    'A_high': sig['A_high'],                    'B_high': sig['B_high'],                    'C_close': sig['C_close'],                    'cup_depth': sig['cup_depth'],                    'handle_depth': sig['handle_depth'],                    'cup_len': sig['cup_len'],                    'handle_len': sig['handle_len'],                    'total_len': sig['total_len'],                    'volume_ratio': sig['volume_ratio'],                })                            detail_df, _ = CupHandleDetector.compute_statistics(df, signals, hold_days)            if not detail_df.empty:                detail_df['stock_code'] = code                detail_df['stock_name'] = stock_name                            return code, sig_records, detail_df, None        except Exception as e:            return code, None, None, str(e)    @staticmethod    def batch_scan(data_dir: str,                   detector: 'CupHandleDetector',                   stock_codes: List[str] = None,                   hold_days: List[int] = None,                   progress_callback=None) -> Tuple[pd.DataFrame, pd.DataFrame, pd.DataFrame]:        """        批量扫描多只股票，汇总所有信号统计。        返回:            (all_detail_df, all_summary_df, signal_list_df)            signal_list_df: 所有信号的明细信息表（股票代码、名称、A/B/C点等）        """        if hold_days is None:            hold_days = [1, 3, 5, 10, 20]        if stock_codes is None:            stock_codes = CupHandleDetector.list_stocks(data_dir)        all_details = []        all_signal_records = []        total = len(stock_codes)                detector_kwargs = {            'lookback_max': detector.lookback_max,            'cup_depth_min': detector.cup_depth_min,            'cup_depth_max': detector.cup_depth_max,            'handle_depth_max': detector.handle_depth_max,            'vol_ratio': detector.vol_ratio,            'handle_vol_shrink': detector.handle_vol_shrink,            'min_cup_len': detector.min_cup_len,            'min_handle_len': detector.min_handle_len,            'max_handle_len': detector.max_handle_len,            'min_total_len': detector.min_total_len,            'pre_rise_threshold': detector.pre_rise_threshold,            'pre_rise_window': detector.pre_rise_window,            'break_max_ratio': detector.break_max_ratio,        }        tasks = [(code, data_dir, detector_kwargs, hold_days) for code in stock_codes]                import concurrent.futures        import os                # 多线程对 IO(read_csv) 提升明显，且无需考虑 Windows 的 spawn 问题        max_workers = min(32, (os.cpu_count() or 1) * 2)        processed_count = 0                with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:            # 使用 as_completed 可以在完成时立即处理            future_to_code = {executor.submit(CupHandleDetector._process_single_stock, task): task[0] for task in tasks}                        for future in concurrent.futures.as_completed(future_to_code):                processed_count += 1                code, sig_records, detail_df, err = future.result()                                if progress_callback:                    progress_callback(processed_count, total, code)                                    if err:                    continue                                    if sig_records:                    all_signal_records.extend(sig_records)                if detail_df is not None and not detail_df.empty:                    all_details.append(detail_df)        # 构建信号明细表        signal_list_df = pd.DataFrame(all_signal_records) if all_signal_records else pd.DataFrame()        if not all_details:            empty_detail = pd.DataFrame()            empty_summary = pd.DataFrame(columns=[                'hold_days', 'signal_count', 'up_count', 'up_probability',                'avg_return', 'median_return', 'max_return', 'max_loss',                'win_rate', 'profit_loss_ratio'            ])            return empty_detail, empty_summary, signal_list_df        all_detail_df = pd.concat(all_details, ignore_index=True)        # 向量化汇总统计        grouped = all_detail_df.groupby('hold_days')['return_pct']        summary = grouped.agg(            signal_count='count',            avg_return='mean',            median_return='median',            max_return='max',            max_loss='min',        ).reset_index()        summary['up_count'] = grouped.apply(lambda x: (x > 0).sum()).values        summary['up_probability'] = (summary['up_count'] / summary['signal_count']).round(4)        summary['win_rate'] = summary['up_probability']        def calc_pl_ratio(x):            wins = x[x > 0]            losses = x[x < 0]            avg_w = wins.mean() if len(wins) > 0 else 0            avg_l = losses.mean() if len(losses) > 0 else 0            return round(abs(avg_w / avg_l), 2) if avg_l != 0 else float('inf')        summary['profit_loss_ratio'] = grouped.apply(calc_pl_ratio).values        for c in ['avg_return', 'median_return', 'max_return', 'max_loss']:            summary[c] = summary[c].round(4)        summary['up_count'] = summary['up_count'].astype(int)        summary = summary[['hold_days', 'signal_count', 'up_count', 'up_probability',                           'avg_return', 'median_return', 'max_return', 'max_loss',                           'win_rate', 'profit_loss_ratio']]        return all_detail_df, summary, signal_list_df# =================== 命令行测试 ===================if __name__ == '__main__':    import time    data_dir = CupHandleDetector.DEFAULT_DATA_DIR    detector = CupHandleDetector()    # 测试单只股票    test_code = '000001.SZ'    print(f'加载 {test_code} ...')    df = CupHandleDetector.load_stock(data_dir, test_code)    print(f'数据量: {len(df)} 行, 日期范围: {df["date"].iloc[0]} ~ {df["date"].iloc[-1]}')    t0 = time.time()    signals = detector.identify(df)    t1 = time.time()    print(f'发现 {len(signals)} 个杯柄形态信号, 耗时: {t1-t0:.3f}s')    if signals:        for i, sig in enumerate(signals[:5]):            print(f'  信号{i+1}: A={sig["A_date"]}, B={sig["B_date"]}, C={sig["C_date"]}, '                  f'杯深={sig["cup_depth"]:.2%}, 柄深={sig["handle_depth"]:.2%}')        detail_df, summary_df = CupHandleDetector.compute_statistics(df, signals)        print('\n收益统计:')        print(summary_df.to_string(index=False))
```

## 效果评测

针对这种**杯柄形态**我们开发了一个以Streamlit为框架的小工具，您可以通过这个工具准确的识别出杯柄结构。**工具仅对未来星球用户（可预约，暂未开放）开源使用。**

**1、单股识别系统**

![](assets/002.png)通过本截面，你就可以准确是识别单股中满足杯柄信号的时间点、信号点。支持历史数据切换。参数可以自由调整。

**2、全市场扫描模式**

![](assets/003.png)

![](assets/004.png)

这是一个全是市场扫描的程序，您可以统计全市场中所有杯柄形态的统计：整体胜率在50%一下，平均收益率也不算很高。当然，这里的参数我没有做调整，小伙伴们可以根据自己的需求调整，再做测试。

**3、app截面设计**

![](assets/005.png)

![](assets/006.png)后期，我们也会推出我们自己的形态识别程序，如果你不会使用python，这一款就比较适合你

## 总结

当然上面的算法仅仅是各种定义中，笔者认为比较合理的部分，很多不同的杯柄结构无非就是程序中7个参数的不同组合。您都可以通过参数调整，准确的识别你心中的杯柄结。另外，我们针对不同人群的开发了app、web版本的python程序。所有的参数公开，您可以根据自己的喜好调节参数，找到适合自己的杯柄结构。