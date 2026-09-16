# 短时序预测排名第一的网络模型。

无言 量化前沿速递 2024-08-26 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488127&idx=1&sn=fbd68c5d478ce910a531a7859afac387&chksm=c3f54fb6494b8196a1c32bf4b4e93fd22077a67b4be0138acfdf358601cef8aac6575dcb60f0#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488127&idx=1&sn=fbd68c5d478ce910a531a7859afac387&chksm=c3f54fb6494b8196a1c32bf4b4e93fd22077a67b4be0138acfdf358601cef8aac6575dcb60f0#rd)

# 

  

**短序列预测排名第一的模型-TimesNet**

简介

![](assets/001.png)

截止2024.3月时间序列在不同类型数据集合上的排名如下：

![](assets/002.png)

今天我们介绍TimesNet，它在短周期序列的预测上排名第一，其在捕捉时序中的多周期关系是其成功的核心。

TimesNet根据时间序列的多周期性，它的模块化架构能够捕捉来自**不同周期**的时间模式。对于每个周期，为了捕捉相应的周期内和周期间的变化，我们在TimesNet中设计了一个TimesBlock，它可以将一维时间序列转换为二维空间，并通过一个参数高效的inception模块同时对这两种变化进行建模。

## 

TimesNet

![](assets/001.png)

### 1\. 核心思想

1.  使用一种模块化的方法来进行时间变化建模。通过将一维时间序列转换为二维空间，这样可以同时呈现周期内和周期间的变。这样我们便可以挖掘多重周期性以及周期内和周期间复杂交互。
    
2.  TimesNet使用TimesBlock通过一个参数高效的Inception模块来发现多个周期，并从转换后的二维张量中捕捉时间上的二维变化。
    

#### 2.TimesNet框架  
一维变二维

TimesNet的核心先将时间序列通过Fast Fourier Transform转化为多个周期的形式。

![](assets/003.png)

转化为多周期形式之后再reshape成二维的形式，这时我们便可以使用处理图像的策略来处理数据，最后再将处理之后的数据转化为和原始数据相同长度的形式。

#### **TimesNet框架**

![](assets/004.png)

**对应数学表示**

![](assets/005.png)

TimesBlock代码可参考如下。

```
class TimesBlock(nn.Module):    def __init__(self, configs):        super(TimesBlock, self).__init__()        self.seq_len = configs.seq_len        self.pred_len = configs.pred_len        self.k = configs.top_k        # parameter-efficient design        self.conv = nn.Sequential(            Inception_Block_V1(configs.d_model, configs.d_ff,                               num_kernels=configs.num_kernels),            nn.GELU(),            Inception_Block_V1(configs.d_ff, configs.d_model,                               num_kernels=configs.num_kernels)        )    def forward(self, x):        B, T, N = x.size()        # 1. FFT转化        period_list, period_weight = FFT_for_Period(x, self.k)        # 2. 1维变2维并使用卷积处理之后转化为原先的长度        res = []        for i in range(self.k):            period = period_list[i]            # padding            if (self.seq_len + self.pred_len) % period != 0:                length = (                                 ((self.seq_len + self.pred_len) // period) + 1) * period                padding = torch.zeros([x.shape[0], (length - (self.seq_len + self.pred_len)), x.shape[2]]).to(x.device)                out = torch.cat([x, padding], dim=1)            else:                length = (self.seq_len + self.pred_len)                out = x            # reshape            out = out.reshape(B, length // period, period,                              N).permute(0, 3, 1, 2).contiguous()            # 2D conv: from 1d Variation to 2d Variation            out = self.conv(out)            # reshape back            out = out.permute(0, 2, 3, 1).reshape(B, -1, N)            res.append(out[:, :(self.seq_len + self.pred_len), :])        # 3. softmax 和 res相乘之后做residual链接        res = torch.stack(res, dim=-1)        # adaptive aggregation        period_weight = F.softmax(period_weight, dim=1)        period_weight = period_weight.unsqueeze(            1).unsqueeze(1).repeat(1, T, N, 1)        res = torch.sum(res * period_weight, -1)                res = res + x        return res
```

## 

实验结果

![](assets/001.png)

**预测结果**

![](assets/006.png)

  

![](assets/007.png)

-   TimesNet在长期和短期设置中都表现出色。具体来说，TimesNet在长期预测中在超过80%的案例中达到了最先进的水平。
    
-   对于M4数据集，由于时间序列是从不同来源收集的，因此时间上的变化可能相当多样化。TimesNet在这一任务中的表现仍然最好，超越了许多先进的基于MLP和Transformer的模型。
    

# 

参考文献

![](assets/001.png)

1.  https://arxiv.org/pdf/2210.02186
    
2.  https://github.com/thuml/Time-Series-Library/blob/main/models/TimesNet.py