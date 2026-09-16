# 增强深度学习模型评估以进行股市预测--Part I

QuantML QuantML 2024-11-03 19:55 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487443&idx=1&sn=c6c555e9b90e263f3ed083ba4166ed44&chksm=cff7c5d8541103c54b8d6faaee4de567ae9884a1b4eedac008c74cadd76d90d8675e14ffa34b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487443&idx=1&sn=c6c555e9b90e263f3ed083ba4166ed44&chksm=cff7c5d8541103c54b8d6faaee4de567ae9884a1b4eedac008c74cadd76d90d8675e14ffa34b#rd)

#### 为什么使用自定义验证指标？

在机器学习中，不同的训练损失函数和验证指标服务于独特的目的。这种区别有助于我们捕捉学习过程的细节和模型的实际应用。

**训练损失的作用**

考虑一个分类任务。在训练过程中，我们通常使用交叉熵损失函数。为什么？因为交叉熵损失在比较预测的类别概率分布与实际分布方面非常有效。这种比较对于模型从数据中有效学习至关重要。

但是，为什么我们不能使用F1分数或准确率进行训练？原因在于可微性的需求。深度学习中的训练损失函数必须是可微的，以便优化算法可以通过梯度下降调整模型的权重。像F1分数这样的指标虽然对于评估最终性能非常出色，但它们不是可微的。

**验证指标的重要性**

在验证过程中，我们关注模型在现实世界场景中的表现，其中像F1分数这样的指标变得重要。F1分数对于分类任务特别有帮助，因为它同时考虑了精确率和召回率，提供了模型性能的平衡视角，特别是对于不平衡的数据集。此外，F1分数比交叉熵损失更易于人类理解和直观，因为它直接反映了模型正确分类正例的能力，同时最小化了假阳性和假阴性。

让我们通过一个垃圾邮件分类任务的例子来探讨这一点。假设我们有一个二元分类任务，用于检测电子邮件是否为垃圾邮件（正类）或非垃圾邮件（负类）。为了简化，假设我们在测试数据集上评估模型后得到了以下混淆矩阵：

  

  

  

  

预测为垃圾邮件

预测非垃圾

垃圾邮件

40

10

非垃圾

5

45

从混淆矩阵中，我们计算出：

-   5（错误识别为垃圾邮件的电子邮件）
    
-   10（垃圾邮件错误识别为非垃圾邮件）
    

使用这些值：

-   精确率 = 40 / (40 + 11) = 0.78
    
-   召回率 = 40 / (40 + 10) = 0.80
    
-   F1分数 = 2 \* (精确率 \* 召回率) / (精确率 + 召回率) = 0.79
    

因此，79%的F1分数提供了一个清晰、易于理解的模型准确性度量。它突出了模型预测中精确率和召回率的平衡。

**股票市场预测呢？**

拥有一个自定义验证指标也适用于股票市场预测。对于多个时间序列问题，使用均方误差（MSE）、均方根误差（RMSE）和分位数损失作为验证指标是完全可接受的。它们提供了一种强有力的方法来评估预测模型的总体准确性。

然而，对于日间交易，使用像均方误差（MSE）和均方根误差（RMSE）这样的指标可能会出现问题。它们对于交易决策的信息量较少且难以解释。这些指标主要用于衡量预测误差的平均大小，但它们没有提供关于交易时机或波动性的清晰洞察。日间交易者更关注他们交易的风险/回报。因此，虽然RMSE或MSE可能用于训练，但像夏普比率或索提诺比率这样的验证指标更为相关。

例如，RMSE可以最小化预测和实际股票价格之间的差异，但与这个指标相关的交易没有风险或回报。相比之下，夏普比率同时考虑了回报和风险，提供了更直观的交易性能度量。如果一个模型预测了高回报但伴随着高风险，交易者可能更喜欢稍微低一点的回报但显著降低的风险，这正是夏普比率所强调的。

通过使用NeuralForecast的时序融合转换器（TFT）模型，并在NeuralForecast框架内创建自定义验证指标，我们可以确保我们的模型与交易者的需求保持一致。这种方法有助于选择具有商业代表性的验证指标，使模型在股票预测方面更加实用。

