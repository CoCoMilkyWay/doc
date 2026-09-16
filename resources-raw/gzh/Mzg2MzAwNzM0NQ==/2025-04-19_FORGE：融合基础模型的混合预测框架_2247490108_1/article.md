# FORGE：融合基础模型的混合预测框架

QuantML QuantML 2025-04-19 21:41 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490108&idx=1&sn=9f8dfe86f605ff57139dc615b1f1fe25&chksm=cf6ca6dda032adb7f0126e02318d4a8ab7fb0bcac8e8734ade511b4de2e8e9379435db2d65e9#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490108&idx=1&sn=9f8dfe86f605ff57139dc615b1f1fe25&chksm=cf6ca6dda032adb7f0126e02318d4a8ab7fb0bcac8e8734ade511b4de2e8e9379435db2d65e9#rd)

基础模型在时间序列预测领域成为了人工智能领域的热门话题。基础模型是一种大规模、通用的模型，这意味着它不需要任何特定任务的训练或数据（尽管我们可以对其进行微调，但并非必须）。因此，我们可以将基础模型应用于零样本推理设置中，即从一小段上下文信息（例如，一个新的时间序列的小窗口），我们就可以预测出一个预测范围。请注意，这个过程只涉及推理，不涉及训练。

几家公司进入了这场竞赛，推出了具有竞争力的基础模型。尽管这些模型的共同目标是生成准确的预测，而无需任何必要的训练，但它们采用了不同的策略和特性。TimeGPT是Nixtla开发的首批用于预测的基础模型之一。随后，其他公司也加入了竞争，推出了新的模型，如Salesforce的MOIRAI、摩根士丹利的Lag-Llama、ServiceNow和一组加拿大大学合作的TimesFM、谷歌的Chronos以及亚马逊的Chronos。

时间序列之间的依赖关系，并结合可能有助于解释目标变量行为的相关特征。例如，在零售环境中，关于营销活动的信息对于理解特定产品的销售模式至关重要。另一方面，Chronos和TimesFM是严格意义上的单变量基础模型，无法使用外部信息来生成更好的预测。

在本文中，我们提出了一种名为FORGE（融合精炼和广义引擎）的混合框架，通过将Chronos与一个多变量非基础模型相结合来解决上述限制。目标是首先利用Chronos生成一个基础预测——利用其强大的零样本推理性能——然后用一个可以结合外部信息并捕捉系列间依赖关系的多变量模型对其进行精炼。本文涵盖了FORGE方法的所有理论细节以及实际实现。

# Chronos

Chronos是亚马逊最新的时间序列预测基础模型，基于T5（文本到文本转换Transformer）架构构建的概率模型，用于预测未来模式。T5是一种专门从事不同自然语言处理（NLP）任务（如分类、摘要或文本生成）的大型语言模型（LLM）。那么，它如何适应处理连续数值数据并生成准确的预测呢？

如图2所示，亚马逊的预测团队通过关注两个主要概念，成功地将任何LLM转变为预测模型：

缩放负责将输入数据映射到适当的值范围，以便在量化步骤中使用。与其通常目标相反，缩放有助于创建输入标记，这是任何LLM所期望的格式。 量化则通过分箱将缩放的连续值转换为4096个离散标记。作者使用了均匀分箱，它将特定范围内的所有值分组到同一个箱子或换句话说，分配到同一个标记。

Chronos的另一个关键特性是其零样本推理能力。由于在能源、交通、医疗、零售网络、天气和金融等不同领域对796,000个不同系列进行了密集训练，该模型能够准确生成零样本预测。

尽管如此，该模型也存在一些缺点，例如：

单变量局部模型，无法对系列之间的依赖关系进行建模。 无法处理外部信息，如静态和动态协变量，如产品品牌或产品价格。 由于其损失函数是交叉熵，因此无法预测训练数据之外的值，这意味着它只能预测训练数据中存在的值，无法准确预测具有急剧上升或下降趋势的时间序列。

![](assets/001.jpg)

# TiDE

TiDE，或称时间序列密集编码器，由谷歌的研究人员开发，旨在通过采用超越复杂Transformer架构的多层感知器（MLP）编码器-解码器模型来处理长期预测。该模型有效地处理了静态和动态协变量，如产品品牌和价格，使其适用于交通、能源或零售等不同行业。

