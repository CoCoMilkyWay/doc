# 高频交易系统（32）：hftbacktest中基于HashMap和Vector订单簙深度回测技术比较

fintechhaibin FinTechHi 2026-05-19 06:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490353&idx=1&sn=b2d26c14e2d30c3a6d93a43992243659&chksm=fb5f5b58f91e68831ebd7065ab8dea933ab3ccf06d1b56875a89eb5cb4726b6c89d243a29484#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490353&idx=1&sn=b2d26c14e2d30c3a6d93a43992243659&chksm=fb5f5b58f91e68831ebd7065ab8dea933ab3ccf06d1b56875a89eb5cb4726b6c89d243a29484#rd)

说明下：

1.此系列文章为github开源软件：hftbacktest

2.此基于订单簙回测的高频策略框架涉及到了高频交易系统的各种细节实现，特别对兴新市场高频策略实现，完全不用重新造轮子，可直接使用。

3.此系列文章主要基于官方文档的学习记录，主要是对自己有用，若对你有用那更好。

4.此系列文章对从事高频交易系统、高频交易回测系统、订单簙策略设计的有参考价值；对于非高频策略相关的开发和策略，或想寻找收益翻倍策略的，没有价值。

5.此系列文章特别适合目前芯片公司，涉及到基于硬件的高频交易解决方案的。毕竟隔行如隔山，如果没有从事过相关工作，往往不能把细节做好，就做不出硬核产品，大陆货又没有出路。

6.学习要点包括：高频订单簙数据处理、回测功能框架设计、技术要点、核心功能实现逻辑、性能测试、延时模拟、高频网格交易策略及优化、高频做市策略及优化等等。我会结合自己实践和所需学到哪记录到哪。

