# 【万字长文】FPGA在HFT中的应用

QuantML QuantML 2025-03-31 18:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489836&idx=1&sn=510230aae2b8158f79a2c16c010b72bd&chksm=cf93d54fa3772768b6203b56845651de192819487571e3c15305827325ce0cce52b210c44924#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489836&idx=1&sn=510230aae2b8158f79a2c16c010b72bd&chksm=cf93d54fa3772768b6203b56845651de192819487571e3c15305827325ce0cce52b210c44924#rd)

#### 1\. 引言

高频交易（HFT）在金融市场中处于前沿地位，其特点是利用复杂的算法和强大的计算机程序，快速执行大量订单。在这种竞争激烈的领域中取得成功，关键在于能够识别并利用各种金融工具之间转瞬即逝的价格差异，这要求反应时间达到微秒甚至纳秒级别。随着电子交易的日益普及，延迟方面的微小优势被放大，成为盈利的关键决定因素。

传统的交易基础设施主要依赖于中央处理器（CPU），在满足HFT的极端速度要求方面存在固有局限性。CPU作为通用处理器，按顺序执行任务，处理时间通常以微秒计。这种顺序执行方式在面对HFT操作中高度并行化和对时间敏感的市场数据和订单执行时，会产生瓶颈。

为了应对这些局限性，现场可编程门阵列（FPGA）作为一种变革性的硬件加速技术应运而生，成为实现HFT所需的超低延迟和高性能的核心。FPGA是集成电路，可在制造后进行编程，以实现针对特定计算任务（包括交易中常见的任务）的定制硬件逻辑。其架构支持并行处理，能够在纳秒级别同时分析大量市场数据并执行交易决策，从而在速度上相较于CPU具有显著优势。

![](assets/001.jpg)

从以CPU为中心的交易基础设施向FPGA加速系统的转变，标志着由HFT对速度和可预测性能日益增长的需求所推动的根本性变革。CPU在实现纳秒级延迟方面的固有架构限制，迫使人们探索和采用FPGA等替代硬件解决方案。这种演变凸显了硬件级优化在保持金融市场中时间最敏感领域的竞争优势方面的关键作用。此外，HFT对提供市场流动性的依赖日益增加，突显了像FPGA这样能够通过速度提供竞争优势的技术的重要性。那些未能采用此类先进技术的企业可能面临重大劣势，因为市场的大部分运作速度已达到纳秒级别，使用FPGA可能会错失机会并遭遇逆向选择。

FPGA与HFT的整合也凸显了金融专业知识和先进硬件工程之间日益增长的协同作用。在这一领域有效利用FPGA的能力，需要量化分析师（负责开发交易策略）与FPGA工程师（具备将策略转化为优化硬件实现的专门技能）之间的紧密合作。这种跨学科合作对于设计并部署能够在HFT的苛刻环境中以所需的速度和效率运行的交易系统至关重要。

#### 2\. FPGA在高频交易中的基础知识

FPGA的核心由大量可编程逻辑块（通常称为可配置逻辑块CLB）组成，这些逻辑块通过可编程布线结构相互连接。这些逻辑块作为基本构建单元，可以配置实现从基本的逻辑门（如AND、OR、NAND）到更复杂的算术单元等多种数字功能。可编程布线结构允许在这些逻辑块之间创建自定义连接，从而实现针对特定计算需求的复杂数字电路。

![](assets/002.png)

FPGA的一个定义性特征，也是其与固定功能集成电路或专用集成电路（ASIC）的主要区别，在于其可重构性。与ASIC在制造时为特定目的设计不同，FPGA在生产后可以重新编程。这使得HFT公司能够以显著的灵活性调整其硬件基础设施，以适应不同的交易算法和不断变化的市场条件。这种可重构性在HFT快速变化的世界中至关重要，使得在硬件中快速原型化和部署新的交易策略成为可能，而无需经历设计和制造定制ASIC相关的漫长且昂贵的过程。交易策略可以不断调整和优化，为动态市场提供了显著优势。

