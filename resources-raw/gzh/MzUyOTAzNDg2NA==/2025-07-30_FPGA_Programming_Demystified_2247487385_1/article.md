# FPGA Programming Demystified

fintechhaibin FinTechHi 2025-07-30 00:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247487385&idx=1&sn=cf6c53c55831e804735add379dd155ae&chksm=fb818a76fa25261d2108b3c19ef8fdf409fe42cb208e9da6526b4c680131235765da945fed70#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487385&idx=1&sn=cf6c53c55831e804735add379dd155ae&chksm=fb818a76fa25261d2108b3c19ef8fdf409fe42cb208e9da6526b4c680131235765da945fed70#rd)

> 原文：“Different” doesn’t mean “Difficult”: FPGA Programming Demystified

  

![](assets/001.png)

FPGA相比CPU、GPU的优势：

-   CPU、GPU：速度快但功耗高、效率低，指令集和内存架构固定，需开发者适配程序以契合架构 。 
    
-   FPGA：具备高吞吐量、低功耗、高效率特点，架构灵活且可完全定制，能让开发者根据程序需求适配架构 ，展现 FPGA 在架构定制等方面的优势。 
    

  

![](assets/002.png)

FPGA 是 “终极并行处理设备”，强调其在并行计算场景的核心优势，适合对并行效率、架构灵活度要求高的任务（如高频交易、AI 加速等 ）。

1.  **“No predefined instruction set or underlying architecture”**  
    FPGA没有 **预定义指令集** 和 **固定底层架构** ，区别于CPU（依赖x86/ARM等指令集）、GPU（依赖CUDA等框架指令）。开发者可完全自定义硬件逻辑，从底层重构计算流程。
    
2.  **“Developer customizes the architecture to his needs”**  
    开发者能根据 **业务需求定制架构** ，具体可自定义：
    

-   _Custom datapaths（自定义数据通路）_：按需设计数据流转路径，减少冗余传输。
    
-   _Custom bit-width（自定义位宽）_：比如处理加密算法时，可适配AES的128/256位宽，无需像CPU/GPU“按通用位宽（如64位）强制转换”。
    
-   _Custom memory hierarchies（自定义存储层级）_：灵活设计缓存、内存调用逻辑，适配低延迟场景（如高频交易需“数据直存特定缓存”）。
    

4.  **“Excels at all types of parallelism”**  
    FPGA **擅长各类并行计算场景** ，覆盖不同任务对“并行模式”的需求：
    

-   _Deeply pipelined（深度流水线，如视频编解码）_：把任务拆成多阶段（如“解码→滤波→输出”），像工厂流水线一样并行处理，提升吞吐。
    
-   _Bit manipulations（位操作，如AES、SHA加密）_：直接对二进制位高效运算，适配加密算法对“位级并行”的需求。
    
-   _Wide datapath（宽数据通路，如DNN）_：支持大规模数据并行（如AI推理时，多路神经元同时计算 ）。
    
-   _Custom memory hierarchy（自定义存储层级，如数据分析）_：为数据分析定制“数据缓存→计算→写回”流程，减少等待时间。
    

6.  **“Adapts to evolving algorithms and workload needs”**  
    FPGA可 **适配算法迭代和业务负载变化** 。比如AI算法从CNN转向Transformer，或高频交易策略升级时，FPGA无需更换硬件，只需重新定义硬件逻辑就能适配，比CPU/GPU（依赖“软件框架升级+指令集兼容”）更灵活。
    

  

![](assets/003.png)

  

这是Xilinx（赛灵思，已被 AMD 收购 ）Alveo 系列 FPGA 加速卡两个主要产品。不同产品对比图如下：

**参数**

**Alveo U200**

**Alveo U250**

**Alveo U30**

（侧重视频/边缘）

**Alveo U55C**

（新架构代表）

**典型场景**

**制程工艺**

16nm

16nm

16nm

7nm

工艺越新，功耗比、算力密度越高

**INT8 峰值算力**

18.6 TOPS

33.3 TOPS

400+ GOPs（视频场景优化）

超 100 TOPS（7nm 能效优化）

越高越适配 AI 推理、密集计算

**DDR 内存带宽**

77 GB/s

77 GB/s

102 GB/s（适配视频流）

100+ GB/s（新内存控制器）

影响“内存→FPGA 计算”的数据传输效率

**内部 SRAM 带宽**

31 TB/s

38 TB/s

\-（侧重外存交互，简化缓存）

超 40 TB/s（新缓存架构）

低延迟任务（如高频交易）核心指标

