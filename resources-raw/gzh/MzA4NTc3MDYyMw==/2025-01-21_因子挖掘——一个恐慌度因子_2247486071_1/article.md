# 因子挖掘——一个恐慌度因子

InfinityQuant 映翡量化 2025-01-21 21:59 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247486071&idx=1&sn=fa4d61104109a0c71934c0a04a31b255&chksm=9ec50cb5fd13872f79752ebcbadbef1e846a7f20c43b84ac69511f318e866ca66a889e082938#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247486071&idx=1&sn=fa4d61104109a0c71934c0a04a31b255&chksm=9ec50cb5fd13872f79752ebcbadbef1e846a7f20c43b84ac69511f318e866ca66a889e082938#rd)

一个有趣的因子——恐慌度因子，并且具有非常强的经济学意义。  
  
m\_ret = group\_mean(returns, rank(ts\_mean(cap, 20)), market);  
horro = abs(returns - m\_ret) / (abs(returns)+abs(m\_ret)+0.1);  
horro\_day = ts\_mean(horro, 22);  
ret\_std = ts\_std\_dev(returns, 22);  
adj\_ret = horro\_day \* ret\_std \* returns;  
adj\_ret\_mean = ts\_mean(adj\_ret, 22);

adj\_ret\_std = ts\_std\_dev(adj\_ret, 22);  
horro\_std\_bonus = zscore(adj\_ret\_mean) + zscore(adj\_ret\_std);  
  
   
🔍 因子构成解析：  
  
m\_ret：计算股票收益的组内均值，基于市值排名和市场的平均收益。  
horro：衡量个股收益与组内均值的偏离程度，反映恐慌情绪。  
horro\_day：对恐慌情绪进行22天的移动平均，平滑数据。  
ret\_std：计算22天的收益标准差，衡量波动性。  
adj\_ret：结合恐慌情绪和波动性，调整收益。  
adj\_ret\_mean 和 adj\_ret\_std：分别计算调整后收益的均值和标准差。  
horro\_std\_bonus：将调整后收益的均值和标准差进行标准化，并相加，得到最终的因子值。  
  
💡 为什么这个因子能赚钱？  
  
做多因子值越大：意味着恐慌情绪较低，收益稳定，适合做多。  
做空因子值越小：意味着恐慌情绪较高，收益波动大，适合做空。  
  
因子表现：  

![](assets/001.jpg)

![](assets/002.jpg)

![](assets/003.jpg)

  

资料来源：

https://platform.worldquantbrain.com/sign-in