### 配置以训练和测试模型

我们对TFT模型进行了少量特征工程，没有进行降维、交叉验证或超参数优化。主要目标是展示一个用于股票预测的自定义验证指标。

**使用的数据**

为了保持模型的简单性，我们将专门关注一个单变量时间序列：SPY（SPDR标准普尔500 ETF信托）的每日回报。模型使用2005年至2024年的历史数据进行训练，涵盖了训练和测试期间。我们使用每天的开盘和收盘价格来计算每日回报。这为模型增加了一层现实感。日间交易者可能在早上开仓并在当天结束时平仓。为了简化，我们最初在模型中省略了佣金和滑点等因素，但这些可以很容易地包含进来。

预测回报使我们能够处理平稳数据。回报通常是平稳的——至少是弱平稳的——不像价格是非平稳的。此外，虽然预测价格可能与期权交易者的策略相关，其策略取决于未来价格，但对于日间交易者来说，主要关注的是资产可能产生的潜在回报，而不是其价格。仅仅知道价格，没有像历史价格这样的额外背景，对交易者来说几乎没有价值。

此外，我们的模型包含了每日外生变量，如VIX（波动率指数）、5年期盈亏平衡通胀率，以提高模型性能。

**配置**

以下是用于训练和测试模型的YAML配置。

```
start date : '2005-07-01'end date : '2024-05-23'max missing data : 0.02min nb trades : 60train test split : [0.9, 0.10]val proportion size : 0.15output :   - source : 'yahoo'    data :       - 'SPY'  historic variables :    - source: 'fred'      data:        - 'T5YIE'        - 'T10YIE'        - 'T10Y3M'        - 'DGS10'        - 'DGS2'        - 'DTB3'        - 'DEXUSNZ'        - 'VIXCLS'        - 'T10Y2Y'        - 'NASDAQCOM'        - 'DCOILWTICO'    - source: 'yahoo'      data:        - "GC=F"        - 'MSFT'        - 'GOOGL'        - 'AAPL'        - 'AMZN'  future variables :    - 'day'    - 'month'TFT_parameters:  h: 1  input size: 64  max steps: 500  val check steps: 1  batch size: 32  inference windows batch size: -1  valid batch size: 2000  learning rate: 0.0005  scaler type : 'robust'  random seed: 42  loss: 'HuberMQLoss'  hidden size: 256  n head: 8  dropout: 0.1  attn_dropout: 0.1  gradient_clip val: 1  other parameters :    confidence level: 0.6    quantiles : [ 0.05, 0.4, 0.5, 0.6, 0.95 ]    callbacks :      EarlyStopping :        monitor : 'valid loss'        patience : 20        verbose : True        mode : 'min'      ModelCheckPoint :        monitor : 'valid loss'        mode : 'min'        save top k : 1        verbose : True
```

模型使用每日交易数据进行训练和测试。

-   外生变量允许的最大缺失数据点百分比。如果超过该值，我们丢弃该特征。
    
-   该变量设置了验证和测试期间所需的最小交易次数。由于我们使用分位数的概率，有时我们可能不会进入交易。更多信息请参阅下面的部分。
    
-   数据分割为训练（90%）和测试（10%）集的比例。
    
-   分配给验证目的的训练数据比例（15%）。15% \* 90% = 总数据集的13.5%。
    
-   我们预测的是SPY（S&P 500 ETF），以保持简单。
    
-   每天的数据，可以潜在地提高模型性能。使用的变量数量保持最小化，因为模型是在没有GPU的本地机器上训练和测试的。我们专注于最有用的变量。我们绝对可以增加外生变量的数量并应用特征工程来提高模型性能。
    
-   一些来自圣路易斯联邦储备银行经济数据（FRED）的例子 - VIX，市场波动率的度量，- 10年期减去3个月期国债恒定到期日，- 5年期盈亏平衡通胀率。
    
-   来自雅虎财经 - 黄金期货每日价格，- 微软股票每日价格。
    
-   预测时已知的变量，如day和month。例如，如果我们认为投资组合经理在每个月末重新平衡他们的投资组合，这可能会影响SPY在该时间的每日回报。考虑像月末（例如，1月31日）这样的变量可以捕捉这些影响，并有助于做出更好的预测。
    
