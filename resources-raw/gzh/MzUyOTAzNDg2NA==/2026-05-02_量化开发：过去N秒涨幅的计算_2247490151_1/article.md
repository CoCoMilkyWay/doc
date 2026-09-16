# 量化开发：过去N秒涨幅的计算

fintechhaibin FinTechHi 2026-05-02 23:12 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490151&idx=1&sn=5ac6c2285b7360271c50586a52ae5233&chksm=fb47721e1c9d94610e47f95ad442c420ecb15bc2fae6cef77f624a43f7234352d70f45ff2f59#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490151&idx=1&sn=5ac6c2285b7360271c50586a52ae5233&chksm=fb47721e1c9d94610e47f95ad442c420ecb15bc2fae6cef77f624a43f7234352d70f45ff2f59#rd)

1.定义

过去N秒涨幅衡量的是价格在最近N秒内的相对变化率。

**公式**：涨幅秒前秒前

-   `new_price`：当前时刻的价格
    
-   `N秒前_new_price`：N秒前的价格
    

**说明**：

-   结果为小数（如0.05 = 5%），乘以100得百分比
    
-   正值表示上涨，负值表示下跌
    
-   若N秒前价格为0，公式无效（需处理除零异常）
    

**示例**：10秒前价格100，当前价格105 → 涨幅 = (105-100)/100 = 0.05 (5%)

###   

### 2.离散行情快照下的计算（以3秒快照示例）

当行情不是连续记录（如每3秒一个快照）时，需要处理时间点不对齐的问题。

#### 取不晚于目标时间的最新快照

**规则**：锚点时间 = 当前时间 - N秒，取 `≤ 锚点时间` 的最新快照价格。

**示例数据**（3秒间隔）：

时间

价格

9:31:45

100

9:31:48

102

9:31:51

105

9:31:54

107

9:32:00

110（当前）

**计算过去10秒涨幅**（当前9:32:00，N=10）：

-   锚点时间 = 9:32:00 - 10秒 = **9:31:50**
    
-   9:31:50无快照，取之前最近快照 → **9:31:48**，价格102
    
-   涨幅 = (110 - 102) / 102 = **7.84%**
    

**关键点**：从9:31:51到9:32:00是 **9秒**，不是10秒。

时间点

相对0秒

9:31:51

0秒

9:31:52

1秒

...

...

9:31:59

8秒

9:32:00

**9秒**

因此：

-   若用户指定使用9:31:51的价格作为锚点，实际时间间隔为9秒
    
-   若要严格10秒，应锚定9:31:50（或其之前最近快照）
    

如果明确要求使用两个特定时间点（如9:32:00和9:31:51），直接取对应价格计算：

```
def user_specified_change(current_price, anchor_price):    return (current_price - anchor_price) / anchor_price# 示例change = (110 - 105) / 105  # 4.76%，实际间隔9秒
```

**注意**：这种方式简单明确，但时间间隔可能与名义N秒不符。

### 3.量化因子中实现

#### 基本原则如下：

原则

说明

时间对齐

精确匹配N秒时间窗口

数据可用性

处理不连续行情

计算效率

优化高频数据处理

边界处理

处理数据不足、除零等异常

####   

#### Python实现参考代码（Pandas + 向量化）

```
import pandas as pdfrom datetime import timedelta# 示例数据（3秒间隔）data = [    ("9:31:45", 100), ("9:31:48", 102), ("9:31:51", 105),    ("9:31:54", 107), ("9:31:57", 108), ("9:32:00", 110),    ("9:32:03", 112), ("9:32:06", 115)]df = pd.DataFrame(data, columns=["timestamp", "price"])df["datetime"] = pd.to_datetime(df["timestamp"], format="%H:%M:%S")df = df.set_index("datetime").sort_index()def calc_past_n_seconds_change(df, N=10):    """计算每个时间点的过去N秒涨幅（向量化版本）"""    shifted_index = df.index - timedelta(seconds=N)    anchor_prices = df["price"].reindex(shifted_index, method="ffill")    df["anchor_price"] = anchor_prices.values    df[f"past_{N}s_change"] = (df["price"] - df["anchor_price"]) / df["anchor_price"]    return dfdf = calc_past_n_seconds_change(df, N=10)print(df[["price", "anchor_price", "past_10s_change"]].tail(3))
```

**输出示例**（9:32:00）：

-   当前价格：110
    
-   锚点价格：102（来自9:31:48，≤9:31:50的最新快照）
    
-   涨幅：7.84%
    

#### 数据边界处理：

场景

处理方式

目标时间早于首条数据

返回 `None` 或 `NaN`

锚点价格为0

返回 `None`（避免除零）

数据不足

返回 `None`

