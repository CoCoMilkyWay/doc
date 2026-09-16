# 基于Hawkes过程的限价订单簿市场下的脉冲控制做市策略

InfinityQuant 映翡量化 2025-11-14 09:31 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247488113&idx=1&sn=aba30d577e8b8cbbd11d48fa72aaa225&chksm=9e24519508a1cada9801e2b5ffbe62822f50e5ca60d0fc12c81230b3165ae83d94843119f640#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247488113&idx=1&sn=aba30d577e8b8cbbd11d48fa72aaa225&chksm=9e24519508a1cada9801e2b5ffbe62822f50e5ca60d0fc12c81230b3165ae83d94843119f640#rd)

📄 《An Impulse Control Approach to Market Making in a Hawkes LOB Market》2025/10/31  
  
💡 核心内容  
1️⃣ 更真实的订单簿：用多元 Hawkes 过程模拟限价簿，天然刻画订单簇发、队列动态与内生价格冲击，告别传统布朗运动“平滑”假设。  
2️⃣ 人不是高频机：把做市商建模为脉冲控制——只能在离散时点挂、撤、吃单，而非连续调仓，更贴近实操约束。  
3️⃣ 高维 HJB-QVI：问题最终落到一组 Hamilton–Jacobi–Bellman 拟变分不等式，维度灾+解析不可解。  
4️⃣ RL 破局：受辅助控制启发，设计双网络 PPO + 自模仿学习，在有限训练步数内把夏普比率干到 30+。【有点神奇】  
5️⃣ 深度 PDE 基准：同时用 Sirignano & Spiliopoulos (2018) 的深度学习方法直接数值求解 HJB-QVI，与 RL 结果交叉验证。  
6️⃣ 实证稳健：在高度逼真的 Hawkes LOB 环境里，两种方法都表现出稳定的做市收益与库存控制。  
  
⚙️ 总结  
把脉冲控制理论与现代深度强化学习结合，为跳跃驱动、高频环境下的做市问题打开了可计算、可落地的新路径。  

  

![](assets/001.png)

  

https://arxiv.org/abs/2510.26438

PDF已更新⬇️

欢迎加入：学术界的Alpha

![](assets/002.jpg)