# 高频交易系统（23）：高频交易系统中头寸管理设计要点

fintechhaibin FinTechHi 2026-04-01 22:26 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489871&idx=1&sn=492fd4dbe985e887bc346bec99849172&chksm=fbaffdac7d2136d96473e1ff9877753f9d0e4b652792ed8ba1808af9298c11dba178d24145d8#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489871&idx=1&sn=492fd4dbe985e887bc346bec99849172&chksm=fbaffdac7d2136d96473e1ff9877753f9d0e4b652792ed8ba1808af9298c11dba178d24145d8#rd)

### 每天与AI的相爱相杀。

### 用来作为知识输入，咋都没问题。

### 用来干简单的活，很溜。

### 用来做点业务性强的代码，不靠谱的几率挺高。

### 最近已经在修改个shi山代码的工程。快差不多了。昨天晚上交给AI跑，早上一看差点气死。

### 1.一个分支编译不过去最近解决不了问题，结果自己切换到另外一个分支，另外一个分支也被修改的一塌糊涂。

### 2.对话中估计记忆了我修改后马上提交的习惯，然后各种提交导致回滚时特别哪找。

### 3.编译时删除已编译文件，估计没注意rm执行路径，把整个项目给删了。

### 4.shi山代码，单个代码的行数都比较大，修改个简单问题非常慢，然后就各种少括号，格式问题。这也是调整逻辑不敢想。

### 今天晚上到家就不停的恢复，自己手动修改，合并。

### 想起来之前TOB，一个客户一个版本或者几个版本，内部产品好几个版本，项目做完了，就开始各种整合。那时候没有任何技巧，就靠一个代码比较工具和自己对各种版本的记忆。

### 现在有了AI，第一反应是：偷懒。第2反应是：同时干好几个活。

### 有些任务下，会很溜。

### 有些任务下，反而会返工，多个活都没干好。

### 所以ai，就好比一个新团队成员一样，要充分的了解和认识，才能发挥其优势，而一旦让他做目前还超出他能力的事，AI非常具有无知者无畏，给我们捅个大篓子，骂他也是，打也打不着。还的给他花钱。

###   

* * *

###   

### 上次有几天在串高频交易系统的事，[高频交易系统（20）：高频交易系统中并发和串行：行情处理模低时延设计要点](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489636&idx=1&sn=e443c2337eaf13334d1f22c85b382744&scene=21#wechat_redirect)[高频交易系统（22）：高频交易系统中并发和串行低时延设计要点](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489702&idx=1&sn=733381dc14a63371095851a72f70b6a4&scene=21#wechat_redirect)

###   

### 这几篇内容都是流程和设计思路层面，并非说就如此，或者是最佳的。

###   

### 本篇主要看下策略中如何管理头寸。

### 对任何交易系统来说，头寸就是管钱和管券。

### 对交易结算系统来说，就是目前国外国内很火的IBOR（投资账簿，投资决策账簿）。

  

其中钱：一般分可用，冻结。然后交易事件如下单、撤单、回报（委托、成交、废单）影响钱相关的值。

对券来说，一般分为持仓量，可用量，冻结量，同钱一样，受交易事件影响。

在策略系统中，相比交易系统来说，基本上没有什么本质的区别。本质还是一个记账模块。

但在高频交易系统上，就有一个特殊点：

1.低时延优先

2.异步处理

3.保证原子操作，但尽量无锁化

4.交易可重演

5.头寸错乱后可重置（因为头寸一旦错乱，部分策略逻辑直接失效。）

6.管理净头寸。这是高频策略的关键。

  

基于这些点，头寸计算的核心是**实时、准确、低时延**，需满足：

1.  单线程内串行计算（贴合现有架构，无锁）；
    
2.  头寸数据内存化（预加载+实时更新，无磁盘IO）；
    
3.  计算逻辑极简（仅内存加减，无复杂运算）；
    
4.  与风控强联动（头寸是风控校验的核心依据）；
    
5.  支持异常回滚（如报单失败时头寸回补）。
    