```
def safe_calc(df, N=10):    df = df.copy()    df["change"] = None    for idx, row in df.iterrows():        past_data = df.loc[:idx - timedelta(seconds=N)]        if len(past_data) == 0:            continue        anchor = past_data.iloc[-1]["price"]        if anchor == 0:            continue        df.at[idx, "change"] = (row["price"] - anchor) / anchor    return df
```

#### 实时行情下流式计算示例：

```
class RealtimeChangeCalculator:    def __init__(self, window_sec=10):        self.window = window_sec        self.prices = []      # 价格列表        self.timestamps = []  # 对应时间戳（秒）    def update(self, timestamp_sec, price):        self.prices.append(price)        self.timestamps.append(timestamp_sec)        cutoff = timestamp_sec - self.window        # 移除过期数据        while self.timestamps and self.timestamps[0] < cutoff:            self.timestamps.pop(0)            self.prices.pop(0)    def get_change(self):        if len(self.prices) < 2:            returnNone        return (self.prices[-1] - self.prices[0]) / self.prices[0]
```

## 4.C++中过去N秒涨幅的高效实现

## 基础实现示例：环形缓冲区

```
#include <vector>#include <deque>#include <chrono>#include <optional>#include <algorithm>#include <numeric>class PriceSnapshot {public:    int64_t timestamp_ms;   // 毫秒时间戳    double price;    PriceSnapshot(int64_t ts, double p) : timestamp_ms(ts), price(p) {}};// 基础版本：使用双端队列class NaiveChangeCalculator {private:    std::deque<PriceSnapshot> buffer;    int64_t window_sec;public:    NaiveChangeCalculator(int64_t window_sec) : window_sec(window_sec) {}    void update(int64_t timestamp_ms, double price)    {        buffer.push_back({timestamp_ms, price});        // 清理过期数据        int64_t cutoff = timestamp_ms - window_sec * 1000;        while (!buffer.empty() && buffer.front().timestamp_ms < cutoff) {            buffer.pop_front();        }    }    std::optional<double> getChange()    {        if (buffer.size() < 2) returnstd::nullopt;        double current_price = buffer.back().price;        double anchor_price = buffer.front().price;        if (anchor_price == 0) returnstd::nullopt;        return (current_price - anchor_price) / anchor_price;    }};
```

## 高性能环形缓冲区无锁设计参考

```
#include <array>#include <atomic>#include <memory>template<size_t Capacity = 10000>class RingBuffer {private:    std::array<PriceSnapshot, Capacity> buffer;    std::atomic<size_t> head{0};    std::atomic<size_t> tail{0};public:    bool push(int64_t timestamp_ms, double price)    {        size_t current_tail = tail.load(std::memory_order_acquire);        size_t next_tail = (current_tail + 1) % Capacity;        if (next_tail == head.load(std::memory_order_acquire)) {            returnfalse;   // 缓冲区满        }        buffer[current_tail] = {timestamp_ms, price};        tail.store(next_tail, std::memory_order_release);        returntrue;    }    std::optional<PriceSnapshot> getLatest() const    {        size_t current_tail = tail.load(std::memory_order_acquire);        if (current_tail == head.load(std::memory_order_acquire)) {            returnstd::nullopt;        }        size_t latest_idx = (current_tail - 1 + Capacity) % Capacity;        return buffer[latest_idx];    }    std::optional<PriceSnapshot> getSnapshotBefore(int64_t timestamp_ms) const    {        size_t current_head = head.load(std::memory_order_acquire);        size_t current_tail = tail.load(std::memory_order_acquire);        if (current_head == current_tail) returnstd::nullopt;        // 从尾部向前查找（最新到最旧）        size_t idx = (current_tail - 1 + Capacity) % Capacity;        while (idx != current_head) {            if (buffer[idx].timestamp_ms <= timestamp_ms) {                return buffer[idx];            }            idx = (idx - 1 + Capacity) % Capacity;        }        // 检查头节点        if (buffer[current_head].timestamp_ms <= timestamp_ms) {            return buffer[current_head];        }        returnstd::nullopt;    }};
```

## 二分查找和预分配内存参考

