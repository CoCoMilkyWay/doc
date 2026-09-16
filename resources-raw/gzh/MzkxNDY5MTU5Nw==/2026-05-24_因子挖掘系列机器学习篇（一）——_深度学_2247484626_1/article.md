# 因子挖掘系列机器学习篇（一）—— 深度学习在因子挖掘中的应用

蝴蝶量化 随率而动的因子工厂 2026-05-24 22:54 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484626&idx=1&sn=c974e6aa5d13d3f31d3fdadaa0c8fe43&chksm=c008d10029081f7166bb2a4ea9ec2b40e88fa1fa10eb4b3b90128faeeaf4af2ef31c40d04873#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484626&idx=1&sn=c974e6aa5d13d3f31d3fdadaa0c8fe43&chksm=c008d10029081f7166bb2a4ea9ec2b40e88fa1fa10eb4b3b90128faeeaf4af2ef31c40d04873#rd)

## 技术背景

作为一个长期关注金融市场的小伙伴，你是不是经常看到各种关于什么智投、什么LLM大模型交易策略、什么机器学习策略等等各种高大上、根本听不懂的名词。乍一看觉得很厉害、高大上的感觉，笔者了解了不少的类似的产品、项目，其实，很多都是包装的后的东西，加上自媒体为了流量夸大宣传，导致了很多人对这些所谓的智能铲平产生了严重的误解：认为它们无所不能，能够精准的判断每一个机会。

笔者认为市面上你能够买到的任何交易策略、智投软件都**不完善**。并不是说他一无是处，对于一部分人来讲，这些产品如果能够正确的使用是能够提高一些东西的，比如：胜率45%提高到55%，盈亏比0.8提高到2.0等等，但是如果你想靠一个产品、甚至一个策略达到稳定的大幅盈利，趁早杜绝这种不切实际的想法。

交易本身是一个很难的事情，需要很多的环节相互配合：研究、交易、风控等等一系列工作。所以，一个人想坚持的做好每一步的工作很艰难，那么目前的这个量化产品、工具，就是我们的好帮手。当然，这同时也极大的考验了我们的执行力、信任度。

上面回答了很多初学者的一个问题：量化到底能不能赚钱？

言归正传，本文的主要内容：**机器学习：深度学习在因子挖掘中的应用。** 给出了一整套的实现方案代码等等。主要的核心内容为：**使用强化学习(RL)结合大语言模型(LLM)来自动挖掘量化因子**

**当然，整篇文章的思路来源华泰的券商研报，有兴趣的可以自己去下载，或者私我。**

## 项目简介

随着大模型的不断发展，机器学习、大模型成了量化交易中一个不可或缺的部分。它们的优点、缺点我这儿就不多说，可以去查一下deepseek，那里比我讲的清楚。

本文提出并验证了一个结合大语言模型和强化学习的自动化因子挖掘框架。其核心思想是：

-   RL负责探索与优化：将因子表达式的构造过程建模为一个序列决策问题，使用强化学习（特别是 MaskablePPO 算法）在巨大的表达式空间中搜索具有预测能力的Alpha因子。
    
-   LLM负责知识与逻辑注入：利用大模型的金融领域知识和推理能力，为RL提供高质量的初始因子池（“热启动”）并定期注入新因子，以解决RL单独使用时容易生成无逻辑、结构简单或陷入局部最优的问题。
    

### 1\. 关键算法简介

1.  **Token化因子表达式**：将因子公式转换为Token序列（如BEG、Low、Rank、TsRank等）
    
2.  **强化学习环境**：把因子挖掘建模为MDP问题，Agent逐步生成Token序列
    
3.  **奖励机制**：使用IC、RankIC、ICIR等指标作为奖励信号
    
4.  **PPO算法训练**：使用MaskablePPO算法训练RL模型
    
5.  **AlphaPool机制**：维护一个高质量因子池，提供更好的奖励信号
    
6.  **大模型辅助**：利用LLM提供先验知识和语义理解能力
    

### 2.技术架构

```
数据层：股票行情数据（OHLCV + VWAP）    ↓因子表达式层：Token序列表示    ↓强化学习层：PPO算法 + LSTM/Transformer网络    ↓AlphaPool层：因子池管理与奖励塑形    ↓评估层：IC/RankIC/ICIR计算    ↓回测层：多空组合收益计算
```

### 3.项目结构