FPGA擅长并行处理，这是其在HFT中有效性的核心。其架构允许在广泛的可配置逻辑块上同时执行多个操作。这与CPU的顺序指令执行模型形成鲜明对比，CPU按顺序处理任务，在处理并行工作负载时会产生固有的延迟。通过直接在硬件中实现交易算法，FPGA能够真正并行执行关键逻辑，显著减少处理市场数据和做出交易决策所需的时间。现代FPGA还集成了其他重要资源，包括片上内存（称为块RAM或BRAM）和数字信号处理（DSP）块，这些资源对于HFT的高性能计算需求特别有价值。

FPGA的编程通常通过两种主要方法实现。传统上，硬件描述语言（HDL）如SystemVerilog和VHDL一直是FPGA开发的主流。这些语言为开发人员提供了对硬件实现的细粒度控制，允许进行高度优化的设计。然而，高级综合（HLS）工具的日益普及正在改变FPGA编程的格局。HLS使开发人员能够使用C和C++等更高级别的语言来描述他们所需的硬件行为。这些工具然后自动将高级代码转换为高效的硬件设计，显著简化了开发过程，并加快了将基于FPGA的HFT解决方案推向市场的时间。

FPGA与CPU的根本区别可以通过将FPGA比作“乐高积木”的类比来有效说明。这种比较突出了FPGA为HFT提供的无与伦比的定制化水平。与CPU的固定指令集不同，FPGA的逻辑块可以配置为创建专门针对特定交易算法需求而定制的硬件加速器。这意味着只实现给定任务所需的基本逻辑，从而消除了与通用硬件和指令相关的开销，最终导致处理速度的显著提高。此外，通过高级综合（HLS）工具提高FPGA编程的可访问性是扩大FPGA在HFT社区中应用的关键因素。HLS降低了量化金融专家进入的门槛，这些专家可能具备强大的编程技能，但缺乏传统的HDL编程专业知识。通过允许量化专家使用他们已经熟悉的语言（如C++）来描述他们的交易策略，HLS促进了这些策略自动转换为FPGA上的硬件实现。这简化了开发过程，并加快了直接在硬件上迭代交易算法的时间，从而促进创新并加速先进交易系统的部署。

#### 3\. FPGA相较于CPU和GPU在HFT中的优势

3.1 **延迟**

FPGA在延迟方面提供了无与伦比的优势，其操作在纳秒级别，这对于HFT这一高风险领域至关重要，因为即使是微小的延迟也会影响盈利能力。这种纳秒级的处理能力使HFT公司能够比传统的基于CPU的系统更快地响应市场事件并执行交易，CPU通常在微秒级别运行。例如，Magmio的基于FPGA的交易平台提供纳秒级的性能，与CPU所需的微秒形成鲜明对比。基准测试结果进一步突出了这一优势，AMD Alveo UL3524 FinTech加速卡的STAC-T0基准测试中实现了13.9纳秒的可操作延迟。该基准测试测量的是做出交易决策所需的最后一个数据位与模拟的出站订单的第一个数据位之间的时间间隔，突出了基于FPGA系统的卓越速度。即使是高度优化的CPU软件解决方案通常也会产生三到五微秒的延迟，进一步强调了FPGA在延迟关键任务中提供的巨大速度优势。这种延迟的显著减少直接转化为HFT中的实际竞争优势，使公司能够利用短暂的市场机会，并通过最小化滑点和最大化成交率来提高执行质量。在HFT中，交易者希望第一个对市场变动信息做出反应，而FPGA的低延迟确保他们的订单更快地到达交易所的匹配引擎，增加了以期望的价格并领先于使用较慢技术的竞争对手获得成交的可能性。

3.2 **吞吐量**

FPGA固有的并行处理架构使其能够处理和以极高的吞吐量处理大量市场数据。与按顺序处理数据的CPU不同，FPGA可以同时处理来自多个市场源的实时数据，执行解析、过滤和订单簿构建等任务，而不会影响延迟。这种能力对于依赖分析和实时响应来自众多交易场所和广泛金融工具的信息的HFT策略至关重要。一个优化的FPGA交易系统每秒可以处理数千笔交易，每笔决策仅需几纳秒。这种高吞吐量源于FPGA的并行处理能力和交易逻辑的直接硬件实现。FPGA能够同时处理大量数据，这对于依赖分析并实时响应来自多个市场和工具的信息的HFT策略至关重要。HFT公司需要处理大量的市场数据源以识别交易机会，而FPGA的并行架构允许它们对数据进行复杂的计算和分析，而不会造成处理瓶颈，这对于保持速度和响应能力至关重要。

