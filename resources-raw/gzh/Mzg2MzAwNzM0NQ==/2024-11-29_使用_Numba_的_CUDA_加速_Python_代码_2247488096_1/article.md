# 使用 Numba 的 CUDA 加速 Python 代码

QuantML QuantML 2024-11-29 19:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488096&idx=1&sn=068456dff964fe8ca39b982fcbcb3c5c&chksm=cf76ea115a22dc6fdb2f334735e7773866518c5d5e77c40775024a3407e72921e7ed8f08888b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488096&idx=1&sn=068456dff964fe8ca39b982fcbcb3c5c&chksm=cf76ea115a22dc6fdb2f334735e7773866518c5d5e77c40775024a3407e72921e7ed8f08888b#rd)

本文将介绍如何利用 Numba 库中的 CUDA 加速 Python 代码。Numba 是一个高性能 Python 库，旨在优化代码速度。其核心是一个即时编译（JIT）编译器，可以将部分 Python 和 NumPy 代码转换为高效的机器代码。这一过程是自动且动态的，允许 Python 开发者在不改变原始代码的情况下获得显著的性能提升。

### Numba 的常规 JIT 编译器与 CUDA JIT 编译器

Numba 的常规 JIT 编译器主要用于优化 CPU 上的代码运行时间。然而，如果你有幸拥有一块 GPU，本文将向你展示如何再次使用 Numba，这次是通过其 CUDA JIT 编译器，将代码运行目标转向 GPU，从而进一步加速 Python 代码。

### 使用 CUDA 的前提条件

要在系统上使用 NVIDIA CUDA，需要满足以下条件：

-   一块支持 CUDA 的 GPU
    
-   与操作系统兼容的 CUDA 驱动程序
    
-   CUDA 工具包（可从 https://developer.nvidia.com/cuda-downloads 下载）
    

建议访问 NVIDIA 官方网站上的安装指南以获取详细说明。此外，熟悉一些 GPU 领域特有的术语也很有帮助，例如：

-   主机内存（host memory）：系统的主内存（RAM）
    
-   设备内存（device memory）：GPU 卡上的板载内存
    
-   内核（kernel）：由主机启动并在设备上执行的 GPU 函数
    
-   设备函数（device function）：在设备上执行的 GPU 函数，只能从设备上调用（即从内核或其他设备函数调用）
    
-   流式多处理器（Streaming Multiprocessors）：NVIDIA GPU 架构中的基本计算单元，负责并行执行线程指令，使 GPU 能够高效地处理并行计算任务。
    

### 理解 GPU 中的内存层次结构

要充分理解 Numba CUDA 编程的工作原理，学习 GPU 的内存层次结构和网格布局系统是很有价值的。与 CPU 不同，GPU 具有分层的内存架构，包括：

1.  寄存器（Registers）：小型、快速的在芯片内存，用于存储临时结果和变量。
    
2.  共享内存（Shared Memory）：小型、快速的在芯片内存，在块内的线程之间共享。
    
3.  全局内存（Global Memory）：大型、离芯片内存，用于存储数据和程序指令。
    
4.  纹理内存（Texture Memory）：只读内存，用于存储 2D 数组，并针对纹理映射进行了优化。
    
5.  常量内存（Constant Memory）：小型、只读内存，用于存储常量，并针对广播进行了优化。
    

### 理解 GPU 中的网格系统

另一个需要掌握的重要概念是网格系统。在 GPU 编程中，网格系统是一个基本概念，它允许开发者在 GPU 上组织和执行并行计算。网格系统包括：

1.  网格（Grid）：由块（Block）组成的 1D、2D 或 3D 数组。
    
2.  块（Block）：一组一起执行的线程。每个块可以包含一定数量的线程，块内的所有线程可以使用共享内存进行协作。块内的线程通常以 1D、2D 或 3D 结构排列。
    
3.  线程（Thread）：最小的执行单元。线程类似于在 GPU 上运行的一个指令流。每个线程对数据的特定部分执行计算。
    

### 网格的工作原理

网格可以定义为 1D、2D 或 3D，具体取决于要解决的问题。例如，如果你正在处理一张 2D 图像，你可能会选择 2D 网格，以便更好地将计算任务映射到数据结构上。

