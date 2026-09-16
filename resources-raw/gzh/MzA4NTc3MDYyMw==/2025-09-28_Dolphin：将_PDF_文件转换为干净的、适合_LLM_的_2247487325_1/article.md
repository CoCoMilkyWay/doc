# Dolphin：将 PDF 文件转换为干净的、适合 LLM 的数据的开源项目

InfinityQuant 映翡量化 2025-09-28 17:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247487325&idx=1&sn=17f8c8ce5be4d27f3cccc49d126a842b&chksm=9eb6cdf698a1b23bc4cd95d908c229c07c8dc5469109d3dda3ef43009c17e8643c74af80019f#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247487325&idx=1&sn=17f8c8ce5be4d27f3cccc49d126a842b&chksm=9eb6cdf698a1b23bc4cd95d908c229c07c8dc5469109d3dda3ef43009c17e8643c74af80019f#rd)

Dolphin 是一个文档解析框架，可将 PDF 转换为 Markdown、HTML、LaTeX 和 JSON 等结构化格式。  
  
它分两个阶段工作：  
  
第一阶段：全面的页面级布局分析，根据自然阅读流程识别和排序元素。

  
第 2 阶段：使用不同的锚点类型和特定于任务的提示对元素进行并行解析  
  
主要特征：  
  
🔄 基于单个 VLM 的两阶段分析然后解析方法；  
📊 在文档解析任务上表现出色；  
🔍 自然读取顺序元素序列生成；  
🧩 针对不同文档元素的异构锚点提示；  
⏱️ 高效的并行解析机制。  
  
它是 100% 开源的。

  

![](assets/001.jpg)

![](assets/002.jpg)

![](assets/003.jpg)

https://github.com/bytedance/Dolphin