3.3 **确定性**

FPGA提供高度确定性的性能，这意味着特定操作的处理时间是稳定且可预测的，这对于HFT系统的可靠性和稳定性至关重要。与CPU和GPU不同，后者由于操作系统调度和内存访问模式等因素可能导致执行时间的变化，FPGA直接在硬件中执行任务，具有精确的时序。这种确定性减少了交易过程中意外延迟或“抖动”的风险，确保即使在市场活动频繁期间也能保持系统和行为的一致性和可预测性。FPGA上的硬件实现提供了所需的确定性，消除了软件解决方案中遇到的“抖动”。这种可预测的性能对于HFT中的时间敏感过程至关重要。FPGA的确定性性能简化了HFT系统的设计、测试和验证，降低了功能错误的风险，并增加了交易执行完整性的信心。在HFT的高风险世界中，任何不可预测的延迟或处理延迟的变化都可能导致重大的财务后果。FPGA的确定性允许精确的时序控制和可预测的执行，这对于构建健壮可靠的交易平台至关重要。

### 表1：FPGA、CPU和GPU在高频交易中的特性比较

**特性**

**CPU**

**GPU**

**FPGA**

**延迟**

微秒级

比FPGA高，但在某些并行任务中比CPU低

纳秒级

**处理**

顺序处理，硬件并行性有限

针对特定数据并行任务的大规模并行处理

高度并行且可定制的硬件逻辑

**确定性**

由于操作系统和其他软件因素而变化

由于软件调度和内存访问，确定性不如FPGA

由于直接硬件执行而具有高度确定性

**吞吐量**

对于高度并行、时间敏感的工作负载较低

对于数据并行、吞吐量导向的任务（例如，图形）较高

对于特定的、并行的、延迟关键的任务较高

**灵活性**

高（基于软件）

中等（基于固定硬件架构的软件）

高（硬件可重配置性）

**能效**

对于并行工作负载较低

对于某些并行任务可能较高，但对于自定义任务通常低于FPGA

对于自定义的、延迟关键的任务通常较高

#### 4\. FPGA在高频交易中的具体应用

4.1 **订单执行**

FPGA在加速HFT系统中的订单执行管道方面发挥着关键作用，显著减少了传输和接收交易订单所需的时间。它们促进了超快速订单路由逻辑的实现，实现了与交易交易所的直接、低延迟通信。一个关键方面是能够在FPGA硬件上直接执行预交易风险检查。这些检查由监管机构规定，确保订单在发送到交易所之前遵守预定义的限制，同时不会在交易过程中引入显著的延迟。例如，Raptor FPGA提供单向延迟不到200纳秒，这包括这些关键的预交易风险评估。此外，基于FPGA的系统可以直接在硬件上处理特定于交易所的消息格式和协议处理，进一步优化订单执行路径以实现超低延迟。通过将关键的订单执行任务卸载到FPGA，HFT公司可以获得显著的速度优势，使他们能够在有利可图的机会出现时成为第一个执行交易的人，从而提高他们的盈利能力。绕过较慢的软件层和通用CPU以实现延迟敏感的订单执行任务的能力，使基于FPGA的系统能够实现往返延迟远低于微秒，这对于快速发展的金融市场动态至关重要。

4.2 **市场数据处理**

FPGA广泛用于处理构成HFT策略基础的高速度市场数据流。其架构允许它们以最小的延迟摄取、解析、解码和规范来自各种交易所的市场数据源，确保交易算法实时接收最新信息。此外，FPGA用于过滤和聚合市场数据，使交易算法能够专注于与其特定策略相关的特定信息。像NovaSparks这样的公司已经开发了纯基于FPGA的行情机，直接在硬件上执行所有实时市场数据处理功能，实现了最低的延迟和最高程度的确定性，即使在市场数据激增期间也是如此。加州大学圣克鲁斯分校进行的一项研究表明，基于FPGA的方法可以将市场数据处理的延迟减少四倍，与传统软件方法相比。FPGA能够在“线速”处理市场数据，这对于HFT公司快速识别交易机会并在竞争对手之前对市场变化做出反应至关重要。当代电子交易中市场数据的巨大数量和速度需要使用硬件加速来实现高效处理。FPGA的并行架构和可定制的逻辑使其能够以显著低于软件解决方案的延迟处理这些苛刻的数据速率。