```
.├── configs/              # 配置文件├── data/                 # 数据目录├── src/                  # 源代码│   ├── data/            # 数据处理│   ├── factor/          # 因子计算│   ├── env/             # RL环境│   ├── models/          # 模型│   ├── training/        # 训练│   ├── llm/             # 大模型│   ├── backtest/        # 回测│   └── visualization/   # 可视化├── scripts/             # 脚本├── notebooks/           # Jupyter笔记本└── tests/               # 测试
```

## 复现算法与改进

### 1\. Token转化方法

**1.1 因子表达式的Token化序列建模**

-   **目标**：将数学表达式转化为RL可以处理的离散序列。
    
-   **方法**：采用**逆波兰表达式**。
    

-   **优势**：序列化简单，无需括号定义运算顺序，适合用PPO等算法进行序列生成。
    
-   **劣势**：只能在序列结束后才能解析和执行，无法在生成过程中进行实时检查，会产生大量无效表达式。
    

-   **示例**：表达式 `(close - open)` 被转化为Token序列 `[BEG, close, open, Sub, SEP]`。
    
-   **Token集构成**：
    

-   **起止符**：`BEG`（开始）， `SEP`（结束）。
    
-   **字段**：`OPEN`, `HIGH`, `LOW`, `CLOSE`, `VOLUME`, `VWAP`。
    
-   **常量**：`-30.0` 到 `30.0` 的离散值。
    
-   **一元/二元/滚动/配对算子**：`Abs`, `Log`, `Add`, `Sub`, `Mul`, `Div`, `Mean`, `Sum`, `Std`, `Corr`, `Cov` 等。
    

**1.2 强化学习作为序列决策问题**

-   **状态**：当前已生成的Token序列
    
-   **动作**：从预定义的Token集中选择下一个符号.
    
-   **状态转移**：将选中的Token追加到当前序列末尾，形成新状态。
    
-   **环境**：`AlphaPool`，它负责评估一个完整的因子表达式（以`SEP`结尾）。
    
-   **奖励**：基于因子在验证集上的预测能力（如IC， ICIR，或对组合的贡献）计算得出。这是驱动RL学习的核心信号。
    

### 2、算法详解

**2.1 强化学习算法：MaskablePPO**

-   **基础**：PPO（Proximal Policy Optimization），一种基于Actor-Critic架构的策略梯度算法。它以稳定的更新和良好的性能著称，通过裁剪（Clipping）目标函数来限制新旧策略的差异，避免训练崩溃。
    
-   **核心改进：动作掩码**：MaskablePPO在每一步决策时，会根据当前状态动态屏蔽无效或非法的Token。例如：
    

-   当表达式已完成时，`SEP` 是唯一合法动作。
    
-   避免生成 `close + volume` 这种无意义的表达式。
    
-   保证表达式在RPN形式下的维度匹配，例:二元操作符前栈中至少有两个元素。
    
-   **作用**：极大地减少了无效搜索空间，提高了因子生成效率和有效性。
    

### 3、关键算法流程

**3.1 训练流程**

1.  **初始化**：LLM生成N个初始因子，填充 AlphaPool。
    
2.  **重置环境**：RL Agent初始化。
    
3.  **生成因子**：
    

-   Agent接收当前状态 （通常是 **BEG** token）。
    
-   Agent根据策略 π 并结合动作掩码，采样一个动作 。
    
-   将  追加到序列，更新状态 。
    
-   重复此过程，直到Agent输出  Token，得到一个完整的因子表达式。
    

5.  **评估与奖励**：
    

-   将完整的因子表达式送入 AlphaPool 环境。
    
-   AlphaPool 计算该因子在训练集上的性能指标（如IC）。
    
-   AlphaPool 根据该因子是否有效、是否重复、是否能提升组合性能等因素，按照预设的奖励表，返回一个标量奖励 。
    

7.  **存储经验**：将轨迹  存储到经验缓存中。
    
8.  **更新策略**：当收集到足够多的经验，，使用MaskablePPO算法更新Agent的策略网络和价值网络。
    
9.  **LLM定期注入**：每隔 llm\_every\_n\_steps步，调用LLM生成新因子，更新 AlphaPool。
    
10.  **循环**：重复步骤3-7，直到达到总训练步数。
     

**3.2 因子组合权重优化**

-   **目标**：AlphaPool 中的因子并非独立使用，而是通过加权合成一个最终的多因子Alpha。权重的优化目标直接影响奖励函数，这个算法我们在之前的
    
-   **两种Pool类型**：
    

