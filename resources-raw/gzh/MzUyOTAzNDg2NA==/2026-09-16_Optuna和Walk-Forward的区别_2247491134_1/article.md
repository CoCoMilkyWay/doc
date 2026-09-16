# Optuna和Walk-Forward的区别

fintechhaibin FinTechHi 2026-09-16 08:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247491134&idx=1&sn=b2ce18bb7ffa9212c5ce786037ac8219&chksm=fb8d8cda403f8ad844223ec85acc6e22685a98f92447ef76adead2f16660aec660de80c86c33#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247491134&idx=1&sn=b2ce18bb7ffa9212c5ce786037ac8219&chksm=fb8d8cda403f8ad844223ec85acc6e22685a98f92447ef76adead2f16660aec660de80c86c33#rd)

一、问题

在量化策略开发中，超参数优化与过拟合始终是一对孪生难题。

我们往往通过全样本网格搜索的惨痛教训后，开始转向 Walk-Forward 验证框架，试图通过滚动训练-验证的方式获得更真实的样本外表现。

与此同时，Optuna 作为新一代超参数优化工具，凭借贝叶斯优化（TPE 采样器）的高效搜索能力，逐渐成为量化圈的热门选择。

于是，对于初学者自然就产生了一个问题，量化投资中什么时候使用**Optuna ，什么时候使用Walk-Forward？两者究竟是什么关系？**

从功能来说，Optuna 本身只是一个"寻优引擎"，必须嵌套在 Walk-Forward 框架内使用，才能真正解决过拟合问题。 

两者不是替代关系，而是工具与框架的关系。

## 二、Optuna的定位：智能寻优引擎

Optuna 是一个超参数优化框架，核心能力是自动化搜索超参数空间。

它采用贝叶斯优化方法，根据每次试跑的结果动态调整下一次该试哪组参数，从而用更少的试验找到更好的解。

简言之，网格搜索是"穷举"，Optuna 是"智能猜"。

它能在几十次试验内逼近网格搜索几百次的效果，并且支持连续空间和复杂参数依赖关系。

然而，Optuna 只负责"怎么找最优参数"，不负责"怎么划分数据、怎么避免未来信息"。更棒的是，Optuna 是框架无关的（framework-agnostic）， 无论你使用的是 scikit-learn、XGBoost、LightGBM、PyTorch 还是TensorFlow，它都能完美配合使用。

它不具备时间序列数据切分的能力，也不会自动防止前视偏差。因此，**Optuna 不能单独完成 Walk-Forward 的任务**。

## 三、二者结合使用的思路

目前业界和开源社区的标准做法，是将 Optuna 嵌套在 Walk-Forward 验证框架内使用。

FinRL\_Crypto 的 Walk-Forward 模块直接集成了 Optuna；Fintuna 明确将流程拆为训练、调优、评估三步；多项学术研究也采用同一范式。甚至有专门项目 `omega-lock` 用于验证 Optuna study 是否存在过拟合，其核心手段正是 Walk-Forward validation。

正确的结构是两层嵌套：

```
for each 滚动窗口 (训练窗 t, 验证窗 t+1):    # 外层：Walk-Forward 数据划分    train_data = 历史数据[ : t]    val_data   = 未来数据[t : t+1]   # 此时完全不可见    # 内层：Optuna 在训练窗内寻优    def objective(params):        在 train_data 上训练模型        在 train_data 内部做时序交叉验证（非 shuffle）        返回验证指标（如 IR、Sharpe）    best_params = optuna.optimize(objective, n_trials=100)    # 用 best_params 在 val_data 上做真实 OOS 测试    oos_result = backtest(best_params, val_data)
```

这个结构下，**Optuna 永远看不到验证窗的数据**，它只负责在训练窗内"卷"，而 Walk-Forward 负责在样本外"打分"。

## 四、两者的本质区别

维度

单纯用 Optuna

Optuna + Walk-Forward

数据划分

通常用全数据集或简单交叉验证

严格按时间滚动切分，训练数据不含任何未来信息

参数寻优

在（可能包含未来信息的）数据集上找最优

仅在当前训练窗内寻优，验证窗完全不可见

过拟合风险

极高——参数可能过度拟合全样本噪声

大幅降低——每个参数都经历了真实样本外检验

最终输出

一组"看起来最优"的参数

一组参数 + 每个验证窗的真实 OOS 表现

**关键**：如果直接在**全历史数据**上跑 Optuna 找最优参数，本质上和全样本网格搜索犯的是同一个错误：都是"事后知道答案再做题"。Optuna 再智能，也救不了这种后视偏差。

  

## 五、何时引入 Optuna

  

从大量项目实践来看，引入 Optuna 的决策应当遵循清晰的边界条件，而非无条件采纳。

  

适用场景：项目已具备严格的 Walk-Forward 框架，每个训练窗内确实需要做参数寻优。此时用 Optuna 替代网格搜索是值得的，它提升效率、扩大搜索空间，且不改变原有的样本外验证逻辑。这是 Optuna 发挥价值的最佳位置。

  

高风险场景：项目尚未建立 Walk-Forward 框架，或试图用 Optuna 直接在全样本上寻找最优参数。实践中已有不少团队踩过这个坑——把 Optuna 当作独立解决方案，在全历史数据上跑 study，结果参数过度拟合全样本噪声，样本外表现惨淡。这种用法不仅无益，反而会因 Optuna 的搜索能力更强而加剧过拟合。

  

业界共识逐渐清晰：真正的稳健性来自更长的训练周期、更稳定的参数平原，以及更严格的样本外验证。Optuna 是更好的"找参数"工具，但 Walk-Forward 才是"验真假"的框架。用 Optuna 替代网格搜索来做滚动选参，可以提升效率、扩大搜索空间，但无法解决短训练窗内参数优化拟合噪声的核心问题。

  

因此，实践中的推荐路径是：在现有 Walk-Forward 框架内逐步引入 Optuna，而非将其作为独立解决方案。 工具与框架各司其职，才能让超参数优化真正服务于策略的样本外稳健性。