4.3 **风险管理**

FPGA的应用正在HFT系统中的实时风险管理领域不断扩大。预交易风险检查，例如限价订单的验证和防止交易量超过预定义阈值的检查，可以在FPGA硬件上以亚微秒级的延迟执行。FPGA处理固有的确定性确保这些风险检查始终如一地应用，而不会在订单流中引入不可预测的延迟。除了预交易检查外，FPGA还可以用于交易后风险分析和监控，促进投资组合风险的实时评估以及任何潜在异常的检测。例如，Algo-Logic Systems提供了一种基于FPGA的预交易风险检查（PTRC）解决方案，其操作延迟低于微秒，确保符合监管要求，同时不会妨碍交易速度。此外，FPGA可以作为“牛头”，在它们影响市场之前识别并阻止交易异常，如错误或破坏性交易。通过在FPGA上实施风险管理功能，HFT公司可以有效地满足严格的监管要求，并保护自己免受错误交易或市场波动带来的潜在损失，同时保持其交易操作的高速度。低延迟和确定性性能的结合使FPGA成为实施实时风险控制的理想平台，可以跟上HFT的高频率特性，确保监管合规和运营安全。

4.4 **预交易分析**

虽然FPGA在HFT中的主要用途集中在订单执行和市场数据处理等对延迟敏感的操作上，但其能力也扩展到加速某些预交易分析的方面。必须在交易执行前进行的复杂计算和算法分析可能会从FPGA固有的并行处理能力中受益。这些分析可能包括评估潜在的交易机会、运行统计套利模型或进行市场影响评估。例如，已经探讨了在FPGA上进行特征值分解以进行相关性分析的可行性。FPGA增强预交易分析速度的潜力代表了一个不断发展的应用领域，在这个领域中，可重构硬件的计算能力可以被利用来促进更明智和及时的交易决策。随着HFT策略变得越来越复杂和以数据为导向，能够以低延迟执行复杂的预交易分析可能会提供额外的竞争优势。虽然这一领域没有其他应用那么广泛记录，但它值得持续的研究和开发，以充分实现其潜力。

### 表2：FPGA与GPU在高频交易中的比较

**特性**

**FPGA**

**GPU**

**延迟**

超低（纳秒级）

比FPGA高（微秒级），但在某些并行任务中比CPU低

**吞吐量**

对于特定的、并行的、延迟关键的任务较高

对于数据并行、吞吐量导向的任务较高

**确定性**

高度确定性

确定性较低

**可编程性**

需要HDL专业知识（Verilog、VHDL），HLS正在提高可访问性

使用CUDA、OpenCL更容易编程

**灵活性**

高度灵活（硬件可重配置性）

灵活性较低（固定架构）

**能效**

对于自定义的、延迟关键的任务通常较高

对于某些并行任务可能较高，但对于自定义任务通常高于FPGA

**成本**

硬件和开发成本较高

某些应用初始成本较低

**典型高频交易应用**

订单执行、市场数据处理、交易前风险检查

在核心高频交易执行路径中不太常见，可能用于分析

#### 5\. 使用FPGA在HFT中的挑战和考虑因素

5.1 **开发复杂性**

基于FPGA的解决方案的开发和部署需要对硬件描述语言（HDL）如Verilog和VHDL有专门的了解。与软件编程相比，FPGA开发的学习曲线要陡峭得多，需要对数字逻辑、微架构和硬件实现的复杂性有深刻的理解。FPGA项目通常涉及复杂的设计流程，包括综合、布局和布线以及细致的时序分析，这既耗时又需要专门的工具和知识。这种对高度熟练的FPGA工程师的需求以及开发过程的固有复杂性，可能为寻求采用这项技术的HFT公司带来了重大障碍，可能导致开发成本增加和上市时间延长。FPGA开发的专门性质限制了可用人才的储备，而且复杂的设计过程可能导致与软件解决方案相比更长的开发周期，这可能会阻碍HFT公司在适应快速变化的市场动态方面的敏捷性。

5.2 **成本**

