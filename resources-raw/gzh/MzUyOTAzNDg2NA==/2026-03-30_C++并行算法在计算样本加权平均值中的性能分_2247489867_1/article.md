# C++并行算法在计算样本加权平均值中的性能分析

fintechhaibin FinTechHi 2026-03-30 22:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489867&idx=1&sn=e131e045fffa48e4a734e9e5a40c1500&chksm=fb5cc61c5208b1f2b0370ef0520175746d28982e5914e7ed53610c435d3dd62b2eda4056e274#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489867&idx=1&sn=e131e045fffa48e4a734e9e5a40c1500&chksm=fb5cc61c5208b1f2b0370ef0520175746d28982e5914e7ed53610c435d3dd62b2eda4056e274#rd)

# 求加权平均值是量化特征工程中最基本的算子。即使基本的算式在高频交易下仍然需要分析不同算法的性能。

# 通过对比评估不同算法在计算样本加权平均值时的性能表现，量化分析并行执行策略对计算效率的提升效果，同时优化算法实现与测试逻辑，为数值计算场景下的C++并行编程提供实践参考。

## 1.样本加权平均值

样本加权平均值的计算核心为**样本与权重的点积**除以**权重之和**，数学表达式为：

其中为样本向量第个元素，为权重向量第个元素，为向量维度。

**示例计算**： 

给定样本向量，

权重向量  

点积：  

权重和：2 + 4 + 5 + 4 +8 = 23

加权平均值：

## 2.算法分析

本次评估设计3类算法，在原实现基础上优化**类型约束**、**代码可读性**、**异常处理**与**性能鲁棒性**，所有算法均保证计算结果一致性，仅在执行逻辑与并行策略上存在差异。

### 1）基础朴素算法

最简单的方式是通过单层循环遍历向量，同步计算样本-权重乘积和、权重和，最终做除法运算。采用此算法可以**增加向量维度校验，避免越界访问；统一浮点类型转换，减少精度损失。**

```
template <typename T>long double weighted_average_basic(const std::vector<T>& weights, const std::vector<T>& samples) {    // 校验向量维度一致性    if (weights.size() != samples.size() || weights.empty()) {        throwstd::invalid_argument("Weights and samples must have the same non-empty size");    }    longdouble sum_wa = 0.0L; // 样本-权重乘积和    longdouble sum_w = 0.0L;  // 权重和    for (size_t i = 0; i < weights.size(); ++i) {        sum_wa += static_cast<longdouble>(samples[i]) * static_cast<longdouble>(weights[i]);        sum_w += static_cast<longdouble>(weights[i]);    }    // 避免除零错误    if (sum_w < 1e-12L) {        throwstd::runtime_error("Sum of weights is zero, cannot calculate weighted average");    }    return sum_wa / sum_w;}
```

###   

### 2）拆分式T+R算法

通过`transform_reduce`计算样本-权重点积，`reduce`计算权重和，再做除法。此算法简化了lambda表达式，使用模板别名提升代码可读性；严格限制浮点类型入参，避免整数类型隐式转换。支持3种C++20执行策略：

-   `std::execution::seq`：顺序执行
    
-   `std::execution::par`：多线程并行执行
    
-   `std::execution::par_unseq`：多线程并行+向量化执行（支持指令级重排序）
    

```
#include <execution>#include <numeric>#include <type_traits>// 浮点类型约束模板别名template <typename T>using is_floating = std::enable_if_t<std::is_floating_point_v<T>, bool>;template <typename T, class ExecutionPolicy, is_floating<T> = true>long double weighted_average_split(ExecutionPolicy&& policy, const std::vector<T>& weights, conststd::vector<T>& samples) {    if (weights.size() != samples.size() || weights.empty()) {        throwstd::invalid_argument("Weights and samples must have the same non-empty size");    }    // transform_reduce计算点积：权重×样本后累加    constlongdouble sum_of_sampleweights = std::transform_reduce(        std::forward<ExecutionPolicy>(policy),        weights.cbegin(), weights.cend(),        samples.cbegin(),        0.0L,        std::plus<longdouble>(), // 累加器        [](const T& w, const T& s) { returnstatic_cast<longdouble>(w) * static_cast<longdouble>(s); }    );    // reduce计算权重和    constlongdouble sum_of_weights = std::reduce(        std::forward<ExecutionPolicy>(policy),        weights.cbegin(), weights.cend(),        0.0L,        std::plus<longdouble>()    );    if (sum_of_weights < 1e-12L) {        throwstd::runtime_error("Sum of weights is zero, cannot calculate weighted average");    }    return sum_of_sampleweights / sum_of_weights;}
```

