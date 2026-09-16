# Qlib学习分析（八）：量化交易中的强化学习

FinTechHi FinTechHi 2023-08-01 20:22 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483875&idx=1&sn=22f52131d9c2044ca8669de92815e54e&chksm=fb21c338e0775cc566b6340e643db860ca632f1202401f57cc23037a84f3c30d4cd0492c0bbd#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483875&idx=1&sn=22f52131d9c2044ca8669de92815e54e&chksm=fb21c338e0775cc566b6340e643db860ca632f1202401f57cc23037a84f3c30d4cd0492c0bbd#rd)

> 说明：  
> 1.大部分内容来自对官方文档的解读，要理解这篇文章需要自己掌握强化学习的一些基本概念。  
> 2.虽然对于A股市场而言，很难训练一个智能体以便适合最新的市场（环境），但Qlib为我们量化投资提供了一个引入强化学习的基础设施，也提供了基本的解题思路，在论文：Learning Multi-Agent Intention-Aware Communication for Optimal Multi-Order Execution in Finance也给出了一个“先知”策略的详细说明，对于需要的同学，所以不管从支持机器学习的量化平台设计、还是量化投资策略层面，都值得深入研究和学习。

## 1、什么是强化学习

不同于分类任务和回归任务等监督学习任务。机器学习的另一个重要范式是强化学习（RL）， 它试图在马尔可夫决策过程（MDP）等一些假设下通过直接与环境交互来优化累积数值奖励信号。RL 系统由四个元素组成：

> 1） Agent：代理  
> 2） Environment：代理与之交互的环境  
> 3） Action：代理遵循的策略以对环境采取行动  
> 4） Reward：从环境到代理的奖励信号。

一般来说，智能体可以感知和解释其环境，通过奖励采取行动和学习，以寻求长期和最大的整体奖励，以实现最优解决方案。

![](assets/001.png)

RL系统构成

RL试图通过反复试验来学习产生动作。 通过对行动进行抽样，然后观察哪一个会导致我们期望的结果，从而获得策略以生成最佳行动。

与监督学习相比，RL不是从标签上学习的，而是从称为奖励的时间延迟标签中学习的。 这个标量值让我们知道当前的结果是好是坏。 总之，RL的目标是采取行动，使奖励最大化。

## 2、QlibRL强化学习工具包

Qlib强化学习工具包（QlibRL）是一个用于量化投资的强化学习平台，它为在Qlib中实现RL算法提供支持。

QlibRL包含一套完整的组件，涵盖RL管道的整个生命周期，包括构建市场模拟器，塑造状态和行动，训练策略（策略）以及在模拟环境中进行回溯测试策略。

QlibRL基本上是在tianshou(Get Started with Jupyter Notebook)和Gym框架(gymnasium (farama.org))的支持下实现的(Gymnasium是OpenAI的Gym库的一个维护分支。Gymnasium 接口简单、pythonic，能够表示一般的 RL 问题)。QlibRL 的高级结构如下所示：

![](assets/002.png)

在这里，我们简要介绍一下图中的每个组件。

1）EnvWrapper

EnvWrapper是模拟环境的完整封装。它接收来自外部（策略/机制/代理）的动作，模拟市场中的变化，然后返回奖励和更新后的状态，从而形成一个交互循环。在QlibRL中，EnvWrapper是gym.Env的子类，因此它实现了gym.Env的所有必要接口。任何接受gym.Env的类或流水线也应该接受EnvWrapper。开发者不需要自己实现EnvWrapper来构建自己的环境。相反，他们只需要实现EnvWrapper的4个组件：

a)Simulator

> 模拟器是负责环境模拟的核心组件，开发人员可以根据自己的需求以任何方式实现与环境模拟直接相关的所有逻辑。在QlibRL中，已经有两种用于单资产交易的模拟器实现：  
> 1）基于Qlib的回测工具包构建的模拟器，考虑了许多实际交易细节，但速度较慢;(SingleAssetOrderExecution)  
> 2）基于简化的交易模拟器构建的模拟器，忽略了许多细节（如交易限制、舍入），但速度较快(SimpleSingleAssetOrderExecution)。

其中：SingleAssetOrderExecution代码路径为：qlib\\rl\\order\_execution\\simulator\_qlib.py，代码如下：

