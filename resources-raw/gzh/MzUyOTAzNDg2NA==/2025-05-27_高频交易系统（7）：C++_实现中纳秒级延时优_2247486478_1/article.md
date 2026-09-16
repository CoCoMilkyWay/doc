# 高频交易系统（7）：C++ 实现中纳秒级延时优化之代码调优

fintechhaibin FinTechHi 2025-05-27 21:19 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486478&idx=1&sn=e2d911d911aaee5ec459d23ba2c4a42e&chksm=fb3bb24ee7501bba6bfa9c2381f9db2a0733840492592c24829326b13caff0619214ce326c27#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486478&idx=1&sn=e2d911d911aaee5ec459d23ba2c4a42e&chksm=fb3bb24ee7501bba6bfa9c2381f9db2a0733840492592c24829326b13caff0619214ce326c27#rd)

因为整个演讲内容（CppCon2024，When Nanoseconds Matter：Ultrafast Trading Systems in C++）1小时半左右，主要包括了：订单薄、代码优化、延时测试，网络与并发（共享内存、队列）等主题。我分几篇文章来整理。

继续上篇：[高频交易系统（6）:纳秒至关重要：C++ 中的超快交易系统](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486440&idx=1&sn=0bd58a7fe7c2d166088aa4789a42278d&scene=21#wechat_redirect)

系统性能分析工具perf，这个工具上次在追踪系统热点功能时使用了，功能的确很强大。我们看作者的介绍。

![](assets/001.png)

在基准测试中运行`perf`工具：如果初始化函数耗时较长，不能直接在整个二进制文件上运行`perf`。可以通过`fork`创建子进程，在子进程中使用`execlp`执行`perf`命令。首次使用`perf`测量时，不要过于具体，例如可以使用如下命令：`   `

```
perf stat –I 10000 –M Frontend_Bound,Backend_Bound,Bad_Speculation,Retiring –p pid
```

`测量前端受限、后端受限、错误推测、指令退休等指标。`

![](assets/002.png)

展示`perf`测量指标相关的表格，包括流水线槽的占用情况、不同类型的受限情况等。

![](assets/003.png)

展示`perf`测量的具体数据示例，包括各种事件的计数和百分比，如：`   `

-   `de_src_op_disp.all:u`（25.0% 错误推测）、`   `
    
-   `ls_not_halted_cyc:u`（26.4% 指令退休）、`   `
    
-   `ex_ret_ops:u`（17.9% 后端受限）、`   `
    
-   `de_no_dispatch_per_slot.no_ops_from_frontend:u`（30.6% 前端受限）
    

  

![](assets/004.png)

使用`perf record –g –p <pid>`命令记录性能数据，展示具体的汇编代码片段，如`jle`、`mov`、`sar`等指令。

定义无分支二分查找函数`branchless_lower_bound，`通过减少分支预测错误来提高性能。

![](assets/005.png)

![](assets/006.png)

对比`lower_bound`和`branchless_lower_bound`的延迟分布：`   `

-   `lower_bound`中位数为 32.0 纳秒，`   `
    
-   `branchless_lower_bound`中位数为 29.0 纳秒。
    

  

![](assets/007.png)

使用`libpapi`库获取硬件计数器数据，如指令数（`PAPI_TOT_INS`）、一级数据缓存缺失数（`PAPI_L1_DCM`）、周期数（`PAPI_TOT_CYC`）、分支预测错误数（`PAPI_BR_MSP`）等，并计算每周期指令数（IPC）。

对比`branchless_lower_bound`和`std::lower_bound`的 IPC、分支预测错误数（百万次）、周期数（十亿次）、指令数（十亿次）等指标。

![](assets/008.png)

对比`branchless_lower_bound`和线性搜索的延迟分布：`   `

-   `branchless_lower_bound`中位数为 29.0 纳秒。
    
-   线性搜索中位数为 22.0 纳秒。
    

  

![](assets/009.png)

上图通过简洁直观的设计，将二分查找的算法步骤和内存访问过程清晰地呈现出来：

第一行数字：数字从0到30排列在白色背景的方格内，部分数字间有黑色箭头指示查找路径。这部分数字序列模拟了二分查找算法在数据集合中的操作过程。二分查找是一种高效的查找算法，它每次将查找范围缩小一半，通过黑色箭头可以清晰地看到算法是如何逐步定位目标元素的。黑色箭头的指向展示了算法在每一步所做出的选择，例如是向左半部分还是右半部分继续查找，帮助观看者理解二分查找的执行逻辑。

第二行数字：同样是从0到30排列，但数字所在的方格背景为红色，并且部分数字被红色突出显示。这可能是为了模拟内存访问的过程，红色突出显示的数字或许代表在二分查找过程中实际被访问到的内存位置。在计算机系统中，二分查找需要通过内存访问来获取数据，这一行数字以直观的方式展示了在执行二分查找时内存的使用情况，让观看者能够将算法操作与实际的内存访问联系起来。

![](assets/010.png)

对比`branchless_lower_bound`和线性搜索的延迟分布：`   `

-   `branchless_lower_bound`中位数为 29.0 纳秒，
    
-   线性搜索中位数为 22.0 纳秒
    

  

关于缓存命中，这里详细说明下：

分享中作者分为**代码逻辑**和**汇编指令**两部分，并结合 `likely/unlikely` 属性说明其对性能。

在高频交易系统中，订单簿需要快速更新或插入【价格-成交量】数据。此函数通过高效查找和分支预测优化，提升性能。

![](assets/011.png)

```
template <class T, class Compare>
```

使用`[[likely]]`和`[[unlikely]]`属性来优化指令缓存（I-Cache）命中率。

-   **查找价格：在容器** `levels` 中搜索是否存在目标价格 `price`。
    
-   如果找到且价格匹配（`likely` 分支），则直接增加对应位置的成交量。
    

-   如果未找到（`unlikely` 分支），则插入新的价格-成交量对。
    

  

具体到代码中：

-   `std::ranges::find_if`：  
    遍历容器 `levels`，通过自定义比较器 `comp` 查找第一个满足 `comp(p.first, price)` 的元素 `p`（即价格匹配）。
    
-   `[[likely]]` 和 `[[unlikely]]`：  
    编译器提示，指示 `if` 分支（价格匹配）是高频路径，`else` 分支（插入新数据）是低频路径。编译器会据此优化分支预测，减少指令流水线停顿。
    

  

![](assets/012.png)

上方是 C++ 代码，下方是对应的汇编指令（伪代码形式），分为两个分支：

1.  **`.L2` 分支**（`likely` 路径，价格匹配时执行）：
    

-   指令较少，直接更新成交量（如 `add` 操作）。
    

3.  **`.L1` 分支**（`unlikely` 路径，插入新数据时执行）：
    

-   指令较多，涉及内存分配和数据移动（如 `insert` 操作）。
    

#### **关键汇编指令**

-   `cmp` / `je` / `jne`：  
    比较价格并跳转至对应分支（`je` 表示相等跳转，`jne` 表示不等跳转）。
    
-   `add`：  
    在 `likely` 分支中直接增加成交量。
    
-   **`insert` 相关指令**：  
    在 `unlikely` 分支中可能涉及动态内存分配（如 `malloc`）或链表节点插入。
    

#### **`通过上述分析，likely/unlikely` 的作用**

-   **分支预测优化**：编译器会根据提示将高频路径（`likely`）的指令放在主执行路径上，减少分支跳转带来的性能损失（如流水线清空）。  
    
-   **缓存局部性**：高频路径的代码更可能驻留在 CPU 缓存中，降低 I-Cache Miss 概率。  
    

#### **在交易系统开发中：**

-   **如果是高频场景（价格匹配）**：直接更新操作（`add`）在 `likely` 分支中执行，速度更快。  
    
-   **低频场景（插入数据）**：即使 `unlikely` 分支指令较多，但由于执行概率低，对整体性能影响较小。
    

  

下图定义了一个名为 `DeleteOrder` 的模板函数，用于在容器 `levels` 中查找特定价格 `price` 对应的元素，减少其成交量 `volume`，并在成交量为非正时删除该元素。

![](assets/013.png)

```
/**
```

该函数旨在从容器 `levels` 中删除特定价格 `price` 对应的订单，并调整成交量。如果删除后成交量为零或负数，则从容器中移除该订单，实现细节如下：

-   查找元素：使用 std::ranges::find\_if 在容器 levels 中查找满足条件的元素。条件由 lambda 函数和比较器 comp 定义，确保找到价格匹配的元素。
    
-   断言检查：使用 EXPECT 宏（可能来自测试框架如 Google Test）确保找到的元素满足预期条件（即存在且价格匹配）。
    
-   减少成交量：找到元素后，减少其成交量 volume。
    
-   删除元素：如果减少后的成交量小于等于零，则从容器中删除该元素。
    

  

![](assets/014.png)

与第1张图类似，但在未找到元素时调用 `HandleError` 函数，并为该函数添加了 `noinline` 和 `cold` 属性。其中HandleError 函数优化点如下：

-   noinline 属性：指示编译器不要将 HandleError 函数内联到调用处，适用于不常执行的函数，以减少代码膨胀。
    
-   cold 属性：提示编译器该函数属于“冷路径”，即执行频率较低，编译器可以将其放置在内存中不常访问的区域，优化缓存使用。
    

  

![](assets/015.png)

-   `mov DWORD PTR [rsp+12], edx`：将寄存器 `edx` 的值存储到栈上偏移量为 `rsp+12` 的位置。为函数调用准备参数。
    
-   `call DeleteOrder(...)`：调用 `DeleteOrder` 函数，并传递相应的参数。
    
-   `jmp L6`：跳转到标签 `L6`，表示函数调用后的继续执行流程。
    
-   `61`：地址或标签的占位符。
    

  

通过汇编代码，了解编译器在生成汇编代码时的优化策略，如内联、循环展开、指令重排等，有助于进一步优化代码性能。（ps:我们不要把低时延挂嘴边，而是有很多具体的点需要深入分析。光纤、绑核、FPGA、缓存、共享内存这些概念只是新闻或者谈论中听到的方式，不是方法。）

为什么说真功夫都在细节中，最近工作中发现一家低时延柜台厂商的代码素养果然很强，判断条件都带了分支预测，而且对一些类型字段值的比较，都不是直接做字符串比较，而是直接使用位运算，这些层面可能我们不扣低时延没有太多概念，但如果真正的在乎纳秒级的差别，且对实际策略有正向作用，那看似毫无用处的细节就值得研究。但现实中很多所谓的高频开发者，大部分都被安排了各种功能性、行情柜台接口层面的“体力活”任务，根本没有精力去深入这些需要学习和研究的

![](assets/016.png)

与 I-Cache Misses 和 IIFE 的关联：

-   I-Cache Misses（指令缓存未命中）：高效的代码布局和减少分支预测错误可以降低 I-Cache Misses，提高指令获取速度。likely/unlikely 提示（尽管在提供的代码中未明确使用）可以帮助编译器优化分支预测。
    
-   Immediately Invoked Function Expressions (IIFE)：虽然代码中未直接展示 IIFE，但在高性能编程中，IIFE 可用于封装逻辑，减少作用域污染和提升执行效率。结合汇编代码，可能涉及内联函数或优化后的函数调用方式。
    

  

下图对比了Lambda表达式与函数对象：

![](assets/017.png)

```
mBidsCompare = [](const std::pair<Price, Volume>& p, Price price) 
```

Lambda的核心是一个匿名函数对象，编译器会自动生成一个闭包类。编译期优化更彻底，性能略优于函数对象。但局限性是无法直接继承或复用，若需复用需重复定义。

再看下函数对象：

```
struct BidsCompare {
```

自定义类重载`operator()`。可继承和复用，支持更复杂的逻辑，以及明确的类名和成员函数，便于调试，但需显式定义类和构造函数。

在看下标准函数（std::function）实现：

```
std::function<bool(const std::pair<Price, Volume>&, Price)> mBidsCompare;
```

可存储任意可调用对象（Lambda、函数指针、Functor）。支持动态绑定和延迟执行。动态分配内存，性能略低（相比Lambda/Functor），同时可能导致编译期优化受限。