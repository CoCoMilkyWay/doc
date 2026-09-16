# 限价订单薄系列（13）使用堆和链表设计订单薄思路

fintechhaibin FinTechHi 2024-12-31 01:11 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247484292&idx=1&sn=a95dac88592a3f310e2133b310a910e8&chksm=fbc607d079a44369be7c65331208ea0c0330e141dd9bd8b2281630f8f18d3cf0f633f6535527#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484292&idx=1&sn=a95dac88592a3f310e2133b310a910e8&chksm=fbc607d079a44369be7c65331208ea0c0330e141dd9bd8b2281630f8f18d3cf0f633f6535527#rd)

持续学习不仅是成长的阶梯，更是遇见智慧导师与宝贵建议的必经之路。  

有同行留言：“其实只考虑连续竞价的话，堆+链表就可以，堆存价格作为索引，然后hashmap中以price和order的链表做key就够了。因为一定是先进后出的一个结构。”

按同行的这个建议再重新理解下订单薄设计思路：

**1.堆（Heap）**：

堆是一种特殊的树形数据结构，可以用来快速找到最大值或最小值。在订单簿中，堆可以用来存储价格，并且可以快速找到最高买价或最低卖价。

堆通常分为两种类型：最大堆（Max-Heap）和最小堆（Min-Heap）。

最大堆（Max-Heap） - 在最大堆中，父节点的值总是大于或等于其子节点的值。 - 最大堆的根节点是整个堆中的最大值。

最小堆（Min-Heap） - 在最小堆中，父节点的值总是小于或等于其子节点的值。 - 最小堆的根节点是整个堆中的最小值。

堆通常用来实现优先队列（Priority Queue），因为它能够高效地进行插入和删除操作。堆的插入和删除操作的时间复杂度为 (O(\\log n))，而取顶操作的时间复杂度为 (O(1))。

**2.链表（Linked List）**：

链表是一种线性数据结构，其中每个元素（节点）包含一个数据部分和一个指向下一个元素的指针。在订单簿中，链表可以用来存储同一价格下的订单，因为订单是按时间顺序排列的（先进先出）。

  

3.设计思路：

**①堆存价格作为索引**：

使用堆来存储价格，可以快速找到最高买价或最低卖价。堆中的每个节点代表一个价格。

**②HashMap中以price和order的链表做key**：

使用HashMap（哈希表）来存储价格和对应的订单链表。每个价格作为一个键（key），对应的值（value）是一个链表，链表中存储了所有该价格下的订单。

**③先进后出结构**：

订单簿中的订单是按时间顺序排列的，新的订单会添加到链表的末尾，而处理订单时会从链表的头部开始处理（先进先出）。这种结构可以高效地处理连续竞价中的订单匹配和管理。按照如上思路：

-   堆用于快速找到最高买价或最低卖价。
    
-   链表用于存储同一价格下的订单，按时间顺序排列。
    
-   HashMap用于将价格和对应的订单链表关联起来。
    

  

4.堆代码示例

下面是关于堆的一个代码示例：

`    #include <iostream>   #include <vector>   #include <algorithm>      class MaxHeap {   public:       void insert(int value) {           heap.push_back(value);           std::push_heap(heap.begin(), heap.end());       }          void deleteMax() {           std::pop_heap(heap.begin(), heap.end());           heap.pop_back();       }          int getMax() const {           return heap.front();       }          bool isEmpty() const {           return heap.empty();       }      private:       std::vector<int> heap;   };      int main() {       MaxHeap maxHeap;       maxHeap.insert(10);       maxHeap.insert(20);       maxHeap.insert(5);          std::cout << "Max value: " << maxHeap.getMax() << std::endl; // 输出 20          maxHeap.deleteMax();       std::cout << "Max value after deletion: " << maxHeap.getMax() << std::endl; // 输出 10          return0;   }    `

  

5.订单薄代码示例

下面是关于基于上述思路实现一个订单薄的简单代码示例（仅仅为了演示思路而已，真正实盘使用的话，技术架构都是通用的，核心的是对各种数据细节的业务逻辑处理。）：

①假设我们有一个订单类 `Order`，包含订单的基本信息：

`       #include <string>   #include <memory>      class Order {   public:       Order(int id, double price, int quantity)           : id(id), price(price), quantity(quantity) {}          int id;       double price;       int quantity;   };    `

②接下来，订单簿类 `OrderBook`，使用堆和链表来管理订单，并处理撤单的情况：