```
# Copyright (c) Microsoft Corporation.# Licensed under the MIT License.from __future__ import annotationsfrom typing import Generator, List, Optionalimport pandas as pdfrom qlib.backtest import collect_data_loop, get_strategy_executorfrom qlib.backtest.decision import BaseTradeDecision, Order, TradeRangeByTimefrom qlib.backtest.executor import NestedExecutorfrom qlib.rl.data.integration import init_qlibfrom qlib.rl.simulator import Simulatorfrom .state import SAOEStatefrom .strategy import SAOEStateAdapter, SAOEStrategyclass SingleAssetOrderExecution(Simulator[Order, SAOEState, float]):    """Single-asset order execution (SAOE) simulator which is implemented based on Qlib backtest tools.    Parameters    ----------    order        The seed to start an SAOE simulator is an order.    executor_config        Executor configuration    exchange_config        Exchange configuration    qlib_config        Configuration used to initialize Qlib. If it is None, Qlib will not be initialized.    cash_limit:        Cash limit.    """    def __init__(        self,        order: Order,        executor_config: dict,        exchange_config: dict,        qlib_config: dict | None = None,        cash_limit: float | None = None,    ) -> None:        super().__init__(initial=order)        assert order.start_time.date() == order.end_time.date(), "Start date and end date must be the same."        strategy_config = {            "class": "SingleOrderStrategy",            "module_path": "qlib.rl.strategy.single_order",            "kwargs": {                "order": order,                "trade_range": TradeRangeByTime(order.start_time.time(), order.end_time.time()),            },        }        self._collect_data_loop: Optional[Generator] = None        self.reset(order, strategy_config, executor_config, exchange_config, qlib_config, cash_limit)    def reset(        self,        order: Order,        strategy_config: dict,        executor_config: dict,        exchange_config: dict,        qlib_config: dict | None = None,        cash_limit: Optional[float] = None,    ) -> None:        if qlib_config is not None:            init_qlib(qlib_config)        strategy, self._executor = get_strategy_executor(            start_time=order.date,            end_time=order.date + pd.DateOffset(1),            strategy=strategy_config,            executor=executor_config,            benchmark=order.stock_id,            account=cash_limit if cash_limit is not None else int(1e12),            exchange_kwargs=exchange_config,            pos_type="Position" if cash_limit is not None else "InfPosition",        )        assert isinstance(self._executor, NestedExecutor)        self.report_dict: dict = {}        self.decisions: List[BaseTradeDecision] = []        self._collect_data_loop = collect_data_loop(            start_time=order.date,            end_time=order.date,            trade_strategy=strategy,            trade_executor=self._executor,            return_value=self.report_dict,        )        assert isinstance(self._collect_data_loop, Generator)        self.step(action=None)        self._order = order    def _get_adapter(self) -> SAOEStateAdapter:        return self._last_yielded_saoe_strategy.adapter_dict[self._order.key_by_day]    @property    def twap_price(self) -> float:        return self._get_adapter().twap_price    def _iter_strategy(self, action: Optional[float] = None) -> SAOEStrategy:        """Iterate the _collect_data_loop until we get the next yield SAOEStrategy."""        assert self._collect_data_loop is not None        obj = next(self._collect_data_loop) if action is None else self._collect_data_loop.send(action)        while not isinstance(obj, SAOEStrategy):            if isinstance(obj, BaseTradeDecision):                self.decisions.append(obj)            obj = next(self._collect_data_loop) if action is None else self._collect_data_loop.send(action)        assert isinstance(obj, SAOEStrategy)        return obj    def step(self, action: Optional[float]) -> None:        """Execute one step or SAOE.        Parameters        ----------        action (float):            The amount you wish to deal. The simulator doesn't guarantee all the amount to be successfully dealt.        """        assert not self.done(), "Simulator has already done!"        try:            self._last_yielded_saoe_strategy = self._iter_strategy(action=action)        except StopIteration:            pass        assert self._executor is not None    def get_state(self) -> SAOEState:        return self._get_adapter().saoe_state    def done(self) -> bool:        return self._executor.finished()
```

SimpleSingleAssetOrderExecution的代码路径：qlib\\rl\\order\_execution\\simulator\_simple.py：