1.  **MSE Pool**：使用**IC**作为评估指标。优化目标是最大化因子组合的IC值。
    
2.  **MeanStd Pool**：使用**ICIR**作为评估指标。优化目标是最大化因子组合的ICIR。
    

-   **权重优化过程**：
    

-   当有新因子成功加入 AlphaPool 时，会基于池内所有因子，重新训练一个权重模型，这里的方法可以是简单的线性回归或带约束的优化器。
    
-   该模型以最大化组合IC/ICIR为目标，学习每个因子的最优权重。
    
-   训练完成后，当前池子的最佳评估指标best\_obj随之更新。
    
-   这个 best\_obj 被用作奖励信号的一部分，成功入池的因子获得的奖励是 new\_obj。
    

### 4、 模型参数设置

-   **RL模型**：使用 **stable\_baselines3\_contrib** 库中的 **MaskablePPO**。
    
-   **特征提取器**：我们对比了LSTM和Transformer。Transformer效果更稳定。
    
-   **关键超参数**：
    

-   总训练步数：10000。
    
-   Episode步数：
    
-   Batch大小：
    
-   折扣因子：
    
-   GAE参数：λ ，用于优势函数估计。
    
-   策略裁剪阈值：ε
    
-   熵系数：
    
-   AlphaPool容量：
    
-   因子最大长度：
    

## 关键代码

由于空间有限，以及后续的计划，这里代码仅仅展示机器学习部分，**代码借助了claude code编写，笔者审查、修改，全部代码跑通。**

