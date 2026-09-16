# QuantSeek框架的时间控制

QuantSeek QuantSeek 2025-05-08 10:14 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485205&idx=1&sn=f136a3ccd5dc2a4094d0ca97a1c7ca11&chksm=ceed62b7ac20996eb56c109f8c8f4e024a89408f110aee52e2cf7eee17364bf267026a69cf7f#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485205&idx=1&sn=f136a3ccd5dc2a4094d0ca97a1c7ca11&chksm=ceed62b7ac20996eb56c109f8c8f4e024a89408f110aee52e2cf7eee17364bf267026a69cf7f#rd)

# 时间控制是确保数据、因子更新无误的重要一环。在QuantSeek框架里面，主要分成2个方面。

## 底层数据的更新时间

QuantSeek会控制各个底层数据的最早更新时间，这是因为底层数据供应商将数据收集需要时间。

1.  不同数据更新的时间不同，比如日线数据基本上收盘过十来分钟就可以获取到，但是财务数据可能需要隔天。
    
2.  不同数据商更新的速度也不同。
    

用户可以根据1、2自行确定各个数据的更新时间。QuantSeek框架以tushare数据源为例子做好了设置。

## 因子的更新时间

不同于底层数据，因子的更新取决于其所需要的底层数据是否更新完毕，因此QS的主要逻辑是在不同的因子文件更新前，自动检查所需底层数据是否更新完毕，避免错误更新。

  

![](assets/001.jpg)