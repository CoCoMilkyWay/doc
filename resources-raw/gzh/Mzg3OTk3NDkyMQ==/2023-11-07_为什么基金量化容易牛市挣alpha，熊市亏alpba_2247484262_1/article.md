# 为什么基金量化容易牛市挣alpha，熊市亏alpba

锤哥 QuantSeek 2023-11-07 13:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247484262&idx=1&sn=108b3e0608870b986c73bcfa38507f0d&chksm=ce0bffe1c322e26e5d91e7a256955f7711ffdca5e011e7b0f7dea2cf15ea02b1ad32e4cb958a#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247484262&idx=1&sn=108b3e0608870b986c73bcfa38507f0d&chksm=ce0bffe1c322e26e5d91e7a256955f7711ffdca5e011e7b0f7dea2cf15ea02b1ad32e4cb958a#rd)

看了下基金的回测数据，有个很明显的感觉就是牛市能挣beta加alpha，熊市亏beta还可能亏alpha。

  

本质上和基金业绩与申赎规律有关。所有的量化因子都在寻找”好的基金"，你不会像股票一样去找所谓反转的基金，因为中间夹杂着经理的交易行为，导致反转行为在基金中并不存在。

  

既然牛熊是外生变量，好基金在牛市中就会得到更多的申购，助长alpha，同理在熊市也经不住大量的赎回，没有alpha甚至略亏。