-   关于TFT参数和超参数的定义，请参阅NeuralForecast文档。对于大多数超参数，我们使用了NeuralForecast提供的默认值。
    
-   预测范围，即模型预测的步数。我们将其设置为1，因为我们想表现得像日间交易者。在每天结束时，我们想知道我们是否应该在第二天采取多头、空头或无头寸。这允许进行每日决策。
    
-   用于模型输入的过去时间步数，相当于大约3个月的交易日。
    
-   训练期间计算验证指标的频率。这非常小。随着数据集的增大和模型的复杂化（例如，更大的hidden\_size），它可以增加到10、50、100，因为它会变得计算上昂贵。
    
-   验证期间的批量大小设置为2000，以确保在计算验证指标时一次性处理所有验证数据。这是因为自定义验证指标是按照我们需要在一次批量中传递所有验证数据的方式来构建的。稍后会详细介绍。
    
-   用于在训练迭代期间对每个输入窗口的数据进行归一化（TemporalNorm）。在这种情况下，使用的是鲁棒归一化器，这是时序融合转换器（TFT）默认使用的归一化器。它对异常值有效，这在经济和金融时间序列中很常见。
    
-   用于训练的是HuberMQLoss损失函数。这种方法对异常值具有鲁棒性。分位数通过提供某些结果的可能性而不是仅仅提供点预测，为时间序列数据提供了更现实的视角。此外，它允许使用分位数推断概率。
    
-   梯度裁剪的最大值，以防止梯度爆炸。我们可以通过使用TensorBoard跟踪梯度来确认最佳值。
    
-   这是我们进入交易的最低水平。负回报或正回报的概率必须超过这个水平；否则，我们不会在那个数据点（或那天）进入交易。这个置信水平设置得很低，因为模型很简单，目标是构建一个自定义验证指标。
    
-   用于预测的不同分位数。
    
-   EarlyStopping回调：监控自定义验证指标，如果损失在20个周期内没有改善，将停止训练，最小化监控值。
    
-   ModelCheckPoint回调：保存具有最佳自定义验证指标的模型，只保留表现最好的模型。
    

**为什么使用最小交易次数？**

在推理过程中，预测分位数而不是点预测允许我们评估特定每日回报的概率。例如，对于80百分位，如果回报是-0.1%，我们可以预期有80%的可能性该回报在该天将低于或等于-0.1%。

这种方法允许我们根据特定的阈值采取头寸。例如，如果我们设置60%的置信水平，并且40百分位的回报是正的，我们将在那天做多，预期有60%的可能性获得正回报。另一方面，如果60百分位的回报是负的，我们将做空，预期有60%的可能性获得负回报。如果这两个条件都不满足，避免头寸有助于防止不必要的交易，这些交易不符合预期的概率。

注意：我们在推理过程中可以推断概率，因为模型是使用分位数损失函数（多分位数Huber损失）训练的。

### 准备数据

**获取数据**

让我们考虑一个使用FRED的5年期盈亏平衡通胀率的例子。这里概述的步骤适用于其他变量，包括外生变量和目标变量（SPY）。

第一部分是从源获取数据。

```
import pandas as pdimport yamlwith open('custom_validation_metric/config.yaml', "r") as yaml_file:    config = yaml.load(yaml_file, Loader=yaml.FullLoader)request = f"https://fred.stlouisfed.org/graph/fredgraph.csv?id=T5YIE"request += f"&cosd={config['start_date']}"request += f"&coed={config['end_date']}"T5YIE_raw = pd.read_csv(request, parse_dates=['DATE'])T5YIE_raw.rename(columns={'DATE': "ds", T5YIE_raw.columns[1]: "value_T5YIE"}, inplace=True)print(T5YIE_raw.head(10))
```

如NeuralForecast数据输入中所指定的，日期戳列必须命名为ds。Y df是一个包含三列的DataFrame：unique\_id，每个时间序列的唯一标识符，一列ds带有日期戳，一列y带有系列的值。

**清理数据**