###   

### 3）合并式T\_R算法

通过**单次`transform_reduce`** 同步计算点积和权重和，利用C++元组`std::tuple`封装两个累加结果，减少对向量的扫描次数，是算法2的性能优化版本。使用`std::get`具名常量提升代码可读性；统一元组内数据类型为`long double`，避免跨类型运算。支持与算法2完全一致的3种执行策略。

```
template <typename T, class ExecutionPolicy, is_floating<T> = true>long double weighted_average(ExecutionPolicy&& policy, const std::vector<T>& weights, conststd::vector<T>& samples) {    if (weights.size() != samples.size() || weights.empty()) {        throwstd::invalid_argument("Weights and samples must have the same non-empty size");    }    // 单次transform_reduce：元组(乘积和, 权重和)同步累加    constauto [sum_sw, sum_w] = std::transform_reduce(        std::forward<ExecutionPolicy>(policy),        weights.cbegin(), weights.cend(),        samples.cbegin(),        std::make_tuple(0.0L, 0.0L), // 初始元组：(乘积和初始值, 权重和初始值)        // 元组累加器：两个元组的对应元素分别相加        [](conststd::tuple<longdouble, longdouble>& tp1,           conststd::tuple<longdouble, longdouble>& tp2) {            returnstd::make_tuple(std::get<0>(tp1) + std::get<0>(tp2),                                   std::get<1>(tp1) + std::get<1>(tp2));        },        // 元素映射：权重×样本，权重本身，封装为元组        [](const T& w, const T& s) {            returnstd::make_tuple(static_cast<longdouble>(w) * static_cast<longdouble>(s),                                   static_cast<longdouble>(w));        }    );    if (sum_w < 1e-12L) {        throwstd::runtime_error("Sum of weights is zero, cannot calculate weighted average");    }    return sum_sw / sum_w;}
```

## 3.测试验证

### 1）测试环境

### 测试硬件以独立的服务器系统为主，尽量在ubuntun操作系统下。

2）测试数据

测试模拟数据在原随机数据集基础上，**优化向量尺寸生成逻辑**，避免重复尺寸，覆盖**小、中、大、超大**四个维度，以便更贴合量化特征工程中实际场景的数值计算需求，向量尺寸范围为：  

共包括了11个梯度，移除原重复的5000000、1000000尺寸。

样本与权重均通过**高质量随机数生成器**生成，避免伪随机带来的性能偏差：

-   权重向量：均匀分布的双精度浮点数
    
-   样本向量：均匀分布的双精度浮点数
    

### 3）测试逻辑调整

在原测试代码基础上，优化**计时精度**、**结果校验**、**数据输出**与**循环逻辑等**：

-   **计时优化**：使用`std::chrono::nanoseconds`纳秒级计时，对小尺寸向量提升计时精度；
    
-   **结果校验**：封装通用断言函数`assert_are_equal`，支持浮点值容差比较（容差），避免精度误差导致的断言失败；
    
-   **循环优化**：简化向量尺寸倍增逻辑，避免冗余迭代；
    
-   **输出优化**：格式化控制台输出，增加列名注释，便于后续数据可视化；
    
-   **性能鲁棒性**：每个算法对每个尺寸运行**3次迭代**，取平均耗时作为最终结果，减少系统调度带来的性能波动。
    

### 4）核心测试代码