```
# Copyright (c) Microsoft Corporation.# Licensed under the MIT License.from __future__ import annotationsfrom typing import Any, cast, List, Optionalimport numpy as npimport pandas as pdfrom pathlib import Pathfrom qlib.backtest.decision import Order, OrderDirfrom qlib.constant import EPS, EPS_T, float_or_ndarrayfrom qlib.rl.data.base import BaseIntradayBacktestDatafrom qlib.rl.data.native import DataframeIntradayBacktestData, load_handler_intraday_processed_datafrom qlib.rl.data.pickle_styled import load_simple_intraday_backtest_datafrom qlib.rl.simulator import Simulatorfrom qlib.rl.utils import LogLevelfrom .state import SAOEMetrics, SAOEState__all__ = ["SingleAssetOrderExecutionSimple"]class SingleAssetOrderExecutionSimple(Simulator[Order, SAOEState, float]):    """Single-asset order execution (SAOE) simulator.    As there's no "calendar" in the simple simulator, ticks are used to trade.    A tick is a record (a line) in the pickle-styled data file.    Each tick is considered as a individual trading opportunity.    If such fine granularity is not needed, use ``ticks_per_step`` to    lengthen the ticks for each step.    In each step, the traded amount are "equally" separated to each tick,    then bounded by volume maximum execution volume (i.e., ``vol_threshold``),    and if it's the last step, try to ensure all the amount to be executed.    Parameters    ----------    order        The seed to start an SAOE simulator is an order.    data_dir        Path to load backtest data.    feature_columns_today        Columns of today's feature.    feature_columns_yesterday        Columns of yesterday's feature.    data_granularity        Number of ticks between consecutive data entries.    ticks_per_step        How many ticks per step.    vol_threshold        Maximum execution volume (divided by market execution volume).    """    history_exec: pd.DataFrame    """All execution history at every possible time ticks. See :class:`SAOEMetrics` for available columns.    Index is ``datetime``.    """    history_steps: pd.DataFrame    """Positions at each step. The position before first step is also recorded.    See :class:`SAOEMetrics` for available columns.    Index is ``datetime``, which is the **starting** time of each step."""    metrics: Optional[SAOEMetrics]    """Metrics. Only available when done."""    twap_price: float    """This price is used to compute price advantage.    It"s defined as the average price in the period from order"s start time to end time."""    ticks_index: pd.DatetimeIndex    """All available ticks for the day (not restricted to order)."""    ticks_for_order: pd.DatetimeIndex    """Ticks that is available for trading (sliced by order)."""    def __init__(        self,        order: Order,        data_dir: Path,        feature_columns_today: List[str] = [],        feature_columns_yesterday: List[str] = [],        data_granularity: int = 1,        ticks_per_step: int = 30,        vol_threshold: Optional[float] = None,    ) -> None:        super().__init__(initial=order)        assert ticks_per_step % data_granularity == 0        self.order = order        self.data_dir = data_dir        self.feature_columns_today = feature_columns_today        self.feature_columns_yesterday = feature_columns_yesterday        self.ticks_per_step: int = ticks_per_step // data_granularity        self.vol_threshold = vol_threshold        self.backtest_data = self.get_backtest_data()        self.ticks_index = self.backtest_data.get_time_index()        # Get time index available for trading        self.ticks_for_order = self._get_ticks_slice(self.order.start_time, self.order.end_time)        self.cur_time = self.ticks_for_order[0]        self.cur_step = 0        # NOTE: astype(float) is necessary in some systems.        # this will align the precision with `.to_numpy()` in `_split_exec_vol`        self.twap_price = float(self.backtest_data.get_deal_price().loc[self.ticks_for_order].astype(float).mean())        self.position = order.amount        metric_keys = list(SAOEMetrics.__annotations__.keys())  # pylint: disable=no-member        # NOTE: can empty dataframe contain index?        self.history_exec = pd.DataFrame(columns=metric_keys).set_index("datetime")        self.history_steps = pd.DataFrame(columns=metric_keys).set_index("datetime")        self.metrics = None        self.market_price: Optional[np.ndarray] = None        self.market_vol: Optional[np.ndarray] = None        self.market_vol_limit: Optional[np.ndarray] = None    def get_backtest_data(self) -> BaseIntradayBacktestData:        try:            data = load_handler_intraday_processed_data(                data_dir=self.data_dir,                stock_id=self.order.stock_id,                date=pd.Timestamp(self.order.start_time.date()),                feature_columns_today=self.feature_columns_today,                feature_columns_yesterday=self.feature_columns_yesterday,                backtest=True,                index_only=False,            )            return DataframeIntradayBacktestData(data.today)        except (AttributeError, FileNotFoundError):            # TODO: For compatibility with older versions of test scripts (tests/rl/test_saoe_simple.py)            # TODO: In the future, we should modify the data format used by the test script,            # TODO: and then delete this branch.            return load_simple_intraday_backtest_data(                self.data_dir / "backtest",                self.order.stock_id,                pd.Timestamp(self.order.start_time.date()),                "close",                self.order.direction,            )    def step(self, amount: float) -> None:        """Execute one step or SAOE.        Parameters        ----------        amount            The amount you wish to deal. The simulator doesn't guarantee all the amount to be successfully dealt.        """        assert not self.done()        self.market_price = self.market_vol = None  # avoid misuse        exec_vol = self._split_exec_vol(amount)        assert self.market_price is not None        assert self.market_vol is not None        ticks_position = self.position - np.cumsum(exec_vol)        self.position -= exec_vol.sum()        if abs(self.position) < 1e-6:            self.position = 0.0        if self.position < -EPS or (exec_vol < -EPS).any():            raise ValueError(f"Execution volume is invalid: {exec_vol} (position = {self.position})")        # Get time index available for this step        time_index = self._get_ticks_slice(self.cur_time, self._next_time())        self.history_exec = self._dataframe_append(            self.history_exec,            SAOEMetrics(                # It should have the same keys with SAOEMetrics,                # but the values do not necessarily have the annotated type.                # Some values could be vectorized (e.g., exec_vol).                stock_id=self.order.stock_id,                datetime=time_index,                direction=self.order.direction,                market_volume=self.market_vol,                market_price=self.market_price,                amount=exec_vol,                inner_amount=exec_vol,                deal_amount=exec_vol,                trade_price=self.market_price,                trade_value=self.market_price * exec_vol,                position=ticks_position,                ffr=exec_vol / self.order.amount,                pa=price_advantage(self.market_price, self.twap_price, self.order.direction),            ),        )        self.history_steps = self._dataframe_append(            self.history_steps,            [self._metrics_collect(self.cur_time, self.market_vol, self.market_price, amount, exec_vol)],        )        if self.done():            if self.env is not None:                self.env.logger.add_any("history_steps", self.history_steps, loglevel=LogLevel.DEBUG)                self.env.logger.add_any("history_exec", self.history_exec, loglevel=LogLevel.DEBUG)            self.metrics = self._metrics_collect(                self.ticks_index[0],  # start time                self.history_exec["market_volume"],                self.history_exec["market_price"],                self.history_steps["amount"].sum(),                self.history_exec["deal_amount"],            )            # NOTE (yuge): It looks to me that it's the "correct" decision to            # put all the logs here, because only components like simulators themselves            # have the knowledge about what could appear in the logs, and what's the format.            # But I admit it's not necessarily the most convenient way.            # I'll rethink about it when we have the second environment            # Maybe some APIs like self.logger.enable_auto_log() ?            if self.env is not None:                for key, value in self.metrics.items():                    if isinstance(value, float):                        self.env.logger.add_scalar(key, value)                    else:                        self.env.logger.add_any(key, value)        self.cur_time = self._next_time()        self.cur_step += 1    def get_state(self) -> SAOEState:        return SAOEState(            order=self.order,            cur_time=self.cur_time,            cur_step=self.cur_step,            position=self.position,            history_exec=self.history_exec,            history_steps=self.history_steps,            metrics=self.metrics,            backtest_data=self.backtest_data,            ticks_per_step=self.ticks_per_step,            ticks_index=self.ticks_index,            ticks_for_order=self.ticks_for_order,        )    def done(self) -> bool:        return self.position < EPS or self.cur_time >= self.order.end_time    def _next_time(self) -> pd.Timestamp:        """The "current time" (``cur_time``) for next step."""        # Look for next time on time index        current_loc = self.ticks_index.get_loc(self.cur_time)        next_loc = current_loc + self.ticks_per_step        # Calibrate the next location to multiple of ticks_per_step.        # This is to make sure that:        # as long as ticks_per_step is a multiple of something, each step won't cross morning and afternoon.        next_loc = next_loc - next_loc % self.ticks_per_step        if next_loc < len(self.ticks_index) and self.ticks_index[next_loc] < self.order.end_time:            return self.ticks_index[next_loc]        else:            return self.order.end_time    def _cur_duration(self) -> pd.Timedelta:        """The "duration" of this step (step that is about to happen)."""        return self._next_time() - self.cur_time    def _split_exec_vol(self, exec_vol_sum: float) -> np.ndarray:        """        Split the volume in each step into minutes, considering possible constraints.        This follows TWAP strategy.        """        next_time = self._next_time()        # get the backtest data for next interval        self.market_vol = self.backtest_data.get_volume().loc[self.cur_time : next_time - EPS_T].to_numpy()        self.market_price = self.backtest_data.get_deal_price().loc[self.cur_time : next_time - EPS_T].to_numpy()        assert self.market_vol is not None and self.market_price is not None        # split the volume equally into each minute        exec_vol = np.repeat(exec_vol_sum / len(self.market_price), len(self.market_price))        # apply the volume threshold        market_vol_limit = self.vol_threshold * self.market_vol if self.vol_threshold is not None else np.inf        exec_vol = np.minimum(exec_vol, market_vol_limit)  # type: ignore        # Complete all the order amount at the last moment.        if next_time >= self.order.end_time:            exec_vol[-1] += self.position - exec_vol.sum()            exec_vol = np.minimum(exec_vol, market_vol_limit)  # type: ignore        return exec_vol    def _metrics_collect(        self,        datetime: pd.Timestamp,        market_vol: np.ndarray,        market_price: np.ndarray,        amount: float,  # intended to trade such amount        exec_vol: np.ndarray,    ) -> SAOEMetrics:        assert len(market_vol) == len(market_price) == len(exec_vol)        if np.abs(np.sum(exec_vol)) < EPS:            exec_avg_price = 0.0        else:            exec_avg_price = cast(float, np.average(market_price, weights=exec_vol))  # could be nan            if hasattr(exec_avg_price, "item"):  # could be numpy scalar                exec_avg_price = exec_avg_price.item()  # type: ignore        return SAOEMetrics(            stock_id=self.order.stock_id,            datetime=datetime,            direction=self.order.direction,            market_volume=market_vol.sum(),            market_price=market_price.mean(),            amount=amount,            inner_amount=exec_vol.sum(),            deal_amount=exec_vol.sum(),  # in this simulator, there's no other restrictions            trade_price=exec_avg_price,            trade_value=float(np.sum(market_price * exec_vol)),            position=self.position,            ffr=float(exec_vol.sum() / self.order.amount),            pa=price_advantage(exec_avg_price, self.twap_price, self.order.direction),        )    def _get_ticks_slice(self, start: pd.Timestamp, end: pd.Timestamp, include_end: bool = False) -> pd.DatetimeIndex:        if not include_end:            end = end - EPS_T        return self.ticks_index[self.ticks_index.slice_indexer(start, end)]    @staticmethod    def _dataframe_append(df: pd.DataFrame, other: Any) -> pd.DataFrame:        # dataframe.append is deprecated        other_df = pd.DataFrame(other).set_index("datetime")        other_df.index.name = "datetime"        return pd.concat([df, other_df], axis=0)def price_advantage(    exec_price: float_or_ndarray,    baseline_price: float,    direction: OrderDir | int,) -> float_or_ndarray:    if baseline_price == 0:  # something is wrong with data. Should be nan here        if isinstance(exec_price, float):            return 0.0        else:            return np.zeros_like(exec_price)    if direction == OrderDir.BUY:        res = (1 - exec_price / baseline_price) * 10000    elif direction == OrderDir.SELL:        res = (exec_price / baseline_price - 1) * 10000    else:        raise ValueError(f"Unexpected order direction: {direction}")    res_wo_nan: np.ndarray = np.nan_to_num(res, nan=0.0)    if res_wo_nan.size == 1:        return res_wo_nan.item()    else:        return cast(float_or_ndarray, res_wo_nan)
```