FPGA技术在HFT中的初始财务支出可能相当大，包括高性能FPGA卡和专用开发板的采购。与FPGA设计工具、知识产权（IP）核心以及招聘和留住经验丰富的FPGA工程师相关的费用进一步增加了实施基于FPGA的HFT系统的总体成本。虽然FPGA提供了令人信服的灵活性和性能优势，但与传统的基于CPU的解决方案相比，其更高的前期和持续成本需要HFT公司进行彻底的成本效益分析。这种分析必须仔细权衡交易盈利能力的潜在收益和获得竞争优势与硬件、开发资源和专门人员所需的大量投资之间的权衡。决定采用FPGA涉及相当大的财务承诺，公司必须严格评估这项技术提供的性能提升是否会产生足够的回报以证明相关成本是合理的。

5.3 **功耗**

虽然FPGA通常在广泛的计算任务中表现出比GPU更高的能效，但HFT中使用的高性能FPGA仍然会消耗相当数量的功率，特别是在承受重计算负载时。在数据中心环境中，有效管理功耗和散热成为需要考虑的重要因素。然而，与高端CPU和GPU的功耗需求相比，FPGA通常为HFT中遇到的特定类型的工作负载提供了更高的每瓦性能比。因此，优化FPGA设计以最小化功耗对于降低运营费用和确保HFT系统在高密度数据中心环境中的长期可靠性至关重要。虽然HFT的主要重点是实现最大速度，但仔细关注能效对于控制能源成本和防止可能对系统性能和整体稳定性产生负面影响的过热问题也至关重要。

5.4 **有限的灵活性**

一旦交易算法在FPGA硬件上实现，进行修改或更新需要更改底层硬件设计，然后重新编程FPGA。这个过程可能比在CPU上更新软件代码的相对简单的任务更为复杂和耗时。因此，与基于软件的系统相比，基于FPGA的系统部署新交易策略或适应快速变化的市场条件所需的周转时间可能更长。然而，FPGA的固有可重构性仍然提供了相对于固定功能ASIC的显著优势，因为它允许在不要求昂贵且耗时的全新硬件开发的情况下实现更新和修改。虽然FPGA提供了一定程度的可重构性，但更新硬件逻辑的过程本质上不如软件更新敏捷。这需要在FPGA系统上实施更改时进行仔细的规划和资源分配。在FPGA提供的卓越性能和基于软件系统的更大灵活性之间的权衡是HFT公司在做出技术采用决策时的关键考虑因素。

#### 6\. FPGA在HFT中的最新技术进步和未来趋势

近年来，FPGA技术在HFT中的应用取得了显著的技术进步，进一步增强了其适用性和性能。一个值得注意的领域是FPGA收发器的演变，引入超低延迟收发器，如AMD的GTF收发器，标志着向前迈出的重要一步。这些先进的收发器显著减少了与数据输入和输出相关的延迟，这是HFT中的关键瓶颈，因为每一纳秒都很重要。例如，AMD Alveo UL3422加速器的超低延迟将收发器延迟从16纳秒减少到大约2.34纳秒。

另一个关键趋势是硬化知识产权（IP）块在FPGA中的日益集成，这些块专门设计用于加速高速网络和金融协议。标准以太网物理编码子层（PCS）和媒体访问控制（MAC）IP直接集成到收发器中，以高频率运行，实现了接近ASIC般的性能，进一步优化了数据处理并减少了延迟。

高级综合（HLS）工具的持续发展和完善也在扩大FPGA在HFT中的应用方面发挥着关键作用。通过允许开发人员使用C++等更高级别的语言进行硬件设计，HLS显著简化了编程过程，缩短了开发时间，并使FPGA技术对更广泛的量化金融专家更具可访问性。

基于FPGA的SmartNIC的出现代表了另一个重大进步。这些智能网络接口卡结合了传统NIC的低延迟网络功能与FPGA的可编程硬件加速。这种集成允许将关键交易功能（如市场数据处理和预交易风险检查）直接卸载到网络卡上，将处理更接近网络，进一步减少了延迟。

展望未来，FPGA在基于云的高性能计算环境中的采用可能会增加。这可能会使更广泛的金融机构能够获得FPGA加速，消除对专用硬件基础设施的大量前期投资的需求。

