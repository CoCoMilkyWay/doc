# QuantSeek框架：分钟数据落盘

QuantSeek QuantSeek 2025-06-16 23:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485231&idx=1&sn=6e99b41e0ca342a1dea08d63546d1880&chksm=ce7ae22d8d887180c1df5db6a7323370ff16db3dd32138aeb3fe4be0353808773a12bda964c9#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485231&idx=1&sn=6e99b41e0ca342a1dea08d63546d1880&chksm=ce7ae22d8d887180c1df5db6a7323370ff16db3dd32138aeb3fe4be0353808773a12bda964c9#rd)

QuantSeek更新啦，这次补全了分钟数据的落盘方式，开启了未来高频因子的研究大门。

## 主要特性

1、采取了日数据完全一样的数据读取接口，用户仅需改变freq参数，比如从'daily'改为'5min'即可无痛读取5分钟数据。

2、唯一区别在于分钟数据增加了trade\_date列，代表交易日datetime，而date列则成了精确到秒的datetime格式数据。

3、通常来说我们都会用交易日来提取分钟数据，很少会精确到分钟提取数据。

更多详细内容请看最新更新说明。

![](assets/001.png)