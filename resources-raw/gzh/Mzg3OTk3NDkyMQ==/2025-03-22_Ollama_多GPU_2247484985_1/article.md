# Ollama 多GPU

QuantSeek QuantSeek 2025-03-22 08:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484985&idx=1&sn=a4b7fb1b7751c8306fdf1ed5f6842045&chksm=ceaf191e8daf5fe6b852c34cb2adaf3eab8f42509d7662ebc44a45422600c2eccf34ffe4946c#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484985&idx=1&sn=a4b7fb1b7751c8306fdf1ed5f6842045&chksm=ceaf191e8daf5fe6b852c34cb2adaf3eab8f42509d7662ebc44a45422600c2eccf34ffe4946c#rd)

当使用配备多个GPU的服务器，通过大型语言模型（LLM）处理大数据集时，使用Ollama服务器进行多进程处理可以是一种有效的策略。以下是优化此过程的详细步骤和技巧。

### 利用多个GPU

###   

根据Ollama的常见问题文档，

安装相同品牌的多个GPU可以显著增加可用的显存（VRAM），从而允许加载更大的模型。当加载一个新模型时，Ollama会评估所需的显存与可用显存的关系。

如果模型能够完全装载到某一单个GPU中，Ollama将把该模型加载到该GPU上。例如，如果模型能够适应单个GPU的内存，你可以在单个服务器上创建多个GPU服务器实例，并使用不同的端口号。这使得可以通过多进程在多个服务器实例之间并行处理。例如，LLMA3.1:70B模型适合装载到单个Nvidia H100 GPU的内存中，这样就可以在一台配有8个H100显卡的服务器上创建8个Ollama服务器实例。

### 设置服务器池

###   

要创建一个服务器池，可以使用以下脚本：

```
#!/bin/bash
```

```

```

```
对齐多进程结果
```

```

```

索引是对齐多进程返回的答案与原始数据框索引的重要步骤。以下是如何跨多个服务器实例设置和调用模型的示例：

```
# 为每个服务器创建实例
```

  

![](assets/001.png)

```
                    GPU利用率
```

```

```

####   

#### 使用Ollama设置进行并发处理

####   

Ollama服务器提供了一些设置来调整其在大多数平台上如何处理并发请求：

-   **OLLAMA\_MAX\_LOADED\_MODELS**
    
    ：最大可并发加载的模型数量，只要它们能够适应可用内存。默认值是3倍GPU数量，或者对于CPU推理，默认值为3。
    
-   **OLLAMA\_NUM\_PARALLEL**
    
    ：每个模型将同时处理的最大并行请求数。默认值会根据可用内存自动选择4或1。
    
-   **OLLAMA\_MAX\_QUEUE**
    
    ：当Ollama繁忙时，它将排队的最大请求数量，超出此数量的请求将被拒绝。默认值是512。
    
      
    

然而，截至2024年9月14日，通过这种方法达到100% GPU资源利用率仍然非常具有挑战性。

  

```
$ OLLAMA_MAX_LOADED_MODELS=8 OLLAMA_NUM_PARALLEL=8 
```

```
OLLAMA_HOST="gpu.server.com:11434" ./ollama serve
```

```

```

### 参考资料

-   https://medium.com/@sangho.oh/efficient-llm-processing-with-ollama-on-local-multi-gpu-server-environment-33bc8e8550c4