我们移除空数据，只保留市场开放的日子。如上所示，2005年7月4日（独立日）有一个空值。

```
import pandas_market_calendars as mcalfrom typing import Optionaldef obtain_market_dates(start_date: str, end_date: str, market: Optional[str] = "NYSE") -> pd.DataFrame:    nyse = mcal.get_calendar(market)    market_open_dates = nyse.schedule(start_date=start_date, end_date=end_date)    return market_open_dates_market_dates = obtain_market_dates(config['start_date'], config['end_date'])T5YIE_correct_dates = T5YIE_raw.loc[T5YIE_raw['ds'].isin(_market_dates.index)]
```

```
def replace_empty_data(df: pd.DataFrame) -> pd.DataFrame:    mask = df.isin(["", ".", None])    rows_to_remove = mask.any(axis=1)    return df.loc[~rows_to_remove]T5YIE_cleaned = replace_empty_data(T5YIE_correct_dates)print(T5YIE_cleaned.head(10))
```

**处理缺失数据**

对于任何外生变量，如果缺失数据的数量超过`max_missing_data`（2%），则该变量被排除在模型训练之外。如果该变量有足够的数据，我们将任何缺失的数据替换为前一个值。

```
from typing import Union, Tupleimport loggingdef handle_missing_data(data: pd.DataFrame, market_open_dates: pd.DataFrame) -> Tuple[Union[None, pd.DataFrame], Union[pd.DataFrame, None]]:    modified_data = data.copy()    market_open_dates["count"] = 0    market_open_dates.index = market_open_dates.index.strftime("%Y-%m-%d")    date_counts = data['ds'].value_counts()    market_open_dates["count"] = market_open_dates.index.map(date_counts).fillna(0)    missing_dates = market_open_dates.loc[market_open_dates["count"] < 1]        if not missing_dates.empty:        max_count = (len(market_open_dates) * config["max_missing_data"])        if len(missing_dates) > max_count:            logging.warning(f"For current asset T5YIE there are {len(missing_dates)} missing data which is more than the maximum threshold of {config['max_missing_data'] * 100}%")            return None, None        else:            for date, row in missing_dates.iterrows():                modified_data = insert_missing_date(modified_data, date, 'ds')            return modified_data, missing_dates    else:        return modified_data, missing_datesdef insert_missing_date(_data: pd.DataFrame, date: str, date_column: str) -> pd.DataFrame:    date = pd.to_datetime(date)    if date not in _data[date_column].values:        prev_date = (_data[_data[date_column] < date].iloc[-1] if not _data[_data[date_column] < date].empty else _data.iloc[0])        new_row = prev_date.copy()        new_row[date_column] = date        _data = (pd.concat([_data, new_row.to_frame().T], ignore_index=True).sort_values(by=date_column).reset_index(drop=True))    return _dataT5YIE_processed, missing_dates = handle_missing_data(T5YIE_cleaned, _market_dates)T5YIE_processed['ds'] = pd.to_datetime(T5YIE_processed['ds'])sample_date = pd.to_datetime(missing_dates.index[0])previous_day_data = T5YIE_processed[T5YIE_processed['ds'] < sample_date].tail(1)missing_day_data = T5YIE_processed[T5YIE_processed['ds'] == sample_date]combined_data = pd.concat([previous_day_data, missing_day_data])print(f'\n{combined_data}\n')print(T5YIE_processed.head(10))
```

在10月10日，我们有一个缺失值。尽管哥伦布日是美国联邦假日，但市场仍然开放。因此，我们将2005年10月10日的缺失值替换为前一个交易日（2005-10-07）的值。

最终值被重新索引。

**分割训练和测试集**

我们将每个变量分割为训练集和测试集。

```
train_proportion = config['train_test_split']split_index = int(len(T5YIE_processed) * train_proportion[0])train_T5YIE = T5YIE_processed.iloc[:split_index]test_T5YIE = T5YIE_processed.iloc[split_index:]
```

**特征工程**

在这一部分，我们使用微软股票价格作为例子进行特征工程。相同的原则适用于其他外生变量。我们创建了两个新特征：每日回报和高低比率。我们期望这些特征能够提高模型性能。

