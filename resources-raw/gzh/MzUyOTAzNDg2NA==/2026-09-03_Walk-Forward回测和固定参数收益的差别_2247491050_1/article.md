# Walk-Forward回测和固定参数收益的差别

fintechhaibin FinTechHi 2026-09-03 22:40 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247491050&idx=1&sn=fce61ff2f21bca595a6cf2cabf9c9b9e&chksm=fb2aaa09520404112a5706e572bb35c8208fdc47a1c286db287d79d2efd59091afd5409195ef#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247491050&idx=1&sn=fce61ff2f21bca595a6cf2cabf9c9b9e&chksm=fb2aaa09520404112a5706e572bb35c8208fdc47a1c286db287d79d2efd59091afd5409195ef#rd)

量化策略回测，别被固定参数的高收益骗了。  
  
普通回测是拿一套参数跑完全程。看着年化超额15%，其实是在偷看未来行情。说白了就是事后挑了个最顺手的参数。  
  
滚动测试：每年末拿过去三年数据重新找最优参数。再拿它测下一年，这样更接近实盘。  
  
结果一测就露馅了：动态调参后，年化超额掉到12.5%。信息比率直接腰斩，最大回撤飙到42%。  
  
为啥会这样？  
  
参数乱跳：所谓最优解根本不靠谱。换个年份就面目全非，纯属在拟合噪音。  
纸上富贵：训练时指标再高也没用。一到样本外照样亏钱，比如2024年预测直接翻车。  
  
动态调参不是万能药。如果市场没有稳定的规律，硬调只会放大风险。

![图1](assets/001.jpg)

图1

![图2](assets/002.jpg)

图2