网格中的每个块也可以是 1D、2D 或 3D。块维度定义了每个块的线程数。

启动 CUDA 内核时，需要指定网格和块维度。CUDA 运行时将线程分布在 GPU 上可用的流式多处理器（SM）上。每个块被分配给一个 SM，块内的线程分布在该 SM 的内核上。

CUDA 提供了一些内置变量，可以帮助你确定块和线程在网格上的位置。为了简单起见，让我们考虑一个 2D 块排列。

网格：

![](assets/001.png)

块位置：

-   bx = cuda.blockIdx.x  -->  在示例图中为 1
    
-   by = cuda.blockIdx.y  -->  1
    

块维度：

-   bw = cuda.blockDim.x  --------->  3
    
-   bh = cuda.blockDim.y  ->  3
    

块线程位置：

-   tx = cuda.threadIdx.x  ->  0
    
-   ty = cuda.threadIdx.y  ->  0
    

网格线程位置：

-   X = bw \* bx + tx  ->  3
    
-   Y = bh \* by + ty  ->  3
    

或

-   X,Y = cuda.grid(2)
    

### 设置开发环境

在开始编码之前，让我们为我们的工作设置一个独立的开发环境。我使用 conda 来实现这一点，但你可以使用任何你熟悉且最适合你的方法。

```
# 创建测试环境(base) $ conda create -n numba_cuda python=3.11 -y# 激活环境(base) $ conda activate numba_cuda(numba_cuda) $
```

现在环境已经设置好了，我们可以安装所需的库和软件。

根据 Numba 对 CUDA 编程的要求，由于我安装了 CUDA 12，我需要以下库：

```
(numba_cuda) $ conda install -c conda-forge cuda-nvcc cuda-nvrtc "cuda>12"
```

我还需要以下内容：

```
(numba_cuda) $ conda install numba jupyter -y(numba_cuda) $ pip install matplotlib
```

### Numba CUDA 的应用

在测试中，我将重复我在 Numba JIT 文章中使用的一些编程片段，看看将它们转换为使用 Numba CUDA 可以获得多少改进。

#### 示例 1 - 简单 for 循环测试

**Numba JIT 版本**

```
from numba import jit import time# 使用 @jit 装饰器启用 JIT 编译@jit (nopython=True)  # 建议使用 nopython 模式以获得最佳性能def loop_test_jit():    result = 0.0  # 外层循环    for i in range (10000) :        # 内层循环        for j in range (10000) :            # 执行简单操作            result += i * j * 0.1    return result# 调用函数以允许 Numba 编译它loop_test_jit()# 记录开始时间start_time = time. time ()# 调用 JIT 编译后的函数for i in range(5) :    result = loop_test_jit()# 记录结束时间end_time = time.time ()# 计算并打印执行时间print(f"CUDA JIT result = {result}")print(f"Execution time: { (end_time - start_time)/5} seconds")
```

输出如下：

```
NUMBA JIT result = 249950002500000.0 Execution time: 0.09600849151611328 seconds
```

回想一下，Numba 第一次遇到一个函数时，在运行之前需要一些时间来编译它。因此，我运行一次函数以进行编译阶段，然后在循环中再次调用它 5 次，并取循环中每次运行的平均时间。这应该可以公平地比较运行时间。

**Numba CUDA 版本**

```
from numba import cuda import numpy as np import time# 定义每个块中运行的线程数threads_per_block = 256# 定义 CUDA 内核函数@cuda.jitdef loop_test_kernel (results):    i = cuda.grid(1)  # 确保我们不会超出边界    if i < results.size:        result = 0.0        for j in range (10000) :            result += i * j * 0.1        results [i] = result# 主函数来管理计算def loop_test_cuda () :    num_elements = 10000    # 计算网格中需要的块数（blocks_per_grid）以使用给定的每个块的线程数处理所有 num_elements。    blocks_per_grid = (num_elements + (threads_per_block - 1)) // threads_per_block    # 在设备（GPU）上为结果分配空间    results = cuda.device_array(num_elements, dtype=np.float64)    # 使用所需的块数和线程数在 GPU 上启动内核    loop_test_kernel [blocks_per_grid, threads_per_block] (results)    # 将结果复制回主机（CPU）    results_host = results. copy_to_host ()    # 聚合结果    return results_host. sum()# 预热 CUDA 内核以允许 JIT 编译loop_test_cuda ()# 记录开始时间start_time = time. time ()# 调用 CUDA 函数for i in range(5) :    result = loop_test_cuda ()# 记录结束时间end_time = time. time ()# 计算并打印执行时间print (f"NUMBA CUDA result = {result}")print(f"Execution time: {(end_time - start_time)/5} seconds")
```