`       #include <unordered_map>   #include <queue>   #include <list>   #include <memory>   #include "order.h"      class OrderBook {   public:       void addOrder(std::shared_ptr<Order> order) {           orders[order->price].push_back(order);           priceHeap.push(order->price);       }          void cancelOrder(int orderId) {           for (auto& [price, orderList] : orders) {               for (auto it = orderList.begin(); it != orderList.end(); ++it) {                   if ((*it)->id == orderId) {                       orderList.erase(it);                       if (orderList.empty()) {                           orders.erase(price);                       }                       return;                   }               }           }       }          std::shared_ptr<Order> getBestOrder() {           while (!priceHeap.empty() && orders[priceHeap.top()].empty()) {               priceHeap.pop();           }           if (priceHeap.empty()) {               returnnullptr;           }           double bestPrice = priceHeap.top();           return orders[bestPrice].front();       }      private:       std::unordered_map<double, std::list<std::shared_ptr<Order>>> orders;       std::priority_queue<double> priceHeap;   };    `

在上面的实现中：

1.  **`addOrder` 方法**：将订单添加到订单簿中。订单按价格存储在 `orders` 哈希表中，价格作为键，订单链表作为值。同时，价格存储在 `priceHeap` 堆中，以便快速找到最佳价格。
    
2.  **`cancelOrder` 方法**：根据订单ID撤销订单。遍历 `orders` 哈希表，找到对应的订单并将其从链表中移除。如果某个价格下的订单链表为空，则从 `orders` 哈希表中删除该价格。
    
3.  **`getBestOrder` 方法**：获取最佳订单（最高买价或最低卖价）。从 `priceHeap` 堆中获取最佳价格，并返回对应的订单。如果堆顶价格的订单链表为空，则从堆中移除该价格并继续查找。
    

6.时间复杂度分析

在上述设计思路实现的订单簿中，主要操作的时间复杂度如下：

1.  **`addOrder` 方法**：
    

-   将订单添加到 `orders` 哈希表中：平均时间复杂度为 (O(1))。
    
-   将价格添加到 `priceHeap` 堆中：时间复杂度为 (O()，其中 (n) 是堆中的元素数量。
    
-   综合时间复杂度为 (O(1) + O(\= O()。
    

3.  **`cancelOrder` 方法**：
    

-   遍历 `orders` 哈希表中的所有价格和订单链表：最坏情况下时间复杂度为 (O(m))，其中 (m) 是所有订单的总数量。
    
-   在链表中查找并删除订单：时间复杂度为 (O(k))，其中 (k) 是某个价格下的订单数量。
    
-   综合时间复杂度为 ，但在平均情况下，哈希表查找和链表删除的时间复杂度较低。
    

5.  **`getBestOrder` 方法**：
    

-   从 `priceHeap` 堆中获取最佳价格：时间复杂度为 (O(1))。
    
-   检查并移除堆顶价格的空链表：最坏情况下时间复杂度为 ，其中 (n) 是堆中的元素数量。
    
-   综合时间复杂度为 。
    

关于此设计思路下的不同订单薄操作的时间复杂度总结：

-   `addOrder` 方法的时间复杂度为 。
    
-   `cancelOrder` 方法的最坏情况下时间复杂度为 ，但在平均情况下较低。
    
-   `getBestOrder` 方法的时间复杂度为 。
    

这些时间复杂度分析基于以下假设：

-   `orders` 哈希表的查找和插入操作在平均情况下为 。
    
-   `priceHeap` 堆的插入和删除操作为 。
    
-   链表的遍历和删除操作在最坏情况下为 。
    

希望更多的大牛交流指正，给出最佳的思路。

  

* * *

  

今日书籍推荐：

丁鹏，中国量化投资学会理事长，“大数据金融丛书”主编。中国量化投资领域的开拓者与奠基者，中国量化投资学会理事长、“大数据金融丛书”主编。

  

《量化投资：策略与技术》适合对量化交易感兴趣的广大投资者，尤其适合希望转型量化交易的程序员参考阅读。

  

本书是有关量化投资策略的著作，首先介绍了量化投资大师西蒙斯的传奇故事（连续20年，每年赚60%）；然后用60多个案例介绍了量化投资的各个方面的内容，主要分为策略篇与理论篇两部分，策略篇主要包括：量化选股、量化择时、股指期货套利、商品期货套利、统计套利、期权套利、算法交易和资产配置等。理论篇主要包括：人工智能、数据挖掘、小波分析、支持向量机、分形理论、随机过程及IT技术等；最后介绍了作者开发的D-Alpha量化对冲交易系统，该系统全球市场验证显示具有长期稳健的收益率。