FPGA技术的持续创新，特别是在物理层最小化延迟和简化开发过程方面，正在使FPGA成为HFT应用越来越引人注目的解决方案。向更低延迟收发器和集成硬件IP的趋势突出了对推动HFT基础设施的速度和效率界限的持续关注。此外，通过HLS工具提高FPGA编程的可访问性表明，未来将有更多的量化金融专家能够直接利用FPGA的性能优势来增强他们的交易策略，从而促进硬件加速交易算法的更大创新。与ASIC的比较也表明了一个可能的未来，FPGA将越来越多地弥合软件灵活性和定制硬件的最终性能之间的差距。

#### 7\. FPGA在HFT中的案例研究和成功应用

FPGA技术在高频交易中的成功部署通过各种案例研究和专业公司的产品得到了充分证明。IMC是一家著名的做市商，长期以来一直采用基于FPGA的交易系统，利用这项技术超过十年，以实现其运营所必需的极低延迟。他们的经验凸显了FPGA在这一个性化领域中的持续价值和有效性。

像Magmio这样的公司开发了专门的基于FPGA的交易平台和基础设施，旨在简化金融机构采用这项技术。他们的平台抽象了FPGA开发的复杂性，使金融专业人士能够相对容易地在硬件上部署他们的交易策略，展示了FPGA加速日益增长的可访问性。

Exegy与AMD的合作提供了一个关于当代FPGA解决方案在HFT中的性能能力的令人信服的例子。使用AMD的Alveo系列FPGA加速卡，他们在STAC-T0基准测试中实现了创纪录的tick-to-trade延迟结果。这些基准测试测量的是从市场数据接收到订单执行的关键路径，展示了现成的FPGA硬件在现实交易场景中实现超低延迟的潜力。

RaptorFintech提供针对特定HFT功能（如直接市场接入（DMA）和预交易风险管理）加速的FPGA解决方案。他们的产品提供了减少延迟和确保符合监管要求方面的切实好处，展示了FPGA技术在解决HFT工作流程中特定需求方面的针对性应用。

FPGA框架，如Orthogone的超低延迟FPGA框架，被HFT公司用来优化交易策略、加速订单执行和实施近零延迟的实时风险分析。这些框架为开发和部署自定义基于FPGA的交易应用提供了一个结构化的环境，突出了支持FPGA采用的工具日益复杂化。

像Algo-Logic Systems这样的提供商专门从事FPGA基础解决方案，用于HFT基础设施的关键组件，如他们的高性能预交易风险检查系统。他们的PTRC系统以亚微秒级的延迟运行，确保符合监管要求，同时不会妨碍交易操作的速度，展示了FPGA处理关键、延迟敏感功能的能力。

NovaSparks专注于纯基于FPGA的市场数据馈处理器，在HFT环境中提供行业领先的低延迟和确定性。他们的解决方案旨在即使在市场活动高峰期间也能保持亚微秒级的延迟，突出了基于FPGA系统的稳健性，用于处理高容量数据。

众多公司成功实施FPGA技术于HFT各个方面的众多例子，证明了这种方法在金融市场中获得显著竞争优势的成熟性和实际可行性。这些现实世界的应用作为具体证据，表明FPGA在HFT中的理论优势正在实践中实现，为采用这项技术的公司带来了更快的执行、改进的数据处理和更有效的风险管理。

#### 8\. 比较分析：FPGA与其他加速技术（GPU）

在考虑高频交易加速技术时，必须将现场可编程门阵列（FPGA）与其它主要选项，特别是图形处理单元（GPU）进行比较。虽然两者在某些任务上相较于传统CPU都有优势，但其底层架构和性能特征导致了在不同HFT背景下不同的优缺点。

FPGA和GPU在架构上有着根本的区别。FPGA拥有高度灵活的编程逻辑块和互连阵列，能够创建针对特定算法而定制的硬件实现。相比之下，GPU具有固定的架构，由大量简单的核心组成，优化用于数据密集型任务的并行处理，主要是图形渲染和某些类型的科学计算。

这些架构上的差异对HFT中的性能有着重要意义。FPGA在需要超低延迟和确定性执行的应用中表现出色，使其非常适合HFT中如订单执行和市场数据处理等对延迟敏感的任务。GPU虽然在高度可并行化的任务上提供高吞吐量，但通常比FPGA有更高的延迟，执行确定性较低，使其不适合HFT中最具时间敏感性的方面。