输出如下：

```
NUMBA CUDA result = 249950002500000.0 Execution time: 0.01670536994934082 seconds
```

可以看到，代码运行速度提高了 6 倍，而这段代码本身已经很快了。

CUDA 代码更复杂，其中大部分来自我们在将 for 循环分配到 GPU 上的线程时必须进行的映射。

代码运行后，我还收到了以下警告信息：

```
NumbaPerformanceWarning: Grid size 40 will likely result in GPU under-utilization due to low occupancy.
```

这意味着当前的网格尺寸（40）可能导致 GPU 利用率低下，因为占用率较低。为了解决这个问题，我尝试调整了一些参数。例如，当我将 `threads_per_block` 变量从 256 改为 64 时，警告信息消失了。这增加了每个网格中的块数，这似乎与直觉相反，但确实有效提升了性能。

### 示例 2 - 递归函数

Numba 还可以加速递归函数调用。为了避免使用斐波那契数列，我们将尝试一种你可能没有听说过的类似算法，称为卢卡斯数列。卢卡斯数列与斐波那契数列类似，也遵循相同的递归模式，但初始值不同。卢卡斯数列以 2 和 1 开始，而不是斐波那契数列的 0 和 1。第 n 个卢卡斯数可以递归定义为 ，基础情况为 和 。

**Numba JIT 版本**

```
from numba import jitimport time# 应用 Numba 的 JIT 装饰器@jit(nopython=True)def lucas_numba(n):    if n == 0:        return 2    elif n == 1:        return 1    else:        return lucas_numba(n-1) + lucas_numba(n-2)# 计算第 40 个卢卡斯数lucas_result_numba = lucas_numba(40)# 计时 JIT 编译后的函数start_time = time.time()for _ in range(5):    lucas_result_numba = lucas_numba(40)end_time = time.time()print(f"Lucas number 40 with Numba: {lucas_result_numba}")print(f"Execution time with Numba: {(end_time - start_time)/5} seconds")
```

输出：

```
Lucas number 40 with Numba: 228826127Execution time with Numba: 0.7562449932098388 seconds
```

**Numba CUDA 版本**

```
from numba import cudaimport numpy as npimport time# CUDA 内核来计算卢卡斯数@cuda.jitdef lucas_cuda(n, result):    i = cuda.grid(1)  # 1D 网格，i 表示数组中的索引    if i <= n:  # 确保不会超出边界        if i == 0:            result[i] = 2        elif i == 1:            result[i] = 1        else:            a = 2            b = 1            for j in range(2, i + 1):                c = a + b                a = b                b = c                result[i] = b# 定义目标数字（第 40 个卢卡斯数）n = 40# 在设备上分配结果数组result = np.zeros(n + 1, dtype=np.int32)  # 我们需要一个大小为 41 的数组（0-40）result_device = cuda.to_device(result)# 定义每个块的线程数和每个网格的块数# 这需要一些试验和调整threads_per_block = 128blocks_per_grid = (n + (threads_per_block - 1)) // threads_per_block# 启动 CUDA 内核start_time = time.time()lucas_cuda[blocks_per_grid, threads_per_block](n, result_device)# 等待所有线程完成cuda.synchronize()end_time = time.time()# 将结果复制回主机result_host = result_device.copy_to_host()# 打印第 40 个卢卡斯数（索引 40）print(f"Lucas number for {n} with CUDA: {result_host[n]}")print(f"Execution time with CUDA: {end_time - start_time} seconds")
```

输出：

```
Lucas number 40 with CUDA: 228826127Execution time with CUDA: 0.10776114463806152 seconds
```

相比原始的 Numba JIT 代码，这次大约快了 7 倍。

### 示例 3 - 图像处理

在这个测试中，我们使用一张泰姬陵的照片并将其转换为灰度图像。在我的系统上，原始彩色图像（PNG 格式）大小为 3.7 MB。