**逻辑单元（LUTs）**

892,000

1,341,000

2.5 百万+（视频加速定制逻辑）

超 3 百万（7nm 高密度）

越多越支持复杂硬件逻辑定制（如算法硬编码）

**典型接口/形态**

PCIe 3.0

PCIe 3.0

PCIe 3.0 + 视频专用接口

PCIe 4.0/5.0（适配新服务器）

接口决定与主机/外设的兼容性

**核心定位**

平衡型：中等算力+低延迟

高性能：高算力+高带宽

视频/边缘：专用视频加速

新架构：7nm + 异构协同优化

按场景选：AI 推理选 U55C，视频选 U30

**功耗（典型）**

~30 - 50W

~50 - 70W

~25 - 40W（低功耗边缘适配）

~40 - 60W（7nm 能效优势）

数据中心关注“算力/功耗比”，边缘看低功耗

**行业适配**

通用加速（如数据预处理）

金融/AI 推理（高算力）

智能视频分析（如监控、直播）

大模型推理、异构计算（CPU+FPGA）

金融选 U250/U55C，视频选 U30

  

在高频交易场景中，对硬件的低延迟、高带宽以及灵活定制化能力有着极高的要求 ，重点关注一下两个产品：

  

-   **Alveo U250**

-   **算力优势**
    
    ：拥有 33.3 Peak INT8 TOPs 的算力，能够快速处理复杂的交易策略和市场数据的分析。在高频交易中，需要实时计算订单的最优价格、数量等，较高的算力可以确保这些计算迅速完成，及时捕捉市场机会。
    
-   **带宽优势**
    
    ：77GB/s 的 DDR 内存带宽以及 38TB/s 的内部 SRAM 带宽，能保障数据在内存、缓存与 FPGA 计算单元之间快速传输。高频交易中，大量的实时市场数据（如报价、成交量等）需要快速读取和处理，高带宽可以减少数据传输的等待时间，降低延迟。
    
-   **逻辑单元优势**
    
    ：1,341,000 个 LUTs 提供了丰富的硬件逻辑定制资源。高频交易策略通常复杂且独特，需要根据市场变化灵活调整，丰富的逻辑单元允许开发者定制专用的硬件逻辑来加速交易算法，比如快速的订单匹配逻辑、风险评估逻辑等。
    

  

-   **Alveo U55C**

-   **制程工艺优势**
    
    ：基于 7nm 制程工艺，相比老款产品，在功耗降低的同时，实现了更高的算力密度。高频交易系统通常部署在数据中心，对设备的功耗和散热有严格要求，7nm 工艺有助于降低运营成本，同时支持更强大的计算能力。
    
-   **高性能算力**
    
    ：INT8 峰值算力超 100 TOPS，能够更快速地处理大规模的市场数据和复杂的交易算法。高频交易中，微秒甚至纳秒级的计算延迟都可能影响交易结果，强大的算力可以确保交易决策迅速做出。
    
-   **内存带宽优势**
    
    ：100+GB/s 的 DDR 内存带宽和超 40TB/s 的内部 SRAM 带宽，进一步提升了数据传输速度。高频交易对数据的实时性要求极高，更快的数据传输可以使交易系统更快地响应市场变化，及时执行交易指令。
    
-   **异构协同优势**
    
    ：深度兼容 AMD 软件栈，能与 AMD 的 CPU 实现高效的异构协同。在高频交易系统中，除了 FPGA 进行定制化加速外，CPU 也需要处理一些通用的管理和控制任务，这种异构协同能力可以提升整个系统的运行效率。
    

  

二者对比如下：

产品型号

优势点

具体指标对高频交易的作用

潜在局限

Alveo U250

算力较高、带宽出色、逻辑单元丰富

33.3 Peak INT8 TOPs的算力，可快速处理交易策略计算；77GB/s DDR内存带宽与38TB/s内部SRAM带宽，能保障数据快速传输，减少延迟；1,341,000个LUTs ，方便定制独特交易算法的硬件逻辑 。

制程工艺为16nm，相比更先进工艺，功耗较高，在大规模部署时运营成本会增加；算力在应对未来更复杂交易策略时，可能存在瓶颈 。

Alveo U55C

先进制程、高性能算力、高带宽、异构协同

7nm制程工艺，降低功耗，适合数据中心大规模部署；INT8峰值算力超100 TOPS，能快速做出交易决策；100+GB/s DDR内存带宽和超40TB/s内部SRAM带宽，实现数据快速传输；与AMD CPU高效异构协同，提升系统整体效率 。