每种技术的可编程性和开发生态系统也有所不同。GPU受益于成熟且广泛采用的软件开发工具包（SDK），如CUDA和OpenCL，这简化了针对其并行架构的编程任务。另一方面，FPGA传统上需要硬件描述语言（HDL）的专业知识，这有更陡峭的学习曲线。然而，高级综合（HLS）工具的日益普及正在提高FPGA编程的可访问性。

在功率效率方面，FPGA通常在定制硬件实现上优于GPU。因为FPGA可以定制执行只有必要的操作，没有固定、通用的架构开销，它们通常在特定的HFT工作负载下消耗更少的功率。GPU，由于其大量的处理核心，在计算密集型任务上可能有显著的功率消耗。

考虑到它们在不同HFT应用中的适用性，FPGA是超低延迟任务（如订单执行、市场数据处理和预交易风险检查）的首选加速技术，因为它们的速度和确定性性能更优越。GPU虽然在核心的延迟敏感路径中不如FPGA普遍，但可能在不太时间关键领域找到应用，如复杂的预交易分析、回测或交易策略的机器学习模型训练，尽管提供的资料中关于这一点在核心HFT执行路径中的证据有限。

架构和性能特征的这些根本差异使得FPGA成为HFT基础设施中最关键、超低延迟组件的首选加速技术。它们纳秒级的延迟和确定性执行对于保持竞争优势至关重要。相比之下，GPU，由于其专注于图形和通用并行计算的高吞吐量，通常有更高的延迟和较不可预测的性能，使其不适合这些核心、时间敏感的任务。然而，FPGA在AI推理在各个领域的日益应用表明，FPGA可能在加速HFT策略中机器学习模型实时应用方面发挥更大的作用，只要严格的延迟要求仍然能够满足。FPGA的可定制性和功率效率使其在延迟敏感环境中部署AI模型具有吸引力，而且随着AI与交易相结合，FPGA可能提供了实现实时推理所需速度的可行路径。

#### 9\. 主要FPGA解决方案提供商

高频交易行业得到了一个强大的生态系统支持，该生态系统由提供FPGA硬件和专门解决方案的公司组成。主要的FPGA硬件供应商包括AMD（前身为Xilinx），这家领先的制造商，其Alveo系列FPGA专为高性能计算和金融应用而设计。英特尔是另一家主要的FPGA供应商，提供Stratix和Arria系列，这些系列也因其性能和特性被用于HFT。思科提供网络设备，包括Nexus SmartNIC，其中一些集成了FPGA，为金融交易提供可编程硬件加速。BittWare是一家提供高性能FPGA基础板和解决方案的提供商，用于各种要求苛刻的应用，包括金融交易。LDA Technologies专门为金融市场提供超低延迟FPGA解决方案，提供硬件和软件为HFT量身定做。

![](assets/003.jpg)

除了硬件供应商外，还有一些公司提供集成的基于FPGA的平台和解决方案，专门用于HFT。Magmio提供了一个简化在FPGA上实施交易策略的交易平台，抽象了硬件开发的复杂性。Exegy是一家领先的贸易和市场数据技术提供商，提供基于FPGA的解决方案，用于超低延迟市场数据处理和交易执行，取得了显著的基准测试结果。RaptorFintech为HFT公司提供FPGA加速的市场网关和预交易风险管理解决方案。Orthogone提供了一个超低延迟FPGA框架，用于开发并部署具有近零延迟的自定义交易应用。Algo-Logic Systems专门为交易所和交易公司提供基于FPGA的解决方案，包括高性能的预交易风险检查系统。NovaSparks专注于纯基于FPGA的市场数据馈处理器，提供行业领先的低延迟和确定性。

主要FPGA制造商和专门解决方案提供商的存在表明了一个成熟且竞争激烈的市场，满足了HFT行业的特定需求。HFT公司在考虑采用FPGA技术时有多种选择，从使用主要制造商的组件构建自己的解决方案到利用专门针对金融市场的供应商提供的集成平台和专门IP核心。这种竞争可能促进创新，并有助于随着时间的推移降低成本。

#### 10\. 结论

FPGA已经在现代高频交易领域确立了自己作为关键技术的地位，在实现超低延迟和高性能方面发挥了变革性的作用，这对于获得竞争优势至关重要。它们相较于传统的CPU甚至GPU的固有优势，特别是在延迟和确定性方面，使其非常适合HFT的苛刻要求。FPGA的多样化应用涵盖了整个交易工作流程，从加速订单执行和实时处理大量市场数据到实施复杂的风险管理控制，并可能增强预交易分析。