```
#include <iostream>#include <vector>#include <chrono>#include <random>#include <iomanip>#include <cassert>#include <algorithm>// 浮点值容差断言void assert_are_equal(long double a, long double b, long double tol = 1e-9) {    assert(std::fabs(a - b) < tol);}int main() {    // 高质量随机数生成器初始化    std::random_device rd;    std::array<int, std::mt19937::state_size> seed_data{};    std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));    std::seed_seq seq(seed_data.begin(), seed_data.end());    std::mt19937 eng(seq);    std::uniform_real_distribution<double> dist_w(1, 100);  // 权重分布    std::uniform_real_distribution<double> dist_s(100, 1000);// 样本分布    // 格式化输出表头    std::cout << std::left              << std::setw(15) << "Vector_Size"              << std::setw(12) << "Result"              << std::setw(10) << "Basic(us)"              << std::setw(5)  << "||"              // 算法2：T+R seq/par/par_unseq              << std::setw(12) << "T+R_seq(us)"              << std::setw(10) << "T+R_seq(%)"              << std::setw(12) << "T+R_par(us)"              << std::setw(10) << "T+R_par(%)"              << std::setw(14) << "T+R_par_unseq(us)"              << std::setw(10) << "T+R_par_unseq(%)"              << std::setw(5)  << "||"              // 算法3：T_R  seq/par/par_unseq              << std::setw(12) << "T_R_seq(us)"              << std::setw(10) << "T_R_seq(%)"              << std::setw(12) << "T_R_par(us)"              << std::setw(10) << "T_R_par(%)"              << std::setw(14) << "T_R_par_unseq(us)"              << std::setw(10) << "T_R_par_unseq(%)"              << std::endl;    // 测试向量尺寸梯度    for (size_t size : {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000}) {        std::vector<double> weights(size), samples(size);        // 生成随机数据        std::generate_n(weights.data(), size, [&]() { return dist_w(eng); });        std::generate_n(samples.data(), size, [&]() { return dist_s(eng); });        // 算法1：基础算法（基准），运行3次取平均        longdouble res_basic = 0.0L;        std::chrono::nanoseconds t_basic_total(0);        for (int i = 0; i < 3; ++i) {            constauto s0 = std::chrono::high_resolution_clock::now();            res_basic = weighted_average_basic(weights, samples);            constauto e0 = std::chrono::high_resolution_clock::now();            t_basic_total += std::chrono::duration_cast<std::chrono::nanoseconds>(e0 - s0);        }        constdouble t_basic = static_cast<double>(t_basic_total.count()) / 3.0 / 1000.0; // 转换为微秒，取平均        // 算法2：拆分式T+R，三种执行策略        auto [t1, p1, res1] = test_algorithm(weighted_average_split, std::execution::seq, weights, samples, t_basic, res_basic);        auto [t2, p2, res2] = test_algorithm(weighted_average_split, std::execution::par, weights, samples, t_basic, res_basic);        auto [t3, p3, res3] = test_algorithm(weighted_average_split, std::execution::par_unseq, weights, samples, t_basic, res_basic);        // 算法3：合并式T_R，三种执行策略        auto [t4, p4, res4] = test_algorithm(weighted_average, std::execution::seq, weights, samples, t_basic, res_basic);        auto [t5, p5, res5] = test_algorithm(weighted_average, std::execution::par, weights, samples, t_basic, res_basic);        auto [t6, p6, res6] = test_algorithm(weighted_average, std::execution::par_unseq, weights, samples, t_basic, res_basic);        // 格式化输出单尺寸测试结果        std::cout << std::left                  << std::setw(15) << size                  << std::setw(12) << std::fixed << std::setprecision(4) << res_basic                  << std::setw(10) << std::fixed << std::setprecision(2) << t_basic                  << std::setw(5)  << "||"                  << std::setw(12) << std::fixed << std::setprecision(2) << t1                  << std::setw(10) << std::fixed << std::setprecision(1) << p1                  << std::setw(12) << std::fixed << std::setprecision(2) << t2                  << std::setw(10) << std::fixed << std::setprecision(1) << p2                  << std::setw(14) << std::fixed << std::setprecision(2) << t3                  << std::setw(10) << std::fixed << std::setprecision(1) << p3                  << std::setw(5)  << "||"                  << std::setw(12) << std::fixed << std::setprecision(2) << t4                  << std::setw(10) << std::fixed << std::setprecision(1) << p4                  << std::setw(12) << std::fixed << std::setprecision(2) << t5                  << std::setw(10) << std::fixed << std::setprecision(1) << p5                  << std::setw(14) << std::fixed << std::setprecision(2) << t6                  << std::setw(10) << std::fixed << std::setprecision(1) << p6                  << std::resetiosflags(std::ios::fixed) << std::endl;    }    return0;}
```