### 示例代码如下（请注意：仅仅为示例代码）：

`#include <atomic>   #include <unordered_map>   #include <cstdint>   #include <immintrin.h>   #include <pthread.h>   #include <thread>      // 前置类型定义（保持原有架构兼容）   enumclass OrderType { BUY, SELL, CANCEL };   enumclass OrderStatus { NEW, FILLED, PARTIALLY_FILLED, CANCELLED, REJECTED };      // 因子结果结构体（原有）   struct FactorResult {       std::string stock_code;       double model_score;       int64_t last_price;       int64_t timestamp;   };      // 订单结构体（补充头寸相关字段）   struct Order {       OrderType type;       std::string stock_code;       int64_t price;       uint64_t quantity;       // 报单数量       uint64_t filled_quantity; // 成交数量（柜台返回更新）       int64_t timestamp;       uint64_t order_id;       // 唯一订单ID       OrderStatus status;      // 订单状态（柜台返回更新）   };      // 头寸数据结构体（内存化，按股票维度存储）   struct PositionInfo {       alignas(64) int64_t available = 0;    // 可用头寸（可交易数量）       alignas(64) int64_t frozen = 0;       // 冻结头寸（报单未成交的数量）       alignas(64) int64_t total = 0;        // 总头寸（available + frozen）       alignas(64) double avg_cost = 0.0;    // 平均持仓成本（可选，按需保留）          // 头寸更新：报单时冻结       void freeze(uint64_t quantity, OrderType type) noexcept {           if (type == OrderType::BUY) {               // 买入冻结资金（此处简化为数量，实际可扩展资金头寸）               frozen += quantity;               total += quantity; // 买入未成交也计入总头寸（或按需调整）           } elseif (type == OrderType::SELL) {               // 卖出冻结持仓               available -= quantity;               frozen += quantity;           }       }          // 头寸更新：成交/撤单时解冻       void unfreeze(uint64_t quantity, OrderType type, OrderStatus status) noexcept {           if (status == OrderStatus::FILLED || status == OrderStatus::PARTIALLY_FILLED) {               // 成交：冻结转可用（卖出）/ 冻结清零（买入）               if (type == OrderType::BUY) {                   frozen -= quantity;                   available += quantity;               } elseif (type == OrderType::SELL) {                   frozen -= quantity;                   total -= quantity; // 卖出成交减少总头寸               }           } elseif (status == OrderStatus::CANCELLED || status == OrderStatus::REJECTED) {               // 撤单/拒单：冻结全额回滚               if (type == OrderType::BUY) {                   frozen -= quantity;                   total -= quantity;               } elseif (type == OrderType::SELL) {                   frozen -= quantity;                   available += quantity;               }           }       }   };      // 单生产者单消费者无锁队列（原有）   template <typename T, size_t CAPACITY>   class SPSCRingBuffer {   private:       alignas(64) std::array<T, CAPACITY> buffer_;       alignas(64) std::atomic<size_t> write_idx_{0};       alignas(64) std::atomic<size_t> read_idx_{0};      public:       bool push(const T& data) noexcept {           size_t curr_write = write_idx_.load(std::memory_order_relaxed);           size_t next_write = (curr_write + 1) & (CAPACITY - 1); // 2的幂优化           if (next_write == read_idx_.load(std::memory_order_acquire)) {               returnfalse;           }           buffer_[curr_write] = data;           write_idx_.store(next_write, std::memory_order_release);           returntrue;       }          bool pop(T& data) noexcept {           size_t curr_read = read_idx_.load(std::memory_order_relaxed);           if (curr_read == write_idx_.load(std::memory_order_acquire)) {               returnfalse;           }           data = buffer_[curr_read];           read_idx_.store((curr_read + 1) & (CAPACITY - 1), std::memory_order_release);           returntrue;       }   };      // 风控模块（整合头寸校验）   class RiskControlModule {   private:       // 头寸容器：股票代码 -> 头寸信息（单线程访问，无锁）       std::unordered_map<std::string, PositionInfo> position_map_;       // 风控阈值（预加载，内存化）       uint64_t max_single_order_quantity = 1000;  // 单笔最大报单量       int64_t max_total_position = 10000;         // 单股票最大总头寸       double max_position_ratio = 0.1;            // 头寸占比阈值（可选）      public:       void init(const std::string& config_path) noexcept {           // 模拟加载配置：实际从内存配置（如json解析后存入内存）           max_single_order_quantity = 1000;           max_total_position = 10000;           // 预加载初始头寸（如从柜台查询后存入内存）           position_map_["000001"] = {1000, 0, 1000, 10.5}; // 示例：平安银行初始头寸           position_map_["600000"] = {2000, 0, 2000, 9.8};  // 示例：浦发银行初始头寸       }          // 核心：风控校验（包含头寸校验）       bool check(const Order& pre_order) noexcept {           // 1. 基础量校验（极简逻辑，内存判断）           if (pre_order.quantity == 0 || pre_order.quantity > max_single_order_quantity) {               returnfalse;           }              // 2. 头寸校验（核心）           auto it = position_map_.find(pre_order.stock_code);           if (it == position_map_.end()) {               // 无头寸记录：买入允许（初始化头寸），卖出拒绝               return pre_order.type == OrderType::BUY;           }              PositionInfo& pos = it->second;           if (pre_order.type == OrderType::BUY) {               // 买入校验：总头寸不超限               if (pos.total + pre_order.quantity > max_total_position) {                   returnfalse;               }           } elseif (pre_order.type == OrderType::SELL) {               // 卖出校验：可用头寸足够               if (pos.available < pre_order.quantity) {                   returnfalse;               }           }              // 3. 其他风控规则（如价格偏离、频次限制，按需添加）           returntrue;       }          // 对外暴露头寸更新接口（单线程调用，无锁）       void update_position(const Order& order) noexcept {           auto it = position_map_.find(order.stock_code);           if (it == position_map_.end() && order.type == OrderType::BUY) {               // 买入新股票：初始化头寸               PositionInfo new_pos;               new_pos.freeze(order.quantity, order.type);               position_map_[order.stock_code] = new_pos;           } elseif (it != position_map_.end()) {               // 已有头寸：更新               if (order.status == OrderStatus::NEW) {                   // 报单成功：冻结头寸                   it->second.freeze(order.quantity, order.type);               } else {                   // 成交/撤单/拒单：解冻头寸                   it->second.unfreeze(order.filled_quantity, order.type, order.status);               }           }       }          // 按需查询头寸（如监控用，单线程）       const PositionInfo* get_position(const std::string& stock_code) const noexcept {           auto it = position_map_.find(stock_code);           return it == position_map_.end() ? nullptr : &(it->second);       }   };      // 柜台API（补充订单状态回调，用于头寸回补）   class TradingCounterAPI {   private:       int sock_fd_; // 非阻塞socket       RiskControlModule* risk_module_; // 关联风控模块，用于回调更新头寸          // 订单状态回调（模拟柜台返回）       void on_order_status(const Order& order) noexcept {           // 回调到风控模块更新头寸（单线程，无锁）           if (risk_module_) {               risk_module_->update_position(order);           }       }      public:       void init(const std::string& config_path) noexcept {           // 模拟初始化非阻塞socket、建立长连接           sock_fd_ = 1;       }          // 关联风控模块（用于订单状态回调更新头寸）       void bind_risk_module(RiskControlModule* risk_module) noexcept {           risk_module_ = risk_module;       }          // 零拷贝报单（sendmsg+iovec，简化实现）       bool send_order(const Order& pre_order) noexcept {           // 1. 构造订单（零拷贝：直接引用内存数据，不拷贝）           Order order = pre_order;           order.order_id = rand() % 1000000; // 生成唯一订单ID（实际用全局递增）           order.status = OrderStatus::NEW;              // 2. 非阻塞发送（模拟零拷贝sendmsg）           bool send_ok = true; // 实际判断socket发送结果              if (send_ok) {               // 报单成功：立即更新头寸（冻结）               risk_module_->update_position(order);                  // 模拟柜台异步返回订单状态（如成交/撤单）               // 实际场景：低优先级线程监听柜台回执，回调on_order_status               // 示例：成交50%               Order filled_order = order;               filled_order.filled_quantity = order.quantity / 2;               filled_order.status = OrderStatus::PARTIALLY_FILLED;               on_order_status(filled_order);           } else {               // 报单失败：不更新头寸，异步重试（低优先级线程处理）               returnfalse;           }           returntrue;       }   };      // 策略+风控+报单+头寸计算（单线程，绑定CPU 2）   class StrategyRiskOrderEngine {   private:       SPSCRingBuffer<FactorResult, 8192>* factor_queue_;       std::thread engine_thread_;       RiskControlModule risk_module_;  // 风控模块（内含头寸计算）       TradingCounterAPI counter_api_;  // 柜台API（零拷贝封装）          // 绑核工具函数（简化版）       void bind_thread_to_cpu(std::thread& t, int cpu_id) noexcept {           cpu_set_t cpuset;           CPU_ZERO(&cpuset);           CPU_SET(cpu_id, &cpuset);           pthread_setaffinity_np(t.native_handle(), sizeof(cpu_set_t), &cpuset);       }      public:       StrategyRiskOrderEngine(SPSCRingBuffer<FactorResult, 8192>* factor_q)            : factor_queue_(factor_q) {           // 初始化风控（预加载头寸+阈值）、柜台API           risk_module_.init("risk_config.json");           counter_api_.init("counter_config.json");           // 柜台绑定风控模块（用于订单状态回调更新头寸）           counter_api_.bind_risk_module(&risk_module_);              // 启动单线程并绑定CPU 2           engine_thread_ = std::thread(&StrategyRiskOrderEngine::run, this);           bind_thread_to_cpu(engine_thread_, 2);       }          // 析构：保证线程退出（原有架构补充）       ~StrategyRiskOrderEngine() {           if (engine_thread_.joinable()) {               engine_thread_.join();           }       }          void run() noexcept {           FactorResult fr;           while (true) {               // 读取因子结果（自旋等待，低时延）               while (!factor_queue_->pop(fr)) {                   _mm_pause();               }                  // 1. 策略逻辑：基于模型分数生成预订单               Order pre_order;               if (fr.model_score > 0.8) {  // 买入阈值                   pre_order.type = OrderType::BUY;                   pre_order.stock_code = fr.stock_code;                   pre_order.price = fr.last_price;                   pre_order.quantity = 100;  // 最小单位                   pre_order.timestamp = fr.timestamp;                   pre_order.status = OrderStatus::NEW; // 初始状态               } elseif (fr.model_score < -0.8) {  // 卖出阈值                   pre_order.type = OrderType::SELL;                   pre_order.stock_code = fr.stock_code;                   pre_order.price = fr.last_price;                   pre_order.quantity = 100;                   pre_order.timestamp = fr.timestamp;                   pre_order.status = OrderStatus::NEW;               } else {                   continue;  // 无订单               }                  // 2. 风控校验（包含头寸校验，单线程无锁）               if (!risk_module_.check(pre_order)) {                   continue;  // 风控拒绝（头寸不足/超限）               }                  // 3. 报送至交易柜台（零拷贝，报单成功则冻结头寸）               counter_api_.send_order(pre_order);           }       }          // 对外暴露头寸查询接口（单线程，无锁）       const PositionInfo* get_position(const std::string& stock_code) const noexcept {           return risk_module_.get_position(stock_code);       }   };      // 测试代码   int main() {       // 初始化因子队列       SPSCRingBuffer<FactorResult, 8192> factor_queue;       // 初始化策略引擎       StrategyRiskOrderEngine engine(&factor_queue);          // 模拟推送因子结果       FactorResult fr;       fr.stock_code = "000001";       fr.model_score = 0.9; // 触发买入       fr.last_price = 1050; // 10.50元（整数化）       fr.timestamp = 1710000000000000;       factor_queue.push(fr);          // 运行1秒后查询头寸       std::this_thread::sleep_for(std::chrono::seconds(1));       const PositionInfo* pos = engine.get_position("000001");       if (pos) {           printf("Stock: 000001, Available: %ld, Frozen: %ld, Total: %ld\n",                  pos->available, pos->frozen, pos->total);       }          return0;   }   `