TiDE的架构如图3所示，从一个特征投影层开始，该层降低了动态协变量的维度。然后，密集编码器处理这些投影数据，以及静态协变量和历史输入，形成一个密集的特征嵌入。这个嵌入被传递给密集解码器以产生初始预测，而时间解码器通过整合时间模式和依赖关系对其进行细化。时间解码器还使用残差连接，利用过去数据的投影进一步提高了预测精度。

尽管TiDE简单而强大，但它对超参数敏感，需要仔细调整才能有效处理复杂的现实世界数据集。

![](assets/002.jpg)  
图3：TiDE架构

# FORGE：结合基础模型和非基础模型

如前所述，Chronos可以进行零样本预测。尽管如此，它有三个主要限制：无法对系列之间的依赖关系进行建模，缺乏结合外部（可能是关键的）信息的灵活性，以及仅限于在训练范围内产生预测。为了解决这些问题，我们提出了一种混合模型，将Chronos的预测与任何可以处理外部数据、捕捉系列依赖关系并预测超出训练中看到的值的多变量模型的 capabilities 相结合。

FORGE有两个组成部分：

基础预测是Chronos根据历史时间序列数据生成的预测。 残差预测是由多变量模型（在本例中为TiDE）根据Chronos生成的全局（对所有时间序列）历史残差以及静态和动态协变量生成的预测。

TiDE的训练过程包括在原始数据集中添加一个新的目标变量，称为残差，该变量基于Chronos生成的预测与实际值之间的差异。我们使用扩展窗口生成这个新的目标变量，如图4所示。

![](assets/003.jpg)  
图4：生成包含残差的数据集的扩展窗口过程

如图5所示，一旦生成了残差，我们就可以使用Chronos生成基础预测，并使用TiDE生成残差预测。然后将这两个预测结合起来，基于历史数据、动态和静态协变量以及系列之间的依赖关系生成最终和增强的预测。

![](assets/004.jpg)  
图5：结合TiDE和Chronos进行增强预测

# FORGE实战

在本节中，我们将使用FORGE预测澳大利亚的旅游访客，使用的是一个在cc-by-4.0许可下公开可用的真实世界数据集。随后，我们将FORGE的预测性能与Chronos和TiDE分别进行比较。

我们使用从Trading Economics提取的经济协变量（例如，CPI、通货膨胀率、GDP）增强了数据集，这些经济指标基于官方来源。我们还进行了一些预处理，以进一步提高数据集的可用性。数据集的最终结构如下：

唯一ID：澳大利亚各州、区域、地区和访问目的（例如，商业、假日、访问、其他）的编码名称的组合。 时间：表示数据集的时间维度，根据每个系列动态调整。 目标：预测的目标变量，特别关注访问量。 动态协变量：随时间变化的CPI、通货膨胀率和GDP等经济指标。 静态协变量（Static\_1到Static\_4）：从唯一ID中提取的，为分析提供了额外的地理和访问目的详细信息。

我们将新版本的数据集存储在这里，以便我们的实验可以轻松重现。

除了最终数据集之外，还创建了残差数据集来训练我们的多变量模型TiDE。它具有相同的结构，但包含的不是目标，而是残差：Chronos预测的目标与实际目标之间的差异。

在实践实现中，我们首先导入库并设置全局变量：

