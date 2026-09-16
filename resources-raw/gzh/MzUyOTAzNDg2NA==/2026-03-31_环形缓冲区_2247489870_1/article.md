# 环形缓冲区

fintechhaibin FinTechHi 2026-03-31 22:15 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247489870&idx=1&sn=47cf48cdd93f13aa2215ae9d52253ad4&chksm=fb2096cdd1f61315965166d62347eb2acc31e23b304f049bd26ef5189bbe9b9a72a48e0488f1#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247489870&idx=1&sn=47cf48cdd93f13aa2215ae9d52253ad4&chksm=fb2096cdd1f61315965166d62347eb2acc31e23b304f049bd26ef5189bbe9b9a72a48e0488f1#rd)

注：这几天事情非常多、杂，没法自主思考一些事情。随便记录一些技术点。

环形缓冲区（ringbuffer），也称为循环缓冲区，是计算领域中用于高效管理固定大小、连续数据流的数据结构。它具有预设的容量，通常使用两个指针： "head" (left) and "tail" (right)“，用来来标记缓冲区的起始和结束位置。

当任一指针到达缓冲区末尾时，会绕回至起始位置。这使得数据可以在常数时间内从头部或尾部添加或访问，从而在特定使用场景中具有极高的效率。

不过，访问缓冲区中间的数据效率较低。一旦缓冲区达到满容量，添加新数据时会覆盖最旧的数据。  

在金融市场领域，连续的数据流的场景很多，比如实时行情接受、实时订单簿更新、实时交易订单处理等等。

在这类场景中处理连续的数值数据时，numpy\_ringbuffer库提供了一种便捷的环形缓冲区实现：

```
 
```

由于高频交易系统中，在短时间内往往会接受大量数据，所以需要编写一个 C 级别的扩展类来加速关键操作。

```
#cringbuffer.pxd
```

```
#cringbuffer.pyx
```

**上面代码中有两个核心变量：**

-   0 ≤ left < capacity：left指针的位置一定在0到缓冲区容量之间，比如容量是10，left就只能是0-9之间的数
    
-   0 ≤ left ≤ right：left 指针的位置一定小于等于right指针的位置，而且两者都不会是负数
    

对于第1点（0 ≤ left < capacity）：

代码里\_wraparound方法中，每次修改 left 指针后都会调用它。比如 left 如果超过了容量（比如容量 10，left 变成 11），这个方法就会把 left 减去容量（11-10=1），让它回到 0-9 的范围内；如果 left 变成负数（比如 - 1），就加上容量（-1+10=9），同样保证在合法范围。

对于第2点（0 ≤ left ≤ right）：

-   在添加元素（append或appendleft）时：right 指针增加的幅度至少和 left 指针减少的幅度一样（或者 left 不动、right 增加），所以 left 永远不会超过 right。
    
-   在删除元素（pop或popleft）时：只有当缓冲区里有元素（即right - left ≥ 1）时，才会调整指针（比如 right 减小或 left 增大）。这保证了即使删除元素，left 也不会超过 right（最多相等，此时缓冲区为空）。
    
-   另外，\_fix\_indices方法调整指针时，left 和 right 会按相同的 "幅度" 移动（比如都减容量或都加容量），它们的相对大小（left ≤ right）不会变。
    

  

上面代码的核心目的是让代码更高效，尤其是在通过 Cython 编译成 C 代码时。

-   因 left 一定在 0 到 capacity 之间，用 left 索引数组时，完全不用担心越界（不用检查是否超出范围）。
    
-   对于 right 指针，只要用right % capacity（取模运算），就能得到它在数组中的实际位置（因为 right 可能比 capacity 大，但取模后一定在 0 到 capacity-1 之间）。
    

这样一来，Cython 生成的代码就可以跳过繁琐的 "索引是否越界" 检查，直接操作内存，速度会快很多。

关于取模，当设置cdivision=True时，取模运算会遵循 C 语言的规则（而不是 Python 的）。这时候要求参与运算的第一个数（这里是 right）必须是正数，才能保证结果正确。

而根据我们的不变量，当需要用 right 指针操作（比如pop元素）时，缓冲区一定不为空（right - left ≥ 1），所以 right 肯定是正数（至少比 left 大，而 left≥0）。因此取模运算的结果一定是正确的。