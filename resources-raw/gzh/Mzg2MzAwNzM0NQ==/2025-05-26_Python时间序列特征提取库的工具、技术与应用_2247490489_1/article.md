# Python时间序列特征提取库的工具、技术与应用（上）

QuantML QuantML 2025-05-26 22:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490489&idx=1&sn=737aff09198cbf5fda753d9688847d06&chksm=cff8a20255262aabcab1f62b25f39ce8b2003d856fe07b91d89d161e3fa269b80384310cbc58#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490489&idx=1&sn=737aff09198cbf5fda753d9688847d06&chksm=cff8a20255262aabcab1f62b25f39ce8b2003d856fe07b91d89d161e3fa269b80384310cbc58#rd)

在[量化中的时序特征提取手册](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490480&idx=1&sn=1c2c87d1ff202a978305d4e1be5d9a6d&scene=21#wechat_redirect)中我们介绍了量化中时序特征提取方法和原理。

本文将详细介绍高度专业化特征提取包（如tsfresh、featuretools、Kats、sktime、Darts、tslearn和Cesium）的各种工具。深入剖析这些库的核心机制、它们能够生成的特征类型（包括统计特征、结构特征、谱特征等），并提供实际的Python代码示例以阐明其用法。通过比较分析，本文旨在为研究人员和实践者在面对具体分析需求和数据集特性时，如何选择合适的特征提取工具提供指导。

**3\. 用于高级时间序列特征提取的专用Python库**

虽然Pandas和Statsmodels为时间序列特征提取提供了坚实的基础，但面对日益复杂的时间序列数据和对模型性能的更高要求，一系列专门的Python库应运而生。这些库通常提供更自动化、更全面或针对特定类型特征的提取能力。

-   3.1. tsfresh：可扩展的综合特征工程
    
    tsfresh 是一个强大的Python包，用于从时间序列中自动提取大量的特征，并能评估这些特征与目标变量的相关性。
    

-   核心机制： tsfresh的核心在于其能够系统性地从时间序列数据中提取数百个特征。这些特征的计算基于统计学、时间序列分析、信号处理和非线性动力学等多个领域的成熟算法。一个关键的组成部分是FRESH (FeatuRe Extraction based on Scalable Hypothesis tests) 算法，它通过可扩展的假设检验来评估每个提取出的特征对于预测目标变量的重要性，从而实现自动化的特征选择。这个过程有助于降低特征空间的维度，去除不相关或冗余的特征，从而提升模型的泛化能力和训练效率。
    
-   支持的特征类型： tsfresh能够生成的特征种类非常广泛，覆盖了时间序列的多种特性。这包括基础的统计量（如均值、中位数、方差、偏度、峰度等），谱特性（如快速傅里叶变换（FFT）系数），复杂度度量（如熵），自相关性特征，以及一些更复杂的特征，例如时间反转对称性统计量 (time reversal symmetry statistic) 和峰值数量 (number of peaks)。tsfresh中的特征计算器可以分为两类：“简单”计算器（simple），用于计算单个数值特征；以及“组合器”计算器（combiner），它能一次性为一系列参数计算一组特征，以便利用缓存结果提高效率。具体的特征例子包括绝对能量 (abs\_energy)、FFT系数 (fft\_coefficient)、自回归系数 (ar\_coefficient)、分箱熵 (binned\_entropy)、连续小波变换系数 (cwt\_coefficients) 以及增广迪基-福勒检验统计量 (augmented\_dickey\_fuller)。
    
-   配置、用法与集成： tsfresh提供了高度的灵活性，用户可以通过ComprehensiveFCParameters对象或自定义设置来精确控制提取哪些特征以及特征的参数。预定义的特征集包括“minimal”（最小集）、“efficient”（高效集）和“comprehensive”（全面集）。该库与Pandas、NumPy和scikit-learn等标准数据科学库良好兼容，并且既可以在本地计算机上运行，也可以部署在集群环境中进行大规模特征提取。输入数据通常是一个特定格式的Pandas DataFrame（长格式或宽格式），需要指定时间序列ID列 (column\_id)、时间排序 (column\_sort)、特征类型列 (column\_kind，用于多变量时间序列) 和值列 (column\_value)。
    
-   优势： tsfresh的主要优势在于其经过了实际应用的检验，拥有完善的单元测试，其特征筛选过程在统计学上是严谨的，并且提供了全面的文档。此外，它还允许用户方便地添加自定义的特征计算器，具有良好的可扩展性。
    
-   **代码示例：使用tsfresh进行特征提取与选择**
    
    Python
    
    `import pandas as pd   import numpy as np   from tsfresh import extract_features, select_features   from tsfresh.utilities.dataframe_functions import impute   from tsfresh.feature_extraction import ComprehensiveFCParameters, EfficientFCParameters      # 1. 准备tsfresh兼容格式的数据   # 假设我们有一个包含多个时间序列的DataFrame   # 每个时间序列有一个唯一的id，一个时间戳列，和一个值列   data = {       'id': np.concatenate([np.ones(10), np.ones(10)*2]).astype(int), # 2个ID，每个ID有10个时间点       'time': np.tile(np.arange(10), 2), # 时间戳从0到9，重复两次       'value': np.random.randn(20) # 20个随机值   }   timeseries_df = pd.DataFrame(data)      print("原始时间序列DataFrame:")   print(timeseries_df)   print("-" * 30)      # 2. 使用extract_features()生成特征矩阵   # 默认情况下，tsfresh会提取大量的特征   # column_id指定ID列，column_sort指定时间排序列，column_value指定值列   # default_fc_parameters可以用来选择特征计算器及其参数   # 例如，使用 'EfficientFCParameters' 来提取一组高效的特征      extracted_features = extract_features(timeseries_df,                                         column_id='id',                                         column_sort='time',                                         column_value='value',                                         default_fc_parameters=EfficientFCParameters(),                                         impute_function=impute, # 处理NaN值                                         show_warnings=False) # 关闭警告信息      print("\n提取的特征矩阵 (部分特征):")   print(extracted_features.head())   print(f"提取的特征数量: {extracted_features.shape}")   print("-" * 30)      # 3. (可选) 如果有目标变量，可以使用select_features()进行特征选择   # 假设我们有一个目标变量y (与每个id对应)   # extracted_features 的索引是id列   y_series = pd.Series([0, 1], index=extracted_features.index.unique().sort_values(), name="target")         if not extracted_features.empty:       # 确保y的索引与extracted_features的索引对齐       # (tsfresh的extract_features返回的DataFrame的索引是column_id的值)       if not y_series.empty:           try:               # select_features expects y to be aligned with X's index (which are the IDs)               selected_features_df = select_features(extracted_features, y_series)               print("\n经过特征选择后的特征矩阵 (部分特征):")               print(selected_features_df.head())               print(f"筛选后的特征数量: {selected_features_df.shape}")           except Exception as e:               print(f"\n特征选择过程中发生错误: {e}")               print("可能是由于目标变量y与特征矩阵不匹配或y中NaN值过多导致。")       else:           print("\n目标变量y为空，跳过特征选择。")   else:       print("\n未提取到特征，跳过特征选择。")      # 示例：提取特定类型的特征，例如FFT系数   # settings = ComprehensiveFCParameters()   # fft_settings = { "fft_coefficient": [{"coeff": i, "attr": "real"} for i in range(5)]}   # specific_extracted_features = extract_features(timeseries_df,   #                                                column_id='id',   #                                                column_sort='time',   #                                                column_value='value',   #                                                kind_to_fc_parameters=fft_settings, # Use kind_to_fc_parameters for specific features   #                                                impute_function=impute,   #                                                show_warnings=False)   # print("\n仅提取FFT系数特征 (前5个实部):")   # print(specific_extracted_features.head())   `
    

-   3.2. featuretools：用于时间序列的自动化深度特征合成
    
    featuretools是一个开源Python库，旨在自动化特征工程过程，特别是通过其核心的深度特征合成（Deep Feature Synthesis, DFS）算法。虽然它最初主要针对关系型和事务型数据集设计，但也为时间序列问题提供了专门的支持。
    

-   深度特征合成 (DFS) 概念： DFS通过在数据中的实体及其关系之上迭代地应用数学运算（称为“原语”，primitives）来自动创建新的特征。这些原语可以是聚合函数（如SUM、MEAN）、转换函数（如ABSOLUTE、DIFFERENCE）或专门为特定数据类型（如时间序列）设计的函数。
    
-   时间序列原语： 针对时间序列问题，featuretools提供了一系列专门的原语：
    

-   **日期时间转换原语 (Datetime Transform Primitives)：** 这些原语直接从时间索引中提取特征，例如“Day”（日期中的天数）、“Year”（年份）、“Weekday”（星期几）、“Month”（月份）等。它们对于捕捉与时间相关的周期性模式（如一年中的月份对温度的影响）非常有用。
    

-   **滞后原语 (Delaying Primitives)：** 主要通过Lag原语实现，用于创建目标列或其他数值列的滞后版本。这些特征表示过去某个时间点的值，对于时间序列预测至关重要。
    

-   **滚动转换原语 (Rolling Transform Primitives)：** 这些原语在一个定义好的滚动窗口内对值进行聚合，例如RollingMean（滚动均值）、RollingMin（滚动最小值）、RollingMax（滚动最大值）、RollingStd（滚动标准差）等。它们有助于捕捉时间序列的局部动态特性。
    

-   时间序列核心机制： 对于单表时间序列数据集（即所有数据都在一个表中，包含时间索引和目标列），featuretools的特征工程窗口从当前时间点向后（即过去）扩展。两个关键参数定义了这个窗口：
    

-   gap：表示当前时间点t与特征工程窗口最早可访问数据点之间的时间间隔。例如，gap=7（假设数据是日度的）意味着最早可用的数据是7天前的数据 (t−7)。在时间序列问题中，应避免gap=0，因为它可能导致目标变量的直接泄露。
    

-   window\_length：定义了从t−gap开始，特征工程窗口向过去延伸多长时间。例如，window\_length=5表示featuretools将查看这5天的数据进行特征计算。 这些参数通常用整数表示，暗示数据是等间隔采样的。
    

  

-   配置与应用： 使用featuretools通常首先需要从Pandas DataFrame创建一个EntitySet对象，该对象定义了数据中的实体（表）及其关系。然后，通过ft.dfs()函数，指定目标实体（表）、要应用的原语以及其他参数（如cutoff\_time用于确保训练/测试数据分割的正确性），来生成特征矩阵。
    
-   优势： featuretools能够显著减少手动创建和选择特征所需的时间，尤其擅长从数据中自动发现复杂的时序模式和关系。它为时间序列数据提供了良好的支持，并且拥有用户友好的接口和完善的文档。
    
-   **代码示例：使用featuretools为时间序列数据集生成特征**
    
    Python
    
    `import featuretools as ft   import pandas as pd   import numpy as np      # 1. 创建一个示例时间序列DataFrame   # 包含id, 时间索引 (Date), 和目标值 (Temp)   data = {       'id': range(20),       'Date': pd.to_datetime(['1981-01-01', '1981-01-02', '1981-01-03', '1981-01-04', '1981-01-05',                               '1981-01-06', '1981-01-07', '1981-01-08', '1981-01-09', '1981-01-10',                               '1981-01-11', '1981-01-12', '1981-01-13', '1981-01-14', '1981-01-15',                               '1981-01-16', '1981-01-17', '1981-01-18', '1981-01-19', '1981-01-20']),       'Temp': [20.7, 17.9, 18.8, 14.6, 15.8, 15.8, 15.8, 17.4, 21.8, 20.0,                16.2, 13.3, 16.7, 21.5, 25.0, 23.0, 21.5, 19.0, 18.5, 20.5]   }   temperatures_df = pd.DataFrame(data)   print("原始温度DataFrame (前5行):")   print(temperatures_df.head())   print("-" * 30)      # 2. 创建EntitySet并添加DataFrame   es = ft.EntitySet(id="weather_data")   es = es.add_dataframe(       dataframe_name="temperatures",       dataframe=temperatures_df,       index="id", # 唯一标识符列       time_index="Date"# 时间索引列   )   print("\nEntitySet 结构:")   print(es)   print("-" * 30)      # 3. 定义gap和window_length (以天为单位)   # 假设我们预测第二天的温度，所以gap至少为1天。   # 为了避免直接使用当天的信息，我们将gap设为1天。   # window_length设为3天，表示看过去3天的数据。   # Featuretools的gap定义为不包含当前点，所以t-gap是窗口的结束点。   # 例如，对于1月5日的数据，gap=1, window_length=3，窗口是[1月1日, 1月2日, 1月3日, 1月4日]   # Lag原语的periods参数是相对于当前行的偏移。   # Rolling原语的gap参数是从当前时间点回溯多少单位开始计算窗口。      # 4. 指定时间序列原语   # 日期时间转换原语   datetime_primitives = ["month", "weekday", "day"]      # 滞后原语 (例如，获取1天前和2天前的温度)   # 注意：Featuretools的Lag原语的periods参数是直接的滞后周期。   # 为了避免数据泄露，通常在DFS的cutoff_time参数中控制。   # 对于单表时间序列，更常见的是使用滚动原语，并配合gap参数。   # 此处我们使用滚动原语来演示滞后和窗口聚合。      # 滚动转换原语   # gap=1天，window_length=3天，表示窗口从t-1天开始，包含t-1, t-2, t-3三天的数据   # min_periods确保窗口中有足够数据点才计算   rolling_mean_primitive = ft.primitives.RollingMean(window_length="3d", gap="1d", min_periods=1)   rolling_std_primitive = ft.primitives.RollingSTD(window_length="3d", gap="1d", min_periods=1)   rolling_max_primitive = ft.primitives.RollingMax(window_length="3d", gap="1d", min_periods=1)         # 也可以创建滞后特征，例如直接使用Lag原语   # lag_primitive_t1 = ft.primitives.Lag(periods=1, time_index='Date', entity_id_col='id')   # (注意：Lag原语在单表时间序列中需要小心使用，确保cutoff_time正确设置)      # 5. 运行DFS生成特征矩阵   # target_dataframe_name指定了我们希望为其生成特征的DataFrame   # cutoff_time对于时间序列问题非常重要，它定义了每个训练样本的“最后已知时间点”。   # DFS只会使用在该cutoff_time之前的数据来计算特征。   # 为了演示，我们假设为temperatures_df中的每个点计算特征，   # 并且特征是基于该点之前的数据计算的。   # cutoff_time_df 可以用来为每个实例指定不同的截止时间。   # 如果不提供cutoff_time_df，DFS会为target_dataframe中的每个实例计算特征，   # 假设所有数据在计算时都是可用的（这对于回测或历史特征生成是合适的）。   # 对于预测任务，通常会设置cutoff_time为预测点之前的时间。      # 为了简单演示，我们为整个表生成特征，假设我们正在为每个点创建历史特征   feature_matrix, feature_defs = ft.dfs(       entityset=es,       target_dataframe_name="temperatures",       agg_primitives=[], # 单表时间序列通常不使用聚合原语       trans_primitives=datetime_primitives + \                        [rolling_mean_primitive, rolling_std_primitive, rolling_max_primitive],       # max_depth=1 # 控制特征的复杂度       # cutoff_time = temperatures_df[['id', 'Date']] # Example for cutoff_time   )      print("\n生成的特征矩阵 (部分列，前10行):")   # 选择一些有代表性的列进行展示   # The actual column names will be generated by featuretools   # For example: 'MONTH(Date)', 'WEEKDAY(Date)', 'DAY(Date)',   # 'ROLLING_MEAN(Temp, window_length=3d, gap=1d, min_periods=1)'   # We'll try to pick some, but they might vary based on exact version/settings   cols_to_show = [col for col in feature_matrix.columns if'ROLLING'in col.upper() or col in ['Temp', 'MONTH(Date)', 'WEEKDAY(Date)', 'DAY(Date)']]   if not cols_to_show: # if no specific columns found, show first few       cols_to_show = feature_matrix.columns[:5].tolist()   else:       cols_to_show = cols_to_show[:7] # Limit to a few columns      print(feature_matrix[cols_to_show].head(10))   print(f"\n总共生成的特征数量: {feature_matrix.shape}")      # 打印一些特征定义   # print("\n部分特征定义:")   # for i in range(min(5, len(feature_defs))):   #     print(feature_defs[i])   `
    

-   3.3. Kats (Facebook时间序列分析工具包):
    
    Kats 是由Facebook（现Meta）开发的一个轻量级、易用且可泛化的时间序列分析工具包，旨在提供一站式的时间序列分析解决方案，包括检测、预测、特征提取/嵌入、多元分析等。
    

-   TsFeatures模块概述： Kats中的TsFeatures模块专门用于从时间序列数据中提取有意义的统计特征。该模块据称可以生成65种特征（尽管在提供的资料中，默认提取约40种，另有28种可选特征），这些特征具有明确的统计定义，可以直接用于大多数机器学习模型（如分类和回归模型）的训练。
    
-   关键可提取特征： TsFeatures模块可以提取多种类型的特征，全面描述时间序列的特性：
    

-   基础统计特征： 长度 (length)、均值 (mean)、方差 (var)。
    

-   **STL分解特征：** 基于STL (Seasonal and Trend decomposition using Loess) 分解，提取季节性强度 (trend\_strength)、趋势强度 (seasonality\_strength)、尖峰度 (spikiness)、线性度 (linearity)、峰谷值 (peak, trough) 等。
    

-   **ACF/PACF特征：** 包括原始序列、一阶差分序列和二阶差分序列的自相关系数（如y\_acf1, y\_acf5）和偏自相关系数（如y\_pacf5），以及季节性ACF/PACF（如seas\_acf1, seas\_pacf1）。
    

-   **Hurst指数：** 衡量时间序列的长期记忆性或自相似性。
    

-   **ARCH统计量：** 基于Engle的拉格朗日乘数（LM）检验，用于检测自回归条件异方差性，返回LM检验统计量 (get\_het\_arch)。
    

-   **水平漂移特征 (Level Shift Features)：** 包括最大水平漂移发生的位置 (level\_shift\_idx) 和幅度 (level\_shift\_size)，通过比较滑动窗口间的均值差异计算得到。
    

-   其他时序特性：
    

-   熵 (entropy，基于功率谱密度的香农熵)。
    

-   块度 (lumpiness，块内方差的方差) 和稳定性 (stability，块内均值的方差)。
    

-   平坦点 (flat\_spots，序列中值不变的连续段的最大长度)。
    

-   过零点/过中位点数 (crossing\_points)。
    

-   均值二值化 (binarize\_mean，高于均值为1，低于为0，取平均)。
    

-   单位根检验统计量 (如KPSS检验的unitroot\_kpss)。
    

-   一阶导数的标准差 (std1st\_der)。
    

-   特殊自相关特征 (special\_ac)：如ACF首次达到最小值的时滞 (firstmin\_ac) 和ACF首次穿过零点的时滞 (firstzero\_ac)。
    

-   基于检测器的特征：
    
    Kats集成了其内部的检测算法来生成特征：
    

-   CUSUM检测器 (cusum\_detector): 检测突变点，输出特征如突变点数量、置信度、位置、突变前后均值差、对数似然比等。
    

-   BOCP检测器 (bocp\_detector): 贝叶斯在线变点检测，输出特征如变点数量、最大置信度、平均置信度。
    

-   鲁棒统计检测器 (robust\_stat\_detector): 输出特征如变点数量、统计指标的均值。
    

-   异常点检测器 (outlier\_detector): 输出异常点数量。
    

-   趋势检测器 (trend\_detector): 输出趋势数量、上升趋势数量、检测到趋势的Tau统计量绝对值的均值。
    

-   基于模型的特征：
    

-   Holt-Winters模型参数 (hw\_params): 如平滑参数alpha, beta, gamma。
    

-   Holt模型参数 (holt\_params)。
    

-   **Nowcasting特征：** 基于金融领域的技术指标，如变化率(ROC)、移动平均(MA)、动量(MOM)、滞后(LAG)、MACD指标及其信号线和差值 (macd, macdsign, macddiff)的均值。
    
-   **季节性特征 (seasonalities):** 运行季节性检测器估计季节周期，并提取趋势、季节性和残差的幅度。
    
      
    
-   用法与配置： Kats的TsFeatures模块要求输入数据为kats.consts.TimeSeriesData对象格式，该对象通常由Pandas DataFrame转换而来，DataFrame需要包含时间和值两列。特征提取主要通过实例化TsFeatures类后调用其.transform()方法完成。在初始化TsFeatures时，可以通过设置布尔型参数（如stl\_features=False, acfpacf\_features=True）来选择启用或禁用特定的特征组或单个特征的计算。feature\_group\_mapping属性揭示了哪些特征是捆绑计算的。
    
-   **代码示例：使用Kats.TsFeatures提取特征**
    
    Python
    
    `import pandas as pd   import numpy as np   from kats.consts import TimeSeriesData   from kats.tsfeatures.tsfeatures import TsFeatures   import pprint # For pretty printing the feature group mapping      # 1. 准备时间序列数据 (Kats的TimeSeriesData格式)   # 假设我们有一个Pandas DataFrame   time_data = pd.to_datetime(pd.date_range(start='2023-01-01', periods=100, freq='D'))   value_data = np.random.rand(100) * 10 + np.arange(100) * 0.5 # 趋势 + 随机性   df = pd.DataFrame({'time': time_data, 'value': value_data})      print("原始Pandas DataFrame (前5行):")   print(df.head())   print("-" * 30)      # 转换为TimeSeriesData对象   ts_data = TimeSeriesData(df)      # 2. 初始化TsFeatures   # 默认情况下会计算大约40个特征   ts_features_calculator = TsFeatures()      # 也可以选择性地开启或关闭特定特征组的计算   # 例如，关闭STL特征，开启ACF/PACF特征 (默认可能已开启部分)   # ts_features_calculator_custom = TsFeatures(stl_features=False, acfpacf_features=True)      # 也可以通过 selected_features 参数指定想要计算的特征子集   # selected_features_list = ["mean", "var", "length", "y_acf1"]   # ts_features_calculator_selected = TsFeatures(selected_features=selected_features_list)      # 3. 调用.transform() 方法提取特征   # 对于单个时间序列，返回一个包含特征名和特征值的字典   extracted_kats_features = ts_features_calculator.transform(ts_data)      print("\n使用Kats提取的特征 (部分展示):")   # 打印前10个特征作为示例   count = 0   for feature_name, feature_value in extracted_kats_features.items():       print(f"{feature_name}: {feature_value}")       count += 1       if count >= 10:           break   print(f"... 以及其他 {len(extracted_kats_features) - count} 个特征。")   print("-" * 30)      # 查看可用的特征组 (可以通过设置这些组为False来禁用它们)   # print("\nKats特征组映射:")   # pprint.pprint(ts_features_calculator.feature_group_mapping)   `
    

-   3.4. sktime：统一的时间序列机器学习框架
    
    sktime是一个为时间序列分析提供统一API的Python库，其设计目标是覆盖包括预测、分类、聚类和转换在内的多种时间序列机器学习任务，并遵循scikit-learn的接口约定，便于集成和使用。
    

-   基于转换器 (Transformer) 的架构： 在sktime中，特征提取主要通过其转换器 (transformers) 实现。这些转换器是模块化的数据处理步骤，与scikit-learn中的转换器类似：它们通过fit(data)方法拟合数据（学习转换所需的参数），然后通过transform(X)方法将学习到的转换应用于新的数据批次。部分转换器还可能提供inverse\_transform(X)方法（如果转换是可逆的）。sktime.transformations模块包含了各种用于数据转换的类，这些类可以根据其输入输出类型进行分类，例如“序列到特征”(series-to-features)、“序列到序列”(series-to-series)等。
    
-   关键的特征提取转换器 (Series-to-Features)： sktime提供了大量将单个时间序列转换为一组原始特征（通常是浮点数或类别向量）的转换器。当应用于面板数据（时间序列的集合）时，结果通常是一个表格，每行对应输入面板中的一个时间序列。
    
-   摘要统计 (Summarization)：
    

-   SummaryTransformer: 从时间序列中提取样本统计量，如均值、标准差、最小值、最大值和多个分位数，输出一个包含这些统计量的pd.DataFrame。
    

-   WindowSummarizer: 基于滚动或扩展窗口提取特征，支持多种聚合函数（如滞后值、均值、标准差等），可以应用于指定的目标列。
    

-   卷积/Shapelet相关：
    

-   ShapeletTransform: 基于时间序列“形态小片段”(shapelets)进行特征提取。Shapelets是具有代表性的子序列，该转换器计算输入序列到一组（学习到的或挖掘出的）shapelets的距离作为特征。
    

-   ROCKET, MiniRocket, MultiRocket: 这些是高效且强大的转换器，它们使用大量随机生成的卷积核来转换时间序列。从每个卷积核的输出（特征图）中，通常提取两个特征：最大值 (max pooling) 和正值比例 (proportion of positive values, PPV)。
    

-   基于距离的特征：
    

-   MatrixProfileTransformer (包装了stumpy库的功能) 或 MatrixProfile (用于面板数据): 计算时间序列的矩阵轮廓。矩阵轮廓是一个向量，存储了序列中每个子序列到其最近邻子序列的z归一化欧氏距离。
    

-   基于字典的特征 (Dictionary-based)：
    

-   SFA (Symbolic Fourier Approximation): 通过离散傅里叶变换(DFT)将时间序列转换到频域，然后对傅里叶系数进行分箱（量化）得到符号表示。
    

-   SAX (Symbolic Aggregate approXimation): 通常先通过PAA (Piecewise Aggregate Approximation)对时间序列进行分段聚合（取均值），然后对聚合值进行符号化。sktime中提到了PAAlegacy和SAXlegacy。
    

-   特征集合 (Feature Collections)：
    

-   TSFreshFeatureExtractor: 这是一个包装器，可以直接在sktime流程中使用tsfresh库的功能来提取大量特征。用户可以指定tsfresh的特征计算参数，如default\_fc\_parameters（例如，"minimal", "efficient", "comprehensive"）或kind\_to\_fc\_parameters。
    

-   Catch22: 提取一组22个经过精心挑选的“规范化时间序列特征”(Canonical Time-series Characteristics)。这些特征是从hctsa工具箱中的数千个特征中筛选出来的，旨在兼具良好的分类性能、计算效率和可解释性。
    

-     
    

-   生成特征的性质与用法： 生成的特征类型因转换器而异，可以是统计摘要、符号序列、距离值或卷积特征等。许多“序列到特征”的转换器输出一个Pandas DataFrame，其中行对应输入的各个时间序列，列则对应提取出的不同特征。这些特征可以直接用于后续的机器学习模型训练。
    
-   **代码示例：演示WindowSummarizer、ROCKET、MatrixProfileTransformer、SFA和Catch22**
    
    Python
    
    `import pandas as pd   import numpy as np   from sktime.datasets import load_airline, load_arrow_head, load_longley, load_italy_power_demand   from sktime.forecasting.model_selection import temporal_train_test_split   from sktime.utils.plotting import plot_series      # 准备一些示例数据   y_airline = load_airline()   X_arrowhead, y_arrowhead = load_arrow_head(return_X_y=True) # Panel data   y_longley, X_longley_exog = load_longley() # y_longley is Series, X_longley_exog is DataFrame of exogenous vars   X_ipd_train, y_ipd_train = load_italy_power_demand(split="train", return_X_y=True) # Panel data      # 1. WindowSummarizer 示例   print("\n--- WindowSummarizer 示例 ---")   from sktime.transformations.series.summarize import WindowSummarizer      # 定义窗口和聚合函数：例如，计算过去3期和过去5期的均值和标准差作为滞后特征   # lag_feature 的键是pandas支持的滚动窗口函数名或自定义函数   # 值是一个包含[lag, window_length]对的列表，或单个整数表示滞后   kwargs = {       "lag_feature": {           "mean": [[1, 3], [1, 5]], # lag 1, window 3; lag 1, window 5           "std": [[1, 3], [1, 5]],           "lag": [1, 2, 3]  # 直接滞后值       }   }   # target_cols 指定对哪些列进行转换，如果X是多变量的   # 这里使用y_longley(Series)作为示例，WindowSummarizer通常用于DataFrame中的列   # 为了演示，我们将y_longley转换为DataFrame   y_longley_df = y_longley.to_frame(name='value') # Ensure it has a name for target_cols if not default      # WindowSummarizer is designed for DataFrame input X.   # If y_longley_df only has one column, target_cols doesn't strictly need to be set.   summarizer = WindowSummarizer(**kwargs, n_jobs=1)   summarizer.fit(y_longley_df) # 拟合   y_longley_transformed = summarizer.transform(y_longley_df)   print("WindowSummarizer 转换结果 (前5行，部分列):")   print(y_longley_transformed.head())   print("-" * 30)      # 2. ROCKET 示例   print("\n--- ROCKET 示例 ---")   from sktime.transformations.panel.rocket import Rocket   # ROCKET 通常用于面板数据 (多个时间序列实例)   # X_arrowhead is a Panel data (Pandas DataFrame where each cell is a Series)   rocket_transformer = Rocket(num_kernels=1000) # 减少核数量以加快示例运行   rocket_transformer.fit(X_arrowhead.iloc[:10]) # 使用部分数据拟合   X_arrowhead_transformed = rocket_transformer.transform(X_arrowhead.iloc[:10])   print("ROCKET 转换结果 (形状):", X_arrowhead_transformed.shape)   print("ROCKET 转换结果 (前2行，前5列):")   print(X_arrowhead_transformed.iloc[:2, :5])   print("-" * 30)      # 3. MatrixProfileTransformer 示例   print("\n--- MatrixProfileTransformer 示例 ---")   from sktime.transformations.series.matrix_profile import MatrixProfileTransformer   mp_transformer = MatrixProfileTransformer(window_length=12) # 窗口长度   y_airline_mp = mp_transformer.fit_transform(y_airline)   print("MatrixProfileTransformer 转换结果 (前5行):")   print(y_airline_mp.head()) # Output is a DataFrame with matrix profile and index   print("-" * 30)      # 4. SFA (Symbolic Fourier Approximation) 示例   print("\n--- SFA 示例 ---")   from sktime.transformations.panel.dictionary_based import SFA   # SFA 通常用于面板数据   sfa_transformer = SFA(word_length=8, alphabet_size=4, window_size=10) # 示例参数   sfa_transformer.fit(X_arrowhead.iloc[:10])   X_arrowhead_sfa = sfa_transformer.transform(X_arrowhead.iloc[:10])   print("SFA 转换结果 (形状):", X_arrowhead_sfa.shape) # 输出是每个序列的SFA词袋表示   print("SFA 转换结果 (前2行，前10列):")   print(X_arrowhead_sfa.iloc[:2, :10])   print("-" * 30)      # 5. Catch22 示例   print("\n--- Catch22 示例 ---")   from sktime.transformations.panel.catch22 import Catch22   catch22_transformer = Catch22()   # Catch22 通常用于面板数据，这里使用意大利电力需求数据集的一个实例   # X_ipd_train is a Pandas DataFrame, where each row is a series, each cell contains a pd.Series   catch22_transformer.fit(X_ipd_train.iloc[:5]) # 使用前5个序列拟合   X_ipd_catch22 = catch22_transformer.transform(X_ipd_train.iloc[:5])   print("Catch22 转换结果 (形状):", X_ipd_catch22.shape) # 应为 (n_instances, 22)   print("Catch22 转换结果 (前2行):")   print(X_ipd_catch22.head(2))   print("-" * 30)   `
    

-   3.5. Darts：用户友好的预测与特征工程
    
    Darts是一个以易用性著称的Python库，主要用于时间序列预测和异常检测，它支持从经典统计模型（如ARIMA）到深度学习模型（如RNN、Transformer）的多种算法。虽然其核心功能是预测，但Darts也提供了一系列用于数据预处理和特征工程的实用工具，这些工具生成的特征通常作为协变量 (covariates) 输入到其预测模型中。
    

-   **使用add\_encoders生成基于时间的协变量： 许多Darts的预测模型，特别是基于PyTorch的TorchForecastingModel以及RegressionModel，接受一个名为add\_encoders的参数。这个参数允许用户方便地自动生成基于时间索引的特征，并将它们作为过去协变量 (past\_covariates) 或未来协变量 (future\_covariates) 添加到模型中。**
    

-   **编码器类型：** Darts提供了多种编码器，如CyclicTemporalEncoder（用于将月份、星期几等周期性属性编码为正弦和余弦分量）、DatetimeAttributeEncoder（用于提取年份、小时等标量时间属性）、IntegerIndexEncoder（用于生成相对位置索引）以及CallableIndexEncoder（允许用户提供自定义函数来编码时间索引）。
    

-   **配置：** add\_encoders参数通常接收一个字典，指定要使用的编码器类型、目标协变量类型（过去或未来）以及要编码的时间属性。例如，可以指定将“月份”编码为未来的周期性协变量，将“星期几”编码为未来的日期时间属性协变量。还可以包含一个Scaler（如darts.dataprocessing.transformers.Scaler）对生成的协变量进行缩放。
    

-   使用WindowTransformer创建滚动窗口特征： darts.dataprocessing.transformers.WindowTransformer类用于对时间序列应用窗口转换，从而创建滚动窗口特征。
    

-   功能： 它可以接受一个或多个转换函数的定义，这些函数将应用于滑动窗口。支持的函数包括Pandas内置的滚动/扩展窗口函数（如"mean", "std", "sum", "min", "max"）或用户自定义的函数。
    

-   **配置：** 每个转换在字典中定义，包含"function"（函数名或可调用对象）、"mode"（如"rolling", "expanding", "ewm"）、"window"（窗口大小）以及其他传递给Pandas相应窗口函数的参数（如"min\_periods", "center"）。
    

-   **应用：** 生成的滚动统计量（如滚动均值、滚动标准差）可以作为协变量输入到预测模型中，帮助模型捕捉时间序列的局部动态。
    

-   其他预处理功能： Darts的TimeSeries对象本身也支持一些基础的转换操作，如.diff()（差分）、.map()（应用自定义函数）、.add\_datetime\_attribute()（添加日期时间属性作为新维度）、.add\_holidays()（添加假期指示器作为新维度）。此外，库中还包含了缺失值填充和数据缩放等预处理工具。
    
-   **代码示例：使用add\_encoders和WindowTransformer进行特征创建**
    
    Python
    
    `import pandas as pd   import numpy as np   from darts import TimeSeries   from darts.dataprocessing.transformers import Scaler, WindowTransformer   # 假设有一个TorchForecastingModel (这里用一个占位符，实际使用时替换为具体的Darts模型)   from darts.models.forecasting.linear_regression_model import LinearRegressionModel   # (LinearRegressionModel支持lags, lags_past_covariates, lags_future_covariates, 但不直接用add_encoders)   # 对于支持add_encoders的模型，例如NBEATSModel:   from darts.models import NBEATSModel      # --- 示例1: 使用 add_encoders 生成时间协变量 ---   print("--- add_encoders 示例 ---")   # 创建一个示例目标时间序列   data_length = 200   time_idx = pd.date_range(start='2022-01-01', periods=data_length, freq='H')   values = np.random.randn(data_length).cumsum() + \            np.sin(np.linspace(0, 20 * np.pi, data_length)) * 5 # 趋势 + 季节性   target_series_for_encoders = TimeSeries.from_times_and_values(time_idx, values)      # 定义add_encoders字典   # 这将被传递给支持此参数的Darts模型 (如NBEATSModel, TFTModel等)   add_encoders_dict = {       'cyclic': {'future': ['month', 'dayofweek']}, # 月份和星期几作为未来周期性协变量       'datetime_attribute': {'future': ['hour', 'day']}, # 小时和天作为未来日期时间属性协变量       # 'position': {'past': ['relative'], 'future': ['relative']}, # 相对位置       'transformer': Scaler(), # 对所有生成的协变量应用Scaler       'tz': 'UTC'# 假设时间戳是UTC   }      # 初始化一个支持add_encoders的模型 (例如NBEATSModel)   # 注意：实际训练需要更多参数和数据   model_with_encoders = NBEATSModel(       input_chunk_length=24, # 模型回看窗口       output_chunk_length=12, # 模型预测长度       n_epochs=1, # 仅为快速演示       add_encoders=add_encoders_dict,       random_state=42   )      # 在模型拟合(fit)和预测(predict)时，这些协变量会自动生成和使用   # 这里不执行实际的fit/predict，仅为说明add_encoders的用法   print(f"为NBEATSModel配置的add_encoders: {model_with_encoders.add_encoders}")   # 当调用 model_with_encoders.fit(target_series_for_encoders) 时，   # Darts的内部机制会使用SequentialEncoder根据add_encoders_dict生成协变量。   print("当模型拟合时，Darts会自动根据add_encoders生成并使用协变量。")   print("-" * 30)      # --- 示例2: 使用 WindowTransformer 创建滚动窗口特征 ---   print("\n--- WindowTransformer 示例 ---")   # 创建一个简单的时间序列   values_wt = np.array([10, 12, 11, 15, 13, 14, 16, 18, 17, 20.0]) # Added .0 to make it float for std   series_wt = TimeSeries.from_values(values_wt)      # 定义滚动均值和滚动标准差的转换   rolling_mean_transform_wt = {       "function": "mean",  # 计算均值       "mode": "rolling",   # 滚动窗口模式       "window": 3,         # 窗口大小为3       "min_periods": 1     # 即使窗口数据不足3个也计算   }      rolling_std_transform_wt = {       "function": "std",       "mode": "rolling",       "window": 3,       "min_periods": 1,       "components": "rolling_std_custom"# 自定义输出特征的名称部分   }      # 实例化WindowTransformer   # keep_non_transformed=True 会保留原始序列   # forecasting_safe=True (默认) 确保不会使用未来信息   window_transformer = WindowTransformer(       transforms=[rolling_mean_transform_wt, rolling_std_transform_wt],       keep_non_transformed=True,       treat_na="bfill"# 用后面的有效值填充开头的NaN   )      # 应用转换   transformed_series_wt = window_transformer.fit_transform(series_wt) # fit_transform for transformers      print("原始序列:")   print(series_wt.pd_dataframe().T)   print("\nWindowTransformer转换后的序列 (包含滚动均值和滚动标准差):")   print(transformed_series_wt.pd_dataframe())   print("\n转换后序列的组件名称:")   print(transformed_series_wt.components)      # 这些转换后的序列 (transformed_series_wt) 可以作为协变量输入到Darts模型中   # 例如: model.fit(target_series, past_covariates=transformed_series_wt)   # (需要确保target_series和transformed_series_wt的时间索引和长度对齐)   print("-" * 30)   `
    

  

篇幅有限，敬请期待下篇。

更多资源见星球，加入QuantML星球，与星主和850+专业人士一起交流学习：

![图片](assets/001.webp)