`from darts.dataprocessing.transformers import StaticCovariatesTransformer   from darts.utils.likelihood_models import QuantileRegression   from darts.dataprocessing.transformers import Scaler   from darts.dataprocessing.pipeline import Pipeline   from dateutil.relativedelta import relativedelta   from chronos import ChronosPipeline   from darts.models import TiDEModel   from darts import TimeSeries   import pandas as pd   import torch   import utils      DATASET = "hf://datasets/zaai-ai/time_series_datasets/data.csv"   RESIDUALS_DATASET = "hf://datasets/zaai-ai/time_series_dataset_residuals/residuals.csv"      TIME_COL = "Date"   TARGET = "visits"   RESIDUALS_TARGET = "residuals"   STATIC_COV = ["static_1","static_2","static_3","static_4"]   DYNAMIC_COV = ["CPI","Inflation_Rate","GDP"]      FORECAST_HORIZON = 6# months   FREQ = "MS"         # 调整后的TiDE超参数用于预测   # RMSE: 134.74   TiDE_params = {       'input_chunk_length': 12,       'output_chunk_length': FORECAST_HORIZON,       'num_encoder_layers': 4,       'num_decoder_layers': 8,       'decoder_output_dim': 8,       'hidden_size': 8,       'temporal_width_past': 16,       'temporal_width_future': 8,       'temporal_decoder_hidden': 128,       'dropout': 0.2,       'batch_size': 16,       'n_epochs': 20,       'likelihood': QuantileRegression(quantiles=[0.25, 0.5, 0.75]),       'random_state': 42,       'use_static_covariates': True,       'optimizer_kwargs': {'lr': 0.001},       'use_reversible_instance_norm': False   }   # RMSE: 133.85   res_TiDE_params = {       'input_chunk_length': 11,       'output_chunk_length': FORECAST_HORIZON,       'num_encoder_layers': 5,       'num_decoder_layers': 10,       'decoder_output_dim': 15,       'hidden_size': 5,       'temporal_width_past': 4,       'temporal_width_future': 10,       'temporal_decoder_hidden': 20,       'dropout': 0.15,       'batch_size': 128,       'n_epochs': 30,       'likelihood': QuantileRegression(quantiles=[0.25, 0.5, 0.75]),       'random_state': 42,       'use_static_covariates': True,       'optimizer_kwargs': {'lr': 0.001},       'use_reversible_instance_norm': True,   }   `

之后，我们加载我们的数据集：

`df = pd.read_csv(DATASET).drop(columns=["Unnamed: 0"])   df[TIME_COL] = pd.to_datetime(df[TIME_COL])      residuals = pd.read_csv(RESIDUALS_DATASET)   residuals[TIME_COL] = pd.to_datetime(residuals[TIME_COL])      print(f"Distinct number of time series: {len(df['unique_id'].unique())}")   `

为了更好地测试FORGE，我们创建了四个折叠。每个折叠的训练集包含直到折叠开始日期的所有数据，而测试集则包含随后6个月的数据。最后一个折叠的测试集在数据集中最接近的日期结束。

这些折叠提供了对模型随时间变化的性能的更稳健衡量。我们不依赖于单一窗口来评估我们的方法。

以下是具体的实现方式：

`folds = []   for i in range(4, 0, -1):       start_date = end_date - relativedelta(months=FORECAST_HORIZON * i)       end_date_fold = start_date + relativedelta(months=FORECAST_HORIZON)       fold = {           "start_date": start_date,           "end_date": end_date_fold,           "train": None,           "test": None,           "df": None,           "predictions": {               "chronos": None,               "tide": None,               "hybrid": None           }       }       fold["train"] = df[df[TIME_COL] <= fold["start_date"]]       fold["test"] = df[(df[TIME_COL] > fold["start_date"]) & (df[TIME_COL] <= fold["end_date"])]       fold["df"] = df[df[TIME_COL] <= fold["end_date"]]       folds.append(fold)      for i, fold in enumerate(folds):       print(f"Fold {i+1}:")       print(f"Months for training: {len(fold['train'][TIME_COL].unique())} from {fold['train'][TIME_COL].min()} to {fold['train'][TIME_COL].max()}")       print(f"Months for testing: {len(fold['test'][TIME_COL].unique())} from {fold['test'][TIME_COL].min()} to {fold['test'][TIME_COL].max()}")   `

折叠1：训练月份：204，从1998-01-01到2014-12-01  
测试月份：6，从2015-01-01到2015-06-01  
折叠2：训练月份：210，从1998-01-01到2015-06-01  
测试月份：6，从2015-07-01到2015-12-01  
折叠3：训练月份：216，从1998-01-01到2015-12-01  
测试月份：6，从2016-01-01到2016-06-01  
折叠4：训练月份：222，从1998-01-01到2016-06-01  
测试月份：6，从2016-07-01到2016-12-01

为了实现FORGE，我们首先使用Chronos为每个折叠生成预测。

`for i, fold in enumerate(folds):       train_darts = TimeSeries.from_group_dataframe(           df=fold['train'],           group_cols=STATIC_COV,           time_col=TIME_COL,           value_cols=TARGET,           freq=FREQ,           fill_missing_dates=True,           fillna_value=0       )       # 加载Chronos管道       pipeline = ChronosPipeline.from_pretrained(           CHRONOS_ARCHITECTURE[0],           device_map=CHRONOS_ARCHITECTURE[1],           torch_dtype=torch.bfloat16       )       forecast = []       for ts in train_darts:           # 预测           lower, mid, upper = utils.chronos_forecast(pipeline, ts.pd_dataframe())           unique_id = "_".join(str(ts.static_covariates[key].item()) for key in ts.static_covariates)           forecast.append(utils.convert_forecast_to_pandas([lower, mid, upper], unique_id))       fold['predictions']['chronos'] = pd.concat(forecast)   `