产品相对较新，生态系统的成熟度可能不如老产品，开发者适配成本可能较高；价格方面可能相对昂贵，增加前期投入成本 。

  

![](assets/004.png)

主要介绍了配套的开发工具的优势：

-   传统 FPGA 开发需从 “硬件电路设计” 到 “驱动编写” 全流程参与，门槛极高；
    
-   现成平台（如 Xilinx Alveo 系列 ）直接提供 “预制硬件 + 软件接口”，开发者不用碰硬件细节，**降低开发门槛**。
    

  

-   软件 API（如 Acceleration API ）：让主机应用轻松调用 FPGA；
    
-   硬件 API（如 AXI 接口规范 ）：规范 FPGA 内部模块交互，开发者只需 “专注业务逻辑硬编码”，不用设计硬件通信。
    

  

以 **高频交易** 为例：

  

-   传统方案：开发者需自己设计 FPGA 硬件、写驱动、调 PCIe，耗时耗力，延迟还可能因设计问题不稳定；
    
-   现成平台：直接用 Alveo 加速卡 + 预制 API，开发者 “写交易策略代码→通过 API 调用 FPGA 加速”，**把延迟从 “毫秒级” 压到 “微秒级”** ，同时大幅缩短开发周期。
    

  

![](assets/005.png)

  

用 “软件编程语言（C/C++）+ 异构计算框架（OpenCL）”，让 FPGA 加速对开发者更 “友好”。

#### 1\. x86 CPU 端

-   **“C/C++ code with OpenCL API calls”**：  
    开发者编写的 **“带 OpenCL API 调用的 C/C++ 代码”** ，作用是“发起加速任务”。
    

-   OpenCL 是“异构计算框架”，让代码能“识别并调用 FPGA 的硬件加速能力”，无需写硬件描述语言。
    
-   示例：高频交易系统中，用 C++ 写“交易策略逻辑”，通过 OpenCL API 把“订单匹配计算”交给 FPGA 加速。
    

-   **Host Application**（主机应用）：  
    运行在 CPU 上的“业务主程序”（如高频交易系统、AI 推理框架 ），负责“业务流程控制”（如数据输入、调用加速、结果输出 ）。
    
-   **Acceleration API**（加速 API）+ **Runtime and Drivers**（运行时与驱动）：
    

-   API 是“软件接口”，让 Host Application 能“调用 FPGA 加速”；
    
-   Runtime/Drivers 负责“硬件驱动”和“运行时环境”，保障 CPU 和 FPGA 间的数据传输、指令执行。
    

#### 2\. FPGA 端

-   **“C/C++ or OpenCL C”**：  
    开发者用 **“C/C++ 或 OpenCL C”** 编写的“加速逻辑代码”，作用是“定义 FPGA 要执行的硬件加速功能”。
    

-   OpenCL C 是 OpenCL 框架的“内核语言”，专门用于“描述硬件加速任务”（比如并行计算逻辑 ）；
    
-   这些代码会被“编译成 FPGA 能识别的硬件逻辑”（底层仍转成硬件电路，但上层用软件语言开发 ）。
    

-   **Accelerated Functions**（加速功能）：  
    FPGA 上“实际运行的硬件加速逻辑”，由“C/C++ 或 OpenCL C 代码编译而来”，比如“并行计算单元”“订单匹配硬件电路”。
    
-   **AXI Interfaces**（AXI 接口）+ **DMA Engine**（DMA 引擎）：
    

-   AXI 是 FPGA 内部的“高速数据交互标准”，保障 FPGA 内部模块（加速逻辑、内存 ）间高效通信；
    
-   DMA Engine 实现“直接内存访问”，让 FPGA 能**跳过 CPU 直接读写内存**，降低延迟（如高频交易中，市场数据“直接从内存→FPGA 处理” ）。
    

#### 3\. 连接与交互

-   **PCIe**：CPU 和 FPGA 之间的“高速总线”，负责传输“加速任务指令”和“数据”。
    
-   **User Application Code**（用户应用代码）：  
    泛指“开发者编写的业务代码”，通过 OpenCL API 调用 FPGA 加速，实现“软件逻辑 + 硬件加速”协同。
    
-   **Xilinx Acceleration Platform**（赛灵思加速平台）：  
    提供“硬件 + 软件”整套方案（如预制的 AXI 接口、DMA 引擎、OpenCL 支持 ），让开发者“开箱即用”，不用从零开发 FPGA 硬件。
    

案例，假设开发“高频交易系统”：