```
#include <vector>#include <algorithm>#include <cmath>class OptimizedChangeCalculator {private:    std::vector<PriceSnapshot> buffer;    size_t write_pos = 0;    size_t capacity;    int64_t window_ms;    // 预分配内存，避免频繁分配    void ensureCapacity()    {        if (buffer.size() < capacity) {            buffer.resize(capacity);        }    }public:    OptimizedChangeCalculator(int64_t window_sec, size_t max_capacity = 100000)         : capacity(max_capacity), window_ms(window_sec * 1000) {        buffer.reserve(max_capacity);    }    void update(int64_t timestamp_ms, double price)    {        if (buffer.size() < capacity) {            buffer.push_back({timestamp_ms, price});            write_pos = buffer.size() - 1;        } else {            write_pos = (write_pos + 1) % capacity;            buffer[write_pos] = {timestamp_ms, price};        }    }    // 使用二分查找定位锚点（数据按时间有序）    std::optional<double> getChange()    {        if (buffer.empty()) returnstd::nullopt;        PriceSnapshot& current = buffer[write_pos];        int64_t target_time = current.timestamp_ms - window_ms;        // 二分查找最后一个 <= target_time 的元素        auto it = std::upper_bound(buffer.begin(), buffer.end(), target_time,            [](int64_t time, const PriceSnapshot& snap) {                return time < snap.timestamp_ms;            });        if (it == buffer.begin()) {            returnstd::nullopt;   // 没有足够历史数据        }        --it;        double anchor_price = it->price;        if (anchor_price == 0) returnstd::nullopt;        return (current.price - anchor_price) / anchor_price;    }    // 批量计算所有历史点的变化（用于回测）    std::vector<double> batchCompute()    {        std::vector<double> results;        results.reserve(buffer.size());        for (size_t i = 0; i < buffer.size(); ++i) {            int64_t target_time = buffer[i].timestamp_ms - window_ms;            // 在当前点之前查找            auto it = std::upper_bound(buffer.begin(), buffer.begin() + i, target_time,                [](int64_t time, const PriceSnapshot& snap) {                    return time < snap.timestamp_ms;                });            if (it == buffer.begin()) {                results.push_back(0.0);   // 或 NAN                continue;            }            --it;            double anchor_price = it->price;            if (anchor_price == 0) {                results.push_back(0.0);                continue;            }            results.push_back((buffer[i].price - anchor_price) / anchor_price);        }        return results;    }};
```

## 内存池和索引缓存参考

```
#include <memory>#include <cstring>// 内存池分配器template<typename T, size_t BlockSize = 4096>class MemoryPool {private:    struct Block {        std::unique_ptr<uint8_t[]> data;        size_t size;        size_t used;        std::unique_ptr<Block> next;        Block(size_t sz) : data(std::make_unique<uint8_t[]>(sz)), size(sz), used(0) {}    };    std::unique_ptr<Block> current_block;    size_t element_size;public:    MemoryPool() : element_size(sizeof(T)) {        current_block = std::make_unique<Block>(BlockSize);    }    T* allocate()    {        if (current_block->used + element_size > current_block->size) {            auto new_block = std::make_unique<Block>(BlockSize);            new_block->next = std::move(current_block);            current_block = std::move(new_block);        }        T* ptr = reinterpret_cast<T*>(current_block->data.get() + current_block->used);        current_block->used += element_size;        return ptr;    }};// 高性能版本：使用原始数组 + 索引缓存class HighPerformanceCalculator {private:    staticconstexprsize_t MAX_SNAPSHOTS = 100000;    int64_t timestamps[MAX_SNAPSHOTS];    double prices[MAX_SNAPSHOTS];    size_t head = 0;    size_t tail = 0;    size_t count = 0;    int64_t window_ms;    // 缓存最近的有效锚点索引    size_t cached_anchor_idx = 0;    int64_t cached_target_time = 0;public:    HighPerformanceCalculator(int64_t window_sec) : window_ms(window_sec * 1000) {        std::memset(timestamps, 0, sizeof(timestamps));        std::memset(prices, 0, sizeof(prices));    }    void update(int64_t timestamp_ms, double price)    {        timestamps[tail] = timestamp_ms;        prices[tail] = price;        tail = (tail + 1) % MAX_SNAPSHOTS;        if (count < MAX_SNAPSHOTS) {            ++count;        } else {            head = (head + 1) % MAX_SNAPSHOTS;        }        // 使缓存失效        cached_target_time = 0;    }    std::optional<double> getChange()    {        if (count < 2) returnstd::nullopt;        size_t current_idx = (tail - 1 + MAX_SNAPSHOTS) % MAX_SNAPSHOTS;        int64_t current_time = timestamps[current_idx];        double current_price = prices[current_idx];        int64_t target_time = current_time - window_ms;        size_t anchor_idx;        // 尝试使用缓存        if (cached_target_time == target_time && cached_anchor_idx < count) {            anchor_idx = cached_anchor_idx;        } else {            // 线性查找（数据量小）或二分查找（数据量大）            anchor_idx = findAnchorIndex(target_time);            if (anchor_idx == static_cast<size_t>(-1)) returnstd::nullopt;            cached_anchor_idx = anchor_idx;            cached_target_time = target_time;        }        double anchor_price = prices[anchor_idx];        if (anchor_price == 0) returnstd::nullopt;        return (current_price - anchor_price) / anchor_price;    }private:    size_t findAnchorIndex(int64_t target_time)    {        // 从当前索引向前查找（数据通常是连续有序的）        size_t idx = (tail - 1 + MAX_SNAPSHOTS) % MAX_SNAPSHOTS;        size_t steps = 0;        while (steps < count) {            if (timestamps[idx] <= target_time) {                return idx;            }            idx = (idx - 1 + MAX_SNAPSHOTS) % MAX_SNAPSHOTS;            ++steps;        }        returnstatic_cast<size_t>(-1);    }    // 二分查找版本（数据量大时使用）    size_t binarySearchAnchor(int64_t target_time)    {        size_t left = 0, right = count - 1;        size_t result = static_cast<size_t>(-1);        // 将环形缓冲区映射到线性索引        std::vector<size_t> linear_indices(count);        for (size_t i = 0; i < count; ++i) {            linear_indices[i] = (head + i) % MAX_SNAPSHOTS;        }        while (left <= right) {            size_t mid = left + (right - left) / 2;            size_t idx = linear_indices[mid];            if (timestamps[idx] <= target_time) {                result = idx;                left = mid + 1;            } else {                right = mid - 1;            }        }        return result;    }};
```

