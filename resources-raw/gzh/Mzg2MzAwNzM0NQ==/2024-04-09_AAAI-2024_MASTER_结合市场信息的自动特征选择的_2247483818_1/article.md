# AAAI-2024 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益，附代码

QuantML QuantML 2024-04-09 10:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=cf5dc731c16e67b2ea33697f6135059b1bc96e0ef1740a5631b7a1f23da6dcedd8f69aa778fc#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=cf5dc731c16e67b2ea33697f6135059b1bc96e0ef1740a5631b7a1f23da6dcedd8f69aa778fc#rd)

1.模型概述

  

本文作者来自上海交通大学和阿里巴巴，文章提出了一个名为MASTER的新型股票价格预测模型，全称为Market-Guided Stock TransformER。该模型旨在解决股票市场高波动性导致的股价预测难题，特别是针对现有方法在处理股票间时刻性和跨时性相关性方面的不足。

  

MASTER模型通过结合市场信息来自动选择特征，并模拟股票间的瞬时和跨时相关性。与传统的基于Transformer的模型不同，MASTER专门针对股票价格预测任务设计，能够有效捕捉股票间的动态相关性，并适应市场变化。

  

  

![](assets/001.png)

  

![](assets/002.png)

  

  

2. 模型架构

  

MASTER模型的架构包括以下几个关键步骤：

1.  市场引导门控（Market-Guided Gating）：
    

-   构建市场状态向量`mτ`，包含市场指数价格和交易量等信息。
    
-   通过门控机制根据市场状态调整特征向量，实现市场引导下的特征选择。
    

3.  股票内部聚合（Intra-Stock Aggregation）：
    

-   对每个股票序列中的每个时间步进行信息聚合，生成局部嵌入`hu,t`，保留时间序列的局部细节。
    

5.  股票间聚合（Inter-Stock Aggregation）：
    

-   利用注意力机制计算股票间的相关性，并聚合其他股票的局部嵌入信息，生成时间嵌入`zu,t`。
    

7.  时间聚合（Temporal Aggregation）：
    

-   对每个股票的所有历史时间嵌入进行聚合，生成综合股票嵌入`eu`。
    

9.  预测（Prediction）：
    

-   将综合股票嵌入送入预测层进行标签预测。
    

  

模型代码：  

  

class MASTER(nn.Module):  
    def \_\_init\_\_(self, d\_feat=158, d\_model=256, t\_nhead=4, s\_nhead=2, T\_dropout\_rate=0.5, S\_dropout\_rate=0.5,  
                 gate\_input\_start\_index=158, gate\_input\_end\_index=221, beta=None):  
        super(MASTER, self).\_\_init\_\_()  
        \# market  
        self.gate\_input\_start\_index = gate\_input\_start\_index  
        self.gate\_input\_end\_index = gate\_input\_end\_index  
        self.d\_gate\_input = (gate\_input\_end\_index - gate\_input\_start\_index) \# F'  
        self.feature\_gate = Gate(self.d\_gate\_input, d\_feat, beta\=beta)  
  
        self.layers = nn.Sequential(  
            \# feature layer  
            nn.Linear(d\_feat, d\_model),  
            PositionalEncoding(d\_model),  
            \# intra-stock aggregation  
            TAttention(d\_model\=d\_model, nhead\=t\_nhead, dropout\=T\_dropout\_rate),  
            \# inter-stock aggregation  
            SAttention(d\_model\=d\_model, nhead\=s\_nhead, dropout\=S\_dropout\_rate),  
            TemporalAttention(d\_model\=d\_model),  
            \# decoder  
            nn.Linear(d\_model, 1)  
        )  
  
    def forward(self, x):  
        src = x\[:, :, :self.gate\_input\_start\_index\] \# N, T, D  
        gate\_input = x\[:, \-1, self.gate\_input\_start\_index:self.gate\_input\_end\_index\]  
        src = src \* torch.unsqueeze(self.feature\_gate(gate\_input), dim\=1)  
  
        output = self.layers(src).squeeze(-1)  
  
        return output  

  

3\. 模型特点

  

-   动态特征选择：MASTER模型通过市场状态向量动态调整特征的重要性，适应市场变化。
    
-   瞬时和跨时相关性建模：与传统模型不同，MASTER能够捕捉股票间的瞬时和跨时相关性，这在股票市场中尤为重要。
    
-   市场信息集成：模型利用市场信息来指导特征选择和相关性建模，提高了预测的准确性和可靠性。
    

  

4\. 实验结果

  

-   在中国股市的CSI300和CSI800股票集上进行的实验表明，MASTER模型在多个排名指标上均优于现有的基准方法。
    
-   通过可视化注意力图，可以观察到MASTER模型捕捉到的瞬时和跨时股票相关性，为研究股票相关性提供了更细粒度的视角。
    

  

MASTER模型为股票价格预测提供了一种新的方法，能够有效地模拟真实的股票相关性，并利用市场信息来指导特征选择。未来的工作可以探索更高质量的股票相关性挖掘，以及市场信息的其他潜在用途。

  

CSI300代码运行结果：

  

{'IC': 0.0611889916540558, 'ICIR': 0.39591070126566097, 'RIC': 0.06375811856723443, 'RICIR': 0.3944402776483699}

  

所有代码，论文及数据下载地址见星球。

  

您也可以将本文转发至三个百人以上量化群至少五分钟，后台截图留言获取代码。

  

欢迎加入星球交流

  

![](assets/003.jpg)