b)State interpreter

> 状态解释器负责将原始格式（由模拟器提供的格式）中的状态解释为策略能够理解的格式中的状态。例如，将非结构化的原始特征转化为数值张量。

c)Action interpreter

> 动作解释器是由策略生成的动作，将其从策略提供的格式转换成模拟器可接受的格式。

d)Reward function

> 奖励函数在每次策略执行一个动作后向策略返回一个数值奖励。

2)Policy

> 可以直接使用Tianshou提供的策略，也可以通过继承Tianshou的策略来实现自己的策略。

3)Training Vessel & Trainer

Training Vessel是一个包含了模拟器/解释器/奖励函数/策略的Vessel，它控制与算法相关的训练部分。训练器则负责控制训练的运行时部分。Training Vessel本身持有构建EnvWrapper所需的所有组件，而不是直接持有EnvWrapper的实例。这使得Training Vessel可以在需要时动态创建EnvWrapper的副本（例如，在并行训练下）。

有了Training Vessel，训练器可以通过简单的类似于Scikit-learn的接口（例如.trainer.fit()）启动训练流程。

Trainer和TrainingVessel的详细使用，可以看这3块代码：qlib.rl.trainer.Trainer、qlib.rl.trainer.TrainingVessel、qlib.rl.trainer.TrainingVesselBase：

  