尽管采用FPGA技术存在一些挑战，包括开发复杂性和成本，但硬件和软件工具的持续进步正在使FPGA变得更易于使用和强大。收发器技术的创新、硬化IP核心的集成以及高级综合工具的日益复杂化，正在不断推动硬件加速交易领域可实现的目标。

FPGA技术在HFT的未来前景光明。由于对速度和效率的追求仍然是行业的核心，FPGA有望继续在寻求超越竞争对手的公司中发挥关键作用。FPGA架构、开发方法以及与人工智能等新兴技术的整合方面的进一步创新可能会扩大它们对金融市场的影响。

  

  

  

  

  

相关文章代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/004.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib重磅更新：DeepSeek核心模型结构用于选股](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489025&idx=1&sn=35941156783794d719e6ff891ce720c3&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 还在使用MSE？试试这些更加适合金融预测的损失函数](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487997&idx=1&sn=e05e8e0dafa605615d425ff1f0702c4b&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 如何运行日内中高频模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰SAM：提升AI量化模型的泛化性能 研报复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487238&idx=1&sn=41cbb5b3bb3e5a277c9175ba64642259&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰AlphaNet模型复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学&华泰证券 在高胜率时交易](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485500&idx=1&sn=b29e1d2efe2482165245ab6add4af051&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)[QuantML-Qlib Model | 滚动模型训练](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
    研报复现：
    
      
    
-   [重磅更新！80+量化策略复现（持续更新中）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488528&idx=1&sn=f9c98f60baca2b690956ff6b56a2553f&scene=21#wechat_redirect)
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [研报复现 | QRS择时信号及改进](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-下](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486787&idx=1&sn=bfe98c0b8d331027191761df3b85ea8c&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-上](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486761&idx=1&sn=84a2de96dd3bc7a7fb38386684b3eec4&scene=21#wechat_redirect)
    
-   [研报复现 | 锚定反转因子](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486379&idx=1&sn=d6763bb198d0706c101f2544aa752b4f&scene=21#wechat_redirect)
    
-   [研报复现 | 另类ETF交易策略：日内动量](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&scene=21#wechat_redirect)
    
-   [研报复现 | 国盛金工：如何将隔夜涨跌变为有效的选股因子？——基于对知情交易者信息优势的刻画](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485766&idx=1&sn=89d4060fb135105b969c0ef2f145a7e0&scene=21#wechat_redirect)
    
-   [研报复现 | 招商证券：基于鳄鱼线的指数择时及轮动策略](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485702&idx=1&sn=2b0ed284177a66ee9d0e8623cd9cb1b4&scene=21#wechat_redirect)
    
-   [研报复现 | 华西金工-股票网络与网络中心度因子研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484829&idx=1&sn=3da8197374301bab9610f7ed5d4b715b&chksm=ce7e6283f909eb9509b3ebc9989fe9d140d5ee663ac8749aeb608833ff37544421d0dcd0fa9c&scene=21#wechat_redirect)  
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
-   [研报复现 | 开源证券 ：形态识别，均线的](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&scene=21#wechat_redirect)  
    
-   [Hummingbot：开源加密货币做市机器人框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489153&idx=1&sn=98198f6cca4aa5bc5646e926c358f01d&scene=21#wechat_redirect)  
    
-   [FinRLlama：基于强化学习和市场反馈的金融情感分析LLM优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489127&idx=1&sn=faad16c8ac3ca02dcb982837d03b21ab&scene=21#wechat_redirect)  
    
-   [端到端基于LLM的增强型交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&scene=21#wechat_redirect)
    
-   [基于分层强化学习的日内风险因子挖掘](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489104&idx=1&sn=c0b6938ebcf0cbd8244f87abe609798e&scene=21#wechat_redirect)
    
-   [DeepScalper：深度强化学习捕捉日内交易的短暂机会](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&scene=21#wechat_redirect)
    
-   [TradingAgents：基于多智能体LLM的金融交易框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488712&idx=1&sn=daa7fb4a9d49a621f9f54579dda4a184&scene=21#wechat_redirect)  
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)