```
train_MSFT['high_low'] = train_MSFT['high'] / train_MSFT['low'] - 1train_MSFT['return'] = train_MSFT['close'] / train_MSFT['open'] - 1test_MSFT['high_low'] = test_MSFT['high'] / test_MSFT['low'] - 1test_MSFT['return'] = test_MSFT['close'] / test_MSFT['open'] - 1print(f"\n{train_MSFT[['high_low', 'return']].head(10)}")
```

我们将为输出变量SPY创建相同的特征，包括开盘价、最高价、最低价、收盘价以及最高价和最低价之间的差异。然而，目标列SPY每日回报需要标识符y。我们还需要该系列的unique\_id。

```
SPY_processed['y'] = SPY_processed['close'] / SPY_processed['open'] - 1SPY_processed = SPY_processed.copy()SPY_processed['unique_id'] = 'SPY'train_SPY = SPY_processed.iloc[:split_index]test_SPY = SPY_processed.iloc[split_index:]
```

接下来，我们将提取日期和月份作为未来的外生变量。我们只需要为一个变量执行此操作，因为我们的所有变量共享相同的日期。

```
from sklearn.preprocessing import MinMaxScalerscaler = MinMaxScaler()scalers = {}columns_to_scale = []train_FUTURE = pd.DataFrame()test_FUTURE = pd.DataFrame()if 'day' in config['future_variables']:    columns_to_scale.append('day')    train_FUTURE['day'] = train_MSFT['ds'].dt.day    test_FUTURE['day'] = test_MSFT['ds'].dt.day    scalers['day'] = MinMaxScaler()if 'month' in config['future_variables']:    columns_to_scale.append('month')    train_FUTURE['month'] = train_MSFT['ds'].dt.month    test_FUTURE['month'] = test_MSFT['ds'].dt.month    scalers['month'] = MinMaxScaler()if columns_to_scale:    train_FUTURE['ds'] = train_MSFT['ds']    test_FUTURE['ds'] = test_MSFT['ds']    for column in columns_to_scale:        data_reshaped_train = train_FUTURE[column].values.reshape(-1, 1)        data_reshaped_test = test_FUTURE[column].values.reshape(-1, 1)        train_FUTURE[[column]] = scalers[column].fit_transform(data_reshaped_train)        test_FUTURE[[column]] = scalers[column].transform(data_reshaped_test)print(f"\n{train_FUTURE.head(10)}\n")
```

日期和月份使用训练数据进行缩放，然后相同的缩放应用于训练和测试集。对于日期和月份，使用MinMaxScaler将值缩放到0和1之间。

**使数据平稳**

为了提高模型的鲁棒性，我们确保数据是平稳的。本文详细解释了平稳性的重要性以及如何自动使数据平稳。

我们将使用增广迪基-福勒检验（ADF检验），以95%的置信水平来确定连续时间序列是否平稳。我们将测试训练数据的平稳性，并对训练和测试集应用必要的转换。

让我们以我们的外生变量之一为例：黄金连续期货合约。我们将只检查黄金收盘价，但相同的方法适用于其他特征。

```
last_date = train_GOLD['ds'].iloc[-1].strftime('%Y-%m-%d')plt.figure(figsize=(10, 5))plt.plot(train_GOLD['ds'], train_GOLD['close'], label='Close Price')plt.title(f'Gold Close Price from {start_date.date()} to {last_date}')plt.xlabel('Date')plt.ylabel('Close Price')plt.legend()plt.grid(True)plt.show()
```

我们可以观察到，时间序列的均值随时间不是恒定的，这表明它不是平稳的。

```
from statsmodels.tsa.stattools import adfulleradf_result = adfuller(train_GOLD['close'])p_value = adf_result[1]print("\nADF Test p-value:", p_value)
```

ADF结果确认：p值大于5%，表明时间序列是非平稳的。

```
first_diff_GOLD = train_GOLD.copy()first_diff_GOLD.loc[:, 'close_diff'] = first_diff_GOLD['close'].diff()first_diff_GOLD = first_diff_GOLD.dropna()
```