Trainer是一个用于训练机器学习模型的类，它提供了一系列方法和功能，用于加载数据、定义模型结构、训练模型、评估模型等。

其中：Trainer类的一些常用方法和功能如下：

> `__init__(self, model, criterion, optimizer, device=None)`：Trainer类的构造函数，用于初始化Trainer对象。参数包括模型、损失函数、优化器和设备。  
> `train(self, train_loader, num_epochs)`：训练方法，用于训练模型。参数包括训练数据加载器和训练的轮数。  
> `evaluate(self, data_loader)`：评估方法，用于评估模型在给定数据集上的性能。参数包括数据加载器。  
> `save_model(self, file_path)`：保存模型方法，将训练好的模型保存到指定文件路径。  
> `load_model(self, file_path)`：加载模型方法，从指定文件路径加载已经训练好的模型。  
> `get_model(self)`：获取模型方法，返回训练好的模型。

TrainingVessel是一个用于管理训练过程的类，它提供了一系列方法和功能，用于配置训练参数、创建Trainer对象、执行训练过程等，下面是TrainingVessel类的一些常用方法和功能：

> `__init__(self, model, criterion, optimizer, device=None)`：TrainingVessel类的构造函数，用于初始化TrainingVessel对象。参数包括模型、损失函数、优化器和设备。  
> `set_train_loader(self, train_loader)`：设置训练数据加载器。  
> `set_val_loader(self, val_loader)`：设置验证数据加载器。  
> `set_test_loader(self, test_loader)`：设置测试数据加载器。  
> `set_num_epochs(self, num_epochs)`：设置训练的轮数。  
> `set_save_model_path(self, save_model_path)`：设置保存模型的文件路径。  
> `set_load_model_path(self, load_model_path)`：设置加载模型的文件路径。  
> `set_checkpoint_path(self, checkpoint_path)`：设置保存训练过程中的检查点的文件路径。  
> `set_checkpoint_frequency(self, checkpoint_frequency)`：设置保存检查点的频率。  
> `set_early_stopping(self, patience=10, delta=0.0)`：设置早停策略，即在验证集上的性能不再提升时是否停止训练。  
> `set_learning_rate_scheduler(self, scheduler)`：设置学习率调度器，用于动态调整学习率。  
> `train(self)`：执行训练过程。  
> `evaluate(self, data_loader)`：评估方法，用于评估模型在给定数据集上的性能。参数包括数据加载器。  
> `save_model(self)`：保存模型方法，将训练好的模型保存到指定文件路径。  
> `load_model(self)`：加载模型方法，从指定文件路径加载已经训练好的模型。  
> `get_model(self)`：获取模型方法，返回训练好的模型。