### 头寸计算模块的核心设计要点

#### 1\. 头寸数据结构优化

-   **缓存对齐**：`PositionInfo`的核心字段（`available`/`frozen`/`total`）均64字节对齐，避免缓存行伪共享；
    
-   **内存化存储**：头寸数据存储在`std::unordered_map`（单线程访问无锁），无磁盘IO，查询时延纳秒级；
    
-   **极简计算逻辑**：仅做内存加减运算，无复杂公式，保证低时延。
    

#### 2\. 头寸更新的核心时机

场景

头寸操作

触发时机

报单成功

买入：冻结资金/总头寸+N；卖出：可用头寸-N、冻结+N

柜台`send_order`成功后

订单成交/部分成交

冻结头寸-N，可用头寸+N（买入）；冻结-N、总头寸-N（卖出）

柜台回调`on_order_status`

订单撤单/拒单

冻结头寸全额回滚（恢复可用/总头寸）

柜台回调`on_order_status`

#### 3\. 与风控的强联动

#### 高频交易，或者任何程序化交易，虽然和公募基金、资产管理投资交易中几百条风控规则没法比，但基本的流速控制、自成交等还是比较要做，但风控模块天生就是高频策略最难受的功能，不管怎么设计的优雅和高效，加了这个模块，多加一个风控逻辑，就一定要牺牲链路延时。所以在高频系统中设计风控模块就不能用交易系统中风控模块的惯性思维，而是要有一些奇思妙想的思路。

