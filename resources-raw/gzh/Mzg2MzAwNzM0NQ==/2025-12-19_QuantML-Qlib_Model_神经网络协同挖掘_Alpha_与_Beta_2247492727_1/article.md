# QuantML-Qlib Model | 神经网络协同挖掘 Alpha 与 Beta

QuantML QuantML 2025-12-19 17:33 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247492727&idx=1&sn=49c09f45c19d052a0bb2f5e0f68f0d9a&chksm=cf706bacd3a5a76535d27619844ec6606de4f249f93b526c34c7aff3beee38655aa43a9a2327#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247492727&idx=1&sn=49c09f45c19d052a0bb2f5e0f68f0d9a&chksm=cf706bacd3a5a76535d27619844ec6606de4f249f93b526c34c7aff3beee38655aa43a9a2327#rd)

_**你以为你挖的是  ，其实模型偷偷学了一堆**_ 

## **写在前面**

做量化的朋友们，有没有这种感觉：我们费劲心思挖出来的 Alpha 因子，上了实盘经常莫名其妙地回撤。事后一归因，经常会发现这些 Alpha 居然在某些风格（流动性、市值）上暴露极高。

也就是说，你以为你挖的是  ，其实模型偷偷学了一堆  。

传统的解法是：先用 Barra 模型把风险剔除，再对残差做预测。但 Barra 那套基本面逻辑，对于中高频的量价策略来说，太慢、太钝了。

本文我们参考东方的研报《ABCM：基于神经网络的 alpha 因子和 beta 因子协同挖掘模型》， **构建ABCM模型：通过神经网络同时挖 Alpha 和 Beta，让它们在对抗和协作中自动解耦。**

## **1\. 核心逻辑：Left hand Alpha, Right hand Beta**

ABCM (Alpha-Beta Co-mining) 的核心公式其实回归到了最原本的收益率分解：

-   : 我们梦寐以求的超额收益，方向稳定，易于预测。
    
-   : 市场波动的主导力量，受宏观、风格影响，方向难测，但解释力度大。
    

传统的 AI 挖因子模型，Loss Function 通常直接对着  或者中性化后的  做 MSE。这会导致模型大概率会去走捷径拟合波动更大的 。

**ABCM 的核心在于设计了双塔结构：**

1.  **Alpha 分支**：负责预测特质收益，目标是让预测值接近真实收益（MSE Loss）。
    
2.  **Risk (Beta) 分支**：负责解释市场波动，目标是最大化 （R-Square Loss）。
    

![](assets/001.png)

最妙的地方在于 Loss 的设计：  
在计算 Risk 分支的 Loss 时，模型把 Alpha 分支的输出也加了进来：

强迫 Risk 因子去解释 "Alpha 解释不了的那部分波动"。

## **2\. 硬核代码拆解：图神经网络的妙用**

这篇研报在 Risk 分支引入了一个叫 **ASTGNN (非对称时空图神经网络)** 的模型，逻辑也很符合直觉：

**股票不是孤立的。** 茅台跌了，五粮液大概率也得跟。这种联动关系，Barra 是通过行业分类硬性规定的，而 ASTGNN 是**动态学习**的。

核心代码：

`class ASTGNN(nn.Module):         def __init__(self, input_dim, hidden_dim):             super(ASTGNN, self).__init__()                      def forward(self, x):             # x: (N, H) -> N只股票的特征向量                          # 1. 动态生成关联矩阵             # m1, m2 是对特征的线性变换             # adj[i, j] 表示股票 i 受股票 j 的影响程度             adj = torch.mm(m1, m2.t()) / (self.hidden_dim ** 0.5) # Scaled Dot-Product                          # 2. 屏蔽自相关 (自己不能解释自己的系统性风险)             mask = torch.eye(num_stocks, device=x.device).bool()             adj = adj.masked_fill(mask, -1e9)                          # 3. 归一化为注意力权重             att_weights = F.softmax(adj, dim=1)                          # 4. 聚合邻居信息 (Aggregating Neighbors)             # 这一步就是在计算 "别人的涨跌对我造成了多少 Beta 冲击"             agg_features = torch.mm(att_weights, m3)                          return x + agg_features  # 残差连接   `

## **3\. Loss Function：灵魂所在**

这个模型的精髓全在 Loss 里。

![](assets/002.png)

来看看这个 Rsquare Loss 是怎么写的：

    `def rsquare_loss(self, factors, returns):             # 这里的 factors 包含了 Alpha 和 Risk 因子             # 我们用线性回归的解析解 (最小二乘法) 来算 R^2                          # w = (F^T F)^{-1} F^T y             # 这一步相当于在 Batch 内做了一次实时回归             # 为了防止矩阵不可逆，一定要加 Ridge 正则项 (+ identity * 1e-2)             try:                 inv_ftf = torch.inverse(ftf + identity)             except RuntimeError:                 inv_ftf = torch.pinverse(ftf + identity)                              # ... (计算 SSE 和 SST)             loss = sse / sst             return loss`

这里有个细节：训练时必须以“截面 (Cross-Section)”为 Batch。  
你不能随机抽 64 只股票训练，必须把某一天的 3000 只股票一起丢进去。因为  是解释截面波动的，随机抽样会让  失去意义。

## **4\. 实战效果与反思**

以中证500为例，以基础量价信息以及Barra CNE5因子作为模型输入，数据集划分如下：

  `TRAIN_START = '2020-01-01'     TRAIN_END = '2022-12-31'     VAL_START = '2023-01-01'     VAL_END = '2023-06-30'     TEST_START = '2023-07-01'     TEST_END = '2025-06-30'`

最终验证集RankIC为0.0905，测试集为0.0871，衰减不大。

![](assets/003.png)

## **5\. 总结**

ABCM 模型不仅仅是一个因子挖掘机，它提供了一种**“端到端风险管理”**的思路。

以前我们是：挖因子 -> 扔给风控 -> 风控说不行 -> 回去重挖。  ABCM 是：在挖的时候就告诉模型，什么是风险，什么是收益。

代码已经集成至QuantML Qlib, 欢迎加入QuantML知识星球获取

## **关于QuantML**

QuantML 是链接全球顶尖量化人才的高端社群，我们聚焦于机器学习在量化投资中的最前沿应用。

**核心价值：**

-   **顶级圈层：** 社区涵盖头部机构从业者、知名私募创始人、机构量化负责人，基金经理，券商金工分析师、GitHub千星作者及顶会学者构成。
    
-   **每日高价值内容：** 持续分享前沿论文、论文研报复现、模型代码、核心Alpha因子以及QuantML-Qlib框架等。
    

加入我们，与最强大脑同行，洞见量化未来。

![图片](assets/004.jpg)