## 3、量化交易过程中的业务场景

强化学习方法在各种应用中都取得了显著的成就，包括游戏、资源分配、推荐系统、营销和广告。 在涉及持续决策的投资背景下，让我们考虑一下股票市场的例子：

> 投资者通过各种买卖行为有效管理自己的头寸和股票持有量，努力优化投资回报。  
> 此外，投资者在做出每个买入或卖出决定之前会仔细评估市场状况和股票特定信息。  
> 从投资者的角度来看，这个过程可以看作是一个由与市场互动驱动的持续决策过程。  
> 强化学习算法为应对此类挑战提供了一种很有前途的方法。

以下是RL在量化投资中具有应用潜力的几种情况。

### 1）订单执行

订单执行任务是在考虑多种因素的同时高效执行订单，包括最优价格、最小化交易成本、降低市场影响、最大化订单履行率以及在指定时间范围内实现执行。

通过将目标纳入奖励功能和行动选择过程，可以将强化学习应用于此类任务。具体来说，RL代理与市场环境交互，从市场信息中观察状态，并决定下一步执行。RL算法通过试错来学习最优执行策略，旨在最大化预期的累积奖励，其中包含预期目标。

常规设置：

> 环境：环境代表发生订单执行的金融市场。它包含订单簿动态、流动性、价格变动和市场状况等变量。  
> 状态：状态是指 RL 代理在给定时间步长可用的信息。它通常包括当前订单簿状态（买卖差价、订单深度）、历史价格数据、历史交易量、市场波动以及任何其他有助于决策的相关信息等功能。  
> 操作：操作是 RL 代理根据观察到的状态做出的决定。在订单执行中，操作可以包括选择订单大小、价格和执行时间。  
> 奖励：奖励是一个标量信号，指示 RL 代理在环境中的操作性能。奖励功能旨在鼓励能够实现高效和具有成本效益的订单执行的行动。它通常考虑多个目标，例如最大化价格优势，最小化交易成本（包括交易费用和滑点），减少市场影响（订单对市场价格的影响）和最大化订单履行率。