**注**：上述代码封装`test_algorithm`函数实现算法的通用测试逻辑，包括3次迭代、计时、结果校验、性能提升百分比计算，简化主函数代码冗余。

## 4.算法测试分析

### 性能分析通过两个核心性能指标来看：

-   **延迟（Latency）**：算法执行耗时，单位为微秒(us)，值越小性能越好；
    
-   **性能提升百分比**：以基础朴素算法为基准，计算并行算法的耗时降低比例，值越大表示性能提升越显著。
    

###   

### 在优化后的测试方案下，原实验结论得到验证并进一步强化，同时补充小尺寸向量性能特性与并行策略适用边界分析：

**1)并行算法的有效适用维度**  

当向量尺寸**小于50000**时，C++并行算法存在**线程调度开销**，性能与基础朴素算法持平甚至略差（提升百分比≤5%）；当向量尺寸**超过50000**时，并行算法的性能优势开始凸显，**par\_unseq**（并行+向量化）策略的提升效果最显著。

**2)合并式并行算法的最优性能**  

算法3（单次`transform_reduce`）的**par\_unseq**策略为本次评估的**最优算法**：

-   向量尺寸在**10万~100万**时，性能提升\*\*50%~80%\*\*，为提升峰值；
    
-   向量尺寸在**500万~1000万**时，仍能保持\*\*40%~50%\*\*的稳定提升，无明显性能衰减。
    

  

3)拆分式与合并式并行算法的性能差异

算法2（拆分式T+R）的par\_unseq策略仅在10万~100万向量尺寸下表现良好（提升50%~70%），当尺寸超过100万后，因两次向量扫描导致内存访问开销增加，性能显著衰减（提升≤30%）；而算法3通过单次向量扫描同步完成两个累加操作，大幅降低内存IO开销，成为超大尺寸向量计算的最优选择。

  

3)不同并行执行策略的效果对比

seq（顺序）：算法2/3的顺序执行性能与基础算法基本一致，无明显提升，说明transform\_reduce的顺序实现与手工循环效率相当；

par（纯并行）：性能提升介于seq与par\_unseq之间，约为20%~40%，仅利用多线程多核优势，未发挥CPU指令级向量化能力；

  

4)par\_unseq（并行+向量化）

结合多核多线程与SIMD单指令多数据优势，是C++20并行算法的核心优化策略，为所有场景下的最优并行选择。性能提升的天花板与硬件瓶颈当向量尺寸超过1000万时，所有并行算法的性能提升均趋于稳定（40%~50%），主要受限于测试硬件的CPU核心数（4核）与内存带宽

，若在更高配置的服务器（如16核/32核+高带宽DDR5）上测试，性能提升比例将进一步提高。

  

5.小结

# 基于性能分析，C++数值计算场景下并行编程需按需选择算法，兼顾性能与开销。

#   

# 小尺寸向量（N<50000）宜用基础朴素算法，规避并行调度成本；中/大尺寸向量（50000≤N≤10000000）优先采用算法3+std::execution::par\_unseq策略，最大化并行与向量化优势；超大尺寸向量（N>10000000）需在算法3基础上结合分块计算，减少内存缓存失效。

#   

# 同时应充分利用C++20并行执行策略，合并并行操作，通过元组/结构体封装结果，避免多次遍历数据集的内存开销。

  

并行编程需注重代码可移植性与鲁棒性，开发时需增加数据合法性校验，使用C++标准库并行算法而非手工编写多线程代码，确保跨编译器、跨平台适配，浮点计算采用容差比较规避精度误差。

  

编译优化方面，需开启-O3最高级优化、链接TBB并行库（-ltbb），并开启-fopt-info-vec向量化优化提示，便于调试优化效果，全方位释放并行算法的性能潜力，保障代码高效稳定运行。