1.  用 C++ 写“交易策略主程序”（Host Application ），通过 OpenCL API 调用 FPGA 加速；
    
2.  用 OpenCL C 写“订单匹配加速逻辑”（Accelerated Functions ），编译后下载到 FPGA；
    
3.  市场数据通过 DMA Engine 直接进入 FPGA 处理，结果快速返回 CPU，实现“微秒级交易决策”。
    

![](assets/006.png)

写好带 OpenCL API 的代码，通过编译直接生成 FPGA 硬件逻辑。

![](assets/007.png)

加速卡的并行能力：

![](assets/008.png)

  

![](assets/009.png)

任务级并行（流水线中加速）：

通过 `#pragma HLS DATAFLOW` 指令，让 **“多个任务（func1/func2/func3）在循环中流水线执行”** 。在高频交易中，“行情接收→策略计算→订单发送” 三个任务，可像工厂流水线一样 “上一轮的策略计算” 和 “下一轮的行情接收” 同时进行，**提升任务吞吐**。

![](assets/010.png)

###   

### 指令级并行（单任务内并行）：

通过 “循环展开（Unroll）”，让 **“单任务内的指令并行执行”** 。比如计算 `acc += A[i] * B[i]` 时，传统 CPU 只能 “循环串行计算”，FPGA 可通过硬件并行，让 “多组乘法 + 加法” 同时运算（如图中多个 `×` 和 `+` 并行 ），**突破单任务的计算瓶颈**。

以期权定价模型加速（以 Black - Scholes 模型为例）：

```
// 这是一个简化版 Black - Scholes 计算：acc 累加每个期权的理论价值
```

CPU 执行时，**循环只能串行遍历** 每个期权合约：

```
第 1 步：计算合约 0 的 
```

`高频交易中，若需计算 1000 个合约，串行执行会导致 微秒级延迟（对高频交易可能致命）。`

  

#### FPGA 的指令级并行通过 **循环展开（Unroll）**，FPGA 可让 **“多组乘加指令并行执行”**：

```
// 用 #pragma HLS UNROLL 指令显式要求循环展开（或编译器自动优化）
```

此时，FPGA 硬件会 **“复制 4 套‘乘加计算单元’”**，并行执行：

```
第 1 组：计算合约 0 的 S[0] * vol_factor[0] - K_pv[0]
```

原本 1000 次串行循环，**变成 250 次并行批次**（1000/4），计算时间直接 **压缩为 1/4 左右**，突破单任务的计算瓶颈。若传统 CPU 计算 1000 个期权合约需 **10 微秒**，FPGA 循环展开后可能只需 **3 微秒。**

除了期权定价，高频交易中 “订单簿匹配”“风险因子实时计算” 等单任务场景，也可通过循环展开加速，订单簿匹配中并行遍历买卖盘，快速找到最优成交对手；风险因子并行计算中可以并行计算多资产的风险敞口，实时监控超限。

官网资料：

![](assets/011.png)

  

这篇文章是2019年：NGN全球下一代网络及交易技术峰会中看到的。这次峰会的主题主要是：

-   Solarflare
    

-   End-to-end cut-through for ultra-low latency
    

-   端对端直通超低延迟实现
    
      
    

-   Xilinx
    

-   Different Doesn't mean difficult: FPGA Programing Demystified
    
-   不同并不意味着困难:FPGA程序化
    
      
    

-   Xenon
    

-   XENON's eXtreme High Freguency Trading Servers & SolarCapture Solution 
    
-   超高频交易服务器和SolarCapture解决方案
    
      
    

-   Arista
    

-   From L1 to L3: The road to enhanced ultra-low latency, high-precision trading network 
    
-   从1层到3层:通向增强的超低延迟、高精度交易网络
    

  

-   BSO 
    

-   Accessing Global Liquidity Through Technology 
    
-   通过技术获取全球流动性
    

  

-   Inspur Power
    

-   Power system - Building stable and efficient IT infrastructure for High Frequency Trading 
    
-   为高频交易构建稳定高效的IT基础设施
    

  

-   ICE Global Network 
    

-   Wireless Connectivity (Microwave Transmission) & Ultra Low Latency Market Data 
    
-   无线连接&超低延迟市场数据
    

  

-   Shengli Financial Software
    

-   HFT Solutions for China's Markets -Now and Next 
    
-   中国市场高频交易解决方案的现状与展望
    
      
    

-   Solace 
    

-   The Start and End of Trading: Low Latency Data Distribution 
    
-   交易的始末:低延迟数据的分布与分类