**Numba JIT 版本**

```
from numba import jitimport numpy as npimport matplotlib.pyplot as pltfrom matplotlib.image import imread# Numba 优化的 RGB 转灰度函数@jit(nopython=True)def rgb_to_grayscale_numba(rgb):    # 预分配输出灰度数组    grayscale = np.zeros((rgb.shape[0], rgb.shape[1]), dtype=np.float64)    # 遍历每个像素并应用灰度转换    for i in range(rgb.shape[0]):        for j in range(rgb.shape[1]):            grayscale[i, j] = (0.299 * rgb[i, j, 0] + 0.587 * rgb[i, j, 1] + 0.114 * rgb[i, j, 2])    return grayscale# 加载图像img = imread("d:/images/enlarged_taj_mahal.png")grayscale_img_numba = rgb_to_grayscale_numba(img)# 仅对 Numba 部分计时start_time = time.time()for _ in range(5):    # 使用 Numba 转换为灰度图像    grayscale_img_numba = rgb_to_grayscale_numba(img)print(f"Numba Execution Time: {time.time() - start_time} seconds")# 显示原始图像和灰度图像plt.figure(figsize=(10, 5))plt.subplot(1, 2, 1)plt.imshow(img)plt.title('Original Image')plt.axis('off')plt.subplot(1, 2, 2)plt.imshow(grayscale_img_numba, cmap='gray')plt.title('Grayscale Image with Numba JIT')plt.axis('off')plt.show()
```

输出：

```
Numba Execution Time: 0.09015464782714844 seconds
```

**Numba CUDA 版本**

```
from numba import cudaimport numpy as npimport matplotlib.pyplot as pltfrom matplotlib.image import imreadimport time# CUDA 内核来转换 RGB 到灰度图像@cuda.jitdef rgb_to_grayscale_cuda(rgb, grayscale):    i, j = cuda.grid(2)  # 获取每个线程的 2D 网格索引    if i < rgb.shape[0] and j < rgb.shape[1]:  # 检查边界        grayscale[i, j] = (0.299 * rgb[i, j, 0] +                           0.587 * rgb[i, j, 1] +                           0.114 * rgb[i, j, 2])# 加载图像img = imread("d:/images/enlarged_taj_mahal.png")# 在主机上预分配输出灰度数组grayscale_img = np.zeros((img.shape[0], img.shape[1]), dtype=np.float32)# 分配设备内存用于输入和输出图像img_device = cuda.to_device(img)grayscale_img_device = cuda.device_array((img.shape[0], img.shape[1]), dtype=np.float32)# 定义每个块的线程数和每个网格的块数threads_per_block = (16, 16)  # 16x16 线程每块是一个常见的选择blocks_per_grid_x = (img.shape[0] + threads_per_block[0] - 1) // threads_per_block[0]blocks_per_grid_y = (img.shape[1] + threads_per_block[1] - 1) // threads_per_block[1]blocks_per_grid = (blocks_per_grid_x, blocks_per_grid_y)# 启动 CUDA 内核start_time = time.time()rgb_to_grayscale_cuda[blocks_per_grid, threads_per_block](img_device, grayscale_img_device)# 复制结果回主机grayscale_img = grayscale_img_device.copy_to_host()print(f"CUDA Execution Time: {time.time() - start_time} seconds")# 显示原始图像和灰度图像plt.figure(figsize=(10, 5))plt.subplot(1, 2, 1)plt.imshow(img)plt.title('Original Image')plt.axis('off')plt.subplot(1, 2, 2)plt.imshow(grayscale_img, cmap='gray')plt.title('Grayscale Image with NUMBA CUDA')plt.axis('off')plt.show()
```

输出：

```
CUDA Execution Time: 0.04651522636413574 seconds
```

![](assets/002.jpg)

这次，CUDA 版本的运行速度仅是 Numba JIT 版本的两倍，但仍然相当令人印象深刻。

### 总结

本文介绍了如何通过 Numba 的 CUDA 加速 Python 代码，只需少量努力即可获得显著的性能提升。需要注意的是，我们从已经使用 Numba JIT 优化的代码开始，因此性能提升的基础水平已经非常高。例如，看看卢卡斯数计算的运行时间从常规 Python 到 Numba JIT 再到 Numba CUDA 的演变：