```
plt.figure(figsize=(10, 5))plt.plot(first_diff_GOLD['ds'], first_diff_GOLD['close_diff'], label='First Difference of Close Price')plt.title('First Difference of Gold Close Price')plt.xlabel('Date')plt.ylabel('First Difference')plt.legend()plt.grid(True)plt.show()
```

通过应用一阶差分，我们观察到时间序列的均值接近于0，并且方差随时间保持大致恒定。

```
adf_result_diff = adfuller(first_diff_GOLD['close_diff'])p_value_diff = adf_result_diff[1]print("\nADF Test p-value after first differencing:", p_value_diff)
```

ADF p值为0，这确认了时间序列在95%的置信水平上是平稳的。

**归一化数据**

我们在训练模型之前使数据平稳。此外，我们在训练迭代期间使用归一化器，并将`scaler_type`参数设置为`robust`。

**在训练模型之前对数据进行分组**

如NeuralForecast文档中所指定的，我们需要列出历史和未来的外生变量。

要将外生变量添加到模型中，首先在初始化期间将前一个DataFrame中每个变量的名称指定为相应的模型超参数：`futr_exog_list`、`hist_exog_list`和`stat_exog_list`。

```
def rename_columns(df, suffix):    return df.rename(columns=lambda col: f"{col}_{suffix}" if col not in ['y', '```pythonunique_id'] else col)current_vars = locals().copy()train_dfs = []test_dfs = []for var_name, df in current_vars.items():    if isinstance(df, pd.DataFrame):        if var_name.startswith('train'):            suffix = var_name.split(' ')[1]            if suffix != 'FUTURE':                df = df.drop(columns='ds')            df = rename_columns(df, suffix)            train_dfs.append(df.reset_index(drop=True))        elif var_name.startswith('test'):            suffix = var_name.split(' ')[1]            if suffix != 'FUTURE':                df = df.drop(columns=['ds'])            df = rename_columns(df, suffix)            test_dfs.append(df.reset_index(drop=True))neuralforecast_train_df = pd.concat(train_dfs, axis=1).reset_index(drop=True)neuralforecast_test_df = pd.concat(test_dfs, axis=1).reset_index(drop=True)futr_list = config['future_variables'] if config['future_variables'] else Nonehist_list = [col for col in neuralforecast_test_df.columns if col not in futr_list and col not in ["ds", "time", "y", "unique_id"]]
```

**实现自定义验证指标以进行交易决策**

NeuralForecast中的所有模型都包括`valid_loss`参数，这允许我们通过一些修改来定义自定义验证指标。

NeuralForecast中的大多数损失函数都继承自`BasePointLoss`类，例如Huberized Multi-Quantile Loss。这些函数共享相同的实现，包括构造函数`__init__`和可调用方法`__call__`。对于`__call__`唯一需要的参数是`y`，实际值以张量格式表示，以及`y_hat`，预测值以张量格式表示。`__call__`方法返回损失值作为张量。

验证损失作为实例通过`valid_loss`参数传递，或者设置为等于损失参数。因此，我们需要将验证指标作为实例通过`valid_loss`传递。

```
# NeuralForecast中的示例代码class TFT(BaseWindows):    def __init__(self, loss=MAE(), valid_loss=None, **other_parameters):        super(TFT, self).__init__(loss=loss, valid_loss=valid_loss, **other_parameters)class BaseWindows(BaseModel):    def __init__(self, loss, valid_loss, **other_parameters):        if valid_loss is None:            self.valid_loss = loss        else:            self.valid_loss = valid_loss
```

现在，我们需要实现一个自定义验证指标，该指标采用相同的参数并返回相同类型的值（张量）。

```
from neuralforecast.losses.pytorch import BasePointLoss, level_to_outputs, quantiles_to_outputsfrom typing import Optional, Unionimport torchclass RiskReturn(BasePointLoss):    def __init__(self, level=[80, 90], quantiles=None, delta: float = 1.0, horizon_weight=None, config_manager: Optional[ConfigManager] = None):        with open('custom_validation_metric/config.yaml', "r") as yaml_file:            self._config = yaml.load(yaml_file, Loader=yaml.FullLoader)        qs, output_names = level_to_outputs(level)        qs = torch.Tensor(qs)        if quantiles is not None:            output_names = quantiles_to_outputs(quantiles)            qs = torch.Tensor(quantiles)        super(RiskReturn, self).__init__(horizon_weight=horizon_weight, outputsize_multiplier=len(qs), output_names=output_names)        self.quantiles = torch.nn.Parameter(qs, requires_grad=False)        self.delta = delta        self.lower_quantile = 1        self.upper_quantile = 3    def __call__(self, y: torch.Tensor, y_hat: torch.Tensor, mask: Union[torch.Tensor, None] = None) -> torch.Tensor:        daily_returns = MetricCalculation.calculate_daily_returns(y, y_hat, lower_quantile=self.lower_quantile, upper_quantile=self.upper_quantile)        metrics = MetricCalculation.get_risk_rewards_metrics(daily_returns)        if metrics['nb_of_trades'] < self.config['min_nb_trades']:            return torch.tensor(float('inf'))        return -return_on_risk
```

对于每个数据点，`y`代表实际值，而`y_hat`代表五个分位数的预测值。

我们返回`return_on_risk`的负值，因为我们的目标是最小化验证损失。另一方面，如果执行的交易次数`metrics['nb_of_trades']`低于所需的`min_nb_trades`（60），我们返回无限值，以忽略其对跨周期训练过程的影响。

```
class MetricCalculation:    def __init__(self):        self.daily_returns = torch.empty(0)        self.metrics = {}    def calculate_daily_returns(self, y: torch.Tensor, y_hat: torch.Tensor, lower_quantile: int, upper_quantile: int) -> torch.Tensor:        y_hat = y_hat.squeeze(1)        y = y.squeeze(1)        low_predictions = y_hat[:, lower_quantile]        high_predictions = y_hat[:, upper_quantile]        positive_condition = low_predictions > 0        negative_condition = high_predictions < 0        daily_returns = torch.full_like(y, float('-inf'))        daily_returns[positive_condition] = y[positive_condition]        daily_returns[negative_condition] = -y[negative_condition]        valid_returns = daily_returns[daily_returns != float('-inf')]        self.daily_returns = valid_returns        return self.daily_returns
```

现在，我们评估所有预测值`y_hat`。如果任何下分位数（40百分位）的值大于0，我们预期当天会有正回报，并采取多头头寸。如果任何上分位数（60百分位）的值小于0，我们采取空头头寸。

```
def get_risk_rewards(self, daily_returns: torch.Tensor = None):    if daily_returns is None:        daily_returns = self.daily_returns    self.metrics = {}    self.metrics["nb_of_trades"] = daily_returns.shape[0]    if self.metrics["nb_of_trades"] <= self.config['min_nb_trades']:        return self.set_zero_to_metrics(self.metrics["nb_of_trades"])    self.metrics['annualized_return'] = torch.prod(1 + daily_returns) ** (252.0 / daily_returns.shape[0]) - 1    self.metrics['annualized_risk'] = daily_returns.std() * (252 ** 0.5)    self.metrics['return_on_risk'] = self.metrics['annualized_return'] / self.metrics['annualized_risk']    return self.metricsdef set_zero_to_metrics(self, nb_of_trades) -> Dict:    self.metrics = {'annualized_return': torch.tensor(0.0), 'annualized_risk': torch.tensor(0.0), 'return_on_risk': torch.tensor(0.0), 'nb_of_trades': nb_of_trades}    return self.metrics
```

这是我们的自定义验证指标。它计算为`annualized_return`除以`annualized_risk`（年化标准差），或者简单地称为风险回报率`return_on_risk`。虽然我们可以使用Sortino或Sharpe比率以获得更高的精确度，但这个指标对于我们的用例来说已经足够好。`return_on_risk`越高越好。

如果交易次数少于所需的最小交易次数`min_nb_trades`，我们返回0的风险回报率。否则，该函数返回计算出的指标。

篇幅所限，下篇后续发出。

  

QuantML星球内有各类丰富的量化资源，包括数百篇论文代码，QuantML-Qlib框架，研报复现，研报分享项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，券商研究员，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

  

![](assets/001.webp)