应用场景：

> 单资产订单执行：

单资产订单执行侧重于为特定资产（例如股票或加密货币）执行单个订单的任务。主要目标是有效地执行订单，同时考虑诸如最大化价格优势、最小化交易成本、减少市场影响和实现高完成率等因素。

_RL 代理与市场环境交互，并就该特定资产的订单大小、价格和执行时间做出决策。目标是学习单个资产的最佳执行策略，在考虑该资产的特定动态和特征的同时最大化预期的累积奖励。_

> 多资产订单执行：

多资产订单执行将订单执行任务扩展为涉及多个资产或证券。它通常涉及同时或按顺序执行不同资产的订单组合。与单一资产订单执行不同，重点不仅在于单个订单的执行，还在于管理投资组合中不同资产之间的交互和依赖关系。

_RL 代理需要就投资组合中每种资产的订单大小、价格和时间做出决策，同时考虑它们的相互依赖性、现金限制、市场条件和交易成本。目标是学习一种最佳执行策略，平衡每种资产的执行效率，同时考虑整个投资组合的整体表现和目标。_

### 2）投资组合构建

投资组合构建是在投资组合中选择和分配资产的过程。RL提供了一个框架，通过学习与市场环境的互动并在考虑风险管理的同时最大化长期回报来优化投资组合管理决策。

常规设置：

> 状态：状态表示有关市场和投资组合的当前信息。它通常包括历史价格和交易量、技术指标和其他相关数据。  
> 行动：该行动对应于将资本分配给投资组合中不同资产的决定。它决定了每种资产投资的权重或比例。  
> 奖励：奖励是评估投资组合表现的指标。它可以通过多种方式定义，例如总回报、风险调整后回报或其他目标，如最大化夏普比率或最小化回撤。

应用场景：

RL可以用来构建股票投资组合，代理学习在不同的股票之间分配资金。

### 4、代码示例

QlibRL提供了单个资产订单执行任务的实现示例：

1）使用QlibRL进行训练的配置文件（train\_config.yml）如下：