-   头寸校验是风控的核心规则（卖出时校验可用头寸、买入时校验总头寸上限）；
    
-   风控模块内置头寸容器，避免跨模块数据拷贝，校验逻辑仅内存判断；
    
-   头寸更新由风控模块统一管理，保证数据一致性（单线程内无并发问题）。
    

#### 4\. 低时延保障（贴合原有架构）

-   **无锁设计**：头寸计算/更新均在单线程内完成，无互斥锁/原子操作开销；
    
-   **零拷贝**：柜台报单仍使用`sendmsg+iovec`零拷贝，头寸更新仅操作内存引用；
    
-   **非阻塞**：柜台连接为非阻塞Socket，报单失败由低优先级线程重试，不阻塞核心线程；
    
-   **自旋等待**：因子队列读取用`_mm_pause()`自旋，避免系统调用时延。
    

### 其中具体细节点有：

1.  **订单ID生成**：实际场景需用全局递增的唯一ID（如原子计数器），避免重复；
    
2.  **异步回执处理**：柜台订单状态回执需由低优先级线程监听（如epoll），回调更新头寸，不占用核心线程；
    
3.  **头寸持久化**：可选低优先级线程定期将头寸数据写入磁盘（如每秒1次），核心线程不参与；
    
4.  **异常处理**：报单失败/网络中断时，头寸需回滚，可在重试线程中处理；
    
5.  **性能优化**：`std::unordered_map`可替换为`flat_hash_map`（如abseil库），进一步降低查询时延。
    

###   

### 在和AI的讨论过程中，AI提到一个之前也偶尔想起来的点：高频交易策略中的头寸设计通过将头寸容器整合至风控模块，实现风控校验与头寸计算一体化。

### 这样在无额外线程开销的前提下，采用内存化数据、极简计算逻辑与单线程无锁架构，贴合原有串行核心以保障低时延特性；同时头寸更新与订单状态强绑定，覆盖报单、成交、撤单全流程以确保数据一致，且仅补充头寸逻辑、兼容原有策略-风控-报单串行架构，既能满足高频交易端到端时延，又能保证头寸计算精准可靠。

### 值得思考。