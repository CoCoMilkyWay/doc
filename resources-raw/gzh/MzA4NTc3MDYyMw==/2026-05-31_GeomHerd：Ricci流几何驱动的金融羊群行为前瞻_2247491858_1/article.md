# GeomHerd：Ricci流几何驱动的金融羊群行为前瞻性量化框架

InfinityQuant 映翡量化 2026-05-31 08:42 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247491858&idx=1&sn=0438e6237645913c572ded5721fa00f4&chksm=9ea0669be2b48b39cbabe40e6bf5aa7c0537b3f21e1c389eff1da231c6b4c9017b054e3c62e8#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247491858&idx=1&sn=0438e6237645913c572ded5721fa00f4&chksm=9ea0669be2b48b39cbabe40e6bf5aa7c0537b3f21e1c389eff1da231c6b4c9017b054e3c62e8#rd)

《GeomHerd: A Forward-looking Herding Quantification via Ricci Flow Geometry on Agent Interactive Simulations》（2026年5月12日）提出一项前瞻性（forward-looking）框架，用于量化金融市场中的“herding”（羊群行为/集体协调），即代理人行为对齐并集体行动的现象，这是市场脆弱性和系统性风险的核心驱动因素。

核心问题与创新

传统herding量化方法（如基于价格的相关性统计、CSSD、CSAD、LSV等）本质上是滞后的（post-hoc），只能在协调行为已影响实际回报或披露头寸后检测到。现有几何方法也多基于价格相关图，继承了这一观测滞后问题。 

GeomHerd的关键创新：

-   上游代理交互图：直接在代理人行为层面构建动态图（而非价格/回报层面）。使用异构LLM驱动的多代理模拟器（每个交易者由个性化persona-conditioned LLM实例化），生成可观测的行为流，作为“可预测世界”。
-   几何度量：基于离散Ollivier-Ricci曲率（Ollivier-Ricci curvature）捕捉协调的结构拓扑。

-   正曲率（κ\_OR^+）：捕捉团簇内（within-clique）协调（信息级联机制）。
-   强负曲率/桥边比例（β\_-）：识别社区间传播的桥边（contagion机制）。

-   额外信号：Ricci流下的“neckpinch”时间（τ\_sing，前瞻性崩塌临近度）和有效行动词汇量（V\_eff，行为多样性收缩）。
-   理论桥接：通过均场近似，将图论度量与经典宏观herding统计CSAD（cross-sectional absolute deviation）关联起来。 

方法在Cividino-Sornette连续自旋（CWS）代理基模型上（66 个代理、4 个资产，耦合参数从独立决策到强烈羊群）作为主要金融测试床评估，并使用Vicsek自驱动粒子模型（物理flocking模型）进行跨域转移验证。主要实证结论

-   显著领先性：

-   主探测器在中位数上比阶参数（order-parameter） onset 提前 272步触发警报。
-   传染探测器（β\_-）在65%的关键轨迹上提前 318步召回。
-   在共同触发轨迹上，比价格相关图基线提前 40步。 

-   互补指标：级联期间代理行动的有效词汇量收缩，反映行为同质化。
-   跨域泛化：几何签名成功转移到Vicsek模型，能以高AUROC区分有序/无序轨迹。
-   预测提升：使用曲率条件化的预测头，在级联窗口的对数回报MAE上优于仅探测器条件或仅价格基线。
-   鲁棒性与消融：二值行动一致边优于余弦相似性变体；信号与经典基准（如增强CCK、LSV）一致但领先；13F披露回测定性捕捉历史压力期。 

讨论、局限与未来GeomHerd 将herding视为几何坍缩（geometric collapse），提供上游、结构化的早期预警，适用于系统稳定性和风险监测。局限包括测试床的程式化性质、假警报验证等。未来方向包括与学习型早期预警系统融合、真实市场13F图部署等。 总体上，该工作将离散Ricci几何、LLM多代理模拟与经典金融herding文献结合，提供了一个可解释、前瞻性的协调量化新范式。

![](assets/001.png)

![](assets/002.png)

https://arxiv.org/abs/2605.11645

PDF已更新至星球，更多策略、资讯⬇️

欢迎加入：学术界的Alpha

![](assets/003.png)