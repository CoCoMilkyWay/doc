# Python时间序列特征提取库的工具、技术与应用（下）

QuantML QuantML 2025-05-27 18:28 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490493&idx=1&sn=5ba72e3d08da86503b43e6e32c5f8d30&chksm=cfc4ff43c4248e3064d443fdb6b2b960cd83e9ab2a7c54f6ce6c9fd7d4fc8f7aeda3c8998baa#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490493&idx=1&sn=5ba72e3d08da86503b43e6e32c5f8d30&chksm=cfc4ff43c4248e3064d443fdb6b2b960cd83e9ab2a7c54f6ce6c9fd7d4fc8f7aeda3c8998baa#rd)

承接上篇[Python时间序列特征提取库的工具、技术与应用（上）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490489&idx=1&sn=737aff09198cbf5fda753d9688847d06&scene=21#wechat_redirect)

-   3.6. tslearn：面向时间序列的机器学习
    
    tslearn是一个专注于时间序列机器学习的Python包，提供了预处理、特征提取、分类、聚类和回归等多种工具。该库的设计遵循scikit-learn的API规范，使得用户可以方便地将其组件集成到标准的机器学习工作流中，例如使用scikit-learn的流水线 (Pipelines) 和模型选择工具。
    

-   预处理工具： tslearn.preprocessing模块包含了一些针对时间序列的预处理类：
    

-   TimeSeriesScalerMinMax: 将每个时间序列的每个维度缩放到一个指定的值域（默认为\[0,1\]）。
    

-   TimeSeriesScalerMeanVariance: 对每个时间序列的每个维度进行标准化，使其均值为0，标准差为1。
    

-   TimeSeriesResampler: 用于将时间序列重采样到指定的长度。
    

-   特征提取方法 (主要来自 tslearn.piecewise 和 tslearn.shapelets 模块)： tslearn提供了一些独特的特征提取方法，特别是在符号化表示和基于形态的特征方面：
    

-   **PiecewiseAggregateApproximation (PAA)：** PAA是一种降维技术，它将时间序列分割成等长的连续段，并用每段内数据的均值来代表该段。这能有效减少数据点的数量，同时保留序列的整体形状。
    

-   **SymbolicAggregateApproximation (SAX)：** SAX在PAA的基础上进一步发展，它将PAA得到的各段均值进行量化（离散化），映射为预定义字母表中的符号。SAX转换后的序列是一串符号，便于进行模式挖掘和相似性度量。通常，量化边界的选取是为了保证在标准正态分布假设下，每个符号出现的概率大致相等。
    

-   **OneD\_SymbolicAggregateApproximation (1d-SAX)：** 1d-SAX是SAX的一种扩展，它不仅考虑每段的均值，还考虑其斜率。每段被近似为一个线性函数，然后对均值和斜率分别进行符号化。
    

-   Shapelet方法 (LearningShapelets, ShapeletTransformer)：
    
    Shapelets是被定义为“在某种意义上最能代表某个类别的时间子序列”。
    

-   LearningShapelets模型在训练过程中学习一组具有区分性的shapelets。学习的目标通常是使得时间序列在其到这些shapelets的距离空间中线性可分。
    

-   一旦shapelets被学习或定义，transform方法会将每个输入时间序列转换为一个特征向量，向量的每个元素是该时间序列到对应shapelet的最小距离。这些距离值随后可用于分类、聚类等任务。
    

-   提取特征的特性：
    

-   PAA、SAX和1d-SAX生成的特征是时间序列的低维、通常是符号化的表示。这些表示对于数据压缩、索引、相似性搜索和模式发现（如motif discovery）非常有用，也可以直接作为特征输入到某些机器学习模型中。
    

-   基于Shapelet的特征是距离值，它们量化了输入时间序列与学习到的关键模式（shapelets）的相似程度。
    

-   **代码示例：使用tslearn进行PAA、SAX和Shapelet特征提取**
    
    Python
    
    `import numpy as np   import matplotlib.pyplot as plt   from tslearn.generators import random_walk_blobs   from tslearn.preprocessing import TimeSeriesScalerMinMax   from tslearn.piecewise import PiecewiseAggregateApproximation, SymbolicAggregateApproximation   from tslearn.shapelets import LearningShapelets, grabocka_params_to_shapelet_size_dict      # 0. 生成一些示例时间序列数据   n_ts_per_blob, sz, d, n_blobs = 20, 100, 1, 3 # 20个序列/簇, 长度100, 1维, 3个簇   X_example, y_example = random_walk_blobs(n_ts_per_blob=n_ts_per_blob, sz=sz, d=d, n_blobs=n_blobs, random_state=42)      # 对数据进行缩放，这对于许多算法（包括Shapelets）很重要   X_scaled = TimeSeriesScalerMinMax().fit_transform(X_example)   print(f"原始数据形状: {X_scaled.shape}") # (n_ts, sz, d)   print("-" * 30)      # 1. PAA (Piecewise Aggregate Approximation) 示例   print("--- PAA 示例 ---")   n_paa_segments = 10 # 将序列缩减为10段   paa_transformer = PiecewiseAggregateApproximation(n_segments=n_paa_segments)   X_paa = paa_transformer.fit_transform(X_scaled)   print(f"PAA转换后数据形状: {X_paa.shape}") # (n_ts, n_paa_segments, d)   print("第一个序列的PAA表示 (前5段):")   print(X_paa[0, :5, 0])      # 可以将PAA结果逆转换为近似的原始长度序列 (用于可视化)   # X_paa_inv = paa_transformer.inverse_transform(X_paa)   print("-" * 30)      # 2. SAX (Symbolic Aggregate Approximation) 示例   print("\n--- SAX 示例 ---")   n_sax_symbols = 8 # 字母表大小   sax_transformer = SymbolicAggregateApproximation(n_segments=n_paa_segments, alphabet_size_avg=n_sax_symbols)   X_sax = sax_transformer.fit_transform(X_scaled) # SAX内部会执行PAA   print(f"SAX转换后数据形状: {X_sax.shape}") # (n_ts, n_paa_segments, d), 值为整数符号   print("第一个序列的SAX表示 (符号):")   print(X_sax[0, :, 0])      # SAX的输出是整数索引，代表符号。   # 也可以逆转换为近似的原始长度序列 (用于可视化，但会丢失符号信息)   # X_sax_inv = sax_transformer.inverse_transform(X_sax)   print("-" * 30)      # 3. LearningShapelets 示例 (用于分类任务的特征提取)   print("\n--- LearningShapelets 示例 ---")   # 定义shapelet的长度和数量   # 例如，学习5个长度为15的shapelets   # shapelet_sizes is a dict: {length: n_shapelets_of_this_length}   shapelet_sizes = grabocka_params_to_shapelet_size_dict(n_ts=X_scaled.shape[0],                                                          ts_sz=X_scaled.shape[1],                                                          n_classes=len(set(y_example)),                                                          l=0.1, # fraction of time series length                                                          r=1)  # number of shapelets per length   if not shapelet_sizes: # if grabocka returns empty, provide a default       shapelet_sizes = {15:5}         shapelet_clf = LearningShapelets(       n_shapelets_per_size=shapelet_sizes,       max_iter=50, # 迭代次数，实际应用中可能需要更多       verbose=0,   # 不打印训练过程       random_state=42   )      # 拟合模型 (学习shapelets)   shapelet_clf.fit(X_scaled, y_example)      # 获取学习到的shapelets   learned_shapelets_ts = shapelet_clf.shapelets_as_time_series_   print(f"学习到的Shapelet数量: {len(learned_shapelets_ts)}")   if learned_shapelets_ts: # It's a list of time series        print(f"第一个Shapelet的形状: {learned_shapelets_ts[0].shape}") # (shapelet_length, d)         # 将原始时间序列转换为到各个shapelet的距离特征   X_shapelet_transformed = shapelet_clf.transform(X_scaled)   print(f"Shapelet转换后的特征矩阵形状: {X_shapelet_transformed.shape}") # (n_ts, n_total_shapelets)   print("第一个序列转换后的Shapelet距离特征:")   print(X_shapelet_transformed[0])      # 这些距离特征可以用于后续的分类器训练   # 例如: from sklearn.linear_model import LogisticRegression   #       lr = LogisticRegression()   #       lr.fit(X_shapelet_transformed, y_example)   print("-" * 30)      # 可视化一个原始序列、其PAA和SAX的逆转换 (近似)   # plt.figure(figsize=(12, 8))   # plt.subplot(3, 1, 1)   # plt.plot(X_scaled[0].ravel(), "b-", label="Original Scaled Series")   # plt.legend()   #   # if X_paa.size > 0:   #     X_paa_inv_single = paa_transformer.inverse_transform(X_paa[0:1])   #     plt.subplot(3, 1, 2)   #     plt.plot(X_paa_inv_single.ravel(), "r-", label=f"PAA Reconstruction ({n_paa_segments} segments)")   #     plt.legend()   #   # if X_sax.size > 0:   #     X_sax_inv_single = sax_transformer.inverse_transform(X_sax[0:1]) # SAX output are symbols, inverse_transform gives reconstruction   #     plt.subplot(3, 1, 3)   #     plt.plot(X_sax_inv_single.ravel(), "g-", label=f"SAX Reconstruction ({n_sax_symbols} symbols)")   #     plt.legend()   #   # plt.tight_layout()   # plt.show()   `
    

-   3.7. Cesium：端到端的时间序列机器学习平台
    
    Cesium是一个开源的Python库和Web平台，旨在为时间序列分析提供从原始数据处理、特征提取到模型构建和预测的端到端解决方案。它特别关注于科学领域（如天文学、神经科学）的时间序列数据分析。
    
-   cesium.featurize模块概述： cesium.featurize是Cesium库中负责特征提取的核心模块。它能够接收原始时间序列数据，通常包括时间戳 (t)、测量值 (m) 和可选的测量误差 (e)，并从中计算出大量预定义的特征。Cesium还支持用户通过提供自定义Python脚本来扩展其特征集。
    
-   关键特征类别： Cesium可以生成多种类型的特征，其官方文档提供了一个详细的特征表。这些特征覆盖了时间序列的幅度、周期性、变异性、形状等多个方面：
    

-   **通用描述性统计特征：** 如均值 (mean)、标准差 (std)、中位数 (median)、偏度 (skew)、峰度 (kurtosis)、振幅 (amplitude)、超出1倍标准差的点的百分比 (percent\_beyond\_1\_std)、接近中位数的点的百分比 (percent\_close\_to\_median)。
    
-   **周期性/频率特征：** 基于Lomb-Scargle周期图的特征（如freq1\_amplitude1 - 最高峰频率的幅度，freq1\_signif - 最高峰频率的显著性，period\_fast - 快速周期，psi\_eta\_log\_freq），以及基于自相关的特征（如autocorr\_len - 自相关长度）。
    
-   **变异性/结构特征：** Stetson J和K指数（stetson\_j, stetson\_k，用于衡量光变曲线的同步变异性）、最大斜率 (max\_slope)、峰值数量 (num\_peaks)、斜率段数量 (num\_slopes)。
    
-   **形状/不对称性特征：** 光通量百分位数比率（如flux\_percentile\_ratio\_mid20，衡量光变曲线形状）、中位数绝对偏差 (median\_absolute\_deviation)。
    
-   **采样间隔/误差特征 (Cadence/Error Features)：** 这是一类针对观测数据特性的特征，例如平均双步与单步时间间隔之比 (avg\_double\_to\_single\_step)、平均误差 (avg\_err)、平均观测时间 (avgt)，以及在不同时间窗口内下一次观测发生的概率 (cad\_probs\_\*)。
    

-   用法与配置： 使用cesium.featurize模块时，通常需要将时间序列数据准备成NumPy数组格式，分别对应时间、测量值和（可选的）误差。cesium.featurize.featurize\_time\_series()是执行特征提取的主要函数，它可以接收单个时间序列或时间序列列表，以及一个指定要提取哪些特征的列表或预定义的特征集名称。
    
-   **代码示例：使用Cesium从时间序列中提取通用特征**
    
    Python
    
    `import numpy as np   import pandas as pd   from cesium.featurize import featurize_time_series # 主要的特征提取函数   # from cesium.time_series import TimeSeries # Cesium的TimeSeries对象，但featurize_time_series可以直接用numpy数组      # 1. 准备示例时间序列数据 (时间、测量值、可选的测量误差)   # 假设我们有一个简单的时间序列   n_points = 100   times = np.sort(np.random.rand(n_points) * 100) # 随机时间戳   measurements = np.sin(times / 5) + np.random.randn(n_points) * 0.5 # 信号 + 噪声   errors = np.random.rand(n_points) * 0.1 + 0.05 # 随机误差      print("示例数据点数:", n_points)   print("时间戳 (前5个):", times[:5])   print("测量值 (前5个):", measurements[:5])   print("测量误差 (前5个):", errors[:5])   print("-" * 30)      # 2. 定义要提取的特征列表   # 参考 Cesium 文档获取完整的特征列表   # 这里选择一些通用的特征作为示例   features_to_extract = [       'amplitude', 'mean', 'std', 'median_absolute_deviation',       'percent_beyond_1_std', 'skew', 'max_slope', 'stetson_k'   ]         # 如果不提供 features_to_extract，Cesium会提取一个默认的特征集合      # 3. 使用 featurize_time_series() 提取特征   # featurize_time_series 需要一个包含时间序列数据的列表   # 每个元素可以是一个字典或一个cesium.TimeSeries对象   # 为了简单，我们直接传递一个包含单个时间序列的列表，每个时间序列用字典表示      # 注意：对于某些特征（如频域特征），可能需要更多的数据点或特定的数据特性才能有效计算。   # 如果数据点太少或不规则，某些特征可能会返回NaN或引发错误。      try:       # 单个时间序列的特征提取       # featurize_time_series 的输入可以是 TimeSeries 对象列表，       # 或者更简单地，是包含 (t, m, e) 的元组或列表的列表       # 这里我们构建一个包含单个时间序列的列表          # featurize_time_series的输入格式:       # - time_series: list of TimeSeries objects or list of (t, m, e) tuples/lists       # - features_to_use: list of feature names          # 创建一个Cesium TimeSeries对象 (可选，但更规范)       from cesium.time_series import TimeSeries as CesiumTimeSeries       ts_object = CesiumTimeSeries(t=times, m=measurements, e=errors, name="example_series")          # 或者直接使用 (t,m,e) 元组列表 (如果只有一个序列，也需要是列表的列表)       # raw_ts_data = [(times, measurements, errors)]          # 使用TimeSeries对象列表       feature_table = featurize_time_series(           time_series=[ts_object], # 传入一个包含TimeSeries对象的列表           features_to_use=features_to_extract       )          # 如果有多个时间序列，可以这样：       # ts_list = [ts_object1, ts_object2]       # feature_table_multi = featurize_time_series(time_series=ts_list, features_to_use=features_to_extract)          print("\nCesium提取的特征表:")       print(feature_table)      except Exception as e:       print(f"\n使用Cesium提取特征时发生错误: {e}")       print("请确保安装了Cesium及其依赖，并且选择的特征适用于提供的数据。")       print("某些特征（如频域特征）可能对数据长度和采样有要求。")      print("-" * 30)      # 如果想提取所有默认特征，可以不指定 features_to_use 或使用预定义的特征集   # try:   #     default_feature_table = featurize_time_series(   #         time_series=[ts_object]   #         # meta_features can also be added if available   #     )   #     print("\nCesium提取的默认特征表 (部分列):")   #     print(default_feature_table.iloc[:, :5].head()) # Show first 5 columns   #     print(f"默认提取的特征数量: {default_feature_table.shape[1]}") # Show number of features   # except Exception as e:   #     print(f"\n提取默认特征时出错: {e}")   `
    

-   3.8. 其他值得关注的库简要概述
    
    除了上述详细讨论的库之外，Python生态系统中还有一些其他在特定场景下有用的时间序列特征提取或相关工具：
    

-   **tsfel：** TSFEL (Time Series Feature Engineering Library) 是一个Python包，用于从时间序列数据中提取统计、时域和频域特征。它允许用户通过配置文件来选择和参数化要提取的特征。虽然在某些特定比较中，其速度可能不及一些高度优化的库，但它提供了结构化的特征提取流程。其time\_series\_features\_extractor函数是核心，可以计算如自相关（内部使用了statsmodels.tsa.stattools.acf）、最大值、均值等特征。
    
-   **seglearn：** 这是一个为scikit-learn设计的扩展库，专门用于处理多元、序列化的时间序列数据，并进行特征工程和机器学习。
    
-   **pyts：** pyts库本身提供了多种时间序列分析算法，包括一些用于特征转换的方法，如SAX、PAA、BOSSVS等。它的一些功能（如ShapeletTransformPyts或RocketPyts）也被集成或用作sktime等其他库中相应转换器的后端实现。
    
-   **stumpy：** stumpy是一个强大且可扩展的Python库，专注于矩阵轮廓 (Matrix Profile) 的计算及其在各种时间序列数据挖掘任务（如模体发现、异常检测、链发现）中的应用。它通常被其他高级库（如sktime的MatrixProfileTransformer）用作计算矩阵轮廓的底层引擎。
    
-   **时间序列增强库：** 如deltapy、tsaug、time\_series\_augmentation和deepecho等库专注于时间序列数据增强。数据增强技术通过生成原始数据的合成变体来扩充训练集，这可以作为特征工程的前置步骤或补充，以提高模型的鲁棒性和泛化能力。
    

这些专业库在自动化程度、控制粒度、特征类型以及与更广泛的Python数据科学生态系统的集成方面各有侧重。例如，tsfresh和featuretools提供了高度自动化的特征生成和（在tsfresh中）筛选机制，旨在从数据中广泛探索潜在特征。而像sktime中的许多转换器（如ROCKET）或tslearn中的Shapelet学习则需要用户对特定算法进行选择和配置，以生成特定类型的特征。这种差异反映了不同的设计理念：前者是广泛的、自动化的发现，后者是目标驱动的、基于算法的特征创建。值得注意的是，许多这类专用库都努力与主流的Python数据科学生态（特别是Pandas和Scikit-learn）保持兼容。tsfresh明确表示与sklearn、pandas和numpy兼容；featuretools使用Pandas DataFrame构建其核心的EntitySet结构；Kats的TimeSeriesData对象通常也由Pandas DataFrame创建；Darts与Pandas、NumPy和PyTorch集成；而tslearn则直接构建在scikit-learn、numpy和scipy之上，并遵循其API设计。这种设计显著降低了这些专业工具的学习和使用门槛，使得用户可以将它们方便地整合到现有的数据分析和机器学习工作流中。因此，Python的时间序列特征提取生态系统日益丰富和互联。用户可以根据其在自动化、控制、特定特征类型和集成需求方面的具体要求来选择合适的工具，并且常常能够结合不同库的优势。然而，这也意味着需要投入更多精力来学习和理解每个库的细微差别和最佳应用场景。此外，当库能够生成大量特征时（如tsfresh），特征冗余和特征选择成为一个关键挑战。tsfresh通过其内置的基于假设检验的筛选机制来解决这个问题，而对于其他库，用户可能需要在特征提取后应用独立的特征选择技术，以避免过拟合并提高模型的效率和可解释性。

**4\. 比较分析与实践指南**

选择合适的时间序列特征提取库对于项目的成功至关重要。本节将对前述主要库进行比较分析，并提供一些实践指导。

-   **4.1. 各库的优势、劣势及理想用例**
    

-   **Cesium:**
    

-   **优势:** 提供端到端的机器学习平台体验，包含大量受科学领域（如天文学光变曲线分析、神经科学脑电图分析）启发的特征，特别包含了与观测节奏和误差相关的特征。
    

-   **劣势:** 其特征集和应用场景可能更偏向科研领域，对于商业或工业应用可能需要甄别。
    

-   **理想用例:** 科学时间序列数据分析（如天文、生物医学信号），需要考虑不规则采样或测量误差影响的特征提取。
    

-   **tslearn:**
    

-   **优势:** 专注于时间序列的机器学习算法，尤其在基于形态的特征（如Shapelets）和符号化表示（如PAA, SAX）方面有独特之处。
    

-   **劣势:** 相较于tsfresh等库，其特征集可能更偏向于特定类型的应用（如时间序列分类或聚类），通用性特征相对较少。
    

-   **理想用例:** 时间序列分类和聚类任务，特别是当序列的形状或局部模式很重要时；利用PAA/SAX进行降维、模式发现或索引。
    

-   **Darts:**
    

-   **优势:** 用户界面友好，特别擅长时间序列预测任务；对协变量（包括过去和未来协变量）有良好支持；通过add\_encoders参数可以轻松生成基于时间的特征作为协变量；WindowTransformer可用于创建滚动窗口特征。
    

-   **劣势:** 其特征工程功能更多地是服务于其自身的预测模型，作为协变量输入，而不是作为一个通用的、独立的特征提取库。
    

-   **理想用例:** 为Darts库中的预测模型创建和准备协变量，特别是时间相关的动态特征。
    

-   **sktime:**
    

-   **优势:** 提供了统一的时间序列机器学习API，其模块化的转换器 (transformers) 设计非常适合构建复杂的、可复现的特征提取和建模流水线，并且能够方便地封装和调用其他库（如tsfresh）的功能。
    

-   **劣势:** 本身更像一个元框架，其特征提取能力依赖于其内部实现的或包装的各种具体转换器，用户仍需理解这些底层转换器的原理。
    

-   **理想用例:** 构建稳健且可维护的时间序列机器学习工作流，方便地比较和组合不同的特征提取技术，进行模型选择和评估。
    

-   **Kats:**
    

-   **优势:** 作为Facebook（Meta）推出的综合性时间序列分析工具包，TsFeatures模块提供了多样化的特征，包括统计特征、STL分解特征、模型参数（如Holt-Winters）、基于内置检测器（如突变点检测、异常检测）的特征等。
    

-   **劣势:** 尽管号称有65个特征，但从现有公开文档中完整、详细地获取所有特征及其精确计算逻辑可能存在一定挑战。
    

-   **理想用例:** 通用时间序列分析，提取与时间序列结构变化（如水平漂移、趋势变化）相关的特征，以及用于异常检测任务的特征。
    

-   **featuretools:**
    

-   **优势:** 通过深度特征合成实现高度自动化的特征发现，尤其擅长处理关系型和多表数据，也能有效应用于时间序列，显著减少手动特征工程的工作量。
    

-   **劣势:** 对于非常大规模的数据集，计算开销可能较大；理解自动生成的复杂特征的含义可能需要额外努力。
    

-   **理想用例:** 自动化特征发现，特别是当时间序列数据与其他相关数据表存在关联时，或者当需要探索数据中隐含的复杂时序关系时。
    

-   **tsfresh:**
    

-   **优势:** 能够自动提取极为全面的特征集（数百个），内置基于统计显著性的特征筛选机制，可扩展性好。
    

-   **劣势:** 可能产生非常高维的特征空间，需要仔细的特征选择以避免过拟合和维度灾难；部分复杂特征的可解释性可能不强。
    

-   **理想用例:** 探索性特征生成，当需要尝试多种不同类型特征时，大规模时间序列数据集的基准测试。
    

-   **Statsmodels:**
    

-   **优势:** 提供了丰富的统计检验和分解方法，其输出（如检验统计量、p值、分解成分）可以直接作为特征使用，有助于从统计视角理解序列特性。
    

-   **劣势:** 本身并非设计为专门的特征提取库，特征是统计分析的副产品；特征提取的自动化程度不高。
    

-   **理想用例:** 生成基于序列统计属性（如平稳性、季节性、趋势强度）的特征，为模型提供统计学意义上的先验信息。
    

-   **Pandas:**
    

-   **优势:** 无处不在，灵活性极高，非常适合手动创建可解释性强的特征，用户对特征生成过程有完全控制权。
    

-   **劣势:** 对于大量或复杂特征的生成，代码可能变得冗长；缺乏内置的高级统计或谱特征提取功能。
    

-   **理想用例:** 基础特征工程（如滞后、滚动统计、日期时间组件提取），创建高度定制化的领域相关特征，初步数据探索。
    

-   **4.2. 可扩展性、易用性与可扩展性**
    

-   **可扩展性 (Scalability)：** 对于大规模时间序列数据，库的可扩展性至关重要。tsfresh明确提及其可以在集群上运行，并针对并行化进行了设计（如通过chunksize和n\_jobs参数）。featuretools在处理大型实体集时也考虑了计算性能，但深度特征合成的计算量会随实体数量、关系复杂度和原语数量的增加而显著增长。其他库如sktime和Darts通过与Dask等并行计算框架的潜在集成或高效的底层实现（如Numba在ROCKET中的使用）来提升处理大规模数据的能力。
    
-   **易用性 (Ease of Use)：** API设计对用户体验有直接影响。sktime遵循scikit-learn的API风格，这对于熟悉scikit-learn的用户来说学习成本较低。Darts也以其用户友好的接口著称，简化了预测模型的构建和应用。Kats和tsfresh也提供了相对直接的API调用方式。Pandas和Statsmodels虽然功能强大，但进行复杂的特征工程时可能需要更多的手动编码。
    
-   **可扩展性 (Extensibility)：** 指用户添加自定义特征或修改现有功能的能力。tsfresh允许用户轻松添加自定义的特征计算器。Cesium也鼓励社区贡献新的时间序列特征。sktime的模块化设计和对自定义转换器的支持也使其具有良好的可扩展性。
    

-   4.3. 与更广泛的机器学习生态系统的集成
    
    大多数现代Python时间序列库都非常注重与主流数据科学生态系统的集成。Pandas DataFrame已成为时间序列数据的标准格式，几乎所有讨论的库都直接支持或可以方便地转换Pandas对象。与NumPy的兼容性也是普遍的。许多库（如sktime, tslearn, Kats的部分组件）遵循或兼容scikit-learn的Estimator API，这使得它们可以无缝地集成到scikit-learn的Pipeline、模型选择和评估工具中。Darts则与PyTorch等深度学习框架有良好的集成。这种互操作性极大地增强了这些库的实用价值。
    
-   4.4. 选择合适工具的建议
    
    选择时间序列特征提取工具时，并没有“一刀切”的解决方案。最佳选择高度依赖于具体问题、数据特性、用户经验以及期望的结果。
    

-   **对于初学者或需要快速生成可解释基础特征的场景：** 从**Pandas**入手进行手动特征构建（如滞后、滚动统计、日期时间组件）是一个很好的起点。结合**Statsmodels**可以方便地获取如ACF/PACF值、平稳性检验结果和分解成分等具有统计意义的特征。这种组合提供了高度的控制权和可解释性。
    
-   **当需要系统性地探索大量潜在特征时：****tsfresh** 是一个强大的选择，它能自动生成并筛选数百个特征，特别适用于对特征空间进行广泛探索或在不确定哪些特征最重要时。但要注意其可能产生的高维特征需要后续仔细处理。
    
-   **如果数据包含复杂的关系或需要自动化发现特征间的交互：****featuretools** 的深度特征合成能力非常适合这类场景，它可以自动构建多层级的特征。
    
-   **若寻求一个统一的框架来试验和部署包含特征提取在内的完整时间序列机器学习流水线：****sktime** 凭借其与scikit-learn一致的API和模块化的转换器设计，是构建和比较不同特征提取策略的理想平台。它还可以方便地集成tsfresh等其他库的功能。
    
-   **当主要目标是时间序列预测，并且希望方便地为模型添加时间相关的协变量时：****Darts** 提供的add\_encoders机制和WindowTransformer非常实用，可以轻松地为Darts的预测模型生成输入特征。
    
-   **对于需要基于序列形态或符号化表示进行分析（如时间序列分类、聚类、相似性搜索）：****tslearn** 提供了如Shapelets、PAA、SAX等专门的工具。
    
-   **如果处理的是特定科学领域（如天文学、生物医学信号）的时间序列，且需要考虑观测特性（如采样节奏、误差）：****Cesium** 提供了针对这些场景的特色特征集。
    
-   **当需要提取与时间序列结构变化（如突变点、趋势变化）或异常点相关的特征时：****Kats** 的TsFeatures模块集成了其内部检测器的输出，可以提供这方面的独特洞察。
    

实践中，通常需要根据数据的大小、序列的单变量/多变量性质、长度、是否有规律采样、计算资源限制以及对特征可解释性的要求等因素综合考虑。有时，组合使用不同库的优势（例如，用Pandas做基础处理，然后用sktime包装tsfresh或ROCKET转换器）可能会是更有效的方法。

**5\. 高级考量与未来趋势**

随着时间序列数据的日益复杂和海量化，特征提取领域也在不断发展。除了选择合适的库之外，还有一些高级因素和未来趋势值得关注。

-   5.1. 高维时间序列特征集的特征选择策略 当使用如tsfresh这类能生成大量特征的库时，或者当手动组合了多种特征提取方法后，很容易得到一个高维的特征集。高维特征空间可能导致“维度灾难”，增加模型训练的计算复杂度，并可能引入不相关或冗余的特征，从而损害模型性能（例如过拟合）。因此，有效的特征选择变得至关重要。
    

-   **过滤式方法 (Filter Methods)：** 根据特征本身的统计属性（如方差、与目标变量的互信息、相关系数等）对特征进行排序和筛选，独立于后续的机器学习模型。
    
-   **包裹式方法 (Wrapper Methods)：** 将特征选择过程视为一个搜索问题，使用预定的机器学习模型来评估不同特征子集的性能，例如递归特征消除 (Recursive Feature Elimination, RFE)。
    
-   **嵌入式方法 (Embedded Methods)：** 特征选择过程嵌入在模型训练过程中完成，例如L1正则化（Lasso）可以使不重要特征的系数变为零，从而实现特征选择。scikit-learn库提供了这些通用特征选择方法的实现。
    

-   tsfresh自身内置了基于可扩展假设检验的特征选择机制（FRESH算法），能够根据特征与目标变量的相关性自动筛选特征。
    
-   对于其他库生成的特征集，或者当需要更细致的控制时，可以应用通用的特征选择技术。这些技术通常分为三类：
    

-   5.2. 深度学习在自动化时间序列特征提取中的作用 近年来，深度学习模型，特别是循环神经网络 (RNNs) 如LSTM、门控循环单元 (GRUs)，以及Transformer架构，在时间序列分析和预测领域取得了显著成功。这些模型的一个显著特点是它们能够直接从原始或接近原始的时间序列数据中自动学习层次化的特征表示，从而在一定程度上减少了对显式、手动特征工程的依赖。例如，Darts库就支持多种基于PyTorch的深度学习预测模型。 然而，这并不意味着传统的时间序列特征工程已经过时。实践表明：
    

-   对于数据量较小或中等规模的时间序列，精心设计的特征往往能帮助深度学习模型更快收敛，并达到更好的性能。
    
-   显式提取的特征通常具有更好的可解释性，这对于许多应用场景（如金融风控、医疗诊断）至关重要，而深度学习模型学习到的内部表示往往是“黑箱”。
    
-   混合方法，即将手动工程化的特征与原始序列（或其部分）一同作为深度学习模型的输入，有时能取得比单独使用任一方法更优的效果。
    

-   5.3. 新兴趋势与有前景的新库/技术 时间序列特征提取领域仍在持续发展，一些新兴趋势和技术值得关注：
    

-   **针对不规则/异步时间序列的特征提取：** 许多传统方法假设时间序列是等间隔采样的。然而，现实世界中大量时间序列（如医疗记录、用户行为日志）是不规则的。针对这类数据的特征提取方法是一个活跃的研究方向。
    
-   **可解释特征学习：** 结合深度学习的自动特征学习能力与传统特征的可解释性是一个重要的目标。研究者们正在探索如何使深度模型学习到的特征更易于人类理解。
    
-   **时间序列表示学习：** 类似于自然语言处理和计算机视觉中的嵌入技术，时间序列表示学习旨在将时间序列映射到一个低维的向量空间，使得相似的序列在向量空间中也相近。这些向量表示本身就可以作为特征。
    
-   **特定领域特征库的涌现：** 随着时间序列分析在更多特定领域的深入应用，可能会出现更多针对特定数据类型（如可穿戴设备数据、工业传感器数据）的专用特征提取库。
    
-   **AutoML在时间序列特征工程中的进一步应用：** 虽然featuretools和tsfresh已经提供了高度自动化的能力，但将特征提取、特征选择与模型选择、超参数优化更紧密地集成到AutoML流程中，是未来的一个发展方向。sktime的流水线和AutoML功能正在朝这个方向努力。
    

当前，时间序列特征工程领域体现了显式特征构建与端到端深度学习方法之间的持续互动与融合。显式特征提取库对于处理中小型数据集、需要高可解释性的问题，或者当领域知识能够被有效编码为特征时，仍然具有不可替代的价值。未来，很可能会看到更多混合方法的出现，即自动化特征工程工具与深度学习模型协同工作，以及对学习到的特征的可解释性的更深入研究。

**6\. 结论**

时间序列特征提取是时间序列分析和建模流程中不可或缺的一环。通过将原始时间序列数据转换为富有信息量的特征，可以显著提升机器学习模型的性能、泛化能力和可解释性。Python凭借其强大的生态系统，为时间序列特征提取提供了从基础操作到高级自动化工具的丰富选择。

-   6.1. 关键洞察回顾 本文对主流的Python时间序列特征提取库进行了全面的回顾和分析。核心的发现可以总结为：
    

1.  **特征提取的重要性：** 原始时间序列数据往往难以直接被机器学习模型有效利用，通过特征提取将其转换为结构化的特征表示是释放数据价值的关键步骤。
    
2.  **Python生态系统的多样性：** Python社区提供了层次丰富、功能各异的库。Pandas和Statsmodels为基础操作和统计特征提取提供了坚实基础。而tsfresh、featuretools、Kats、sktime、Darts、tslearn、Cesium等专用库则在自动化程度、特征类型覆盖面、特定算法实现以及与特定应用领域的结合方面各有侧重。
    
3.  **工具选择的权衡：** 不存在适用于所有场景的“万能”特征提取库。选择合适的工具需要权衡自动化水平与控制精度、特征的全面性与特定性、计算效率与资源消耗、以及库的易用性和与现有工作流的集成度。例如，tsfresh和featuretools提供了高度的自动化，适合快速探索和发现特征；而sktime和tslearn中的特定转换器则给予用户更多对算法选择和参数配置的控制。
    
4.  **互操作性与集成：** 大多数现代库都致力于与Pandas、NumPy和Scikit-learn等核心数据科学库保持良好的兼容性和API一致性，这极大地促进了它们在实际项目中的应用和组合。
    
5.  **显式特征工程与深度学习的并存：** 尽管深度学习模型能够自动学习特征，但显式提取的特征在提升模型性能、数据效率、可解释性以及处理中小型数据集方面仍然具有重要价值。两者并非完全替代关系，而是可以互补共存。
    

-   6.2. 对实践者和研究者的最终建议 对于从事时间序列分析的实践者和研究者，以下建议可能有助于更有效地利用Python进行特征提取：
    

1.  **从基础开始，逐步深入：** 熟练掌握Pandas进行数据预处理和基础特征构建（如滞后、滚动统计、时间组件），以及Statsmodels进行统计分析和分解，是进行更高级特征工程的前提。
    
2.  **根据需求选择专业工具：** 在理解基础工具的局限性后，根据具体任务需求（如需要全面探索特征、自动化特征发现、特定类型的特征如Shapelets或频域特征、或为特定预测框架准备协变量）选择合适的专用库。参考本文第四部分的比较分析和用例可以作为起点。
    
3.  **理解特征的含义：** 即使是使用自动化工具生成的特征，也应努力理解其背后的计算逻辑和潜在含义。这有助于判断特征的有效性、避免引入偏差，并增强模型结果的可解释性。
    
4.  **重视特征选择：** 当生成大量特征时（尤其使用tsfresh等工具），必须采用有效的特征选择策略，以避免维度灾难、降低计算成本并提高模型泛化能力。
    
5.  **考虑计算成本和可扩展性：** 不同的库和特征提取方法在计算效率和处理大规模数据的能力上存在差异。在项目初期即应评估这些因素。
    
6.  **拥抱混合方法：** 不要局限于单一工具或方法。根据问题的复杂性，可以考虑组合使用不同库的优势，或者将手动工程化的特征与深度学习模型相结合。
    
7.  **持续学习与探索：** 时间序列分析和特征工程是一个快速发展的领域，新的库、算法和技术不断涌现。保持学习的热情，关注社区动态，并勇于尝试新的工具，是提升专业能力的关键。
    

  

  

更多资源见星球，加入QuantML星球，与星主和850+专业人士一起交流学习：

![图片](assets/001.webp)