-   常规 Python: 29 秒
    
-   Numba JIT: 0.71 秒
    
-   Numba CUDA: 0.1 秒
    

与最初的非优化代码相比，这几乎快了 300 倍。

### 进一步优化和注意事项

虽然 Numba 的 CUDA 加速功能已经非常强大，但仍有进一步优化的空间。以下是一些建议和注意事项：

1.  **调整块和线程数**：
    

-   在 CUDA 编程中，块（Block）和线程（Thread）的配置对性能有显著影响。不同的配置可能导致不同的 GPU 利用率和并行度。
    
-   在示例 1 中，将 `threads_per_block` 从 256 调整为 64 消除了性能警告，并可能提高了 GPU 利用率。这是因为较小的块可以更好地分配到 GPU 的流式多处理器（SM）上，从而提高并行度。
    
-   可以使用 Numba 提供的内置函数 `cuda.gridsize` 和 `cuda.blockDim` 来动态调整块和线程数，以适应不同的 GPU 架构和计算任务。
    

3.  **内存管理**：
    

-   在 GPU 上进行计算时，内存传输是一个重要的瓶颈。尽量减少主机和设备之间的数据传输次数。
    
-   在示例 3 中，我们将图像数据复制到设备内存中，并直接在设备上进行计算，然后将结果复制回主机。这种方法减少了数据传输次数，提高了效率。
    
-   还可以使用 CUDA 的统一内存（Unified Memory）功能，使主机和设备共享同一内存空间，从而简化内存管理。
    

5.  **并行算法设计**：
    

-   并行算法设计是 CUDA 编程的核心。设计高效的并行算法可以显著提高性能。
    
-   在示例 2 中，我们使用了一个简单的递归算法来计算卢卡斯数。虽然这种方法在 CPU 上效率不高，但在 GPU 上，由于其高度并行性，仍然可以取得不错的效果。
    
-   对于更复杂的计算任务，可以考虑使用更高级的并行算法，例如并行归约（Parallel Reduction）、扫描（Scan）等。
    

7.  **错误处理和调试**：
    

-   CUDA 编程可能会引入一些新的错误类型，例如内存访问越界、设备内存不足等。
    
-   Numba 提供了一些错误处理和调试工具，例如 `cuda-memcheck` 工具，可以帮助检测内存错误。
    
-   还可以使用 Numba 的调试模式（Debug Mode）来获取更详细的错误信息。
    

9.  **硬件限制**：
    

-   并非所有 Python 代码都可以通过 Numba CUDA 加速。例如，Numba 目前不支持所有 Python 特性，例如动态类型、异常处理等。
    
-   此外，GPU 的计算能力和内存容量也会影响加速效果。对于非常大的数据集，可能需要使用更强大的 GPU 或分布式计算技术。
    

### 结论

通过使用 Numba 的 CUDA 加速功能，Python 开发者可以轻松地将计算密集型任务从 CPU 转移到 GPU，从而显著提高代码性能。本文通过三个示例展示了 Numba CUDA 的基本用法和性能优势，包括简单 for 循环、递归函数和图像处理任务。

尽管 Numba CUDA 已经提供了强大的加速能力，但为了充分发挥 GPU 的潜力，开发者还需要深入理解 GPU 编程的基本原理，并进行合理的算法设计和优化。

以下是一些关键要点：

-   **Numba CUDA** 是 Numba 库的一部分，可以将部分 Python 代码编译为 CUDA 核函数，并在 GPU 上运行。
    
-   **性能优化** 需要根据具体的计算任务和 GPU 架构进行调整，例如调整块和线程数、优化内存管理、设计高效的并行算法等。
    
-   **内存管理** 是 GPU 编程的重要部分，尽量减少主机和设备之间的数据传输次数，使用统一内存可以简化内存管理。
    
-   **并行算法设计** 是 GPU 编程的核心，设计高效的并行算法可以显著提高性能。
    
-   **错误处理和调试** 是 CUDA 编程的重要环节，使用 Numba 提供的工具可以简化错误检测和调试过程。
    

通过合理使用 Numba CUDA，Python 开发者可以充分利用 GPU 的计算能力，将 Python 应用于更广泛的计算领域，例如科学计算、数据分析、机器学习等。

  

  

![](assets/003.png)