```
simulator:    # Each step contains 30mins    time_per_step: 30    # Upper bound of volume, should be null or a float between 0 and 1, if it is a float, represent upper bound is calculated by the percentage of the market volume    vol_limit: nullenv:    # Concurrent environment workers.    concurrency: 1    # dummy or subproc or shmem. Corresponding to `parallelism in tianshou <https://tianshou.readthedocs.io/en/master/api/tianshou.env.html#vectorenv>`_.    parallel_mode: dummyaction_interpreter:    class: CategoricalActionInterpreter    kwargs:        # Candidate actions, it can be a list with length L: [a_1, a_2,..., a_L] or an integer n, in which case the list of length n+1 is auto-generated, i.e., [0, 1/n, 2/n,..., n/n].        values: 14        # Total number of steps (an upper-bound estimation)        max_step: 8    module_path: qlib.rl.order_execution.interpreterstate_interpreter:    class: FullHistoryStateInterpreter    kwargs:        # Number of dimensions in data.        data_dim: 6        # Equal to the total number of records. For example, in SAOE per minute, data_ticks is the length of the day in minutes.        data_ticks: 240        # The total number of steps (an upper-bound estimation). For example, 390min / 30min-per-step = 13 steps.        max_step: 8        # Provider of the processed data.        processed_data_provider:            class: PickleProcessedDataProvider            module_path: qlib.rl.data.pickle_styled            kwargs:                data_dir: ./data/pickle_dataframe/feature    module_path: qlib.rl.order_execution.interpreterreward:    class: PAPenaltyReward    kwargs:        # The penalty for a large volume in a short time.        penalty: 100.0    module_path: qlib.rl.order_execution.rewarddata:    source:        order_dir: ./data/training_order_split        data_dir: ./data/pickle_dataframe/backtest        # number of time indexes        total_time: 240        # start time index        default_start_time: 0        # end time index        default_end_time: 240        proc_data_dim: 6    num_workers: 0    queue_size: 20network:    class: Recurrent    module_path: qlib.rl.order_execution.networkpolicy:    class: PPO    kwargs:        lr: 0.0001    module_path: qlib.rl.order_execution.policyruntime:    seed: 42    use_cuda: falsetrainer:    max_epoch: 2    # Number of episodes collected in each training iteration    repeat_per_collect: 5    earlystop_patience: 2    # Episodes per collect at training.    episode_per_collect: 20    batch_size: 16    # Perform validation every n iterations    val_every_n_epoch: 1    checkpoint_path: ./checkpoints    checkpoint_every_n_iters: 1
```

2）使用QlibRL进行回测的配置文件（backtest\_config.yml）如下：

```
order_file: ./data/backtest_orders.csvstart_time: "9:45"end_time: "14:44"qlib:    provider_uri_1min: ./data/bin    feature_root_dir: ./data/pickle    # feature generated by today's information    feature_columns_today: [        "$open", "$high", "$low", "$close", "$vwap", "$volume",    ]    # feature generated by yesterday's information    feature_columns_yesterday: [        "$open_v1", "$high_v1", "$low_v1", "$close_v1", "$vwap_v1", "$volume_v1",    ]exchange:    # the expression for buying and selling stock limitation    limit_threshold: ['$close == 0', '$close == 0']    # deal price for buying and selling    deal_price: ["If($close == 0, $vwap, $close)", "If($close == 0, $vwap, $close)"]volume_threshold:    # volume limits are both buying and selling, "cum" means that this is a cumulative value over time    all: ["cum", "0.2 * DayCumsum($volume, '9:45', '14:44')"]    # the volume limits of buying    buy: ["current", "$close"]    # the volume limits of selling, "current" means that this is a real-time value and will not accumulate over time    sell: ["current", "$close"]strategies:    30min:        class: TWAPStrategy        module_path: qlib.contrib.strategy.rule_strategy        kwargs: {}    1day:        class: SAOEIntStrategy        module_path: qlib.rl.order_execution.strategy        kwargs:        state_interpreter:            class: FullHistoryStateInterpreter            module_path: qlib.rl.order_execution.interpreter            kwargs:            max_step: 8            data_ticks: 240            data_dim: 6            processed_data_provider:                class: PickleProcessedDataProvider                module_path: qlib.rl.data.pickle_styled                kwargs:                data_dir: ./data/pickle_dataframe/feature        action_interpreter:            class: CategoricalActionInterpreter            module_path: qlib.rl.order_execution.interpreter            kwargs:            values: 14            max_step: 8        network:            class: Recurrent            module_path: qlib.rl.order_execution.network            kwargs: {}        policy:            class: PPO            module_path: qlib.rl.order_execution.policy            kwargs:                lr: 1.0e-4                # Local path to the latest model. The model is generated during training, so please run training first if you want to run backtest with a trained policy. You could also remove this parameter file to run backtest with a randomly initialized policy.                weight_file: ./checkpoints/latest.pth# Concurrent environment workers.concurrency: 5
```

3）通过上面的配置文件，使用下面的命令开始训练agent:

```
$ python -m qlib.rl.contrib.train_onpolicy.py --config_path train_config.yml
```

4）训练完成后，可以使用如下命令进行回测:

```
$ python -m qlib.rl.contrib.backtest.py --config_path backtest_config.yml
```

在上述例子中：

模拟器相关的类：

> qlib.rl.order\_execution.simulator\_qlib.SingleAssetOrderExecution  
> qlib.rl.order\_execution.simulator\_simple.SingleAssetOrderExecutionSimple

解析器相关的类：

> qlib.rl.order\_execution.interpreter.FullHistoryStateInterpreter  
> qlib.rl.order\_execution.interpreter.CategoricalActionInterpreter

策略相关的类：

> qlib.rl.order\_execution.policy.PPO

奖励相关的类：

> qlib.rl.order\_execution.reward.PAPenaltyReward

如果自定义上述类后，在配置文件中做下修改，即可启动自己的训练和回测。