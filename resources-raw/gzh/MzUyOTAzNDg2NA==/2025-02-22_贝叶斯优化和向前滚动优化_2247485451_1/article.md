# 贝叶斯优化和向前滚动优化

FinTechHi FinTechHi 2025-02-22 08:36 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485451&idx=1&sn=14389057dc40fc070112044ac836a0b8&chksm=fb31ed2dcb9ffc25dcefba2b6f74ba672ba4574995a0cff68b1ade75e8c890f7a4f1a30db9c9#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485451&idx=1&sn=14389057dc40fc070112044ac836a0b8&chksm=fb31ed2dcb9ffc25dcefba2b6f74ba672ba4574995a0cff68b1ade75e8c890f7a4f1a30db9c9#rd)

本篇文章是在 [动态止损过程的参数优化](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485355&idx=1&sn=1ac94ae08e693d23ba9b05d729014234&scene=21#wechat_redirect) 文章基础上，结合deepseek详细说明下贝叶斯优化和向前滚动优化的基础概念。以便大家能更好的理解，然后举一反三使用其他的同类方式。

###   
**1.贝叶斯优化**  

通过贝叶斯优化寻找某个目标函数的最优参数。  
交易中它可以帮忙帮助调整算法策略。其核心是通过概率模型（如高斯过程）近似目标函数，并平衡**探索新参数**与**利用已知好参数**的两种策略。

####   
**优化过程**  

1.  **定义目标函数**
    

-   目标函数  是需优化的函数（如策略收益率）。
    

3.  **选择代理模型**
    

-   常用高斯过程模型，包含均值函数  和协方差函数 。
    

5.  **获取函数（Acquisition Function）**
    

-   **期望提升（Expected Improvement, EI）**
    
-   **上置信界（Upper Confidence Bound, UCB）**
    

-   指导选择下一个采样点，常用方法包括：
    
-   公式示例（EI）：  
    其中  是当前最佳观测点。
    

8.  **迭代优化**
    

-   在选点处评估目标函数 -> 更新代理模型 -> 重复直至收敛。
    

####   
**优势**  

-   **高效性**：比网格搜索或随机搜索需要更少的评估次数。
    
-   **适应性**：处理复杂、有噪声或计算成本高的函数。
    
-   **灵活性**：可注入先验知识加速优化过程。
    

###   

### **2.向前滚动优化（Walk-Forward Optimization）**  

通过多个滚动窗口评估和优化策略，防止对历史数据的过拟合。  
适用于动态止损设置，适应市场变化。核心步骤：

####   
**流程**  

1.  **数据分段**
    

-   将历史数据划分为训练集和测试集，窗口需重叠以确保连续性。
    
-   示例数据分段：
    
      
    `[训练窗口1] -> [测试窗口1]     [训练窗口2] -> [测试窗口2]     ...`  
    

3.  **训练集优化**
    

-   在训练集上优化策略参数（如最大化收益率）。
    

5.  **测试集验证**
    

-   将优化后的参数应用于后续测试集，记录表现。
    

7.  **滚动迭代**
    

-   向前移动窗口，重复优化和验证，覆盖所有数据周期。
    

####   
**优势**  

-   **降低过拟合**：使用样本外验证。
    
-   **动态适应**：参数随市场变化更新。
    
-   **提升鲁棒性**：确保策略在不同时段表现一致。
    

### 

### **3.动态止损方法**  

结合技术指标与向前滚动优化设置动态止损。

####   
**步骤**  

1.  **计算技术指标**
    

-   使用ATR（平均真实波幅）、EMA（指数移动平均）、MACD、RSI等生成交易信号。
    

3.  **设置止损**
    

-   止损值为ATR的倍数，如：  
    止损
    
-   通过贝叶斯优化选择最佳倍数 ( k ) 和其他参数。
    

5.  **向前滚动验证**
    

-   验证参数在不同市场阶段的表现。
    

7.  **最小持仓时间**
    

-   强制持仓一定时间（如1小时），减少频繁交易。
    

###   
**代码实现与注释**  

  
`def optimize_parameters(data, min_atr_multiplier, min_holding_period):       """       使用贝叶斯优化寻找最佳ATR乘数和窗口参数       :param data: 历史价格数据       :param min_atr_multiplier: ATR乘数的最小值（优化下限）       :param min_holding_period: 最小持仓周期（避免频繁交易）       :return: 最优参数（ATR乘数、ATR窗口）       """              def objective(atr_multiplier, atr_window):           """           目标函数：通过回测策略计算收益率           :param atr_multiplier: ATR乘数（动态止损倍数）           :param atr_window: ATR计算窗口（需为整数）           :return: 策略收益率（需最大化）           """           # 将atr_window四舍五入为整数（贝叶斯优化输出可能是浮点数）           atr_window = int(round(atr_window))           return backtest_strategy(               atr_multiplier=atr_multiplier,               atr_window=atr_window,               data=data,               min_holding_period=min_holding_period           )              # 初始化贝叶斯优化器       optimizer = BayesianOptimization(           f=objective,           pbounds={               "atr_multiplier": (min_atr_multiplier, 3),  # ATR乘数范围（下限由用户指定，上限为3）               "atr_window": (5, 60)                       # ATR窗口范围（5到60天）           },           random_state=42                                  # 固定随机种子确保结果可复现       )              # 执行优化：10次随机初始化 + 100次迭代       optimizer.maximize(init_points=10, n_iter=100)              # 提取最优参数并确保atr_window为整数       best_params = optimizer.max['params']       best_params['atr_window'] = int(round(best_params['atr_window']))              return best_params   `

###   

### **4.详细讲解**  

1.  **贝叶斯优化流程**
    

-   **代理模型**：高斯过程模拟参数与收益率的映射关系。
    
-   **获取函数**：平衡探索（尝试新参数）与利用（优化已知好参数）。
    
-   **参数调整**：每次迭代选择使获取函数最大的参数组合进行回测。
    

3.  **向前滚动优化实战**
    

-   训练集：2020年1月-2020年6月
    
-   测试集：2020年7月-2020年12月
    
-   滚动步长：6个月，覆盖全部数据。
    

-   **数据分段示例**：
    
-   **避免过拟合**：测试集表现决定参数是否有效。
    

6.  **动态止损实现**
    

-   **ATR计算**：窗口为60天时，计算过去60日的平均波幅。
    
-   **止损逻辑**：若价格下跌超过 ( 2 \\times \\text{ATR} )，则触发止损。
    

8.  **代码关键点**
    

-   **整数处理**：`atr_window`需四舍五入，避免传入非整数导致技术指标计算错误。
    
-   **参数范围**：`atr_multiplier`下限由策略需求决定，上限设为3以防止过度激进。
    

通过结合贝叶斯优化和向前滚动验证，策略能在动态市场中自适应调整，同时避免过拟合，提升实盘表现。