## 多code下SIMD批量并行计算参考

```
#ifdef __AVX2__#include <immintrin.h>class SIMDChangeCalculator {private:    std::vector<double> prices;    std::vector<int64_t> timestamps;    int64_t window_ms;public:    SIMDChangeCalculator(int64_t window_sec) : window_ms(window_sec * 1000) {}    void addSnapshot(int64_t ts, double price)    {        timestamps.push_back(ts);        prices.push_back(price);    }    // 使用AVX2批量计算涨幅    std::vector<double> batchComputeSIMD()    {        std::vector<double> results(prices.size(), 0.0);        for (size_t i = 1; i < prices.size(); ++i) {            int64_t target_time = timestamps[i] - window_ms;            // 找到锚点索引            size_t anchor_idx = findAnchorIndex(i, target_time);            if (anchor_idx == static_cast<size_t>(-1)) continue;            results[i] = (prices[i] - prices[anchor_idx]) / prices[anchor_idx];        }        // SIMD批量处理（适用于连续计算）        processBatchSIMD(results);        return results;    }private:    void processBatchSIMD(std::vector<double>& results)    {        constsize_t batch_size = 4;   // AVX2一次处理4个double        size_t i = 0;        for (; i + batch_size <= results.size(); i += batch_size) {            __m256d changes = _mm256_loadu_pd(&results[i]);            // 执行其他SIMD操作（如乘以100转百分比等）            __m256d hundred = _mm256_set1_pd(100.0);            __m256d percentages = _mm256_mul_pd(changes, hundred);            _mm256_storeu_pd(&results[i], percentages);        }        // 处理剩余元素        for (; i < results.size(); ++i) {            results[i] *= 100.0;        }    }    size_t findAnchorIndex(size_t current_idx, int64_t target_time)    {        // 二分查找实现        size_t left = 0, right = current_idx;        size_t result = static_cast<size_t>(-1);        while (left <= right) {            size_t mid = left + (right - left) / 2;            if (timestamps[mid] <= target_time) {                result = mid;                left = mid + 1;            } else {                right = mid - 1;            }        }        return result;    }};#endif
```

  

### 以上仅为实现思路及底阿妈示例，具体不同方案的性能需要结合具体code数量、硬件资源、业务逻辑测试。

##   

实现方式

时间复杂度

内存占用

适用场景

双端队列

O(1) 清理，O(n) 查找

中等

低频数据，开发调试

环形缓冲区

O(1) 清理，O(n) 查找

固定

实时高频，内存敏感

二分查找优化

O(log n) 查找

较低

数据量大，时间有序

SIMD批量计算

O(n) + 向量化

较高

回测，批量数据处理

索引缓存

O(1) 平均查找

中等

连续流数据，局部性好

**理论思路**：

-   **实时交易**：使用`HighPerformanceCalculator` + 索引缓存
    
-   **回测研究**：使用`OptimizedChangeCalculator` + 二分查找
    
-   **极限性能**：结合内存池和SIMD指令集
    

### 5.总结与建议

场景

推荐方法

关键注意

有精确时间点数据

直接取对应价格

验证时间间隔是否等于N秒

离散快照，需严格N秒

取 ≤ (当前-N秒) 的最新快照

标准行业做法

用户明确指定两个时间点

直接使用指定价格

简单明确，但间隔可能≠N

量化因子批量计算

向量化方法（`reindex` + `ffill`）

高效，适合大规模数据

实时流式计算

滑动窗口缓冲区

注意及时清理过期数据

注意：计算时间窗口时，务必确认时间差计算是否正确：例如9:31:51到9:32:00是9秒而非10秒，这在策略回测和实盘交易中都可能产生显著影响。