之后，对于每个折叠，我们使用TiDE生成残差预测，并将其与Chronos预测相加，以产生最终预测：

`for i, fold in enumerate(folds):       residuals_train = residuals[residuals[TIME_COL] <= fold['start_date']]       residuals_df = residuals[(residuals[TIME_COL] <= fold['end_date'])]          residuals_darts = TimeSeries.from_group_dataframe(           df=residuals_train,           group_cols=STATIC_COV,           time_col=TIME_COL,           value_cols=RESIDUALS_TARGET,           freq=FREQ,           fill_missing_dates=True,           fillna_value=0       )          dynamic_covariates = utils.create_dynamic_covariates(residuals_darts, residuals_train)       # 缩放协变量       dynamic_covariates_transformed = SCALER.fit_transform(dynamic_covariates)          # 缩放数据并转换静态协变量       data_transformed = PIPELINE.fit_transform(residuals_darts)          residuals_tide = TiDEModel(**res_TiDE_params)       residuals_tide.fit(data_transformed, future_covariates=dynamic_covariates_transformed)       pred = PIPELINE.inverse_transform(residuals_tide.predict(n=FORECAST_HORIZON))       residuals_forecast = utils.transform_predictions_to_pandas(pred, RESIDUALS_TARGET)       fold['predictions']['hybrid'] = utils.combine_predictions(fold['predictions'])   `

最后，我们使用TiDE在原始数据集上生成以访问量为目标的预测，以将其与Chronos和FORGE进行比较。

`for i, fold in enumerate(folds):       train_darts = TimeSeries.from_group_dataframe(           df=fold['train'],           group_cols=STATIC_COV,           time_col=TIME_COL,           value_cols=TARGET,           freq=FREQ,           fill_missing_dates=True,           fillna_value=0       )          dynamic_covariates = utils.create_dynamic_covariates(train_darts, fold['df'])       # 缩放协变量       dynamic_covariates_transformed = SCALER.fit_transform(dynamic_covariates)          # 缩放数据并转换静态 + 协变量       data_transformed = PIPELINE.fit_transform(train_darts)          tide = TiDEModel(**TiDE_params)       tide.fit(data_transformed, future_covariates=dynamic_covariates_transformed)       pred = PIPELINE.inverse_transform(tide.predict(n=FORECAST_HORIZON, series=fold['df']))       fold['predictions']['tide'] = utils.transform_predictions_to_pandas(pred, TARGET)   `

一旦所有预测生成完毕，我们就可以比较FORGE与TiDE和Chronos的性能。为此，我们计算每个模型在预测范围内的每个月的MAPE（平均绝对百分比误差），并对所有折叠取平均值。此外，我们决定使用MAPE是因为它更直观，更容易解释，因为它将误差表示为百分比，可以直接理解预测误差的相对大小。

我们选择了访问量最高的25个唯一ID进行更好的评估。这种方法确保了低访问量计数可能导致的MAPE过高不会扭曲结果。

图6显示，FORGE在更长期预测中始终优于TiDE和Chronos，只有在前两个月出现例外。这种模式表明，随着时间的推移，FORGE的优势变得更加明显。我们认为，对于与目标变量更密切相关的外部特征的数据库（其中TiDE表现出色）或对于更短、更不稳定的系列（其中Chronos表现出色），这些好处会更加显著。

![](assets/005.jpg)

图6：模型比较

# 结论

在本文中，我们提出了FORGE，这是一个结合基础和非基础时间序列预测模型的框架。在本例中，我们展示了如何使用FORGE将Chronos和TiDE结合起来，利用它们的优势来改进我们的预测。

FORGE显示出有希望的结果，在更长期的预测中优于单个模型。对于外部特征与目标变量更相关的数据库（其中TiDE表现出色）或系列更短、更不稳定的数据库（其中Chronos表现出色），结果应该更加显著。

总的来说，FORGE代表了结合基础和非基础方法的向前迈进了一步，为现实世界的应用提供了更稳健的解决方案。

  

  

  

  

  

完整代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/006.png)