```
"""训练脚本功能：1. 加载配置2. 准备数据3. 创建环境4. 训练模型5. 评估和保存创建日期：2026-05-20修改日期：2026-05-20"""import sysimport osimport yamlimport argparseimport numpy as npfrom pathlib import Path# 添加项目根目录到路径project_root = Path(__file__).parent.parentsys.path.insert(0, str(project_root))from src.env.token_vocab import TokenVocabularyfrom src.env.factor_env import FactorMiningEnvfrom src.env.alpha_pool import create_alpha_poolfrom src.data.data_loader import StockDataLoaderfrom src.training.custom_callbacks import (    DetailedLoggingCallback,    AlphaPoolMonitorCallback,    EarlyStoppingCallback)def load_config(config_path: str) -> dict:    """加载配置文件"""    with open(config_path, 'r', encoding='utf-8') as f:        config = yaml.safe_load(f)    return configdef set_seed(seed: int):    """设置随机种子"""    np.random.seed(seed)    try:        import torch        torch.manual_seed(seed)        if torch.cuda.is_available():            torch.cuda.manual_seed(seed)    except ImportError:        passdef prepare_data(config: dict):    """准备数据"""    print("\n" + "="*60)    print("准备数据")    print("="*60)    loader = StockDataLoader(data_dir=config['data']['data_dir'])    # 加载数据    print(f"\n加载数据...")    # 加载股票列表    stock_list_file = config['data'].get('stock_list_file')    stock_codes = None    if stock_list_file:        with open(stock_list_file, 'r') as f:            stock_codes = [line.strip() for line in f if line.strip()]        print(f"从文件加载 {len(stock_codes)} 只股票")    data = loader.load_ohlcv_data(        stock_codes=stock_codes,        start_date=config['data'].get('start_date', '2010-01-01'),        end_date=config['data'].get('end_date', '2025-11-28')    )    # 限制股票数量（如果配置了）    max_stocks = config['data'].get('max_stocks')    if max_stocks is not None:        print(f"限制股票数量为: {max_stocks}")        for field in data:            data[field] = data[field].iloc[:, :max_stocks]    # 清洗数据    print(f"清洗数据...")    data = loader.clean_data(data)    # 计算收益率    print(f"计算收益率...")    returns = loader.calculate_returns(data['CLOSE'], periods=1)    returns = returns.shift(-1)  # 未来1日收益率    # 划分数据集    print(f"划分数据集...")    train_end = config['data'].get('train_end', '2018-12-31')    valid_end = config['data'].get('valid_end', '2020-12-31')    # split_data返回的是元组: (train_data, valid_data, test_data)    train_data, valid_data, test_data = loader.split_data(        data,        train_end=train_end,        valid_end=valid_end    )    # 划分收益率    train_returns = returns[returns.index <= train_end]    valid_returns = returns[(returns.index > train_end) &                           (returns.index <= valid_end)]    test_returns = returns[returns.index > valid_end]    return {        'train': (train_data, train_returns),        'valid': (valid_data, valid_returns),        'test': (test_data, test_returns)    }def create_env(data, returns, vocab, config, alpha_pool=None):    """创建环境"""    env = FactorMiningEnv(        stock_data=data,        returns_data=returns,        vocab=vocab,        max_length=config['env']['max_expr_length'],        reward_type=config['env']['reward_type'],        invalid_penalty=config['env']['invalid_penalty']    )    return envdef train(config: dict):    """训练模型"""    print("\n" + "="*60)    print(f"开始训练: {config['experiment_name']}")    print("="*60)    # 设置随机种子    set_seed(config['seed'])    # 准备数据    datasets = prepare_data(config)    train_data, train_returns = datasets['train']    valid_data, valid_returns = datasets['valid']    # 创建Token词汇表    print("\n创建Token词汇表...")    vocab = TokenVocabulary()    print(f"词汇表大小: {vocab.vocab_size}")    # 创建AlphaPool    alpha_pool = None    if config['alpha_pool']['enabled']:        print("\n创建AlphaPool...")        alpha_pool = create_alpha_pool(            pool_type=config['alpha_pool']['pool_type'],            capacity=config['alpha_pool']['capacity'],            correlation_threshold=config['alpha_pool']['correlation_threshold']        )        print(f"AlphaPool类型: {config['alpha_pool']['pool_type']}")        print(f"容量: {config['alpha_pool']['capacity']}")    # 创建环境    print("\n创建训练环境...")    train_env = create_env(train_data, train_returns, vocab, config, alpha_pool)    print(f"观察空间: {train_env.observation_space}")    print(f"动作空间: {train_env.action_space}")    print("\n创建验证环境...")    valid_env = create_env(valid_data, valid_returns, vocab, config, None)    # 测试环境    print("\n测试环境...")    obs = train_env.reset()    print(f"初始观察: {obs[:5]}")    # 尝试导入stable-baselines3    try:        from sb3_contrib import MaskablePPO        from sb3_contrib.common.wrappers import ActionMasker        from stable_baselines3.common.callbacks import EvalCallback, CheckpointCallback        from stable_baselines3.common.monitor import Monitor        has_sb3 = True    except ImportError:        has_sb3 = False        print("\n警告: 未安装stable-baselines3，只运行环境测试")    if not has_sb3:        # 运行几个随机episode        print("\n运行测试episode...")        for episode in range(3):            obs = train_env.reset()            done = False            total_reward = 0            steps = 0            while not done and steps < 20:                # 随机选择动作（使用动作掩码）                mask = train_env.get_action_mask()                valid_actions = np.where(mask)[0]                action = np.random.choice(valid_actions)                obs, reward, done, info = train_env.step(action)                total_reward += reward                steps += 1            print(f"  Episode {episode+1}: 步数={steps}, 总奖励={total_reward:.4f}, "                  f"有效={info.get('valid', False)}")        print("\n" + "="*60)        print("训练准备完成！")        print("="*60)        print("\n注意：完整的PPO训练需要安装stable-baselines3")        print("运行: pip install stable-baselines3 sb3-contrib")        return    # 包装环境以支持动作掩码    print("\n包装环境...")    def mask_fn(env):        return env.get_action_mask()    train_env = ActionMasker(train_env, mask_fn)    train_env = Monitor(train_env)    valid_env = ActionMasker(valid_env, mask_fn)    valid_env = Monitor(valid_env)    # 创建模型    print("\n创建PPO模型...")    tensorboard_log = config['logging']['log_dir'] if config['logging'].get('tensorboard', False) else None    model = MaskablePPO(        "MlpPolicy",        train_env,        learning_rate=config['ppo']['learning_rate'],        n_steps=config['ppo']['n_steps'],        batch_size=config['ppo']['batch_size'],        n_epochs=config['ppo']['n_epochs'],        gamma=config['ppo']['gamma'],        gae_lambda=config['ppo']['gae_lambda'],        clip_range=config['ppo']['clip_range'],        ent_coef=config['ppo']['ent_coef'],        vf_coef=config['ppo']['vf_coef'],        max_grad_norm=config['ppo']['max_grad_norm'],        verbose=1,        tensorboard_log=tensorboard_log    )    # 创建回调    print("\n设置训练回调...")    # 每10000步保存一次checkpoint    save_freq = 10000    checkpoint_callback = CheckpointCallback(        save_freq=save_freq,        save_path=config['checkpoint']['save_dir'],        name_prefix=config['experiment_name']    )    eval_callback = EvalCallback(        valid_env,        best_model_save_path=config['checkpoint']['save_dir'],        log_path=config['logging']['log_dir'],        eval_freq=10000,        n_eval_episodes=config['evaluation']['n_eval_episodes'],        deterministic=True,        render=False    )    # 添加自定义回调    detailed_logging_callback = DetailedLoggingCallback(        log_dir=config['logging']['log_dir'],        log_freq=1000,        verbose=1    )    alpha_pool_monitor_callback = AlphaPoolMonitorCallback(        log_dir=config['logging']['log_dir'],        log_freq=5000,        verbose=1    )    early_stopping_callback = EarlyStoppingCallback(        patience=50,        min_delta=0.001,        verbose=1    )    # 组合所有回调    callbacks = [        checkpoint_callback,        eval_callback,        detailed_logging_callback,        alpha_pool_monitor_callback,        early_stopping_callback    ]    # 开始训练    print("\n" + "="*60)    print("开始训练！")    print("="*60)    print(f"总步数: {config['training']['total_timesteps']}")    print(f"评估频率: 每 10000 步")    print(f"日志目录: {config['logging']['log_dir']}")    print(f"Checkpoint保存: {config['checkpoint']['save_dir']}")    print()    model.learn(        total_timesteps=config['training']['total_timesteps'],        callback=callbacks,        progress_bar=True    )    # 保存最终模型    final_model_path = os.path.join(        config['logging']['checkpoint_dir'],        f"{config['experiment']['name']}_final"    )    model.save(final_model_path)    print(f"\n最终模型已保存: {final_model_path}")    # 打印AlphaPool统计    print("\n" + "="*60)    print("AlphaPool统计")    print("="*60)    print(f"池大小: {len(alpha_pool.factors)}/{alpha_pool.pool_size}")    if alpha_pool.factors:        print("\n最佳因子:")        for i, (tokens, ic_mean, ic_std) in enumerate(alpha_pool.factors[:5], 1):            print(f"  {i}. IC均值={ic_mean:.4f}, IC标准差={ic_std:.4f}")            print(f"     Token序列: {' '.join(tokens)}")    print("\n训练完成！")def main():    parser = argparse.ArgumentParser(description='训练因子挖掘RL模型')    parser.add_argument(        '--config',        type=str,        default='configs/train_config.yaml',        help='配置文件路径'    )    args = parser.parse_args()    # 加载配置    config = load_config(args.config)    # 训练    train(config)if __name__ == '__main__':    main()
```