[高频交易系统（26）：hftbacktest行情模块编译及数据分析](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490288&idx=1&sn=9db4a5c91f836639cb4af9743252b5ae&scene=21#wechat_redirect)

[高频交易系统（27）：hftbacktest中使用Tardis数据](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490307&idx=1&sn=6c9869db204529374a8099e85b991ae5&scene=21#wechat_redirect)

[高频交易系统（28）：hftbacktest中回测框架](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490308&idx=1&sn=9cc865c1b8f2253b41593fff07934b9a&scene=21#wechat_redirect)

[高频交易系统（29）：hftbacktest中多参数回测](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490320&idx=1&sn=ce96298569f59acf7b918aaa52780855&scene=21#wechat_redirect)

[高频交易系统（30）：hftbacktest中多资产策略基础概念](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490339&idx=1&sn=f7147bc20c908c8a1025e4858ea5a19f&scene=21#wechat_redirect)

[高频交易系统（31）：hftbacktest中订单提交与订单管理](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490341&idx=1&sn=301f66b3bf09c62fcab2b29919e1ef5d&scene=21#wechat_redirect)

* * *

  

hftbacktest中有两个回测方式。核心代码在hashmapmarketdepth.rs、roivectormarketdepth.rs中。

1.HashMap底层分析

Rust 的 \`HashMap<K, V>\` 基于hashbrown crate 实现，采用开放寻址法（Open Addressing）+ Robin Hood 哈希：

```
内存布局：
```

主要特点如下：

-   开放寻址法：冲突时不使用链表，而是线性探测下一个槽位；
    
-   Robin Hood 哈希：减少探测长度，将"富"元素移到"穷"位置；
    
-   负载因子：默认 7/8，超过时自动扩容（rehash）。
    

  

hftbacktest 中价格档位使用高频交易系统普遍做法，即 i64 作为键：

```
// hashmapmarketdepth.rs:25-26
```

哈希过程如下：

-   price\_tick: i64→ 哈希函数 → hash: u64；
    
-   index = hash % buckets.len()；
    
-   线性探测直到找到对应键。
    

  

性能情况：

-   哈希计算：O(1)
    
-   查找平均：O(1)（假设哈希分布均匀）
    
-   最坏情况：O(n)（所有键冲突）
    

  

扩容机制：

当 size / capacity > 7/8时触发扩容，扩容流程如下：

-   分配新内存：new\_capacity = old\_capacity \* 2；
    
-   重新哈希：所有元素重新计算位置；
    
-   释放旧内存。
    

  

扩容成本：

-   时间：O(n) 需要移动所有元素；
    
-   空间：峰值时占用 2x 内存。
    

  

扩容场景：

-   ob初期频繁扩容：从空订单簿开始；
    
-   ob稳定后无需扩容：价格范围相对固定下来；
    
-   ob极端行情可能触发扩容：比如价格跳空。
    

  

缓存命中率：

HashMap 的缓存局部性较差，比如查询连续价格档位：

```
HashMap 内存分布（非连续）：
```

每次访问可能触发，按回测数据，遍历HashMap的缓存命中率约60-70%：

-   L1 缓存未命中 → L2 缓存查询
    
-   L2 缓存未命中 → L3 缓存查询
    
-   L3 缓存未命中 → 主存访问（~100ns）
    

  

2.Vector底层分析

Rust 的 \`Vec<T>\` 是连续内存分配：

```
内存布局：
```

充分利用了CPU缓存预取的硬件优势：

```
   访问 arr[0]：
```

缓存行对齐：

```
   缓存行大小：64 bytes
```

按内存局部性原理，Vector完美符合时间和空间局部性：

-   时间局部性：最近访问的数据很可能再次访问。
    
-   空间局部性：相邻地址的数据很可能被访问。
    

在hftbacktest中的ROI 区间索引映射算法实现中，核心思想是将价格区间 \[roi\_lb, roi\_ub\]映射到数组索引\[0, roi\_range-1\]。

```
// roivectormarketdepth.rs:56-59
```

映射过程如下：

```
价格 → 索引：
```

示例如下：

```
假设：
```

把连续的价格变成数组下标（索引），让查买卖盘深度变成 O (1) 极速访问。用数组下标代替价格，实现最快速度的盘口查询。

```
bid_depth = [10, 25, 18, 0, 0, 0]
```

```
ask_depth = [0, 0, 0, 32, 40, 22]
```

3.HashMapMarketDepth 源码实现

```
// hashmapmarketdepth.rs:21-32
```

数据结构实例：

```
HashMapMarketDepth {
```

查询实现：

```
// hashmapmarketdepth.rs:302-310
```

查询路径：

```
bid_qty_at_tick(600000):
```

时间复杂度：

-   平均：O(1) + 哈希计算 (~10-20ns)
    
-   最坏：O(n) 理论上可能，实际很少发生
    

  

更新逻辑：

```
// hashmapmarketdepth.rs:86-139
```

查找最优价：

```
// hashmapmarketdepth.rs:34-42
```

基于价格区间索引映射的**HashMap** 盘口结构，**删除最优价后需遍历查找新最优价，最坏情况遍历全价格区间，且 HashMap 遍历效率远低于 Vector，存在缓存未命中导致的性能损耗**。

4.ROIVectorMarketDepth 源码实现

```
// roivectormarketdepth.rs:15-28
```

内存示例：

```
roi_lb = 300000, roi_ub = 900000, tick_size = 0.1
```

价格到索引的映射：

```
// roivectormarketdepth.rs:436-446
```

因已确保索引有效，使用`get_unchecked`可跳过边界检查，在保证安全的前提下将数组访问速度提升数倍，满足高频交易的极致性能需求。

更新逻辑：

```
// roivectormarketdepth.rs:139-204
```

查询最优价：

```
// roivectormarketdepth.rs:30-40
```

Vector 凭借连续内存实现 CPU 自动预取、直接索引访问省去哈希计算，带来高达约90%的缓存命中率，显著优于 HashMap 约60%的缓存命中率。

5.两者在回测框架中的集成

MarketDepth trait 定义如下：

```
// depth/mod.rs:27-61
```

多态实现：

```
// 两种实现都满足 MarketDepth trait
```

6.性能优化点

内联优化：

```
// 所有关键方法都标记为 #[inline(always)]
```

分支预测优化：

```
// ROI 检查的分支预测
```

编译时优化：

```
// tick_size 和 lot_size 在构造时确定
```

7.实际中如何选择

```
                      开始选型
```