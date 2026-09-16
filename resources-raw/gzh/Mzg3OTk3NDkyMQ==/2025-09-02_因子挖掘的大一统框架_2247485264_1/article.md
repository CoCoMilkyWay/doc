# 因子挖掘的大一统框架

QuantSeek QuantSeek 2025-09-02 23:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&chksm=ced42d6e84295a0f21358621908fd765c627a681412aaf915edb3163d1c2fa3d01225f7f9085#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485264&idx=1&sn=513377dbb620e7270b35b259d7dbc865&chksm=ced42d6e84295a0f21358621908fd765c627a681412aaf915edb3163d1c2fa3d01225f7f9085#rd)

# ![](assets/001.png)

这篇文章提出了一套全新的、统一且高效的量化投资策略（Alpha因子）自动挖掘模型评估框架——AlphaEval。该框架旨在解决传统评估方法（如回测和IC）存在的高成本、低效率、指标单一等问题。

## 一、背景

1.  Alpha因子挖掘的意义： Alpha因子是将原始金融数据转化为未来收益预测信号的公式或表达式。 近年来，随着遗传算法、强化学习、生成对抗网络（GANs）和大语言模型（LLMs）的发展，Alpha因子的自动化挖掘能力显著增强。
    
2.  现有评估方法的局限性： 回测（Backtesting）：计算昂贵、顺序执行、对策略参数敏感。 IC/RankIC等指标：只衡量预测能力，忽略稳定性、鲁棒性、多样性和可解释性。 封闭源代码：大多数模型不开源，难以复现和公平比较。
    

## 二、AlphaEval框架

AlphaEval是一个无需回测、可并行化、统一的多维度评估框架，从五个互补维度评估Alpha因子及其生成模型的质量：

维度

指标

说明

**预测能力**

PPS（Predictive Power Score）

综合IC和RankIC

**时序稳定性**

RRE（Relative Rank Entropy）

衡量Alpha排名随时间的稳定性

**鲁棒性**

PFS（Perturbation Fidelity Score）

衡量Alpha对市场扰动的敏感度

**金融逻辑性**

Logic Score

用大语言模型评估Alpha的合理性

**多样性**

DH（Diversity Entropy）

衡量Alpha集合的信号多样性，避免冗余

**具体来说：**

1.  预测能力（PPS） 综合Pearson IC和Spearman RankIC，平衡线性和非线性关系。
    
2.  时序稳定性（RRE） 使用KL散度衡量相邻时间点Alpha排名的变化，值越高越稳定。
    
3.  鲁棒性（PFS） 引入高斯噪声和t分布扰动，计算扰动前后Alpha排名的Spearman相关性，值越高越鲁棒。
    
4.  金融逻辑性（Logic Score） 使用GPT-4o对Alpha表达式进行逻辑性评分（0–100），考虑经济直觉和可解释性。
    
5.  多样性（DH） 基于Alpha信号的协方差矩阵特征值分布计算熵，值越高表示信号越不冗余。
    

![](assets/002.png)

## 三、实验验证

1.  实验设置 使用Qlib平台，涵盖A股和美股数据。 评估8个代表性模型，包括GA、RL、GANs、LLMs四类。
    
2.  主要结果：
    

![](assets/003.png)

-   \*\*LLMs类模型（AlphaAgent）\*\*在预测力、逻辑性方面表现最优，适合人机协同场景。
    
-   **RL类模型**在稳定性和鲁棒性方面最强。
    
-   **GANs类模型**预测力强，但鲁棒性较差。
    
-   **GA类模型**鲁棒性好，AutoAlpha在多样性方面突出。
    

![](assets/004.png)

  

### 3\. 消融实验（Ablation Study）

-   单独使用某一维度指标选股效果不如综合AlphaEval评分。
    
-   AlphaEval综合评分能显著提升组合收益并降低回撤。
    

  

### 4\. 指标合理性验证

-   **RRE与换手率负相关**：稳定性高的Alpha导致更低交易频率。
    
-   **PFS与最大回撤负相关**：鲁棒性高的Alpha回撤更小。
    
-   **Logic Score与人类专家评分高度一致**（NDCG>0.9）。
    

  

### 5\. 效率对比

-   AlphaEval比传统回测方法**快25%以上**，且可并行化。
    

  

## 四、写在最后

开源代码可看https://github.com/BerkinChen/AlphaEval。

大家可以将AlphaEval无痛接入[QuantSeek框架](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247485132&idx=1&sn=fce61f52f8122a9d512469c416341d8c&scene=21#wechat_redirect)进行研究，快速转化。

![](assets/005.jpg)