## 结果总结

### 图表

**1、训练过程因子数量**

![](assets/001.png)

**2、因子的特征分析**

![](assets/002.png)

**3、分组收益**

![](assets/003.png)当然，我并没有去微调这个模型，为了方便起见，仅仅在hs300的成分股上做了测试，所以，结果是片面的。

### 关键结论

-   **RL单独有效**：在无大模型增强时，RL（Transformer模型，10个因子）已能取得沪深300年化超额。
    
-   **大模型增益显著**：引入LLM后，沪深300年化超额提升至17.85%，信息比率1.50。中证500策略年化超额由7.17%提升至9.78%。
    
-   **Transformer vs. LSTM**：在沪深300策略中，Transformer效果优于LSTM，且回撤更小。
    
-   **因子数量**：当因子池容量为10时，效果最优。过多因子会引入噪音，导致策略表现下降。
    
-   **复杂度约束**：将因子表达式长度限制在 ， 时，年化超额收益最高，但约束过严或过松都会损害性能。
    
-   **过拟合风险**：训练步数超过10万步后，测试集超额收益显著下降，表明模型可能开始记忆训练数据的噪声。
    

**总的来说，这篇文章中的算法，是值得学习的，至于能否用于实战，我认为依然是仁者见仁，况且本公众号的目的就是算法研究与策略研究。**

### 总结

本文提供了一个完整且先进的自动化因子挖掘框架。其核心洞见在于结合RL的**强大搜索能力**与LLM的**知识推理能力**，有效克服了单纯使用遗传规划或RL的局限性。复现该框架的关键在于：1）正确实现RPN的Token化与动作掩码；2）精心设计基于因子组合表现的分层奖励函数；3）巧妙地将LLM作为“知识外脑”集成到RL训练循环中。

**最后，再一次强调，重要的是方法、方法、方法。当然后续我们会推出这类产品的合集，让小伙伴们能够简单的使用这些方法。**